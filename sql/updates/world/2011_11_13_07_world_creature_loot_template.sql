-- Add Formula: Enchant Cloak - Superior Arcane Resistance to Frostbrood Spawn & Cult Researcher
DELETE FROM `creature_loot_template` WHERE `entry` IN (31702,32297) AND `item`=37330;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES 
(31702,37330,1.5,1,0,1,1), -- Formula: Enchant Cloak - Superior Arcane Resistance
(32297,37330,0.8,1,0,1,1); -- Formula: Enchant Cloak - Superior Arcane Resistance
