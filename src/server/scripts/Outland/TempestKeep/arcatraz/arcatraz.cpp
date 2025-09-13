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

/*
 * The way Mellichar's event is reset requires additional research
 */

#include "ScriptMgr.h"
#include "arcatraz.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum MillhouseTexts
{
    SAY_INTRO_1                = 0,
    SAY_INTRO_2                = 1,
    SAY_INTRO_3                = 2,
    SAY_INTRO_4                = 3,
    SAY_WATER                  = 4,
    SAY_BUFFS                  = 5,
    SAY_DRINK                  = 6,
    SAY_READY                  = 7,
    SAY_SLAY                   = 8,
    SAY_PYRO                   = 9,
    SAY_ICEBLOCK               = 10,
    SAY_LOWHP                  = 11,
    SAY_DEATH                  = 12,
    SAY_COMPLETE               = 13
};

enum MillhouseSpells
{
    SPELL_SIMPLE_TELEPORT      = 12980,
    SPELL_CONJURE_WATER        = 36879,
    SPELL_ARCANE_INTELLECT     = 36880,
    SPELL_ICE_ARMOR            = 36881,
    SPELL_DRINK                = 30024,

    SPELL_FIREBALL             = 14034,
    SPELL_FROSTBOLT            = 15497,
    SPELL_ARCANE_MISSILES      = 33832,
    SPELL_CONE_OF_COLD         = 12611,
    SPELL_FIRE_BLAST           = 13341,
    SPELL_PYROBLAST            = 33975,
    SPELL_ICE_BLOCK            = 36911
};

enum MillhouseEvents
{
    EVENT_INTRO_1              = 1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5,
    EVENT_INTRO_6,
    EVENT_INTRO_7,
    EVENT_INTRO_8,
    EVENT_INTRO_9,
    EVENT_INTRO_10,
    EVENT_INTRO_11,
    EVENT_INTRO_12,

    EVENT_MAIN_SPELL,
    EVENT_ARCANE_MISSILES,
    EVENT_CONE_OF_COLD,
    EVENT_FIRE_BLAST,
    EVENT_PYROBLAST,
    EVENT_ICE_BLOCK,
    EVENT_LOW_HEALTH
};

enum MillhouseMisc
{
    POINT_CENTER               = 1
};

Position const CenterPos = { 445.88043f, -158.70554f, 43.068977f, 0.0f };

// 20977 - Millhouse Manastorm
struct npc_millhouse_manastorm : public ScriptedAI
{
    npc_millhouse_manastorm(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()), _lowHealth(false), _hasIceBlock(false) { }

    void JustAppeared() override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        _events.ScheduleEvent(EVENT_INTRO_1, 0s);
    }

    void Reset() override
    {
        _events.Reset();
        _lowHealth = false;
        _hasIceBlock = false;

        if (_instance->GetBossState(DATA_HARBINGER_SKYRISS) == DONE)
        {
            Talk(SAY_COMPLETE);
            me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_MAIN_SPELL, 0s);
        _events.ScheduleEvent(EVENT_ARCANE_MISSILES, 10s, 20s);
        _events.ScheduleEvent(EVENT_CONE_OF_COLD, 15s, 25s);
        _events.ScheduleEvent(EVENT_FIRE_BLAST, 20s, 30s);
        _events.ScheduleEvent(EVENT_PYROBLAST, 30s, 45s);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 30.0f);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_CENTER)
            _events.ScheduleEvent(EVENT_INTRO_12, 0s);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_lowHealth && me->HealthBelowPctDamaged(20, damage))
        {
            _lowHealth = true;
            _events.ScheduleEvent(EVENT_LOW_HEALTH, 0s);
        }
        // Guessed, how this spell should be used?
        if (!_hasIceBlock && me->HealthBelowPctDamaged(10, damage))
        {
            _hasIceBlock = true;
            _events.ScheduleEvent(EVENT_ICE_BLOCK, 0s);
        }
    }

    void OnSpellStart(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_PYROBLAST)
            Talk(SAY_PYRO);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ICE_BLOCK)
            Talk(SAY_ICEBLOCK);
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateIntroEvents(diff);
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MAIN_SPELL:
                    DoCastVictim(RAND(SPELL_FIREBALL, SPELL_FROSTBOLT));
                    _events.Repeat(3s);
                    break;
                case EVENT_ARCANE_MISSILES:
                    DoCastVictim(SPELL_ARCANE_MISSILES);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_CONE_OF_COLD:
                    DoCastSelf(SPELL_CONE_OF_COLD);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_FIRE_BLAST:
                    DoCastVictim(SPELL_FIRE_BLAST);
                    _events.Repeat(25s, 40s);
                    break;
                case EVENT_PYROBLAST:
                    DoCastVictim(SPELL_PYROBLAST);
                    _events.Repeat(40s, 60s);
                    break;
                case EVENT_ICE_BLOCK:
                    DoCastSelf(SPELL_ICE_BLOCK);
                    break;
                case EVENT_LOW_HEALTH:
                    Talk(SAY_LOWHP);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void UpdateIntroEvents(uint32 diff)
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    DoCastSelf(SPELL_SIMPLE_TELEPORT);
                    _events.ScheduleEvent(EVENT_INTRO_2, 2s);
                    break;
                case EVENT_INTRO_2:
                    Talk(SAY_INTRO_1);
                    _events.ScheduleEvent(EVENT_INTRO_3, 4s + 500ms);
                    break;
                case EVENT_INTRO_3:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    _events.ScheduleEvent(EVENT_INTRO_4, 14s);
                    break;
                case EVENT_INTRO_4:
                    if (Creature* mellichar = _instance->GetCreature(DATA_MELLICHAR))
                        me->SetFacingToObject(mellichar);
                    Talk(SAY_INTRO_2);
                    _events.ScheduleEvent(EVENT_INTRO_5, 9s);
                    break;
                case EVENT_INTRO_5:
                    Talk(SAY_INTRO_3);
                    me->SetFacingTo(0.03490658476948738f);
                    _events.ScheduleEvent(EVENT_INTRO_6, 8s);
                    break;
                case EVENT_INTRO_6:
                    if (Creature* mellichar = _instance->GetCreature(DATA_MELLICHAR))
                        me->SetFacingToObject(mellichar);
                    Talk(SAY_INTRO_4);
                    _events.ScheduleEvent(EVENT_INTRO_7, 5s);
                    break;
                case EVENT_INTRO_7:
                    Talk(SAY_WATER);
                    DoCastSelf(SPELL_CONJURE_WATER);
                    _events.ScheduleEvent(EVENT_INTRO_8, 7s);
                    break;
                case EVENT_INTRO_8:
                    Talk(SAY_BUFFS);
                    DoCastSelf(SPELL_ARCANE_INTELLECT);
                    _events.ScheduleEvent(EVENT_INTRO_9, 3s);
                    break;
                case EVENT_INTRO_9:
                    DoCastSelf(SPELL_ICE_ARMOR);
                    _events.ScheduleEvent(EVENT_INTRO_10, 6s);
                    break;
                case EVENT_INTRO_10:
                    Talk(SAY_DRINK);
                    DoCastSelf(SPELL_DRINK);
                    _events.ScheduleEvent(EVENT_INTRO_11, 6s);
                    break;
                case EVENT_INTRO_11:
                    Talk(SAY_READY);
                    // Clear stand state from Drink spell manually, otherwise it will be not cleared
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->GetMotionMaster()->MovePoint(POINT_CENTER, CenterPos);
                    break;
                case EVENT_INTRO_12:
                    if (Creature* mellichar = _instance->GetCreature(DATA_MELLICHAR))
                        me->SetFacingToObject(mellichar);
                    me->SetImmuneToAll(false);
                    me->SetHomePosition(me->GetPosition());
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _lowHealth;
    bool _hasIceBlock;
};

enum WardenTexts
{
    SAY_RELEASE_1         = 0,
    SAY_RELEASE_2         = 1,
    SAY_RELEASE_3         = 2,
    SAY_RELEASE_4         = 3,
    SAY_RELEASE_5         = 4,
    SAY_RELEASE_6         = 5,
    SAY_RELEASE_7         = 6,
    SAY_RELEASE_8         = 7
};

enum WardenSpells
{
    SPELL_SEAL_SPHERE     = 36849,
    SPELL_TARGET_OMEGA    = 36852,
    SPELL_TARGET_ALPHA    = 36854,
    SPELL_TARGET_BETA     = 36856,
    SPELL_TARGET_DELTA    = 36857,
    SPELL_TARGET_GAMMA    = 36858,
    SPELL_QUIET_SUICIDE   = 3617
};

enum WardenEvents
{
    EVENT_MAIN_CHANNEL    = 1,

    EVENT_RELEASE_1_1,
    EVENT_RELEASE_1_2,
    EVENT_RELEASE_1_3,
    EVENT_RELEASE_1_4,
    EVENT_RELEASE_1_5,
    EVENT_RELEASE_1_6,
    EVENT_RELEASE_1_7,
    EVENT_RELEASE_1_8,
    EVENT_RELEASE_1_9,

    EVENT_RELEASE_2_1,
    EVENT_RELEASE_2_2,
    EVENT_RELEASE_2_3,
    EVENT_RELEASE_2_4,
    EVENT_RELEASE_2_5,
    EVENT_RELEASE_2_6,

    EVENT_RELEASE_3_1,
    EVENT_RELEASE_3_2,
    EVENT_RELEASE_3_3,
    EVENT_RELEASE_3_4,
    EVENT_RELEASE_3_5,
    EVENT_RELEASE_3_6,
    EVENT_RELEASE_3_7,

    EVENT_RELEASE_4_1,
    EVENT_RELEASE_4_2,
    EVENT_RELEASE_4_3,
    EVENT_RELEASE_4_4,
    EVENT_RELEASE_4_5,
    EVENT_RELEASE_4_6,

    EVENT_RELEASE_5_1,
    EVENT_RELEASE_5_2,
    EVENT_RELEASE_5_3,
    EVENT_RELEASE_5_4,
    EVENT_RELEASE_5_5
};

enum WardenCreatures
{
    // Prisoner 1
    NPC_TRICKSTER         = 20905,
    NPC_PH_HUNTER         = 20906,
    // Prisoner 2
    NPC_MILLHOUSE_M       = 20977,
    // Prisoner 3
    NPC_AKKIRIS           = 20908,
    NPC_SULFURON          = 20909,
    // Prisoner 4
    NPC_TW_DRAK           = 20910,
    NPC_BL_DRAK           = 20911,
    // Prisoner 5
    NPC_SKYRISS           = 20912
};

Position const PrisonerSpawnPos[5] =
{
    { 472.231f, -150.860f, 42.6573f, 3.106690f },
    { 417.242f, -149.795f, 42.6548f, 0.191986f },
    { 420.851f, -174.337f, 42.6655f, 0.122173f },
    { 470.364f, -174.656f, 42.6753f, 3.595380f },
    { 446.086f, -182.506f, 44.0852f, 1.570800f }
};

// 20904 - Warden Mellichar
struct npc_warden_mellichar : public ScriptedAI
{
    npc_warden_mellichar(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()), _summons(me), _inProgress(false) { }

    void Reset() override
    {
        _events.Reset();
        _summons.DespawnAll();
        _events.ScheduleEvent(EVENT_MAIN_CHANNEL, 0s);
        me->SetReactState(REACT_PASSIVE);

        _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_STASIS_POD_ALPHA));
        _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_STASIS_POD_BETA));
        _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_STASIS_POD_DELTA));
        _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_STASIS_POD_GAMMA));
        _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_STASIS_POD_OMEGA));
        _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_WARDENS_SHIELD));

        if (_instance->GetBossState(DATA_HARBINGER_SKYRISS) == FAIL)
        {
            _instance->SetBossState(DATA_HARBINGER_SKYRISS, NOT_STARTED);
            me->DespawnOrUnsummon(0s, 1min);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (_inProgress)
            return;

        if (who->GetTypeId() != TYPEID_PLAYER || !who->IsWithinDist(me, INTERACTION_DISTANCE))
            return;

        JustEngagedWith(who);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_inProgress)
            return;

        _inProgress = true;
        _events.ScheduleEvent(EVENT_RELEASE_1_1, 1s);
        _instance->SetBossState(DATA_HARBINGER_SKYRISS, IN_PROGRESS);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SEAL_SPHERE)
            _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_WARDENS_SHIELD));
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // Creature is unkillable by default. But allow to kill self with Quiet Suicide spell
        if (damage >= me->GetHealth() && who != me)
            damage = me->GetHealth() -1;
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_RESET_PRISON)
            Reset();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
        DoZoneInCombat(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        // Not entirely correct. Next phase is started when prisoner is about to die, not when he's dead
        switch (summon->GetEntry())
        {
            case NPC_TRICKSTER:
            case NPC_PH_HUNTER:
                _events.ScheduleEvent(EVENT_RELEASE_2_1, 0s);
                break;
            case NPC_AKKIRIS:
            case NPC_SULFURON:
                _events.ScheduleEvent(EVENT_RELEASE_4_1, 0s);
                break;
            case NPC_TW_DRAK:
            case NPC_BL_DRAK:
                _events.ScheduleEvent(EVENT_RELEASE_5_1, 0s);
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
                case EVENT_MAIN_CHANNEL:
                    DoCastSelf(SPELL_TARGET_OMEGA);
                    _events.Repeat(12s);
                    break;

                case EVENT_RELEASE_1_1:
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAurasDueToSpell(SPELL_TARGET_OMEGA);
                    me->SetImmuneToPC(true);
                    _events.CancelEvent(EVENT_MAIN_CHANNEL);
                    _events.ScheduleEvent(EVENT_RELEASE_1_2, 2s);
                    break;
                case EVENT_RELEASE_1_2:
                    me->SetFacingTo(1.605702877044677734f);
                    // Apparently casting this spell makes him reset orientation to default
                    DoCastSelf(SPELL_SEAL_SPHERE);
                    Talk(SAY_RELEASE_1);
                    _events.ScheduleEvent(EVENT_RELEASE_1_3, 23s);
                    break;
                case EVENT_RELEASE_1_3:
                    Talk(SAY_RELEASE_2);
                    _events.ScheduleEvent(EVENT_RELEASE_1_4, 2s);
                    break;
                case EVENT_RELEASE_1_4:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    _events.ScheduleEvent(EVENT_RELEASE_1_5, 2s);
                    break;
                case EVENT_RELEASE_1_5:
                    DoCastSelf(SPELL_TARGET_ALPHA);
                    _events.ScheduleEvent(EVENT_RELEASE_1_6, 4s);
                    break;
                case EVENT_RELEASE_1_6:
                    _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_STASIS_POD_ALPHA));
                    _events.ScheduleEvent(EVENT_RELEASE_1_7, 2s);
                    break;
                case EVENT_RELEASE_1_7:
                    me->SetFacingTo(4.747295379638671875f);
                    _events.ScheduleEvent(EVENT_RELEASE_1_8, 2s);
                    break;
                case EVENT_RELEASE_1_8:
                    _events.ScheduleEvent(EVENT_MAIN_CHANNEL, 0s);
                    _events.ScheduleEvent(EVENT_RELEASE_1_9, 6s);
                    break;
                case EVENT_RELEASE_1_9:
                    me->SummonCreature(RAND(NPC_TRICKSTER, NPC_PH_HUNTER), PrisonerSpawnPos[0], TEMPSUMMON_MANUAL_DESPAWN);
                    break;

                case EVENT_RELEASE_2_1:
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAurasDueToSpell(SPELL_TARGET_OMEGA);
                    me->SetFacingTo(1.675516128540039062f);
                    Talk(SAY_RELEASE_3);
                    _events.CancelEvent(EVENT_MAIN_CHANNEL);
                    _events.ScheduleEvent(EVENT_RELEASE_2_2, 5s);
                    break;
                case EVENT_RELEASE_2_2:
                    DoCastSelf(SPELL_TARGET_BETA);
                    _events.ScheduleEvent(EVENT_RELEASE_2_3, 3s);
                    break;
                case EVENT_RELEASE_2_3:
                    me->SetFacingTo(4.747295379638671875f);
                    Talk(SAY_RELEASE_4);
                    _events.ScheduleEvent(EVENT_RELEASE_2_4, 1s);
                    break;
                case EVENT_RELEASE_2_4:
                    _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_STASIS_POD_BETA));
                    _events.ScheduleEvent(EVENT_RELEASE_2_5, 1s);
                    break;
                case EVENT_RELEASE_2_5:
                    _events.ScheduleEvent(EVENT_MAIN_CHANNEL, 0s);
                    _events.ScheduleEvent(EVENT_RELEASE_2_6, 7s);
                    break;
                case EVENT_RELEASE_2_6:
                    me->SummonCreature(NPC_MILLHOUSE_M, PrisonerSpawnPos[1], TEMPSUMMON_MANUAL_DESPAWN);
                    _events.ScheduleEvent(EVENT_RELEASE_3_1, 12s);
                    break;

                case EVENT_RELEASE_3_1:
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAurasDueToSpell(SPELL_TARGET_OMEGA);
                    _events.CancelEvent(EVENT_MAIN_CHANNEL);
                    _events.ScheduleEvent(EVENT_RELEASE_3_2, 2s);
                    break;
                case EVENT_RELEASE_3_2:
                    me->SetFacingTo(2.478367567062377929f);
                    Talk(SAY_RELEASE_5);
                    _events.ScheduleEvent(EVENT_RELEASE_3_3, 6s);
                    break;
                case EVENT_RELEASE_3_3:
                    DoCastSelf(SPELL_TARGET_DELTA);
                    _events.ScheduleEvent(EVENT_RELEASE_3_4, 3s);
                    break;
                case EVENT_RELEASE_3_4:
                    me->SetFacingTo(4.747295379638671875f);
                    _events.ScheduleEvent(EVENT_RELEASE_3_5, 1s);
                    break;
                case EVENT_RELEASE_3_5:
                    _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_STASIS_POD_DELTA));
                    _events.ScheduleEvent(EVENT_RELEASE_3_6, 4s);
                    break;
                case EVENT_RELEASE_3_6:
                    _events.ScheduleEvent(EVENT_MAIN_CHANNEL, 0s);
                    _events.ScheduleEvent(EVENT_RELEASE_3_7, 4s);
                    break;
                case EVENT_RELEASE_3_7:
                    me->SummonCreature(RAND(NPC_AKKIRIS, NPC_SULFURON), PrisonerSpawnPos[2], TEMPSUMMON_MANUAL_DESPAWN);
                    break;

                case EVENT_RELEASE_4_1:
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAurasDueToSpell(SPELL_TARGET_OMEGA);
                    me->SetFacingTo(6.056292533874511718f);
                    Talk(SAY_RELEASE_6);
                    _events.CancelEvent(EVENT_MAIN_CHANNEL);
                    _events.ScheduleEvent(EVENT_RELEASE_4_2, 5s);
                    break;
                case EVENT_RELEASE_4_2:
                    DoCastSelf(SPELL_TARGET_GAMMA);
                    _events.ScheduleEvent(EVENT_RELEASE_4_3, 2s);
                    break;
                case EVENT_RELEASE_4_3:
                    me->SetFacingTo(4.747295379638671875f);
                    _events.ScheduleEvent(EVENT_RELEASE_4_4, 1s);
                    break;
                case EVENT_RELEASE_4_4:
                    _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_STASIS_POD_GAMMA));
                    _events.ScheduleEvent(EVENT_RELEASE_4_5, 2s);
                    break;
                case EVENT_RELEASE_4_5:
                    _events.ScheduleEvent(EVENT_MAIN_CHANNEL, 0s);
                    _events.ScheduleEvent(EVENT_RELEASE_4_6, 7s);
                    break;
                case EVENT_RELEASE_4_6:
                    me->SummonCreature(RAND(NPC_TW_DRAK, NPC_BL_DRAK), PrisonerSpawnPos[3], TEMPSUMMON_MANUAL_DESPAWN);
                    break;

                case EVENT_RELEASE_5_1:
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAurasDueToSpell(SPELL_TARGET_OMEGA);
                    Talk(SAY_RELEASE_7);
                    _events.CancelEvent(EVENT_MAIN_CHANNEL);
                    _events.ScheduleEvent(EVENT_RELEASE_5_2, 1s);
                    break;
                case EVENT_RELEASE_5_2:
                    _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_STASIS_POD_OMEGA));
                    _events.ScheduleEvent(EVENT_RELEASE_5_3, 10s);
                    break;
                case EVENT_RELEASE_5_3:
                    me->SummonCreature(NPC_SKYRISS, PrisonerSpawnPos[4], TEMPSUMMON_MANUAL_DESPAWN);
                    _events.ScheduleEvent(EVENT_RELEASE_5_4, 24s);
                    break;
                case EVENT_RELEASE_5_4:
                    Talk(SAY_RELEASE_8);
                    _events.ScheduleEvent(EVENT_RELEASE_5_5, 7s);
                    break;
                case EVENT_RELEASE_5_5:
                    DoCastSelf(SPELL_QUIET_SUICIDE);
                    _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_WARDENS_SHIELD));
                    me->DespawnOrUnsummon(18s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    SummonList _summons;
    bool _inProgress;
};

enum ChaosBreath
{
    SPELL_NECROTIC_POISON     = 36693,
    SPELL_CORROSIVE_POISON    = 36694,
    SPELL_FEVERED_FATIGUE     = 36695,
    SPELL_WITHERED_TOUCH      = 36696,
    SPELL_SHRINK              = 36697,
    SPELL_PIERCING_SHADOW     = 36698,
    SPELL_WAVERING_WILL       = 36699,
    SPELL_HEX                 = 36700
};

// 36677 - Chaos Breath
class spell_arcatraz_chaos_breath : public SpellScript
{
    PrepareSpellScript(spell_arcatraz_chaos_breath);

    static constexpr std::array<uint32, 8> PossibleSpells = { SPELL_NECROTIC_POISON, SPELL_CORROSIVE_POISON, SPELL_FEVERED_FATIGUE, SPELL_WITHERED_TOUCH, SPELL_SHRINK, SPELL_PIERCING_SHADOW, SPELL_WAVERING_WILL, SPELL_HEX };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(PossibleSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        std::array<uint32, 8> spellsToCast = PossibleSpells;

        Trinity::Containers::RandomShuffle(spellsToCast);

        for (uint32 i = 0; i < 3; ++i)
            caster->CastSpell(caster, spellsToCast[i]);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arcatraz_chaos_breath::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum DeathCountRemover
{
    SPELL_DEATH_COUNT_DAMAGE       = 36657,
    SPELL_DEATH_COUNT_DAMAGE_H     = 38818,
    SPELL_DEATH_COUNT_REMOVER      = 36660,
    SPELL_DEATH_COUNT_REMOVER_H    = 38820
};

// 36660, 38820 - Death Count
class spell_arcatraz_death_count : public AuraScript
{
    PrepareAuraScript(spell_arcatraz_death_count);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DEATH_COUNT_DAMAGE, SPELL_DEATH_COUNT_DAMAGE_H });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        switch (GetId())
        {
            case SPELL_DEATH_COUNT_REMOVER:
                GetTarget()->RemoveAurasDueToSpell(SPELL_DEATH_COUNT_DAMAGE);
                break;
            case SPELL_DEATH_COUNT_REMOVER_H:
                GetTarget()->RemoveAurasDueToSpell(SPELL_DEATH_COUNT_DAMAGE_H);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_arcatraz_death_count::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_arcatraz()
{
    RegisterArcatrazCreatureAI(npc_millhouse_manastorm);
    RegisterArcatrazCreatureAI(npc_warden_mellichar);
    RegisterSpellScript(spell_arcatraz_chaos_breath);
    RegisterSpellScript(spell_arcatraz_death_count);
}
