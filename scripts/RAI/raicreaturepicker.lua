local RaiCreaturePicker = {}

function RaiCreaturePicker:new()
  --[[
    OVERVIEW

    PickEntry()
    FetchMinAndMaxLevel()
    ConstructCreatureEntry()
  --]]

  --[[
    PickEntry()

    @desc Picks a creature entry depending on a multitude of circumstances
    @return The choosen entry
  --]]
  function RaiCreaturePicker:PickEntry(spawnpoint)
    if spawnpoint["creature_entry"] ~= -1 then return spawnpoint["creature_entry"] end

    local minMax = RaiCreaturePicker:FetchMinAndMaxLevel(spawnpoint["zone"])
    local selectedLevel = math.random(minMax["min"], minMax["max"])
    return RaiCreaturePicker:ConstructCreatureEntry(selectedLevel)
  end

  --[[
    FetchMinAndMaxLevel()
    @desc Fetches the min amd max level for a given zone
    @zone The zone in question
    @return {"min" => 5, "max" => 30} | nil
  --]]

  function RaiCreaturePicker:FetchMinAndMaxLevel(zone)
    local query = WorldDBQuery(string.format("SELECT minlevel, maxlevel FROM rai_zone_level WHERE zone=%i", zone))

    if query then 
      local row = query:GetRow()

      local data = {}
      data["min"] = row["minlevel"]
      data["max"] = row["maxlevel"]
      return data
    else
      print("RaiCreaturePicker: Could not find min and max level for zone "..tostring(zone))
      return nil
    end
  end

  --[[
    ConstructCreatureEntry()
    @desc Constructs a creature entry from a given level
    @level The provided level
    @return The constructed creature entry
  --]]

  function RaiCreaturePicker:ConstructCreatureEntry(level)
    return 100000 + level
  end

  return RaiCreaturePicker
end

return RaiCreaturePicker