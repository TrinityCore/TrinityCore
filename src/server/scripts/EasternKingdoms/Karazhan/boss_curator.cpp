/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Curator
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Curator
{
    SAY_AGGRO                       = 0,
    SAY_SUMMON                      = 1,
    SAY_EVOCATE                     = 2,
    SAY_ENRAGE                      = 3,
    SAY_KILL                        = 4,
    SAY_DEATH                       = 5,

    //Flare spell info
    SPELL_ASTRAL_FLARE_PASSIVE      = 30234,               //Visual effect + Flare damage

    //Curator spell info
    SPELL_HATEFUL_BOLT              = 30383,
    SPELL_EVOCATION                 = 30254,
    SPELL_ENRAGE                    = 30403,               //Arcane Infusion: Transforms Curator and adds damage.
    SPELL_BERSERK                   = 26662,
};




class boss_curator : public CreatureScript
{
public:
    boss_curator() : CreatureScript("boss_curator") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_curatorAI (creature);
    }

    struct boss_curatorAI : public ScriptedAI
    {
        boss_curatorAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 AddTimer;
        uint32 HatefulBoltTimer;
        uint32 BerserkTimer;

        bool Enraged;
        bool Evocating;

        void Reset()
        {
            AddTimer = 10000;
            HatefulBoltTimer = 15000;                           //This time may be wrong
            BerserkTimer = 720000;                              //12 minutes
            Enraged = false;
            Evocating = false;

            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //always decrease BerserkTimer
            if (BerserkTimer <= diff)
            {
                //if evocate, then break evocate
                if (Evocating)
                {
                    if (me->HasAura(SPELL_EVOCATION))
                        me->RemoveAurasDueToSpell(SPELL_EVOCATION);

                    Evocating = false;
                }

                //may not be correct SAY (generic hard enrage)
                Talk(SAY_ENRAGE);

                me->InterruptNonMeleeSpells(true);
                DoCast(me, SPELL_BERSERK);

                //don't know if he's supposed to do summon/evocate after hard enrage (probably not)
                Enraged = true;
            } else BerserkTimer -= diff;

            if (Evocating)
            {
                //not supposed to do anything while evocate
                if (me->HasAura(SPELL_EVOCATION))
                    return;
                else
                    Evocating = false;
            }

            if (!Enraged)
            {
                if (AddTimer <= diff)
                {
                    //Summon Astral Flare
                    Creature* AstralFlare = DoSpawnCreature(17096, float(rand()%37), float(rand()%37), 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    Unit* target = NULL;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                    if (AstralFlare && target)
                    {
                        AstralFlare->CastSpell(AstralFlare, SPELL_ASTRAL_FLARE_PASSIVE, false);
                        AstralFlare->AI()->AttackStart(target);
                    }

                    //Reduce Mana by 10% of max health
                    if (int32 mana = me->GetMaxPower(POWER_MANA))
                    {
                        mana /= 10;
                        me->ModifyPower(POWER_MANA, -mana);

                        //if this get's us below 10%, then we evocate (the 10th should be summoned now)
                        if (me->GetPower(POWER_MANA)*100 / me->GetMaxPower(POWER_MANA) < 10)
                        {
                            Talk(SAY_EVOCATE);
                            me->InterruptNonMeleeSpells(false);
                            DoCast(me, SPELL_EVOCATION);
                            Evocating = true;
                            //no AddTimer cooldown, this will make first flare appear instantly after evocate end, like expected
                            return;
                        }
                        else
                        {
                            if (urand(0, 1) == 0)
                            {
                                Talk(SAY_SUMMON);
                            }
                        }
                    }

                    AddTimer = 10000;
                } else AddTimer -= diff;

                if (!HealthAbovePct(15))
                {
                    Enraged = true;
                    DoCast(me, SPELL_ENRAGE);
                    Talk(SAY_ENRAGE);
                }
            }

            if (HatefulBoltTimer <= diff)
            {
                if (Enraged)
                    HatefulBoltTimer = 7000;
                else
                    HatefulBoltTimer = 15000;

                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                    DoCast(target, SPELL_HATEFUL_BOLT);
            } else HatefulBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_curator()
{
    new boss_curator();
}
