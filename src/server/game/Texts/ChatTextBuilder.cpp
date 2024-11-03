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

#include "ChatTextBuilder.h"
#include "CreatureTextMgr.h"
#include "DB2Stores.h"
#include "LanguageMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldSession.h"
#include <cstdarg>

namespace Trinity
{
ChatPacketSender::ChatPacketSender(ChatMsg chatType, ::Language language, WorldObject const* sender, WorldObject const* receiver,
    std::string message, uint32 achievementId /*= 0*/, LocaleConstant locale /*= LOCALE_enUS*/, uint32 broadcastTextId /*= 0*/, uint16 emoteId /*= 0*/, uint32 soundKitId /*= 0*/, SoundKitPlayType soundKitPlayType /*= SoundKitPlayType::Normal*/, uint32 playerConditionId /*= 0*/)
    : Type(chatType), Language(language), Sender(sender), Receiver(receiver), Text(std::move(message)), AchievementId(achievementId), Locale(locale), PlayerConditionID(playerConditionId)
{
    UntranslatedPacket.Initialize(Type, Language, Sender, Receiver, Text, AchievementId, "", Locale);
    UntranslatedPacket.Write();

    if (sender && sender->IsUnit() && emoteId)
    {
        EmotePacket.emplace();
        EmotePacket->Guid = sender->GetGUID();
        EmotePacket->EmoteID = emoteId;
        EmotePacket->Write();
    }

    SoundPacket = nullptr;
    if (soundKitId)
    {
        if (soundKitPlayType == SoundKitPlayType::Normal)
        {
            SoundPacket = std::make_unique<WorldPackets::Misc::PlaySound>(
                sender ? sender->GetGUID() : ObjectGuid::Empty,
                soundKitId,
                broadcastTextId
            );
        }
        else if (soundKitPlayType == SoundKitPlayType::ObjectSound)
        {
            SoundPacket = std::make_unique<WorldPackets::Misc::PlayObjectSound>(
                receiver ? receiver->GetGUID() : ObjectGuid::Empty,
                sender ? sender->GetGUID() : ObjectGuid::Empty,
                soundKitId,
                receiver ? receiver->GetWorldLocation() : Position(0, 0, 0),
                broadcastTextId
            );
        }
        SoundPacket->Write();
    }
}

void ChatPacketSender::operator()(Player const* player) const
{
    if (!player->MeetPlayerCondition(PlayerConditionID))
        return;

    if (SoundPacket)
        player->SendDirectMessage(SoundPacket->GetRawPacket());

    if (EmotePacket)
        player->SendDirectMessage(EmotePacket->GetRawPacket());

    if (Language == LANG_UNIVERSAL || Language == LANG_ADDON || Language == LANG_ADDON_LOGGED || player->CanUnderstandLanguage(Language))
    {
        player->SendDirectMessage(UntranslatedPacket.GetRawPacket());
        return;
    }

    if (!TranslatedPacket)
    {
        TranslatedPacket.emplace();
        TranslatedPacket->Initialize(Type, Language, Sender, Receiver, sLanguageMgr->Translate(Text, Language, player->GetSession()->GetSessionDbcLocale()),
            AchievementId, "", Locale);
        TranslatedPacket->Write();
    }

    player->SendDirectMessage(TranslatedPacket->GetRawPacket());
}

ChatPacketSender* BroadcastTextBuilder::operator()(LocaleConstant locale) const
{
    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(_textId);
    Unit const* unitSender = Object::ToUnit(_source);
    uint8 const gender = unitSender ? unitSender->GetGender() : GENDER_UNKNOWN;
    uint32 soundKitId = bct ? bct->SoundKitID[gender == GENDER_FEMALE ? 1 : 0] : 0;

    return new ChatPacketSender(_msgType,
        bct ? Language(bct->LanguageID) : LANG_UNIVERSAL,
        _source,
        _target,
        bct ? DB2Manager::GetBroadcastTextValue(bct, locale, _gender) : "",
        _achievementId,
        locale,
        bct ? bct->ID : 0,
        bct ? bct->EmotesID : 0,
        soundKitId,
        SoundKitPlayType::Normal,
        bct ? bct->ConditionID : 0
    );
}

ChatPacketSender* CustomChatTextBuilder::operator()(LocaleConstant locale) const
{
    return new ChatPacketSender(_msgType, _language, _source, _target, _text, 0, locale);
}

ChatPacketSender* TrinityStringChatBuilder::operator()(LocaleConstant locale) const
{
    char const* text = sObjectMgr->GetTrinityString(_textId, locale);

    if (_args)
    {
        // we need copy va_list before use or original va_list will corrupted
        va_list ap;
        va_copy(ap, *_args);

        static size_t const BufferSize = 2048;
        char strBuffer[BufferSize];
        vsnprintf(strBuffer, BufferSize, text, ap);
        va_end(ap);

        return new ChatPacketSender(_msgType, LANG_UNIVERSAL, _source, _target, strBuffer, 0, locale);
    }

    return new ChatPacketSender(_msgType, LANG_UNIVERSAL, _source, _target, text, 0, locale);
}

ChatPacketSender* CreatureTextTextBuilder::operator()(LocaleConstant locale) const
{
    return new ChatPacketSender(_msgType, _language, _talker, _target, sCreatureTextMgr->GetLocalizedChatString(_source->GetEntry(), _gender, _textGroup, _textId, locale), 0, locale,
        _broadcastTextId, _emoteId, _soundKitId, _soundKitPlayType, _playerConditionId);
}
}
