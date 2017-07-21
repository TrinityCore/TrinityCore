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

#include "PlayerAI.h"
#include "Creature.h"
#include "Item.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"

enum Spells
{
    /* Generic */
    SPELL_AUTO_SHOT         =    75,
    SPELL_SHOOT             =  3018,
    SPELL_THROW             =  2764,
    SPELL_SHOOT_WAND        =  5019,

    /* Warrior - Generic */
    SPELL_BATTLE_STANCE     =  2457,
    SPELL_BERSERKER_STANCE  =  2458,
    SPELL_DEFENSIVE_STANCE  =    71,
    SPELL_CHARGE            = 11578,
    SPELL_INTERCEPT         = 20252,
    SPELL_ENRAGED_REGEN     = 55694,
    SPELL_INTIMIDATING_SHOUT=  5246,
    SPELL_PUMMEL            =  6552,
    SPELL_SHIELD_BASH       =    72,
    SPELL_BLOODRAGE         =  2687,

    /* Warrior - Arms */
    SPELL_SWEEPING_STRIKES  = 12328,
    SPELL_MORTAL_STRIKE     = 12294,
    SPELL_BLADESTORM        = 46924,
    SPELL_REND              = 47465,
    SPELL_RETALIATION       = 20230,
    SPELL_SHATTERING_THROW  = 64382,
    SPELL_THUNDER_CLAP      = 47502,

    /* Warrior - Fury */
    SPELL_DEATH_WISH        = 12292,
    SPELL_BLOODTHIRST       = 23881,
    PASSIVE_TITANS_GRIP     = 46917,
    SPELL_DEMO_SHOUT        = 47437,
    SPELL_EXECUTE           = 47471,
    SPELL_HEROIC_FURY       = 60970,
    SPELL_RECKLESSNESS      =  1719,
    SPELL_PIERCING_HOWL     = 12323,

    /* Warrior - Protection */
    SPELL_VIGILANCE         = 50720,
    SPELL_DEVASTATE         = 20243,
    SPELL_SHOCKWAVE         = 46968,
    SPELL_CONCUSSION_BLOW   = 12809,
    SPELL_DISARM            =   676,
    SPELL_LAST_STAND        = 12975,
    SPELL_SHIELD_BLOCK      =  2565,
    SPELL_SHIELD_SLAM       = 47488,
    SPELL_SHIELD_WALL       =   871,
    SPELL_SPELL_REFLECTION  = 23920,

    /* Paladin - Generic */
    SPELL_PAL_AURA_MASTERY      = 31821,
    SPELL_LAY_ON_HANDS          = 48788,
    SPELL_BLESSING_OF_MIGHT     = 48932,
    SPELL_AVENGING_WRATH        = 31884,
    SPELL_DIVINE_PROTECTION     =   498,
    SPELL_DIVINE_SHIELD         =   642,
    SPELL_HAMMER_OF_JUSTICE     = 10308,
    SPELL_HAND_OF_FREEDOM       =  1044,
    SPELL_HAND_OF_PROTECTION    = 10278,
    SPELL_HAND_OF_SACRIFICE     =  6940,

    /* Paladin - Holy*/
    PASSIVE_ILLUMINATION        = 20215,
    SPELL_HOLY_SHOCK            = 20473,
    SPELL_BEACON_OF_LIGHT       = 53563,
    SPELL_CONSECRATION          = 48819,
    SPELL_FLASH_OF_LIGHT        = 48785,
    SPELL_HOLY_LIGHT            = 48782,
    SPELL_DIVINE_FAVOR          = 20216,
    SPELL_DIVINE_ILLUMINATION   = 31842,

    /* Paladin - Protection */
    SPELL_BLESS_OF_SANC         = 20911,
    SPELL_HOLY_SHIELD           = 20925,
    SPELL_AVENGERS_SHIELD       = 48827,
    SPELL_DIVINE_SACRIFICE      = 64205,
    SPELL_HAMMER_OF_RIGHTEOUS   = 53595,
    SPELL_RIGHTEOUS_FURY        = 25780,
    SPELL_SHIELD_OF_RIGHTEOUS   = 61411,

    /* Paladin - Retribution */
    SPELL_SEAL_OF_COMMAND       = 20375,
    SPELL_CRUSADER_STRIKE       = 35395,
    SPELL_DIVINE_STORM          = 53385,
    SPELL_JUDGEMENT             = 20271,
    SPELL_HAMMER_OF_WRATH       = 48806,

    /* Hunter - Generic */
    SPELL_DETERRENCE        = 19263,
    SPELL_EXPLOSIVE_TRAP    = 49067,
    SPELL_FREEZING_ARROW    = 60192,
    SPELL_RAPID_FIRE        =  3045,
    SPELL_KILL_SHOT         = 61006,
    SPELL_MULTI_SHOT        = 49048,
    SPELL_VIPER_STING       =  3034,

    /* Hunter - Beast Mastery */
    SPELL_BESTIAL_WRATH     = 19574,
    PASSIVE_BEAST_WITHIN    = 34692,
    PASSIVE_BEAST_MASTERY   = 53270,

    /* Hunter - Marksmanship */
    SPELL_AIMED_SHOT        = 19434,
    PASSIVE_TRUESHOT_AURA   = 19506,
    SPELL_CHIMERA_SHOT      = 53209,
    SPELL_ARCANE_SHOT       = 49045,
    SPELL_STEADY_SHOT       = 49052,
    SPELL_READINESS         = 23989,
    SPELL_SILENCING_SHOT    = 34490,

    /* Hunter - Survival */
    PASSIVE_LOCK_AND_LOAD   = 56344,
    SPELL_WYVERN_STING      = 19386,
    SPELL_EXPLOSIVE_SHOT    = 53301,
    SPELL_BLACK_ARROW       =  3674,

    /* Rogue - Generic */
    SPELL_DISMANTLE         = 51722,
    SPELL_EVASION           = 26669,
    SPELL_KICK              =  1766,
    SPELL_VANISH            = 26889,
    SPELL_BLIND             =  2094,
    SPELL_CLOAK_OF_SHADOWS  = 31224,

    /* Rogue - Assassination */
    SPELL_COLD_BLOOD        = 14177,
    SPELL_MUTILATE          =  1329,
    SPELL_HUNGER_FOR_BLOOD  = 51662,
    SPELL_ENVENOM           = 57993,

    /* Rogue - Combat */
    SPELL_SINISTER_STRIKE   = 48637,
    SPELL_BLADE_FLURRY      = 13877,
    SPELL_ADRENALINE_RUSH   = 13750,
    SPELL_KILLING_SPREE     = 51690,
    SPELL_EVISCERATE        = 48668,

    /* Rogue - Sublety */
    SPELL_HEMORRHAGE        = 16511,
    SPELL_PREMEDITATION     = 14183,
    SPELL_SHADOW_DANCE      = 51713,
    SPELL_PREPARATION       = 14185,
    SPELL_SHADOWSTEP        = 36554,

    /* Priest - Generic */
    SPELL_FEAR_WARD         =  6346,
    SPELL_POWER_WORD_FORT   = 48161,
    SPELL_DIVINE_SPIRIT     = 48073,
    SPELL_SHADOW_PROTECTION = 48169,
    SPELL_DIVINE_HYMN       = 64843,
    SPELL_HYMN_OF_HOPE      = 64901,
    SPELL_SHADOW_WORD_DEATH = 48158,
    SPELL_PSYCHIC_SCREAM    = 10890,

    /* Priest - Discipline */
    PASSIVE_SOUL_WARDING      = 63574,
    SPELL_POWER_INFUSION      = 10060,
    SPELL_PENANCE             = 47540,
    SPELL_PAIN_SUPPRESSION    = 33206,
    SPELL_INNER_FOCUS         = 14751,
    SPELL_POWER_WORD_SHIELD   = 48066,

    /* Priest - Holy */
    PASSIVE_SPIRIT_REDEMPTION = 20711,
    SPELL_DESPERATE_PRAYER    = 19236,
    SPELL_GUARDIAN_SPIRIT     = 47788,
    SPELL_FLASH_HEAL          = 48071,
    SPELL_RENEW               = 48068,

    /* Priest - Shadow */
    SPELL_VAMPIRIC_EMBRACE    = 15286,
    SPELL_SHADOWFORM          = 15473,
    SPELL_VAMPIRIC_TOUCH      = 34914,
    SPELL_MIND_FLAY           = 15407,
    SPELL_MIND_BLAST          = 48127,
    SPELL_SHADOW_WORD_PAIN    = 48125,
    SPELL_DEVOURING_PLAGUE    = 48300,
    SPELL_DISPERSION          = 47585,

    /* Death Knight - Generic */
    SPELL_DEATH_GRIP        = 49576,
    SPELL_STRANGULATE       = 47476,
    SPELL_EMPOWER_RUNE_WEAP = 47568,
    SPELL_ICEBORN_FORTITUDE = 48792,
    SPELL_ANTI_MAGIC_SHELL  = 48707,
    SPELL_DEATH_COIL_DK     = 49895,
    SPELL_MIND_FREEZE       = 47528,
    SPELL_ICY_TOUCH         = 49909,
    AURA_FROST_FEVER        = 55095,
    SPELL_PLAGUE_STRIKE     = 49921,
    AURA_BLOOD_PLAGUE       = 55078,
    SPELL_PESTILENCE        = 50842,

    /* Death Knight - Blood */
    SPELL_RUNE_TAP          = 48982,
    SPELL_HYSTERIA          = 49016,
    SPELL_HEART_STRIKE      = 55050,
    SPELL_DEATH_STRIKE      = 49924,
    SPELL_BLOOD_STRIKE      = 49930,
    SPELL_MARK_OF_BLOOD     = 49005,
    SPELL_VAMPIRIC_BLOOD    = 55233,

    /* Death Knight - Frost */
    PASSIVE_ICY_TALONS      = 50887,
    SPELL_FROST_STRIKE      = 49143,
    SPELL_HOWLING_BLAST     = 49184,
    SPELL_UNBREAKABLE_ARMOR = 51271,
    SPELL_OBLITERATE        = 51425,
    SPELL_DEATHCHILL        = 49796,

    /* Death Knight - Unholy */
    PASSIVE_UNHOLY_BLIGHT   = 49194,
    PASSIVE_MASTER_OF_GHOUL = 52143,
    SPELL_SCOURGE_STRIKE    = 55090,
    SPELL_DEATH_AND_DECAY   = 49938,
    SPELL_ANTI_MAGIC_ZONE   = 51052,
    SPELL_SUMMON_GARGOYLE   = 49206,

    /* Shaman - Generic */
    SPELL_HEROISM           = 32182,
    SPELL_BLOODLUST         =  2825,
    SPELL_GROUNDING_TOTEM   =  8177,

    /* Shaman - Elemental*/
    PASSIVE_ELEMENTAL_FOCUS = 16164,
    SPELL_TOTEM_OF_WRATH    = 30706,
    SPELL_THUNDERSTORM      = 51490,
    SPELL_LIGHTNING_BOLT    = 49238,
    SPELL_EARTH_SHOCK       = 49231,
    SPELL_FLAME_SHOCK       = 49233,
    SPELL_LAVA_BURST        = 60043,
    SPELL_CHAIN_LIGHTNING   = 49271,
    SPELL_ELEMENTAL_MASTERY = 16166,

    /* Shaman - Enhancement */
    PASSIVE_SPIRIT_WEAPONS  = 16268,
    SPELL_LAVA_LASH         = 60103,
    SPELL_FERAL_SPIRIT      = 51533,
    AURA_MAELSTROM_WEAPON   = 53817,
    SPELL_STORMSTRIKE       = 17364,
    SPELL_SHAMANISTIC_RAGE  = 30823,

    /* Shaman - Restoration*/
    SPELL_SHA_NATURE_SWIFT  =   591,
    SPELL_MANA_TIDE_TOTEM   =   590,
    SPELL_EARTH_SHIELD      = 49284,
    SPELL_RIPTIDE           = 61295,
    SPELL_HEALING_WAVE      = 49273,
    SPELL_LESSER_HEAL_WAVE  = 49276,
    SPELL_TIDAL_FORCE       = 55198,

    /* Mage - Generic */
    SPELL_DAMPEN_MAGIC      = 43015,
    SPELL_EVOCATION         = 12051,
    SPELL_MANA_SHIELD       = 43020,
    SPELL_MIRROR_IMAGE      = 55342,
    SPELL_SPELLSTEAL        = 30449,
    SPELL_COUNTERSPELL      =  2139,
    SPELL_ICE_BLOCK         = 45438,

    /* Mage - Arcane */
    SPELL_FOCUS_MAGIC       = 54646,
    SPELL_ARCANE_POWER      = 12042,
    SPELL_ARCANE_BARRAGE    = 44425,
    SPELL_ARCANE_BLAST      = 42897,
    AURA_ARCANE_BLAST       = 36032,
    SPELL_ARCANE_MISSILES   = 42846,
    SPELL_PRESENCE_OF_MIND  = 12043,

    /* Mage - Fire */
    SPELL_PYROBLAST         = 11366,
    SPELL_COMBUSTION        = 11129,
    SPELL_LIVING_BOMB       = 44457,
    SPELL_FIREBALL          = 42833,
    SPELL_FIRE_BLAST        = 42873,
    SPELL_DRAGONS_BREATH    = 31661,
    SPELL_BLAST_WAVE        = 11113,

    /* Mage - Frost */
    SPELL_ICY_VEINS         = 12472,
    SPELL_ICE_BARRIER       = 11426,
    SPELL_DEEP_FREEZE       = 44572,
    SPELL_FROST_NOVA        = 42917,
    SPELL_FROSTBOLT         = 42842,
    SPELL_COLD_SNAP         = 11958,
    SPELL_ICE_LANCE         = 42914,

    /* Warlock - Generic */
    SPELL_FEAR                 =  6215,
    SPELL_HOWL_OF_TERROR       = 17928,
    SPELL_CORRUPTION           = 47813,
    SPELL_DEATH_COIL_W         = 47860,
    SPELL_SHADOW_BOLT          = 47809,
    SPELL_INCINERATE           = 47838,
    SPELL_IMMOLATE             = 47811,
    SPELL_SEED_OF_CORRUPTION   = 47836,

    /* Warlock - Affliction */
    PASSIVE_SIPHON_LIFE        = 63108,
    SPELL_UNSTABLE_AFFLICTION  = 30108,
    SPELL_HAUNT                = 48181,
    SPELL_CURSE_OF_AGONY       = 47864,
    SPELL_DRAIN_SOUL           = 47855,

    /* Warlock - Demonology */
    SPELL_SOUL_LINK            = 19028,
    SPELL_DEMONIC_EMPOWERMENT  = 47193,
    SPELL_METAMORPHOSIS        = 59672,
    SPELL_IMMOLATION_AURA      = 50589,
    SPELL_DEMON_CHARGE         = 54785,
    AURA_DECIMATION            = 63167,
    AURA_MOLTEN_CORE           = 71165,
    SPELL_SOUL_FIRE            = 47825,

    /* Warlock - Destruction */
    SPELL_SHADOWBURN           = 17877,
    SPELL_CONFLAGRATE          = 17962,
    SPELL_CHAOS_BOLT           = 50796,
    SPELL_SHADOWFURY           = 47847,

    /* Druid - Generic */
    SPELL_BARKSKIN             = 22812,
    SPELL_INNERVATE            = 29166,

    /* Druid - Balance */
    SPELL_INSECT_SWARM        =  5570,
    SPELL_MOONKIN_FORM        = 24858,
    SPELL_STARFALL            = 48505,
    SPELL_TYPHOON             = 61384,
    AURA_ECLIPSE_LUNAR        = 48518,
    SPELL_MOONFIRE            = 48463,
    SPELL_STARFIRE            = 48465,
    SPELL_WRATH               = 48461,

    /* Druid - Feral */
    SPELL_CAT_FORM            =   768,
    SPELL_SURVIVAL_INSTINCTS  = 61336,
    SPELL_MANGLE              = 33917,
    SPELL_BERSERK             = 50334,
    SPELL_MANGLE_CAT          = 48566,
    SPELL_FERAL_CHARGE_CAT    = 49376,
    SPELL_RAKE                = 48574,
    SPELL_RIP                 = 49800,
    SPELL_SAVAGE_ROAR         = 52610,
    SPELL_TIGER_FURY          = 50213,
    SPELL_CLAW                = 48570,
    SPELL_DASH                = 33357,
    SPELL_MAIM                = 49802,

    /* Druid - Restoration */
    SPELL_SWIFTMEND           = 18562,
    SPELL_TREE_OF_LIFE        = 33891,
    SPELL_WILD_GROWTH         = 48438,
    SPELL_NATURE_SWIFTNESS    = 17116,
    SPELL_TRANQUILITY         = 48447,
    SPELL_NOURISH             = 50464,
    SPELL_HEALING_TOUCH       = 48378,
    SPELL_REJUVENATION        = 48441,
    SPELL_REGROWTH            = 48443,
    SPELL_LIFEBLOOM           = 48451
};

PlayerAI::PlayerAI(Player* player) : UnitAI(player), me(player),
    _selfSpec(player->GetPrimarySpecialization()),
    _isSelfHealer(PlayerAI::IsPlayerHealer(player)),
    _isSelfRangedAttacker(PlayerAI::IsPlayerRangedAttacker(player))
{
}

Creature* PlayerAI::GetCharmer() const
{
    if (me->GetCharmerGUID().IsCreature())
        return ObjectAccessor::GetCreature(*me, me->GetCharmerGUID());
    return nullptr;
}

uint16 PlayerAI::GetSpec(Player const* who /*= nullptr*/) const
{
    return (!who || who == me) ? _selfSpec : who->GetPrimarySpecialization();
}

bool PlayerAI::IsPlayerHealer(Player const* who)
{
    if (!who)
        return false;

    switch (who->getClass())
    {
        case CLASS_WARRIOR:
        case CLASS_HUNTER:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        case CLASS_DEMON_HUNTER:
        default:
            return false;
        case CLASS_PALADIN:
            return who->GetPrimarySpecialization() == TALENT_SPEC_PALADIN_HOLY;
        case CLASS_PRIEST:
            return who->GetPrimarySpecialization() == TALENT_SPEC_PRIEST_DISCIPLINE || who->GetPrimarySpecialization() == TALENT_SPEC_PRIEST_HOLY;
        case CLASS_SHAMAN:
            return who->GetPrimarySpecialization() == TALENT_SPEC_SHAMAN_RESTORATION;
        case CLASS_MONK:
            return who->GetPrimarySpecialization() == TALENT_SPEC_MONK_MISTWEAVER;
        case CLASS_DRUID:
            return who->GetPrimarySpecialization() == TALENT_SPEC_DRUID_RESTORATION;
    }
}

bool PlayerAI::IsPlayerRangedAttacker(Player const* who)
{
    if (!who)
        return false;

    switch (who->getClass())
    {
        case CLASS_WARRIOR:
        case CLASS_PALADIN:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        default:
            return false;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            return true;
        case CLASS_HUNTER:
        {
            // check if we have a ranged weapon equipped
            Item const* rangedSlot = who->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (ItemTemplate const* rangedTemplate = rangedSlot ? rangedSlot->GetTemplate() : nullptr)
                if ((1 << rangedTemplate->GetSubClass()) & ITEM_SUBCLASS_MASK_WEAPON_RANGED)
                    return true;
            return false;
        }
        case CLASS_PRIEST:
            return who->GetPrimarySpecialization() == TALENT_SPEC_PRIEST_SHADOW;
        case CLASS_SHAMAN:
            return who->GetPrimarySpecialization() == TALENT_SPEC_SHAMAN_ELEMENTAL;
        case CLASS_DRUID:
            return who->GetPrimarySpecialization() == TALENT_SPEC_DRUID_BALANCE;
    }
}

PlayerAI::TargetedSpell PlayerAI::VerifySpellCast(uint32 spellId, Unit* target)
{
    // Find highest spell rank that we know
    uint32 knownRank, nextRank;
    if (me->HasSpell(spellId))
    {
        // this will save us some lookups if the player has the highest rank (expected case)
        knownRank = spellId;
        nextRank = sSpellMgr->GetNextSpellInChain(spellId);
    }
    else
    {
        knownRank = 0;
        nextRank = sSpellMgr->GetFirstSpellInChain(spellId);
    }

    while (nextRank && me->HasSpell(nextRank))
    {
        knownRank = nextRank;
        nextRank = sSpellMgr->GetNextSpellInChain(knownRank);
    }

    if (!knownRank)
        return {};

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(knownRank, me->GetMap()->GetDifficultyID());
    if (!spellInfo)
        return {};

    if (me->GetSpellHistory()->HasGlobalCooldown(spellInfo))
        return {};

    Spell* spell = new Spell(me, spellInfo, TRIGGERED_NONE);
    if (spell->CanAutoCast(target))
        return{ spell, target };

    delete spell;
    return {};
}

PlayerAI::TargetedSpell PlayerAI::VerifySpellCast(uint32 spellId, SpellTarget target)
{
    Unit* pTarget = nullptr;
    switch (target)
    {
        case TARGET_NONE:
            break;
        case TARGET_VICTIM:
            pTarget = me->GetVictim();
            if (!pTarget)
                return {};
            break;
        case TARGET_CHARMER:
            pTarget = me->GetCharmer();
            if (!pTarget)
                return {};
            break;
        case TARGET_SELF:
            pTarget = me;
            break;
    }

    return VerifySpellCast(spellId, pTarget);
}

PlayerAI::TargetedSpell PlayerAI::SelectSpellCast(PossibleSpellVector& spells)
{
    if (spells.empty())
        return{};

    uint32 totalWeights = 0;
    for (PossibleSpell const& wSpell : spells)
        totalWeights += wSpell.second;

    TargetedSpell selected;
    uint32 randNum = urand(0, totalWeights - 1);
    for (PossibleSpell const& wSpell : spells)
    {
        if (selected)
        {
            delete wSpell.first.first;
            continue;
        }

        if (randNum < wSpell.second)
            selected = wSpell.first;
        else
        {
            randNum -= wSpell.second;
            delete wSpell.first.first;
        }
    }

    spells.clear();
    return selected;
}

void PlayerAI::DoCastAtTarget(TargetedSpell spell)
{
    SpellCastTargets targets;
    targets.SetUnitTarget(spell.second);
    spell.first->prepare(&targets);
}

void PlayerAI::DoRangedAttackIfReady()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (!me->isAttackReady(RANGED_ATTACK))
        return;

    Unit* victim = me->GetVictim();
    if (!victim)
        return;

    uint32 rangedAttackSpell = 0;

    Item const* rangedItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
    if (ItemTemplate const* rangedTemplate = rangedItem ? rangedItem->GetTemplate() : nullptr)
    {
        switch (rangedTemplate->GetSubClass())
        {
            case ITEM_SUBCLASS_WEAPON_BOW:
            case ITEM_SUBCLASS_WEAPON_GUN:
            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                rangedAttackSpell = SPELL_SHOOT;
                break;
            case ITEM_SUBCLASS_WEAPON_THROWN:
                rangedAttackSpell = SPELL_THROW;
                break;
            case ITEM_SUBCLASS_WEAPON_WAND:
                rangedAttackSpell = SPELL_SHOOT_WAND;
                break;
        }
    }

    if (!rangedAttackSpell)
        return;

    me->CastSpell(victim, rangedAttackSpell, TRIGGERED_CAST_DIRECTLY);
    me->resetAttackTimer(RANGED_ATTACK);
}

void PlayerAI::DoAutoAttackIfReady()
{
    if (IsRangedAttacker())
        DoRangedAttackIfReady();
    else
        DoMeleeAttackIfReady();
}

void PlayerAI::CancelAllShapeshifts()
{
    std::list<AuraEffect*> const& shapeshiftAuras = me->GetAuraEffectsByType(SPELL_AURA_MOD_SHAPESHIFT);
    std::set<Aura*> removableShapeshifts;
    for (AuraEffect* auraEff : shapeshiftAuras)
    {
        Aura* aura = auraEff->GetBase();
        if (!aura)
            continue;
        SpellInfo const* auraInfo = aura->GetSpellInfo();
        if (!auraInfo)
            continue;
        if (auraInfo->HasAttribute(SPELL_ATTR0_CANT_CANCEL))
            continue;
        if (!auraInfo->IsPositive() || auraInfo->IsPassive())
            continue;
        removableShapeshifts.insert(aura);
    }

    for (Aura* aura : removableShapeshifts)
        me->RemoveOwnedAura(aura, AURA_REMOVE_BY_CANCEL);
}

Unit* PlayerAI::SelectAttackTarget() const
{
    return me->GetCharmer() ? me->GetCharmer()->GetVictim() : nullptr;
}

struct ValidTargetSelectPredicate
{
    ValidTargetSelectPredicate(UnitAI const* ai) : _ai(ai) { }
    UnitAI const* const _ai;
    bool operator()(Unit const* target) const
    {
        return _ai->CanAIAttack(target);
    }
};

bool SimpleCharmedPlayerAI::CanAIAttack(Unit const* who) const
{
    if (!me->IsValidAttackTarget(who) || who->HasBreakableByDamageCrowdControlAura())
        return false;
    if (Unit* charmer = me->GetCharmer())
        if (!charmer->IsValidAttackTarget(who))
            return false;
    return UnitAI::CanAIAttack(who);
}

Unit* SimpleCharmedPlayerAI::SelectAttackTarget() const
{
    if (Unit* charmer = me->GetCharmer())
        return charmer->IsAIEnabled ? charmer->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, ValidTargetSelectPredicate(this)) : charmer->GetVictim();
    return nullptr;
}

PlayerAI::TargetedSpell SimpleCharmedPlayerAI::SelectAppropriateCastForSpec()
{
    PossibleSpellVector spells;
    /*
    switch (me->getClass())
    {
        case CLASS_WARRIOR:
            if (!me->IsWithinMeleeRange(me->GetVictim()))
            {
                VerifyAndPushSpellCast(spells, SPELL_CHARGE, TARGET_VICTIM, 15);
                VerifyAndPushSpellCast(spells, SPELL_INTERCEPT, TARGET_VICTIM, 10);
            }
            VerifyAndPushSpellCast(spells, SPELL_ENRAGED_REGEN, TARGET_NONE, 3);
            VerifyAndPushSpellCast(spells, SPELL_INTIMIDATING_SHOUT, TARGET_VICTIM, 4);
            if (me->GetVictim() && me->GetVictim()->HasUnitState(UNIT_STATE_CASTING))
            {
                VerifyAndPushSpellCast(spells, SPELL_PUMMEL, TARGET_VICTIM, 15);
                VerifyAndPushSpellCast(spells, SPELL_SHIELD_BASH, TARGET_VICTIM, 15);
            }
            VerifyAndPushSpellCast(spells, SPELL_BLOODRAGE, TARGET_NONE, 5);
            switch (GetSpec())
            {
                case TALENT_SPEC_WARRIOR_PROTECTION:
                    VerifyAndPushSpellCast(spells, SPELL_SHOCKWAVE, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_CONCUSSION_BLOW, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_DISARM, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_LAST_STAND, TARGET_NONE, 5);
                    VerifyAndPushSpellCast(spells, SPELL_SHIELD_BLOCK, TARGET_NONE, 1);
                    VerifyAndPushSpellCast(spells, SPELL_SHIELD_SLAM, TARGET_VICTIM, 4);
                    VerifyAndPushSpellCast(spells, SPELL_SHIELD_WALL, TARGET_NONE, 5);
                    VerifyAndPushSpellCast(spells, SPELL_SPELL_REFLECTION, TARGET_NONE, 3);
                    VerifyAndPushSpellCast(spells, SPELL_DEVASTATE, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_REND, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_THUNDER_CLAP, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_DEMO_SHOUT, TARGET_VICTIM, 1);
                    break;
                case TALENT_SPEC_WARRIOR_ARMS:
                    VerifyAndPushSpellCast(spells, SPELL_SWEEPING_STRIKES, TARGET_NONE, 2);
                    VerifyAndPushSpellCast(spells, SPELL_MORTAL_STRIKE, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_BLADESTORM, TARGET_NONE, 10);
                    VerifyAndPushSpellCast(spells, SPELL_REND, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_RETALIATION, TARGET_NONE, 3);
                    VerifyAndPushSpellCast(spells, SPELL_SHATTERING_THROW, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_SWEEPING_STRIKES, TARGET_NONE, 5);
                    VerifyAndPushSpellCast(spells, SPELL_THUNDER_CLAP, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_EXECUTE, TARGET_VICTIM, 15);
                    break;
                case TALENT_SPEC_WARRIOR_FURY:
                    VerifyAndPushSpellCast(spells, SPELL_DEATH_WISH, TARGET_NONE, 10);
                    VerifyAndPushSpellCast(spells, SPELL_BLOODTHIRST, TARGET_VICTIM, 4);
                    VerifyAndPushSpellCast(spells, SPELL_DEMO_SHOUT, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_EXECUTE, TARGET_VICTIM, 15);
                    VerifyAndPushSpellCast(spells, SPELL_HEROIC_FURY, TARGET_NONE, 5);
                    VerifyAndPushSpellCast(spells, SPELL_RECKLESSNESS, TARGET_NONE, 8);
                    VerifyAndPushSpellCast(spells, SPELL_PIERCING_HOWL, TARGET_VICTIM, 2);
                    break;
            }
            break;
        case CLASS_PALADIN:
            VerifyAndPushSpellCast(spells, SPELL_AURA_MASTERY, TARGET_NONE, 3);
            VerifyAndPushSpellCast(spells, SPELL_LAY_ON_HANDS, TARGET_CHARMER, 8);
            VerifyAndPushSpellCast(spells, SPELL_BLESSING_OF_MIGHT, TARGET_CHARMER, 8);
            VerifyAndPushSpellCast(spells, SPELL_AVENGING_WRATH, TARGET_NONE, 5);
            VerifyAndPushSpellCast(spells, SPELL_DIVINE_PROTECTION, TARGET_NONE, 4);
            VerifyAndPushSpellCast(spells, SPELL_DIVINE_SHIELD, TARGET_NONE, 2);
            VerifyAndPushSpellCast(spells, SPELL_HAMMER_OF_JUSTICE, TARGET_VICTIM, 6);
            VerifyAndPushSpellCast(spells, SPELL_HAND_OF_FREEDOM, TARGET_SELF, 3);
            VerifyAndPushSpellCast(spells, SPELL_HAND_OF_PROTECTION, TARGET_SELF, 1);
            if (Creature* creatureCharmer = GetCharmer())
            {
                if (creatureCharmer->IsDungeonBoss() || creatureCharmer->isWorldBoss())
                    VerifyAndPushSpellCast(spells, SPELL_HAND_OF_SACRIFICE, creatureCharmer, 10);
                else
                    VerifyAndPushSpellCast(spells, SPELL_HAND_OF_PROTECTION, creatureCharmer, 3);
            }

            switch (GetSpec())
            {
                case TALENT_SPEC_PALADIN_PROTECTION:
                    VerifyAndPushSpellCast(spells, SPELL_HAMMER_OF_RIGHTEOUS, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_DIVINE_SACRIFICE, TARGET_NONE, 2);
                    VerifyAndPushSpellCast(spells, SPELL_SHIELD_OF_RIGHTEOUS, TARGET_VICTIM, 4);
                    VerifyAndPushSpellCast(spells, SPELL_JUDGEMENT, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_CONSECRATION, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_HOLY_SHIELD, TARGET_NONE, 1);
                    break;
                case TALENT_SPEC_PALADIN_HOLY:
                    VerifyAndPushSpellCast(spells, SPELL_HOLY_SHOCK, TARGET_CHARMER, 3);
                    VerifyAndPushSpellCast(spells, SPELL_HOLY_SHOCK, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_FLASH_OF_LIGHT, TARGET_CHARMER, 4);
                    VerifyAndPushSpellCast(spells, SPELL_HOLY_LIGHT, TARGET_CHARMER, 3);
                    VerifyAndPushSpellCast(spells, SPELL_DIVINE_FAVOR, TARGET_NONE, 5);
                    VerifyAndPushSpellCast(spells, SPELL_DIVINE_ILLUMINATION, TARGET_NONE, 3);
                    break;
                case TALENT_SPEC_PALADIN_RETRIBUTION:
                    VerifyAndPushSpellCast(spells, SPELL_CRUSADER_STRIKE, TARGET_VICTIM, 4);
                    VerifyAndPushSpellCast(spells, SPELL_DIVINE_STORM, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_JUDGEMENT, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_HAMMER_OF_WRATH, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_RIGHTEOUS_FURY, TARGET_NONE, 2);
                    break;
            }
            break;
        case CLASS_HUNTER:
            VerifyAndPushSpellCast(spells, SPELL_DETERRENCE, TARGET_NONE, 3);
            VerifyAndPushSpellCast(spells, SPELL_EXPLOSIVE_TRAP, TARGET_NONE, 1);
            VerifyAndPushSpellCast(spells, SPELL_FREEZING_ARROW, TARGET_VICTIM, 2);
            VerifyAndPushSpellCast(spells, SPELL_RAPID_FIRE, TARGET_NONE, 10);
            VerifyAndPushSpellCast(spells, SPELL_KILL_SHOT, TARGET_VICTIM, 10);
            if (me->GetVictim() && me->GetVictim()->GetPowerType() == POWER_MANA && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_VIPER_STING, me->GetGUID()))
                VerifyAndPushSpellCast(spells, SPELL_VIPER_STING, TARGET_VICTIM, 5);

            switch (GetSpec())
            {
                case TALENT_SPEC_HUNTER_BEASTMASTER:
                    VerifyAndPushSpellCast(spells, SPELL_AIMED_SHOT, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_ARCANE_SHOT, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_STEADY_SHOT, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_MULTI_SHOT, TARGET_VICTIM, 2);
                    break;
                case TALENT_SPEC_HUNTER_MARKSMAN:
                    VerifyAndPushSpellCast(spells, SPELL_AIMED_SHOT, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_CHIMERA_SHOT, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_ARCANE_SHOT, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_STEADY_SHOT, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_READINESS, TARGET_NONE, 10);
                    VerifyAndPushSpellCast(spells, SPELL_SILENCING_SHOT, TARGET_VICTIM, 5);
                    break;
                case TALENT_SPEC_HUNTER_SURVIVAL:
                    VerifyAndPushSpellCast(spells, SPELL_EXPLOSIVE_SHOT, TARGET_VICTIM, 8);
                    VerifyAndPushSpellCast(spells, SPELL_BLACK_ARROW, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_MULTI_SHOT, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_STEADY_SHOT, TARGET_VICTIM, 1);
                    break;
            }
            break;
        case CLASS_ROGUE:
        {
            VerifyAndPushSpellCast(spells, SPELL_DISMANTLE, TARGET_VICTIM, 8);
            VerifyAndPushSpellCast(spells, SPELL_EVASION, TARGET_NONE, 8);
            VerifyAndPushSpellCast(spells, SPELL_VANISH, TARGET_NONE, 4);
            VerifyAndPushSpellCast(spells, SPELL_BLIND, TARGET_VICTIM, 2);
            VerifyAndPushSpellCast(spells, SPELL_CLOAK_OF_SHADOWS, TARGET_NONE, 2);

            uint32 builder = 0, finisher = 0;
            switch (GetSpec())
            {
                case TALENT_SPEC_ROGUE_ASSASSINATION:
                    builder = SPELL_MUTILATE, finisher = SPELL_ENVENOM;
                    VerifyAndPushSpellCast(spells, SPELL_COLD_BLOOD, TARGET_NONE, 20);
                    break;
                case TALENT_SPEC_ROGUE_COMBAT:
                    builder = SPELL_SINISTER_STRIKE, finisher = SPELL_EVISCERATE;
                    VerifyAndPushSpellCast(spells, SPELL_ADRENALINE_RUSH, TARGET_NONE, 6);
                    VerifyAndPushSpellCast(spells, SPELL_BLADE_FLURRY, TARGET_NONE, 5);
                    VerifyAndPushSpellCast(spells, SPELL_KILLING_SPREE, TARGET_NONE, 25);
                    break;
                case TALENT_SPEC_ROGUE_SUBTLETY:
                    builder = SPELL_HEMORRHAGE, finisher = SPELL_EVISCERATE;
                    VerifyAndPushSpellCast(spells, SPELL_PREPARATION, TARGET_NONE, 10);
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        VerifyAndPushSpellCast(spells, SPELL_SHADOWSTEP, TARGET_VICTIM, 25);
                    VerifyAndPushSpellCast(spells, SPELL_SHADOW_DANCE, TARGET_NONE, 10);
                    break;
            }

            if (Unit* victim = me->GetVictim())
            {
                if (victim->HasUnitState(UNIT_STATE_CASTING))
                    VerifyAndPushSpellCast(spells, SPELL_KICK, TARGET_VICTIM, 25);

                uint8 const cp = me->GetPower(POWER_COMBO_POINTS);
                if (cp >= 4)
                    VerifyAndPushSpellCast(spells, finisher, TARGET_VICTIM, 10);
                if (cp <= 4)
                    VerifyAndPushSpellCast(spells, builder, TARGET_VICTIM, 5);
            }
            break;
        }
        case CLASS_PRIEST:
            VerifyAndPushSpellCast(spells, SPELL_FEAR_WARD, TARGET_SELF, 2);
            VerifyAndPushSpellCast(spells, SPELL_POWER_WORD_FORT, TARGET_CHARMER, 1);
            VerifyAndPushSpellCast(spells, SPELL_DIVINE_SPIRIT, TARGET_CHARMER, 1);
            VerifyAndPushSpellCast(spells, SPELL_SHADOW_PROTECTION, TARGET_CHARMER, 2);
            VerifyAndPushSpellCast(spells, SPELL_DIVINE_HYMN, TARGET_NONE, 5);
            VerifyAndPushSpellCast(spells, SPELL_HYMN_OF_HOPE, TARGET_NONE, 5);
            VerifyAndPushSpellCast(spells, SPELL_SHADOW_WORD_DEATH, TARGET_VICTIM, 1);
            VerifyAndPushSpellCast(spells, SPELL_PSYCHIC_SCREAM, TARGET_VICTIM, 3);
            switch (GetSpec())
            {
                case TALENT_SPEC_PRIEST_DISCIPLINE:
                    VerifyAndPushSpellCast(spells, SPELL_POWER_WORD_SHIELD, TARGET_CHARMER, 3);
                    VerifyAndPushSpellCast(spells, SPELL_INNER_FOCUS, TARGET_NONE, 3);
                    VerifyAndPushSpellCast(spells, SPELL_PAIN_SUPPRESSION, TARGET_CHARMER, 15);
                    VerifyAndPushSpellCast(spells, SPELL_POWER_INFUSION, TARGET_CHARMER, 10);
                    VerifyAndPushSpellCast(spells, SPELL_PENANCE, TARGET_CHARMER, 3);
                    VerifyAndPushSpellCast(spells, SPELL_FLASH_HEAL, TARGET_CHARMER, 1);
                    break;
                case TALENT_SPEC_PRIEST_HOLY:
                    VerifyAndPushSpellCast(spells, SPELL_DESPERATE_PRAYER, TARGET_NONE, 3);
                    VerifyAndPushSpellCast(spells, SPELL_GUARDIAN_SPIRIT, TARGET_CHARMER, 5);
                    VerifyAndPushSpellCast(spells, SPELL_FLASH_HEAL, TARGET_CHARMER, 1);
                    VerifyAndPushSpellCast(spells, SPELL_RENEW, TARGET_CHARMER, 3);
                    break;
                case TALENT_SPEC_PRIEST_SHADOW:
                    if (!me->HasAura(SPELL_SHADOWFORM))
                    {
                        VerifyAndPushSpellCast(spells, SPELL_SHADOWFORM, TARGET_NONE, 100);
                        break;
                    }
                    if (Unit* victim = me->GetVictim())
                    {
                        if (!victim->GetAuraApplicationOfRankedSpell(SPELL_VAMPIRIC_TOUCH, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_VAMPIRIC_TOUCH, TARGET_VICTIM, 4);
                        if (!victim->GetAuraApplicationOfRankedSpell(SPELL_SHADOW_WORD_PAIN, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_SHADOW_WORD_PAIN, TARGET_VICTIM, 3);
                        if (!victim->GetAuraApplicationOfRankedSpell(SPELL_DEVOURING_PLAGUE, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_DEVOURING_PLAGUE, TARGET_VICTIM, 4);
                    }
                    VerifyAndPushSpellCast(spells, SPELL_MIND_BLAST, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_MIND_FLAY, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_DISPERSION, TARGET_NONE, 10);
                    break;
            }
            break;
        case CLASS_DEATH_KNIGHT:
        {
            if (!me->IsWithinMeleeRange(me->GetVictim()))
                VerifyAndPushSpellCast(spells, SPELL_DEATH_GRIP, TARGET_VICTIM, 25);
            VerifyAndPushSpellCast(spells, SPELL_STRANGULATE, TARGET_VICTIM, 15);
            VerifyAndPushSpellCast(spells, SPELL_EMPOWER_RUNE_WEAP, TARGET_NONE, 5);
            VerifyAndPushSpellCast(spells, SPELL_ICEBORN_FORTITUDE, TARGET_NONE, 15);
            VerifyAndPushSpellCast(spells, SPELL_ANTI_MAGIC_SHELL, TARGET_NONE, 10);

            bool hasFF = false, hasBP = false;
            if (Unit* victim = me->GetVictim())
            {
                if (victim->HasUnitState(UNIT_STATE_CASTING))
                    VerifyAndPushSpellCast(spells, SPELL_MIND_FREEZE, TARGET_VICTIM, 25);

                hasFF = !!victim->GetAuraApplicationOfRankedSpell(AURA_FROST_FEVER, me->GetGUID()), hasBP = !!victim->GetAuraApplicationOfRankedSpell(AURA_BLOOD_PLAGUE, me->GetGUID());
                if (hasFF && hasBP)
                    VerifyAndPushSpellCast(spells, SPELL_PESTILENCE, TARGET_VICTIM, 3);
                if (!hasFF)
                    VerifyAndPushSpellCast(spells, SPELL_ICY_TOUCH, TARGET_VICTIM, 4);
                if (!hasBP)
                    VerifyAndPushSpellCast(spells, SPELL_PLAGUE_STRIKE, TARGET_VICTIM, 4);
            }
            switch (GetSpec())
            {
                case TALENT_SPEC_DEATHKNIGHT_BLOOD:
                    VerifyAndPushSpellCast(spells, SPELL_RUNE_TAP, TARGET_NONE, 2);
                    VerifyAndPushSpellCast(spells, SPELL_HYSTERIA, TARGET_SELF, 5);
                    if (Creature* creatureCharmer = GetCharmer())
                        if (!creatureCharmer->IsDungeonBoss() && !creatureCharmer->isWorldBoss())
                            VerifyAndPushSpellCast(spells, SPELL_HYSTERIA, creatureCharmer, 15);
                    VerifyAndPushSpellCast(spells, SPELL_HEART_STRIKE, TARGET_VICTIM, 2);
                    if (hasFF && hasBP)
                        VerifyAndPushSpellCast(spells, SPELL_DEATH_STRIKE, TARGET_VICTIM, 8);
                    VerifyAndPushSpellCast(spells, SPELL_DEATH_COIL_DK, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_MARK_OF_BLOOD, TARGET_VICTIM, 20);
                    VerifyAndPushSpellCast(spells, SPELL_VAMPIRIC_BLOOD, TARGET_NONE, 10);
                    break;
                case TALENT_SPEC_DEATHKNIGHT_FROST:
                    if (hasFF && hasBP)
                        VerifyAndPushSpellCast(spells, SPELL_OBLITERATE, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_HOWLING_BLAST, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_UNBREAKABLE_ARMOR, TARGET_NONE, 10);
                    VerifyAndPushSpellCast(spells, SPELL_DEATHCHILL, TARGET_NONE, 10);
                    VerifyAndPushSpellCast(spells, SPELL_FROST_STRIKE, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_BLOOD_STRIKE, TARGET_VICTIM, 1);
                    break;
                case TALENT_SPEC_DEATHKNIGHT_UNHOLY:
                    if (hasFF && hasBP)
                        VerifyAndPushSpellCast(spells, SPELL_SCOURGE_STRIKE, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_DEATH_AND_DECAY, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_ANTI_MAGIC_ZONE, TARGET_NONE, 8);
                    VerifyAndPushSpellCast(spells, SPELL_SUMMON_GARGOYLE, TARGET_VICTIM, 7);
                    VerifyAndPushSpellCast(spells, SPELL_BLOOD_STRIKE, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_DEATH_COIL_DK, TARGET_VICTIM, 3);
                    break;
            }
            break;
        }
        case CLASS_SHAMAN:
            VerifyAndPushSpellCast(spells, SPELL_HEROISM, TARGET_NONE, 25);
            VerifyAndPushSpellCast(spells, SPELL_BLOODLUST, TARGET_NONE, 25);
            VerifyAndPushSpellCast(spells, SPELL_GROUNDING_TOTEM, TARGET_NONE, 2);
            switch (GetSpec())
            {
                case TALENT_SPEC_SHAMAN_RESTORATION:
                    if (Unit* charmer = me->GetCharmer())
                        if (!charmer->GetAuraApplicationOfRankedSpell(SPELL_EARTH_SHIELD, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_EARTH_SHIELD, charmer, 2);
                    if (me->HasAura(SPELL_SHA_NATURE_SWIFT))
                        VerifyAndPushSpellCast(spells, SPELL_HEALING_WAVE, TARGET_CHARMER, 20);
                    else
                        VerifyAndPushSpellCast(spells, SPELL_LESSER_HEAL_WAVE, TARGET_CHARMER, 1);
                    VerifyAndPushSpellCast(spells, SPELL_TIDAL_FORCE, TARGET_NONE, 4);
                    VerifyAndPushSpellCast(spells, SPELL_SHA_NATURE_SWIFT, TARGET_NONE, 4);
                    VerifyAndPushSpellCast(spells, SPELL_MANA_TIDE_TOTEM, TARGET_NONE, 3);
                    break;
                case TALENT_SPEC_SHAMAN_ELEMENTAL:
                    if (Unit* victim = me->GetVictim())
                    {
                        if (victim->GetAuraOfRankedSpell(SPELL_FLAME_SHOCK, GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_LAVA_BURST, TARGET_VICTIM, 5);
                        else
                            VerifyAndPushSpellCast(spells, SPELL_FLAME_SHOCK, TARGET_VICTIM, 3);
                    }
                    VerifyAndPushSpellCast(spells, SPELL_CHAIN_LIGHTNING, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_LIGHTNING_BOLT, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_ELEMENTAL_MASTERY, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_THUNDERSTORM, TARGET_NONE, 3);
                    break;
                case TALENT_SPEC_SHAMAN_ENHANCEMENT:
                    if (Aura const* maelstrom = me->GetAura(AURA_MAELSTROM_WEAPON))
                        if (maelstrom->GetStackAmount() == 5)
                            VerifyAndPushSpellCast(spells, SPELL_LIGHTNING_BOLT, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_STORMSTRIKE, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_EARTH_SHOCK, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_LAVA_LASH, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_SHAMANISTIC_RAGE, TARGET_NONE, 10);
                    break;
            }
            break;
        case CLASS_MAGE:
            if (me->GetVictim() && me->GetVictim()->HasUnitState(UNIT_STATE_CASTING))
                VerifyAndPushSpellCast(spells, SPELL_COUNTERSPELL, TARGET_VICTIM, 25);
            VerifyAndPushSpellCast(spells, SPELL_DAMPEN_MAGIC, TARGET_CHARMER, 2);
            VerifyAndPushSpellCast(spells, SPELL_EVOCATION, TARGET_NONE, 3);
            VerifyAndPushSpellCast(spells, SPELL_MANA_SHIELD, TARGET_NONE, 1);
            VerifyAndPushSpellCast(spells, SPELL_MIRROR_IMAGE, TARGET_NONE, 3);
            VerifyAndPushSpellCast(spells, SPELL_SPELLSTEAL, TARGET_VICTIM, 2);
            VerifyAndPushSpellCast(spells, SPELL_ICE_BLOCK, TARGET_NONE, 1);
            VerifyAndPushSpellCast(spells, SPELL_ICY_VEINS, TARGET_NONE, 3);
            switch (GetSpec())
            {
                case TALENT_SPEC_MAGE_ARCANE:
                    if (Aura* abAura = me->GetAura(AURA_ARCANE_BLAST))
                        if (abAura->GetStackAmount() >= 3)
                            VerifyAndPushSpellCast(spells, SPELL_ARCANE_MISSILES, TARGET_VICTIM, 7);
                    VerifyAndPushSpellCast(spells, SPELL_ARCANE_BLAST, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_ARCANE_BARRAGE, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_ARCANE_POWER, TARGET_NONE, 8);
                    VerifyAndPushSpellCast(spells, SPELL_PRESENCE_OF_MIND, TARGET_NONE, 7);
                    break;
                case TALENT_SPEC_MAGE_FIRE:
                    if (me->GetVictim() && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_LIVING_BOMB))
                        VerifyAndPushSpellCast(spells, SPELL_LIVING_BOMB, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_COMBUSTION, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_FIREBALL, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_FIRE_BLAST, TARGET_VICTIM, 1);
                    VerifyAndPushSpellCast(spells, SPELL_DRAGONS_BREATH, TARGET_VICTIM, 2);
                    VerifyAndPushSpellCast(spells, SPELL_BLAST_WAVE, TARGET_VICTIM, 1);
                    break;
                case TALENT_SPEC_MAGE_FROST:
                    VerifyAndPushSpellCast(spells, SPELL_DEEP_FREEZE, TARGET_VICTIM, 10);
                    VerifyAndPushSpellCast(spells, SPELL_FROST_NOVA, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_FROSTBOLT, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_COLD_SNAP, TARGET_VICTIM, 5);
                    if (me->GetVictim() && me->GetVictim()->HasAuraState(AURA_STATE_FROZEN, nullptr, me))
                        VerifyAndPushSpellCast(spells, SPELL_ICE_LANCE, TARGET_VICTIM, 5);
                    break;
            }
            break;
        case CLASS_WARLOCK:
            VerifyAndPushSpellCast(spells, SPELL_DEATH_COIL_W, TARGET_VICTIM, 2);
            VerifyAndPushSpellCast(spells, SPELL_FEAR, TARGET_VICTIM, 2);
            VerifyAndPushSpellCast(spells, SPELL_SEED_OF_CORRUPTION, TARGET_VICTIM, 4);
            VerifyAndPushSpellCast(spells, SPELL_HOWL_OF_TERROR, TARGET_NONE, 2);
            if (me->GetVictim() && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_CORRUPTION, me->GetGUID()))
                VerifyAndPushSpellCast(spells, SPELL_CORRUPTION, TARGET_VICTIM, 10);
            switch (GetSpec())
            {
                case TALENT_SPEC_WARLOCK_AFFLICTION:
                    if (Unit* victim = me->GetVictim())
                    {
                        VerifyAndPushSpellCast(spells, SPELL_SHADOW_BOLT, TARGET_VICTIM, 7);
                        if (!victim->GetAuraApplicationOfRankedSpell(SPELL_UNSTABLE_AFFLICTION, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_UNSTABLE_AFFLICTION, TARGET_VICTIM, 8);
                        if (!victim->GetAuraApplicationOfRankedSpell(SPELL_HAUNT, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_HAUNT, TARGET_VICTIM, 8);
                        if (!victim->GetAuraApplicationOfRankedSpell(SPELL_CURSE_OF_AGONY, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_CURSE_OF_AGONY, TARGET_VICTIM, 4);
                        if (victim->HealthBelowPct(25))
                            VerifyAndPushSpellCast(spells, SPELL_DRAIN_SOUL, TARGET_VICTIM, 100);
                    }
                    break;
                case TALENT_SPEC_WARLOCK_DEMONOLOGY:
                    VerifyAndPushSpellCast(spells, SPELL_METAMORPHOSIS, TARGET_NONE, 15);
                    VerifyAndPushSpellCast(spells, SPELL_SHADOW_BOLT, TARGET_VICTIM, 7);
                    if (me->HasAura(AURA_DECIMATION))
                        VerifyAndPushSpellCast(spells, SPELL_SOUL_FIRE, TARGET_VICTIM, 100);
                    if (me->HasAura(SPELL_METAMORPHOSIS))
                    {
                        VerifyAndPushSpellCast(spells, SPELL_IMMOLATION_AURA, TARGET_NONE, 30);
                        if (!me->IsWithinMeleeRange(me->GetVictim()))
                            VerifyAndPushSpellCast(spells, SPELL_DEMON_CHARGE, TARGET_VICTIM, 20);
                    }
                    if (me->GetVictim() && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_IMMOLATE, me->GetGUID()))
                        VerifyAndPushSpellCast(spells, SPELL_IMMOLATE, TARGET_VICTIM, 5);
                    if (me->HasAura(AURA_MOLTEN_CORE))
                        VerifyAndPushSpellCast(spells, SPELL_INCINERATE, TARGET_VICTIM, 10);
                    break;
                case TALENT_SPEC_WARLOCK_DESTRUCTION:
                    if (me->GetVictim() && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_IMMOLATE, me->GetGUID()))
                        VerifyAndPushSpellCast(spells, SPELL_IMMOLATE, TARGET_VICTIM, 8);
                    if (me->GetVictim() && me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_IMMOLATE, me->GetGUID()))
                        VerifyAndPushSpellCast(spells, SPELL_CONFLAGRATE, TARGET_VICTIM, 8);
                    VerifyAndPushSpellCast(spells, SPELL_SHADOWFURY, TARGET_VICTIM, 5);
                    VerifyAndPushSpellCast(spells, SPELL_CHAOS_BOLT, TARGET_VICTIM, 10);
                    VerifyAndPushSpellCast(spells, SPELL_SHADOWBURN, TARGET_VICTIM, 3);
                    VerifyAndPushSpellCast(spells, SPELL_INCINERATE, TARGET_VICTIM, 7);
                    break;
            }
            break;
        case CLASS_MONK:
            switch (GetSpec())
            {
                case TALENT_SPEC_MONK_BREWMASTER:
                case TALENT_SPEC_MONK_BATTLEDANCER:
                case TALENT_SPEC_MONK_MISTWEAVER:
                    break;
            }
            break;
        case CLASS_DRUID:
            VerifyAndPushSpellCast(spells, SPELL_INNERVATE, TARGET_CHARMER, 5);
            VerifyAndPushSpellCast(spells, SPELL_BARKSKIN, TARGET_NONE, 5);
            switch (GetSpec())
            {
                case TALENT_SPEC_DRUID_RESTORATION:
                    if (!me->HasAura(SPELL_TREE_OF_LIFE))
                    {
                        CancelAllShapeshifts();
                        VerifyAndPushSpellCast(spells, SPELL_TREE_OF_LIFE, TARGET_NONE, 100);
                        break;
                    }
                    VerifyAndPushSpellCast(spells, SPELL_TRANQUILITY, TARGET_NONE, 10);
                    VerifyAndPushSpellCast(spells, SPELL_NATURE_SWIFTNESS, TARGET_NONE, 7);
                    if (Creature* creatureCharmer = GetCharmer())
                    {
                        VerifyAndPushSpellCast(spells, SPELL_NOURISH, creatureCharmer, 5);
                        VerifyAndPushSpellCast(spells, SPELL_WILD_GROWTH, creatureCharmer, 5);
                        if (!creatureCharmer->GetAuraApplicationOfRankedSpell(SPELL_REJUVENATION, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_REJUVENATION, creatureCharmer, 8);
                        if (!creatureCharmer->GetAuraApplicationOfRankedSpell(SPELL_REGROWTH, me->GetGUID()))
                            VerifyAndPushSpellCast(spells, SPELL_REGROWTH, creatureCharmer, 8);
                        uint8 lifebloomStacks = 0;
                        if (Aura const* lifebloom = creatureCharmer->GetAura(SPELL_LIFEBLOOM, me->GetGUID()))
                            lifebloomStacks = lifebloom->GetStackAmount();
                        if (lifebloomStacks < 3)
                            VerifyAndPushSpellCast(spells, SPELL_LIFEBLOOM, creatureCharmer, 5);
                        if (creatureCharmer->GetAuraApplicationOfRankedSpell(SPELL_REJUVENATION) ||
                            creatureCharmer->GetAuraApplicationOfRankedSpell(SPELL_REGROWTH))
                            VerifyAndPushSpellCast(spells, SPELL_SWIFTMEND, creatureCharmer, 10);
                        if (me->HasAura(SPELL_NATURE_SWIFTNESS))
                            VerifyAndPushSpellCast(spells, SPELL_HEALING_TOUCH, creatureCharmer, 100);
                    }
                    break;
                case TALENT_SPEC_DRUID_BALANCE:
                {
                    if (!me->HasAura(SPELL_MOONKIN_FORM))
                    {
                        CancelAllShapeshifts();
                        VerifyAndPushSpellCast(spells, SPELL_MOONKIN_FORM, TARGET_NONE, 100);
                        break;
                    }
                    uint32 const mainAttackSpell = me->HasAura(AURA_ECLIPSE_LUNAR) ? SPELL_STARFIRE : SPELL_WRATH;
                    VerifyAndPushSpellCast(spells, SPELL_STARFALL, TARGET_NONE, 20);
                    VerifyAndPushSpellCast(spells, mainAttackSpell, TARGET_VICTIM, 10);
                    if (me->GetVictim() && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_INSECT_SWARM, me->GetGUID()))
                        VerifyAndPushSpellCast(spells, SPELL_INSECT_SWARM, TARGET_VICTIM, 7);
                    if (me->GetVictim() && !me->GetVictim()->GetAuraApplicationOfRankedSpell(SPELL_MOONFIRE, me->GetGUID()))
                        VerifyAndPushSpellCast(spells, SPELL_MOONFIRE, TARGET_VICTIM, 5);
                    if (me->GetVictim() && me->GetVictim()->HasUnitState(UNIT_STATE_CASTING))
                        VerifyAndPushSpellCast(spells, SPELL_TYPHOON, TARGET_NONE, 15);
                    break;
                }
                case TALENT_SPEC_DRUID_CAT:
                case TALENT_SPEC_DRUID_BEAR:
                    if (!me->HasAura(SPELL_CAT_FORM))
                    {
                        CancelAllShapeshifts();
                        VerifyAndPushSpellCast(spells, SPELL_CAT_FORM, TARGET_NONE, 100);
                        break;
                    }
                    VerifyAndPushSpellCast(spells, SPELL_BERSERK, TARGET_NONE, 20);
                    VerifyAndPushSpellCast(spells, SPELL_SURVIVAL_INSTINCTS, TARGET_NONE, 15);
                    VerifyAndPushSpellCast(spells, SPELL_TIGER_FURY, TARGET_NONE, 15);
                    VerifyAndPushSpellCast(spells, SPELL_DASH, TARGET_NONE, 5);
                    if (Unit* victim = me->GetVictim())
                    {
                        uint8 const cp = me->GetPower(POWER_COMBO_POINTS);
                        if (victim->HasUnitState(UNIT_STATE_CASTING) && cp >= 1)
                            VerifyAndPushSpellCast(spells, SPELL_MAIM, TARGET_VICTIM, 25);
                        if (!me->IsWithinMeleeRange(victim))
                            VerifyAndPushSpellCast(spells, SPELL_FERAL_CHARGE_CAT, TARGET_VICTIM, 25);
                        if (cp >= 4)
                            VerifyAndPushSpellCast(spells, SPELL_RIP, TARGET_VICTIM, 50);
                        if (cp <= 4)
                        {
                            VerifyAndPushSpellCast(spells, SPELL_MANGLE_CAT, TARGET_VICTIM, 10);
                            VerifyAndPushSpellCast(spells, SPELL_CLAW, TARGET_VICTIM, 5);
                            if (!victim->GetAuraApplicationOfRankedSpell(SPELL_RAKE, me->GetGUID()))
                                VerifyAndPushSpellCast(spells, SPELL_RAKE, TARGET_VICTIM, 8);
                            if (!me->HasAura(SPELL_SAVAGE_ROAR))
                                VerifyAndPushSpellCast(spells, SPELL_SAVAGE_ROAR, TARGET_NONE, 15);
                        }
                    }
                    break;
            }
            break;
        case CLASS_DEMON_HUNTER:
            switch (GetSpec())
            {
                case TALENT_SPEC_DEMON_HUNTER_HAVOC:
                case TALENT_SPEC_DEMON_HUNTER_VENGEANCE:
                    break;
            }
            break;
    }
    */
    return SelectSpellCast(spells);
}

static const float CASTER_CHASE_DISTANCE = 28.0f;
void SimpleCharmedPlayerAI::UpdateAI(const uint32 diff)
{
    Creature* charmer = GetCharmer();
    if (!charmer)
        return;

    //kill self if charm aura has infinite duration
    if (charmer->IsInEvadeMode())
    {
        Player::AuraEffectList const& auras = me->GetAuraEffectsByType(SPELL_AURA_MOD_CHARM);
        for (Player::AuraEffectList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
        {
            if ((*iter)->GetCasterGUID() == charmer->GetGUID() && (*iter)->GetBase()->IsPermanent())
            {
                me->KillSelf();
                return;
            }
        }
    }

    if (charmer->IsEngaged())
    {
        Unit* target = me->GetVictim();
        if (!target || !CanAIAttack(target))
        {
            target = SelectAttackTarget();
            if (!target || !CanAIAttack(target))
            {
                if (!_isFollowing)
                {
                    _isFollowing = true;
                    me->AttackStop();
                    me->CastStop();
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                }
                return;
            }
            _isFollowing = false;

            if (IsRangedAttacker())
            {
                _chaseCloser = !me->IsWithinLOSInMap(target);
                if (_chaseCloser)
                    AttackStart(target);
                else
                    AttackStartCaster(target, CASTER_CHASE_DISTANCE);
            }
            else
                AttackStart(target);
            _forceFacing = true;
        }

        if (me->IsStopped() && !me->HasUnitState(UNIT_STATE_CANNOT_TURN))
        {
            float targetAngle = me->GetAngle(target);
            if (_forceFacing || fabs(me->GetOrientation() - targetAngle) > 0.4f)
            {
                me->SetFacingTo(targetAngle);
                _forceFacing = false;
            }
        }

        if (_castCheckTimer <= diff)
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                _castCheckTimer = 0;
            else
            {
                if (IsRangedAttacker())
                { // chase to zero if the target isn't in line of sight
                    bool inLOS = me->IsWithinLOSInMap(target);
                    if (_chaseCloser != !inLOS)
                    {
                        _chaseCloser = !inLOS;
                        if (_chaseCloser)
                            AttackStart(target);
                        else
                            AttackStartCaster(target, CASTER_CHASE_DISTANCE);
                    }
                }
                if (TargetedSpell shouldCast = SelectAppropriateCastForSpec())
                    DoCastAtTarget(shouldCast);
                _castCheckTimer = 500;
            }
        }
        else
            _castCheckTimer -= diff;

        DoAutoAttackIfReady();
    }
    else if (!_isFollowing)
    {
        _isFollowing = true;
        me->AttackStop();
        me->CastStop();
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }
}

void SimpleCharmedPlayerAI::OnCharmed(bool apply)
{
    if (apply)
    {
        me->CastStop();
        me->AttackStop();
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MovePoint(0, me->GetPosition(), false); // force re-sync of current position for all clients
    }
    else
    {
        me->CastStop();
        me->AttackStop();
        // @todo only voluntary movement (don't cancel stuff like death grip or charge mid-animation)
        me->GetMotionMaster()->Clear();
        me->StopMoving();
    }
}
