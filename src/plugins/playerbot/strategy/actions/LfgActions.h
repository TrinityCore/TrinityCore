#pragma once

#include "../Action.h"
#include "InventoryAction.h"
#include "MovementActions.h"
#include "../../AiFactory.h"
#include "../../PlayerbotAIConfig.h"
#include "../ItemVisitors.h"
#include "../../RandomPlayerbotMgr.h"
#include "../../../DungeonFinding/LFGMgr.h"
#include "../../../DungeonFinding/LFG.h"
#include "../../../Battlegrounds/Battleground.h"
#include "../../../Battlegrounds/BattlegroundMgr.h"
#include "../../../Battlegrounds/BattlegroundQueue.h"
#include "../../../Battlegrounds/Zones/BattlegroundWS.h"
#include "ChooseTargetActions.h"
#include "CheckMountStateAction.h"
#include "G3D/Vector3.h"

namespace ai
{
    class LfgJoinAction : public InventoryAction
    {
    public:
        LfgJoinAction(PlayerbotAI* ai, string name = "lfg join") : InventoryAction(ai, name) {}
        virtual bool Execute(Event event);

    protected:
        bool JoinProposal();
        bool SetRoles();
        uint8 GetRoles();
    };

    class LfgAcceptAction : public LfgJoinAction
    {
    public:
        LfgAcceptAction(PlayerbotAI* ai) : LfgJoinAction(ai, "lfg accept") {}
        virtual bool Execute(Event event);
    };

    class LfgRoleCheckAction : public LfgJoinAction
    {
    public:
        LfgRoleCheckAction(PlayerbotAI* ai) : LfgJoinAction(ai, "lfg role check") {}
        virtual bool Execute(Event event);
    };

    class LfgLeaveAction : public Action
    {
    public:
        LfgLeaveAction(PlayerbotAI* ai) : Action(ai, "lfg leave") {}
        virtual bool Execute(Event event);
    };

    class LfgTeleportAction : public Action
    {
    public:
        LfgTeleportAction(PlayerbotAI* ai) : Action(ai, "lfg teleport") {}
        virtual bool Execute(Event event);
    };

	class BGJoinAction : public InventoryAction
	{
	public:
		BGJoinAction(PlayerbotAI* ai, string name = "bg join") : InventoryAction(ai, name) {}
		virtual bool Execute(Event event);

	protected:
		bool JoinProposal();
	};

	class BGStatusAction : public BGJoinAction
	{
	public:
		BGStatusAction(PlayerbotAI* ai) : BGJoinAction(ai, "bg status") {}
		virtual bool Execute(Event event);
	};

	class BGTacticsWS : public MovementAction
	{
	public:
		BGTacticsWS(PlayerbotAI* ai, string name ="bg tactics ws") : MovementAction(ai, name) {}
		virtual bool Execute(Event event);
	private:
		bool moveTowardsEnemyFlag(BattlegroundWS *bg);
		bool consumeHealthy(Battleground *bg);
		bool homerun(BattlegroundWS *bg);
		bool runPathTo(WorldObject *unit, Battleground *bg);
		bool wasInCombat = false;
	};

}
