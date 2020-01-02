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
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ulduar.h"

/* @todo Achievements
          Storm Cloud (Shaman ability)
          Destroying of Toasty Fires
*/

/* @todo Hodir aggro behavior is wonky. He gets set to _PASSIVE, but never to _AGGRESSIVE unless you kill an ice block which doesn't spawn unless you have*/

enum HodirYells
{
    SAY_AGGRO                                    = 0,
    SAY_SLAY                                     = 1,
    SAY_FLASH_FREEZE                             = 2,
    SAY_STALACTITE                               = 3,
    SAY_DEATH                                    = 4,
    SAY_BERSERK                                  = 5,
    SAY_HARD_MODE_FAILED                         = 6,
    EMOTE_FREEZE                                 = 7,
    EMOTE_BLOWS                                  = 8
};

enum HodirSpells
{
    // Hodir
    SPELL_FROZEN_BLOWS                           = 62478,
    SPELL_FLASH_FREEZE                           = 61968,
    SPELL_FLASH_FREEZE_VISUAL                    = 62148,
    SPELL_BITING_COLD                            = 62038,
    SPELL_BITING_COLD_TRIGGERED                  = 62039, // Needed for Achievement Getting Cold In Here
    SPELL_BITING_COLD_DAMAGE                     = 62188,
    SPELL_FREEZE                                 = 62469,
    SPELL_ICICLE                                 = 62234,
    SPELL_ICICLE_SNOWDRIFT                       = 62462,
    SPELL_BLOCK_OF_ICE                           = 61969, // Player + Helper
    SPELL_SUMMON_FLASH_FREEZE_HELPER             = 61989, // Helper
    SPELL_SUMMON_BLOCK_OF_ICE                    = 61970, // Player + Helper
    SPELL_FLASH_FREEZE_HELPER                    = 61990, // Helper
    SPELL_FLASH_FREEZE_KILL                      = 62226,
    SPELL_ICICLE_FALL                            = 69428,
    SPELL_FALL_DAMAGE                            = 62236,
    SPELL_FALL_SNOWDRIFT                         = 62460,
    SPELL_BERSERK                                = 47008,
    SPELL_ICE_SHARD                              = 62457,
    SPELL_ICE_SHARD_HIT                          = 65370,

    SPELL_KILL_CREDIT                            = 64899,

    // Druids
    SPELL_WRATH                                  = 62793,
    SPELL_STARLIGHT                              = 62807,

    // Shamans
    SPELL_LAVA_BURST                             = 61924,
    SPELL_STORM_CLOUD                            = 65123,

    // Mages
    SPELL_FIREBALL                               = 61909,
    SPELL_CONJURE_FIRE                           = 62823,
    SPELL_MELT_ICE                               = 64528,
    SPELL_SINGED                                 = 62821,

    // Priests
    SPELL_SMITE                                  = 61923,
    SPELL_GREATER_HEAL                           = 62809,
    SPELL_DISPEL_MAGIC                           = 63499,
};

enum HodirNPC
{
    NPC_ICE_BLOCK                                = 32938,
    NPC_FLASH_FREEZE                             = 32926,
    NPC_SNOWPACKED_ICICLE                        = 33174,
    NPC_ICICLE                                   = 33169,
    NPC_ICICLE_SNOWDRIFT                         = 33173,
    NPC_TOASTY_FIRE                              = 33342,
};

enum HodirGameObjects
{
    GO_TOASTY_FIRE                               = 194300,
    GO_SNOWDRIFT                                 = 194173,
};

enum HodirEvents
{
    // Hodir
    EVENT_FREEZE                                 = 1,
    EVENT_FLASH_FREEZE                           = 2,
    EVENT_FLASH_FREEZE_EFFECT                    = 3,
    EVENT_ICICLE                                 = 4,
    EVENT_BLOWS                                  = 5,
    EVENT_RARE_CACHE                             = 6,
    EVENT_BERSERK                                = 7,

    // Priest
    EVENT_HEAL                                   = 8,
    EVENT_DISPEL_MAGIC                           = 9,

    // Shaman
    EVENT_STORM_CLOUD                            = 10,

    // Druid
    EVENT_STARLIGHT                              = 11,

    // Mage
    EVENT_CONJURE_FIRE                           = 12,
    EVENT_MELT_ICE                               = 13,
};

enum HodirActions
{
    ACTION_I_HAVE_THE_COOLEST_FRIENDS            = 1,
    ACTION_CHEESE_THE_FREEZE                     = 2,
};

#define ACHIEVEMENT_CHEESE_THE_FREEZE            RAID_MODE<uint8>(2961, 2962)
#define ACHIEVEMENT_GETTING_COLD_IN_HERE         RAID_MODE<uint8>(2967, 2968)
#define ACHIEVEMENT_THIS_CACHE_WAS_RARE          RAID_MODE<uint8>(3182, 3184)
#define ACHIEVEMENT_COOLEST_FRIENDS              RAID_MODE<uint8>(2963, 2965)
#define FRIENDS_COUNT                            RAID_MODE<uint8>(4, 8)

enum Misc
{
    DATA_GETTING_COLD_IN_HERE                    = 29672968 // 2967, 2968 are achievement IDs
};

Position const SummonPositions[8] =
{
    { 1983.75f, -243.36f, 432.767f, 1.57f }, // Field Medic Penny    &&  Battle-Priest Eliza
    { 1999.90f, -230.49f, 432.767f, 1.57f }, // Eivi Nightfeather    &&  Tor Greycloud
    { 2010.06f, -243.45f, 432.767f, 1.57f }, // Elementalist Mahfuun &&  Spiritwalker Tara
    { 2021.12f, -236.65f, 432.767f, 1.57f }, // Missy Flamecuffs     &&  Amira Blazeweaver
    { 2028.10f, -244.66f, 432.767f, 1.57f }, // Field Medic Jessi    &&  Battle-Priest Gina
    { 2014.18f, -232.80f, 432.767f, 1.57f }, // Ellie Nightfeather   &&  Kar Greycloud
    { 1992.90f, -237.54f, 432.767f, 1.57f }, // Elementalist Avuun   &&  Spiritwalker Yona
    { 1976.60f, -233.53f, 432.767f, 1.57f }, // Sissy Flamecuffs     &&  Veesha Blazeweaver
};

uint32 const Entry[8] =
{
    NPC_FIELD_MEDIC_PENNY,
    NPC_EIVI_NIGHTFEATHER,
    NPC_ELEMENTALIST_MAHFUUN,
    NPC_MISSY_FLAMECUFFS,
    NPC_FIELD_MEDIC_JESSI,
    NPC_ELLIE_NIGHTFEATHER,
    NPC_ELEMENTALIST_AVUUN,
    NPC_SISSY_FLAMECUFFS,
};

class npc_flash_freeze : public CreatureScript
{
    public:
        npc_flash_freeze() : CreatureScript("npc_flash_freeze") { }

        struct npc_flash_freezeAI : public ScriptedAI
        {
            npc_flash_freezeAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = me->GetInstanceScript();
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
                me->SetControlled(true, UNIT_STATE_ROOT);
            }

            void Initialize()
            {
                targetGUID.Clear();
                checkDespawnTimer = 1000;
            }

            InstanceScript* instance;

            ObjectGuid targetGUID;
            uint32 checkDespawnTimer;

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim()
                 || !me->GetVictim()
                 || me->EnsureVictim()->HasAura(SPELL_BLOCK_OF_ICE)
                 || me->EnsureVictim()->HasAura(SPELL_FLASH_FREEZE_HELPER))
                    return;

                if (me->EnsureVictim()->GetGUID() != targetGUID || instance->GetBossState(BOSS_HODIR) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (checkDespawnTimer <= diff)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                        if (!target->IsAlive())
                            me->DisappearAndDie();
                    checkDespawnTimer = 2500;
                }
                else
                    checkDespawnTimer -= diff;
            }

            void IsSummonedBy(WorldObject* summonerWO) override
            {
                Unit* summoner = summonerWO->ToUnit();
                if (!summoner)
                    return;

                targetGUID = summoner->GetGUID();
                me->SetInCombatWith(summoner);
                AddThreat(summoner, 250.0f);
                if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                {
                    DoCast(target, SPELL_BLOCK_OF_ICE, true);
                    // Prevents to have Ice Block on other place than target is
                    me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                    if (target->GetTypeId() == TYPEID_PLAYER)
                        if (Creature* hodir = instance->GetCreature(BOSS_HODIR))
                            hodir->AI()->DoAction(ACTION_CHEESE_THE_FREEZE);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_flash_freezeAI>(creature);
        }
};

class npc_ice_block : public CreatureScript
{
    public:
        npc_ice_block() : CreatureScript("npc_ice_block") { }

        struct npc_ice_blockAI : public ScriptedAI
        {
            npc_ice_blockAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
                me->SetControlled(true, UNIT_STATE_ROOT);
            }

            InstanceScript* instance;

            ObjectGuid targetGUID;

            void IsSummonedBy(WorldObject* summonerWO) override
            {
                Unit* summoner = summonerWO->ToUnit();
                if (!summoner)
                    return;

                targetGUID = summoner->GetGUID();
                summoner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
                summoner->SetControlled(true, UNIT_STATE_ROOT);
                me->SetInCombatWith(summoner);
                AddThreat(summoner, 250.0f);
                AddThreat(me, 250.0f, summoner);
                if (Creature* target = ObjectAccessor::GetCreature(*me, targetGUID))
                {
                    DoCast(target, SPELL_FLASH_FREEZE_HELPER, true);
                    // Prevents to have Ice Block on other place than target is
                    me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                }
            }

            void DamageTaken(Unit* who, uint32& /*damage*/) override
            {
                if (Creature* helper = ObjectAccessor::GetCreature(*me, targetGUID))
                {
                    helper->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
                    helper->SetControlled(false, UNIT_STATE_ROOT);

                    if (Creature* hodir = instance->GetCreature(BOSS_HODIR))
                    {
                        if (!hodir->IsInCombat())
                        {
                            hodir->SetReactState(REACT_AGGRESSIVE);
                            hodir->AI()->DoZoneInCombat();
                            hodir->AI()->AttackStart(who);
                        }

                        helper->AI()->AttackStart(hodir);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_ice_blockAI>(creature);
        }
};

class boss_hodir : public CreatureScript
{
    public:
        boss_hodir() : CreatureScript("boss_hodir") { }

        struct boss_hodirAI : public BossAI
        {
            boss_hodirAI(Creature* creature) : BossAI(creature, BOSS_HODIR)
            {
                Initialize();
                me->SetReactState(REACT_PASSIVE);
            }

            void Initialize()
            {
                gettingColdInHereTimer = 0;
                gettingColdInHere = false;
                cheeseTheFreeze = false;
                iHaveTheCoolestFriends = false;
                iCouldSayThatThisCacheWasRare = false;
            }

            uint32 gettingColdInHereTimer;

            bool gettingColdInHere;
            bool cheeseTheFreeze;
            bool iHaveTheCoolestFriends;
            bool iCouldSayThatThisCacheWasRare;

            void Reset() override
            {
                Initialize();

                _Reset();
                me->SetReactState(REACT_PASSIVE);

                for (uint8 n = 0; n < FRIENDS_COUNT; ++n)
                    if (Creature* FrozenHelper = me->SummonCreature(Entry[n], SummonPositions[n], TEMPSUMMON_MANUAL_DESPAWN))
                        FrozenHelper->CastSpell(FrozenHelper, SPELL_SUMMON_FLASH_FREEZE_HELPER, true);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_BITING_COLD, true);

                gettingColdInHereTimer = 1000;
                gettingColdInHere = true;
                cheeseTheFreeze = true;
                iHaveTheCoolestFriends = true;
                iCouldSayThatThisCacheWasRare = true;

                events.ScheduleEvent(EVENT_ICICLE, 2s);
                events.ScheduleEvent(EVENT_FREEZE, 25s);
                events.ScheduleEvent(EVENT_BLOWS, 60s, 65s);
                events.ScheduleEvent(EVENT_FLASH_FREEZE, 45s);
                events.ScheduleEvent(EVENT_RARE_CACHE, 3min);
                events.ScheduleEvent(EVENT_BERSERK, 8min);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    Talk(SAY_DEATH);
                    if (iCouldSayThatThisCacheWasRare)
                        instance->SetData(DATA_HODIR_RARE_CACHE, 1);

                    me->RemoveAllAuras();
                    me->RemoveAllAttackers();
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->InterruptNonMeleeSpells(true);
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    me->SetControlled(true, UNIT_STATE_STUNNED);
                    me->CombatStop(true);

                    DoCastAOE(SPELL_KILL_CREDIT, true); /// need to be cast before changing boss faction
                                                        /// spell will target enemies only
                    me->SetFaction(FACTION_FRIENDLY);
                    me->DespawnOrUnsummon(10000);

                    _JustDied();
                }
                else if (!me->IsInCombat())
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->AI()->DoZoneInCombat();
                    me->AI()->AttackStart(who);
                }
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
                        case EVENT_FREEZE:
                            DoCastAOE(SPELL_FREEZE);
                            events.ScheduleEvent(EVENT_FREEZE, 30s, 45s);
                            break;
                        case EVENT_ICICLE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_ICICLE);
                            events.ScheduleEvent(EVENT_ICICLE, RAID_MODE(5500, 3500));
                            break;
                        case EVENT_FLASH_FREEZE:
                            Talk(SAY_FLASH_FREEZE);
                            Talk(EMOTE_FREEZE);
                            for (uint8 n = 0; n < RAID_MODE(2, 3); ++n)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                    target->CastSpell(target, SPELL_ICICLE_SNOWDRIFT, true);
                            DoCast(SPELL_FLASH_FREEZE);
                            events.ScheduleEvent(EVENT_FLASH_FREEZE_EFFECT, 500ms);
                            break;
                        case EVENT_FLASH_FREEZE_EFFECT:
                        {
                            std::list<Creature*> IcicleSnowdriftList;
                            GetCreatureListWithEntryInGrid(IcicleSnowdriftList, me, NPC_SNOWPACKED_ICICLE, 100.0f);
                            for (std::list<Creature*>::iterator itr = IcicleSnowdriftList.begin(); itr != IcicleSnowdriftList.end(); ++itr)
                                (*itr)->CastSpell(me, SPELL_FLASH_FREEZE_VISUAL, true);
                            FlashFreeze();
                            events.CancelEvent(EVENT_FLASH_FREEZE_EFFECT);
                            events.ScheduleEvent(EVENT_FLASH_FREEZE, 25s, 35s);
                            break;
                        }
                        case EVENT_BLOWS:
                            Talk(SAY_STALACTITE);
                            Talk(EMOTE_BLOWS);
                            DoCast(me, SPELL_FROZEN_BLOWS);
                            events.ScheduleEvent(EVENT_BLOWS, 60s, 65s);
                            break;
                        case EVENT_RARE_CACHE:
                            Talk(SAY_HARD_MODE_FAILED);
                            iCouldSayThatThisCacheWasRare = false;
                            instance->SetData(DATA_HODIR_RARE_CACHE, 0);
                            events.CancelEvent(EVENT_RARE_CACHE);
                            break;
                        case EVENT_BERSERK:
                            Talk(SAY_BERSERK);
                            DoCast(me, SPELL_BERSERK, true);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                if (gettingColdInHereTimer <= diff && gettingColdInHere)
                {
                    for (auto const& pair : me->GetCombatManager().GetPvECombatRefs())
                        if (Player* target = pair.second->GetOther(me)->ToPlayer())
                            if (Aura* BitingColdAura = target->GetAura(SPELL_BITING_COLD_TRIGGERED))
                                if (BitingColdAura->GetStackAmount() > 2)
                                    SetData(DATA_GETTING_COLD_IN_HERE, 0);
                    gettingColdInHereTimer = 1000;
                }
                else
                    gettingColdInHereTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_I_HAVE_THE_COOLEST_FRIENDS:
                        iHaveTheCoolestFriends = false;
                        break;
                    case ACTION_CHEESE_THE_FREEZE:
                        cheeseTheFreeze = false;
                        break;
                    default:
                        break;
                }
            }

            void FlashFreeze()
            {
                std::list<Unit*> TargetList;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck checker(me, me, 100.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, TargetList, checker);
                Cell::VisitAllObjects(me, searcher, 100.0f);
                for (std::list<Unit*>::iterator itr = TargetList.begin(); itr != TargetList.end(); ++itr)
                {
                    Unit* target = *itr;
                    if (!target || !target->IsAlive() || GetClosestCreatureWithEntry(target, NPC_SNOWPACKED_ICICLE, 5.0f))
                        continue;

                    if (target->HasAura(SPELL_FLASH_FREEZE_HELPER) || target->HasAura(SPELL_BLOCK_OF_ICE))
                    {
                        me->CastSpell(target, SPELL_FLASH_FREEZE_KILL, true);
                        continue;
                    }

                    target->CastSpell(target, SPELL_SUMMON_BLOCK_OF_ICE, true);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_hodirAI>(creature);
        };
};

class npc_icicle : public CreatureScript
{
    public:
        npc_icicle() : CreatureScript("npc_icicle") { }

        struct npc_icicleAI : public ScriptedAI
        {
            npc_icicleAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_NOT_SELECTABLE);
                me->SetControlled(true, UNIT_STATE_ROOT);
                me->SetReactState(REACT_PASSIVE);
            }

            void Initialize()
            {
                icicleTimer = 2500;
            }

            uint32 icicleTimer;

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                if (icicleTimer <= diff)
                {
                    if (me->GetEntry() == NPC_ICICLE_SNOWDRIFT)
                    {
                        DoCast(me, SPELL_FALL_SNOWDRIFT);
                        DoCast(me, SPELL_ICICLE_FALL);
                    }
                    else if (me->GetEntry() == NPC_ICICLE)
                    {
                        DoCast(me, SPELL_ICICLE_FALL);
                        DoCast(me, SPELL_FALL_DAMAGE, true);
                    }
                    icicleTimer = 10000;
                }
                else
                    icicleTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_icicleAI>(creature);
        };
};

class npc_snowpacked_icicle : public CreatureScript
{
    public:
        npc_snowpacked_icicle() : CreatureScript("npc_snowpacked_icicle") { }

        struct npc_snowpacked_icicleAI : public ScriptedAI
        {
            npc_snowpacked_icicleAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->SetControlled(true, UNIT_STATE_ROOT);
                me->SetReactState(REACT_PASSIVE);
            }

            void Initialize()
            {
                despawnTimer = 12000;
            }

            uint32 despawnTimer;

            void Reset() override
            {
                Initialize();
            }

            void UpdateAI(uint32 diff) override
            {
                if (despawnTimer <= diff)
                {
                    if (GameObject* Snowdrift = me->FindNearestGameObject(GO_SNOWDRIFT, 2.0f))
                        me->RemoveGameObject(Snowdrift, true);
                    me->DespawnOrUnsummon();
                }
                else
                    despawnTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_snowpacked_icicleAI>(creature);
        };
};

class npc_hodir_priest : public CreatureScript
{
    public:
        npc_hodir_priest() : CreatureScript("npc_hodir_priest") { }

        struct npc_hodir_priestAI : public ScriptedAI
        {
            npc_hodir_priestAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_HEAL, 4s, 8s);
                events.ScheduleEvent(EVENT_DISPEL_MAGIC, 15s, 20s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (HealthBelowPct(30))
                    DoCast(me, SPELL_GREATER_HEAL);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEAL:
                            DoCastAOE(SPELL_GREATER_HEAL);
                            events.ScheduleEvent(EVENT_HEAL, 7500ms, 10s);
                            break;
                        case EVENT_DISPEL_MAGIC:
                        {
                            std::list<Unit*> TargetList;
                            Trinity::AnyFriendlyUnitInObjectRangeCheck checker(me, me, 30.0f);
                            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, TargetList, checker);
                            Cell::VisitAllObjects(me, searcher, 30.0f);
                            for (std::list<Unit*>::iterator itr = TargetList.begin(); itr != TargetList.end(); ++itr)
                                if ((*itr)->HasAura(SPELL_FREEZE))
                                    DoCast(*itr, SPELL_DISPEL_MAGIC, true);
                            events.ScheduleEvent(EVENT_DISPEL_MAGIC, 15s, 20s);
                            break;
                        }
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoSpellAttackIfReady(SPELL_SMITE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* hodir = instance->GetCreature(BOSS_HODIR))
                    hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_hodir_priestAI>(creature);
        };
};

class npc_hodir_shaman : public CreatureScript
{
    public:
        npc_hodir_shaman() : CreatureScript("npc_hodir_shaman") { }

        struct npc_hodir_shamanAI : public ScriptedAI
        {
            npc_hodir_shamanAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_STORM_CLOUD, 10s, 12500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STORM_CLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_STORM_CLOUD, true);
                            events.ScheduleEvent(EVENT_STORM_CLOUD, 15s, 20s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoSpellAttackIfReady(SPELL_LAVA_BURST);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* hodir = instance->GetCreature(BOSS_HODIR))
                    hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_hodir_shamanAI>(creature);
        };
};

class npc_hodir_druid : public CreatureScript
{
    public:
        npc_hodir_druid() : CreatureScript("npc_hodir_druid") { }

        struct npc_hodir_druidAI : public ScriptedAI
        {
            npc_hodir_druidAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_STARLIGHT, 15s, 17500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STARLIGHT:
                            DoCast(me, SPELL_STARLIGHT, true);
                            events.ScheduleEvent(EVENT_STARLIGHT, 25s, 35s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoSpellAttackIfReady(SPELL_WRATH);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* hodir = instance->GetCreature(BOSS_HODIR))
                    hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_hodir_druidAI>(creature);
        };
};

class npc_hodir_mage : public CreatureScript
{
    public:
        npc_hodir_mage() : CreatureScript("npc_hodir_mage") { }

        struct npc_hodir_mageAI : public ScriptedAI
        {
            npc_hodir_mageAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();
                events.ScheduleEvent(EVENT_CONJURE_FIRE, 10s, 12500ms);
                events.ScheduleEvent(EVENT_MELT_ICE, 5s);
            }

            void JustSummoned(Creature* summoned) override
            {
                if (summoned->GetEntry() == NPC_TOASTY_FIRE)
                    summons.Summon(summoned);
            }

            void SummonedCreatureDespawn(Creature* summoned) override
            {
                if (summoned->GetEntry() == NPC_TOASTY_FIRE)
                    summons.Despawn(summoned);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CONJURE_FIRE:
                            if (summons.size() >= RAID_MODE<uint64>(2, 4))
                                break;
                            DoCast(me, SPELL_CONJURE_FIRE, true);
                            events.ScheduleEvent(EVENT_CONJURE_FIRE, 15s, 20s);
                            break;
                        case EVENT_MELT_ICE:
                            if (Creature* FlashFreeze = me->FindNearestCreature(NPC_FLASH_FREEZE, 50.0f, true))
                                DoCast(FlashFreeze, SPELL_MELT_ICE, true);
                            events.ScheduleEvent(EVENT_MELT_ICE, 10s, 15s);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoSpellAttackIfReady(SPELL_FIREBALL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* hodir = instance->GetCreature(BOSS_HODIR))
                    hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
            }

        private:
            InstanceScript* instance;
            EventMap events;
            SummonList summons;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_hodir_mageAI>(creature);
        };
};

class npc_toasty_fire : public CreatureScript
{
    public:
        npc_toasty_fire() : CreatureScript("npc_toasty_fire") { }

        struct npc_toasty_fireAI : public ScriptedAI
        {
            npc_toasty_fireAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void Reset() override
            {
                DoCast(me, SPELL_SINGED, true);
            }

            void SpellHit(Unit* /*who*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_BLOCK_OF_ICE || spell->Id == SPELL_ICE_SHARD || spell->Id == SPELL_ICE_SHARD_HIT)
                {
                    if (GameObject* ToastyFire = me->FindNearestGameObject(GO_TOASTY_FIRE, 1.0f))
                        me->RemoveGameObject(ToastyFire, true);
                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_toasty_fireAI>(creature);
        };
};

class spell_biting_cold : public SpellScriptLoader
{
    public:
        spell_biting_cold() : SpellScriptLoader("spell_biting_cold") { }

        class spell_biting_cold_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_biting_cold_AuraScript);

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();
                bool found = false;

                for (TargetList::iterator itr = listOfTargets.begin(); itr != listOfTargets.end(); ++itr)
                {
                    if (itr->first != target->GetGUID())
                        continue;

                    if (itr->second >= 4)
                    {
                        target->CastSpell(target, SPELL_BITING_COLD_TRIGGERED, true);
                        itr->second = 1;
                    }
                    else
                    {
                        if (target->isMoving())
                            itr->second = 1;
                        else
                            itr->second++;
                    }

                    found = true;
                    break;
                }

                if (!found)
                    listOfTargets.push_back(std::make_pair(target->GetGUID(), 1));
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_biting_cold_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:
            typedef std::list<std::pair<ObjectGuid, uint8>> TargetList;
            TargetList listOfTargets;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_biting_cold_AuraScript();
        }
};

class spell_biting_cold_dot : public SpellScriptLoader
{
public:
    spell_biting_cold_dot() : SpellScriptLoader("spell_biting_cold_dot") { }

    class spell_biting_cold_dot_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_biting_cold_dot_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 damage = int32(200 * std::pow(2.0f, GetStackAmount()));
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellBP0(damage);
            caster->CastSpell(caster, SPELL_BITING_COLD_DAMAGE, args);

            if (caster->isMoving())
                caster->RemoveAuraFromStack(SPELL_BITING_COLD_TRIGGERED);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_biting_cold_dot_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_biting_cold_dot_AuraScript();
    }
};

void AddSC_boss_hodir()
{
    new boss_hodir();
    new npc_icicle();
    new npc_snowpacked_icicle();
    new npc_hodir_priest();
    new npc_hodir_shaman();
    new npc_hodir_druid();
    new npc_hodir_mage();
    new npc_toasty_fire();
    new npc_ice_block();
    new npc_flash_freeze();
    new spell_biting_cold();
    new spell_biting_cold_dot();
}
