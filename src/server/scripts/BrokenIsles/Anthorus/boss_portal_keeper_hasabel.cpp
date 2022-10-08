/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "antorus_the_burning_throne.h"

enum Spells
{
    //Platform: Nexus
    SPELL_COLLAPSING_WORLD = 243983,//10s every 33s
    SPELL_FELSTORM_BARRAGE = 244000,// every 33s
    SPELL_REALITY_TEAR = 244016,//   every 12s
    SPELL_TRANSPORT_PORTAL = 244689, //244677 every 41s
    SPELL_CATASTROPHIC_IMPLOSION = 246075,//mythic

    //Platform: Xoroth
    NPC_VULCANAR = 122211,
    SPELL_SUPERNOVA = 244598,
    SPELL_FLAMES_OF_XOROTH = 244607,// every 7s
    //Platform: Rancora
    NPC_LADY_DACIDION = 122212,
    SPELL_FELSILK_WRAP = 244949,// every 17s
    SPELL_POISON_ESSENCE = 246316,// every 10s
    SPELL_LEECH_ESSENCE = 244915,// every 10s
    //Platform: Nathreza
    NPC_LORD_EILGAR = 122213,
    SPELL_CORRUPT = 245040,
    SPELL_DELUSIONS = 245050,// every 15s
    //all mobs
    SPELL_UNSTABLE_PORTAL = 255805,

    //gateway
    NPC_GATEWAY_XOROTH_ENTERING = 122494,//Gateway: Xoroth (Entering)
    NPC_GATEWAY_XOROTH_LEAVING = 122533,//Gateway: Xoroth (Leaving)
    NPC_GATEWAY_RANCORA_ENTERING = 122543,//Gateway: Rancora (Entering)
    NPC_GATEWAY_RANCORA_LEAVING = 122555,//Gateway: Rancora (Leaving)
    NPC_GATEWAY_NATHREZA_ENTERING = 122558,//Gateway: Nathreza (Entering)
    NPC_GATEWAY_NATHREZA_LEAVING = 122559,//Gateway: Nathreza (Leaving)

    //NPC
    NPC_FELCRUSH_PORTAL = 122438,
    SPELL_FELSTORM_BARRAGE_DMG = 244001,
    NPC_TRANSPORT_PORTAL = 122761,
    NPC_FELBLAZE_IMP = 120535,
    NPC_COLLAPSING_WORLD = 122425,
    SPELL_COLLAPSING_WORLD_VISUAL = 243984,
};

enum
{
    ACTION_OPEN = 1,
    ACTION_CLOSE,
};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_MOVEINLINEOFSIGHT,       EVENT_TYPE_TALK,            0 },
    { EVENT_ON_ENTERCOMBAT,             EVENT_TYPE_TALK,            1 },
    { SPELL_COLLAPSING_WORLD,           EVENT_TYPE_TALK,            2 },
    { EVENT_ON_HP90,                    EVENT_TYPE_TALK,            3 },
    { EVENT_ON_HP90,                    EVENT_TYPE_TALK,            4 },
   // { SPELL_PURGING_PROTOCOL,           EVENT_TYPE_TALK,            5 },
    { EVENT_ON_HP60,                    EVENT_TYPE_TALK,            8 },
    { EVENT_ON_HP60,                    EVENT_TYPE_TALK,            9 },
    { EVENT_ON_HP30,                    EVENT_TYPE_TALK,            11 },
    { EVENT_ON_HP30,                    EVENT_TYPE_TALK,            12 },
    { EVENT_ON_JUSTDIED,                EVENT_TYPE_TALK,            15 },
};

struct boss_portal_keeper_hasabel : public BossAI
{
    boss_portal_keeper_hasabel(Creature* creature) : BossAI(creature, DATA_PORTAL_KEEPER_HASABEL) { Initialize(); }

    void Initialize()
    {
        //SetDungeonEncounterID(2064);
        LoadTalkData(&talkData);
    }

    void SetDoorStatusByNPC(uint32 npcId, int32 status)
    {
        if (Creature* target = me->FindNearestCreature(npcId, 300.0f, true))
            target->AI()->DoAction(status);
    }

    void SetDoorStatus(int32 status)
    {
        SetDoorStatusByNPC(NPC_GATEWAY_XOROTH_ENTERING, status);
        SetDoorStatusByNPC(NPC_GATEWAY_XOROTH_LEAVING, status);
        SetDoorStatusByNPC(NPC_GATEWAY_RANCORA_ENTERING, status);
        SetDoorStatusByNPC(NPC_GATEWAY_RANCORA_LEAVING, status);
        SetDoorStatusByNPC(NPC_GATEWAY_NATHREZA_ENTERING, status);
        SetDoorStatusByNPC(NPC_GATEWAY_NATHREZA_LEAVING, status);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(90, damage))
        {
            GetTalkData(EVENT_ON_HP90);
            SetDoorStatusByNPC(NPC_GATEWAY_XOROTH_ENTERING, ACTION_OPEN);
            SetDoorStatusByNPC(NPC_GATEWAY_XOROTH_LEAVING, ACTION_OPEN);
        }
        if (me->HealthWillBeBelowPctDamaged(60, damage))
        {
            GetTalkData(EVENT_ON_HP60);
            SetDoorStatusByNPC(NPC_GATEWAY_RANCORA_ENTERING, ACTION_OPEN);
            SetDoorStatusByNPC(NPC_GATEWAY_RANCORA_LEAVING, ACTION_OPEN);
        }
        if (me->HealthWillBeBelowPctDamaged(30, damage))
        {
            GetTalkData(EVENT_ON_HP30);
            SetDoorStatusByNPC(NPC_GATEWAY_NATHREZA_ENTERING, ACTION_OPEN);
            SetDoorStatusByNPC(NPC_GATEWAY_NATHREZA_LEAVING, ACTION_OPEN);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SetBossState(DATA_PORTAL_KEEPER_HASABEL, DONE);
        //instance->DoDelayedConversation(4000, 5521);
    }

    void ScheduleTasks() override
    {
        PhaseStatus = PHASE_01;
        SetDoorStatus(ACTION_CLOSE);
        events.ScheduleEvent(SPELL_COLLAPSING_WORLD, 10s);
        events.ScheduleEvent(SPELL_FELSTORM_BARRAGE, 25s);
        events.ScheduleEvent(SPELL_REALITY_TEAR, 6s);
        events.ScheduleEvent(SPELL_TRANSPORT_PORTAL, 41s);
        if(IsMythic())
            events.ScheduleEvent(SPELL_CATASTROPHIC_IMPLOSION, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_COLLAPSING_WORLD:
        {
            GetTalkData(SPELL_COLLAPSING_WORLD);
            DoCast(SPELL_COLLAPSING_WORLD);
            events.Repeat(33s);
            break;
        }
        case SPELL_FELSTORM_BARRAGE:
        {
            DoCast(SPELL_FELSTORM_BARRAGE);
            AddTimedDelayedOperation(2500, [this]() -> void
            {
                if (Creature* felcrush = me->SummonCreature(NPC_FELCRUSH_PORTAL, me->GetRandomNearPosition(25.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    felcrush->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        felcrush->CastSpell(target1->GetPosition(), SPELL_FELSTORM_BARRAGE_DMG, false);
                }
            });
            AddTimedDelayedOperation(3000, [this]() -> void
            {
                if (Creature* felcrush = me->SummonCreature(NPC_FELCRUSH_PORTAL, me->GetRandomNearPosition(25.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    felcrush->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        felcrush->CastSpell(target1->GetPosition(), SPELL_FELSTORM_BARRAGE_DMG, false);
                }
            });
            AddTimedDelayedOperation(3500, [this]() -> void
            {
                if (Creature* felcrush = me->SummonCreature(NPC_FELCRUSH_PORTAL, me->GetRandomNearPosition(25.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    felcrush->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        felcrush->CastSpell(target1->GetPosition(), SPELL_FELSTORM_BARRAGE_DMG, false);
                }
            });
            events.Repeat(33s);
            break;
        }
        case SPELL_REALITY_TEAR:
        {
            DoCast(SPELL_REALITY_TEAR);
            events.Repeat(12s);
            break;
        }
        case SPELL_TRANSPORT_PORTAL:
        {
            DoCast(SPELL_TRANSPORT_PORTAL);
            Talk(urand(5, 7));

            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
            {
                me->SummonCreature(NPC_TRANSPORT_PORTAL, target1->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 10000);
                AddTimedDelayedOperation(2500, [this, target1]() -> void
                {
                    me->SummonCreature(NPC_FELBLAZE_IMP, target1->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
                });
                AddTimedDelayedOperation(5000, [this, target1]() -> void
                {
                    me->SummonCreature(NPC_FELBLAZE_IMP, target1->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
                });
                AddTimedDelayedOperation(7500, [this, target1]() -> void
                {
                    me->SummonCreature(NPC_FELBLAZE_IMP, target1->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
                });
            }
            events.Repeat(41s);
            break;
        }
        case SPELL_CATASTROPHIC_IMPLOSION:
        {
            //DoCast(SPELL_CATASTROPHIC_IMPLOSION);
            //events.Repeat(5s);
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;
            GetTalkData(EVENT_ON_MOVEINLINEOFSIGHT);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        }
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);
        switch (summon->GetEntry())
        {
        case NPC_FELBLAZE_IMP:
        case NPC_FELCRUSH_PORTAL:
        {
            summon->SetFaction(me->GetFaction());
            break;
        }
        }
    }
    uint8 PhaseStatus;
    bool IsLock;
    uint8 PHASE_01;
};

struct npc_gateway_portal_hasabel : public ScriptedAI
{
    npc_gateway_portal_hasabel(Creature* creature) : ScriptedAI(creature) { }
    virtual Position const* GetPos() const = 0;
    void Reset() override
    {
        IsLock = false;
    }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_OPEN:
            IsLock = true;
            //me->SetDisplayId(18783);
            break;
        case ACTION_CLOSE:
            IsLock = false;
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 5.0f, false) && IsLock)
            who->NearTeleportTo(GetPos()->GetPosition());
    }
    bool IsLock;
};

struct npc_gateway_xoroth_entering_122494 : public npc_gateway_portal_hasabel
{
    npc_gateway_xoroth_entering_122494(Creature* creature) : npc_gateway_portal_hasabel(creature) { }
    Position const pos[1] = { { -3781.5634f, -1407.33f, 645.2726f, 3.776f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_gateway_xoroth_leaving_122533 : public npc_gateway_portal_hasabel
{
    npc_gateway_xoroth_leaving_122533(Creature* creature) : npc_gateway_portal_hasabel(creature) { }
    Position const pos[1] = { { -3719.884f, -1361.777f, 624.5f, 0.4897f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_gateway_rancora_entering_122543 : public npc_gateway_portal_hasabel
{
    npc_gateway_rancora_entering_122543(Creature* creature) : npc_gateway_portal_hasabel(creature) { }
    Position const pos[1] = { { -3705.034f, -1268.9577f, 649.8345f, 1.546f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_gateway_rancora_leaving_122555 : public npc_gateway_portal_hasabel
{
    npc_gateway_rancora_leaving_122555(Creature* creature) : npc_gateway_portal_hasabel(creature) { }
    Position const pos[1] = { { -3704.05f, -1335.9755f, 624.5f, 4.719f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_gateway_nathreza_entering_122558 : public npc_gateway_portal_hasabel
{
    npc_gateway_nathreza_entering_122558(Creature* creature) : npc_gateway_portal_hasabel(creature) { }
    Position const pos[1] = { { -3626.6979f, -1403.9112f, 645.2756f, 5.637f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_gateway_nathreza_leaving_122559 : public npc_gateway_portal_hasabel
{
    npc_gateway_nathreza_leaving_122559(Creature* creature) : npc_gateway_portal_hasabel(creature) { }
    Position const pos[1] = { { -3690.457f, -1359.1f, 624.5f, 2.718f } };
    Position const* GetPos() const override { return pos; }
};

struct npc_collapsing_world_122425 : public ScriptedAI
{
    npc_collapsing_world_122425(Creature* creature) : ScriptedAI(creature) { SetCombatMovement(false); }

    void UpdateAI(uint32 diff) override
    {
        if (!IsLock)
        {
            IsLock = true;
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
            DoCastSelf(SPELL_COLLAPSING_WORLD_VISUAL);
            me->DespawnOrUnsummon(10000);
        }
    }
    bool IsLock;
};

struct npc_lord_eilgar_122213 : public ScriptedAI
{
    npc_lord_eilgar_122213(Creature* creature) : ScriptedAI(creature) { }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_UNSTABLE_PORTAL, 8s);
        events.ScheduleEvent(SPELL_CORRUPT, 8s);
        events.ScheduleEvent(SPELL_DELUSIONS, 15s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DELUSIONS);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_UNSTABLE_PORTAL:
        {
            DoCast(SPELL_UNSTABLE_PORTAL);
            events.Repeat(15s);
            break;
        }
        case SPELL_CORRUPT:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_CORRUPT, false);
            events.Repeat(15s);
            break;
        }
        case SPELL_DELUSIONS:
        {
            DoCast(SPELL_DELUSIONS);
            events.Repeat(15s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_lady_dacidion_122212 : public ScriptedAI
{
    npc_lady_dacidion_122212(Creature* creature) : ScriptedAI(creature) { }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_UNSTABLE_PORTAL, 8s);
        events.ScheduleEvent(SPELL_FELSILK_WRAP, 17s);
        events.ScheduleEvent(SPELL_POISON_ESSENCE, 10s);
        events.ScheduleEvent(SPELL_LEECH_ESSENCE, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_UNSTABLE_PORTAL:
        {
            DoCast(SPELL_UNSTABLE_PORTAL);
            events.Repeat(15s);
            break;
        }
        case SPELL_FELSILK_WRAP:
        {
            DoCast(SPELL_FELSILK_WRAP);
            events.Repeat(17s);
            break;
        }
        case SPELL_POISON_ESSENCE:
        {
            DoCast(SPELL_POISON_ESSENCE);
            events.Repeat(10s);
            break;
        }
        case SPELL_LEECH_ESSENCE:
        {
            DoCast(SPELL_LEECH_ESSENCE);
            events.Repeat(10s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_vulcanar_122211 : public ScriptedAI
{
    npc_vulcanar_122211(Creature* creature) : ScriptedAI(creature) { }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_UNSTABLE_PORTAL, 8s);
        events.ScheduleEvent(SPELL_SUPERNOVA, 8s);
        events.ScheduleEvent(SPELL_FLAMES_OF_XOROTH, 7s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_UNSTABLE_PORTAL:
        {
            DoCast(SPELL_UNSTABLE_PORTAL);
            events.Repeat(15s);
            break;
        }
        case SPELL_SUPERNOVA:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target->GetPosition(), SPELL_SUPERNOVA, false);
            events.Repeat(15s);
            break;
        }
        case SPELL_FLAMES_OF_XOROTH:
        {
            DoCast(SPELL_FLAMES_OF_XOROTH);
            events.Repeat(7s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_transport_portal_122761 : public ScriptedAI
{
    npc_transport_portal_122761(Creature* creature) : ScriptedAI(creature) { SetCombatMovement(false); }

    void UpdateAI(uint32 diff) override
    {}
};

struct npc_felcrush_portal_122438 : public ScriptedAI
{
    npc_felcrush_portal_122438(Creature* creature) : ScriptedAI(creature) { SetCombatMovement(false); }
};

void AddSC_boss_portal_keeper_hasabel()
{
    RegisterCreatureAI(boss_portal_keeper_hasabel);
    RegisterCreatureAI(npc_gateway_xoroth_entering_122494);
    RegisterCreatureAI(npc_gateway_xoroth_leaving_122533);
    RegisterCreatureAI(npc_gateway_rancora_entering_122543);
    RegisterCreatureAI(npc_gateway_rancora_leaving_122555);
    RegisterCreatureAI(npc_gateway_nathreza_entering_122558);
    RegisterCreatureAI(npc_gateway_nathreza_leaving_122559);
    RegisterCreatureAI(npc_collapsing_world_122425);
    RegisterCreatureAI(npc_lord_eilgar_122213);
    RegisterCreatureAI(npc_lady_dacidion_122212);
    RegisterCreatureAI(npc_vulcanar_122211);
    RegisterCreatureAI(npc_transport_portal_122761);
    RegisterCreatureAI(npc_felcrush_portal_122438);
}
