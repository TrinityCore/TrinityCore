#ifndef _BOTDUMP_H
#define _BOTDUMP_H

#include "Define.h"

#include <fstream>
#include <string>

enum BotDataDumpResult
{
    //all
    BOT_DUMP_SUCCESS                    = 0,
    //write
    BOT_DUMP_FAIL_FILE_ALREADY_EXISTS,
    BOT_DUMP_FAIL_CANT_WRITE_TO_FILE,
    BOT_DUMP_FAIL_INCOMPLETE,
    //load
    BOT_DUMP_FAIL_FILE_NOT_EXIST,
    BOT_DUMP_FAIL_FILE_CORRUPTED,
    BOT_DUMP_FAIL_DATA_OCCUPIED
};

enum BotDataVerificationResult
{
    BOT_DATA_VALID                      = 0,
    BOT_DATA_NOT_EXIST,
    BOT_DATA_INCOMPLETE
};

class BotStringTransaction;

class NPCBotsDump
{
    public:
        NPCBotsDump() {}

        BotDataDumpResult Write(std::string const& file);
        BotDataDumpResult Load(std::string const& file);

    private:
        bool GetDump(std::string& dump);
        BotDataVerificationResult VerifyWriteData(uint32 entry) const;
        void AppendBotNPCBotData(BotStringTransaction* trans, uint32 entry) const;
        void AppendBotNPCBotTransmogData(BotStringTransaction* trans, uint32 entry) const;
        void AppendBotEquipsData(BotStringTransaction* trans, uint32 entry) const;
        void AppendBotCreatureData(BotStringTransaction* trans, uint32 entry) const;

        BotDataDumpResult LoadDump(std::ifstream& input);
};

#endif
