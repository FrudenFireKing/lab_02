#include "../include/three.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

Three::Three() {
    digits.push_back(0);
}

Three::Three(const size_t& n, unsigned char t) {
    if (n == 0) {
        throw invalid_argument("Size cannot be zero");
    }
    
    if (!isValidTernaryDigit(t)) {
        throw invalid_argument("Invalid ternary digit");
    }
    
    digits.resize(n, t);
    removeLeadingZeros();
}

Three::Three(const initializer_list<unsigned char>& t) {
    if (t.size() == 0) {
        throw invalid_argument("Initializer list cannot be empty");
    }
    
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (!isValidTernaryDigit(*it)) {
            throw invalid_argument("Invalid ternary digit in initializer list");
        }
        digits.push_back(*it);
    }
    
    reverse(digits.begin(), digits.end());
    removeLeadingZeros();
}

Three::Three(const string& t) {
    if (t.empty()) {
        throw invalid_argument("String cannot be empty");
    }
    
    for (auto it = t.rbegin(); it != t.rend(); ++it) {
        unsigned char digit = charToDigit(*it);
        digits.push_back(digit);
    }
    
    removeLeadingZeros();
}

Three::Three(const Three& other) : digits(other.digits) {}

Three::Three(Three&& other) noexcept : digits(move(other.digits)) {}

Three::~Three() noexcept {}

void Three::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
    
    if (digits.empty()) {
        digits.push_back(0);
    }
}

bool Three::isValidTernaryDigit(unsigned char digit) const {
    return digit >= 0 && digit <= 2;
}

unsigned char Three::charToDigit(unsigned char c) const {
    if (c >= '0' && c <= '2') {
        return static_cast<unsigned char>(c - '0');
    }
    throw invalid_argument("Invalid character in ternary string");
}

char Three::digitToChar(unsigned char digit) const {
    if (!isValidTernaryDigit(digit)) {
        throw invalid_argument("Invalid ternary digit");
    }
    return static_cast<char>('0' + digit);
}

string Three::toString() const {
    string result;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result += digitToChar(*it);
    }
    return result;
}

Three Three::add(const Three& other) const {
    Three result;
    result.digits.clear();
    
    size_t maxSize = max(digits.size(), other.digits.size());
    unsigned char carry = 0;
    
    for (size_t i = 0; i < maxSize || carry != 0; ++i) {
        unsigned char sum = carry;
        
        if (i < digits.size()) 
            sum = static_cast<unsigned char>(sum + digits[i]);
        if (i < other.digits.size()) 
            sum = static_cast<unsigned char>(sum + other.digits[i]);
        
        result.digits.push_back(static_cast<unsigned char>(sum % 3));
        carry = static_cast<unsigned char>(sum / 3);
    }
    
    result.removeLeadingZeros();
    return result;
}

Three Three::subtract(const Three& other) const {
    if (lessThan(other)) {
        throw invalid_argument("Cannot subtract larger number from smaller");
    }
    
    if (equals(other)) {
        return Three();
    }
    
    Three result;
    result.digits.clear();
    
    int borrow = 0;
    
    for (size_t i = 0; i < digits.size(); ++i) {
        int diff = static_cast<int>(digits[i]) - borrow;
        
        if (i < other.digits.size()) {
            diff -= static_cast<int>(other.digits[i]);
        }
        
        if (diff < 0) {
            diff += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.digits.push_back(static_cast<unsigned char>(diff));
    }
    
    result.removeLeadingZeros();
    return result;
}

Three Three::addAndAssign(const Three& other) const {
    return add(other);
}

Three Three::subtractAndAssign(const Three& other) const {
    return subtract(other);
}

bool Three::equals(const Three& other) const {
    if (digits.size() != other.digits.size()) 
        return false;
    
    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i] != other.digits[i]) 
            return false;
    }
    
    return true;
}

bool Three::lessThan(const Three& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    
    return false;
}

bool Three::greaterThan(const Three& other) const {
    return !lessThan(other) && !equals(other);
}

bool Three::isZero() const {
    return (digits.size() == 1) && (digits[0] == 0);
}