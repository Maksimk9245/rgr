#include <iostream>
#include <string>
bool validateString(const std::string& str) {
    size_t i = 0;
    size_t n = str.size();

    if (str[i] != '+' && str[i] != '-') {
        std::cout << "Error: String must start with '+' or '-'\n";
        return false;
    }
    i++;

    bool hasDigits = false;
    while (i < n && str[i] >= '3' && str[i] <= '9') {
        i++;
        hasDigits = true;
    }
    if (!hasDigits) {
        std::cout << "Error: String must contain at least one digit from '3' to '9'\n"; return false;
    }

    while (i < n && str[i] >= 'J' && str[i] <= 'Z') {
        i++;
    }

    if (i < n && str[i] == '+') {
        i++;
    } else {
        std::cout << "Error: String must end with '+'\n";
        return false;
    }

    if (i != n) {
        std::cout << "Error: Invalid characters in string\n";
        return false;
    }
    return true;
}
int main() {
    std::string testString;
    std::cout << "Enter a string to validate: ";
    std::cin >> testString;
    if (validateString(testString)) {
        std::cout << "The string is valid and belongs to L(V).\n";
    } else {
        std::cout << "The string is invalid and does not belong to L(V).\n"; }
    return 0;
}
