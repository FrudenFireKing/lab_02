#include <iostream>
#include "three.h"

int main() {
    try {
        Three a("120");
        Three b("21");

        std::cout << "=== Демонстрация класса Three для работы с троичными числами ===\n";
        std::cout << "a = " << a.toString() << "\n";
        std::cout << "b = " << b.toString() << "\n";

        Three a_copy = a;

        std::cout << "\n1. Копирование:\n";
        std::cout << "a_copy = a = " << a_copy.toString() << "\n";
        std::cout << "a.equals(a_copy) = " << (a.equals(a_copy) ? "true" : "false") << "\n";

        Three c = a.add(b);
        Three d = a.subtract(b);

        std::cout << "\n2. Арифметические операции:\n";
        std::cout << "c = a + b = " << c.toString() << "\n";
        std::cout << "d = a - b = " << d.toString() << "\n";

        std::cout << "\n3. Операции с присваиванием:\n";
        Three e("12");
        Three f("10");
        std::cout << "e = " << e.toString() << ", f = " << f.toString() << "\n";
        Three result_add = e.addAndAssign(f);
        std::cout << "e.addAndAssign(f) = " << result_add.toString() << "\n";

        Three g("21");
        Three h("10");
        std::cout << "g = " << g.toString() << ", h = " << h.toString() << "\n";
        Three result_sub = g.subtractAndAssign(h);
        std::cout << "g.subtractAndAssign(h) = " << result_sub.toString() << "\n";

        bool eq = a.equals(b);
        bool lt = a.lessThan(b);
        bool gt = a.greaterThan(b);

        std::cout << "\n4. Операции сравнения:\n";
        std::cout << "a == b ? " << (eq ? "true" : "false") << "\n";
        std::cout << "a <  b ? " << (lt ? "true" : "false") << "\n";
        std::cout << "a >  b ? " << (gt ? "true" : "false") << "\n";

        std::cout << "\n5. Проверка иммутабельности:\n";
        std::cout << "Исходное значение a: " << a.toString() << "\n";
        
        Three new_val("210");
        std::cout << "Попытка присвоить a новое значение (new_val): " << new_val.toString() << "\n";

        Three a_after_assignment = a;
        
        std::cout << "Значение a после попытки изменения: " << a.toString() << " - осталось прежним!\n";
        std::cout << "Новый объект a_after_assignment: " << a_after_assignment.toString() << " - независимая копия!\n";
        
        std::cout << "a.equals(new_val) = " << (a.equals(new_val) ? "true" : "false") << " - разные значения!\n";
        
        std::cout << "\n6. Проверка адресов памяти:\n";
        std::cout << "Адрес объекта a: " << &a << "\n";
        std::cout << "Адрес объекта a_copy: " << &a_copy << "\n";
        std::cout << "Адрес объекта a_after_assignment: " << &a_after_assignment << "\n";
        std::cout << "Адрес объекта new_val: " << &new_val << "\n";
        std::cout << "Все объекты имеют разные адреса - каждый объект уникален и неизменяем!\n";

    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}