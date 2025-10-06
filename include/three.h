#ifndef THREE_H
#define THREE_H

#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

class Three {
private:
    std::vector<unsigned char> digits;

    void removeLeadingZeros();
    bool isValidTernaryDigit(unsigned char digit) const;
    unsigned char charToDigit(unsigned char c) const;
    char digitToChar(unsigned char digit) const;

public:
    // Конструкторы
    Three();
    explicit Three(const size_t& n, unsigned char t = 0);
    Three(const std::initializer_list<unsigned char>& t);
    explicit Three(const std::string& t);
    Three(const Three& other);
    Three(Three&& other) noexcept;
    virtual ~Three() noexcept;

    // Методы доступа
    size_t getSize() const { return digits.size(); }
    std::string toString() const;
    const std::vector<unsigned char>& getDigits() const { return digits; }

    // Арифметические операции
    Three add(const Three& other) const;
    Three subtract(const Three& other) const;
    
    // Операции с присваиванием
    Three addAndAssign(const Three& other) const;
    Three subtractAndAssign(const Three& other) const;

    // Операции сравнения
    bool equals(const Three& other) const;
    bool lessThan(const Three& other) const;
    bool greaterThan(const Three& other) const;

    bool isZero() const;
    
    // Защита от присваивания
    Three& operator=(const Three& other) = delete;
    Three& operator=(Three&& other) = delete;
};

#endif