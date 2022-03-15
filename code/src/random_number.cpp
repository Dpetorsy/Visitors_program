#include <random>

int random_number(const int l, const int r)
{
    // generate random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(l, r);

    return dis(gen);
}
