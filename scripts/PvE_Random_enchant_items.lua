function RollEnchant(item)
	rarityRoll = math.random(25)
	local itemClass = ""
	if (item:GetClass() == 2) then
		itemClass = "WEAPON"
	elseif (item:GetClass() == 4) then
		itemClass = "ARMOR"
	end
	if (rarityRoll <= 44) then
		local query = WorldDBQuery("SELECT enchantID FROM item_enchantment_random_tiers WHERE tier=1 AND exclusiveSubClass=NULL AND class='"..itemClass.."' OR exclusiveSubClass="..item:GetSubClass().." OR class='ANY' ORDER BY RAND() LIMIT 1")
		return query:GetUInt32(0)
	elseif (rarityRoll <= 64) then
		local query = WorldDBQuery("SELECT enchantID FROM item_enchantment_random_tiers WHERE tier=2 AND exclusiveSubClass=NULL AND class='"..itemClass.."' OR exclusiveSubClass="..item:GetSubClass().." OR class='ANY' ORDER BY RAND() LIMIT 1")
		return query:GetUInt32(0)
	elseif (rarityRoll <= 79) then
		local query = WorldDBQuery("SELECT enchantID FROM item_enchantment_random_tiers WHERE tier=3 AND exclusiveSubClass=NULL AND class='"..itemClass.."' OR exclusiveSubClass="..item:GetSubClass().." OR class='ANY' ORDER BY RAND() LIMIT 1")
		return query:GetUInt32(0)
	elseif (rarityRoll <= 92) then
		local query = WorldDBQuery("SELECT enchantID FROM item_enchantment_random_tiers WHERE tier=4 AND exclusiveSubClass=NULL AND class='"..itemClass.."' OR exclusiveSubClass="..item:GetSubClass().." OR class='ANY' ORDER BY RAND() LIMIT 1")
		return query:GetUInt32(0)
	else
		local query = WorldDBQuery("SELECT enchantID FROM item_enchantment_random_tiers WHERE tier=5 AND exclusiveSubClass=NULL AND class='"..itemClass.."' OR exclusiveSubClass="..item:GetSubClass().." OR class='ANY' ORDER BY RAND() LIMIT 1")
		return query:GetUInt32(0)
	end
end

function OnLoot(event, player, item, count)
	local slotBools		= {}
	local slotIDs		= {}
	local its			= 0
	
	local boolRoll1		= math.random(100)
	if (boolRoll1 >= 60) then 
		slotBools[1]	= true
		slotIDs[1]		= RollEnchant(item)
	else slotBools[1]	= false 
	end
	
	local boolRoll2		= math.random(100)
	if (boolRoll2 >=65) and (slotBools[1] == true) then
		slotBools[2]	= true
		slotIDs[2]		= RollEnchant(item)
	else slotBools[2] = false
	end
	
	local boolRoll3		= math.random(100)
	if (boolRoll2 >=70) and (slotBools[2] == true) then
		slotBools[3]	= true
		slotIDs[3]		= RollEnchant(item)
	else slotBools[3] = false
	end
	
	local boolRoll4		= math.random(100)
	if (boolRoll2 >=75) and (slotBools[3] == true) then
		slotBools[4]	= true
		slotIDs[4]		= RollEnchant(item)
	else slotBools[4] = false
	end
	
	if (slotBools[1] == true) then
		for i, id in ipairs(slotIDs) do
			if (its == 2) then
				its = its + 3
			end
			if (slotBools[i] == true) then
				item:SetEnchantment(id, its)
				its = its + 1
			end
		end
	end	
end

RegisterPlayerEvent(32, OnLoot)