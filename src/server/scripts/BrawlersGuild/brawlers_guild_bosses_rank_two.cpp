/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AchievementMgr.h"
#include "brawlers_guild.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"


enum eSpells
{
    // dippy
    SPELL_PECK = 134537,

    // bill
    SPELL_SUMMON_BROOM = 233158,
    SPELL_SUMMON_BROOM_BOOM = 236458,

    // sanoriak
    SPELL_FIREBALL = 136333,
    SPELL_FIREWALL = 132666,
    SPELL_PYROBLAST = 136334,
    SPELL_FLAME_BUFFET = 135237,

    // master
    SPELL_DZEN = 229865,
    SPELL_DZEN_SPHERE = 229884,
    SPELL_MAIN_STATE = 229843,
};

// 68255
class boss_brawguild_dippy : public CreatureScript
{
public:
    boss_brawguild_dippy() : CreatureScript("boss_brawguild_dippy") {}

    struct boss_brawguild_dippyAI : public BossAI
    {
        boss_brawguild_dippyAI(Creature* creature) : BossAI(creature, DATA_BOSS_RANK_TWO) {}

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.RescheduleEvent(1, 3000);
        }

        void UpdateAI(uint32 diff) override
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
                case 1:
                    DoCast(SPELL_PECK);
                    events.RescheduleEvent(1, 3500);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_brawguild_dippyAI(creature);
    }
};

// 117077
class boss_brawguild_bill : public CreatureScript
{
public:
    boss_brawguild_bill() : CreatureScript("boss_brawguild_bill") {}

    struct boss_brawguild_billAI : public BossAI
    {
        boss_brawguild_billAI(Creature* creature) : BossAI(creature, DATA_BOSS_RANK_TWO) {}

        void Reset() override
        {
            summons.DespawnAll();
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.RescheduleEvent(1, 1000);
        }

        void UpdateAI(uint32 diff) override
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
                case 1:
                    DoCast(urand(1, 4) == 1 ? SPELL_SUMMON_BROOM_BOOM : SPELL_SUMMON_BROOM);
                    events.RescheduleEvent(1, urand(9000, 12000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_brawguild_billAI(creature);
    }
};

// 67268
class boss_brawguild_sanoriak : public CreatureScript
{
public:
    boss_brawguild_sanoriak() : CreatureScript("boss_brawguild_sanoriak") {}

    struct boss_brawguild_sanoriakAI : public BossAI
    {
        boss_brawguild_sanoriakAI(Creature* creature) : BossAI(creature, DATA_BOSS_RANK_TWO) {}

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.RescheduleEvent(1, 4000);
            events.RescheduleEvent(2, 7000);
            events.RescheduleEvent(3, 4000);
            events.RescheduleEvent(4, 26000);
        }

        void JustDied(Unit* who) override
        {
            _Reset();

            if (who)
            {
                Talk(1);
            }
        }

        void SpellFinishCast(const SpellInfo* spell)
        {
            if (spell->Id == SPELL_FIREWALL)
                events.RescheduleEvent(5, 1);
        }

        void UpdateAI(uint32 diff) override
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
                case 1:
                    Talk(0);
                    DoCast(SPELL_FIREWALL);
                    events.RescheduleEvent(1, urand(17000, 18000));
                    break;
                case 2:
                    DoCast(SPELL_PYROBLAST);
                    events.RescheduleEvent(2, urand(27000, 32000));
                    break;
                case 3:
                    DoCast(SPELL_FIREBALL);
                    events.RescheduleEvent(3, urand(4000, 4500));
                    break;
                case 4:
                    DoCast(SPELL_FLAME_BUFFET);
                    events.RescheduleEvent(4, urand(12000, 14000));
                    break;
                case 5:
                    DoCastVictim(132662);
                    DoCastVictim(132663);
                    DoCastVictim(132664);
                    DoCastVictim(132665);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_brawguild_sanoriakAI(creature);
    }
};


Position a_atPos[42]
{
    {-138.431f, 2499.43f, -49.109f, 6.23186f},
    {-141.506f, 2499.33f, -49.1092f, 6.26006f},
    {-141.621f, 2494.35f, -49.1092f, 6.26006f},
    {-141.73f, 2489.64f, -49.1092f, 6.26006f},
    {-141.847f, 2484.58f, -49.1092f, 6.26006f},
    {-141.411f, 2503.42f, -49.1092f, 6.26006f},
    {-141.297f, 2508.35f, -49.1092f, 6.26006f},
    {-141.206f, 2512.29f, -49.1092f, 6.26006f},
    {-141.114f, 2516.28f, -49.1092f, 6.26006f},
    {-135.438f, 2499.27f, -49.109f, 6.23186f},
    {-134.405f, 2492.4f, -49.109f, 6.27279f},
    {-134.695f, 2488.54f, -49.109f, 6.25305f},
    {-131.725f, 2488.33f, -49.109f, 0.00756502f},
    {-134.474f, 2506.09f, -49.109f, 0.0131671f},
    {-134.523f, 2509.82f, -49.109f, 0.0131671f},
    {-131.328f, 2509.87f, -49.109f, 0.0131671f},
    {-122.671f, 2494.66f, -49.109f, 0.0170913f},
    {-118.972f, 2491.51f, -49.109f, 0.0170913f},
    {-114.649f, 2494.79f, -49.109f, 0.0170913f},
    {-122.84f, 2502.72f, -49.109f, 6.26101f},
    {-118.69f, 2506.21f, -49.109f, 6.26886f},
    {-114.777f, 2502.32f, -49.109f, 0.0170913f},
    {-119.779f, 2483.2f, -49.109f, 0.0170913f},
    {-118.869f, 2516.82f, -49.109f, 6.2343f},
    {-108.306f, 2511.18f, -49.109f, 6.26179f},
    {-103.982f, 2511.09f, -49.109f, 6.26572f},
    {-109.547f, 2486.95f, -49.109f, 6.26572f},
    {-104.879f, 2486.87f, -49.109f, 6.26572f},
    {-105.101f, 2494.4f, -49.109f, 6.26572f},
    {-101.02f, 2494.33f, -49.109f, 6.26572f},
    {-100.783f, 2498.37f, -49.109f, 6.26179f},
    {-104.484f, 2502.67f, -49.109f, 6.26572f},
    {-100.999f, 2502.61f, -49.109f, 6.26572f},
    {-97.2453f, 2498.3f, -49.109f, 6.26179f},
    {-97.1538f, 2502.57f, -49.109f, 6.26179f},
    {-97.0674f, 2506.61f, -49.109f, 6.26179f},
    {-96.9946f, 2510.02f, -49.109f, 6.26179f},
    {-96.8997f, 2514.45f, -49.109f, 6.26179f},
    {-97.2928f, 2496.08f, -49.109f, 6.26179f},
    {-97.3789f, 2492.05f, -49.109f, 6.26179f},
    {-97.465f, 2488.03f, -49.109f, 6.26179f},
    {-97.5511f, 2484.0f, -49.109f, 6.26179f}
};

Position h_atPos[93]
{
    {2010.72f, -4734.05f, 86.7752f, 4.70682f},
    {2017.2f, -4732.25f, 86.7756f, 4.71467f},
    {2019.8f, -4732.16f, 86.7756f, 4.71467f},
    {2011.16f, -4761.27f, 86.7701f, 4.73822f},
    {2011.07f, -4757.91f, 86.7701f, 4.73822f},
    {2022.36f, -4732.06f, 86.7754f, 4.71467f},
    {2025.34f, -4732.05f, 86.7754f, 4.71467f},
    {2027.86f, -4732.05f, 86.7754f, 4.71467f},
    {2031.35f, -4738.89f, 86.77f, 4.77357f},
    {2031.17f, -4736.09f, 86.77f, 4.77357f},
    {2030.09f, -4732.04f, 86.7754f, 4.71467f},
    {2010.97f, -4754.02f, 86.7701f, 4.73822f},
    {2010.73f, -4739.8f, 86.7701f, 4.70288f},
    {2010.7f, -4743.52f, 86.7701f, 4.73822f},
    {2010.77f, -4746.44f, 86.7701f, 4.73822f},
    {2010.87f, -4750.3f, 86.7701f, 4.73822f},
    {2010.76f, -4736.48f, 86.7701f, 4.70288f},
    {2045.62f, -4773.25f, 86.7704f, 4.73822f},
    {2051.19f, -4750.06f, 86.7765f, 4.69504f},
    {2050.62f, -4738.7f, 86.7765f, 4.67541f},
    {2011.66f, -4732.46f, 87.05f, 4.68718f},
    {2013.49f, -4732.39f, 86.7756f, 4.68718f},
    {2015.14f, -4732.33f, 86.7756f, 4.68718f},
    {2032.26f, -4732.04f, 86.7754f, 4.71467f},
    {2035.58f, -4732.03f, 86.7754f, 4.71467f},
    {2041.44f, -4732.01f, 86.7754f, 4.71467f},
    {2038.28f, -4732.02f, 86.7754f, 4.71467f},
    {2047.5f, -4731.94f, 86.7754f, 4.73038f},
    {2045.0f, -4731.98f, 86.7754f, 4.72645f},
    {2050.76f, -4732.11f, 86.7704f, 4.73822f},
    {2050.81f, -4734.36f, 86.7704f, 4.73822f},
    {2050.87f, -4736.6f, 86.7704f, 4.73822f},
    {2050.99f, -4741.1f, 86.7704f, 4.73822f},
    {2051.05f, -4743.35f, 86.7704f, 4.73822f},
    {2051.1f, -4745.6f, 86.7704f, 4.73822f},
    {2051.16f, -4747.85f, 86.7704f, 4.73822f},
    {2051.28f, -4752.35f, 86.7704f, 4.73822f},
    {2051.34f, -4754.6f, 86.7704f, 4.73822f},
    {2051.4f, -4756.85f, 86.7704f, 4.73822f},
    {2051.51f, -4761.35f, 86.7704f, 4.73822f},
    {2051.57f, -4763.6f, 86.7704f, 4.73822f},
    {2051.63f, -4765.85f, 86.7704f, 4.73822f},
    {2051.69f, -4768.09f, 86.7704f, 4.73822f},
    {2051.74f, -4770.13f, 86.7704f, 4.73822f},
    {2051.31f, -4773.1f, 86.7704f, 4.73822f},
    {2048.45f, -4773.18f, 86.7704f, 4.73822f},
    {2042.59f, -4773.33f, 86.7704f, 4.73822f},
    {2038.84f, -4773.43f, 86.7704f, 4.73822f},
    {2035.81f, -4773.51f, 86.7704f, 4.73822f},
    {2032.46f, -4773.59f, 86.7704f, 4.73822f},
    {2029.32f, -4773.67f, 86.7704f, 4.73822f},
    {2026.05f, -4773.76f, 86.7704f, 4.73822f},
    {2023.19f, -4773.83f, 86.7704f, 4.73822f},
    {2019.99f, -4773.91f, 86.7704f, 4.73822f},
    {2016.52f, -4774.0f, 86.7704f, 4.73822f},
    {2014.34f, -4774.06f, 86.7704f, 4.73822f},
    {2011.49f, -4774.13f, 86.7701f, 4.73822f},
    {2011.43f, -4771.82f, 86.7701f, 4.73822f},
    {2011.34f, -4768.29f, 86.7701f, 4.73822f},
    {2011.25f, -4764.84f, 86.7701f, 4.73822f},
    {2051.09f, -4758.56f, 86.7765f, 4.71467f},
    {2023.49f, -4738.59f, 86.7765f, 4.7186f},
    {2019.7f, -4738.63f, 86.7765f, 4.72252f},
    {2019.73f, -4742.28f, 86.7765f, 4.72252f},
    {2043.31f, -4742.04f, 86.7765f, 4.72252f},
    {2043.49f, -4737.94f, 86.7765f, 4.72252f},
    {2039.88f, -4737.98f, 86.7765f, 4.72252f},
    {2048.07f, -4750.35f, 86.7765f, 4.7775f},
    {2013.93f, -4751.86f, 86.7763f, 4.73823f},
    {2043.64f, -4760.47f, 86.7763f, 4.75473f},
    {2043.84f, -4764.49f, 86.7763f, 4.77436f},
    {2026.61f, -4755.43f, 86.7763f, 4.77829f},
    {2035.81f, -4748.17f, 86.7763f, 4.73509f},
    {2039.44f, -4750.67f, 86.7763f, 4.73509f},
    {2036.74f, -4754.35f, 86.7763f, 4.73509f},
    {2023.26f, -4752.25f, 86.7763f, 4.90395f},
    {2026.8f, -4749.27f, 86.7763f, 4.90788f},
    {2019.24f, -4761.23f, 86.7763f, 4.73902f},
    {2019.34f, -4764.91f, 86.7763f, 4.73902f},
    {2026.51f, -4765.39f, 86.7763f, 4.73902f},
    {2026.62f, -4769.79f, 86.7763f, 4.73902f},
    {2036.26f, -4769.53f, 86.7763f, 4.73902f},
    {2031.6f, -4769.66f, 86.7763f, 4.73902f},
    {2036.09f, -4764.92f, 86.7763f, 4.73902f},
    {2033.92f, -4769.59f, 86.7763f, 4.72724f},
    {2029.03f, -4769.66f, 86.7763f, 4.72724f},
    {2026.48f, -4767.59f, 86.7763f, 4.72724f},
    {2036.26f, -4767.15f, 86.7763f, 4.72724f},
    {2026.67f, -4771.46f, 86.7763f, 4.80971f},
    {2029.26f, -4771.54f, 86.7763f, 4.80971f},
    {2032.07f, -4771.26f, 86.7763f, 4.80579f},
    {2034.17f, -4771.07f, 86.7763f, 4.80579f},
    {2036.2f, -4771.0f, 86.7763f, 4.74296f},
};

uint32 a_WP[6]
{
    11854504,
    11854505,
    11854506,
    11854507,
    11854508,
    11854504
};

uint32 h_WP[6]
{
    11854509,
    11854510,
    11854511,
    11854512,
    11854513,
    11854509
};

Position a_spherePos[15]
{
    {-118.662f, 2499.05f, -49.1082f, 3.19389f},
    {-104.649f, 2490.59f, -49.1082f, 0.0169518f},
    {-103.529f, 2507.13f, -49.1082f, 0.00124788f},
    {-132.056f, 2506.37f, -49.1082f, 3.16641f},
    {-131.921f, 2491.65f, -49.1082f, 3.11143f},

    {-118.817f, 2498.37f, -49.1082f, 6.25695f},
    {-133.01f, 2483.17f, -49.1082f, 3.15855f},
    {-134.121f, 2515.38f, -49.1082f, 3.17426f},
    {-104.153f, 2515.17f, -49.1082f, 3.17426f},
    {-104.621f, 2482.92f, -49.1082f, 3.22924f},

    {-103.925f, 2498.39f, -49.1082f, 3.23317f},
    {-100.595f, 2511.22f, -49.1082f, 6.27266f},
    {-101.506f, 2486.79f, -49.1082f, 6.27266f},
    {-138.729f, 2489.29f, -49.1082f, 6.27266f},
    {-138.254f, 2508.86f, -49.1082f, 6.25695f}
};

Position h_spherePos[15]
{
    {2031.84f, -4752.73f, 86.7763f, 1.67313f},
    {2040.32f, -4762.81f, 86.7763f, 3.39315f},
    {2039.15f, -4748.52f, 86.7763f, 3.16538f},
    {2023.53f, -4748.31f, 86.7763f, 1.57888f},
    {2022.99f, -4761.75f, 86.7763f, 1.49248f},
    {2015.47f, -4763.47f, 86.7763f, 4.72047f},
    {2015.7f, -4741.59f, 86.7763f, 1.63779f},
    {2047.28f, -4741.58f, 86.7763f, 1.57103f},
    {2047.64f, -4762.9f, 86.7763f, 1.57103f},
    {2031.53f, -4766.39f, 86.7763f, 1.57103f},
    {2019.24f, -4769.91f, 86.7763f, 4.74011f},
    {2043.97f, -4769.23f, 86.7763f, 4.75582f},
    {2041.74f, -4735.14f, 86.7763f, 1.57103f},
    {2021.5f, -4734.95f, 86.7763f, 1.57103f},
    {2031.55f, -4752.33f, 86.7763f, 1.57103f}
};

// 115645, 115637
// + sphere 115660 (229884) + AT 4520    
class boss_brawguild_master : public CreatureScript
{
public:
    boss_brawguild_master() : CreatureScript("boss_brawguild_master") {}

    struct boss_brawguild_masterAI : public BossAI
    {
        boss_brawguild_masterAI(Creature* creature) : BossAI(creature, DATA_BOSS_RANK_TWO)
        {
            count_adds = 0;
            me->setRegeneratingHealth(false);
            me->SetReactState(REACT_PASSIVE);
        }

        uint8 count_adds;
        uint8 phase_of_sphere;
        uint32 timer_check;

        void Reset() override
        {
            timer_check = 500;
            if (me->GetEntry() == 115645)
            {
                me->CastSpell(me, 229862);
                me->SummonCreature(115637, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->SummonCreature(115637, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->SummonCreature(115637, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());

                if (me->GetOwner() && me->GetOwner()->IsPlayer())
                {
                    if (Player* player = me->GetOwner()->ToPlayer())
                    {
                        Position* pos = player->GetTeamId() == TEAM_ALLIANCE ? a_atPos : h_atPos;
                        uint8 count = player->GetTeamId() == TEAM_ALLIANCE ? 42 : 93;
                    }
                }
                phase_of_sphere = 1;

                me->AddDelayedEvent(3000, [this]() -> void
                {
                    if (me->GetOwner() && me->GetOwner()->IsPlayer())
                    {
                        if (Player* player = me->GetOwner()->ToPlayer())
                        {
                            Position* pos = player->GetTeamId() == TEAM_ALLIANCE ? a_spherePos : h_spherePos;
                            for (uint8 i = 0; i < 5; ++i)
                                me->SummonCreature(115660, pos[i].GetPositionX(), pos[i].GetPositionY(), pos[i].GetPositionZ(), pos[i].GetOrientation());
                        }
                    }
                });

                if (Unit* owner = me->GetOwner())
                    if (Player* player = owner->ToPlayer())
                        player->AddAura(SPELL_MOVE_FORWARD, player);
                me->SetVisible(false);
            }
        }

        void DoAction(int32 const /*action*/) override
        {
            if (me->GetEntry() == 115645)
            {
                summons.DespawnEntry(115660);
                EntryCheckPredicate pred(115637);
                summons.DoAction(true, pred);

                me->AddDelayedEvent(20000, [this]() -> void
                {
                    if (me->GetOwner() && me->GetOwner()->IsPlayer())
                    {
                        if (Player* player = me->GetOwner()->ToPlayer())
                        {
                            Position* pos = player->GetTeamId() == TEAM_ALLIANCE ? a_spherePos : h_spherePos;
                            for (uint8 i = phase_of_sphere * 5; i < phase_of_sphere * 5 + 5; ++i)
                                me->SummonCreature(115660, pos[i].GetPositionX(), pos[i].GetPositionY(), pos[i].GetPositionZ(), pos[i].GetOrientation());
                        }
                    }
                });

                phase_of_sphere++;

                if (phase_of_sphere == 3)
                    phase_of_sphere = 0;
            }
            else if (me->GetEntry() == 115637)
                DoCast(SPELL_DZEN);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() != 115637)
                return;

            if (Unit* owner = me->GetOwner())
                summon->AI()->EnterCombat(owner);

            if (me->GetOwner() && me->GetOwner()->IsPlayer())
                if (Player* player = me->GetOwner()->ToPlayer())
                {
                    summon->GetMotionMaster()->MovePath(player->GetTeamId() == TEAM_ALLIANCE ? a_WP[count_adds] : h_WP[count_adds], false);
                    summon->AddDelayedEvent(47000, [summon, player]() -> void
                    {
                        summon->GetMotionMaster()->Clear();
                        summon->GetMotionMaster()->MovePath(player->GetTeamId() == TEAM_ALLIANCE ? a_WP[urand(0, 5)] : h_WP[urand(0, 5)], false);
                    });
                }

            count_adds++;

            switch (count_adds)
            {
            case 1:
                summon->CastSpell(summon, 229861);
                summon->CastSpell(summon, SPELL_MAIN_STATE);
                break;
            case 2:
                summon->CastSpell(summon, 229860);
                summon->CastSpell(summon, SPELL_MAIN_STATE);
                break;
            case 3:
                summon->CastSpell(summon, 229852);
                summon->CastSpell(summon, SPELL_MAIN_STATE);
                break;
            }
        }

        void JustDied(Unit* who) override
        {
            if (me->GetEntry() == 115637)
            {
                me->DespawnOrUnsummon(100);
                return;
            }

            _Reset();
          //  me->KillAllDelayedEvents();

            if (!who)
                return;

        }

        void KilledUnit(Unit* who) override
        {
            if (Unit* owner = me->GetOwner())
            {
                if (owner->IsPlayer())
                {
                    if (who->GetGUID() != owner->GetGUID())
                        return;
                  //  me->KillAllDelayedEvents();
                    _Reset();
                }
                else
                    owner->ToCreature()->AI()->KilledUnit(who);
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() != 115637)
                return;


            count_adds--;
            if (count_adds == 0)
            {
                summons.DespawnAll();
                if (me->GetOwner() && me->GetOwner()->IsPlayer())
                {
                //    me->KillAllDelayedEvents();
                    Player* player = me->GetOwner()->ToPlayer();
                    player->AddDelayedEvent(700, [player]() -> void
                    {
                           if (player && player->IsAlive())
                               if (BrawlersGuild* brawlerGuild = player->GetBrawlerGuild())
                                   brawlerGuild->BossReport(player->GetGUID(), true);
                    });
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->GetEntry() == 115645)
            {
                if (timer_check <= diff)
                {
                    if (Unit* owner = me->GetOwner())
                    {
                        if (!owner->IsAlive())
                            KilledUnit(owner);
                    }
                    else
                        timer_check = 500;
                }
                else
                    timer_check -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_brawguild_masterAI(creature);
    }
};

// 115660
class npc_brawguild_master_sphere : public CreatureScript
{
public:
    npc_brawguild_master_sphere() : CreatureScript("npc_brawguild_master_sphere") { }

    struct npc_brawguild_master_sphereAI : public ScriptedAI
    {
        npc_brawguild_master_sphereAI(Creature* creature) : ScriptedAI(creature)
        {
            me->CastSpell(me, 229878);
            justCasted = false;
        }

        bool justCasted;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!justCasted && me->GetExactDist2d(who) <= 2)
            {
                justCasted = true;
                who->CastSpell(who, SPELL_DZEN_SPHERE);
                if (Unit* owner = me->GetOwner())
                    if (Creature* master = owner->ToCreature())
                        master->AI()->DoAction(true);
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_brawguild_master_sphereAI(creature);
    }
};

void AddSC_the_brawlers_guild_bosses_rank_two()
{
    new boss_brawguild_dippy();
    new boss_brawguild_bill();
    new boss_brawguild_sanoriak();
    new boss_brawguild_master();
    new npc_brawguild_master_sphere();
};

