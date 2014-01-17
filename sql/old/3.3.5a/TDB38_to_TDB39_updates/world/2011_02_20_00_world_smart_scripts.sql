ALTER TABLE `smart_scripts` CHANGE `entryorguid` `entryorguid` INT(32) NOT NULL;
ALTER TABLE `smart_scripts` MODIFY `action_param1` INT(32) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `smart_scripts` MODIFY `action_param2` INT(32) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `smart_scripts` MODIFY `action_param3` INT(32) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `smart_scripts` MODIFY `action_param4` INT(32) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `smart_scripts` MODIFY `action_param5` INT(32) UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE `smart_scripts` MODIFY `action_param6` INT(32) UNSIGNED NOT NULL DEFAULT 0;
