///*
// * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
// * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
// /* ScriptData
// SDName: Example_Escort
// SD%Complete: 100
// SDComment: Script used for testing escortAI
// SDCategory: Script Examples
// EndScriptData */
//
//#include "PrecompiledHeaders/ScriptPCH.h"
//
//#define START            1
//
//enum eEnums
//{
//    NPC_PATCHWERK = 31099,
//
//    SAY_AGGRO = 0,
//    SAY_DEATH
//};
//
//class Loskutik : public CreatureScript
//{
//public:
//
//    Loskutik()
//        : CreatureScript("Loskutik")
//    {
//    }
//
//    struct LoskutikAI : public ScriptedAI
//    {
//        LoskutikAI(Creature* pCreature) : ScriptedAI(pCreature) {}
//
//        void EnterCombat(Unit* /*pWho*/) override
//        {
//            Talk(SAY_AGGRO);
//            if (me->getVictim())
//                me->AttackerStateUpdate(me->getVictim());
//        }
//
//        void EnterEvadeMode() override
//        {
//            me->DespawnOrUnsummon();
//        }
//
//        void JustDied(Unit* pKiller) override
//        {
//            Talk(SAY_DEATH);
//            me->DespawnOrUnsummon();
//
//            if (pKiller->IsPlayer())
//                pKiller->ToPlayer()->KilledMonsterCredit(31099);
//        }
//
//        void UpdateAI(uint32 uiDiff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new LoskutikAI(creature);
//    }
//};
//
//class Loskutik_Start : public CreatureScript
//{
//public:
//    Loskutik_Start() : CreatureScript("Loskutik_Start") {}
//
//    struct Loskutik_StartAI : public ScriptedAI
//    {
//        // CreatureAI functions
//        Loskutik_StartAI(Creature* creature) : ScriptedAI(creature) {}
//
//        void Reset() override {}
//
//        void JustDied(Unit* /*who*/) override {}
//
//        void UpdateAI(uint32 uiDiff) override {}
//    };
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
//        player->PrepareGossipMenu(creature, 0);
//        if (Creature* e = creature->FindNearestCreature(31099, 60.0f))
//            return true;
//
//        if (player->getClass() == CLASS_DEATH_KNIGHT)
//            player->ADD_GOSSIP_ITEM(0, "Start event Patchwerk!", GOSSIP_SENDER_MAIN, START);
//
//        player->SendPreparedGossip(creature);
//
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
//    {
//        if (sender != GOSSIP_SENDER_MAIN)
//        {
//            player->CLOSE_GOSSIP_MENU();
//            return true;
//        }
//
//        switch (action)
//        {
//        case START:
//            player->CLOSE_GOSSIP_MENU();
//            creature->SummonCreature(31099, 2460.29f, -5593.26f, 414.122f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
//            break;
//        default:
//            return false;                                   // nothing defined      -> trinity core handling
//        }
//        return true;
//    }
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new Loskutik_StartAI(creature);
//    }
//};
//
//void AddSC_Loskutik()
//{
//    new Loskutik();
//    new Loskutik_Start();
//}
