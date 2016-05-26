/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __CHATTEXT_BUILDER_H
#define __CHATTEXT_BUILDER_H

#include "Chat.h"
#include "ObjectMgr.h"

namespace Trinity
{
    class BroadcastTextBuilder
    {
        public:
            BroadcastTextBuilder(Unit const* obj, ChatMsg msgType, uint32 textId, WorldObject const* target = nullptr, uint32 achievementId = 0)
                : _source(obj), _msgType(msgType), _textId(textId), _target(target), _achievementId(achievementId) { }

            void operator()(WorldPacket& data, LocaleConstant locale)
            {
                BroadcastText const* bct = sObjectMgr->GetBroadcastText(_textId);
                ChatHandler::BuildChatPacket(data, _msgType, bct ? Language(bct->Language) : LANG_UNIVERSAL, _source, _target, bct ? bct->GetText(locale, _source->getGender()) : "", _achievementId, "", locale);
            }

            size_t operator()(WorldPacket* data, LocaleConstant locale) const
            {
                BroadcastText const* bct = sObjectMgr->GetBroadcastText(_textId);
                return ChatHandler::BuildChatPacket(*data, _msgType, bct ? Language(bct->Language) : LANG_UNIVERSAL, _source, _target, bct ? bct->GetText(locale, _source->getGender()) : "", _achievementId, "", locale);
            }

        private:
            Unit const* _source;
            ChatMsg _msgType;
            uint32 _textId;
            WorldObject const* _target;
            uint32 _achievementId;
    };

    class CustomChatTextBuilder
    {
        public:
            CustomChatTextBuilder(WorldObject const* obj, ChatMsg msgType, std::string const& text, Language language = LANG_UNIVERSAL, WorldObject const* target = nullptr)
                : _source(obj), _msgType(msgType), _text(text), _language(language), _target(target) { }

            void operator()(WorldPacket& data, LocaleConstant locale)
            {
                ChatHandler::BuildChatPacket(data, _msgType, _language, _source, _target, _text, 0, "", locale);
            }

        private:
            WorldObject const* _source;
            ChatMsg _msgType;
            std::string _text;
            Language _language;
            WorldObject const* _target;
    };
}
// namespace Trinity

#endif // __CHATTEXT_BUILDER_H
