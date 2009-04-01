/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Sulfuron_Harbringer
SD%Complete: 80
SDComment: Adds NYI
SDCategory: Molten Core
EndScriptData */

#include "precompiled.h"
#include "def_molten_core.h"

#define SPELL_DARKSTRIKE            19777
#define SPELL_DEMORALIZINGSHOUT     19778
#define SPELL_INSPIRE               19779
#define SPELL_KNOCKDOWN             19780
#define SPELL_FLAMESPEAR            19781

//Adds Spells
#define SPELL_HEAL                  19775
#define SPELL_SHADOWWORDPAIN        19776
#define SPELL_IMMOLATE              20294

struct TRINITY_DLL_DECL boss_sulfuronAI : public ScriptedAI
{
    boss_sulfuronAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    uint32 Darkstrike_Timer;
    uint32 DemoralizingShout_Timer;
    uint32 Inspire_Timer;
    uint32 Knockdown_Timer;
    uint32 Flamespear_Timer;
    ScriptedInstance *pInstance;

    void Reset()
    {
        Darkstrike_Timer=10000;                             //These times are probably wrong
        DemoralizingShout_Timer = 15000;
        Inspire_Timer = 13000;
        Knockdown_Timer = 6000;
        Flamespear_Timer = 2000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //DemoralizingShout_Timer
        if (DemoralizingShout_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_DEMORALIZINGSHOUT);
            DemoralizingShout_Timer = 15000 + rand()%5000;
        }else DemoralizingShout_Timer -= diff;

        //Inspire_Timer
        if (Inspire_Timer < diff)
        {
            Creature* target = NULL;
            std::list<Creature*> pList = DoFindFriendlyMissingBuff(45.0f,SPELL_INSPIRE);
            if (!pList.empty())
            {
                std::list<Creature*>::iterator i = pList.begin();
                advance(i, (rand()%pList.size()));
                target = (*i);
            }

            if (target)
                DoCast(target,SPELL_INSPIRE);

            DoCast(m_creature,SPELL_INSPIRE);

            Inspire_Timer = 20000 + rand()%6000;
        }else Inspire_Timer -= diff;

        //Knockdown_Timer
        if (Knockdown_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_KNOCKDOWN);
            Knockdown_Timer = 12000 + rand()%3000;
        }else Knockdown_Timer -= diff;

        //Flamespear_Timer
        if (Flamespear_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_FLAMESPEAR);

            Flamespear_Timer = 12000 + rand()%4000;
        }else Flamespear_Timer -= diff;

        //DarkStrike_Timer
        if (Darkstrike_Timer < diff)
        {
            DoCast(m_creature, SPELL_DARKSTRIKE);
            Darkstrike_Timer = 15000 + rand()%3000;
        }else Darkstrike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_flamewaker_priestAI : public ScriptedAI
{
    mob_flamewaker_priestAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    uint32 Heal_Timer;
    uint32 ShadowWordPain_Timer;
    uint32 Immolate_Timer;

    ScriptedInstance *pInstance;

    void Reset()
    {
        Heal_Timer = 15000+rand()%15000;
        ShadowWordPain_Timer = 2000;
        Immolate_Timer = 8000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Casting Heal to Sulfuron or other Guards.
        if(Heal_Timer < diff)
        {
            Unit* pUnit = DoSelectLowestHpFriendly(60.0f, 1);
            if (!pUnit)
                return;

            DoCast(pUnit, SPELL_HEAL);

            Heal_Timer = 15000+rand()%5000;
        }else Heal_Timer -= diff;

        //ShadowWordPain_Timer
        if (ShadowWordPain_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_SHADOWWORDPAIN);

            ShadowWordPain_Timer = 18000+rand()%8000;
        }else ShadowWordPain_Timer -= diff;

        //Immolate_Timer
        if (Immolate_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_IMMOLATE);

            Immolate_Timer = 15000+rand()%10000;
        }else Immolate_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_sulfuron(Creature *_Creature)
{
    return new boss_sulfuronAI (_Creature);
}

CreatureAI* GetAI_mob_flamewaker_priest(Creature *_Creature)
{
    return new mob_flamewaker_priestAI (_Creature);
}

void AddSC_boss_sulfuron()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_sulfuron";
    newscript->GetAI = &GetAI_boss_sulfuron;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_flamewaker_priest";
    newscript->GetAI = &GetAI_mob_flamewaker_priest;
    newscript->RegisterSelf();
}

