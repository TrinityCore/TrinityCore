#pragma once

std::vector<std::string> split(const std::string &s, char delim);
#ifndef WIN32
int strcmpi(std::string s1, std::string s2);
#endif

#include "../Spell.h"
#include "../../game/Server/WorldPacket.h"
#include "../Loot/LootMgr.h"
#include "../Entities/Creature/GossipDef.h"
#include "../Chat/Chat.h"
#include "../../common/Common.h"
#include "../World/World.h"
#include "../Spells/SpellMgr.h"
#include "../Globals/ObjectMgr.h"
#include "../Entities/Unit/Unit.h"
#include "../Miscellaneous/SharedDefines.h"
#include "../Movement/MotionMaster.h"
#include "../Spells/Auras/SpellAuras.h"
#include "../Guilds/Guild.h"
#include "../Groups/Group.h"
#include "../../game/Accounts/AccountMgr.h"
#include "../../game/Globals/ObjectMgr.h"

#include "playerbotDefs.h"
#include "PlayerbotAIAware.h"
#include "PlayerbotMgr.h"
#include "RandomPlayerbotMgr.h"
#include "ChatHelper.h"
#include "PlayerbotAI.h"
