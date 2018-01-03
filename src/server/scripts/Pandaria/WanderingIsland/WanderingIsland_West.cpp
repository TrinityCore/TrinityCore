/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "Vehicle.h"

#define GOSSIP_WIND     "I would like to go back on the top of the temple"
#define ACTION_TALK 1
class mob_master_shang_xi_temple : public CreatureScript
{
public:
    mob_master_shang_xi_temple() : CreatureScript("mob_master_shang_xi_temple") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == 29776) // Brise du matin
        {
            if (Creature* vehicle = player->SummonCreature(55685, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation()))
            {
                player->AddAura(99385, vehicle);
                player->EnterVehicle(vehicle);
            }
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(29776) != QUEST_STATUS_NONE)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_WIND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, 1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            player->NearTeleportTo(926.58f, 3605.33f, 251.63f, 3.114f);
        }

        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_master_shang_xi_templeAI(creature);
    }

    struct mob_master_shang_xi_templeAI : public ScriptedAI
    {
        mob_master_shang_xi_templeAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 l_CheckTimer;
        uint32 l_TalkRefill;
        bool hasSaid1;

        void Reset() override
        {
            hasSaid1 = false;
            l_CheckTimer = 1500;
            l_TalkRefill = 30000;
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case ACTION_TALK:
                    if (!hasSaid1)
                    {
                        Talk(0);
                        hasSaid1 = true;
                    }
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (l_CheckTimer)
            {
                if (l_CheckTimer <= diff)
                {
                    std::list<Player*> l_PlayerList;
                    GetPlayerListInGrid(l_PlayerList, me, 15.0f);

                    for (Player* l_Player : l_PlayerList)
                    {
                        if (l_Player->GetQuestStatus(29775) == QUEST_STATUS_INCOMPLETE && l_Player->GetQuestObjectiveCounter(276326) < 1)
                            l_Player->KilledMonsterCredit(59497);
                        else if (l_Player->GetQuestStatus(29423) == QUEST_STATUS_COMPLETE)
                            DoAction(ACTION_TALK);
                    }

                    l_CheckTimer = 1500;
                }
                else
                    l_CheckTimer -= diff;
            }

            if (l_TalkRefill)
            {
                if (l_TalkRefill <= diff)
                {
                    hasSaid1 = false;
                    l_TalkRefill = 30000;
                }
                else
                    l_TalkRefill -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_wind_vehicle : public CreatureScript
{
public:
    npc_wind_vehicle() : CreatureScript("npc_wind_vehicle") { }

    struct npc_wind_vehicleAI : public npc_escortAI
    {
        npc_wind_vehicleAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint32 IntroTimer;

        void Reset() override
        {
            IntroTimer = 100;
        }

        void WaypointReached(uint32 waypointId) override
        {
            if (waypointId == 6)
            {
                if (me->GetVehicleKit())
                    me->GetVehicleKit()->RemoveAllPassengers();

                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wind_vehicleAI(creature);
    }

};

class AreaTrigger_at_wind_temple_entrance : public AreaTriggerScript
{
public:
    AreaTrigger_at_wind_temple_entrance() : AreaTriggerScript("AreaTrigger_at_wind_temple_entrance")
    {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
    {
        if (player->GetQuestStatus(29785) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* aysa = player->SummonCreature(55744, 665.60f, 4220.66f, 201.93f, 1.93f, TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                aysa->AI()->SetGUID(player->GetGUID());
        }

        return true;
    }
};

class mob_aysa_wind_temple_escort : public CreatureScript
{
public:
    mob_aysa_wind_temple_escort() : CreatureScript("mob_aysa_wind_temple_escort") { }

    struct mob_aysa_wind_temple_escortAI : public npc_escortAI
    {
        mob_aysa_wind_temple_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint32 IntroTimer;

        ObjectGuid playerGuid;

        void Reset() override
        {
            IntroTimer = 100;
            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(ObjectGuid guid, int32) override
        {
            playerGuid = guid;
        }

        void DoAction(int32 const /*param*/) override
        {
            SetEscortPaused(false);
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 1:
    //                SetEscortPaused(true);  <-- Who did this ? And why ?
    //                me->SetFacingTo(2.38f);
                    break;
                case 6:
    //                SetEscortPaused(true);  <-- Who did this ? And why ?
                    break;
                case 8:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                        player->KilledMonsterCredit(55666);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_aysa_wind_temple_escortAI(creature);
    }
};

class mob_frightened_wind : public CreatureScript
{
public:
    mob_frightened_wind() : CreatureScript("mob_frightened_wind") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_frightened_windAI(creature);
    }

    struct mob_frightened_windAI : public ScriptedAI
    {
        mob_frightened_windAI(Creature* creature) : ScriptedAI(creature)
        {}

        uint32 tornadeTimer;

        enum Spells
        {
            SPELL_TORNADE    = 107278,
        };

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            tornadeTimer = 8 * IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff) override
        {
            if (tornadeTimer <= diff)
            {
                if (!me->HasAura(SPELL_TORNADE))
                {
                    me->AddAura(SPELL_TORNADE, me);

                    std::list<Creature*> aysaList;
                    GetCreatureListWithEntryInGrid(aysaList, me, 55744, 35.0f);

                    for (auto aysa: aysaList)
                        aysa->AI()->DoAction(1);
                }
                else
                    me->RemoveAurasDueToSpell(SPELL_TORNADE);

                tornadeTimer = 8 * IN_MILLISECONDS;
            }
            else
                tornadeTimer -= diff;
        }
    };
};

class npc_aysa_in_wind_temple : public CreatureScript
{
public:
    npc_aysa_in_wind_temple() : CreatureScript("npc_aysa_in_wind_temple") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == 29786) // Bataille Pyrotechnique
        {
            if (Creature* aysa = player->SummonCreature(64543, 543.94f, 4317.31f, 212.24f, 1.675520f, TEMPSUMMON_TIMED_DESPAWN, 10000, true))
                aysa->GetMotionMaster()->MovePoint(1, 643.45f, 4228.66f, 202.90f);

            if (Creature* dafeng = player->SummonCreature(64532, 543.56f, 4320.97f, 212.24f, 5.445430f, TEMPSUMMON_TIMED_DESPAWN, 10000, true))
                dafeng->GetMotionMaster()->MovePoint(1, 643.45f, 4228.66f, 202.90f);
        }

        return true;
    }
};

enum Enums
{
    NPC_ROCKET_LAUNCHER = 64507,
    SPELL_ROCKET_LAUNCH = 104855,

    EVENT_NEXT_MOVEMENT = 1,
    EVENT_STUNNED       = 2,
    EVENT_LIGHTNING     = 3,

    SPELL_SERPENT_SWEEP = 125990,
    SPELL_STUNNED       = 125992,
    SPELL_LIGHTNING     = 126006,
};

Position ZhaoPos[] =
{
    {719.36f, 4164.60f, 216.06f}, // Center
    {745.91f, 4154.35f, 223.48f},
    {717.04f, 4141.16f, 219.83f},
    {689.62f, 4153.16f, 217.63f},
    {684.53f, 4173.24f, 216.98f},
    {704.77f, 4190.16f, 218.24f},
    {736.90f, 4183.85f, 221.41f}
};

class boss_zhao_ren : public CreatureScript
{
public:
    boss_zhao_ren() : CreatureScript("boss_zhao_ren") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_zhao_renAI(creature);
    }

    struct boss_zhao_renAI : public ScriptedAI
    {
        boss_zhao_renAI(Creature* creature) : ScriptedAI(creature)
        {}

        EventMap _events;
        bool eventStarted;
        uint8 hitCount;
        uint8 currentPos;

        void Reset() override
        {
            _events.Reset();
            me->SetReactState(REACT_PASSIVE);

            eventStarted = false;
            hitCount = 0;
            currentPos = 0;

            me->SetFullHealth();
            me->RemoveAurasDueToSpell(SPELL_STUNNED);

            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(0, ZhaoPos[0].GetPositionX(), ZhaoPos[0].GetPositionY(), ZhaoPos[0].GetPositionZ());
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_ROCKET_LAUNCH)
            {
                if (++hitCount >= 5)
                {
                    me->CastSpell(me, SPELL_STUNNED, true);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveFall();
                    _events.ScheduleEvent(EVENT_STUNNED, 12000);
                    hitCount = 0;
                }
            }
        }

        bool checkPlayers()
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 80.0f);

            for (auto player : playerList)
                if (player->GetQuestStatus(29786) == QUEST_STATUS_INCOMPLETE)
                    if (player->IsAlive())
                        return true;

            return false;
        }

        void GoToNextPos()
        {
            if (++currentPos > 6)
                currentPos = 1;

            me->GetMotionMaster()->MovePoint(currentPos, ZhaoPos[currentPos].GetPositionX(), ZhaoPos[currentPos].GetPositionY(), ZhaoPos[currentPos].GetPositionZ());
        }

        Player* GetRandomPlayer()
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 50.0f);

            if (playerList.empty())
                return NULL;

            Trinity::Containers::RandomResize(playerList, 1);

            return *playerList.begin();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (!id)
                return;

            _events.ScheduleEvent(EVENT_NEXT_MOVEMENT, 200);
        }

        void JustDied(Unit* /*attacker*/) override
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 50.0f);

            for (auto player : playerList)
                if (player->GetQuestStatus(29786) == QUEST_STATUS_INCOMPLETE)
                    if (player->IsAlive())
                        player->KilledMonsterCredit(me->GetEntry());
        }

        void UpdateAI(uint32 diff) override
        {
            if (checkPlayers())
            {
                if (!eventStarted)  // Event not started, player found
                {
                    _events.ScheduleEvent(EVENT_NEXT_MOVEMENT, 1000);
                    _events.ScheduleEvent(EVENT_LIGHTNING, 5000);
                    eventStarted = true;
                }
            }
            else
            {
                if (eventStarted)  // Event started, no player found
                    Reset();

                return;
            }

            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
            case EVENT_NEXT_MOVEMENT:
                {
                    if (me->HasAura(SPELL_STUNNED))
                        _events.ScheduleEvent(EVENT_NEXT_MOVEMENT, 2000);

                    GoToNextPos();
                    break;
                }
            case EVENT_STUNNED:
                {
                    me->RemoveAurasDueToSpell(SPELL_STUNNED);
                    me->CastSpell(me, SPELL_SERPENT_SWEEP, false);
                    _events.ScheduleEvent(EVENT_NEXT_MOVEMENT, 3000);
                    break;
                }
            case EVENT_LIGHTNING:
                {
                    if (Player* player = GetRandomPlayer())
                        me->CastSpell(player, SPELL_LIGHTNING, false);

                    _events.ScheduleEvent(EVENT_LIGHTNING, 5000);
                    break;
                }
            }
        }
    };
};

class npc_rocket_launcher : public CreatureScript
{
public:
    npc_rocket_launcher() : CreatureScript("npc_rocket_launcher") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rocket_launcherAI (creature);
    }

    struct npc_rocket_launcherAI : public ScriptedAI
    {
        npc_rocket_launcherAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 cooldown;

        void Reset() override
        {
            cooldown = 0;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* /*Clicker*/, bool& /*result*/) override
        {
            if (cooldown)
                return;

            if (Creature* zhao = GetClosestCreatureWithEntry(me, 55786, 50.0f))
                me->CastSpell(zhao, SPELL_ROCKET_LAUNCH, false);

            cooldown = 5000;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            return;
        }

        void UpdateAI(uint32 diff) override
        {
            if (cooldown)
            {
                if (cooldown <= diff)
                {
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    cooldown = 0;
                }
                else
                    cooldown -= diff;
            }
        }
    };
};

class mob_master_shang_xi_after_zhao : public CreatureScript
{
public:
    mob_master_shang_xi_after_zhao() : CreatureScript("mob_master_shang_xi_after_zhao") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 29787) // Digne de passer
            if (Creature* master = player->SummonCreature(56159, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                master->AI()->SetGUID(player->GetGUID());

        return true;
    }
};

class mob_master_shang_xi_after_zhao_escort : public CreatureScript
{
public:
    mob_master_shang_xi_after_zhao_escort() : CreatureScript("mob_master_shang_xi_after_zhao_escort") { }

    struct mob_master_shang_xi_after_zhao_escortAI : public npc_escortAI
    {
        mob_master_shang_xi_after_zhao_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint32 IntroTimer;

        ObjectGuid playerGuid;

        void Reset() override
        {
            IntroTimer = 250;
            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(ObjectGuid guid, int32) override
        {
            playerGuid = guid;
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
//             case 11:
//                 me->SummonCreature(56274, 845.89f, 4372.62f, 223.98f, 4.78f, TEMPSUMMON_CORPSE_DESPAWN, 0, playerGuid); // TODO : set template
//                 break;
                case 12:
                    me->SetFacingTo(0.0f);
                    SetEscortPaused(true);
                    break;
                case 17:
                    me->SetFacingTo(4.537860f);
                    me->DespawnOrUnsummon(1000);

                    if (Player* owner = ObjectAccessor::GetPlayer(*me, playerGuid))
                        owner->AddAura(59074, owner);
                    break;
                default:
                    break;
            }
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (summon->GetEntry() == 56274)
                SetEscortPaused(false);
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    Start(false, true);
                    IntroTimer = 0;
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_master_shang_xi_after_zhao_escortAI(creature);
    }
};

class mob_master_shang_xi_thousand_staff : public CreatureScript
{
public:
    mob_master_shang_xi_thousand_staff() : CreatureScript("mob_master_shang_xi_thousand_staff") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 29790) // Digne de passer
            if (Creature* master = player->SummonCreature(56686, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                master->AI()->SetGUID(player->GetGUID());

        return true;
    }
};

class mob_master_shang_xi_thousand_staff_escort : public CreatureScript
{
public:
    mob_master_shang_xi_thousand_staff_escort() : CreatureScript("mob_master_shang_xi_thousand_staff_escort") { }

    struct mob_master_shang_xi_thousand_staff_escortAI : public npc_escortAI
    {
        mob_master_shang_xi_thousand_staff_escortAI(Creature* creature) : npc_escortAI(creature)
        {}

        ObjectGuid playerGuid;

        void Reset() override
        {
            me->GetScheduler().Schedule(Milliseconds(250), [this](TaskContext /*context*/)
            {
                Start(false, true);
            });

            me->SetReactState(REACT_PASSIVE);
            SetRun(false);
        }

        void SetGUID(ObjectGuid guid, int32) override
        {
            playerGuid = guid;
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 4:
                    SetEscortPaused(true);
                    me->SetFacingTo(4.522332f);
                    TalkIn(0, 3000);
                    TalkIn(1, 10000);
                    TalkIn(2, 20000);
                    TalkIn(3, 30000);
                    TalkIn(4, 40000);
                    TalkIn(5, 50000);

                    me->GetScheduler().Schedule(Milliseconds(58000), [this](TaskContext /*context*/)
                    {
                        me->DespawnOrUnsummon();
                        me->SummonCreature(57874, 873.09f, 4462.25f, 241.27f, 3.80f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);

                        if (Player* owner = ObjectAccessor::GetPlayer(*me, playerGuid))
                            owner->KilledMonsterCredit(56688);
                    });

                    break;
                default:
                    break;
            }
        }

        void TalkIn(uint32 talkId, uint32 talkTimer)
        {
            me->GetScheduler().Schedule(Milliseconds(talkTimer), [this, talkId](TaskContext /*context*/)
            {
                Talk(talkId);
            });
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_master_shang_xi_thousand_staff_escortAI(creature);
    }
};

class mob_shang_xi_air_balloon : public VehicleScript
{
public:
    mob_shang_xi_air_balloon() : VehicleScript("mob_shang_xi_air_balloon") { }

    void OnAddPassenger(Vehicle* /*veh*/, Unit* passenger, int8 seatId) override
    {
        if (seatId == 1)
            if (Player* player = passenger->ToPlayer())
                player->KilledMonsterCredit(56378);
    }

    struct mob_shang_xi_air_balloonAI : public npc_escortAI
    {
        mob_shang_xi_air_balloonAI(Creature* creature) : npc_escortAI(creature)
        {}

        uint32 IntroTimer;

        void Reset() override
        {
            IntroTimer = 250;
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
            {
                case 19:
                    if (me->GetVehicleKit())
                    {
                        if (Unit* passenger = me->GetVehicleKit()->GetPassenger(1))
                            if (Player* player = passenger->ToPlayer())
                            {
                                player->KilledMonsterCredit(55939);
                                player->AddAura(50550, player);
                            }

                            me->GetVehicleKit()->RemoveAllPassengers();
                    }

                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (IntroTimer)
            {
                if (IntroTimer <= diff)
                {
                    if (me->GetVehicleKit())
                    {
                        if (me->GetVehicleKit()->GetPassenger(1))
                        {
                            Start(false, true);
                            IntroTimer = 0;
                        }
                    }
                }
                else
                    IntroTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_shang_xi_air_balloonAI(creature);
    }
};

class npc_ji_firepaw : public CreatureScript
{
public:
    npc_ji_firepaw() : CreatureScript("npc_ji_firepaw")
    {
        IsSummoned = false;
    }

    bool IsSummoned;

    void SummonHiFirepawHelper(Player* summoner, uint32 entry)
    {
        uint32 phase = summoner->GetPhaseMask();
        Position pos = summoner->GetPosition();

        Guardian* summon = new Guardian(NULL, summoner, false);

        if (!summon->Create(summoner->GetMap()->GenerateLowGuid<HighGuid::Creature>(), summoner->GetMap(), phase, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation()))
        {
            delete summon;
            return;
        }

        summon->SetHomePosition(pos);
        summon->InitStats(0);
        summoner->GetMap()->AddToMap(summon->ToCreature());
        summon->InitSummon();
        summon->InitStatsForLevel(10);
        summon->SetFollowAngle(summoner->GetAngle(summon));
        summon->SetReactState(REACT_AGGRESSIVE);
    }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        std::list<Creature*> summonList;
        GetCreatureListWithEntryInGrid(summonList, player, 59960, 6.0f);

        IsSummoned = summonList.size() != 0;

        if (IsSummoned == false &&
            (quest->GetQuestId() == 29779 ||
             quest->GetQuestId() == 29780 ||
             quest->GetQuestId() == 29781))
        {
            SummonHiFirepawHelper(player, 59960);
            IsSummoned = true;
        }

        return true;
    }
};

class npc_ji_firepaw_escort : public CreatureScript
{
public:
    npc_ji_firepaw_escort() : CreatureScript("npc_ji_firepaw_escort") { }

    struct npc_ji_firepaw_escortAI : public ScriptedAI
    {
        npc_ji_firepaw_escortAI(Creature* creature) : ScriptedAI(creature) { }

        ObjectGuid playerGuid;

        void IsSummonedBy(Unit* summoner) override
        {
            playerGuid = summoner->GetGUID();
            me->GetMotionMaster()->MoveFollow(summoner, 1.0f, 1.0f, MOTION_SLOT_ACTIVE);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            Player* summoner = ObjectAccessor::GetPlayer(*me, playerGuid);
            if (!summoner)
                return;

            if (Unit* target = summoner->GetVictim())
            {
                me->Attack(target, true);
                DoMeleeAttackIfReady();
                return;
            }

            if ((summoner->GetQuestStatus(29780) == QUEST_STATUS_COMPLETE || summoner->GetQuestStatus(29780) == QUEST_STATUS_REWARDED) && (summoner->GetQuestStatus(29779) == QUEST_STATUS_COMPLETE
                || summoner->GetQuestStatus(29779) == QUEST_STATUS_REWARDED) && (summoner->GetQuestStatus(29781) == QUEST_STATUS_COMPLETE || summoner->GetQuestStatus(29781) == QUEST_STATUS_REWARDED))
                me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ji_firepaw_escortAI(creature);
    }
};

class mob_guardian_of_the_elders : public CreatureScript
{
    public:
        mob_guardian_of_the_elders() : CreatureScript("mob_guardian_of_the_elders") { }

        struct mob_guardian_of_the_eldersAI : public ScriptedAI
        {
            mob_guardian_of_the_eldersAI(Creature* creature) : ScriptedAI(creature)
            {
                playerGUID = ObjectGuid::Empty;
            }

            ObjectGuid playerGUID;

            void JustDied(Unit* p_Killer) override
            {
                if (p_Killer->GetTypeId() != TYPEID_PLAYER)
                    return;

                std::list<GameObject*> l_GobList;
                GetGameObjectListWithEntryInGrid(l_GobList, me, 209922, 20.0f);

                for (GameObject* l_Gob : l_GobList)
                    l_Gob->UseDoorOrButton(me->GetRespawnTime());
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_guardian_of_the_eldersAI(creature);
        }
};

class gob_defaced_scroll_of_wisdom : public GameObjectScript
{
public:
    gob_defaced_scroll_of_wisdom() : GameObjectScript("gob_defaced_scroll_of_wisdom")
    {
    }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(29778) == QUEST_STATUS_INCOMPLETE)
            player->KilledMonsterCredit(55600);

        go->DestroyForPlayer(player);
        return true;
    }
};

class mob_shang_xi_second_air_balloon : public VehicleScript
{
public:
    mob_shang_xi_second_air_balloon() : VehicleScript("mob_shang_xi_second_air_balloon") { }

    void OnAddPassenger(Vehicle* /*veh*/, Unit* passenger, int8 seatId) override
    {
        if (seatId == -1)
            if (Player* player = passenger->ToPlayer())
            {
                player->ExitVehicle();

                if (Creature* balloon = player->SummonCreature(55649, 915.55f, 4563.66f, 230.68f, 2.298090f, TEMPSUMMON_MANUAL_DESPAWN, 0, true))
                    player->EnterVehicle(balloon, 1);
            }
    }
};

void AddSC_WanderingIsland_West()
{
    new mob_guardian_of_the_elders();
    new mob_master_shang_xi_temple();
    new npc_wind_vehicle();
    new AreaTrigger_at_wind_temple_entrance();
    new mob_aysa_wind_temple_escort();
    new mob_frightened_wind();
    new npc_aysa_in_wind_temple();
    new boss_zhao_ren();
    new npc_rocket_launcher();
    new mob_master_shang_xi_after_zhao();
    new mob_master_shang_xi_after_zhao_escort();
    new mob_master_shang_xi_thousand_staff();
    new mob_master_shang_xi_thousand_staff_escort();
    new mob_shang_xi_air_balloon();
    new npc_ji_firepaw();
    new npc_ji_firepaw_escort();
    new gob_defaced_scroll_of_wisdom();
    new mob_shang_xi_second_air_balloon();
}
