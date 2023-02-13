#pragma once
#include "Category.h"

using namespace std;

namespace ahbot
{
    class TradeSkill : public Trade
    {
    public:
        TradeSkill(uint32 skill) : Trade(), skill(skill) {}

    public:
        virtual bool Contains(ItemPrototype const* proto);
        virtual string GetName();
        virtual string GetLabel();
        virtual uint32 GetSkillId() { return skill; }

    private:
        bool ContainsInternal(ItemPrototype const* proto);
        bool IsCraftedBySpell(ItemPrototype const* proto, uint32 spellId);
        bool IsCraftedBy(ItemPrototype const* proto, uint32 craftId);
        uint32 skill;
        set<uint32> itemCache;
    };

};
