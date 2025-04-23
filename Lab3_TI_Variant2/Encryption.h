#pragma once
#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <vector>
#include <cstdint>

/**
 * @brief Шифрует сообщение алгоритмом Эль-Гамаля
 *
 * @param message Входное сообщение (вектор байтов)
 * @param p Простое число (модуль)
 * @param g Первообразный корень по модулю p
 * @param y Открытый ключ (y = g^x mod p)
 * @return std::vector<int> Шифротекст в виде последовательности чисел (пары a,b)
 */
std::vector <uint8_t> EncryptMessage(const std::vector<uint8_t>& message, int p, int g, int y);

/**
 * @brief Дешифрует сообщение алгоритмом Эль-Гамаля
 *
 * @param ciphertext Шифротекст (вектор чисел, где a и b идут последовательно)
 * @param p Простое число (модуль)
 * @param x Закрытый ключ
 * @return std::vector<uint8_t> Расшифрованное сообщение
 * @throws std::invalid_argument Если размер ciphertext нечетный
 */
std::vector<uint8_t> DecryptMessage(const std::vector<uint8_t>& ciphertext, int p, int x);

#endif // ELGAMAL_H