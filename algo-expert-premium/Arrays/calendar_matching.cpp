#include <bits/stdc++.h>
using namespace std;

struct StringMeeting
{
    string start;
    string end;
};

struct Meeting
{
    int start;
    int end;
};

int timeToMinutes(string time)
{
    int delimiterPos = time.find(":");
    int hours = stoi(time.substr(0, delimiterPos));
    int min = stoi(time.substr(delimiterPos + 1, time.length()));

    return (hours * 60) + min;
}

string minutesToTime(int min)
{
    int hours = min / 60;
    int mins = min % 60;
    string strHours = to_string(hours);
    string strMins = mins < 10 ? "0" + to_string(mins) : to_string(mins);

    return strHours + ":" + strMins;
}

vector<Meeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds)
{
    vector<StringMeeting> updatedCalendar;
    updatedCalendar.push_back({"0:00", dailyBounds.start});
    updatedCalendar.insert(updatedCalendar.end(), calendar.begin(), calendar.end());
    updatedCalendar.push_back({dailyBounds.end, "23:59"});

    vector<Meeting> calendarInMinutes;
    for (int i = 0; i < updatedCalendar.size(); i++)
    {
        calendarInMinutes.push_back({timeToMinutes(updatedCalendar[i].start), timeToMinutes(updatedCalendar[i].end)});
    }

    return calendarInMinutes;
}

vector<Meeting> mergeCalendars(vector<Meeting> calendar1, vector<Meeting> calendar2)
{
    vector<Meeting> mergedCalendars;
    // Merge the two calendar according to their starting time.
    int i = 0;
    int j = 0;

    while (i < calendar1.size() && j < calendar2.size())
    {
        if (calendar1[i].start < calendar2[j].start)
        {
            mergedCalendars.push_back(calendar1[i]);
            i++;
        }
        else
        {
            mergedCalendars.push_back(calendar2[j]);
            j++;
        }
    }

    while (i < calendar1.size())
    {
        mergedCalendars.push_back(calendar1[i++]);
    }
    while (j < calendar2.size())
    {
        mergedCalendars.push_back(calendar2[j++]);
    }

    return mergedCalendars;
}

vector<Meeting> flattenCalendar(vector<Meeting> calendar)
{

    vector<Meeting> flattened;
    flattened.push_back(calendar[0]);
    int currEnd = calendar[0].end;

    for (int i = 1; i < calendar.size(); i++)
    {
        if (calendar[i].end < currEnd)
            continue;
        if (calendar[i].start < currEnd)
        {
            currEnd = calendar[i].end;
        }
        else
        {
            flattened[flattened.size() - 1].end = currEnd;
            flattened.push_back(calendar[i]);
            currEnd = calendar[i].end;
        }
    }
    return flattened;
}

vector<StringMeeting> getMatchingBreaks(vector<Meeting> meetings, int duration)
{
    vector<Meeting> matchingBreaks;

    for (int i = 1; i < meetings.size(); i++)
    {
        if ((meetings[i].start - meetings[i - 1].end) >= duration)
        {
            matchingBreaks.push_back({meetings[i - 1].end, meetings[i].start});
        }
    }

    vector<StringMeeting> updatedMeetings;

    // convert into strings
    for (Meeting meeting : matchingBreaks)
    {
        updatedMeetings.push_back({minutesToTime(meeting.start), minutesToTime(meeting.end)});
    }
    return updatedMeetings;
}

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration)
{

    // get updated calendar1
    vector<Meeting> updatedCalendar1 = updateCalendar(calendar1, dailyBounds1);
    // get updated calendar2
    vector<Meeting> updatedCalendar2 = updateCalendar(calendar2, dailyBounds2);
    // Merge Calendars
    vector<Meeting> mergedCalendars = mergeCalendars(updatedCalendar1, updatedCalendar2);
    // flatten calendars
    vector<Meeting> flattenedMeetings = flattenCalendar(mergedCalendars);
    vector<StringMeeting> breaks = getMatchingBreaks(flattenedMeetings, meetingDuration);

    return breaks;
}

int main()
{

    // CALENDAR MATCHING PROBLEM

    vector<StringMeeting> calendar1 = {
        {"9:00", "10:30"},
        {"12:00", "13:00"},
        {"16:00", "18:00"}};

    StringMeeting dailyBounds1 = {"9:00", "20:00"};

    vector<StringMeeting> calendar2 = {
        {"10:00", "11:30"},
        {"12:30", "14:30"},
        {"14:30", "15:00"},
        {"16:00", "17:00"}};

    StringMeeting dailyBounds2 = {"10:00", "18:30"};

    int meetingDuration = 30;

    // Expected result
    /***
     *
     * 11:30-12:00
     * 15:00-16:00
     * 18:00-18:30
     *
     * ***/

    vector<StringMeeting> result = calendarMatching(calendar1, dailyBounds1, calendar2, dailyBounds2, meetingDuration);

    for (StringMeeting meeting : result)
    {
        cout << meeting.start << "-" << meeting.end << endl;
    }
    return 0;
}