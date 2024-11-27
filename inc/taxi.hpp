#ifndef __TAXI_HPP
#define __TAXI_HPP

#include <string>
#include <vector>

#include "travel.hpp"
#include "driver.hpp"
#include "mission.hpp"

const std::string OK = "OK";
const std::string DUPLICATE_MISSION_ID = "DUPLICATE_MISSION_ID";
const std::string INVALID_ARGUMENTS = "INVALID_ARGUMENTS";
const std::string MISSION_NOT_FOUND = "MISSION_NOT_FOUND";
const std::string DUPLICATE_DRIVER_MISSION = "DUPLICATE_DRIVER_MISSION";

class Taxi {
private:
    std::vector<Driver*> drivers;
    std::vector<Mission*> missions;

    Mission* find_mission_by_id(int id);
    Driver* find_driver_by_id(int id);
public:
    Taxi();
    ~Taxi();
    void add_time_mission(std::string mission_id, std::string start_ts,
        std::string end_ts, std::string target_time, std::string reward);
    void add_distance_mission(std::string mission_id, std::string start_ts,
        std::string end_ts, std::string target_dist, std::string reward);
    void add_count_mission(std::string mission_id, std::string start_ts,
        std::string end_ts, std::string target_num, std::string reward);
    void assign_mission(std::string mission_id, std::string driver_id);
    void record_ride(std::string start_ts, std::string end_ts,
        std::string driver_id, std::string distance);
};

#endif /* __TAXI_HPP */
