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
(3870, @ENTRY, @ENTRY, 0.1, "Stone Sleeper - SFK Rares"),
(3873, @ENTRY, @ENTRY, 0.1, "Tormented Officer - SFK Rares"),
(3875, @ENTRY, @ENTRY, 0.1, "Haunted Servitor - SFK Rares"),
(3877, @ENTRY, @ENTRY, 0.1, "Wailing Guardsman - SFK Rares"),
(47131, @ENTRY, @ENTRY, 0.1, "Frantic Geist - SFK Rares"),
(47132, @ENTRY, @ENTRY, 0.1, "Dark Creeper - SFK Rares"),
(47134, @ENTRY, @ENTRY, 0.1, "Corpse Eater - SFK Rares"),
(47135, @ENTRY, @ENTRY, 0.1, "Fetid Ghoul - SFK Rares"),
(47136, @ENTRY, @ENTRY, 0.1, "Unstable Ravager - SFK Rares"),
(47137, @ENTRY, @ENTRY, 0.1, "Mindless Horror - SFK Rares"),
(47138, @ENTRY, @ENTRY, 0.1, "Pustulant Monstrosity - SFK Rares"),
(47140, @ENTRY, @ENTRY, 0.1, "Sorcerous Skeleton - SFK Rares"),
(47141, @ENTRY, @ENTRY, 0.1, "Dread Scryer - SFK Rares"),
(47143, @ENTRY, @ENTRY, 0.1, "Spitebone Skeleton - SFK Rares"),
(47145, @ENTRY, @ENTRY, 0.1, "Spitebone Guardian - SFK Rares"),
(47146, @ENTRY, @ENTRY, 0.1, "Spitebone Flayer - SFK Rares"),
(47231, @ENTRY, @ENTRY, 0.1, "Shadowy Attendant - SFK Rares"),
(47232, @ENTRY, @ENTRY, 0.1, "Ghostly Cook - SFK Rares");
