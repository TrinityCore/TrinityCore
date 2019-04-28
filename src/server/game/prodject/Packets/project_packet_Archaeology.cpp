#include "project_packet_Archaeology.h"

namespace PROJECT {
namespace Packets {
namespace Archaeology {

ByteBuffer& operator<<(ByteBuffer& data, ResearchHistory const& history)
{
    data << history.ProjectID;
    data << history.FirstCompleted;
    data << history.CompletionCount;

    return data;
}

WorldPacket const* PROJECT::Packets::Archaeology::ArchaeologySurveryCast::Write()
{
    _worldPacket << NumFindsCompleted;
    _worldPacket << TotalFinds;
    _worldPacket << ResearchBranchID;
    _worldPacket.WriteBit(SuccessfulFind);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Archaeology::SetupResearchHistory::Write()
{
    _worldPacket << uint32(History.size());

    for (auto history : History)
        _worldPacket << history;

    return &_worldPacket;
}

} // Archaeology
} // Packets
} // PROJECT
