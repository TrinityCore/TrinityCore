-- Add reference for Zone Drop Netherstorm Blues
DELETE FROM `reference_loot_template` WHERE `entry`=14501;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(14501,31940,0,1,1,1,1), -- Ethereum Torque
(14501,31936,0,1,1,1,1), -- Fiery Cloak
(14501,31565,0,1,1,1,1), -- Skystalker's Boots
(14501,31573,0,1,1,1,1), -- Mistshroud Boots
(14501,31557,0,1,1,1,1), -- Windchanneller's Boots
(14501,31937,0,1,1,1,1), -- Living Cloak
(14501,31928,0,1,1,1,1), -- Dark Band
(14501,31581,0,1,1,1,1), -- Slatesteel Boots
(14501,31929,0,1,1,1,1), -- Enigmatic Band
(14501,31938,0,1,1,1,1), -- Enigmatic Cloak
(14501,31943,0,1,1,1,1), -- Ethereum Band
(14501,31939,0,1,1,1,1), -- Dark Cloak
(14501,31925,0,1,1,1,1), -- Fiery Band
(14501,31926,0,1,1,1,1), -- Frigid Band
(14501,31927,0,1,1,1,1), -- Living Band
(14501,32520,0,1,1,1,1), -- Manaforged Sphere
(14501,31935,0,1,1,1,1); -- Frigid Cloak
-- Add loot for Protectorate Treasure Cache
UPDATE `item_template` SET `minMoneyLoot`=10000,`maxMoneyLoot`=10000 WHERE `entry`=32064;
DELETE FROM `item_loot_template` WHERE `entry`=32064;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(32064,1,80,1,1,-24013,1), -- one from greens
(32064,2,20,1,1,-14501,1); -- one from blue items
