#include "database.h"
#include "string.h"


tDatabase Database_Create(char* dbFileName)
{
    tDatabase database;
    database.fileName = dbFileName;
    database.file = fopen(dbFileName, "a+");
    return database;
}

void Database_Append(tDatabase* database, tAbiturent* abiturent)
{
    fwrite(abiturent, sizeof(tAbiturent), 1, database->file);
}

void Database_Commit(tDatabase* database)
{
    fflush(database->file);
}

bool Database_ReadNext(tDatabase* database, tAbiturent* abiturent)
{
    int size = fread(abiturent, sizeof(tAbiturent), 1, database->file);
    return size == 1;
}