/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CreatureTextMgr.h"
#include "CreatureTextMgrImpl.h"
#include "CellImpl.h"
#include "Chat.h"
#include "ChatTextBuilder.h"
#include "Common.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "LanguageMgr.h"
#include "Log.h"
#include "MiscPackets.h"
#include "ObjectMgr.h"
#include "World.h"

CreatureTextMgr::CreatureTextMgr() = default;
CreatureTextMgr::~CreatureTextMgr() = default;

CreatureTextMgr* CreatureTextMgr::instance()
{
    static CreatureTextMgr instance;
    return &instance;
}

void CreatureTextMgr::LoadCreatureTexts()
{
    uint32 oldMSTime = getMSTime();

    mTextMap.clear(); // for reload case
    //all currently used temp texts are NOT reset

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEXT);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 ceature texts. DB table `creature_text` is empty.");

        return;
    }

    uint32 textCount = 0;

    do
    {
        Field* fields = result->Fetch();
        CreatureTextEntry temp;

        temp.creatureId      = fields[0].GetUInt32();
        temp.groupId         = fields[1].GetUInt8();
        temp.id              = fields[2].GetUInt8();
        temp.text            = fields[3].GetString();
        temp.type            = ChatMsg(fields[4].GetUInt8());
        temp.lang            = Language(fields[5].GetUInt8());
        temp.probability     = fields[6].GetFloat();
        temp.emote           = Emote(fields[7].GetUInt32());
        temp.duration        = fields[8].GetUInt32();
        temp.sound           = fields[9].GetUInt32();
        temp.SoundPlayType   = SoundKitPlayType(fields[10].GetUInt8());
        temp.BroadcastTextId = fields[11].GetUInt32();
        temp.TextRange       = CreatureTextRange(fields[12].GetUInt8());

        if (temp.sound)
        {
            if (!sSoundKitStore.LookupEntry(temp.sound))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {} in table `creature_text` has Sound {} but sound does not exist.", temp.creatureId, temp.groupId, temp.sound);
                temp.sound = 0;
            }
        }

        if (temp.SoundPlayType >= SoundKitPlayType::Max)
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {} in table `creature_text` has PlayType {} but does not exist.", temp.creatureId, temp.groupId, uint32(temp.SoundPlayType));
            temp.SoundPlayType = SoundKitPlayType::Normal;
        }

        if (temp.lang != LANG_UNIVERSAL && !sLanguageMgr->IsLanguageExist(temp.lang))
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {} in table `creature_text` using Language {} but Language does not exist.", temp.creatureId, temp.groupId, uint32(temp.lang));
            temp.lang = LANG_UNIVERSAL;
        }

        if (temp.type >= MAX_CHAT_MSG_TYPE)
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {} in table `creature_text` has Type {} but this Chat Type does not exist.", temp.creatureId, temp.groupId, uint32(temp.type));
            temp.type = CHAT_MSG_SAY;
        }

        if (temp.emote)
        {
            if (!sEmotesStore.LookupEntry(temp.emote))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {} in table `creature_text` has Emote {} but emote does not exist.", temp.creatureId, temp.groupId, uint32(temp.emote));
                temp.emote = EMOTE_ONESHOT_NONE;
            }
        }

        if (temp.BroadcastTextId)
        {
            if (!sBroadcastTextStore.LookupEntry(temp.BroadcastTextId))
            {
                TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {}, Id {} in table `creature_text` has non-existing or incompatible BroadcastTextId {}.", temp.creatureId, temp.groupId, temp.id, temp.BroadcastTextId);
                temp.BroadcastTextId = 0;
            }
        }

        if (temp.TextRange > TEXT_RANGE_PERSONAL)
        {
            TC_LOG_ERROR("sql.sql", "CreatureTextMgr: Entry {}, Group {}, Id {} in table `creature_text` has incorrect TextRange {}.", temp.creatureId, temp.groupId, temp.id, temp.TextRange);
            temp.TextRange = TEXT_RANGE_NORMAL;
        }

        // add the text into our entry's group
        mTextMap[temp.creatureId][temp.groupId].push_back(temp);

        ++textCount;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature texts for {} creatures in {} ms", textCount, mTextMap.size(), GetMSTimeDiffToNow(oldMSTime));
}

void CreatureTextMgr::LoadCreatureTextLocales()
{
    uint32 oldMSTime = getMSTime();

    mLocaleTextMap.clear(); // for reload case

    QueryResult result = WorldDatabase.Query("SELECT CreatureId, GroupId, ID, Locale, Text FROM creature_text_locale");

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureId           = fields[0].GetUInt32();
        uint32 groupId              = fields[1].GetUInt8();
        uint32 id                   = fields[2].GetUInt8();
        std::string_view localeName = fields[3].GetStringView();

        LocaleConstant locale    = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        CreatureTextLocale& data = mLocaleTextMap[CreatureTextId(creatureId, groupId, id)];
        ObjectMgr::AddLocaleString(fields[4].GetStringView(), locale, data.Text);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature localized texts in {} ms", uint32(mLocaleTextMap.size()), GetMSTimeDiffToNow(oldMSTime));
}

uint32 CreatureTextMgr::SendChat(Creature* source, uint8 textGroup, WorldObject const* whisperTarget /*= nullptr*/, ChatMsg msgType /*= CHAT_MSG_ADDON*/, Language language /*= LANG_ADDON*/, CreatureTextRange range /*= TEXT_RANGE_NORMAL*/, uint32 sound /*= 0*/, SoundKitPlayType playType /*= SoundKitPlayType::Normal*/, Team team /*= TEAM_OTHER*/, bool gmOnly /*= false*/, Player* srcPlr /*= nullptr*/)
{
    if (!source)
        return 0;

    CreatureTextMap::const_iterator sList = mTextMap.find(source->GetEntry());
    if (sList == mTextMap.end())
    {
        TC_LOG_ERROR("sql.sql.creaturetextmgr", "CreatureTextMgr: Could not find Text for Creature {} ({}) in 'creature_text' table. Ignoring.", source->GetName(), source->GetGUID().ToString());
        return 0;
    }

    CreatureTextHolder const& textHolder = sList->second;
    CreatureTextHolder::const_iterator itr = textHolder.find(textGroup);
    if (itr == textHolder.end())
    {
        TC_LOG_ERROR("sql.sql.creaturetextmgr", "CreatureTextMgr: Could not find TextGroup {} for Creature {} ({}) in 'creature_text' table. Ignoring.", uint32(textGroup), source->GetName(), source->GetGUID().ToString());
        return 0;
    }

    CreatureTextGroup const& textGroupContainer = itr->second;  //has all texts in the group
    CreatureTextRepeatIds repeatGroup = source->GetTextRepeatGroup(textGroup);//has all textIDs from the group that were already said
    CreatureTextGroup tempGroup;//will use this to talk after sorting repeatGroup

    for (CreatureTextGroup::const_iterator giter = textGroupContainer.begin(); giter != textGroupContainer.end(); ++giter)
        if (std::find(repeatGroup.begin(), repeatGroup.end(), giter->id) == repeatGroup.end())
            tempGroup.push_back(*giter);

    if (tempGroup.empty())
    {
        source->ClearTextRepeatGroup(textGroup);
        tempGroup = textGroupContainer;
    }

    auto iter = Trinity::Containers::SelectRandomWeightedContainerElement(tempGroup, [](CreatureTextEntry const& t) -> double
    {
        return t.probability;
    });

    ChatMsg finalType = (msgType == CHAT_MSG_ADDON) ? iter->type : msgType;
    Language finalLang = (language == LANG_ADDON) ? iter->lang : language;
    uint32 finalSound = iter->sound;
    SoundKitPlayType finalPlayType = iter->SoundPlayType;
    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(iter->BroadcastTextId);
    if (sound)
    {
        finalSound = sound;
        finalPlayType = playType;
    }
    else if (bct)
        if (uint32 broadcastTextSoundId = bct->SoundKitID[source->GetGender() == GENDER_FEMALE ? 1 : 0])
            finalSound = broadcastTextSoundId;

    if (range == TEXT_RANGE_NORMAL)
        range = iter->TextRange;

    Unit* finalSource = source;
    if (srcPlr)
        finalSource = srcPlr;

    if (srcPlr)
    {
        Trinity::CreatureTextTextBuilder builder(source, finalSource, finalSource->GetGender(), finalType, iter->groupId, iter->id, finalLang, whisperTarget, iter->BroadcastTextId, iter->emote, finalSound, finalPlayType, bct ? bct->ConditionID : 0);
        SendChatPacket(finalSource, builder, finalType, whisperTarget, range, team, gmOnly);
    }
    else
    {
        Trinity::CreatureTextTextBuilder builder(finalSource, finalSource, finalSource->GetGender(), finalType, iter->groupId, iter->id, finalLang, whisperTarget, iter->BroadcastTextId, iter->emote, finalSound, finalPlayType, bct ? bct->ConditionID : 0);
        SendChatPacket(finalSource, builder, finalType, whisperTarget, range, team, gmOnly);
    }

    source->SetTextRepeatId(textGroup, iter->id);
    return iter->duration;
}

float CreatureTextMgr::GetRangeForChatType(ChatMsg msgType)
{
    float dist = sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY);
    switch (msgType)
    {
        case CHAT_MSG_MONSTER_YELL:
            dist = sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL);
            break;
        case CHAT_MSG_MONSTER_EMOTE:
        case CHAT_MSG_RAID_BOSS_EMOTE:
            dist = sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE);
            break;
        default:
            break;
    }

    return dist;
}

bool CreatureTextMgr::TextExist(uint32 sourceEntry, uint8 textGroup) const
{
    if (!sourceEntry)
        return false;

    CreatureTextMap::const_iterator sList = mTextMap.find(sourceEntry);
    if (sList == mTextMap.end())
    {
        TC_LOG_DEBUG("entities.unit", "CreatureTextMgr::TextExist: Could not find Text for Creature (entry {}) in 'creature_text' table.", sourceEntry);
        return false;
    }

    CreatureTextHolder const& textHolder = sList->second;
    CreatureTextHolder::const_iterator itr = textHolder.find(textGroup);
    if (itr == textHolder.end())
    {
        TC_LOG_DEBUG("entities.unit", "CreatureTextMgr::TextExist: Could not find TextGroup {} for Creature (entry {}).", uint32(textGroup), sourceEntry);
        return false;
    }

    return true;
}

std::string CreatureTextMgr::GetLocalizedChatString(uint32 entry, uint8 gender, uint8 textGroup, uint32 id, LocaleConstant locale) const
{
    CreatureTextMap::const_iterator mapitr = mTextMap.find(entry);
    if (mapitr == mTextMap.end())
        return "";

    CreatureTextHolder::const_iterator holderItr = mapitr->second.find(textGroup);
    if (holderItr == mapitr->second.end())
        return "";

    CreatureTextGroup::const_iterator groupItr = holderItr->second.begin();
    for (; groupItr != holderItr->second.end(); ++groupItr)
        if (groupItr->id == id)
            break;

    if (groupItr == holderItr->second.end())
        return "";

    if (locale >= TOTAL_LOCALES)
        locale = DEFAULT_LOCALE;

    std::string baseText = "";
    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(groupItr->BroadcastTextId);

    if (bct)
        baseText = DB2Manager::GetBroadcastTextValue(bct, locale, gender);
    else
        baseText = groupItr->text;

    if (locale != DEFAULT_LOCALE && !bct)
    {
        LocaleCreatureTextMap::const_iterator locItr = mLocaleTextMap.find(CreatureTextId(entry, uint32(textGroup), id));
        if (locItr != mLocaleTextMap.end())
            ObjectMgr::GetLocaleString(locItr->second.Text, locale, baseText);
    }

    return baseText;
}
