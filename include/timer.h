#pragma once

#include <chrono>
#include <functional>
#include <vector>

using Clock = std::chrono::steady_clock;
using namespace std::chrono;

struct Timer {
    milliseconds interval;
    Clock::time_point next;
    std::function<void()> callback;
};

struct TimerManager {
    std::vector<Timer> timers;
};

void addTimer(TimerManager *tm, std::chrono::milliseconds interval, std::function<void()> cb);

void update(TimerManager *tm);

milliseconds timeLeft(const Timer& t);