#include <iostream>
#include <string>

//void test_func(std::string (*func)(const std::string &text), std::string *inputs[]) {
//}

std::string alphabet_position(const std::string &text) {
    std::string result;
    for (std::string::size_type i = 0; i < text.size(); ++i) {
        if (std::isalpha(text[i])) {
            int num = std::toupper(text[i]) - 0x40;
            result += std::to_string(num) + ' ';
        }
    }
    
    if (result.size() > 0) {
        result.pop_back();
        return result;
    }
    else {
        return "";
    }
}

int main(void) {
    std::cout << alphabet_position("The sunset sets at twelve o' clock.");
    return 0;
}

