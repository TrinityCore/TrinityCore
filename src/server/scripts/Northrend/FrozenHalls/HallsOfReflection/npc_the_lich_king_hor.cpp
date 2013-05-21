/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "halls_of_reflection.h"
#include "ScriptedEscortAI.h"
enum Enums
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

   SAY_LICH_KING_WALL_01              = 2,   
   SAY_LICH_KING_GNOUL                = 8,
   SAY_LICH_KING_ABON                 = 7,
   SAY_LICH_KING_WINTER               = 6,
   SAY_LICH_KING_END_DUN              = 9,
   SAY_LICH_KING_WIN                  = 10,
};

class npc_the_lich_king_hor : public CreatureScript
{
public:
   npc_the_lich_king_hor() : CreatureScript("npc_the_lich_king_hor") { }

   CreatureAI* GetAI(Creature* creature) const
   {
       return new npc_the_lich_king_horAI(creature);
   }

   struct npc_the_lich_king_horAI : public npc_escortAI
   {
       npc_the_lich_king_horAI(Creature *creature) : npc_escortAI(creature)
       {
           instance = (InstanceScript*)creature->GetInstanceScript();
           Reset();
       }
       InstanceScript* instance;
       uint32 _stepCount;
       uint32 _stepTimer;
       uint32 _wallEntry;
       bool   _startEscort;
       bool   _nonFight;
       float  _walkSpeed;

       void Reset()
       {
           if (!instance)
                  return;
           _nonFight = false;
           _startEscort = false;
           _walkSpeed = 1.0f;
           _wallEntry = 0;
       }

       void JustDied(Unit* killer) { }

       void WaypointReached(uint32 i)
       {
           if (instance->GetData(DATA_ICE_WALL_1) == IN_PROGRESS)
           {
                  _wallEntry = 1;
                  SetEscortPaused(true);
           }

           if (instance->GetData(DATA_ICE_WALL_2) == IN_PROGRESS)
           {
                  _wallEntry = 2;
                  SetEscortPaused(true);
           }

           if (instance->GetData(DATA_ICE_WALL_3) == IN_PROGRESS)
           {
                  _wallEntry = 3;
                  SetEscortPaused(true);
           }

           if (instance->GetData(DATA_ICE_WALL_4) == IN_PROGRESS)
           {
                  _wallEntry = 4;
                  SetEscortPaused(true);
           }

           switch(i)
           {
               case 66:
                   SetEscortPaused(true);
                   instance->SetData(DATA_LICHKING_EVENT, SPECIAL);
                   Talk(SAY_LICH_KING_END_DUN);
                   if (Creature* lider = ((Creature*)Unit::GetUnit((*me), instance->GetData64(DATA_ESCAPE_LIDER))))
                         me->CastSpell(lider, SPELL_HARVEST_SOUL, false);
                         me->setActive(false);
                   break;
           }
       }

       void AttackStart(Unit* who)
       {
           if (!instance || !who)
                  return;

           if (_nonFight)
                  return;

           if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS || who->GetTypeId() == TYPEID_PLAYER)
                  return;

           npc_escortAI::AttackStart(who);
       }

       void JustSummoned(Creature* summoned)
       {
           if (!instance || !summoned)
                  return;
           summoned->SetInCombatWithZone();
           summoned->setActive(true);

           instance->SetData(DATA_SUMMONS, 1);
           if (Unit* lider = Unit::GetUnit((*me), instance->GetData64(DATA_ESCAPE_LIDER)))
           {
                  summoned->GetMotionMaster()->MoveChase(lider);
           }
       }

       void CallGuard(uint32 GuardID)
       {
           me->SummonCreature(GuardID,(me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ(),4.17f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,360000);
       }

       void Wall01()
       {
           switch(_stepCount)
           {
               case 0:
                   instance->SetData(DATA_SUMMONS, 3);
                   Talk(SAY_LICH_KING_WALL_01);
                   _stepTimer = 3000;
                   ++_stepCount;
                   break;
               case 1:
                   DoCast(me, SPELL_RAISE_DEAD);
                   Talk(SAY_LICH_KING_GNOUL);
                   _stepTimer = 8000;
                   ++_stepCount;
                   break;
               case 2:
                   DoCast(me, SPELL_WINTER);
                   Talk(SAY_LICH_KING_WINTER);
                   me->SetSpeed(MOVE_WALK, _walkSpeed, true);
                   _stepTimer = 2000;
                   ++_stepCount;
                   break;
               case 3:
                   _stepTimer = 3000;
                   ++_stepCount;
                   break;
               case 4:
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   instance->SetData(DATA_ICE_WALL_1, DONE);
                   _stepTimer = 100;
                   _stepCount = 0;
                   _wallEntry = 0;
                   SetEscortPaused(false);
                   break;
           }
       }

       void Wall02()
       {
           switch(_stepCount)
           {
               case 0:
                   instance->SetData(DATA_SUMMONS, 3);
                   Talk(SAY_LICH_KING_GNOUL);
                   DoCast(me, SPELL_RAISE_DEAD);
                   _stepTimer = 7000;
                   ++_stepCount;
                   break;
               case 1:
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_ABON);
                   instance->SetData(DATA_ICE_WALL_2, DONE);
                   _stepTimer = 6000;
                   _stepCount = 0;
                   _wallEntry = 0;
                   SetEscortPaused(false);
                   break;
           }
       }

       void Wall03()
       {
           switch(_stepCount)
           {
               case 0:
                   instance->SetData(DATA_SUMMONS, 3);
                   DoCast(me, SPELL_RAISE_DEAD);
                   Talk(SAY_LICH_KING_GNOUL);
                   _stepTimer = 7000;
                   ++_stepCount;
                   break;
               case 1:
                   Talk(SAY_LICH_KING_ABON);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_ABON);
                   CallGuard(NPC_ABON);
                   instance->SetData(DATA_ICE_WALL_3, DONE);
                   _stepTimer = 6000;
                   _stepCount = 0;
                   _wallEntry = 0;
                   SetEscortPaused(false);
                   break;
           }
       }

       void Wall04()
       {
           switch(_stepCount)
           {
               case 0:
                   instance->SetData(DATA_SUMMONS, 3);
                   DoCast(me, SPELL_RAISE_DEAD);
                   Talk(SAY_LICH_KING_GNOUL);
                   _stepTimer = 7000;
                   ++_stepCount;
                   break;
               case 1:
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_ABON);
                   CallGuard(NPC_ABON);
                   _stepTimer = 12000;
                   ++_stepCount;
                   break;
               case 2:
                   Talk(SAY_LICH_KING_ABON);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   CallGuard(NPC_RISEN_WITCH_DOCTOR);
                   instance->SetData(DATA_ICE_WALL_4, DONE);
                   _wallEntry = 0;
                   SetEscortPaused(false);
                   ++_stepCount;
                   break;
           }
       }

       void UpdateEscortAI(const uint32 diff)
       {
           if (!instance)
                  return;

           if (instance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED || instance->GetData(DATA_LICHKING_EVENT) == FAIL)
           {
               if (!UpdateVictim())
                      return;

               DoMeleeAttackIfReady();
           }

           if (me->isInCombat() && instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
           {
                  npc_escortAI::EnterEvadeMode();
           }

           // Start chase for leader
           if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS && _startEscort != true)
           {               
                  me->RemoveAllAuras();               
                  _startEscort = true;               
                  _nonFight = true;
                  me->AttackStop();
                  me->SetSpeed(MOVE_WALK, 2.5f, true);
                  Start(false, false);
                  _stepCount = 0;
                  _stepTimer = 100;
           }

           // Leader caught, wipe
           if (Creature* lider = ((Creature*)Unit::GetUnit((*me), instance->GetData64(DATA_ESCAPE_LIDER))))
           {
               if (lider->IsWithinDistInMap(me, 2.0f) && instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
               {
                      me->setActive(false);
                      SetEscortPaused(false);
                      me->StopMoving();
                      Talk(SAY_LICH_KING_WIN);
                      me->CastSpell(me, SPELL_FURY_OF_FROSTMOURNE, false);
                      me->DealDamage(lider, lider->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
               }
           }

           if (_wallEntry == 1)
           {
               if (_stepTimer < diff)
                      Wall01();
               else
                      _stepTimer -= diff;
           }

           if (_wallEntry == 2)
           {
               if (_stepTimer < diff)
                      Wall02();
               else
                      _stepTimer -= diff;
           }

           if (_wallEntry == 3)
           {
               if (_stepTimer < diff)
                      Wall03();
               else
                      _stepTimer -= diff;
           }

           if (_wallEntry == 4)
           {
               if (_stepTimer < diff)
                      Wall04();
               else
                      _stepTimer -= diff;
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
           instance = (InstanceScript*)creature->GetInstanceScript();
           me->setActive(true);
           Reset();
       }

       InstanceScript* instance;
       uint32 _emergeTimer;
       bool _doEmerge;
       bool _doJump;
       uint64 _liderGuid;

       void Reset()
       {
           DoCast(me, SPELL_EMERGE_VISUAL);
           _emergeTimer = 4000;
           _doEmerge = false;
           _doJump = false;
       }

       void JustDied(Unit* /*killer*/)
       {
           if (!instance)
                  return;

           instance->SetData(DATA_SUMMONS, 0);
       }

       void AttackStart(Unit* who)
       {
           if (!who)
                  return;

           if (_doEmerge == false)
                  return;

           ScriptedAI::AttackStart(who);
       }

       void UpdateAI(uint32 diff)
       {
           if (!instance)
                  return;

           if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
           {
                  _liderGuid = instance->GetData64(DATA_ESCAPE_LIDER);
                  Creature* lider = ((Creature*)Unit::GetUnit((*me), _liderGuid));

               if (_doEmerge != true)
               {
                   if (_emergeTimer < diff)
                   {
                          _doEmerge = true;
                          _liderGuid = instance->GetData64(DATA_ESCAPE_LIDER);
                       if (lider)
                       {
                              DoResetThreat();                           
                              me->GetMotionMaster()->Clear();
                              me->GetMotionMaster()->MoveChase(lider);
                       }
                   }
                   else
                          _emergeTimer -= diff;
               }

               if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
               {
                   if (!_doJump && me->IsWithinDistInMap(target, 30.0f) && !me->IsWithinDistInMap(target, 5.0f))
                   {
                          _doJump = true;
                          DoCast(target, SPELL_GNOUL_JUMP);
                   }
               }
           }
           else if (instance->GetData(DATA_LICHKING_EVENT) == FAIL || instance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
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
           instance = (InstanceScript*)creature->GetInstanceScript();
           me->setActive(true);
           Reset();
       }

       InstanceScript* instance;
       uint32 _emergeTimer;
       bool _doEmerge;
       uint64 _liderGuid;
       uint32 _boltTimer;
       uint32 _boltVolleyTimer;
       uint32 _curseTimer;

       void Reset()
       {
           DoCast(me, SPELL_EMERGE_VISUAL);
           _emergeTimer = 5000;
           _boltTimer = 6000;
           _boltVolleyTimer = 15000;
           _curseTimer = 7000;
           _doEmerge = false;
       }

       void JustDied(Unit* /*killer*/)
       {
           if (!instance)
                  return;

           instance->SetData(DATA_SUMMONS, 0);

       }

       void AttackStart(Unit* who)
       {
           if (!who)
                  return;

           if (_doEmerge == false)
                  return;

           ScriptedAI::AttackStart(who);
       }

       void UpdateAI(uint32 diff)
       {
           if (!instance)
                  return;

           if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
           {
               if (_doEmerge != true)
               {
                   if (_emergeTimer < diff)
                   {
                          _doEmerge = true;
                          _liderGuid = instance->GetData64(DATA_ESCAPE_LIDER);
                       if (Creature* lider = ((Creature*)Unit::GetUnit((*me), _liderGuid)))
                       {
                              DoResetThreat();                           
                              me->GetMotionMaster()->Clear();
                              me->GetMotionMaster()->MoveChase(lider);
                       }
                   }
                   else
                          _emergeTimer -= diff;
               }

               if (_curseTimer < diff)
               {
                   if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
                          DoCast(target, SPELL_COURSE_OF_DOOM);
                          _curseTimer = urand(10000, 15000);
               } else _curseTimer -= diff;

               if (_boltTimer < diff)
               {
                   if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                           DoCast(target, SPELL_SHADOW_BOLT);
                          _boltTimer = urand(2000, 3000);
               } else _boltTimer -= diff;

               if (_boltVolleyTimer < diff)
               {
                   if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                          DoCast(target, SPELL_SHADOW_BOLT_VOLLEY);
                          _boltVolleyTimer = urand(15000, 22000);
               } 
               else 
                   _boltVolleyTimer -= diff;

           }
           else if (instance->GetData(DATA_LICHKING_EVENT) == FAIL || instance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
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
           instance = (InstanceScript*)creature->GetInstanceScript();
           me->setActive(true);
           Reset();
       }

       InstanceScript* instance;
       uint64 _liderGuid;
       bool _doWalk;
       uint32 _strikeTimer;
       uint32 _vomitTimer;

       void Reset()
       {
           _doWalk = false;
           _vomitTimer = 15000;
           _strikeTimer = 6000;
       }

       void UpdateAI(uint32 diff)
       {
           if (!instance) 
                  return;

           if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
           {
               if (_doWalk != true)
               {
                      _doWalk = true;
                      _liderGuid = instance->GetData64(DATA_ESCAPE_LIDER);
                   if (Creature* lider = ((Creature*)Unit::GetUnit((*me), _liderGuid)))
                   {
                          DoResetThreat();                       
                          me->GetMotionMaster()->Clear();
                          me->GetMotionMaster()->MoveChase(lider);
                   }
               }

               if (_strikeTimer < diff)
               {
                   if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                          DoCast(target, SPELL_ABON_STRIKE);
                          _strikeTimer = urand(7000, 9000);
               } 
               else 
                       _strikeTimer -= diff;

               if (_vomitTimer < diff)
               {
                   if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                          DoCast(target, SPELL_VOMIT_SPRAY);
                          _vomitTimer = urand(15000, 20000);
               } 
               else 
                       _vomitTimer -= diff;
           }
           else if (instance->GetData(DATA_LICHKING_EVENT) == FAIL || instance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED)
                       me->DespawnOrUnsummon();
           DoMeleeAttackIfReady();
       }

       void JustDied(Unit* /*killer*/)
       {
           if (!instance)
               return;

           instance->SetData(DATA_SUMMONS, 0);
       }
   };

   CreatureAI* GetAI(Creature* creature) const
   {
       return new npc_abonAI(creature);
   }
};

void AddSC_npc_the_lich_king_hor()
{
   new npc_the_lich_king_hor();
   new npc_raging_gnoul();
   new npc_risen_witch_doctor();
   new npc_abon();
}
