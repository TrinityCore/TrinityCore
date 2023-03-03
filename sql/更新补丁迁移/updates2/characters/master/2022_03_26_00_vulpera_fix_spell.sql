ALTER TABLE `characters` 
ADD COLUMN `camp_x` float NULL DEFAULT NULL AFTER `numRespecs`,
ADD COLUMN `camp_y` float NULL DEFAULT NULL AFTER `camp_x`,
ADD COLUMN `camp_z` float NULL DEFAULT NULL AFTER `camp_y`,
ADD COLUMN `camp_o` float NULL DEFAULT NULL AFTER `camp_z`,
ADD COLUMN `camp_mapid` smallint(5) NULL DEFAULT NULL AFTER `camp_o`;