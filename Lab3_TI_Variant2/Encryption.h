#pragma once
#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <vector>
#include <cstdint>

/**
 * @brief ������� ��������� ���������� ���-������
 *
 * @param message ������� ��������� (������ ������)
 * @param p ������� ����� (������)
 * @param g ������������� ������ �� ������ p
 * @param y �������� ���� (y = g^x mod p)
 * @return std::vector<int> ���������� � ���� ������������������ ����� (���� a,b)
 */
std::vector <uint8_t> EncryptMessage(const std::vector<uint8_t>& message, int p, int g, int y);

/**
 * @brief ��������� ��������� ���������� ���-������
 *
 * @param ciphertext ���������� (������ �����, ��� a � b ���� ���������������)
 * @param p ������� ����� (������)
 * @param x �������� ����
 * @return std::vector<uint8_t> �������������� ���������
 * @throws std::invalid_argument ���� ������ ciphertext ��������
 */
std::vector<uint8_t> DecryptMessage(const std::vector<uint8_t>& ciphertext, int p, int x);

#endif // ELGAMAL_H