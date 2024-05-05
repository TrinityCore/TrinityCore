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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "the_black_morass.h"
#include "GameObject.h"

enum MedivhBm
{
    SAY_ENTER                            = 0,
    SAY_WEAK75                           = 2,
    SAY_WEAK50                           = 3,
    SAY_WEAK25                           = 4,
    SAY_DEATH                            = 5,
    SAY_WIN                              = 6,
    SAY_ORCS_ENTER                       = 7,
    SAY_ORCS_ANSWER                      = 0,

    SPELL_CHANNEL                        = 31556,
    SPELL_PORTAL_RUNE                    = 32570,    // aura(portal on ground effect)

    SPELL_BLACK_CRYSTAL                  = 32563,    // aura
    SPELL_PORTAL_CRYSTAL                 = 32564,    // summon

    SPELL_BANISH_PURPLE                  = 32566,    // aura
    SPELL_BANISH_GREEN                   = 32567,    // aura

    SPELL_CORRUPT                        = 31326,
    SPELL_CORRUPT_AEONUS                 = 37853,

    // NYI
    SPELL_SUMMON_INFINITE_WHELP          = 37606,
    SPELL_SUMMON_INFINITE_ASSASSIN       = 31318,
    SPELL_SUMMON_INFINITE_ASSASSIN_2     = 36229,
    SPELL_SUMMON_INFINITE_CHRONOMANCER   = 31421,
    SPELL_SUMMON_INFINITE_CHRONOMANCER_2 = 36231,
    SPELL_SUMMON_INFINITE_EXECUTIONER    = 33363,
    SPELL_SUMMON_INFINITE_EXECUTIONER_2  = 36232,
    SPELL_SUMMON_INFINITE_VANQUISHER     = 33364,
    SPELL_SUMMON_INFINITE_VANQUISHER_2   = 36233,

    SPELL_SUMMON_RIFT_LORD               = 31321,
    SPELL_SUMMON_RIFT_LORD_2             = 36234,
    SPELL_SUMMON_RIFT_KEEPER             = 36235,
    SPELL_SUMMON_RIFT_KEEPER_2           = 36236,

    SPELL_SUMMON_CHRONO_LORD_DEJA        = 31391,
    SPELL_SUMMON_TEMPORUS                = 31392,
    SPELL_SUMMON_AEONUS                  = 31393,
    SPELL_SUMMON_INFINITE_CHRONO_LORD    = 37177,
    SPELL_SUMMON_INFINITE_TIMEREAVER     = 37178,

    SPELL_SUMMON_TIME_RIFT_PERIODIC_90   = 31353,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_120  = 31632,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_45   = 31636,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_75   = 31637,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_30   = 34188,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_5    = 35143,
    SPELL_SUMMON_TIME_RIFT_EFFECT_1      = 31354,
    SPELL_SUMMON_TIME_RIFT_EFFECT_2      = 31355,
    SPELL_SUMMON_TIME_RIFT_EFFECT_3      = 31356,
    SPELL_SUMMON_TIME_RIFT_EFFECT_4      = 31357,
    SPELL_SUMMON_TIME_RIFT               = 39041,
    SPELL_TIME_RIFT_1_READY              = 39570,
    SPELL_TIME_RIFT_2_READY              = 39571,
    SPELL_TIME_RIFT_3_READY              = 39572,
    SPELL_TIME_RIFT_4_READY              = 39573,
    SPELL_CLOSE_TIME_RIFT_TRIGGER        = 31322,
    SPELL_CLOSE_TIME_RIFT_EFFECT         = 31323,
    SPELL_TIME_RIFT_READY_PRIMER         = 31352,
    SPELL_TIME_RIFT_CHANNEL              = 31387,
    SPELL_TIME_RIFT_CHANNEL_TRIGGER      = 31388,
    SPELL_TIME_RIFT_PERIODIC             = 31320,

    SPELL_MEDIVH_LIVES                   = 31395,
    SPELL_MEDIVH_DIES                    = 31327,
    SPELL_MEDIVH_SHIELD                  = 32613,

    SPELL_THE_BLACK_MORASS_COMPLETE      = 37215,

    C_COUNCIL_ENFORCER                   = 17023
};

#define PORTAL_ORIENTATION 6.1515f

static const Position OrcSpawnPos[6] =
{
    {-2089.731f, 7118.083f, 34.589f, 6.19f},
    {-2089.331f, 7121.083f, 34.589f, 6.19f},
    {-2088.931f, 7124.083f, 34.589f, 6.19f},
    {-2088.531f, 7127.083f, 34.589f, 6.19f},
    {-2088.131f, 7130.083f, 34.589f, 6.19f},
    {-2087.731f, 7133.083f, 34.589f, 6.19f}
};

static const Position OrcSquadPos[4] =
{
    {-2042.571f, 7113.892f, 0.f, 0.f},
    {-2054.446f, 7115.418f, 0.f, 0.f},
    {-2067.175f, 7116.800f, 0.f, 0.f},
    {-2083.669f, 7118.932f, 0.f, 0.f}
};

static const Position DarkPortalPos = { -2085.570f, 7125.6215f, 29.444f, 6.148f };

class HomeMovementEvent : public BasicEvent
{
public:
    explicit HomeMovementEvent(Unit* owner) : _owner(owner) { }

    bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
    {
        _owner->GetMotionMaster()->MoveTargetedHome();
        return true;
    }

private:
    Unit* _owner;
};

class YellEvent : public BasicEvent
{
public:
    explicit YellEvent(Creature* owner) : _owner(owner) { }

    bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
    {
        _owner->SetFacingTo(3.05f);
        _owner->AI()->Talk(SAY_ORCS_ANSWER);
        return true;
    }

private:
    Creature* _owner;
};

class MarchMovementEvent : public BasicEvent
{
public:
    explicit MarchMovementEvent(Creature* owner, uint8 orcSquadNumber, uint8 orcNumber) : _owner(owner), _orcSquadNumber(orcSquadNumber), _orcNumber(orcNumber) { }

    bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
    {
        float x = OrcSquadPos[_orcSquadNumber].GetPositionX();
        if (!_orcSquadNumber && _orcNumber == 2)
        {
            _owner->m_Events.AddEvent(new YellEvent(_owner), _owner->m_Events.CalculateTime(33s));
            x += 2;
        }
        float y = (OrcSquadPos[_orcSquadNumber].GetPositionY() + _orcNumber * 3);
        float z = _owner->GetMapHeight(x, y, _owner->GetPositionZ());
        _owner->GetMotionMaster()->MovePoint(0, x, y, z);
        _owner->SetVisible(true);
        _owner->m_Events.AddEvent(new HomeMovementEvent(_owner), _owner->m_Events.CalculateTime(Seconds(urand(44, 47))));
        _owner->DespawnOrUnsummon(Seconds(urand(51, 55)));
        return true;
    }

private:
    Creature* _owner;
    uint8 _orcSquadNumber;
    uint8 _orcNumber;
};

enum MedivhEvents
{
    EVENT_SPELL_CORRUPT = 1,
    EVENT_CHECK,
    EVENT_ORCS_MARSH,
};

struct npc_medivh_bm : public ScriptedAI
{
    npc_medivh_bm(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        orcSquadNumber = 0;
        Life75 = true;
        Life50 = true;
        Life25 = true;
    }

    InstanceScript* instance;
    EventMap Events;
    uint8 orcSquadNumber;

    bool Life75;
    bool Life50;
    bool Life25;

    void StartPostEvent()
    {
        QuaternionData rot = QuaternionData::fromEulerAnglesZYX(PORTAL_ORIENTATION, 0.f, 0.f);
        me->SummonGameObject(GO_DARK_PORTAL, DarkPortalPos, rot, 0s, GOSummonType(GO_SUMMON_TIMED_OR_CORPSE_DESPAWN))->GetGUID();
        for (uint8 i = 0; i < 4; ++i)
            for (uint8 j = 0; j < 6; ++j)
                if (Creature* creature = me->SummonCreature(NPC_SHADOW_COUNCIL_ENFORCER, OrcSpawnPos[j]))
                {
                    creature->m_Events.AddEvent(new MarchMovementEvent(creature, i, j), Seconds(30 + i));
                    creature->SetVisible(false);
                }
        Events.ScheduleEvent(EVENT_ORCS_MARSH, 47s);
    }

    void Reset() override
    {
        Initialize();

        if (instance->GetData(TYPE_MEDIVH) == IN_PROGRESS)
            DoCast(me, SPELL_CHANNEL, true);
        else if (me->HasAura(SPELL_CHANNEL))
            me->RemoveAura(SPELL_CHANNEL);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f))
        {
            if (instance->GetData(TYPE_MEDIVH) == IN_PROGRESS || instance->GetData(TYPE_MEDIVH) == DONE)
                return;

            Talk(SAY_ENTER);
            instance->SetData(TYPE_MEDIVH, IN_PROGRESS);
            DoCast(me, SPELL_CHANNEL, false);
            Events.ScheduleEvent(EVENT_CHECK, 5s);
        }
        else if (who->GetTypeId() == TYPEID_UNIT && me->IsWithinDistInMap(who, 15.0f))
        {
            if (instance->GetData(TYPE_MEDIVH) != IN_PROGRESS)
                return;

            uint32 entry = who->GetEntry();
            if (entry == NPC_INFINITE_ASSASIN || entry == NPC_INFINITE_WHELP || entry == NPC_INFINITE_CRONOMANCER || entry == NPC_INFINITE_EXECUTIONER || entry == NPC_INFINITE_VANQUISHER)
            {
                who->StopMoving();
                who->CastSpell(me, SPELL_CORRUPT, false);
            }
            else if (entry == NPC_AEONUS)
            {
                who->StopMoving();
                who->CastSpell(me, SPELL_CORRUPT_AEONUS, false);
            }
        }
    }

    void AttackStart(Unit* /*who*/) override
    {
        //if (instance->GetData(TYPE_MEDIVH) == IN_PROGRESS)
        //    return;

        //ScriptedAI::AttackStart(who);
    }

    void JustEngagedWith(Unit* /*who*/) override { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (Events.HasEventScheduled(EVENT_SPELL_CORRUPT))
            return;

        if (spellInfo->Id == SPELL_CORRUPT_AEONUS)
            Events.ScheduleEvent(EVENT_SPELL_CORRUPT, 1s);

        if (spellInfo->Id == SPELL_CORRUPT)
            Events.ScheduleEvent(EVENT_SPELL_CORRUPT, 3s);
    }

    void JustDied(Unit* killer) override
    {
        if (killer && killer->GetEntry() == me->GetEntry())
            return;

        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        Events.Update(diff);

        switch (Events.ExecuteEvent())
        {
        case EVENT_SPELL_CORRUPT:
            instance->SetData(TYPE_MEDIVH, SPECIAL);
            if (me->HasAura(SPELL_CORRUPT_AEONUS))
                Events.ScheduleEvent(EVENT_SPELL_CORRUPT, 1s);
            else if (me->HasAura(SPELL_CORRUPT))
                Events.ScheduleEvent(EVENT_SPELL_CORRUPT, 3s);
            break;
        case EVENT_CHECK:
        {
            uint32 pct = instance->GetData(DATA_SHIELD);

            Events.ScheduleEvent(EVENT_CHECK, 5s);

            if (Life25 && pct <= 25)
            {
                Talk(SAY_WEAK25);
                Life25 = false;
            }
            else if (Life50 && pct <= 50)
            {
                Talk(SAY_WEAK50);
                Life50 = false;
            }
            else if (Life75 && pct <= 75)
            {
                Talk(SAY_WEAK75);
                Life75 = false;
            }

            //if we reach this it means event was running but at some point reset.
            if (instance->GetData(TYPE_MEDIVH) == NOT_STARTED)
            {
                me->DespawnOrUnsummon();
                me->Respawn();
                return;
            }

            if (instance->GetData(TYPE_RIFT) == DONE)
            {
                Talk(SAY_WIN);
                Events.CancelEvent(EVENT_CHECK);

                if (me->HasAura(SPELL_CHANNEL))
                    me->RemoveAura(SPELL_CHANNEL);

                instance->SetData(TYPE_MEDIVH, DONE);
                StartPostEvent();
            }
        }
            break;
        case EVENT_ORCS_MARSH:
            Talk(SAY_ORCS_ENTER);
            break;
        default:
            break;
        }

        //if (!UpdateVictim())
        //return;

        //DoMeleeAttackIfReady();
    }
};

struct Wave
{
    uint32 PortalMob[4];                                    //spawns for portal waves (in order)
};

static Wave PortalWaves[]=
{
    { {NPC_INFINITE_ASSASIN, NPC_INFINITE_WHELP, NPC_INFINITE_CRONOMANCER, 0} },
    { {NPC_INFINITE_EXECUTIONER, NPC_INFINITE_CRONOMANCER, NPC_INFINITE_WHELP, NPC_INFINITE_ASSASIN} },
    { {NPC_INFINITE_EXECUTIONER, NPC_INFINITE_VANQUISHER, NPC_INFINITE_CRONOMANCER, NPC_INFINITE_ASSASIN} }
};

enum TimeRiftEvents
{
    EVENT_TIME_RIFT_WAVE = 1
};

struct npc_time_rift : public ScriptedAI
{
    npc_time_rift(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        Events.ScheduleEvent(EVENT_TIME_RIFT_WAVE, 15s);
        mRiftWaveCount = 0;
        mWaveId = 0;
    }

    InstanceScript* instance;

    EventMap Events;
    uint8 mRiftWaveCount;
    uint8 mWaveId;

    void Reset() override
    {
        Initialize();

        uint8 mPortalCount = instance->GetData(DATA_PORTAL_COUNT);

        if (mPortalCount < 6)
            mWaveId = 0;
        else if (mPortalCount > 12)
            mWaveId = 2;
        else mWaveId = 1;

    }
    void JustEngagedWith(Unit* /*who*/) override { }

    void DoSummonAtRift(uint32 creature_entry)
    {
        if (!creature_entry)
            return;

        if (instance->GetData(TYPE_MEDIVH) != IN_PROGRESS)
        {
            me->InterruptNonMeleeSpells(true);
            me->RemoveAllAuras();
            return;
        }

        Position pos = me->GetRandomNearPosition(10.0f);

        //normalize Z-level if we can, if rift is not at ground level.
        pos.m_positionZ = std::max(me->GetMap()->GetHeight(pos.m_positionX, pos.m_positionY, MAX_HEIGHT), me->GetMap()->GetWaterLevel(pos.m_positionX, pos.m_positionY));

        if (Unit* Summon = DoSummon(creature_entry, pos, 30s, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT))
            if (Unit* temp = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_MEDIVH)))
                AddThreat(temp, 0.0f, Summon);
    }

    void DoSelectSummon()
    {
        if ((mRiftWaveCount > 2 && mWaveId < 1) || mRiftWaveCount > 3)
            mRiftWaveCount = 0;

        uint32 entry = 0;

        entry = PortalWaves[mWaveId].PortalMob[mRiftWaveCount];
        TC_LOG_DEBUG("scripts", "npc_time_rift: summoning wave Creature (Wave {}, Entry {}).", mRiftWaveCount, entry);

        ++mRiftWaveCount;

        if (entry == NPC_INFINITE_WHELP)
        {
            for (uint8 i = 0; i < 3; ++i)
                DoSummonAtRift(entry);
        } else DoSummonAtRift(entry);
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance->GetData(DATA_PORTAL_COUNT) == 18)
            return;

        Events.Update(diff);

        switch (Events.ExecuteEvent())
        {
        case EVENT_TIME_RIFT_WAVE:
            DoSelectSummon();
            Events.Repeat(15s);
            break;
        default:
            break;
        }

        if (me->IsNonMeleeSpellCast(false))
            return;

        TC_LOG_DEBUG("scripts", "npc_time_rift: not casting anylonger, i need to die.");
        me->setDeathState(JUST_DIED);

        if (instance->GetData(TYPE_RIFT) == IN_PROGRESS)
            instance->SetData(TYPE_RIFT, SPECIAL);
    }
};

void AddSC_the_black_morass()
{
    RegisterBlackMorassCreatureAI(npc_medivh_bm);
    RegisterBlackMorassCreatureAI(npc_time_rift);
}
