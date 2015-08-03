-- Remove Grimscale Murloc SAI
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`IN (15668);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15668);
