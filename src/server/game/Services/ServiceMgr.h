/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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

#ifndef SERVICEMGR_H
#define SERVICEMGR_H

#include "Common.h"
#include <atomic>

enum RidingSpells
{
    RIDING_APPRENTICE = 33388,
    RIDING_JOURNEYMAN = 33391,
    RIDING_EXPERT = 34090,
    RIDING_ARTISAN = 34091,
    RIDING_MASTER = 90265,

    COLD_WEATHER_FLYING = 54197,
    FLIGHT_MASTER_LICENSE = 90267,
    WISDOM_OF_THE_FOUR_WINDS = 115913,
};

enum projectService
{
    ISERVICE_NULL,
    ISERVICE_ANTIERROR,
    ISERVICE_REPLACE_PROFFESION,
    ISERVICE_RECLASS,
    ISERVICE_END
};

enum ReclassFlags
{
    RECLASS_ALLIANCE = 0x00000001,
    RECLASS_HORDE = 0x00000002,
    RECLASS_SPELL = 0x00000004,
    RECLASS_SKILL = 0x00000008,
    RECLASS_QUEST = 0x00000010,
    RECLASS_ACHIEVEMENT = 0x00000020,
};

enum ServiceTypes // only for ExecutedServices
{
    SERVICE_TYPE_RENAME = 1,
    SERVICE_TYPE_CHANGE_ACCOUNT,
    SERVICE_TYPE_CUSTOMIZE,
    SERVICE_TYPE_CHANGE_RACE,
    SERVICE_TYPE_CHANGE_CLASS,
    SERVICE_TYPE_CHANGE_PROFESSION,
    SERVICE_TYPE_CHAR_RESTORE,
    SERVICE_TYPE_GUILD_RENAME,
    SERVICE_TYPE_UNBAN,
    SERVICE_TYPE_LEVEL_DOWN,
    SERVICE_TYPE_MARKETPLACE, // unused
    SERVICE_TYPE_TRANSFER, // unused
    SERVICE_TYPE_BOOST,
    SERVICE_TYPE_ITEM_RESTORE,
    SERVICE_TYPE_BOOST_PROFESSION,
    SERVICE_TYPE_BOOST_PROFESSION_SMALL,
};

enum ItemDeletingType
{
    DELETING_TYPE_BY_PLAYER = 0,
    DELETING_TYPE_VENDOR = 1,
    DELETING_TYPE_DISENCHANT = 2,
};

struct RetroactiveFix
{
    virtual char const* GetDescription() const = 0;
    virtual bool IsActive() { return true; }
    virtual bool IsApplicable(Player* /*player*/) { return true; }
    virtual bool Execute(Player* player) = 0;
};

struct ServiceEntry
{
    explicit ServiceEntry(projectService service)
        : Service(service) { }

    uint32 ID = 0;
    uint32 Service = 0;
    uint32 Data1 = 0;
    uint32 Data2 = 0;
    uint32 Data3 = 0;
    std::string Data4;
};

class ServiceMgr
{
public:
    static ServiceMgr* instance()
    {
        static ServiceMgr _instance;
        return &_instance;
    }

    struct ReclassInfo
    {
        uint32 entry;   // spell or skill ID
        uint8 learn;    // learn (1), unlearn (0) or both (2)
        uint32 data;    // special data: linked spell, skill, quest
        uint32 flag;    // flag for special data;
    };

    struct ProfRankLevel
    {
        uint32 Level;
        uint32 SpellID;
    };

    struct ProfSkill
    {
        uint32 ID;
        ProfRankLevel Rank[8];
    };

    typedef std::list<ReclassInfo> ReclassData;

    std::set<uint32> const* GetClassSpells(uint8 classID, uint32 team);
    const ProfSkill* LookupProfession(uint32 entry);

    Creature* GetPremiumAuc(Player* player);
    uint32 GetSpellFamilyByClass(uint32 classID);
    ReclassData* GetReclassData(uint8 classID);
    void RemoveOldSkillsFromDB(uint32 guid, uint8 classID);
    void LoadFromDB();

    // Retroactive player fixes
    void ApplyRetroactiveFixes(Player* player);

    void AddService(Player* target, uint32 guid, ServiceEntry& entry);
    //void ExecuteService(Player* player, ServiceEntry const& entry, SQLTransaction const& trans = nullptr);

    uint32 GenerateServiceId() { return ++_serviceID; }

    void ExecutedServices(uint32 guid, uint8 type, std::string oldData, std::string newData);

    // Service handlers
    void HandleReplaceSkill(Player* player, uint32 oldSkill, uint32 newSkill, uint32 value, std::string const& /**/);
    void HandleChangeClass(Player* player, uint32 oldClass, uint32 newClass, uint32 /**/, std::string const& /**/);
    void HandleAntiError(Player* player, uint32, uint32, uint32, std::string const&);

    void AddSpecificPlayerData(uint32 guid, uint32 oldRace, uint32 race, uint32 pClass, Player* player = nullptr, bool add = true, bool remove = false);

    void DeletedItemNotify(uint32 guidLow, Item* item, uint8 type);

private:
    static void InsertServiceEntry(uint32 guid, uint32 service, uint32 data1 = 0, uint32 data2 = 0, uint32 data3 = 0, std::string const& data4 = "");
    static void SetExecuted(uint32 id);

    // Retroactive player fixes
    static std::vector<RetroactiveFix*> _retroactiveFixes;

    typedef void (ServiceMgr::* ServiceHandler)(Player*, uint32, uint32, uint32, std::string const&);
    static ServiceHandler _serviceMethods[ISERVICE_END];

    // Containers loading
    void _LoadPremium();
    void _LoadReClassRoutine();
    void LoadSpells();

    std::list<uint64> _aucGUIDs[2];
    ReclassData _reclassData[12];
    static ProfSkill _profs[11];
    std::set<uint32> _classSpells[2][12];

    std::atomic<uint32> _serviceID;
};

#define sServiceMgr ServiceMgr::instance()

#endif // !SERVICEMGR_H
