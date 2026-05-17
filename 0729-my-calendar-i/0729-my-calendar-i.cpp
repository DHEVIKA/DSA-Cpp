class MyCalendar {
public:

    map<int, int> mp;

    MyCalendar() {

    }

    bool book(int startTime, int endTime) {

        // add new booking
        mp[startTime]++;
        mp[endTime]--;

        int bookings = 0;

        for(auto entry : mp) {

            bookings += entry.second;

            // double booking found
            if(bookings > 1) {

                // undo changes
                mp[startTime]--;
                mp[endTime]++;

                // remove if value becomes 0
                if(mp[startTime] == 0) {
                    mp.erase(startTime);
                }

                if(mp[endTime] == 0) {
                    mp.erase(endTime);
                }

                return false;
            }
        }

        return true;
    }
};

/* 

Main Idea

Same as MyCalendar II.

But here:

only 1 booking allowed
if active bookings become 2 → invalid
Line Sweep Concept

We store:

+1 at start
-1 at end

Example:

book(10,20)

Map:

10 -> +1
20 -> -1
Running Active Bookings
bookings += entry.second;

Tracks how many meetings active currently.

Double Booking Condition

bookings>1

If true:

overlap exists
invalid booking
Undo Changes

If overlap happens:

mp[startTime]--;
mp[endTime]++;

Removes inserted booking.

Remove Zero Entries
if(mp[startTime] == 0)

Delete useless map entries.

Dry Run
book(10,20)

Map:

10 -> +1
20 -> -1

Running:

1 → 0

Valid.

Return:

true
book(15,25)

Map:

10 -> +1
15 -> +1
20 -> -1
25 -> -1

Running:

1 → 2

Double booking found.

Undo insertion.

Return:

false
book(20,30)

Map:

10 -> +1
20 -> -1
20 -> +1
30 -> -1

Effectively:

10 -> +1
30 -> -1

Running:

1 → 0

Valid.

Return:

true
Time Complexity

Each booking scans map:

O(n)
Space Complexity
O(n)

*/