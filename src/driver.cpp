#include <iostream>
#include <vector>

#include "../inc/driver.hpp"
#include "../inc/mission.hpp"

using namespace std;

Driver::Driver(int _id, Mission* _mission)
{
    this->id = _id;
    Mission* mission = _mission->clone();
    this->missions.push_back(mission);
}

Driver::Driver()
{

}

Driver::Driver(const Driver& driver)
{
    this->id = driver.id;
    for (Travel* _travel : driver.travels) {
        Travel* travel = new Travel(*_travel);
        this->travels.push_back(travel);
    }
    for (Mission* _mission : driver.missions) {
        Mission* mission = _mission->clone();
        this->missions.push_back(mission);
    }
}

Driver& Driver::operator=(const Driver& driver)
{
    this->id = driver.id;
    for (Travel* _travel : this->travels) {
        delete _travel;
    }
    for (Travel* trav : driver.travels) {
        Travel* travel = new Travel(*trav);
        this->travels.push_back(travel);
    }
    for (Mission* _mission : this->missions) {
        delete _mission;
    }
    for (Mission* _mission : driver.missions) {
        Mission* mission = _mission->clone();
        this->missions.push_back(mission);
    }
    return *this;
}

Driver::~Driver()
{
    for (auto travel : this->travels) {
        delete travel;
    }
    for (auto mission : this->missions) {
        delete mission;
    }
}

int Driver::get_id(void) const
{
    return this->id;
}

bool Driver::has_mission(int mission_id) const
{
    for (Mission* mission : this->missions) {
        if (mission->get_id() == mission_id) {
            return true;
        }
    }
    return false;
}

void Driver::add_mission(const Mission* _mission)
{
    Mission* mission = _mission->clone();
    for (list<Mission*>::iterator it = this->missions.begin();
            it != this->missions.end();
            ++it) {
        if ((*it)->get_start_ts() > (*it)->get_start_ts()) {
            this->missions.insert(it, mission);
            return;
        }
    }
    this->missions.push_back(mission);
}

void Driver::add_travel(const Travel& _travel)
{
    Travel* travel = new Travel(_travel);
    this->travels.push_back(travel);
    for (Mission* mission : this->missions) {
        if (mission->is_completed(this->travels)) {
            mission->set_end_ts(travel->get_end_ts());
        }
    }
}

void Driver::print_completed_missions(void) const
{
    for (Mission* mission : this->missions) {
        if (mission->is_completed(this->travels)) {
            cout << "mission: " << mission->get_id() << endl;
            mission->print();
        }
    }
}

bool Driver::has_any_mission(void) const
{
    return this->missions.empty() ? false : true; 
}

void Driver::print_missions_status(void) const
{
    for (Mission* mission : this->missions) {
        cout << "mission " << mission->get_id() << ":" << endl;
        mission->print();
        if (mission->is_completed(this->travels)) {
            cout << "status: completed" << endl;
        } else {
            cout << "status: ongoing" << endl;
        }
    }
}
