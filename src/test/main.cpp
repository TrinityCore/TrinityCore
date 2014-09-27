#include "pch.h"
#include "../../plugins/playerbot/PlayerbotAIConfig.h"

WorldDatabaseWorkerPool WorldDatabase;                      ///< Accessor to the world database
CharacterDatabaseWorkerPool CharacterDatabase;              ///< Accessor to the character database
LoginDatabaseWorkerPool LoginDatabase;                      ///< Accessor to the realm/login database
uint32 realmID;                                             ///< Id of the realm

int main()
{
  sPlayerbotAIConfig.Initialize();
  sPlayerbotAIConfig.enabled = true;
  sPlayerbotAIConfig.globalCoolDown = 1000;
  sPlayerbotAIConfig.reactDelay = 100;
  sPlayerbotAIConfig.sightDistance = 40.0f;
  sPlayerbotAIConfig.spellDistance = 25.0f;
  sPlayerbotAIConfig.reactDistance = 100.0f;
  sPlayerbotAIConfig.grindDistance = 50.0f;
  sPlayerbotAIConfig.meleeDistance = ATTACK_DISTANCE;
  sPlayerbotAIConfig.followDistance = ATTACK_DISTANCE;
  sPlayerbotAIConfig.tooCloseDistance = ATTACK_DISTANCE;
  sPlayerbotAIConfig.contactDistance = CONTACT_DISTANCE;
  sPlayerbotAIConfig.lootDistance = 20.0f;
  sPlayerbotAIConfig.criticalHealth = 25;
  sPlayerbotAIConfig.lowHealth = 40;
  sPlayerbotAIConfig.mediumHealth = 60;
  sPlayerbotAIConfig.almostFullHealth = 80;
  sPlayerbotAIConfig.lowMana = 40;
  sPlayerbotAIConfig.mediumMana = 60;
  sPlayerbotAIConfig.iterationsPerTick = 10;
  sPlayerbotAIConfig.randomChangeMultiplier = 1;

  // Create the event manager and test controller
  CPPUNIT_NS::TestResult controller;

  // Add a listener that colllects test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );

  // Add a listener that print dots as test run.
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );

  // Add the top suite to the test runner
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );

  // Print test in a compiler compatible format.
  CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
  outputter.write();

  return result.wasSuccessful() ? 0 : 1;
}
