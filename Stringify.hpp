#pragma once

#include "SpecialAttacks.hpp"
#include "Kingdom.hpp"
#include "CharacterID.hpp"

#include <string_view>
#include <typeinfo>
#include <array>

using namespace std::literals;

struct Stringify
{
    constexpr static std::array SpecialAttacks = {
        "True Speed"sv,
        "True Speed"sv,
        "Volley"sv,
        "Rockfall"sv,
        "Swift Attack"sv,
        "Fire"sv
    };

    constexpr static std::array Kingdom = {
        "Shu"sv,
        "Wei"sv,
        "Wu"sv,
        "Other"sv
    };

    constexpr static std::array Character = {
        "Guan Ping"sv,      
        "Guan Yu"sv,        
        "Huang Zhong"sv,    
        "Liu Bei"sv,        
        "Ma Chao"sv,        
        "Pang Tong"sv,      
        "Wei Yan"sv,        
        "Yue Ying"sv,       
        "Zhang Fei"sv,      
        "Zhao Yun"sv,       
        "Zhuge Liang"sv,    
        "Cao Cao"sv,        
        "Cao Pi"sv,         
        "Cao Ren"sv,        
        "Dian Wei"sv,       
        "Sima Yi"sv,        
        "Xiahou Dun"sv,     
        "Xiahou Yuan"sv,    
        "Xu Huang"sv,       
        "Xu Zhu"sv,         
        "Zhang He"sv,       
        "Zhang Liao"sv,     
        "Zhen Ji"sv,        
        "Gan Ning"sv,       
        "Huang Gai"sv,      
        "Ling Tong"sv,      
        "Lu Meng"sv,        
        "Lu Xun"sv,         
        "Sun Ce"sv,         
        "Sun Jian"sv,       
        "Sun Quan"sv,       
        "Sun Shang Xiang"sv,
        "Taishi Ci"sv,      
        "Xiao Qiao"sv,      
        "Zhou Tai"sv,       
        "Zhou Yu"sv,        
        "Diao Chan"sv,      
        "Dong Zhuo"sv,      
        "Lu Bu"sv,          
        "Yuan Shao"sv,      
        "Zhang Jiao"sv
    };
};