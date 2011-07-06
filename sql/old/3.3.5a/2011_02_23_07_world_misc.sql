-- SAI for Neltharaku
SET @ENTRY := 21657;
UPDATE `creature_template` SET `speed_run`=2.5,`ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,8396,0,0,0,26,10814,0,1,0,0,0,7,0,0,0,0,0,0,0,'Neltharaku - On Gossip option - Quest credit'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Neltharaku - On Gossip option - Close gossip');
-- Waypoints for Neltharaku from sniff
SET @NPC := 75654;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4147.188,`position_y`=852.9213,`position_z`=112.449 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`) VALUES (@ENTRY,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4149.083,816.8467,102.0771,0,0,0,100,0),
(@PATH,2,-4148.741,817.7864,102.0771,0,0,0,100,0),
(@PATH,3,-4150.894,819.7193,112.4489,0,0,0,100,0),
(@PATH,4,-4147.188,852.9213,112.449,0,0,0,100,0),
(@PATH,5,-4126.215,897.6987,112.449,0,0,0,100,0),
(@PATH,6,-4113.534,926.0124,112.449,0,0,0,100,0),
(@PATH,7,-4098.13,963.6712,112.449,0,0,0,100,0),
(@PATH,8,-4063.067,1046.515,112.449,0,0,0,100,0),
(@PATH,9,-4008.534,1081.363,112.449,0,0,0,100,0),
(@PATH,10,-3926.171,1057.316,112.449,0,0,0,100,0),
(@PATH,11,-3914.31,958.3683,114.7823,0,0,0,100,0),
(@PATH,12,-3930.769,894.2169,114.2545,0,0,0,100,0),
(@PATH,13,-3991.642,763.9112,112.449,0,0,0,100,0),
(@PATH,14,-4060.605,579.9987,112.449,0,0,0,100,0),
(@PATH,15,-4085.638,468.8222,173.4489,0,0,0,100,0),
(@PATH,16,-4097.893,416.0321,177.8378,0,0,0,100,0),
(@PATH,17,-4110.39,374.4871,174.2545,0,0,0,100,0),
(@PATH,18,-4135.225,331.1968,174.7545,0,0,0,100,0),
(@PATH,19,-4203.078,269.2113,172.4767,0,0,0,100,0),
(@PATH,20,-4239.532,280.7727,169.0878,0,0,0,100,0),
(@PATH,21,-4278.137,304.6405,169.1989,0,0,0,100,0),
(@PATH,22,-4295.682,340.7838,173.9212,0,0,0,100,0),
(@PATH,23,-4297.044,383.0331,169.0878,0,0,0,100,0),
(@PATH,24,-4267.532,404.9037,169.0878,0,0,0,100,0),
(@PATH,25,-4225.749,416.8825,169.0878,0,0,0,100,0),
(@PATH,26,-4193.994,418.2155,169.0878,0,0,0,100,0),
(@PATH,27,-4176.15,444.5788,158.2545,0,0,0,100,0),
(@PATH,28,-4163.389,480.9925,149.6712,0,0,0,100,0),
(@PATH,29,-4157.379,548.4786,145.2823,0,0,0,100,0),
(@PATH,30,-4178.163,628.6951,101.0601,0,0,0,100,0),
(@PATH,31,-4182.795,656.5566,97.31005,0,0,0,100,0),
(@PATH,32,-4184.389,678.5916,98.50452,0,0,0,100,0),
(@PATH,33,-4182.358,726.181,102.5323,0,0,0,100,0),
(@PATH,34,-4175.015,753.1885,103.2545,0,0,0,100,0),
(@PATH,35,-4160.292,781.7564,107.8656,0,0,0,100,0),
(@PATH,36,-4150.894,819.7193,112.4489,0,0,0,100,0),
(@PATH,37,-4147.188,852.9213,112.449,0,0,0,100,0);

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8394 AND `text_id`=10614;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8394,10614);
DELETE FROM `gossip_menu` WHERE `entry`=8395 AND `text_id`=10615;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8395,10615);
DELETE FROM `gossip_menu` WHERE `entry`=8396 AND `text_id`=10616;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8396,10616);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=19352;
UPDATE `creature_template` SET `gossip_menu_id`=9563 WHERE `entry`=27575;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `id`=0 AND `menu_id` IN (8013,8397,8394,8395,8396);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8013,0,0, 'I see.',1,1,8014,0,0,0,0, ''),
(8397,0,0, 'I am listening, dragon.',1,1,8394,0,0,0,0, ''),
(8394,0,0, 'But you are dragons! How could orcs do this to you?',1,1,8395,0,0,0,0, ''),
(8395,0,0, 'Your mate?',1,1,8396,0,0,0,0, ''),
(8396,0,0, 'I have battled many beasts, dragon. I will help you.',1,1,0,0,0,0,0, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8397;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8397,0,0,9,10814,0,0,0,'','Show gossip option 0 if player has quest 10814');
