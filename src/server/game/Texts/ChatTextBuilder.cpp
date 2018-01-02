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
#include "Unit.h"

WorldPackets::Packet* Trinity::BroadcastTextBuilder::operator()(LocaleConstant locale) const
{
    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(_textId);
    WorldPackets::Chat::Chat* chat = new WorldPackets::Chat::Chat();
    chat->Initialize(_msgType, bct ? Language(bct->Language) : LANG_UNIVERSAL, _source, _target, bct ? DB2Manager::GetBroadcastTextValue(bct, locale, _source->getGender()) : "", _achievementId, "", locale);
    return chat;
}

WorldPackets::Packet* Trinity::CustomChatTextBuilder::operator()(LocaleConstant locale) const
{
    WorldPackets::Chat::Chat* chat = new WorldPackets::Chat::Chat();
    chat->Initialize(_msgType, _language, _source, _target, _text, 0, "", locale);
    return chat;
}
