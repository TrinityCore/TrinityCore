#pragma once
using namespace std;

namespace ai
{
    class MockTargetValue : public ManualSetValue<Unit*>, public Qualified
    {
    public:
        MockTargetValue(PlayerbotAI* const ai) : ManualSetValue<Unit*>(ai, NULL) {}
    };

    class MockStatsValue : public ManualSetValue<uint8>, public Qualified
    {
    public:
        MockStatsValue(PlayerbotAI* const ai) : ManualSetValue<uint8>(ai, 0) {}
    };

    class MockFloatValue : public ManualSetValue<float>, public Qualified
    {
    public:
        MockFloatValue(PlayerbotAI* const ai) : ManualSetValue<float>(ai, 0) {}
    };

    class MockStringValue : public ManualSetValue<string>, public Qualified
    {
    public:
        MockStringValue(PlayerbotAI* const ai) : ManualSetValue<string>(ai, "") {}
    };

    class MockItemListValue : public ManualSetValue<list<Item*> >, public Qualified
    {
    public:
        MockItemListValue(PlayerbotAI* const ai) : ManualSetValue<list<Item*> >(ai, list<Item*>()) {}
    };

    class MockItemValue : public ManualSetValue<Item*>, public Qualified
    {
    public:
        MockItemValue(PlayerbotAI* const ai) : ManualSetValue<Item*>(ai, NULL) {}
    };

    class MockLogicalValue : public ManualSetValue<bool>, public Qualified
    {
    public:
        MockLogicalValue(PlayerbotAI* const ai) : ManualSetValue<bool>(ai, false) {}
    };

    class AlwaysTrueValue : public BoolCalculatedValue, public Qualified
    {
    public:
        AlwaysTrueValue(PlayerbotAI* const ai) : BoolCalculatedValue(ai) {}
        virtual bool Calculate() { return true; }
    };

    class MockPartyMemberWithoutAuraValue : public UnitCalculatedValue, public Qualified
    {
    public:
        MockPartyMemberWithoutAuraValue(PlayerbotAI* const ai) : UnitCalculatedValue(ai) {}

        virtual Unit* Calculate()
        {
            string  spell = qualifier;
            Unit* target = MockedTargets::GetPartyMember();
            return ai->HasAura(spell, target) ? NULL : target;
        }
    };

    class MockPartyMemberToHeal : public UnitCalculatedValue
    {
    public:
        MockPartyMemberToHeal(PlayerbotAI* const ai) : UnitCalculatedValue(ai) {}

        virtual Unit* Calculate()
        {
            Unit* target = MockedTargets::GetPartyMember();
            return AI_VALUE2(uint8, "health", "party member to heal") < 100.0f ? target : NULL;
        }
    };

    class MockPartyMemberToDispel : public UnitCalculatedValue, public Qualified
    {
    public:
        MockPartyMemberToDispel(PlayerbotAI* const ai) : UnitCalculatedValue(ai) {}

        virtual Unit* Calculate()
        {
            uint32 dispelType = atoi(qualifier.c_str());
            Unit* target = MockedTargets::GetPartyMember();
            return ai->HasAuraToDispel(target, dispelType) ? target : NULL;
        }
    };

    class MockUnitListValue : public ManualSetValue<list<ObjectGuid>>
    {
    public:
        MockUnitListValue(PlayerbotAI* const ai) : ManualSetValue<list<ObjectGuid>>(ai, list<ObjectGuid>()) {}
    };

    class MockSpellIdValue : public CalculatedValue<uint32>, public Qualified
    {
    public:
        MockSpellIdValue(PlayerbotAI* ai) : CalculatedValue<uint32>(ai) {}

    public:
        virtual uint32 Calculate() { return 1; }

    };

    class MockValueContext : public NamedObjectContext<UntypedValue>
    {
    public:
        MockValueContext() : NamedObjectContext<UntypedValue>()
        {
            creators["attacker without aura"] = &MockValueContext::mock;
            creators["party member without aura"] = &MockValueContext::party_member_without_aura;
            creators["party member to heal"] = &MockValueContext::party_member_to_heal;
            creators["party member to dispel"] = &MockValueContext::party_member_to_dispel;
            creators["party member to resurrect"] = &MockValueContext::mock;
            creators["current target"] = &MockValueContext::mock;
            creators["old target"] = &MockValueContext::mock;
            creators["self target"] = &MockValueContext::mock;
            creators["master target"] = &MockValueContext::mock;
            creators["line target"] = &MockValueContext::mock;
            creators["tank target"] = &MockValueContext::mock;
            creators["dps target"] = &MockValueContext::mock;
            creators["cc target"] = &MockValueContext::mock;
            creators["current cc target"] = &MockValueContext::mock;
            creators["pet target"] = &MockValueContext::mock;
            creators["grind target"] = &MockValueContext::mock;
            creators["least hp target"] = &MockValueContext::mock;
            creators["rti target"] = &MockValueContext::mock;
            creators["duel target"] = &MockValueContext::mock;
            creators["enemy player target"] = &MockValueContext::mock;
            creators["enemy healer target"] = &MockValueContext::mock;

            creators["health"] = &MockValueContext::stats;
            creators["rage"] = &MockValueContext::stats;
            creators["energy"] = &MockValueContext::stats;
            creators["mana"] = &MockValueContext::stats;
            creators["combo"] = &MockValueContext::stats;
            creators["dead"] = &MockValueContext::logical;
            creators["has mana"] = &MockValueContext::logical;
            creators["combat"] = &MockValueContext::logical;

            creators["attacker count"] = &MockValueContext::stats;
            creators["my attacker count"] = &MockValueContext::stats;
            creators["has aggro"] = &MockValueContext::logical;
            creators["balance"] = &MockValueContext::stats;
            creators["mounted"] = &MockValueContext::logical;
            creators["has available loot"] = &MockValueContext::logical;
            creators["distance"] = &MockValueContext::floating;
            creators["moving"] = &MockValueContext::logical;
            creators["swimming"] = &MockValueContext::logical;
            creators["behind"] = &MockValueContext::logical;
            creators["facing"] = &MockValueContext::logical;
            creators["item count"] = &MockValueContext::stats;
            creators["inventory items"] = &MockValueContext::itemlist;
            creators["item for spell"] = &MockValueContext::item;
            creators["spell cast useful"] = &MockValueContext::always_true;
            creators["can loot"] = &MockValueContext::logical;
            creators["invalid target"] = &MockValueContext::logical;

            creators["possible targets"] = &MockValueContext::units;
            creators["nearest adds"] = &MockValueContext::units;
            creators["attackers"] = &MockValueContext::units;
            creators["has totem"] = &MockValueContext::logical;
            creators["aoe heal"] = &MockValueContext::stats;

            creators["rti"] = &MockValueContext::str;
            creators["spell id"] = &MockValueContext::spell_id;
            creators["threat"] = &MockValueContext::stats;
            creators["bag space"] = &MockValueContext::stats;
            creators["speed"] = &MockValueContext::stats;
        }

    private:
        static UntypedValue* always_true(PlayerbotAI* ai) { return new AlwaysTrueValue(ai); }
        static UntypedValue* stats(PlayerbotAI* ai) { return new MockStatsValue(ai); }
        static UntypedValue* itemlist(PlayerbotAI* ai) { return new MockItemListValue(ai); }
        static UntypedValue* item(PlayerbotAI* ai) { return new MockItemValue(ai); }
        static UntypedValue* floating(PlayerbotAI* ai) { return new MockFloatValue(ai); }
        static UntypedValue* str(PlayerbotAI* ai) { return new MockStringValue(ai); }
        static UntypedValue* logical(PlayerbotAI* ai) { return new MockLogicalValue(ai); }
        static UntypedValue* mock(PlayerbotAI* ai) { return new MockTargetValue(ai); }
        static UntypedValue* party_member_without_aura(PlayerbotAI* ai) { return new MockPartyMemberWithoutAuraValue(ai); }
        static UntypedValue* party_member_to_heal(PlayerbotAI* ai) { return new MockPartyMemberToHeal(ai); }
        static UntypedValue* party_member_to_dispel(PlayerbotAI* ai) { return new MockPartyMemberToDispel(ai); }
        static UntypedValue* units(PlayerbotAI* ai) { return new MockUnitListValue(ai); }
        static UntypedValue* spell_id(PlayerbotAI* ai) { return new MockSpellIdValue(ai); }
    };

    class AiObjectContextWrapper : public AiObjectContext
    {
    public:
        AiObjectContextWrapper(PlayerbotAI* const ai, AiObjectContext *realContext) :
          AiObjectContext(ai), realContext(realContext)
          {
              GetValue<Unit*>("self target")->Set(MockedTargets::GetSelf());
              GetValue<Unit*>("master target")->Set(MockedTargets::GetMaster());
              GetValue<Unit*>("line target")->Set(MockedTargets::GetLineTarget());
              GetValue<Unit*>("tank target")->Set(MockedTargets::GetTargetForTank());
              GetValue<Unit*>("dps target")->Set(MockedTargets::GetTargetForDps());
              GetValue<Unit*>("current cc target")->Set(NULL);
              GetValue<Unit*>("current target")->Set(MockedTargets::GetCurrentTarget());
              GetValue<Unit*>("old target")->Set(MockedTargets::GetCurrentTarget());
              GetValue<Unit*>("pet target")->Set(MockedTargets::GetPet());
              GetValue<Unit*>("enemy player target")->Set(MockedTargets::GetEnemyPlayer());
              GetValue<Unit*>("attacker without aura")->Set(NULL);

              GetValue<uint8>("health", "self target")->Set(100);
              GetValue<uint8>("health", "current target")->Set(100);
              GetValue<uint8>("health", "pet target")->Set(100);
              GetValue<uint8>("health", "party member to heal")->Set(100);
              GetValue<uint8>("health", "party member to resurrect")->Set(100);

              GetValue<bool>("dead", "current target")->Set(false);
              GetValue<bool>("dead", "self target")->Set(false);

              GetValue<uint8>("mana", "self target")->Set(100);
              GetValue<uint8>("mana", "current target")->Set(100);
              GetValue<uint8>("mana", "pet target")->Set(100);
              GetValue<uint8>("mana", "party member to heal")->Set(100);
              GetValue<uint8>("mana", "party member to resurrect")->Set(100);

              GetValue<bool>("has mana", "self target")->Set(true);
              GetValue<bool>("has mana", "current target")->Set(true);
              GetValue<bool>("has mana", "pet target")->Set(true);
              GetValue<bool>("has mana", "party member to heal")->Set(true);
              GetValue<bool>("has mana", "party member to resurrect")->Set(true);

              GetValue<bool>("combat", "self target")->Set(false);

              GetValue<uint8>("attacker count")->Set(1);
              GetValue<uint8>("my attacker count")->Set(1);
              GetValue<uint8>("balance")->Set(100);
              GetValue<float>("distance", "current target")->Set(15.0f);
              GetValue<float>("distance", "loot target")->Set(0.0f);

              GetValue<bool>("has aggro", "current target")->Set(true);
              GetValue<bool>("can loot")->Set(false);

              GetValue<bool>("facing", "current target")->Set(true);

              list<Item*> items; items.push_back((Item*)(void*)0x01);
              GetValue<list<Item*> >("inventory items", "drink")->Set(items);
              GetValue<list<Item*> >("inventory items", "food")->Set(items);

              GetValue<uint8>("aoe heal", "low")->Set(0);
              GetValue<uint8>("aoe heal", "medium")->Set(0);
              GetValue<uint8>("aoe heal", "critical")->Set(0);

              GetValue<uint8>("threat")->Set(0);
              GetValue<uint8>("bag space")->Set(0);
              GetValue<uint8>("speed", "current target")->Set(80);
          }

    public:
        virtual UntypedValue* GetUntypedValue(string  name)
        {
            UntypedValue* value = mockValueContext.create(name, ai);
            UntypedValue* real = realContext->GetUntypedValue(name);
            if (!real)
            {
                std::cout << "\n===\n";
                cout << "Value " << name << " not found in context";
                std::cout << "\n===\n";

                CPPUNIT_ASSERT(false);
            }
            return value ? value : real;
        }
        virtual Strategy* GetStrategy(string  name) { return realContext->GetStrategy(name); }
        virtual set<string> GetSiblingStrategy(string name) { return realContext->GetSiblingStrategy(name); }
        virtual Trigger* GetTrigger(string  name) { return realContext->GetTrigger(name); }
        virtual Action* GetAction(string  name) { return realContext->GetAction(name); }
        virtual void Update()
        {
            mockValueContext.Update();
            realContext->Update();
        }

    private:
        AiObjectContext *realContext;
        MockValueContext mockValueContext;
    };

}
