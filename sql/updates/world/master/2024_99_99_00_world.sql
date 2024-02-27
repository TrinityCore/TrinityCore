-- Convert existing data to static flags. There may be some errors in conversion due to dirty unit flag that that's been dumped into the DB which needs manual fixups

-- CREATURE_STATIC_FLAG_CAN_SWIM
UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template` AS ct ON ct.`entry` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` | 0x10000000
WHERE (ct.`unit_flags` & 0x00008000) != 0;

UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template` AS ct ON ct.`entry` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` &~ 0x00000100
WHERE (ct.`unit_flags` & 0x00008000) != 0;

-- CREATURE_STATIC_FLAG_CANT_SWIM
UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template` AS ct ON ct.`entry` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` | 0x00000100
WHERE (ct.`unit_flags` & 0x00004000) != 0;

UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template` AS ct ON ct.`entry` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` &~ 0x10000000
WHERE (ct.`unit_flags` & 0x00004000) != 0;

-- CREATURE_STATIC_FLAG_AMPHIBIOUS
UPDATE `creature_template_difficulty` AS ctd 
LEFT JOIN `creature_template_movement` AS ctm ON ctm.`CreatureId` = ctd.`Entry` 
LEFT JOIN `creature_template` AS ct ON ct.`entry` = ctd.`Entry` 
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` | 0x00080000
WHERE ctm.`Ground`= 1 AND ctm.`Swim`= 1 AND (ct.`unit_flags` & 0x00008000) = 0;

-- CREATURE_STATIC_FLAG_SESSILE
UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template_movement` AS ctm ON ctm.`CreatureId` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` | 0x00000100
WHERE ctm.`Rooted`= 1;

-- CREATURE_STATIC_FLAG_FLOATING
UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template_movement` AS ctm ON ctm.`CreatureId` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` | 0x20000000
WHERE ctm.`Flight`!= 0;

-- CREATURE_STATIC_FLAG_AQUATIC
UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template_movement` AS ctm ON ctm.`CreatureId` = ctd.`Entry`
SET ctd.`StaticFlags1`= ctd.`StaticFlags1` | 0x00040000
WHERE ctm.`Ground`= 0 AND ctm.`Swim`= 1;

-- CREATURE_STATIC_FLAG_3_CANNOT_TURN
UPDATE `creature_template_difficulty` AS ctd LEFT JOIN `creature_template` AS ct ON ct.`entry` = ctd.`Entry`
SET ctd.`StaticFlags3`= ctd.`StaticFlags3` | 0x02000000
WHERE (ct.`unit_flags2` & 0x00008000) != 0;

-- Remove unit flags that are now handled by static flags
UPDATE `creature_template` SET `unit_flags`= `unit_flags` &~ (0x00008000 | 0x00004000);
UPDATE `creature_template` SET `unit_flags2`= `unit_flags2` &~ 0x00008000;

-- Add new movement settings
ALTER TABLE `creature_template_movement`   
	ADD COLUMN `HoverInitiallyEnabled` TINYINT UNSIGNED NULL AFTER `CreatureId`;

UPDATE `creature_template_movement` SET `HoverInitiallyEnabled`= 1 WHERE `Ground` = 2;

ALTER TABLE `creature_movement_override`   
	ADD COLUMN `HoverInitiallyEnabled` TINYINT UNSIGNED NULL AFTER `SpawnId`;

UPDATE `creature_movement_override` SET `HoverInitiallyEnabled`= 1 WHERE `Ground` = 2;

-- Remove deprecated CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE
UPDATE `creature_template` SET `flags_extra`= `flags_extra` &~ 0x200;

-- Conversion done. Drop old columns
ALTER TABLE `creature_movement_override`   
	DROP COLUMN `Ground`, 
	DROP COLUMN `Swim`, 
	DROP COLUMN `Flight`, 
	DROP COLUMN `Rooted`;

ALTER TABLE `creature_template_movement`   
	DROP COLUMN `Ground`, 
	DROP COLUMN `Swim`, 
	DROP COLUMN `Flight`, 
	DROP COLUMN `Rooted`;

-- Converted a couple script hacks to static flags where they belong
UPDATE `creature_template_difficulty` SET `StaticFlags1`= `StaticFlags1` | 0x00000100 WHERE `Entry` IN (37081, 38038);
