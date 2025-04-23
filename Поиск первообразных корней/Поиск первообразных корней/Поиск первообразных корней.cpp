#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция вычисления НОД
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Быстрое возведение в степень по модулю
int pow_mod(int a, int b, int mod) {
    int result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// Функция Эйлера φ(n)
int euler_phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Проверка, является ли число первообразным корнем
bool is_primitive_root(int g, int p, const vector<int>& factors) {
    if (gcd(g, p) != 1) return false;
    int phi = p - 1;
    for (int q : factors) {
        if (pow_mod(g, phi / q, p) == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    int p;
    cout << "Введите простое число: ";
    cin >> p;

    cout << "\n=== Анализ числа " << p << " ===" << endl;

    // Шаг 1: Проверка простоты (упрощенная)
    cout << "1. Проверка простоты: " << p << " - " << (p == 2 || p % 2 != 0 ? "простое" : "составное") << endl;

    // Шаг 2: Вычисление φ(p)
    int phi = p - 1;
    cout << "2. Fi(" << p << ") = " << p << " - 1 = " << phi << endl;

    // Шаг 3: Факторизация φ(p)
    vector<int> factors;
    int temp = phi;
    for (int i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            factors.push_back(i);
            while (temp % i == 0)
                temp /= i;
        }
    }
    if (temp > 1) {
        factors.push_back(temp);
    }

    cout << "3. Факторизация Fi(" << p << "): " << phi << " = ";
    for (size_t i = 0; i < factors.size(); ++i) {
        if (i != 0) cout << " * ";
        cout << factors[i];
    }
    cout << endl;

    // Шаг 4: Поиск первообразных корней
    cout << "\n4. Поиск первообразных корней:" << endl;
    cout << "   Условия: для каждого g от 1 до " << p - 1 << " проверяем:\n";
    for (int q : factors) {
        cout << "   - g^" << (phi / q) << " mod " << p << " != 1\n";
    }

    vector<int> primitive_roots;
    int total_checks = 0;

    cout << "\n5. Подробная проверка каждого кандидата:" << endl;
    for (int g = 1; g < p; ++g) {
        cout << "\n   Проверка g = " << g << ":\n";
        bool is_root = true;
        total_checks++;

        // Проверка НОД
        int g_gcd = gcd(g, p);
        cout << "   - НОД(" << g << "," << p << ") = " << g_gcd;
        if (g_gcd != 1) {
            cout << " -> не взаимно просты, пропускаем\n";
            is_root = false;
        }
        else {
            cout << " -> OK\n";
            // Проверка условий для каждого простого делителя
            for (int q : factors) {
                int exponent = phi / q;
                int result = pow_mod(g, exponent, p);
                cout << "   - " << g << "^" << exponent << " mod " << p << " = " << result;
                if (result == 1) {
                    cout << " == 1 -> не корень\n";
                    is_root = false;
                    break;
                }
                else {
                    cout << " != 1 -> OK\n";
                }
            }
        }

        if (is_root) {
            primitive_roots.push_back(g);
            cout << "   ==> " << g << " - первообразный корень!\n";
        }
    }

    // Шаг 5: Вывод результатов
    cout << "\n=== Результаты ===" << endl;
    cout << "Всего проверено кандидатов: " << total_checks << endl;
    cout << "Найдено первообразных корней: " << primitive_roots.size() << " (теория: Fi(" << phi << ") = " << euler_phi(phi) << ")" << endl;

    if (!primitive_roots.empty()) {
        cout << "\nСписок всех первообразных корней по модулю " << p << ":\n";
        for (size_t i = 0; i < primitive_roots.size(); ++i) {
            cout << primitive_roots[i];
            if (i != primitive_roots.size() - 1) cout << ", ";
            if ((i + 1) % 10 == 0) cout << endl;
        }
        cout << endl;

        cout << "\nНаименьший первообразный корень: " << primitive_roots.front() << endl;
        cout << "Наибольший первообразный корень: " << primitive_roots.back() << endl;
    }
    else {
        cout << "Первообразных корней не найдено!" << endl;
    }

    cin >> p;
    return 0;
}