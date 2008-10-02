-- create fields
ALTER TABLE `creature_addon`
    ADD COLUMN `auras` text DEFAULT NULL AFTER `emote`;
ALTER TABLE `creature_template_addon`
    ADD COLUMN `auras` text DEFAULT NULL AFTER `emote`;

-- move data
UPDATE `creature_template_addon` SET `auras`=CONCAT(`aura`," 0") WHERE `aura`!=0;

-- create missing records
INSERT IGNORE INTO `creature_addon` (`guid`) SELECT `guid` FROM `creature` WHERE `auras` IS NOT NULL AND TRIM(`auras`)!="";
-- move data
UPDATE `creature_addon`,`creature` SET `creature_addon`.`auras`=`creature`.`auras` WHERE `creature_addon`.`guid`=`creature`.`guid` AND `creature`.`auras` IS NOT NULL AND TRIM(`creature`.`auras`)!="";

-- prepare fields
UPDATE `creature_addon` SET `auras`="" WHERE `auras` IS NULL AND `aura`!=0;
UPDATE `creature_addon` SET `auras`=CONCAT(`auras`," ") WHERE `auras`!="" AND `aura`!=0;
-- move data
UPDATE `creature_addon` SET `auras`=CONCAT(`auras`,`aura`," 0") WHERE `aura`!=0;

-- Cleanup
ALTER TABLE `creature_addon`
    DROP COLUMN `aura`,
    DROP COLUMN `auraflags`,
    DROP COLUMN `auralevels`,
    DROP COLUMN `auraapplications`,
    DROP COLUMN `aurastate`;

ALTER TABLE `creature_template_addon`
    DROP COLUMN `aura`,
    DROP COLUMN `auraflags`,
    DROP COLUMN `auralevels`,
    DROP COLUMN `auraapplications`,
    DROP COLUMN `aurastate`;

ALTER TABLE `creature`
    DROP COLUMN `auras`;
