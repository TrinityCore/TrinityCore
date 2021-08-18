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
#include "ScriptedCreature.h"
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_POISON_CLOUD     = 3815,
    SPELL_FRENZIED_RAGE    = 3490
};

enum Events
{
    EVENT_POISON_CLOUD     = 1,
    EVENT_FRENZIED_RAGE
};

struct boss_aku_mai : public BossAI
{
    boss_aku_mai(Creature* creature) : BossAI(creature, DATA_AKU_MAI)
    {
        Initialize();
    }

    void Initialize()
    {
        IsEnraged = false;
    }

    void Reset() override
    {
        Initialize();
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_POISON_CLOUD, 5s, 9s);
    }

    void DamageTaken(Unit* /*atacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!IsEnraged && me->HealthBelowPctDamaged(30, damage))
        {
            DoCast(me, SPELL_FRENZIED_RAGE);
            IsEnraged = true;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_POISON_CLOUD:
                DoCastVictim(SPELL_POISON_CLOUD);
                events.ScheduleEvent(EVENT_POISON_CLOUD, 25s, 50s);
                break;
            default:
                break;
        }
    }

    private:
        bool IsEnraged;
};

void AddSC_boss_aku_mai()
{
    RegisterBlackfathomDeepsCreatureAI(boss_aku_mai);
}
