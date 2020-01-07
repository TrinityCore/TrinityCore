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

enum Events
{
};

enum MovePoints
{
};

enum Texts
{
    // Deathstalker Commander Belmont
    SAY_BELMONT_ASHBURY_DEAD    = 0,
    SAY_BELMONT_MOVE_TO_DOOR    = 1,
    SAY_BELMONT_UNLOCK_DOOR     = 2,
    SAY_BELMONT_OPEN_DOOR       = 3,
    SAY_BELMONT_SILVERLAINE_DEAD = 4,
    SAY_BELMONT_TO_CROMUSH_1    = 5,
    SAY_BELMONT_TO_CROMUSH_2    = 6,
    SAY_BELMONT_TO_CROMUSH_3    = 7,
    SAY_BELMONT_WALDEN_DEAD     = 8,
    SAY_BELMONT_WALDEN_OUTRO    = 9,
    SAY_BELMONT_DOOR_CLOSED     = 10,
    SAY_BELMONT_DOOR_OPENED     = 11,
    SAY_BELMONT_GODFREY         = 12,

    // High Warlord Cromush
    SAY_CROMUSH_TO_BELMONT_1    = 0,
    SAY_CROMUSH_TO_BELMONT_2    = 1,
    SAY_CROMUSH_FOR_THE_HORDE   = 2,
    SAY_CROMUSH_TO_BELMONT_3    = 3,

    // Packleader Ivar Bloodfang
    SAY_IVAR_ASHBURY_DEAD_1     = 0,
    SAY_IVAR_ASHBURY_DEAD_2     = 1,
    SAY_IVAR_TALK_TO_PACK_1     = 2,
    SAY_IVAR_MOVE_TO_COURTYARD  = 3,
    SAY_IVAR_UNLOCK_DOOR        = 4,
    SAY_IVAR_EMOTE_BERSERKER    = 5,
    SAY_IVAR_SILVERLAINE_DEAD   = 6,
    SAY_IVAR_WALDEN_INTRO       = 7,
    SAY_IVAR_WALDEN_DEAD        = 8,
    SAY_IVAR_ATTACK_WORGEN      = 9,
    SAY_IVAR_OPEN_GATE          = 10,
    SAY_IVAR_DOOR_CLOSED_1      = 11,
    SAY_IVAR_DOOR_CLOSED_2      = 12,
    SAY_IVAR_ROOM_OPEN          = 13
};

enum SKShieldOfBones
{
    SPELL_SHIELD_OF_BONES_TRIGGERED = 91631,
};

class spell_sfk_shield_of_bones : public AuraScript
{
    PrepareAuraScript(spell_sfk_shield_of_bones);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHIELD_OF_BONES_TRIGGERED });
    }

    void OnAuraRemoveHandler(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_SHIELD_OF_BONES_TRIGGERED, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sfk_shield_of_bones::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

class at_sfk_pre_walden : public AreaTriggerScript
{
public:
    at_sfk_pre_walden() : AreaTriggerScript("at_sfk_pre_walden") { }

    bool OnTrigger(Player* /*player*/, AreaTriggerEntry const* /*areaTrigger*/)
    {
        return true;
    }
};

class at_sfk_godfrey_intro : public AreaTriggerScript
{
public:
    at_sfk_godfrey_intro() : AreaTriggerScript("at_sfk_godfrey_intro") { }

    bool OnTrigger(Player* /*player*/, AreaTriggerEntry const* /*areaTrigger*/)
    {
        return true;
    }
};

void AddSC_shadowfang_keep()
{
    RegisterAuraScript(spell_sfk_shield_of_bones);
    new at_sfk_pre_walden();
    new at_sfk_godfrey_intro();
}
