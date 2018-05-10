#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish;
};

//=============== Funções para configurar o sort ======================
bool activityCompare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}

bool activityCompare2(Activity s1, Activity s2)
{
    return (s1.start < s2.start);
}

bool activityCompare3(Activity s1, Activity s2)
{
    return ((s1.finish - s1.start) < (s2.finish - s2.start));
}
//=====================================================================

void printMaxActivities(Activity arr[], int n)
{
    sort(arr, arr+n, activityCompare);

    cout << "Atividades que podem ser feitas (pelo deadline): " << endl;

    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")";

    for (int j = 1; j < n; j++)
    {
      if (arr[j].start >= arr[i].finish)
      {
        cout << ", ";
        cout << "(" << arr[j].start << ","
            << arr[j].finish << ")";
        i = j;
      }
    }
    cout << endl;
}

void printWithStartTime(Activity arr[], int n){

    sort(arr, arr+n, activityCompare2);

    cout << "Atividades que podem ser feitas (pelo start time): " << endl;

    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")";

    for (int j = 1; j < n; j++)
    {
      if (arr[j].start >= arr[i].finish)
      {
        cout << ", ";
        cout << "(" << arr[j].start << ","
            << arr[j].finish << ")";
        i = j;
      }
    }
    cout << endl;
}

void printWithSlack(Activity arr[], int n){

    sort(arr, arr+n, activityCompare3);

    cout << "Atividades que podem ser feitas (pelo slack): " << endl;

    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")";

    for (int j = 1; j < n; j++)
    {
      if (arr[j].start >= arr[i].finish)
      {
        cout << ", ";
        cout << "(" << arr[j].start << ","
            << arr[j].finish << ")";
        i = j;
      }
    }
    cout << endl;
}

int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};

    int n = sizeof(arr)/sizeof(arr[0]);
    int j = 0;
    
    cout << "Atividades a serem analisadas (start time, deadline): " << endl;

    cout << "(" << arr[j].start << ","
        << arr[j].finish << ")";

    for (j = 1; j < n; j++)
    {
      cout << ", ";
      cout << "(" << arr[j].start << ","
          << arr[j].finish << ")";
    }
    cout << endl;
    cout << endl;
    printWithStartTime(arr, n);
    cout << endl;
    printWithSlack(arr, n);
    cout << endl;
    printMaxActivities(arr, n);
    return 0;
}
