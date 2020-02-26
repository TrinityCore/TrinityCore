-- Create new reference loot template for Shadowfang Keep
SET @ENTRY := 1055;  -- need a new id

DELETE FROM `reference_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(@ENTRY, 1318, 0, 1, "Night Reaver"),
(@ENTRY, 1482, 0, 1, "Shadowfang"),
(@ENTRY, 1483, 0, 1, "Face Smasher"),
(@ENTRY, 1484, 0, 1, "Witching Stave"),
(@ENTRY, 1489, 0, 1, "Gloomshroud Armor"),
(@ENTRY, 1935, 0, 1, "Assassin's Blade"),
(@ENTRY, 1974, 0, 1, "Mindthrust Bracers"),
(@ENTRY, 2205, 0, 1, "Duskbringer"),
(@ENTRY, 2292, 0, 1, "Necrology Robes"),
(@ENTRY, 2807, 0, 1, "Guillotine Axe"),
(@ENTRY, 3194, 0, 1, "Black Malice");

-- Remove all SFK exclusive items from direct drops from NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN
(1318, 1482, 1483, 1484, 1489, 1935, 1974, 2205, 2292, 2807, 3194);

-- Add SFK reference template for non-boss NPCs
DELETE FROM `creature_loot_template` WHERE `Reference` = @ENTRY;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `Comment`) VALUES
(2529, @ENTRY, @ENTRY, 0.1, "Son of Arugal - SFK Rares"),
(3851, @ENTRY, @ENTRY, 0.1, "Shadowfang Whitescalp - SFK Rares"),
(3853, @ENTRY, @ENTRY, 0.1, "Shadowfang Moonwalker - SFK Rares"),
(3854, @ENTRY, @ENTRY, 0.1, "Shadowfang Wolfguard - SFK Rares"),
(3855, @ENTRY, @ENTRY, 0.1, "Shadowfang Darksoul - SFK Rares"),
(3857, @ENTRY, @ENTRY, 0.1, "Shadowfang Glutton - SFK Rares"),
(3859, @ENTRY, @ENTRY, 0.1, "Shadowfang Ragetooth - SFK Rares"),
(3861, @ENTRY, @ENTRY, 0.1, "Bleak Worg - SFK Rares"),
(3862, @ENTRY, @ENTRY, 0.1, "Slavering Worg - SFK Rares"),
(3863, @ENTRY, @ENTRY, 0.1, "Lupine Horror - SFK Rares"),
(3866, @ENTRY, @ENTRY, 0.1, "Vile Bat - SFK Rares"),
(3868, @ENTRY, @ENTRY, 0.1, "Blood Seeker - SFK Rares"),
(3873, @ENTRY, @ENTRY, 0.1, "Tormented Officer - SFK Rares"),
(3875, @ENTRY, @ENTRY, 0.1, "Haunted Servitor - SFK Rares"),
(3877, @ENTRY, @ENTRY, 0.1, "Wailing Guardsman - SFK Rares");
