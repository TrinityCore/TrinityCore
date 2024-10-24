#include "bot_ai.h"
#include "bot_GridNotifiers.h"
#include "botmgr.h"
#include "botspell.h"
#include "bottext.h"
#include "bottraits.h"
#include "CellImpl.h"
#include "Containers.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
//#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
//#include "World.h"
/*
Necromancer NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
Necromancer (Warcraft III / Disablo II tribute)
Abilities:
1) Shadow Bolt: main attack, single target, no mana cost
Complete - 90%
TODO:
maximum skeletons for botparty
fine-tune corpse explosion conditions
*/

enum NecromancerBaseSpells
{
    MAIN_ATTACK_1           = SPELL_SHADOW_BOLT2,
    RAISE_DEAD_1            = SPELL_RAISE_DEAD,
    UNHOLY_FRENZY_1         = SPELL_UNHOLY_FRENZY,
    CRIPPLE_1               = SPELL_CRIPPLE,

    CORPSE_EXPLOSION_1      = SPELL_CORPSE_EXPLOSION,
    //ATTRACT_1               = SPELL_BLOOD_CURSE
};
enum NecromancerSpecial
{
    MH_ATTACK_ANIM          = SPELL_ATTACK_MELEE_1H,

    RAISE_DEAD_COST         = 50 * 5, // 75 * 5, Reduced to match playstyle (1-2,3?) necromancers
    UNHOLY_FRENZY_COST      = 50 * 5,
    CRIPPLE_COST            = 175 * 5,
    CORPSE_EXPLOSION_COST   = 100 * 5,
    //ATTRACT_COST            = 200 * 5,

    //get 80% mana back if casting on a skeleton
    UNHOLY_FRENZY_REFUND    = UNHOLY_FRENZY_COST / 10 * 8,

    MAX_MINIONS             = 12,

    SPELL_SPAWN_ANIM        = 25035,
    SPELL_BLOODY_EXPLOSION  = 36599,

    MODEL_BLOODY_BONES      = 25538,

    CORPSE_EXPLOSION_DAMAGE = 50444, //DK spell

    CE_DAMAGE_PCT_BASE      = 35,
    CE_DAMAGE_PCT_PER_LEVEL = 1,

    CE_MIN_TARGETS          = 3
};

static const uint32 Necromancer_spells_damage_arr[] =
{ /*MAIN_ATTACK_1, */CORPSE_EXPLOSION_1/*, ATTRACT_1*/ };

static const uint32 Necromancer_spells_support_arr[] =
{ RAISE_DEAD_1, UNHOLY_FRENZY_1, CRIPPLE_1/*, ATTRACT_1*/ };

static const std::vector<uint32> Necromancer_spells_damage(FROM_ARRAY(Necromancer_spells_damage_arr));
static const std::vector<uint32> Necromancer_spells_support(FROM_ARRAY(Necromancer_spells_support_arr));

class necromancer_bot : public CreatureScript
{
public:
    necromancer_bot() : CreatureScript("necromancer_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new necromancer_botAI(creature);
    }

    struct necromancer_botAI : public bot_ai
    {
        necromancer_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_NECROMANCER;

            InitUnitFlags();

            //necromancer immunities
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_POSSESS, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SILENCE, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_BLOCK_SPELL_FAMILY, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
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
        void AttackStart(Unit*) override { }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonAll(false); bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void CheckCorpseExplosion(uint32 diff)
        {
            if (!IsSpellReady(CORPSE_EXPLOSION_1, diff) || _corpseExplosionCheckTimer > diff ||
                me->GetLevel() < 40 || me->GetPower(POWER_MANA) < CORPSE_EXPLOSION_COST ||  Rand() > 80)
                return;

            _corpseExplosionCheckTimer = 500;

            SpellInfo const* ceinfo = AssertBotSpellInfoOverride(GetSpell(CORPSE_EXPLOSION_1));
            float ceradius = ceinfo->GetEffect(EFFECT_0).RadiusEntry->Radius;
            ApplyBotSpellRadiusMods(ceinfo, ceradius);

            //1. Corpse near current target
            if ((IAmFree() || !master->GetGroup() || master->GetGroup()->GetMembersCount() <= 3) &&
                me->GetVictim() && me->GetVictim()->GetHealth() <= me->GetMaxHealth() * 3)
            {
                auto corpse_pred = [this, mindist = ceradius](Creature const* c) mutable {
                    if (_isUsableCorpse(c) && c->GetDistance(me->GetVictim()) < mindist)
                    {
                        mindist = c->GetDistance(me->GetVictim());
                        return true;
                    }
                    return false;
                };
                Creature* creature = nullptr;
                Trinity::CreatureLastSearcher searcher(me, creature, corpse_pred);
                Cell::VisitAllObjects(me, searcher, ceinfo->RangeEntry->RangeMax[0]);

                if (creature)
                {
                    if (doCast(creature, GetSpell(CORPSE_EXPLOSION_1)))
                    {
                        me->CastSpell(me, MH_ATTACK_ANIM, true);
                        return;
                    }
                }
            }

            //2. Find a corpse with enough idiots around it (this one in n^2 so open for reviews)
            {
                auto corpse_pred = [this, ceradius = ceradius, maxmob = std::size_t(CE_MIN_TARGETS-1)](Creature const* c) mutable {
                    if (_isUsableCorpse(c))
                    {
                        std::list<Unit*> units;
                        NearbyHostileUnitCheck check(me, ceradius, this, 0, c);
                        Trinity::UnitListSearcher searcher(c, units, check);
                        Cell::VisitAllObjects(c, searcher, ceradius);
                        if (units.size() > maxmob)
                        {
                            maxmob = units.size();
                            return true;
                        }
                        return false;
                    }
                    return false;
                };
                std::list<Creature*> corpses;
                Trinity::CreatureListSearcher searcher(me, corpses, corpse_pred);
                Cell::VisitAllObjects(me, searcher, ceinfo->RangeEntry->RangeMax[0]);

                if (Creature* corpse = corpses.empty() ? nullptr : corpses.size() == 1 ? corpses.front() :
                    Trinity::Containers::SelectRandomContainerElement(corpses))
                {
                    if (doCast(corpse, GetSpell(CORPSE_EXPLOSION_1)))
                    {
                        me->CastSpell(me, MH_ATTACK_ANIM, true);
                        return;
                    }
                }
            }
        }

        void CheckRaiseDead(uint32 diff)
        {
            if (!IsSpellReady(RAISE_DEAD_1, diff) || _raiseDeadCheckTimer > diff || _minions.size() > MAX_MINIONS - 2 ||
                me->GetPower(POWER_MANA) < RAISE_DEAD_COST || Rand() > 50)
                return;

            _raiseDeadCheckTimer = 500;

            auto corpse_pred = [this, mindist = 25.f](Creature const* c) mutable {
                if (_isUsableCorpse(c) && c->GetDistance(me) < mindist)
                {
                    mindist = c->GetDistance(me);
                    return true;
                }
                return false;
            };
            Creature* creature = nullptr;
            Trinity::CreatureLastSearcher searcher(me, creature, corpse_pred);
            Cell::VisitAllObjects(me, searcher, 25.f);

            if (creature)
            {
                if (doCast(creature, GetSpell(RAISE_DEAD_1)))
                    return;
            }
        }

        void CheckUnholyFrenzy(uint32 diff)
        {
            if (!IsSpellReady(UNHOLY_FRENZY_1, diff) || me->GetLevel() < 30 || me->GetPower(POWER_MANA) < UNHOLY_FRENZY_COST || Rand() > 35)
                return;

            static const auto frenzy_pred_player = [](Player const* pl, Unit const* nec) -> bool {
                return (pl->GetVictim() && pl->IsInCombat() && IsMeleeClass(pl->GetClass()) && nec->GetDistance(pl) < 30 &&
                    pl->GetDistance(pl->GetVictim()) < 15 && pl->getAttackers().empty() && !CCed(pl, true) &&
                    !pl->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && pl->GetHealth() >= nec->GetMaxHealth());
            };

            static const auto frenzy_pred_bot = [](Creature const* bot, Unit const* nec) -> bool {
                return (IsMeleeClass(bot->GetBotClass()) && bot->GetVictim() && !bot->GetBotAI()->IsTank(bot) &&
                    bot->GetBotAI()->HasRole(BOT_ROLE_DPS) && !bot->GetBotAI()->HasRole(BOT_ROLE_RANGED) &&
                    nec->GetDistance(bot) < 30 && bot->GetDistance(bot->GetVictim()) < 15 &&
                    bot->getAttackers().empty() && !CCed(bot, true) &&
                    !bot->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && bot->GetHealth() >= nec->GetMaxHealth());
            };

            Unit* target = nullptr;

            //master
            if (!IsTank(master) && frenzy_pred_player(master, me))
                target = master;
            //minions
            else if (HasRole(BOT_ROLE_DPS) && !_minions.empty())
            {
                for (Unit* minion : _minions)
                {
                    if (minion->GetVictim() && GetHealthPCT(minion) > 80 && me->GetDistance(minion) < 30 && !CCed(minion, true) &&
                        !minion->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                    {
                        target = minion;
                        break;
                    }
                }
            }

            if (!target)
            {
                std::set<Unit*> targets;
                if (Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup())
                {
                    std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
                    for (uint8 i = 0; i < 2 && !targets.empty(); ++i)
                    {
                        for (Unit* member : members)
                        {
                            if (!(i == 0 ? member->IsPlayer() : member->IsNPCBot()) || me->GetMap() != member->FindMap() ||
                                member->GetGUID() == master->GetGUID())
                                continue;
                            if (member->IsPlayer() ?
                                (!IsTank(member) && frenzy_pred_player(member->ToPlayer(), me)) :
                                frenzy_pred_bot(member->ToCreature(), me))
                                targets.insert(member);
                        }
                    }
                }
                if (!targets.empty())
                    target = targets.size() == 1u ? *targets.begin() : Trinity::Containers::SelectRandomContainerElement(targets);
            }

            if (target && doCast(target, GetSpell(UNHOLY_FRENZY_1)))
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                    ReportSpellCast(UNHOLY_FRENZY_1, LocalizedNpcText(target->ToPlayer(), BOT_TEXT__ON_YOU), target->ToPlayer());
                return;
            }

            SetSpellCooldown(UNHOLY_FRENZY_1, 1000); //fail
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            //Interrupt corpse-usage spells if no longer usable
            if (Spell const* spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            {
                if ((spell->GetSpellInfo()->GetFirstRankSpell()->Id == RAISE_DEAD_1 ||
                    spell->GetSpellInfo()->GetFirstRankSpell()->Id == CORPSE_EXPLOSION_1))
                {
                    Unit const* target = ObjectAccessor::GetUnit(*me, spell->m_targets.GetObjectTargetGUID());
                    if (target && target->GetDisplayId() != target->GetNativeDisplayId())
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                }
            }

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            if (IsPotionReady())
            {
                if (me->GetPower(POWER_MANA) < CORPSE_EXPLOSION_COST)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            CheckCorpseExplosion(diff);
            CheckRaiseDead(diff);
            CheckUnholyFrenzy(diff);

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

            MoveBehind(mytar);

            if (!HasRole(BOT_ROLE_DPS))
                return;

            if (GC_Timer > diff)
                return;

            if (!CanAffectVictimAny(mytar, SPELL_SCHOOL_SHADOW, SPELL_SCHOOL_ARCANE))
                return;

            //Cripple
            if (IsSpellReady(CRIPPLE_1, diff) && me->GetDistance(mytar) < 30 &&
                me->GetLevel() >= 50 && me->GetPower(POWER_MANA) >= CRIPPLE_COST &&
                mytar->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_MELEE_HASTE) >= 0 &&
                (mytar->GetTypeId() == TYPEID_PLAYER || mytar->GetHealth() > me->GetMaxHealth() * 3))
            {
                if (doCast(mytar, GetSpell(CRIPPLE_1)))
                    return;
            }

            if (IsSpellReady(MAIN_ATTACK_1, diff) && me->GetDistance(mytar) < 30)
            {
                if (doCast(mytar, GetSpell(MAIN_ATTACK_1)))
                    return;
            }
        }

        //void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        //{
        //    uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
        //    //uint8 lvl = me->GetLevel();
        //    float fdamage = float(damage);

        //    //apply bonus damage mods
        //    float pctbonus = 1.0f;
        //    if (iscrit)
        //        pctbonus *= 1.333f;

        //    if (baseId == MAIN_ATTACK_1)
        //        fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * (spellInfo->_effects[0].BonusMultiplier - 1.f) * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);

        //    damage = int32(fdamage * pctbonus);
        //}

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //flat mods
            //Corpse Explosion radii per level
            if (lvl > 40 && (baseId == CORPSE_EXPLOSION_1 || baseId == CORPSE_EXPLOSION_DAMAGE))
                radius += 0.25f * (lvl - 40);

            radius = radius * pctbonus;
        }

        void ApplyClassEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //uint8 lvl = me->GetLevel();
            float pctbonus = 1.0f;

            //Set damage for Unholy Frenzy: 45 sec, 15 ticks, total damage is 125% if Necromancer's max health
            if (baseId == UNHOLY_FRENZY_1 && effIndex == EFFECT_1)
                value += (me->GetMaxHealth() * 1.25f) / std::max<uint32>(1, spellInfo->GetMaxTicks());

            value = value * pctbonus;
        }

        void ApplyClassThreatMods(SpellInfo const* spellInfo, float& threat) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            float pctbonus = 1.0f;

            if (baseId == CORPSE_EXPLOSION_DAMAGE)
                threat = 0.f;

            threat = threat * pctbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == MAIN_ATTACK_1 || baseId == RAISE_DEAD_1 || baseId == UNHOLY_FRENZY_1 ||
                baseId == CRIPPLE_1 || baseId == CORPSE_EXPLOSION_1/* || baseId == ATTRACT_1*/)
                GC_Timer = uint32(me->GetAttackTime(BASE_ATTACK) * me->m_modAttackSpeedPct[BASE_ATTACK]);

            if (baseId == MAIN_ATTACK_1 || baseId == RAISE_DEAD_1 || baseId == UNHOLY_FRENZY_1 ||
                baseId == CRIPPLE_1/* || baseId == CORPSE_EXPLOSION_1*//* || baseId == ATTRACT_1*/)
                me->CastSpell(me, MH_ATTACK_ANIM, true);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;

            if (baseId != MAIN_ATTACK_1)
            {
                if (baseId == CORPSE_EXPLOSION_1)
                {
                    ASSERT(!IsInBotParty(target));
                    target->CastSpell(target, CORPSE_EXPLOSION_VISUAL, true);
                    target->CastSpell(target, SPELL_BLOODY_EXPLOSION, true);
                    target->SetDisplayId(MODEL_BLOODY_BONES);

                    //Corpse Explosion damage: progress with level 35 to 75% (base level 40)
                    int32 fdamage = CalculatePct(target->GetMaxHealth(),
                        CE_DAMAGE_PCT_BASE + CE_DAMAGE_PCT_PER_LEVEL * (uint32(me->GetLevel()) - spell->BaseLevel));

                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellBP0(fdamage);
                    me->CastSpell(target, CORPSE_EXPLOSION_DAMAGE, args);
                }

                if (baseId == RAISE_DEAD_1)
                {
                    ASSERT(!IsInBotParty(target));
                    //Two skeletons
                    for (uint8 i = 0; i < 2; ++i)
                        SummonBotPet(target);
                    //visuals
                    if (!target->IsPet() && !target->IsVehicle() && !target->ToCreature()->isWorldBoss() && !target->ToCreature()->IsDungeonBoss())
                    {
                        target->CastSpell(target, SPELL_BLOODY_EXPLOSION, true);
                        target->SetDisplayId(MODEL_BLOODY_BONES);
                    }
                }

                if (baseId == UNHOLY_FRENZY_1)
                {
                    if (target->GetEntry() == BOT_PET_NECROSKELETON && _minions.find(target->ToCreature()) != _minions.end())
                    {
                        //get 80% mana back if casting on a skeleton
                        me->EnergizeBySpell(me, UNHOLY_FRENZY_1, UNHOLY_FRENZY_REFUND, POWER_MANA);
                    }
                }

                if (baseId == CRIPPLE_1)
                {
                    if (target->GetTypeId() == TYPEID_PLAYER || target->GetLevel() > 80)
                    {
                        if (Aura* crip = target->GetAura(spell->Id, me->GetGUID()))
                        {
                            int32 dur = std::min<int32>(crip->GetMaxDuration(), 10000);
                            crip->SetDuration(dur);
                            crip->SetMaxDuration(dur);
                        }
                    }
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
                //try 2: by minimal duration (if expiring already)
                if (!u)
                {
                    uint32 minduration = static_cast<uint32>((*_minions.begin())->GetAI()->GetData(BOTPETAI_MISC_DURATION_MAX) * 3 / 4);
                    for (Summons::const_iterator itr = _minions.begin(); itr != _minions.end(); ++itr)
                    {
                        if ((*itr)->GetAI()->GetData(BOTPETAI_MISC_DURATION) > minduration)
                        {
                            minduration = (*itr)->GetAI()->GetData(BOTPETAI_MISC_DURATION);
                            u = *itr;
                        }
                    }
                }

                if (!u)
                    return;

                u->ToTempSummon()->UnSummon();
            }

            Position pos = from->GetPosition();

            Creature* myPet = me->SummonCreature(BOT_PET_NECROSKELETON, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1s);
            myPet->SetCreator(master);
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, RAISE_DEAD_1);

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

            myPet->CastSpell(myPet, SPELL_SPAWN_ANIM, true);
            if (Aura* stun = myPet->AddAura(SUMMONING_DISORIENTATION, myPet))
            {
                stun->SetDuration(1500);
                stun->SetMaxDuration(1500);
            }

            myPet->GetAI()->SetData(BOTPETAI_MISC_MAXLEVEL, me->GetLevel());
            _minions.insert(myPet);
        }

        void UnsummonAll(bool savePets = true) override
        {
            UnsummonCreatures(_minions, savePets);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (_minions.find(summon) != _minions.end())
                _minions.erase(summon);
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_NECROSKELETON;
                default:
                    return 0;
            }
        }

        void CheckAttackState() override
        {
        }

        void OnBotEnterVehicle(Vehicle const* vehicle) override
        {
            me->Dismount();
            bot_ai::OnBotEnterVehicle(vehicle);
        }

        void Reset() override
        {
            _corpseExplosionCheckTimer = 0;
            _raiseDeadCheckTimer = 0;

            UnsummonAll(false);

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (_corpseExplosionCheckTimer > diff)          _corpseExplosionCheckTimer -= diff;
            if (_raiseDeadCheckTimer > diff)                _raiseDeadCheckTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            InitSpellMap(MAIN_ATTACK_1, true, false);
            InitSpellMap(RAISE_DEAD_1, true, false);
            InitSpellMap(UNHOLY_FRENZY_1, true, false);
            InitSpellMap(CRIPPLE_1, true, false);
            InitSpellMap(CORPSE_EXPLOSION_1, true, false);
            //InitSpellMap(ATTRACT_1, true, false);
        }

        void ApplyClassPassives() const override
        {
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case UNHOLY_FRENZY_1:
                    return me->GetLevel() >= 30;
                default:
                    return false;
            }
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Necromancer_spells_damage;
        }
        //std::vector<uint32> const* GetCCSpellsList() const override
        //{
        //    return &Necromancer_spells_cc;
        //}
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Necromancer_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Necromancer_spells_support;
        }

    private:
        bool _isUsableCorpse(Creature const* c) const
        {
            static const uint32 ViableCreatureTypesMask =
                (1 << (CREATURE_TYPE_BEAST-1)) | (1 << (CREATURE_TYPE_DRAGONKIN-1)) | (1 << (CREATURE_TYPE_HUMANOID-1));

            return c->getDeathState() == DeathState::CORPSE && c->GetDisplayId() == c->GetNativeDisplayId() &&
                !c->IsVehicle() && !c->isWorldBoss() && !c->IsDungeonBoss() &&
                ((1 << (c->GetCreatureType()-1)) & ViableCreatureTypesMask) &&
                !c->IsControlledByPlayer() && !c->IsNPCBot() && c->GetMaxHealth() >= me->GetMaxHealth() / 4;
        }

        uint32 _corpseExplosionCheckTimer;
        uint32 _raiseDeadCheckTimer;

        typedef std::set<Creature*> Summons;
        Summons _minions;
    };
};

void AddSC_necromancer_bot()
{
    new necromancer_bot();
}
