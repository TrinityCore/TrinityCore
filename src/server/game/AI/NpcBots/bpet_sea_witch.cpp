#include "bot_ai.h"
#include "botspell.h"
#include "bpet_ai.h"
#include "Containers.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
/*
Sea Witch NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 100%
TODO:
*/

enum SeaWitchPetBaseSpells
{
    ENVELOP_1                   = SPELL_TORNADO_EFFECT,
    LIGHTNING_1                 = SPELL_TORNADO_EFFECT2,
};

enum SeaWitchPetSpecial
{
    TORNADO_DURATION            = 40000,
    TORNADO_MOVE_RESET_TIMER    = 1500,
    TORNADO_GROWTH_TIMER        = 2500,
    TORNADO_DISSIPATE_TIMER     = 5000,

    PERIODIC_LIGHTNING_VISUAL   = 45869,
    CAMERA_SHAKE_VISUAL         = 12816,
    TARGET_LIGHTNING_VISUAL     = 39381,
    TARGET_LIGHTNING_VISUAL2    = 45935,
    SPELL_GROWTH                = 55948,//+10% size, +10% damage
    SPELL_SLOW_AURA             = SPELL_TORNADO_EFFECT3
};

class sea_witch_pet_bot : public CreatureScript
{
public:
    sea_witch_pet_bot() : CreatureScript("sea_witch_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new tornado_botpetAI(creature);
    }

    struct tornado_botpetAI : public bot_pet_ai
    {
        tornado_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

        void JustEnteredCombat(Unit* u) override { bot_pet_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_pet_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_pet_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_pet_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { bot_pet_ai::JustDied(u); }

        void DoPetActions(uint32 diff)
        {
            //Envelop random target: every 3 sec
            if (IsSpellReady(ENVELOP_1, diff, false))
            {
                std::list<Unit*> targets;
                petOwner->GetBotAI()->HelpGetNearbyTargetsList(targets, 10.f, 1, me);
                if (targets.size() > 2)
                    Trinity::Containers::RandomResize(targets, 2);
                for (Unit* u : targets)
                    me->CastSpell(u, GetSpell(ENVELOP_1), true);
                SetSpellCooldown(ENVELOP_1, 3000);
            }

            if (IsSpellReady(LIGHTNING_1, diff, false))
            {
                std::list<Unit*> targets;
                petOwner->GetBotAI()->HelpGetNearbyTargetsList(targets, 15.f, 0, me);
                if (!targets.empty())
                    me->CastSpell(me, CAMERA_SHAKE_VISUAL, true);
                for (Unit* u : targets)
                {
                    me->CastSpell(u, GetSpell(LIGHTNING_1), true);
                    u->CastSpell(u, TARGET_LIGHTNING_VISUAL, true);
                    u->CastSpell(u, TARGET_LIGHTNING_VISUAL2, true);
                }
                SetSpellCooldown(LIGHTNING_1, 4500);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (((liveTimer += diff) >= TORNADO_DURATION) || !petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS))
            {
                canUpdate = false;
                me->ToTempSummon()->UnSummon(1);
                return;
            }
            else if ((IsIndoors() && !me->IsOutdoors()) && (isIndoorsTimer += diff) >= TORNADO_DISSIPATE_TIMER)
            {
                canUpdate = false;
                me->SetObjectScale(me->GetNativeObjectScale() / 2.f);
                me->ToTempSummon()->UnSummon(2000);
                return;
            }

            if ((growthTimer += diff) > TORNADO_GROWTH_TIMER)
            {
                growthTimer %= TORNADO_GROWTH_TIMER;
                me->CastSpell(me, SPELL_GROWTH, true);
                //me->SetObjectScale(me->GetObjectScale() * 1.1f);
            }

            if (!GlobalUpdate(diff))
                return;

            DoPetActions(diff);

            if (IsCasting())
                return;

            if (!CheckAttackTarget())
                return;

            DoPetAttack(diff);
        }

        void DoPetAttack(uint32 diff)
        {
            if ((moveResetTimer += diff) > TORNADO_MOVE_RESET_TIMER || opponent->GetGUID() != me->GetTarget())
            {
                moveResetTimer %= TORNADO_MOVE_RESET_TIMER;
                SetBotCommandState(BOT_COMMAND_ATTACK);
                me->SetTarget(opponent->GetGUID());
                Position pos = opponent->GetNearPosition(frand(3.f, 5.f + opponent->GetCombatReach()), opponent->GetAbsoluteAngle(petOwner) + frand(float(-M_PI) / 2.f, float(M_PI) / 2.f));
                me->GetMotionMaster()->MovePoint(me->GetMapId(), pos.GetPositionX(), pos.GetPositionY(), opponent->GetPositionZ(), false);
                //me->GetMotionMaster()->MoveChase(opponent, frand(3.f, 10.f), opponent->GetAbsoluteAngle(petOwner) + frand(-M_PI / 2, M_PI / 2));
            }
        }

        void ApplyBotPetSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            ////pct mods
            ////Increased Area (AhnQ set bonus?) 23549
            //if (lvl >= 60 && (spellInfo->SpellFamilyFlags[0] & 0x1084))
            //    pctbonus += 0.25f;

            //flat mods
            //Slow Aura growth
            if (baseId == SPELL_SLOW_AURA)
                flatbonus += me->GetCombatReach();

            radius = radius * (1.0f + pctbonus) + flatbonus;
        }

        void OnPetClassSpellGo(SpellInfo const* /*spellInfo*/) override {}

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
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

            if (baseId == ENVELOP_1)
            {
                if (target->IsControlledByPlayer())
                {
                    if (Aura* enve = target->GetAura(GetSpell(baseId), me->GetGUID()))
                    {
                        int32 dur = std::max<int32>(enve->GetDuration() - 6000, 0);
                        enve->SetDuration(dur);
                        enve->SetMaxDuration(dur);
                    }
                }
            }
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

        void CheckAttackState() override
        {
        }

        void Reset() override
        {
            liveTimer = 0;
            moveResetTimer = 0;
            growthTimer = 0;
            isIndoorsTimer = 0;
        }

        void InitPetSpells() override
        {
            InitSpellMap(ENVELOP_1, true, false);
            InitSpellMap(LIGHTNING_1, true, false);
        }

        void ApplyPetPassives() const override
        {
            RefreshAura(PERIODIC_LIGHTNING_VISUAL);
            RefreshAura(SPELL_SLOW_AURA);
        }

    private:
        uint32 liveTimer;
        uint32 moveResetTimer;
        uint32 growthTimer;
        uint32 isIndoorsTimer;
    };
};

void AddSC_sea_witch_bot_pets()
{
    new sea_witch_pet_bot();
}
