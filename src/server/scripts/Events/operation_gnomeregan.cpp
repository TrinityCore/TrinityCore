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
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum BasicOrdersEmote
{
    SPELL_TEST_SALUTE        = 73835,
    SPELL_TEST_ROAR          = 73836,
    SPELL_TEST_CHEER         = 73725,
    SPELL_TEST_DANCE         = 73837,
    SPELL_TEST_STOP_DANCE    = 73886
};

/* 73725 - [DND] Test Cheer
   73835 - [DND] Test Salute
   73836 - [DND] Test Roar
   73837 - [DND] Test Dance
   73886 - [DND] Test Stop Dance */
class spell_operation_gnomeregan_basic_orders_emote : public AuraScript
{
    PrepareAuraScript(spell_operation_gnomeregan_basic_orders_emote);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();

        switch (GetSpellInfo()->Id)
        {
            case SPELL_TEST_SALUTE:
                target->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                break;
            case SPELL_TEST_ROAR:
                target->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                break;
            case SPELL_TEST_CHEER:
                target->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                break;
            case SPELL_TEST_DANCE:
                target->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_DANCE);
                break;
            case SPELL_TEST_STOP_DANCE:
                target->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                break;
            default:
                return;
        }
        Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_operation_gnomeregan_basic_orders_emote::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_event_operation_gnomeregan()
{
    RegisterSpellScript(spell_operation_gnomeregan_basic_orders_emote);
}
