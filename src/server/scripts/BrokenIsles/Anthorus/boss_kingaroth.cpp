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
    SPELL_APOCALYPSE_PROTOCOL = 246516,
    SPELL_RUINER = 246833,//246840
    SPELL_DIABOLIC_BOMB = 248214,//248214  246779,246754
    SPELL_DIABOLIC_BOMB_DMG = 246779,
    SPELL_FORGING_STRIKE = 254919,//244312
    SPELL_REVERBERATING_STRIKE = 254926,
    //Mythic
    SPELL_EMPOWERED_DIABOLIC_BOMB = 254796,
    SPELL_EMPOWERED_RUINER = 254797,
    //Mobs
    NPC_GAROTHI_ANNIHILATOR = 123906,
    NPC_GAROTHI_DECIMATOR = 123921,
    NPC_GAROTHI_DEMOLISHER = 123929,
    SPELL_INITIALIZING = 246504, //32s 30s
    SPELL_DECIMATION = 246687,//11s
    SPELL_ANNIHILATION = 245807,//16s
    SPELL_DEMOLISH = 246692,//16s

    SPELL_PURGING_PROTOCOL = 248061,
    SPELL_FLAMES_OF_THE_FORGE = 246646,
    SPELL_APOCALYPSE_BLAST = 246634,
};

enum Events
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
};

Position northwestern = { -10514.5f,8142.45f,1873.18f,3.7699f };
Position southwestern = { -10635.0996f,8142.43f,1873.18f,5.65487f };
Position eastern = { -10574.7998f,8024.12f,1873.14f,1.57f };
//Stage: Deployment
//Stage: Construction

struct CustomSpawnData
{
    uint32 event, npcId;
    Position pos;
};

CustomSpawnData const spawnData[] =
{
    { EVENT_1, NPC_GAROTHI_DEMOLISHER, northwestern },
    { EVENT_1, NPC_GAROTHI_DECIMATOR, southwestern },
    { EVENT_2, NPC_GAROTHI_ANNIHILATOR, northwestern },
    { EVENT_2, NPC_GAROTHI_DECIMATOR, eastern },
    { EVENT_3, NPC_GAROTHI_DECIMATOR, eastern },
    { EVENT_3, NPC_GAROTHI_DEMOLISHER, southwestern },
};


std::vector<TalkData> const talkData =
{
    { EVENT_ON_ENTERCOMBAT,             EVENT_TYPE_TALK,            0 },
    { SPELL_REVERBERATING_STRIKE,       EVENT_TYPE_TALK,            1 },
    { SPELL_RUINER,                     EVENT_TYPE_TALK,            2 },
    { SPELL_APOCALYPSE_PROTOCOL,        EVENT_TYPE_TALK,            3 },
    { SPELL_APOCALYPSE_PROTOCOL,        EVENT_TYPE_TALK,            4 },
    { SPELL_PURGING_PROTOCOL,           EVENT_TYPE_TALK,            5 },
    { EVENT_ON_JUSTDIED,                EVENT_TYPE_TALK,            14 },
};

///.go creature id
struct boss_kingaroth : public BossAI
{
    boss_kingaroth(Creature* creature) : BossAI(creature, DATA_KINGAROTH) { Initialize(); }

    void Initialize()
    {
        //SetDungeonEncounterID(2088);
        LoadTalkData(&talkData);
        SetCombatMovement(false);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SetBossState(DATA_KINGAROTH, DONE);
        me->GetScheduler().Schedule(500ms, [this](TaskContext context)
        {
            //if(me->GetPositionZ()<1873.f)
            me->NearTeleportTo(me->GetHomePosition());
            context.Repeat(500ms);
        });
        if (me->FindNearestCreature(128303, 100.0f, true))
            me->SummonCreature(128303, Position(-10574.7998f, 8211.94f, 1871.459961f, 4.71183f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
    }

    void DoAction(int32 action) override
    {
        if (action == 1)
        {
            uint64 damage = 0.06f * me->GetMaxHealth();
            uint64 ohealth = me->GetHealth() - damage;
            me->SetHealth(ohealth > 0 ? ohealth : 0);
            if (ohealth <= 0)
                me->KillSelf();
        }
    }

    void LoadNPC(uint32 event, const CustomSpawnData* data)
    {
        while (data->event)
        {
            if (data->event == event)
                me->SummonCreature(data->npcId, Position(data->pos), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            ++data;
        }
    }

    void ScheduleTasks() override
    {
        wave = EVENT_1;
        PhaseStatus = PHASE_01;
        events.ScheduleEvent(SPELL_APOCALYPSE_PROTOCOL, 32s);//32
        events.ScheduleEvent(SPELL_RUINER, 21s);
        events.ScheduleEvent(SPELL_DIABOLIC_BOMB, 11s);
        events.ScheduleEvent(SPELL_FORGING_STRIKE, 6s);
        events.ScheduleEvent(SPELL_REVERBERATING_STRIKE, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_PURGING_PROTOCOL:
        {
            if (wave > EVENT_1)
                Talk(6);
            PhaseStatus = PHASE_01;
            events.Reset();
            events.ScheduleEvent(SPELL_RUINER, 21s);
            events.ScheduleEvent(SPELL_DIABOLIC_BOMB, 11s);
            events.ScheduleEvent(SPELL_FORGING_STRIKE, 6s);
            events.ScheduleEvent(SPELL_REVERBERATING_STRIKE, 15s);
            events.ScheduleEvent(SPELL_APOCALYPSE_PROTOCOL, 77s);
            break;
        }
        case SPELL_APOCALYPSE_PROTOCOL:
        {
            PhaseStatus = PHASE_02;
            events.Reset();
            events.ScheduleEvent(SPELL_APOCALYPSE_BLAST, 10s);
            events.ScheduleEvent(SPELL_FLAMES_OF_THE_FORGE, 10s);
            events.ScheduleEvent(SPELL_PURGING_PROTOCOL, 43s);
            LoadNPC(wave, spawnData);
            wave++;
            if (wave > EVENT_3)
                wave = EVENT_1;
            GetTalkData(SPELL_APOCALYPSE_PROTOCOL);
            DoCast(SPELL_APOCALYPSE_PROTOCOL);
            //events.Repeat(77s);
            break;
        }
        case SPELL_RUINER:
        {
            GetTalkData(SPELL_RUINER);
            if (IsMythic())
                DoCast(SPELL_EMPOWERED_RUINER);
            DoCast(SPELL_RUINER);
            events.Repeat(29s);
            break;
        }
        case SPELL_DIABOLIC_BOMB:
        {
            if(IsMythic())
                DoCast(SPELL_EMPOWERED_DIABOLIC_BOMB);
            DoCast(SPELL_DIABOLIC_BOMB);
            events.Repeat(20s);
            break;
        }
        case SPELL_FORGING_STRIKE:
        {
            DoCast(SPELL_FORGING_STRIKE);
            events.Repeat(15s);
            break;
        }
        case SPELL_REVERBERATING_STRIKE:
        {
            GetTalkData(SPELL_REVERBERATING_STRIKE);
            DoCast(SPELL_REVERBERATING_STRIKE);
            events.Repeat(28s);
            break;
        }
        case SPELL_APOCALYPSE_BLAST:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                me->CastSpell(target, SPELL_APOCALYPSE_BLAST, true);
            events.Repeat(10s);
            break;
        }
        case SPELL_FLAMES_OF_THE_FORGE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                me->CastSpell(target, SPELL_FLAMES_OF_THE_FORGE, true);
            events.Repeat(10s);
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
            instance->DoPlayConversation(5609);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        }
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);
        switch (summon->GetEntry())
        {
        case NPC_GAROTHI_ANNIHILATOR:
        case NPC_GAROTHI_DECIMATOR:
        case NPC_GAROTHI_DEMOLISHER:
        {
            summon->SetFaction(me->GetFaction());
            break;
        }
        }
    }
    uint8 PhaseStatus;
    bool hp70 = false;
    bool hp40 = false;
    bool IsLock;
    uint8 wave = 1;
    uint8 PHASE_01;
    uint8 PHASE_02;
};


struct npc_garothi_kingaroth_mobs : public ScriptedAI
{
    npc_garothi_kingaroth_mobs(Creature* creature) : ScriptedAI(creature) {  }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* boss = me->FindNearestCreature(NPC_KINGAROTH, 150.0f, true))
            boss->AI()->DoAction(1);
    }
    void EnterCombat(Unit* /*attacker*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GAROTHI_ANNIHILATOR:
            events.ScheduleEvent(SPELL_ANNIHILATION, 16s);
            break;
        case NPC_GAROTHI_DECIMATOR:
            events.ScheduleEvent(SPELL_DECIMATION, 11s);
            break;
        case NPC_GAROTHI_DEMOLISHER:
            events.ScheduleEvent(SPELL_DEMOLISH, 16s);
            break;
        default:
            break;
        }
        events.ScheduleEvent(SPELL_INITIALIZING, 30s);
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
        case SPELL_INITIALIZING:
            DoCast(SPELL_INITIALIZING);
            break;
        case SPELL_DECIMATION:
            DoCast(SPELL_DECIMATION);
            events.Repeat(16s);
            break;
        case SPELL_DEMOLISH:
            DoCast(SPELL_DEMOLISH);
            events.Repeat(11s);
            break;
        case SPELL_ANNIHILATION:
            DoCast(SPELL_ANNIHILATION);
            events.Repeat(16s);
            break;
        }
        DoMeleeAttackIfReady();
    }
};


void AddSC_boss_kingaroth()
{
    RegisterCreatureAI(boss_kingaroth);
    RegisterCreatureAI(npc_garothi_kingaroth_mobs);
}
