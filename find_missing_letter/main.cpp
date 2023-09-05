#include <iostream>
#include <map>
#include <vector>

typedef std::map<std::vector<char>, char> mapvec;

void test_func(char (*func)(const std::vector<char> &data), mapvec inputs) {
    char result;
    int ind = 0;
    for (mapvec::const_iterator it = inputs.begin(); it != inputs.end(); ++it) {
        result = func(it->first);
        if (result == it->second)
            std::cout << "Test " << ind << " passed\n";
        else
            std::cout << "Test " << ind << " failed!\n";
        ++ind;
    }
}

char find_missing_letter(const std::vector<char> &chars) {
    for (std::vector<char>::const_iterator it = chars.begin(); it < chars.end() - 1; ++it) {
        if ((char) (*it + 1) != *(it + 1)) return (char) (*it + 1);
    }
    return ' ';
}

int main(void) {
    mapvec vec {
        {{'a','b','c','d','f'}, 'e'},
        {{'O', 'Q', 'R', 'S'}, 'P'},
    };

    test_func(find_missing_letter, vec);

    return 0;
}

