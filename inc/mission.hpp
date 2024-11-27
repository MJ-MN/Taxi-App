#ifndef __MISSION_HPP
#define __MISSION_HPP

#include "travel.hpp"

class Mission {
private:
    int id;
    int start_ts;
    int end_ts;
    int reward;
public:
    Mission(int _id, int _start_ts, int _end_ts, int _reward);
    Mission();
    virtual ~Mission();
    int get_id(void);
    virtual bool is_completed(std::vector<Travel*> travels) = 0;
    void print(void);
};

class TimeMission : public Mission {
private:
    int target_time;
public:
    TimeMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_time);
    TimeMission();
    virtual ~TimeMission();
    bool is_completed(std::vector<Travel*> travels);
};

class DistanceMission : public Mission {
private:
    int target_dist;
public:
    DistanceMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_dist);
    DistanceMission();
    virtual ~DistanceMission();
    bool is_completed(std::vector<Travel*> travels);
};

class CountMission : public Mission {
private:
    int target_num;
public:
    CountMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_num);
    CountMission();
    virtual ~CountMission();
    bool is_completed(std::vector<Travel*> travels);
};

#endif /* __MISSION_HPP */
