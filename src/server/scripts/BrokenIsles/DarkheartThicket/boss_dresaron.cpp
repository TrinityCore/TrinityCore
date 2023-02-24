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
//#include "darkheart_thicket.h"
//
//enum Spells
//{
//    SPELL_BREATH_OF_CORRUPTION = 199329,
//    SPELL_BREATH_OF_CORRUPTION_SUM = 199332,
//    SPELL_BREATH_OF_CORRUPTION_DMG = 191325,
//    SPELL_EARTHSHAKING_ROAR = 199389,
//    SPELL_DOWN_DRAFT = 199345,
//
//    //Egg
//    SPELL_SUM_BIRTH_WHELPLING_1 = 199304, //Npc 100528 - unuseble?
//    SPELL_SUM_BIRTH_WHELPLING_2 = 199313, //Npc 101074
//    //Emerald Egg
//    SPELL_HATESPAWN_ABOMINATION = 220921,
//
//    //Whelpling
//    SPELL_HATESPAWN_DETONATION = 212797,
//};
//
//enum eEvents
//{
//    EVENT_BREATH_OF_CORRUPTION = 1,
//    EVENT_EARTHSHAKING_ROAR = 2,
//    EVENT_DOWN_DRAFT = 3,
//};
//
//enum Misc
//{
//    ABOMINATION_KILLED = 1,
//    ACTION_1,
//};
//
////99200
//class boss_dresaron : public CreatureScript
//{
//public:
//    boss_dresaron() : CreatureScript("boss_dresaron") {}
//
//    struct boss_dresaronAI : public BossAI
//    {
//        boss_dresaronAI(Creature* creature) : BossAI(creature, DATA_DRESARON) {}
//
//        bool abomination;
//
//        void Reset() override
//        {
//            _Reset();
//            TreshRestore(false);
//            abomination = false;
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            _JustEngagedWith();
//
//            events.RescheduleEvent(EVENT_BREATH_OF_CORRUPTION, 7000);
//            events.RescheduleEvent(EVENT_EARTHSHAKING_ROAR, 14000);
//            events.RescheduleEvent(EVENT_DOWN_DRAFT, 20000);
//            abomination = false;
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            _JustDied();
//            TreshRestore(true);
//        }
//
//        void DoAction(int32 const action) override
//        {
//            switch (action)
//            {
//            case ACTION_1:
//                abomination = true;
//                break;
//            }
//        }
//
//        uint32 GetData(uint32 type) const override
//        {
//            if (type == ABOMINATION_KILLED)
//                return abomination ? 1 : 0;
//            return 0;
//        }
//
//        void TreshRestore(bool encounterEnd)
//        {
//            std::list<Creature*> creList;
//            GetCreatureListWithEntryInGrid(creList, me, NPC_CORRUPTED_DRAGON_EGG, 100.0f);
//            GetCreatureListWithEntryInGrid(creList, me, NPC_HATESPAWN_WHELPLING, 100.0f);
//            GetCreatureListWithEntryInGrid(creList, me, NPC_EMERALD_EGG, 100.0f);
//            GetCreatureListWithEntryInGrid(creList, me, NPC_HATESPAWN_ABOMINATION, 100.0f);
//            for (auto const& tresh : creList)
//            {
//                if (tresh->GetEntry() == NPC_CORRUPTED_DRAGON_EGG || tresh->GetEntry() == NPC_EMERALD_EGG)
//                {
//                    if (encounterEnd)
//                        tresh->DespawnOrUnsummon();
//                    else
//                    {
//                        if (!tresh->IsAlive())
//                        {
//                            tresh->RemoveCorpse();
//                            tresh->Respawn();
//                        }
//                    }
//                }
//                else
//                    tresh->DespawnOrUnsummon();
//            }
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
//                case EVENT_BREATH_OF_CORRUPTION:
//                    DoCast(SPELL_BREATH_OF_CORRUPTION);
//                    events.RescheduleEvent(EVENT_BREATH_OF_CORRUPTION, 27000);
//                    break;
//                case EVENT_EARTHSHAKING_ROAR:
//                    DoCast(SPELL_EARTHSHAKING_ROAR);
//                    events.RescheduleEvent(EVENT_EARTHSHAKING_ROAR, 19000);
//                    break;
//                case EVENT_DOWN_DRAFT:
//                    DoCast(SPELL_DOWN_DRAFT);
//                    events.RescheduleEvent(EVENT_DOWN_DRAFT, 30000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_dresaronAI(creature);
//    }
//};
//
////100533, 101072
//class npc_dresaron_corrupted_dragon_egg : public CreatureScript
//{
//public:
//    npc_dresaron_corrupted_dragon_egg() : CreatureScript("npc_dresaron_corrupted_dragon_egg") {}
//
//    struct npc_dresaron_corrupted_dragon_eggAI : public ScriptedAI
//    {
//        npc_dresaron_corrupted_dragon_eggAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//            me->SetUnitFlags(UNIT_FLAG_STUNNED);
//        }
//
//        InstanceScript* instance;
//        bool destroed;
//
//        void Reset() override
//        {
//            destroed = false;
//        }
//
//        void MoveInLineOfSight(Unit* who) override
//        {
//            if (who->GetTypeId() != TYPEID_PLAYER || who->ToPlayer()->IsGameMaster())
//                return;
//
//            if (instance->GetBossState(DATA_DRESARON) != IN_PROGRESS)
//                return;
//
//            if ((me->GetDistance(who) < 3.0f) && !destroed)
//            {
//                destroed = true;
//                DoCast(me, SPELL_SUM_BIRTH_WHELPLING_2, true);
//                me->Kill(me,me);
//            }
//        }
//
//        void UpdateAI(uint32 diff) override {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_dresaron_corrupted_dragon_eggAI(creature);
//    }
//};
//
////101078
//class npc_dresaron_acid_breath_stalker : public CreatureScript
//{
//public:
//    npc_dresaron_acid_breath_stalker() : CreatureScript("npc_dresaron_acid_breath_stalker") {}
//
//    struct npc_dresaron_acid_breath_stalkerAI : public ScriptedAI
//    {
//        npc_dresaron_acid_breath_stalkerAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner)
//        {
//            summoner->CastSpell(me, SPELL_BREATH_OF_CORRUPTION_DMG, false);
//        }
//
//        void UpdateAI(uint32 diff) override {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_dresaron_acid_breath_stalkerAI(creature);
//    }
//};
//
////101074
//class npc_dresaron_hatespawn_whelpling : public CreatureScript
//{
//public:
//    npc_dresaron_hatespawn_whelpling() : CreatureScript("npc_dresaron_hatespawn_whelpling") {}
//
//    struct npc_dresaron_hatespawn_whelplingAI : public ScriptedAI
//    {
//        npc_dresaron_hatespawn_whelplingAI(Creature* creature) : ScriptedAI(creature) {}
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            DoZoneInCombat(me, 60.0f);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
//                DoCast(me, SPELL_HATESPAWN_DETONATION, true);
//        }
//
//        void UpdateAI(uint32 diff) override
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
//        return new npc_dresaron_hatespawn_whelplingAI(creature);
//    }
//};
//
//// achievement egg
//class npc_dresaron_emerald_dragon_egg : public CreatureScript
//{
//public:
//    npc_dresaron_emerald_dragon_egg() : CreatureScript("npc_dresaron_emerald_dragon_egg") {}
//
//    struct npc_dresaron_emerald_dragon_eggAI : public ScriptedAI
//    {
//        npc_dresaron_emerald_dragon_eggAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//            me->SetUnitFlags(UNIT_FLAG_STUNNED);
//        }
//
//        InstanceScript* instance;
//        bool destroed;
//
//        void Reset() override
//        {
//            destroed = false;
//        }
//
//        void MoveInLineOfSight(Unit* who) override
//        {
//            if (who->GetTypeId() != TYPEID_PLAYER || who->ToPlayer()->IsGameMaster())
//                return;
//
//            if (instance->GetBossState(DATA_DRESARON) != IN_PROGRESS)
//                return;
//
//            if ((me->GetDistance(who) < 2.0f) && !destroed)
//            {
//                destroed = true;
//                DoCast(me, SPELL_HATESPAWN_ABOMINATION, true);
//                me->Kill(me,me);
//            }
//        }
//
//        void UpdateAI(uint32 diff) override {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_dresaron_emerald_dragon_eggAI(creature);
//    }
//};
//
////111008 achievement add
//class npc_dresaron_hatespawn_abomination : public CreatureScript
//{
//public:
//    npc_dresaron_hatespawn_abomination() : CreatureScript("npc_dresaron_hatespawn_abomination") {}
//
//    struct npc_dresaron_hatespawn_abominationAI : public ScriptedAI
//    {
//        npc_dresaron_hatespawn_abominationAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//        }
//
//        InstanceScript* instance;
//
//        void Reset() override {}
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE)
//                if (Creature* dresaron = instance->instance->GetCreature(instance->GetGuidData(NPC_DRESARON)))
//                    dresaron->GetAI()->DoAction(ACTION_1);
//        }
//
//        void UpdateAI(uint32 diff) override
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
//        return new npc_dresaron_hatespawn_abominationAI(creature);
//    }
//};
//
//class achievement_egg_cellent : public AchievementCriteriaScript
//{
//public:
//    achievement_egg_cellent() : AchievementCriteriaScript("achievement_egg_cellent") { }
//
//    bool OnCheck(Player* /*player*/, Unit* target) override
//    {
//        if (!target)
//            return false;
//
//        if (Creature* boss = target->ToCreature())
//            if (boss->AI()->GetData(ABOMINATION_KILLED))
//                return true;
//
//        return false;
//    }
//};
//
//void AddSC_boss_dresaron()
//{
//    new boss_dresaron();
//    new npc_dresaron_corrupted_dragon_egg();
//    new npc_dresaron_acid_breath_stalker();
//    new npc_dresaron_hatespawn_whelpling();
//    new npc_dresaron_emerald_dragon_egg();
//    new npc_dresaron_hatespawn_abomination();
//    new achievement_egg_cellent();
//}
