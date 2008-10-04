/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Darkweaver_Syth
SD%Complete: 85
SDComment: Shock spells/times need more work. Heroic not implemented.
SDCategory: Auchindoun, Sethekk Halls
EndScriptData */

#include "precompiled.h"

#define SAY_SUMMON                  "I have pets..<squawk>..of my own!"
#define SOUND_SUMMON                10502

#define SAY_AGGRO_1                 "Hrrmm.. Time to.. hrrm.. make my move."
#define SOUND_AGGRO_1               10503
#define SAY_AGGRO_2                 "Nice pets..hrm.. Yes! <squawking>"
#define SOUND_AGGRO_2               10504
#define SAY_AGGRO_3                 "Nice pets have.. weapons. No so..<squawk>..nice."
#define SOUND_AGGRO_3               10505

#define SAY_SLAY_1                  "Death.. meeting life is.. <squawking>"
#define SOUND_SLAY_1                10506
#define SAY_SLAY_2                  "Uhn.. Be free..<squawk>"
#define SOUND_SLAY_2                10507

#define SAY_DEATH                   "No more life..hrm. No more pain. <squawks weakly>"
#define SOUND_DEATH                 10508

#define SPELL_FROST_SHOCK           37865
#define SPELL_FLAME_SHOCK           34354
#define SPELL_SHADOW_SHOCK          30138
#define SPELL_ARCANE_SHOCK          37132

#define SPELL_CHAIN_LIGHTNING       39945

#define SPELL_SUMMON_SYTH_FIRE      33537                   // Spawns 19203
#define SPELL_SUMMON_SYTH_ARCANE    33538                   // Spawns 19205
#define SPELL_SUMMON_SYTH_FROST     33539                   // Spawns 19204
#define SPELL_SUMMON_SYTH_SHADOW    33540                   // Spawns 19206

#define SPELL_FLAME_BUFFET          33526
#define H_SPELL_FLAME_BUFFET        38141
#define SPELL_ARCANE_BUFFET         33527
#define H_SPELL_ARCANE_BUFFET       38138
#define SPELL_FROST_BUFFET          33528
#define H_SPELL_FROST_BUFFET        38142
#define SPELL_SHADOW_BUFFET         33529
#define H_SPELL_SHADOW_BUFFET       38143

struct MANGOS_DLL_DECL boss_darkweaver_sythAI : public ScriptedAI
{
    boss_darkweaver_sythAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 flameshock_timer;
    uint32 arcaneshock_timer;
    uint32 frostshock_timer;
    uint32 shadowshock_timer;
    uint32 chainlightning_timer;

    bool summon90;
    bool summon50;
    bool summon10;

    void Reset()
    {
        flameshock_timer = 2000;
        arcaneshock_timer = 4000;
        frostshock_timer = 6000;
        shadowshock_timer = 8000;
        chainlightning_timer = 15000;

        summon90 = false;
        summon50 = false;
        summon10 = false;
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
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

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

    void JustSummoned(Creature *summoned)
    {
        if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
            summoned->AI()->AttackStart(target);

    }

    void SythSummoning()
    {
        DoYell(SAY_SUMMON, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_SUMMON);

        if( m_creature->IsNonMeleeSpellCasted(false) )
            m_creature->InterruptNonMeleeSpells(false);

        DoCast(m_creature,SPELL_SUMMON_SYTH_ARCANE,true);   //front
        DoCast(m_creature,SPELL_SUMMON_SYTH_FIRE,true);     //back
        DoCast(m_creature,SPELL_SUMMON_SYTH_FROST,true);    //left
        DoCast(m_creature,SPELL_SUMMON_SYTH_SHADOW,true);   //right
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 90) && !summon90)
        {
            SythSummoning();
            summon90 = true;
        }

        if( ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 50) && !summon50)
        {
            SythSummoning();
            summon50 = true;
        }

        if( ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 10) && !summon10)
        {
            SythSummoning();
            summon10 = true;
        }

        if( flameshock_timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_FLAME_SHOCK);

            flameshock_timer = 10000 + rand()%5000;
        }else flameshock_timer -= diff;

        if( arcaneshock_timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_ARCANE_SHOCK);

            arcaneshock_timer = 10000 + rand()%5000;
        }else arcaneshock_timer -= diff;

        if( frostshock_timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_FROST_SHOCK);

            frostshock_timer = 10000 + rand()%5000;
        }else frostshock_timer -= diff;

        if( shadowshock_timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_SHADOW_SHOCK);

            shadowshock_timer = 10000 + rand()%5000;
        }else shadowshock_timer -= diff;

        if( chainlightning_timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_CHAIN_LIGHTNING);

            chainlightning_timer = 25000;
        }else chainlightning_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_darkweaver_syth(Creature *_Creature)
{
    return new boss_darkweaver_sythAI (_Creature);
}

/* ELEMENTALS */

struct MANGOS_DLL_DECL mob_syth_fireAI : public ScriptedAI
{
    mob_syth_fireAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 flameshock_timer;
    uint32 flamebuffet_timer;

    void Reset()
    {
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
        flameshock_timer = 2500;
        flamebuffet_timer = 5000;
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(flameshock_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_FLAME_SHOCK);

            flameshock_timer = 5000;
        }else flameshock_timer -= diff;

        if(flamebuffet_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_FLAME_BUFFET);

            flamebuffet_timer = 5000;
        }else flamebuffet_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_syth_fire(Creature *_Creature)
{
    return new mob_syth_fireAI (_Creature);
}

struct MANGOS_DLL_DECL mob_syth_arcaneAI : public ScriptedAI
{
    mob_syth_arcaneAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 arcaneshock_timer;
    uint32 arcanebuffet_timer;

    void Reset()
    {
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
        arcaneshock_timer = 2500;
        arcanebuffet_timer = 5000;
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(arcaneshock_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_ARCANE_SHOCK);

            arcaneshock_timer = 5000;
        }else arcaneshock_timer -= diff;

        if(arcanebuffet_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_ARCANE_BUFFET);

            arcanebuffet_timer = 5000;
        }else arcanebuffet_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_syth_arcane(Creature *_Creature)
{
    return new mob_syth_arcaneAI (_Creature);
}

struct MANGOS_DLL_DECL mob_syth_frostAI : public ScriptedAI
{
    mob_syth_frostAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 frostshock_timer;
    uint32 frostbuffet_timer;

    void Reset()
    {
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
        frostshock_timer = 2500;
        frostbuffet_timer = 5000;
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(frostshock_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_FROST_SHOCK);

            frostshock_timer = 5000;
        }else frostshock_timer -= diff;

        if(frostbuffet_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_FROST_BUFFET);

            frostbuffet_timer = 5000;
        }else frostbuffet_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_syth_frost(Creature *_Creature)
{
    return new mob_syth_frostAI (_Creature);
}

struct MANGOS_DLL_DECL mob_syth_shadowAI : public ScriptedAI
{
    mob_syth_shadowAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 shadowshock_timer;
    uint32 shadowbuffet_timer;

    void Reset()
    {
        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
        shadowshock_timer = 2500;
        shadowbuffet_timer = 5000;
    }

    void Aggro(Unit *who) { }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(shadowshock_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_SHADOW_SHOCK);

            shadowshock_timer = 5000;
        }else shadowshock_timer -= diff;

        if(shadowbuffet_timer < diff)
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_SHADOW_BUFFET);

            shadowbuffet_timer = 5000;
        }else shadowbuffet_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_syth_shadow(Creature *_Creature)
{
    return new mob_syth_shadowAI (_Creature);
}

void AddSC_boss_darkweaver_syth()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_darkweaver_syth";
    newscript->GetAI = GetAI_boss_darkweaver_syth;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_syth_fire";
    newscript->GetAI = GetAI_mob_syth_arcane;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_syth_arcane";
    newscript->GetAI = GetAI_mob_syth_arcane;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_syth_frost";
    newscript->GetAI = GetAI_mob_syth_frost;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_syth_shadow";
    newscript->GetAI = GetAI_mob_syth_shadow;
    m_scripts[nrscripts++] = newscript;
}
