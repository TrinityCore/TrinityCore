local dbHelper = require("raidbhelper").new()
local generator = require("raigenerator").new()
local encounter = require("raiencounter").new()
local combat = require("raicombat").new()
local logic = require("railogic").new()
local rCreature = require("raicreature").new()
local commands = require("raicommands").new()
local group = require("raigroup").new()
local spawner = require("raispawner").new()

-- If true sets up database structure for RAI support
local initialize = false
local debug = false

if initialize then 
  dbHelper:Initialize()
end

-- Store table data for encounters
local encounters = {}

local function OnCreatureSpawn(event, creature)
  creature:AttackStop()
  creature:RemoveEvents()

  local entry = tostring(creature:GetEntry())

  if debug then
    creature:SendUnitYell("RAI Triggered Entry: "..entry.." GUID: "..tostring(creature:GetGUID()), 0)
  end

  creature:AttackStop()
  local npcEncounter = encounter:Generate(entry)
  encounters[tostring(creature:GetGUID())] = npcEncounter

  creature:SetDisplayId(generator:SelectAdventurerDisplayID())
  rCreature:RemoveAdventurerAuras(creature)
  rCreature:SetAdventurerAura(creature)
  rCreature:SetEquipment(creature)
end

local function OnEnterCombat(event, creature, target)
  local npcEncounter = encounters[tostring(creature:GetGUID())]
  if not npcEncounter then return end --Should only happen if the creature spawns in combat
  local phase = npcEncounter[1]

  ---50 pct chance of casting a spell when entering combat from phase 1
  if math.random(1, 2) == 1 then 

    if npcEncounter ~= nil then 
      creature:CastSpell(target, phase["damage"][1], true)
    end
  end

  logic:RegisterPhase(creature, phase)

  if creature:GetData("groupInfo") then 
    group:OnGroupMemberEnterCombat(creature)
  end 
end

local function OnLeaveCombat(event, creature)
  creature:RemoveEvents()
  rCreature:RemoveAdventurerAuras(creature)
  rCreature:SetAdventurerAura(creature)
end

local function OnDamageTaken(event, creature, attacker, damage)
  local healthPct = creature:GetHealthPct()
  local phase, phaseID = encounter:GetPhaseForHealthPct(encounters[tostring(creature:GetGUID())], healthPct)

  if not creature:GetData("phase"..phaseID) then
    creature:RemoveEvents()
    logic:RegisterPhase(creature, phase)
    creature:SetData("phase"..phaseID, true)
  end
end

local function OnDeath(event, creature, killer)
  local encounter = encounters[tostring(creature:GetGUID())]

  for i=1, encounter["phases"] do
    creature:SetData("phase"..i, false)
  end

  creature:RemoveEvents()
end

local function OnReachHome(event, creature, killer)
  if creature:GetData("aura") then 
    creature:CastSpell(creature, creature:GetData("aura"), true)
  end

  local groupInfo = creature:GetData("groupInfo")
  if groupInfo then 
    if groupInfo["leader"] == creature:GetGUID() then 
      group:StartPatrolling(creature)
    elseif group:IsLeaderAlive(creature, groupInfo) == false then 
      group:PickLeader(creature, groupInfo, creature)
      group:StartPatrolling(creature)
    else
      local leader = group:GetLeader(creature, groupInfo)
      creature:MoveFollow(leader, -5)
      creature:SetWalk(true)
      creature:ClearUnitState(4194304)
    end
  end

  rCreature:RemoveAdventurerAuras(creature)
  rCreature:SetAdventurerAura(creature)
  creature:SetWalk(true)
end

local function spawnRAI(eventID, delay, pCall, creature)
  local spawnData = {}
  spawnData["creature_entry"] = -1
  spawnData["map"] = creature:GetMapId()
  spawnData["zone"] = creature:GetZoneId()
  spawnData["area"] = creature:GetAreaId()
  spawnData["x"] = creature:GetX()
  spawnData["y"] = creature:GetY()
  spawnData["z"] = creature:GetZ()
  spawnData["o"] = creature:GetO()
  spawnData["osTime"] = nil
  spawner:Spawn(spawnData)
end

local function OnCreatureSpawnSpawner(event, creature)
  creature:RegisterEvent(spawnRAI, 100, 1)
  creature:RegisterEvent(spawnRAI, 1400000, 0)
end

--Hook RAI creatures
local creatures = dbHelper:GetRAICreatures()
for i=1, #creatures do 
  RegisterCreatureEvent(creatures[i], 5, OnCreatureSpawn)
  RegisterCreatureEvent(creatures[i], 1, OnEnterCombat)
  RegisterCreatureEvent(creatures[i], 2, OnLeaveCombat)
  RegisterCreatureEvent(creatures[i], 9, OnDamageTaken)
  RegisterCreatureEvent(creatures[i], 4, OnDeath)
  RegisterCreatureEvent(creatures[i], 24, OnReachHome)
end

--Hook Rai Spawner Creature
RegisterCreatureEvent(90002, 5, OnCreatureSpawnSpawner)

-- COMMAND SYSTEM STARTS HERE
local function ExecuteCommand(event, player, command)
  if not player:IsGM() then return true end 

  if string.find(command, "rai") ~= nil then 
    if string.find(command, "rai add spawn") then
      local creatureEntry = tonumber(tostring(string.gsub(command, "rai add spawn ", "")))
      return commands:AddSpawn(player, creatureEntry)
    end

    if string.find(command, "rai delete spawn") then 
      return commands:DeleteSpawn(player)
    end

    if string.find(command, "rai spawn") then 
      return commands:Spawn(player)
    end

    if string.find(command, "rai add linespawn") then 
      local faction = tonumber(tostring(string.gsub(command, "rai add linespawn ", "")))
      return commands:AddSpawnLine(player, faction)
    end

    if string.find(command, "rai linespawn") then 
      return commands:LineSpawn(player)
    end

    if string.find(command, "rai delete linespawn") then 
      return commands:DeleteLineSpawn(player)
    end

    if (string.find(command, "rai add linemove")) then 
      return commands:AddLineMove(player)
    end
  end
end

RegisterPlayerEvent(42, ExecuteCommand)