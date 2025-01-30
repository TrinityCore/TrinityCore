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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "atal_dazar.h"

enum VolkaalSpells
{
    SPELL_RAPID_DECAY        = 250241,
    SPELL_RAPID_DECAY_TARGET = 250694,
    SPELL_RAPID_DECAY_RANDOM = 250697
};

enum VolkaalEvents
{
    EVENT_TERRIFYING_VISAGE = 1,
    EVENT_TAIL,
    EVENT_SERRATED_TEETH,
    EVENT_PURSUIT
};

enum VolkaalTexts
{
    SAY_REANIMATED_RAPTOR_WARNING  = 0,
    SAY_REANIMATED_RAPTOR_SUMMONER = 1,
    SAY_TERRIFYING_VISAGE          = 2,
    SAY_PURSUIT                    = 3
};

// 250241 - Rapid Decay
class spell_volkaal_rapid_decay : public AuraScript
{
    void HandleToxicPool(AuraEffect const* aurEff) const
    {
        Unit* caster = GetCaster();
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;
        args.TriggeringAura = aurEff;
        caster->CastSpell(caster->GetThreatManager().GetCurrentVictim(), SPELL_GASEOUS_BLOAT, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_volkaal_rapid_decay::HandleToxicPool, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_volkaal()
{
    //RegisterAtalDazarCreatureAI(boss_Volkaal);

}
