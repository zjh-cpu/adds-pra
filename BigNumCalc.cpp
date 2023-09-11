#include "BigNumCalc.h"
#include <list>
#include <string>

std::list<int> bigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char c : numString) {
        int digit = c - '0';
        result.push_back(digit);
    }
    return result;
}

std::list<int> bigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;

    while (!num1.empty() || !num2.empty() || carry) {
        int sum = carry;
        if (!num1.empty()) {
            sum += num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) {
            sum += num2.back();
            num2.pop_back();
        }

        result.push_front(sum % 10);
        carry = sum / 10;
    }

    return result;
}

std::list<int> bigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int borrow = 0;

    while (!num1.empty() || !num2.empty()) {
        int diff = borrow;
        if (!num1.empty()) {
            diff += num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) {
            diff -= num2.back();
            num2.pop_back();
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        result.push_front(diff);
    }

    // Remove leading zeros
    while (!result.empty() && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> bigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    if (num2.size() != 1) {
        // For simplicity, num2 should be a single-digit number
        return std::list<int>();
    }

    int digit2 = num2.front
