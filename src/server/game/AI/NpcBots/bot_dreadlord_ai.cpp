#include "bot_ai.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
/*
Dreadlord NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
Incredibly powerful demon who wields power of darkness and mental domination
Specifics:
High armor, high resistances, partially immune to control effects, damage taken speeds up spells recharge, plate armor,
deals melee/spellshadow damage, bonus damage to CCed units, spell power bonus: 200% strength.
Abilities:
1) Carrion Swarm. Sends a horde of bats combined with chaotic magic to damage enemies in frontal cone, 10 seconds cooldown.
2) Sleep. Puts the enemy target to sleep for 60 seconds (15 seconds on players) and allows next physical attack
on that target to bypass armor, removed by direct damage, 6 seconds cooldown.
3) Vampiric Aura. Increases physical critical damage by 5% and heals party and raid members within 40 yards for a
percentage (100% for Dreadlord and 25% for everyone else) of damage done by physical attacks and Carrion Swarm, no threat.
4) Summon Infernal Servant. Calls an infernal down from the sky dealing damage and stunning enemy units, lasts 180 seconds, 180 seconds cooldown.
Complete - 100%
TODO:
*/

enum DreadlordBaseSpells
{
    CARRION_SWARM_1         = SPELL_CARRION_SWARM,
    SLEEP_1                 = SPELL_SLEEP,
    INFERNO_1               = SPELL_INFERNO
};
enum DreadlordPassives
{
    VAMPIRIC_AURA           = SPELL_VAMPIRIC_AURA,
};
enum DreadlordSpecial
{
    MH_ATTACK_ANIM          = SPELL_ATTACK_MELEE_1H,

    CARRION_COST            = 110 * 5,
    SLEEP_COST              = 50 * 5,
    INFERNAL_COST           = 175 * 5,

    DAMAGE_CD_REDUCTION     = 250,//ms
    INFERNO_SPAWN_DELAY     = 650,//ms

    IMMOLATION              = 39007
};

static const uint32 Dreadlord_spells_damage_arr[] =
{ CARRION_SWARM_1, INFERNO_1 };

static const uint32 Dreadlord_spells_cc_arr[] =
{ SLEEP_1 };

static const uint32 Dreadlord_spells_support_arr[] =
{ INFERNO_1 };

static const std::vector<uint32> Dreadlord_spells_damage(FROM_ARRAY(Dreadlord_spells_damage_arr));
static const std::vector<uint32> Dreadlord_spells_cc(FROM_ARRAY(Dreadlord_spells_cc_arr));
static const std::vector<uint32> Dreadlord_spells_support(FROM_ARRAY(Dreadlord_spells_support_arr));

class dreadlord_bot : public CreatureScript
{
public:
    dreadlord_bot() : CreatureScript("dreadlord_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new dreadlord_botAI(creature);
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
    struct dreadlord_botAI : public bot_ai
    {
    private:
        //DelayedPetSpawnEvent - Dreadlord
        //Impact anim, spawn, linked effects
        class DelayedPetSpawnEvent : public BasicEvent
        {
            public:
                DelayedPetSpawnEvent(Creature const* bot, Position const* pos) : _bot(bot), _pos(pos) { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    ((dreadlord_botAI*)_bot->AI())->SummonBotPet(_pos);
                    return true;
                }

            private:
                Creature const* _bot;
                Position const* _pos;
                DelayedPetSpawnEvent(DelayedPetSpawnEvent const&);
        };

    public:
        dreadlord_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_DREADLORD;

            //dreadlord immunities
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_POSSESS, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM_OFFHAND, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_TURN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
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
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonAll(); bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void CheckAura(uint32 diff)
        {
            if (checkAuraTimer > diff || GC_Timer > diff || IsCasting())
                return;

            checkAuraTimer = 10000;

            if (!me->HasAura(VAMPIRIC_AURA, me->GetGUID()))
                RefreshAura(VAMPIRIC_AURA);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            //if (!me->IsInCombat())
            //    DoNonCombatActions(diff);

            CheckAura(diff);

            if (IsPotionReady())
            {
                if (me->GetPower(POWER_MANA) < CARRION_COST)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            if (IsCasting())
                return;

            if (IsSpellReady(INFERNO_1, diff) && !botPet && me->IsInCombat() &&
                me->GetPower(POWER_MANA) >= INFERNAL_COST && Rand() < 60)
            {
                Unit* target = FindAOETarget(CalcSpellMaxRange(INFERNO_1));

                if (target)
                    _infernoPos = target->GetPosition();
                else
                    me->GetNearPoint(me, _infernoPos.m_positionX, _infernoPos.m_positionY, _infernoPos.m_positionZ, 5.f, 0.f);

                me->CastSpell(_infernoPos, GetSpell(INFERNO_1), false);
                return;
            }

            if (!CheckAttackTarget())
                return;

            CheckSleep(diff);

            Attack(diff);
        }

        void Attack(uint32 diff)
        {
            StartAttack(opponent, IsMelee());

            MoveBehind(opponent);

            if (!HasRole(BOT_ROLE_DPS))
                return;

            if (IsSpellReady(CARRION_SWARM_1, diff) && me->GetPower(POWER_MANA) >= CARRION_COST && Rand() < 80)
            {
                bool cast = false;
                if (me->HasInArc(M_PI/2, opponent) && me->GetDistance(opponent) < 25 &&
                    (IsTank() || GetManaPCT(me) > 60 || me->getAttackers().empty() || GetHealthPCT(me) < 50 ||
                    opponent->HasAura(SLEEP_1)))
                {
                    cast = true;
                }

                if (!cast)
                {
                    std::list<Unit*> targets;
                    GetNearbyTargetsInConeList(targets, 25); //real radius is 30
                    if (targets.size() > 1)
                    {
                        cast = true;
                    }
                }

                if (cast && doCast(me, GetSpell(CARRION_SWARM_1)))
                    return;
            }
        }

        void CheckSleep(uint32 diff)
        {
            if (!IsSpellReady(SLEEP_1, diff) || IsCasting() || Rand() > 50)
                return;

            //fleeing/casting/solo enemy
            Unit* u = me->GetVictim();
            if (u && IsSpellReady(CARRION_SWARM_1, diff, false) && !CCed(u) && me->GetDistance(u) < CalcSpellMaxRange(SLEEP_1) &&
                (u->IsNonMeleeSpellCast(false,false, true) || (u->IsInCombat() && u->getAttackers().size() == 1)))
            {
                if (doCast(u, GetSpell(SLEEP_1)))
                    return;
            }

            if (Unit* target = FindCastingTarget(CalcSpellMaxRange(SLEEP_1), 0, SLEEP_1))
            {
                if (doCast(target, GetSpell(SLEEP_1)))
                    return;
            }

            if (Unit* target = FindStunTarget(CalcSpellMaxRange(SLEEP_1)))
            {
                if (doCast(target, GetSpell(SLEEP_1)))
                    return;
            }
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& damageinfo) const override
        {
            float pctbonus = 1.0f;

            //150% damage on CCed units
            if (CCed(damageinfo.Target))
                pctbonus *= 1.5f;

            damageinfo.Damages[0].Damage *= pctbonus;
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool crit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 1.0f;
            if (crit)
                pctbonus *= 1.333f;

            //double damage on CCed units
            if (CCed(damageinfo.target))
                pctbonus *= 2.f;

            if (baseId == CARRION_SWARM_1)
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * (spellInfo->Effects[0].BonusMultiplier - 1.f) * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);

            damage = int32(fdamage * pctbonus);
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == CARRION_SWARM_1)
            {
                me->resetAttackTimer();
                me->CastSpell(me, MH_ATTACK_ANIM, true);
            }

            if (baseId == INFERNO_1)
            {
                me->CastSpell(_infernoPos, SPELL_INFERNO_METEOR_VISUAL, true);
                DelayedPetSpawnEvent* spawnEvent = new DelayedPetSpawnEvent(me, &_infernoPos);
                Events.AddEvent(spawnEvent, Events.CalculateTime(std::chrono::milliseconds(INFERNO_SPAWN_DELAY)));
            }
        }

        void SpellHitTarget(WorldObject* /*wtarget*/, SpellInfo const* /*spell*/) override
        {
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void OnBotDamageDealt(Unit* victim, uint32 damage, CleanDamage const* /*cleanDamage*/, DamageEffectType /*damagetype*/, SpellInfo const* spellInfo) override
        {
            //Carrion swarm heal
            if (damage && victim != me && spellInfo && spellInfo->GetFirstRankSpell()->Id == CARRION_SWARM_1)
            {
                int32 basepoints0 = std::min<uint32>(damage, victim->GetHealth());
                //TC_LOG_ERROR("entities.unit", "OnBotDamageDealt(drl): %s on %s base val %i (%s),",
                //    me->GetName().c_str(), victim->GetName().c_str(), int32(damage), spellInfo->SpellName[0]);
                CastSpellExtraArgs args(true);
                args.AddSpellBP0(basepoints0);
                me->CastSpell(me, SPELL_TRIGGERED_HEAL, args);
            }
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& damage) override
        {
            if (damage)
            {
                BotSpellMap const& spells = GetSpellMap();
                for (BotSpellMap::const_iterator itr = spells.begin(); itr != spells.end(); ++itr)
                {
                    //not affected if pet is alive
                    if (botPet && itr->first == INFERNO_1)
                        continue;

                    uint32& cooldown = itr->second->cooldown;
                    if (!cooldown)
                        continue;

                    cooldown = cooldown > DAMAGE_CD_REDUCTION ? cooldown - DAMAGE_CD_REDUCTION : 0;
                }
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

        void SummonBotPet(Position const* sPos)
        {
            if (botPet)
                UnsummonAll();

            uint32 entry = BOT_PET_INFERNAL;

            //Position pos;

            Creature* myPet = me->SummonCreature(entry, *sPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, std::chrono::milliseconds(2000));
            //me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0, 2, me->GetOrientation());
            //myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            myPet->SetCreatorGUID(master->GetGUID());
            myPet->SetOwnerGUID(master->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            //immune
            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, INFERNO_1);
            //dreadlord immunities
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_TURN, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);

            //myPet->SetMeleeDamageSchool(SPELL_SCHOOL_FIRE);

            //infernal is immune to magic
            //myPet->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
            myPet->CastSpell(myPet, SPELL_INFERNO_EFFECT, true); //damage, stun
            //myPet->CastSpell(myPet, SPELL_INFERNO_IMPACT_EXPLOSION, true); //visual
            myPet->CastSpell(myPet, IMMOLATION, true);

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
                    return BOT_PET_INFERNAL;
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            checkAuraTimer = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (checkAuraTimer > diff)              checkAuraTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            InitSpellMap(CARRION_SWARM_1, true, false);
            InitSpellMap(SLEEP_1, true, false);
            InitSpellMap(INFERNO_1);
        }

        void ApplyClassPassives() const override
        {
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case CARRION_SWARM_1:
                    return true;
                default:
                    return false;
            }
        }

        std::vector<uint32> const* GetDamagingSpellsList() const
        {
            return &Dreadlord_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const
        {
            return &Dreadlord_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const
        //{
        //    return &Dreadlord_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const
        {
            return &Dreadlord_spells_support;
        }

    private:
        uint32 checkAuraTimer;
        Position _infernoPos;
    };
};

void AddSC_dreadlord_bot()
{
    new dreadlord_bot();
}
