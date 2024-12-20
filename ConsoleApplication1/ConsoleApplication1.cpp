#include <iostream>
#include <vector>
#include <string>
#include <utility>

template <typename T>
void move_vectors(std::vector<T>& from, std::vector<T>& to) {

    to.reserve(from.size()); 
    for (auto& item : from) {
        to.push_back(std::move(item)); 
    }
    from.clear(); 
}

int main() 
{
    using namespace std;

    setlocale(LC_ALL, "Rus");

    vector<std::string> one = { "test_string1", "test_string2" };
    vector<std::string> two;

    move_vectors(one, two);
    
    cout << "Vector one: ";
    for (const auto& str : one) {
        std::cout << str << " ";
    }
    cout << "\n";

    cout << "Vector two: ";
    for (const auto& str : two) {
        std::cout << str << " ";
    }
    cout << "\n";

    return EXIT_SUCCESS;
}