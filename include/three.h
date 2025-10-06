#ifndef THREE_H
#define THREE_H

#include <string>
#include <vector>

class Three {
private:
    std::vector<unsigned char> digits;
    void removeLeadingZeros();
    bool isValidDigit(unsigned char c) const;
    
public:
    Three();
    Three(const size_t& n, unsigned char t = 0);
    Three(const std::string& t);
    Three(const Three& other);

    ~Three();

    std::string toString() const;
    bool equals(const Three& other) const;
    bool lessThan(const Three& other) const;
    bool greaterThan(const Three& other) const;
    
    Three add(const Three& other) const;
    Three subtract(const Three& other) const;

    Three addAndAssign(const Three& other);
    Three subtractAndAssign(const Three& other);

    size_t size() const;
};

#endif