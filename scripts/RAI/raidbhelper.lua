local RaiDbHelper = {}

function RaiDbHelper.new()

  --[[
    OVERVIEW
    
    Initialize

    GetRaiCreatures()
    GetCreatureLevel()
    GetCreatureWeaponsForLevel()
  --]]

  --[[
    Initialize()
    @desc Prepares the required DB structure for RAI
  --]]
  function RaiDbHelper:Initialize()
    --WorldDBExecute("DROP TABLE rai_creature")
    --WorldDBExecute("CREATE TABLE rai_creature (creature_entry INT)")

    --WorldDBExecute("DROP TABLE rai_spawns")
    --WorldDBExecute("CREATE TABLE rai_spawns (creature_entry INT, map INT, zone INT, area INT, x FLOAT, y FLOAT, z FLOAT, o FLOAT, osTime INT)")
    
    WorldDBExecute("DROP TABLE rai_line_spawns")
    WorldDBExecute("CREATE TABLE rai_line_spawns (id INT NOT NULL AUTO_INCREMENT, creature_entry INT, faction INT, map INT, zone INT, area INT, x FLOAT, y FLOAT, z FLOAT, o FLOAT, osTime INT, PRIMARY KEY(id))")
    
    WorldDBExecute("DROP TABLE rai_line_moveto")
    WorldDBExecute("CREATE TABLE rai_line_moveto (linespawn INT, x FLOAT, y FLOAT, Z FLOAT)")
  end

  --[[
    GetRaiCreatures()
    @desc Fetches all RAI creatures from database table rai_creature
    @return {100001, 10000..}
  --]]
  function RaiDbHelper:GetRAICreatures()
    local query = WorldDBQuery("SELECT creature_entry FROM rai_creature")
    local creatures = {}

    if query then 
      repeat  

        local row = query:GetRow()
        creatures[#creatures+1] = row["creature_entry"]

      until not query:NextRow()
    end

    return creatures
  end

  --[[
    GetCreatureLevel
    @entry The creature to fetch level of
    @desc Gets a creature's level from database entry
    @return 12
  --]]
  function RaiDbHelper:GetCreatureLevel(entry)
    local query = WorldDBQuery(string.format("SELECT maxlevel FROM creature_template WHERE entry=%i", entry))

    if query then 
      local row = query:GetRow()
      return row["maxlevel"]
    end
  end

  --[[
    GetCreatureWeaponsForLevel()
    @creature The creature to get weapons for
    @return {1231, 451..}
  --]]
  function RaiDbHelper:GetCreatureWeaponsForLevel(creature)
    local level = RaiDbHelper:GetCreatureLevel(creature:GetEntry())
    local query = WorldDBQuery(string.format("SELECT entry, name FROM item_template WHERE class=2 AND requiredlevel = %i AND subclass NOT IN (16, 18, 19, 20, 3, 2) AND quality < 4", level))
    
    local items = {}
    if query then
      repeat
        local row = query:GetRow()
        items[#items+1] = row["entry"]
      until not query:NextRow()
    end

    return items
  end


  return RaiDbHelper
end

return RaiDbHelper