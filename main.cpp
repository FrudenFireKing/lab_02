#include <iostream>
#include "three.h"

void demonstrateThreeClass() {
    std::cout << "=== Демонстрация класса Three для работы с троичными числами ===" << std::endl;
    
    std::cout << "\n1. Создание чисел:" << std::endl;
    
    Three num1;
    std::cout << "По умолчанию: " << num1.toString() << std::endl;
    
    Three num2(4, 2);
    std::cout << "Из размера и значения: " << num2.toString() << std::endl;
    
    Three num3{1, 2, 0, 1};
    std::cout << "Из списка инициализации: " << num3.toString() << std::endl;
    
    Three num4("2101");
    std::cout << "Из строки: " << num4.toString() << std::endl;
    
    std::cout << "\n2. Арифметические операции:" << std::endl;
    
    Three a("120");
    Three b("21");
    
    std::cout << a.toString() << " + " << b.toString() << " = ";
    Three sum = a.add(b);
    std::cout << sum.toString() << std::endl;
    
    std::cout << a.toString() << " - " << b.toString() << " = ";
    Three diff = a.subtract(b);
    std::cout << diff.toString() << std::endl;
    
    std::cout << "\n3. Операции с присваиванием:" << std::endl;
    
    Three c("12");
    Three d("10");
    Three result_add = c.addAndAssign(d);
    std::cout << c.toString() << " += " << d.toString() << " = " << result_add.toString() << std::endl;
    
    Three e("21");
    Three f("10");
    Three result_sub = e.subtractAndAssign(f);
    std::cout << e.toString() << " -= " << f.toString() << " = " << result_sub.toString() << std::endl;
    
    std::cout << "\n4. Операции сравнения:" << std::endl;
    
    Three x("210");
    Three y("120");
    
    std::cout << x.toString() << " > " << y.toString() << " : " 
              << (x.greaterThan(y) ? "true" : "false") << std::endl;
    
    std::cout << x.toString() << " < " << y.toString() << " : " 
              << (x.lessThan(y) ? "true" : "false") << std::endl;
    
    std::cout << x.toString() << " == " << y.toString() << " : " 
              << (x.equals(y) ? "true" : "false") << std::endl;
    
    std::cout << "\n5. Демонстрация иммутабельности:" << std::endl;
    
    Three original("121");
    Three original_copy = original;
    Three modified = original.add(Three("1"));
    
    std::cout << "Исходное число: " << original.toString() << std::endl;
    std::cout << "После операции: " << original_copy.toString() << " (не изменилось)" << std::endl;
    std::cout << "Новый объект: " << modified.toString() << std::endl;

    std::cout << "Адрес исходного объекта: " << &original << std::endl;
    std::cout << "Адрес объекта после операции: " << &original_copy << std::endl;

    std::cout << "\n8. Попытка 'изменить' объект (защита компилятором):" << std::endl;

    Three protected_num("210");
    Three new_num1 = protected_num.add(Three("1"));
    Three new_num2 = protected_num.subtract(Three("1"));

    Three num("100");
    std::cout << "Попытка изменить num = Three(\"200\"): ";
    num = Three("200");
    std::cout << num.toString() << std::endl;
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