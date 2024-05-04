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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "CellImpl.h"
#include "Containers.h"
#include "TaskScheduler.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "G3DPosition.hpp"
#include "MoveSplineInitArgs.h"
#include <G3D/Box.h>
#include <G3D/CoordinateFrame.h>
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "UpdateFields.h"
#include "G3D/Vector2.h"
#include "Unit.h"
#include "Weather.h"
#include "GameObjectAI.h"
#include "sepulcher_of_the_first_ones.h"

enum LordsOfDreadSpells
{
    // Mimicking Transformations
    SPELL_MIMICKING_TRANSFORMATION_1                    = 361096,
    SPELL_MIMICKING_TRANSFORMATION_2                    = 361102,
    SPELL_MIMICKING_TRANSFORMATION_3                    = 361103,
    SPELL_MIMICKING_TRANSFORMATION_4                    = 361104,
    SPELL_MIMICKING_TRANSFORMATION_5                    = 361105,
    SPELL_MIMICKING_TRANSFORMATION_6                    = 361106,
    SPELL_MIMICKING_TRANSFORMATION_7                    = 361107,
    SPELL_MIMICKING_TRANSFORMATION_8                    = 361108,
    SPELL_MIMICKING_TRANSFORMATION_9                    = 361111,
    SPELL_MIMICKING_TRANSFORMATION_10                   = 361112,
    SPELL_MIMICKING_TRANSFORMATION_11                   = 361113,
    SPELL_MIMICKING_TRANSFORMATION_12                   = 361114,
    SPELL_MIMICKING_TRANSFORMATION_13                   = 361115,
    SPELL_MIMICKING_TRANSFORMATION_14                   = 361116,

    // Introduction Imitations
    SPELL_GRAND_REVEAL_MALGANIS                         = 366518,
    SPELL_GRAND_REVEAL_KINTESSA                         = 366565,
    SPELL_SWARMING_RETREAT_CLEAR_DEBUFFS                = 367410,
    SPELL_SWARMING_RETREAT                              = 366559,
    SPELL_CLEAR_ALL_DEBUFFS                             = 34098,
    SPELL_LEECHING_CLAWS_PROTECTOR                      = 366549,
    SPELL_LEECHING_CLAWS_PHYSICAL_DAMAGE_PROTECTOR      = 366550,
    SPELL_OPENED_VEINS_PROTECTOR                        = 366551,
    SPELL_LEECHING_CLAWS_HEAL_PROTECTOR                 = 366553,
    SPELL_CLOUD_OF_CARRION_PROTECTOR                    = 366573,
    SPELL_CLOUD_OF_CARRION_DEBUFF_PROTECTOR             = 366574,
    SPELL_ANGUISHING_STRIKE_PROTECTOR                   = 366629,
    SPELL_ANGUISHING_STRIKE_PHYSICAL_DAMAGE_PROTECTOR   = 366631,
    SPELL_ANGUISHING_STRIKE_DEBUFF_PROTECTOR            = 366632,
    SPELL_FEARFUL_TREPIDATION_PROTECTOR                 = 366633,
    SPELL_FEARFUL_TREPIDATION_DEBUFF_PROTECTOR          = 366634,

    // Generic
    SPELL_BERSERK                                       = 26662,
    SPELL_LIFE_LINK                                     = 345561,
    SPELL_LORDS_OF_DREAD_ENGAGED                        = 364120, // Mal'Ganis only
    SPELL_LORDS_OF_DREAD_ENCOUNTER_END                  = 364123, // Cast on Encounter END Mal'ganis only

    // Mimicking Disguise
    SPELL_MIMICKING_DISGUISE_PERIODIC_MALGANIS          = 361117,
    SPELL_MIMICKING_DISGUISE_PERIODIC_BOTH_DREADLORDS   = 365624,
    SPELL_MIMICKING_DISGUISE_VISUALS                    = 365634,
    SPELL_MIMICKING_DISGUISE_DUMMY                      = 365662,

    // Rampaging Swarm
    SPELL_RAMPAGING_SWARM = 360374,
    SPELL_RAMPAGING_SWARM_GO = 360376,
    SPELL_RAMPAGING_SWARM_START = 360377,

    // Mal'Ganis Spells
    // Energy
    SPELL_DECAY_ENERGY                                  = 360166,
    SPELL_DECAY_ENERGY_OVERRIDE                         = 360164,

    // Leeching Claws
    SPELL_LEECHING_CLAWS                                = 359960,
    SPELL_LEECHING_CLAWS_PHYSICAL                       = 362714,
    SPELL_LEECHING_CLAWS_HEAL                           = 359964,
    SPELL_OPENED_VEINS                                  = 359963,

    // Cloud of Carrion
    SPELL_CLOUD_OF_CARRION                              = 360006,
    SPELL_CLOUD_OF_CARRION_INITIAL_CIRCLE               = 360189,
    SPELL_CLOUD_OF_CARRION_MISSILE                      = 360182,
    SPELL_CLOUD_OF_CARRION_PREVENT_TRANSFER             = 360181,
    SPELL_CLOUD_OF_CARRION_CIRCLE                       = 360017,
    SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF           = 360012,
    SPELL_CLOUD_OF_CARRION_DEBUFF_DAMAGE                = 360015,
    SPELL_CLOUD_OF_CARRION_IMMUNITY                     = 368033,
    SPELL_CLOUD_OF_CARRION_AREATRIGGER                  = 360386,
    SPELL_BITING_WOUNDS_DEBUFF                          = 364985,

    // Manifest Shadows
    SPELL_MANIFEST_SHADOWS                              = 361913,
    SPELL_MANIFEST_SHADOWS_SUMMONING                    = 361915,
    SPELL_MANIFEST_SHADOWS_IDK                          = 364996, // Entry 183138

    // Swarm of Decay
    SPELL_SWARM_OF_DECAY                                = 360300,
    SPELL_SWARM_OF_DECAY_DAMAGE                         = 360302,
    SPELL_UNTO_DARKNESS                                 = 360319,
    SPELL_UNTO_DARKNESS_DARKEN_ENVIRONMENT              = 363275,
    SPELL_UNTO_DARKNESS_CLEAR                           = 363276,
    SPELL_RIDE_VEHICLE_HARDCODED                        = 46598,
    SPELL_DECAY_MASTERY                                 = 362158,
    SPELL_AURA_OF_CARRION                               = 363184,

    // Kin'Tessa
    //Energy
    SPELL_DARKNESS_ENERGY                               = 360167,
    SPELL_DARKNESS_OVERRIDE                             = 360163,

    // Anguishing Strike
    SPELL_ANGUISHING_STRIKE                             = 360284,
    SPELL_ANGUISHING_STRIKE_PHYSICAL                    = 362711,
    SPELL_ANGUISHING_STRIKE_DEBUFF                      = 360287,
    SPELL_ANGUISHING_STRIKE_DEBUFF_DAMAGE               = 360288,

    // Slumber Cloud
    SPELL_SLUMBER_CLOUD                                 = 360229,
    SPELL_SLUMBER_CLOUD_MISSILE                         = 360235,
    SPELL_SLUMBER_CLOUD_SUMMON                          = 360239,
    SPELL_SLUMBER_CLOUD_AREATRIGGER                     = 360260,
    SPELL_UNSETTLING_DREAMS                             = 360241,
    SPELL_UNSETLING_DREAMS_IMMUNE                       = 360262,

    // Fearful Trepidation
    SPELL_FEARFUL_TREPIDATION                           = 360145,
    SPELL_FEARFUL_TREPIDATION_CIRCLE                    = 360146,
    SPELL_BURSTING_DREAD_IMMUNITY                       = 360212,
    SPELL_BURSTING_DREAD_FEAR                           = 360148,

    // Swarm of Darkness
    SPELL_SWARM_OF_DARKNESS                             = 360304,
    SPELL_SWARM_OF_DARKNESS_2                           = 360303,

    // Infiltration of Dread
    SPELL_INFILTRATION_OF_DREAD                         = 360717,
    SPELL_INFILTRATION_OF_DREAD_KINTESSA                = 360417,
    SPELL_PARANOIA                                      = 360418,
    SPELL_PARANOIA_DAMAGE                               = 360419,
    SPELL_PARANOIA_STUN                                 = 361284,
    SPELL_INFILTRATION_DISAPPEAR                        = 360516,
    SPELL_INFILTRATION_PULL                             = 361528,
    SPELL_MALGANIS_IMPOSTER_REAL                        = 360496,
    SPELL_KINTESSA_IMPOSTER_REAL                        = 360498,
    SPELL_MOMENT_OF_CLARITY                             = 360428, // 3 casts
    SPELL_INFILTRATION_RETURN_TO_MALGANIS               = 360601,
    SPELL_INFILTRATION_RETURN_TO_KINTESSA               = 360602,
    SPELL_MALGANIS_IMPOSTER_FAKE                        = 360678,
    SPELL_KINTESSA_IMPOSTER_FAKE                        = 360680,

    SPELL_INFILTRATION_1                                = 360759, // Player casts on Player IDK
    SPELL_INFILTRATION_2                                = 365157, // Player casts on Player IDK
    SPELL_INFILTRATION_3                                = 365158, // Player casts on Player IDK

    SPELL_SUDDEN_REVEAL                                 = 360513,
    SPELL_STRENGTH_OF_MIND_IMPOSTER                     = 361502,
    SPELL_SHATTER_MIND                                  = 360420, // Cast by Both
    SPELL_HORRIFYING_SHADOWS                            = 363232,
    SPELL_HORRIFYING_SHADOWS_FEAR                       = 363235,
    SPELL_FEEDBACK                                      = 360466, // Not enough players for infiltration -> stun all
    SPELL_SHADOW_MASTERY                                = 362152,
    SPELL_AURA_OF_SHADOWS                               = 363191,

    // Inchoate Shadow
    // Ravenous Hunger
    SPELL_RAVENOUS_HUNGER                               = 361923,
    SPELL_RAVENOUS_HUNGER_PERIODIC                      = 361935,
    SPELL_RAVENOUS_HUNGER_TARGETTING                    = 361951,
    SPELL_RAVENOUS_HUNGER_HEAL                          = 361943,

    //Form
    SPELL_INCOMPLETE_FORM                               = 361934,
    SPELL_FULLY_FORMED                                  = 361945,
    SPELL_COALESCING_DARKNESS                           = 362585,
    SPELL_INCOMPLETE_FORM_AURA                          = 362020,
};

enum Events
{
    // Overthrown Protector Malganis
    EVENT_LEECHING_CLAWS_PROTECTOR = 1,
    EVENT_CLOUD_OF_CARRION_PROTECTOR,

    // Overthrown Protector Kintessa
    EVENT_ANGUISHING_STRIKE_PROTECTOR,
    EVENT_FEARFUL_TREPIDATION_PROTECTOR,

    // Mal'Ganis
    EVENT_LEECHING_CLAWS,
    EVENT_CLOUD_OF_CARRION,
    EVENT_MANIFEST_SHADOWS,
    EVENT_SWARM_OF_DECAY,

    // Kin'Tessa
    EVENT_ANGUISHING_STRIKE,
    EVENT_SLUMBER_CLOUD,
    EVENT_FEARFUL_TREPIDATION,
    EVENT_INFILTRATION_OF_DREAD,

    // Both
    EVENT_ENRAGE,

    // Inchoate Shadow
    EVENT_RAVENOUS_HUNGER,
};

enum Actions
{
    ACTION_OPEN_DOOR_TO_LORDS_OF_DREAD = 1,
    ACTION_START_INTRODUCTION,
    ACTION_MIMICKING_DISGUISE,
    ACTION_MALGANIS_SWARM_EVENTS,
    ACTION_KINTESSA_SWARM_EVENTS,
    ACTION_KINTESSA_PARANOIA_EVENTS,
    ACTION_MALGANIS_PARANOIA_EVENTS,
    ACTION_KINTESSA_RETURNED_ESSENCE,
    ACTION_MALGANIS_SLAIN,
    ACTION_KINTESSA_SLAIN,
    ACTION_MALGANIS_INFILTRATION_OF_DREAD,
    ACTION_PARANOIA,
};

enum LordsOfDreadTexts
{
    // Imitation texts
    SAY_MALGANIS_COPY_AGGRO                 = 0,
    SAY_MALGANIS_COPY_RETREAT               = 1,

    SAY_KINTESSA_COPY_AGGRO                 = 0,
    SAY_KINTESSA_COPY_RETREAT               = 1,

    SAY_MALGANIS_AGGRO                      = 0,
    SAY_MALGANIS_SLAY                       = 1,
    SAY_MANIFEST_SHADOWS                    = 2,
    SAY_SWARM_OF_DECAY                      = 3,
    SAY_SWARM_OF_DECAY_ANNOUNCE             = 4,
    SAY_MALGANIS_DEATH                      = 5,
    SAY_MALGANIS_ANNOUNCE_AURA_OF_CARRION   = 6,
    SAY_MALGANIS_ANNOUNCE_ENRAGE            = 7,
    SAY_MALGANIS_ENRAGE                     = 8,

    //SAY_KINTESSA_AGGRO                      = 0,
    SAY_KINTESSA_SLAY                       = 1,
    SAY_FEARFUL_TREPIDATION                 = 2,
    SAY_INFILTRATION_OF_DREAD               = 3,
    SAY_ANNOUNCE_INFILTRATION_OF_DREAD      = 4,
    SAY_KINTESSA_DEATH                      = 5,
    SAY_KINTESSA_ANNOUNCE_AURA_OF_SHADOWS   = 6,
    SAY_KINTESSA_ANNOUNCE_ENRAGE            = 7,
    SAY_KINTESSA_ENRAGE                     = 8,
};
enum LordsOfDreadConversations
{
    CONVERSATION_INTRODUCTION           = 17838,

    CONVERSATION_RESET_ENCOUNTER_01     = 17691,
    CONVERSATION_RESET_ENCOUNTER_02     = 17692,
    CONVERSATION_RESET_ENCOUNTER_03     = 17693,
    CONVERSATION_RESET_ENCOUNTER_04     = 17694,
    CONVERSATION_RESET_ENCOUNTER_05     = 17695,
    CONVERSATION_RESET_ENCOUNTER_06     = 17696,
};

Position const SwarmingRetreatPos = { -5727.0454f, -4067.804f, 146.26663f };

Position const MalganisVisuals[14] =
{
   { -5720.8384f, -4044.9219f, 151.26650f, },
   { -5706.1580f, -4046.3784f, 154.84780f, },
   { -5692.8267f, -4060.4410f, 155.99051f, },
   { -5705.3890f, -4037.6110f, 154.11404f, },
   { -5699.4272f, -4066.5764f, 154.35902f, },
   { -5709.5800f, -4062.5070f, 152.75505f, },
   { -5730.7520f, -4049.3090f, 152.96742f, },
   { -5713.4165f, -4055.9758f, 154.06033f, },
   { -5701.0728f, -4059.5452f, 154.77895f, },
   { -5700.5034f, -4054.5208f, 152.53079f, },
   { -5699.2847f, -4042.9480f, 146.17812f, },
   { -5719.8926f, -4057.0781f, 156.23918f, },
   { -5729.3994f, -4041.4219f, 154.11404f, },
   { -5722.5225f, -4036.4446f, 155.44520f  }
};

Position const KintessaVisuals[14] =
{
   { -5748.1616f, -4089.40620f, 152.53079f, },
   { -5741.4497f, -4096.69430f, 154.84780f, },
   { -5735.5260f, -4102.90970f, 152.34096f, },
   { -5729.2970f, -4084.23270f, 156.23918f, },
   { -5723.8870f, -4104.31600f, 155.44520f, },
   { -5735.5260f, -4102.90970f, 152.34096f, },
   { -5748.1616f, -4089.40620f, 152.53079f, },
   { -5741.0156f, -4105.48300f, 154.11404f, },
   { -5735.5260f, -4102.90970f, 152.34096f, },
   { -5726.7100f, -4096.14940f, 151.26650f, },
   { -5747.7900f, -4101.03800f, 146.17812f, },
   { -5748.1616f, -4089.40620f, 152.53079f, },
   { -5729.2970f, -4084.23270f, 156.23918f, },
   { -5741.0156f, -4105.48300f, 154.11404f  }
};

namespace
{
void ForDreadlords(InstanceScript* instance, std::function<void(Creature* dreadlord)> func)
{
    for (uint32 data = DATA_MALGANIS; data <= DATA_KINTESSA; data++)
    {
        if (Creature* dreadLord = instance->GetCreature(data))
            func(dreadLord);
    }
}

void ClearLordsOfDreadDebuffs(InstanceScript* instance)
{
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OPENED_VEINS);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ANGUISHING_STRIKE_DEBUFF);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOUD_OF_CARRION_DEBUFF_DAMAGE);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FEARFUL_TREPIDATION_CIRCLE);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARANOIA);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARANOIA_STUN);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FEEDBACK);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BURSTING_DREAD_FEAR);
    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNSETTLING_DREAMS);
}

void StartEncounter(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_LORDS_OF_DREAD) == IN_PROGRESS)
        return;

    instance->SetBossState(DATA_LORDS_OF_DREAD, IN_PROGRESS);
    instance->DoUpdateWorldState(WORLD_STATE_LORDS_OF_DREAD_ENCOUNTER_STARTED, 1);

    bool doAggroTalk = roll_chance_i(50);
    ForDreadlords(instance, [instance, &doAggroTalk](Creature* dreadlord)
    {
        if (doAggroTalk)
        {
            dreadlord->AI()->Talk(SAY_MALGANIS_AGGRO);
            doAggroTalk = false;
        }
        else
            doAggroTalk = true;

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, dreadlord);
        dreadlord->AI()->DoZoneInCombat(); // @TODO: ovah did changes here, i forgot which
    });
}

void FailEncounter(InstanceScript* instance, EvadeReason why)
{
    if (instance->GetBossState(DATA_LORDS_OF_DREAD) == FAIL)
        return;

    instance->SetBossState(DATA_LORDS_OF_DREAD, FAIL);
    instance->DoUpdateWorldState(WORLD_STATE_LORDS_OF_DREAD_ENCOUNTER_STARTED, 0);
    ClearLordsOfDreadDebuffs(instance);

    ForDreadlords(instance, [instance, why](Creature* dreadlord)
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, dreadlord);
        dreadlord->AI()->EnterEvadeMode(why);
    });
}

void DoneEncounter(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_LORDS_OF_DREAD) == DONE)
        return;

    bool bothDead = true;
    ForDreadlords(instance, [&bothDead](Creature* dreadlord)
    {
        if (dreadlord->IsAlive())
            bothDead = false;
    });

    if (!bothDead)
        return;

    instance->SetBossState(DATA_LORDS_OF_DREAD, DONE);
    instance->DoUpdateWorldState(WORLD_STATE_LORDS_OF_DREAD_ENCOUNTER_COMPLETED, 1);
    instance->DoUpdateWorldState(WORLD_STATE_LORDS_OF_DREAD_ENCOUNTER_STARTED, 0);
    ClearLordsOfDreadDebuffs(instance);

    ForDreadlords(instance, [instance](Creature* dreadlord)
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, dreadlord);
    });
}
}

struct LordsOfDreadAI : public BossAI
{
    LordsOfDreadAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId) { }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
    }

    void JustAppeared() override
    {
        scheduler.ClearValidator();
        scheduler.Schedule(5s, [this](TaskContext task)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            task.Repeat(4s, 10s);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        StartEncounter(instance);

        if (IsLFR())
            DoCast(GetOtherDreadlord(), SPELL_LIFE_LINK, true);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        FailEncounter(instance, why);

        events.Reset();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        events.Reset();
        summons.DespawnAll();

        DoneEncounter(instance);
    }

protected:
    Creature* GetOtherDreadlord()
    {
        return instance->GetCreature(me->GetEntry() == BOSS_MALGANIS ? DATA_KINTESSA : DATA_MALGANIS);
    }
};

// 181398 - Mal'Ganis
struct boss_lords_of_dread_mal_ganis : public LordsOfDreadAI
{
    struct boss_lords_of_dread_mal_ganis(Creature* creature) : LordsOfDreadAI(creature, DATA_MALGANIS), _retreatsCount(0), _carrionCount(0) { }

    void CancelMalganisEventsScheduleAfterParanoia()
    {
        events.ScheduleEvent(EVENT_LEECHING_CLAWS, 5s);
        events.ScheduleEvent(EVENT_CLOUD_OF_CARRION, 7500ms);
        events.ScheduleEvent(EVENT_SWARM_OF_DECAY, 51s);
        if (IsMythic())
            events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 9500ms);
        else
            events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 10s);
    }

    void JustAppeared() override
    {
        LordsOfDreadAI::JustAppeared();

        DoCastSelf(SPELL_DARKNESS_OVERRIDE);
    }

    void Reset() override
    {
        LordsOfDreadAI::Reset();

        _carrionCount = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        DoCastSelf(SPELL_DECAY_ENERGY, true);

        events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 13s);
        events.ScheduleEvent(EVENT_LEECHING_CLAWS, 15500ms);
        events.ScheduleEvent(EVENT_SWARM_OF_DECAY, 51s);
        if (IsMythic())
            events.ScheduleEvent(EVENT_CLOUD_OF_CARRION, 7s);
        else
            events.ScheduleEvent(EVENT_CLOUD_OF_CARRION, 6s);

        LordsOfDreadAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_MALGANIS_DEATH);

        LordsOfDreadAI::JustDied(killer);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OPEN_DOOR_TO_LORDS_OF_DREAD:
            {
                _retreatsCount++;
                if (_retreatsCount == 2)
                {
                    scheduler.Schedule(3s, [this](TaskContext /*task*/)
                    {
                        instance->DoUseDoorOrButton(instance->GetGuidData(DATA_DOOR_TO_LORDS_OF_DREAD));
                    });
                }
                break;
            }
            case ACTION_MALGANIS_SWARM_EVENTS:
            {
                events.CancelEvent(EVENT_CLOUD_OF_CARRION);
                events.CancelEvent(EVENT_MANIFEST_SHADOWS);
                events.CancelEvent(EVENT_LEECHING_CLAWS);
                events.CancelEvent(EVENT_SWARM_OF_DECAY);

                events.ScheduleEvent(EVENT_LEECHING_CLAWS, 28100ms);
                events.ScheduleEvent(EVENT_CLOUD_OF_CARRION, 30500ms);
                events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 33600ms);
                break;
            }
            case ACTION_MIMICKING_DISGUISE:
            {
                for (uint8 i = 0; i < 14; i++)
                {
                    scheduler.Schedule(Milliseconds(i * 250), [this, i](TaskContext /*task*/)
                    {
                        me->CastSpell(MalganisVisuals[i], SPELL_MIMICKING_DISGUISE_VISUALS, true);
                    });
                }
                break;
            }
            case ACTION_MALGANIS_INFILTRATION_OF_DREAD:
            {
                events.CancelEvent(EVENT_LEECHING_CLAWS);
                events.CancelEvent(EVENT_CLOUD_OF_CARRION);
                events.CancelEvent(EVENT_MANIFEST_SHADOWS);
                events.CancelEvent(EVENT_SWARM_OF_DECAY);
                DoCastSelf(SPELL_INFILTRATION_OF_DREAD);
                break;
            }
            case ACTION_MALGANIS_PARANOIA_EVENTS:
            {
                events.ScheduleEvent(EVENT_LEECHING_CLAWS, 5s);
                events.ScheduleEvent(EVENT_CLOUD_OF_CARRION, 7500ms);
                events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 9500ms);
                events.ScheduleEvent(EVENT_SWARM_OF_DECAY, 51s);
                break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        LordsOfDreadAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENRAGE:
                {
                    DoCastSelf(SPELL_BERSERK, true);
                    Talk(SAY_MALGANIS_ANNOUNCE_ENRAGE);
                    Talk(SAY_MALGANIS_ENRAGE);
                    break;
                }
                case EVENT_CLOUD_OF_CARRION:
                {
                    DoCastSelf(SPELL_CLOUD_OF_CARRION);
                    _carrionCount++;
                    if (_carrionCount % 2 == 0)
                        events.Repeat(51500ms);
                    else
                        events.Repeat(21900ms);
                    break;
                }
                case EVENT_MANIFEST_SHADOWS:
                {
                    DoCastSelf(SPELL_MANIFEST_SHADOWS);
                    Talk(SAY_MANIFEST_SHADOWS);
                    break;
                }
                case EVENT_LEECHING_CLAWS:
                {
                    DoCastVictim(SPELL_LEECHING_CLAWS, false);
                    events.Repeat(16s);
                    break;
                }
                case EVENT_SWARM_OF_DECAY:
                {
                    Creature* kintessa = GetOtherDreadlord();
                    if (!kintessa->IsAlive())
                        return;

                    DoCastSelf(SPELL_SWARM_OF_DECAY);
                    DoCastAOE(SPELL_UNTO_DARKNESS);
                    Talk(SAY_SWARM_OF_DECAY);
                    DoAction(ACTION_MALGANIS_SWARM_EVENTS);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    uint8 _retreatsCount;
    uint8 _carrionCount;
};

// 181399 - Kin'tessa
struct boss_lords_of_dread_kintessa : public LordsOfDreadAI
{
    struct boss_lords_of_dread_kintessa(Creature* creature) : LordsOfDreadAI(creature, DATA_KINTESSA), _essencesReturned(0), _swarmCount(0) { }

    static constexpr uint32 ResetConversations[] =
    {
        CONVERSATION_RESET_ENCOUNTER_01,
        CONVERSATION_RESET_ENCOUNTER_02,
        CONVERSATION_RESET_ENCOUNTER_03,
        CONVERSATION_RESET_ENCOUNTER_04,
        CONVERSATION_RESET_ENCOUNTER_05,
        CONVERSATION_RESET_ENCOUNTER_06
    };

    void StartRandomResetConversation()
    {
        int randomConversation = Trinity::Containers::SelectRandomContainerElement(ResetConversations);
        Conversation::CreateConversation(randomConversation, me, me->GetPosition(), ObjectGuid::Empty, nullptr, true);
    }

    void JustAppeared() override
    {
        LordsOfDreadAI::JustAppeared();

        DoCastSelf(SPELL_DARKNESS_OVERRIDE);
    }

    void Reset() override
    {
        LordsOfDreadAI::Reset();

        _swarmCount = 0;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        StartRandomResetConversation();

        LordsOfDreadAI::EnterEvadeMode(why);
    }

    void JustEngagedWith(Unit* who) override
    {
        DoCastSelf(SPELL_DARKNESS_ENERGY, true);

        events.ScheduleEvent(EVENT_ANGUISHING_STRIKE, 8500ms);
        events.ScheduleEvent(EVENT_SLUMBER_CLOUD, 13s);
        events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION, 25100ms);
        events.ScheduleEvent(EVENT_INFILTRATION_OF_DREAD, 124s);

        LordsOfDreadAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_KINTESSA_DEATH);

        LordsOfDreadAI::JustDied(killer);
    }

    void ScheduleKintessaEventsAfterParanoia()
    {
        events.ScheduleEvent(EVENT_ANGUISHING_STRIKE, 8s);
        events.ScheduleEvent(EVENT_SLUMBER_CLOUD, 5s);
        events.ScheduleEvent(EVENT_INFILTRATION_OF_DREAD, 126s);
        events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION, 10700ms);

        if (IsMythic())
            events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION, 9500ms);
        else
            events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 10s);
    }

    void CancelKintessaEvents()
    {
        events.CancelEvent(EVENT_ANGUISHING_STRIKE);
        events.CancelEvent(EVENT_SLUMBER_CLOUD);
        events.CancelEvent(EVENT_INFILTRATION_OF_DREAD);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRODUCTION:
            {
                Conversation::CreateConversation(CONVERSATION_INTRODUCTION, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                break;
            }
            case ACTION_MIMICKING_DISGUISE:
            {
                for (uint8 i = 0; i < 14; i++)
                {
                    scheduler.Schedule(Milliseconds(i * 250), [this, i](TaskContext /*task*/)
                    {
                        me->CastSpell(KintessaVisuals[i], SPELL_MIMICKING_DISGUISE_VISUALS, true);
                    });
                }
                break;
            }
            case ACTION_KINTESSA_SWARM_EVENTS:
            {
                _swarmCount++;
                me->InterruptNonMeleeSpells(true);
                me->AttackStop();
                DoCastSelf(SPELL_SWARM_OF_DARKNESS);
                events.CancelEvent(EVENT_ANGUISHING_STRIKE);
                events.CancelEvent(EVENT_FEARFUL_TREPIDATION);
                events.CancelEvent(EVENT_SLUMBER_CLOUD);

                events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION, 28s);
                events.ScheduleEvent(EVENT_MANIFEST_SHADOWS, 29s);
                events.ScheduleEvent(EVENT_SLUMBER_CLOUD, 49s);
                break;
            }
            case ACTION_PARANOIA:
            {
                scheduler.Schedule(2s, [this](TaskContext /*task*/)
                {
                    std::unordered_map<ObjectGuid /*player*/, uint32 /*spell*/> _spellAssignments;
                    int8 momentOfClaritytargets = 3;
                    int8 realDreadLordsImposters = 2;
                    int8 fakeDreadLordsImposters = 2;

                    std::list<Player*> allPlayers;
                    GetPlayerListInGrid(allPlayers, me, 100.0f);
                    if (allPlayers.size() <= 0) //Testing purposes
                    {
                        DoCastAOE(SPELL_FEEDBACK);
                        me->RemoveAurasDueToSpell(SPELL_INFILTRATION_DISAPPEAR);
                        if (Creature* malganis = instance->GetCreature(DATA_MALGANIS))
                            malganis->RemoveAurasDueToSpell(SPELL_INFILTRATION_DISAPPEAR);
                    }

                    Trinity::Containers::RandomResize(allPlayers, 2);
                    for (Player* target : allPlayers)
                    {
                        if (realDreadLordsImposters > 0)
                        {
                            _spellAssignments[target->GetGUID()] = realDreadLordsImposters == 2 ? SPELL_MALGANIS_IMPOSTER_REAL : SPELL_KINTESSA_IMPOSTER_REAL;
                            realDreadLordsImposters--;
                        }
                        else if (fakeDreadLordsImposters > 0)
                        {
                            _spellAssignments[target->GetGUID()] = fakeDreadLordsImposters == 2 ? SPELL_MALGANIS_IMPOSTER_FAKE : SPELL_KINTESSA_IMPOSTER_FAKE;
                            fakeDreadLordsImposters--;
                        }
                        else if (momentOfClaritytargets > 0)
                        {
                            // TODO: Moment of clarity must be capped to 3 regardless of raid size
                            _spellAssignments[target->GetGUID()] = SPELL_MOMENT_OF_CLARITY;
                            momentOfClaritytargets--;
                        }

                        uint32* spellId = Trinity::Containers::MapGetValuePtr(_spellAssignments, target->GetGUID());
                        target->CastSpell(target, *spellId, true);
                    }
                });
                break;
            }
            case ACTION_KINTESSA_PARANOIA_EVENTS:
            {
                events.ScheduleEvent(EVENT_SLUMBER_CLOUD, 5s);
                events.ScheduleEvent(EVENT_ANGUISHING_STRIKE, 7800ms);
                events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION, 11s);
                break;
            }
            case ACTION_KINTESSA_RETURNED_ESSENCE:
            {
                _essencesReturned++;
                if (_essencesReturned == 2)
                {
                    ForDreadlords(instance, [](Creature* dreadlord)
                    {
                        dreadlord->RemoveAurasDueToSpell(SPELL_INFILTRATION_DISAPPEAR);
                    });
                }
                break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        LordsOfDreadAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENRAGE:
                {
                    DoCastSelf(SPELL_BERSERK, true);
                    Talk(SAY_KINTESSA_ANNOUNCE_ENRAGE);
                    Talk(SAY_KINTESSA_ENRAGE);
                    break;
                }
                case EVENT_ANGUISHING_STRIKE:
                {
                    DoCastVictim(SPELL_ANGUISHING_STRIKE);
                    events.Repeat(9s);
                    break;
                }
                case EVENT_SLUMBER_CLOUD:
                {
                    DoCastSelf(SPELL_SLUMBER_CLOUD);
                    events.Repeat(33s);
                    break;
                }
                case EVENT_FEARFUL_TREPIDATION:
                {
                    DoCastVictim(SPELL_FEARFUL_TREPIDATION, false);
                    Talk(SAY_FEARFUL_TREPIDATION);
                    if (_swarmCount == 1)
                        events.Repeat(30s);
                    break;
                }
                case EVENT_INFILTRATION_OF_DREAD:
                {
                    Creature* malganis = GetOtherDreadlord();
                    if (!malganis->IsAlive())
                        return;

                    Talk(SAY_INFILTRATION_OF_DREAD);
                    DoCastSelf(SPELL_INFILTRATION_OF_DREAD);
                    break;
                }
                default:
                    break;
            }
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    uint8 _essencesReturned;
    uint8 _swarmCount;
};

// 183138 - Inchoate Shadow
int32 constexpr CORPOREAL_SHADOW_NAME_OVERRIDE = 274;
struct npc_inchoate_shadow : public ScriptedAI
{
    npc_inchoate_shadow(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        SetCombatMovement(false);
        DoZoneInCombat();
        DoCastSelf(SPELL_RAVENOUS_HUNGER_PERIODIC);
        me->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (!IsLFR())
        {
            DoCastSelf(SPELL_INCOMPLETE_FORM);
            me->SetHealth(1);
        }
        if (IsMythic())
            DoCastSelf(SPELL_COALESCING_DARKNESS, true);
    }

    void HealReceived(Unit* /*healer*/, uint32& heal) override
    {
        if (me->HealthAbovePctHealed(100, heal))
        {
            me->RemoveAurasDueToSpell(SPELL_INCOMPLETE_FORM);
            me->RemoveAurasDueToSpell(SPELL_INCOMPLETE_FORM_AURA);
            me->SetSpellOverrideNameID(CORPOREAL_SHADOW_NAME_OVERRIDE);
            if (IsMythic())
                DoCastSelf(SPELL_FULLY_FORMED, true);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(1, damage) && me->HasAura(SPELL_INCOMPLETE_FORM) || me->HasAura(SPELL_INCOMPLETE_FORM_AURA))
            damage = 0;
    }
};

// 181925 - Slumber Cloud
struct npc_slumber_cloud : public ScriptedAI
{
    npc_slumber_cloud(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SLUMBER_CLOUD_AREATRIGGER, true);
        _scheduler.Schedule(3s, [this](TaskContext /*task*/)
        {
            me->GetMotionMaster()->MoveRandom(3);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 185154 - Overthrown Protector (Mal'Ganis)
struct npc_overthrown_protector_malganis : public ScriptedAI
{
    npc_overthrown_protector_malganis(Creature* creature) : ScriptedAI(creature), _malganisRetreated(false) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_GRAND_REVEAL_MALGANIS, true);
        _events.ScheduleEvent(EVENT_LEECHING_CLAWS_PROTECTOR, 10s);
        _events.ScheduleEvent(EVENT_CLOUD_OF_CARRION_PROTECTOR, 15s);
        _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            Talk(SAY_MALGANIS_COPY_AGGRO);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(90, damage) && _malganisRetreated == false)
        {
            _malganisRetreated = true;
            DoCastSelf(SPELL_SWARMING_RETREAT_CLEAR_DEBUFFS, true);
            DoCastSelf(SPELL_SWARMING_RETREAT);
            Talk(SAY_MALGANIS_COPY_RETREAT);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LEECHING_CLAWS_PROTECTOR:
                {
                    DoCastVictim(SPELL_LEECHING_CLAWS_PROTECTOR);
                    _events.Repeat(10s);
                    break;
                }
                case EVENT_CLOUD_OF_CARRION_PROTECTOR:
                {
                    DoCastSelf(SPELL_CLOUD_OF_CARRION_PROTECTOR);
                    _events.Repeat(5s, 10s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    bool _malganisRetreated;
    TaskScheduler _scheduler;
    EventMap _events;
};

// 185155 - Overthrown Protector (Kin'tessa)
struct npc_overthrown_protector_kintessa : public ScriptedAI
{
    npc_overthrown_protector_kintessa(Creature* creature) : ScriptedAI(creature), _kintessaRetreated(false) { }

    void JustAppeared() override
    {
        me->SetImmuneToAll(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_GRAND_REVEAL_KINTESSA, true);
        _events.ScheduleEvent(EVENT_ANGUISHING_STRIKE_PROTECTOR, Milliseconds(urand(8000, 10000)));
        _events.ScheduleEvent(EVENT_FEARFUL_TREPIDATION_PROTECTOR, Milliseconds(urand(15000, 20000)));
        me->SetObjectScale(2);
        _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            Talk(SAY_KINTESSA_COPY_AGGRO);
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(90, damage) && _kintessaRetreated == false)
        {
            _kintessaRetreated = true;
            DoCastSelf(SPELL_SWARMING_RETREAT_CLEAR_DEBUFFS, true);
            DoCastSelf(SPELL_SWARMING_RETREAT);
            Talk(SAY_KINTESSA_COPY_RETREAT);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ANGUISHING_STRIKE_PROTECTOR:
                {
                    DoCastVictim(SPELL_ANGUISHING_STRIKE_PROTECTOR);
                    _events.Repeat(10s, 12s);
                    break;
                }
                case EVENT_FEARFUL_TREPIDATION_PROTECTOR:
                {
                    DoCastSelf(SPELL_FEARFUL_TREPIDATION_PROTECTOR);
                    _events.Repeat(15s, 20s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    bool _kintessaRetreated;
    TaskScheduler _scheduler;
    EventMap _events;
};

// 366518 - Grand Reveal Mal'Ganis
// 366565 - Grand Reveal Kin'Tessa
int32 constexpr MALGANIS_OVERRIDE_NAME = 279;
int32 constexpr KINTESSA_OVERRIDE_NAME = 280;
class spell_lords_of_dread_grand_reveal : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (Creature* creature = target->ToCreature())
            if (creature->GetEntry() == NPC_OVERTHROWN_PROTECTOR_MALGANIS)
                target->SetSpellOverrideNameID(MALGANIS_OVERRIDE_NAME);
            else
                target->SetSpellOverrideNameID(KINTESSA_OVERRIDE_NAME);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_lords_of_dread_grand_reveal::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 366549 - Leeching Claws Malganis Imitation
class spell_malganis_imitation_leeching_claws : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_OPENED_VEINS_PROTECTOR, SPELL_LEECHING_CLAWS_HEAL_PROTECTOR, SPELL_LEECHING_CLAWS_PHYSICAL_DAMAGE_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (target->HasAura(SPELL_OPENED_VEINS_PROTECTOR))
            caster->CastSpell(caster, SPELL_LEECHING_CLAWS_HEAL_PROTECTOR, true);

        caster->CastSpell(target, SPELL_LEECHING_CLAWS_PHYSICAL_DAMAGE_PROTECTOR, true);
        caster->CastSpell(target, SPELL_OPENED_VEINS_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_imitation_leeching_claws::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366573 - Cloud of Carrion Malganis Imitation
class spell_malganis_imitation_cloud_of_carrion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLOUD_OF_CARRION_DEBUFF_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_CLOUD_OF_CARRION_DEBUFF_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_imitation_cloud_of_carrion::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366629 - Anguishing Strike Kintessa Imitation
class spell_kintessa_imitation_anguishing_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANGUISHING_STRIKE_PHYSICAL_DAMAGE_PROTECTOR, SPELL_ANGUISHING_STRIKE_DEBUFF_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, SPELL_ANGUISHING_STRIKE_PHYSICAL_DAMAGE_PROTECTOR, true);
        caster->CastSpell(target, SPELL_ANGUISHING_STRIKE_DEBUFF_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_imitation_anguishing_strike::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366633 - Fearful Trepidation Kintessa Imitation
class spell_kintessa_imitation_fearful_trepidation : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEARFUL_TREPIDATION_DEBUFF_PROTECTOR });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_FEARFUL_TREPIDATION_DEBUFF_PROTECTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_imitation_fearful_trepidation::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366559 - Swarming Retreat
class spell_lords_of_dread_swarming_retreat : public SpellScript
{
    void HandleAfterCast()
    {
        Creature* malganis = GetCaster()->GetInstanceScript()->GetCreature(DATA_MALGANIS);
        if (!malganis)
            return;
        malganis->GetAI()->DoAction(ACTION_OPEN_DOOR_TO_LORDS_OF_DREAD);
        GetCaster()->GetMotionMaster()->MovePoint(0, SwarmingRetreatPos);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_lords_of_dread_swarming_retreat::HandleAfterCast);
    }
};

// Custom AT 999999 - Lords of Dread Introduction
struct at_lords_of_dread_introduction : AreaTriggerAI
{
    at_lords_of_dread_introduction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()), _firstEntry(false) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        _firstEntry = true;
        if (Creature* kintessa = _instance->GetCreature(DATA_KINTESSA))
        {
            kintessa->GetAI()->DoAction(ACTION_START_INTRODUCTION);
        }
    }

private:
    InstanceScript* _instance;
    bool _firstEntry;
};

// 361117 - Lords of Dread Mimicking Disguise
class spell_lords_of_dread_mimicking_disguise : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MIMICKING_TRANSFORMATION_1,
            SPELL_MIMICKING_TRANSFORMATION_2,
            SPELL_MIMICKING_TRANSFORMATION_3,
            SPELL_MIMICKING_TRANSFORMATION_4,
            SPELL_MIMICKING_TRANSFORMATION_5,
            SPELL_MIMICKING_TRANSFORMATION_6,
            SPELL_MIMICKING_TRANSFORMATION_7,
            SPELL_MIMICKING_TRANSFORMATION_8,
            SPELL_MIMICKING_TRANSFORMATION_9,
            SPELL_MIMICKING_TRANSFORMATION_10,
            SPELL_MIMICKING_TRANSFORMATION_11,
            SPELL_MIMICKING_TRANSFORMATION_12,
            SPELL_MIMICKING_TRANSFORMATION_13,
            SPELL_MIMICKING_TRANSFORMATION_14
        });
    }

    static constexpr uint32 MimickingTransformations[] =
    {
        SPELL_MIMICKING_TRANSFORMATION_1,
        SPELL_MIMICKING_TRANSFORMATION_2,
        SPELL_MIMICKING_TRANSFORMATION_3,
        SPELL_MIMICKING_TRANSFORMATION_4,
        SPELL_MIMICKING_TRANSFORMATION_5,
        SPELL_MIMICKING_TRANSFORMATION_6,
        SPELL_MIMICKING_TRANSFORMATION_7,
        SPELL_MIMICKING_TRANSFORMATION_8,
        SPELL_MIMICKING_TRANSFORMATION_9,
        SPELL_MIMICKING_TRANSFORMATION_10,
        SPELL_MIMICKING_TRANSFORMATION_11,
        SPELL_MIMICKING_TRANSFORMATION_12,
        SPELL_MIMICKING_TRANSFORMATION_13,
        SPELL_MIMICKING_TRANSFORMATION_14
    };

    void OnPeriodic(AuraEffect const* aurEff)
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        Creature* creature = nullptr;

        if (aurEff->GetTickNumber() % 2 == 0)
            creature = instance->GetCreature(DATA_KINTESSA);
        else
            creature = instance->GetCreature(DATA_MALGANIS);

        if (!creature)
            return;

        uint32 chosenTransformation = Trinity::Containers::SelectRandomContainerElement(MimickingTransformations);
        creature->GetAI()->DoAction(ACTION_MIMICKING_DISGUISE);
        creature->CastSpell(creature, chosenTransformation);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lords_of_dread_mimicking_disguise::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 365624 - Lords of Dread Transformation Visuals
class spell_lords_of_dread_transformation_visuals : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_lords_of_dread_transformation_visuals::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 360166 - Lords of Dread Energy Regeneration
// 360167 - Lords of Dread Energy Regeneration
class spell_lords_of_dread_energy_regeneration : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SWARM_OF_DECAY, SPELL_INFILTRATION_DISAPPEAR });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();

        Creature* malganis = instance->GetCreature(DATA_MALGANIS);
        Creature* kintessa = instance->GetCreature(DATA_KINTESSA);

        if (!malganis || !kintessa)
            return;

        if (malganis->HasAura(SPELL_SWARM_OF_DECAY) || kintessa->HasAura(SPELL_INFILTRATION_DISAPPEAR))
            return;

        int32 malganisEnergy = malganis->GetPower(malganis->GetPowerType());
        int32 kintessaEnergy = kintessa->GetPower(kintessa->GetPowerType());

        if (malganisEnergy == 100 && kintessaEnergy == 50 || malganisEnergy == 50 && kintessaEnergy == 100)
            return;

        target->ModifyPower(target->GetPowerType(), 1);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lords_of_dread_energy_regeneration::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 359960 - Leeching Claws
class spell_malganis_leeching_claws : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_OPENED_VEINS, SPELL_LEECHING_CLAWS_HEAL, SPELL_LEECHING_CLAWS_PHYSICAL });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (target->HasAura(SPELL_OPENED_VEINS))
            caster->CastSpell(target, SPELL_LEECHING_CLAWS_HEAL, true);
        caster->CastSpell(target, SPELL_LEECHING_CLAWS_PHYSICAL, true);
        caster->CastSpell(target, SPELL_OPENED_VEINS, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_leeching_claws::HandleCast, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 360006 - Cloud of Carrion
class spell_malganis_cloud_of_carrion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLOUD_OF_CARRION_INITIAL_CIRCLE });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_CLOUD_OF_CARRION_INITIAL_CIRCLE, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 rangedDpsCount = 0;
        for (WorldObject* target : targets)
        {
            Player* targetPlayer = target->ToPlayer();
            if (!targetPlayer)
                continue;

            ChrSpecializationEntry const* spec = targetPlayer->GetPrimarySpecializationEntry();
            if (!spec)
                continue;

            if (!targetPlayer->IsAlive())
                continue;

            if ((spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Caster)) ||
                (spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Ranged)))
                rangedDpsCount++;
        }

        targets.remove_if([rangedDpsCount](WorldObject* target) -> bool
        {
            Player* player = target->ToPlayer();

            if (!player)
                return true;

            if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Tank)
                return true;

            if (rangedDpsCount >= 4)
            {
                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Dps && player->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Melee))
                    return true;

                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Healer)
                    return true;
            }
            return false;
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_cloud_of_carrion::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malganis_cloud_of_carrion::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 360189 - Cloud of Carrion Circle Initial
class spell_malganis_cloud_of_carrion_init : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_CLOUD_OF_CARRION_MISSILE,
            SPELL_CLOUD_OF_CARRION_PREVENT_TRANSFER,
            SPELL_AURA_OF_CARRION,
            SPELL_DECAY_MASTERY,
            SPELL_CLOUD_OF_CARRION_AREATRIGGER,
        });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* malganis = instance->GetCreature(DATA_MALGANIS);
        if (!malganis)
            return;

        caster->CastSpell(target, SPELL_CLOUD_OF_CARRION_MISSILE, true);
        caster->CastSpell(target, SPELL_CLOUD_OF_CARRION_PREVENT_TRANSFER, true);

        if (caster->GetMap()->IsMythic() && caster->HasAura(SPELL_AURA_OF_CARRION))
        {
            Aura* decayMastery = malganis->GetAura(SPELL_DECAY_MASTERY);
            uint8 decayMasteryStacks = decayMastery->GetStackAmount();

            if (!decayMastery || decayMasteryStacks <= 0)
                decayMasteryStacks = 0;

            uint8 totalWaves = _carrionWaves + decayMasteryStacks;

            float _angleOffset = float(M_PI * 2) / totalWaves;
            for (uint8 i = 0; i < totalWaves; i++)
            {
                float angle = caster->GetOrientation();
                float nextAngle = angle - _angleOffset * i;

                Position dest = { caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), nextAngle };
                target->CastSpell(dest, SPELL_CLOUD_OF_CARRION_AREATRIGGER, true);
            }
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            caster->CastSpell(target, SPELL_CLOUD_OF_CARRION_CIRCLE, true);
            caster->CastSpell(target, SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF, true);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_malganis_cloud_of_carrion_init::OnApply, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_malganis_cloud_of_carrion_init::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    uint8 _carrionWaves = 4;
};

// 360017 - Cloud of Carrion Circle
class spell_malganis_cloud_of_carrion_circle : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_CLOUD_OF_CARRION_DEBUFF_DAMAGE,
            SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF,
            SPELL_DECAY_MASTERY,
            SPELL_BURSTING_DREAD_IMMUNITY,
        });
    }
    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster)
            return;

        caster->CastSpell(target, SPELL_CLOUD_OF_CARRION_DEBUFF_DAMAGE, true);

        uint8 CurrentTick = aurEff->GetTickNumber();
        if (CurrentTick % 3 == 0)
            caster->CastSpell(target, SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* malganis = instance->GetCreature(DATA_MALGANIS);
        if (!malganis)
            return;

        switch (GetTargetApplication()->GetRemoveMode())
        {
            case AURA_REMOVE_BY_DEFAULT:
            {
                Aura* decayMastery = malganis->GetAura(SPELL_DECAY_MASTERY);

                uint8 decayMasteryStacks = 0;

                if (!decayMastery)
                    decayMasteryStacks = 0;
                else
                    decayMasteryStacks = decayMastery->GetStackAmount();

                Unit* target = GetTarget();
                target->RemoveAurasDueToSpell(SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF);
                target->CastSpell(target, SPELL_BURSTING_DREAD_IMMUNITY, true);

                switch (GetTarget()->GetMap()->GetDifficultyID())
                {
                    case DIFFICULTY_LFR_NEW:
                    case DIFFICULTY_NORMAL_RAID:
                        _carrionWaves = 2;
                        break;
                    case DIFFICULTY_HEROIC_RAID:
                        _carrionWaves = 4;
                        break;
                    case DIFFICULTY_MYTHIC_RAID:
                        _carrionWaves = uint32(6 + decayMasteryStacks);
                        break;
                    default:
                        _carrionWaves = 6;
                        break;
                }

                float _angleOffset = float(M_PI * 2) / _carrionWaves;
                for (uint8 i = 0; i < _carrionWaves; i++)
                {
                    float angle = target->GetOrientation();
                    float nextAngle = angle - _angleOffset * i;

                    Position dest = { target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), nextAngle };
                    target->CastSpell(dest, SPELL_CLOUD_OF_CARRION_AREATRIGGER, true);
                }
                break;
            }
            case AURA_REMOVE_BY_EXPIRE:
            case AURA_REMOVE_BY_DEATH:
                GetTarget()->RemoveAurasDueToSpell(SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF);
                break;
            default:
                return;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_malganis_cloud_of_carrion_circle::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_malganis_cloud_of_carrion_circle::OnRemove, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }

private:
    uint8 _carrionWaves = 0;
};

// 360015 - Cloud of Carrion Damage Debuff
class spell_malganis_cloud_of_carrion_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Aura* carrionAura = target->GetAura(SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF);
        if (!carrionAura)
            return;

        uint8 carrionAuraStacks = carrionAura->GetStackAmount();
        double damageMultiplier = 1.0;

        for (uint8 i = 1; i < carrionAuraStacks; i++)
            damageMultiplier *= 1.15;

        SetHitDamage(GetHitDamage() * damageMultiplier);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_cloud_of_carrion_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 24063 - Cloud of Carrion AT
struct at_malganis_cloud_of_carrion : public AreaTriggerAI
{
    at_malganis_cloud_of_carrion(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || unit->HasAura(SPELL_CLOUD_OF_CARRION_PREVENT_TRANSFER) || unit->HasAura(SPELL_BURSTING_DREAD_IMMUNITY))
            return;

        if (Creature* Malganis = _instance->GetCreature(DATA_MALGANIS))
        {
            Malganis->CastSpell(unit, SPELL_CLOUD_OF_CARRION_AREATRIGGER_DEBUFF);
        }
    }

private:
    InstanceScript* _instance;
};

// Cloud of Carrion waves
struct at_malganis_cloud_of_carrion_puddle : AreaTriggerAI
{
    at_malganis_cloud_of_carrion_puddle(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
        {
            Position originPos = at->GetPosition();

            float carrionWave = 100.0f;

            Position destPos(originPos.GetPositionX() + (std::cos(originPos.GetOrientation()) * carrionWave), originPos.GetPositionY() + (std::sin(originPos.GetOrientation()) * carrionWave), originPos.GetPositionZ());

            _lastPointPos = destPos.GetPosition();

            Movement::PointsArray carrionWaveSpliePoints;

            carrionWaveSpliePoints.push_back(PositionToVector3(at));
            carrionWaveSpliePoints.push_back(PositionToVector3(destPos));

            at->InitSplines(carrionWaveSpliePoints, uint32(at->GetDistance(destPos) * 180));
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer() || unit->HasAura(SPELL_BURSTING_DREAD_IMMUNITY))
            return;

        Creature* malganis = _instance->GetCreature(DATA_MALGANIS);
        if (!malganis)
            return;

        Position currentPos = at->GetPosition();

        malganis->CastSpell(unit, SPELL_CLOUD_OF_CARRION_CIRCLE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;
    }

private:
    InstanceScript* _instance;
    Position _lastPointPos;
};

// 361913 - Manifest Shadows
class spell_malganis_manifest_shadows : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MANIFEST_SHADOWS_SUMMONING });
    }

    void HandleSummoning(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MANIFEST_SHADOWS_SUMMONING, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 rangedDpsCount = 0;
        for (WorldObject* target : targets)
        {
            Player* targetPlayer = target->ToPlayer();
            if (!targetPlayer)
                continue;

            ChrSpecializationEntry const* spec = targetPlayer->GetPrimarySpecializationEntry();
            if (!spec)
                continue;

            if (!targetPlayer->IsAlive())
                continue;

            if ((spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Caster)) ||
                (spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Ranged)))
                rangedDpsCount++;
        }

        targets.remove_if([rangedDpsCount](WorldObject* target) -> bool
        {
            Player* player = target->ToPlayer();
            if (!player)
                return true;

            if (rangedDpsCount >= 1)
            {
                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Tank)
                    return true;

                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Dps && player->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Melee))
                    return true;

                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Healer)
                    return true;
            }
            return false;
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_malganis_manifest_shadows::HandleSummoning, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_malganis_manifest_shadows::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 361935 - Ravenous Hunger Periodic
class spell_inchoate_shadow_ravenous_hunger_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RAVENOUS_HUNGER });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_RAVENOUS_HUNGER);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_inchoate_shadow_ravenous_hunger_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 360300 - Swarm of Decay
class spell_malganis_swarm_of_decay : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE_VEHICLE_HARDCODED, SPELL_UNTO_DARKNESS_DARKEN_ENVIRONMENT });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* malganis = instance->GetCreature(DATA_MALGANIS);
        Creature* kintessa = instance->GetCreature(DATA_KINTESSA);

        if (!malganis || !kintessa)
            return;

        if (Creature* creature = caster->ToCreature())
        {
            if (CreatureAI* malganisAI = creature->AI())
            {
                malganisAI->Talk(SAY_SWARM_OF_DECAY);
                malganisAI->Talk(SAY_SWARM_OF_DECAY_ANNOUNCE);
            }
        }

        malganis->SummonCreature(NPC_SWARM_OF_SHADOWS, caster->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        malganis->GetAI()->DoAction(ACTION_MALGANIS_SWARM_EVENTS);

        if (Creature* kintessa = GetCaster()->GetInstanceScript()->GetCreature(DATA_KINTESSA))
            kintessa->GetAI()->DoAction(ACTION_KINTESSA_SWARM_EVENTS);

    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* malganis = instance->GetCreature(DATA_MALGANIS);
        if (!malganis)
            return;

        Unit* swarmOfShadows = caster->FindNearestCreature(NPC_SWARM_OF_SHADOWS, 20.0f, true);
        if (!swarmOfShadows)
            return;

        swarmOfShadows->GetMotionMaster()->MoveRotate(2, ROTATE_DIRECTION_RIGHT, 30s);

        malganis->CastSpell(swarmOfShadows, SPELL_RIDE_VEHICLE_HARDCODED, true);
        malganis->CastSpell(malganis, SPELL_UNTO_DARKNESS_DARKEN_ENVIRONMENT, true);
        malganis->SetPower(malganis->GetPowerType(), 0);
        if (Creature* kintessa = caster->GetInstanceScript()->GetCreature(DATA_KINTESSA))
            kintessa->CastSpell(swarmOfShadows, SPELL_RIDE_VEHICLE_HARDCODED, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_malganis_swarm_of_decay::HandleAfterCast);
    }
};

class spell_malganis_swarm_of_decay_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DECAY_MASTERY, SPELL_AURA_OF_CARRION });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* malganis = instance->GetCreature(DATA_MALGANIS))
        {
            if (Unit* swarmOfShadows = GetTarget()->FindNearestCreature(NPC_SWARM_OF_SHADOWS, 30.0f, true))
                swarmOfShadows->ToCreature()->DespawnOrUnsummon();

            if (malganis->GetMap()->IsHeroicOrHigher())
                malganis->CastSpell(malganis, SPELL_DECAY_MASTERY, true);
            if (malganis->GetMap()->IsMythic())
            {
                malganis->CastSpell(malganis, SPELL_AURA_OF_CARRION, true);
                malganis->AI()->Talk(SAY_MALGANIS_ANNOUNCE_AURA_OF_CARRION);
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_malganis_swarm_of_decay_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 360284 - Anguishing Strike
class spell_kintessa_anguishing_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANGUISHING_STRIKE_PHYSICAL, SPELL_ANGUISHING_STRIKE_DEBUFF });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, SPELL_ANGUISHING_STRIKE_PHYSICAL, true);
        caster->CastSpell(target, SPELL_ANGUISHING_STRIKE_DEBUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_anguishing_strike::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 360287 - Anguishing Strike Periodic
class spell_kintessa_anguishing_strike_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANGUISHING_STRIKE_DEBUFF_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster())
            return;

        GetCaster()->CastSpell(GetTarget(), SPELL_ANGUISHING_STRIKE_DEBUFF_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kintessa_anguishing_strike_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 360288 - Anguishing Strike Damage Modification
struct spell_kintessa_anguishing_strike_debuff_damage : SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANGUISHING_STRIKE_DEBUFF });
    }

    void ModifyDamage(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster())
            return;

        Aura* anguishingStrikes = GetHitUnit()->GetAura(SPELL_ANGUISHING_STRIKE_DEBUFF);
        if (!anguishingStrikes)
            return;

        uint8 anguishingStacks = anguishingStrikes->GetStackAmount();

        SetHitDamage(int32(GetHitDamage() * anguishingStacks));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_anguishing_strike_debuff_damage::ModifyDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 360229 - Slumber Cloud
class spell_kintessa_slumber_cloud : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SLUMBER_CLOUD_MISSILE });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SLUMBER_CLOUD_MISSILE, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 rangedDpsCount = 0;
        for (WorldObject* target : targets)
        {
            Player* targetPlayer = target->ToPlayer();
            if (!targetPlayer)
                continue;

            ChrSpecializationEntry const* spec = targetPlayer->GetPrimarySpecializationEntry();
            if (!spec)
                continue;

            if (!targetPlayer->IsAlive())
                continue;

            if ((spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Caster)) ||
                (spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Ranged)))
                rangedDpsCount++;
        }

        targets.remove_if([rangedDpsCount](WorldObject* target) -> bool
        {
            Player* player = target->ToPlayer();
            if (!player)
                return true;

            if (rangedDpsCount >= 2)
            {
                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Tank)
                    return true;

                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Dps && player->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Melee))
                    return true;

                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Healer)
                    return true;
            }
            return false;
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_slumber_cloud::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kintessa_slumber_cloud::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 23805 - Slumber Cloud AT
struct at_kintessa_slumber_cloud : AreaTriggerAI
{
    at_kintessa_slumber_cloud(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(500ms, [this](TaskContext task)
        {
            float startRadius = 1.0f;
            float targetRadius = 1.0f;

            UpdateSize(startRadius, targetRadius);
            at->SetTimeToTargetScale(3000);

            task.Schedule(Milliseconds(5000), [this](TaskContext task)
            {
                UpdateSizeBasedOnInfiltration();
                task.Repeat(Milliseconds(10000));
            });
        });
    }

    void OnUpdate(uint32 diff) override
    {
        if (!_instance)
            return;

        _scheduler.Update(diff);

    }

    void UpdateSize(float radius, float targetRadius)
    {
        _radius = radius;
        _targetRadius = targetRadius;

        std::array<DBCPosition2D, 2> points =
        { {
            { 0.0f, radius },
            { 1.0f, targetRadius }
        } };

        at->SetOverrideScaleCurve(at->GetTimeSinceCreated());
        at->SetOverrideScaleCurve(points);
    }

    void UpdateSizeBasedOnInfiltration()
    {
        Creature* kintessa = _instance->GetCreature(DATA_KINTESSA);
        if (!kintessa)
            return;

        Aura* shadowMastery = kintessa->GetAura(SPELL_SHADOW_MASTERY);
        if (!shadowMastery)
            return;

        uint8 shadowMasteryStacks = shadowMastery->GetStackAmount();
        float oldRadius = _radius;
        float newRadius = 1.0f + (0.25f * shadowMasteryStacks);

        if (G3D::fuzzyEq(oldRadius, newRadius))
            return;

        UpdateSize(oldRadius, newRadius);

        _scheduler.Schedule(5000ms, [this, newRadius](TaskContext task)
        {
            UpdateSize(newRadius, newRadius);
        });
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->AddAura(SPELL_UNSETTLING_DREAMS, unit);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    float _radius = 0;
    float _targetRadius = 0;
};

// 360145 - Fearful Trepidation
class spell_kintessa_fearful_trepidation : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FEARFUL_TREPIDATION_CIRCLE });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_FEARFUL_TREPIDATION_CIRCLE, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target) -> bool
        {
            Player* player = target->ToPlayer();
            if (!player)
                return true;

            ChrSpecializationEntry const* spec = player->GetPrimarySpecializationEntry();
            if (!spec)
                return true;

            if (!player->IsAlive())
                return true;

            if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Tank)
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_fearful_trepidation::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kintessa_fearful_trepidation::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 360146 - Fearful Trepidation Debuff
class spell_kintessa_fearful_trepidation_debuff : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURSTING_DREAD_FEAR, SPELL_CLOUD_OF_CARRION_CIRCLE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster)
            return;

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BURSTING_DREAD_FEAR, caster->GetMap()->GetDifficultyID()))
            _radius = spellInfo->GetEffect(EFFECT_0).CalcValue();

        std::list<Player*> playerList;
        target->GetPlayerListInGrid(playerList, _radius);

        for (Player* playersInRadius : playerList)
        {
            if (playersInRadius->HasAura(SPELL_CLOUD_OF_CARRION_CIRCLE))
                playersInRadius->RemoveAura(SPELL_CLOUD_OF_CARRION_CIRCLE);
            else
                playersInRadius->CastSpell(playersInRadius, SPELL_BURSTING_DREAD_FEAR, true);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kintessa_fearful_trepidation_debuff::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    float _radius = 0;
};

// 360717 - Infiltration of Dread Cast
class spell_infiltration_of_dread_cast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFILTRATION_DISAPPEAR, SPELL_INFILTRATION_OF_DREAD_KINTESSA });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();
        if (caster->GetEntry() == BOSS_KINTESSA)
        {
            if (Creature* creature = caster->ToCreature())
            {
                if (CreatureAI* kintessaAI = creature->AI())
                {
                    kintessaAI->Talk(SAY_ANNOUNCE_INFILTRATION_OF_DREAD);
                    kintessaAI->Talk(SAY_INFILTRATION_OF_DREAD);
                }
            }

            InstanceScript* instance = caster->GetInstanceScript();
            if (!instance)
                return;

            Creature* malganis = instance->GetCreature(DATA_MALGANIS);
            if (!malganis)
                return;
            malganis->GetAI()->DoAction(ACTION_MALGANIS_INFILTRATION_OF_DREAD);
        }
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_INFILTRATION_DISAPPEAR, true);
        if (GetCaster()->GetEntry() == BOSS_KINTESSA)
            GetCaster()->CastSpell(GetCaster(), SPELL_INFILTRATION_OF_DREAD_KINTESSA, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_infiltration_of_dread_cast::HandleAfterCast);
    }
};

// 360417 - Infiltration of Dread
class spell_kintessa_infiltration_of_dread : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFILTRATION_PULL, SPELL_PARANOIA });
    }

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, SPELL_INFILTRATION_PULL, true);
        caster->CastSpell(target, SPELL_PARANOIA, true);

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* kintessa = instance->GetCreature(DATA_KINTESSA))
            kintessa->GetAI()->DoAction(ACTION_PARANOIA);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target) -> bool
        {
            if (!target->IsPlayer())
                return true;
            return false;
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kintessa_infiltration_of_dread::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kintessa_infiltration_of_dread::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }

private:
    TaskScheduler _scheduler;
};

// 360418 - Paranoia
class spell_infiltration_of_dread_paranoia : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLOUD_OF_CARRION_CIRCLE });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUnitFlag(UNIT_FLAG_PVP_ENABLING);
        GetTarget()->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
        GetTarget()->SetUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION);
        GetTarget()->SetPvpFlag(UNIT_BYTE2_FLAG_UNK1);
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        amount = 0;
        canBeRecalculated = true;
    }

    void Trigger(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_CLOUD_OF_CARRION_CIRCLE, GetCaster()->GetMap()->GetDifficultyID());
        if (dmgInfo.GetSpellInfo() != spellInfo)
            return;
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_infiltration_of_dread_paranoia::OnApply, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_infiltration_of_dread_paranoia::Trigger, EFFECT_0);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_infiltration_of_dread_paranoia::CalculateAmount, EFFECT_3, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// 360496 - Infiltration Mal'Ganis
// 360498 - Infiltration Kin'Tessa
class spell_lords_of_dread_infiltration : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {   SPELL_STRENGTH_OF_MIND_IMPOSTER,
            SPELL_MALGANIS_IMPOSTER_REAL,
            SPELL_INFILTRATION_RETURN_TO_MALGANIS,
            SPELL_INFILTRATION_RETURN_TO_KINTESSA
        });
    }

public:
    bool Load() override
    {
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        amount = 0;
        canBeRecalculated = true;
    }

    void Trigger(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();

        if (dmgInfo.GetDamage() <= target->GetHealth())
            return;

        if (dmgInfo.GetDamage() >= target->GetHealth())
        {
            absorbAmount = dmgInfo.GetDamage();
            if (_triggered)
                return;

            target->SetHealth((target->GetMaxHealth() / 2));
            target->CastSpell(target, SPELL_STRENGTH_OF_MIND_IMPOSTER, true);
            if (target->HasAura(SPELL_MALGANIS_IMPOSTER_REAL))
                target->CastSpell(target, SPELL_INFILTRATION_RETURN_TO_MALGANIS);
            else
                target->CastSpell(target, SPELL_INFILTRATION_RETURN_TO_KINTESSA);
            _triggered = true;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_lords_of_dread_infiltration::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_lords_of_dread_infiltration::Trigger, EFFECT_0);
    }

private:
    bool _triggered = false;
};

// 360516 - Infiltration of Dread Disappear
class spell_lords_of_dread_disappear : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_MASTERY, SPELL_AURA_OF_SHADOWS, SPELL_PARANOIA });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        Creature* kintessa = instance->GetCreature(DATA_KINTESSA);
        Creature* malganis = instance->GetCreature(DATA_MALGANIS);

        if (!kintessa || !malganis)
            return;

        if (target->GetMap()->IsHeroicOrHigher())
        {
            if (target->GetEntry() == BOSS_KINTESSA)
                target->CastSpell(target, SPELL_SHADOW_MASTERY, true);
        }

        if (target->GetMap()->IsMythic() && target == kintessa)
        {
            kintessa->CastSpell(kintessa, SPELL_AURA_OF_SHADOWS);
            kintessa->AI()->Talk(SAY_KINTESSA_ANNOUNCE_AURA_OF_SHADOWS);
        }

        // TODO both dreadlords must have their auras removed
        switch (GetTargetApplication()->GetRemoveMode())
        {
            case AURA_REMOVE_BY_ENEMY_SPELL:
            case AURA_REMOVE_BY_DEFAULT:
            {
                if (target->GetEntry() == BOSS_KINTESSA)
                {
                    target->GetAI()->DoAction(ACTION_KINTESSA_PARANOIA_EVENTS);
                }

                else if (target->GetEntry() == BOSS_MALGANIS)
                {
                    target->GetAI()->DoAction(ACTION_MALGANIS_PARANOIA_EVENTS);
                }
                target->GetInstanceScript()->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARANOIA);
                break;
            }
            case AURA_REMOVE_BY_EXPIRE:
            {
                target->CastSpell(target, SPELL_SHATTER_MIND, true);
                if (target->GetEntry() == BOSS_KINTESSA)
                {
                    target->GetAI()->DoAction(ACTION_KINTESSA_PARANOIA_EVENTS);
                }

                else if (target->GetEntry() == BOSS_MALGANIS)
                {
                    target->GetAI()->DoAction(ACTION_MALGANIS_PARANOIA_EVENTS);
                }
                target->GetInstanceScript()->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARANOIA);
                break;
            }
            default:
                return;
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_lords_of_dread_disappear::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 360601 - Return to Malganis
// 360602 - Return to Kintessa
class spell_lords_of_dread_return_essence : public SpellScript
{
    void HandleAfterCast()
    {
        Creature* kintessa = GetCaster()->GetInstanceScript()->GetCreature(DATA_KINTESSA);
        if (!kintessa)
            return;

        kintessa->GetAI()->DoAction(ACTION_KINTESSA_RETURNED_ESSENCE);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_lords_of_dread_return_essence::HandleAfterCast);
    }
};

// 363191 - Aura of Shadows AT 24126
struct at_kintessa_aura_of_shadows : AreaTriggerAI
{
    at_kintessa_aura_of_shadows(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            for (ObjectGuid const& guid : at->GetInsideUnits())
            {
                Player* player = ObjectAccessor::GetPlayer(*at, guid);
                if (!player)
                    continue;

                uint8 playersInRange = 0;
                for (ObjectGuid const& otherGuid : at->GetInsideUnits())
                {
                    if (guid == otherGuid)
                        continue;

                    Player* otherPlayer = ObjectAccessor::GetPlayer(*at, otherGuid);
                    if (!otherPlayer)
                        continue;

                    if (player->GetDistance(otherPlayer) > 10.0f)
                        continue;

                    playersInRange++;
                }

                if (playersInRange > 0)
                    player->RemoveAurasDueToSpell(SPELL_HORRIFYING_SHADOWS);
                else if (!player->HasAura(SPELL_HORRIFYING_SHADOWS))
                    player->CastSpell(player, SPELL_HORRIFYING_SHADOWS);
            }
            task.Repeat(500ms);
        });
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 363232 - Horriying Shadows Aura
class spell_kintessa_horrifying_shadows_aura_players : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HORRIFYING_SHADOWS_FEAR });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            GetTarget()->CastSpell(GetTarget(), SPELL_HORRIFYING_SHADOWS_FEAR, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kintessa_horrifying_shadows_aura_players::OnRemove, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 363235 - Horrifying Shadows Players
struct at_kintessa_horrifying_shadows : AreaTriggerAI
{
    at_kintessa_horrifying_shadows(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(500ms, [this](TaskContext task)
        {
            for (ObjectGuid const& guid : at->GetInsideUnits())
            {
                Player* player = ObjectAccessor::GetPlayer(*at, guid);
                if (!player)
                    continue;
                if (at->GetInsideUnits().size() >= 1)
                    player->RemoveAurasDueToSpell(SPELL_HORRIFYING_SHADOWS);
            }
        });
    }

    void OnUpdate(uint32 diff)
    {
        _scheduler.Update(diff);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || unit->GetGUID() == at->GetCaster()->GetGUID())
            return;

        if (at->GetInsideUnits().size() <= 1)
            unit->CastSpell(unit, SPELL_HORRIFYING_SHADOWS, true);
        else
            at->GetCaster()->RemoveAurasDueToSpell(SPELL_HORRIFYING_SHADOWS_FEAR);
    }
private:
    TaskScheduler _scheduler;

};

void AddSC_boss_lords_of_dread()
{
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_overthrown_protector_malganis);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_overthrown_protector_kintessa);
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_lords_of_dread_mal_ganis);
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_lords_of_dread_kintessa);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_inchoate_shadow);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_slumber_cloud);

    RegisterSpellScript(spell_lords_of_dread_grand_reveal);
    RegisterSpellScript(spell_malganis_imitation_leeching_claws);
    RegisterSpellScript(spell_malganis_imitation_cloud_of_carrion);
    RegisterSpellScript(spell_kintessa_imitation_anguishing_strike);
    RegisterSpellScript(spell_kintessa_imitation_fearful_trepidation);
    RegisterSpellScript(spell_lords_of_dread_swarming_retreat);

    RegisterAreaTriggerAI(at_lords_of_dread_introduction);
    RegisterSpellScript(spell_lords_of_dread_mimicking_disguise);
    RegisterSpellScript(spell_lords_of_dread_transformation_visuals);
    RegisterSpellScript(spell_lords_of_dread_energy_regeneration);
    RegisterSpellScript(spell_malganis_leeching_claws);
    RegisterSpellScript(spell_malganis_cloud_of_carrion);
    RegisterSpellScript(spell_malganis_cloud_of_carrion_init);
    RegisterSpellScript(spell_malganis_cloud_of_carrion_circle);
    RegisterSpellScript(spell_malganis_cloud_of_carrion_damage);
    RegisterAreaTriggerAI(at_malganis_cloud_of_carrion);
    RegisterAreaTriggerAI(at_malganis_cloud_of_carrion_puddle);
    RegisterSpellScript(spell_malganis_manifest_shadows);
    RegisterSpellScript(spell_inchoate_shadow_ravenous_hunger_periodic);
    RegisterSpellAndAuraScriptPair(spell_malganis_swarm_of_decay, spell_malganis_swarm_of_decay_aura);

    // Kin'tessa
    RegisterSpellScript(spell_kintessa_anguishing_strike);
    RegisterSpellScript(spell_kintessa_anguishing_strike_periodic);
    RegisterSpellScript(spell_kintessa_anguishing_strike_debuff_damage);

    RegisterSpellScript(spell_kintessa_slumber_cloud);
    RegisterAreaTriggerAI(at_kintessa_slumber_cloud);

    RegisterSpellScript(spell_kintessa_fearful_trepidation);
    RegisterSpellScript(spell_kintessa_fearful_trepidation_debuff);
    RegisterSpellScript(spell_infiltration_of_dread_cast);
    RegisterSpellScript(spell_kintessa_infiltration_of_dread);
    RegisterSpellScript(spell_infiltration_of_dread_paranoia);
    RegisterSpellScript(spell_lords_of_dread_infiltration);
    RegisterAreaTriggerAI(at_kintessa_aura_of_shadows);
    RegisterSpellScript(spell_kintessa_horrifying_shadows_aura_players);
    RegisterSpellScript(spell_lords_of_dread_disappear);
    RegisterSpellScript(spell_lords_of_dread_return_essence);
    RegisterAreaTriggerAI(at_kintessa_horrifying_shadows);
}
