#include "Timer.h"

// Start the timer
void Timer::Start() {
	mBegin = std::chrono::steady_clock::now();
}

// Stop the timer
void Timer::Stop() {
	mEnd = std::chrono::steady_clock::now();
}

// Get the elapsed time (in both micro and nano seconds)
void Timer::Elapsed() {
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(mEnd - mBegin).count() << " milliseconds\n";
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(mEnd - mBegin).count() << " microseconds\n";
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (mEnd - mBegin).count() << " nanoseconds\n";	
}


