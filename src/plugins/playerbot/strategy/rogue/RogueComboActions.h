#pragma once

namespace ai
{
	class CastComboAction : public CastMeleeSpellAction
	{
	public:
	    CastComboAction(PlayerbotAI* ai, string name) : CastMeleeSpellAction(ai, name) {}

	    virtual bool isUseful()
	    {
	        return CastMeleeSpellAction::isUseful() && AI_VALUE2(uint8, "combo", "self target") < 5;
	    }
	};

	class CastSinisterStrikeAction : public CastComboAction
	{
	public:
		CastSinisterStrikeAction(PlayerbotAI* ai) : CastComboAction(ai, "sinister strike") {}
	};

    class CastMutilateAction : public CastComboAction
    {
    public:
        CastMutilateAction(PlayerbotAI* ai) : CastComboAction(ai, "mutilate") {}
    };

    class CastRiposteAction : public CastComboAction
    {
    public:
        CastRiposteAction(PlayerbotAI* ai) : CastComboAction(ai, "riposte") {}
    };

	class CastGougeAction : public CastComboAction
	{
	public:
		CastGougeAction(PlayerbotAI* ai) : CastComboAction(ai, "gouge") {}
	};

    class CastBackstabAction : public CastComboAction
    {
    public:
        CastBackstabAction(PlayerbotAI* ai) : CastComboAction(ai, "backstab") {}
    };
}
