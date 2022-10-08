#include "ScriptMgr.h"
#include "waycrest_manor.h"

enum Texts
{
	SAY_LADY_INTRO = 0,
	SAY_LADY_INTRO_2 = 1,
	SAY_LUCILLE_INTRO = 0,
	SAY_COME_BACK = 0,
	SAY_MACE = 0,
	SAY_RUNNING = 1,
	SAY_HEROES = 1,
	SAY_HUNTING = 0,
};

//136084
struct npc_lucille_waycrest_intro : public ScriptedAI
{
	npc_lucille_waycrest_intro(Creature* c) : ScriptedAI(c) { }

	void MoveInLineOfSight(Unit* u) override
	{
		if (u->GetDistance2d(me) < 13.0f && u->IsPlayer() && me->HasUnitFlag2(UNIT_FLAG2_REGENERATE_POWER))
		{	
			me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
			Intro();
		}
	}

	void Intro()
	{
			me->GetScheduler().Schedule(3s, [this](TaskContext context)
			{
				if (Creature* lady = instance->GetCreature(NPC_LADY_WAYCREST_INTRO))
					lady->AI()->Talk(SAY_LADY_INTRO);
			});

			me->GetScheduler().Schedule(8s, [this](TaskContext context)
			{
				if (Creature* lucille = instance->GetCreature(NPC_LUCILLE_WAYCREST_INTRO))
					lucille->AI()->Talk(SAY_LUCILLE_INTRO);
			});

			me->GetScheduler().Schedule(11s, [this](TaskContext context)
			{
				if (Creature* lady = instance->GetCreature(NPC_LADY_WAYCREST_INTRO))
					lady->AI()->Talk(SAY_LADY_INTRO_2);
			});

			me->GetScheduler().Schedule(14s, [this](TaskContext context)
			{
				if (Creature* lady = instance->GetCreature(NPC_LADY_WAYCREST_INTRO))	
					lady->SetVisible(false);

				if (Creature* solena = instance->GetCreature(NPC_SISTER_SOLENA_INTRO))
					solena->SetVisible(false);

				if (Creature* briar = instance->GetCreature(NPC_SISTER_BRIAR_INTRO))
					briar->SetVisible(false);

				if (Creature* malady = instance->GetCreature(NPC_SISTER_MALADY_INTRO))
					malady->SetVisible(false);

			});

			me->GetScheduler().Schedule(21s, [this](TaskContext context)
			{
				if (Creature* mace = instance->GetCreature(NPC_INQUISITOR_MACE))
				{
					mace->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
					std::list<Creature*> c_list;
					me->GetCreatureListWithEntryInGrid(c_list, NPC_INQUISITOR_MACE, 500.0f);
					for (auto & mace : c_list)
					{
						mace->AI()->Talk(SAY_COME_BACK);
						mace->GetMotionMaster()->MovePoint(1, -547.0f, -259.0f, 245.0f, true);
					}
				}
			});

			me->GetScheduler().Schedule(23s, [this](TaskContext context)
			{
				if (Creature* notley = instance->GetCreature(NPC_INQUISITOR_NOTLEY))
				{
					std::list<Creature*> c_list;
					me->GetCreatureListWithEntryInGrid(c_list, NPC_INQUISITOR_NOTLEY, 500.0f);
					for (auto & notley : c_list)
					{
						notley->AI()->Talk(SAY_MACE);
					}
				}
			});

			me->GetScheduler().Schedule(25s, [this](TaskContext context)
			{
				if (Creature* notley = instance->GetCreature(NPC_INQUISITOR_NOTLEY))
				{
					std::list<Creature*> c_list;
					me->GetCreatureListWithEntryInGrid(c_list, NPC_INQUISITOR_NOTLEY, 500.0f);
					for (auto & notley : c_list)
					{
						notley->AI()->Talk(SAY_RUNNING);
					}
				}
			});

			me->GetScheduler().Schedule(33s, [this](TaskContext context)
			{
				if (Creature* lucille = instance->GetCreature(NPC_LUCILLE_WAYCREST_INTRO))
					lucille->AI()->Talk(SAY_HEROES);
			});

			me->GetScheduler().Schedule(40s, [this](TaskContext context)
			{
				if (Creature* yorrick = instance->GetCreature(NPC_INQUISITOR_YORRICK))
				{
					std::list<Creature*> c_list;
					me->GetCreatureListWithEntryInGrid(c_list, NPC_INQUISITOR_YORRICK, 500.0f);
					for (auto & yorrick : c_list)
					{
						yorrick->AI()->Talk(SAY_HUNTING);
					}
				}
			});

			me->GetScheduler().Schedule(44s, [this](TaskContext context)
			{
				if (Creature* lucille = instance->GetCreature(NPC_LUCILLE_WAYCREST_INTRO))
				{
					std::list<Creature*> c_list;
					lucille->GetCreatureListInGrid(c_list, 13.0f);
					for (auto & creatures : c_list)
					switch (creatures->GetEntry())
					{
					case NPC_LUCILLE_WAYCREST_INTRO:
						creatures->GetMotionMaster()->MovePoint(1, -547.0f, -259.0f, 245.0f, true);
						break;

					case NPC_INQUISITOR_NOTLEY:
						creatures->GetMotionMaster()->MovePoint(1, -547.0f, -259.0f, 245.0f, true);
						break;

					case NPC_INQUISITOR_YORRICK:
						creatures->GetMotionMaster()->MovePoint(1, -547.0f, -259.0f, 245.0f, true);
						break;

					case NPC_INQUISITOR_STERNTIDE:
						creatures->GetMotionMaster()->MovePoint(1, -547.0f, -259.0f, 245.0f, true);
						break;

					}
				}
			});
	}		

	void UpdateAI(uint32 diff) override
	{
		scheduler.Update(diff);
	}

	void MovementInform(uint32 motion, uint32 point) override
	{
		if (motion != POINT_MOTION_TYPE)
		return;

		if (point == 1)
		{	
			me->GetMotionMaster()->Clear();
			me->GetMotionMaster()->MovePoint(2, -588.0f, -294.0f, 249.0f, true);
		}

		if (point == 2)
			me->DespawnOrUnsummon();
	}

private:
	TaskScheduler scheduler;
};

//135357
struct npc_lady_waycrest_intro : public ScriptedAI
{
	npc_lady_waycrest_intro(Creature* c) : ScriptedAI(c) { }	

	void UpdateAI(uint32 diff) override
	{
		scheduler.Update(diff);
	}

private:
	TaskScheduler scheduler;
};

//136086
struct npc_inquisitor_mace : public ScriptedAI
{
	npc_inquisitor_mace(Creature* c) : ScriptedAI(c) { }

	void UpdateAI(uint32 diff) override
	{
		scheduler.Update(diff);
	}

	void MovementInform(uint32 motion, uint32 point) override
	{
		if (motion != POINT_MOTION_TYPE)
			return;

		if (point == 1)
		{	
			me->GetMotionMaster()->Clear();
			me->GetMotionMaster()->MovePoint(2, -588.0f, -294.0f, 249.0f, true);
		}

		if (point == 2)
			me->DespawnOrUnsummon();
	}

private:
	TaskScheduler scheduler;
};

//136094
struct npc_inquisitor_notley : public ScriptedAI
{
	npc_inquisitor_notley(Creature* c) : ScriptedAI(c) { }

	void UpdateAI(uint32 diff) override
	{
		scheduler.Update(diff);
	}

	void MovementInform(uint32 motion, uint32 point) override
	{
		if (motion != POINT_MOTION_TYPE)
		return;

		if (point == 1)
		{
			me->GetMotionMaster()->Clear();
			me->GetMotionMaster()->MovePoint(2, -588.0f, -294.0f, 249.0f, true);
		}
		if (point == 2)
			me->DespawnOrUnsummon();
	}

private:
	TaskScheduler scheduler;
};

//136085
struct npc_inquisitor_yorrick: public ScriptedAI
{
	npc_inquisitor_yorrick(Creature* c) : ScriptedAI(c) { }

	void UpdateAI(uint32 diff) override
	{
		scheduler.Update(diff);
	}

	void MovementInform(uint32 motion, uint32 point) override
	{
		if (motion != POINT_MOTION_TYPE)
		return;

		if (point == 1)
		{	
			me->GetMotionMaster()->Clear();
			me->GetMotionMaster()->MovePoint(2, -588.0f, -294.0f, 249.0f, true);
		}
		if (point == 2)
			me->DespawnOrUnsummon();
	}

private:
	TaskScheduler scheduler;
};

//136087
struct npc_inquisitor_sterntide : public ScriptedAI
{
	npc_inquisitor_sterntide(Creature* c) : ScriptedAI(c) { }

	void UpdateAI(uint32 diff) override
	{
		scheduler.Update(diff);
	}

	void MovementInform(uint32 motion, uint32 point) override
	{
		if (motion != POINT_MOTION_TYPE)
		return;

		if (point == 1)
		{	
			me->GetMotionMaster()->Clear();
			me->GetMotionMaster()->MovePoint(2, -588.0f, -294.0f, 249.0f, true);
		}

		if (point == 2)	
			me->DespawnOrUnsummon();
	}

private:
	TaskScheduler scheduler;
};

void AddSC_waycrest_manor()
{
	RegisterCreatureAI(npc_lady_waycrest_intro);
	RegisterCreatureAI(npc_lucille_waycrest_intro);
	RegisterCreatureAI(npc_inquisitor_mace);
	RegisterCreatureAI(npc_inquisitor_notley);
	RegisterCreatureAI(npc_inquisitor_yorrick);
	RegisterCreatureAI(npc_inquisitor_sterntide);
}
