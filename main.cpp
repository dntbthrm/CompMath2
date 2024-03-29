#include "equations.h"
#include "io.h"
#include "my_locale.h"
#include "single.h"
#include "systems.h"

#include <iostream>

using namespace std;
int main() {
    locale out_comma (cout.getloc(), new my_locale);
    cout.imbue(out_comma);
    locale in_comma (cin.getloc(), new my_locale);
    cin.imbue(in_comma);
    io io;
    equations equations;
    cout << "Для решения нелинейного уравнения введите 1 \nДля решения СНАУ введите 2" << endl;
    int task = io.get_task();
    switch(task){
        case 1:{
            single solve;
            cout << "Введите номер примера (от 1 до 4):" << endl;
            int number = io.get_example(task);
            auto equation = equations.get_equation(number);
            cout << "Укажите точность вычислений" << endl;
            double eps = io.get_accuracy();

            double a, b;
            cout << "Укажите интервал [a, b]" << endl;
            cin >> a >> b;
            cout << "Метод половинного деления:" << endl;
            solve.bisection(equation, a, b, eps);
            cout << "\n" << "Метод хорд: " << endl;
            solve.secant(equation, a, b, eps);
            break;
        }
        case 2:{
            systems solve;
            cout << "Введите номер примера (от 1 до 2):" << endl;
            int number = io.get_example(task);
            cout << "Укажите точность вычислений" << endl;
            double eps = io.get_accuracy();
            cout << "Введите начальные приближения корней" << endl;
            double a, b;
            cin >> a >> b;
            solve.newton_method(number, a, b, eps);
            break;
        }

    }
    return 0;
}
