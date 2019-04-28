#ifndef PROJECT_PACKETS_ARCHAEOLOGY_H
#define PROJECT_PACKETS_ARCHAEOLOGY_H

#include <Server/Packet.h>

namespace PROJECT
{
    namespace Packets
    {
        namespace Archaeology
        {
            class ArchaeologySurveryCast final : public WorldPackets::ServerPacket
            {
                public:
                    ArchaeologySurveryCast() : WorldPackets::ServerPacket(SMSG_ARCHAEOLOGY_SURVERY_CAST) { }
            
                    WorldPacket const* Write() override;

                    int32 ResearchBranchID = 0;
                    bool SuccessfulFind = false;
                    uint32 NumFindsCompleted = 0;
                    uint32 TotalFinds = 0;
            };

            class RequestResearchHistory final : public WorldPackets::ClientPacket
            {
            	public:
            	    RequestResearchHistory(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_REQUEST_RESEARCH_HISTORY, std::move(packet)) { }
            	
                    void Read() override { }
            };

            struct ResearchHistory
            {
                int32 ProjectID = 0;
                uint32 FirstCompleted = 0;
                int32 CompletionCount = 0;
            };

            class SetupResearchHistory final : public WorldPackets::ServerPacket
            {
                public:
                    SetupResearchHistory() : WorldPackets::ServerPacket(SMSG_SETUP_RESEARCH_HISTORY) { }
            
                    WorldPacket const* Write() override;

                    std::vector<ResearchHistory> History;
            };
        }
    }
}

#endif
