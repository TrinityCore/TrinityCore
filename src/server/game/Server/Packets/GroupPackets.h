#ifndef GroupPackets_h__
#define GroupPackets_h__

#include "Packet.h"
#include "SharedDefines.h"
#include "ObjectGuid.h"

class WorldObject;

namespace WorldPackets
{
	namespace Party
	{
		class PartyInvite final : public ClientPacket
		{
		public:
			PartyInvite(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

			void Read() override;

			int32 Language = LANG_UNIVERSAL;
			uint8 targetLen;
			uint8 targetLen1;
			uint8 targetLen2;
			uint8 targetLen3;
			uint8 targetLen4;
			uint8 targetLen5;
			uint8 targetLen6;
			uint8 targetLen7;
			uint8 targetLen8;
			std::string Target;
		};
		class PartyInviteResponse final : public ClientPacket
		{
		public:
			PartyInviteResponse(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

			void Read() override;

			int32 Language = LANG_UNIVERSAL;
			bool Accept = false;
		};
	}
}
#endif
