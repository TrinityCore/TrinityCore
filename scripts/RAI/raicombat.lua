local RaiCombat = {}

local cooldowns = {
  ["damage"] = 7,
  ["heal"] = 20,
  ["buff"] = 30
}

function RaiCombat.new()
  --[[
    OVERVIEW

    CastSpellRAI()

    Casting()
    CanCastNext()
    CanCastNextHealSelf()
    CanCastNextHealFriendly()
    CanCastNextBuffSelf()
    CanCastNextBuffFriendly()

    CastSpellVictim()
    CastSpellRandom()
    CastSpellAll()
    CastHeal()
    CastBuff()

    CastHealSelf()
    CastHealFriendly()
    
    CastBuffSelf()
    CastBuffFriendly()
  --]]

  --[[
    CastSpellRAI()

    @creature Reference to creature
    @spell Spell ID to cast
    @target Damage Target Type (see RaiTargets)
    @return Nothing
  --]]
  function RaiCombat:CastSpell(creature, spell, target)
    if not RaiCombat:CanCastNext(creature) then return end 

    creature:SetData("lastCastTime", os.time())

    if target == 1 then 
      RaiCombat:CastSpellVictim(creature, spell)
    elseif target == 2 then 
      RaiCombat:CastSpellRandom(creature, spell)
    elseif target == 3 then  
      RaiCombat:CastSpellAll(creature, spell) 
    end
  end

  --[[
    Casting()

    @creature Reference to creature
    @return true or false
  --]]
  function RaiCombat:Casting(creature)
    return creature:HasUnitState(32768) --Casting
  end

  --[[
    CanCastNext()
  
    @creature Reference to creature
    @return true or false
  --]]
  function RaiCombat:CanCastNext(creature)
    if RaiCombat:Casting(creature) then return false end
    if not creature:GetData("lastCastTime") then return true end


    local castingCooldown = cooldowns["damage"]--In seconds
    return (os.time() - creature:GetData("lastCastTime")) > castingCooldown
  end

  --[[
    CanCastNextHealSelf()

    @creature Reference to creature
    @return true or false
  --]]

  function RaiCombat:CanCastNextHealSelf(creature)
    if RaiCombat:Casting(creature) then return false end
    if creature:GetHealthPct() > 90 then return false end 
    if not creature:GetData("lastCastTimeHeal") then return true end

    local castingCooldown = cooldowns["heal"]
    return (os.time() - creature:GetData("lastCastTimeHeal")) > castingCooldown
  end

  --[[
    CanCastNextHealFriendly

    @creature Reference to creature
    @spell Spell to cast
    @return true or false
  --]]

  function RaiCombat:CanCastNextHealFriendly(creature, spell)
    if RaiCombat:Casting(creature) then return false end
    if not creature:GetData("lastCastTimeHeal") then return true end

    local castingCooldown = cooldowns["heal"]
    return (os.time() - creature:GetData("lastCastTimeHeal")) > castingCooldown
  end


  --[[
    CanCastNextBuffSelf()

    @creature Reference to creature
    @spell The buff spell
    @return true or false
  --]]
  function RaiCombat:CanCastNextBuffSelf(creature, spell)
    if creature:HasAura(spell) then return false end
    if RaiCombat:Casting(creature) then return false end
    if not creature:GetData("lastCastTimeBuff") then return true end

    local castingCooldown = cooldowns["buff"]
    return (os.time() - creature:GetData("lastCastTimeBuff")) > castingCooldown
  end

  --[[
    CanCastNextBuffFriendly()

    @creature Reference to creature
    @return true or false
  --]]

  function RaiCombat:CanCastNextBuffFriendly(creature)
    if RaiCombat:Casting(creature) then return false end
    if not creature:GetData("lastCastTimeBuff") then return true end

    local castingCooldown = cooldowns["buff"]
    return (os.time() - creature:GetData("lastCastTimeBuff")) > castingCooldown
  end

  --[[
    CastSpellVictim()

    @creature Reference to creature
    @spell Spell to cast
    @return Nothing
  --]]
  function RaiCombat:CastSpellVictim(creature, spell)
    creature:CastSpellRAI(creature:GetVictim(), spell, true)
  end

  --[[
    CastSpellRandom()

    @creature Reference to creature
    @spell Spell to cast
    @return nothing
  --]]
  function RaiCombat:CastSpellRandom(creature, spell)
    local targets = creature:GetAITargets()

    local target = nil
    if #targets > 1 then 
      target = targets[math.random(1, #targets)]
    else
      target = targets[1]
    end

    if target then 
      creature:CastSpellRAI(target, spell, true)
    end
  end
  --[[
    WARNING! DEPRECATED - SHOULD NOT BE USED
    CastSpellAll()

    @creature Reference to creature
    @spell Spell to cast
    @return nothing
  --]]
  function RaiCombat:CastSpellAll(creature, spell)
    local targets = creature:GetAITargets()

    for i=1, #targets do 
      creature:CastSpell(targets[i], spell, true)
    end
  end

  --[[
    CastHeal

    @creature Reference to creature
    @spell Spell to cast
    @return nothing
  --]]
  function RaiCombat:CastHeal(creature, spell)
    if RaiCombat:CanCastNextHealSelf(creature) then 
      RaiCombat:CastHealSelf(creature, spell)
    elseif RaiCombat:CanCastNextHealFriendly(creature) then
      RaiCombat:CastHealFriendly(creature, spell)
    end
  end

  --[[
    CastHealSelf

    @creature Reference to creature
    @spell Spell to cast
    @return nothing
  --]]
  function RaiCombat:CastHealSelf(creature, spell)
    creature:SetData("lastCastTimeHeal", os.time())
    creature:CastSpellRAI(creature, spell, true)
  end

  --[[
    CastHealFriendly

    @creature Reference to creature caster
    @spell Spell to cast
    @return nothing    
  --]]
  function RaiCombat:CastHealFriendly(creature, spell)
    local creatures = creature:GetCreaturesInRange(15, 0, 2, 1)
    local casted = false

    for k, v in ipairs(creatures) do 
      if v:GetHealthPct() < 90 then
        creature:CastSpellRAI(v, spell, true)
        casted = true
      end
    end

    if not casted and creatures ~= nil then 
      if #creatures >= 1 then 
        local randomFriendly = creatures[math.random(1, #creatures)]

        if randomFriendly ~= nil then 
          if randomFriendly:GetHealthPct() < 95 then 
            creature:CastSpellRAI(randomFriendly, spell, true)
            casted = true
          end
        end
      end
    end

    if casted then
      creature:SetData("lastCastTimeHeal", os.time())
    end
  end

  --[[
    CastBuff

    @creature Reference to creature
    @spell Spell to cast
    @return nothing
  --]]

  function RaiCombat:CastBuff(creature, spell)
    if RaiCombat:CanCastNextBuffSelf(creature, spell) then 
      RaiCombat:CastBuffSelf(creature, spell)
    elseif RaiCombat:CanCastNextBuffFriendly(creature) then 
      RaiCombat:CastBuffFriendly(creature, spell)
    end
  end

  --[[
    CastBuffSelf

    @creature Reference to creature
    @spell Spell to cast
    @return nothing
  --]]
  function RaiCombat:CastBuffSelf(creature, spell)
    creature:SetData("lastCastTimeBuff", os.time())
    creature:CastSpellRAI(creature, spell, true)
  end

  --[[
    CastBuffFriendly

    @creature Reference to creature
    @spell spell to cast
    @return nothing
  --]]

  function RaiCombat:CastBuffFriendly(creature, spell)
    local creatures = creature:GetCreaturesInRange(15, 0, 2, 1)
    local target = nil

    for k, v in ipairs(creatures) do 
      if not v:HasAura(spell) then
        target = v
      end
    end

    if target ~= nil then 
      creature:SetData("lastCastTimeBuff", os.time())
      creature:CastSpellRAI(target, spell, true)
    end
  end

  return RaiCombat
end

return RaiCombat