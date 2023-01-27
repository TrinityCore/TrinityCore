#pragma once

std::vector<std::string> split(const std::string &s, char delim);
#ifndef WIN32
int strcmpi(std::string s1, std::string s2);
#endif

#include "Spell.h"
#include "WorldPacket.h"
#include "LootMgr.h"
#include "GossipDef.h"
#include "Chat.h"
#include "Common.h"
#include "World.h"
#include "SpellMgr.h"
#include "ObjectMgr.h"
#include "Unit.h"
#include "SharedDefines.h"
#include "MotionMaster.h"
#include "SpellAuras.h"
#include "Guild.h"

#include "playerbotDefs.h"
#include "PlayerbotAIAware.h"
#include "PlayerbotMgr.h"
#include "RandomPlayerbotMgr.h"
#include "ChatHelper.h"
#include "PlayerbotAI.h"

#if MAX_EXPANSION == 1
    #define MANGOSBOT_ONE
#elif MAX_EXPANSION == 2
    #define MANGOSBOT_TWO
#else
    #define MANGOSBOT_ZERO
#endif
