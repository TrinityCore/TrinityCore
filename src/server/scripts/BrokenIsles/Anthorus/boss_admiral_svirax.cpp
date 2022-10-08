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
/// .go -2826.932, 10857.5, 139.512 1712
enum Spells
{
    SPELL_CHAOS_PULSE = 257974,//share radom 2 player

    NPC_FANATICAL_PYROMANCER = 127724,
    SPELL_PYROBLAST = 246505,

    NPC_FELBLADE_SHOCKTROOPER = 127725,
    SPELL_BLADESTORM = 253038,


    SPELL_ENTROPIC_MINE_2 = 257262,
    SPELL_ENTROPIC_BLAST = 253290,//after 3:45

    NPC_ADMIRALS_POD = 122554,
    SPELL_WITHERING_FIRE = 245103, //[Admiral's Pod]'


    ///Use Chief Engineer Ishkar's pod
    SPELL_FELSHIELD_EMITTER = 244902, //summon ?????
    NPC_FELSHIELD_EMITTER = 122867,
    ///Phase Three - Active Boss: General Erodus
    SPELL_SUMMON_DISRUPTOR_BEACON = 245174,
    NPC_DISRUPTOR_BEACON = 122884,
    //general
    SPELL_EXPLOIT_WEAKNESS = 244892,
    SPELL_SHOCK_GRENADE = 244722, // ???? mythic
    SPELL_ASSUME_COMMAND = 245227,//?? 90s
    //In Pod
    //Admiral Svirax
    SPELL_FUSILLADE = 244625, //30s
    //Chief Engineer Ishkar
    SPELL_ENTROPIC_MINE = 245161,//5s every 10s    summon 122992/entropic-mine
    //General Erodus
    SPELL_SUMMON_REINFORCEMENTS = 245546,//8s every 8.4s  summon 1 NPC_FANATICAL_PYROMANCER 2 NPC_FELBLADE_SHOCKTROOPER


    NPC_CHIEF_ENGINEER_ISHKAR = 122369,
    NPC_GENERAL_ERODUS = 122333,
    /*
    NPC_CHIEF_ENGINEER_ISHKAR
    ??????????
    NPC_GENERAL_ERODUS
    ???!??!
    NPC_CHIEF_ENGINEER_ISHKAR
    ????
    NPC_GENERAL_ERODUS
    ????
    NPC_CHIEF_ENGINEER_ISHKAR????,???????? ?
    ????
    NPC_CHIEF_ENGINEER_ISHKAR ??
    */
};

Position const phase2pos = { -2809.739f,10829.299f,139.751f,2.05f };
Position const phase3pos = { -2859.6398f,10864.7998f,139.74f,5.9322f };
//Phase One - Active Boss: Admiral Svirax
//Phase Two - Active Boss: Chief Engineer Ishkar
//Phase Three - Active Boss: General Erodus
///.go creature id 102679
struct boss_admiral_svirax : public BossAI
{
    boss_admiral_svirax(Creature* creature) : BossAI(creature, DATA_ADMIRAL_SVIRAX) { Initialize(); }

    void Initialize()
    {
        //SetDungeonEncounterID,(2070);
    }

    void DamageTaken(Unit* done_by, uint32 &damage) override
    {
        _DamageTaken(done_by, damage);

        SubDamageTaken(NPC_CHIEF_ENGINEER_ISHKAR, damage);
        SubDamageTaken(NPC_GENERAL_ERODUS, damage);
    }

    void SubDamageTaken(uint32 dragonid, uint32 &damage)
    {
        if (Creature* target = me->FindNearestCreature(dragonid, 500.0f))
        {
            uint64 ohealth = target->GetHealth() - damage;
            target->SetHealth(ohealth > 0 ? ohealth : 0);

            if (ohealth <= 0)
                target->setDeathState(JUST_DIED);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(2);
        instance->SetBossState(DATA_ADMIRAL_SVIRAX, DONE);
        me->SummonCreature(129449, Position(-3098.5f, 10474.6298f, -112.6252f, 4.157f), TEMPSUMMON_MANUAL_DESPAWN);
        if (instance)
            instance->DoDelayedConversation(2000, 5525);
    }

    void ScheduleTasks() override
    {
        PhaseStatus = PHASE_01;
        events.ScheduleEvent(NPC_CHIEF_ENGINEER_ISHKAR, 90s);
        events.ScheduleEvent(NPC_GENERAL_ERODUS, 180s);
        //general
        events.ScheduleEvent(SPELL_EXPLOIT_WEAKNESS, 8s);
        if(IsMythic())
            events.ScheduleEvent(SPELL_SHOCK_GRENADE, 15s);
        events.ScheduleEvent(SPELL_ASSUME_COMMAND, 90s);
        events.ScheduleEvent(SPELL_CHAOS_PULSE, 15s);
        events.ScheduleEvent(SPELL_FUSILLADE, 30s);

        events.ScheduleEvent(SPELL_ENTROPIC_MINE, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case NPC_CHIEF_ENGINEER_ISHKAR:
        {
            PhaseStatus = PHASE_02;
            events.CancelEvent(SPELL_ENTROPIC_MINE);
            events.ScheduleEvent(SPELL_SUMMON_REINFORCEMENTS, 8s);
            me->SummonCreature(NPC_CHIEF_ENGINEER_ISHKAR, phase2pos, TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            break;
        }
        case NPC_GENERAL_ERODUS:
        {
            PhaseStatus = PHASE_03;
            events.CancelEvent(SPELL_SUMMON_REINFORCEMENTS);
            events.ScheduleEvent(SPELL_ENTROPIC_MINE, 5s);
            me->SummonCreature(NPC_GENERAL_ERODUS, phase2pos, TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            break;
        }
        case SPELL_EXPLOIT_WEAKNESS:
        {
            DoCast(SPELL_EXPLOIT_WEAKNESS);
            events.Repeat(8s, 9s);
            break;
        }
        case SPELL_SHOCK_GRENADE:
        {
            DoCast(SPELL_SHOCK_GRENADE);
            events.Repeat(15s);
            break;
        }
        case SPELL_ASSUME_COMMAND:
        {
            DoCast(SPELL_ASSUME_COMMAND);
            events.Repeat(90s);
            break;
        }
        case SPELL_CHAOS_PULSE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target->GetPosition(), SPELL_CHAOS_PULSE, false);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target->GetPosition(), SPELL_CHAOS_PULSE, false);
            events.Repeat(15s);
            break;
        }
        case SPELL_FUSILLADE:
        {
            DoCast(SPELL_FUSILLADE);
            events.Repeat(30s);
            break;
        }
        case SPELL_ENTROPIC_MINE:
        {
            DoCast(SPELL_ENTROPIC_MINE);
            for (uint8 i = 0; i < 5; ++i)
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                    me->CastSpell(target->GetPosition(), SPELL_CHAOS_PULSE, false);
            events.Repeat(10s);
            break;
        }
        case SPELL_SUMMON_REINFORCEMENTS:
        {
            DoCast(SPELL_SUMMON_REINFORCEMENTS);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->SummonCreature(NPC_FANATICAL_PYROMANCER, target->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->SummonCreature(NPC_CHIEF_ENGINEER_ISHKAR, target->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->SummonCreature(NPC_FELBLADE_SHOCKTROOPER, target->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(8s, 9s);
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
            Talk(0);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        }
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);
        switch (summon->GetEntry())
        {
            case NPC_CHIEF_ENGINEER_ISHKAR:
            case NPC_GENERAL_ERODUS:
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
};

struct npc_chief_engineer_ishkar_122369 : public ScriptedAI
{
    npc_chief_engineer_ishkar_122369(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void EnterCombat(Unit* /*attacker*/) override
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
        events.ScheduleEvent(SPELL_EXPLOIT_WEAKNESS, 8s);
        if (IsMythic())
            events.ScheduleEvent(SPELL_SHOCK_GRENADE, 15s);
        events.ScheduleEvent(SPELL_ASSUME_COMMAND, 90s);
        events.ScheduleEvent(SPELL_CHAOS_PULSE, 15s);
        //In Pod
        events.ScheduleEvent(SPELL_ENTROPIC_MINE, 5s);
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
        case SPELL_EXPLOIT_WEAKNESS:
        {
            DoCast(SPELL_EXPLOIT_WEAKNESS);
            events.Repeat(8s, 9s);
            break;
        }
        case SPELL_SHOCK_GRENADE:
        {
            DoCast(SPELL_SHOCK_GRENADE);
            events.Repeat(15s);
            break;
        }
        case SPELL_ASSUME_COMMAND:
        {
            DoCast(SPELL_ASSUME_COMMAND);
            events.Repeat(90s);
            break;
        }
        case SPELL_CHAOS_PULSE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_CHAOS_PULSE, false);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_CHAOS_PULSE, false);
            events.Repeat(15s);
            break;
        }
        case SPELL_ENTROPIC_MINE:
        {
            DoCast(SPELL_ENTROPIC_MINE);
            for (uint8 i = 0; i < 5; ++i)
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                    me->CastSpell(target->GetPosition(), SPELL_CHAOS_PULSE, false);
            events.Repeat(10s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* done_by, uint32 &damage) override
    {
        SubDamageTaken(NPC_ADMIRAL_SVIRAX, damage);
        SubDamageTaken(NPC_GENERAL_ERODUS, damage);
    }

    void SubDamageTaken(uint32 dragonid, uint32 &damage)
    {
        if (Creature* target = me->FindNearestCreature(dragonid, 500.0f))
        {
            uint64 ohealth = target->GetHealth() - damage;
            target->SetHealth(ohealth > 0 ? ohealth : 0);

            if (ohealth <= 0)
                target->setDeathState(JUST_DIED);
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

private:
    InstanceScript * instance;
};

struct npc_general_erodus_122333 : public ScriptedAI
{
    npc_general_erodus_122333(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void EnterCombat(Unit* /*attacker*/) override
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
        events.ScheduleEvent(SPELL_EXPLOIT_WEAKNESS, 8s);
        if (IsMythic())
            events.ScheduleEvent(SPELL_SHOCK_GRENADE, 15s);
        events.ScheduleEvent(SPELL_ASSUME_COMMAND, 90s);
        events.ScheduleEvent(SPELL_CHAOS_PULSE, 15s);
        //In Pod
        events.ScheduleEvent(SPELL_SUMMON_REINFORCEMENTS, 8s);
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
        case SPELL_EXPLOIT_WEAKNESS:
        {
            DoCast(SPELL_EXPLOIT_WEAKNESS);
            events.Repeat(8s, 9s);
            break;
        }
        case SPELL_SHOCK_GRENADE:
        {
            DoCast(SPELL_SHOCK_GRENADE);
            events.Repeat(15s);
            break;
        }
        case SPELL_ASSUME_COMMAND:
        {
            DoCast(SPELL_ASSUME_COMMAND);
            events.Repeat(90s);
            break;
        }
        case SPELL_CHAOS_PULSE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_CHAOS_PULSE, false);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_CHAOS_PULSE, false);
            events.Repeat(15s);
            break;
        }
        case SPELL_SUMMON_REINFORCEMENTS:
        {
            DoCast(SPELL_SUMMON_REINFORCEMENTS);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->SummonCreature(NPC_FANATICAL_PYROMANCER, target->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->SummonCreature(NPC_CHIEF_ENGINEER_ISHKAR, target->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->SummonCreature(NPC_FELBLADE_SHOCKTROOPER, target->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(8s, 9s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* done_by, uint32 &damage) override
    {
        SubDamageTaken(NPC_ADMIRAL_SVIRAX, damage);
        SubDamageTaken(NPC_CHIEF_ENGINEER_ISHKAR, damage);
    }

    void SubDamageTaken(uint32 dragonid, uint32 &damage)
    {
        if (Creature* target = me->FindNearestCreature(dragonid, 500.0f))
        {
            uint64 ohealth = target->GetHealth() - damage;
            target->SetHealth(ohealth > 0 ? ohealth : 0);

            if (ohealth <= 0)
                target->setDeathState(JUST_DIED);
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

private:
    InstanceScript * instance;
};

struct npc_entropic_mine_122992 : public ScriptedAI
{
    npc_entropic_mine_122992(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->CastSpell(me, SPELL_ENTROPIC_MINE_2, true);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 5.0f, false))
        {
            me->CastSpell(who, SPELL_ENTROPIC_BLAST, true);
            me->DespawnOrUnsummon();
        }
    }
};

void AddSC_boss_admiral_svirax()
{
    RegisterCreatureAI(boss_admiral_svirax);
    RegisterCreatureAI(npc_chief_engineer_ishkar_122369);
    RegisterCreatureAI(npc_general_erodus_122333);
    RegisterCreatureAI(npc_entropic_mine_122992);
}
