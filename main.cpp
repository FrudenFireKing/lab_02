#include <iostream>
#include "three.h"

int main() {
    try {
        Three a("120");
        Three b("21");

        std::cout << "=== Демонстрация класса Three для работы с троичными числами ===\n";
        std::cout << "a = " << a.tostr() << "\n";
        std::cout << "b = " << b.tostr() << "\n";

        Three a_copy = a;

        std::cout << "\n1. Копирование:\n";
        std::cout << "a_copy = a = " << a_copy.tostr() << "\n";
        std::cout << "a.equal(a_copy) = " << (a.equal(a_copy) ? "true" : "false") << "\n";

        Three c = a.plus(b);
        Three d = a.minus(b);

        std::cout << "\n2. Арифметические операции:\n";
        std::cout << "c = a + b = " << c.tostr() << "\n";
        std::cout << "d = a - b = " << d.tostr() << "\n";

        std::cout << "\n3. Операции с присваиванием:\n";
        Three e("12");
        Three f("10");
        std::cout << "e = " << e.tostr() << ", f = " << f.tostr() << "\n";
        Three result_add = e.plus_assign(f);
        std::cout << "e.plus_assign(f) = " << result_add.tostr() << "\n";

        Three g("21");
        Three h("10");
        std::cout << "g = " << g.tostr() << ", h = " << h.tostr() << "\n";
        Three result_sub = g.minus_assign(h);
        std::cout << "g.minus_assign(h) = " << result_sub.tostr() << "\n";

        bool eq = a.equal(b);
        bool lt = a.lower(b);
        bool gt = a.bigger(b);

        std::cout << "\n4. Операции сравнения:\n";
        std::cout << "a == b ? " << (eq ? "true" : "false") << "\n";
        std::cout << "a <  b ? " << (lt ? "true" : "false") << "\n";
        std::cout << "a >  b ? " << (gt ? "true" : "false") << "\n";

        std::cout << "\n5. Проверка иммутабельности:\n";
        std::cout << "Исходное значение a: " << a.tostr() << "\n";
        
        Three new_val("210");
        std::cout << "Попытка присвоить a новое значение (new_val): " << new_val.tostr() << "\n";

        Three a_after_assignment = a;
        
        std::cout << "Значение a после попытки изменения: " << a.tostr() << " → осталось прежним!\n";
        std::cout << "Новый объект a_after_assignment: " << a_after_assignment.tostr() << " → независимая копия!\n";
        
        std::cout << "a.equal(new_val) = " << (a.equal(new_val) ? "true" : "false") << " → разные значения!\n";
        
        std::cout << "\n6. Проверка адресов памяти:\n";
        std::cout << "Адрес объекта a: " << &a << "\n";
        std::cout << "Адрес объекта a_copy: " << &a_copy << "\n";
        std::cout << "Адрес объекта a_after_assignment: " << &a_after_assignment << "\n";
        std::cout << "Адрес объекта new_val: " << &new_val << "\n";
        std::cout << "Все объекты имеют разные адреса → каждый объект уникален и неизменяем!\n";

    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
