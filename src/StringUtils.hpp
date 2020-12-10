#include <iostream>
#include <vector>

// StringUtils groups utilities methods for strings
namespace StringUtils
{
    std::string& ltrim(std::string &str, const std::string& chars = "\t\n\v\f\r ");
    
    std::string& rtrim(std::string &str, const std::string& chars = "\t\n\v\f\r ");
    
    std::string& trim(std::string &str, const std::string& chars = "\t\n\v\f\r ");

    std::vector<double> split(const std::string &str, const std::string &delim);
}