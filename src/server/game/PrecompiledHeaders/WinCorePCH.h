//add here most rarely modified headers to speed up debug build compilation
#include "..\Server\WorldSocket.h"                                    // must be first to make ACE happy with ACE includes in it
#include "..\..\shared\Common.h"

#include "..\Maps\MapManager.h"
#include "..\..\shared\Logging\Log.h"
#include "..\Globals\ObjectAccessor.h"
#include "..\Entities\Object\ObjectDefines.h"
#include "..\..\shared\Database/SQLStorage.h"
#include "..\Protocol\Opcodes.h"
#include "..\Miscellaneous\SharedDefines.h"
#include "..\Globals\ObjectMgr.h"

#include "ScriptPCH.h"