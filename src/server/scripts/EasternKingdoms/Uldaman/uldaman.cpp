/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Uldaman
SD%Complete: 100
SDComment: Quest support: 2278 + 1 trash mob.
SDCategory: Uldaman
EndScriptData */

/* ContentData
mob_jadespine_basilisk
go_keystone_chamber
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Player.h"
#include "scriptPCH.h"
#include "uldaman.h"

/*######
## go_keystone_chamber
######*/
 ## go_keystone_chamber
 ######*/

bool GOHello_go_keystone_chamber(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if (!pInstance)
        return false;

    if (pPlayer)
        pInstance->SetData64(0, pPlayer->GetGUID()); // Ironaya first victim

    if (pGo)
        pGo->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);

    // save state
    pInstance->SetData(ULDAMAN_ENCOUNTER_IRONAYA_DOOR, DONE);

    return false;
}

// Return true to avoid db script attempt
bool ProcessEventId_event_awaken_stone_keeper(uint32 eventId, Object* source, Object* target, bool isStart)
{
    if (!source || source->GetTypeId() != TYPEID_PLAYER)
        return true;

    if (!target)
        return true;

    if (ScriptedInstance* instance = dynamic_cast<ScriptedInstance*>(((Player*)source)->GetInstanceData()))
        instance->SetData(ULDAMAN_ENCOUNTER_STONE_KEEPERS, IN_PROGRESS);

    return true;
}

struct mob_stone_keeperAI : public ScriptedAI
{
    mob_stone_keeperAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        instance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }
    
    ScriptedInstance* instance;
    
    uint32 m_uiTrample_Timer;

    void Reset() override
    {
        m_uiTrample_Timer = urand(4000, 9000);
    }

    void EnterEvadeMode() override
    {
        if (Unit* target = me->SelectNearestHostileUnitInAggroRange(true))
        {
            AttackStart(target);
            return;
        }
        Reset();
        if (instance)
            instance->SetData(ULDAMAN_ENCOUNTER_STONE_KEEPERS, FAIL);
    }

    void JustDied(Unit* pWho) override
    {
        if (instance)
            instance->SetData(ULDAMAN_ENCOUNTER_STONE_KEEPERS, IN_PROGRESS);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            return;
        }
        if (m_uiTrample_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TRAMPLE) == CAST_OK)
            {
                m_uiTrample_Timer = urand(4000, 10000);
            }
        }
        else m_uiTrample_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_stone_keeper(Creature* pCreature)
{
    return new mob_stone_keeperAI(pCreature);
}


/*######
## mob_jadespine_basilisk
######*/

struct mob_jadespine_basiliskAI : public ScriptedAI
{
    mob_jadespine_basiliskAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Cslumber_Timer;

    void Reset() override
    {
        Cslumber_Timer = 2000;
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            return;
        }

        //Cslumber_Timer
        if (Cslumber_Timer < diff)
        {
            //Cast
            // DoCastSpellIfCan(m_creature->GetVictim(),SPELL_CRYSTALLINE_SLUMBER);
            m_creature->CastSpell(m_creature->GetVictim(), SPELL_CRYSTALLINE_SLUMBER, false);

            //Stop attacking target thast asleep and pick new target
            Cslumber_Timer = 28000;

            Unit* Target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0);

            if (!Target || Target == m_creature->GetVictim())
            {
                Target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            }

            if (Target)
            {
                m_creature->TauntApply(Target);
            }
        }
        else Cslumber_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_jadespine_basilisk(Creature* pCreature)
{
    return new mob_jadespine_basiliskAI(pCreature);
}

struct AnnoraAI : public ScriptedAI
{
    AnnoraAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_creature->SetVisibility(VISIBILITY_OFF);
        m_creature->SetFactionTemplateId(FACTION_STONED);
        m_uiNbScorpion = 0;
        isSpawned = false;
        Reset();
    }

    uint32 m_uiNbScorpion;
    bool isSpawned;

    void Reset() override
    {
    }

    void Aggro(Unit* pWho) override
    {
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!isSpawned)
        {
            std::list<Creature*> m_EscortList;
            m_uiNbScorpion = 0;

            GetCreatureListWithEntryInGrid(m_EscortList, m_creature, 7078, 30.0f);
            for (const auto& it : m_EscortList)
            {
                if (it->IsAlive())
                {
                    m_uiNbScorpion++;
                }
               
            }
            m_EscortList.clear();

            if (m_uiNbScorpion == 0)
            {
                m_creature->SetVisibility(VISIBILITY_ON);
                m_creature->GetMotionMaster()->MovePoint(1, -164.3657f, 210.7687f, -49.572f);
                isSpawned = true;
            }
        }
};
    InstanceScript* instance;
    bool OnGossipHello(Player* /*player*/) override
    {
        instance->SetData(DATA_IRONAYA_SEAL, IN_PROGRESS); //door animation and save state.
        return false;
    };
/*######
## at_map_chamber
######*/

enum MapChamber
{
    QUEST_HIDDEN_CHAMBER = 2240
};

class AreaTrigger_at_map_chamber : public AreaTriggerScript
{
    public:

        AreaTrigger_at_map_chamber()
            : AreaTriggerScript("at_map_chamber")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool /*entered*/) override
        {
            if (player->GetQuestStatus(QUEST_HIDDEN_CHAMBER) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(QUEST_HIDDEN_CHAMBER);

            return true;
        }
};

void AddSC_uldaman()
{
    
    Script* newscript;

    newscript = new Script;
    newscript->Name = "mob_annora";
    newscript->GetAI = &GetAI_annora;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_jadespine_basilisk";
    newscript->GetAI = &GetAI_mob_jadespine_basilisk;
    newscript->RegisterSelf();


    newscript = new Script;
    newscript->Name = "mob_stone_keeper";
    newscript->GetAI = &GetAI_mob_stone_keeper;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_keystone_chamber";
    newscript->pGOHello = &GOHello_go_keystone_chamber;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "event_awaken_stone_keeper";
    newscript->pProcessEventId = &ProcessEventId_event_awaken_stone_keeper;
    newscript->RegisterSelf();
}

void AddSC_uldaman()
{
    new go_keystone_chamber();
}
