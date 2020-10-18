#include "bot_ai.h"
#include "bot_GridNotifiers.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
/*
Dark Ranger NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
A former ranger of Quel'thalas forcibly raised from the dead (Warcraft III tribute)
Specifics:
Spell damage taken reduced by 35%, partially immune to control effects, leather/cloth armor,
deals physical/spellshadow damage, spell power bonus: 50% intellect. Main attribute: Agility
Abilities:
1) Silence. Silences an enemy and up to 4 nearby targets for 8 seconds, 15 seconds cooldown
2) Black Arrow. Fires a cursed arrow dealing 150% weapon damage and additional spellshadow damage over time.
If affected target dies from Dark Ranger\'s damage, a Dark Minion will spawn from the corpse
(maximum 5 Minions, 80 seconds duration, only works on humanoids, beasts and dragonkin),
skeleton level depends on level of the killed unit
Deals five times more damage if target is under 20% health
3) Drain Life. Drains health from an enemy every second for 5 seconds (6 ticks),
healing Dark Ranger for 200% of the drained amount
4) Charm NIY
5ex) Auto Shot. A hunter auto shot ability since dark ranger is purely ranged and only uses bows.
Complete - 75%
TODO: Charm
*/

enum DarkRangerBaseSpells
{
    AUTO_SHOT_1                         = 75,
    BLACK_ARROW_1                       = SPELL_BLACK_ARROW,
    DRAIN_LIFE_1                        = SPELL_DRAIN_LIFE,
    SILENCE_1                           = SPELL_SILENCE
};
enum DarkRangerPassives
{
};
enum DarkRangerSpecial
{
    DRAINLIFE_COST                      = 75 * 5,
    MAX_MINIONS                         = 5,

    SPELL_SPAWN_ANIM                    = 25035,
    SPELL_BLOODY_EXPLOSION              = 36599,
    SPELL_THREAT_MOD                    = 31745, //Salvation

    MODEL_BLOODY_BONES                  = 25538
};

static const uint32 Darkranger_spells_damage_arr[] =
{ BLACK_ARROW_1, DRAIN_LIFE_1 };

static const uint32 Darkranger_spells_cc_arr[] =
{ SILENCE_1 };

static const std::vector<uint32> Darkranger_spells_damage(FROM_ARRAY(Darkranger_spells_damage_arr));
static const std::vector<uint32> Darkranger_spells_cc(FROM_ARRAY(Darkranger_spells_cc_arr));

class dark_ranger_bot : public CreatureScript
{
public:
    dark_ranger_bot() : CreatureScript("dark_ranger_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new dark_ranger_botAI(creature);
    }

    struct dark_ranger_botAI : public bot_ai
    {
/*
        bool GossipHello(Player* player) override
        {
            return OnGossipHello(player, 0);
        }

        bool GossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            return OnGossipSelect(player, me, sender, action);
        }

        bool GossipSelectCode(Player* player, uint32 sender, uint32 action, char const* code) override
        {
            return OnGossipSelectCode(player, me, sender, action, code);
        }
*/
        dark_ranger_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_DARK_RANGER;

            //dark ranger immunities
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
        void JustDied(Unit* u) override { UnsummonAll(); bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void KilledUnit(Unit* u) override
        {
            bot_ai::KilledUnit(u);

            if (u->GetGUID() == _blackArrowKillGUID)
            {
                //black arrow affection -> spawn skeleton (launch)
                SummonBotPet(u);
            }
        }

        void Counter(uint32 diff)
        {
            if (Rand() > 55)
                return;

            if (IsSpellReady(SILENCE_1, diff))
            {
                Unit* target = FindCastingTarget(CalcSpellMaxRange(SILENCE_1), 0, SILENCE_1);
                if (target && doCast(target, GetSpell(SILENCE_1)))
                    return;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            CheckDrainLife(diff);

            if (IsPotionReady())
            {
                if (me->GetPower(POWER_MANA) < DRAINLIFE_COST)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 30)
                    DrinkPotion(false);
            }

            if (!CheckAttackTarget())
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);

                if (!IAmFree() && me->IsStandState() && !me->isMoving() && !master->isMoving() && !me->IsMounted() &&
                    !me->IsInCombat() && !master->IsInCombat() && Rand() < 10 && me->GetDistance(master) < 15 &&
                    !me->HasStealthAura() && !me->HasInvisibilityAura() && !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) &&
                    _minions.empty())
                {
                    me->CastSpell(me, RACIAL_SHADOWMELD, true);
                }

                return;
            }

            if (IsCasting())
                return;

            DoRangedAttack(diff);
        }

        void DoRangedAttack(uint32 diff)
        {
            StartAttack(opponent, IsMelee());

            Counter(diff);

            CheckBlackArrow(diff);

            float dist = me->GetDistance(opponent);
            float maxRangeLong = 30.f;

            bool inpostion = !opponent->HasAuraType(SPELL_AURA_MOD_CONFUSE) || dist > maxRangeLong - 15.f;

            //Auto Shot
            if (Spell const* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            {
                if (shot->GetSpellInfo()->Id == AUTO_SHOT_1 && (shot->m_targets.GetUnitTarget() != opponent || !inpostion))
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }
            else if (HasRole(BOT_ROLE_DPS)/* && dist > 5*/ && dist < maxRangeLong)
            {
                if (doCast(opponent, AUTO_SHOT_1))
                {}
            }

            //RANGED SECTION
            if (dist > maxRangeLong)
                return;

            //Black Arrow
            if (IsSpellReady(BLACK_ARROW_1, diff) && HasRole(BOT_ROLE_DPS) &&
                (Rand() < 20 || !opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x0, 0x4, 0x0, me->GetGUID())))
            {
                if (doCast(opponent, GetSpell(BLACK_ARROW_1)))
                    return;
            }
        }

        void CheckDrainLife(uint32 diff)
        {
            if (!IsSpellReady(DRAIN_LIFE_1, diff) || !HasRole(BOT_ROLE_DPS) || GetHealthPCT(me) > 70 || Rand() > 80 ||
                IsCasting())
                return;

            Unit* target = me->GetVictim();
            if (!target)
                target = FindAffectedTarget(GetSpell(BLACK_ARROW_1), me->GetGUID(), 30);

            if (target && doCast(target, GetSpell(DRAIN_LIFE_1)))
                return;
        }

        void CheckBlackArrow(uint32 diff)
        {
            if (!IsSpellReady(BLACK_ARROW_1, diff) || !HasRole(BOT_ROLE_DPS) || Rand() > 30)
                return;

            std::list<Unit*> targets;
            GetNearbyTargetsList(targets, 50, 0);
            targets.remove_if(BOTAI_PRED::AuraedTargetExcludeByCaster(BLACK_ARROW_1, me->GetGUID()));
            if (Unit* target = !targets.empty() ? Trinity::Containers::SelectRandomContainerElement(targets) : nullptr)
            {
                if (doCast(target, GetSpell(BLACK_ARROW_1)))
                    return;
            }
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& /*crit_chance*/, SpellInfo const* /*spellInfo*/, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const override
        {
        }

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool /*crit*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            float flat_mod = 0.f;

            //2) apply bonus damage mods
            float pctbonus = 1.0f;
            //Black Arrow on targets < 20% hp (only direct damage)
            if (baseId == BLACK_ARROW_1 && damageinfo.target && damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))
                pctbonus *= 5.f;

            damage = int32(damage * pctbonus + flat_mod);
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool /*crit*/) const override
        {
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();
            float fdamage = float(damage);
            float flat_mod = 0.f;

            //2) apply bonus damage mods
            float pctbonus = 1.0f;
            //if (crit)
            //{
            //    //!!!spell damage is not yet critical and will be multiplied by 1.5
            //    //so we should put here bonus damage mult /1.5
            //    //Lava Flows (part 1): 24% additional crit damage bonus for Lava Burst
            //    if (lvl >= 50 && spellId == GetSpell(LAVA_BURST_1))
            //        pctbonus *= 1.16f;
            //}
            ////Trap Mastery part 2: 30% bonus damage for Immolation Trap, Explosive Trap and Black Arrow
            //if (lvl >= 15 && (baseId == IMMOLATION_TRAP_AURA_1 || baseId == EXPLOSIVE_TRAP_AURA_1 || baseId == BLACK_ARROW_1))
            //    pctbonus *= 1.3f;
            //Black Arrow on targets < 20% hp (only direct damage)
            //if (baseId == BLACK_ARROW_1 && damageinfo.target && damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))
            //    pctbonus *= 5.f;

            damage = int32(fdamage * pctbonus + flat_mod);
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //Drain Life scaling from health pool: 2%
            if (baseId == DRAIN_LIFE_1 && effIndex == EFFECT_0)
                value += float(me->GetMaxHealth()) * 0.02f;

            value = value * pctbonus;
        }

        void ApplyClassEffectMods(Unit const* /*target*/, SpellInfo const* /*spellInfo*/, uint8 /*effIndex*/, float& value) const
        {
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            float pctbonus = 1.0f;

            value = value * pctbonus;
        }

        void OnClassSpellGo(SpellInfo const* /*spellInfo*/) override
        {
            //uint32 spellId = spellInfo->Id;
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            //Rapid Killing: use up buff manually
            //if (baseId == AIMED_SHOT_1 || baseId == ARCANE_SHOT_1 || baseId == CHIMERA_SHOT_1)
            //{
            //    if (AuraEffect const* rapi = me->GetAuraEffect(RAPID_KILLING_BUFF, 0))
            //        if (rapi->IsAffectedOnSpell(spellInfo))
            //            me->RemoveAura(RAPID_KILLING_BUFF);
            //}
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* /*spell*/) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            if (target == me)
                return;

            //uint32 baseId = spell->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();

            //if (baseId == HUNTERS_MARK_1)
            //{
            //    //DarkRanger's Mark helper
            //    if (AuraEffect* mark = target->GetAuraEffect(spell->Id, 1, me->GetGUID()))
            //    {
            //        //Glyph of DarkRanger's Mark: +20% effect
            //        //Improved DarkRanger's Mark: +30% effect
            //        if (lvl >= 15)
            //            mark->ChangeAmount(mark->GetAmount() + mark->GetAmount() / 2);
            //        else if (lvl >= 10)
            //            mark->ChangeAmount(mark->GetAmount() * 13 / 10);
            //    }
            //}
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
            //black arrow affection -> spawn skeleton (mark)
            if (damage && me->IsAlive() && victim->GetTypeId() == TYPEID_UNIT && damage >= victim->GetHealth() &&
                (victim->GetCreatureType() == CREATURE_TYPE_BEAST ||
                victim->GetCreatureType() == CREATURE_TYPE_DRAGONKIN ||
                victim->GetCreatureType() == CREATURE_TYPE_HUMANOID) &&
                ((spellInfo && spellInfo->GetFirstRankSpell()->Id == BLACK_ARROW_1) ||
                victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x0, 0x4, 0x0, me->GetGUID())))
                _blackArrowKillGUID = victim->GetGUID();
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

        uint8 GetPetPositionNumber(Creature const* summon) const override
        {
            uint8 i = 0;
            for (Summons::const_iterator citr = _minions.begin(); citr != _minions.end(); ++citr)
            {
                if ((*citr)->GetGUID() == summon->GetGUID())
                    return i;
                ++i;
            }
            return 0;
        }

        void SummonBotPet(Unit* from)
        {
            if (_minions.size() >= MAX_MINIONS)
            {
                //TC_LOG_ERROR("entities.player", "bot_dranger_ai::SummonBotPet(): max minions");
                Unit* u = nullptr;
                //try 1: by minimal level
                uint8 minlevel = me->GetLevel();
                for (Summons::const_iterator itr = _minions.begin(); itr != _minions.end(); ++itr)
                {
                    if ((*itr)->GetLevel() < minlevel)
                    {
                        minlevel = (*itr)->GetLevel();
                        u = *itr;
                    }
                }
                //try 2: by minimal duration
                if (!u)
                {
                    uint32 minduration = 0;
                    for (Summons::const_iterator itr = _minions.begin(); itr != _minions.end(); ++itr)
                    {
                        if ((*itr)->GetAI()->GetData(BOTPETAI_MISC_DURATION) > minduration)
                        {
                            minduration = (*itr)->GetAI()->GetData(BOTPETAI_MISC_DURATION);
                            u = *itr;
                        }
                    }
                }
                //if (u)
                //    TC_LOG_ERROR("entities.player", "bot_dranger_ai::SummonBotPet(): found minion to erase(1)");
                //try 3: last resort
                if (!u)
                u = *(_minions.begin());
                //if (u)
                //    TC_LOG_ERROR("entities.player", "bot_dranger_ai::SummonBotPet(): found minion to erase(2)");

                u->ToTempSummon()->UnSummon();
            }

            //addition: change unit's modelid
            if (!from->IsPet() && !from->IsVehicle() &&
                !from->ToCreature()->isWorldBoss() &&
                !from->ToCreature()->IsDungeonBoss())
            {
                from->CastSpell(from, SPELL_BLOODY_EXPLOSION, true);
                from->SetDisplayId(MODEL_BLOODY_BONES);
            }

            uint32 rank = from->ToCreature()->GetCreatureTemplate()->rank;
            uint32 entry = (rank == CREATURE_ELITE_NORMAL) ? BOT_PET_DARK_MINION : BOT_PET_DARK_MINION_ELITE;

            uint8 maxLevel = std::min<uint8>(from->GetLevel(), me->GetLevel());

            Position pos = from->GetPosition();

            Creature* myPet = me->SummonCreature(entry, pos, TEMPSUMMON_MANUAL_DESPAWN);
            myPet->SetCreatorGUID(master->GetGUID());
            myPet->SetOwnerGUID(master->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, BLACK_ARROW_1);

            //dark minion immunities
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            myPet->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
            //heal
            myPet->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL, true);
            myPet->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL_PCT, true);
            myPet->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_PERIODIC_HEAL, true);

            //myPet->CastSpell(myPet, SPELL_BLOODY_EXPLOSION, true);
            myPet->CastSpell(myPet, SPELL_SPAWN_ANIM, true);
            if (Aura* stun = myPet->AddAura(SUMMONING_DISORIENTATION, myPet))
            {
                stun->SetDuration(1500);
                stun->SetMaxDuration(1500);
            }

            myPet->GetAI()->SetData(BOTPETAI_MISC_MAXLEVEL, maxLevel);
            _minions.insert(myPet);
        }

        void UnsummonAll() override
        {
            while (!_minions.empty())
                (*_minions.begin())->ToTempSummon()->UnSummon();
            //for (Summons::const_iterator itr = _minions.begin(); itr != _minions.end(); ++itr)
            //    (*itr)->ToTempSummon()->UnSummon();

            //_minions.clear();
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDies: %s's %s", me->GetName().c_str(), summon->GetName().c_str());
            //if (summon == botPet)
            //    botPet = nullptr;
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //all darkranger bot pets despawn at death or manually (gossip, teleport, etc.)
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: %s's %s", me->GetName().c_str(), summon->GetName().c_str());
            if (_minions.find(summon) != _minions.end())
                _minions.erase(summon);
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(BLACK_ARROW_1) - 5.f : 15.f;
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_DARK_MINION;
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            UnsummonAll();

            //for (uint8 i = 0; i != MAX_SPELL_SCHOOL; ++i)
            //    me->m_threatModifier[1] = 0.0f;

            _blackArrowKillGUID = 0;

            DefaultInit();

            //threat mod
            if (Aura* threat = me->AddAura(SPELL_THREAT_MOD, me))
                threat->GetEffect(0)->ChangeAmount(-100);
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
            InitSpellMap(AUTO_SHOT_1);
            InitSpellMap(BLACK_ARROW_1);
            InitSpellMap(DRAIN_LIFE_1);
            InitSpellMap(SILENCE_1);
        }

        void ApplyClassPassives() const override
        {
        }

        std::vector<uint32> const* GetDamagingSpellsList() const
        {
            return &Darkranger_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const
        {
            return &Darkranger_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const
        //{
        //    return &Darkranger_spells_heal;
        //}
        //std::vector<uint32> const* GetSupportSpellsList() const
        //{
        //    return &Darkranger_spells_support;
        //}
    private:
        uint64 _blackArrowKillGUID;
        typedef std::set<Unit*> Summons;
        Summons _minions;
    };
};

void AddSC_dark_ranger_bot()
{
    new dark_ranger_bot();
}
