class MyCalendar {
public:
    vector<pair<int, int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto i: bookings)
            if (((i.first <= start && start < i.second) || (i.first < end && end <= i.second)) || (start <= i.first && i.second <= end))
                return false;
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */