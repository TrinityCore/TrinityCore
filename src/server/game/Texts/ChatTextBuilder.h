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
#include "MiscPackets.h"
#include "SharedDefines.h"

#include <memory>
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
        uint32 PlayerConditionID;

    public:
        // caches
        WorldPackets::Chat::Chat UntranslatedPacket;
        mutable Optional<WorldPackets::Chat::Chat> TranslatedPacket;
        Optional<WorldPackets::Chat::Emote> EmotePacket;
        std::unique_ptr<WorldPackets::ServerPacket> SoundPacket;

        ChatPacketSender(ChatMsg chatType, ::Language language, WorldObject const* sender, WorldObject const* receiver, std::string message,
            uint32 achievementId = 0, LocaleConstant locale = LOCALE_enUS, uint32 broadcastTextId = 0, uint16 emoteId = 0, uint32 soundKitId = 0, SoundKitPlayType soundKitPlayType = SoundKitPlayType::Normal, uint32 playerConditionId = 0);

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
            CustomChatTextBuilder(WorldObject const* obj, ChatMsg msgType, std::string_view text, Language language = LANG_UNIVERSAL, WorldObject const* target = nullptr)
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
            CreatureTextTextBuilder(WorldObject const* obj, WorldObject const* speaker, uint8 gender, ChatMsg msgtype, uint8 textGroup, uint32 id, Language language, WorldObject const* target, uint32 broadcastTextId, uint16 emoteId, uint32 soundKitId, SoundKitPlayType soundKitPlayType, uint32 playerConditionId)
                : _source(obj), _talker(speaker), _gender(gender), _msgType(msgtype), _textGroup(textGroup), _textId(id), _language(language), _target(target), _broadcastTextId(broadcastTextId), _emoteId(emoteId), _soundKitId(soundKitId), _soundKitPlayType(soundKitPlayType), _playerConditionId(playerConditionId) { }

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
            uint32 _broadcastTextId;
            uint16 _emoteId;
            uint32 _soundKitId;
            SoundKitPlayType _soundKitPlayType;
            uint32 _playerConditionId;
    };
}
// namespace Trinity

#endif // __CHATTEXT_BUILDER_H
