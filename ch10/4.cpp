#include <iostream>
#include <ctime>
#include <sstream>
#include <cstring>

using namespace std;

namespace Chrono {

    int day_per_month[] = {
        0,
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};

    int day_per_month_leap[] = {
        0,
        31, 29, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};


    class Date {
    public:
        enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
        static Date default_date;
    
        class Bad_date {};

        Date(int dd = 0, Month mm = Month(0), int yy = 0);
        ~Date();

        int day() const { return d; };
        Month month() const { return m; };
        int year() const { return y; };
        string string_rep() const;
        void char_rep(char s[]) const;

        static void set_default(int dd = 0, Month mm = Month(0), int yy = 0);

        Date &add_year(int n);
        Date &add_month(int n);
        Date &add_day(int n);

        bool operator==(Date &a);

    private:
        int d, y;
        Month m;
    };


    bool leapyear(int y)
    {
        return (y % 4) == 0;
    }

    Date Date::default_date(1, Month(1), 2012);

    Date::Date(int dd, Month mm, int yy)
    {
        cout << "constructor\n" << (void *)this << endl;
    
        if (yy == 0) yy = default_date.year();
        if (mm == 0) mm = default_date.month();
        if (dd == 0) dd = default_date.day();

        int max;

        switch (mm) {
            case feb:
                max = 28 + leapyear(yy);
                break;
            case apr: case jun: case sep: case nov:
                max = 30;
                break;
            case jan: case mar: case may: case jul: case aug: case oct: case dec:
                max = 31;
                break;
            default:
                throw Bad_date();
        }

        if (dd < 1 || max < dd) throw Bad_date();

        y = yy;
        m = mm;
        d = dd;

        cout << y << m << d << endl;

    }

    Date::~Date()
    {
        cout << "destructor\n";
    }



    void Date::set_default(int dd, Month mm, int yy)
    {
        time_t rawtime;
        struct tm * timeinfo;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        if (dd == 0)
            default_date.d = timeinfo->tm_mday;
        else
            default_date.d = dd;

        if (mm == 0)
            default_date.m = Month(timeinfo->tm_mon + 1);
        else
            default_date.m = mm;

        if (yy == 0)
            default_date.y = timeinfo->tm_year + 1900;
        else
            default_date.y = yy;

        cout << default_date.d << default_date.m << endl;
    }

    Date &Date::add_month(int n)
    {
        if (n == 0) return *this;
        if (n > 0) {
            int delta_y = n/12;
            int mm = m + n%12;
            if (12 < mm) {
                delta_y++;
                mm -= 12;
            }

            y += delta_y;
            m = Month(mm);
            return *this;
        }

        return *this;
    }

    Date &Date::add_year(int n)
    {
        if (d == 29 && m == Month(2) && !leapyear(y+n)) {
            d = 1;
            m = Month(3);
        }

        y += n;
        return *this;
    }

    Date &Date::add_day(int n)
    {
        if (n > 30)
        {
            cout << "not implemented" << endl;
            return *this;
        }
    
        if (0 != (y % 4))
        {
            if ((d+n) > day_per_month[int(m)])
            {
                d = (d+n) - day_per_month[int(m)];;
                add_month(1);
            }
            else
            {
                d += n;
            }
        }
        else
        {
            if ((d+n) >= day_per_month_leap[int(m)])
            {
                d = (d+n) - day_per_month_leap[int(m)];;
                add_month(1);
            }
            else
            {
                d += n;
            }
        }

        return *this;
    }

    string Date::string_rep() const
    {
        stringstream ss;
        ss << y << ":" << int(m) << ":" << d;
        string *sz = new string(ss.str());

        return *sz;
    }

    void Date::char_rep(char s[]) const
    {
        stringstream ss;
        ss << y << ":" << int(m) << ":" << d;
        string *sz = new string(ss.str());
        strcpy(s, sz->c_str());
    }

    inline bool Date::operator==(Date &a)
    {
        return a.day() == d &&
            a.month() == int(m) &&
            a.year() == y;
    }

}

using namespace Chrono;

int main(void)
{
    // default_date is initialized first
    cout << (void *)&Date::default_date << endl;
    
    Date ddd;
    char buf[12];

    cout << ddd.string_rep() << endl;

    ddd.char_rep(buf);
    cout << buf << endl;

    Date::set_default(); // 1
    Chrono::Date::set_default(); // 2

    Date new_ddd;

    Date comp_ddd;

    if (new_ddd == comp_ddd)
        cout << "operator== ok\n";
    else
        cout << "operator== failed\n";

    cout << new_ddd.string_rep() << endl;

    cout << new_ddd.add_day(30).string_rep() << endl;
    cout << new_ddd.add_month(12).string_rep() << endl;

    if (new_ddd == ddd)
        cout << "error in operator==\n";

}
