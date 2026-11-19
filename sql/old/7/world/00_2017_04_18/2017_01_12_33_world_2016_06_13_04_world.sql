UPDATE `creature_template` SET `AIName`='' WHERE `entry`=28092;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28092 AND `source_type`=0;
