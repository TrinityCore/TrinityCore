#pragma once

#include "MockedTargets.h"

namespace ai
{
	class MockPlayerbotAIBase : public PlayerbotAI
	{
	public:
		MockPlayerbotAIBase() : PlayerbotAI() 
        {
            targetIsCastingNonMeleeSpell = false;
        }
        void SetContext(AiObjectContext* context) { this->aiObjectContext = context; }
	
        virtual uint32 GetSpellId(string args) { return 1; }
        virtual void InterruptSpell();
        virtual void RemoveAura(string name);
        virtual bool CanCastSpell(string name, Unit* target);
        virtual bool CastSpell(string name, Unit* target);
        virtual bool HasAura(string spellName, Unit* player);
        virtual bool IsInterruptableSpellCasting(Unit* player, string spell);
        virtual bool HasAuraToDispel(Unit* player, uint32 dispelType);
        virtual bool IsSpellCastUseful(string name, Unit* target);

    public:
        void resetSpells() {spellCooldowns.clear(); }

    public:
        string buffer;

    public:
        list<string > spellCooldowns;

        map<Unit*, list<string >> auras;
        map<Unit*, uint32> dispels;

        bool targetIsCastingNonMeleeSpell;
    };

}
