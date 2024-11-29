#ifndef __MISSION_HPP
#define __MISSION_HPP

#include "travel.hpp"

class Mission {
protected:
    int id;
    int start_ts;
    int end_ts;
    int actual_end_ts;
    int reward;
public:
    Mission(int _id, int _start_ts, int _end_ts,
        int _actual_end_ts, int _reward);
    Mission();
    virtual ~Mission();
    virtual Mission* clone(void) const = 0;
    int get_id(void) const;
    int get_start_ts(void) const;
    void set_end_ts(int end_ts);
    virtual bool is_completed(std::vector<Travel*> travels) const = 0;
    void print(void) const;
};

class TimeMission : public Mission {
private:
    int target_time;
public:
    TimeMission(int _id, int _start_ts, int _end_ts,
        int _actual_end_ts, int _reward, int _target_time);
    TimeMission();
    virtual ~TimeMission();
    Mission* clone(void) const;
    bool is_completed(std::vector<Travel*> travels) const;
};

class DistanceMission : public Mission {
private:
    int target_dist;
public:
    DistanceMission(int _id, int _start_ts, int _end_ts,
        int _actual_end_ts, int _reward, int _target_dist);
    DistanceMission();
    virtual ~DistanceMission();
    Mission* clone(void) const;
    bool is_completed(std::vector<Travel*> travels) const;
};

class CountMission : public Mission {
private:
    int target_num;
public:
    CountMission(int _id, int _start_ts, int _end_ts,
        int _actual_end_ts, int _reward, int _target_num);
    CountMission();
    virtual ~CountMission();
    Mission* clone(void) const;
    bool is_completed(std::vector<Travel*> travels) const;
};

#endif /* __MISSION_HPP */
