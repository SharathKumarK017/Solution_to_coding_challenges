#include <iostream>
#include <string>

std::string to_camel_case(std::string text) {
    if (text == "")
        return "";

    for (std::string::size_type i = 0; i < text.length(); ++i) {
       if (text[i] == '_' || text[i] == '-') {
           if (text[i+1])
               text.at(i+1) = std::toupper(text.at(i+1));
            text.erase(i, 1);
       }
    }
    return text;
}


int main(void) {
    std::string s1("the-stealth-warrior");
    std::string s2("The_Stealth_Warrior");
    std::string s3("The_Stealth-Warrior");

    std::cout << "String 1 " << s1 << " -> " << to_camel_case(s1) << std::endl;
    std::cout << "String 2 " << s2 << " -> " << to_camel_case(s2) << std::endl;
    std::cout << "String 3 " << s3 << " -> " << to_camel_case(s3) << std::endl;
    return 0;
}

