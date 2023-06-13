#include <map>
#include <string>
#include <any>
        
int main()
{
    std::map<std::string, std::any> notebook;

    std::string name{ "Pluto" };
    int year = 2015;

    notebook["PetName"] = name;
    notebook["Born"] = year;

    std::string name2 = std::any_cast<std::string>(notebook["PetName"]); // = "Pluto"
    int year2 = std::any_cast<int>(notebook["Born"]); // = 2015
}