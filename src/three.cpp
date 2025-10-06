#include "three.h"
#include <stdexcept>
#include <algorithm>

bool Three::isValidDigit(unsigned char c) const {
    return c >= '0' && c <= '2';
}

void Three::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == '0') {
        digits.pop_back();
    }
}

Three::Three() {
    digits.push_back('0');
}

Three::Three(const size_t& n, unsigned char t) {
    if (n == 0) {
        throw std::invalid_argument("Size cannot be zero");
    }
    if (!isValidDigit(t)) {
        throw std::invalid_argument("Invalid digit for ternary system");
    }
    
    digits.resize(n, t);
}

Three::Three(const std::string& t) {
    if (t.empty()) {
        throw std::invalid_argument("String cannot be empty");
    }
    
    for (size_t i = 0; i < t.length(); ++i) {
        if (!isValidDigit(t[i])) {
            throw std::invalid_argument("Invalid digit in string");
        }
    }
    
    for (int i = t.length() - 1; i >= 0; --i) {
        digits.push_back(t[i]);
    }
    
    removeLeadingZeros();
}

Three::Three(const Three& other) {
    digits = other.digits;
}

Three::~Three() {
}

std::string Three::toString() const {
    std::string result;
    for (int i = digits.size() - 1; i >= 0; --i) {
        result += digits[i];
    }
    return result;
}

bool Three::equals(const Three& other) const {
    return digits == other.digits;
}

bool Three::lessThan(const Three& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    
    return false;
}

bool Three::greaterThan(const Three& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() > other.digits.size();
    }
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] > other.digits[i];
        }
    }
    
    return false;
}

Three Three::add(const Three& other) const {
    Three result;
    result.digits.clear();
    
    size_t maxSize = std::max(digits.size(), other.digits.size());
    int carry = 0;
    
    for (size_t i = 0; i < maxSize || carry; ++i) {
        int sum = carry;
        
        if (i < digits.size()) {
            sum += digits[i] - '0';
        }
        if (i < other.digits.size()) {
            sum += other.digits[i] - '0';
        }
        
        carry = sum / 3;
        result.digits.push_back('0' + (sum % 3));
    }
    
    result.removeLeadingZeros();
    return result;
}

Three Three::subtract(const Three& other) const {
    if (this->lessThan(other)) {
        throw std::invalid_argument("Cannot subtract larger number");
    }
    
    Three result;
    result.digits.clear();
    
    int borrow = 0;
    
    for (size_t i = 0; i < digits.size(); ++i) {
        int current = digits[i] - '0' - borrow;
        int sub = (i < other.digits.size()) ? (other.digits[i] - '0') : 0;
        
        if (current < sub) {
            current += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.digits.push_back('0' + (current - sub));
    }
    
    result.removeLeadingZeros();
    return result;
}

Three Three::addAndAssign(const Three& other) {
    *this = this->add(other);
    return *this;
}

Three Three::subtractAndAssign(const Three& other) {
    *this = this->subtract(other);
    return *this;
}

size_t Three::size() const {
    return digits.size();
}