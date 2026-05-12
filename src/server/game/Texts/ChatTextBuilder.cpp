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
#include "ChatPackets.h"
#include "ObjectMgr.h"
#include <cstdarg>

std::size_t Trinity::BroadcastTextBuilder::operator()(WorldPacket* data, LocaleConstant locale) const
{
    BroadcastText const* bct = sObjectMgr->GetBroadcastText(_textId);
    WorldPackets::Chat::Chat chat;
    chat.Initialize(_msgType, bct ? Language(bct->LanguageID) : LANG_UNIVERSAL, _source, _target, bct ? bct->GetText(locale, _gender) : "", _achievementId, "", locale);
    chat.Write();

    *data = chat.Move();

    return chat.TargetGUIDPos;
}

void Trinity::CustomChatTextBuilder::operator()(WorldPacket& data, LocaleConstant locale) const
{
    WorldPackets::Chat::Chat chat;
    chat.Initialize(_msgType, _language, _source, _target, _text, 0, "", locale);
    chat.Write();

    data = chat.Move();
}

void Trinity::TrinityStringChatBuilder::operator()(WorldPacket& data, LocaleConstant locale) const
{
    char const* text = sObjectMgr->GetTrinityString(_textId, locale);

    WorldPackets::Chat::Chat chat;
    chat.Initialize(_msgType, LANG_UNIVERSAL, _source, _target, "", 0, "", locale);

    if (_args)
    {
        // we need copy va_list before use or original va_list will corrupted
        va_list ap;
        va_copy(ap, *_args);

        static size_t const BufferSize = 2048;
        char strBuffer[BufferSize];
        vsnprintf(strBuffer, BufferSize, text, ap);
        va_end(ap);

        chat.ChatText = strBuffer;
    }
    else
        chat.ChatText = text;

    chat.Write();

    data = chat.Move();
}
