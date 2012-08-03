#include "AppenderFile.h"
#include "Common.h"

AppenderFile::AppenderFile(uint8 id, std::string const& name, LogLevel level, const char* _filename, const char* _mode, bool _backup)
    : Appender(id, name, APPENDER_FILE, level)
    , filename(_filename)
    , mode(_mode)
    , backup(_backup)
{
    dynamicName = std::string::npos != filename.find("%u");
    if (!dynamicName)
        logfile = OpenFile(_filename, _mode, _backup);
}

AppenderFile::~AppenderFile()
{
    if (logfile)
    {
        fclose(logfile);
        logfile = NULL;
    }
}

void AppenderFile::_write(LogMessage& message)
{
    if (dynamicName)
    {
        char namebuf[TRINITY_PATH_MAX];
        snprintf(namebuf, TRINITY_PATH_MAX, filename.c_str(), message.param1);
        logfile = OpenFile(namebuf, mode, backup);
    }

    if (logfile)
    {
        fprintf(logfile, "%s %-5s [%-15s] %s", message.getTimeStr().c_str(), Appender::getLogLevelString(message.level), Appender::getLogFilterTypeString(message.type), message.text.c_str());

        fflush(logfile);

        if (dynamicName)
            fclose(logfile);
    }
}

FILE* AppenderFile::OpenFile(std::string const &filename, std::string const &mode, bool backup)
{
    if (mode == "w" && backup)
    {
        std::string newName(filename);
        newName.push_back('.');
        newName.append(LogMessage::getTimeStr(time(NULL)));
        rename(filename.c_str(), newName.c_str()); // no error handling... if we couldn't make a backup, just ignore
    }
    return fopen(filename.c_str(), mode.c_str());
}
