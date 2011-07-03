-- Startup Fixes for Greymane's custom SQL

-- Drop unused  reference loot rows
DELETE FROM `reference_loot_template` WHERE `entry` IN (12020,12021,12022,34126,34127);

-- Add/fix proper loot conditions to greymane's custom loot fixes
UPDATE `conditions` SET `SourceGroup` = 27081 WHERE SourceEntry = 45788; -- Freya Sigil 10M
UPDATE `conditions` SET `SourceGroup` = 27086 WHERE SourceEntry = 45787; -- Mimiron Sigil 10M
UPDATE `conditions` SET `SourceGroup` = 27074 WHERE SourceEntry = 45784; -- Thorim Sigil 10M
UPDATE `conditions` SET `SourceGroup` = 26962 WHERE SourceEntry = 45814; -- Freya Sigil 25M
UPDATE `conditions` SET `SourceGroup` = 26967 WHERE SourceEntry = 45816; -- Mimiron Sigil 25M

-- Fix proper lootmode on freya's sigil
UPDATE `gameobject_loot_template` SET `lootmode` = 1 WHERE `item` IN (45788,45814) AND `entry` IN (27081,26962);
-- Add Condition for hodirs sigil drop
DELETE FROM `conditions` WHERE `SourceEntry` = 45786;
INSERT INTO `conditions` VALUES
(4,27069,45786,0,9,13609,0,0,0,'',NULL),
(4,26950,45815,0,9,13822,0,0,0,'',NULL);
