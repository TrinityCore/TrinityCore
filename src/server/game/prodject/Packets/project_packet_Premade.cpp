#include "project_packet_Premade.h"

WorldPacket const* PROJECT::Packets::Premade::LfgListUpdateBlacklist::Write()
{
    _worldPacket << uint32(Blacklists.size());

    for (auto blacklist : Blacklists)
    {
        _worldPacket << blacklist.ActivityID;
        _worldPacket << blacklist.Reason;
    }

    return &_worldPacket;
}

void PROJECT::Packets::Premade::LfgListSearch::Read()
{
    uint16 search_size = _worldPacket.ReadBits(6);
    _worldPacket.ResetBitPos();
    _worldPacket >> Category;
    _worldPacket >> SubCategory;
    _worldPacket >> Unk1;
    _worldPacket >> Unk2;
    uint32 blacklist_size = _worldPacket.read<uint32>();
    uint32 guid_size = _worldPacket.read<uint32>();
    for (uint32 i = 0; i < blacklist_size; ++i)
    {
        BlacklistActivity list;
        _worldPacket >> list.ActivityID;
        _worldPacket >> list.Reason;
        Blacklists.push_back(list);
    }

    for (uint32 i = 0; i < guid_size; ++i)
    {
        ObjectGuid guid;
        _worldPacket >> guid;
        Guids.push_back(guid);
    }
}

WorldPacket const* PROJECT::Packets::Premade::LfgListSearchResults::Write()
{
    _worldPacket << uint16(Entities.size());
    _worldPacket << uint32(Entities.size());

    for (auto e : Entities)
        _worldPacket << e;

    return &_worldPacket;
}

void PROJECT::Packets::Premade::LfgListJoin::Read()
{
    _worldPacket >> Application;
}

WorldPacket const* PROJECT::Packets::Premade::LfgListUpdateStatus::Write()
{
    _worldPacket << Ride;
    _worldPacket << Application;
    _worldPacket << CreationDate;
    _worldPacket << Reason;

    _worldPacket.WriteBit(Listed);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Premade::LfgListApplication const& application)
{
    data << application.ActivityID;
    data << application.ItemLevelRequired;
    data << application.Unk2;
    data.WriteBits(application.Name.length(), 8);
    data.WriteBits(application.Comment.length(), 11);
    data.WriteBits(application.VoiceChat.length(), 8);
    data.WriteBit(application.IsAutoAccepted);
    data.WriteBit(application.IsPrivate);
    data.WriteBit(application.Quest.is_initialized());
    data.FlushBits();

    data.WriteString(application.Name);
    data.WriteString(application.Comment);
    data.WriteString(application.VoiceChat);

    if (application.Quest.is_initialized())
        data << *application.Quest;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Premade::LfgListRide const& ride)
{
    data << ride.Party;
    data << ride.Loot;
    data << ride.Unk;
    data << ride.Timestamp;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, PROJECT::Packets::Premade::LfgListRide& ride)
{
    data >> ride.Party;
    data >> ride.Loot;
    data >> ride.Unk;
    data >> ride.Timestamp;

    return data;
}

ByteBuffer& operator >> (ByteBuffer& data, PROJECT::Packets::Premade::LfgListApplication& app)
{
    data >> app.ActivityID;
    data >> app.ItemLevelRequired;
    data >> app.Unk2;
    uint32 name_size, comment_size, voice_size;
    name_size = data.ReadBits(8);
    comment_size = data.ReadBits(11);
    voice_size = data.ReadBits(8);
    app.IsAutoAccepted = data.ReadBit();
    app.IsPrivate = data.ReadBit();
    bool operation = data.ReadBit();
    data.ResetBitPos();

    app.Name = data.ReadString(name_size);
    app.Comment = data.ReadString(comment_size);
    app.VoiceChat = data.ReadString(voice_size);

    if (operation)
    {
        app.Quest = boost::in_place();
        data >> *app.Quest;
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Premade::LfgEntity const& e)
{
    data << e.Ride.Party;
    data << e.Ride.Loot;
    data << e.Ride.Unk;
    data << e.Ride.Timestamp;
    data << e.Unk1;

    for (auto guid : e.Owners)
        data << guid;

    data << e.VirtualRealmAddress;
    data << uint32(e.Guid1.size());
    data << uint32(e.Guid2.size());
    data << uint32(e.Guid3.size());
    data << uint32(e.MemberRoles.size());
    data << e.Unk3;
    data << e.CreationTime;
    data << e.RoleMask;

    for (auto guid : e.Guid1)
        data << guid;

    for (auto guid : e.Guid2)
        data << guid;

    for (auto guid : e.Guid3)
        data << guid;

    for (auto role : e.MemberRoles)
    {
        data << role.Class;
        data << role.Role;
    }

    data << e.Application;

    return data;
}

void PROJECT::Packets::Premade::LfgListLeave::Read()
{
    _worldPacket >> Ride;
}

void PROJECT::Packets::Premade::LfgListUpdateRequest::Read()
{
    _worldPacket >> Ride;
    _worldPacket >> Application;
}

void PROJECT::Packets::Premade::LfgListApplyToGroup::Read()
{
    _worldPacket >> Ride;
    _worldPacket >> ActivityID;
    _worldPacket >> RoleMask;
    uint8 size = _worldPacket.ReadBits(8);
    Comment = _worldPacket.ReadString(size);
}

void PROJECT::Packets::Premade::LfgListCancelApplication::Read()
{
    _worldPacket >> Ride;
}

void PROJECT::Packets::Premade::LfgListInviteApplicant::Read()
{
    _worldPacket >> RideParty;
    _worldPacket >> RideApplicant;
    uint32 size = _worldPacket.read<uint32>();
    Members.resize(size);

    for (uint32 i = 0; i < size; ++i)
    {
        Member mem;
        _worldPacket >> mem.Guid;
        _worldPacket >> mem.Role;
        Members.push_back(mem);
    }
}

void PROJECT::Packets::Premade::LfgListInviteResponse::Read()
{
    _worldPacket >> Ride;
    Accepted = _worldPacket.ReadBit();
}

void PROJECT::Packets::Premade::LfgListDeclineApplication::Read()
{
    _worldPacket >> Ride;
    _worldPacket >> RideApply;
}

WorldPacket const* PROJECT::Packets::Premade::LfgListJoinResult::Write()
{
    _worldPacket << Ride;
    _worldPacket << Error;
    _worldPacket << Unk;

    return &_worldPacket;
}
