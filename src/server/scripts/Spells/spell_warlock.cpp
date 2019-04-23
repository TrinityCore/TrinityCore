/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

/*
* Scripts for spells with SPELLFAMILY_WARLOCK and SPELLFAMILY_GENERIC spells used by warlock players.
* Ordered alphabetically using scriptname.
* Scriptnames of files in this file should be prefixed with "spell_warl_".
*/

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "PetAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellPackets.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "WorldPacket.h"
#include "World.h"

enum WarlockSpells
{
    SPELL_WARLOCK_ABSOLUTE_CORRUPTION               = 196103,
    SPELL_WARLOCK_AFTERMATH_STUN                    = 85387,
    SPELL_WARLOCK_AGONY                             = 980,
    SPELL_WARLOCK_ARCHIMONDES_VENGEANCE_COOLDOWN    = 116405,
    SPELL_WARLOCK_ARCHIMONDES_VENGEANCE_DAMAGE      = 124051,
    SPELL_WARLOCK_ARCHIMONDES_VENGEANCE_PASSIVE     = 116403,
    SPELL_WARLOCK_BACKDRAFT                         = 117828,
    SPELL_WARLOCK_BACKDRAFT_AURA                    = 196406,
    SPELL_WARLOCK_BANE_OF_DOOM_EFFECT               = 18662,
    SPELL_WARLOCK_BURNING_RUSH                      = 111400,
    SPELL_WARLOCK_CALL_DREADSTALKERS                = 104316,
    SPELL_WARLOCK_CALL_DREADSTALKERS_SUMMON         = 193331,
    SPELL_WARLOCK_CHANNEL_DEMONFIRE_ACTIVATOR       = 228312,
    SPELL_WARLOCK_CHANNEL_DEMONFIRE_DAMAGE          = 196448,
    SPELL_WARLOCK_COMMAND_DEMON_OVERRIDER           = 119904,
    SPELL_WARLOCK_CONFLAGRATE                       = 17962,
    SPELL_WARLOCK_CONFLAGRATE_FIRE_AND_BRIMSTONE    = 108685,
    SPELL_WARLOCK_CORRUPTION                        = 172,
    SPELL_WARLOCK_CORRUPTION_DAMAGE                 = 146739,
    SPELL_WARLOCK_CREATE_HEALTHSTONE                = 23517,
    SPELL_WARLOCK_CURSE_OF_DOOM_EFFECT              = 18662,
    SPELL_WARLOCK_DARK_BARGAIN_DOT                  = 110914,
    SPELL_WARLOCK_DARK_REGENERATION                 = 108359,
    SPELL_WARLOCK_DARK_SOUL_INSTABILITY             = 113858,
    SPELL_WARLOCK_DARK_SOUL_KNOWLEDGE               = 113861,
    SPELL_WARLOCK_DARK_SOUL_MISERY                  = 113860,
    SPELL_WARLOCK_DECIMATE_AURA                     = 108869,
    SPELL_WARLOCK_DEMON_SOUL_FELGUARD               = 79452,
    SPELL_WARLOCK_DEMON_SOUL_FELHUNTER              = 79460,
    SPELL_WARLOCK_DEMON_SOUL_IMP                    = 79459,
    SPELL_WARLOCK_DEMON_SOUL_SUCCUBUS               = 79453,
    SPELL_WARLOCK_DEMON_SOUL_VOIDWALKER             = 79454,
    SPELL_WARLOCK_DEMONBOLT                         = 157695,
    SPELL_WARLOCK_DEMONIC_CALL                      = 114925,
    SPELL_WARLOCK_DEMONIC_CALLING                   = 205145,
    SPELL_WARLOCK_DEMONIC_CALLING_TRIGGER           = 205146,
    SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST         = 62388,
    SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON             = 48018,
    SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT           = 48020,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELGUARD      = 54508,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELHUNTER     = 54509,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_IMP           = 54444,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS      = 54435,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER    = 54443,
    SPELL_WARLOCK_DEMONIC_GATEWAY_PERIODIC_CHARGE   = 113901,
    SPELL_WARLOCK_DEMONIC_GATEWAY_SUMMON_GREEN      = 113886,
    SPELL_WARLOCK_DEMONIC_GATEWAY_TELEPORT_GREEN    = 113896,
    SPELL_WARLOCK_DEMONIC_GATEWAY_TELEPORT_PURPLE   = 120729,
    SPELL_WARLOCK_DEMONIC_LEAP_JUMP                 = 109163,
    SPELL_WARLOCK_DEMONSKIN                         = 219272,
    SPELL_WARLOCK_DEMONWRATH_AURA                   = 193440,
    SPELL_WARLOCK_DEMONWRATH_SOULSHARD              = 194379,
    SPELL_WARLOCK_DESTRUCTION_PASSIVE               = 137046,
    SPELL_WARLOCK_DEVOUR_MAGIC_HEAL                 = 19658,
    SPELL_WARLOCK_DISRUPTED_NETHER                  = 114736,
    SPELL_WARLOCK_DOOM                              = 603,
    SPELL_WARLOCK_DOOM_SOUL_SHARD                   = 193318,
    SPELL_WARLOCK_DRAIN_LIFE_HEAL                   = 89653,
    SPELL_WARLOCK_ERADICATION                       = 196412,
    SPELL_WARLOCK_ERADICATION_DEBUFF                = 196414,
    SPELL_WARLOCK_EYE_LASER                         = 205231,
    SPELL_WARLOCK_FEAR                              = 5782,
    SPELL_WARLOCK_FEAR_BUFF                         = 118699,
    SPELL_WARLOCK_FEAR_EFFECT                       = 118699,
    SPELL_WARLOCK_FEL_FIREBOLT                      = 104318,
    SPELL_WARLOCK_FEL_SYNERGY_HEAL                  = 54181,
    SPELL_WARLOCK_FIRE_AND_BRIMSTONE                = 196408,
    SPELL_WARLOCK_GLYPH_OF_CONFLAGRATE              = 56235,
    SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING           = 56249,
    SPELL_WARLOCK_GLYPH_OF_FEAR                     = 56244,
    SPELL_WARLOCK_GLYPH_OF_FEAR_EFFECT              = 130616,
    SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME              = 63311,
    SPELL_WARLOCK_GLYPH_OF_SIPHON_LIFE              = 63106,
    SPELL_WARLOCK_GLYPH_OF_SOULWELL                 = 58094,
    SPELL_WARLOCK_GLYPH_OF_SOULWELL_VISUAL          = 34145,
    SPELL_WARLOCK_GRIMOIRE_FELGUARD                 = 111898,
    SPELL_WARLOCK_GRIMOIRE_FELHUNTER                = 111897,
    SPELL_WARLOCK_GRIMOIRE_IMP                      = 111859,
    SPELL_WARLOCK_GRIMOIRE_OF_SACRIFICE             = 108503,
    SPELL_WARLOCK_GRIMOIRE_OF_SYNERGY_BUFF          = 171982,
    SPELL_WARLOCK_GRIMOIRE_SUCCUBUS                 = 111896,
    SPELL_WARLOCK_GRIMOIRE_VOIDWALKER               = 111895,
    SPELL_WARLOCK_HAND_OF_DOOM                      = 196283,
    SPELL_WARLOCK_HAND_OF_GULDAN_DAMAGE             = 86040,
    SPELL_WARLOCK_HAND_OF_GULDAN_SUMMON             = 196282,
    SPELL_WARLOCK_HARVEST_LIFE_HEAL                 = 125314,
    SPELL_WARLOCK_HAUNT                             = 48181,
    SPELL_WARLOCK_HAVOC                             = 80240,
    SPELL_WARLOCK_HEALTH_FUNNEL_HEAL                = 217979,
    SPELL_WARLOCK_IMMOLATE                          = 348,
    SPELL_WARLOCK_IMMOLATE_DOT                      = 157736,
    SPELL_WARLOCK_IMMOLATE_FIRE_AND_BRIMSTONE       = 108686,
    SPELL_WARLOCK_IMMOLATE_PROC                     = 193541,
    SPELL_WARLOCK_IMPENDING_DOOM                    = 196270,
    SPELL_WARLOCK_IMPENDING_DOOM_SUMMON             = 196271,
    SPELL_WARLOCK_IMPLOSION_DAMAGE                  = 196278,
    SPELL_WARLOCK_IMPLOSION_JUMP                    = 205205,
    SPELL_WARLOCK_IMPROVED_DREADSTALKERS            = 196272,
    SPELL_WARLOCK_IMPROVED_SOUL_FIRE_PCT            = 85383,
    SPELL_WARLOCK_IMPROVED_SOUL_FIRE_STATE          = 85385,
    SPELL_WARLOCK_INCINERATE                        = 29722,
    SPELL_WARLOCK_ITEM_S12_TIER_4                   = 131632,
    SPELL_WARLOCK_KIL_JAEDENS_CUNNING_PASSIVE       = 108507,
    SPELL_WARLOCK_LIFE_TAP_ENERGIZE                 = 31818,
    SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2               = 32553,
    SPELL_WARLOCK_METAMORPHOSIS                     = 103958,
    SPELL_WARLOCK_MOLTEN_CORE                       = 122355,
    SPELL_WARLOCK_MOLTEN_CORE_AURA                  = 122351,
    SPELL_WARLOCK_NETHER_TALENT                     = 91713,
    SPELL_WARLOCK_NETHER_WARD                       = 91711,
    SPELL_WARLOCK_NIGHTFALL                         = 108558,
    SPELL_WARLOCK_PHANTOMATIC_SINGULARITY           = 205179,
    SPELL_WARLOCK_PHANTOMATIC_SINGULARITY_DAMAGE    = 205246,
    SPELL_WARLOCK_POWER_TRIP                        = 196605,
    SPELL_WARLOCK_POWER_TRIP_ENERGIZE               = 216125,
    SPELL_WARLOCK_PYROCLASM                         = 123686,
    SPELL_WARLOCK_RAIN_OF_FIRE_DAMAGE               = 42223,
    SPELL_WARLOCK_ROARING_BLAZE                     = 205184,
    SPELL_WARLOCK_SEED_OF_CURRUPTION                = 27243,
    SPELL_WARLOCK_SEED_OF_CURRUPTION_DAMAGE         = 27285,
    SPELL_WARLOCK_SHADOW_BOLT                       = 686,
    SPELL_WARLOCK_SHADOW_BOLT_SHOULSHARD            = 194192,
    SPELL_WARLOCK_SHADOW_TRANCE                     = 17941,
    SPELL_WARLOCK_SHADOW_WARD                       = 6229,
    SPELL_WARLOCK_SHADOWBURN_ENERGIZE               = 125882,
    SPELL_WARLOCK_SHADOWFLAME                       = 47960,
    SPELL_WARLOCK_SHADOWY_INSPIRATION               = 196269,
    SPELL_WARLOCK_SHADOWY_INSPIRATION_EFFECT        = 196606,
    SPELL_WARLOCK_SHIELD_OF_SHADOW                  = 115232,
    SPELL_WARLOCK_SIPHON_LIFE_HEAL                  = 63106,
    SPELL_WARLOCK_SOUL_CONDUIT_REFUND               = 215942,
    SPELL_WARLOCK_SOUL_LEECH                        = 228974,
    SPELL_WARLOCK_SOUL_LEECH_ABSORB                 = 108366,
    SPELL_WARLOCK_SOUL_LEECH_AURA                   = 108370,
    SPELL_WARLOCK_SOUL_LINK_DUMMY_AURA              = 108446,
    SPELL_WARLOCK_SOUL_SWAP_AURA                    = 86211,
    SPELL_WARLOCK_SOUL_SWAP_CD_MARKER               = 94229,
    SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER              = 92795,
    SPELL_WARLOCK_SOUL_SWAP_MOD_COST                = 92794,
    SPELL_WARLOCK_SOUL_SWAP_OVERRIDE                = 86211,
    SPELL_WARLOCK_SOUL_SWAP_VISUAL                  = 92795,
    SPELL_WARLOCK_SOULSHATTER                       = 32835,
    SPELL_WARLOCK_SOULWELL_CREATE_HEALTHSTONE       = 34130,
    SPELL_WARLOCK_SOW_THE_SEEDS                     = 196226,
    SPELL_WARLOCK_SPAWN_PURPLE_DEMONIC_GATEWAY      = 113890,
    SPELL_WARLOCK_SUMMON_DREADSTALKER               = 193332,
    SPELL_WARLOCK_SUPPLANT_DEMONIC_COMMAND          = 119904,
    SPELL_WARLOCK_THREATENING_PRESENCE              = 112042,
    SPELL_WARLOCK_TWILIGHT_WARD_METAMORPHOSIS_S12   = 131624,
    SPELL_WARLOCK_TWILIGHT_WARD_S12                 = 131623,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION               = 30108,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_1      = 233490,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_2      = 233496,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_3      = 233497,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_4      = 233498,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_5      = 233499,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL        = 196364,
    SPELL_WARLOCK_WRITHE_IN_AGONY                   = 196102,
};

enum WarlockSpellIcons
{
    WARLOCK_ICON_ID_IMPROVED_LIFE_TAP   = 208,
    WARLOCK_ICON_ID_MANA_FEED           = 1982
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT         = 57669,
    SPELL_PRIEST_SHADOW_WORD_DEATH  = 32409
};

enum eGatewaySpells
{
    PortalVisual            = 113900,
    GatewayInteract         = 113902,
    CooldownMarker          = 113942,
    TeleportVisualGreen     = 236762,
    TeleportVisualPurple    = 236671
};

enum eGatewayNpc
{
    GreenGate   = 59262,
    PurpleGate  = 59271
};

// Demonwrath damage - 193439
class spell_warl_demonwrath : public SpellScript
{
    PrepareSpellScript(spell_warl_demonwrath);

    void SelectTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Creature*> pets;
        caster->GetCreatureListInGrid(pets, 100.0f);

        pets.remove_if([caster](Creature* creature)
        {
            if (creature == caster)
                return true;
            if (!creature->HasAura(SPELL_WARLOCK_DEMONWRATH_AURA))
                return true;
            if (creature->GetCreatureType() != CREATURE_TYPE_DEMON)
                return true;
            return false;
        });

        targets.remove_if([pets, caster](WorldObject* obj)
        {
            if (!obj->ToUnit())
                return true;
            if (!caster->IsValidAttackTarget(obj->ToUnit()))
                return true;
            bool inRange = false;
            for (Unit* pet : pets)
                if (pet->GetExactDist(obj) <= 10.0f)
                    inRange = true;

            return !inRange;
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* aur = caster->GetAura(SPELL_WARLOCK_DEMONIC_CALLING))
            if (AuraEffect* aurEff = aur->GetEffect(EFFECT_1))
                if (roll_chance_i(aurEff->GetBaseAmount()))
                    caster->CastSpell(caster, SPELL_WARLOCK_DEMONIC_CALLING_TRIGGER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_demonwrath::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_demonwrath::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// Demonwrath periodic - 193440
class spell_warl_demonwrath_periodic : public AuraScript
{
    PrepareAuraScript(spell_warl_demonwrath_periodic);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 rollChance = GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints;
        if (roll_chance_i(rollChance))
            caster->CastSpell(caster, SPELL_WARLOCK_DEMONWRATH_SOULSHARD, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_demonwrath_periodic::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// Demonbolt - 157695
class spell_warl_demonbolt : public SpellScript
{
    PrepareSpellScript(spell_warl_demonbolt);

    int32 _summons = 0;

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        int32 damage = GetHitDamage();
        AddPct(damage, _summons * 20);
        SetHitDamage(damage);
    }

    void CountSummons(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        for (WorldObject* wo : targets)
        {
            if (!wo->ToCreature())
                continue;
            if (wo->ToCreature()->GetOwner() != caster)
                continue;
            if (wo->ToCreature()->GetCreatureType() != CREATURE_TYPE_DEMON)
                continue;

            _summons++;
        }

        targets.clear();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_demonbolt::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_demonbolt::CountSummons, EFFECT_2, TARGET_UNIT_CASTER_PET);
    }
};

// Immolate Dot - 157736
class spell_warl_immolate_dot : public AuraScript
{
    PrepareAuraScript(spell_warl_immolate_dot);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->ModifyPower(POWER_SOUL_SHARDS, 10);
        caster->CastSpell(caster, SPELL_WARLOCK_CHANNEL_DEMONFIRE_ACTIVATOR, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Unit*> enemies;
        caster->GetAttackableUnitListInRange(enemies, 100.0f);
        enemies.remove_if(Trinity::UnitAuraCheck(false, SPELL_WARLOCK_IMMOLATE_DOT, caster->GetGUID()));
        if (enemies.empty())
            if (Aura* aur = caster->GetAura(SPELL_WARLOCK_CHANNEL_DEMONFIRE_ACTIVATOR))
                aur->SetDuration(0);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_immolate_dot::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        AfterEffectRemove += AuraEffectRemoveFn(spell_warl_immolate_dot::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// Immolate proc - 193541
class spell_warl_immolate_aura : public AuraScript
{
    PrepareAuraScript(spell_warl_immolate_aura);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_WARLOCK_IMMOLATE_DOT)
        {
            int32 rollChance = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
            bool crit = (eventInfo.GetHitMask() & PROC_HIT_CRITICAL) != 0;
            return crit ? roll_chance_i(rollChance * 2) : roll_chance_i(rollChance);
        }
        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_warl_immolate_aura::CheckProc);
    }
};

// Shadow Bolt - 686
class spell_warl_shadow_bolt : public SpellScript
{
    PrepareSpellScript(spell_warl_shadow_bolt);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SHADOW_BOLT, SPELL_WARLOCK_SHADOW_BOLT_SHOULSHARD });
    }

    void HandleOnCast()
    {
		Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_WARLOCK_SHADOW_BOLT_SHOULSHARD, true);

        if (caster->HasAura(SPELL_WARLOCK_SHADOWY_INSPIRATION_EFFECT))
            caster->RemoveAura(SPELL_WARLOCK_SHADOWY_INSPIRATION_EFFECT);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_warl_shadow_bolt::HandleOnCast);
    }
};

// 710 - Banish
class spell_warl_banish : public SpellScript
{
    PrepareSpellScript(spell_warl_banish);

    void HandleBanish(SpellMissInfo missInfo)
    {
        if (missInfo != SPELL_MISS_IMMUNE)
            return;

        if (Unit* target = GetHitUnit())
        {
            // Casting Banish on a banished target will remove applied aura
            if (Aura * banishAura = target->GetAura(GetSpellInfo()->Id, GetCaster()->GetGUID()))
                banishAura->Remove();
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_warl_banish::HandleBanish);
    }
};

// 17962 - Conflagrate
class spell_warl_conflagrate : public SpellScript
{
    PrepareSpellScript(spell_warl_conflagrate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_IMMOLATE });
    }

    void HandleHit(SpellEffIndex /*effindex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (caster->HasAura(SPELL_WARLOCK_BACKDRAFT_AURA))
            caster->CastSpell(caster, SPELL_WARLOCK_BACKDRAFT, true);

        caster->ModifyPower(POWER_SOUL_SHARDS, 50);

        if (caster->HasAura(SPELL_WARLOCK_ROARING_BLAZE))
        {
            if (Aura* aur = target->GetAura(SPELL_WARLOCK_IMMOLATE_DOT, caster->GetGUID()))
            {
                if (AuraEffect* aurEff = aur->GetEffect(EFFECT_0))
                {
                    int32 damage = aurEff->GetDamage();
                    aurEff->SetDamage(AddPct(damage, 25));
                    aur->SetNeedClientUpdateForTargets();
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_conflagrate::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 6201 - Create Healthstone
class spell_warl_create_healthstone : public SpellScript
{
    PrepareSpellScript(spell_warl_create_healthstone);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_CREATE_HEALTHSTONE });
    }

    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_CREATE_HEALTHSTONE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_create_healthstone::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 603 - Bane of Doom
class spell_warl_doom : public AuraScript
{
    PrepareAuraScript(spell_warl_doom);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_WARLOCK_DOOM_SOUL_SHARD, true);
        if (caster->HasAura(SPELL_WARLOCK_IMPENDING_DOOM))
            caster->CastSpell(caster, SPELL_WARLOCK_HAND_OF_GULDAN_SUMMON, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_doom::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};


// 48018 - Demonic Circle: Summon
/// Updated 4.3.4
class spell_warl_demonic_circle_summon : public AuraScript
{
    PrepareAuraScript(spell_warl_demonic_circle_summon);

    bool firstTick = true;

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
    {
        // If effect is removed by expire remove the summoned demonic circle too.
        if (!(mode & AURA_EFFECT_HANDLE_REAPPLY))
            GetTarget()->RemoveGameObject(GetId(), true);

        if (AuraApplication* aurApp = GetTarget()->GetAuraApplication(GetSpellInfo()->Id, GetTarget()->GetGUID()))
            aurApp->SendFakeAuraUpdate(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST, true);
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        if (GetTarget()->GetGameObject(GetId()))
        {
            Unit* target = GetTarget();
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT);

            if (!target || !spellInfo)
                return;

            GameObject* circle = target->GetGameObject(GetId());
            if (!circle)
            {
                if (firstTick)
                    GetAura()->SetDuration(0);

                return;
            }

            // Here we check if player is in demonic circle teleport range, if so add
            // WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST; allowing him to cast the WARLOCK_DEMONIC_CIRCLE_TELEPORT.
            // If not in range remove the WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST.
            if (AuraApplication* circleSummon = target->GetAuraApplication(GetSpellInfo()->Id, target->GetGUID()))
            {
                if (target->IsWithinDist(circle, spellInfo->GetMaxRange(true)))
                    circleSummon->SendFakeAuraUpdate(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST, false);
                else if (target->HasVisibleAura(circleSummon))
                    circleSummon->SendFakeAuraUpdate(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST, true);
            }
            else
                target->RemoveAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_warl_demonic_circle_summon::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_demonic_circle_summon::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 48020 - Demonic Circle: Teleport
/// Updated 4.3.4
class spell_warl_demonic_circle_teleport : public AuraScript
{
    PrepareAuraScript(spell_warl_demonic_circle_teleport);

    void HandleTeleport(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetTarget()->ToPlayer())
        {
            if (GameObject* circle = player->GetGameObject(SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON))
            {
                player->NearTeleportTo(circle->GetPositionX(), circle->GetPositionY(), circle->GetPositionZ(), circle->GetOrientation());
                player->RemoveMovementImpairingAuras();
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_warl_demonic_circle_teleport::HandleTeleport, EFFECT_0, SPELL_AURA_MECHANIC_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Demonic Empowerment - 193396
class spell_warl_demonic_empowerment : public SpellScript
{
    PrepareSpellScript(spell_warl_demonic_empowerment);

    void HandleTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        targets.remove_if([caster](WorldObject* target)
        {
            if (!target->ToCreature())
                return true;

            if (!caster->IsFriendlyTo(target->ToUnit()))
                return true;

            if (target->ToCreature()->GetCreatureType() != CREATURE_TYPE_DEMON)
                return true;

            return false;
        });
    }

    void HandleCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_WARLOCK_SHADOWY_INSPIRATION))
            caster->CastSpell(caster, SPELL_WARLOCK_SHADOWY_INSPIRATION_EFFECT, true);

        if (caster->HasAura(SPELL_WARLOCK_POWER_TRIP) && caster->IsInCombat() && roll_chance_i(50))
            caster->CastSpell(caster, SPELL_WARLOCK_POWER_TRIP_ENERGIZE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_demonic_empowerment::HandleTargets, EFFECT_ALL, TARGET_UNIT_CASTER_PET);
        OnCast += SpellCastFn(spell_warl_demonic_empowerment::HandleCast);
    }
};

// 67518, 19505 - Devour Magic
class spell_warl_devour_magic : public SpellScript
{
    PrepareSpellScript(spell_warl_devour_magic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL });
    }

    void OnSuccessfulDispel(SpellEffIndex /*effIndex*/)
    {
        if (SpellEffectInfo const* effect = GetSpellInfo()->GetEffect(EFFECT_1))
        {
            Unit* caster = GetCaster();
            int32 heal_amount = effect->CalcValue(caster);

            caster->CastCustomSpell(caster, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL, &heal_amount, nullptr, nullptr, true);

            // Glyph of Felhunter
            if (Unit* owner = caster->GetOwner())
                if (owner->GetAura(SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING))
                    owner->CastCustomSpell(owner, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL, &heal_amount, nullptr, nullptr, true);
        }
    }

    void Register() override
    {
        OnEffectSuccessfulDispel += SpellEffectFn(spell_warl_devour_magic::OnSuccessfulDispel, EFFECT_0, SPELL_EFFECT_DISPEL);
    }
};

// 48181 - Haunt
class aura_warl_haunt : public AuraScript
{
    PrepareAuraScript(aura_warl_haunt);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            return;

        caster->GetSpellHistory()->ResetCooldown(SPELL_WARLOCK_HAUNT, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(aura_warl_haunt::HandleRemove, EFFECT_1, SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 755 - Health Funnel
/// Updated 4.3.4
class spell_warl_health_funnel : public AuraScript
{
    PrepareAuraScript(spell_warl_health_funnel);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_HEALTH_FUNNEL_HEAL });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetUnitOwner();
        Unit* caster = GetCaster();
        if (!target || !caster)
            return;

        CustomSpellValues values;
        int32 damage = caster->CountPctFromMaxHealth(4);
        values.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT1, damage * 2);

        caster->CastCustomSpell(SPELL_WARLOCK_HEALTH_FUNNEL_HEAL, values, target, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_health_funnel::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 6262 - Healthstone
class spell_warl_healthstone_heal : public SpellScript
{
    PrepareSpellScript(spell_warl_healthstone_heal);

    void HandleOnHit()
    {
        int32 heal = int32(CalculatePct(GetCaster()->GetCreateHealth(), GetHitHeal()));
        SetHitHeal(heal);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warl_healthstone_heal::HandleOnHit);
    }
};

// 27243 - Seed of Corruption
class spell_warl_seed_of_corruption : public SpellScript
{
    PrepareSpellScript(spell_warl_seed_of_corruption);

    void HandleBeforeCast()
    {
        _maxAdditionalTargets = 0;

        if (Aura* aura = GetCaster()->GetAura(SPELL_WARLOCK_SOW_THE_SEEDS))
            _maxAdditionalTargets += aura->GetSpellEffectInfo(EFFECT_0)->BasePoints;
    }

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> correctedTargets;
        for (WorldObject* obj : targets)
        {
            if (obj == GetExplTargetUnit())
            {
                correctedTargets.push_back(obj);
                continue;
            }

            if (_maxAdditionalTargets)
            {
                correctedTargets.push_back(obj);
                --_maxAdditionalTargets;
            }
        }

        targets = correctedTargets;
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_warl_seed_of_corruption::HandleBeforeCast);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_seed_of_corruption::CorrectTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_seed_of_corruption::CorrectTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
    }

private:
    uint8 _maxAdditionalTargets;
};

// 27243 - Seed of Corruption
class aura_warl_seed_of_corruption : public AuraScript
{
    PrepareAuraScript(aura_warl_seed_of_corruption);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SEED_OF_CURRUPTION_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        aurEff->GetBase()->Remove(AURA_REMOVE_BY_EXPIRE);
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget()->GetPosition(), SPELL_WARLOCK_SEED_OF_CURRUPTION_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_warl_seed_of_corruption::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 27285 - Seed of Corruption damages
class spell_warl_seed_of_corruption_damage : public SpellScript
{
    PrepareSpellScript(spell_warl_seed_of_corruption_damage);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Aura* seedOfCorruption = target->GetAura(SPELL_WARLOCK_SEED_OF_CURRUPTION))
            {
                seedOfCorruption->Remove();
                GetCaster()->CastSpell(target->GetPosition(), SPELL_WARLOCK_SEED_OF_CURRUPTION_DAMAGE, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_seed_of_corruption_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// -7235 - Shadow Ward
class spell_warl_shadow_ward : public AuraScript
{
    PrepareAuraScript(spell_warl_shadow_ward);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            // +80.68% from sp bonus
            float bonus = 0.8068f;

            bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());

            amount += int32(bonus);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_shadow_ward::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// Soul Leech aura - 228974
class spell_warl_soul_leech_aura : public AuraScript
{
    PrepareAuraScript(spell_warl_soul_leech_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_DEMONSKIN });
    }

    bool OnCheckProc(ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return false;

        int32 basePoints = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints;
        int32 absorb = ((eventInfo.GetDamageInfo() ? eventInfo.GetDamageInfo()->GetDamage(): 0) * basePoints) / 100.f;

        // Add remaining amount if already applied
        if (Aura* aur = caster->GetAura(SPELL_WARLOCK_SOUL_LEECH_ABSORB))
            if (AuraEffect* aurEff = aur->GetEffect(EFFECT_0))
                absorb += aurEff->GetAmount();

        // Cannot go over 15% (or 20% with Demonskin) max health
        int32 basePointNormal = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
        int32 basePointDS = sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONSKIN)->GetEffect(EFFECT_1)->BasePoints;
        int32 totalBP = caster->HasAura(SPELL_WARLOCK_DEMONSKIN) ? basePointDS : basePointNormal;
        int32 threshold = (caster->GetMaxHealth() * totalBP) / 100.f;
        absorb = std::min(absorb, threshold);

        caster->CastCustomSpell(SPELL_WARLOCK_SOUL_LEECH_ABSORB, SPELLVALUE_BASE_POINT0, absorb, caster, TRIGGERED_FULL_MASK);
        return true;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_warl_soul_leech_aura::OnCheckProc);
    }
};

// 86121 - Soul Swap
class spell_warl_soul_swap : public SpellScript
{
    PrepareSpellScript(spell_warl_soul_swap);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SOUL_SWAP_CD_MARKER, SPELL_WARLOCK_SOUL_SWAP_OVERRIDE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_OVERRIDE, true);
        GetHitUnit()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

#define SoulSwapOverrideScriptName "spell_warl_soul_swap_override"

// 86211 - Soul Swap Override - Also acts as a dot container
class spell_warl_soul_swap_override : public SpellScriptLoader
{
public:
    spell_warl_soul_swap_override() : SpellScriptLoader(SoulSwapOverrideScriptName) { }

    class spell_warl_soul_swap_override_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_soul_swap_override_AuraScript);

        //! Forced to, pure virtual functions must have a body when linking
        void Register() override { }

    public:
        void AddDot(uint32 id) { _dotList.push_back(id); }
        std::list<uint32> const GetDotList() const { return _dotList; }
        Unit* GetOriginalSwapSource() const { return _swapCaster; }
        void SetOriginalSwapSource(Unit* victim) { _swapCaster = victim; }

    private:
        std::list<uint32> _dotList;
        Unit* _swapCaster = nullptr;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_soul_swap_override_AuraScript();
    }
};

typedef spell_warl_soul_swap_override::spell_warl_soul_swap_override_AuraScript SoulSwapOverrideAuraScript;

//! Soul Swap Copy Spells - 92795 - Simply copies spell IDs.
class spell_warl_soul_swap_dot_marker : public SpellScriptLoader
{
public:
    spell_warl_soul_swap_dot_marker() : SpellScriptLoader("spell_warl_soul_swap_dot_marker") { }

    class spell_warl_soul_swap_dot_marker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_soul_swap_dot_marker_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* swapVictim = GetCaster();
            Unit* warlock = GetHitUnit();
            if (!warlock || !swapVictim)
                return;

            Unit::AuraApplicationMap const& appliedAuras = swapVictim->GetAppliedAuras();
            SoulSwapOverrideAuraScript* swapSpellScript = nullptr;
            if (Aura* swapOverrideAura = warlock->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
                swapSpellScript = dynamic_cast<SoulSwapOverrideAuraScript*>(swapOverrideAura->GetScriptByName(SoulSwapOverrideScriptName));

            if (!swapSpellScript)
                return;

            flag128 classMask = GetEffectInfo()->SpellClassMask;

            for (Unit::AuraApplicationMap::const_iterator itr = appliedAuras.begin(); itr != appliedAuras.end(); ++itr)
            {
                SpellInfo const* spellProto = itr->second->GetBase()->GetSpellInfo();
                if (itr->second->GetBase()->GetCaster() == warlock)
                    if (spellProto->SpellFamilyName == SPELLFAMILY_WARLOCK && (spellProto->SpellFamilyFlags & classMask))
                        swapSpellScript->AddDot(itr->first);
            }

            swapSpellScript->SetOriginalSwapSource(swapVictim);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_dot_marker_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_soul_swap_dot_marker_SpellScript();
    }
};

// 86213 - Soul Swap Exhale
class spell_warl_soul_swap_exhale : public SpellScriptLoader
{
public:
    spell_warl_soul_swap_exhale() : SpellScriptLoader("spell_warl_soul_swap_exhale") { }

    class spell_warl_soul_swap_exhale_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_soul_swap_exhale_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_WARLOCK_SOUL_SWAP_MOD_COST, SPELL_WARLOCK_SOUL_SWAP_OVERRIDE });
        }

        SpellCastResult CheckCast()
        {
            Unit* currentTarget = GetExplTargetUnit();
            Unit* swapTarget = nullptr;
            if (Aura const* swapOverride = GetCaster()->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
                if (SoulSwapOverrideAuraScript* swapScript = dynamic_cast<SoulSwapOverrideAuraScript*>(swapOverride->GetScriptByName(SoulSwapOverrideScriptName)))
                    swapTarget = swapScript->GetOriginalSwapSource();

            // Soul Swap Exhale can't be cast on the same target than Soul Swap
            if (swapTarget && currentTarget && swapTarget == currentTarget)
                return SPELL_FAILED_BAD_TARGETS;

            return SPELL_CAST_OK;
        }

        void OnEffectHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_MOD_COST, true);

            std::list<uint32> dotList;
            Unit* swapSource = nullptr;
            if (Aura const* swapOverride = GetCaster()->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
            {
                SoulSwapOverrideAuraScript* swapScript = dynamic_cast<SoulSwapOverrideAuraScript*>(swapOverride->GetScriptByName(SoulSwapOverrideScriptName));
                if (!swapScript)
                    return;
                dotList = swapScript->GetDotList();
                swapSource = swapScript->GetOriginalSwapSource();
            }

            if (dotList.empty())
                return;

            for (std::list<uint32>::const_iterator itr = dotList.begin(); itr != dotList.end(); ++itr)
            {
                GetCaster()->AddAura(*itr, GetHitUnit());
                if (swapSource)
                    swapSource->RemoveAurasDueToSpell(*itr);
            }

            // Remove Soul Swap Exhale buff
            GetCaster()->RemoveAurasDueToSpell(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_soul_swap_exhale_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_exhale_SpellScript::OnEffectHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_soul_swap_exhale_SpellScript();
    }
};

// 29858 - Soulshatter
/// Updated 4.3.4
class spell_warl_soulshatter : public SpellScriptLoader
{
public:
    spell_warl_soulshatter() : SpellScriptLoader("spell_warl_soulshatter") { }

    class spell_warl_soulshatter_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_soulshatter_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOULSHATTER))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* target = GetHitUnit())
                if (target->CanHaveThreatList() && target->getThreatManager().getThreat(caster) > 0.0f)
                    caster->CastSpell(target, SPELL_WARLOCK_SOULSHATTER, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_soulshatter_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_soulshatter_SpellScript();
    }
};

// 30108 Unstable Affliction
class spell_warl_unstable_affliction : public SpellScript
{
    PrepareSpellScript(spell_warl_unstable_affliction);

    const uint32 damageSpells[5] =
    {
        SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_1,
        SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_2,
        SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_3,
        SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_4,
        SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE_5,
    };

    void HandleOnHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            for (uint8 i = 0; i < 5; ++i)
            {
                if (target->HasAura(damageSpells[i]))
                    continue;

                GetCaster()->CastSpell(target, damageSpells[i], true);
                break;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_unstable_affliction::HandleOnHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 233490 - 233496 - 233497 - 233498 - 233499 - Unstable Affliction
class aura_warl_unstable_affliction : public AuraScript
{
    PrepareAuraScript(aura_warl_unstable_affliction);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL });
    }

    void HandleDispel(DispelInfo* dispelInfo)
    {
        if (Unit* caster = GetCaster())
        {
            // backfire damage and silence
            int32 damage = int32(4.0f * 0.927f * caster->SpellBaseDamageBonusDone(GetSpellInfo()->GetSchoolMask()));
            caster->CastCustomSpell(dispelInfo->GetDispeller(), SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL, &damage, nullptr, nullptr, true);
        }
    }

    void HandleRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
    {
        if (GetCaster() && GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
            GetCaster()->ModifyPower(POWER_SOUL_SHARDS, 10);
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(aura_warl_unstable_affliction::HandleDispel);
        OnEffectRemove += AuraEffectApplyFn(aura_warl_unstable_affliction::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

enum lifeTap
{
    SPELL_WARLOCK_LIFE_TAP = 1454,
    SPELL_WARLOCK_LIFE_TAP_GLYPH = 63320,
};

// Life Tap - 1454
class spell_warl_life_tap : public SpellScriptLoader
{
public:
    spell_warl_life_tap() : SpellScriptLoader("spell_warl_life_tap") { }

    class spell_warl_life_tap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_life_tap_SpellScript);

        SpellCastResult CheckLife()
        {
            if (GetCaster()->GetHealthPct() > 15.0f || GetCaster()->HasAura(SPELL_WARLOCK_LIFE_TAP_GLYPH))
                return SPELL_CAST_OK;
            return SPELL_FAILED_FIZZLE;
        }

        void HandleOnHitTarget(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            if (!GetCaster()->HasAura(SPELL_WARLOCK_LIFE_TAP_GLYPH))
                GetCaster()->EnergizeBySpell(GetCaster(), SPELL_WARLOCK_LIFE_TAP, int32(GetCaster()->GetMaxHealth() * GetSpellInfo()->GetEffect(0)->BasePoints / 100), POWER_MANA);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_life_tap_SpellScript::CheckLife);
            OnEffectHitTarget += SpellEffectFn(spell_warl_life_tap_SpellScript::HandleOnHitTarget, EFFECT_0, SPELL_EFFECT_ENERGIZE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_life_tap_SpellScript();
    }

    class spell_warl_life_tap_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_life_tap_AuraScript);

        void CalculateAmount(AuraEffect const* /* aurEff */, int32& amount, bool& /* canBeRecalculated */)
        {
            if (GetCaster()->HasAura(SPELL_WARLOCK_LIFE_TAP_GLYPH))
                amount *= GetCaster()->GetMaxHealth();
            else
                amount = 0;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_life_tap_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_SCHOOL_HEAL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_life_tap_AuraScript();
    }
};

// 980 - Agony
class spell_warlock_agony : public SpellScriptLoader
{
public:
    spell_warlock_agony() : SpellScriptLoader("spell_warlock_agony") {}

    class spell_warlock_agony_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warlock_agony_AuraScript);

        void HandleDummyPeriodic(AuraEffect const* auraEffect)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            float soulShardAgonyTick = caster->Variables.GetValue<float>("SoulShardAgonyTick", frand(0.0f, 99.0f));
            soulShardAgonyTick += 16.0f;

            if (soulShardAgonyTick >= 100.0f)
            {
                soulShardAgonyTick = frand(0.0f, 99.0f);

                if (Player* player = GetCaster()->ToPlayer())
                    if (player->GetPower(POWER_SOUL_SHARDS) < player->GetMaxPower(POWER_SOUL_SHARDS))
                        player->SetPower(POWER_SOUL_SHARDS, player->GetPower(POWER_SOUL_SHARDS) + 10);
            }

            caster->Variables.Set("SoulShardAgonyTick", soulShardAgonyTick);

            // If we have more than maxStackAmount, dont do anything
            if (GetStackAmount() >= auraEffect->GetBase()->GetMaxStackAmount())
                return;

            SetStackAmount(GetStackAmount() + 1);
        }

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            // If last agony removed, remove tick counter
            if (Unit* caster = GetCaster())
                if (!caster->GetOwnedAura(SPELL_WARLOCK_AGONY))
                    caster->Variables.Remove("SoulShardAgonyTick");
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warlock_agony_AuraScript::HandleDummyPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            AfterEffectRemove += AuraEffectRemoveFn(spell_warlock_agony_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warlock_agony_AuraScript();
    }
};

// Burning Rush - 111400
class spell_warl_burning_rush : public SpellScript
{
    PrepareSpellScript(spell_warl_burning_rush);

    bool _isRemove = false;

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        if (caster->HealthBelowPct(5))
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        return SPELL_CAST_OK;
    }

    void HandleBeforeCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_WARLOCK_BURNING_RUSH))
            _isRemove = true;
    }

    void HandleHit()
    {
        if (_isRemove)
            GetCaster()->RemoveAurasDueToSpell(SPELL_WARLOCK_BURNING_RUSH);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_warl_burning_rush::HandleBeforeCast);
        AfterHit += SpellHitFn(spell_warl_burning_rush::HandleHit);
        OnCheckCast += SpellCheckCastFn(spell_warl_burning_rush::CheckCast);
    }
};

class aura_warl_burning_rush : public AuraScript
{
    PrepareAuraScript(aura_warl_burning_rush);

    void OnTick(const AuraEffect* /* aurEff */)
    {
        if (GetCaster())
        {
            // This way if the current tick takes you below 4%, next tick won't execute
            uint64 basepoints = GetCaster()->CountPctFromMaxHealth(4);
            if (GetCaster()->GetHealth() <= basepoints ||
                GetCaster()->GetHealth() - basepoints <= basepoints)
                GetAura()->SetDuration(0);
        }
    }
    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_warl_burning_rush::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
    }
};

// Chaos Bolt - 116858 and 215279
class spell_warl_chaos_bolt : public SpellScript
{
    PrepareSpellScript(spell_warl_chaos_bolt);

    void HandleCritChance(Unit* /*victim*/, float& chance)
    {
        chance = 100.f;
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* player = GetOriginalCaster())
        {
            int32 damage = GetHitDamage();
            float crit = player->GetFloatValue(ACTIVE_PLAYER_FIELD_SPELL_CRIT_PERCENTAGE1);
            AddPct(damage, crit);
            SetHitDamage(damage);

            if (Unit* target = GetHitUnit())
                if (player->HasAura(SPELL_WARLOCK_ERADICATION))
                    player->CastSpell(target, SPELL_WARLOCK_ERADICATION_DEBUFF, true);
        }
    }

    void Register() override
    {
        OnCalcCritChance += SpellOnCalcCritChanceFn(spell_warl_chaos_bolt::HandleCritChance);
        OnEffectHitTarget += SpellEffectFn(spell_warl_chaos_bolt::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_warl_conflagrate_aura : public SpellScript
{
    PrepareSpellScript(spell_warl_conflagrate_aura);

    void HandleOnHit()
    {
        if (Player* _player = GetCaster()->ToPlayer())
        {
            if (Unit* target = GetHitUnit())
            {
                if (!target->HasAura(SPELL_WARLOCK_IMMOLATE) && !_player->HasAura(SPELL_WARLOCK_GLYPH_OF_CONFLAGRATE))
                    if (target->GetAura(SPELL_WARLOCK_CONFLAGRATE))
                        target->RemoveAura(SPELL_WARLOCK_CONFLAGRATE);

                if (!target->HasAura(SPELL_WARLOCK_IMMOLATE_FIRE_AND_BRIMSTONE))
                    if (target->GetAura(SPELL_WARLOCK_CONFLAGRATE_FIRE_AND_BRIMSTONE))
                        target->RemoveAura(SPELL_WARLOCK_CONFLAGRATE_FIRE_AND_BRIMSTONE);
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warl_conflagrate_aura::HandleOnHit);
    }
};

class spell_warl_dark_regeneration : public AuraScript
{
    PrepareAuraScript(spell_warl_dark_regeneration);

    void HandleApply(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
    {
        if (GetTarget())
            if (Guardian* pet = GetTarget()->GetGuardianPet())
                pet->CastSpell(pet, SPELL_WARLOCK_DARK_REGENERATION, true);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_warl_dark_regeneration::HandleApply, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_warl_demonic_call : public SpellScript
{
    PrepareSpellScript(spell_warl_demonic_call);

    void HandleOnHit()
    {
        if (Player* _player = GetCaster()->ToPlayer())
        {
            if (GetHitUnit())
            {
                if (_player->HasAura(SPELL_WARLOCK_DEMONIC_CALL) && !_player->HasAura(SPELL_WARLOCK_DISRUPTED_NETHER))
                {
                    _player->CastSpell(_player, SPELL_WARLOCK_HAND_OF_GULDAN_SUMMON, true);
                    _player->RemoveAura(SPELL_WARLOCK_DEMONIC_CALL);
                }
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warl_demonic_call::HandleOnHit);
    }
};

class spell_warl_demonic_gateway : public SpellScript
{
    PrepareSpellScript(spell_warl_demonic_gateway);

    void HandleSummon()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Player* player = caster->ToPlayer();
        if (!player)
            return;

        std::list<Creature*> gatewayPurpleList;
        player->GetCreatureListWithEntryInGrid(gatewayPurpleList, 59271, 500.0f);

        for (std::list<Creature*>::iterator i = gatewayPurpleList.begin(); i != gatewayPurpleList.end(); ++i)
        {
            Unit* owner = (*i)->GetOwner();

            if (owner && owner == player && (*i)->IsSummon())
                continue;

            i = gatewayPurpleList.erase(i);
        }

        if ((int32)gatewayPurpleList.size() >= 1)
            gatewayPurpleList.back()->ToTempSummon()->UnSummon();

        std::list<Creature*> gatewayGreenList;
        player->GetCreatureListWithEntryInGrid(gatewayGreenList, 59262, 500.0f);

        for (std::list<Creature*>::iterator i = gatewayGreenList.begin(); i != gatewayGreenList.end(); ++i)
        {
            Unit* owner = (*i)->GetOwner();

            if (owner && owner == player && (*i)->IsSummon())
                continue;

            i = gatewayGreenList.erase(i);
        }

        if ((int32)gatewayGreenList.size() >= 1)
            gatewayGreenList.back()->ToTempSummon()->UnSummon();

        WorldLocation const* dest = GetExplTargetDest();
        if (!dest)
            return;

        caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_WARLOCK_DEMONIC_GATEWAY_SUMMON_GREEN, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_warl_demonic_gateway::HandleSummon);
    }
};

// Drain Soul - 198590
class spell_warl_drain_soul : public SpellScriptLoader
{
public:
    spell_warl_drain_soul() : SpellScriptLoader("spell_warl_drain_soul") { }

    class spell_warl_drain_soul_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_drain_soul_AuraScript);

        void HandleRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
        {
            if (GetCaster() && GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                GetCaster()->ModifyPower(POWER_SOUL_SHARDS, 10);
        }

        void HandleDummyPeriodic(AuraEffect const* /* auraEffect */)
        {
            Unit* target = GetTarget();
            Unit* caster = GetCaster();
            if (!caster || !target)
                return;

            uint32 DrainSoulData[4][3] =
            {
                { 146739,   EFFECT_0, 131740 }, // Corruption
                { 30108,    EFFECT_0, 131736 },
                { 27243,    EFFECT_0, 132566 },
                { 980,      EFFECT_0, 131737 },
            };

            for (uint8 i = 0; i < 4; i++)
            {
                if (target->GetAuraEffect(DrainSoulData[i][0], DrainSoulData[i][1], GetCaster()->GetGUID()))
                    caster->CastSpell(target, DrainSoulData[i][2], true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_drain_soul_AuraScript::HandleDummyPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_LEECH);
            OnEffectRemove += AuraEffectApplyFn(spell_warl_drain_soul_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_LEECH, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_drain_soul_AuraScript();
    }
};

class spell_warl_glyph_of_soulwell : public SpellScriptLoader
{
public:
    spell_warl_glyph_of_soulwell() : SpellScriptLoader("spell_warl_glyph_of_soulwell") { }

    class spell_warl_glyph_of_soulwell_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_glyph_of_soulwell_SpellScript);

        void HandleAfterCast()
        {
            if (!GetCaster())
                return;

            if (!GetExplTargetDest())
                return;

            if (!GetCaster()->HasAura(SPELL_WARLOCK_GLYPH_OF_SOULWELL))
                return;

            GetCaster()->CastSpell(GetExplTargetDest()->GetPositionX(), GetExplTargetDest()->GetPositionY(), GetExplTargetDest()->GetPositionZ(), SPELL_WARLOCK_GLYPH_OF_SOULWELL_VISUAL, true);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_warl_glyph_of_soulwell_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_glyph_of_soulwell_SpellScript();
    }
};

#define ENTRY_IMP               416
#define ENTRY_VOIDWALKER        1860
#define ENTRY_SUCCUBUS          1863
#define ENTRY_FELHUNTER         417
#define ENTRY_FELGUARD          17252
#define ENTRY_WATER_ELEMENTAL   510
#define ENTRY_TREANT            1964
#define ENTRY_FIRE_ELEMENTAL    15438
#define ENTRY_GHOUL             26125
#define ENTRY_BLOODWORM         28017


// Hand of Gul'Dan - 105174
class spell_warl_hand_of_guldan : public SpellScriptLoader
{
public:
    spell_warl_hand_of_guldan() : SpellScriptLoader("spell_warl_hand_of_guldan") { }

    class spell_warl_hand_of_guldan_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_hand_of_guldan_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    int32 nrofsummons = 1;
                    nrofsummons += caster->GetPower(POWER_SOUL_SHARDS);
                    if (nrofsummons > 4)
                        nrofsummons = 4;

                    int8 offsetX[4]{ 0, 0, 1, 1 };
                    int8 offsetY[4]{ 0, 1, 0, 1 };

                    for (int i = 0; i < nrofsummons; i++)
                        caster->CastSpell(target->GetPositionX() + offsetX[i], target->GetPositionY() + offsetY[i], target->GetPositionZ(), SPELL_WARLOCK_HAND_OF_GULDAN_SUMMON, true);
                    caster->CastSpell(target, SPELL_WARLOCK_HAND_OF_GULDAN_DAMAGE, true);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_hand_of_guldan_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_hand_of_guldan_SpellScript();
    }
};


// Hand of Guldan damage - 86040
class spell_warl_hand_of_guldan_damage : public SpellScriptLoader
{
public:
    spell_warl_hand_of_guldan_damage() : SpellScriptLoader("spell_warl_hand_of_guldan_damage") { }

    class spell_warl_hand_of_guldan_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_hand_of_guldan_damage_SpellScript);

    public:
        spell_warl_hand_of_guldan_damage_SpellScript()
        {
            soulshards = 1;
        }

    private:

        bool Load() override
        {
            soulshards += GetCaster()->GetPower(POWER_SOUL_SHARDS);
            if (soulshards > 4)
            {
                GetCaster()->SetPower(POWER_SOUL_SHARDS, 1);
                soulshards = 4;

            }
            else
                GetCaster()->SetPower(POWER_SOUL_SHARDS, 0);
            return true;
        }

        uint32 soulshards;

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    uint32 dmg = GetHitDamage();
                    SetHitDamage(dmg*soulshards);

                    if (caster->HasAura(SPELL_WARLOCK_HAND_OF_DOOM))
                        caster->CastSpell(target, SPELL_WARLOCK_DOOM, true);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_hand_of_guldan_damage_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_hand_of_guldan_damage_SpellScript();
    }
};

class spell_warl_metamorphosis_cost : public SpellScriptLoader
{
public:
    spell_warl_metamorphosis_cost() : SpellScriptLoader("spell_warl_metamorphosis_cost") { }

    class spell_warl_metamorphosis_cost_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_metamorphosis_cost_AuraScript);

        void OnTick(const AuraEffect* /* aurEff */)
        {
            if (GetCaster())
            {
                GetCaster()->EnergizeBySpell(GetCaster(), SPELL_WARLOCK_METAMORPHOSIS, -6, POWER_DEMONIC_FURY);
                if (GetCaster()->GetPower(POWER_DEMONIC_FURY) < 0)
                    GetCaster()->RemoveAura(GetAura());
            }

        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_metamorphosis_cost_AuraScript::OnTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_metamorphosis_cost_AuraScript();
    }
};

class spell_warl_molten_core_dot : public SpellScriptLoader
{
public:
    spell_warl_molten_core_dot() : SpellScriptLoader("spell_warl_molten_core_dot") { }

    class spell_warl_molten_core_dot_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_molten_core_dot_AuraScript);

        void OnTick(const AuraEffect* aurEff)
        {
            if (GetCaster())
            {
                if (GetCaster()->HasAura(SPELL_WARLOCK_MOLTEN_CORE_AURA))
                    if (roll_chance_i(8))
                        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_MOLTEN_CORE, true);

                GetCaster()->EnergizeBySpell(GetCaster(), aurEff->GetSpellInfo()->Id, 2, POWER_DEMONIC_FURY);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_molten_core_dot_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_molten_core_dot_AuraScript();
    }
};

class spell_warl_shadow_bulwark : public SpellScriptLoader
{
public:
    spell_warl_shadow_bulwark() : SpellScriptLoader("spell_warl_shadow_bulwark") { }

    class spell_warl_shadow_bulwark_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_shadow_bulwark_AuraScript);

        void CalculateAmount(const AuraEffect*, int32& amount, bool &)
        {
            if (Unit* caster = GetCaster())
                amount = caster->CountPctFromMaxHealth(amount);
        }
        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_shadow_bulwark_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_HEALTH_2);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_shadow_bulwark_AuraScript();
    }
};

class spell_warl_shadowburn : public SpellScriptLoader
{
public:
    spell_warl_shadowburn() : SpellScriptLoader("spell_warl_shadowburn") { }

    class spell_warl_shadowburn_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_shadowburn_AuraScript);

        void HandleRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /* mode */)
        {
            if (GetCaster())
            {
                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode == AURA_REMOVE_BY_DEATH)
                    GetCaster()->SetPower(POWER_SOUL_SHARDS, GetCaster()->GetPower(POWER_SOUL_SHARDS) + 50);
            }
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectApplyFn(spell_warl_shadowburn_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_shadowburn_AuraScript();
    }
};

class spell_warl_twilight_ward_s12 : public SpellScriptLoader
{
public:
    spell_warl_twilight_ward_s12() : SpellScriptLoader("spell_warl_twilight_ward_s12") { }

    class spell_warl_twilight_ward_s12_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_twilight_ward_s12_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (_player->HasAura(SPELL_WARLOCK_ITEM_S12_TIER_4))
                {
                    if (GetSpellInfo()->Id == 6229)
                    {
                        if (_player->HasAura(GetSpellInfo()->Id))
                            _player->RemoveAura(GetSpellInfo()->Id);

                        _player->CastSpell(_player, SPELL_WARLOCK_TWILIGHT_WARD_S12, true);
                    }
                    else if (GetSpellInfo()->Id == 104048)
                    {
                        if (_player->HasAura(GetSpellInfo()->Id))
                            _player->RemoveAura(GetSpellInfo()->Id);

                        _player->CastSpell(_player, SPELL_WARLOCK_TWILIGHT_WARD_METAMORPHOSIS_S12, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_warl_twilight_ward_s12_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_twilight_ward_s12_SpellScript();
    }
};

class spell_warl_void_ray : public SpellScriptLoader
{
public:
    spell_warl_void_ray() : SpellScriptLoader("spell_warl_void_ray") { }

    class spell_warl_void_ray_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_void_ray_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (Aura* corruption = target->GetAura(SPELL_WARLOCK_CORRUPTION, _player->GetGUID()))
                    {
                        corruption->SetDuration(corruption->GetDuration() + 4000);
                        corruption->SetNeedClientUpdateForTargets();
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_warl_void_ray_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_void_ray_SpellScript();
    }
};

// Immolate - 348
class spell_warl_immolate : public SpellScriptLoader
{
public:
    spell_warl_immolate() : SpellScriptLoader("spell_warl_immolate") { }

    class spell_warl_immolate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_immolate_SpellScript);

        void HandleOnHit()
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_WARLOCK_IMMOLATE_DOT, true);
            GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_CHANNEL_DEMONFIRE_ACTIVATOR, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_warl_immolate_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_immolate_SpellScript();
    }
};

// Create Healthstone (Soulwell) - 34130
class spell_warl_create_healthstone_soulwell : public SpellScript
{
    PrepareSpellScript(spell_warl_create_healthstone_soulwell);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOULWELL_CREATE_HEALTHSTONE))
            return false;
        return true;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), 23517, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_create_healthstone_soulwell::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Call Dreadstalkers - 104316
class spell_warl_call_dreadstalkers : public SpellScript
{
    PrepareSpellScript(spell_warl_call_dreadstalkers);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_WARLOCK_CALL_DREADSTALKERS_SUMMON, true);
        caster->CastSpell(caster, SPELL_WARLOCK_CALL_DREADSTALKERS_SUMMON + 1, true);

        if (Aura* aura = caster->GetAura(SPELL_WARLOCK_IMPROVED_DREADSTALKERS))
            for (int i = 0; i < aura->GetSpellEffectInfo(EFFECT_0)->BasePoints; ++i)
                caster->CastSpell(caster, SPELL_WARLOCK_HAND_OF_GULDAN_SUMMON, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_call_dreadstalkers::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//5782 - Fear
class spell_warl_fear : public SpellScriptLoader
{
public:
    spell_warl_fear() : SpellScriptLoader("spell_warl_fear") {}

    class spell_warl_fear_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_fear_SpellScript);

        bool  Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_FEAR))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_FEAR_BUFF))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Unit* target = GetExplTargetUnit();
            if (!target)
                return;

            caster->CastSpell(target, SPELL_WARLOCK_FEAR_BUFF, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_fear_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_fear_SpellScript();
    }
};

//204730 - Fear (effect)
class spell_warl_fear_buff : public SpellScriptLoader
{
public:
    spell_warl_fear_buff() : SpellScriptLoader("spell_warl_fear_buff") {}

    class spell_warl_fear_buff_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_fear_buff_SpellScript);

        bool  Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_FEAR_BUFF))
                return false;
            return true;
        }

        void HandleAfterHit()
        {
            if (Aura* aura = GetHitAura())
            {
                aura->SetMaxDuration(20 * IN_MILLISECONDS);
                aura->SetDuration(20 * IN_MILLISECONDS);
                aura->RefreshDuration();
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_warl_fear_buff_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_fear_buff_SpellScript();
    }
};

class spell_warl_dark_pact : public AuraScript
{
    PrepareAuraScript(spell_warl_dark_pact);

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
        {
            int32 sacrifiedHealth = 0;

            if (Guardian* guardian = caster->GetGuardianPet())
            {
                sacrifiedHealth = guardian->CountPctFromCurHealth(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints);
                guardian->ModifyHealth(-sacrifiedHealth);
            }
            else
            {
                sacrifiedHealth = caster->CountPctFromCurHealth(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints);
                caster->ModifyHealth(-sacrifiedHealth);
            }

            amount = CalculatePct(sacrifiedHealth, aurEff->GetBaseAmount());
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_dark_pact::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

//80240 - Havoc
class spell_warl_havoc : public SpellScriptLoader
{
public:
    spell_warl_havoc() : SpellScriptLoader("spell_warl_havoc") { }

    class spell_warl_havoc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_havoc_AuraScript);

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& procInfo)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Unit* victim = procInfo.GetActionTarget())
            {
                if (Unit* target = procInfo.GetProcTarget())
                {
                    if (victim != target)
                    {
                        if (SpellInfo const* spellInfo = aurEff->GetSpellInfo())
                        {
                            uint32 dmg = procInfo.GetDamageInfo()->GetDamage();
                            SpellNonMeleeDamage spell(caster, target, SPELL_WARLOCK_HAVOC, spellInfo->GetSpellXSpellVisualId(caster), SPELL_SCHOOL_MASK_SHADOW);
                            spell.damage = dmg;
                            spell.cleanDamage = spell.damage;
                            caster->DealSpellDamage(&spell, false);
                            caster->SendSpellNonMeleeDamageLog(&spell);
                        }
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_warl_havoc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_havoc_AuraScript();
    }
};

//146739 - Corruption
class spell_warl_corruption_effect : public AuraScript
{
    PrepareAuraScript(spell_warl_corruption_effect);

    bool  Validate(SpellInfo const* /*spellInfo*/) override
    {
        if(!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_ABSOLUTE_CORRUPTION))
            return false;
        return true;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if(!target || !caster)
            return;

        //If the target is a player, only cast for the time said in ABSOLUTE_CORRUPTION
        if(caster->HasAura(SPELL_WARLOCK_ABSOLUTE_CORRUPTION))
            GetAura()->SetDuration(target->GetTypeId() == TYPEID_PLAYER ? sSpellMgr->GetSpellInfo(SPELL_WARLOCK_ABSOLUTE_CORRUPTION)->GetEffect(EFFECT_0)->BasePoints * IN_MILLISECONDS : 60 * 60 * IN_MILLISECONDS); //If not player, 1 hour
    }

    /*
    Removes the aura if the caster is null, far away or dead.
    */
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!target)
            return;

        if(!caster)
        {
            target->RemoveAura(SPELL_WARLOCK_CORRUPTION_DAMAGE);
            return;
        }

        if(caster->isDead())
            target->RemoveAura(SPELL_WARLOCK_CORRUPTION_DAMAGE);

        if(!caster->IsInRange(target, 0, 80))
            target->RemoveAura(SPELL_WARLOCK_CORRUPTION_DAMAGE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_warl_corruption_effect::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_corruption_effect::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// Rain of Fire - 5740
// AreaTriggerID - 5420
struct at_warl_rain_of_fire : AreaTriggerAI
{
    int32 timeInterval;

    at_warl_rain_of_fire(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    {
        timeInterval = 1000;
    }

    void OnUpdate(uint32 diff) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        // Check if we can handle actions
        timeInterval += diff;
        if (timeInterval < 1000)
            return;

        for (auto obj : at->GetInsideUnits())
            if (Unit* unit = ObjectAccessor::GetUnit(*caster, obj))
                if (caster->IsValidAttackTarget(unit))
                    caster->CastSpell(unit, SPELL_WARLOCK_RAIN_OF_FIRE_DAMAGE, true);

        timeInterval -= 1000;
    }
};

/// npc_demonic_gateway_purple - 59271
class spell_npc_warl_demonic_gateway_purple : public CreatureScript
{
public:
    spell_npc_warl_demonic_gateway_purple() : CreatureScript("spell_npc_warl_demonic_gateway_purple") { }
    enum eNpc
    {
        DELAY_TO_INTERACT = 50
    };
    struct spell_npc_warl_demonic_gateway_purpleAI : public CreatureAI
    {
        spell_npc_warl_demonic_gateway_purpleAI(Creature* p_Creature) : CreatureAI(p_Creature) { Init(); }

        EventMap m_events;
        uint32 ready_to_jump;

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);
            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case DELAY_TO_INTERACT:
                {
                    ready_to_jump = 1;
                    me->SetFlag(UNIT_FIELD_INTERACT_SPELLID, eGatewaySpells::GatewayInteract);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    break;
                }
                }
            }
        }
        void Init()
        {
            me->CastSpell(me, eGatewaySpells::PortalVisual, true);
            ready_to_jump = 0;
            m_events.ScheduleEvent(DELAY_TO_INTERACT, 500);
        }

        void OnSpellClick(Unit* p_Clicker, bool& /*result*/) override
        {
            if (p_Clicker->GetTypeId() != TYPEID_PLAYER)
                return;

            // Demonic Gateway cooldown marker
            if (p_Clicker->HasAura(eGatewaySpells::CooldownMarker))
                return;

            /// Can't use gates in control
            if (p_Clicker->isFeared())
                return;

            Unit* l_Owner = me->GetOwner();
            if (!l_Owner || !l_Owner->ToPlayer())
                return;

            if (Group* l_Group = p_Clicker->ToPlayer()->GetGroup())
            {
                if (l_Owner->ToPlayer()->GetGroup() != l_Group)
                    return;
            }
            else if (l_Owner != p_Clicker)
                return;

            std::list<Creature*> l_GreenGates;
            me->GetCreatureListWithEntryInGrid(l_GreenGates, eGatewayNpc::GreenGate, 75.0f);

            if (l_GreenGates.empty())
                return;


            l_GreenGates.sort([this](const Unit* a, const Unit* b)
            {
                return a->GetDistance(me) < b->GetDistance(me);
            });
            for (auto itr : l_GreenGates)
            {
                p_Clicker->CastSpell(p_Clicker, eGatewaySpells::CooldownMarker, true);

                Unit* l_CurrentGateOwner = itr->GetOwner();

                /// Can't teleport to other players Gates
                if (l_CurrentGateOwner && l_Owner != l_CurrentGateOwner)
                    continue;

                // Init dest coordinates
                float x, y, z;
                itr->GetPosition(x, y, z);
                float speedXY;
                float speedZ = 5;

                speedXY = p_Clicker->GetExactDist2d(x, y) * 10.0f / speedZ;
                p_Clicker->CastSpell(p_Clicker, eGatewaySpells::TeleportVisualPurple, true);
                p_Clicker->GetMotionMaster()->MoveJump(x, y, z, p_Clicker->GetOrientation(), speedXY, speedZ);

                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new spell_npc_warl_demonic_gateway_purpleAI(p_Creature);
    }
};

/// npc_demonic_gateway_green - 59262
class spell_npc_warl_demonic_gateway_green : public CreatureScript
{
public:
    spell_npc_warl_demonic_gateway_green() : CreatureScript("spell_npc_warl_demonic_gateway_green") { }
    enum eNpc
    {
        DELAY_TO_INTERACT = 50
    };
    struct spell_npc_warl_demonic_gateway_greenAI : public CreatureAI
    {
        spell_npc_warl_demonic_gateway_greenAI(Creature* p_Creature) : CreatureAI(p_Creature) { Init(); }

        EventMap m_events;
        uint32 ready_to_jump;

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);
            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case DELAY_TO_INTERACT:
                {
                    ready_to_jump = 1;
                    me->SetFlag(UNIT_FIELD_INTERACT_SPELLID, eGatewaySpells::GatewayInteract);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    break;
                }
                }
            }
        }
        void Init()
        {
            me->CastSpell(me, eGatewaySpells::PortalVisual, true);
            ready_to_jump = 0;
            m_events.ScheduleEvent(DELAY_TO_INTERACT, 500);
        }

        void OnSpellClick(Unit* p_Clicker, bool& /*result*/) override
        {
            if (p_Clicker->GetTypeId() != TYPEID_PLAYER)
                return;

            if (p_Clicker->HasAura(eGatewaySpells::CooldownMarker))
                return;

            /// Can't use gates in control
            if (p_Clicker->isFeared())
                return;

            Unit* l_Owner = me->GetOwner();
            if (!l_Owner || !l_Owner->ToPlayer())
                return;

            if (Group* l_Group = p_Clicker->ToPlayer()->GetGroup())
            {
                if (l_Owner->ToPlayer()->GetGroup() != l_Group)
                    return;
            }
            else if (l_Owner != p_Clicker)
                return;

            std::list<Creature*> l_PurpleGates;
            me->GetCreatureListWithEntryInGrid(l_PurpleGates, eGatewayNpc::PurpleGate, 75.0f);

            if (l_PurpleGates.empty())
                return;

            l_PurpleGates.sort([this](const Unit* a, const Unit* b)
            {
                return a->GetDistance(me) < b->GetDistance(me);
            });

            for (auto itr : l_PurpleGates)
            {
                Unit* l_CurrentGateOwner = itr->GetOwner();

                /// Can't teleport to other players Gates
                if (l_CurrentGateOwner && l_Owner != l_CurrentGateOwner)
                    continue;

                p_Clicker->CastSpell(p_Clicker, eGatewaySpells::CooldownMarker, true);

                // Init dest coordinates
                float x, y, z;
                itr->GetPosition(x, y, z);
                float speedXY;
                float speedZ = 5;

                speedXY = p_Clicker->GetExactDist2d(x, y) * 10.0f / speedZ;
                p_Clicker->CastSpell(p_Clicker, eGatewaySpells::TeleportVisualGreen, true);
                p_Clicker->GetMotionMaster()->MoveJump(x, y, z, p_Clicker->GetOrientation(), speedXY, speedZ);

                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new spell_npc_warl_demonic_gateway_greenAI(p_Creature);
    }
};

enum eCommandDemonSpells
{
    SPELL_IMP_CAUTERIZE_MASTER          = 119899,
    SPELL_VOIDWALKER_SUFFERING          = 17735,
    SPELL_FELHUNTER_SPELL_LOCK          = 19647,
    SPELL_SUCCUBUS_WHIPLASH             = 6360,
    SPELL_FELGUARD_FELSTORM             = 89751,
    SPELL_INFERNAL_METEOR_STRIKE        = 171017,
    SPELL_DOOMGUARD_SHADOW_LOCK         = 171138
};

// Cauterize Master - 119905
class spell_warl_cauterize_master : public SpellScriptLoader
{
public:
    spell_warl_cauterize_master() : SpellScriptLoader("spell_warl_cauterize_master") {}

    class spell_warl_cauterize_master_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_cauterize_master_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_IMP_CAUTERIZE_MASTER))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return;

            /*if (pet->GetEntry() != PET_ENTRY_IMP)
                return;*/

            pet->CastSpell(caster, SPELL_IMP_CAUTERIZE_MASTER, true);
            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 30 * IN_MILLISECONDS);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_cauterize_master_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_warl_cauterize_master_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_cauterize_master_SpellScript();
    }
};

// Suffering - 119907
class spell_warl_suffering : public SpellScriptLoader
{
public:
    spell_warl_suffering() : SpellScriptLoader("spell_warl_suffering") {}

    class spell_warl_suffering_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_suffering_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_VOIDWALKER_SUFFERING))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet || !target)
                return;

            /*if (pet->GetEntry() != PET_ENTRY_VOIDWALKER)
                return;*/

            pet->CastSpell(target, SPELL_VOIDWALKER_SUFFERING, true);
            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 10 * IN_MILLISECONDS);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_suffering_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_warl_suffering_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_suffering_SpellScript();
    }
};

// Spell Lock - 119910
class spell_warl_spell_lock : public SpellScriptLoader
{
public:
    spell_warl_spell_lock() : SpellScriptLoader("spell_warl_spell_lock") {}

    class spell_warl_spell_lock_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_spell_lock_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_FELHUNTER_SPELL_LOCK))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet || !target)
                return;

            /*if (pet->GetEntry() != PET_ENTRY_FELHUNTER)
                return;*/

            pet->CastSpell(target, SPELL_FELHUNTER_SPELL_LOCK, true);
            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 24 * IN_MILLISECONDS);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_spell_lock_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_warl_spell_lock_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_spell_lock_SpellScript();
    }
};

// Whiplash - 119909
class spell_warl_whiplash : public SpellScriptLoader
{
public:
    spell_warl_whiplash() : SpellScriptLoader("spell_warl_whiplash") {}

    class spell_warl_whiplash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_whiplash_SpellScript);

        void HandleHit()
        {
            Unit* caster = GetCaster();
            WorldLocation const* dest = GetExplTargetDest();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet || !dest)
                return;

            /*if (pet->GetEntry() != PET_ENTRY_SUCCUBUS)
                return;*/

            pet->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_SUCCUBUS_WHIPLASH, true);
            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 25 * IN_MILLISECONDS);
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_SUCCUBUS_WHIPLASH))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_whiplash_SpellScript::CheckCast);
            OnCast += SpellCastFn(spell_warl_whiplash_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_whiplash_SpellScript();
    }
};

// Felstorm - 119914
class spell_warl_felstorm : public SpellScriptLoader
{
public:
    spell_warl_felstorm() : SpellScriptLoader("spell_warl_felstorm") {}

    class spell_warl_felstorm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_felstorm_SpellScript);

        void HandleHit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 45 * IN_MILLISECONDS);
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_FELGUARD_FELSTORM))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_felstorm_SpellScript::CheckCast);
            OnCast += SpellCastFn(spell_warl_felstorm_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_felstorm_SpellScript();
    }
};

// Meteor Strike - 171152
class spell_warl_meteor_strike : public SpellScriptLoader
{
public:
    spell_warl_meteor_strike() : SpellScriptLoader("spell_warl_meteor_strike") {}

    class spell_warl_meteor_strike_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_meteor_strike_SpellScript);

        void HandleHit()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return;

            /*if (pet->GetEntry() != PET_ENTRY_INFERNAL)
                return;*/

            pet->CastSpell(pet, SPELL_INFERNAL_METEOR_STRIKE, true);

            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 60 * IN_MILLISECONDS);
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_INFERNAL_METEOR_STRIKE))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_meteor_strike_SpellScript::CheckCast);
            OnCast += SpellCastFn(spell_warl_meteor_strike_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_meteor_strike_SpellScript();
    }
};

// Shadow Lock - 171140
class spell_warl_shadow_lock : public SpellScriptLoader
{
public:
    spell_warl_shadow_lock() : SpellScriptLoader("spell_warl_shadow_lock") {}

    class spell_warl_shadow_lock_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_shadow_lock_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet || !target)
                return;

            /*if (pet->GetEntry() != PET_ENTRY_DOOMGUARD)
                return;*/

            pet->CastSpell(target, SPELL_DOOMGUARD_SHADOW_LOCK, true);

            caster->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, 24 * IN_MILLISECONDS);
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Guardian* pet = caster->GetGuardianPet();
            if (!caster || !pet)
                return SPELL_FAILED_DONT_REPORT;

            if (pet->GetSpellHistory()->HasCooldown(SPELL_DOOMGUARD_SHADOW_LOCK))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_shadow_lock_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_warl_shadow_lock_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_shadow_lock_SpellScript();
    }
};

// Soul Leach appliers - 137046, 137044, 137043
class spell_warl_soul_leach_applier : public SpellScriptLoader
{
public:
    spell_warl_soul_leach_applier() : SpellScriptLoader("spell_warl_soul_leach_applier") {}

    class spell_warl_soul_leach_applier_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_soul_leach_applier_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_WARLOCK_SOUL_LEECH, true);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_warl_soul_leach_applier_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_soul_leach_applier_SpellScript();
    }
};

// Demonskin - 219272
class spell_warl_demonskin : public AuraScript
{
    PrepareAuraScript(spell_warl_demonskin);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 absorb = caster->CountPctFromMaxHealth(1);

        // Add remaining amount if already applied
        if (Aura* aur = caster->GetAura(SPELL_WARLOCK_SOUL_LEECH_ABSORB))
            if (AuraEffect* aurEff = aur->GetEffect(EFFECT_0))
                absorb += aurEff->GetAmount();

        int32 basePointDS = sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONSKIN)->GetEffect(EFFECT_1)->BasePoints;
        int32 threshold = caster->CountPctFromMaxHealth(basePointDS);
        absorb = std::min(absorb, threshold);

        caster->CastCustomSpell(SPELL_WARLOCK_SOUL_LEECH_ABSORB, SPELLVALUE_BASE_POINT0, absorb, caster, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_demonskin::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Cataclysm - 152108
class spell_warl_cataclysm : public SpellScriptLoader
{
public:
    spell_warl_cataclysm() : SpellScriptLoader("spell_warl_cataclysm") {}

    class spell_warl_cataclysm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_cataclysm_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;
            if (!caster->ToPlayer())
                return;

            if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_WARLOCK_DESTRUCTION)
                caster->CastSpell(target, SPELL_WARLOCK_IMMOLATE_DOT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_cataclysm_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_cataclysm_SpellScript();
    }
};

// Channel Demonfire - 196447
class spell_warl_channel_demonfire : public SpellScriptLoader
{
public:
    spell_warl_channel_demonfire() : SpellScriptLoader("spell_warl_channel_demonfire") {}

    class spell_warl_channel_demonfire_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_channel_demonfire_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Unit*> enemies;
            caster->GetAttackableUnitListInRange(enemies, 100.0f);
            enemies.remove_if(Trinity::UnitAuraCheck(false, SPELL_WARLOCK_IMMOLATE_DOT, caster->GetGUID()));
            if (enemies.empty())
                return;

            Unit* target = Trinity::Containers::SelectRandomContainerElement(enemies);
            caster->CastSpell(target, SPELL_WARLOCK_CHANNEL_DEMONFIRE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_channel_demonfire_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_channel_demonfire_AuraScript();
    }
};

// Soul Conduit - 215941
class spell_warl_soul_conduit : public SpellScriptLoader
{
public:
    spell_warl_soul_conduit() : SpellScriptLoader("spell_warl_soul_conduit") {}

    class spell_warl_soul_conduit_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_soul_conduit_AuraScript);

        int32 refund = 0;

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return false;
            if (eventInfo.GetActor() && eventInfo.GetActor() != caster)
                return false;

            if (Spell const* spell = eventInfo.GetProcSpell())
            {
                std::vector<SpellPowerCost> const& costs = spell->GetPowerCost();
                auto costData = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA && cost.Amount > 0; });
                if (costData == costs.end())
                    return false;

                refund = costData->Amount;
                return true;
            }

            return false;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (roll_chance_i(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints))
                caster->CastCustomSpell(SPELL_WARLOCK_SOUL_CONDUIT_REFUND, SPELLVALUE_BASE_POINT0, refund, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_warl_soul_conduit_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_warl_soul_conduit_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_soul_conduit_AuraScript();
    }
};

// Soul Harvest - 196098
class spell_warl_soul_harvest : public SpellScriptLoader
{
public:
    spell_warl_soul_harvest() : SpellScriptLoader("spell_warl_soul_harvest") {}

    class spell_warl_soul_harvest_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_soul_harvest_AuraScript);

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            if (!caster->ToPlayer())
                return;

            std::list<Unit*> enemies;
            caster->GetAttackableUnitListInRange(enemies, 100.0f);
            int32 spellId = 0;
            switch (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID))
            {
                case TALENT_SPEC_WARLOCK_AFFLICTION:
                    spellId = SPELL_WARLOCK_AGONY;
                    break;
                case TALENT_SPEC_WARLOCK_DEMONOLOGY:
                    spellId = SPELL_WARLOCK_DOOM;
                    break;
                case TALENT_SPEC_WARLOCK_DESTRUCTION:
                    spellId = SPELL_WARLOCK_IMMOLATE_DOT;
                    break;
            }
            enemies.remove_if(Trinity::UnitAuraCheck(false, spellId, caster->GetGUID()));
            int32 mod = std::min((int)enemies.size(), 15);
            int32 duration = GetAura()->GetMaxDuration() + 2 * mod * IN_MILLISECONDS;

            GetAura()->SetMaxDuration(duration);
            GetAura()->SetDuration(duration);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_warl_soul_harvest_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_soul_harvest_AuraScript();
    }
};

// Grimoire of Service summons - 111859, 111895, 111896, 111897, 111898
class spell_warl_grimoire_of_service : public SpellScriptLoader
{
public:
    spell_warl_grimoire_of_service() : SpellScriptLoader("spell_warl_grimoire_of_service") {}

    class spell_warl_grimoire_of_service_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_grimoire_of_service_SpellScript);

        enum eServiceSpells
        {
            SPELL_IMP_SINGE_MAGIC               = 89808,
            SPELL_VOIDWALKER_SUFFERING          = 17735,
            SPELL_SUCCUBUS_SEDUCTION            = 6358,
            SPELL_FELHUNTER_SPELL_LOCK          = 19647,
            SPELL_FELGUARD_AXE_TOSS             = 89766
        };

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(eServiceSpells::SPELL_FELGUARD_AXE_TOSS) ||
                !sSpellMgr->GetSpellInfo(eServiceSpells::SPELL_FELHUNTER_SPELL_LOCK) ||
                !sSpellMgr->GetSpellInfo(eServiceSpells::SPELL_IMP_SINGE_MAGIC) ||
                !sSpellMgr->GetSpellInfo(eServiceSpells::SPELL_SUCCUBUS_SEDUCTION) ||
                !sSpellMgr->GetSpellInfo(eServiceSpells::SPELL_VOIDWALKER_SUFFERING))
                return false;
            return true;
        }

        void HandleSummon(Creature* creature)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if (!caster || !creature || !target)
                return;

            switch (GetSpellInfo()->Id)
            {
                case SPELL_WARLOCK_GRIMOIRE_IMP: // Imp
                    creature->CastSpell(caster, eServiceSpells::SPELL_IMP_SINGE_MAGIC, true);
                    break;
                case SPELL_WARLOCK_GRIMOIRE_VOIDWALKER: // Voidwalker
                    creature->CastSpell(target, eServiceSpells::SPELL_VOIDWALKER_SUFFERING, true);
                    break;
                case SPELL_WARLOCK_GRIMOIRE_SUCCUBUS: // Succubus
                    creature->CastSpell(target, eServiceSpells::SPELL_SUCCUBUS_SEDUCTION, true);
                    break;
                case SPELL_WARLOCK_GRIMOIRE_FELHUNTER: // Felhunter
                    creature->CastSpell(target, eServiceSpells::SPELL_FELHUNTER_SPELL_LOCK, true);
                    break;
                case SPELL_WARLOCK_GRIMOIRE_FELGUARD: // Felguard
                    creature->CastSpell(target, eServiceSpells::SPELL_FELGUARD_AXE_TOSS, true);
                    break;
            }
        }

        void Register() override
        {
            OnEffectSummon += SpellOnEffectSummonFn(spell_warl_grimoire_of_service_SpellScript::HandleSummon);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_grimoire_of_service_SpellScript();
    }
};

class ImplosionDamageEvent : public BasicEvent
{
public:
    ImplosionDamageEvent(Unit* caster, Unit* target) : _caster(caster), _target(target) { }

    bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
    {
        if (_caster && _target)
        {
            _caster->CastSpell(_target, SPELL_WARLOCK_IMPLOSION_DAMAGE, true);
            _target->ToCreature()->DisappearAndDie();
        }
        return true;
    }
private:
    Unit* _caster;
    Unit* _target;
};

// Implosion - 196277
class spell_warl_implosion : public SpellScriptLoader
{
public:
    spell_warl_implosion() : SpellScriptLoader("spell_warl_implosion") {}

    class spell_warl_implosion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_implosion_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            /*Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;
            if (Player* player = caster->ToPlayer())
            {
                std::list<Unit*> summons;
                player->GetAllSummons(summons);
                for (Unit* pet : summons)
                {
                    if (pet->GetEntry() == PET_ENTRY_WILD_IMP)
                    {
                        pet->CastStop();
                        pet->CastSpell(target, SPELL_WARLOCK_IMPLOSION_JUMP, true);
                        player->m_Events.AddEvent(new ImplosionDamageEvent(caster, pet), player->m_Events.CalculateTime(1000));
                    }
                }
            }*/
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warl_implosion_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_implosion_SpellScript();
    }
};

// Grimoire of Synergy - 171975
class spell_warl_grimoire_of_synergy : public SpellScriptLoader
{
public:
    spell_warl_grimoire_of_synergy() : SpellScriptLoader("spell_warl_grimoire_of_synergy") {}

    class spell_warl_grimoire_of_synergy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_grimoire_of_synergy_SpellScript);

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            if (Player* player = caster->ToPlayer())
            {
                player->AddAura(GetSpellInfo()->Id, player);
                if (Guardian* pet = player->GetGuardianPet())
                    player->AddAura(GetSpellInfo()->Id, pet);
            }

        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_warl_grimoire_of_synergy_SpellScript::HandleCast);
        }
    };

    class spell_warl_grimoire_of_synergy_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_grimoire_of_synergy_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* actor = eventInfo.GetActor();
            if (!actor)
                return false;
            if (actor->IsPet() || actor->IsGuardian())
            {
                Unit* owner = actor->GetOwner();
                if (!owner)
                    return false;
                if (roll_chance_i(10))
                    owner->CastSpell(owner, SPELL_WARLOCK_GRIMOIRE_OF_SYNERGY_BUFF, true);
                return true;
            }
            if (Player* player = actor->ToPlayer())
            {
                Guardian* guardian = player->GetGuardianPet();
                if (!guardian)
                    return false;
                if (roll_chance_i(10))
                    player->CastSpell(guardian, SPELL_WARLOCK_GRIMOIRE_OF_SYNERGY_BUFF, true);
                return true;
            }
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_warl_grimoire_of_synergy_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_grimoire_of_synergy_AuraScript();
    }

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_grimoire_of_synergy_SpellScript();
    }
};

// Eye Laser - 205231
class spell_warl_eye_laser : public SpellScriptLoader
{
public:
    spell_warl_eye_laser() : SpellScriptLoader("spell_warl_eye_laser") {}

    class spell_warl_eye_laser_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_eye_laser_SpellScript);

        void HandleTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetOriginalCaster();
            if (!caster)
                return;
            targets.clear();
            Trinity::AllWorldObjectsInRange check(caster, 100.f);
            Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> search(caster, targets, check);
            Cell::VisitAllObjects(caster, search, 100.f);
            targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_WARLOCK_DOOM, caster->GetGUID()));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_eye_laser_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_eye_laser_SpellScript();
    }
};

// Darkglare - 103673
class npc_pet_warlock_darkglare : public CreatureScript
{
public:
    npc_pet_warlock_darkglare() : CreatureScript("npc_pet_warlock_darkglare") {}

    struct npc_pet_warlock_darkglare_PetAI : public PetAI
    {
        npc_pet_warlock_darkglare_PetAI(Creature* creature) : PetAI(creature) {}

        void UpdateAI(uint32 /*diff*/) override
        {
            Unit* owner = me->GetOwner();
            if (!owner)
                return;

            std::list<Unit*> targets;
            owner->GetAttackableUnitListInRange(targets, 100.0f);
            targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_WARLOCK_DOOM, owner->GetGUID()));
            if (!targets.empty())
                me->CastSpell(targets.front(), SPELL_WARLOCK_EYE_LASER, false, nullptr, nullptr, owner->GetGUID());
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pet_warlock_darkglare_PetAI(creature);
    }
};

// Wild Imp - 99739
struct npc_pet_warlock_wild_imp : public PetAI
{
    npc_pet_warlock_wild_imp(Creature* creature) : PetAI(creature) {}

    void UpdateAI(uint32 /*diff*/) override
    {
        Unit* owner = me->GetOwner();
        if (!owner)
            return;

        Unit* target = GetTarget();
        ObjectGuid newtargetGUID = owner->GetTarget();
        if (newtargetGUID.IsEmpty() || newtargetGUID == _targetGUID)
        {
            CastSpellOnTarget(owner, target);
            return;
        }

        if (Unit* newTarget = ObjectAccessor::GetUnit(*me, newtargetGUID))
            if (target != newTarget && me->IsValidAttackTarget(newTarget))
                target = newTarget;

        CastSpellOnTarget(owner, target);
    }

private:
    Unit* GetTarget() const
    {
        return ObjectAccessor::GetUnit(*me, _targetGUID);
    }

    void CastSpellOnTarget(Unit* owner, Unit* target)
    {
        if (target && me->IsValidAttackTarget(target))
        {
            _targetGUID = target->GetGUID();
            me->CastSpell(target, SPELL_WARLOCK_FEL_FIREBOLT, false, nullptr, nullptr, owner->GetGUID());
        }
    }

    ObjectGuid _targetGUID;
};

// Demonic Calling - 205145
class spell_warl_demonic_calling : public SpellScriptLoader
{
public:
    spell_warl_demonic_calling() : SpellScriptLoader("spell_warl_demonic_calling") {}

    class spell_warl_demonic_calling_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_demonic_calling_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_CALLING_TRIGGER))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return false;
            if (eventInfo.GetSpellInfo() && (eventInfo.GetSpellInfo()->Id == SPELL_WARLOCK_DEMONBOLT || eventInfo.GetSpellInfo()->Id == SPELL_WARLOCK_SHADOW_BOLT) && roll_chance_i(20))
                caster->CastSpell(caster, SPELL_WARLOCK_DEMONIC_CALLING_TRIGGER, true);
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_warl_demonic_calling_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_demonic_calling_AuraScript();
    }
};

// Chaotic Energies - 77220
class spell_warl_chaotic_energies : public SpellScriptLoader
{
public:
    spell_warl_chaotic_energies() : SpellScriptLoader("spell_warl_chaotic_energies") {}

    class spell_warl_chaotic_energies_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_chaotic_energies_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            int32 absorb = 0;
            if (Aura* aur = GetAura())
                if (AuraEffect* absorbEffect = aur->GetEffect(EFFECT_1))
                    absorb = std::rand() % absorbEffect->GetAmount() + 1;

            aurEff->SetAmount(-1);
            int32 damage = dmgInfo.GetDamage();
            absorbAmount = ApplyPct(damage, absorb);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_chaotic_energies_AuraScript::CalcAmount, EFFECT_2, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_warl_chaotic_energies_AuraScript::HandleAbsorb, EFFECT_2);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_chaotic_energies_AuraScript();
    }
};

// Eradication - 196414
class spell_warl_eradication : public SpellScriptLoader
{
public:
    spell_warl_eradication() : SpellScriptLoader("spell_warl_eradication") {}

    class spell_warl_eradication_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_eradication_AuraScript);

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_warl_eradication_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_eradication_AuraScript();
    }
};

// 205179
class aura_warl_phantomatic_singularity : public AuraScript
{
    PrepareAuraScript(aura_warl_phantomatic_singularity);

    void OnTick(const AuraEffect* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget()->GetPosition(), SPELL_WARLOCK_PHANTOMATIC_SINGULARITY_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_warl_phantomatic_singularity::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Grimoire of Service - 108501
class spell_warl_grimoire_of_service_aura : public AuraScript
{
    PrepareAuraScript(spell_warl_grimoire_of_service_aura);

    void Handlearn(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->LearnSpell(SPELL_WARLOCK_GRIMOIRE_IMP, false);
            player->LearnSpell(SPELL_WARLOCK_GRIMOIRE_VOIDWALKER, false);
            player->LearnSpell(SPELL_WARLOCK_GRIMOIRE_SUCCUBUS, false);
            player->LearnSpell(SPELL_WARLOCK_GRIMOIRE_FELHUNTER, false);
            if (player->GetSpecializationId() == TALENT_SPEC_WARLOCK_DEMONOLOGY)
                player->LearnSpell(SPELL_WARLOCK_GRIMOIRE_FELGUARD, false);
        }
    }
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->RemoveSpell(SPELL_WARLOCK_GRIMOIRE_IMP, false, false);
            player->RemoveSpell(SPELL_WARLOCK_GRIMOIRE_VOIDWALKER, false, false);
            player->RemoveSpell(SPELL_WARLOCK_GRIMOIRE_SUCCUBUS, false, false);
            player->RemoveSpell(SPELL_WARLOCK_GRIMOIRE_FELHUNTER, false, false);
            player->RemoveSpell(SPELL_WARLOCK_GRIMOIRE_FELGUARD, false, false);
        }
    }
    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_warl_grimoire_of_service_aura::Handlearn, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectApplyFn(spell_warl_grimoire_of_service_aura::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Incinerate - 29722
class spell_warl_incinerate : public SpellScript
{
    PrepareSpellScript(spell_warl_incinerate);

    void HandleOnHitMainTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->ModifyPower(POWER_SOUL_SHARDS, 20);
    }

    void HandleOnHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (!GetCaster()->HasAura(SPELL_WARLOCK_FIRE_AND_BRIMSTONE))
                if (target != GetExplTargetUnit())
                    PreventHitDamage();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_incinerate::HandleOnHitMainTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_warl_incinerate::HandleOnHitTarget, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_warlock_spell_scripts()
{
    RegisterAuraScript(spell_warl_demonskin);
    RegisterAuraScript(spell_warl_doom);
    RegisterSpellScript(spell_warl_banish);
    RegisterSpellAndAuraScriptPair(spell_warl_burning_rush, aura_warl_burning_rush);
    RegisterSpellScript(spell_warl_call_dreadstalkers);
    RegisterSpellScript(spell_warl_chaos_bolt);
    RegisterSpellScript(spell_warl_conflagrate);
    RegisterSpellScript(spell_warl_conflagrate_aura);
    RegisterAuraScript(spell_warl_corruption_effect);
    RegisterSpellScript(spell_warl_create_healthstone);
    RegisterSpellScript(spell_warl_create_healthstone_soulwell);
    RegisterAuraScript(spell_warl_dark_pact);
    RegisterAuraScript(spell_warl_dark_regeneration);
    RegisterSpellScript(spell_warl_demonbolt);
    RegisterSpellScript(spell_warl_demonic_call);
    RegisterAuraScript(spell_warl_demonic_circle_summon);
    RegisterAuraScript(spell_warl_demonic_circle_teleport);
    RegisterSpellScript(spell_warl_demonic_empowerment);
    RegisterSpellScript(spell_warl_demonic_gateway);
    RegisterSpellScript(spell_warl_devour_magic);
    new spell_warl_drain_soul();
    new spell_warl_fear();
    new spell_warl_fear_buff();
    new spell_warl_glyph_of_soulwell();
    new spell_warl_hand_of_guldan();
    new spell_warl_hand_of_guldan_damage();
    RegisterAuraScript(aura_warl_haunt);
    new spell_warl_havoc();
    RegisterAuraScript(spell_warl_health_funnel);
    RegisterSpellScript(spell_warl_healthstone_heal);
    new spell_warl_immolate();
    RegisterAuraScript(spell_warl_immolate_aura);
    new spell_warl_life_tap();
    new spell_warl_metamorphosis_cost();
    new spell_warl_molten_core_dot();
    RegisterSpellAndAuraScriptPair(spell_warl_seed_of_corruption, aura_warl_seed_of_corruption);
    RegisterSpellScript(spell_warl_seed_of_corruption_damage);
    RegisterSpellScript(spell_warl_shadow_bolt);
    new spell_warl_shadow_bulwark();
    RegisterAuraScript(spell_warl_shadow_ward);
    new spell_warl_shadowburn();
    new spell_warl_soul_leach_applier();
    RegisterAuraScript(spell_warl_soul_leech_aura);
    RegisterSpellScript(spell_warl_soul_swap);
    new spell_warl_soul_swap_dot_marker();
    new spell_warl_soul_swap_exhale();
    new spell_warl_soul_swap_override();
    new spell_warl_soulshatter();
    new spell_warl_twilight_ward_s12();
    RegisterSpellScript(spell_warl_unstable_affliction);
    RegisterAuraScript(aura_warl_unstable_affliction);
    new spell_warl_void_ray();
    new spell_warlock_agony();
    new spell_warl_cauterize_master();
    new spell_warl_suffering();
    new spell_warl_whiplash();
    new spell_warl_spell_lock();
    new spell_warl_felstorm();
    RegisterSpellScript(spell_warl_demonwrath);
    RegisterAuraScript(spell_warl_demonwrath_periodic);
    new spell_warl_meteor_strike();
    new spell_warl_shadow_lock();
    new spell_warl_cataclysm();
    RegisterAuraScript(spell_warl_immolate_dot);
    new spell_warl_channel_demonfire();
    new spell_warl_soul_conduit();
    new spell_warl_soul_harvest();
    new spell_warl_grimoire_of_service();
    new spell_warl_implosion();
    new spell_warl_grimoire_of_synergy();
    new spell_warl_eye_laser();
    new spell_warl_demonic_calling();
    new spell_warl_chaotic_energies();
    new spell_warl_eradication();
    RegisterAuraScript(aura_warl_phantomatic_singularity);
    RegisterAuraScript(spell_warl_grimoire_of_service_aura);
    RegisterSpellScript(spell_warl_incinerate);

    ///AreaTrigger scripts
    RegisterAreaTriggerAI(at_warl_rain_of_fire);

    ///NPC scripts
    new spell_npc_warl_demonic_gateway_green();
    new spell_npc_warl_demonic_gateway_purple();
    new npc_pet_warlock_darkglare();
    RegisterCreatureAI(npc_pet_warlock_wild_imp);
}
