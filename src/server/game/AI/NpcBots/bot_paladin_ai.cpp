#include "bot_ai.h"
#include "botmgr.h"
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
    //JUDGEMENT_OF_WISDOM_AURA            = 20186,
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
    IMMUNITY_SHIELD_MARKER_SPELL        = 61988
};

class paladin_bot : public CreatureScript
{
public:
    paladin_bot() : CreatureScript("paladin_bot") { }

    CreatureAI* GetAI(Creature* creature) const
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
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        void CheckBeacon(uint32 diff)
        {
            if (checkBeaconTimer > diff || !IsSpellReady(BEACON_OF_LIGHT_1, diff) || IAmFree() || !master->GetGroup() ||
                !HasRole(BOT_ROLE_HEAL|BOT_ROLE_RANGED) || IsCasting() || Rand() > 15)
                return;

            checkBeaconTimer = urand(2000, 5000);

            if (FindAffectedTarget(GetSpell(BEACON_OF_LIGHT_1), me->GetGUID(), 60, 3))
                return;

            //find tank
            //stacks
            std::list<Unit*> tanks;
            Group const* gr = master->GetGroup();
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* player = itr->GetSource();
                if (!player || !player->IsInWorld() || me->GetMap() != player->FindMap())
                    continue;

                if (player->IsAlive() && player->IsInCombat() && IsTank(player) &&
                    (!player->getAttackers().empty() || GetHealthPCT(player) < 90) &&
                    !player->GetAuraEffect(SPELL_AURA_PERIODIC_TRIGGER_SPELL, SPELLFAMILY_PALADIN, 0x0, 0x1000000, 0x0, me->GetGUID()))
                    tanks.push_back(player);

                if (!player->HaveBot())
                    continue;

                BotMap const* map = player->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                {
                    if (itr->second == me)
                        continue;
                    if (!gr->IsMember(itr->second->GetGUID()))
                        continue;

                    Unit* u = itr->second;
                    if (u->IsInWorld() && u->IsAlive() && u->IsInCombat() && IsTank(u) &&
                        (!u->getAttackers().empty() || GetHealthPCT(u) < 90) &&
                        !u->GetAuraEffect(SPELL_AURA_PERIODIC_TRIGGER_SPELL, SPELLFAMILY_PALADIN, 0x0, 0x1000000, 0x0, me->GetGUID()))
                        tanks.push_back(u);
                }
            }

            if (tanks.empty())
                return;

            Unit* target = tanks.size() == 1 ? *tanks.begin() : Trinity::Containers::SelectRandomContainerElement(tanks);
            if (doCast(target, GetSpell(BEACON_OF_LIGHT_1)))
                return;
        }

        void CheckSacrifice(uint32 diff)
        {
            if (!IsSpellReady(DIVINE_SACRIFICE_1, diff) || IAmFree() || me->IsMounted() ||
                IsTank() || Feasting() || !CanBlock() || IsCasting() || Rand() > 25 || GetHealthPCT(me) < 50)
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
                uint32 attacked = 0;
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player const* pl = itr->GetSource();
                    if (!pl || !pl->IsInWorld() || me->GetMap() != pl->FindMap())
                        continue;

                    if (pl->IsAlive() && me->GetDistance(pl) < 30 && !pl->getAttackers().empty() &&
                        !pl->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELLFAMILY_PALADIN, 3837, EFFECT_0))
                    {
                        if (++attacked > 3)
                            break;
                    }

                    if (!pl->HaveBot())
                        continue;

                    BotMap const* map = pl->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature const* bot = it->second;
                        if (bot && bot->IsInWorld() && me->GetMap() == bot->FindMap() && bot->IsAlive() &&
                            !bot->IsTempBot() && me->GetDistance(bot) < 30 && !bot->getAttackers().empty() &&
                            !bot->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, SPELLFAMILY_PALADIN, 3837, EFFECT_0))
                        {
                            if (++attacked > 3)
                                break;
                        }
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
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* pl = itr->GetSource();
                    if (!pl || !pl->IsInWorld() || me->GetMap() != pl->FindMap())
                        continue;

                    if (pl->IsAlive() && me->GetDistance(pl) < 30 && !pl->getAttackers().empty() &&
                        (pl->getAttackers().size() > 2 || GetHealthPCT(pl) < 50) &&
                        !pl->GetAuraEffect(SPELL_AURA_SPLIT_DAMAGE_PCT, SPELLFAMILY_PALADIN, 0x2000, 0x0, 0x0))
                    {
                        u = pl;
                        break;
                    }

                    if (!pl->HaveBot())
                        continue;

                    BotMap const* map = pl->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* bot = it->second;
                        if (bot->IsAlive() && me->GetDistance(bot) < 30 && !bot->getAttackers().empty() &&
                            (bot->getAttackers().size() > 2 || GetHealthPCT(bot) < 50) &&
                            !bot->GetAuraEffect(SPELL_AURA_SPLIT_DAMAGE_PCT, SPELLFAMILY_PALADIN, 0x2000, 0x0, 0x0))
                        {
                            u = bot;
                            break;
                        }
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

            Unit* u;
            if (IAmFree())
            {
                u = me;
                if (u->IsInCombat() && (!u->getAttackers().empty() || u->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) &&
                    !u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                {
                    if (doCast(u, GetSpell(SACRED_SHIELD_1)))
                    {}
                }

                return;
            }

            if (IsTank())
            {
                if (Rand() > 15)
                    return;
            }
            else if (!HasRole(BOT_ROLE_HEAL) && Rand() > 10)
                return;

            if (FindAffectedTarget(GetSpell(SACRED_SHIELD_1), me->GetGUID(), 70, 3))
                return;

            bool foundTank = false;
            Group const* gr = master->GetGroup();
            if (!gr)
            {
                u = master;
                if (u->IsAlive() && u->IsInCombat() && IsTank(u) && me->GetDistance(u) < 30 &&
                    !u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                    foundTank = true;

                if (!foundTank)
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

                        foundTank = true;
                        break;
                    }
                }
                if (!foundTank)
                {
                    for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
                    {
                        u = *itr;
                        if (!u || !u->IsPet() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() ||
                            !IsTank(u) || me->GetDistance(u) > 30 ||
                            u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                            continue;

                        foundTank = true;
                        break;
                    }
                }
                if (!foundTank)
                {
                    u = master;
                    if (u->IsAlive() && u->IsInCombat() && !u->getAttackers().empty() && me->GetDistance(u) < 30 &&
                        !u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                        foundTank = true;
                }

                if (foundTank && doCast(u, GetSpell(SACRED_SHIELD_1)))
                    return;

                return;
            }

            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                u = itr->GetSource();
                if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() ||
                    !IsTank(u) || me->GetDistance(u) > 30 ||
                    u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                    continue;

                foundTank = true;
                break;
            }
            if (!foundTank)
            {
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* pl = itr->GetSource();
                    if (!pl || !pl->IsInWorld() || me->GetMap() != pl->FindMap())
                        continue;

                    if (pl->HaveBot())
                    {
                        BotMap const* map = pl->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                        {
                            u = it->second;
                            if (u != me && IsTank())
                                continue;
                            if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() ||
                                it->second->IsTempBot() || !IsTank(u) || me->GetDistance(u) > 30 ||
                                u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                                continue;

                            foundTank = true;
                            break;
                        }
                    }
                    if (!foundTank)
                    {
                        for (Unit::ControlList::const_iterator itr = master->m_Controlled.begin(); itr != master->m_Controlled.end(); ++itr)
                        {
                            u = *itr;
                            if (!u || !u->IsPet() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() ||
                                !IsTank(u) || me->GetDistance(u) > 30 ||
                                u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                                continue;

                            foundTank = true;
                            break;
                        }
                    }
                    if (foundTank)
                        break;
                }
            }
            if (!foundTank)
            {
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    u = itr->GetSource();
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap())
                        continue;

                    if (u->IsAlive() && u->IsInCombat() && !u->getAttackers().empty() && me->GetDistance(u) < 30 &&
                        !u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                    {
                        foundTank = true;
                        break;
                    }

                    if (!u->ToPlayer()->HaveBot())
                        continue;

                    BotMap const* map = u->ToPlayer()->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        if (it->second->IsTempBot())
                            continue;

                        u = it->second;
                        if (u->IsAlive() && u->IsInCombat() && !u->getAttackers().empty() && me->GetDistance(u) < 30 &&
                            !u->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 0x0, 0x80000, 0x0))
                        {
                            foundTank = true;
                            break;
                        }
                    }
                    if (foundTank)
                        break;
                }
            }

            if (foundTank && doCast(u, GetSpell(SACRED_SHIELD_1)))
                return;
        }

        void HOPGroup(uint32 diff)
        {
            if (!IsSpellReady(HAND_OF_PROTECTION_1, diff) || IAmFree() || me->IsMounted() || Feasting() || IsCasting() ||
                Rand() > 30)
                return;

            Unit* u;
            Player* player = master;
            Group const* gr = player->GetGroup();
            if (!gr)
            {
                u = player;
                if (u->IsInWorld() && me->GetMap() == u->FindMap())
                {
                    if (HOPTarget(u, diff))
                        return;
                }

                for (Unit::ControlList::const_iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                {
                    u = *itr;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() ||
                        u->isType(TYPEMASK_PLAYER) || !u->ToCreature()->IsNPCBot() || u->ToCreature()->IsTempBot() ||
                        IsTank(u) || me->GetDistance(u) > 30)
                        continue;
                    if (HOPTarget(u, diff))
                        return;
                }

                return;
            }

            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                u = itr->GetSource();
                if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() ||
                    IsTank(u) || me->GetDistance(u) > 30)
                    continue;
                if (HOPTarget(u, diff))
                    return;
            }
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* pl = itr->GetSource();
                if (!pl || !pl->IsInWorld() || me->GetMap() != pl->FindMap() || !pl->HaveBot())
                    continue;

                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                {
                    u = it->second;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() ||
                        it->second->IsTempBot() || IsTank(u) || me->GetDistance(u) > 30)
                        continue;
                    if (HOPTarget(u, diff))
                        return;
                }
            }
        }

        bool HOPTarget(Unit* target, uint32 diff)
        {
            if (target == me ||
                (target->GetTypeId() == TYPEID_PLAYER ? target->GetClass() == BOT_CLASS_PALADIN :
                target->ToCreature()->GetBotClass() == BOT_CLASS_PALADIN))
                return false; //paladins should use their own damn bubble
            if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 1) ||
                target->HasAuraTypeWithMiscvalue(SPELL_AURA_SCHOOL_IMMUNITY, 127))
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
                    if (target->GetTypeId() == TYPEID_PLAYER)
                        BotWhisper("Hand of Protection on you!", target->ToPlayer());
                    if (target != master)
                    {
                        std::ostringstream msg;
                        msg << "Hand of Protection on " << target->GetName() << '!';
                        BotWhisper(msg.str().c_str());
                    }
                }
                return true;
            }

            return false;
        }

        void HOFGroup(uint32 diff)
        {
            if (!IsSpellReady(HAND_OF_FREEDOM_1, diff) || me->IsMounted() || Feasting() || IsCasting() || Rand() > 20)
                return;

            if (IAmFree())
            {
                HOFTarget(me, diff);
                return;
            }

            Unit* u;
            Player* player = master;
            Group const* gr = player->GetGroup();
            if (!gr)
            {
                u = player;
                if (u->IsInWorld() && me->GetMap() == u->FindMap() &&
                    HOFTarget(u, diff))
                    return;

                for (Unit::ControlList::const_iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                {
                    u = *itr;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() ||
                        u->isType(TYPEMASK_PLAYER) || (!u->IsPet() && !u->ToCreature()->IsNPCBot()) ||
                        u->ToCreature()->IsTempBot() || me->GetDistance(u) > 30)
                        continue;
                    if (HOFTarget(u, diff))
                        return;
                }

                return;
            }

            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                u = itr->GetSource();
                if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || me->GetDistance(u) > 30)
                    continue;
                if (HOFTarget(u, diff))
                    return;
            }
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* pl = itr->GetSource();
                if (!pl || !pl->IsInWorld() || me->GetMap() != pl->FindMap() || !pl->HaveBot())
                    continue;

                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                {
                    u = it->second;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() ||
                        it->second->IsTempBot() || me->GetDistance(u) > 30)
                        continue;
                    if (HOFTarget(u, diff))
                        return;
                }
            }
        }

        bool HOFTarget(Unit* target, uint32 diff)
        {
            if (target->HasAuraType(SPELL_AURA_MECHANIC_IMMUNITY))
            {
                if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 11) &&
                    target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 7))
                    return false; //immune to root and snares
                if (me->GetLevel() >= 35 && target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, 12))
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
                if (spellInfo->GetAllEffectsMechanicMask() &
                    ((1<<MECHANIC_SNARE) | (1<<MECHANIC_ROOT) | (me->GetLevel() < 35 ? 0 : (1<<MECHANIC_STUN))))
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

            Unit* u;

            if (me->GetLevel() >= 26 && (IAmFree() || IsTank()))
            {
                u = me;
                if (u->IsInCombat() && !u->getAttackers().empty() &&
                    GetHealthPCT(u) < std::max<int32>(80 - 5 * u->getAttackers().size(), 25))
                    if (doCast(u, GetSpell(HAND_OF_SALVATION_1)))
                    {}
                return;
            }

            if (IAmFree())
                return;

            Group const* gr = master->GetGroup();
            if (!gr)
                 return;

            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                u = itr->GetSource();
                if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() ||
                    IsTank(u) || (IsTankingClass(u->GetClass()) && !me->GetMap()->IsRaid()) || me->GetDistance(u) > 30)
                    continue;

                if (HOSTarget(u, diff))
                    return;
            }
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* pl = itr->GetSource();
                if (!pl || !pl->IsInWorld() || me->GetMap() != pl->FindMap() || !pl->HaveBot())
                    continue;

                BotMap const* map = pl->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                {
                    u = it->second;
                    if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->IsAlive() || !u->IsInCombat() || it->second->IsTempBot() ||
                        IsTank(u) || (IsTankingClass(u->ToCreature()->GetBotClass()) && !me->GetMap()->IsRaid()) || me->GetDistance(u) > 30)
                        continue;
                    if (HOSTarget(u, diff))
                        return;
                }
            }
        }

        bool HOSTarget(Unit* target, uint32 diff)
        {
            if (target->HasAuraTypeWithFamilyFlags(SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE, SPELLFAMILY_PALADIN, 0x100))
                return false;

            Unit::AttackerSet const& t_attackers = target->getAttackers();
            if (t_attackers.empty())
                return false;

            for (Unit::AttackerSet::const_iterator iter = t_attackers.begin(); iter != t_attackers.end(); ++iter)
            {
                if (!(*iter)) continue;
                if (!(*iter)->CanHaveThreatList()) continue;
                if ((*iter)->getAttackers().size() < 3) continue; //would be useless
                if (target->GetDistance((*iter)) < 15)
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
            if (hp > 90 &&
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
            if (xppct >= 95 && hp >= 25)
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
                        BotWhisper("Lay on Hands on you!", target->ToPlayer());
                    if (target != master)
                    {
                        std::ostringstream msg;
                        msg << "Lay on Hands on " << (target == me ? "myself" : target->GetName()) << '!';
                        BotWhisper(msg.str().c_str());
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
            if (GetBotCommandState() == COMMAND_ATTACK && !force) return;
            SetBotCommandState(COMMAND_ATTACK);
            OnStartAttack(u);
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_ai::JustDied(u); }

        void BreakCC(uint32 diff) override
        {
            if (me->GetLevel() >= 35 && IsSpellReady(HAND_OF_FREEDOM_1, diff) && Rand() < 30 && me->HasAuraWithMechanic(1<<MECHANIC_STUN))
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

            DoNormalAttack(diff);
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            RezGroup(GetSpell(REDEMPTION_1));
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
            if (checkAuraTimer > diff || GC_Timer > diff || IsCasting() ||
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

            bool pureHealer = HasRole(BOT_ROLE_HEAL) && HasRole(BOT_ROLE_RANGED) && !HasRole(BOT_ROLE_TANK);

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
                (!RETRIBUTION_AURA || IsTank(master) || IsTank()))
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

        bool BuffTarget(Unit* target, uint32 diff) override
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
                if (target && doCast(opponent, GetSpell(HAMMER_OF_JUSTICE_1)))
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
            if ((opponent->GetCreatureType() == CREATURE_TYPE_UNDEAD || opponent->GetCreatureType() == CREATURE_TYPE_DEMON) &&
                !CCed(opponent) &&
                opponent->GetVictim() && !IsTank(opponent->GetVictim()) && opponent->GetVictim() != me &&
                GetHealthPCT(me) < 90 &&
                doCast(opponent, GetSpell(TURN_EVIL_1)))
                return;
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

            Unit* target = players.size() == 1 ? *players.begin() : Trinity::Containers::SelectRandomContainerElement(players);
            if (doCast(target, GetSpell(DIVINE_INTERVENTION_1)))
                return;
        }

        void DoNormalAttack(uint32 diff)
        {
            StartAttack(opponent, IsMelee());

            MoveBehind(opponent);

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

            if (!CanAffectVictim(SPELL_SCHOOL_MASK_HOLY))
                return;

            float dist = me->GetDistance(opponent);

            //HAMMER OF WRATH
            if (IsSpellReady(HAMMER_OF_WRATH_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 80 &&
                opponent->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT) && dist < 30)
            {
                if (doCast(opponent, GetSpell(HAMMER_OF_WRATH_1)))
                    return;
            }
            //HAND OF RECKONING //No GCD
            Unit* u = opponent->GetVictim();
            if (IsSpellReady(HAND_OF_RECKONING_1, diff, false) && u && u != me && dist < 30 &&
                opponent->GetTypeId() == TYPEID_UNIT && !opponent->IsControlledByPlayer() &&
                !CCed(opponent) && HasRole(BOT_ROLE_DPS) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (IsTank() && GetHealthPCT(u) < 30 && GetHealthPCT(me) > 67)) &&
                ((!IsTankingClass(u->GetClass()) && GetHealthPCT(u) < 80) || IsTank()) &&
                IsInBotParty(u) && Rand() < 50)
            {
                if (doCast(opponent, GetSpell(HAND_OF_RECKONING_1)))
                    return;
            }
            //HAND OF RECKONING 2 (distant)
            if (IsSpellReady(HAND_OF_RECKONING_1, diff, false) && u == me && IsTank() && HasRole(BOT_ROLE_DPS) && Rand() < 30 &&
                !(me->GetLevel() >= 40 && opponent->GetTypeId() == TYPEID_UNIT &&
                (opponent->ToCreature()->IsDungeonBoss() || opponent->ToCreature()->isWorldBoss())))
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
                me->GetDistance(u) < 40 && opponent->GetTypeId() == TYPEID_UNIT && !opponent->IsControlledByPlayer() &&
                !IsTankingClass(u->GetClass()) && GetHealthPCT(u) < 80 &&
                !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 67)) &&
                IsInBotParty(u) && Rand() < 20 + 30 * u->getAttackers().size())
            {
                if (doCast(u, GetSpell(RIGHTEOUS_DEFENSE_1)))
                    return;
            }
            //RIGHTEOUS DEFENSE 2 (distant)
            if (IsSpellReady(RIGHTEOUS_DEFENSE_1, diff, false) && !IAmFree() && u == me && IsTank() && Rand() < 30 &&
                !(me->GetLevel() >= 40 && opponent->GetTypeId() == TYPEID_UNIT &&
                (opponent->ToCreature()->IsDungeonBoss() || opponent->ToCreature()->isWorldBoss())))
            {
                Unit* tUnit = FindDistantTauntTarget(40, true);
                if (tUnit)
                {
                    if (doCast(tUnit, GetSpell(RIGHTEOUS_DEFENSE_1)))
                        return;
                }
            }
            //Divine Plea tanks only (Guarded by the Light synergy)
            if (IsSpellReady(DIVINE_PLEA_1, diff) && IsTank() && !HasRole(BOT_ROLE_HEAL) && Rand() < 30 &&
                dist < 10 && GetManaPCT(me) < 90 &&
                !me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x80004000, 0x1))
            {
                if (doCast(me, GetSpell(DIVINE_PLEA_1)))
                    return;
            }
            //Avenging Wrath (tank - big threat, dps - big hp, heal - divine plea counter)
            if (IsSpellReady(AVENGING_WRATH_1, diff, false) && avDelayTimer <= diff &&
                HasRole(BOT_ROLE_HEAL|BOT_ROLE_DPS) && Rand() < 35 && dist < 30 &&
                IsTank() ? (opponent->GetTypeId() == TYPEID_UNIT && (opponent->ToCreature()->IsDungeonBoss() || opponent->ToCreature()->isWorldBoss())) :
                (!HasRole(BOT_ROLE_HEAL) || !HasRole(BOT_ROLE_RANGED)) ? (opponent->GetHealth() > me->GetMaxHealth()/4 * (1 + opponent->getAttackers().size())) :
                (me->GetAuraEffect(SPELL_AURA_OBS_MOD_POWER, SPELLFAMILY_PALADIN, 0x0, 0x80004000, 0x1) != nullptr))
            {
                if (doCast(me, GetSpell(AVENGING_WRATH_1)))
                {}
            }
            //Avenger's shield
            if (IsSpellReady(AVENGERS_SHIELD_1, diff) && CanBlock() && (IsTank() || IAmFree()) &&
                HasRole(BOT_ROLE_DPS) && dist < 30 && Rand() < 60)
            {
                if (doCast(opponent, GetSpell(AVENGERS_SHIELD_1)))
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
            if (IsSpellReady(EXORCISM_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 30 && Rand() < 70 &&
                ((IsTank() && dist > 12) || (HasRole(BOT_ROLE_RANGED) && !HasRole(BOT_ROLE_HEAL)) ||
                me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_PALADIN, 0x0, 0x0, 0x2)))
            {
                if (doCast(opponent, GetSpell(EXORCISM_1)))
                    return;
            }
            //Hammer of Justice
            if (IsSpellReady(HAMMER_OF_JUSTICE_1, diff) && !CCed(opponent) && dist < 10 && Rand() < 20 &&
                opponent->GetDiminishing(DIMINISHING_STUN) <= DIMINISHING_LEVEL_2 &&
                !opponent->IsImmunedToSpellEffect(sSpellMgr->GetSpellInfo(HAMMER_OF_JUSTICE_1), 0, me))
            {
                if (doCast(opponent, GetSpell(HAMMER_OF_JUSTICE_1)))
                    return;
            }
            //Judgement
            if (GetSpellCooldown(JUDGEMENT_OF_LIGHT_1) <= diff && HasRole(BOT_ROLE_DPS) && Rand() < 120)
            {
                uint32 JUDGEMENT = 0;

                if (GetSpell(JUDGEMENT_OF_JUSTICE_1) && opponent->HasAuraType(SPELL_AURA_MOD_INCREASE_SPEED) &&
                    dist < CalcSpellMaxRange(JUDGEMENT_OF_JUSTICE_1))
                {
                    //has joj from someone else
                    bool canCast = true;
                    Unit::AuraEffectList const& notSpeedAuras = opponent->GetAuraEffectsByType(SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED);
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
                        Unit::AuraEffectList const& speedAuras = opponent->GetAuraEffectsByType(SPELL_AURA_MOD_INCREASE_SPEED);
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
                    //opponent->GetAuraEffect(JUDGEMENT_OF_WISDOM_AURA, 0, me->GetGUID()
                    AuraEffect const* wisd = opponent->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 3014, 0);
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

                if (JUDGEMENT && doCast(opponent, GetSpell(JUDGEMENT)))
                    return;
            }
            //Consecration
            if (IsSpellReady(CONSECRATION_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 5 &&
                !opponent->isMoving() && Rand() < 50)
            {
                if (doCast(me, GetSpell(CONSECRATION_1)))
                    return;
            }
            //Hammer of Righteous (1h only)
            if (IsSpellReady(HAMMER_OF_THE_RIGHTEOUS_1, diff) && (IsTank() || IAmFree()) && HasRole(BOT_ROLE_DPS) &&
                dist < 5 && Rand() < 80)
            {
                Item const* weapMH = GetEquips(BOT_SLOT_MAINHAND);
                if (weapMH &&
                    (weapMH->GetTemplate()->InventoryType == INVTYPE_WEAPON ||
                    weapMH->GetTemplate()->InventoryType == INVTYPE_WEAPONMAINHAND) &&
                    doCast(opponent, GetSpell(HAMMER_OF_THE_RIGHTEOUS_1)))
                    return;
            }
            //Shield of Righteousness
            if (IsSpellReady(SHIELD_OF_RIGHTEOUSNESS_1, diff) && HasRole(BOT_ROLE_DPS) && CanBlock() &&
                (IsTank() || IAmFree()) && dist < 5 && Rand() < 90)
            {
                if (doCast(opponent, GetSpell(SHIELD_OF_RIGHTEOUSNESS_1)))
                    return;
            }
            //Crusader Strike (2h only)
            if (IsSpellReady(CRUSADER_STRIKE_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 5 && Rand() < 90)
            {
                Item const* mh = GetEquips(BOT_SLOT_MAINHAND);
                if (mh && mh->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
                    if (doCast(opponent, GetSpell(CRUSADER_STRIKE_1)))
                        return;
            }
            //Divine Storm (2h only)
            if (IsSpellReady(DIVINE_STORM_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 7 && Rand() < 40)
            {
                Item const* mh = GetEquips(BOT_SLOT_MAINHAND);
                if (mh && mh->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
                    if (doCast(me, GetSpell(DIVINE_STORM_1)))
                        return;
            }
            //Holy Wrath
            if (IsSpellReady(HOLY_WRATH_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 50)
            {
                if ((opponent->GetCreatureType() == CREATURE_TYPE_UNDEAD || opponent->GetCreatureType() == CREATURE_TYPE_DEMON) &&
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
            if (lvl >= 30 && (baseId == HOLY_LIGHT_1 || baseId == HOLY_SHOCK_1))
                crit_chance += 6.f;
            //Holy Power: 5% additional critical chance for Holy spells
            if (lvl >= 35 && (schoolMask & SPELL_SCHOOL_MASK_HOLY))
                crit_chance += 5.f;
            //Improved Flash of Light (id: 20251): 6% additional critical chance for Flash of Light
            if (lvl >= 70 && baseId == FLASH_OF_LIGHT_1)
                crit_chance += 6.f;
            //Glyph of Flash of Light: 5% additional critical chance for Flash of Light
            if (lvl >= 20 && baseId == FLASH_OF_LIGHT_1)
                crit_chance += 5.f;
            //Sanctified Wrath: 50% additional critical chance for Hammer of Wrath
            if (lvl >= 45 && baseId == HAMMER_OF_WRATH_1)
                crit_chance += 50.f;
            //Fanaticism: 18% additional critical chance for all Judgements (not shure which check is right)
            if (lvl >= 45 && spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT)
                crit_chance += 18.f;
            //Infusion of Light
            if (baseId == HOLY_LIGHT_1)
            {
                if (AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 0))
                    if (infu->IsAffectedOnSpell(spellInfo))
                        crit_chance += 20.f;
            }
            if (baseId == HOLY_LIGHT_1 || baseId == FLASH_OF_LIGHT_1 || baseId == HOLY_SHOCK_1)
            {
                if (AuraEffect const* favo = me->GetAuraEffect(DIVINE_FAVOR_1, 0))
                    if (favo->IsAffectedOnSpell(spellInfo))
                        crit_chance += 100.f;
            }
        }

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool crit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            //if (crit)
            //{
            //}
            //Sanctity of Battle: 15% bonus damage for Exorcism and Crusader Strike
            if (lvl >= 25 && baseId == EXORCISM_1)
                pctbonus += 0.15f;
            //The Art of War (damage part): 10% bonus damage for Judgements, Crusader Strike and Divine Storm
            if (lvl >= 40 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT || baseId == CRUSADER_STRIKE_1 || baseId == DIVINE_STORM_1))
                pctbonus += 0.1f;
            //Judgements of the Pure (damage part): 25% bonus damage for Judgements and Seals
            if (lvl >= 50 &&
                (spellInfo->GetCategory() == SPELLCATEGORY_JUDGEMENT ||
                spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_SEAL ||
                baseId == JUDGEMENT_OF_COMMAND_DAMAGE))
                pctbonus += 0.25f;
            //Glyph of Exorcism: 20% bonus damage for Exorcism
            if (lvl >= 50 && baseId == EXORCISM_1)
                pctbonus += 0.2f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool crit) const override
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            //if (crit)
            //{
            //}

            //Judgements of the Pure (damage part): 25% bonus damage for Judgements and Seals
            if (lvl >= 50 &&
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
            if (lvl >= 15 && (baseId == HOLY_LIGHT_1 || baseId == FLASH_OF_LIGHT_1 || baseId == HOLY_SHOCK_1))
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
            if (lvl >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x2110))
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
                if (arto && arto->IsAffectedOnSpell(spellInfo))
                    timebonus += casttime;
                else if (infu && infu->IsAffectedOnSpell(spellInfo))
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
                    if (enli->IsAffectedOnSpell(spellInfo))
                        timebonus += 500;
                if (AuraEffect const* grac = me->GetAuraEffect(LIGHTS_GRACE_BUFF, 0))
                    if (grac->IsAffectedOnSpell(spellInfo))
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
            if (lvl >= 35 && (baseId == DIVINE_SHIELD_1 || baseId == DIVINE_PROTECTION_1))
                timebonus += 60000;
            //Reduced Righteous Defense Cooldown (37181): -2 sec cooldown for Righteous Defense
            if (lvl >= 60 && baseId == RIGHTEOUS_DEFENSE_1)
                timebonus += 2000;
            //Paladin T9 Tank 2P Bonus part 1: -2 sec cooldown for Hand of Reckoning
            if (lvl >= 60 && baseId == HAND_OF_RECKONING_1)
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
            if (lvl >= 35 && (baseId == EXORCISM_1 || baseId == HOLY_WRATH_1))
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
            if (lvl >= 25 && baseId == HAMMER_OF_JUSTICE_1)
                timebonus += 20000;
            //Judgements of the Just: -10 sec cooldown for Hammer of Justice (tanks only)
            if (lvl >= 55 && baseId == HAMMER_OF_JUSTICE_1 && IsTank())
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

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
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
            if (lvl >= 55 && (spellInfo->SpellFamilyFlags[0] & 0x800000) &&
                HasRole(BOT_ROLE_HEAL) && HasRole(BOT_ROLE_RANGED))
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

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == HOLY_LIGHT_1 || baseId == FLASH_OF_LIGHT_1 || baseId == HOLY_SHOCK_1)
            {
                if (AuraEffect const* favo = me->GetAuraEffect(DIVINE_FAVOR_1, 0))
                    if (favo->IsAffectedOnSpell(spellInfo))
                        me->RemoveAurasDueToSpell(DIVINE_FAVOR_1);
            }

            if (baseId == HOLY_LIGHT_1)
            {
                if (AuraEffect const* enli = me->GetAuraEffect(ENLIGHTENMENT_BUFF, 0))
                    if (enli->IsAffectedOnSpell(spellInfo))
                        me->RemoveAurasDueToSpell(ENLIGHTENMENT_BUFF);
                if (AuraEffect const* grac = me->GetAuraEffect(LIGHTS_GRACE_BUFF, 0))
                    if (grac->IsAffectedOnSpell(spellInfo))
                        me->RemoveAurasDueToSpell(LIGHTS_GRACE_BUFF);
                if (AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 0))
                    if (infu->IsAffectedOnSpell(spellInfo))
                        me->RemoveAurasDueToSpell(INFUSION_OF_LIGHT_BUFF);
            }

            if (baseId == EXORCISM_1 || baseId == FLASH_OF_LIGHT_1)
            {
                //Infusion of Light takes priority since AoW affects Exorcism too
                AuraEffect const* infu = me->GetAuraEffect(INFUSION_OF_LIGHT_BUFF, 1);
                //The Art of War
                AuraEffect const* arto = me->GetAuraEffect(THE_ART_OF_WAR_BUFF, 0);
                if (arto && arto->IsAffectedOnSpell(spellInfo))
                    me->RemoveAurasDueToSpell(THE_ART_OF_WAR_BUFF);
                else if (infu && infu->IsAffectedOnSpell(spellInfo))
                    me->RemoveAurasDueToSpell(INFUSION_OF_LIGHT_BUFF);
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
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
            if (lvl >= 55 && IsTank() && spell->GetCategory() == SPELLCATEGORY_JUDGEMENT)
            {
                me->CastSpell(target, JUDGEMENTS_OF_THE_JUST_AURA, true);
            }
            //Judgements of the Just melee attack speed reduction part 2
            if (spellId == JUDGEMENTS_OF_THE_JUST_AURA)
            {
                AuraEffect* slow = target->GetAuraEffect(JUDGEMENTS_OF_THE_JUST_AURA, 1, me->GetGUID());
                if (slow)
                    slow->ChangeAmount(slow->GetAmount() - 20);
            }

            if (spellId == SEAL_OF_JUSTICE_STUN_AURA)
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
            if (baseId == RETRIBUTION_AURA_1)
            {
                if (lvl >= 30)
                {
                    //Sanctified Retribution: 50% increased effect
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                        eff->ChangeAmount(eff->GetAmount() * 3 / 2);
                }
            }
            if (baseId == DEVOTION_AURA_1)
            {
                if (lvl >= 25)
                {
                    //Improved Devotion Aura: 50% increased effect
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                        eff->ChangeAmount(eff->GetAmount() * 3 / 2);
                }
            }
            if (baseId == CONCENTRATION_AURA_1)
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
                if (lvl >= 68 && HasRole(BOT_ROLE_HEAL) && !HasRole(BOT_ROLE_TANK | BOT_ROLE_DPS))
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
            if (baseId == HAND_OF_SALVATION_1 && !IsTank(target))
            {
                //Blessed Hands (part 2)
                if (AuraEffect* hos = target->GetAuraEffect(spellId, 0, me->GetGUID()))
                {
                    hos->ChangeAmount(hos->GetAmount() * 2);
                }
            }
            if (baseId == HAND_OF_SACRIFICE_1)
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
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
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

        void DamageTaken(Unit* u, uint32& /*damage*/) override
        {
            if (!u)
                return;
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        //healer may be nullptr
        void HealReceived(Unit* healer, uint32& heal) override
        {
            //Spiritual Attunement (double the effect on bots)
            if (heal && me->GetLevel() >= 40 && healer != me && HasRole(BOT_ROLE_TANK) && GetLostHP(me))
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

            InitSpellMap(FLASH_OF_LIGHT_1);
            InitSpellMap(HOLY_LIGHT_1);
            InitSpellMap(LAY_ON_HANDS_1);
            InitSpellMap(SACRED_SHIELD_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(HOLY_SHOCK_1) : RemoveSpell(HOLY_SHOCK_1);
            InitSpellMap(REDEMPTION_1);
            InitSpellMap(HAMMER_OF_JUSTICE_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(REPENTANCE_1) : RemoveSpell(REPENTANCE_1);
            InitSpellMap(TURN_EVIL_1);
            InitSpellMap(HOLY_WRATH_1);
            InitSpellMap(EXORCISM_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(SEAL_OF_COMMAND_1) : RemoveSpell(SEAL_OF_COMMAND_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(CRUSADER_STRIKE_1) : RemoveSpell(CRUSADER_STRIKE_1);
            InitSpellMap(JUDGEMENT_OF_LIGHT_1);
            InitSpellMap(JUDGEMENT_OF_WISDOM_1);
            InitSpellMap(JUDGEMENT_OF_JUSTICE_1);
            InitSpellMap(CONSECRATION_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(DIVINE_STORM_1) : RemoveSpell(DIVINE_STORM_1);
            InitSpellMap(HAMMER_OF_WRATH_1);
            InitSpellMap(AVENGING_WRATH_1);
            InitSpellMap(RIGHTEOUS_FURY_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(HOLY_SHIELD_1) : RemoveSpell(HOLY_SHIELD_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(AVENGERS_SHIELD_1) : RemoveSpell(AVENGERS_SHIELD_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(HAMMER_OF_THE_RIGHTEOUS_1) : RemoveSpell(HAMMER_OF_THE_RIGHTEOUS_1);
            InitSpellMap(SHIELD_OF_RIGHTEOUSNESS_1);
            InitSpellMap(BLESSING_OF_MIGHT_1);
            InitSpellMap(BLESSING_OF_WISDOM_1);
            InitSpellMap(BLESSING_OF_KINGS_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(BLESSING_OF_SANCTUARY_1) : RemoveSpell(BLESSING_OF_SANCTUARY_1);
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
  /*Talent*/lvl >= 20 ? InitSpellMap(DIVINE_SACRIFICE_1) : RemoveSpell(DIVINE_SACRIFICE_1);
            InitSpellMap(DIVINE_INTERVENTION_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(AURA_MASTERY_1) : RemoveSpell(AURA_MASTERY_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(DIVINE_FAVOR_1) : RemoveSpell(DIVINE_FAVOR_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(DIVINE_ILLUMINATION_1) : RemoveSpell(DIVINE_ILLUMINATION_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(BEACON_OF_LIGHT_1) : RemoveSpell(BEACON_OF_LIGHT_1);

            InitSpellMap(DIVINE_PROTECTION_1);
            InitSpellMap(DIVINE_SHIELD_1);

            CLEANSE = InitSpell(me, CLEANSE_1) ? CLEANSE_1 : PURIFY_1;
            RemoveSpell(CLEANSE_1);
            RemoveSpell(PURIFY_1);
            InitSpellMap(CLEANSE);

 /*SPECIAL*/InitSpellMap(ARDENT_DEFENDER_HEAL, true);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();

            RefreshAura(JUDGEMENTS_OF_THE_PURE, level >= 50 ? 1 : 0);
            RefreshAura(JUDGEMENTS_OF_THE_WISE, level >= 40 ? 1 : 0);
            RefreshAura(RECKONING5, level >= 50 ? 1 : 0);
            RefreshAura(RECKONING4, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(RECKONING3, level >= 40 && level < 45 ? 1 : 0);
            RefreshAura(RECKONING2, level >= 35 && level < 40 ? 1 : 0);
            RefreshAura(RECKONING1, level >= 30 && level < 35 ? 1 : 0);
            RefreshAura(VENGEANCE3, level >= 40 ? 1 : 0);
            RefreshAura(VENGEANCE2, level >= 37 && level < 40 ? 1 : 0);
            RefreshAura(VENGEANCE1, level >= 35 && level < 37 ? 1 : 0);
            RefreshAura(RIGHTEOUS_VENGEANCE3, level >= 60 ? 1 : 0);
            RefreshAura(RIGHTEOUS_VENGEANCE2, level >= 57 && level < 60 ? 1 : 0);
            RefreshAura(RIGHTEOUS_VENGEANCE1, level >= 55 && level < 57 ? 1 : 0);
            RefreshAura(SHEATH_OF_LIGHT3, level >= 60 ? 1 : 0);
            RefreshAura(SHEATH_OF_LIGHT2, level >= 55 && level < 60 ? 1 : 0);
            RefreshAura(SHEATH_OF_LIGHT1, level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(SACRED_CLEANSING, level >= 45 ? 1 : 0);
            RefreshAura(DIVINE_PURPOSE, level >= 35 ? 1 : 0);
            RefreshAura(VINDICATION2, level >= 25 ? 1 : 0);
            RefreshAura(VINDICATION1, level >= 20 && level < 25 ? 1 : 0);
            RefreshAura(PURSUIT_OF_JUSTICE, level >= 20 ? 1 : 0);
            RefreshAura(ART_OF_WAR, level >= 40 ? 1 : 0);
            RefreshAura(IMPROVED_LAY_ON_HANDS, level >= 30 ? 1 : 0);
            RefreshAura(FANATICISM, level >= 20 ? 1 : 0);
            RefreshAura(ARDENT_DEFENDER, level >= 40 ? 1 : 0);
            RefreshAura(ILLUMINATION, level >= 20 ? 1 : 0);
            RefreshAura(INFUSION_OF_LIGHT, level >= 55 ? 1 : 0);
            RefreshAura(REDOUBT3, level >= 55 ? 1 : 0);
            RefreshAura(REDOUBT2, level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(REDOUBT1, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(IMPROVED_RIGHTEOUS_FURY, level >= 20 ? 1 : 0);
            RefreshAura(SHIELD_OF_THE_TEMPLAR, level >= 55 ? 1 : 0);
            RefreshAura(IMPROVED_DEVOTION_AURA, level >= 25 ? 1 : 0);
            RefreshAura(IMPROVED_CONCENTRATION_AURA, level >= 25 ? 1 : 0);
            RefreshAura(SANCTIFIED_RETRIBUTION, level >= 30 ? 1 : 0);
            RefreshAura(LIGHTS_GRACE, level >= 40 ? 1 : 0);
            RefreshAura(DIVINE_GUARDIAN, level >= 25 ? 1 : 0);
            //RefreshAura(COMBAT_EXPERTISE, level >= 45 ? 1 : 0);
            RefreshAura(CRUSADE, level >= 25 ? 1 : 0);
            RefreshAura(ONE_HANDED_WEAPON_SPECIALIZATION, level >= 35 ? 1 : 0);
            RefreshAura(TWO_HANDED_WEAPON_SPECIALIZATION, level >= 30 ? 1 : 0);
            //RefreshAura(JUDGEMENTS_OF_THE_JUST, level >= 55 ? 1 : 0);
            RefreshAura(GUARDED_BY_THE_LIGHT, level >= 50 ? 1 : 0);
            RefreshAura(TOUCHED_BY_THE_LIGHT, level >= 50 ? 1 : 0);
            RefreshAura(HEART_OF_THE_CRUSADER, level >= 15 ? 1 : 0);
            RefreshAura(SWIFT_RETRIBUTION, level >= 50 ? 1 : 0);
            RefreshAura(GLYPH_HOLY_LIGHT, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_SALVATION, level >= 26 ? 1 : 0);

            RefreshAura(JUDGEMENT_ANTI_PARRY_DODGE_PASSIVE);

            RefreshAura(RECUCED_HOLY_LIGHT_CAST_TIME, level >= 65 ? 1 : 0);
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
        void FillAbilitiesSpecifics(std::list<std::string> &specList) override
        {
            std::ostringstream msg1;
            msg1 << "Aura: ";
            switch (_aura)
            {
                case DEVOTIONAURA:
                    msg1 << "Devotion Aura";
                    break;
                case CONCENTRATIONAURA:
                    msg1 << "Concentration Aura";
                    break;
                case FIRERESAURA:
                    msg1 << "Fire Resistance Aura";
                    break;
                case FROSTRESAURA:
                    msg1 << "Frost Resistance Aura";
                    break;
                case SHADOWRESAURA:
                    msg1 << "Shadow Resistance Aura";
                    break;
                case RETRIBUTIONAURA:
                    msg1 << "Retribution Aura";
                    break;
                case CRUSADERAURA:
                    msg1 << "Crusader Aura";
                    break;
                case NOAURA:
                default:
                    msg1 << "No Aura";
                    break;
            }
            specList.push_back(msg1.str());
        }

        void InitHeals() override
        {
            SpellInfo const* spellInfo;
            if (InitSpell(me, HOLY_SHOCK_HEAL_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, HOLY_SHOCK_HEAL_1));
                _heals[HOLY_SHOCK_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->Effects[0].CalcValue(me), HEAL, 0, nullptr);
            }
            else
                _heals[HOLY_SHOCK_1] = 0;

            if (InitSpell(me, HOLY_LIGHT_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, HOLY_LIGHT_1));
                _heals[HOLY_LIGHT_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->Effects[0].CalcValue(me), HEAL, 0, nullptr);
            }
            else
                _heals[HOLY_LIGHT_1] = 0;

            if (InitSpell(me, FLASH_OF_LIGHT_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, FLASH_OF_LIGHT_1));
                _heals[FLASH_OF_LIGHT_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->Effects[0].CalcValue(me), HEAL, 0, nullptr);
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
