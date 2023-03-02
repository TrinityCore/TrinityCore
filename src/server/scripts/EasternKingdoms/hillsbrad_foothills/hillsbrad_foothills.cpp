/* Nostalrius
*Alita: j'inaugure ce fichier!
*
*
*
*/

/* ContentData
EndContentData */

#include "scriptPCH.h"

struct go_helcular_s_graveAI: public GameObjectAI
{
    go_helcular_s_graveAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        guid_helcular = 0;
    }

    uint64 guid_helcular;

    bool CheckHelcularSpawned()
    {
        if (Creature* pHelcular = me->GetMap()->GetCreature(guid_helcular))
            return true;
        return false;
    }

    void SetHelcularGuid(Creature* crea)
    {
        guid_helcular = crea->GetGUID();
    }
};

GameObjectAI* GetAIgo_helcular_s_grave(GameObject *pGo)
{
    return new go_helcular_s_graveAI(pGo);
}

bool QuestRewarded_go_helcular_s_grave(Player* pPlayer, GameObject* pGo, Quest const* pQuest)
{
    if (go_helcular_s_graveAI* pGraveAI = dynamic_cast<go_helcular_s_graveAI*>(pGo->AI()))
    {
        if (!pGraveAI->CheckHelcularSpawned())
        {
            if (Creature* helcular = pGo->SummonCreature(2433, -741.982f, -621.186f, 18.3853f, 2.05043f, TEMPSUMMON_DEAD_DESPAWN, 0))
                pGraveAI->SetHelcularGuid(helcular);
        }
    }
    return true;
}

enum
{
    NPC_CAPTURED_FARMER     = 2284,

    GO_TAINTED_KEG          = 1729,
    GO_TAINTED_KEG_SMOKE    = 1730
};

struct go_dusty_rugAI: public GameObjectAI
{
    go_dusty_rugAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        timer = 0;
        step = 0;
    }
    uint32 timer;
    GuidList Farmers;
    uint8 step;//0 = usual, nothing giong on // 1+ event going on

    void UpdateAI(uint32 const uiDiff) override
    {
        if (step)
        {
            if (timer < uiDiff)
            {
                Creature* curr = nullptr;
                switch (step)
                {
                    case 1:
                        float fX, fY, fZ;
                        if (GameObject* pKeg = me->FindNearestGameObject(GO_TAINTED_KEG, 10.000000))
                        {
                            std::list<Creature*> lCrea;
                            me->GetCreatureListWithEntryInGrid(lCrea, NPC_CAPTURED_FARMER, 30.0f);
                            for (const auto& it : lCrea)
                            {
                                if (it->IsAlive())
                                {
                                    Farmers.push_back(it->GetGUID());
                                    pKeg->GetContactPoint(it, fX, fY, fZ, CONTACT_DISTANCE);
                                    it->GetMotionMaster()->MovePoint(1, fX, fY, fZ, MOVE_PATHFINDING);
                                }
                            }
                        }
                        timer = 4500;
                        step++;
                        break;
                    case 2:
                        if (curr = me->GetMap()->GetCreature(Farmers.front()))
                            curr->SetStandState(UNIT_STAND_STATE_KNEEL);
                        timer = 2000;
                        step++;
                        break;
                    case 3:
                        if (GameObject* pBaril = me->FindNearestGameObject(GO_TAINTED_KEG, 10.000000))
                        {
                            float fX, fY, fZ;
                            pBaril->GetPosition(fX, fY, fZ);
                            me->SummonGameObject(GO_TAINTED_KEG_SMOKE, fX, fY, fZ + 1, 0, 0, 0, 0, 0, 120);
                        }
                        if (curr = me->GetMap()->GetCreature(Farmers.front()))
                            curr->SetStandState(UNIT_STAND_STATE_STAND);
                        curr = nullptr;
                        while (!Farmers.empty())
                        {
                            if (curr = me->GetMap()->GetCreature(Farmers.front()))
                                curr->DealDamage(curr, curr->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                            Farmers.pop_front();
                            curr = nullptr;
                        }

                        timer = 20000;
                        step++;
                        break;
                    case 4:
                        timer = 0;
                        step = 0;
                        break;
                }
            }
            else
                timer -= uiDiff;
        }
    }

    void StartEvent()
    {
        if (step)
            return;
        step = 1;
        timer = 2000;
        if (GameObject* pKeg = me->FindNearestGameObject(GO_TAINTED_KEG, 10.0f))
        {
            pKeg->SetRespawnTime(120);
            pKeg->Refresh();
        }
    }
};

GameObjectAI* GetAIgo_dusty_rug(GameObject *pGo)
{
    return new go_dusty_rugAI(pGo);
}

bool QuestRewarded_go_dusty_rug(Player* pPlayer, GameObject* pGo, Quest const* pQuest)
{
    if (go_dusty_rugAI* pRugAI = dynamic_cast<go_dusty_rugAI*>(pGo->AI()))
        pRugAI->StartEvent();
    return true;
}

void AddSC_hillsbrad_foothills()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "go_helcular_s_grave";
    newscript->GOGetAI = &GetAIgo_helcular_s_grave;
    newscript->pQuestRewardedGO = &QuestRewarded_go_helcular_s_grave;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_dusty_rug";
    newscript->GOGetAI = &GetAIgo_dusty_rug;
    newscript->pQuestRewardedGO = &QuestRewarded_go_dusty_rug;
    newscript->RegisterSelf();
}
