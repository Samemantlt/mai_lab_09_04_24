#pragma once

#include "stdbool.h"

typedef enum Gender {
    GENDER_MALE = 0,
    GENDER_FEMALE = 1,
    GENDER_OTHER = 2
} tGender;

typedef struct ExamScore {
    int russian;
    int math;
    int physics;
    int computerScience;
} tExamScore;

typedef struct Abiturent {
    char lastName[30];
    char initials[3];
    tGender gender;
    int schoolIndex;
    bool hasMedal;
    tExamScore examScore;
    bool passedEssay;
} tAbiturent;

void Abiturent_PrintTableHeader();

void Abiturent_PrintTableLine(tAbiturent* abiturent);

int ExamScore_Sum(tExamScore* score);