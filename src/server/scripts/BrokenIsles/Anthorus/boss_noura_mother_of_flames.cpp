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
    //SPELL_SENSE_OF_DREAD = 253753,
    SPELL_SENSE_OF_DREAD = 258018,//??
    SPELL_SHIVAN_PACT = 253203,//????? 20yard

    SPELL_TORMENT_OF_KHAZ_GOROTH = 250333,//250333,244733
    SPELL_TORMENT_OF_NORGANNON = 250334,//250334, 244740
    SPELL_TORMENT_OF_AMAN_THUL = 250335,
    SPELL_TORMENT_OF_GOLGANNETH = 249793,//249793 ,244756

    //Noura, Mother of Flames
    SPELL_FIERY_STRIKE = 244899,//???? 11s 10-11s
    SPELL_WHIRLING_SABER = 245627, //????? 8s  35s  123348   cast 245630 245629
    SPELL_FULMINATING_PULSE = 253520,//???? 20s   40s

    //Asara, Mother of Night
    SPELL_TOUCH_OF_DARKNESS = 245303,//????
    SPELL_SHADOW_BLADES = 246329,//???? 11s   27-28s  258932,245290,
    SPELL_STORM_OF_DARKNESS = 252861,//???? 26s 57s

    //Diima, Mother of Gloom
    SPELL_FLASHFREEZE = 245518,//????  10s
    //SPELL_CHILLED_BLOOD_1 = 245532,
    SPELL_CHILLED_BLOOD_2 = 245586,//???? 6-7s   25-16s
    //SPELL_ORB_OF_FROST = 253697,
    SPELL_ORB_OF_FROST = 253650,//???? 30s

    //Thu'raya, Mother of the Cosmos (Mythic)
    SPELL_FACE_RANDOM_TARGET = 256432,
    NPC_SHADOW_BLADE = 123086,
};


enum
{
    EVENT_STEP_1 = 1,
    EVENT_STEP_2 = 2,
    EVENT_STEP_3 = 3,
    EVENT_STEP_4 = 4,
    EVENT_STEP_5 = 5,
    EVENT_STEP_6 = 6,
    EVENT_STEP_7 = 7,
    EVENT_STEP_8 = 8,

    NPC_TORMENT_OF_NORGANNON = 123503,
    SPELL_VISAGE_OF_THE_TITAN = 249863,
    NPC_TORMENT_OF_AMANTHUL = 125837,
    SPELL_MACHINATIONS_OF_AMANTHUL = 250095,
    NPC_TORMENT_OF_KHAZGOROTH = 124166,
    SPELL_FLAMES_OF_KHAZGOROTH = 245671,
    NPC_TORMENT_OF_GOLGANNETH = 124164,
    SPELL_FURY_OF_GOLGANNETH = 246739,
};

struct CustomSpawnData
{
    uint32 event, npcId;
    float X;
    float Y;
    float Z;
    float orientation;
};

CustomSpawnData const spawnData[] =
{
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12672.9f, -2809.39f, 2476.12f, 6.22161f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12593.7f, -2809.54f, 2476.12f, 3.12464f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12645.1f, -2859.03f, 2476.1f, 1.56893f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12673.5f, -2799.74f, 2476.12f, 6.22161f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12593.7f, -2830.61f, 2476.12f, 3.12464f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12654.7f, -2860.16f, 2476.11f, 1.56893f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12592.7f, -2840.41f, 2476.11f, 3.12464f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12614.1f, -2859.72f, 2476.07f, 1.56893f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12614.0f, -2779.59f, 2476.1f, 4.7037f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12592.7f, -2800.43f, 2476.11f, 3.12464f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12654.9f, -2779.8f, 2476.1f, 4.7037f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12634.3f, -2781.25f, 2476.1f, 4.7037f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12673.5f, -2839.49f, 2476.13f, 6.22161f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12672.8f, -2819.89f, 2476.12f, 6.22161f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12644.8f, -2780.8f, 2476.1f, 4.7037f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12634.7f, -2858.38f, 2476.08f, 1.56893f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12673.6f, -2829.97f, 2476.13f, 6.22161f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12594.2f, -2819.78f, 2476.11f, 3.12464f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12623.6f, -2780.66f, 2476.1f, 4.7037f },
{ EVENT_STEP_1, NPC_TORMENT_OF_NORGANNON, -12624.0f, -2858.77f, 2476.07f, 1.56893f },
{ EVENT_STEP_2, NPC_TORMENT_OF_AMANTHUL, -12602.6f, -2804.43f, 2475.37f, 3.58119f },
{ EVENT_STEP_2, NPC_TORMENT_OF_AMANTHUL, -12649.5f, -2787.94f, 2475.15f, 5.16065f },
{ EVENT_STEP_2, NPC_TORMENT_OF_AMANTHUL, -12667.2f, -2834.27f, 2475.08f, 0.426257f },
{ EVENT_STEP_2, NPC_TORMENT_OF_AMANTHUL, -12618.8f, -2851.78f, 2475.34f, 2.01902f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12656.6f, -2797.45f, 2475.54f, 5.48286f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12634.9f, -2781.54f, 2476.91f, 4.72128f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12656.8f, -2842.03f, 2475.55f, 0.808043f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12612.2f, -2797.81f, 2475.54f, 3.95917f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12677.0f, -2820.13f, 2476.94f, 0.0032677f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12586.8f, -2819.73f, 2476.91f, 3.13858f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12612.1f, -2842.18f, 2475.54f, 2.31361f },
{ EVENT_STEP_3, NPC_TORMENT_OF_KHAZGOROTH, -12634.3f, -2859.33f, 2476.89f, 1.57006f },
{ EVENT_STEP_4, NPC_TORMENT_OF_GOLGANNETH, -12634.4f, -2860.38f, 2475.23f, 1.57003f },
{ EVENT_STEP_4, NPC_TORMENT_OF_GOLGANNETH, -12590.5f, -2820.04f, 2475.17f, 3.14524f },
{ EVENT_STEP_4, NPC_TORMENT_OF_GOLGANNETH, -12634.5f, -2780.56f, 2475.23f, 4.71457f },
{ EVENT_STEP_4, NPC_TORMENT_OF_GOLGANNETH, -12676.6f, -2820.15f, 2475.35f, 0.0124727f },

};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_ENTERCOMBAT,       EVENT_TYPE_TALK,            0 },
    { EVENT_ON_JUSTDIED,          EVENT_TYPE_TALK,            1 },
};

struct boss_noura_mother_of_flames : public BossAI
{
    boss_noura_mother_of_flames(Creature* creature) : BossAI(creature, DATA_NOURA_MOTHER_OF_FLAMES) { Initialize(); }

    void Initialize()
    {
        //SetDungeonEncounterID(2073);
        LoadTalkData(&talkData);
    }

    void LoadNPC(uint32 event, const CustomSpawnData* data)
    {
        while (data->event)
        {
            if (data->event == event)
                me->SummonCreature(data->npcId, Position(data->X, data->Y, data->Z, data->orientation), TEMPSUMMON_DEAD_DESPAWN, WEEK);
            ++data;
        }
    }

    void DamageTaken(Unit* done_by, uint32 &damage) override
    {
        _DamageTaken(done_by, damage);

        SubDamageTaken(NPC_ASARA_MOTHER_OF_NIGHT, damage);
        SubDamageTaken(NPC_DIIMA_MOTHER_OF_GLOOM, damage);
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
        //instance->DoDelayedConversation(5000, 5752);
    }

    void ScheduleTasks() override
    {
        PhaseStatus = PHASE_01;

        events.ScheduleEvent(EVENT_STEP_1, 80s);
        events.ScheduleEvent(SPELL_FIERY_STRIKE, 11s);
        events.ScheduleEvent(SPELL_WHIRLING_SABER, 8s);
        events.ScheduleEvent(SPELL_FULMINATING_PULSE, 20s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_STEP_1:
        {
            LoadNPC(EVENT_STEP_1, spawnData);
            events.ScheduleEvent(EVENT_STEP_2, 80s);
            break;
        }
        case EVENT_STEP_2:
        {
            LoadNPC(EVENT_STEP_2, spawnData);
            events.ScheduleEvent(EVENT_STEP_3, 80s);
            break;
        }
        case EVENT_STEP_3:
        {
            LoadNPC(EVENT_STEP_3, spawnData);
            events.ScheduleEvent(EVENT_STEP_4, 80s);
            break;
        }
        case EVENT_STEP_4:
        {
            LoadNPC(EVENT_STEP_4, spawnData);
            events.ScheduleEvent(EVENT_STEP_1, 80s);
            break;
        }
        case SPELL_FIERY_STRIKE:
        {
            DoCast(SPELL_FIERY_STRIKE);
            events.Repeat(10s, 11s);
            break;
        }
        case SPELL_WHIRLING_SABER:
        {
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_WHIRLING_SABER, false);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_WHIRLING_SABER, false);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_WHIRLING_SABER, false);
            events.Repeat(35s);
            break;
        }
        case SPELL_FULMINATING_PULSE:
        {
            DoCast(SPELL_FULMINATING_PULSE);
            events.Repeat(40s);
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
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
            me->RemoveAurasDueToSpell(244733);
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
    bool IsLock;
    uint8 PHASE_01;
};

struct npc_asara_mother_of_night_122467 : public ScriptedAI
{
    npc_asara_mother_of_night_122467(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
    {
        SubDamageTaken(NPC_NOURA_MOTHER_OF_FLAMES, damage);
        SubDamageTaken(NPC_DIIMA_MOTHER_OF_GLOOM, damage);
    }

    void SubDamageTaken(uint32 dragonid, uint32 &damage)
    {
        if (Creature* target = me->FindNearestCreature(dragonid, 500.0f))
        {
            uint64 ohealth = target->GetHealth() - damage;
            target->SetHealth(ohealth > 0 ? ohealth : 0);

            if (ohealth <= 0)
            {
                target->setDeathState(JUST_DIED);
                if (dragonid == NPC_NOURA_MOTHER_OF_FLAMES)
                    target->SetDynamicFlags(UNIT_DYNFLAG_LOOTABLE);
            }

        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SHADOW_BLADE:
        {
            summon->SetFaction(me->GetFaction());
            break;
        }
        }
    }

    void EnterCombat(Unit* /*victim*/)
    {
        Talk(0);
       events.ScheduleEvent(SPELL_SHADOW_BLADES, 11s);
       events.ScheduleEvent(SPELL_STORM_OF_DARKNESS, 26s);
       events.ScheduleEvent(SPELL_TOUCH_OF_DARKNESS, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_SHADOW_BLADES:
            {
                DoCast(SPELL_SHADOW_BLADES);
                AddTimedDelayedOperation(500, [this]() -> void
                {
                    if (Creature* shadowblade = me->SummonCreature(NPC_SHADOW_BLADE, me->GetRandomNearPosition(5.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        {
                            shadowblade->SetFacingToObject(target1);
                            shadowblade->AI()->DoAction(1);
                        }
                    }
                });
                AddTimedDelayedOperation(1000, [this]() -> void
                {
                    if (Creature* shadowblade = me->SummonCreature(NPC_SHADOW_BLADE, me->GetRandomNearPosition(5.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        {
                            shadowblade->SetFacingToObject(target1);
                            shadowblade->AI()->DoAction(1);
                        }
                    }
                });
                AddTimedDelayedOperation(1500, [this]() -> void
                {
                    if (Creature* shadowblade = me->SummonCreature(NPC_SHADOW_BLADE, me->GetRandomNearPosition(5.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                        {
                            shadowblade->SetFacingToObject(target1);
                            shadowblade->AI()->DoAction(1);
                        }
                    }
                });
                events.Repeat(27s, 28s);
                break;
            }
            case SPELL_STORM_OF_DARKNESS:
            {
                DoCast(SPELL_STORM_OF_DARKNESS);
                events.Repeat(57s);
                break;
            }
            case SPELL_TOUCH_OF_DARKNESS:
            {
                DoCast(SPELL_TOUCH_OF_DARKNESS);
                events.Repeat(10s);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;
            me->RemoveAurasDueToSpell(244740);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
        }
    }
    bool IsLock;
};

struct npc_diima_mother_of_gloom_122469 : public ScriptedAI
{
    npc_diima_mother_of_gloom_122469(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
    {
        SubDamageTaken(NPC_NOURA_MOTHER_OF_FLAMES, damage);
        SubDamageTaken(NPC_ASARA_MOTHER_OF_NIGHT, damage);
    }

    void SubDamageTaken(uint32 dragonid, uint32 &damage)
    {
        if (Creature* target = me->FindNearestCreature(dragonid, 500.0f))
        {
            uint64 ohealth = target->GetHealth() - damage;
            target->SetHealth(ohealth > 0 ? ohealth : 0);

            if (ohealth <= 0)
            {
                target->setDeathState(JUST_DIED);
                if (dragonid == NPC_NOURA_MOTHER_OF_FLAMES)
                    target->SetDynamicFlags(UNIT_DYNFLAG_LOOTABLE);
            }

        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case 1:
        {
            summon->SetFaction(me->GetFaction());
            break;
        }
        }
    }

    void EnterCombat(Unit* /*victim*/)
    {
        Talk(0);
        events.ScheduleEvent(SPELL_FLASHFREEZE, 10s);
        events.ScheduleEvent(SPELL_CHILLED_BLOOD_2, 6s, 7s);
        events.ScheduleEvent(SPELL_ORB_OF_FROST, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_FLASHFREEZE:
            {
                DoCast(SPELL_FLASHFREEZE);
                events.Repeat(10s);
                break;
            }
            case SPELL_CHILLED_BLOOD_2:
            {
                DoCast(SPELL_CHILLED_BLOOD_2);
                events.Repeat(15s, 16s);
                break;
            }
            case SPELL_ORB_OF_FROST:
            {
                DoCast(SPELL_ORB_OF_FROST);
                events.Repeat(30s);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
            me->RemoveAurasDueToSpell(244756);
        }
    }
    bool IsLock;
};
//SPELL_VISAGE_OF_THE_TITAN
struct npc_torment_of_norgannon_123503 : public ScriptedAI
{
    npc_torment_of_norgannon_123503(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->GetMotionMaster()->Clear();
        me->AddAura(SPELL_VISAGE_OF_THE_TITAN);
        me->GetMotionMaster()->MoveAwayAndDespawn(250.0f, 60000);
    }

    void UpdateAI(uint32 diff) override { }
};
//SPELL_MACHINATIONS_OF_AMANTHUL
struct npc_torment_of_amanthul_125837 : public ScriptedAI
{
    npc_torment_of_amanthul_125837(Creature* creature) : ScriptedAI(creature)
    {
        events.ScheduleEvent(SPELL_MACHINATIONS_OF_AMANTHUL, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_MACHINATIONS_OF_AMANTHUL:
        {
            me->CastSpell(me, SPELL_MACHINATIONS_OF_AMANTHUL, true);
            events.Repeat(20s);
            break;
        }
        }
    }
};
//SPELL_FLAMES_OF_KHAZGOROTH
struct npc_torment_of_khazgoroth_124166 : public ScriptedAI
{
    npc_torment_of_khazgoroth_124166(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->CastSpell(me, SPELL_FLAMES_OF_KHAZGOROTH, true);
    }

    void UpdateAI(uint32 diff) override {}

};
//SPELL_FURY_OF_GOLGANNETH
struct npc_torment_of_golganneth_124164 : public ScriptedAI
{
    npc_torment_of_golganneth_124164(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        events.ScheduleEvent(SPELL_FLASHFREEZE, 5s);
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
        case SPELL_FLASHFREEZE:
        {
            DoCast(SPELL_FLASHFREEZE);
            events.Repeat(5s);
            break;
        }
        }
        DoSpellAttackIfReady(SPELL_FURY_OF_GOLGANNETH);
    }
};

struct npc_whirling_saber_123348 : public ScriptedAI
{
    npc_whirling_saber_123348(Creature* creature) : ScriptedAI(creature)
    {
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
        me->CastSpell(me, 245630, true);
        me->DespawnOrUnsummon(5000);
    }

    void UpdateAI(uint32 diff) override { }
};

struct npc_shadow_blade_123086 : public ScriptedAI
{
    npc_shadow_blade_123086(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
        me->SetSpeed(UnitMoveType::MOVE_RUN, 25.0f);
        me->CastSpell(me, 258932, true);
        me->CastSpell(me, 245290, true);
    }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->GetMotionMaster()->MoveAwayAndDespawn(100.0f, 20000);
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && !me->IsWithinDist(who, 5.0f, true))
            who->RemoveAurasDueToSpell(245290);
    }

    void UpdateAI(uint32 diff) override { }
};

void AddSC_boss_noura_mother_of_flames()
{
    RegisterCreatureAI(boss_noura_mother_of_flames);
    RegisterCreatureAI(npc_asara_mother_of_night_122467);
    RegisterCreatureAI(npc_diima_mother_of_gloom_122469);
    RegisterCreatureAI(npc_torment_of_norgannon_123503);
    RegisterCreatureAI(npc_torment_of_amanthul_125837);
    RegisterCreatureAI(npc_torment_of_khazgoroth_124166);
    RegisterCreatureAI(npc_torment_of_golganneth_124164);
    RegisterCreatureAI(npc_whirling_saber_123348);
    RegisterCreatureAI(npc_shadow_blade_123086);
}
