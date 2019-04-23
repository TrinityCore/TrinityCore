/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "ChatPackets.h"
#include "DB2Stores.h"
#include "ObjectMgr.h"
#include <cstdarg>

WorldPackets::Packet* Trinity::BroadcastTextBuilder::operator()(LocaleConstant locale) const
{
    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(_textId);
    WorldPackets::Chat::Chat* chat = new WorldPackets::Chat::Chat();
    chat->Initialize(_msgType, bct ? Language(bct->LanguageID) : LANG_UNIVERSAL, _source, _target, bct ? DB2Manager::GetBroadcastTextValue(bct, locale, _gender) : "", _achievementId, "", locale);
    return chat;
}

WorldPackets::Packet* Trinity::CustomChatTextBuilder::operator()(LocaleConstant locale) const
{
    WorldPackets::Chat::Chat* chat = new WorldPackets::Chat::Chat();
    chat->Initialize(_msgType, _language, _source, _target, _text, 0, "", locale);
    return chat;
}

WorldPackets::Packet* Trinity::TrinityStringChatBuilder::operator()(LocaleConstant locale) const
{
    WorldPackets::Chat::Chat* packet = new WorldPackets::Chat::Chat();

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

        packet->Initialize(_msgType, LANG_UNIVERSAL, _source, _target, strBuffer, 0, "", locale);
    }
    else
        packet->Initialize(_msgType, LANG_UNIVERSAL, _source, _target, text, 0, "", locale);

    return packet;
}
