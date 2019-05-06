/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "ScriptedCreature.h"

enum VanCleefData
{
    SPELL_DUAL_WIELD = 674,
    SPELL_THRASH = 12787,
    SPELL_VANCLEEFS_ALLIES = 5200
};

enum Speech
{
    SAY_AGGRO  = 0,    // None may challenge the Brotherhood!
    SAY_ONE    = 1,    // Lapdogs, all of you!
    SAY_SUMMON = 2,    // calls more of his allies out of the shadows.
    SAY_TWO    = 3,    // Fools! Our cause is righteous!
    SAY_KILL   = 4,    // And stay down!
    SAY_THREE  = 5     // The Brotherhood shall prevail!
};

// TDB coords
Position const BlackguardPositions[] =
{
    { -78.2791f, -824.784f, 40.0007f, 2.93215f },
    { -77.8071f, -815.097f, 40.0188f, 3.26377f }
};

struct boss_vancleef : public BossAI
{
    public:
        boss_vancleef(Creature* creature) : BossAI(creature, DATA_VANCLEEF), _guardsCalled(false), _health25(false), _health33(false), _health66(false) { }

        void Reset() override
        {
            BossAI::Reset();

            _guardsCalled = false;
            _health25 = false;
            _health33 = false;
            _health66 = false;

            DoCastSelf(SPELL_DUAL_WIELD, true);
            DoCastSelf(SPELL_THRASH, true);

            SummonBlackguards();
        }

        void JustEngagedWith(Unit* victim) override
        {
            BossAI::JustEngagedWith(victim);
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

        void SummonBlackguards()
        {
            for (Position BlackguardPosition : BlackguardPositions)
                DoSummon(NPC_BLACKGUARD, BlackguardPosition, 60000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!_guardsCalled && HealthBelowPct(50))
            {
                Talk(SAY_SUMMON);
                DoCastSelf(SPELL_VANCLEEFS_ALLIES);
                _guardsCalled = true;
            }

            if (!_health25 && HealthBelowPct(25))
            {
                Talk(SAY_THREE);
                _health25 = true;
            }
            else if (!_health33 && HealthBelowPct(33))
            {
                Talk(SAY_TWO);
                _health33 = true;
            }
            else if (!_health66 && HealthBelowPct(66))
            {
                Talk(SAY_ONE);
                _health66 = true;
            }
        }

    private:
        bool _guardsCalled;
        bool _health25;
        bool _health33;
        bool _health66;
};

void AddSC_boss_vancleef()
{
    RegisterDeadminesCreatureAI(boss_vancleef);
}
