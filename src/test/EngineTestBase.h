#pragma once;

#include "../game/playerbot/strategy/Action.h"
#include "../game/playerbot/strategy/ActionBasket.h"
#include "../game/playerbot/strategy/Queue.h"
#include "../game/playerbot/strategy/Trigger.h"
#include "../game/playerbot/strategy/Engine.h"

#include "MockPlayerbotAIBase.h"

using namespace ai;

class EngineTestBase : public CPPUNIT_NS::TestFixture
{
public:
    virtual void setUp();
    virtual void tearDown();

private:
	void va_generic(void (EngineTestBase::*callback)(const char*), va_list vl);

protected:
    template <class T>
    void set(string  name, T value) { context->GetValue<T>(name)->Set(value); }
    template <class T>
    void set(string  name, string  param, T value) { context->GetValue<T>(name, param)->Set(value); }

protected:
	virtual void setupEngine(AiObjectContext* AiObjectContext, ...);
	void setupEngineCallback(const char*  name);
	void tick();
	void assertActions(string  expected);

	void tickWithNoTarget();
	void spellUnavailable(string  spell);
	void tickWithSpellUnavailable(string  spell);
	void tickWithSpellAvailable(string  spell);
	void spellAvailable(string  spell);
	void addAura(string  spell);
	void addTargetAura(string  spell);
	void removeTargetAura(string  spell);
	void addPartyAura(string  spell);
	void removePartyAura(string  spell);
	void removeAura(string  spell);
	void tickOutOfSpellRange();
	void tickOutOfMeleeRange();
	void tickInMeleeRange();
	void tickInSpellRange();
	void tickWithNoAggro();
	void tickWithRage(int amount);
	void tickWithEnergy(int amount);
	void tickWithAttackerCount(int count);
	void tickWithMyAttackerCount(int count);
	void tickWithLowHealth(int amount);
	void tickWithPartyLowHealth(int amount);
	void tickWithAuraToDispel(uint32 type);
	void tickWithPartyAuraToDispel(uint32 type);
	void tickWithTargetAuraToDispel(uint32 type);
    void tickBehindTarget();
	void lowHealth(int amount);
	void lowMana(int amount);
	void healthRestored();
	void tickWithComboPoints(int amount);
	void tickWithTargetIsCastingNonMeleeSpell();
	void tickWithBalancePercent(int percent);
	void tickWithNoPet();
	void tickWithPetLowHealth(int amount);
    void tickWithPetDead();
	void tickWithLowMana(int amount);
	void tickWithTargetLowHealth(int amount);
	void tickWithTargetIsMoving();
	void tickWithLootAvailable();
	void tickWithNoFood();
	void tickWithNoDrink();
	void itemAvailable(string  item, int amount);
	void tickWithDeadPartyMember();
    void tickWithCcTarget(string   spell);
    void tickWhileSwimming();
    void setInMeleeRange();
    void tickWithAoeHeal(string type, int amount = 2);
    void tickWithItemForSpell(string spell);
    void tickWithEnemyHealerIsCastingInterruptableSpell(string interrupt);

protected:
    MockPlayerbotAIBase *ai;
    Engine *engine;
    AiObjectContext *context;
};
