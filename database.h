#pragma once

#include "abiturient.h"
#include "stdio.h"
#include "stdbool.h"

typedef struct Database
{
    char* fileName;
    FILE* file;
} tDatabase;

tDatabase Database_Create(char* dbFileName);

void Database_Append(tDatabase* database, tAbiturent* abiturent);

void Database_Commit(tDatabase* database);

bool Database_ReadNext(tDatabase* database, tAbiturent* abiturent);
