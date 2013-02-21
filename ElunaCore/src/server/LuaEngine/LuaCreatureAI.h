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

			void EnterCombat(Unit* target)
			{
				if (!target || !target->IsInWorld())
					return;

				Eluna::get()->BeginCall(Eluna::get()->GetCreatureScript()->GetCreatureBindingForId(me->GetEntry())->_functionReferences[CREATURE_EVENT_ON_COMBAT]);
				Eluna::get()->PushInteger(Eluna::get()->_luaState, CREATURE_EVENT_ON_COMBAT);
				Eluna::get()->PushUnit(Eluna::get()->_luaState, me);
				Eluna::get()->PushUnit(Eluna::get()->_luaState, target);
				Eluna::get()->ExecuteCall(3, 0);
			}
		};
};
#endif