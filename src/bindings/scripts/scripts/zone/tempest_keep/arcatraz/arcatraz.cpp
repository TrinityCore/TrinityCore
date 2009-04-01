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
SDName: Arcatraz
SD%Complete: 60
SDComment: Warden Mellichar, event controller for Skyriss event. Millhouse Manastorm. TODO: make better combatAI for Millhouse.
SDCategory: Tempest Keep, The Arcatraz
EndScriptData */

/* ContentData
npc_millhouse_manastorm
npc_warden_mellichar
mob_zerekethvoidzone
EndContentData */

#include "precompiled.h"
#include "def_arcatraz.h"

/*#####
# npc_millhouse_manastorm
#####*/

#define SAY_INTRO_1                 -1552010
#define SAY_INTRO_2                 -1552011
#define SAY_WATER                   -1552012
#define SAY_BUFFS                   -1552013
#define SAY_DRINK                   -1552014
#define SAY_READY                   -1552015
#define SAY_KILL_1                  -1552016
#define SAY_KILL_2                  -1552017
#define SAY_PYRO                    -1552018
#define SAY_ICEBLOCK                -1552019
#define SAY_LOWHP                   -1552020
#define SAY_DEATH                   -1552021
#define SAY_COMPLETE                -1552022

#define SPELL_CONJURE_WATER         36879
#define SPELL_ARCANE_INTELLECT      36880
#define SPELL_ICE_ARMOR             36881

#define SPELL_ARCANE_MISSILES       33833
#define SPELL_CONE_OF_COLD          12611
#define SPELL_FIRE_BLAST            13341
#define SPELL_FIREBALL              14034
#define SPELL_FROSTBOLT             15497
#define SPELL_PYROBLAST             33975

struct TRINITY_DLL_DECL npc_millhouse_manastormAI : public ScriptedAI
{
    npc_millhouse_manastormAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    uint32 EventProgress_Timer;
    uint32 Phase;
    bool Init;
    bool LowHp;

    uint32 Pyroblast_Timer;
    uint32 Fireball_Timer;

    void Reset()
    {
        EventProgress_Timer = 2000;
        LowHp = false;
        Init = false;
        Phase = 1;

        Pyroblast_Timer = 1000;
        Fireball_Timer = 2500;

        if( pInstance )
        {
            if( pInstance->GetData(TYPE_WARDEN_2) == DONE )
                Init = true;

            if( pInstance->GetData(TYPE_HARBINGERSKYRISS) == DONE )
            {
                DoScriptText(SAY_COMPLETE, m_creature);
            }
        }
    }

    void AttackStart(Unit* who)
    {
        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who, 0.0f);

            if (!InCombat)
            {
                InCombat = true;
                Aggro(who);
            }

            //TODO: Make it so he moves when target out of range
            DoStartNoMovement(who);
        }
    }

    void Aggro(Unit *who)
    {
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
        case 0: DoScriptText(SAY_KILL_1, m_creature); break;
        case 1: DoScriptText(SAY_KILL_2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        /*for questId 10886 (heroic mode only)
        if( pInstance && pInstance->GetData(TYPE_HARBINGERSKYRISS) != DONE )
            ->FailQuest();*/
    }

    void UpdateAI(const uint32 diff)
    {
        if( !Init )
        {
            if( EventProgress_Timer < diff )
            {
                if( Phase < 8 )
                {
                    switch( Phase )
                    {
                        case 1:
                            DoScriptText(SAY_INTRO_1, m_creature);
                            EventProgress_Timer = 18000;
                            break;
                        case 2:
                            DoScriptText(SAY_INTRO_2, m_creature);
                            EventProgress_Timer = 18000;
                            break;
                        case 3:
                            DoScriptText(SAY_WATER, m_creature);
                            DoCast(m_creature,SPELL_CONJURE_WATER);
                            EventProgress_Timer = 7000;
                            break;
                        case 4:
                            DoScriptText(SAY_BUFFS, m_creature);
                            DoCast(m_creature,SPELL_ICE_ARMOR);
                            EventProgress_Timer = 7000;
                            break;
                        case 5:
                             DoScriptText(SAY_DRINK, m_creature);
                            DoCast(m_creature,SPELL_ARCANE_INTELLECT);
                            EventProgress_Timer = 7000;
                            break;
                        case 6:
                              DoScriptText(SAY_READY, m_creature);
                            EventProgress_Timer = 6000;
                            break;
                        case 7:
                            if( pInstance )
                                pInstance->SetData(TYPE_WARDEN_2,DONE);
                            Init = true;
                            break;
                    }
                    ++Phase;
                }
            } else EventProgress_Timer -= diff;
        }

        if( !UpdateVictim() )
            return;

        if( !LowHp && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 20) )
        {
            DoScriptText(SAY_LOWHP, m_creature);
            LowHp = true;
        }

        if( Pyroblast_Timer < diff )
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                return;

             DoScriptText(SAY_PYRO, m_creature);

            DoCast(m_creature->getVictim(),SPELL_PYROBLAST);
            Pyroblast_Timer = 40000;
        }else Pyroblast_Timer -=diff;

        if( Fireball_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_FIREBALL);
            Fireball_Timer = 4000;
        }else Fireball_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_millhouse_manastorm(Creature *_Creature)
{
    return new npc_millhouse_manastormAI (_Creature);
}

/*#####
# npc_warden_mellichar
#####*/

#define YELL_INTRO1         -1552023
#define YELL_INTRO2         -1552024
#define YELL_RELEASE1       -1552025
#define YELL_RELEASE2A      -1552026
#define YELL_RELEASE2B      -1552027
#define YELL_RELEASE3       -1552028
#define YELL_RELEASE4       -1552029
#define YELL_WELCOME        -1552030

//phase 2(acid mobs)
#define ENTRY_TRICKSTER     20905
#define ENTRY_PH_HUNTER     20906
//phase 3
#define ENTRY_MILLHOUSE     20977
//phase 4(acid mobs)
#define ENTRY_AKKIRIS       20908
#define ENTRY_SULFURON      20909
//phase 5(acid mobs)
#define ENTRY_TW_DRAK       20910
#define ENTRY_BL_DRAK       20911
//phase 6
#define ENTRY_SKYRISS       20912

//TARGET_SCRIPT
#define SPELL_TARGET_ALPHA  36856
#define SPELL_TARGET_BETA   36854
#define SPELL_TARGET_DELTA  36857
#define SPELL_TARGET_GAMMA  36858
#define SPELL_TARGET_OMEGA  36852
#define SPELL_BUBBLE_VISUAL 36849

struct TRINITY_DLL_DECL npc_warden_mellicharAI : public ScriptedAI
{
    npc_warden_mellicharAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    bool IsRunning;
    bool CanSpawn;

    uint32 EventProgress_Timer;
    uint32 Phase;

    void Reset()
    {
        IsRunning = false;
        CanSpawn = false;

        EventProgress_Timer = 22000;
        Phase = 1;

        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
        DoCast(m_creature,SPELL_TARGET_OMEGA);

        if( pInstance )
            pInstance->SetData(TYPE_HARBINGERSKYRISS,NOT_STARTED);
    }

    void AttackStart(Unit* who) { }

    void MoveInLineOfSight(Unit *who)
    {
        if( IsRunning )
            return;

        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessiblePlaceFor(m_creature) )
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            float attackRadius = m_creature->GetAttackDistance(who)/10;
            if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
                Aggro(who);
        }
    }

    void Aggro(Unit *who)
    {
        DoScriptText(YELL_INTRO1, m_creature);
        DoCast(m_creature,SPELL_BUBBLE_VISUAL);

        if( pInstance )
        {
            pInstance->SetData(TYPE_HARBINGERSKYRISS,IN_PROGRESS);
            if (GameObject* Sphere = GameObject::GetGameObject(*m_creature,pInstance->GetData64(DATA_SPHERE_SHIELD)))
                Sphere->SetGoState(1);
            IsRunning = true;
        }
    }

    bool CanProgress()
    {
        if( pInstance )
        {
            if( Phase == 7 && pInstance->GetData(TYPE_WARDEN_4) == DONE )
                return true;
            if( Phase == 6 && pInstance->GetData(TYPE_WARDEN_3) == DONE )
                return true;
            if( Phase == 5 && pInstance->GetData(TYPE_WARDEN_2) == DONE )
                return true;
            if( Phase == 4 )
                return true;
            if( Phase == 3 && pInstance->GetData(TYPE_WARDEN_1) == DONE )
                return true;
            if( Phase == 2 && pInstance->GetData(TYPE_HARBINGERSKYRISS) == IN_PROGRESS )
                return true;
            if( Phase == 1 && pInstance->GetData(TYPE_HARBINGERSKYRISS) == IN_PROGRESS )
                return true;
            return false;
        }
        return false;
    }

    void DoPrepareForPhase()
    {
        if( pInstance )
        {
            m_creature->InterruptNonMeleeSpells(true);
            m_creature->RemoveSpellsCausingAura(SPELL_AURA_DUMMY);

            switch( Phase )
            {
                case 2:
                    DoCast(m_creature,SPELL_TARGET_ALPHA);
                    pInstance->SetData(TYPE_WARDEN_1,IN_PROGRESS);
                    if (GameObject *Sphere = GameObject::GetGameObject(*m_creature,pInstance->GetData64(DATA_SPHERE_SHIELD)))
                        Sphere->SetGoState(1);
                    break;
                case 3:
                    DoCast(m_creature,SPELL_TARGET_BETA);
                    pInstance->SetData(TYPE_WARDEN_2,IN_PROGRESS);
                    break;
                case 5:
                    DoCast(m_creature,SPELL_TARGET_DELTA);
                    pInstance->SetData(TYPE_WARDEN_3,IN_PROGRESS);
                    break;
                case 6:
                    DoCast(m_creature,SPELL_TARGET_GAMMA);
                    pInstance->SetData(TYPE_WARDEN_4,IN_PROGRESS);
                    break;
                case 7:
                    pInstance->SetData(TYPE_WARDEN_5,IN_PROGRESS);
                    break;
            }
            CanSpawn = true;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( !IsRunning )
            return;

        if( EventProgress_Timer < diff )
        {
            if( pInstance )
            {
                if( pInstance->GetData(TYPE_HARBINGERSKYRISS) == FAIL )
                    Reset();
            }

            if( CanSpawn )
            {
                //continue beam omega pod, unless we are about to summon skyriss
                if( Phase != 7 )
                    DoCast(m_creature,SPELL_TARGET_OMEGA);

                switch( Phase )
                {
                    case 2:
                        switch( rand()%2 )
                        {
                            case 0: m_creature->SummonCreature(ENTRY_TRICKSTER,478.326,-148.505,42.56,3.19,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); break;
                            case 1: m_creature->SummonCreature(ENTRY_PH_HUNTER,478.326,-148.505,42.56,3.19,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); break;
                        }
                        break;
                    case 3:
                        m_creature->SummonCreature(ENTRY_MILLHOUSE,413.292,-148.378,42.56,6.27,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000);
                        break;
                    case 4:
                       DoScriptText(YELL_RELEASE2B, m_creature);
                        break;
                    case 5:
                        switch( rand()%2 )
                        {
                            case 0: m_creature->SummonCreature(ENTRY_AKKIRIS,420.179,-174.396,42.58,0.02,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); break;
                            case 1: m_creature->SummonCreature(ENTRY_SULFURON,420.179,-174.396,42.58,0.02,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); break;
                        }
                        break;
                    case 6:
                        switch( rand()%2 )
                        {
                            case 0: m_creature->SummonCreature(ENTRY_TW_DRAK,471.795,-174.58,42.58,3.06,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); break;
                            case 1: m_creature->SummonCreature(ENTRY_BL_DRAK,471.795,-174.58,42.58,3.06,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); break;
                        }
                        break;
                    case 7:
                        m_creature->SummonCreature(ENTRY_SKYRISS,445.763,-191.639,44.64,1.60,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000);
                        DoScriptText(YELL_WELCOME, m_creature);
                        break;
                }
                CanSpawn = false;
                ++Phase;
            }
            if( CanProgress() )
            {
                switch( Phase )
                {
                    case 1:
                        DoScriptText(YELL_INTRO2, m_creature);
                        EventProgress_Timer = 10000;
                        ++Phase;
                        break;
                    case 2:
                        DoScriptText(YELL_RELEASE1, m_creature);
                        DoPrepareForPhase();
                        EventProgress_Timer = 7000;
                        break;
                    case 3:
                        DoScriptText(YELL_RELEASE2A, m_creature);
                        DoPrepareForPhase();
                        EventProgress_Timer = 10000;
                        break;
                    case 4:
                        DoPrepareForPhase();
                        EventProgress_Timer = 15000;
                        break;
                    case 5:
                        DoScriptText(YELL_RELEASE3, m_creature);
                        DoPrepareForPhase();
                        EventProgress_Timer = 15000;
                        break;
                    case 6:
                        DoScriptText(YELL_RELEASE4, m_creature);
                        DoPrepareForPhase();
                        EventProgress_Timer = 15000;
                        break;
                    case 7:
                        DoPrepareForPhase();
                        EventProgress_Timer = 15000;
                        break;
                }
            }
        } else EventProgress_Timer -= diff;
    }
};
CreatureAI* GetAI_npc_warden_mellichar(Creature *_Creature)
{
    return new npc_warden_mellicharAI (_Creature);
}

/*#####
# mob_zerekethvoidzone (this script probably not needed in future -> `creature_template_addon`.`auras`='36120 0')
#####*/

#define SPELL_VOID_ZONE_DAMAGE 36120

struct TRINITY_DLL_DECL mob_zerekethvoidzoneAI : public ScriptedAI
{
    mob_zerekethvoidzoneAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS,0);
        m_creature->setFaction(16);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        DoCast(m_creature,SPELL_VOID_ZONE_DAMAGE);
    }

    void Aggro(Unit* who) {}
};
CreatureAI* GetAI_mob_zerekethvoidzoneAI(Creature *_Creature)
{
    return new mob_zerekethvoidzoneAI (_Creature);
}

void AddSC_arcatraz()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_millhouse_manastorm";
    newscript->GetAI = &GetAI_npc_millhouse_manastorm;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_warden_mellichar";
    newscript->GetAI = &GetAI_npc_warden_mellichar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_zerekethvoidzone";
    newscript->GetAI = &GetAI_mob_zerekethvoidzoneAI;
    newscript->RegisterSelf();
}

