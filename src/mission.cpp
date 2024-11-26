#include "../inc/mission.hpp"

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
