DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (21220,21301);

UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (21220,21301);
