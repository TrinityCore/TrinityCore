local spawner = require("raispawner").new()
local RaiCommands = {}

function RaiCommands.new()
  --[[
    OVERVIEW

    AddSpawn
    DeleteSpawn
    Spawn
  --]]

  --[[
    AddSpawn()
    @player The player executing the command
    @creature The entry of the creature to add a spawnpoint for
    @return False or true
  --]]
  function RaiCommands:AddSpawn(player, creature)
    if creature == nil then 
      creature = -1
    end

    local map = player:GetMapId()
    local zone = player:GetZoneId()
    local area = player:GetAreaId()
    local x = player:GetX()
    local y = player:GetY()
    local z = player:GetZ()
    local o = player:GetO()
    local osTime = os.time()

    WorldDBExecute(string.format("INSERT INTO rai_spawns VALUES (%i, %i, %i, %i, %f, %f, %f, %f, %i)", creature, map, zone, area, x, y, z, o, osTime))

    player:SendBroadcastMessage("RAI: Spawnpoint Added With Entry "..tostring(creature))
    return false
  end

  --[[
    DeleteSpawn()
    @desc Deletes the last spawnpoint according to osTime
    @player The player executing the command
  --]]
  function RaiCommands:DeleteSpawn(player)
    local query = WorldDBQuery("SELECT max(osTime) AS osTime FROM rai_spawns")

    local osTime = nil
    if query then 
      osTime = query:GetRow()["osTime"]
    end

    if osTime == nil then 
      player:SendBroadcastMessage("RAI: DeleteSpawn No Spawn Entries.")
      return false
    end

    WorldDBExecute(string.format("DELETE FROM rai_spawns WHERE osTime=%i", osTime))

    player:SendBroadcastMessage("RAI: SpawnPoint Deleted.")
    return false
  end

  --[[
    Spawn()
    @desc Spawns all RAI creatures from the database 
    @player The player executing the command
  --]]
  function RaiCommands:Spawn(player)
    local query = WorldDBQuery("SELECT * FROM rai_spawns")

    player:UpdateCustomSpellAmount()

    local nSpawned = 0
    if query then 
      repeat
      nSpawned = nSpawned + 1
      local row = query:GetRow()
      
      spawner:Spawn(row)

      until not query:NextRow()
    else
      player:SendBroadcastMessage("RAI: Spawn No Entries In Database.")
      return false
    end

    player:SendBroadcastMessage("RAI: Spawned Creatures For "..nSpawned.." Spawnpoints.")
    return false
  end

  --[[
    AddSpawnLine()
    @desc Spawns creatures on the different line positions
    @player The player executing the command
    @faction The faction for the creature
  --]]
  function RaiCommands:AddSpawnLine(player, faction)
    if faction == nil then 
      player:SendBroadcastMessage("RAI: AddSpawnLine Invalid Faction Argument")
      return false
    end

    local creature = 100000
    local map = player:GetMapId()
    local zone = player:GetZoneId()
    local area = player:GetAreaId()
    local x = player:GetX()
    local y = player:GetY()
    local z = player:GetZ()
    local o = player:GetO()
    local osTime = os.time()

    WorldDBExecute(string.format("INSERT INTO rai_line_spawns (creature_entry, faction, map, zone, area, x, y, z, o, osTime) VALUES (%i, %i, %i, %i, %i, %f, %f, %f, %f, %i)", creature, faction, map, zone, area, x, y, z, o, osTime))

    player:SendBroadcastMessage("RAI: SpawnLine Point Added")
    return false
  end

  --[[
    LineSpawn()
    @desc Spawns all existing line entries
    @player The player executing the command
  --]]
  function RaiCommands:LineSpawn(player)
    local query = WorldDBQuery("SELECT * FROM rai_line_spawns")

    local nSpawned = 0
    if query then 
      repeat
      nSpawned = nSpawned + 1
      local row = query:GetRow()
      
      local creature = spawner:SpawnStatic(row)
      creature:SetFaction(row["faction"])
      creature:AttackStop()
      row["creature_entry"] = 23885
      local triggerNPC = spawner:SpawnStatic(row)

      local movementQuery = WorldDBQuery(string.format("SELECT x, y, z FROM rai_line_moveto WHERE linespawn=%i", row["id"]))

      if movementQuery then 
        local movementRow = movementQuery:GetRow()

        print(movementRow["x"])
        print(movementRow["y"])
        print(movementRow["z"])
        creature:MoveTo(1, movementRow["x"], movementRow["y"], movementRow["z"], true)
      end

      until not query:NextRow()
    else
      player:SendBroadcastMessage("RAI: LineSpawn No Entries In Database.")
      return false
    end

    player:SendBroadcastMessage("RAI: Spawned Creatures For "..nSpawned.." Spawnpoints.")
    return false
  end

  --[[
    DeleteLineSpawn()
    @desc Deletes the last spawnpoint according to osTime
    @player The player executing the command
  --]]
  function RaiCommands:DeleteLineSpawn(player)
    local query = WorldDBQuery("SELECT max(osTime) AS osTime FROM rai_line_spawns")

    local osTime = nil
    if query then 
      osTime = query:GetRow()["osTime"]
    end

    if osTime == nil then 
      player:SendBroadcastMessage("RAI: DeleteLineSpawn No Spawn Entries.")
      return false
    end

    WorldDBExecute(string.format("DELETE FROM rai_line_spawns WHERE osTime=%i", osTime))

    player:SendBroadcastMessage("RAI: LineSpawnPoint Deleted.")
    return false
  end

  --[[
    AddLineMove()
    @desc Add a movement point to the latest added RAI line spawnpoint
    @player The player executing the command
  --]]
  function RaiCommands:AddLineMove(player)
    local query = WorldDBQuery("SELECT max(id) AS id FROM rai_line_spawns")

    if query then 
      local row = query:GetRow()

      local id = row["id"]
      local x = player:GetX()
      local y = player:GetY()
      local z = player:GetZ()

      if id == nil then 
        player:SendBroadcastMessage("RAI: Error rai_line_Spawns ID is null")
      else
        WorldDBExecute(string.format("INSERT INTO rai_line_moveto VALUES (%i, %f, %f, %f)", id, x, y, z))
        player:SendBroadcastMessage("RAI: LineMove Added")
      end
    else
      player:SendBroadcastMessage("RAI: No line spawns found")
    end

    return false
  end

  return RaiCommands
end

return RaiCommands