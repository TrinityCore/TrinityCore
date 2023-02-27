///*
//* Copyright 2021 FuzionCore Project
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
///* Script Data Start
//SDName: 
//SDAuthor: Frozen
//SD%Complete: %
//SDComment: still working on structure.
//Script Data End */
//
//#include "ScriptMgr.h"
//#include "Player.h"
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "InstanceScript.h"
//#include "SpellAuras.h"
//#include "zone_the_maw"
//#include "zone_Sanctum_of_Domination.h"
//#include "Sanctum_of_Domination.h"
//
//
//
//enum Spells
//{
//    SPELL_ = 319619,
//    SPELL_ = 319636, //23341, 19347
//    SPELL_ = 320834,
//    SPELL_ = 319627,
//    SPELL_ = 334199,
//    SPELL_ = 321948,
//    SPELL_ = 342961,
//    SPELL_ = 320230,
//    SPELL_ = 320232,
//    SPELL_ = 342962,
//};
//
////179390
//struct Boss_Fatescribe_Roh_Kalo : public BossAI
//{
//    Boss_Fatescribe_Roh_Kalo(Creature* c) : BossAI(c, DATA_FATESCRIBE_ROH_KALO) { }
//
//    void Reset() override
//    {
//        BossAI::Reset();
//    }
//
//    void EnterCombat(Unit* /*who*/) override
//    {
//        _EnterCombat();
//        events.ScheduleEvent(SPELL_, 0s);
//        events.ScheduleEvent(SPELL_, 0s);
//        events.ScheduleEvent(SPELL_, 0s);
//    }
//
//    void OnSpellFinished(SpellInfo const* spellInfo) override
//    {
//        switch (spellInfo->Id)
//        {
//        case SPELL_:
//        {
//            std::list<Player*> targetList;
//            me->GetPlayerListInGrid(targetList, 100.0f);
//            for (Player* targets : targetList)
//            {
//                me->CastSpell(targets->GetPosition(), SPELL_, true);
//            }
//            break;
//        }
//
//        case SPELL_:
//        {
//            std::list<AreaTrigger*> atList;
//            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_, 100.0f);
//            for (AreaTrigger* at : atList)
//            {
//                if (at->GetPositionZ() < -45.0f)
//                {
//                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_, true);
//                    at->Remove();
//                }
//            }
//            std::list<Player*> targetList;
//            me->GetPlayerListInGrid(targetList, 100.0f);
//            for (Player* targets : targetList)
//            {
//                if (targets->GetPositionZ() < -45.0f && !targets->HasAura(SPELL_))
//                    me->CastSpell(targets, SPELL_, true);
//            }
//            break;
//        }
//        }    
//    }
//
//    void ExecuteEvent(uint32 eventId) override
//    {
//        switch (eventId)
//        {
//        case SPELL_:
//            me->CastSpell(nullptr, SPELL_, true);
//            events.Repeat(20s, 25s); 
//            break;
//
//        case SPELL_:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0F, true))
//            {
//                me->CastSpell(target, SPELL_, true);
//                me->AddAura(SPELL_, target);
//            }
//            events.Repeat(0s);
//            break;
//
//        case SPELL_:
//            me->CastSpell(nullptr, SPELL_, false);
//            events.Repeat(0s);
//            break;
//        }
//    }
//
//    void JustReachedHome() override
//    {
//        _JustReachedHome();
//        me->RemoveAllAreaTriggers();
//    }
//
//    void EnterEvadeMode(EvadeReason /*why*/) override
//    {
//        me->RemoveAllAreaTriggers();
//        _DespawnAtEvade();
//    }
//
//    void JustDied(Unit* /*who*/) override
//    {
//        _JustDied();
//        me->RemoveAllAreaTriggers();
//    }
//};
//
//
//
//57.4 70.2
