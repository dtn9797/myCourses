#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string input;
    std::regex integer{"(\\+|-)?[[:digit:]]+"};
    std::cout << "Enter some integers:" << std::endl;

    int sum = 0;
    while(std::cin>>input) {
        if(std::regex_match(input,integer))
            sum += stoi(input);
        else
            std::cerr << "Error: Not an integer" << std::endl;
    }
    std::cout << "Sum is " << sum << std::endl;
}
