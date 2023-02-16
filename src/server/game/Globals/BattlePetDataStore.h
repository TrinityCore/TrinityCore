/*
 * Copyright 2021 DekkCore
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

#ifndef _BATTLE_PET_DATA_STORE_H
#define _BATTLE_PET_DATA_STORE_H

struct BattlePetTemplate
{
    uint32 CreatureID;
    uint32 BreedMask;
    uint32 MinQuality;
    uint32 minlevel;
    uint32 maxlevel;
    uint32 Species;
    std::set<uint32> BreedIDs;
};

struct BattlePetNpcTeamMember
{
    uint32 Specie;
    uint32 maxlevel;
    uint32 minlevel;
    uint32 minquality;
    uint32 breadsMask;
    uint32 Ability[3];
    std::set<uint32> BreedIDs;
};

typedef std::map<uint32, BattlePetTemplate> BattlePetTemplateContainer;
typedef std::map<uint32, BattlePetTemplate*> BattlePetTemplateMap;
typedef std::map<uint32, std::vector<BattlePetNpcTeamMember>> BattlePetNpcTeamMembers;

class BattlePetDataStoreMgr
{
    BattlePetDataStoreMgr();
    ~BattlePetDataStoreMgr();

public:
    static BattlePetDataStoreMgr* instance();

    void Initialize();
    void LoadBattlePetTemplate();
    void LoadBattlePetNpcTeamMember();
    void ComputeBattlePetSpawns();

    BattlePetTemplate const* GetBattlePetTemplate(uint32 species) const;
    BattlePetTemplate const* GetBattlePetTemplateByEntry(uint32 CreatureID) const;
    uint16 GetRandomBreedID(std::set<uint32> BreedIDs);
    uint8 GetWeightForBreed(uint16 breedID);
    uint8 GetRandomQuailty();
    std::vector<BattlePetNpcTeamMember> GetPetBattleTrainerTeam(uint32 npcID);
private:
    BattlePetTemplateContainer _battlePetTemplateStore;
    BattlePetTemplateMap _battlePetTemplate;
    BattlePetNpcTeamMembers _battlePetNpcTeamMembers;
};

#define sBattlePetDataStore BattlePetDataStoreMgr::instance()

#endif
