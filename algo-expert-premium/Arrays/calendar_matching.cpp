#include <bits/stdc++.h>

using namespace std;

struct StringMeeting
{
    string start;
    string end;
};

typedef vector<StringMeeting *> vs;
typedef vector<vector<StringMeeting *>> vss;

int timeToMinutes(string time)
{
    int position = time.find(":");
    int minutes = stoi(time.substr(0, position));
    int hours = stoi(time.substr(position + 1, time.length()));
    return minutes + (hours * 60);
}

string minutesToTime(int minutes)
{
    int hours = minutes / 60;
    int minutes = minutes % 60;

    return "" + hours == 0 ? "00" : to_string(hours) + ":" + to_string(minutes);
}

StringMeeting *extractBreak(string start, string end, int duration)
{
    int diffMin = timeToMinutes(end) - timeToMinutes(start);
    StringMeeting *strMeeting = new StringMeeting();

    if (diffMin >= duration)
    {
        strMeeting->start = start;
        strMeeting->end = minutesToTime(timeToMinutes(start) + duration);
    }
    else
    {
        strMeeting = nullptr;
    }

    return strMeeting;
}

void extractBreaks(vector<StringMeeting> calendar1,
                   StringMeeting dailyBounds1,
                   vector<StringMeeting> calendar2,
                   StringMeeting dailyBounds2,
                   int meetingDuration, vs &breaks1, vs &breaks2)
{

    StringMeeting *strMeeting = extractBreak(dailyBounds1.start, calendar1[0].start, meetingDuration);
    if (strMeeting != nullptr)
    {
        breaks1.push_back(strMeeting);
    }

    strMeeting = extractBreak(dailyBounds2.start, calendar2[0].start, meetingDuration);
    if (strMeeting != nullptr)
    {
        breaks2.push_back(strMeeting);
    }

    for (int i = 0; i < (calendar1.size() - 1); i++)
    {
        strMeeting = extractBreak(calendar1[i].end, calendar1[i + 1].start, meetingDuration);
        if (strMeeting != nullptr)
        {
            breaks1.push_back(strMeeting);
        }
    }

    for (int i = 0; i < (calendar2.size() - 1); i++)
    {
        strMeeting = extractBreak(calendar2[i].end, calendar2[i + 1].start, meetingDuration);
        if (strMeeting != nullptr)
        {
            breaks2.push_back(strMeeting);
        }
    }
}
vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration)
{

    vs breaks1;
    vs breaks2;
    extractBreaks(calendar1,
                  dailyBounds1,
                  calendar2,
                  dailyBounds2,
                  meetingDuration, breaks1, breaks2);

    int i = 0;
    int j = 0;

    while(i < breaks1.size() && j < breaks2.size()){

       string start_time;

       int diffMin = timeToMinutes(breaks1[i].start) - timeToMinutes(breaks2[j].start);
       
       if(diffMin < 0){
              start_time = breaks2[j].start;
              bool notFound = true;

              while(notFound){
                int diff = timeToMinutes(start_time) - timeToMinutes(breaks2[j].end)
                if(abs(diff) >= diff){
                   
                }
              }
              
       }
          
        else start_time = breaks1[i].start;
       

    }
}

int main()
{

    return 0;
}