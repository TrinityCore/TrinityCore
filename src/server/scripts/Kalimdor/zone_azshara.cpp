///*
// * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
//class npc_runaway_shredder : public CreatureScript
//{
//public:
//    npc_runaway_shredder() : CreatureScript("npc_runaway_shredder") { }
//
//    CreatureAI* GetAI(Creature* pCreature) const
//    {
//        return new npc_runaway_shredderAI(pCreature);
//    }
//
//    struct npc_runaway_shredderAI : public ScriptedAI
//    {
//        npc_runaway_shredderAI(Creature *c) : ScriptedAI(c) { }
//
//        void Reset() override
//        {
//            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
//        }
//
//        void DamageTaken(Unit* /*done_by*/, uint32& damage) override
//        {
//           // if (Player* player = done_by->ToPlayer())
//           // {
//              //  if (player->hasQuest(14129))
//             //   {
//                    if (me->HealthBelowPctDamaged(5, damage))
//                    {
//                        damage = 0;
//                        me->RemoveAllAuras();
//                        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
//                        me->AddUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                        me->setFaction(35);
//                        me->CombatStop(true);
//                        me->DeleteThreatList();
//                        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
//                        Talk(0);
//                    }
//             //   }
//            //}
//        }
//
//        void UpdateAI(const uint32 /*diff*/) override
//        {
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//void AddSC_azshara()
//{
//    new npc_runaway_shredder();
//}
