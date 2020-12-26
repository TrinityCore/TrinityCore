-- Quest 27418, Challenge Overlord Mok'Morokk

SET @OMM := 4500; -- Overlord Mok'Morokk

UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE  `ID`=1173;

DELETE FROM `creature_text` WHERE `CreatureID`= @OMM;
INSERT INTO `creature_text` (`CreatureID`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@OMM, 0,0,'Puny $r wanna fight Overlord Mok''Morokk? Me beat you! Me boss here!',12,0,100,0,0,0,1515,0,'Overlord Mok''Morokk - on Quest Accept'),
(@OMM, 1,0,'Me scared! Me run now!',                                              14,0,100,0,0,0,1523,0,'Overlord Mok''Morokk - on Health 0%-25%');

DELETE FROM `waypoints` WHERE `entry` = @OMM;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@OMM, 1, -3138.49, -2864.64, 34.76, 'Overlord Mok''Morokk'),
(@OMM, 2, -3128.08, -2847.37, 34.72, 'Overlord Mok''Morokk'),
(@OMM, 3, -3108.94, -2839.60, 34.28, 'Overlord Mok''Morokk');

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = '' WHERE `entry` = @OMM;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@OMM, @OMM*100, @OMM*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OMM,      0, 0,0,  0,0,100,0, 1000,3000,7000,10000, 11,      6749,   2, 0,0,0,0,  2, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - In Combat Update - cast ''Wide Swipe'''),
(@OMM,      0, 1,2, 19,0,100,1, 1173,   0,   0,    0, 64,         1,   0, 0,0,0,0, 16, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Quest Accept - Store players (No repeat)'),
(@OMM,      0, 2,0, 61,0,100,0,    0,   0,   0,    0, 80,  @OMM*100,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Quest Accept - Run Actionlist 450000'),
(@OMM*100,  9, 0,0,  0,0,100,0, 3000,3000,   0,    0,  1,         0,   0, 0,0,0,0, 12, 1,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Say text 0'),
(@OMM*100,  9, 1,0,  0,0,100,0,    0,   0,   0,    0,  2,        16,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Set faction (Monster)'),
(@OMM*100,  9, 2,0,  0,0,100,0,    0,   0,   0,    0, 83,         2,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Remove npcflag Quest Giver'),
(@OMM*100,  9, 3,0,  0,0,100,0,    0,   0,   0,    0, 19,       768,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Remove Unit Flags immune to NPC & immune to PC'),
(@OMM*100,  9, 4,0,  0,0,100,0,    0,   0,   0,    0, 49,         0,   0, 0,0,0,0, 12, 1,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Attack stored player'),
(@OMM,      0, 3,0,  2,0,100,1,    0,  25,   0,    0, 80,@OMM*100+1,   2, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Health 0%-25% - Run Actionlist 450001 (No repeat)'),
(@OMM,      0, 4,0,  0,0,100,1,    0,   0,   0,    0, 42,         0,   1, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - In Combat - Set invincibility hp level (No repeat)'),
(@OMM*100+1,9, 0,0,  0,0,100,0,    0,   0,   0,    0, 18,       768,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Set Unit Flags immune to NPC & immune to PC'),
(@OMM*100+1,9, 1,0,  0,0,100,0,    0,   0,   0,    0, 28,         0,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Remove all auras'),
(@OMM*100+1,9, 2,0,  0,0,100,0,    0,   0,   0,    0,  2,        29,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Set faction (Orgrimmar)'),
(@OMM*100+1,9, 3,0,  0,0,100,0,    0,   0,   0,    0, 24,         0,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Evade'),
(@OMM*100+1,9, 4,0,  0,0,100,0,    0,   0,   0,    0, 15,      1173,   0, 0,0,0,0, 12, 1,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Credit Quest ''Challenge Overlord Mok''Morokk'''),
(@OMM*100+1,9, 5,0,  0,0,100,0,  500, 500,   0,    0,  1,         1,   0, 0,0,0,0, 12, 1,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Say text 1'),
(@OMM*100+1,9, 6,0,  0,0,100,0,    0,   0,   0,    0, 53,         1,@OMM, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - Actionlist - Start Waypoint'),
(@OMM,      0, 5,0, 58,0,100,0,    0,@OMM,   0,    0, 41,         0,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on WP End - Despawn'),
(@OMM,      0, 6,7, 25,0,100,0,    0,   0,   0,    0, 18,       768,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Reset - Set Unit Flags immune to NPC & immune to PC'),
(@OMM,      0, 7,8, 61,0,100,0,    0,   0,   0,    0, 82,         2,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Reset - Remove all auras'),
(@OMM,      0, 8,0, 61,0,100,0,    0,   0,   0,    0,  2,        29,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Reset - Set faction (Orgrimmar)'),
(@OMM,      0, 9,0, 11,0,100,0,    0,   0,   0,    0, 42,         1,   0, 0,0,0,0,  1, 0,0,0,0,0,0,0,'Overlord Mok''Morokk - on Spawn - Set Invincibility at 1 HP');
--
