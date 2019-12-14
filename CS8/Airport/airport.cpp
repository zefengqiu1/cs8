#include "airport.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Bool_probability::Bool_probability(double p)
{
    assert(p >= 0);
    assert(p <= 1);
    _probability=p;

}

bool Bool_probability::query() const
{
    return (rand( ) < _probability * RAND_MAX);
}


averager::averager()
{
    count=0;
    sum=0;
}

void averager::next_number(double value)
{
    sum+=value;
    ++count;
}

int averager::count_of_plane()
{
    return count;
}

double averager::average()
{
    assert(count!=0);
    return sum/count;
}

landing_stripe::landing_stripe()
{
    time_left=0;
    time_to_work=0;
}


landing_stripe::landing_stripe(unsigned int time)
{
    time_to_work=time;
    time_left=0;
}

void landing_stripe::one_second()
{
    if(is_busy())
    {
        time_left--;
    }
}

void landing_stripe::set_time(unsigned int _time)
{
    time_to_work=_time;


}
bool landing_stripe::is_busy() const
{
    return time_left>0;
}
void landing_stripe::start()
{
    assert(!is_busy());
    time_left=time_to_work;
}

