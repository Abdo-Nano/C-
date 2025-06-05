#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include <atomic>
#include <csignal>

using namespace std;
using namespace std::chrono;

atomic<bool> interrupt_flag(false);

void signal_handler(int) {
    interrupt_flag.store(true);
}

void countdown_timer(int days) {
    // Set up end time point
    auto end_time = system_clock::now() + hours(24 * days);

    while (!interrupt_flag.load()) {
        // Calculate remaining time
        auto remaining = duration_cast<seconds>(end_time - system_clock::now());

        // Check if countdown complete
        if (remaining.count() <= 0) {
            cout << "\nCountdown complete! " << days << " days have passed!" << endl;
            break;
        }

        // Calculate days, hours, minutes, seconds
        auto days_remaining = duration_cast<hours>(remaining).count() / 24;
        auto hours_remaining = duration_cast<hours>(remaining).count() % 24;
        auto minutes_remaining = duration_cast<minutes>(remaining).count() % 60;
        auto seconds_remaining = remaining.count() % 60;

        // Display the countdown
        cout << "\rDays: " << setw(2) << setfill('0') << days_remaining << " | "
             << "Hours: " << setw(2) << setfill('0') << hours_remaining << " | "
             << "Minutes: " << setw(2) << setfill('0') << minutes_remaining << " | "
             << "Seconds: " << setw(2) << setfill('0') << seconds_remaining << flush;

        // Wait for 1 second
        this_thread::sleep_for(seconds(1));
    }
}

int main() {
    // Set up signal handler for Ctrl+C
    signal(SIGINT, signal_handler);

    const int days = 90;
    cout << days << "-Day Countdown Timer" << endl;
    cout << "Press Ctrl+C to stop the timer" << endl << endl;

    try {
        countdown_timer(days);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    if (interrupt_flag.load()) {
        cout << "\n\nTimer stopped by user" << endl;
    }

    cout << "Goodbye!" << endl;
    return 0;
}