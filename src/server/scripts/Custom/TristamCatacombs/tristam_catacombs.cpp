#include "tristam_catacombs.h"
#include "Creature.h"
#include "EventProcessor.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Unit.h"

#include <iostream>

enum Spells
{
    SPELL_ARCANE_BARRAGE        = 100009,
    SPELL_ARCANE_BLAST          = 100010,
    SPELL_ARCANE_PROJECTILE     = 100012,
    SPELL_ARCANE_EXPLOSION      = 100011,
    SPELL_STOP_TIME             = 100096,
    SPELL_WRAP_IN_TIME          = 100097
};

enum Events
{
	EVENT_START_01              = 1,
	EVENT_START_02,
	EVENT_START_03,

	EVENT_ANTONN_GRAVE_01,
	EVENT_ANTONN_GRAVE_02,
	EVENT_ANTONN_GRAVE_03,
	EVENT_ANTONN_GRAVE_04,
	EVENT_ANTONN_GRAVE_05,
	EVENT_ANTONN_GRAVE_06,
	EVENT_ANTONN_GRAVE_07,
	EVENT_ANTONN_GRAVE_08,
	EVENT_ANTONN_GRAVE_09,

    EVENT_SPELL_ARCANE_BARRAGE,
    EVENT_SPELL_ARCANE_BLAST,
    EVENT_SPELL_ARCANE_PROJECTILE,
    EVENT_SPELL_ARCANE_EXPLOSION
};

enum Texts
{
	SAY_NETRISTRASZA_INTRO_01   = 0,
	SAY_NETRISTRASZA_INTRO_02   = 1,

	SAY_NETRISTRASZA_ESCORT_01  = 2,
	SAY_NETRISTRASZA_ESCORT_02  = 3,
	SAY_NETRISTRASZA_ESCORT_03  = 4,
	SAY_NETRISTRASZA_ESCORT_04  = 5,

	SAY_AG_ANTONN_GRAVE_01      = 0,
    SAY_AG_ANTONN_GRAVE_02      = 2,
	SAY_AG_NETRISTRASZA_03      = 6,
    SAY_AG_ANTONN_GRAVE_04      = 3,
    SAY_AG_LEORIC_05            = 0,
};

enum Gossips
{
	GOSSIP_MENU_START           = 57024,
	GOSSIP_MENU_FINAL           = 57025,
};

const Position leoricPos01 = { 261.69f, 93.37f, 109.97f, 4.72f };
const Position leoricPos02 = { 261.69f, 82.90f, 109.97f, 4.72f };

// 100075
class npc_netristrasza : public CreatureScript
{
	public:
	npc_netristrasza() : CreatureScript("npc_netristrasza")
	{
	}

	struct npc_netristraszaAI : public EscortAI
	{
		npc_netristraszaAI(Creature* creature) : EscortAI(creature),
			instance(creature->GetInstanceScript()), started(false), wrapInTime(false)
		{
		}

		void Reset() override
		{
			events.Reset();
		}

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!wrapInTime && HealthBelowPct(30))
            {
                wrapInTime = true;
                me->InterruptNonMeleeSpells(false);
                DoCastAOE(SPELL_STOP_TIME, true);
                DoCast(SPELL_WRAP_IN_TIME);
            }
        }

        void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
        {
            if (spell->Id == SPELL_WRAP_IN_TIME && reason == SPELL_FINISHED_CHANNELING_COMPLETE)
                wrapInTime = false;
        }

		void DoAction(int32 actionId) override
		{
			switch (actionId)
			{
				case ACTION_START_DUNGEON:
					if (started)
						return;
					if (Player* player = me->SelectNearestPlayer(50.f))
						playerGUID = player->GetGUID();
					started = true;
                    me->SetVisible(true);
                    DoCast(SPELL_VISUAL_TELEPORT);
                    Start(true, true, playerGUID);
                    SetDespawnAtEnd(false);
                    break;
				case ACTION_AG_INTRO:
					if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
					{
						me->SetFacingToObject(antonn);
						antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_01);
					}
					events.ScheduleEvent(EVENT_ANTONN_GRAVE_01, 4s);
					break;
				default:
					break;
			}
		}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SPELL_ARCANE_BARRAGE, 5s);
            events.ScheduleEvent(EVENT_SPELL_ARCANE_BLAST, 2s);
            events.ScheduleEvent(EVENT_SPELL_ARCANE_PROJECTILE, 24s);
            events.ScheduleEvent(EVENT_SPELL_ARCANE_EXPLOSION, 18s);
        }

		void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
		{
			switch (waypointId)
			{
				case 1:
					SetEscortPaused(true);
					if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
						me->SetFacingToObject(player);
                    if (Creature* rift = instance->GetCreature(DATA_TIME_RIFT))
                        rift->DespawnOrUnsummon();
                    events.ScheduleEvent(EVENT_START_01, 1s);
					break;
				case 4:
					me->AI()->Talk(SAY_NETRISTRASZA_ESCORT_01);
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                        me->SetFacingToObject(player);
					break;
                case 10:
                    if (GameObject* door = instance->GetGameObject(DATA_NETRISTRASZA_ENTRANCE))
                        instance->HandleGameObject(ObjectGuid::Empty, false, door);
                    if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                        antonn->AI()->Talk(SAY_ANTONN_01);
                    break;
				case 15:
					SetEscortPaused(true);
					DoAction(ACTION_AG_INTRO);
					break;
				default:
					break;
			}
		}

		void UpdateAI(uint32 diff) override
		{
			events.Update(diff);

            EscortAI::UpdateAI(diff);

			while (uint32 event = events.ExecuteEvent())
			{
				switch (event)
				{
                    // Handle after waypoint 1
					case EVENT_START_01:
						me->AI()->Talk(SAY_NETRISTRASZA_INTRO_01);
						events.ScheduleEvent(EVENT_START_02, 6s);
						break;
					case EVENT_START_02:
						me->AI()->Talk(SAY_NETRISTRASZA_INTRO_02);
						events.ScheduleEvent(EVENT_START_03, 4s);
						break;
					case EVENT_START_03:
						me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                            me->SetFacingToObject(player);
						break;
                    // Handle after waypoint 15
					case EVENT_ANTONN_GRAVE_01:
                        if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                            antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_02);
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_02, 4s);
                        break;
                    case EVENT_ANTONN_GRAVE_02:
						me->AI()->Talk(SAY_AG_NETRISTRASZA_03);
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_03, 4s);
                        break;
                    case EVENT_ANTONN_GRAVE_03:
                        if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                            antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_04);
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_04, 2s);
                        break;
                    case EVENT_ANTONN_GRAVE_04:
                        if (Creature* stalker = me->SummonCreature(NPC_INVISIBLE_STALKER, 261.69f, 93.37f, 112.19f, 4.72f))
                        {
                            stalker->CastSpell(stalker, SPELL_DEMONIC_PORTAL);
                            portalGUID = stalker->GetGUID();
                        }
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_05, 1s);
                        break;
                    case EVENT_ANTONN_GRAVE_05:
                        if (Creature* leoric = me->SummonCreature(NPC_LEORIC, leoricPos01))
                        {
                            leoric->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            leoric->SetWalk(true);
                            leoric->GetMotionMaster()->MovePoint(0, leoricPos02);
                        }
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_06, 2s);
                        break;
                    case EVENT_ANTONN_GRAVE_06:
                        if (Creature* leoric = instance->GetCreature(DATA_LEORIC))
                            leoric->AI()->Talk(SAY_AG_LEORIC_05);
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_07, 9s);
                        break;
                    case EVENT_ANTONN_GRAVE_07:
                        if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                        {
                            antonn->RemoveAllAuras();
                            antonn->SetStandState(UNIT_STAND_STATE_STAND);
                        }
                        if (Creature* leoric = instance->GetCreature(DATA_LEORIC))
                        {
                            leoric->GetMotionMaster()->MovePoint(0, leoricPos01);
                            leoric->DespawnOrUnsummon(5s);
                            if (Creature* portal = ObjectAccessor::GetCreature(*me, portalGUID))
                                portal->DespawnOrUnsummon(7s);
                        }
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_08, 8s);
                        break;
                    case EVENT_ANTONN_GRAVE_08:
                        if (GameObject* door = instance->GetGameObject(DATA_NETRISTRASZA_ENTRANCE))
                            instance->HandleGameObject(ObjectGuid::Empty, true, door);
                        if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                        {
                            antonn->AI()->DoAction(ACTION_AG_SKELETON);
                            antonn->SetFacingToObject(me);
                        }
                        break;
                    default:
                        break;
				}
			}
		}

        void UpdateEscortAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 event = events.ExecuteEvent())
            {
                switch (event)
                {
                    case EVENT_SPELL_ARCANE_BARRAGE:
                        if (Unit* victim = SelectTarget(SelectTargetMethod::Random))
                            DoCast(victim, SPELL_ARCANE_BARRAGE);
                        events.RescheduleEvent(EVENT_SPELL_ARCANE_BARRAGE, 5s, 8s);
                        break;
                    case EVENT_SPELL_ARCANE_BLAST:
                        DoCastVictim(SPELL_ARCANE_BLAST);
                        events.RescheduleEvent(EVENT_SPELL_ARCANE_BLAST, 1s, 2s);
                        break;
                    case EVENT_SPELL_ARCANE_PROJECTILE:
                        DoCastVictim(SPELL_ARCANE_PROJECTILE);
                        events.RescheduleEvent(EVENT_SPELL_ARCANE_PROJECTILE, 12s, 15s);
                        break;
                    case EVENT_SPELL_ARCANE_EXPLOSION:
                        DoCastAOE(SPELL_ARCANE_EXPLOSION);
                        events.RescheduleEvent(EVENT_SPELL_ARCANE_EXPLOSION, 13s, 28s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

		bool OnGossipHello(Player* player) override
		{
			// override default gossip
			if (instance->GetBossState(DATA_NETRISTRASZA) == DONE)
			{
				player->PrepareGossipMenu(me, GOSSIP_MENU_FINAL, true);
				player->SendPreparedGossip(me);
				return true;
			}

			// load default gossip
			return false;
		}

		bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
		{
			ClearGossipMenuFor(player);

			switch (gossipListId)
			{
				case 0:
					player->PlayerTalkClass->SendCloseGossip();
					me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
					SetEscortPaused(false);
                    if (GameObject* ironGate = GetClosestGameObjectWithEntry(me, GOB_IRON_GATE, 50.f))
                        instance->HandleGameObject(ObjectGuid::Empty, true, ironGate);
					break;
				default:
					break;
			}
			return false;
		}

		private:
		InstanceScript* instance;
		EventMap events;
		bool started;
		bool wrapInTime;
		ObjectGuid playerGUID;
		ObjectGuid portalGUID;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTristamCatacombsAI<npc_netristraszaAI>(creature);
	}
};

// 5873
class at_entrance_catacombs : public AreaTriggerScript
{
	public:
	at_entrance_catacombs() : AreaTriggerScript("at_entrance_catacombs")
	{
	}

	bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
	{
		if (player->IsGameMaster())
			return true;

		InstanceScript* instance = player->GetInstanceScript();

		if (instance->GetBossState(DATA_NETRISTRASZA) == NOT_STARTED)
			instance->SetBossState(DATA_NETRISTRASZA, IN_PROGRESS);

		return true;
	}
};

void AddSC_tristam_catacombs()
{
	new at_entrance_catacombs();
	new npc_netristrasza();
}
