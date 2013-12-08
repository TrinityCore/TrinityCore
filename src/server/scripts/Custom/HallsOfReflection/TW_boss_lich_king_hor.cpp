/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TW_halls_of_reflection.h"
#include "ScriptedEscortAI.h"

enum
{
    SPELL_WINTER                       = 69780,
    SPELL_FURY_OF_FROSTMOURNE          = 70063,
    SPELL_SOUL_REAPER                  = 73797,
    SPELL_RAISE_DEAD                   = 69818,
    SPELL_ICE_PRISON                   = 69708,
    SPELL_DARK_ARROW                   = 70194,
    SPELL_HARVEST_SOUL                 = 70070,

    //Raging gnoul
    SPELL_EMERGE_VISUAL                = 50142,
    SPELL_GNOUL_JUMP                   = 70150,

    //Witch Doctor
    SPELL_COURSE_OF_DOOM               = 70144,
    H_SPELL_COURSE_OF_DOOM             = 70183,
    SPELL_SHADOW_BOLT_VOLLEY           = 70145,
    H_SPELL_SHADOW_BOLT_VOLLEY         = 70184,
    SPELL_SHADOW_BOLT                  = 70080,
    H_SPELL_SHADOW_BOLT                = 70182,

    //Lumbering Abomination
    SPELL_ABON_STRIKE                  = 40505,
    SPELL_VOMIT_SPRAY                  = 70176,
    H_SPELL_VOMIT_SPRAY                = 70181,

    SAY_LICH_KING_AGGRO_A              = 0,
    SAY_LICH_KING_AGGRO_H              = 1,
    SAY_LICH_KING_WALL_02              = 2,
    SAY_LICH_KING_WALL_03              = 3,
    SAY_LICH_KING_WALL_04              = 4,
    SAY_LICH_KING_WALL_01              = 5,
    SAY_LICH_KING_GNOUL                = 6,
    SAY_LICH_KING_ABON                 = 7,
    SAY_LICH_KING_WINTER               = 8,
    SAY_LICH_KING_END_DUN              = 9,
    SAY_LICH_KING_WIN                  = 10,
};

class TW_boss_lich_king_hor : public CreatureScript
{
public:
    TW_boss_lich_king_hor() : CreatureScript("TW_boss_lich_king_hor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_lich_king_horAI(creature);
    }

    struct TW_boss_lich_king_horAI : public npc_escortAI
    {
        TW_boss_lich_king_horAI(Creature *creature) : npc_escortAI(creature)
        {
            pInstance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;
        uint32 Step;
        uint32 StepTimer;
        uint32 uiWall;
        bool StartEscort;
        bool NonFight;
        float walkSpeed;

        void Reset() OVERRIDE
        {
            if(!pInstance)
                return;
            NonFight = false;
            StartEscort = false;
            walkSpeed = 1.0f;
            uiWall = 0;
        }

        void JustDied(Unit* pKiller) OVERRIDE { }

        void WaypointReached(uint32 i) OVERRIDE
        {
            if(pInstance->GetData(DATA_ICE_WALL_1) == IN_PROGRESS)
            {
                uiWall = 1;
                SetEscortPaused(true);
            }

            if(pInstance->GetData(DATA_ICE_WALL_2) == IN_PROGRESS)
            {
                uiWall = 2;
                SetEscortPaused(true);
            }

            if(pInstance->GetData(DATA_ICE_WALL_3) == IN_PROGRESS)
            {
                uiWall = 3;
                SetEscortPaused(true);
            }

            if(pInstance->GetData(DATA_ICE_WALL_4) == IN_PROGRESS)
            {
                uiWall = 4;
                SetEscortPaused(true);
            }

            switch(i)
            {
                case 66:
                    SetEscortPaused(true);
                    pInstance->SetBossState(DATA_LICHKING_EVENT, SPECIAL);
                    Talk(SAY_LICH_KING_END_DUN);
                    if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), pInstance->GetData64(DATA_ESCAPE_LEADER))))
                        me->CastSpell(pLider, SPELL_HARVEST_SOUL, false);
                    me->setActive(false);
                    break;
            }
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!pInstance || !who)
                return;

            if (NonFight)
                return;

            if(pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS || who->GetTypeId() == TYPEID_PLAYER)
                return;

            npc_escortAI::AttackStart(who);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            if(!pInstance || !summoned)
                return;

            summoned->SetInCombatWithZone();
            summoned->setActive(true);

            pInstance->SetData(DATA_SUMMONS, 1);
            if (Unit* pLider = Unit::GetUnit((*me), pInstance->GetData64(DATA_ESCAPE_LEADER)))
            {
                summoned->GetMotionMaster()->MoveChase(pLider);
                summoned->AddThreat(pLider, 0.0f);
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
                    pInstance->SetData(DATA_SUMMONS, 3);
                    Talk(SAY_LICH_KING_WALL_01);
                    StepTimer = 2000;
                    ++Step;
                    break;
                case 1:
                    DoCast(me, SPELL_RAISE_DEAD);
                    Talk(SAY_LICH_KING_GNOUL);
                    StepTimer = 7000;
                    ++Step;
                    break;
                case 2:
                    //DoCast(me, SPELL_WINTER);
					me->AddAura(SPELL_WINTER, me);
                    Talk(SAY_LICH_KING_WINTER);
                    me->SetSpeed(MOVE_WALK, walkSpeed, true);
                    StepTimer = 1000;
                    ++Step;
                    break;
                case 3:
                    StepTimer = 2000;
                    ++Step;
                    break;
                case 4:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    pInstance->SetData(DATA_ICE_WALL_1, DONE);
                    StepTimer = 100;
                    Step = 0;
                    uiWall = 0;
                    SetEscortPaused(false);
                    break;
            }
        }

        void Wall02()
        {
            switch(Step)
            {
                case 0:
                    pInstance->SetData(DATA_SUMMONS, 3);
                    Talk(SAY_LICH_KING_GNOUL);
                    DoCast(me, SPELL_RAISE_DEAD);
                    StepTimer = 6000;
                    ++Step;
                    break;
                case 1:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    pInstance->SetData(DATA_ICE_WALL_2, DONE);
                    StepTimer = 5000;
                    Step = 0;
                    uiWall = 0;
                    SetEscortPaused(false);
                    break;
            }
        }

        void Wall03()
        {
            switch(Step)
            {
                case 0:
                    pInstance->SetData(DATA_SUMMONS, 3);
                    DoCast(me, SPELL_RAISE_DEAD);
                    Talk(SAY_LICH_KING_GNOUL);
                    StepTimer = 6000;
                    ++Step;
                    break;
                case 1:
                    Talk(SAY_LICH_KING_ABON);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    CallGuard(NPC_ABON);
                    pInstance->SetData(DATA_ICE_WALL_3, DONE);
                    StepTimer = 5000;
                    Step = 0;
                    uiWall = 0;
                    SetEscortPaused(false);
                    break;
            }
        }

        void Wall04()
        {
            switch(Step)
            {
                case 0:
                    pInstance->SetData(DATA_SUMMONS, 3);
                    DoCast(me, SPELL_RAISE_DEAD);
                    Talk(SAY_LICH_KING_GNOUL);
                    StepTimer = 6000;
                    ++Step;
                    break;
                case 1:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    CallGuard(NPC_ABON);
                    StepTimer = 15000;
                    ++Step;
                    break;
                case 2:
                    Talk(SAY_LICH_KING_ABON);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    pInstance->SetData(DATA_ICE_WALL_4, DONE);
                    uiWall = 0;
                    SetEscortPaused(false);
                    ++Step;
                    break;
            }
        }

        void UpdateEscortAI(uint32 const diff) OVERRIDE
        {
            if(!pInstance)
                return;

            if(pInstance->GetBossState(DATA_LICHKING_EVENT) == NOT_STARTED || pInstance->GetBossState(DATA_LICHKING_EVENT) == FAIL)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            if(me->IsInCombat() && pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS)
            {
                npc_escortAI::EnterEvadeMode();
            }

            // Start chase for leader
            if(pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS && StartEscort != true)
            {
                StartEscort = true;
                me->RemoveAurasDueToSpell(SPELL_ICE_PRISON);
                me->RemoveAurasDueToSpell(SPELL_DARK_ARROW);
                me->setActive(true);
                NonFight = true;
                me->AttackStop();
                me->SetSpeed(MOVE_WALK, 2.5f, true);
                Start(false, false);
                Step = 0;
                StepTimer = 100;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC);
            }

            // Leader caught, wipe
            if (Creature* pLider = ((Creature*)Unit::GetUnit((*me), pInstance->GetData64(DATA_ESCAPE_LEADER))))
            {
                if (pLider->IsWithinDistInMap(me, 2.0f) && pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS)
                {
                    me->setActive(false);
                    SetEscortPaused(false);
                    me->StopMoving();
                    Talk(SAY_LICH_KING_WIN);
                    me->CastSpell(me, SPELL_FURY_OF_FROSTMOURNE, false);
                    me->DealDamage(pLider, pLider->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
            }

            if(uiWall == 1)
            {
                if(StepTimer < diff)
                    Wall01();
                else
                    StepTimer -= diff;
            }

            if(uiWall == 2)
            {
                if(StepTimer < diff)
                    Wall02();
                else
                    StepTimer -= diff;
            }

            if(uiWall == 3)
            {
                if(StepTimer < diff)
                    Wall03();
                else
                    StepTimer -= diff;
            }

            if(uiWall == 4)
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

class TW_npc_raging_ghoul : public CreatureScript
{
public:
    TW_npc_raging_ghoul() : CreatureScript("TW_npc_raging_ghoul") { }

    struct TW_npc_raging_ghoulAI : public ScriptedAI
    {
        TW_npc_raging_ghoulAI(Creature *creature) : ScriptedAI(creature)
        {
            pInstance = (InstanceScript*)creature->GetInstanceScript();
            me->setActive(true);
            Reset();
        }

        InstanceScript* pInstance;
        uint32 EmergeTimer;
        bool Emerge;
        bool Jumped;
        uint64 uiLiderGUID;

        void Reset() OVERRIDE
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            EmergeTimer = 4000;
            Emerge = false;
            Jumped = false;
        }

        void JustDied(Unit* pKiller) OVERRIDE
        {
            if(!pInstance)
                return;

            pInstance->SetData(DATA_SUMMONS, 0);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if(Emerge == false)
                return;

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if(!pInstance)
                return;

            if(pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS)
            {
                uiLiderGUID = pInstance->GetData64(DATA_ESCAPE_LEADER);
                Creature* pLider = ((Creature*)Unit::GetUnit((*me), uiLiderGUID));

                if(Emerge != true)
                {
                    if(EmergeTimer < diff)
                    {
                        //me->RemoveFlag(SPLINEFLAG_WALKING | MOVEMENTFLAG_WALKING, true);
                        Emerge = true;
                        uiLiderGUID = pInstance->GetData64(DATA_ESCAPE_LEADER);
                        if(pLider)
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

                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                {
                    if(!Jumped && me->IsWithinDistInMap(target, 30.0f) && !me->IsWithinDistInMap(target, 5.0f))
                    {
                        Jumped = true;
                        DoCast(target, SPELL_GNOUL_JUMP);
                    }
                }
            }
            else if (pInstance->GetBossState(DATA_LICHKING_EVENT) == FAIL || pInstance->GetBossState(DATA_LICHKING_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_raging_ghoulAI(creature);
    }

};

class TW_npc_risen_witch_doctor : public CreatureScript
{
public:
    TW_npc_risen_witch_doctor() : CreatureScript("TW_npc_risen_witch_doctor") { }

    struct TW_npc_risen_witch_doctorAI : public ScriptedAI
    {
        TW_npc_risen_witch_doctorAI(Creature *creature) : ScriptedAI(creature)
        {
            pInstance = (InstanceScript*)creature->GetInstanceScript();
            me->setActive(true);
            Reset();
        }

        InstanceScript* pInstance;
        uint32 EmergeTimer;
        bool Emerge;
        uint64 uiLiderGUID;
        uint32 uiBoltTimer;
        uint32 uiBoltVolleyTimer;
        uint32 uiCurseTimer;

        void Reset() OVERRIDE
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            EmergeTimer = 5000;
            uiBoltTimer = 6000;
            uiBoltVolleyTimer = 15000;
            uiCurseTimer = 7000;
            Emerge = false;
        }

        void JustDied(Unit* pKiller) OVERRIDE
        {
            if(!pInstance)
                return;

            pInstance->SetData(DATA_SUMMONS, 0);

        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if(Emerge == false)
                return;

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if(!pInstance)
                return;

            if(pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS)
            {
                if(Emerge != true)
                {
                    if(EmergeTimer < diff)
                    {
                        Emerge = true;
                        uiLiderGUID = pInstance->GetData64(DATA_ESCAPE_LEADER);
                        if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), uiLiderGUID)))
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

                if (uiCurseTimer < diff)
                {
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_COURSE_OF_DOOM);
                    uiCurseTimer = urand(10000, 15000);
                } else uiCurseTimer -= diff;

                if (uiBoltTimer < diff)
                {
                    if(Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_SHADOW_BOLT);
                    uiBoltTimer = urand(2000, 3000);
                } else uiBoltTimer -= diff;

                if (uiBoltVolleyTimer < diff)
                {
                    if(Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_SHADOW_BOLT_VOLLEY);
                    uiBoltVolleyTimer = urand(15000, 22000);
                } else uiBoltVolleyTimer -= diff;

            }
            else if (pInstance->GetBossState(DATA_LICHKING_EVENT) == FAIL || pInstance->GetBossState(DATA_LICHKING_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_risen_witch_doctorAI(creature);
    }

};

class TW_npc_abom : public CreatureScript
{
public:
    TW_npc_abom() : CreatureScript("TW_npc_abom") { }

    struct TW_npc_abomAI : public ScriptedAI
    {
        TW_npc_abomAI(Creature *creature) : ScriptedAI(creature)
        {
            pInstance = (InstanceScript*)creature->GetInstanceScript();
            me->setActive(true);
            Reset();
        }

        InstanceScript* pInstance;
        uint64 uiLiderGUID;
        bool Walk;
        uint32 uiStrikeTimer;
        uint32 uiVomitTimer;

        void Reset() OVERRIDE
        {
            Walk = false;
            uiVomitTimer = 15000;
            uiStrikeTimer = 6000;
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if(!pInstance) return;

            if(pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS)
            {
                if(Walk != true)
                {
                    Walk = true;
                    uiLiderGUID = pInstance->GetData64(DATA_ESCAPE_LEADER);
                    if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), uiLiderGUID)))
                    {
                        DoResetThreat();
                        me->AI()->AttackStart(pLider);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(pLider);
                    }
                }

                if (uiStrikeTimer < diff)
                {
                    if(Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_ABON_STRIKE);
                    uiStrikeTimer = urand(7000, 9000);
                } else uiStrikeTimer -= diff;

                if (uiVomitTimer < diff)
                {
                    if(Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_VOMIT_SPRAY);
                    uiVomitTimer = urand(15000, 20000);
                } else uiVomitTimer -= diff;
            }
            else if (pInstance->GetBossState(DATA_LICHKING_EVENT) == FAIL || pInstance->GetBossState(DATA_LICHKING_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller) OVERRIDE
        {
            if(!pInstance)
                return;

            pInstance->SetData(DATA_SUMMONS, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_abomAI(creature);
    }
};

enum Defs
{
    SAY_JAINA_AGGRO                    = 0,
    SAY_JAINA_WALL_01                  = 1,
    SAY_JAINA_WALL_02                  = 2,
    SAY_JAINA_WALL_03                  = 3,
    SAY_JAINA_WALL_04                  = 4,
    SAY_JAINA_ESCAPE_01                = 5,
    SAY_JAINA_ESCAPE_02                = 6,
    SAY_JAINA_TRAP                     = 7,
    SAY_JAINA_FINAL_2                  = 8,
    SAY_JAINA_FINAL_3                  = 9,

    SAY_SYLVANA_AGGRO                  = 0,
    SAY_SYLVANA_WALL_01                = 1,
    SAY_SYLVANA_WALL_02                = 2,
    SAY_SYLVANA_WALL_03                = 3,
    SAY_SYLVANA_WALL_04                = 4,
    SAY_SYLVANA_ESCAPE_01              = 5,
    SAY_SYLVANA_ESCAPE_02              = 6,
    SAY_SYLVANA_TRAP                   = 7,
    SAY_SYLVANA_FINAL_2                = 8,

    //SAY_BARTLETT_FIRE                  = 0,
    //SAY_BARTLETT_FINAL_1               = 1,

    //SAY_KORM_FIRE                      = 0,
    //SAY_KORM_FINAL_1                   = 1,

    //SAY_MATHEAS_JAINA                  = -1594505,

    /*SPELLS AND VISUAL EFFECTS*/
    SPELL_ICE_BARRIER                  = 69787,
    SPELL_DESTROY_ICE_WALL_01          = 69784, //Jaina
    SPELL_DESTROY_ICE_WALL_03          = 70225, //Sylvana
    SPELL_SYLVANA_JUMP                 = 68339,
    SPELL_SYLVANA_STEP                 = 69087,
    //SPELL_FIRE_CANNON                  = 67461,

    FACTION                            = 2076,
};

const Position CannonSpawns[4] =
{
    {5230.00f, 1658.75f, 802.22f, 0.00f},
    {5245.74f, 1644.44f, 802.35f, 0.00f},
    {5260.64f, 1636.07f, 802.16f, 0.00f},
    {5275.90f, 1633.22f, 802.25f, 0.00f},
};

class TW_npc_jaina_and_sylvana_hor_part2 : public CreatureScript
{
public:
    TW_npc_jaina_and_sylvana_hor_part2() : CreatureScript("TW_npc_jaina_and_sylvana_hor_part2") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction) OVERRIDE
    {
        InstanceScript* m_pInstance = (InstanceScript*)creature->GetInstanceScript();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                ((TW_npc_jaina_and_sylvana_hor_part2AI*)creature->AI())->Start(false,true);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                creature->setActive(true);

                if(m_pInstance)
                {
                    m_pInstance->SetData64(DATA_ESCAPE_LEADER, creature->GetGUID());
                    m_pInstance->SetBossState(DATA_LICHKING_EVENT, IN_PROGRESS);
                    if (m_pInstance->instance->IsHeroic())
                        m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                }
                return true;
            default:
                return false;
        }
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        InstanceScript*   m_pInstance = (InstanceScript*)creature->GetInstanceScript();

        if(!m_pInstance)
            return false;

        if(m_pInstance->GetBossState(DATA_LICHKING_EVENT) == DONE)
            return false;

        if(creature->IsQuestGiver())
           player->PrepareQuestMenu( creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "We're ready! Let's go!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new TW_npc_jaina_and_sylvana_hor_part2AI(creature);
    }

    struct TW_npc_jaina_and_sylvana_hor_part2AI : public npc_escortAI
    {
        TW_npc_jaina_and_sylvana_hor_part2AI(Creature *creature) : npc_escortAI(creature)
        {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        uint32 CastTimer;
        uint32 StepTimer;
        uint32 Step;
        int32 HoldTimer;
        uint32 Count;
        bool Fight;
        bool Event;
        bool PreFight;
        bool WallCast;
        uint64 m_uiLichKingGUID;
        uint64 m_uiLiderGUID;
        uint64 m_uiIceWallGUID;
        uint64 m_uipWallTargetGUID;
        uint64 uiCaptain;
        Creature* pLichKing;
        uint32 m_chestID;

        void Reset() OVERRIDE
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS)
                return;

            Step = 0;
            StepTimer = 500;
            Fight = true;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            m_uipWallTargetGUID = 0;

            if(me->GetEntry() == NPC_JAINA_OUTRO)
            {
                me->CastSpell(me, SPELL_ICE_BARRIER, false);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
            }
            if(m_pInstance->GetBossState(DATA_LICHKING_EVENT) == DONE)
                me->SetVisible(false);
            me->SetInCombatState(false);
            me->SetHealth(252000);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if(!who)
                return;

            if(me->GetEntry() != NPC_SYLVANA_OUTRO)
                return;

            if(m_pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS || Fight != true)
                return;

            npc_escortAI::AttackStart(who);

        }

        void JustDied(Unit* pKiller) OVERRIDE
        {
            if(!m_pInstance)
                return;
            m_pInstance->SetBossState(DATA_LICHKING_EVENT, FAIL);
            if (m_pInstance->instance->IsHeroic())
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
        }

        void WaypointReached(uint32 i) OVERRIDE
        {
            switch(i)
            {
                case 3:
                    m_pInstance->SetData(DATA_ICE_WALL_1, IN_PROGRESS);
                    
                    if (GameObject* pGate = me->SummonGameObject(GO_ICE_WALL, 5540.39f, 2086.48f, 731.066f, 1.00057f, 0.0f, 0.0f, 0.479677f, 0.877445f, 0))
                    {
                        pGate->SetGoState(GO_STATE_READY);
                        m_uiIceWallGUID = pGate->GetGUID();
                    }
                    break;
                case 4:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_01);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_01);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 6:
                    m_pInstance->SetData(DATA_ICE_WALL_2, IN_PROGRESS);
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->IsAlive())
                        {
                            pWallTarget->DespawnOrUnsummon ();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    break;
                case 8:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_02);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_02);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 9:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_ESCAPE_01);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_ESCAPE_01);
                    break;
                case 11:
                    m_pInstance->SetData(DATA_ICE_WALL_3, IN_PROGRESS);
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->IsAlive())
                        {
                            pWallTarget->DespawnOrUnsummon ();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    break;
                case 12:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_03);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_03);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 13:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_ESCAPE_02);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_ESCAPE_02);
                    break;
                case 15:
                    m_pInstance->SetData(DATA_ICE_WALL_4, IN_PROGRESS);
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->IsAlive())
                        {
                            pWallTarget->DespawnOrUnsummon ();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    break;
                case 16:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_04);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_04);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 19:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_TRAP);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_TRAP);
                    break;
                case 20:
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->IsAlive())
                        {
                            pWallTarget->DespawnOrUnsummon ();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    SetEscortPaused(true);
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE
        {
            if (!who || !m_pInstance)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;
            
            if (Player* player = who->ToPlayer())
                if (player->IsGameMaster())
                    return;
            
            // just in case the spawns fuckup,force correct the id based on teamInInstance
            // usually happens after a crash
            if (m_pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE && me->GetCreatureTemplate()->Entry == NPC_SYLVANA_OUTRO)
                 me->UpdateEntry(NPC_JAINA_OUTRO, ALLIANCE);
            else if (m_pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE && me->GetCreatureTemplate()->Entry == NPC_JAINA_OUTRO)
                    me->UpdateEntry(NPC_SYLVANA_OUTRO, HORDE);
            
            Player* player = (Player *)who;

            if (player->GetTeam() == ALLIANCE && me->GetEntry() == NPC_SYLVANA_OUTRO)
                return;

            if (player->GetTeam() == HORDE && me->GetEntry() == NPC_JAINA_OUTRO)
                return;
            
            if (me->IsWithinDistInMap(who, 50.0f)
                && m_pInstance->GetData(DATA_FROSWORN_EVENT) == DONE
                && m_pInstance->GetData(DATA_PHASE) == 3)
            {
                player = (Player *)who;
                Event = true;
                me->setFaction(FACTION);
                m_pInstance->SetData(DATA_PHASE, 4);
            }
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) OVERRIDE
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetBossState(DATA_LICHKING_EVENT) != IN_PROGRESS)
            {
                uiDamage = 0;
                return;
            }

            if(m_pInstance->GetBossState(DATA_LICHKING_EVENT) == IN_PROGRESS && WallCast == true)
            {
                HoldTimer = HoldTimer + 100;
                return;
            }
        }

        void JumpNextStep(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }

        void Intro()
        {
            switch(Step)
            {
                case 0:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    m_uiLichKingGUID = m_pInstance->GetData64(DATA_LICHKING);
                    pLichKing = m_pInstance->instance->GetCreature(m_uiLichKingGUID);
                    me->SetUInt64Value(UNIT_FIELD_TARGET, m_uiLichKingGUID);
                    JumpNextStep(100);
                    break;
                case 1:
                    HoRQuestComplete(me->GetEntry());
                    if(pLichKing)
                    {
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            pLichKing->AI()->Talk(SAY_LICH_KING_AGGRO_A);
                        if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                            pLichKing->AI()->Talk(SAY_LICH_KING_AGGRO_H);
                        pLichKing->AI()->AttackStart(me);
                        me->AI()->AttackStart(pLichKing);
                    }
                    JumpNextStep(3000);
                    break;
                case 2:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                    {
                        Fight = false;
                        if(pLichKing)
                            me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                        JumpNextStep(3000);
                    }
                    else
                        JumpNextStep(100);
                    break;
                case 3:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Fight = true;
                    JumpNextStep(100);
                    break;
                case 4:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                    {
                        if(pLichKing)
                            me->CastSpell(pLichKing, SPELL_SYLVANA_STEP, false);
                        JumpNextStep(3000);
                    }
                    else
                        JumpNextStep(100);
                    break;
                case 5:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                    {
                        Fight = false;
                        if(pLichKing)
                            me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                        JumpNextStep(3000);
                    }
                    else
                        JumpNextStep(12000);
                    break;
                case 6:
                    Fight = true;

                    if(pLichKing)
                    {
                        if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                            DoCast(SPELL_SYLVANA_JUMP);
                        DoCast(pLichKing, me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON : SPELL_DARK_ARROW, false);
                        pLichKing->AttackStop();
                    }
                    JumpNextStep(1480);
                    break;
                case 7:
                    me->RemoveAllAuras();

                    if(pLichKing && !pLichKing->HasAura(SPELL_ICE_PRISON))
                        pLichKing->AddAura(me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON : SPELL_DARK_ARROW, pLichKing);

                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                    me->AttackStop();

                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                    {
                        me->RemoveAurasDueToSpell(SPELL_ICE_BARRIER);
                        Talk(SAY_JAINA_AGGRO);
                    }

                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_AGGRO);

                    JumpNextStep(3000);
                    break;
                case 8:
                    me->GetMotionMaster()->MovePoint(0, 5577.187f, 2236.003f, 733.012f);
                    if(pLichKing && !pLichKing->HasAura(SPELL_ICE_PRISON))
                    {
                        pLichKing->AddAura(me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON : SPELL_DARK_ARROW, pLichKing);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, m_uiLichKingGUID);
                    }
                    JumpNextStep(10000);
                    break;
                case 9:
                    if(pLichKing && (!pLichKing->HasAura(SPELL_ICE_PRISON) || !pLichKing->HasAura(SPELL_DARK_ARROW)))
                    {
                        pLichKing->AddAura(me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON : SPELL_DARK_ARROW, pLichKing);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, m_uiLichKingGUID);
                    }
                    me->RemoveAllAuras();
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    Count = 1;
                    JumpNextStep(100);
                    break;
            }
        }

        void Outro()
        {
            switch(Step)
            {
                case 10:
                    {
                    JumpNextStep(10000);
                    }
                    break;
                case 11:
                    {
                    JumpNextStep(6000);
                    }
                    break;
                case 12:
                    {
                    if(GameObject* pCave = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_CAVE)))
                        pCave->SetGoState(GO_STATE_READY);
                    me->RemoveAllAuras();

                    if (pLichKing)
                    {
                        //manual RDF credit...since spell 72830 won't trigger it
                        m_pInstance->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ACHIEV_CHECK, pLichKing);
                        m_pInstance->SetBossState(DATA_LICHKING_EVENT, DONE);
                        HoRQuestComplete(38211);
                        pLichKing->DespawnOrUnsummon();
                    }
                    
                    JumpNextStep(10000);
                    }
                    break;
                case 13:
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);

                    if (m_pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->SummonGameObject(IsHeroic() ? GO_CAPTAIN_CHEST_ALLIANCE_HEROIC : GO_CAPTAIN_CHEST_ALLIANCE_NORMAL, 5246.187500f, 1649.079468f, 784.301758f, 0.901268f, 0, 0, 0, 0, 720000);
                        else
                            me->SummonGameObject(IsHeroic() ? GO_CAPTAIN_CHEST_HORDE_HEROIC : GO_CAPTAIN_CHEST_HORDE_NORMAL, 5246.187500f, 1649.079468f, 784.301758f, 0.901268f, 0, 0, 0, 0, 720000);
                        me->SummonGameObject(GO_PORTAL, 5270.634277f ,1639.101196f, 784.303040f, 1.682743f, 0, 0, 0, 0, 720000);
                    JumpNextStep(10000);
                    break;
                case 14:
                    Talk(me->GetEntry() == NPC_JAINA_OUTRO ? SAY_JAINA_FINAL_2 : SAY_SYLVANA_FINAL_2);
                    JumpNextStep(20000);
                    break;
                case 15:
                    Talk(me->GetEntry() == NPC_JAINA_OUTRO ? SAY_JAINA_FINAL_3 : 0);
                    JumpNextStep(5000);
                    break;
                case 16:
                    me->SetOrientation(0.68f);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    //me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    JumpNextStep(5000);
                    break;
                case 17:
                    if(GameObject* pCave = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_CAVE)))
                        pCave->SetGoState(GO_STATE_ACTIVE);
                    break;
            }
        }

        void HoRQuestComplete(uint32 killCredit)
        {
            if (m_pInstance)
            {
                Map::PlayerList const &PlayerList = m_pInstance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    i->GetSource()->KilledMonsterCredit(killCredit, 0);
            }
        }

        void UpdateEscortAI(uint32 const diff) OVERRIDE
        {
            if (!m_pInstance || !Event)
                return;

            DoMeleeAttackIfReady();

            if (m_pInstance->GetData(DATA_PHASE) == 4 && m_pInstance->GetBossState(DATA_LICHKING_EVENT) != IN_PROGRESS)
            {
                if(StepTimer < diff)
                    Intro();
                else
                    StepTimer -= diff;
            }

            if (m_pInstance->GetBossState(DATA_LICHKING_EVENT) == SPECIAL
                && m_pInstance->GetData(DATA_PHASE) != 6)       //End Cinematic
            {
                m_pInstance->SetData(DATA_PHASE, 6);
                Step = 10;
            }

            if (m_pInstance->GetData(DATA_PHASE) == 6)
            {
                if (StepTimer < diff)
                    Outro();
                else
                    StepTimer -= diff;
                return;
            }

            if (WallCast == true && CastTimer < diff)
            {
                if (me->GetEntry() == NPC_SYLVANA_OUTRO)
                {
                   if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                        me->CastSpell(pWallTarget, SPELL_DESTROY_ICE_WALL_03, false);
                    CastTimer = 1000;
                }
            }
            else
                CastTimer -= diff;

            if (WallCast == true && HoldTimer < 10000 && ( m_pInstance->GetData(DATA_SUMMONS) == 0 || !me->IsInCombat()))
            {
                WallCast = false;
                me->InterruptNonMeleeSpells(false);
                SetEscortPaused(false);
                if(GameObject* pGate = m_pInstance->instance->GetGameObject(m_uiIceWallGUID))
                    pGate->SetGoState(GO_STATE_ACTIVE);
                ++Count;
                switch(Count)
                {
                    case 2:
                        if (GameObject* pGate = me->SummonGameObject(GO_ICE_WALL, 5494.3f, 1978.27f, 736.689f, 1.0885f, 0.0f, 0.0f, 0.517777f, 0.855516f, 0))
                        {
                            pGate->SetGoState(GO_STATE_READY);
                            if (pLichKing && pLichKing->IsAlive())
                                pLichKing->AI()->Talk(SAY_LICH_KING_WALL_02);
                            m_uiIceWallGUID = pGate->GetGUID();
                        }
                        break;
                    case 3:
                        if (GameObject* pGate = me->SummonGameObject(GO_ICE_WALL, 5434.27f, 1881.12f, 751.303f, 0.923328f, 0.0f, 0.0f, 0.445439f, 0.895312f, 0))
                        {
                            pGate->SetGoState(GO_STATE_READY);
                            if (pLichKing && pLichKing->IsAlive())
                                pLichKing->AI()->Talk(SAY_LICH_KING_WALL_03);
                            m_uiIceWallGUID = pGate->GetGUID();
                        }
                        break;
                    case 4:
                        if (GameObject* pGate = me->SummonGameObject(GO_ICE_WALL, 5323.61f, 1755.85f, 770.305f, 0.784186f, 0.0f, 0.0f, 0.382124f, 0.924111f, 0))
                        {
                            pGate->SetGoState(GO_STATE_READY);
                            if (pLichKing && pLichKing->IsAlive())
                                pLichKing->AI()->Talk(SAY_LICH_KING_WALL_04);
                            m_uiIceWallGUID = pGate->GetGUID();
                        }
                        break;
                    case 5:
                        if (pLichKing && pLichKing->IsAlive())
                        {
                            pLichKing->RemoveAurasDueToSpell(SPELL_WINTER);
                            pLichKing->SetSpeed(MOVE_WALK, 2.5f, true);
                            Step = 0;
                        }
                        break;
                }
            }
            else
            {
                HoldTimer -= diff;
                if (HoldTimer <= 0)
                    HoldTimer = 0;
            }
        }
    };
};

void AddSC_TW_boss_lich_king_hor()
{
    new TW_boss_lich_king_hor();
    new TW_npc_raging_ghoul();
    new TW_npc_risen_witch_doctor();
    new TW_npc_abom();
	new TW_npc_jaina_and_sylvana_hor_part2();
}
