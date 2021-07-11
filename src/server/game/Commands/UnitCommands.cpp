/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "World.h"
#include "Player.h"
#include "Chat.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Util.h"
#include "SpellAuras.h"
#include "TargetedMovementGenerator.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

bool ChatHandler::HandleGUIDCommand(char* /*args*/)
{
    ObjectGuid guid = m_session->GetPlayer()->GetSelectionGuid();

    if (!guid)
    {
        SendSysMessage(LANG_NO_SELECTION);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_OBJECT_GUID, guid.GetString().c_str());
    return true;
}

bool ChatHandler::HandleGPSCommand(char* args)
{
    WorldObject* obj = nullptr;
    if (*args)
    {
        if (ObjectGuid guid = ExtractGuidFromLink(&args))
            obj = (WorldObject*)m_session->GetPlayer()->GetObjectByTypeMask(guid, TYPEMASK_CREATURE_OR_GAMEOBJECT);

        if (!obj)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        obj = GetSelectedUnit();

        if (!obj)
        {
            SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }
    }
    CellPair cell_val = MaNGOS::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    Cell cell(cell_val);

    uint32 zone_id, area_id;
    obj->GetZoneAndAreaId(zone_id, area_id);

    MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(obj->GetMapId());
    const auto *zoneEntry = AreaEntry::GetById(zone_id);
    const auto *areaEntry = AreaEntry::GetById(area_id);

    float zone_x = obj->GetPositionX();
    float zone_y = obj->GetPositionY();

    if (!Map2ZoneCoordinates(zone_x, zone_y, zone_id))
    {
        zone_x = 0;
        zone_y = 0;
    }

    Map const* map = obj->GetMap();
    float ground_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), MAX_HEIGHT);
    float floor_z = map->GetHeight(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ());

    GridPair p = MaNGOS::ComputeGridPair(obj->GetPositionX(), obj->GetPositionY());

    int gx = 63 - p.x_coord;
    int gy = 63 - p.y_coord;

    uint32 have_map = GridMap::ExistMap(obj->GetMapId(), gx, gy) ? 1 : 0;
    uint32 have_vmap = GridMap::ExistVMap(obj->GetMapId(), gx, gy) ? 1 : 0;

    TerrainInfo const* terrain = obj->GetTerrain();
    if (have_vmap)
    {
        if (terrain->IsOutdoors(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ()))
            PSendSysMessage("You are OUTdoor");
        else
            PSendSysMessage("You are INdoor");
    }
    else PSendSysMessage("no VMAP available for area info");

    std::string zoneName = "<unknown>";
    std::string areaName = "<unknown>";

    if (zoneEntry)
    {
        zoneName = zoneEntry->Name;
        sObjectMgr.GetAreaLocaleString(zoneEntry->Id, GetSessionDbLocaleIndex(), &zoneName);
    }

    if (areaEntry)
    {
        areaName = areaEntry->Name;
        sObjectMgr.GetAreaLocaleString(areaEntry->Id, GetSessionDbLocaleIndex(), &areaName);
    }

    PSendSysMessage(LANG_MAP_POSITION,
                    obj->GetMapId(), (mapEntry ? mapEntry->name : "<unknown>"),
                    zone_id, zoneName.c_str(), area_id, areaName.c_str(),
                    obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation(),
                    cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), obj->GetInstanceId(),
                    zone_x, zone_y, ground_z, floor_z, have_map, have_vmap);

    if (GenericTransport* transport = obj->GetTransport())
    {
        Position pos;
        obj->GetPosition(pos.x, pos.y, pos.z, transport);
        PSendSysMessage("Transport coords: %f %f %f %f", pos.x, pos.y, pos.z, pos.o);
    }

    DEBUG_LOG("Player %s GPS call for %s '%s' (%s: %u):",
              m_session ? GetNameLink().c_str() : GetMangosString(LANG_CONSOLE_COMMAND),
              (obj->GetTypeId() == TYPEID_PLAYER ? "player" : "creature"), obj->GetName(),
              (obj->GetTypeId() == TYPEID_PLAYER ? "GUID" : "Entry"), (obj->GetTypeId() == TYPEID_PLAYER ? obj->GetGUIDLow() : obj->GetEntry()));

    if (zoneEntry)
        sObjectMgr.GetAreaLocaleString(zoneEntry->Id, sWorld.GetDefaultDbcLocale(), &zoneName);

    if (areaEntry)
        sObjectMgr.GetAreaLocaleString(areaEntry->Id, sWorld.GetDefaultDbcLocale(), &areaName);

    DEBUG_LOG(GetMangosString(LANG_MAP_POSITION),
              obj->GetMapId(), (mapEntry ? mapEntry->name : "<unknown>"),
              zone_id, zoneName.c_str(), area_id, areaName.c_str(),
              obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation(),
              cell.GridX(), cell.GridY(), cell.CellX(), cell.CellY(), obj->GetInstanceId(),
              zone_x, zone_y, ground_z, floor_z, have_map, have_vmap);

    GridMapLiquidData liquid_status;
    GridMapLiquidStatus res = terrain->getLiquidStatus(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), MAP_ALL_LIQUIDS, &liquid_status);
    if (res)
        PSendSysMessage(LANG_LIQUID_STATUS, liquid_status.level, liquid_status.depth_level, liquid_status.type_flags, res);
    return true;
}

bool ChatHandler::HandleGetDistanceCommand(char* args)
{
    WorldObject* obj = nullptr;

    if (*args)
    {
        if (ObjectGuid guid = ExtractGuidFromLink(&args))
            obj = (WorldObject*)m_session->GetPlayer()->GetObjectByTypeMask(guid, TYPEMASK_CREATURE_OR_GAMEOBJECT);

        if (!obj)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        obj = GetSelectedUnit();

        if (!obj)
        {
            SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }
    }

    Player* player = m_session->GetPlayer();
    // Calculate point-to-point distance
    float dx, dy, dz;
    dx = player->GetPositionX() - obj->GetPositionX();
    dy = player->GetPositionY() - obj->GetPositionY();
    dz = player->GetPositionZ() - obj->GetPositionZ();

    PSendSysMessage(LANG_DISTANCE, player->GetDistance(obj), player->GetDistance2d(obj), sqrt(dx * dx + dy * dy + dz * dz));

    return true;
}

bool ChatHandler::HandleGetAngleCommand(char* args)
{
    WorldObject* obj = nullptr;

    if (*args)
    {
        if (ObjectGuid guid = ExtractGuidFromLink(&args))
            obj = (WorldObject*)m_session->GetPlayer()->GetObjectByTypeMask(guid, TYPEMASK_CREATURE_OR_GAMEOBJECT);

        if (!obj)
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }
    }
    else
    {
        obj = GetSelectedUnit();

        if (!obj)
        {
            SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            SetSentErrorMessage(true);
            return false;
        }
    }

    Player* player = m_session->GetPlayer();
    float angle = player->GetAngle(obj);
    PSendSysMessage("You are at a %f angle to %s.", angle, obj->GetName());

    return true;
}

bool ChatHandler::HandleUnitAIInfoCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (pTarget->IsCreature())
        return HandleNpcAIInfoCommand(args);

    return HandleCharacterAIInfoCommand(args);
}

bool ChatHandler::HandleUnitInfoCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("Unit info for %s", pTarget->GetObjectGuid().GetString().c_str());
    PSendSysMessage("Victim: %s", pTarget->GetVictim() ? pTarget->GetVictim()->GetObjectGuid().GetString().c_str() : ObjectGuid().GetString().c_str());
    PSendSysMessage("Charm: %s", pTarget->GetCharmGuid().GetString().c_str());
    PSendSysMessage("Summon: %s", pTarget->GetGuidValue(UNIT_FIELD_SUMMON).GetString().c_str());
    PSendSysMessage("Charmed by: %s", pTarget->GetCharmerGuid().GetString().c_str());
    PSendSysMessage("Summoned by: %s", pTarget->GetGuidValue(UNIT_FIELD_SUMMONEDBY).GetString().c_str());
    PSendSysMessage("Created by: %s", pTarget->GetGuidValue(UNIT_FIELD_CREATEDBY).GetString().c_str());
    PSendSysMessage("Target: %s", pTarget->GetTargetGuid().GetString().c_str());
    PSendSysMessage("Persuaded: %s", pTarget->GetGuidValue(UNIT_FIELD_PERSUADED).GetString().c_str());
    PSendSysMessage("Channel object: %s", pTarget->GetChannelObjectGuid().GetString().c_str());
    PSendSysMessage("Scale: %g", pTarget->GetFloatValue(OBJECT_FIELD_SCALE_X));
    PSendSysMessage("Level: %u", pTarget->GetLevel());
    if (auto pFactionTemplate = pTarget->getFactionTemplateEntry())
    {
        if (auto pFaction = sObjectMgr.GetFactionEntry(pFactionTemplate->faction))
            PSendSysMessage("Faction template: %u - %s", pTarget->GetFactionTemplateId(), pFaction->name[0].c_str());
    }
    else
        PSendSysMessage("Faction template: %u", pTarget->GetFactionTemplateId());
    PSendSysMessage("Race: %hhu", pTarget->GetRace());
    PSendSysMessage("Class: %hhu", pTarget->GetClass());
    PSendSysMessage("Gender: %hhu", pTarget->GetGender());
    PSendSysMessage("Creature type: %u", pTarget->GetCreatureType());
    PSendSysMessage("Unit flags: %u", pTarget->GetUInt32Value(UNIT_FIELD_FLAGS));
    PSendSysMessage("Aura state: %u", pTarget->GetUInt32Value(UNIT_FIELD_AURASTATE));
    PSendSysMessage("Bounding radius: %f", pTarget->GetObjectBoundingRadius());
    PSendSysMessage("Combat reach: %f", pTarget->GetCombatReach());
    PSendSysMessage("Display id: %u", pTarget->GetDisplayId());
    PSendSysMessage("Native display id: %u", pTarget->GetNativeDisplayId());
    PSendSysMessage("Mount display id: %u", pTarget->GetMountID());
    PSendSysMessage("Stand state: %hhu", pTarget->GetStandState());
    PSendSysMessage("Shapeshift form: %hhu", pTarget->GetShapeshiftForm());
    PSendSysMessage("Vis flags: %hhu", pTarget->GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG));
    PSendSysMessage("Dynamic flags: %u", pTarget->GetUInt32Value(UNIT_DYNAMIC_FLAGS));
    if (auto pSpellEntry = sSpellMgr.GetSpellEntry(pTarget->GetUInt32Value(UNIT_CHANNEL_SPELL)))
        PSendSysMessage("Channel spell: %u - %s", pTarget->GetUInt32Value(UNIT_CHANNEL_SPELL), pSpellEntry->SpellName[0].c_str());
    else
        PSendSysMessage("Channel spell: %u", pTarget->GetUInt32Value(UNIT_CHANNEL_SPELL));
    if (auto pSpellEntry = sSpellMgr.GetSpellEntry(pTarget->GetUInt32Value(UNIT_CREATED_BY_SPELL)))
        PSendSysMessage("Created by spell: %u - %s", pTarget->GetUInt32Value(UNIT_CREATED_BY_SPELL), pSpellEntry->SpellName[0].c_str());
    else
        PSendSysMessage("Created by spell: %u", pTarget->GetUInt32Value(UNIT_CREATED_BY_SPELL));
    PSendSysMessage("NPC flags: %u", pTarget->GetUInt32Value(UNIT_NPC_FLAGS));
    PSendSysMessage("NPC emote state: %u", pTarget->GetUInt32Value(UNIT_NPC_EMOTESTATE));
    PSendSysMessage("Unit state flags: %u", pTarget->GetUnitState());
    PSendSysMessage("Death state: %hhu", pTarget->GetDeathState());
    PSendSysMessage("Sheath state: %hhu", pTarget->GetSheath());
    PSendSysMessage("Byte flags 2: %hhu", pTarget->GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_MISC_FLAGS));

    return true;
}

bool ChatHandler::HandleUnitSpeedInfoCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("Speed info for %s", pTarget->GetObjectGuid().GetString().c_str());
    PSendSysMessage("Walk: %g", pTarget->GetSpeed(MOVE_WALK));
    PSendSysMessage("Run: %g", pTarget->GetSpeed(MOVE_RUN));
    PSendSysMessage("Run Back: %g", pTarget->GetSpeed(MOVE_RUN_BACK));
    PSendSysMessage("Swim: %g", pTarget->GetSpeed(MOVE_SWIM));
    PSendSysMessage("Swim Back: %g", pTarget->GetSpeed(MOVE_SWIM_BACK));
    PSendSysMessage("Turn: %g", pTarget->GetSpeed(MOVE_TURN_RATE));

    return true;
}

bool ChatHandler::HandleUnitStatInfoCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("Stat info for %s", pTarget->GetObjectGuid().GetString().c_str());
    PSendSysMessage("Health: %u", pTarget->GetHealth());
    PSendSysMessage("Max Health: %u", pTarget->GetMaxHealth());
    PSendSysMessage("Power type: %hhu", pTarget->GetPowerType());
    PSendSysMessage("Mana: %u", pTarget->GetPower(POWER_MANA));
    PSendSysMessage("Max Mana: %u", pTarget->GetMaxPower(POWER_MANA));
    PSendSysMessage("Rage: %u", pTarget->GetPower(POWER_RAGE));
    PSendSysMessage("Max Rage: %u", pTarget->GetMaxPower(POWER_RAGE));
    PSendSysMessage("Focus: %u", pTarget->GetPower(POWER_FOCUS));
    PSendSysMessage("Max Focus: %u", pTarget->GetMaxPower(POWER_FOCUS));
    PSendSysMessage("Energy: %u", pTarget->GetPower(POWER_ENERGY));
    PSendSysMessage("Max Energy: %u", pTarget->GetMaxPower(POWER_ENERGY));
    PSendSysMessage("Happiness: %u", pTarget->GetPower(POWER_HAPPINESS));
    PSendSysMessage("Max Happiness: %u", pTarget->GetMaxPower(POWER_HAPPINESS));
    PSendSysMessage("Base attack time: %g", pTarget->GetFloatValue(UNIT_FIELD_BASEATTACKTIME));
    PSendSysMessage("Off hand attack time: %g", pTarget->GetFloatValue(UNIT_FIELD_BASEATTACKTIME+1));
    PSendSysMessage("Ranged attack time: %g", pTarget->GetFloatValue(UNIT_FIELD_RANGEDATTACKTIME));
    PSendSysMessage("Min damage: %g", pTarget->GetFloatValue(UNIT_FIELD_MINDAMAGE));
    PSendSysMessage("Max damage: %g", pTarget->GetFloatValue(UNIT_FIELD_MAXDAMAGE));
    PSendSysMessage("Min off hand damage: %g", pTarget->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE));
    PSendSysMessage("Max off hand damage: %g", pTarget->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE));
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_11_2
    PSendSysMessage("Casting speed mod: %g", pTarget->GetFloatValue(UNIT_MOD_CAST_SPEED));
#else
    PSendSysMessage("Casting speed mod: %i", pTarget->GetInt32Value(UNIT_MOD_CAST_SPEED));
#endif
    PSendSysMessage("Base strenght: %g", pTarget->GetCreateStat(STAT_STRENGTH));
    PSendSysMessage("Base agility: %g", pTarget->GetCreateStat(STAT_AGILITY));
    PSendSysMessage("Base stamina: %g", pTarget->GetCreateStat(STAT_STAMINA));
    PSendSysMessage("Base intellect: %g", pTarget->GetCreateStat(STAT_INTELLECT));
    PSendSysMessage("Base spirit: %g", pTarget->GetCreateStat(STAT_SPIRIT));
    PSendSysMessage("Total strenght: %g", pTarget->GetStat(STAT_STRENGTH));
    PSendSysMessage("Total agility: %g", pTarget->GetStat(STAT_AGILITY));
    PSendSysMessage("Total stamina: %g", pTarget->GetStat(STAT_STAMINA));
    PSendSysMessage("Total intellect: %g", pTarget->GetStat(STAT_INTELLECT));
    PSendSysMessage("Total spirit: %g", pTarget->GetStat(STAT_SPIRIT));
    PSendSysMessage("Base armor: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Base holy resist: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_HOLY));
    PSendSysMessage("Base fire resist: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_FIRE));
    PSendSysMessage("Base nature resist: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_NATURE));
    PSendSysMessage("Base frost resist: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_FROST));
    PSendSysMessage("Base shadow resist: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Base arcane resist: %i", pTarget->GetCreateResistance(SPELL_SCHOOL_ARCANE));
    PSendSysMessage("Total armor: %i", pTarget->GetResistance(SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Total holy resist: %i", pTarget->GetResistance(SPELL_SCHOOL_HOLY));
    PSendSysMessage("Total fire resist: %i", pTarget->GetResistance(SPELL_SCHOOL_FIRE));
    PSendSysMessage("Total nature resist: %i", pTarget->GetResistance(SPELL_SCHOOL_NATURE));
    PSendSysMessage("Total frost resist: %i", pTarget->GetResistance(SPELL_SCHOOL_FROST));
    PSendSysMessage("Total shadow resist: %i", pTarget->GetResistance(SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Total arcane resist: %i", pTarget->GetResistance(SPELL_SCHOOL_ARCANE));
    PSendSysMessage("Attack power: %u", pTarget->GetUInt32Value(UNIT_FIELD_ATTACK_POWER));
    PSendSysMessage("Attack power mods: %u", pTarget->GetUInt32Value(UNIT_FIELD_ATTACK_POWER_MODS));
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    PSendSysMessage("Attack power multiplier: %u", pTarget->GetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER));
#endif
    PSendSysMessage("Ranged attack power: %u", pTarget->GetUInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER));
    PSendSysMessage("Ranged attack power mods: %u", pTarget->GetUInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS));
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    PSendSysMessage("Ranged attack power multiplier: %u", pTarget->GetFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER));
#endif
    PSendSysMessage("Min ranged damage: %g", pTarget->GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE));
    PSendSysMessage("Max ranged damage: %g", pTarget->GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE));
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    PSendSysMessage("Physical power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Holy power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_HOLY));
    PSendSysMessage("Fire power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_FIRE));
    PSendSysMessage("Nature power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_NATURE));
    PSendSysMessage("Frost power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_FROST));
    PSendSysMessage("Shadow power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Arcane power cost modifier: %i", pTarget->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + SPELL_SCHOOL_ARCANE));
    PSendSysMessage("Physical power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Holy power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_HOLY));
    PSendSysMessage("Fire power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_FIRE));
    PSendSysMessage("Nature power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_NATURE));
    PSendSysMessage("Frost power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_FROST));
    PSendSysMessage("Shadow power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Arcane power cost multiplier: %g", pTarget->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + SPELL_SCHOOL_ARCANE));
#endif

    Player* pPlayer = pTarget->ToPlayer();
    if (!pPlayer)
        return true;

    PSendSysMessage("Block chance: %g", pPlayer->GetFloatValue(PLAYER_BLOCK_PERCENTAGE));
    PSendSysMessage("Dodge chance: %g", pPlayer->GetFloatValue(PLAYER_DODGE_PERCENTAGE));
    PSendSysMessage("Parry chance: %g", pPlayer->GetFloatValue(PLAYER_PARRY_PERCENTAGE));
    PSendSysMessage("Crit chance: %g", pPlayer->GetFloatValue(PLAYER_CRIT_PERCENTAGE));
    PSendSysMessage("Ranged crit chance: %g", pPlayer->GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE));
    PSendSysMessage("Physical spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Holy spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_HOLY));
    PSendSysMessage("Fire spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_FIRE));
    PSendSysMessage("Nature spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_NATURE));
    PSendSysMessage("Frost spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_FROST));
    PSendSysMessage("Shadow spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Arcane spell crit chance: %g", pPlayer->GetSpellCritPercent(SPELL_SCHOOL_ARCANE));
    PSendSysMessage("Positive strenght: %g", pPlayer->GetPosStat(STAT_STRENGTH));
    PSendSysMessage("Positive agility: %g", pPlayer->GetPosStat(STAT_AGILITY));
    PSendSysMessage("Positive stamina: %g", pPlayer->GetPosStat(STAT_STAMINA));
    PSendSysMessage("Positive intellect: %g", pPlayer->GetPosStat(STAT_INTELLECT));
    PSendSysMessage("Positive spirit: %g", pPlayer->GetPosStat(STAT_SPIRIT));
    PSendSysMessage("Negative strenght: %g", pPlayer->GetNegStat(STAT_STRENGTH));
    PSendSysMessage("Negative agility: %g", pPlayer->GetNegStat(STAT_AGILITY));
    PSendSysMessage("Negative stamina: %g", pPlayer->GetNegStat(STAT_STAMINA));
    PSendSysMessage("Negative intellect: %g", pPlayer->GetNegStat(STAT_INTELLECT));
    PSendSysMessage("Negative spirit: %g", pPlayer->GetNegStat(STAT_SPIRIT));
    PSendSysMessage("Positive armor buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_NORMAL, true));
    PSendSysMessage("Positive holy resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_HOLY, true));
    PSendSysMessage("Positive fire resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_FIRE, true));
    PSendSysMessage("Positive nature resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_NATURE, true));
    PSendSysMessage("Positive frost resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_FROST, true));
    PSendSysMessage("Positive shadow resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_SHADOW, true));
    PSendSysMessage("Positive arcane resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_ARCANE, true));
    PSendSysMessage("Negative armor buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_NORMAL, false));
    PSendSysMessage("Negative holy resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_HOLY, false));
    PSendSysMessage("Negative fire resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_FIRE, false));
    PSendSysMessage("Negative nature resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_NATURE, false));
    PSendSysMessage("Negative frost resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_FROST, false));
    PSendSysMessage("Negative shadow resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_SHADOW, false));
    PSendSysMessage("Negative arcane resist buff mod: %g", pPlayer->GetResistanceBuffMods(SPELL_SCHOOL_ARCANE, false));
    PSendSysMessage("Positive physical damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Positive holy damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_HOLY));
    PSendSysMessage("Positive fire damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_FIRE));
    PSendSysMessage("Positive nature damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_NATURE));
    PSendSysMessage("Positive frost damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_FROST));
    PSendSysMessage("Positive shadow damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Positive arcane damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + SPELL_SCHOOL_ARCANE));
    PSendSysMessage("Negative physical damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Negative holy damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_HOLY));
    PSendSysMessage("Negative fire damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_FIRE));
    PSendSysMessage("Negative nature damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_NATURE));
    PSendSysMessage("Negative frost damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_FROST));
    PSendSysMessage("Negative shadow damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Negative arcane damage mod: %u", pPlayer->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + SPELL_SCHOOL_ARCANE));
    PSendSysMessage("Percent physical damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_NORMAL));
    PSendSysMessage("Percent holy damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_HOLY));
    PSendSysMessage("Percent fire damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_FIRE));
    PSendSysMessage("Percent nature damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_NATURE));
    PSendSysMessage("Percent frost damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_FROST));
    PSendSysMessage("Percent shadow damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_SHADOW));
    PSendSysMessage("Percent arcane damage mod: %g", pPlayer->GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + SPELL_SCHOOL_ARCANE));

    return true;
}

bool ChatHandler::HandleUnitUpdateFieldsInfoCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    ShowAllUpdateFieldsHelper(pTarget);

    return true;
}

bool ChatHandler::HandleFreezeCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();
    if (!pTarget)
        return false;
    pTarget->CastSpell(pTarget, 9454, true);
    return true;
}

bool ChatHandler::HandleUnfreezeCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();
    if (!pTarget)
        return false;
    pTarget->RemoveAurasDueToSpell(9454);
    return true;
}

bool ChatHandler::HandlePossessCommand(char *args)
{
    Unit* tar = GetSelectedUnit();
    if (!tar)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        return false;
    }
    m_session->GetPlayer()->CastSpell(tar, 530, true);
    return true;
}

//.auraname spell player duration
bool ChatHandler::HandleNameAuraCommand(char* args)
{
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellId = ExtractSpellIdFromLink(&args);
    if (!spellId)
        return false;

    char* nameStr = ExtractArg(&args);
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
        return false;

    // Aura duration in seconds
    int32 duration = 0;
    ExtractInt32(&args, duration);
    return HandleAuraHelper(spellId, duration, target);
}

bool ChatHandler::HandleAuraHelper(uint32 spellId, int32 duration, Unit* unit)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);
    if (!spellInfo)
        return false;

    if (!spellInfo->IsSpellAppliesAura((1 << EFFECT_INDEX_0) | (1 << EFFECT_INDEX_1) | (1 << EFFECT_INDEX_2)) &&
        !spellInfo->HasEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
    {
        PSendSysMessage(LANG_SPELL_NO_HAVE_AURAS, spellId);
        SetSentErrorMessage(true);
        return false;
    }

    SpellAuraHolder* holder = CreateSpellAuraHolder(spellInfo, unit, m_session->GetPlayer(), m_session->GetPlayer());

    if (duration > 0)
        holder->SetAuraDuration(duration * IN_MILLISECONDS);

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        uint8 eff = spellInfo->Effect[i];
        if (eff >= TOTAL_SPELL_EFFECTS)
            continue;
        if (Spells::IsAreaAuraEffect(eff) ||
            eff == SPELL_EFFECT_APPLY_AURA ||
            eff == SPELL_EFFECT_PERSISTENT_AREA_AURA)
        {
            Aura* aur = CreateAura(spellInfo, SpellEffectIndex(i), nullptr, holder, unit);
            holder->AddAura(aur, SpellEffectIndex(i));
        }
    }
    if (!unit->AddSpellAuraHolder(holder))
        holder = nullptr;
    return true;
}

bool ChatHandler::HandleAuraCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellId = ExtractSpellIdFromLink(&args);
    // Aura duration in seconds
    int32 duration = 0;
    ExtractInt32(&args, duration);

    return HandleAuraHelper(spellId, duration, target);
}

bool ChatHandler::HandleUnAuraCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    std::string argstr = args;
    if (argstr == "all")
    {
        target->RemoveAllAuras();
        return true;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellId = ExtractSpellIdFromLink(&args);
    if (!spellId)
        return false;

    target->RemoveAurasDueToSpell(spellId);

    return true;
}

bool ChatHandler::HandleListAurasCommand(char* /*args*/)
{
    Unit* unit = GetSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    char const* talentStr = GetMangosString(LANG_TALENT);
    char const* passiveStr = GetMangosString(LANG_PASSIVE);

    Unit::SpellAuraHolderMap const& uAuras = unit->GetSpellAuraHolderMap();
    PSendSysMessage(LANG_COMMAND_TARGET_LISTAURAS, uAuras.size());
    for (const auto& aura : uAuras)
    {
        bool talent = GetTalentSpellCost(aura.second->GetId()) > 0;

        SpellAuraHolder* holder = aura.second;
        char const* name = holder->GetSpellProto()->SpellName[GetSessionDbcLocale()].c_str();

        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        {
            Aura* aur = holder->GetAuraByEffectIndex(SpellEffectIndex(i));
            if (!aur)
                continue;

            if (m_session)
            {
                std::ostringstream ss_name;
                ss_name << "|cffffffff|Hspell:" << aura.second->GetId() << "|h[" << name << "]|h|r";

                PSendSysMessage(LANG_COMMAND_TARGET_AURADETAIL, holder->GetId(), aur->GetEffIndex(),
                    aur->GetModifier()->m_auraname, aur->GetAuraDuration(), aur->GetAuraMaxDuration(), aur->GetStackAmount(),
                    ss_name.str().c_str(),
                    (holder->IsPassive() ? passiveStr : ""), (talent ? talentStr : ""),
                    holder->GetCasterGuid().GetString().c_str());
            }
            else
            {
                PSendSysMessage(LANG_COMMAND_TARGET_AURADETAIL, holder->GetId(), aur->GetEffIndex(),
                    aur->GetModifier()->m_auraname, aur->GetAuraDuration(), aur->GetAuraMaxDuration(), aur->GetStackAmount(),
                    name,
                    (holder->IsPassive() ? passiveStr : ""), (talent ? talentStr : ""),
                    holder->GetCasterGuid().GetString().c_str());
            }
        }
    }

    return true;
}

bool ChatHandler::HandleListMoveGensCommand(char* /*args*/)
{
    Unit* unit = GetSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("List of move gens for %s:", unit->GetObjectGuid().GetString().c_str());
    std::vector<MovementGeneratorType> generators;
    unit->GetMotionMaster()->GetUsedMovementGeneratorsList(generators);
    for (uint32 i = 0; i < generators.size(); i++)
        PSendSysMessage("%u. %s (%u)", (i+1), MotionMaster::GetMovementGeneratorTypeName(generators[i]), generators[i]);

    return true;
}

bool ChatHandler::HandleListHostileRefsCommand(char* /*args*/)
{
    Unit* pUnit = GetSelectedUnit();
    if (!pUnit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("List of hostile references for %s:", pUnit->GetObjectGuid().GetString().c_str());
    HostileReference* pReference = pUnit->GetHostileRefManager().getFirst();
    uint32 counter = 1;
    while (pReference)
    {
        if (Unit* pTarget = pReference->getSourceUnit())
            PSendSysMessage("%u. %s", counter++, pTarget->GetGuidStr().c_str());
        pReference = pReference->next();
    }

    return true;
}

bool ChatHandler::HandleListThreatCommand(char* /*args*/)
{
    Unit* pUnit = GetSelectedUnit();
    if (!pUnit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("Threat list for %s:", pUnit->GetObjectGuid().GetString().c_str());
    ThreatList const& threatList = pUnit->GetThreatManager().getThreatList();
    for (auto const& itr : threatList)
    {
        PSendSysMessage("%g - %s", itr->getThreat(), itr->getUnitGuid().GetString().c_str());
    }

    return true;
}

bool ChatHandler::HandleCastCommand(char* args)
{
    if (!*args)
        return false;

    Unit* target = GetSelectedUnit();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = ExtractSpellIdFromLink(&args);
    if (!spell)
        return false;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell);
    if (!spellInfo)
        return false;

    if (!SpellMgr::IsSpellValid(spellInfo, m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell);
        SetSentErrorMessage(true);
        return false;
    }

    bool triggered = ExtractLiteralArg(&args, "triggered") != nullptr;
    if (!triggered && *args)                                // can be fail also at syntax error
        return false;

    m_session->GetPlayer()->CastSpell(target, spell, triggered);

    return true;
}

bool ChatHandler::HandleCastBackCommand(char* args)
{
    Unit* caster = GetSelectedUnit();

    if (!caster)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = ExtractSpellIdFromLink(&args);
    if (!spell || !sSpellMgr.GetSpellEntry(spell))
        return false;

    bool triggered = ExtractLiteralArg(&args, "triggered") != nullptr;
    if (!triggered && *args)                                // can be fail also at syntax error
        return false;

    caster->SetFacingToObject(m_session->GetPlayer());

    caster->CastSpell(m_session->GetPlayer(), spell, triggered);

    return true;
}

bool ChatHandler::HandleCastDistCommand(char* args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = ExtractSpellIdFromLink(&args);
    if (!spell)
        return false;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell);
    if (!spellInfo)
        return false;

    if (!SpellMgr::IsSpellValid(spellInfo, m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell);
        SetSentErrorMessage(true);
        return false;
    }

    float dist;
    if (!ExtractFloat(&args, dist))
        return false;

    bool triggered = ExtractLiteralArg(&args, "triggered") != nullptr;
    if (!triggered && *args)                                // can be fail also at syntax error
        return false;

    float x, y, z;
    m_session->GetPlayer()->GetClosePoint(x, y, z, dist);

    m_session->GetPlayer()->CastSpell(x, y, z, spell, triggered);
    return true;
}

bool ChatHandler::HandleCastTargetCommand(char* args)
{
    Unit* caster = GetSelectedUnit();

    if (!caster)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!caster->GetVictim())
    {
        SendSysMessage(LANG_SELECTED_TARGET_NOT_HAVE_VICTIM);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = ExtractSpellIdFromLink(&args);
    if (!spell || !sSpellMgr.GetSpellEntry(spell))
        return false;

    bool triggered = ExtractLiteralArg(&args, "triggered") != nullptr;
    if (!triggered && *args)                                // can be fail also at syntax error
        return false;

    caster->SetFacingToObject(m_session->GetPlayer());

    caster->CastSpell(caster->GetVictim(), spell, triggered);

    return true;
}

bool ChatHandler::HandleCastSelfCommand(char* args)
{
    if (!*args)
        return false;

    Unit* target = GetSelectedUnit();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = ExtractSpellIdFromLink(&args);
    if (!spell)
        return false;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell);
    if (!spellInfo)
        return false;

    if (!SpellMgr::IsSpellValid(spellInfo, m_session->GetPlayer()))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell);
        SetSentErrorMessage(true);
        return false;
    }

    bool triggered = ExtractLiteralArg(&args, "triggered") != nullptr;
    if (!triggered && *args)                                // can be fail also at syntax error
        return false;

    target->CastSpell(target, spell, triggered);

    return true;
}

bool ChatHandler::HandleModifyStrengthCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetModifierValue(UNIT_MOD_STAT_STRENGTH, BASE_VALUE, (float) amount);
    pTarget->UpdateAllStats();

    PSendSysMessage(LANG_YOU_CHANGE_STR, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_STR_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyAgilityCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetModifierValue(UNIT_MOD_STAT_AGILITY, BASE_VALUE, (float) amount);
    pTarget->UpdateAllStats();

    PSendSysMessage(LANG_YOU_CHANGE_AGI, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_AGI_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyStaminaCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetModifierValue(UNIT_MOD_STAT_STAMINA, BASE_VALUE, (float)amount);
    pTarget->UpdateAllStats();

    if (pTarget->IsAlive())
        pTarget->SetHealth(pTarget->GetMaxHealth());

    PSendSysMessage(LANG_YOU_CHANGE_STA, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_STA_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyIntellectCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetModifierValue(UNIT_MOD_STAT_INTELLECT, BASE_VALUE, (float) amount);
    pTarget->UpdateAllStats();

    PSendSysMessage(LANG_YOU_CHANGE_INT, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_INT_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifySpiritCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetModifierValue(UNIT_MOD_STAT_SPIRIT, BASE_VALUE, (float) amount);
    pTarget->UpdateAllStats();

    PSendSysMessage(LANG_YOU_CHANGE_SPI, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_SPI_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyArmorCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES, amount);

    PSendSysMessage(LANG_YOU_CHANGE_ARMOR, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_ARMOR_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyHolyCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES+1, amount);

    PSendSysMessage(LANG_YOU_CHANGE_HOLY, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_HOLY_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyFireCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES+2, amount);

    PSendSysMessage(LANG_YOU_CHANGE_FIRE, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_FIRE_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyNatureCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES+3, amount);

    PSendSysMessage(LANG_YOU_CHANGE_NATURE, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_NATURE_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyFrostCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES+4, amount);

    PSendSysMessage(LANG_YOU_CHANGE_FROST, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_FROST_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyShadowCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES+5, amount);

    PSendSysMessage(LANG_YOU_CHANGE_SHADOW, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_SHADOW_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyArcaneCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    pTarget->SetInt32Value(UNIT_FIELD_RESISTANCES+6, amount);

    PSendSysMessage(LANG_YOU_CHANGE_ARCANE, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_ARCANE_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyMeleeApCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetInt32Value(UNIT_FIELD_ATTACK_POWER, amount);
    pTarget->UpdateDamagePhysical(BASE_ATTACK);
    pTarget->UpdateDamagePhysical(OFF_ATTACK);

    PSendSysMessage(LANG_YOU_CHANGE_MELEEAP, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_MELEEAP_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyRangedApCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER, amount);
    pTarget->UpdateDamagePhysical(RANGED_ATTACK);

    PSendSysMessage(LANG_YOU_CHANGE_RANGEDAP, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_RANGEDAP_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifySpellPowerCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    // dunno where spell power is stored so using a custom spell
    pTarget->RemoveAurasDueToSpell(18058);
    pTarget->CastCustomSpell(pTarget, 18058, amount, amount, {}, true);

    PSendSysMessage(LANG_YOU_CHANGE_SP, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_SP_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyMainSpeedCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetFloatValue(UNIT_FIELD_BASEATTACKTIME, (float) amount);

    PSendSysMessage(LANG_YOU_CHANGE_MHSPD, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_MHSPD_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyOffSpeedCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetFloatValue(UNIT_FIELD_BASEATTACKTIME+1, (float) amount);

    PSendSysMessage(LANG_YOU_CHANGE_OHSPD, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_OHSPD_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyRangedSpeedCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    if (amount <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetFloatValue(UNIT_FIELD_RANGEDATTACKTIME, (float) amount);

    PSendSysMessage(LANG_YOU_CHANGE_RSPD, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_RSPD_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyCastSpeedCommand(char *args)
{
    if (!*args)
        return false;

    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    // This field is an Int32 before 1.12.
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
    if (amount < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SetFloatValue(UNIT_MOD_CAST_SPEED, amount);
#else
    pTarget->SetInt32Value(UNIT_MOD_CAST_SPEED, amount);
#endif

    PSendSysMessage(LANG_YOU_CHANGE_CSPD, pTarget->GetName(), amount);

    if (needReportToTarget(pTarget->ToPlayer()))
        ChatHandler(pTarget->ToPlayer()).PSendSysMessage(LANG_YOURS_CSPD_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyCrCommand(char *args)
{
    if (!*args)
        return false;

    Unit* target = GetSelectedUnit();
    if (!target) return false;
    float f;
    if (!ExtractFloat(&args, f))
        return false;

    target->SetFloatValue(UNIT_FIELD_COMBATREACH, f);
    return true;
}

bool ChatHandler::HandleModifyBrCommand(char *args)
{
    if (!*args)
        return false;

    Unit* target = GetSelectedUnit();
    if (!target) return false;
    float f;
    if (!ExtractFloat(&args, f))
        return false;

    target->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, f);
    return true;
}

bool ChatHandler::HandleDeMorphCommand(char* /*args*/)
{
    Unit* target = GetSelectedUnit();
    if (!target)
        target = m_session->GetPlayer();
    // check online security
    else if (target->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity((Player*)target))
        return false;

    target->DeMorph();

    return true;
}

bool ChatHandler::HandleModifyMorphCommand(char* args)
{
    if (!*args)
        return false;

    uint32 display_id = (uint32)atoi(args);
    if (!sCreatureDisplayInfoStore.LookupEntry(display_id))
    {
        PSendSysMessage("Display Id %u does not exist.", display_id);
        return false;
    }

    Unit* target = GetSelectedUnit();
    if (!target)
        target = m_session->GetPlayer();

    // check online security
    else if (target->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity((Player*)target))
        return false;

    target->SetDisplayId(display_id);

    return true;
}

bool ChatHandler::HandleModifyEmoteStateCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();

    if (!pTarget)
    {
        PSendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 anim_id;
    if (!ExtractUInt32(&args, anim_id))
        return false;

    if (!sEmotesStore.LookupEntry(anim_id))
        return false;

    pTarget->HandleEmoteState(anim_id);

    return true;
}

bool ChatHandler::HandleModifyFactionCommand(char* args)
{
    Unit* chr = GetSelectedUnit();
    if (!chr)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!*args)
    {
        if (chr)
        {
            uint32 factionid = chr->GetFactionTemplateId();
            uint32 flag      = chr->GetUInt32Value(UNIT_FIELD_FLAGS);
            uint32 npcflag   = chr->GetUInt32Value(UNIT_NPC_FLAGS);
            uint32 dyflag    = chr->GetUInt32Value(UNIT_DYNAMIC_FLAGS);
            PSendSysMessage(LANG_CURRENT_FACTION, chr->GetGUIDLow(), factionid, flag, npcflag, dyflag);
        }
        return true;
    }

    if (!chr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 factionid;
    if (!ExtractUint32KeyFromLink(&args, "Hfaction", factionid))
        return false;

    if (!sObjectMgr.GetFactionTemplateEntry(factionid))
    {
        PSendSysMessage(LANG_WRONG_FACTION, factionid);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 flag;
    if (!ExtractOptUInt32(&args, flag, chr->GetUInt32Value(UNIT_FIELD_FLAGS)))
        return false;

    uint32 npcflag;
    if (!ExtractOptUInt32(&args, npcflag, chr->GetUInt32Value(UNIT_NPC_FLAGS)))
        return false;

    uint32  dyflag;
    if (!ExtractOptUInt32(&args, dyflag, chr->GetUInt32Value(UNIT_DYNAMIC_FLAGS)))
        return false;

    PSendSysMessage(LANG_YOU_CHANGE_FACTION, chr->GetGUIDLow(), factionid, flag, npcflag, dyflag);

    chr->SetFactionTemplateId(factionid);
    chr->SetUInt32Value(UNIT_FIELD_FLAGS, flag);
    chr->SetUInt32Value(UNIT_NPC_FLAGS, npcflag);
    chr->SetUInt32Value(UNIT_DYNAMIC_FLAGS, dyflag);

    return true;
}

bool ChatHandler::HandleModifyASpeedCommand(char* args)
{
    if (!*args)
        return false;

    float modSpeed = (float)atof(args);

    if (modSpeed > 4.0f && GetAccessLevel() < SEC_BASIC_ADMIN)
        modSpeed = 4.0f;

    if (modSpeed > 100 || modSpeed < 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Unit* chr = GetSelectedUnit();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    std::string chrNameLink = (chr->GetTypeId() == TYPEID_PLAYER) ? ((Player*)chr)->GetName() : "<creature>";

    if (chr->IsTaxiFlying())
    {
        PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }
    PSendSysMessage(LANG_YOU_CHANGE_ASPEED, modSpeed, chrNameLink.c_str());

    chr->UpdateSpeed(MOVE_WALK, false, modSpeed);
    chr->UpdateSpeed(MOVE_RUN, false, modSpeed);
    chr->UpdateSpeed(MOVE_SWIM, false, modSpeed);

    return true;
}

bool ChatHandler::HandleModifyScaleCommand(char* args)
{
    if (!*args)
        return false;

    float Scale = (float)atof(args);
    if (Scale > 100.0f || Scale <= 0.0f)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Unit* target = GetSelectedUnit();
    if (target == nullptr)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (target->GetTypeId() == TYPEID_PLAYER)
    {
        // check online security
        if (HasLowerSecurity((Player*)target))
            return false;

        PSendSysMessage(LANG_YOU_CHANGE_SIZE, Scale, GetNameLink((Player*)target).c_str());
        if (needReportToTarget((Player*)target))
            ChatHandler((Player*)target).PSendSysMessage(LANG_YOURS_SIZE_CHANGED, GetNameLink().c_str(), Scale);
    }

    target->SetObjectScale(Scale);
    target->UpdateModelData();

    return true;
}

bool ChatHandler::HandleModifyHPCommand(char* args)
{
    if (!*args)
        return false;

    int32 hp = 0;
    int32 hpm = 0;
    ExtractInt32(&args, hp);
    ExtractInt32(&args, hpm);

    if (hpm < hp)
        hpm = hp;

    if (hp <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Unit* chr = GetSelectedUnit();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (chr->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity(chr->ToPlayer()))
        return false;

    PSendSysMessage(LANG_YOU_CHANGE_HP, chr->ToPlayer() ? GetNameLink(chr->ToPlayer()).c_str() : "<creature>", hp, hpm);
    if (chr->GetTypeId() == TYPEID_PLAYER && needReportToTarget(chr->ToPlayer()))
        ChatHandler(chr->ToPlayer()).PSendSysMessage(LANG_YOURS_HP_CHANGED, GetNameLink().c_str(), hp, hpm);

    chr->SetMaxHealth(hpm);
    chr->SetHealth(hp);

    return true;
}

bool ChatHandler::HandleModifyManaCommand(char* args)
{
    if (!*args)
        return false;

    int32 mana = 0;
    int32 manam = 0;
    ExtractInt32(&args, mana);
    ExtractInt32(&args, manam);

    if (manam < mana)
        manam = mana;

    if (mana <= 0)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Unit* chr = GetSelectedUnit();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (chr->GetTypeId() == TYPEID_PLAYER && HasLowerSecurity(chr->ToPlayer()))
        return false;

    PSendSysMessage(LANG_YOU_CHANGE_MANA, chr->ToPlayer() ? GetNameLink(chr->ToPlayer()).c_str() : "<creature>", mana, manam);
    if (chr->GetTypeId() == TYPEID_PLAYER && needReportToTarget(chr->ToPlayer()))
        ChatHandler(chr->ToPlayer()).PSendSysMessage(LANG_YOURS_MANA_CHANGED, GetNameLink().c_str(), mana, manam);

    chr->SetMaxPower(POWER_MANA, manam);
    chr->SetPower(POWER_MANA, mana);

    return true;
}

bool ChatHandler::HandleReplenishCommand(char* args)
{
    Unit* pUnit = GetSelectedUnit();
    if (!pUnit || !pUnit->IsAlive())
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    pUnit->SetHealth(pUnit->GetMaxHealth());

    if (pUnit->GetPowerType() == POWER_MANA)
        pUnit->SetPower(POWER_MANA, pUnit->GetMaxPower(POWER_MANA));

    return true;
}

bool ChatHandler::HandleDamageCommand(char* args)
{
    if (!*args)
        return false;

    Unit* target = GetSelectedUnit();
    Player* player = m_session->GetPlayer();

    if (!target || !player->GetSelectionGuid())
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!target->IsAlive())
        return true;

    int32 damage_int;
    if (!ExtractInt32(&args, damage_int))
        return false;

    if (damage_int <= 0)
        return true;

    uint32 damage = uint32(damage_int);

    // flat melee damage without resistence/etc reduction
    if (!*args)
    {
        player->DealDamage(target, damage, nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        if (target != player)
            player->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, target, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_NORMAL, 0);
        return true;
    }

    uint32 school;
    if (!ExtractUInt32(&args, school))
        return false;

    if (school >= MAX_SPELL_SCHOOL)
        return false;

    SpellSchoolMask schoolmask = GetSchoolMask(school);

    if (schoolmask & SPELL_SCHOOL_MASK_NORMAL)
        damage = ditheru(player->CalcArmorReducedDamage(target, damage));

    // melee damage by specific school
    if (!*args)
    {
        uint32 absorb = 0;
        int32 resist = 0;

        target->CalculateDamageAbsorbAndResist(player, schoolmask, SPELL_DIRECT_DAMAGE, damage, &absorb, &resist, nullptr);

        uint32 const bonus = (resist < 0 ? uint32(std::abs(resist)) : 0);
        damage += bonus;
        uint32 const malus = (resist > 0 ? (absorb + uint32(resist)) : absorb);

        if (damage <= malus)
            return true;

        damage -= malus;

        player->DealDamageMods(target, damage, &absorb);
        player->DealDamage(target, damage, nullptr, DIRECT_DAMAGE, schoolmask, nullptr, false);
        player->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, target, 1, schoolmask, damage, absorb, resist, VICTIMSTATE_NORMAL, 0);
        return true;
    }

    // non-melee damage

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spellid = ExtractSpellIdFromLink(&args);
    if (!spellid || !sSpellMgr.GetSpellEntry(spellid))
        return false;

    player->SpellNonMeleeDamageLog(target, spellid, damage);
    return true;
}

bool ChatHandler::HandleAoEDamageCommand(char* args)
{
    int32 damage_int = 1000;
    ExtractInt32(&args, damage_int);

    if (damage_int <= 0)
        return false;

    uint32 damage = uint32(damage_int);

    int32 max_range = 10;
    ExtractInt32(&args, max_range);

    if (max_range <= 0)
        return false;

    Player* pPlayer = m_session->GetPlayer();

    std::list<Unit*> targetsList;
    MaNGOS::AnyAoETargetUnitInObjectRangeCheck u_check(pPlayer, pPlayer, max_range);
    MaNGOS::UnitListSearcher<MaNGOS::AnyAoETargetUnitInObjectRangeCheck> searcher(targetsList, u_check);
    Cell::VisitAllObjects(pPlayer, searcher, max_range);

    for (Unit* pTarget : targetsList)
    {
        pPlayer->DealDamage(pTarget, damage, nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        pPlayer->SendAttackStateUpdate(HITINFO_AFFECTS_VICTIM, pTarget, 1, SPELL_SCHOOL_MASK_NORMAL, damage, 0, 0, VICTIMSTATE_NORMAL, 0);
    }

    return true;
}

bool ChatHandler::HandleMovegensCommand(char* /*args*/)
{
    Unit* unit = GetSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_MOVEGENS_LIST, (unit->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), unit->GetGUIDLow());

    MotionMaster* mm = unit->GetMotionMaster();
    float x, y, z;
    mm->GetDestination(x, y, z);
    for (MotionMaster::const_iterator itr = mm->begin(); itr != mm->end(); ++itr)
    {
        switch ((*itr)->GetMovementGeneratorType())
        {
            case IDLE_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_IDLE);
                break;
            case RANDOM_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_RANDOM);
                break;
            case WAYPOINT_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_WAYPOINT);
                break;
            case CONFUSED_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_CONFUSED);
                break;

            case CHASE_MOTION_TYPE:
            {
                Unit* target = nullptr;
                if (unit->GetTypeId() == TYPEID_PLAYER)
                    target = static_cast<ChaseMovementGenerator<Player> const*>(*itr)->GetTarget();
                else
                    target = static_cast<ChaseMovementGenerator<Creature> const*>(*itr)->GetTarget();

                if (!target)
                    SendSysMessage(LANG_MOVEGENS_CHASE_NULL);
                else if (target->GetTypeId() == TYPEID_PLAYER)
                    PSendSysMessage(LANG_MOVEGENS_CHASE_PLAYER, target->GetName(), target->GetGUIDLow());
                else
                    PSendSysMessage(LANG_MOVEGENS_CHASE_CREATURE, target->GetName(), target->GetGUIDLow());
                break;
            }
            case FOLLOW_MOTION_TYPE:
            {
                Unit* target = nullptr;
                if (unit->GetTypeId() == TYPEID_PLAYER)
                    target = static_cast<FollowMovementGenerator<Player> const*>(*itr)->GetTarget();
                else
                    target = static_cast<FollowMovementGenerator<Creature> const*>(*itr)->GetTarget();

                if (!target)
                    SendSysMessage(LANG_MOVEGENS_FOLLOW_NULL);
                else if (target->GetTypeId() == TYPEID_PLAYER)
                    PSendSysMessage(LANG_MOVEGENS_FOLLOW_PLAYER, target->GetName(), target->GetGUIDLow());
                else
                    PSendSysMessage(LANG_MOVEGENS_FOLLOW_CREATURE, target->GetName(), target->GetGUIDLow());
                break;
            }
            case HOME_MOTION_TYPE:
                if (unit->GetTypeId() == TYPEID_UNIT)
                    PSendSysMessage(LANG_MOVEGENS_HOME_CREATURE, x, y, z);
                else
                    SendSysMessage(LANG_MOVEGENS_HOME_PLAYER);
                break;
            case FLIGHT_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_FLIGHT);
                break;
            case POINT_MOTION_TYPE:
            {
                PSendSysMessage(LANG_MOVEGENS_POINT, x, y, z);
                break;
            }
            case FLEEING_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_FEAR);
                break;
            case DISTRACT_MOTION_TYPE:
                SendSysMessage(LANG_MOVEGENS_DISTRACT);
                break;
            default:
                PSendSysMessage(LANG_MOVEGENS_UNKNOWN, (*itr)->GetMovementGeneratorType());
                break;
        }
    }
    return true;
}

bool ChatHandler::HandleCooldownListCommand(char* /*args*/)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    target->PrintCooldownList(*this);
    return true;
}

bool ChatHandler::HandleCooldownClearCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = "Unknown";
    if (target->GetTypeId() == TYPEID_PLAYER)
        tNameLink = GetNameLink(static_cast<Player*>(target));
    else
        tNameLink = target->GetName();

    if (!*args)
    {
        target->RemoveAllCooldowns();
        PSendSysMessage(LANG_REMOVEALL_COOLDOWN, tNameLink.c_str());
    }
    else
    {
        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spell_id = ExtractSpellIdFromLink(&args);
        if (!spell_id)
            return false;

        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(spell_id);
        if (!spellEntry)
        {
            PSendSysMessage(LANG_UNKNOWN_SPELL, target == m_session->GetPlayer() ? GetMangosString(LANG_YOU) : tNameLink.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        target->RemoveSpellCooldown(*spellEntry);
        PSendSysMessage(LANG_REMOVE_COOLDOWN, spell_id, target == m_session->GetPlayer() ? GetMangosString(LANG_YOU) : tNameLink.c_str());
    }
    return true;
}

bool ChatHandler::HandleCooldownClearClientSideCommand(char*)
{
    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = GetNameLink(target);

    target->RemoveAllCooldowns(true);
    PSendSysMessage(LANG_REMOVEALL_COOLDOWN, tNameLink.c_str());
    return true;
}


bool ChatHandler::HandleNameDieCommand(char* args)
{
    char* nameStr = ExtractArg(&args);
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
        return false;

    return HandleDieHelper(target);
}

bool ChatHandler::HandleDieCommand(char* /*args*/)
{
    Unit* target = GetSelectedUnit();
    return HandleDieHelper(target);
}

bool ChatHandler::HandleDieHelper(Unit* target)
{
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (Player* player = target->ToPlayer())
    {
        if (HasLowerSecurity((Player*)target, ObjectGuid(), false))
            return false;

        if (player->IsGod())
            player->SetCheatGod(false);
    }

    if (target->IsAlive())
    {
        if (sWorld.getConfig(CONFIG_BOOL_DIE_COMMAND_CREDIT))
            m_session->GetPlayer()->DealDamage(target, target->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        else
        {
            Creature* targetCreature = target->ToCreature();
            if (targetCreature)
                targetCreature->SetLootRecipient(nullptr);
            target->DealDamage(target, target->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
        }
    }

    return true;
}

bool ChatHandler::HandleFearCommand(char* args)
{
    Unit* target = GetSelectedUnit();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 spellId = 0;

    for (uint32 i = 0; i < sSpellMgr.GetMaxSpellId(); i++)
    {
        SpellEntry const* pSpellInfo = sSpellMgr.GetSpellEntry(i);
        if (!pSpellInfo)
            continue;

        if ((pSpellInfo->Effect[0] == SPELL_EFFECT_APPLY_AURA) &&
            (pSpellInfo->EffectApplyAuraName[0] == SPELL_AURA_MOD_FEAR) &&
            (pSpellInfo->Effect[1] == SPELL_EFFECT_NONE) &&
            (!pSpellInfo->HasAttribute(SPELL_ATTR_PASSIVE)))
        {
            spellId = i;
            break;
        }
    }

    int32 duration = 0;
    ExtractInt32(&args, duration);

    if (spellId)
        HandleAuraHelper(spellId, duration, target);

    return true;
}

bool ChatHandler::HandleKnockBackCommand(char* args)
{
    Unit* target = GetSelectedUnit();

    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* player = GetSession()->GetPlayer();
    
    float horizontalSpeed = 10.0f;
    ExtractFloat(&args, horizontalSpeed);
    float verticalSpeed = 10.0f;
    ExtractFloat(&args, verticalSpeed);

    target->KnockBackFrom(player, horizontalSpeed, verticalSpeed);

    return true;
}
