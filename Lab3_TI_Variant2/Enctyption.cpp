#include "Math.h"
#include <iostream>
#include <vector>
#include <random>

int getChiperedSymbolSize(int p)
{
    int i = 1;
    while (1)
    {
        if (p > 256 * i && p < std::pow(256, i + 1))
        {
            return i + 1;
        }
        i++;
    }
}


std::vector<uint8_t> EncryptMessage(const std::vector<uint8_t>& message, int p, int g, int y) 
{
    // 2 байта    256 - 256*256
    // 3 байта    256*256 - 256*256*256
    // ...
    int bytesPerElement = getChiperedSymbolSize(p);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, p - 2);

    std::vector<uint8_t> cipheredText(message.size()*bytesPerElement*2);

    int index = 0;
    for (uint8_t m : message)
    {
      //  int k = dis(gen);
        int k = 41;
        int a = pow_mod(g, k, p);
        int yk = pow_mod(y, k, p);
        int b = (yk * m) % p;
        for (int i = 0; i < bytesPerElement; i++)
        {
            uint8_t partOfSymbol = static_cast<uint8_t>((a >> ((bytesPerElement - 1 - i) * 8)) & 0xFF);
            cipheredText[index++] = partOfSymbol;
        }
        for (int i = 0; i < bytesPerElement; i++)
        {
            uint8_t partOfSymbol = static_cast<uint8_t>((b >> ((bytesPerElement - 1 - i) * 8)) & 0xFF);
            cipheredText[index++] = partOfSymbol;
        }
    }

    return cipheredText;
}

int getValueFromVector(const std::vector<uint8_t>& vec, int index, int bytesPerElement)
{
    int result = 0;
    const int start_pos = index * bytesPerElement;
    for (int i = 0; i < bytesPerElement; ++i) {
        result = (result << 8) | static_cast<int>(vec[start_pos + i]);
    }

    return result;
}

std::vector<uint8_t> DecryptMessage(const std::vector<uint8_t>& ciphertext, int p, int x) 
{
    int symbolSize = getChiperedSymbolSize(p);
    if (ciphertext.size() % 2 != 0)
    {
        System::Windows::Forms::MessageBox::Show("Недопустима расшифровка текст нечетной длины!");
        return {};
    }
    std::vector<uint8_t> message(ciphertext.size()/2/symbolSize);

    int indexInMessage = 0;
    for (int i = 0; i < ciphertext.size() / 2; i += symbolSize) {
        int a = getValueFromVector(ciphertext, i, symbolSize);
        int b = getValueFromVector(ciphertext, i + 1, symbolSize);
        int ax = pow_mod(a, x, p);
        int ax_inv = pow_mod(ax, p - 2, p);
        int m = (b * ax_inv) % p;
        message[indexInMessage++] = static_cast<uint8_t>(m);
    }

    return message;
}