#pragma once

#include "../server/game/Miscellaneous/Language.h"
#include "../common/Logging/Log.h"
#include "../server/game/World/World.h"
#include "../server/game/Globals/ObjectMgr.h"
#include "../server/game/Server/WorldSession.h"
#include "../common/Configuration/Config.h"
#include "../common/Utilities/Util.h"
#include "../server/game/Accounts/AccountMgr.h"
#include "../server/worldserver/CommandLine/CliRunnable.h"
#include "../server/game/Maps/MapManager.h"
#include "../server/game/Entities/Player/Player.h"
#include "../server/game/Chat/Chat.h"
#include "../server/database/Database/DatabaseEnv.h"
#include <openssl/opensslv.h>
#include <openssl/crypto.h>

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestPath.h>
#include <stdexcept>

#include <stdio.h>
#include <iostream>

#include <list>
#include "../common/Define.h"

#include <stdexcept>

#include "../../plugins/playerbot/playerbotDefs.h"
