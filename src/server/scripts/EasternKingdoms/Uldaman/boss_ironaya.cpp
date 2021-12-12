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
SDName: Boss_Ironaya
SD%Complete: 100
SDComment:
SDCategory: Uldaman
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "uldaman.h"

enum Ironaya
{
    SPELL_ARCINGSMASH           = 8374,
    SPELL_KNOCKAWAY             = 10101,
    SPELL_WSTOMP                = 11876
};

struct boss_ironaya : public ScriptedAI
{
    boss_ironaya(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _hasCastKnockaway = false;
        _hasCastWstomp = false;
    }

    void Reset() override
    {
        _scheduler.CancelAll();
        Initialize();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_hasCastKnockaway && HealthBelowPct(50) && me->GetVictim())
        {
            _hasCastKnockaway = true;
            DoCastVictim(SPELL_KNOCKAWAY, true);
            ResetThreat(me->GetVictim(), me);
        }

        if (!_hasCastWstomp && HealthBelowPct(25))
        {
            _hasCastWstomp = true;
            DoCastSelf(SPELL_WSTOMP);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(3s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_ARCINGSMASH);
            task.Repeat(13s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
    bool _hasCastKnockaway;
    bool _hasCastWstomp;
};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_boss_ironaya()
{
    RegisterUldamanCreatureAI(boss_ironaya);
}
