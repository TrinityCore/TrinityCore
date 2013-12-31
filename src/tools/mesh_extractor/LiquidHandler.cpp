/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "LiquidHandler.h"
#include "Utils.h"

LiquidHandler::LiquidHandler( ADT* adt ) : Source(adt)
{
    HandleNewLiquid();
}

LiquidHandler::~LiquidHandler()
{
    for (std::vector<MCNKLiquidData*>::iterator itr = MCNKData.begin(); itr != MCNKData.end(); ++itr)
        delete *itr;
    MCNKData.clear();
}

void LiquidHandler::HandleNewLiquid()
{
    Chunk* chunk = Source->Data->GetChunkByName("MH2O");
    if (!chunk)
        return;

    Vertices.reserve(1000);
    Triangles.reserve(1000);

    Stream* stream = chunk->GetStream();
    H2OHeader header[256];
    MCNKData.reserve(256);
    for (int i = 0; i < 256; i++)
        header[i] = H2OHeader::Read(stream);

    for (int i = 0; i < 256; i++)
    {
        H2OHeader h = header[i];
        if (h.LayerCount == 0)
        {
            // Need to fill in missing data with dummies.
            MCNKData.push_back(new MCNKLiquidData(NULL, H2ORenderMask()));
            continue;
        }
        stream->Seek(chunk->Offset + h.OffsetInformation, SEEK_SET);
        H2OInformation information = H2OInformation::Read(stream);

        // This pointer will be passed to the MCNKLiquidData constructor, from that point on, it is the job of MCNKLiquidData's destructor to release it.
        float** heights = new float*[9];
        for (int j = 0; j < 9; ++j)
        {
            heights[j] = new float[9];
            memset(heights[j], 0, sizeof(float) * 9);
        }

        H2ORenderMask renderMask;
        if (information.LiquidType != 2)
        {
            stream->Seek(chunk->Offset + h.OffsetRender, SEEK_SET);
            renderMask = H2ORenderMask::Read(stream);
            if ((Utils::IsAllZero(renderMask.Mask, 8) || (information.Width == 8 && information.Height == 8)) && information.OffsetMask2)
            {
                stream->Seek(chunk->Offset + information.OffsetMask2, SEEK_SET);
                uint32 size = ceil(information.Width * information.Height / 8.0f);
                uint8* altMask = (uint8*)stream->Read(size);
                for (uint32 mi = 0; mi < size; mi++)
                    renderMask.Mask[mi + information.OffsetY] |= altMask[mi];
                delete[] altMask;
            }
            stream->Seek(chunk->Offset + information.OffsetHeightmap, SEEK_SET);

            for (int y = information.OffsetY; y < (information.OffsetY + information.Height); y++)
                for (int x = information.OffsetX; x < (information.OffsetX + information.Width); x++)
                    heights[x][y] = stream->Read<float>();
        }
        else
        {
            // Fill with ocean data
            for (uint32 i = 0; i < 8; ++i)
                renderMask.Mask[i] = 0xFF;

            for (uint32 y = 0; y < 9; ++y)
                for (uint32 x = 0; x < 9; ++x)
                    heights[x][y] = information.HeightLevel1;
        }

        MCNKData.push_back(new MCNKLiquidData(heights, renderMask));

        for (int y = information.OffsetY; y < (information.OffsetY + information.Height); y++)
        {
            for (int x = information.OffsetX; x < (information.OffsetX + information.Width); x++)
            {
                if (!renderMask.ShouldRender(x, y))
                    continue;

                MapChunk* mapChunk = Source->MapChunks[i];
                Vector3 location = mapChunk->Header.Position;
                location.y = location.y - (x * Constants::UnitSize);
                location.x = location.x - (y * Constants::UnitSize);
                location.z = heights[x][y];

                uint32 vertOffset = Vertices.size();
                Vertices.push_back(location);
                Vertices.push_back(Vector3(location.x - Constants::UnitSize, location.y, location.z));
                Vertices.push_back(Vector3(location.x, location.y - Constants::UnitSize, location.z));
                Vertices.push_back(Vector3(location.x - Constants::UnitSize, location.y - Constants::UnitSize, location.z));
                
                // Define the liquid type
                Constants::TriangleType type = Constants::TRIANGLE_TYPE_UNKNOWN;
                switch (information.LiquidType)
                {
                    case 1: // Water
                    case 2: // Ocean
                    default:
                        type = Constants::TRIANGLE_TYPE_WATER;
                        break;
                    case 3:
                        type = Constants::TRIANGLE_TYPE_MAGMA;
                        break;
                    case 4:
                        type = Constants::TRIANGLE_TYPE_SLIME;
                        break;
                }

                Triangles.push_back(Triangle<uint32>(type, vertOffset, vertOffset+2, vertOffset + 1));
                Triangles.push_back(Triangle<uint32>(type, vertOffset + 2, vertOffset + 3, vertOffset + 1));
            }
        }
    }
}
