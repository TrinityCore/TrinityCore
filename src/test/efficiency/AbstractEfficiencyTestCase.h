#pragma once

#include "../EngineTestBase.h"
#include "EfficiencyActionExecutionListener.h"

using namespace std;

namespace ai
{
    class AbstractEfficiencyTestCase : public EngineTestBase
    {
    public:
        void setUp()
        {
            EngineTestBase::setUp();
        }

    protected:
        void refresh(map<string, SpellInfo> spellInfo)
        {
            for (map<string, SpellInfo>::iterator i = spellInfo.begin(); i != spellInfo.end(); ++i)
            {
                spellAvailable(i->first);
            }
        }

        void run(map<string, SpellInfo> spellInfo, double mana)
        {
            EfficiencyActionExecutionListener* listener = new EfficiencyActionExecutionListener(ai, spellInfo, mana);
            engine->AddActionExecutionListener(listener);
            while (listener->CanContinue())
            {
                tick();
                refresh(spellInfo);
            }
            listener->Report();
        }
    };

}
