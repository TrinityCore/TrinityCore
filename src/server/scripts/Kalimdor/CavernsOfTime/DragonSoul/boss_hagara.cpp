/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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
#include "MoveSplineInit.h"
#include "AchievementMgr.h"
#include "ObjectMgr.h"
#include "dragon_soul.h"
#include "SpellMgr.h"
#include "GameObject.h"
#include "SpellAuraEffects.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"

enum ScriptedTexts
{
    SAY_ADDS_1      = 0,
    SAY_ADDS_2      = 1,
    SAY_ADDS_3      = 2,
    SAY_ADDS_4      = 3,
    SAY_AGGRO       = 4,
    SAY_OVERLOAD    = 5,
    SAY_CRYSTAL     = 6,
    SAY_DEATH       = 7,
    SAY_ICE_LANCE   = 8,
    SAY_ICE_WAVE    = 9,
    SAY_ICY_TOMB    = 10,
    SAY_INTRO       = 11,
    SAY_LIGHTNING   = 12,
    SAY_KILL        = 13,
};

enum Spells
{
    SPELL_BERSERK                   = 64238,
    SPELL_ICE_LANCE_DUMMY           = 105269, // visual spear
    SPELL_TARGET                    = 105285,
    SPELL_ICE_LANCE_CONE            = 105287,
    SPELL_ICE_LANCE_AOE             = 105298,
    SPELL_ICE_LANCE_SUMMON          = 105297,
    SPELL_ICE_LANCE_MISSILE         = 105313,
    SPELL_ICE_LANCE_DMG             = 105316,
    SPELL_ICY_TOMB_AOE              = 104448,
    SPELL_ICY_TOMB_DUMMY            = 104449,
    SPELL_ICY_TOMB                  = 104451,
    SPELL_SHATTERED_ICE             = 105289,
    SPELL_FOCUSED_ASSAULT           = 107851,
    SPELL_FROZEN_TEMPEST            = 105256,
    SPELL_ICICLE                    = 109315,
    SPELL_ICICLE_FALL               = 69428,
    SPELL_ICICLE_AURA               = 92201,
    SPELL_ICICLE_DPS                = 92203,
    SPELL_ICE_WAVE                  = 105265,
    SPELL_ICE_WAVE_DPS                = 105314,
    SPELL_CRYSTALLINE_TETHER_1      = 105311,
    SPELL_CRYSTALLINE_OVERLOAD_1    = 105312,
    SPELL_WATERY_ENTRENCHMENT       = 110317,
    SPELL_FROSTFLAKE                = 109325,
    SPELL_FROSTFLAKE_SNARE          = 109337,
    SPELL_FEEDBACK                  = 108934,
    SPELL_WATER_SHIELD              = 105409,
    SPELL_LIGHTNING_STORM           = 105465,
    SPELL_LIGHTNING_STORM_DUMMY     = 105467,
    SPELL_CRYSTALLINE_TETHER_2      = 105482,
    SPELL_LIGHTNING_ROD_1           = 105343, // visual
    SPELL_LIGHTNING_ROD_2           = 109180, // visual
    SPELL_OVERLOAD_1                = 105487,
    SPELL_OVERLOAD_2                = 105481, // by elemental
    SPELL_LIGHTNING_CONDUIT_AOE     = 105377,
    SPELL_LIGHTNING_CONDUIT_DMG     = 105369,
    SPELL_LIGHTNING_CONDUIT_DUMMY_2 = 105371,
    SPELL_LIGHTNING_CONDUIT_DUMMY_1 = 105367,
    SPELL_STORM_PILLARS             = 109557,
    SPELL_STORM_PILLAR              = 109541,

    SPELL_TWILIGHT_PORTAL_VISUAL    = 95716,
    SPELL_HAGARA_LIGHTNING_AXES     = 109670,
    SPELL_HAGARA_FROST_AXES         = 109671,

    // Stormborn Myrmidon
    SPELL_SPARK                     = 109368,
    SPELL_CHAIN_LIGHTNING           = 109348,

    // Stormbinder Adept
    SPELL_TORNADO                   = 109443,
    SPELL_TORNADO_VISUAL            = 109444,
    SPELL_TORNADO_AURA              = 109440,
    SPELL_TORNADO_FIXATE            = 109442,

    // Twilight Frost Envoker
    SPELL_BLIZZARD                  = 109360,
    SPELL_FROST_BOLT                = 109334,
    SPELL_SHACKLES_OF_ICE           = 109423,

    // Lieutenant Shara
    SPELL_SHATTER                   = 109393,
    SPELL_FROST_CORRUPTION          = 109333,
    SPELL_FROZEN_GRASP              = 109305,
    SPELL_FROZEN_GRASP_GRIP         = 109307,
};

enum Adds
{
    NPC_FROZEN_BINDING_CRYSTAL          = 56136,
    NPC_CRYSTAL_CONDUCTOR               = 56165,
    NPC_ICE_LANCE                       = 56108,
    NPC_ICY_TOMB                        = 55695,
    NPC_COLLAPSING_ICICLE               = 57867,
    NPC_ICE_WAVE                        = 56104,
    NPC_BOUND_LIGHTNING_ELEMENTAL       = 56700,
    NPC_HAGARA_FACING_STALKER           = 57929,
    NPC_HAGARA_TRASH_TWILIGHT_PORTAL    = 57809,
    NPC_HOVER_DISK                      = 57924, // {13550, 13613.3f, 133.127f, 0.0f}

    NPC_STORMBORN_MYRMIDON              = 57817,
    NPC_STORMBINDER_ADEPT               = 57823,
    NPC_TORNADO_STALKER                 = 57921,
    NPC_TWILIGHT_FROST_EVOKER           = 57807,
    NPC_CORRUPTED_FRAGMENT              = 57819,
    NPC_LIEUTENANT_SHARA                = 57821,
    NPC_FROST_GRASP_STALKER             = 57860,
};

enum Events
{
    EVENT_CHECK_PLAYERS     = 1,
    EVENT_SUMMON_ADDS_1     = 2,
    EVENT_SUMMON_ADDS_2     = 3,
    EVENT_SUMMON_ADDS_3     = 4,
    EVENT_SUMMON_ADDS_4     = 5,
    EVENT_SUMMON_ADDS_5     = 6,
    EVENT_SUMMON_ADDS_6     = 7,
    EVENT_SUMMON_ADDS_7     = 8,
    EVENT_SUMMON_ADDS_8     = 9,
    EVENT_SHATTERED_ICE     = 10,
    EVENT_FOCUSED_ASSAULT   = 11,
    EVENT_ICY_TOMB          = 12,
    EVENT_ICE_LANCE         = 13,
    EVENT_FROZEN_TEMPEST_1  = 14,
    EVENT_FROZEN_TEMPEST_2,
    EVENT_ICICLE,
    EVENT_ICE_WAVE,
    EVENT_ICE_WAVE_MOVE,
    EVENT_FROSTFLAKE,
    EVENT_ELECTRICAL_STORM_1,
    EVENT_ELECTRICAL_STORM_2,
    EVENT_STORM_PILLARS,
    EVENT_BERSERK,
    EVENT_WATERY_ENTRENCHMENT,
    EVENT_END_SPECIAL_PHASE,


    // Stormborn Myrmidon
    EVENT_SPARK,
    EVENT_CHAIN_LIGHTNING,

    // Stormbinder Adept
    EVENT_TORNADO,

    // Twilight Frost Evoker
    EVENT_BLIZZARD,
    EVENT_FROST_BOLT,
    EVENT_SHACKLES_OF_ICE,

    // Lieutenant Shara
    EVENT_SHATTER,
    EVENT_FROST_CORRUPTION,
    EVENT_FROZEN_GRASP,
};

enum MiscData
{
    ACTION_START_EVENT      = 1,
    ACTION_ICE_WAVE_MOVE    = 2,
    DATA_TRAPPED_PLAYER     = 3,
    DATA_ICE_LANCE_GUID     = 4,
    POINT_ICE_WAVE          = 5,
    POINT_ICE_WAVE_MOVE     = 6,
    DATA_CIRCLE_POINT       = 7,
    DATA_MAIN_WAVE          = 8,
    ACTION_CRYSTAL_DIED     = 9,
    DATA_CRYSTAL_OVERLOADED = 10,
    DATA_PHASE              = 11,
};

const Position centerPos = {13587.4f, 13612.0f, 122.43f, 5.93f};
const Position portalPos[3] =
{
    {13558.625977f, 13582.341797f, 123.49f, 0.90f}, // left
    {13565.067383f, 13611.850586f, 122.42f, 6.17f}, // center
    {13560.788086f, 13641.041016f, 123.49f, 5.59f} // right
};

const Position icelancePos[3] =
{
    {13555.495117f, 13641.369141f, 123.49f, 5.62f},
    {13561.820313f, 13576.739258f, 123.49f, 0.89f},
    {13631.335938f, 13604.969727f, 123.49f, 3.05f}
};

const Position frozencrystalPos[4] =
{
    {13617.5f, 13580.9f, 123.567f, 2.35619f},
    {13557.4f, 13643.1f, 123.567f, 5.48033f},
    {13557.7f, 13580.7f, 123.567f, 0.802851f},
    {13617.3f, 13643.5f, 123.567f, 3.94444f}
};

const Position crystalconductorPos[8] =
{
    {13587.3f, 13658.6f, 123.567f, 4.66003f},
    {13541.8f, 13611.3f, 123.567f, 0.0f},
    {13587.4f, 13566.8f, 123.567f, 1.48353f},
    {13633.0f, 13612.1f, 123.567f, 3.14159f},

    // + 10 heroic only
    {13566.260742f, 13589.701172f, 123.49f, 0.79f},
    {13608.689453f, 13589.539063f, 123.49f, 2.31f},
    {13608.835938f, 13634.269531f, 123.49f, 3.91f},
    {13566.288086f, 13634.226563f, 123.49f, 5.46f}
};

const Position circlePos[18][5] =
{
    // 0
    {
        {13588.195313f, 13560.274414f, 124.480095f, 3.046000f},
        {13588.815430f, 13566.745117f, 123.483849f, 0.0f},
        {13589.292969f, 13571.721680f, 123.483849f, 0.0f},
        {13589.770508f, 13576.699219f, 123.483849f, 0.0f},
        {13590.247070f, 13581.675781f, 123.417847f, 0.0f}
    },
    {
        {13571.882813f, 13563.098633f, 124.480095f, 2.802526f},
        {13574.044922f, 13569.228516f, 123.483849f, 0.0f},
        {13575.708008f, 13573.944336f, 123.483849f, 0.0f},
        {13577.371094f, 13578.659180f, 123.483849f, 0.0f},
        {13579.034180f, 13583.375000f, 123.052773f, 0.0f}
    },
    {
        {13554.680664f, 13572.165039f, 124.480095f, 2.288090f},
        {13559.579102f, 13576.437500f, 123.483849f, 0.0f},
        {13563.346680f, 13579.724609f, 123.483849f, 0.0f},
        {13567.115234f, 13583.011719f, 123.483849f, 0.0f},
        {13570.882813f, 13586.297852f, 123.483849f, 0.0f}
    },
    {
        {13542.881836f, 13585.850586f, 124.480095f, 2.064251f},
        {13548.606445f, 13588.929688f, 123.483849f, 0.0f},
        {13553.009766f, 13591.297852f, 123.483849f, 0.0f},
        {13557.413086f, 13593.666016f, 123.483849f, 0.0f},
        {13561.817383f, 13596.034180f, 123.218773f, 0.0f}
    },
    {
        {13536.680664f, 13603.588867f, 124.480095f, 1.710822f},
        {13543.117188f, 13604.496094f, 123.483849f, 0.0f},
        {13548.068359f, 13605.194336f, 123.483849f, 0.0f},
        {13553.019531f, 13605.891602f, 123.483849f, 0.0f},
        {13557.970703f, 13606.589844f, 123.035400f, 0.0f}
    },
    // 5
    {
        {13536.618164f, 13620.696289f, 124.480095f, 1.472240f},
        {13543.086914f, 13620.056641f, 123.483856f, 0.0f},
        {13548.062500f, 13619.564453f, 123.483856f, 0.0f},
        {13553.038086f, 13619.072266f, 123.483849f, 0.0f},
        {13558.013672f, 13618.581055f, 123.228790f, 0.0f}
    },
    {
        {13542.865234f, 13637.391602f, 124.480095f, 0.953877f},
        {13548.166992f, 13633.630859f, 123.483856f, 0.0f},
        {13552.245117f, 13630.738281f, 123.483849f, 0.0f},
        {13556.323242f, 13627.845703f, 123.483849f, 0.0f},
        {13560.402344f, 13624.953125f, 123.192871f, 0.0f}
    },
    {
        {13553.818359f, 13651.536133f, 124.480095f, 0.569032f},
        {13557.320313f, 13646.060547f, 123.483856f, 0.0f},
        {13560.014648f, 13641.848633f, 123.483849f, 0.0f},
        {13562.708984f, 13637.635742f, 123.483849f, 0.0f},
        {13565.403320f, 13633.423828f, 123.483849f, 0.0f}
    },
    {
        {13570.151367f, 13660.645508f, 124.480095f, 0.282361f},
        {13571.962891f, 13654.403320f, 123.483849f, 0.0f},
        {13573.355469f, 13649.600586f, 123.483849f, 0.0f},
        {13574.749023f, 13644.798828f, 123.483849f, 0.0f},
        {13576.141602f, 13639.997070f, 123.194534f, 0.0f}
    },
    // 9
    {
        {13587.694336f, 13663.437500f, 124.480095f, 6.200338f},
        {13587.156250f, 13656.959961f, 123.483849f, 0.0f},
        {13586.743164f, 13651.976563f, 123.483849f, 0.0f},
        {13586.329102f, 13646.994141f, 123.483849f, 0.0f},
        {13585.915039f, 13642.011719f, 123.132782f, 0.0f}
    },
    {
        {13604.433594f, 13660.982422f, 124.480095f, 5.846913f},
        {13601.686523f, 13655.090820f, 123.483849f, 0.0f},
        {13599.574219f, 13650.559570f, 123.483849f, 0.0f},
        {13597.460938f, 13646.028320f, 123.483849f, 0.0f},
        {13595.348633f, 13641.496094f, 123.442535f, 0.0f}
    },
    {
        {13620.228516f, 13651.585938f, 124.480095f, 5.587738f},
        {13616.063477f, 13646.595703f, 123.483849f, 0.0f},
        {13612.860352f, 13642.756836f, 123.483849f, 0.0f},
        {13609.656250f, 13638.917969f, 123.483849f, 0.0f},
        {13606.453125f, 13635.079102f, 122.912933f, 0.0f}
    },
    {
        {13631.908203f, 13638.895508f, 124.480095f, 5.104725f},
        {13625.902344f, 13636.410156f, 123.483849f, 0.0f},
        {13621.282227f, 13634.498047f, 123.483849f, 0.0f},
        {13616.662109f, 13632.586914f, 123.483849f, 0.0f},
        {13612.041992f, 13630.674805f, 123.483849f, 0.0f},
    },
    {
        {13638.326172f, 13621.443359f, 124.480095f, 4.802349f},
        {13631.852539f, 13620.859375f, 123.483849f, 0.0f},
        {13626.873047f, 13620.410156f, 123.483849f, 0.0f},
        {13621.892578f, 13619.960938f, 123.483849f, 0.0f},
        {13616.913086f, 13619.511719f, 123.314667f, 0.0f},
    },
    // 14
    {
        {13638.371094f, 13604.269531f, 124.480095f, 4.539246f},
        {13631.968750f, 13605.389648f, 123.483856f, 0.0f},
        {13627.042969f, 13606.250977f, 123.483849f, 0.0f},
        {13622.118164f, 13607.112305f, 123.483849f, 0.0f},
        {13617.192383f, 13607.973633f, 123.031342f, 0.0f}
    },
    {
        {13632.013672f, 13586.010742f, 124.480095f, 4.068014f},
        {13626.817383f, 13589.915039f, 123.483856f, 0.0f},
        {13622.819336f, 13592.918945f, 123.483856f, 0.0f},
        {13618.822266f, 13595.921875f, 123.483849f, 0.0f},
        {13614.825195f, 13598.925781f, 123.286789f, 0.0f}
    },
    {
        {13621.313477f, 13572.966797f, 124.480095f, 3.734221f},
        {13617.682617f, 13578.358398f, 123.483849f, 0.0f},
        {13614.890625f, 13582.505859f, 123.483849f, 0.0f},
        {13612.097656f, 13586.653320f, 123.483849f, 0.0f},
        {13609.304688f, 13590.800781f, 123.393356f, 0.0f}
    },
    {
        {13605.115234f, 13563.460938f, 124.480095f, 3.392572f},
        {13603.500977f, 13569.756836f, 123.483849f, 0.0f},
        {13602.258789f, 13574.600586f, 123.483849f, 0.0f},
        {13601.017578f, 13579.444336f, 123.483849f, 0.0f},
        {13599.775391f, 13584.287109f, 123.296410f, 0.0f}
    }
};
class boss_hagara_the_stormbinder: public CreatureScript
{
    public:
        boss_hagara_the_stormbinder() : CreatureScript("boss_hagara_the_stormbinder") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_hagara_the_stormbinderAI(pCreature);
        }

        struct boss_hagara_the_stormbinderAI : public BossAI
        {
            boss_hagara_the_stormbinderAI(Creature* pCreature) : BossAI(pCreature, DATA_HAGARA)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                bEvent = false;
                bEventDone = false;
                specialPhase = false;
                phase = 0;
                summonCount = 0;
                crystalCount = 0;
            }

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(DSScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset() override
            {
                _Reset();

                DespawnCreatures(NPC_ICE_WAVE);

                bEvent = false;
                phase = 0;
                specialPhase = false;
                summonCount = 0;
                crystalCount = 0;

                if (instance->GetData(DATA_HAGARA_EVENT) != DONE)
                {
                    bEventDone = false;
                    me->SetVisible(false);
                    me->SetReactState(REACT_PASSIVE);
                    me->SummonGameObject(GO_THE_FOCUSING_IRIS, centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), 0.0f, QuaternionData(0.0f, 0.0f, 0.0f, 1.0f), WEEK);
                }
                else
                {
                    bEventDone = true;
                    me->SetVisible(true);
                    me->SetReactState(REACT_DEFENSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WATERY_ENTRENCHMENT);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_BERSERK, 8 * MINUTE * IN_MILLISECONDS);
                if (urand(0, 1))
                {
                    events.ScheduleEvent(EVENT_FROZEN_TEMPEST_1, 32000);
                    me->AddAura(SPELL_HAGARA_FROST_AXES, me);
                }
                else
                {
                    events.ScheduleEvent(EVENT_ELECTRICAL_STORM_1, 32000);
                    me->AddAura(SPELL_HAGARA_LIGHTNING_AXES, me);
                }
                events.ScheduleEvent(EVENT_SHATTERED_ICE, urand(10500, 15000));
                events.ScheduleEvent(EVENT_FOCUSED_ASSAULT, 11000);
                events.ScheduleEvent(EVENT_ICE_LANCE, 10000);
                events.ScheduleEvent(EVENT_ICY_TOMB, 20000);

                DoZoneInCombat();
                instance->SetBossState(DATA_HAGARA, IN_PROGRESS);
            }

            void JustSummoned(Creature* summon) override
            {
                if (me->IsInCombat())
                    DoZoneInCombat(summon, 200.0f);

                summons.Summon(summon);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_START_EVENT && !bEvent && !bEventDone)
                {
                    bEvent = true;
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                    events.ScheduleEvent(EVENT_SUMMON_ADDS_1, 3000);
                }
                else if (action == ACTION_CRYSTAL_DIED && crystalCount > 0)
                {
                    crystalCount--;
                    if (crystalCount == 0)
                        SpecialPhaseEnd();
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PHASE)
                    return (uint32)phase;
                return 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);

                if (instance)
                {
                    instance->DoModifyPlayerCurrencies(395, 7500);
                    if (!IsHeroic())
                    {
                        instance->DoModifyPlayerCurrencies(614, 1);
                        instance->DoModifyPlayerCurrencies(615, 1);
                    }
                    else
                    {
                        instance->DoModifyPlayerCurrencies(614, 2);
                        instance->DoModifyPlayerCurrencies(615, 2);
                    }
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WATERY_ENTRENCHMENT);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ICY_TOMB);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FROSTFLAKE);
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
            {
                if (!bEvent)
                    return;

                switch (phase)
                {
                    case 1:
                        if (summonCount <= 1)
                        {
                            summonCount = 0;
                            summons.DespawnEntry(NPC_HAGARA_TRASH_TWILIGHT_PORTAL);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_4, 3000);
                        }
                        else
                            summonCount--;
                        break;
                    case 2:
                        if (summonCount <= 1)
                        {
                            summonCount = 0;
                            summons.DespawnEntry(NPC_HAGARA_TRASH_TWILIGHT_PORTAL);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_5, 3000);
                        }
                        else
                            summonCount--;
                        break;
                    case 3:
                        if (summonCount <= 1)
                        {
                            summonCount = 0;
                            summons.DespawnEntry(NPC_HAGARA_TRASH_TWILIGHT_PORTAL);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_6, 3000);
                        }
                        else
                            summonCount--;
                        break;
                    case 4:
                        if (summonCount <= 1)
                        {
                            summonCount = 0;
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_7, 3000);
                        }
                        else
                            summonCount--;
                        break;
                    case 5:
                        if (summonCount <= 1)
                        {
                            Talk(SAY_INTRO);
                            summonCount = 0;
                            summons.DespawnEntry(NPC_HAGARA_TRASH_TWILIGHT_PORTAL);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_8, 3000);
                        }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() && !bEvent)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) && !specialPhase)
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                        case EVENT_CHECK_PLAYERS:
                            if (!me->SelectNearestPlayer(60.0f))
                            {
                                events.Reset();
                                Reset();
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                            break;
                        case EVENT_SUMMON_ADDS_1:
                            Talk(SAY_ADDS_1);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_2, 7000);
                            break;
                        case EVENT_SUMMON_ADDS_2:
                            me->SummonCreature(NPC_HAGARA_TRASH_TWILIGHT_PORTAL, portalPos[1]);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS_3, 3000);
                            break;
                        case EVENT_SUMMON_ADDS_3:
                            phase = 1;
                            summonCount = 4;
                            me->SummonCreature(NPC_TWILIGHT_FROST_EVOKER, portalPos[1].GetPositionX(), portalPos[1].GetPositionY() + 4.0f, portalPos[1].GetPositionZ() + 1.0f, portalPos[1].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_STORMBORN_MYRMIDON, portalPos[1].GetPositionX(), portalPos[1].GetPositionY() + 2.0f, portalPos[1].GetPositionZ() + 1.0f, portalPos[1].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_STORMBORN_MYRMIDON, portalPos[1].GetPositionX(), portalPos[1].GetPositionY() - 2.0f, portalPos[1].GetPositionZ() + 1.0f, portalPos[1].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_TWILIGHT_FROST_EVOKER, portalPos[1].GetPositionX(), portalPos[1].GetPositionY() - 4.0f, portalPos[1].GetPositionZ() + 1.0f, portalPos[1].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            break;
                        case EVENT_SUMMON_ADDS_4:
                            Talk(SAY_ADDS_2);
                            phase = 2;
                            summonCount = 12;
                            me->SummonCreature(NPC_HAGARA_TRASH_TWILIGHT_PORTAL, portalPos[0]);
                            me->SummonCreature(NPC_STORMBINDER_ADEPT, portalPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            for (uint8 i = 0; i < 5; ++i)
                                me->SummonCreature(NPC_CORRUPTED_FRAGMENT, portalPos[0].GetPositionX()+ frand(-2.0f, 2.0f), portalPos[0].GetPositionY() + frand(-2.0f, 2.0f), portalPos[0].GetPositionZ() + 1.0f, portalPos[0].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

                            me->SummonCreature(NPC_HAGARA_TRASH_TWILIGHT_PORTAL, portalPos[2]);
                            me->SummonCreature(NPC_STORMBINDER_ADEPT, portalPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            for (uint8 i = 0; i < 5; ++i)
                                me->SummonCreature(NPC_CORRUPTED_FRAGMENT, portalPos[2].GetPositionX()+ frand(-2.0f, 2.0f), portalPos[2].GetPositionY() + frand(-2.0f, 2.0f), portalPos[2].GetPositionZ() + 1.0f, portalPos[2].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            break;
                        case EVENT_SUMMON_ADDS_5:
                            Talk(SAY_ADDS_3);
                            phase = 3;
                            summonCount = 6;
                            me->SummonCreature(NPC_HAGARA_TRASH_TWILIGHT_PORTAL, portalPos[0]);
                            me->SummonCreature(NPC_STORMBINDER_ADEPT, portalPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_TWILIGHT_FROST_EVOKER, portalPos[0].GetPositionX(), portalPos[0].GetPositionY() + 4.0f, portalPos[0].GetPositionZ() + 1.0f, portalPos[0].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_STORMBORN_MYRMIDON, portalPos[0].GetPositionX(), portalPos[0].GetPositionY() + 2.0f, portalPos[0].GetPositionZ() + 1.0f, portalPos[0].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

                            me->SummonCreature(NPC_HAGARA_TRASH_TWILIGHT_PORTAL, portalPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_STORMBINDER_ADEPT, portalPos[2]);
                            me->SummonCreature(NPC_TWILIGHT_FROST_EVOKER, portalPos[2].GetPositionX(), portalPos[2].GetPositionY() - 4.0f, portalPos[2].GetPositionZ() + 1.0f, portalPos[2].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            me->SummonCreature(NPC_STORMBORN_MYRMIDON, portalPos[2].GetPositionX(), portalPos[2].GetPositionY() - 2.0f, portalPos[2].GetPositionZ() + 1.0f, portalPos[2].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            break;
                        case EVENT_SUMMON_ADDS_6:
                            phase = 4;
                            summonCount = 10;
                            me->SummonCreature(NPC_HAGARA_TRASH_TWILIGHT_PORTAL, portalPos[1]);
                            for (uint8 i = 0; i < 10; ++i)
                                me->SummonCreature(NPC_CORRUPTED_FRAGMENT, portalPos[1].GetPositionX()+ frand(-2.0f, 2.0f), portalPos[1].GetPositionY() + frand(-2.0f, 2.0f), portalPos[1].GetPositionZ() + 1.0f, portalPos[1].GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            break;
                        case EVENT_SUMMON_ADDS_7:
                            Talk(SAY_ADDS_4);
                            phase = 5;
                            summonCount = 1;
                            me->SummonCreature(NPC_LIEUTENANT_SHARA, portalPos[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            break;
                        case EVENT_SUMMON_ADDS_8:
                            phase = 0;
                            bEvent = false;
                            bEventDone = true;
                            instance->SetData(DATA_HAGARA_EVENT, DONE);
                            events.CancelEvent(EVENT_CHECK_PLAYERS);
                            me->SetVisible(true);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                                AttackStart(target);
                            break;
                        case EVENT_SHATTERED_ICE:
                        {
                            Unit* pTarget = NULL;
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true);
                            if (!pTarget)
                                pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                            if (pTarget)
                                DoCast(pTarget, SPELL_SHATTERED_ICE);

                            events.ScheduleEvent(EVENT_SHATTERED_ICE, 10500);
                            break;
                        }
                        case EVENT_FOCUSED_ASSAULT:
                            me->StopMoving();
                            me->SetReactState(REACT_PASSIVE);
                            DoCastVictim(SPELL_FOCUSED_ASSAULT);
                            me->SetReactState(REACT_AGGRESSIVE);
                            events.ScheduleEvent(EVENT_FOCUSED_ASSAULT, 15000);
                            break;
                        case EVENT_ICY_TOMB:
                            Talk(SAY_ICY_TOMB);
                            me->CastCustomSpell(SPELL_ICY_TOMB_AOE, SPELLVALUE_MAX_TARGETS, RAID_MODE(2, 5, 2, 6));
                            break;
                        case EVENT_ICE_LANCE:
                        {
                            UnitList targets;
                            SelectTargetList(targets, 3, SELECT_TARGET_NEAREST, 0.0f, true);
                            if (targets.empty())
                                break;

                            Talk(SAY_ICE_LANCE);

                            uint8 i = 0;
                            for (UnitList::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                            {
                                if (Creature* pLance = me->SummonCreature(NPC_ICE_LANCE, icelancePos[i], TEMPSUMMON_TIMED_DESPAWN, 15000))
                                    pLance->AI()->SetGUID((*itr)->GetGUID(), DATA_ICE_LANCE_GUID);
                                i++;
                            }
                            break;
                        }
                        case EVENT_FROZEN_TEMPEST_1:
                            events.CancelEvent(EVENT_SHATTERED_ICE);
                            events.CancelEvent(EVENT_ICY_TOMB);
                            events.CancelEvent(EVENT_ICE_LANCE);
                            events.CancelEvent(EVENT_FOCUSED_ASSAULT);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->NearTeleportTo(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), centerPos.GetOrientation());
                            events.ScheduleEvent(EVENT_FROZEN_TEMPEST_2, 1500);
                            break;
                        case EVENT_FROZEN_TEMPEST_2:
                            specialPhase = true;
                            crystalCount = 4;
                            phase = 11;
                            for (uint8 i = 0; i < 4; ++i)
                                if (Creature* pCrystal = me->SummonCreature(NPC_FROZEN_BINDING_CRYSTAL, frozencrystalPos[i]))
                                    pCrystal->CastSpell(me, SPELL_CRYSTALLINE_TETHER_1);
                            DoCast(me, SPELL_FROZEN_TEMPEST);
                            events.ScheduleEvent(EVENT_ICE_WAVE, 6000);
                            events.ScheduleEvent(EVENT_ICICLE, 2000);
                            events.ScheduleEvent(EVENT_WATERY_ENTRENCHMENT, 7000);
                            events.ScheduleEvent(EVENT_END_SPECIAL_PHASE, 305000);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_FROSTFLAKE, urand(2000, 5000));
                            break;
                        case EVENT_WATERY_ENTRENCHMENT:
                        {
                            Map::PlayerList const& plrList = instance->instance->GetPlayers();
                            if (!plrList.isEmpty())
                            {
                                for (Map::PlayerList::const_iterator itr = plrList.begin(); itr != plrList.end(); ++itr)
                                    if (Player* pPlayer = itr->GetSource())
                                    {
                                        if (me->GetDistance(pPlayer) <= 23)
                                        {
                                            if (!pPlayer->HasAura(SPELL_WATERY_ENTRENCHMENT))
                                                pPlayer->CastSpell(pPlayer, SPELL_WATERY_ENTRENCHMENT, true);
                                        }
                                        else
                                            pPlayer->RemoveAurasDueToSpell(SPELL_WATERY_ENTRENCHMENT);
                                    }
                            }
                            events.ScheduleEvent(EVENT_WATERY_ENTRENCHMENT, 1000);
                            break;
                        }
                        case EVENT_ICE_WAVE:
                        {
                            Talk(SAY_ICE_WAVE);

                            if (Creature* pWave = me->SummonCreature(NPC_ICE_WAVE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                            {
                                pWave->AI()->SetData(DATA_CIRCLE_POINT, 0);
                                pWave->AI()->SetData(DATA_MAIN_WAVE, 1);
                                pWave->GetMotionMaster()->MovePoint(POINT_ICE_WAVE, circlePos[0][0]);
                            }
                            if (Creature* pWave = me->SummonCreature(NPC_ICE_WAVE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                            {
                                pWave->AI()->SetData(DATA_CIRCLE_POINT, 5);
                                pWave->AI()->SetData(DATA_MAIN_WAVE, 1);
                                pWave->GetMotionMaster()->MovePoint(POINT_ICE_WAVE, circlePos[5][0]);
                            }
                            if (Creature* pWave = me->SummonCreature(NPC_ICE_WAVE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                            {
                                pWave->AI()->SetData(DATA_CIRCLE_POINT, 9);
                                pWave->AI()->SetData(DATA_MAIN_WAVE, 1);
                                pWave->GetMotionMaster()->MovePoint(POINT_ICE_WAVE, circlePos[9][0]);
                            }
                            if (Creature* pWave = me->SummonCreature(NPC_ICE_WAVE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                            {
                                pWave->AI()->SetData(DATA_CIRCLE_POINT, 14);
                                pWave->AI()->SetData(DATA_MAIN_WAVE, 1);
                                pWave->GetMotionMaster()->MovePoint(POINT_ICE_WAVE, circlePos[14][0]);
                            }

                            events.ScheduleEvent(EVENT_ICE_WAVE_MOVE, 12000);
                            break;
                        }
                        case EVENT_ICE_WAVE_MOVE:
                        {
                            Talk(SAY_ICE_WAVE);
                            EntryCheckPredicate pred(NPC_ICE_WAVE);
                            summons.DoAction(ACTION_ICE_WAVE_MOVE, pred);
                            break;
                        }
                        case EVENT_ICICLE:
                        {
                            UnitList targets;
                            SelectTargetList(targets, RAID_MODE(3, 7), SELECT_TARGET_RANDOM, 0.0f, true);
                            if (!targets.empty())
                                for (UnitList::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                    DoCast((*itr), SPELL_ICICLE, true);
                            events.ScheduleEvent(EVENT_ICICLE, urand(8000, 9000));
                            break;
                        }
                        case EVENT_FROSTFLAKE:
                            DoCastAOE(SPELL_FROSTFLAKE, true);
                            events.ScheduleEvent(EVENT_FROSTFLAKE, urand(9000, 12000));
                            break;
                        case EVENT_ELECTRICAL_STORM_1:
                            events.CancelEvent(EVENT_SHATTERED_ICE);
                            events.CancelEvent(EVENT_ICY_TOMB);
                            events.CancelEvent(EVENT_ICE_LANCE);
                            events.CancelEvent(EVENT_FOCUSED_ASSAULT);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->NearTeleportTo(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), centerPos.GetOrientation());
                            events.ScheduleEvent(EVENT_ELECTRICAL_STORM_2, 1500);
                            break;
                        case EVENT_ELECTRICAL_STORM_2:
                            specialPhase = true;
                            crystalCount = 4;
                            phase = 10;
                            Talk(SAY_LIGHTNING);
                            switch (GetDifficulty())
                            {
                                case DIFFICULTY_10_N:
                                    for (uint8 i = 0; i < 4; ++i)
                                        if (Creature* pCronductor = me->SummonCreature(NPC_CRYSTAL_CONDUCTOR, crystalconductorPos[i + 4]))
                                            pCronductor->CastSpell(me, SPELL_CRYSTALLINE_TETHER_2);
                                    break;
                                case DIFFICULTY_10_HC:
                                    crystalCount += 4;
                                    for (uint8 i = 0; i < 4; ++i)
                                        if (Creature* pCronductor = me->SummonCreature(NPC_CRYSTAL_CONDUCTOR, crystalconductorPos[i + 4]))
                                            pCronductor->CastSpell(me, SPELL_CRYSTALLINE_TETHER_2);
                                // no break
                                case DIFFICULTY_25_N:
                                case DIFFICULTY_25_HC:
                                    for (uint8 i = 0; i < 4; ++i)
                                        if (Creature* pCronductor = me->SummonCreature(NPC_CRYSTAL_CONDUCTOR, crystalconductorPos[i]))
                                            pCronductor->CastSpell(me, SPELL_CRYSTALLINE_TETHER_2);
                                    break;
                                default:
                                    break;
                            }

                            me->SummonCreature(NPC_BOUND_LIGHTNING_ELEMENTAL, circlePos[0][3]);

                            DoCast(me, SPELL_WATER_SHIELD);

                            events.ScheduleEvent(EVENT_END_SPECIAL_PHASE, 305000);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_STORM_PILLARS, 5000);
                            break;
                        case EVENT_STORM_PILLARS:
                            DoCastAOE(SPELL_STORM_PILLARS, true);
                            events.ScheduleEvent(EVENT_STORM_PILLARS, urand(5000, 10000));
                            break;
                        case EVENT_END_SPECIAL_PHASE:
                            crystalCount = 0;
                            summons.DespawnEntry(NPC_CRYSTAL_CONDUCTOR);
                            summons.DespawnEntry(NPC_BOUND_LIGHTNING_ELEMENTAL);
                            summons.DespawnEntry(NPC_FROZEN_BINDING_CRYSTAL);
                            SpecialPhaseEnd();
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool bEvent;
            bool bEventDone;
            bool specialPhase;
            uint8 phase;
            uint8 summonCount;
            uint8 crystalCount;

            void SpecialPhaseEnd()
            {
                specialPhase = false;
                events.CancelEvent(EVENT_ICICLE);
                events.CancelEvent(EVENT_WATERY_ENTRENCHMENT);
                events.CancelEvent(EVENT_STORM_PILLARS);
                events.CancelEvent(EVENT_FROSTFLAKE);
                events.CancelEvent(EVENT_END_SPECIAL_PHASE);

                me->RemoveAura(SPELL_WATER_SHIELD);
                me->RemoveAura(SPELL_FROZEN_TEMPEST);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WATERY_ENTRENCHMENT);

                DespawnCreatures(NPC_ICE_WAVE);
                summons.DespawnEntry(NPC_CRYSTAL_CONDUCTOR);
                summons.DespawnEntry(NPC_BOUND_LIGHTNING_ELEMENTAL);
                summons.DespawnEntry(NPC_FROZEN_BINDING_CRYSTAL);

                me->SetReactState(REACT_AGGRESSIVE);
                AttackStart(me->GetVictim());

                DoCast(me, SPELL_FEEDBACK, true);

                events.ScheduleEvent(EVENT_ICE_LANCE, 12000);
                events.ScheduleEvent(EVENT_ICY_TOMB, 20000);
                events.ScheduleEvent(EVENT_FOCUSED_ASSAULT, 15000);
                events.ScheduleEvent(EVENT_SHATTERED_ICE, urand(20000, 30500));

                if (phase == 10)
                {
                    events.ScheduleEvent(EVENT_FROZEN_TEMPEST_1, 62000);
                    me->RemoveAura(SPELL_HAGARA_LIGHTNING_AXES);
                    DoCast(me, SPELL_HAGARA_FROST_AXES, true);
                }
                else if (phase == 11)
                {
                    events.ScheduleEvent(EVENT_ELECTRICAL_STORM_1, 62000);
                    me->RemoveAura(SPELL_HAGARA_FROST_AXES);
                    DoCast(me, SPELL_HAGARA_LIGHTNING_AXES, true);
                }
                phase = 0;
            }

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon();
            }
        };
};

class npc_hagara_the_stormbinder_stormborn_myrmidon : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_stormborn_myrmidon() : CreatureScript("npc_hagara_the_stormbinder_stormborn_myrmidon") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_hagara_the_stormbinder_stormborn_myrmidonAI (pCreature);
        }

        struct npc_hagara_the_stormbinder_stormborn_myrmidonAI : public ScriptedAI
        {
            npc_hagara_the_stormbinder_stormborn_myrmidonAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SPARK, urand(3000, 10000));
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(2000, 10000));
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    AttackStart(target);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPARK:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                if (Aura* aur = pTarget->GetAura(SPELL_SPARK))
                                    aur->ModStackAmount(1);
                                else
                                    DoCast(pTarget, SPELL_SPARK);
                            }
                            events.ScheduleEvent(EVENT_SPARK, urand(7000, 9000));
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(5000, 7000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class npc_hagara_the_stormbinder_stormbinder_adept : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_stormbinder_adept() : CreatureScript("npc_hagara_the_stormbinder_stormbinder_adept") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_hagara_the_stormbinder_stormbinder_adeptAI (pCreature);
        }

        struct npc_hagara_the_stormbinder_stormbinder_adeptAI : public ScriptedAI
        {
            npc_hagara_the_stormbinder_stormbinder_adeptAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_TORNADO, urand(5000, 15000));
            }

            void JustSummoned(Creature* summon) override
            {
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
                summons.Summon(summon);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    AttackStart(target);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void JustDied(Unit* /*killer*/) override
            {
                summons.DespawnAll();
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_TORNADO:
                        DoCast(SPELL_TORNADO);
                        events.ScheduleEvent(EVENT_TORNADO, urand(15000, 20000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

        private:
             EventMap events;
             SummonList summons;
        };
};

class npc_hagara_the_stormbinder_tornado_stalker : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_tornado_stalker() : CreatureScript("npc_hagara_the_stormbinder_tornado_stalker") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_hagara_the_stormbinder_tornado_stalkerAI (pCreature);
        }

        struct npc_hagara_the_stormbinder_tornado_stalkerAI : public Scripted_NoMovementAI
        {
            npc_hagara_the_stormbinder_tornado_stalkerAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                me->AddAura(SPELL_TORNADO_VISUAL, me);
                me->AddAura(SPELL_TORNADO_AURA, me);
                events.ScheduleEvent(EVENT_TORNADO, 3000);
            }

            void UpdateAI(uint32 const diff) override
            {
                events.Update(diff);

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_TORNADO:
                        me->StopMoving();
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            DoCast(pTarget, SPELL_TORNADO_FIXATE, true);
                            me->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
                        }
                        break;
                    default:
                        break;
                }
            }

        private:
            EventMap events;
        };
};

class npc_hagara_the_stormbinder_twilight_frost_evoker : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_twilight_frost_evoker() : CreatureScript("npc_hagara_the_stormbinder_twilight_frost_evoker") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_hagara_the_stormbinder_twilight_frost_evokerAI (pCreature);
        }

        struct npc_hagara_the_stormbinder_twilight_frost_evokerAI : public ScriptedAI
        {
            npc_hagara_the_stormbinder_twilight_frost_evokerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_FROST_BOLT, 1);
                events.ScheduleEvent(EVENT_BLIZZARD, urand(5000, 15000));
                events.ScheduleEvent(EVENT_SHACKLES_OF_ICE, urand(5000, 15000));
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    AttackStart(target);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FROST_BOLT:
                            DoCastVictim(SPELL_FROST_BOLT);
                            events.ScheduleEvent(EVENT_FROST_BOLT, 1600);
                            break;
                        case EVENT_BLIZZARD:
                        {
                            Unit* pTarget = NULL;
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true);
                            if (!pTarget)
                                return;

                                DoCast(pTarget, SPELL_BLIZZARD);

                            events.ScheduleEvent(EVENT_BLIZZARD, urand(16000, 20000));
                            break;
                        }
                        case EVENT_SHACKLES_OF_ICE:
                        {
                            Unit* pTarget = NULL;
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true);
                            if (!pTarget)
                                return;

                                DoCast(pTarget, SPELL_SHACKLES_OF_ICE);

                            events.ScheduleEvent(EVENT_SHACKLES_OF_ICE, urand(8000, 14000));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class npc_hagara_the_stormbinder_lieutenant_shara : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_lieutenant_shara() : CreatureScript("npc_hagara_the_stormbinder_lieutenant_shara") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_hagara_the_stormbinder_lieutenant_sharaAI (pCreature);
        }

        struct npc_hagara_the_stormbinder_lieutenant_sharaAI : public ScriptedAI
        {
            npc_hagara_the_stormbinder_lieutenant_sharaAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SHATTER, urand(4000, 6000));
                events.ScheduleEvent(EVENT_FROST_CORRUPTION, urand(3000, 10000));
                events.ScheduleEvent(EVENT_FROZEN_GRASP, urand(5000, 10000));
            }

            void JustSummoned(Creature* summon) override
            {
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    AttackStart(target);
            }

            void JustDied(Unit* /*killer*/) override
            {
                summons.DespawnAll();
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHATTER:
                            DoCastVictim(SPELL_SHATTER);
                            events.ScheduleEvent(EVENT_SHATTER, urand(8000, 13000));
                            break;
                        case EVENT_FROST_CORRUPTION:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_FROST_CORRUPTION);
                            events.ScheduleEvent(EVENT_FROST_CORRUPTION, urand(10000, 15000));
                            break;
                        case EVENT_FROZEN_GRASP:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_FROZEN_GRASP);
                            events.ScheduleEvent(EVENT_FROZEN_GRASP, 31000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
            SummonList summons;
        };
};

class npc_hagara_the_stormbinder_icy_tomb : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_icy_tomb() : CreatureScript("npc_hagara_the_stormbinder_icy_tomb") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hagara_the_stormbinder_icy_tombAI(creature);
        }

        struct npc_hagara_the_stormbinder_icy_tombAI : public Scripted_NoMovementAI
        {
            npc_hagara_the_stormbinder_icy_tombAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                existenceCheckTimer = 1000;
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_TRAPPED_PLAYER)
                {
                    trappedPlayer = guid;
                    existenceCheckTimer = 1000;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, trappedPlayer))
                {
                    trappedPlayer = ObjectGuid::Empty;
                    player->RemoveAura(SPELL_ICY_TOMB);
                }
                me->DespawnOrUnsummon(800);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!trappedPlayer)
                    return;

                if (existenceCheckTimer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, trappedPlayer);
                    if (!player || player->isDead() || !player->HasAura(SPELL_ICY_TOMB))
                    {
                        JustDied(me);
                        me->DespawnOrUnsummon();
                        return;
                    }
                }
                else
                    existenceCheckTimer -= diff;
            }

        private:
            ObjectGuid trappedPlayer;
            uint32 existenceCheckTimer;
        };
};

class npc_hagara_the_stormbinder_ice_lance : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_ice_lance() : CreatureScript("npc_hagara_the_stormbinder_ice_lance") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hagara_the_stormbinder_ice_lanceAI(creature);
        }

        struct npc_hagara_the_stormbinder_ice_lanceAI : public Scripted_NoMovementAI
        {
            npc_hagara_the_stormbinder_ice_lanceAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void Reset() override
            {
                me->AddAura(SPELL_ICE_LANCE_DUMMY, me);
                me->SetReactState(REACT_PASSIVE);
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_ICE_LANCE_GUID)
                {
                    targetPlayer = guid;
                    if (Player* pPlayer = ObjectAccessor::FindPlayer(guid))
                        DoCast(pPlayer, SPELL_TARGET);
                    else
                        me->DespawnOrUnsummon();
                }
            }

            ObjectGuid GetGUID(int32 type) const override
            {
                if (type == DATA_ICE_LANCE_GUID)
                    return targetPlayer;
                return ObjectGuid::Empty;
            }

        private:
            ObjectGuid targetPlayer;
        };
};

class npc_hagara_the_stormbinder_collapsing_icicle : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_collapsing_icicle() : CreatureScript("npc_hagara_the_stormbinder_collapsing_icicle") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hagara_the_stormbinder_collapsing_icicleAI(creature);
        }

        struct npc_hagara_the_stormbinder_collapsing_icicleAI : public ScriptedAI
        {
            npc_hagara_the_stormbinder_collapsing_icicleAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_ICICLE, 6000);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_ICICLE:
                        DoCast(me, SPELL_ICICLE_AURA);
                        DoCast(me, SPELL_ICICLE_FALL);
                        break;
                    default:
                        break;
                }
            }

        private:
            EventMap events;
        };
};

class npc_hagara_the_stormbinder_ice_wave : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_ice_wave() : CreatureScript("npc_hagara_the_stormbinder_ice_wave") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hagara_the_stormbinder_ice_waveAI(creature);
        }

        struct npc_hagara_the_stormbinder_ice_waveAI : public Scripted_NoMovementAI
        {
            npc_hagara_the_stormbinder_ice_waveAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                circlePoint = 0;
                bDespawn = false;
                pInstance = me->GetInstanceScript();
                bMain = false;
            }

            void MovementInform(uint32 type, uint32 data) override
            {
                if (bDespawn)
                    return;

                if (type == POINT_MOTION_TYPE)
                {
                    if (data == POINT_ICE_WAVE)
                    {
                        //
                    }
                    else if (data == POINT_ICE_WAVE_MOVE)
                    {
                        if (bMain)
                        {
                            UpdateNextPoint();
                            for (uint8 i = 0; i < 4; ++i)
                            {

                                if (Creature* pWave = me->SummonCreature(NPC_ICE_WAVE, circlePos[circlePoint][i]))
                                {
                                    pWave->SetSpeed(MOVE_RUN, (0.8f - 0.1f * i));
                                    pWave->AI()->SetData(DATA_CIRCLE_POINT, circlePoint);
                                    pWave->AI()->SetData(DATA_MAIN_WAVE, ((i == 0) ? 1 : 0));
                                    pWave->GetMotionMaster()->MovePoint(POINT_ICE_WAVE_MOVE, circlePos[(circlePoint < 17 ? circlePoint + 1 : 0)][i]);
                                }
                            }
                        }
                        me->DespawnOrUnsummon(500);
                    }
                }
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                me->AddAura(SPELL_ICE_WAVE, me);
            }

            void JustSummoned(Creature* summon) override
            {
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_CIRCLE_POINT)
                    circlePoint = (uint8)data;
                else if (type == DATA_MAIN_WAVE)
                    bMain = (bool)data;
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_ICE_WAVE_MOVE)
                {
                    me->GetMotionMaster()->MovePoint(POINT_ICE_WAVE_MOVE, circlePos[UpdateNextPoint()][0]);
                }
            }

            void UpdateAI(const uint32 /*diff*/) override
            {
                if (bDespawn)
                    return;

                if (pInstance->GetBossState(DATA_HAGARA) != IN_PROGRESS)
                {
                    bDespawn = true;
                    me->DespawnOrUnsummon(100);
                }
            }

        private:
            bool bDespawn;
            InstanceScript* pInstance;
            uint8 circlePoint;
            bool bMain;

            uint8 UpdateNextPoint()
            {
                circlePoint++;
                if (circlePoint > 17)
                    circlePoint = 0;
                return circlePoint;
            }
        };
};

class npc_hagara_the_stormbinder_frozen_binding_crystal : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_frozen_binding_crystal() : CreatureScript("npc_hagara_the_stormbinder_frozen_binding_crystal") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hagara_the_stormbinder_frozen_binding_crystalAI(creature);
        }

        struct npc_hagara_the_stormbinder_frozen_binding_crystalAI : public Scripted_NoMovementAI
        {
            npc_hagara_the_stormbinder_frozen_binding_crystalAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->SetReactState(REACT_PASSIVE);
                pInstance = me->GetInstanceScript();
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCast(me, SPELL_CRYSTALLINE_OVERLOAD_1);

                if (pInstance)
                    if (Creature* pHagara = pInstance->GetCreature(DATA_HAGARA))
                    {
                        pHagara->RemoveAura(SPELL_CRYSTALLINE_TETHER_1, me->GetGUID());
                        pHagara->AI()->DoAction(ACTION_CRYSTAL_DIED);
                    }

                me->DespawnOrUnsummon(2000);
            }

        private:
            InstanceScript* pInstance;
        };
};

class npc_hagara_the_stormbinder_crystal_conductor : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_crystal_conductor() : CreatureScript("npc_hagara_the_stormbinder_crystal_conductor") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hagara_the_stormbinder_crystal_conductorAI(creature);
        }

        struct npc_hagara_the_stormbinder_crystal_conductorAI : public Scripted_NoMovementAI
        {
            npc_hagara_the_stormbinder_crystal_conductorAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->SetReactState(REACT_PASSIVE);
                pInstance = me->GetInstanceScript();
                bOverloaded = false;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if ((spellInfo->Id == SPELL_OVERLOAD_2 || spellInfo->Id == SPELL_LIGHTNING_CONDUIT_DUMMY_1) && !bOverloaded)
                {
                    bOverloaded = true;

                    DoCast(me, SPELL_LIGHTNING_ROD_2, true);

                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 2000);

                    if (pInstance)
                        if (Creature* pHagara = pInstance->GetCreature(DATA_HAGARA))
                        {
                            pHagara->RemoveAura(SPELL_CRYSTALLINE_TETHER_2, me->GetGUID());
                            pHagara->AI()->DoAction(ACTION_CRYSTAL_DIED);
                        }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_CRYSTAL_OVERLOADED)
                    return (uint32)bOverloaded;
                return 0;
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_CHECK_PLAYERS:
                        if (Player* pPlayer = me->SelectNearestPlayer(10.0f))
                            DoCast(pPlayer, SPELL_LIGHTNING_CONDUIT_DUMMY_1, true);

                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                        break;
                    default:
                        break;
                }
            }

        private:
            InstanceScript* pInstance;
            bool bOverloaded;
            EventMap events;

        };
};

class npc_hagara_the_stormbinder_bound_lightning_elemental : public CreatureScript
{
    public:
        npc_hagara_the_stormbinder_bound_lightning_elemental() : CreatureScript("npc_hagara_the_stormbinder_bound_lightning_elemental") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_hagara_the_stormbinder_bound_lightning_elementalAI (pCreature);
        }

        struct npc_hagara_the_stormbinder_bound_lightning_elementalAI : public ScriptedAI
        {
            npc_hagara_the_stormbinder_bound_lightning_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 2000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* pCreature = me->FindNearestCreature(NPC_CRYSTAL_CONDUCTOR, 100.0f))
                    DoCast(pCreature, SPELL_OVERLOAD_2, true);
                me->DespawnOrUnsummon(3000);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                switch (uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_CHECK_PLAYERS:
                        me->SetReactState(REACT_AGGRESSIVE);
                        AttackStart(me->GetVictim());
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class npc_hagara_the_stormbinder_corrupted_fragment : public CreatureScript
{
public:
    npc_hagara_the_stormbinder_corrupted_fragment() : CreatureScript("npc_hagara_the_stormbinder_corrupted_fragment") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_hagara_the_stormbinder_corrupted_fragmentAI(pCreature);
    }

    struct npc_hagara_the_stormbinder_corrupted_fragmentAI : public ScriptedAI
    {
        npc_hagara_the_stormbinder_corrupted_fragmentAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        }

        void IsSummonedBy(Unit* /*owner*/) override
        {
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat(me, 200.0f);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                AttackStart(target);
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };
};

class go_hagara_the_stormbinder_the_focusing_iris : public GameObjectScript
{
    public:
        go_hagara_the_stormbinder_the_focusing_iris() : GameObjectScript("go_hagara_the_stormbinder_the_focusing_iris") {}

        bool OnGossipHello(Player* /*pPlayer*/, GameObject* pGo) override
        {
            if (InstanceScript* pInstance = pGo->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_ZONOZZ) != DONE || pInstance->GetBossState(DATA_YORSAHJ) != DONE)
                {
                    pInstance->DoNearTeleportPlayers(teleportPos[0]);
                    return true;
                }

                if (Creature* pHagara = pInstance->GetCreature(DATA_HAGARA))
                {
                    pHagara->AI()->DoAction(ACTION_START_EVENT);
                    pGo->Delete();
                }
            }
            return true;
        }
};

class spell_dragon_soul_lieutenant_shara_frozen_grasp : public SpellScriptLoader
{
    public:
        spell_dragon_soul_lieutenant_shara_frozen_grasp() : SpellScriptLoader("spell_dragon_soul_lieutenant_shara_frozen_grasp") { }

        class spell_dragon_soul_lieutenant_shara_frozen_grasp_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dragon_soul_lieutenant_shara_frozen_grasp_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetCaster(), SPELL_FROZEN_GRASP_GRIP, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dragon_soul_lieutenant_shara_frozen_grasp_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dragon_soul_lieutenant_shara_frozen_grasp_SpellScript();
        }
};

class spell_hagara_the_stormbinder_icy_tomb_aoe : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_icy_tomb_aoe() : SpellScriptLoader("spell_hagara_the_stormbinder_icy_tomb_aoe") { }

        class spell_hagara_the_stormbinder_icy_tomb_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hagara_the_stormbinder_icy_tomb_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (!GetCaster()->GetVictim())
                    return;

                if (targets.size() > 1)
                    targets.remove(GetCaster()->GetVictim());
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_ICY_TOMB_DUMMY, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hagara_the_stormbinder_icy_tomb_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_hagara_the_stormbinder_icy_tomb_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hagara_the_stormbinder_icy_tomb_aoe_SpellScript();
        }
};

class spell_hagara_the_stormbinder_icy_tomb_dummy : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_icy_tomb_dummy() : SpellScriptLoader("spell_hagara_the_stormbinder_icy_tomb_dummy") { }

        class spell_hagara_the_stormbinder_icy_tomb_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hagara_the_stormbinder_icy_tomb_dummy_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_ICY_TOMB, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hagara_the_stormbinder_icy_tomb_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hagara_the_stormbinder_icy_tomb_dummy_SpellScript();
        }
};

class spell_hagara_the_stormbinder_icy_tomb : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_icy_tomb() : SpellScriptLoader("spell_hagara_the_stormbinder_icy_tomb") { }

        class spell_hagara_the_stormbinder_icy_tomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hagara_the_stormbinder_icy_tomb_AuraScript);

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Position pos = aurEff->GetBase()->GetOwner()->GetPosition();
                if (!GetCaster())
                    return;
                if (TempSummon* summon = GetCaster()->SummonCreature(NPC_ICY_TOMB, pos))
                    summon->AI()->SetGUID(aurEff->GetBase()->GetOwner()->GetGUID(), DATA_TRAPPED_PLAYER);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_hagara_the_stormbinder_icy_tomb_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hagara_the_stormbinder_icy_tomb_AuraScript();
        }
};

// Ice Lance 105287
class spell_hagara_the_stormbinder_ice_lance_target : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_ice_lance_target() : SpellScriptLoader("spell_hagara_the_stormbinder_ice_lance_target") { }

        class spell_hagara_the_stormbinder_ice_lance_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hagara_the_stormbinder_ice_lance_target_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.size() <= 1)
                    return;

                ObjectGuid guid;

                if (Creature* pLance = GetCaster()->ToCreature())
                {
                    guid = pLance->AI()->GetGUID(DATA_ICE_LANCE_GUID);
                }

                if (!guid)
                {
                    targets.clear();
                    return;
                }

                Player* pPlayer = ObjectAccessor::FindPlayer(guid);
                if (!pPlayer)
                {
                    targets.clear();
                    return;
                }
                WorldObject* objTarget = NULL;
                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if ((*itr)->IsInBetween(GetCaster(), pPlayer, 4.0f))
                        if (!objTarget || (GetCaster()->GetDistance(objTarget) > GetCaster()->GetDistance((*itr))))
                            objTarget = (*itr);

                if (!objTarget)
                    objTarget = pPlayer;
                targets.clear();
                targets.push_back(objTarget);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_ICE_LANCE_MISSILE, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hagara_the_stormbinder_ice_lance_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
                OnEffectHitTarget += SpellEffectFn(spell_hagara_the_stormbinder_ice_lance_target_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hagara_the_stormbinder_ice_lance_target_SpellScript();
        }
};

class spell_hagara_the_stormbinder_storm_pillars : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_storm_pillars() : SpellScriptLoader("spell_hagara_the_stormbinder_storm_pillars") { }

        class spell_hagara_the_stormbinder_storm_pillars_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hagara_the_stormbinder_storm_pillars_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_STORM_PILLAR, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hagara_the_stormbinder_storm_pillars_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hagara_the_stormbinder_storm_pillars_SpellScript();
        }
};

class spell_hagara_the_stormbinder_frostflake : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_frostflake() : SpellScriptLoader("spell_hagara_the_stormbinder_frostflake") { }

        class spell_hagara_the_stormbinder_frostflake_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hagara_the_stormbinder_frostflake_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetUnitOwner())
                    return;

                if (Aura* aur = GetAura())
                    if (aur->GetStackAmount() < 9)
                        aur->ModStackAmount(1);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                    if (removeMode == AURA_REMOVE_BY_EXPIRE || removeMode == AURA_REMOVE_BY_DEATH || removeMode == AURA_REMOVE_BY_ENEMY_SPELL)
                        GetCaster()->CastSpell(owner, SPELL_FROSTFLAKE_SNARE, true);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hagara_the_stormbinder_frostflake_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_hagara_the_stormbinder_frostflake_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hagara_the_stormbinder_frostflake_AuraScript();
        }
};

class spell_hagara_the_stormbinder_lightning_conduit : public SpellScriptLoader
{
    public:
        spell_hagara_the_stormbinder_lightning_conduit() : SpellScriptLoader("spell_hagara_the_stormbinder_lightning_conduit") { }

        class spell_hagara_the_stormbinder_lightning_conduit_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hagara_the_stormbinder_lightning_conduit_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster() || !GetTarget())
                    return;

                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                Creature* pHagara = GetCaster()->FindNearestCreature(NPC_HAGARA, 200.0f, true);
                Unit* target = GetTarget();
                if (!pHagara || !target)
                    return;

                if (pHagara->AI()->GetData(DATA_PHASE) != 10)
                    return;

                std::list<Player*> players;
                AnyPlayerOrCrystalCheck check(GetTarget(), 10.0f);
                Trinity::PlayerListSearcher<AnyPlayerOrCrystalCheck> searcher(pHagara, players, check);
                Cell::VisitWorldObjects(pHagara, searcher, 10.0f);

                if (!players.empty())
                {
                    for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        target->CastSpell((*itr), SPELL_LIGHTNING_CONDUIT_DUMMY_1, true);
                        target->CastSpell((*itr), SPELL_LIGHTNING_CONDUIT_DMG, true);
                    }
                }

                if (Creature* pCrystal = GetTarget()->FindNearestCreature(NPC_CRYSTAL_CONDUCTOR, 10.0f))
                {
                    target->CastSpell(pCrystal, SPELL_LIGHTNING_CONDUIT_DUMMY_1, true);
                    pCrystal->CastSpell(target, SPELL_LIGHTNING_CONDUIT_DMG, true);
                }

            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hagara_the_stormbinder_lightning_conduit_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:
            class AnyPlayerOrCrystalCheck
            {
                public:
                    AnyPlayerOrCrystalCheck(WorldObject const* obj, float range) : _obj(obj), _range(range) {}
                    bool operator()(Player* u)
                    {
                        if (u->GetGUID() == _obj->GetGUID())
                            return false;

                        if (u->HasAura(SPELL_LIGHTNING_CONDUIT_DUMMY_1))
                            return false;

                        if (!u->IsAlive())
                            return false;

                        if (!_obj->IsWithinDistInMap(u, _range))
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
            };
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_hagara_the_stormbinder_lightning_conduit_AuraScript();
        }
};

//Icicle Damage 92203
class spell_hagara_the_stormbinder_icicle_dmg : public SpellScriptLoader
{
public:
    spell_hagara_the_stormbinder_icicle_dmg() : SpellScriptLoader("spell_hagara_the_stormbinder_icicle_dmg") { }

    class spell_hagara_the_stormbinder_icicle_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hagara_the_stormbinder_icicle_dmg_SpellScript);

        bool Load() override
        {
            // This script should execute only in Dragon Soul
            if (InstanceMap* instance = GetCaster()->GetMap()->ToInstanceMap())
            if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(DSScriptName))
                return true;

            return false;
        }

        void HandleDummy()
        {
            if (!GetHitUnit()->IsAlive() || !GetCaster())
                return;

            uint32 dmg = GetHitDamage() * 2; //This is beacuse don´t exist one spell for this, and this spell is use in other side
            SetHitDamage(dmg);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_hagara_the_stormbinder_icicle_dmg_SpellScript::HandleDummy);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hagara_the_stormbinder_icicle_dmg_SpellScript();
    }
};


void AddSC_boss_hagara_the_stormbinder()
{
    new boss_hagara_the_stormbinder();
    new npc_hagara_the_stormbinder_stormborn_myrmidon();
    new npc_hagara_the_stormbinder_stormbinder_adept();
    new npc_hagara_the_stormbinder_tornado_stalker();
    new npc_hagara_the_stormbinder_twilight_frost_evoker();
    new npc_hagara_the_stormbinder_lieutenant_shara();
    new npc_hagara_the_stormbinder_icy_tomb();
    new npc_hagara_the_stormbinder_ice_lance();
    new npc_hagara_the_stormbinder_collapsing_icicle();
    new npc_hagara_the_stormbinder_ice_wave();
    new npc_hagara_the_stormbinder_frozen_binding_crystal();
    new npc_hagara_the_stormbinder_crystal_conductor();
    new npc_hagara_the_stormbinder_bound_lightning_elemental();
    new npc_hagara_the_stormbinder_corrupted_fragment();
    new go_hagara_the_stormbinder_the_focusing_iris();
    new spell_dragon_soul_lieutenant_shara_frozen_grasp();
    new spell_hagara_the_stormbinder_icy_tomb_aoe();
    new spell_hagara_the_stormbinder_icy_tomb_dummy();
    new spell_hagara_the_stormbinder_icy_tomb();
    new spell_hagara_the_stormbinder_ice_lance_target();
    new spell_hagara_the_stormbinder_storm_pillars();
    new spell_hagara_the_stormbinder_frostflake();
    new spell_hagara_the_stormbinder_lightning_conduit();
    new spell_hagara_the_stormbinder_icicle_dmg();
}
