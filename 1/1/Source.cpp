#include <iostream>
#include <chrono>

using namespace std;

// Функция для вычисления числа Фибоначчи циклом
unsigned long long fibonacci_loop(int n) {
    if (n <= 1)
        return n;

    unsigned long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        unsigned long long temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

// Функция для вычисления числа Фибоначчи рекурсивно
unsigned long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "Введите число N: ";
    cin >> N;

    // Вычисление числа Фибоначчи циклом
    auto start_time = chrono::steady_clock::now();
    unsigned long long fib_loop = fibonacci_loop(N);
    auto loop_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time);

    // Вычисление числа Фибоначчи рекурсивно
    start_time = chrono::steady_clock::now();
    unsigned long long fib_recursive = fibonacci_recursive(N);
    auto recursive_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time);

    cout << N << "-ое число последовательности Фибоначчи (цикл): " << fib_loop << endl;
    cout << "Расчетное время циклом: " << loop_time.count() << " миллисекунд" << endl;

    cout << N << "-ое число последовательности Фибоначчи (рекурсия): " << fib_recursive << endl;
    cout << "Расчетное время рекурсией: " << recursive_time.count() << " миллисекунд" << endl;

    if (loop_time < recursive_time)
        cout << "Циклический метод быстрее." << endl;
    else if (loop_time > recursive_time)
        cout << "Рекурсивный метод быстрее." << endl;
    else
        cout << "Оба метода выполнились за одинаковое время." << endl;

    return 0;
}