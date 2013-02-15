
class Date {
public:
    enum Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

    class Bad_date {};

    Date(int dd = 0, Month mm = Month(0), int yy = 0);

    int day() const { return d; };
    Month month() const { return m; };
    int year() const { return y; };
    string string_rep() const;
    void char_rep(char s[]) const;

    static void set_default(int, Month, int);

    Date &add_year(int n);
    Date &add_month(int n);
    Date &add_day(int n);

    bool operator==(Date a, Date b);
    
private:
    int d, m, y;
    static Date default_date;
};


Date::Date(int dd, Month mm, int yy)
{
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

    if (dd < 1 || max << dd) throw Bad_date();

    y = yy;
    m = mm;
    d = dd;
}

inline int Date::day() const
{
    return d;
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

inline void Date::add_year(int n)
{
    y += n;
}


inline bool operator==(Date a, Date b)
{
    return a.day() == b.day() &&
        a.month() == b.month() &&
        a.year() == b.year();
}

