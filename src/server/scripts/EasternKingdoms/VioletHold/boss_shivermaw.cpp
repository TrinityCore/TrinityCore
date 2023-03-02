///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "violet_hold_assault.h"
//
//enum Says
//{
//    SAY_WARNING = 0,
//};
//
//enum Spells
//{
//    SPELL_FROST_BREATH = 201379,
//    SPELL_RELENTLESS_STORM = 201672,
//    SPELL_RELENTLESS_STORM_TRIG = 201848, //26 cast count
//    SPELL_RELENTLESS_STORM_SEARCH = 201865, //Target search
//    SPELL_RELENTLESS_STORM_DMG = 201852,
//    SPELL_RELENTLESS_STORM_AT_1 = 201643,
//    SPELL_RELENTLESS_STORM_AT_2 = 201652,
//    SPELL_TAIL_SWEEP = 201354,
//    SPELL_WING_BUFFET = 201355,
//    SPELL_ICE_BOMB = 201960,
//    SPELL_ICE_BOMB_DMG_AOE = 201961,
//    SPELL_FROZEN = 202037,
//
//    //Heroic+
//    SPELL_FRIGID_WINDS = 202062,
//};
//
//enum eEvents
//{
//    EVENT_FROST_BREATH = 1,
//    EVENT_RELENTLESS_STORM = 2,
//    EVENT_TAIL_SWEEP = 3,
//    EVENT_WING_BUFFET = 4,
//    EVENT_FLY = 5,
//    EVENT_ICE_BOMB = 6,
//    EVENT_GROUND = 7,
//    EVENT_FRIGID_WINDS = 8
//};
//
////101951
//class boss_shivermaw : public CreatureScript
//{
//public:
//    boss_shivermaw() : CreatureScript("boss_shivermaw") {}
//
//    struct boss_shivermawAI : public BossAI
//    {
//        boss_shivermawAI(Creature* creature) : BossAI(creature, DATA_SHIVERMAW)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//            removeloot = false;
//        }
//
//        bool removeloot;
//
//        void Reset() override
//        {
//            _Reset();
//            me->SetCanFly(true);
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//            //49:22
//        {
//            _JustEngagedWith();
//
//            events.RescheduleEvent(EVENT_FROST_BREATH, 5000); //49:27, 49:53, 50:28
//            events.RescheduleEvent(EVENT_RELENTLESS_STORM, 9000); //49:31, 49:45, 50:32, 50:46, 51:33, 51:47
//            events.RescheduleEvent(EVENT_TAIL_SWEEP, 17000); //49:39, 49:57
//            events.RescheduleEvent(EVENT_FLY, 40000);
//
//            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
//                events.RescheduleEvent(EVENT_FRIGID_WINDS, 30000);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            _JustDied();
//
//            if (removeloot)
//                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_RELENTLESS_STORM)
//            {
//                Position pos;
//
//                for (uint8 i = 0; i < 26; i++)
//                {
//                    caster->GetRandomNearPosition(urand(1, 50));
//                    caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_RELENTLESS_STORM_TRIG, true);
//                }
//            }
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_RELENTLESS_STORM_SEARCH)
//                DoCast(SPELL_RELENTLESS_STORM_DMG);
//
//            if (spell->Id == SPELL_ICE_BOMB_DMG_AOE)
//                if (target->GetPositionZ() < 82.0f)
//                    DoCast(target, SPELL_FROZEN, true);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type != POINT_MOTION_TYPE)
//                return;
//
//            if (id == 2)
//                events.RescheduleEvent(EVENT_ICE_BOMB, 500);
//
//            if (id == 3)
//            {
//                me->SetCanFly(false);
//                me->SetReactState(REACT_AGGRESSIVE);
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (action == ACTION_REMOVE_LOOT)
//                removeloot = true;
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_FROST_BREATH:
//                    DoCast(SPELL_FROST_BREATH);
//                    events.RescheduleEvent(EVENT_FROST_BREATH, 26000);
//                    break;
//                case EVENT_RELENTLESS_STORM:
//                    DoCast(SPELL_RELENTLESS_STORM);
//                    events.RescheduleEvent(EVENT_RELENTLESS_STORM, 14000);
//                case EVENT_TAIL_SWEEP:
//                    DoCastVictim(SPELL_TAIL_SWEEP);
//                    events.RescheduleEvent(EVENT_TAIL_SWEEP, 18000);
//                    events.RescheduleEvent(EVENT_WING_BUFFET, 3000); //49:42, 50:00, 50:43
//                    break;
//                case EVENT_WING_BUFFET:
//                    DoCastVictim(SPELL_WING_BUFFET);
//                    break;
//                case EVENT_FLY:
//                    me->AttackStop();
//                    me->SetCanFly(true);
//                    me->GetMotionMaster()->MovePoint(2, 4632.15f, 4016.52f, 112.51f, false); //Fly point
//                    events.RescheduleEvent(EVENT_FLY, 60000);
//                    break;
//                case EVENT_ICE_BOMB:
//                    DoCast(SPELL_ICE_BOMB);
//                 //   ZoneTalk(SAY_WARNING, nullptr);
//                    events.RescheduleEvent(EVENT_GROUND, 3000);
//                    break;
//                case EVENT_GROUND:
//                    events.DelayEvents(3000);
//                    me->GetMotionMaster()->MovePoint(3, me->GetPositionX(), me->GetPositionY(), 78.0f);
//                    break;
//                case EVENT_FRIGID_WINDS:
//                    DoCast(SPELL_FRIGID_WINDS);
//                    events.RescheduleEvent(EVENT_FRIGID_WINDS, 60000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_shivermawAI(creature);
//    }
//};
//
////102301
//class npc_shivermaw_ice_block : public CreatureScript
//{
//public:
//    npc_shivermaw_ice_block() : CreatureScript("npc_shivermaw_ice_block") {}
//
//    struct npc_shivermaw_ice_blockAI : public ScriptedAI
//    {
//        npc_shivermaw_ice_blockAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetUnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
//        }
//
//        ObjectGuid sGuid;
//
//        void Reset() override
//        {
//            sGuid.Clear();
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            sGuid = summoner->GetGUID();
//        }
//
//        void JustDied(Unit* killer) override
//        {
//            killer->RemoveAurasDueToSpell(SPELL_FROZEN);
//           
//            me->DespawnOrUnsummon();
//        }
//
//        void UpdateAI(uint32 diff) override {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_shivermaw_ice_blockAI(creature);
//    }
//};
//
//void AddSC_boss_shivermaw()
//{
//    new boss_shivermaw();
//    new npc_shivermaw_ice_block();
//}
