SET @entry := 35093;
SET @epic := 25009;
SET @gem := @entry+1;
-- Create references
DELETE FROM `reference_loot_template` WHERE `entry` IN(@entry,@epic,@gem);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@entry,27452,0,1,1,1,1), -- Light Scribe Bands
(@entry,27453,0,1,1,1,1), -- Averinn's RIng of Slaying
(@entry,27454,0,1,1,1,1), -- Volcanic Pauldrons
(@entry,27455,0,1,1,1,1), -- Irondrake faceguard
(@entry,27456,0,1,1,1,1), -- Raiments of Nature's Breath
(@entry,27457,0,1,1,1,1), -- Life Bearer's Gauntlets
(@entry,27458,0,1,1,1,1), -- Oceansong Kilt
(@entry,27459,0,1,1,1,1), -- Vambraces of Daring
(@entry,27460,0,1,1,1,1), -- Reavers' Ring
(@entry,27461,0,1,1,1,1), -- Chestguard of the Prowler
-- Epics
(@epic,29238,0,1,1,1,1), -- Lion's Heart Girdle
(@epic,29264,0,1,1,1,1), -- Tree-Mender's Belt
(@epic,29346,0,1,1,1,1), -- Feltooth Eviscerator
(@epic,32077,0,1,1,1,1), -- Wrath Infused Gauntlets
-- Gems
(@gem,30592,0,1,1,1,1), -- Steady Chrysoprase
(@gem,30593,0,1,1,1,1), -- Potent Fire Opal
(@gem,30594,0,1,1,1,1); -- Regal Chrysoprase
-- Assign loot to the chest
SET @GOloot := 21764; -- lootid of Reinforced Fel Iron Chest Heroic
DELETE FROM `gameobject_loot_template` WHERE `entry`=@GOloot;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@GOloot,1,100,1,0,-@entry, 2), -- one from gear
(@GOloot,2,30,1,0,-@gem,1), -- one gem (30%)
(@GOloot,3,100,1,0,-@epic,1); -- one from epics
