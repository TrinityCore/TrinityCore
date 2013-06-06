-- Remove from quest_end_scripts
DELETE FROM `quest_end_scripts` WHERE `id` IN (7642,5158,3922,1191,1103,997,943,931,930,902,492,489,407,349,308,63);

-- Convert quest_end_script "7642" to SAI
-- Indexes:
SET @Grimand_Elmore := 1416;
SET @SCRIPT := @Grimand_Elmore * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Grimand_Elmore;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Grimand_Elmore AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Grimand_Elmore,0,0,0,20,0,100,0,7642,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - On quest 7642 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - Action 3 - Say line 0'),
(@SCRIPT,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8393.09,687.41,95.27,3.72, 'Grimand Elmore - Action 1 - Move to pos'),
(@SCRIPT,9,2,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8400.51,681.85,95.96,5, 'Grimand Elmore - Action 6 - Move to pos'),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8388.72,646.85,94.82,3.92, 'Grimand Elmore - Action 2 - Move to pos'),
(@SCRIPT,9,4,0,0,0,100,0,9000,9000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8422.25,618.12,95.46,3.2, 'Grimand Elmore - Action 10 - Move to pos'),
(@SCRIPT,9,5,0,0,0,100,0,13000,13000,0,0,5,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - Action 4 - Play emote'),
(@SCRIPT,9,6,0,0,0,100,0,6000,6000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - Action 5 - Play emote'),
(@SCRIPT,9,7,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-8421.99,617.93,95.45,5.34, 'Grimand Elmore - Action 7 - Move to pos'),
(@SCRIPT,9,8,0,0,0,100,0,2000,2000,0,0,5,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - Action 8 - Play emote'),
(@SCRIPT,9,9,0,0,0,100,0,6000,6000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - Action 9 - Play emote'),
(@SCRIPT,9,10,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grimand Elmore - Action 13 - Say line 1'),
(@SCRIPT,9,11,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8388.72,646.85,94.82,3.92, 'Grimand Elmore - Action 11 - Move to pos'),
(@SCRIPT,9,12,0,0,0,100,0,9000,9000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8400.51,681.85,95.96,5, 'Grimand Elmore - Action 12 - Move to pos'),
(@SCRIPT,9,13,0,0,0,100,0,12000,12000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8393.09,687.41,95.27,3.72, 'Grimand Elmore - Action 14 - Move to pos'),
(@SCRIPT,9,14,0,0,0,100,0,15000,15000,0,0,69,0,0,0,0,0,0,8,0,0,0,-8387,685.2,95.35,2.28, 'Grimand Elmore - Action 0 - Move to pos');
-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000063,2000000064);
DELETE FROM `creature_text` WHERE `entry`=@Grimand_Elmore;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Grimand_Elmore,0,0, 'Follow me, good $C. I''ll have your barding done faster than I could down a Dwarven stout. Mmmm... stout.',12,0,100,1,0,0, 'Grimand Elmore'),
(@Grimand_Elmore,1,0, 'Well, that should do it. Come now, back to the shop to finish our business!',12,0,100,1,0,0, 'Grimand Elmore');

-- Convert quest_end_script "5158" to SAI
-- Indexes:
SET @Islen_Waterseer := 5901;
SET @SCRIPT := @Islen_Waterseer * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Islen_Waterseer;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Islen_Waterseer AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Islen_Waterseer,0,0,0,20,0,100,0,5158,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Islen Waterseer - On quest 5158 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Islen Waterseer - Action 0 - Set unit flags'),
(@SCRIPT,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-1345.16,-4065.02,-0.49,4.73, 'Islen Waterseer- Action 1 - Move to pos'),
(@SCRIPT,9,2,0,0,0,100,0,5000,5000,0,0,12,11256,3,30000,0,0,0,8,0,0,0,-1346.59,-4076.39,-1.23,1.6, 'Islen Waterseer - Action 2 - Summon'),
(@SCRIPT,9,3,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Islen Waterseer - Action 4 - Say line 0'),
(@SCRIPT,9,4,0,0,0,100,0,12000,12000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Islen Waterseer - Action 5 - Say line 1'),
(@SCRIPT,9,5,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-1345.0,-4048.0,6.09,4.34, 'Islen Waterseer - Action 6 - Move to pos'),
(@SCRIPT,9,6,0,0,0,100,0,6000,6000,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Islen Waterseer - Action 7 - Remove unit flags');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000057,2000000058);
DELETE FROM `creature_text` WHERE `entry`=@Islen_Waterseer;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Islen_Waterseer,0,0, 'Spirits of Water, I give you praise, and I beg of you a favour. You have heard $N''s pleas, and I trust his inent is noble. Please, will you aid us?',42,0,100,1,0,0, 'Islen Waterseer'),
(@Islen_Waterseer,1,0, 'Thank you great spirit. Thank you!',12,0,100,1,0,0, 'Islen Waterseer');

-- Convert quest_end_script "3922" to SAI
-- Indexes:
SET @Wenikee_Boltbucket := 9316;
SET @SCRIPT := @Wenikee_Boltbucket * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Wenikee_Boltbucket;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Wenikee_Boltbucket AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Wenikee_Boltbucket,0,0,0,20,0,100,0,3922,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Wenikee Boltbucket - On quest 3922 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wenikee Boltbucket - Action 0 - Say line 0'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,70,7,0,0,0,0,0,14,6579,162024,0,0,0,0,0, 'Wenikee Boltbucket - Action 1 - Respawn go guid in 7 seconds'),
(@SCRIPT,9,2,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,858.17,-2347.74,91.8282,6.06139, 'Wenikee Boltbucket - Action 2 - Move to pos'),
(@SCRIPT,9,3,0,0,0,100,0,1000,1000,0,0,5,173,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wenikee Boltbucket - Action 3 - Play emote'),
(@SCRIPT,9,4,0,0,0,100,0,4000,4000,0,0,11,13727,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wenikee Boltbucket - Action 4 - Cast spell'),
(@SCRIPT,9,5,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,858.14,-2347.64,91.92,2.72271, 'Wenikee Boltbucket - Action 5 - Move to pos'),
(@SCRIPT,9,6,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wenikee Boltbucket - Action 6 - Say line 1');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000103,2000000104);
DELETE FROM `creature_text` WHERE `entry`=@Wenikee_Boltbucket;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Wenikee_Boltbucket,0,0, 'Ok, let''s get started!',12,0,100,1,0,0, 'Wenikee Boltbucket'),
(@Wenikee_Boltbucket,1,0, '... oops.',12,0,100,1,0,0, 'Wenikee Boltbucket');

-- Convert quest_end_script "1191" to SAI
-- Indexes:
SET @Zamek := 4709;
SET @SCRIPT := @Zamek * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Zamek;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Zamek AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Zamek,0,0,0,20,0,100,0,1191,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zamek - On quest 1191 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-6273.41,-3841.7,-58.75,1.9, 'Zamek - Action 0 - Move to pos'),
(@SCRIPT,9,1,0,0,0,100,0,30000,30000,0,0,70,600,0,0,0,0,0,14,13621,20805,0,0,0,0,0, 'Zamek - Action 1 - Respawn go'),
(@SCRIPT,9,2,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-6224,-3945,-58.75,0.75, 'Zamek - Action 2 - Move to pos');

-- Convert quest_end_script "1103" to SAI
-- Indexes:
SET @Tiev_Mordune := 7007;
SET @SCRIPT := @Tiev_Mordune * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Tiev_Mordune;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Tiev_Mordune AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Tiev_Mordune,0,0,0,20,0,100,0,1103,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Tiev Vordune - On quest 1103 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,70,30,0,0,0,0,0,14,15175,106528,0,0,0,0,0, 'Tiev Mordune - Action 0 - Respawn go'),
(@SCRIPT,9,1,0,0,0,100,0,15000,15000,0,0,12,5895,3,180000,0,0,0,8,0,0,0,417.05,1822.39,13.007,0.035, 'Tiev Vordune - Action 1 - Move to pos'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,70,180,0,0,0,0,0,14,15176,106528,0,0,0,0,0, 'Tiev Mordune - Action 2 - Respawn go');

-- Convert quest_end_script "997"/"931"/"930" to SAI
-- Indexes:
SET @Denalan := 2080;
SET @SCRIPT := @Denalan * 100;
SET @SCRIPT1 := @SCRIPT + 1;
SET @SCRIPT2 := @SCRIPT + 2;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Denalan;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Denalan AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SCRIPT,@SCRIPT1,@SCRIPT2) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Denalan,0,0,0,20,0,100,0,997,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - On quest 997 rewarded - Start action list'),
(@Denalan,0,1,0,20,0,100,0,931,0,0,0,80,@SCRIPT1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - On quest 931 rewarded - Start action list 1'),
(@Denalan,0,2,0,20,0,100,0,930,0,0,0,80,@SCRIPT2,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - On quest 930 rewarded - Start action list 2'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 0 - Say 0'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,9505.03,719.358,1256.22,2.5643, 'Denalan - Action 1 - Move'),
(@SCRIPT,9,2,0,0,0,100,0,5000,5000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 2 - Play emote'),
(@SCRIPT,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 3 - Say 1'),
(@SCRIPT,9,4,0,0,0,100,0,1000,1000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 4 - Play emote'),
(@SCRIPT,9,5,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,14,0,0,0,9505.83,712.352,1255.89,0.533, 'Denalan - Action 5 - Move'),
(@SCRIPT1,9,0,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,9508.02,715.749,1255.89,1.03055, 'Denalan - Action 0 - Move'),
(@SCRIPT1,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 1 - Say 2'),
(@SCRIPT1,9,2,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,9507.66,718.009,1255.89,1.80417, 'Denalan - Action 2 - Move'),
(@SCRIPT1,9,3,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,9505.56,719.088,1256.2,2.65632, 'Denalan - Action 3 - Move'),
(@SCRIPT1,9,4,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 4 - Say 3'),
(@SCRIPT1,9,5,0,0,0,100,0,0,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 5 - Play emote'),
(@SCRIPT1,9,6,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,9506.92,713.766,1255.89,0.279253, 'Denalan - Action 6 - Move'),
(@SCRIPT1,9,7,0,0,0,100,0,2000,2000,0,0,70,15,0,0,0,0,0,14,67984,7510,0,0,0,0,0, 'Denalan - Action 7 - Respawn go'),
(@SCRIPT1,9,8,0,0,0,100,0,0,0,0,0,70,15,0,0,0,0,0,14,42936,7510,0,0,0,0,0, 'Denalan - Action 8 - Respawn go'),
(@SCRIPT1,9,9,0,0,0,100,0,0,0,0,0,70,15,0,0,0,0,0,14,30276,7510,0,0,0,0,0, 'Denalan - Action 9 - Respawn go'),
(@SCRIPT2,9,0,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 0 - Say 4'),
(@SCRIPT2,9,1,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 1 - Say 5'),
(@SCRIPT2,9,2,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,9508.02,715.749,1255.89,1.03055, 'Denalan - Action 2 - Move'),
(@SCRIPT2,9,3,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,9507.66,718.009,1255.89,1.80417, 'Denalan - Action 3 - Move'),
(@SCRIPT2,9,4,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,9505.56,719.088,1256.2,2.65632, 'Denalan - Action 4 - Move'),
(@SCRIPT2,9,5,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 5 - Say 6'),
(@SCRIPT2,9,6,0,0,0,100,0,5000,5000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 6 - Play emote'),
(@SCRIPT2,9,7,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,9506.92,713.766,1255.89,0.279253, 'Denalan - Action 7 - Move'),
(@SCRIPT2,9,8,0,0,0,100,0,0,0,0,0,12,3569,3,20000,0,0,0,8,0,0,0,9505.13,722.011,1255.94,0.0244875, 'Denalan - Action 8 - Summon'),
(@SCRIPT2,9,9,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Action 9 - Say 7'),
(@SCRIPT2,9,10,0,0,0,100,0,0,0,0,0,12,3569,3,20000,0,0,0,8,0,0,0,9504.09,720.294,1255.94,1.00709, 'Denalan - Action 10 - Summon'),
(@SCRIPT2,9,11,0,0,0,100,0,0,0,0,0,12,3569,3,20000,0,0,0,8,0,0,0,9504.13,721.459,1255.94,6.24727, 'Denalan - Action 11 - Summon');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000048,2000000049,2000000093,2000000094,2000000086,2000000087,2000000088,2000000089);
DELETE FROM `creature_text` WHERE `entry`=@Denalan;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Denalan,0,0, 'Now let us place this rare earth in my planter...',12,0,100,1,0,0, 'Denalan'),
(@Denalan,1,0, 'Thank you again, $N. This rare earth will be very helpful in my experiments.',12,0,100,1,0,0, 'Denalan'),
(@Denalan,2,0, 'Denalan hurries to his planter.',41,0,100,1,0,0, 'Denalan'),
(@Denalan,3,0, 'I hope this frond takes root...',12,0,100,1,0,0, 'Denalan'),
(@Denalan,4,0, 'Denalan removes the seeds from the Glowing Fruit...',41,0,100,1,0,0, 'Denalan'),
(@Denalan,5,0, 'Let''s see how these seeds grow in my prepared soil...',12,0,100,1,0,0, 'Denalan'),
(@Denalan,6,0, 'Denalan plants fruit seeds.',41,0,100,1,0,0, 'Denalan'),
(@Denalan,7,0, 'Bogling rises from the soil!',41,0,100,1,0,0, 'Denalan');

-- Convert quest_end_script "943" to SAI
-- Indexes:
SET @Archaeologist_Flagongut := 2911;
SET @SCRIPT := @Archaeologist_Flagongut * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Archaeologist_Flagongut;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Archaeologist_Flagongut AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Archaeologist_Flagongut,0,0,0,20,0,100,0,943,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Archaeologist Flagongut - On quest 943 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,12,3582,3,40000,0,0,0,8,0,0,0,-3809,-839,16.94,2.16, 'Archaeologist Flagongut - Action 0 - Summon'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archaeologist Flagongut - Action 1 - Say 0'),
(@SCRIPT,9,2,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3809,-839,16.94,2.16, 'Archaeologist Flagongut - Action 2 - Move'),
(@SCRIPT,9,3,0,0,0,100,0,24000,24000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archaeologist Flagongut - Action 3 - Say 1'),
(@SCRIPT,9,4,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-3819,-821,16.94,4.7, 'Archaeologist Flagongut - Action 4 - Move');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000060,2000000061);
DELETE FROM `creature_text` WHERE `entry`=@Archaeologist_Flagongut;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Archaeologist_Flagongut,0,0, 'By the stars! A spirit has been summoned!',12,0,100,1,0,0, 'Archaeologist Flagongut'),
(@Archaeologist_Flagongut,1,0, 'It''s a mystery of the past indeed! But a key to our future!',12,0,100,1,0,0, 'Archaeologist Flagongut');

-- Convert quest_end_script "902" to SAI
-- Indexes:
SET @Sputtervalve := 3442;
SET @SCRIPT := @Sputtervalve * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Sputtervalve;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sputtervalve AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Sputtervalve,0,0,0,20,0,100,0,902,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Sputtervalve - On quest 902 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sputtervalve - Action 0 - Say 0'),
(@SCRIPT,9,1,0,0,0,100,0,1000,1000,0,0,70,13,0,0,0,0,0,14,6552,162024,0,0,0,0,0, 'Sputtervalve - Action 1 - Respawn go'),
(@SCRIPT,9,2,0,0,0,100,0,1000,1000,0,0,5,173,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sputtervalve - Action 2 - Play emote'),
(@SCRIPT,9,3,0,0,0,100,0,6000,6000,0,0,11,13727,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sputtervalve - Action 3 - Cast spell'),
(@SCRIPT,9,4,0,0,0,100,0,1000,1000,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sputtervalve - Action 4 - Play emote none'),
(@SCRIPT,9,5,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Sputtervalve - Action 5 - Say 1');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000101,2000000102);
DELETE FROM `creature_text` WHERE `entry`=@Sputtervalve;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Sputtervalve,0,0, 'Ok, let''s take a look at this thing...',12,0,100,1,0,0, 'Sputtervalve'),
(@Sputtervalve,1,0, 'Oh, darn...',12,0,100,1,0,0, 'Sputtervalve');

-- Convert quest_end_script "492" to SAI
-- Indexes:
SET @Kalaran_Windblade := 8479;
SET @SCRIPT := @Kalaran_Windblade * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Kalaran_Windblade;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Kalaran_Windblade AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Kalaran_Windblade,0,0,0,20,0,100,0,492,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Kalaran Windblade - On quest 492 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kalaran Windblade - Action 0 - Say 0'),
(@SCRIPT,9,1,0,0,0,100,0,1000,1000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kalaran Windblade - Action 1 - Play emote'),
(@SCRIPT,9,2,0,0,0,100,0,4000,4000,0,0,11,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Kalaran Windblade - Action 2 - Cast Death Touch on self');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry`=2000000084;
DELETE FROM `creature_text` WHERE `entry`=@Kalaran_Windblade;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Kalaran_Windblade,0,0, 'I raise my brew and hope to be rid of the likes of you! Cheers, you no good scoundrel, $N!',12,0,100,1,0,0, 'Kalaran Windblade');

-- Convert quest_end_script "489" to SAI
-- Indexes:
SET @Zenn_Foulhoof := 2150;
SET @SCRIPT := @Zenn_Foulhoof * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Zenn_Foulhoof;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Zenn_Foulhoof AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Zenn_Foulhoof,0,0,0,20,0,100,0,492,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zenn Foulhoof - On quest 492 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,2000,2000,0,0,11,12244,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zenn Foulhoof - Action 0 - Cast spell'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,11,3329,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zenn Foulhoof - Action 1 - Cast spell'),
(@SCRIPT,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zenn Foulhoof - Action 2 - Say 0');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry`=2000000047;
DELETE FROM `creature_text` WHERE `entry`=@Zenn_Foulhoof;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Zenn_Foulhoof,0,0, 'Ribbit! No!! This cannot...ribbit...be! You have duped me with...ribbit...your foul trickery! Ribbit!',12,0,100,1,0,0, 'Zenn Foulhoof');

-- Convert quest_end_script "407" to SAI
-- Indexes:
SET @Scarlet_Zealot := 1931;
SET @SCRIPT := @Scarlet_Zealot * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet_Zealot;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Scarlet_Zealot AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Scarlet_Zealot,0,0,0,20,0,100,0,407,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarlet Zealot - On quest 407 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarlet Zealot - Action 0 - Say 0'),
(@SCRIPT,9,1,0,0,0,100,0,3000,3000,0,0,11,3287,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarlet Zealot - Action 1 - Cast spell'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2292,239.481,27.0892,0.693878, 'Scarlet Zealot - Action 2 - Move'),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,2287.97,236.253,27.0892,2.6613, 'Scarlet Zealot - Action 3 - Move'),
(@SCRIPT,9,4,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarlet Zealot - Action 4 - Say 1'),
(@SCRIPT,9,5,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,2292.52,235.226,27.0892,4.8345, 'Scarlet Zealot - Action 5 - Move'),
(@SCRIPT,9,6,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,2288.96,237.96,27.0892,2.48773, 'Scarlet Zealot - Action 6 - Move'),
(@SCRIPT,9,7,0,0,0,100,0,6000,6000,0,0,11,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarlet Zealot - Action 7 - Cast spell');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000082,2000000083);
DELETE FROM `creature_text` WHERE `entry`=@Scarlet_Zealot;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Scarlet_Zealot,0,0, 'I. . .I. . .don''t. . .feel. . .right. . .',12,0,100,1,0,0, 'Scarlet Zealot'),
(@Scarlet_Zealot,1,0, 'My mind. . .my flesh. . .I''m. . .rotting. . . .!',12,0,100,1,0,0, 'Scarlet Zealot');

-- Convert quest_end_script "349" to SAI
-- Indexes:
SET @Witch_Doctor_Unbagwa := 1449;
SET @SCRIPT := @Witch_Doctor_Unbagwa * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Witch_Doctor_Unbagwa;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Witch_Doctor_Unbagwa AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Witch_Doctor_Unbagwa,0,0,0,20,0,100,0,349,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Scarlet Zealot - On quest 349 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,2000,2000,0,0,12,1511,3,300000,0,0,0,8,0,0,0,-13743.7,-23.97,45.14,5.7, 'Witch Doctor Unbagwa - Action 0 - Summon'),
(@SCRIPT,9,1,0,0,0,100,0,28000,28000,0,0,12,1516,3,300000,0,0,0,8,0,0,0,-13743.7,-23.97,45.14,5.7, 'Witch Doctor Unbagwa - Action 1 - Summon'),
(@SCRIPT,9,2,0,0,0,100,0,20000,20000,0,0,12,1514,3,300000,0,0,0,8,0,0,0,-13743.7,-23.97,45.14,5.7, 'Witch Doctor Unbagwa - Action 2 - Summon');

-- Convert quest_end_script "308" to SAI
-- Indexes:
SET @Jarven_Thunderbrew := 1373;
SET @SCRIPT := @Jarven_Thunderbrew * 100;

-- Add SAI support
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Jarven_Thunderbrew;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Jarven_Thunderbrew AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Jarven_Thunderbrew,0,0,0,20,0,100,0,308,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Jarven Thunderbrew - On quest 308 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jarven Thunderbrew - Action 0 - Say 0'),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-5601.64,-541.38,392.42,0.5, 'Jarven Thunderbrew - Action 1 - Move'),
(@SCRIPT,9,2,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.94,-542.04,392.42,5.5, 'Jarven Thunderbrew - Action 2 - Move'),
(@SCRIPT,9,3,0,0,0,100,0,1000,1000,0,0,70,30,0,0,0,0,0,14,35875,270,0,0,0,0,0, 'Jarven Thunderbrew - Action 3 - Respawn'),
(@SCRIPT,9,4,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.95,-548.43,395.48,4.7, 'Jarven Thunderbrew - Action 4 - Move'),
(@SCRIPT,9,5,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5605.31,-549.33,399.09,3.1, 'Jarven Thunderbrew - Action 5 - Move'),
(@SCRIPT,9,6,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5607.55,-546.63,399.09,1.5, 'Jarven Thunderbrew - Action 6 - Move'),
(@SCRIPT,9,7,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.52,-538.75,399.09,1.5, 'Jarven Thunderbrew - Action 7 - Move'),
(@SCRIPT,9,8,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.62,-530.24,399.65,3, 'Jarven Thunderbrew - Action 8 - Move'),
(@SCRIPT,9,9,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5603.67,-529.91,399.65,4.2, 'Jarven Thunderbrew - Action 9 - Move'),
(@SCRIPT,9,10,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jarven Thunderbrew - Action 10 - Say 1'),
(@SCRIPT,9,11,0,0,0,100,0,11000,11000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5603.67,-529.91,399.65,4.2, 'Jarven Thunderbrew - Action 11 - Move'),
(@SCRIPT,9,12,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.62,-530.24,399.65,3, 'Jarven Thunderbrew - Action 12 - Move'),
(@SCRIPT,9,13,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.52,-538.75,399.09,1.5, 'Jarven Thunderbrew - Action 13 - Move'),
(@SCRIPT,9,14,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5607.55,-546.63,399.09,1.5, 'Jarven Thunderbrew - Action 14 - Move'),
(@SCRIPT,9,15,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5605.31,-549.33,399.09,3.1, 'Jarven Thunderbrew - Action 15 - Move'),
(@SCRIPT,9,16,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.95,-548.43,395.48,4.7, 'Jarven Thunderbrew - Action 16 - Move'),
(@SCRIPT,9,17,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-5597.94,-542.04,392.42,5.5, 'Jarven Thunderbrew - Action 17 - Move'),
(@SCRIPT,9,18,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jarven Thunderbrew - Action 18 - Say 2'),
(@SCRIPT,9,19,0,0,0,100,0,3000,3000,0,0,11,5,0,0,0,0,0,1,0,0,0,-5601.64,-541.38,392.42,0.5, 'Jarven Thunderbrew - Action 19 - Movel'),
(@SCRIPT,9,20,0,0,0,100,0,2000,2000,0,0,11,5,0,0,0,0,0,1,0,0,0,-5605.96,-544.45,392.43,0.9, 'Jarven Thunderbrew - Action 20 - Move'),
(@SCRIPT,9,21,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jarven Thunderbrew - Action 21 - Say 3');

-- Convert from db_script_string to creature_text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000077,2000000056,2000000078,2000000079);
DELETE FROM `creature_text` WHERE `entry`=@Jarven_Thunderbrew;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Jarven_Thunderbrew,0,0, '%s gestures to the pitcher of water sitting on the edge of the well.',12,0,100,1,0,0, 'Jarven Thunderbrew'),
(@Jarven_Thunderbrew,1,0, 'Hey there, Belm! Give me a mug of Thunder Ale, and one for my good friend $N.',12,0,100,1,0,0, 'Jarven Thunderbrew'),
(@Jarven_Thunderbrew,2,0, 'How goes the barrel watching...?',12,0,100,1,0,0, 'Jarven Thunderbrew'),
(@Jarven_Thunderbrew,3,0, 'Well, back to business for me. But it sure was nice taking that short break, and it''s always nice drinking Thunder Ale!',12,0,100,1,0,0, 'Jarven Thunderbrew');

-- Convert quest_end_script "63" to SAI
-- Indexes:
SET @Brazier_Everfount := 113791;
SET @SCRIPT := @Brazier_Everfount * 100;

-- Add SAI support
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@Brazier_Everfount;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Brazier_Everfount AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Brazier_Everfount,1,0,0,20,0,100,0,63,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Brazier of Everfount - On quest 63 rewarded - Start action list'),
(@SCRIPT,9,0,0,0,0,100,0,0,0,0,0,70,30,0,0,0,0,0,14,15175,106528,0,0,0,0,0, 'Brazier of Everfount - Action 0 - Respawn go'),
(@SCRIPT,9,1,0,0,0,100,0,15000,15000,0,0,70,180,0,0,0,0,0,14,15176,106529,0,0,0,0,0, 'Brazier of Everfount - Action 1 - Respawn go'),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,12,5895,3,180000,0,0,0,8,0,0,0,417.05,1822.39,13.007,0.035, 'Brazier of Everfount - Action 2 - Summon');
