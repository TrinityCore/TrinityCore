/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "M2Stores.h"
#include "Common.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Log.h"
#include "M2Structure.h"
#include "World.h"
#include <boost/filesystem/path.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>

typedef std::vector<FlyByCamera> FlyByCameraCollection;
std::unordered_map<uint32, FlyByCameraCollection> sFlyByCameraStore;

// Convert the geomoetry from a spline value, to an actual WoW XYZ
G3D::Vector3 translateLocation(G3D::Vector4 const* dbcLocation, G3D::Vector3 const* basePosition, G3D::Vector3 const* splineVector)
{
    G3D::Vector3 work;
    float x = basePosition->x + splineVector->x;
    float y = basePosition->y + splineVector->y;
    float z = basePosition->z + splineVector->z;
    float const distance = sqrt((x * x) + (y * y));
    float angle = std::atan2(x, y) - dbcLocation->w;

    if (angle < 0)
        angle += 2 * float(M_PI);

    work.x = dbcLocation->x + (distance * sin(angle));
    work.y = dbcLocation->y + (distance * cos(angle));
    work.z = dbcLocation->z + z;
    return work;
}

// Number of cameras not used. Multiple cameras never used in 7.1.5
bool readCamera(M2Camera const* cam, uint32 buffSize, M2Header const* header, CinematicCameraEntry const* dbcentry)
{
    char const* buffer = reinterpret_cast<char const*>(header);

    FlyByCameraCollection cameras;
    FlyByCameraCollection targetcam;

    G3D::Vector4 dbcData;
    dbcData.x = dbcentry->Origin.X;
    dbcData.y = dbcentry->Origin.Y;
    dbcData.z = dbcentry->Origin.Z;
    dbcData.w = dbcentry->OriginFacing;

    // Read target locations, only so that we can calculate orientation
    for (uint32 k = 0; k < cam->target_positions.timestamps.number; ++k)
    {
        // Extract Target positions
        if (cam->target_positions.timestamps.offset_elements + sizeof(M2Array) > buffSize)
            return false;
        M2Array const* targTsArray = reinterpret_cast<M2Array const*>(buffer + cam->target_positions.timestamps.offset_elements);
        if (targTsArray->offset_elements + sizeof(uint32) > buffSize || cam->target_positions.values.offset_elements + sizeof(M2Array) > buffSize)
            return false;
        uint32 const* targTimestamps = reinterpret_cast<uint32 const*>(buffer + targTsArray->offset_elements);
        M2Array const* targArray = reinterpret_cast<M2Array const*>(buffer + cam->target_positions.values.offset_elements);

        if (targArray->offset_elements + sizeof(M2SplineKey<G3D::Vector3>) > buffSize)
            return false;
        M2SplineKey<G3D::Vector3> const* targPositions = reinterpret_cast<M2SplineKey<G3D::Vector3> const*>(buffer + targArray->offset_elements);

        // Read the data for this set
        uint32 currPos = targArray->offset_elements;
        for (uint32 i = 0; i < targTsArray->number; ++i)
        {
            if (currPos + sizeof(M2SplineKey<G3D::Vector3>) > buffSize)
                return false;
            // Translate co-ordinates
            G3D::Vector3 newPos = translateLocation(&dbcData, &cam->target_position_base, &targPositions->p0);

            // Add to vector
            FlyByCamera thisCam;
            thisCam.timeStamp = targTimestamps[i];
            thisCam.locations.Relocate(newPos.x, newPos.y, newPos.z, 0.0f);
            targetcam.push_back(thisCam);
            targPositions++;
            currPos += sizeof(M2SplineKey<G3D::Vector3>);
        }
    }

    // Read camera positions and timestamps (translating first position of 3 only, we don't need to translate the whole spline)
    for (uint32 k = 0; k < cam->positions.timestamps.number; ++k)
    {
        // Extract Camera positions for this set
        if (cam->positions.timestamps.offset_elements + sizeof(M2Array) > buffSize)
            return false;
        M2Array const* posTsArray = reinterpret_cast<M2Array const*>(buffer + cam->positions.timestamps.offset_elements);
        if (posTsArray->offset_elements + sizeof(uint32) > buffSize || cam->positions.values.offset_elements + sizeof(M2Array) > buffSize)
            return false;
        uint32 const* posTimestamps = reinterpret_cast<uint32 const*>(buffer + posTsArray->offset_elements);
        M2Array const* posArray = reinterpret_cast<M2Array const*>(buffer + cam->positions.values.offset_elements);
        if (posArray->offset_elements + sizeof(M2SplineKey<G3D::Vector3>) > buffSize)
            return false;
        M2SplineKey<G3D::Vector3> const* positions = reinterpret_cast<M2SplineKey<G3D::Vector3> const*>(buffer + posArray->offset_elements);

        // Read the data for this set
        uint32 currPos = posArray->offset_elements;
        for (uint32 i = 0; i < posTsArray->number; ++i)
        {
            if (currPos + sizeof(M2SplineKey<G3D::Vector3>) > buffSize)
                return false;
            // Translate co-ordinates
            G3D::Vector3 newPos = translateLocation(&dbcData, &cam->position_base, &positions->p0);

            // Add to vector
            FlyByCamera thisCam;
            thisCam.timeStamp = posTimestamps[i];
            thisCam.locations.Relocate(newPos.x, newPos.y, newPos.z);

            if (targetcam.size() > 0)
            {
                // Find the target camera before and after this camera
                FlyByCamera lastTarget;
                FlyByCamera nextTarget;

                // Pre-load first item
                lastTarget = targetcam[0];
                nextTarget = targetcam[0];
                for (uint32 j = 0; j < targetcam.size(); ++j)
                {
                    nextTarget = targetcam[j];
                    if (targetcam[j].timeStamp > posTimestamps[i])
                        break;

                    lastTarget = targetcam[j];
                }

                float x = lastTarget.locations.GetPositionX();
                float y = lastTarget.locations.GetPositionY();
                float z = lastTarget.locations.GetPositionZ();

                // Now, the timestamps for target cam and position can be different. So, if they differ we interpolate
                if (lastTarget.timeStamp != posTimestamps[i])
                {
                    uint32 timeDiffTarget = nextTarget.timeStamp - lastTarget.timeStamp;
                    uint32 timeDiffThis = posTimestamps[i] - lastTarget.timeStamp;
                    float xDiff = nextTarget.locations.GetPositionX() - lastTarget.locations.GetPositionX();
                    float yDiff = nextTarget.locations.GetPositionY() - lastTarget.locations.GetPositionY();
                    float zDiff = nextTarget.locations.GetPositionZ() - lastTarget.locations.GetPositionZ();
                    x = lastTarget.locations.GetPositionX() + (xDiff * (float(timeDiffThis) / float(timeDiffTarget)));
                    y = lastTarget.locations.GetPositionY() + (yDiff * (float(timeDiffThis) / float(timeDiffTarget)));
                    z = lastTarget.locations.GetPositionZ() + (zDiff * (float(timeDiffThis) / float(timeDiffTarget)));
                }
                float xDiff = x - thisCam.locations.GetPositionX();
                float yDiff = y - thisCam.locations.GetPositionY();
                thisCam.locations.SetOrientation(std::atan2(yDiff, xDiff));
            }

            cameras.push_back(thisCam);
            positions++;
            currPos += sizeof(M2SplineKey<G3D::Vector3>);
        }
    }

    sFlyByCameraStore[dbcentry->ID] = cameras;
    return true;
}

TC_GAME_API void LoadM2Cameras(std::string const& dataPath)
{
    sFlyByCameraStore.clear();
    TC_LOG_INFO("server.loading", ">> Loading Cinematic Camera files");

    boost::filesystem::path camerasPath = boost::filesystem::path(dataPath) / "cameras";

    uint32 oldMSTime = getMSTime();
    for (CinematicCameraEntry const* cameraEntry : sCinematicCameraStore)
    {
        boost::filesystem::path filename = camerasPath / Trinity::StringFormat("FILE%08X.xxx", cameraEntry->ModelFileDataID);

        // Convert to native format
        filename.make_preferred();

        std::ifstream m2file(filename.string().c_str(), std::ios::in | std::ios::binary);
        if (!m2file.is_open())
            continue;

        // Get file size
        m2file.seekg(0, std::ios::end);
        std::streamoff const fileSize = m2file.tellg();

        // Reject if not at least the size of the header
        if (static_cast<uint32 const>(fileSize) < sizeof(M2Header) + 4)
        {
            TC_LOG_ERROR("server.loading", "Camera file %s is damaged. File is smaller than header size", filename.string().c_str());
            m2file.close();
            continue;
        }

        // Read 4 bytes (signature)
        m2file.seekg(0, std::ios::beg);
        char fileCheck[5];
        m2file.read(fileCheck, 4);
        fileCheck[4] = '\0';

        // Check file has correct magic (MD21)
        if (strcmp(fileCheck, "MD21"))
        {
            TC_LOG_ERROR("server.loading", "Camera file %s is damaged. File identifier not found.", filename.string().c_str());
            m2file.close();
            continue;
        }

        // Now we have a good file, read it all into a vector of char's, then close the file.
        std::vector<char> buffer(fileSize);
        m2file.seekg(0, std::ios::beg);
        if (!m2file.read(buffer.data(), fileSize))
        {
            m2file.close();
            continue;
        }
        m2file.close();

        bool fileValid = true;
        uint32 m2start = 0;
        char const* ptr = buffer.data();
        while (m2start + 4 < buffer.size() && *reinterpret_cast<uint32 const*>(ptr) != '02DM')
        {
            ++m2start;
            ++ptr;
            if (m2start + sizeof(M2Header) > buffer.size())
            {
                fileValid = false;
                break;
            }
        }

        if (!fileValid)
        {
            TC_LOG_ERROR("server.loading", "Camera file %s is damaged. File is smaller than header size.", filename.string().c_str());
            continue;
        }

        // Read header
        M2Header const* header = reinterpret_cast<M2Header const*>(buffer.data() + m2start);

        if (m2start + header->ofsCameras + sizeof(M2Camera) > static_cast<uint32 const>(fileSize))
        {
            TC_LOG_ERROR("server.loading", "Camera file %s is damaged. Camera references position beyond file end", filename.string().c_str());
            continue;
        }

        // Get camera(s) - Main header, then dump them.
        M2Camera const* cam = reinterpret_cast<M2Camera const*>(buffer.data() + m2start + header->ofsCameras);
        if (!readCamera(cam, fileSize - m2start, header, cameraEntry))
            TC_LOG_ERROR("server.loading", "Camera file %s is damaged. Camera references position beyond file end", filename.string().c_str());
    }
    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " cinematic waypoint sets in %u ms", sFlyByCameraStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

std::vector<FlyByCamera> const* GetFlyByCameras(uint32 cinematicCameraId)
{
    return Trinity::Containers::MapGetValuePtr(sFlyByCameraStore, cinematicCameraId);
}
