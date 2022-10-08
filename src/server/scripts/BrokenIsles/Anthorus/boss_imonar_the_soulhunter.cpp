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
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "antorus_the_burning_throne.h"

enum Spells
{
    //Stage One: Attack Force
    SPELL_SHOCK_LANCE = 247367,//???? 4s
    SPELL_SLEEP_CANISTER = 254244,// 5s every 12s 247552
    //SPELL_SLEEP_CANISTER = 255029,
    SPELL_PULSE_GRENADE = 247376,//???? 12-14s every 17s summon

    //Stage Two: Contract to Kill
    SPELL_SEVER = 247687,//?? 6s  every 8s
    SPELL_CHARGED_BLASTS = 248254,//247716  8s   every 18s
    SPELL_SHRAPNEL_BLAST = 247923, //????247923 every 12 14s 247939,247944 ,255641 NPC 124776 //247927  ->247929 summon
    NPC_SHRAPNEL_BLAST = 124776,
    SPELL_SHRAPNEL_BLAST_DMG1 = 247927,
    SPELL_SHRAPNEL_BLAST_DMG2 = 247939,
    //Stage Three/Five: The Perfect Weapon
    SPELL_EMPOWERED_SHOCK_LANCE = 250255,//??????   5s
    SPELL_EMPOWERED_PULSE_GRENADE = 248068,//?????? 6 7s
    //SPELL_EMPOWERED_PULSE_GRENADE = 250006,
    SPELL_EMPOWERED_SHRAPNEL_BLAST = 248070,//?????? 15s

    SPELL_INFERNAL_ROCKETS = 248252,
    //SPELL_INFERNAL_ROCKETS = 248255,
    SPELL_GATHERING_POWER = 248424,

    SPELL_CONFLAGRATION = 248233,//1min ????
    //SPELL_CONFLAGRATION = 250135,//2min
    NPC_BOMBING_RUN = 124704,
    SPELL_LEGION_SHIP_INVASION_SPAWN = 251446,//visual
    SPELL_CHARGED_BLASTS_DMG = 247704,//257197 248968
    NPC_PULSE_GRENADE = 124928,
    SPELL_PULSE_GRENADE_VISUAL = 247397,
    SPELL_PULSE_GRENADE_DMG = 247388,
};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_MOVEINLINEOFSIGHT,       EVENT_TYPE_TALK,            0 },
    { EVENT_ON_ENTERCOMBAT,             EVENT_TYPE_TALK,            1 },
    { SPELL_SLEEP_CANISTER,             EVENT_TYPE_TALK,            2 },
    { SPELL_PULSE_GRENADE,              EVENT_TYPE_TALK,            3 },
    { EVENT_ON_JUSTDIED,                EVENT_TYPE_TALK,            11 },
};
struct boss_imonar_the_soulhunter : public BossAI
{
    boss_imonar_the_soulhunter(Creature* creature) : BossAI(creature, DATA_IMONAR_THE_SOULHUNTER) { Initialize(); }

    void Initialize()
    {
        //SetDungeonEncounterID(2082);
        LoadTalkData(&talkData);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SetBossState(DATA_IMONAR_THE_SOULHUNTER, DONE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EMPOWERED_SHOCK_LANCE);
    }

    void ScheduleTasks() override
    {
        PhaseStatus = PHASE_01;
        events.ScheduleEvent(SPELL_SHOCK_LANCE, 4s);
        events.ScheduleEvent(SPELL_SLEEP_CANISTER, 5s);
        events.ScheduleEvent(SPELL_PULSE_GRENADE, 12s, 14s);
        //events.ScheduleEvent(SPELL_INFERNAL_ROCKETS, 5s);
        //events.ScheduleEvent(SPELL_GATHERING_POWER, 5s);
    }


    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(66, damage))
        {
            PhaseStatus = PHASE_02;
            events.Reset();
            DoCast(SPELL_CONFLAGRATION);
            AddTimedDelayedOperation(10000, [this]() -> void
            {
                me->RemoveAurasDueToSpell(SPELL_CONFLAGRATION);
                events.ScheduleEvent(SPELL_SEVER, 6s);
                events.ScheduleEvent(SPELL_CHARGED_BLASTS, 8s);
                events.ScheduleEvent(SPELL_SHRAPNEL_BLAST, 12s, 14s);
            });
        }
        if (me->HealthWillBeBelowPctDamaged(33, damage))
        {
            PhaseStatus = PHASE_03;
            events.Reset();
            DoCast(SPELL_CONFLAGRATION);
            AddTimedDelayedOperation(10000, [this]() -> void
            {
                me->RemoveAurasDueToSpell(SPELL_CONFLAGRATION);
                events.ScheduleEvent(SPELL_EMPOWERED_SHOCK_LANCE, 5s);
                events.ScheduleEvent(SPELL_EMPOWERED_PULSE_GRENADE, 6s, 7s);
                events.ScheduleEvent(SPELL_EMPOWERED_SHRAPNEL_BLAST, 15s);
            });
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_SHOCK_LANCE:
        {
            DoCast(SPELL_SHOCK_LANCE);
            events.Repeat(4s);
            break;
        }
        case SPELL_SLEEP_CANISTER:
        {
            GetTalkData(SPELL_SLEEP_CANISTER);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SLEEP_CANISTER, false);
            events.Repeat(12s);
            break;
        }
        case SPELL_PULSE_GRENADE:
        {
            if (urand(0, 1))
                GetTalkData(SPELL_PULSE_GRENADE);
            DoCast(SPELL_PULSE_GRENADE);

            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->SummonCreature(NPC_PULSE_GRENADE, target1->GetRandomNearPosition(10.0f), TEMPSUMMON_DEAD_DESPAWN, WEEK);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->SummonCreature(NPC_PULSE_GRENADE, target1->GetRandomNearPosition(10.0f), TEMPSUMMON_DEAD_DESPAWN, WEEK);
            events.Repeat(17s);
            break;
        }
        case SPELL_SEVER:
        {
            DoCast(SPELL_SEVER);
            events.Repeat(8s);
            break;
        }
        case SPELL_CHARGED_BLASTS:
        {
            DoCast(SPELL_CHARGED_BLASTS);
            Position pos1 = me->GetRandomNearPosition(35.0f);
            Position pos2 = me->GetRandomNearPosition(35.0f);
            AddTimedDelayedOperation(2500, [this, pos1]() -> void
            {
                if (Creature* felcrush = me->SummonCreature(NPC_BOMBING_RUN, Position(pos1.GetPositionX(),pos1.GetPositionY(), 1878.13f,pos1.GetOrientation()), TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    felcrush->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        felcrush->CastSpell(target1, SPELL_CHARGED_BLASTS_DMG, false);
                }
            });
            AddTimedDelayedOperation(3000, [this, pos2]() -> void
            {
                if (Creature* felcrush = me->SummonCreature(NPC_BOMBING_RUN, Position(pos2.GetPositionX(), pos2.GetPositionY(), 1878.13f, pos2.GetOrientation()), TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    felcrush->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                    if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        felcrush->CastSpell(target1, SPELL_CHARGED_BLASTS_DMG, false);
                }
            });
            events.Repeat(18s);
            break;
        }
        case SPELL_SHRAPNEL_BLAST:
        {
            DoCast(SPELL_SHRAPNEL_BLAST);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SHRAPNEL_BLAST_DMG1, false);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SHRAPNEL_BLAST_DMG1, false);
            events.Repeat(12s, 14s);
            break;
        }
        case SPELL_EMPOWERED_SHOCK_LANCE:
        {
            DoCast(SPELL_EMPOWERED_SHOCK_LANCE);
            events.Repeat(5s);
            break;
        }
        case SPELL_EMPOWERED_PULSE_GRENADE:
        {
            DoCast(SPELL_EMPOWERED_PULSE_GRENADE);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->SummonCreature(NPC_PULSE_GRENADE, target1->GetRandomNearPosition(10.0f), TEMPSUMMON_DEAD_DESPAWN, WEEK);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->SummonCreature(NPC_PULSE_GRENADE, target1->GetRandomNearPosition(10.0f), TEMPSUMMON_DEAD_DESPAWN, WEEK);
            events.Repeat(6s, 7s);
            break;
        }
        case SPELL_EMPOWERED_SHRAPNEL_BLAST:
        {
            DoCast(SPELL_EMPOWERED_SHRAPNEL_BLAST);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SHRAPNEL_BLAST_DMG1, false);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SHRAPNEL_BLAST_DMG1, false);
            events.Repeat(15s);
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
        case 1:
        {
            summon->SetFaction(me->GetFaction());
            break;
        }
        }
    }
    uint8 PhaseStatus;
    uint8 PHASE_01;
    uint8 PHASE_02;
    uint8 PHASE_03;
    bool IsLock;
};

struct npc_bombing_run_124704 : public ScriptedAI
{
    npc_bombing_run_124704(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->CastSpell(me, SPELL_LEGION_SHIP_INVASION_SPAWN, true);
    }

    void UpdateAI(uint32 diff) override {}
};

struct npc_pulse_grenade_124928 : public ScriptedAI
{
    npc_pulse_grenade_124928(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        me->CastSpell(me, SPELL_PULSE_GRENADE_VISUAL, true);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
        case SPELL_PULSE_GRENADE_DMG:
        {
            if (Player* player = me->SelectNearestPlayer(3.0f))
                me->CastSpell(player, SPELL_PULSE_GRENADE_DMG, true);
            me->DespawnOrUnsummon();
            break;
        }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 3.0f, false) && !IsLock)
        {
            IsLock = true;
            events.ScheduleEvent(SPELL_PULSE_GRENADE_DMG, 1s);
        }
    }
    bool IsLock;
};

struct npc_shrapnel_blast_124776 : public ScriptedAI
{
    npc_shrapnel_blast_124776(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
        case SPELL_SHRAPNEL_BLAST_DMG2:
        {
            if (Player* player = me->SelectNearestPlayer(4.0f))
                me->CastSpell(player, SPELL_SHRAPNEL_BLAST_DMG2, true);
            me->DespawnOrUnsummon();
            break;
        }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 4.0f, false) && !IsLock)
        {
            IsLock = true;
            events.ScheduleEvent(SPELL_SHRAPNEL_BLAST_DMG2, 1s);
        }
    }
    bool IsLock;
};

void AddSC_boss_imonar_the_soulhunter()
{
    RegisterCreatureAI(boss_imonar_the_soulhunter);
    RegisterCreatureAI(npc_bombing_run_124704);
    RegisterCreatureAI(npc_pulse_grenade_124928);

    RegisterCreatureAI(npc_shrapnel_blast_124776);
}
