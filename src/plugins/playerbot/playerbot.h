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
#include "Group.h"
#include "AccountMgr.h"
#include "Random.h"
#include "Item.h"
#include "Creature.h"
#include "WorldSession.h"
#include "GameObject.h"
#include "DBCStores.h"
#include "DatabaseEnv.h"
#include "Bag.h"

#include "playerbotDefs.h"
#include "PlayerbotAIAware.h"
#include "PlayerbotMgr.h"
#include "RandomPlayerbotMgr.h"
#include "ChatHelper.h"
#include "PlayerbotAI.h"
