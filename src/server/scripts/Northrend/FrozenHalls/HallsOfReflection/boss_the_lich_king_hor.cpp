/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "halls_of_reflection.h"
#include "ScriptedEscortAI.h"

enum
{
   SPELL_WINTER                        = 69780,
   SPELL_FURY_OF_FROSTMOURNE           = 70063,
   SPELL_SOUL_REAPER                   = 73797,
   SPELL_RAISE_DEAD                    = 69818,
   SPELL_ICE_PRISON                    = 69708,
   SPELL_DARK_ARROW                    = 70194,
   SPELL_HARVEST_SOUL                  = 70070,
   SPELL_PAIN_AND_SUFFERING            = 74115,

   //Raging gnoul
   SPELL_EMERGE_VISUAL                 = 50142,
   SPELL_GHOUL_JUMP                    = 70150,

   //Witch Doctor
   SPELL_COURSE_OF_DOOM                = 70144,
   H_SPELL_COURSE_OF_DOOM              = 70183,
   SPELL_SHADOW_BOLT_VOLLEY            = 70145,
   H_SPELL_SHADOW_BOLT_VOLLEY          = 70184,
   SPELL_SHADOW_BOLT                   = 70080,
   H_SPELL_SHADOW_BOLT                 = 70182,

   //Lumbering Abomination
   SPELL_ABON_STRIKE                  = 40505,
   SPELL_VOMIT_SPRAY                  = 70176,
   H_SPELL_VOMIT_SPRAY                = 70181,

   SAY_LICH_KING_WALL_01              = 5,
   SAY_LICH_KING_WALL_02              = 6,
   SAY_LICH_KING_GNOUL                = 7,
   SAY_LICH_KING_ABON                 = 8,
   SAY_LICH_KING_WINTER               = 9,
   SAY_LICH_KING_END_DUN              = 10,
   SAY_LICH_KING_WIN                  = 11,
};

class boss_lich_king_hor : public CreatureScript
{
public:
   boss_lich_king_hor() : CreatureScript("boss_lich_king_hor") { }

   CreatureAI* GetAI(Creature* creature) const
   {
       return new boss_lich_king_horAI(creature);
   }

   struct boss_lich_king_horAI : public npc_escortAI
   {
       boss_lich_king_horAI(Creature *creature) : npc_escortAI(creature)
       {
           pInstance = (InstanceScript*)creature->GetInstanceScript();
           Reset();
       }

       InstanceScript* pInstance;
       uint32 Step;
       uint32 StepTimer;
       uint32 uiWall;
       bool StartEscort;
       bool WipedGroup;
       bool NonFight;
       float walkSpeed;

       void Reset()
       {
           if(!pInstance)
               return;
           NonFight = false;
           StartEscort = false;
           WipedGroup = false;
           walkSpeed = 0.8f;
           uiWall = 0;
           if (pInstance->GetData(DATA_FROSWORN_EVENT) == DONE)
               me->SetHealth(me->GetMaxHealth() * 0.80);
       }

       void JustDied(Unit* /*killer*/) { }

       void WaypointReached(uint32 i)
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
                   pInstance->SetData(DATA_LICHKING_EVENT, SPECIAL);
                   Talk(SAY_LICH_KING_END_DUN);
                   if(Creature* pLider = ((Creature*)Unit::GetUnit((*me), pInstance->GetData64(DATA_ESCAPE_LIDER))))
                       me->CastSpell(pLider, SPELL_HARVEST_SOUL, false);
                   me->setActive(false);
                   break;
           }
       }

       void AttackStart(Unit* who)
       {
           if (!pInstance || !who)
               return;

           if (NonFight)
               return;

           if(pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS || who->GetTypeId() == TYPEID_PLAYER)
               return;

           npc_escortAI::AttackStart(who);
       }

       void JustSummoned(Creature* summoned)
       {
           if(!pInstance || !summoned)
               return;

           summoned->SetInCombatWithZone();
           summoned->setActive(true);

           pInstance->SetData(DATA_SUMMONS, 1);
           if (Unit* pLider = Unit::GetUnit((*me), pInstance->GetData64(DATA_ESCAPE_LIDER)))
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
                   me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                   me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE );
                   // DoCast(me, SPELL_PAIN_AND_SUFFERING); Spell is currently broken, it also does damage to people in front of you.
                   DoCast(me, SPELL_WINTER);
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

       void UpdateEscortAI(const uint32 diff)
       {
           if(!pInstance)
               return;

           if(pInstance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED || pInstance->GetData(DATA_LICHKING_EVENT) == FAIL)
           {
               if (!UpdateVictim())
                   return;

               DoMeleeAttackIfReady();
           }

           // Start chase for leader
           if(pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS && StartEscort != true)
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
           }

           // Leader caught, wipe
           if (Creature* pLider = ((Creature*)Unit::GetUnit((*me), pInstance->GetData64(DATA_ESCAPE_LIDER))))
           {
               if (!WipedGroup && pLider->IsWithinDistInMap(me, 2.0f) && pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
               {
                    WipedGroup = true;
                   me->setActive(false);
                   SetEscortPaused(true);
                   me->StopMoving();
                   Talk(SAY_LICH_KING_WIN);
                   me->CastSpell((Unit*)NULL, SPELL_FURY_OF_FROSTMOURNE, TRIGGERED_NONE);
                   me->DealDamage(pLider, pLider->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false); // Probably a hack
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

class npc_raging_gnoul : public CreatureScript
{
public:
   npc_raging_gnoul() : CreatureScript("npc_raging_gnoul") { }

   struct npc_raging_gnoulAI : public ScriptedAI
   {
       npc_raging_gnoulAI(Creature *creature) : ScriptedAI(creature)
       {
           pInstance = (InstanceScript*)creature->GetInstanceScript();
           me->setActive(true);
           Reset();
       }

       InstanceScript* pInstance;
       uint32 EmergeTimer;
       bool Emerge;
       bool jumped;
       uint64 uiLiderGUID;

       void Reset()
       {
           DoCast(me, SPELL_EMERGE_VISUAL);
           EmergeTimer = 4000;
           Emerge = false;
           jumped = false;
       }

       void JustDied(Unit* /*killer*/)
       {
           if(!pInstance)
               return;

           pInstance->SetData(DATA_SUMMONS, 0);
       }

       void UpdateAI(uint32 diff)
       {
           if (!UpdateVictim())
                return;

            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
            {
                if (!jumped && me->IsWithinDistInMap(target, 30.0f) && !me->IsWithinDistInMap(target, 5.0f))
                {
                    jumped = true;
                    DoCast(target, SPELL_GHOUL_JUMP);
                }
           }
           
           if (pInstance->GetData(DATA_LICHKING_EVENT) == FAIL || pInstance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
               me->DespawnOrUnsummon();

           DoMeleeAttackIfReady();
       }
   };

   CreatureAI* GetAI(Creature* creature) const
   {
       return new npc_raging_gnoulAI(creature);
   }

};

class npc_risen_witch_doctor : public CreatureScript
{
public:
   npc_risen_witch_doctor() : CreatureScript("npc_risen_witch_doctor") { }

   struct npc_risen_witch_doctorAI : public ScriptedAI
   {
       npc_risen_witch_doctorAI(Creature *creature) : ScriptedAI(creature)
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

       void Reset()
       {
           DoCast(me, SPELL_EMERGE_VISUAL);
           EmergeTimer = 5000;
           uiBoltTimer = 6000;
           uiBoltVolleyTimer = 15000;
           uiCurseTimer = 7000;
           Emerge = false;
       }

       void JustDied(Unit* /*killer*/)
       {
           if(!pInstance)
               return;

           pInstance->SetData(DATA_SUMMONS, 0);

       }

       void AttackStart(Unit* who)
       {
           if (!who)
               return;

           if(Emerge == false)
               return;

           ScriptedAI::AttackStart(who);
       }

       void UpdateAI(uint32 diff)
       {
           if(!pInstance)
               return;

           if(pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
           {
               if(Emerge != true)
               {
                   if(EmergeTimer < diff)
                   {
                       Emerge = true;
                       uiLiderGUID = pInstance->GetData64(DATA_ESCAPE_LIDER);
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
           else if (pInstance->GetData(DATA_LICHKING_EVENT) == FAIL || pInstance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
               me->DespawnOrUnsummon();

           DoMeleeAttackIfReady();
       }
   };

   CreatureAI* GetAI(Creature* creature) const
   {
       return new npc_risen_witch_doctorAI(creature);
   }

};

class npc_abon : public CreatureScript
{
public:
   npc_abon() : CreatureScript("npc_abon") { }

   struct npc_abonAI : public ScriptedAI
   {
       npc_abonAI(Creature *creature) : ScriptedAI(creature)
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

       void Reset()
       {
           Walk = false;
           uiVomitTimer = 15000;
           uiStrikeTimer = 6000;
       }

       void UpdateAI(uint32 diff)
       {
           if(!pInstance) return;

           if(pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
           {
               if(Walk != true)
               {
                   Walk = true;
                   uiLiderGUID = pInstance->GetData64(DATA_ESCAPE_LIDER);
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
           else if (pInstance->GetData(DATA_LICHKING_EVENT) == FAIL || pInstance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
               me->DespawnOrUnsummon();
           DoMeleeAttackIfReady();
       }

       void JustDied(Unit* /*killer*/)
       {
           if(!pInstance)
               return;

           pInstance->SetData(DATA_SUMMONS, 0);
       }
   };

   CreatureAI* GetAI(Creature* creature) const
   {
       return new npc_abonAI(creature);
   }
};

void AddSC_boss_lich_king_hr()
{
   new boss_lich_king_hor();
   new npc_raging_gnoul();
   new npc_risen_witch_doctor();
   new npc_abon();
}
