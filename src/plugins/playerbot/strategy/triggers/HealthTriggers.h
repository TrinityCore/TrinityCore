#pragma once
#include "../Trigger.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class ValueInRangeTrigger : public Trigger
    {
    public:
        ValueInRangeTrigger(PlayerbotAI* ai, string name, float maxValue, float minValue) : Trigger(ai, name) {
            this->maxValue = maxValue;
            this->minValue = minValue;
        }
    public:
        virtual float GetValue() = 0;
        virtual bool IsActive() {
            float value = GetValue();
            return value < maxValue && value >= minValue;
        }

    protected:
        float maxValue, minValue;
    };

	class HealthInRangeTrigger : public ValueInRangeTrigger
	{
	public:
		HealthInRangeTrigger(PlayerbotAI* ai, string name, float maxValue, float minValue = 0) :
		  ValueInRangeTrigger(ai, name, maxValue, minValue) {}

		virtual bool IsActive()
		{
		    return ValueInRangeTrigger::IsActive() && !AI_VALUE2(bool, "dead", GetTargetName());
		}

		virtual float GetValue();
	};

    class LowHealthTrigger : public HealthInRangeTrigger
    {
    public:
        LowHealthTrigger(PlayerbotAI* ai, string name = "low health",
            float value = sPlayerbotAIConfig.lowHealth, float minValue = sPlayerbotAIConfig.criticalHealth) :
            HealthInRangeTrigger(ai, name, value, minValue) {}

		virtual string GetTargetName() { return "self target"; }
    };

    class CriticalHealthTrigger : public LowHealthTrigger
    {
    public:
        CriticalHealthTrigger(PlayerbotAI* ai) :
            LowHealthTrigger(ai, "critical health", sPlayerbotAIConfig.criticalHealth, 0) {}
    };

    class MediumHealthTrigger : public LowHealthTrigger
    {
    public:
        MediumHealthTrigger(PlayerbotAI* ai) :
            LowHealthTrigger(ai, "medium health", sPlayerbotAIConfig.mediumHealth, sPlayerbotAIConfig.lowHealth) {}
    };

    class AlmostFullHealthTrigger : public LowHealthTrigger
    {
    public:
        AlmostFullHealthTrigger(PlayerbotAI* ai) :
            LowHealthTrigger(ai, "almost full health", sPlayerbotAIConfig.almostFullHealth, sPlayerbotAIConfig.mediumHealth) {}
    };

    class PartyMemberLowHealthTrigger : public HealthInRangeTrigger
    {
    public:
        PartyMemberLowHealthTrigger(PlayerbotAI* ai, string name = "party member low health", float value = sPlayerbotAIConfig.lowHealth, float minValue = sPlayerbotAIConfig.criticalHealth) :
            HealthInRangeTrigger(ai, name, value, minValue) {}

        virtual string GetTargetName() { return "party member to heal"; }
    };

    class PartyMemberCriticalHealthTrigger : public PartyMemberLowHealthTrigger
    {
    public:
        PartyMemberCriticalHealthTrigger(PlayerbotAI* ai) :
            PartyMemberLowHealthTrigger(ai, "party member critical health", sPlayerbotAIConfig.criticalHealth, 0) {}
    };

    class PartyMemberMediumHealthTrigger : public PartyMemberLowHealthTrigger
    {
    public:
        PartyMemberMediumHealthTrigger(PlayerbotAI* ai) :
            PartyMemberLowHealthTrigger(ai, "party member medium health", sPlayerbotAIConfig.mediumHealth,sPlayerbotAIConfig.lowHealth) {}
    };

    class PartyMemberAlmostFullHealthTrigger : public PartyMemberLowHealthTrigger
    {
    public:
        PartyMemberAlmostFullHealthTrigger(PlayerbotAI* ai) :
            PartyMemberLowHealthTrigger(ai, "party member almost full health", sPlayerbotAIConfig.almostFullHealth,sPlayerbotAIConfig.mediumHealth) {}
    };

    class TargetLowHealthTrigger : public HealthInRangeTrigger {
    public:
        TargetLowHealthTrigger(PlayerbotAI* ai, float value, float minValue = 0) :
            HealthInRangeTrigger(ai, "target low health", value, minValue) {}
        virtual string GetTargetName() { return "current target"; }
    };

    class TargetCriticalHealthTrigger : public TargetLowHealthTrigger
    {
    public:
        TargetCriticalHealthTrigger(PlayerbotAI* ai) : TargetLowHealthTrigger(ai, 20) {}
    };

	class PartyMemberDeadTrigger : public Trigger {
	public:
		PartyMemberDeadTrigger(PlayerbotAI* ai) : Trigger(ai, "resurrect", 10) {}
        virtual string GetTargetName() { return "party member to resurrect"; }
		virtual bool IsActive();
	};

    class DeadTrigger : public Trigger {
    public:
        DeadTrigger(PlayerbotAI* ai) : Trigger(ai, "dead", 10) {}
        virtual string GetTargetName() { return "self target"; }
        virtual bool IsActive();
    };

    class AoeHealTrigger : public Trigger {
    public:
    	AoeHealTrigger(PlayerbotAI* ai, string name, string type, int count) :
    		Trigger(ai, name), type(type), count(count) {}
    public:
        virtual bool IsActive();

    protected:
        int count;
        string type;
    };

}
