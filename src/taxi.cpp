#include <iostream>
#include <string>

#include "../inc/taxi.hpp"

using namespace std;

Taxi::Taxi()
{

}

Taxi::~Taxi()
{
    for (auto driver : this->drivers) {
        delete driver;
    }
    for (auto mission : this->missions) {
        delete mission;
    }
}

Taxi::Taxi(const Taxi& taxi)
{
    for (Driver* _driver : taxi.drivers) {
        Driver* driver = new Driver(*_driver);
        this->drivers.push_back(driver);
    }
    for (Mission* _mission : taxi.missions) {
        Mission* mission = _mission->clone();
        this->missions.push_back(mission);
    }
}

Taxi& Taxi::operator=(const Taxi& taxi)
{
    for (Driver* _driver : taxi.drivers) {
        delete _driver;
    }
    for (Driver* _driver : taxi.drivers) {
        Driver* driver = new Driver(*_driver);
        this->drivers.push_back(driver);
    }
    for (Mission* _mission : this->missions) {
        delete _mission;
    }
    for (Mission* _mission : taxi.missions) {
        Mission* mission = _mission->clone();
        this->missions.push_back(mission);
    }
    return *this;
}

Mission* Taxi::find_mission_by_id(int id) const
{
    for (Mission* mission : this->missions) {
        if (mission->get_id() == id) {
            return mission;
        }
    }
    return NULL;
}

Driver* Taxi::find_driver_by_id(int id) const
{
    for (Driver* driver : this->drivers) {
        if (driver->get_id() == id) {
            return driver;
        }
    }
    return NULL;
}

void Taxi::add_time_mission(std::string mission_id, std::string start_ts,
    std::string end_ts, std::string target_time, std::string reward)
{
    if (mission_id.empty() ||
        start_ts.empty() ||
        end_ts.empty() ||
        target_time.empty() ||
        reward.empty()) {
        cout << INVALID_ARGUMENTS << endl;
        return;
    }
    int _mission_id = stoi(mission_id);
    int _start_ts = stoi(start_ts);
    int _end_ts = stoi(end_ts);
    int _target_time = stoi(target_time);
    int _reward = stoi(reward);

    if (this->find_mission_by_id(_mission_id) == NULL) {
        if (_start_ts <= _end_ts &&
            _target_time >= 0 &&
            _reward >= 0) {
            TimeMission* timeMission = new TimeMission(_mission_id, _start_ts,
                _end_ts, -1, _reward, _target_time);
            this->missions.push_back(timeMission);
            cout << OK << endl;
        } else {
            cout << INVALID_ARGUMENTS << endl;
        }
    } else {
        cout << DUPLICATE_MISSION_ID << endl;
    }
}

void Taxi::add_distance_mission(std::string mission_id, std::string start_ts,
    std::string end_ts, std::string target_dist, std::string reward)
{
    if (mission_id.empty() ||
        start_ts.empty() ||
        end_ts.empty() ||
        target_dist.empty() ||
        reward.empty()) {
        cout << INVALID_ARGUMENTS << endl;
        return;
    }
    int _mission_id = stoi(mission_id);
    int _start_ts = stoi(start_ts);
    int _end_ts = stoi(end_ts);
    int _target_dist = stoi(target_dist);
    int _reward = stoi(reward);

    if (this->find_mission_by_id(_mission_id) == NULL) {
        if (_start_ts <= _end_ts &&
            _target_dist >= 0 &&
            _reward >= 0) {
            DistanceMission* distanceMission = new DistanceMission(_mission_id, _start_ts,
                _end_ts, -1, _reward, _target_dist);
            this->missions.push_back(distanceMission);
            cout << OK << endl;
        } else {
            cout << INVALID_ARGUMENTS << endl;
        }
    } else {
        cout << DUPLICATE_MISSION_ID << endl;
    }
}

void Taxi::add_count_mission(std::string mission_id, std::string start_ts,
    std::string end_ts, std::string target_num, std::string reward)
{
    if (mission_id.empty() ||
        start_ts.empty() ||
        end_ts.empty() ||
        target_num.empty() ||
        reward.empty()) {
        cout << INVALID_ARGUMENTS << endl;
        return;
    }
    int _mission_id = stoi(mission_id);
    int _start_ts = stoi(start_ts);
    int _end_ts = stoi(end_ts);
    int _target_num = stoi(target_num);
    int _reward = stoi(reward);

    if (this->find_mission_by_id(_mission_id) == NULL) {
        if (_start_ts <= _end_ts &&
            _target_num >= 0 &&
            _reward >= 0) {
            CountMission* countMission = new CountMission(_mission_id, _start_ts,
                _end_ts, -1, _reward, _target_num);
            this->missions.push_back(countMission);
            cout << OK << endl;
        } else {
            cout << INVALID_ARGUMENTS << endl;
        }
    } else {
        cout << DUPLICATE_MISSION_ID << endl;
    }
}

void Taxi::assign_mission(std::string mission_id, std::string driver_id)
{
    if (mission_id.empty() ||
        driver_id.empty()) {
        cout << INVALID_ARGUMENTS << endl;
        return;
    }
    int _mission_id = stoi(mission_id);
    int _driver_id = stoi(driver_id);
    Mission* mission = this->find_mission_by_id(_mission_id);

    if (mission != NULL) {
        Driver* driver = this->find_driver_by_id(_driver_id);
        if (driver == NULL) {
            Driver* driver = new Driver(_driver_id, mission);
            this->drivers.push_back(driver);
            cout << OK << endl;
        } else if (!driver->has_mission(_mission_id)) {
            driver->add_mission(mission);
            cout << OK << endl;
        } else {
            cout << DUPLICATE_DRIVER_MISSION << endl;
        }
    } else {
        cout << MISSION_NOT_FOUND << endl;
    }
}

void Taxi::record_ride(std::string start_ts, std::string end_ts,
    std::string driver_id, std::string distance)
{
    if (start_ts.empty() ||
        end_ts.empty() ||
        driver_id.empty() ||
        distance.empty()) {
        cout << INVALID_ARGUMENTS << endl;
        return;
    }
    int _start_ts = stoi(start_ts);
    int _end_ts = stoi(end_ts);
    int _driver_id = stoi(driver_id);
    int _distance = stoi(distance);

    if (_start_ts <= _end_ts) {
        cout << "completed missions for driver " << driver_id << ":" << endl;
        Driver* driver = this->find_driver_by_id(_driver_id);
        driver->add_travel(Travel(_start_ts, _end_ts, _driver_id, _distance));
        driver->print_completed_missions();
    } else {
        cout << INVALID_ARGUMENTS << endl;
    }
}

void Taxi::show_missions_status(string driver_id) const
{
    if (driver_id.empty()) {
        cout << INVALID_ARGUMENTS << endl;
        return;
    }
    int _driver_id = stoi(driver_id);
    Driver* driver = this->find_driver_by_id(_driver_id);

    if (driver != NULL && driver->has_any_mission()) {
        cout << "missions status for driver " << driver_id << ":" << endl;
        driver->print_missions_status();
    } else {
        cout << DRIVER_MISSION_NOT_FOUND << endl;
    }
}
