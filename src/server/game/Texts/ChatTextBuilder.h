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

#ifndef __CHATTEXT_BUILDER_H
#define __CHATTEXT_BUILDER_H

#include "Common.h"
#include "SharedDefines.h"
#include <string>

class WorldObject;
class WorldPacket;

namespace Trinity
{
    class BroadcastTextBuilder
    {
        public:
            BroadcastTextBuilder(WorldObject const* obj, ChatMsg msgType, uint32 textId, uint8 gender, WorldObject const* target = nullptr, uint32 achievementId = 0)
                : _source(obj), _msgType(msgType), _textId(textId), _gender(gender), _target(target), _achievementId(achievementId) { }

            void operator()(WorldPacket& data, LocaleConstant locale) const;
            size_t operator()(WorldPacket* data, LocaleConstant locale) const;

        private:
            WorldObject const* _source;
            ChatMsg _msgType;
            uint32 _textId;
            uint8 _gender;
            WorldObject const* _target;
            uint32 _achievementId;
    };

    class CustomChatTextBuilder
    {
        public:
            CustomChatTextBuilder(WorldObject const* obj, ChatMsg msgType, std::string_view text, Language language = LANG_UNIVERSAL, WorldObject const* target = nullptr)
                : _source(obj), _msgType(msgType), _text(text), _language(language), _target(target) { }

            void operator()(WorldPacket& data, LocaleConstant locale) const;

        private:
            WorldObject const* _source;
            ChatMsg _msgType;
            std::string _text;
            Language _language;
            WorldObject const* _target;
    };

    class TrinityStringChatBuilder
    {
        public:
            TrinityStringChatBuilder(WorldObject const* obj, ChatMsg msgType, uint32 textId, WorldObject const* target = nullptr, va_list* args = nullptr)
                : _source(obj), _msgType(msgType), _textId(textId), _target(target), _args(args) { }

            void operator()(WorldPacket& data, LocaleConstant locale) const;

        private:
            WorldObject const* _source;
            ChatMsg _msgType;
            uint32 _textId;
            WorldObject const* _target;
            va_list* _args;
    };
}
// namespace Trinity

#endif // __CHATTEXT_BUILDER_H
