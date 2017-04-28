local phase = require("raiphase").new()

local RaiEncounter = {}

function RaiEncounter.new()

  --[[
    OVERVIEW

    Generate()
    AmountOfPhases()
    PhaseHealthPct()

    GetPhaseForHealthPct()
  --]]

  --[[
    generate()
    @entry Creature entry
    @return {
      ["phases"] = 3, -- Phases 1, 2, 3 supported
      [1] = {
        ["damage"] = {1231, 13371..},
        ["healing"] = {1307..},
        ["buff"] = {131..},
        ["utility"] = {100},
        ["targets"] = {
          ["1231"] = 1, -- 1 in this case references to current victim
          ["13371"] = 2 -- 2 in this case references to all targets
          ["100"] = 1 -- 1 in this case references to self 
        }
        ["healthpct"] = 0..100
      },
      ["2"] = {
        .....
      }
  --]]
  function RaiEncounter:Generate(entry) 
      local encounter = {}

      -- If we change max amount of phases we must also change 
      local nPhases = RaiEncounter:AmountOfPhases(2, 3)
      encounter["phases"] = nPhases

      for i=1, nPhases do 
        encounter[i] = phase:Generate(entry)
      end

      for i=1, nPhases do 
        encounter[i]["healthpct"] = RaiEncounter:PhaseHealthPct(i, nPhases)
      end

      -- Debug print
      local debug = false
      if debug then 
        print("--------------------")
        print("--------------------")
        print("NPC Entry: "..entry)
        print("Phases: "..nPhases)
        
        for i=1, nPhases do 
          print("## PHASE "..i.." ##")
          local phase = encounter[i] -- phase == nil

          for i=1, #phase["damage"] do 
            print("Damage: "..phase["damage"][i])
          end

          for i=1, #phase["healing"] do 
            print("Healing: "..phase["healing"][i])
          end

          for i=1, #phase["buff"] do 
            print("Buff: "..phase["buff"][i])
          end

          for i=1, #phase["utility"] do 
            print("Utility: "..phase["utility"][i])
          end

          print("HealthPCT: "..phase["healthpct"])
        end

        
      end

      return encounter
  end
  --[[
    AmountOfPhases
    @min Min amount of phases
    @max Max amount of phases
  --]]
  function RaiEncounter:AmountOfPhases(min, max)
    return math.random(min, max)
  end

  --[[
    PhaseHealthPct
    @desc Depends on other phases health PCT
    @phase Phase ID  
    @phases Max amount of phases
    @return health pct (0-100)
  --]]
  function RaiEncounter:PhaseHealthPct(phase, phases)
      --[[ 
        Phase - Pct
        1 - 0.66
        2 - 0.33
        3 - 0

        1 - (100 - 1/3) = 0.66
        2 - (100 - 2/3) = 0.33
        3 - (100 - 3/3) = 0.0
    --]]
    return math.floor(100 - ((phase/phases)* 100))
  end

  --[[
    GetPhaseForHealthPct()

    @desc Returns the phase that is active for the given health PCT.
    @encounter The full encounter table
    @health Health PCT
  --]]
  function RaiEncounter:GetPhaseForHealthPct(encounter, health)
    --100-0
    --3 phases {0.66, 0.33, 0}
    --

    for i=1, encounter["phases"] do 
      local phase = encounter[i]

      if i == 1 then --If it's the first phase
        if health > phase["healthpct"] then 
          return phase, i
        end
      end

      local prevPhase = encounter[i-1]
      if health > phase["healthpct"] and health < prevPhase["healthpct"]then 
        return phase, i
      end

      if i == encounter["phases"] then --If it's the final phase 
        return phase, i
      end
    end
  end

  return RaiEncounter
end

return RaiEncounter