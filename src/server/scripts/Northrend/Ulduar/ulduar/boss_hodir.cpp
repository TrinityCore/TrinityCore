/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ulduar.h"

/* #TODO: Achievements
          Storm Cloud (Shaman ability)
          Destroying of Toasty Fires
*/

enum HodirYells
{
    SAY_AGGRO                                    = -1603210,
    SAY_SLAY_1                                   = -1603211,
    SAY_SLAY_2                                   = -1603212,
    SAY_FLASH_FREEZE                             = -1603213,
    SAY_STALACTITE                               = -1603214,
    SAY_DEATH                                    = -1603215,
    SAY_BERSERK                                  = -1603216,
    SAY_YS_HELP                                  = -1603217,
    SAY_HARD_MODE_FAILED                         = -1603218,

    EMOTE_FREEZE                                 = -1603209,
    EMOTE_BLOWS                                  = -1603219,
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

#define ACHIEVEMENT_CHEESE_THE_FREEZE            RAID_MODE(2961, 2962)
#define ACHIEVEMENT_GETTING_COLD_IN_HERE         RAID_MODE(2967, 2968)
#define ACHIEVEMENT_THIS_CACHE_WAS_RARE          RAID_MODE(3182, 3184)
#define ACHIEVEMENT_COOLEST_FRIENDS              RAID_MODE(2963, 2965)
#define FRIENDS_COUNT                            RAID_MODE(4, 8)
#define DATA_GETTING_COLD_IN_HERE                29672968 // 2967, 2968 are achievement IDs

const Position SummonPositions[8] =
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

uint32 Entry[8] =
{
    32897, 33325, 33328, 32893, 33326, 32901, 32900, 33327,
};

class npc_flash_freeze : public CreatureScript
{
    public:
        npc_flash_freeze() : CreatureScript("npc_flash_freeze") { }

        struct npc_flash_freezeAI : public ScriptedAI
        {
            npc_flash_freezeAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
                me->SetDisplayId(me->GetCreatureInfo()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
            }

            InstanceScript* instance;

            uint64 targetGUID;
            uint32 checkDespawnTimer;

            void Reset()
            {
                targetGUID = 0;
                checkDespawnTimer = 1000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->getVictim()->HasAura(SPELL_BLOCK_OF_ICE) || me->getVictim()->HasAura(SPELL_FLASH_FREEZE_HELPER))
                    return;

                if (checkDespawnTimer <= diff)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                        if (!target->isAlive())
                            me->DisappearAndDie();
                    checkDespawnTimer = 2500;
                }
                else
                    checkDespawnTimer -= diff;
            }

            void IsSummonedBy(Unit* summoner)
            {
                targetGUID = summoner->GetGUID();
                me->SetInCombatWith(summoner);
                me->AddThreat(summoner, 250.0f);
                if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                {
                    DoCast(target, SPELL_BLOCK_OF_ICE, true);
                    // Prevents to have Ice Block on other place than target is
                    me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                    if (target->GetTypeId() == TYPEID_PLAYER)
                        if (Creature* Hodir = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_HODIR) : 0))
                            Hodir->AI()->DoAction(ACTION_CHEESE_THE_FREEZE);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_flash_freezeAI(creature);
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
                me->SetDisplayId(me->GetCreatureInfo()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
                targetGUID = 0;
            }

            InstanceScript* instance;

            uint64 targetGUID;

            void IsSummonedBy(Unit* summoner)
            {
                targetGUID = summoner->GetGUID();
                summoner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);
                me->SetInCombatWith(summoner);
                me->AddThreat(summoner, 250.0f);
                summoner->AddThreat(me, 250.0f);
                if (Creature* target = ObjectAccessor::GetCreature(*me, targetGUID))
                {
                    DoCast(target, SPELL_FLASH_FREEZE_HELPER, true);
                    // Prevents to have Ice Block on other place than target is
                    me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
                }
            }

            void DamageTaken(Unit* who, uint32& /*damage*/)
            {
                if (Creature* Helper = ObjectAccessor::GetCreature(*me, targetGUID))
                {
                    Helper->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED | UNIT_FLAG_PACIFIED);

                    if (Creature* Hodir = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_HODIR) : 0))
                    {
                        if (!Hodir->isInCombat())
                        {
                            Hodir->SetReactState(REACT_AGGRESSIVE);
                            Hodir->AI()->DoZoneInCombat();
                            Hodir->AI()->AttackStart(who);
                        }

                        Helper->AI()->AttackStart(Hodir);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ice_blockAI(creature);
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
                me->SetReactState(REACT_PASSIVE);
            }

            uint32 gettingColdInHereTimer;

            bool gettingColdInHere;
            bool cheeseTheFreeze;
            bool iHaveTheCoolestFriends;
            bool iCouldSayThatThisCacheWasRare;

            void Reset()
            {
                _Reset();
                me->SetReactState(REACT_PASSIVE);

                for (uint8 n = 0; n < FRIENDS_COUNT; ++n)
                    if (Creature* FrozenHelper = me->SummonCreature(Entry[n], SummonPositions[n], TEMPSUMMON_MANUAL_DESPAWN))
                        FrozenHelper->CastSpell(FrozenHelper, SPELL_SUMMON_FLASH_FREEZE_HELPER, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                DoScriptText(SAY_AGGRO, me);
                DoCast(me, SPELL_BITING_COLD, true);

                gettingColdInHereTimer = 1000;
                gettingColdInHere = true;
                cheeseTheFreeze = true;
                iHaveTheCoolestFriends = true;
                iCouldSayThatThisCacheWasRare = true;

                events.ScheduleEvent(EVENT_ICICLE, 2000);
                events.ScheduleEvent(EVENT_FREEZE, 25000);
                events.ScheduleEvent(EVENT_BLOWS, urand(60000, 65000));
                events.ScheduleEvent(EVENT_FLASH_FREEZE, 45000);
                events.ScheduleEvent(EVENT_RARE_CACHE, 180000);
                events.ScheduleEvent(EVENT_BERSERK, 480000);
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0, 3))
                    DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    _JustDied();
                    DoScriptText(SAY_DEATH, me);

                    me->RemoveAllAuras();
                    me->RemoveAllAttackers();
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
                    me->InterruptNonMeleeSpells(true);
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();
                    me->SetControlled(true, UNIT_STAT_STUNNED);
                    me->CombatStop(true);

                    me->setFaction(35);
                    me->DespawnOrUnsummon(10000);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FREEZE:
                            DoCastAOE(SPELL_FREEZE);
                            events.ScheduleEvent(EVENT_FREEZE, urand(30000, 45000));
                            break;
                        case EVENT_ICICLE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_ICICLE);
                            events.ScheduleEvent(EVENT_ICICLE, RAID_MODE(5500, 3500));
                            break;
                        case EVENT_FLASH_FREEZE:
                            DoScriptText(SAY_FLASH_FREEZE, me);
                            DoScriptText(EMOTE_FREEZE, me);
                            for (uint8 n = 0; n < RAID_MODE(2, 3); ++n)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                    target->CastSpell(target, SPELL_ICICLE_SNOWDRIFT, true);
                            DoCast(SPELL_FLASH_FREEZE);
                            events.ScheduleEvent(EVENT_FLASH_FREEZE_EFFECT, 500);
                            break;
                        case EVENT_FLASH_FREEZE_EFFECT:
                        {
                            std::list<Creature*> IcicleSnowdriftList;
                            GetCreatureListWithEntryInGrid(IcicleSnowdriftList, me, NPC_SNOWPACKED_ICICLE, 100.0f);
                            for (std::list<Creature*>::iterator itr = IcicleSnowdriftList.begin(); itr != IcicleSnowdriftList.end(); ++itr)
                                (*itr)->CastSpell(me, SPELL_FLASH_FREEZE_VISUAL, true);
                            FlashFreeze();
                            events.CancelEvent(EVENT_FLASH_FREEZE_EFFECT);
                            events.ScheduleEvent(EVENT_FLASH_FREEZE, urand(25000, 35000));
                            break;
                        }
                        case EVENT_BLOWS:
                            DoScriptText(SAY_STALACTITE, me);
                            DoScriptText(EMOTE_BLOWS, me);
                            DoCast(me, SPELL_FROZEN_BLOWS);
                            events.ScheduleEvent(EVENT_BLOWS, urand(60000, 65000));
                            break;
                        case EVENT_RARE_CACHE:
                            DoScriptText(SAY_HARD_MODE_FAILED, me);
                            iCouldSayThatThisCacheWasRare = false;
                            events.CancelEvent(EVENT_RARE_CACHE);
                            break;
                        case EVENT_BERSERK:
                            DoScriptText(SAY_BERSERK, me);
                            DoCast(me, SPELL_BERSERK, true);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                    }
                }

                if (gettingColdInHereTimer <= diff && gettingColdInHere)
                {
                    std::list<HostileReference*> ThreatList = me->getThreatManager().getThreatList();
                    for (std::list<HostileReference*>::const_iterator itr = ThreatList.begin(); itr != ThreatList.end(); ++itr)
                        if (Unit* target = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid()))
                            if (Aura* BitingColdAura = target->GetAura(SPELL_BITING_COLD_TRIGGERED))
                                if ((target->GetTypeId() == TYPEID_PLAYER) && (BitingColdAura->GetStackAmount() > 2))
                                        me->AI()->SetData(DATA_GETTING_COLD_IN_HERE, 0);
                    gettingColdInHereTimer = 1000;
                }
                else
                    gettingColdInHereTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void DoAction(const int32 action)
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
                me->VisitNearbyObject(100.0f, searcher);
                for (std::list<Unit*>::iterator itr = TargetList.begin(); itr != TargetList.end(); ++itr)
                {
                    Unit* target = *itr;
                    if (!target || !target->isAlive() || GetClosestCreatureWithEntry(target, NPC_SNOWPACKED_ICICLE, 5.0f))
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

        CreatureAI* GetAI(Creature* creature) const
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
                me->SetDisplayId(me->GetCreatureInfo()->Modelid1);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
            }

            uint32 icicleTimer;

            void Reset()
            {
                icicleTimer = 2500;
            }

            void UpdateAI(uint32 const diff)
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_icicleAI(creature);
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
                me->SetDisplayId(me->GetCreatureInfo()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->SetReactState(REACT_PASSIVE);
            }

            uint32 despawnTimer;

            void Reset()
            {
                despawnTimer = 12000;
            }

            void UpdateAI(uint32 const diff)
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowpacked_icicleAI(creature);
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

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_HEAL, urand(4000, 8000));
                events.ScheduleEvent(EVENT_DISPEL_MAGIC, urand(15000, 20000));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (HealthBelowPct(30))
                    DoCast(me, SPELL_GREATER_HEAL);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEAL:
                            DoCastAOE(SPELL_GREATER_HEAL);
                            events.ScheduleEvent(EVENT_HEAL, urand(7500, 10000));
                            break;
                        case EVENT_DISPEL_MAGIC:
                        {
                            std::list<Unit*> TargetList;
                            Trinity::AnyFriendlyUnitInObjectRangeCheck checker(me, me, 30.0f);
                            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, TargetList, checker);
                            me->VisitNearbyObject(30.0f, searcher);
                            for (std::list<Unit*>::iterator itr = TargetList.begin(); itr != TargetList.end(); ++itr)
                                if ((*itr)->HasAura(SPELL_FREEZE))
                                    DoCast(*itr, SPELL_DISPEL_MAGIC, true);
                            events.ScheduleEvent(EVENT_DISPEL_MAGIC, urand(15000, 20000));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_SMITE);
            }

            void JustDied(Unit* /*who*/)
 	        {
                if (Creature* Hodir = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_HODIR) : 0))
                    Hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
  	        }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hodir_priestAI(creature);
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

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_STORM_CLOUD, urand(10000, 12500));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STORM_CLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_STORM_CLOUD, true);
                            events.ScheduleEvent(EVENT_STORM_CLOUD, urand(15000, 20000));
                            break;
                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_LAVA_BURST);
            }

            void JustDied(Unit* /*who*/)
 	        {
                if (Creature* Hodir = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_HODIR) : 0))
                    Hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
  	        }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hodir_shamanAI(creature);
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

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_STARLIGHT, urand(15000, 17500));
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STARLIGHT:
                            DoCast(me, SPELL_STARLIGHT, true);
                            events.ScheduleEvent(EVENT_STARLIGHT, urand(25000, 35000));
                            break;
                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_WRATH);
            }

            void JustDied(Unit* /*who*/)
 	        {
                if (Creature* Hodir = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_HODIR) : 0))
                    Hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
  	        }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hodir_druidAI(creature);
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

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
                events.ScheduleEvent(EVENT_CONJURE_FIRE, urand(10000, 12500));
                events.ScheduleEvent(EVENT_MELT_ICE, 5000);
            }

            void JustSummoned(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_TOASTY_FIRE)
                    summons.Summon(summoned);
            }

            void SummonedCreatureDespawn(Creature* summoned)
            {
                if (summoned->GetEntry() == NPC_TOASTY_FIRE)
                    summons.remove(summoned->GetGUID());
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STAT_STUNNED) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CONJURE_FIRE:
                            if (summons.size() >= RAID_MODE(2, 4))
                                break;
                            DoCast(me, SPELL_CONJURE_FIRE, true);
                            events.ScheduleEvent(EVENT_CONJURE_FIRE, urand(15000, 20000));
                            break;
                        case EVENT_MELT_ICE:
                            if (Creature* FlashFreeze = me->FindNearestCreature(NPC_FLASH_FREEZE, 50.0f, true))
                                DoCast(FlashFreeze, SPELL_MELT_ICE, true);
                            events.ScheduleEvent(EVENT_MELT_ICE, urand(10000, 15000));
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_FIREBALL);
            }

            void JustDied(Unit* /*who*/)
 	        {
  	            if (Creature* Hodir = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_HODIR) : 0))
                    Hodir->AI()->DoAction(ACTION_I_HAVE_THE_COOLEST_FRIENDS);
  	        }

        private:
            InstanceScript* instance;
            EventMap events;
            SummonList summons;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hodir_mageAI(creature);
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
                me->SetDisplayId(me->GetCreatureInfo()->Modelid2);
            }

            void Reset()
            {
                DoCast(me, SPELL_SINGED, true);
            }

            void SpellHit(Unit* /*who*/, const SpellEntry* spell)
            {
                if (spell->Id == SPELL_BLOCK_OF_ICE || spell->Id == SPELL_ICE_SHARD || spell->Id == SPELL_ICE_SHARD_HIT)
                {
                    if (GameObject* ToastyFire = me->FindNearestGameObject(GO_TOASTY_FIRE, 1.0f))
                        me->RemoveGameObject(ToastyFire, true);
                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_toasty_fireAI(creature);
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
                Unit* caster = GetCaster();
                Unit* target = GetTarget();
                bool found = false;

                if (!caster || !target)
                    return;

                for (TargetList::iterator itr = listOfTargets.begin(); itr != listOfTargets.end(); ++itr)
                {
                    if (itr->first != target->GetGUID())
                        return;

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

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_biting_cold_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:
            typedef std::list< std::pair<uint64, uint8> > TargetList;
            TargetList listOfTargets;
        };

        AuraScript* GetAuraScript() const
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

            int32 damage = int32(200 * pow(2.0f, GetStackAmount()));
            caster->CastCustomSpell(caster, SPELL_BITING_COLD_DAMAGE, &damage, NULL, NULL, true);

            if (caster->isMoving())
                caster->RemoveAuraFromStack(SPELL_BITING_COLD_TRIGGERED);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_biting_cold_dot_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
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
