#pragma once
#include "../Value.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class Formation : public AiNamedObject
    {
    public:
        Formation(PlayerbotAI* ai, string name) : AiNamedObject (ai, name) {}

    public:
        virtual string GetTargetName() { return ""; }
        virtual WorldLocation GetLocation() { return NullLocation; }
        virtual float GetMaxDistance() { return sPlayerbotAIConfig.followDistance; }
        static WorldLocation NullLocation;

    protected:
        float GetFollowAngle();
    };

    class FollowFormation : public Formation
    {
    public:
        FollowFormation(PlayerbotAI* ai, string name) : Formation(ai, name) {}
    };

    class MoveFormation : public Formation
    {
    public:
        MoveFormation(PlayerbotAI* ai, string name) : Formation(ai, name) {}

    protected:
        WorldLocation MoveLine(vector<Player*> line, float diff, float cx, float cy, float cz, float orientation, float range);
        WorldLocation MoveSingleLine(vector<Player*> line, float diff, float cx, float cy, float cz, float orientation, float range);
    };

    class FormationValue : public ManualSetValue<Formation*>
	{
	public:
        FormationValue(PlayerbotAI* ai);
        ~FormationValue() { if (value) { delete value; value = NULL; } }
    };

    class SetFormationAction : public Action
    {
    public:
        SetFormationAction(PlayerbotAI* ai) : Action(ai, "set formation") {}
        virtual bool Execute(Event event);
    };
};

