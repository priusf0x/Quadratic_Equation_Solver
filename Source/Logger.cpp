#include "Logger.h"

#include <stdio.h>
#include <stdlib.h>

enum LogType log_type = LOG_TYPE_ERROR;
FILE * log_file = NULL;

void LogError(const char * LogInformation)
{
    if (log_type == LOG_TYPE_DEBUG || log_type == LOG_TYPE_ERROR)\
    {
        fprintf(log_file, "<%s %s> ERROR: %s\n" , __DATE__, __TIME__, LogInformation);
    }
}

void LogDebug(const char * LogInformation)
{
    if (log_type == LOG_TYPE_DEBUG)
    {
        fprintf(log_file, "<%s %s> INFO: %s\n" , __DATE__, __TIME__, LogInformation);
    }
}

void OpenLogFile()
{
    log_file = fopen(LOG_FILE, "a+");
    if (log_file == NULL)
    {
        fprintf(stderr, "FAILED TO READ FILE\n");
        exit(EXIT_FAILURE);
        return;
    }
    fprintf(log_file, "-------------------------------------\n");
}

void CloseLogFile()
{
    if (fclose(log_file) != 0)
    {
        fprintf(stderr, "FAILED TO CLOSE FILE\n");
        exit(EXIT_FAILURE);
        return;
    }
}

void ChangeDetalizationToDebug()
{
    log_type = LOG_TYPE_DEBUG;
}




