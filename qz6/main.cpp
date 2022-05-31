#include <iostream>
#include <string>

using namespace std;

class Clock {
  private:
    int h;
    int m;
    int s;
    string hour12;

  public:
    Clock(int hour, int minute, int second, string meridian) {
      hour == 0 || hour > 12 ? h = 12 : h = hour;
      minute > 59 ? m = 59 : m = minute;
      second > 59 ? s = 59 : s = second;
      hour12 = meridian;
    }
    int hour() { return h; }
    int minute() { return m; }
    int second() { return s; }
    string meridian() { return hour12; }
    void display() {
      cout << h << ":" << m << ":" << s << " " << hour12 << endl;
    }
};

class StandardClock : Clock {
  public:
    StandardClock(int hour, int minute, int second, string meridian)
        : Clock(hour, minute, second, meridian) {}
    void display() {
      if (meridian() == "AM") cout << "上午 ";
      if (meridian() == "PM") cout << "下午 ";
      cout << hour() << ":" << minute() << ":" << second() << endl;
    }
};

class MilitaryClock : Clock {
  public:
    MilitaryClock(int hour, int minute, int second, string meridian)
        : Clock(hour, minute, second, meridian) {}
    void display() {
      meridian() == "PM" ? cout << hour() + 12 : cout << hour();
      cout << ":" << minute() << ":" << second() << endl;
    }
};

int main() {
  Clock cc(10, 25, 43, "AM");
  StandardClock sc(10, 25, 43, "AM");
  MilitaryClock mc(10, 25, 43, "PM");
  cc.display();
  sc.display();
  mc.display();
  return 0;
}
