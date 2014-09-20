#pragma once

namespace ai
{
	class CastEviscerateAction : public CastMeleeSpellAction 
	{ 
	public: 
		CastEviscerateAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "eviscerate") {} 
	};

	class CastSliceAndDiceAction : public CastMeleeSpellAction 
	{ 
	public: 
		CastSliceAndDiceAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "slice and dice") {} 
	};

	class CastExposeArmorAction : public CastMeleeSpellAction 
	{ 
	public: 
		CastExposeArmorAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "expose armor") {} 
	};

	class CastRuptureAction : public CastMeleeSpellAction 
	{ 
	public: 
		CastRuptureAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "rupture") {} 
	};
	
	class CastKidneyShotAction : public CastMeleeSpellAction 
	{ 
	public: 
		CastKidneyShotAction(PlayerbotAI* ai) : CastMeleeSpellAction(ai, "kidney shot") {} 
	};
	
}