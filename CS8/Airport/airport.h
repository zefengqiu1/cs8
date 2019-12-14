#ifndef AIRPORT_H
#define AIRPORT_H
#include <cstdlib>

class Bool_probability{

public:
    Bool_probability(double p=0.5);
    bool query() const;
private:
    double _probability;
};

class averager{
public:
    averager();
    void next_number(double value);
    int count_of_plane();
    double average();

private:
    double sum;
    int count;
};


class landing_stripe{
public:
    landing_stripe();
    landing_stripe(unsigned int time);
    bool is_busy() const;
    void one_second();
    void set_time(unsigned int _time);
    void start();

private:
    unsigned int time_to_work;
    unsigned int time_left;

};
#endif // AIRPORT_H
