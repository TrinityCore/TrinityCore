#include "bot_ai.h"
#include "bpet_ai.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
/*
Dark Ranger NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Notes:
Extra abilities. For the sake of defending the owner added Taunt. For self defense added Blocking (block value unchanged)
Both abilities are one-time use
Complete - 100%
TODO:
*/

enum DarkRangerPetBaseSpells
{
    BLOCKING_1                          = 3248,
    TAUNT_1                             = 37548
};
enum DarkRangerPetPassives
{
};
enum DarkRangerPetSpecial
{
    SPELL_GENERATE_THREAT               = 23604, //reduce threat
    THREAT_BASE                         = 5,
    MINION_DURATION                     = 80000
};

class dark_ranger_pet_bot : public CreatureScript
{
public:
    dark_ranger_pet_bot() : CreatureScript("dark_ranger_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new dark_ranger_botpetAI(creature);
    }

    struct dark_ranger_botpetAI : public bot_pet_ai
    {
        dark_ranger_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

        void JustEnteredCombat(Unit* u) override { bot_pet_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_pet_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_pet_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_pet_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { canUpdate = false; me->ToTempSummon()->UnSummon(1000); bot_pet_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_pet_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void DoPetActions(uint32 /*diff*/)
        {
            //if (threatGenTimer < diff)
            //{
            //    threatGenTimer = 1500;
            //    int32 threat = THREAT_BASE;
            //    CastSpellExtraArgs args(true);
            //    args.AddSpellBP0(threat);
            //    me->CastSpell(me, SPELL_GENERATE_THREAT, args);
            //}
        }

        void UpdateAI(uint32 diff) override
        {
            if ((liveTimer += diff) >= MINION_DURATION)
            {
                canUpdate = false;
                me->setDeathState(JUST_DIED);
                me->ToTempSummon()->UnSummon(1000);
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

            if (IsSpellReady(TAUNT_1, diff, false) && Rand() < 50 &&
                ((opponent->GetVictim() == petOwner && !IsTank(petOwner)) ||
                (opponent->GetVictim() == petOwner->GetBotOwner() && !IsTank(petOwner->GetBotOwner()))) &&
                !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) && me->IsWithinMeleeRange(opponent))
            {
                me->CastSpell(opponent, GetSpell(TAUNT_1), false);
                SetSpellCooldown(TAUNT_1, std::numeric_limits<uint32>::max());
                return;
            }

            if (IsSpellReady(BLOCKING_1, diff) && !me->getAttackers().empty() && Rand() < 40)
            {
                me->CastSpell(me, GetSpell(BLOCKING_1), true);
                SetSpellCooldown(BLOCKING_1, 20000);
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

        uint32 GetData(uint32 data) const override
        {
            switch (data)
            {
                case BOTPETAI_MISC_DURATION:
                    return liveTimer;
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
            liveTimer = 0;
            maxlevel = 1;
        }

        void InitPetSpells() override
        {
            InitSpellMap(TAUNT_1, true, false);
            InitSpellMap(BLOCKING_1, true, false);
        }

        void ApplyPetPassives() const override
        {

            if (me->GetEntry() == BOT_PET_DARK_MINION_ELITE)
                RefreshAura(SPELL_VERTEX_COLOR_BLACK);
            else if (me->GetEntry() == BOT_PET_DARK_MINION)
                RefreshAura(SPELL_VERTEX_COLOR_GREY);
        }

    private:
        uint32 liveTimer;
        uint8 maxlevel;
    };
};

void AddSC_dark_ranger_bot_pets()
{
    new dark_ranger_pet_bot();
}
