#ifndef TIMER_HPP
#define TIMER_HPP

#include <stdlib.h>
#include <sys/time.h>

class Timer
{
public:
	Timer()
	{
		start_count.tv_sec = start_count.tv_usec = 0;
		end_count.tv_sec = end_count.tv_usec = 0;

		stopped = 0;
		start_time = 0;
		end_time = 0;
	}

	void start()
	{
		stopped = 0; // reset stop flag
		gettimeofday(&start_count, NULL);
	}
	
	void stop()
	{
		stopped = 1; // set timer stopped flag
		gettimeofday(&end_count, NULL);
	}

	double get_elapsed_time()
	{
		if(!stopped)
			gettimeofday(&end_count, NULL);

		start_time = (start_count.tv_sec * 1000.0) + start_count.tv_usec * 0.001;
		end_time = (end_count.tv_sec * 1000.0) + end_count.tv_usec * 0.001;

		return end_time - start_time;
	}

private:
	double start_time;
	double end_time;
	int    stopped;
	timeval start_count;
	timeval end_count;
};

#endif
