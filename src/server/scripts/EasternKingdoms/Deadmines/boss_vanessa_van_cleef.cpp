/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "deadmines.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    // Vanessa VanCleef
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_SUMMON_DEFIAS_SUPPORT       = 2,

    // Vanessa VanCleef Intro
    SAY_ANNOUNCE_NOISE_FROM_ABOVE   = 0,
    SAY_INTRO_1                     = 1,
    SAY_INTRO_2                     = 2,
    SAY_INTRO_3                     = 3,
    SAY_INTRO_4                     = 4,
    SAY_INTRO_5                     = 5,
    SAY_ANNOUNCE_NIGHTMARE_ELIXIR   = 6,

    // A Note from Vanessa VanCleef
    SAY_ANNOUNCE_NOTE_ON_THE_GROUND = 0,
};

enum Spells
{
    // Vanessa VanCleef
    SPELL_DEFLECTION                = 92614,
    SPELL_DEADLY_BLADES             = 92622,
    SPELL_BACK_SLASH                = 92619,

    // Vanessa VanCleef Nightmare
    SPELL_SITTING                   = 89279,
    SPELL_NOXIOUS_CONCOCTION        = 92100,
    SPELL_NIGHTMARE_ELIXIR          = 92113,
    SPELL_VANESSAS_BLACKOUT_AURA    = 92120,

};

enum Events
{
    // Vanessa VanCleef
    EVENT_DEFLECTION = 1,
    EVENT_DEADLY_BLADES,

    // Vanessa VanCleef Intro
    EVENT_ANNOUNCE_NOISE_FROM_ABOVE,
    EVENT_TALK_INTRO_1,
    EVENT_JUMP_ON_DECK,
    EVENT_MOVE_TO_INTRO_POS,
    EVENT_TALK_INTRO_2,
    EVENT_TALK_INTRO_3,
    EVENT_FACE_TO_PLAYERS,
    EVENT_TALK_INTRO_4,
    EVENT_NOXIOUS_CONCOCTION,
    EVENT_TALK_INTRO_5,
    EVENT_NIGHTMARE_ELIXIR,
    EVENT_ANNOUNCE_NIGHTMARE_ELIXIR,
    EVENT_LAUGH,
    EVENT_SETUP_NIGHTMARE,
    EVENT_MAGMA_TRAP,

    // A Note from Vanessa VanCleef
    EVENT_TALK_NOTE_FALLS_TO_THE_GROUND,
};

Position const vanessaIntroJumpPos = { -64.5677f,  -820.161f,  41.123f   };
Position const vanessaIntroWalkPos = { -65.30209f, -838.0382f, 41.11562f };

class boss_vanessa_van_cleef : public CreatureScript
{
    public:
        boss_vanessa_van_cleef() : CreatureScript("boss_vanessa_van_cleef") { }

        struct boss_vanessa_van_cleefAI : public BossAI
        {
            boss_vanessa_van_cleefAI(Creature* creature) : BossAI(creature, DATA_VANESSA_VAN_CLEEF) { }

            void Reset() override
            {
                _Reset();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_DEFLECTION, Seconds(11));
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, FAIL);
                _DespawnAtEvade();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEFLECTION:
                            if (me->HealthAbovePct(25))
                                DoCastSelf(SPELL_DEFLECTION);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetDeadminesAI<boss_vanessa_van_cleefAI>(creature);
        }
};

class npc_vanessa_vanessa_van_cleef : public CreatureScript
{
    public:
        npc_vanessa_vanessa_van_cleef() : CreatureScript("npc_vanessa_vanessa_van_cleef") { }

        struct npc_vanessa_vanessa_van_cleefAI : public ScriptedAI
        {
            npc_vanessa_vanessa_van_cleefAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                _instance->SetBossState(DATA_VANESSA_VAN_CLEEF, IN_PROGRESS);
                _events.ScheduleEvent(EVENT_ANNOUNCE_NOISE_FROM_ABOVE, Seconds(2) + Milliseconds(500));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ANNOUNCE_NOISE_FROM_ABOVE:
                            Talk(SAY_ANNOUNCE_NOISE_FROM_ABOVE);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_1, Seconds(3) + Milliseconds(500));
                            break;
                        case EVENT_TALK_INTRO_1:
                            Talk(SAY_INTRO_1);
                            _events.ScheduleEvent(EVENT_JUMP_ON_DECK, Seconds(2));
                            break;
                        case EVENT_JUMP_ON_DECK:
                            me->RemoveAurasDueToSpell(SPELL_SITTING);
                            me->GetMotionMaster()->MoveJump(vanessaIntroJumpPos, 10.0f, 16.31084f);
                            _events.ScheduleEvent(EVENT_MOVE_TO_INTRO_POS, Seconds(8) + Milliseconds(400));
                            break;
                        case EVENT_MOVE_TO_INTRO_POS:
                        {
                            Movement::MoveSplineInit init(me);
                            init.SetWalk(true);
                            init.MoveTo(vanessaIntroWalkPos.GetPositionX(), vanessaIntroWalkPos.GetPositionY(), vanessaIntroWalkPos.GetPositionZ(), true);
                            init.Launch();
                            _events.ScheduleEvent(EVENT_TALK_INTRO_2, Milliseconds(200));
                            break;
                        }
                        case EVENT_TALK_INTRO_2:
                            Talk(SAY_INTRO_2);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_3, Seconds(9) + Milliseconds(700));
                            break;
                        case EVENT_TALK_INTRO_3:
                            Talk(SAY_INTRO_3);
                            _events.ScheduleEvent(EVENT_FACE_TO_PLAYERS, Seconds(7) + Milliseconds(900));
                            break;
                        case EVENT_FACE_TO_PLAYERS:
                            me->SetFacingTo(1.53589f);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_4, Milliseconds(200));
                            break;
                        case EVENT_TALK_INTRO_4:
                            Talk(SAY_INTRO_4);
                            _events.ScheduleEvent(EVENT_NOXIOUS_CONCOCTION, Seconds(2) + Milliseconds(200));
                            break;
                        case EVENT_NOXIOUS_CONCOCTION:
                            DoCastAOE(SPELL_NOXIOUS_CONCOCTION);
                            _events.ScheduleEvent(EVENT_TALK_INTRO_5, Seconds(2) + Milliseconds(600));
                            break;
                        case EVENT_TALK_INTRO_5:
                            Talk(SAY_INTRO_5);
                            _events.ScheduleEvent(EVENT_NIGHTMARE_ELIXIR, Seconds(4) + Milliseconds(600));
                            break;
                        case EVENT_NIGHTMARE_ELIXIR:
                            DoCastAOE(SPELL_NIGHTMARE_ELIXIR);
                            DoCastAOE(SPELL_VANESSAS_BLACKOUT_AURA, true);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_NIGHTMARE_ELIXIR, Milliseconds(200));
                            break;
                        case EVENT_ANNOUNCE_NIGHTMARE_ELIXIR:
                            Talk(SAY_ANNOUNCE_NIGHTMARE_ELIXIR);
                            _events.ScheduleEvent(EVENT_LAUGH, Seconds(2) + Milliseconds(100));
                            break;
                        case EVENT_LAUGH:
                            me->HandleEmoteCommand(EMOTE_STATE_LAUGH);
                            _events.ScheduleEvent(EVENT_SETUP_NIGHTMARE, Milliseconds(700));
                            me->DespawnOrUnsummon(Seconds(5));
                            break;
                        case EVENT_SETUP_NIGHTMARE:
                            _instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STATE_PREPARE_TRAP);
                            _events.ScheduleEvent(EVENT_MAGMA_TRAP, Milliseconds(800));
                            break;
                        case EVENT_MAGMA_TRAP:
                            _instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, NIGHTMARE_STAGE_MAGMA_TRAP);
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
            return GetDeadminesAI<npc_vanessa_vanessa_van_cleefAI>(creature);
        }
};

class npc_vanessa_note_from_vanessa : public CreatureScript
{
    public:
        npc_vanessa_note_from_vanessa() : CreatureScript("npc_vanessa_note_from_vanessa") { }

        struct npc_vanessa_note_from_vanessaAI : public ScriptedAI
        {
            npc_vanessa_note_from_vanessaAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_TALK_NOTE_FALLS_TO_THE_GROUND, Seconds(5));
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                if (_instance->GetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER) != IN_PROGRESS)
                {
                    _instance->SetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER, IN_PROGRESS);
                    me->DespawnOrUnsummon(Seconds(7));
                }
                return false;
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_NOTE_FALLS_TO_THE_GROUND:
                            Talk(SAY_ANNOUNCE_NOTE_ON_THE_GROUND);
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
            return GetDeadminesAI<npc_vanessa_note_from_vanessaAI>(creature);
        }
};

void AddSC_boss_vanessa_van_cleef()
{
    new boss_vanessa_van_cleef();
    new npc_vanessa_vanessa_van_cleef();
    new npc_vanessa_note_from_vanessa();
}
