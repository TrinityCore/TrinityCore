SET @GOSSIP             := 8301;
SET @EVENT              := 13888;
SET @BLOOD_MOUNT        := 19085;
SET @BORAK              := 21293;
SET @ICARIUS            := 21409;
SET @ZARATH             := 21410;
SET @GOBJECT            := 184798;

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=10356;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP,10356);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,0,0,'Borak, I need another bundle of bloodthistle.',1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15,@GOSSIP,0,0,0,9,0,10570,0,0,0,0,0,'','Show gossip menu option if player has quest To Catch a Thistlehead'),
(15,@GOSSIP,0,0,0,2,0,30616,1,0,1,0,0,'','Show gossip menu option if player doesn''t have item Bundle of Bloodthistle');

DELETE FROM `creature_text` WHERE entry IN (@ZARATH,@ICARIUS,@BORAK);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@BORAK,0,0,'Hide! Hide before they see you! Back up!',15,0,100,0,0,0,'Borak'),
(@BORAK,1,0,'The time to strike is at hand. Terminate Icarius.',15,0,100,0,0,0,'Borak'),
(@BORAK,2,0,'You have it. Do not lose it again!',12,0,100,5,0,0,'Borak'),
(@ZARATH,0,0,'What is it, my lord?',12,0,100,6,0,0,'Zarath'),
(@ZARATH,1,0,'My lord, surely you do not expect me to leave you unattended. Lord Illidan would have my head if anything were to happen to you.',12,0,100,1,0,0,'Zarath'),
(@ZARATH,2,0,'As you wish, my lord.',12,0,100,66,0,0,'Zarath'),
(@ICARIUS,0,0,'Halt!',12,0,100,1,0,0,'Icarius'),
(@ICARIUS,1,0,'Zarath you must return to the Black Temple at once! I... I seem to have misplaced Lord Illidan''s orders. Quickly!',12,0,100,5,0,0,'Icarius'),
(@ICARIUS,2,0,'Zarath, I am perfectly capable of making it up this road to Eclipse Point. If we do not deliver the missive, Lord Illidan will have both of our heads! You are dismissed!',12,0,100,1,0,0,'Icarius'),
(@ICARIUS,3,0,'Ah, sweet, sweet bloodthistle... Probably left behind by one of those filthy addicts at Eclipse Point.',12,0,100,1,0,0,'Icarius'),
(@ICARIUS,4,0,'Their loss is most definitely my gain...',12,0,100,275,0,0,'Icarius'),
(@ICARIUS,5,0,'Envoy Icarius puts the bundle of bloodthistle in his robe.',16,0,100,0,0,0,'Icarius'),
(@ICARIUS,6,0,'Ah, damn it all! Clever trap. Too bad you''ll never live to tell the tale...',12,0,100,1,0,0,'Icarius');

DELETE FROM `creature_template_addon` WHERE entry = @ZARATH;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes2`) VALUES 
(@ZARATH,@BLOOD_MOUNT,0);

UPDATE `gameobject` SET `position_x`=-4057.190, `position_y`=1527.482, `position_z`=93.0938 WHERE `guid`=99970;

UPDATE `creature_template` SET `gossip_menu_id`=8301 WHERE `entry`=@BORAK;
UPDATE `creature_template` SET `faction_A`=1701, `faction_H`=1701, `speed_walk`=1.14286 WHERE `entry` IN (@ZARATH,@ICARIUS);

UPDATE `creature_template` SET AIName='SmartAI' WHERE entry IN (@ZARATH,@ICARIUS,@BORAK);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@GOBJECT;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@ZARATH,@ICARIUS,@BORAK);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@GOBJECT;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ICARIUS*100,@ZARATH*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BORAK,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,17,50,100,0,0,0,0,0,'Borak - On Data Set - Say 0'),
(@BORAK,0,1,0,38,0,100,0,2,2,0,0,1,1,0,0,0,0,0,17,50,100,0,0,0,0,0,'Borak - On Data Set - Say 1'),
(@BORAK,0,2,3,62,0,100,0,@GOSSIP,0,0,0,56,30616,35,0,0,0,0,7,0,0,0,0,0,0,0,'Borak - On gossip select - Add Item to Player'),
(@BORAK,0,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Borak - On gossip select - Close Gossip'),
(@BORAK,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,17,50,100,0,0,0,0,0,'Borak - On gossip select - Say 2'),

(@ZARATH,0,0,1,54,0,100,0,0,0,0,0,53,0,@ZARATH,0,10570,0,0,1,0,0,0,0,0,0,0,'Zarath - Just Summoned - Start Wp'),
(@ZARATH,0,1,2,61,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,@BORAK,500,0,0,0,0,0,'Zarath - On Link - Set Data to Borak'),
(@ZARATH,0,2,0,61,0,100,1,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zarath - On Link - Set react state aggressive'),
(@ZARATH,0,3,0,38,0,100,0,0,1,0,0,66,0,0,0,0,0,0,19,@ICARIUS,10,0,0,0,0,0,'Zarath - On Data Set - Turn to'),
(@ZARATH,0,4,5,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.716,'Zarath - On Data Set - Set Orientation'),
(@ZARATH,0,5,0,61,0,100,0,0,0,0,0,80,@ZARATH*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Zarath - On Link - Timed Script'),
(@ZARATH,0,6,0,40,0,100,0,1,@ZARATH,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zarath - WP Reached - Set Home Pos'),

(@ICARIUS,0,0,1,54,0,100,0,0,0,0,0,53,0,@ICARIUS,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Just Summoned - Start Wp'),
(@ICARIUS,0,1,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Just Summoned - Set react state aggressive'),
(@ICARIUS,0,2,0,40,0,100,0,1,@ICARIUS,0,0,80,@ICARIUS*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - WP reached - Call Action Script'),
(@ICARIUS,0,3,0,4,1,100,1,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - On aggro (phase 1) - Say text 6'),

(@GOBJECT,1,0,0,38,0,100,0,3,3,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bundle of Bloodthistle - On data 3 3 set - Set phase 2'),

(@ZARATH*100,9,0,0,0,0,100,0,1500,1500,0,0,46,100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zarath - Move forward'),

(@ICARIUS*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Say Text 0'),
(@ICARIUS*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,19,@ZARATH,10,0,0,0,0,0,'Zarath - Say Text 0 Zarath'),
(@ICARIUS*100,9,2,0,0,0,100,0,6500,6500,0,0,66,0,0,0,0,0,0,19,@ZARATH,10,0,0,0,0,0,'Icarius - Turn to'),
(@ICARIUS*100,9,3,0,0,0,100,0,500,500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Say Text 1'),
(@ICARIUS*100,9,4,0,0,0,100,0,1000,1000,0,0,45,0,1,0,0,0,0,19,@ZARATH,10,0,0,0,0,0,'Zarath - Set data 0 1'),
(@ICARIUS*100,9,5,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,@ZARATH,10,0,0,0,0,0,'Zarath - Say Text 1 Zarath'),
(@ICARIUS*100,9,6,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Say Text 2'),
(@ICARIUS*100,9,7,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,19,@ZARATH,10,0,0,0,0,0,'Zarath - Say Text 2 Zarath'),
(@ICARIUS*100,9,8,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,@ZARATH,10,0,0,0,0,0,'Zarath - Set Data 1 1'),
(@ICARIUS*100,9,9,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,@GOBJECT,50,0,0,0,0,0,'Icarius - Turn to'),
(@ICARIUS*100,9,10,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Say Text 3'),
(@ICARIUS*100,9,11,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Say Text 4'),
(@ICARIUS*100,9,12,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,20,@GOBJECT,50,0,0,0,0,0,'Icarius - Go to GO PoS'),
(@ICARIUS*100,9,13,0,0,0,100,0,5000,5000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Emote Kneel'),
(@ICARIUS*100,9,14,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Say Text 5'),
(@ICARIUS*100,9,15,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,20,@GOBJECT,5,0,0,0,0,0,'Icarius - Set Data Gameobject'),
(@ICARIUS*100,9,16,0,0,0,100,1,3000,3000,0,0,45,2,2,0,0,0,0,11,@BORAK,100,0,0,0,0,0,'Icarius - Set Data 2 2'),
(@ICARIUS*100,9,17,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icarius - Set event phase 1');

DELETE FROM `event_scripts` WHERE `id`=@EVENT;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT,0,10,@ZARATH,80000,0,-4055.979,1478.097,87.927,1.501698),
(@EVENT,0,10,@ICARIUS,120000,0,-4052.285,1478.886,87.8424,1.604585);

DELETE FROM `waypoints` WHERE `entry` IN (@ZARATH,@ICARIUS);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ZARATH,1,-4058.758,1515.231,91.292,'Zarath'),
(@ICARIUS,1,-4054.427,1515.515,91.511,'Icarius');
