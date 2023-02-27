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
//#include "ScriptMgr.h"
//#include "Player.h"
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraEffects.h"
//#include "Map.h"
//#include "necrotic_wake.h"
//#include "npc_Bastion"
//#include "objects_Bastion"
//
//enum Spells
//{
//	//Surgeon Stitchflesh
//	SPELL_NOXIOUS_FOG      = 327100,
//	SPELL_EMBALMING_ICHOR  = 327664,
//	SPELL_STITCHNEEDLE     = 320200,
//	SPELL_SEVER_FLESH      = 334488,
//	SPELL_MORBID_FIXATION  = 343555,
//	SPELL_ESCAPE           = 320359,
//	//Stitchflesh's Creation
//    SPELL_MEAT_HOOK        = 320208,322548,322681,
//    SPELL_AWAKEN_CREATION  = 320358,
//    SPELL_FESTERING_ROT    = 348170,
//    SPELL_LETHARGY         = 326868,
//    SPELL_MEERAHS_JUKEBOX  = 288865,
//    SPELL_MUTILATE         = 320376,
//    SPELL_SHATTERED_PSYCHE = 344663,
//};
//
//enum Creatures
//{
//	NPC_SURGEON_STITCHFLESH   = 166882,
//	NPC_STITCHFLESHS_CREATION = 164578,
//	NPC_SURGEON_STITCHFLESH   = 166882,
//	NPC_STITCHING_ASSISTANT   = 173044,
//	NPC_SEPARATION_ASSISTANT  = 167731,
//	NPC_GOREGRIND_BITS        = 163622,
//	NPC_GOREGRIND             = 163621,
//	NPC_ROTSPEW               = 163620,
//	NPC_ROTSPEW_LEFTOVERS     = 163623,
//}
//
//enum Texts
//{
//	TEXT_SURGEON_STITCHFLESH_SAY : "Come, my Assistants! these raw materials are in need of processing! "
//	TEXT_SURGEON_STITCHFLESH_SAY : "Incompentent oafs! Goregrind! try not to damage those limbs whilst you thear them off."
//	TEXT_SURGEON_STITCHFLESH_SAY : "How vexing.Rotspew! Get to work,and don't fail me like your predecesor!"
//	TEXT_SURGEON_STITCHFLESH_SAY : "No! Now I have to rebuild those two from scratch! It seems I must take matters intro my own hands."
//	TEXT_SURGEON_STITCHFLESH_YELLS : "So much materials to work with!"
//	TEXT_SURGEON_STITCHFLESH_YELLS : "I must preserve your parts for later!"
//	TEXT_SURGEON_STITCHFLESH_YELLS : "Have you no respect for craftsmanship?!"
//	TEXT_SURGEON_STITCHFLESH_YELLS : "I'm awfully proud of this one!"
//	TEXT_SURGEON_STITCHFLESH_YELLS : "That one was my favorite!"
//	TEXT_SURGEON_STITCHFLESH_YELLS : "Imbecille! I'm the one who made you!"
//    TEXT_SURGEON_STITCHFLESH_YELLS : "My constructs can handle you on their own."
//    TEXT_SURGEON_STITCHFLESH_YELLS : "My greatest...was yet...to come..."
//    
//}
//
////162691
//struct surgeon_stitchflesh : public BossAI
//{
//    surgeon_stitchflesh(Creature* creature) : BossAI(creature, DATA_SURGEON_STITCHFLESH) { }
//
//    void Reset() override
//    {
//        BossAI::Reset();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        Talk(0);
//        if (auto* encounterDoor = me->FindNearestGameObject(GO_SURGEON_STITCHFLESH_EXIT, 100.0f))
//            encounterDoor->SetGoState(GO_STATE_READY);
//        events.ScheduleEvent(SPELL_NOXIOUS_FOG, 3s);
//        events.ScheduleEvent(SPELL_EMBALMING_ICHOR, 5s);
//        events.ScheduleEvent(SPELL_STITCHNEEDLE, 10s);
//        events.ScheduleEvent(SPELL_SPELL_SEVER_FLESH, 3s);
//        events.ScheduleEvent(SPELL_MORBID_FIXATION, 3s);
//        events.ScheduleEvent(SPELL_ESCAPE, 3s);
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override 
//    { 
//        switch (spellInfo->Id)
//        {
//        case SPELL_NOXIOUS_FOG:
//            me->AddAura(SPELL_NOXIOUS_FOG, target);
//            break;
//        case SPELL_EMBALMING_ICHOR:
//            me->AddAura(SPELL_EMBALMING_ICHOR, target);
//            break;
//        case SPELL_STITCHNEEDLE:
//            me->AddAura(SPELL_STITCHNEEDLE, target);
//            break;
//        case SPELL_SPELL_SEVER_FLESH:
//            me->AddAura(SPELL_SPELL_SEVER_FLESH, target);
//            break;
//        case SPELL_MORBID_FIXATION:
//            me->AddAura(SPELL_MORBID_FIXATION, target);
//            break;
//        case SPELL_ESCAPE:
//            me->AddAura(SPELL_ESCAPE, target);
//            break;                   
//        }
//    }
//
//    void ExecuteEvent(uint32 eventId) override
//    {
//        switch (eventId)
//        {
//        case SPELL_NOXIOUS_FOG:
//            DoCastVictim(SPELL_NOXIOUS_FOG, false);
//            events.Repeat(15s);
//            break;
//        case SPELL_EMBALMING_ICHOR:
//            DoCastVictim(SPELL_EMBALMING_ICHOR, false);
//            events.Repeat(15s);
//            break;
//        case SPELL_STITCHNEEDLE:
//            DoCastVictim(SPELL_STITCHNEEDLE, false);
//            events.Repeat(15s);
//            break;
//        case SPELL_SEVER_FLESH:
//            DoCastVictim(SPELL_SPELL_SEVER_FLESH, false);
//            events.Repeat(15s);
//            break;
//        case SPELL_MORBID_FIXATION:
//            DoCastVictim(SPELL_MORBID_FIXATION, false);
//            events.Repeat(15s);
//            break;
//        case SPELL_ESCAPE:
//            DoCastVictim(SPELL_ESCAPE, false);
//            events.Repeat(15s);
//            break;
//    };                           
//        case SPELL_NOXIOUS_FOG:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                me->CastSpell(target, SPELL_NOXIOUS_FOG), false;
//                AddTimedDelayedOperation(2600, [this, target]() -> void
//                {
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->CastSpell(target, SPELL_NOXIOUS_FOG, true);
//                    }
//                });
//            }
//            events.Repeat(20s);
//            break;
//        case SPELL_EMBALMING_ICHOR:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                me->CastSpell(target, SPELL_EMBALMING_ICHOR), false;
//                AddTimedDelayedOperation(2600, [this, target]() -> void
//                {
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->CastSpell(target, SPELL_EMBALMING_ICHOR, true);
//                    }
//                });
//            }
//            events.Repeat(20s);
//            break;
//        case SPELL_STITCHNEEDLE:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                me->CastSpell(target, SPELL_STITCHNEEDLE), false;
//                AddTimedDelayedOperation(2600, [this, target]() -> void
//                {
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->CastSpell(target, SPELL_STITCHNEEDLE, true);
//                    }
//                });
//            }
//            events.Repeat(20s);
//            break;
//        case SPELL_SEVER_FLESH:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                me->CastSpell(target, SPELL_SEVER_FLESH), false;
//                AddTimedDelayedOperation(2600, [this, target]() -> void
//                {
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->CastSpell(target, SPELL_SEVER_FLESH, true);
//                    }
//                });
//            }
//            events.Repeat(20s);
//            break;
//        case SPELL_MORBID_FIXATION:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                me->CastSpell(target, SPELL_MORBID_FIXATION), false;
//                AddTimedDelayedOperation(2600, [this, target]() -> void
//                {
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->CastSpell(target, SPELL_MORBID_FIXATION, true);
//                    }
//                });
//            }
//            events.Repeat(20s);
//            break;
//        case SPELL_ESCAPE:
//            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                me->CastSpell(target, SPELL_ESCAPE), false;
//                AddTimedDelayedOperation(2600, [this, target]() -> void
//                {
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->CastSpell(target, SPELL_ESCAPE, true);
//                    }
//                });
//            }
//            events.Repeat(20s);
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
//    void JustDied(Unit* /*who*/) override
//    {
//        _JustDied();
//        Talk(1);
//        me->RemoveAllAreaTriggers();
//        if (auto* encounterDoor = me->FindNearestGameObject(GO_SURGEON_STITCHFLESH_EXIT, 100.0f))
//            encounterDoor->SetGoState(GO_STATE_ACTIVE);
//        break;
//    };
//};
//
////23443
//struct at_boss_surgeon_stitchfleshAI : public AreaTriggerAI
//{
//    at_fetid_gas(AreaTrigger* at) : AreaTriggerAI(at) { }
//
//    void OnUnitEnter(Unit* target) override
//    {
//        if (!target->IsPlayer())
//            return;
//
//        if (!target->HasAura(SPELL_FETID_GAS_AURA))
//            at->GetCaster()->AddAura(SPELL_FETID_GAS_AURA, target);
//    }
//
//    void OnUnitExit(Unit* target) override
//    {
//        if (target->HasAura(SPELL_FETID_GAS_AURA))
//            target->RemoveAura(SPELL_FETID_GAS_AURA);
//    }
//};
//
////164702
//struct npc_boss_surgeon_stitchflesh : public ScriptedAI
//{
//    npc_carrion_worm_nw(Creature* creature) : ScriptedAI(c) { }
//    
//    void Reset() override
//    {
//        ScriptedAI::Reset();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _events.ScheduleEvent(SPELL_BLOOD_GORGE, 3s);
//    }
//
//    void ExecuteEvent(uint32 eventId)// override
//    {
//        if (Aura const* gorge = me->GetAura(SPELL_BLOOD_GORGE_BUFF))
//            if (gorge->GetStackAmount() == 3)
//            {
//                me->RemoveAurasDueToSpell(SPELL_BLOOD_GORGE_BUFF);
//                me->CastSpell(nullptr, SPELL_CARRION_ERUPTION, false);
//            }
//
//        switch (eventId)
//        {
//        case SPELL_BLOOD_GORGE:
//            DoCastVictim(SPELL_BLOOD_GORGE, false);
//            me->AddAura(SPELL_BLOOD_GORGE_BUFF, me);
//            _events.Repeat(10s);
//            break;
//        }
//    }
//
//    void JustDied(Unit* /*who*/) override
//    {
//        if (IsMythic())
//            me->CastSpell(nullptr, SPELL_FETID_GAS_CREATE_AT, true);
//    }
//
//private:
//    EventMap _events;
//};
//
//void boss_surgeon_stitchflesh()
//{
//    RegisterCreatureAI(boss_surgeon_stitchflesh);
//    RegisterAreaTriggerAI(at_boss_surgeon_stitchfleshAI);
//    RegisterCreatureAI(npc_boss_surgeon_stitchfleshAI);
//}
