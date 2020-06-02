
#include <iostream>

using namespace std;

class Time
{
private:
    int _hour;
    int _minuts;
    int _seconds;
public:
    explicit Time() :_hour{ 0 }, _minuts{ 0 }, _seconds{}{}
    explicit Time(int hour,int minuts,int seconds) :_hour{ hour }, _minuts{ minuts }, _seconds{seconds}{}
    int getH() { return this->_hour; }
    int getM() { return this->_minuts; }
    int getS() { return this->_seconds; }


    void changeTime(int tm)
    {
        char symb;
        cout << "What do you want (+/-)? Timezone " << endl;
        cin >> symb;
        
        switch (symb)
        {
        case '+':
            this->_hour+=tm ;
            break;

        case'-':
              this->_hour-=tm;
              break;
        }
    }

    void changeStyle()
    {
        if (this->_hour >= 13)
        {
            cout << "(pm!--)";
           this->_hour-=12;
        }
        else if (this->_hour = 12)
        {
            cout << "(pm!++)";
        }
        else
        {
            cout << "(am!--)";
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& j);
    friend std::istream& operator>>(std::istream& in, Time& j);
};

 std::ostream& operator<<(std::ostream& out, const Time& j)
{
     out << j._hour << ":" << j._minuts << ":" << j._seconds << "\n";
     return out;
}

 std::istream& operator>>(std::istream& in, Time& j)
 {
     do {
     cout << "Enter corect time " << endl;
     cout << "Hou/min/sec" << endl;
     in >> j._hour;
     in >> j._minuts;
     in >> j._seconds;
    
     } while (j._hour > 23 || j._minuts > 60 || j._seconds > 60);
     
     return in;
 }




int main()
{
    Time a;
    cout << "Enter hours minutes and seconds separated by space" << endl;
    cin >> a;
   cout<<"Time is now - " << a;

     a.changeTime(2);
   cout<<"Time after change time zone:" << a << endl;
   a.changeStyle();
   cout << "Time after changing to american format:" << a << endl;
   
    
}

