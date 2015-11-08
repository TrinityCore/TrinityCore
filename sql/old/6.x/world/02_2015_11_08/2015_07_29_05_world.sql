--
SET @CGUID = 2; -- Set by TDB team (need 10)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 63331, 1, 1, 0, 10424.83, 765.6614, 1322.754, 1.998563, 120, 0, 0),
(@CGUID+1, 12160, 1, 1, 0, 10313.05, 816.032, 1327.698, 3.972167, 120, 10, 1),
(@CGUID+2, 12160, 1, 1, 0, 10413.19, 731.5011, 1321.063, 5.983846, 120, 10, 1), 
(@CGUID+3, 12160, 1, 1, 0, 10348.853, 751.136, 1325.35, 5.057269, 120, 10, 1),
(@CGUID+4, 62242, 1, 1, 0, 10626.83, 927.5742, 1327.541, 2.04279, 120, 15, 1),
(@CGUID+5, 62242, 1, 1, 0, 10625.32, 821.9661, 1316.752, 5.311656, 120, 15, 1),
(@CGUID+6, 62242, 1, 1, 0, 10575.35, 963.194, 1325.54, 4.892617, 120, 15, 1),
(@CGUID+7, 62242, 1, 1, 0, 10423.52, 919.1991, 1324.547, 5.583723, 120, 15, 1),
(@CGUID+8, 62242, 1, 1, 0, 10283.21, 854.236, 1341.771, 4.222265, 120, 15, 1),
(@CGUID+9, 61757, 1, 1, 0, 10690.396, 669.625, 1335.091, 5.874082, 120, 15, 1);

UPDATE `creature_template_addon` SET `emote`=426 WHERE `entry`=8583;
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=2031;
UPDATE `creature_template_addon` SET `mount`=6448 WHERE `entry`=49478;
UPDATE `creature_template_addon` SET `mount`=9991 WHERE `entry`=49477;
UPDATE `creature` SET `MovementType`=1, `spawndist`=15 WHERE `id` IN (883, 1984, 2031, 721,1989,2032,1985,890, 1986, 14881, 49728, 1988);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (48624, 48623, 62242);
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=44614;
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=49598;
UPDATE `creature_template` SET `unit_flags`=768  WHERE `entry` IN (49598);
DELETE FROM `creature` WHERE `guid`=271995;
UPDATE `quest_template` SET `flags`=0 WHERE `id`=28725;
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry`=44617;
UPDATE `creature` SET `curhealth`=650 WHERE `id`=44617;
DELETE FROM `smart_scripts` WHERE `entryorguid`=44617 AND `source_type`=0; -- 6x only
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=44617; -- 6x only
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (313087, 313078, 313080, 313108, 313104, 313102, 313120, 313126, 313118, 313123);

DELETE FROM `spell_area` WHERE `spell` IN (49417, 49416, 60922, 92549, 94566, 92237);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(49417, 188, 0, 28713, 0, 0, 2, 1, 0, 41),
(49416, 188, 28713, 28714, 0, 0, 2, 1, 66, 41),
(60922, 188, 28714, 0, 0, 0, 2, 1, 66, 0),
(92549, 188, 0, 28727, 0, 0, 2, 1, 0, 43),
(94566, 188, 28727, 0, 0, 0, 2, 1, 64, 0),
(92237, 257, 28725, 28728, -92239, 0, 2, 1, 74, 41);

DELETE FROM `creature_addon` WHERE `guid` IN (331003);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`auras`) VALUES
(331003,0,1,'80797');
UPDATE `creature_template_addon` SET `Auras`="80797" WHERE `entry`=8584;
UPDATE `creature_template_addon` SET `emote`="415" WHERE `entry`=2082;

SET @ENTRY := 2077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,70,0,2000,4000,7000,9000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melithar Forteramure - OOC - Play emote Talk"),
(@ENTRY,0,1,0,19,0,100,0,3118,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1"),
(@ENTRY,0,2,0,19,0,100,0,3117,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1"),
(@ENTRY,0,3,0,19,0,100,0,26841,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1"),
(@ENTRY,0,4,0,19,0,100,0,3119,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1"),
(@ENTRY,0,5,0,19,0,100,0,3116,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1"),
(@ENTRY,0,6,0,19,0,100,0,3120,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1"),
(@ENTRY,0,7,0,19,0,100,0,31168,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - on quest accepted - Say text1");

SET @ENTRY := 49479;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,28724,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - action list"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Close gossip"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Remove npc flag"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,11,87071,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Cast Alchemy"),
(@ENTRY*100,9,3,0,0,0,100,0,3000,3000,0,0,11,92388,0,0,0,0,0,19,8584,15,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Cast Curing Ivveron"),
(@ENTRY*100,9,4,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Say text 1"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Add npc flag"),
(@ENTRY,0,1,0,19,0,100,0,28725,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Say text 2"),
(@ENTRY,0,2,0,19,0,100,0,28729,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Say text 3"),
(@ENTRY,0,3,0,19,0,100,0,28730,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - on quest rewarded - Say text 4");

SET @ENTRY := 2079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY, 49478);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,49478) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100, 4947800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,28713,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ilthalaine - on quest rewarded - action list"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - Action list - Say text 1"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - Action list - store target"),
(@ENTRY*100,9,2,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,49477,10,0,0,0,0,0,"Ilthalaine - Action list - Say text 1"),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,100,1,0,0,0,0,0,19,49478,10,0,0,0,0,0,"Ilthalaine - Action list - Send target"),
(@ENTRY*100,9,4,0,0,0,100,0,6000,6000,0,0,45,1,1,0,0,0,0,19,49478,10,0,0,0,0,0,"Ilthalaine - Action list - Set data"),
(@ENTRY,0,1,0,19,0,100,0,3118,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - on quest accepted - Say text2"),
(@ENTRY,0,2,0,19,0,100,0,3117,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - on quest accepted - Say text2"),
(@ENTRY,0,3,0,19,0,100,0,26841,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - on quest accepted - Say text2"),
(@ENTRY,0,4,0,19,0,100,0,3119,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - on quest accepted - Say text2"),
(@ENTRY,0,5,0,19,0,100,0,3116,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - on quest accepted - Say text2"),
(@ENTRY,0,6,0,19,0,100,0,3120,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - on quest accepted - Say text2"),
(49478,0,0,0,38,0,100,0,1,1,0,0,80,4947800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On data set - action list"),
(4947800,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Dentaria Silverglade - Action list - Say text 1"),
(4947800,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Dentaria Silverglade - Action list - Say text 2");

SET @ENTRY := 44614;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,122,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,1,0,8,0,100,0,100,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,2,0,8,0,100,0,2098,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,3,0,8,0,100,0,56641,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,4,0,8,0,100,0,8921,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,5,0,8,0,100,0,589,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,6,0,8,0,100,0,100787,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Training Dummy - On Death - Respawn');

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (34757);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34757) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34757*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34757,0,0,0,10,0,100,0,1,25,25000,25000,80,34757*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doranel Amberleaf - ooc los - action list"),
(34757*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doranel Amberleaf - action list - Say text 1"),
(34757*100,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,34756,15,0,0,0,0,0,"Doranel Amberleaf - action list - Say text 1"),   -- 
(34757*100,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,10455.959961, 833.090576, 1380.937988, 2.795327,"Doranel Amberleaf - action list - Set Orientation"),
(34757*100,9,3,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,10456, 832.971985, 1381.02002, 5.3058,"Doranel Amberleaf - action list - Set Orientation");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1) AND `SourceEntry`=34757;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(22,1,34757,0,31,4,0,0,0,'','event require a player', 0, 0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (1994);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1994) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1994,0,0,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,49480,20,0,0,0,0,0,"Githyiss the Vile - On death  - Set data"),
(1994,0,1,0,4,0,100,0,0,0,0,0,45,1,3,0,0,0,0,11,49480,30,0,0,0,0,0,"Githyiss the Vile - On aggro  - Set data");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (1986);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1986) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1986,0,0,0,6,0,100,0,0,0,0,0,45,1,2,0,0,0,0,19,49480,20,0,0,0,0,0,"Webwood Spider - On death  - Set data");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (49480);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (49480) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (49480*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(49480,0,0,0,1,0,100,0,3000,3000,3000,3000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - ooc  - despawn if in area 188"),
(49480,0,1,0,0,0,100,0,3000,6000,8000,9000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarindrella - IC  - Cast Entangling Roots"),
(49480,0,2,0,38,0,100,0,1,3,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - on data set  - Say text 3"),
(49480,0,3,0,38,0,100,0,1,3,0,0,11,92573,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - on data seto  - Cast to Summon Nature's Bite"),
(49480,0,4,0,38,0,100,0,1,3,0,0,11,92573,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - on data set  - Cast to Summon Nature's Bite"),
(49480,0,5,0,38,0,100,0,1,3,0,0,11,92573,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - In aggro  - Cast to Summon Nature's Bite"),
(49480,0,6,7,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tarindrella - just summoned  - Say text 0"),
(49480,0,7,0,61,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - just summoned  - react passif"),
(49480,0,8,0,38,0,40,0,1,2,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - on data set  - Say text 1"),
(49480,0,9,0,38,0,100,0,1,1,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - on data set  - Say text 2"),
(49480,0,10,0,20,0,100,0,28727,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,"Tarindrella - ooc  - Say text 4"),
(49480,0,11,0,0,0,100,0,3000,6000,5000,6000,11,66056,0,0,0,0,0,23,0,0,0,0,0,0,0,"Tarindrella - IC  - Cast Entangling Roots"),   
(49480,0,12,0,19,0,100,0,28728,0,0,0,80,49480*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - On quest taken  - Actionlist"),
(4948000,9,0,0,0,0,100,0,0,0,0,0,85,92420,2,0,0,0,0,7,0,0,0,0,0,0,0,"Tarindrella - Actionlist  - Cast teleport"),
(4948000,9,1,0,0,0,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - Actionlist  - Despawn");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (34575, 34574);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34575, 34574) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3457400, 3457401, 3457402) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34575,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(34575,0,1,0,10,0,100,0,1,10,119000,119000,11,65656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doranel Amberleaf - ooc los - Cast Summon Shade of the Kaldorei"),
(34574,0,0,0,54,0,100,0,0,0,0,0,80,3457400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On just summoned  - Action list"),
(3457400,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text 1"),
(3457400,9,1,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text 2"),
(3457400,9,2,0,0,0,100,0,4000,4000,0,0,53,0,34574,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - start wp"),
(34574,0,1,0,40,0,100,0,1,34574,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On wp1 reached  - Pause wp"),
(34574,0,2,0,40,0,100,0,1,34574,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On wp1 reached  - Say text 2"),
(34574,0,3,0,40,0,100,0,3,34574,0,0,80,3457401,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On wp1 reached  - Action list"),
(3457401,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list  - Pause wp"),
(3457401,9,1,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list  - Say text 3"),
(3457401,9,2,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list  - Say text 4"),
(34574,0,4,0,40,0,100,0,4,34574,0,0,80,3457402,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On wp1 reached  - Action list"),
(3457402,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,10713.9882, 761.775, 1321.589, 2.957,"Shade of the Kaldorei - Action list  - Set orientation"),
(3457402,9,1,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list  - Say text 3"),
(3457402,9,2,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text 4"),
(3457402,9,3,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list  - Despawn");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (3514);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3514) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (351400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3514,0,0,0,10,0,100,0,1,10,20000,20000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tenaron Stormgrip - Ooc los  - Say line 1"),
(3514,0,1,0,19,0,100,0,28731,0,0,0,80,351400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tenaron Stormgrip - On quest accepted  - Action list"),
(351400,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tenaron Stormgrip - Action list  - Say text 2"),
(351400,9,1,0,0,0,100,0,0,0,0,0,11,65453,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tenaron Stormgrip - Action list  - Cast Wind's Embrace");

DELETE FROM `waypoints` WHERE `entry`=34574;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(34574,1,10702.9423, 761.374, 1322.905,"Shade of the Kaldorei"),
(34574,2,10704.4101, 769.148, 1322.599,"Shade of the Kaldorei"),
(34574,3,10706.4238, 768.360, 1322.765,"Shade of the Kaldorei"),
(34574,4,10713.9882, 761.775, 1321.589,"Shade of the Kaldorei");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1,2) AND `SourceEntry` IN (34575, 3514);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(22,2,34575,0,9,28730,0,0,0,'','event require quest 28730 taken', 0, 0),
(22,1,3514,0,31,4,0,0,0,'','event require a player', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1,3) AND `SourceEntry`=49480;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(22,1,49480,0,23,188,0,0,0,'','event require area 188', 0, 1);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-92237);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-92237, 92237, 0, 'Tarindrella Guardian Aura');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND  `SourceGroup`=0 AND `SourceEntry` IN (92238);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 92238, 0, 0, 29, 0, 49480, 20, 0, 1, 0, 0, '', 'Summon Tarindrella if sh''s not summoned');

DELETE FROM `creature_text` WHERE `entry` IN (2079, 49477, 49478, 2077, 49479, 34756, 34757, 49480, 34574, 3514);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(2079,0,0,"I'm sorry, Huntress. None of our new $cs are ready. They still have much to learn.",12,0,100,0,0,0, 'Ilthalaine', 49681),
(2079,1,0,"You'll find the trainer inside of Aldrassil, $n.",12,0,100,0,0,0, 'Ilthalaine', 49664),
(2077,0,0,"You'll find the trainer inside of Aldrassil, $n.",12,0,100,0,0,0, 'Melithar Staghelm', 49664),
(49477,0,0,"I fear time may not be on our side, Ilthalaine. The battle may carry to Teldrassil itself if we do not act soon.",12,0,100,0,0,0, 'Huntress Sandrya Moonfall', 49682),
(49478,0,0,"We will leave you to your training, Ilthalaine. This is your area of expertise.",12,0,100,0,0,0, 'Dentaria Silverglade', 49683),
(49478,1,0,"Study well, $n. We may need you fighting by our side before the next moon fills.",12,0,100,0,0,0, 'Dentaria Silverglade', 49684),
(49479,0,0,"Iverron's poison is cured, but it will take some time for him to recover.",12,0,100,0,0,0, 'Dentaria Silverglade', 49668),
(49479,1,0,"Shadowthread Cave lies to the north. Be careful, it's dangerous there of late.",12,0,100,0,0,0, 'Dentaria Silverglade', 49665),
(49479,2,0,"The moonwell is to the northeast, on the other side of the pool and up the hill.",12,0,100,0,0,0, 'Dentaria Silverglade', 49666),
(49479,3,0,"The ramp up to Aldrassil is just in sight over there. Circle around and find Tenaron up top.",12,0,100,0,0,0, 'Dentaria Silverglade', 49667),
(34756,0,0,"Shh! Someone's here.",12,0,100,0,0,0, 'Moriana Dawnlight', 35023),
(34757,0,0,"Don't get me wrong... I'm grateful to have Shando Stormrage back, but this is all really suspicious. What happened to Fandral?",12,0,100,0,0,0, 'Doranel Amberleaf', 35024),
(49480,0,0,"You've come to help, $c? Let us stay together for a while.",12,0,100,0,0,0, 'Tarindrella', 49550),
(49480,1,0,"The corruption goes much further than these spiders. I fear the true source is not within this cave.",12,0,100,0,0,0, 'Tarindrella', 49673),
(49480,1,1,"His body screams for death, but his soul",12,0,100,0,0,0, 'Tarindrella', 49672),
(49480,1,2,"I weep at these atrocities we commit. It is almost unbearable.",12,0,100,0,0,0, 'Tarindrella', 49674),
(49480,1,3,"Corruption this deep could not have come from outside.",12,0,100,0,0,0, 'Tarindrella', 49675),
(49480,1,4,"It almost seems as if he was born with this corruption inside of him.",12,0,100,0,0,0, 'Tarindrella', 49676),
(49480,1,5,"They are surely unredeemable, but it still hurts to see them die.",12,0,100,0,0,0, 'Tarindrella', 49670),
(49480,1,6,"The corruption is buried deep within him.",12,0,100,0,0,0, 'Tarindrella', 49669),
(49480,2,0,"This totem has been corrupting the eggs! It seems a greater threat looms. The Gnarlpine remain tainted by something most foul.",12,0,100,0,0,0, 'Tarindrella', 49697),
(49480,3,0,"My dear friends... I'm sorry..",12,0,100,0,0,0, 'Tarindrella', 49671),
(49480,4,0,"I'm going to stay and do what I can to free these spiders. Thank you for your help, $n.",12,0,100,0,0,0, 'Tarindrella', 49549),
(34574,0,0,"%s fades into existence as you approach, nodding a subtle greeting.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34832),
(34574,1,0,"Much has changed for our people since the Battle of Mount Hyjal.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34792),
(34574,2,0,"Nordrassil lies a pale shadow of what it once was, its power used to defeat Archimonde and drive back the Burning Legion.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34793),
(34574,3,0,"Our immortality-the very essence of our beings!-was lost.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34794),
(34574,4,0,"The Betrayer was freed from his prison, and Shand'do Stormrage disappeared into the emerald dream.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34795),
(34574,5,0,"A dark time for all.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34796),
(34574,6,0,"The Shade of the Kaldorei closes its eyes and fades away.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34820),
(3514,1,0,"Take with you the blessing of the wind's embrace. May it make your descent from Aldrassil more... direct.",12,0,100,1,0,0, 'Tenaron Stormgrip', 34602),
(3514,0,0,"Greetings, $c.",12,0,100,2,0,0, 'Tenaron Stormgrip', 13306);

UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (313169, 313206, 313226, 313274, 313219);
DELETE FROM `creature_addon` WHERE `guid` IN (313169, 313206, 313226, 313274, 313219);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (313169,3131690,1), (313206,3132060,1), (313226, 3132260,1), (313274, 3132740,1), (313219, 3132190,1);
DELETE FROM `waypoint_data` WHERE `id` IN (3131690, 3132060, 3132260, 3132740, 3132190);
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(3131690,0,10397.1, 883.697, 1321.38),
(3131690,1,10365.086, 866.052, 1324.957),
(3131690,2,10355.648, 852.585, 1325.153),
(3131690,3,10323.380, 827.040, 1326.372),
(3131690,4,10368.04, 747.071, 1321.498),
(3131690,5,10323.38, 827.040, 1326.372),
(3131690,6,10353.702, 850.765, 1325.191),
(3131690,7,10366.606, 867.413, 1324.948),
(3131690,8,10383.323, 875.205, 1323.82),
(3131690,9,10395.709, 884.819, 1321.464),
(3131690,10,10417.325, 886.186, 1318.983),
(3132060,0,10502.5, 835.888, 1361.219),
(3132060,1,10512.655, 820.212, 1354.791),
(3132060,2,10520.407, 825.945, 1354.791),
(3132060,3,10510.217, 848.159, 1348.965),
(3132060,4,10488.945, 856.990, 1342.790),
(3132060,5,10462.384, 858.067, 1339.001),
(3132060,6,10419.645, 885.502, 1319.205),
(3132060,7,10460.513, 858.739, 1338.220),
(3132060,8,10497.229, 855.959, 1344.867),
(3132060,9,10514.280, 843.018, 1350.855),
(3132060,10,10521.792, 823.973, 1354.790),
(3132060,11,10513.139, 821.360, 1354.790),
(3132060,12,10502.500, 835.888, 1361.219),
(3132060,13,10492.272, 845.633, 1366.704),
(3132060,14,10469.248, 849.412, 1375.608),
(3132060,15,10450.879, 843.149, 1380.849),
(3132060,16,10483.722, 849.269, 1370.218),
(3132260,0,10484.900, 800.648, 1326.810),
(3132260,1,10495.391, 797.863, 1328.542),
(3132260,2,10504.521, 796.760, 1330.43),
(3132260,3,10522.355, 782.140, 1329.599),
(3132260,4,10502.737, 796.839, 1330.355),
(3132260,5,10490.255, 799.390, 1326.818),
(3132260,6,10484.900, 800.648, 1326.810),
(3132260,7,10473.137, 799.122, 1322.745),
(3132260,8,10460.290, 799.294, 1322.586),
(3132260,9,10402.640, 764.818, 1322.690),
(3132260,10,10461.493, 799.607, 1322.670),
(3132260,11,10476.748, 799.978, 1324.267),
(3132260,12,10484.900, 800.648, 1326.810),
(3132740,0,10427.900, 771.281, 1335.500),
(3132740,1,10435.214, 776.668, 1337.285),
(3132740,2,10428.291, 786.768, 1337.285),
(3132740,3,10442.534, 797.240, 1345.633),
(3132740,4,10452.217, 797.576, 1345.652),
(3132740,5,10442.357, 796.852, 1345.633),
(3132740,6,10428.579, 787.004, 1337.286),
(3132740,7,10434.862, 776.611, 1337.286),
(3132740,8,10421.213, 767.289, 1331.536),
(3132740,9,10404.082, 759.106, 1322.680),
(3132740,10,10418.659, 765.651, 1329.756),
(3132190,0,10501.599, 787.122, 1397.800049),
(3132190,1,10484.208, 786.734, 1395.329834),
(3132190,2,10461.358, 798.532, 1388.930664),
(3132190,3,10444.578, 821.521, 1382.356323),
(3132190,4,10444.853, 834.345, 1380.909058),
(3132190,5,10449.272, 841.089, 1381.171143),
(3132190,6,10444.853, 834.345, 1380.909058),
(3132190,7,10444.578, 821.521, 1382.356323),
(3132190,8,10461.358, 798.532, 1388.930664),
(3132190,9,10484.208, 786.734, 1395.329834),
(3132190,10,10501.599, 787.122, 1397.800049);

UPDATE `creature` SET  `position_x`=10458.53, `position_y`=803.5,    `position_z`=1346.837, `orientation`=3.829888 WHERE `id`=3588;
UPDATE `creature` SET  `position_x`=10461.84, `position_y`=796.7726, `position_z`=1346.837, `orientation`=2.918795 WHERE `id`=3589;
UPDATE `creature` SET  `position_x`=10444.3,  `position_y`=783.1163, `position_z`=1337.368, `orientation`=3.441297 WHERE `id`=3590;
UPDATE `creature` SET  `position_x`=10436.1,  `position_y`=769.5018, `position_z`=1322.749, `orientation`=2.301193 WHERE `id`=43006;
UPDATE `creature` SET  `position_x`=10441.9,  `position_y`=773.5695, `position_z`=1322.749, `orientation`=2.372235 WHERE `id`=3595;
UPDATE `creature` SET  `position_x`=10449.46, `position_y`=780.4097, `position_z`=1322.753, `orientation`=3.088696 WHERE `id`=3591;
UPDATE `creature` SET  `position_x`=10433.55, `position_y`=796.7604, `position_z`=1322.79,  `orientation`=5.995227 WHERE `id`=3594;
UPDATE `creature` SET  `position_x`=10435.85, `position_y`=798.5434, `position_z`=1322.791, `orientation`=4.145119 WHERE `id`=3593;
UPDATE `creature` SET  `position_x`=10437.67, `position_y`=796.0573, `position_z`=1322.785, `orientation`=3.138109 WHERE `id`=3596;
UPDATE `creature` SET  `position_x`=10512.27, `position_y`=782.3906, `position_z`=1329.682, `orientation`=1.31167  WHERE `id`=3587;
UPDATE `creature` SET  `position_x`=10526.37, `position_y`=784.0903, `position_z`=1329.682, `orientation`=3.23779  WHERE `id`=6091;
UPDATE `creature` SET  `position_x`=10430,    `position_y`=765.778 , `position_z`=1322.75 , `orientation`=2.146750 WHERE `guid`=313269;
UPDATE `creature` SET  `position_x`=10396.87, `position_y`=775.3403, `position_z`=1322.796, `orientation`=5.280887  WHERE `id`=3592;
