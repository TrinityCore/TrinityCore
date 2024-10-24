#include "bot_ai.h"
#include "botmgr.h"
#include "bottext.h"
#include "bottraits.h"
#include "Containers.h"
#include "Creature.h"
#include "Group.h"
#include "Item.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
//#include "WorldSession.h"
/*
Paladin NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - Around 95%
TODO:
*/

enum PaladinBaseSpells// all orignals
{
    FLASH_OF_LIGHT_1                    = 19750,
    HOLY_LIGHT_1                        = 635,
    LAY_ON_HANDS_1                      = 633,
    REDEMPTION_1                        = 7328,
    HAND_OF_FREEDOM_1                   = 1044,
    SACRED_SHIELD_1                     = 53601,
    HOLY_SHOCK_1                        = 20473,
    CLEANSE_1                           = 4987,
    HAND_OF_PROTECTION_1                = 1022,
    HAND_OF_SALVATION_1                 = 1038,
    HAND_OF_SACRIFICE_1                 = 6940,
    SEAL_OF_VENGEANCE_1                 = 31801,
    SEAL_OF_CORRUPTION_1                = 53736,
    SEAL_OF_COMMAND_1                   = 20375,
    SEAL_OF_LIGHT_1                     = 20165,
    SEAL_OF_RIGHTEOUSNESS_1             = 21084,
    SEAL_OF_WISDOM_1                    = 20166,
    SEAL_OF_JUSTICE_1                   = 20164,
    DIVINE_SACRIFICE_1                  = 64205,
    HAND_OF_RECKONING_1                 = 62124,
    RIGHTEOUS_DEFENSE_1                 = 31789,
    DIVINE_PLEA_1                       = 54428,
    REPENTANCE_1                        = 20066,
    TURN_EVIL_1                         = 10326,
    CRUSADER_STRIKE_1                   = 35395,
    JUDGEMENT_OF_LIGHT_1                = 20271,
    JUDGEMENT_OF_WISDOM_1               = 53408,
    JUDGEMENT_OF_JUSTICE_1              = 53407,
    CONSECRATION_1                      = 26573,
    HAMMER_OF_JUSTICE_1                 = 853,
    DIVINE_STORM_1                      = 53385,
    HAMMER_OF_WRATH_1                   = 24275,
    EXORCISM_1                          = 879,
    HOLY_WRATH_1                        = 2812,
    AVENGING_WRATH_1                    = 31884,
    RIGHTEOUS_FURY_1                    = 25780,
    HOLY_SHIELD_1                       = 20925,
    AVENGERS_SHIELD_1                   = 31935,
    HAMMER_OF_THE_RIGHTEOUS_1           = 53595,
    SHIELD_OF_RIGHTEOUSNESS_1           = 53600,
    BLESSING_OF_MIGHT_1                 = 19740,
    BLESSING_OF_WISDOM_1                = 19742,
    BLESSING_OF_KINGS_1                 = 20217,
    BLESSING_OF_SANCTUARY_1             = 20911,
    DEVOTION_AURA_1                     = 465,
    CONCENTRATION_AURA_1                = 19746,
    FIRE_RESISTANCE_AURA_1              = 19891,
    FROST_RESISTANCE_AURA_1             = 19888,
    SHADOW_RESISTANCE_AURA_1            = 19876,
    RETRIBUTION_AURA_1                  = 7294,
    CRUSADER_AURA_1                     = 32223,

    DIVINE_INTERVENTION_1               = 19752,
    AURA_MASTERY_1                      = 31821,
    DIVINE_FAVOR_1                      = 20216,
    DIVINE_ILLUMINATION_1               = 31842,
    BEACON_OF_LIGHT_1                   = 53563,

    DIVINE_PROTECTION_1                 = 498,
    DIVINE_SHIELD_1                     = 642,

    PURIFY_1                            = 1152
};
enum PaladinPassives
{
//Talents
    DIVINE_PURPOSE                      = 31872,
    JUDGEMENTS_OF_THE_PURE              = 54155,
    JUDGEMENTS_OF_THE_WISE              = 31878,
    SACRED_CLEANSING                    = 53553,//rank 3
    RECKONING1                          = 20177,
    RECKONING2                          = 20179,
    RECKONING3                          = 20181,
    RECKONING4                          = 20180,
    RECKONING5                          = 20182,
    VINDICATION1                        = 9452,
    VINDICATION2                        = 26016,
    PURSUIT_OF_JUSTICE                  = 26023,//rank 2
    ART_OF_WAR                          = 53488,//rank 2
    IMPROVED_LAY_ON_HANDS               = 20235,//rank 2
    FANATICISM                          = 31881,//rank 3
    RIGHTEOUS_VENGEANCE1                = 53380,//rank 1
    RIGHTEOUS_VENGEANCE2                = 53381,//rank 2
    RIGHTEOUS_VENGEANCE3                = 53382,//rank 3
    VENGEANCE1                          = 20049,//rank 1
    VENGEANCE2                          = 20056,//rank 2
    VENGEANCE3                          = 20057,//rank 3
    SHEATH_OF_LIGHT1                    = 53501,//rank 1
    SHEATH_OF_LIGHT2                    = 53502,//rank 2
    SHEATH_OF_LIGHT3                    = 53503,//rank 3
    ARDENT_DEFENDER                     = 31852,//rank 3
    ILLUMINATION                        = 20215,//rank 5
    INFUSION_OF_LIGHT                   = 53576,//rank 2
    REDOUBT1                            = 20127,//rank 3
    REDOUBT2                            = 20130,//rank 3
    REDOUBT3                            = 20135,//rank 3
    IMPROVED_RIGHTEOUS_FURY             = 20470,//rank 3
    SHIELD_OF_THE_TEMPLAR               = 53711,//rank 3
    IMPROVED_DEVOTION_AURA              = 20140,//rank 3
    IMPROVED_CONCENTRATION_AURA         = 20256,//rank 3
    SANCTIFIED_RETRIBUTION              = 31869,
    SWIFT_RETRIBUTION                   = 53648,//rank 3
    LIGHTS_GRACE                        = 31836,//rank 3
    DIVINE_GUARDIAN                     = 53530,//rank 3
    //COMBAT_EXPERTISE                    = 31860,//rank 3
    CRUSADE                             = 31868,//rank 3
    ONE_HANDED_WEAPON_SPECIALIZATION    = 20198,//rank 3
    TWO_HANDED_WEAPON_SPECIALIZATION    = 20113,//rank 3
    //JUDGEMENTS_OF_THE_JUST              = 53696,//rank 2
    GUARDED_BY_THE_LIGHT                = 53585,//rank 2
    TOUCHED_BY_THE_LIGHT                = 53592,//rank 3
    HEART_OF_THE_CRUSADER               = 20337,//rank 3
//Glyphs
    GLYPH_HOLY_LIGHT                    = 54937,
    GLYPH_SALVATION                     = 63225,
//Innate
    JUDGEMENT_ANTI_PARRY_DODGE_PASSIVE  = 60091,
//other
    RECUCED_HOLY_LIGHT_CAST_TIME        = 37189,//not a typo
    //CLEANSE_HEAL_PASSIVE                = 28787
};

enum PaladinSpecial
{
    NOAURA                              = 0,
    DEVOTIONAURA                        = 1,
    CONCENTRATIONAURA                   = 2,
    FIRERESAURA                         = 3,
    FROSTRESAURA                        = 4,
    SHADOWRESAURA                       = 5,
    RETRIBUTIONAURA                     = 6,
    CRUSADERAURA                        = 7,

    SPECIFIC_BLESSING_WISDOM            = 0x01,
    SPECIFIC_BLESSING_KINGS             = 0x02,
    SPECIFIC_BLESSING_SANCTUARY         = 0x04,
    SPECIFIC_BLESSING_MIGHT             = 0x08,
    SPECIFIC_BLESSING_MY_BLESSING       = 0x10,

    SPECIFIC_AURA_DEVOTION              = 0x01,
    SPECIFIC_AURA_CONCENTRATION         = 0x02,
    SPECIFIC_AURA_FIRE_RES              = 0x04,
    SPECIFIC_AURA_FROST_RES             = 0x08,
    SPECIFIC_AURA_SHADOW_RES            = 0x10,
    SPECIFIC_AURA_RETRIBUTION           = 0x20,
    SPECIFIC_AURA_CRUSADER              = 0x40,
    SPECIFIC_AURA_MY_AURA               = 0x80,
    SPECIFIC_AURA_ALL_AUTOUSE           = (SPECIFIC_AURA_DEVOTION | SPECIFIC_AURA_CONCENTRATION | SPECIFIC_AURA_RETRIBUTION | \
                                            SPECIFIC_AURA_FIRE_RES | SPECIFIC_AURA_FROST_RES | SPECIFIC_AURA_SHADOW_RES),

    FLASH_OF_LIGHT_HEAL_PERIODIC        = 66922,

    ENLIGHTENMENT_BUFF                  = 43837,
    INFUSION_OF_LIGHT_BUFF              = 54149,//rank 2
    THE_ART_OF_WAR_BUFF                 = 59578,//rank 2
    //FORBEARANCE_AURA                    = 25771,

    LIGHTS_GRACE_BUFF                   = 31834,

    SEAL_OF_JUSTICE_STUN_AURA           = 20170,
    JUDGEMENTS_OF_THE_JUST_AURA         = 68055, //melee attack speed reduce

    //JUDGEMENT_OF_LIGHT_AURA             = 20185,
    JUDGEMENT_OF_WISDOM_AURA            = 20186,
    //JUDGEMENT_OF_JUSTICE_AURA           = 20184,

    GREATER_BLESSING_OF_MIGHT_1         = 25782,
    GREATER_BLESSING_OF_WISDOM_1        = 25894,
    GREATER_BLESSING_OF_KINGS_1         = 25898,
    GREATER_BLESSING_OF_SANCTUARY_1     = 25899,
    BATTLESHOUT_1                       = 6673,

    HOLY_SHOCK_HEAL_1                   = 25914,
    ARDENT_DEFENDER_HEAL                = 66235,
    JUDGEMENT_OF_COMMAND_DAMAGE         = 20467,
    SPIRITUAL_ATTUNEMENT_ENERGIZE       = 31786,
    SACRED_SHIELD_AURA_TRIGGERED        = 58597,

    AVENGING_WRATH_MARKER_SPELL         = 61987,
    IMMUNITY_SHIELD_MARKER_SPELL        = 61988,

    IMPROVED_DEVOTION_AURA_SPELL        = 63514
};

static const uint32 Paladin_spells_damage_arr[] =
{ AVENGERS_SHIELD_1, CONSECRATION_1, CRUSADER_STRIKE_1, DIVINE_STORM_1, EXORCISM_1, JUDGEMENT_OF_LIGHT_1,
JUDGEMENT_OF_WISDOM_1, JUDGEMENT_OF_JUSTICE_1, HAMMER_OF_THE_RIGHTEOUS_1, HAMMER_OF_WRATH_1, HOLY_SHIELD_1,
HOLY_SHOCK_1, HOLY_WRATH_1, SHIELD_OF_RIGHTEOUSNESS_1, HAND_OF_RECKONING_1 };

static const uint32 Paladin_spells_cc_arr[] =
{ HAMMER_OF_JUSTICE_1, HOLY_WRATH_1, REPENTANCE_1, TURN_EVIL_1 };

static const uint32 Paladin_spells_heal_arr[] =
{ BEACON_OF_LIGHT_1, FLASH_OF_LIGHT_1, HOLY_LIGHT_1, HOLY_SHOCK_1, LAY_ON_HANDS_1 };

static const uint32 Paladin_spells_support_arr[] =
{ /*DEVOTION_AURA_1, CONCENTRATION_AURA_1, FIRE_RESISTANCE_AURA_1, FROST_RESISTANCE_AURA_1, SHADOW_RESISTANCE_AURA_1,
RETRIBUTION_AURA_1, CRUSADER_AURA_1, */AURA_MASTERY_1, AVENGING_WRATH_1, BLESSING_OF_MIGHT_1, BLESSING_OF_WISDOM_1,
BLESSING_OF_KINGS_1, BLESSING_OF_SANCTUARY_1, CLEANSE_1, DIVINE_FAVOR_1, DIVINE_ILLUMINATION_1, DIVINE_INTERVENTION_1,
DIVINE_PLEA_1, DIVINE_PROTECTION_1, DIVINE_SACRIFICE_1, DIVINE_SHIELD_1, HAND_OF_FREEDOM_1, HAND_OF_PROTECTION_1,
HAND_OF_RECKONING_1, HAND_OF_SACRIFICE_1, HAND_OF_SALVATION_1, HOLY_SHIELD_1, PURIFY_1, REDEMPTION_1,
RIGHTEOUS_DEFENSE_1, RIGHTEOUS_FURY_1, SACRED_SHIELD_1, SEAL_OF_RIGHTEOUSNESS_1, SEAL_OF_JUSTICE_1, SEAL_OF_LIGHT_1,
SEAL_OF_WISDOM_1, SEAL_OF_COMMAND_1, SEAL_OF_VENGEANCE_1, SEAL_OF_CORRUPTION_1 };

static const std::vector<uint32> Paladin_spells_damage(FROM_ARRAY(Paladin_spells_damage_arr));
static const std::vector<uint32> Paladin_spells_cc(FROM_ARRAY(Paladin_spells_cc_arr));
static const std::vector<uint32> Paladin_spells_heal(FROM_ARRAY(Paladin_spells_heal_arr));
static const std::vector<uint32> Paladin_spells_support(FROM_ARRAY(Paladin_spells_support_arr));

class paladin_bot : public CreatureScript
{
public:
    paladin_bot() : CreatureScript("paladin_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new paladin_botAI(creature);
    }
/*
    bool OnGossipHello(Player* player, Creature* creature)
    {
        return creature->GetBotAI()->OnGossipHello(player, 0);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelect(player, creature, sender, action);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelectCode(player, creature, sender, action, code);
        return true;
    }
*/
    struct paladin_botAI : public bot_ai
    {
        paladin_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_PALADIN;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        void CheckBeacon(uint32 diff)
        {
            if (checkBeaconTimer > diff || !IsSpellReady(BEACON_OF_LIGHT_1, diff) ||
                !HasRole(BOT_ROLE_HEAL|BOT_ROLE_RANGED) || IsCasting() || Rand() > 15)
                return;

            checkBeaconTimer = urand(2000, 5000);

            if (FindAffectedTarget(GetSpell(BEACON_OF_LIGHT_1), me->GetGUID(), 60, 3))
                return;

            //find tank
            //stacks
            if (Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup())
            {
                std::set<Unit*> tanks;
                for (Unit* member : BotMgr::GetAllGroupMembers(gr))
                {
                    if (me->GetMap() == member->FindMap() && member->IsAlive() && member->IsInCombat() && IsTank(member) &&
                        (!member->getAttackers().empty() || GetHealthPCT(member) < 90) &&
                        !member->GetAuraEffect(SPELL_AURA_PERIODIC_TRIGGER_SPELL, SPELLFAMILY_PALADIN, 0x0, 0x1000000, 0x0, me->GetGUID()))
                        tanks.insert(member);
                }

                if (tanks.empty())
                    return;

                Unit* target = tanks.size() == 1 ? *tanks.begin() : Trinity::Containers::SelectRandomContainerElement(tanks);
                if (doCast(target, GetSpell(BEACON_OF_LIGHT_1)))
                    return;
            }
        }

        void CheckSacrifice(uint32 diff)
        {
            if (!IsSpellReady(DIVINE_SACRIFICE_1, diff) || IAmFree() || me->IsMounted() ||
                IsTank() || Feasting() || !CanBlock() || IsCasting() || Rand() > 25 || GetHealthPCT(me) < 60)
                return;

            Group const* gr = master->GetGroup();
            if (!gr)
            {
                if (master->IsAlive() && GetHealthPCT(master) < 75 && me->GetDistance(master) < 30 && !master->getAttackers().empty() &&
                    !master->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELLFAMILY_PALADIN, 3837, EFFECT_0))
                {
                    if (doCast(me, GetSpell(DIVINE_SACRIFICE_1)))
                        return;
                }
            }
            else
            {
                uint8 attacked = 0;
                for (Unit const* member : BotMgr::GetAllGroupMembers(gr))
                {
                    if (me->GetMap() == member->FindMap() && member->IsAlive() &&
                        !(member->IsNPCBot() && member->ToCreature()->IsTempBot()) &&
                        me->GetDistance(member) < 30 && !member->getAttackers().empty() &&
                        !member->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELLFAMILY_PALADIN, 3837, EFFECT_0))
                    {
                        if (++attacked > 3)
                            break;
                    }
                }
                if (attacked > 3 && doCast(me, GetSpell(DIVINE_SACRIFICE_1)))
                    return;
            }

            SetSpellCooldown(DIVINE_SACRIFICE_1, 1000); //fail
        }

        void CheckHandOfSacrifice(uint32 diff)
        {
            if (!IsSpellReady(HAND_OF_SACRIFICE_1, diff) || IAmFree() || me->IsMounted() ||
                IsTank() || Feasting() || !CanBlock() || IsCasting() || Rand() > 25 || GetHealthPCT(me) < 50)
                return;

            Group const* gr = master->GetGroup();
            if (!gr)
            {
                if (master->IsAlive() && me->GetDistance(master) < 30 && !master->getAttackers().empty() &&
                    (master->getAttackers().size() > 2 || GetHealthPCT(master) < 50) &&
                    !master->GetAuraEffect(SPELL_AURA_SPLIT_DAMAGE_PCT, SPELLFAMILY_PALADIN, 0x2000, 0x0, 0x0))
                {
                    if (doCast(master, GetSpell(HAND_OF_SACRIFICE_1)))
                        return;
                }
            }
            else
            {
                Unit* u = nullptr;
                for (Unit* member : BotMgr::GetAllGroupMembers(gr))
                {
                    if (me->GetMap() == member->FindMap() && member->IsAlive() && me->GetDistance(member) < 30 &&
                        !(member->IsNPCBot() && member->ToCreature()->IsTempBot()) &&
                        (member->getAttackers().size() > 2 || GetHealthPCT(member) < 50) &&
                        !member->GetAuraEffect(SPELL_AURA_SPLIT_DAMAGE_PCT, SPELLFAMILY_PALADIN, 0x2000, 0x0, 0x0))
                    {
                        u = member;
                        break;
                    }
                }

                if (u && doCast(u, GetSpell(HAND_OF_SACRIFICE_1)))
                    return;
            }

            SetSpellCooldown(HAND_OF_SACRIFICE_1, 2000); //fail
        }

        void ShieldGroup(uint32 diff)
        {
            if (checkShieldTimer > diff || !IsSpellReady(SACRED_SHIELD_1, diff) ||
                me->IsMounted() || Feasting() || IsCasting() || Rand() > 50)
                return;

            checkShieldTimer = 1500;

            if (IsTank())
            {
                if (Rand() > 15)
                    return;
            }
            else if (!HasRole(BOT_ROLE_HEAL) && Rand() > 10)
                return;

            if (FindAffectedTarget(GetSpell(SACRED_SHIELD_1), me->GetGUID(), 70, 3))
                return;

            Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup();
            Unit* target = nullptr;
            if (!gr)
            {
                Unit* u = master;
                if (u->IsAlive() && u->IsInCombat() && IsTank(u) && me->GetDistance(u) < 30 &&
                    !u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                    target = u;

                if (!target && !IAmFree())
                {
                    BotMap const* map = master->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                    {
                        u = itr->second;
                        if (u != me && IsTank())
                            continue;
                        if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() ||
                            u->ToCreature()->IsTempBot() || !IsTank(u) || me->GetDistance(u) > 30 ||
                            u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                            continue;

                        target = u;
                        break;
                    }
                }
            }
            else
            {
                std::set<Unit*> targets;
                std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
                for (uint8 i = 0; i < 4 && !targets.empty(); ++i)
                {
                    for (Unit* member : members)
                    {
                        if (!(!(i & 1) ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                            !member->IsAlive() || !member->IsInCombat() || me->GetDistance(member) > 30 ||
                            (i < 2 ? !IsTank(member) : member->getAttackers().empty()) ||
                            (member->IsNPCBot() && member->ToCreature()->IsTempBot()) ||
                            member->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                            continue;
                        targets.insert(member);
                    }
                }
                if (!targets.empty())
                    target = targets.size() == 1u ? *targets.begin() : Trinity::Containers::SelectRandomContainerElement(targets);
            }

            if (target && doCast(target, GetSpell(SACRED_SHIELD_1)))
                return;
        }

        void HOPGroup(uint32 diff)
        {
            if (!IsSpellReady(HAND_OF_PROTECTION_1, diff) || me->IsMounted() || Feasting() || IsCasting() || Rand() > 30)
                return;

            Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup();
            if (!gr)
            {
                if (me->GetMap() == master->FindMap())
                {
                    if (HOPTarget(master))
                    {}
                    if (!IAmFree() && HOPTarget(me))
                    {}
                }
            }
            else
            {
                std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
                for (uint8 i = 0; i < 2; ++i)
                {
                    for (Unit* member : members)
                    {
                        if (!(i == 0 ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                            !member->IsAlive() || !member->IsInCombat() || me->GetDistance(member) > 30 || IsTank(member) ||
                            (member->IsNPCBot() && member->ToCreature()->IsTempBot()) ||
                            member->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                            continue;
                        if (HOPTarget(member))
                            return;
                    }
                }
            }
        }

        bool HOPTarget(Unit* target)
        {
            if ((target->IsPlayer() ? target->GetClass() : target->ToCreature()->GetBotClass()) == BOT_CLASS_PALADIN)
                return false; //paladins should use their own damn bubble
            if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 1) || target->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
                return false; //immune to physical (hop or smth is present)
            if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 25))
                return false; //forbearance
            if (target->getAttackers().empty())
                return false; //HOP only saves from physical, these aoe are rare and on bosses they are ultimate anyway

            if (GetHealthPCT(target) < 15 + 5*(uint32)target->getAttackers().size())
            {
                me->InterruptNonMeleeSpells(false);
                if (doCast(target, GetSpell(HAND_OF_PROTECTION_1)))
                {
                    if (target->IsPlayer())
                        ReportSpellCast(HAND_OF_PROTECTION_1, LocalizedNpcText(target->ToPlayer(), BOT_TEXT__ON_YOU), target->ToPlayer());

                    if (!IAmFree() && target->GetGUID() != master->GetGUID())
                        ReportSpellCast(HAND_OF_PROTECTION_1, LocalizedNpcText(master, BOT_TEXT__ON_) + target->GetName() + '!', master);
                }
                return true;
            }

            return false;
        }

        void HOFGroup(uint32 diff)
        {
            if (!IsSpellReady(HAND_OF_FREEDOM_1, diff) || me->IsMounted() || Feasting() || IsCasting() || Rand() > 20)
                return;

            Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup();
            if (!gr)
            {
                if (me->GetMap() == master->FindMap())
                {
                    if (HOFTarget(master))
                    {}
                    if (!IAmFree() && HOFTarget(me))
                    {}
                }
            }
            else
            {
                std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
                for (uint8 i = 0; i < 2; ++i)
                {
                    for (Unit* member : members)
                    {
                        if (!(i == 0 ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                            !member->IsAlive() || me->GetDistance(member) > 30 || (member->IsNPCBot() && member->ToCreature()->IsTempBot()))
                            continue;
                        if (HOFTarget(member))
                            return;
                    }
                }
            }
        }

        bool HOFTarget(Unit* target)
        {
            const bool canUnstun = me->GetLevel() >= 35 && GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION;
            if (target->HasAuraType(SPELL_AURA_MECHANIC_IMMUNITY))
            {
                if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 11) &&
                    target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 7))
                    return false; //immune to root and snares
                if (canUnstun && target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 12))
                    return false; //immune to stuns
            }

            SpellInfo const* spellInfo;
            AuraApplication const* app;
            Unit::AuraApplicationMap const& auras = target->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator i = auras.begin(); i != auras.end(); ++i)
            {
                app = i->second;
                if (!app || app->IsPositive() || app->GetBase()->IsPassive() || app->GetBase()->GetDuration() < 2000)
                    continue;
                spellInfo = app->GetBase()->GetSpellInfo();
                if (spellInfo->Attributes & SPELL_ATTR0_HIDDEN_CLIENTSIDE) continue;
                //if (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR) continue;
                if (spellInfo->GetSpellMechanicMaskByEffectMask(app->GetEffectMask()) &
                    ((1<<MECHANIC_SNARE) | (1<<MECHANIC_ROOT) | (!canUnstun ? 0 : (1<<MECHANIC_STUN))))
                {
                    uint32 dispel = spellInfo->Dispel;
                    uint32 spell;
                    //Hand of Freedom is level 12, Purify is 8, Cleanse is 42
                    if (!GetSpell(CLEANSE))
                        spell = (dispel == DISPEL_DISEASE || dispel == DISPEL_POISON) ?
                        GetSpell(PURIFY_1) : GetSpell(HAND_OF_FREEDOM_1);
                    else
                        spell = (dispel == DISPEL_MAGIC || dispel == DISPEL_DISEASE || dispel == DISPEL_POISON) ?
                        GetSpell(CLEANSE_1) : GetSpell(HAND_OF_FREEDOM_1);

                    if (doCast(target, spell))
                        return true;
                }
            }
            return false;
        }

        void HOSGroup(uint32 diff)
        {
            if (!IsSpellReady(HAND_OF_SALVATION_1, diff) || IsCasting() || Rand() > 40)
                return;

            //Glyph of Salvation
            if (me->GetLevel() >= 26 && (IAmFree() || IsTank()))
            {
                if (!me->getAttackers().empty() && GetHealthPCT(me) < std::max<int32>(80 - 5 * me->getAttackers().size(), 25))
                {
                    if (doCast(me, GetSpell(HAND_OF_SALVATION_1)))
                    {}
                }
                return;
            }

            if (IAmFree())
                return;

            Group const* gr = master->GetGroup();
            if (!gr)
                 return;

            std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
            for (uint8 i = 0; i < 2; ++i)
            {
                for (Unit* member : members)
                {
                    if (!(i == 0 ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                        !member->IsInCombat() || IsTank(member) || me->GetDistance(member) > 30 ||
                        (IsTankingClass(i == 0 ? member->GetClass() : member->ToCreature()->GetBotClass()) && !me->GetMap()->IsRaid()) ||
                        (member->IsNPCBot() && member->ToCreature()->IsTempBot()) ||
                        member->HasAuraTypeWithFamilyFlags(SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE, SPELLFAMILY_PALADIN, 0x100))
                        continue;
                    if (HOSTarget(member))
                        return;
                }
            }
        }

        bool HOSTarget(Unit* target)
        {
            for (Unit* attacker : target->getAttackers())
            {
                if (attacker->CanHaveThreatList() && attacker->getAttackers().size() >= 3 && target->GetDistance(attacker) < 15)
                {
                    if (doCast(target, GetSpell(HAND_OF_SALVATION_1)))
                        return true;
                    break; //do not try more than once on the same target
                }
            }
            return false;
        }

        bool HealTarget(Unit* target, uint32 diff) override
        {
            if (!target || !target->IsAlive() || target->GetShapeshiftForm() == FORM_SPIRITOFREDEMPTION || me->GetDistance(target) > 40)
                return false;
            uint8 hp = GetHealthPCT(target);
            if (hp > GetHealHpPctThreshold())
                return false;
            bool pointed = IsPointedHealTarget(target);
            if (hp > 90 && !(pointed && me->GetMap()->IsRaid()) &&
                (!target->IsInCombat() || target->getAttackers().empty() || !IsTank(target) || !me->GetMap()->IsRaid()))
                return false;
            //try to preserve heal if Divine Plea is active
            if (hp > 50 && me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x0, 0x1))
                return false;

            int32 hps = GetHPS(target);
            int32 xphp = target->GetHealth() + hps * 2.5f;
            int32 hppctps = int32(hps * 100.f / float(target->GetMaxHealth()));
            int32 xphploss = xphp > int32(target->GetMaxHealth()) ? 0 : abs(int32(xphp - target->GetMaxHealth()));
            int32 xppct = hp + hppctps * 2.5f;
            if (xppct >= 95 && hp >= 25 && !pointed)
                return false;

            //Lay on Hands
            if (IsSpellReady(LAY_ON_HANDS_1, diff, false) && (target != me || shieldDelayTimer <= diff) &&
                (target->IsInCombat() || !target->getAttackers().empty()) && Rand() < 80 && hp <= 20 && xppct <=0 &&
                !target->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
            {
                me->InterruptNonMeleeSpells(false);
                if (doCast(target, GetSpell(LAY_ON_HANDS_1)))
                {
                    if (target->GetTypeId() == TYPEID_PLAYER)
                        ReportSpellCast(LAY_ON_HANDS_1, LocalizedNpcText(target->ToPlayer(), BOT_TEXT__ON_YOU), target->ToPlayer());

                    if (!IAmFree() && target != master)
                    {
                        std::string msg = target == me ? LocalizedNpcText(master, BOT_TEXT__ON_MYSELF) : (LocalizedNpcText(master, BOT_TEXT__ON_) + target->GetName() + '!');
                        ReportSpellCast(LAY_ON_HANDS_1, msg, master);
                    }
                    return true;
                }
            }

            //Holy Shock
            if (IsSpellReady(HOLY_SHOCK_1, diff, false) && !target->IsCharmed() && !target->isPossessed() &&
                xphploss > _heals[HOLY_SHOCK_1])
            {
                me->InterruptNonMeleeSpells(false);
                if (hp < 30 && IsSpellReady(DIVINE_FAVOR_1, diff, false) && !target->getAttackers().empty())
                    if (doCast(me, GetSpell(DIVINE_FAVOR_1)))
                    {}
                if (doCast(target, GetSpell(HOLY_SHOCK_1)))
                    return true;
            }

            if (IsCasting()) return false;

            Unit const* u = target->GetVictim();
            bool tanking = u && IsTank(target) && u->ToCreature() && u->ToCreature()->isWorldBoss();

            if (IsSpellReady(DIVINE_ILLUMINATION_1, diff, false) && GetManaPCT(me) <= 50 && Rand() < 50 + 50*tanking)
                if (doCast(me, GetSpell(DIVINE_ILLUMINATION_1)))
                {}

            //Holy Light
            if (IsSpellReady(HOLY_LIGHT_1, diff) && (xppct > 15 || !GetSpell(FLASH_OF_LIGHT_1)) &&
                xphploss > _heals[HOLY_LIGHT_1])
            {
                //Aura Mastery
                if (hp < 60 && _aura == CONCENTRATIONAURA && IsSpellReady(AURA_MASTERY_1, diff, false) && Rand() < 90 &&
                    ((!me->getAttackers().empty() && (*me->getAttackers().begin())->GetTypeId() == TYPEID_PLAYER) ||
                    me->GetMap()->Instanceable() || tanking))
                    if (doCast(me, GetSpell(AURA_MASTERY_1)))
                    {}
                if (doCast(target, GetSpell(HOLY_LIGHT_1)))
                    return true;
            }
            //Flash of Light
            if (IsSpellReady(FLASH_OF_LIGHT_1, diff) && (tanking || xphploss > _heals[FLASH_OF_LIGHT_1]))
            {
                if (doCast(target, GetSpell(FLASH_OF_LIGHT_1)))
                    return true;
            }

            return false;
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_ai::JustDied(u); }

        void BreakCC(uint32 diff) override
        {
            if (me->GetLevel() >= 35 && GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION && IsSpellReady(HAND_OF_FREEDOM_1, diff) && Rand() < 30 && me->HasAuraWithMechanic(1<<MECHANIC_STUN))
            {
                if (me->IsMounted())
                    me->RemoveAurasByType(SPELL_AURA_MOUNTED);
                if (doCast(me, GetSpell(HAND_OF_FREEDOM_1)))
                    return;
            }
            bot_ai::BreakCC(diff);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            if (IsPotionReady())
            {
                if (GetManaPCT(me) < 30)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 60)
                    DrinkPotion(false);
            }
            else if (GetManaPCT(me) < 40 && IsSpellReady(DIVINE_PLEA_1, diff) && Rand() < 30 &&
                !me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x80004000, 0x1))
            {
                if (doCast(me, GetSpell(DIVINE_PLEA_1)))
                    return;
            }

            CheckRacials(diff);

            HOPGroup(diff);
            CheckBeacon(diff);

            if (me->GetMap()->IsRaid())
            {
                CureGroup(GetSpell(CLEANSE), diff);
                BuffAndHealGroup(diff);
                CheckHandOfSacrifice(diff);
                ShieldGroup(diff);
            }
            else
            {
                BuffAndHealGroup(diff);
                CheckHandOfSacrifice(diff);
                ShieldGroup(diff);
                CureGroup(GetSpell(CLEANSE), diff);
            }

            CheckSacrifice(diff);
            HOFGroup(diff);
            HOSGroup(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            CheckSeal(diff);
            CheckAura(diff);

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
                return;

            Repentance(diff);
            Counter(diff);
            TurnEvil(diff);

            CheckDivineIntervention(diff);
            if (!me->IsAlive())
                return;

            if (IsCasting())
                return;

            CheckUsableItems(diff);

            DoNormalAttack(diff);
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            ResurrectGroup(GetSpell(REDEMPTION_1));
        }

        void CheckSeal(uint32 diff)
        {
            if (checkSealTimer > diff || GC_Timer > diff || me->IsMounted() ||
                IsCasting() || Feasting() || Rand() > 30)
                return;

            checkSealTimer = 10000;

            Unit const* victim = me->GetVictim();

            uint32 COMMAND = GetSpell(SEAL_OF_COMMAND_1);
            uint32 LIGHT = GetSpell(SEAL_OF_LIGHT_1);
            uint32 RIGHT = GetSpell(SEAL_OF_RIGHTEOUSNESS_1);
            uint32 WISDOM = GetSpell(SEAL_OF_WISDOM_1);
            uint32 JUSTICE = GetSpell(SEAL_OF_JUSTICE_1);
            uint32 VENGEANCE = (me->GetRaceMask() & RACEMASK_ALLIANCE) ? GetSpell(SEAL_OF_VENGEANCE_1) : GetSpell(SEAL_OF_CORRUPTION_1);

            if (VENGEANCE && victim &&
                (victim->GetMaxHealth() > me->GetMaxHealth() * (2 + victim->getAttackers().size() / 2) ||
                victim->GetClass() == CLASS_ROGUE))
                COMMAND = VENGEANCE;

            uint32 SEAL = 0;

            if (IsMelee() && GetManaPCT(me) < 20 && WISDOM)
                SEAL = WISDOM;
            else if (IsTank())
            {
                if (JUSTICE && me->getAttackers().size() > 1)
                    JUSTICE = 0;
                if (JUSTICE && victim)
                {
                    Creature const* cre = victim->ToCreature();
                    if (cre && cre->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL &&
                        (cre->GetCreatureTemplate()->MechanicImmuneMask & (1<<(MECHANIC_STUN-1))))
                        JUSTICE = 0;
                }
                SEAL = COMMAND ? COMMAND : JUSTICE ? JUSTICE : RIGHT;
            }
            else if (HasRole(BOT_ROLE_DPS))
            {
                SEAL = WISDOM && HasRole(BOT_ROLE_HEAL) ? WISDOM : COMMAND ? COMMAND : RIGHT;
            }
            else if (HasRole(BOT_ROLE_HEAL))
                SEAL = WISDOM ? WISDOM : LIGHT ? LIGHT : RIGHT;

            if (SEAL && !me->HasAura(SEAL))
                if (doCast(me, SEAL))
                    return;
        }

        void CheckAura(uint32 diff)
        {
            if (checkAuraTimer > diff || GC_Timer > diff || IAmFree() || IsCasting() ||
                /*me->GetExactDist(master) > 40 || me->IsMounted() || Feasting() || */Rand() > 20)
                return;

            checkAuraTimer = urand(3000, 6000);

            //7 paladins in group?
            uint32 DEVOTION_AURA = GetSpell(DEVOTION_AURA_1);
            uint32 CONCENTRATION_AURA = GetSpell(CONCENTRATION_AURA_1);
            uint32 FIRE_RESISTANCE_AURA = GetSpell(FIRE_RESISTANCE_AURA_1);
            uint32 FROST_RESISTANCE_AURA = GetSpell(FROST_RESISTANCE_AURA_1);
            uint32 SHADOW_RESISTANCE_AURA = GetSpell(SHADOW_RESISTANCE_AURA_1);
            uint32 RETRIBUTION_AURA = GetSpell(RETRIBUTION_AURA_1);
            //uint32 CRUSADER_AURA = GetSpell(CRUSADER_AURA_1);

            bool pureHealer = GetSpec() == BOT_SPEC_PALADIN_HOLY;
            bool isProt = GetSpec() == BOT_SPEC_PALADIN_PROTECTION;

            std::map<uint32 /*baseid*/, uint32 /*curid*/> idMap;
            uint32 mask = _getAurasMask(idMap);

            //for Aura Mastery allow every pure healer paladin to have their own C aura
            //SPECIFIC_AURA_MY_AURA check still works so no spam
            if (pureHealer)
                mask &= ~SPECIFIC_AURA_CONCENTRATION;

            //if (CRUSADER_AURA && !(mask & SPECIFIC_AURA_CRUSADER) &&
            //    (master->IsMounted() || me->IsMounted()))
            //{
            //    if (doCast(me, CRUSADER_AURA))
            //        return;
            //}

            //Has own aura or has all auras
            if (mask & SPECIFIC_AURA_MY_AURA)
                return;
            else if ((mask & SPECIFIC_AURA_ALL_AUTOUSE) == SPECIFIC_AURA_ALL_AUTOUSE)
                return;

            //TODO: priority?
            if (DEVOTION_AURA &&
                (!(mask & SPECIFIC_AURA_DEVOTION) || idMap[DEVOTION_AURA_1] < DEVOTION_AURA) &&
                (!RETRIBUTION_AURA || IsTank(master) || isProt))
            {
                if (doCast(me, DEVOTION_AURA))
                    return;
            }
            if (CONCENTRATION_AURA && !(mask & SPECIFIC_AURA_CONCENTRATION) &&
                (master->GetClass() == BOT_CLASS_MAGE || master->GetClass() == BOT_CLASS_PRIEST ||
                master->GetClass() == BOT_CLASS_WARLOCK || master->GetClass() == BOT_CLASS_DRUID ||
                (!IAmFree() && master->GetClass() == BOT_CLASS_PALADIN) || pureHealer))
            {
                if (doCast(me, CONCENTRATION_AURA))
                    return;
            }
            if (RETRIBUTION_AURA &&
                (!(mask & SPECIFIC_AURA_RETRIBUTION) || idMap[RETRIBUTION_AURA_1] < RETRIBUTION_AURA) &&
                (IsMeleeClass(master->GetClass()) || IsMelee()))
            {
                if (doCast(me, RETRIBUTION_AURA))
                    return;
            }
            if (FIRE_RESISTANCE_AURA &&
                (!(mask & SPECIFIC_AURA_FIRE_RES) || idMap[FIRE_RESISTANCE_AURA_1] < FIRE_RESISTANCE_AURA))
            {
                if (doCast(me, FIRE_RESISTANCE_AURA))
                    return;
            }
            if (FROST_RESISTANCE_AURA &&
                (!(mask & SPECIFIC_AURA_FROST_RES) || idMap[FROST_RESISTANCE_AURA_1] < FROST_RESISTANCE_AURA))
            {
                if (doCast(me, FROST_RESISTANCE_AURA))
                    return;
            }
            if (SHADOW_RESISTANCE_AURA &&
                (!(mask & SPECIFIC_AURA_SHADOW_RES) || idMap[SHADOW_RESISTANCE_AURA_1] < SHADOW_RESISTANCE_AURA))
            {
                if (doCast(me, SHADOW_RESISTANCE_AURA))
                    return;
            }
        }

        bool BuffTarget(Unit* target, uint32 /*diff*/) override
        {
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;

            if (target == me)
            {
                if (uint32 rFury = GetSpell(RIGHTEOUS_FURY_1))
                {
                    if (IsTank())
                    {
                        if (!me->HasAura(rFury) && doCast(me, rFury))
                            return true;
                    }
                    else if (me->HasAura(rFury))
                        me->RemoveAurasDueToSpell(rFury);
                }
            }

            uint32 mask = _getBlessingsMask(target);

            //already has my blessing
            if (mask & SPECIFIC_BLESSING_MY_BLESSING)
                return false;

            uint32 BLESSING_OF_WISDOM = GetSpell(BLESSING_OF_WISDOM_1);
            uint32 BLESSING_OF_KINGS = GetSpell(BLESSING_OF_KINGS_1);
            uint32 BLESSING_OF_SANCTUARY = GetSpell(BLESSING_OF_SANCTUARY_1);
            uint32 BLESSING_OF_MIGHT = GetSpell(BLESSING_OF_MIGHT_1);

            bool wisdom = (mask & SPECIFIC_BLESSING_WISDOM);
            bool kings = (mask & SPECIFIC_BLESSING_KINGS);
            bool sanctuary = (mask & SPECIFIC_BLESSING_SANCTUARY);
            bool might = (mask & SPECIFIC_BLESSING_MIGHT);

            if (IsTank(target))
            {
                if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                    return true;
                else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                    return true;
                else if (BLESSING_OF_WISDOM && !wisdom && target->GetMaxPower(POWER_MANA) > 1 && doCast(target, BLESSING_OF_WISDOM))
                    return true;
                else if (BLESSING_OF_MIGHT && !might && doCast(target, BLESSING_OF_MIGHT))
                    return true;

                return false;
            }

            uint8 Class = 0;
            if (target->GetTypeId() == TYPEID_PLAYER)
                Class = target->GetClass();
            else if (Creature* cre = target->ToCreature())
                Class = cre->GetBotAI() ? cre->GetBotAI()->GetBotClass() : cre->GetClass();

            switch (Class)
            {
                case BOT_CLASS_BM:
                case BOT_CLASS_SPHYNX:
                case BOT_CLASS_DREADLORD:
                case BOT_CLASS_SPELLBREAKER:
                case BOT_CLASS_DARK_RANGER:
                case BOT_CLASS_NECROMANCER:
                case BOT_CLASS_SEA_WITCH:
                case BOT_CLASS_CRYPT_LORD:
                    if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_MIGHT && !might && doCast(target, BLESSING_OF_MIGHT))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    break;
                case CLASS_PRIEST:
                case CLASS_MAGE:
                case CLASS_WARLOCK:
                    if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_WISDOM && !wisdom && doCast(target, BLESSING_OF_WISDOM))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    break;
                case CLASS_DEATH_KNIGHT:
                case CLASS_WARRIOR:
                case CLASS_PALADIN:
                case CLASS_ROGUE:
                case CLASS_HUNTER:
                case CLASS_SHAMAN:
                    if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_MIGHT && !might && doCast(target, BLESSING_OF_MIGHT))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    else if (BLESSING_OF_WISDOM && !wisdom && target->GetPowerType() == POWER_MANA && doCast(target, BLESSING_OF_WISDOM))
                        return true;
                    break;
                default:
                    if (BLESSING_OF_KINGS && !kings && doCast(target, BLESSING_OF_KINGS))
                        return true;
                    else if (BLESSING_OF_WISDOM && !wisdom && target->GetMaxPower(POWER_MANA) > 1 && doCast(target, BLESSING_OF_WISDOM))
                        return true;
                    else if (BLESSING_OF_SANCTUARY && !sanctuary && doCast(target, BLESSING_OF_SANCTUARY))
                        return true;
                    else if (BLESSING_OF_MIGHT && !might && doCast(target, BLESSING_OF_MIGHT))
                        return true;
                    break;
            }
            return false;
        }

        void Repentance(uint32 diff, Unit* target = nullptr)
        {
            if (target)
            {
                if (IsSpellReady(REPENTANCE_1, diff) && doCast(target, GetSpell(REPENTANCE_1)))
                    return;
            }
            else if (IsSpellReady(REPENTANCE_1, diff))
            {
                Unit* u = FindStunTarget();
                if (u && u->GetVictim() != me && doCast(u, GetSpell(REPENTANCE_1)))
                    return;
            }
        }

        void Counter(uint32 diff)
        {
            if (IsCasting())
                return;
            if (Rand() > 60)
                return;

            Unit* target = IsSpellReady(REPENTANCE_1, diff) ? FindCastingTarget(20, 0, REPENTANCE_1) : nullptr;
            if (target)
                Repentance(diff, target); //first check repentance
            if (!target && IsSpellReady(TURN_EVIL_1, diff))
            {
                target = FindCastingTarget(20, 0, TURN_EVIL_1);
                if (target && doCast(target, GetSpell(TURN_EVIL_1)))
                    return;
            }
            if (!target && IsSpellReady(HOLY_WRATH_1, diff, false) && HasRole(BOT_ROLE_DPS))
            {
                target = FindCastingTarget(8, 0, TURN_EVIL_1); //here we check target as with turn evil cuz of same requirements
                if (target && doCast(me, GetSpell(HOLY_WRATH_1)))
                    return;
            }
            if (!target && IsSpellReady(HAMMER_OF_JUSTICE_1, diff, false))
            {
                target = FindCastingTarget(10, 0, HAMMER_OF_JUSTICE_1);
                if (target && doCast(target, GetSpell(HAMMER_OF_JUSTICE_1)))
                {}
            }
        }

        void TurnEvil(uint32 diff)
        {
            if (!IsSpellReady(TURN_EVIL_1, diff) || IsCasting() || Rand() > 50 ||
                FindAffectedTarget(GetSpell(TURN_EVIL_1), me->GetGUID(), 50))
                return;
            Unit* target = FindUndeadCCTarget(20, TURN_EVIL_1);
            if (target &&
                (target != me->GetVictim() || GetHealthPCT(me) < 70 || target->GetVictim() == master) &&
                doCast(target, GetSpell(TURN_EVIL_1)))
                return;
            else
            {
                for (Unit* mtar : { opponent, disttarget })
                {
                    if (mtar && (mtar->GetCreatureTypeMask() & CREATURE_TYPEMASK_DEMON_OR_UNDEAD) && !CCed(mtar) &&
                        mtar->GetVictim() && !IsTank(mtar->GetVictim()) && mtar->GetVictim() != me &&
                        GetHealthPCT(me) < 90 &&
                        doCast(mtar, GetSpell(TURN_EVIL_1)))
                        return;
                }
            }
        }

        void CheckDivineIntervention(uint32 diff)
        {
            if (!IsSpellReady(DIVINE_INTERVENTION_1, diff, !IsCasting()) || IAmFree() || IsTank() ||
                GetManaPCT(me) > 10 || Rand() > 20)
                return;

            std::list<Unit*> players;

            if (master->IsAlive() && !master->getAttackers().empty() && GetHealthPCT(master) < 15 &&
                !master->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
                players.push_back(master);
            if (Group const* gr = master->GetGroup())
            {
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* pl = itr->GetSource();
                    if (!pl || pl == master || !pl->IsInWorld() || me->GetMap() != pl->FindMap() ||
                        !pl->IsAlive() || pl->getAttackers().empty() || GetHealthPCT(pl) > 15 ||
                        pl->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
                        continue;

                    players.push_back(pl);
                }
            }

            if (players.empty())
                return;

            Unit* target = players.size() == 1 ? players.front() : Trinity::Containers::SelectRandomContainerElement(players);
            if (doCast(target, GetSpell(DIVINE_INTERVENTION_1)))
                return;
        }

        void DoNormalAttack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, IsMelee());

            CheckAttackState();
            if (!me->IsAlive() || !mytar->IsAlive())
                return;

            MoveBehind(mytar);

            //Divine Shield
            if (IsSpellReady(DIVINE_SHIELD_1, diff) && shieldDelayTimer <= diff && (IAmFree() || !IsTank()) &&
                Rand() < 80 && !me->getAttackers().empty() && GetHealthPCT(me) < 25)
            {
                if (doCast(me, GetSpell(DIVINE_SHIELD_1)))
                    return;
            }

            //Holy shield
            if (IsSpellReady(HOLY_SHIELD_1, diff) && HasRole(BOT_ROLE_DPS) && CanBlock() && !me->getAttackers().empty() &&
                !me->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
            {
                if (doCast(me, GetSpell(HOLY_SHIELD_1)))
                    return;
            }

            auto [can_do_holy, can_do_normal] = CanAffectVictimBools(mytar, SPELL_SCHOOL_HOLY, SPELL_SCHOOL_NORMAL);

            float dist = me->GetDistance(mytar);

            //HAMMER OF WRATH
            if (IsSpellReady(HAMMER_OF_WRATH_1, diff) && can_do_holy && HasRole(BOT_ROLE_DPS) && Rand() < 80 &&
                mytar->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT) && dist < 30)
            {
                if (doCast(mytar, GetSpell(HAMMER_OF_WRATH_1)))
                    return;
            }
            //HAND OF RECKONING //No GCD
            Unit* u = mytar->GetVictim();
            if (IsSpellReady(HAND_OF_RECKONING_1, diff, false) && can_do_holy && u && u != me && Rand() < 50 && dist < 30 &&
                mytar->GetTypeId() == TYPEID_UNIT && !mytar->IsControlledByPlayer() &&
                !CCed(mytar) && HasRole(BOT_ROLE_DPS) && !mytar->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (IsTank() && GetHealthPCT(me) > 67 &&
                (GetHealthPCT(u) < 30 || (IsOffTank() && !IsOffTank(u) && IsPointedOffTankingTarget(mytar)) ||
                (!IsOffTank() && IsOffTank(u) && IsPointedTankingTarget(mytar))))) &&
                ((!IsTankingClass(u->GetClass()) && GetHealthPCT(u) < 80) || IsTank()) &&
                IsInBotParty(u))
            {
                if (doCast(mytar, GetSpell(HAND_OF_RECKONING_1)))
                    return;
            }
            //HAND OF RECKONING 2 (distant)
            if (IsSpellReady(HAND_OF_RECKONING_1, diff, false) && !IAmFree() && u == me && Rand() < 30 && IsTank() && HasRole(BOT_ROLE_DPS) &&
                (IsOffTank() || master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_TANK_OFF) == 0) &&
                !(me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())))
            {
                Unit* tUnit = FindDistantTauntTarget();
                if (tUnit)
                {
                    if (doCast(tUnit, GetSpell(HAND_OF_RECKONING_1)))
                        return;
                }
            }
            //RIGHTEOUS DEFENSE //No GCD
            if (IsSpellReady(RIGHTEOUS_DEFENSE_1, diff, false) && !IAmFree() && u && u != me && IsTank() &&
                me->GetDistance(u) < 40 && mytar->GetTypeId() == TYPEID_UNIT && !mytar->IsControlledByPlayer() &&
                !IsTankingClass(u->GetClass()) && GetHealthPCT(u) < 80 &&
                !CCed(mytar) && !mytar->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 67)) &&
                IsInBotParty(u) && Rand() < 20 + 30 * u->getAttackers().size())
            {
                if (doCast(u, GetSpell(RIGHTEOUS_DEFENSE_1)))
                    return;
            }
            //RIGHTEOUS DEFENSE 2 (distant)
            if (IsSpellReady(RIGHTEOUS_DEFENSE_1, diff, false) && !IAmFree() && u == me && IsTank() && Rand() < 30 &&
                !(me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())))
            {
                Unit* tUnit = FindDistantTauntTarget(40, true);
                if (tUnit)
                {
                    if (doCast(tUnit, GetSpell(RIGHTEOUS_DEFENSE_1)))
                        return;
                }
            }
            //Divine Plea
            if (IsSpellReady(DIVINE_PLEA_1, diff) && Rand() < 30 && GetManaPCT(me) < (IsTank() ? 90 : 7) &&
                !me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x80004000, 0x1))
            {
                if (doCast(me, GetSpell(DIVINE_PLEA_1)))
                    return;
            }
            //Avenging Wrath (tank - big threat, dps - big hp, heal - divine plea counter)
            if (IsSpellReady(AVENGING_WRATH_1, diff, false) && can_do_holy && avDelayTimer <= diff &&
                HasRole(BOT_ROLE_HEAL|BOT_ROLE_DPS) && Rand() < 35 && dist < 30 &&
                IsTank() ? (mytar->GetTypeId() == TYPEID_UNIT && (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())) :
                (!HasRole(BOT_ROLE_HEAL) || !HasRole(BOT_ROLE_RANGED)) ? (mytar->GetHealth() > me->GetMaxHealth()/4 * (1 + mytar->getAttackers().size())) :
                (me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x80004000, 0x1) != nullptr))
            {
                if (doCast(me, GetSpell(AVENGING_WRATH_1)))
                {}
            }
            //Avenger's shield
            if (IsSpellReady(AVENGERS_SHIELD_1, diff) && can_do_holy && CanBlock() &&
                HasRole(BOT_ROLE_DPS) && dist < 30 && Rand() < 60)
            {
                if (doCast(mytar, GetSpell(AVENGERS_SHIELD_1)))
                    return;
            }
            //Divine Protection tanks only
            if (IsSpellReady(DIVINE_PROTECTION_1, diff, false) && shieldDelayTimer <= diff && IsTank() && Rand() < 80 &&
                !me->getAttackers().empty() && GetHealthPCT(me) < 67 - 20*me->HasAuraType(SPELL_AURA_PERIODIC_HEAL))
            {
                if (doCast(me, GetSpell(DIVINE_PROTECTION_1)))
                    return;
            }
            //Exorcism (have cast window or instant)
            if (IsSpellReady(EXORCISM_1, diff) && can_do_holy && HasRole(BOT_ROLE_DPS) && dist < 30 && Rand() < 70 &&
                ((IsTank() && dist > 12) || (HasRole(BOT_ROLE_RANGED) && !HasRole(BOT_ROLE_HEAL)) ||
                me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_PALADIN, 0x0, 0x0, 0x2)))
            {
                if (doCast(mytar, GetSpell(EXORCISM_1)))
                    return;
            }
            //Hammer of Justice
            if (IsSpellReady(HAMMER_OF_JUSTICE_1, diff) && !CCed(mytar) && dist < 10 && Rand() < 20 &&
                mytar->GetDiminishing(DIMINISHING_STUN) <= DIMINISHING_LEVEL_2 &&
                !IsImmunedToMySpellEffect(mytar, sSpellMgr->GetSpellInfo(HAMMER_OF_JUSTICE_1), EFFECT_0))
            {
                if (doCast(mytar, GetSpell(HAMMER_OF_JUSTICE_1)))
                    return;
            }
            //Judgement
            if (GetSpellCooldown(JUDGEMENT_OF_LIGHT_1) <= diff && can_do_holy && HasRole(BOT_ROLE_DPS) && Rand() < 120)
            {
                uint32 JUDGEMENT = 0;

                if (GetSpell(JUDGEMENT_OF_JUSTICE_1) && mytar->HasAuraType(SPELL_AURA_MOD_INCREASE_SPEED) &&
                    dist < CalcSpellMaxRange(JUDGEMENT_OF_JUSTICE_1))
                {
                    //has joj from someone else
                    bool canCast = true;
                    Unit::AuraEffectList const& notSpeedAuras = mytar->GetAuraEffectsByType(SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED);
                    for (Unit::AuraEffectList::const_iterator itr = notSpeedAuras.begin(); itr != notSpeedAuras.end(); ++itr)
                    {
                        if ((*itr)->GetCasterGUID() != me->GetGUID() && (*itr)->GetBase()->GetDuration() > 2000)
                        {
                            canCast = false;
                            break;
                        }
                    }
                    if (canCast)
                    {
                        //has sprint or something
                        Unit::AuraEffectList const& speedAuras = mytar->GetAuraEffectsByType(SPELL_AURA_MOD_INCREASE_SPEED);
                        for (Unit::AuraEffectList::const_iterator itr = speedAuras.begin(); itr != speedAuras.end(); ++itr)
                        {
                            if (!(*itr)->GetBase()->IsPassive() &&
                                (*itr)->GetBase()->GetDuration() > 2000 &&
                                (*itr)->GetAmount() >= 30)
                            {
                                JUDGEMENT = JUDGEMENT_OF_JUSTICE_1;
                                break;
                            }
                        }
                    }
                }
                if (!JUDGEMENT && GetSpell(JUDGEMENT_OF_WISDOM_1) && dist < CalcSpellMaxRange(JUDGEMENT_OF_WISDOM_1))
                {
                    //from 35% to 50% mana
                    AuraEffect const* wisd = mytar->GetAuraEffect(JUDGEMENT_OF_WISDOM_AURA, 0);
                    //AuraEffect const* wisd = mytar->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 3014, 0);
                    uint8 myManaPct = GetManaPCT(me);
                    if ((!wisd && myManaPct < 35) || (wisd && wisd->GetCasterGUID() == me->GetGUID() && myManaPct < 50))
                        JUDGEMENT = JUDGEMENT_OF_WISDOM_1;
                }
                if (!JUDGEMENT && GetSpell(JUDGEMENT_OF_LIGHT_1) && dist < CalcSpellMaxRange(JUDGEMENT_OF_LIGHT_1))
                {
                    JUDGEMENT = JUDGEMENT_OF_LIGHT_1;
                }

                //Conditional spell unavailable, use any other
                if (!JUDGEMENT)
                {
                    if (GetSpell(JUDGEMENT_OF_WISDOM_1))
                        JUDGEMENT = JUDGEMENT_OF_WISDOM_1;
                    else if (GetSpell(JUDGEMENT_OF_LIGHT_1))
                        JUDGEMENT = JUDGEMENT_OF_LIGHT_1;
                    else if (GetSpell(JUDGEMENT_OF_JUSTICE_1))
                        JUDGEMENT = JUDGEMENT_OF_JUSTICE_1;
                }

                if (JUDGEMENT && doCast(mytar, GetSpell(JUDGEMENT)))
                    return;
            }
            //Consecration
            if (IsSpellReady(CONSECRATION_1, diff) && can_do_holy && HasRole(BOT_ROLE_DPS) && dist < 5 &&
                !mytar->isMoving() && Rand() < 50)
            {
                if (doCast(me, GetSpell(CONSECRATION_1)))
                    return;
            }
            //Hammer of the Righteous (1h only)
            if (IsSpellReady(HAMMER_OF_THE_RIGHTEOUS_1, diff) && can_do_holy && HasRole(BOT_ROLE_DPS) &&
                dist < 5 && Rand() < 80)
            {
                Item const* weapMH = GetEquips(BOT_SLOT_MAINHAND);
                if (weapMH &&
                    (weapMH->GetTemplate()->InventoryType == INVTYPE_WEAPON ||
                    weapMH->GetTemplate()->InventoryType == INVTYPE_WEAPONMAINHAND) &&
                    doCast(mytar, GetSpell(HAMMER_OF_THE_RIGHTEOUS_1)))
                    return;
            }
            //Shield of Righteousness
            if (IsSpellReady(SHIELD_OF_RIGHTEOUSNESS_1, diff) && can_do_holy && HasRole(BOT_ROLE_DPS) && CanBlock() &&
                (IsTank() || IAmFree()) && dist < 5 && Rand() < 90)
            {
                if (doCast(mytar, GetSpell(SHIELD_OF_RIGHTEOUSNESS_1)))
                    return;
            }
            //Crusader Strike
            if (IsSpellReady(CRUSADER_STRIKE_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && dist < 5 && Rand() < 90)
            {
                if (doCast(mytar, GetSpell(CRUSADER_STRIKE_1)))
                    return;
            }
            //Divine Storm
            if (IsSpellReady(DIVINE_STORM_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) && dist < 7 && Rand() < 40)
            {
                if (doCast(me, GetSpell(DIVINE_STORM_1)))
                    return;
            }
            //Holy Wrath
            if (IsSpellReady(HOLY_WRATH_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 50)
            {
                if ((mytar->GetCreatureType() == CREATURE_TYPE_UNDEAD || mytar->GetCreatureType() == CREATURE_TYPE_DEMON) &&
                    dist < 8.5f && doCast(me, GetSpell(HOLY_WRATH_1)))
                    return;
                else
                {
                    if (FindUndeadCCTarget(8.5f, HOLY_WRATH_1, false) &&
                        doCast(me, GetSpell(HOLY_WRATH_1)))
                        return;
                }
            }
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType /*attackType*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Sanctified Light: 6% additional critical chance for Holy Light and Holy Shock
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 30 && (baseId == HOLY_LIGHT_1 || baseId == HOLY_SHOCK_1))
                crit_chance += 6.f;
            //Holy Power: 5% additional critical chance for Holy spells
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 35 && (schoolMask & SPELL_SCHOOL_MASK_HOLY))
                crit_chance += 5.f;
            //Improved Flash of Light (id: 20251): 6% additional critical chance for Flash of Light
            if (lvl >= 70 && baseId == FLASH_OF_LIGHT_1)
                crit_chance += 6.f;
            //Glyph of Flash of Light: 5% additional critical chance for Flash of Light
            if (lvl >= 20 && baseId == FLASH_OF_LIGHT_1)
                crit_chance += 5.f;
            //Sanctified Wrath: 50% additional critical chance for Hammer of Wrath
            if ((GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION) && lvl >= 45 && baseId == HAMMER_OF_WRATH_1)
                crit_chance += 50.f;
            //Fanaticism: 18% additional critical chance for all Judgements (not shure which check is right)
            if ((GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION) && lvl >= 45 && spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT)
                crit_chance += 18.f;
            //Infusion of Light
            if (baseId == HOLY_LIGHT_1)
            {
                if (AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 0))
                    if (infu->IsAffectingSpell(spellInfo))
                        crit_chance += 20.f;
            }
            if (baseId == HOLY_LIGHT_1 || baseId == FLASH_OF_LIGHT_1 || baseId == HOLY_SHOCK_1)
            {
                if (AuraEffect const* favo = me->GetAuraEffect(DIVINE_FAVOR_1, 0))
                    if (favo->IsAffectingSpell(spellInfo))
                        crit_chance += 100.f;
            }
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool /*iscrit*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            //if (iscrit)
            //{
            //}
            //Sanctity of Battle: 15% bonus damage for Exorcism and Crusader Strike
            if ((GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION) && lvl >= 25 && baseId == EXORCISM_1)
                pctbonus += 0.15f;
            //The Art of War (damage part): 10% bonus damage for Judgements, Crusader Strike and Divine Storm
            if ((GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION) && lvl >= 40 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT || baseId == CRUSADER_STRIKE_1 || baseId == DIVINE_STORM_1))
                pctbonus += 0.1f;
            //Judgements of the Pure (damage part): 25% bonus damage for Judgements and Seals
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 50 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_SEAL ||
                baseId == JUDGEMENT_OF_COMMAND_DAMAGE))
                pctbonus += 0.25f;
            //Glyph of Exorcism: 20% bonus damage for Exorcism
            if (lvl >= 50 && baseId == EXORCISM_1)
                pctbonus += 0.2f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool /*iscrit*/) const override
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            //if (iscrit)
            //{
            //}

            //Judgements of the Pure (damage part): 25% bonus damage for Judgements and Seals
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 50 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_SEAL ||
                spellId == JUDGEMENT_OF_COMMAND_DAMAGE))
                pctbonus += 0.25f;
            //Improved Consecration (id: 38422): 10% bonus damage for Consecration
            if (lvl >= 20 && spellId == GetSpell(CONSECRATION_1))
                pctbonus += 0.1f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType /*damagetype*/, uint32 /*stack*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Divine Plea: 50% reduced healing for all spells
            if (/*lvl >= 71 && */me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x80004000, 0x1))
                pctbonus -= 0.5f;

            //Healing Light: 12% bonus healing for Holy Light, Flash of Light and Holy Shock
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 15 && (baseId == HOLY_LIGHT_1 || baseId == FLASH_OF_LIGHT_1 || baseId == HOLY_SHOCK_1))
                pctbonus += 0.12f;
            //Glyph of Seal of Light: 5% bonus healing for all spells
            if (lvl >= 30 && me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_PALADIN, 0x0, 0x2000000, 0x0))
                pctbonus += 0.05f;

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //percent mods
            //Benediction: -10% mana cost for Instant spells
            if (lvl >= 10 && !spellInfo->CalcCastTime())
                pctbonus += 0.1f;
            //Blessed Hands: -30% mana cost for Hand spells
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x2110))
                pctbonus += 0.3f;
            //Holy Light Cost Reduction (id: 60148): -5% mana cost for Holy Light
            if (lvl >= 30 && baseId == HOLY_LIGHT_1)
                pctbonus += 0.05f;
            //Consecration Discount (id: 37180): -15% mana cost for Consecration
            if (lvl >= 30 && baseId == CONSECRATION_1)
                pctbonus += 0.15f;
            //Glyph of Seal of Wisdom: -5% mana cost for all healing spells (for bot it is all spells)
            if (lvl >= 15 && me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_PALADIN, 0x0, 0x4000000, 0x0))
                pctbonus += 0.05f;
            //Glyph of Shield of Righteous: -80% mana cost for Shield of Righteous
            if (lvl >= 75 && (spellInfo->SpellFamilyFlags[1] & 0x100000))
                pctbonus += 0.8f;

            //flat mods
            //Cleanse Cost Reduced (id: 27847): -25 mana cost for Cleanse
            if (lvl >= 40 && baseId == CLEANSE_1)
                flatbonus += 25;
            //Reduced Holy Light Cost (id: 37739): -34 mana cost for Holy Light
            if (lvl >= 40 && baseId == HOLY_LIGHT_1)
                flatbonus += 34;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //casttime is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            //float pctbonus = 0.0f;

            //100% mods
            //Glyph of Turn Evil: -100% cast time for Turn Evil
            if (lvl >= 24 && baseId == TURN_EVIL_1)
                timebonus += casttime;
            if (baseId == FLASH_OF_LIGHT_1 || baseId == EXORCISM_1)
            {
                //The Art of War
                AuraEffect const* arto = me->GetAuraEffect(THE_ART_OF_WAR_BUFF, 0);
                //Infusion of Light
                AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 1);
                if (arto && arto->IsAffectingSpell(spellInfo))
                    timebonus += casttime;
                else if (infu && infu->IsAffectingSpell(spellInfo))
                    timebonus += casttime;
            }

            //flat mods
            //Improved Holy Light (id: 24457): -0.1 sec cast time for Holy Light
            if (lvl >= 40 && baseId == HOLY_LIGHT_1)
                timebonus += 100;
            //Recuced Holy Light Cast Time (id: 37189): -0.5 sec cast time for Holy Light (works only for healers)
            //Light's Grace: -0.5 sec cast time for Holy Light
            if (baseId == HOLY_LIGHT_1)
            {
                if (AuraEffect const* enli = me->GetAuraEffect(ENLIGHTENMENT_BUFF, 0))
                    if (enli->IsAffectingSpell(spellInfo))
                        timebonus += 500;
                if (AuraEffect const* grac = me->GetAuraEffect(LIGHTS_GRACE_BUFF, 0))
                    if (grac->IsAffectingSpell(spellInfo))
                        timebonus += 500;
            }

            casttime = std::max<int32>(casttime - timebonus, 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods

            //flat mods
            //Improved Judgements: -2 sec cooldown for judgements
            //Judgment Cooldown Reduction (60153): -1 sec cooldown for judgements
            //Judgement Cooldown Reduction (61776): -1 sec cooldown for judgements
            if (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT)
            {
                if (lvl >= 70)
                    timebonus += 4000;
                else if (lvl >= 60)
                    timebonus += 3000;
                else if (lvl >= 15)
                    timebonus += 2000;
            }
            //Sacred Duty: -60 sec cooldown for Divine Shield and Divine Protection
            if ((GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && lvl >= 35 && (baseId == DIVINE_SHIELD_1 || baseId == DIVINE_PROTECTION_1))
                timebonus += 60000;
            //Reduced Righteous Defense Cooldown (37181): -2 sec cooldown for Righteous Defense
            if (lvl >= 60 && baseId == RIGHTEOUS_DEFENSE_1)
                timebonus += 2000;
            //Paladin T9 Tank 2P Bonus part 1: -2 sec cooldown for Hand of Reckoning
            if (lvl >= 78 && baseId == HAND_OF_RECKONING_1)
                timebonus += 2000;
            //Glyph of Turn Evil: +8 sec cooldown for Turn Evil
            if (lvl >= 24 && baseId == TURN_EVIL_1)
                timebonus -= 8000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Purifying Power part 2: -33% cooldown for Exorcism and Holy Wrath
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 35 && (baseId == EXORCISM_1 || baseId == HOLY_WRATH_1))
                pctbonus += 0.333f;
            //Glyph of Avenging Wrath: -50% cooldown for Hammer of Wrath if Avenging Wrath is active
            if (lvl >= 70 && baseId == HAMMER_OF_WRATH_1 &&
                me->GetAuraEffect(SPELL_AURA_MOD_HEALING_DONE_PERCENT, SPELLFAMILY_PALADIN, 0x0, 0x2000, 0x0))
                pctbonus += 0.5f;

            //flat mods
            //Improved Judgements: -2 sec cooldown for judgements
            //Judgment Cooldown Reduction (60153): -1 sec cooldown for judgements
            //Judgement Cooldown Reduction (61776): -1 sec cooldown for judgements
            if (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT)
            {
                if (lvl >= 70)
                    timebonus += 4000;
                else if (lvl >= 60)
                    timebonus += 3000;
                else if (lvl >= 15)
                    timebonus += 2000;
            }
            //Guardian's Favor part 1: -120 sec cooldown for Hand of Protection
            if (lvl >= 15 && baseId == HAND_OF_PROTECTION_1)
                timebonus += 120000;
            //Improved Hammer of Justice: -20 sec cooldown for Hammer of Justice
            if ((GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && lvl >= 25 && baseId == HAMMER_OF_JUSTICE_1)
                timebonus += 20000;
            //Judgements of the Just: -10 sec cooldown for Hammer of Justice (tanks only)
            if ((GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && lvl >= 55 && baseId == HAMMER_OF_JUSTICE_1)
                timebonus += 10000;
            //Glyph of Holy Shock: -1 sec cooldown for Holy Shock
            if (baseId == HOLY_SHOCK_1)
                timebonus += 1000;
            //Glyph of Consecration: +2 sec cooldown for Consecration
            if (lvl >= 20 && baseId == CONSECRATION_1)
                timebonus -= 2000;
            //Glyph of Holy Wrath: -15 sec cooldown for Holy Wrath
            if (lvl >= 50 && baseId == HOLY_WRATH_1)
                timebonus += 15000;
            //Improved Lay on Hands (part 2): -4 min cooldown for Lay on Hands
            if (lvl >= 20 && baseId == LAY_ON_HANDS_1)
                timebonus += 240000;
            //Glyph of Lay on Hands: -5 min cooldown for Lay on Hands (only healers)
            if (lvl >= 15 && HasRole(BOT_ROLE_HEAL) && baseId == LAY_ON_HANDS_1)
                timebonus += 300000;
            //Lay Hands (id: 28774): -4 min cooldown for Lay on Hands (only healers)
            if (lvl >= 60 && HasRole(BOT_ROLE_HEAL) && baseId == LAY_ON_HANDS_1)
                timebonus += 240000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* /*spellInfo*/, float& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            ////Unrelenting Assault (part 1, special): -0.5 sec global cooldown for Overpower and Revenge (not for tanks)
            //if (lvl >= 50 && !IsTank() && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
            //    timebonus += 500.f;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            //uint32 spellId = spellInfo->Id;
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            ////Holy Reach
            //if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x18400200) || (spellInfo->SpellFamilyFlags[2] & 0x4)))
            //    pctbonus += 0.2f;

            //flat mods
            //Increased Aura Radii (23565)
            if (lvl >= 40 && (spellInfo->SpellFamilyFlags[0] & 0x4020048))
                flatbonus += 10.f;

            radius = radius * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            //uint32 spellId = spellInfo->Id;
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Booming Voice
            //if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x30000) || (spellInfo->SpellFamilyFlags[1] & 0x80)))
            //    pctbonus += 1.0f;

            //flat mods
            //Enlightened Judgements: +30 yd range for Judgement of Light and Judgement of Wisdom (healers)
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 55 && (spellInfo->SpellFamilyFlags[0] & 0x800000))
                flatbonus += 30.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const override
        {
            uint32 bonusTargets = 0;

            //Glyph of Hammer of the Righteous: +1 target
            if (spellInfo->SpellFamilyFlags[1] & 0x40000)
                bonusTargets += 1;

            targets = targets + bonusTargets;
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //Improved Devotion Aura: 50% increased effect
            if (baseId == DEVOTION_AURA_1 && effIndex == EFFECT_0 && GetSpec() == BOT_SPEC_PALADIN_PROTECTION && lvl >= 25)
                pctbonus *= 1.5f;
            //Improved Devotion Aura: 6% bonus healing
            if (baseId == IMPROVED_DEVOTION_AURA_SPELL && effIndex == EFFECT_1 && GetSpec() == BOT_SPEC_PALADIN_PROTECTION && lvl >= 25)
                value += 6.f;

            value = value * pctbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == HOLY_LIGHT_1 || baseId == FLASH_OF_LIGHT_1 || baseId == HOLY_SHOCK_1)
            {
                if (AuraEffect const* favo = me->GetAuraEffect(DIVINE_FAVOR_1, 0))
                    if (favo->IsAffectingSpell(spellInfo))
                        me->RemoveAurasDueToSpell(DIVINE_FAVOR_1);
            }

            if (baseId == HOLY_LIGHT_1)
            {
                if (AuraEffect const* enli = me->GetAuraEffect(ENLIGHTENMENT_BUFF, 0))
                    if (enli->IsAffectingSpell(spellInfo))
                        me->RemoveAurasDueToSpell(ENLIGHTENMENT_BUFF);
                if (AuraEffect const* grac = me->GetAuraEffect(LIGHTS_GRACE_BUFF, 0))
                    if (grac->IsAffectingSpell(spellInfo))
                        me->RemoveAurasDueToSpell(LIGHTS_GRACE_BUFF);
                if (AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 0))
                    if (infu->IsAffectingSpell(spellInfo))
                        me->RemoveAurasDueToSpell(INFUSION_OF_LIGHT_BUFF);
            }

            if (baseId == EXORCISM_1 || baseId == FLASH_OF_LIGHT_1)
            {
                //Infusion of Light takes priority since AoW affects Exorcism too
                AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 1);
                //The Art of War
                AuraEffect const* arto = me->GetAuraEffect(THE_ART_OF_WAR_BUFF, 0);
                if (arto && arto->IsAffectingSpell(spellInfo))
                    me->RemoveAurasDueToSpell(THE_ART_OF_WAR_BUFF);
                else if (infu && infu->IsAffectingSpell(spellInfo))
                    me->RemoveAurasDueToSpell(INFUSION_OF_LIGHT_BUFF);
            }

            if (baseId == DIVINE_SACRIFICE_1)
            {
                _sacDamage = 0;
            }
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Glyph of Beacon of Light: 30 sec increased duration
            if (baseId == BEACON_OF_LIGHT_1)
            {
                Aura* beac = target->GetAura(spellId, me->GetGUID());
                if (beac)
                {
                    uint32 dur = beac->GetDuration() + 30000;
                    beac->SetDuration(dur);
                    beac->SetMaxDuration(dur);
                }
            }
            //Judgements of the Just melee attack speed reduction part 1
            if ((GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && lvl >= 55 && spell->GetCategory() == SPELLCATEGORY_JUDGEMENT)
            {
                me->CastSpell(target, JUDGEMENTS_OF_THE_JUST_AURA, true);
            }
            //Judgements of the Just melee attack speed reduction part 2
            if ((GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && spellId == JUDGEMENTS_OF_THE_JUST_AURA)
            {
                AuraEffect* slow = target->GetAuraEffect(JUDGEMENTS_OF_THE_JUST_AURA, 1, me->GetGUID());
                if (slow)
                    slow->ChangeAmount(slow->GetAmount() - 20);
            }

            if ((GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && spellId == SEAL_OF_JUSTICE_STUN_AURA)
            {
                if (lvl >= 55)
                {
                    //Judgements of the Just: 1 sec increased duration
                    Aura* stun = target->GetAura(spellId, me->GetGUID());
                    if (stun)
                    {
                        uint32 dur = stun->GetDuration() + 1000;
                        stun->SetDuration(dur);
                        stun->SetMaxDuration(dur);
                    }
                }
            }
            if (baseId == CONSECRATION_1)
            {
                if (lvl >= 30)
                {
                    //Glyph of Consecration: 2 sec increased duration
                    Aura* cons = target->GetAura(spellId, me->GetGUID());
                    if (cons)
                    {
                        uint32 dur = cons->GetDuration() + 2000;
                        cons->SetDuration(dur);
                        cons->SetMaxDuration(dur);
                    }
                }
            }
            if ((GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION) && baseId == RETRIBUTION_AURA_1)
            {
                if (lvl >= 30)
                {
                    //Sanctified Retribution: 50% increased effect
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                        eff->ChangeAmount(eff->GetAmount() * 3 / 2);
                }
            }
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && baseId == CONCENTRATION_AURA_1)
            {
                if (lvl >= 25)
                {
                    //Improved Concentration Aura: 15% increased effect (flat)
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                        eff->ChangeAmount(eff->GetAmount() + 15); //base = 35, bonus = 15
                }
            }
            if (baseId == FLASH_OF_LIGHT_HEAL_PERIODIC)
            {
                if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && lvl >= 78 && !HasRole(BOT_ROLE_TANK | BOT_ROLE_DPS))
                {
                    //Paldin T9 Holy 4P Bonus: 100% increased healing from Infusion of Light (pure healers only)
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                        eff->ChangeAmount(eff->GetAmount() * 2);
                }
            }
            if (baseId == BLESSING_OF_WISDOM_1)
            {
                if (lvl >= 25)
                {
                    //Improved Blessing of Wisdom: 20% increased effect
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                        eff->ChangeAmount(eff->GetAmount() * 6 / 5);
                }
            }
            if (baseId == BLESSING_OF_MIGHT_1)
            {
                if (lvl >= 15)
                {
                    //Improved Blessing of Might: 25% increased effect
                    if (Aura* migh = target->GetAura(spellId, me->GetGUID()))
                        for (uint8 i = 0; i != EFFECT_2; ++i) // 2 effects
                            if (AuraEffect* eff = migh->GetEffect(i))
                                eff->ChangeAmount((eff->GetAmount() * 125) / 100);
                }
            }
            if (baseId == HAND_OF_FREEDOM_1)
            {
                //Guardian's Favor part 2 (handled separately)
                if (Aura* hof = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = hof->GetDuration() + 4000;
                    hof->SetDuration(dur);
                    hof->SetMaxDuration(dur);
                }
            }
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && baseId == HAND_OF_SALVATION_1 && !IsTank(target))
            {
                //Blessed Hands (part 2)
                if (AuraEffect* hos = target->GetAuraEffect(spellId, 0, me->GetGUID()))
                {
                    hos->ChangeAmount(hos->GetAmount() * 2);
                }
            }
            if ((GetSpec() == BOT_SPEC_PALADIN_HOLY) && baseId == HAND_OF_SACRIFICE_1)
            {
                //Blessed Hands (part 3)
                if (AuraEffect* hos = target->GetAuraEffect(spellId, 0, me->GetGUID()))
                {
                    hos->ChangeAmount(hos->GetAmount() + 10);
                }
            }
            if (baseId == BLESSING_OF_KINGS_1 || baseId == BLESSING_OF_MIGHT_1 ||
                baseId == BLESSING_OF_WISDOM_1 || baseId == BLESSING_OF_SANCTUARY_1)
            {
                //Blessings duration 1h
                if (Aura* bless = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = HOUR * IN_MILLISECONDS;
                    bless->SetDuration(dur);
                    bless->SetMaxDuration(dur);
                }
            }
            if (baseId == SACRED_SHIELD_AURA_TRIGGERED || baseId == SACRED_SHIELD_1)
            {
                //Divine Guardian (part 2): 20% increased absorb, +100% duration
                Aura* shi = target->GetAura(spellId, me->GetGUID());
                if (shi)
                {
                    uint32 dur = shi->GetDuration() * 2;
                    shi->SetDuration(dur);
                    shi->SetMaxDuration(dur);
                    if (baseId == SACRED_SHIELD_AURA_TRIGGERED)
                    {
                        if (AuraEffect* eff = shi->GetEffect(EFFECT_0))
                            eff->ChangeAmount(eff->GetAmount() * 6 / 5);
                    }
                }
            }

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;

            //Glyph of Seal of Vengeance
            if (baseId == SEAL_OF_VENGEANCE_1 || baseId == SEAL_OF_CORRUPTION_1)
            {
                AuraEffect* sea = me->GetAuraEffect(spell->Id, 1);
                if (sea)
                    sea->ChangeAmount(sea->GetAmount() + 10);
            }

            //Aura Helper
            if (caster == me)
            {
                if (baseId == DEVOTION_AURA_1)
                    _aura = DEVOTIONAURA;
                if (baseId == CONCENTRATION_AURA_1)
                    _aura = CONCENTRATIONAURA;
                if (baseId == FIRE_RESISTANCE_AURA_1)
                    _aura = FIRERESAURA;
                if (baseId == FROST_RESISTANCE_AURA_1)
                    _aura = FROSTRESAURA;
                if (baseId == SHADOW_RESISTANCE_AURA_1)
                    _aura = SHADOWRESAURA;
                if (baseId == RETRIBUTION_AURA_1)
                    _aura = RETRIBUTIONAURA;
                if (baseId == CRUSADER_AURA_1)
                    _aura = CRUSADERAURA;
            }

            //immunity markers
            if (baseId == AVENGING_WRATH_MARKER_SPELL)
                avDelayTimer = 30000;
            if (baseId == IMMUNITY_SHIELD_MARKER_SPELL)
                shieldDelayTimer = 30000;

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void OnBotDamageTaken(Unit* /*attacker*/, uint32 damage, CleanDamage const* /*cleanDamage*/, DamageEffectType /*damagetype*/, SpellInfo const* spellInfo) override
        {
            // Divine Sacrifice helper - calculate remaining damage amount and find if we can be one-shot'ed
            if (damage && _sacDamage < int32(me->GetMaxHealth() / 4))
            {
                if (spellInfo && spellInfo->Id == DIVINE_SACRIFICE_1)
                    _sacDamage -= int32(damage);
                else
                    _sacDamage += int32(damage);

                if (me->GetHealth() - _sacDamage < me->GetMaxHealth() / 5)
                {
                    if (me->GetAuraEffect(SPELL_AURA_SPLIT_DAMAGE_PCT, SPELLFAMILY_PALADIN, 0x0, 0x0, 0x4, me->GetGUID()))
                    {
                        _sacDamage = me->GetMaxHealth();
                        me->RemoveAurasDueToSpell(DIVINE_SACRIFICE_1, me->GetGUID());
                    }
                }
            }
        }

        void DamageTaken(Unit* u, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
        {
            if (!u)
                return;
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        //healer may be nullptr
        void HealReceived(Unit* healer, uint32& heal) override
        {
            //Spiritual Attunement (double the effect on bots)
            if (heal && (GetSpec() == BOT_SPEC_PALADIN_PROTECTION) && me->GetLevel() >= 40 && healer != me && GetLostHP(me))
            {
                if (int32 basepoints = int32(CalculatePct(std::min<int32>(heal, GetLostHP(me)), 20)))
                {
                    CastSpellExtraArgs args(true);
                    args.AddSpellBP0(basepoints);
                    me->CastSpell(me, SPIRITUAL_ATTUNEMENT_ENERGIZE, args);
                }
            }

            //bot_ai::HealReceived(healer, heal);
        }

        void OwnerAttackedBy(Unit* u) override
        {
            if (!u)
                return;
            OnOwnerDamagedBy(u);
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(GetSpell(EXORCISM_1) ? EXORCISM_1 : JUDGEMENT_OF_LIGHT_1) : 10.f;
        }

        void Reset() override
        {
            checkAuraTimer = 0;
            checkSealTimer = 0;
            checkShieldTimer = 0;
            checkBeaconTimer = 0;
            avDelayTimer = 0;
            shieldDelayTimer = 0;
            _aura = NOAURA;
            _sacDamage = 0;

            CLEANSE = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (checkAuraTimer > diff)              checkAuraTimer -= diff;
            if (checkSealTimer > diff)              checkSealTimer -= diff;
            if (checkShieldTimer > diff)            checkShieldTimer -= diff;
            if (checkBeaconTimer > diff)            checkBeaconTimer -= diff;
            if (avDelayTimer > diff)                avDelayTimer -= diff;
            if (shieldDelayTimer > diff)            shieldDelayTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isHoly = GetSpec() == BOT_SPEC_PALADIN_HOLY;
            bool isProt = GetSpec() == BOT_SPEC_PALADIN_PROTECTION;
            bool isRetr = GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION;

            InitSpellMap(FLASH_OF_LIGHT_1);
            InitSpellMap(HOLY_LIGHT_1);
            InitSpellMap(LAY_ON_HANDS_1);
            InitSpellMap(SACRED_SHIELD_1);
            InitSpellMap(REDEMPTION_1);
            InitSpellMap(HAMMER_OF_JUSTICE_1);
            InitSpellMap(TURN_EVIL_1);
            InitSpellMap(HOLY_WRATH_1);
            InitSpellMap(EXORCISM_1);
            InitSpellMap(JUDGEMENT_OF_LIGHT_1);
            InitSpellMap(JUDGEMENT_OF_WISDOM_1);
            InitSpellMap(JUDGEMENT_OF_JUSTICE_1);
            InitSpellMap(CONSECRATION_1);
            InitSpellMap(HAMMER_OF_WRATH_1);
            InitSpellMap(AVENGING_WRATH_1);
            InitSpellMap(RIGHTEOUS_FURY_1);
            InitSpellMap(SHIELD_OF_RIGHTEOUSNESS_1);
            InitSpellMap(BLESSING_OF_MIGHT_1);
            InitSpellMap(BLESSING_OF_WISDOM_1);
            InitSpellMap(BLESSING_OF_KINGS_1);
            InitSpellMap(DEVOTION_AURA_1);
            InitSpellMap(CONCENTRATION_AURA_1);
            InitSpellMap(FIRE_RESISTANCE_AURA_1);
            InitSpellMap(FROST_RESISTANCE_AURA_1);
            InitSpellMap(SHADOW_RESISTANCE_AURA_1);
            InitSpellMap(RETRIBUTION_AURA_1);
            InitSpellMap(CRUSADER_AURA_1);
            InitSpellMap(DIVINE_PLEA_1);
            InitSpellMap(HAND_OF_PROTECTION_1);
            InitSpellMap(HAND_OF_FREEDOM_1);
            InitSpellMap(HAND_OF_SALVATION_1);
            InitSpellMap(HAND_OF_SACRIFICE_1);
            InitSpellMap(HAND_OF_RECKONING_1);
            InitSpellMap(RIGHTEOUS_DEFENSE_1);
            //InitSpellMap(PURIFY_1);
            //InitSpellMap(CLEANSE_1);
            InitSpellMap(SEAL_OF_LIGHT_1);
            InitSpellMap(SEAL_OF_RIGHTEOUSNESS_1);
            InitSpellMap(SEAL_OF_WISDOM_1);
            InitSpellMap(SEAL_OF_JUSTICE_1);
            InitSpellMap((me->GetRaceMask() & RACEMASK_ALLIANCE) ? SEAL_OF_VENGEANCE_1 : SEAL_OF_CORRUPTION_1);
            InitSpellMap(DIVINE_INTERVENTION_1);
            InitSpellMap(DIVINE_PROTECTION_1);
            InitSpellMap(DIVINE_SHIELD_1);

  /*Talent*/lvl >= (isHoly ? 20 : 70) ? InitSpellMap(AURA_MASTERY_1) : RemoveSpell(AURA_MASTERY_1);
  /*Talent*/lvl >= 30 && isHoly ? InitSpellMap(DIVINE_FAVOR_1) : RemoveSpell(DIVINE_FAVOR_1);
  /*Talent*/lvl >= 40 && isHoly ? InitSpellMap(HOLY_SHOCK_1) : RemoveSpell(HOLY_SHOCK_1);
  /*Talent*/lvl >= 50 && isHoly ? InitSpellMap(DIVINE_ILLUMINATION_1) : RemoveSpell(DIVINE_ILLUMINATION_1);
  /*Talent*/lvl >= 60 && isHoly ? InitSpellMap(BEACON_OF_LIGHT_1) : RemoveSpell(BEACON_OF_LIGHT_1);

  /*Talent*/lvl >= (isProt ? 20 : isHoly ? 70 : 99) ? InitSpellMap(DIVINE_SACRIFICE_1) : RemoveSpell(DIVINE_SACRIFICE_1);
  /*Talent*/lvl >= 30 && isProt ? InitSpellMap(BLESSING_OF_SANCTUARY_1) : RemoveSpell(BLESSING_OF_SANCTUARY_1);
  /*Talent*/lvl >= 40 && isProt ? InitSpellMap(HOLY_SHIELD_1) : RemoveSpell(HOLY_SHIELD_1);
  /*Talent*/lvl >= 50 && isProt ? InitSpellMap(AVENGERS_SHIELD_1) : RemoveSpell(AVENGERS_SHIELD_1);
  /*Talent*/lvl >= 60 && isProt ? InitSpellMap(HAMMER_OF_THE_RIGHTEOUS_1) : RemoveSpell(HAMMER_OF_THE_RIGHTEOUS_1);

  /*Talent*/lvl >= 20 && isRetr ? InitSpellMap(SEAL_OF_COMMAND_1) : RemoveSpell(SEAL_OF_COMMAND_1);
  /*Talent*/lvl >= 40 && isRetr ? InitSpellMap(REPENTANCE_1) : RemoveSpell(REPENTANCE_1);
  /*Talent*/lvl >= 50 && isRetr ? InitSpellMap(CRUSADER_STRIKE_1) : RemoveSpell(CRUSADER_STRIKE_1);
  /*Talent*/lvl >= 60 && isRetr ? InitSpellMap(DIVINE_STORM_1) : RemoveSpell(DIVINE_STORM_1);

            CLEANSE = InitSpell(me, CLEANSE_1) ? CLEANSE_1 : PURIFY_1;
            RemoveSpell(CLEANSE_1);
            RemoveSpell(PURIFY_1);
            InitSpellMap(CLEANSE);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isHoly = GetSpec() == BOT_SPEC_PALADIN_HOLY;
            bool isProt = GetSpec() == BOT_SPEC_PALADIN_PROTECTION;
            bool isRetr = GetSpec() == BOT_SPEC_PALADIN_RETRIBUTION;

            RefreshAura(ILLUMINATION, isHoly && level >= 20 ? 1 : 0);
            RefreshAura(IMPROVED_LAY_ON_HANDS, isHoly && level >= 20 ? 1 : 0);
            RefreshAura(IMPROVED_CONCENTRATION_AURA, isHoly && level >= 25 ? 1 : 0);
            RefreshAura(LIGHTS_GRACE, isHoly && level >= 40 ? 1 : 0);
            RefreshAura(SACRED_CLEANSING, isHoly && level >= 45 ? 1 : 0);
            RefreshAura(JUDGEMENTS_OF_THE_PURE, isHoly && level >= 50 ? 1 : 0);
            RefreshAura(INFUSION_OF_LIGHT, isHoly && level >= 55 ? 1 : 0);
            RefreshAura(RECUCED_HOLY_LIGHT_CAST_TIME, isHoly && level >= 60 ? 1 : 0); //

            RefreshAura(IMPROVED_RIGHTEOUS_FURY, isProt && level >= 20 ? 1 : 0);
            RefreshAura(IMPROVED_DEVOTION_AURA, isProt && level >= 25 ? 1 : 0);
            RefreshAura(DIVINE_GUARDIAN, isProt && level >= 25 ? 1 : 0);
            RefreshAura(RECKONING5, isProt && level >= 50 ? 1 : 0);
            RefreshAura(RECKONING4, isProt && level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(RECKONING3, isProt && level >= 40 && level < 45 ? 1 : 0);
            RefreshAura(RECKONING2, isProt && level >= 35 && level < 40 ? 1 : 0);
            RefreshAura(RECKONING1, isProt && level >= 30 && level < 35 ? 1 : 0);
            RefreshAura(ONE_HANDED_WEAPON_SPECIALIZATION, isProt && level >= 35 ? 1 : 0);
            RefreshAura(ARDENT_DEFENDER, isProt && level >= 40 ? 1 : 0);
            //RefreshAura(COMBAT_EXPERTISE, isProt && level >= 45 ? 1 : 0);
            RefreshAura(REDOUBT3, isProt && level >= 55 ? 1 : 0);
            RefreshAura(REDOUBT2, isProt && level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(REDOUBT1, isProt && level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(GUARDED_BY_THE_LIGHT, isProt && level >= 50 ? 1 : 0);
            RefreshAura(TOUCHED_BY_THE_LIGHT, isProt && level >= 50 ? 1 : 0);
            RefreshAura(SHIELD_OF_THE_TEMPLAR, isProt && level >= 55 ? 1 : 0);
            //RefreshAura(JUDGEMENTS_OF_THE_JUST, isProt && level >= 55 ? 1 : 0);

            RefreshAura(HEART_OF_THE_CRUSADER, isRetr && level >= 15 ? 1 : 0);
            RefreshAura(PURSUIT_OF_JUSTICE, isRetr && level >= 20 ? 1 : 0);
            RefreshAura(FANATICISM, isRetr && level >= 20 ? 1 : 0);
            RefreshAura(VINDICATION2, isRetr && level >= 25 ? 1 : 0);
            RefreshAura(VINDICATION1, isRetr && level >= 20 && level < 25 ? 1 : 0);
            RefreshAura(CRUSADE, isRetr && level >= 25 ? 1 : 0);
            RefreshAura(TWO_HANDED_WEAPON_SPECIALIZATION, isRetr && level >= 30 ? 1 : 0);
            RefreshAura(SANCTIFIED_RETRIBUTION, !IAmFree() && isRetr && level >= 30 ? 1 : 0);
            RefreshAura(VENGEANCE3, isRetr && level >= 40 ? 1 : 0);
            RefreshAura(VENGEANCE2, isRetr && level >= 37 && level < 40 ? 1 : 0);
            RefreshAura(VENGEANCE1, isRetr && level >= 35 && level < 37 ? 1 : 0);
            RefreshAura(DIVINE_PURPOSE, isRetr && level >= 35 ? 1 : 0);
            RefreshAura(JUDGEMENTS_OF_THE_WISE, isRetr && level >= 40 ? 1 : 0);
            RefreshAura(ART_OF_WAR, isRetr && level >= 40 ? 1 : 0);
            RefreshAura(SWIFT_RETRIBUTION, !IAmFree() && isRetr && level >= 50 ? 1 : 0);
            RefreshAura(SHEATH_OF_LIGHT3, isRetr && level >= 60 ? 1 : 0);
            RefreshAura(SHEATH_OF_LIGHT2, isRetr && level >= 55 && level < 60 ? 1 : 0);
            RefreshAura(SHEATH_OF_LIGHT1, isRetr && level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(RIGHTEOUS_VENGEANCE3, isRetr && level >= 60 ? 1 : 0);
            RefreshAura(RIGHTEOUS_VENGEANCE2, isRetr && level >= 57 && level < 60 ? 1 : 0);
            RefreshAura(RIGHTEOUS_VENGEANCE1, isRetr && level >= 55 && level < 57 ? 1 : 0);

            RefreshAura(GLYPH_HOLY_LIGHT, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_SALVATION, level >= 26 ? 1 : 0);

            RefreshAura(JUDGEMENT_ANTI_PARRY_DODGE_PASSIVE);

            //RefreshAura(CLEANSE_HEAL_PASSIVE, level >= 58 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case FLASH_OF_LIGHT_1:
                case HOLY_LIGHT_1:
                case LAY_ON_HANDS_1:
                case HAND_OF_FREEDOM_1:
                case SACRED_SHIELD_1:
                case CLEANSE_1:
                case HAND_OF_PROTECTION_1:
                case HAND_OF_SALVATION_1:
                case HAND_OF_SACRIFICE_1:
                //case SEAL_OF_COMMAND_1:
                //case SEAL_OF_LIGHT_1:
                //case SEAL_OF_RIGHTEOUSNESS_1:
                //case SEAL_OF_WISDOM_1:
                //case SEAL_OF_JUSTICE_1:
                case DIVINE_PLEA_1:
                case AVENGING_WRATH_1:
                case BLESSING_OF_MIGHT_1:
                case BLESSING_OF_WISDOM_1:
                case BLESSING_OF_KINGS_1:
                case BLESSING_OF_SANCTUARY_1:
                    return true;
                case HOLY_SHOCK_1:
                    return HasRole(BOT_ROLE_HEAL);
                case DEVOTION_AURA_1:
                    return _aura != DEVOTIONAURA;
                case CONCENTRATION_AURA_1:
                    return _aura != CONCENTRATIONAURA;
                case FIRE_RESISTANCE_AURA_1:
                    return _aura != FIRERESAURA;
                case FROST_RESISTANCE_AURA_1:
                    return _aura != FROSTRESAURA;
                case SHADOW_RESISTANCE_AURA_1:
                    return _aura != SHADOWRESAURA;
                case RETRIBUTION_AURA_1:
                    return _aura != RETRIBUTIONAURA;
                case CRUSADER_AURA_1:
                    return _aura != CRUSADERAURA;
                case PURIFY_1:
                    return !GetSpell(CLEANSE_1);
                default:
                    return false;
            }
        }

        bool HasAbilitiesSpecifics() const override { return true; }
        void FillAbilitiesSpecifics(Player const* player, std::list<std::string> &specList) override
        {
            uint32 textId;
            switch (_aura)
            {
                case DEVOTIONAURA:      textId = BOT_TEXT_DEVOTION;         break;
                case CONCENTRATIONAURA: textId = BOT_TEXT_CONCENTRATION;    break;
                case FIRERESAURA:       textId = BOT_TEXT_FIRERESISTANCE;   break;
                case FROSTRESAURA:      textId = BOT_TEXT_FROSTRESISTANCE;  break;
                case SHADOWRESAURA:     textId = BOT_TEXT_SHADOWRESISTANCE; break;
                case RETRIBUTIONAURA:   textId = BOT_TEXT_RETRIBUTION;      break;
                case CRUSADERAURA:      textId = BOT_TEXT_CRUSADER;         break;
                case NOAURA: default:   textId = BOT_TEXT_NOAURA;           break;
            }
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_AURA) + ": " + LocalizedNpcText(player, textId));
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Paladin_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Paladin_spells_cc;
        }
        std::vector<uint32> const* GetHealingSpellsList() const override
        {
            return &Paladin_spells_heal;
        }
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Paladin_spells_support;
        }

        void InitHeals() override
        {
            SpellInfo const* spellInfo;
            if (InitSpell(me, HOLY_SHOCK_HEAL_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, HOLY_SHOCK_HEAL_1));
                _heals[HOLY_SHOCK_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[HOLY_SHOCK_1] = 0;

            if (InitSpell(me, HOLY_LIGHT_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, HOLY_LIGHT_1));
                _heals[HOLY_LIGHT_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[HOLY_LIGHT_1] = 0;

            if (InitSpell(me, FLASH_OF_LIGHT_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, FLASH_OF_LIGHT_1));
                _heals[FLASH_OF_LIGHT_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[FLASH_OF_LIGHT_1] = 0;
        }

    private:
        //Spells
        uint32 CLEANSE;
        //Timers
/*misc*/uint32 checkAuraTimer, checkSealTimer, checkShieldTimer, checkBeaconTimer, avDelayTimer, shieldDelayTimer;
        //Special
/*misc*/uint8 _aura;
/*misc*/int32 _sacDamage;

        typedef std::unordered_map<uint32 /*baseId*/, int32 /*amount*/> HealMap;
        HealMap _heals;

        //uint32 _getBlessingsMask(Unit const*) const
        //Scans target for auras which are related to paladin's blessings
        //(even if aura is just incompatible with one)
        //returns applied blessings mask
        //used for finding out which blessings target lacks
        uint32 _getBlessingsMask(Unit const* target) const
        {
            uint32 mask = 0;

            bool blessing;
            Unit::AuraApplicationMap const& aurapps = target->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = aurapps.begin(); itr != aurapps.end(); ++itr)
            {
                blessing = true;
                switch (itr->second->GetBase()->GetSpellInfo()->GetFirstRankSpell()->Id)
                {
                    case BLESSING_OF_WISDOM_1:
                    case GREATER_BLESSING_OF_WISDOM_1:
                        mask |= SPECIFIC_BLESSING_WISDOM;
                        break;
                    case BLESSING_OF_KINGS_1:
                    case GREATER_BLESSING_OF_KINGS_1:
                        mask |= SPECIFIC_BLESSING_KINGS;
                        break;
                    case BLESSING_OF_SANCTUARY_1:
                    case GREATER_BLESSING_OF_SANCTUARY_1:
                        mask |= SPECIFIC_BLESSING_SANCTUARY;
                        break;
                    case BLESSING_OF_MIGHT_1:
                    case GREATER_BLESSING_OF_MIGHT_1:
                    case BATTLESHOUT_1:
                        mask |= SPECIFIC_BLESSING_MIGHT;
                        break;
                    default:
                        blessing = false; //next aura
                        break;
                }

                if (blessing && itr->second->GetBase()->GetCasterGUID() == me->GetGUID())
                    mask |= SPECIFIC_BLESSING_MY_BLESSING;
            }

            return mask;
        }
        //uint32 _getAurasMask(Unit const*) const
        //Scans target for paladin's auras
        //returns applied auras mask
        //used for finding out which auras target lacks
        uint32 _getAurasMask(std::map<uint32 /*type*/, uint32 /*curId*/>& idMap) const
        {
            uint32 mask = 0;

            uint32 baseId;
            bool isAura;
            Unit::AuraApplicationMap const& aurapps = me->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = aurapps.begin(); itr != aurapps.end(); ++itr)
            {
                isAura = true;
                baseId = itr->second->GetBase()->GetSpellInfo()->GetFirstRankSpell()->Id;
                switch (baseId)
                {
                    case DEVOTION_AURA_1:
                        mask |= SPECIFIC_AURA_DEVOTION;
                        break;
                    case CONCENTRATION_AURA_1:
                        mask |= SPECIFIC_AURA_CONCENTRATION;
                        break;
                    case FIRE_RESISTANCE_AURA_1:
                        mask |= SPECIFIC_AURA_FIRE_RES;
                        break;
                    case FROST_RESISTANCE_AURA_1:
                        mask |= SPECIFIC_AURA_FROST_RES;
                        break;
                    case SHADOW_RESISTANCE_AURA_1:
                        mask |= SPECIFIC_AURA_SHADOW_RES;
                        break;
                    case RETRIBUTION_AURA_1:
                        mask |= SPECIFIC_AURA_RETRIBUTION;
                        break;
                    case CRUSADER_AURA_1:
                        mask |= SPECIFIC_AURA_CRUSADER;
                        break;
                    default:
                        isAura = false; //next aura
                        break;
                }

                if (isAura)
                {
                    idMap[baseId] = itr->first;
                    if (itr->second->GetBase()->GetCasterGUID() == me->GetGUID())
                        mask |= SPECIFIC_AURA_MY_AURA;
                }
            }

            return mask;
        }
    };
};

void AddSC_paladin_bot()
{
    new paladin_bot();
}
