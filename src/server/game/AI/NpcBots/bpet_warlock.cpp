#include "bot_ai.h"
#include "bpet_ai.h"
#include "botmgr.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Player.h"
#include "TemporarySummon.h"
/*
Warlock NpcBot Pets (by Trickerer onlysuffering@gmail.com)
Complete - 100%
TODO:
*/

enum WarlockPetBaseSpells
{
    //imp
    FIREBOLT_1                          = 3110,//1
    BLOOD_PACT_1                        = 6307,//4
    PHASE_SHIFT_1                       = 4511,//12
    FIRE_SHIELD_1                       = 2947,//14 unused
    //voidwalker
    TORMENT_1                           = 3716,//10
    SACRIFICE_1                         = 7812,//16
    CONSUME_SHADOWS_1                   = 17767,//18
    SUFFERING_1                         = 17735,//24
    //succubus
    LASH_OF_PAIN_1                      = 7814,//20
    SOOTHING_KISS_1                     = 6360,//22
    SEDUCTION_1                         = 6358,//26
    LESSER_INVISIBILITY_1               = 7870,//32
    //felhunter
    DEVOUR_MAGIC_1                      = 19505,//30
    FEL_INTELLIGENCE_1                  = 54424,//32
    SPELL_LOCK_1                        = 19244,//36
    SHADOW_BITE_1                       = 54049,//42
    //felguard
    ANGUISH_1                           = 33698,//50
    CLEAVE_1                            = 30213,//50
    INTERCEPT_1                         = 30151 //52
};

enum WarlockPetPassives
{
    AVOIDANCE                           = 32233,
    DEMONIC_FRENZY                      = 32850
};

enum WarlockPetSpecial
{
    SOUL_LINK_PET                       = 25228//split effect lvl 20 req
};

class warlock_pet_bot : public CreatureScript
{
public:
    warlock_pet_bot() : CreatureScript("warlock_pet_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new warlock_botpetAI(creature);
    }

    struct warlock_botpetAI : public bot_pet_ai
    {
        warlock_botpetAI(Creature* creature) : bot_pet_ai(creature) { }

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
            if (GetSpell(SOUL_LINK_PET) && !petOwner->HasAuraTypeWithCaster(SPELL_AURA_SPLIT_DAMAGE_PCT, me->GetGUID()))
            {
                me->CastSpell(me, SOUL_LINK_PET, false);
                return;
            }
            if (myType == BOT_PET_IMP)
            {
                //hacked - confilct with soul link due to ownerGuid mismatch
                if (IsSpellReady(BLOOD_PACT_1, diff, false) && (!me->HasAuraType(SPELL_AURA_230) ||
                    me->GetAuraEffectsByType(SPELL_AURA_230).front()->GetAmount() < sSpellMgr->GetSpellInfo(GetSpell(BLOOD_PACT_1))->Effects[0].CalcValue()))
                {
                    me->CastSpell(me, GetSpell(BLOOD_PACT_1), false);
                    //CastSpellExtraArgs args(true);
                    //args.SetOriginalCaster(me->GetGUID());
                    //petOwner->CastSpell(petOwner, GetSpell(BLOOD_PACT_1), args);
                    SetSpellCooldown(BLOOD_PACT_1, uint32(-1));
                }

                if (IsSpellReady(PHASE_SHIFT_1, diff, false) && !me->GetVictim() &&
                    (!petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS) || !me->IsInCombat()) &&
                    !me->HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
                {
                    me->CastSpell(me, GetSpell(PHASE_SHIFT_1), false);
                    return;
                }
            }
            else if (myType == BOT_PET_VOIDWALKER)
            {
                if (GetSpell(CONSUME_SHADOWS_1) && !me->IsInCombat() && !me->isMoving() &&
                    me->GetDistance(me) < 10 && GetHealthPCT(me) < 80)
                {
                    me->CastSpell(me, GetSpell(CONSUME_SHADOWS_1), false);
                    return;
                }

                if (IsSpellReady(SACRIFICE_1, diff, false) &&
                    (!petOwner->getAttackers().empty() || petOwner->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) &&
                    me->GetHealth() > me->GetCreateHealth() / 4) //hp cost 25%
                {
                    me->CastSpell(me, GetSpell(SACRIFICE_1), false);
                    return;
                }
            }
            else if (myType == BOT_PET_SUCCUBUS)
            {
                if (IsSpellReady(SOOTHING_KISS_1, diff, false) &&
                    !me->getAttackers().empty() && me->GetDistance(*(me->getAttackers().begin())) < 10)
                {
                    me->CastSpell(*(me->getAttackers().begin()), GetSpell(SOOTHING_KISS_1), false);
                    SetSpellCooldown(SOOTHING_KISS_1, 4000);
                    return;
                }

                if (GetSpell(SEDUCTION_1) && Rand() < 20 && !IsCasting())
                {
                    Unit* target = petOwner->GetBotAI()->HelpFindStunTarget(30);
                    if (target && target->GetDiminishing(DIMINISHING_FEAR) <= DIMINISHING_LEVEL_2 + 1 * (target->IsNonMeleeSpellCast(false, false, true)))
                    {
                        me->CastSpell(target, GetSpell(SEDUCTION_1), false);
                        return;
                    }
                }

                if (IsSpellReady(LESSER_INVISIBILITY_1, diff, false) && !me->GetVictim() && !me->IsInCombat() &&
                    !me->HasAuraType(SPELL_AURA_MOD_INVISIBILITY))
                {
                    me->CastSpell(me, GetSpell(LESSER_INVISIBILITY_1), false);
                    return;
                }
            }
            else if (myType == BOT_PET_FELHUNTER)
            {
                //hacked - confilct with soul link due to ownerGuid mismatch
                if (IsSpellReady(FEL_INTELLIGENCE_1, diff, false) &&
                    (IAmFree() ||
                    (!petOwner->GetBotOwner()->GetBotMgr()->HasBotClass(BOT_CLASS_MAGE) &&
                    !petOwner->GetBotOwner()->GetBotMgr()->HasBotClass(BOT_CLASS_PRIEST))))
                {
                    me->CastSpell(me, GetSpell(FEL_INTELLIGENCE_1), false);
                    //CastSpellExtraArgs args(true);
                    //args.SetOriginalCaster(me->GetGUID());
                    //petOwner->CastSpell(petOwner, GetSpell(FEL_INTELLIGENCE_1), args);
                    SetSpellCooldown(FEL_INTELLIGENCE_1, uint32(-1));
                }

                if (IsSpellReady(SPELL_LOCK_1, diff, false))
                {
                    if (Unit* target = petOwner->GetBotAI()->HelpFindCastingTarget(30, 0, SPELL_LOCK_1))
                        me->CastSpell(target, GetSpell(SPELL_LOCK_1), false);
                }

                CureGroup(GetSpell(DEVOUR_MAGIC_1), diff);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            if (Spell const* spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
            {
                if (myType == BOT_PET_SUCCUBUS)
                {
                    if (Unit const* target = spell->m_targets.GetUnitTarget())
                    {
                        //Seduction interrupt
                        if (spell->GetSpellInfo()->GetFirstRankSpell()->Id == SEDUCTION_1 && CCed(target))
                            me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    }
                }
            }

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
            Unit const* u = opponent->GetVictim();
            bool canDPS = petOwner->GetBotAI()->HasRole(BOT_ROLE_DPS);

            if (myType == BOT_PET_IMP)
            {
                if (GetSpell(FIREBOLT_1) && canDPS && dist < 30)
                {
                    me->CastSpell(opponent, GetSpell(FIREBOLT_1), false);
                    return;
                }
            }
            else if (myType == BOT_PET_VOIDWALKER)
            {
                if (IsSpellReady(TORMENT_1, diff, false) && u && u != me && me->IsWithinMeleeRange(opponent) &&
                    opponent->CanHaveThreatList() && !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                    (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 20)) && IsInBotParty(u))
                {
                    me->CastSpell(opponent, GetSpell(TORMENT_1), false);
                    SetSpellCooldown(TORMENT_1, 5000);
                    return;
                }

                if (IsSpellReady(SUFFERING_1, diff) &&
                    !(u == me && opponent->GetTypeId() == TYPEID_UNIT &&
                    (opponent->ToCreature()->IsDungeonBoss() || opponent->ToCreature()->isWorldBoss())))
                {
                    std::list<Unit*> targets;
                    petOwner->GetBotAI()->HelpGetNearbyTargetsList(targets, 9.f, 1, me);
                    uint8 count = 0;
                    for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        if (!((*itr)->GetVictim() && IsTank((*itr)->GetVictim())))
                            if (++count > 1)
                                break;
                    }
                    if (count < 2 && u && u != me && !IsSpellReady(TORMENT_1, diff, false) && !IsTank(u) && !CCed(opponent) && dist < 8 &&
                        IsInBotParty(u))
                    {
                        count += 2;
                    }

                    if (count > 1)
                    {
                        me->CastSpell(me, GetSpell(SUFFERING_1), false);
                        SetSpellCooldown(SUFFERING_1, 120000);
                        return;
                    }
                }
            }
            else if (myType == BOT_PET_SUCCUBUS)
            {
                if (IsSpellReady(LASH_OF_PAIN_1, diff, false) && canDPS && me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(LASH_OF_PAIN_1), false);
                    //this could have worked if cast was triggered
                    //SetSpellCooldown(LASH_OF_PAIN_1, 6000); //Demonic Power part 1
                    return;
                }
            }
            else if (myType == BOT_PET_FELHUNTER)
            {
                if (IsSpellReady(SHADOW_BITE_1, diff, false) && canDPS && me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(SHADOW_BITE_1), false);
                    SetSpellCooldown(SHADOW_BITE_1, me->GetLevel() >= 35 ? 2000 : 6000); //improved felhunter part 2
                    return;
                }
            }
            else if (myType == BOT_PET_FELGUARD)
            {
                if (IsSpellReady(INTERCEPT_1, diff, false) && canDPS &&
                    !HasBotCommandState(BOT_COMMAND_STAY) &&
                    !(opponent->GetTypeId() == TYPEID_UNIT && opponent->ToCreature()->isWorldBoss()) &&
                    dist > 8 && dist < 25 && !CCed(opponent))
                {
                    me->CastSpell(opponent, GetSpell(INTERCEPT_1), false);
                    SetSpellCooldown(INTERCEPT_1, 30000);
                    return;
                }

                if (IsSpellReady(ANGUISH_1, diff, false) && u && u != me && me->IsWithinMeleeRange(opponent) &&
                    opponent->CanHaveThreatList() && !CCed(opponent) && !opponent->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                    (!IsTank(u) || (GetHealthPCT(u) < 30 && GetHealthPCT(me) > 20)) && IsInBotParty(u))
                {
                    me->CastSpell(opponent, GetSpell(ANGUISH_1), false);
                    SetSpellCooldown(ANGUISH_1, 5000);
                    return;
                }

                if (IsSpellReady(CLEAVE_1, diff, false) && canDPS && me->IsWithinMeleeRange(opponent))
                {
                    me->CastSpell(opponent, GetSpell(CLEAVE_1), false);
                    SetSpellCooldown(CLEAVE_1, 6000);
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
        }

        void InitPetSpells() override
        {
            InitSpellMap(FIREBOLT_1);
            InitSpellMap(BLOOD_PACT_1);
            InitSpellMap(PHASE_SHIFT_1);
            //InitSpellMap(FIRE_SHIELD_1);

            InitSpellMap(TORMENT_1);
            InitSpellMap(SACRIFICE_1);
            InitSpellMap(CONSUME_SHADOWS_1);
            InitSpellMap(SUFFERING_1);

            InitSpellMap(LASH_OF_PAIN_1);
            InitSpellMap(SOOTHING_KISS_1);
            InitSpellMap(SEDUCTION_1);
            InitSpellMap(LESSER_INVISIBILITY_1);

            InitSpellMap(DEVOUR_MAGIC_1);
            InitSpellMap(FEL_INTELLIGENCE_1);
            InitSpellMap(SPELL_LOCK_1);
            InitSpellMap(SHADOW_BITE_1);

            InitSpellMap(ANGUISH_1);
            InitSpellMap(CLEAVE_1);
            InitSpellMap(INTERCEPT_1);

            InitSpellMap(SOUL_LINK_PET);
        }

        void ApplyPetPassives() const override
        {
            uint8 lvl = me->GetLevel();
            switch (myType)
            {
                case BOT_PET_FELGUARD:
                    RefreshAura(DEMONIC_FRENZY);
                    break;
                default:
                    break;
            }

            RefreshAura(AVOIDANCE, lvl >= 60 ? 1 : 0);
        }

    private:
    };
};

void AddSC_warlock_bot_pets()
{
    new warlock_pet_bot();
}
