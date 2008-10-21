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
SDName: Boss_Warlord_Kalithres
SD%Complete: 65
SDComment: Contains workarounds regarding warlord's rage spells not acting as expected. Both scripts here require review and fine tuning.
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

#include "precompiled.h"
#include "def_steam_vault.h"

#define SAY_INTRO           "You deem yourselves worthy simply because you bested my guards? Our work here will not be compromised!"
#define SOUND_INTRO         10390

#define SAY_REGEN           "This is not nearly over..."
#define SOUND_REGEN         10391

#define SAY_AGGRO1          "Your head will roll!"
#define SOUND_AGGRO1        10392
#define SAY_AGGRO2          "I despise all of your kind!"
#define SOUND_AGGRO2        10393
#define SAY_AGGRO3          "Ba'ahntha sol'dorei!"
#define SOUND_AGGRO3        10394

#define SAY_SLAY1           "Scram, surface filth!"
#define SOUND_SLAY1         10395
#define SAY_SLAY2           "Ah ha ha ha ha ha ha!"
#define SOUND_SLAY2         10396

#define SAY_DEATH           "For her Excellency... for... Vashj!"
#define SOUND_DEATH         10397

#define SPELL_SPELL_REFLECTION      31534
#define SPELL_IMPALE                39061
#define SPELL_WARLORDS_RAGE         37081
#define SPELL_WARLORDS_RAGE_NAGA    31543

#define SPELL_WARLORDS_RAGE_PROC    36453

struct TRINITY_DLL_DECL mob_naga_distillerAI : public ScriptedAI
{
    mob_naga_distillerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        //hack, due to really weird spell behaviour :(
        if( pInstance )
            if( pInstance->GetData(TYPE_DISTILLER) == IN_PROGRESS )
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    void Aggro(Unit *who) { }

    void StartRageGen(Unit *caster)
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        DoCast(m_creature,SPELL_WARLORDS_RAGE_NAGA,true);
        if( pInstance ) pInstance->SetData(TYPE_DISTILLER,IN_PROGRESS);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if( m_creature->GetHealth() <= damage )
            if( pInstance ) pInstance->SetData(TYPE_DISTILLER,DONE);
    }
};

struct TRINITY_DLL_DECL boss_warlord_kalithreshAI : public ScriptedAI
{
    boss_warlord_kalithreshAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 Reflection_Timer;
    uint32 Impale_Timer;
    uint32 Rage_Timer;
    bool CanRage;

    void Reset()
    {
        Reflection_Timer = 10000;
        Impale_Timer = 30000;
        Rage_Timer = 45000;
        CanRage = false;

        if( pInstance ) pInstance->SetData(TYPE_WARLORD_KALITHRESH, NOT_STARTED);
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO1);
                break;
            case 1:
                DoYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO2);
                break;
            case 2:
                DoYell(SAY_AGGRO3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO3);
                break;
        }

        if( pInstance ) pInstance->SetData(TYPE_WARLORD_KALITHRESH, IN_PROGRESS);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(victim, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(victim, SOUND_SLAY2);
                break;
        }
    }

    Creature* SelectCreatureInGrid(uint32 entry, float range)
    {
        Creature* pCreature = NULL;

        CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
        Cell cell(pair);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck creature_check(*m_creature, entry, true, range);
        Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(pCreature, creature_check);

        TypeContainerVisitor<Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck>, GridTypeMapContainer> creature_searcher(searcher);

        CellLock<GridReadGuard> cell_lock(cell, pair);
        cell_lock->Visit(cell_lock, creature_searcher,*(m_creature->GetMap()));

        return pCreature;
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        //hack :(
        if( spell->Id == SPELL_WARLORDS_RAGE_PROC )
            if( pInstance )
                if( pInstance->GetData(TYPE_DISTILLER) == DONE )
                    m_creature->RemoveAurasDueToSpell(SPELL_WARLORDS_RAGE_PROC);
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);

        if( pInstance ) pInstance->SetData(TYPE_WARLORD_KALITHRESH, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( Rage_Timer < diff )
        {
            Creature* distiller = SelectCreatureInGrid(17954, 100);
            if( distiller )
            {
                DoYell(SAY_REGEN, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_REGEN);
                DoCast(m_creature,SPELL_WARLORDS_RAGE);
                ((mob_naga_distillerAI*)distiller->AI())->StartRageGen(m_creature);
            }
            Rage_Timer = 45000;
        }else Rage_Timer -= diff;

        //Reflection_Timer
        if( Reflection_Timer < diff )
        {
            DoCast(m_creature, SPELL_SPELL_REFLECTION);
            Reflection_Timer = 20000+rand()%5000;
        }else Reflection_Timer -= diff;

        //Impale_Timer
        if( Impale_Timer < diff )
        {
            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_IMPALE);

            Impale_Timer = 7500+rand()%5000;
        }else Impale_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_naga_distiller(Creature *_Creature)
{
    return new mob_naga_distillerAI (_Creature);
}

CreatureAI* GetAI_boss_warlord_kalithresh(Creature *_Creature)
{
    return new boss_warlord_kalithreshAI (_Creature);
}

void AddSC_boss_warlord_kalithresh()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mob_naga_distiller";
    newscript->GetAI = GetAI_mob_naga_distiller;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_warlord_kalithresh";
    newscript->GetAI = GetAI_boss_warlord_kalithresh;
    m_scripts[nrscripts++] = newscript;
}
