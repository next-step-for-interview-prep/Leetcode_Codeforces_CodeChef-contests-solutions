#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 4 LEDS for hours
    vector<int>hours = {1,2,4,8};
    // 6 LEDS for minutes
    vector<int>mins = {1,2,4,8,16,32};
    // helper function : Ye 4 parameters lega :
    // a) result vector of strings
    // b) ek pair of hours and minutes jahan par time.first hour ko represent karega and time.second minutes ko
    // c) No_Of_LEDs : iska use hum kitne LEDs on karne reh gaye hai iske liye use karenge
    // d) idx : current position of pointer in vectors (hours and mins)
    void helper(vector<string>&res,pair<int,int>time,int No_Of_LEDs,int idx)
    {
        // agar number of LEDs zero hojaate hai iska matlab mujhe ek possible time milgaya jisse mein apne result vector mein add karlunga
        if(No_Of_LEDs==0)
        {
            // agar number of minutes less than 10 hai toh ":0" ko add karenge like this : "12:05"
            if(time.second<10)
            {
                res.push_back(to_string(time.first)+":0"+to_string(time.second));
            }
            // agar number of minutes greater than 10 hai toh ":" ko add karenge like this : "12:15"
            else
            {
                res.push_back(to_string(time.first)+":"+to_string(time.second));
            }
            return;
        }
        int n = hours.size();
        int m = mins.size();
        for(int i=idx;i<(m+n);i++)
        {
            // agar saare 6 LEDs hours waale check nahi kare abhi toh pehle unhe check karo
            if(i<n)
            {
                // current hour waale LED ko lelo
                time.first += hours[i];
                // agar hours less than 12 hai toh aage bado
                if(time.first<12)
                {
                    helper(res,time,No_Of_LEDs-1,i+1);
                }
                // backtracking step current hour jo liya tha usse remove karo taaki kisi aur hour waale LED ko use kar saken
                time.first -= hours[i];
            }
            // agar saare 6 LEDs hours waale check karliye toh ab minutes waale LEDs ko check karo
            else
            {
                // current minutes waale LED ko lelo
                time.second += mins[i-n];
                // agar minutes less than 60 hai toh aage bado
                if(time.second<60)
                {
                    helper(res,time,No_Of_LEDs-1,i+1);
                }
                // backtracking step current minutes jo liya tha usse remove karo taaki kisi aur minutes waale LED ko use kar saken
                time.second -= mins[i-n];
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        // ek vector of string le lenge return karne ke liye
        vector<string>res;
        // helper function ko call karenge
        helper(res,{0,0},turnedOn,0);
        return res;
    }
};



// class Solution
// {
//     public:
//     vector<int> hours = {1,2,4,8}, minutes={1,2,4,8,16,32};
//     void ans(vector<string> res, pair<int, int> time, int turnedOn, int startPoint)
//     {
//         if(turnedOn==0)
//         {
//             res.push_back(to_string(time.first) + (time.second<10 ? ":0" : ":") + to_string (time.second));
//             return;
//         }

//         for (int i = startPoint; i < hours.size() + minutes.size(); i++)
//         {
//             if(i<hours.size())
//             {
//                 time.first += hours[i-hours.size()];
//                 if(time.first<12) ans(res, time, turnedOn-1, i+1);
//                 time.first-= hours[i-hours.size()];
//             }

//             else
//             {
//                 time.second += minutes[i];
//                 if(time.second < 60) ans(res, time, turnedOn-1, i+1);
//                 time.second -= minutes[i];
//             }
//         }
        
//     }

//     vector<string> readBinaryWatch(int turnedOn)
//     {
//         vector<string> res;
//         ans(res, {0,0}, turnedOn, 0);
//         return res;
//     }
// };

// int main()
// {
    
//     return 0;
// }