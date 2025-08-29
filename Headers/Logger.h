#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
#define COMMA ,

void LogError(const char * LogInfo);
void LogDebug(const char * LogInfo);
void OpenLogFile();
void CloseLogFile();

const int log_size = 60;
static char log_buffer[log_size] = {0};
const size_t max_log_buffer = sizeof(log_buffer);

const char LOG_FILE[] = "log/Logs.txt";

enum LogType
{
    LOG_TYPE_DEBUG,
    LOG_TYPE_ERROR
};

#define LOGERROR(LogInformation) \
    {\
    memset(log_buffer, 0, log_size);\
    snprintf(log_buffer,max_log_buffer, LogInformation);   \
    LogError(log_buffer);\
    }

#define LOGDEBUG(LogInformation) \
    {\
    memset(log_buffer, 0, log_size);\
    snprintf(log_buffer, max_log_buffer, LogInformation);   \
    LogDebug(log_buffer);\
    }

void ChangeDetalizationToDebug();

#endif
