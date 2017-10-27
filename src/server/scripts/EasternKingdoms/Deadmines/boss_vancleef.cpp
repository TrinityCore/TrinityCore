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
#include "ScriptedCreature.h"
#include "deadmines.h"

enum VanCleefData
{
    NPC_BLACKGUARD = 636,

    SPELL_DUAL_WIELD = 674,
    SPELL_THRASH = 12787,
    SPELL_VANCLEEFS_ALLIES = 5200,

    PHASE_NORMAL = 1,
    PHASE_66_PCT = 2,
    PHASE_50_PCT = 3,
    PHASE_33_PCT = 4,
    PHASE_25_PCT = 5
};

enum Speech
{
    SAY_AGGRO = 0,		// None may challenge the Brotherhood!
    SAY_ONE = 1,		// Lapdogs, all of you!
    SAY_SUMMON = 2,		// calls more of his allies out of the shadows.
    SAY_TWO = 3,		// Fools! Our cause is righteous!
    SAY_KILL = 4,		// And stay down!
    SAY_THREE = 5		// The Brotherhood shall prevail!
};

// From TDB 335.63
Position const BlackguardPositions[] =
{
        { -78.2791f, -824.784f, 40.0007f,2.93215f },
        { -77.8071f, -815.097f, 40.0188f, 3.26377f }
};

class boss_vancleef : public CreatureScript
{
public:
    boss_vancleef() : CreatureScript("boss_vancleef") { }

    struct boss_vancleefAI: public BossAI
    {
        boss_vancleefAI(Creature* creature) : BossAI(creature, 0)
        {
            _phase = PHASE_NORMAL;
        }

        void Initialize()
        {
            DoCastSelf(SPELL_DUAL_WIELD, true);
            DoCastSelf(SPELL_THRASH, true);

            _SummonBlackguards();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            summons.DoZoneInCombat();

            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            summons.DespawnAll();
            _DespawnAtEvade();
        }

        void Reset() override
        {
            BossAI::Reset();
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update(diff, [this]
            {
                DoMeleeAttackIfReady();
            });
        }

        void _SummonBlackguards()
        {
            for (auto BlackguardPosition : BlackguardPositions)
                DoSummon(NPC_BLACKGUARD, BlackguardPosition, 60000,
                        TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        void _SwitchPhase(uint8 Phase)
        {
            // don't repeat
            if (_phase == Phase)
                return;

            _phase = Phase;

            switch (_phase)
            {
            case PHASE_66_PCT:
                Talk(SAY_ONE);
                break;
            case PHASE_50_PCT:
                Talk(SAY_SUMMON);
                DoCastSelf(SPELL_VANCLEEFS_ALLIES);
                break;
            case PHASE_33_PCT:
                Talk(SAY_TWO);
                break;
            case PHASE_25_PCT:
                Talk(SAY_THREE);
                break;
            default:
                break;
            }
        }

        void ScheduleTasks() override
        {
            scheduler.Schedule(Seconds(1), [this](TaskContext task)
            {
                if (_phase == PHASE_NORMAL && HealthBelowPct(66))
                    _SwitchPhase(PHASE_66_PCT);
                else if (_phase == PHASE_66_PCT && HealthBelowPct(50))
                    _SwitchPhase(PHASE_50_PCT);
                else if (_phase == PHASE_50_PCT && HealthBelowPct(33))
                    _SwitchPhase(PHASE_33_PCT);
                else if (_phase == PHASE_33_PCT && HealthBelowPct(25))
                    _SwitchPhase(PHASE_25_PCT);

                task.Repeat(Seconds(1));
            });
        }

    protected:
        uint8 _phase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetDeadminesAI<boss_vancleefAI>(creature);
    }
};

void AddSC_boss_vancleef()
{
    new boss_vancleef();
}
