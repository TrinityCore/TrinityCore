#include "bot_ai.h"
#include "botspell.h"
#include "bpet_ai.h"
#include "CellImpl.h"
#include "Containers.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
/*
Crypt Lord NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Notes:
Complete - 75%
TODO: Check if Burrow can be added
*/

enum CryptLordPetBaseSpells
{
};
enum CryptLordPetPassives
{
};
enum CryptLordPetSpecial
{
    LOCUST_SWARM_EFFECTIVE_RADIUS       = 60,
    LOCUST_SWARM_SPELL_DURATION         = 30000,
};

class crypt_lord_pet_bot : public CreatureScript
{
public:
    crypt_lord_pet_bot() : CreatureScript("crypt_lord_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        switch (creature->GetEntry())
        {
            case BOT_PET_LOCUST_SWARM:
                return new locust_swarm_botpetAI(creature);
            default:
                return new carrion_beetle_botpetAI(creature);
        }
    }

    struct carrion_beetle_botpetAI : public bot_pet_ai
    {
        carrion_beetle_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

        void JustEnteredCombat(Unit* u) override { bot_pet_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_pet_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_pet_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_pet_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_pet_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_pet_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            DoPetAttack(diff);
        }

        void DoPetAttack(uint32 /*diff*/)
        {
            StartAttack(opponent, IsPetMelee());
        }

        void OnPetClassSpellGo(SpellInfo const* /*spellInfo*/) override
        {
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(WorldObject* /*wtarget*/, SpellInfo const* /*spell*/) override
        {
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            bot_pet_ai::DamageDealt(victim, damage, damageType);
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

        uint32 GetData(uint32 data) const override
        {
            switch (data)
            {
                case BOTPETAI_MISC_MAXLEVEL:
                    return maxlevel;
                default:
                    return bot_pet_ai::GetData(data);
            }
        }

        void SetData(uint32 data, uint32 value) override
        {
            switch (data)
            {
                case BOTPETAI_MISC_MAXLEVEL:
                    maxlevel = uint8(value);
                    SetPetStats(true);
                    break;
                default:
                    break;
            }
        }

        void Reset() override
        {
            maxlevel = 1;
        }

        void InitPetSpells() override
        {
        }

        void ApplyPetPassives() const override
        {
        }

    private:
        uint8 maxlevel;
    };

    struct locust_swarm_botpetAI : public bot_pet_ai
    {
        locust_swarm_botpetAI(Creature* creature) : bot_pet_ai(creature)
        {
            (const_cast<CreatureMovementData&>(me->GetMovementTemplate())).Ground = CreatureGroundMovementType::Hover;
        }

        void JustEnteredCombat(Unit* u) override { bot_pet_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_pet_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_pet_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_pet_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_pet_ai::JustDied(u); }

        void UpdateAI(uint32 diff) override
        {
            _activeTimer += diff;

            if (!GlobalUpdate(diff))
                return;

            DoLocustActions(diff);
        }

        void DoLocustActions(uint32 diff)
        {
            bool is_full = _gathered >= _capacity;
            bool expired = _activeTimer >= LOCUST_SWARM_SPELL_DURATION;

            if (Unit* u = me->GetVictim())
            {
                if (petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS) && me->IsWithinMeleeRange(u) && me->isAttackReady())
                {
                    me->resetAttackTimer();
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SOUL_BITE);
                    spellInfo = spellInfo->TryGetSpellInfoOverride(me);
                    int32 bp = spellInfo->GetEffect(EFFECT_0).CalcValue(petOwner);
                    CastSpellExtraArgs args(true);
                    args.AddSpellBP0(bp);
                    me->CastSpell(u, SPELL_SOUL_BITE, args);
                }
                if (!is_full && !expired && u->IsWithinDist(petOwner, LOCUST_SWARM_EFFECTIVE_RADIUS))
                {
                    if (_chaseCheckTimer <= diff)
                    {
                        _chaseCheckTimer = urand(350, 1350);
                        float dist = CONTACT_DISTANCE + me->GetCombatReach() * frand(1.0f, 3.0f);
                        float angle = frand(0.001f, float(M_PI * 2));
                        Position nearpos = u->GetNearPosition(dist, angle);
                        me->GetMotionMaster()->MovePoint(1, nearpos, false);
                    }
                    return;
                }
                else
                {
                    me->AttackStop();
                    me->BotStopMovement();
                }
            }
            else
            {
                _chaseCheckTimer = 0;

                if (me->GetExactDist(petOwner) < (1.5f + 5u * uint32(expired)))
                {
                    if (_gathered > 0 && (is_full || expired))
                    {
                        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_LOCUST_SWARM);
                        spellInfo = spellInfo->TryGetSpellInfoOverride(petOwner);
                        HealInfo hinfo(petOwner, petOwner, _gathered, spellInfo, spellInfo->GetSchoolMask());
                        petOwner->CastSpell(petOwner, SPELL_ENERGIZE_VISUAL, true);
                        petOwner->HealBySpell(hinfo);
                        _gathered = 0;
                    }
                    if (expired)
                    {
                        canUpdate = false;
                        me->ToTempSummon()->UnSummon(1);
                        return;
                    }
                }
            }

            if (_targetRecheckTimer <= diff)
            {
                _targetRecheckTimer = urand(1000, 1500);

                std::list<Unit*> targets;
                if (petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS) && !is_full && !expired)
                {
                    Trinity::AnyUnfriendlyUnitInObjectRangeCheck check(petOwner, petOwner, LOCUST_SWARM_EFFECTIVE_RADIUS);
                    Trinity::UnitListSearcher searcher(petOwner, targets, check);
                    Cell::VisitAllObjects(petOwner, searcher, LOCUST_SWARM_EFFECTIVE_RADIUS);

                    targets.remove_if([poguid = petOwner->GetGUID(), combat = petOwner->IsInCombat(), max_attackers = _attackers](Unit const* unit) {
                        Unit::AttackerSet const& attackers = unit->getAttackers();
                        if (!(unit->IsInCombat() || (combat && !attackers.empty())))
                            return true;
                        return max_attackers <= std::count_if(std::cbegin(attackers), std::cend(attackers), [oguid = poguid](Unit const* attacker) {
                            return attacker->GetEntry() == BOT_PET_LOCUST_SWARM && attacker->GetOwnerGUID() == oguid;
                        });
                    });
                }

                if (!targets.empty())
                {
                    opponent = targets.size() == 1 ? targets.front() : Trinity::Containers::SelectRandomContainerElement(targets);
                    me->Attack(opponent, false);
                    me->GetMotionMaster()->MoveChase(opponent);
                }
                else
                {
                    if (expired)
                    {
                        _targetRecheckTimer = 150;
                        for (auto rate : { MOVE_WALK, MOVE_RUN })
                            me->SetSpeedRate(rate, std::min<float>(1000.0f, me->GetSpeedRate(rate) * 1.35f));
                    }

                    float dist = (expired || is_full) ? 0.0f : frand(3.0f, 20.0f);
                    float angle = frand(0.001f, float(M_PI * 2));
                    Position nearpos = petOwner->GetNearPosition(dist, angle);
                    me->GetMotionMaster()->MovePoint(1, nearpos, false);
                }
            }
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
            _gathered = std::min<uint32>(_gathered + CalculatePct(damage, 75.0f), _capacity);

            bot_pet_ai::DamageDealt(victim, damage, damageType);
        }

        uint32 GetData(uint32 data) const override
        {
            switch (data)
            {
                case BOTPETAI_MISC_FIXEDLEVEL:
                    return me->GetCreatureTemplate()->maxlevel;
                case BOTPETAI_MISC_CARRY:
                    return _gathered;
                default:
                    return bot_pet_ai::GetData(data);
            }
        }

        void SetData(uint32 data, uint32 value) override
        {
            switch (data)
            {
                case BOTPETAI_MISC_CAPACITY:
                    _capacity = value;
                    break;
                case BOTPETAI_MISC_MAX_ATTACKERS:
                    _attackers = value;
                    break;
                default:
                    break;
            }
        }

        void CheckAttackState() override
        {
        }

        void Reset() override
        {
            _gathered = 0;
            _capacity = 100;
            _attackers = 7;

            _targetRecheckTimer = 0;
            _chaseCheckTimer = 0;

            _activeTimer = 0;
        }

        void ReduceCD(uint32 diff) override
        {
            if (_targetRecheckTimer > diff)                 _targetRecheckTimer -= diff;
            if (_chaseCheckTimer > diff)                    _chaseCheckTimer -= diff;
        }

        void InitPetSpells() override
        {
        }

        void ApplyPetPassives() const override
        {
            RefreshAura(SPELL_VERTEX_COLOR_BLACK);
            RefreshAura(SPELL_BLACK_HOLE_VISUAL_2);
        }

    private:
        uint32 _gathered;
        uint32 _capacity;
        uint32 _attackers;

        uint32 _targetRecheckTimer;
        uint32 _chaseCheckTimer;

        uint32 _activeTimer;
    };
};

void AddSC_crypt_lord_bot_pets()
{
    new crypt_lord_pet_bot();
}
