/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Tirisfal_Glades
SD%Complete: 100
SDComment: Quest support: 590, 1819
SDCategory: Tirisfal Glades
EndScriptData */

/* ContentData
npc_calvin_montague
go_mausoleum_door
go_mausoleum_trigger
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

/*######
## npc_calvin_montague
######*/

enum Calvin
{
    SAY_COMPLETE        = 0,
    SPELL_DRINK         = 2639,                             // possibly not correct spell (but iconId is correct)
    QUEST_590           = 590,
    FACTION_HOSTILE     = 168
};

class npc_calvin_montague : public CreatureScript
{
public:
    npc_calvin_montague() : CreatureScript("npc_calvin_montague") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_590)
        {
            creature->setFaction(FACTION_HOSTILE);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            ENSURE_AI(npc_calvin_montague::npc_calvin_montagueAI, creature->AI())->AttackStart(player);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_calvin_montagueAI(creature);
    }

    struct npc_calvin_montagueAI : public ScriptedAI
    {
        npc_calvin_montagueAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_uiPhase = 0;
            m_uiPhaseTimer = 5000;
            m_uiPlayerGUID.Clear();
        }

        uint32 m_uiPhase;
        uint32 m_uiPhaseTimer;
        ObjectGuid m_uiPlayerGUID;

        void Reset() override
        {
            Initialize();

            me->RestoreFaction();

            if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC))
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void AttackedBy(Unit* pAttacker) override
        {
            if (me->GetVictim() || me->IsFriendlyTo(pAttacker))
                return;

            AttackStart(pAttacker);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
        {
            if (uiDamage > me->GetHealth() || me->HealthBelowPctDamaged(15, uiDamage))
            {
                uiDamage = 0;

                me->RestoreFaction();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->CombatStop(true);

                m_uiPhase = 1;

                if (pDoneBy->GetTypeId() == TYPEID_PLAYER)
                    m_uiPlayerGUID = pDoneBy->GetGUID();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (m_uiPhase)
            {
                if (m_uiPhaseTimer <= diff)
                    m_uiPhaseTimer = 7500;
                else
                {
                    m_uiPhaseTimer -= diff;
                    return;
                }

                switch (m_uiPhase)
                {
                    case 1:
                        Talk(SAY_COMPLETE);
                        ++m_uiPhase;
                        break;
                    case 2:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_uiPlayerGUID))
                            player->AreaExploredOrEventHappens(QUEST_590);

                        DoCast(me, SPELL_DRINK, true);
                        ++m_uiPhase;
                        break;
                    case 3:
                        EnterEvadeMode();
                        break;
                }

                return;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## go_mausoleum_door
## go_mausoleum_trigger
######*/

enum Mausoleum
{
    QUEST_ULAG      = 1819,
    NPC_ULAG        = 6390,
    GO_TRIGGER      = 104593,
    GO_DOOR         = 176594
};

class go_mausoleum_door : public GameObjectScript
{
public:
    go_mausoleum_door() : GameObjectScript("go_mausoleum_door") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (player->GetQuestStatus(QUEST_ULAG) != QUEST_STATUS_INCOMPLETE)
            return false;

        if (!player->FindNearestCreature(NPC_ULAG, 50.0f))
            if (GameObject* pTrigger = player->FindNearestGameObject(GO_TRIGGER, 30.0f))
            {
                pTrigger->SetGoState(GO_STATE_READY);
                player->SummonCreature(NPC_ULAG, 2390.26f, 336.47f, 40.01f, 2.26f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 300000);
                return false;
            }

        return false;
    }
};

class go_mausoleum_trigger : public GameObjectScript
{
public:
    go_mausoleum_trigger() : GameObjectScript("go_mausoleum_trigger") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(QUEST_ULAG) != QUEST_STATUS_INCOMPLETE)
            return false;

        if (GameObject* pDoor = player->FindNearestGameObject(GO_DOOR, 30.0f))
        {
            go->SetGoState(GO_STATE_ACTIVE);
            pDoor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
            return true;
        }

        return false;
    }
};

void AddSC_tirisfal_glades()
{
    new npc_calvin_montague();
    new go_mausoleum_door();
    new go_mausoleum_trigger();
}
