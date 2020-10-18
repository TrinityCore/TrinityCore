#include "bot_ai.h"
#include "bot_GridNotifiers.h"
//#include "GridNotifiers.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
/*
Spell Breaker NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
Spellbreaker (Warcraft III tribute)
Abilities:
1) Steal Magic (Spellsteal). steals a benefical spell from an enemy and applies it to a nearby ally or removes a
negative spell from an ally and applies it to a nearby enemy, affects magic and curse effects, 3 seconds cooldown.
2) Control Magic NIY (no substitute for spell)
3) Feedback (passive). Successful melee attacks burn target's mana equal to damage caused, dealing arcane damage
Complete - 67%
TODO:
*/

enum SpellbreakerBaseSpells
{
    SPELLSTEAL_1            = SPELL_STEAL_MAGIC
};
enum SpellbreakerPassives
{
};
enum SpellbreakerSpecial
{
    SPELLSTEAL_COST         = 75 * 5,

    FEEDBACK_EFFECT         = SPELL_FEEDBACK,

    MH_ATTACK_VISUAL        = SPELL_ATTACK_MELEE_1H,
    SPELLSTEAL_VISUAL       = 34396 //Zap selfcast
};

static const uint32 Spellbreaker_spells_support_arr[] =
{ SPELLSTEAL_1 };

static const std::vector<uint32> Spellbreaker_spells_support(FROM_ARRAY(Spellbreaker_spells_support_arr));

class spellbreaker_bot : public CreatureScript
{
public:
    spellbreaker_bot() : CreatureScript("spellbreaker_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new spellbreaker_botAI(creature);
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
    struct spellbreaker_botAI : public bot_ai
    {
        spellbreaker_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_SPELLBREAKER;

            //spellbreaker immunities
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
        void JustDied(Unit* u) override { /*UnsummonAll();*/ bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            if (IsPotionReady())
            {
                if (me->GetPower(POWER_MANA) < SPELLSTEAL_COST)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            if ((me->GetVictim() || Rand() < 15) && IsSpellReady(SPELLSTEAL_1, diff))
                CureGroup(GetSpell(SPELLSTEAL_1), diff);

            if (master->IsInCombat() || me->IsInCombat())
                CheckDispel(diff);

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            Attack(diff);
        }

        void Attack(uint32 /*diff*/)
        {
            StartAttack(opponent, IsMelee());

            MoveBehind(opponent);
        }

        void CheckDispel(uint32 diff)
        {
            if (!IsSpellReady(SPELLSTEAL_1, diff) || IsCasting())
                return;

            Unit* target = FindHostileDispelTarget(CalcSpellMaxRange(SPELLSTEAL_1));
            if (target && doCast(target, GetSpell(SPELLSTEAL_1)))
                return;

            SetSpellCooldown(SPELLSTEAL_1, 500); //fail
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& damageinfo) const override
        {
            float pctbonus = 1.0f;

            if (damageinfo.Target && damageinfo.Target->GetPowerType() == POWER_MANA && damageinfo.Target->GetMaxPower(POWER_MANA) > 1 &&
                damageinfo.Target->GetPower(POWER_MANA) < me->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE))
            {
                pctbonus *= 3.f;
                if (_doCrit == false && urand(1,100) < 2 * GetBotCritChance())
                    const_cast<spellbreaker_botAI*>(this)->_doCrit = true;
            }
            else if (_doCrit == true)
                const_cast<spellbreaker_botAI*>(this)->_doCrit = false;

            damageinfo.Damages[0].Damage *= pctbonus;
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            float pctbonus = 1.0f;

            //Feedback scaling: 50%
            if (baseId == FEEDBACK_EFFECT && effIndex == EFFECT_0)
                value += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.5f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);

            value = value * pctbonus;
        }

        MeleeHitOutcome GetNextAttackMeleeOutCome() const override
        {
            return _doCrit ? MELEE_HIT_CRIT : bot_ai::GetNextAttackMeleeOutCome();
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == FEEDBACK_EFFECT)
                me->CastSpell(me, MH_ATTACK_VISUAL, true);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;

            if (baseId == SPELLSTEAL_1)
                ProcessSpellsteal(target);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            //Feedback
            if (damage && victim != me && damageType == DIRECT_DAMAGE && victim->GetPowerType() == POWER_MANA)
            {
                if (uint32 burned = std::min<uint32>(victim->GetPower(POWER_MANA), damage + me->GetLevel() * 2))
                {
                    int32 basepoints = int32(burned);
                    //reduce amount againts ex bots
                    if (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->GetBotClass() >= BOT_CLASS_EX_START)
                        basepoints /= 10;

                    CastSpellExtraArgs args(true);
                    args.AddSpellBP0(basepoints);
                    me->CastSpell(victim, FEEDBACK_EFFECT, args);
                }
            }

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

        void Reset() override
        {
            _doCrit = false;

            DefaultInit();
        }

        void ReduceCD(uint32 /*diff*/) override
        {
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            InitSpellMap(SPELLSTEAL_1, true, false);
        }

        void ApplyClassPassives() const override
        {
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case SPELLSTEAL_1:
                    return true;
                default:
                    return false;
            }
        }

        //std::vector<uint32> const* GetDamagingSpellsList() const
        //{
        //    return &Spellbreaker_spells_damage;
        //}
        //std::vector<uint32> const* GetCCSpellsList() const
        //{
        //    return &Spellbreaker_spells_cc;
        //}
        //std::vector<uint32> const* GetHealingSpellsList() const
        //{
        //    return &Spellbreaker_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const
        {
            return &Spellbreaker_spells_support;
        }

    private:

        bool _doCrit;

        void ProcessSpellsteal(Unit* target)
        {
            DispelChargesList steal_list;

            bool const isFriend = IsInBotParty(target) || target->IsFriendlyTo(me);
            static const uint32 sbDispelMask  = (1<<DISPEL_MAGIC) | (1<<DISPEL_CURSE);
            static const uint8 max_dispelled = 1;

            //TC_LOG_ERROR("entities.unit", "ProcessSpellsteal: on %s, fr=%u", target->GetName().c_str(), uint32(isFriend));

            Unit::AuraMap const& auras = target->GetOwnedAuras();
            for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
            {
                Aura* aura = itr->second;

                if (aura->IsPassive() || !(aura->GetSpellInfo()->GetDispelMask() & sbDispelMask) ||
                    (aura->GetSpellInfo()->AttributesEx4 & SPELL_ATTR4_NOT_STEALABLE))
                    continue;

                AuraApplication const* aurApp = aura->GetApplicationOfTarget(target->GetGUID());
                if (!aurApp)
                    continue;

                //do not dispel positive auras from enemies and negative ones from friends
                if (aurApp->IsPositive() == isFriend)
                    continue;

                int32 chance = aura->CalcDispelChance(target, !isFriend);
                if (!chance)
                    continue;
                //TC_LOG_ERROR("entities.unit", "%s", aura->GetSpellInfo()->SpellName[0]);

                // The charges / stack amounts don't count towards the total number of auras that can be dispelled.
                // Ie: A dispel on a target with 5 stacks of Winters Chill and a Polymorph has 1 / (1 + 1) -> 50% chance to dispell
                // Polymorph instead of 1 / (5 + 1) -> 16%.
                bool dispel_charges = (aura->GetSpellInfo()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES);
                uint8 charges = dispel_charges ? aura->GetCharges() : aura->GetStackAmount();
                if (charges > 0)
                    steal_list.emplace_back(aura, chance, charges);
            }

            if (steal_list.empty())
                return;

            //TC_LOG_ERROR("entities.unit", "failcount...");

            size_t remaining = steal_list.size();
            uint32 failCount = 0;
            DispelChargesList success_list;
            success_list.reserve(max_dispelled);
            WorldPacket dataFail(SMSG_DISPEL_FAILED, 8+8+4+4+max_dispelled*4);
            // dispel N = damage buffs (or while exist buffs for dispel)
            for (uint8 count = 0; count < max_dispelled && remaining > 0;)
            {
                // Random select buff for dispel
                DispelChargesList::iterator itr = steal_list.begin();
                std::advance(itr, urand(0, steal_list.size() - 1));

                //int32 chance = itr->RollDispel();//itr->first->CalcDispelChance(target, !isFriend);
                // 2.4.3 Patch Notes: "Dispel effects will no longer attempt to remove effects that have 100% dispel resistance."
                //if (!chance)
                //{
                //    steal_list.erase(itr);
                //    continue;
                //}
                //else
                bool chance = itr->RollDispel();
                {
                    if (chance/*roll_chance_i(chance)*/)
                    {
                        auto successItr = std::find_if(success_list.begin(), success_list.end(), [&itr](DispelableAura& dispelAura) -> bool
                        {
                            if (dispelAura.GetAura()->GetId() == itr->GetAura()->GetId() && dispelAura.GetAura()->GetCaster() == itr->GetAura()->GetCaster())
                                return true;
                            return false;
                        });

                        if (successItr == success_list.end())
                            success_list.emplace_back(itr->GetAura(), 0, 1);
                        else
                            successItr->IncrementCharges();

                        if (!itr->DecrementCharge())
                        {
                            --remaining;
                            std::swap(*itr, steal_list[remaining]);
                        }
                        //success_list.push_back(std::make_pair(itr->first->GetId(), itr->first->GetCasterGUID()));
                        //--itr->second;
                        //if (itr->second <= 0)
                        //    steal_list.erase(itr);
                    }
                    else
                    {
                        if (!failCount)
                        {
                            // Failed to dispell
                            dataFail << uint64(me->GetGUID());                  // Caster GUID
                            dataFail << uint64(target->GetGUID());              // Victim GUID
                            dataFail << uint32(SPELLSTEAL_1);                   // dispel spell id
                        }
                        ++failCount;
                        dataFail << uint32(itr->GetAura()->GetId());                // Spell Id
                    }
                    ++count;
                }
            }

            if (failCount)
                me->SendMessageToSet(&dataFail, true);

            if (success_list.empty())
                return;

            //TC_LOG_ERROR("entities.unit", "logs and auras");

            WorldPacket dataSuccess(SMSG_SPELLSTEALLOG, 8+8+4+1+4+max_dispelled*5);
            dataSuccess << target->GetPackGUID();           // Victim GUID
            dataSuccess << me->GetPackGUID();               // Caster GUID
            dataSuccess << uint32(SPELLSTEAL_1);            // dispel spell id
            dataSuccess << uint8(0);                        // not used
            dataSuccess << uint32(success_list.size());     // count

            Unit* randomTarget = nullptr;

            std::list<Unit*> targets;

            if (isFriend) //negative spell from friend to enemy
            {
                GetNearbyTargetsList(targets, 50, 0);
                if (Unit* u = me->GetVictim())
                {
                    if (!u->GetVictim() && me->IsWithinDistInMap(u, 50) && !me->IsFriendlyTo(u) &&
                        me->IsValidAttackTarget(u) && u->GetCreatureType() != CREATURE_TYPE_CRITTER && !u->IsTotem() &&
                        me->CanSeeOrDetect(u))
                        targets.push_back(u);
                }
                //Trinity::AnyUnfriendlyAttackableVisibleUnitInObjectRangeCheck check(me, 50.f);
                //Trinity::UnitListSearcher<Trinity::AnyUnfriendlyAttackableVisibleUnitInObjectRangeCheck> searcher(me, targets, check);
                //me->VisitNearbyObject(50.f, searcher);
            }
            else
            {
                GetNearbyFriendlyTargetsList(targets, 50); //not self
                targets.push_back(me); //add self
            }

            if (!targets.empty())
            {
                //if target has stealed aura we should skip him if possible
                std::list<Unit*> targetsCopy = targets;
                targets.remove_if(BOTAI_PRED::AuraedTargetExclude(success_list.front().GetAura()->GetId()));

                randomTarget = Trinity::Containers::SelectRandomContainerElement(!targets.empty() ? targets : targetsCopy);
            }

            for (DispelChargesList::iterator itr = success_list.begin(); itr != success_list.end(); ++itr)
            {
                dataSuccess << uint32(itr->GetAura()->GetId());          // Spell Id
                dataSuccess << uint8(0);                    // 0 - steals !=0 transfers

                if (randomTarget)
                {
                    //target->RemoveAurasDueToSpellBySteal(itr->first, itr->second, randomTarget);
                    TransferAura(itr->GetAura()->GetId(), itr->GetAura()->GetCasterGUID(), target, randomTarget);
                    randomTarget->CastSpell(randomTarget, SPELLSTEAL_VISUAL, true);
                }
                else
                    target->RemoveAurasDueToSpellByDispel(itr->GetAura()->GetId(), SPELLSTEAL_1, itr->GetAura()->GetCasterGUID(), me, uint8(-1));
            }

            me->SendMessageToSet(&dataSuccess, true);
        }

        void TransferAura(uint32 spellId, ObjectGuid casterGUID, Unit* target, Unit* newTarget)
        {
            //Copied from Unit::RemoveAurasDueToSpellBySteal with modifications
            Unit::AuraMapBoundsNonConst range = target->GetOwnedAuras().equal_range(spellId);
            for (Unit::AuraMap::iterator iter = range.first; iter != range.second;)
            {
                Aura* aura = iter->second;
                if (aura->GetCasterGUID() == casterGUID)
                {
                    int32 damage[MAX_SPELL_EFFECTS];
                    int32 baseDamage[MAX_SPELL_EFFECTS];
                    uint8 effMask = 0;
                    uint8 recalculateMask = 0;
                    Unit* caster = aura->GetCaster();
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        if (aura->GetEffect(i))
                        {
                            baseDamage[i] = aura->GetEffect(i)->GetBaseAmount();
                            damage[i] = aura->GetEffect(i)->GetAmount();
                            effMask |= (1<<i);
                            if (aura->GetEffect(i)->CanBeRecalculated())
                                recalculateMask |= (1<<i);
                        }
                        else
                        {
                            baseDamage[i] = 0;
                            damage[i] = 0;
                        }
                    }

                    bool stealCharge = (aura->GetSpellInfo()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES);
                    // Limit max duration to 5 minutes
                    int32 dur = std::min<int32>(int32(5 * MINUTE * IN_MILLISECONDS), aura->GetDuration());
                    // But at least for 5 seconds
                    dur = std::max<int32>(dur, 5 * IN_MILLISECONDS);

                    if (Aura* oldAura = newTarget->GetAura(aura->GetId(), aura->GetCasterGUID()))
                    {
                        if (stealCharge)
                            oldAura->ModCharges(aura->GetCharges());
                        else
                            oldAura->ModStackAmount(aura->GetStackAmount());
                        oldAura->SetDuration(std::max<int32>(dur, oldAura->GetDuration()));
                    }
                    else
                    {
                        // single target state must be removed before aura creation to preserve existing single target aura
                        if (aura->IsSingleTarget())
                            aura->UnregisterSingleTarget();

                        AuraCreateInfo createInfo(aura->GetSpellInfo(), effMask, newTarget);
                        createInfo.SetCasterGUID(aura->GetCasterGUID());
                        createInfo.SetBaseAmount(baseDamage);
                        if (Aura* newAura = Aura::TryRefreshStackOrCreate(createInfo))
                        {
                            // created aura must not be single target aura,, so stealer won't loose it on recast
                            if (newAura->IsSingleTarget())
                            {
                                newAura->UnregisterSingleTarget();
                                aura->SetIsSingleTarget(true);
                                caster->GetSingleCastAuras().push_back(aura);
                            }
                            newAura->SetLoadedState(aura->GetMaxDuration(), dur, aura->GetCharges(), aura->GetStackAmount(), recalculateMask, aura->GetCritChance(), aura->CanApplyResilience(), &damage[0]);
                            newAura->ApplyForTargets();
                        }
                    }

                    aura->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                    return;
                }
                else
                    ++iter;
            }
        }
    };
};

void AddSC_spellbreaker_bot()
{
    new spellbreaker_bot();
}
