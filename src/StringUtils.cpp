#include "StringUtils.hpp"

// StringUtils groups utilities methods for strings
namespace StringUtils
{
    std::string& ltrim(std::string &str, const std::string& chars)
    {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }
    
    std::string& rtrim(std::string &str, const std::string& chars)
    {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }
    
    std::string& trim(std::string &str, const std::string& chars)
    {
        return ltrim(rtrim(str, chars), chars);
    }

    std::vector<double> split(const std::string &str, const std::string &delim)
    {
        std::vector<double> tokens;
        size_t prev = 0, pos = 0;
        
        do
        {
            pos = str.find(delim, prev);
            if (pos == std::string::npos)
                pos = str.length();
            std::string token = str.substr(prev, pos - prev);
            if (!token.empty()) tokens.push_back(std::stod(token));
            prev = pos + delim.length();
        } while (pos < str.length() && prev < str.length());
        return tokens;
    }
}