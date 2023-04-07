/*
 * Copyright 2023 AzgathCore
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
#include "temple_of_sethraliss.h"
#include "ScriptedGossip.h"

enum Misc
{
    ENCOUNTER_ID = 2127,
};

enum Texts
{
    SAY_OBJECTIVE = 0,
    SAY_EFFECTIVE_HEAL = 1,
    SAY_INTRO = 5,
    SAY_RESTORE = 6,
    SAY_THANK_YOU = 4,
    SAY_JOIN_COMBAT = 3,
};

enum Spells
{
    SPELL_EMPOWERMENT = 269670,
    SPELL_LIFE_FORCE = 274149,
    SPELL_CARDIAC_SHOCK = 279015,
    SPELL_LIFE_FORCE_HEAL = 274149,
    SPELL_CHAIN_LIGHTNING = 268061,
    SPELL_SNAKE_CHARM = 268008,
    SPELL_JOLT = 279000,
    SPELL_TAINT_DEBUFF = 267944,
  
    SPELL_TAINT_CHANNEL = 273677,
    SPELL_TAINT_VISUAL = 267759,
    SPELL_HEART_ATTACK = 268007,
  
    SPELL_PULSE = 268024,
    SPELL_PLAGUE = 269686,
    SPELL_SPAWN_FRAGMENT = 278885,
    SPELL_LAVA_BURST = 274642,
    SPELL_FLAME_SHOCK = 268013
};

enum Events
{
    EVENT_SUMMON_TOADS = 1,
    EVENT_SUMMON_HEXER,
    EVENT_SUMMON_GUARDIAN,
    EVENT_SUMMON_DOCTOR,
    EVENT_CHECK_PLAYERS,
    EVENT_PULSE,
    EVENT_CHAIN_LIGHTNING,
    EVENT_SNAKE_CHARM,
    EVENT_CHANNEL,
    EVENT_HEART_ATTACK,
    EVENT_LIGHTNING_STRIKE,
    EVENT_PLAGUE_DOCTOR = 1,
    EVENT_HEART_GUARDIAN,
    EVENT_TOAD,
    EVENT_JOLT
};

enum Timers
{};
//const Position universal_spawn_pos = { 4140.0f, 3659.0f, -43.0f, 0.59f };
//const Position middle_of_room_pos = { 4161.0f, 3673.0f, -34.0f, 3.69f };

////133392
//struct boss_avatar_of_sethraliss : public BossAI
//{
//    TIMER_PULSE = 30 * IN_MILLISECONDS,
//    TIMER_LIGHTNING_STRIKE = 15 * IN_MILLISECONDS,
//    boss_avatar_of_sethraliss(Creature* creature) : BossAI(creature, DATA_AVATAR_OF_SETHRALISS) { }
//
//    TIMER_CHECK_PLAYERS = 2 * IN_MILLISECONDS,
//    void Reset() override
//    {
//        BossAI::Reset();
//        _JustReachedHome();
//        instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, NOT_STARTED);
//        this->wavecount = 0;           
//        me->RestoreFaction();
//        std::list<Creature*> c_li;
//        me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
//        for (auto & hoodoo : c_li)
//        {
//            if (hoodoo->IsAlive())
//            {
//                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, hoodoo);
//            }
//            else
//            {
//                hoodoo->Respawn(true);
//                hoodoo->AI()->Reset();
//            }
//        }
//        me->DespawnCreaturesInArea(NPC_HEART_GUARDIAN);
//        me->DespawnCreaturesInArea(NPC_PLAGUE_TOAD);
//        me->DespawnCreaturesInArea(NPC_PLAGUE_DOCTOR);
//        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);       
//    }
//
//    TIMER_SUMMON_TOADS = 25 * IN_MILLISECONDS,
//    TIMER_SUMMON_GUARDIAN = 15 * IN_MILLISECONDS,
//    TIMER_SUMMON_DOCTOR = 20 * IN_MILLISECONDS,
//    void EnterCombat(Unit* who) override
//    {
//        instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, IN_PROGRESS);
//        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1s);
//        events.ScheduleEvent(EVENT_HEART_GUARDIAN, 5s);
//        events.ScheduleEvent(EVENT_TOAD, 25s);
//        if (IsHeroic() || IsMythic()) 
//            events.ScheduleEvent(EVENT_PLAGUE_DOCTOR, 10s);
//    }
//
//    TIMER_CHAIN_LIGHTNING = 8 * IN_MILLISECONDS,
//    TIMER_SNAKE_CHARM = 25 * IN_MILLISECONDS,
//    TIMER_HEART_ATTACK = 5 * IN_MILLISECONDS,
//};
//    void JustDied(Unit* u) override
//    {
//        _JustDied();
//        me->ForcedDespawn(0, 5s);
//        me->DespawnCreaturesInArea(NPC_HEART_GUARDIAN);
//        me->DespawnCreaturesInArea(NPC_PLAGUE_TOAD);
//        me->DespawnCreaturesInArea(NPC_PLAGUE_DOCTOR);        
//    }
//
//enum Actions
//    void DamageTaken(Unit* done_by, uint32& dmg) override
//    {
//    ACTION_START = 1,
//    ACTION_COMPLETE,
//        if (me->HealthAbovePct(99))
//        {
//            me->CastStop();
//            instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, DONE);
//            _JustReachedHome();
//            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//            instance->SendBossKillCredit(ENCOUNTER_ID);
//            std::list<Player*> p_li;
//            me->GetPlayerListInGrid(p_li, 150.0f);
//            for (auto & players : p_li)
//            {
//                players->KilledMonsterCredit(me->GetEntry());
//                players->ClearInCombat();
//            }
//            Talk(SAY_THANK_YOU);
//            me->SummonGameObject(GO_SETHRALISS_TREASURE, 4149.73f, 3665.59f, -43.0365f, 3.68391f, QuaternionData(0, 0, -0.963461f, 0.267849f), false);
//            if (IsMythic() && instance->IsChallengeModeStarted())
//            {
//                me->SummonGameObject(GO_CHALLENGERS_CACHE_SETHRALISS, 4185.0f, 3688.0f, -43.0f, 3.84f, QuaternionData(), false);
//            }
//            me->DespawnCreaturesInArea(NPC_HOODOO_HEXER, 125.0f);
//            me->DespawnCreaturesInArea(NPC_HEART_GUARDIAN, 125.0f);
//            me->DespawnCreaturesInArea(NPC_PLAGUE_TOAD, 125.0f);
//            me->DespawnCreaturesInArea(NPC_PLAGUE_DOCTOR, 125.0f);
//        }
//
//        if (me->HealthBelowPctDamaged(80, dmg) && (this->wavecount = 0))
//        {
//            wavecount = 1;
//            std::list<Creature*> c_li;
//            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
//            for (auto& hoodoo : c_li)
//            {
//                if (hoodoo->IsAlive())
//                {
//                    return;
//                }
//                else
//                {
//                    hoodoo->Respawn(true);
//                    hoodoo->AI()->Reset();
//                }
//            }
//        }
//
//        if (me->HealthBelowPctDamaged(70, dmg) && (this->wavecount = 1))
//        {
//            wavecount = 2;
//            std::list<Creature*> c_li;
//            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
//            for (auto& hoodoo : c_li)
//            {
//                if (hoodoo->IsAlive())
//                {
//                    return;
//                }
//                else
//                {
//                    hoodoo->Respawn(true);
//                    hoodoo->AI()->Reset();
//                }
//            }
//        }
//
//        if (me->HealthBelowPctDamaged(40, dmg) && (this->wavecount = 2))
//        {
//            wavecount = 3;
//            std::list<Creature*> c_li;
//            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
//            for (auto & hoodoo : c_li)
//            {
//                if (hoodoo->IsAlive())
//                {
//                    return;
//                }
//                else
//                {
//                    hoodoo->Respawn(true);
//                    hoodoo->AI()->Reset();
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, hoodoo);
//                    std::list<Creature*> c_li;
//                    me->GetCreatureListWithEntryInGrid(c_li, NPC_AVATAR_OF_SETHRALISS, 100.0f);
//                    for (auto& avatar : c_li)
//                    if (avatar->IsAlive())
//                    {    
//                        me->CastSpell(avatar, SPELL_TAINT_CHANNEL);
//                        me->CastSpell(avatar, SPELL_TAINT_VISUAL);
//                    }
//                }
//            }
//        }
//    }
//
//    void ExecuteEvent(uint32 eventId) override
//    {
//        switch (eventId)
//        {
//        case EVENT_JOLT:
//        {
//            std::list<Creature*> c_li;
//            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
//            for (auto& hoodoo : c_li)
//            me->AI()->DoCast(hoodoo, SPELL_JOLT);
//            events.Repeat(3s);
//            break;
//        }
//
//        case EVENT_CHECK_PLAYERS:
//        {
//            std::list<Player*> p_li;
//            me->GetPlayerListInGrid(p_li, 150.0f);
//            for (auto & players : p_li)
//            if (players->IsAlive())
//            {
//                return;
//            }
//            else
//            {
//                BossAI::Reset();
//            }
//            events.Repeat(3s);
//            break;
//        }
//
//        case EVENT_HEART_GUARDIAN:
//             me->SummonCreature(NPC_HEART_GUARDIAN, universal_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
//             events.Repeat(15s);
//             break;
//
//        case EVENT_PLAGUE_DOCTOR:
//             me->SummonCreature(NPC_PLAGUE_DOCTOR, universal_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
//             events.Repeat(20s);
//             break;
//
//        case EVENT_TOAD:
//            for (uint8 i = 0; i < 6; i++)
//            {
//                me->SummonCreature(NPC_PLAGUE_TOAD, me->GetRandomPoint(middle_of_room_pos, 30.0f));
//            }
//            events.Repeat(25s);
//            break;
//        }        
//    }
//
//    void JustSummoned(Creature* summon)
//    {
//        switch (summon->GetEntry())
//        {
//        case NPC_PLAGUE_TOAD:
//            if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                summon->AI()->AttackStart(tar);
//            }      
//            break;
//
//        case NPC_HEART_GUARDIAN:
//            summon->RemoveAura(274609);
//            summon->RemoveAura(231201);
//            summon->RemoveAura(274603);  
//            summon->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//            summon->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//            summon->SetFaction(14);
//            summon->AI()->DoZoneInCombat();
//            break;
//
//        default:
//            break;
//        }
//    }
//
//    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) 
//    { 
//        if (instance->GetBossState(DATA_AVATAR_OF_SETHRALISS == NOT_STARTED))
//        {
//            instance->SetBossState(DATA_AVATAR_OF_SETHRALISS, IN_PROGRESS);
//            me->AddUnitState(UNIT_STATE_ROOT);
//            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
//            me->SetHealth(me->GetMaxHealth() * 0.10f);
//            me->SetFaction(FACTION_MASK_PLAYER);
//            events.ScheduleEvent(EVENT_JOLT, 100ms);
//
//            std::list<Creature*> c_li;
//            me->GetCreatureListWithEntryInGrid(c_li, NPC_HOODOO_HEXER, 150.0f);
//            for (auto & hoodoo : c_li)
//            {
//                if (hoodoo->IsAlive())
//                {
//                    hoodoo->SetVisible(true);
//                    hoodoo->SetReactState(REACT_DEFENSIVE);
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, hoodoo);
//                }
//            }
//
//            if (Creature* avatar = instance->GetCreature(NPC_AVATAR_OF_SETHRALISS))
//            {
//                avatar->AI()->Talk(SAY_INTRO);
//                _EnterCombat();
//
//                avatar->GetScheduler().Schedule(6s, [this, avatar] (TaskContext context)
//                {
//                    avatar->AI()->Talk(SAY_OBJECTIVE);
//                });
//
//                avatar->GetScheduler().Schedule(8s, [this, avatar] (TaskContext context)
//                {
//                    avatar->AI()->Talk(SAY_RESTORE);                    
//                });
//            }          
//        }
//    }
//
//private:
//    uint8 wavecount;
//    uint8 encouter_done;
//};
//
//enum Creatures
//enum HoodooHexerSpells
//{
//    BOSS_AVATAR_OF_SETHRALISS = 133392,
//    SPELL_LAVA_BURST = 274642,
//    SPELL_FLAME_SHOCK = 268013
//};
//
//    NPC_HOODOO_HEXER_BFA = 136250,
//    NPC_PLAGUE_DOCTOR_BFA = 139949,
//    NPC_HEART_GUARDIAN_BFA = 139946,
//    NPC_PLAGUE_TOAD_BFA = 137233,
//    NPC_ENERGY_FRAGMENT_BFA = 142929,
//enum HoodooHexerEvents
//{
//    EVENT_LAVA_BURST = 1,
//    EVENT_FLAME_SHOCK
//};
//
//Position HoodooPos[4] =
////135552
//struct npc_hoodoo_hexer : public ScriptedAI
//{
//    npc_hoodoo_hexer(Creature* c) : ScriptedAI(c) { }
//
//    void Reset() override
//    {
//        ScriptedAI::Reset();
//        me->SetReactState(REACT_PASSIVE);
//        std::list<Creature*> c_li;
//        me->GetCreatureListWithEntryInGrid(c_li, NPC_AVATAR_OF_SETHRALISS, 100.0f);
//        for (auto & avatar : c_li)
//        if (avatar->IsAlive())
//        {            
//            me->CastSpell(avatar, SPELL_TAINT_CHANNEL);
//            me->CastSpell(avatar, SPELL_TAINT_VISUAL);
//        }
//        me->SetVisible(false);
//    }
//
//    void EnterCombat(Unit* u) override
//    {        
//        if (IsHeroic() || IsMythic())
//        {
//            events.ScheduleEvent(EVENT_FLAME_SHOCK, 1s);
//        }
//        events.ScheduleEvent(EVENT_LAVA_BURST, 3s);
//    }
//
//    void JustDied(Unit* u) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//
//    void ExecuteEvent(uint32 eventId) override
//    {
//        switch (eventId)
//        {
//        case EVENT_FLAME_SHOCK:
//            if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//            {
//                DoCast(tar, SPELL_FLAME_SHOCK);
//            }
//            events.Repeat(15s);
//            break;
//
//        case EVENT_LAVA_BURST:
//            if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
//            {
//    { 4142.10f, 3678.26f, -42.95f },
//    { 4167.25f, 3692.94f, -42.95f },
//    { 4181.25f, 3668.73f, -42.95f },
//    { 4156.75f, 3653.69f, -42.95f },
//                DoCast(tar, SPELL_LAVA_BURST);
//            }
//            events.Repeat(3s);
//            break;
//
//        default:
//            break;
//        }
//    }
//};
//
//Position ToadPos[5] =
////137233
//struct npc_plague_toad_137233 : public ScriptedAI
//{
//    npc_plague_toad_137233(Creature* c) : ScriptedAI(c) { }
//
//    void Reset() override
//    {
//        ScriptedAI::Reset();
//    }
//
//    void EnterCombat(Unit* u) override
//    {
//    { 4142.10f, 3678.26f, -42.95f },
//    { 4167.25f, 3692.94f, -42.95f },
//    { 4181.25f, 3668.73f, -42.95f },
//    { 4156.75f, 3653.69f, -42.95f },
//    { 4168.72f, 3655.34f, -43.25f },
//       DoCastVictim(SPELL_PLAGUE);
//    }
//};
//
//#define AVATAR_START "The hex is shattered, but the temple's defenses have awakened!"
//#define SECOND_TEXT_AVATAR "Should you fail, I am lost!"
//#define AVATAR_COMPLETED "The storm has broken, and I am myself again. Thank you."
//#define FIRST_TEXT_AVATAR "Restore me and I will disable them!"
////142929
//struct npc_energy_fragment : public ScriptedAI
//{
//    npc_energy_fragment(Creature* c) : ScriptedAI(c) { }
//
//    void Reset() override
//    {
//        ScriptedAI::Reset();
//    }
//
//    void sGossipHello(Player* player) 
//    { 
//        CloseGossipMenuFor(player);
//        if (Creature* avatar = instance->GetCreature(NPC_AVATAR_OF_SETHRALISS))
//        {
//            avatar->RemoveAura(SPELL_TAINT_DEBUFF);
//            avatar->AddAura(SPELL_LIFE_FORCE);
//            me->CastSpell(avatar, SPELL_LIFE_FORCE_HEAL);
//            avatar->AI()->Talk(SAY_EFFECTIVE_HEAL);            
//            me->DespawnOrUnsummon();
//        }
//    }
//};
//
//void AddSC_boss_avatar_of_sethraliss()
//{
//    
//    RegisterCreatureAI(boss_avatar_of_sethraliss);
//    RegisterCreatureAI(npc_hoodoo_hexer);
//    RegisterCreatureAI(npc_plague_toad_137233);
//    RegisterCreatureAI(npc_energy_fragment);
//}
