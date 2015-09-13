/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "precompiled.h"

#define SPELL_ROAR	36922	// aoe fear x 4 secondi. il timer � offylike.
#define SPELL_CHARRED_EARTH	30129	// 21k di danno over 30 secondi... li avverto.
#define SPELL_CLEAVE	31345	// il cleave + debole. ogni 25 secondi xk ogni 20 gli faccio fare lo smoking blast
#define SPELL_ASH	30130	// riduce canche to hit con tt del 30%. dura 40 secondi
#define SPELL_BREATH	30210	// tipica fiammata. 4k danno subito, 1700 ogni 3 sec x 15 sec.
#define SPELL_SWEEP	25653	// codata k fa 450 di danno + 450 ogni 3 sec x 24 sec. in teoria sl a qll dietro
#define SPELL_WAVE	39038	// 3500 to 4500 danno. scelta xk ha 20 yard radius. anke knockback. ogni minuto.
#define SPELL_BLAST	30128	// circa 2k danno + 3k danno over 18 sec

#define SAY_RICHIAMO	"STATE OSANDO TROPPO!"
#define SAY_VOTOSULREGISTRO	"BRUCIATE TRA LE ANTICHE FIAMME DI MEDIVH!"
#define SAY_KILL	"cenere! questa � la fine che vi aspetta!"
#define SAY_AGGRO1	"Com'� possibile? Voi non siete Medivh!"
#define SAY_AGGRO2	"Chi osa evocarmi?"

struct MANGOS_DLL_DECL boss_nightbaneAI : public ScriptedAI
{
    boss_nightbaneAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 roar_timer;
    uint32 cleave_timer;
    uint32 ash_timer;
    uint32 breath_timer;
    uint32 sweep_timer;
    uint32 wave_timer;
    uint32 blast_timer;
    
    bool said;
    bool voto;

    Unit* target;
    Unit* target2;
    

    void Reset()
    {
        // alcuni timer iniziali sono + brevi
        roar_timer = 50000;
        cleave_timer = 15000; // dopo diventa 25 sec
        ash_timer = 40000; // dopo diventa 2 min e 5 sec
        breath_timer = 18000;
        sweep_timer = 30000;
        wave_timer = 55000;
        blast_timer = 5000; // dopo diventa 20 sec

        said = false;
        voto = false;

        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM , true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR , true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SILENCE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DAZE, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
    }


    void KilledUnit(Unit* Victim)
    {
        m_creature->MonsterYell(SAY_KILL,LANG_UNIVERSAL,NULL);
    }

	void Aggro(Unit *who)
    {        
            switch(rand()%2)
            {
                case 0:
                m_creature->MonsterYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
                break;

                case 1:
                m_creature->MonsterYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
                break;
            }

    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() )
            return;

        if (roar_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ROAR);
            roar_timer = 50000;
        }
        else roar_timer -= diff;

        if (cleave_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            cleave_timer = 10000;
        }
        else cleave_timer -= diff;

        if(ash_timer < diff)
        {
            target = m_creature->SelectRandomUnfriendlyTarget();
            DoCast(target,SPELL_ASH);
            ash_timer = 32000;
        }
        else ash_timer -= diff;

        if(breath_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BREATH);
            breath_timer = 18000;
        }
        else breath_timer -= diff;

        if(sweep_timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SWEEP);
            sweep_timer = 30000;
        }
        else sweep_timer -= diff;

        if(blast_timer < diff)
        {

            switch(rand()%2)
            {
             case 0:
                 target2 = m_creature->SelectRandomUnfriendlyTarget();
                 DoCast(target2,SPELL_BLAST);
                 break;
             case 1:
                 DoCast(m_creature->getVictim(),SPELL_BLAST);
                 break;
            }

            blast_timer = 8000;
        }
        else blast_timer -= diff;

        if ( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 60 && !said)
        {   
            said = true;    
            m_creature->MonsterYell(SAY_RICHIAMO,LANG_UNIVERSAL,NULL);
        }

        if ( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 50 )
        {   
            if(!voto)
            {
               m_creature->MonsterYell(SAY_VOTOSULREGISTRO,LANG_UNIVERSAL,NULL);
               DoCast(m_creature->getVictim(),SPELL_CHARRED_EARTH);
               voto = true;
            }

            if(wave_timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_WAVE);
                wave_timer = 55000;
            }
            else wave_timer -= diff;

        }

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_nightbane_azsc(Creature *_Creature)
{
    return new boss_nightbaneAI (_Creature);
}

void AddSC_boss_nightbane_azsc()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_nightbane_azsc";
    newscript->GetAI = GetAI_boss_nightbane_azsc;
    newscript->RegisterSelf();
}
