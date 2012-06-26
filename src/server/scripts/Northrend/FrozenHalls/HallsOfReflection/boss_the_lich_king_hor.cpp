/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
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
 SDName: boss_Lich_king
 SD%Complete: 0%
 SDComment: new script for tc implementation.
 SDCategory: Halls of Reflection
 EndScriptData */

#include "ScriptPCH.h"
#include "halls_of_reflection.h"
#include "ScriptedEscortAI.h"
#include "Unit.h"

enum
{
    SPELL_WINTER                       = 69780,
    SPELL_FURY_OF_FROSTMOURNE          = 70063,
    SPELL_SOUL_REAPER                  = 73797,
    SPELL_RAISE_DEAD                   = 69818,
    SPELL_ICE_PRISON                   = 69708,
    SPELL_DARK_ARROW                   = 70194,
    SPELL_EMERGE_VISUAL                = 50142,
    SPELL_DESTROY_ICE_WALL_02          = 70224,
    SPELL_SILENCE                      = 69413,
    SPELL_LICH_KING_CAST               = 57561,
    SPELL_GNOUL_JUMP                   = 70150,
    SPELL_ABON_STRIKE                  = 40505,
    SPELL_FROSTMOURNE_VISUAL           = 73220,

    /*SPELLS - Witch Doctor*/
    SPELL_COURSE_OF_DOOM               = 70144,
    SPELL_SHADOW_BOLT_VALLEY           = 70145,
    SPELL_SHADOW_BOLT_N                = 70080,
    SPELL_SHADOW_BOLT_H                = 70182,

    SAY_LICH_KING_WALL_01              = -1594486,
    SAY_LICH_KING_WALL_02              = -1594491,
    SAY_LICH_KING_GNOUL                = -1594482,
    SAY_LICH_KING_ABON                 = -1594483,
    SAY_LICH_KING_WINTER               = -1594481,
    SAY_LICH_KING_END_DUN              = -1594504,
    SAY_LICH_KING_WIN                  = -1594485,
};

class boss_lich_king_hor : public CreatureScript
{
public:
    boss_lich_king_hor() : CreatureScript("boss_lich_king_hor") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_lich_king_horAI(pCreature);
    }

    struct boss_lich_king_horAI : public npc_escortAI
    {
        boss_lich_king_horAI(Creature *pCreature) : npc_escortAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;
        uint32 Step;
        uint32 StepTimer;
        bool StartEscort;
        bool IceWall01;
        bool NonFight;
        bool Finish;

        void Reset()
        {
            if(!m_pInstance)
                return;
            NonFight = false;
            StartEscort = false;
            me->CastSpell(me, SPELL_FROSTMOURNE_VISUAL, false);
        }

        void JustDied(Unit* pKiller) { }

        void WaypointReached(uint32 i)
        {
            switch(i)
            {
                case 20:
                    SetEscortPaused(true);
                    Finish = true;
                    DoCast(me, SPELL_LICH_KING_CAST);
                    m_pInstance->SetData(TYPE_LICH_KING, SPECIAL);
                    DoScriptText(SAY_LICH_KING_END_DUN, me);
                    if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), m_pInstance->GetData64(DATA_ESCAPE_LIDER))))
                        me->CastSpell(pLider, SPELL_SILENCE, false);
                    me->setActive(false);
                    break;
            }
        }

        void AttackStart(Unit* who)
        {
            if (!m_pInstance || !who)
                return;

            if (NonFight)
                return;

            if(m_pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS || who->GetTypeId() == TYPEID_PLAYER)
                return;

            npc_escortAI::AttackStart(who);
        }

        void JustSummoned(Creature* summoned)
        {
            if(!m_pInstance || !summoned)
                return;

            summoned->SetPhaseMask(65535, true);
            summoned->SetInCombatWithZone();
            summoned->setActive(true);

            m_pInstance->SetData(DATA_SUMMONS, 1);
            if (Unit* pLider = Unit::GetUnit((*me), m_pInstance->GetData64(DATA_ESCAPE_LIDER)))
            {
                summoned->GetMotionMaster()->MoveChase(pLider);
                summoned->AddThreat(pLider, 100.0f);
            }
        }

        void CallGuard(uint32 GuardID)
        {
            me->SummonCreature(GuardID,(me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ(),4.17f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,360000);
        }

        void Wall01()
        {
            switch(Step)
            {
                case 0:
                    SetEscortPaused(true);
                    m_pInstance->SetData(DATA_SUMMONS, 3);
                    DoScriptText(SAY_LICH_KING_WALL_01, me);
                    DoCast(me, SPELL_DESTROY_ICE_WALL_02);
                    StepTimer = 2000;
                    ++Step;
                    break;
                case 1:
                    StepTimer = 2000;
                    ++Step;
                    break;
                case 2:
                    DoCast(me, SPELL_RAISE_DEAD);
                    DoScriptText(SAY_LICH_KING_GNOUL, me);
                    StepTimer = 7000;
                    ++Step;
                    break;
                case 3:
                    DoCast(me, SPELL_WINTER);
                    DoScriptText(SAY_LICH_KING_WINTER, me);
                    me->SetSpeed(MOVE_WALK, 1.1f, true);
                    StepTimer = 1000;
                    ++Step;
                    break;
                case 4:
                    SetEscortPaused(false);
                    StepTimer = 2000;
                    ++Step;
                    break;
                case 5:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    m_pInstance->SetData(TYPE_ICE_WALL_01, DONE);
                    StepTimer = 100;
                    Step = 0;
                    break;
            }
        }

        void Wall02()
        {
            switch(Step)
            {
                case 0:
                    m_pInstance->SetData(DATA_SUMMONS, 3);
                    SetEscortPaused(true);
                    DoCast(me, SPELL_RAISE_DEAD);
                    DoScriptText(SAY_LICH_KING_GNOUL, me);
                    StepTimer = 10000;
                    ++Step;
                    break;
                case 1:
                    SetEscortPaused(false);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    m_pInstance->SetData(TYPE_ICE_WALL_02, DONE);
                    StepTimer = 100;
                    Step = 0;
                    break;
            }
        }

        void Wall03()
        {
            switch(Step)
            {
                case 0:
                    m_pInstance->SetData(DATA_SUMMONS, 3);
                    SetEscortPaused(true);
                    DoCast(me, SPELL_RAISE_DEAD);
                    DoScriptText(SAY_LICH_KING_GNOUL, me);
                    StepTimer = 10000;
                    ++Step;
                    break;
                case 1:
                    SetEscortPaused(false);
                    DoScriptText(SAY_LICH_KING_ABON, me);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    CallGuard(NPC_ABON);
                    m_pInstance->SetData(TYPE_ICE_WALL_03, DONE);
                    StepTimer = 100;
                    Step = 0;
                    break;
            }
        }

        void Wall04()
        {
            switch(Step)
            {
                case 0:
                    m_pInstance->SetData(DATA_SUMMONS, 3);
                    SetEscortPaused(true);
                    DoCast(me, SPELL_RAISE_DEAD);
                    DoScriptText(SAY_LICH_KING_GNOUL, me);
                    StepTimer = 10000;
                    ++Step;
                    break;
                case 1:
                    SetEscortPaused(false);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    CallGuard(NPC_ABON);
                    StepTimer = 15000;
                    ++Step;
                    break;
                case 2:
                    DoScriptText(SAY_LICH_KING_ABON, me);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    m_pInstance->SetData(TYPE_ICE_WALL_04, DONE);
                    ++Step;
                    break;
            }
        }

        void UpdateEscortAI(const uint32 diff)
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            if(me->isInCombat() && m_pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS)
            {
                npc_escortAI::EnterEvadeMode();
            }

            if(m_pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS && StartEscort != true)
            {
                StartEscort = true;
                me->RemoveAurasDueToSpell(SPELL_ICE_PRISON);
                me->RemoveAurasDueToSpell(SPELL_DARK_ARROW);
                //me->RemoveAllAuras();
                me->setActive(true);
                me->CastSpell(me, SPELL_FROSTMOURNE_VISUAL, false);
                NonFight = true;
                me->AttackStop();
                me->SetSpeed(MOVE_WALK, 2.5f, true);
                Start(false, false);
                Step = 0;
                StepTimer = 100;
            }

            if (Creature* pLider = ((Creature*)Unit::GetUnit((*me), m_pInstance->GetData64(DATA_ESCAPE_LIDER))))
            {
                if (pLider->IsWithinDistInMap(me, 2.0f))
                {
                    me->setActive(false);
                    SetEscortPaused(true);
                    npc_escortAI::EnterEvadeMode();
                    DoScriptText(SAY_LICH_KING_WIN, me);
                    me->CastSpell(me, SPELL_FURY_OF_FROSTMOURNE, false);
                    me->DealDamage(pLider, pLider->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    me->NearTeleportTo(5572.077f, 2283.1f, 734.976f, 3.89f);
                    m_pInstance->SetData(TYPE_LICH_KING, FAIL);
                }
            }

            if(m_pInstance->GetData(TYPE_ICE_WALL_01) == IN_PROGRESS)
            {
                if(StepTimer < diff)
                    Wall01();
                else
                    StepTimer -= diff;
            }

            if(m_pInstance->GetData(TYPE_ICE_WALL_02) == IN_PROGRESS)
            {
                if(StepTimer < diff)
                    Wall02();
                else
                    StepTimer -= diff;
            }

            if(m_pInstance->GetData(TYPE_ICE_WALL_03) == IN_PROGRESS)
            {
                if(StepTimer < diff)
                    Wall03();
                else
                    StepTimer -= diff;
            }

            if(m_pInstance->GetData(TYPE_ICE_WALL_04) == IN_PROGRESS)
            {
                if(StepTimer < diff)
                    Wall04();
                else
                    StepTimer -= diff;
            }
            return;
        }
    };
};

class npc_raging_gnoul : public CreatureScript
{
public:
    npc_raging_gnoul() : CreatureScript("npc_raging_gnoul") { }

    struct npc_raging_gnoulAI : public ScriptedAI
    {
        npc_raging_gnoulAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            me->setActive(true);
            Reset();
        }

        InstanceScript* m_pInstance;
        uint32 EmergeTimer;
        bool Emerge;
        uint64 m_uiLiderGUID;

        void Reset()
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            EmergeTimer = 4000;
            Emerge = false;
        }

        void JustDied(Unit* pKiller)
        {
            if(!m_pInstance)
                return;

            m_pInstance->SetData(DATA_SUMMONS, 0);
        }

        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            if(Emerge == false)
                return;

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS)
            {
                if(Emerge != true)
                {
                    if(EmergeTimer < diff)
                    {
                        //me->RemoveFlag(SPLINEFLAG_WALKING | MOVEMENTFLAG_WALKING, true);
                        Emerge = true;
                        m_uiLiderGUID = m_pInstance->GetData64(DATA_ESCAPE_LIDER);
                        if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), m_uiLiderGUID)))
                        {
                            DoResetThreat();
                            me->AI()->AttackStart(pLider);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(pLider);
                        }
                    }
                    else
                        EmergeTimer -= diff;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_raging_gnoulAI(pCreature);
    }

};

class npc_risen_witch_doctor : public CreatureScript
{
public:
    npc_risen_witch_doctor() : CreatureScript("npc_risen_witch_doctor") { }

    struct npc_risen_witch_doctorAI : public ScriptedAI
    {
        npc_risen_witch_doctorAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            me->setActive(true);
            Reset();
        }

        InstanceScript* m_pInstance;
        uint32 EmergeTimer;
        bool Emerge;
        uint64 m_uiLiderGUID;

        void Reset()
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            EmergeTimer = 5000;
            Emerge = false;
        }

        void JustDied(Unit* pKiller)
        {
            if(!m_pInstance)
                return;

            m_pInstance->SetData(DATA_SUMMONS, 0);

        }

        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            if(Emerge == false)
                return;

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(const uint32 diff)
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS)
            {
                if(Emerge != true)
                {
                    if(EmergeTimer < diff)
                    {
                        Emerge = true;
                        m_uiLiderGUID = m_pInstance->GetData64(DATA_ESCAPE_LIDER);
                        if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), m_uiLiderGUID)))
                        {
                            DoResetThreat();
                            me->AI()->AttackStart(pLider);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(pLider);
                        }
                    }
                    else
                        EmergeTimer -= diff;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_risen_witch_doctorAI(pCreature);
    }

};

class npc_abon : public CreatureScript
{
public:
    npc_abon() : CreatureScript("npc_abon") { }

    struct npc_abonAI : public ScriptedAI
    {
        npc_abonAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            me->setActive(true);
            Reset();
        }

        InstanceScript* m_pInstance;
        uint64 m_uiLiderGUID;
        bool Walk;

        void Reset()
        {
            Walk = false;
        }

        void UpdateAI(const uint32 diff)
        {
            if(!m_pInstance) return;

            if(m_pInstance->GetData(TYPE_LICH_KING) == IN_PROGRESS)
            {
                if(Walk != true)
                {
                    Walk = true;
                    m_uiLiderGUID = m_pInstance->GetData64(DATA_ESCAPE_LIDER);
                    if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), m_uiLiderGUID)))
                    {
                        DoResetThreat();
                        me->AI()->AttackStart(pLider);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(pLider);
                    }
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
            if(!m_pInstance)
                return;

            m_pInstance->SetData(DATA_SUMMONS, 0);
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_abonAI(pCreature);
    }
};

void AddSC_boss_lich_king_hr()
{
    new boss_lich_king_hor();
    new npc_raging_gnoul();
    new npc_risen_witch_doctor();
    new npc_abon();
}
