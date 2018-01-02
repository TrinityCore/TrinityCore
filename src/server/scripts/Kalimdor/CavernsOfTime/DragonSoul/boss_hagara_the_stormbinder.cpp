/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/* ScriptData
SDName: boss_hagara_the_stormbinder
Author: Bennu
SD%Complete: 90%
SDComment: TODO Heroic Mode
SDCategory: Boss Hagara
EndScriptData
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "dragon_soul.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum Events
{
    // Main Phase
    EVENT_ICE_LANCE = 1,
    EVENT_LANCE_HIT,
    EVENT_ICE_TOMB,
    EVENT_SHATTERED_ICE,
    EVENT_FOCUSED_ASSAULT,
    EVENT_FEEDBACK,
    EVENT_BERSERK,

    // Ice Phase
    EVENT_ICE_WAVES,
    EVENT_RADIATE,
    EVENT_CIRCLING,
    EVENT_EDGE,
    EVENT_ICICLE,
    EVENT_FROSTFLAKE,
    HAS_ICE_TETHER,

    // Lightning Phase
    EVENT_ELEMENTAL,
    EVENT_SUMMON_CRYSTAL,
    EVENT_STORM_PILLAR,
    HAS_CONDUIT_TETHER,

    // Icicle
    EVENT_FALL,
    EVENT_DAMAGE,

    // Lightning Conduit
    EVENT_CAST_CRYSTAL,

    // Phases
    EVENT_FIRST_MAIN_PHASE,
    EVENT_SECOND_MAIN_PHASE,
    EVENT_ICE_PHASE,
    EVENT_LIGHTNING_PHASE,
};

enum Spells
{
    SPELL_BERSERK                  = 64238,
    SPELL_FEEDBACK                 = 108934,
    SPELL_FOCUSED_ASSAULT          = 107851,
    SPELL_FROZEN_TEMPEST           = 105256,
    SPELL_ICE_TOMB_DUMMY           = 104448,
    SPELL_ICE_TOMB                 = 104451,
    SPELL_SHATTERED_ICE            = 105289,
    SPELL_WATER_SHIELD             = 105409,
    SPELL_WATERY_ENTRENCHMENT      = 110317,

    SPELL_LIGHTNING_CONDUIT        = 105369,
    SPELL_LIGHTNING_CONDUIT_VISUAL = 105367,
    SPELL_LIGHTNING_CONDUIT_DUMMY  = 105377,
    SPELL_LIGHTNING_STORM          = 105465,
    SPELL_LIGHTNING_ROD            = 109180,
    SPELL_LIGHTNING_ROD_LIGHT      = 105343,
    SPELL_STORM_PILLAR             = 109557,

    SPELL_LANCE_TARGET             = 105285,
    SPELL_ICE_LANCE_SUMMON         = 105297,
    SPELL_ICE_LANCE_VISUAL         = 105269,
    SPELL_ICE_LANCE                = 105313,

    SPELL_ICE_WAVE                 = 105265,
    SPELL_ICICLE                   = 109315,
    SPELL_OVERLOAD                 = 105487,
    SPELL_ICICLE_SHARD             = 92201,
    SPELL_ICICLE_FALLING           = 92202,
    SPELL_FROSTFLAKE               = 109325,

    SPELL_CRYSTAL_CONDUCTOR        = 105482,
    SPELL_CRYSTALLINE_TETHER       = 105311,
    SPELL_CRYSTALLINE_OVERLOAD     = 105312,
};

enum ScriptedTexts
{
    SAY_INTRO = 0,
    SAY_AGGRO = 1,
    SAY_LANCE = 2,
    SAY_TOMB  = 3,
    SAY_WAVE  = 4,
    SAY_LIGHT = 5,
    SAY_FEED  = 6,
    SAY_KILL  = 7,
    SAY_DEATH = 8,
};

Position const centerpos =  { 13587.0f, 13612.0f, 122.42f, 0.0f };

Position const ElementalPosition = { 13625.0f, 13612.0f, 123.483f, 0.0f };

const Position LancePosition[] =
{
    { 13627.711914f, 13580.286133f, 124.480316f, 2.474090f },
    { 13553.189453f, 13652.718750f, 124.480225f, 5.403617f },
    { 13536.749023f, 13603.763672f, 124.479698f, 0.172847f },
};

const Position WavePosition[] =
{
    { 13618.0f, 13612.0f, 123.483f, 0.0f },
    { 13625.0f, 13612.0f, 123.483f, 0.0f },
    { 13632.0f, 13612.0f, 124.480f, 0.0f },
    { 13639.0f, 13612.0f, 124.480f, 0.0f },
    { 13587.0f, 13643.0f, 123.483f, 3.14f },
    { 13587.0f, 13650.0f, 123.483f, 3.14f },
    { 13587.0f, 13657.0f, 123.483f, 3.14f },
    { 13587.0f, 13664.0f, 123.479f, 3.14f },
    { 13556.0f, 13612.0f, 123.484f, 4.71f },
    { 13549.0f, 13612.0f, 123.484f, 4.71f },
    { 13542.0f, 13612.0f, 123.484f, 4.71f },
    { 13535.0f, 13612.0f, 124.480f, 4.71f },
    { 13587.0f, 13581.0f, 123.483f, 6.28f },
    { 13587.0f, 13574.0f, 123.483f, 6.28f },
    { 13587.0f, 13567.0f, 124.483f, 6.28f },
    { 13587.0f, 13560.0f, 124.480f, 6.28f },
};

const Position IciclePosition[] =
{
    { 13570.661f, 13582.291f, 123.483f, 0.0f},
    { 13570.661f, 13582.291f, 123.483f, 0.0f},
    { 13541.572f, 13611.474f, 123.482f, 0.0f},
    { 13617.093f, 13595.264f, 123.482f, 0.0f},
    { 13580.350f, 13565.208f, 123.900f, 0.0f},
    { 13599.159f, 13565.880f, 123.975f, 0.0f},
    { 13599.159f, 13565.880f, 123.975f, 0.0f},
    { 13577.062f, 13657.772f, 123.566f, 0.0f},
    { 13568.254f, 13633.398f, 122.422f, 0.0f},
    { 13584.448f, 13648.763f, 123.484f, 0.0f},
};

const Position CrystalPosition[] =
{
    { 13617.5f, 13580.9f, 123.567f, 0.0f },
    { 13557.4f, 13643.1f, 123.567f, 0.0f },
    { 13557.7f, 13580.7f, 123.567f, 0.0f },
    { 13617.3f, 13643.5f, 123.567f, 0.0f },
};

const Position ConductorPosition[] =
{
    { 13608.559f, 13589.850f, 123.414268f, 0.0f },
    { 13566.439f, 13589.971f, 123.413284f, 0.0f },
    { 13566.475f, 13634.254f, 123.468864f, 0.0f },
    { 13608.578f, 13633.906f, 123.326485f, 0.0f },
    { 13542.100f, 13611.900f, 123.483000f, 0.0f },
    { 13587.400f, 13657.800f, 123.483000f, 0.0f },
    { 13632.900f, 13612.100f, 123.484000f, 0.0f },
    { 13587.800f, 13566.400f, 123.483000f, 0.0f },
};

class boss_hagara_the_stormbinder : public CreatureScript
{
public:
    boss_hagara_the_stormbinder() : CreatureScript("boss_hagara") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_hagara_the_stormbinderAI(creature);
    }

    struct boss_hagara_the_stormbinderAI: public BossAI
    {
        boss_hagara_the_stormbinderAI(Creature* creature) : BossAI(creature, DATA_HAGARA)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        float ori;
        float distance;
        bool initphase;
        bool icephase;

        void InitializeAI() override
        {
            if (GameObject* iris = me->FindNearestGameObject(210132, 100.0f))
                iris->RemoveFromWorld();

            if (Creature* portal = me->FindNearestCreature(57809, 200.0f))
                portal->DespawnOrUnsummon();

            Talk(SAY_INTRO);
        }

        void Reset() override
        {
            me->ClearUnitState(UNIT_STATE_ROOT);

            events.Reset();
            summons.DespawnAll();
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            events.ScheduleEvent(EVENT_FIRST_MAIN_PHASE, 150);
            events.ScheduleEvent(EVENT_BERSERK, 480000);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim && victim->GetTypeId() == TYPEID_PLAYER)
            {
                Talk(SAY_KILL);
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                // Main Phase
                case EVENT_FIRST_MAIN_PHASE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_NPC);
                    summons.DespawnAll();

                    events.ScheduleEvent(EVENT_FOCUSED_ASSAULT, 15000);
                    events.ScheduleEvent(EVENT_ICE_LANCE, 5000);
                    events.ScheduleEvent(EVENT_SHATTERED_ICE, 21000);

                    switch (urand(0, 1))
                    {
                    case 0:
                        events.ScheduleEvent(EVENT_ICE_PHASE, 30000);
                        break;
                    case 1:
                        events.ScheduleEvent(EVENT_LIGHTNING_PHASE, 30000);
                        break;
                    }
                    break;

                case EVENT_SECOND_MAIN_PHASE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_NPC);
                    summons.DespawnAll();

                    events.ScheduleEvent(EVENT_FOCUSED_ASSAULT, 15000);
                    events.ScheduleEvent(EVENT_ICE_LANCE, 5000);
                    events.ScheduleEvent(EVENT_SHATTERED_ICE, 21000);
                    events.ScheduleEvent(EVENT_ICE_TOMB, 23000);

                    if (icephase == true)
                        events.ScheduleEvent(EVENT_LIGHTNING_PHASE, 50000);
                    else
                        events.ScheduleEvent(EVENT_ICE_PHASE, 50000);
                    break;

                case EVENT_ICE_TOMB:
                    Talk(SAY_TOMB);
                    DoCast(me, SPELL_ICE_TOMB_DUMMY);
                    break;

                case EVENT_FOCUSED_ASSAULT:
                    me->StopMoving();
                    DoCastVictim(SPELL_FOCUSED_ASSAULT);

                    events.ScheduleEvent(EVENT_FOCUSED_ASSAULT, 15000);
                    break;

                case EVENT_ICE_LANCE:
                    Talk(SAY_LANCE);
                    for (uint32 x =0; x< 3; ++x)
                        me->CastSpell(LancePosition[x].GetPositionX(),LancePosition[x].GetPositionY(), LancePosition[x].GetPositionZ(), SPELL_ICE_LANCE_SUMMON, false);

                    events.ScheduleEvent(EVENT_ICE_LANCE, 30000);
                    break;

                case EVENT_SHATTERED_ICE:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_SHATTERED_ICE);

                    events.ScheduleEvent(EVENT_SHATTERED_ICE, 16000);
                    break;

                case EVENT_FEEDBACK:
                    Talk(SAY_FEED);

                    me->ClearUnitState(UNIT_STATE_ROOT);
                    summons.DespawnAll();
                    DoCast(me, SPELL_FEEDBACK);
                    instance->DoRemoveAurasDueToSpellOnPlayers(RAID_MODE(105369,108569,109201,109202));
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIGHTNING_CONDUIT_VISUAL);

                    events.ScheduleEvent(EVENT_SECOND_MAIN_PHASE, 15000);
                    break;

                //Ice Phase
                case EVENT_ICE_PHASE:
                    icephase = true;
                    me->AddUnitState(UNIT_STATE_ROOT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_NPC);
                    me->NearTeleportTo(centerpos.GetPositionX(), centerpos.GetPositionY(), centerpos.GetPositionZ(), 0);
                    DoCast(me, SPELL_FROZEN_TEMPEST);

                    for (uint32 j= 0; j< 4; ++j)
                        me->SummonCreature(NPC_FORZEN_BINDIG_CRYSTAL, CrystalPosition[j], TEMPSUMMON_MANUAL_DESPAWN);

                    events.CancelEvent(EVENT_SHATTERED_ICE);
                    events.CancelEvent(EVENT_FOCUSED_ASSAULT);
                    events.CancelEvent(EVENT_ICE_LANCE);
                    events.ScheduleEvent(HAS_ICE_TETHER, 15000);
                    events.ScheduleEvent(EVENT_ICE_WAVES, 10000);
                    events.ScheduleEvent(EVENT_ICICLE, 15000);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_FROSTFLAKE, 6000);
                    break;

                case HAS_ICE_TETHER:
                    if(me->HasAura(SPELL_CRYSTALLINE_TETHER))
                        events.ScheduleEvent(HAS_ICE_TETHER, 1000);
                    else
                    {
                        events.CancelEvent(EVENT_ICE_WAVES);
                        events.CancelEvent(EVENT_ICICLE);
                        events.CancelEvent(HAS_ICE_TETHER);
                        events.CancelEvent(EVENT_FROSTFLAKE);
                        events.ScheduleEvent(EVENT_FEEDBACK, 100);
                        me->RemoveAurasDueToSpell(RAID_MODE(105256, 109552, 109553, 109554));
                    }
                    break;

                case EVENT_ICE_WAVES:
                    Talk(SAY_WAVE);
                    for (uint32 x= 0; x< 16; ++x)
                        if (Creature* wave = me->SummonCreature(NPC_ICE_WAVE, centerpos.GetPositionX(), centerpos.GetPositionY(), centerpos.GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
                            wave->GetMotionMaster()->MovePoint(0, WavePosition[x]);
                    break;

                case EVENT_ICICLE:
                    for (uint32 x= 0; x< 10; ++x)
                        me->SummonCreature(NPC_ICICLE, IciclePosition[x], TEMPSUMMON_TIMED_DESPAWN, 10000);

                    events.ScheduleEvent(EVENT_ICICLE, urand(15000,20000));
                    break;

                case EVENT_FROSTFLAKE:
                    if (Creature* fflake= me->SummonCreature(NPC_FROSTFLAKE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 30000))
                        fflake->CastSpell(fflake, SPELL_FROSTFLAKE);

                    events.ScheduleEvent(EVENT_FROSTFLAKE, 6000);
                    break;

                //Lightning Phase
                case EVENT_LIGHTNING_PHASE:
                    icephase = false;
                    Talk(SAY_LIGHT);
                    me->SetReactState(REACT_PASSIVE);
                    me->NearTeleportTo(centerpos.GetPositionX(), centerpos.GetPositionY(), centerpos.GetPositionZ(), 0);
                    DoCast(SPELL_WATER_SHIELD);

                    events.CancelEvent(EVENT_ICE_LANCE);
                    events.CancelEvent(EVENT_SHATTERED_ICE);
                    events.CancelEvent(EVENT_FOCUSED_ASSAULT);
                    events.ScheduleEvent(EVENT_ELEMENTAL, 10000);
                    events.ScheduleEvent(HAS_CONDUIT_TETHER, 15000);
                    events.ScheduleEvent(EVENT_SUMMON_CRYSTAL, 4000);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_STORM_PILLAR, 5000);
                    break;

                case HAS_CONDUIT_TETHER:
                    if(me->HasAura(SPELL_CRYSTAL_CONDUCTOR))
                    {
                        events.ScheduleEvent(HAS_CONDUIT_TETHER, 1000);
                    }
                    else
                    {
                        me->RemoveAurasDueToSpell(RAID_MODE(105409,109560,109561,109562));

                        events.CancelEvent(EVENT_ELEMENTAL);
                        events.CancelEvent(HAS_CONDUIT_TETHER);
                        events.CancelEvent(EVENT_STORM_PILLAR);
                        events.ScheduleEvent(EVENT_FEEDBACK, 100);
                    }
                    break;

                case EVENT_ELEMENTAL:
                    me->SummonCreature(NPC_BOUND_LIGHTNING_ELEMENTAL, ElementalPosition, TEMPSUMMON_CORPSE_DESPAWN, 5000);

                    events.ScheduleEvent(EVENT_ELEMENTAL, urand(60000,90000));
                    break;

                case EVENT_SUMMON_CRYSTAL:
                {
                    uint32 crystals = 4;

                    if (IsHeroic())
                        crystals = 8;

                    for (uint32 j = 0; j < crystals; ++j)
                        me->SummonCreature(NPC_CRYSTAL_CONDUCTOR, ConductorPosition[j], TEMPSUMMON_CORPSE_DESPAWN, 310000);
                }
                    break;

                case EVENT_STORM_PILLAR:
                    if (Creature* pillar = me->SummonCreature(NPC_STORM_PILLAR, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 4000))
                        pillar->CastSpell(pillar, SPELL_STORM_PILLAR, true);

                    events.ScheduleEvent(EVENT_STORM_PILLAR, 5000);
                    break;

                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) <= 22.0f)
            {
                if (me->HasAura(RAID_MODE(105256, 109552, 109553, 109554)))
                    if (who->GetEntry() != NPC_ICE_WAVE)
                        who->CastSpell(who, SPELL_WATERY_ENTRENCHMENT);
            }
            else
                who->RemoveAura(SPELL_WATERY_ENTRENCHMENT);

            BossAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            instance->SetBossState(DATA_HAGARA, DONE);
            _JustDied();
        }
    };
};

class npc_ds_ice_tomb : public CreatureScript
{
public:
    npc_ds_ice_tomb() : CreatureScript("npc_ds_ice_tomb") { }

    struct npc_ds_ice_tombAI : public ScriptedAI
    {
        npc_ds_ice_tombAI(Creature* creature) : ScriptedAI(creature) {}

        void InitializeAI() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->SetReactState(REACT_PASSIVE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ds_ice_tombAI(creature);
    }
};

class npc_frozen_binding_crystal : public CreatureScript
{
public:
    npc_frozen_binding_crystal() : CreatureScript("npc_frozen_binding_crystal") { }

    struct npc_frozen_binding_crystalAI : public ScriptedAI
    {
        npc_frozen_binding_crystalAI(Creature* creature) : ScriptedAI(creature) {}

            void InitializeAI() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                if (Creature* hagara = me->FindNearestCreature(NPC_HAGARA, 100.0f, true))
                    DoCast(hagara, SPELL_CRYSTALLINE_TETHER);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* hagara = me->FindNearestCreature(NPC_HAGARA, 100.0f, true))
                    hagara->RemoveAura(SPELL_CRYSTALLINE_TETHER);
            }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_frozen_binding_crystalAI(creature);
    }
};

class npc_bound_lightning_elemental : public CreatureScript
{
public:
    npc_bound_lightning_elemental() : CreatureScript("npc_bound_lightning_elemental") { }

    struct npc_bound_lightning_elementalAI : public ScriptedAI
    {
        npc_bound_lightning_elementalAI(Creature* creature) : ScriptedAI(creature) {}

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* conductor = me->FindNearestCreature(NPC_CRYSTAL_CONDUCTOR, 10.0f, true))
                conductor->CastSpell(conductor, SPELL_LIGHTNING_ROD);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bound_lightning_elementalAI(creature);
    }
};

class npc_ice_lance : public CreatureScript
{
    public:
        npc_ice_lance() : CreatureScript("npc_ice_lance") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ice_lanceAI(creature);
        }

        struct npc_ice_lanceAI : public ScriptedAI
        {
            npc_ice_lanceAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;

            void InitializeAI() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                DoCast(SPELL_ICE_LANCE_VISUAL);

                events.ScheduleEvent(EVENT_LANCE_HIT, 1000);
            }

            void Reset() override
            {
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_LANCE_HIT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 200.0f, true, -SPELL_LANCE_TARGET))
                            me->CastSpell(target, SPELL_LANCE_TARGET);
                        break;
                    default:
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_ice_wave : public CreatureScript
{
    public:
        npc_ice_wave() : CreatureScript("npc_ice_wave") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ice_waveAI(creature);
        }

        struct npc_ice_waveAI : public ScriptedAI
        {
            npc_ice_waveAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            float ori;
            float distance;
            float row;


            void InitializeAI() override
            {
                events.ScheduleEvent(EVENT_RADIATE, 100);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_ICE_WAVE);

                events.ScheduleEvent(EVENT_EDGE, 4000);
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_EDGE:
                        if (me->GetPositionX()> 13612.0f)
                            ori=(0);
                        else if (me->GetPositionX()< 13562.0f)
                            ori=float(M_PI);
                        else if (me->GetPositionY()> 13638.0f)
                            ori=(float(M_PI)/2.0f);
                        else if (me->GetPositionY()< 13584.0f)
                            ori=(1.5f* float(M_PI));

                        me->SetFacingTo(ori);
                        events.ScheduleEvent(EVENT_CIRCLING, 1000);
                        break;
                    case EVENT_CIRCLING:
                        {
                        distance = me->GetExactDist2d(centerpos.GetPositionX(), centerpos.GetPositionY());
                        if (distance >49.0f)
                            row=52;
                        else if (distance >42.0f && distance < 49.0f)
                            row=45;
                        else if (distance >35.0f && distance < 42.0f)
                            row=38;
                        else if (distance < 35.0f)
                            row=31;

                        ori-= 0.0415f;
                        if (ori <= 0)
                            ori += 2.0f * float(M_PI);
                        float X = centerpos.GetPositionX() + row*cos(ori);
                        float Y = centerpos.GetPositionY() + row*sin(ori);
                        me->GetMotionMaster()->MovePoint(0, X, Y, centerpos.GetPositionZ());

                        events.ScheduleEvent(EVENT_CIRCLING, 250);
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        };
};

class npc_collapsing_icicle : public CreatureScript
{
public:
    npc_collapsing_icicle() : CreatureScript("npc_collapsing_icicle") { }

    struct npc_collapsing_icicleAI : public ScriptedAI
    {
        npc_collapsing_icicleAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

            void InitializeAI() override
            {
                DoCast(me, SPELL_ICICLE);
                events.ScheduleEvent(EVENT_FALL, 4000);
            }
            void UpdateAI(uint32 diff) override

            {

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_FALL:
                        if (Creature* ishard = me->FindNearestCreature (NPC_FALLING_ICICLE, 7.0f))
                            ishard->CastSpell(ishard, SPELL_ICICLE_FALLING);
                         DoCast(me, SPELL_ICICLE_SHARD);
                         break;
                    default:
                        break;
                    }
                }
            }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_collapsing_icicleAI(creature);
    }
};

class npc_crystal_conductor : public CreatureScript
{
    public:
        npc_crystal_conductor() : CreatureScript("npc_crystal_conductor") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_crystal_conductorAI(creature);
        }

        struct npc_crystal_conductorAI : public ScriptedAI
        {
            npc_crystal_conductorAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;

            void InitializeAI() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                if(Unit* target = me->FindNearestCreature(NPC_HAGARA, 100.0f, true))
                    DoCast(target, SPELL_CRYSTAL_CONDUCTOR);
            }

        void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_LIGHTNING_ROD)
                events.ScheduleEvent(EVENT_CAST_CRYSTAL, 1000);
            if (spellInfo->Id == SPELL_LIGHTNING_CONDUIT_VISUAL)
                DoCast(me, SPELL_LIGHTNING_ROD);
        }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_CAST_CRYSTAL:
                         if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 10.0f, true))
                            DoCast(target, SPELL_LIGHTNING_CONDUIT);

                         DoCast(me, SPELL_LIGHTNING_ROD_LIGHT);
                         DoCast(me, SPELL_OVERLOAD);

                         events.ScheduleEvent(EVENT_CAST_CRYSTAL, 1000);
                         break;
                    default:
                        break;
                    }
                }
            }
        };
};

class NotVictimFilter
{
    public:
        NotVictimFilter(Unit* caster) : _victim(caster->GetVictim()){}

        bool operator()(WorldObject* target)
        {
            return target == _victim;
        }

    private:
        Unit* _victim;
};

class spell_ice_tomb : public SpellScriptLoader
{
    public:
        spell_ice_tomb() : SpellScriptLoader("spell_ice_tomb") { }

        class spell_ice_tomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ice_tomb_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
               targets.remove_if(NotVictimFilter(GetCaster()));

               if ((GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_N) ||
                   (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC))
                   Trinity::Containers::RandomResize(targets, 5);
               else
                   Trinity::Containers::RandomResize(targets, 2);
            }

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), SPELL_ICE_TOMB);
            }


            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ice_tomb_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_ice_tomb_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ice_tomb_SpellScript();
    }
};

class spell_ice_tomb_freeze : public SpellScriptLoader
{
    public:
        spell_ice_tomb_freeze() : SpellScriptLoader("spell_ice_tomb_freeze") { }

        class spell_ice_tomb_freeze_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ice_tomb_freeze_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sObjectMgr->GetCreatureTemplate(NPC_ICE_TOMB))
                    return false;
                return true;
            }

            void SummonTomb()
            {
                Position pos = GetHitUnit()->GetPosition();

                GetCaster()->SummonCreature(NPC_ICE_TOMB, pos, TEMPSUMMON_MANUAL_DESPAWN);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_ice_tomb_freeze_SpellScript::SummonTomb);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ice_tomb_freeze_SpellScript();
        }

    class spell_ice_tomb_freeze_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ice_tomb_freeze_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_ICE_TOMB))
                return false;
            return true;
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (GetUnitOwner()->FindNearestCreature(NPC_ICE_TOMB, 2.0f, false))
                GetUnitOwner()->RemoveAurasDueToSpell(SPELL_ICE_TOMB);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ice_tomb_freeze_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ice_tomb_freeze_AuraScript();
    }
};

class spell_ds_ice_lance : public SpellScriptLoader
{
public:
    spell_ds_ice_lance() : SpellScriptLoader("spell_ds_ice_lance") { }

    class spell_ds_ice_lance_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ds_ice_lance_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_LANCE_TARGET))
                return false;
            return true;
        }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                if(Unit* caster = aurEff->GetCaster())
                {
                    if(Unit* target = GetTarget())
                    {
                        std::list<Player*> betweeners;
                        std::list<Player*> targets;
                        caster->GetPlayerListInGrid(targets, 500.0f);

                        for (std::list<Player*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                        {
                            if((*iter)->ToPlayer())
                            {
                                if((*iter)->IsInBetween(caster, target, 5.0f))
                                {
                                    betweeners.push_back((*iter));
                                }
                            }
                        }
                        if(betweeners.size() > 0)
                        {
                            betweeners.sort(Trinity::ObjectDistanceOrderPred(caster));

                            if(Unit* target = betweeners.front())
                            {
                                caster->CastSpell(target, SPELL_ICE_LANCE, true);
                            }
                        }
                        else
                        {
                            caster->CastSpell(target, SPELL_ICE_LANCE, true);
                        }
                    }
                }
            }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ds_ice_lance_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ds_ice_lance_AuraScript();
    }
};

class spell_lightning_conduit_dummy : public SpellScriptLoader
{
    public:
        spell_lightning_conduit_dummy() : SpellScriptLoader("spell_lightning_conduit_dummy") { }

        class spell_lightning_conduit_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_lightning_conduit_dummy_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        caster->CastSpell(target, SPELL_LIGHTNING_CONDUIT, true);
                        if (target->GetExactDist2d(caster) > 10.0f)
                        {
                            target->RemoveAurasDueToSpell(SPELL_LIGHTNING_CONDUIT);
                            target->RemoveAurasDueToSpell(SPELL_LIGHTNING_CONDUIT_VISUAL);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_lightning_conduit_dummy_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_lightning_conduit_dummy_SpellScript::HandleHit, EFFECT_2, SPELL_EFFECT_DUMMY);
            }
        };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lightning_conduit_dummy_SpellScript();
    }
};

class spell_lightning_conduit : public SpellScriptLoader
{
public:
    spell_lightning_conduit() : SpellScriptLoader("spell_lightning_conduit") { }

        class spell_lightning_conduit_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_lightning_conduit_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if(Unit* caster = GetCaster())
                    if(Unit* target = GetHitUnit())
                        caster->CastSpell(target, SPELL_LIGHTNING_CONDUIT_VISUAL, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_lightning_conduit_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lightning_conduit_SpellScript();
    }

    class spell_lightning_conduit_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_lightning_conduit_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_LIGHTNING_CONDUIT))
                return false;
            return true;
        }


        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if(Unit* owner = GetUnitOwner())
                owner->CastSpell(owner, SPELL_LIGHTNING_CONDUIT_DUMMY, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_lightning_conduit_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_lightning_conduit_AuraScript();
    }
};

class spell_frozen_tempest : public SpellScriptLoader
{
    public:
        spell_frozen_tempest() : SpellScriptLoader("spell_frozen_tempest") { }

        class spell_frozen_tempest_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_frozen_tempest_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if(Unit* owner = GetUnitOwner())
                    if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                        owner->CastSpell(owner, SPELL_FROZEN_TEMPEST);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_frozen_tempest_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_frozen_tempest_AuraScript();
        }
};

class spell_frostflake : public SpellScriptLoader
{
public:
    spell_frostflake() : SpellScriptLoader("spell_frostflake") { }

    class spell_frostflake_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_frostflake_SpellScript);

        void FilterEff0(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
            DamageTarget = targets;
        }

        void FilterEff1(std::list<WorldObject*>& targets)
        {
            targets = DamageTarget;
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_frostflake_SpellScript::FilterEff0, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_frostflake_SpellScript::FilterEff1, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        }
        std::list<WorldObject*> DamageTarget;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_frostflake_SpellScript();
    }


    class spell_frostflake_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_frostflake_AuraScript);

        bool Load() override
        {
            _spell = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            int32 stack = 0;
            if (Unit* owner = GetUnitOwner())
            {
                if (Aura* fflake = owner->GetAura(SPELL_FROSTFLAKE))
                    stack = fflake->GetStackAmount();

                owner->SetAuraStack(SPELL_FROSTFLAKE, owner, stack + 1);
                aurEff->GetBase()->SetDuration(15000 - (1000* stack));
            }
        }

        void Dispel(DispelInfo* dispelData)
        {
            dispelData->SetRemovedCharges(0);
            if (Unit* caster = GetCaster())
            {
                if (Unit* dispelledUnit = GetUnitOwner())
                    if (dispelledUnit->HasAura(SPELL_FROSTFLAKE))
                    {
                        dispelledUnit->RemoveAurasDueToSpell(SPELL_FROSTFLAKE, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
                        caster->CastSpell(dispelledUnit, 80019);
                    }
            }
        }
    private:
        int32 _spell;

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_frostflake_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            OnDispel += AuraDispelFn(spell_frostflake_AuraScript::Dispel);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_frostflake_AuraScript();
    }
};

class spell_storm_pillars : public SpellScriptLoader
{

public:
    spell_storm_pillars() : SpellScriptLoader("spell_storm_pillars") { }

    class spell_storm_pillars_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_storm_pillars_SpellScript);

        bool Load() override
        {
            _spell = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), _spell);
        }
    private:
        uint32 _spell;

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_storm_pillars_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_storm_pillars_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_storm_pillars_SpellScript();
    }
};

void AddSC_boss_hagara_the_stormbinder()
{
    new boss_hagara_the_stormbinder();
    new npc_ds_ice_tomb();
    new npc_frozen_binding_crystal();
    new npc_bound_lightning_elemental();
    new npc_ice_lance();
    new npc_ice_wave();
    new npc_collapsing_icicle();
    new npc_crystal_conductor();
    new spell_ice_tomb();
    new spell_ice_tomb_freeze();
    new spell_ds_ice_lance();
    new spell_lightning_conduit_dummy();
    new spell_lightning_conduit();
    new spell_frozen_tempest();
    new spell_frostflake();
    new spell_storm_pillars();
}
