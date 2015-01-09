-- Add Reference Loots
SET @RefNormal := 35091;
SET @RefHeroic := 35092;
DELETE FROM `reference_loot_template` WHERE `entry` IN (@RefNormal,@RefHeroic);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Normal Loot
(@RefNormal,49839,0,1,1,1,1), -- Mourning Malice
(@RefNormal,49840,0,1,1,1,1), -- Hate-Forged Cleaver
(@RefNormal,49841,0,1,1,1,1), -- Blackened Geist Ribs
(@RefNormal,49842,0,1,1,1,1), -- Tapestry of the Frozen Throne
(@RefNormal,49843,0,1,1,1,1), -- Crystalline Citadel Gauntlets
(@RefNormal,49844,0,1,1,1,1), -- Crypt Fiend Slayer
(@RefNormal,49845,0,1,1,1,1), -- Bone Golem Scapula
(@RefNormal,49846,0,1,1,1,1), -- Chilled Heart of the Glacier
(@RefNormal,49847,0,1,1,1,1), -- Legguards of Untimely Demise
(@RefNormal,49848,0,1,1,1,1), -- Grim Lasher Shoulderguards
(@RefNormal,49849,0,1,1,1,1), -- Tattered Glacial-Woven Hood
(@RefNormal,49851,0,1,1,1,1), -- Greathelm of the Silver Hand
-- Heroic Loot
(@RefHeroic,50303,0,1,1,1,1), -- Black Icicle
(@RefHeroic,50302,0,1,1,1,1), -- Liar's Tongue
(@RefHeroic,50311,0,1,1,1,1), -- Second Helm of the Executioner
(@RefHeroic,50312,0,1,1,1,1), -- Chestguard of Broken Branches
(@RefHeroic,50310,0,1,1,1,1), -- Fossilized Ammonite Choker
(@RefHeroic,50313,0,1,1,1,1), -- Oath of Empress Zoe
(@RefHeroic,50309,0,1,1,1,1), -- Shriveled Heart
(@RefHeroic,50314,0,1,1,1,1), -- Strip of Remorse
(@RefHeroic,50308,0,1,1,1,1), -- Blighted Leather Footpads
(@RefHeroic,50305,0,1,1,1,1), -- Grinning Skull Boots
(@RefHeroic,50306,0,1,1,1,1), -- The Lady's Promise
(@RefHeroic,50304,0,1,1,1,1); -- Hoarfrost Gauntlets
-- Assign to the chest
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (27985,27993);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(27985,1,100,1,0,-@RefNormal,2), -- Two from Normal Reference Loot
(27993,1,100,1,0,-@RefHeroic,2), -- Two from Heroic Reference Loot
(27993,43102,85,1,0,1,1); -- Frozen Orb
