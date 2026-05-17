class MyCalendarTwo {
public:

    map<int, int> mp;

    MyCalendarTwo() {

    }

    bool book(int startTime, int endTime) {

        // mark start
        mp[startTime]++;

        // mark end
        mp[endTime]--;

        int bookings = 0;

        for(auto entry : mp) {

            bookings += entry.second;

            // triple booking found
            if(bookings > 2) {

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

This uses:

Line Sweep Algorithm

We store:

+1 at meeting start
-1 at meeting end

Then traverse timeline and count active bookings.

If active bookings become 3,
triple booking happened → return false.

Why Map?
map<int,int> mp;

Stores:

time -> change in bookings

Example:

10 -> +1
20 -> -1

Means:

booking starts at 10
booking ends at 20
Add Booking
mp[startTime]++;
mp[endTime]--;

Example:

book(10,20)

Map becomes:

10 -> +1
20 -> -1
Count Active Bookings
bookings += entry.second;

Running sum gives active meetings.

Triple Booking Condition

bookings>2

If true:

3 meetings overlap
invalid booking
Undo Changes

If triple booking occurs:

mp[startTime]--;
mp[endTime]++;

Removes the booking we added.

Remove Zero Values
if(mp[startTime] == 0)

Remove useless entries from map.

Dry Run
book(10,20)

Map:

10 -> +1
20 -> -1

Running bookings:

1 → 0

Max = 1

Return:

true
book(15,25)

Map:

10 -> +1
15 -> +1
20 -> -1
25 -> -1

Running:

1 → 2 → 1 → 0

Max = 2

Allowed.

Return:

true
book(17,22)

Map:

10 -> +1
15 -> +1
17 -> +1
20 -> -1
22 -> -1
25 -> -1

Running:

1 → 2 → 3

Triple booking.

Undo insertion.

Return:

false
Time Complexity

Each booking traverses map:

O(n)

For n bookings.

Space Complexity
O(n)

For storing timeline points. 

*/
