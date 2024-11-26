#ifndef __DRIVER_HPP
#define __DRIVER_HPP

#include <vector>

#include "mission.hpp"

class Driver {
private:
    int id;
    std::vector<Mission*> missions;
public:
    Driver(int _id, Mission* _mission);
    Driver();
    virtual ~Driver();
    int get_id(void);
    bool has_mission(int mission_id);
    void add_mission(Mission* mission);
};

#endif /* __DRIVER_HPP */
