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
 
#include "the_vortex_pinnacle.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

 
enum Texts
{
    SAY_AGGRO                 = 0,
    SAY_SLAY                  = 1,
    SAY_DEATH                 = 2,
    SAY_TORNADO_SHIELD        = 3
};

enum Spells
{
    SPELL_LIGHTING_BOLT       = 86331,
    SPELL_CYCLONE_SHIELD      = 86267
};

enum Events
{
    EVENT_LIGHTNING_BOLT      = 1,
    EVENT_MOVE_TORNADO        = 2,
    EVENT_TORNADO_SHIELD_PULL = 3,
    EVENT_TORNADO_SHIELD_PUSH = 4
};

Position const StartPos1 = {-702.228f, -13.440f, 635.672f, 2.338f};
Position const StartPos2 = {-719.625f, -20.499f, 635.672f, 1.427f};
Position const StartPos3 = {-736.997f, -13.297f, 635.672f, 0.715f};
Position const StartPos4 = {-744.433f, 4.024f, 635.672f, 6.260f};
Position const StartPos5 = {-737.178f, 21.330f, 635.672f, 5.561f};
Position const StartPos6 = {-719.958f, 28.493f, 635.672f, 4.689f};
Position const StartPos7 = {-702.408f, 21.482f, 635.674f, 3.923f};
Position const StartPos8 = {-695.130f, 4.116f, 635.672f, 3.173f};

class boss_grand_vizier_ertan : public CreatureScript
{
    public:
    boss_grand_vizier_ertan() : CreatureScript("boss_grand_vizier_ertan") {}
	
    struct boss_grand_vizier_ertanAI : public BossAI
    {
        boss_grand_vizier_ertanAI(Creature* creature) : BossAI(creature, DATA_GRAND_VIZIER_ERTAN) 
        {
        }
		
        void Reset() OVERRIDE
        {
            _Reset();
            Pos1 = StartPos1;
            Pos2 = StartPos2;
            Pos3 = StartPos3;
            Pos4 = StartPos4;
            Pos5 = StartPos5;
            Pos6 = StartPos6;
            Pos7 = StartPos7;
            Pos8 = StartPos8;
        }
		
        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            SummonTornados();
            ertanpos = {me->GetPositionX(), me->GetPositionY(),  me->GetPositionZ()};
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 0);
            events.ScheduleEvent(EVENT_MOVE_TORNADO, 1000);
            events.ScheduleEvent(EVENT_TORNADO_SHIELD_PULL, 20000);
        }
		
        void SummonTornados()
	{
            tornado1 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos1, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado2 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado3 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos3, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado4 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos4, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado5 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos5, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado6 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos6, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado7 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos7, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
            tornado8 = me->SummonCreature(NPC_ERTANS_VORTEX, Pos8, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
        }			
		
        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
            Talk(SAY_DEATH);
        }
		
        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER) Talk(SAY_SLAY);         
        }
		
        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim()) return;
			
            events.Update(diff);
			
            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_LIGHTNING_BOLT:
                    //DoCast((Unit*)me->GetTarget(), SPELL_LIGHTING_BOLT,true);  // crash
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 1500);
                    break;
                case EVENT_MOVE_TORNADO:
                    Aux = Pos1;
                    Pos1 = Pos2;
                    tornado1->GetMotionMaster()->MovePoint(1, Pos1);
                    Pos2 = Pos3;
                    tornado2->GetMotionMaster()->MovePoint(2, Pos2);
                    Pos3 = Pos4;
                    tornado3->GetMotionMaster()->MovePoint(3, Pos3);
                    Pos4 = Pos5;
                    tornado4->GetMotionMaster()->MovePoint(4, Pos4);
                    Pos5 = Pos6;
                    tornado5->GetMotionMaster()->MovePoint(5, Pos5);
                    Pos6 = Pos7;
                    tornado6->GetMotionMaster()->MovePoint(6, Pos6);
                    Pos7 = Pos8;
                    tornado7->GetMotionMaster()->MovePoint(7, Pos7);
                    Pos8 = Aux;
                    tornado8->GetMotionMaster()->MovePoint(8, Pos8);
                    events.ScheduleEvent(EVENT_MOVE_TORNADO, 6000);
                    break;
                case EVENT_TORNADO_SHIELD_PULL:
                    Talk(SAY_TORNADO_SHIELD);
                    tornado1->GetMotionMaster()->MovePoint(1, ertanpos);
                    tornado2->GetMotionMaster()->MovePoint(2, ertanpos);
                    tornado3->GetMotionMaster()->MovePoint(3, ertanpos);
                    tornado4->GetMotionMaster()->MovePoint(4, ertanpos);
                    tornado5->GetMotionMaster()->MovePoint(5, ertanpos);
                    tornado6->GetMotionMaster()->MovePoint(6, ertanpos);
                    tornado7->GetMotionMaster()->MovePoint(7, ertanpos);
                    tornado8->GetMotionMaster()->MovePoint(8, ertanpos);            
                    events.ScheduleEvent(EVENT_TORNADO_SHIELD_PUSH, 10000);
                    events.ScheduleEvent(EVENT_MOVE_TORNADO, 25000);
                    break;
                case EVENT_TORNADO_SHIELD_PUSH:
                    tornado1->GetMotionMaster()->MovePoint(1, Pos1);
                    tornado2->GetMotionMaster()->MovePoint(2, Pos2);
                    tornado3->GetMotionMaster()->MovePoint(3, Pos3);
                    tornado4->GetMotionMaster()->MovePoint(4, Pos4);
                    tornado5->GetMotionMaster()->MovePoint(5, Pos5);
                    tornado6->GetMotionMaster()->MovePoint(6, Pos6);
                    tornado7->GetMotionMaster()->MovePoint(7, Pos7);
                    tornado8->GetMotionMaster()->MovePoint(8, Pos8);
                    events.ScheduleEvent(EVENT_TORNADO_SHIELD_PULL, 25000);
	            break;
                }
            }
        }
		
        private:
        Creature *tornado1;
        Creature *tornado2;
        Creature *tornado3;
        Creature *tornado4;
        Creature *tornado5;
        Creature *tornado6;
        Creature *tornado7;
        Creature *tornado8;
		
        Position Pos1;
        Position Pos2;
        Position Pos3;
        Position Pos4;
        Position Pos5;
        Position Pos6;
        Position Pos7;
        Position Pos8;
        Position Aux;

        Position ertanpos;
    };
	
    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetTheVortexPinnacleAI<boss_grand_vizier_ertanAI>(creature);
    }
};

class npc_ertans_vortex : public CreatureScript
{
    public:
    npc_ertans_vortex() : CreatureScript("npc_ertans_vortex") {}
	
    struct npc_ertans_vortexAI  : public ScriptedAI
    {
        npc_ertans_vortexAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() OVERRIDE
	{
	    DoCast(me, SPELL_CYCLONE_SHIELD, true);
        }
		
        void UpdateAI(uint32 diff) OVERRIDE
        {
            if(me->GetInstanceScript()->GetBossState(DATA_GRAND_VIZIER_ERTAN) == NOT_STARTED || me->GetInstanceScript()->GetBossState(DATA_GRAND_VIZIER_ERTAN) == DONE) me->DespawnOrUnsummon(); 
        }
    };
	
    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ertans_vortexAI(creature);
    }
};

void AddSC_boss_grand_vizier_ertan()
{
    new boss_grand_vizier_ertan();
    new npc_ertans_vortex();
}
