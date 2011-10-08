/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

enum Quotes
{
 YELL_INTRO                 =   -1580017,
 YELL_INTRO_BREAK_ICE       =   -1580018,
 YELL_INTRO_CHARGE          =   -1580019,
 YELL_INTRO_KILL_MADRIGOSA  =   -1580020,
 YELL_INTRO_TAUNT           =   -1580021,

 YELL_MADR_ICE_BARRIER      =   -1580031,
 YELL_MADR_INTRO            =   -1580032,
 YELL_MADR_ICE_BLOCK        =   -1580033,
 YELL_MADR_TRAP             =   -1580034,
 YELL_MADR_DEATH            =   -1580035,

 YELL_AGGRO                 =   -1580022,
 YELL_KILL1                 =   -1580023,
 YELL_KILL2                 =   -1580024,
 YELL_KILL3                 =   -1580025,
 YELL_LOVE1                 =   -1580026,
 YELL_LOVE2                 =   -1580027,
 YELL_LOVE3                 =   -1580028,
 YELL_BERSERK               =   -1580029,
 YELL_DEATH                 =   -1580030
};

enum Spells
{
    SPELL_METEOR_SLASH                 =   45150,
    SPELL_BURN                         =   46394,
    SPELL_STOMP                        =   45185,
    SPELL_BERSERK                      =   26662,
    SPELL_DUAL_WIELD                   =   42459,

    SPELL_INTRO_FROST_BLAST            =   45203,
    SPELL_INTRO_FROSTBOLT              =   44843,
    SPELL_INTRO_ENCAPSULATE            =   45665,
    SPELL_INTRO_ENCAPSULATE_CHANELLING =   45661
};

#define FELMYST 25038

class boss_brutallus : public CreatureScript
{
public:
    boss_brutallus() : CreatureScript("boss_brutallus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_brutallusAI (creature);
    }

    struct boss_brutallusAI : public ScriptedAI
    {
        boss_brutallusAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
            Intro = true;
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

        void Reset()
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

            DoCast(me, SPELL_DUAL_WIELD, true);

            if (instance)
                instance->SetData(DATA_BRUTALLUS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(YELL_AGGRO, me);

            if (instance)
                instance->SetData(DATA_BRUTALLUS_EVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(YELL_KILL1, YELL_KILL2, YELL_KILL3), me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(YELL_DEATH, me);

            if (instance)
            {
                instance->SetData(DATA_BRUTALLUS_EVENT, DONE);
                float x, y, z;
                me->GetPosition(x, y, z);
                me->SummonCreature(FELMYST, x, y, z+30, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0);
            }
        }

        void EnterEvadeMode()
        {
            if (!Intro)
                ScriptedAI::EnterEvadeMode();
        }

        void StartIntro()
        {
            if (!Intro || IsIntro)
                return;
            Creature* Madrigosa = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_MADRIGOSA) : 0);
            if (Madrigosa)
            {
                Madrigosa->Respawn();
                Madrigosa->setActive(true);
                IsIntro = true;
                Madrigosa->SetMaxHealth(me->GetMaxHealth());
                Madrigosa->SetHealth(me->GetMaxHealth());
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->Attack(Madrigosa, true);
                Madrigosa->Attack(me, true);
            }
            else
            {
                //Madrigosa not found, end intro
                sLog->outError("Madrigosa was not found");
                EndIntro();
            }
        }

        void EndIntro()
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            Intro = false;
            IsIntro = false;
        }

        void AttackStart(Unit* who)
        {
            if (!who || Intro || IsIntro)
                return;
            ScriptedAI::AttackStart(who);
        }

        void DoIntro()
        {
            Creature* Madrigosa = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_MADRIGOSA) : 0);
            if (!Madrigosa)
                return;

            switch (IntroPhase)
            {
                case 0:
                    DoScriptText(YELL_MADR_ICE_BARRIER, Madrigosa);
                    IntroPhaseTimer = 7000;
                    ++IntroPhase;
                    break;
                case 1:
                    me->SetInFront(Madrigosa);
                    Madrigosa->SetInFront(me);
                    DoScriptText(YELL_MADR_INTRO, Madrigosa, me);
                    IntroPhaseTimer = 9000;
                    ++IntroPhase;
                    break;
                case 2:
                    DoScriptText(YELL_INTRO, me, Madrigosa);
                    IntroPhaseTimer = 13000;
                    ++IntroPhase;
                    break;
                case 3:
                    DoCast(me, SPELL_INTRO_FROST_BLAST);
                    Madrigosa->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->AttackStop();
                    Madrigosa->AttackStop();
                    IntroFrostBoltTimer = 3000;
                    IntroPhaseTimer = 28000;
                    ++IntroPhase;
                    break;
                case 4:
                    DoScriptText(YELL_INTRO_BREAK_ICE, me);
                    IntroPhaseTimer = 6000;
                    ++IntroPhase;
                    break;
                case 5:
                    Madrigosa->CastSpell(me, SPELL_INTRO_ENCAPSULATE_CHANELLING, false);
                    DoScriptText(YELL_MADR_TRAP, Madrigosa);
                    DoCast(me, SPELL_INTRO_ENCAPSULATE);
                    IntroPhaseTimer = 11000;
                    ++IntroPhase;
                    break;
                case 6:
                    DoScriptText(YELL_INTRO_CHARGE, me);
                    IntroPhaseTimer = 5000;
                    ++IntroPhase;
                    break;
                case 7:
                    me->Kill(Madrigosa);
                    DoScriptText(YELL_MADR_DEATH, Madrigosa);
                    me->SetFullHealth();
                    me->AttackStop();
                    IntroPhaseTimer = 4000;
                    ++IntroPhase;
                    break;
                case 8:
                    DoScriptText(YELL_INTRO_KILL_MADRIGOSA, me);
                    me->SetOrientation(0.14f);
                    me->StopMoving();
                    Madrigosa->setDeathState(CORPSE);
                    IntroPhaseTimer = 8000;
                    ++IntroPhase;
                    break;
                case 9:
                    DoScriptText(YELL_INTRO_TAUNT, me);
                    IntroPhaseTimer = 5000;
                    ++IntroPhase;
                    break;
                case 10:
                    EndIntro();
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!me->IsValidAttackTarget(who))
                return;
            if (instance && Intro)
                instance->SetData(DATA_BRUTALLUS_EVENT, SPECIAL);

            if (Intro && !IsIntro)
                StartIntro();
            if (!Intro)
                ScriptedAI::MoveInLineOfSight(who);
        }

        void UpdateAI(const uint32 diff)
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
                        if (Creature* Madrigosa = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_MADRIGOSA) : 0))
                        {
                            Madrigosa->CastSpell(me, SPELL_INTRO_FROSTBOLT, true);
                            IntroFrostBoltTimer = 2000;
                        }
                    } else IntroFrostBoltTimer -= diff;
                }
                if (!UpdateVictim())
                    return;
                DoMeleeAttackIfReady();
            }

            if (!UpdateVictim() || IsIntro)
                return;

            if (SlashTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_METEOR_SLASH);
                SlashTimer = 11000;
            } else SlashTimer -= diff;

            if (StompTimer <= diff)
            {
                DoScriptText(RAND(YELL_LOVE1, YELL_LOVE2, YELL_LOVE3), me);
                DoCast(me->getVictim(), SPELL_STOMP);
                StompTimer = 30000;
            } else StompTimer -= diff;

            if (BurnTimer <= diff)
            {
                std::list<Unit*> targets;
                SelectTargetList(targets, 10, SELECT_TARGET_RANDOM, 100, true);
                for (std::list<Unit*>::const_iterator i = targets.begin(); i != targets.end(); ++i)
                    if (!(*i)->HasAura(SPELL_BURN))
                    {
                        (*i)->CastSpell((*i), SPELL_BURN, true);
                        break;
                    }
                BurnTimer = urand(60000, 180000);
            } else BurnTimer -= diff;

            if (BerserkTimer < diff && !Enraged)
            {
                DoScriptText(YELL_BERSERK, me);
                DoCast(me, SPELL_BERSERK);
                Enraged = true;
            } else BerserkTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_brutallus()
{
    new boss_brutallus();
}
