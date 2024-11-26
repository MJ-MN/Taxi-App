#ifndef __TRAVEL_HPP
#define __TRAVEL_HPP

class Travel {
private:
    int start_ts;
    int end_ts;
    int driver_id;
    int distance;
public:
    Travel(int _start_ts, int _end_ts, int _driver_id, int _distance);
    Travel();
    virtual ~Travel();
};

#endif /* __TRAVEL_HPP */
