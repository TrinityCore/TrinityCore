--
UPDATE `smart_scripts` SET `action_type` = 147, `action_param1` = 5, `action_param2` = 0, `comment` = "Dorius Stonetender - On Script - Activate Object (Disturb)" WHERE `entryorguid` IN (828401,828403) AND `source_type` = 9 AND `action_type` = 45;

UPDATE `gameobject_template` SET `AIName` = '' WHERE `entry` IN (147516,147517);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (147516,147517) AND `source_type` = 1;
