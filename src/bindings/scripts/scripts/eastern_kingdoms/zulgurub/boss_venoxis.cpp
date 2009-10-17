/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Venoxis
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "precompiled.h"
#include "def_zulgurub.h"

#define SAY_TRANSFORM       -1309000
#define SAY_DEATH           -1309001

#define SPELL_HOLY_FIRE     23860
#define SPELL_HOLY_WRATH    28883                           //Not sure if this or 23979
#define SPELL_VENOMSPIT     23862
#define SPELL_HOLY_NOVA     23858
#define SPELL_POISON_CLOUD  23861
#define SPELL_SNAKE_FORM    23849
#define SPELL_RENEW         23895
#define SPELL_BERSERK       23537
#define SPELL_DISPELL       23859

struct TRINITY_DLL_DECL boss_venoxisAI : public ScriptedAI
{
    boss_venoxisAI(Creature *c) : ScriptedAI(c)
    {
        m_pInstance = c->GetInstanceData();
    }

    ScriptedInstance *m_pInstance;

    uint32 HolyFire_Timer;
    uint32 HolyWrath_Timer;
    uint32 VenomSpit_Timer;
    uint32 Renew_Timer;
    uint32 PoisonCloud_Timer;
    uint32 HolyNova_Timer;
    uint32 Dispell_Timer;
    uint32 TargetInRange;

    bool PhaseTwo;
    bool InBerserk;

    void Reset()
    {
        HolyFire_Timer = 10000;
        HolyWrath_Timer = 60500;
        VenomSpit_Timer = 5500;
        Renew_Timer = 30500;
        PoisonCloud_Timer = 2000;
        HolyNova_Timer = 5000;
        Dispell_Timer = 35000;
        TargetInRange = 0;

        PhaseTwo = false;
        InBerserk= false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (m_pInstance)
            m_pInstance->SetData(TYPE_VENOXIS, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
          if (!UpdateVictim())
            return;

            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth() > 50))
            {
                if (Dispell_Timer < diff)
                {
                    DoCast(m_creature, SPELL_DISPELL);
                    Dispell_Timer = 15000 + rand()%15000;
                }else Dispell_Timer -= diff;

                if (Renew_Timer < diff)
                {
                    DoCast(m_creature, SPELL_RENEW);
                    Renew_Timer = 20000 + rand()%10000;
                }else Renew_Timer -= diff;

                if (HolyWrath_Timer < diff)
                {
                    DoCast(m_creature->getVictim(), SPELL_HOLY_WRATH);
                    HolyWrath_Timer = 15000 + rand()%10000;
                }else HolyWrath_Timer -= diff;

                if (HolyNova_Timer < diff)
                {
                    TargetInRange = 0;
                    for(uint8 i=0; i<10; ++i)
                    {
                        if (Unit* target = SelectUnit(SELECT_TARGET_TOPAGGRO,i))
                            if (m_creature->IsWithinMeleeRange(target))
                                TargetInRange++;
                    }

                    if (TargetInRange > 1)
                    {
                        DoCast(m_creature->getVictim(),SPELL_HOLY_NOVA);
                        HolyNova_Timer = 1000;
                    }
                    else
                    {
                        HolyNova_Timer = 2000;
                    }

                }else HolyNova_Timer -= diff;

                if (HolyFire_Timer < diff && TargetInRange < 3)
                {
                    if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                        DoCast(target, SPELL_HOLY_FIRE);

                    HolyFire_Timer = 8000;
                }else HolyFire_Timer -= diff;
            }
            else
            {
                if (!PhaseTwo)
                {
                    DoScriptText(SAY_TRANSFORM, m_creature);
                    m_creature->InterruptNonMeleeSpells(false);
                    DoCast(m_creature,SPELL_SNAKE_FORM);
                    m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.00f);
                    const CreatureInfo *cinfo = m_creature->GetCreatureInfo();
                    m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 25)));
                    m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 25)));
                    m_creature->UpdateDamagePhysical(BASE_ATTACK);
                    DoResetThreat();
                    PhaseTwo = true;
                }

                if (PhaseTwo && PoisonCloud_Timer < diff)
                {
                    DoCast(m_creature->getVictim(), SPELL_POISON_CLOUD);
                    PoisonCloud_Timer = 15000;
                }PoisonCloud_Timer -=diff;

                if (PhaseTwo && VenomSpit_Timer < diff)
                {
                    if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                        DoCast(target, SPELL_VENOMSPIT);

                    VenomSpit_Timer = 15000 + rand()%5000;
                }else VenomSpit_Timer -= diff;

                if (PhaseTwo && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 11))
                {
                    if (!InBerserk)
                    {
                        m_creature->InterruptNonMeleeSpells(false);
                        DoCast(m_creature, SPELL_BERSERK);
                        InBerserk = true;
                    }
                }
            }
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_venoxis(Creature* pCreature)
{
    return new boss_venoxisAI (pCreature);
}

void AddSC_boss_venoxis()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_venoxis";
    newscript->GetAI = &GetAI_boss_venoxis;
    newscript->RegisterSelf();
}

