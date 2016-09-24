#include "../pchdef.h"
#include "PlayerbotMgr.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotAI.h"
#include "ChatHelper.h"

PlayerbotSecurity::PlayerbotSecurity(Player* const bot) : bot(bot)
{
    if (bot)
        account = sObjectMgr->GetPlayerAccountIdByGUID(bot->GetGUID());
}

PlayerbotSecurityLevel PlayerbotSecurity::LevelFor(Player* from, DenyReason* reason, bool ignoreGroup)
{
    if (from->GetSession()->GetSecurity() >= SEC_GAMEMASTER)
        return PLAYERBOT_SECURITY_ALLOW_ALL;

    if (from->GetPlayerbotAI())
    {
        if (reason) *reason = PLAYERBOT_DENY_IS_BOT;
        return PLAYERBOT_SECURITY_DENY_ALL;
    }

    if (bot->GetPlayerbotAI()->IsOpposing(from))
    {
        if (reason) *reason = PLAYERBOT_DENY_OPPOSING;
        return PLAYERBOT_SECURITY_DENY_ALL;
    }

    if (sPlayerbotAIConfig.IsInRandomAccountList(account))
    {
        if (bot->GetPlayerbotAI()->IsOpposing(from))
        {
            if (reason) *reason = PLAYERBOT_DENY_OPPOSING;
            return PLAYERBOT_SECURITY_DENY_ALL;
        }

        Group* group = from->GetGroup();
        if (group)
        {
            for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
            {
                Player* player = gref->GetSource();
                if (player == bot && !ignoreGroup)
                    return PLAYERBOT_SECURITY_ALLOW_ALL;
            }
        }

        if ((int)bot->getLevel() - (int)from->getLevel() > 5)
        {
            if (reason) *reason = PLAYERBOT_DENY_LOW_LEVEL;
            return PLAYERBOT_SECURITY_TALK;
        }

        if (bot->GetMapId() != from->GetMapId() || bot->GetDistance(from) > sPlayerbotAIConfig.whisperDistance)
        {
            if (!bot->GetGuildId() || bot->GetGuildId() != from->GetGuildId())
            {
                if (reason) *reason = PLAYERBOT_DENY_FAR;
                return PLAYERBOT_SECURITY_TALK;
            }
        }

        int botGS = (int)bot->GetPlayerbotAI()->GetEquipGearScore(bot, false, false);
        int fromGS = (int)bot->GetPlayerbotAI()->GetEquipGearScore(from, false, false);
        if (botGS && bot->getLevel() > 15 && (100 * (botGS - fromGS) / botGS) >= 20)
        {
            if (reason) *reason = PLAYERBOT_DENY_GEARSCORE;
            return PLAYERBOT_SECURITY_TALK;
        }

        if (bot->isDead())
        {
            if (reason) *reason = PLAYERBOT_DENY_DEAD;
            return PLAYERBOT_SECURITY_TALK;
        }

        group = bot->GetGroup();
        if (!group)
        {
            if (reason) *reason = PLAYERBOT_DENY_INVITE;
            return PLAYERBOT_SECURITY_INVITE;
        }

        for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
        {
            Player* player = gref->GetSource();
            if (player == from)
                return PLAYERBOT_SECURITY_ALLOW_ALL;
        }

        if (group->IsFull())
        {
            if (reason) *reason = PLAYERBOT_DENY_FULL_GROUP;
            return PLAYERBOT_SECURITY_TALK;
        }

        if (reason) *reason = PLAYERBOT_DENY_INVITE;
        return PLAYERBOT_SECURITY_INVITE;
    }

    return PLAYERBOT_SECURITY_ALLOW_ALL;
}

bool PlayerbotSecurity::CheckLevelFor(PlayerbotSecurityLevel level, bool silent, Player* from, bool ignoreGroup)
{
    DenyReason reason = PLAYERBOT_DENY_NONE;
    PlayerbotSecurityLevel realLevel = LevelFor(from, &reason, ignoreGroup);
    if (realLevel >= level)
        return true;

    if (silent || from->GetPlayerbotAI())
        return false;

    Player* master = bot->GetPlayerbotAI()->GetMaster();
    if (master && bot->GetPlayerbotAI() && bot->GetPlayerbotAI()->IsOpposing(master) && master->GetSession()->GetSecurity() < SEC_GAMEMASTER)
        return false;

    ostringstream out;
    switch (realLevel)
    {
    case PLAYERBOT_SECURITY_DENY_ALL:
        out << "I'm kind of busy now";
        break;
    case PLAYERBOT_SECURITY_TALK:
        switch (reason)
        {
        case PLAYERBOT_DENY_NONE:
            out << "I'll do it later";
            break;
        case PLAYERBOT_DENY_LOW_LEVEL:
            out << "You are too low level: |cffff0000" << (uint32)from->getLevel() << "|cffffffff/|cff00ff00" << (uint32)bot->getLevel();
            break;
        case PLAYERBOT_DENY_GEARSCORE:
            {
                int botGS = (int)bot->GetPlayerbotAI()->GetEquipGearScore(bot, false, false);
                int fromGS = (int)bot->GetPlayerbotAI()->GetEquipGearScore(from, false, false);
                out << "Your gearscore is too low: |cffff0000" << fromGS << "|cffffffff/|cff00ff00" << botGS;
            }
            break;
        case PLAYERBOT_DENY_NOT_YOURS:
            out << "I have a master already";
            break;
        case PLAYERBOT_DENY_IS_BOT:
            out << "You are a bot";
            break;
        case PLAYERBOT_DENY_OPPOSING:
            out << "You are the enemy";
            break;
        case PLAYERBOT_DENY_DEAD:
            out << "I'm dead. Will do it later";
            break;
        case PLAYERBOT_DENY_INVITE:
            out << "Invite me to your group first";
            break;
        case PLAYERBOT_DENY_FAR:
            {
                out << "I am too far away";

                uint32 area = bot->GetAreaId();
                if (area)
                {
					const AreaTableEntry* entry = sAreaTableStore.LookupEntry(area);
                    if (entry)
                    {
                        out << " |cffffffff(|cffff0000" << entry->area_name[0] << "|cffffffff)";
                    }
                }
            }
            break;
        case PLAYERBOT_DENY_FULL_GROUP:
            out << "I am in a full group. Will do it later";
            break;
        default:
            out << "I can't do that";
            break;
        }
        break;
    case PLAYERBOT_SECURITY_INVITE:
        out << "Invite me to your group first";
        break;
    }

	bot->Whisper(out.str(), LANG_UNIVERSAL, from);
    return false;
}
