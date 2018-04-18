//Created by Giuseppe Rizzi 2018
//basic timer for timing code execution and outputting in millisecond

#include <ctime>

#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
	long long int start_time;
	long long int stop_time;
	bool going;
	bool finished;
public:
	Timer();
	void start();
	void stop();
	long long int ms();
};

#endif
