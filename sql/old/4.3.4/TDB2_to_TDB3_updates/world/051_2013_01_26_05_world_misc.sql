-- Issue 5882: Dire Maul Arena Rare Bosses
-- Spawnlocations are from YTDB need to be checked!
/*
SET @GUID := 45758; -- set the guid for spawning 4.x verified
SET @POOL := 372; -- set the poolid for the spawn 4.x verified
DELETE FROM `creature` WHERE `id` IN (11447,11497,11498);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID  ,11447,1,1,1,0,0,-3799.62,1063.83,132.806,1.20424,21600,0,0,60000,    0,0,0,0,0),
(@GUID+1,11497,1,1,1,0,0,-3731.22,1061.32,132.345,1.78150,21600,0,0,73000,24340,0,0,0,0),
(@GUID+2,11498,1,1,1,0,0,-3690.96,1077.14,131.969,2.65172,21600,0,0,57000,    0,0,0,0,0);
DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOL,1,'Max 1 Rare in Dire Maul Arena');
DELETE FROM `pool_creature` WHERE `pool_entry`=@POOL;
INSERT INTO `pool_creature` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@GUID  ,@POOL,0, 'Rare Spawn Dire Maul Arena'),
(@GUID+1,@POOL,0, 'Rare Spawn Dire Maul Arena'),
(@GUID+2,@POOL,0, 'Rare Spawn Dire Maul Arena');
*/
-- Issue 5925: Missing Sand Shark from Durotar
-- Thx Mogale for sniffing
DELETE FROM `creature` WHERE `id`=5435;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(43494,5435,1,1,1,0,0,-1144.251,-4336.333,-8.457234,4.602825,900,4,0,741,0,1,0,0,0);  -- 4.x verified
-- Issue 8498: Fix 2 centaurs stuck in the ground (by Baric)
-- UPDATE creature SET position_z=93.67 WHERE guid IN (14007, 20588); 4.x verified
-- Issue 568: No Mercy for the Captured
-- Gossip Menu Options
DELETE FROM `gossip_menu_option` WHERE  `menu_id` IN (9510,9509,9508,9507);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
-- Chancellor
(9510,0,0, 'No, chancellor.. I wouldn''t say that I''m here to ''rescue'' you, per se.',1,1,0,0,0,0,NULL),
(9510,1,0, 'Where is Senior Scrivener Barriga being held?'         ,1,1,50424,0,0,0,NULL),
(9510,2,0, 'Did you see where they took Sanitation Engineer Burke?',1,1,50426,0,0,0,NULL),
(9510,3,0, 'Any idea where they''re keeping Deathguard Schneider?' ,1,1,50425,0,0,0,NULL),
-- Engineer
(9509,0,0, 'Affraid not. Your days as a sanitation engineer are coming to an end',  1,1,    0,0,0,0,NULL),
(9509,1,0, 'Can you tell me where they have Chancellor Amai caged?',1,1,50423,0,0,0,NULL),
(9509,2,0, 'Where is Senior Scrivener Barriga being held?'         ,1,1,50424,0,0,0,NULL),
(9509,3,0, 'Any idea where they''re keeping Deathguard Schneider?' ,1,1,50425,0,0,0,NULL),
-- Scrivener
(9508,0,0, 'Not today, senior scrivener!'                          ,1,1,    0,0,0,0,NULL),
(9508,1,0, 'Can you tell me where they have Chancellor Amai caged?',1,1,50423,0,0,0,NULL),
(9508,2,0, 'Did you see where they took Sanitation Engineer Burke?',1,1,50426,0,0,0,NULL),
(9508,3,0, 'Any idea where they''re keeping Deathguard Schneider?' ,1,1,50425,0,0,0,NULL),
-- Schneider
(9507,0,0, 'I''m affraid not. Schneider. Your time has come!'       ,1,1,    0,0,0,0,NULL),
(9507,1,0, 'Can you tell me where they have Chancellor Amai caged?',1,1,50423,0,0,0,NULL),
(9507,2,0, 'Where is Senior Scrivener Barriga being held?'         ,1,1,50424,0,0,0,NULL),
(9507,3,0, 'Did you see where they took Sanitation Engineer Burke?',1,1,50426,0,0,0,NULL);
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry` IN (50423,50424,50425,50426);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(50423,12833), -- I think I saw them take him over by the north side of the abbey, near the archery targets.
(50424,12827), -- I think they put him in a cage over near the lumbermill.
(50425,12832), -- I think they have her down near the gallows.
(50426,12830); -- I think he's on the south side of the abbey.
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27376,27378,27379,27381) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2737600,2737800,2737900,2738100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Deathguard Schneider
(27376  ,0,0,0,62,0,100,0,9507,0,0,0,80,2737600,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - On Gossip Option Select - Start Script"),
(27376  ,0,1,0,10,0,100,0,0,10,180000,300000,1,1,0,0,0,0,0,17,0,10,0,0.0,0.0,0.0,0.0,"Deathguard Schneider - On LoS with Player Near - Say Line 1"),
(2737600,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Close Gossip"),
(2737600,9,1,0,0,0,100,0,200,200,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Say line 0"),
(2737600,9,2,0,0,0,100,0,5000,5000,0,0,2,14,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Set facton 14 (Hostile)"),
(2737600,9,3,0,0,0,100,0,2500,2500,0,0,46,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Move"),
-- Senior Scrivener Barriga
(27378  ,0,0,0,62,0,100,0,9508,0,0,0,80,2737800,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Senior Scrivener Barriga - On Gossip Option Select - Start Script"),
(27378  ,0,1,0,10,0,100,0,0,10,180000,300000,1,1,0,0,0,0,0,17,0,10,0,0.0,0.0,0.0,0.0,"Senior Scrivener Barriga - On LoS with Player Near - Say Line 1"),
(2737800,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Close Gossip"),
(2737800,9,1,0,0,0,100,0,200,200,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Senior Scrivener Barriga - Say line 0"),
(2737800,9,2,0,0,0,100,0,5000,5000,0,0,2,14,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Senior Scrivener Barriga - Set facton 14"),
(2737800,9,3,0,0,0,100,0,2500,2500,0,0,46,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Senior Scrivener Barriga - Move"),
-- Engineer Burke
(27379  ,0,0,0,62,0,100,0,9509,0,0,0,80,2737900,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Engineer Burke - On Gossip Option Select - Start Script"),
(27379  ,0,1,0,10,0,100,0,0,10,180000,300000,1,1,0,0,0,0,0,17,0,10,0,0.0,0.0,0.0,0.0,"Engineer Burke - On LoS with Player Near - Say Line 1"),
(2737900,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Close Gossip"),
(2737900,9,1,0,0,0,100,0,200,200,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Engineer Burke - Script - Say line 0"),
(2737900,9,2,0,0,0,100,0,5000,5000,0,0,2,14,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Engineer Burke - Script - Set facton 14"),
(2737900,9,3,0,0,0,100,0,2500,2500,0,0,46,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Engineer Burke - Script - Move"),
-- Chancellor Amai
(27381  ,0,0,0,62,0,100,0,9510,0,0,0,80,2738100,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Chancellor Amai - On Gossip Option Select - Start Script"),
(27381  ,0,1,0,10,0,100,0,0,10,180000,300000,1,1,0,0,0,0,0,17,0,10,0,0.0,0.0,0.0,0.0,"Chancellor Amai - On LoS with Player Near - Say Line 1"),
(2738100,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0, "Deathguard Schneider - Script - Close Gossip"),
(2738100,9,1,0,0,0,100,0,200,200,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Chancellor Amai - Script - Say line 0"),
(2738100,9,2,0,0,0,100,0,5000,5000,0,0,2,14,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Chancellor Amai - Script - Set facton 14"),
(2738100,9,3,0,0,0,100,0,2500,2500,0,0,46,1,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Chancellor Amai - Script - Move");
-- Creature Texts
DELETE FROM `creature_text` WHERE `entry` IN (27376,27378,27379,27381);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(27376,0,0, 'What do you mean my time has come? I''ll kill you where you stand!',12,0,100,0,0,0, 'Deathguard Schneider before going hostile'),
(27376,1,0, 'Hey, over here!',12,0,100,0,0,0, 'Deathguard Schneider upon LoS'),
(27378,0,0, 'You can''t possibly mean to.... I''ll write you up for this, $C!',12,0,100,0,0,0, 'Senior Scrivener Barriga before going hostile'),
(27378,1,0, 'If you''d be so kind, please let me out of here!',12,0,100,0,0,0, 'Senior Scrivener Barriga upon LoS'),
(27379,0,0, 'No! I beg you! Please don''t kill me!',12,0,100,0,0,0, 'Engineer Burke before going hostile'),
(27379,1,0, 'Can Someone let me out of here? I need to get back to Venomspite and finish my shift.',12,0,100,0,0,0, 'Engineer Burke upon LoS'),
(27381,0,0, 'What is the meaning of this? Stop! I''ll double whatever they''re paying you!',12,0,100,0,0,0, 'Chancellor Amai before going hostile'),
(27381,1,0, 'I just arrived in Venomspite. How could i have possibly wronged you?',12,0,100,0,0,0, 'Chancellor Amai upon Los');
-- Conditions
DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9507,9508,9509,9510);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9507,0,0,9,12245,0,0,0, '', 'Deathguard Schneider: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9507,1,0,9,12245,0,0,0, '', 'Deathguard Schneider: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9507,2,0,9,12245,0,0,0, '', 'Deathguard Schneider: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9507,3,0,9,12245,0,0,0, '', 'Deathguard Schneider: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9508,0,0,9,12245,0,0,0, '', 'Senior Scivener Barriga: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9508,1,0,9,12245,0,0,0, '', 'Senior Scivener Barriga: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9508,2,0,9,12245,0,0,0, '', 'Senior Scivener Barriga: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9508,3,0,9,12245,0,0,0, '', 'Senior Scivener Barriga: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9509,0,0,9,12245,0,0,0, '', 'Engineer Burke: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9509,1,0,9,12245,0,0,0, '', 'Engineer Burke: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9509,2,0,9,12245,0,0,0, '', 'Engineer Burke: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9509,3,0,9,12245,0,0,0, '', 'Engineer Burke: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9510,0,0,9,12245,0,0,0, '', 'Chancellor Amai: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9510,1,0,9,12245,0,0,0, '', 'Chancellor Amai: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9510,2,0,9,12245,0,0,0, '', 'Chancellor Amai: Show Gossip only if on quest "No Mercy for the Captured" '),
(15,9510,3,0,9,12245,0,0,0, '', 'Chancellor Amai: Show Gossip only if on quest "No Mercy for the Captured" ');
