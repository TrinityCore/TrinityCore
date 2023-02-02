#ifndef _PlayerbotTextMgr_H
#define _PlayerbotTextMgr_H

#include "Common.h"
#include "PlayerbotAIBase.h"

using namespace std;

class PlayerbotTextMgr
{
    public:
        PlayerbotTextMgr();
        virtual ~PlayerbotTextMgr();
        static PlayerbotTextMgr& instance()
        {
            static PlayerbotTextMgr instance;
            return instance;
        }

	public:
        string Format(string key, map<string, string> placeholders);

    private:
        void LoadTemplates();

    private:
        map<string, vector<string>> templates;
};

#define sPlayerbotTextMgr PlayerbotTextMgr::instance()

#endif
