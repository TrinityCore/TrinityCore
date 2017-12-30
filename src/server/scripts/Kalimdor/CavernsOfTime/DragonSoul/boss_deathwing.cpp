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
SDName: boss_deathwing
Author: Bennu
SD%Complete: 80%
SDComment: Needs tests , missing Hero mode
SDCategory: Boss Deathwing
EndScriptData
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "dragon_soul.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "Map.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

#define TRALL_MENU "Inconceivable! He couldn't possibly be alive!"

enum Events
{
    // Deathwing
    EVENT_ASSAULT_ASPECTS = 1,
    EVENT_CATACLYSM,
    EVENT_CORRUPTING_PARASITE,
    EVENT_ELEMENTIUM_BOLT,
    EVENT_ASSAULT_ALEXSTRASZA,
    EVENT_ASSAULT_NOZDORMU,
    EVENT_ASSAULT_YSERA,
    EVENT_ASSAULT_KALECGOS,
    EVENT_ENRAGE,
    EVENT_DIE,

    //tentacle
    EVENT_HEMORRHAGE,
    EVENT_BURNING_BLOOD,

    // Mutated Corruption
    EVENT_IMPALE,
    EVENT_CRUSH,
    EVENT_CRUSH_DAMAGE,

    //other
    EVENT_INCREASE_ENERGY,
    EVENT_CAUTERIZE,
    EVENT_TIME_ZONE,
    EVENT_SUMMON,
    EVENT_SUMMON_1,
    ATTACK_START,

    //Phase
    PHASE_1,
    PHASE_2,

    //Phase 2
    EVENT_ELEMENTIUM_FRAGMENT,
    EVENT_ELEMENTIUM_TERROR,
    EVENT_CORRUPTED_BLOOD,
    EVENT_CONGEALING_BLOOD,

    //Phase 2 mob events
    EVENT_SHRAPNEL,
    EVENT_TETANUS,
    EVENT_CONGEALING_BLOOD_CAST,

    //trall
    EVENT_SAY_TRALL_START,
    EVENT_SAY_TRALL_1,

    EVENT_PROVA // Bennu's stuff
};

enum AnimKits
{
    // Deathwing
    ANIM_KIT_FALL_FORWARD = 1537,
};

enum Actions
{
    ACTION_ALEXS                = 0,
    ACTION_NOZDORMU             = 1,
    ACTION_YSERA                = 2,
    ACTION_KALECGOS             = 3,
    ACTION_PLATFORM_DONE        = 4,
    ACTION_TIME_ZONE            = 5,
    ACTION_ENCOUNTER_START      = 6,
    ACTION_TIME_ZONE_PHASE_2    = 7,
    ACTION_PHASE_2              = 8,
    ACTION_CATACLYSM            = 9,
};

enum Spells
{
    //DeathWing
    SPELL_ASSAULT_ASPECTS               = 107018,
    SPELL_CATACLYSM                     = 106523,
    SPELL_CATACLYSM_AURA                = 106527,
    SPELL_ELEMENTIUM_BOLT               = 105651,
    SPELL_ELEMENTIUM_METEOR_VOID        = 106242,
    SPELL_ELEMENTIUM_BLAST_IMPACT       = 105723,
    SPELL_ELEMENTUM_BLAST_PERIODIC      = 110628,
    SPELL_BERSERK                       = 64238,
    SPELL_CORRUPTING_PARASITE           = 108597,
    SPELL_CORRUPTING_PARASITE_VEHICLE   = 108649,
    SPELL_CORRUPTING_PARASITE_DAMAGE    = 108601,
    SPELL_CONGEALING_BLOOD_SUMMON       = 109089,
    SPELL_CONGEALING_BLOOD_HEAL         = 109102,

    // Mutated corruption
    SPELL_IMPALE                        = 106400,
    SPELL_IMPALE_ASPECT                 = 107029,
    SPELL_CRUSH                         = 106382,
    SPELL_CRUSH_DAMAGE                  = 106385,

    // tentacle
    SPELL_BURNING_BLOOD                 = 105401,
    SPELL_BURNING_BLOOD_DAMAGE          = 105408,
    SPELL_AGONUZUNG_PAIN                = 106548,
    SPELL_HEMORRHAGE_SUMMON             = 105853,
    SPELL_HEMORRHAGE                    = 105861,
    SPELL_BLISTERING_HEAT               = 105444,

    // Regenerative Blood
    SPELL_REGENERATIVE_BLOOD            = 105937,
    SPELL_DEGENERATIVE_BITE             = 105842,

    // Aspects
    SPELL_ASTRAL_RECALL                 = 108537,
    SPELL_ALEXSTRASZA_PRESENCE          = 105825,
    SPELL_CAUTERIZE_PHASE_1             = 105565,
    SPELL_NOZDORMU_PRESENCE             = 105823,
    SPELL_TIME_ZONE_SUMMON_TARGET       = 106919,
    SPELL_TIME_ZONE                     = 105799,
    SPELL_YSERA_PRESENCE                = 106456,
    SPELL_THE_DREAMER                   = 106463,
    SPELL_KALECGOS_PRESENCE             = 106026,
    SPELL_SPELLWEAVER                   = 106039,
    SPELL_SPELLWEAVE                    = 106043,
    SPELL_EXPOSE_WEAKNESS_ALEXSTRASZA   = 106588,
    SPELL_EXPOSE_WEAKNESS_NOZDORMU      = 106600,
    SPELL_EXPOSE_WEAKNESS_YSERA         = 106613,
    SPELL_EXPOSE_WEAKNESS_KALECGOS      = 106624,
    SPELL_ALEXSTRASZA_BEAM = 107618,
    SPELL_NOZDORMU_BEAM = 108616,
    SPELL_YSERA_BEAM = 108615,
    SPELL_KALECGOS_BEAM = 107668,

    // Carrying Winds
    SPELL_CARRYING_WINDS_LEFTMOST        = 106666,
    SPELL_CARRYING_WINDS_LEFTMOST_ML    = 106669,
    SPELL_CARRYING_WINDS_MIDDLE_LEFT    = 106671,
    SPELL_CARRYING_WINDS_MIDDLE_LEFT_MR = 106673,
    SPELL_CARRYING_WINDS_MIDDLE_RIGHT    = 106675,
    SPELL_CARRYING_WINDS_RIGHTMOST        = 106677,
    SPELL_CARRYING_WINDS_BUFF = 106664,

    // Phase 2
    SPELL_ELEMENTIUM_TERROR_SUMMON      = 106765,
    SPELL_IMPALING_TENTACLES            = 106775,
    SPELL_SHRAPNEL                      = 106791,
    SPELL_SHRAPNEL_TARGET               = 106794,
    SPELL_TETANUS                       = 106728,
    SPELL_CORRUPTED_BLOOD               = 106835,
    SPELL_CORRUPTED_BLOOD_STACKER       = 106843,
    SPELL_FIRE_DRAGON_SOUL              = 109971,
    SPELL_CONGEALING_BLOOD              = 109082,
    SPELL_CONGEALING_BLOOD_DUMMY        = 109087,

    // Corrupting Parasite
    SPELL_UNSTABLE_CORRUPTION           = 108813,
};

enum Texts
{
    //Deathwing
    SAY_AGGRO           = 0,
    SAY_PHASE_2         = 1,
    SAY_METEOR          = 2,

    // Alexstrasza
    SAY_ASSAULTED       = 0,
    SAY_CATACLYSM       = 1,
    SAY_ALEX_PHASE_2    = 3,

    // Nozdormu
    SAY_NOZ_PHASE_2     = 4,

    // Ysera
    SAY_YSERA_PHASE_2   = 2,

    // Kalecgos
    SAY_KALEC_PHASE_2   = 2,
    SAY_END             = 3,

    // Thrall
    SAY_THRALL_PHASE_2  = 0,
};

enum areaTrigger
{
    LEFTMOST        = 575818,
    LEFTMOST_ML     = 575819,
    MIDDLE_LEFT     = 575820,
    MIDDLE_LEFT_MR  = 575821,
    MIDDLE_RIGHT    = 575822,
    RIGHTMOST       = 575823,
};

Position const JumpPad[]
{
    { -12023.0f, 12228.5f, -6.068f, 1.0821f },
    { -12087.5f, 12165.7f, -2.650f, 1.0821f },
    { -12047.9f, 12213.9f, -5.942f, 4.7822f },
    { -12099.6f, 12152.8f, -2.650f, 1.0821f },
    { -12118.2f, 12084.9f,  2.390f, 1.0821f },
    { -11972.8f, 12272.8f,  1.383f, 4.0142f },
};

Position const mutatedCorr[]
{
    { -12107.4f, 12201.9f, -5.32f, 5.16f },
    { -12028.8f, 12265.6f, -6.27f, 4.13f },
    { -11993.3f, 12286.3f, -2.58f, 5.91f },
    { -12160.9f, 12057.0f,  2.47f, 0.73f },
};

Position const platformPos[]
{
    { -12111.4f, 12169.9f, -2.65f, 5.68f },
    { -12040.3f, 12232.5f, -6.06f, 5.51f },
    { -11960.5f, 12288.5f,  1.38f, 4.92f },
    { -12139.4f, 12080.6f,  2.39f, 5.79f },
};

Position const armTentacle1   = { -12065.0f, 12127.2f, -3.2946f, 2.3387f };
Position const wingTentacle1  = { -11941.2f, 12248.9f, 12.1499f, 1.9896f };
Position const wingTentacle2  = { -12097.8f, 12067.4f, 13.4888f, 2.2165f };
Position const armTentacle2   = { -12005.8f, 12190.3f, -6.5939f, 2.1293f };
Position const congealingDest = { -12083.2f, 12173.7f, -4.719f, 0.0f };

class between_maelstrom_platforms : public CreatureScript
{
public:
    between_maelstrom_platforms() : CreatureScript("between_maelstrom_platforms") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new between_maelstrom_platformsAI(creature);
    }

    struct between_maelstrom_platformsAI : public ScriptedAI
    {
        between_maelstrom_platformsAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void UpdateAI(uint32 diff) override

        {
            std::list<Player*> targets;
            me->GetPlayerListInGrid(targets, 15.0f);
            for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                switch (me->GetEntry())
                {
                case LEFTMOST:
                    (*itr)->CastSpell(*itr, SPELL_CARRYING_WINDS_LEFTMOST);
                    break;

                case LEFTMOST_ML:
                    (*itr)->CastSpell(*itr, SPELL_CARRYING_WINDS_LEFTMOST_ML);
                    break;

                case MIDDLE_LEFT:
                    (*itr)->CastSpell(*itr, SPELL_CARRYING_WINDS_MIDDLE_LEFT);
                    break;

                case MIDDLE_LEFT_MR:
                    (*itr)->CastSpell(*itr, SPELL_CARRYING_WINDS_MIDDLE_LEFT_MR);
                    break;

                case MIDDLE_RIGHT:
                    (*itr)->CastSpell(*itr, SPELL_CARRYING_WINDS_MIDDLE_RIGHT);
                    break;

                case RIGHTMOST:
                    (*itr)->CastSpell(*itr, SPELL_CARRYING_WINDS_RIGHTMOST);
                    break;
                default:
                    break;
                }
            }
        }
    };
};

class boss_deathwing : public CreatureScript
{
public:
    boss_deathwing() : CreatureScript("boss_deathwing") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_deathwingAI(creature);
    }

    struct boss_deathwingAI : public BossAI
    {
        boss_deathwingAI(Creature* creature) : BossAI(creature, DATA_DEATHWING)
        {
            instance = creature->GetInstanceScript();
            platform = 0;
            dwingDeath = 0;
        }

        InstanceScript* instance;
        EventMap events;
        uint32 platform;
        uint32 dwingDeath;
        uint32 congealing;
        bool phaseTwo;
        bool encounterEnd;

        Creature* thrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true);
        Creature* alexs = me->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 500.0f, true);
        Creature* noz = me->FindNearestCreature(NPC_NOZDORMU_DRAGON, 500.0f, true);
        Creature* ysera = me->FindNearestCreature(NPC_YSERA_DRAGON, 500.0f, true);
        Creature* kalec = me->FindNearestCreature(NPC_KALECGOS_DRAGON, 500.0f, true);

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
            DoZoneInCombat(me, 500.0f);

            encounterEnd = false;
            phaseTwo = false;

            events.ScheduleEvent(PHASE_1, 1000);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            Talk(SAY_AGGRO);
            me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
        }

        void Reset() override
        {
            DespawnCreatures(NPC_WING_TENTACLE, 1000.0f);
            DespawnCreatures(NPC_ARM_TENTACLE_1, 1000.0f);
            DespawnCreatures(NPC_ARM_TENTACLE_2, 1000.0f);
            DespawnCreatures(NPC_REGENERATIVE_BLOOD, 1000.0f);
            DespawnCreatures(NPC_TIME_ZONE, 1000.0f);
            DespawnCreatures(NPC_MUTATED_CORRUPTION, 1000.0f);
            DespawnCreatures(NPC_ELEMENTIUM_BOLT, 1000.0f);

            thrall->NearTeleportTo(thrall->GetHomePosition().GetPositionX(), thrall->GetHomePosition().GetPositionY(), thrall->GetHomePosition().GetPositionZ(), thrall->GetHomePosition().GetOrientation());
            thrall->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CATACLYSM_AURA);

            me->DespawnOrUnsummon();
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
        }

        void DespawnCreatures(uint32 entry, float distance)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ALEXS:
                if (Creature* wing = alexs->FindNearestCreature(NPC_WING_TENTACLE, 200.0f, true))
                     {
                    wing->AI()->DoAction(ACTION_ENCOUNTER_START);
                    events.ScheduleEvent(EVENT_ASSAULT_ALEXSTRASZA, 1000);
                    }
                else
                     DoAction(ACTION_NOZDORMU);
                break;

             case ACTION_NOZDORMU:
                if (Creature* arm = noz->FindNearestCreature(NPC_ARM_TENTACLE_1, 500.0f, true))
                     {
                    arm->AI()->DoAction(ACTION_ENCOUNTER_START);
                    events.ScheduleEvent(EVENT_ASSAULT_NOZDORMU, 1000);
                    }
                else
                     DoAction(ACTION_YSERA);
                break;

             case ACTION_YSERA:
                 if (Creature* arm = ysera->FindNearestCreature(NPC_ARM_TENTACLE_2, 500.0f, true))
                      {
                     arm->AI()->DoAction(ACTION_ENCOUNTER_START);
                     events.ScheduleEvent(EVENT_ASSAULT_YSERA, 1000);
                     }
                 else
                     DoAction(ACTION_KALECGOS);
                 break;

            case ACTION_KALECGOS:
                if (Creature* wing = kalec->FindNearestCreature(NPC_WING_TENTACLE, 200.0f, true))
                     {
                    wing->AI()->DoAction(ACTION_ENCOUNTER_START);
                    events.ScheduleEvent(EVENT_ASSAULT_KALECGOS, 1000);
                    }
                else
                     DoAction(ACTION_ALEXS);
                break;

            case ACTION_PLATFORM_DONE:
                me->CastStop();
                me->DealDamage(me, me->GetMaxHealth() * 0.2f);

                events.CancelEvent(EVENT_ELEMENTIUM_BOLT);
                events.CancelEvent(EVENT_CATACLYSM);
                events.ScheduleEvent(PHASE_1, 1000);
                break;
            }
        }

        void UpdateAI(uint32 diff) override

        {
            std::list<Player*> targets;
            me->GetPlayerListInGrid(targets, 1000.0f);

            if (targets.size() == 0)
                Reset();

            if (me->GetHealthPct() <= 20)
                if (phaseTwo == false)
                {
                    phaseTwo = true;
                    events.ScheduleEvent(PHASE_2, 1000);
                }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    //Phase 1

                case PHASE_1:
                    events.ScheduleEvent(EVENT_ENRAGE, 900000);
                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 1000);
                    break;

                case EVENT_ASSAULT_ASPECTS:
                    DoCast(me, SPELL_ASSAULT_ASPECTS);

                    if (Creature* platform = me->FindNearestCreature(NPC_PLATFORM, 500.0f, true))
                        platform->DespawnOrUnsummon();

                    if (Creature* tzone = me->FindNearestCreature(NPC_TIME_ZONE, 500.0f, true))
                        tzone->DespawnOrUnsummon();

                    events.CancelEvent(EVENT_CORRUPTING_PARASITE);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_BOLT, 40000);
                    events.ScheduleEvent(EVENT_CATACLYSM, 120000);
                    break;

                case EVENT_ASSAULT_ALEXSTRASZA:
                    platform = 2;

                    alexs->AI()->Talk(SAY_ASSAULTED);
                    me->SummonCreature(NPC_MUTATED_CORRUPTION, mutatedCorr[platform], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    me->SummonCreature(NPC_PLATFORM, platformPos[platform], TEMPSUMMON_MANUAL_DESPAWN);

                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 100);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 60000);
                    }

                    noz->AI()->DoAction(ACTION_TIME_ZONE);
                    break;

                case EVENT_ASSAULT_NOZDORMU:
                    platform = 1;

                    noz->AI()->Talk(SAY_ASSAULTED);
                    me->SummonCreature(NPC_MUTATED_CORRUPTION, mutatedCorr[platform], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    me->SummonCreature(NPC_PLATFORM, platformPos[platform], TEMPSUMMON_MANUAL_DESPAWN);

                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 100);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 60000);
                    }

                    noz->AI()->DoAction(ACTION_TIME_ZONE);
                    break;

                case EVENT_ASSAULT_YSERA:
                    platform = 0;

                    ysera->AI()->Talk(SAY_ASSAULTED);
                    me->SummonCreature(NPC_MUTATED_CORRUPTION, mutatedCorr[platform], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    me->SummonCreature(NPC_PLATFORM, platformPos[platform], TEMPSUMMON_MANUAL_DESPAWN);

                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 100);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 60000);
                    }

                    noz->AI()->DoAction(ACTION_TIME_ZONE);
                    break;

                case EVENT_ASSAULT_KALECGOS:
                    platform = 3;

                    kalec->AI()->Talk(SAY_ASSAULTED);
                    me->SummonCreature(NPC_MUTATED_CORRUPTION, mutatedCorr[platform], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                    me->SummonCreature(NPC_PLATFORM, platformPos[platform], TEMPSUMMON_MANUAL_DESPAWN);

                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 100);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 60000);
                    }

                    noz->AI()->DoAction(ACTION_TIME_ZONE);
                    break;

                case EVENT_ELEMENTIUM_BOLT:
                    Talk(SAY_METEOR);

                    DoCast(me, SPELL_ELEMENTIUM_BOLT);

                    if (Creature* platform = me->FindNearestCreature(NPC_PLATFORM, 500.0f, true))
                        platform->AddAura(SPELL_ELEMENTIUM_METEOR_VOID, platform);

                    break;

                case EVENT_CATACLYSM:

                    switch (platform)
                    {
                    case 0:
                        ysera->AI()->DoAction(ACTION_CATACLYSM);
                        break;
                    case 1:
                        noz->AI()->DoAction(ACTION_CATACLYSM);
                        break;
                    case 2:
                        alexs->AI()->DoAction(ACTION_CATACLYSM);
                        break;
                    case 3:
                        kalec->AI()->DoAction(ACTION_CATACLYSM);
                        break;
                    }

                    DoCast(me, SPELL_CATACLYSM);
                    break;

                case EVENT_CORRUPTING_PARASITE:
                    DoCast(me, SPELL_CORRUPTING_PARASITE);
                    break;

                    // Phase 2

                case PHASE_2:
                    congealing = 0;
                    platform = 0;

                    if (Creature* platform = me->FindNearestCreature(NPC_PLATFORM, 500.0f, true))
                        platform->DespawnOrUnsummon();

                    thrall->AI()->DoAction(ACTION_PHASE_2);
                    ysera->AI()->DoCast(SPELL_THE_DREAMER);

                    me->SummonCreature(NPC_PLATFORM, platformPos[platform], TEMPSUMMON_MANUAL_DESPAWN);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                    me->PlayOneShotAnimKitId(ANIM_KIT_FALL_FORWARD);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CUSTOM_SPELL_02);

                    events.CancelEvent(EVENT_CORRUPTING_PARASITE);
                    events.CancelEvent(EVENT_ASSAULT_ASPECTS);
                    events.CancelEvent(EVENT_CATACLYSM);
                    events.CancelEvent(EVENT_CORRUPTING_PARASITE);
                    events.CancelEvent(EVENT_ELEMENTIUM_BOLT);
                    events.ScheduleEvent(EVENT_CORRUPTED_BLOOD, 5000);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, 10000);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, 40000);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_CONGEALING_BLOOD, 60000);
                    break;

                case EVENT_CORRUPTED_BLOOD:
                    DoCast(SPELL_CORRUPTED_BLOOD_STACKER);
                    break;

                case EVENT_ELEMENTIUM_TERROR:
                    DoCast(SPELL_ELEMENTIUM_TERROR_SUMMON);

                    events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, 90000);
                    break;

                case EVENT_ELEMENTIUM_FRAGMENT:
                    noz->AI()->DoAction(ACTION_TIME_ZONE_PHASE_2);

                    DoCast(SPELL_IMPALING_TENTACLES);

                    events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, 90000);
                    break;

                case EVENT_CONGEALING_BLOOD:
                    congealing += 1;
                    DoCast(me, SPELL_CONGEALING_BLOOD);
                    break;

                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                    break;

                case EVENT_DIE:
                    dwingDeath += 1;

                    if (dwingDeath == 1)
                        me->HandleEmoteCommand(EMOTE_ONESHOT_CUSTOM_SPELL_05);
                    else if (dwingDeath == 2)
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                        me->DespawnOrUnsummon();
                    }

                    events.ScheduleEvent(EVENT_DIE, 8000);
                    break;
                default:
                    break;
                }
            }
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;
            if (IsHeroic())
            {
                if (me->HealthAbovePct(15.0f) && (me->GetMaxHealth() *0.15f) > (me->GetHealth() - damage))
                {
                    if (congealing == 0)
                        events.RescheduleEvent(EVENT_CONGEALING_BLOOD, 100);

                    events.ScheduleEvent(EVENT_CONGEALING_BLOOD, 60000);
                }

                if (me->HealthAbovePct(10.0f) && (me->GetMaxHealth() *0.10f) > (me->GetHealth() - damage))
                {
                    if (congealing == 1)
                        events.RescheduleEvent(EVENT_CONGEALING_BLOOD, 100);

                    events.ScheduleEvent(EVENT_CONGEALING_BLOOD, 60000);
                }

                if (me->HealthAbovePct(5.0f) && (me->GetMaxHealth() *0.05f) > (me->GetHealth() - damage))
                {
                    if (congealing == 2)
                        events.RescheduleEvent(EVENT_CONGEALING_BLOOD, 100);
                }
            }

            if (me->HealthAbovePct(1.5f) && (me->GetMaxHealth() *0.015f) > (me->GetHealth() - damage))
            {
                if (encounterEnd == false)
                {
                    encounterEnd = true;

                    kalec->AI()->Talk(SAY_END);

                    events.Reset();
                    me->RemoveAllAuras();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CUSTOM_SPELL_04);

                    DespawnCreatures(NPC_ELEMENTIUM_FRAGMENT, 500.0f);
                    DespawnCreatures(NPC_ELEMENTIUM_TERROR, 500.0f);
                    DespawnCreatures(NPC_PLATFORM, 500.0f);
                    DespawnCreatures(NPC_TIME_ZONE, 500.0f);

                    thrall->NearTeleportTo(-12058.31f, 12185.38f, 23.28f, 5.47f);
                    thrall->CastSpell(thrall, SPELL_FIRE_DRAGON_SOUL);

                    instance->SetBossState(DATA_DEATHWING, DONE);
                    who->SummonGameObject(RAID_MODE(GO_ELEMENTIUM_FRAGMENT_10N, GO_ELEMENTIUM_FRAGMENT_25N, GO_ELEMENTIUM_FRAGMENT_10H, GO_ELEMENTIUM_FRAGMENT_25H), -12100.5f, 12173.6f, -2.73425f, 5.09636f, QuaternionData(0.0f, 0.0f, -0.559193f, 0.829038f), 100000);

                    Map::PlayerList const& PlayerList = instance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                        {
                            if (IsHeroic())
                                player->CompletedAchievement(6116);
                            else
                            {
                                player->CompletedAchievement(6177);
                                player->CompletedAchievement(6107);
                            }
                        }
                    }

                    events.ScheduleEvent(EVENT_DIE, 15000);
                }
            }
        }

        void JustDied(Unit* /*kller*/) override
        {
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustDied();
        }
    };
};

class npc_maelstrom_trall : public CreatureScript
{
public:
    npc_maelstrom_trall() : CreatureScript("npc_maelstrom_trall") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maelstrom_trallAI(creature);
    }

    struct npc_maelstrom_trallAI : public ScriptedAI
    {
        npc_maelstrom_trallAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_ASTRAL_RECALL)
            {
                me->NearTeleportTo(-12126.105f, 12252.240f, 0.0427f, 5.848f);

                me->AddAura(SPELL_ALEXSTRASZA_PRESENCE, me);
                me->AddAura(SPELL_YSERA_PRESENCE, me);
                me->AddAura(SPELL_NOZDORMU_PRESENCE, me);
                me->AddAura(SPELL_KALECGOS_PRESENCE, me);

                DoCast(SPELL_THE_DREAMER);
                DoCast(SPELL_SPELLWEAVER);

                events.ScheduleEvent(EVENT_CAUTERIZE, 1000);
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_PHASE_2:
                me->AddAura(SPELL_ALEXSTRASZA_PRESENCE, me);
                me->AddAura(SPELL_YSERA_PRESENCE, me);
                me->AddAura(SPELL_NOZDORMU_PRESENCE, me);
                me->AddAura(SPELL_KALECGOS_PRESENCE, me);

                DoCast(SPELL_THE_DREAMER);
                DoCast(SPELL_SPELLWEAVER);
                break;
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAUTERIZE:
                    if (Creature* alexs = me->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 500.0f, true))
                    {
                        if (Creature* wing = alexs->FindNearestCreature(NPC_WING_TENTACLE, 100.0f, true))
                        {
                            if (Creature* blistering = me->FindNearestCreature(NPC_BLISTERING_TENTACLES, 500.0f, true))
                            {
                                /*if (Creature* alexs = me->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 500.0f, true))
                                    alexs->CastSpell(alexs, SPELL_CAUTERIZE_PHASE_1);*/

                                // Hack, core limitation
                                blistering->CastSpell(blistering, 105569);
                            }

                            events.ScheduleEvent(EVENT_CAUTERIZE, 200);
                        }
                    }
                    break;
                default:
                    break;
                }
            }
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->GetInstanceScript())
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, TRALL_MENU, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (uiAction)
            {
            case GOSSIP_ACTION_INFO_DEF:
                if (InstanceScript* instance = creature->GetInstanceScript())
                {
                    if (instance->GetBossState(DATA_DEATHWING) != DONE)
                    {
                        CloseGossipMenuFor(player);
                        creature->CastSpell(creature, SPELL_ASTRAL_RECALL);
                        creature->SummonCreature(NPC_DEATHWING, -11903.9f, 11989.1f, -113.204f, 2.16421f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 12000000);
                        creature->SummonCreature(NPC_ARM_TENTACLE_2, armTentacle1, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                        creature->SummonCreature(NPC_WING_TENTACLE, wingTentacle2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                        creature->SummonCreature(NPC_WING_TENTACLE, wingTentacle1, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                        creature->SummonCreature(NPC_ARM_TENTACLE_1, armTentacle2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                        creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    }
                }
                break;
            default:
                break;
            }
        }
        return true;
    }
};

class npc_arm_tentacle_one : public CreatureScript
{
public:
    npc_arm_tentacle_one() : CreatureScript("npc_arm_tentacle_one") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_arm_tentacle_oneAI(creature);
    }

    struct npc_arm_tentacle_oneAI : public BossAI
    {
        npc_arm_tentacle_oneAI(Creature* creature) : BossAI(creature, DATA_DAMAGE_DEATHWING), vehicle(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;
        Vehicle* vehicle;
        bool firstBlistering;
        bool secondBlistering;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(REACT_PASSIVE);

            if (Creature* noz = me->FindNearestCreature(NPC_NOZDORMU_DRAGON, 500.0f, true))
                noz->AI()->DoAction(ACTION_ENCOUNTER_START);

            firstBlistering = false;
            secondBlistering = false;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
        }

        void Reset() override
        {
            me->RemoveAllAuras();
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {

            case ACTION_ENCOUNTER_START:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                events.ScheduleEvent(EVENT_BURNING_BLOOD, 1000);
                events.ScheduleEvent(EVENT_HEMORRHAGE, 90000);
                break;
            }
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (me->HealthAbovePct(70) && (me->GetMaxHealth() *0.7f) > (me->GetHealth() - damage))
            {
                if (firstBlistering == false)
                {
                    firstBlistering = true;

                    for (uint32 x = 0; x <= 5; x++)
                        vehicle->InstallAccessory(NPC_BLISTERING_TENTACLES, x, 1, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
            }

            if (me->HealthAbovePct(40) && (me->GetMaxHealth() *0.4f) > (me->GetHealth() - damage))
            {
                if (secondBlistering == false)
                {
                    secondBlistering = true;

                    for (uint32 x = 0; x <= 5; x++)
                        vehicle->InstallAccessory(NPC_BLISTERING_TENTACLES, x, 1, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BURNING_BLOOD:
                    DoCast(SPELL_BURNING_BLOOD);

                    events.ScheduleEvent(EVENT_BURNING_BLOOD, 2000);
                    break;

                case EVENT_HEMORRHAGE:
                    DoCast(SPELL_HEMORRHAGE_SUMMON);
                    DoCast(me, SPELL_HEMORRHAGE);
                    break;
                default:
                    break;
                }
            }
        }

        void DespawnCreatures(uint32 entry, float distance)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* dwing = me->FindNearestCreature(NPC_DEATHWING, 500.0f, true))
                dwing->AI()->DoAction(ACTION_PLATFORM_DONE);

            DespawnCreatures(NPC_TIME_ZONE, 1000.0f);
            DespawnCreatures(NPC_MUTATED_CORRUPTION, 1000.0f);
            DespawnCreatures(NPC_ELEMENTIUM_BOLT, 1000.0f);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

    };
};

class npc_arm_tentacle_two : public CreatureScript
{
public:
    npc_arm_tentacle_two() : CreatureScript("npc_arm_tentacle_two") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_arm_tentacle_twoAI(creature);
    }

    struct npc_arm_tentacle_twoAI : public BossAI
    {
        npc_arm_tentacle_twoAI(Creature* creature) : BossAI(creature, DATA_DAMAGE_DEATHWING), vehicle(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;
        Vehicle* vehicle;
        bool firstBlistering;
        bool secondBlistering;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(REACT_PASSIVE);

            if (Creature* ysera = me->FindNearestCreature(NPC_YSERA_DRAGON, 500.0f, true))
                ysera->AI()->DoAction(ACTION_ENCOUNTER_START);

            firstBlistering = false;
            secondBlistering = false;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
        }

        void Reset() override
        {
            me->RemoveAllAuras();
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {

            case ACTION_ENCOUNTER_START:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                events.ScheduleEvent(EVENT_BURNING_BLOOD, 1000);
                events.ScheduleEvent(EVENT_HEMORRHAGE, 90000);
                break;
            }
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (me->HealthAbovePct(70) && (me->GetMaxHealth() *0.7f) > (me->GetHealth() - damage))
            {
                if (firstBlistering == false)
                {
                    firstBlistering = true;

                    for (uint32 x = 0; x <= 5; x++)
                        vehicle->InstallAccessory(NPC_BLISTERING_TENTACLES, x, 1, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
            }

            if (me->HealthAbovePct(40) && (me->GetMaxHealth() *0.4f) > (me->GetHealth() - damage))
            {
                if (secondBlistering == false)
                {
                    secondBlistering = true;

                    for (uint32 x = 0; x <= 5; x++)
                        vehicle->InstallAccessory(NPC_BLISTERING_TENTACLES, x, 1, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BURNING_BLOOD:
                    DoCast(SPELL_BURNING_BLOOD);

                    events.ScheduleEvent(EVENT_BURNING_BLOOD, 2000);
                    break;

                case EVENT_HEMORRHAGE:
                    DoCast(SPELL_HEMORRHAGE_SUMMON);
                    DoCast(me, SPELL_HEMORRHAGE);
                    break;
                default:
                    break;
                }
            }
        }

        void DespawnCreatures(uint32 entry, float distance)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* dwing = me->FindNearestCreature(NPC_DEATHWING, 500.0f, true))
                dwing->AI()->DoAction(ACTION_PLATFORM_DONE);

            if (Creature* ysera = me->FindNearestCreature(NPC_YSERA_DRAGON, 500.0f, true))
                ysera->RemoveAura(SPELL_THE_DREAMER);

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
            {
                thrall->RemoveAura(SPELL_YSERA_PRESENCE);
                thrall->RemoveAura(SPELL_THE_DREAMER);
            }

            DespawnCreatures(NPC_TIME_ZONE, 1000.0f);
            DespawnCreatures(NPC_MUTATED_CORRUPTION, 1000.0f);
            DespawnCreatures(NPC_ELEMENTIUM_BOLT, 1000.0f);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

    };
};

class npc_wing_tentacle : public CreatureScript
{
public:
    npc_wing_tentacle() : CreatureScript("npc_wing_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wing_tentacleAI(creature);
    }

    struct npc_wing_tentacleAI : public BossAI
    {
        npc_wing_tentacleAI(Creature* creature) : BossAI(creature, DATA_DAMAGE_DEATHWING), vehicle(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Position pos;
        Vehicle* vehicle;
        bool firstBlistering;
        bool secondBlistering;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(REACT_PASSIVE);

            if (Creature* alex = me->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 200.0f, true))
                alex->AI()->DoAction(ACTION_ENCOUNTER_START);

            if (Creature* kalec = me->FindNearestCreature(NPC_KALECGOS_DRAGON, 200.0f, true))
                kalec->AI()->DoAction(ACTION_ENCOUNTER_START);

            firstBlistering = false;
            secondBlistering = false;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
        }

        void Reset() override
        {
            me->RemoveAllAuras();
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ENCOUNTER_START:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                events.ScheduleEvent(EVENT_BURNING_BLOOD, 1000);
                events.ScheduleEvent(EVENT_HEMORRHAGE, 90000);
                break;
            }
        }

        void DamageTaken(Unit* who, uint32&damage) override
        {
            if (!me || !me->IsAlive())
                return;

            if (me->HealthAbovePct(70) && (me->GetMaxHealth() *0.7f) > (me->GetHealth() - damage))
            {
                if (firstBlistering == false)
                {
                    firstBlistering = true;

                    for (uint32 x = 0; x <= 5; x++)
                        vehicle->InstallAccessory(NPC_BLISTERING_TENTACLES, x, 1, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
            }

            if (me->HealthAbovePct(40) && (me->GetMaxHealth() *0.4f) > (me->GetHealth() - damage))
            {
                if (secondBlistering == false)
                {
                    secondBlistering = true;

                    for (uint32 x = 0; x <= 5; x++)
                        vehicle->InstallAccessory(NPC_BLISTERING_TENTACLES, x, 1, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BURNING_BLOOD:
                    DoCast(SPELL_BURNING_BLOOD);

                    events.ScheduleEvent(EVENT_BURNING_BLOOD, 2000);
                    break;

                case EVENT_HEMORRHAGE:
                    DoCast(SPELL_HEMORRHAGE_SUMMON);
                    DoCast(me, SPELL_HEMORRHAGE);
                    break;
                default:
                    break;
                }
            }
        }

        void DespawnCreatures(uint32 entry, float distance)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* dwing = me->FindNearestCreature(NPC_DEATHWING, 500.0f, true))
                dwing->AI()->DoAction(ACTION_PLATFORM_DONE);

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
            {
                if (Creature* alex = me->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 200.0f, true))
                {
                    thrall->RemoveAura(SPELL_ALEXSTRASZA_PRESENCE);
                    alex->RemoveAura(SPELL_CAUTERIZE_PHASE_1);
                }

                if (Creature* kalec = me->FindNearestCreature(NPC_KALECGOS_DRAGON, 200.0f, true))
                {
                    thrall->RemoveAura(SPELL_KALECGOS_PRESENCE);
                    thrall->RemoveAura(SPELL_SPELLWEAVER);
                }
            }

            DespawnCreatures(NPC_TIME_ZONE, 1000.0f);
            DespawnCreatures(NPC_MUTATED_CORRUPTION, 1000.0f);
            DespawnCreatures(NPC_ELEMENTIUM_BOLT, 1000.0f);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

    };
};

class npc_elementium_meteor : public CreatureScript
{
public:
    npc_elementium_meteor() : CreatureScript("npc_elementium_meteor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_elementium_meteorAI(creature);
    }

    struct npc_elementium_meteorAI : public ScriptedAI
    {
        npc_elementium_meteorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        bool reachedPos;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(REACT_PASSIVE);

            me->SetSpeed(MOVE_WALK, 2.85f);
            me->SetSpeed(MOVE_RUN, 2.85f);
            me->SetSpeed(MOVE_FLIGHT, 2.85f);

            me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 145, me->GetOrientation());
            reachedPos = false;
        }

        void UpdateAI(uint32 diff) override

        {
            if (Creature* platform = me->FindNearestCreature(NPC_PLATFORM, 500.0f, true))
            {
                me->GetMotionMaster()->MoveFollow(platform, 0.5f, 0);

                if (platform->GetExactDist2d(me) <= 5.0f)
                {
                    if (reachedPos == false)
                    {
                        DoCast(me, SPELL_ELEMENTIUM_BLAST_IMPACT);
                        DoCast(me, SPELL_ELEMENTUM_BLAST_PERIODIC);
                        reachedPos = true;
                    }
                }
            }

            if (Creature* tzone = me->FindNearestCreature(NPC_TIME_ZONE, 30.0f, true))
                if (tzone->GetExactDist2d(me) <= 11.0f)
                {
                    me->SetSpeed(MOVE_WALK, 0.4f);
                    me->SetSpeed(MOVE_RUN, 0.4f);
                    me->SetSpeed(MOVE_FLIGHT, 0.4f);
                }
                else
                {
                    me->SetSpeed(MOVE_WALK, 2.85f);
                    me->SetSpeed(MOVE_RUN, 2.85f);
                    me->SetSpeed(MOVE_FLIGHT, 2.85f);
                }
        }

        void JustDied(Unit* /*kller*/) override
        {
            me->DespawnOrUnsummon();
        }
    };
};

class npc_mutated_corruption : public CreatureScript
{
public:
    npc_mutated_corruption() : CreatureScript("npc_mutated_corruption") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mutated_corruptionAI(creature);
    }

    struct npc_mutated_corruptionAI : public BossAI
    {
        npc_mutated_corruptionAI(Creature* creature) : BossAI(creature, DATA_DAMAGE_DEATHWING)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override
        {
            me->DespawnOrUnsummon();
        }

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

            events.ScheduleEvent(EVENT_IMPALE, 10000);
            events.ScheduleEvent(EVENT_CRUSH, 1000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
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
                case EVENT_IMPALE:
                    DoCastVictim(SPELL_IMPALE);

                    events.ScheduleEvent(EVENT_IMPALE, 35000);
                    break;

                case EVENT_CRUSH:
                    if (Creature* target = me->FindNearestCreature(NPC_CRUSH_TARGET, 100.0f, true))
                        target->DespawnOrUnsummon();

                    DoCast(SPELL_CRUSH);

                    events.ScheduleEvent(EVENT_CRUSH_DAMAGE, 500);
                    break;

                case EVENT_CRUSH_DAMAGE:
                    if (Creature* target = me->FindNearestCreature(NPC_CRUSH_TARGET, 100.0f, true))
                        me->SetFacingToObject(target);

                    DoCast(SPELL_CRUSH_DAMAGE);

                    events.ScheduleEvent(EVENT_CRUSH, 15000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_regenerative_blood : public CreatureScript
{
public:
    npc_regenerative_blood() : CreatureScript("npc_regenerative_blood") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_regenerative_bloodAI(creature);
    }

    struct npc_regenerative_bloodAI : public ScriptedAI
    {
        npc_regenerative_bloodAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->setRegeneratingHealth(false);
            me->setPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            EnterCombat(me);

            DoCast(SPELL_DEGENERATIVE_BITE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_INCREASE_ENERGY, 1000);
        }

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INCREASE_ENERGY:
                {
                    int32 energy = me->GetPower(POWER_ENERGY);

                    if (energy == 100)
                    {
                        me->SetFullHealth();
                        energy = 0;
                    }
                    else
                    {
                        energy += 5;
                    }

                    me->SetPower(POWER_ENERGY, energy);

                    events.ScheduleEvent(EVENT_INCREASE_ENERGY, 1000);
                }
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_blistering_tentacle : public CreatureScript
{
public:
    npc_blistering_tentacle() : CreatureScript("npc_blistering_tentacle") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_blistering_tentacleAI(creature);
    }

    struct npc_blistering_tentacleAI : public ScriptedAI
    {
        npc_blistering_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        bool reachedPos;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            DoCast(SPELL_BLISTERING_HEAT);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SPELLWEAVE, true);
        }

        void JustDied(Unit* /*kller*/) override
        {
            me->DespawnOrUnsummon();
        }
    };
};

class npc_maelstrom_alexstrasza : public CreatureScript
{
public:
    npc_maelstrom_alexstrasza() : CreatureScript("npc_maelstrom_alexstrasza") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maelstrom_alexstraszaAI(creature);
    }

    struct npc_maelstrom_alexstraszaAI : public ScriptedAI
    {
        npc_maelstrom_alexstraszaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            me->SetReactState(REACT_PASSIVE);

        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CATACLYSM:
                Talk(SAY_CATACLYSM);
                DoCast(SPELL_EXPOSE_WEAKNESS_ALEXSTRASZA);
                break;

            case ACTION_ENCOUNTER_START:
                //DoCast(SPELL_ALEXSTRASZA_PRESENCE);
            break;
            }
        }
    };
};

class npc_maelstrom_nozdormu : public CreatureScript
{
public:
    npc_maelstrom_nozdormu() : CreatureScript("npc_maelstrom_nozdormu") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maelstrom_nozdormuAI(creature);
    }

    struct npc_maelstrom_nozdormuAI : public ScriptedAI
    {
        npc_maelstrom_nozdormuAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            me->SetReactState(REACT_PASSIVE);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_TIME_ZONE:
                if (Creature* tentacle = me->FindNearestCreature(NPC_ARM_TENTACLE_1, 500.0f, true))
                {
                    DoCast(SPELL_TIME_ZONE_SUMMON_TARGET);

                    events.ScheduleEvent(EVENT_TIME_ZONE, 1000);
                }
                else if(Creature* thrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
                    thrall->RemoveAura(SPELL_NOZDORMU_PRESENCE);
                break;

            case ACTION_TIME_ZONE_PHASE_2:
                if (Creature* tzone = me->FindNearestCreature(NPC_TIME_ZONE, 500.0f, true))
                    tzone->DespawnOrUnsummon();

                DoCast(SPELL_TIME_ZONE_SUMMON_TARGET);

                events.ScheduleEvent(EVENT_TIME_ZONE, 1000);
                break;

            case ACTION_CATACLYSM:
                Talk(SAY_CATACLYSM);

                DoCast(SPELL_EXPOSE_WEAKNESS_NOZDORMU);
                break;

            case ACTION_ENCOUNTER_START:
                //DoCast(SPELL_NOZDORMU_PRESENCE);
                break;
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TIME_ZONE :
                    if (Creature* tzone = me->FindNearestCreature(NPC_TIME_ZONE_TARGET, 500.0f, true))
                        DoCast(tzone, SPELL_TIME_ZONE);
                    break;
                default:
                    break;
                }
            }
        }
    };
};

class npc_maelstrom_ysera : public CreatureScript
{
public:
    npc_maelstrom_ysera() : CreatureScript("npc_maelstrom_ysera") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maelstrom_yseraAI(creature);
    }

    struct npc_maelstrom_yseraAI : public ScriptedAI
    {
        npc_maelstrom_yseraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CATACLYSM:
                Talk(SAY_CATACLYSM);
                DoCast(SPELL_EXPOSE_WEAKNESS_YSERA);
                break;

            case ACTION_ENCOUNTER_START:
                //DoCast(SPELL_YSERA_PRESENCE);
                break;
            }
        }
    };
};

class npc_maelstrom_kalecgos : public CreatureScript
{
public:
    npc_maelstrom_kalecgos() : CreatureScript("npc_maelstrom_kalecgos") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_maelstrom_kalecgosAI(creature);
    }

    struct npc_maelstrom_kalecgosAI : public ScriptedAI
    {
        npc_maelstrom_kalecgosAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            DoCast(SPELL_SPELLWEAVER);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_CATACLYSM:
                Talk(SAY_CATACLYSM);

                DoCast(SPELL_EXPOSE_WEAKNESS_KALECGOS);
                break;

            case ACTION_ENCOUNTER_START:
                //DoCast(SPELL_KALECGOS_PRESENCE);
                break;
            }
        }
    };
};

class npc_corrupting_parasite : public CreatureScript
{
public:
    npc_corrupting_parasite() : CreatureScript("npc_corrupting_parasite") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_corrupting_parasiteAI(creature);
    }

    struct npc_corrupting_parasiteAI : public ScriptedAI
    {
        npc_corrupting_parasiteAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_UNSTABLE_CORRUPTION);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_UNSTABLE_CORRUPTION)
            {
                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            if (me->GetHealthPct() >= 50.0f)
                me->DealDamage(me, me->GetMaxHealth() * 0.02f);
        }
    };
};

class npc_congealing_blood : public CreatureScript
{
public:
    npc_congealing_blood() : CreatureScript("npc_congealing_blood") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_congealing_bloodAI(creature);
    }

    struct npc_congealing_bloodAI : public ScriptedAI
    {
        npc_congealing_bloodAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetHomePosition(congealingDest);
            me->SetSpeed(MOVE_WALK, 0.5f);
            me->SetSpeed(MOVE_RUN, 0.5f);
            DoZoneInCombat(me);
        }

        void JustReachedHome()
        {
            DoCast(me, SPELL_CONGEALING_BLOOD_HEAL);
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override

        {
            events.Update(diff);

            me->GetMotionMaster()->MoveTargetedHome();

        }
    };
};

class spell_carrying_winds : public SpellScriptLoader
{

public:
    spell_carrying_winds() : SpellScriptLoader("spell_carrying_winds") { }

    class spell_carrying_winds_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_carrying_winds_SpellScript);

        uint32 spell;

        bool Load()
        {
            spell = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
            {
                target->CastSpell(target, SPELL_CARRYING_WINDS_BUFF);
                target->CastSpell(target, spell);
                target->AddAura(spell, target);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_carrying_winds_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_carrying_winds_SpellScript();
    }
};

class spell_assault_aspects : public SpellScriptLoader
{

public:
    spell_assault_aspects() : SpellScriptLoader("spell_assault_aspects") { }

    class spell_assault_aspects_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_assault_aspects_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                Creature* alex = caster->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 500.0f, true);
                Creature* yse = caster->FindNearestCreature(NPC_YSERA_DRAGON, 500.0f, true);
                Creature* noz = caster->FindNearestCreature(NPC_NOZDORMU_DRAGON, 500.0f, true);
                Creature* kal = caster->FindNearestCreature(NPC_KALECGOS_DRAGON, 500.0f, true);

                std::list<Player*> players;
                std::list<Player*> alexs;
                std::list<Player*> nozdormu;
                std::list<Player*> ysera;
                std::list<Player*> kalec;
                std::list<Player*> conf;
                caster->GetPlayerListInGrid(players, 500.0f);

                for (std::list<Player*>::const_iterator iter = players.begin(); iter != players.end(); ++iter)
                {
                    if ((*iter)->ToPlayer())
                    {
                        if ((*iter)->IsInBetween(caster, alex, 35.0f) && (*iter)->FindNearestCreature(NPC_WING_TENTACLE, 200.0f,true))
                            alexs.push_back((*iter));
                        else if ((*iter)->IsInBetween(caster, noz, 35.0f) && (*iter)->FindNearestCreature(NPC_ARM_TENTACLE_1, 200.0f, true))
                            nozdormu.push_back((*iter));
                        else if ((*iter)->IsInBetween(caster, yse, 35.0f) && (*iter)->FindNearestCreature(NPC_ARM_TENTACLE_2, 200.0f, true))
                            ysera.push_back((*iter));
                        else if ((*iter)->IsInBetween(caster, kal, 35.0f) && (*iter)->FindNearestCreature(NPC_WING_TENTACLE, 200.0f, true))
                            kalec.push_back((*iter));
                    }
                }

                if (alexs.size() > nozdormu.size() && alexs.size() > ysera.size() && alexs.size() > kalec.size())
                    caster->ToCreature()->AI()->DoAction(ACTION_ALEXS);
                else if (nozdormu.size() > alexs.size() && nozdormu.size() > ysera.size() && nozdormu.size() > kalec.size())
                    caster->ToCreature()->AI()->DoAction(ACTION_NOZDORMU);
                else if (ysera.size() > nozdormu.size() && ysera.size() > alexs.size() && ysera.size() > kalec.size())
                    caster->ToCreature()->AI()->DoAction(ACTION_YSERA);
                else if (kalec.size() > nozdormu.size() && kalec.size() > alexs.size() && kalec.size() > ysera.size())
                    caster->ToCreature()->AI()->DoAction(ACTION_KALECGOS);
                else
                    caster->ToCreature()->AI()->DoAction(ACTION_ALEXS);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_assault_aspects_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_assault_aspects_SpellScript();
    }
};

class spell_hemorrhage : public SpellScriptLoader
{

public:
    spell_hemorrhage() : SpellScriptLoader("spell_hemorrhage") { }

    class spell_hemorrhage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hemorrhage_SpellScript);

        int32 triggerSpell;

        bool Load()
        {
            triggerSpell = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void HandleScriptEffect(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, triggerSpell);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_hemorrhage_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hemorrhage_SpellScript();
    }
};

class spell_crush : public SpellScriptLoader
{

public:
    spell_crush() : SpellScriptLoader("spell_crush") { }

    class spell_crush_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_crush_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_crush_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_crush_SpellScript();
    }
};

class spell_elementium_terror_summon : public SpellScriptLoader
{

public:
    spell_elementium_terror_summon() : SpellScriptLoader("spell_elementium_terror_summon") { }

    class spell_elementium_terror_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_elementium_terror_summon_SpellScript);

        int32 triggerSpell;

        bool Load()
        {
            triggerSpell = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void HandleScriptEffect(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
            {
                for (int32 x = 0; x <= 1; x++)
                    caster->CastSpell(caster, triggerSpell);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_elementium_terror_summon_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_elementium_terror_summon_SpellScript();
    }
};

class spell_impaling_tentacles : public SpellScriptLoader
{

public:
    spell_impaling_tentacles() : SpellScriptLoader("spell_impaling_tentacles") { }

    class spell_impaling_tentacles_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_impaling_tentacles_SpellScript);

        int32 triggerSpell;

        bool Load()
        {
            triggerSpell = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void HandleScriptEffect(SpellEffIndex effIndex)
        {
            int32 num;

            if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_N ||
                GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                num = 7;
            else
                num = 2;

            if (Unit* caster = GetCaster())
            {
                for (int32 x = 0; x <= num; x++)
                    caster->CastSpell(caster, triggerSpell);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_impaling_tentacles_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_impaling_tentacles_SpellScript();
    }
};

class spell_shrapnel : public SpellScriptLoader
{

public:
    spell_shrapnel() : SpellScriptLoader("spell_shrapnel") { }

    class spell_shrapnel_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shrapnel_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                {
                    caster->AddAura(SPELL_SHRAPNEL_TARGET, target);
                    caster->CastSpell(target, SPELL_SHRAPNEL);
                }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shrapnel_SpellScript::FilterTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_shrapnel_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shrapnel_SpellScript();
    }
};

class spell_corrupted_blood : public SpellScriptLoader
{
public:
    spell_corrupted_blood() : SpellScriptLoader("spell_corrupted_blood") { }

    class spell_corrupted_blood_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_corrupted_blood_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_1))
                    effect->RecalculateAmount(caster);
        }

        void CalculateBonus(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = true;
            amount = 0;
            if (Unit* caster = GetCaster())
                amount = (20 - int32(caster->GetHealthPct())) * 190 ;
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_corrupted_blood_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_corrupted_blood_AuraScript::CalculateBonus, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_corrupted_blood_AuraScript();
    }
};

class spell_burning_blood : public SpellScriptLoader
{
public:
    spell_burning_blood() : SpellScriptLoader("spell_burning_blood") { }

    class spell_burning_blood_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_burning_blood_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            if (Unit* caster = GetCaster())
            {
                uint32 triggerSpell = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell;
                SpellInfo const* spell = sSpellMgr->GetSpellInfo(triggerSpell);

                int32 damage = spell->GetEffect(EFFECT_0)->CalcValue(caster);
                int32 bp0 = damage + damage * ((100 - (caster->GetHealthPct())) / 1.9);

                caster->CastCustomSpell(caster, SPELL_BURNING_BLOOD_DAMAGE, &bp0, 0, 0, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_burning_blood_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_burning_blood_AuraScript();
    }
};

class spell_elementium_blast : public SpellScriptLoader
{
public:
    spell_elementium_blast() : SpellScriptLoader("spell_elementium_blast") { }

    class spell_elementium_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_elementium_blast_SpellScript);

        int32 initialDamage;
        int32 damageAmount;
        uint32 distance;

        bool Load()
        {
            initialDamage = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
            return GetCaster()->GetTypeId() == TYPEID_UNIT;
        }

        void CalcDamage(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    distance = caster->GetExactDist2d(target);
                    damageAmount = initialDamage - (distance * 12000);
                    SetHitDamage(damageAmount);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_elementium_blast_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_elementium_blast_SpellScript();
    }
};

class spell_corrupting_parasite : public SpellScriptLoader
{

public:
    spell_corrupting_parasite() : SpellScriptLoader("spell_corrupting_parasite") { }

    class spell_corrupting_parasite_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_corrupting_parasite_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                {
                caster->CastSpell(target, SPELL_CORRUPTING_PARASITE_VEHICLE);
                caster->CastSpell(target, SPELL_CORRUPTING_PARASITE_DAMAGE);
                }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_corrupting_parasite_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_corrupting_parasite_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_corrupting_parasite_SpellScript();
    }
};

class spell_corrupting_parasite_aura : public SpellScriptLoader
{
public:
    spell_corrupting_parasite_aura() : SpellScriptLoader("spell_corrupting_parasite_aura") { }

    class spell_corrupting_parasite_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_corrupting_parasite_aura_AuraScript);

        void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* owner = GetUnitOwner())
                owner->SummonCreature(NPC_CORRUPTING_PARASITE, owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), owner->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_corrupting_parasite_aura_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_corrupting_parasite_aura_AuraScript();
    }
};

class spell_unstable_corruption : public SpellScriptLoader
{
public:
    spell_unstable_corruption() : SpellScriptLoader("spell_unstable_corruption") { }

    class spell_unstable_corruption_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_unstable_corruption_SpellScript);

        uint32 amount;
        int32 bp0;

        void CalcAmount(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    amount = 0.1f * (caster->GetHealth());
                    bp0 = amount;

                    SetHitDamage(amount);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_unstable_corruption_SpellScript::CalcAmount, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_unstable_corruption_SpellScript();
    }
};

class spell_congealing_blood_dummy : public SpellScriptLoader
{

public:
    spell_congealing_blood_dummy() : SpellScriptLoader("spell_congealing_blood_dummy") { }

    class spell_congealing_blood_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_congealing_blood_dummy_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetHitUnit())
                {
                target->CastSpell(caster, SPELL_CONGEALING_BLOOD_SUMMON);
                }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_congealing_blood_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_congealing_blood_dummy_SpellScript();
    }
};

class spell_congealing_blood : public SpellScriptLoader
{

public:
    spell_congealing_blood() : SpellScriptLoader("spell_congealing_blood") { }

    class spell_congealing_blood_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_congealing_blood_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_congealing_blood_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_congealing_blood_SpellScript();
    }
};

void AddSC_boss_deathwing()
{
    new between_maelstrom_platforms();
    new boss_deathwing();
    new npc_maelstrom_trall();
    new npc_arm_tentacle_one();
    new npc_arm_tentacle_two();
    new npc_wing_tentacle();
    new npc_elementium_meteor();
    new npc_mutated_corruption();
    new npc_regenerative_blood();
    new npc_blistering_tentacle();
    new npc_maelstrom_alexstrasza();
    new npc_maelstrom_kalecgos();
    new npc_maelstrom_ysera();
    new npc_maelstrom_nozdormu();
    new npc_corrupting_parasite();
    new npc_congealing_blood();
    new spell_carrying_winds();
    new spell_assault_aspects();
    new spell_hemorrhage();
    new spell_crush();
    new spell_elementium_terror_summon();
    new spell_impaling_tentacles();
    new spell_shrapnel();
    new spell_corrupted_blood();
    new spell_burning_blood;
    new spell_elementium_blast();
    new spell_corrupting_parasite();
    new spell_corrupting_parasite_aura();
    new spell_unstable_corruption();
    new spell_congealing_blood_dummy();
    new spell_congealing_blood();
}
