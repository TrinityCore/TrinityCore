#include "GroupPackets.h"
#include "Group.h"
#include "Player.h"
#include "World.h"
#include "Creature.h"

void WorldPackets::Party::PartyInvite::Read()
{
	_worldPacket >> Language;
	ObjectGuid crossRealmGuid;
	//targetLen = _worldPacket.ReadBits(65);
	_worldPacket.read_skip<uint32>();
	_worldPacket.read_skip<uint16>();
	_worldPacket.read_skip<uint8>();
	targetLen = _worldPacket.ReadBits(9);
	targetLen1 = _worldPacket.ReadBits(15);
	//targetLen2 = _worldPacket.ReadBits(7);
	/*targetLen3 = _worldPacket.ReadBits(1);
	targetLen4 = _worldPacket.ReadBits(1);
	targetLen5 = _worldPacket.ReadBits(1);
	targetLen6 = _worldPacket.ReadBits(1);
	targetLen7 = _worldPacket.ReadBits(1);
	targetLen8 = _worldPacket.ReadBits(1);*/
	/*_worldPacket.read_skip<uint32>();
	_worldPacket.read_skip<uint32>();
	crossRealmGuid[2] = _worldPacket.ReadBit();
	crossRealmGuid[7] = _worldPacket.ReadBit();
	targetLen1 = _worldPacket.ReadBits(9);
	crossRealmGuid[3] = _worldPacket.ReadBit();
	targetLen = _worldPacket.ReadBits(16);
	crossRealmGuid[5] = _worldPacket.ReadBit();
	crossRealmGuid[4] = _worldPacket.ReadBit();
	crossRealmGuid[6] = _worldPacket.ReadBit();
	crossRealmGuid[0] = _worldPacket.ReadBit();
	crossRealmGuid[1] = _worldPacket.ReadBit();*/
	std::string Realmname;
	/*_worldPacket.ReadByteSeq(crossRealmGuid[4]);
	_worldPacket.ReadByteSeq(crossRealmGuid[7]);
	_worldPacket.ReadByteSeq(crossRealmGuid[6]);*/
	Target = _worldPacket.ReadString(targetLen);
	Realmname = _worldPacket.ReadString(targetLen1);
	//Realmname = _worldPacket.ReadString(targetLen1);
	/*_worldPacket.ReadByteSeq(crossRealmGuid[1]);
	_worldPacket.ReadByteSeq(crossRealmGuid[0]);
	_worldPacket.ReadByteSeq(crossRealmGuid[5]);
	_worldPacket.ReadByteSeq(crossRealmGuid[3]);
	_worldPacket.ReadByteSeq(crossRealmGuid[2]);*/

}

void WorldPackets::Party::PartyInviteResponse::Read()
{
	_worldPacket >> Language;
	_worldPacket.ReadBits(8);
	uint8 accepter = _worldPacket.ReadBits(8);
	if (accepter > 0)
		Accept = true;

}

/*
void WorldPackets::Party::PartyCommandResult::Write()
{
		_worldPacket.WriteBits(Name.length(), 9);
		_worldPacket << uint32(Command);
		_worldPacket << uint32(Result);
		_worldPacket << uint32(ResultData);
		_worldPacket << ResultGUID;
		_worldPacket.WriteString(Name);

return &_worldPacket;
}


*/

//void WorldSession::SendPartyResult(PartyOperation operation, const std::string& member, PartyResult res, uint32 val /* = 0 */)
/*{
WorldPackets::Party::PartyCommandResult data;
data.Name = member;
data.Command = operation;
data.Result = res;
data.ResultData = val; // LFD cooldown related (used with ERR_PARTY_LFG_BOOT_COOLDOWN_S and ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S)

SendPacket(data.Write());
}*/