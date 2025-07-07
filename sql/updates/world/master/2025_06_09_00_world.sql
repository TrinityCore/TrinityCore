SET @REFERENCEID := 450000;

-- Adarogg
UPDATE `creature_template_difficulty` SET `LootID` = 61408, `GoldMin` = 65000, `GoldMax` = 75000 WHERE `Entry` = 61408;

DELETE FROM `creature_loot_template` WHERE `Entry` = 61408;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(61408, 1, @REFERENCEID+0, 100, 0, 1, 0, 1, 2, 'Reference Adarogg Boss loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 82879, 0, 0, 1, 1, 1, 1, 'Collarspike Bracers'),
(@REFERENCEID+0, 0, 82772, 0, 0, 1, 1, 1, 1, 'Snarlsmouth Leggins'),
(@REFERENCEID+0, 0, 82880, 0, 0, 1, 1, 1, 1, 'Fang of Adarogg'),
(@REFERENCEID+0, 0, 151421, 0, 0, 1, 1, 1, 1, 'Scorched Blazehound Boots'),
(@REFERENCEID+0, 0, 151422, 0, 0, 1, 1, 1, 1, 'Bonecoal Waistguard');

-- Dark Shaman Koranthal
UPDATE `creature_template_difficulty` SET `LootID` = 61412, `GoldMin` = 65000, `GoldMax` = 75000 WHERE `Entry` = 61412;

DELETE FROM `creature_loot_template` WHERE `Entry` = 61412;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(61412, 1, @REFERENCEID+1, 100, 0, 1, 0, 1, 2, 'Reference Dark Shaman Koranthal Boss loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+1;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+1, 0, 82882, 0, 0, 1, 1, 1, 1, 'Dark Ritual Cape'),
(@REFERENCEID+1, 0, 82877, 0, 0, 1, 1, 1, 1, 'Grasp of the Broken Totem'),
(@REFERENCEID+1, 0, 82881, 0, 0, 1, 1, 1, 1, 'Cuffs of Black Elements'),
(@REFERENCEID+1, 0, 132551, 0, 0, 1, 1, 1, 1, 'Dark Shamans Jerkin');

-- Slagmaw
UPDATE `creature_template_difficulty` SET `LootID` = 61463, `GoldMin` = 65000, `GoldMax` = 75000 WHERE `Entry` = 61463;

DELETE FROM `creature_loot_template` WHERE `Entry` = 61463;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(61463, 1, @REFERENCEID+2, 100, 0, 1, 0, 1, 2, 'Reference Slagmaw Boss loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+2;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+2, 0, 82885, 0, 0, 1, 1, 1, 1, 'Flameseared Carapace'),
(@REFERENCEID+2, 0, 82884, 0, 0, 1, 1, 1, 1, 'Chitonous Bracers'),
(@REFERENCEID+2, 0, 82878, 0, 0, 1, 1, 1, 1, 'Fireworm Robes'),
(@REFERENCEID+2, 0, 132552, 0, 0, 1, 1, 1, 1, 'Chitonous Bindings');

-- Lava Guard Gordoth
UPDATE `creature_template_difficulty` SET `LootID` = 61528, `GoldMin` = 160000, `GoldMax` = 170000 WHERE `Entry` = 61528;

DELETE FROM `creature_loot_template` WHERE `Entry` = 61528;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(61528, 1, @REFERENCEID+3, 100, 0, 1, 0, 1, 2, 'Reference Lava Guard Gordoth Boss loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+3;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+3, 0, 82888, 0, 0, 1, 1, 1, 1, 'Heartboiler Staff'),
(@REFERENCEID+3, 0, 82886, 0, 0, 1, 1, 1, 1, 'Gorewalker Treads'),
(@REFERENCEID+3, 0, 82883, 0, 0, 1, 1, 1, 1, 'Bloodcursed Felblade'),
(@REFERENCEID+3, 0, 151424, 0, 0, 1, 1, 1, 1, 'Beld of Boundless Fury'),
(@REFERENCEID+3, 0, 151425, 0, 0, 1, 1, 1, 1, 'Gordoths Crushers');
