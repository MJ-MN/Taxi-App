#include "../inc/travel.hpp"

Travel::Travel(int _start_ts, int _end_ts, int _driver_id, int _distance)
{
    this->start_ts = _start_ts;
    this->end_ts = _end_ts;
    this->driver_id = _driver_id;
    this->distance = _distance;
}

Travel::Travel()
{

}

Travel::~Travel()
{
    
}

int Travel::get_duration(void) const
{
    return (this->end_ts - this->start_ts);
}

int Travel::get_distance(void) const
{
    return this->distance;
}

int Travel::get_start_ts(void) const
{
    return this->start_ts;
}

int Travel::get_end_ts(void) const
{
    return this->end_ts;
}
