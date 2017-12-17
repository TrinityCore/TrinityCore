/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"

/*######
## npc_calvin_montague
######*/

enum Calvin
{
    SAY_COMPLETE = 0,
    SPELL_DRINK  = 7737, // Possibly incorrect spell, but both duration and icon are correct
    QUEST_590    = 590,

    EVENT_EMOTE_RUDE          = 1,
    EVENT_TALK                = 2,
    EVENT_DRINK               = 3,
    EVENT_SET_QUESTGIVER_FLAG = 4,
    EVENT_STAND               = 5
};

class npc_calvin_montague : public CreatureScript
{
public:
    npc_calvin_montague() : CreatureScript("npc_calvin_montague") { }

    struct npc_calvin_montagueAI : public ScriptedAI
    {
        npc_calvin_montagueAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->RestoreFaction();
            if (!me->IsImmuneToPC())
                me->SetImmuneToPC(true);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (damage > me->GetHealth() || me->HealthBelowPctDamaged(15, damage))
            {
                damage = 0;
                me->CombatStop(true);
                EnterEvadeMode();
                _events.ScheduleEvent(EVENT_EMOTE_RUDE, Seconds(3));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EMOTE_RUDE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                        _events.ScheduleEvent(EVENT_TALK, Seconds(2));
                        break;
                    case EVENT_TALK:
                        Talk(SAY_COMPLETE);
                        _events.ScheduleEvent(EVENT_DRINK, Seconds(5));
                        break;
                    case EVENT_DRINK:
                        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                            player->AreaExploredOrEventHappens(QUEST_590);
                        _playerGUID.Clear();
                        DoCastSelf(SPELL_DRINK);
                        _events.ScheduleEvent(EVENT_SET_QUESTGIVER_FLAG, Seconds(12));
                        break;
                    case EVENT_SET_QUESTGIVER_FLAG:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        _events.ScheduleEvent(EVENT_STAND, Seconds(3));
                        break;
                    case EVENT_STAND:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_590)
            {
                _playerGUID = player->GetGUID();
                me->SetFaction(FACTION_ENEMY);
                me->SetImmuneToPC(false);
                AttackStart(player);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            }
        }

    private:
        EventMap _events;
        ObjectGuid _playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_calvin_montagueAI(creature);
    }
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

        struct go_mausoleum_doorAI : public GameObjectAI
        {
            go_mausoleum_doorAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player) override
            {
                if (player->GetQuestStatus(QUEST_ULAG) != QUEST_STATUS_INCOMPLETE)
                    return false;

                if (!player->FindNearestCreature(NPC_ULAG, 50.0f))
                {
                    if (GameObject* pTrigger = player->FindNearestGameObject(GO_TRIGGER, 30.0f))
                    {
                        pTrigger->SetGoState(GO_STATE_READY);
                        player->SummonCreature(NPC_ULAG, 2390.26f, 336.47f, 40.01f, 2.26f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 300000);
                        return false;
                    }
                }
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_mausoleum_doorAI(go);
        }
};

class go_mausoleum_trigger : public GameObjectScript
{
    public:
        go_mausoleum_trigger() : GameObjectScript("go_mausoleum_trigger") { }

        struct go_mausoleum_triggerAI : public GameObjectAI
        {
            go_mausoleum_triggerAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player) override
            {
                if (player->GetQuestStatus(QUEST_ULAG) != QUEST_STATUS_INCOMPLETE)
                    return false;

                if (GameObject* pDoor = player->FindNearestGameObject(GO_DOOR, 30.0f))
                {
                    me->SetGoState(GO_STATE_ACTIVE);
                    pDoor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    return true;
                }
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_mausoleum_triggerAI(go);
        }
};

void AddSC_tirisfal_glades()
{
    new npc_calvin_montague();
    new go_mausoleum_door();
    new go_mausoleum_trigger();
}
