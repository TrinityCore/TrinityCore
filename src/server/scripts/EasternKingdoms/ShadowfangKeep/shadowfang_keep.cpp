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
#include "shadowfang_keep.h"
#include "MotionMaster.h"
#include "GridNotifiersImpl.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "InstanceScript.h"

enum Events
{
};

enum MovePoints
{
};

enum Texts
{
    // Packleader Ivar Bloodfang
    SAY_IVAR_WALDEN_INTRO           = 7,

    // Bloodfang Berserker
    SAY_SHOW_COMMANDER_SPRINGVALE   = 1,

    // DEBUG Announcer
    SAY_ANNOUNCE_GARGOYLES          = 0
};

enum SKShieldOfBones
{
    SPELL_SHIELD_OF_BONES_TRIGGERED = 91631
};

class spell_sfk_shield_of_bones : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHIELD_OF_BONES_TRIGGERED });
    }

    void OnAuraRemoveHandler(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByEnemySpell))
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_SHIELD_OF_BONES_TRIGGERED, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_sfk_shield_of_bones::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

class at_sfk_baron_silverlaine_post_floor : public OnlyOnceAreaTriggerScript
{
public:
    at_sfk_baron_silverlaine_post_floor() : OnlyOnceAreaTriggerScript("at_sfk_baron_silverlaine_post_floor") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (Creature* berserker = player->FindNearestCreature(NPC_BLOODFANG_BERSERKER, 15.f, true))
            if (berserker->IsAIEnabled)
                berserker->AI()->Talk(SAY_SHOW_COMMANDER_SPRINGVALE, player);

        return true;
    }
};

class at_sfk_outside_troups : public OnlyOnceAreaTriggerScript
{
public:
    at_sfk_outside_troups() : OnlyOnceAreaTriggerScript("at_sfk_outside_troups") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(DATA_OUTSIDE_TROUPS_SPAWN, DONE);

        return true;
    }
};

class at_sfk_outside_ivar_bloodfang : public OnlyOnceAreaTriggerScript
{
public:
    at_sfk_outside_ivar_bloodfang() : OnlyOnceAreaTriggerScript("at_sfk_outside_ivar_bloodfang") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (Creature* ivar = player->FindNearestCreature(NPC_PACKLEADER_IVAR_BLOODFANG, 15.f))
            if (ivar->IsAIEnabled)
                ivar->AI()->Talk(SAY_IVAR_WALDEN_INTRO, player);

        return true;
    }
};

class at_sfk_godfrey_intro : public OnlyOnceAreaTriggerScript
{
public:
    at_sfk_godfrey_intro() : OnlyOnceAreaTriggerScript("at_sfk_godfrey_intro") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (instance->GetBossState(DATA_LORD_GODFREY) != DONE)
                instance->SetData(DATA_GODFREY_INTRO_SPAWN, DONE);

        return true;
    }
};

class at_sfk_gargoyle_event : public OnlyOnceAreaTriggerScript
{
public:
    at_sfk_gargoyle_event() : OnlyOnceAreaTriggerScript("at_sfk_gargoyle_event") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* announcer = instance->GetCreature(DATA_DEBUG_ANNOUNCER))
                if (announcer->IsAIEnabled)
                    announcer->AI()->Talk(SAY_ANNOUNCE_GARGOYLES);
        }
        return true;
    }
};

void AddSC_shadowfang_keep()
{
    RegisterSpellScript(spell_sfk_shield_of_bones);
    new at_sfk_outside_troups();
    new at_sfk_outside_ivar_bloodfang();
    new at_sfk_godfrey_intro();
    new at_sfk_baron_silverlaine_post_floor();
    new at_sfk_gargoyle_event();
}
