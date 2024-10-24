#include "bot_ai.h"
#include "bpet_ai.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
/*
Shaman NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 100%
TODO:
*/

enum ShamanPetBaseSpells
{
    BASH_1                              = 58861, //r5 cd45
    LEAP_1                              = 58867, //r5-30 cd20
    TWIN_HOWL_1                         = 58857, //r10 cd15
    SPIRIT_WALK_1                       = 58875  //r25 cd32
};

enum ShamanPetPassives
{
    SPIRIT_HUNT                         = 58877
};

enum ShamanPetSpecial
{
    SPIRITWOLF_DURATION                 = 45000
};

class shaman_pet_bot : public CreatureScript
{
public:
    shaman_pet_bot() : CreatureScript("shaman_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shaman_botpetAI(creature);
    }

    struct shaman_botpetAI : public bot_pet_ai
    {
        shaman_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

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

        void DoPetActions(uint32 diff)
        {
            if (IsSpellReady(SPIRIT_WALK_1, diff) && (me->GetVictim() || petOwner->GetVictim()) &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                me->GetDistance(petOwner) < 25)
            {
                me->CastSpell(me, GetSpell(SPIRIT_WALK_1), false);
                return;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if ((liveTimer += diff) >= SPIRITWOLF_DURATION)
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

            float dist = me->GetDistance(opponent);
            Unit const* u = opponent->GetVictim();
            //bool canDPS = petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS);

            if (IsSpellReady(LEAP_1, diff) &&
                !HasBotCommandState(BOT_COMMAND_STAY) &&
                !(opponent->GetTypeId() == TYPEID_UNIT && opponent->ToCreature()->isWorldBoss()) &&
                dist > 5 && dist < 30)
            {
                me->CastSpell(opponent, GetSpell(LEAP_1), false);
                return;
            }

            if (IsSpellReady(BASH_1, diff) && !CCed(opponent) &&
                me->IsWithinMeleeRange(opponent))
            {
                me->CastSpell(opponent, GetSpell(BASH_1), false);
                return;
            }

            if (IsSpellReady(TWIN_HOWL_1, diff, false) && u && u != me && me->IsWithinMeleeRange(opponent) &&
                !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 50)) && IsInBotParty(u))
            {
                me->CastSpell(opponent, GetSpell(TWIN_HOWL_1), false);
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

        void Reset() override
        {
            liveTimer = 0;
        }

        void InitPetSpells() override
        {
            InitSpellMap(BASH_1);
            InitSpellMap(LEAP_1);
            InitSpellMap(TWIN_HOWL_1);
            InitSpellMap(SPIRIT_WALK_1);
        }

        void ApplyPetPassives() const override
        {
            RefreshAura(SPIRIT_HUNT);
        }

    private:
        uint32 liveTimer;
    };
};

void AddSC_shaman_bot_pets()
{
    new shaman_pet_bot();
}
