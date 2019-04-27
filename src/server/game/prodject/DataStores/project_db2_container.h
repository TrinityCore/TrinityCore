#ifndef PROJECT_DB2_CONTAINER_H
#define PROJECT_DB2_CONTAINER_H

#include "project_db2.h"
#include "SharedDefines.h"
#include <unordered_map>
#include <vector>

typedef std::unordered_map<uint32/*spec*/, std::vector<PROJECT::DataStores::Structs::GarrClassSpecPlayerCond const*>> GarrisonSpecPlayerContainer;
typedef std::unordered_map<uint32/*class*/, PROJECT::DataStores::Structs::GarrTalentTree const*> GarrisonTalentTreeContainer;
typedef std::unordered_map<uint32/*item*/, PROJECT::DataStores::Structs::AzeriteEmpoweredItemEntry const*> EmpoweredItemContainer;
typedef std::unordered_map<uint32/*AzeriteTierUnlock*/, std::vector<PROJECT::DataStores::Structs::AzeriteTierUnlockEntry const*>> AzeriteTierUnlockContainer;
typedef std::unordered_map<uint32/*AzeritePowerMember*/, PROJECT::DataStores::Structs::AzeritePowerSetMemberEntry const*> AzeritePowerSetMemberContainer;
typedef std::unordered_map<uint32 /* SpecSetMemberID*/, std::vector<uint32>> SpecSetMemberContainer;
typedef std::map<int32/*itemlevel*/, uint32/*bonus*/> ItemLevelToBonusList;

#define PROJECT_DB2_CONTAINER_STORES GarrisonSpecPlayerContainer _garrSpecPlayer; \
                                     GarrisonTalentTreeContainer _garrTalentTree; \
                                     EmpoweredItemContainer _empoweredItem; \
                                     AzeriteTierUnlockContainer _azeriteTierUnlock; \
                                     AzeritePowerSetMemberContainer _azeritePowerSetMember; \
                                     SpecSetMemberContainer _specSetMember; \
                                     ItemLevelToBonusList _itemLevelToBonusList; \


#endif
