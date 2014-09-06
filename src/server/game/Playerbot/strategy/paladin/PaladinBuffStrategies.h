#pragma once

#include "GenericPaladinStrategy.h"

namespace ai
{
    class PaladinBuffManaStrategy : public Strategy
    {
    public:
        PaladinBuffManaStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bmana"; }
    };

    class PaladinBuffHealthStrategy : public Strategy
    {
    public:
        PaladinBuffHealthStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bhealth"; }
    };

    class PaladinBuffDpsStrategy : public Strategy
    {
    public:
        PaladinBuffDpsStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bdps"; }
    };

	class PaladinBuffArmorStrategy : public Strategy
	{
	public:
		PaladinBuffArmorStrategy(PlayerbotAI* ai) : Strategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "barmor"; }
	};

	class PaladinBuffSpeedStrategy : public Strategy
	{
	public:
		PaladinBuffSpeedStrategy(PlayerbotAI* ai) : Strategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "bspeed"; }
	};

	class PaladinShadowResistanceStrategy : public Strategy
	{
	public:
		PaladinShadowResistanceStrategy(PlayerbotAI* ai) : Strategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "rshadow"; }
	};

	class PaladinFrostResistanceStrategy : public Strategy
	{
	public:
		PaladinFrostResistanceStrategy(PlayerbotAI* ai) : Strategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "rfrost"; }
	};

	class PaladinFireResistanceStrategy : public Strategy
	{
	public:
		PaladinFireResistanceStrategy(PlayerbotAI* ai) : Strategy(ai) {}

	public:
		virtual void InitTriggers(std::list<TriggerNode*> &triggers);
		virtual string getName() { return "rfire"; }
	};
}
