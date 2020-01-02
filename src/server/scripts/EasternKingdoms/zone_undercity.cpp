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

/* ScriptData
SDName: Undercity
SD%Complete: 95
SDComment: Quest support: 6628, 9180(post-event).
SDCategory: Undercity
EndScriptData */

/* ContentData
npc_lady_sylvanas_windrunner
npc_highborne_lamenter
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

/*######
## npc_lady_sylvanas_windrunner
######*/

enum Sylvanas
{
    QUEST_JOURNEY_TO_UNDERCITY      = 9180,

    EMOTE_LAMENT_END                = 0,
    SAY_LAMENT_END                  = 1,
    EMOTE_LAMENT                    = 2,

    // Ambassador Sunsorrow
    SAY_SUNSORROW_WHISPER           = 0,

    SOUND_CREDIT                    = 10896,

    NPC_HIGHBORNE_LAMENTER          = 21628,
    NPC_HIGHBORNE_BUNNY             = 21641,
    NPC_AMBASSADOR_SUNSORROW        = 16287,

    SPELL_HIGHBORNE_AURA            = 37090,
    SPELL_SYLVANAS_CAST             = 36568,
    //SPELL_RIBBON_OF_SOULS         = 34432, the real one to use might be 37099
    SPELL_RIBBON_OF_SOULS           = 37099,

    // Combat spells
    SPELL_BLACK_ARROW               = 59712,
    SPELL_FADE                      = 20672,
    SPELL_FADE_BLINK                = 29211,
    SPELL_MULTI_SHOT                = 59713,
    SPELL_SHOT                      = 59710,
    SPELL_SUMMON_SKELETON           = 59711,

    // Events
    EVENT_FADE                      = 1,
    EVENT_SUMMON_SKELETON           = 2,
    EVENT_BLACK_ARROW               = 3,
    EVENT_SHOOT                     = 4,
    EVENT_MULTI_SHOT                = 5,
    EVENT_LAMENT_OF_THE_HIGHBORN    = 6,
    EVENT_SUNSORROW_WHISPER         = 7,

    GUID_EVENT_INVOKER              = 1,
};

float HighborneLoc[4][3]=
{
    {1285.41f, 312.47f, 0.51f},
    {1286.96f, 310.40f, 1.00f},
    {1289.66f, 309.66f, 1.52f},
    {1292.51f, 310.50f, 1.99f},
};

#define HIGHBORNE_LOC_Y             -61.00f
#define HIGHBORNE_LOC_Y_NEW         -55.50f

class npc_lady_sylvanas_windrunner : public CreatureScript
{
public:
    npc_lady_sylvanas_windrunner() : CreatureScript("npc_lady_sylvanas_windrunner") { }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 /*slot*/) override
    {
        if (_Quest->GetQuestId() == QUEST_JOURNEY_TO_UNDERCITY)
            creature->AI()->SetGUID(player->GetGUID(), GUID_EVENT_INVOKER);

        return true;
    }

    struct npc_lady_sylvanas_windrunnerAI : public ScriptedAI
    {
        npc_lady_sylvanas_windrunnerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            LamentEvent = false;
            targetGUID.Clear();
            playerGUID.Clear();
        }

        void Reset() override
        {
            Initialize();
            _events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_FADE, 30000);
            _events.ScheduleEvent(EVENT_SUMMON_SKELETON, 20000);
            _events.ScheduleEvent(EVENT_BLACK_ARROW, 15000);
            _events.ScheduleEvent(EVENT_SHOOT, 8000);
            _events.ScheduleEvent(EVENT_MULTI_SHOT, 10000);
        }

        void SetGUID(ObjectGuid guid, int32 type) override
        {
            if (type == GUID_EVENT_INVOKER)
            {
                Talk(EMOTE_LAMENT);
                DoPlaySoundToSet(me, SOUND_CREDIT);
                DoCast(me, SPELL_SYLVANAS_CAST, false);
                playerGUID = guid;
                LamentEvent = true;

                for (uint8 i = 0; i < 4; ++i)
                    me->SummonCreature(NPC_HIGHBORNE_LAMENTER, HighborneLoc[i][0], HighborneLoc[i][1], HIGHBORNE_LOC_Y, HighborneLoc[i][2], TEMPSUMMON_TIMED_DESPAWN, 160000);

                _events.ScheduleEvent(EVENT_LAMENT_OF_THE_HIGHBORN, 2000);
                _events.ScheduleEvent(EVENT_SUNSORROW_WHISPER, 10000);
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_HIGHBORNE_BUNNY)
            {
                if (Creature* target = ObjectAccessor::GetCreature(*summoned, targetGUID))
                {
                    target->GetMotionMaster()->MoveJump(target->GetPositionX(), target->GetPositionY(), me->GetPositionZ() + 15.0f, me->GetOrientation(), 0);
                    target->SetPosition(target->GetPositionX(), target->GetPositionY(), me->GetPositionZ()+15.0f, 0.0f);
                    summoned->CastSpell(target, SPELL_RIBBON_OF_SOULS, false);
                }

                summoned->SetDisableGravity(true);
                targetGUID = summoned->GetGUID();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !LamentEvent)
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FADE:
                        DoCast(me, SPELL_FADE);
                        // add a blink to simulate a stealthed movement and reappearing elsewhere
                        DoCast(me, SPELL_FADE_BLINK);
                        // if the victim is out of melee range she cast multi shot
                        if (Unit* victim = me->GetVictim())
                            if (me->GetDistance(victim) > 10.0f)
                                DoCast(victim, SPELL_MULTI_SHOT);
                        _events.ScheduleEvent(EVENT_FADE, urand(30000, 35000));
                        break;
                    case EVENT_SUMMON_SKELETON:
                        DoCast(me, SPELL_SUMMON_SKELETON);
                        _events.ScheduleEvent(EVENT_SUMMON_SKELETON, urand(20000, 30000));
                        break;
                    case EVENT_BLACK_ARROW:
                        if (Unit* victim = me->GetVictim())
                            DoCast(victim, SPELL_BLACK_ARROW);
                        _events.ScheduleEvent(EVENT_BLACK_ARROW, urand(15000, 20000));
                        break;
                    case EVENT_SHOOT:
                        if (Unit* victim = me->GetVictim())
                            DoCast(victim, SPELL_SHOT);
                        _events.ScheduleEvent(EVENT_SHOOT, urand(8000, 10000));
                        break;
                    case EVENT_MULTI_SHOT:
                        if (Unit* victim = me->GetVictim())
                            DoCast(victim, SPELL_MULTI_SHOT);
                        _events.ScheduleEvent(EVENT_MULTI_SHOT, urand(10000, 13000));
                        break;
                    case EVENT_LAMENT_OF_THE_HIGHBORN:
                        if (!me->HasAura(SPELL_SYLVANAS_CAST))
                        {
                            Talk(SAY_LAMENT_END);
                            Talk(EMOTE_LAMENT_END);
                            LamentEvent = false;
                            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                            Reset();
                        }
                        else
                        {
                            DoSummon(NPC_HIGHBORNE_BUNNY, me, 10.0f, 3000, TEMPSUMMON_TIMED_DESPAWN);
                            _events.ScheduleEvent(EVENT_LAMENT_OF_THE_HIGHBORN, 2000);
                        }
                        break;
                    case EVENT_SUNSORROW_WHISPER:
                        if (Creature* ambassador = me->FindNearestCreature(NPC_AMBASSADOR_SUNSORROW, 20.0f))
                            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                                ambassador->AI()->Talk(SAY_SUNSORROW_WHISPER, player);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        bool LamentEvent;
        ObjectGuid targetGUID;
        ObjectGuid playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lady_sylvanas_windrunnerAI(creature);
    }
};

/*######
## npc_highborne_lamenter
######*/

class npc_highborne_lamenter : public CreatureScript
{
public:
    npc_highborne_lamenter() : CreatureScript("npc_highborne_lamenter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_highborne_lamenterAI(creature);
    }

    struct npc_highborne_lamenterAI : public ScriptedAI
    {
        npc_highborne_lamenterAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            EventMoveTimer = 10000;
            EventCastTimer = 17500;
            EventMove = true;
            EventCast = true;
        }

        uint32 EventMoveTimer;
        uint32 EventCastTimer;
        bool EventMove;
        bool EventCast;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (EventMove)
            {
                if (EventMoveTimer <= diff)
                {
                    me->SetDisableGravity(true);
                    me->MonsterMoveWithSpeed(me->GetPositionX(), me->GetPositionY(), HIGHBORNE_LOC_Y_NEW, me->GetDistance(me->GetPositionX(), me->GetPositionY(), HIGHBORNE_LOC_Y_NEW) / (5000 * 0.001f));
                    me->SetPosition(me->GetPositionX(), me->GetPositionY(), HIGHBORNE_LOC_Y_NEW, me->GetOrientation());
                    EventMove = false;
                } else EventMoveTimer -= diff;
            }
            if (EventCast)
            {
                if (EventCastTimer <= diff)
                {
                    DoCast(me, SPELL_HIGHBORNE_AURA);
                    EventCast = false;
                } else EventCastTimer -= diff;
            }
        }
    };
};

/*######
## AddSC
######*/

void AddSC_undercity()
{
    new npc_lady_sylvanas_windrunner();
    new npc_highborne_lamenter();
}
