--
UPDATE `creature_template` SET `ainame`='' WHERE `entry` IN (2406,2384);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2406,2384);
