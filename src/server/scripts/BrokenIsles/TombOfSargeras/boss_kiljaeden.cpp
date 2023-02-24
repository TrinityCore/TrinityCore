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

#include "AreaTriggerAI.h"
#include "tomb_of_sargeras.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_ILLIDAN_STAGE_4 = 0,

    SAY_AGGRO = 0,
    SAY_ARMAGEDDON = 1,
    SAY_WARN_ARMAGEDDON = 2,
    SAY_REFLECTION_ERUPTING = 3,
    SAY_RUPTURING_SINGULARITY = 4,
    SAY_WARN_RUPTURING_SINGULARITY = 5,
    SAY_STAGE_2_CHANGE = 6,
    SAY_FLY_POINT_1 = 7,
    SAY_BURSTING_DREADFLAME = 8,
    SAY_FOCUSED_DREADFLAME = 9,
    SAY_WARN_FOCUSED_DREADFLAME = 10,
    SAY_WAILING = 11,
    SAY_HOPELESS = 12,
    SAY_STAGE_4_CHANGE = 13,
    SAY_DECEIVER_VEIL_FINISH_CAST = 14,
    SAY_STAGE_5 = 15,
    SAY_TEAR_RIFT = 16,
    SAY_DARKNESS_THOUSAND_SOULS = 17,
    SAY_FLAMING_ORB = 18,
};

enum Spells
{
    SPELL_KILJAEDEN_BONUS_ROLL = 240662,
    SPELL_BERSERK = 47008,
    SPELL_FELCLAWS = 239932,
    SPELL_RUPTURING_SINGULARITY = 235059,
    SPELL_ARMAGEDDON_DUMMY = 240910,
    SPELL_ARMAGEDDON_RAIN_AT = 234295,
    SPELL_ARMAGEDDON_RAIN_SELF = 234309,
    SPELL_ARMAGEDDON_RAIN_DMG = 234310,
    SPELL_ARMAGEDDON_RAIN_VISUAL = 240832,
    SPELL_ARMAGEDDON_HAIL_AT = 240911,
    SPELL_ARMAGEDDON_HAIL_SELF = 240912,
    SPELL_ARMAGEDDON_HAIL_VISUAL = 240915,
    SPELL_ARMAGEDDON_HAIL_DMG = 240916,
    SPELL_ARMAGEDDON_BLAST = 240908,
    SPELL_BURSTING_DREADFLAME_FILTER = 238429,
    SPELL_FOCUSED_DREADFLAME_FILTER = 238505,
    SPELL_FOCUSED_DREADFLAME_DMG = 238502,
    SPELL_FOCUSED_DREADBURST = 238503, //Heroc+
    SPELL_SHADOW_REFLECTION_ERUPTING = 236710,
    SPELL_SHADOW_REFLECTION_WAILING = 236378, //Mythic
    SPELL_SHADOW_REFLECTION_HOPELESS = 237590, //Mythic
    SPELL_SUM_SHADOW_REFLECTION_ERUPTING = 242032,
    SPELL_ERUPTING_REFLECTION_CLONE = 236711,
    SPELL_DARKNESS_THOUSAND_SOULS = 238999,
    SPELL_DARKNESS_THOUSAND_SOULS_DMG = 239112,
    SPELL_DARKNESS_THOUSAND_SOULS_DUMMY = 239129,
    SPELL_DARKNESS_THOUSAND_SOULS_AURA = 239216,
    SPELL_TEAR_RIFT = 243982,
    SPELL_TEAR_RIFT_AT = 239130,
    SPELL_GRAVITY_SQUEEZE_DUMMY = 239154,
    SPELL_GRAVITY_SQUEEZE_DOT = 239155,
    SPELL_FLAMING_ORB_FILTER = 244856,

    SPELL_KILJAEDEN_PLAYERS_TELEPOT = 244719,
    SPELL_KILJAEDEN_PLAY_MOVIE = 246240,

    //Change phase
    SPELL_WINGSPAN_SOUND = 242377,
    SPELL_NETHER_GALE = 244834,

    SPELL_DECEIVER_VEIL_AT = 241983,
    SPELL_DECEIVER_VEIL_1 = 236555, //Decrease Hit chance
    SPELL_DECEIVER_VEIL_2 = 242696, //Hit ok
    SPELL_CURSED_SIGHT = 241768,
    SPELL_ILLIDAN_SIGHTLESS_GAZE = 241721,

    //Erupting Reflection
    SPELL_ERUPTING_DREADFLAME = 235120,
    SPELL_LINGERING_ERUPTION = 243536, //Mythic
    SPELL_LATENT_ERUPTION = 245014,
    SPELL_ERUPTING_ORB_AT = 243542, //Dmg 245017

    //Wailing Reflection
    SPELL_SORROWFUL_WAIL_AT = 241564,
    SPELL_SORROWFUL_WAIL_DMG = 236381,
    SPELL_LINGERING_WAIL = 243624,
    SPELL_WAILING_GRASP_FILTER = 243625,
    SPELL_WAILING_GRASP_JUMP = 243626,

    //Hopeless Reflection
    SPELL_HOPELESSNESS_DUMMY = 237725,
    SPELL_HOPELESSNESS_AT = 237728,
    SPELL_LINGERING_HOPE = 243621,

    //Shadowsoul
    SPELL_SPAWN_VISUAL = 241905,
    SPELL_DESTABILIZED_SHADOWSOUL_DMG = 241702,
    SPELL_DESTABILIZED_SHADOWSOUL_TP = 242074,

    //Demonic Obelisk
    SPELL_DEMONIC_OBELISK_VISUAL = 239785,
    SPELL_DEMONIC_OBELISK_DMG = 239852,

    //Nether Rift
    SPELL_TEAR_RIFT_VISUAL = 240020,

    //Flaming Orb
    SPELL_FLAMING_ORB_AT = 239256,
    SPELL_ORG_FIXATE = 239280,
    SPELL_FLAMING_DETONATION = 239267,
};

enum eEvents
{
    EVENT_FELCLAWS = 1,
    EVENT_RUPTURING_SINGULARITY = 2,
    EVENT_ARMAGEDDON = 3,
    EVENT_BURSTING_DREADFLAME = 4,
    EVENT_FOCUSED_DREADFLAME = 5,
    EVENT_SHADOW_REFLECTION_ERUPTING = 6,
    EVENT_DECEIVER_VEIL = 7,
    EVENT_DARKNESS_THOUSAND_SOULS = 8,
    EVENT_DEMONIC_OBELISK = 9,
    EVENT_TEAR_RIFT = 10,
    EVENT_FLAMING_ORB = 11,
    EVENT_SHADOW_REFLECTION_WAILING = 12, //Heroic+
    EVENT_SHADOW_REFLECTION_HOPELESS = 13, //Mythic
};

enum Stages
{
    S1_P1 = 1,
    S2_CHANGE = 2,
    S3_P2 = 3,
    S4_CHANGE = 4,
    S5_P3 = 5
};

enum eAnim
{
    //Illidan
    ILLIDAN_ANIM_1 = 12447, //SMSG_PLAY_ONE_SHOT_ANIM_KIT
    ILLIDAN_ANIM_2 = 12448,
    OBELISK_ANIM_1 = 4396,
    OBELISK_ANIM_2 = 8216,
};

enum eMisc
{
    DATA_HOPELESS_HEALTH_EVENT = 1,
    DATA_ACHIEVEMENT,
    
    EVENT_1,
    ACTION_1,
};

Position const centrPos = { 4500.39f, -1510.12f, 5385.64f };

Position const singularPos[5] =
{
    {4538.57f, -1548.27f, 5385.64f},
    {4462.66f, -1547.71f, 5385.64f},
    {4462.46f, -1472.97f, 5385.64f},
    {4538.33f, -1472.74f, 5385.64f},
    {4500.39f, -1510.12f, 5385.64f} //Center
};

Position const flyPos[5] =
{
    {4552.45f, -1458.32f, 5395.64f},
    {4552.29f, -1562.31f, 5395.64f},
    {4448.31f, -1561.16f, 5395.64f},
    {4445.37f, -1457.75f, 5395.64f},
    {4500.39f, -1510.12f, 5395.64f} //Center
};

Position const riftPos[4] =
{
    {4472.49f, -1449.58f, 5385.99f},
    {4528.95f, -1450.75f, 5385.99f},
    {4532.03f, -1568.90f, 5385.99f},
    {4469.95f, -1570.39f, 5385.99f}
};

//117269
struct boss_tos_kiljaeden : BossAI
{
    explicit boss_tos_kiljaeden(Creature* creature) : BossAI(creature, DATA_KILJAEDEN) {}

    bool flymove = false;
    bool darknessThousandEvent = false;
    bool achievement = true;
    uint8 stage = 0;
    uint8 sungularRand = 0;
    uint8 healthPct = 0;
    uint8 shadowsoulDiedCount = 0;
    uint8 obeliskCount = 0;
    uint8 obeliskIdx = 0;
    uint8 flamingOrbIdx = 0;
    uint8 armageddonCount = 0;
    uint32 wailingTimers = 0;
    uint32 berserkTimer = 0;
    std::vector<uint8> randList;
    std::map<uint8, std::list<uint32>> singularityTime;
    std::map<uint8, std::list<uint32>> armageddonTime;
    std::map<uint8, std::list<uint32>> burstingDreadflameTime;
    std::map<uint8, std::list<uint32>> focusedDreadFlameTime;

    void Reset() override
    {
        _Reset();
        flymove = false;
        darknessThousandEvent = false;
        achievement = true;
        stage = 0;
        sungularRand = 0;
        healthPct = 81;
        shadowsoulDiedCount = 0;
        obeliskCount = IsHeroicPlusRaid() ? 3 : 1;
        obeliskIdx = 0;
        flamingOrbIdx = 0;
        berserkTimer = (IsMythicRaid() ? 840 : 600) * IN_MILLISECONDS;
        randList = { 0, 1, 2, 3 };
        Trinity::Containers::RandomResize(randList, 2);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        _JustEngagedWith();

        if (IsMythicRaid())
        {
            armageddonCount = 8;
        }
        else if (me->GetMap()->GetPlayersCountExceptGMs() <= 15)
        {
            if (IsHeroicRaid())
                armageddonCount = 5;
            else if (IsNormalRaid())
                armageddonCount = 4;
            else if (IsLFR())
                armageddonCount = 3;
        }
        else if (me->GetMap()->GetPlayersCountExceptGMs() <= 20)
        {
            if (IsHeroicRaid())
                armageddonCount = 6;
            else if (IsNormalRaid())
                armageddonCount = 5;
            else if (IsLFR())
                armageddonCount = 4;
        }
        else if (me->GetMap()->GetPlayersCountExceptGMs() <= 25)
        {
            if (IsHeroicRaid())
                armageddonCount = 7;
            else if (IsNormalRaid())
                armageddonCount = 6;
            else if (IsLFR())
                armageddonCount = 4;
        }
        else if (me->GetMap()->GetPlayersCountExceptGMs() <= 30)
        {
            if (IsHeroicRaid())
                armageddonCount = 8;
            else if (IsNormalRaid())
                armageddonCount = 7;
            else if (IsLFR())
                armageddonCount = 6;
        }
        DefaultEvents();
    }

    void EnterEvadeMode(EvadeReason w)
    {
        //BossAI::EnterEvadeMode();
        //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetCanFly(false);
        me->NearTeleportTo(me->GetHomePosition());
        me->SetReactState(REACT_AGGRESSIVE);
        RemoveDebuff();
    }

    void RemoveDebuff()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DARKNESS_THOUSAND_SOULS_AURA);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DECEIVER_VEIL_1);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DECEIVER_VEIL_2);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ILLIDAN_SIGHTLESS_GAZE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        RemoveDebuff();
        DoCast(me, SPELL_KILJAEDEN_PLAY_MOVIE, true);
        me->SetLootRecipient(nullptr);
        me->GetMap()->LoadGrid(-254.31f, 5950.06f);

        instance->DoOnPlayers([](Player* player)
        {

            player->CastSpell(player, SPELL_KILJAEDEN_PLAYERS_TELEPOT, true);
        });

        if (auto chest = instance->instance->GetGameObject(instance->GetGuidData(GO_KILJAEDEN_CHEST)))
            chest->SetRespawnTime(86400);
    }

    void DefaultEvents()
    {
        ++stage;
        events.Reset();

        if (stage == S2_CHANGE || stage == S4_CHANGE)
            return;

        if (IsLFR())
        {
            armageddonTime[S1_P1] = { 10000, 22000, 42000, 22000, 30000 };
            armageddonTime[S3_P2] = { 56000, 28000, 56000, 26000, 12000, 20000 };
            burstingDreadflameTime[S3_P2] = { 58000, 53000, 61000, 57000 };
            burstingDreadflameTime[S5_P3] = { 42000, 25000, 70000 };
        }
        else if (IsMythicRaid())
        {
            singularityTime[S1_P1] = { 55000, 25000, 25000, 28000 };
            singularityTime[S3_P2] = { 22000, 50000, 67000, 78000, 84000 };
            armageddonTime[S1_P1] = { 11000, 54000, 38000 };
            armageddonTime[S3_P2] = { 18500, 32000, 45000, 33000, 36000, 36000, 47000, 32000, 45000 };
            burstingDreadflameTime[S3_P2] = { 52500, 50000, 45000, 48000, 86000, 50000 };
            burstingDreadflameTime[S5_P3] = { 30000, 52000, 43000 };
            focusedDreadFlameTime[S3_P2] = { 30000, 44000, 47000, 138000, 44000 };
            focusedDreadFlameTime[S5_P3] = { 48000, 36000, 59000 };
        }
        else if (IsHeroicRaid())
        {
            singularityTime[S1_P1] = { 58000, 56000 };
            singularityTime[S3_P2] = { 74000, 26000, 55000, 44000 };
            armageddonTime[S1_P1] = { 10000, 64000 };
            armageddonTime[S3_P2] = { 50400, 76000, 35000, 31000 };
            burstingDreadflameTime[S3_P2] = { 52400, 48000, 55000, 50000 };
            burstingDreadflameTime[S5_P3] = { 42000, 25000, 70000 };
            focusedDreadFlameTime[S3_P2] = { 30000, 46000, 53000, 46000 };
            focusedDreadFlameTime[S5_P3] = { 80000, 95000 };
        }
        else
        {
            singularityTime[S1_P1] = { 58000, 56000 };
            singularityTime[S3_P2] = { 74000, 81000 };
            armageddonTime[S1_P1] = { 10000, 64000 };
            armageddonTime[S3_P2] = { 50400, 45000, 31000, 35000, 31000, 78000 };
            burstingDreadflameTime[S3_P2] = { 52400, 48000, 55000, 50000 };
            burstingDreadflameTime[S5_P3] = { 42000, 25000, 70000 };
            focusedDreadFlameTime[S3_P2] = { 76000, 99000 };
            focusedDreadFlameTime[S5_P3] = { 80000, 95000 };
        }

        switch (stage)
        {
        case S1_P1:
            events.RescheduleEvent(EVENT_FELCLAWS, 25000);
            events.RescheduleEvent(EVENT_ARMAGEDDON, armageddonTime[stage].front());
            if (!IsLFR())
                events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, singularityTime[stage].front());
            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_ERUPTING, 18000);
            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_WAILING, 56000);
            break;
        case S3_P2:
            if (!IsLFR())
            {
                events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, singularityTime[stage].front());
                events.RescheduleEvent(EVENT_FOCUSED_DREADFLAME, focusedDreadFlameTime[stage].front());
            }
            events.RescheduleEvent(EVENT_FELCLAWS, 10000);
            events.RescheduleEvent(EVENT_ARMAGEDDON, armageddonTime[stage].front());
            events.RescheduleEvent(EVENT_BURSTING_DREADFLAME, burstingDreadflameTime[stage].front());
            events.RescheduleEvent(EVENT_SHADOW_REFLECTION_ERUPTING, IsMythicRaid() ? 163000 : 12000);
            if (IsMythicRaid())
            {
                wailingTimers = 168000;
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_WAILING, 50000);
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_HOPELESS, 26000);
            }
            else if (IsHeroicRaid())
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_WAILING, 48000);
            break;
        case S5_P3:
            events.RescheduleEvent(EVENT_FELCLAWS, 10000);
            events.RescheduleEvent(EVENT_DARKNESS_THOUSAND_SOULS, 1000);
            events.RescheduleEvent(EVENT_DEMONIC_OBELISK, 25000);
            events.RescheduleEvent(EVENT_TEAR_RIFT, 14000);
            events.RescheduleEvent(EVENT_BURSTING_DREADFLAME, burstingDreadflameTime[stage].front());
            if (IsHeroicPlusRaid())
                events.RescheduleEvent(EVENT_FLAMING_ORB, 30000);
            if (!IsLFR())
                events.RescheduleEvent(EVENT_FOCUSED_DREADFLAME, focusedDreadFlameTime[stage].front());
            break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            DoCast(me, SPELL_NETHER_GALE, true);
            me->SetSpeed(MOVE_FLIGHT, 5.0f);

            AddDelayedCombat(4000, [this]() -> void
            {
                me->GetMotionMaster()->MovePoint(2, flyPos[randList.front()], false);
            });
        }
        else if (id == 2)
        {
            uint32 delayTimer = IsMythicRaid() ? 57000 : 24000;
            flymove = false;
            Talk(SAY_FLY_POINT_1);
            me->SetFacingTo(flyPos[4].GetAngle(me) - M_PI);
            events.RescheduleEvent(EVENT_ARMAGEDDON, 1000);
            events.RescheduleEvent(EVENT_BURSTING_DREADFLAME, IsMythicRaid() ? 4000 : 2000);
            if (!IsLFR())
                events.RescheduleEvent(EVENT_FOCUSED_DREADFLAME, IsMythicRaid() ? 25000 : 18000);
            if (IsHeroicRaid())
                events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, 7000);
            else if (IsMythicRaid())
            {
                // Rupturing Singularity
                for (auto timer : { 8000, 13000, 26000, 31000, 36000, 41000 })
                {
                    AddDelayedCombat(timer, [this]() -> void { RupturingSingularity(); });
                }
            }

            AddDelayedCombat(delayTimer, [this]() -> void
            {
                flymove = true;
                me->GetMotionMaster()->MovePoint(3, flyPos[randList.back()], false);
            });
        }
        else if (id == 3)
        {
            uint32 delayTimer = IsMythicRaid() ? 24000 : 16000;
            flymove = false;
            Talk(SAY_FLY_POINT_1);
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
            me->SetFacingTo(flyPos[4].GetAngle(me) - M_PI);
            events.RescheduleEvent(EVENT_ARMAGEDDON, 1000);
            events.RescheduleEvent(EVENT_BURSTING_DREADFLAME, IsMythicRaid() ? 24000 : 20000);
            if (!IsLFR())
                events.RescheduleEvent(EVENT_FOCUSED_DREADFLAME, IsMythicRaid() ? 4000 : 2000);
            if (IsHeroicRaid())
                events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, 8000);
            else if (IsMythicRaid())
            {
                // Rupturing Singularity
                for (auto timer : { 7000, 12000 })
                {
                    AddDelayedCombat(timer, [this]() -> void { RupturingSingularity(); });
                }
            }

            AddDelayedCombat(delayTimer, [this]() -> void
            {
                flymove = true;
                me->GetMotionMaster()->MovePoint(4, flyPos[4], false);
            });
        }
        else if (id == 4)
        {
            me->SetCanFly(false);
            //me->SetAnimTier(0);
            me->GetMotionMaster()->MoveFall();
            me->RemoveAurasDueToSpell(SPELL_NETHER_GALE);
            me->SetReactState(REACT_AGGRESSIVE);
            flymove = false;
            DefaultEvents();
        }
        else if (id == 5)
        {
            me->CastSpell(me, SPELL_DARKNESS_THOUSAND_SOULS);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HealthBelowPct(healthPct))
        {
            if (healthPct == 81)
            {
                healthPct = 41;
                flymove = true;
                Talk(SAY_STAGE_2_CHANGE);
                DefaultEvents();
                me->AttackStop();
                me->SetCanFly(true);
               // me->SetAnimTier(3);
                me->SetSpeed(MOVE_FLIGHT, 3.0f);
                me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 10.0f, false);
                DoCast(me, SPELL_WINGSPAN_SOUND, true);
            }
            else if (healthPct == 41)
            {
                healthPct = 0;
                Talk(SAY_STAGE_4_CHANGE);
                shadowsoulDiedCount = 0;
                DefaultEvents();
                me->AttackStop();
                events.RescheduleEvent(EVENT_DECEIVER_VEIL, 500);
                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, 20000);
            }
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_ARMAGEDDON_DUMMY:
            Talk(SAY_WARN_ARMAGEDDON);
            Armageddon();
            break;
        case SPELL_DECEIVER_VEIL_AT:
            Talk(SAY_DECEIVER_VEIL_FINISH_CAST);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            break;
        case SPELL_DARKNESS_THOUSAND_SOULS:
            darknessThousandEvent = false;
            me->SetReactState(REACT_AGGRESSIVE);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_FOCUSED_DREADFLAME_FILTER:
            Talk(SAY_WARN_FOCUSED_DREADFLAME, target);
            me->CastSpell(target, SPELL_FOCUSED_DREADFLAME_DMG, false);
            break;
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (!me->IsInCombat() || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_SHADOW_REFLECTION_ERUPTING:
        {
            if (auto summon = me->SummonCreature(NPC_ERUPTING_REFLECTION, target->GetPosition()))
                target->CastSpell(summon, SPELL_ERUPTING_REFLECTION_CLONE, true);
            break;
        }
        case SPELL_SHADOW_REFLECTION_WAILING:
        {
            if (auto summon = me->SummonCreature(NPC_WAILING_REFLECTION, target->GetPosition()))
                target->CastSpell(summon, SPELL_ERUPTING_REFLECTION_CLONE, true);
            break;
        }
        case SPELL_SHADOW_REFLECTION_HOPELESS:
        {
            if (auto summon = me->SummonCreature(NPC_HOPELESS_REFLECTION, target->GetPosition()))
                target->CastSpell(summon, SPELL_ERUPTING_REFLECTION_CLONE, true);
            break;
        }
        default:
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SHADOWSOUL:
        {
            if (++shadowsoulDiedCount == 5)
            {
                Talk(SAY_STAGE_5);
                //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAurasDueToSpell(SPELL_DECEIVER_VEIL_AT);
                me->RemoveAreaTrigger(SPELL_DECEIVER_VEIL_AT);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DECEIVER_VEIL_1);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DECEIVER_VEIL_2);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ILLIDAN_SIGHTLESS_GAZE);
                summons.DespawnEntry(NPC_STAGE4_ILLIDAN_STORMRAGE);
                DefaultEvents();
            }
            break;
        }
        }
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
            achievement = false;
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_ACHIEVEMENT:
            return achievement ? 1 : 0;
        }
        return 0;
    }

    void RupturingSingularity()
    {
        uint8 sungularRandOld = sungularRand;

        while (sungularRandOld == sungularRand)
        {
            sungularRand = urand(0, 3);
        }

        me->CastSpell(singularPos[sungularRand], SPELL_RUPTURING_SINGULARITY, true);
    }

    void Armageddon()
    {
        std::list<Position> randPosList;
        //me->GenerateNonDuplicatePoints(randPosList, centrPos, armageddonCount, 15.0f, 38.0f, 8.0f);
        uint8 count = 0;

        for (auto _pos : randPosList)
        {
            if (auto summon = me->SummonCreature(NPC_ARMAGEDDON_STALKER, _pos, TEMPSUMMON_TIMED_DESPAWN, 8000))
            {
                if (!count || (count == 1 && IsMythicRaid()))
                    summon->CastSpell(summon, SPELL_ARMAGEDDON_HAIL_AT, true);
                else
                    summon->CastSpell(summon, SPELL_ARMAGEDDON_RAIN_AT, true);

                ++count;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;
                DoCast(me, SPELL_BERSERK, true);
            }
            else
                berserkTimer -= diff;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING) || flymove || darknessThousandEvent)
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FELCLAWS:
                DoCast(SPELL_FELCLAWS);
                events.RescheduleEvent(EVENT_FELCLAWS, 25000);
                break;
            case EVENT_RUPTURING_SINGULARITY:
                Talk(SAY_RUPTURING_SINGULARITY);
                Talk(SAY_WARN_RUPTURING_SINGULARITY);
                RupturingSingularity();
                if (singularityTime[stage].size() > 1)
                    singularityTime[stage].pop_front();
                if (!singularityTime[stage].empty())
                    events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, singularityTime[stage].front());
                if (stage == S4_CHANGE)
                    events.RescheduleEvent(EVENT_RUPTURING_SINGULARITY, 10000);
                break;
            case EVENT_ARMAGEDDON:
                DoCast(SPELL_ARMAGEDDON_DUMMY);
                if (armageddonTime[stage].size() > 1)
                    armageddonTime[stage].pop_front();
                if (!armageddonTime[stage].empty())
                {
                    Talk(SAY_ARMAGEDDON);
                    events.RescheduleEvent(EVENT_ARMAGEDDON, armageddonTime[stage].front());
                }
                break;
            case EVENT_BURSTING_DREADFLAME:
                Talk(SAY_BURSTING_DREADFLAME);
                DoCast(SPELL_BURSTING_DREADFLAME_FILTER);
                if (burstingDreadflameTime[stage].size() > 1)
                {
                    if (stage == S5_P3 && burstingDreadflameTime[stage].size() == 2)
                        burstingDreadflameTime[stage].reverse();
                    else
                        burstingDreadflameTime[stage].pop_front();
                }
                if (!burstingDreadflameTime[stage].empty())
                    events.RescheduleEvent(EVENT_BURSTING_DREADFLAME, burstingDreadflameTime[stage].front());
                break;
            case EVENT_FOCUSED_DREADFLAME:
                Talk(SAY_FOCUSED_DREADFLAME);
                DoCast(SPELL_FOCUSED_DREADFLAME_FILTER);
                if (focusedDreadFlameTime[stage].size() > 1)
                {
                    if (stage == S5_P3 && focusedDreadFlameTime[stage].size() == 2)
                        focusedDreadFlameTime[stage].reverse();
                    else
                        focusedDreadFlameTime[stage].pop_front();
                }
                if (!focusedDreadFlameTime[stage].empty())
                    events.RescheduleEvent(EVENT_FOCUSED_DREADFLAME, focusedDreadFlameTime[stage].front());
                break;
            case EVENT_SHADOW_REFLECTION_ERUPTING:
                Talk(SAY_REFLECTION_ERUPTING);
                DoCast(SPELL_SHADOW_REFLECTION_ERUPTING);
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_ERUPTING, IsMythicRaid() ? 163000 : 111000);
                break;
            case EVENT_DECEIVER_VEIL:
            {
                DoCast(SPELL_DECEIVER_VEIL_AT);
                Position pos;
                for (uint8 i = 0; i < 5; ++i)
                {
                    //centrPos.SimplePosXYRelocationByAngle(pos, frand(15.0f, 35.0f), frand(0.0f, 6.28f));
                    AddDelayedCombat(3000, [this, pos]() -> void { me->SummonCreature(NPC_SHADOWSOUL, pos); });
                }
                //centrPos.SimplePosXYRelocationByAngle(pos, frand(15.0f, 35.0f), frand(0.0f, 6.28f));
                AddDelayedCombat(7000, [this, pos]() -> void { me->SummonCreature(NPC_STAGE4_ILLIDAN_STORMRAGE, pos); });
                break;
            }
            case EVENT_DARKNESS_THOUSAND_SOULS:
                Talk(SAY_DARKNESS_THOUSAND_SOULS);
                darknessThousandEvent = true;
                me->AttackStop();
                me->GetMotionMaster()->MovePoint(5, flyPos[4]); //Center
                events.RescheduleEvent(EVENT_DARKNESS_THOUSAND_SOULS, 90000);
                break;
            case EVENT_DEMONIC_OBELISK:
            {
                uint32 timer = 36000;
                if (++obeliskIdx == 2)
                {
                    obeliskIdx = 0;
                    ++obeliskCount;
                    timer = 60000;
                }
                Position pos;
                for (uint8 i = 0; i < obeliskCount; ++i)
                {
                   // centrPos.SimplePosXYRelocationByAngle(pos, frand(25.0f, 35.0f), frand(0.0f, 6.28f));
                    me->SummonCreature(NPC_DEMONIC_OBELISK, pos);
                }
                events.RescheduleEvent(EVENT_DEMONIC_OBELISK, timer);
                break;
            }
            case EVENT_TEAR_RIFT:
            {
                Talk(SAY_TEAR_RIFT);
                summons.DespawnEntry(NPC_NETHER_RIFT);
                uint8 rand = urand(0, 3);
                me->CastSpell(riftPos[rand], SPELL_TEAR_RIFT, false);
                me->SummonCreature(NPC_NETHER_RIFT, riftPos[rand]);
                events.RescheduleEvent(EVENT_TEAR_RIFT, 94000);
                break;
            }
            case EVENT_FLAMING_ORB:
            {
                uint32 timer = 30000;
                if (++flamingOrbIdx == 2)
                {
                    flamingOrbIdx = 0;
                    timer = 60000;
                }
                Talk(SAY_FLAMING_ORB);
                DoCast(SPELL_FLAMING_ORB_FILTER);
                events.RescheduleEvent(EVENT_FLAMING_ORB, timer);
                break;
            }
            case EVENT_SHADOW_REFLECTION_WAILING:
                if (IsMythicRaid())
                    wailingTimers = wailingTimers == 168000 ? 60000 : 168000;
                else
                    wailingTimers = 114000;
                Talk(SAY_WAILING);
                me->CastSpell(me->GetVictim(), SPELL_SHADOW_REFLECTION_WAILING);
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_WAILING, stage == S1_P1 ? 114000 : wailingTimers);
                break;
            case EVENT_SHADOW_REFLECTION_HOPELESS:
                Talk(SAY_HOPELESS);
                DoCast(SPELL_SHADOW_REFLECTION_HOPELESS);
                events.RescheduleEvent(EVENT_SHADOW_REFLECTION_HOPELESS, 196000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//120839
struct npc_tos_armageddon_stalker : public ScriptedAI
{
    explicit npc_tos_armageddon_stalker(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override {}

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        auto owner = me->GetOwner();
        if (!owner)
            return;

        if (spell->Id == SPELL_ARMAGEDDON_RAIN_SELF)
        {
            owner->CastSpell(me, SPELL_ARMAGEDDON_RAIN_DMG, true);

            me->RemoveAurasDueToSpell(SPELL_ARMAGEDDON_RAIN_AT);
        }

        if (spell->Id == SPELL_ARMAGEDDON_HAIL_SELF)
        {
            owner->CastSpell(me, SPELL_ARMAGEDDON_HAIL_DMG, true);


            me->RemoveAurasDueToSpell(SPELL_ARMAGEDDON_HAIL_AT);
        }
    }

    void UpdateAI(uint32 /*diff*/) override {}
};

//119206
struct npc_tos_erupting_reflection : public ScriptedAI
{
    explicit npc_tos_erupting_reflection(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    ObjectGuid targetGUID;

    void IsSummonedBy(Unit* summoner) override
    {
        AddDelayedEvent(500, [this]() -> void { me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR); });
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void Reset() override {}

    void JustDied(Unit* /*killer*/) override
    {
        if (IsMythicRaid())
        {
            if (auto target = ObjectAccessor::GetPlayer(*me, targetGUID))
            {
                if (target->IsAlive())
                    if (auto owner = me->GetOwner())
                        owner->CastSpell(target, SPELL_LINGERING_ERUPTION, true);
            }
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ERUPTING_REFLECTION_CLONE)
            targetGUID = caster->GetGUID();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoSpellAttackIfReady(SPELL_ERUPTING_DREADFLAME);
    }
};

//119107
struct npc_tos_wailing_reflection : public ScriptedAI
{
    explicit npc_tos_wailing_reflection(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    ObjectGuid targetGUID;
    uint32 sorrowfulWailTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        AddDelayedEvent(500, [this]() -> void { me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR); });
        me->SetReactState(REACT_AGGRESSIVE);

        sorrowfulWailTimer = 16000;
    }

    void Reset() override {}

    void JustDied(Unit* /*killer*/) override
    {
        if (!IsMythicRaid())
            return;

        if (auto target = ObjectAccessor::GetPlayer(*me, targetGUID))
        {
            if (target->IsAlive())
                if (auto owner = me->GetOwner())
                    owner->CastSpell(target, SPELL_LINGERING_WAIL, true);
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ERUPTING_REFLECTION_CLONE)
            targetGUID = caster->GetGUID();
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (spellId == SPELL_SORROWFUL_WAIL_AT)
            DoCast(me, SPELL_SORROWFUL_WAIL_DMG, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (sorrowfulWailTimer)
        {
            if (sorrowfulWailTimer <= diff)
            {
                sorrowfulWailTimer = 14000;
                me->CastSpell(me, SPELL_SORROWFUL_WAIL_AT);
            }
            else
                sorrowfulWailTimer -= diff;
        }
        DoMeleeAttackIfReady();
    }
};

//119663
struct npc_tos_hopeless_reflection : public ScriptedAI
{
    explicit npc_tos_hopeless_reflection(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetRegenerateHealth(false);
        me->SetHealth(1);
    }

    uint32 checkTimer = 0;
    uint32 timePassed = 0;
    uint32 despawnTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_HOPELESSNESS_DUMMY, false);
        checkTimer = 500;
    }

    void Reset() override {}

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_HOPELESSNESS_DUMMY)
        {
            checkTimer = 0;
            DoCast(me, SPELL_HOPELESSNESS_AT, true);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_HOPELESS_HEALTH_EVENT:
            return timePassed / 1000;
        }
        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkTimer)
        {
            timePassed += diff;

            if (checkTimer <= diff)
            {
                checkTimer = 500;

                if (me->GetHealthPct() >= 99.9f)
                {
                    checkTimer = 0;
                    despawnTimer = 62000;
                    me->InterruptNonMeleeSpells(false);
                    me->CastSpell(me, SPELL_HOPELESSNESS_AT, true);
                    me->CastSpell(me, SPELL_LINGERING_HOPE, true);
                    //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    AddDelayedEvent(500, [this]() -> void { me->SetVisible(false); });
                }
            }
            else
                checkTimer -= diff;
        }
        if (despawnTimer)
        {
            if (despawnTimer <= diff)
            {
                despawnTimer = 0;
                me->DespawnOrUnsummon();
            }
            else
                despawnTimer -= diff;
        }
    }
};

//121193
struct npc_tos_shadowsoul : public ScriptedAI
{
    explicit npc_tos_shadowsoul(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    EventMap events;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_SPAWN_VISUAL, true);
        me->SetReactState(REACT_AGGRESSIVE);
        events.RescheduleEvent(EVENT_1, 3000);
    }

    void Reset() override {}

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_DESTABILIZED_SHADOWSOUL_DMG)
        {
            DoCast(me, SPELL_DESTABILIZED_SHADOWSOUL_TP, true);

            if (auto kj = me->GetOwner())
                if (kj->IsAIEnabled)
                    kj->GetAI()->DoAction(ACTION_1);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (events.ExecuteEvent() == EVENT_1)
        {
            me->CastSpell(me, SPELL_DESTABILIZED_SHADOWSOUL_DMG);
            events.RescheduleEvent(EVENT_1, 5000);
        }
    }
};

//121227
struct npc_tos_stage4_illidan_stormrage : public ScriptedAI
{
    explicit npc_tos_stage4_illidan_stormrage(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        //me->PlayOneShotAnimKit(ILLIDAN_ANIM_1);

        AddDelayedEvent(500, [this]() -> void
        {
            Talk(SAY_ILLIDAN_STAGE_4);
            me->CastSpell(me, SPELL_CURSED_SIGHT, true);
        });
    }

    void Reset() override {}

    void UpdateAI(uint32 /*diff*/) override {}
};

//120270
struct npc_tos_demonic_obelisk : public ScriptedAI
{
    explicit npc_tos_demonic_obelisk(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    uint32 obeliskVisualTimer = 0;
    uint32 animTimer = 0;
    uint32 obeliskDmgTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        obeliskVisualTimer = 9000;
        animTimer = 12000;
        obeliskDmgTimer = 14000;
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override
    {
        if (obeliskVisualTimer)
        {
            if (obeliskVisualTimer <= diff)
            {
                obeliskVisualTimer = 0;
                DoCast(me, SPELL_DEMONIC_OBELISK_VISUAL, true);
            }
            else
                obeliskVisualTimer -= diff;
        }
        if (animTimer)
        {
            if (animTimer <= diff)
            {
                animTimer = 0;
                //me->PlayOneShotAnimKit(OBELISK_ANIM_1);
            }
            else
                animTimer -= diff;
        }
        if (obeliskDmgTimer)
        {
            if (obeliskDmgTimer <= diff)
            {
                obeliskDmgTimer = 0;
                float x, y;
                float angle = 0.0f;
                for (uint8 i = 0; i < 4; ++i)
                {
                    me->GetNearPoint2D(x, y, 1.0f, angle);
                    me->CastSpell(x, y, me->GetPositionZ(), SPELL_DEMONIC_OBELISK_DMG, true);
                    angle += 3.14f / 2.0f;
                }
              //  me->PlayOneShotAnimKit(OBELISK_ANIM_2);
                me->DespawnOrUnsummon(500);
            }
            else
                obeliskDmgTimer -= diff;
        }
    }
};

//120390
struct npc_tos_nether_rift : public ScriptedAI
{
    explicit npc_tos_nether_rift(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    bool openRift = false;
    uint32 riftSumTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_TEAR_RIFT_VISUAL, true);
        riftSumTimer = 30000;
    }

    void Reset() override {}

};

//120082
struct npc_tos_flaming_orb : public ScriptedAI
{
    explicit npc_tos_flaming_orb(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetSpeed(MOVE_RUN, 2.0f);
    }

    uint32 startMovingTimer = 0;
    ObjectGuid targetGUID;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_FLAMING_ORB_AT, true);
        me->CastSpell(me, SPELL_ORG_FIXATE, true);
        startMovingTimer = 2000;
    }

    void Reset() override {}

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ORG_FIXATE)
            targetGUID = target->GetGUID();
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_FLAMING_DETONATION)
        {
            startMovingTimer = 0;
            me->RemoveAurasDueToSpell(SPELL_FLAMING_ORB_AT);
            me->InterruptNonMeleeSpells(false);
            me->GetMotionMaster()->Clear();
            me->DespawnOrUnsummon(500);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (startMovingTimer)
        {
            if (startMovingTimer <= diff)
            {
                startMovingTimer = 500;

                auto target = ObjectAccessor::GetPlayer(*me, targetGUID);
                if (!target || !target->IsAlive())
                {
                    startMovingTimer = 2000;
                    DoCast(me, SPELL_ORG_FIXATE, true);
                    me->GetMotionMaster()->Clear();
                }
                else
                    me->GetMotionMaster()->MovePoint(1, target->GetPosition(), false);
            }
            else
                startMovingTimer -= diff;
        }
    }
};

//238502
class spell_tos_focused_dreadflame : public SpellScript
{
    PrepareSpellScript(spell_tos_focused_dreadflame);

    uint8 count = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            return false;
        });

        count = targets.size();
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (count)
            SetHitDamage(GetHitDamage() / count);

        if (GetCaster() && GetHitUnit() && GetCaster()->GetMap()->IsHeroic())
            GetCaster()->CastSpell(GetHitUnit(), SPELL_FOCUSED_DREADBURST, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_focused_dreadflame::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_tos_focused_dreadflame::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//242074
class spell_tos_destabilized_shadowsoul : public SpellScript
{
    PrepareSpellScript(spell_tos_destabilized_shadowsoul);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_0);

        Position pos;
        //centrPos.SimplePosXYRelocationByAngle(pos, frand(15.0f, 35.0f), frand(0.0f, 6.28f));
        GetHitDest()->Relocate(pos);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_tos_destabilized_shadowsoul::HandleDummy, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

//238999
class spell_tos_darkness_thousand_souls : public SpellScript
{
    PrepareSpellScript(spell_tos_darkness_thousand_souls);

    ObjectGuid RiftGuid;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempTargets;

        for (auto target : targets)
        {
            if (target->IsPlayer())
                tempTargets.push_back(target);
            else if (target->GetEntry() == NPC_NETHER_RIFT)
                RiftGuid = target->GetGUID();
        }
        targets = tempTargets;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitUnit())
            return;

        if (auto caster = GetCaster())
        {
            if (GetHitUnit()->HasAura(SPELL_GRAVITY_SQUEEZE_DUMMY))
            {
                if (auto rift = Creature::GetCreature(*caster, RiftGuid))
                    caster->CastSpell(rift, SPELL_DARKNESS_THOUSAND_SOULS_DUMMY, true);
            }
            else
                caster->CastSpell(GetHitUnit(), SPELL_DARKNESS_THOUSAND_SOULS_DMG, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_darkness_thousand_souls::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_tos_darkness_thousand_souls::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//239280
class spell_tos_flaming_orb_fixate : public SpellScript
{
    PrepareSpellScript(spell_tos_flaming_orb_fixate);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            return false;
        });

        //targets.sort(Trinity::UnitSortDistance(true, GetCaster()));

        if (targets.size() > 1)
            targets.resize(1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_flaming_orb_fixate::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

//243625
class spell_tos_lingering_wail_jump : public SpellScript
{
    PrepareSpellScript(spell_tos_lingering_wail_jump);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster() && GetHitUnit())
            GetHitUnit()->CastSpell(GetCaster(), SPELL_WAILING_GRASP_JUMP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_lingering_wail_jump::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

//237728
class spell_tos_hopelessness : public SpellScript
{
    PrepareSpellScript(spell_tos_hopelessness);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (auto hopelessness = GetCaster())
        {
            float pct = float(hopelessness->GetAI()->GetData(DATA_HOPELESS_HEALTH_EVENT)) / 30.0f * 100.0f;
            SetHitDamage(CalculatePct(GetHitDamage(), pct));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tos_hopelessness::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//239154
class spell_tos_gravity_squeeze : public AuraScript
{
    PrepareAuraScript(spell_tos_gravity_squeeze);

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (GetUnitOwner())
        {
            if (InstanceScript* instance = GetUnitOwner()->GetInstanceScript())
                if (Creature* kiljaeden = instance->instance->GetCreature(instance->GetGuidData(DATA_KILJAEDEN)))
                    kiljaeden->CastSpell(GetUnitOwner(), SPELL_GRAVITY_SQUEEZE_DOT, true);
        }
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget())
            GetTarget()->RemoveAurasDueToSpell(SPELL_GRAVITY_SQUEEZE_DOT);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_gravity_squeeze::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_tos_gravity_squeeze::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//243536
class spell_tos_lingering_eruption : public AuraScript
{
    PrepareAuraScript(spell_tos_lingering_eruption);

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (GetUnitOwner())
        {
            GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_LATENT_ERUPTION, true);

            Position pos;
            float angle = 0.5f;
            for (uint8 i = 0; i < 3; ++i)
            {
                GetUnitOwner()->GetNearPosition(5.0f, angle);
                GetUnitOwner()->CastSpell(pos, SPELL_ERUPTING_ORB_AT, true);
                GetUnitOwner()->GetNearPosition(5.0f, -angle);
                GetUnitOwner()->CastSpell(pos, SPELL_ERUPTING_ORB_AT, true);
                angle += 1.0f;
            }
        }
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_lingering_eruption::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

//243624
class spell_tos_lingering_wail : public AuraScript
{
    PrepareAuraScript(spell_tos_lingering_wail);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();

        if (mode != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        if (GetTarget())
            GetTarget()->CastSpell(GetTarget(), SPELL_WAILING_GRASP_FILTER, true);
    }

    void Register()
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_tos_lingering_wail::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//15115, 15121
struct at_tos_armageddon : AreaTriggerAI
{
    at_tos_armageddon(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void ActionOnUpdate(GuidList& affectedPlayers)
    {
        auto owner = at->GetCaster();
        if (!owner)
            return;

        uint32 spellArmageddon = at->GetSpellId() == SPELL_ARMAGEDDON_RAIN_AT ? SPELL_ARMAGEDDON_RAIN_VISUAL : SPELL_ARMAGEDDON_HAIL_VISUAL;

        if (affectedPlayers.empty() && !owner->HasAura(spellArmageddon))
        {
            owner->CastSpell(owner, spellArmageddon, true);
        }
        else if (!affectedPlayers.empty() && owner->HasAura(spellArmageddon))
        {
            owner->RemoveAurasDueToSpell(spellArmageddon);
        }
    }
};
//14915
struct at_tos_flaming_detonation : AreaTriggerAI
{
    at_tos_flaming_detonation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    float createScale = 0.0f;
    float scaleStep = 0.0f;
    float maxDist = 0.0f;
    uint32 createScaleTimer = 0;
    uint32 scaleTimer = 0;
    Position finalPos;

    void OnCreate() override
    {
        createScale = CalculatePct(30.0f, 1 * 100.0f);
        createScaleTimer = 200;
    }

    bool CalculateSpline(Position const* pos, Position& startPos, Position& endPos, std::vector<Position>& path)
    {
        auto owner = at->GetCaster();
        auto rift = owner->FindNearestCreature(NPC_NETHER_RIFT, 150.0f);
        if (!owner || !rift)
        {
            at->Remove();
            return false;
        }

        finalPos = rift->GetPosition();
        maxDist = at->GetDistance(finalPos);

        startPos.m_positionX = pos->GetPositionX();
        startPos.m_positionY = pos->GetPositionY();
        startPos.m_positionZ = pos->GetPositionZ();

        endPos.m_positionX = rift->GetPositionX();
        endPos.m_positionY = rift->GetPositionY();
        endPos.m_positionZ = pos->GetPositionZ();
        return true;
    }

    void OnUpdate(uint32 diff) override
    {
        if (scaleTimer)
        {
            if (scaleTimer <= diff)
            {
                scaleTimer = 200;

                scaleStep = createScale * (at->GetDistance(finalPos) / maxDist);
                at->SetObjectScale(scaleStep);
                if (scaleStep <= 0.1f)
                    at->Remove();
            }
            else
                scaleTimer -= diff;
        }
    }
};

//1027000
struct at_tos_hopelessness : AreaTriggerAI
{
    at_tos_hopelessness(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    uint32 scaleTimer = 500;
    float scale = 0.0f;

    void OnCreate() override
    {
        auto owner = at->GetCaster();
        if (!owner)
            return;

        float pct = owner->GetAI()->GetData(DATA_HOPELESS_HEALTH_EVENT) / 30.0f;
        scale = 20.0f * pct;
    }

};

// 36478
class achievement_dark_souls : public AchievementCriteriaScript
{
public:
    achievement_dark_souls() : AchievementCriteriaScript("achievement_dark_souls") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Creature* Kj = target->ToCreature())
            if (Kj->AI()->GetData(DATA_ACHIEVEMENT))
                return true;

        return false;
    }
};

void AddSC_boss_tos_kiljaeden()
{
    RegisterCreatureAI(boss_tos_kiljaeden);
    RegisterCreatureAI(npc_tos_armageddon_stalker);
    RegisterCreatureAI(npc_tos_erupting_reflection);
    RegisterCreatureAI(npc_tos_wailing_reflection);
    RegisterCreatureAI(npc_tos_hopeless_reflection);
    RegisterCreatureAI(npc_tos_shadowsoul);
    RegisterCreatureAI(npc_tos_stage4_illidan_stormrage);
    RegisterCreatureAI(npc_tos_demonic_obelisk);
    RegisterCreatureAI(npc_tos_nether_rift);
    RegisterCreatureAI(npc_tos_flaming_orb);
    RegisterSpellScript(spell_tos_focused_dreadflame);
    RegisterSpellScript(spell_tos_destabilized_shadowsoul);
    RegisterSpellScript(spell_tos_darkness_thousand_souls);
    RegisterSpellScript(spell_tos_flaming_orb_fixate);
    RegisterSpellScript(spell_tos_lingering_wail_jump);
    RegisterSpellScript(spell_tos_hopelessness);
    RegisterAuraScript(spell_tos_gravity_squeeze);
    RegisterAuraScript(spell_tos_lingering_eruption);
    RegisterAuraScript(spell_tos_lingering_wail);
    RegisterAreaTriggerAI(at_tos_armageddon);
    RegisterAreaTriggerAI(at_tos_flaming_detonation);
    RegisterAreaTriggerAI(at_tos_hopelessness);
    new achievement_dark_souls();
}
