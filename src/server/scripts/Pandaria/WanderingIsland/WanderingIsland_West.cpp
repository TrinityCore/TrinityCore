#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"

#define GOSSIP_WIND     "I would like to go back on the top of the temple"
#define ACTION_TALK 1
class mob_master_shang_xi_temple : public CreatureScript
{
public:
    mob_master_shang_xi_temple() : CreatureScript("mob_master_shang_xi_temple") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
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

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(29776) != QUEST_STATUS_NONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_WIND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            /* The vehicle bug for now on TaranZhu, too much lags
            if (Creature* vehicle = player->SummonCreature(55685, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation()))
            {
            player->AddAura(99385, vehicle);
            player->EnterVehicle(vehicle);
            }*/

            player->NearTeleportTo(943.52f, 3619.68f, 252.34f, 1.476f);
        }

        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_master_shang_xi_templeAI(creature);
    }

    struct mob_master_shang_xi_templeAI : public ScriptedAI
    {
        mob_master_shang_xi_templeAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        bool hasSaid1;

        void Reset()
        {
            hasSaid1 = false;
        }

        void DoAction (uint8 action)
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

        void UpdateAI(const uint32 diff)
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 7.0f);
            for (auto player: playerList)
            {
                if (player->GetQuestStatus(29423) == QUEST_STATUS_COMPLETE)
                {
                    DoAction(ACTION_TALK);
                }
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

        void Reset()
        {
            IntroTimer = 100;
        }

        void WaypointReached(uint32 waypointId)
        {
            if (waypointId == 9)
            {
                if (me->GetVehicleKit())
                    me->GetVehicleKit()->RemoveAllPassengers();

                me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(const uint32 diff)
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
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_wind_vehicleAI(creature);
    }
    
};

class AreaTrigger_at_wind_temple_entrance : public AreaTriggerScript
{
public:
    AreaTrigger_at_wind_temple_entrance() : AreaTriggerScript("AreaTrigger_at_wind_temple_entrance")
    {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
    {
        if (player->GetQuestStatus(29785) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* aysa = player->SummonCreature(55744, 665.60f, 4220.66f, 201.93f, 1.93f, TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
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

        uint64 playerGuid;

        void Reset()
        {
            IntroTimer = 100;
            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(uint64 guid, int32)
        {
            playerGuid = guid;
        }

        void DoAction(int32 const /*param*/)
        {
            SetEscortPaused(false);
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 1:
                    SetEscortPaused(true);
                    me->SetFacingTo(2.38f);
                    break;
                case 6:
                    SetEscortPaused(true);
                    break;
                case 8:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                        player->KilledMonsterCredit(55666);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
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
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_aysa_wind_temple_escortAI(creature);
    }
};

class mob_frightened_wind : public CreatureScript
{
public:
    mob_frightened_wind() : CreatureScript("mob_frightened_wind") { }

    CreatureAI* GetAI(Creature* creature) const
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

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            tornadeTimer = 8 * IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (tornadeTimer <= diff)
            {
                me->ToggleAura(SPELL_TORNADE, me);

                if (!me->HasAura(SPELL_TORNADE))
                {
                    std::list<Creature*> aysaList;
                    GetCreatureListWithEntryInGrid(aysaList, me, 55744, 35.0f);

                    for (auto aysa: aysaList)
                        aysa->AI()->DoAction(1);
                }
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

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == 29786) // Bataille Pyrotechnique
        {
            if (Creature* aysa = player->SummonCreature(64543, 543.94f, 4317.31f, 212.24f, 1.675520f, TEMPSUMMON_TIMED_DESPAWN, 10000, player->GetGUID()))
                aysa->GetMotionMaster()->MovePoint(1, 643.45f, 4228.66f, 202.90f);

            if (Creature* dafeng = player->SummonCreature(64532, 543.56f, 4320.97f, 212.24f, 5.445430f, TEMPSUMMON_TIMED_DESPAWN, 10000, player->GetGUID()))
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

    CreatureAI* GetAI(Creature* creature) const
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

        void Reset()
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

        void SpellHit(Unit* caster, const SpellInfo* spell)
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

            MoPCore::Containers::RandomResizeList(playerList, 1);

            return *playerList.begin();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (!id)
                return;

            _events.ScheduleEvent(EVENT_NEXT_MOVEMENT, 200);
        }

        void JustDied(Unit* attacker)
        {
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 50.0f);

            for (auto player : playerList)
                if (player->GetQuestStatus(29786) == QUEST_STATUS_INCOMPLETE)
                    if (player->IsAlive())
                        player->KilledMonsterCredit(me->GetEntry());
        }

        void UpdateAI(const uint32 diff)
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_rocket_launcherAI (creature);
    }

    struct npc_rocket_launcherAI : public ScriptedAI
    {
        npc_rocket_launcherAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 cooldown;

        void Reset()
        {
            cooldown = 0;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* Clicker)
        {
            if (cooldown)
                return;

            if (Creature* zhao = GetClosestCreatureWithEntry(me, 55786, 50.0f))
                me->CastSpell(zhao, SPELL_ROCKET_LAUNCH, false);

            cooldown = 5000;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void EnterCombat(Unit* /*who*/)
        {
            return;
        }

        void UpdateAI(const uint32 diff)
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

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == 29787) // Digne de passer
            if (Creature* master = player->SummonCreature(56159, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
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

        uint64 playerGuid;

        void Reset()
        {
            IntroTimer = 250;
            me->SetReactState(REACT_PASSIVE);
        }

        void SetGUID(uint64 guid, int32)
        {
            playerGuid = guid;
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 6:
                    me->SummonCreature(56274, 845.89f, 4372.62f, 223.98f, 4.78f, TEMPSUMMON_CORPSE_DESPAWN, 0, playerGuid);
                    break;
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

        void SummonedCreatureDespawn(Creature* summon)
        {
            if (summon->GetEntry() == 56274)
                SetEscortPaused(false);
        }

        void UpdateAI(const uint32 diff)
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
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_master_shang_xi_after_zhao_escortAI(creature);
    }
};

class mob_master_shang_xi_thousand_staff : public CreatureScript
{
public:
    mob_master_shang_xi_thousand_staff() : CreatureScript("mob_master_shang_xi_thousand_staff") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == 29790) // Digne de passer
            if (Creature* master = player->SummonCreature(56686, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0, player->GetGUID()))
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
        
        uint32 IntroTimer;
        uint32 DespawnTimer;

        uint64 playerGuid;

        void Reset()
        {
            IntroTimer = 250;
            DespawnTimer = 0;
            me->SetReactState(REACT_PASSIVE);
            SetRun(false);
        }

        void SetGUID(uint64 guid, int32)
        {
            playerGuid = guid;
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 4:
                    SetEscortPaused(true);
                    me->SetFacingTo(4.522332f);
                    DespawnTimer = 3000;
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
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

            if (DespawnTimer)
            {
                if (DespawnTimer <= diff)
                {
                    me->DespawnOrUnsummon();
                    me->SummonCreature(57874, 873.09f, 4462.25f, 241.27f, 3.80f, TEMPSUMMON_MANUAL_DESPAWN, 0, playerGuid);

                    if (Player* owner = ObjectAccessor::GetPlayer(*me, playerGuid))
                        owner->KilledMonsterCredit(56688);

                    DespawnTimer = 0;
                }
                else
                    DespawnTimer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_master_shang_xi_thousand_staff_escortAI(creature);
    }
};

// Grab Air Balloon - 95247
class spell_grab_air_balloon: public SpellScriptLoader
{
public:
    spell_grab_air_balloon() : SpellScriptLoader("spell_grab_air_balloon") { }

    class spell_grab_air_balloon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_grab_air_balloon_SpellScript);

        void HandleScriptEffect(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            if (Unit* caster = GetCaster())
                if (Creature* balloon = caster->SummonCreature(55649, 915.55f, 4563.66f, 230.68f, 2.298090f, TEMPSUMMON_MANUAL_DESPAWN, 0))
                    caster->EnterVehicle(balloon, 0);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_grab_air_balloon_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_grab_air_balloon_SpellScript();
    }
};

class mob_shang_xi_air_balloon : public VehicleScript
{
    public:
        mob_shang_xi_air_balloon() : VehicleScript("mob_shang_xi_air_balloon") { }

    void OnAddPassenger(Vehicle* /*veh*/, Unit* passenger, int8 seatId)
    {
        if (seatId == 0)
            if (Player* player = passenger->ToPlayer())
                player->KilledMonsterCredit(56378);
    }

    struct mob_shang_xi_air_balloonAI : public npc_escortAI
    {        
        mob_shang_xi_air_balloonAI(Creature* creature) : npc_escortAI(creature)
        {}
        
        uint32 IntroTimer;

        void Reset()
        {
            IntroTimer = 250;
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 55:
                    if (me->GetVehicleKit())
                    {
                        if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
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

        void UpdateAI(const uint32 diff)
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
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_shang_xi_air_balloonAI(creature);
    }
};

class spell_monkey_wisdom : public SpellScriptLoader
{
public:
    spell_monkey_wisdom() : SpellScriptLoader("spell_monkey_wisdom") {}

    class spell_monkey_wisdom_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monkey_wisdom_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            uint8 text = urand(0, 8);
            if (text == 0)
                GetHitUnit()->MonsterTextEmote("Peel banana first, eat second.", GetHitUnit()->GetGUID(), true);
            if (text == 1)
                GetHitUnit()->MonsterTextEmote("Wet fur not fun to sleep on.", GetHitUnit()->GetGUID(), true);
            if (text == 2)
                GetHitUnit()->MonsterTextEmote("Don't roll in own poo unless you want to smell like poo all day.", GetHitUnit()->GetGUID(), true);
            if (text == 3)
                GetHitUnit()->MonsterTextEmote("Steal a banana from a hozen, expect an angry hozen.", GetHitUnit()->GetGUID(), true);
            if (text == 4)
                GetHitUnit()->MonsterTextEmote("Poo not good to eat, but very good to throw.", GetHitUnit()->GetGUID(), true);
            if (text == 5)
                GetHitUnit()->MonsterTextEmote("Mouth only hole that banana go in.", GetHitUnit()->GetGUID(), true);
            if (text == 6)
                GetHitUnit()->MonsterTextEmote("Don't throw banana peel where going to walk.", GetHitUnit()->GetGUID(), true);
            if (text == 7)
                GetHitUnit()->MonsterTextEmote("Firecracker for throwing, banana for eating.", GetHitUnit()->GetGUID(), true);
            if (text == 8)
                GetHitUnit()->MonsterTextEmote("Don't pull own tail when there are other tails to pull.", GetHitUnit()->GetGUID(), true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_monkey_wisdom_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_KILL_CREDIT2);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monkey_wisdom_SpellScript();
    }
};

class npc_ji_firepaw : public CreatureScript
{
public:
    npc_ji_firepaw() : CreatureScript("npc_ji_firepaw")
    {
        isSummoned = false;
    }

    bool isSummoned;

    void SummonHiFirepawHelper(Player* summoner, uint32 entry)
    {
        uint32 phase = summoner->GetPhaseMask();
        uint32 team = summoner->GetTeam();
        Position pos;

        summoner->GetPosition(&pos);

        Guardian* summon = new Guardian(NULL, summoner, false);

        if (!summon->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), summoner->GetMap(), phase, entry, 0, team, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation()))
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

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        std::list<Creature*> summonList;
        GetCreatureListWithEntryInGrid(summonList, player, 59960, 6.0f);

        for (auto summoned: summonList)
            isSummoned = true;

        if (isSummoned == false)
        {
            if (quest->GetQuestId() == 29779)
            {
                SummonHiFirepawHelper(player, 59960);
                isSummoned = true;
            }

            if (quest->GetQuestId() == 29780)
            {
                SummonHiFirepawHelper(player, 59960);
                isSummoned = true;
            }

            if (quest->GetQuestId() == 29781)
            {
                SummonHiFirepawHelper(player, 59960);
                isSummoned = true;
            }
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
        npc_ji_firepaw_escortAI(Creature* creature) : ScriptedAI(creature)
        {
            playerGuid = 0;
        }

        uint64 playerGuid;

        void IsSummonedBy(Unit* summoner)
        {
            playerGuid = summoner->GetGUID();
            me->GetMotionMaster()->MoveFollow(summoner, 1.0f, 1.0f, MOTION_SLOT_ACTIVE);
        }

        void UpdateAI(const uint32 diff)
        {
            Player* summoner = sObjectAccessor->FindPlayer(playerGuid);
            if (!summoner)
                return;

            if (Unit* target = summoner->getVictim())
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ji_firepaw_escortAI(creature);
    }
};

void AddSC_WanderingIsland_West()
{
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
    new spell_grab_air_balloon();
    new mob_shang_xi_air_balloon();
    new npc_ji_firepaw();
    new npc_ji_firepaw_escort();
    new spell_monkey_wisdom();
}
