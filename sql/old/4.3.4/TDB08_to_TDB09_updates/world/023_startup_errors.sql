--
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (643,17809,17811,17812);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (643,17809,17811,17812);
