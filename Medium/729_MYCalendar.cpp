class MyCalendar
{
public:
    map<int, int> m;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto next_interval = m.lower_bound(start); // search for a start greater or equal to 'start'

        if (next_interval != m.end() && next_interval->first < end) // if found and that interval starts before 'end' then false
            return false;
        if (next_interval != m.begin() && (--next_interval)->second > start) // if end of the interval is after 'start' then false 
            return false;
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */