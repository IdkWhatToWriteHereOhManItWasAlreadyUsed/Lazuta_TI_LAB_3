#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>
#include <cmath>
#include <Windows.h>
#include <intrin.h>
#include <random>

uint32_t ctz(uint32_t value)
{
    DWORD trailing_zero = 0;

    if (_BitScanForward(&trailing_zero, value))
    {
        return trailing_zero;
    }
    else
    {
        // This is undefined, I better choose 32 than 0
        return 32;
    }
}

uint32_t clz(uint32_t value)
{
    DWORD leading_zero = 0;

    if (_BitScanReverse(&leading_zero, value))
    {
        return 31 - leading_zero;
    }
    else
    {
        // Same remarks as above
        return 32;
    }
}

using namespace std;

// простые делители
vector<int> prime_factors(int n) {
    vector<int> factors;
    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// быстрое возведение в степень по модулю
int pow_mod(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b /= 2;
    }
    return res;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// проверка, является ли g первообразным корнем по модулю p
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

bool is_prime(int n, int k = 5) 
{
    if ((n & 1) == 0) return n == 2;
    if (n < 9) return n > 1; // 3, 5 и 7.

    int32_t s = ctz(n - 1);
    int32_t t = (n - 1) >> s;

    int32_t primes[3] = { 2, 3, 5 };

    for (int32_t a : primes) {
        int32_t x = pow_mod(a, t, n);

        if (x == 1) continue;

        for (int i = 1; x != n - 1; i++) {
            if (i == s) return false;

            x = (x * x) % n;

            if (x == 1) return false;
        }
    }
    return true;
}

// первообразные корни по модулю p
vector<int> find_primitive_roots(int p) {
    vector<int> roots;
    if (!is_prime(p)) {
        cerr << "Ошибка: p должно быть простым числом!" << endl;
        return roots;
    }
    if (p == 2) {
        roots.push_back(1);
        return roots;
    }
    int phi = p - 1;
    vector<int> factors = prime_factors(phi);

    for (int g = 2; g < p; ++g) {
        if (is_primitive_root(g, p, factors)) {
            roots.push_back(g);
        }
    }
    return roots;
}

// возведение в степень по модулю
int exp_module(int G, int X, int P) {
    int result = 1;
    G = G % P; 

    while (X > 0) 
    {
        if (X % 2 == 1) {
            result = (result * G) % P;
        }
        X = X >> 1; // div 2
        G = (G * G) % P;
    }

    return result;
}

int getRandomPrime(int min, int max) {
    if (min % 2 == 0) min++;
    if (min < 3) min = 3;   
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    while (true) {
        int candidate = dist(gen);
        if (candidate % 2 == 0) continue; 

        if (is_prime(candidate)) {
            return candidate;
        }
    }
}
