-- Remove incorrect items from Trelane's Chest / Footlocker / Lockbox and Alterac Granite
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (2145,2177,2178,2179) AND `Item` NOT IN (4521,4530,4531,4532);
