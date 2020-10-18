#include "bot_ai.h"
#include "bpet_ai.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
/*
Mage NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 100%
TODO:
*/

enum MagePetBaseSpells
{
    WATERBOLT_1             = 31707,
    FREEZE_1                = 33395
};

enum MagePetSpecial
{
    ELEMENTAL_DURATION      = 45000
};

class mage_pet_bot : public CreatureScript
{
public:
    mage_pet_bot() : CreatureScript("mage_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new water_elemental_botpetAI(creature);
    }

    struct water_elemental_botpetAI : public bot_pet_ai
    {
        water_elemental_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

        void JustEnteredCombat(Unit* u) override { bot_pet_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_pet_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_pet_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_pet_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { canUpdate = false; me->ToTempSummon()->UnSummon(3000); bot_pet_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_pet_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void DoPetActions(uint32 diff)
        {
            if (!petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS))
                return;

            if (!IsSpellReady(FREEZE_1, diff, false) || Rand() > 40 || !IsCasting(petOwner))
                return;

            Spell const* spell = petOwner->GetCurrentSpell(CURRENT_GENERIC_SPELL);
            if (!spell || !spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) ||
                !(spell->GetTimer() < spell->GetCastTime() / 2))
                return;

            Unit* target = ObjectAccessor::GetUnit(*me, spell->m_targets.GetObjectTargetGUID());
            if (!target || target->IsFrozen() || target->GetDistance(me) - target->GetCombatReach() > 25.f ||
                !me->IsValidAttackTarget(target))
                return;

            me->InterruptNonMeleeSpells(false);
            me->CastSpell(target, GetSpell(FREEZE_1), false);
            return;
        }

        void UpdateAI(uint32 diff) override
        {
            if ((liveTimer += diff) >= ELEMENTAL_DURATION)
            {
                canUpdate = false;
                me->ToTempSummon()->UnSummon(1);
                return;
            }

            if (!GlobalUpdate(diff))
                return;

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            DoPetActions(diff);

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            DoPetAttack(diff);
        }

        void DoPetAttack(uint32 diff)
        {
            StartAttack(opponent, IsPetMelee());

            if (!petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS))
                return;

            if (IsSpellReady(WATERBOLT_1, diff) && me->GetDistance(opponent) < 45)
            {
                me->CastSpell(opponent, GetSpell(WATERBOLT_1), false);
                return;
            }
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
            liveTimer = 0;
        }

        void InitPetSpells() override
        {
            InitSpellMap(WATERBOLT_1);
            InitSpellMap(FREEZE_1);
        }

        void ApplyPetPassives() const override
        {
        }

    private:
        uint32 liveTimer;
    };
};

void AddSC_mage_bot_pets()
{
    new mage_pet_bot();
}
