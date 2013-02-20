#ifndef __CREATUREAI_ELUNA
#define __CREATUREAI_ELUNA
#include "LuaEngine.h"
#include "ScriptMgr.h"
#include "Creature.h"
#include "ScriptedCreature.h"

class LuaCreatureAI : public CreatureScript
{
	public:
		LuaCreatureAI() : CreatureScript("LuaCreature") { }
		~LuaCreatureAI() { }

		CreatureAI * GetLuaCreatureAI(Creature * creature) const { return new LuaScriptedAI(creature); }

		struct LuaScriptedAI : public ScriptedAI
		{
			LuaScriptedAI(Creature * creature) : ScriptedAI(creature) { }
		};
};
#endif