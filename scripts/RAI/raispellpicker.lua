local dbHelper = require("raidbhelper").new()
local tableHelper = require("raitablehelper").new()

local RaiSpellPicker = {}

function RaiSpellPicker.new()

  --[[
    OVERVIEW

    Heal()
    Damage()
    Buff()
    Utility()
    FetchSpellCategory()
    FetchSpells()
  --]]

  --[[
    Heal()
    @entry Creature entry
    @return 13121
  --]]
  function RaiSpellPicker:Heal(entry)
    return RaiSpellPicker:FetchSpellCategory(entry, 2)
  end

  --[[
    Damage()
    @entry Creature entry
    @return 13121
  --]]
  function RaiSpellPicker:Damage(entry)
    return RaiSpellPicker:FetchSpellCategory(entry, 1)
  end

  --[[
    Buff()
    @entry Creature entry
    @return 13121
  --]]
  function RaiSpellPicker:Buff(entry)
    return RaiSpellPicker:FetchSpellCategory(entry, 3)
  end

  --[[
    Utility()
    @entry Creature entry
    @return 13121
  --]]
    function RaiSpellPicker:Utility(entry)
    return RaiSpellPicker:FetchSpellCategory(entry, 4)
  end

  --[[
    FetchSpellCategory()
    @entry Creature entry
    @category Category from custom_spell_system_categories
    @return 131221
  --]]

  function RaiSpellPicker:FetchSpellCategory(entry, category)
    local level = dbHelper:GetCreatureLevel(entry)
    local spells = RaiSpellPicker:FetchSpells(level, category)
    return tableHelper:Random(spells) 
  end

  --[[
    FetchSpells()
    @level Creature level
    @category Category from custom_spell_system_categories
    @return {1771, 205..}
  --]]
  function RaiSpellPicker:FetchSpells(level, category)
    local maxLevelDifference = 7 -- If set to 4 and level is 20 spells are selected between level 16-20
    local query = WorldDBQuery(string.format("SELECT * FROM custom_spell_system JOIN custom_spell_system_categories WHERE custom_spell_system.spellID = custom_spell_system_categories.spellID AND category=%i AND spellLevel > %i - %i AND spellLevel < %i", category, level, maxLevelDifference, level))
    local spells = {}

    if query then 
      repeat 

      local row = query:GetRow()
      spells[#spells+1] = row["spellID"]
      until not query:NextRow()
    end

    return spells
  end

  return RaiSpellPicker
end

return RaiSpellPicker