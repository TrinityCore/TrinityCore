//add here most rarely modified headers to speed up debug build compilation
#include "Server/WorldSocket.h"                                    // must be first to make ACE happy with ACE includes in it
#include "Common.h"

#include "MapManager.h"
#include "Logging/Log.h"
#include "ObjectAccessor.h"
#include "ObjectDefines.h"
#include "Database/SQLStorage.h"
#include "Opcodes.h"
#include "SharedDefines.h"
#include "ObjectMgr.h"
