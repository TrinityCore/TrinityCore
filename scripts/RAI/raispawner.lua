local group = require("raigroup").new()
local picker = require("raicreaturepicker").new()

local RaiSpawner = {}

function RaiSpawner:new()
  --[[
    OVERVIEW

    Spawn()
  
    SpawnPatroller()
    SpawnPack()

    UpdateCreatureEntry
  --]]

  --[[
    Spawn()
    @desc Handles RAI creature spawn at provided spawnpoint
    @spawnpoint The spawnpoint where the spawn should take place
  --]]
  function RaiSpawner:Spawn(spawnpoint)
    spawnpoint["creature_entry"] = picker:PickEntry(spawnpoint)
    
    if math.random(1, 2) == 1 then 
      RaiSpawner:SpawnPatroller(spawnpoint)
    else
      RaiSpawner:SpawnPack(spawnpoint)
    end
  end

  --[[
    SpawnPatroller()
    @desc Spawns a patrolling RAI creature at the given spawnpoint
    @spawnpoint The spawnpoint where the spawn should take place
  --]]
  function RaiSpawner:SpawnPatroller(spawnpoint)
    local creature = PerformIngameSpawn(1, spawnpoint["creature_entry"], spawnpoint["map"], 0, spawnpoint["x"], spawnpoint["y"], spawnpoint["z"], spawnpoint["o"])
    creature:MoveRandom(600)
    creature:SetFaction(17)
  end

  --[[
    SpawnPack()
    @desc Spawns a patrolling RAI pack at the given spawnpoint
    @spawnpoint The spawnpoint where the spawn should take place
  --]]
  function RaiSpawner:SpawnPack(spawnpoint)
    local packSize = math.random(2, 4)
    --local leader = nil
    local members = {}

    for i=1, packSize do 
      local creature = PerformIngameSpawn(1, spawnpoint["creature_entry"], spawnpoint["map"], 0, spawnpoint["x"], spawnpoint["y"], spawnpoint["z"], spawnpoint["o"])
      creature:SetFaction(17)
      members[#members+1] = creature
    end

    group:PrepareCreatureGroup(members)
  end

  --[[
    SpawnStatic()
    @desc Spawns a static RAI creature
    @spawnpoint The spawnpoint where the spawn should take place
    @return The staticly spawned creature
  --]]
  function RaiSpawner:SpawnStatic(spawnpoint)
    local creature = PerformIngameSpawn(1, spawnpoint["creature_entry"], spawnpoint["map"], 0, spawnpoint["x"], spawnpoint["y"], spawnpoint["z"], spawnpoint["o"])
    return creature
  end

  return RaiSpawner
end

return RaiSpawner