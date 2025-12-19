#pragma once

#include <random>

std::mt19937& rng();

int randomInt(int min, int max);

double randomDouble(double min, double max);

float randomFloat(float min, float max);

template<typename T>
const T& randomFrom(const std::vector<T>& v);