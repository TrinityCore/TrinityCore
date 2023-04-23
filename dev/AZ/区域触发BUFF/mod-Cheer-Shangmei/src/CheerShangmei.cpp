#pragma execution_character_set("utf-8")
#include "Config.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameObjectAI.h"
#include "Spell.h"
#include "Player.h"
#include "WorldSession.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

class Cheer_Shangmei : public GameObjectScript
{

public:
    Cheer_Shangmei() : GameObjectScript("Cheer_Shangmei_ss") { }


    struct Cheer_ShangmeiAI : public GameObjectAI
    {

        uint32 Cheer_Shangmei = sConfigMgr->GetIntDefault("Cheer.Shangmei_SPELL", 7897);

        Cheer_ShangmeiAI(GameObject* gameObject) : GameObjectAI(gameObject),

            timer{ 0 }
        {

        }

        void UpdateAI(uint32  diff)

        {

            timer += diff;
            
            if (timer > sConfigMgr->GetIntDefault("Cheer.Shangmei_time", 3000))
            {

                timer = 0;
                std::list<Player*> players;
                acore::AnyPlayerExactPositionInGameObjectRangeCheck checker(go, sConfigMgr->GetIntDefault("Cheer.Shangmei_distance", 20));
                acore::PlayerListSearcher<acore::AnyPlayerExactPositionInGameObjectRangeCheck> searcher(go, players, checker);
                go->VisitNearbyWorldObject(0.3f, searcher);

                if (players.size() > 0)
                {
                    std::list<Player*>::iterator itr = players.begin();
                    std::advance(itr, urand(0, players.size() - 1));
                    if (Creature* trigger = go->SummonTrigger((*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), 0, 2000, true))
                        trigger->CastSpell(trigger, Cheer_Shangmei);
                    
                }
                
            }
            
        }
    private:
        uint32 timer;
    };
    GameObjectAI* GetAI(GameObject* go) const
    {
        return new Cheer_ShangmeiAI(go);

    }
};

void AddCheerShangmeiScripts()
{
    new Cheer_Shangmei();
}
