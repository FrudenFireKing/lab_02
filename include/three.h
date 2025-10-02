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
    char dg_to_ch(unsigned char digit) const;

    Three();
    explicit Three(const size_t& n, unsigned char t = 0);
    Three(const std::initializer_list<unsigned char>& t);
    explicit Three(const std::string& t);
    Three(const Three& other);
    Three(Three&& other) noexcept;
    virtual ~Three() noexcept;

    size_t getSize() const { return digits.size(); }
    std::string tostr() const;
    const std::vector<unsigned char>& getdg() const { return digits; }

    Three plus(const Three& other) const;
    Three minus(const Three& other) const;
    
    Three plus_assign(const Three& other) const;
    Three minus_assign(const Three& other) const;

    bool equal(const Three& other) const;
    bool lower(const Three& other) const;
    bool bigger(const Three& other) const;

    bool iszero() const;
    
    Three& operator=(const Three& other) {
        (void)other;
        throw std::runtime_error("Для объекта Three нельзя присвоить новое значение!");
    }
    
    Three& operator=(Three&& other) {
        (void)other;
        throw std::runtime_error("Для объекта Three нельзя присвоить новое значение!");
    }
};

#endif 