#include <iostream>
#include <vector>

#include "../inc/mission.hpp"

using namespace std;

Mission::Mission(int _id, int _start_ts, int _end_ts,
    int _actual_end_ts, int _reward)
{
    this->id = _id;
    this->start_ts = _start_ts;
    this->end_ts = _end_ts;
    this->actual_end_ts = _actual_end_ts;
    this->reward = _reward;
}

Mission::Mission()
{

}

Mission::~Mission()
{

}

int Mission::get_id(void) const
{
    return this->id;
}

int Mission::get_start_ts(void) const
{
    return this->start_ts;
}

void Mission::set_end_ts(int _actual_end_ts)
{
    this->actual_end_ts = _actual_end_ts;
}

void Mission::print(void) const
{
    cout << "start timestamp: " << this->start_ts << endl;
    cout << "end timestamp: " << this->actual_end_ts << endl;
    cout << "reward: " << this->reward << endl;
}

TimeMission::TimeMission(int _id, int _start_ts, int _end_ts,
    int _actual_end_ts, int _reward, int _target_time)
    : Mission(_id, _start_ts, _end_ts, _actual_end_ts, _reward)
{
    this->target_time = _target_time;
}

TimeMission::TimeMission()
{

}

TimeMission::~TimeMission()
{
    
}

Mission* TimeMission::clone(void) const
{
    return new TimeMission(*this);
}

bool TimeMission::is_completed(const vector<Travel*> travels) const
{
    int travel_time = 0;

    for (Travel* travel : travels) {
        if (travel->get_start_ts() >= this->start_ts &&
            travel->get_end_ts() <= this->end_ts) {
            travel_time += travel->get_duration();
        }
    }
    return (travel_time >= this->target_time * 60) ? true : false;
}

DistanceMission::DistanceMission(int _id, int _start_ts, int _end_ts,
    int _actual_end_ts, int _reward, int _target_dist)
    : Mission(_id, _start_ts, _end_ts, _actual_end_ts, _reward)
{
    this->target_dist = _target_dist;
}

DistanceMission::DistanceMission()
{

}

DistanceMission::~DistanceMission()
{
    
}

Mission* DistanceMission::clone(void) const
{
    return new DistanceMission(*this);
}

bool DistanceMission::is_completed(const vector<Travel*> travels) const
{
    int travel_dist = 0;

    for (Travel* travel : travels) {
        if (travel->get_start_ts() >= this->start_ts &&
            travel->get_end_ts() <= this->end_ts) {
            travel_dist += travel->get_distance();
        }
    }
    return (travel_dist >= this->target_dist) ? true : false;
}

CountMission::CountMission(int _id, int _start_ts, int _end_ts,
    int _actual_end_ts, int _reward, int _target_num)
    : Mission(_id, _start_ts, _end_ts, _actual_end_ts, _reward)
{
    this->target_num = _target_num;
}

CountMission::CountMission()
{

}

CountMission::~CountMission()
{
    
}

Mission* CountMission::clone(void) const
{
    return new CountMission(*this);
}

bool CountMission::is_completed(const vector<Travel*> travels) const
{
    int travel_count = 0;

    for (Travel* travel : travels) {
        if (travel->get_start_ts() >= this->start_ts &&
            travel->get_end_ts() <= this->end_ts) {
            travel_count++;
        }
    }
    return (travel_count >= this->target_num) ? true : false;
}
