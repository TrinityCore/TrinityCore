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
#include "PhasingHandler.h"
#include "antorus_the_burning_throne.h"

enum Spells
{
    SPELL_PANTHEON_INTRO_MOVIE = 256945,
    SPELL_RAID_ANTORUS_BONUS_ROLL_PROMPT_BOSS11_LOOT = 250608, //SPELL_EFFECT_LOOT A 75888 B 438
    //Stage One: Storm and Sky
    SPELL_SWEEPING_SCYTHE = 248499,//phase 1 every 5-6s  phase2  start 16-17s
    SPELL_CONE_OF_DEATH = 248165,// start 30s  19.4-24   256457,
    SPELL_SOULBLIGHT_ORB = 248317,// start 35  22-32
    SPELL_TORTURED_RAGE = 257296,//12 13-16
    SPELL_SKY_AND_SEA = 255594,//10  24.9-27.8
    //Stage one Mythic
    SPELL_SARGERAS_GAZE = 258068,//8 35
    //Stage Two: The Protector Redeemed
    SPELL_GOLGANNETHS_WRATH = 255648,
    SPELL_SOULBOMB = 251570,//30s 42s
    SPELL_SOULBURST = 250669,//30s 42s
    SPELL_EDGE_OF_OBLITERATION = 255826,//21s  34s
    //Aggramar's Aid BUFF
    SPELL_AVTAR_OF_AGGRAMAR = 255199,//21s 60S
    SPELL_AGGRAMARS_BOON = 255200,// player buff nearby
    //Stage Three: The Arcane Masters
    SPELL_CLEARALLDEBUFFS = 34098,
    SPELL_COSMIC_RAY = 252729,//30s 20s
    SPELL_COSMIC_BEACON = 252616,//40s  20s   14S NEXT
    //257645/Aman'thul will cast   on Argu
    NPC_AMANTHUL = 125885,
    SPELL_TEMPORAL_BLAST = 257645,

    //Norgannon's Aid 15 seconds after all the adds have spawned, Norgannon casts  .
    NPC_NORGANNON = 126266,
    SPELL_THE_DISCS_OF_NORGANNNON = 252516, //15s
    //Stage Three Mythic
    SPELL_SOULRENDING_SCYTHE = 258838,// 8-9s
    SPELL_SENTENCE_OF_SARGERAS = 257966,//35s
    SPELL_EDGE_OF_ANNIHILATION = 258834, // 5-6s
    //Stage Four: The Gift of Life, The Forge of Loss (Non Mythic)
    //Argus has replaced  with
    SPEEL_DEADLY_SCYTHE = 258039, // 5-6s
    //256388 Initialization Sequence 258029 Initialization Sequence (Mythic)
    SPELL_REORIGINATION_MODULE = 256389, //48s
    SPELL_REAP_SOUL = 256542,
    SPELL_GIFT_OF_THE_LIFEBINDER = 257619, //8

    //PHASE 1
    SPELL_DEATH_FOG = 248167, //SPELL_CONE_OF_DEATH SPELL_SOULBLIGHT_ORB

    //Golganneth's Aid BUFF
    SPELL_STRENGTH_OF_THE_SEA_MARK = 258647,
    SPELL_STRENGTH_OF_THE_SKY_MARK = 258646,
    SPELL_STRENGTH_OF_THE_SEA_AT = 257306,//253889
    SPELL_STRENGTH_OF_THE_SKY_AT = 257313,//253884
    SPELL_STRENGTH_OF_THE_SEA = 253901,
    SPELL_STRENGTH_OF_THE_SKY = 253903,
    //PHASE 2

    SPELL_VOLATILE_SOUL = 252280,

    SPELL_SOULBURST_DETONATION = 251572,




    //PHASE 3

    //Constellar Designate adds can not be crowd controlled
    NPC_CONSTELLAR_DESIGNATE = 127192,
    SPELL_STARBLAST = 253061,// RANDOM

    SPELL_COSMIC_SMASH = 252634,
    SPELL_SWORD_OF_THE_COSMOS = 255496,
    SPELL_COSMIC_POWER = 255935,


    //PHASE 4
    //Eonar's Aid Shortly after the raid dies, Eonar will create a [Gift of the Lifebinder] tree.
    NPC_EONAR = 126267,
    NPC_GIFT_OF_THE_LIFEBINDER = 129386,

    SPELL_END_OF_ALL_THINGS = 256544,

    NPC_SOULBLIGHT_ORB = 125008,
    SPELL_BLIGHT_ORB = 248376,
    SPELL_SOULBLIGHT = 248396,

    NPC_HUNGERING_SOUL = 129635,

    NPC_REORIGINATION_MODULE = 127809,
    SPELL_INITIALIZATION_SEQUENCE = 256388,
    SPELL_REORIGINATION_MODULE_DMG = 256396,
    NPC_GOLGANNETH = 126268,

    HP_70 = 70,
    HP_40 = 40,
    HP_30 = 30,
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
    EVENT_2 = 2,
    EVENT_3 = 3,
    EVENT_4 = 4,
    EVENT_5 = 5,
};

/*const TalkData talkData[] =
{
    { TALK_1,                    EVENT_TYPE_TALK,            0 },
    { TALK_2,                    EVENT_TYPE_TALK,            EVENT_ON_HP60 },
    { TALK_3,                    EVENT_TYPE_SPELL,           SPELL_PANTHEON_INTRO_MOVIE },
};*/

struct CustomSpawnData
{
    uint32 event, npcId;
    float X;
    float Y;
    float Z;
    float orientation;
    uint32 spellId;
};

CustomSpawnData const spawnData[] =
{
    { EVENT_2, NPC_HUNGERING_SOUL, 2896.31f, -4556.56f, 292.006f, 3.22141f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2903.4f, -4585.5f, 292.017f, 1.79704f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2857.86f, -4571.63f, 292.006f, 4.87108f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2879.84f, -4573.46f, 292.007f, 1.74118f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2844.35f, -4532.37f, 292.029f, 4.84296f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2877.66f, -4567.0f, 292.025f, 5.04947f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2859.73f, -4525.18f, 292.175f, 1.8014f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2842.71f, -4584.44f, 292.006f, 3.13497f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2855.26f, -4584.71f, 291.996f, 6.26141f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2828.92f, -4553.31f, 292.006f, 3.20696f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2881.98f, -4536.66f, 292.068f, 1.7638f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2853.42f, -4598.2f, 292.007f, 4.83248f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2867.11f, -4600.67f, 292.029f, 6.23542f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2869.46f, -4558.69f, 292.006f, 3.21288f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2830.55f, -4569.13f, 292.044f, 0.0563265f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2847.55f, -4552.09f, 292.012f, 0.0653512f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2850.34f, -4579.1f, 291.998f, 1.75584f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2833.31f, -4591.49f, 292.028f, 0.0161866f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2838.21f, -4560.88f, 292.005f, 0.0540929f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2898.77f, -4564.39f, 292.009f, 1.78361f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2881.08f, -4579.98f, 292.007f, 1.74492f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2870.5f, -4582.95f, 291.995f, 1.73396f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2851.25f, -4532.19f, 292.113f, 1.74584f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2854.91f, -4553.16f, 292.006f, 4.87108f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2906.33f, -4576.39f, 292.109f, 6.2386f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2895.75f, -4601.13f, 292.207f, 0.0153108f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2885.34f, -4605.63f, 292.157f, 4.87257f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2838.25f, -4576.13f, 292.002f, 0.0291354f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2840.19f, -4582.78f, 292.006f, 4.87085f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2893.27f, -4541.35f, 292.006f, 1.847f, 0 },
    { EVENT_2, NPC_HUNGERING_SOUL, 2872.38f, -4539.45f, 292.126f, 3.23133f, 0 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2890.83f, -4538.69f, 292.028f, 4.02036f, 255430 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2852.88f, -4606.91f, 292.029f, 1.22925f, 255433 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2888.44f, -4600.9f, 292.028f, 2.14662f, 255425 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2905.77f, -4570.62f, 292.028f, 3.06515f, 255429 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2828.07f, -4553.25f, 292.029f, 5.9277f, 255419 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2856.43f, -4533.67f, 292.027f, 5.00975f, 255418 },
    { EVENT_3, NPC_CONSTELLAR_DESIGNATE, 2828.72f, -4584.8f, 292.029f, 0.422982f, 255422 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2905.27f, -4557.19f, 297.089f, 4.4855f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2838.21f, -4539.79f, 297.133f, 6.00393f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2853.1f, -4605.46f, 297.107f, 0.383972f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2826.74f, -4566.52f, 297.089f, 5.68977f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2855.64f, -4529.42f, 297.227f, 3.40339f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2898.28f, -4592.43f, 297.089f, 3.03687f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2899.85f, -4545.43f, 297.089f, 1.67552f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2868.54f, -4607.81f, 297.131f, 3.28122f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2826.76f, -4569.67f, 297.089f, 3.90954f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2864.9f, -4527.89f, 297.255f, 1.78024f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2906.68f, -4566.02f, 297.089f, 1.85005f, 0 },
    { EVENT_4, NPC_REORIGINATION_MODULE, 2856.67f, -4606.57f, 297.114f, 1.01229f, 0 },
    { EVENT_5, NPC_GIFT_OF_THE_LIFEBINDER, 2893.73f, -4545.36f, 292.028f, 3.77829f, 0 },
};

///.go creature id
struct boss_argus_the_unmaker : public BossAI
{
    boss_argus_the_unmaker(Creature* creature) : BossAI(creature, DATA_ARGUS_THE_UNMAKER) { Initialize(); }

    Position pos1 = { 2877.458f, -4592.133f, 292.0213f, 3.341679f };
    Position pos2 = { 3112.8728f, -9635.2373f, 62.25f, 3.137645f };
    uint32 _mobsCount = 0;
    void Initialize()
    {
        ////SetDungeonEncounterID(2092);
        //LoadTalkData(&talkData);
    }

    void LoadNPC(uint32 event, const CustomSpawnData* data)
    {
        while (data->event)
        {
            if (data->event == event)
                if (TempSummon* personalCreature = me->SummonCreature(data->npcId, Position(data->X, data->Y, data->Z, data->orientation), TEMPSUMMON_MANUAL_DESPAWN, WEEK))
                {
                    if (data->spellId > 0)
                        personalCreature->CastSpell(personalCreature, data->spellId, true);
                }
            ++data;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        if (IsMythic())
        {
            instance->DoCompleteAchievement(12002);
            //instance->DoAddItemOnPlayers(152789, 1); // loot shackled-urzul
        }

        instance->DoCompleteAchievement(11991);
        instance->DoCompleteAchievement(12266);
        if (IsMythic() || IsHeroic())
            //instance->DoAddItemOnPlayers(152900, 1); // loot blood-of-the-unmaker
        instance->AddTimedDelayedOperation(5000, [this]() -> void
        {
            instance->DoStartMovie(688);
        });
        instance->DoNearTeleportPlayers(pos2);
    }

    void DoAction(int32 action) override
    {
        if (action == 1)
        {
            --_mobsCount;
            if (_mobsCount <= 0)
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                //PhasingHandler::RemovePhase(me, 170);
                me->SetReactState(REACT_AGGRESSIVE);
                me->Attack(me->GetVictim(),true);
                me->GetMotionMaster()->MoveChase(me->GetVictim());
                DoCastAOE(SPELL_CLEARALLDEBUFFS);
                //events.ScheduleEvent(SPELL_THE_DISCS_OF_NORGANNNON, 3s);
                if (IsMythic())
                {
                    events.ScheduleEvent(SPELL_SOULRENDING_SCYTHE, 5s);
                    events.ScheduleEvent(SPELL_SENTENCE_OF_SARGERAS, 35s);
                    events.ScheduleEvent(SPELL_EDGE_OF_ANNIHILATION, 5s);
                }
                events.ScheduleEvent(SPELL_SOULBOMB, 41s);
                events.ScheduleEvent(SPELL_SOULBURST, 41s);
            }
        }
    }

    void SwitchPhase(uint32 phase)
    {
        switch (phase)
        {
        case PHASE_01:
            PhaseStatus = PHASE_01;
            events.Reset();
            events.ScheduleEvent(SPELL_SWEEPING_SCYTHE, 5s, 6s);
            events.ScheduleEvent(SPELL_CONE_OF_DEATH, 30s);
            events.ScheduleEvent(SPELL_SOULBLIGHT_ORB, 35s);
            events.ScheduleEvent(SPELL_TORTURED_RAGE, 12s);
            events.ScheduleEvent(SPELL_SKY_AND_SEA, 10s);
            if (IsMythic())
                events.ScheduleEvent(SPELL_SARGERAS_GAZE, 8s);
            break;
        case PHASE_02:
            PhaseStatus = PHASE_02;
            events.Reset();
            DoCast(SPELL_GOLGANNETHS_WRATH);
            if (Creature* target = me->FindNearestCreature(NPC_GOLGANNETH, 150.0f, true))
                target->AI()->DoAction(2);
            //AREA CLEAR
            AddTimedDelayedOperation(2500, [this]() -> void
            {
                events.ScheduleEvent(SPELL_SWEEPING_SCYTHE, 16s, 17s);
                events.ScheduleEvent(SPELL_SOULBOMB, 30s);
                events.ScheduleEvent(SPELL_SOULBURST, 30s);
                events.ScheduleEvent(SPELL_EDGE_OF_OBLITERATION, 21s);
                events.ScheduleEvent(SPELL_AVTAR_OF_AGGRAMAR, 21s);
                if (IsMythic())
                    events.ScheduleEvent(SPELL_SARGERAS_GAZE, 26s);
            });

            //events.ScheduleEvent(SPELL_TORTURED_RAGE, 15s);
            events.ScheduleEvent(SPELL_VOLATILE_SOUL, 15s);
            events.ScheduleEvent(SPELL_SOULBURST_DETONATION, 15s);
            break;
        case PHASE_03:
            PhaseStatus = PHASE_03;
            events.Reset();
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
            if (Creature* amanthul = me->FindNearestCreature(NPC_AMANTHUL, 150.0f, true))
            {
                amanthul->CastSpell(me, SPELL_TEMPORAL_BLAST, true);
                AddTimedDelayedOperation(5000, [this, amanthul]() -> void
                {
                    me->SetFacingToObject(amanthul);
                });
                DoCast(SPELL_TEMPORAL_BLAST);
            }
            _health = (uint64)(me->GetMaxHealth()* HP_40 / 100);
            me->SetHealth(_health);
            AddTimedDelayedOperation(10000, [this]() -> void
            {
                //summon NPC
                LoadNPC(EVENT_3, spawnData);
                _mobsCount = 7;
                if (Creature* norgannon = me->FindNearestCreature(NPC_NORGANNON, 150.0f, true))
                    norgannon->CastSpell(me, SPELL_THE_DISCS_OF_NORGANNNON, true);
                //PhasingHandler::AddPhase(me, 170);
            });
            break;
        case PHASE_04:
            //phase4
            PhaseStatus = PHASE_04;
            events.Reset();
            instance->SetBossState(DATA_ARGUS_THE_UNMAKER, SPECIAL);
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
            instance->DoNearTeleportPlayers(Position(2887.892f, -4567.8f, 291.965f, 3.09f));
            _health = (uint64)(me->GetMaxHealth()* HP_30 / 100);
            me->SetHealth(_health);
            //DoAction(SPECIAL);
            AddTimedDelayedOperation(12000, [this]() -> void
            {
                if (Creature* life = me->FindNearestCreature(NPC_EONAR, 150.0f, true))
                    life->CastSpell(me, SPELL_GIFT_OF_THE_LIFEBINDER, true);
            });
            //SPELL_REAP_SOUL kill all
            if (Creature* amanthul = me->FindNearestCreature(NPC_AMANTHUL, 150.0f, true))
                me->SetFacingToObject(amanthul);
            DoCast(SPELL_REAP_SOUL);

            AddTimedDelayedOperation(20000, [this]() -> void
            {
                uint64 _health = (uint64)(me->GetMaxHealth()* HP_30 / 100);
                me->SetHealth(_health);
                if (Creature* life = me->FindNearestCreature(NPC_EONAR, 150.0f, true))
                    life->SummonCreature(NPC_GIFT_OF_THE_LIFEBINDER, Position(2893.73f, -4545.36f, 292.028f, 3.77829f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
                //LoadNPC(EVENT_5, spawnData);
                //instance->DoResurrectPlayers(1.0f);
            });

            AddTimedDelayedOperation(22000, [this]() -> void
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->Attack(me->GetVictim(), true);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(me->GetVictim());
                events.ScheduleEvent(SPEEL_DEADLY_SCYTHE, 5s);
                events.ScheduleEvent(SPELL_REORIGINATION_MODULE, 48s);
                events.ScheduleEvent(SPELL_SOULBOMB, 80s);
                events.ScheduleEvent(SPELL_SOULBURST, 40s);
            });
            break;
        default:
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(HP_70, damage))
            if (PhaseStatus == PHASE_01)
                SwitchPhase(PHASE_02);

        if (me->HealthWillBeBelowPctDamaged(HP_40, damage))
            if (PhaseStatus == PHASE_02)
                SwitchPhase(PHASE_03);

        if (me->HealthWillBeBelowPctDamaged(HP_30, damage))
            if(PhaseStatus == PHASE_03)
                SwitchPhase(PHASE_04);
    }

    void ScheduleTasks() override
    {
        if (Creature* life = me->FindNearestCreature(NPC_GIFT_OF_THE_LIFEBINDER, 150.0f, true))
            life->DespawnOrUnsummon();

        SwitchPhase(PHASE_01);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_SWEEPING_SCYTHE:
        {
            DoCast(SPELL_SWEEPING_SCYTHE);
            events.Repeat(5s);
            break;
        }
        case SPELL_TORTURED_RAGE:
        {
            DoCast(SPELL_TORTURED_RAGE);
            events.Repeat(13s, 16s);
            break;
        }
        case SPELL_CONE_OF_DEATH:
        {
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_CONE_OF_DEATH, false);
            events.Repeat(19s, 24s);
            break;
        }
        case SPELL_SOULBLIGHT_ORB:
        {
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                me->CastSpell(target1, SPELL_SOULBLIGHT_ORB, false);
            events.Repeat(22s);
            break;
        }
        case SPELL_SKY_AND_SEA:
        {
            if (Creature* target = me->FindNearestCreature(NPC_GOLGANNETH, 150.0f, true))
                target->AI()->DoAction(1);
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
            {
                me->CastSpell(target1, SPELL_STRENGTH_OF_THE_SEA_MARK, false);
                AddTimedDelayedOperation(4000, [this, target1]() -> void
                {
                    me->CastSpell(target1, SPELL_STRENGTH_OF_THE_SEA_AT, false);
                    target1->CastSpell(target1, SPELL_STRENGTH_OF_THE_SEA, false);
                });
            }

            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
            {
                me->CastSpell(target1, SPELL_STRENGTH_OF_THE_SKY_MARK, false);
                AddTimedDelayedOperation(4000, [this, target1]() -> void
                {
                    me->CastSpell(target1, SPELL_STRENGTH_OF_THE_SKY_AT, false);
                    target1->CastSpell(target1, SPELL_STRENGTH_OF_THE_SKY, false);
                });
            }
            events.Repeat(25s, 28s);
            break;
        }
        case SPELL_SARGERAS_GAZE:
        {
            DoCast(SPELL_SARGERAS_GAZE);
            events.Repeat(35s);
            break;
        }
        case SPELL_SOULBOMB:
        {
            DoCast(SPELL_SOULBOMB);
            events.Repeat(42s);
            break;
        }
        case SPELL_SOULBURST:
        {
            DoCast(SPELL_SOULBURST);//2 Targets
            events.Repeat(42s);
            break;
        }
        case SPELL_EDGE_OF_OBLITERATION:
        {
            DoCast(SPELL_EDGE_OF_OBLITERATION);
            events.Repeat(34s);
            break;
        }
        case SPELL_AVTAR_OF_AGGRAMAR:
        {
            if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                target1->CastSpell(target1, SPELL_AVTAR_OF_AGGRAMAR, true);
            events.Repeat(60s);
            break;
        }

        case SPELL_SOULRENDING_SCYTHE:
        {
            DoCast(SPELL_SOULRENDING_SCYTHE);
            events.Repeat(8s, 9s);
            break;
        }
        case SPELL_SENTENCE_OF_SARGERAS:
        {
            DoCast(SPELL_SENTENCE_OF_SARGERAS);
            events.Repeat(35s);
            break;
        }
        case SPELL_EDGE_OF_ANNIHILATION:
        {
            DoCast(SPELL_EDGE_OF_ANNIHILATION);
            events.Repeat(5s, 6s);
            break;
        }
        case SPEEL_DEADLY_SCYTHE:
        {
            DoCast(SPEEL_DEADLY_SCYTHE);
            events.Repeat(5s, 6s);
            break;
        }
        case SPELL_REORIGINATION_MODULE:
        {
            DoCast(SPELL_REORIGINATION_MODULE);
            LoadNPC(EVENT_4, spawnData);
            events.Repeat(35s);
            break;
        }

        case SPELL_VOLATILE_SOUL:
        {
            DoCast(SPELL_VOLATILE_SOUL);
            events.Repeat(15s);
            break;
        }

        case SPELL_SOULBURST_DETONATION:
        {
            DoCast(SPELL_SOULBURST_DETONATION);
            events.Repeat(15s);
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 50.0f, false) && !IsLock)
        {
            IsLock = true;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        }
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);
        switch (summon->GetEntry())
        {
        case NPC_HUNGERING_SOUL:
        case NPC_CONSTELLAR_DESIGNATE:
        case NPC_REORIGINATION_MODULE:
        {
            summon->SetFaction(me->GetFaction());
            break;
        }
        case NPC_SOULBLIGHT_ORB:
        {
            summon->SetFaction(me->GetFaction());
            summon->CastSpell(summon, SPELL_BLIGHT_ORB, true);
            summon->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
            summon->DespawnOrUnsummon(9000);
            break;
        }
        }
    }
    uint8 PhaseStatus;
    uint8 killCount;
    uint64 _health;
    bool IsLock;
};

struct npc_golganneth_126268 : public ScriptedAI
{
    npc_golganneth_126268(Creature* creature) : ScriptedAI(creature) { }
    Position pos = { 2867.12f, -4567.54f, 292.942f };//center pos
    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            Talk(0);
            me->CastSpell(me, SPELL_SKY_AND_SEA, true);
            break;
        case 2:
            if (Creature* boss = me->FindNearestCreature(NPC_ARGUS_THE_UNMAKER, 150.0f, true))
                me->CastSpell(boss, SPELL_GOLGANNETHS_WRATH, true);
            break;
        }
    }
};

struct npc_constellar_designate_127192 : public ScriptedAI
{
    npc_constellar_designate_127192(Creature* creature) : ScriptedAI(creature) { SetCombatMovement(false); }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* boss = me->FindNearestCreature(NPC_ARGUS_THE_UNMAKER, 150.0f, true))
            boss->AI()->DoAction(1);
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_STARBLAST, 8s);
        //if (!IsMythic())
        events.ScheduleEvent(SPELL_COSMIC_RAY, 30s);
        events.ScheduleEvent(SPELL_COSMIC_BEACON, 40s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_STARBLAST:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_STARBLAST, false);
            events.Repeat(15s);
            break;
        }
        case SPELL_COSMIC_RAY:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_COSMIC_RAY, false);
            events.Repeat(20s);
            break;
        }
        case SPELL_COSMIC_BEACON:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_COSMIC_BEACON, false);
            events.Repeat(20s);
            break;
        }
        }
        DoSpellAttackIfReady(SPELL_STARBLAST);
    }
};

struct npc_gift_of_the_lifebinder_129386 : public ScriptedAI
{
    npc_gift_of_the_lifebinder_129386(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        events.ScheduleEvent(SPELL_STARBLAST, 8s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        switch (events.ExecuteEvent())
        {
        case SPELL_STARBLAST:
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                //instance->DoResurrectPlayers(1.0f);
            events.Repeat(8s);
            break;
        }
        }
    }
};

struct npc_reorigination_module_127809 : public ScriptedAI
{
    npc_reorigination_module_127809(Creature* creature) : ScriptedAI(creature) { SetCombatMovement(false); }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_INITIALIZATION_SEQUENCE, 8s);
        events.ScheduleEvent(SPELL_REORIGINATION_MODULE_DMG, 45s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        switch (events.ExecuteEvent())
        {
        case SPELL_INITIALIZATION_SEQUENCE:
        {
            DoCastSelf(SPELL_INITIALIZATION_SEQUENCE);
            events.Repeat(30s);
            break;
        }
        case SPELL_REORIGINATION_MODULE_DMG:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                me->CastSpell(target, SPELL_REORIGINATION_MODULE_DMG, false);
            events.Repeat(45s);
            break;
        }
        }
    }
};

void AddSC_boss_argus_the_unmaker()
{
    RegisterCreatureAI(boss_argus_the_unmaker);
    RegisterCreatureAI(npc_golganneth_126268);
    RegisterCreatureAI(npc_constellar_designate_127192);
    RegisterCreatureAI(npc_gift_of_the_lifebinder_129386);
    RegisterCreatureAI(npc_reorigination_module_127809);
}
