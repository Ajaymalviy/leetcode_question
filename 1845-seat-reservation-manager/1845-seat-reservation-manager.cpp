#include <queue>
#include <set>
using namespace std;  // Adding using namespace std for convenience.

class SeatManager {
public:
    SeatManager(int n) {
        // Initialize available seats from 1 to n.
        for (int i = 1; i <= n; i++) {
            available_seats.push(i);
        }
    }

    int reserve() {
        // Fetch the smallest-numbered unreserved seat.
        int reserved_seat = available_seats.top();
        available_seats.pop();
        
        // Reserve the seat and return its number.
        reserved_seats.insert(reserved_seat);
        return reserved_seat;
    }

    void unreserve(int seatNumber) {
        // Unreserve the seat with the given seatNumber.
        if (reserved_seats.find(seatNumber) != reserved_seats.end()) {
            reserved_seats.erase(seatNumber);
            available_seats.push(seatNumber);
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> available_seats;
    set<int> reserved_seats;
};


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */