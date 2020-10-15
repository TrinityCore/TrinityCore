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
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Unit.h"

#include <iostream>

enum Spells
{
	AURA_ARCANE_BLAST           = 36032,

	SPELL_ARCANE_BARRAGE        = 100009,
	SPELL_ARCANE_BLAST          = 100010,
	SPELL_ARCANE_EXPLOSION      = 100011,
	SPELL_STOP_TIME             = 100090,
	SPELL_WRAP_IN_TIME          = 100096
};

enum Texts
{
	SAY_NETRISTRASZA_AGGRO      = 0,
	SAY_NETRISTRASZA_COMBAT     = 2,
	SAY_NETRISTRASZA_WOUNDED    = 3,
	SAY_NETRISTRASZA_KILL       = 4,
	SAY_NETRISTRASZA_DONE       = 5,

	SAY_NETRISTRASZA_ESCORT_01  = 6,
	SAY_NETRISTRASZA_ESCORT_02  = 7,
	SAY_NETRISTRASZA_ESCORT_03  = 8,
	SAY_NETRISTRASZA_ESCORT_04  = 9,
	SAY_NETRISTRASZA_ESCORT_05  = 10,
	SAY_NETRISTRASZA_ESCORT_06  = 11,

	SAY_NETRISTRASZA_HURRY      = 12,
	SAY_NETRISTRASZA_THANKS     = 13,
	SAY_NETRISTRASZA_WAIT       = 14,

	SAY_NETRISTRASZA_INTRO_01   = 15,
	SAY_NETRISTRASZA_INTRO_02   = 16,

	SAY_AG_ANTONN_GRAVE_01      = 0,
	SAY_AG_ANTONN_GRAVE_02      = 1,
	SAY_AG_ANTONN_GRAVE_03      = 2,
	SAY_AG_NETRISTRASZA_04      = 17,
	SAY_AG_ANTONN_GRAVE_05      = 3,
	SAY_AG_LEORIC_06            = 0,
	SAY_AG_NETRISTRASZA_07      = 18
};

enum Misc
{
	// Gossips
	GOSSIP_MENU_START           = 57024,
	GOSSIP_MENU_FINAL           = 57025,

	// Group
	GROUP_COMBAT                = 1
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
			instance(creature->GetInstanceScript()), started(false), wrapInTime(false), debug(false)
		{
			Initialize();
		}

		void Initialize()
		{
			scheduler.SetValidator([this]
			{
				return !me->HasUnitState(UNIT_STATE_CASTING);
			});
		}

		void Reset() override
		{
			scheduler.CancelGroup(GROUP_COMBAT);
		}

		void EnterEvadeMode(EvadeReason why) override
		{
			scheduler.CancelGroup(GROUP_COMBAT);

			EscortAI::EnterEvadeMode(why);
		}

		void JustDied(Unit* killer) override
		{
			scheduler.CancelGroup(GROUP_COMBAT);

			EscortAI::JustDied(killer);
		}

		void KilledUnit(Unit* /*victim*/) override
		{
			if (roll_chance_i(50))
				Talk(SAY_NETRISTRASZA_KILL);
		}

		void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
		{
			if (!wrapInTime && HealthBelowPct(50))
			{
				Talk(SAY_NETRISTRASZA_WOUNDED);

				wrapInTime = true;
				scheduler.DelayGroup(GROUP_COMBAT, 9s);
				me->InterruptNonMeleeSpells(false);
				DoCastAOE(SPELL_STOP_TIME);
			}
		}

		void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
		{
			switch (spell->Id)
			{
				case SPELL_STOP_TIME:
					if (reason == SPELL_FINISHED_SUCCESSFUL_CAST)
						DoCast(SPELL_WRAP_IN_TIME);
					break;
				case SPELL_WRAP_IN_TIME:
					if (reason == SPELL_FINISHED_CHANNELING_COMPLETE)
						wrapInTime = false;
					break;
				default:
					break;
			}
		}

        void SetData(uint32 id, uint32 /*value*/) override
        {
            if (GameObject* ironGate = GetClosestGameObjectWithEntry(me, GOB_IRON_GATE, 50.f))
                instance->HandleGameObject(ObjectGuid::Empty, true, ironGate);

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            debug = true;

            switch (id)
            {
                case 0:
                    me->SetVisible(true);
                    Start(true, true, playerGUID);
                    SetDespawnAtEnd(false);
                    break;
                default:
                    break;
            }
        }

		void DoAction(int32 actionId) override
		{
			switch (actionId)
			{
				case ACTION_SAY_DONE:
					Talk(SAY_NETRISTRASZA_DONE);
					break;
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
						antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_02);
					}
					scheduler.Schedule(4s, [this](TaskContext context)
					{
						switch (context.GetRepeatCounter())
						{
							case 0:
								if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
									antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_03);
								context.Repeat(4s);
								break;
							case 1:
								Talk(SAY_AG_NETRISTRASZA_04);
								context.Repeat(4s);
								break;
							case 2:
								if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
									antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_05);
								context.Repeat(2s);
								break;
							case 3:
								if (Creature* stalker = me->SummonCreature(NPC_INVISIBLE_STALKER, 261.69f, 93.37f, 112.19f, 4.72f))
								{
									stalker->CastSpell(stalker, SPELL_DEMONIC_PORTAL);
									portalGUID = stalker->GetGUID();
								}
								context.Repeat(1s);
								break;
							case 4:
								if (Creature* leoric = me->SummonCreature(NPC_LEORIC, leoricPos01))
								{
									leoric->SetImmuneToAll(true);
									leoric->SetWalk(true);
									leoric->GetMotionMaster()->MovePoint(0, leoricPos02, true, leoricPos02.GetOrientation());
								}
								context.Repeat(1s);
								break;
							case 5:
								if (Creature* leoric = instance->GetCreature(DATA_LEORIC))
									leoric->AI()->Talk(SAY_AG_LEORIC_06);
								context.Repeat(9s);
								break;
							case 6:
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
                                context.Repeat(5s);
                                break;
							case 7:
                                if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                                    antonn->SetFacingToObject(me);
                                context.Repeat(2s);
								break;
                            case 8:
                                if (GameObject* door = instance->GetGameObject(DATA_ANTONN_GRAVE_ENTRANCE))
                                    instance->HandleGameObject(ObjectGuid::Empty, true, door);
                                context.Repeat(1s);
                                break;
                            case 9:
                                if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
                                    antonn->AI()->DoAction(ACTION_AG_SKELETON);
                                break;
							default:
								break;
						}
					});
					break;
				case ACTION_AG_END:
					scheduler.Schedule(5s, [this](TaskContext context)
					{
						switch (context.GetRepeatCounter())
						{
							case 0:
								if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
									me->SetFacingToObject(antonn);
								context.Repeat(1s);
								break;
							case 1:
								Talk(SAY_AG_NETRISTRASZA_07);
								context.Repeat(5s);
								break;
							case 2:
								SetEscortPaused(false);
								break;
							default:
								break;
						}
					});
					break;
				default:
					break;
			}
		}

		void JustEngagedWith(Unit* /*who*/) override
		{
            if (roll_chance_i(30))
                Talk(SAY_NETRISTRASZA_AGGRO);

			scheduler
				.Schedule(2s, GROUP_COMBAT, [this](TaskContext arcane_blast)
				{
                    if (roll_chance_i(20))
                        Talk(SAY_NETRISTRASZA_COMBAT);
                    DoCastVictim(SPELL_ARCANE_BLAST);
					arcane_blast.Repeat(8s, 12s);
				})
				.Schedule(5s, GROUP_COMBAT, [this](TaskContext arcane_barrage)
				{
					if (Aura* aura = me->GetAura(AURA_ARCANE_BLAST))
						me->RemoveAura(aura);
					me->InterruptNonMeleeSpells(true);
					DoCastVictim(SPELL_ARCANE_BARRAGE);
					arcane_barrage.Repeat(14s, 24s);
				})
				.Schedule(18s, GROUP_COMBAT, [this](TaskContext arcane_explosion)
				{
                    me->InterruptNonMeleeSpells(true);
					DoCastAOE(SPELL_ARCANE_EXPLOSION);
					arcane_explosion.Repeat(32s, 45s);
				});
		}

		void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
		{
			switch (waypointId)
			{
				case 1:
                    if (debug)
                        return;
					SetEscortPaused(true);
					if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
						me->SetFacingToObject(player);
					scheduler.Schedule(1s, [this](TaskContext context)
					{
						switch (context.GetRepeatCounter())
						{
							case 0:
								Talk(SAY_NETRISTRASZA_INTRO_01);
								if (Creature* rift = instance->GetCreature(DATA_TIME_RIFT))
									rift->DespawnOrUnsummon();
								context.Repeat(6s);
								break;
							case 1:
								Talk(SAY_NETRISTRASZA_INTRO_02);
								context.Repeat(4s);
								break;
							case 2:
								me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
								if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
									me->SetFacingToObject(player);
								break;
							default:
								break;
						}
					});
					break;
				case 4:
                    if (debug)
                        return;
					Talk(SAY_NETRISTRASZA_ESCORT_01);
					if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
						me->SetFacingToObject(player);
					break;
				case 10:
					if (GameObject* door = instance->GetGameObject(DATA_NETRISTRASZA_ENTRANCE))
						instance->HandleGameObject(ObjectGuid::Empty, false, door);
					if (Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE))
						antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_01);
					break;
				case 15:
					SetEscortPaused(true);
					DoAction(ACTION_AG_INTRO);
					break;
				default:
					break;
			}
		}

		void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
		{
			instance->SetBossState(DATA_NETRISTRASZA, DONE);
		}

		void UpdateEscortAI(uint32 diff) override
		{
			scheduler.Update(diff, [this]
			{
				if (UpdateVictim())
					DoMeleeAttackIfReady();
			});
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
		TaskScheduler scheduler;
		bool started;
		bool wrapInTime;
        bool debug;
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
