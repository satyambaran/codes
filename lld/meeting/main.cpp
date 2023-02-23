#include<bits/stdc++.h>
using namespace std;

class Meeting;
typedef vector<Meeting> Calendar;
class Room {
public:
    Room(string);
    bool book(int, int, int);
    Calendar getCalendar() const;
    void setCalendar(Calendar calendar);
    string getName() const;
    void setName(string name);

private:
    string name;
    Calendar calendar;
};

class Meeting {
public:
    Meeting(int, int, int, Room);
    int getEnd() const;
    void setEnd(int end);
    const Room& getRoom() const;
    void setRoom(const Room& room);
    int getStart() const;
    void setStart(int start);
    int getDay() const;
    void setDay(int day);

private:
    int start, end, day;
    Room room;
};

class Scheduler {
    vector<Room>rooms;
public:
    Scheduler(vector<Room>);
    string book(int, int, int);
};

int main() {
    Room room1("adarsh");
    Room room2("utkramit");
    Room room3("pariyojana");
    vector<Room> roomVec = { room1,room2, room3 };

    Scheduler scheduler(roomVec);

    cout<<scheduler.book(2, 5, 1)<<"\n";
    cout<<scheduler.book(5, 8, 2)<<"\n";
    cout<<scheduler.book(4, 8, 1)<<"\n";
    cout<<scheduler.book(3, 6, 2)<<"\n";
    cout<<scheduler.book(7, 8, 1)<<"\n";
    cout<<scheduler.book(6, 9, 2)<<"\n";
    return 0;
}

Room::Room(string name) {
    this->name = name;
}

Calendar Room::getCalendar() const {
    return calendar;
}

void Room::setCalendar(Calendar calendar) {
    this->calendar = calendar;
}

string Room::getName() const {
    return name;
}

void Room::setName(string name) {
    this->name = name;
}

bool Room::book(int start, int  end, int day) {
    Calendar calendar = getCalendar();
    for (Meeting m : calendar) {
        if (m.getDay()==day&&m.getStart()<end&&start<m.getEnd()) {
            return false;
        }
    }

    Meeting meeting(start, end, day, *this);
    calendar.push_back(meeting);
    setCalendar(calendar);
    return true;
}

Meeting::Meeting(int start, int end, int day, Room room):room(room) { //passed copy here
    // this->room = room; //? this wont work because
    //constructor for 'Meeting' must explicitly initialize the member 'room' which does not have a default constructor
    this->start = start;
    this->end = end;
    this->day = day;
}

int Meeting::getEnd() const {
    return end;
}

void Meeting::setEnd(int end) {
    this->end = end;
}

const Room& Meeting::getRoom() const {
    return room;
}

void Meeting::setRoom(const Room& room) {
    this->room = room;
}

int Meeting::getStart() const {
    return start;
}

void Meeting::setStart(int start) {
    this->start = start;
}

int Meeting::getDay() const {
    return day;
}

void Meeting::setDay(int day) {
    this->day = day;
}


Scheduler::Scheduler(vector<Room> rooms) {
    this->rooms = rooms;
}

string Scheduler::book(int start, int end, int day) {
    for (Room& room: rooms) {
        bool flag = room.book(start, end, day);
        if (flag==true) {
            return room.getName();
        }
    }
    return "No rooms booked";
}