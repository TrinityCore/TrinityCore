-- make types larger so we can fit more values
ALTER TABLE `smart_scripts` MODIFY COLUMN `action_type` int unsigned;
ALTER TABLE `smart_scripts` MODIFY COLUMN `event_type` int unsigned;