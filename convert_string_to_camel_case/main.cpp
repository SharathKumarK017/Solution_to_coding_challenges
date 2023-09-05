#include <iostream>
#include <string>
#include <map>

void test_func(std::string (*func)(std::string text), std::map<std::string, std::string> test_data) {
    int i = 1;
    for (std::map<std::string, std::string>::iterator it = test_data.begin(); it != test_data.end(); ++it) {
        if (func(it->first) == it->second) {
            std::cout << "Test " << i << " passed.\n";
        }
        else {
            std::cout << "Test " << i << " failed!\n";
        }
        ++i;
    }
}

std::string to_camel_case(std::string text) {
    if (text == "")
        return "";

    for (std::string::size_type i = 0; i < text.length(); ++i) {
       if (text[i] == '_' || text[i] == '-') {
           if (text[i+1])
               text.at(i+1) = toupper(text.at(i+1));
            text.erase(i, 1);
       }
    }
    return text;
}


int main(void) {
    std::map<std::string, std::string> data = {
        {"the-stealth-warrior", "theStealthWarrior"},
        {"The_Stealth_Warrior", "TheStealthWarrior"},
        {"The_Stealth-Warrior", "TheStealthWarrior"},
    };

    test_func(to_camel_case, data);

    return 0;
}

