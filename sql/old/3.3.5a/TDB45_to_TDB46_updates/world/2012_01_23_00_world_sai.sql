-- Windle Sparkshine SAI
SET @ENTRY := 29261;
SET @SPELL_LIGHT_LAMP := 60535;
UPDATE `gameobject` SET `state`=1 WHERE `id` IN (191444,192086,192085,192084,192087,192089,192088,192067,191445,192850,192853,192854,192852,192083,191440,192070,192069,192117,192116,192119,191665);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,68,0,100,0,25,0,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - Game Event 25 Start - Start WP"),
(@ENTRY,0,1,0,40,0,100,0,1,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 1 - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,5,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 5 - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,8,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 8 - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,12,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 12 - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,16,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 16 - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,20,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 20 - Run Script"),
(@ENTRY,0,7,0,40,0,100,0,24,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 24 - Run Script"),
(@ENTRY,0,8,0,40,0,100,0,29,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 29 - Run Script"),
(@ENTRY,0,9,0,40,0,100,0,33,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 33 - Run Script"),
(@ENTRY,0,10,0,40,0,100,0,36,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 36 - Run Script"),
(@ENTRY,0,11,0,40,0,100,0,38,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 38 - Run Script"),
(@ENTRY,0,12,0,40,0,100,0,45,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 45 - Run Script"),
(@ENTRY,0,13,0,40,0,100,0,48,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 48 - Run Script"),
(@ENTRY,0,14,0,40,0,100,0,53,@ENTRY,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - At WP 53 - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,3500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - On Script - Pause WP"),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,11,@SPELL_LIGHT_LAMP,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windle Sparkshine - On Script - Cast Light Lamp"),
(@ENTRY,0,15,0,40,0,100,0,1,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.654867,"Windle Sparkshine - At WP 56 - Set Orientation");

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5747.069,685.3748,643.8239,'Windle Sparkshine'), -- Lamp 1
(@ENTRY,2,5749.971,682.7211,643.4057,'Windle Sparkshine'),
(@ENTRY,3,5760.647,698.313,642.3947,'Windle Sparkshine'),
(@ENTRY,4,5770.979,712.3667,641.5851,'Windle Sparkshine'),
(@ENTRY,5,5771.641,718.9518,641.9728,'Windle Sparkshine'), -- Lamp 2
(@ENTRY,6,5793.795,719.567,640.5906,'Windle Sparkshine'),
(@ENTRY,7,5806.629,718.5358,640.7841,'Windle Sparkshine'),
(@ENTRY,8,5807.11,723.0623,641.0547,'Windle Sparkshine'), -- Lamp 3
(@ENTRY,9,5812.014,718.6132,640.9974,'Windle Sparkshine'),
(@ENTRY,10,5825.027,714.0911,640.9233,'Windle Sparkshine'),
(@ENTRY,11,5836.411,706.2252,641.2604,'Windle Sparkshine'),
(@ENTRY,12,5838.926,710.4177,641.3674,'Windle Sparkshine'), -- Lamp 4
(@ENTRY,13,5836.411,706.2252,641.2604,'Windle Sparkshine'),
(@ENTRY,14,5850.628,692.9323,642.3394,'Windle Sparkshine'),
(@ENTRY,15,5871.261,679.3507,643.1625,'Windle Sparkshine'),
(@ENTRY,16,5889.708,676.6304,643.6068,'Windle Sparkshine'), -- Lamp 5
(@ENTRY,17,5885.975,668.9486,643.8263,'Windle Sparkshine'),
(@ENTRY,18,5894.604,656.5289,644.8455,'Windle Sparkshine'),
(@ENTRY,19,5893.215,644.1390,645.6358,'Windle Sparkshine'),
(@ENTRY,20,5891.531,635.5212,647.5772,'Windle Sparkshine'), -- Lamp 6
(@ENTRY,21,5885.393,639.2025,646.5132,'Windle Sparkshine'),
(@ENTRY,22,5878.637,630.1852,647.6648,'Windle Sparkshine'),
(@ENTRY,23,5865.146,615.7023,650.0197,'Windle Sparkshine'),
(@ENTRY,24,5867.964,613.0705,650.4550,'Windle Sparkshine'), -- Lamp 7
(@ENTRY,25,5865.146,615.7023,650.0197,'Windle Sparkshine'),
(@ENTRY,26,5854.076,607.8509,650.7210,'Windle Sparkshine'),
(@ENTRY,27,5840.764,590.5446,650.6240,'Windle Sparkshine'),
(@ENTRY,28,5837.371,583.0912,650.7756,'Windle Sparkshine'),
(@ENTRY,29,5840.763,580.3890,651.8137,'Windle Sparkshine'), -- Lamp 8
(@ENTRY,30,5837.371,583.0912,650.7756,'Windle Sparkshine'),
(@ENTRY,31,5822.904,570.0418,650.1446,'Windle Sparkshine'),
(@ENTRY,32,5805.871,564.1931,650.1898,'Windle Sparkshine'),
(@ENTRY,33,5796.087,561.1876,650.6658,'Windle Sparkshine'), -- Lamp 9
(@ENTRY,34,5796.753,566.2323,650.1285,'Windle Sparkshine'),
(@ENTRY,35,5772.444,583.8340,649.8836,'Windle Sparkshine'),
(@ENTRY,36,5767.615,579.1342,650.2487,'Windle Sparkshine'), -- Lamp 10
(@ENTRY,37,5761.446,588.7081,649.6515,'Windle Sparkshine'),
(@ENTRY,38,5750.556,591.0724,649.8145,'Windle Sparkshine'), -- Lamp 11
(@ENTRY,39,5749.783,599.296,649.0384,'Windle Sparkshine'),
(@ENTRY,40,5737.969,611.5457,647.9193,'Windle Sparkshine'),
(@ENTRY,41,5726.467,621.8894,646.9294,'Windle Sparkshine'),
(@ENTRY,42,5714.581,625.4625,646.4603,'Windle Sparkshine'),
(@ENTRY,43,5702.122,627.8116,646.3648,'Windle Sparkshine'),
(@ENTRY,44,5693.323,629.3795,646.5901,'Windle Sparkshine'),
(@ENTRY,45,5687.516,629.6511,647.1143,'Windle Sparkshine'), -- Lamp 12
(@ENTRY,46,5692.803,651.879,646.5027,'Windle Sparkshine'),
(@ENTRY,47,5696.018,667.5477,645.7817,'Windle Sparkshine'),
(@ENTRY,48,5695.917,678.2612,646.0887,'Windle Sparkshine'), -- Lamp 13
(@ENTRY,49,5700.438,674.0465,645.4587,'Windle Sparkshine'),
(@ENTRY,50,5714.589,662.3508,645.9952,'Windle Sparkshine'),
(@ENTRY,51,5723.479,658.3279,646.0461,'Windle Sparkshine'),
(@ENTRY,52,5728.87,666.1133,645.8447,'Windle Sparkshine'),
(@ENTRY,53,5726.601,666.7487,645.8505,'Windle Sparkshine'), -- Lamp 14
(@ENTRY,54,5736.254,665.7919,644.9579,'Windle Sparkshine'),
(@ENTRY,55,5744.996,676.1825,644.0975,'Windle Sparkshine'),
(@ENTRY,56,5744.94,681.546,644.136,'Windle Sparkshine'); -- Homeposition

-- Conditions for spell 'Light Lamp'
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_LIGHT_LAMP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,@SPELL_LIGHT_LAMP,0,18,0,191444,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192086,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192085,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192084,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192087,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192089,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192088,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192067,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,191445,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192850,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192853,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192854,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192852,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192083,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,191440,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192070,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192069,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192117,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192116,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,192119,0,0,'',NULL),
(13,0,@SPELL_LIGHT_LAMP,0,18,0,191665,0,0,'',NULL);
