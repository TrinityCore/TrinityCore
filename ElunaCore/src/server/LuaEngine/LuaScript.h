#ifndef _H_ELUNASCRIPT
#define _H_ELUNASCRIPT
#include "ScriptMgr.h"
#include "LuaEngine.h"

class ElunaScript : public ScriptObject
{
    static ElunaScript* _singleton;
    void setSingleton(ElunaScript* e) { _singleton = e; }

public:
    static ElunaScript* getSingleton()
    {
        return _singleton;
    }
    static bool hasSingleton()
    {
        return _singleton != NULL;
    }

    static void initialize()
    {
        if(!hasSingleton())
            new ElunaScript("MasterScript");
    }

    ElunaScript(char const* name);
    bool IsDatabaseBound() const { return false; }

    ~ElunaScript()
    {
        delete this;
    }
};
#endif