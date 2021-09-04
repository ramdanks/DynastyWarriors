#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <queue>
#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>

using work = std::function<void(void)>;

struct ThreadPool
{
    explicit ThreadPool(size_t threadCount = std::thread::hardware_concurrency())
        : exit(false)
    {
        if (threadCount == 0)
            throw std::runtime_error("cannot create thread pool with thread count 0");
        workers.reserve(threadCount);
        for (size_t i = 0; i < threadCount; ++i)
            workers.emplace_back(&ThreadPool::mainLoop, this);
    }
    // add work to queue and notify threads to run it
    void inline dispatch(work&& work) noexcept
    {
        workQueue.emplace(std::move(work));
        condition.notify_one();
    }
    // ask threads to exit and wait for it to complete it's task if exists
    // dtor will not wait for queue to be completed (emptied).
    ~ThreadPool()
    {
        exit = true;
        condition.notify_all();
        for (auto& worker : workers)
            worker.join();
    }

    ThreadPool& operator=(const ThreadPool& other) noexcept = delete;
    ThreadPool& operator=(ThreadPool&& other) noexcept = delete;

private:
    // making all threads live until it asked to exit
    void mainLoop()
    {
        while (true)
        {
            work task{nullptr};
            // locked by mutex, one thread at a time
            {
                std::unique_lock guard(mutex);
                condition.wait(guard, [this]{ return exit || !workQueue.empty(); });
                // break if asked to exit
                if (exit) break;
                // get a task from front queue and remove it
                task = std::move(workQueue.front());
                workQueue.pop();
            }
            // do work simultaneously no need synchronization
            // TODO: exception handling
            task();
        }
    }

private:
    bool exit;
    std::vector<std::thread> workers;
    std::queue<work> workQueue;

    mutable std::mutex mutex;
    std::condition_variable condition;
};

#endif