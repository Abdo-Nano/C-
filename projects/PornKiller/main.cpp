#include <iostream>
#include <chrono>
#include <thread>
#include <future>


void timer() {
    std::chrono::seconds seconds (5);
    std::chrono::seconds zero (0);
    while ( zero.count() < seconds.count()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        ++zero;

        auto days = std::chrono::floor<std::chrono::days>(zero);
        auto time_of_day = zero - days;

        auto hours = std::chrono::floor<std::chrono::hours>(time_of_day);
        auto minutes = std::chrono::floor<std::chrono::minutes>(time_of_day - hours);
        auto secs = time_of_day - hours - minutes;

        std::cout << "Days: " << days.count()
                  << " Hours: " << hours.count()
                  << " Minutes: " << minutes.count()
                  << " Seconds: " << secs.count() << '\n';
        
    }
}



int main() {
    timer();
}