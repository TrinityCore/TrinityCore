/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Chat.h"
#include "ObjectMgr.h"
#include "Unit.h"

void Trinity::BroadcastTextBuilder::operator()(WorldPacket& data, LocaleConstant locale) const
{
    BroadcastText const* bct = sObjectMgr->GetBroadcastText(_textId);
    ChatHandler::BuildChatPacket(data, _msgType, bct ? Language(bct->Language) : LANG_UNIVERSAL, _source, _target, bct ? bct->GetText(locale, _source->getGender()) : "", _achievementId, "", locale);
}

size_t Trinity::BroadcastTextBuilder::operator()(WorldPacket* data, LocaleConstant locale) const
{
    BroadcastText const* bct = sObjectMgr->GetBroadcastText(_textId);
    return ChatHandler::BuildChatPacket(*data, _msgType, bct ? Language(bct->Language) : LANG_UNIVERSAL, _source, _target, bct ? bct->GetText(locale, _source->getGender()) : "", _achievementId, "", locale);
}

void Trinity::CustomChatTextBuilder::operator()(WorldPacket& data, LocaleConstant locale) const
{
    ChatHandler::BuildChatPacket(data, _msgType, _language, _source, _target, _text, 0, "", locale);
}
