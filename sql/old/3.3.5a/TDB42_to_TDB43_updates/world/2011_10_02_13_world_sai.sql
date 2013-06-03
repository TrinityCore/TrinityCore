-- Quest:The Armor's Secrets (12980)
DELETE FROM `creature` WHERE `id`=30190;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(6337,30190,571,1,1,0,0,8256.75,-433.488,970.583,4.223697,300,0,0,1,0,0,0,0,0);

-- Anvil and Metel bars
DELETE FROM `gameobject` WHERE `id` IN (192125,192128);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(177,192125,571,1,1,8262.05,-430.288,968.272,0,0,0,-0.861628,0.507539,120,0,1),
(183,192125,571,1,1,8231.716,-451.452576,968.368835,-3.10665226,0,0,0,0,120,0,1),
(181,192128,571,1,1,8281.357,-432.069,970.723,-2.844883,0,0,-0.9890156,0.1478114,120,0,1),
(188,192128,571,1,1,8233.997,-434.379456,970.722961,-2.07693934,0,0,0,0,120,0,1),
(190,192128,571,1,1,8243.935,-429.880981,970.722961,-1.08210289,0,0,0,0,120,0,1),
(194,192128,571,1,1,8246.777,-424.707367,970.722961,-1.16936862,0,0,0,0,120,0,1),
(197,192128,571,1,1,8264.213,-432.40332,975.778564,1.134463,0,0,0,0,120,0,1);

-- Template updates
UPDATE `creature_template` SET `npcflag`=`npcflag`|1,`speed_run`=0.99206 WHERE `entry`=30190; -- Attendant Tock
UPDATE `creature_template` SET `speed_run`=0.99206 WHERE `entry`=30170; -- Mechagnome Attendant

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (30190,30170);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30190,0,0,1,0,NULL), -- Mechagnome Attendant
(30170,0,7,1,0, NULL); -- Attendant Tock

SET @ENTRY=30190;
UPDATE `creature_template` SET `gossip_menu_id`=9880, `AIName`='SmartAI' WHERE entry=@ENTRY;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9880;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9880,0,0,'I found this strange armor plate. Can you tell me more about it?',1,1,0,0,0,0, '');

DELETE FROM `gossip_menu` WHERE `entry`=9880;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9880,13703);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,9880,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Start Script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Remove Gossip Flag'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Close Gossip'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,50,192132,77000,0,0,0,0,8,0,0,0,8262.029,-430.0284,974.1605,-2.757613, 'Attendant Tock - Summon Armor'),
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 0'),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 1'),
(@ENTRY*100,9,5,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,8262.029,-430.0284,976.1391,1.6, 'Attendant Tock - Move'), -- Move
(@ENTRY*100,9,6,0,0,0,100,0,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 2'),
(@ENTRY*100,9,7,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 3'),
(@ENTRY*100,9,8,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 4'),
(@ENTRY*100,9,9,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 5'),
(@ENTRY*100,9,10,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 6'),
(@ENTRY*100,9,11,0,0,0,100,0,5000,5000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 7'),
(@ENTRY*100,9,12,0,0,0,100,0,6000,6000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 8'),
(@ENTRY*100,9,13,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,8256.75,-433.488,970.583,4.223697, 'Attendant Tock - Move Home'),
(@ENTRY*100,9,14,0,0,0,100,0,6000,6000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Speach 9'),
(@ENTRY*100,9,15,0,0,0,100,0,0,0,0,0,33,30190,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Attendant Tock - Quest Credit'),
(@ENTRY*100,9,16,0,0,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attendant Tock - Add Gossip Flag');

DELETE FROM `creature_text` WHERE `entry`=30190;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30190,0,0,'Metallic specimen of foreign origin detected.',12,0,100,0,5,0, 'Attendant Tock'),
(30190,1,0,'Beginning analysis...',12,0,100,0,0,0, 'Attendant Tock'),
(30190,2,0,'Specimen identified as an alloy of saronite and iron.',12,0,100,0,0,0, 'Attendant Tock'),
(30190,3,0,'The ore used in this sample originated deep wihin the crust of Azeroth and was recently unearthed.',12,0,100,275,0,0, 'Attendant Tock'),
(30190,4,0,'The saronite in this sample is nearly pure. Ores like this do not occur naturally on the surface of Azeroth.',12,0,100,0,0,0, 'Attendant Tock'),
(30190,5,0,'This ore can only have been created by a powerful, malevolent force. Attempting to access databanks for more information...',12,0,100,1,0,0, 'Attendant Tock'),
(30190,6,0,'Access denied?!',12,0,100,6,0,0, 'Attendant Tock'),
(30190,7,0,'Further information can only be accessed from the archives within Ulduar, by order of Keeper Loken.',12,0,100,1,0,0, 'Attendant Tock'),
(30190,8,0,'But one thing is for certain: this plate''s size, thickness, and bolt holes point to a use as armor for a colossal structure.',12,0,100,1,0,0, 'Attendant Tock'),
(30190,9,0,'Directive completed. Returning TO standby mode.',12,0,100,1,0,0, 'Attendant Tock');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9880;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9880,0,0,9,12980,0,0,0, '', 'The Armor''s Secrets');
