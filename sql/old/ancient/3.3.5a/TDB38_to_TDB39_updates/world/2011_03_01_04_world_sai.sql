-- Apothecary Enith Fixup for quest 9164 "Captives at Deatholme"
-- add gossip_id to npc and fix stand state
UPDATE `creature_template` SET `gossip_menu_id`=7182,`unit_flags`=33024 WHERE `entry`=16208;
DELETE FROM `creature_template_addon` WHERE `entry`=16208;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES (16208,7);
-- add gossip menu items
DELETE FROM `gossip_menu` WHERE `entry` IN (7182,7179);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7182,8459),
(7179,8460);
-- add gossip menu options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7182,7179);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7182,0,0,'<Administer the restorative draught.>',1,1,7179,0,0,0,0,''),
(7179,0,0,'A bit ungrateful, aren''t we? The way out is clear, flee quickly!',1,1,0,0,0,0,0,'');
-- add condition for gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7182;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7182,0,0,2,22628,1,0,0,'','Show gossip option 0 if player has Renzithen''s Restorative Draught');
-- Apothecary Enith SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16208;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16208,1620800);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16208,0,0,0,62,0,100,0,7179,0,0,0,80,1620800,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On gossip option select run script'),
(16208,0,1,0,40,0,100,0,5,16208,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On reach waypoint 5 despawn'),
(1620800,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Turn off Gossip flag'),
(1620800,9,1,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1 stand'),
(1620800,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'turn to envoker'),
(1620800,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 0'),
(1620800,9,4,0,0,0,100,0,2000,2000,0,0,33,16208,0,0,0,0,0,7,0,0,0,0,0,0,0, 'give quest credit'),
(1620800,9,5,0,0,0,100,0,1000,1000,0,0,53,1,16208,0,0,0,0,1,0,0,0,0,0,0,0, 'start waypoint movement');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=16208;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16208,0,0, 'Thanks, I should''ve never left Silverpine Forest.',0,0,100,6,0,0, 'Apothecary Enith');
-- Apothecary Enith Path
DELETE FROM `waypoints` WHERE `entry`=16208;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(16208,1,6647.83,-6344.92,9.13345,'Apothecary Enith point 1'),
(16208,2,6657.92,-6345.96,15.3468,'Apothecary Enith point 2'),
(16208,3,6661.58,-6342.65,15.4309,'Apothecary Enith point 3'),
(16208,4,6662.35,-6334.64,20.8803,'Apothecary Enith point 4'),
(16208,5,6662.63,-6331.85,20.8924,'Apothecary Enith point 5');

-- Ranger Vedoran <Farstriders> Fixup for quest 9164 "Captives at Deatholme"
-- add gossip_id to npc and fix stand state
UPDATE `creature_template` SET `gossip_menu_id`=7177 WHERE `entry`=16209;
-- add gossip menu items
DELETE FROM `gossip_menu` WHERE `entry` IN (7177,7176);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7177,8457),
(7176,8456);
-- add gossip menu options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7177,7176);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7177,0,0,'<Administer the restorative draught.>',1,1,7176,0,0,0,0,''),
(7176,0,0,'You''re free to go now. The way out is safe.',1,1,0,0,0,0,0,'');
-- add condition for gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7177;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7177,0,0,2,22628,1,0,0,'','Show gossip option 0 if player has Renzithen''s Restorative Draught');
-- Ranger Vedoran SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16209;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16209,1620900);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16209,0,0,0,62,0,100,0,7176,0,0,0,80,1620900,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On gossip option select run script'),
(16209,0,1,0,40,0,100,0,7,16209,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On reach waypoint 7 despawn'),
(1620900,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Turn off Gossip flag'),
(1620900,9,1,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1 stand'),
(1620900,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'turn to envoker'),
(1620900,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 0'),
(1620900,9,4,0,0,0,100,0,2000,2000,0,0,33,16209,0,0,0,0,0,7,0,0,0,0,0,0,0, 'give quest credit'),
(1620900,9,5,0,0,0,100,0,1000,1000,0,0,53,1,16209,0,0,0,0,1,0,0,0,0,0,0,0, 'start waypoint movement');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=16209;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16209,0,0, 'You have my thanks!',0,0,100,0,0,0, 'Ranger Vedoran');
-- Ranger Vedoran Path
DELETE FROM `waypoints` WHERE `entry`=16209;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(16209,1,6290.21,-6366.1,78.0195,'Ranger Vedoran point 1'),
(16209,2,6301.65,-6364.06,78.0238,'Ranger Vedoran point 2'),
(16209,3,6305.82,-6360.2,78.0782,'Ranger Vedoran point 3'),
(16209,4,6310.5,-6356.76,80.6154,'Ranger Vedoran point 4'),
(16209,5,6314.06,-6360.67,82.6096,'Ranger Vedoran point 5'),
(16209,6,6317.35,-6365.34,82.7124,'Ranger Vedoran point 6'),
(16209,7,6326.85,-6366.82,82.7090,'Ranger Vedoran point 7');

-- Apprentice Varnis Fixup for quest 9164 "Captives at Deatholme"
-- add gossip_id to npc and fix stand state
UPDATE `creature_template` SET `gossip_menu_id`=7185 WHERE `entry`=16206;
-- add gossip menu items
DELETE FROM `gossip_menu` WHERE `entry` IN (7185,7186);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7185,8461),
(7186,8463);
-- add gossip menu options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7185,7186);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7185,0,0,'<Administer the restorative draught.>',1,1,7186,0,0,0,0,''),
(7186,0,0,'You''re free to go now. The way out is safe.',1,1,0,0,0,0,0,'');
-- add condition for gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7185;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7185,0,0,2,22628,1,0,0,'','Show gossip option 0 if player has Renzithen''s Restorative Draught');
-- Apprentice Varnis SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16206;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16206,1620600);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16206,0,0,0,62,0,100,0,7186,0,0,0,80,1620600,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On gossip option select run script'),
(16206,0,1,0,40,0,100,0,7,16206,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On reach waypoint 7 despawn'),
(1620600,9,0,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Turn off Gossip flag'),
(1620600,9,1,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1 stand'),
(1620600,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'turn to envoker'),
(1620600,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 0'),
(1620600,9,4,0,0,0,100,0,2000,2000,0,0,33,16206,0,0,0,0,0,7,0,0,0,0,0,0,0, 'give quest credit'),
(1620600,9,5,0,0,0,100,0,1000,1000,0,0,53,1,16206,0,0,0,0,1,0,0,0,0,0,0,0, 'start waypoint movement');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=16206;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16206,0,0, 'Thank you. I thought I was going to die.',0,0,100,0,0,0, 'Apprentice Varnis');
-- Apprentice Varnis Path
DELETE FROM `waypoints` WHERE `entry`=16206;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(16206,1,6436.87,-6633.02,107.432,'Apprentice Varnis point 1'),
(16206,2,6435.63,-6620.86,107.436,'Apprentice Varnis point 2'),
(16206,3,6429.88,-6618.29,108.128,'Apprentice Varnis point 3'),
(16206,4,6426.7,-6614.82,110.159,'Apprentice Varnis point 4'),
(16206,5,6428.75,-6611.21,111.905,'Apprentice Varnis point 5'),
(16206,6,6432.83,-6606.89,112.126,'Apprentice Varnis point 6'),
(16206,7,6431.51,-6597.97,112.113,'Apprentice Varnis point 7');

-- Gossip update Ghostlands
UPDATE `creature_template` SET `gossip_menu_id`=7242, `npcflag`=`npcflag`|1 WHERE `entry`=16204; -- Magister Idonis
UPDATE `creature_template` SET `gossip_menu_id`=7397, `npcflag`=`npcflag`|1 WHERE `entry`=16239; -- Magister Kaendris
UPDATE `creature_template` SET `gossip_menu_id`=7194, `npcflag`=`npcflag`|1 WHERE `entry`=16291; -- Magister Quallestis
UPDATE `creature_template` SET `gossip_menu_id`=7190, `npcflag`=`npcflag`|1 WHERE `entry`=16240; -- Arcanist Janeda
UPDATE `creature_template` SET `gossip_menu_id`=7187 WHERE `entry`=16198; -- Apothecary Renzithen
DELETE FROM `gossip_menu` WHERE `entry`=7242 AND `text_id`=8548;
DELETE FROM `gossip_menu` WHERE `entry`=7397 AND `text_id`=8860;
DELETE FROM `gossip_menu` WHERE `entry`=7194 AND `text_id`=8474;
DELETE FROM `gossip_menu` WHERE `entry`=7190 AND `text_id`=8470;
DELETE FROM `gossip_menu` WHERE `entry`=7187 AND `text_id`=8464;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7242,8548),(7397,8860),(7194,8474),(7190,8470),(7187,8464);
-- Gossip menu option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7187;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7187,0,0,'I seek a sample of your restorative draught, apothecary.',1,1,0,0,0,0,0,'');
-- Gossip menu option condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7187;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7187,0,0,9,9164,0,0,0,'','Show gossip option 0 if player has quest 9164');
-- Smart AI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16198;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=16198;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16198,0,0,1,62,0,100,0,7187,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'On gossip option select close gossip'),
(16198,0,1,0,61,0,100,0,0,0,0,0,11,28149,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Cast Create Restorative Draught on player ');
