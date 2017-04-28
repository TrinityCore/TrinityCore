local tableHelper = require("raitablehelper").new()

local RaiTargets = {}

--[[
  Damage Targets
  ---------------
  1 = Main target
  2 = Random Target
  3 = All enemies

  Healing Targets
  ----------------
  1 = Self

  Buff Targets
  ----------------
  1 = Self
--]]

function RaiTargets.new()
  --[[
    OVERVIEW

    SelectTargets()

    SelectDamageTargets()
    SelectDamageTarget()

    SelectHealingTargets()
    SelectHealingTarget()


    SelectBuffTargets()
    SelectBuffTarget()
  --]]

  --[[
    SelectTargets

    @phase The phase with spells to pick targets for
    @return {
      12341 = 1,
      1301 = 4..
    }
  --]]
  function RaiTargets:SelectTargets(phase)
    local targets = {}

    local damageTargets = RaiTargets:SelectDamageTargets(phase["damage"])
    local healingTargets = RaiTargets:SelectHealingTargets(phase["healing"])
    local buffTargets = RaiTargets:SelectBuffTargets(phase["buff"])

    targets = tableHelper:Merge(targets, damageTargets)
    targets = tableHelper:Merge(targets, healingTargets)
    targets = tableHelper:Merge(targets, buffTargets)

    return targets
  end

  --[[
    SelectDamageTargets()
    @spells Spells to pick targets for 
    @return {
      1234 = 1, 
      1301 = 4..
    }
  --]]
  function RaiTargets:SelectDamageTargets(spells)
    local spellTargets = { }

    for i=1, #spells do 
      local spell = spells[i]
      local target = RaiTargets:SelectDamageTarget()

      spellTargets[spell] = target
    end

    return spellTargets
  end

  --[[
    SelectDamageTarget()
    @return 1
  --]]
  function RaiTargets:SelectDamageTarget()
    return math.random(1, 2) -- Max to 3 to support all targets
  end

  --[[
    SelectHealingTargets()
    @spells Spells to pick targets for
    @return { 
      1234 = 1,
      1301 = 4..
    }
  --]]
  function RaiTargets:SelectHealingTargets(spells)
    local spellTargets = {}

    for i=1, #spells do 
      local spell = spells[i]
      local target = RaiTargets:SelectHealingTarget()

      spellTargets[spell] = target
    end

    return spellTargets
  end
  --[[
    SelectHealingTarget
    @return 1
  --]]
  function RaiTargets:SelectHealingTarget()
    return math.random(1, 1)
  end

  --[[
    SelectBuffTargets()
    @spells Spells to pick targets for
    @return { 
      1234 = 1,
      1301 = 4..
    }
  --]]
  function RaiTargets:SelectBuffTargets(spells)
    local spellTargets = {}

    for i=1, #spells do 
      local spell = spells[i]
      local target = RaiTargets:SelectBuffTarget()

      spellTargets[spell] = target
    end

    return spellTargets
  end
  --[[
    SelectHealingTarget
    @return 1
  --]]
  function RaiTargets:SelectBuffTarget()
    return math.random(1, 1)
  end

  return RaiTargets
end

return RaiTargets