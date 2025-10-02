#ifndef THREE_H
#define THREE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

class Three {
public:
    std::vector<unsigned char> digits;

    void rm_lead_zer();
    bool val_tern(unsigned char digit) const;
    unsigned char ch_to_dg(unsigned char c) const;
    char digitToChar(unsigned char digit) const;

    Three();
    explicit Three(const size_t& n, unsigned char t = 0);
    Three(const std::initializer_list<unsigned char>& t);
    explicit Three(const std::string& t);
    Three(const Three& other);
    Three(Three&& other) noexcept;
    virtual ~Three() noexcept;

    size_t getSize() const { return digits.size(); }
    std::string toString() const;
    const std::vector<unsigned char>& getDigits() const { return digits; }

    Three add(const Three& other) const;
    Three subtract(const Three& other) const;
    
    Three addAndAssign(const Three& other) const;
    Three subtractAndAssign(const Three& other) const;

    bool equals(const Three& other) const;
    bool lessThan(const Three& other) const;
    bool greaterThan(const Three& other) const;

    bool isZero() const;
    
    Three& operator=(const Three& other) {
        (void)other;
        throw std::runtime_error("Объект Three неизменяемый! Нельзя присвоить новое значение.");
    }
    
    Three& operator=(Three&& other) {
        (void)other;
        throw std::runtime_error("Объект Three неизменяемый! Нельзя присвоить новое значение.");
    }
};

#endif 