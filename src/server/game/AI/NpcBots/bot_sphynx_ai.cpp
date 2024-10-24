#include "bot_ai.h"
#include "bot_GridNotifiers.h"
#include "botmgr.h"
#include "botspell.h"
#include "bottraits.h"
#include "Containers.h"
#include "Creature.h"
#include "ScriptMgr.h"
/*
Obsidian Destroyer NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
Obsidian winged monstrocity with unsatable hunger for magic (Warcraft III tribute)
Specifics:
High armor, very high resistances, partially immune to magic, negative mana regeneration (-2%/sec, cannot be changed),
any armor, dual-wielding wands, no physical attack, spellpower = 50% attack power + 200% intellect
Abilities:
1) Devour Magic: dispel up to 2 magic effects from enemies, up to 2 magic effects and up to 2 curses from allies
and damaging summoned units in 20 yards area, every dispelled effect restores 20% mana and 5% health, 7 seconds cooldown
2) Shadow Bolt: main attack, single target, no mana cost
3) Shadow Blast: 125 mana empowered attack, splash damage (6.25% of base mana)
4) Shadow Armor (passive, custom): restores mana equal to a percentage of damage taken
5) Drain Mana: leech all mana from a friendly target (up to 100% of od's max mana)
6) Replenish Mana: restores 2% of max mana to up to 10 surrounding allies within 25yds at cost of all mana
7) Replenish Life: restores 3% of max hp to up to 10 surrounding allies within 25yds at cost of all mana
Complete - 100%
TODO:
*/

enum SphynxBaseSpells
{
    MAIN_ATTACK_1           = SPELL_SHADOW_BOLT1,
    SPLASH_ATTACK_1         = SPELL_SHADOW_BLAST,
    DEVOUR_MAGIC_1          = SPELL_DEVOUR_MAGIC,
    DRAIN_MANA_1            = SPELL_DRAIN_MANA,

    REPLENISH_MANA_1        = SPELL_REPLENISH_MANA,
    REPLENISH_HEALTH_1      = SPELL_REPLENISH_HEALTH
};
enum SphynxPassives
{
};
enum SphynxSpecial
{
    MH_ATTACK_ANIM          = SPELL_ATTACK_MELEE_1H,
    MH_OH_ATTACK_ANIM       = SPELL_ATTACK_MELEE_RANDOM,
    SPELL_ENERGIZE          = 34424,//"Shadow Armor"

    SPLASH_ATTACK_COST      = BASE_MANA_SPHYNX/16//6.25%
};

static const uint32 Sphynx_spells_damage_arr[] =
{ /*MAIN_ATTACK_1, */SPLASH_ATTACK_1 };

static const uint32 Sphynx_spells_heal_arr[] =
{ REPLENISH_HEALTH_1 };

static const uint32 Sphynx_spells_support_arr[] =
{ DEVOUR_MAGIC_1, /*DRAIN_MANA_1, */REPLENISH_HEALTH_1, REPLENISH_MANA_1 };

static const std::vector<uint32> Sphynx_spells_damage(FROM_ARRAY(Sphynx_spells_damage_arr));
static const std::vector<uint32> Sphynx_spells_heal(FROM_ARRAY(Sphynx_spells_heal_arr));
static const std::vector<uint32> Sphynx_spells_support(FROM_ARRAY(Sphynx_spells_support_arr));

class sphynx_bot : public CreatureScript
{
public:
    sphynx_bot() : CreatureScript("sphynx_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new sphynx_botAI(creature);
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
    struct sphynx_botAI : public bot_ai
    {
        sphynx_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_SPHYNX;

            InitUnitFlags();

            //sphynx immunities
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_POSSESS, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SILENCE, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_BLOCK_SPELL_FAMILY, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM_OFFHAND, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BLEED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INFECTED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_TURN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId, triggered);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { dmgReceived = 0; DraincheckTimer = 2000; bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { dmgReceived = 0; bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            CheckDevourMagic(diff);

            if (IsSpellReady(DEVOUR_MAGIC_1, diff))
                CureGroup(DEVOUR_MAGIC_1, diff);

            //if (!me->IsInCombat())
            //    DoNonCombatActions(diff);

            if (IsCasting())
                return;

            CheckReplenishHealth(diff);
            CheckReplenishMana(diff);

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
                return;

            CheckUsableItems(diff);

            Attack(diff);
        }

        void Attack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, IsMelee());

            CheckAttackState();
            if (!me->IsAlive() || !mytar->IsAlive())
                return;

            CheckDrainMana(diff);

            MoveBehind(mytar);

            if (!HasRole(BOT_ROLE_DPS))
                return;

            if (GC_Timer > diff)
                return;

            if (me->GetDistance(mytar) > 30)
                return;

            if (me->isMoving() && !me->HasInArc(float(M_PI)/2, mytar))
                return;

            if (!CanAffectVictimAny(mytar, SPELL_SCHOOL_SHADOW, SPELL_SCHOOL_ARCANE))
                return;

            if (me->GetPower(POWER_MANA) >= SPLASH_ATTACK_COST && IsSpellReady(SPLASH_ATTACK_1, diff))
            {
                if (doCast(mytar, GetSpell(SPLASH_ATTACK_1)))
                    return;
            }
            else if (IsSpellReady(MAIN_ATTACK_1, diff))
            {
                if (doCast(mytar, GetSpell(MAIN_ATTACK_1)))
                    return;
            }
        }

        void CheckDevourMagic(uint32 diff)
        {
            if (DevourcheckTimer > diff || !IsSpellReady(DEVOUR_MAGIC_1, diff, false) || IsCasting() ||
                (GetHealthPCT(me) > 75 && Rand() > 15 &&
                (!HasRole(BOT_ROLE_DPS) || me->GetPower(POWER_MANA) >= SPLASH_ATTACK_COST * 6)))
                return;

            DevourcheckTimer = urand(350, 700);

            Unit* target = FindHostileDispelTarget(40);
            if (target && doCast(target, GetSpell(DEVOUR_MAGIC_1)))
                return;
        }

        void CheckDrainMana(uint32 diff)
        {
            if (DraincheckTimer > diff || Rand() > 40 || IAmFree() || !HasRole(BOT_ROLE_DPS) || IsCasting() ||
                !IsSpellReady(DRAIN_MANA_1, diff, false) || me->GetPower(POWER_MANA) >= SPLASH_ATTACK_COST)
                return;

            DraincheckTimer = urand(750, 1500);

            std::list<Unit*> targets;
            GetNearbyFriendlyTargetsList(targets, 40);
            targets.remove_if(BOTAI_PRED::DrainTargetExclude());

            if (targets.empty())
                return;

            Unit* target = Trinity::Containers::SelectRandomContainerElement(targets);
            if (doCast(target, GetSpell(DRAIN_MANA_1)))
                return;
        }

        void CheckReplenishHealth(uint32 diff)
        {
            if (ReplHealthcheckTimer > diff || !IsSpellReady(REPLENISH_HEALTH_1, diff) || IAmFree() ||
                !HasRole(BOT_ROLE_HEAL) || IsCasting() ||
                (HasRole(BOT_ROLE_DPS) && me->GetPower(POWER_MANA) > 0))
                return;

            ReplHealthcheckTimer = 1000;

            Group const* gr = master->GetGroup();
            if (!gr)
                return;

            bool haveHp = false;
            uint8 partycombat = 0, partynocombat = 0;
            for (Unit const* member : BotMgr::GetAllGroupMembers(gr))
            {
                if (me->GetMap() == member->FindMap())
                {
                    if (member->IsInCombat())
                        partycombat++;
                    else if (member->IsAlive())
                        partynocombat++;

                    if (!haveHp && member->IsAlive() && me->GetDistance(member) < 15 && GetHealthPCT(member) < 95)
                        haveHp = true;
                }
            }

            if (haveHp && (!me->IsInCombat() || partycombat > partynocombat) &&
                doCast(me, GetSpell(REPLENISH_HEALTH_1)))
                return;
        }

        void CheckReplenishMana(uint32 diff)
        {
            if (ReplManacheckTimer > diff || !IsSpellReady(REPLENISH_MANA_1, diff) || IAmFree() || IsCasting() ||
                (HasRole(BOT_ROLE_DPS) && me->GetPower(POWER_MANA) > 0))
                return;

            ReplManacheckTimer = 1000;

            Group const* gr = master->GetGroup();
            if (!gr)
                return;

            bool haveMana = false;
            uint8 partycombat = 0, partynocombat = 0;
            for (Unit const* member : BotMgr::GetAllGroupMembers(gr))
            {
                if (me->GetMap() == member->FindMap())
                {
                    if (member->IsInCombat())
                        partycombat++;
                    else if (member->IsAlive())
                        partynocombat++;

                    if (!haveMana && member->IsAlive() && me->GetDistance(member) < 15 && GetManaPCT(member) < 95 &&
                        !(member->IsNPCBot() && member->ToCreature()->GetBotClass() == BOT_CLASS_SPHYNX))
                        haveMana = true;
                }
            }

            if (haveMana && (!me->IsInCombat() || partycombat > partynocombat) &&
                doCast(me, GetSpell(REPLENISH_MANA_1)))
                return;
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //uint8 lvl = me->getLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 1.0f;
            if (iscrit)
                pctbonus *= 1.333f;

            damage = int32(fdamage * pctbonus);
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == MAIN_ATTACK_1 || baseId == SPLASH_ATTACK_1 || baseId == DEVOUR_MAGIC_1 ||
                baseId == DRAIN_MANA_1 || baseId == REPLENISH_MANA_1 || baseId == REPLENISH_HEALTH_1)
                GC_Timer = uint32(me->GetAttackTime(BASE_ATTACK) * me->m_modAttackSpeedPct[BASE_ATTACK]);

            if (baseId == SPLASH_ATTACK_1)
                me->CastSpell(me, MH_ATTACK_ANIM, true);
            else if (baseId == MAIN_ATTACK_1)
                me->CastSpell(me, MH_OH_ATTACK_ANIM, true);

            if (baseId == DEVOUR_MAGIC_1)
            {
                me->CastSpell(me, MH_OH_ATTACK_ANIM, true);

                if (dispelsDealt > 0)
                {
                    //gain 20% of max mana and 5% of max health for every dispel
                    int32 manaGain = me->GetMaxPower(POWER_MANA) / 5 * dispelsDealt;
                    uint32 healthGain = me->GetMaxHealth() / 20 * dispelsDealt;

                    HealInfo hinfo(me, me, healthGain, spellInfo, spellInfo->GetSchoolMask());

                    me->EnergizeBySpell(me, DEVOUR_MAGIC_1, manaGain, POWER_MANA);
                    me->HealBySpell(hinfo);

                    me->CastSpell(me, SPELL_DEVOUR_MAGIC_CASTER_IMPACT, true);
                }

                dispelsDealt = 0;
            }

            if (baseId == DRAIN_MANA_1)
                me->CastSpell(me, MH_OH_ATTACK_ANIM, true);

            if (baseId == REPLENISH_MANA_1)
                me->SendPlaySpellVisual(425); //arcane cast omni
            if (baseId == REPLENISH_HEALTH_1)
                me->SendPlaySpellVisual(21); //empty cast finish anim

            if (baseId == REPLENISH_MANA_1 || baseId == REPLENISH_HEALTH_1)
                me->SetPower(POWER_MANA, 0);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            if (blastVisualTimer < GetLastDiff() && spellId == SPLASH_ATTACK_1)
            {
                blastVisualTimer = 500;
                me->CastSpell(*target, SHADOWFURY_VISUAL, true);
            }
            //Devour Magic: damage to summons
            if (spellId == DEVOUR_MAGIC_1 && target->IsSummon() && target->GetUInt32Value(UNIT_CREATED_BY_SPELL) &&
                !target->IsTotem() && me->GetReactionTo(target) <= REP_NEUTRAL)
            {
                SpellInfo const* devInfo = AssertBotSpellInfoOverride(spellId);
                uint32 damage = std::min<uint32>(target->GetMaxHealth() / 2, me->GetMaxHealth() / 5 + me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC));
                Unit::DealDamage(me, target, damage, nullptr, SPELL_DIRECT_DAMAGE, devInfo->GetSchoolMask(), devInfo);
                OnBotDispelDealt(target, 1);
            }

            if (spellId == DRAIN_MANA_1)
            {
                me->CastSpell(target, SPELL_DEVOUR_MAGIC_BEAM, true);
                target->SendPlaySpellVisual(419); //drain impact visual
            }
            if (spellId == REPLENISH_MANA_1)
                if (target != me)
                    target->SendPlaySpellVisual(524/*436*/); //mana gain visual//heal bigger crimson ish

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void OnBotDispelDealt(Unit* dispelled, uint8 num) override
        {
            //cast drain visual on dispelled
            if (me != dispelled)
            {
                me->CastSpell(dispelled, SPELL_DEVOUR_MAGIC_BEAM, true);
                dispelled->SendPlaySpellVisual(357/*317*/); //purge visual
            }

            dispelsDealt += num;
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
        {
            if (damage)
            {
                dmgReceived += damage / 10;
                uint32 energizeThreshold = me->GetMaxPower(POWER_MANA) / 10;

                int32 manaGain = 0;
                while (dmgReceived >= energizeThreshold)
                {
                    manaGain += energizeThreshold;
                    dmgReceived -= energizeThreshold;
                }
                if (manaGain)
                    me->EnergizeBySpell(me, SPELL_ENERGIZE, manaGain, POWER_MANA);
            }

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

        void CheckAttackState() override
        {
        }

        void Reset() override
        {
            blastVisualTimer = 0;
            DevourcheckTimer = 0;
            DraincheckTimer = 0;
            ReplManacheckTimer = 0;
            ReplHealthcheckTimer = 0;

            dmgReceived = 0;
            dispelsDealt = 0;

            DefaultInit();

            me->SetPower(POWER_MANA, 0);
        }

        void ReduceCD(uint32 diff) override
        {
            if (blastVisualTimer > diff)            blastVisualTimer -= diff;
            if (DevourcheckTimer > diff)            DevourcheckTimer -= diff;
            if (DraincheckTimer > diff)             DraincheckTimer -= diff;
            if (ReplManacheckTimer > diff)          ReplManacheckTimer -= diff;
            if (ReplHealthcheckTimer > diff)        ReplHealthcheckTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            InitSpellMap(MAIN_ATTACK_1, true, false);
            InitSpellMap(SPLASH_ATTACK_1, true, false);
            InitSpellMap(DEVOUR_MAGIC_1, true, false);
            InitSpellMap(DRAIN_MANA_1, true, false);

            InitSpellMap(REPLENISH_MANA_1, true, false);
            InitSpellMap(REPLENISH_HEALTH_1, true, false);
        }

        void ApplyClassPassives() const override
        {
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case DEVOUR_MAGIC_1:
                case DRAIN_MANA_1:
                case REPLENISH_MANA_1:
                case REPLENISH_HEALTH_1:
                    return true;
                default:
                    return false;
            }
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Sphynx_spells_damage;
        }
        //std::vector<uint32> const* GetCCSpellsList() const override
        //{
        //    return &Sphynx_spells_cc;
        //}
        std::vector<uint32> const* GetHealingSpellsList() const override
        {
            return &Sphynx_spells_heal;
        }
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Sphynx_spells_support;
        }

    private:
        uint32 blastVisualTimer;
        uint32 DevourcheckTimer, DraincheckTimer, ReplManacheckTimer, ReplHealthcheckTimer;

        uint32 dmgReceived;
        uint8 dispelsDealt;
    };
};

void AddSC_sphynx_bot()
{
    new sphynx_bot();
}
