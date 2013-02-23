#include "ScriptMgr.h"
#include "GameObjectAI.h"

#ifndef __GAMEOBJECTAI_ELUNA
#define __GAMEOBJECTAI_ELUNA

class LuaGameObjectAI : public GameObjectScript
{
	public:
		LuaGameObjectAI() : GameObjectScript("LuaGameObject") { }
		~LuaGameObjectAI() { }

		GameObjectAI* GetLuaGameObjectAI(GameObject* go) const { return new LuaGameObjectScriptedAI(go); }

		struct LuaGameObjectScriptedAI : public GameObjectAI
		{
			LuaGameObjectScriptedAI(GameObject* _go) : GameObjectAI(_go) { }
		};
};
#endif