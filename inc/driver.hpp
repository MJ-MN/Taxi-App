#ifndef __DRIVER_HPP
#define __DRIVER_HPP

#include <vector>
#include <list>

#include "travel.hpp"
#include "mission.hpp"

class Driver {
private:
    int id;
    std::vector<Travel*> travels;
    std::list<Mission*> missions;
public:
    Driver(int _id, Mission* _mission);
    Driver();
    Driver(const Driver& driver);
    Driver& operator=(const Driver& driver);
    virtual ~Driver();
    int get_id(void) const;
    bool has_mission(int mission_id) const;
    void add_mission(const Mission* _mission);
    void add_travel(const Travel& _travel);
    void print_completed_missions(void) const;
    void print_missions_status(void) const;
    bool has_any_mission(void) const;
};

#endif /* __DRIVER_HPP */
