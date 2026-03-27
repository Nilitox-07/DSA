#pragma once

#include <iostream>
#include <chrono>

// A simple static timer class
class Timer
{
private:
	std::chrono::steady_clock::time_point mBegin;
	std::chrono::steady_clock::time_point mEnd;

public:

	Timer() {

	}

	// Start the timer
	void Start();

	// Stop the timer
	void Stop();

	// Get the elapsed time (in milli, micro, and nano seconds)
	void Elapsed();
};

