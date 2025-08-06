#include <iostream>
#include <string>
using namespace std;
int main()
{
    double scoreSum = 0;
    double scoreGradeSum = 0;

    for (int i = 0; i < 20; i++)
    {
        string s;
        double score;
        string grade;

        cin >> s >> score >> grade;

        double temp;

        if (grade == "A+")
            temp = 4.5;
        else if (grade == "A0")
            temp = 4.0;
        else if (grade == "B+")
            temp = 3.5;
        else if (grade == "B0")
            temp = 3.0;
        else if (grade == "C+")
            temp = 2.5;
        else if (grade == "C0")
            temp = 2.0;
        else if (grade == "D+")
            temp = 1.5;
        else if (grade == "D0")
            temp = 1.0;
        else if (grade == "F")
            temp = 0.0;
        else
            continue;

        scoreSum += score;
        scoreGradeSum += score * temp;
    }

    cout << scoreGradeSum / scoreSum;
}