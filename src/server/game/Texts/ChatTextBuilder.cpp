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
    std::string message, uint32 achievementId /*= 0*/, LocaleConstant locale /*= LOCALE_enUS*/)
    : Type(chatType), Language(language), Sender(sender), Receiver(receiver), Text(std::move(message)), AchievementId(achievementId), Locale(locale)
{
    UntranslatedPacket.Initialize(Type, Language, Sender, Receiver, Text, AchievementId, "", Locale);
    UntranslatedPacket.Write();
}

void ChatPacketSender::operator()(Player const* player) const
{
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
    return new ChatPacketSender(_msgType, bct ? Language(bct->LanguageID) : LANG_UNIVERSAL, _source, _target, bct ? DB2Manager::GetBroadcastTextValue(bct, locale, _gender) : "", _achievementId, locale);
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
    return new ChatPacketSender(_msgType, _language, _talker, _target, sCreatureTextMgr->GetLocalizedChatString(_source->GetEntry(), _gender, _textGroup, _textId, locale), 0, locale);
}
}
