/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "violet_hold_broken_isles.h"

enum CreatureText
{
    SAY_INTRO = 0,
    SAY_BYE = 1,
};

enum Events
{
    EVENT_INTRO = 1,
    EVENT_MOVE_DOOR = 2,
    EVENT_TALK_OUTRO = 3,
    EVENT_DESPAWN = 4,
    EVENT_SUMMONS = 5
};

enum Actions
{
    ACTION_GO_DOOR = 1,
};

enum MovementPoints
{
    PATH_TO_DOOR = 102278
};

enum Menus
{
    OPTION_START_INTRO_EVENT_MID = 19230,
    OPTION_START_INTRO_EVENT_OID = 0
};

enum GameObjectId
{
    GO_PRISON_SEAL = 247002
};

enum CreatureId
{
    NPC_SUMMON_PORTAL = 102267,
    NPC_FELSTALKER_RAVENER = 102269,
    NPC_EREDAR_INVADER = 102270,
    NPC_FELGUARD_DESTROYER = 102272,
    NPC_DOOMGUARD_INFILTRATOR = 102273
};

Position const TempSummonPositions[3] =
{   //     X         Y           Z         O
    { 4623.08f, 4059.6f, 82.7241f, 4.7822f }, // 1 Portal Left
    { 4685.84f, 4013.8f, 91.8186f, 3.12414f }, // 2 Portal Middle
    { 4638.16f, 3962.08f, 87.0574f, 1.71042f }, // 3 Portal Right
};


class npc_summon_portal : public CreatureScript
{
public:
    npc_summon_portal() : CreatureScript("npc_summon_portal") { }

    struct npc_summon_portalAI : public ScriptedAI
    {
        npc_summon_portalAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

        void Reset() override
        {
            _events.Reset();
            Summons.DespawnAll();
        }

        void JustAppeared() override
        {
            _events.ScheduleEvent(EVENT_SUMMONS, 20s);
        }

        void JustSummoned(Creature* summon) override
        {
            Summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_FELSTALKER_RAVENER:
            case NPC_EREDAR_INVADER:
            case NPC_FELGUARD_DESTROYER:
            case NPC_DOOMGUARD_INFILTRATOR:
                summon->RemoveAura(29266);
                summon->GetMotionMaster()->MovePath(PATH_TO_DOOR, false);
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Summons.DespawnAll();
            _events.ScheduleEvent(EVENT_SUMMONS, 20s);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUMMONS:
                    me->SummonCreature(NPC_EREDAR_INVADER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s);
                    me->SummonCreature(NPC_FELGUARD_DESTROYER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s);
                    me->SummonCreature(NPC_FELSTALKER_RAVENER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s);
                    me->SummonCreature(NPC_FELSTALKER_RAVENER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s);
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap _events;
        SummonList Summons;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVioletHolBrokenIslesAI<npc_summon_portalAI>(creature);
    }
};


class npc_lieutenantSinclari : public CreatureScript
{
public:
    npc_lieutenantSinclari() : CreatureScript("npc_lieutenantSinclari") { }

    struct npc_lieutenantSinclariAI : public ScriptedAI
    {
        npc_lieutenantSinclariAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == OPTION_START_INTRO_EVENT_MID && gossipListId == OPTION_START_INTRO_EVENT_OID)
            {
                CloseGossipMenuFor(player);
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_INTRO, player);
                _events.ScheduleEvent(EVENT_INTRO, 2s);
            }
            return false;
        }

        void Reset() override
        {
            _events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INTRO:
                    DoAction(ACTION_GO_DOOR);
                    _events.ScheduleEvent(EVENT_MOVE_DOOR, 2s);
                    break;
                case EVENT_MOVE_DOOR:
                    me->PauseMovement();
                    me->GetMotionMaster()->Clear();
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 1.14286f);
                    me->GetMotionMaster()->MovePath(PATH_TO_DOOR, false);
                    _events.ScheduleEvent(EVENT_TALK_OUTRO, 6s);
                    break;
                case EVENT_TALK_OUTRO:
                    me->SetFacingTo(6.195918560028076171f, true);
                    Talk(SAY_BYE);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
                    _events.ScheduleEvent(EVENT_DESPAWN, 8s);
                    break;
                case EVENT_DESPAWN:
                    //if (GameObject* table = ObjectAccessor::GetGameObject(*me, _instance->GetGuidData(GO_PRISON_SEAL)))
                    //    me->FindNearestGameObject(GO_PRISON_SEAL, 5, true);
                    //_instance->HandleGameObject(GetGUID(GO_PRISON_SEAL), false);
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
                }
            }
        }
    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVioletHolBrokenIslesAI<npc_lieutenantSinclariAI>(creature);
    }
};

void AddSC_viole_thold_broken_isles()
{
    new npc_lieutenantSinclari();
    new npc_summon_portal();
}
