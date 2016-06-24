--[[
Author: Rochet2 - https://rochet2.github.io/
Source: http://emudevs.com/showthread.php/53-Lua-Enchant-visual-system-and-gossip

About:
All weapons looted have a 25% chance to have a random enchant visual
This is purely visual fun and the visual will be replaced when the weapon is enchanted.

This script is 100% automatic. You can only put it to your script folder and it will work.
]]

local chance = 1.0

-- Do not edit anything below

local charactersSQL = [[
CREATE TABLE IF NOT EXISTS `custom_item_enchant_visuals` (
    `iguid` INT(10) UNSIGNED NOT NULL COMMENT 'item DB guid',
    `display` INT(10) UNSIGNED NOT NULL COMMENT 'enchantID',
    PRIMARY KEY (`iguid`)
)
COMMENT='stores the enchant IDs for the visuals'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;
]]
CharDBQuery(charactersSQL)

-- script variables:
local EQUIPMENT_SLOT_MAINHAND = 15
local EQUIPMENT_SLOT_OFFHAND = 16
local PLAYER_VISIBLE_ITEM_1_ENCHANTMENT = 284
local PERM_ENCHANTMENT_SLOT = 0
local DD

-- functions
local LoadDB, setVisual, applyVisuals, LOGIN

function LoadDB()
    DD = {}
    CharDBQuery("DELETE FROM custom_item_enchant_visuals WHERE NOT EXISTS(SELECT 1 FROM item_instance WHERE custom_item_enchant_visuals.iguid = item_instance.guid)")
    local Q = CharDBQuery("SELECT iguid, display FROM custom_item_enchant_visuals")
    if (Q) then
        repeat
            local iguid, display = Q:GetUInt32(0), Q:GetUInt32(1)
            DD[iguid] = display
        until not Q:NextRow()
    end
end
LoadDB()

function setVisual(player, item, display)
    if (not player or not item) then return
        false
    end
    local iguid = item:GetGUIDLow()
    local enID = item:GetEnchantmentId(PERM_ENCHANTMENT_SLOT) or 0
    if (enID ~= 0) then
        CharDBExecute("DELETE FROM custom_item_enchant_visuals WHERE iguid = "..iguid)
        DD[iguid] = nil
        display = enID
    elseif (not display) then
        if (not DD[iguid]) then
            return false
        end
        display = DD[iguid]
    else
        CharDBExecute("REPLACE INTO custom_item_enchant_visuals (iguid, display) VALUES ("..iguid..", "..display..")")
        DD[iguid] = display
    end
    if (item:IsEquipped()) then
        player:SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (item:GetSlot() * 2), 0, display)
    end
    return true
end

function applyVisuals(player)
    if (not player) then
        return
    end
    for i = EQUIPMENT_SLOT_MAINHAND, EQUIPMENT_SLOT_OFFHAND do
        setVisual(player, player:GetItemByPos(255, i))
    end
end

function LOGIN(event, player)
    applyVisuals(player)
end

RegisterPlayerEvent(3, LOGIN)
RegisterPlayerEvent(29, function(e,p,i,b,s) setVisual(p, i) end)

-- Enchant IDs
local E = {3789, 3854, 3273, 3225, 3870, 1899, 2674, 2675, 2671, 2672, 3365, 2673, 2343, 425, 3855, 1894, 1103, 1898, 3345, 1743, 3093, 1900, 3846, 1606, 283, 1, 3265, 2, 3, 3266, 1903, 13, 26, 7, 803, 1896, 2666, 253789, 3854, 3273, 3225, 3870, 1899, 2674, 2675, 2671, 2672, 3365, 2673, 2343, 425, 3855, 1894, 1103, 1898, 3345, 1743, 3093, 1900, 3846, 1606, 283, 1, 3265, 2, 3, 3266, 1903, 13, 26, 7, 803, 1896, 2666, 25}
local SubClasses = {
    [0] = true,
    [1] = true,
    [4] = true,
    [5] = true,
    [6] = true,
    [7] = true,
    [8] = true,
    [10] = true,
    [11] = true,
    [12] = true,
    [14] = true,
    [15] = true,
}

math.randomseed(os.time())
local function ONITEMLOOT(event, player, item, count, guid)
    if (item:GetClass() == 2 and SubClasses[item:GetSubClass()]) then
        if (math.random() < chance) then -- 25% of looted weapons get the visuals
            setVisual(player, item, E[math.random(#E)])
        end
    end
end

RegisterPlayerEvent(32, ONITEMLOOT)