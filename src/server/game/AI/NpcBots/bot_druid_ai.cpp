#include "bot_ai.h"
#include "botmgr.h"
#include "bottext.h"
#include "bottraits.h"
#include "Containers.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "World.h"
/*
Druid NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - 85-90%
TODO: Resolve remaining bugs with wrong power type after death
TODO2: PvP behaviour revamp (again, it's like 5th time?)
*/

#define MAX_TREANTS 3

enum DruidBaseSpells
{
    MARK_OF_THE_WILD_1                  = 1126,
    THORNS_1                            = 467,
    HEALING_TOUCH_1                     = 5185,
    REGROWTH_1                          = 8936,
    REJUVENATION_1                      = 774,
    LIFEBLOOM_1                         = 33763,
    NOURISH_1                           = 50464,
    WILD_GROWTH_1                       = 48438,
    SWIFTMEND_1                         = 18562,
    TRANQUILITY_1                       = 740,
    REVIVE_1                            = 50769,
    REBIRTH_1                           = 20484,
    BEAR_FORM_1                         = 5487,
    SWIPE_BEAR_1                        = 779,
    MANGLE_BEAR_1                       = 33878,
    BASH_1                              = 5211,
    MAUL_1                              = 6807,
    FERAL_CHARGE_BEAR_1                 = 16979,
    CHALLENGING_ROAR_1                  = 5209,
    ENRAGE_1                            = 5229,
    FRENZIED_REGENERATION_1             = 22842,
    GROWL_1                             = 6795,
    LACERATE_1                          = 33745,
    SURVIVAL_INSTINCTS_1                = 61336,
    FAERIE_FIRE_FERAL_1                 = 16857,//chains threat and damage spell regardless of bot feral form
    BERSERK_1                           = 50334,
    CAT_FORM_1                          = 768,
    CLAW_1                              = 1082,
    RAKE_1                              = 1822,
    SHRED_1                             = 5221,
    MANGLE_CAT_1                        = 33876,
    RIP_1                               = 1079,
    FEROCIOUS_BITE_1                    = 22568,
    POUNCE_1                            = 9005,
    RAVAGE_1                            = 6785,
    MAIM_1                              = 22570,
    SWIPE_CAT_1                         = 62078,
    SAVAGE_ROAR_1                       = 52610,
    FERAL_CHARGE_CAT_1                  = 49376,
    COWER_1                             = 8998,
    DASH_1                              = 1850,
    TIGERS_FURY_1                       = 5217,
    PROWL_1                             = 5215,
    MOONFIRE_1                          = 8921,
    STARFIRE_1                          = 2912,
    WRATH_1                             = 5176,
    HURRICANE_1                         = 16914,
    FAERIE_FIRE_NORMAL_1                = 770,
    INSECT_SWARM_1                      = 5570,
    TYPHOON_1                           = 50516,
    STARFALL_1                          = 48505,
    MOONKIN_FORM_1                      = 24858,
    TREE_OF_LIFE_FORM_1                 = 33891,
    TRAVEL_FORM_1                       = 783,
    AQUATIC_FORM_1                      = 1066,
    FLIGHT_FORM_1                       = 33943,
    ABOLISH_POISON_1                    = 2893,//manual use only
    CURE_POISON_1                       = 8946,
    REMOVE_CURSE_1                      = 2782,
    ENTANGLING_ROOTS_1                  = 339,
    CYCLONE_1                           = 33786,
    HIBERNATE_1                         = 2637,
    BARKSKIN_1                          = 22812,
    NATURES_GRASP_1                     = 16689,
    INNERVATE_1                         = 29166,
    NATURES_SWIFTNESS_1                 = 17116
};
enum DruidPassives
{
//Talents
    OMEN_OF_CLARITY                     = 16864,//clearcast
    NATURESGRACE                        = 61346,//rank 3
    NATURAL_PERFECTION1                 = 33881,
    NATURAL_PERFECTION2                 = 33882,
    NATURAL_PERFECTION3                 = 33883,
    LIVING_SEED1                        = 48496,
    LIVING_SEED2                        = 48499,
    LIVING_SEED3                        = 48500,
    REVITALIZE1                         = 48539,
    REVITALIZE2                         = 48544,
    REVITALIZE3                         = 48545,
    NATURALIST                          = 17073,//rank 5
    IMPROVED_MARK_OF_THE_WILD           = 17051,//rank 2
    FUROR                               = 17061,//rank 5
    INTENSITY                           = 17108,//rank 3
    LIVING_SPIRIT                       = 34153,//rank 3
    GIFT_OF_THE_EARTHMOTHER             = 51183,//rank 5
    ECLIPSE                             = 48525,//rank 3
    EARTH_AND_MOON                      = 48511,//rank 3
    SURVIVAL_OF_THE_FITTEST             = 33856,//rank 3
    DREAMSTATE                          = 33956,//rank 3
    BALANCE_OF_POWER                    = 33596,//rank 2
    IMPROVED_MOONKIN_FORM               = 48396,//rank 3
    OWLKIN_FRENZY                       = 48393,//rank 3 NOT REFRESHAURABLE
    FERAL_SWIFTNESS                     = 24866,//rank 2 NOT REFRESHAURABLE
    PRIMAL_PRECISION                    = 48410,//rank 2 expertise only, refund handled in Spell.cpp
    NATURAL_REACTION                    = 57881,//rank 3 NOT REFRESHAURABLE
    IMPROVED_LEADER_OF_THE_PACK         = 34300,//rank 2
    PRIMAL_TENACITY                     = 33957,//rank 3
    PREDATORY_INSTINCTS                 = 33867,//rank 3 NOT REFRESHAURABLE
    KING_OF_THE_JUNGLE                  = 48495,//rank 3
    PRIMAL_GORE                         = 63503,//rank 1
//Glyphs
    GLYPH_NOURISH                       = 62971,
    GLYPH_SWIFTMEND                     = 54824,//no consumption
    GLYPH_INNERVATE                     = 54832,//self regen
    GLYPH_RAPID_REJUVENATION            = 71013,
    GLYPH_REGROWTH                      = 54743,
    GLYPH_REJUVENATION                  = 54754,
    GLYPH_FRENZIED_REGENERATION         = 54810,
    GLYPH_BARKSKIN                      = 63057,
    GLYPH_RAKE                          = 54821,
    GLYPH_SHRED                         = 54815,
//other
    T10_RESTO_P4_BONUS                  = 70664,//rejuve jump
    T9_RESTO_P4_BONUS                   = 67128,//rejuve crits
    T8_RESTO_P4_BONUS                   = 64760,//rejuve init heal

    T8_BALANCE_P4_BONUS                 = 64824,//insect swarm periodic starfire instacast trigger
    T9_BALANCE_P2_BONUS                 = 67125,//moonfire crits
    T10_BALANCE_P2_BONUS                = 70718,//omen of doom (15%)
    T10_BALANCE_P4_BONUS                = 70723,//Languish(DOT)

    T10_FERAL_P4_BONUS                  = 70726,//rake crit, enraged defense
    T8_FERAL_P2_BONUS                   = 64752,//periodic clearcast trigger
};
enum DruidSpecial
{
    STARFALL_DAMAGE_AOE_4               = 53190,//for radius mods
    //STARFALL_DAMAGE_DIRECT_4            = 53195,
    STARFALL_DUMMY_AOE_4                = 53198,//for radius mods

    HURRICANE_DAMAGE_1                  = 42231,
    //TRANQUILITY_HEAL_1                  = 44203,
    //TYPHOON_DAMAGE_1                    = 61391,

    SAVAGE_ROAR_BUFF                    = 62071,//hidden buff
    PREDATORS_SWIFTNESS_BUFF            = 69369,
    LEADER_OF_THE_PACK_BUFF             = 24932,
    NURTURING_INSTINCT_BUFF             = 47180,//rank 2 hidden NOT REFRESHAURABLE
    SURVIVAL_OF_THE_FITTEST_BUFF        = 62069,//hidden buff
    SAVAGE_DEFENSE_PASSIVE              = 62600,//class passive lvl 40
    SAVAGE_DEFENSE_BUFF                 = 62606,
    MASTER_SHAPESHIFTER_BEAR_BUFF       = 48418,
    MASTER_SHAPESHIFTER_CAT_BUFF        = 48420,
    MASTER_SHAPESHIFTER_MOONKIN_BUFF    = 48421,
    MASTER_SHAPESHIFTER_TREE_BUFF       = 48422,
    //NATURESGRACEBUFF                    = 16886,
    ECLIPSE_SOLAR_BUFF                  = 48517,// from Starfire to Wrath
    ECLIPSE_LUNAR_BUFF                  = 48518,// from Wrath to Starfire
    ELUNES_WRATH_BUFF                   = 64823,//Starfire instacast
    OMEN_OF_CLARITY_BUFF                = 16870,

    //FERAL_CHARGE_EFFECT_BEAR_ROOT       = 45334,
    //FERAL_CHARGE_EFFECT_CAT_DAZE        = 50259,
    INFECTED_WOUNDS_EFFECT              = 58181,//rank 3
    PRIMAL_FURY_EFFECT_ENERGIZE         = 16959,//5 rage

    FORCE_OF_NATURE_1                   = 33831 //not casted
};

static const uint32 Druid_spells_damage_arr[] =
{ FAERIE_FIRE_FERAL_1, CLAW_1, FEROCIOUS_BITE_1, MAIM_1, MANGLE_CAT_1, POUNCE_1, RAKE_1, RAVAGE_1, RIP_1, SHRED_1,
SWIPE_CAT_1, LACERATE_1, MANGLE_BEAR_1, MAUL_1,SWIPE_BEAR_1, ENTANGLING_ROOTS_1, HURRICANE_1, INSECT_SWARM_1,
WRATH_1, MOONFIRE_1, STARFALL_1, STARFIRE_1, TYPHOON_1, THORNS_1 };

static const uint32 Druid_spells_cc_arr[] =
{ BASH_1, CYCLONE_1, ENTANGLING_ROOTS_1, FERAL_CHARGE_BEAR_1, HIBERNATE_1, MAIM_1, POUNCE_1, TYPHOON_1 };

static const uint32 Druid_spells_heal_arr[] =
{ HEALING_TOUCH_1, LIFEBLOOM_1, NOURISH_1, REGROWTH_1, REJUVENATION_1, SWIFTMEND_1, TRANQUILITY_1, WILD_GROWTH_1 };

static const uint32 Druid_spells_support_arr[] =
{ ABOLISH_POISON_1, BARKSKIN_1, BERSERK_1, CHALLENGING_ROAR_1, COWER_1, CURE_POISON_1, DASH_1, ENRAGE_1,
FAERIE_FIRE_NORMAL_1, FAERIE_FIRE_FERAL_1, FERAL_CHARGE_BEAR_1, FERAL_CHARGE_CAT_1, FRENZIED_REGENERATION_1,
GROWL_1, INNERVATE_1, MARK_OF_THE_WILD_1, NATURES_GRASP_1, NATURES_SWIFTNESS_1, PROWL_1, REMOVE_CURSE_1,
REBIRTH_1, REVIVE_1, SAVAGE_ROAR_1, SURVIVAL_INSTINCTS_1, THORNS_1, TIGERS_FURY_1 };

static const std::vector<uint32> Druid_spells_damage(FROM_ARRAY(Druid_spells_damage_arr));
static const std::vector<uint32> Druid_spells_cc(FROM_ARRAY(Druid_spells_cc_arr));
static const std::vector<uint32> Druid_spells_heal(FROM_ARRAY(Druid_spells_heal_arr));
static const std::vector<uint32> Druid_spells_support(FROM_ARRAY(Druid_spells_support_arr));

static float rageLossMult;

class druid_bot : public CreatureScript
{
public:
    druid_bot() : CreatureScript("druid_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bot_druid_ai(creature);
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
    struct bot_druid_ai : public bot_ai
    {
        bot_druid_ai(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_DRUID;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { removeShapeshiftForm(); UnsummonAll(false); bot_ai::JustDied(u); }

        uint8 GetBotStance() const override
        {
            return _form;
        }

        bool removeShapeshiftForm() override
        {
            BotStances myform = _form;
            _form = BOT_STANCE_NONE;
            //ShapeshiftForm form = me->GetShapeshiftForm();
            //if (form != FORM_NONE)
            {
                switch (myform/*form*/)
                {
                    //case FORM_DIREBEAR:
                    //case FORM_BEAR:
                    case DRUID_BEAR_FORM:
                        if (IsRegenActive())
                            return false;
                        me->RemoveAurasDueToSpell(GetSpell(BEAR_FORM_1));
                        me->RemoveAurasDueToSpell(MASTER_SHAPESHIFTER_BEAR_BUFF);
                        me->RemoveAurasDueToSpell(NATURAL_REACTION);
                        me->RemoveAurasDueToSpell(SURVIVAL_OF_THE_FITTEST_BUFF);
                        me->RemoveAurasDueToSpell(SAVAGE_DEFENSE_PASSIVE);
                        break;
                    //case FORM_CAT:
                    case DRUID_CAT_FORM:
                        me->RemoveAurasDueToSpell(GetSpell(CAT_FORM_1));
                        me->RemoveAurasDueToSpell(FERAL_SWIFTNESS);
                        me->RemoveAurasDueToSpell(MASTER_SHAPESHIFTER_CAT_BUFF);
                        me->RemoveAurasDueToSpell(NURTURING_INSTINCT_BUFF);
                        me->RemoveAurasDueToSpell(PREDATORY_INSTINCTS);
                        break;
                    //case FORM_MOONKIN:
                    case DRUID_MOONKIN_FORM:
                        me->RemoveAurasDueToSpell(GetSpell(MOONKIN_FORM_1));
                        me->RemoveAurasDueToSpell(GetSpell(OWLKIN_FRENZY));
                        me->RemoveAurasDueToSpell(MASTER_SHAPESHIFTER_MOONKIN_BUFF);
                        break;
                    //case FORM_TREE:
                    case DRUID_TREE_FORM:
                        me->RemoveAurasDueToSpell(GetSpell(TREE_OF_LIFE_FORM_1));
                        me->RemoveAurasDueToSpell(MASTER_SHAPESHIFTER_TREE_BUFF);
                        break;
                    //case FORM_TRAVEL:
                    case DRUID_TRAVEL_FORM:
                        me->RemoveAurasDueToSpell(GetSpell(TRAVEL_FORM_1));
                        break;
                    //case FORM_AQUA:
                    case DRUID_AQUATIC_FORM:
                        me->RemoveAurasDueToSpell(GetSpell(AQUATIC_FORM_1));
                        break;
                    //case FORM_FLIGHT:
                    //case FORM_FLIGHT_EPIC:
                    case DRUID_FLIGHT_FORM:
                        me->RemoveAurasDueToSpell(GetSpell(FLIGHT_FORM_1));
                        break;
                    default:
                        break;
                }

                if (me->GetPowerType() != POWER_MANA)
                {
                    //TC_LOG_ERROR("entities.player", "druid_bot::removeShapeshiftForm(): still has poweType {}!", uint32(me->GetPowerType()));
                    me->SetPowerType(POWER_MANA);
                }
                if (me->GetShapeshiftForm() != FORM_NONE)
                {
                    //TC_LOG_ERROR("entities.player", "druid_bot::removeShapeshiftForm(): still speshifted into {}!", uint32(me->GetShapeshiftForm()));
                    me->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT, me->GetGUID(), nullptr, false);
                }

                setStats(BOT_STANCE_NONE);
            }
            return true;
        }

        //bool IsMelee() const
        //{
        //    return bot_ai::IsMelee() && (_form == DRUID_BEAR_FORM || _form == DRUID_CAT_FORM);
        //}

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            if (_form == DRUID_BEAR_FORM && HasRole(BOT_ROLE_RANGED) && IsSpellReady(BASH_1, GetLastDiff(), false))
                return;
            GetInPosition(force, u);
        }

        bool MassGroupHeal(Player* gPlayer, uint32 diff)
        {
            if (!HasRole(BOT_ROLE_HEAL)) return false;
            if (!gPlayer || GC_Timer > diff || IAmFree()) return false;
            if (IsCasting()) return false; // if I'm already casting
            if (Rand() > 30 + 50 * (me->GetMap()->IsRaid())) return false;
            if (!gPlayer->GetGroup()) return false;

            bool tranq = IsSpellReady(TRANQUILITY_1, diff, false);
            bool growt = IsSpellReady(WILD_GROWTH_1, diff, false) && !HasRole(BOT_ROLE_DPS);
            if (!tranq && !growt)
                return false;

            uint8 LHPcount = 0;
            uint8 pct = 100;
            Unit* healTarget = nullptr;
            std::vector<Unit*> members = BotMgr::GetAllGroupMembers(master);
            std::vector<Unit*> groupUnits;
            groupUnits.reserve(members.size());

            for (Unit* member : members)
            {
                if (me->GetMap() != member->FindMap() || member->isPossessed() || member->IsCharmed() ||
                    !member->IsAlive() || me->GetDistance(member) > 40)
                    continue;
                if (growt)
                    groupUnits.push_back(member);
                if (tranq && GetHealthPCT(member) < 80)
                {
                    if (GetHealthPCT(member) < pct)
                    {
                        pct = GetHealthPCT(member);
                        healTarget = member;
                    }
                    ++LHPcount;
                    if (LHPcount > 2)
                        break;
                }
            }

            if (LHPcount > 2 && tranq &&
                doCast(me, GetSpell(TRANQUILITY_1)))
                return true;

            healTarget = nullptr;
            for (Unit* gUnit : groupUnits)
            {
                LHPcount = 0;
                for (Unit* member : members)
                {
                    if (me->GetMap() != member->FindMap() || member->isPossessed() || member->IsCharmed() ||
                        !member->IsAlive() || me->GetDistance(member) > 40)
                        continue;
                    if (gUnit->GetDistance(member) < 15 && (GetLostHP(member) > 2000 || GetHealthPCT(member) < 90))
                        if (++LHPcount >= 3)
                            break;
                }

                if (LHPcount >= 3)
                {
                    healTarget = gUnit;
                    break;
                }
            }

            if (LHPcount >= 3 && growt && healTarget &&
                doCast(healTarget, GetSpell(WILD_GROWTH_1)))
                return true;

            return false;
        }

        //Powers
        //rage
        void getrage()
        {
            rage = me->GetPower(POWER_RAGE);
            if (me->FindCurrentSpellBySpellId(GetSpell(MAUL_1)))
                rage = std::max<int32>(rage - 150, 0);
        }

        //energy
        void getenergy()
        {
            energy = me->GetPower(POWER_ENERGY);
        }

        //all
        int32 acost(uint32 spellId) const
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                return spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask());
            return 0;
        }

        bool IsRegenActive() const
        {
            return me->IsAlive() && me->IsInCombat() && rage > 100 && GetHealthPCT(me) < 90 &&
                me->GetAuraEffect(SPELL_AURA_PERIODIC_DUMMY, SPELLFAMILY_DRUID, 0x0, 0x40000000, 0x0);
        }

        void CheckBarkskin(uint32 diff)
        {
            if (!me->IsAlive())
                return;
            if (me->GetVehicle())
                return;
            //No GCD
            if (IsSpellReady(BARKSKIN_1, diff, false) && !IsCasting() && !me->getAttackers().empty() &&
                Rand() < (25 + 20 * me->getAttackers().size()) &&
                GetHealthPCT(me) < (IsTank() ? 67 : 70 + 25 * me->getAttackers().size()))
            {
                if (doCast(me, GetSpell(BARKSKIN_1)))
                {}
            }
        }

        void CheckHibery(uint32 diff)
        {
            if (hiberyCheckTimer <= diff)
            {
                hibery = FindAffectedTarget(GetSpell(HIBERNATE_1), me->GetGUID());
                hiberyCheckTimer = 2000;
            }
        }

        void CheckHibernate(uint32 diff)
        {
            if (!(_form == DRUID_MOONKIN_FORM || _form == BOT_STANCE_NONE))
                return;
            //Skip Tranquility, Hurricane
            if (GC_Timer > diff || IsCasting() || Rand() > 35)
                return;

            if (hibery == false && IsSpellReady(HIBERNATE_1, diff))
            {
                if (Unit* target = FindStunTarget(30))
                {
                    if (doCast(target, GetSpell(HIBERNATE_1)))
                        return;
                }
            }
        }

        void Counter(uint32 diff)
        {
            if (!(_form == DRUID_MOONKIN_FORM || _form == BOT_STANCE_NONE))
                return;
            //Skip Tranquility, Hurricane
            if (GC_Timer > diff || Rand() > 35 || IsChanneling() || (HasRole(BOT_ROLE_HEAL) && IsCasting()))
                return;

            if (IsSpellReady(CYCLONE_1, diff))
            {
                if (Unit* target = FindCastingTarget(20, 0, CYCLONE_1))
                {
                    bool cast = false;
                    for (uint8 i = CURRENT_GENERIC_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
                    {
                        Spell const* spell = target->GetCurrentSpell(CurrentSpellTypes(i));
                        if (spell && spell->GetTimer() > 1500 &&
                            (IAmFree() ? (spell->m_targets.GetUnitTarget() == me) : (master->GetGroup() && master->GetGroup()->IsMember(spell->m_targets.GetObjectTargetGUID()))))
                        {
                            cast = true;
                            break;
                        }
                    }
                    if (cast)
                    {
                        me->InterruptNonMeleeSpells(false);
                        if (doCast(target, GetSpell(CYCLONE_1)))
                            return;
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->GetPowerType() == POWER_RAGE && me->IsAlive())
            {
                if (ragetimer <= diff)
                {
                    if (!me->IsInCombat() &&
                        !me->HasAuraTypeWithFamilyFlags(SPELL_AURA_PERIODIC_ENERGIZE, SPELLFAMILY_DRUID, 0x00080000)
                    /*!HasAuraName(me, ENRAGE_1)*/)
                    {
                        if (me->GetPower(POWER_RAGE) > uint32(10.f * rageLossMult))
                            me->SetPower(POWER_RAGE, me->GetPower(POWER_RAGE) - uint32(10.f * rageLossMult)); //-1 rage per 1.5 sec
                        else
                            me->SetPower(POWER_RAGE, 0);
                    }
                    ragetimer = 1500;
                }
                getrage();
            }
            else if (me->GetPowerType() == POWER_ENERGY)
                getenergy();

            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            CheckHibery(diff);
            CheckBarkskin(diff);

            if (IsPotionReady())
            {
                if (me->GetPowerType() == POWER_MANA && GetManaPCT(me) < 33)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 35)
                    DrinkPotion(false);
            }

            CheckRacials(diff);

            //Innervate
            doInnervate(diff);

            MassGroupHeal(master, diff);
            if (me->IsInCombat())
                CheckBattleRez(diff);
            else
                DoNonCombatActions(diff);

            if (HasRole(BOT_ROLE_RANGED) || !me->IsInCombat() || !me->GetVictim() ||
                (_form != DRUID_BEAR_FORM && (_form != DRUID_CAT_FORM || !me->GetMap()->IsRaid())))
                BuffAndHealGroup(diff);
            if (_form != DRUID_BEAR_FORM && _form != DRUID_CAT_FORM)
            {
                CureGroup(GetSpell(CURE_POISON_1), diff);
                CureGroup(GetSpell(REMOVE_CURSE_1), diff);
            }

            if (ProcessImmediateNonAttackTarget())
                return;

            CheckTravel(diff);

            if (!CheckAttackTarget())
            {
                if (!me->IsInCombat() && Rand() < 5 && me->HasAuraType(SPELL_AURA_MOD_STEALTH))
                    me->RemoveAurasDueToSpell(PROWL_1);
                return;
            }

            CheckHibernate(diff);
            Counter(diff);

            if (IsCasting())
                return;

            CheckUsableItems(diff);

            Attack(diff);
        }

        void Attack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, bot_ai::IsMelee());

            CheckAttackState();
            if (!me->IsAlive() || !mytar->IsAlive())
                return;

            //NOT all forms abilities (prioritized)
            //Cat Instaheal
            if (_form == DRUID_CAT_FORM && GC_Timer <= diff && Rand() < 60 &&
                HasRole(BOT_ROLE_HEAL) && GetHealthPCT(me) < 45 &&
                (me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_DRUID, 0x0, 0x80000, 0x0) ||/*me->HasAura(PREDATORS_SWIFTNESS_BUFF)*/
                (IsSpellReady(NATURES_SWIFTNESS_1, diff, false) && doCast(me, GetSpell(NATURES_SWIFTNESS_1)))))
            {
                //TODO maybe istant spells if clearcast?
                //heal myself with instant
                //Healing Touch has same reqs
                if ((GetSpell(REGROWTH_1) && !me->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x40, 0x0, 0x0) &&
                    doCast(me, GetSpell(REGROWTH_1))) || doCast(me, GetSpell(HEALING_TOUCH_1)))
                {
                    Position pos;
                    mytar->GetNearPoint(me, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 15.f, mytar->GetAbsoluteAngle(me));
                    GetInPosition(true, mytar, &pos);
                    return;
                }
            }
            //Roots
            if (_form != DRUID_BEAR_FORM && _form != DRUID_TREE_FORM && Rand() < 35 &&
                (HasRole(BOT_ROLE_DPS) || IAmFree()) && IsSpellReady(ENTANGLING_ROOTS_1, diff) &&
                (_form != DRUID_CAT_FORM || IAmFree() || me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_DRUID, 0x0, 0x80000, 0x0)
                /*me->HasAura(PREDATORS_SWIFTNESS_BUFF)*/))
                CheckRoots();

            //ALL forms abilities
            //Nature's Grasp (no shapeshift)
            if (IsSpellReady(NATURES_GRASP_1, diff) && HasRole(BOT_ROLE_DPS) && HasRole(BOT_ROLE_RANGED) && Rand() < 70 &&
                !me->getAttackers().empty())
            {
                if (doCast(me, GetSpell(NATURES_GRASP_1)))
                    return;
            }
            //Survival Instincts
            //No GCD, bear is lvl 10, SI is lvl 20
            //Shapeshift into bear if needed
            if (IsSpellReady(SURVIVAL_INSTINCTS_1, diff, false) && Rand() < 75 &&
                (GetHealthPCT(me) < (30 + 20 * (me->getAttackers().size() > 1))) &&
                (_form == DRUID_BEAR_FORM || (GC_Timer <= diff && doCast(me, GetSpell(BEAR_FORM_1)))))
            {
                if (doCast(me, SURVIVAL_INSTINCTS_1))
                    if (!IAmFree())
                        ReportSpellCast(SURVIVAL_INSTINCTS_1, LocalizedNpcText(master, BOT_TEXT__USED), master);
            }
            //Bash
            //Assuming Furor is present which is lvl 10
            //Shapeshift into bear if needed
            //bear is lvl 10, bash is lvl 14
            //Retreat is triggered only if hit (SpellHitTarget)
            if (IsSpellReady(BASH_1, diff) && !CCed(mytar, !mytar->IsNonMeleeSpellCast(false,false,true)) &&
                mytar->IsWithinMeleeRange(me))
            {
                if ((_form == DRUID_BEAR_FORM && rage >= acost(BASH_1)) ||
                    (IsSpellReady(BEAR_FORM_1, diff, false) && doCast(me, GetSpell(BEAR_FORM_1))))
                {
                    if (doCast(mytar, GetSpell(BASH_1)))
                        return;
                }
            }

            //Main mode
            //Choose form. Mode should be selected considering bot_ai::CheckAttackTarget() positioning selection
            //1 Tanking mode
            if ((IsTank() || (IsWanderer() && bot_ai::IsMelee() && !GetSpell(CAT_FORM_1))) && GetSpell(BEAR_FORM_1))
            {
                if (_form == DRUID_BEAR_FORM || (IsSpellReady(BEAR_FORM_1, diff, false) && doCast(me, GetSpell(BEAR_FORM_1))))
                    doBearActions(mytar, diff);
            }
            //2 Melee (tanking cat impossible: cat lvl 20, bear lvl 10)
            else if (bot_ai::IsMelee())
            {
                //if lvl < 20 then bot gonna just melee its targets
                if (_form == DRUID_CAT_FORM || (IsSpellReady(CAT_FORM_1, diff, false) && doCast(me, GetSpell(CAT_FORM_1))))
                    doCatActions(mytar, diff);
            }
            //3 Ranged dps
            else if (HasRole(BOT_ROLE_DPS))
            {
                //pure dps goes moonkin
                if (_form == DRUID_MOONKIN_FORM ||
                    ((!GetSpell(MOONKIN_FORM_1) || HasRole(BOT_ROLE_HEAL)) && (_form == BOT_STANCE_NONE || removeShapeshiftForm())) ||
                    (!HasRole(BOT_ROLE_HEAL) && IsSpellReady(MOONKIN_FORM_1, diff, false) && doCast(me, GetSpell(MOONKIN_FORM_1))))
                    doBalanceActions(mytar, diff);
            }
            //4 Healer
            else if (HasRole(BOT_ROLE_HEAL))
            {
                //pure healer goes tree
                if (_form == DRUID_TREE_FORM ||
                    ((!GetSpell(TREE_OF_LIFE_FORM_1) || HasRole(BOT_ROLE_DPS)) && (_form == BOT_STANCE_NONE || removeShapeshiftForm())) ||
                    (!HasRole(BOT_ROLE_DPS) && IsSpellReady(TREE_OF_LIFE_FORM_1, diff) && doCast(me, GetSpell(TREE_OF_LIFE_FORM_1))))
                {/*do nothing*/} //not a mistake
            }
        }

        void doBearActions(Unit* mytar, uint32 diff)
        {
            //debug
            if (me->GetPowerType() != POWER_RAGE || (me->GetShapeshiftForm() != FORM_BEAR && me->GetShapeshiftForm() != FORM_DIREBEAR))
                return;

            //Enrage
            if (IsSpellReady(ENRAGE_1, diff, false) && me->IsInCombat() && (rage < 400 || IsTank()) && Rand() < 40)
            {
                if (doCast(me, GetSpell(ENRAGE_1)))
                    getrage();
            }
            //Frenzied Regeneration
            if (IsSpellReady(FRENZIED_REGENERATION_1, diff) && rage > 700 && GetHealthPCT(me) < 70 && Rand() < 40)
            {
                if (doCast(me, GetSpell(FRENZIED_REGENERATION_1)))
                    return;
            }

            float dist = me->GetDistance(mytar);
            //GROWL //No GCD
            Unit* u = mytar->GetVictim();
            if (IsSpellReady(GROWL_1, diff, false) && u && u != me && Rand() < 40 && dist < 30 &&
                mytar->GetTypeId() == TYPEID_UNIT && !mytar->IsControlledByPlayer() &&
                !CCed(mytar) && !mytar->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (IsTank() && GetHealthPCT(me) > 67 &&
                (GetHealthPCT(u) < 30 || (IsOffTank() && !IsOffTank(u) && IsPointedOffTankingTarget(mytar)) ||
                (!IsOffTank() && IsOffTank(u) && IsPointedTankingTarget(mytar))))) &&
                ((!IsTankingClass(u->GetClass()) && GetHealthPCT(u) < 80) || IsTank()) &&
                IsInBotParty(u))
            {
                if (doCast(mytar, GetSpell(GROWL_1)))
                    return;
            }
            //GROWL 2 (distant)
            if (IsSpellReady(GROWL_1, diff, false) && !IAmFree() && u == me &&  Rand() < 20 && IsTank() &&
                (IsOffTank() || master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_TANK_OFF) == 0) &&
                !(me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())))
            {
                if (Unit* tUnit = FindDistantTauntTarget())
                {
                    if (doCast(tUnit, GetSpell(GROWL_1)))
                        return;
                }
            }
            //Challenging Roar
            if (IsSpellReady(CHALLENGING_ROAR_1, diff) &&
                !(u == me && me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())) &&
                rage >= acost(CHALLENGING_ROAR_1))
            {
                u = mytar->GetVictim();
                if (u && u != me && !IsTank(u) && IsInBotParty(u) && !CCed(mytar) && dist <= 10 && Rand() < 25 &&
                    (!IsTankingClass(u->GetClass()) || IsTank()))
                {
                    if (doCast(me, GetSpell(CHALLENGING_ROAR_1)))
                        return;
                }
                if (IsTank() && Rand() < 20)
                {
                    std::list<Unit*> targets;
                    GetNearbyTargetsList(targets, 9.f, 1);
                    uint8 count = 0;
                    for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        if (!((*itr)->GetVictim() && IsTank((*itr)->GetVictim())))
                            if (++count > 1)
                                break;
                    }
                    if (count > 1 && doCast(me, GetSpell(CHALLENGING_ROAR_1)))
                        return;
                }
            }

            if (!CanAffectVictimAny(mytar, SPELL_SCHOOL_NORMAL))
                return;

            //Feral Charge
            if (IsSpellReady(FERAL_CHARGE_BEAR_1, diff, false) && rage >= acost(FERAL_CHARGE_BEAR_1) &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                !CCed(mytar, true) && dist > 9 && dist < 25)
            {
                if (doCast(mytar, GetSpell(FERAL_CHARGE_BEAR_1)))
                    return;
            }

            //Faerie Fire (Feral, Bear)
            if (IsSpellReady(FAERIE_FIRE_FERAL_1, diff) && me->IsInCombat() && Rand() < 35 && dist < CalcSpellMaxRange(FAERIE_FIRE_FERAL_1) &&
                !mytar->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_RESISTANCE_PCT, SPELLFAMILY_DRUID, 0x400))
            {
                if (doCast(mytar, GetSpell(FAERIE_FIRE_FERAL_1)))
                    return;
            }

            //range check (melee) to prevent fake casts
            if (dist > 5) return;

            //Berserk (Bear)
            if (IsSpellReady(BERSERK_1, diff) && !HasRole(BOT_ROLE_HEAL) && rage > 400 && Rand() < 40 &&
                me->getAttackers().size() > 2)
            {
                if (doCast(me, GetSpell(BERSERK_1)))
                    return;
            }

            //BOT_ROLE_DPS is checked in Attack(uin32)
            //if (!HasRole(BOT_ROLE_DPS)) return;

            //frenzied regeneration check
            //we don't need to spend too much rage if regening
            bool isRegenActive = IsRegenActive();

            //Mangle (Bear)
            if (IsSpellReady(MANGLE_BEAR_1, diff) && rage >= acost(MANGLE_BEAR_1) + 200*isRegenActive)
            {
                if (me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x40) ||
                    (Rand() < 30 && !mytar->GetAuraEffect(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, SPELLFAMILY_DRUID, 0x0, 0x40, 0x0)))
                {
                    if (doCast(mytar, GetSpell(MANGLE_BEAR_1)))
                        return;
                }
            }
            //Swipe (Bear)
            if (IsSpellReady(SWIPE_BEAR_1, diff) && rage >= acost(SWIPE_BEAR_1) + 200*isRegenActive &&
                IsTank() && Rand() < 70)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsInConeList(targets, 5);
                if (targets.size() > 2)
                    if (doCast(mytar, GetSpell(SWIPE_BEAR_1)))
                        return;
            }
            //Lacerate
            if (IsSpellReady(LACERATE_1, diff) && rage >= acost(LACERATE_1) + 200*isRegenActive &&
                mytar->GetHealth() > me->GetMaxHealth() * 2 && Rand() < 45)
            {
                bool cast = rage >= 600;
                if (!cast)
                {
                    AuraApplication const* lacera = mytar->GetAuraApplicationOfRankedSpell(LACERATE_1);
                    cast = (!lacera || lacera->GetBase()->GetStackAmount() < 5 || lacera->GetBase()->GetDuration() < 6000);
                }

                if (cast && doCast(mytar, GetSpell(LACERATE_1)))
                    return;
            }

            //skip if maul is active
            if (me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                return;

            //Maul //No GCD
            if (IsSpellReady(MAUL_1, diff, false) && rage >= acost(MAUL_1) + 200 + 200*isRegenActive)
            {
                if (doCast(mytar, GetSpell(MAUL_1)))
                    return;
            }
        }

        void doCatActions(Unit* mytar, uint32 diff)
        {
            //debug
            if (me->GetPowerType() != POWER_ENERGY || me->GetShapeshiftForm() != FORM_CAT)
                return;

            //Prowl (for Cooldown handling see bot_ai::ReleaseSpellCooldown)
            if (IsSpellReady(PROWL_1, diff, false) && !me->IsInCombat() && Rand() < 50 && me->GetDistance(mytar) < 28 && !IsFlagCarrier(me))
            {
                if (doCast(me, GetSpell(PROWL_1)))
                {}
            }

            if (!CanAffectVictimAny(mytar, SPELL_SCHOOL_NORMAL))
                return;

            //Faerie Fire (Feral, Cat)
            if (IsSpellReady(FAERIE_FIRE_FERAL_1, diff) && me->IsInCombat() && !me->HasAuraType(SPELL_AURA_MOD_STEALTH) &&
                Rand() < 35 && me->GetDistance(mytar) < 30 &&
                !mytar->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_RESISTANCE_PCT, SPELLFAMILY_DRUID, 0x400))
            {
                if (doCast(mytar, GetSpell(FAERIE_FIRE_FERAL_1)))
                    return;
            }

            if (!JumpingOrFalling() && !CCed(me, true))
            {
                //leap here
                //Feral Charge (Cat)
                if (IsSpellReady(FERAL_CHARGE_CAT_1, diff, false) && energy >= acost(FERAL_CHARGE_CAT_1) && !me->GetMap()->IsDungeon() &&
                    !HasBotCommandState(BOT_COMMAND_STAY) &&
                    !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && Rand() < 65 &&
                    !me->GetAuraEffect(SPELL_AURA_MOD_INCREASE_SPEED, SPELLFAMILY_DRUID, 0x0, 0x0, 0x8) &&//not dashing
                    me->GetDistance(mytar) > 10 && me->GetDistance(mytar) < 25)
                {
                    if (doCast(mytar, GetSpell(FERAL_CHARGE_CAT_1)))
                        return; //no gcd but jump time
                }

                //Dash (no GCD)
                if (IsSpellReady(DASH_1, diff, false) &&
                    (me->HasAuraType(SPELL_AURA_MOD_STEALTH) || (me->IsInCombat() && !IsSpellReady(FERAL_CHARGE_CAT_1, diff, false))) &&
                    Rand() < 85 && me->GetDistance(mytar) > 15)
                {
                    if (doCast(me, GetSpell(DASH_1)))
                    {}
                }
                //Savage Roar
                if (IsSpellReady(SAVAGE_ROAR_1, diff) && comboPoints >= 1 && (me->IsInCombat() || mytar->IsInCombat()) &&
                    !me->HasAuraType(SPELL_AURA_MOD_STEALTH) && energy >= acost(SAVAGE_ROAR_1) &&
                    !me->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_DRUID, 0, 0x10000000, 0))
                {
                    if (doCast(mytar, GetSpell(SAVAGE_ROAR_1)))
                        return;
                }
            }

            MoveBehind(mytar);

            //range check (melee) to prevent fake casts
            if (me->GetDistance(mytar) > 5)
                return;

            //Cower
            if (mytar->CanHaveThreatList())
            {
                if (IsSpellReady(COWER_1, diff) && mytar->GetVictim() == me && energy >= acost(COWER_1) &&
                    int32(mytar->GetThreatManager().GetThreatListSize()) > 1 &&
                    int32(mytar->getAttackers().size()) > 1 && Rand() < 45)
                {
                    if (doCast(mytar, GetSpell(COWER_1)))
                        return;
                }
            }
            //Tiger's Fury (no GCD) cannot use while Berserk is active
            if (IsSpellReady(TIGERS_FURY_1, diff, false) && mytar->GetHealth() > me->GetHealth() / 4 &&
                (me->GetLevel() < 55 || energy <= 40) && Rand() < 40 &&
                !me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x40))
            {
                if (doCast(me, GetSpell(TIGERS_FURY_1)))
                    getenergy();
            }
            //Berserk can be used After Tiger's Fury without dispelling it
            //Berserk (Cat)
            if (IsSpellReady(BERSERK_1, diff) && !HasRole(BOT_ROLE_HEAL) && (!me->HasAuraType(SPELL_AURA_MOD_STEALTH) || energy >= 40) && Rand() < 50 &&
                (mytar->GetTypeId() == TYPEID_PLAYER || mytar->GetHealth() + 5000 > me->GetHealth()))
            {
                if (doCast(me, GetSpell(BERSERK_1)))
                    return;
            }

            //Openers
            if (me->HasAuraType(SPELL_AURA_MOD_STEALTH))
            {
                uint32 opener =
                    GetSpell(POUNCE_1) &&
                    !mytar->HasAuraType(SPELL_AURA_MOD_STUN) &&
                    mytar->GetDiminishing(DIMINISHING_OPENING_STUN) < DIMINISHING_LEVEL_3 &&
                    (mytar->GetTypeId() == TYPEID_PLAYER || (!IAmFree() && master->GetNpcBotsCount() > 1)) ? POUNCE_1 :
                    GetSpell(RAVAGE_1) ? RAVAGE_1 :
                    GetSpell(SHRED_1) ? SHRED_1 : 0;

                //all opener spells disabled
                if (!opener)
                {
                    me->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                    return;
                }

                if (opener != POUNCE_1 && mytar->HasInArc(float(M_PI), me))
                    return;

                //We do not check combo points amount
                if (IsSpellReady(opener, diff) && energy >= acost(opener))
                {
                    if (doCast(mytar, GetSpell(opener)))
                        return;
                }

                return;
            }

            //Finishers
            if (comboPoints > 0)
            {
                //Maim
                if (IsSpellReady(MAIM_1, diff) && !CCed(mytar) && energy >= acost(MAIM_1) &&
                    (comboPoints >= 4 || mytar->IsNonMeleeSpellCast(false,false,true)))
                {
                    if (doCast(mytar, GetSpell(MAIM_1)))
                        return;
                }
                //Ferocious Bite
                if (IsSpellReady(FEROCIOUS_BITE_1, diff) && (comboPoints >= 4 || mytar->GetHealth() < me->GetMaxHealth() / 4) &&
                    energy >= acost(FEROCIOUS_BITE_1) && Rand() < (50 + comboPoints * 20))
                {
                    if (doCast(mytar, GetSpell(FEROCIOUS_BITE_1)))
                        return;
                }
                //Rip
                if (IsSpellReady(RIP_1, diff) && (comboPoints < 4 || !GetSpell(FEROCIOUS_BITE_1)) &&
                    energy >= acost(RIP_1) && mytar->GetHealth() > me->GetMaxHealth() / 4 &&
                    Rand() < (50 + 40 * (mytar->GetTypeId() == TYPEID_PLAYER && IsMeleeClass(mytar->GetClass()))) &&
                    !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x800000, 0x0, 0x0, me->GetGUID()))
                {
                    if (doCast(mytar, GetSpell(RIP_1)))
                        return;
                }
            }

            //Combo points generating
            //Swipe (Cat)
            if (IsSpellReady(SWIPE_CAT_1, diff) && me->getAttackers().empty() && energy >= acost(SWIPE_CAT_1) && Rand() < (35 + 100 * (me->GetMap()->IsDungeon())))
            {
                std::list<Unit*> targets;
                GetNearbyTargetsInConeList(targets, 5);
                if (targets.size() > 2)
                    if (doCast(mytar, GetSpell(SWIPE_CAT_1)))
                        return;
            }
            //Shred
            if (IsSpellReady(SHRED_1, diff) && comboPoints < 4 && energy >= acost(SHRED_1) && Rand() < 85 &&
                !mytar->HasInArc(float(M_PI), me))
            {
                if (doCast(mytar, GetSpell(SHRED_1)))
                    return;
            }
            //Mangle (Cat)
            if (IsSpellReady(MANGLE_CAT_1, diff) && comboPoints < 5 && energy >= acost(MANGLE_CAT_1) &&
                (Rand() < 20 || !mytar->GetAuraEffect(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, SPELLFAMILY_DRUID, 0x0, 0x400, 0x0)))
            {
                if (doCast(mytar, GetSpell(MANGLE_CAT_1)))
                    return;
            }
            //Rake
            if (IsSpellReady(RAKE_1, diff) && comboPoints < 3 && energy >= acost(RAKE_1) && Rand() < 60 &&
                !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x1000, 0x0, 0x0, me->GetGUID()))
            {
                if (doCast(mytar, GetSpell(RAKE_1)))
                    return;
            }
            //Claw
            if (IsSpellReady(CLAW_1, diff) && comboPoints < 5 && Rand() < 50 && (!GetSpell(SHRED_1) || mytar->HasInArc(float(M_PI), me)) &&
                energy >= acost(CLAW_1))
            {
                if (doCast(mytar, GetSpell(CLAW_1)))
                    return;
            }
        }

        void doBalanceActions(Unit* mytar, uint32 diff)
        {
            //debug
            if (me->GetPowerType() != POWER_MANA)
                return;

            MoveBehind(mytar);

            if (HasRole(BOT_ROLE_HEAL) && GetManaPCT(me) < 25)
                return;

            //BOT_ROLE_DPS is checked in Attack(uint32)

            float dist = me->GetDistance(mytar);
            if (dist > CalcSpellMaxRange(WRATH_1))
                return;

            auto [can_do_nature, can_do_arcane] = CanAffectVictimBools(mytar, SPELL_SCHOOL_NATURE, SPELL_SCHOOL_ARCANE);
            if (!can_do_nature && !can_do_arcane)
                return;

            //spell reflections
            if (IsSpellReady(FAERIE_FIRE_NORMAL_1, diff) && can_do_nature && CanRemoveReflectSpells(mytar, FAERIE_FIRE_NORMAL_1) &&
                doCast(mytar, FAERIE_FIRE_NORMAL_1))
                return;

            //Starfall
            if (IsSpellReady(STARFALL_1, diff) && Rand() < 40)
            {
                bool cast = (mytar->GetTypeId() == TYPEID_PLAYER || me->getAttackers().size() > 1);
                if (!cast)
                {
                    std::list<Unit*> targets;
                    GetNearbyTargetsList(targets, 30.f, 0);
                    if (targets.size() > 3)
                        cast = true;
                }

                if (cast && doCast(me, GetSpell(STARFALL_1)))
                    return;

                SetSpellCooldown(STARFALL_1, 1500); //fail
            }
            //Hurricane
            if (IsSpellReady(HURRICANE_1, diff) && !JumpingOrFalling() && Rand() < 50)
            {
                if (Unit* target = FindAOETarget(CalcSpellMaxRange(HURRICANE_1)))
                {
                    if (doCast(target, GetSpell(HURRICANE_1)))
                        return;
                }
                SetSpellCooldown(HURRICANE_1, 1000); //fail
            }
            //Typhoon
            if (IsSpellReady(TYPHOON_1, diff) && Rand() < 75)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsInConeList(targets, 25);
                if (targets.size() > 2)
                    if (doCast(me, GetSpell(TYPHOON_1)))
                        return;

                SetSpellCooldown(TYPHOON_1, 1000); //fail
            }

            if (IsSpellReady(FORCE_OF_NATURE_1, diff))
            {
                SummonBotPet(mytar);
                SetSpellCooldown(FORCE_OF_NATURE_1, 180000);
                return;
            }

            //Faerie Fire (non-feral): moonkin or non-shapeshifted
            if (IsSpellReady(FAERIE_FIRE_NORMAL_1, diff) && can_do_nature && mytar->getAttackers().size() > 2 && Rand() < 50 &&
                dist < CalcSpellMaxRange(FAERIE_FIRE_NORMAL_1) &&
                !mytar->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_RESISTANCE_PCT, SPELLFAMILY_DRUID, 0x400)
                /*!HasAuraName(mytar, FAERIE_FIRE_ANY)*/)
            {
                if (doCast(mytar, GetSpell(FAERIE_FIRE_NORMAL_1)))
                    return;
            }

            Unit const* u = mytar->GetVictim();
            //Insect Swarm
            if (IsSpellReady(INSECT_SWARM_1, diff) && can_do_nature && u && mytar->GetDistance(u) < 8 && Rand() < 30 &&
                dist < CalcSpellMaxRange(INSECT_SWARM_1) &&
                !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x200000, 0x0, 0x0, me->GetGUID())
                /*!HasAuraName(mytar, INSECT_SWARM_1, me->GetGUID())*/)
            {
                if (doCast(mytar, GetSpell(INSECT_SWARM_1)))
                    return;
            }

            if (IsSpellReady(MOONFIRE_1, diff) && can_do_arcane && Rand() < 60 && dist < CalcSpellMaxRange(MOONFIRE_1) &&
                !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x2, 0x0, 0x0, me->GetGUID())
                /*!HasAuraName(mytar, MOONFIRE_1, me->GetGUID())*/)
            {
                if (doCast(mytar, GetSpell(MOONFIRE_1)))
                    return;
            }
            //TODO: balance starfire/wrath frequency based on mana effeciency
            if (IsSpellReady(STARFIRE_1, diff) && can_do_arcane && dist < CalcSpellMaxRange(STARFIRE_1))
            {
                AuraEffect const* eclipeLunar = me->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_DRUID, 0x0, 0x0, 0x4000);
                int32 rand = 30 + 100 * (eclipeLunar && eclipeLunar->GetBase()->GetDuration() > 3000);

                if (Rand() < rand && doCast(mytar, GetSpell(STARFIRE_1)))
                    return;
            }
            if (IsSpellReady(WRATH_1, diff) && can_do_nature)
            {
                if (doCast(mytar, GetSpell(WRATH_1)))
                    return;
            }
        }

        void BreakCC(uint32 diff) override
        {
            if (GC_Timer <= diff && Rand() < 25 && GetManaPCT(me) > 15 &&
                (me->IsPolymorphed() || me->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT))))
            {
                uint32 sshift;
                switch (_form)
                {
                    case DRUID_BEAR_FORM:
                        sshift = IsTank() && !me->getAttackers().empty() &&
                            (!me->GetVictim() || me->GetDistance(me->GetVictim()) < 5) ? 0 :
                            GetSpell(BEAR_FORM_1); break;
                    case DRUID_CAT_FORM:     sshift = GetSpell(CAT_FORM_1);         break;
                    case DRUID_MOONKIN_FORM: sshift = GetSpell(MOONKIN_FORM_1);     break;
                    case DRUID_TREE_FORM:    sshift = GetSpell(TREE_OF_LIFE_FORM_1);break;
                    case DRUID_TRAVEL_FORM:  sshift = GetSpell(TRAVEL_FORM_1);      break;
                    case DRUID_AQUATIC_FORM: sshift = GetSpell(AQUATIC_FORM_1);     break;
                    case DRUID_FLIGHT_FORM:  sshift = GetSpell(FLIGHT_FORM_1);      break;
                    case BOT_STANCE_NONE:    sshift = GetSpell(TRAVEL_FORM_1);      break;
                    default:                 sshift = 0;                            break;
                }
                if (sshift && doCast(me, sshift))
                {
                    GetInPosition(false, nullptr);
                    return;
                }
            }
            if (IsSpellReady(BERSERK_1, diff) && Rand() < 10 && me->HasAuraWithMechanic(1<<MECHANIC_FEAR))
            {
                if (doCast(me, GetSpell(BERSERK_1)))
                    return;
            }
            bot_ai::BreakCC(diff);
        }

        bool HealTarget(Unit* target, uint32 diff) override
        {
            if (!target || !target->IsAlive() || target->GetShapeshiftForm() == FORM_SPIRITOFREDEMPTION || me->GetDistance(target) > 40)
                return false;
            uint8 hp = GetHealthPCT(target);
            if (hp > GetHealHpPctThreshold())
                return false;
            bool pointed = IsPointedHealTarget(target);
            if (hp > 95 && !(pointed && me->GetMap()->IsRaid()) &&
                (!target->IsInCombat() || target->getAttackers().empty() || !IsTank(target) || !me->GetMap()->IsRaid()))
                return false;

            int32 hps = GetHPS(target);
            int32 xphp = target->GetHealth() + hps * 2;
            int32 hppctps = int32(hps * 100.f / float(target->GetMaxHealth()));
            int32 xphploss = xphp > int32(target->GetMaxHealth()) ? 0 : abs(int32(xphp - target->GetMaxHealth()));
            int32 xppct = hp + hppctps * 2;
            if (xppct >= 95 && hp >= 25 && !pointed)
                return false;

            if (IsTank() && xppct > 25)
                return false;
            if (hp > 50 && !IsTank(target) && (_form == DRUID_BEAR_FORM || _form == DRUID_CAT_FORM))
                return false; //do not waste heal if in feral or so

            if (IsSpellReady(NATURES_SWIFTNESS_1, diff, false) && Rand() < 80 &&
                (me->IsInCombat() || target->IsInCombat()) &&//may just revive
                hp <= 20 && xppct <= 0 && xphploss > _heals[HEALING_TOUCH_1] / 2 &&
                (target->GetTypeId() == TYPEID_PLAYER || IsTank(target) || target->IsInCombat() || !target->getAttackers().empty()))
            {
                me->InterruptNonMeleeSpells(false);
                if (doCast(me, GetSpell(NATURES_SWIFTNESS_1)))
                {
                    if (doCast(target, GetSpell(HEALING_TOUCH_1)))
                        return true;
                }
            }
            if (IsSpellReady(NOURISH_1, diff) && xppct <= 65 && xphploss > _heals[REJUVENATION_1])
            {
                static uint8 minHots = 2;
                uint8 hots = 0;
                Unit::AuraEffectList const& effectList = target->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
                for (Unit::AuraEffectList::const_iterator itr = effectList.begin(); itr != effectList.end(); ++itr)
                {
                    AuraEffect const* eff = *itr;
                    if (eff->GetCasterGUID() != me->GetGUID())
                        continue;
                    SpellInfo const* spellInfo = eff->GetSpellInfo();
                    if (spellInfo->SpellFamilyName != SPELLFAMILY_DRUID)
                        continue;
                    //rejuv,regro,lifeb,wildg
                    if (!((spellInfo->SpellFamilyFlags[0] & 0x50) || (spellInfo->SpellFamilyFlags[1] & 0x4000010)))
                        continue;
                    hots += eff->GetBase()->GetStackAmount();
                    if (hots >= minHots)
                        break;
                }
                if (hots >= minHots && doCast(target, GetSpell(NOURISH_1)))
                    return true;
            }
            if (IsSpellReady(SWIFTMEND_1, diff, false) && !HasRole(BOT_ROLE_DPS|BOT_ROLE_TANK) && hp < 60 &&
                (xppct <= 15 || int32(GetLostHP(target)) > _heals[REJUVENATION_1]) &&
                //rejuv,regro
                target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x50, 0x0, 0x0, me->GetGUID())
                /*(HasAuraName(target, REGROWTH_1) || HasAuraName(target, REJUVENATION_1))*/)
            {
                if (doCast(target, GetSpell(SWIFTMEND_1)))
                    return true;
            }
            //maintain HoTs
            Unit const* u = target->GetVictim();
            bool tanking = u && IsTank(target) && u->ToCreature() && u->ToCreature()->isWorldBoss();
            if (IsSpellReady(REGROWTH_1, diff) && Rand() < 80 && (tanking || xphploss > _heals[REGROWTH_1]) &&
                (xppct <= 45 || !target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x40, 0x0, 0x0, me->GetGUID()))
                /*!HasAuraName(target, REGROWTH_1, me->GetGUID())*/)
            {
                if (doCast(target, GetSpell(REGROWTH_1)))
                    return true;
            }
            if (IsSpellReady(LIFEBLOOM_1, diff) && xppct >= 40 && hp < 75 + 10 * tanking)
            {
                AuraEffect const* bloom = target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x0, 0x10, 0x0, me->GetGUID());
                //Aura const* bloom = target->GetAura(GetSpell(LIFEBLOOM_1), me->GetGUID());
                if ((!bloom || bloom->GetBase()->GetStackAmount() < 3 ||
                    (bloom->GetBase()->GetDuration() < 2000 && !target->getAttackers().empty())) &&
                    doCast(target, GetSpell(LIFEBLOOM_1)))
                    return true;
            }
            if (IsSpellReady(HEALING_TOUCH_1, diff) && (xppct > 15 || !GetSpell(REGROWTH_1)) &&
                xphploss > _heals[HEALING_TOUCH_1] &&
                doCast(target, GetSpell(HEALING_TOUCH_1)))
                return true;
            if (IsSpellReady(REJUVENATION_1, diff) && xppct > 45 &&
                (tanking || xphploss > _heals[REJUVENATION_1]) &&
                !target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x10, 0x0, 0x0, me->GetGUID())
                /*!HasAuraName(target, REJUVENATION_1, me->GetGUID())*/)
            {
                if (doCast(target, GetSpell(REJUVENATION_1)))
                    return true;
            }
            return false;
        }

        bool BuffTarget(Unit* target, uint32 /*diff*/) override
        {
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;

            if (uint32 MARK_OF_THE_WILD = GetSpell(MARK_OF_THE_WILD_1))
            {
                if (!target->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_RESISTANCE, SPELLFAMILY_DRUID, 0x40000)
                    /*!HasAuraName(target, MARK_OF_THE_WILD_1)*/)
                    if (doCast(target, MARK_OF_THE_WILD))
                        return true;
            }
            if (uint32 THORNS = GetSpell(THORNS_1))
            {
                if (IsTank(target) &&
                    !target->HasAuraTypeWithFamilyFlags(SPELL_AURA_DAMAGE_SHIELD, SPELLFAMILY_DRUID, 0x100)
                    /*!HasAuraName(target, THORNS_1)*/)
                    if (doCast(target, THORNS))
                        return true;
            }

            return false;
        }

        void CheckTravel(uint32 diff)
        {
            if ((!IAmFree() && !HasBotCommandState(BOT_COMMAND_FOLLOW)) || Rand() > 35 || me->IsMounted() || IsCasting() ||
                me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING))
                return;

            bool can_use_travel_form = IsSpellReady(TRAVEL_FORM_1, diff) && me->GetShapeshiftForm() == FORM_NONE && IsOutdoors();

            if (IAmFree())
            {
                InstanceTemplate const* instt = sObjectMgr->GetInstanceTemplate(me->GetMap()->GetId());
                bool map_allows_mount = (!me->GetMap()->IsDungeon() || me->GetMap()->IsBattlegroundOrArena()) && (!instt || instt->AllowMount);
                if (me->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD) &&
                    (!me->GetVictim() ?
                        (me->IsInCombat() || !map_allows_mount || IsFlagCarrier(me)) :
                        !me->IsWithinDist(me->GetVictim(), 8.0f + (IsMelee() ? 0.0f : GetSpellAttackRange(true)))))
                {
                    if (me->GetShapeshiftForm() == FORM_CAT && IsSpellReady(DASH_1, diff, false))
                    {
                        if (doCast(me, GetSpell(DASH_1)))
                            return;
                    }
                    else if (can_use_travel_form)
                    {
                        if (doCast(me, GetSpell(TRAVEL_FORM_1)))
                            return;
                    }
                }

                return;
            }

            if (me->GetExactDist2d(master) > std::max<uint8>(master->GetBotMgr()->GetBotFollowDist(), 30))
            {
                if (me->GetShapeshiftForm() == FORM_CAT && IsSpellReady(DASH_1, diff, false))
                {
                    if (doCast(me, GetSpell(DASH_1)))
                        return;
                }
                else if (can_use_travel_form)
                {
                    if (doCast(me, GetSpell(TRAVEL_FORM_1)))
                        return;
                }
            }
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            ResurrectGroup(GetSpell(REVIVE_1));

            if (!IAmFree() && HasBotCommandState(BOT_COMMAND_FOLLOW) && !master->IsMounted() && Rand() < 35)
            {
                int32 dist = int32(me->GetDistance(master));
                if (me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
                {
                    if (_form != DRUID_AQUATIC_FORM && dist > 30 && GetSpell(AQUATIC_FORM_1) &&
                        doCast(me, GetSpell(AQUATIC_FORM_1)))
                        return;
                }
                //if (me->HasUnitMovementFlag(MOVEMENTFLAG_FLYING))
                //{
                //    if (_form != DRUID_AQUATIC_FORM && dist > 30 && GetSpell(AQUATIC_FORM_1) &&
                //        doCast(me, GetSpell(AQUATIC_FORM_1)))
                //        return;
                //}
                else if (_form != DRUID_TRAVEL_FORM && dist > 30 && GetSpell(TRAVEL_FORM_1))
                {
                    if (doCast(me, GetSpell(TRAVEL_FORM_1)))
                        return;
                }
                else if (_form == DRUID_AQUATIC_FORM)
                    removeShapeshiftForm();
            }
        }

        void doInnervate(uint32 diff)
        {
            if (!IsSpellReady(INNERVATE_1, diff) || Rand() > 25)
                return;
            if (_form != BOT_STANCE_NONE && _form != DRUID_MOONKIN_FORM && _form != DRUID_TREE_FORM &&
                (IsTank() || me->getAttackers().size() > 3))
                return;

            static const uint8 minmanaval = 30;
            Unit* iTarget = nullptr;

            if (master->IsInCombat() && master->GetPowerType() == POWER_MANA &&
                GetManaPCT(master) < minmanaval && !master->GetAuraEffect(SPELL_AURA_PERIODIC_ENERGIZE, SPELLFAMILY_DRUID, 0x0, 0x1000, 0x0))
                iTarget = master;
            else if (me->IsInCombat() && me->GetPowerType() == POWER_MANA &&
                GetManaPCT(me) < minmanaval && !me->GetAuraEffect(SPELL_AURA_PERIODIC_ENERGIZE, SPELLFAMILY_DRUID, 0x0, 0x1000, 0x0))
                iTarget = me;

            if (!IAmFree())
            {
                Group const* group = master->GetGroup();
                if (!iTarget && !group) //first check master's bots
                {
                    BotMap const* map = master->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                    {
                        Creature* bot = itr->second;
                        if (!bot || !bot->IsInCombat() || !bot->IsAlive() || bot->IsTempBot()) continue;
                        if (bot->GetPowerType() != POWER_MANA) continue;
                        if (bot->GetBotClass() == BOT_CLASS_HUNTER || bot->GetBotClass() == BOT_CLASS_WARLOCK ||
                            bot->GetBotClass() == BOT_CLASS_SPHYNX || bot->GetBotClass() == BOT_CLASS_SPELLBREAKER ||
                            bot->GetBotClass() == BOT_CLASS_NECROMANCER) continue;
                        if (me->GetExactDist(bot) > 30) continue;
                        if (GetManaPCT(bot) < minmanaval && !bot->GetAuraEffect(SPELL_AURA_PERIODIC_ENERGIZE, SPELLFAMILY_DRUID, 0x0, 0x1000, 0x0))
                        {
                            iTarget = bot;
                            break;
                        }
                    }
                }
                if (!iTarget && group) //cycle through player members...
                {
                    std::vector<Unit*> members = BotMgr::GetAllGroupMembers(group);
                    for (uint8 i = 0; i < 2 && !iTarget; ++i)
                    {
                        for (Unit* member : members)
                        {
                            if (!(i == 0 ? member->IsPlayer() : member->IsNPCBot()) || !member->IsInWorld() || !member->IsInCombat() ||
                                !member->IsAlive() || me->GetExactDist(member) > 30 || GetManaPCT(member) > minmanaval ||
                                member->GetAuraEffect(SPELL_AURA_PERIODIC_ENERGIZE, SPELLFAMILY_DRUID, 0x0, 0x1000, 0x0))
                                continue;
                            if (i == 1)
                            {
                                Creature const* bot = member->ToCreature();
                                if (bot->IsTempBot() || bot->GetPowerType() != POWER_MANA ||
                                    bot->GetBotClass() == BOT_CLASS_HUNTER || bot->GetBotClass() == BOT_CLASS_WARLOCK ||
                                    bot->GetBotClass() == BOT_CLASS_SPHYNX || bot->GetBotClass() == BOT_CLASS_SPELLBREAKER ||
                                    bot->GetBotClass() == BOT_CLASS_NECROMANCER)
                                    continue;
                            }
                            iTarget = member;
                            break;
                        }
                    }
                }
            }

            if (iTarget && doCast(iTarget, INNERVATE_1))
            {
                if (iTarget->GetTypeId() == TYPEID_PLAYER)
                    ReportSpellCast(INNERVATE_1, LocalizedNpcText(iTarget->ToPlayer(), BOT_TEXT__ON_YOU), iTarget->ToPlayer());

                if (!IAmFree() && iTarget != master)
                {
                    std::string msg = iTarget == me ? LocalizedNpcText(master, BOT_TEXT__ON_MYSELF) : (LocalizedNpcText(master, BOT_TEXT__ON_) + iTarget->GetName() + '!');
                    ReportSpellCast(INNERVATE_1, msg, master);
                }

                return;
            }

            SetSpellCooldown(INNERVATE_1, 1500); //fail
        }

        void CheckRoots()
        {
            if (uint32 ENTANGLING_ROOTS = GetSpell(ENTANGLING_ROOTS_1))
            {
                if (FindAffectedTarget(ENTANGLING_ROOTS, me->GetGUID(), 60))
                    return;
                if (Unit* target = FindRootTarget(30, ENTANGLING_ROOTS))
                    if (doCast(target, ENTANGLING_ROOTS))
                        return;
            }
        }

        void CheckBattleRez(uint32 diff)
        {
            if (!IsSpellReady(REBIRTH_1, diff, false) || IAmFree() || me->IsMounted() ||
                IsTank() || IsCasting() || Rand() > 20) return;

            Group const* gr = master->GetGroup();
            std::list<Unit*> targets;
            if (!gr)
            {
                Unit* target = master;
                if (master->IsAlive()) return;
                if (master->IsResurrectRequested() || master->GetUInt32Value(PLAYER_SELF_RES_SPELL)) return; //resurrected
                if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                    target = (Unit*)master->GetCorpse();
                if (!target || !target->IsInWorld())
                    return;
                if (me->GetExactDist(target) > 30 && !HasBotCommandState(BOT_COMMAND_STAY))
                {
                    me->GetMotionMaster()->MovePoint(master->GetMapId(), *target);
                    SetSpellCooldown(REBIRTH_1, 1500);
                    return;
                }
                else if (!target->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    me->Relocate(*target);

                if (doCast(target, GetSpell(REBIRTH_1))) //rezzing
                {
                    BotWhisper(LocalizedNpcText(master, BOT_TEXT_REZZING_YOU));
                    return;
                }
            }
            else
            {
                for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* tPlayer = itr->GetSource();
                    Unit* target = tPlayer;
                    if (!tPlayer || tPlayer->IsAlive()) continue;
                    if (tPlayer->IsResurrectRequested() || tPlayer->GetUInt32Value(PLAYER_SELF_RES_SPELL)) continue; //resurrected
                    if (tPlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                        target = (Unit*)tPlayer->GetCorpse();
                    if (!target || !target->IsInWorld()) continue;
                    if (master->GetMap() != target->FindMap()) continue;
                    if (me->GetDistance(target) > 100) continue;
                    targets.push_back(target);
                }
            }

            BotMap const* botMap = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = botMap->begin(); itr != botMap->end(); ++itr)
            {
                Creature* bot = itr->second;
                if (bot && bot->IsInWorld() && !bot->IsAlive() && !bot->GetBotAI()->GetSelfRezSpell() && IsTank(bot) && me->GetDistance(bot) < 80)
                    targets.push_back(bot);
            }

            if (Unit* targetOrCorpse = !targets.empty() ? Trinity::Containers::SelectRandomContainerElement(targets) : nullptr)
            {
                if (me->GetExactDist(targetOrCorpse) > 30 && !HasBotCommandState(BOT_COMMAND_STAY))
                {
                    me->GetMotionMaster()->MovePoint(targetOrCorpse->GetMapId(), *targetOrCorpse);
                    return;
                }
                else if (!targetOrCorpse->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    me->Relocate(*targetOrCorpse);

                if (doCast(targetOrCorpse, GetSpell(REBIRTH_1))) //rezzing
                {
                    if (targetOrCorpse->GetTypeId() == TYPEID_PLAYER)
                        BotWhisper(LocalizedNpcText(targetOrCorpse->ToPlayer(), BOT_TEXT_REZZING_YOU), targetOrCorpse->ToPlayer());
                    if (targetOrCorpse != master)
                    {
                        std::string rezstr = LocalizedNpcText(master, BOT_TEXT_REZZING_) + targetOrCorpse->GetName();
                        if (targetOrCorpse->GetTypeId() == TYPEID_UNIT)
                            rezstr += " (" + LocalizedNpcText(master, BOT_TEXT_BOT_TANK) + ')';
                        BotWhisper(rezstr);
                    }
                    return;
                }
            }
        }

        void setStats(BotStances form)
        {
            _form = form;
            switch (form)
            {
                case DRUID_BEAR_FORM:
                    if (me->GetPowerType() != POWER_RAGE)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_RAGE");
                        me->SetPowerType(POWER_RAGE);
                    }
                    RefreshAura(MASTER_SHAPESHIFTER_BEAR_BUFF, me->GetLevel() >= 20);
                    if (GetSpec() == BOT_SPEC_DRUID_FERAL)
                    {
                        RefreshAura(NATURAL_REACTION, me->GetLevel() >= 35);
                        RefreshAura(SURVIVAL_OF_THE_FITTEST_BUFF, me->GetLevel() >= 35);
                        RefreshAura(SAVAGE_DEFENSE_PASSIVE, me->GetLevel() >= 40);
                    }
                    break;
                case DRUID_CAT_FORM:
                    if (me->GetPowerType() != POWER_ENERGY)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_ENERGY");
                        me->SetPowerType(POWER_ENERGY);
                    }
                    RefreshAura(MASTER_SHAPESHIFTER_CAT_BUFF, me->GetLevel() >= 20);
                    RefreshAura(FERAL_SWIFTNESS, me->GetLevel() >= 20); //talents ignore forms for creatures so put that here
                    if (GetSpec() == BOT_SPEC_DRUID_FERAL)
                    {
                        RefreshAura(NURTURING_INSTINCT_BUFF, me->GetLevel() >= 30);
                        RefreshAura(PREDATORY_INSTINCTS, me->GetLevel() >= 45);
                    }
                    break;
                case DRUID_MOONKIN_FORM:
                    if (me->GetPowerType() != POWER_MANA)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_MANA (moonkin)");
                        me->SetPowerType(POWER_MANA);
                    }
                    RefreshAura(MASTER_SHAPESHIFTER_MOONKIN_BUFF, me->GetLevel() >= 20);
                    RefreshAura(OWLKIN_FRENZY, me->GetLevel() >= 45);
                    break;
                case DRUID_TREE_FORM:
                    if (me->GetPowerType() != POWER_MANA)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_MANA (tree)");
                        me->SetPowerType(POWER_MANA);
                    }
                    RefreshAura(MASTER_SHAPESHIFTER_TREE_BUFF, me->GetLevel() >= 20);
                    break;
                case DRUID_TRAVEL_FORM:
                    if (me->GetPowerType() != POWER_MANA)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_MANA (travel)");
                        me->SetPowerType(POWER_MANA);
                    }
                    break;
                case DRUID_AQUATIC_FORM:
                    if (me->GetPowerType() != POWER_MANA)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_MANA (aquatic)");
                        me->SetPowerType(POWER_MANA);
                    }
                    break;
                case DRUID_FLIGHT_FORM:
                    if (me->GetPowerType() != POWER_MANA)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_MANA (flight)");
                        me->SetPowerType(POWER_MANA);
                    }
                    break;
                case BOT_STANCE_NONE:
                    if (me->GetPowerType() != POWER_MANA)
                    {
                        //TC_LOG_ERROR("entities.player", "druid_bot::setStats(): has to set powerType to POWER_MANA (deshape)");
                        me->SetPowerType(POWER_MANA);
                    }
                    break;
                default:
                    TC_LOG_ERROR("entities.player", "druid_bot::setStats(): NYI form {}", uint32(form));
                    setStats(BOT_STANCE_NONE);
                    return;
            }

            SetShouldUpdateStats();
            SetStats(false);
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& damageinfo) const override
        {
            uint8 lvl = me->GetLevel();
            float pctbonus = 0.0f;

            if (damageinfo.HitOutCome == MELEE_HIT_CRIT)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Primal Fury (white attacks): 100% to gain 5 rage at crit in (Dire) Bear Form
                if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 25 && _form == DRUID_BEAR_FORM)
                    me->CastSpell(me, PRIMAL_FURY_EFFECT_ENERGIZE, true);
                //Predatory Instincts (part 1): 10% additional crit damage bonus for melee attacks in Cat form
                if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 45 && _form == DRUID_CAT_FORM)
                    pctbonus += 0.05f;
            }

            damageinfo.Damages[0].Damage = uint32(damageinfo.Damages[0].Damage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                ////Elemental Fury (part 2): 50% additional crit damage bonus for Nature, Fire and Frost (all) spells
                //if (lvl >= 21)
                //    pctbonus += 0.25f;
            }

            //Feral Aggression: 15% bonus damage for Ferocious Bite
            if (lvl >= 10 && baseId == FEROCIOUS_BITE_1)
                pctbonus += 0.15f;
            //Feral Instinct: 30% bonus damage for Swipe (Bear)
            if (lvl >= 15 && baseId == SWIPE_BEAR_1)
                pctbonus += 0.3f;
            //Savage Fury: 20% bonus damage for Claw, Rake, Mangle (Cat), Mangle (Bear) and Maul
            if (lvl >= 15 &&
                (baseId == CLAW_1 ||
                baseId == RAKE_1 ||
                baseId == MANGLE_CAT_1 ||
                baseId == MANGLE_BEAR_1 ||
                baseId == MAUL_1))
                pctbonus += 0.2f;
            //Rend and Tear: 20% bonus damage on bleeding targets for Maul and Shred
            if ((GetSpec() == BOT_SPEC_DRUID_FERAL) &&
                lvl >= 55 && damageinfo.target && damageinfo.target->HasAuraState(AURA_STATE_BLEEDING) &&
                (baseId == MAUL_1 || baseId == SHRED_1))
                pctbonus += 0.2f;
            //Glyph of Mangle: 10% bonus damage for Mangle (all)
            if (lvl >= 50 && (baseId == MANGLE_BEAR_1 || baseId == MANGLE_CAT_1))
                pctbonus += 0.1f;

            //Primal Fury (yellow attacks): 100% to gain 5 rage at crit in (Dire) Bear Form
            //Primal Fury (yellow attacks): 100% to gain 1 combo point at crit in Cat Form
            if (_form == DRUID_BEAR_FORM && iscrit && lvl >= 25)
                me->CastSpell(me, PRIMAL_FURY_EFFECT_ENERGIZE, true);
            if (_form == DRUID_CAT_FORM &&
                (baseId == CLAW_1 || baseId == MANGLE_CAT_1 || baseId == POUNCE_1 ||
                baseId == RAKE_1 || baseId == RAVAGE_1 || baseId == SHRED_1))
                primalFuryProc = iscrit && lvl >= 25;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Nature's bounty: 25% additional critical chance for Regrowth and Nourish
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) && lvl >= 35 && (baseId == REGROWTH_1 || baseId == NOURISH_1))
                crit_chance += 25.f;
            //Rend and Tear (part 2): 25% additional critical chance on bleeding targets for Ferocious Bite (handled in Unit.cpp)
            //if (lvl >= 55 && victim->HasAuraState(AURA_STATE_BLEEDING) && baseId == FEROCIOUS_BITE_1)
            //    crit_chance += 25.f;
            //Improved Moonfire
            if (lvl >= 15 && baseId == MOONFIRE_1)
                crit_chance += 10.f;
            //Nature's Majesty: 4% additional critical chance for Wrath, Starfire, Starfall, Nourish and Healing Touch
            if (lvl >= 15 && ((spellInfo->SpellFamilyFlags[0] & 0x25) || (spellInfo->SpellFamilyFlags[1] & 0x2800000)))
                crit_chance += 4.f;
            //Eclipse (Lunar): 40% additional critical chance for Starfire
            if (lvl >= 50 && baseId == STARFIRE_1 && me->HasAura(ECLIPSE_LUNAR_BUFF))
                crit_chance += 40.f;
            //Improved Faerie Fire (part 2): 3% additional critical chance for all spells on target affected by Faerie Fire
            if (GetSpec() == BOT_SPEC_DRUID_BALANCE && lvl >= 40 && victim && victim->HasAuraState(AURA_STATE_FAERIE_FIRE))
                crit_chance += 3.f;
            //Natural Perfection: 3% additional critical chance for all spells
            if (GetSpec() == BOT_SPEC_DRUID_RESTORATION && lvl >= 40)
                crit_chance += 3.f;
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Vengeance: 100% additional crit damage bonus for Starfire, Starfall, Moonfire and Wrath
                if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x7) || (spellInfo->SpellFamilyFlags[1] & 0x800000)))
                    pctbonus += 0.333f;
            }
            //Genesis: 5% bonus damage for Dots
            if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x6002D2) || (spellInfo->SpellFamilyFlags[1] & 0x4000010)))
                pctbonus += 0.05f;
            //Improved Insect Swarm: SpellEffects.cpp, Unit.cpp
            //Brambles: 75% bonus damage for Throns and Entangling Roots (Thorns are handled in Unit.cpp)
            if (lvl >= 20 && (spellInfo->SpellFamilyFlags[0] & 0x200))
                pctbonus += 0.75f;
            //Moonfury: 10% bonus damage for Starfire, Moonfire and Wrath
            if (lvl >= 35 && (spellInfo->SpellFamilyFlags[0] & 0x7))
                pctbonus += 0.1f;
            //Glyph of Focus (part 1): 10% bonus damage for Starfall
            if (lvl >= 70 && (spellInfo->SpellFamilyFlags[1] & 0x800000))
                pctbonus += 0.1f;
            //Wrath of Cenarius: 20%/10% Increased spellpower bonus for Starfire/Wrath
            if ((GetSpec() == BOT_SPEC_DRUID_BALANCE) && lvl >= 45)
            {
                if (baseId == STARFIRE_1)
                    fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.2f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
                if (baseId == WRATH_1)
                    fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.1f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            }
            //Eclipse (Solar): 40% bonus damage for Wrath
            if (lvl >= 50 && baseId == WRATH_1 && me->HasAura(ECLIPSE_SOLAR_BUFF))
                pctbonus += 0.4f;
            //Gale Winds: 30% bonus damage for Hurricane and Typhoon
            if ((GetSpec() == BOT_SPEC_DRUID_BALANCE) &&
                lvl >= 50 && ((spellInfo->SpellFamilyFlags[0] & 0x400000) || (spellInfo->SpellFamilyFlags[1] & 0x1000000)))
                pctbonus += 0.3f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Genesis: 5% bonus healing for Hots
            if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x6002D2) || (spellInfo->SpellFamilyFlags[1] & 0x4000010)))
                pctbonus += 0.05f;
            //Improved Rejuvenation: 15% bonus healing for Rejuvenation
            if (lvl >= 25 && baseId == REJUVENATION_1)
                pctbonus += 0.15f;
            //Improved Rejuvenation (17114,17115): 27% bonus healing for Rejuvenation
            //if (baseId == REJUVENATION_1)
            //    pctbonus += 0.27f;
            //Gift of Nature: 10% bonus healing for all spells
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) && lvl >= 30)
                pctbonus += 0.1f;
            //Empowered Touch: 40% bonus (from spellpower) for Healing Touch and 20% bonus (from spellpower) for Nourish
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) && lvl >= 35)
            {
                if (baseId == HEALING_TOUCH_1)
                    flat_mod += me->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.4f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * 1.88f * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo) * stack;
                else if (baseId == NOURISH_1)
                    flat_mod += me->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.2f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * 1.88f * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo) * stack;
            }
            //Empowered Rejuvenation: 20% bonus healing for healing over time effects
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) &&
                lvl >= 45 && ((spellInfo->SpellFamilyFlags[0] & 0xD0) || (spellInfo->SpellFamilyFlags[1] & 0x4000010)))
                flat_mod += me->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.2f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * 1.88f * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo) * stack;

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //Clearcasting: -100% mana/rage/energy cost for any spell
            if (AuraEffect const* eff = me->GetAuraEffect(OMEN_OF_CLARITY_BUFF, 0, me->GetGUID()))
                if (eff->IsAffectingSpell(spellInfo))
                    pctbonus += 1.0f;

            //percent mods
            //Tree of Life Passive (5420) (activates when learned):
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) &&
                lvl >= 50 && ((spellInfo->SpellFamilyFlags[0] & 0x50) || (spellInfo->SpellFamilyFlags[1] & 0x4000010)))
                pctbonus += 0.5f;
            //Glyph of the Wild:
            if (lvl >= 15 && baseId == MARK_OF_THE_WILD_1)
                pctbonus += 0.5f;
            //Natural Shapeshifter:
            if (lvl >= 15 &&
                spellInfo->_effects[0].Effect == SPELL_EFFECT_APPLY_AURA &&
                spellInfo->_effects[0].ApplyAuraName == SPELL_AURA_MOD_SHAPESHIFT)
                pctbonus += 0.3f;
            //King of the Jungle part 3:
            if (lvl >= 15 && (spellInfo->SpellFamilyFlags[0] & 0xC0000000))
                pctbonus += 0.6f;
            //Tranquil Spirit:
            if (lvl >= 25 &&
                (baseId == HEALING_TOUCH_1 || baseId == NOURISH_1 || baseId == TRANQUILITY_1))
                pctbonus += 0.1f;
            //Moonglow:
            if (lvl >= 15 && ((spellInfo->SpellFamilyFlags[0] & 0x77) || (spellInfo->SpellFamilyFlags[1] & 0x2800000)))
                pctbonus += 0.09f;
            //Berserk part 2:
            if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 60 && _form == DRUID_CAT_FORM &&
                //((spellInfo->SpellFamilyFlags[0] & 0x839000) ||
                //(spellInfo->SpellFamilyFlags[1] & 0x30000480) ||
                //(spellInfo->SpellFamilyFlags[2] & 0x40420)) &&
                me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x40))
                pctbonus += 0.5f;

            //flat mods
            //Shredding Attacks:
            if (lvl >= 25)
            {
                if (spellInfo->SpellFamilyFlags[0] & 0x8000)
                    flatbonus += 18;
                else if (spellInfo->SpellFamilyFlags[1] & 0x100)
                    flatbonus += 20;
            }
            //Ferocity:
            if (lvl >= 10)
            {
                if ((spellInfo->SpellFamilyFlags[0] & 0x800) || (spellInfo->SpellFamilyFlags[1] & 0x100040))
                    flatbonus += 50;
                else if ((spellInfo->SpellFamilyFlags[0] & 0x1000) ||
                    (spellInfo->SpellFamilyFlags[1] & 0x400) ||
                    (spellInfo->SpellFamilyFlags[2] & 0x40400))
                    flatbonus += 5;
            }
            //Improved Mangle part 2:
            if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 50 && (spellInfo->SpellFamilyFlags[1] & 0x400))
                flatbonus += 6;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //casttime is in milliseconds
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //Elune's Wrath: -100% cast time for Starfire
            AuraEffect const* elun = me->GetAuraEffect(ELUNES_WRATH_BUFF, 0);
            //Predator's Swiftness: -100% cast time
            AuraEffect const* pred = me->GetAuraEffect(PREDATORS_SWIFTNESS_BUFF, 0);
            //Nature's Swiftness: -100% cast time
            AuraEffect const* natu = me->GetAuraEffect(NATURES_SWIFTNESS_1, 0);
            if ((elun && elun->IsAffectingSpell(spellInfo)) ||
                (pred && pred->IsAffectingSpell(spellInfo)) ||
                (natu && natu->IsAffectingSpell(spellInfo)))
                pctbonus += 1.0f;

            //pct mods
            //Celestial Focus: 3% haste
            if (lvl >= 25)
                pctbonus += 0.03f;

            //flat mods
            //Starlight Wrath: -0.5 sec cast time for Wrath and Starfire
            if (lvl >= 10 && (baseId == WRATH_1 || baseId == STARFIRE_1))
                timebonus += 500;
            //Naturalist: -0.5 sec cast time for Healing Touch
            if (lvl >= 15 && baseId == HEALING_TOUCH_1)
                timebonus += 500;
            //Regrowth bonus (ids:21872,46834): -0.2 x2 sec cast time for Regrowth
            if (lvl >= 68 && baseId == REGROWTH_1)
                timebonus += 400;

            casttime = std::max<int32>(int32((float(casttime) * (1.0f - pctbonus)) - timebonus), 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Improved Tranquility: -60% cooldown for Tanquility
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) && lvl >= 30 && baseId == TRANQUILITY_1)
                pctbonus += 0.6f;

            //flat mods
            //Glyph of Turn Evil: +8 sec cooldown for Turn Evil (3 sec for bots)
            //if (lvl >= 24 && spellId == GetSpell(TURN_EVIL_1))
            //    timebonus -= 3000;

            cooldown = std::max<int32>(int32((float(cooldown) * (1.0f - pctbonus)) - timebonus), 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Glyph of Dash: -20% cooldown for Dash
            if (lvl >= 16 && baseId == DASH_1)
                pctbonus += 0.2f;
            //Berserk part 1:
            if (lvl >= 60 && _form == DRUID_BEAR_FORM && (spellInfo->SpellFamilyFlags[1] & 0x40) &&
                me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x40))
                pctbonus += 1.0f;

            //flat mods
            //Genesis Rebirth Bonus (26106): -5 min cooldown for Rebirth
            if (baseId == REBIRTH_1)
                timebonus += 300000;
            //Improved Mangle part 1: -1.5 sec cooldown for Mangle (Bear)
            if (lvl >= 50 && baseId == MANGLE_BEAR_1)
                timebonus += 1500;
            //Brutal Impact: -30 sec cooldown for Bash
            if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 30 && baseId == BASH_1)
                timebonus += 30000;
            //Glyph of Typhoon: -3 sec cooldown for Typhoon
            if (lvl >= 70 && baseId == TYPHOON_1)
                timebonus += 3000;
            //Starfall: increase cooldown for bots
            if (baseId == STARFALL_1)
                timebonus -= 90000; //x2

            cooldown = std::max<int32>(int32((float(cooldown) * (1.0f - pctbonus)) - timebonus), 0);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            //pct bonus
            //Gift of the Earthmother part 2:
            if (lvl >= 55 && baseId == LIFEBLOOM_1)
                pctbonus += 0.1f;

            //flat bonus
            ////Unrelenting Assault (part 1, special): -0.5 sec global cooldown for Overpower and Revenge (not for tanks)
            //if (lvl >= 50 && !IsTank() && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
            //    timebonus += 500.f;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            uint32 spellId = spellInfo->Id;
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods

            //flat mods
            //Starfall
            if (spellId == STARFALL_DUMMY_AOE_4)
                flatbonus -= 10.f; //20 = 36 talented - 18 glyphed + 2 custom
            if (spellId == STARFALL_DAMAGE_AOE_4)
                flatbonus += 4.f; //5 nominal + 4 custom

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
            //Nature's Reach: +20% range for Balance Spells and Faerie Fire (Feral)
            if (lvl >= 20 && ((spellInfo->SpellFamilyFlags[0] & 0x600707) || (spellInfo->SpellFamilyFlags[1] & 0x1821220)))
                pctbonus += 0.2f;

            //flat mods
            //Glyph of Curse of Exhaustion: +5 yd range for Curse of Exhaustion
            //if (lvl >= 70 && baseId == CURSE_OF_EXHAUSTION_1)
            //    flatbonus += 5.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const override
        {
            uint32 bonusTargets = 0;

            //Glyph of Maul: + 1 target
            if (spellInfo->SpellFamilyFlags[0] & 0x800)
                bonusTargets += 1;
            //Glyph of Wild Growth: + 1 target
            if (spellInfo->SpellFamilyFlags[1] & 0x4000000)
                bonusTargets += 1;
            //Berserk: + 2 Mangle (Bear) targets
            if ((spellInfo->SpellFamilyFlags[1] & 0x40) &&
                me->GetAuraEffect(SPELL_AURA_MECHANIC_IMMUNITY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x40))
                bonusTargets += 2;

            targets = targets + bonusTargets;
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            float pctbonus = 1.0f;

            //Improved Leader of the Pack: chance
            if (baseId == LEADER_OF_THE_PACK_BUFF && effIndex == EFFECT_1)
                value += 4.f;

            value = value * pctbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            //Nature's Swiftness: notify master
            if (baseId == NATURES_SWIFTNESS_1)
            {
                if (!IAmFree())
                    ReportSpellCast(NATURES_SWIFTNESS_1, LocalizedNpcText(master, BOT_TEXT__USED), master);
            }

            //On next attack spells cooldown handle
            //if (baseId == MAUL_1)
            //    SetSpellCooldown(baseId, me->getAttackTimer(BASE_ATTACK) - 250);

            //Handle clearcasting
            //Notes: bugged with hurricane (periodic)
            if (AuraEffect const* eff = me->GetAuraEffect(OMEN_OF_CLARITY_BUFF, 0, me->GetGUID()))
                if (eff->IsAffectingSpell(spellInfo) && !spellInfo->IsRankOf(sSpellMgr->GetSpellInfo(HURRICANE_DAMAGE_1)))
                    me->RemoveAurasDueToSpell(OMEN_OF_CLARITY_BUFF);

            //Elune's Wrath: -100% takes priority since only Starfire
            AuraEffect const* elun = me->GetAuraEffect(ELUNES_WRATH_BUFF, 0);
            //Predator's Swiftness takes priority since duration
            AuraEffect const* pred = me->GetAuraEffect(PREDATORS_SWIFTNESS_BUFF, 0);
            //Nature's Swiftness
            AuraEffect const* natu = me->GetAuraEffect(NATURES_SWIFTNESS_1, 0);
            if (elun && elun->IsAffectingSpell(spellInfo))
                me->RemoveAurasDueToSpell(ELUNES_WRATH_BUFF);
            else if (pred && pred->IsAffectingSpell(spellInfo))
                me->RemoveAurasDueToSpell(PREDATORS_SWIFTNESS_BUFF);
            else if (natu && natu->IsAffectingSpell(spellInfo))
                me->RemoveAurasDueToSpell(NATURES_SWIFTNESS_1);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            if (_form == DRUID_CAT_FORM)
            {
                //Combo point generating
                if (baseId == CLAW_1 || baseId == MANGLE_CAT_1 || baseId == POUNCE_1 ||
                    baseId == RAKE_1 || baseId == RAVAGE_1 || baseId == SHRED_1)
                {
                    comboPoints++;
                    //debug
                    //TC_LOG_ERROR("entities.player", "druid_bot CP GEN: {} adds 1, now {}", spell->SpellName[0], uint32(comboPoints));
                    if (primalFuryProc)
                    {
                        comboPoints++;
                        //debug
                        //TC_LOG_ERROR("entities.player", "druid_bot CP EX: now {}", uint32(comboPoints));
                    }
                    if (comboPoints > 5)
                    {
                        comboPoints = 5;
                        //debug
                        //TC_LOG_ERROR("entities.player", "druid_bot CP NOR: now {}", uint32(comboPoints));
                    }
                }
                //Combo point spending
                //else if (baseId == FEROCIOUS_BITE_1 || baseId == MAIM_1 || baseId == RIP_1 || baseId == SAVAGE_ROAR_1)
                else if (spell->NeedsComboPoints())
                {
                    //debug
                    //TC_LOG_ERROR("entities.player", "druid_bot CP SPEND1: {} to 0", uint32(comboPoints));
                    if (lvl >= 25 && comboPoints > 0)
                    {
                        if (urand(1,100) <= uint32(comboPoints * 20))
                        {
                            me->CastSpell(me, PREDATORS_SWIFTNESS_BUFF, true);
                            //debug
                            //TC_LOG_ERROR("entities.player", "druid_bot CP SPEND1: PS proc!");
                        }
                    }
                    comboPoints = 0;
                }

                //Maim helper
                if (baseId == MAIM_1)
                    MoveBehind(target);
            }

            //Hibernate helper
            if (spellId == GetSpell(HIBERNATE_1))
            {
                hibery = true;
                hiberyCheckTimer = 2000;
            }

            //Bash desperate use (ranged): retreat
            //Only if hit
            if (baseId == BASH_1 && HasRole(BOT_ROLE_RANGED) && !HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
            {
                //if (GC_Timer <= lastdiff && GetSpell(TRAVEL_FORM_1))
                //    doCast(me, GetSpell(TRAVEL_FORM_1));
                GetInPosition(true, target);
            }

            //Infected Wound: handle proc
            if (baseId == SHRED_1 || baseId == MAUL_1 || baseId == MANGLE_BEAR_1 || baseId == MANGLE_CAT_1)
            {
                if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 45)
                {
                    CastSpellExtraArgs args(true);
                    args.SetOriginalCaster(me->GetGUID());
                    target->CastSpell(target, INFECTED_WOUNDS_EFFECT, args);
                }
            }

            //Brutal Impact: +1 sec duration for Bash and Pounce stun
            if (baseId == BASH_1 || baseId == POUNCE_1)
            {
                if (Aura* stu = target->GetAura(spellId))
                {
                    //1 extra second on creatures
                    uint32 dur = stu->GetDuration() + target->GetTypeId() == TYPEID_PLAYER ? 1000 : 2000;
                    stu->SetDuration(dur);
                    stu->SetMaxDuration(dur);
                }
            }

            //Glyph of Starfire: Increase max duration of Moonfire and refresh
            if (baseId == STARFIRE_1 && GetSpell(MOONFIRE_1))
            {
                if (lvl >= 20)
                {
                    if (Aura* aur = target->GetAura(GetSpell(MOONFIRE_1), me->GetGUID()))
                    {
                        //extra 9 sec base + 3 sec Nature's Splendor
                        if (aur->GetMaxDuration() < spell->GetMaxDuration() + 12000)
                        {
                            aur->SetDuration(aur->GetDuration() + 3000);
                            aur->SetMaxDuration(aur->GetMaxDuration() + 3000);
                        }
                    }
                }
            }
            //Nature's Splendor: Increased duraion for
            //Moonfire (3 sec), Rejuvenation (3 sec, let 6), Regrowth (6 sec, let 9),
            //Insect Swarm (2 sec) and Lifebloom (2 sec)
            if (baseId == MOONFIRE_1 || baseId == REJUVENATION_1 || baseId == REGROWTH_1 ||
                baseId == INSECT_SWARM_1 || baseId == LIFEBLOOM_1)
            {
                if (lvl >= 20)
                {
                    if (Aura* aur = target->GetAura(spellId, me->GetGUID()))
                    {
                        uint32 dur = aur->GetDuration();

                        switch (baseId)
                        {
                            case MOONFIRE_1:
                                dur += 3000;
                                break;
                            case REJUVENATION_1:
                                dur += 6000;
                                break;
                            case REGROWTH_1:
                                dur += 9000;
                                break;
                            case INSECT_SWARM_1:
                            case LIFEBLOOM_1:
                                dur += 2000;
                                break;
                            default:
                                break;
                        }

                        aur->SetDuration(dur);
                        aur->SetMaxDuration(dur);
                    }
                }
            }

            if (baseId == THORNS_1)
            {
                //30 min duration for Thorns
                if (Aura* thorn = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = 30 * MINUTE * IN_MILLISECONDS;
                    thorn->SetDuration(dur);
                    thorn->SetMaxDuration(dur);
                }
            }
            if (baseId == MARK_OF_THE_WILD_1)
            {
                //1 hour duration for Mark of the Wild
                if (Aura* mark = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = 1 * HOUR * IN_MILLISECONDS;
                    mark->SetDuration(dur);
                    mark->SetMaxDuration(dur);

                    //Improved Mark of the Wild: +40% effect
                    for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
                        if (AuraEffect* app = mark->GetEffect(i))
                            app->ChangeAmount((app->GetAmount() * 14) / 10);
                }
            }
            if ((baseId == FAERIE_FIRE_NORMAL_1 || baseId == FAERIE_FIRE_FERAL_1) && lvl >= 40)
            {
                //Improved Faerie Fire (part 1): incrase crit chance taken by 3% (effect2)
                if (AuraEffect* faf = target->GetAuraEffect(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE, SPELLFAMILY_DRUID, 0x400, 0x0, 0x0, me->GetGUID()))
                    faf->ChangeAmount(faf->GetAmount() + 3);
            }

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Savage Roar duration
            if (spellId == SAVAGE_ROAR_BUFF || spellId == SAVAGE_ROAR_1)
            {
                if (Aura* sav = me->GetAura(spellId))
                {
                    uint32 dur = sav->GetDuration() + 6000;
                    sav->SetDuration(dur);
                    sav->SetMaxDuration(dur);
                }
                //Glyph of Savage Roar: 3% increase (20 for bot)
                if (spellId == SAVAGE_ROAR_BUFF)
                {
                    AuraEffect* sav = me->GetAuraEffect(spellId, EFFECT_0);
                    if (sav)
                        sav->ChangeAmount(sav->GetAmount() + 20);
                }
            }

            //Glyph of Berserk: duration
            if (baseId == BERSERK_1)
            {
                if (Aura* ber = me->GetAura(spellId))
                {
                    uint32 dur = ber->GetDuration() + 5000;
                    ber->SetDuration(dur);
                    ber->SetMaxDuration(dur);
                }
            }
            //Glyph of Survival Instincts
            if (lvl >= 20 && spellId == SURVIVAL_INSTINCTS_1)
            {
                AuraEffect* sur = me->GetAuraEffect(spellId, EFFECT_0);
                if (sur)
                    sur->ChangeAmount(sur->GetAmount() + 15);
            }
            //Starfall: duration
            if (baseId == STARFALL_1)
            {
                if (Aura* sta = me->GetAura(spellId))
                {
                    uint32 dur = sta->GetDuration() * 3;
                    sta->SetDuration(dur);
                    sta->SetMaxDuration(dur);
                }
            }
            //Predatoe's Swiftness: duration
            if (spellId == PREDATORS_SWIFTNESS_BUFF)
            {
                if (Aura* swi = me->GetAura(spellId))
                {
                    swi->SetDuration(15000);
                    swi->SetMaxDuration(15000);
                }
            }
            //Eclipse (helper): cooldown
            if (spellId == ECLIPSE_SOLAR_BUFF || spellId == ECLIPSE_LUNAR_BUFF)
                SetSpellCooldown(spellId, 30000);
            //Improved Leader of the Pack: handle SPELLMOD_EFFECT_2 MOVED to effect mods
            /*
            if (spellId == LEADER_OF_THE_PACK_BUFF)
            {
                AuraEffect* lea = me->GetAuraEffect(spellId, EFFECT_1, me->GetGUID());
                if (lea)
                    lea->ChangeAmount(lea->GetAmount() + 4);
            }
            */
            //Improved Barkskin: 10% additional damage reduction
            if ((GetSpec() == BOT_SPEC_DRUID_RESTORATION) && baseId == BARKSKIN_1)
            {
                AuraEffect* bar = me->GetAuraEffect(spellId, EFFECT_1, me->GetGUID());
                if (bar)
                    bar->ChangeAmount(bar->GetAmount() - 10);
            }

            //Forms helper
            if (baseId == BEAR_FORM_1)
                setStats(DRUID_BEAR_FORM);
            else if (baseId == CAT_FORM_1)
                setStats(DRUID_CAT_FORM);
            else if (baseId == MOONKIN_FORM_1)
                setStats(DRUID_MOONKIN_FORM);
            else if (baseId == TREE_OF_LIFE_FORM_1)
                setStats(DRUID_TREE_FORM);
            else if (baseId == TRAVEL_FORM_1)
                setStats(DRUID_TRAVEL_FORM);
            else if (baseId == AQUATIC_FORM_1)
                setStats(DRUID_AQUATIC_FORM);
            else if (baseId == FLIGHT_FORM_1)
                setStats(DRUID_FLIGHT_FORM);

            //Cat Form: delay prowl just a little bit
            if (baseId == CAT_FORM_1 && GetSpell(PROWL_1) && GetSpellCooldown(PROWL_1) < 300)
                SetSpellCooldown(PROWL_1, 300);

            //Leader of the Pack helper
            if (baseId == CAT_FORM_1 || baseId == BEAR_FORM_1)
            {
                if ((GetSpec() == BOT_SPEC_DRUID_FERAL) && lvl >= 40)
                    me->CastSpell(me, LEADER_OF_THE_PACK_BUFF, true);
            }

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
        {
            if (!u)
                return;
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void OwnerAttackedBy(Unit* u) override
        {
            if (!u)
                return;
            OnOwnerDamagedBy(u);
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(WRATH_1) : 20.f;
        }

        uint8 GetPetPositionNumber(Creature const* summon) const override
        {
            for (uint8 i = 0; i != MAX_TREANTS; ++i)
                if (_treants[i] == summon->GetGUID())
                    return i;

            return 0;
        }

        void SummonBotPet(Unit* target)
        {
            UnsummonTreants();

            uint32 entry = BOT_PET_FORCE_OF_NATURE;

            for (uint8 i = 0; i != MAX_TREANTS; ++i)
            {
                //Position pos;

                //30 sec duration
                Creature* myPet = me->SummonCreature(entry, (me->GetDistance(target) < 36.f ? *target : *me), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s);
                //me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0, 2, me->GetOrientation());
                //myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
                myPet->SetCreator(master);
                myPet->SetOwnerGUID(me->GetGUID());
                myPet->SetFaction(master->GetFaction());
                myPet->SetControlledByPlayer(!IAmFree());
                myPet->SetPvP(me->IsPvP());
                myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
                myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, FORCE_OF_NATURE_1);
                //botPet = myPet;

                myPet->Attack(target, true);
                if (!HasBotCommandState(BOT_COMMAND_MASK_UNCHASE))
                    myPet->GetMotionMaster()->MoveChase(target);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == BOT_PET_FORCE_OF_NATURE)
            {
                bool found = false;
                for (uint8 i = 0; i != MAX_TREANTS; ++i)
                {
                    if (!_treants[i])
                    {
                        _treants[i] = summon->GetGUID();
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    TC_LOG_ERROR("entities.unit", "Druid_bot:JustSummoned() treants array is full");
                    ASSERT(false);
                }
            }
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: {}'s {}", me->GetName(), summon->GetName());
            //if (summon == botPet)
            //    botPet = nullptr;
            if (summon->GetEntry() == BOT_PET_FORCE_OF_NATURE)
            {
                //bool found = false;
                for (uint8 i = 0; i != MAX_TREANTS; ++i)
                {
                    if (_treants[i] == summon->GetGUID())
                    {
                        _treants[i] = ObjectGuid::Empty;
                        //found = true;
                        break;
                    }
                }
                //if (!found)
                //{
                //    TC_LOG_ERROR("entities.unit", "Druid_bot:SummonedCreatureDespawn() treant is not found in array");
                //    ASSERT(false);
                //}
            }
        }

        void UnsummonTreants()
        {
            for (uint8 i = 0; i != MAX_TREANTS; ++i)
            {
                if (_treants[i])
                {
                    if (Unit* tr = ObjectAccessor::GetUnit(*me, _treants[i]))
                        tr->ToTempSummon()->UnSummon();
                    else
                        _treants[i] = ObjectGuid::Empty;
                }
            }
        }

        void UnsummonAll(bool /*savePets*/ = true) override
        {
            for (uint8 i = 0; i != MAX_TREANTS; ++i)
            {
                if (_treants[i])
                    if (Unit* tr = ObjectAccessor::GetUnit(*me, _treants[i]))
                        tr->ToTempSummon()->UnSummon();
            }
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_COMBO_POINTS:
                    return comboPoints;
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_FORCE_OF_NATURE;
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            UnsummonAll(false);
            for (uint8 i = 0; i != MAX_TREANTS; ++i)
                _treants[i] = ObjectGuid::Empty;

            //_form = BOT_STANCE_NONE;
            rage = 0;
            removeShapeshiftForm();

            energy = 0;
            comboPoints = 0;
            primalFuryProc = false;

            hibery = false;
            hiberyCheckTimer = 0;

            me->SetMaxPower(POWER_ENERGY, 100); //for regeneration
            rageLossMult = sWorld->getRate(RATE_POWER_RAGE_LOSS);

            ragetimer = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (ragetimer > diff)                   ragetimer -= diff;

            if (hiberyCheckTimer > diff)            hiberyCheckTimer -= diff;
        }

        void InitPowers() override
        {
            switch (me->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                    me->SetPowerType(POWER_RAGE);
                    break;
                case FORM_CAT:
                    me->SetPowerType(POWER_ENERGY);
                    break;
                default:
                    me->SetPowerType(POWER_MANA);
                    break;
            }
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isBala = GetSpec() == BOT_SPEC_DRUID_BALANCE;
            bool isFera = GetSpec() == BOT_SPEC_DRUID_FERAL;
            bool isRest = GetSpec() == BOT_SPEC_DRUID_RESTORATION;

            InitSpellMap(MARK_OF_THE_WILD_1);
            InitSpellMap(THORNS_1);
            InitSpellMap(HEALING_TOUCH_1);
            InitSpellMap(REGROWTH_1);
            InitSpellMap(REJUVENATION_1);
            InitSpellMap(LIFEBLOOM_1);
            InitSpellMap(NOURISH_1);
            InitSpellMap(TRANQUILITY_1);
            InitSpellMap(REVIVE_1);
            InitSpellMap(REBIRTH_1);
            InitSpellMap(BEAR_FORM_1);
            InitSpellMap(SWIPE_BEAR_1);
            InitSpellMap(BASH_1);
            InitSpellMap(MAUL_1);
            InitSpellMap(CHALLENGING_ROAR_1);
            InitSpellMap(ENRAGE_1);
            InitSpellMap(FRENZIED_REGENERATION_1);
            InitSpellMap(GROWL_1);
            InitSpellMap(LACERATE_1);
            InitSpellMap(SURVIVAL_INSTINCTS_1);
            InitSpellMap(FAERIE_FIRE_FERAL_1);
            InitSpellMap(CAT_FORM_1);
            InitSpellMap(CLAW_1);
            InitSpellMap(RAKE_1);
            InitSpellMap(SHRED_1);
            InitSpellMap(POUNCE_1);
            InitSpellMap(RAVAGE_1);
            InitSpellMap(RIP_1);
            InitSpellMap(FEROCIOUS_BITE_1);
            InitSpellMap(MAIM_1);
            InitSpellMap(SWIPE_CAT_1);
            InitSpellMap(SAVAGE_ROAR_1);
            InitSpellMap(TIGERS_FURY_1);
            InitSpellMap(COWER_1);
            InitSpellMap(DASH_1);
  /*custom*/lvl >= 22 ? InitSpellMap(PROWL_1) : RemoveSpell(PROWL_1); //base lvl 20
            InitSpellMap(MOONFIRE_1);
            InitSpellMap(STARFIRE_1);
            InitSpellMap(WRATH_1);
            InitSpellMap(HURRICANE_1);
            InitSpellMap(FAERIE_FIRE_NORMAL_1);
            InitSpellMap(TRAVEL_FORM_1);
            InitSpellMap(AQUATIC_FORM_1);
            InitSpellMap(FLIGHT_FORM_1);
            InitSpellMap(CURE_POISON_1);
            InitSpellMap(ABOLISH_POISON_1);
            InitSpellMap(REMOVE_CURSE_1);
            InitSpellMap(ENTANGLING_ROOTS_1);
            InitSpellMap(CYCLONE_1);
            InitSpellMap(HIBERNATE_1);
            InitSpellMap(BARKSKIN_1);
            InitSpellMap(NATURES_GRASP_1);
            InitSpellMap(INNERVATE_1);

     /*tal*/lvl >= 30 && isBala ? InitSpellMap(INSECT_SWARM_1) : RemoveSpell(INSECT_SWARM_1);
     /*tal*/lvl >= 40 && isBala ? InitSpellMap(MOONKIN_FORM_1) : RemoveSpell(MOONKIN_FORM_1);
     /*tal*/lvl >= 50 && isBala ? InitSpellMap(TYPHOON_1) : RemoveSpell(TYPHOON_1);
     /*tal*/lvl >= 50 && isBala ? InitSpellMap(FORCE_OF_NATURE_1) : RemoveSpell(FORCE_OF_NATURE_1); //not casted
     /*tal*/lvl >= 60 && isBala ? InitSpellMap(STARFALL_1) : RemoveSpell(STARFALL_1);

     /*tal*/lvl >= 30 && isFera ? InitSpellMap(FERAL_CHARGE_BEAR_1) : RemoveSpell(FERAL_CHARGE_BEAR_1);
     /*tal*/lvl >= 30 && isFera ? InitSpellMap(FERAL_CHARGE_CAT_1) : RemoveSpell(FERAL_CHARGE_CAT_1);
     /*tal*/lvl >= 50 && isFera ? InitSpellMap(MANGLE_BEAR_1) : RemoveSpell(MANGLE_BEAR_1);
     /*tal*/lvl >= 50 && isFera ? InitSpellMap(MANGLE_CAT_1) : RemoveSpell(MANGLE_CAT_1);
     /*tal*/lvl >= 60 && isFera ? InitSpellMap(BERSERK_1) : RemoveSpell(BERSERK_1);

     /*tal*/lvl >= 30 && isRest ? InitSpellMap(NATURES_SWIFTNESS_1) : RemoveSpell(NATURES_SWIFTNESS_1);
     /*tal*/lvl >= 40 && isRest ? InitSpellMap(SWIFTMEND_1) : RemoveSpell(SWIFTMEND_1);
     /*tal*/lvl >= 50 && isRest ? InitSpellMap(TREE_OF_LIFE_FORM_1) : RemoveSpell(TREE_OF_LIFE_FORM_1);
     /*tal*/lvl >= 60 && isRest ? InitSpellMap(WILD_GROWTH_1) : RemoveSpell(WILD_GROWTH_1);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isBala = GetSpec() == BOT_SPEC_DRUID_BALANCE;
            bool isFera = GetSpec() == BOT_SPEC_DRUID_FERAL;
            bool isRest = GetSpec() == BOT_SPEC_DRUID_RESTORATION;

            RefreshAura(NATURESGRACE, level >= 20 ? 1 : 0);
            RefreshAura(DREAMSTATE, isBala && level >= 35 ? 1 : 0);
            RefreshAura(BALANCE_OF_POWER, isBala && level >= 35 ? 1 : 0);
            RefreshAura(IMPROVED_MOONKIN_FORM, !IAmFree() && isBala && level >= 40 ? 1 : 0);
            RefreshAura(ECLIPSE, isBala && level >= 50 ? 1 : 0);
            RefreshAura(EARTH_AND_MOON, isBala && level >= 55 ? 1 : 0);

            RefreshAura(PRIMAL_PRECISION, isFera && level >= 25 ? 1 : 0);
            RefreshAura(SURVIVAL_OF_THE_FITTEST, isFera && level >= 35 ? 1 : 0);
            RefreshAura(IMPROVED_LEADER_OF_THE_PACK, isFera && level >= 40 ? 1 : 0);
            RefreshAura(PRIMAL_TENACITY, isFera && level >= 40 ? 1 : 0);
            RefreshAura(KING_OF_THE_JUNGLE, isFera && level >= 50 ? 1 : 0);
            RefreshAura(PRIMAL_GORE, isFera && level >= 55 ? 1 : 0);

            RefreshAura(IMPROVED_MARK_OF_THE_WILD, level >= 10 ? 1 : 0);
            RefreshAura(FUROR, level >= 10 ? 1 : 0);
            RefreshAura(NATURALIST, level >= 15 ? 1 : 0);
            RefreshAura(INTENSITY, level >= 20 ? 1 : 0);
            RefreshAura(OMEN_OF_CLARITY, level >= 20 ? 1 : 0);
            RefreshAura(NATURAL_PERFECTION3, isRest && level >= 45 ? 1 : 0);
            RefreshAura(NATURAL_PERFECTION2, isRest && level >= 43 && level < 45 ? 1 : 0);
            RefreshAura(NATURAL_PERFECTION1, isRest && level >= 41 && level < 43 ? 1 : 0);
            RefreshAura(LIVING_SEED3, isRest && level >= 50 ? 1 : 0);
            RefreshAura(LIVING_SEED2, isRest && level >= 48 && level < 50 ? 1 : 0);
            RefreshAura(LIVING_SEED1, isRest && level >= 46 && level < 48 ? 1 : 0);
            RefreshAura(REVITALIZE3, isRest && level >= 55 ? 1 : 0);
            RefreshAura(REVITALIZE2, isRest && level >= 53 && level < 55 ? 1 : 0);
            RefreshAura(REVITALIZE1, isRest && level >= 51 && level < 53 ? 1 : 0);
            RefreshAura(GIFT_OF_THE_EARTHMOTHER, isRest && level >= 55 ? 1 : 0);

            RefreshAura(GLYPH_NOURISH, level >= 80 ? 1 : 0);
            RefreshAura(GLYPH_SWIFTMEND, level >= 45 ? 1 : 0);
            RefreshAura(GLYPH_INNERVATE, level >= 40 ? 1 : 0);
            RefreshAura(GLYPH_RAPID_REJUVENATION, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_REGROWTH, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_REJUVENATION, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_FRENZIED_REGENERATION, level >= 36 ? 1 : 0);
            RefreshAura(GLYPH_BARKSKIN, level >= 44 ? 1 : 0);
            RefreshAura(GLYPH_RAKE, level >= 24 ? 1 : 0);
            RefreshAura(GLYPH_SHRED, level >= 22 ? 1 : 0);
            RefreshAura(T10_RESTO_P4_BONUS, level >= 80 ? 1 : 0);
            RefreshAura(T9_RESTO_P4_BONUS, level >= 80 ? 1 : 0);
            RefreshAura(T8_RESTO_P4_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T9_BALANCE_P2_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T10_BALANCE_P2_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T10_BALANCE_P4_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T8_FERAL_P2_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T10_FERAL_P4_BONUS, level >= 80 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case MARK_OF_THE_WILD_1:
                case THORNS_1:
                case HEALING_TOUCH_1:
                case REJUVENATION_1:
                case LIFEBLOOM_1:
                case REGROWTH_1:
                case NOURISH_1:
                case WILD_GROWTH_1:
                case SWIFTMEND_1:
                case TRANQUILITY_1:
                case HURRICANE_1:
                case INNERVATE_1:
                case ABOLISH_POISON_1:
                case NATURES_GRASP_1:
                case BARKSKIN_1:
                case BEAR_FORM_1:
                case CAT_FORM_1:
                case TRAVEL_FORM_1:
                    return true;
                case AQUATIC_FORM_1:
                    return me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) && me->IsUnderWater();
                case FLIGHT_FORM_1:
                    return master->IsMounted() && !me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) && !me->IsUnderWater();
                case TYPHOON_1:
                case STARFALL_1:
                case MOONKIN_FORM_1:
                    return (GetBotRoles() & BOT_ROLE_MASK_MAIN) == (BOT_ROLE_DPS|BOT_ROLE_RANGED);
                case TREE_OF_LIFE_FORM_1:
                    return ((GetBotRoles() & BOT_ROLE_MASK_MAIN) & ~BOT_ROLE_RANGED) == BOT_ROLE_HEAL;
                case SURVIVAL_INSTINCTS_1:
                case FRENZIED_REGENERATION_1:
                case ENRAGE_1:
                case CHALLENGING_ROAR_1:
                    return _form == DRUID_BEAR_FORM;
                case TIGERS_FURY_1:
                case DASH_1:
                case PROWL_1:
                    return _form == DRUID_CAT_FORM;
                case BERSERK_1:
                    return (_form == DRUID_BEAR_FORM || _form == DRUID_CAT_FORM) &&
                        (((GetBotRoles() & BOT_ROLE_MASK_MAIN) & BOT_ROLE_TANK) || (GetBotRoles() & BOT_ROLE_MASK_MAIN) == BOT_ROLE_DPS);
                default:
                    return false;
            }
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Druid_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Druid_spells_cc;
        }
        std::vector<uint32> const* GetHealingSpellsList() const override
        {
            return &Druid_spells_heal;
        }
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Druid_spells_support;
        }

        void InitHeals() override
        {
            SpellInfo const* spellInfo;
            if (InitSpell(me, NOURISH_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, NOURISH_1));
                _heals[NOURISH_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[NOURISH_1] = 0;

            if (InitSpell(me, REGROWTH_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, REGROWTH_1));
                _heals[REGROWTH_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[REGROWTH_1] = 0;

            if (InitSpell(me, HEALING_TOUCH_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, HEALING_TOUCH_1));
                _heals[HEALING_TOUCH_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[HEALING_TOUCH_1] = 0;

            if (InitSpell(me, REJUVENATION_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, REJUVENATION_1));
                _heals[REJUVENATION_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), DOT, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[REJUVENATION_1] = 0;
        }

    private:
        //Treants
        ObjectGuid _treants[MAX_TREANTS];
        //Timers/other
/*Form*/BotStances _form;
/*Misc*/mutable bool primalFuryProc;
/*Misc*/uint8 comboPoints;
/*Misc*/uint32 ragetimer;
        bool hibery;
        uint32 hiberyCheckTimer;
/*Misc*/int32 rage, energy;

        typedef std::unordered_map<uint32 /*baseId*/, int32 /*amount*/> HealMap;
        HealMap _heals;
    };
};

void AddSC_druid_bot()
{
    new druid_bot();
}
