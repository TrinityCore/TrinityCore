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

#include "TicketPackets.h"
#include "TicketMgr.h"

namespace WorldPackets::Ticket
{
ByteBuffer& operator>>(ByteBuffer& data, SupportTicketHeader& header)
{
    data >> header.MapID;
    data >> header.Position;

    return data;
}

WorldPacket const* GMTicketSystemStatus::Write()
{
    _worldPacket << int32(Status);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GMTicketInfo const& gmTicketInfo)
{
    data << int32(gmTicketInfo.TicketID);
    data << gmTicketInfo.TicketDescription;
    data << uint8(gmTicketInfo.Category);
    data << float(gmTicketInfo.TicketOpenTime);
    data << float(gmTicketInfo.OldestTicketTime);
    data << float(gmTicketInfo.UpdateTime);
    data << uint8(gmTicketInfo.AssignedToGM);
    data << uint8(gmTicketInfo.OpenedByGM);

    return data;
}

WorldPacket const* GMTicketGetTicketResponse::Write()
{
    _worldPacket << int32(Result);
    if (Result == GMTICKET_STATUS_HASTEXT)
        _worldPacket << Info;

    return &_worldPacket;
}

void GMTicketCreate::Read()
{
    _worldPacket >> Header;
    _worldPacket >> Description;
    _worldPacket >> NeedResponse;
    _worldPacket >> NeedMoreHelp;
    ChatTimes.resize(_worldPacket.read<uint32>());

    for (uint32& chatTime : ChatTimes)
        _worldPacket >> chatTime;

    _worldPacket >> DecompressedSize;

    std::size_t pos = _worldPacket.rpos();
    std::size_t remainingSize = _worldPacket.size() - pos;

    ChatLines = { _worldPacket.contents() + pos, remainingSize };
    _worldPacket.rpos(pos + remainingSize);
}

WorldPacket const* GMTicketCreateResponse::Write()
{
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

void GMTicketUpdateText::Read()
{
    _worldPacket >> Description;
}

WorldPacket const* GMTicketUpdate::Write()
{
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

WorldPacket const* GMTicketDeleteResponse::Write()
{
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

WorldPacket const* GMTicketResponse::Write()
{
    _worldPacket << uint32(ResponseID);
    _worldPacket << uint32(TicketID);
    _worldPacket << Description;

    for (std::string_view const& responseText : ResponseText)
        _worldPacket << responseText;

    return &_worldPacket;
}

void GMSurveySubmit::Read()
{
    _worldPacket >> SurveyID;
    for (uint32 i = 0; i < 10; ++i)
    {
        int32 questionId = _worldPacket.read<int32>();
        if (!questionId)
            break;

        GMSurveyQuestion& surveyQuestion = SurveyQuestion.emplace_back();
        surveyQuestion.QuestionID = questionId;
        _worldPacket >> surveyQuestion.Answer;
        _worldPacket >> surveyQuestion.AnswerComment;
    }

    _worldPacket >> Comment;
}

void GMLagReport::Read()
{
    _worldPacket >> LagKind;
    _worldPacket >> Header;
}

WorldPacket const* GMTicketResolveResponse::Write()
{
    _worldPacket << uint8(ShowSurvey);

    return &_worldPacket;
}
}
