#include <iostream>
#include <vector>

#include "../inc/mission.hpp"

using namespace std;

Mission::Mission(int _id, int _start_ts, int _end_ts, int _reward)
{
    this->id = _id;
    this->start_ts = _start_ts;
    this->end_ts = _end_ts;
    this->reward = _reward;
}

Mission::Mission()
{

}

Mission::~Mission()
{

}

int Mission::get_id(void)
{
    return this->id;
}

void Mission::print(void)
{
    cout << "mission: " << this->id << endl;
    cout << "start timestamp: " << this->start_ts << endl;
    cout << "end timestamp: " << this->end_ts << endl;
    cout << "reward: " << this->reward << endl;
}

TimeMission::TimeMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_time)
    : Mission(_id, _start_ts, _end_ts, _reward)
{
    this->target_time = _target_time;
}

TimeMission::TimeMission()
{

}

TimeMission::~TimeMission()
{
    
}

bool TimeMission::is_completed(vector<Travel*> travels)
{
    int travel_time = 0;

    for (Travel* travel : travels) {
        travel_time += travel->get_duration();
    }
    return (travel_time >= this->target_time * 60) ? true : false;
}

DistanceMission::DistanceMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_dist)
    : Mission(_id, _start_ts, _end_ts, _reward)
{
    this->target_dist = _target_dist;
}

DistanceMission::DistanceMission()
{

}

DistanceMission::~DistanceMission()
{
    
}

bool DistanceMission::is_completed(vector<Travel*> travels)
{
    int travel_dist = 0;

    for (Travel* travel : travels) {
        travel_dist += travel->get_distance();
    }
    return (travel_dist >= this->target_dist) ? true : false;
}

CountMission::CountMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_num)
    : Mission(_id, _start_ts, _end_ts, _reward)
{
    this->target_num = _target_num;
}

CountMission::CountMission()
{

}

CountMission::~CountMission()
{
    
}

bool CountMission::is_completed(vector<Travel*> travels)
{
    return (travels.size() >= this->target_num) ? true : false;
}
