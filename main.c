#include "database.h"
#include "abiturient.h"
#include "string.h"


void insert(char* dbFileName, tAbiturent* abiturent)
{
    tDatabase database = Database_Create(dbFileName);
    Database_Append(&database, abiturent);
    Database_Commit(&database);
}

void selectAll(char* dbFileName)
{
    tDatabase database = Database_Create(dbFileName);
    tAbiturent abiturent;

    printf("[SELECT] all\n");
    Abiturent_PrintTableHeader();
    while (Database_ReadNext(&database, &abiturent))
    {
        Abiturent_PrintTableLine(&abiturent);
    }
    printf("\n");
}

void selectWhereScoreEquals(char* dbFileName, int targetScore)
{
    tDatabase database = Database_Create(dbFileName);
    tAbiturent abiturent;

    printf("[SELECT] where [score] = %i\n", targetScore);
    Abiturent_PrintTableHeader();
    while (Database_ReadNext(&database, &abiturent))
    {
        if (ExamScore_Sum(&abiturent.examScore) == targetScore)
            Abiturent_PrintTableLine(&abiturent);
    }
    printf("\n");
}

void helpMessage(char* executableName)
{
    printf("[Abiturient DB]\n");
    printf("Show this help page\n");
    printf("\tUsage: %s --help\n", executableName);
    printf("\n");

    printf("List all abiturients\n");
    printf("\tUsage: %s <dbFile: str> select-all\n", executableName);
    printf("\n");

    printf("List abiturients with specified exam score sum\n");
    printf("\tUsage: %s <dbFile: str> select-where-score-eq <scoreSum: number>\n", executableName);
    printf("\n");

    printf("Insert abiturient\n");
    printf("\tUsage: %s <dbFile: str> insert \\\n", executableName);
    printf("\t\t<lastName: str> \\\n");
    printf("\t\t<initials: str> \\\n");
    printf("\t\t<gender: 'm' | 'f'> \\\n");
    printf("\t\t<schoolIndex: number> \\\n");
    printf("\t\t<hasMedal: '+' | '-'> \\\n");
    printf("\t\t<russian: number> \\\n");
    printf("\t\t<math: number> \\\n");
    printf("\t\t<physics: number> \\\n");
    printf("\t\t<computerScience: number> \\\n");
    printf("\t\t<passedEssay: '+' | '-'>");
    printf("\n");
    printf("\n");
}

void errorMessage(char* error)
{
    printf("Error: %s\n", error);
    printf("Try to use --help\n");
}

tGender parseGender(char* text)
{
    if (strcmp(text, "male") == 0 || strcmp(text, "m") == 0 || strcmp(text, "0") == 0)
    {
        return GENDER_MALE;
    }
    if (strcmp(text, "female") == 0 || strcmp(text, "f") == 0 || strcmp(text, "1") == 0)
    {
        return GENDER_FEMALE;
    }
    return GENDER_OTHER;
}


int main(int nArgs, char *args[])
{
    const int FIRST_ARG_INDEX = 3;

    if (nArgs <= 1 || strcmp(args[1], "-h") == 0 || strcmp(args[1], "--help") == 0 || strcmp(args[1], "help") == 0)
    {
        helpMessage(args[0]);
        return 0;
    }

    if (nArgs < 3)
    {
        errorMessage("Not enough arguments");
        return 1;
    }

    char* dbFileName = args[1];
    char* verb = args[2];

    if (strcmp(verb, "insert") == 0)
    {
        int index = FIRST_ARG_INDEX;

        if (nArgs != 10 + FIRST_ARG_INDEX)
        {
            errorMessage("[insert] Wrong arguments count");
            return 1;
        }

        tAbiturent abiturent;

        strncpy(abiturent.lastName, args[index++], sizeof(abiturent.lastName));
        strncpy(abiturent.initials, args[index++], sizeof(abiturent.initials));

        abiturent.gender = parseGender(args[index++]);

        sscanf(args[index++], "%i", &abiturent.schoolIndex);

        abiturent.hasMedal = strcmp(args[index++], "+") == 0;

        sscanf(args[index++], "%i", &abiturent.examScore.russian);
        sscanf(args[index++], "%i", &abiturent.examScore.math);
        sscanf(args[index++], "%i", &abiturent.examScore.physics);
        sscanf(args[index++], "%i", &abiturent.examScore.computerScience);

        abiturent.passedEssay = strcmp(args[index++], "+") == 0;

        insert(dbFileName, &abiturent);

        return 0;
    }

    if (strcmp(verb, "select-all") == 0)
    {
        if (nArgs != 3)
        {
            errorMessage("[select-all] Wrong arguments count");
            return 1;
        }

        selectAll(dbFileName);
        return 0;
    }

    if (strcmp(verb, "select-where-score-eq") == 0)
    {
        if (nArgs != 1 + FIRST_ARG_INDEX)
        {
            errorMessage("[select-where-score-eq] Wrong arguments count");
            return 1;
        }

        int targetScore;
        sscanf(args[3], "%i", &targetScore);

        selectWhereScoreEquals(dbFileName, targetScore);
        return 0;
    }

    errorMessage("Unknown arguments");
    return 1;
}