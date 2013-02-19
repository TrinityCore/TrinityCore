#ifndef _H_ELUNASCRIPT
#define _H_ELUNASCRIPT
#include "ScriptMgr.h"
#include "LuaEngine.h"

class ElunaScript : public ScriptObject
{
        static ElunaScript* m_singleton;
        void setSingleton(ElunaScript* e) { m_singleton = e; }

public:
        static ElunaScript* getSingleton()
        {
                return m_singleton;
        }
        static bool hasSingleton()
        {
                return m_singleton != NULL;
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