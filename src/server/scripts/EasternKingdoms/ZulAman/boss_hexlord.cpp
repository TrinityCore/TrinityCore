/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "zulaman.h"

enum Texts
{
};

enum Spells
{
};

enum Events
{
};

struct boss_hexlord_malacrass : public BossAI
{
    boss_hexlord_malacrass(Creature* creature) : BossAI(creature, DATA_HEXLORD_MALACRASS)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void Reset() override
    {
        _Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
    }
};

void AddSC_boss_hex_lord_malacrass()
{
    RegisterZulAamanCreatureAI(boss_hexlord_malacrass);
}
