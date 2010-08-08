/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "arcatraz.h"

/*#####
# npc_millhouse_manastorm
#####*/

enum eMillhouseSays
{
    SAY_INTRO_1                = -1552010,
    SAY_INTRO_2                = -1552011,
    SAY_WATER                  = -1552012,
    SAY_BUFFS                  = -1552013,
    SAY_DRINK                  = -1552014,
    SAY_READY                  = -1552015,
    SAY_KILL_1                 = -1552016,
    SAY_KILL_2                 = -1552017,
    SAY_PYRO                   = -1552018,
    SAY_ICEBLOCK               = -1552019,
    SAY_LOWHP                  = -1552020,
    SAY_DEATH                  = -1552021,
    SAY_COMPLETE               = -1552022,
};

enum eMillhouseSpells
{
    SPELL_CONJURE_WATER        = 36879,
    SPELL_ARCANE_INTELLECT     = 36880,
    SPELL_ICE_ARMOR            = 36881,
    SPELL_ARCANE_MISSILES      = 33833,
    SPELL_CONE_OF_COLD         = 12611,
    SPELL_FIRE_BLAST           = 13341,
    SPELL_FIREBALL             = 14034,
    SPELL_FROSTBOLT            = 15497,
    SPELL_PYROBLAST            = 33975,
};

class npc_millhouse_manastorm : public CreatureScript
{
    public:

        npc_millhouse_manastorm()
            : CreatureScript("npc_millhouse_manastorm")
        {
        }
        struct npc_millhouse_manastormAI : public ScriptedAI
        {
            npc_millhouse_manastormAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }
            
            InstanceScript* pInstance;

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

                if (pInstance)
                {
                    if (pInstance->GetData(TYPE_WARDEN_2) == DONE)
                        Init = true;

                    if (pInstance->GetData(TYPE_HARBINGERSKYRISS) == DONE)                    
                        DoScriptText(SAY_COMPLETE, me);                    
                }
            }
            
            void AttackStart(Unit* pWho)
            {
                if (me->Attack(pWho, true))
                {
                    me->AddThreat(pWho, 0.0f);
                    me->SetInCombatWith(pWho);
                    pWho->SetInCombatWith(me);
                    me->GetMotionMaster()->MoveChase(pWho, 25.0f);
                }
            }

            void EnterCombat(Unit * /*who*/){}

            void KilledUnit(Unit * /*victim*/)
            {
                DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), me);
            }

            void JustDied(Unit * /*victim*/)
            {
                DoScriptText(SAY_DEATH, me);

                /*for questId 10886 (heroic mode only)
                if (pInstance && pInstance->GetData(TYPE_HARBINGERSKYRISS) != DONE)
                ->FailQuest();*/
            }
            
            void UpdateAI(const uint32 diff)
            {
                if (!Init)
                {
                    if (EventProgress_Timer <= diff)
                    {
                        if (Phase < 8)
                        {
                            switch(Phase)
                            {
                            case 1:
                                DoScriptText(SAY_INTRO_1, me);
                                EventProgress_Timer = 18000;
                                break;
                            case 2:
                                DoScriptText(SAY_INTRO_2, me);
                                EventProgress_Timer = 18000;
                                break;
                            case 3:
                                DoScriptText(SAY_WATER, me);
                                DoCast(me, SPELL_CONJURE_WATER);
                                EventProgress_Timer = 7000;
                                break;
                            case 4:
                                DoScriptText(SAY_BUFFS, me);
                                DoCast(me, SPELL_ICE_ARMOR);
                                EventProgress_Timer = 7000;
                                break;
                            case 5:
                                DoScriptText(SAY_DRINK, me);
                                DoCast(me, SPELL_ARCANE_INTELLECT);
                                EventProgress_Timer = 7000;
                                break;
                            case 6:
                                DoScriptText(SAY_READY, me);
                                EventProgress_Timer = 6000;
                                break;
                            case 7:
                                if (pInstance)
                                    pInstance->SetData(TYPE_WARDEN_2,DONE);
                                Init = true;
                                break;
                            }
                            ++Phase;
                        }
                    } 
                    else 
                        EventProgress_Timer -= diff;
                }

                if (!UpdateVictim())            
                    return;
                if (!LowHp && ((me->GetHealth()*100 / me->GetMaxHealth()) < 20))
                {
                    DoScriptText(SAY_LOWHP, me);
                    LowHp = true;
                }

                if (Pyroblast_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        return;

                    DoScriptText(SAY_PYRO, me);

                    DoCast(me->getVictim(), SPELL_PYROBLAST);
                    Pyroblast_Timer = 40000;
                }
                else
                    Pyroblast_Timer -=diff;

                if (Fireball_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FIREBALL);
                    Fireball_Timer = 4000;
                }
                else
                    Fireball_Timer -=diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* OnGetAI(Creature* creature) const
        {
            return new npc_millhouse_manastormAI(creature);
        }
};
/*#####
# npc_warden_mellichar
#####*/

enum eWardenSays
{
    YELL_INTRO1         = -1552023,
    YELL_INTRO2         = -1552024,
    YELL_RELEASE1       = -1552025,
    YELL_RELEASE2A      = -1552026,
    YELL_RELEASE2B      = -1552027,
    YELL_RELEASE3       = -1552028,
    YELL_RELEASE4       = -1552029,
    YELL_WELCOME        = -1552030,
};

enum eWardenUnits
{
    //phase 2(acid mobs)
    ENTRY_TRICKSTER    = 20905,
    ENTRY_PH_HUNTER    = 20906,
    //phase 3
    ENTRY_MILLHOUSE    = 20977,
    //phase 4(acid mobs)
    ENTRY_AKKIRIS      = 20908,
    ENTRY_SULFURON     = 20909,
    //phase 5(acid mobs)
    ENTRY_TW_DRAK      = 20910,
    ENTRY_BL_DRAK      = 20911,
    //phase 6
    ENTRY_SKYRISS      = 20912,
};

enum eWardenSpells
{
    //TARGET_SCRIPT
    SPELL_TARGET_ALPHA  = 36856,
    SPELL_TARGET_BETA   = 36854,
    SPELL_TARGET_DELTA  = 36857,
    SPELL_TARGET_GAMMA  = 36858,
    SPELL_TARGET_OMEGA  = 36852,
    SPELL_BUBBLE_VISUAL = 36849,
};

class npc_warden_mellichar : public CreatureScript
{
    public:

        npc_warden_mellichar()
            : CreatureScript("npc_warden_mellichar")
        {
        }
        struct npc_warden_mellicharAI : public ScriptedAI
        {
            npc_warden_mellicharAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;

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

                me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                DoCast(me, SPELL_TARGET_OMEGA);

                if (pInstance)
                    pInstance->SetData(TYPE_HARBINGERSKYRISS,NOT_STARTED);
            }

            void AttackStart(Unit* /*who*/) {}

            void MoveInLineOfSight(Unit *who)
            {
                if (IsRunning)
                    return;

                if (!me->getVictim() && who->isTargetableForAttack() && (me->IsHostileTo(who)) && who->isInAccessiblePlaceFor(me))
                {
                    if (!me->canFly() && me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                        return;
                    if (who->GetTypeId() != TYPEID_PLAYER)
                        return;

                    float attackRadius = me->GetAttackDistance(who)/10;
                    if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                        EnterCombat(who);
                }
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoScriptText(YELL_INTRO1, me);
                DoCast(me, SPELL_BUBBLE_VISUAL);

                if (pInstance)
                {
                    pInstance->SetData(TYPE_HARBINGERSKYRISS,IN_PROGRESS);
                    pInstance->HandleGameObject(pInstance->GetData64(DATA_SPHERE_SHIELD), false);
                    IsRunning = true;
                }
            }

            bool CanProgress()
            {
                if (pInstance)
                {
                    if (Phase == 7 && pInstance->GetData(TYPE_WARDEN_4) == DONE)
                        return true;
                    if (Phase == 6 && pInstance->GetData(TYPE_WARDEN_3) == DONE)
                        return true;
                    if (Phase == 5 && pInstance->GetData(TYPE_WARDEN_2) == DONE)
                        return true;
                    if (Phase == 4)
                        return true;
                    if (Phase == 3 && pInstance->GetData(TYPE_WARDEN_1) == DONE)
                        return true;
                    if (Phase == 2 && pInstance->GetData(TYPE_HARBINGERSKYRISS) == IN_PROGRESS)
                        return true;
                    if (Phase == 1 && pInstance->GetData(TYPE_HARBINGERSKYRISS) == IN_PROGRESS)
                        return true;
                    return false;
                }
                return false;
            }

            void DoPrepareForPhase()
            {
                if (pInstance)
                {
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAurasByType(SPELL_AURA_DUMMY);

                    switch(Phase)
                    {
                    case 2:
                        DoCast(me, SPELL_TARGET_ALPHA);
                        pInstance->SetData(TYPE_WARDEN_1,IN_PROGRESS);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_SPHERE_SHIELD), false);
                        break;
                    case 3:
                        DoCast(me, SPELL_TARGET_BETA);
                        pInstance->SetData(TYPE_WARDEN_2,IN_PROGRESS);
                        break;
                    case 5:
                        DoCast(me, SPELL_TARGET_DELTA);
                        pInstance->SetData(TYPE_WARDEN_3,IN_PROGRESS);
                        break;
                    case 6:
                        DoCast(me, SPELL_TARGET_GAMMA);
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
                if (!IsRunning)
                    return;

                if (EventProgress_Timer <= diff)
                {
                    if (pInstance)
                    {
                        if (pInstance->GetData(TYPE_HARBINGERSKYRISS) == FAIL)
                        {
                            Reset();
                            return;
                        }
                    }

                    if (CanSpawn)
                    {
                        //continue beam omega pod, unless we are about to summon skyriss
                        if (Phase != 7)
                            DoCast(me, SPELL_TARGET_OMEGA);

                        switch(Phase)
                        {
                        case 2:
                            switch (urand(0,1))
                            {
                            case 0: 
                                me->SummonCreature(ENTRY_TRICKSTER,478.326,-148.505,42.56,3.19,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); 
                                break;
                            case 1:
                                me->SummonCreature(ENTRY_PH_HUNTER,478.326,-148.505,42.56,3.19,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); 
                                break;
                            }
                            break;
                        case 3:
                            me->SummonCreature(ENTRY_MILLHOUSE,413.292,-148.378,42.56,6.27,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000);
                            break;
                        case 4:
                            DoScriptText(YELL_RELEASE2B, me);
                            break;
                        case 5:
                            switch (urand(0,1))
                            {
                            case 0: 
                                me->SummonCreature(ENTRY_AKKIRIS,420.179,-174.396,42.58,0.02,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); 
                                break;
                            case 1: 
                                me->SummonCreature(ENTRY_SULFURON,420.179,-174.396,42.58,0.02,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); 
                                break;
                            }
                            break;
                        case 6:
                            switch (urand(0,1))
                            {
                            case 0: 
                                me->SummonCreature(ENTRY_TW_DRAK,471.795,-174.58,42.58,3.06,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); 
                                break;
                            case 1: 
                                me->SummonCreature(ENTRY_BL_DRAK,471.795,-174.58,42.58,3.06,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000); 
                                break;
                            }
                            break;
                        case 7:
                            me->SummonCreature(ENTRY_SKYRISS,445.763,-191.639,44.64,1.60,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000);
                            DoScriptText(YELL_WELCOME, me);
                            break;
                        }
                        CanSpawn = false;
                        ++Phase;
                    }
                    if (CanProgress())
                    {
                        switch(Phase)
                        {
                        case 1:
                            DoScriptText(YELL_INTRO2, me);
                            EventProgress_Timer = 10000;
                            ++Phase;
                            break;
                        case 2:
                            DoScriptText(YELL_RELEASE1, me);
                            DoPrepareForPhase();
                            EventProgress_Timer = 7000;
                            break;
                        case 3:
                            DoScriptText(YELL_RELEASE2A, me);
                            DoPrepareForPhase();
                            EventProgress_Timer = 10000;
                            break;
                        case 4:
                            DoPrepareForPhase();
                            EventProgress_Timer = 15000;
                            break;
                        case 5:
                            DoScriptText(YELL_RELEASE3, me);
                            DoPrepareForPhase();
                            EventProgress_Timer = 15000;
                            break;
                        case 6:
                            DoScriptText(YELL_RELEASE4, me);
                            DoPrepareForPhase();
                            EventProgress_Timer = 15000;
                            break;
                        case 7:
                            DoPrepareForPhase();
                            EventProgress_Timer = 15000;
                            break;
                        }
                    }
                } 
                else 
                    EventProgress_Timer -= diff;
            }
        };

        CreatureAI* OnGetAI(Creature* creature) const
        {
            return new npc_warden_mellicharAI(creature);
        }        
};

/*#####
# mob_zerekethvoidzone (this script probably not needed in future -> `creature_template_addon`.`auras`='36120 0')
#####*/

#define SPELL_VOID_ZONE_DAMAGE 36120

class mob_zerekethvoidzone : public CreatureScript
{
    public:

        mob_zerekethvoidzone()
            : CreatureScript("mob_zerekethvoidzone")
        {
        }
        struct mob_zerekethvoidzoneAI : public ScriptedAI
        {
            mob_zerekethvoidzoneAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            void Reset()
            {
                me->SetUInt32Value(UNIT_NPC_FLAGS,0);
                me->setFaction(16);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                
                DoCast(me, SPELL_VOID_ZONE_DAMAGE);
            }
            
            void EnterCombat(Unit* /*who*/) {}
        };
        
        CreatureAI* OnGetAI(Creature* creature) const
        {
            return new mob_zerekethvoidzoneAI(creature);
        }
};
void AddSC_arcatraz()
{
    new npc_millhouse_manastorm();
    new npc_warden_mellichar();
    new mob_zerekethvoidzone();
}

