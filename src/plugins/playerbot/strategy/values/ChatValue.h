#pragma once
#include "../Value.h"

namespace ai
{
    class ChatValue : public ManualSetValue<ChatMsg>
	{
	public:
        ChatValue(PlayerbotAI* ai) : ManualSetValue<ChatMsg>(ai, CHAT_MSG_WHISPER) {}
    };
}
