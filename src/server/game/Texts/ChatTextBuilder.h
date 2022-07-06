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
#include "ChatPackets.h"
#include "SharedDefines.h"
#include <string>

class Player;
class WorldObject;

namespace Trinity
{
    class ChatPacketSender
    {
    private:
        // params
        ChatMsg Type;
        ::Language Language;
        WorldObject const* Sender;
        WorldObject const* Receiver;
        std::string Text;
        uint32 AchievementId;
        LocaleConstant Locale;

    public:
        // caches
        WorldPackets::Chat::Chat UntranslatedPacket;
        mutable Optional<WorldPackets::Chat::Chat> TranslatedPacket;

        ChatPacketSender(ChatMsg chatType, ::Language language, WorldObject const* sender, WorldObject const* receiver, std::string message,
            uint32 achievementId = 0, LocaleConstant locale = LOCALE_enUS);

        void operator()(Player const* player) const;
    };

    class BroadcastTextBuilder
    {
        public:
            BroadcastTextBuilder(WorldObject const* obj, ChatMsg msgType, uint32 textId, uint8 gender, WorldObject const* target = nullptr, uint32 achievementId = 0)
                : _source(obj), _msgType(msgType), _textId(textId), _gender(gender), _target(target), _achievementId(achievementId) { }

            ChatPacketSender* operator()(LocaleConstant locale) const;

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
            CustomChatTextBuilder(WorldObject const* obj, ChatMsg msgType, std::string const& text, Language language = LANG_UNIVERSAL, WorldObject const* target = nullptr)
                : _source(obj), _msgType(msgType), _text(text), _language(language), _target(target) { }

            ChatPacketSender* operator()(LocaleConstant locale) const;

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

            ChatPacketSender* operator()(LocaleConstant locale) const;

        private:
            WorldObject const* _source;
            ChatMsg _msgType;
            uint32 _textId;
            WorldObject const* _target;
            va_list* _args;
    };

    class CreatureTextTextBuilder
    {
        public:
            CreatureTextTextBuilder(WorldObject const* obj, WorldObject const* speaker, uint8 gender, ChatMsg msgtype, uint8 textGroup, uint32 id, Language language, WorldObject const* target)
                : _source(obj), _talker(speaker), _gender(gender), _msgType(msgtype), _textGroup(textGroup), _textId(id), _language(language), _target(target) { }

            ChatPacketSender* operator()(LocaleConstant locale) const;

        private:
            WorldObject const* _source;
            WorldObject const* _talker;
            uint8 _gender;
            ChatMsg _msgType;
            uint8 _textGroup;
            uint32 _textId;
            Language _language;
            WorldObject const* _target;
    };
}
// namespace Trinity

#endif // __CHATTEXT_BUILDER_H
