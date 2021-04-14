-- Remove Wintergrasp commands from command table
DELETE FROM `command` WHERE `name` LIKE '%wg%';
