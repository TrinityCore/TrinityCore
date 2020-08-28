/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "zulaman.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Weather.h"

enum Texts
{
    // Akil'zon
    SAY_AGGRO                       = 0,
    SAY_SUMMON_EAGLES               = 1,
    SAY_ANNOUNCE_ELECTRICAL_STORM   = 2,
    SAY_SLAY                        = 3,
    SAY_DEATH                       = 4
};

enum Spells
{
    // Akil'zon
    SPELL_STATIC_DISRUPTION             = 43622,
    SPELL_CALL_LIGHTNING                = 43661,
    SPELL_GUST_OF_WIND                  = 43621,
    SPELL_ELECTRICAL_STORM              = 43648,

    // Soaring Eagle
    SPELL_EAGLE_SWOOP                   = 44732,

    // Amani Kidnapper
    SPELL_GRAB_PASSENGER                = 98869,
    SPELL_PLUCKED                       = 97318,

    // Player
    SPELL_TELEPORT_SELF                 = 44006,
    SPELL_ELECTRICAL_STORM_AREA_AURA    = 44007,
    SPELL_ELECTRICAL_ARC_1              = 43653,
    SPELL_ELECTRICAL_ARC_2              = 43654,
    SPELL_ELECTRICAL_ARC_3              = 43655,
    SPELL_ELECTRICAL_ARC_4              = 43656,
    SPELL_ELECTRICAL_ARC_5              = 43659
};

uint32 const electricalArcSpells[5] =
{
    SPELL_ELECTRICAL_ARC_1,
    SPELL_ELECTRICAL_ARC_2,
    SPELL_ELECTRICAL_ARC_3,
    SPELL_ELECTRICAL_ARC_4,
    SPELL_ELECTRICAL_ARC_5
};

enum Events
{
    // Akil'zon
    EVENT_STATIC_DISRUPTION = 1,
    EVENT_CALL_LIGHTNING,
    EVENT_GUST_OF_WIND,
    EVENT_ELECTRICAL_STORM,
    EVENT_START_RAIN,
    EVENT_END_RAIN,
    EVENT_SUMMON_SOARING_EAGLES,

    // Soaring Eagle
    EVENT_EAGLE_SWOOP,
    EVENT_EAGLE_SCREECH,
    EVENT_MOVE_RANDOM,
    EVENT_MOVE_CYCLIC_PATH
};

enum Actions
{
    // Soaring Eagle
    ACTION_DO_RANDOM_MOVEMENT = 1
};

enum Data
{
    DATA_EAGLE_NUMBER = 0
};

enum MovePoints
{
    // Amani Kidnapper
    POINT_GRAB_PASSENGER = 1
};

enum Misc
{
    ZONE_ID_ZULAMAN         = 3805,
    SOUND_ID_EAGLE_SCREECH  = 12196
};

Position const SoaringEagleSummonPositions[] =
{
    { 355.0323f, 1411.f,    91.6518f,  5.856372f },
    { 356.82877f, 1422.785f, 91.71573f, 1.518436f },
    { 368.7743f, 1377.933f, 91.78314f, 0.4260757f },
    { 361.3212f, 1380.682f, 91.76196f, 3.036873f  },
    { 396.1938f, 1398.954f, 91.53065f, 4.3096f    },
    { 395.2363f, 1391.221f, 91.78426f, 3.787364f  },
    { 386.3385f, 1430.294f, 92.51662f, 3.173957f  },
    { 379.344f,  1434.552f, 91.64027f, 0.9599311f }
};

std::vector<Position> AmaniKidnapperCyclicPath =
{
    { 360.25174f, 1422.9219f, 79.72605f },
    { 373.98438f, 1431.1823f, 79.85269f },
    { 395.0295f,  1425.8403f, 79.52386f },
    { 399.20486f, 1398.4219f, 79.31239f },
    { 390.6059f,  1390.1146f, 79.76962f },
    { 372.62674f, 1383.9062f, 79.27089f },
    { 354.83682f, 1397.5192f, 79.283394f },
    { 353.40973f, 1414.5608f, 79.529434f }
};

std::vector<Position> SoraringEagleCyclicPath0 =
{
   { 352.03665f, 1411.3475f, 91.7419f },
   { 352.768f, 1412.0295f, 91.7419f },
   { 389.26443f, 1394.4066f, 90.3169f },
   { 405.69748f, 1381.4075f, 90.3169f },
   { 418.16028f, 1383.2f, 90.3169f },
   { 415.5009f, 1387.942f, 90.3169f },
   { 399.76562f, 1414.877f, 90.3169f },
   { 380.8964f, 1424.8958f, 90.3169f },
   { 357.7345f, 1418.2468f, 90.3169f },
   { 342.5394f, 1404.734f, 90.3169f },
   { 343.50098f, 1395.6887f, 90.3169f },
   { 340.88748f, 1384.222f, 90.3169f },
   { 360.84256f, 1382.7749f, 90.3169f },
   { 369.62912f, 1388.5502f, 90.3169f },
   { 376.77408f, 1400.9977f, 90.3169f },
   { 388.67688f, 1423.4247f, 90.3169f },
   { 398.8929f, 1441.9341f, 90.3169f },
   { 382.19348f, 1437.8445f, 90.3169f },
   { 370.78647f, 1423.2487f, 90.3169f },
   { 356.91635f, 1397.7987f, 90.3169f },
   { 354.5165f, 1380.9031f, 90.3169f },
   { 395.601f, 1376.0145f, 90.3169f },
   { 422.74762f, 1384.6039f, 90.3169f },
   { 398.88052f, 1410.5187f, 90.3169f },
   { 382.2971f, 1424.7145f, 90.3169f },
   { 360.14865f, 1431.6875f, 90.3169f },
   { 345.7219f, 1422.5363f, 90.3169f },
   { 345.66623f, 1416.4381f, 90.3169f },
   { 389.26443f, 1394.4066f, 90.3169f },
   { 405.69748f, 1381.4075f, 90.3169f }
};

std::vector<Position> SoraringEagleCyclicPath2 =
{
    { 367.06046f, 1376.0284f, 91.747284f },
    { 366.48688f, 1376.8475f, 91.747284f },
    { 402.18002f, 1393.9266f, 92.29734f },
    { 405.5344f, 1407.2664f, 92.29734f },
    { 391.50912f, 1426.6482f, 92.29734f },
    { 384.56445f, 1434.1189f, 92.29734f },
    { 357.36685f, 1441.9121f, 92.29734f },
    { 351.07693f, 1440.2948f, 92.29734f },
    { 329.53537f, 1422.8164f, 92.29734f },
    { 331.16852f, 1411.1921f, 92.29734f },
    { 352.1847f, 1384.4667f,  92.29734f },
    { 394.28995f, 1393.1965f, 92.29734f },
    { 410.53754f, 1400.7565f, 92.29734f },
    { 397.51172f, 1432.3961f, 92.29734f },
    { 351.6988f, 1433.4469f, 92.29734f },
    { 335.5918f, 1438.5464f, 92.29734f },
    { 328.19498f, 1434.6647f, 92.29734f },
    { 319.32867f, 1429.3776f, 92.29734f },
    { 329.76138f, 1413.6876f, 92.29734f },
    { 365.2091f, 1407.883f, 92.29734f },
    { 402.18002f, 1393.9266f, 92.29734f },
    { 405.5344f, 1407.2664f,  92.29734f }
};

std::vector<Position> SoraringEagleCyclicPath4 =
{
    { 396.47882f, 1402.0371f, 91.81095f },
    { 397.27747f, 1401.4353f, 91.81095f },
    { 387.03668f, 1381.7903f, 89.69339f },
    { 370.12805f, 1370.0513f, 89.69339f },
    { 359.64487f, 1373.1759f, 89.69339f },
    { 350.18198f, 1386.6072f, 89.69339f },
    { 345.56348f, 1402.6711f, 89.69339f },
    { 355.46756f, 1424.0919f, 89.69339f },
    { 367.25217f, 1433.9203f, 89.69339f },
    { 373.7067f, 1438.8328f, 89.69339f },
    { 386.6186f, 1435.4559f, 89.69339f },
    { 405.42404f, 1418.889f, 89.69339f },
    { 410.99643f, 1390.823f, 89.69339f },
    { 397.09592f, 1382.1975f, 89.69339f },
    { 376.45215f, 1393.8619f, 89.69339f },
    { 356.00858f, 1404.278f, 89.69339f },
    { 344.35168f, 1416.3293f, 89.69339f },
    { 351.9594f, 1439.8646f, 89.69339f },
    { 353.33682f, 1441.8173f, 89.69339f },
    { 368.85004f, 1445.7336f, 89.69339f },
    { 381.1107f, 1440.9076f, 89.69339f },
    { 392.25012f, 1433.5304f, 89.69339f },
    { 388.21756f, 1408.2224f, 89.69339f },
    { 378.6734f, 1393.3729f, 89.69339f },
    { 368.74435f, 1377.1985f, 89.69339f },
    { 358.59244f, 1357.8248f, 89.69339f },
    { 352.95963f, 1373.3104f, 89.69339f },
    { 354.78592f, 1394.457f, 89.69339f },
    { 362.43695f, 1408.394f, 89.69339f },
    { 379.70877f, 1427.434f, 89.69339f },
    { 392.25433f, 1431.5131f, 89.69339f },
    { 402.16602f, 1427.8239f, 89.69339f },
    { 387.03668f, 1381.7903f, 89.69339f },
    { 370.12805f, 1370.0513f, 89.69339f }
};

std::vector<Position> SoraringEagleCyclicPath6 =
{
    { 389.7559f, 1429.5692f, 91.704124f },
    { 389.15408f, 1430.3678f, 91.704124f },
    { 364.2945f, 1429.2323f, 99.35547f },
    { 385.5457f, 1429.0762f, 97.52219f },
    { 403.14258f, 1412.2823f, 91.68882f },
    { 400.02182f, 1390.2379f, 91.68882f },
    { 376.41537f, 1384.655f, 94.605484f },
    { 359.02756f, 1371.6508f, 94.605484f },
    { 346.9107f, 1391.9337f, 94.605484f },
    { 341.37088f, 1418.3412f, 94.605484f },
    { 350.69977f, 1429.8486f, 94.605484f },
    { 370.01108f, 1435.0266f, 94.605484f },
    { 392.06976f, 1429.9241f, 94.605484f },
    { 386.54068f, 1408.4303f, 94.605484f },
    { 373.95096f, 1376.0957f, 94.605484f },
    { 357.72754f, 1363.8644f, 94.605484f },
    { 347.01358f, 1378.5763f, 94.605484f },
    { 347.7666f, 1389.9219f, 94.605484f },
    { 365.9999f, 1404.3414f, 94.605484f },
    { 383.0139f, 1413.7719f, 94.605484f },
    { 409.8304f, 1421.2222f, 94.605484f },
    { 401.74924f, 1445.9572f, 94.605484f },
    { 382.86514f, 1454.6213f, 94.605484f },
    { 365.86273f, 1452.1888f, 94.605484f },
    { 351.98242f, 1449.2568f, 94.605484f },
    { 334.17416f, 1440.2583f, 94.605484f },
    { 334.8176f, 1426.2494f, 94.605484f },
    { 345.3902f, 1406.333f, 94.605484f },
    { 362.73828f, 1394.9055f, 94.605484f },
    { 394.5153f, 1384.1464f, 94.605484f },
    { 419.7296f, 1377.4557f, 94.605484f },
    { 409.288f, 1407.1461f, 94.605484f },
    { 386.95444f, 1434.5723f, 94.605484f },
    { 349.70334f, 1440.1602f, 98.16106f },
    { 333.68912f, 1444.1354f, 100.02217f },
    { 312.27518f, 1440.3971f, 100.02216f },
    { 303.0779f, 1411.3394f, 97.49439f },
    { 321.6631f, 1412.2037f, 94.605484f },
    { 364.2945f, 1429.2323f, 99.35547f },
    { 385.5457f, 1429.0762f, 97.52219f }
};

std::unordered_map<uint8, std::vector<Position>> CyclicPathsByEagleNumber =
{
    { 0, SoraringEagleCyclicPath0 },
    { 2, SoraringEagleCyclicPath2 },
    { 4, SoraringEagleCyclicPath4 },
    { 6, SoraringEagleCyclicPath6 }
};

struct boss_akilzon : public BossAI
{
    boss_akilzon(Creature* creature) : BossAI(creature, DATA_ALKILZON) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 6s);
        events.ScheduleEvent(EVENT_CALL_LIGHTNING, 7s);
        events.ScheduleEvent(EVENT_GUST_OF_WIND, 9s + 500ms);
        events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 49s);
        events.ScheduleEvent(EVENT_START_RAIN, 41s);
        events.ScheduleEvent(EVENT_SUMMON_SOARING_EAGLES, 11s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->GetMap()->SetZoneWeather(ZONE_ID_ZULAMAN, WEATHER_STATE_FOG, 0.f);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->GetMap()->SetZoneWeather(ZONE_ID_ZULAMAN, WEATHER_STATE_FOG, 0.f);
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        summon->SetReactState(REACT_PASSIVE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STATIC_DISRUPTION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_STATIC_DISRUPTION);
                    events.Repeat(12s);
                    break;
                case EVENT_CALL_LIGHTNING:
                    DoCastVictim(SPELL_CALL_LIGHTNING);
                    events.Repeat(7s, 9s);
                    break;
                case EVENT_GUST_OF_WIND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* potentialTarget)->bool
                        {
                            return potentialTarget && me->GetVictim() != potentialTarget && !potentialTarget->HasAura(SPELL_PLUCKED);
                        }))
                        DoCast(target, SPELL_GUST_OF_WIND);
                    events.Repeat(24s);
                    break;
                case EVENT_ELECTRICAL_STORM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_ELECTRICAL_STORM);

                    events.RescheduleEvent(EVENT_STATIC_DISRUPTION, 14s + 500ms);
                    events.RescheduleEvent(EVENT_GUST_OF_WIND, 17s);
                    events.RescheduleEvent(EVENT_CALL_LIGHTNING, 18s);
                    events.ScheduleEvent(EVENT_END_RAIN, 8s);
                    events.ScheduleEvent(EVENT_START_RAIN, 41s);
                    events.ScheduleEvent(EVENT_SUMMON_SOARING_EAGLES, 19s);
                    events.Repeat(49s);
                    break;
                case EVENT_START_RAIN:
                    me->GetMap()->SetZoneWeather(ZONE_ID_ZULAMAN, WEATHER_STATE_MEDIUM_RAIN, 0.75f);
                    break;
                case EVENT_END_RAIN:
                    me->GetMap()->SetZoneWeather(ZONE_ID_ZULAMAN, WEATHER_STATE_FOG, 0.f);
                    break;
                case EVENT_SUMMON_SOARING_EAGLES:
                    Talk(SAY_SUMMON_EAGLES);
                    for (uint8 i = 0; i < 8; i++)
                    {
                        bool cyclic = i == 0 || i == 2 || i == 4 || i == 6;

                        if (Creature* eagle = DoSummon(NPC_SOARING_EAGLE, SoaringEagleSummonPositions[i], 4000))
                        {
                            if (cyclic)
                            {
                                eagle->GetMotionMaster()->MoveCyclicPath(CyclicPathsByEagleNumber[i].data(), CyclicPathsByEagleNumber[i].size(), false, true);
                                eagle->AI()->SetData(DATA_EAGLE_NUMBER, i);
                            }
                            else
                                eagle->AI()->DoAction(ACTION_DO_RANDOM_MOVEMENT);
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_akilzon_soaring_eagle : public PassiveAI
{
    npc_akilzon_soaring_eagle(Creature* creature) : PassiveAI(creature), _randomMovement(false), _eagleNumber(0) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_EAGLE_SCREECH, 3s, 6s);
        _events.ScheduleEvent(EVENT_EAGLE_SWOOP, 3s, 6s);
        DoZoneInCombat();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DO_RANDOM_MOVEMENT:
                _events.ScheduleEvent(EVENT_MOVE_RANDOM, 1ms);
                _randomMovement = true;
                break;
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case DATA_EAGLE_NUMBER:
                _eagleNumber = data;
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EAGLE_SCREECH:
                    me->PlayDirectSound(SOUND_ID_EAGLE_SCREECH);
                    _events.Repeat(3s + 500ms, 10s);
                    break;
                case EVENT_EAGLE_SWOOP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.f, true))
                        DoCast(target, SPELL_EAGLE_SWOOP);
                    _events.Repeat(5s, 6s);

                    if (_randomMovement)
                        _events.RescheduleEvent(EVENT_MOVE_RANDOM, 2s);
                    else
                        _events.ScheduleEvent(EVENT_MOVE_CYCLIC_PATH, 2s);
                    break;
                case EVENT_MOVE_RANDOM:
                {
                    Position pos = me->GetHomePosition();
                    pos.RelocateOffset({ frand(-7.f, 7.f), frand(-7.f, 7.f), frand(-1.f, 1.f) });
                    if (me->GetPositionZ() <= 90.f)
                        pos.m_positionZ = std::min(me->GetPositionZ() + 10.f, pos.GetPositionZ());

                    me->GetMotionMaster()->MovePoint(0, pos, false);
                    _events.Repeat(1s + 200ms);
                    break;
                }
                case EVENT_MOVE_CYCLIC_PATH:
                    me->GetMotionMaster()->MoveCyclicPath(CyclicPathsByEagleNumber[_eagleNumber].data(), CyclicPathsByEagleNumber[_eagleNumber].size(), false, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _randomMovement;
    uint8 _eagleNumber;
};

struct npc_akilzon_amani_kidnapper : public PassiveAI
{
    npc_akilzon_amani_kidnapper(Creature* creature) : PassiveAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* akilzon = instance->GetCreature(DATA_ALKILZON))
                akilzon->AI()->JustSummoned(me);
    }

    void JustAppeared() override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* summoner = summon->GetSummoner())
                me->GetMotionMaster()->MovePoint(POINT_GRAB_PASSENGER, summoner->GetPosition(), false);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(6s);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_GRAB_PASSENGER:
                if (TempSummon* summon = me->ToTempSummon())
                    if (Unit* summoner = summon->GetSummoner())
                        DoCast(summoner, SPELL_GRAB_PASSENGER);
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        me->GetMotionMaster()->MoveCyclicPath(AmaniKidnapperCyclicPath.data(), AmaniKidnapperCyclicPath.size(), false, true);
    }

    void UpdateAI(uint32 /*diff*/) override { }
};

class spell_akilzon_electrical_storm : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_TELEPORT_SELF,
                SPELL_ELECTRICAL_STORM_AREA_AURA
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetDisableGravity(true);
        target->SendSetPlayHoverAnim(true);
        target->SetControlled(true, UNIT_STATE_ROOT);
        target->CastSpell(target, SPELL_ELECTRICAL_STORM_AREA_AURA, true);
        target->CastSpell(target, SPELL_TELEPORT_SELF, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetDisableGravity(false);
        target->SetControlled(false, UNIT_STATE_ROOT);
        target->RemoveAurasDueToSpell(SPELL_ELECTRICAL_STORM_AREA_AURA);
        target->SendSetPlayHoverAnim(false);
        target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_2].BasePoints);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_akilzon_electrical_storm::AfterApply, EFFECT_0, SPELL_AURA_BLOCK_SPELL_FAMILY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_akilzon_electrical_storm::AfterRemove, EFFECT_0, SPELL_AURA_BLOCK_SPELL_FAMILY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_akilzon_electrical_storm_damage : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* target)->bool
        {
            return (!target->ToUnit() || target->ToUnit()->HasAura(SPELL_ELECTRICAL_STORM_AREA_AURA));
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_akilzon_electrical_storm_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnObjectAreaTargetSelect.Register(&spell_akilzon_electrical_storm_damage::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

class spell_akilzon_electrical_overloard_graphic_pulse : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ELECTRICAL_ARC_1,
                SPELL_ELECTRICAL_ARC_2,
                SPELL_ELECTRICAL_ARC_3,
                SPELL_ELECTRICAL_ARC_4,
                SPELL_ELECTRICAL_ARC_5
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        for (uint8 i = 0; i < 5; i++)
            GetHitUnit()->CastSpell(GetHitUnit(), electricalArcSpells[i], true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_akilzon_electrical_overloard_graphic_pulse::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_akilzon_teleport_self : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 10.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_akilzon_teleport_self::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_akilzon_grab_passenger : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_akilzon_grab_passenger::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_akilzon_summon_amani_kidnapper : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 30.0f, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_akilzon_summon_amani_kidnapper::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

void AddSC_boss_akilzon()
{
    RegisterZulAamanCreatureAI(boss_akilzon);
    RegisterZulAamanCreatureAI(npc_akilzon_soaring_eagle);
    RegisterZulAamanCreatureAI(npc_akilzon_amani_kidnapper);
    RegisterSpellScript(spell_akilzon_electrical_storm);
    RegisterSpellScript(spell_akilzon_electrical_storm_damage);
    RegisterSpellScript(spell_akilzon_electrical_overloard_graphic_pulse);
    RegisterSpellScript(spell_akilzon_teleport_self);
    RegisterSpellScript(spell_akilzon_grab_passenger);
    RegisterSpellScript(spell_akilzon_summon_amani_kidnapper);
}
