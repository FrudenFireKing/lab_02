#include <iostream>
#include "three.h"

int main() {
    std::cout << "=== Демонстрация класса Three для работы с троичными числами ===\n";
    
    std::cout << "\n1. Создание чисел:" << "\n";
    
    Three num1;
    std::cout << "По умолчанию: " << num1.tostr() << "\n";
    
    Three num2(4, 2);
    std::cout << "Из размера и значения: " << num2.tostr() << "\n";
    
    Three num3{1, 2, 0, 1};
    std::cout << "Из списка инициализации: " << num3.tostr() << "\n";
    
    Three num4("2101");
    std::cout << "Из строки: " << num4.tostr() << "\n";
    
    std::cout << "\n2. Арифметические операции:\n";
    
    Three a("120");
    Three b("21");
    
    std::cout << a.tostr() << " + " << b.tostr() << " = ";
    Three sum = a.plus(b);
    std::cout << sum.tostr() << "\n";
    
    std::cout << a.tostr() << " - " << b.tostr() << " = ";
    Three diff = a.minus(b);
    std::cout << diff.tostr() << "\n";
    
    std::cout << "\n3. Операции с присваиванием:" << "\n";
    
    Three c("12");
    Three d("10");
    Three result_add = c.plus_assign(d);
    std::cout << c.tostr() << " += " << d.tostr() << " = " << result_add.tostr() << "\n";
    
    Three e("21");
    Three f("10");
    Three result_sub = e.minus_assign(f);
    std::cout << e.tostr() << " -= " << f.tostr() << " = " << result_sub.tostr() << "\n";
    
    std::cout << "\n4. Операции сравнения:\n";
    
    Three x("210");
    Three y("120");
    
    std::cout << x.tostr() << " > " << y.tostr() << " : " 
              << (x.bigger(y) ? "true" : "false") << "\n";
    
    std::cout << x.tostr() << " < " << y.tostr() << " : " 
              << (x.lower(y) ? "true" : "false") << "\n";
    
    std::cout << x.tostr() << " == " << y.tostr() << " : " 
              << (x.equal(y) ? "true" : "false") << "\n";
    
    std::cout << "\n5. Демонстрация иммутабельности:\n";
    
    Three number("121");
    Three number_copy = a;
    Three number_plus = a.plus(Three("1"));
    
    std::cout << "Исходное число: " << number.tostr() << "\n";
    std::cout << "После операции: " << number_copy.tostr() << " (не изменилось)\n";
    std::cout << "Новый объект: " << number_plus.tostr() << "\n";

    std::cout << "Адрес исходного объекта: " << &number << "\n";
    std::cout << "Адрес объекта после операции: " << &number_copy << "\n";

    std::cout << "\n6. Попытка 'изменить' объект (защита компилятором):\n";
    try {
        Three num1("120");
        std::cout << "Создан объект: " << num1.tostr() << std::endl;
        
        Three num2("200");
        num1 = num2;
        
        std::cout << "ОШИБКА: объект изменился на " << num1.tostr() << std::endl;
    } 
    catch (const std::exception& ex) {
        std::cout << "УСПЕХ: " << ex.what() << std::endl;
        std::cout << "Объект остался неизменным (иммутабельный)" << std::endl;
    }
    
    return 0;
}