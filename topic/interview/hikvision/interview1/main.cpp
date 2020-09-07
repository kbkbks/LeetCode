/*
# Copyright (c) 2020 Xinyan Han. All rights reserved.
*/
#include <bits/stdc++.h>

using namespace std;

class StudentInfo {
 private:
    char * studentName;
    char number[10];
    char * specialty;

 public:
    StudentInfo() {}
    StudentInfo(string s, char num[10], string spe) {
        int name_num = s.size();
        studentName = new char[name_num];
        strcpy(studentName, s.c_str());
        strcpy(number, num);

        int spe_num = spe.size();
        specialty = new char[spe_num];
        strcpy(specialty, spe.c_str());
    }
    ~StudentInfo() {
        delete[] studentName;
        delete[] specialty;
    }
};

class Grades : StudentInfo {
 private:
    double score[6];
    double aveScore;

 public:
    Grades(double Score[6]) {
        memcpy(score, Score, 6 * sizeof(double));
        double sum = 0;
        for (int i = 0; i < 6; ++i) {
            sum += Score[i];
        }
        aveScore = sum / 6;
    }
};

int main() {
    double Score[6] = {1, 2, 3, 4, 5, 6};
    StudentInfo a("Jack", "101010101", "Automation");

    Grades grades(Score);

    return 0;
}
