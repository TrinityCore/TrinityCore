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
SDName: Boss_Hydromancer_Thespia
SD%Complete: 80
SDComment: Normal/heroic mode: to be tested. Needs additional adjustments (when instance script is adjusted)
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

/* ContentData
boss_hydromancer_thespia
mob_coilfang_waterelemental
EndContentData */

#include "precompiled.h"
#include "def_steam_vault.h"

#define SAY_SUMMON                  "Surge forth my pets!"
#define SOUND_SUMMON                10360

#define SAY_AGGRO_1                 "The depths will consume you!"
#define SOUND_AGGRO_1               10361
#define SAY_AGGRO_2                 "Meet your doom, surface dwellers!"
#define SOUND_AGGRO_2               10362
#define SAY_AGGRO_3                 "You will drown in blood!"
#define SOUND_AGGRO_3               10363

#define SAY_SLAY_1                  "To the depths of oblivion with you!"
#define SOUND_SLAY_1                10364
#define SAY_SLAY_2                  "For my lady and master!"
#define SOUND_SLAY_2                10365

#define SAY_DEAD                    "Our matron will be.. the end of.. you.."
#define SOUND_DEAD                  10366

#define SPELL_LIGHTNING_CLOUD       25033
#define SPELL_LUNG_BURST            31481
#define SPELL_ENVELOPING_WINDS      31718

struct TRINITY_DLL_DECL boss_thespiaAI : public ScriptedAI
{
    boss_thespiaAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;
    bool HeroicMode;

    uint32 LightningCloud_Timer;
    uint32 LungBurst_Timer;
    uint32 EnvelopingWinds_Timer;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();

        LightningCloud_Timer = 28000;
        LungBurst_Timer = 7000;
        EnvelopingWinds_Timer = 9000;

        if( pInstance ) pInstance->SetData(TYPE_HYDROMANCER_THESPIA, NOT_STARTED);
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEAD, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEAD);

        if( pInstance ) pInstance->SetData(TYPE_HYDROMANCER_THESPIA, DONE);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY_1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_SLAY_1);
                break;
            case 1:
                DoYell(SAY_SLAY_2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_SLAY_2);
                break;
        }
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_AGGRO_1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_1);
                break;
            case 1:
                DoYell(SAY_AGGRO_2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_2);
                break;
            case 2:
                DoYell(SAY_AGGRO_3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_3);
                break;
        }

        if( pInstance ) pInstance->SetData(TYPE_HYDROMANCER_THESPIA, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //LightningCloud_Timer
        if( LightningCloud_Timer < diff )
        {
            //cast twice in Heroic mode
            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target, SPELL_LIGHTNING_CLOUD);
            if( HeroicMode )
                if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                    DoCast(target, SPELL_LIGHTNING_CLOUD);
            LightningCloud_Timer = 28000;
        }else LightningCloud_Timer -=diff;

        //LungBurst_Timer
        if( LungBurst_Timer < diff )
        {
            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target, SPELL_LUNG_BURST);
            LungBurst_Timer = 10000+rand()%5000;
        }else LungBurst_Timer -=diff;

        //EnvelopingWinds_Timer
        if( EnvelopingWinds_Timer < diff )
        {
            //cast twice in Heroic mode
            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target, SPELL_ENVELOPING_WINDS);
            if( HeroicMode )
                if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
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
    mob_coilfang_waterelementalAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool HeroicMode;
    uint32 WaterBoltVolley_Timer;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();
        WaterBoltVolley_Timer = 3000+rand()%3000;
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( WaterBoltVolley_Timer < diff )
        {
            if( HeroicMode ) DoCast(m_creature,H_SPELL_WATER_BOLT_VOLLEY);
            else DoCast(m_creature,SPELL_WATER_BOLT_VOLLEY);

            WaterBoltVolley_Timer = 10000+rand()%5000;
        }else WaterBoltVolley_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_thespiaAI(Creature *_Creature)
{
    return new boss_thespiaAI (_Creature);
}

CreatureAI* GetAI_mob_coilfang_waterelementalAI(Creature *_Creature)
{
    return new mob_coilfang_waterelementalAI (_Creature);
}

void AddSC_boss_hydromancer_thespia()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_hydromancer_thespia";
    newscript->GetAI = GetAI_boss_thespiaAI;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_coilfang_waterelemental";
    newscript->GetAI = GetAI_mob_coilfang_waterelementalAI;
    m_scripts[nrscripts++] = newscript;
}
