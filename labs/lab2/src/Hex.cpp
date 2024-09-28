#include "../include/Hex.h"

int CharToInt(unsigned char hexChar) {
    if (hexChar >= '0' && hexChar <= '9') {
        return hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        return hexChar - 'A' + 10;
    } else if (hexChar >= 'a' && hexChar <= 'f') {
        return hexChar - 'a' + 10;
    }
    throw std::logic_error("Invalid hexadecimal character");
}

char IntToChar(int intValue) {
    if (intValue >= 0 && intValue <= 9) {
        return '0' + intValue;
    } else if (intValue >= 10 && intValue <= 15) {
        return 'A' + (intValue - 10);
    }
    throw std::logic_error("Integer value out of hex range");
}

bool IsHex(unsigned char hexChar) {
    return (hexChar >= '0' && hexChar <= '9') || (hexChar >= 'A' && hexChar <= 'F') || (hexChar >= 'a' && hexChar <= 'f');
}

Hex::Hex() : size(0), capacity(0), digits(nullptr) {}

Hex::Hex(const size_t& count, unsigned char hexChar) {
    size = count;
    capacity = size * 2;
    digits = new unsigned char[capacity];
    if (!IsHex(hexChar)) {
        delete[] digits;
        digits = nullptr;
        size = 0;
        capacity = 0;
        throw std::logic_error("Provided character is not a valid hex digit");
    }
    for (size_t index = 0; index < size; ++index) {
        if (hexChar == '0' && size > 0) {
            digits[0] = '0';
            size = 1;
            break; 
        }
        digits[index] = hexChar;
    }
}

Hex::Hex(const std::initializer_list<unsigned char>& hexList) {
    size = hexList.size();
    capacity = size * 2;
    digits = new unsigned char[capacity];
    size_t index = size - 1;
    size_t insignificantZeroCount = 0;
    bool goodZero = false;
    for (const auto& hexChar : hexList) {
        if (!IsHex(hexChar)) {
            delete[] digits;
            digits = nullptr;
            size = 0;
            capacity = 0;
            throw std::logic_error("Invalid character in initializer list");
        }
        if (!goodZero && size != 1 && hexChar == '0' && index != 0) {
            ++insignificantZeroCount;
            --index;
            continue;
        }
        goodZero = true;
        digits[index--] = hexChar;
    }
    size -= insignificantZeroCount; // Уменьшаем размер после цикла
}

Hex::Hex(const std::string& hexString) {
    size = hexString.size();
    capacity = size * 2;
    digits = new unsigned char[capacity];
    size_t index = size - 1;
    size_t insignificantZeroCount = 0;
    bool goodZero = false;
    for (const auto& hexChar : hexString) {
        if (!IsHex(hexChar)) {
            delete[] digits;
            digits = nullptr;
            size = 0;
            capacity = 0;
            throw std::logic_error("Invalid character in string");
        }
        if (!goodZero && size != 1 && hexChar == '0' && index != 0) {
            ++insignificantZeroCount;
            --index;
            continue;
        }
        goodZero = true;
        digits[index--] = hexChar;
    }
    size -= insignificantZeroCount; // Уменьшаем размер после цикла
}

Hex::Hex(const Hex& other) {
    size = other.size;
    capacity = other.capacity;
    digits = new unsigned char[capacity];
    for (size_t index = 0; index < size; ++index) {
        digits[index] = other.digits[index];
    }
}

Hex::Hex(Hex&& other) noexcept {
    size = other.size;
    capacity = other.capacity;
    digits = other.digits;
    other.size = 0;
    other.capacity = 0;
    other.digits = nullptr;
}

void Hex::reallocate(const size_t& newCapacity) {
    unsigned char* newArray = new unsigned char[newCapacity];
    capacity = newCapacity;
    for (size_t index = 0; index < size; ++index) {
        newArray[index] = digits[index];
    }
    delete[] digits;
    digits = newArray;
}

size_t Hex::getsize() const {
    return size;
}

Hex::~Hex() noexcept {
    size = 0;
    capacity = 0;
    delete[] digits;
    digits = nullptr;
}

size_t Hex::HexToDecimal() const {
    size_t result = 0;
    for (size_t index = 0; index < size; ++index) {
        result += CharToInt(digits[index]) * (1 << (index * 4)); // Использование побитового сдвига
    }
    return result;   
}

std::string Hex::getvalue() const {
    std::string result(size, '\0');
    for (size_t index = 0; index < size; ++index) {
        result[size - index - 1] = static_cast<char>(digits[index]);
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, Hex& obj) {
    for (int index = obj.size - 1; index >= 0; --index) {
        out << obj.digits[index];
    }
    return out;
}

// Арифметические методы
Hex& Hex::copy(const Hex& other) {
    if (this != &other) {
        if (capacity < other.capacity) {
            reallocate(other.capacity);
        }
        size = other.size;
        for (size_t index = 0; index < size; ++index) {
            digits[index] = other.digits[index];
        }
    }
    return *this;
}

Hex& Hex::move(Hex&& other) {
    if (this != &other) {
        size = other.size;
        capacity = other.capacity;
        delete[] digits;
        digits = other.digits;

        other.digits = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

Hex& Hex::add_assign(const Hex& other) {
    if (capacity < other.capacity) {
        reallocate(other.capacity);
    }

    std::string result = "";
    int carry = 0;
    int index1 = 0;
    int index2 = 0;

    while (index1 < size || index2 < other.size || carry != 0) {
        int sum = carry;

        if (index1 < size) {
            sum += CharToInt(digits[index1++]); // Увеличиваем индекс сразу
        }

        if (index2 < other.size) {
            sum += CharToInt(other.digits[index2++]); // Увеличиваем индекс сразу
        }

        carry = sum / 16;
        sum %= 16;

        result = IntToChar(sum) + result;
    }

    size = result.size();
    
    for (size_t index = 0; index < result.size(); ++index) {
        digits[size - 1 - index] = result[index];
    }

    return *this;
}

Hex Hex::add(const Hex& other) const {
    Hex ans = *this;
    ans.add_assign(other);
    return ans;
}

Hex& Hex::subtract_assign(const Hex& other) {
    if (is_less(other)) {
        throw std::logic_error("The size of left value is less than size of right value");
    }
    
    if (other.size == 0) {
        return *this;
    }

    std::string result = "";
    int borrow = 0;

    int i = 0;
    int j = 0;

    while (i < size || j < other.size) {
        int digit1 = (i < size) ? CharToInt(digits[i]) : 0;
        int digit2 = (j < other.size) ? CharToInt(other.digits[j]) : 0;

        digit1 -= borrow;

        if (digit1 < digit2) {
            digit1 += 16;
            borrow = 1;
        } else {
            borrow = 0;
        }

        int difference = digit1 - digit2;

        result = result + IntToChar(difference);

        ++i;
        ++j;
    }

    bool goodzero = false;
    for (int i = result.size() - 1; i >= 0 && result.size() != 1; --i) {
        if (result[i] == '0' && !goodzero && i != 0) {
            result.erase(result.begin() + i);
            continue;
        }
        goodzero = true;
    }

    size = result.size();

    for(size_t i = 0; i < result.size(); ++i) {
        digits[i] = result[i];
    }

    return *this;
}

Hex Hex::subtract(const Hex& other) const {
    Hex ans = *this;
    ans.subtract_assign(other);
    return ans;
}

// Методы сравнения
bool Hex::is_equal(const Hex& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_t index = 0; index < size; ++index) {
        if (digits[index] != other.digits[index]) {
            return false;
        }
    }
    return true;
}

bool Hex::is_less(const Hex& other) const {
    if (size < other.size) {
        return true;
    }
    if (size > other.size) {
        return false;
    }
    for (size_t index = size; index > 0; --index) {
        if (digits[index - 1] < other.digits[index - 1]) {
            return true;
        }
        if (digits[index - 1] > other.digits[index - 1]) {
            return false;
        }
    }
    return false; // Они равны
}

bool Hex::is_greater(const Hex& other) const {
    return other.is_less(*this);
}

bool Hex::is_not_equal(const Hex& other) const {
    return !is_equal(other);
}

bool Hex::is_less_or_equal(const Hex& other) const {
    return is_less(other) || is_equal(other);
}

bool Hex::is_greater_or_equal(const Hex& other) const {
    return is_greater(other) || is_equal(other);
}
