#include "timer.h"

void addTimer(TimerManager *tm, std::chrono::milliseconds interval, std::function<void()> cb) {
    tm->timers.push_back({
        interval,
        Clock::now() + interval,
        std::move(cb)
    });
}

void update(TimerManager *tm) {
    auto now = Clock::now();
    for (auto &t : tm->timers) {
        if (now >= t.next) {
            t.callback();
            t.next += t.interval;
        }
    }
}

milliseconds timeLeft(const Timer& t) {
    auto now = Clock::now();
    if (t.next <= now) return std::chrono::milliseconds{0};
    return std::chrono::duration_cast<std::chrono::milliseconds>(t.next - now);
}