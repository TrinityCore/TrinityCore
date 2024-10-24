#include "bot_ai.h"
#include "bpet_ai.h"
#include "ScriptMgr.h"
/*
Deathknight NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 25%
TODO: Garg, AOD, DRW
*/
enum DeathknightPetBaseSpells
{
    CLAW_1                              = 47468, //150% damage, 40 cost
    GNAW_1                              = 47481, //12% damage, stun 3 sec, 30 cost
    LEAP_1                              = 47482, //jump beh tar, 10 cost
    HUDDLE_1                            = 47484  //mini-shwall, channeled, 10 sec, 10 cost
};

enum DeathknightPetPassives
{
    AVOIDANCE                           = 62137
};

enum DeathknightPetSpecial
{
    GHOUL_FRENZY_1                      = 63560 //player-on-pet spell
};

class deathknight_pet_bot : public CreatureScript
{
public:
    deathknight_pet_bot() : CreatureScript("deathknight_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new deathknight_botpetAI(creature);
    }

    struct deathknight_botpetAI : public bot_pet_ai
    {
        deathknight_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

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
            //Unit const* u = opponent->GetVictim();
            bool canDPS = petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS);

            if (myType == BOT_PET_GHOUL)
            {
                if (IsSpellReady(GHOUL_FRENZY_1, diff) && canDPS && me->IsWithinMeleeRange(opponent))
                {
                    RefreshAura(GHOUL_FRENZY_1);
                    SetSpellCooldown(GHOUL_FRENZY_1, 30000);
                }

                uint32 const energy = me->GetPower(POWER_ENERGY);

                if (IsSpellReady(HUDDLE_1, diff) && energy >= 10 && dist < 7 &&
                    !me->getAttackers().empty() && GetHealthPCT(me) < 70)
                {
                    me->CastSpell(me, GetSpell(HUDDLE_1), false);
                    return;
                }

                if (IsSpellReady(LEAP_1, diff) && energy >= 10 &&
                    !HasBotCommandState(BOT_COMMAND_STAY) &&
                    !(opponent->GetTypeId() == TYPEID_UNIT && opponent->ToCreature()->isWorldBoss()) &&
                    dist > 5 && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(LEAP_1), false);
                    return;
                }

                if (IsSpellReady(GNAW_1, diff) && canDPS && energy >= 30 &&
                    me->IsWithinMeleeRange(opponent) && opponent->IsNonMeleeSpellCast(false, false, true))
                {
                    me->CastSpell(opponent, GetSpell(GNAW_1), false);
                    return;
                }

                if (IsSpellReady(CLAW_1, diff) && canDPS && energy >= 40 && me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(CLAW_1), false);
                    return;
                }
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
        }

        void InitPetSpells() override
        {
            InitSpellMap(CLAW_1);
            InitSpellMap(GNAW_1);
            InitSpellMap(LEAP_1);
            InitSpellMap(HUDDLE_1);
        }

        void ApplyPetPassives() const override
        {
            if (myType == BOT_PET_GHOUL/* || myType == BOT_PET_AOD_GHOUL*/)
                RefreshAura(AVOIDANCE);
        }

    private:
    };
};

void AddSC_deathknight_bot_pets()
{
    new deathknight_pet_bot();
}
