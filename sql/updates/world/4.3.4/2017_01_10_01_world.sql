--
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (6207,6210);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6207,6210);
--