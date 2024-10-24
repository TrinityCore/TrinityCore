#include "bot_ai.h"
#include "bot_GridNotifiers.h"
#include "botspell.h"
#include "bottext.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
/*
Naga Sea Witch NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
A vicious scaly denizen of ocean often associated with the coming of prodigious storms (Warcraft III tribute)
Specifics:
Spell damage taken reduced by 30%, partially immune to control effects, cloth armor,
deals physical/spellfrost/spellstorm damage, attack power bonus: agility x2, spell power bonus: 200% intellect. Main attribute: intellect
Abilities:
1) Forked Lightning. Calls forth a cone of lightning to damage enemies. Hits 2 to all targets (depending on hero level),
stunning them for 2 seconds. This damage generates no threat
2) Frost Arrows. Imbues arrow with spellfrost for extra damage, slowing target's
movement, attack and casting speed by up to 70% (depending on hero level)
3) Mana Shield. Creates a shield that absorbs 100% incoming (non-mitigated) damage by using Sea Witch's mana,
absorbs 2 to 10 damage per point of mana (depending on hero level)
4) Tornado. Summons a fierce tornado that damages and slows nearby enemy units, sometimes incapacitating them completely.
Tornado grows over time oudoors, increasing damage dealt and area of effect, but shrinks indoors, dissipating quickly
5ex) Shot. Normal shoot
6ex) Naga (passive). Swim speed increased by 200%. Damage and dodge chance are greatly increased while in water
Complete - 100%
*/

enum SeaWitchBaseSpells
{
    //AUTO_SHOT_1                         = 75,
    SHOOT_BOW_1                         = SPELL_SHOOT_BOW,
    FORKED_LIGHTNING_1                  = SPELL_FORKED_LIGHTNING,
    FROST_ARROW_1                       = SPELL_FROST_ARROW,
    MANA_SHIELD_1                       = SPELL_MANA_SHIELD,
    TORNADO_1                           = SPELL_TORNADO
};
enum SeaWitchPassives
{
};
enum SeaWitchSpecial
{
    MH_ATTACK_ANIM                      = SPELL_ATTACK_MELEE_1H,

    FORKEDLIGHTNING_COST                = 110 * 5,
    FROSTARROW_COST                     = 10 * 5,
    TORNADO_COST                        = 250 * 5,

    FORKED_LIGHTNING_EFFECT             = SPELL_FORKED_LIGHTNING_EFFECT,
    FROST_ARROW_EFFECT                  = SPELL_FROST_ARROW_EFFECT,

    NAGA_SWIM_PASSIVE                   = 40513,
    SPELL_THREAT_MOD                    = 31745, //Salvation

    SPELL_PARALYTIC_POISON              = 35201
};

static constexpr size_t TORNADO_MIN_TARGETS = 4u;

static const uint32 Seawitch_spells_damage_arr[] =
{ FORKED_LIGHTNING_1, FROST_ARROW_1, TORNADO_1 };

static const uint32 Seawitch_spells_cc_arr[] =
{ FROST_ARROW_1, TORNADO_1 };

static const uint32 Seawitch_spells_support_arr[] =
{ MANA_SHIELD_1 };

static const std::vector<uint32> Seawitch_spells_damage(FROM_ARRAY(Seawitch_spells_damage_arr));
static const std::vector<uint32> Seawitch_spells_cc(FROM_ARRAY(Seawitch_spells_cc_arr));
static const std::vector<uint32> Seawitch_spells_support(FROM_ARRAY(Seawitch_spells_support_arr));

class sea_witch_bot : public CreatureScript
{
public:
    sea_witch_bot() : CreatureScript("sea_witch_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new sea_witch_botAI(creature);
    }

    struct sea_witch_botAI : public bot_ai
    {
        sea_witch_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_SEA_WITCH;

            InitUnitFlags();

            //sea witch immunities
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_POSSESS, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM_OFFHAND, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM_RANGED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_TURN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            //Sea Witch is immune to poisons
            me->ApplySpellImmune(0, IMMUNITY_DISPEL, DISPEL_POISON, true);
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

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { /*UnsummonAll(false);*/ bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }

        void CheckManaShield(uint32 diff)
        {
            if (me->HasAuraType(SPELL_AURA_MANA_SHIELD) || me->HasAuraType(SPELL_AURA_SCHOOL_ABSORB))
                return;

            if (IsSpellReady(MANA_SHIELD_1, diff, false) && GetManaPCT(me) >= 25 && me->IsInCombat())
                if (doCast(me, GetSpell(MANA_SHIELD_1)))
                    return;
        }

        void Counter(uint32 diff)
        {
            if (!IsSpellReady(FORKED_LIGHTNING_1, diff, false) || !HasRole(BOT_ROLE_DPS) || Rand() > 55)
                return;

            if (Unit* target = FindCastingTarget(CalcSpellMaxRange(FORKED_LIGHTNING_1) - 5.f, 0, FORKED_LIGHTNING_1))
            {
                Spell const* spell = target->GetCurrentSpell(CURRENT_GENERIC_SPELL);
                if (!spell)
                    spell = target->GetCurrentSpell(CURRENT_CHANNELED_SPELL);

                if (spell && spell->GetTimer() > int32(AssertBotSpellInfoOverride(GetSpell(FORKED_LIGHTNING_1))->CalcCastTime() + 250))
                {
                    me->SetFacingTo(me->GetAbsoluteAngle(target));
                    if (doCast(target, GetSpell(FORKED_LIGHTNING_1)))
                        return;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            if (Spell const* spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            {
                uint32 const baseId = spell->GetSpellInfo()->GetFirstRankSpell()->Id;
                //Tornado interrupt
                if (!me->IsInCombat() && baseId == TORNADO_1)
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                else if (baseId == FORKED_LIGHTNING_1 && (!me->GetVictim() || !me->HasInArc(float(M_PI) / 2.f, me->GetVictim())))
                {
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    SetSpellCooldown(FORKED_LIGHTNING_1, 500);
                }
                else if (_spell_preact && spell->GetTimer() < 400)
                {
                    _spell_preact = false;
                    switch (baseId)
                    {
                        case TORNADO_1:
                        //    BotSay("REAP THE STORM!");
                        //[[fallthrough]];
                        case FORKED_LIGHTNING_1:
                            me->CastSpell(me, MH_ATTACK_ANIM, true);
                            break;
                        default:
                            break;
                    }
                }
            }

            if (IsPotionReady())
            {
                if (me->GetPower(POWER_MANA) < FORKEDLIGHTNING_COST)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 30)
                    DrinkPotion(false);
            }

            if (ProcessImmediateNonAttackTarget())
                return;

            CheckManaShield(diff);

            if (!CheckAttackTarget())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                return;
            }

            Counter(diff);

            if (IsCasting())
                return;

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

            MoveBehind(mytar);

            float dist = me->GetDistance(mytar);
            static constexpr float maxRangeLong = 35.f;

            //bool inpostion = !mytar->HasAuraType(SPELL_AURA_MOD_SPEED_SLOW_ALL) || dist > maxRangeLong - 20.f;

            //Auto Shot
            //Spell const* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL);
            //if (shot && shot->GetSpellInfo()->Id == AUTO_SHOT_1 && (shot->m_targets.GetUnitTarget() != mytar || !inpostion))
            //    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);

            if (!HasRole(BOT_ROLE_DPS))
                return;

            //RANGED SECTION
            if (dist > maxRangeLong)
                return;

            if (CheckForkedLightning(diff))
                return;

            if (CheckTornado(diff))
                return;

            if (/*inpostion && */!me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            {
                //Frost Arrow / Autoshot
                if (IsSpellReady(FROST_ARROW_1, diff) && me->GetPower(POWER_MANA) >= FROSTARROW_COST &&
                    !mytar->IsImmunedToDamage(AssertBotSpellInfoOverride(FROST_ARROW_1)))
                {
                    if (doCast(mytar, GetSpell(FROST_ARROW_1)))
                        return;
                }
                else if (IsSpellReady(SHOOT_BOW_1, diff))
                {
                    if (doCast(mytar, SHOOT_BOW_1))
                        return;
                }
            }
        }

        bool CheckTornado(uint32 diff)
        {
            if (!IsSpellReady(TORNADO_1, diff, false) || !me->GetVictim() || me->GetPower(POWER_MANA) < TORNADO_COST || Rand() > 50)
                return false;

            std::list<Unit*> targets;
            GetNearbyTargetsList(targets, 40.f, 0);
            targets.erase(std::remove_if(targets.begin(), targets.end(), [healthThreshold = uint32(me->GetMaxHealth() / 4 * 3)](Unit const* u) {
                return u->GetHealth() < healthThreshold;
            }), targets.end());

            size_t targets_count = (IAmFree() || !master->GetGroup()) ? TORNADO_MIN_TARGETS : std::max<size_t>(master->GetGroup()->GetMemberSlots().size() / 3, TORNADO_MIN_TARGETS);
            if (targets.size() >= targets_count)
            {
                me->SetFacingTo(me->GetAbsoluteAngle(me->GetVictim()));
                if (doCast(me->GetVictim(), GetSpell(TORNADO_1)))
                    return true;
            }

            return false;
        }

        bool CheckForkedLightning(uint32 diff)
        {
            if (!IsSpellReady(FORKED_LIGHTNING_1, diff, false) || !me->GetVictim() || me->GetPower(POWER_MANA) < FORKEDLIGHTNING_COST ||
                Rand() > 90 || !me->HasInArc(float(M_PI), me->GetVictim()))
                return false;

            std::list<Unit*> targets;
            GetNearbyTargetsInConeList(targets, CalcSpellMaxRange(FORKED_LIGHTNING_1) - 5.f);
            if (targets.size() > ((me->GetLevel() < 60) ? 1u : 0u))
            {
                me->SetFacingTo(me->GetAbsoluteAngle(me->GetVictim()));
                if (doCast(me->GetVictim(), GetSpell(FORKED_LIGHTNING_1)))
                    return true;
            }

            return false;
        }

        void ApplyClassDamageMultiplierMelee(uint32& damage, CalcDamageInfo& /*damageinfo*/) const override
        {
            if (IsInContactWithWater())
            {
                //TC_LOG_ERROR("scripts", "ApplyClassDamageMultiplierMelee: {} now in water", me->GetName());
                damage *= 3;
            }
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool /*crit*/) const override
        {
            if (IsInContactWithWater())
            {
                //TC_LOG_ERROR("scripts", "ApplyClassDamageMultiplierMelee: {} now in water", me->GetName());
                damage *= 3;
            }
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);
            float flat_mod = 0.f;

            if (IsInContactWithWater())
            {
                //TC_LOG_ERROR("scripts", "ApplyClassDamageMultiplierSpell: {} now in water", me->GetName());
                fdamage *= 3.f;
            }

            //2) apply bonus damage mods
            float pctbonus = 1.0f;
            if (iscrit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                if (/*baseId == FROST_ARROW_1 || */baseId == FORKED_LIGHTNING_1)
                    pctbonus *= 1.33f;
            }

            if (baseId == FORKED_LIGHTNING_1)
            {
                constexpr float basecoef = 2.5f / 80.f;
                float coef = basecoef * (lvl - 3);
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * coef * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            }

            damage = int32(fdamage * pctbonus + flat_mod);
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //if ()
            //    pctbonus += 1.0f;

            //pct mods
            //Frost Arrow affect by attack speed
            if (baseId == FROST_ARROW_1)
                pctbonus += 1.0f - me->m_modAttackSpeedPct[RANGED_ATTACK];

            //flat mods
            //Starlight Wrath: -0.5 sec cast time for Wrath and Starfire
            //if (lvl >= 10 && (baseId == WRATH_1 || baseId == STARFIRE_1))
            //    timebonus += 500;

            casttime = std::max<int32>(int32((float(casttime) * (1.0f - pctbonus)) - timebonus), 0);
        }

        void ApplyClassSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            if (baseId == FORKED_LIGHTNING_1)
            {
                switch (lvl / 10)
                {
                    case 8: targets = 666; break;
                    case 7: targets =  10; break;
                    case 6: targets =   7; break;
                    case 5: targets =   6; break;
                    case 4: targets =   5; break;
                    case 3: targets =   4; break;
                    case 2: targets =   3; break;
                    case 1: targets =   3; break;
                    default:               break;
                }
            }
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            if (baseId == FROST_ARROW_EFFECT && (effIndex == EFFECT_0 || effIndex == EFFECT_1))
            {
                switch (lvl / 10)
                {
                    case 8: case 7: case 6: value = -70; break;
                    case 5: case 4:         value = -50; break;
                    default:                             break;
                }
            }

            value = value * pctbonus;
        }

        void ApplyClassEffectValueMultiplierMods(SpellInfo const* spellInfo, SpellEffIndex effIndex, float& multiplier) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //Mana Shield absorption modifier
            //Base is 10.f
            if (baseId == MANA_SHIELD_1 && effIndex == EFFECT_0)
                pctbonus *= _manaPerDamageMult();

            multiplier = multiplier * pctbonus;
        }

        void OnClassSpellStart(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            switch (baseId)
            {
                case FORKED_LIGHTNING_1:
                case TORNADO_1:
                    _spell_preact = true;
                    break;
                default:
                    break;
            }
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            switch (baseId)
            {
                case FROST_ARROW_1:
                case FORKED_LIGHTNING_1:
                case TORNADO_1:
                {
                    uint32 attackTime = uint32(me->GetAttackTime(RANGED_ATTACK) * me->m_modAttackSpeedPct[RANGED_ATTACK]);
                    if (baseId == FROST_ARROW_1)
                    {
                        uint32 castTime = spellInfo->CalcCastTime();
                        GC_Timer = castTime >= attackTime ? 0 : attackTime - castTime;
                    }
                    if (baseId == FORKED_LIGHTNING_1 || baseId == TORNADO_1)
                    {
                        me->resetAttackTimer();
                        GC_Timer = attackTime;
                        //me->CastSpell(me, MH_ATTACK_ANIM, true);
                    }
                    break;
                }
                default:
                    break;
            }

            if (baseId == TORNADO_1)
                SummonBotPet();
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            if (target == me)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();

            if (baseId == FORKED_LIGHTNING_1)
            {
                //Forked Lightning stun
                me->CastSpell(target, FORKED_LIGHTNING_EFFECT, true);
            }
            if (baseId == FROST_ARROW_1)
            {
                if (AuraEffect* sarr = target->GetAuraEffect(SPELL_AURA_MOD_SPEED_SLOW_ALL, SPELLFAMILY_GENERIC, 0x0, 0x4, 0x0, me->GetGUID()))
                {
                    sarr->GetBase()->RefreshDuration();
                }
                else if (Aura* arro = me->AddAura(FROST_ARROW_EFFECT, target))
                {
                    int32 dur = target->IsPlayer() ? 2000 : 6000;
                    arro->SetDuration(dur);
                    arro->SetMaxDuration(dur);
                }
            }
            if (baseId == SPELL_PARALYTIC_POISON)
            {
                if (Aura* para = target->GetAura(SPELL_PARALYTIC_POISON, me->GetGUID()))
                {
                    static constexpr int32 duration_threshold = 6000;
                    if (para->GetMaxDuration() > duration_threshold)
                    {
                        para->SetDuration(duration_threshold);
                        para->SetMaxDuration(duration_threshold);
                    }
                    else
                        para->RefreshDuration();
                }
            }

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void OnBotDamageDealt(Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType /*damagetype*/, SpellInfo const* /*spellInfo*/) override
        {
            if (damage && victim && cleanDamage && (cleanDamage->attackType == BASE_ATTACK || cleanDamage->attackType == OFF_ATTACK) &&
                victim->IsWithinCombatRange(me, ATTACK_DISTANCE))
            {
                if (urand(0, 100) < 5)
                {
                    int32 baseAmount = 1;
                    if (AuraEffect* pois = victim->GetAuraEffect(SPELL_PARALYTIC_POISON, EFFECT_0, me->GetGUID()))
                        baseAmount = pois->GetAmount() * 2;
                    else
                        baseAmount = int32(me->GetFloatValue(UNIT_FIELD_MAXDAMAGE)) + 1;
                    CastSpellExtraArgs args(true);
                    args.AddSpellBP0(baseAmount);
                    me->CastSpell(victim, SPELL_PARALYTIC_POISON, args);
                }
            }
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
        {
            if (damage && me->HasAuraType(SPELL_AURA_MANA_SHIELD))
                me->RemoveAurasDueToSpell(MANA_SHIELD_1);

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

        uint8 GetPetPositionNumber(Creature const* /*summon*/) const override
        {
            return 0;
        }

        void SummonBotPet()
        {
            if (!_minions.empty())
                UnsummonAll(false);

            Position spos;
            if (Unit const* mytar = me->GetVictim())
                mytar->GetNearPoint(mytar, spos.m_positionX, spos.m_positionY, spos.m_positionZ, me->GetDistance2d(mytar) * 0.25f, mytar->GetAbsoluteAngle(me));
            else
                me->GetNearPoint(me, spos.m_positionX, spos.m_positionY, spos.m_positionZ, 10.f, 0.f);

            Creature* myPet = me->SummonCreature(BOT_PET_TORNADO, spos, TEMPSUMMON_CORPSE_DESPAWN);
            myPet->SetCreator(master);
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, TORNADO_1);

            CreatureMovementData& cmData = const_cast<CreatureMovementData&>(myPet->GetMovementTemplate());
            cmData.Swim = false;
            cmData.Ground = CreatureGroundMovementType::Run;
            cmData.Flight = CreatureFlightMovementType::None;

            _minions.insert(myPet);
        }

        void UnsummonAll(bool savePets = true) override
        {
            UnsummonCreatures(_minions, savePets);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDies: {}'s {}", me->GetName(), summon->GetName());
            //if (summon == botPet)
            //    botPet = nullptr;
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: {}'s {}", me->GetName(), summon->GetName());
            if (_minions.find(summon) != _minions.end())
                _minions.erase(summon);
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(FROST_ARROW_1) - 6.f : CalcSpellMaxRange(FROST_ARROW_1) - 15.f;
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_TORNADO;
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            UnsummonAll(false);

            _spell_preact = false;

            DefaultInit();

            //swim mod
            if (Aura* swim = me->AddAura(NAGA_SWIM_PASSIVE, me))
                swim->GetEffect(0)->ChangeAmount(200);

            //threat mod
            if (Aura* threat = me->AddAura(SPELL_THREAT_MOD, me))
                threat->GetEffect(0)->ChangeAmount(-50);
        }

        void ReduceCD(uint32 /*diff*/) override
        {
            //if (trapTimer > diff)                   trapTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            //uint8 lvl = me->GetLevel();
            //InitSpellMap(AUTO_SHOT_1);
            InitSpellMap(SHOOT_BOW_1);
            InitSpellMap(FORKED_LIGHTNING_1);
            InitSpellMap(FROST_ARROW_1);
            InitSpellMap(MANA_SHIELD_1);
            InitSpellMap(TORNADO_1);
        }

        void ApplyClassPassives() const override
        {
        }

        //bool CanUseManually(uint32 basespell) const override
        //{
        //    switch (basespell)
        //    {
        //        case FORKED_LIGHTNING_1:
        //        case TORNADO_1:
        //            return true;
        //        default:
        //            return false;
        //    }
        //}

        bool HasAbilitiesSpecifics() const override { return true; }
        void FillAbilitiesSpecifics(Player const* player, std::list<std::string> &specList) override
        {
            bool amount_is_mana = true;
            float amount = AssertBotSpellInfoOverride(MANA_SHIELD_1)->GetEffect(EFFECT_0).CalcValueMultiplier(me); //mana per damage
            if (amount < 1.0f)
            {
                amount_is_mana = false;
                amount = 1.f / amount;
            }

            std::ostringstream amount_sstr;
            amount_sstr.setf(std::ios_base::fixed);
            amount_sstr.precision(1);
            amount_sstr << amount;
            uint32 text_id = amount_is_mana ? BOT_TEXT_MANA_PER_DAMAGE : BOT_TEXT_DAMAGE_PER_MANA;

            specList.push_back(LocalizedNpcText(player, text_id) + ": " + amount_sstr.str());
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Seawitch_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Seawitch_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Seawitch_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Seawitch_spells_support;
        }
    private:
        typedef std::set<Creature*> Summons;
        Summons _minions;

        bool _spell_preact;

        float _manaPerDamageMult() const
        {
            switch (me->GetLevel() / 10)
            {
                case 8: return 1.f / 100.00f;
                case 7: return 1.f /  50.00f;
                case 6: return 1.f /  20.00f;
                case 5: return 1.f /  10.00f;
                case 4: return 1.f /   4.00f;
                case 3: return 1.f /   2.50f;
                case 2: return 1.f /   1.67f;
                case 1: return 1.f /   1.25f;
                default:return 1.f /   1.00f;
            }
        }
    };
};

void AddSC_sea_witch_bot()
{
    new sea_witch_bot();
}
