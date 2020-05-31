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

#ifndef _PETITIONMGR_H
#define _PETITIONMGR_H

#include "Define.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"

#include <string>
#include <utility>
#include <vector>

enum PetitionTurns
{
    PETITION_TURN_OK                    = 0,
    PETITION_TURN_ALREADY_IN_GUILD      = 2,
    PETITION_TURN_NEED_MORE_SIGNATURES  = 4,
    PETITION_TURN_GUILD_PERMISSIONS     = 11,
    PETITION_TURN_GUILD_NAME_INVALID    = 12,
    PETITION_TURN_HAS_RESTRICTION       = 13
};

enum PetitionSigns
{
    PETITION_SIGN_OK                        = 0,
    PETITION_SIGN_ALREADY_SIGNED            = 1,
    PETITION_SIGN_ALREADY_IN_GUILD          = 2,
    PETITION_SIGN_CANT_SIGN_OWN             = 3,
    PETITION_SIGN_NOT_SERVER                = 5,
    PETITION_SIGN_FULL                      = 8,
    PETITION_SIGN_ALREADY_SIGNED_OTHER      = 10,
    PETITION_SIGN_RESTRICTED_ACCOUNT_TRIAL  = 11,
    PETITION_SIGN_HAS_RESTRICTION           = 13
};

typedef std::pair<uint32, ObjectGuid> Signature;
typedef std::vector<Signature> SignaturesVector;

struct Petition
{
    ObjectGuid       petitionGuid;
    ObjectGuid       ownerGuid;
    std::string      petitionName;
    SignaturesVector signatures;

    bool IsPetitionSignedByAccount(uint32 accountId) const;
    void AddSignature(ObjectGuid petitionGuid, uint32 accountId, ObjectGuid playerGuid, bool isLoading);
    void UpdateName(std::string const& newName);
    void RemoveSignatureBySigner(ObjectGuid playerGuid);
};

class TC_GAME_API PetitionMgr
{
    public:
        PetitionMgr() { }
        ~PetitionMgr() { }

        static PetitionMgr* instance();

        // Load from DB
        void LoadPetitions();
        void LoadSignatures();

        // Petitions
        void AddPetition(ObjectGuid petitionGuid, ObjectGuid ownerGuid, std::string const& name, bool isLoading);
        void RemovePetition(ObjectGuid petitionGuid);
        Petition* GetPetition(ObjectGuid petitionGuid);
        Petition* GetPetitionByOwner(ObjectGuid ownerGuid);
        void RemovePetitionsByOwner(ObjectGuid ownerGuid);
        void RemoveSignaturesBySigner(ObjectGuid signerGuid);
};

#define sPetitionMgr PetitionMgr::instance()

#endif
