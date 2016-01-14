/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "naxxramas.h"

enum Phases
{
    PHASE_NONE,
    PHASE_GROUND,
    PHASE_BALCONY
};

enum Events
{
    EVENT_CURSE = 1,            // curse of the plaguebringer
    EVENT_BLINK,                // blink (25m only)
    EVENT_WARRIOR,              // summon warriors during ground phase
    EVENT_BALCONY,              // become untargetable and begin balcony phase
    EVENT_BALCONY_TELEPORT,     // actually teleport to balcony, this is slightly delayed
    EVENT_WAVE,                 // spawn wave during balcony phase
    EVENT_GROUND,               // end balcony phase and teleport to ground
    EVENT_GROUND_ATTACKABLE     // become attackable and aggressive again at start of ground phase, once again slightly delayed to prevent motionmaster weirdness
};

enum Talk
{
    SAY_AGGRO               = 0,
    SAY_SUMMON              = 1,
    SAY_SLAY                = 2,
    SAY_DEATH               = 3,

    EMOTE_SUMMON            = 4, // ground phase
    EMOTE_SUMMON_WAVE       = 5, // balcony phase
    EMOTE_TELEPORT_1        = 6, // ground to balcony
    EMOTE_TELEPORT_2        = 7  // balcony to ground
};

enum Spells
{
    SPELL_CURSE         = 29213, // 25-man: 54835
    SPELL_CRIPPLE       = 29212, // 25-man: 54814

    SPELL_TELEPORT      = 29216, // ground to balcony
    SPELL_TELEPORT_BACK = 29231  // balcony to ground
};

enum Adds
{
    N_WARRIOR_SPELLS = 3,
    N_CHAMPION_SPELLS = 6,
    N_GUARDIAN_SPELLS = 3
};
const uint32 SummonWarriorSpells[N_WARRIOR_SPELLS] = { 29247, 29248, 29249 };
const uint32 SummonChampionSpells[N_CHAMPION_SPELLS] = { 29238, 29255, 29257, 29258, 29262, 29267 };
const uint32 SummonGuardianSpells[N_GUARDIAN_SPELLS] = { 29239, 29256, 29268 };

#define SPELL_BLINK                 RAND(29208, 29209, 29210, 29211)

class boss_noth : public CreatureScript
{
public:
    boss_noth() : CreatureScript("boss_noth") { }

    struct boss_nothAI : public BossAI
    {
        boss_nothAI(Creature* creature) : BossAI(creature, BOSS_NOTH), balconyCount(0), justBlinked(false)
        {
            std::copy(SummonWarriorSpells, SummonWarriorSpells + N_WARRIOR_SPELLS, _SummonWarriorSpells);
            std::copy(SummonChampionSpells, SummonChampionSpells + N_CHAMPION_SPELLS, _SummonChampionSpells);
            std::copy(SummonGuardianSpells, SummonGuardianSpells + N_GUARDIAN_SPELLS, _SummonGuardianSpells);

            events.SetPhase(PHASE_NONE);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset(); // teleport back first
            _EnterEvadeMode();
        }

        void Reset() override
        {
            if (!me->IsAlive())
                return;

            // in case we reset during balcony phase
            if (events.IsInPhase(PHASE_BALCONY))
            {
                DoCastAOE(SPELL_TELEPORT_BACK);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
            }

            balconyCount = 0;
            events.SetPhase(PHASE_NONE);
            justBlinked = false;

            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            EnterPhaseGround();
        }

        void EnterPhaseGround()
        {
            events.SetPhase(PHASE_GROUND);

            DoZoneInCombat();

            if (me->getThreatManager().isThreatListEmpty())
                Reset();
            else
            {
                uint8 secondsGround;
                switch (balconyCount)
                {
                    case 0:
                        secondsGround =  90;
                        break;
                    case 1:
                        secondsGround = 110;
                        break;
                    case 2:
                    default:
                        secondsGround = 180;
                }
                events.ScheduleEvent(EVENT_GROUND_ATTACKABLE, 2 * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_BALCONY, secondsGround * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_CURSE, urand(10,25) * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_WARRIOR, urand(20,30) * IN_MILLISECONDS, 0, PHASE_GROUND);
                if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                    events.ScheduleEvent(EVENT_BLINK, urand(20,30) * IN_MILLISECONDS, 0, PHASE_GROUND);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->setActive(true);
            summon->AI()->DoZoneInCombat(nullptr, 250.0f); // specify range to cover entire room - default 50yd is not enough
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override // prevent noth from somehow dying in the balcony phase
        {
            if (!events.IsInPhase(PHASE_BALCONY))
                return;
            if (damage < me->GetHealth())
                return;

            me->SetHealth(1u);
            damage = 0u;
        }

        void HandleSummon(uint32* spellsList, const uint8 nSpells, uint8 num)
        { // this ensures we do not spawn two mobs using the same spell (<=> in the same position) if we can help it
            while (num)
                for (uint8 it = 0; it < nSpells && num; ++it)
                {
                    num--;
                    uint8 selected = urand(it, nSpells - 1);
                    DoCastAOE(spellsList[selected]);
                    if (selected != it) // shuffle the selected into the part of the array that is no longer being searched
                        std::swap(spellsList[selected], spellsList[it]);
                }
        }

        void CastSummon(uint8 nWarrior, uint8 nChampion, uint8 nGuardian)
        {
            HandleSummon(_SummonWarriorSpells, N_WARRIOR_SPELLS, nWarrior);
            HandleSummon(_SummonChampionSpells, N_CHAMPION_SPELLS, nChampion);
            HandleSummon(_SummonGuardianSpells, N_GUARDIAN_SPELLS, nGuardian);
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
                    case EVENT_CURSE:
                    {
                        DoCastAOE(SPELL_CURSE);
                        events.ScheduleEvent(EVENT_CURSE, urand(50, 70) * IN_MILLISECONDS, 0, PHASE_GROUND);
                        break;
                    }
                    case EVENT_WARRIOR:
                        Talk(SAY_SUMMON);
                        Talk(EMOTE_SUMMON);

                        CastSummon(RAID_MODE(2, 3), 0, 0);

                        events.ScheduleEvent(EVENT_WARRIOR, 40 * IN_MILLISECONDS, 0, PHASE_GROUND);
                        break;
                    case EVENT_BLINK:
                        DoCastAOE(SPELL_CRIPPLE, true);
                        DoCastAOE(SPELL_BLINK);
                        DoResetThreat();
                        justBlinked = true;

                        events.ScheduleEvent(EVENT_BLINK, 40000, 0, PHASE_GROUND);
                        break;
                    case EVENT_BALCONY:
                        events.SetPhase(PHASE_BALCONY);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                        me->AttackStop();
                        me->StopMoving();
                        me->RemoveAllAuras();

                        events.ScheduleEvent(EVENT_BALCONY_TELEPORT, 3 * IN_MILLISECONDS, 0, PHASE_BALCONY);
                        events.ScheduleEvent(EVENT_WAVE, urand(5 * IN_MILLISECONDS, 8 * IN_MILLISECONDS), 0, PHASE_BALCONY);

                        uint8 secondsBalcony;
                        switch (balconyCount)
                        {
                            case 0:
                                secondsBalcony = 70;
                                break;
                            case 1:
                                secondsBalcony = 97;
                                break;
                            case 2:
                            default:
                                secondsBalcony = 120;
                                break;
                        }
                        events.ScheduleEvent(EVENT_GROUND, secondsBalcony * IN_MILLISECONDS, 0, PHASE_BALCONY);
                        break;
                    case EVENT_BALCONY_TELEPORT:
                        Talk(EMOTE_TELEPORT_1);
                        DoCastAOE(SPELL_TELEPORT);
                        break;
                    case EVENT_WAVE:
                        Talk(EMOTE_SUMMON_WAVE);
                        switch (balconyCount)
                        {
                            case 0:
                                CastSummon(0, RAID_MODE(2, 4), 0);
                                break;
                            case 1:
                                CastSummon(0, RAID_MODE(1, 2), RAID_MODE(1, 2));
                                break;
                            case 2:
                                CastSummon(0, 0, RAID_MODE(2, 4));
                                break;
                            default:
                                CastSummon(0, RAID_MODE(5, 10), RAID_MODE(5, 10));
                                break;
                        }
                        events.ScheduleEvent(EVENT_WAVE, urand(30, 45) * IN_MILLISECONDS, 0, PHASE_BALCONY);
                        break;
                    case EVENT_GROUND:
                        ++balconyCount;

                        DoCastAOE(SPELL_TELEPORT_BACK);
                        Talk(EMOTE_TELEPORT_2);

                        EnterPhaseGround();
                        break;
                    case EVENT_GROUND_ATTACKABLE:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                }
            }

            if (events.IsInPhase(PHASE_GROUND))
            {
                /* workaround for movechase breaking after blinking
                   without this noth would just stand there unless his current target moves */
                if (justBlinked && me->GetVictim() && !me->IsWithinMeleeRange(me->EnsureVictim()))
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveChase(me->EnsureVictim());
                    justBlinked = false;
                }
                else
                    DoMeleeAttackIfReady();
            }
        }

        private:
            uint32 balconyCount;

            bool justBlinked;

            uint32 _SummonWarriorSpells[N_WARRIOR_SPELLS];
            uint32 _SummonChampionSpells[N_CHAMPION_SPELLS];
            uint32 _SummonGuardianSpells[N_GUARDIAN_SPELLS];
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_nothAI>(creature);
    }
};

void AddSC_boss_noth()
{
    new boss_noth();
}
