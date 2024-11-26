#include <vector>

#include "../inc/driver.hpp"
#include "../inc/mission.hpp"

using namespace std;

Driver::Driver(int _id, Mission* _mission)
{
    this->id = _id;
    this->missions.push_back(_mission);
}

Driver::Driver()
{

}

Driver::~Driver()
{

}

int Driver::get_id(void)
{
    return this->id;
}

bool Driver::has_mission(int mission_id)
{
    for (Mission* mission : this->missions) {
        if (mission->get_id() == mission_id) {
            return true;
        }
    }
    return false;
}

void Driver::add_mission(Mission* mission)
{
    this->missions.push_back(mission);
}
