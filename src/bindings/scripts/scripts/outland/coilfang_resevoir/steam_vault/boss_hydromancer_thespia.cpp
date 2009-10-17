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
SDName: Boss_Hydromancer_Thespia
SD%Complete: 80
SDComment: Needs additional adjustments (when instance script is adjusted)
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

/* ContentData
boss_hydromancer_thespia
mob_coilfang_waterelemental
EndContentData */

#include "precompiled.h"
#include "def_steam_vault.h"

#define SAY_SUMMON                  -1545000
#define SAY_AGGRO_1                 -1545001
#define SAY_AGGRO_2                 -1545002
#define SAY_AGGRO_3                 -1545003
#define SAY_SLAY_1                  -1545004
#define SAY_SLAY_2                  -1545005
#define SAY_DEAD                    -1545006

#define SPELL_LIGHTNING_CLOUD       25033
#define SPELL_LUNG_BURST            31481
#define SPELL_ENVELOPING_WINDS      31718

struct TRINITY_DLL_DECL boss_thespiaAI : public ScriptedAI
{
    boss_thespiaAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance *pInstance;
    bool HeroicMode;

    uint32 LightningCloud_Timer;
    uint32 LungBurst_Timer;
    uint32 EnvelopingWinds_Timer;

    void Reset()
    {
        LightningCloud_Timer = 15000;
        LungBurst_Timer = 7000;
        EnvelopingWinds_Timer = 9000;

        if (pInstance)
            pInstance->SetData(TYPE_HYDROMANCER_THESPIA, NOT_STARTED);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEAD, m_creature);

        if (pInstance)
            pInstance->SetData(TYPE_HYDROMANCER_THESPIA, DONE);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature); break;
        }
    }

    void EnterCombat(Unit *who)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_AGGRO_1, m_creature); break;
            case 1: DoScriptText(SAY_AGGRO_2, m_creature); break;
            case 2: DoScriptText(SAY_AGGRO_3, m_creature); break;
        }

        if (pInstance)
            pInstance->SetData(TYPE_HYDROMANCER_THESPIA, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //LightningCloud_Timer
        if (LightningCloud_Timer < diff)
        {
            //cast twice in Heroic mode
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target, SPELL_LIGHTNING_CLOUD);
            if (HeroicMode)
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(target, SPELL_LIGHTNING_CLOUD);
            LightningCloud_Timer = 15000+rand()%10000;
        }else LightningCloud_Timer -=diff;

        //LungBurst_Timer
        if (LungBurst_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target, SPELL_LUNG_BURST);
            LungBurst_Timer = 7000+rand()%5000;
        }else LungBurst_Timer -=diff;

        //EnvelopingWinds_Timer
        if (EnvelopingWinds_Timer < diff)
        {
            //cast twice in Heroic mode
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target, SPELL_ENVELOPING_WINDS);
            if (HeroicMode)
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(target, SPELL_ENVELOPING_WINDS);
            EnvelopingWinds_Timer = 10000+rand()%5000;
        }else EnvelopingWinds_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

#define SPELL_WATER_BOLT_VOLLEY     34449
#define H_SPELL_WATER_BOLT_VOLLEY   37924

struct TRINITY_DLL_DECL mob_coilfang_waterelementalAI : public ScriptedAI
{
    mob_coilfang_waterelementalAI(Creature *c) : ScriptedAI(c) {}

    bool HeroicMode;
    uint32 WaterBoltVolley_Timer;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();
        WaterBoltVolley_Timer = 3000+rand()%3000;
    }

    void EnterCombat(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (WaterBoltVolley_Timer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_WATER_BOLT_VOLLEY, H_SPELL_WATER_BOLT_VOLLEY));
            WaterBoltVolley_Timer = 7000+rand()%5000;
        }else WaterBoltVolley_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_thespiaAI(Creature* pCreature)
{
    return new boss_thespiaAI (pCreature);
}

CreatureAI* GetAI_mob_coilfang_waterelementalAI(Creature* pCreature)
{
    return new mob_coilfang_waterelementalAI (pCreature);
}

void AddSC_boss_hydromancer_thespia()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_hydromancer_thespia";
    newscript->GetAI = &GetAI_boss_thespiaAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_coilfang_waterelemental";
    newscript->GetAI = &GetAI_mob_coilfang_waterelementalAI;
    newscript->RegisterSelf();
}

