-- Apply same loot template to below mentioned Bloodsail NPCs as that of Bloodsail Raider 1561
-- (Mage 1562, Swashbuckler 1563, Warlock 1564, Sea Dog 1565)
UPDATE `creature_template` SET `lootid`=1561 WHERE `entry` IN (1562,1563,1564,1565);
-- Remove Loot from `creature_loot_template` for above mentioned NPCs because it contains only 2 items.
-- Those 2 items, along with complete loot template for these mobs is applied in query above.
DELETE FROM `creature_loot_template` WHERE `entry` IN (1562,1563,1564,1565);
-- Remove loot and gold drop from Bloodsail Warlock's Minions
UPDATE `creature_template` SET `lootid`=0, `mingold`=0 AND `maxgold`=0 WHERE `entry` IN (10928,12922);
DELETE FROM `creature_loot_template` WHERE `entry` IN (10928,12922);
