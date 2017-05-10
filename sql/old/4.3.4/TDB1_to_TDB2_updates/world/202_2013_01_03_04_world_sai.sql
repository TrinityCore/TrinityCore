-- UPDATE `gameobject` SET `position_x`=-113.4616,`position_y`=2165.083,`position_z`=156.7546,`orientation`=1.195702,`rotation0`=0.6946974,`rotation1`=-0.1318922,`rotation2`=0.6946964,`rotation3`=0.1318972,`spawntimesecs`=7200,`animprogress`=255 WHERE `guid`=32480;

DELETE FROM `gameobject_scripts` WHERE `id` IN (32260,32378,32480,32625,32442,32443,32444,34006);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (18900,18901,18899,90567,101811,101812,101855,185501);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18900,18901,18899,90567,101811,101812,101855,185501) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
( 18900,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,32445,18934,0,0,0,0,0, 'Lever - On activate - Activate Cell Door'),
( 18901,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,33219,18936,0,0,0,0,0, 'Lever - On activate - Activate Cell Door'),
( 18899,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,33241,18971,0,0,0,0,0, 'Lever - On activate - Activate Arugals Lair'),
( 90567,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,32373,90566,0,0,0,0,0, 'Lever - On activate - Activate Workshop Door'),
(101811,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,32446,18935,0,0,0,0,0, 'Lever - On activate - Activate Cell Door'),
(101812,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,20835,18895,0,0,0,0,0, 'Lever - On activate - Activate Courtyard Door'),
(101855,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,32250,101854,0,0,0,0,0, 'Lever - On activate - Activate Herods Door'),
(185501,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,25064,184212,0,0,0,0,0, 'Waterfall Control Console - On activate - Activate Waterfall');
