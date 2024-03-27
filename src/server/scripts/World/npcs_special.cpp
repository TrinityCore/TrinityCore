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
#include "CharmInfo.h"
#include "CombatAI.h"
#include "Containers.h"
#include "CreatureTextMgr.h"
#include "GameEventMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
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

/*########
# npc_air_force_bots
#########*/

enum AirForceBots
{
    TRIPWIRE, // do not attack flying players, smaller range
    ALARMBOT, // attack flying players, casts guard's mark

    SPELL_GUARDS_MARK = 38067
};

float constexpr RANGE_TRIPWIRE =  15.0f;
float constexpr RANGE_ALARMBOT = 100.0f;

struct AirForceSpawn
{
    uint32 myEntry;
    uint32 otherEntry;
    AirForceBots type;
};

AirForceSpawn constexpr airforceSpawns[] =
{
    {2614,  15241, ALARMBOT}, // Air Force Alarm Bot (Alliance)
    {2615,  15242, ALARMBOT}, // Air Force Alarm Bot (Horde)
    {21974, 21976, ALARMBOT}, // Air Force Alarm Bot (Area 52)
    {21993, 15242, ALARMBOT}, // Air Force Guard Post (Horde - Bat Rider)
    {21996, 15241, ALARMBOT}, // Air Force Guard Post (Alliance - Gryphon)
    {21997, 21976, ALARMBOT}, // Air Force Guard Post (Goblin - Area 52 - Zeppelin)
    {21999, 15241, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Alliance)
    {22001, 15242, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Horde)
    {22002, 15242, TRIPWIRE}, // Air Force Trip Wire - Ground (Horde)
    {22003, 15241, TRIPWIRE}, // Air Force Trip Wire - Ground (Alliance)
    {22063, 21976, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Goblin - Area 52)
    {22065, 22064, ALARMBOT}, // Air Force Guard Post (Ethereal - Stormspire)
    {22066, 22067, ALARMBOT}, // Air Force Guard Post (Scryer - Dragonhawk)
    {22068, 22064, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
    {22069, 22064, ALARMBOT}, // Air Force Alarm Bot (Stormspire)
    {22070, 22067, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Scryer)
    {22071, 22067, ALARMBOT}, // Air Force Alarm Bot (Scryer)
    {22078, 22077, ALARMBOT}, // Air Force Alarm Bot (Aldor)
    {22079, 22077, ALARMBOT}, // Air Force Guard Post (Aldor - Gryphon)
    {22080, 22077, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Aldor)
    {22086, 22085, ALARMBOT}, // Air Force Alarm Bot (Sporeggar)
    {22087, 22085, ALARMBOT}, // Air Force Guard Post (Sporeggar - Spore Bat)
    {22088, 22085, TRIPWIRE}, // Air Force Trip Wire - Rooftop (Sporeggar)
    {22090, 22089, ALARMBOT}, // Air Force Guard Post (Toshley's Station - Flying Machine)
    {22124, 22122, ALARMBOT}, // Air Force Alarm Bot (Cenarion)
    {22125, 22122, ALARMBOT}, // Air Force Guard Post (Cenarion - Stormcrow)
    {22126, 22122, ALARMBOT}  // Air Force Trip Wire - Rooftop (Cenarion Expedition)
};

class npc_air_force_bots : public CreatureScript
{
public:
    npc_air_force_bots() : CreatureScript("npc_air_force_bots") { }

    struct npc_air_force_botsAI : public NullCreatureAI
    {
        static AirForceSpawn const& FindSpawnFor(uint32 entry)
        {
            for (AirForceSpawn const& spawn : airforceSpawns)
            {
                if (spawn.myEntry == entry)
                {
                    ASSERT_NODEBUGINFO(sObjectMgr->GetCreatureTemplate(spawn.otherEntry), "Invalid creature entry %u in 'npc_air_force_bots' script", spawn.otherEntry);
                    return spawn;
                }
            }
            ASSERT_NODEBUGINFO(false, "Unhandled creature with entry %u is assigned 'npc_air_force_bots' script", entry);
        }

        npc_air_force_botsAI(Creature* creature) : NullCreatureAI(creature), _spawn(FindSpawnFor(creature->GetEntry())) {}

        Creature* GetOrSummonGuard()
        {
            Creature* guard = ObjectAccessor::GetCreature(*me, _myGuard);

            if (!guard && (guard = me->SummonCreature(_spawn.otherEntry, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5min)))
                _myGuard = guard->GetGUID();

            return guard;
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (_toAttack.empty())
                return;

            Creature* guard = GetOrSummonGuard();
            if (!guard)
                return;

            // Keep the list of targets for later on when the guards will be alive
            if (!guard->IsAlive())
                return;

            for (ObjectGuid guid : _toAttack)
            {
                Unit* target = ObjectAccessor::GetUnit(*me, guid);
                if (!target)
                    continue;
                if (guard->IsEngagedBy(target))
                    continue;

                guard->EngageWithTarget(target);
                if (_spawn.type == ALARMBOT)
                    guard->CastSpell(target, SPELL_GUARDS_MARK, true);
            }

            _toAttack.clear();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            // guards are only spawned against players
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            // we're already scheduled to attack this player on our next tick, don't bother checking
            if (_toAttack.find(who->GetGUID()) != _toAttack.end())
                return;

            // check if they're in range
            if (!who->IsWithinDistInMap(me, (_spawn.type == ALARMBOT) ? RANGE_ALARMBOT : RANGE_TRIPWIRE))
                return;

            // check if they're hostile
            if (!(me->IsHostileTo(who) || who->IsHostileTo(me)))
                return;

            // check if they're a valid attack target
            if (!me->IsValidAttackTarget(who))
                return;

            if ((_spawn.type == TRIPWIRE) && who->IsFlying())
                return;

            _toAttack.insert(who->GetGUID());
        }

        private:
            AirForceSpawn const& _spawn;
            ObjectGuid _myGuard;
            std::unordered_set<ObjectGuid> _toAttack;

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

        void JustEngagedWith(Unit* /*who*/) override { }

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

            UpdateVictim();
        }

        void ReceiveEmote(Player* player, uint32 emote) override
        {
            switch (emote)
            {
                case TEXT_EMOTE_CHICKEN:
                    if (player->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_NONE && rand32() % 30 == 1)
                    {
                        me->SetNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFaction(FACTION_FRIENDLY);
                        Talk(player->GetTeam() == HORDE ? EMOTE_HELLO_H : EMOTE_HELLO_A);
                    }
                    break;
                case TEXT_EMOTE_CHEER:
                    if (player->GetQuestStatus(QUEST_CLUCK) == QUEST_STATUS_COMPLETE)
                    {
                        me->SetNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFaction(FACTION_FRIENDLY);
                        Talk(EMOTE_CLUCK_TEXT);
                    }
                    break;
            }
        }

        void OnQuestAccept(Player* /*player*/, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_CLUCK)
                Reset();
        }

        void OnQuestReward(Player* /*player*/, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
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
    SPELL_SUMMON_BRAZIER    = 45423,
    SPELL_BRAZIER_DANCE     = 45427,
    SPELL_FIERY_SEDUCTION   = 47057
};

struct npc_dancing_flames : public ScriptedAI
{
    npc_dancing_flames(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(SPELL_SUMMON_BRAZIER, true);
        DoCastSelf(SPELL_BRAZIER_DANCE, false);
        me->SetEmoteState(EMOTE_STATE_DANCE);
        float x, y, z;
        me->GetPosition(x, y, z);
        me->Relocate(x, y, z + 1.05f);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void ReceiveEmote(Player* player, uint32 emote) override
    {
        if (me->IsWithinLOS(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()) && me->IsWithinDistInMap(player, 30.0f))
        {
            // She responds to emotes not instantly but ~1500ms later
            // If you first /bow, then /wave before dancing flames bow back, it doesnt bow at all and only does wave
            // If you're performing emotes too fast, she will not respond to them
            // Means she just replaces currently scheduled event with new after receiving new emote
            _scheduler.CancelAll();

            switch (emote)
            {
                case TEXT_EMOTE_KISS:
                    _scheduler.Schedule(1500ms, [this](TaskContext /*context*/)
                    {
                        me->HandleEmoteCommand(EMOTE_ONESHOT_SHY);
                    });
                    break;
                case TEXT_EMOTE_WAVE:
                    _scheduler.Schedule(1500ms, [this](TaskContext /*context*/)
                    {
                        me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                    });
                    break;
                case TEXT_EMOTE_BOW:
                    _scheduler.Schedule(1500ms, [this](TaskContext /*context*/)
                    {
                        me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                    });
                    break;
                case TEXT_EMOTE_JOKE:
                    _scheduler.Schedule(1500ms, [this](TaskContext /*context*/)
                    {
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                    });
                    break;
                case TEXT_EMOTE_DANCE:
                    if (!player->HasAura(SPELL_FIERY_SEDUCTION))
                    {
                        DoCast(player, SPELL_FIERY_SEDUCTION, true);
                        me->SetFacingTo(me->GetAbsoluteAngle(player));
                    }
                    break;
            }
        }
    }

private:
    TaskScheduler _scheduler;
};

/*######
## npc_torch_tossing_target_bunny_controller
######*/

enum TorchTossingTarget
{
    SPELL_TORCH_TARGET_PICKER      = 45907
};

class npc_torch_tossing_target_bunny_controller : public CreatureScript
{
public:
    npc_torch_tossing_target_bunny_controller() : CreatureScript("npc_torch_tossing_target_bunny_controller") { }

    struct npc_torch_tossing_target_bunny_controllerAI : public ScriptedAI
    {
        npc_torch_tossing_target_bunny_controllerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(2), [this](TaskContext context)
            {
                me->CastSpell(nullptr, SPELL_TORCH_TARGET_PICKER);
                _scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
                {
                    me->CastSpell(nullptr, SPELL_TORCH_TARGET_PICKER);
                });
                context.Repeat(Seconds(5));
            });
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
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
            events.ScheduleEvent(EVENT_CAST_RED_FIRE_RING, 1ms);
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

                events.ScheduleEvent(EVENT_CAST_BLUE_FIRE_RING, 5s);
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

                events.ScheduleEvent(EVENT_CAST_RED_FIRE_RING, 5s);
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
            me->SetUninteractible(false);
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
            me->SetUninteractible(true);
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

        void JustEngagedWith(Unit* /*who*/) override { }

        void OnQuestAccept(Player* player, Quest const* quest) override
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
            Coord = nullptr;
        }

        ObjectGuid DoctorGUID;
        Position const* Coord;

        void Reset() override
        {
            Initialize();

            //no select
            me->SetUninteractible(false);

            //no regen health
            me->SetUnitFlag(UNIT_FLAG_IN_COMBAT);

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

        void JustEngagedWith(Unit* /*who*/) override { }

        void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
        {
            Player* player = caster->ToPlayer();
            if (!player || !me->IsAlive() || spellInfo->Id != 20804)
                return;

            if (player->GetQuestStatus(6624) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(6622) == QUEST_STATUS_INCOMPLETE)
                if (!DoctorGUID.IsEmpty())
                    if (Creature* doctor = ObjectAccessor::GetCreature(*me, DoctorGUID))
                        ENSURE_AI(npc_doctor::npc_doctorAI, doctor->AI())->PatientSaved(me, player, Coord);

            //make uninteractible
            me->SetUninteractible(true);

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
                me->SetUninteractible(true);
                me->setDeathState(JUST_DIED);
                me->SetUnitFlag3(UNIT_FLAG3_FAKE_DEAD);

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

            if (Creature* Patient = me->SummonCreature(patientEntry, **point, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5s))
            {
                //303, this flag appear to be required for client side item->spell to work (TARGET_SINGLE_FRIEND)
                Patient->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);

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

    struct npc_garments_of_questsAI : public EscortAI
    {
        npc_garments_of_questsAI(Creature* creature) : EscortAI(creature)
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

            Initialize();
        }

        void Initialize()
        {
            IsHealed = false;
            CanRun = false;

            RunAwayTimer = 5000;
        }

        ObjectGuid CasterGUID;

        bool IsHealed;
        bool CanRun;

        uint32 RunAwayTimer;
        uint32 quest;

        void Reset() override
        {
            CasterGUID.Clear();

            Initialize();

            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            // expect database to have RegenHealth=0
            me->SetSpawnHealth();
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_LESSER_HEAL_R2 || spellInfo->Id == SPELL_FORTITUDE_R1)
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
                        if (IsHealed && !CanRun && spellInfo->Id == SPELL_FORTITUDE_R1)
                        {
                            Talk(SAY_THANKS, player);
                            CanRun = true;
                        }
                        else if (!IsHealed && spellInfo->Id == SPELL_LESSER_HEAL_R2)
                        {
                            CasterGUID = player->GetGUID();
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            Talk(SAY_HEALED, player);
                            IsHealed = true;
                        }
                    }

                    // give quest credit, not expect any special quest objectives
                    if (CanRun)
                        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
                }
            }
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

                        LoadPath((me->GetEntry() << 3) | 2);
                        Start(false);
                    }
                    else
                        EnterEvadeMode(EvadeReason::Other);                       //something went wrong

                    RunAwayTimer = 30000;
                }
                else
                    RunAwayTimer -= diff;
            }

            EscortAI::UpdateAI(diff);
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
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void JustEngagedWith(Unit* /*who*/) override
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

class npc_steam_tonk : public CreatureScript
{
public:
    npc_steam_tonk() : CreatureScript("npc_steam_tonk") { }

    struct npc_steam_tonkAI : public ScriptedAI
    {
        npc_steam_tonkAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }
        void JustEngagedWith(Unit* /*who*/) override { }

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
                    player->CastSpell(nullptr, _pennantSpellId, true);
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
                            return player->GetClass() == CLASS_DEATH_KNIGHT ? SPELL_PENNANT_EBON_BLADE_CHAMPION : SPELL_PENNANT_ARGENT_CRUSADE_CHAMPION;
                        else if (player->HasAchieved(ACHIEVEMENT_ARGENT_VALOR))
                            return player->GetClass() == CLASS_DEATH_KNIGHT ? SPELL_PENNANT_EBON_BLADE_VALIANT : SPELL_PENNANT_ARGENT_CRUSADE_VALIANT;
                        else
                            return player->GetClass() == CLASS_DEATH_KNIGHT ? SPELL_PENNANT_EBON_BLADE_ASPIRANT : SPELL_PENNANT_ARGENT_CRUSADE_ASPIRANT;
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

/*######
# npc_brewfest_reveler_2
######*/

Emote const BrewfestRandomEmote[] =
{
    EMOTE_ONESHOT_QUESTION,
    EMOTE_ONESHOT_APPLAUD,
    EMOTE_ONESHOT_SHOUT,
    EMOTE_ONESHOT_EAT_NO_SHEATHE,
    EMOTE_ONESHOT_LAUGH_NO_SHEATHE
};

struct npc_brewfest_reveler_2 : ScriptedAI
{
    enum BrewfestReveler2
    {
        NPC_BREWFEST_REVELER    = 24484,

        EVENT_FILL_LIST         = 1,
        EVENT_FACE_TO           = 2,
        EVENT_EMOTE             = 3,
        EVENT_NEXT              = 4
    };

    npc_brewfest_reveler_2(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FILL_LIST, 1s, 2s);
    }

    // Copied from old script. I don't know if this is 100% correct.
    void ReceiveEmote(Player* player, uint32 emote) override
    {
        if (!IsHolidayActive(HOLIDAY_BREWFEST))
            return;

        if (emote == TEXT_EMOTE_DANCE)
            me->CastSpell(player, SPELL_BREWFEST_TOAST, false);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FILL_LIST:
                {
                    std::list<Creature*> creatureList;
                    GetCreatureListWithEntryInGrid(creatureList, me, NPC_BREWFEST_REVELER, 5.0f);
                    for (Creature* creature : creatureList)
                        if (creature != me)
                            _revelerGuids.push_back(creature->GetGUID());

                    _events.ScheduleEvent(EVENT_FACE_TO, 1s, 2s);
                    break;
                }
                case EVENT_FACE_TO:
                {
                    // Turn to random brewfest reveler within set range
                    if (!_revelerGuids.empty())
                        if (Creature* creature = ObjectAccessor::GetCreature(*me, Trinity::Containers::SelectRandomContainerElement(_revelerGuids)))
                            me->SetFacingToObject(creature);

                    _events.ScheduleEvent(EVENT_EMOTE, 2s, 6s);
                    break;
                }
                case EVENT_EMOTE:
                    // Play random emote or dance
                    if (roll_chance_i(50))
                    {
                        me->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(BrewfestRandomEmote));
                        _events.ScheduleEvent(EVENT_NEXT, 4s, 6s);
                    }
                    else
                    {
                        me->SetEmoteState(EMOTE_STATE_DANCE);
                        _events.ScheduleEvent(EVENT_NEXT, 8s, 12s);
                    }
                    break;
                case EVENT_NEXT:
                    // If dancing stop before next random state
                    if (me->GetEmoteState() == EMOTE_STATE_DANCE)
                        me->SetEmoteState(EMOTE_ONESHOT_NONE);

                    // Random EVENT_EMOTE or EVENT_FACETO
                    if (roll_chance_i(50))
                        _events.ScheduleEvent(EVENT_FACE_TO, 1s);
                    else
                        _events.ScheduleEvent(EVENT_EMOTE, 1s);
                    break;
                default:
                    break;
                }
        }
    }

private:
    EventMap _events;
    GuidVector _revelerGuids;
};

struct npc_training_dummy : NullCreatureAI
{
    npc_training_dummy(Creature* creature) : NullCreatureAI(creature) { }

    void JustEnteredCombat(Unit* who) override
    {
        _combatTimer[who->GetGUID()] = 5s;
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType damageType, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = 0;

        if (!attacker || damageType == DOT)
            return;

        _combatTimer[attacker->GetGUID()] = 5s;
    }

    void UpdateAI(uint32 diff) override
    {
        for (auto itr = _combatTimer.begin(); itr != _combatTimer.end();)
        {
            itr->second -= Milliseconds(diff);
            if (itr->second <= 0s)
            {
                // The attacker has not dealt any damage to the dummy for over 5 seconds. End combat.
                auto const& pveRefs = me->GetCombatManager().GetPvECombatRefs();
                auto it = pveRefs.find(itr->first);
                if (it != pveRefs.end())
                    it->second->EndCombat();

                itr = _combatTimer.erase(itr);
            }
            else
                ++itr;
        }
    }
private:
    std::unordered_map<ObjectGuid /*attackerGUID*/, Milliseconds /*combatTime*/> _combatTimer;
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

            bool OnGossipHello(Player* player) override
            {
                InitGossipMenuFor(player, MENU_ID_WORMHOLE);
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

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
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

        void JustEngagedWith(Unit* /*who*/) override { }

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

        void IsSummonedBy(WorldObject* summoner) override
        {
            if (summoner->GetTypeId() == TYPEID_PLAYER)
            {
                summonerGUID = summoner->GetGUID();
                events.ScheduleEvent(EVENT_TALK, 3s);
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
                me->DespawnOrUnsummon(3s);
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
                            me->GetMotionMaster()->MovePoint(MOVEID_CHASE, target->GetNearPosition(3.0f, target->GetAbsoluteAngle(me)));
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
                                _timer = 1.5 * AsUnderlyingType(IN_MILLISECONDS);
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
                            me->DespawnOrUnsummon(5s);
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
    NPC_ARGENT_SQUIRE   = 33238,
    ACHIEVEMENT_PONY_UP = 3736
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
        }

        void Reset() override
        {
            if (Player* owner = Object::ToPlayer(me->GetOwner()))
            {
                if (Aura* ownerTired = owner->GetAura(SPELL_TIRED_PLAYER))
                    if (Aura* squireTired = me->AddAura(IsArgentSquire() ? SPELL_AURA_TIRED_S : SPELL_AURA_TIRED_G, me))
                        squireTired->SetDuration(ownerTired->GetDuration());

                if (owner->HasAchieved(ACHIEVEMENT_PONY_UP) && !me->HasAura(SPELL_AURA_TIRED_S) && !me->HasAura(SPELL_AURA_TIRED_G))
                {
                    me->SetNpcFlag(UNIT_NPC_FLAG_BANKER | UNIT_NPC_FLAG_MAILBOX | UNIT_NPC_FLAG_VENDOR);
                    return;
                }
            }

            me->RemoveNpcFlag(UNIT_NPC_FLAG_BANKER | UNIT_NPC_FLAG_MAILBOX | UNIT_NPC_FLAG_VENDOR);
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            switch (gossipListId)
            {
                case GOSSIP_OPTION_BANK:
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_MAILBOX | UNIT_NPC_FLAG_VENDOR);
                    uint32 _bankAura = IsArgentSquire() ? SPELL_AURA_BANK_S : SPELL_AURA_BANK_G;
                    if (!me->HasAura(_bankAura))
                        DoCastSelf(_bankAura);

                    if (!player->HasAura(SPELL_TIRED_PLAYER))
                        player->CastSpell(player, SPELL_TIRED_PLAYER, true);
                    break;
                }
                case GOSSIP_OPTION_SHOP:
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_BANKER | UNIT_NPC_FLAG_MAILBOX);
                    uint32 _shopAura = IsArgentSquire() ? SPELL_AURA_SHOP_S : SPELL_AURA_SHOP_G;
                    if (!me->HasAura(_shopAura))
                        DoCastSelf(_shopAura);

                    if (!player->HasAura(SPELL_TIRED_PLAYER))
                        player->CastSpell(player, SPELL_TIRED_PLAYER, true);
                    break;
                }
                case GOSSIP_OPTION_MAIL:
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_BANKER | UNIT_NPC_FLAG_VENDOR);
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

                    player->PlayerTalkClass->SendCloseGossip();
                    break;
                default:
                    break;
            }

            return false;
        }

        bool IsArgentSquire() const { return me->GetEntry() == NPC_ARGENT_SQUIRE; }
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
            return true;
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

            std::function<void(Movement::MoveSplineInit&)> initializer = [=](Movement::MoveSplineInit& init)
            {
                init.DisableTransportPathTransformations();
                init.MoveTo(x, y, z, false);
                init.SetFacing(o);
            };
            who->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), EVENT_VEHICLE_BOARD, MOTION_PRIORITY_HIGHEST);
            who->m_Events.AddEvent(new CastFoodSpell(who, _chairSpells.at(who->GetEntry())), who->m_Events.CalculateTime(1s));
            if (Creature* creature = who->ToCreature())
                creature->SetDisplayFromModel(0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bountiful_tableAI(creature);
    }
};

enum VoidZone
{
    SPELL_CONSUMPTION     = 28874
};

struct npc_gen_void_zone : public ScriptedAI
{
    npc_gen_void_zone(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_CONSUMPTION);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_npcs_special()
{
    new npc_air_force_bots();
    new npc_chicken_cluck();
    RegisterCreatureAI(npc_dancing_flames);
    new npc_torch_tossing_target_bunny_controller();
    new npc_midsummer_bunny_pole();
    new npc_doctor();
    new npc_injured_patient();
    new npc_garments_of_quests();
    new npc_guardian();
    new npc_steam_tonk();
    new npc_tournament_mount();
    new npc_brewfest_reveler();
    RegisterCreatureAI(npc_brewfest_reveler_2);
    RegisterCreatureAI(npc_training_dummy);
    new npc_wormhole();
    new npc_spring_rabbit();
    new npc_imp_in_a_ball();
    new npc_train_wrecker();
    new npc_argent_squire_gruntling();
    new npc_bountiful_table();
    RegisterCreatureAI(npc_gen_void_zone);
}
