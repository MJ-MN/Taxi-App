#ifndef __DRIVER_HPP
#define __DRIVER_HPP

#include <vector>

#include "travel.hpp"
#include "mission.hpp"

class Driver {
private:
    int id;
    std::vector<Travel*> travels;
    std::vector<Mission*> missions;
public:
    Driver(int _id, Mission* _mission);
    Driver();
    virtual ~Driver();
    int get_id(void);
    bool has_mission(int mission_id);
    void add_mission(Mission* mission);
    void add_travel(Travel* travel);
    void print_completed_missions(void);
};

#endif /* __DRIVER_HPP */
