#include <iostream>

#include "../inc/main.hpp"
#include "../inc/taxi.hpp"

using namespace std;

int main(void)
{
    Taxi taxi;
    string cmd, args[MAX_NUMBER_OF_ARGUMENTS];

    while (cin >> cmd) {
        if (cmd == "add_time_mission") {
            cin >> args[0] >> args[1] >> args[2] >> args[3] >> args[4];
            taxi.add_time_mission(args[0], args[1], args[2], args[3], args[4]);
        } else if (cmd == "add_distance_mission") {
            cin >> args[0] >> args[1] >> args[2] >> args[3] >> args[4];
            taxi.add_distance_mission(args[0], args[1], args[2], args[3], args[4]);
        } else if (cmd == "add_count_mission") {
            cin >> args[0] >> args[1] >> args[2] >> args[3] >> args[4];
            taxi.add_count_mission(args[0], args[1], args[2], args[3], args[4]);
        } else if (cmd == "assign_mission") {
            cin >> args[0] >> args[1];
            taxi.assign_mission(args[0], args[1]);
        } else if (cmd == "record_ride") {
            cin >> args[0] >> args[1] >> args[2] >> args[3];
            taxi.record_ride(args[0], args[1], args[2], args[3]);
        }
    }
}
