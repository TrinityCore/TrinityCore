#include "ScriptMgr.h"
#include "Creature.h"
#include "ScriptedCreature.h"
#ifndef __CREATUREAI_ELUNA
#define __CREATUREAI_ELUNA

class LuaCreatureAI : public CreatureScript
{
	public:
		LuaCreatureAI() : CreatureScript("LuaCreature") { }
		~LuaCreatureAI() { }

		CreatureAI* GetLuaCreatureAI(Creature* creature) const { return new LuaScriptedAI(creature); }

		struct LuaScriptedAI : public ScriptedAI
		{
			LuaScriptedAI(Creature* creature) : ScriptedAI(creature) { }
		};
};
#endif