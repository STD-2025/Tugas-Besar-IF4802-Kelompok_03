#include "randomizer.h"

std::mt19937& rng() {
    static std::mt19937 engine{ std::random_device{}() };
    return engine;
}

int randomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng());
}

double randomDouble(double min, double max) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng());
}

float randomFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng());
}

template<typename T>
const T& randomFrom(const std::vector<T>& v) {
    return v[randomInt(0, static_cast<int>(v.size() - 1))];
}