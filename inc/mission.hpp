#ifndef __MISSION_HPP
#define __MISSION_HPP

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
};

class TimeMission : public Mission {
private:
    int target_time;
public:
    TimeMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_time);
    TimeMission();
    virtual ~TimeMission();
};

class DistanceMission : public Mission {
private:
    int target_dist;
public:
    DistanceMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_dist);
    DistanceMission();
    virtual ~DistanceMission();
};

class CountMission : public Mission {
private:
    int target_num;
public:
    CountMission(int _id, int _start_ts, int _end_ts, int _reward, int _target_num);
    CountMission();
    virtual ~CountMission();
};

#endif /* __MISSION_HPP */
