local tableHelper = require("raitablehelper").new()
local dbHelper = require("raidbhelper").new()

local RaiCreature = {}

local adventurerAuras = {
  92001,
  92002,
  92003,
  92004,
  92005,
  92006,
  92007,
  92008,
  92009,
  92010  
}

function RaiCreature.new()
  --[[
    OVERVIEW

    SetAdventurerAura()
    RemoveAdventurerAuras()
    SetEquipment()
    Patrol()
  --]]

  --[[
    SetAdventurerAura()
    @creature Reference to the creature
    @return Nothing
  --]]
  function RaiCreature:SetAdventurerAura(creature)
    local aura = creature:GetData("aura")

    if aura ~= nil then 
      creature:CastSpell(creature, aura, true)
    else
      local aura = tableHelper:Random(adventurerAuras)
      creature:CastSpell(creature, aura, true)
      creature:SetData("aura", aura)
    end
  end

  --[[
    RemoveAdventurerAuras()
    @creature Reference to the creature
    @return Nothing
  --]]
  function RaiCreature:RemoveAdventurerAuras(creature)
    for i=1, #adventurerAuras do
      local aura = adventurerAuras[i] 
      creature:RemoveAura(aura)
    end
  end

  --[[
    SetEquipment()
    @creature Reference to the creature
    @return Nothing
  --]]
  function RaiCreature:SetEquipment(creature)
    --creature:SetEquipmentSlots( main_hand, off_hand, ranged )
    local items = dbHelper:GetCreatureWeaponsForLevel(creature)
    local mainHand = tableHelper:Random(items)
    local offHand = tableHelper:Random(items)

    creature:SetEquipmentSlots(mainHand, offHand, 0)
  end

  --[[
    Patrol()
    @creature Reference to the creature
    @return Nothing
  --]]
  function RaiCreature:Patrol(creature)
    creature:PatrolArea(150)
  end

  return RaiCreature
end

return RaiCreature