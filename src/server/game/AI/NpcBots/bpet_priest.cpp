#include "bot_ai.h"
#include "bpet_ai.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
/*
Priest NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 100%
TODO:
*/

enum PriestPetBaseSpells
{
    SHADOWCRAWL_1                       = 63619
};

enum PriestPetPassives
{
    MANA_LEECH                          = 28305,
    AVOIDANCE                           = 63623
};

enum PriestPetSpecial
{
    GLYPH_SHADOWFIEND_PROC              = 58227,

    SHADOWFIEND_DURATION                = 15000
};

class priest_pet_bot : public CreatureScript
{
public:
    priest_pet_bot() : CreatureScript("priest_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new priest_botpetAI(creature);
    }

    struct priest_botpetAI : public bot_pet_ai
    {
        priest_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

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

        void DoPetActions(uint32 /*diff*/)
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if ((liveTimer += diff) >= SHADOWFIEND_DURATION)
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
            //CheckDrainMana(diff);

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            DoPetAttack(diff);
        }

        void DoPetAttack(uint32 diff)
        {
            StartAttack(opponent, IsPetMelee());

            float dist = me->GetDistance(opponent);
            bool canDPS = petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS);

            if (IsSpellReady(SHADOWCRAWL_1, diff) && canDPS && dist < 30)
            {
                me->CastSpell(opponent, GetSpell(SHADOWCRAWL_1), false);
                SetSpellCooldown(SHADOWCRAWL_1, 6000);
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
            //Handled by spell scripts
            //if (damage && victim && damageType == DIRECT_DAMAGE)
            //    victim->CastSpell(petOwner, MANA_LEECH_PROC, true);

            bot_pet_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
        {
            if (damage >= me->GetHealth())
                petOwner->CastSpell(petOwner, GLYPH_SHADOWFIEND_PROC, true);

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
            InitSpellMap(SHADOWCRAWL_1);
        }

        void ApplyPetPassives() const override
        {
            RefreshAura(MANA_LEECH);
            RefreshAura(AVOIDANCE);
        }

    private:
        uint32 liveTimer;
    };
};

void AddSC_priest_bot_pets()
{
    new priest_pet_bot();
}
