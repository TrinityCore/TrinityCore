/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "CombatAI.h"
#include "Player.h"
#include "WorldSession.h"

/////////////////////
///npc_injured_goblin
/////////////////////

enum InjuredGoblinMiner
{
    QUEST_BITTER_DEPARTURE     = 12832,
    SAY_QUEST_ACCEPT           = 0,
    SAY_END_WP_REACHED         = 1,
    GOSSIP_ID                  = 9859,
    GOSSIP_OPTION_ID           = 0
};

class npc_injured_goblin : public CreatureScript
{
public:
    npc_injured_goblin() : CreatureScript("npc_injured_goblin") { }

    struct npc_injured_goblinAI : public npc_escortAI
    {
        npc_injured_goblinAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 26:
                    Talk(SAY_END_WP_REACHED, player->GetGUID());
                    break;
                case 27:
                    player->GroupEventHappens(QUEST_BITTER_DEPARTURE, me);
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void Reset() OVERRIDE { }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (HasEscortState(STATE_ESCORT_ESCORTING) && player)
                player->FailQuest(QUEST_BITTER_DEPARTURE);
        }

       void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            npc_escortAI::UpdateAI(uiDiff);
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }

        void sGossipSelect(Player* player, uint32 sender, uint32 action) OVERRIDE
        {
            if (sender == GOSSIP_ID && action == GOSSIP_OPTION_ID)
            {
                player->CLOSE_GOSSIP_MENU();
                me->setFaction(113);
                npc_escortAI::Start(true, true, player->GetGUID());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_injured_goblinAI(creature);
    }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_BITTER_DEPARTURE)
            creature->AI()->Talk(SAY_QUEST_ACCEPT);

        return false;
    }
};

/*######
## npc_roxi_ramrocket
######*/

enum RoxiRamrocket
{
    SPELL_MECHANO_HOG               = 60866,
    SPELL_MEKGINEERS_CHOPPER        = 60867
};

class npc_roxi_ramrocket : public CreatureScript
{
public:
    npc_roxi_ramrocket() : CreatureScript("npc_roxi_ramrocket") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        //Quest Menu
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        //Trainer Menu
        if ( creature->IsTrainer() )
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        //Vendor Menu
        if ( creature->IsVendor() )
            if (player->HasSpell(SPELL_MECHANO_HOG) || player->HasSpell(SPELL_MEKGINEERS_CHOPPER))
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
        case GOSSIP_ACTION_TRAIN:
            player->GetSession()->SendTrainerList(creature->GetGUID());
            break;
        case GOSSIP_ACTION_TRADE:
            player->GetSession()->SendListInventory(creature->GetGUID());
            break;
        }
        return true;
    }
};

/*######
## npc_brunnhildar_prisoner
######*/

enum BrunnhildarPrisoner {
    SPELL_ICE_PRISON           = 54894,
    SPELL_ICE_LANCE            = 55046,
    SPELL_FREE_PRISONER        = 55048,
    SPELL_RIDE_DRAKE           = 55074,
    SPELL_SHARD_IMPACT         = 55047
};

class npc_brunnhildar_prisoner : public CreatureScript
{
public:
    npc_brunnhildar_prisoner() : CreatureScript("npc_brunnhildar_prisoner") { }

    struct npc_brunnhildar_prisonerAI : public ScriptedAI
    {
        npc_brunnhildar_prisonerAI(Creature* creature) : ScriptedAI(creature) { }

        bool freed;

        void Reset() OVERRIDE
        {
            freed = false;
            me->CastSpell(me, SPELL_ICE_PRISON, true);
        }

        void JustRespawned() OVERRIDE
        {
            Reset();
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            if (!freed)
                return;

            if (!me->GetVehicle())
                me->DespawnOrUnsummon();
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) OVERRIDE
        {
            if (spell->Id != SPELL_ICE_LANCE)
                return;

            if (caster->GetVehicleKit()->GetAvailableSeatCount() != 0)
            {
                me->CastSpell(me, SPELL_FREE_PRISONER, true);
                me->CastSpell(caster, SPELL_RIDE_DRAKE, true);
                me->CastSpell(me, SPELL_SHARD_IMPACT, true);
                freed = true;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_brunnhildar_prisonerAI(creature);
    }
};

/*######
## npc_freed_protodrake
######*/

enum FreedProtoDrake
{
    NPC_DRAKE                           = 29709,

    AREA_VALLEY_OF_ANCIENT_WINTERS      = 4437,

    TEXT_EMOTE                          = 0,

    SPELL_KILL_CREDIT_PRISONER          = 55144,
    SPELL_SUMMON_LIBERATED              = 55073,
    SPELL_KILL_CREDIT_DRAKE             = 55143,

    EVENT_CHECK_AREA                    = 1,
    EVENT_REACHED_HOME                  = 2,
};

class npc_freed_protodrake : public CreatureScript
{
public:
    npc_freed_protodrake() : CreatureScript("npc_freed_protodrake") { }

    struct npc_freed_protodrakeAI : public VehicleAI
    {
        npc_freed_protodrakeAI(Creature* creature) : VehicleAI(creature) { }

        EventMap events;

        void Reset() OVERRIDE
        {
            events.ScheduleEvent(EVENT_CHECK_AREA, 5000);
        }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            if (type != WAYPOINT_MOTION_TYPE)
                return;

            if (id == 15)
            // drake reached village
            events.ScheduleEvent(EVENT_REACHED_HOME, 2000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_CHECK_AREA:
                    if (me->GetAreaId() == AREA_VALLEY_OF_ANCIENT_WINTERS)
                    {
                        if (Vehicle* vehicle = me->GetVehicleKit())
                            if (Unit* passenger = vehicle->GetPassenger(0))
                            {
                                Talk(TEXT_EMOTE, passenger->GetGUID());
                                me->GetMotionMaster()->MovePath(NPC_DRAKE, false);
                            }
                    }
                    else
                        events.ScheduleEvent(EVENT_CHECK_AREA, 5000);
                    break;
                case EVENT_REACHED_HOME:
                    Unit* player = me->GetVehicleKit()->GetPassenger(0);
                    if (player && player->GetTypeId() == TYPEID_PLAYER)
                    {
                        // for each prisoner on drake, give credit
                        for (uint8 i = 1; i < 4; ++i)
                            if (Unit* prisoner = me->GetVehicleKit()->GetPassenger(i))
                            {
                                if (prisoner->GetTypeId() != TYPEID_UNIT)
                                    return;
                                prisoner->CastSpell(player, SPELL_KILL_CREDIT_PRISONER, true);
                                prisoner->CastSpell(prisoner, SPELL_SUMMON_LIBERATED, true);
                                prisoner->ExitVehicle();
                            }
                        me->CastSpell(me, SPELL_KILL_CREDIT_DRAKE, true);
                        player->ExitVehicle();
                    }
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_freed_protodrakeAI(creature);
    }
};

class npc_icefang : public CreatureScript
{
public:
    npc_icefang() : CreatureScript("npc_icefang") { }

    struct npc_icefangAI : public npc_escortAI
    {
        npc_icefangAI(Creature* creature) : npc_escortAI(creature) { }

        void AttackStart(Unit* /*who*/) OVERRIDE { }
        void EnterCombat(Unit* /*who*/) OVERRIDE { }
        void EnterEvadeMode() OVERRIDE { }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (apply)
                    Start(false, true, who->GetGUID());
            }
        }

        void WaypointReached(uint32 /*waypointId*/) OVERRIDE
        {
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
        }

        void OnCharmed(bool /*apply*/) OVERRIDE
        {
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_icefangAI(creature);
    }
};

class npc_hyldsmeet_protodrake : public CreatureScript
{
    enum NPCs
    {
        NPC_HYLDSMEET_DRAKERIDER = 29694
    };

    public:
        npc_hyldsmeet_protodrake() : CreatureScript("npc_hyldsmeet_protodrake") { }

        class npc_hyldsmeet_protodrakeAI : public CreatureAI
        {
            public:
                npc_hyldsmeet_protodrakeAI(Creature* creature) : CreatureAI(creature), _accessoryRespawnTimer(0), _vehicleKit(creature->GetVehicleKit()) { }

                void PassengerBoarded(Unit* who, int8 /*seat*/, bool apply) OVERRIDE
                {
                    if (apply)
                        return;

                    if (who->GetEntry() == NPC_HYLDSMEET_DRAKERIDER)
                        _accessoryRespawnTimer = 5 * MINUTE * IN_MILLISECONDS;
                }

                void UpdateAI(uint32 diff) OVERRIDE
                {
                    //! We need to manually reinstall accessories because the vehicle itself is friendly to players,
                    //! so EnterEvadeMode is never triggered. The accessory on the other hand is hostile and killable.
                    if (_accessoryRespawnTimer && _accessoryRespawnTimer <= diff && _vehicleKit)
                    {
                        _vehicleKit->InstallAllAccessories(true);
                        _accessoryRespawnTimer = 0;
                    }
                    else
                        _accessoryRespawnTimer -= diff;
                }

            private:
                uint32 _accessoryRespawnTimer;
                Vehicle* _vehicleKit;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_hyldsmeet_protodrakeAI(creature);
        }
};


/*#####
# npc_brann_bronzebeard for Quest 13285 "Forging the Keystone"
#####*/

enum BrannBronzebeard
{
    NPC_BRANN_BRONZEBEARD = 31810,
    NPC_A_DISTANT_VOICE   = 31814,
    OBJECT_TOL_SIGNAL_1   = 193590,
    OBJECT_TOL_SIGNAL_2   = 193591,
    OBJECT_TOL_SIGNAL_3   = 193592,
    OBJECT_TOL_SIGNAL_4   = 193593,
    OBJECT_TOL_SIGNAL_5   = 193594,
    SPELL_RESURRECTION    = 58854,
    SAY_BRANN_1           = 0,
    SAY_BRANN_2           = 1,
    SAY_BRANN_3           = 2,
    SAY_VOICE_1           = 0,
    SAY_VOICE_2           = 1,
    SAY_VOICE_3           = 2,
    SAY_VOICE_4           = 3,
    SAY_VOICE_5           = 4,

    EVENT_SCRIPT_1        = 1,
    EVENT_SCRIPT_2        = 2,
    EVENT_SCRIPT_3        = 3,
    EVENT_SCRIPT_4        = 4,
    EVENT_SCRIPT_5        = 5,
    EVENT_SCRIPT_6        = 6,
    EVENT_SCRIPT_7        = 7,
    EVENT_SCRIPT_8        = 8,
    EVENT_SCRIPT_9        = 9,
    EVENT_SCRIPT_10       = 10,
    EVENT_SCRIPT_11       = 11,
    EVENT_SCRIPT_12       = 12,
    EVENT_SCRIPT_13       = 13
};

class npc_brann_bronzebeard : public CreatureScript
{
public:
    npc_brann_bronzebeard() : CreatureScript("npc_brann_bronzebeard") { }

    struct npc_brann_bronzebeardAI : public ScriptedAI
    {
        npc_brann_bronzebeardAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE
        {
            memset(&objectGUID, 0, sizeof(objectGUID));
            playerGUID = 0;
            voiceGUID  = 0;
            objectCounter = 0;
        }

        void sGossipSelect(Player* player, uint32 /*sender*/, uint32 /*action*/) OVERRIDE
        {
            player->CLOSE_GOSSIP_MENU();
            playerGUID = player->GetGUID();
            events.ScheduleEvent(EVENT_SCRIPT_1, 100);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SCRIPT_1:
                        Talk(SAY_BRANN_1, playerGUID);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        if (Creature* voice = me->SummonCreature(NPC_A_DISTANT_VOICE, 7863.43f, -1396.585f, 1538.076f, 2.949606f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 49000))
                            voiceGUID = voice->GetGUID();
                        events.ScheduleEvent(EVENT_SCRIPT_2, 4000);
                        break;
                    case EVENT_SCRIPT_2:
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, 7861.488f, -1396.376f, 1534.059f, false);
                        events.ScheduleEvent(EVENT_SCRIPT_3, 6000);
                        break;
                    case EVENT_SCRIPT_3:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_WORK_MINING);
                        events.ScheduleEvent(EVENT_SCRIPT_4, 6000);
                        break;
                    case EVENT_SCRIPT_4:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        if (Creature* voice = ObjectAccessor::GetCreature(*me, voiceGUID))
                        {
                            voice->AI()->DoCast(voice, SPELL_RESURRECTION);
                            voice->AI()->Talk(SAY_VOICE_1, playerGUID);
                        }
                        if (GameObject* go = me->SummonGameObject(OBJECT_TOL_SIGNAL_1, 7860.273f, -1383.622f, 1538.302f, -1.658062f, 0, 0,  -0.737277f, 0.6755905f, 0))
                            objectGUID[objectCounter++] = go->GetGUID();
                        events.ScheduleEvent(EVENT_SCRIPT_5, 6000);
                        break;
                    case EVENT_SCRIPT_5:
                        if (Creature* voice = ObjectAccessor::GetCreature(*me, voiceGUID))
                            voice->AI()->Talk(SAY_VOICE_2, playerGUID);
                        if (GameObject* go = me->SummonGameObject(OBJECT_TOL_SIGNAL_2, 7875.67f, -1387.266f, 1538.323f, -2.373644f, 0, 0,  -0.9271832f, 0.3746083f, 0))
                            objectGUID[objectCounter++] = go->GetGUID();
                        events.ScheduleEvent(EVENT_SCRIPT_6, 6000);
                        break;
                    case EVENT_SCRIPT_6:
                        if (Creature* voice = ObjectAccessor::GetCreature(*me, voiceGUID))
                            voice->AI()->Talk(SAY_VOICE_3, playerGUID);
                        if (GameObject* go = me->SummonGameObject(OBJECT_TOL_SIGNAL_3, 7879.212f, -1401.175f, 1538.279f, 2.967041f, 0, 0,  0.9961939f, 0.08716504f, 0))
                            objectGUID[objectCounter++] = go->GetGUID();
                        events.ScheduleEvent(EVENT_SCRIPT_7, 6000);
                        break;
                    case EVENT_SCRIPT_7:
                        if (Creature* voice = ObjectAccessor::GetCreature(*me, voiceGUID))
                            voice->AI()->Talk(SAY_VOICE_4, playerGUID);
                        if (GameObject* go = me->SummonGameObject(OBJECT_TOL_SIGNAL_4, 7868.944f, -1411.18f, 1538.213f, 2.111848f, 0, 0,  0.8703556f, 0.4924237f, 0))
                            objectGUID[objectCounter++] = go->GetGUID();
                        events.ScheduleEvent(EVENT_SCRIPT_8, 6000);
                        break;
                    case EVENT_SCRIPT_8:
                        if (Creature* voice = ObjectAccessor::GetCreature(*me, voiceGUID))
                            voice->AI()->Talk(SAY_VOICE_5, playerGUID);
                        if (GameObject* go = me->SummonGameObject(OBJECT_TOL_SIGNAL_5, 7855.11f, -1406.839f, 1538.42f, 1.151916f, 0, 0,  0.5446386f, 0.8386708f, 0))
                            objectGUID[objectCounter] = go->GetGUID();
                        events.ScheduleEvent(EVENT_SCRIPT_9, 6000);
                        break;
                    case EVENT_SCRIPT_9:
                        if (Creature* voice = ObjectAccessor::GetCreature(*me, voiceGUID))
                            voice->AI()->DoCast(voice, SPELL_RESURRECTION);
                        events.ScheduleEvent(EVENT_SCRIPT_10, 6000);
                        break;
                    case EVENT_SCRIPT_10:
                        Talk(SAY_BRANN_2, playerGUID);
                        if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                            player->KilledMonsterCredit(me->GetEntry());
                        events.ScheduleEvent(EVENT_SCRIPT_11, 6000);
                        break;
                    case EVENT_SCRIPT_11:
                        me->SetOrientation(2.932153f);
                        me->SendMovementFlagUpdate(true);
                        Talk(SAY_BRANN_3, playerGUID);
                        for (uint8 i = 0; i < 5; ++i)
                        {
                            if (GameObject* go = ObjectAccessor::GetGameObject(*me, objectGUID[i]))
                                go->Delete();
                        }
                        events.ScheduleEvent(EVENT_SCRIPT_12, 6000);
                        break;
                    case EVENT_SCRIPT_12:
                        me->GetMotionMaster()->Clear();
                        me->SetWalk(false);
                        me->GetMotionMaster()->MovePoint(0, 7799.908f, -1413.561f, 1534.829f, false);
                        events.ScheduleEvent(EVENT_SCRIPT_13, 10000);
                        break;
                    case EVENT_SCRIPT_13:
                        me->DisappearAndDie();
                        break;
                }
            }
        }

    private:
        EventMap events;
        uint64 playerGUID;
        uint64 objectGUID[5];
        uint64 voiceGUID;
        uint8 objectCounter;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_brann_bronzebeardAI(creature);
    }
};

enum CloseRift
{
    SPELL_DESPAWN_RIFT          = 61665
};

class spell_close_rift : public SpellScriptLoader
{
    public:
        spell_close_rift() : SpellScriptLoader("spell_close_rift") { }

        class spell_close_rift_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_close_rift_AuraScript);

            bool Load() OVERRIDE
            {
                _counter = 0;
                return true;
            }

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                return sSpellMgr->GetSpellInfo(SPELL_DESPAWN_RIFT);
            }

            void HandlePeriodic(AuraEffect const* /* aurEff */)
            {
                if (++_counter == 5)
                    GetTarget()->CastSpell((Unit*)NULL, SPELL_DESPAWN_RIFT, true);
            }

            void Register() OVERRIDE
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_close_rift_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

        private:
            uint8 _counter;

        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_close_rift_AuraScript();
        }
};

/*#####
# spell_jokkum_scriptcast
#####*/

enum JokkumScriptcast
{
    SPELL_JOKKUM_KILL_CREDIT    = 56545,
    SPELL_JOKKUM_SUMMON         = 56541,
};

class spell_jokkum_scriptcast : public SpellScriptLoader
{
    public: spell_jokkum_scriptcast() : SpellScriptLoader("spell_jokkum_scriptcast") { }

        class spell_jokkum_scriptcast_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jokkum_scriptcast_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_JOKKUM_KILL_CREDIT) || !sSpellMgr->GetSpellInfo(SPELL_JOKKUM_SUMMON))
                    return false;
                return true;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetTarget()->ToPlayer())
                {
                    player->CastSpell(player, SPELL_JOKKUM_KILL_CREDIT, true);
                    player->CastSpell(player, SPELL_JOKKUM_SUMMON, true);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectApply += AuraEffectApplyFn(spell_jokkum_scriptcast_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_jokkum_scriptcast_AuraScript();
        }
};

void AddSC_storm_peaks()
{
    new npc_injured_goblin();
    new npc_roxi_ramrocket();
    new npc_brunnhildar_prisoner();
    new npc_freed_protodrake();
    new npc_icefang();
    new npc_hyldsmeet_protodrake();
    new npc_brann_bronzebeard();
    new spell_close_rift();
    new spell_jokkum_scriptcast();
}
