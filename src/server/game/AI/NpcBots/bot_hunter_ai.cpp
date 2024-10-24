#include "bot_ai.h"
#include "botmgr.h"
#include "botspell.h"
#include "bottext.h"
#include "bottraits.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
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
Hunter NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - around 95%
TODO: Master's Call
*/

enum HunterBaseSpells
{
    AUTO_SHOT_1                         = 75,
    ARCANE_SHOT_1                       = 3044,
    TRANQ_SHOT_1                        = 19801,
    BLACK_ARROW_1                       = 3674,
    SILENCING_SHOT_1                    = 34490,
    CHIMERA_SHOT_1                      = 53209,
    AIMED_SHOT_1                        = 19434,
    STEADY_SHOT_1                       = 56641,
    EXPLOSIVE_SHOT_1                    = 53301,
    KILL_SHOT_1                         = 53351,
    MULTISHOT_1                         = 2643,
    VOLLEY_1                            = 1510,
    SCATTER_SHOT_1                      = 19503,
    CONCUSSIVE_SHOT_1                   = 5116,
    DISTRACTING_SHOT_1                  = 20736,
    SERPENT_STING_1                     = 1978,
    SCORPID_STING_1                     = 3043,
    VIPER_STING_1                       = 3034,
    RAPID_FIRE_1                        = 3045,
    FLARE_1                             = 1543,
    TRUESHOT_AURA_1                     = 19506,
    WYVERN_STING_1                      = 19386,
    WING_CLIP_1                         = 2974,
    RAPTOR_STRIKE_1                     = 2973,
    MONGOOSE_BITE_1                     = 1495,
    COUNTERATTACK_1                     = 19306,
    DISENGAGE_1                         = 781,
    IMMOLATION_TRAP_1                   = 13795,
    FREEZING_TRAP_1                     = 1499,
    FROST_TRAP_1                        = 13809,
    EXPLOSIVE_TRAP_1                    = 13813,
    FREEZING_ARROW_1                    = 60192,
    SNAKE_TRAP_1                        = 34600,//NIY
    HUNTERS_MARK_1                      = 1130,
    SCARE_BEAST_1                       = 1513,
    FEIGN_DEATH_1                       = 5384,
    READINESS_1                         = 23989,
    DETERRENCE_1                        = 19263,
    MISDIRECTION_1                      = 34477,
    MEND_PET_1                          = 136,

    ASPECT_OF_THE_MONKEY_1              = 13163,
    ASPECT_OF_THE_HAWK_1                = 13165,
    ASPECT_OF_THE_CHEETAH_1             = 5118,
    ASPECT_OF_THE_VIPER_1               = 34074,
    ASPECT_OF_THE_BEAST_1               = 13161,//NIY
    ASPECT_OF_THE_PACK_1                = 13159,
    ASPECT_OF_THE_WILD_1                = 20043,
    ASPECT_OF_THE_DRAGONHAWK_1          = 61846
};

enum HunterPassives
{
//Talents
    SUREFOOTED                          = 24283,//rank 3
    ENTRAPMENT                          = 19388,//rank 3
    RAPID_KILLING                       = 34949,//rank 2
    IMPROVED_MEND_PET                   = 19573,//rank 2
    LOCK_AND_LOAD                       = 56344,//rank 3
    CONCUSSIVE_BARRAGE                  = 35102,//rank 2
    PIERCING_SHOTS                      = 53238,//rank 3
    EXPOSE_WEAKNESS                     = 34503,//rank 3
    THRILL_OF_THE_HUNT                  = 34499,//rank 3
    MASTER_MARKSMAN                     = 34489,//rank 5
    MASTER_TACTICIAN1                   = 34506,
    MASTER_TACTICIAN2                   = 34507,
    MASTER_TACTICIAN3                   = 34508,
    MASTER_TACTICIAN4                   = 34838,
    MASTER_TACTICIAN5                   = 34839,
    NOXIOUS_STINGS                      = 53297,//rank 3
    WILD_QUIVER                         = 53217,//rank 3
    SNIPER_TRAINING                     = 53304,//rank 3

    GLYPH_RAPTOR_STRIKE                 = 63086,
    GLYPH_ASPECT_OF_THE_VIPER           = 56851,
    GLYPH_FREEZING_TRAP                 = 56845,
    GLYPH_EXPLOSIVE_TRAP                = 63068,

    HUNTER_T8_P2                        = 67150,//serpent sting crits
    HUNTER_T10_P2                       = 70727,//autoshot 15% dmg proc
    HUNTER_T10_P4                       = 70730 //sting 20% ap proc
};

enum HunterSpecial
{
    ASPECT_NONE                         = 0,
    ASPECT_MONKEY                       = 1,
    ASPECT_HAWK                         = 2,
    ASPECT_CHEETAH                      = 3,
    ASPECT_VIPER                        = 4,
    ASPECT_BEAST                        = 5,
    ASPECT_PACK                         = 6,
    ASPECT_WILD                         = 7,
    ASPECT_DRAGONHAWK                   = 8,

    SPECIFIC_ASPECT_MONKEY              = 0x001,
    SPECIFIC_ASPECT_HAWK                = 0x002,
    SPECIFIC_ASPECT_CHEETAH             = 0x004,
    SPECIFIC_ASPECT_VIPER               = 0x008,
    SPECIFIC_ASPECT_BEAST               = 0x010,
    SPECIFIC_ASPECT_PACK                = 0x020,
    SPECIFIC_ASPECT_WILD                = 0x040,
    SPECIFIC_ASPECT_DRAGONHAWK          = 0x080,
    SPECIFIC_ASPECT_MY_ASPECT           = 0x100,
    //SPECIFIC_ASPECT_ALL_AREA_AUTOUSE    = (SPECIFIC_ASPECT_PACK),

    IMPROVED_CONCUSSION                 = 28445,
    IMPROVED_WING_CLIP_NORMAL           = 47168,
    IMPROVED_WING_CLIP_EX               = 35963,

    VOLLEY_DAMAGE_1                     = 42243,//rank 1
    //EXPLOSIVE_TRAP_DAMAGE_1             = 13812,//same as EXPLOSIVE_TRAP_AURA_1

    QUICK_SHOTS_BUFF                    = 6150,
    RAPID_KILLING_BUFF                  = 35099,//rank 2
    LOCK_AND_LOAD_BUFF                  = 56453,//rank 3
    SNIPER_TRAINING_BUFF                = 64420,//rank 3
    RAPID_RECUPERATION_BUFF             = 54227,//rank 2, rapid fire, hidden
    RAPID_RECUPERATION_BUFF2            = 58882,//rapid killing, 6 sec
    IMPROVED_STEADY_SHOT_BUFF           = 53220,

    FROST_TRAP_AURA                     = 13810,
    FREEZING_TRAP_AURA_1                = 3355,
    IMMOLATION_TRAP_AURA_1              = 13797,
    EXPLOSIVE_TRAP_AURA_1               = 13812,//same as EXPLOSIVE_TRAP_DAMAGE_1
    WYVERN_STING_DOT_AURA_1             = 24131,
    FREEZING_ARROW_AURA                 = 60210,
    EXPLOSIVE_SHOT_PERIODIC_DUMMY_AURA  = 53352,

    ASPECT_OF_THE_DRAGONHAWK_MONKEY     = 61848, //linked, hidden

    GLYPH_OF_ARCANE_SHOT_ENERGIZE       = 61389,
    RAPID_RECUPERATION_ENERGIZE         = 58883,//rapid killing
    RAPID_RECUPERATION_ENERGIZE_PCT_1   = 64180,//rank 1, 2%

    GIFT_OF_NAARU_HUNTER                = 59543,

    SPIRIT_BOND_PET                     = 24529,
    KINDRED_SPIRITS_PET                 = 57475,
    //INTIMIDATION_1                      = 24394,
    BESTIAL_WRATH_1                     = 19574,
    //BEAST_WITHIN_1                      = 34471,

    GO_FOR_THE_THROAT_ENERGIZE          = 34953,
    FRENZY_BUFF                         = 19615
};
//talent tiers 20-32-44-56-68-80

static const uint32 Hunter_spells_damage_arr[] =
{ AIMED_SHOT_1, ARCANE_SHOT_1, BLACK_ARROW_1, COUNTERATTACK_1, CHIMERA_SHOT_1, EXPLOSIVE_SHOT_1, EXPLOSIVE_TRAP_1,
IMMOLATION_TRAP_1, KILL_SHOT_1, MONGOOSE_BITE_1, MULTISHOT_1, RAPTOR_STRIKE_1, SCATTER_SHOT_1, SERPENT_STING_1,
STEADY_SHOT_1, VOLLEY_1, WYVERN_STING_1 };

static const uint32 Hunter_spells_cc_arr[] =
{ CONCUSSIVE_SHOT_1, FREEZING_ARROW_1, FREEZING_TRAP_1, FROST_TRAP_1, SCARE_BEAST_1, SCATTER_SHOT_1,
SILENCING_SHOT_1, WING_CLIP_1, WYVERN_STING_1 };

static const uint32 Hunter_spells_support_arr[] =
{ /*ASPECT_OF_THE_BEAST_1, */ASPECT_OF_THE_MONKEY_1, ASPECT_OF_THE_HAWK_1, ASPECT_OF_THE_DRAGONHAWK_1,
ASPECT_OF_THE_CHEETAH_1, ASPECT_OF_THE_PACK_1, ASPECT_OF_THE_VIPER_1, ASPECT_OF_THE_WILD_1,
DETERRENCE_1, DISENGAGE_1, DISTRACTING_SHOT_1, FEIGN_DEATH_1, FLARE_1, HUNTERS_MARK_1, MEND_PET_1,
MISDIRECTION_1, RAPID_FIRE_1, READINESS_1, SCORPID_STING_1, /*SNAKE_TRAP_1, */TRANQ_SHOT_1, VIPER_STING_1 };

static const std::vector<uint32> Hunter_spells_damage(FROM_ARRAY(Hunter_spells_damage_arr));
static const std::vector<uint32> Hunter_spells_cc(FROM_ARRAY(Hunter_spells_cc_arr));
static const std::vector<uint32> Hunter_spells_support(FROM_ARRAY(Hunter_spells_support_arr));

class hunter_bot : public CreatureScript
{
public:
    hunter_bot() : CreatureScript("hunter_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new hunter_botAI(creature);
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
    struct hunter_botAI : public bot_ai
    {
        hunter_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_HUNTER;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;

            return bot_ai::doCast(victim, spellId);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { aspectTimer = 0; bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { Aspect = 0; UnsummonAll(false); bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void CheckAspects(uint32 diff)
        {
            if (aspectTimer > diff || me->IsMounted() || Feasting() || IsCasting() || Rand() > 55)
                return;

            aspectTimer = urand(5000, 10000);

            if (Aspect == ASPECT_VIPER && GetManaPCT(me) < 50)
                return;

            uint32 ASPECT_OF_THE_MONKEY = GetSpell(ASPECT_OF_THE_MONKEY_1);
            uint32 ASPECT_OF_THE_HAWK = GetSpell(ASPECT_OF_THE_HAWK_1);
            uint32 ASPECT_OF_THE_CHEETAH = GetSpell(ASPECT_OF_THE_CHEETAH_1);
            uint32 ASPECT_OF_THE_VIPER = GetSpell(ASPECT_OF_THE_VIPER_1);
            //uint32 ASPECT_OF_THE_BEAST = GetSpell(ASPECT_OF_THE_BEAST_1);
            uint32 ASPECT_OF_THE_PACK = GetSpell(ASPECT_OF_THE_PACK_1);
            uint32 ASPECT_OF_THE_WILD = GetSpell(ASPECT_OF_THE_WILD_1);
            uint32 ASPECT_OF_THE_DRAGONHAWK = GetSpell(ASPECT_OF_THE_DRAGONHAWK_1);

            std::map<uint32 /*baseid*/, uint32 /*curid*/> idMap;
            uint32 mask = _getAspectsMask(idMap);

            if (Aspect == ASPECT_WILD) //manual
            {
                if (idMap[ASPECT_OF_THE_WILD_1] != ASPECT_OF_THE_WILD)
                    if (doCast(me, ASPECT_OF_THE_WILD))
                        return;
                return;
            }

            if (GetManaPCT(me) < 20)
            {
                if (ASPECT_OF_THE_VIPER)
                {
                    if (doCast(me, ASPECT_OF_THE_VIPER))
                        return;
                }
                return;
            }
            else if (Aspect == ASPECT_VIPER && GetManaPCT(me) > 50)
            {
                me->RemoveAurasDueToSpell(ASPECT_OF_THE_VIPER_1, me->GetGUID());
                Aspect = ASPECT_NONE;
            }

            if (IAmFree())
            {
                InstanceTemplate const* instt = sObjectMgr->GetInstanceTemplate(me->GetMap()->GetId());
                bool map_allows_mount = (!me->GetMap()->IsDungeon() || me->GetMap()->IsBattlegroundOrArena()) && (!instt || instt->AllowMount);
                if (me->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD) &&
                    (!me->GetVictim() ?
                        (me->IsInCombat() || !map_allows_mount || !IsOutdoors() || IsFlagCarrier(me)) :
                        !me->IsWithinDist(me->GetVictim(), 8.0f + GetSpellAttackRange(true))))
                {
                    if (ASPECT_OF_THE_CHEETAH && !(mask & (SPECIFIC_ASPECT_CHEETAH | SPECIFIC_ASPECT_PACK)) && Aspect != ASPECT_CHEETAH)
                    {
                        if (doCast(me, ASPECT_OF_THE_CHEETAH))
                            return;
                    }

                    return;
                }
                else if (Aspect == ASPECT_CHEETAH)
                {
                    me->RemoveAurasDueToSpell(ASPECT_OF_THE_CHEETAH_1, me->GetGUID());
                    Aspect = ASPECT_NONE;
                }
            }
            else
            {
                //choose movement aspect first
                if (!master->GetBotMgr()->IsPartyInCombat())
                {
                    if (!(mask & SPECIFIC_ASPECT_PACK))
                    {
                        uint32 movFlags;
                        if (ASPECT_OF_THE_PACK)
                        {
                            movFlags = master->m_movementInfo.GetMovementFlags();
                            if ((movFlags & MOVEMENTFLAG_FORWARD) && !(movFlags & (MOVEMENTFLAG_FALLING_FAR)))
                            {
                                if (doCast(me, ASPECT_OF_THE_PACK))
                                    return;
                            }
                        }
                        if (ASPECT_OF_THE_CHEETAH && Aspect != ASPECT_CHEETAH)
                        {
                            movFlags = me->m_movementInfo.GetMovementFlags();
                            if ((movFlags & MOVEMENTFLAG_FORWARD) && !(movFlags & (MOVEMENTFLAG_FALLING_FAR)) &&
                                me->GetDistance(master) > 20)
                            {
                                if (doCast(me, ASPECT_OF_THE_CHEETAH))
                                    return;
                            }
                        }
                    }

                    return;
                }
                else if (Aspect == ASPECT_PACK)
                {
                    me->RemoveAurasDueToSpell(ASPECT_OF_THE_PACK_1, me->GetGUID());
                    Aspect = ASPECT_NONE;
                }
            }

            if ((Aspect == ASPECT_DRAGONHAWK && idMap[ASPECT_OF_THE_DRAGONHAWK_1] == ASPECT_OF_THE_DRAGONHAWK) ||
                (!ASPECT_OF_THE_DRAGONHAWK && ((Aspect == ASPECT_HAWK && idMap[ASPECT_OF_THE_HAWK_1] == ASPECT_OF_THE_HAWK) ||
                Aspect == ASPECT_MONKEY)))
                return;

            if (ASPECT_OF_THE_DRAGONHAWK &&
                (Aspect != ASPECT_DRAGONHAWK || idMap[ASPECT_OF_THE_DRAGONHAWK_1] != ASPECT_OF_THE_DRAGONHAWK))
            {
                if (doCast(me, ASPECT_OF_THE_DRAGONHAWK))
                    return;
                return;
            }
            if (ASPECT_OF_THE_HAWK && (!IsTank() || (!ASPECT_OF_THE_MONKEY && !ASPECT_OF_THE_DRAGONHAWK)) &&
                (Aspect != ASPECT_HAWK || idMap[ASPECT_OF_THE_HAWK_1] != ASPECT_OF_THE_HAWK))
            {
                if (doCast(me, ASPECT_OF_THE_HAWK))
                    return;
                return;
            }
            if (ASPECT_OF_THE_MONKEY && Aspect != ASPECT_MONKEY)
            {
                if (doCast(me, ASPECT_OF_THE_MONKEY))
                    return;
                return;
            }
        }

        void Counter(uint32 diff)
        {
            if (IsCasting() || Rand() > 35)
                return;

            Unit* target = nullptr;

            if (IsSpellReady(SCATTER_SHOT_1, diff) && HasRole(BOT_ROLE_DPS))
            {
                target = FindCastingTarget(CalcSpellMaxRange(SCATTER_SHOT_1), 0, SCATTER_SHOT_1);
                if (target && doCast(target, GetSpell(SCATTER_SHOT_1)))
                    return;
            }
            if (!target && IsSpellReady(WYVERN_STING_1, diff) && HasRole(BOT_ROLE_DPS))
            {
                target = FindCastingTarget(CalcSpellMaxRange(WYVERN_STING_1), 5, WYVERN_STING_1);
                if (target && doCast(target, GetSpell(WYVERN_STING_1)))
                    return;
            }
            //if (!target && IsSpellReady(FREEZING_ARROW_1, diff))
            //{
            //    target = FindCastingTarget(40, 0, false, FREEZING_ARROW_1);
            //    if (target && doCast(target, GetSpell(FREEZING_ARROW_1)))
            //        return;
            //}
            //if (!target && IsSpellReady(SCARE_BEAST_1, diff))
            //{
            //    target = FindCastingTarget(30, 0, SCARE_BEAST_1);
            //    if (target && doCast(target, GetSpell(SCARE_BEAST_1)))
            //        return;
            //}
            if (!target && IsSpellReady(SILENCING_SHOT_1, diff, false) && HasRole(BOT_ROLE_DPS))
            {
                target = FindCastingTarget(CalcSpellMaxRange(SILENCING_SHOT_1), 5, SILENCING_SHOT_1);
                if (target && doCast(target, GetSpell(SILENCING_SHOT_1)))
                    return;
            }
        }

        void CheckScatter(uint32 diff)
        {
            if (!IsSpellReady(SCATTER_SHOT_1, diff) || !HasRole(BOT_ROLE_DPS) || Rand() > 50)
                return;

            for (Unit* mtar : { opponent, disttarget })
            {
                if (mtar && mtar->GetVictim() == me && mtar->GetDistance(me) < 10 &&
                    !mtar->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && mtar->getAttackers().size() <= 1)
                {
                    if (doCast(mtar, GetSpell(SCATTER_SHOT_1)))
                    {
                        GetInPosition(true, nullptr);
                        return;
                    }
                }
            }
            if (Unit* target = FindStunTarget(CalcSpellMaxRange(SCATTER_SHOT_1)))
            {
                if (doCast(target, GetSpell(SCATTER_SHOT_1)))
                    return;
            }
        }

        void CheckWyvernSting(uint32 diff)
        {
            if (!IsSpellReady(WYVERN_STING_1, diff) || !HasRole(BOT_ROLE_DPS) || Rand() > 50)
                return;

            if (Unit* target = FindStunTarget(CalcSpellMaxRange(WYVERN_STING_1)))
            {
                if (doCast(target, GetSpell(WYVERN_STING_1)))
                    return;
            }
        }

        void CheckFreezingArrow(uint32 diff)
        {
            //Freezing Trap shares cooldown with frosty traps
            if (!IsSpellReady(FREEZING_ARROW_1, diff) || Rand() > 35)
                return;

            if (Unit* target = FindStunTarget(25))
            {
                if (doCast(target, GetSpell(FREEZING_ARROW_1)))
                    return;
            }
        }

        void CheckTraps(uint32 diff)
        {
            if (trapTimer > diff || IsCasting() || Rand() > 35)
                return;

            trapTimer = urand(1000, 2000);

            //trap summon spell is 2yd radius
            std::list<Unit*> targets;
            GetNearbyTargetsInConeList(targets, 4);
            if (targets.empty())
                return;

            //frost trap, freezing trap, freezing arrow: cat 411
            if (IsSpellReady(FROST_TRAP_1, diff) && !IsTank())
            {
                //uint8 movingCount = 0;
                //for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                //{
                //    if ((*itr)->isMoving() || ((*itr)->GetVictim() && !IsTank((*itr)->GetVictim())))
                //    {
                //        if (++movingCount >= 2)
                        //if (targets.size() > 1)
                //        {
                            if (doCast(me, GetSpell(FROST_TRAP_1)))
                                return;
                //            break;
                //        }
                //    }
                //}
            }
            //only if taming beast (or manual)
            if (IsSpellReady(FREEZING_TRAP_1, diff) && !HasRole(BOT_ROLE_DPS) && !IAmFree() &&
                master->GetAuraEffect(SPELL_AURA_MOD_RESISTANCE_PCT, SPELLFAMILY_GENERIC, 255, 2))
            {
                if (doCast(me, GetSpell(FREEZING_TRAP_1)))
                    return;
            }
            //black arrow, immolation trap, explosive trap: cat 1250
            if (IsSpellReady(EXPLOSIVE_TRAP_1, diff) && HasRole(BOT_ROLE_DPS))
            {
                if (targets.size() > 1)
                {
                    if (doCast(me, GetSpell(EXPLOSIVE_TRAP_1)))
                        return;
                }
            }
            if (IsSpellReady(IMMOLATION_TRAP_1, diff) && HasRole(BOT_ROLE_DPS) && !(*targets.begin())->IsControlledByPlayer())
            {
                if (targets.size() > 1)
                {
                    if (doCast(me, GetSpell(IMMOLATION_TRAP_1)))
                        return;
                }
            }
            //snake trap: cat 1249
            //if (IsSpellReady(SNAKE_TRAP_1, diff) && HasRole(BOT_ROLE_DPS) && (*targets.begin())->IsControlledByPlayer())
            //{
            //    if (doCast(me, GetSpell(SNAKE_TRAP_1)))
            //        return;
            //}
        }

        void CheckMendPet(uint32 diff)
        {
            if (!IsSpellReady(MEND_PET_1, diff) || checkMendTimer > diff || Rand() > 75 ||
                !botPet || !botPet->IsAlive() || GetHealthPCT(botPet) > 80 ||
                me->GetDistance(botPet) > CalcSpellMaxRange(MEND_PET_1, false) || IsCasting())
                return;

            checkMendTimer = urand(2000, 4000);

            Aura const* mend = botPet->GetAura(GetSpell(MEND_PET_1));
            if (!mend || mend->GetDuration() < 3000)
            {
                if (doCast(me, GetSpell(MEND_PET_1)))
                    return;
            }
        }

        void CheckScare(uint32 diff)
        {
            if (!IsSpellReady(SCARE_BEAST_1, diff) || IsCasting() || Rand() > 25)
                return;

            if (FindAffectedTarget(GetSpell(SCARE_BEAST_1), me->GetGUID(), 60))
            {
                SetSpellCooldown(SCARE_BEAST_1, 2000);
                return;
            }

            if (Unit* scareTarget = FindFearTarget())
            {
                if (doCast(scareTarget, GetSpell(SCARE_BEAST_1)))
                    return;
            }

            SetSpellCooldown(SCARE_BEAST_1, 1500); //fail
        }

        void doDefend(uint32 diff)
        {
            if (IsTank() || Rand() > 55)
                return;

            bool feignReady = IsSpellReady(FEIGN_DEATH_1, diff, false);
            bool deterReady = IsSpellReady(DETERRENCE_1, diff, false);
            if (!feignReady && !deterReady)
                return;

            Unit::AttackerSet const& b_attackers = me->getAttackers();
            if (b_attackers.empty())
                return;

            bool cast = false;

            if (b_attackers.size() == 1)
            {
                if (Creature* cre = (*b_attackers.begin())->ToCreature())
                    if (cre->isWorldBoss() || cre->IsDungeonBoss() || cre->GetMaxHealth() > me->GetMaxHealth() * 10)
                        cast = true;
            }
            else
                cast = (uint8(b_attackers.size()) > (GetHealthPCT(me) > 20 ? 1 : 0));

            if (!cast)
                return;

            if (feignReady && (*b_attackers.begin())->getAttackers().size() > 1)
            {
                if (doCast(me, GetSpell(FEIGN_DEATH_1)))
                    return;
            }

            if (deterReady)
            {
                if (doCast(me, GetSpell(DETERRENCE_1)))
                    return;
            }
        }

        void CheckTranquil(uint32 diff)
        {
            if (!IsSpellReady(TRANQ_SHOT_1, diff) || Rand() > 20)
                return;

            //First check current target
            for (Unit* mtar : { opponent, disttarget })
            {
                if (mtar && me->GetDistance(mtar) > 5 && me->GetDistance(mtar) < CalcSpellMaxRange(TRANQ_SHOT_1) &&
                    !mtar->IsImmunedToSpell(sSpellMgr->GetSpellInfo(TRANQ_SHOT_1), me))
                {
                    AuraApplication const* aurApp;
                    SpellInfo const* spellInfo;
                    Unit::AuraMap const& auras = mtar->GetOwnedAuras();
                    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                    {
                        spellInfo = itr->second->GetSpellInfo();
                        if (spellInfo->Dispel != DISPEL_MAGIC && spellInfo->Dispel != DISPEL_ENRAGE) continue;
                        if (spellInfo->Attributes & (SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) continue;
                        //if (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR) continue;
                        aurApp = itr->second->GetApplicationOfTarget(mtar->GetGUID());
                        if (aurApp && aurApp->IsPositive())
                        {
                            if (doCast(mtar, GetSpell(TRANQ_SHOT_1)))
                                return;
                        }
                    }
                }
            }

            Unit* target = FindTranquilTarget(5, CalcSpellMaxRange(TRANQ_SHOT_1));
            if (target && doCast(target, GetSpell(TRANQ_SHOT_1)))
                return;
        }

        void CheckMisdirect(uint32 diff)
        {
            if (!IsSpellReady(MISDIRECTION_1, diff) || misdirectionTimer > diff || IAmFree() ||
                !master->GetGroup() || Rand() > 20)
                return;

            misdirectionTimer = urand(3000, 6000);

            //find tank
            //stacks
            std::list<Unit*> tanks;
            for (Unit* member : BotMgr::GetAllGroupMembers(master))
            {
                if (member->IsInWorld() && me->GetMap() == member->FindMap() && member->IsAlive() &&
                    member->GetVictim() && member->IsInCombat() && IsTank(member))
                {
                    tanks.push_back(member);
                }
            }

            if (tanks.empty())
                return;

            Unit* target = tanks.size() == 1 ? *tanks.begin() : Trinity::Containers::SelectRandomContainerElement(tanks);
            if (doCast(target, GetSpell(MISDIRECTION_1)))
                return;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            //pet is killed or unreachable
            if (GC_Timer <= diff && !me->IsInCombat() && !me->IsMounted() && !me->GetVictim() && !IsCasting() && Rand() < 25 &&
                (!botPet || me->GetDistance2d(botPet) > sWorld->GetMaxVisibleDistanceOnContinents()))
                SummonBotPet();

            //Scare Beast interrupt
            Spell const* spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL);
            if (spell && spell->GetSpellInfo()->Id == GetSpell(SCARE_BEAST_1))
            {
                Unit const* target = ObjectAccessor::GetUnit(*me, spell->m_targets.GetObjectTargetGUID());
                if (target && target->HasAuraType(SPELL_AURA_MOD_FEAR))
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
            }

            if (IsPotionReady())
            {
                if (GetManaPCT(me) < 10)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            CheckRacials(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);
            else
                doDefend(diff);

            CheckAspects(diff);

            if (IsSpellReady(TRUESHOT_AURA_1, diff) && !IAmFree() && Rand() < 5 &&
                !me->GetAuraEffect(SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT, SPELLFAMILY_HUNTER, 0x0, 0x200000, 0x0, me->GetGUID()))
            {
                if (doCast(me, GetSpell(TRUESHOT_AURA_1)))
                    return;
            }

            CheckMendPet(diff);

            if (master->IsInCombat() || me->IsInCombat())
                CheckScare(diff);

            //Deterrence check
            if (me->HasUnitFlag(UNIT_FLAG_PACIFIED) && !IsCasting())
            {
                if (!me->isMoving())
                    GetInPosition(true, nullptr);
                return;
            }

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                return;
            }

            if (IsCasting())
                return;

            CheckFlare(diff);
            CheckReadiness(diff);

            CheckUsableItems(diff);

            DoRangedAttack(diff);
        }

        void DoRangedAttack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, IsMelee());

            CheckAttackState();
            if (!me->IsAlive() || !mytar->IsAlive())
                return;

            Counter(diff);
            CheckTranquil(diff);

            float dist = me->GetDistance(mytar);
            float maxRangeLong = me->GetLevel() >= 10 ? 51.f : 45.f;
            float maxRangeNormal = me->GetLevel() >= 10 ? 41.f : 35.f;

            bool inposition = !mytar->HasAuraType(SPELL_AURA_MOD_CONFUSE) || dist > maxRangeNormal - 15.f;

            //Auto Shot
            if (Spell const* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            {
                if (shot->GetSpellInfo()->Id == AUTO_SHOT_1 && (shot->m_targets.GetUnitTarget() != mytar || !inposition))
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }
            else if (HasRole(BOT_ROLE_DPS) && dist > 5 && dist < maxRangeNormal)
            {
                if (doCast(mytar, AUTO_SHOT_1))
                {}
            }

            CheckScatter(diff);
            CheckFreezingArrow(diff);
            CheckWyvernSting(diff);

            //TRAPS
            CheckTraps(diff);

            auto [can_do_nature, can_do_fire, can_do_arcane, can_do_shadow, can_do_normal] =
                CanAffectVictimBools(mytar, SPELL_SCHOOL_NATURE, SPELL_SCHOOL_FIRE, SPELL_SCHOOL_ARCANE, SPELL_SCHOOL_SHADOW, SPELL_SCHOOL_NORMAL);

            //scatter pvp
            if (IsSpellReady(SCATTER_SHOT_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) &&
                mytar->GetTypeId() == TYPEID_PLAYER && dist < 10 && Rand() < 60)
            {
                if (doCast(mytar, GetSpell(SCATTER_SHOT_1)))
                {
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                    me->AttackStop();
                    GetInPosition(true, mytar);
                    return;
                }
            }

            //DISENGAGE
            if (IsSpellReady(DISENGAGE_1, diff, false) && me->IsInCombat() && !IsTank() && Rand() < 70 &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                !me->getAttackers().empty() && me->GetDistance(*me->getAttackers().begin()) < 5 &&
                me->HasInArc(float(M_PI), *me->getAttackers().begin()))
            {
                if (doCast(me, GetSpell(DISENGAGE_1)))
                    return;
            }

            MoveBehind(mytar);

            //MELEE SECTION
            if (dist < 5)
            {
                if (!can_do_normal)
                    return;

                //MONGOOSE BITE
                if (IsSpellReady(MONGOOSE_BITE_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 50)
                {
                    if (doCast(mytar, GetSpell(MONGOOSE_BITE_1)))
                        return;
                }
                //COUNTERATTACK
                if (IsSpellReady(COUNTERATTACK_1, diff) && HasRole(BOT_ROLE_DPS) &&
                    me->HasReactive(REACTIVE_HUNTER_PARRY) && Rand() < 90)
                {
                    if (doCast(mytar, GetSpell(COUNTERATTACK_1)))
                        return;
                }
                //WING CLIP
                if (IsSpellReady(WING_CLIP_1, diff) && (!IsTank() || mytar->isMoving()) &&
                    Rand() < 80 && !CCed(mytar, true) && !mytar->HasAuraWithMechanic(1<<MECHANIC_SNARE))
                {
                    if (doCast(mytar, GetSpell(WING_CLIP_1)))
                        return;
                }
                //RAPTOR STRIKE
                if (IsSpellReady(RAPTOR_STRIKE_1, diff, false) && HasRole(BOT_ROLE_DPS) && Rand() < 40 &&
                    !me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                {
                    if (doCast(mytar, GetSpell(RAPTOR_STRIKE_1)))
                        return;
                }

                return; //don't try to do anything else in melee
            }

            //RANGED SECTION

            //HUNTERS MARK //100 yd range so don't check it
            if (IsSpellReady(HUNTERS_MARK_1, diff) && can_do_arcane && Rand() < 65 &&
                !mytar->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_STALKED, SPELLFAMILY_HUNTER, 0x400))
            {
                if (doCast(mytar, GetSpell(HUNTERS_MARK_1)))
                    return;
            }

            CheckMisdirect(diff);

            //attack range check 1
            if (dist > maxRangeLong)
                return;

            //KILL SHOT
            if (IsSpellReady(KILL_SHOT_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS) &&
                mytar->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))
            {
                if (doCast(mytar, GetSpell(KILL_SHOT_1)))
                    return;
            }

            //attack range check 2
            if (dist > maxRangeNormal)
                return;

            if (!inposition && me->getAttackers().empty())
                return;

            //CONCUSSIVE SHOT
            if (IsSpellReady(CONCUSSIVE_SHOT_1, diff) && can_do_arcane && Rand() < 35 &&
                !CCed(mytar, true) && !mytar->HasAuraWithMechanic(1<<MECHANIC_SNARE))
            {
                if (doCast(mytar, GetSpell(CONCUSSIVE_SHOT_1)))
                    return;
            }
            //DISTRACTING SHOT
            Unit const* u = mytar->GetVictim();
            if (IsSpellReady(DISTRACTING_SHOT_1, diff) && can_do_arcane && u && u != me && IsTank() && !CCed(mytar) &&
                IsInBotParty(u) && Rand() < 75 && (!IsTank(u) || (dist > 25 && GetHealthPCT(u) < 25)))
            {
                if (doCast(mytar, GetSpell(DISTRACTING_SHOT_1)))
                    return;
            }
            //MULTI-SHOT shares cd with aimed shot
            if (IsSpellReady(MULTISHOT_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 70)
            {
                if (Rand() < 30 || !GetSpell(STEADY_SHOT_1) || FindSplashTarget(maxRangeNormal))
                {
                    if (doCast(mytar, GetSpell(MULTISHOT_1)))
                        return;
                }
            }
            //VOLLEY
            if (IsSpellReady(VOLLEY_1, diff) && HasRole(BOT_ROLE_DPS) && !JumpingOrFalling() && Rand() < 75)
            {
                if (Unit* target = FindAOETarget(maxRangeNormal))
                {
                    if (doCast(target, GetSpell(VOLLEY_1)))
                        return;
                }
            }
            //RAPID FIRE
            if (IsSpellReady(RAPID_FIRE_1, diff, false) && can_do_normal && HasRole(BOT_ROLE_DPS) && !me->isMoving() && Rand() < 55 &&
                (mytar->GetHealth() > me->GetMaxHealth() * (1 + mytar->getAttackers().size()) ||
                mytar->GetTypeId() == TYPEID_PLAYER) &&
                !me->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_RANGED_HASTE, SPELLFAMILY_HUNTER, 0x20))
            {
                if (doCast(me, GetSpell(RAPID_FIRE_1)))
                {}
            }
            //BLACK ARROW
            //Black Arrow shares cooldown with fire traps
            if (IsSpellReady(BLACK_ARROW_1, diff) && can_do_shadow && HasRole(BOT_ROLE_DPS) &&
                mytar->GetHealth() > me->GetMaxHealth()/4 * (1 + mytar->getAttackers().size()))
            {
                if (doCast(mytar, GetSpell(BLACK_ARROW_1)))
                    return;
            }
            //CHIMERA SHOT: no viper
            if (IsSpellReady(CHIMERA_SHOT_1, diff) && can_do_nature && HasRole(BOT_ROLE_DPS))
            {
                //Serpent
                if (mytar->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, SPELLFAMILY_HUNTER, 0x4000, 0x0, 0x0, me->GetGUID()))
                {
                    if (doCast(mytar, GetSpell(CHIMERA_SHOT_1)))
                        return;
                }
                //Scorpid
                else if (mytar->GetAuraEffect(SPELL_AURA_MOD_HIT_CHANCE, SPELLFAMILY_HUNTER, 0x8000, 0x0, 0x0, me->GetGUID()))
                {
                    if (!mytar->HasAuraType(SPELL_AURA_MOD_DISARM) &&
                        (mytar->GetTypeId() == TYPEID_PLAYER || mytar->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID)))
                    {
                        if (doCast(mytar, GetSpell(CHIMERA_SHOT_1)))
                            return;
                    }
                }

                SetSpellCooldown(CHIMERA_SHOT_1, 500); //fail
            }
            //STING
            if (GetSpellCooldown(SERPENT_STING_1) <= diff && can_do_nature && stingTimer <= diff && Rand() < 60)
            {
                uint32 STING = 0;
                AuraEffect const* sting = nullptr;
                if (!STING && GetSpell(SCORPID_STING_1) && mytar->GetTypeId() == TYPEID_UNIT &&
                    mytar->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)
                {
                    sting = mytar->GetAuraEffect(SPELL_AURA_MOD_HIT_CHANCE, SPELLFAMILY_HUNTER, 0x8000, 0x0, 0x0);
                    if (!sting || sting->GetBase()->GetCasterGUID() == me->GetGUID())
                        STING = SCORPID_STING_1;
                }
                //VIPER STING: pvp only
                if (!STING && GetSpell(VIPER_STING_1) && mytar->GetTypeId() == TYPEID_PLAYER &&
                    mytar->GetPowerType() == POWER_MANA && mytar->GetHealth() > me->GetMaxHealth()/2 &&
                    mytar->GetMaxPower(POWER_MANA) > me->GetMaxPower(POWER_MANA))
                {
                    sting = mytar->GetAuraEffect(SPELL_AURA_PERIODIC_MANA_LEECH, SPELLFAMILY_HUNTER, 0x0, 0x80, 0x0, me->GetGUID());
                    if (!sting)
                        STING = VIPER_STING_1;
                }
                if (!STING && GetSpell(SERPENT_STING_1) && HasRole(BOT_ROLE_DPS) &&
                    mytar->GetHealth() > me->GetMaxHealth()/2 * (1 + mytar->getAttackers().size()))
                {
                    sting = mytar->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, SPELLFAMILY_HUNTER, 0x4000, 0x0, 0x0, me->GetGUID());
                    if (!sting)
                        STING = SERPENT_STING_1;
                }

                if (sting && sting->GetBase()->GetCasterGUID() == me->GetGUID() &&
                    sting->GetBase()->GetDuration() >= 3000)
                {
                    stingTimer = 3000;
                }
                else
                {
                    if (STING && doCast(mytar, GetSpell(STING)))
                    {
                        stingTimer = 8000;
                        return;
                    }
                }
            }
            //EXPLOSIVE SHOT: replaces Arcane Shot at 60
            if (IsSpellReady(EXPLOSIVE_SHOT_1, diff) && can_do_fire && HasRole(BOT_ROLE_DPS))
            {
                if (doCast(mytar, GetSpell(EXPLOSIVE_SHOT_1)))
                    return;
            }
            //ARCANE SHOT: shares cd with Explosive Shot
            if (IsSpellReady(ARCANE_SHOT_1, diff) && can_do_arcane && HasRole(BOT_ROLE_DPS) && !GetSpell(EXPLOSIVE_SHOT_1))
            {
                if (doCast(mytar, GetSpell(ARCANE_SHOT_1)))
                    return;
            }
            //AIMED SHOT shares cd with multishot
            if (IsSpellReady(AIMED_SHOT_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS))
            {
                if (doCast(mytar, GetSpell(AIMED_SHOT_1)))
                    return;
            }
            //STEADY SHOT
            if (IsSpellReady(STEADY_SHOT_1, diff) && can_do_normal && HasRole(BOT_ROLE_DPS))
            {
                if (doCast(mytar, GetSpell(STEADY_SHOT_1)))
                    return;
            }
        }

        void CheckFlare(uint32 diff)
        {
            if (!IsSpellReady(FLARE_1, diff) || flareTimer > diff || me->IsMounted() || Rand() > 25)
                return;

            flareTimer = urand(2000, 4000);

            std::set<Unit*> targets;
            if (Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup())
            {
                for (Unit* member : BotMgr::GetAllGroupMembers(gr))
                {
                    if (me->GetMap() != member->FindMap() || !member->IsAlive())
                        continue;
                    for (Unit* attacker : member->getAttackers())
                    {
                        if (attacker->GetClass() == CLASS_ROGUE || attacker->HasInvisibilityAura() || attacker->HasStealthAura())
                        {
                            if (member->GetDistance(attacker) < 15)
                            {
                                targets.insert(member);
                                break;
                            }
                        }
                    }
                }
            }
            for (Unit* attacker : me->getAttackers())
            {
                if (attacker->GetClass() == CLASS_ROGUE || attacker->HasInvisibilityAura() || attacker->HasStealthAura())
                {
                    if (me->GetDistance(attacker) < 15)
                    {
                        targets.insert(me);
                        break;
                    }
                }
            }

            if (targets.empty())
                return;

            Unit* target = targets.size() == 1u ? *targets.begin() : Trinity::Containers::SelectRandomContainerElement(targets);
            if (doCast(target, GetSpell(FLARE_1)))
                return;
        }

        void CheckReadiness(uint32 diff)
        {
            if (!IsSpellReady(READINESS_1, diff) || !me->IsInCombat() || me->IsMounted() || Rand() > 30)
                return;

            //mainly used for rapid fire cd reset
            bool cast = me->GetVictim() && !IsSpellReady(RAPID_FIRE_1, diff, false);

            if (cast && doCast(me, GetSpell(READINESS_1)))
                return;
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Glyph of Explosive Shot: 4% additional critical chance for Explosive Shot
            if (lvl >= 60 && (baseId == EXPLOSIVE_SHOT_1 || baseId == EXPLOSIVE_SHOT_PERIODIC_DUMMY_AURA))
                crit_chance += 4.f;
            //Point of No Escape: 6% additional critical chance on targets affected by frosty traps
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 50)
            {
                if (victim->GetAuraEffect(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER, SPELLFAMILY_HUNTER, 0x18, 0x0, 0x0, me->GetGUID()))
                    crit_chance += 6.f;
            }
            //Sniper Training (part 1): 15% additional critical chance for Kill Shot
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 50 && baseId == KILL_SHOT_1)
                crit_chance += 15.f;
            //Improved Steady Shot (37505): 5% additional critical chance for Steady Shot
            if (lvl >= 50 && baseId == STEADY_SHOT_1)
                crit_chance += 5.f;
            //Glyph of TrueShot Aura (req lvl 40): 10% additional critical chance for Aimed Shot
            if (lvl >= 40 && baseId == AIMED_SHOT_1)
                crit_chance += 10.f;
            //Improved Barrage: 12% additional critical chance for Multi-Shot and Aimed Shot
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 40 && (baseId == AIMED_SHOT_1 || baseId == MULTISHOT_1))
                crit_chance += 12.f;
            //Survival Instincts: 4% additional critical chance for Arcane Shot, Steady Shot and Explosive Shot
            if (lvl >= 15 && (baseId == ARCANE_SHOT_1 || baseId == STEADY_SHOT_1 || baseId == EXPLOSIVE_SHOT_1 ||
                baseId == EXPLOSIVE_SHOT_PERIODIC_DUMMY_AURA))
                crit_chance += 4.f;
            //Savage Strikes: 20% additional critical chance for Raptor Strike, Mongoose Bite and Counterattack
            if (lvl >= 10 && (baseId == RAPTOR_STRIKE_1 || baseId == MONGOOSE_BITE_1 || baseId == COUNTERATTACK_1))
                crit_chance += 20.f;
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            ////do nothing with autoshot
            //if (baseId == AUTO_SHOT_1)
            //    return;

            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Mortal Shots: 30% crit damage bonus for all ranged abilities
                if (lvl >= 15 && baseId != AUTO_SHOT_1)
                    pctbonus += 0.15f;
                //Marked for Death (part 2): 10% crit damage bonus for Aimed Shot, Arcane Shot, Steady Shot, Kill Shot and Chimera Shot
                if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 55 &&
                    (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == STEADY_SHOT_1 ||
                    baseId == KILL_SHOT_1 || baseId == CHIMERA_SHOT_1))
                    pctbonus += 0.05f;
            }

            //Improved Tracking: 5% bonus damage versus tracked types (all for bots)
            if (lvl >= 10)
                pctbonus += 0.05f;
            //Focused Fire: 2% bonus damage while pet is active
            if (lvl >= 15 && botPet)
                pctbonus += 0.02f;
            //Ranged Weapon Specialization: 5% bonus damage for ranged attacks
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 35)
                pctbonus += 0.05f;
            //Improved Arcane Shot: 15% bonus damage for Arcane Shot
            if (lvl >= 20 && baseId == ARCANE_SHOT_1)
                pctbonus += 0.15f;
            //Rapid Killing (buff): 20% bonus damage for Aimed Shot, Arcane Shot or Chimera Shot (removed in SpellHitTarget())
            if (lvl >= 20 && (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == CHIMERA_SHOT_1))
            {
                if (AuraEffect const* rapi = me->GetAuraEffect(RAPID_KILLING_BUFF, 0))
                    if (rapi->IsAffectingSpell(spellInfo))
                        pctbonus += 0.2f;
            }
            //Barrage: 12% bonus damage for Aimed Shot, Multi-Shot or Volley
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 30 && (spellInfo->SpellFamilyFlags[0] & 0x23000))
                pctbonus += 0.12f;
            //Marked for Death (part 1): 5% bonus damage for all ranged shots on marked target
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 55 && damageinfo.target &&
                damageinfo.target->GetAuraEffect(SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS, SPELLFAMILY_HUNTER, 0x400, 0x0, 0x0/*, me->GetGUID()*/))
                pctbonus += 0.05f;
            //T.N.T: 6% bonus damage for Explosive Shot, Explosive Trap, Immolation Trap and Black Arrow
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 25 &&
                (baseId == EXPLOSIVE_SHOT_1 || baseId == EXPLOSIVE_SHOT_PERIODIC_DUMMY_AURA ||
                baseId == EXPLOSIVE_TRAP_AURA_1 || baseId == IMMOLATION_TRAP_AURA_1 || baseId == BLACK_ARROW_1))
                pctbonus += 0.06f;
            //Ferocious Inspiration part 2: 9% bonus damage for Arcane Shot and Steady Shot
            if ((GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY) &&
                lvl >= 40 && (baseId == ARCANE_SHOT_1 || baseId == STEADY_SHOT_1))
                pctbonus += 0.09f;
            //Improved Steady Shot (38392): 10% bonus damage for Steady Shot
            if (lvl >= 50 && baseId == STEADY_SHOT_1)
                pctbonus += 0.1f;
            //Glyph of Steady Shot: 10% bonus damage for Steady Shot if affected by Serpent Sting
            if (lvl >= 62 && baseId == STEADY_SHOT_1 && damageinfo.target &&
                damageinfo.target->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, SPELLFAMILY_HUNTER, 0x4000, 0x0, 0x0/*, me->GetGUID()*/))
                pctbonus += 0.1f;
            //The Beast Within part 1: 10% bonus damage for all abilities
            if ((GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY) && lvl >= 50)
                pctbonus += 0.1f;
            //Sniper Training part 2: 6% bonus damage for Steady Shot, Aimed Shot, Black Arrow and Explosive Shot
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 50 &&
                ((spellInfo->SpellFamilyFlags[0] & 0x20000) ||
                (spellInfo->SpellFamilyFlags[1] & 0x8000001) ||
                (spellInfo->SpellFamilyFlags[2] & 0x200)))
            {
                if (Aura const* snip = me->GetAura(SNIPER_TRAINING_BUFF))
                {
                    if (snip->GetEffect(0)->IsAffectingSpell(spellInfo) ||
                        snip->GetEffect(1)->IsAffectingSpell(spellInfo))
                        pctbonus += 0.06f;
                }
            }
            //Improved Steady Shot part 1: 15% bonus damage for Steady Shot, Aimed Shot, Arcane Arrow and Chimera Shot
            if (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == CHIMERA_SHOT_1)
            {
                if (AuraEffect const* stea = me->GetAuraEffect(IMPROVED_STEADY_SHOT_BUFF, 0))
                    if (stea->IsAffectingSpell(spellInfo))
                        pctbonus += 0.15f;
            }

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool /*iscrit*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);
            float flat_mod = 0.f;

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            //if (iscrit)
            //{
            //    //!!!spell damage is not yet critical and will be multiplied by 1.5
            //    //so we should put here bonus damage mult /1.5
            //    //Lava Flows (part 1): 24% additional crit damage bonus for Lava Burst
            //    if (lvl >= 50 && spellId == GetSpell(LAVA_BURST_1))
            //        pctbonus += 0.16f;
            //}
            //Trap Mastery part 2: 30% bonus damage for Immolation Trap, Explosive Trap and Black Arrow
            if (lvl >= 15 && (baseId == IMMOLATION_TRAP_AURA_1 || baseId == EXPLOSIVE_TRAP_AURA_1 || baseId == BLACK_ARROW_1))
                pctbonus += 0.3f;
            //T.N.T: 6% bonus damage for Explosive Shot, Explosive Trap, Immolation Trap and Black Arrow
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 25 &&
                (baseId == EXPLOSIVE_SHOT_1 || baseId == EXPLOSIVE_SHOT_PERIODIC_DUMMY_AURA ||
                baseId == EXPLOSIVE_TRAP_AURA_1 || baseId == IMMOLATION_TRAP_AURA_1 || baseId == BLACK_ARROW_1))
                pctbonus += 0.06f;
            //The Beast Within part 1: 10% bonus damage for all abilities
            if ((GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY) && lvl >= 50)
                pctbonus += 0.1f;

            damage = int32(fdamage * (1.0f + pctbonus) + flat_mod);
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
            //100% mods
            //Improved Hunter's Mark: -100% mana cost for Hunter's Mark
            if (lvl >= 15 && baseId == HUNTERS_MARK_1)
                pctbonus += 1.0f;
            //Lock and Load: mana cost
            if (baseId == ARCANE_SHOT_1 || baseId == EXPLOSIVE_SHOT_1)
            {
                AuraEffect const* lock = me->GetAuraEffect(LOCK_AND_LOAD_BUFF, 0);
                if (lock && lock->IsAffectingSpell(spellInfo))
                    pctbonus += 1.0f;
            }

            //Improved Mend Pet: -20% mana cost for Mend Pet
            //Improved Mend Pet (23560) part 3
            if (lvl >= 25 && baseId == MEND_PET_1)
                pctbonus += 0.5f;
            //Efficiency: -15% mana cost for Stings and Shots
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 25 &&
                ((spellInfo->SpellFamilyFlags[0] & 0x7FA00) ||
                (spellInfo->SpellFamilyFlags[1] & 0x88801081) ||
                (spellInfo->SpellFamilyFlags[2] & 0x1)))
                pctbonus += 0.15f;
            //Resourcefulness: -60% mana cost for Traps, melee spells and Black Arrow
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 35 &&
                ((spellInfo->SpellFamilyFlags[0] & 0xDE) ||
                (spellInfo->SpellFamilyFlags[1] & 0x84000)))
                pctbonus += 0.6f;
            //Glyph of Volley: -20% mana cost for Volley
            if (lvl >= 40 && baseId == VOLLEY_1)
                pctbonus += 0.2f;
            //Master Marksman: -25% mana cost for Steady Shot, Aimed Shot and Chimera Shot
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) &&
                lvl >= 45 && (baseId == STEADY_SHOT_1 || baseId == AIMED_SHOT_1 || baseId == CHIMERA_SHOT_1))
                pctbonus += 0.25f;
            //Improved Steady Shot part 2: -20% mana cost for Steady Shot, Aimed Shot, Arcane Arrow and Chimera Shot
            if (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == CHIMERA_SHOT_1)
            {
                if (AuraEffect const* stea = me->GetAuraEffect(IMPROVED_STEADY_SHOT_BUFF, 1))
                    if (stea->IsAffectingSpell(spellInfo))
                        pctbonus += 0.2f;
            }

            //flat mods
            //!1 rage = 10 pts!
            //Improved Heroic Strike: -3 rage cost for Heroic Strike
            //if (lvl >= 10 && baseId == HEROIC_STRIKE_1)
            //    flatbonus += 30;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
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
            //Glyph of Rapid Charge: -7% cooldown for Charge
            //if (lvl >= 40 && spellId == GetSpell(CHARGE_1))
            //    pctbonus += 0.07f;

            //flat mods
            //Survival Tactics: -4 sec cooldown for Disengage
            //Glyph of Disengage: -5 sec cooldown for Disengage
            if (lvl >= 20 && baseId == DISENGAGE_1)
                timebonus += (GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) ? 9000 : 5000;
            //Glyph of Feign Death: -5 sec cooldown for Feign Death
            //Improved Feign Death (24432): -2 sec cooldown for Feign Death
            if (lvl >= 30 && baseId == FEIGN_DEATH_1)
                timebonus += 7000;
            //Tranquilizing Shot Cooldown reduction (61255): -2 sec cooldown for Tranquilizing Shot
            if (lvl >= 60 && baseId == TRANQ_SHOT_1)
                timebonus += 2000;
            //Glyph of Deterrence: -10 sec cooldown for Deterrence
            if (lvl >= 60 && baseId == DETERRENCE_1)
                timebonus += 10000;
            //Glyph of Chimera Shot: -1 sec cooldown for Chimera Shot
            if (lvl >= 60 && baseId == CHIMERA_SHOT_1)
                timebonus += 1000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //Lock and Load: cooldown
            if (baseId == ARCANE_SHOT_1 || baseId == EXPLOSIVE_SHOT_1)
            {
                AuraEffect const* lock = me->GetAuraEffect(LOCK_AND_LOAD_BUFF, 0);
                if (lock && lock->IsAffectingSpell(spellInfo))
                    pctbonus += 1.0f;
            }

            //Rapid Killing part 1: -2 min cooldown for Rapid Fire
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && baseId == RAPID_FIRE_1)
                timebonus += 120000;
            //Glyph of Aimed Shot: -2 sec cooldown for Aimed Shot
            if (baseId == AIMED_SHOT_1)
                timebonus += 2000;
            //Glyph of Multi-Shot: -1 sec cooldown for Multi-Shot
            //Improved Multi-Shot (44292): -1 sec cooldown for Multi-Shot
            if (baseId == MULTISHOT_1)
                timebonus += 2000;
            //Trap Cooldown (37481): -4 sec cd for Traps
            //Trap Cooldown Reduction: -2 sec cd for Traps
            if (spellInfo->SpellFamilyFlags[0] & 0x80)
                timebonus += 6000;
            //Resourcefulness: -6 sec cd for Traps and Black Arrow
            if ((GetSpec() == BOT_SPEC_HUNTER_SURVIVAL) && lvl >= 35 && (spellInfo->SpellFamilyFlags[0] & 0x80))
                timebonus += 6000;
            //Catlike Reflexes part 3: -30 sec cd for Kill Command
            if ((GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY) && lvl >= 40 && (spellInfo->SpellFamilyFlags[1] & 0x800))
                timebonus += 30000;
            //Glyph of Kill Shot: -6 sec cooldown for Kill Shot
            if (lvl >= 40 && baseId == KILL_SHOT_1)
                timebonus += 6000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            ////Holy Reach
            //if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x18400200) || (spellInfo->SpellFamilyFlags[2] & 0x4)))
            //    pctbonus += 0.2f;

            //flat mods
            //Glyph of Frost Trap
            if (baseId == FROST_TRAP_AURA)
                flatbonus += 2.f;
            //Glyph of the Pack
            if (baseId == ASPECT_OF_THE_PACK_1)
                flatbonus += 15.f;

            radius = radius * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Improved Mend Pet (23560) part 1
            if (lvl >= 25 && baseId == MEND_PET_1)
                pctbonus += 0.5f;

            //flat mods
            //Hawk Eye: +6 yd range for Ranged Abilities
            if (lvl >= 10 &&
                ((spellInfo->SpellFamilyFlags[0] & 0x7FA01) ||
                (spellInfo->SpellFamilyFlags[1] & 0x88801081) ||
                (spellInfo->SpellFamilyFlags[2] & 0x401)))
                flatbonus += 6.f;
            //Glyph of Scatter Shot
            if (lvl >= 20 && baseId == SCATTER_SHOT_1)
                flatbonus += 3.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellChanceOfSuccessMods(SpellInfo const* spellInfo, float& chance) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();

            //Improved Aspect of the Hawk: 10% chance
            if (lvl >= 10 && (baseId == ASPECT_OF_THE_HAWK_1 || baseId == ASPECT_OF_THE_DRAGONHAWK_1))
                chance += 10.f;
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            float pctbonus = 1.0f;

            //Improved Mend Pet (23560) part 2
            if (baseId == MEND_PET_1 && effIndex == EFFECT_0)
                pctbonus *= 1.1f;

            value = value * pctbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            //Rapid Killing: use up buff manually
            if (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == CHIMERA_SHOT_1)
            {
                if (AuraEffect const* rapi = me->GetAuraEffect(RAPID_KILLING_BUFF, 0))
                    if (rapi->IsAffectingSpell(spellInfo))
                        me->RemoveAura(RAPID_KILLING_BUFF);
            }
            //Glyph of Arcane Shot
            if (baseId == ARCANE_SHOT_1)
            {
                Unit const* victim = me->GetVictim();
                if (victim &&
                    (victim->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, SPELLFAMILY_HUNTER, 0x4000, 0x0, 0x0, me->GetGUID()) ||
                    victim->GetAuraEffect(SPELL_AURA_PERIODIC_MANA_LEECH, SPELLFAMILY_HUNTER, 0x0, 0x80, 0x0, me->GetGUID()) ||
                    victim->GetAuraEffect(SPELL_AURA_MOD_HIT_CHANCE, SPELLFAMILY_HUNTER, 0x8000, 0x0, 0x0, me->GetGUID()) ||
                    victim->GetAuraEffect(SPELL_AURA_MOD_STUN, SPELLFAMILY_HUNTER, 0x0, 0x1000, 0x0, me->GetGUID()) ||
                    victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_HUNTER, 0x0, 0x100, 0x0, me->GetGUID())))
                {
                    int32 cost = spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask());
                    CastSpellExtraArgs args(true);
                    args.AddSpellBP0(cost);
                    me->CastSpell(me, GLYPH_OF_ARCANE_SHOT_ENERGIZE, args);
                }
            }
            //Lock and Load: consume charge
            if (baseId == ARCANE_SHOT_1 || baseId == EXPLOSIVE_SHOT_1)
            {
                AuraEffect const* lock = me->GetAuraEffect(LOCK_AND_LOAD_BUFF, 0);
                if (lock && lock->IsAffectingSpell(spellInfo))
                    lock->GetBase()->DropCharge();
            }
            if (baseId == READINESS_1)
            {
                SpellInfo const* cdInfo;
                BotSpellMap const& myspells = GetSpellMap();
                for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
                {
                    if (itr->first == spellInfo->Id || itr->first == BESTIAL_WRATH_1 || itr->first == GIFT_OF_NAARU_HUNTER)
                        continue;
                    if (itr->second->spellId != 0 && itr->second->cooldown > 0)
                    {
                        cdInfo = sSpellMgr->GetSpellInfo(itr->first);
                        if (cdInfo && cdInfo->SpellFamilyName == SPELLFAMILY_HUNTER && cdInfo->GetRecoveryTime() > 0)
                            ResetSpellCooldown(itr->first);
                    }
                }
            }
            //Improved Steady Shot: consume buff
            if (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == CHIMERA_SHOT_1)
            {
                if (AuraEffect const* stea = me->GetAuraEffect(IMPROVED_STEADY_SHOT_BUFF, 0))
                    if (stea->IsAffectingSpell(spellInfo))
                        me->RemoveAurasDueToSpell(IMPROVED_STEADY_SHOT_BUFF);
            }

            //Aspect helper
            switch (baseId)
            {
                case ASPECT_OF_THE_MONKEY_1:
                    Aspect = ASPECT_MONKEY;
                    break;
                case ASPECT_OF_THE_HAWK_1:
                    Aspect = ASPECT_HAWK;
                    break;
                case ASPECT_OF_THE_CHEETAH_1:
                    Aspect = ASPECT_CHEETAH;
                    break;
                case ASPECT_OF_THE_VIPER_1:
                    Aspect = ASPECT_VIPER;
                    break;
                case ASPECT_OF_THE_BEAST_1:
                    Aspect = ASPECT_BEAST;
                    break;
                case ASPECT_OF_THE_PACK_1:
                    Aspect = ASPECT_PACK;
                    break;
                case ASPECT_OF_THE_WILD_1:
                    Aspect = ASPECT_WILD;
                    break;
                case ASPECT_OF_THE_DRAGONHAWK_1:
                    Aspect = ASPECT_DRAGONHAWK;
                    break;
                default:
                    break;
            }
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            if (target == me)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            if (baseId == HUNTERS_MARK_1)
            {
                //Hunter's Mark helper
                if (AuraEffect* mark = target->GetAuraEffect(spell->Id, 1, me->GetGUID()))
                {
                    //Glyph of Hunter's Mark: +20% effect
                    //Improved Hunter's Mark: +30% effect
                    if (lvl >= 15)
                        mark->ChangeAmount(mark->GetAmount() + mark->GetAmount() / 2);
                    else if (lvl >= 10)
                        mark->ChangeAmount(mark->GetAmount() * 13 / 10);
                }
            }
            //Improved Stings part 1: +30% damage
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 25 && (baseId == SERPENT_STING_1 || baseId == WYVERN_STING_DOT_AURA_1))
            {
                if (AuraEffect* stin = target->GetAuraEffect(spell->Id, 0, me->GetGUID()))
                {
                    stin->ChangeAmount(stin->GetAmount() * 13 / 10);
                }
            }
            //Improved Stings part 2: +30% effect: not working?
            //Trap Mastery part 1
            if (lvl >= 15 && (baseId == FROST_TRAP_AURA || baseId == FREEZING_TRAP_AURA_1))
            {
                if (Aura* freez = target->GetAura(spell->Id, me->GetGUID()))
                {
                    int32 dur = freez->GetDuration() * 13 / 10;
                    freez->SetDuration(dur);
                    freez->SetMaxDuration(dur);
                }
            }
            if (lvl >= 16 && baseId == IMMOLATION_TRAP_AURA_1)
            {
                if (AuraEffect* immo = target->GetAuraEffect(spell->Id, 0, me->GetGUID()))
                {
                    //Glyph of Immolation Trap: -6 sec duration, +100% effect
                    immo->ChangeAmount(immo->GetAmount() * 2);
                    int32 dur = immo->GetBase()->GetDuration() - 6000;
                    immo->GetBase()->SetDuration(dur);
                    immo->GetBase()->SetMaxDuration(dur);
                }
            }
            if (lvl >= 15 && baseId == SERPENT_STING_1)
            {
                if (Aura* sting = target->GetAura(spell->Id, me->GetGUID()))
                {
                    //Glyph of Serpent Sting: +6 sec duration
                    //Improved Serpent Sting (24467): +3 sec duration
                    int32 dur = sting->GetDuration() + 6000;
                    if (lvl >= 60)
                        dur += 3000;
                    sting->SetDuration(dur);
                    sting->SetMaxDuration(dur);
                }
            }
            if (lvl >= 30 && baseId == WING_CLIP_1)
            {
                //zzzOLD Improved Wing Clip (only on creatures): 30% to root target with Wing Clip
                //normal creatures are rooted for 10 sec, elites+ for 6 sec
                if (target->GetTypeId() == TYPEID_UNIT)
                {
                    if (urand(1,100) <= 30)
                    {
                        uint32 clip = target->ToCreature()->GetCreatureTemplate()->rank == CREATURE_ELITE_NORMAL ? IMPROVED_WING_CLIP_NORMAL : IMPROVED_WING_CLIP_EX;
                        me->CastSpell(target, clip, true);
                    }
                }
            }
            if (lvl >= 10 && baseId == CONCUSSIVE_SHOT_1)
            {
                //Improved Concussion Shot rank 2: 2 sec increased daze duration
                if (Aura* concus = target->GetAura(spell->Id, me->GetGUID()))
                {
                    int32 dur = concus->GetDuration() + 2000;
                    concus->SetDuration(dur);
                    concus->SetMaxDuration(dur);
                }

                //zzzOLD Improved Concussion Shot: chance to stun target for 3 sec
                if (urand(1,100) <= 15)
                {
                    me->CastSpell(target, IMPROVED_CONCUSSION, true);
                }
            }
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && lvl >= 50 && baseId == STEADY_SHOT_1)
            {
                //Improved Steady Shot: 15% chance
                if (urand(1,100) <= 15)
                {
                    me->CastSpell(me, IMPROVED_STEADY_SHOT_BUFF, true);
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
            uint8 lvl = me->GetLevel();

            //Feign Death should always clear combat on bots
            if (baseId == FEIGN_DEATH_1 && me->GetMap()->IsDungeon())
                me->CombatStop(false, false);

            //Rapid Recuperation (Rapid Killing) hackfix: trigger 2% energize
            if (baseId == RAPID_RECUPERATION_ENERGIZE)
            {
                me->CastSpell(me, RAPID_RECUPERATION_ENERGIZE_PCT_1, true);
            }
            //Rapid Recuperation (Rapid Fire): match duration
            if (baseId == RAPID_RECUPERATION_BUFF && GetSpell(RAPID_FIRE_1))
            {
                if (Aura const* rapi = me->GetAura(GetSpell(RAPID_FIRE_1)))
                {
                    if (Aura* recu = me->GetAura(spell->Id))
                    {
                        uint32 dur = rapi->GetDuration();
                        recu->SetDuration(dur);
                        recu->SetMaxDuration(dur);
                    }
                }
            }
            //Rapid Recuperation (Rapid Fire)
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && baseId == RAPID_FIRE_1 && me->GetLevel() >= 45)
            {
                me->CastSpell(me, RAPID_RECUPERATION_BUFF, true);
            }
            //Rapid Recuperation (Rapid Killing)
            if ((GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP) && baseId == RAPID_KILLING_BUFF && me->GetLevel() >= 45)
            {
                me->CastSpell(me, RAPID_RECUPERATION_BUFF2, true);
            }
            if (baseId == RAPID_FIRE_1 && lvl >= 26)
            {
                //Rapid Fire (id 28755): 4 sec increased duration
                //Glyph of Rapid Fire: +8% haste
                if (AuraEffect* rapi = me->GetAuraEffect(spell->Id, 0, me->GetGUID()))
                {
                    rapi->ChangeAmount(rapi->GetAmount() + 8);

                    uint32 dur = rapi->GetBase()->GetDuration() + 4000;
                    rapi->GetBase()->SetDuration(dur);
                    rapi->GetBase()->SetMaxDuration(dur);
                }
            }
            if (baseId == QUICK_SHOTS_BUFF)
            {
                if (AuraEffect* quic = me->GetAuraEffect(QUICK_SHOTS_BUFF, 0))
                {
                    //base 15% haste
                    int32 newAmount = quic->GetAmount() + 15;
                    //Glyph of the Hawk: +6% effect flat
                    if (lvl >= 15)
                        newAmount += 6;

                    quic->ChangeAmount(newAmount);
                }
            }
            if ((baseId == ASPECT_OF_THE_CHEETAH_1 || baseId == ASPECT_OF_THE_PACK_1) && caster == me && lvl >= 20)
            {
                //Pathfinding: +8% increased effect
                if (AuraEffect* spee = me->GetAuraEffect(spell->Id, 0, me->GetGUID()))
                {
                    spee->ChangeAmount(spee->GetAmount() + 8);
                }
            }
            if ((baseId == ASPECT_OF_THE_MONKEY_1 || baseId == ASPECT_OF_THE_DRAGONHAWK_MONKEY) && lvl >= 15)
            {
                //Improved Aspect of The Monkey: +6% dodge chance
                if (AuraEffect* monk = me->GetAuraEffect(spell->Id, 0, me->GetGUID()))
                {
                    monk->ChangeAmount(monk->GetAmount() + 6);
                }
            }
            //Aspect Mastery
            if (lvl >= 20)
            {
                if (baseId == ASPECT_OF_THE_VIPER_1)
                {
                    if (AuraEffect* vipe = me->GetAuraEffect(spell->Id, 1, me->GetGUID()))
                    {
                        //part 1: 10% reduced damage penalty
                        vipe->ChangeAmount(vipe->GetAmount() + 10);
                    }
                }
                if (baseId == ASPECT_OF_THE_MONKEY_1 || baseId == ASPECT_OF_THE_DRAGONHAWK_MONKEY)
                {
                    if (AuraEffect* monk = me->GetAuraEffect(spell->Id, 1, me->GetGUID()))
                    {
                        //part 2: 5% reduced damage
                        monk->ChangeAmount(monk->GetAmount() - 5);
                    }
                }
                if (baseId == ASPECT_OF_THE_HAWK_1 || baseId == ASPECT_OF_THE_DRAGONHAWK_1)
                {
                    if (AuraEffect* hawk = me->GetAuraEffect(spell->Id, 0, me->GetGUID()))
                    {
                        //part 3: 30% attack power bonus
                        hawk->ChangeAmount(hawk->GetAmount() * 13 / 10);
                    }
                }
            }

            OnSpellHit(caster, spell);
        }

        void OnBotDamageDealt(Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellInfo const* /*spellInfo*/) override
        {
            if (botPet && victim != me && victim != botPet && damage > 0 && cleanDamage && cleanDamage->hitOutCome == MELEE_HIT_CRIT &&
                (damagetype == DIRECT_DAMAGE || damagetype == SPELL_DIRECT_DAMAGE) && me->GetLevel() >= 20)
            {
                //Go for the Throat: energize pet
                me->EnergizeBySpell(botPet, GO_FOR_THE_THROAT_ENERGIZE, 50, POWER_FOCUS);
                //Frenzy hack: proc from hunter's crits
                if (me->GetLevel() >= 35)
                    botPet->CastSpell(botPet, FRENZY_BUFF, true);
            }
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

        void SummonBotPet()
        {
            if (botPet)
                UnsummonAll(false);

            if (me->GetLevel() < 10)
                return;

            if (myPetType == BOT_PET_INVALID) //disabled
                return;

            if (petSummonTimer > GetLastDiff())
                return;

            uint32 entry;

            if (myPetType)
                entry = myPetType;
            else if (!IAmFree())
            {
                if ((master->GetGroup() && master->GetGroup()->isRaidGroup()) || master->GetNpcBotsCount() >= 10)
                    entry = BOT_PET_WOLF; //raid pet
                else if (!IsMeleeClass(master->GetClass()))
                    entry = urand(BOT_PET_TENACITY_START, BOT_PET_TENACITY_END);
                else if (sWorld->IsFFAPvPRealm() || sWorld->IsPvPRealm())
                    entry = urand(BOT_PET_CUNNING_START, BOT_PET_CUNNING_END);
                else
                    entry = urand(BOT_PET_HUNTER_START, BOT_PET_HUNTER_END_GENERAL);
            }
            else
                entry = urand(BOT_PET_HUNTER_START, BOT_PET_HUNTER_END_GENERAL);

            //ensurance
            if (entry < BOT_PET_HUNTER_START || entry > BOT_PET_HUNTER_END_EXOTIC ||
                (entry >= BOT_PET_EXOTIC_START && _spec != BOT_SPEC_HUNTER_BEASTMASTERY))
                entry = 0;

            myPetType = entry;

            //try next time
            if (!myPetType)
                return;

            petSummonTimer = 10000;
            ResetSpellCooldown(KINDRED_SPIRITS_PET);
            ResetSpellCooldown(SPIRIT_BOND_PET);

            Position pos;

            me->CastSpell(me, CALL_PET_VISUAL, true);
            Creature* myPet = me->SummonCreature(myPetType, *me, TEMPSUMMON_CORPSE_DESPAWN);
            me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0, me->GetOrientation() + M_PI / 2);
            myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            myPet->SetCreator(master);
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            //fix scale
            switch (myPetType)
            {
                case BOT_PET_RAVAGER:
                case BOT_PET_WASP:
                case BOT_PET_TEROMOTH:
                case BOT_PET_SCORPID:
                case BOT_PET_TURTLE:
                case BOT_PET_BEAR:
                case BOT_PET_WARPSTALKER:
                case BOT_PET_COREHOUND:
                    myPet->SetObjectScale(0.75f);
                    break;
                case BOT_PET_CHIMAERA:
                    myPet->SetObjectScale(0.67f);
                    break;
                case BOT_PET_RAPTOR:
                case BOT_PET_DEVILSAUR:
                case BOT_PET_RHINO:
                    myPet->SetObjectScale(0.5f);
                    break;
                default:
                    break;
            }

            botPet = myPet;
        }

        void UnsummonAll(bool savePets = true) override
        {
            UnsummonPet(savePets);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDies: {}'s {}", me->GetName(), summon->GetName());
            //if (summon == botPet)
            //    botPet = nullptr;
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //all hunter bot pets despawn at death or manually (gossip, teleport, etc.)
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: {}'s {}", me->GetName(), summon->GetName());
            if (summon == botPet)
            {
                petSummonTimer = 10000;
                botPet = nullptr;
            }
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(AUTO_SHOT_1) : 25.f;
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return myPetType;
                case BOTAI_MISC_PET_AVAILABLE_1:
                    return BOT_PET_WOLF;
                case BOTAI_MISC_PET_AVAILABLE_2:
                    return BOT_PET_CUNNING_START;
                case BOTAI_MISC_PET_AVAILABLE_3:
                    return BOT_PET_FEROCITY_START;
                case BOTAI_MISC_PET_AVAILABLE_4:
                    return BOT_PET_TENACITY_START;
                case BOTAI_MISC_PET_AVAILABLE_5:
                    return me->GetLevel() >= 80 ? BOT_PET_SILITHID : 0;
                case BOTAI_MISC_PET_AVAILABLE_6:
                    return me->GetLevel() >= 80 ? BOT_PET_CHIMAERA : 0;
                case BOTAI_MISC_PET_AVAILABLE_7:
                    return me->GetLevel() >= 80 ? BOT_PET_SPIRITBEAST : 0;
                case BOTAI_MISC_PET_AVAILABLE_8:
                    return me->GetLevel() >= 80 ? BOT_PET_COREHOUND : 0;
                case BOTAI_MISC_PET_AVAILABLE_9:
                    return me->GetLevel() >= 80 ? BOT_PET_DEVILSAUR : 0;
                case BOTAI_MISC_PET_AVAILABLE_10:
                    return me->GetLevel() >= 80 ? BOT_PET_RHINO : 0;
                case BOTAI_MISC_PET_AVAILABLE_11:
                    return me->GetLevel() >= 80 ? BOT_PET_WORM : 0;
                default:
                    return 0;
            }
        }

        void SetAIMiscValue(uint32 data, uint32 value) override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    myPetType = value;
                    UnsummonAll(false);
                    break;
                default:
                    break;
            }
        }

        void Reset() override
        {
            UnsummonAll(false);

            myPetType = 0;

            trapTimer = 0;
            stingTimer = 0;
            aspectTimer = 0;
            flareTimer = 0;
            misdirectionTimer = 0;
            checkMendTimer = 0;

            petSummonTimer = 5000;

            Aspect = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (trapTimer > diff)                   trapTimer -= diff;
            if (stingTimer > diff)                  stingTimer -= diff;
            if (aspectTimer > diff)                 aspectTimer -= diff;
            if (flareTimer > diff)                  flareTimer -= diff;
            if (misdirectionTimer > diff)           misdirectionTimer -= diff;
            if (checkMendTimer > diff)              checkMendTimer -= diff;

            if (petSummonTimer > diff)              petSummonTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);

            if (botPet && botPet->GetPowerType() != POWER_FOCUS)
                botPet->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_FOCUS);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            //bool isBeas = GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY;
            bool isMark = GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP;
            bool isSurv = GetSpec() == BOT_SPEC_HUNTER_SURVIVAL;

            InitSpellMap(AUTO_SHOT_1);
            InitSpellMap(ARCANE_SHOT_1);
            InitSpellMap(TRANQ_SHOT_1);
            InitSpellMap(STEADY_SHOT_1);
            InitSpellMap(KILL_SHOT_1);
            InitSpellMap(MULTISHOT_1);
            InitSpellMap(VOLLEY_1);
            InitSpellMap(CONCUSSIVE_SHOT_1);
            InitSpellMap(DISTRACTING_SHOT_1);
            InitSpellMap(SERPENT_STING_1);
            InitSpellMap(SCORPID_STING_1);
            InitSpellMap(VIPER_STING_1);
            InitSpellMap(RAPID_FIRE_1);
            InitSpellMap(FLARE_1);
            InitSpellMap(WING_CLIP_1);
            InitSpellMap(RAPTOR_STRIKE_1);
            InitSpellMap(MONGOOSE_BITE_1);
            InitSpellMap(DISENGAGE_1);
            InitSpellMap(IMMOLATION_TRAP_1);
            InitSpellMap(FREEZING_TRAP_1);
            InitSpellMap(FROST_TRAP_1);
            InitSpellMap(EXPLOSIVE_TRAP_1);
            InitSpellMap(FREEZING_ARROW_1);
            InitSpellMap(HUNTERS_MARK_1);
            InitSpellMap(SCARE_BEAST_1);
            InitSpellMap(FEIGN_DEATH_1);
            InitSpellMap(DETERRENCE_1);
            InitSpellMap(MISDIRECTION_1);
            InitSpellMap(MEND_PET_1);

            InitSpellMap(ASPECT_OF_THE_MONKEY_1);
            InitSpellMap(ASPECT_OF_THE_HAWK_1);
            InitSpellMap(ASPECT_OF_THE_CHEETAH_1);
            InitSpellMap(ASPECT_OF_THE_VIPER_1);
            //InitSpellMap(ASPECT_OF_THE_BEAST_1);
            InitSpellMap(ASPECT_OF_THE_PACK_1);
            InitSpellMap(ASPECT_OF_THE_WILD_1);
            InitSpellMap(ASPECT_OF_THE_DRAGONHAWK_1);

  /*Talent*/lvl >= (isMark ? 20 : 70) ? InitSpellMap(AIMED_SHOT_1) : RemoveSpell(AIMED_SHOT_1);
  /*Talent*/lvl >= 30 && isMark ? InitSpellMap(READINESS_1) : RemoveSpell(READINESS_1);
  /*Talent*/lvl >= 40 && isMark ? InitSpellMap(TRUESHOT_AURA_1) : RemoveSpell(TRUESHOT_AURA_1);
  /*Talent*/lvl >= 50 && isMark ? InitSpellMap(SILENCING_SHOT_1) : RemoveSpell(SILENCING_SHOT_1);
  /*Talent*/lvl >= 60 && isMark ? InitSpellMap(CHIMERA_SHOT_1) : RemoveSpell(CHIMERA_SHOT_1);

  /*Talent*/lvl >= (isSurv ? 20 : isMark ? 70 : 99) ? InitSpellMap(SCATTER_SHOT_1) : RemoveSpell(SCATTER_SHOT_1);
  /*Talent*/lvl >= 30 && isSurv ? InitSpellMap(COUNTERATTACK_1) : RemoveSpell(COUNTERATTACK_1);
  /*Talent*/lvl >= 40 && isSurv ? InitSpellMap(WYVERN_STING_1) : RemoveSpell(WYVERN_STING_1);
  /*Talent*/lvl >= 50 && isSurv ? InitSpellMap(BLACK_ARROW_1) : RemoveSpell(BLACK_ARROW_1);
  /*Talent*/lvl >= 60 && isSurv ? InitSpellMap(EXPLOSIVE_SHOT_1) : RemoveSpell(EXPLOSIVE_SHOT_1);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isBeas = GetSpec() == BOT_SPEC_HUNTER_BEASTMASTERY;
            bool isMark = GetSpec() == BOT_SPEC_HUNTER_MARKSMANSHIP;
            bool isSurv = GetSpec() == BOT_SPEC_HUNTER_SURVIVAL;

            RefreshAura(IMPROVED_MEND_PET, isBeas && level >= 25 ? 1 : 0);

            RefreshAura(RAPID_KILLING, isMark && level >= 20 ? 1 : 0);
            RefreshAura(CONCUSSIVE_BARRAGE, isMark && level >= 30 ? 1 : 0);
            RefreshAura(PIERCING_SHOTS, isMark && level >= 40 ? 1 : 0);
            //RefreshAura(TRUESHOT_AURA, isMark && level >= 40 ? 1 : 0);
            RefreshAura(MASTER_MARKSMAN, isMark && level >= 45 ? 1 : 0);
            RefreshAura(WILD_QUIVER, isMark && level >= 50 ? 1 : 0);

            RefreshAura(SUREFOOTED, level >= 15 ? 1 : 0);
            RefreshAura(ENTRAPMENT, isSurv && level >= 15 ? 1 : 0);
            RefreshAura(LOCK_AND_LOAD, isSurv && level >= 25 ? 1 : 0);
            RefreshAura(EXPOSE_WEAKNESS, isSurv && level >= 40 ? 1 : 0);
            RefreshAura(THRILL_OF_THE_HUNT, isSurv && level >= 40 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN5, isSurv && level >= 50 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN4, isSurv && level >= 49 && level < 50 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN3, isSurv && level >= 48 && level < 49 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN2, isSurv && level >= 47 && level < 48 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN1, isSurv && level >= 46 && level < 47 ? 1 : 0);
            RefreshAura(NOXIOUS_STINGS, isSurv && level >= 45 ? 1 : 0);
            RefreshAura(SNIPER_TRAINING, isSurv && level >= 50 ? 1 : 0);

            RefreshAura(GLYPH_RAPTOR_STRIKE, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_ASPECT_OF_THE_VIPER, level >= 20 ? 1 : 0);
            RefreshAura(GLYPH_FREEZING_TRAP, level >= 20 ? 1 : 0);
            RefreshAura(GLYPH_EXPLOSIVE_TRAP, level >= 34 ? 1 : 0);

            RefreshAura(HUNTER_T8_P2, level >= 70 ? 1 : 0);
            RefreshAura(HUNTER_T10_P2, level >= 75 ? 1 : 0);
            RefreshAura(HUNTER_T10_P4, level >= 80 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                //case RAPID_FIRE_1:
                case FLARE_1:
                case MEND_PET_1:
                case IMMOLATION_TRAP_1:
                case FREEZING_TRAP_1:
                case FROST_TRAP_1:
                case EXPLOSIVE_TRAP_1:
                case VOLLEY_1:
                //case ASPECT_OF_THE_MONKEY_1:
                //case ASPECT_OF_THE_HAWK_1:
                //case ASPECT_OF_THE_CHEETAH_1:
                //case ASPECT_OF_THE_VIPER_1:
                //case ASPECT_OF_THE_BEAST_1:
                case ASPECT_OF_THE_PACK_1:
                case ASPECT_OF_THE_WILD_1:
                //case ASPECT_OF_THE_DRAGONHAWK_1:
                    return true;
                default:
                    return false;
            }
        }

        bool HasAbilitiesSpecifics() const override { return true; }
        void FillAbilitiesSpecifics(Player const* player, std::list<std::string> &specList) override
        {
            uint32 textId;
            switch (Aspect)
            {
                case ASPECT_MONKEY:     textId = BOT_TEXT_MONKEY;       break;
                case ASPECT_HAWK:       textId = BOT_TEXT_HAWK;         break;
                case ASPECT_CHEETAH:    textId = BOT_TEXT_CHEETAH;      break;
                case ASPECT_VIPER:      textId = BOT_TEXT_VIPER;        break;
                case ASPECT_BEAST:      textId = BOT_TEXT_BEAST;        break;
                case ASPECT_PACK:       textId = BOT_TEXT_PACK;         break;
                case ASPECT_WILD:       textId = BOT_TEXT_WILD;         break;
                case ASPECT_DRAGONHAWK: textId = BOT_TEXT_DRAGONHAWK;   break;
                default:                textId = BOT_TEXT_NOASPECT;     break;
            }
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_ASPECT) + ": " + LocalizedNpcText(player, textId));
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Hunter_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Hunter_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Hunter_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Hunter_spells_support;
        }

    private:
        uint32 trapTimer, stingTimer, aspectTimer, flareTimer, misdirectionTimer, checkMendTimer;
        uint8 Aspect;
        //Pet
        uint32 myPetType;
        uint32 petSummonTimer;

        //Scans target for hunter's aspects
        //returns applied aspects mask
        //used for finding out which aspects target lacks
        uint32 _getAspectsMask(std::map<uint32 /*type*/, uint32 /*curId*/>& idMap) const
        {
            uint32 mask = 0;

            uint32 baseId;
            bool isAspect;
            Unit::AuraApplicationMap const& aurapps = me->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = aurapps.begin(); itr != aurapps.end(); ++itr)
            {
                isAspect = true;
                baseId = itr->second->GetBase()->GetSpellInfo()->GetFirstRankSpell()->Id;
                switch (baseId)
                {
                    //case ASPECT_OF_THE_MONKEY_1:
                    //    mask |= SPECIFIC_ASPECT_MONKEY;
                    //    break;
                    case ASPECT_OF_THE_HAWK_1:
                        mask |= SPECIFIC_ASPECT_HAWK;
                        break;
                    case ASPECT_OF_THE_CHEETAH_1:
                        mask |= SPECIFIC_ASPECT_CHEETAH;
                        break;
                    //case ASPECT_OF_THE_VIPER_1:
                    //    mask |= SPECIFIC_ASPECT_VIPER;
                    //    break;
                    //case ASPECT_OF_THE_BEAST_1:
                    //    mask |= SPECIFIC_ASPECT_BEAST;
                    //    break;
                    case ASPECT_OF_THE_PACK_1:
                        mask |= SPECIFIC_ASPECT_PACK;
                        break;
                    case ASPECT_OF_THE_WILD_1:
                        mask |= SPECIFIC_ASPECT_WILD;
                        break;
                    case ASPECT_OF_THE_DRAGONHAWK_1:
                        mask |= SPECIFIC_ASPECT_DRAGONHAWK;
                        break;
                    default:
                        isAspect = false; //next aura
                        break;
                }

                if (isAspect)
                {
                    idMap[baseId] = itr->first;
                    if (itr->second->GetBase()->GetCasterGUID() == me->GetGUID())
                        mask |= SPECIFIC_ASPECT_MY_ASPECT;
                }
            }

            return mask;
        }
    };
};

void AddSC_hunter_bot()
{
    new hunter_bot();
}
