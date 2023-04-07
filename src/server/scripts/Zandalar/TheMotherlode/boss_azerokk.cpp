/*
 * Copyright 2023 AzgathCore
  * Copyright (C) 2022 BfaCore Reforged
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
#include "the_motherlode.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells
{
    SPELL_RAGING_GAZE_BEAM = 257582,
    SPELL_RAGING_GAZE_SELECTOR = 271526,
    SPELL_AZERITE_INFUSION1 = 257597,
    SPELL_AZERITE_INFUSION2 = 271698,

    SPELL_CALL_EARTHRAGER = 257593,
    SPELL_AZERITE_INFUSION_MISSILE = 271698,
    SPELL_JAGGED_CUT = 257543,
    SPELL_RESONANT_QUAKE = 258627,

    SPELL_FRACKING_TOTEM_BUTTON = 257455,
    SPELL_FRACKING_TOTEM_CAST   = 257480,
    SPELL_FRACKING_TOTEM_STUN   = 257481,
    SPELL_FRACKING_TOTEM_SUMMON = 268204,
    SPELL_RESONANT_PULSE        = 258622,
    SPELL_TECTONIC_SMASH        = 275907,
};

enum Events
{
    EVENT_TOTEM_TARGET,
    EVENT_FIXATE = 1,
    EVENT_JAGGED_CUT,
    EVENT_RESONANT_QUAKE,
    EVENT_AZERITE_INFUSION = 1,
    EVENT_CALL_EARTHRAGER = 2,
    EVENT_RESONANT_PULSE = 3,
    EVENT_TECTONIC_SMASH = 4,
};
enum Yells
{
    YELL_AZERITE_INFUSION = 0,
    YELL_CALL_EARTHRAGER = 1,
    YELL_RESONANT_PULSE = 2,
    YELL_TECTONIC_SMASH = 3,
    YELL_KILLED = 4,
    YELL_KILL = 5,
    YELL_ENTER_COMBAT = 6,
};

enum Timers
{};
enum AnimKit
{
    TIMER_AZERITE_INFUSION = 28 * IN_MILLISECONDS,
    TIMER_CALL_EARTHRAGER = 15 * IN_MILLISECONDS,
    TIMER_RESONANT_PULSE = 20 * IN_MILLISECONDS,
    TIMER_TECTONIC_SMASH = 40 * IN_MILLISECONDS,

    TIMER_TOTEM_TARGET = 2 * IN_MILLISECONDS,
};
//enum Creatures
//
//struct boss_azerokk : public BossAI
//{
//    BOSS_AZEROKK = 129227,
//    NPC_EARTHRAGERS = 129802,
//    NPC_FRACKING_TOTEM = 136500,
//    NPC_FRACKING_TOTEM_PRE = 129804,
//};
//public:
//    boss_azerokk(Creature* creature) : BossAI(creature, DATA_AZEROKK)
//    {
//        Initialize();
//    }
//
//const Position centerPos = { 1215.50f, -3325.10f, 57.33f }; // 40y
//
//enum SoundId
//    void Initialize()
//    {
//    SOUND_AZERITE_INFUSION = 97390,
//    SOUND_CALL_EARTHRAGER = 97384,
//    SOUND_RESONANT_PULSE = 97381,
//    SOUND_TECTONIC_SMASH = 115344,
//    SOUND_KILL = 97380,
//    SOUND_DEATH = 97379,
//    SOUND_AGGRO = 97385,
//};
//        events.ScheduleEvent(EVENT_AZERITE_INFUSION, 6000);
//        events.ScheduleEvent(EVENT_CALL_EARTHRAGER, 3000);
//        events.ScheduleEvent(EVENT_RESONANT_PULSE, 3000);
//        if (IsHeroic() || IsMythic())
//            events.ScheduleEvent(EVENT_TECTONIC_SMASH, 5000);
//    }
//
//const Position earthragerPos[4] =
//    void Reset() override
//    {
//    { 1235.39f, -3324.67f, 56.98f },
//    { 1213.96f, -3346.69f, 55.51f },
//    { 1213.57f, -3304.01f, 55.71f },
//    { 1194.62f, -3321.71f, 55.17f },
//};
//        BossAI::Reset();
//        events.Reset();
//        Initialize();
//        instance->SetBossState(DATA_AZEROKK, FAIL);
//    }
//
//    void EnterCombat(Unit* who)
//    {
//        BossAI::EnterCombat(who);
//        Talk(YELL_ENTER_COMBAT);
//        instance->SetBossState(DATA_AZEROKK, IN_PROGRESS);
//    }
//
//    void JustDied(Unit* killer) override
//    {
//        BossAI::JustDied(killer);
//        Talk(YELL_KILLED);
//        instance->SetBossState(DATA_AZEROKK, DONE);
//    }
//
//    void KilledUnit(Unit* victim) override
//    {
//        if (victim->GetTypeId() == TYPEID_PLAYER)
//            Talk(YELL_KILL);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//const Position frackingPos[2] =
//        while (uint32 eventID = events.ExecuteEvent())
//        {
//            switch (eventID)
//            {
//    { 1183.08f, -3304.60f, 56.83f },
//    { 1185.00f, -3301.67f, 56.67f },
//
//            case EVENT_AZERITE_INFUSION:
//                Talk(YELL_AZERITE_INFUSION);
//                events.DelayEvents(1000);
//                DoCastVictim(SPELL_AZERITE_INFUSION1);
//                DoCastVictim(SPELL_AZERITE_INFUSION2);
//                events.ScheduleEvent(EVENT_AZERITE_INFUSION, 30000);
//                break;
//            case EVENT_CALL_EARTHRAGER:
//				Talk(YELL_CALL_EARTHRAGER);
//                DoCastVictim(SPELL_CALL_EARTHRAGER);
//                events.ScheduleEvent(EVENT_CALL_EARTHRAGER, 10000);
//                break;
//            case EVENT_RESONANT_PULSE:
//                Talk(YELL_TECTONIC_SMASH);
//                DoCastVictim(SPELL_RESONANT_PULSE);
//                events.ScheduleEvent(EVENT_RESONANT_PULSE, 15800);
//                break;
//            case EVENT_TECTONIC_SMASH:
//                Talk(YELL_TECTONIC_SMASH);
//                DoCastVictim(SPELL_TECTONIC_SMASH, me);
//                events.ScheduleEvent(EVENT_TECTONIC_SMASH, 47400);
//                break;
//            default:
//                break;
//            }
//        }
//
//        DoMeleeAttackIfReady();
//    }
//};
//
//#define AZERITE_INFUSION "You are not prepared!!!!"
//#define CALL_EARTHRAGER "Burn..."
//#define RESONANT_PULSE "Figth with me."
//#define TECTONIC_SMASH "Arg"
//#define KILL_TEXT "I will kill you"
//#define DEATH_TEXT "Oh nooo..."
//#define AGGRO_TEXT "Come here..."
//
//void AddSC_boss_azerokk()
//{
//   
//    RegisterCreatureAI(boss_azerokk);
//}
