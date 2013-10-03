#include "LiquidHandler.h"
#include "Utils.h"

LiquidHandler::LiquidHandler( ADT* adt ) : Source(adt)
{
    HandleNewLiquid();
}

void LiquidHandler::HandleNewLiquid()
{
    Chunk* chunk = Source->Data->GetChunkByName("MH2O");
    if (!chunk)
        return;

    Vertices.reserve(1000);
    Triangles.reserve(1000);

    FILE* stream = chunk->GetStream();
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
            MCNKData.push_back(MCNKLiquidData(NULL, H2ORenderMask()));
            continue;
        }
        fseek(stream, chunk->Offset + h.OffsetInformation, SEEK_SET);
        H2OInformation information = H2OInformation::Read(stream);

        float** heights = new float*[9];
        for (int j = 0; j < 9; ++j)
        {
            heights[j] = new float[9];
            memset(heights[j], 0, sizeof(float) * 9);
        }

        H2ORenderMask renderMask;
        if (information.LiquidType != 2)
        {
            fseek(stream, chunk->Offset + h.OffsetRender, SEEK_SET);
            renderMask = H2ORenderMask::Read(stream);
            if ((Utils::IsAllZero(renderMask.Mask, 8) || (information.Width == 8 && information.Height == 8)) && information.OffsetMask2)
            {
                fseek(stream, chunk->Offset + information.OffsetMask2, SEEK_SET);
                uint32 size = ceil(information.Width * information.Height / 8.0f);
                uint8* altMask = new uint8[size];
                if (fread(altMask, sizeof(uint8), size, stream) == size)
                    for (uint32 mi = 0; mi < size; mi++)
                        renderMask.Mask[mi + information.OffsetY] |= altMask[mi];
                delete[] altMask;
            }
            fseek(stream, chunk->Offset + information.OffsetHeightmap, SEEK_SET);

            for (int y = information.OffsetY; y < (information.OffsetY + information.Height); y++)
                for (int x = information.OffsetX; x < (information.OffsetX + information.Width); x++)
                    if (fread(&heights[x][y], sizeof(float), 1, stream) != 1)
                        return;
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

        MCNKData.push_back(MCNKLiquidData(heights, renderMask));

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

                Triangles.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WATER, vertOffset, vertOffset+2, vertOffset + 1));
                Triangles.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WATER, vertOffset + 2, vertOffset + 3, vertOffset + 1));
            }
        }
    }
}
