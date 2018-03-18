-- [Q] Totem of Vark -- http://wotlk.openwow.com/quest=9542
-- this spell must be casted later in the spawnscript
UPDATE `quest_template_addon` SET `SourceSpellID`=0 WHERE  `ID`=9542;

-- Totem of Yor SAI
SET @ENTRY := 17363;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,9542,0,0,0,12,17393,1,360000,0,0,0,8,0,0,0,-4637.05,-13067.3,-13.5973,0.26767,"Totem of Yor - On Quest 'Totem of Vark' Taken - Summon Creature 'Stillpine Ancestor Yor'");

-- spawncondition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=17363;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,17363,0,0,29,0,17393,50,0,1,0,0,"","Totem of Yor - Do not summon Stillpine Ancestor Yor if creature is in 50 yards range");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (30448, -30448, 30447);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(30448, 32213, 2, 'Shadow of the Forest - Shadow of the Forest SI DND'),
(30447, 32213, 2, 'Shadow of the Forest - Shadow of the Forest SI DND'),
(-30448, -32213, 0, 'Shadow of the Forest - Shadow of the Forest SI DND');

-- Stillpine Ancestor Yor SAI
SET @ENTRY := 17393;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Respawn - Run Script (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,21,30,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Respawn - Store Targetlist (No Repeat)"),
(@ENTRY,0,2,0,40,0,100,0,63,17393,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Waypoint 63 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1739300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,3,0,17002,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Morph To Model 17002"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Elemental Spawn-in'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Set Orientation Stored Player"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4646.63,-13015.4,-1.38673,1.6751,"Stillpine Ancestor Yor - On Script - Move To Position"),
(@ENTRY,9,5,0,0,0,100,0,13000,13000,0,0,11,30446,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Yor Transform Furbolg DND'"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4679.14,-12985,0.5803,1.93085,"Stillpine Ancestor Yor - On Script - Move To Position"),
(@ENTRY,9,7,0,0,0,100,0,13000,13000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Set Orientation Stored Player"),
(@ENTRY,9,8,0,0,0,100,0,3000,3000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 1"),
(@ENTRY,9,9,0,0,0,100,0,3000,3000,0,0,11,30448,0,0,0,0,0,12,1,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest'"),
(@ENTRY,9,10,0,0,0,100,0,1000,1000,0,0,11,30447,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Invoker Cast 'Shadow of the Forest'"),
(@ENTRY,9,11,0,0,0,100,0,2000,2000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 2"),
(@ENTRY,9,12,0,0,0,100,0,5000,5000,0,0,53,1,17393,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 1739301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,3,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 3"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Elemental Spawn-in'"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID`=17393;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(17393, 0, 0, '[Furbolg] Come, $n. Let us leave the water together, purified.', 12, 0, 100, 0, 0, 0, 13901, 'Stillpine Ancestor Yor'),
(17393, 1, 0, '[Furbolg] We go now, together. We will seek Vark.', 12, 0, 100, 0, 0, 0, 13903, 'Stillpine Ancestor Yor'),
(17393, 2, 0, '[Furbolg] Follow me to Vark.', 12, 0, 100, 0, 0, 0, 13907, 'Stillpine Ancestor Yor'),
(17393, 3, 0, '[Furbolg] Hurry, $n. Vark awaits you.', 12, 0, 100, 0, 0, 0, 13927, 'Stillpine Ancestor Yor');

DELETE FROM `waypoints` WHERE `entry`=17393;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(17393, 1, -4679.14,-12985,0.5803,       'Stillpine Ancestor Yor'),
(17393, 2, -4680.61,-12963.3,2.66436,    'Stillpine Ancestor Yor'),
(17393, 3, -4681.2,-12949.7,5.54,        'Stillpine Ancestor Yor'),
(17393, 4, -4682.73,-12929.5,3.47035,    'Stillpine Ancestor Yor'),
(17393, 5, -4667.73,-12909.8,1.50962,    'Stillpine Ancestor Yor'),
(17393, 6, -4647.96,-12887.9,2.97161,    'Stillpine Ancestor Yor'),
(17393, 7, -4639.09,-12877.2,4.9471,     'Stillpine Ancestor Yor'),
(17393, 8, -4630.71,-12855.1,4.28118,    'Stillpine Ancestor Yor'),
(17393, 9, -4620.17,-12829.9,6.06746,    'Stillpine Ancestor Yor'),
(17393, 10, -4612,-12814,7.12509,        'Stillpine Ancestor Yor'),
(17393, 11, -4601.96,-12795.7,3.27105,   'Stillpine Ancestor Yor'),
(17393, 12, -4588.53,-12774.2,7.44323,   'Stillpine Ancestor Yor'),
(17393, 13, -4575.77,-12760.8,6.10979,   'Stillpine Ancestor Yor'),
(17393, 14, -4563.73,-12744.2,9.99685,   'Stillpine Ancestor Yor'),
(17393, 15, -4554.96,-12729,12.2105,     'Stillpine Ancestor Yor'),
(17393, 16, -4547.41,-12712.1,9.81412,   'Stillpine Ancestor Yor'),
(17393, 17, -4538.2,-12689.2,12.5838,    'Stillpine Ancestor Yor'),
(17393, 18, -4533.22,-12668.1,16.8651,   'Stillpine Ancestor Yor'),
(17393, 19, -4532.96,-12656.8,15.2664,   'Stillpine Ancestor Yor'),
(17393, 20, -4532.78,-12637.9,16.5789,   'Stillpine Ancestor Yor'),
(17393, 21, -4533.02,-12619.1,12.0263,   'Stillpine Ancestor Yor'),
(17393, 22, -4532.77,-12592.5,14.642,    'Stillpine Ancestor Yor'),
(17393, 23, -4535.16,-12572.5,11.9603,   'Stillpine Ancestor Yor'),
(17393, 24, -4521.38,-12547.2,8.20642,   'Stillpine Ancestor Yor'),
(17393, 25, -4506.74,-12520.5,2.71515,   'Stillpine Ancestor Yor'),
(17393, 26, -4492.57,-12495.4,4.36968,   'Stillpine Ancestor Yor'),
(17393, 27, -4476.92,-12469.2,2.26036,   'Stillpine Ancestor Yor'),
(17393, 28, -4462.38,-12438.4,2.68436,   'Stillpine Ancestor Yor'),
(17393, 29, -4430.42,-12442,2.38524,     'Stillpine Ancestor Yor'),
(17393, 30, -4419.91,-12429.3,3.2091,    'Stillpine Ancestor Yor'),
(17393, 31, -4408.61,-12400.1,5.02559,   'Stillpine Ancestor Yor'),
(17393, 32, -4414.42,-12370.4,5.99229,   'Stillpine Ancestor Yor'),
(17393, 33, -4423.44,-12345,8.29463,     'Stillpine Ancestor Yor'),
(17393, 34, -4435.58,-12315.7,10.3162,   'Stillpine Ancestor Yor'),
(17393, 35, -4457.19,-12304.2,12.3064,   'Stillpine Ancestor Yor'),
(17393, 36, -4475.24,-12294,13.9122,     'Stillpine Ancestor Yor'),
(17393, 37, -4490.89,-12279.7,15.2792,   'Stillpine Ancestor Yor'),
(17393, 38, -4503.42,-12249.6,16.3871,   'Stillpine Ancestor Yor'),
(17393, 39, -4510.15,-12229.8,17.1362,   'Stillpine Ancestor Yor'),
(17393, 40, -4513.27,-12209.5,16.9777,   'Stillpine Ancestor Yor'),
(17393, 41, -4513.64,-12189.1,16.9593,   'Stillpine Ancestor Yor'),
(17393, 42, -4502.99,-12158,16.1291,     'Stillpine Ancestor Yor'),
(17393, 43, -4508.94,-12122.7,16.9898,   'Stillpine Ancestor Yor'),
(17393, 44, -4505.31,-12095.6,18.8873,   'Stillpine Ancestor Yor'),
(17393, 45, -4500.36,-12071.2,21.4168,   'Stillpine Ancestor Yor'),
(17393, 46, -4516.81,-12050.5,24.2492,   'Stillpine Ancestor Yor'),
(17393, 47, -4528.22,-12037.5,26.0347,   'Stillpine Ancestor Yor'),
(17393, 48, -4531.9,-12008.6,28.4037,    'Stillpine Ancestor Yor'),
(17393, 49, -4538.61,-11984.4,29.7635,   'Stillpine Ancestor Yor'),
(17393, 50, -4543.79,-11963.5,29.1954,   'Stillpine Ancestor Yor'),
(17393, 51, -4537.48,-11934.2,27.0094,   'Stillpine Ancestor Yor'),
(17393, 52, -4533.18,-11906.3,22.686,    'Stillpine Ancestor Yor'),
(17393, 53, -4504.71,-11879,17.5661,     'Stillpine Ancestor Yor'),
(17393, 54, -4500.36,-11845.7,15.0063,   'Stillpine Ancestor Yor'),
(17393, 55, -4510.63,-11816.8,13.8306,   'Stillpine Ancestor Yor'),
(17393, 56, -4531.7,-11786.6,15.5384,    'Stillpine Ancestor Yor'),
(17393, 57, -4555.94,-11756.9,17.6289,   'Stillpine Ancestor Yor'),
(17393, 58, -4546.7,-11735.9,19.533,     'Stillpine Ancestor Yor'),
(17393, 59, -4535.96,-11712.4,18.2368,   'Stillpine Ancestor Yor'),
(17393, 60, -4519.88,-11702.4,17.8815,   'Stillpine Ancestor Yor'),
(17393, 61, -4507,-11694.5,13.2184,      'Stillpine Ancestor Yor'),
(17393, 62, -4490.14,-11673,10.8723,     'Stillpine Ancestor Yor'),
(17393, 63, -4486.34,-11658,10.6353,     'Stillpine Ancestor Yor');
