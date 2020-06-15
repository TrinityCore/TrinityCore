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
#include "CreatureTextMgr.h"
#include "CombatAI.h"
#include "GameEventMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "MoveSplineInit.h"

/*########
# npc_air_force_bots
#########*/

enum SpawnType
{
    SPAWNTYPE_TRIPWIRE_ROOFTOP,                             // no warning, summon Creature at smaller range
    SPAWNTYPE_ALARMBOT,                                     // cast guards mark and summon npc - if player shows up with that buff duration < 5 seconds attack
};

struct SpawnAssociation
{
    uint32 thisCreatureEntry;
    uint32 spawnedCreatureEntry;
    SpawnType spawnType;
};

enum AirFoceBots
{
    SPELL_GUARDS_MARK               = 38067,
    AURA_DURATION_TIME_LEFT         = 5000
};

float const RANGE_TRIPWIRE          = 15.0f;
float const RANGE_GUARDS_MARK       = 50.0f;

SpawnAssociation spawnAssociations[] =
{
    {2614,  15241, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Alliance)
    {2615,  15242, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Horde)
    {21974, 21976, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Area 52)
    {21993, 15242, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Horde - Bat Rider)
    {21996, 15241, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Alliance - Gryphon)
    {21997, 21976, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Goblin - Area 52 - Zeppelin)
    {21999, 15241, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Alliance)
    {22001, 15242, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Horde)
    {22002, 15242, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Ground (Horde)
    {22003, 15241, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Ground (Alliance)
    {22063, 21976, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Goblin - Area 52)
    {22065, 22064, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Ethereal - Stormspire)
    {22066, 22067, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Scryer - Dragonhawk)
    {22068, 22064, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
    {22069, 22064, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Stormspire)
    {22070, 22067, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Scryer)
    {22071, 22067, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Scryer)
    {22078, 22077, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Aldor)
    {22079, 22077, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Aldor - Gryphon)
    {22080, 22077, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Aldor)
    {22086, 22085, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Sporeggar)
    {22087, 22085, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Sporeggar - Spore Bat)
    {22088, 22085, SPAWNTYPE_TRIPWIRE_ROOFTOP},             //Air Force Trip Wire - Rooftop (Sporeggar)
    {22090, 22089, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Toshley's Station - Flying Machine)
    {22124, 22122, SPAWNTYPE_ALARMBOT},                     //Air Force Alarm Bot (Cenarion)
    {22125, 22122, SPAWNTYPE_ALARMBOT},                     //Air Force Guard Post (Cenarion - Stormcrow)
    {22126, 22122, SPAWNTYPE_ALARMBOT}                      //Air Force Trip Wire - Rooftop (Cenarion Expedition)
};

class npc_air_force_bots : public CreatureScript
{
public:
    npc_air_force_bots() : CreatureScript("npc_air_force_bots") { }

    struct npc_air_force_botsAI : public ScriptedAI
    {
        npc_air_force_botsAI(Creature* creature) : ScriptedAI(creature)
        {
            SpawnAssoc = NULL;
            SpawnedGUID.Clear();

            // find the correct spawnhandling
            static uint32 entryCount = sizeof(spawnAssociations) / sizeof(SpawnAssociation);

            for (uint8 i = 0; i < entryCount; ++i)
            {
                if (spawnAssociations[i].thisCreatureEntry == creature->GetEntry())
                {
                    SpawnAssoc = &spawnAssociations[i];
                    break;
                }
            }

            if (!SpawnAssoc)
                TC_LOG_ERROR("sql.sql", "TCSR: Creature template entry %u has ScriptName npc_air_force_bots, but it's not handled by that script", creature->GetEntry());
            else
            {
                CreatureTemplate const* spawnedTemplate = sObjectMgr->GetCreatureTemplate(SpawnAssoc->spawnedCreatureEntry);

                if (!spawnedTemplate)
                {
                    TC_LOG_ERROR("sql.sql", "TCSR: Creature template entry %u does not exist in DB, which is required by npc_air_force_bots", SpawnAssoc->spawnedCreatureEntry);
                    SpawnAssoc = NULL;
                    return;
                }
            }
        }

        SpawnAssociation* SpawnAssoc;
        ObjectGuid SpawnedGUID;

        void Reset() override { }

        Creature* SummonGuard()
        {
            Creature* summoned = me->SummonCreature(SpawnAssoc->spawnedCreatureEntry, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);

            if (summoned)
                SpawnedGUID = summoned->GetGUID();
            else
            {
                TC_LOG_ERROR("sql.sql", "TCSR: npc_air_force_bots: wasn't able to spawn Creature %u", SpawnAssoc->spawnedCreatureEntry);
                SpawnAssoc = NULL;
            }

            return summoned;
        }

        Creature* GetSummonedGuard()
        {
            Creature* creature = ObjectAccessor::GetCreature(*me, SpawnedGUID);

            if (creature && creature->IsAlive())
                return creature;

            return NULL;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!SpawnAssoc)
                return;

            if (me->IsValidAttackTarget(who))
            {
                Player* playerTarget = who->ToPlayer();

                // airforce guards only spawn for players
                if (!playerTarget)
                    return;

                Creature* lastSpawnedGuard = SpawnedGUID.IsEmpty() ? NULL : GetSummonedGuard();

                // prevent calling Unit::GetUnit at next MoveInLineOfSight call - speedup
                if (!lastSpawnedGuard)
                    SpawnedGUID.Clear();

                switch (SpawnAssoc->spawnType)
                {
                    case SPAWNTYPE_ALARMBOT:
                    {
                        if (!who->IsWithinDistInMap(me, RANGE_GUARDS_MARK))
                            return;

                        Aura* markAura = who->GetAura(SPELL_GUARDS_MARK);
                        if (markAura)
                        {
                            // the target wasn't able to move out of our range within 25 seconds
                            if (!lastSpawnedGuard)
                            {
                                lastSpawnedGuard = SummonGuard();

                                if (!lastSpawnedGuard)
                                    return;
                            }

                            if (markAura->GetDuration() < AURA_DURATION_TIME_LEFT)
                                if (!lastSpawnedGuard->GetVictim())
                                    lastSpawnedGuard->AI()->AttackStart(who);
                        }
                        else
                        {
                            if (!lastSpawnedGuard)
                                lastSpawnedGuard = SummonGuard();

                            if (!lastSpawnedGuard)
                                return;

                            lastSpawnedGuard->CastSpell(who, SPELL_GUARDS_MARK, true);
                        }
                        break;
                    }
                    case SPAWNTYPE_TRIPWIRE_ROOFTOP:
                    {
                        if (!who->IsWithinDistInMap(me, RANGE_TRIPWIRE))
                            return;

                        if (!lastSpawnedGuard)
                            lastSpawnedGuard = SummonGuard();

                        if (!lastSpawnedGuard)
                            return;

                        // ROOFTOP only triggers if the player is on the ground
                        if (!playerTarget->IsFlying() && !lastSpawnedGuard->GetVictim())
                            lastSpawnedGuard->AI()->AttackStart(who);

                        break;
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_air_force_botsAI(creature);
    }
};

/*########
# npc_chicken_cluck
#########*/

enum ChickenCluck
{
    EMOTE_HELLO_A       = 0,
    EMOTE_HELLO_H       = 1,
    EMOTE_CLUCK_TEXT    = 2,

    QUEST_CLUCK         = 3861,
};

class npc_chicken_cluck : public CreatureScript
{
public:
    npc_chicken_cluck() : CreatureScript("npc_chicken_cluck") { }

    struct npc_chicken_cluckAI : public ScriptedAI
    {
        npc_chicken_cluckAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ResetFlagTimer = 120000;
        }

        uint32 ResetFlagTimer;

        void Reset() override
        {
            Initialize();
            me->SetFaction(FACTION_PREY);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            // Reset flags after a certain time has passed so that the next player has to start the 'event' again
            if (me->HasNpcFlag(UNIT_NPC_FLAG_QUESTGIVER))
            {
                if (ResetFlagTimer <= diff)
                {
                    EnterEvadeMode();
                    return;
                }
                else
                    ResetFlagTimer -= diff;
            }

            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            switch (emote)
            {
                case TEXT_EMOTE_CHICKEN:
                    if (player->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_NONE && rand32() % 30 == 1)
                    {
                        me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFaction(FACTION_FRIENDLY);
                        Talk(player->GetTeam() == HORDE ? EMOTE_HELLO_H : EMOTE_HELLO_A);
                    }
                    break;
                case TEXT_EMOTE_CHEER:
                    if (player->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_COMPLETE)
                    {
                        me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFaction(FACTION_FRIENDLY);
                        Talk(EMOTE_CLUCK_TEXT);
                    }
                    break;
            }
        }

        void QuestAccept(Player* /*player*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_CLUCK)
                Reset();
        }

        void QuestReward(Player* /*player*/, Quest const* quest, uint32 /*opt*/) override
        {
            if (quest->GetQuestId() == QUEST_CLUCK)
                Reset();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chicken_cluckAI(creature);
    }
};

/*######
## npc_dancing_flames
######*/

enum DancingFlames
{
    SPELL_BRAZIER           = 45423,
    SPELL_SEDUCTION         = 47057,
    SPELL_FIERY_AURA        = 45427
};

class npc_dancing_flames : public CreatureScript
{
public:
    npc_dancing_flames() : CreatureScript("npc_dancing_flames") { }

    struct npc_dancing_flamesAI : public ScriptedAI
    {
        npc_dancing_flamesAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            Active = true;
            CanIteract = 3500;
        }

        bool Active;
        uint32 CanIteract;

        void Reset() override
        {
            Initialize();
            DoCast(me, SPELL_BRAZIER, true);
            DoCast(me, SPELL_FIERY_AURA, false);
            float x, y, z;
            me->GetPosition(x, y, z);
            me->Relocate(x, y, z + 0.94f);
            me->SetDisableGravity(true);
            me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!Active)
            {
                if (CanIteract <= diff)
                {
                    Active = true;
                    CanIteract = 3500;
                    me->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
                }
                else
                    CanIteract -= diff;
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            if (me->IsWithinLOS(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()) && me->IsWithinDistInMap(player, 30.0f))
            {
                me->SetFacingToObject(player);
                Active = false;

                switch (emote)
                {
                    case TEXT_EMOTE_KISS:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_SHY);
                        break;
                    case TEXT_EMOTE_WAVE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                        break;
                    case TEXT_EMOTE_BOW:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                        break;
                    case TEXT_EMOTE_JOKE:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        break;
                    case TEXT_EMOTE_DANCE:
                        if (!player->HasAura(SPELL_SEDUCTION))
                            DoCast(player, SPELL_SEDUCTION, true);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dancing_flamesAI(creature);
    }
};

/*######
## npc_torch_tossing_target_bunny_controller
######*/

enum TorchTossingTarget
{
    NPC_TORCH_TOSSING_TARGET_BUNNY      = 25535,
    SPELL_TARGET_INDICATOR              = 45723
};

class npc_torch_tossing_target_bunny_controller : public CreatureScript
{
public:
    npc_torch_tossing_target_bunny_controller() : CreatureScript("npc_torch_tossing_target_bunny_controller") { }

    struct npc_torch_tossing_target_bunny_controllerAI : public ScriptedAI
    {
        npc_torch_tossing_target_bunny_controllerAI(Creature* creature) : ScriptedAI(creature)
        {
            _targetTimer = 3000;
        }

        ObjectGuid DoSearchForTargets(ObjectGuid lastTargetGUID)
        {
            std::list<Creature*> targets;
            me->GetCreatureListWithEntryInGrid(targets, NPC_TORCH_TOSSING_TARGET_BUNNY, 60.0f);
            targets.remove_if([lastTargetGUID](Creature* creature) { return creature->GetGUID() == lastTargetGUID; });

            if (!targets.empty())
            {
                _lastTargetGUID = Trinity::Containers::SelectRandomContainerElement(targets)->GetGUID();

                return _lastTargetGUID;
            }
            return ObjectGuid::Empty;
        }

        void UpdateAI(uint32 diff) override
        {
            if (_targetTimer < diff)
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, DoSearchForTargets(_lastTargetGUID)))
                    target->CastSpell(target, SPELL_TARGET_INDICATOR, true);

                _targetTimer = 3000;
            }
            else
                _targetTimer -= diff;
        }

    private:
        uint32 _targetTimer;
        ObjectGuid _lastTargetGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_torch_tossing_target_bunny_controllerAI(creature);
    }
};

/*######
## npc_midsummer_bunny_pole
######*/

enum RibbonPoleData
{
    GO_RIBBON_POLE              = 181605,
    SPELL_RIBBON_DANCE_COSMETIC = 29726,
    SPELL_RED_FIRE_RING         = 46836,
    SPELL_BLUE_FIRE_RING        = 46842,
    EVENT_CAST_RED_FIRE_RING    = 1,
    EVENT_CAST_BLUE_FIRE_RING   = 2
};

class npc_midsummer_bunny_pole : public CreatureScript
{
public:
    npc_midsummer_bunny_pole() : CreatureScript("npc_midsummer_bunny_pole") { }

    struct npc_midsummer_bunny_poleAI : public ScriptedAI
    {
        npc_midsummer_bunny_poleAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            events.Reset();
            running = false;
        }

        void Reset() override
        {
            Initialize();
        }

        void DoAction(int32 /*action*/) override
        {
            // Don't start event if it's already running.
            if (running)
                return;

            running = true;
            events.ScheduleEvent(EVENT_CAST_RED_FIRE_RING, 1);
        }

        bool checkNearbyPlayers()
        {
            // Returns true if no nearby player has aura "Test Ribbon Pole Channel".
            std::list<Player*> players;
            Trinity::UnitAuraCheck check(true, SPELL_RIBBON_DANCE_COSMETIC);
            Trinity::PlayerListSearcher<Trinity::UnitAuraCheck> searcher(me, players, check);
            Cell::VisitWorldObjects(me, searcher, 10.0f);

            return players.empty();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!running)
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_CAST_RED_FIRE_RING:
            {
                if (checkNearbyPlayers())
                {
                    Reset();
                    return;
                }

                if (GameObject* go = me->FindNearestGameObject(GO_RIBBON_POLE, 10.0f))
                    me->CastSpell(go, SPELL_RED_FIRE_RING, true);

                events.ScheduleEvent(EVENT_CAST_BLUE_FIRE_RING, Seconds(5));
            }
            break;
            case EVENT_CAST_BLUE_FIRE_RING:
            {
                if (checkNearbyPlayers())
                {
                    Reset();
                    return;
                }

                if (GameObject* go = me->FindNearestGameObject(GO_RIBBON_POLE, 10.0f))
                    me->CastSpell(go, SPELL_BLUE_FIRE_RING, true);

                events.ScheduleEvent(EVENT_CAST_RED_FIRE_RING, Seconds(5));
            }
            break;
            }
        }

    private:
        EventMap events;
        bool running;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_midsummer_bunny_poleAI(creature);
    }
};

/*######
## Triage quest
######*/

enum Doctor
{
    SAY_DOC             = 0,

    DOCTOR_ALLIANCE     = 12939,
    DOCTOR_HORDE        = 12920,
    ALLIANCE_COORDS     = 7,
    HORDE_COORDS        = 6
};

Position const AllianceCoords[]=
{
    {-3757.38f, -4533.05f, 14.16f, 3.62f},                      // Top-far-right bunk as seen from entrance
    {-3754.36f, -4539.13f, 14.16f, 5.13f},                      // Top-far-left bunk
    {-3749.54f, -4540.25f, 14.28f, 3.34f},                      // Far-right bunk
    {-3742.10f, -4536.85f, 14.28f, 3.64f},                      // Right bunk near entrance
    {-3755.89f, -4529.07f, 14.05f, 0.57f},                      // Far-left bunk
    {-3749.51f, -4527.08f, 14.07f, 5.26f},                      // Mid-left bunk
    {-3746.37f, -4525.35f, 14.16f, 5.22f},                      // Left bunk near entrance
};

//alliance run to where
#define A_RUNTOX -3742.96f
#define A_RUNTOY -4531.52f
#define A_RUNTOZ 11.91f

Position const HordeCoords[]=
{
    {-1013.75f, -3492.59f, 62.62f, 4.34f},                      // Left, Behind
    {-1017.72f, -3490.92f, 62.62f, 4.34f},                      // Right, Behind
    {-1015.77f, -3497.15f, 62.82f, 4.34f},                      // Left, Mid
    {-1019.51f, -3495.49f, 62.82f, 4.34f},                      // Right, Mid
    {-1017.25f, -3500.85f, 62.98f, 4.34f},                      // Left, front
    {-1020.95f, -3499.21f, 62.98f, 4.34f}                       // Right, Front
};

//horde run to where
#define H_RUNTOX -1016.44f
#define H_RUNTOY -3508.48f
#define H_RUNTOZ 62.96f

uint32 const AllianceSoldierId[3] =
{
    12938,                                                  // 12938 Injured Alliance Soldier
    12936,                                                  // 12936 Badly injured Alliance Soldier
    12937                                                   // 12937 Critically injured Alliance Soldier
};

uint32 const HordeSoldierId[3] =
{
    12923,                                                  //12923 Injured Soldier
    12924,                                                  //12924 Badly injured Soldier
    12925                                                   //12925 Critically injured Soldier
};

/*######
## npc_doctor (handles both Gustaf Vanhowzen and Gregory Victor)
######*/
class npc_doctor : public CreatureScript
{
public:
    npc_doctor() : CreatureScript("npc_doctor") { }

    struct npc_doctorAI : public ScriptedAI
    {
        npc_doctorAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            PlayerGUID.Clear();

            SummonPatientTimer = 10000;
            SummonPatientCount = 0;
            PatientDiedCount = 0;
            PatientSavedCount = 0;

            Patients.clear();
            Coordinates.clear();

            Event = false;
        }

        ObjectGuid PlayerGUID;

        uint32 SummonPatientTimer;
        uint32 SummonPatientCount;
        uint32 PatientDiedCount;
        uint32 PatientSavedCount;

        bool Event;

        GuidList Patients;
        std::vector<Position const*> Coordinates;

        void Reset() override
        {
            Initialize();
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        }

        void BeginEvent(Player* player)
        {
            PlayerGUID = player->GetGUID();

            SummonPatientTimer = 10000;
            SummonPatientCount = 0;
            PatientDiedCount = 0;
            PatientSavedCount = 0;

            switch (me->GetEntry())
            {
                case DOCTOR_ALLIANCE:
                    for (uint8 i = 0; i < ALLIANCE_COORDS; ++i)
                        Coordinates.push_back(&AllianceCoords[i]);
                    break;
                case DOCTOR_HORDE:
                    for (uint8 i = 0; i < HORDE_COORDS; ++i)
                        Coordinates.push_back(&HordeCoords[i]);
                    break;
            }

            Event = true;
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        }

        void PatientDied(Position const* point)
        {
            Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID);
            if (player && ((player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)))
            {
                ++PatientDiedCount;

                if (PatientDiedCount > 5 && Event)
                {
                    if (player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE)
                        player->FailQuest(6624);
                    else if (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                        player->FailQuest(6622);

                    Reset();
                    return;
                }

                Coordinates.push_back(point);
            }
            else
                // If no player or player abandon quest in progress
                Reset();
        }

        void PatientSaved(Creature* /*soldier*/, Player* player, Position const* point)
        {
            if (player && PlayerGUID == player->GetGUID())
            {
                if ((player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE) || (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE))
                {
                    ++PatientSavedCount;

                    if (PatientSavedCount == 15)
                    {
                        if (!Patients.empty())
                        {
                            for (GuidList::const_iterator itr = Patients.begin(); itr != Patients.end(); ++itr)
                            {
                                if (Creature* patient = ObjectAccessor::GetCreature(*me, *itr))
                                    patient->setDeathState(JUST_DIED);
                            }
                        }

                        if (player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE)
                            player->AreaExploredOrEventHappens(6624);
                        else if (player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                            player->AreaExploredOrEventHappens(6622);

                        Reset();
                        return;
                    }

                    Coordinates.push_back(point);
                }
            }
        }

        void UpdateAI(uint32 diff) override;

        void EnterCombat(Unit* /*who*/) override { }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if ((quest->GetQuestId() == 6624) || (quest->GetQuestId() == 6622))
                BeginEvent(player);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_doctorAI(creature);
    }
};

/*#####
## npc_injured_patient (handles all the patients, no matter Horde or Alliance)
#####*/

class npc_injured_patient : public CreatureScript
{
public:
    npc_injured_patient() : CreatureScript("npc_injured_patient") { }

    struct npc_injured_patientAI : public ScriptedAI
    {
        npc_injured_patientAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DoctorGUID.Clear();
            Coord = NULL;
        }

        ObjectGuid DoctorGUID;
        Position const* Coord;

        void Reset() override
        {
            Initialize();

            //no select
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            //no regen health
            me->AddUnitFlag(UNIT_FLAG_IN_COMBAT);

            //to make them lay with face down
            me->SetStandState(UNIT_STAND_STATE_DEAD);

            uint32 mobId = me->GetEntry();

            switch (mobId)
            {                                                   //lower max health
                case 12923:
                case 12938:                                     //Injured Soldier
                    me->SetHealth(me->CountPctFromMaxHealth(75));
                    break;
                case 12924:
                case 12936:                                     //Badly injured Soldier
                    me->SetHealth(me->CountPctFromMaxHealth(50));
                    break;
                case 12925:
                case 12937:                                     //Critically injured Soldier
                    me->SetHealth(me->CountPctFromMaxHealth(25));
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            Player* player = caster->ToPlayer();
            if (!player || !me->IsAlive() || spell->Id != 20804)
                return;

            if (player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                if (!DoctorGUID.IsEmpty())
                    if (Creature* doctor = ObjectAccessor::GetCreature(*me, DoctorGUID))
                        ENSURE_AI(npc_doctor::npc_doctorAI, doctor->AI())->PatientSaved(me, player, Coord);

            //make not selectable
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            //regen health
            me->RemoveUnitFlag(UNIT_FLAG_IN_COMBAT);

            //stand up
            me->SetStandState(UNIT_STAND_STATE_STAND);

            Talk(SAY_DOC);

            uint32 mobId = me->GetEntry();
            me->SetWalk(false);

            switch (mobId)
            {
                case 12923:
                case 12924:
                case 12925:
                    me->GetMotionMaster()->MovePoint(0, H_RUNTOX, H_RUNTOY, H_RUNTOZ);
                    break;
                case 12936:
                case 12937:
                case 12938:
                    me->GetMotionMaster()->MovePoint(0, A_RUNTOX, A_RUNTOY, A_RUNTOZ);
                    break;
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            //lower HP on every world tick makes it a useful counter, not officlone though
            if (me->IsAlive() && me->GetHealth() > 6)
                me->ModifyHealth(-5);

            if (me->IsAlive() && me->GetHealth() <= 6)
            {
                me->RemoveUnitFlag(UNIT_FLAG_IN_COMBAT);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->setDeathState(JUST_DIED);
                me->AddDynamicFlag(UNIT_DYNFLAG_DEAD);

                if (!DoctorGUID.IsEmpty())
                    if (Creature* doctor = ObjectAccessor::GetCreature((*me), DoctorGUID))
                        ENSURE_AI(npc_doctor::npc_doctorAI, doctor->AI())->PatientDied(Coord);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_injured_patientAI(creature);
    }
};

void npc_doctor::npc_doctorAI::UpdateAI(uint32 diff)
{
    if (Event && SummonPatientCount >= 20)
    {
        Reset();
        return;
    }

    if (Event)
    {
        if (SummonPatientTimer <= diff)
        {
            if (Coordinates.empty())
                return;

            uint32 patientEntry = 0;

            switch (me->GetEntry())
            {
                case DOCTOR_ALLIANCE:
                    patientEntry = AllianceSoldierId[rand32() % 3];
                    break;
                case DOCTOR_HORDE:
                    patientEntry = HordeSoldierId[rand32() % 3];
                    break;
                default:
                    TC_LOG_ERROR("scripts", "Invalid entry for Triage doctor. Please check your database");
                    return;
            }

            std::vector<Position const*>::iterator point = Coordinates.begin();
            std::advance(point, urand(0, Coordinates.size() - 1));

            if (Creature* Patient = me->SummonCreature(patientEntry, **point, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000))
            {
                //303, this flag appear to be required for client side item->spell to work (TARGET_SINGLE_FRIEND)
                Patient->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);

                Patients.push_back(Patient->GetGUID());
                ENSURE_AI(npc_injured_patient::npc_injured_patientAI, Patient->AI())->DoctorGUID = me->GetGUID();
                ENSURE_AI(npc_injured_patient::npc_injured_patientAI, Patient->AI())->Coord = *point;

                Coordinates.erase(point);
            }

            SummonPatientTimer = 10000;
            ++SummonPatientCount;
        }
        else
            SummonPatientTimer -= diff;
    }
}

/*######
## npc_garments_of_quests
######*/

/// @todo get text for each NPC

enum Garments
{
    SPELL_LESSER_HEAL_R2    = 2052,
    SPELL_FORTITUDE_R1      = 1243,

    QUEST_MOON              = 5621,
    QUEST_LIGHT_1           = 5624,
    QUEST_LIGHT_2           = 5625,
    QUEST_SPIRIT            = 5648,
    QUEST_DARKNESS          = 5650,

    ENTRY_SHAYA             = 12429,
    ENTRY_ROBERTS           = 12423,
    ENTRY_DOLF              = 12427,
    ENTRY_KORJA             = 12430,
    ENTRY_DG_KEL            = 12428,

    // used by 12429, 12423, 12427, 12430, 12428, but signed for 12429
    SAY_THANKS              = 0,
    SAY_GOODBYE             = 1,
    SAY_HEALED              = 2,
};

class npc_garments_of_quests : public CreatureScript
{
public:
    npc_garments_of_quests() : CreatureScript("npc_garments_of_quests") { }

    struct npc_garments_of_questsAI : public npc_escortAI
    {
        npc_garments_of_questsAI(Creature* creature) : npc_escortAI(creature)
        {
            switch (me->GetEntry())
            {
                case ENTRY_SHAYA:
                    quest = QUEST_MOON;
                    break;
                case ENTRY_ROBERTS:
                    quest = QUEST_LIGHT_1;
                    break;
                case ENTRY_DOLF:
                    quest = QUEST_LIGHT_2;
                    break;
                case ENTRY_KORJA:
                    quest = QUEST_SPIRIT;
                    break;
                case ENTRY_DG_KEL:
                    quest = QUEST_DARKNESS;
                    break;
                default:
                    quest = 0;
                    break;
            }

            Reset();
        }

        ObjectGuid CasterGUID;

        bool IsHealed;
        bool CanRun;

        uint32 RunAwayTimer;
        uint32 quest;

        void Reset() override
        {
            CasterGUID.Clear();

            IsHealed = false;
            CanRun = false;

            RunAwayTimer = 5000;

            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            // expect database to have RegenHealth=0
            me->SetHealth(me->CountPctFromMaxHealth(70));
        }

        void EnterCombat(Unit* /*who*/) override { }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_LESSER_HEAL_R2 || spell->Id == SPELL_FORTITUDE_R1)
            {
                //not while in combat
                if (me->IsInCombat())
                    return;

                //nothing to be done now
                if (IsHealed && CanRun)
                    return;

                if (Player* player = caster->ToPlayer())
                {
                    if (quest && player->GetQuestStatus(quest) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (IsHealed && !CanRun && spell->Id == SPELL_FORTITUDE_R1)
                        {
                            Talk(SAY_THANKS, caster);
                            CanRun = true;
                        }
                        else if (!IsHealed && spell->Id == SPELL_LESSER_HEAL_R2)
                        {
                            CasterGUID = caster->GetGUID();
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            Talk(SAY_HEALED, caster);
                            IsHealed = true;
                        }
                    }

                    // give quest credit, not expect any special quest objectives
                    if (CanRun)
                        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
                }
            }
        }

        void WaypointReached(uint32 /*waypointId*/) override
        {

        }

        void UpdateAI(uint32 diff) override
        {
            if (CanRun && !me->IsInCombat())
            {
                if (RunAwayTimer <= diff)
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, CasterGUID))
                    {
                        switch (me->GetEntry())
                        {
                            case ENTRY_SHAYA:
                            case ENTRY_ROBERTS:
                            case ENTRY_DOLF:
                            case ENTRY_KORJA:
                            case ENTRY_DG_KEL:
                                Talk(SAY_GOODBYE, unit);
                                break;
                        }

                        Start(false, true);
                    }
                    else
                        EnterEvadeMode();                       //something went wrong

                    RunAwayTimer = 30000;
                }
                else
                    RunAwayTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_garments_of_questsAI(creature);
    }
};

/*######
## npc_guardian
######*/

enum GuardianSpells
{
    SPELL_DEATHTOUCH            = 5
};

class npc_guardian : public CreatureScript
{
public:
    npc_guardian() : CreatureScript("npc_guardian") { }

    struct npc_guardianAI : public ScriptedAI
    {
        npc_guardianAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            if (me->isAttackReady())
            {
                DoCastVictim(SPELL_DEATHTOUCH, true);
                me->resetAttackTimer();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_guardianAI(creature);
    }
};

/*######
## npc_sayge
######*/

enum Sayge
{
    GOSSIP_MENU_OPTION_ID_ANSWER_1   = 0,
    GOSSIP_MENU_OPTION_ID_ANSWER_2   = 1,
    GOSSIP_MENU_OPTION_ID_ANSWER_3   = 2,
    GOSSIP_MENU_OPTION_ID_ANSWER_4   = 3,
    GOSSIP_I_AM_READY_TO_DISCOVER    = 6186,
    GOSSIP_MENU_OPTION_SAYGE1        = 6185,
    GOSSIP_MENU_OPTION_SAYGE2        = 6185,
    GOSSIP_MENU_OPTION_SAYGE3        = 6185,
    GOSSIP_MENU_OPTION_SAYGE4        = 6185,
    GOSSIP_MENU_OPTION_SAYGE5        = 6187,
    GOSSIP_MENU_OPTION_SAYGE6        = 6187,
    GOSSIP_MENU_OPTION_SAYGE7        = 6187,
    GOSSIP_MENU_OPTION_SAYGE8        = 6208,
    GOSSIP_MENU_OPTION_SAYGE9        = 6208,
    GOSSIP_MENU_OPTION_SAYGE10       = 6208,
    GOSSIP_MENU_OPTION_SAYGE11       = 6209,
    GOSSIP_MENU_OPTION_SAYGE12       = 6209,
    GOSSIP_MENU_OPTION_SAYGE13       = 6209,
    GOSSIP_MENU_OPTION_SAYGE14       = 6210,
    GOSSIP_MENU_OPTION_SAYGE15       = 6210,
    GOSSIP_MENU_OPTION_SAYGE16       = 6210,
    GOSSIP_MENU_OPTION_SAYGE17       = 6211,
    GOSSIP_MENU_I_HAVE_LONG_KNOWN    = 7339,
    GOSSIP_MENU_YOU_HAVE_BEEN_TASKED = 7340,
    GOSSIP_MENU_SWORN_EXECUTIONER    = 7341,
    GOSSIP_MENU_DIPLOMATIC_MISSION   = 7361,
    GOSSIP_MENU_YOUR_BROTHER_SEEKS   = 7362,
    GOSSIP_MENU_A_TERRIBLE_BEAST     = 7363,
    GOSSIP_MENU_YOUR_FORTUNE_IS_CAST = 7364,
    GOSSIP_MENU_HERE_IS_YOUR_FORTUNE = 7365,
    GOSSIP_MENU_CANT_GIVE_YOU_YOUR   = 7393,

    SPELL_STRENGTH                   = 23735, // +10% Strength
    SPELL_AGILITY                    = 23736, // +10% Agility
    SPELL_STAMINA                    = 23737, // +10% Stamina
    SPELL_SPIRIT                     = 23738, // +10% Spirit
    SPELL_INTELLECT                  = 23766, // +10% Intellect
    SPELL_ARMOR                      = 23767, // +10% Armor
    SPELL_DAMAGE                     = 23768, // +10% Damage
    SPELL_RESISTANCE                 = 23769, // +25 Magic Resistance (All)
    SPELL_FORTUNE                    = 23765  // Darkmoon Faire Fortune
};

class npc_sayge : public CreatureScript
{
public:
    npc_sayge() : CreatureScript("npc_sayge") { }

    struct npc_saygeAI : public ScriptedAI
    {
        npc_saygeAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (player->GetSpellHistory()->HasCooldown(SPELL_STRENGTH) ||
                player->GetSpellHistory()->HasCooldown(SPELL_AGILITY) ||
                player->GetSpellHistory()->HasCooldown(SPELL_STAMINA) ||
                player->GetSpellHistory()->HasCooldown(SPELL_SPIRIT) ||
                player->GetSpellHistory()->HasCooldown(SPELL_INTELLECT) ||
                player->GetSpellHistory()->HasCooldown(SPELL_ARMOR) ||
                player->GetSpellHistory()->HasCooldown(SPELL_DAMAGE) ||
                player->GetSpellHistory()->HasCooldown(SPELL_RESISTANCE))
                SendGossipMenuFor(player, GOSSIP_MENU_CANT_GIVE_YOU_YOUR, me->GetGUID());
            else
            {
                AddGossipItemFor(player, GOSSIP_I_AM_READY_TO_DISCOVER, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, GOSSIP_MENU_I_HAVE_LONG_KNOWN, me->GetGUID());
            }

            return true;
        }

        void SendAction(Player* player, uint32 action)
        {
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE1, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE2, GOSSIP_MENU_OPTION_ID_ANSWER_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE3, GOSSIP_MENU_OPTION_ID_ANSWER_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE4, GOSSIP_MENU_OPTION_ID_ANSWER_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                    SendGossipMenuFor(player, GOSSIP_MENU_YOU_HAVE_BEEN_TASKED, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE5, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN + 1, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE6, GOSSIP_MENU_OPTION_ID_ANSWER_2, GOSSIP_SENDER_MAIN + 2, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE7, GOSSIP_MENU_OPTION_ID_ANSWER_3, GOSSIP_SENDER_MAIN + 3, GOSSIP_ACTION_INFO_DEF);
                    SendGossipMenuFor(player, GOSSIP_MENU_SWORN_EXECUTIONER, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE8, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN + 4, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE9, GOSSIP_MENU_OPTION_ID_ANSWER_2, GOSSIP_SENDER_MAIN + 5, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE10, GOSSIP_MENU_OPTION_ID_ANSWER_3, GOSSIP_SENDER_MAIN + 2, GOSSIP_ACTION_INFO_DEF);
                    SendGossipMenuFor(player, GOSSIP_MENU_DIPLOMATIC_MISSION, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE11, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN + 6, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE12, GOSSIP_MENU_OPTION_ID_ANSWER_2, GOSSIP_SENDER_MAIN + 7, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE13, GOSSIP_MENU_OPTION_ID_ANSWER_3, GOSSIP_SENDER_MAIN + 8, GOSSIP_ACTION_INFO_DEF);
                    SendGossipMenuFor(player, GOSSIP_MENU_YOUR_BROTHER_SEEKS, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 5:
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE14, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN + 5, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE15, GOSSIP_MENU_OPTION_ID_ANSWER_2, GOSSIP_SENDER_MAIN + 4, GOSSIP_ACTION_INFO_DEF);
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE16, GOSSIP_MENU_OPTION_ID_ANSWER_3, GOSSIP_SENDER_MAIN + 3, GOSSIP_ACTION_INFO_DEF);
                    SendGossipMenuFor(player, GOSSIP_MENU_A_TERRIBLE_BEAST, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF:
                    AddGossipItemFor(player, GOSSIP_MENU_OPTION_SAYGE17, GOSSIP_MENU_OPTION_ID_ANSWER_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                    SendGossipMenuFor(player, GOSSIP_MENU_YOUR_FORTUNE_IS_CAST, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 6:
                    DoCast(player, SPELL_FORTUNE, false);
                    SendGossipMenuFor(player, GOSSIP_MENU_HERE_IS_YOUR_FORTUNE, me->GetGUID());
                    break;
            }
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            uint32 spellId = 0;
            switch (sender)
            {
                case GOSSIP_SENDER_MAIN:
                    SendAction(player, action);
                    break;
                case GOSSIP_SENDER_MAIN + 1:
                    spellId = SPELL_DAMAGE;
                    break;
                case GOSSIP_SENDER_MAIN + 2:
                    spellId = SPELL_RESISTANCE;
                    break;
                case GOSSIP_SENDER_MAIN + 3:
                    spellId = SPELL_ARMOR;
                    break;
                case GOSSIP_SENDER_MAIN + 4:
                    spellId = SPELL_SPIRIT;
                    break;
                case GOSSIP_SENDER_MAIN + 5:
                    spellId = SPELL_INTELLECT;
                    break;
                case GOSSIP_SENDER_MAIN + 6:
                    spellId = SPELL_STAMINA;
                    break;
                case GOSSIP_SENDER_MAIN + 7:
                    spellId = SPELL_STRENGTH;
                    break;
                case GOSSIP_SENDER_MAIN + 8:
                    spellId = SPELL_AGILITY;
                    break;
            }

            if (spellId)
            {
                DoCast(player, spellId, false);
                player->GetSpellHistory()->AddCooldown(spellId, 0, std::chrono::hours(2));
                SendAction(player, action);
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_saygeAI(creature);
    }
};

class npc_steam_tonk : public CreatureScript
{
public:
    npc_steam_tonk() : CreatureScript("npc_steam_tonk") { }

    struct npc_steam_tonkAI : public ScriptedAI
    {
        npc_steam_tonkAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }
        void EnterCombat(Unit* /*who*/) override { }

        void OnPossess(bool apply)
        {
            if (apply)
            {
                // Initialize the action bar without the melee attack command
                me->InitCharmInfo();
                me->GetCharmInfo()->InitEmptyActionBar(false);

                me->SetReactState(REACT_PASSIVE);
            }
            else
                me->SetReactState(REACT_AGGRESSIVE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_steam_tonkAI(creature);
    }
};

enum TonkMine
{
    SPELL_TONK_MINE_DETONATE    = 25099
};

class npc_tonk_mine : public CreatureScript
{
public:
    npc_tonk_mine() : CreatureScript("npc_tonk_mine") { }

    struct npc_tonk_mineAI : public ScriptedAI
    {
        npc_tonk_mineAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            me->SetReactState(REACT_PASSIVE);
        }

        void Initialize()
        {
            ExplosionTimer = 3000;
        }

        uint32 ExplosionTimer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }
        void AttackStart(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 diff) override
        {
            if (ExplosionTimer <= diff)
            {
                DoCast(me, SPELL_TONK_MINE_DETONATE, true);
                me->setDeathState(DEAD); // unsummon it
            }
            else
                ExplosionTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tonk_mineAI(creature);
    }
};

enum TournamentPennantSpells
{
    SPELL_PENNANT_STORMWIND_ASPIRANT        = 62595,
    SPELL_PENNANT_STORMWIND_VALIANT         = 62596,
    SPELL_PENNANT_STORMWIND_CHAMPION        = 62594,
    SPELL_PENNANT_GNOMEREGAN_ASPIRANT       = 63394,
    SPELL_PENNANT_GNOMEREGAN_VALIANT        = 63395,
    SPELL_PENNANT_GNOMEREGAN_CHAMPION       = 63396,
    SPELL_PENNANT_SEN_JIN_ASPIRANT          = 63397,
    SPELL_PENNANT_SEN_JIN_VALIANT           = 63398,
    SPELL_PENNANT_SEN_JIN_CHAMPION          = 63399,
    SPELL_PENNANT_SILVERMOON_ASPIRANT       = 63401,
    SPELL_PENNANT_SILVERMOON_VALIANT        = 63402,
    SPELL_PENNANT_SILVERMOON_CHAMPION       = 63403,
    SPELL_PENNANT_DARNASSUS_ASPIRANT        = 63404,
    SPELL_PENNANT_DARNASSUS_VALIANT         = 63405,
    SPELL_PENNANT_DARNASSUS_CHAMPION        = 63406,
    SPELL_PENNANT_EXODAR_ASPIRANT           = 63421,
    SPELL_PENNANT_EXODAR_VALIANT            = 63422,
    SPELL_PENNANT_EXODAR_CHAMPION           = 63423,
    SPELL_PENNANT_IRONFORGE_ASPIRANT        = 63425,
    SPELL_PENNANT_IRONFORGE_VALIANT         = 63426,
    SPELL_PENNANT_IRONFORGE_CHAMPION        = 63427,
    SPELL_PENNANT_UNDERCITY_ASPIRANT        = 63428,
    SPELL_PENNANT_UNDERCITY_VALIANT         = 63429,
    SPELL_PENNANT_UNDERCITY_CHAMPION        = 63430,
    SPELL_PENNANT_ORGRIMMAR_ASPIRANT        = 63431,
    SPELL_PENNANT_ORGRIMMAR_VALIANT         = 63432,
    SPELL_PENNANT_ORGRIMMAR_CHAMPION        = 63433,
    SPELL_PENNANT_THUNDER_BLUFF_ASPIRANT    = 63434,
    SPELL_PENNANT_THUNDER_BLUFF_VALIANT     = 63435,
    SPELL_PENNANT_THUNDER_BLUFF_CHAMPION    = 63436,
    SPELL_PENNANT_ARGENT_CRUSADE_ASPIRANT   = 63606,
    SPELL_PENNANT_ARGENT_CRUSADE_VALIANT    = 63500,
    SPELL_PENNANT_ARGENT_CRUSADE_CHAMPION   = 63501,
    SPELL_PENNANT_EBON_BLADE_ASPIRANT       = 63607,
    SPELL_PENNANT_EBON_BLADE_VALIANT        = 63608,
    SPELL_PENNANT_EBON_BLADE_CHAMPION       = 63609
};

 enum TournamentMounts
{
    NPC_STORMWIND_STEED                     = 33217,
    NPC_IRONFORGE_RAM                       = 33316,
    NPC_GNOMEREGAN_MECHANOSTRIDER           = 33317,
    NPC_EXODAR_ELEKK                        = 33318,
    NPC_DARNASSIAN_NIGHTSABER               = 33319,
    NPC_ORGRIMMAR_WOLF                      = 33320,
    NPC_DARK_SPEAR_RAPTOR                   = 33321,
    NPC_THUNDER_BLUFF_KODO                  = 33322,
    NPC_SILVERMOON_HAWKSTRIDER              = 33323,
    NPC_FORSAKEN_WARHORSE                   = 33324,
    NPC_ARGENT_WARHORSE                     = 33782,
    NPC_ARGENT_STEED_ASPIRANT               = 33845,
    NPC_ARGENT_HAWKSTRIDER_ASPIRANT         = 33844
};

 enum TournamentQuestsAchievements
{
    ACHIEVEMENT_CHAMPION_STORMWIND          = 2781,
    ACHIEVEMENT_CHAMPION_DARNASSUS          = 2777,
    ACHIEVEMENT_CHAMPION_IRONFORGE          = 2780,
    ACHIEVEMENT_CHAMPION_GNOMEREGAN         = 2779,
    ACHIEVEMENT_CHAMPION_THE_EXODAR         = 2778,
    ACHIEVEMENT_CHAMPION_ORGRIMMAR          = 2783,
    ACHIEVEMENT_CHAMPION_SEN_JIN            = 2784,
    ACHIEVEMENT_CHAMPION_THUNDER_BLUFF      = 2786,
    ACHIEVEMENT_CHAMPION_UNDERCITY          = 2787,
    ACHIEVEMENT_CHAMPION_SILVERMOON         = 2785,
    ACHIEVEMENT_ARGENT_VALOR                = 2758,
    ACHIEVEMENT_CHAMPION_ALLIANCE           = 2782,
    ACHIEVEMENT_CHAMPION_HORDE              = 2788,

     QUEST_VALIANT_OF_STORMWIND              = 13593,
    QUEST_A_VALIANT_OF_STORMWIND            = 13684,
    QUEST_VALIANT_OF_DARNASSUS              = 13706,
    QUEST_A_VALIANT_OF_DARNASSUS            = 13689,
    QUEST_VALIANT_OF_IRONFORGE              = 13703,
    QUEST_A_VALIANT_OF_IRONFORGE            = 13685,
    QUEST_VALIANT_OF_GNOMEREGAN             = 13704,
    QUEST_A_VALIANT_OF_GNOMEREGAN           = 13688,
    QUEST_VALIANT_OF_THE_EXODAR             = 13705,
    QUEST_A_VALIANT_OF_THE_EXODAR           = 13690,
    QUEST_VALIANT_OF_ORGRIMMAR              = 13707,
    QUEST_A_VALIANT_OF_ORGRIMMAR            = 13691,
    QUEST_VALIANT_OF_SEN_JIN                = 13708,
    QUEST_A_VALIANT_OF_SEN_JIN              = 13693,
    QUEST_VALIANT_OF_THUNDER_BLUFF          = 13709,
    QUEST_A_VALIANT_OF_THUNDER_BLUFF        = 13694,
    QUEST_VALIANT_OF_UNDERCITY              = 13710,
    QUEST_A_VALIANT_OF_UNDERCITY            = 13695,
    QUEST_VALIANT_OF_SILVERMOON             = 13711,
    QUEST_A_VALIANT_OF_SILVERMOON           = 13696
};

 class npc_tournament_mount : public CreatureScript
{
    public:
        npc_tournament_mount() : CreatureScript("npc_tournament_mount") { }

         struct npc_tournament_mountAI : public VehicleAI
        {
            npc_tournament_mountAI(Creature* creature) : VehicleAI(creature)
            {
                _pennantSpellId = 0;
            }

             void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                Player* player = passenger->ToPlayer();
                if (!player)
                    return;

                 if (apply)
                {
                    _pennantSpellId = GetPennantSpellId(player);
                    player->CastSpell((Unit*)nullptr, _pennantSpellId, true);
                }
                else
                    player->RemoveAurasDueToSpell(_pennantSpellId);
            }

         private:
            uint32 _pennantSpellId;

             uint32 GetPennantSpellId(Player* player) const
            {
                switch (me->GetEntry())
                {
                    case NPC_ARGENT_STEED_ASPIRANT:
                    case NPC_STORMWIND_STEED:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_STORMWIND))
                            return SPELL_PENNANT_STORMWIND_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_STORMWIND) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_STORMWIND))
                            return SPELL_PENNANT_STORMWIND_VALIANT;
                        else
                            return SPELL_PENNANT_STORMWIND_ASPIRANT;
                    }
                    case NPC_GNOMEREGAN_MECHANOSTRIDER:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_GNOMEREGAN))
                            return SPELL_PENNANT_GNOMEREGAN_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_GNOMEREGAN) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_GNOMEREGAN))
                            return SPELL_PENNANT_GNOMEREGAN_VALIANT;
                        else
                            return SPELL_PENNANT_GNOMEREGAN_ASPIRANT;
                    }
                    case NPC_DARK_SPEAR_RAPTOR:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_SEN_JIN))
                            return SPELL_PENNANT_SEN_JIN_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_SEN_JIN) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_SEN_JIN))
                            return SPELL_PENNANT_SEN_JIN_VALIANT;
                        else
                            return SPELL_PENNANT_SEN_JIN_ASPIRANT;
                    }
                    case NPC_ARGENT_HAWKSTRIDER_ASPIRANT:
                    case NPC_SILVERMOON_HAWKSTRIDER:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_SILVERMOON))
                            return SPELL_PENNANT_SILVERMOON_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_SILVERMOON) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_SILVERMOON))
                            return SPELL_PENNANT_SILVERMOON_VALIANT;
                        else
                            return SPELL_PENNANT_SILVERMOON_ASPIRANT;
                    }
                    case NPC_DARNASSIAN_NIGHTSABER:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_DARNASSUS))
                            return SPELL_PENNANT_DARNASSUS_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_DARNASSUS) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_DARNASSUS))
                            return SPELL_PENNANT_DARNASSUS_VALIANT;
                        else
                            return SPELL_PENNANT_DARNASSUS_ASPIRANT;
                    }
                    case NPC_EXODAR_ELEKK:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_THE_EXODAR))
                            return SPELL_PENNANT_EXODAR_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_THE_EXODAR) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_THE_EXODAR))
                            return SPELL_PENNANT_EXODAR_VALIANT;
                        else
                            return SPELL_PENNANT_EXODAR_ASPIRANT;
                    }
                    case NPC_IRONFORGE_RAM:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_IRONFORGE))
                            return SPELL_PENNANT_IRONFORGE_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_IRONFORGE) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_IRONFORGE))
                            return SPELL_PENNANT_IRONFORGE_VALIANT;
                        else
                            return SPELL_PENNANT_IRONFORGE_ASPIRANT;
                    }
                    case NPC_FORSAKEN_WARHORSE:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_UNDERCITY))
                            return SPELL_PENNANT_UNDERCITY_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_UNDERCITY) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_UNDERCITY))
                            return SPELL_PENNANT_UNDERCITY_VALIANT;
                        else
                            return SPELL_PENNANT_UNDERCITY_ASPIRANT;
                    }
                    case NPC_ORGRIMMAR_WOLF:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_ORGRIMMAR))
                            return SPELL_PENNANT_ORGRIMMAR_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_ORGRIMMAR) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_ORGRIMMAR))
                            return SPELL_PENNANT_ORGRIMMAR_VALIANT;
                        else
                            return SPELL_PENNANT_ORGRIMMAR_ASPIRANT;
                    }
                    case NPC_THUNDER_BLUFF_KODO:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_THUNDER_BLUFF))
                            return SPELL_PENNANT_THUNDER_BLUFF_CHAMPION;
                        else if (player->GetQuestRewardStatus(QUEST_VALIANT_OF_THUNDER_BLUFF) || player->GetQuestRewardStatus(QUEST_A_VALIANT_OF_THUNDER_BLUFF))
                            return SPELL_PENNANT_THUNDER_BLUFF_VALIANT;
                        else
                            return SPELL_PENNANT_THUNDER_BLUFF_ASPIRANT;
                    }
                    case NPC_ARGENT_WARHORSE:
                    {
                        if (player->HasAchieved(ACHIEVEMENT_CHAMPION_ALLIANCE) || player->HasAchieved(ACHIEVEMENT_CHAMPION_HORDE))
                            return player->getClass() == CLASS_DEATH_KNIGHT ? SPELL_PENNANT_EBON_BLADE_CHAMPION : SPELL_PENNANT_ARGENT_CRUSADE_CHAMPION;
                        else if (player->HasAchieved(ACHIEVEMENT_ARGENT_VALOR))
                            return player->getClass() == CLASS_DEATH_KNIGHT ? SPELL_PENNANT_EBON_BLADE_VALIANT : SPELL_PENNANT_ARGENT_CRUSADE_VALIANT;
                        else
                            return player->getClass() == CLASS_DEATH_KNIGHT ? SPELL_PENNANT_EBON_BLADE_ASPIRANT : SPELL_PENNANT_ARGENT_CRUSADE_ASPIRANT;
                    }
                    default:
                        return 0;
                }
            }
        };

         CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_tournament_mountAI(creature);
        }
};

/*####
## npc_brewfest_reveler
####*/

enum BrewfestReveler
{
    SPELL_BREWFEST_TOAST = 41586
};

class npc_brewfest_reveler : public CreatureScript
{
    public:
        npc_brewfest_reveler() : CreatureScript("npc_brewfest_reveler") { }

        struct npc_brewfest_revelerAI : public ScriptedAI
        {
            npc_brewfest_revelerAI(Creature* creature) : ScriptedAI(creature) { }

            void ReceiveEmote(Player* player, uint32 emote) override
            {
                if (!IsHolidayActive(HOLIDAY_BREWFEST))
                    return;

                if (emote == TEXT_EMOTE_DANCE)
                    me->CastSpell(player, SPELL_BREWFEST_TOAST, false);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_brewfest_revelerAI(creature);
        }
};

enum TrainingDummy
{
    NPC_ADVANCED_TARGET_DUMMY                  = 2674,
    NPC_TARGET_DUMMY                           = 2673,

    EVENT_TD_CHECK_COMBAT                      = 1,
    EVENT_TD_DESPAWN                           = 2
};

class npc_training_dummy : public CreatureScript
{
public:
    npc_training_dummy() : CreatureScript("npc_training_dummy") { }

    struct npc_training_dummyAI : ScriptedAI
    {
        npc_training_dummyAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        EventMap _events;
        std::unordered_map<ObjectGuid, time_t> _damageTimes;

        void Reset() override
        {
            // TODO: solve this in a different way! setting them as stunned prevents dummies from parrying
            me->SetControlled(true, UNIT_STATE_STUNNED);//disable rotate

            _events.Reset();
            _damageTimes.clear();
            if (me->GetEntry() != NPC_ADVANCED_TARGET_DUMMY && me->GetEntry() != NPC_TARGET_DUMMY)
                _events.ScheduleEvent(EVENT_TD_CHECK_COMBAT, 1000);
            else
                _events.ScheduleEvent(EVENT_TD_DESPAWN, 15000);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (!_EnterEvadeMode(why))
                return;

            Reset();
        }

        void DamageTaken(Unit* doneBy, uint32& damage) override
        {
            me->AddThreat(doneBy, float(damage));    // just to create threat reference
            _damageTimes[doneBy->GetGUID()] = time(NULL);
            damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->IsInCombat())
                return;

            if (!me->HasUnitState(UNIT_STATE_STUNNED))
                me->SetControlled(true, UNIT_STATE_STUNNED);//disable rotate

            _events.Update(diff);

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TD_CHECK_COMBAT:
                    {
                        time_t now = time(NULL);
                        for (std::unordered_map<ObjectGuid, time_t>::iterator itr = _damageTimes.begin(); itr != _damageTimes.end();)
                        {
                            // If unit has not dealt damage to training dummy for 5 seconds, remove him from combat
                            if (itr->second < now - 5)
                            {
                                if (Unit* unit = ObjectAccessor::GetUnit(*me, itr->first))
                                    unit->getHostileRefManager().deleteReference(me);

                                itr = _damageTimes.erase(itr);
                            }
                            else
                                ++itr;
                        }
                        _events.ScheduleEvent(EVENT_TD_CHECK_COMBAT, 1000);
                        break;
                    }
                    case EVENT_TD_DESPAWN:
                        me->DespawnOrUnsummon(1);
                        break;
                    default:
                        break;
                }
            }
        }

        void MoveInLineOfSight(Unit* /*who*/) override { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_training_dummyAI(creature);
    }
};

/*######
# npc_wormhole
######*/

enum NPC_Wormhole
{
    MENU_ID_WORMHOLE      = 10668, // "This tear in the fabric of time and space looks ominous."
    NPC_TEXT_WORMHOLE     = 14785, // (not 907 "What brings you to this part of the world, $n?")
    GOSSIP_OPTION_1       = 0,     // "Borean Tundra"
    GOSSIP_OPTION_2       = 1,     // "Howling Fjord"
    GOSSIP_OPTION_3       = 2,     // "Sholazar Basin"
    GOSSIP_OPTION_4       = 3,     // "Icecrown"
    GOSSIP_OPTION_5       = 4,     // "Storm Peaks"
    GOSSIP_OPTION_6       = 5,     // "Underground..."

    SPELL_BOREAN_TUNDRA   = 67834, // 0
    SPELL_HOWLING_FJORD   = 67838, // 1
    SPELL_SHOLAZAR_BASIN  = 67835, // 2
    SPELL_ICECROWN        = 67836, // 3
    SPELL_STORM_PEAKS     = 67837, // 4
    SPELL_UNDERGROUND     = 68081  // 5
};

class npc_wormhole : public CreatureScript
{
    public:
        npc_wormhole() : CreatureScript("npc_wormhole") { }

        struct npc_wormholeAI : public PassiveAI
        {
            npc_wormholeAI(Creature* creature) : PassiveAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _showUnderground = urand(0, 100) == 0; // Guessed value, it is really rare though
            }

            void InitializeAI() override
            {
                Initialize();
            }

            bool GossipHello(Player* player) override
            {
                if (me->IsSummon())
                {
                    if (player == me->ToTempSummon()->GetSummoner())
                    {
                        AddGossipItemFor(player, MENU_ID_WORMHOLE, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        AddGossipItemFor(player, MENU_ID_WORMHOLE, GOSSIP_OPTION_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        AddGossipItemFor(player, MENU_ID_WORMHOLE, GOSSIP_OPTION_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        AddGossipItemFor(player, MENU_ID_WORMHOLE, GOSSIP_OPTION_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                        AddGossipItemFor(player, MENU_ID_WORMHOLE, GOSSIP_OPTION_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);

                        if (_showUnderground)
                            AddGossipItemFor(player, MENU_ID_WORMHOLE, GOSSIP_OPTION_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);

                        SendGossipMenuFor(player, NPC_TEXT_WORMHOLE, me->GetGUID());
                    }
                }

                return true;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);

                switch (action)
                {
                    case GOSSIP_ACTION_INFO_DEF + 1: // Borean Tundra
                        CloseGossipMenuFor(player);
                        DoCast(player, SPELL_BOREAN_TUNDRA, false);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 2: // Howling Fjord
                        CloseGossipMenuFor(player);
                        DoCast(player, SPELL_HOWLING_FJORD, false);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 3: // Sholazar Basin
                        CloseGossipMenuFor(player);
                        DoCast(player, SPELL_SHOLAZAR_BASIN, false);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 4: // Icecrown
                        CloseGossipMenuFor(player);
                        DoCast(player, SPELL_ICECROWN, false);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 5: // Storm peaks
                        CloseGossipMenuFor(player);
                        DoCast(player, SPELL_STORM_PEAKS, false);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 6: // Underground
                        CloseGossipMenuFor(player);
                        DoCast(player, SPELL_UNDERGROUND, false);
                        break;
                }

                return true;
            }

        private:
            bool _showUnderground;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wormholeAI(creature);
        }
};

/*######
## npc_experience
######*/

enum BehstenSlahtz
{
    MENU_ID_XP_ON_OFF  = 10638,
    NPC_TEXT_XP_ON_OFF = 14736,
    OPTION_ID_XP_OFF   = 0,     // "I no longer wish to gain experience."
    OPTION_ID_XP_ON    = 1      // "I wish to start gaining experience again."
};

class npc_experience : public CreatureScript
{
public:
    npc_experience() : CreatureScript("npc_experience") { }

    struct npc_experienceAI : public ScriptedAI
    {
        npc_experienceAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (player->HasPlayerFlag(PLAYER_FLAGS_NO_XP_GAIN)) // not gaining XP
            {
                AddGossipItemFor(player, MENU_ID_XP_ON_OFF, OPTION_ID_XP_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_XP_ON_OFF, me->GetGUID());
            }
            else // currently gaining XP
            {
                AddGossipItemFor(player, MENU_ID_XP_ON_OFF, OPTION_ID_XP_OFF, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, NPC_TEXT_XP_ON_OFF, me->GetGUID());
            }
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1: // XP ON selected
                    player->RemovePlayerFlag(PLAYER_FLAGS_NO_XP_GAIN); // turn on XP gain
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2: // XP OFF selected
                    player->AddPlayerFlag(PLAYER_FLAGS_NO_XP_GAIN); // turn off XP gain
                    break;
            }
            CloseGossipMenuFor(player);
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_experienceAI(creature);
    }
};

enum Fireworks
{
    NPC_OMEN                = 15467,
    NPC_MINION_OF_OMEN      = 15466,
    NPC_FIREWORK_BLUE       = 15879,
    NPC_FIREWORK_GREEN      = 15880,
    NPC_FIREWORK_PURPLE     = 15881,
    NPC_FIREWORK_RED        = 15882,
    NPC_FIREWORK_YELLOW     = 15883,
    NPC_FIREWORK_WHITE      = 15884,
    NPC_FIREWORK_BIG_BLUE   = 15885,
    NPC_FIREWORK_BIG_GREEN  = 15886,
    NPC_FIREWORK_BIG_PURPLE = 15887,
    NPC_FIREWORK_BIG_RED    = 15888,
    NPC_FIREWORK_BIG_YELLOW = 15889,
    NPC_FIREWORK_BIG_WHITE  = 15890,

    NPC_CLUSTER_BLUE        = 15872,
    NPC_CLUSTER_RED         = 15873,
    NPC_CLUSTER_GREEN       = 15874,
    NPC_CLUSTER_PURPLE      = 15875,
    NPC_CLUSTER_WHITE       = 15876,
    NPC_CLUSTER_YELLOW      = 15877,
    NPC_CLUSTER_BIG_BLUE    = 15911,
    NPC_CLUSTER_BIG_GREEN   = 15912,
    NPC_CLUSTER_BIG_PURPLE  = 15913,
    NPC_CLUSTER_BIG_RED     = 15914,
    NPC_CLUSTER_BIG_WHITE   = 15915,
    NPC_CLUSTER_BIG_YELLOW  = 15916,
    NPC_CLUSTER_ELUNE       = 15918,

    GO_FIREWORK_LAUNCHER_1  = 180771,
    GO_FIREWORK_LAUNCHER_2  = 180868,
    GO_FIREWORK_LAUNCHER_3  = 180850,
    GO_CLUSTER_LAUNCHER_1   = 180772,
    GO_CLUSTER_LAUNCHER_2   = 180859,
    GO_CLUSTER_LAUNCHER_3   = 180869,
    GO_CLUSTER_LAUNCHER_4   = 180874,

    SPELL_ROCKET_BLUE       = 26344,
    SPELL_ROCKET_GREEN      = 26345,
    SPELL_ROCKET_PURPLE     = 26346,
    SPELL_ROCKET_RED        = 26347,
    SPELL_ROCKET_WHITE      = 26348,
    SPELL_ROCKET_YELLOW     = 26349,
    SPELL_ROCKET_BIG_BLUE   = 26351,
    SPELL_ROCKET_BIG_GREEN  = 26352,
    SPELL_ROCKET_BIG_PURPLE = 26353,
    SPELL_ROCKET_BIG_RED    = 26354,
    SPELL_ROCKET_BIG_WHITE  = 26355,
    SPELL_ROCKET_BIG_YELLOW = 26356,
    SPELL_LUNAR_FORTUNE     = 26522,

    ANIM_GO_LAUNCH_FIREWORK = 3,
    ZONE_MOONGLADE          = 493,
};

Position omenSummonPos = {7558.993f, -2839.999f, 450.0214f, 4.46f};

class npc_firework : public CreatureScript
{
public:
    npc_firework() : CreatureScript("npc_firework") { }

    struct npc_fireworkAI : public ScriptedAI
    {
        npc_fireworkAI(Creature* creature) : ScriptedAI(creature) { }

        bool isCluster()
        {
            switch (me->GetEntry())
            {
                case NPC_FIREWORK_BLUE:
                case NPC_FIREWORK_GREEN:
                case NPC_FIREWORK_PURPLE:
                case NPC_FIREWORK_RED:
                case NPC_FIREWORK_YELLOW:
                case NPC_FIREWORK_WHITE:
                case NPC_FIREWORK_BIG_BLUE:
                case NPC_FIREWORK_BIG_GREEN:
                case NPC_FIREWORK_BIG_PURPLE:
                case NPC_FIREWORK_BIG_RED:
                case NPC_FIREWORK_BIG_YELLOW:
                case NPC_FIREWORK_BIG_WHITE:
                    return false;
                case NPC_CLUSTER_BLUE:
                case NPC_CLUSTER_GREEN:
                case NPC_CLUSTER_PURPLE:
                case NPC_CLUSTER_RED:
                case NPC_CLUSTER_YELLOW:
                case NPC_CLUSTER_WHITE:
                case NPC_CLUSTER_BIG_BLUE:
                case NPC_CLUSTER_BIG_GREEN:
                case NPC_CLUSTER_BIG_PURPLE:
                case NPC_CLUSTER_BIG_RED:
                case NPC_CLUSTER_BIG_YELLOW:
                case NPC_CLUSTER_BIG_WHITE:
                case NPC_CLUSTER_ELUNE:
                default:
                    return true;
            }
        }

        GameObject* FindNearestLauncher()
        {
            GameObject* launcher = NULL;

            if (isCluster())
            {
                GameObject* launcher1 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_1, 0.5f);
                GameObject* launcher2 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_2, 0.5f);
                GameObject* launcher3 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_3, 0.5f);
                GameObject* launcher4 = GetClosestGameObjectWithEntry(me, GO_CLUSTER_LAUNCHER_4, 0.5f);

                if (launcher1)
                    launcher = launcher1;
                else if (launcher2)
                    launcher = launcher2;
                else if (launcher3)
                    launcher = launcher3;
                else if (launcher4)
                    launcher = launcher4;
            }
            else
            {
                GameObject* launcher1 = GetClosestGameObjectWithEntry(me, GO_FIREWORK_LAUNCHER_1, 0.5f);
                GameObject* launcher2 = GetClosestGameObjectWithEntry(me, GO_FIREWORK_LAUNCHER_2, 0.5f);
                GameObject* launcher3 = GetClosestGameObjectWithEntry(me, GO_FIREWORK_LAUNCHER_3, 0.5f);

                if (launcher1)
                    launcher = launcher1;
                else if (launcher2)
                    launcher = launcher2;
                else if (launcher3)
                    launcher = launcher3;
            }

            return launcher;
        }

        uint32 GetFireworkSpell(uint32 entry)
        {
            switch (entry)
            {
                case NPC_FIREWORK_BLUE:
                    return SPELL_ROCKET_BLUE;
                case NPC_FIREWORK_GREEN:
                    return SPELL_ROCKET_GREEN;
                case NPC_FIREWORK_PURPLE:
                    return SPELL_ROCKET_PURPLE;
                case NPC_FIREWORK_RED:
                    return SPELL_ROCKET_RED;
                case NPC_FIREWORK_YELLOW:
                    return SPELL_ROCKET_YELLOW;
                case NPC_FIREWORK_WHITE:
                    return SPELL_ROCKET_WHITE;
                case NPC_FIREWORK_BIG_BLUE:
                    return SPELL_ROCKET_BIG_BLUE;
                case NPC_FIREWORK_BIG_GREEN:
                    return SPELL_ROCKET_BIG_GREEN;
                case NPC_FIREWORK_BIG_PURPLE:
                    return SPELL_ROCKET_BIG_PURPLE;
                case NPC_FIREWORK_BIG_RED:
                    return SPELL_ROCKET_BIG_RED;
                case NPC_FIREWORK_BIG_YELLOW:
                    return SPELL_ROCKET_BIG_YELLOW;
                case NPC_FIREWORK_BIG_WHITE:
                    return SPELL_ROCKET_BIG_WHITE;
                default:
                    return 0;
            }
        }

        uint32 GetFireworkGameObjectId()
        {
            uint32 spellId = 0;

            switch (me->GetEntry())
            {
                case NPC_CLUSTER_BLUE:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BLUE);
                    break;
                case NPC_CLUSTER_GREEN:
                    spellId = GetFireworkSpell(NPC_FIREWORK_GREEN);
                    break;
                case NPC_CLUSTER_PURPLE:
                    spellId = GetFireworkSpell(NPC_FIREWORK_PURPLE);
                    break;
                case NPC_CLUSTER_RED:
                    spellId = GetFireworkSpell(NPC_FIREWORK_RED);
                    break;
                case NPC_CLUSTER_YELLOW:
                    spellId = GetFireworkSpell(NPC_FIREWORK_YELLOW);
                    break;
                case NPC_CLUSTER_WHITE:
                    spellId = GetFireworkSpell(NPC_FIREWORK_WHITE);
                    break;
                case NPC_CLUSTER_BIG_BLUE:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BIG_BLUE);
                    break;
                case NPC_CLUSTER_BIG_GREEN:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BIG_GREEN);
                    break;
                case NPC_CLUSTER_BIG_PURPLE:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BIG_PURPLE);
                    break;
                case NPC_CLUSTER_BIG_RED:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BIG_RED);
                    break;
                case NPC_CLUSTER_BIG_YELLOW:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BIG_YELLOW);
                    break;
                case NPC_CLUSTER_BIG_WHITE:
                    spellId = GetFireworkSpell(NPC_FIREWORK_BIG_WHITE);
                    break;
                case NPC_CLUSTER_ELUNE:
                    spellId = GetFireworkSpell(urand(NPC_FIREWORK_BLUE, NPC_FIREWORK_WHITE));
                    break;
            }

            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE))
                if (SpellEffectInfo const* effect0 = spellInfo->GetEffect(EFFECT_0))
                    if (effect0->Effect == SPELL_EFFECT_SUMMON_OBJECT_WILD)
                        return effect0->MiscValue;

            return 0;
        }

        void Reset() override
        {
            if (GameObject* launcher = FindNearestLauncher())
            {
                launcher->SendCustomAnim(ANIM_GO_LAUNCH_FIREWORK);
                me->SetOrientation(launcher->GetOrientation() + float(M_PI) / 2);
            }
            else
                return;

            if (isCluster())
            {
                // Check if we are near Elune'ara lake south, if so try to summon Omen or a minion
                if (me->GetZoneId() == ZONE_MOONGLADE)
                {
                    if (!me->FindNearestCreature(NPC_OMEN, 100.0f) && me->GetDistance2d(omenSummonPos.GetPositionX(), omenSummonPos.GetPositionY()) <= 100.0f)
                    {
                        switch (urand(0, 9))
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                                if (Creature* minion = me->SummonCreature(NPC_MINION_OF_OMEN, me->GetPositionX()+frand(-5.0f, 5.0f), me->GetPositionY()+frand(-5.0f, 5.0f), me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                                    minion->AI()->AttackStart(me->SelectNearestPlayer(20.0f));
                                break;
                            case 9:
                                me->SummonCreature(NPC_OMEN, omenSummonPos);
                                break;
                        }
                    }
                }
                if (me->GetEntry() == NPC_CLUSTER_ELUNE)
                    DoCast(SPELL_LUNAR_FORTUNE);

                float displacement = 0.7f;
                for (uint8 i = 0; i < 4; i++)
                    me->SummonGameObject(GetFireworkGameObjectId(), me->GetPositionX() + (i % 2 == 0 ? displacement : -displacement), me->GetPositionY() + (i > 1 ? displacement : -displacement), me->GetPositionZ() + 4.0f, me->GetOrientation(), QuaternionData::fromEulerAnglesZYX(me->GetOrientation(), 0.0f, 0.0f), 1);
            }
            else
                //me->CastSpell(me, GetFireworkSpell(me->GetEntry()), true);
                me->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), GetFireworkSpell(me->GetEntry()), true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fireworkAI(creature);
    }
};

/*#####
# npc_spring_rabbit
#####*/

enum rabbitSpells
{
    SPELL_SPRING_FLING          = 61875,
    SPELL_SPRING_RABBIT_JUMP    = 61724,
    SPELL_SPRING_RABBIT_WANDER  = 61726,
    SPELL_SUMMON_BABY_BUNNY     = 61727,
    SPELL_SPRING_RABBIT_IN_LOVE = 61728,
    NPC_SPRING_RABBIT           = 32791
};

class npc_spring_rabbit : public CreatureScript
{
public:
    npc_spring_rabbit() : CreatureScript("npc_spring_rabbit") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spring_rabbitAI(creature);
    }

    struct npc_spring_rabbitAI : public ScriptedAI
    {
        npc_spring_rabbitAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            inLove = false;
            rabbitGUID.Clear();
            jumpTimer = urand(5000, 10000);
            bunnyTimer = urand(10000, 20000);
            searchTimer = urand(5000, 10000);
        }

        bool inLove;
        uint32 jumpTimer;
        uint32 bunnyTimer;
        uint32 searchTimer;
        ObjectGuid rabbitGUID;

        void Reset() override
        {
            Initialize();
            if (Unit* owner = me->GetOwner())
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void DoAction(int32 /*param*/) override
        {
            inLove = true;
            if (Unit* owner = me->GetOwner())
                owner->CastSpell(owner, SPELL_SPRING_FLING, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (inLove)
            {
                if (jumpTimer <= diff)
                {
                    if (Unit* rabbit = ObjectAccessor::GetUnit(*me, rabbitGUID))
                        DoCast(rabbit, SPELL_SPRING_RABBIT_JUMP);
                    jumpTimer = urand(5000, 10000);
                } else jumpTimer -= diff;

                if (bunnyTimer <= diff)
                {
                    DoCast(SPELL_SUMMON_BABY_BUNNY);
                    bunnyTimer = urand(20000, 40000);
                } else bunnyTimer -= diff;
            }
            else
            {
                if (searchTimer <= diff)
                {
                    if (Creature* rabbit = me->FindNearestCreature(NPC_SPRING_RABBIT, 10.0f))
                    {
                        if (rabbit == me || rabbit->HasAura(SPELL_SPRING_RABBIT_IN_LOVE))
                            return;

                        me->AddAura(SPELL_SPRING_RABBIT_IN_LOVE, me);
                        DoAction(1);
                        rabbit->AddAura(SPELL_SPRING_RABBIT_IN_LOVE, rabbit);
                        rabbit->AI()->DoAction(1);
                        rabbit->CastSpell(rabbit, SPELL_SPRING_RABBIT_JUMP, true);
                        rabbitGUID = rabbit->GetGUID();
                    }
                    searchTimer = urand(5000, 10000);
                } else searchTimer -= diff;
            }
        }
    };
};

class npc_imp_in_a_ball : public CreatureScript
{
private:
    enum
    {
        SAY_RANDOM,

        EVENT_TALK = 1,
    };

public:
    npc_imp_in_a_ball() : CreatureScript("npc_imp_in_a_ball") { }

    struct npc_imp_in_a_ballAI : public ScriptedAI
    {
        npc_imp_in_a_ballAI(Creature* creature) : ScriptedAI(creature)
        {
            summonerGUID.Clear();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->GetTypeId() == TYPEID_PLAYER)
            {
                summonerGUID = summoner->GetGUID();
                events.ScheduleEvent(EVENT_TALK, 3000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_TALK)
            {
                if (Player* owner = ObjectAccessor::GetPlayer(*me, summonerGUID))
                {
                    sCreatureTextMgr->SendChat(me, SAY_RANDOM, owner,
                        owner->GetGroup() ? CHAT_MSG_MONSTER_PARTY : CHAT_MSG_MONSTER_WHISPER, LANG_ADDON, TEXT_RANGE_NORMAL);
                }
            }
        }

    private:
        EventMap events;
        ObjectGuid summonerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_imp_in_a_ballAI(creature);
    }
};

enum TrainWrecker
{
    GO_TOY_TRAIN          = 193963,
    SPELL_TOY_TRAIN_PULSE =  61551,
    SPELL_WRECK_TRAIN     =  62943,
    ACTION_WRECKED        =      1,
    EVENT_DO_JUMP         =      1,
    EVENT_DO_FACING       =      2,
    EVENT_DO_WRECK        =      3,
    EVENT_DO_DANCE        =      4,
    MOVEID_CHASE          =      1,
    MOVEID_JUMP           =      2,

    NPC_EXULTING_WIND_UP_TRAIN_WRECKER = 81071
};
class npc_train_wrecker : public CreatureScript
{
    public:
        npc_train_wrecker() : CreatureScript("npc_train_wrecker") { }

        struct npc_train_wreckerAI : public NullCreatureAI
        {
            npc_train_wreckerAI(Creature* creature) : NullCreatureAI(creature), _isSearching(true), _nextAction(0), _timer(1 * IN_MILLISECONDS) { }

            GameObject* VerifyTarget() const
            {
                if (GameObject* target = ObjectAccessor::GetGameObject(*me, _target))
                    return target;
                me->HandleEmoteCommand(EMOTE_ONESHOT_RUDE);
                me->DespawnOrUnsummon(3 * IN_MILLISECONDS);
                return nullptr;
            }

            void UpdateAI(uint32 diff) override
            {
                if (_isSearching)
                {
                    if (diff < _timer)
                        _timer -= diff;
                    else
                    {
                        if (GameObject* target = me->FindNearestGameObject(GO_TOY_TRAIN, 15.0f))
                        {
                            _isSearching = false;
                            _target = target->GetGUID();
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(MOVEID_CHASE, target->GetNearPosition(3.0f, target->GetAngle(me)));
                        }
                        else
                            _timer = 3 * IN_MILLISECONDS;
                    }
                }
                else
                {
                    switch (_nextAction)
                    {
                        case EVENT_DO_JUMP:
                            if (GameObject* target = VerifyTarget())
                                me->GetMotionMaster()->MoveJump(*target, 5.0, 10.0, MOVEID_JUMP);
                            _nextAction = 0;
                            break;
                        case EVENT_DO_FACING:
                            if (GameObject* target = VerifyTarget())
                            {
                                me->SetFacingTo(target->GetOrientation());
                                me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);
                                _timer = 1.5 * IN_MILLISECONDS;
                                _nextAction = EVENT_DO_WRECK;
                            }
                            else
                                _nextAction = 0;
                            break;
                        case EVENT_DO_WRECK:
                            if (diff < _timer)
                            {
                                _timer -= diff;
                                break;
                            }
                            if (GameObject* target = VerifyTarget())
                            {
                                me->CastSpell(target, SPELL_WRECK_TRAIN, false);
                                target->AI()->DoAction(ACTION_WRECKED);
                                _timer = 2 * IN_MILLISECONDS;
                                _nextAction = EVENT_DO_DANCE;
                            }
                            else
                                _nextAction = 0;
                            break;
                        case EVENT_DO_DANCE:
                            if (diff < _timer)
                            {
                                _timer -= diff;
                                break;
                            }
                            me->UpdateEntry(NPC_EXULTING_WIND_UP_TRAIN_WRECKER);
                            me->SetEmoteState(EMOTE_ONESHOT_DANCE);
                            me->DespawnOrUnsummon(5 * IN_MILLISECONDS);
                            _nextAction = 0;
                            break;
                        default:
                            break;
                    }
                }
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id == MOVEID_CHASE)
                    _nextAction = EVENT_DO_JUMP;
                else if (id == MOVEID_JUMP)
                    _nextAction = EVENT_DO_FACING;
            }

        private:
            bool _isSearching;
            uint8 _nextAction;
            uint32 _timer;
            ObjectGuid _target;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_train_wreckerAI(creature);
        }
};

/*######
## npc_argent_squire/gruntling
######*/

enum Pennants
{
    SPELL_DARNASSUS_PENNANT     = 63443,
    SPELL_EXODAR_PENNANT        = 63439,
    SPELL_GNOMEREGAN_PENNANT    = 63442,
    SPELL_IRONFORGE_PENNANT     = 63440,
    SPELL_STORMWIND_PENNANT     = 62727,
    SPELL_SENJIN_PENNANT        = 63446,
    SPELL_UNDERCITY_PENNANT     = 63441,
    SPELL_ORGRIMMAR_PENNANT     = 63444,
    SPELL_SILVERMOON_PENNANT    = 63438,
    SPELL_THUNDERBLUFF_PENNANT  = 63445,
    SPELL_AURA_POSTMAN_S        = 67376,
    SPELL_AURA_SHOP_S           = 67377,
    SPELL_AURA_BANK_S           = 67368,
    SPELL_AURA_TIRED_S          = 67401,
    SPELL_AURA_BANK_G           = 68849,
    SPELL_AURA_POSTMAN_G        = 68850,
    SPELL_AURA_SHOP_G           = 68851,
    SPELL_AURA_TIRED_G          = 68852,
    SPELL_TIRED_PLAYER          = 67334
};

enum ArgentPetGossipOptions
{
    GOSSIP_OPTION_BANK                            = 0,
    GOSSIP_OPTION_SHOP                            = 1,
    GOSSIP_OPTION_MAIL                            = 2,
    GOSSIP_OPTION_DARNASSUS_SENJIN_PENNANT        = 3,
    GOSSIP_OPTION_EXODAR_UNDERCITY_PENNANT        = 4,
    GOSSIP_OPTION_GNOMEREGAN_ORGRIMMAR_PENNANT    = 5,
    GOSSIP_OPTION_IRONFORGE_SILVERMOON_PENNANT    = 6,
    GOSSIP_OPTION_STORMWIND_THUNDERBLUFF_PENNANT  = 7
};

enum Misc
{
    NPC_ARGENT_SQUIRE  = 33238
};

struct ArgentPonyBannerSpells
{
    uint32 spellSquire;
    uint32 spellGruntling;
};

ArgentPonyBannerSpells const bannerSpells[5] =
{
    { SPELL_DARNASSUS_PENNANT, SPELL_SENJIN_PENNANT },
    { SPELL_EXODAR_PENNANT, SPELL_UNDERCITY_PENNANT },
    { SPELL_GNOMEREGAN_PENNANT, SPELL_ORGRIMMAR_PENNANT },
    { SPELL_IRONFORGE_PENNANT, SPELL_SILVERMOON_PENNANT },
    { SPELL_STORMWIND_PENNANT, SPELL_THUNDERBLUFF_PENNANT }
};

class npc_argent_squire_gruntling : public CreatureScript
{
public:
    npc_argent_squire_gruntling() : CreatureScript("npc_argent_squire_gruntling") { }

    struct npc_argent_squire_gruntlingAI : public ScriptedAI
    {
        npc_argent_squire_gruntlingAI(Creature* creature) : ScriptedAI(creature)
        {
            ScheduleTasks();
        }

        void ScheduleTasks()
        {
            _scheduler
                .Schedule(Seconds(1), [this](TaskContext /*context*/)
                {
                    if (Aura* ownerTired = me->GetOwner()->GetAura(SPELL_TIRED_PLAYER))
                        if (Aura* squireTired = me->AddAura(IsArgentSquire() ? SPELL_AURA_TIRED_S : SPELL_AURA_TIRED_G, me))
                            squireTired->SetDuration(ownerTired->GetDuration());
                })
                .Schedule(Seconds(1), [this](TaskContext context)
                {
                    if ((me->HasAura(SPELL_AURA_TIRED_S) || me->HasAura(SPELL_AURA_TIRED_G)) && me->HasNpcFlag(NPCFlags(UNIT_NPC_FLAG_BANKER | UNIT_NPC_FLAG_MAILBOX | UNIT_NPC_FLAG_VENDOR)))
                        me->RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_BANKER | UNIT_NPC_FLAG_MAILBOX | UNIT_NPC_FLAG_VENDOR));
                    context.Repeat();
                });
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            switch (gossipListId)
            {
                case GOSSIP_OPTION_BANK:
                {
                    me->AddNpcFlag(UNIT_NPC_FLAG_BANKER);
                    uint32 _bankAura = IsArgentSquire() ? SPELL_AURA_BANK_S : SPELL_AURA_BANK_G;
                    if (!me->HasAura(_bankAura))
                        DoCastSelf(_bankAura);

                    if (!player->HasAura(SPELL_TIRED_PLAYER))
                        player->CastSpell(player, SPELL_TIRED_PLAYER, true);
                    break;
                }
                case GOSSIP_OPTION_SHOP:
                {
                    me->AddNpcFlag(UNIT_NPC_FLAG_VENDOR);
                    uint32 _shopAura = IsArgentSquire() ? SPELL_AURA_SHOP_S : SPELL_AURA_SHOP_G;
                    if (!me->HasAura(_shopAura))
                        DoCastSelf(_shopAura);

                    if (!player->HasAura(SPELL_TIRED_PLAYER))
                        player->CastSpell(player, SPELL_TIRED_PLAYER, true);
                    break;
                }
                case GOSSIP_OPTION_MAIL:
                {
                    me->AddNpcFlag(UNIT_NPC_FLAG_MAILBOX);
                    player->GetSession()->SendShowMailBox(me->GetGUID());

                    uint32 _mailAura = IsArgentSquire() ? SPELL_AURA_POSTMAN_S : SPELL_AURA_POSTMAN_G;
                    if (!me->HasAura(_mailAura))
                        DoCastSelf(_mailAura);

                    if (!player->HasAura(SPELL_TIRED_PLAYER))
                        player->CastSpell(player, SPELL_TIRED_PLAYER, true);
                    break;
                }
                case GOSSIP_OPTION_DARNASSUS_SENJIN_PENNANT:
                case GOSSIP_OPTION_EXODAR_UNDERCITY_PENNANT:
                case GOSSIP_OPTION_GNOMEREGAN_ORGRIMMAR_PENNANT:
                case GOSSIP_OPTION_IRONFORGE_SILVERMOON_PENNANT:
                case GOSSIP_OPTION_STORMWIND_THUNDERBLUFF_PENNANT:
                    if (IsArgentSquire())
                        DoCastSelf(bannerSpells[gossipListId - 3].spellSquire, true);
                    else
                        DoCastSelf(bannerSpells[gossipListId - 3].spellGruntling, true);
                    break;
            }
            player->PlayerTalkClass->SendCloseGossip();
            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

        bool IsArgentSquire() const { return me->GetEntry() == NPC_ARGENT_SQUIRE; }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature *creature) const override
    {
        return new npc_argent_squire_gruntlingAI(creature);
    }
};

enum BountifulTable
{
    SEAT_TURKEY_CHAIR                       = 0,
    SEAT_CRANBERRY_CHAIR                    = 1,
    SEAT_STUFFING_CHAIR                     = 2,
    SEAT_SWEET_POTATO_CHAIR                 = 3,
    SEAT_PIE_CHAIR                          = 4,
    SEAT_FOOD_HOLDER                        = 5,
    SEAT_PLATE_HOLDER                       = 6,
    NPC_THE_TURKEY_CHAIR                    = 34812,
    NPC_THE_CRANBERRY_CHAIR                 = 34823,
    NPC_THE_STUFFING_CHAIR                  = 34819,
    NPC_THE_SWEET_POTATO_CHAIR              = 34824,
    NPC_THE_PIE_CHAIR                       = 34822,
    SPELL_CRANBERRY_SERVER                  = 61793,
    SPELL_PIE_SERVER                        = 61794,
    SPELL_STUFFING_SERVER                   = 61795,
    SPELL_TURKEY_SERVER                     = 61796,
    SPELL_SWEET_POTATOES_SERVER             = 61797
};

typedef std::unordered_map<uint32 /*Entry*/, uint32 /*Spell*/> ChairSpells;
ChairSpells const _chairSpells =
{
    { NPC_THE_CRANBERRY_CHAIR, SPELL_CRANBERRY_SERVER },
    { NPC_THE_PIE_CHAIR, SPELL_PIE_SERVER },
    { NPC_THE_STUFFING_CHAIR, SPELL_STUFFING_SERVER },
    { NPC_THE_TURKEY_CHAIR, SPELL_TURKEY_SERVER },
    { NPC_THE_SWEET_POTATO_CHAIR, SPELL_SWEET_POTATOES_SERVER },
};

class CastFoodSpell : public BasicEvent
{
    public:
        CastFoodSpell(Unit* owner, uint32 spellId) : _owner(owner), _spellId(spellId) { }

        bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, _spellId, true);
            return false;
        }

    private:
        Unit* _owner;
        uint32 _spellId;
};

class npc_bountiful_table : public CreatureScript
{
public:
    npc_bountiful_table() : CreatureScript("npc_bountiful_table") { }

    struct npc_bountiful_tableAI : public PassiveAI
    {
        npc_bountiful_tableAI(Creature* creature) : PassiveAI(creature) { }

        void PassengerBoarded(Unit* who, int8 seatId, bool /*apply*/) override
        {
            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;
            float o = 0.0f;

            switch (seatId)
            {
                case SEAT_TURKEY_CHAIR:
                    x = 3.87f;
                    y = 2.07f;
                    o = 3.700098f;
                    break;
                case SEAT_CRANBERRY_CHAIR:
                    x = 3.87f;
                    y = -2.07f;
                    o = 2.460914f;
                    break;
                case SEAT_STUFFING_CHAIR:
                    x = -2.52f;
                    break;
                case SEAT_SWEET_POTATO_CHAIR:
                    x = -0.09f;
                    y = -3.24f;
                    o = 1.186824f;
                    break;
                case SEAT_PIE_CHAIR:
                    x = -0.18f;
                    y = 3.24f;
                    o = 5.009095f;
                    break;
                case SEAT_FOOD_HOLDER:
                case SEAT_PLATE_HOLDER:
                    if (Vehicle* holders = who->GetVehicleKit())
                        holders->InstallAllAccessories(true);
                    return;
                default:
                    break;
            }

            Movement::MoveSplineInit init(who);
            init.DisableTransportPathTransformations();
            init.MoveTo(x, y, z, false);
            init.SetFacing(o);
            init.Launch();
            who->m_Events.AddEvent(new CastFoodSpell(who, _chairSpells.at(who->GetEntry())), who->m_Events.CalculateTime(1000));
            if (Creature* creature = who->ToCreature())
                creature->SetDisplayFromModel(0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bountiful_tableAI(creature);
    }
};

void AddSC_npcs_special()
{
    new npc_air_force_bots();
    new npc_chicken_cluck();
    new npc_dancing_flames();
    new npc_torch_tossing_target_bunny_controller();
    new npc_midsummer_bunny_pole();
    new npc_doctor();
    new npc_injured_patient();
    new npc_garments_of_quests();
    new npc_guardian();
    new npc_sayge();
    new npc_steam_tonk();
    new npc_tonk_mine();
    new npc_tournament_mount();
    new npc_brewfest_reveler();
    new npc_training_dummy();
    new npc_wormhole();
    new npc_experience();
    new npc_firework();
    new npc_spring_rabbit();
    new npc_imp_in_a_ball();
    new npc_train_wrecker();
    new npc_argent_squire_gruntling();
    new npc_bountiful_table();
}
