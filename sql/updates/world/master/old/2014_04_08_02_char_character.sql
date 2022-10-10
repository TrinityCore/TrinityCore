ALTER TABLE  `characters` CHANGE  `petslotused`  `petslot` LONGTEXT CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL;
UPDATE `characters` SET `petslot` = 0;