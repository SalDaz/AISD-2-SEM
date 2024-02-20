#include <iostream>
#include <chrono>

using namespace std;

// ������� ��� ���������� ����� ��������� ������
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

// ������� ��� ���������� ����� ��������� ����������
unsigned long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "������� ����� N: ";
    cin >> N;

    // ���������� ����� ��������� ������
    auto start_time = chrono::steady_clock::now();
    unsigned long long fib_loop = fibonacci_loop(N);
    auto loop_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time);

    // ���������� ����� ��������� ����������
    start_time = chrono::steady_clock::now();
    unsigned long long fib_recursive = fibonacci_recursive(N);
    auto recursive_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time);

    cout << N << "-�� ����� ������������������ ��������� (����): " << fib_loop << endl;
    cout << "��������� ����� ������: " << loop_time.count() << " �����������" << endl;

    cout << N << "-�� ����� ������������������ ��������� (��������): " << fib_recursive << endl;
    cout << "��������� ����� ���������: " << recursive_time.count() << " �����������" << endl;

    if (loop_time < recursive_time)
        cout << "����������� ����� �������." << endl;
    else if (loop_time > recursive_time)
        cout << "����������� ����� �������." << endl;
    else
        cout << "��� ������ ����������� �� ���������� �����." << endl;

    return 0;
}