#pragma once

#include <chrono>

using namespace std::chrono;
//https://stackoverflow.com/questions/57042063/
//how-do-i-create-a-timer-for-the-program-with-clocking
template<class Resolution = seconds>
class Timer {
public:
    using Clock = std::conditional_t<high_resolution_clock::is_steady,
          high_resolution_clock, steady_clock>;

private:
    Clock::time_point startTime_;
    Clock::time_point timeToRunFor_;
    bool isRunning_ = false;

public:
    explicit Timer(int count) :
        startTime_{ Clock::now() },
        timeToRunFor_{ Clock::now() + Resolution(count) },
        isRunning_{ true }
    {
        run();
    }

    ~Timer() {
        const auto stopTime = Clock::now();
        std::ostringstream stream;
        stream << "Time Elapsed: "
               << duration_cast<Resolution>(stopTime - startTime_).count()
               << std::endl;
        std::cerr << stream.str() << std::endl;
    }

    bool isRunning() {
        return isRunning_;
    }

private:
    void run() {
        while (steady_clock::now() < timeToRunFor_) {}
        isRunning_ = false;
    }
};