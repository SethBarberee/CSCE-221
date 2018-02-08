//Created by Giuseppe Rizzi 2018
#include "Timer.h"
#include <ctime>
#include <stdexcept>

using namespace std;

Timer::Timer(): going(false), finished(false), start_time(0), stop_time(0) {}

void Timer::start() {
	going = true;
	finished = false;
	start_time = clock();
}
	
void Timer::stop() {
	if (going) {
		stop_time = clock();
		finished = true;
		going = false;
	}
}

long long int Timer::ms() {
	if (finished)
		//this code stolen from http://www.cplusplus.com/forum/beginner/40563/
		return (stop_time-start_time)/double(CLOCKS_PER_SEC)*1000;
	else
		 throw runtime_error("The timer hasn't been run or hasn't finished running.");
	 return -1;
}
