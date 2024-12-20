#include <iostream>
#include <string>
#include <algorithm>

class big_integer {
private:
    std::string number;

public:
    big_integer(const std::string& num) : number(num) {}

    big_integer(big_integer&& other) noexcept : number(std::move(other.number)) {}

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            number = std::move(other.number);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        std::string num1 = std::string(this->number.rbegin(), this->number.rend());
        std::string num2 = std::string(other.number.rbegin(), other.number.rend());

        std::string result;
        int carry = 0;

        size_t len1 = num1.length();
        size_t len2 = num2.length();
        size_t maxLength = std::max(len1, len2);

        for (size_t i = 0; i < maxLength || carry; ++i) {
            int digit1 = (i < len1) ? num1[i] - '0' : 0; 
            int digit2 = (i < len2) ? num2[i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        std::reverse(result.begin(), result.end());
        return big_integer(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& bi) {
        os << bi.number;
        return os;
    }
};

int main() {

    using namespace std;

    setlocale(LC_ALL, "Rsu");

    big_integer number1("114575");
    big_integer number2("78524");
    big_integer result = number1 + number2;

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}