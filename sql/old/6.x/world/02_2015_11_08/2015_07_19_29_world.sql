ALTER TABLE `npc_vendor`
    CHANGE COLUMN `PlayerConditionID` `PlayerConditionID` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `type`;
