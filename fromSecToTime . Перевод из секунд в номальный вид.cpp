#include <string>
#include <iostream>
#include <vector>

using namespace std;

string fromSecToTime(int seconds)
{
    if (seconds == 0)
        return "now";
    vector<int> V = {0, 0, 0, 0, 0};
    vector<int> times = {31536000, 86400, 3600, 60, 1};
    int I = 0;
    while (seconds > 0)
    {
        if (seconds - times[I] >= 0)
        {
            V[I]++;
            seconds -= times[I];
        }
        else
            I++;
    }
    string rez;
    int border = 0;
    for (int i = 0; i < V.size(); i++)
        if (V[i] != 0)
            border++;
    bool flag = false;
    for (int i = 0; i < V.size(); i++)
    {
        if (i == 0 && V[i] != 0)
        {
            if (V[i] == 1)
                rez += " " + to_string(V[i]) + " year";
            else
                rez += " " + to_string(V[i]) + " years";
            flag = true;
        }
        else if (i == 1 && V[i] != 0)
        {
            if (V[i] == 1)
                rez += " " + to_string(V[i]) + " day";
            else
                rez += " " + to_string(V[i]) + " days";
            flag = true;
        }
        else if (i == 2 && V[i] != 0)
        {
            if (V[i] == 1)
                rez += " " + to_string(V[i]) + " hour";
            else
                rez += " " + to_string(V[i]) + " hours";
            flag = true;
        }
        else if (i == 3 && V[i] != 0)
        {
            if (V[i] == 1)
                rez += " " + to_string(V[i]) + " minute";
            else
                rez += " " + to_string(V[i]) + " minutes";
            flag = true;
        }
        else if (i == 4 && V[i] != 0)
        {
            if (V[i] == 1)
                rez += " " + to_string(V[i]) + " second";
            else
                rez += " " + to_string(V[i]) + " seconds";
            flag = true;
        }
        if (border == 2 && flag)
        {
            if (rez.size() > 0)
            {
                rez += " and";
                border--;
            }
            flag = false;
        }
        else if (border > 2 && flag)
        {
            if (rez.size() > 0)
            {
                rez += ",";
                border--;
            }
            flag = false;
        }
    }
    rez.erase(0, 1);
    return rez;
}

int main()
{
    cout << fromSecToTime(2163045);
}