#pragma once
#ifndef MATH_H
#define MATH_H

#include <vector>
#include <cstdint>

// Подсчет trailing zeros (количество младших нулевых битов)
uint32_t ctz(uint32_t value);

// Подсчет leading zeros (количество старших нулевых битов)
uint32_t clz(uint32_t value);

// Проверка на простоту (тест Миллера-Рабина)
bool is_prime(int n, int k = 5);

// Получение списка простых делителей числа
std::vector<int> prime_factors(int n);

// Быстрое возведение в степень по модулю
int pow_mod(long long a, long long b, long long mod);

// Проверка, является ли число первообразным корнем
bool is_primitive_root(int g, int p, const std::vector<int>& factors);

// Поиск всех первообразных корней по простому модулю p
std::vector<int> find_primitive_roots(int p);

// Альтернативная реализация возведения в степень по модулю
int exp_module(int G, int X, int P);

// Генерация случайного простого числа в диапазоне [min, max]
int getRandomPrime(int min, int max);

#endif // MATH_H