#include <iostream>
#include "three.h"

void demonstrateThreeClass() {
    std::cout << "=== Демонстрация класса Three для работы с троичными числами ===" << std::endl;
    
    std::cout << "\n1. Создание чисел:" << std::endl;
    
    Three num1;
    std::cout << "По умолчанию: " << num1.tostr() << std::endl;
    
    Three num2(4, 2);
    std::cout << "Из размера и значения: " << num2.tostr() << std::endl;
    
    Three num3{1, 2, 0, 1};
    std::cout << "Из списка инициализации: " << num3.tostr() << std::endl;
    
    Three num4("2101");
    std::cout << "Из строки: " << num4.tostr() << std::endl;
    
    std::cout << "\n2. Арифметические операции:" << std::endl;
    
    Three a("120");
    Three b("21");
    
    std::cout << a.tostr() << " + " << b.tostr() << " = ";
    Three sum = a.plus(b);
    std::cout << sum.tostr() << std::endl;
    
    std::cout << a.tostr() << " - " << b.tostr() << " = ";
    Three diff = a.minus(b);
    std::cout << diff.tostr() << std::endl;
    
    std::cout << "\n3. Операции с присваиванием:" << std::endl;
    
    Three c("12");
    Three d("10");
    Three result_add = c.plus_assign(d);
    std::cout << c.tostr() << " += " << d.tostr() << " = " << result_add.tostr() << std::endl;
    
    Three e("21");
    Three f("10");
    Three result_sub = e.minus_assign(f);
    std::cout << e.tostr() << " -= " << f.tostr() << " = " << result_sub.tostr() << std::endl;
    
    std::cout << "\n4. Операции сравнения:" << std::endl;
    
    Three x("210");
    Three y("120");
    
    std::cout << x.tostr() << " > " << y.tostr() << " : " 
              << (x.bigger(y) ? "true" : "false") << std::endl;
    
    std::cout << x.tostr() << " < " << y.tostr() << " : " 
              << (x.lower(y) ? "true" : "false") << std::endl;
    
    std::cout << x.tostr() << " == " << y.tostr() << " : " 
              << (x.equal(y) ? "true" : "false") << std::endl;
    
    std::cout << "\n5. Демонстрация иммутабельности:" << std::endl;
    
    Three number("121");
    Three number_copy = a;
    Three number_plus = a.plus(Three("1"));
    
    std::cout << "Исходное число: " << number.tostr() << std::endl;
    std::cout << "После операции: " << number_copy.tostr() << " (не изменилось)" << std::endl;
    std::cout << "Новый объект: " << number_plus.tostr() << std::endl;

    std::cout << "Адрес исходного объекта: " << &number << std::endl;
    std::cout << "Адрес объекта после операции: " << &number_copy << std::endl;

    std::cout << "\n6. Попытка 'изменить' объект (защита компилятором):" << std::endl;

    Three num("100");
    std::cout << "Попытка изменить num = Three(\"200\"): ";
    num = Three("200");
    std::cout << num.tostr() << std::endl;
}

int main() {
    try {
        demonstrateThreeClass();
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;

}

