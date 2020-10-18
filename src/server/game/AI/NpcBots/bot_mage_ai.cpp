#include "bot_ai.h"
#include "botmgr.h"
#include "GameEventMgr.h"
#include "Group.h"
#include "Item.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
/*
Mage NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - 80-90%
TODO: arcane spec, arcane power, presence of mind, slow (pvp), mana shield, cold snap
*/

enum MageBaseSpells
{
    DAMPENMAGIC_1                       = 604,
    AMPLIFYMAGIC_1                      = 1008,//manual use only
    ARCANEINTELLECT_1                   = 1459,
    ARCANEMISSILES_1                    = 5143,
    POLYMORPH_1                         = 118,
    COUNTERSPELL_1                      = 2139,
    SPELLSTEAL_1                        = 30449,
    EVOCATION_1                         = 12051,
    BLINK_1                             = 1953,
    REMOVE_CURSE_1                      = 475,
    INVISIBILITY_1                      = 66,
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
    SLOW_FALL_1                         = 130,
    ICE_LANCE_1                         = 30455,
    ICY_VEINS_1                         = 12472,
    DEEP_FREEZE_1                       = 44572,
    FROST_WARD_1                        = 6143,
    FIRE_WARD_1                         = 543,
    //Special
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
    IMPROVED_BLIZZARD_CHILL             = 12486,//rank 3
    FROSTBITE_TRIGGERED                 = 12494,
    WINTERS_CHILL_TRIGGERED             = 12579,
    IGNITE_TRIGGERED                    = 12654,
    //creature
    CREATURE_ENTRY_CHROMAGGUS           = 14020
};

static const uint32 Mage_spells_damage_arr[] =
{ ARCANEMISSILES_1, BLAST_WAVE_1, BLIZZARD_1, CONE_OF_COLD_1, DEEP_FREEZE_1, DRAGON_BREATH_1, FIREBALL_1,
FIRE_BLAST_1, FLAMESTRIKE_1, FROSTBOLT_1, FROSTFIRE_BOLT_1, FROST_NOVA_1, ICE_LANCE_1, LIVING_BOMB_1, PYROBLAST_1 };

static const uint32 Mage_spells_cc_arr[] =
{ COUNTERSPELL_1, DRAGON_BREATH_1, DEEP_FREEZE_1, FROST_NOVA_1, POLYMORPH_1 };

static const uint32 Mage_spells_support_arr[] =
{ AMPLIFYMAGIC_1, ARCANEINTELLECT_1, BLINK_1, COMBUSTION_1, DAMPENMAGIC_1, EVOCATION_1, FIRE_WARD_1, FROST_WARD_1,
FROST_ARMOR_1, FOCUS_MAGIC_1, ICE_BARRIER_1, ICE_BLOCK_1, ICY_VEINS_1, INVISIBILITY_1, ICE_ARMOR_1, MOLTEN_ARMOR_1,
SLOW_FALL_1, SPELLSTEAL_1, REMOVE_CURSE_1, CONJURE_MANA_GEM_1, RITUAL_OF_REFRESHMENT_1, SUMMON_WATER_ELEMENTAL_1 };

static const std::vector<uint32> Mage_spells_damage(FROM_ARRAY(Mage_spells_damage_arr));
static const std::vector<uint32> Mage_spells_cc(FROM_ARRAY(Mage_spells_cc_arr));
static const std::vector<uint32> Mage_spells_support(FROM_ARRAY(Mage_spells_support_arr));

class mage_bot : public CreatureScript
{
public:
    mage_bot() : CreatureScript("mage_bot") { }

    CreatureAI* GetAI(Creature* creature) const
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
        void JustDied(Unit* u) override { UnsummonAll(); bot_ai::JustDied(u); }

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
            uint32 ARMOR = !MOLTENARMOR ? ICEARMOR : me->GetMap()->IsDungeon() ? MOLTENARMOR : ICEARMOR;
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
            CheckPoly(diff);
            CheckBlink(diff);
            CheckIceBlock(diff);

            if (!GlobalUpdate(diff))
                return;

            CheckPots(diff);

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

            if (!CheckAttackTarget())
                return;

            CheckPolymorph(diff);//this should go AFTER getting target

            Counter(diff);
            CheckSpellSteal(diff);
            DoNormalAttack(diff);
        }

        void DoNormalAttack(uint32 diff)
        {
            if (IsCasting())
                return;

            StartAttack(opponent, IsMelee());

            //mage
            if (me->HasInvisibilityAura()) return;
            if (!HasRole(BOT_ROLE_DPS)) return;

            Unit::AttackerSet const& m_attackers = master->getAttackers();
            Unit::AttackerSet const& b_attackers = me->getAttackers();

            float dist = me->GetDistance(opponent);

            //COMBUSTION (no GCD)
            if (IsSpellReady(COMBUSTION_1, diff, false) && GetManaPCT(me) > 20 &&
                (opponent->GetMaxHealth() > master->GetMaxHealth() * 4 ||
                m_attackers.size() > 1 || b_attackers.size() > 1) &&
                Rand() < 45 &&
                !me->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_MAGE, 0x0, 0x04000000, 0x0)
                /*!HasAuraName(me, COMBUSTION_1)*/)
            {
                if (doCast(me, GetSpell(COMBUSTION_1)))
                    return;
            }
            //ICY VEINS (no GCD)
            if (IsSpellReady(ICY_VEINS_1, diff, false) && GetManaPCT(me) > 20 &&
                (opponent->GetMaxHealth() > master->GetMaxHealth() * 2 ||
                (opponent->GetTypeId() == TYPEID_UNIT && opponent->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)) &&
                Rand() < 45)
            {
                if (doCast(me, GetSpell(ICY_VEINS_1)))
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
                    bool oneOnOne = (*targets.begin()) == opponent;
                    //Frost Nova
                    if (IsSpellReady(FROST_NOVA_1, diff) && (targets.size() > 1 || oneOnOne))
                    {
                        if (doCast(me, GetSpell(FROST_NOVA_1)))
                        {
                            GetInPosition(true, opponent);
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

            if (!CanAffectVictim(SPELL_SCHOOL_MASK_FROST|SPELL_SCHOOL_MASK_FIRE))
                return;

            //spell reflections: Ice Lance instant / Frostbolt Rank 1
            if (IsSpellReady(ICE_LANCE_1, diff) && dist < CalcSpellMaxRange(ICE_LANCE_1) && CanRemoveReflectSpells(opponent, ICE_LANCE_1) &&
                doCast(opponent, ICE_LANCE_1))
                return;
            else if (IsSpellReady(FROSTBOLT_1, diff) && dist < CalcSpellMaxRange(FROSTBOLT_1) && CanRemoveReflectSpells(opponent, FROSTBOLT_1) &&
                doCast(opponent, FROSTBOLT_1))
                return;

            //Pyroblast TODO: PoM
            if (IsSpellReady(PYROBLAST_1, diff) &&
                dist < CalcSpellMaxRange(PYROBLAST_1) && ((opponent->IsPolymorphed() &&
                (b_attackers.size() < 2 || (*b_attackers.begin()) == opponent)) || me->HasAura(HOT_STREAK_BUFF)))
            {
                if (doCast(opponent, GetSpell(PYROBLAST_1)))
                    return;
            }
            //Living Bomb
            if (fbCasted && IsSpellReady(LIVING_BOMB_1, diff) && dist < CalcSpellMaxRange(LIVING_BOMB_1) &&
                opponent->GetHealth() > me->GetHealth() / 2 * opponent->getAttackers().size() &&
                Rand() < 25 && !opponent->HasAura(GetSpell(LIVING_BOMB_1), me->GetGUID()))
            {
                if (doCast(opponent, GetSpell(LIVING_BOMB_1)))
                    return;
            }
            //Fire Blast (do not waste mana in raids)
            if (IsSpellReady(FIRE_BLAST_1, diff) && dist < CalcSpellMaxRange(FIRE_BLAST_1) &&
                opponent->GetHealth() < me->GetMaxHealth()*4 && (fbCasted || opponent->GetHealth() < me->GetMaxHealth() / 4) &&
                Rand() < (30 + 40*fbCasted + 80*(!opponent->IsFrozen() && !opponent->HasUnitState(UNIT_STATE_STUNNED) && me->HasAura(IMPACT_BUFF))))
            {
                if (doCast(opponent, GetSpell(FIRE_BLAST_1)))
                    return;
            }
            //Deep Freeze (damage only)
            if (fbCasted && IsSpellReady(DEEP_FREEZE_1, diff) && dist < CalcSpellMaxRange(DEEP_FREEZE_1) && Rand() < 30 &&
                opponent->IsImmunedToSpellEffect(sSpellMgr->GetSpellInfo(DEEP_FREEZE_1), 0, me) && (opponent->IsFrozen() || me->HasAuraType(SPELL_AURA_ABILITY_IGNORE_AURASTATE)))
            {
                if (doCast(opponent, GetSpell(DEEP_FREEZE_1)))
                    return;
            }
            //Flamestrike (instant cast only)
            if (/*fbCasted && */IsSpellReady(FLAMESTRIKE_1, diff) && dist < CalcSpellMaxRange(FLAMESTRIKE_1) && Rand() < 80 &&
                me->HasAura(FIRESTARTER_BUFF))
            {
                if (doCast(opponent, GetSpell(FLAMESTRIKE_1)))
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
            //Arcane Missiles (special condition for BWL)
            //if (IsSpellReady(ARCANEMISSILES_1, diff) && dist < CalcSpellMaxRange(ARCANEMISSILES_1) &&
            //    ((opponent->GetTypeId() == TYPEID_UNIT && opponent->GetEntry() == CREATURE_ENTRY_CHROMAGGUS) || (b_attackers.empty() && Rand() < 3)))
            //{
            //    if (doCast(opponent, GetSpell(ARCANEMISSILES_1)))
            //        return;
            //}
            //Ice Lance (no cd, only GCD)
            if (fbCasted && (!me->GetMap()->IsDungeon() || opponent->IsControlledByPlayer()) &&
                IsSpellReady(ICE_LANCE_1, diff) && dist < CalcSpellMaxRange(ICE_LANCE_1) &&
                (opponent->IsFrozen() || me->HasAuraType(SPELL_AURA_ABILITY_IGNORE_AURASTATE)))
            {
                if (doCast(opponent, GetSpell(ICE_LANCE_1)))
                    return;
            }
            //Fireball or Frostfire Bolt (instant cast or combustion use up)
            if (/*fbCasted && */IsSpellReady(FROSTFIREBOLT, diff) && dist < CalcSpellMaxRange(FROSTFIREBOLT) && Rand() < 150 &&
                ((((CCed(opponent, true) || b_attackers.empty()) && me->HasAura(COMBUSTION_BUFF)) || me->HasAura(BRAIN_FREEZE_BUFF)) ||
                !GetSpell(FROSTBOLT_1))) //level 1-3
            {
                if (doCast(opponent, GetSpell(FROSTFIREBOLT)))
                    return;
            }
            //Main rotation
            if (IsSpellReady(FROSTFIREBOLT, diff) && _spec == BOT_SPEC_MAGE_FIRE && dist < CalcSpellMaxRange(FROSTFIREBOLT))
            {
                if (doCast(opponent, GetSpell(FROSTFIREBOLT)))
                    return;
            }
            if (IsSpellReady(FROSTBOLT_1, diff) && _spec == BOT_SPEC_MAGE_FROST && dist < CalcSpellMaxRange(FROSTBOLT_1))
            {
                if (doCast(opponent, GetSpell(FROSTBOLT_1)))
                    return;
            }

            if (Spell const* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            {
                if (shot->GetSpellInfo()->Id == SHOOT_WAND && shot->m_targets.GetUnitTarget() != opponent)
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }
            else if (IsSpellReady(SHOOT_WAND, diff) && me->GetDistance(opponent) < 30 && GetEquips(BOT_SLOT_RANGED) &&
                doCast(opponent, SHOOT_WAND))
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
            if (HasBotCommandState(BOT_COMMAND_STAY) || me->IsMounted())
                return;
            if (!IsSpellReady(BLINK_1, diff) || IsCasting() || Rand() > 70)
                return;

            if (!IAmFree())
            {
                if (!me->IsInCombat() && me->GetExactDist2d(master) > std::max<uint8>(master->GetBotMgr()->GetBotFollowDist(), 35) &&
                    me->HasInArc(M_PI*0.67f, master))
                {
                    if (doCast(me, GetSpell(BLINK_1)))
                        return;
                }
            }
            if (me->IsInCombat() && !me->getAttackers().empty() && HasRole(BOT_ROLE_RANGED))
            {
                bool cast = me->HasAuraWithMechanic((1<<MECHANIC_STUN)|(1<<MECHANIC_ROOT));
                Unit* u = nullptr;
                if (!cast)
                {
                    u = me->SelectNearestTarget(7);
                    cast = (u && u->GetVictim() == me && u->IsWithinLOSInMap(me));
                }
                if (!cast)
                {
                    u = (*me->getAttackers().begin());
                    cast = (u && (!CCed(u, true) || me->getAttackers().size() > 1) && u->GetDistance(me) < 5.f &&
                        u->IsWithinLOSInMap(me));
                }
                if (cast)
                {
                    if (u)
                    {
                        //turn away from target
                        me->AttackStop();
                        //me->SetFacingTo(me->GetAbsoluteAngle(u) + M_PI);
                        me->SetOrientation(me->GetAbsoluteAngle(u) + M_PI);
                    }
                    if (doCast(me, GetSpell(BLINK_1)))
                        return;
                }
            }
        }

        void CheckFocusMagic(uint32 diff)
        {
            if (fmCheckTimer > diff || GC_Timer > diff || IAmFree() || me->GetLevel() < 20 || IsCasting() || Rand() > 50)
                return;

            uint32 FOCUSMAGIC = GetSpell(FOCUS_MAGIC_1);
            if (!FOCUSMAGIC)
                return;

            if (Unit* target = FindAffectedTarget(FOCUSMAGIC, me->GetGUID(), 70, 3))
            {
                fmCheckTimer = 15000;
                return;
            }
            else
            {
                Group const* pGroup = master->GetGroup();
                if (!pGroup)
                {
                    if (master->GetPowerType() == POWER_MANA && me->GetExactDist(master) < 30 &&
                        !master->HasAura(FOCUSMAGIC))
                        target = master;
                }
                else
                {
                    for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* pPlayer = itr->GetSource();
                        if (!pPlayer || !pPlayer->IsInWorld() || !pPlayer->IsAlive()) continue;
                        if (me->GetMapId() != pPlayer->GetMapId()) continue;
                        if (pPlayer->GetPowerType() == POWER_MANA && me->GetExactDist(pPlayer) < 30 &&
                            !pPlayer->HasAura(FOCUSMAGIC))
                        {
                            target = pPlayer;
                            break;
                        }
                    }
                    //damaging bots
                    if (!target)
                    {
                        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                        {
                            Player* pPlayer = itr->GetSource();
                            if (!pPlayer || !pPlayer->IsInWorld() || !pPlayer->HaveBot()) continue;
                            if (me->GetMapId() != pPlayer->GetMapId()) continue;
                            BotMap const* map = pPlayer->GetBotMgr()->GetBotMap();
                            for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                            {
                                Creature* cre = it->second;
                                if (!cre || !cre->IsInWorld() || cre == me || !cre->IsAlive() ||
                                    cre->GetPowerType() != POWER_MANA || cre->GetBotAI()->HasRole(BOT_ROLE_TANK) ||
                                    cre->GetBotClass() == BOT_CLASS_BM || cre->GetBotClass() == BOT_CLASS_HUNTER ||
                                    cre->GetBotClass() == BOT_CLASS_SPELLBREAKER || cre->GetBotClass() == BOT_CLASS_DARK_RANGER)
                                    continue;
                                if (cre->GetBotAI()->HasRole(BOT_ROLE_DPS) && me->GetExactDist(cre) < 30 &&
                                    !cre->HasAura(FOCUSMAGIC))
                                {
                                    target = cre;
                                    break;
                                }
                            }
                        }
                    }
                    //any bot
                    if (!target)
                    {
                        for (GroupReference const* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                        {
                            Player* pPlayer = itr->GetSource();
                            if (!pPlayer || !pPlayer->IsInWorld() || !pPlayer->HaveBot()) continue;
                            if (me->GetMapId() != pPlayer->GetMapId()) continue;
                            BotMap const* map = pPlayer->GetBotMgr()->GetBotMap();
                            for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                            {
                                Creature* cre = it->second;
                                if (!cre || !cre->IsInWorld() || cre == me || !cre->IsAlive() ||
                                    cre->GetPowerType() != POWER_MANA || cre->GetBotAI()->HasRole(BOT_ROLE_TANK) ||
                                    cre->GetBotClass() == BOT_CLASS_BM || cre->GetBotClass() == BOT_CLASS_HUNTER ||
                                    cre->GetBotClass() == BOT_CLASS_SPELLBREAKER || cre->GetBotClass() == BOT_CLASS_DARK_RANGER)
                                    continue;
                                if (me->GetExactDist(cre) < 30 &&
                                    !cre->HasAura(FOCUSMAGIC))
                                {
                                    target = cre;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (target && doCast(target, FOCUSMAGIC))
                {
                    fmCheckTimer = 30000;
                    return;
                }
            }

            fmCheckTimer = 5000; //fail
        }

        void CheckIceBlock(uint32 diff)
        {
            if (!me->IsAlive() || GC_Timer > diff || !GetSpell(ICE_BLOCK_1) || Rand() > 60 || IsTank())
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

        void CheckShield(uint32 diff)
        {
            //TODO: Mana Shield
            if (!GetSpell(ICE_BARRIER_1))
                return;

            if (shieldCheckTimer <= diff)
            {
                shieldCheckTimer = 1500;
                shielded = me->HasAura(GetSpell(ICE_BARRIER_1));
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
                (baseId == FIRE_BLAST_1 || /*baseId == SCORCH_1 ||
                baseId == ARCANE_BLAST_1 || */baseId == CONE_OF_COLD_1))
                crit_chance += 6.f;
            //World In Flames: 6% additional critical chance for Flamestrike, Pyroblast, Blast Wave, Dragon's Breath, Living Bomb, Blizzard and Arcane Explosion
            if (lvl >= 15 &&
                (baseId == FLAMESTRIKE_1 || baseId == PYROBLAST_1 ||
                baseId == BLAST_WAVE_1 || baseId == DRAGON_BREATH_1 ||
                baseId == BLIZZARD_DAMAGE_1/* || spellId == ARCANEXPLOSION*/ ||
                baseId == LIVING_BOMB_1 || baseId == LIVING_BOMB_DAMAGE_1))
                crit_chance += 6.f;
            //Improved Scorch part 1: 3% additional critical chance for Scorch, Fireball and Frostfire Bolt
            if (lvl >= 20 && (/*baseId == SCORCH_1 || */baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1))
                crit_chance += 3.f;
            //Critical Mass: 6% additional critical chance for Fire spells
            if ((_spec == BOT_SPEC_MAGE_FIRE) && lvl >= 30 && (SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask()))
                crit_chance += 6.f;
            //Winter's chill part 1: 3% additional crit chance for Frostbolt
            if ((_spec == BOT_SPEC_MAGE_FROST) && lvl >= 35 && baseId == FROSTBOLT_1)
                crit_chance += 3.f;

            //Glyph of Frostfire Bolt part 2: 2% additional critical chance for Frostfire Bolt
            if (/*lvl >= 75 && */baseId == FROSTFIRE_BOLT_1)
                crit_chance += 2.f;
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool crit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Burnout: 50% additional crit damage bonus for All spells
                //well it's gonna be a little too much eh? skipped
                //Ice Shards: 50% additional crit damage bonus for Frost spells
                if (lvl >= 15 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                    pctbonus += 0.334f;
                //Spell Power: 50% additional crit damage bonus for All spells
                if ((_spec == BOT_SPEC_MAGE_ARCANE) && lvl >= 55)
                    pctbonus += 0.334f;
                //Combustion: 50% additional crit damage bonus for Fire spells
                if ((SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask()) && me->HasAura(COMBUSTION_1))
                    pctbonus += 0.334f;
            }

            //Spell Impact: 6% bonus damage for Arcne Explosion, Arcane Blast, Scorch, Fireball, Ice Lance and Cone of Cold
            if (lvl >= 20 &&
                (/*baseId == ARCANE_EXPLOSION_1 || baseId == ARCANE_BLAST_1 ||
                baseId == SCORCH_1 || */baseId == FIREBALL_1 ||
                baseId == ICE_LANCE_1 || baseId == CONE_OF_COLD_1))
                pctbonus += 0.06f;
            //Piercing Ice: 6% bonus damage for Frost spells
            if (lvl >= 20 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                pctbonus += 0.06f;
            //Playing with Fire part 1: 3% bonus damage for all spells
            if ((_spec == BOT_SPEC_MAGE_FIRE) && lvl >= 30)
                pctbonus += 0.03f;
            //Improved Cone of Cold: 35% bonus damage for Cone of Cold
            if ((_spec == BOT_SPEC_MAGE_FROST) && lvl >= 30 && baseId == CONE_OF_COLD_1)
                pctbonus += 0.35f;
            //Arcane Instability part 1: 3% bonus damage for all spells
            if ((_spec == BOT_SPEC_MAGE_ARCANE) && lvl >= 35)
                pctbonus += 0.03f;
            //Fire Power: 10% bonus damage for Fire spells
            if ((_spec == BOT_SPEC_MAGE_FIRE) && lvl >= 35 && (SPELL_SCHOOL_MASK_FIRE & spellInfo->GetSchoolMask()))
                pctbonus += 0.1f;
            //Molten Fury: 12% bonus damage for All spells against target with less than 35% hp
            if ((_spec == BOT_SPEC_MAGE_FIRE) &&
                lvl >= 40 && damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
                pctbonus += 0.12f;
            //Arctic Winds part 1: 5% bonus damage for Frost spells
            if ((_spec == BOT_SPEC_MAGE_FROST) && lvl >= 40 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                pctbonus += 0.05f;
            //Empowered Fire part 1: 15% bonus damage (from spellpower) for Fireball, Frostfire Bolt and Pyroblast
            if ((_spec == BOT_SPEC_MAGE_FIRE) &&
                lvl >= 45 && (baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1 || baseId == PYROBLAST_1))
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.15f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            //Empowered Frostbolt part 1: 10% of spellpower to Frostbolt damage
            if ((_spec == BOT_SPEC_MAGE_FROST) && lvl >= 45 && baseId == FROSTBOLT_1)
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.1f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            //Chilled to the Bone part 1: 5% bonus damage for Frostbolt, Frostfire Bolt and Ice Lance
            if ((_spec == BOT_SPEC_MAGE_FROST) &&
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
                if (eff->IsAffectedOnSpell(spellInfo))
                    pctbonus += 1.0f;

            //pct mods
            //Precision part 1: -3% mana cost for All spells
            if (lvl >= 15)
                pctbonus += 0.03f;
            //Frost Channeling: -10% mana cost for all spells
            if (lvl >= 25)
                pctbonus += 0.1f;
            //Improved Blink part 1: -50% mana cost for Blink
            if ((_spec == BOT_SPEC_MAGE_ARCANE) && lvl >= 30 && baseId == BLINK_1)
                pctbonus += 0.5f;

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
            if ((_spec == BOT_SPEC_MAGE_FROST) && lvl >= 35 &&
                (baseId == ICE_BARRIER_1/* || baseId == COLD_SNAP_1*/ || baseId == SUMMON_WATER_ELEMENTAL_1))
                pctbonus += 0.2f;

            //flat mods
            //Improved Fire Blast: -2 sec cooldown for Fire Blast
            if (lvl >= 10 && baseId == FIRE_BLAST_1)
                timebonus += 2000;
            //Arcane Flows part 2: -2 min cooldown for Evocation
            if ((_spec == BOT_SPEC_MAGE_ARCANE) && lvl >= 45 && baseId == EVOCATION_1)
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
                //ItemTemplate const* gem = sObjectMgr->GetItemTemplate(spellInfo->Effects[0].ItemType);
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
                fbCasted = (baseId == FROSTBOLT_1 || baseId == FIREBALL_1 || baseId == FROSTFIRE_BOLT_1);

            //Handle clearcasting
            if (AuraEffect const* eff = me->GetAuraEffect(ARCANE_CONCENTRATION_BUFF, 0, me->GetGUID()))
            {
                if (eff->IsAffectedOnSpell(spellInfo))
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
            //Firestarter
            if (baseId == FLAMESTRIKE_1/* && me->HasAura(FIRESTARTER_BUFF)*/)
                me->RemoveAurasDueToSpell(FIRESTARTER_BUFF);
            //Brain Freeze (Fireball!)
            if (baseId == FROSTFIRE_BOLT_1 || baseId == FIREBALL_1)
                me->RemoveAurasDueToSpell(BRAIN_FREEZE_BUFF);
            //Hot Streak
            if (baseId == PYROBLAST_1)
                me->RemoveAurasDueToSpell(HOT_STREAK_BUFF);
            //TODO: Presence of mind
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
                    switch (spell->Effects[i].Effect)
                    {
                        case SPELL_EFFECT_CREATE_ITEM:
                        case SPELL_EFFECT_CREATE_ITEM_2:
                        {
                            uint32 newitemid = spell->Effects[i].ItemType;
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
                        if ((_spec == BOT_SPEC_MAGE_FROST) && lvl >= 55)
                            amount -= 10; //chilled to the bone
                        chillEff->ChangeAmount(amount);
                    }
                }
            }

            //Glyph of Ice Barrier: 30% increased effect
            if (baseId == ICE_BARRIER_1 && lvl >= 46)
            {
                AuraEffect* barr = me->GetAuraEffect(spellId, 0);
                if (barr)
                    barr->ChangeAmount(barr->GetAmount() * 1.3f);
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
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            //uint32 spellId = spell->Id;

            //Ward helper
            if (!canFrostWard && (spell->GetSchoolMask() & SPELL_SCHOOL_MASK_FROST) &&
                (spell->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) || spell->HasAura(SPELL_AURA_PERIODIC_DAMAGE)))
                canFrostWard = true;
            if (!canFireWard && (spell->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE) &&
                (spell->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) || spell->HasAura(SPELL_AURA_PERIODIC_DAMAGE)))
                canFireWard = true;

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/) override
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
                UnsummonAll();

            uint32 entry = BOT_PET_WATER_ELEMENTAL;

            Position pos;

            //glyphed: permanent
            Creature* myPet = me->SummonCreature(entry, *me, TEMPSUMMON_MANUAL_DESPAWN);
            me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 2, me->GetOrientation());
            myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            myPet->SetCreatorGUID(master->GetGUID());
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, SUMMON_WATER_ELEMENTAL_1);

            botPet = myPet;
        }

        void UnsummonAll() override
        {
            if (botPet)
                botPet->ToTempSummon()->UnSummon();
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: %s's %s", me->GetName().c_str(), summon->GetName().c_str());
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
            UnsummonAll();

            polyCheckTimer = 0;
            fmCheckTimer = 0;
            iceblockCheckTimer = 0;
            shieldCheckTimer = 0;
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
            //bool isArca = _spec == BOT_SPEC_MAGE_ARCANE;
            bool isFire = _spec == BOT_SPEC_MAGE_FIRE;
            bool isFros = _spec == BOT_SPEC_MAGE_FROST;

            InitSpellMap(DAMPENMAGIC_1);
            InitSpellMap(AMPLIFYMAGIC_1);
            InitSpellMap(ARCANEINTELLECT_1);
            InitSpellMap(ARCANEMISSILES_1);
            InitSpellMap(POLYMORPH_1);
            InitSpellMap(COUNTERSPELL_1);
            InitSpellMap(SPELLSTEAL_1);
            InitSpellMap(EVOCATION_1);
            InitSpellMap(BLINK_1);
            InitSpellMap(REMOVE_CURSE_1);
            InitSpellMap(INVISIBILITY_1);
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

 /*Special*/InitSpellMap(CONJURE_MANA_GEM_1);
 /*Special*/InitSpellMap(MANA_GEM_1);

            InitSpellMap(RITUAL_OF_REFRESHMENT_1); //not casted

  /*Talent*/lvl >= 20 ? InitSpellMap(FOCUS_MAGIC_1) : RemoveSpell(FOCUS_MAGIC_1);

  /*Talent*/lvl >= 20 ? InitSpellMap(PYROBLAST_1) : RemoveSpell(PYROBLAST_1);
  /*Talent*/lvl >= 30 && isFire ? InitSpellMap(BLAST_WAVE_1) : RemoveSpell(BLAST_WAVE_1);
  /*Talent*/lvl >= 40 && isFire ? InitSpellMap(DRAGON_BREATH_1) : RemoveSpell(DRAGON_BREATH_1);
  /*Talent*/lvl >= 50 && isFire ? InitSpellMap(COMBUSTION_1) : RemoveSpell(COMBUSTION_1);
  /*Talent*/lvl >= 60 && isFire ? InitSpellMap(LIVING_BOMB_1) : RemoveSpell(LIVING_BOMB_1);

  /*Talent*/lvl >= 20 ? InitSpellMap(ICY_VEINS_1) : RemoveSpell(ICY_VEINS_1);
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
            bool isArca = _spec == BOT_SPEC_MAGE_ARCANE;
            bool isFire = _spec == BOT_SPEC_MAGE_FIRE;
            bool isFros = _spec == BOT_SPEC_MAGE_FROST;

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

            RefreshAura(IGNITE, level >= 15 ? 1 : 0);
            RefreshAura(BURNING_DETERMINATION, level >= 15 ? 1 : 0);
            RefreshAura(IMPACT, level >= 20 ? 1 : 0);
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
                case ICE_ARMOR_1:
                case ICE_BARRIER_1:
                case COMBUSTION_1:
                case ICY_VEINS_1:
                case BLAST_WAVE_1:
                case FLAMESTRIKE_1:
                case FROST_NOVA_1:
                case BLIZZARD_1:
                case ICE_BLOCK_1:
                case INVISIBILITY_1:
                case SLOW_FALL_1:
                case CONJURE_MANA_GEM_1:
                case SUMMON_WATER_ELEMENTAL_1:
                    return true;
                case FROST_ARMOR_1:
                    return !GetSpell(ICE_ARMOR_1);
                //case MANA_GEM_1:
                //    return manaGemCharges > 0;
                default:
                    return false;
            }
        }

        std::vector<uint32> const* GetDamagingSpellsList() const
        {
            return &Mage_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const
        {
            return &Mage_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const
        //{
        //    return &Mage_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const
        {
            return &Mage_spells_support;
        }

    private:
        //Spells
/*frst*/uint32 FROSTFIREBOLT;
        //Timers
/*exc.*/uint32 polyCheckTimer, fmCheckTimer, iceblockCheckTimer, shieldCheckTimer;
        //Counters
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
