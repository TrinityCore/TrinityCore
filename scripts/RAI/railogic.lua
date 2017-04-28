local combat = require("raicombat").new()

local RaiLogic = {}

local spellCooldownMin = 100
local spellCooldownMax = 500 -- Ms

function RaiLogic.new()
  --[[
    OVERVIEW
  
    RegisterPhase()

    RegisterDamage()
    RegisterHeal()
    RegisterBuff()
  --]]

  --[[
    RegisterPhase()
    @creature Creature reference
    @phase Phase table
  --]]
  function RaiLogic:RegisterPhase(creature, phase)
    RaiLogic:RegisterDamage(creature, phase)
    RaiLogic:RegisterHeal(creature, phase)
    RaiLogic:RegisterBuff(creature, phase)
  end

  --[[
    RegisterDamage()

    @creature Reference to creature
    @phase Phase data
  --]]
  function RaiLogic:RegisterDamage(creature, phase)
    for i=1, #phase["damage"] do 
      --creature:SendUnitYell("REGISTERED SPELL: "..phase["damage"][i], 0)
      creature:RegisterEvent(function() combat:CastSpell(creature, phase["damage"][i], phase["targets"][phase["damage"][i]]) end, math.random(spellCooldownMin, spellCooldownMax),0)
    end
  end

  --[[
    RegisterHeal()

    @creature Reference to creature
    @phase Phase data
  --]]
  function RaiLogic:RegisterHeal(creature, phase)
    for i=1, #phase["healing"] do 
      --creature:SendUnitYell("REGISTERED HEAL: "..phase["healing"][i], 0)
      creature:RegisterEvent(function() combat:CastHeal(creature, phase["healing"][1]) end, math.random(spellCooldownMin, spellCooldownMax), 0)
    end
  end

  --[[
    RegisterBuff()

    @creature Reference to creature
    @phase Phase data
  --]]
  function RaiLogic:RegisterBuff(creature, phase)
    for i=1, #phase["buff"] do 
      --creature:SendUnitYell("REGISTERED BUFF: "..phase["buff"][i], 0)
      creature:RegisterEvent(function() combat:CastBuff(creature, phase["buff"][1]) end, math.random(spellCooldownMin, spellCooldownMax), 0)
    end
  end 

  return RaiLogic
end

return RaiLogic