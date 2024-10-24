#include "bot_ai.h"
#include "botmgr.h"
#include "botspell.h"
#include "bottraits.h"
#include "Containers.h"
#include "GameEventMgr.h"
#include "Group.h"
#include "Item.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
/*
Mage NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - 92-97%
TODO: slow (pvp), mana shield
*/

enum MageBaseSpells
{
    DAMPENMAGIC_1                       = 604,
    AMPLIFYMAGIC_1                      = 1008,//manual use only
    ARCANEINTELLECT_1                   = 1459,
    ARCANEMISSILES_1                    = 5143,
    ARCANE_BLAST_1                      = 30451,
    POLYMORPH_1                         = 118,
    COUNTERSPELL_1                      = 2139,
    SPELLSTEAL_1                        = 30449,
    EVOCATION_1                         = 12051,
    BLINK_1                             = 1953,
    REMOVE_CURSE_1                      = 475,
    INVISIBILITY_1                      = 66,
    SCORCH_1                            = 2948,
    BLAST_WAVE_1                        = 11113,
    DRAGON_BREATH_1                     = 31661,
    FIRE_BLAST_1                        = 2136,
    PYROBLAST_1                         = 11366,
    LIVING_BOMB_1                       = 44457,
    FLAMESTRIKE_1                       = 2120,
    COMBUSTION_1                        = 11129,
    FROSTFIRE_BOLT_1                    = 44614,
    FIREBALL_1                          = 133,
    FROSTBOLT_1                         = 116,
    FROST_NOVA_1                        = 122,
    CONE_OF_COLD_1                      = 120,
    BLIZZARD_1                          = 10,
    FROST_ARMOR_1                       = 168,
    ICE_ARMOR_1                         = 7302,
    MOLTEN_ARMOR_1                      = 30482,
    ICE_BARRIER_1                       = 11426,
    ICE_BLOCK_1                         = 45438,
    FOCUS_MAGIC_1                       = 54646,
    PRESENCE_OF_MIND_1                  = 12043,
    ARCANE_POWER_1                      = 12042,
    SLOW_FALL_1                         = 130,
    ICE_LANCE_1                         = 30455,
    ICY_VEINS_1                         = 12472,
    COLD_SNAP_1                         = 11958,
    DEEP_FREEZE_1                       = 44572,
    FROST_WARD_1                        = 6143,
    FIRE_WARD_1                         = 543,
    MIRROR_IMAGE_1                      = 55342,
    //Special
    ARCANE_MISSILES_DAMAGE_1            = 7268,
    BLIZZARD_DAMAGE_1                   = 42208,
    LIVING_BOMB_DAMAGE_1                = 44461,
    CONJURE_MANA_GEM_1                  = 759,
    MANA_GEM_1                          = 5405,
    RITUAL_OF_REFRESHMENT_1             = 43987,

    SUMMON_WATER_ELEMENTAL_1            = 31687
};

enum MagePassives
{
//Talents
    FROSTBITE1                          = 11071,
    FROSTBITE2                          = 12496,
    FROSTBITE3                          = 12497,
    ARCANE_CONCENTRATION                = 12577,//rank 5, clearcast
    IGNITE                              = 12848,//rank 5
    BURNING_DETERMINATION               = 54749,//rank 2
    FROST_WARDING                       = 28332,//rank 2
    IMPROVED_COUNTERSPELL1              = 11255,
    IMPROVED_COUNTERSPELL2              = 12598,
    ARCANE_MEDITATION                   = 18464,//rank 3
    TORMENT_THE_WEAK                    = 55340,//rank 3
    IMPACT                              = 12358,//rank 3
    IMPROVED_BLIZZARD                   = 12488,//rank 3
    IMPROVED_SCORCH                     = 12873,//rank 3
    MOLTEN_SHIELDS                      = 13043,//rank 2
    MASTER_OF_ELEMENTS                  = 29076,//rank 3
    SHATTER1                            = 11170,
    SHATTER2                            = 12982,
    SHATTER3                            = 12983,
    ARCANE_POTENCY1                     = 31571,
    ARCANE_POTENCY2                     = 31572,
    BLAZING_SPEED                       = 31642,//rank 2
    WINTERS_CHILL1                      = 11180,
    WINTERS_CHILL2                      = 28592,
    WINTERS_CHILL3                      = 28593,
    ARCANE_EMPOWERMENT                  = 31583,//rank 3
    INCANTERS_ABSORPTION1               = 44394,
    INCANTERS_ABSORPTION2               = 44395,
    INCANTERS_ABSORPTION3               = 44396,
    MISSILE_BARRAGE                     = 54490,//rank 5
    PYROMANIAC                          = 34296,//rank 3
    SHATTERED_BARRIER                   = 54787,//rank 2
    //ARCTIC_WINDS                        = 31678,//rank 5
    FINGERS_OF_FROST                    = 44545,//rank 2
    FIRESTARTER1                        = 44442,
    FIRESTARTER2                        = 44443,
    HOT_STREAK                          = 44448,//rank 3
    BRAIN_FREEZE1                       = 44546,
    BRAIN_FREEZE2                       = 44548,
    BRAIN_FREEZE3                       = 44549,

    GLYPH_POLYMORPH                     = 56375,
    GLYPG_REMOVE_CURSE                  = 56364,
    GLYPH_ICY_VEINS                     = 56374,
    GLYPH_LIVING_BOMB                   = 63091,
    GLYPH_ICE_LANCE                     = 56377
};
enum MageSpecial
{
    ARCANE_CONCENTRATION_BUFF           = 12536,
    IMPACT_BUFF                         = 64343,
    FIRESTARTER_BUFF                    = 54741,
    ARCANE_POTENCY_BUFF1                = 57529,
    ARCANE_POTENCY_BUFF2                = 57531,
    COMBUSTION_BUFF                     = 28682,
    BRAIN_FREEZE_BUFF                   = 57761,
    HOT_STREAK_BUFF                     = 48108,
    FINGERS_OF_FROST_BUFF               = 44544,
    ARCANE_BLAST_DEBUFF                 = 36032,
    MISSILE_BARRAGE_BUFF                = 44401,
    IMPROVED_BLIZZARD_CHILL             = 12486,//rank 3
    FROSTBITE_TRIGGERED                 = 12494,
    WINTERS_CHILL_TRIGGERED             = 12579,
    IGNITE_TRIGGERED                    = 12654
};

static const uint32 Mage_spells_damage_arr[] =
{ ARCANEMISSILES_1, ARCANE_BLAST_1, BLAST_WAVE_1, BLIZZARD_1, CONE_OF_COLD_1, DEEP_FREEZE_1, DRAGON_BREATH_1, FIREBALL_1,
FIRE_BLAST_1, FLAMESTRIKE_1, FROSTBOLT_1, FROSTFIRE_BOLT_1, FROST_NOVA_1, ICE_LANCE_1, LIVING_BOMB_1, PYROBLAST_1,
SCORCH_1 };

static const uint32 Mage_spells_cc_arr[] =
{ COUNTERSPELL_1, DRAGON_BREATH_1, DEEP_FREEZE_1, FROST_NOVA_1, POLYMORPH_1 };

static const uint32 Mage_spells_support_arr[] =
{ AMPLIFYMAGIC_1, ARCANEINTELLECT_1, BLINK_1, COMBUSTION_1, DAMPENMAGIC_1, EVOCATION_1, FIRE_WARD_1, FROST_WARD_1,
FROST_ARMOR_1, FOCUS_MAGIC_1, ICE_BARRIER_1, ICE_BLOCK_1, ICY_VEINS_1, INVISIBILITY_1, ICE_ARMOR_1, MOLTEN_ARMOR_1,
SLOW_FALL_1, SPELLSTEAL_1, REMOVE_CURSE_1, CONJURE_MANA_GEM_1, RITUAL_OF_REFRESHMENT_1, SUMMON_WATER_ELEMENTAL_1,
COLD_SNAP_1, PRESENCE_OF_MIND_1, ARCANE_POWER_1 };

static const std::vector<uint32> Mage_spells_damage(FROM_ARRAY(Mage_spells_damage_arr));
static const std::vector<uint32> Mage_spells_cc(FROM_ARRAY(Mage_spells_cc_arr));
static const std::vector<uint32> Mage_spells_support(FROM_ARRAY(Mage_spells_support_arr));

class mage_bot : public CreatureScript
{
public:
    mage_bot() : CreatureScript("mage_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mage_botAI(creature);
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
    struct mage_botAI : public bot_ai
    {
        mage_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_MAGE;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        void JustEnteredCombat(Unit* u) override { canFrostWard = false; canFireWard = false; bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonAll(false); bot_ai::JustDied(u); }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void Counter(uint32 diff)
        {
            //skip if evocation, blizzard
            if (IsChanneling() || Rand() > 30)
                return;

            if (IsSpellReady(COUNTERSPELL_1, diff, false))
            {
                if (Unit* target = FindCastingTarget(CalcSpellMaxRange(COUNTERSPELL_1), 0, COUNTERSPELL_1))
                {
                    me->InterruptNonMeleeSpells(false);
                    if (doCast(target, GetSpell(COUNTERSPELL_1)))
                        return;
                }
            }
            if (IsSpellReady(DEEP_FREEZE_1, diff) && me->HasAuraType(SPELL_AURA_ABILITY_IGNORE_AURASTATE))
            {
                if (Unit* target = FindCastingTarget(CalcSpellMaxRange(DEEP_FREEZE_1), 0, DEEP_FREEZE_1))
                {
                    me->InterruptNonMeleeSpells(false);
                    if (doCast(target, GetSpell(DEEP_FREEZE_1)))
                        return;
                }
            }
            if (IsSpellReady(FIRE_BLAST_1, diff) && me->HasAura(IMPACT_BUFF))
            {
                if (Unit* target = FindCastingTarget(CalcSpellMaxRange(FIRE_BLAST_1), 0, FIRE_BLAST_1))
                {
                    me->InterruptNonMeleeSpells(false);
                    if (doCast(target, GetSpell(FIRE_BLAST_1)))
                        return;
                }
            }
            if (!IsCasting() && IsSpellReady(POLYMORPH_1, diff))
            {
                if (Unit* target = FindCastingTarget(CalcSpellMaxRange(POLYMORPH_1), 0, POLYMORPH_1, 75))
                {
                    if (doCast(target, GetSpell(POLYMORPH_1)))
                        return;
                }
            }
        }

        void CheckSpellSteal(uint32 diff)
        {
            if (!IsSpellReady(SPELLSTEAL_1, diff) || IsCasting() || Rand() > 15)
                return;

            Unit* target = FindHostileDispelTarget(CalcSpellMaxRange(SPELLSTEAL_1), true);
            if (target && doCast(target, GetSpell(SPELLSTEAL_1)))
                return;
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || Feasting() || Rand() > 25)
                return;

            //slow fall
            if (GetSpell(SLOW_FALL_1) && !IAmFree())
            {
                Player* fPlayer = nullptr;
                Group const* gr = master->GetGroup();
                if (gr)
                {
                    for (GroupReference const* ref = gr->GetFirstMember(); ref != nullptr; ref = ref->next())
                    {
                        Player* pl = ref->GetSource();
                        if (pl && pl->IsAlive() && pl->FindMap() == me->GetMap() && pl->GetDistance(me) < 30 &&
                            pl->IsFalling() && pl->m_movementInfo.fallTime > 1000 &&
                            !pl->HasAuraType(SPELL_AURA_FEATHER_FALL))
                        {
                            fPlayer = pl;
                            break;
                        }
                    }
                }
                else if (master->IsAlive() && master->GetDistance(me) < 30 && master->IsFalling() &&
                    master->m_movementInfo.fallTime > 1000 && !master->HasAuraType(SPELL_AURA_FEATHER_FALL))
                    fPlayer = master;

                if (fPlayer && doCast(fPlayer, GetSpell(SLOW_FALL_1)))
                    return;
            }

            //ARMOR
            uint32 MOLTENARMOR = HasRole(BOT_ROLE_DPS) ? GetSpell(MOLTEN_ARMOR_1) : GetSpell(ICE_ARMOR_1);
            uint32 ICEARMOR = GetSpell(ICE_ARMOR_1) ? GetSpell(ICE_ARMOR_1) : GetSpell(FROST_ARMOR_1);
            uint32 ARMOR = !MOLTENARMOR ? ICEARMOR : (me->GetMap()->IsDungeon() || !ICEARMOR) ? MOLTENARMOR : ICEARMOR;
            if (ARMOR && !me->HasAura(ARMOR))
            {
                if (doCast(me, ARMOR))
                    return;
            }

            if (GetSpell(CONJURE_MANA_GEM_1))
            {
                if (manaGemCharges == 0 &&
                    doCast(me, GetSpell(CONJURE_MANA_GEM_1)))
                    return;
            }
            if (GetSpell(DAMPENMAGIC_1))
            {
                if (!me->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_DAMAGE_TAKEN, SPELLFAMILY_MAGE, 0x2000)
                    /*!HasAuraName(me, DAMPENMAGIC_1)*/ &&
                    doCast(me, GetSpell(DAMPENMAGIC_1)))
                    return;
            }
        }

        bool BuffTarget(Unit* target, uint32 /*diff*/) override
        {
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;

            if (GetSpell(ARCANEINTELLECT_1) && target->GetMaxPower(POWER_MANA) > 1 &&
                !target->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_STAT, SPELLFAMILY_MAGE, 0x400)
                /*!HasAuraName(target, ARCANEINTELLECT_1)*/)
            {
                if (doCast(target, GetSpell(ARCANEINTELLECT_1)))
                    return true;
            }

            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            CheckPots(diff);

            CheckPoly(diff);
            CheckBlink(diff);
            CheckIceBlock(diff);

            CheckRacials(diff);

            CheckShield(diff);
            CureGroup(GetSpell(REMOVE_CURSE_1), diff);
            CheckWard(diff);

            CheckFocusMagic(diff);
            BuffAndHealGroup(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            //pet
            if ((!botPet || !botPet->IsAlive()) &&
                IsSpellReady(SUMMON_WATER_ELEMENTAL_1, diff) && !IsCasting() && (IAmFree() || master->IsInCombat()))
                if (doCast(me, GetSpell(SUMMON_WATER_ELEMENTAL_1)))
                    return;

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
                return;

            CheckPolymorph(diff);//this should go AFTER getting target

            Counter(diff);
            CheckSpellSteal(diff);
            CheckColdSnap(diff);

            if (IsCasting())
                return;

            if (me->HasInvisibilityAura())
                return;

            CheckUsableItems(diff);

            DoNormalAttack(diff);
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

            if (!HasRole(BOT_ROLE_DPS))
                return;

            Unit::AttackerSet const& b_attackers = me->getAttackers();

            float dist = me->GetDistance(mytar);

            //COMBUSTION (no GCD)
            if (IsSpellReady(COMBUSTION_1, diff, false) && GetManaPCT(me) > 20 &&
                (mytar->GetMaxHealth() > master->GetMaxHealth() * 4 ||
                master->getAttackers().size() > 1 || b_attackers.size() > 1) &&
                Rand() < 45 &&
                !me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x04000000, 0x0)
                /*!HasAuraName(me, COMBUSTION_1)*/)
            {
                if (doCast(me, GetSpell(COMBUSTION_1)))
                    return;
            }
            //ICY VEINS (no GCD)
            if (IsSpellReady(ICY_VEINS_1, diff, false) && me->IsInCombat() && GetManaPCT(me) > 20 &&
                (mytar->GetMaxHealth() > master->GetMaxHealth() * 2 ||
                (mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)) &&
                Rand() < 45)
            {
                if (doCast(me, GetSpell(ICY_VEINS_1)))
                    return;
            }
            //ARCANE POWER (no GCD, not with PoM)
            if (IsSpellReady(ARCANE_POWER_1, diff, false) && me->IsInCombat() && GetManaPCT(me) > 50 &&
                (mytar->GetMaxHealth() > master->GetMaxHealth() * 2 ||
                (mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)) &&
                Rand() < 75 && !me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x20, 0x0))
            {
                if (doCast(me, GetSpell(ARCANE_POWER_1)))
                    return;
            }
            //PRESENCE OF MIND (no GCD, not with AP)
            if (IsSpellReady(PRESENCE_OF_MIND_1, diff, false) && me->IsInCombat() && GetManaPCT(me) > 10 && Rand() < 35 &&
                !me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x80000, 0x0))
            {
                if (doCast(me, GetSpell(PRESENCE_OF_MIND_1)))
                    return;
            }
            //DAMAGE
            //Cheap check
            if (GC_Timer > diff) //!ensure none spells below ignore GCD!
                return;
            //NOVAS
            if ((IsSpellReady(FROST_NOVA_1, diff) || IsSpellReady(BLAST_WAVE_1, diff)) && Rand() < 85)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 8.5f, 1); //both are radius 10 yd
                if (!targets.empty())
                {
                    bool oneOnOne = (*targets.begin()) == mytar;
                    //Frost Nova
                    if (IsSpellReady(FROST_NOVA_1, diff) && (targets.size() > 1 || oneOnOne))
                    {
                        if (doCast(me, GetSpell(FROST_NOVA_1)))
                        {
                            GetInPosition(true, mytar);
                            return;
                        }
                    }
                    //Blast Wave
                    else if (IsSpellReady(BLAST_WAVE_1, diff) && (targets.size() > 1 || oneOnOne))
                    {
                        if (doCast(me, GetSpell(BLAST_WAVE_1)))
                            return;
                    }
                }
            }
            //MIRROR IMAGE
            if (IsSpellReady(MIRROR_IMAGE_1, diff) &&
                (mytar->GetTypeId() == TYPEID_PLAYER ||
                (mytar->GetTypeId() == TYPEID_UNIT && mytar->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)) &&
                Rand() < 25)
            {
                if (doCast(me, GetSpell(MIRROR_IMAGE_1)))
                    return;
            }
            //CONES
            if (/*fbCasted && */(IsSpellReady(CONE_OF_COLD_1, diff) || IsSpellReady(DRAGON_BREATH_1, diff)) && Rand() < 65)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsInConeList(targets, 8); //both are radius 10 yd
                if (!targets.empty())
                {
                    //Cone of Cold
                    if (IsSpellReady(CONE_OF_COLD_1, diff))
                    {
                        if (doCast(me, GetSpell(CONE_OF_COLD_1)))
                            return;
                    }
                    //Dragon's Breath
                    else if (IsSpellReady(DRAGON_BREATH_1, diff))
                    {
                        if (doCast(me, GetSpell(DRAGON_BREATH_1)))
                            return;
                    }
                }
            }

            auto [can_do_frost, can_do_fire, can_do_arcane] = CanAffectVictimBools(mytar, SPELL_SCHOOL_FROST, SPELL_SCHOOL_FIRE, SPELL_SCHOOL_ARCANE);

            //spell reflections: Ice Lance instant / Frostbolt Rank 1
            if (IsSpellReady(ICE_LANCE_1, diff) && can_do_frost && dist < CalcSpellMaxRange(ICE_LANCE_1) && CanRemoveReflectSpells(mytar, ICE_LANCE_1) &&
                doCast(mytar, ICE_LANCE_1))
                return;
            else if (IsSpellReady(FROSTBOLT_1, diff) && can_do_frost && dist < CalcSpellMaxRange(FROSTBOLT_1) && CanRemoveReflectSpells(mytar, FROSTBOLT_1) &&
                doCast(mytar, FROSTBOLT_1))
                return;

            //Pyroblast TODO: PoM
            if (IsSpellReady(PYROBLAST_1, diff) && can_do_fire && dist < CalcSpellMaxRange(PYROBLAST_1) &&
                ((mytar->IsPolymorphed() && (b_attackers.size() < 2 || (*b_attackers.begin()) == mytar)) ||
                me->HasAura(HOT_STREAK_BUFF) || (me->HasAura(PRESENCE_OF_MIND_1) && (GetSpec() != BOT_SPEC_MAGE_ARCANE || !GetSpell(ARCANE_BLAST_1)))))
            {
                if (doCast(mytar, GetSpell(PYROBLAST_1)))
                    return;
            }
            //Scorch
            if (IsSpellReady(SCORCH_1, diff) && can_do_fire && GetSpec() == BOT_SPEC_MAGE_FIRE && dist < CalcSpellMaxRange(SCORCH_1) && me->GetLevel() >= 25 &&
                !mytar->GetAuraEffect(SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE, SPELLFAMILY_MAGE, 0x0, 0x2000, 0x0))
            {
                if (doCast(mytar, GetSpell(SCORCH_1)))
                    return;
            }
            //Living Bomb
            if ((!mytar->IsControlledByPlayer() || fbCasted) && IsSpellReady(LIVING_BOMB_1, diff) && can_do_fire && dist < CalcSpellMaxRange(LIVING_BOMB_1) &&
                mytar->GetHealth() > me->GetHealth() / 2 * mytar->getAttackers().size() &&
                Rand() < 115 && !mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_MAGE, 0x0, 0x20000, 0x0, me->GetGUID()))
            {
                if (doCast(mytar, GetSpell(LIVING_BOMB_1)))
                    return;
            }
            //Fire Blast (do not waste mana in raids)
            if (IsSpellReady(FIRE_BLAST_1, diff) && can_do_fire && dist < CalcSpellMaxRange(FIRE_BLAST_1) &&
                mytar->GetHealth() < me->GetMaxHealth()*4 && (fbCasted || mytar->GetHealth() < me->GetMaxHealth() / 4) &&
                Rand() < (30 + 40*fbCasted + 80*(!mytar->IsFrozen() && !mytar->HasUnitState(UNIT_STATE_STUNNED) && me->HasAura(IMPACT_BUFF))))
            {
                if (doCast(mytar, GetSpell(FIRE_BLAST_1)))
                    return;
            }
            //Deep Freeze (damage only)
            if (fbCasted && IsSpellReady(DEEP_FREEZE_1, diff) && can_do_frost && dist < CalcSpellMaxRange(DEEP_FREEZE_1) && Rand() < 30 &&
                IsImmunedToMySpellEffect(mytar, sSpellMgr->GetSpellInfo(DEEP_FREEZE_1), EFFECT_0) && (mytar->IsFrozen() || me->HasAuraType(SPELL_AURA_ABILITY_IGNORE_AURASTATE)))
            {
                if (doCast(mytar, GetSpell(DEEP_FREEZE_1)))
                    return;
            }
            //Flamestrike (instant cast only)
            if (/*fbCasted && */IsSpellReady(FLAMESTRIKE_1, diff) && can_do_fire && dist < CalcSpellMaxRange(FLAMESTRIKE_1) && Rand() < 80 &&
                me->HasAura(FIRESTARTER_BUFF))
            {
                if (doCast(mytar, GetSpell(FLAMESTRIKE_1)))
                    return;
            }
            //Blizzard
            if (IsSpellReady(BLIZZARD_1, diff) && !JumpingOrFalling() && Rand() < 50)
            {
                if (Unit* blizztarget = FindAOETarget(CalcSpellMaxRange(BLIZZARD_1)))
                {
                    if (doCast(blizztarget, GetSpell(BLIZZARD_1)))
                        return;
                }

                SetSpellCooldown(BLIZZARD_1, 1500); //fail
            }
            //Ice Lance (no cd, only GCD)
            if (fbCasted && (!me->GetMap()->IsDungeon() || mytar->IsControlledByPlayer()) &&
                IsSpellReady(ICE_LANCE_1, diff) && can_do_frost && dist < CalcSpellMaxRange(ICE_LANCE_1) &&
                (mytar->IsFrozen() || me->HasAuraType(SPELL_AURA_ABILITY_IGNORE_AURASTATE)))
            {
                if (doCast(mytar, GetSpell(ICE_LANCE_1)))
                    return;
            }
            //Fireball or Frostfire Bolt (instant cast or combustion use up)
            if (/*fbCasted && */IsSpellReady(FROSTFIREBOLT, diff) && (can_do_frost | can_do_fire) && dist < CalcSpellMaxRange(FROSTFIREBOLT) && Rand() < 150 &&
                ((((CCed(mytar, true) || b_attackers.empty()) && me->HasAura(COMBUSTION_BUFF)) || me->HasAura(BRAIN_FREEZE_BUFF)) ||
                !GetSpell(FROSTBOLT_1))) //level 1-3
            {
                if (doCast(mytar, GetSpell(FROSTFIREBOLT)))
                    return;
            }
            //Main rotation
            //Arcane Missiles (arcane spec only)
            if (IsSpellReady(ARCANEMISSILES_1, diff) && can_do_arcane && GetSpec() == BOT_SPEC_MAGE_ARCANE && dist < CalcSpellMaxRange(ARCANEMISSILES_1) &&
                (me->GetLevel() < 45 ||
                ((!GetSpell(ARCANE_BLAST_1) || arcaneBlastStack >= 3 || sSpellMgr->GetSpellInfo(ARCANE_BLAST_1)->CalcPowerCost(me, SPELL_SCHOOL_MASK_ARCANE) > int(me->GetPower(POWER_MANA))) &&
                me->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x2, 0x0))))
            {
                if (doCast(mytar, GetSpell(ARCANEMISSILES_1)))
                    return;
            }
            if (IsSpellReady(ARCANE_BLAST_1, diff) && can_do_arcane && GetSpec() == BOT_SPEC_MAGE_ARCANE && dist < CalcSpellMaxRange(ARCANE_BLAST_1) &&
                (arcaneBlastStack < 4 || !me->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x2, 0x0)))
            {
                if (doCast(mytar, GetSpell(ARCANE_BLAST_1)))
                    return;
            }
            if (GetSpec() != BOT_SPEC_MAGE_ARCANE || !GetSpell(ARCANE_BLAST_1))
            {
                if (IsSpellReady(FROSTFIREBOLT, diff) && (can_do_frost | can_do_fire) && (GetSpec() == BOT_SPEC_MAGE_FIRE ||
                    (GetSpec() == BOT_SPEC_MAGE_FROST && (FROSTFIREBOLT == FROSTFIRE_BOLT_1 || !GetSpell(FROSTBOLT_1)))) &&
                    dist < CalcSpellMaxRange(FROSTFIREBOLT))
                {
                    if (doCast(mytar, GetSpell(FROSTFIREBOLT)))
                        return;
                }

                if (IsSpellReady(FROSTBOLT_1, diff) && can_do_frost && GetSpec() != BOT_SPEC_MAGE_FIRE && dist < CalcSpellMaxRange(FROSTBOLT_1))
                {
                    if (doCast(mytar, GetSpell(FROSTBOLT_1)))
                        return;
                }
                if (IsSpellReady(FIREBALL_1, diff) && can_do_fire && GetSpec() == BOT_SPEC_DEFAULT && dist < CalcSpellMaxRange(FIREBALL_1))
                {
                    if (doCast(mytar, GetSpell(FIREBALL_1)))
                        return;
                }
            }

            if (Spell const* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            {
                if (shot->GetSpellInfo()->Id == SHOOT_WAND && shot->m_targets.GetUnitTarget() != mytar)
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }
            else if (IsSpellReady(SHOOT_WAND, diff) && !me->isMoving() && me->GetDistance(mytar) < 30 && GetEquips(BOT_SLOT_RANGED) &&
                doCast(mytar, SHOOT_WAND))
                return;
        }

        void CheckPoly(uint32 diff)
        {
            if (polyCheckTimer <= diff)
            {
                poly = FindAffectedTarget(GetSpell(POLYMORPH_1), me->GetGUID());
                polyCheckTimer = 2000;
            }
        }

        void CheckPolymorph(uint32 diff)
        {
            if (poly == false && IsSpellReady(POLYMORPH_1, diff) && !IsCasting())
            {
                if (Unit* target = FindPolyTarget(CalcSpellMaxRange(POLYMORPH_1)))
                {
                    if (doCast(target, GetSpell(POLYMORPH_1)))
                        return;
                }
            }
        }

        void CheckPots(uint32 diff)
        {
            if (me->IsMounted() || IsCasting())
                return;

            if (IsPotionReady())
            {
                if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }
            if (Rand() < 35)
            {
                if (IsSpellReady(EVOCATION_1, diff) && GetManaPCT(me) < 15 && uint8(me->getAttackers().size()) < (shielded ? 3 : 1))
                {
                    if (doCast(me, GetSpell(EVOCATION_1)))
                        return;
                }
                if (manaGemCharges > 0 && GetManaPCT(me) < 50 && IsSpellReady(MANA_GEM_1, diff, false))
                {
                    if (doCast(me, GetSpell(MANA_GEM_1)))
                        return;
                }
                if (IsPotionReady() && GetManaPCT(me) < 40)
                    DrinkPotion(true);
            }
        }

        void CheckBlink(uint32 diff)
        {
            if (!me->IsAlive())
                return;
            if (me->GetVehicle())
                return;
            if (HasBotCommandState(BOT_COMMAND_STAY) || me->IsMounted())
                return;
            if (!IsSpellReady(BLINK_1, diff) || IsCasting() || Rand() > 70)
                return;

            bool cast = false;
            Unit* u = nullptr;
            if (!IAmFree())
            {
                if (!me->IsInCombat() && me->GetExactDist2d(master) > std::max<uint8>(master->GetBotMgr()->GetBotFollowDist(), 35) &&
                    me->HasInArc(float(M_PI)*0.67f, master))
                {
                    cast = true;
                }
            }
            if (!cast && me->IsInCombat() && !me->getAttackers().empty() && HasRole(BOT_ROLE_RANGED))
            {
                cast = me->HasAuraWithMechanic((1<<MECHANIC_STUN)|(1<<MECHANIC_ROOT));
                if (!cast)
                {
                    u = me->SelectNearestTarget(7);
                    cast = (u && u->GetVictim() == me && u->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2));
                }
                if (!cast)
                {
                    u = (*me->getAttackers().begin());
                    cast = (u && (!CCed(u, true) || me->getAttackers().size() > 1) && u->GetDistance(me) < 5.f &&
                        u->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2));
                }
            }
            if (!cast && IsWanderer() && (me->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD) || me->HasUnitState(UNIT_STATE_ROOT)))
            {
                u = nullptr;
                InstanceTemplate const* instt = sObjectMgr->GetInstanceTemplate(me->GetMap()->GetId());
                bool map_allows_mount = (!me->GetMap()->IsDungeon() || me->GetMap()->IsBattlegroundOrArena()) && (!instt || instt->AllowMount);
                if (!me->GetVictim() ?
                    (me->IsInCombat() || !map_allows_mount || !IsOutdoors() || IsFlagCarrier(me)) :
                    !me->IsWithinDist(me->GetVictim(), 15.0f + GetSpellAttackRange(true)))
                {
                    Position forwardPos = me->GetFirstCollisionPosition(30.0f, 0.0f);
                    cast = me->GetExactDist2d(forwardPos) > 15.0f;
                }
            }
            if (cast)
            {
                if (u)
                {
                    //turn away from target
                    me->AttackStop();
                    me->SetOrientation(me->GetAbsoluteAngle(u) + float(M_PI) * frand(0.85f, 1.15f));
                }
                if (doCast(me, GetSpell(BLINK_1)))
                    return;
            }
        }

        void CheckFocusMagic(uint32 diff)
        {
            if (fmCheckTimer > diff || GC_Timer > diff || IAmFree() || me->GetLevel() < 20 || IsCasting() || Rand() > 50)
                return;

            uint32 FOCUSMAGIC = GetSpell(FOCUS_MAGIC_1);
            if (!FOCUSMAGIC)
                return;

            if (FindAffectedTarget(FOCUSMAGIC, me->GetGUID(), 70, 3))
            {
                fmCheckTimer = 15000;
                return;
            }

            std::set<Unit*> targets;
            if (Group const* gr = master->GetGroup())
            {
                std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
                for (uint8 i = 0; i < 3 && !targets.empty(); ++i)
                {
                    for (Unit* member : members)
                    {
                        if (!(i == 0 ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                            !member->IsAlive() || member->GetPowerType() != POWER_MANA || me->GetExactDist(member) > 30 ||
                            member->HasAura(FOCUSMAGIC))
                            continue;
                        if (i > 0)
                        {
                            Creature const* bot = member->ToCreature();
                            if (bot->GetBotAI()->HasRole(BOT_ROLE_TANK) ||
                                bot->GetBotClass() == BOT_CLASS_BM || bot->GetBotClass() == BOT_CLASS_HUNTER ||
                                bot->GetBotClass() == BOT_CLASS_SPELLBREAKER || bot->GetBotClass() == BOT_CLASS_DARK_RANGER ||
                                bot->GetBotClass() == BOT_CLASS_SEA_WITCH)
                                continue;
                            if (i < 2 && bot->GetBotAI()->HasRole(BOT_ROLE_DPS))
                                continue;
                        }
                        targets.insert(member);
                    }
                }
            }
            else
            {
                if (master->GetPowerType() == POWER_MANA && me->GetExactDist(master) < 30 && !master->HasAura(FOCUSMAGIC))
                    targets.insert(master);
            }

            if (!targets.empty())
            {
                Unit* target = targets.size() == 1u ? *targets.begin() : Trinity::Containers::SelectRandomContainerElement(targets);
                if (doCast(target, FOCUSMAGIC))
                {
                    fmCheckTimer = 30000;
                    return;
                }
            }

            fmCheckTimer = 5000; //fail
        }

        void CheckIceBlock(uint32 diff)
        {
            if (!me->IsAlive() || GC_Timer > diff || me->GetVehicle() || !GetSpell(ICE_BLOCK_1) || Rand() > 60 || IsTank() || IsFlagCarrier(me))
                return;

            if (iceblockCheckTimer <= diff)
            {
                if (me->getAttackers().empty() && (!me->IsInCombat() || (GetManaPCT(me) > 45 && GetHealthPCT(me) > 80)))
                {
                    me->RemoveAurasDueToSpell(GetSpell(ICE_BLOCK_1));
                    return;
                }
                iceblockCheckTimer = std::numeric_limits<uint32>::max();
            }

            if (!IsSpellReady(ICE_BLOCK_1, diff))
                return;

            if (me->IsInCombat() && !me->getAttackers().empty() &&
                (CCed(me, true) || me->getAttackers().size() > 2 || GetHealthPCT(me) < 40))
            {
                if (doCast(me, GetSpell(ICE_BLOCK_1)))
                    return;
            }
        }

        void CheckColdSnap(uint32 diff)
        {
            if (!IsSpellReady(COLD_SNAP_1, diff) || !me->IsInCombat() || me->IsMounted() || Rand() > 50)
                return;

            //TODO: recheck priorities
            uint32 needFactor = 0;
            uint32 cooldown;
            cooldown = GetSpellCooldown(FROST_NOVA_1);
            needFactor += !cooldown ? 0 : 3 * cooldown / 220;  //0-100 x3
            cooldown = GetSpellCooldown(ICE_BLOCK_1);
            needFactor += !cooldown ? 0 : 3 * cooldown / 2400; //0-100 x3
            cooldown = shielded ? 0 : GetSpellCooldown(ICE_BARRIER_1);
            needFactor += !cooldown ? 0 : 3 * cooldown / 240;  //0-100 x3
            cooldown = GetSpellCooldown(FROST_WARD_1);
            needFactor += !cooldown ? 0 : 2 * cooldown / 300;  //0-100 x2
            cooldown = GetSpellCooldown(ICY_VEINS_1);
            needFactor += !cooldown ? 0 : 2 * cooldown / 1500; //0-100 x2
            cooldown = (botPet && botPet->IsAlive()) ? 0 : GetSpellCooldown(SUMMON_WATER_ELEMENTAL_1);
            needFactor += !cooldown ? 0 : 1 * cooldown / 1500; //0-100
            cooldown = GetSpellCooldown(DEEP_FREEZE_1);
            needFactor += !cooldown ? 0 : 1 * cooldown / 240;  //0-100
            cooldown = GetSpellCooldown(CONE_OF_COLD_1);
            needFactor += !cooldown ? 0 : 1 * cooldown / 80;   //0-100
            //0-1600

            if (needFactor >= 700 && doCast(me, GetSpell(COLD_SNAP_1)))
                return;
        }

        void CheckShield(uint32 diff)
        {
            //TODO: Mana Shield
            if (!GetSpell(ICE_BARRIER_1))
                return;

            if (shieldCheckTimer <= diff)
            {
                shieldCheckTimer = 1500;
                shielded = me->GetTotalAuraModifierByMiscValue(SPELL_AURA_SCHOOL_ABSORB, 127) > 0;
                shielded = shielded ? shielded : me->HasAura(GetSpell(ICE_BARRIER_1));
            }

            if (shielded || !IsSpellReady(ICE_BARRIER_1, diff) || IsCasting())
                return;

            if ((me->IsInCombat() && me->GetMap()->Instanceable()) ||
                !me->getAttackers().empty() || GetHealthPCT(me) < 90)
            {
                if (doCast(me, GetSpell(ICE_BARRIER_1)))
                    return;
            }
        }

        void CheckWard(uint32 diff)
        {
            if ((!me->IsInCombat() && !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) ||
                !IsSpellReady(FROST_WARD_1, diff) || IsCasting())
                return;

            uint32 FROSTWARD = canFrostWard ? GetSpell(FROST_WARD_1) : 0;
            uint32 FIREWARD = canFireWard ? GetSpell(FIRE_WARD_1) : 0;

            if (FIREWARD && doCast(me, FIREWARD))
                return;

            if (FROSTWARD && doCast(me, FROSTWARD))
                return;
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Shatter
            //SHATTER IS HANDLED IN Unit::isSpCrit()

            //Arcane Potency: 15%/30% additional crit chance for All spells
            if (me->HasAura(ARCANE_POTENCY_BUFF2))
                crit_chance += 30.f;
            else if (me->HasAura(ARCANE_POTENCY_BUFF1))
                crit_chance += 15.f;

            //Combustion: 10% additional critical chance for fire spells per stack
            if (SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask())
                if (Aura* combustion = me->GetAura(COMBUSTION_BUFF))
                    crit_chance += float(combustion->GetStackAmount() * 10);

            //Incineration: 6% additional crit chance for Fire Blast, Scorch, Arcane Blast and Cone of Cold
            if (lvl >= 10 &&
                (baseId == FIRE_BLAST_1 || baseId == SCORCH_1 ||
                baseId == ARCANE_BLAST_1 || baseId == CONE_OF_COLD_1))
                crit_chance += 6.f;
            //World In Flames: 6% additional critical chance for Flamestrike, Pyroblast, Blast Wave, Dragon's Breath, Living Bomb, Blizzard and Arcane Explosion
            if (lvl >= 15 &&
                (baseId == FLAMESTRIKE_1 || baseId == PYROBLAST_1 ||
                baseId == BLAST_WAVE_1 || baseId == DRAGON_BREATH_1 ||
                baseId == BLIZZARD_DAMAGE_1/* || spellId == ARCANEXPLOSION*/ ||
                baseId == LIVING_BOMB_1 || baseId == LIVING_BOMB_DAMAGE_1))
                crit_chance += 6.f;
            //Improved Scorch part 1: 3% additional critical chance for Scorch, Fireball and Frostfire Bolt
            if (lvl >= 20 && (baseId == SCORCH_1 || baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1))
                crit_chance += 3.f;
            //Critical Mass: 6% additional critical chance for Fire spells
            if ((GetSpec() == BOT_SPEC_MAGE_FIRE) && lvl >= 30 && (SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask()))
                crit_chance += 6.f;
            //Winter's chill part 1: 3% additional crit chance for Frostbolt
            if ((GetSpec() == BOT_SPEC_MAGE_FROST) && lvl >= 35 && baseId == FROSTBOLT_1)
                crit_chance += 3.f;

            //Glyph of Frostfire Bolt part 2: 2% additional critical chance for Frostfire Bolt
            if (/*lvl >= 75 && */baseId == FROSTFIRE_BOLT_1)
                crit_chance += 2.f;
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Burnout: 50% additional crit damage bonus for All spells
                //well it's gonna be a little too much eh? skipped
                //Ice Shards: 50% additional crit damage bonus for Frost spells
                if (lvl >= 15 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                    pctbonus += 0.334f;
                //Spell Power: 50% additional crit damage bonus for All spells
                if ((GetSpec() == BOT_SPEC_MAGE_ARCANE) && lvl >= 55)
                    pctbonus += 0.334f;
                //Combustion: 50% additional crit damage bonus for Fire spells
                if ((SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask()) && me->HasAura(COMBUSTION_1))
                    pctbonus += 0.334f;
            }

            //Spell Impact: 6% bonus damage for Arcne Explosion, Arcane Blast, Scorch, Fireball, Ice Lance and Cone of Cold
            if (lvl >= 20 &&
                (/*baseId == ARCANE_EXPLOSION_1 || */baseId == SCORCH_1 ||
                baseId == ARCANE_BLAST_1 || baseId == FIREBALL_1 ||
                baseId == ICE_LANCE_1 || baseId == CONE_OF_COLD_1))
                pctbonus += 0.06f;
            //Piercing Ice: 6% bonus damage for Frost spells
            if (lvl >= 20 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                pctbonus += 0.06f;
            //Playing with Fire part 1: 3% bonus damage for all spells
            if ((GetSpec() == BOT_SPEC_MAGE_FIRE) && lvl >= 30)
                pctbonus += 0.03f;
            //Improved Cone of Cold: 35% bonus damage for Cone of Cold
            if ((GetSpec() == BOT_SPEC_MAGE_FROST) && lvl >= 30 && baseId == CONE_OF_COLD_1)
                pctbonus += 0.35f;
            //Arcane Instability part 1: 3% bonus damage for all spells
            if ((GetSpec() == BOT_SPEC_MAGE_ARCANE) && lvl >= 35)
                pctbonus += 0.03f;
            //Fire Power: 10% bonus damage for Fire spells
            if ((GetSpec() == BOT_SPEC_MAGE_FIRE) && lvl >= 35 && (SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask()))
                pctbonus += 0.1f;
            //Arcane Empowerment part 1,2: 45% / 9% bonus damage (from spellpower) for Arcane Missiles / Arcane Blast
            if (GetSpec() == BOT_SPEC_MAGE_ARCANE && lvl >= 40)
            {
                if (baseId == ARCANE_MISSILES_DAMAGE_1)
                    fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.45f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
                else if (baseId == ARCANE_BLAST_1)
                    fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.09f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            }
            //Arcane Power: +20% bonus damage
            if (AuraEffect const* pow = me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x80000, 0x0))
                if (pow->IsAffectingSpell(spellInfo))
                    pctbonus += 0.2f;
            //Molten Fury: 12% bonus damage for All spells against target with less than 35% hp
            if ((GetSpec() == BOT_SPEC_MAGE_FIRE) &&
                lvl >= 40 && damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
                pctbonus += 0.12f;
            //Arctic Winds part 1: 5% bonus damage for Frost spells
            if ((GetSpec() == BOT_SPEC_MAGE_FROST) && lvl >= 40 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                pctbonus += 0.05f;
            //Empowered Fire part 1: 15% bonus damage (from spellpower) for Fireball, Frostfire Bolt and Pyroblast
            if ((GetSpec() == BOT_SPEC_MAGE_FIRE) &&
                lvl >= 45 && (baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1 || baseId == PYROBLAST_1))
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.15f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            //Empowered Frostbolt part 1: 10% of spellpower to Frostbolt damage
            if ((GetSpec() == BOT_SPEC_MAGE_FROST) && lvl >= 45 && baseId == FROSTBOLT_1)
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.1f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            //Chilled to the Bone part 1: 5% bonus damage for Frostbolt, Frostfire Bolt and Ice Lance
            if ((GetSpec() == BOT_SPEC_MAGE_FROST) &&
                lvl >= 55 && (baseId == FROSTBOLT_1 || baseId == FROSTFIRE_BOLT_1 || baseId == ICE_LANCE_1))
                pctbonus += 0.05f;

            //Glyph of Frostfire Bolt part 1: 2% bonus damage for Frostfire Bolt
            if (/*lvl >= 75 && */baseId == FROSTFIRE_BOLT_1)
                pctbonus += 0.02f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //Firestarter part 2: -100% mana cost for Flamestrike
            if (baseId == FLAMESTRIKE_1)
                if (me->HasAura(FIRESTARTER_BUFF))
                    pctbonus += 1.0f;
            //Brain Freeze buff: -100% mana cost for Fireball and Frostfire Bolt while active
            //we can check spellFamilyFlags or just use ids, going easy way here
            if (baseId == FROSTFIRE_BOLT_1 || baseId == FIREBALL_1)
                if (me->HasAura(BRAIN_FREEZE_BUFF))
                    pctbonus += 1.0f;
            //Clearcasting: -100% mana cost for damaging spells
            if (AuraEffect const* eff = me->GetAuraEffect(ARCANE_CONCENTRATION_BUFF, 0, me->GetGUID()))
                if (eff->IsAffectingSpell(spellInfo))
                    pctbonus += 1.0f;
            //Missile Barrage: -100% mana cost for Arcane Missiles
            if (baseId == ARCANEMISSILES_1)
                if (me->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x2, 0x0))
                    pctbonus += 1.0f;

            //pct mods
            //Precision part 1: -3% mana cost for All spells
            if (lvl >= 15)
                pctbonus += 0.03f;
            //Frost Channeling: -10% mana cost for all spells
            if (lvl >= 25)
                pctbonus += 0.1f;
            //Improved Blink part 1: -50% mana cost for Blink
            if ((GetSpec() == BOT_SPEC_MAGE_ARCANE) && lvl >= 30 && baseId == BLINK_1)
                pctbonus += 0.5f;

            //Arcane Blast: +175% mana cost for Arcane Blast (per stack)
            if (baseId == ARCANE_BLAST_1)
                if (AuraEffect const* bla = me->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_MAGE, 0x0, 0x0, 0xC))
                    pctbonus += -1.75f * bla->GetBase()->GetStackAmount();
            //Arcane Power: +20% mana cost
            if (AuraEffect const* pow = me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x80000, 0x0))
                if (pow->IsAffectingSpell(spellInfo))
                    pctbonus += -0.2f;

            //Glyph of Arcane Intellect: -50% mana cost for Arcane Intellect/Brilliance
            if (lvl >= 15 && baseId == ARCANEINTELLECT_1)
                pctbonus += 0.5f;
            //Glyph of Blast Wave part 1: -15% mana cost for Blast Wave
            if (lvl >= 70 && baseId == BLAST_WAVE_1)
                pctbonus += 0.15f;

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
            //Firestarter part 1: -100% cast time for Flamestrike
            if (baseId == FLAMESTRIKE_1)
                if (me->HasAura(FIRESTARTER_BUFF))
                    timebonus += casttime;
            //Brain Freeze: -100% cast time for Fireball and Frostfire Bolt
            //we can check spellFamilyFlags or just use ids, going easy way here
            if (baseId == FROSTFIRE_BOLT_1 || baseId == FIREBALL_1)
                if (me->HasAura(BRAIN_FREEZE_BUFF))
                    timebonus += casttime;
            //Hot Streak: -100% cast time for Pyroblast
            if (baseId == PYROBLAST_1)
                if (me->HasAura(HOT_STREAK_BUFF))
                    timebonus += casttime;
            //Presence of Mind: -100% cast time
            if (AuraEffect const* eff = me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x20, 0x0))
                if (eff->IsAffectingSpell(spellInfo))
                    timebonus += casttime;

            //flat mods
            //Improved Fireball: -0.5 sec cast time for Fireball (Frostfire too for bot)
            if (lvl >= 10 && (baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1))
                timebonus += 500;
            //Improved Frostbolt: -0.5 sec cast time for Frostbolt
            if (lvl >= 10 && baseId == FROSTBOLT_1)
                timebonus += 500;
            //Empowered Frostbolt part 2: -0.2 sec cast time for Frostbolt
            if (lvl >= 45 && baseId == FROSTBOLT_1)
                timebonus += 200;

            //Missile Barrage: -2.5 sec channeling time, -0.5 sec for every tick
            if (baseId == ARCANEMISSILES_1 && me->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x2, 0x0))
                timebonus += casttime / 2;

            casttime = std::max<int32>(casttime - timebonus, 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Ice Floes: -20% cooldown for Frost Nova, Cone of Cold, Ice Block and Icy Veins
            if (lvl >= 10 &&
                (baseId == FROST_NOVA_1 || baseId == CONE_OF_COLD_1 || baseId == ICE_BLOCK_1 || baseId == ICY_VEINS_1))
                pctbonus += 0.2f;
            //Cold as Ice: -20% cooldown for Ice Barrier, Cold Snap and Summon Water Elemental
            if ((GetSpec() == BOT_SPEC_MAGE_FROST) && lvl >= 35 &&
                (baseId == ICE_BARRIER_1 || baseId == COLD_SNAP_1 || baseId == SUMMON_WATER_ELEMENTAL_1))
                pctbonus += 0.2f;

            //flat mods
            //Improved Fire Blast: -2 sec cooldown for Fire Blast
            if (lvl >= 10 && baseId == FIRE_BLAST_1)
                timebonus += 2000;
            //Arcane Flows part 2: -2 min cooldown for Evocation
            if ((GetSpec() == BOT_SPEC_MAGE_ARCANE) && lvl >= 45 && baseId == EVOCATION_1)
                timebonus += 120000;
            //Glyph of Water Elemental: -30 sec cooldown for Summon Water Elemental
            if (lvl >= 50 && baseId == SUMMON_WATER_ELEMENTAL_1)
                timebonus += 30000;

            ////Pyroblast (special): ensure no double pyroblast casts
            //if (baseId == PYROBLAST_1)
            //    timebonus -= 3000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Increased Area (AhnQ set bonus?) 23549
            if (lvl >= 60 && (spellInfo->SpellFamilyFlags[0] & 0x1084))
                pctbonus += 0.25f;
            //Arctic Reach
            if (lvl >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x240))
                pctbonus += 0.2f;

            //flat mods
            //Glyph of Blink
            if (lvl >= 20 && baseId == BLINK_1)
                flatbonus += 5.f;

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
            //Arctic Reach: +20% range for Frost Spells
            if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x200A0) || (spellInfo->SpellFamilyFlags[1] & 0x100000)))
                pctbonus += 0.2f;

            //flat mods
            //Magic Attunement: +6 yd range for Arcane Spells
            if (lvl >= 20 && ((spellInfo->SpellFamilyFlags[0] & 0xA1006C00) || (spellInfo->SpellFamilyFlags[1] & 0x8010)))
                flatbonus += 6.f;
            //Flame Throwing: +6 yd range for Fire Spells
            if (lvl >= 20 && ((spellInfo->SpellFamilyFlags[0] & 0x400017) || (spellInfo->SpellFamilyFlags[1] & 0x20000)))
                flatbonus += 6.f;

            //Glyph of Deep Freeze
            if (lvl >= 60 && baseId == DEEP_FREEZE_1)
                flatbonus += 10.f;

            //Mage Fire Blast Range Bonus (33066): +6 yd range for Fire Blast
            if (lvl >= 60 && baseId == FIRE_BLAST_1)
                flatbonus += 6.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            //DEBUG
            //if (!IAmFree())
            //{
            //    std::ostringstream msg;
            //    msg << "OnClassSpellGo: " << spellInfo->SpellName[0] << " (" << spellId << ")!";
            //    BotWhisper(msg.str().c_str());
            //}

            if (baseId == SUMMON_WATER_ELEMENTAL_1)
                SummonBotPet();

            //Mana gem conjure and use
            if (baseId == CONJURE_MANA_GEM_1)
            {
                //ItemTemplate const* gem = sObjectMgr->GetItemTemplate(spellInfo->_effects[0].ItemType);
                //ASSERT(gem);
                //manaGemCharges = uint8(abs(gem->Spells[1].SpellCharges)); //at index 1

                //Do not bother with this crap
                manaGemCharges = 3;
            }
            if (baseId == MANA_GEM_1)
            {
                //spell cd is 1 min, item cd is 2 min, correct here
                SetSpellCooldown(MANA_GEM_1, 120000);
                manaGemCharges -= 1;
            }

            //special cases
            //Pyroblast (special): ensure no double pyroblast casts
            if (baseId == PYROBLAST_1)
                SetSpellCooldown(PYROBLAST_1, 3000);

            if (baseId == ICE_BLOCK_1)
            {
                //Glyph of Ice Block: reset Frost Nova cd
                ResetSpellCooldown(FROST_NOVA_1);
                iceblockCheckTimer = 4000;
            }

            //check for minor rotation thingy (skip common triggered on-hit spells
            /*if (spellId != FROSTBITE_TRIGGERED && spellId != WINTERS_CHILL_TRIGGERED && spellId != IGNITE_TRIGGERED &&
                spellId != ARCANE_CONCENTRATION_BUFF && spellId != ARCANE_POTENCY_BUFF1 && spellId != ARCANE_POTENCY_BUFF2 &&
                spellId != FIRESTARTER_BUFF && spellId != BRAIN_FREEZE_BUFF && spellId != HOT_STREAK_BUFF)*/
                fbCasted = (baseId == SCORCH_1 || baseId == FROSTBOLT_1 || baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1);

            //Handle clearcasting
            if (AuraEffect const* eff = me->GetAuraEffect(ARCANE_CONCENTRATION_BUFF, 0, me->GetGUID()))
            {
                if (eff->IsAffectingSpell(spellInfo))
                {
                    //if (int32 cost = spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()))
                    {
                        //me->ModifyPower(POWER_MANA, cost > 0 ? cost : 0);
                        me->RemoveAurasDueToSpell(ARCANE_CONCENTRATION_BUFF);
                    }
                    //arcane potency has the same affection (damaging spells only)
                    me->RemoveAurasDueToSpell(ARCANE_POTENCY_BUFF1);
                    me->RemoveAurasDueToSpell(ARCANE_POTENCY_BUFF2);
                }
            }
            //Handle Presence of Mind
            bool consumed_Pom = false;
            if (AuraEffect const* eff = me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x20, 0x0))
            {
                if (eff->IsAffectingSpell(spellInfo))
                {
                    me->RemoveAurasDueToSpell(PRESENCE_OF_MIND_1);
                    consumed_Pom = true;
                }
            }
            if (!consumed_Pom)
            {
                //Firestarter
                if (baseId == FLAMESTRIKE_1)
                    me->RemoveAurasDueToSpell(FIRESTARTER_BUFF);
                //Brain Freeze (Fireball!)
                if (baseId == FROSTFIRE_BOLT_1 || baseId == FIREBALL_1)
                    me->RemoveAurasDueToSpell(BRAIN_FREEZE_BUFF);
                //Hot Streak
                if (baseId == PYROBLAST_1)
                    me->RemoveAurasDueToSpell(HOT_STREAK_BUFF);
            }
            //Handle Cold Snap
            if (baseId == COLD_SNAP_1)
            {
                SpellInfo const* cdInfo;
                BotSpellMap const& myspells = GetSpellMap();
                for (BotSpellMap::const_iterator itr = myspells.begin(); itr != myspells.end(); ++itr)
                {
                    if (itr->first == baseId)
                        continue;
                    if (itr->second->spellId != 0 && itr->second->cooldown > 0)
                    {
                        cdInfo = sSpellMgr->GetSpellInfo(itr->first);
                        if (cdInfo && cdInfo->SpellFamilyName == SPELLFAMILY_MAGE && cdInfo->GetRecoveryTime() > 0 &&
                            (cdInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST))
                            ResetSpellCooldown(itr->first);
                    }
                }
            }

            //Missile Barrage
            if (baseId == ARCANEMISSILES_1)
                me->RemoveAurasDueToSpell(MISSILE_BARRAGE_BUFF);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            if (aftercastTargetGuid != ObjectGuid::Empty)
            {
                //only players for now
                if (!aftercastTargetGuid.IsPlayer())
                {
                    aftercastTargetGuid = ObjectGuid::Empty;
                    return;
                }

                Player* pTarget = ObjectAccessor::GetPlayer(*me, aftercastTargetGuid);
                aftercastTargetGuid = ObjectGuid::Empty;

                if (!pTarget/* || me->GetDistance(pTarget) > 15*/)
                    return;

                //handle effects
                for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
                {
                    switch (spell->_effects[i].Effect)
                    {
                        case SPELL_EFFECT_CREATE_ITEM:
                        case SPELL_EFFECT_CREATE_ITEM_2:
                        {
                            uint32 newitemid = spell->_effects[i].ItemType;
                            if (newitemid)
                            {
                                ItemPosCountVec dest;
                                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(newitemid);
                                if (!pProto)
                                    return;
                                uint32 count = pProto->GetMaxStackSize();
                                uint32 no_space = 0;
                                InventoryResult msg = pTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, newitemid, count, &no_space);
                                if (msg != EQUIP_ERR_OK)
                                {
                                    if (msg == EQUIP_ERR_INVENTORY_FULL || msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
                                        count -= no_space;
                                    else
                                    {
                                        // if not created by another reason from full inventory or unique items amount limitation
                                        pTarget->SendEquipError(msg, nullptr, nullptr, newitemid);
                                        continue;
                                    }
                                }
                                if (count)
                                {
                                    Item* pItem = pTarget->StoreNewItem(dest, newitemid, true, 0);
                                    if (!pItem)
                                    {
                                        pTarget->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
                                        continue;
                                    }

                                    pTarget->SendNewItem(pItem, count, true, false, true);
                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }

                return;
            }

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            if (baseId == ARCANEINTELLECT_1)
            {
                if (Aura* arc = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = HOUR * IN_MILLISECONDS;
                    arc->SetDuration(dur);
                    arc->SetMaxDuration(dur);
                }
            }

            //Spells with chill effect
            //chill amount by spell family mask
            //00100000 00000000 00000000 chilled (blizzard)
            //00000200 00000000 00000000 conecold
            //00000020 00000000 00000000 frbolt
            //00000000 00001000 00000008 ffbolt
            //00100220 00001000 00000000 permafrst
            //00100220 00001000 00000000 cttbn
            if (spell->SpellFamilyName == SPELLFAMILY_MAGE &&
                ((spell->SpellFamilyFlags[0] & 0x100220) || (spell->SpellFamilyFlags[1] & 0x1000)))
            {
                //frostbolt, cone of cold, blizzard chill, frostfire bolt
                Aura* chill = target->GetAura(spellId, me->GetGUID());
                if (chill)
                {
                    //Permafrost: chill effects duration + 3 sec
                    if (lvl >= 15)
                    {
                        uint32 dur = chill->GetDuration() + 3000;
                        chill->SetDuration(dur);
                        chill->SetMaxDuration(dur);
                    }
                    //chill effect is at index 0
                    AuraEffect* chillEff = chill->GetEffect(0);
                    if (chillEff)
                    {
                        int32 amount = chillEff->GetAmount();
                        if (lvl >= 15)
                            amount -= 10; //permafrost
                        if ((GetSpec() == BOT_SPEC_MAGE_FROST) && lvl >= 55)
                            amount -= 10; //chilled to the bone
                        chillEff->ChangeAmount(amount);
                    }
                }
            }

            //Glyph of Ice Barrier: 30% increased effect
            if (baseId == ICE_BARRIER_1)
            {
                shielded = true;
                if (lvl >= 46)
                {
                    AuraEffect* barr = me->GetAuraEffect(spellId, 0);
                    if (barr)
                        barr->ChangeAmount(barr->GetAmount() * 1.3f);
                }
            }

            //Custom things
            if (baseId == POLYMORPH_1)
            {
                poly = true;
                polyCheckTimer = 2000;
            }

            //Winter Veil addition
            if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
            {
                if (SPELL_SCHOOL_MASK_FROST & spell->GetSchoolMask())
                    me->AddAura(44755, target); //snowflakes

                //if (baseId == FROSTBOLT_1 && urand(1,100) <= 10)
                //    me->CastSpell(target, 25686, true); //10% super snowball
            }

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;

            if (baseId == ARCANE_BLAST_DEBUFF)
                if (Aura* blas = me->GetAura(spell->Id))
                    arcaneBlastStack = blas->GetStackAmount();

            //Ward helper
            if (spell->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) || spell->HasAura(SPELL_AURA_PERIODIC_DAMAGE))
            {
                if (!canFrostWard && (spell->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST))
                    canFrostWard = true;
                if (!canFireWard && (spell->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE))
                    canFireWard = true;
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

        void SummonBotPet()
        {
            if (botPet)
                UnsummonAll(false);

            uint32 entry = BOT_PET_WATER_ELEMENTAL;

            Position pos;

            //glyphed: permanent
            Creature* myPet = me->SummonCreature(entry, *me, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3s);
            me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 2, me->GetOrientation());
            myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            myPet->SetCreator(master);
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, SUMMON_WATER_ELEMENTAL_1);

            botPet = myPet;
        }

        void UnsummonAll(bool savePets = true) override
        {
            UnsummonPet(savePets);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: {}'s {}", me->GetName(), summon->GetName());
            if (summon == botPet)
                botPet = nullptr;
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_WATER_ELEMENTAL;
                default:
                    return 0;
            }
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(FROSTBOLT_1) : 20.f;
        }

        void Reset() override
        {
            UnsummonAll(false);

            polyCheckTimer = 0;
            fmCheckTimer = 0;
            iceblockCheckTimer = 0;
            shieldCheckTimer = 0;
            arcaneBlastStack = 0;
            manaGemCharges = 0;

            poly = false;
            shielded = false;
            fbCasted = false;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (polyCheckTimer > diff)              polyCheckTimer -= diff;
            if (fmCheckTimer > diff)                fmCheckTimer -= diff;
            if (iceblockCheckTimer > diff)          iceblockCheckTimer -= diff;
            if (shieldCheckTimer > diff)            shieldCheckTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            //bool isArca = GetSpec() == BOT_SPEC_MAGE_ARCANE;
            bool isFire = GetSpec() == BOT_SPEC_MAGE_FIRE;
            bool isFros = GetSpec() == BOT_SPEC_MAGE_FROST;

            InitSpellMap(DAMPENMAGIC_1);
            InitSpellMap(AMPLIFYMAGIC_1);
            InitSpellMap(ARCANEINTELLECT_1);
            InitSpellMap(ARCANEMISSILES_1);
            InitSpellMap(ARCANE_BLAST_1);
            InitSpellMap(POLYMORPH_1);
            InitSpellMap(COUNTERSPELL_1);
            InitSpellMap(SPELLSTEAL_1);
            InitSpellMap(EVOCATION_1);
            InitSpellMap(BLINK_1);
            InitSpellMap(REMOVE_CURSE_1);
            InitSpellMap(INVISIBILITY_1);
            InitSpellMap(SCORCH_1);
            InitSpellMap(FIRE_BLAST_1);
            InitSpellMap(FLAMESTRIKE_1);
            InitSpellMap(DAMPENMAGIC_1);
            InitSpellMap(FROSTBOLT_1);
            InitSpellMap(FROST_NOVA_1);
            InitSpellMap(CONE_OF_COLD_1);
            InitSpellMap(BLIZZARD_1);
            InitSpellMap(FROST_ARMOR_1);
            InitSpellMap(ICE_ARMOR_1);
            InitSpellMap(MOLTEN_ARMOR_1);
            InitSpellMap(ICE_BLOCK_1);
 /*Special*/InitSpellMap(BLIZZARD_DAMAGE_1); //important
 /*Special*/InitSpellMap(LIVING_BOMB_DAMAGE_1); //important
            InitSpellMap(SLOW_FALL_1);
            InitSpellMap(ICE_LANCE_1);
            InitSpellMap(FROST_WARD_1);
            InitSpellMap(FIRE_WARD_1);
            InitSpellMap(MIRROR_IMAGE_1);

 /*Special*/InitSpellMap(CONJURE_MANA_GEM_1);
 /*Special*/InitSpellMap(MANA_GEM_1);

            InitSpellMap(RITUAL_OF_REFRESHMENT_1); //not casted

  /*Talent*/lvl >= 20 ? InitSpellMap(FOCUS_MAGIC_1) : RemoveSpell(FOCUS_MAGIC_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(PRESENCE_OF_MIND_1) : RemoveSpell(PRESENCE_OF_MIND_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(ARCANE_POWER_1) : RemoveSpell(ARCANE_POWER_1);

  /*Talent*/lvl >= 20 ? InitSpellMap(PYROBLAST_1) : RemoveSpell(PYROBLAST_1);
  /*Talent*/lvl >= 30 && isFire ? InitSpellMap(BLAST_WAVE_1) : RemoveSpell(BLAST_WAVE_1);
  /*Talent*/lvl >= 40 && isFire ? InitSpellMap(DRAGON_BREATH_1) : RemoveSpell(DRAGON_BREATH_1);
  /*Talent*/lvl >= 50 && isFire ? InitSpellMap(COMBUSTION_1) : RemoveSpell(COMBUSTION_1);
  /*Talent*/lvl >= 60 && isFire ? InitSpellMap(LIVING_BOMB_1) : RemoveSpell(LIVING_BOMB_1);

  /*Talent*/lvl >= 20 ? InitSpellMap(ICY_VEINS_1) : RemoveSpell(ICY_VEINS_1);
  /*Talent*/lvl >= 30 && isFros ? InitSpellMap(COLD_SNAP_1) : RemoveSpell(COLD_SNAP_1);
  /*Talent*/lvl >= 40 && isFros ? InitSpellMap(ICE_BARRIER_1) : RemoveSpell(ICE_BARRIER_1);
  /*Talent*/lvl >= 50 && isFros ? InitSpellMap(SUMMON_WATER_ELEMENTAL_1) : RemoveSpell(SUMMON_WATER_ELEMENTAL_1);
  /*Talent*/lvl >= 60 && isFros ? InitSpellMap(DEEP_FREEZE_1) : RemoveSpell(DEEP_FREEZE_1);

            InitSpellMap(FROSTFIRE_BOLT_1);
            InitSpellMap(FIREBALL_1);
            FROSTFIREBOLT = GetSpell(FROSTFIRE_BOLT_1) ? FROSTFIRE_BOLT_1 : FIREBALL_1;
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isArca = GetSpec() == BOT_SPEC_MAGE_ARCANE;
            bool isFire = GetSpec() == BOT_SPEC_MAGE_FIRE;
            bool isFros = GetSpec() == BOT_SPEC_MAGE_FROST;

            RefreshAura(ARCANE_CONCENTRATION, level >= 15 ? 1 : 0);
            RefreshAura(ARCANE_MEDITATION, level >= 25 ? 1 : 0); //mana regen 1
            RefreshAura(TORMENT_THE_WEAK, level >= 25 ? 1 : 0);
            RefreshAura(IMPROVED_COUNTERSPELL2, isArca && level >= 26 ? 1 : 0);
            RefreshAura(IMPROVED_COUNTERSPELL1, isArca && level >= 25 && level < 26 ? 1 : 0);
            RefreshAura(ARCANE_POTENCY2, isArca && level >= 36 ? 1 : 0);
            RefreshAura(ARCANE_POTENCY1, isArca && level >= 35 && level < 36 ? 1 : 0);
            RefreshAura(ARCANE_EMPOWERMENT, isArca && level >= 40 ? 1 : 0);
            RefreshAura(INCANTERS_ABSORPTION3, isArca && level >= 42 ? 1 : 0);
            RefreshAura(INCANTERS_ABSORPTION2, isArca && level >= 41 && level < 42 ? 1 : 0);
            RefreshAura(INCANTERS_ABSORPTION1, isArca && level >= 40 && level < 41 ? 1 : 0);
            RefreshAura(MISSILE_BARRAGE, isArca && level >= 45 ? 1 : 0);

            RefreshAura(IGNITE, level >= 15 ? 1 : 0);
            RefreshAura(BURNING_DETERMINATION, level >= 15 ? 1 : 0);
            RefreshAura(IMPACT, level >= 20 ? 1 : 0);
            RefreshAura(IMPROVED_SCORCH, level >= 25 ? 1 : 0);
            RefreshAura(MOLTEN_SHIELDS, level >= 25 ? 1 : 0);
            RefreshAura(MASTER_OF_ELEMENTS, level >= 25 ? 1 : 0);
            RefreshAura(BLAZING_SPEED, isFire && level >= 35 ? 1 : 0);
            RefreshAura(PYROMANIAC, isFire && level >= 40 ? 1 : 0); //mana regen 2
            RefreshAura(FIRESTARTER2, isFire && level >= 51 ? 1 : 0);
            RefreshAura(FIRESTARTER1, isFire && level >= 50 && level < 51 ? 1 : 0);
            RefreshAura(HOT_STREAK, isFire && level >= 50 ? 1 : 0);

            RefreshAura(FROSTBITE3, level >= 12 ? 1 : 0);
            RefreshAura(FROSTBITE2, level >= 11 && level < 12 ? 1 : 0);
            RefreshAura(FROSTBITE1, level >= 10 && level < 11 ? 1 : 0);
            RefreshAura(FROST_WARDING, level >= 15 ? 1 : 0);
            RefreshAura(IMPROVED_BLIZZARD, level >= 20 ? 1 : 0);
            RefreshAura(SHATTER3, level >= 27 ? 1 : 0);
            RefreshAura(SHATTER2, level >= 26 && level < 27 ? 1 : 0);
            RefreshAura(SHATTER1, level >= 25 && level < 26 ? 1 : 0);
            RefreshAura(WINTERS_CHILL3, isFros && level >= 37 ? 1 : 0);
            RefreshAura(WINTERS_CHILL2, isFros && level >= 36 && level < 37 ? 1 : 0);
            RefreshAura(WINTERS_CHILL1, isFros && level >= 35 && level < 36 ? 1 : 0);
            RefreshAura(SHATTERED_BARRIER, isFros && level >= 45 ? 1 : 0);
            //RefreshAura(ARCTIC_WINDS, isFros && level >= 45 ? 1 : 0); //only miss chance
            RefreshAura(FINGERS_OF_FROST, isFros && level >= 45 ? 1 : 0);
            RefreshAura(BRAIN_FREEZE3, isFros && level >= 53 ? 1 : 0);
            RefreshAura(BRAIN_FREEZE2, isFros && level >= 51 && level < 52 ? 1 : 0);
            RefreshAura(BRAIN_FREEZE1, isFros && level >= 50 && level < 51 ? 1 : 0);

            RefreshAura(GLYPH_POLYMORPH, level >= 15 ? 1 : 0);
            RefreshAura(GLYPG_REMOVE_CURSE, level >= 18 ? 1 : 0);
            RefreshAura(GLYPH_ICY_VEINS, level >= 20 ? 1 : 0);
            RefreshAura(GLYPH_LIVING_BOMB, level >= 60 ? 1 : 0);
            RefreshAura(GLYPH_ICE_LANCE, level >= 66 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case DAMPENMAGIC_1:
                case AMPLIFYMAGIC_1:
                case ARCANEINTELLECT_1:
                case EVOCATION_1:
                case REMOVE_CURSE_1:
                case FOCUS_MAGIC_1:
                case PRESENCE_OF_MIND_1:
                case ARCANE_POWER_1:
                case ICE_ARMOR_1:
                case ICE_BARRIER_1:
                case COMBUSTION_1:
                case ICY_VEINS_1:
                case BLAST_WAVE_1:
                case FLAMESTRIKE_1:
                case FROST_NOVA_1:
                case BLIZZARD_1:
                case ICE_BLOCK_1:
                case COLD_SNAP_1:
                case INVISIBILITY_1:
                case SLOW_FALL_1:
                case CONJURE_MANA_GEM_1:
                case SUMMON_WATER_ELEMENTAL_1:
                case MIRROR_IMAGE_1:
                    return true;
                case FROST_ARMOR_1:
                    return !GetSpell(ICE_ARMOR_1);
                //case MANA_GEM_1:
                //    return manaGemCharges > 0;
                default:
                    return false;
            }
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Mage_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Mage_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Mage_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Mage_spells_support;
        }

    private:
        //Spells
/*frst*/uint32 FROSTFIREBOLT;
        //Timers
/*exc.*/uint32 polyCheckTimer, fmCheckTimer, iceblockCheckTimer, shieldCheckTimer;
        //Counters
/*exc.*/uint8 arcaneBlastStack;
/*exc.*/uint8 manaGemCharges;
        //Check
/*exc.*/bool poly, shielded, fbCasted;
/*exc.*/bool canFrostWard, canFireWard;
    };
};

void AddSC_mage_bot()
{
    new mage_bot();
}
