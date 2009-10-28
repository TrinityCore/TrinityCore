/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Curator
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO                       -1532057
#define SAY_SUMMON1                     -1532058
#define SAY_SUMMON2                     -1532059
#define SAY_EVOCATE                     -1532060
#define SAY_ENRAGE                      -1532061
#define SAY_KILL1                       -1532062
#define SAY_KILL2                       -1532063
#define SAY_DEATH                       -1532064

//Flare spell info
#define SPELL_ASTRAL_FLARE_PASSIVE      30234               //Visual effect + Flare damage

//Curator spell info
#define SPELL_HATEFUL_BOLT              30383
#define SPELL_EVOCATION                 30254
#define SPELL_ENRAGE                    30403               //Arcane Infusion: Transforms Curator and adds damage.
#define SPELL_BERSERK                   26662

struct  TRINITY_DLL_DECL boss_curatorAI : public ScriptedAI
{
    boss_curatorAI(Creature *c) : ScriptedAI(c) {}

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

        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_KILL1,SAY_KILL2), m_creature);
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
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
                if (m_creature->HasAura(SPELL_EVOCATION))
                    m_creature->RemoveAurasDueToSpell(SPELL_EVOCATION);

                Evocating = false;
            }

            //may not be correct SAY (generic hard enrage)
            DoScriptText(SAY_ENRAGE, m_creature);

            m_creature->InterruptNonMeleeSpells(true);
            DoCast(m_creature, SPELL_BERSERK);

            //don't know if he's supposed to do summon/evocate after hard enrage (probably not)
            Enraged = true;
        } else BerserkTimer -= diff;

        if (Evocating)
        {
            //not supposed to do anything while evocate
            if (m_creature->HasAura(SPELL_EVOCATION))
                return;
            else
                Evocating = false;
        }

        if (!Enraged)
        {
            if (AddTimer <= diff)
            {
                //Summon Astral Flare
                Creature* AstralFlare = DoSpawnCreature(17096, rand()%37, rand()%37, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

                if (AstralFlare && pTarget)
                {
                    AstralFlare->CastSpell(AstralFlare, SPELL_ASTRAL_FLARE_PASSIVE, false);
                    AstralFlare->AI()->AttackStart(pTarget);
                }

                //Reduce Mana by 10% of max health
                if (int32 mana = m_creature->GetMaxPower(POWER_MANA))
                {
                    mana /= 10;
                    m_creature->ModifyPower(POWER_MANA, -mana);

                    //if this get's us below 10%, then we evocate (the 10th should be summoned now)
                    if (m_creature->GetPower(POWER_MANA)*100 / m_creature->GetMaxPower(POWER_MANA) < 10)
                    {
                        DoScriptText(SAY_EVOCATE, m_creature);
                        m_creature->InterruptNonMeleeSpells(false);
                        DoCast(m_creature, SPELL_EVOCATION);
                        Evocating = true;
                        //no AddTimer cooldown, this will make first flare appear instantly after evocate end, like expected
                        return;
                    }
                    else
                    {
                        if(urand(0,1) == 0)
                        {
                            DoScriptText(RAND(SAY_SUMMON1,SAY_SUMMON2), m_creature);
                        }
                    }
                }

                AddTimer = 10000;
            } else AddTimer -= diff;

            if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 15)
            {
                Enraged = true;
                DoCast(m_creature, SPELL_ENRAGE);
                DoScriptText(SAY_ENRAGE, m_creature);
            }
        }

        if (HatefulBoltTimer <= diff)
        {
            if (Enraged)
                HatefulBoltTimer = 7000;
            else
                HatefulBoltTimer = 15000;

            if (Unit *pTarget = SelectUnit(SELECT_TARGET_TOPAGGRO, 1))
                DoCast(pTarget, SPELL_HATEFUL_BOLT);

        } else HatefulBoltTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_curator(Creature* pCreature)
{
    return new boss_curatorAI (pCreature);
}

void AddSC_boss_curator()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_curator";
    newscript->GetAI = &GetAI_boss_curator;
    newscript->RegisterSelf();
}
