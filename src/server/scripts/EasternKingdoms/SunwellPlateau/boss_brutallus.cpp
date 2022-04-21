/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Brutallus
SD%Complete: 80
SDComment: Find a way to start the intro, best code for the intro
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "sunwell_plateau.h"

enum Quotes
{
    YELL_INTRO                          = 0,
    YELL_INTRO_BREAK_ICE                = 1,
    YELL_INTRO_CHARGE                   = 2,
    YELL_INTRO_KILL_MADRIGOSA           = 3,
    YELL_INTRO_TAUNT                    = 4,

    YELL_AGGRO                          = 5,
    YELL_KILL                           = 6,
    YELL_LOVE                           = 7,
    YELL_BERSERK                        = 8,
    YELL_DEATH                          = 9,

    YELL_MADR_ICE_BARRIER               = 0,
    YELL_MADR_INTRO                     = 1,
    YELL_MADR_ICE_BLOCK                 = 2,
    YELL_MADR_TRAP                      = 3,
    YELL_MADR_DEATH                     = 4
};

enum Spells
{
    SPELL_METEOR_SLASH                  = 45150,
    SPELL_BURN                          = 46394,
    SPELL_STOMP                         = 45185,
    SPELL_BERSERK                       = 26662,
    SPELL_DUAL_WIELD                    = 42459,

    SPELL_INTRO_FROST_BLAST             = 45203,
    SPELL_INTRO_FROSTBOLT               = 44843,
    SPELL_INTRO_ENCAPSULATE             = 45665,
    SPELL_INTRO_ENCAPSULATE_CHANELLING  = 45661
};

class boss_brutallus : public CreatureScript
{
public:
    boss_brutallus() : CreatureScript("boss_brutallus") { }

    struct boss_brutallusAI : public ScriptedAI
    {
        boss_brutallusAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            Intro = true;
        }

        void Initialize()
        {
            SlashTimer = 11000;
            StompTimer = 30000;
            BurnTimer = 60000;
            BerserkTimer = 360000;

            IntroPhase = 0;
            IntroPhaseTimer = 0;
            IntroFrostBoltTimer = 0;

            IsIntro = false;
            Enraged = false;
        }

        InstanceScript* instance;

        uint32 SlashTimer;
        uint32 BurnTimer;
        uint32 StompTimer;
        uint32 BerserkTimer;

        uint32 IntroPhase;
        uint32 IntroPhaseTimer;
        uint32 IntroFrostBoltTimer;

        bool Intro;
        bool IsIntro;
        bool Enraged;

        void Reset() override
        {
            Initialize();

            DoCast(me, SPELL_DUAL_WIELD, true);

            instance->SetBossState(DATA_BRUTALLUS, NOT_STARTED);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(YELL_AGGRO);

            instance->SetBossState(DATA_BRUTALLUS, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(YELL_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(YELL_DEATH);

            instance->SetBossState(DATA_BRUTALLUS, DONE);
            float x, y, z;
            me->GetPosition(x, y, z);
            me->SummonCreature(NPC_FELMYST, x, y, z + 30, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (!Intro)
                ScriptedAI::EnterEvadeMode(why);
        }

        void StartIntro()
        {
            if (!Intro || IsIntro)
                return;

            if (Creature* Madrigosa = instance->GetCreature(DATA_MADRIGOSA))
            {
                Madrigosa->Respawn();
                Madrigosa->setActive(true);
                Madrigosa->SetFarVisible(true);
                IsIntro = true;
                Madrigosa->SetMaxHealth(me->GetMaxHealth());
                Madrigosa->SetHealth(me->GetMaxHealth());
                me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->Attack(Madrigosa, true);
                Madrigosa->Attack(me, true);
            }
            else
            {
                // Madrigosa not found, end intro
                TC_LOG_ERROR("scripts", "Madrigosa was not found");
                EndIntro();
            }
        }

        void EndIntro()
        {
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            Intro = false;
            IsIntro = false;
        }

        void AttackStart(Unit* who) override
        {
            if (!who || Intro || IsIntro)
                return;
            ScriptedAI::AttackStart(who);
        }

        void DoIntro()
        {
            Creature* Madrigosa = instance->GetCreature(DATA_MADRIGOSA);
            if (!Madrigosa)
                return;

            switch (IntroPhase)
            {
                case 0:
                    Madrigosa->AI()->Talk(YELL_MADR_ICE_BARRIER);
                    IntroPhaseTimer = 7000;
                    ++IntroPhase;
                    break;
                case 1:
                    me->SetFacingToObject(Madrigosa);
                    Madrigosa->SetFacingToObject(me);
                    Madrigosa->AI()->Talk(YELL_MADR_INTRO, me);
                    IntroPhaseTimer = 9000;
                    ++IntroPhase;
                    break;
                case 2:
                    Talk(YELL_INTRO, Madrigosa);
                    IntroPhaseTimer = 13000;
                    ++IntroPhase;
                    break;
                case 3:
                    DoCast(me, SPELL_INTRO_FROST_BLAST);
                    Madrigosa->SetDisableGravity(true);
                    me->AttackStop();
                    Madrigosa->AttackStop();
                    IntroFrostBoltTimer = 3000;
                    IntroPhaseTimer = 28000;
                    ++IntroPhase;
                    break;
                case 4:
                    Talk(YELL_INTRO_BREAK_ICE);
                    IntroPhaseTimer = 6000;
                    ++IntroPhase;
                    break;
                case 5:
                    Madrigosa->CastSpell(me, SPELL_INTRO_ENCAPSULATE_CHANELLING, false);
                    Madrigosa->AI()->Talk(YELL_MADR_TRAP);
                    DoCast(me, SPELL_INTRO_ENCAPSULATE);
                    IntroPhaseTimer = 11000;
                    ++IntroPhase;
                    break;
                case 6:
                    Talk(YELL_INTRO_CHARGE);
                    IntroPhaseTimer = 5000;
                    ++IntroPhase;
                    break;
                case 7:
                    Unit::Kill(me, Madrigosa);
                    Madrigosa->AI()->Talk(YELL_MADR_DEATH);
                    me->SetFullHealth();
                    me->AttackStop();
                    IntroPhaseTimer = 4000;
                    ++IntroPhase;
                    break;
                case 8:
                    Talk(YELL_INTRO_KILL_MADRIGOSA);
                    me->SetOrientation(0.14f);
                    me->StopMoving();
                    Madrigosa->setDeathState(CORPSE);
                    IntroPhaseTimer = 8000;
                    ++IntroPhase;
                    break;
                case 9:
                    Talk(YELL_INTRO_TAUNT);
                    IntroPhaseTimer = 5000;
                    ++IntroPhase;
                    break;
                case 10:
                    EndIntro();
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!me->IsValidAttackTarget(who))
                return;

            if (Intro)
                instance->SetBossState(DATA_BRUTALLUS, SPECIAL);

            if (Intro && !IsIntro)
                StartIntro();

            if (!Intro)
                ScriptedAI::MoveInLineOfSight(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if (IsIntro)
            {
                if (IntroPhaseTimer <= diff)
                    DoIntro();
                else IntroPhaseTimer -= diff;

                if (IntroPhase == 3 + 1)
                {
                    if (IntroFrostBoltTimer <= diff)
                    {
                        if (Creature* Madrigosa = instance->GetCreature(DATA_MADRIGOSA))
                        {
                            Madrigosa->CastSpell(me, SPELL_INTRO_FROSTBOLT, true);
                            IntroFrostBoltTimer = 2000;
                        }
                    }
                    else
                        IntroFrostBoltTimer -= diff;
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            if (!UpdateVictim() || IsIntro)
                return;

            if (SlashTimer <= diff)
            {
                DoCastVictim(SPELL_METEOR_SLASH);
                SlashTimer = 11000;
            } else SlashTimer -= diff;

            if (StompTimer <= diff)
            {
                Talk(YELL_LOVE);
                DoCastVictim(SPELL_STOMP);
                StompTimer = 30000;
            } else StompTimer -= diff;

            if (BurnTimer <= diff)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_BURN))
                    target->CastSpell(target, SPELL_BURN, true);
                BurnTimer = urand(60000, 180000);
            } else BurnTimer -= diff;

            if (BerserkTimer < diff && !Enraged)
            {
                Talk(YELL_BERSERK);
                DoCast(me, SPELL_BERSERK);
                Enraged = true;
            } else BerserkTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_brutallusAI>(creature);
    }
};

// 46394 - Burn
class spell_brutallus_burn : public AuraScript
{
    PrepareAuraScript(spell_brutallus_burn);

    void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
    {
        if (aurEff->GetTickNumber() % 11 == 0)
            aurEff->SetAmount(aurEff->GetAmount() * 2);
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_brutallus_burn::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_brutallus()
{
    new boss_brutallus();
    RegisterSpellScript(spell_brutallus_burn);
}
