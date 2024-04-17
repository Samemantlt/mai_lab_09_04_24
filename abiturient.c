#include "abiturient.h"
#include "stdio.h"


char* genderNames[] = { "Male", "Female", "Other" };


char boolToStr(bool value)
{
    return value ? '+' : '-';
}

void Abiturent_PrintTableHeader()
{
    printf("%-20s\t%-8s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
        "Last name",
        "Initials",
        "Gender",
        "School",
        "Medal",
        "Russian",
        "Math",
        "Physics",
        "C-Sci",
        "Sum",
        "Passed essay"
    );
}

void Abiturent_PrintTableLine(tAbiturent* abiturent)
{
    printf("%-20s\t%-8s\t%s\t%i\t%c\t%i\t%i\t%i\t%i\t%i\t%c\n",
        abiturent->lastName,
        abiturent->initials,
        genderNames[abiturent->gender],
        abiturent->schoolIndex,
        boolToStr(abiturent->hasMedal),
        abiturent->examScore.russian,
        abiturent->examScore.math,
        abiturent->examScore.physics,
        abiturent->examScore.computerScience,
        ExamScore_Sum(&abiturent->examScore),
        boolToStr(abiturent->passedEssay)
    );
}

int ExamScore_Sum(tExamScore* score)
{
    return score->russian +
        score->math +
        score->physics +
        score->computerScience;
}