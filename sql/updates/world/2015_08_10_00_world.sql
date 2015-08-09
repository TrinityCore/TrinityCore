SET @CGUID = 2; -- Set by TDB team (need 3)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 12160, 1, 1, 0, 10313.05, 816.032, 1327.698, 3.972167, 120, 10, 1),
(@CGUID+1, 12160, 1, 1, 0, 10413.19, 731.5011, 1321.063, 5.983846, 120, 10, 1), 
(@CGUID+2, 12160, 1, 1, 0, 10348.853, 751.136, 1325.35, 5.057269, 120, 10, 1);

UPDATE `creature_template_addon` SET `emote`=426 WHERE `entry`=8583;
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=2031;
UPDATE `creature_template_addon` SET `mount`=6448 WHERE `entry`=49478;
UPDATE `creature_template_addon` SET `mount`=9991 WHERE `entry` IN (49477, 34761);
UPDATE `creature` SET `MovementType`=1, `spawndist`=15 WHERE `id` IN (883, 1984, 2031, 721,1989,2032,1985,890, 1986, 14881, 49728, 1988);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (48624, 48623);
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=44614;
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=49598;
UPDATE `creature_template` SET `unit_flags`=768  WHERE `entry` IN (49598);
DELETE FROM `creature` WHERE `guid`=271995;
UPDATE `quest_template` SET `flags`=0 WHERE `id`=28725;
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry`=44617;
UPDATE `creature` SET `curhealth`=650 WHERE `id`=44617;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (313087, 313078, 313080, 313108, 313104, 313102, 313120, 313126, 313118, 313123);

DELETE FROM `spell_area` WHERE `spell` IN (49417, 49416, 60922, 92549, 94566, 92237) AND `area` IN (188, 257);
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
(@ENTRY,0,0,0,8,0,100,0,5143,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,1,0,8,0,100,0,100,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,2,0,8,0,100,0,2098,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,3,0,8,0,100,0,56641,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Training Dummy - On Death - Respawn');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (44617) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(44617,0,1,0,8,0,100,0,2061,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wounded Sentinel- On spell hit - Credit kill");

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

-- Part 2

SET @CGUID = 568; -- Set by TDB team (need 41)
SET @OGUID := 7; -- Set by TDB team (need 3)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+40;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 2030, 1, 1, 0, 10886.4, 1552.92, 1282.74, 4.18029, 300, 15, 1),
(@CGUID+1, 2030, 1, 1, 0, 10915.8, 1580.19, 1270.4, 5.62533, 300, 15, 1),
(@CGUID+2, 2030, 1, 1, 0, 10947.7, 1614.85, 1271.4, 3.91132, 300, 15, 1),
(@CGUID+3, 2030, 1, 1, 0, 10951, 1580.16, 1270.87, 4.43587, 300, 15, 1),
(@CGUID+4, 2030, 1, 1, 0, 10948.7, 1548.97, 1271.87, 1.54567, 300, 15, 1),
(@CGUID+5, 2030, 1, 1, 0, 10929.5, 1521.84, 1278.5, 4.21832, 300, 15, 1),
(@CGUID+6, 2030, 1, 1, 0, 10884, 1614.79, 1270.73, 2.25397, 300, 15, 1),
(@CGUID+7, 2030, 1, 1, 0, 10849.6, 1581.85, 1273.72, 5.01153, 300, 15, 1),
(@CGUID+8, 2166, 1, 1, 0,10469.4, 1451.67, 1327.55, 0.128997, 300, 10, 1),
(@CGUID+9, 2027, 1, 1, 0, 10442.3, 1585.11, 1284.26, 0.185374, 300, 15, 1),
(@CGUID+10, 2027, 1, 1, 0, 10503.2, 1579.87, 1303.58, 4.42541, 300, 15, 1),
(@CGUID+11, 2027, 1, 1, 0, 10513.6, 1639.99, 1283.9, 3.79467, 300, 15, 1),
(@CGUID+12, 2027, 1, 1, 0, 10541.3, 1691.1, 1296.07, 2.98256, 300, 15, 1),
(@CGUID+13, 2029, 1, 1, 0, 10649, 1653.19, 1281.85, 1.37573, 300, 15, 1),
(@CGUID+14, 2029, 1, 1, 0, 10821.1, 1618.67, 1271.26, 0.204982, 300, 15, 1),
(@CGUID+15, 2029, 1, 1, 0, 10708.4, 1669.06, 1277.46, 1.88941, 300, 15, 1),
(@CGUID+16, 2029, 1, 1, 0, 10582.1, 1650.66, 1281.77, 4.29351, 300, 15, 1),
(@CGUID+17, 2029, 1, 1, 0, 10616, 1612.38, 1287.78, 4.48779, 300, 15, 1),
(@CGUID+18, 2029, 1, 1, 0, 10752.5, 1614.48, 1270.07, 5.82202, 300, 15, 1),
(@CGUID+19, 2029, 1, 1, 0, 10643.7, 1588.44, 1294.39, 2.46736, 300, 15, 1),
(@CGUID+20, 2029, 1, 1, 0, 10682.7, 1617.88, 1278.85, 0.555947, 300, 15, 1),
(@CGUID+21, 2000, 1, 1, 0, 10363.5, 1490.32, 1322.63, 4.22996, 300, 15, 1),
(@CGUID+22, 2000, 1, 1, 0, 10522.6, 1721.17, 1302.47, 4.90787, 300, 15, 1),
(@CGUID+23, 2000, 1, 1, 0, 10552.8, 1717.76, 1306.16, 2.49093, 300, 15, 1),
(@CGUID+24, 2000, 1, 1, 0, 10637.2, 1491.34, 1314.14, 2.25591, 300, 15, 1),
(@CGUID+25, 2000, 1, 1, 0, 10684.3, 1716, 1301.8, 3.72755, 300, 15, 1),
(@CGUID+26, 2000, 1, 1, 0, 10690.5, 1426.66, 1325.6, 4.03666, 300, 15, 1),
(@CGUID+27, 2000, 1, 1, 0, 10737.2, 1382.99, 1328.06, 2.52163, 300, 15, 1),
(@CGUID+28, 1997, 1, 1, 0, 10452.8, 1487.4, 1315.84, 5.14489, 300, 15, 1),
(@CGUID+29, 1997, 1, 1, 0, 10471.8, 1569, 1297.31, 5.1673, 300, 15, 1),
(@CGUID+30, 1997, 1, 1, 0, 10482.3, 1457.54, 1327.43, 3.27576, 300, 15, 1),
(@CGUID+31, 1997, 1, 1, 0, 10715.4, 1447.84, 1323.72, 3.48325, 300, 15, 1),
(@CGUID+32, 1997, 1, 1, 0, 10749.1, 1477.22, 1317.92, 4.80827, 300, 15, 1),
(@CGUID+33, 1997, 1, 1, 0, 10758.8, 1510.72, 1311.72, 0.069394, 300, 15, 1),
(@CGUID+34, 2033, 1, 1, 0,10581.1, 1516.21, 1315.97, 1.23271, 300, 15, 1),
(@CGUID+35, 2033, 1, 1, 0,10692.7, 1498.61, 1305.33, 3.88072, 300, 15, 1),
(@CGUID+36, 2033, 1, 1, 0,10519.7, 1560.88, 1302.73, 2.83824, 300, 15, 1),
(@CGUID+37, 2033, 1, 1, 0,10541.4, 1477.35, 1325.2, 3.31133, 300, 15, 1),
(@CGUID+38, 2033, 1, 1, 0,10326.8, 1454.97, 1340.1, 3.50596, 300, 15, 1),
(@CGUID+39, 2033, 1, 1, 0,10292.6, 1780.71, 1321.65, 6.27733, 300, 15, 1),
(@CGUID+40, 2033, 1, 1, 0,10380.6, 1492.62, 1319.31, 1.8839, 300, 15, 1);

DELETE FROM `gameobject` WHERE `id` IN (195174, 195175, 195176);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0, 195175, 1, 1, 0, 9150.53, 1838.69, 1327.58, 2.88144, 0, 0, 0.991552, 0.129707, 300, 255, 1), 
(@OGUID+1, 195176, 1, 1, 0, 9122.65, 1776.09, 1321.49, 2.87272, 0, 0, 0.990977, 0.13403, 300, 255, 1),
(@OGUID+2, 195174, 1, 1, 0, 9110.72, 1844.54, 1327.5, 3.01233, 0, 0, 0.997912, 0.064582, 300, 255, 1);

SET @CGUID = 802; -- Set by TDB team (need 56)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+55;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(@CGUID+0, 34522, 1, 1, 0, 9114.52, 1835.88, 1328.18, 0.383972, 300),
(@CGUID+1, 34522, 1, 1, 0, 9146.16, 1835.6,  1327.68, 2.60054, 300),
(@CGUID+2, 34522, 1, 1, 0, 9103.31, 1781.89, 1324.65, 5.2709, 300),
(@CGUID+3, 34522, 1, 1, 0, 9390.06, 1707.76, 1306.19, 0.142008, 300),
(@CGUID+4, 34522, 1, 1, 0, 9302.64, 1706.77, 1318.5,  6.17646, 300),
(@CGUID+5, 34524, 1, 1, 0, 9118.99, 1841.19, 1327.6,  0.20944, 300),
(@CGUID+6, 34524, 1, 1, 0, 9140.63, 1835.12, 1327.86, 2.32129, 300),
(@CGUID+7, 34524, 1, 1, 0, 9141.28, 1841.81, 1326.81, 2.93215, 300),
(@CGUID+8, 34524, 1, 1, 0, 9122.16, 1842.75, 1327.26, 0.122173,300),
(@CGUID+9, 34524, 1, 1, 0, 9146.56, 1840.94, 1327.14, 2.94961, 300),
(@CGUID+10, 34524, 1, 1, 0, 9121.84, 1836.86, 1328.3,  0.593412,300),
(@CGUID+11, 34524, 1, 1, 0, 9103.89, 1778.31, 1324.25, 5.55015, 300),
(@CGUID+12, 34524, 1, 1, 0, 9099.82, 1781.42, 1326.01, 5.42797, 300),
(@CGUID+13, 34524, 1, 1, 0, 9106.95, 1785.78, 1323.74, 5.3058, 300),
(@CGUID+14, 34524, 1, 1, 0, 9102.93, 1772.87, 1324.5,  5.42797, 300),
(@CGUID+15, 34524, 1, 1, 0, 9107.43, 1781.46, 1323.37, 5.42797, 300),
(@CGUID+16, 34524, 1, 1, 0, 9373.47, 1701.69, 1307.19, 0.35098, 300),
(@CGUID+17, 34524, 1, 1, 0, 9378.08, 1707.24, 1307.82, 0.0452782,300),
(@CGUID+18, 34524, 1, 1, 0, 9494.21, 1729.87, 1293.47, 0.34503, 300),
(@CGUID+19, 34524, 1, 1, 0, 9492,    1729.14, 1293.17, 0.333665, 300),
(@CGUID+20, 34524, 1, 1, 0, 9372.27, 1702.07, 1307.44, 0.309179, 300),
(@CGUID+21, 34525, 1, 1, 0, 9125.75, 1719.96, 1319.05, 6.10865, 300),
(@CGUID+22, 34525, 1, 1, 0, 9120.83, 1718.24, 1319.76, 6.24828, 300),
(@CGUID+23, 34525, 1, 1, 0, 9121.3,  1723.32, 1319.15, 5.95157, 300),
(@CGUID+24, 34525, 1, 1, 0, 9124.18, 1827.71, 1328.66, 1.06465, 300),
(@CGUID+25, 34525, 1, 1, 0, 9124.38, 1831.77, 1328.62, 0.942478, 300),
(@CGUID+26, 34525, 1, 1, 0, 9109.45, 1841.29, 1327.59, 0.0872665,300),
(@CGUID+27, 34525, 1, 1, 0, 9106.83, 1844.28, 1327.59, 6.24828, 300),
(@CGUID+28, 34525, 1, 1, 0, 9124.65, 1777.34, 1321.28, 4.06662, 300),
(@CGUID+29, 34525, 1, 1, 0, 9122.14, 1778.87, 1321.63, 4.79965, 300),
(@CGUID+30, 34525, 1, 1, 0, 9129.18, 1830.08, 1328.54, 1.32645, 300),
(@CGUID+31, 34525, 1, 1, 0, 9120.2, 1775.58, 1321.9, 6.05629, 300),
(@CGUID+32, 34521, 1, 1, 0, 9132.51, 1843.83, 1327.02, 4.32842, 300),
(@CGUID+33, 2041, 1, 1, 0, 10014.681, 1913.451, 1329.70, 4.543223, 300),
(@CGUID+34, 2041, 1, 1, 0, 9948.699, 2044.195, 1329.948, 5.860334, 300),
(@CGUID+35, 4423, 1, 1, 0, 10253.996, 2538.350, 1334.564, 0.523322, 300),
(@CGUID+36, 4423, 1, 1, 0, 10245.595, 2552.594, 1333.374, 1.403752, 300),
(@CGUID+37, 4423, 1, 1, 0, 10200.453, 2593.298, 1323.493, 0.728309, 300),
(@CGUID+38, 4423, 1, 1, 0, 10119.420, 2627.700, 1323.635, 2.251772, 300),
(@CGUID+39, 4423, 1, 1, 0, 10089.391, 2611.625, 1322.089, 2.140244, 300),
(@CGUID+40, 2041, 1, 1, 0, 10228.429, 2642.442, 1321.750, 3.174825, 300),
(@CGUID+41, 2041, 1, 1, 0, 10202.888, 2670.41, 1320.602, 4.525507, 300),
(@CGUID+42, 2041, 1, 1, 0, 10106.509, 2668.337, 1318.270, 5.827691, 300),
(@CGUID+43, 2041, 1, 1, 0, 10384.809, 2461.476, 1337.153, 4.398274, 300),
(@CGUID+44, 2041, 1, 1, 0, 10362.449, 2372.032, 1333.223, 3.310497, 300),
(@CGUID+45, 4262, 1, 1, 0, 10100.132, 2388.805, 1316.575, 2.111684, 300),
(@CGUID+46, 4262, 1, 1, 0, 10172.1, 2343.781, 1328.059, 6.031611, 300),
(@CGUID+47, 4262, 1, 1, 0, 10227.4, 2399.558, 1329.719, 6.00962, 300),
(@CGUID+48, 2041, 1, 1, 0, 10042.247, 2218.097, 1328.158, 0.341, 300),
(@CGUID+49, 2041, 1, 1, 0, 10033.202, 2188.435, 1328.062, 4.457675, 300),
(@CGUID+50, 4262, 1, 1, 0, 9927.770,1980.428, 1344.571, 4.991534, 300),
(@CGUID+51, 4262, 1, 1, 0, 9950.338,2019.333, 1353.318, 4.119741, 300),
(@CGUID+52, 4262, 1, 1, 0, 9957.236,1984.951, 1353.318, 6.173552, 300),
(@CGUID+53, 4262, 1, 1, 0, 10023.306, 2019.579, 1353.317, 4.975816, 300),
(@CGUID+54, 4262, 1, 1, 0, 9963.8164, 2253.166, 1334.978, 4.844656, 300),
(@CGUID+55, 4262, 1, 1, 0, 9941.563, 2252.546, 1334.928, 4.845440, 300);

DELETE FROM `creature_template_addon` WHERE `entry` IN (50498);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(50498, 0, 0x1, 0x101, ''); -- 50498

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (35281,52292,4165,47569,36506,2912,50690,50715,50714,50499,36479,50502,50519,50516,50517,50521,50518,50520,50508,50509,50510,50513,50501,50504,50500,50497,50506, 50505, 50507);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35281,52292,4165,47569,36506,2912,50690,50715,50714,50499,36479,50502,50519,50516,50517,50521,50518,50520,50508,50509,50510,50513,50501,50504,50500,50497,50506, 50505, 50507) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35281,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(52292,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(4165,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273, 1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(47569,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(36506,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(2912,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273, 1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50690,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50715,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50714,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50499,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(36479,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50502,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50519,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50516,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50517,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50521,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50518,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50520,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50508,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50509,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50510,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50513,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50501,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50504,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50500,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50497,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50506,0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50505, 0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)"),
(50507, 0,0,0,1,0,50,0,3000,5000,3000,5000,10,274,273,1,0,0,0,1,0,0,0,0,0,0,0,"Cosmetic NPC - Out of Combat - Play Random Emote (274, 273, 1)");

DELETE FROM `creature_template_addon` WHERE `entry` IN (50305, 50307);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(50305, 29256, 0x0, 0x101, ''), 
(50307, 2402, 0x0, 0x101, '');

UPDATE `creature` SET `MovementType`=1, `spawndist`=15 WHERE `id` IN (1995, 49778, 2042, 7235, 2008, 1998, 2007, 2006, 1996, 2043, 1999, 2025, 2027, 2022, 2000, 1997, 2034, 2001, 2030, 2029, 2033);
UPDATE `creature` SET `MovementType`=1, `spawndist`=7 WHERE `id` IN (2002, 2003, 2004, 2005, 2009, 2010, 2011, 2152, 34517, 34530, 34396, 4242, 55272, 55273, 3681, 54116); 
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (311937, 311941);

UPDATE `creature` SET `MovementType`=2,`position_x`=9816.841797,`position_y`=355.442474,`position_z`=1308.459351,`currentwaypoint`=1 WHERE `guid`=312671;
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (312748, 312734, 312238, 844, 311991, 849, 848, 847, 850, 854);
UPDATE `creature` SET `MovementType`=2,`position_x`=9658.96,`position_y`=2432.3,`position_z`=1335.68,`currentwaypoint`=1 WHERE `guid`=312111;
UPDATE `creature` SET `MovementType`=2,`position_x`=9776.55,`position_y`=2531.54,`position_z`=1318.93,`currentwaypoint`=1 WHERE `guid`=311671;
UPDATE `creature` SET `MovementType`=2,`position_x`=9775.32,`position_y`=2526.24,`position_z`=1318.84,`currentwaypoint`=1 WHERE `guid`=311651;
UPDATE `creature` SET `MovementType`=2,`position_x`=10174.8,`position_y`=2346.64,`position_z`=1328.18,`currentwaypoint`=1 WHERE `guid`=312060;
UPDATE `creature` SET `MovementType`=2,`position_x`=9932.1,`position_y`=2593.26,`position_z`=1315.93,`currentwaypoint`=1 WHERE `guid`=311613;
UPDATE `creature` SET `MovementType`=2,`position_x`=10090.2,`position_y`=2522.53,`position_z`=1317.589,`currentwaypoint`=1 WHERE `guid`=311970;
UPDATE `creature` SET `MovementType`=2,`position_x`=10126,`position_y`=2582.53,`position_z`=1325.97,`currentwaypoint`=1 WHERE `guid`=311995;
UPDATE `creature` SET `MovementType`=2,`position_x`=9662.45,`position_y`=2327.01,`position_z`=1327.61,`currentwaypoint`=1 WHERE `guid`=311759;  
UPDATE `creature` SET `MovementType`=2,`position_x`=9732.6,`position_y`=2255.22,`position_z`=1327.49,`currentwaypoint`=1 WHERE `guid`=311769;
UPDATE `creature` SET `MovementType`=1,`position_x`=9633.372,`position_y`=2524.039,`position_z`=1371.021 WHERE `guid`=311708;

DELETE FROM creature WHERE `id`=3569;
DELETE FROM `creature_addon` WHERE `guid` IN (312671);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`path_id`,`auras`) VALUES
(312671,0,1,3126710,'');
DELETE FROM `creature_addon` WHERE `guid` IN (312761, 312756, 312766);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`auras`,`emote`) VALUES
(312761,8,1,'',0),
(312756,0,1,'',426),
(312766,0,1,'',426);
DELETE FROM `creature_addon` WHERE `guid` IN (312748, 312734, 312238, 844, 311991, 311970);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`path_id`,`auras`) VALUES
(312748,0,1,3127480,''),
(312734,0,1,3127340,''),
(312238,0,1,3122380,''),
(844,0,1,8440,''),
(311991,0,1,3119910,''),
(311970,0,1,3119700,'');

DELETE FROM `creature_addon` WHERE `guid` IN (849, 848, 847, 850, 854);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`,`bytes2`,`path_id`,`auras`) VALUES
(849,14332,0,1,8490,''),
(848,14332,0,1,8480,''),
(847,14332,0,1,8470,''),
(854,14332,0,1,8540,''),
(850,0,0,1,8500,'');

UPDATE `creature_template_addon` SET `path_id`=3121110 WHERE `entry`=10878;
UPDATE `creature_template_addon` SET `path_id`=3116710 WHERE `entry`=3562;
UPDATE `creature_template_addon` SET `path_id`=3116510 WHERE `entry`=14378;
UPDATE `creature_template_addon` SET `path_id`=3120600 WHERE `entry`=14379;
UPDATE `creature_template_addon` SET `path_id`=3116130 WHERE `entry`=5782;
UPDATE `creature_template_addon` SET `path_id`=3119950 WHERE `entry`=4167;
UPDATE `creature_template_addon` SET `path_id`=3117590 WHERE `entry`=14380;
UPDATE `creature_template_addon` SET `path_id`=3117690 WHERE `entry`=4169;

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (1995, 3681, 51371, 37543, 37574, 1996, 2853, 34575, 62450, 54116, 65097);
UPDATE `creature_template_addon` SET `mount`=22470 WHERE `entry`=51371;

UPDATE `smart_scripts` SET `action_param1`=41056 WHERE `entryorguid`=2008 AND `source_Type`=0 AND `id`=0;
UPDATE `creature_template` SET `unit_flags`=768, `VehicleId`=432 WHERE `entry`=34760;
UPDATE `creature_template` SET `gossip_menu_id`=10517, `unit_flags`=768 WHERE `entry`=34249;
UPDATE `creature_template` SET `npcflag`=1, `gossip_menu_id`=10517, `unit_flags`=768 WHERE `entry`=34249;
DELETE FROM `gameobject` WHERE `guid`=218959;

DELETE FROM `spell_area` WHERE `spell` IN (65548, 65549) AND `area` IN (262);
DELETE FROM `spell_area` WHERE `spell` IN (84777, 66130) AND `area` IN (186, 262);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(84777, 186, 0, 7383, 0, 0, 2, 1, 0, 41),
(66130, 262, 13945, 483, 0, 0, 2, 1, 74, 9),
(65548, 262, 0, 2561, 0, 0, 2, 1, 0, 97),
(65549, 262, 2561, 2561, 0, 0, 2, 1, 10, 43);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-65549);
INSERT INTO `spell_linked_spell` VALUES (-65549, 65548, 0, 'Ban''ethil Barrow Den: See Quest Invis');

DELETE FROM `gameobject_addon` WHERE `guid` IN (204691, 211041);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES 
(204691,7,1000), (211041,8,1000);
UPDATE `gameobject` SET `state`=2 WHERE `guid`=211041;

DELETE FROM `gossip_menu` WHERE `entry`=10517;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (10517, 14549);

DELETE FROM `gossip_menu` WHERE `entry`=10564 AND `text_id`=4994;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (10564, 4994);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10564 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES
(10564, 0, 0, "I'm ready to depart for Ban'ethil Barrow Den.", 35036, 1, 1);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10517;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`) VALUES
(10517, 0, 0, "Where is the Rune of Nesting?", 34642, 1, 1),  
(10517, 1, 0, "Where is the Sapphire of Sky?", 34643, 1, 1),
(10517, 2, 0, "Where is the Black Feather Quill?", 34644, 1, 1),
(10517, 3, 0, "Where is the Raven Claw Talisman?", 34645, 1, 1),
(10517, 4, 0, "Where I can find Oben Rageclaw?", 34646, 1, 1),
(10517, 5, 0, "Can you lead me to the exit?", 34670, 1, 1);

SET @ENTRY := 3515;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY, 34586, 34583, 2081, 34761, 34760, 1999, 34249, 14429, 2852, 2853, 34584, 34585, 1992);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY, -312720, 34586, -312853, 34583, 2081, 34761, 34760, 34249, 14429, 2852, 2853, 2009, 2010, 2011, 1999, -311234, 34584, 34585, -311413, -312359, -312365, -312388, -311408,-311409,-311414,-311415,-311416, 1992) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2002, 2003, 2004, 2005, 2000, 7234, 2039) AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3458600, 3458300, 3476000, 3458400, 3458500, 199200) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,28731,0,0,0,45,1,1,0,0,0,0,19,34575,20,0,0,0,0,0,"Corithras Moonrage - on quest rewarded - Set Data"),
(-312720,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(-312720,0,1,0,38,0,100,0,1,1,0,0,11,65676,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - on data set - Cast Summon Shade of the Kaldorei"),
(34586,0,0,0,54,0,100,0,0,0,0,0,80,3458600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On just summoned - Action list"),
(3458600,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Set run off"),
(3458600,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,9733.180,955.127,1295.25,2.263,"Shade of the Kaldorei - Action list - move to pos"),
(3458600,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text1"),
(3458600,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text2"),
(3458600,9,4,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text3"),
(3458600,9,5,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - State Kneel"),
(3458600,9,6,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text4"),
(3458600,9,7,0,0,0,100,0,7000,7000,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - State stand"),
(3458600,9,8,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,9733.180, 955.127, 1295.25, 0.186,"Shade of the Kaldorei - Action list - Set orientation"),
(3458600,9,9,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text5"),
(3458600,9,10,0,0,0,100,0,6000,6000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text6"),
(3458600,9,11,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Despawn"),
(-312853,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(-312853,0,1,0,10,0,100,0,1,10,119000,119000,11,65668,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - ooc los - Cast Summon Shade of the Kaldorei"),
(34583,0,0,0,54,0,100,0,0,0,0,0,80,3458300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On just summoned  - Action list"),
(3458300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text 1"),
(3458300,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text"),
(3458300,9,2,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text"),
(3458300,9,3,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text"),
(3458300,9,4,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text"),
(3458300,9,5,0,0,0,100,0,9000,9000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text"),
(3458300,9,6,0,0,0,100,0,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Actionlist  - Say text"),
(2081,0,0,0,19,0,100,0,13945,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Kyra Starsong - on quest Accepted - Say text"),
(34761,0,0,1,62,0,100,0,10564,0,0,0,11,66159,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Kyra Starsong - on gossip select - Cast Forcecast Summon Nightsaber"),
(34761,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Kyra Starsong - on gossip select - Close gossip"),
(34760,0,0,0,54,0,100,0,0,0,0,0,80,3476000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Nightsaber - Just summoned - Action list"),
(3476000,9,0,0,0,0,100,0,3000,3000,0,0,53,1,34760,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Nightsaber - Action list - start waypoint"),
(34760,0,1,2,40,0,100,0,19,0,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Nightsaber - on way point reached - Cast eject passengers"),
(34760,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Nightsaber - on way point reached - despawn"),
(2002,0,1,0,0,0,100,0,2000,4000,15000,16000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rascal Sprite - IC - Cast Faerie Fire"),
(2003,0,1,0,0,0,100,0,2000,4000,3500,4000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Sprite - IC - Cast Shadow Bolt"),
(2004,0,1,0,0,0,100,0,2000,4000,12000,13000,11,5514,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Sprite - IC - Cast Darken Vision"),
(2005,0,1,0,8,0,100,1,65455,0,0,0,33,34440,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vicious Grell - On spell hit - Kill credit"),
(2000,0,1,0,0,0,100,0,2000,4000,15000,17000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Webwood Silkspinner - IC - Cast Poison"),
(7234,0,1,0,0,0,100,0,2000,4000,5000,7000,11,78921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ferocitas the Dream Eater - IC - Cast Dream Lash"),
(14429,0,0,0,0,0,100,0,2000,4000,4000,5000,11,19319,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimmaw - IC - Cast Vicious Bite"),
(2039,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,2852,100,0,0,0,0,0,"Ursal the Mauler - On death - set data"),
(2852,0,0,1,38,0,100,0,1,1,0,0,12,2853,3,7000,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Data set  - Summon unit"),
(2852,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Druid of the Talon - On Data set  - Despawn"),
(2853,0,0,0,54,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,10342.299, 1201.523, 1472.23, 3.2734,"Freed Druid of the Talon - On just summoned  - move to pos"),
(34249,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sentinel Huntress - just summoned - say text1"),
(34249,0,1,2,62,0,100,0,10517,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Say text"),
(34249,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Close gossip"),
(34249,0,3,4,62,0,100,0,10517,1,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Say text"),
(34249,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Close gossip"),
(34249,0,5,6,62,0,100,0,10517,2,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Say text"),
(34249,0,6,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Close gossip"),
(34249,0,7,8,62,0,100,0,10517,3,0,0,1,6,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Say text"),
(34249,0,8,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Close gossip"),
(34249,0,9,10,62,0,100,0,10517,4,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Say text"),
(34249,0,10,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Close gossip"),
(34249,0,11,12,62,0,100,0,10517,5,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Say text"),
(34249,0,12,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentinel Huntress - on gossip select - Close gossip"),
(2009,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlpine Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2009,0,1,0,0,0,100,0,2000,4000,12000,13000,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarlpine Shaman - IC - Cast Flame Shock"),
(2009,0,2,0,0,0,100,0,6000,8000,13000,16000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlpine Shaman - IC - Cast Healing Wave"),
(2010,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlpine Defender - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2011,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlpine Augur - Between 0-15% Health - Flee For Assist (No Repeat)"),
(2011,0,1,0,0,0,100,0,2000,4000,8000,11000,11,17227,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarlpine Augur - IC - Cast Curse of Weakness"),
(2011,0,2,0,2,0,100,1,0,20,0,0,11,5628,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlpine Augur - IN health pct 20% - Cast Gnarlpine Vengeance"),
(1999,0,0,0,0,0,100,0,2000,4000,15000,16000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Webwood Venomfang - IC - Cast ¨Poison"),
(-311234,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(-311234,0,1,0,10,0,100,0,1,10,119000,119000,11,65680,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - ooc los - Cast Summon Shade of the Kaldorei"),
(34584,0,0,0,54,0,100,0,0,0,0,0,80,3458400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On just summoned - Action list"),
(3458400,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Set run off"),
(3458400,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,10669.8125,1858.392578,1325.901611,6.21656,"Shade of the Kaldorei - Action list - move to pos"),
(3458400,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text1"),
(3458400,9,3,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text2"),
(3458400,9,4,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text3"),
(3458400,9,5,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text4"),
(3458400,9,6,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,10671.004883,1863.977295,1325.617676,4.771425,"Shade of the Kaldorei - Action list - move to pos"),
(3458400,9,7,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text5"),
(3458400,9,8,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,10671.004883,1863.977295,1325.617676,4.771425,"Shade of the Kaldorei - Action list - Set orientation"),
(3458400,9,9,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text6"),
(3458400,9,10,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text7"),
(3458400,9,11,0,0,0,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Despawn"),
(-311413,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(-311413,0,1,0,10,0,100,0,1,10,119000,119000,11,65679,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - ooc los - Cast Summon Shade of the Kaldorei"),
(34585,0,0,0,54,0,100,0,0,0,0,0,80,3458500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - On just summoned - Action list"),
(3458500,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Set run off"),
(3458500,9,1,0,0,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Set Stand to sit"),
(3458500,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text0"),
(3458500,9,4,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text1"),
(3458500,9,5,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text2"),
(3458500,9,6,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text3"),
(3458500,9,7,0,0,0,100,0,9000,9000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text4"),
(3458500,9,8,0,0,0,100,0,2000,2000,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Remove Stand standup"),
(3458500,9,9,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,9559.289,1655.6696,1299.711792,2.685835,"Shade of the Kaldorei - Action list - move to pos"),
(3458500,9,10,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,9559.289,1655.6696,1299.711792,2.685835,"Shade of the Kaldorei - Action list - Set orientation"),
(3458500,9,11,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text5"),
(3458500,9,12,0,0,0,100,0,8000,8000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text6"),
(3458500,9,13,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text7"),
(3458500,9,14,0,0,0,100,0,7000,7000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Say text8"),
(3458500,9,15,0,0,0,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of the Kaldorei - Action list - Despawn"),
(-312359,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(-312365,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(-312388,0,0,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Set invisible"),
(1992,0,0,0,19,0,100,0,14005,0,0,0,80,199200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tarindrella - On quest Accepted - Action list"),
(199200,9,0,0,0,0,100,0,0,0,0,0,64,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tarindrella - Action list - Store target"),
(199200,9,1,0,0,0,100,0,0,0,0,0,11,66027,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tarindrella - Action list - Cast Forcecast Vengeance of Elune"),
(199200,9,2,0,0,0,100,0,0,0,0,0,100,0,0,0,0,0,0,11,34575,35,0,0,0,0,0,"Tarindrella - Action list - Send target"),
(199200,9,3,0,0,0,100,0,1000,1000,0,0,45,1,2,0,0,0,0,11,34575,35,0,0,0,0,0,"Tarindrella - Action list - Set Data"),
(-311408,0,0,0,25,0,100,0,0,0,0,0,3,0,27823,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Morph to model"),
(-311408,0,1,0,38,0,100,0,1,2,0,0,11,66163,0,0,0,0,0,12,0,0,0,0,0,0,0,"Moonwell Bunny - on data set - Cast Vengeance of Elune Water Visual"),
(-311409,0,0,0,25,0,100,0,0,0,0,0,3,0,27823,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Morph to model"),
(-311409,0,1,0,38,0,100,0,1,2,0,0,11,66163,0,0,0,0,0,12,0,0,0,0,0,0,0,"Moonwell Bunny - on data set - Cast Vengeance of Elune Water Visual"),
(-311414,0,0,0,25,0,100,0,0,0,0,0,3,0,27823,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Morph to model"),
(-311414,0,1,0,38,0,100,0,1,2,0,0,11,66163,0,0,0,0,0,12,0,0,0,0,0,0,0,"Moonwell Bunny - on data set - Cast Vengeance of Elune Water Visual"),
(-311415,0,0,0,25,0,100,0,0,0,0,0,3,0,27823,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Morph to model"),
(-311415,0,1,0,38,0,100,0,1,2,0,0,11,66163,0,0,0,0,0,12,0,0,0,0,0,0,0,"Moonwell Bunny - on data set - Cast Vengeance of Elune Water Visual"),
(-311416,0,0,0,25,0,100,0,0,0,0,0,3,0,27823,0,0,0,0,1,0,0,0,0,0,0,0,"Moonwell Bunny - On reset  - Morph to model"),
(-311416,0,1,0,38,0,100,0,1,2,0,0,11,66163,0,0,0,0,0,12,0,0,0,0,0,0,0,"Moonwell Bunny - on data set - Cast Vengeance of Elune Water Visual"),
(1992,0,1,0,20,0,100,0,14005,0,0,0,85,66166,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tarindrella - On quest Reward - Cast Cancel Vengeance of Elune");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2080) AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3569) AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (208002) AND `source_type`=9 AND `id`=12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2080,0,3,0,20,0,100,0,930,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Denalan - On Quest 'The Glowing Fruit' Finished - Set Run off"),
(3569,0,1,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,"Bogling - On Just summoned - Start Attack"),
(208002,9,12,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,9506.919922,713.765991,1255.969971,0.279253,"Denalan - On Script - Set orientation");
UPDATE `creature_text` SET `type`=16, `emote`=0 WHERE `Entry`=2080 AND `groupid` IN (2, 4, 6);
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000 WHERE `entryorguid`=208002 AND `source_Type`=9 AND `id`=6;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=3000 WHERE `entryorguid`=208002 AND `source_Type`=9 AND `id`=7;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=3000 WHERE `entryorguid`=208002 AND `source_Type`=9 AND `id`=8;
UPDATE `smart_scripts` SET `action_param1`=1, `target_type`=19, `target_param1`=3569, `target_param2`=15 WHERE `entryorguid`=208002 AND `source_Type`=9 AND `id`=9;
DELETE FROM `creature_text` WHERE `entry` IN (2080) AND `groupid`=7;
DELETE FROM `creature_text` WHERE `entry` IN (3569) AND `groupid`=1;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(3569,1,0,"%s rises from the soil!",16,0,100,0,0,0, 'Bogling', 1174);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (208001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(208001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Set Run off"),
(208001, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 49417, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Remove aura"),
(208001, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10120.128906, 1654.324219, 1324.174927, 0.045387, "Denalan - On Script - Move To Position"),
(208001, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 2"),
(208001, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Say Line 3"),
(208001, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Play Emote 16"),
(208001, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10116.900391, 1654.170044, 1324.709961, 5.550150, "Denalan - On Script - Move To Position"),
(208001, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 10116.900391, 1654.170044, 1324.709961, 5.550150, "Denalan - On Script - Set orientation"),
(208001, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 75, 49417, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Denalan - On Script - Add aura");

DELETE FROM `gameobject_addon` WHERE `guid` IN (219037, 219038, 219039);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES 
(219037,8,100), (219038,8,100), (219039,8,100);

DELETE FROM `spell_area` WHERE `spell` IN (49417) AND `area` IN (4718);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(49417, 4718, 931, 0, 0, 0, 2, 1, 64, 0);

UPDATE `creature_template_addon` SET `auras`=49415 WHERE `entry`=7411;
DELETE FROM `spell_area` WHERE `spell` IN (49417) AND `area` IN (264);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(49417, 264, 2518, 0, 0, 0, 2, 1, 64, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1,3,4) AND `SourceEntry` IN (2080);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (2) AND `SourceEntry` IN (-312853, -311234, 2080, -311413);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(22,2,-312853,0,9,929,0,0,0,'','event require quest 929 taken', 0, 0),
(22,2,-311234,0,9,7383,0,0,0,'','event require quest 7383 taken', 0, 0),
(22,2,-311413,0,9,933,0,0,0,'','event require quest 933 taken', 0, 0),
(22,2,2080,0,23,4718,0,0,0,'','event require area 4718', 0, 0),
(22,1,2080,0,23,259,0,0,0,'','event require area 259', 0, 0),
(22,3,2080,0,23,259,0,0,0,'','event require area 259', 0, 0),
(22,4,2080,0,23,259,0,0,0,'','event require area 259', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10564);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(15,10564,0,0,9,13945,0,0,0,'','Gossip option require quest 13945 taken', 0, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=65455 AND `ConditionValue2`=2005;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(13,1,65455,3,31,3,2005,0,0,'','Nature''s Fury can hit only Vicious Grell', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup` IN (1,2,4) AND `SourceEntry`=5628;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(13,1,5628,0,31,3,2011,0,0,'','Gnarlpine Vengeance affect only Gnarlpine Augur', 0, 0),
(13,2,5628,0,31,3,2011,0,0,'','Gnarlpine Vengeance affect only Gnarlpine Augur', 0, 0),
(13,4,5628,0,31,3,2011,0,0,'','Gnarlpine Vengeance affect only Gnarlpine Augur', 0, 0);

DELETE FROM `waypoints` WHERE `entry`=34760;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(34760,1,9835.322, 964.0228, 1308.692,"Sentinel Nightsaber"),
(34760,2,9850.457, 976.3512, 1305.240,"Sentinel Nightsaber"),
(34760,3,9846.52, 990.3774, 1305.366,"Sentinel Nightsaber"),
(34760,4,9849.604, 1051.058, 1305.339,"Sentinel Nightsaber"),
(34760,5,9882.152, 1097.784, 1307.991,"Sentinel Nightsaber"),
(34760,6,9884.829, 1115.149, 1307.856,"Sentinel Nightsaber"),
(34760,7,9913.489, 1140.864, 1307.951,"Sentinel Nightsaber"),
(34760,8,9917.555, 1181.575, 1308.018,"Sentinel Nightsaber"),
(34760,9,9907.700, 1197.454, 1308.697,"Sentinel Nightsaber"),
(34760,10,9913.514, 1221.290, 1307.830,"Sentinel Nightsaber"),
(34760,11,9928.159, 1241.625, 1307.881,"Sentinel Nightsaber"),
(34760,12,9944.103, 1253.263, 1305.962,"Sentinel Nightsaber"),
(34760,13,9946.414, 1271.075, 1298.205,"Sentinel Nightsaber"),
(34760,14,9948.055, 1309.540, 1294.922,"Sentinel Nightsaber"),
(34760,15,9954.332, 1341.850, 1293.871,"Sentinel Nightsaber"),
(34760,16,9962.835, 1391.428, 1291.576,"Sentinel Nightsaber"),
(34760,17,9985.163, 1447.862, 1290.367,"Sentinel Nightsaber"),
(34760,18,9964.450, 1534.254, 1309.515,"Sentinel Nightsaber"),
(34760,19,9873.501, 1551.539, 1328.753,"Sentinel Nightsaber");

DELETE FROM `creature_text` WHERE `entry` IN (34586, 34583, 2081, 34249, 34584, 34585);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(34586,0,0,"%s smiles at you knowingly as it approaches.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34835),
(34586,1,0,"With Malfurion Stormrage gone, the druids were left in disarray and in desperate need of a new leader.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34797),
(34586,2,0,"Arch Druid Fandral Staghelm roused the druids and convinced the Circle of Ancients in Darkshore that it was time for our people to rebuild.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34798),
(34586,3,0,"In an effort to regain immortality for our people, and with the approval of the Circle, Staghelm and the most powerful druids grew Teldrassil, upon whose boughs you now stand.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34799),
(34586,4,0,"Though we have our new home, our immortal lives have not been restored.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34800),
(34586,5,0,"The Shade of the Kaldorei closes its eyes and fades away.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34820),
(34583,0,0,"%s stares into the moonwell, lost in distant memories.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34819),
(34583,1,0,"The Arch Druid approached the dragons for their blessings, as the dragons had placed on Nordrassil in ancient times.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34801),
(34583,2,0,"But Nozdormu, Lord of Time, refused to give his blessing, chiding the druid for his arrogance.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34802),
(34583,3,0,"In agreement, Alexstrasza also refused Staghelm, and without her blessing, Teldrassil's growth has been flawed and unpredictable.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34803),
(34583,4,0,"Staghelm retreated to his enclave in Darnassus, ever seeking a new direction by which to bless Teldrassil, and restore the immortality of our people.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34804),
(34583,5,0,"The Shade of the Kaldorei closes its eyes and fades away.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34820),
(2081,0,0,"Some of our huntresses have already made their way to Ban'ethil Barrow Den. They will find you when you get inside. Go ahead and speak to Citarre to secure a ride there.",12,0,100,0,0,0, 'Sentinel Kyra Starsong', 34694),
(34249,0,0,"You're finally here. Take the scenic route?",12,0,100,0,0,0, 'Sentinel Huntress', 34985),
(34249,1,0,"The exit is to the northwest... the mist will lead the way.",15,0,100,0,0,0, 'Sentinel Huntress',34669),
(34249,2,0,"The mist will lead the way.",15,0,100,0,0,0, 'Sentinel Huntress',34668),
(34249,3,0,"The Rune of Nesting is located across the bridge in the upper section of the southern chamber.",15,0,100,0,0,0, 'Sentinel Huntress',34650),
(34249,4,0,"The Sapphire of Sky is located at the separate room in the lower section of the northern chamber.",15,0,100,0,0,0, 'Sentinel Huntress',34651),
(34249,5,0,"The Black Feather Quill is located down the ramp in the lower section of the southern chamber.",15,0,100,0,0,0, 'Sentinel Huntress',34652),
(34249,6,0,"The Raven Claw Talisman is located on the ledge in the upper section of the northern chamber.",15,0,100,0,0,0, 'Sentinel Huntress',34653),
(34249,7,0,"Oben Rageclaw resides at the double bridges in the western chamber, near the hallway that leads out of the Barrow Den.",15,0,100,0,0,0, 'Sentinel Huntress',34654),
(34584,0,0,"%s approaches the moonwell slowly, a familiar, thoughtful look upon its face.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34834),
(34584,1,0,"Over time, Staghelm only grew more disconnected from our people.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34805),
(34584,2,0,"Some pose that he blames us, his people, for the loss of his son, long ago during the War of the Shifting Sands.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34806),
(34584,3,0,"Others cite rumors of his escalating conflicts with Tyrande Whisperwind, the shining light of our people, our leader in Darnassus.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34807),
(34584,4,0,"But many druids of the Cenarion Circle stand firm that he wants only what is best for all of the Kaldorei, and serve him unerringly towards that end.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34808),
(34584,5,0,"Fandral Staghelm carries the burden of our sins and our follies, and in so doing deserves the respect of us all.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34809),
(34584,6,0,"The Shade of the Kaldorei closes its eyes and fades away.",16,0,100,66,0,0, 'Shade of the Kaldorei', 34820),
(34585,0,0,"%s rests on the side of the moonwell in peaceful contemplation.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34833),
(34585,1,0,"In weeks past, all of those living atop Teldrassil have found their memories blurry, as if time itself seized a portion of their lives.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34810),
(34585,2,0,"We break from this haze to find that Fandral Staghelm and many of his closest followers have disappeared without a word.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34811),
(34585,3,0,"But in his place, Shan'do Stormrage awoke from the dream and returned to his beloved Tyrande Whisperwind.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34812),
(34585,4,0,"And with his return came Alexstrasza and Ysera, to at long last offer their blessings upon Teldrassil",12,0,100,1,0,0, 'Shade of the Kaldorei', 34813),
(34585,5,0,"Though a small corruption lingers, desperately longing to be cleansed, the boughs of Teldrassil itself seem changed. Growth has begun anew.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34814),
(34585,6,0,"None know what to expect next, but with Malfurion and Tyrande reunited, a new hope dawns on the Kaldorei.",12,0,100,1,0,0, 'Shade of the Kaldorei', 34815),
(34585,7,0,"Hope for lasting relief from the shadow that has been cast on our people for so long.",12,0,100,1,0,0, 'Shade of the Kaldorei', 44123),
(34585,8,0,"The Shade of the Kaldorei closes its eyes and fades away.",16,0,100,0,0,0, 'Shade of the Kaldorei', 34820);

DELETE FROM `waypoint_data` WHERE `id` IN (3127480, 3127340, 3126710, 3122380, 3121110, 3116710, 3116510, 3120600, 3116130, 8440, 3119910, 3119700, 3119950, 3117590, 3117690, 8490, 8470, 8480, 8500, 8540, 3121150, 3120140, 3119880, 3119160, 3120090, 3119260, 3117920); 
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(3127480, 1, 9767.04, 931.276, 1301.29,0,0,0,0,100,0),
(3127480, 2, 9768.41, 940.088, 1304.78,0,0,0,0,100,0),
(3127480, 3, 9774.92, 947.13 , 1306.67,0,0,0,0,100,0),
(3127480, 4, 9785.26, 949.66 , 1308.77,0,0,0,0,100,0),
(3127480, 5, 9796.48, 951.802, 1308.8,0,0,0,0,100,0),
(3127480, 6, 9818.75, 958.055, 1308.79,0,0,0,0,100,0),
(3127480, 7, 9835.03, 964.474, 1308.71,0,0,0,0,100,0),
(3127480, 8, 9817.31, 957.435, 1308.79,0,0,0,0,100,0),
(3127480, 9, 9796.98, 952.453, 1308.79,0,0,0,0,100,0), 
(3127480, 10, 9784.36, 949.532, 1308.67,0,0,0,0,100,0),
(3127480, 11, 9770.59, 944.071, 1306.12,0,0,0,0,100,0),
(3127480, 12, 9767.69, 938.043, 1303.98,0,0,0,0,100,0),
(3127480, 13, 9767.08, 926.653, 1299.71,0,0,0,0,100,0),
(3127340, 1, 9850.219, 1051.86, 1305.417,0,0,0,0,100,0),
(3127340, 2, 9845.459, 1011.14, 1305.560,0,0,0,0,100,0),
(3127340, 3, 9850.496, 969.813, 1305.870,0,0,0,0,100,0),
(3127340, 4, 9878.447, 932.986, 1307.358,0,0,0,0,100,0),
(3127340, 5, 9886.167, 917.438, 1307.434,0,0,0,0,100,0),
(3127340, 6, 9865.355, 906.483, 1306.299,0,0,0,0,100,0),
(3127340, 7, 9828.242, 911.325, 1303.836,0,0,0,0,100,0),
(3127340, 8, 9775.522, 904.579, 1297.314,0,0,0,0,100,0),
(3127340, 9, 9828.242, 911.325, 1303.836,0,0,0,0,100,0),
(3127340, 10,9865.355, 906.483, 1306.299,0,0,0,0,100,0),
(3127340, 11,9886.167, 917.438, 1307.434,0,0,0,0,100,0),
(3127340, 12,9878.447, 932.986, 1307.358,0,0,0,0,100,0),
(3127340, 13,9850.496, 969.813, 1305.870,0,0,0,0,100,0),
(3127340, 14,9845.459, 1011.14, 1305.560,0,0,0,0,100,0),
(3127340, 15,9850.219, 1051.86, 1305.417,0,0,0,0,100,0),
(3126710,1,9816.841797,355.442474,1308.459351,0,0,0,0,100,0),
(3126710,2,9812.415039,362.828094,1308.752197,0,0,0,0,100,0),
(3126710,3,9813.471680,371.201080,1307.603882,0,0,0,0,100,0),
(3126710,4,9817.410156,378.589417,1307.885742,0,0,0,0,100,0),
(3126710,5,9825.732422,384.063232,1307.750610,0,0,0,0,100,0),
(3126710,6,9834.477539,389.443268,1307.568115,0,0,0,0,100,0),
(3126710,7,9841.236328,395.250305,1307.572998,0,0,0,0,100,0),
(3126710,8,9848.033203,401.213165,1306.638672,0,0,0,0,100,0),
(3126710,9,9859.214844,406.416229,1305.993896,0,0,0,0,100,0),
(3126710,10,9869.071289,406.038055,1306.539917,0,0,0,0,100,0),
(3126710,11,9878.757813,405.102966,1307.240845,0,0,0,0,100,0),
(3126710,12,9885.528320,403.787720,1307.657715,0,0,0,0,100,0),
(3126710,13,9889.619141,397.835724,1308.962280,0,0,0,0,100,0),
(3126710,14,9893.748047,390.061859,1309.997925,0,0,0,0,100,0),
(3126710,15,9896.480469,384.763855,1309.682861,0,0,0,0,100,0),
(3126710,16,9893.901367,389.335175,1309.996948,0,0,0,0,100,0),
(3126710,17,9891.625977,394.618530,1309.802979,0,0,0,0,100,0),
(3126710,18,9889.411133,401.266754,1308.383423,0,0,0,0,100,0),
(3126710,19,9889.074219,410.169098,1306.578735,0,0,0,0,100,0),
(3126710,20,9889.352539,418.270325,1305.849609,0,0,0,0,100,0),
(3126710,21,9889.537109,426.961700,1305.150146,0,0,0,0,100,0),
(3126710,22,9886.551758,436.957245,1304.242920,0,0,0,0,100,0),
(3126710,23,9880.396484,443.821472,1303.310303,0,0,0,0,100,0),
(3126710,24,9870.833008,446.340790,1303.197144,0,0,0,0,100,0),
(3126710,25,9862.344727,445.663116,1305.028198,0,0,0,0,100,0),
(3126710,26,9853.178711,443.624847,1306.194458,0,0,0,0,100,0),
(3126710,27,9846.104492,441.481476,1307.793701,0,0,0,0,100,0),
(3126710,28,9837.686523,438.918671,1307.793701,0,0,0,0,100,0),
(3126710,29,9844.111328,440.791779,1307.793701,0,0,0,0,100,0),
(3126710,30,9851.247070,442.721130,1306.898926,0,0,0,0,100,0),
(3126710,31,9859.722656,444.624786,1305.261841,0,0,0,0,100,0),
(3126710,32,9868.759766,446.034027,1303.592163,0,0,0,0,100,0),
(3126710,33,9876.381836,446.370392,1302.643555,0,0,0,0,100,0),
(3126710,34,9882.995117,443.218323,1303.420654,0,0,0,0,100,0),
(3126710,35,9886.392578,436.599731,1304.326904,0,0,0,0,100,0),
(3126710,36,9888.699219,427.984589,1305.102173,0,0,0,0,100,0),
(3126710,37,9888.677734,420.184723,1305.806763,0,0,0,0,100,0),
(3126710,38,9886.924805,411.696075,1306.650635,0,0,0,0,100,0),
(3126710,39,9881.045898,406.513794,1307.236572,0,0,0,0,100,0),
(3126710,40,9872.117188,405.889221,1306.774536,0,0,0,0,100,0),
(3126710,41,9863.948242,407.544800,1306.226685,0,0,0,0,100,0),
(3126710,42,9857.266602,406.285339,1306.106934,0,0,0,0,100,0),
(3126710,43,9850.121094,401.789185,1306.542236,0,0,0,0,100,0),
(3126710,44,9843.356445,396.552856,1307.546021,0,0,0,0,100,0),
(3126710,45,9836.401367,390.980865,1307.567749,0,0,0,0,100,0),
(3126710,46,9828.750977,386.198456,1307.593384,0,0,0,0,100,0),
(3126710,47,9820.420898,380.808014,1307.936279,0,0,0,0,100,0),
(3126710,48,9814.184570,374.616272,1307.687866,0,0,0,0,100,0),
(3126710,49,9812.975586,367.559235,1307.733276,0,0,0,0,100,0),
(3126710,50,9812.920898,362.307007,1308.749512,0,0,0,0,100,0),
(3122380, 1, 10109.917969, 1730.282349, 1332.491699,0,0,0,0,100,0),
(3122380, 2, 10087.831055, 1668.881226, 1325.284912,0,0,0,0,100,0),
(3122380, 3, 10109.917969, 1730.282349, 1332.491699,0,0,0,0,100,0),
(3122380, 4, 10109.000000, 1765.560059, 1335.209961,0,0,0,0,100,0),
(3122380, 5, 10078.985352, 1802.986206, 1327.596558,0,0,0,0,100,0),
(3122380, 6, 10030.204102, 1821.405762, 1319.677612,0,0,0,0,100,0),
(3122380, 7, 9983.161133, 1870.316284, 1318.548584,0,0,0,0,100,0),
(3122380, 8, 9984.972656, 1963.705933, 1326.194580,0,0,0,0,100,0),
(3122380, 9, 9983.161133 , 1870.316284, 1318.548584,0,0,0,0,100,0),
(3122380, 10, 10030.204102, 1821.405762, 1319.677612,0,0,0,0,100,0),
(3122380, 11, 10078.985352, 1802.986206, 1327.596558,0,0,0,0,100,0),
(3122380, 12, 10109.000000, 1765.560059, 1335.209961,0,0,0,0,100,0),
(3122380, 13, 10109.917969, 1730.282349, 1332.491699,0,0,0,0,100,0),
(3122380, 14, 10087.831055, 1668.881226, 1325.284912,0,0,0,0,100,0),
(3122380, 15, 10109.917969, 1730.282349, 1332.491699,0,0,0,0,100,0),
(3121110, 1, 9658.96, 2432.3, 1335.68, 0, 0, 0, 0, 100, 0),
(3121110, 2, 9679.9, 2455.32, 1335.68, 0, 0, 0, 0, 100, 0),
(3121110, 3, 9708.29, 2490.8, 1335.68, 0, 0, 0, 0, 100, 0),
(3121110, 4, 9717.46, 2518.7, 1335.68, 0, 0, 0, 0, 100, 0),
(3121110, 5, 9727.39, 2524.16, 1335.56, 0, 0, 0, 0, 100, 0),
(3121110, 6, 9771.39, 2526.82, 1319.75, 0, 0, 0, 0, 100, 0),
(3121110, 7, 9816.15, 2527.66, 1320.84, 0, 0, 0, 0, 100, 0),
(3121110, 8, 9845.84, 2528.83, 1321.53, 0, 0, 0, 0, 100, 0),
(3121110, 9, 9886.09, 2530.36, 1318.77, 0, 0, 0, 0, 100, 0),
(3121110, 10, 9899.04, 2530.86, 1315.27, 0, 0, 0, 0, 100, 0),
(3121110, 11, 9906.06, 2531.28, 1316.13, 0, 0, 0, 0, 100, 0),
(3121110, 12, 9919.57, 2544.89, 1317.09, 0, 0, 0, 0, 100, 0),
(3121110, 13, 9931.79, 2551.53, 1317.37, 0, 0, 0, 0, 100, 0),
(3121110, 14, 9943.84, 2553.68, 1316.49, 0, 0, 0, 0, 100, 0),
(3121110, 15, 9960.02, 2547.37, 1316.85, 0, 0, 0, 0, 100, 0),
(3121110, 16, 9975.21, 2536.21, 1316.45, 0, 0, 0, 0, 100, 0),
(3121110, 17, 9984.03, 2523.6, 1316.34, 0, 0, 0, 0, 100, 0),
(3121110, 18, 9998.81, 2513.33, 1315.15, 0, 0, 0, 0, 100, 0),
(3121110, 19, 10005.7, 2510.75, 1317.43, 0, 0, 0, 0, 100, 0),
(3121110, 20, 10013.2, 2507.64, 1319, 0, 0, 0, 0, 100, 0),
(3121110, 21, 10032.8, 2499.24, 1318.43, 0, 0, 0, 0, 100, 0), 
(3121110, 22, 10051.7, 2508.99, 1318.38, 0, 0, 0, 0, 100, 0),
(3121110, 23, 10067.8, 2517.56, 1319.89, 0, 0, 0, 0, 100, 0),
(3121110, 24, 10082.1, 2525.78, 1317.37, 0, 0, 0, 0, 100, 0),
(3121110, 25, 10094.5, 2534.33, 1318.57, 0, 0, 0, 0, 100, 0),
(3121110, 26, 10108.9, 2539.55, 1320.47, 0, 0, 0, 0, 100, 0),
(3121110, 27, 10127.8, 2544.79, 1321.77, 0, 0, 0, 0, 100, 0),
(3121110, 28, 10140.4, 2549.95, 1321.73, 0, 0, 0, 0, 100, 0),
(3121110, 29, 10142.1, 2557.33, 1321.81, 0, 0, 0, 0, 100, 0),
(3121110, 30, 10136.5, 2568.59, 1322.36, 0, 0, 0, 0, 100, 0),
(3121110, 31, 10125.1, 2583.15, 1326.23, 0, 0, 0, 0, 100, 0),
(3121110, 32, 10141.3, 2561.26, 1321.86, 0, 0, 0, 0, 100, 0),
(3121110, 33, 10139, 2549.19, 1321.74, 0, 0, 0, 0, 100, 0),
(3121110, 34, 10119.6, 2541.21, 1321.52, 0, 0, 0, 0, 100, 0),
(3121110, 35, 10096.8, 2537.22, 1319.03, 0, 0, 0, 0, 100, 0),
(3121110, 36, 10082.8, 2527.48, 1317.46, 0, 0, 0, 0, 100, 0),
(3121110, 37, 10068.3, 2518.29, 1319.86, 0, 0, 0, 0, 100, 0),
(3121110, 38, 10047.9, 2503.52, 1318.4, 0, 0, 0, 0, 100, 0),
(3121110, 39, 10028.6, 2498.52, 1318.42, 0, 0, 0, 0, 100, 0),
(3121110, 40, 10012.8, 2505.91, 1318.97, 0, 0, 0, 0, 100, 0),
(3121110, 41, 9998.73, 2512.19, 1315.14, 0, 0, 0, 0, 100, 0),
(3121110, 42, 9983.9, 2518.29, 1316.69, 0, 0, 0, 0, 100, 0),
(3121110, 43, 9974.22, 2514.3, 1317.38, 0, 0, 0, 0, 100, 0),
(3121110, 44, 9963.2, 2498.5, 1316.68, 0, 0, 0, 0, 100, 0),
(3121110, 45, 9952.92, 2486.57, 1316.34, 0, 0, 0, 0, 100, 0),
(3121110, 46, 9948.21, 2475.4, 1316.04, 0, 0, 0, 0, 100, 0),
(3121110, 47, 9949.17, 2439.02, 1324.01, 0, 0, 0, 0, 100, 0),
(3121110, 48, 9949.58, 2406.16, 1328.17, 0, 0, 0, 0, 100, 0),
(3121110, 49, 9950.11, 2373.62, 1330.02, 0, 0, 0, 0, 100, 0),
(3121110, 50, 9950.97, 2340.03, 1330.78, 0, 0, 0, 0, 100, 0),
(3121110, 51, 9951.17, 2319.11, 1336.55, 0, 0, 0, 0, 100, 0),
(3121110, 52, 9952.56, 2303.43, 1336.55, 0, 0, 0, 0, 100, 0),
(3121110, 53, 9952.21, 2291.59, 1341.39, 0, 0, 0, 0, 100, 0),
(3121110, 54, 9952.16, 2281.78, 1341.39, 0, 0, 0, 0, 100, 0),
(3121110, 55, 9937.95, 2280.07, 1341.39, 0, 0, 0, 0, 100, 0),
(3121110, 56, 9894.94, 2281.3, 1341.39, 0, 0, 0, 0, 100, 0),
(3121110, 57, 9870.11, 2280.41, 1328.62, 0, 0, 0, 0, 100, 0),
(3121110, 58, 9851.93, 2279.51, 1326.36, 0, 0, 0, 0, 100, 0),
(3121110, 59, 9849.11, 2255.54, 1327.53, 0, 0, 0, 0, 100, 0),
(3121110, 60, 9839.85, 2231, 1327.65, 0, 0, 0, 0, 100, 0),
(3121110, 61, 9832.5, 2220.38, 1327.77, 0, 0, 0, 0, 100, 0),
(3121110, 62, 9811.69, 2217.56, 1327.64, 0, 0, 0, 0, 100, 0),
(3121110, 63, 9793.25, 2225.16, 1327.65, 0, 0, 0, 0, 100, 0),
(3121110, 64, 9775.66, 2237.8, 1327.64, 0, 0, 0, 0, 100, 0),
(3121110, 65, 9753.25, 2249.31, 1327.59, 0, 0, 0, 0, 100, 0),
(3121110, 66, 9722.65, 2262.31, 1327.49, 0, 0, 0, 0, 100, 0),
(3121110, 67, 9705.75, 2276.46, 1327.57, 0, 0, 0, 0, 100, 0),
(3121110, 68, 9694.09, 2289.5, 1327.49, 0, 0, 0, 0, 100, 0),
(3121110, 69, 9675.89, 2312.57, 1327.53, 0, 0, 0, 0, 100, 0),
(3121110, 70, 9658.56, 2328.83, 1327.49, 0, 0, 0, 0, 100, 0),
(3121110, 71, 9659.79, 2337.78, 1327.49, 0, 0, 0, 0, 100, 0),
(3121110, 72, 9672.12, 2346.31, 1327.54, 0, 0, 0, 0, 100, 0),
(3121110, 73, 9685.13, 2353.61, 1327.88, 0, 0, 0, 0, 100, 0),
(3121110, 74, 9708.49, 2355.19, 1327.52, 0, 0, 0, 0, 100, 0),
(3121110, 75, 9715.95, 2359.62, 1327.38, 0, 0, 0, 0, 100, 0),
(3121110, 76, 9706.47, 2379.02, 1326.95, 0, 0, 0, 0, 100, 0),
(3121110, 77, 9701.32, 2404.41, 1326.87, 0, 0, 0, 0, 100, 0),
(3121110, 78, 9691.62, 2408.08, 1326.96, 0, 0, 0, 0, 100, 0),
(3121110, 79, 9684.3, 2408.23, 1332.73, 0, 0, 0, 0, 100, 0),
(3121110, 80, 9668.91, 2409.1, 1335.68, 0, 0, 0, 0, 100, 0),
(3121110, 81, 9661.99, 2422.47, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 1, 9776.55, 2531.54, 1318.93, 0, 0, 0, 0, 100, 0),
(3116710, 2, 9769.36, 2531.15, 1320.44, 0, 0, 0, 0, 100, 0),
(3116710, 3, 9767.59, 2531.53, 1321.08, 0, 0, 0, 0, 100, 0),
(3116710, 4, 9764.53, 2532.3, 1322.15, 0, 0, 0, 0, 100, 0),
(3116710, 5, 9736.58, 2537.27, 1332.01, 0, 0, 0, 0, 100, 0),
(3116710, 6, 9726.99, 2538.13, 1335.38, 0, 0, 0, 0, 100, 0),
(3116710, 7, 9723.63, 2540.35, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 8, 9721.65, 2542.9, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 9, 9710.68, 2562.7, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 10, 9691.4, 2586.07, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 11, 9666.76, 2605.76, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 12, 9663.6, 2607.97, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 13, 9661.93, 2610.4, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 14, 9661.1, 2613.19, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 15, 9659.82, 2627.53, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 16, 9658.55, 2628.94, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 17, 9657.16, 2629.32, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 18, 9654.96, 2629.39, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 19, 9653.19, 2628.38, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 20, 9652.2, 2626.19, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 21, 9652.27, 2623.64, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 22, 9653.91, 2602.25, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 23, 9654.32, 2600.85, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 24, 9655.22, 2599.56, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 25, 9656.18, 2598.45, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 26, 9657.87, 2597.43, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 27, 9661.17, 2596.11, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 28, 9663.25, 2594.92, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 29, 9665.19, 2593.21, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 30, 9683.42, 2575.19, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 31, 9702.05, 2556.37, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 32, 9711.03, 2542.86, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 33, 9712.06, 2513.48, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 34, 9709.97, 2499.3, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 35, 9686.86, 2471.14, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 36, 9661.4, 2446.29, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 37, 9659.7, 2443.97, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 38, 9658.9, 2441.08, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 39, 9658.38, 2437.55, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 40, 9654.82, 2413.7, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 41, 9654.82, 2413.7, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 42, 9655.17, 2410.48, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 43, 9656.12, 2408.8, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 44, 9657.85, 2407.21, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 45, 9660.05, 2406.62, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 46, 9662.48, 2407.19, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 47, 9664.22, 2408.92, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 48, 9665.18, 2411.42, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 49, 9665.36, 2414.14, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 50, 9664.27, 2432.98, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 51, 9664.56, 2434.64, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 52, 9665.23, 2435.96, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 53, 9667.42, 2437.88, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 54, 9695.22, 2463.22, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 55, 9713.3, 2489.69, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 56, 9719.5, 2512.31, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 57, 9720.29, 2513.85, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 58, 9721.17, 2514.99, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 59, 9722.42, 2515.67, 1335.68, 0, 0, 0, 0, 100, 0),
(3116710, 60, 9729.86, 2518.51, 1334.58, 0, 0, 0, 0, 100, 0),
(3116710, 61, 9735.13, 2520.27, 1332.72, 0, 0, 0, 0, 100, 0),
(3116710, 62, 9736.73, 2520.53, 1332.16, 0, 0, 0, 0, 100, 0),
(3116710, 63, 9766.79, 2522.69, 1321.44, 0, 0, 0, 0, 100, 0),
(3116710, 64, 9776.27, 2523.3, 1318.9, 0, 0, 0, 0, 100, 0),
(3116710, 65, 9807.24, 2524.39, 1320.62, 0, 0, 0, 0, 100, 0),
(3116710, 66, 9827.92, 2524.93, 1321.12, 0, 0, 0, 0, 100, 0),
(3116710, 67, 9852.38, 2525.86, 1321.08, 0, 0, 0, 0, 100, 0),
(3116710, 68, 9878.07, 2526.71, 1319.32, 0, 0, 0, 0, 100, 0),
(3116710, 69, 9894.91, 2529.19, 1316.53, 0, 0, 0, 0, 100, 0),
(3116710, 70, 9909.73, 2533.67, 1316.38, 0, 0, 0, 0, 100, 0),
(3116710, 71, 9910.85, 2535.16, 1316.38, 0, 0, 0, 0, 100, 0),
(3116710, 72, 9911.65, 2537.52, 1316.5, 0, 0, 0, 0, 100, 0),
(3116710, 73, 9913.32, 2539.02, 1316.63, 0, 0, 0, 0, 100, 0),
(3116710, 74, 9922.6, 2545.77, 1317.13, 0, 0, 0, 0, 100, 0),
(3116710, 75, 9939.89, 2553.77, 1316.82, 0, 0, 0, 0, 100, 0),
(3116710, 76, 9944.88, 2555.72, 1316.44, 0, 0, 0, 0, 100, 0),
(3116710, 77, 9946.14, 2555.79, 1316.32, 0, 0, 0, 0, 100, 0),
(3116710, 78, 9947.52, 2555.26, 1316.32, 0, 0, 0, 0, 100, 0),
(3116710, 79, 9970.48, 2541.57, 1316.75, 0, 0, 0, 0, 100, 0),
(3116710, 80, 9982.52, 2526.08, 1316.37, 0, 0, 0, 0, 100, 0),
(3116710, 81, 9983.06, 2524.38, 1316.5, 0, 0, 0, 0, 100, 0),
(3116710, 82, 9982.89, 2522.09, 1316.5, 0, 0, 0, 0, 100, 0),
(3116710, 83, 9981.35, 2520.54, 1316.75, 0, 0, 0, 0, 100, 0),
(3116710, 84, 9978.96, 2519.39, 1317.12, 0, 0, 0, 0, 100, 0),
(3116710, 85, 9968.58, 2510.83, 1317.75, 0, 0, 0, 0, 100, 0),
(3116710, 86, 9967.57, 2509.13, 1317.62, 0, 0, 0, 0, 100, 0),
(3116710, 87, 9966.94, 2506.63, 1317.37, 0, 0, 0, 0, 100, 0),
(3116710, 88, 9964.4, 2498.46, 1316.62, 0, 0, 0, 0, 100, 0),
(3116710, 89, 9963.43, 2496.6, 1316.49, 0, 0, 0, 0, 100, 0),
(3116710, 90, 9961.62, 2494.32, 1316.49, 0, 0, 0, 0, 100, 0),
(3116710, 91, 9949.46, 2481.62, 1316.24, 0, 0, 0, 0, 100, 0),
(3116710, 92, 9949.16, 2480.26, 1316.24, 0, 0, 0, 0, 100, 0),
(3116710, 93, 9949.14, 2478.52, 1316.24, 0, 0, 0, 0, 100, 0),
(3116710, 94, 9949.9, 2444.03, 1323.02, 0, 0, 0, 0, 100, 0),
(3116710, 95, 9950.92, 2406.31, 1328.17, 0, 0, 0, 0, 100, 0),
(3116710, 96, 9950.92, 2406.31, 1328.17, 0, 0, 0, 0, 100, 0),
(3116710, 97, 9951.81, 2372.26, 1330.06, 0, 0, 0, 0, 100, 0),
(3116710, 98, 9952.05, 2347.56, 1330.74, 0, 0, 0, 0, 100, 0),
(3116710, 99, 9953.08, 2310.86, 1336.55, 0, 0, 0, 0, 100, 0),
(3116710, 100, 9953.78, 2289.47, 1341.39, 0, 0, 0, 0, 100, 0),
(3116710, 101, 9953.67, 2270.07, 1340.67, 0, 0, 0, 0, 100, 0),
(3116710, 102, 9955.03, 2250.6, 1335.07, 0, 0, 0, 0, 100, 0),
(3116710, 103, 9954.9, 2229.24, 1331.83, 0, 0, 0, 0, 100, 0),
(3116710, 104, 9955.75, 2200.32, 1328.33, 0, 0, 0, 0, 100, 0),
(3116710, 105, 9955.95, 2176.62, 1327.58, 0, 0, 0, 0, 100, 0),
(3116710, 106, 9955.34, 2148.66, 1327.83, 0, 0, 0, 0, 100, 0),
(3116710, 107, 9953.31, 2119.95, 1327.77, 0, 0, 0, 0, 100, 0),
(3116710, 108, 9957.02, 2095.75, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 109, 9952.51, 2076.1, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 110, 9952.51, 2073.93, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 111, 9953.16, 2071.67, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 112, 9954.76, 2069.54, 1327.93, 0, 0, 0, 0, 100, 0),
(3116710, 113, 9973.54, 2042.18, 1328.14, 0, 0, 0, 0, 100, 0),
(3116710, 114, 9974, 2040.55, 1328.14, 0, 0, 0, 0, 100, 0),
(3116710, 115, 9973.74, 2039.33, 1328.14, 0, 0, 0, 0, 100, 0),
(3116710, 116, 9972.79, 2038.65, 1328.14, 0, 0, 0, 0, 100, 0),
(3116710, 117, 9971.4, 2038.56, 1328.14, 0, 0, 0, 0, 100, 0),
(3116710, 118, 9969.6, 2038.98, 1328.14, 0, 0, 0, 0, 100, 0),
(3116710, 119, 9967.37, 2040.95, 1328.26, 0, 0, 0, 0, 100, 0),
(3116710, 120, 9957.31, 2052.81, 1328.37, 0, 0, 0, 0, 100, 0),
(3116710, 121, 9955.88, 2055, 1328.37, 0, 0, 0, 0, 100, 0),
(3116710, 122, 9954.63, 2057.55, 1328.24, 0, 0, 0, 0, 100, 0),
(3116710, 123, 9946.69, 2073.5, 1327.93, 0, 0, 0, 0, 100, 0),
(3116710, 124, 9946.26, 2075.42, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 125, 9946.45, 2077.42, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 126, 9951.13, 2094.52, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 127, 9951.55, 2096.97, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 128, 9951.2, 2099.71, 1327.8, 0, 0, 0, 0, 100, 0),
(3116710, 129, 9950.03, 2136.16, 1327.7, 0, 0, 0, 0, 100, 0),
(3116710, 130, 9949.29, 2181.96, 1327.58, 0, 0, 0, 0, 100, 0),
(3116710, 131, 9948.41, 2224.65, 1330.95, 0, 0, 0, 0, 100, 0),
(3116710, 132, 9948.41, 2224.65, 1330.95, 0, 0, 0, 0, 100, 0),
(3116710, 133, 9949.03, 2253.35, 1335.44, 0, 0, 0, 0, 100, 0),
(3116710, 134, 9950.26, 2270.03, 1340.69, 0, 0, 0, 0, 100, 0),
(3116710, 135, 9949.62, 2288.9, 1341.39, 0, 0, 0, 0, 100, 0),
(3116710, 136, 9948.97, 2311.09, 1336.55, 0, 0, 0, 0, 100, 0),
(3116710, 137, 9947.62, 2346.41, 1330.76, 0, 0, 0, 0, 100, 0),
(3116710, 138, 9947.48, 2372.31, 1330.04, 0, 0, 0, 0, 100, 0),
(3116710, 139, 9947.57, 2406.61, 1328.11, 0, 0, 0, 0, 100, 0),
(3116710, 140, 9946.79, 2444.89, 1322.83, 0, 0, 0, 0, 100, 0),
(3116710, 141, 9947.04, 2473.77, 1316.55, 0, 0, 0, 0, 100, 0),
(3116710, 142, 9946.34, 2481.54, 1316.24, 0, 0, 0, 0, 100, 0),
(3116710, 143, 9945.25, 2483.19, 1316.24, 0, 0, 0, 0, 100, 0),
(3116710, 144, 9943.71, 2484.51, 1316.49, 0, 0, 0, 0, 100, 0),
(3116710, 145, 9941.13, 2486.06, 1316.74, 0, 0, 0, 0, 100, 0),
(3116710, 146, 9933.91, 2491.38, 1317.74, 0, 0, 0, 0, 100, 0),
(3116710, 147, 9933.32, 2492.54, 1317.9, 0, 0, 0, 0, 100, 0),
(3116710, 148, 9933.14, 2494.48, 1317.9, 0, 0, 0, 0, 100, 0),
(3116710, 149, 9933.66, 2496.92, 1317.87, 0, 0, 0, 0, 100, 0),
(3116710, 150, 9936.65, 2504.63, 1317.88, 0, 0, 0, 0, 100, 0),
(3116710, 151, 9937.35, 2506.57, 1317.88, 0, 0, 0, 0, 100, 0),
(3116710, 152, 9936.72, 2507.74, 1317.88, 0, 0, 0, 0, 100, 0),
(3116710, 153, 9935.66, 2507.19, 1317.88, 0, 0, 0, 0, 100, 0),
(3116710, 154, 9934.84, 2504.61, 1317.88, 0, 0, 0, 0, 100, 0),
(3116710, 155, 9933.5, 2502.29, 1317.88, 0, 0, 0, 0, 100, 0),
(3116710, 156, 9931.78, 2500.85, 1317.92, 0, 0, 0, 0, 100, 0),
(3116710, 157, 9929.06, 2500.65, 1317.92, 0, 0, 0, 0, 100, 0),
(3116710, 158, 9926.89, 2501.91, 1318.17, 0, 0, 0, 0, 100, 0),
(3116710, 159, 9919.01, 2508.07, 1317.55, 0, 0, 0, 0, 100, 0),
(3116710, 160, 9917.28, 2509.89, 1317.3, 0, 0, 0, 0, 100, 0),
(3116710, 161, 9916.58, 2512.78, 1317.17, 0, 0, 0, 0, 100, 0),
(3116710, 162, 9915.53, 2521.38, 1317.05, 0, 0, 0, 0, 100, 0),
(3116710, 163, 9914.63, 2523.59, 1317.05, 0, 0, 0, 0, 100, 0),
(3116710, 164, 9913.53, 2525.35, 1316.67, 0, 0, 0, 0, 100, 0),
(3116710, 165, 9907.01, 2533.01, 1316.17, 0, 0, 0, 0, 100, 0),
(3116710, 166, 9905.48, 2533.7, 1316, 0, 0, 0, 0, 100, 0),
(3116710, 167, 9903.21, 2534.1, 1315.75, 0, 0, 0, 0, 100, 0),
(3116710, 168, 9896.53, 2534.52, 1316, 0, 0, 0, 0, 100, 0),
(3116710, 169, 9886.23, 2534.43, 1318.75, 0, 0, 0, 0, 100, 0),
(3116710, 170, 9854.98, 2533.49, 1320.89, 0, 0, 0, 0, 100, 0),
(3116710, 171, 9825.17, 2532.56, 1321.06, 0, 0, 0, 0, 100, 0),
(3116710, 172, 9789.95, 2531.94, 1319.86, 0, 0, 0, 0, 100, 0),
(3116510, 1, 9775.32, 2526.24, 1318.84, 0, 0, 0, 0, 100, 0),
(3116510, 2, 9741.11, 2526.47, 1330.59, 0, 0, 0, 0, 100, 0),
(3116510, 3, 9714.14, 2525.51, 1335.69, 0, 20000, 0, 0, 100, 0),
(3116510, 4, 9712.36, 2537.05, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 5, 9709.46, 2550.9, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 6, 9703.13, 2563.03, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 7, 9698.74, 2568.85, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 8, 9698.28, 2581.84, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 9, 9710.37, 2592.32, 1336.72, 0, 0, 0, 0, 100, 0),
(3116510, 10, 9720.52, 2601.8, 1337.11, 0, 0, 0, 0, 100, 0),
(3116510, 11, 9732.8, 2612.01, 1335.79, 0, 0, 0, 0, 100, 0),
(3116510, 12, 9739.72, 2618.73, 1334.02, 0, 0, 0, 0, 100, 0),
(3116510, 13, 9745.11, 2629.8, 1334.3, 0, 19000, 0, 0, 100, 0),
(3116510, 14, 9742.93, 2627.36, 1334.22, 0, 0, 0, 0, 100, 0),
(3116510, 15, 9739.16, 2617.08, 1334.31, 0, 0, 0, 0, 100, 0),
(3116510, 16, 9732.11, 2611.05, 1335.79, 0, 0, 0, 0, 100, 0),
(3116510, 17, 9713.32, 2594.29, 1336.95, 0, 0, 0, 0, 100, 0),
(3116510, 18, 9703.71, 2586.42, 1335.73, 0, 0, 0, 0, 100, 0),
(3116510, 19, 9696.2, 2571.05, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 20, 9706.78, 2555.83, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 21, 9712.2, 2543.83, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 22, 9713.91, 2525.54, 1335.69, 0, 0, 0, 0, 100, 0),
(3116510, 23, 9713.77, 2513.44, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 24, 9712.47, 2502.87, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 25, 9708.95, 2493.58, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 26, 9703.36, 2484.98, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 27, 9699.19, 2479.34, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 28, 9702.04, 2469.11, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 29, 9716.89, 2456.65, 1336.96, 0, 0, 0, 0, 100, 0),
(3116510, 30, 9732.5, 2443.68, 1336.26, 0, 0, 0, 0, 100, 0),
(3116510, 31, 9758.73, 2423.4, 1334.14, 0, 34000, 0, 0, 100, 0),
(3116510, 32, 9744.31, 2434.67, 1334.22, 0, 0, 0, 0, 100, 0),
(3116510, 33, 9737.4, 2439.93, 1335.79, 0, 0, 0, 0, 100, 0),
(3116510, 34, 9718.78, 2454.4, 1337.07, 0, 0, 0, 0, 100, 0),
(3116510, 35, 9706.88, 2464.56, 1335.72, 0, 0, 0, 0, 100, 0),
(3116510, 36, 9700.29, 2478.86, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 37, 9708.25, 2493.77, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 38, 9712.78, 2509.64, 1335.68, 0, 0, 0, 0, 100, 0),
(3116510, 39, 9713.75, 2519.07, 1335.69, 0, 0, 0, 0, 100, 0),
(3116510, 40, 9719.04, 2525.65, 1335.69, 0, 0, 0, 0, 100, 0),
(3116510, 41, 9734.46, 2525.73, 1333.02, 0, 0, 0, 0, 100, 0),
(3116510, 42, 9750.11, 2526.17, 1327.45, 0, 0, 0, 0, 100, 0),
(3116510, 43, 9759.05, 2526.22, 1324.19, 0, 0, 0, 0, 100, 0),
(3116510, 44, 9774.12, 2527, 1319.15, 0, 0, 0, 0, 100, 0),
(3116510, 45, 9792.75, 2526.98, 1320.01, 0, 0, 0, 0, 100, 0),
(3116510, 46, 9809.65, 2527.63, 1320.68, 0, 0, 0, 0, 100, 0),
(3116510, 47, 9829.67, 2527.95, 1321.16, 0, 0, 0, 0, 100, 0),
(3116510, 48, 9846.95, 2528.68, 1321.45, 0, 0, 0, 0, 100, 0),
(3116510, 49, 9865.62, 2529.46, 1320.17, 0, 0, 0, 0, 100, 0),
(3116510, 50, 9883.95, 2529.66, 1318.92, 0, 0, 0, 0, 100, 0),
(3116510, 51, 9899.61, 2529.96, 1315.11, 0, 0, 0, 0, 100, 0),
(3116510, 52, 9923.5, 2529.91, 1319.05, 0, 26000, 0, 0, 100, 0),
(3116510, 53, 9900.18, 2530.35, 1315.3, 0, 0, 0, 0, 100, 0),
(3116510, 54, 9871.44, 2529.47, 1319.77, 0, 0, 0, 0, 100, 0),
(3116510, 55, 9850.28, 2529.3, 1321.22, 0, 0, 0, 0, 100, 0),
(3116510, 56, 9825.11, 2528.36, 1321.05, 0, 0, 0, 0, 100, 0),
(3116510, 57, 9800.17, 2528.08, 1320.35, 0, 0, 0, 0, 100, 0),
(3120600, 1, 10174.8, 2346.64, 1328.18, 0, 0, 0, 0, 100, 0),
(3120600, 2, 10182.5, 2339.69, 1328.06, 0, 0, 0, 0, 100, 0),
(3120600, 3, 10185.9, 2333.11, 1327.83, 0, 0, 0, 0, 100, 0),
(3120600, 4, 10186.5, 2328.58, 1327.95, 0, 0, 0, 0, 100, 0),
(3120600, 5, 10181.4, 2314.36, 1327.83, 0, 0, 0, 0, 100, 0),
(3120600, 6, 10170.9, 2294.66, 1328.04, 0, 0, 0, 0, 100, 0),
(3120600, 7, 10155.1, 2273.72, 1328.55, 0, 0, 0, 0, 100, 0),
(3120600, 8, 10140.4, 2259.7, 1328.09, 0, 0, 0, 0, 100, 0),
(3120600, 9, 10131, 2249.28, 1327.7, 0, 0, 0, 0, 100, 0),
(3120600, 10, 10126.2, 2246.83, 1327.7, 0, 0, 0, 0, 100, 0),
(3120600, 11, 10120.1, 2247.96, 1327.58, 0, 0, 0, 0, 100, 0),
(3120600, 12, 10114, 2253.09, 1327.58, 0, 0, 0, 0, 100, 0),
(3120600, 13, 10099, 2271.4, 1328.11, 0, 0, 0, 0, 100, 0),
(3120600, 14, 10088.5, 2287.25, 1329.36, 0, 0, 0, 0, 100, 0),
(3120600, 15, 10081.6, 2295.72, 1329.61, 0, 0, 0, 0, 100, 0),
(3120600, 16, 10075.9, 2295.84, 1329.49, 0, 0, 0, 0, 100, 0),
(3120600, 17, 10067.8, 2290.9, 1329.49, 0, 0, 0, 0, 100, 0 ),
(3120600, 18, 10055.8, 2285.36, 1329.44, 0, 0, 0, 0, 100, 0),
(3120600, 19, 10035.5, 2280.12, 1328.94, 0, 0, 0, 0, 100, 0 ),
(3120600, 20, 10019.1, 2281.63, 1335.93, 0, 0, 0, 0, 100, 0 ),
(3120600, 21, 10009.5, 2282.59, 1341.04, 0, 0, 0, 0, 100, 0 ),
(3120600, 22, 10002.2, 2282.77, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3120600, 23, 9974.47, 2279.73, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3120600, 24, 9958.83, 2279.63, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3120600, 25, 9954.92, 2282.52, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3120600, 26, 9950.62, 2289.64, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3120600, 27, 9948.64, 2298.74, 1338.22, 0, 0, 0, 0, 100, 0 ),
(3120600, 28, 9948.25, 2316.27, 1336.55, 0, 0, 0, 0, 100, 0 ),
(3120600, 29, 9947.92, 2327.04, 1334.35, 0, 0, 0, 0, 100, 0 ),
(3120600, 30, 9946.04, 2352.68, 1330.66, 0, 0, 0, 0, 100, 0 ),
(3120600, 31, 9944.61, 2386.32, 1329.33, 0, 0, 0, 0, 100, 0 ),
(3120600, 32, 9942.54, 2429.39, 1325.2, 0, 0, 0, 0, 100, 0  ),
(3120600, 33, 9943.56, 2456.7, 1320.44, 0, 0, 0, 0, 100, 0  ),
(3120600, 34, 9945.89, 2478.35, 1316.24, 0, 0, 0, 0, 100, 0 ),
(3120600, 35, 9945.46, 2483.71, 1316.37, 0, 0, 0, 0, 100, 0 ),
(3120600, 36, 9941.52, 2488.43, 1316.87, 0, 0, 0, 0, 100, 0 ),
(3120600, 37, 9934.64, 2492.63, 1317.74, 0, 0, 0, 0, 100, 0 ),
(3120600, 38, 9931.78, 2496.82, 1317.9, 0, 0, 0, 0, 100, 0  ),
(3120600, 39, 9923.84, 2505.3, 1318.05, 0, 0, 0, 0, 100, 0  ),
(3120600, 40, 9918.91, 2507.74, 1317.55, 0, 0, 0, 0, 100, 0 ),
(3120600, 41, 9915.42, 2512.41, 1317.05, 0, 0, 0, 0, 100, 0 ),
(3120600, 42, 9914.59, 2520.89, 1317.05, 0, 0, 0, 0, 100, 0 ),
(3120600, 43, 9910.34, 2527.94, 1316.42, 0, 0, 0, 0, 100, 0 ),
(3120600, 44, 9909.56, 2533.26, 1316.42, 0, 0, 0, 0, 100, 0 ),
(3120600, 45, 9912.56, 2537.83, 1316.63, 0, 0, 0, 0, 100, 0 ),
(3120600, 46, 9924.19, 2546.5, 1317.25, 0, 0, 0, 0, 100, 0  ),
(3120600, 47, 9924.19, 2546.5, 1317.25, 0, 0, 0, 0, 100, 0  ),
(3120600, 48, 9941.22, 2553.06, 1316.82, 0, 0, 0, 0, 100, 0 ),
(3120600, 49, 9949.14, 2553.75, 1316.44, 0, 0, 0, 0, 100, 0 ),
(3120600, 50, 9955.25, 2548.69, 1316.82, 0, 0, 0, 0, 100, 0 ),
(3120600, 51, 9961.83, 2545.14, 1317.07, 0, 0, 0, 0, 100, 0 ),
(3120600, 52, 9968.58, 2541.93, 1316.87, 0, 0, 0, 0, 100, 0 ),
(3120600, 53, 9987.74, 2520.83, 1316.25, 0, 0, 0, 0, 100, 0 ),
(3120600, 54, 9993.47, 2514.22, 1316.25, 0, 0, 0, 0, 100, 0 ),
(3120600, 55, 10002.2, 2510.39, 1316.55, 0, 0, 0, 0, 100, 0 ),
(3120600, 56, 10012.2, 2506.15, 1319.02, 0, 0, 0, 0, 100, 0 ),
(3120600, 57, 10031.3, 2500.34, 1318.42, 0, 0, 0, 0, 100, 0 ),
(3120600, 58, 10036.8, 2500.6, 1318.42, 0, 0, 0, 0, 100, 0  ),
(3120600, 59, 10051.2, 2508.19, 1318.39, 0, 0, 0, 0, 100, 0 ),
(3120600, 60, 10062.5, 2514.76, 1320.1, 0, 0, 0, 0, 100, 0  ),
(3120600, 61, 10074.4, 2521.6, 1319.62, 0, 0, 0, 0, 100, 0  ),
(3120600, 62, 10084.5, 2527.64, 1317.59, 0, 0, 0, 0, 100, 0 ),
(3120600, 63, 10089.4, 2533.48, 1317.89, 0, 0, 0, 0, 100, 0 ),
(3120600, 64, 10095.5, 2538.91, 1319.01, 0, 0, 0, 0, 100, 0 ),
(3120600, 65, 10101.1, 2539.83, 1319.71, 0, 0, 0, 0, 100, 0 ),
(3120600, 66, 10117, 2542.48, 1321.34, 0, 0, 0, 0, 100, 0   ),
(3120600, 67, 10124.5, 2544.19, 1321.71, 0, 0, 0, 0, 100, 0 ),
(3120600, 68, 10131.5, 2546.76, 1321.84, 0, 0, 0, 0, 100, 0 ),
(3120600, 69, 10136.5, 2550.14, 1321.8, 0, 0, 0, 0, 100, 0  ),
(3120600, 70, 10139.3, 2553.62, 1321.8, 0, 0, 0, 0, 100, 0  ),
(3120600, 71, 10139.5, 2557.88, 1321.92, 0, 0, 0, 0, 100, 0 ),
(3120600, 72, 10138.1, 2563.78, 1322.17, 0, 0, 0, 0, 100, 0 ),
(3120600, 73, 10135, 2566.4, 1322.55, 0, 0, 0, 0, 100, 0    ),
(3120600, 74, 10132.3, 2571.3, 1323.33, 0, 0, 0, 0, 100, 0  ),
(3120600, 75, 10131.5, 2574.56, 1323.71, 0, 0, 0, 0, 100, 0 ),
(3120600, 76, 10134, 2573.48, 1323.28, 0, 0, 0, 0, 100, 0   ),
(3120600, 77, 10141.2, 2565.23, 1321.8, 0, 0, 0, 0, 100, 0  ),
(3120600, 78, 10142.4, 2562.29, 1321.92, 0, 0, 0, 0, 100, 0 ),
(3120600, 79, 10143.8, 2553.87, 1321.8, 0, 0, 0, 0, 100, 0  ),
(3120600, 80, 10140.7, 2548.88, 1321.92, 0, 0, 0, 0, 100, 0 ),
(3120600, 81, 10120.1, 2539.57, 1321.71, 0, 0, 0, 0, 100, 0 ),
(3120600, 82, 10107.5, 2537.9, 1320.34, 0, 0, 0, 0, 100, 0  ),
(3120600, 83, 10098.9, 2536.35, 1319.26, 0, 0, 0, 0, 100, 0 ),
(3120600, 84, 10090.9, 2529.96, 1317.59, 0, 0, 0, 0, 100, 0 ),
(3120600, 85, 10090.3, 2526.44, 1317.59, 0, 0, 0, 0, 100, 0 ),
(3120600, 86, 10099.5, 2510.2, 1317.72, 0, 0, 0, 0, 100, 0  ),
(3120600, 87, 10108.5, 2492.17, 1317.57, 0, 0, 0, 0, 100, 0 ),
(3120600, 88, 10109.9, 2483.67, 1317.57, 0, 0, 0, 0, 100, 0 ),
(3120600, 89, 10104.2, 2464.98, 1317.44, 0, 0, 0, 0, 100, 0 ),
(3120600, 90, 10105.3, 2454.7, 1318.82, 0, 0, 0, 0, 100, 0  ),
(3120600, 91, 10106.1, 2442.88, 1318.94, 0, 0, 0, 0, 100, 0 ),
(3120600, 92, 10104.3, 2411.59, 1316.09, 0, 0, 0, 0, 100, 0 ),
(3120600, 93, 10104.3, 2411.59, 1316.09, 0, 0, 0, 0, 100, 0 ),
(3120600, 94, 10098.8, 2392.37, 1316.51, 0, 0, 0, 0, 100, 0 ),
(3120600, 95, 10099.9, 2389.5, 1316.51, 0, 0, 0, 0, 100, 0  ),
(3120600, 96, 10107.3, 2385.02, 1316.98, 0, 0, 0, 0, 100, 0 ),
(3120600, 97, 10115.7, 2379.92, 1317.48, 0, 0, 0, 0, 100, 0 ),
(3120600, 98, 10127.5, 2374.58, 1319.48, 0, 0, 0, 0, 100, 0 ),
(3120600, 99, 10133.7, 2372.88, 1320.37, 0, 0, 0, 0, 100, 0 ),
(3120600, 100, 10142.2, 2372.35, 1321.37, 0, 0, 0, 0, 100, 0),
(3120600, 101, 10152.8, 2371.75, 1323.12, 0, 0, 0, 0, 100, 0),
(3120600, 102, 10164, 2367.42, 1324.74, 0, 0, 0, 0, 100, 0  ),
(3120600, 103, 10169.9, 2361.33, 1326.18, 0, 0, 0, 0, 100, 0),
(3120600, 104, 10172.5, 2350.92, 1327.93, 0, 0, 0, 0, 100, 0),
(3116130, 1, 9932.1, 2593.26, 1315.93, 0, 10000, 0, 0, 100, 0),
(3116130, 2, 9944.62, 2588.15, 1316.19, 0, 0, 0, 0, 100, 0),
(3116130, 3, 9945.83, 2576.32, 1318.33, 0, 0, 0, 0, 100, 0),
(3116130, 4, 9946.67, 2556.98, 1316.22, 0, 0, 0, 0, 100, 0),
(3116130, 5, 9954.39, 2552.2, 1316.42, 0, 0, 0, 0, 100, 0),
(3116130, 6, 9973.6, 2538.99, 1316.45, 0, 0, 0, 0, 100, 0),
(3116130, 7, 9984, 2524.64, 1316.3, 0, 0, 0, 0, 100, 0),
(3116130, 8, 9994.98, 2513.92, 1315.93, 0, 0, 0, 0, 100, 0),
(3116130, 9, 10004.2, 2510.24, 1317.17, 0, 0, 0, 0, 100, 0),
(3116130, 10, 10012.4, 2507.05, 1319.03, 0, 0, 0, 0, 100, 0),
(3116130, 11, 10029.1, 2501.75, 1318.41, 0, 0, 0, 0, 100, 0),
(3116130, 12, 10049.7, 2506.84, 1318.39, 0, 0, 0, 0, 100, 0),
(3116130, 13, 10061.8, 2513.79, 1320.14, 0, 0, 0, 0, 100, 0),
(3116130, 14, 10074.5, 2521.84, 1319.61, 0, 0, 0, 0, 100, 0),
(3116130, 15, 10081.8, 2527.27, 1317.31, 0, 0, 0, 0, 100, 0),
(3116130, 16, 10090, 2536.3, 1318.12, 0, 0, 0, 0, 100, 0),
(3116130, 17, 10083.9, 2552.59, 1318.85, 0, 0, 0, 0, 100, 0),
(3116130, 18, 10076.9, 2572.1, 1319.79, 0, 0, 0, 0, 100, 0),
(3116130, 19, 10074.8, 2596.34, 1320.21, 0, 0, 0, 0, 100, 0),
(3116130, 20, 10073.4, 2616.82, 1318.19, 0, 0, 0, 0, 100, 0),
(3116130, 21, 10070.6, 2628.49, 1316.96, 0, 0, 0, 0, 100, 0),
(3116130, 22, 10063.7, 2631.14, 1315.7, 0, 20000, 0, 0, 100, 0),
(3116130, 23, 10071.1, 2613.4, 1318.46, 0, 0, 0, 0, 100, 0),
(3116130, 24, 10074.3, 2593.36, 1320.09, 0, 0, 0, 0, 100, 0),
(3116130, 25, 10081.1, 2570.85, 1319.96, 0, 0, 0, 0, 100, 0),
(3116130, 26, 10086.1, 2544.85, 1318.33, 0, 0, 0, 0, 100, 0),
(3116130, 27, 10089.1, 2530.4, 1317.56, 0, 0, 0, 0, 100, 0),
(3116130, 28, 10082.6, 2524.75, 1317.44, 0, 0, 0, 0, 100, 0),
(3116130, 29, 10074.9, 2520.34, 1319.62, 0, 0, 0, 0, 100, 0),
(3116130, 30, 10062.3, 2513.29, 1320.12, 0, 0, 0, 0, 100, 0),
(3116130, 31, 10052.1, 2507.46, 1318.38, 0, 0, 0, 0, 100, 0),
(3116130, 32, 10031.9, 2499.78, 1318.42, 0, 0, 0, 0, 100, 0),
(3116130, 33, 10011.2, 2505.53, 1319.01, 0, 0, 0, 0, 100, 0),
(3116130, 34, 10002.1, 2509.56, 1316.66, 0, 0, 0, 0, 100, 0),
(3116130, 35, 9999.23, 2510.97, 1315.06, 0, 0, 0, 0, 100, 0),
(3116130, 36, 9986.87, 2516.76, 1316.48, 0, 0, 0, 0, 100, 0),
(3116130, 37, 9973.29, 2510.98, 1317.28, 0, 0, 0, 0, 100, 0),
(3116130, 38, 9962.53, 2499.78, 1316.86, 0, 0, 0, 0, 100, 0),
(3116130, 39, 9951.02, 2489.04, 1316.63, 0, 0, 0, 0, 100, 0),
(3116130, 40, 9938.44, 2489.89, 1317.22, 0, 0, 0, 0, 100, 0),
(3116130, 41, 9926.8, 2499.39, 1317.88, 0, 0, 0, 0, 100, 0),
(3116130, 42, 9915.18, 2504.09, 1316.83, 0, 0, 0, 0, 100, 0),
(3116130, 43, 9908.78, 2503.71, 1315.63, 0, 0, 0, 0, 100, 0),
(3116130, 44, 9903.12, 2502.95, 1317.86, 0, 0, 0, 0, 100, 0),
(3116130, 45, 9892.87, 2500.73, 1318.71, 0, 0, 0, 0, 100, 0),
(3116130, 46, 9882.37, 2498.01, 1315.93, 0, 0, 0, 0, 100, 0),
(3116130, 47, 9875.86, 2485.17, 1315.9, 0, 0, 0, 0, 100, 0),
(3116130, 48, 9879.28, 2476.49, 1317.81, 0, 0, 0, 0, 100, 0),
(3116130, 49, 9882.92, 2466.66, 1317.85, 0, 0, 0, 0, 100, 0),
(3116130, 50, 9883.89, 2463.7, 1316.85, 0, 0, 0, 0, 100, 0),
(3116130, 51, 9884.69, 2455.03, 1317.35, 0, 0, 0, 0, 100, 0),
(3116130, 52, 9880.77, 2446.7, 1317.13, 0, 0, 0, 0, 100, 0),
(3116130, 53, 9870.79, 2436.41, 1316.72, 0, 20000, 0, 0, 100, 0),
(3116130, 54, 9882.4, 2441.23, 1316.35, 0, 0, 0, 0, 100, 0),
(3116130, 55, 9887.27, 2454.27, 1317.19, 0, 0, 0, 0, 100, 0),
(3116130, 56, 9883.81, 2463.44, 1316.92, 0, 0, 0, 0, 100, 0),
(3116130, 57, 9882.46, 2467.04, 1317.92, 0, 0, 0, 0, 100, 0),
(3116130, 58, 9878.92, 2476.43, 1317.81, 0, 0, 0, 0, 100, 0),
(3116130, 59, 9876.91, 2481.78, 1316.05, 0, 0, 0, 0, 100, 0),
(3116130, 60, 9879.51, 2499.29, 1315.91, 0, 0, 0, 0, 100, 0),
(3116130, 61, 9892.47, 2501.61, 1318.72, 0, 0, 0, 0, 100, 0),
(3116130, 62, 9902.97, 2503.1, 1317.87, 0, 0, 0, 0, 100, 0),
(3116130, 63, 9909.83, 2505.33, 1316.08, 0, 0, 0, 0, 100, 0),
(3116130, 64, 9913.17, 2515.62, 1316.73, 0, 0, 0, 0, 100, 0),
(3116130, 65, 9911.46, 2524.95, 1316.47, 0, 0, 0, 0, 100, 0),
(3116130, 66, 9910.31, 2535.63, 1316.33, 0, 0, 0, 0, 100, 0),
(3116130, 67, 9920.09, 2545.76, 1317.13, 0, 0, 0, 0, 100, 0),
(3116130, 68, 9933.32, 2551.27, 1317.37, 0, 0, 0, 0, 100, 0),
(3116130, 69, 9944.02, 2555.59, 1316.43, 0, 0, 0, 0, 100, 0),
(3116130, 70, 9945.22, 2559.85, 1315.88, 0, 0, 0, 0, 100, 0),
(3116130, 71, 9944.64, 2568.81, 1318.28, 0, 0, 0, 0, 100, 0),
(3116130, 72, 9944.17, 2576.73, 1318.33, 0, 0, 0, 0, 100, 0),
(3116130, 73, 9943.88, 2583.02, 1315.99, 0, 0, 0, 0, 100, 0),
(3116130, 74, 9940.84, 2591.64, 1316.21, 0, 0, 0, 0, 100, 0),
(8440, 1,10163.099, 2638.071, 1322.061, 0, 0, 0, 0, 100, 0),
(8440, 2,10211.149, 2614.471, 1317.925, 0, 0, 0, 0, 100, 0),
(8440, 3,10242.527, 2577.304, 1332.429, 0, 0, 0, 0, 100, 0),
(8440, 4,10286.833, 2547.500, 1335.184, 0, 0, 0, 0, 100, 0),
(8440, 5,10242.527, 2577.304, 1332.429, 0, 0, 0, 0, 100, 0),
(8440, 6,10211.149, 2614.471, 1317.925, 0, 0, 0, 0, 100, 0),
(8440, 7,10163.099, 2638.071, 1322.061, 0, 0, 0, 0, 100, 0),
(3119910, 1,10084.010, 2527.048, 1317.558,0, 0, 0, 0, 100, 0),
(3119910, 2,10111.700, 2533.770, 1321.189,0, 0, 0, 0, 100, 0),
(3119910, 3,10144.516, 2551.302, 1321.750,0, 0, 0, 0, 100, 0),
(3119910, 4,10124.552, 2587.826, 1327.542,0, 0, 0, 0, 100, 0),
(3119910, 5,10144.516, 2551.302, 1321.750,0, 0, 0, 0, 100, 0),
(3119910, 6,10111.700, 2533.770, 1321.189,0, 0, 0, 0, 100, 0),
(3119910, 7,10084.010, 2527.048, 1317.558,0, 0, 0, 0, 100, 0),
(3119700, 1,10090.200, 2522.530, 1317.589,0, 0, 0, 0, 100, 0),
(3119700, 2,10106.415, 2490.870, 1317.583,0, 0, 0, 0, 100, 0),
(3119700, 3,10108.822, 2479.502, 1317.285,0, 0, 0, 0, 100, 0),
(3119700, 4,10100.720, 2460.128, 1317.890,0, 0, 0, 0, 100, 0),
(3119700, 5,10068.838, 2445.922, 1317.255,0, 0, 0, 0, 100, 0),
(3119700, 6,10034.832, 2427.690, 1315.901,0, 0, 0, 0, 100, 0),
(3119700, 7,10068.838, 2445.922, 1317.255,0, 0, 0, 0, 100, 0),
(3119700, 8,10100.720, 2460.128, 1317.890,0, 0, 0, 0, 100, 0),
(3119700, 9,10108.822, 2479.502, 1317.285,0, 0, 0, 0, 100, 0),
(3119700, 10,10106.415, 2490.870, 1317.583,0, 0, 0, 0, 100, 0),
(3119700, 11,10090.200, 2522.530, 1317.589,0, 0, 0, 0, 100, 0),
(3119950, 1, 10126, 2582.53, 1325.97, 0, 0, 0, 0, 100, 0),
(3119950, 2, 10132.5, 2573.71, 1323.42, 0, 0, 0, 0, 100, 0),
(3119950, 3, 10139, 2565.42, 1322.01, 0, 0, 0, 0, 100, 0),
(3119950, 4, 10142.9, 2551.64, 1321.72, 0, 0, 0, 0, 100, 0),
(3119950, 5, 10131.6, 2546.08, 1321.79, 0, 0, 0, 0, 100, 0),
(3119950, 6, 10119.4, 2540.75, 1321.52, 0, 0, 0, 0, 100, 0),
(3119950, 7, 10101, 2538.54, 1319.55, 0, 0, 0, 0, 100, 0),
(3119950, 8, 10088.4, 2529.86, 1317.56, 0, 0, 0, 0, 100, 0),
(3119950, 9, 10094.6, 2516.65, 1317.67, 0, 0, 0, 0, 100, 0),
(3119950, 10, 10104.1, 2498.36, 1317.6, 0, 0, 0, 0, 100, 0),
(3119950, 11, 10108.1, 2484.09, 1317.46, 0, 0, 0, 0, 100, 0),
(3119950, 12, 10105, 2470.59, 1317.16, 0, 0, 0, 0, 100, 0),
(3119950, 13, 10098.4, 2460.89, 1317.88, 0, 0, 0, 0, 100, 0),
(3119950, 14, 10086.9, 2454.49, 1318.06, 0, 0, 0, 0, 100, 0),
(3119950, 15, 10074.6, 2448.79, 1317.34, 0, 0, 0, 0, 100, 0),
(3119950, 16, 10090.9, 2456.54, 1318.14, 0, 0, 0, 0, 100, 0),
(3119950, 17, 10102, 2463.36, 1317.59, 0, 0, 0, 0, 100, 0),
(3119950, 18, 10108.3, 2480.45, 1317.32, 0, 0, 0, 0, 100, 0),
(3119950, 19, 10106.2, 2493.46, 1317.56, 0, 0, 0, 0, 100, 0),
(3119950, 20, 10088, 2529.08, 1317.56, 0, 0, 0, 0, 100, 0),
(3119950, 21, 10098.2, 2536.91, 1319.19, 0, 0, 0, 0, 100, 0),
(3119950, 22, 10118.8, 2541.91, 1321.45, 0, 0, 0, 0, 100, 0),
(3119950, 23, 10141.5, 2550.47, 1321.72, 0, 0, 0, 0, 100, 0),
(3119950, 24, 10139.5, 2564.52, 1321.96, 0, 0, 0, 0, 100, 0),
(3117590, 1, 9662.45, 2327.01, 1327.61, 0, 0, 0, 0, 100, 0  ),
(3117590, 2, 9658.77, 2330.16, 1327.61, 0, 0, 0, 0, 100, 0  ),
(3117590, 3, 9650.28, 2338.99, 1327.56, 0, 0, 0, 0, 100, 0  ),
(3117590, 4, 9647.56, 2342.8, 1327.56, 0, 0, 0, 0, 100, 0   ),
(3117590, 5, 9644.05, 2347.35, 1327.56, 0, 0, 0, 0, 100, 0  ),
(3117590, 6, 9740.74, 2340.18, 1328.34, 0, 0, 0, 0, 100, 0  ),
(3117590, 7, 9733.45, 2342.2, 1327.84, 0, 0, 0, 0, 100, 0   ),
(3117590, 8, 9728.34, 2347.02, 1327.62, 0, 0, 0, 0, 100, 0  ),
(3117590, 9, 9724.54, 2351.81, 1327.5, 0, 0, 0, 0, 100, 0   ),
(3117590, 10, 9719.77, 2357.38, 1327.5, 0, 0, 0, 0, 100, 0  ),
(3117590, 11, 9716.24, 2359.51, 1327.5, 0, 0, 0, 0, 100, 0  ),
(3117590, 12, 9713.92, 2358.9, 1327.5, 0, 0, 0, 0, 100, 0   ),
(3117590, 13, 9713.4, 2357.47, 1327.5, 0, 0, 0, 0, 100, 0   ),
(3117590, 14, 9715.08, 2355.19, 1327.5, 0, 0, 0, 0, 100, 0  ),
(3117590, 15, 9722.51, 2348.68, 1327.37, 0, 0, 0, 0, 100, 0 ),
(3117590, 16, 9731.41, 2339.11, 1327.87, 0, 0, 0, 0, 100, 0 ),
(3117590, 17, 9738.89, 2335.75, 1328.72, 0, 0, 0, 0, 100, 0 ),
(3117590, 18, 9742.57, 2333.9, 1328.97, 0, 0, 0, 0, 100, 0  ),
(3117590, 19, 9748.34, 2329.59, 1328.98, 0, 0, 0, 0, 100, 0 ),
(3117590, 20, 9752.23, 2325.58, 1328.85, 0, 0, 0, 0, 100, 0 ),
(3117590, 21, 9755.49, 2319.34, 1328.48, 0, 0, 0, 0, 100, 0 ),
(3117590, 22, 9756.31, 2314.43, 1328.23, 0, 0, 0, 0, 100, 0 ),
(3117590, 23, 9760.53, 2310.07, 1327.98, 0, 0, 0, 0, 100, 0 ),
(3117590, 24, 9762.57, 2305.8, 1327.85, 0, 0, 0, 0, 100, 0  ),
(3117590, 25, 9771.15, 2298.07, 1327.48, 0, 0, 0, 0, 100, 0 ),
(3117590, 26, 9779.69, 2289.91, 1327.48, 0, 0, 0, 0, 100, 0 ),
(3117590, 27, 9783.95, 2287.09, 1327.73, 0, 0, 0, 0, 100, 0 ),
(3117590, 28, 9791.25, 2283.94, 1327.73, 0, 0, 0, 0, 100, 0 ),
(3117590, 29, 9798.12, 2283.38, 1327.35, 0, 0, 0, 0, 100, 0 ),
(3117590, 30, 9804.93, 2283.01, 1327.15, 0, 0, 0, 0, 100, 0 ),
(3117590, 31, 9814.32, 2278.78, 1327.15, 0, 0, 0, 0, 100, 0 ),
(3117590, 32, 9822.92, 2276.22, 1327.02, 0, 0, 0, 0, 100, 0 ),
(3117590, 33, 9832.75, 2277, 1327.02, 0, 0, 0, 0, 100, 0    ),
(3117590, 34, 9843.3, 2278.08, 1326.74, 0, 0, 0, 0, 100, 0  ),
(3117590, 35, 9858.15, 2278.75, 1327.24, 0, 0, 0, 0, 100, 0 ),
(3117590, 36, 9869.67, 2278.27, 1328.65, 0, 0, 0, 0, 100, 0 ),
(3117590, 37, 9880.76, 2278.4, 1333.95, 0, 0, 0, 0, 100, 0  ),
(3117590, 38, 9890.19, 2279.55, 1338.64, 0, 0, 0, 0, 100, 0 ),
(3117590, 39, 9899.26, 2279.79, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3117590, 40, 9912.74, 2278.86, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3117590, 41, 9924, 2278.35, 1341.39, 0, 0, 0, 0, 100, 0    ),
(3117590, 42, 9936.09, 2278.17, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3117590, 43, 9943.57, 2279.43, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3117590, 44, 9947.86, 2282.39, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3117590, 45, 9949.2, 2285, 1341.39, 0, 0, 0, 0, 100, 0     ),
(3117590, 46, 9949.31, 2287.86, 1341.39, 0, 0, 0, 0, 100, 0 ),
(3117590, 47, 9949.21, 2293.42, 1341.02, 0, 0, 0, 0, 100, 0 ),
(3117590, 48, 9948.45, 2304.3, 1336.55, 0, 0, 0, 0, 100, 0  ),
(3117590, 49, 9948.39, 2313.23, 1336.55, 0, 0, 0, 0, 100, 0 ),
(3117590, 50, 9948.19, 2323.44, 1335.48, 0, 0, 0, 0, 100, 0 ),
(3117590, 51, 9947.31, 2336.46, 1331.57, 0, 0, 0, 0, 100, 0 ),
(3117590, 52, 9946.2, 2354.28, 1330.61, 0, 0, 0, 0, 100, 0  ),
(3117590, 53, 9945.45, 2375.02, 1329.95, 0, 0, 0, 0, 100, 0 ),
(3117590, 54, 9944.13, 2409.82, 1327.69, 0, 0, 0, 0, 100, 0 ),
(3117590, 55, 9944.13, 2409.82, 1327.69, 0, 0, 0, 0, 100, 0 ),
(3117590, 56, 9943, 2428.54, 1325.31, 0, 0, 0, 0, 100, 0    ),
(3117590, 57, 9942.94, 2447.72, 1322.24, 0, 0, 0, 0, 100, 0 ),
(3117590, 58, 9944.98, 2470.11, 1317.46, 0, 0, 0, 0, 100, 0 ),
(3117590, 59, 9946.16, 2480.07, 1316.24, 0, 0, 0, 0, 100, 0 ),
(3117590, 60, 9945.3, 2483.65, 1316.37, 0, 0, 0, 0, 100, 0  ),
(3117590, 61, 9938, 2490, 1317.37, 0, 0, 0, 0, 100, 0       ),
(3117590, 62, 9932.35, 2496.28, 1317.9, 0, 0, 0, 0, 100, 0  ),
(3117590, 63, 9923.41, 2503.71, 1318.05, 0, 0, 0, 0, 100, 0 ),
(3117590, 64, 9919.17, 2505.46, 1317.55, 0, 0, 0, 0, 100, 0 ),
(3117590, 65, 9915.68, 2505.95, 1317.05, 0, 0, 0, 0, 100, 0 ),
(3117590, 66, 9907.5, 2505.25, 1316.03, 0, 0, 0, 0, 100, 0  ),
(3117590, 67, 9899.11, 2503.24, 1318.12, 0, 0, 0, 0, 100, 0 ),
(3117590, 68, 9888.55, 2501.81, 1317.89, 0, 0, 0, 0, 100, 0 ),
(3117590, 69, 9882.41, 2498.56, 1315.92, 0, 0, 0, 0, 100, 0 ),
(3117590, 70, 9878.96, 2494.41, 1315.88, 0, 0, 0, 0, 100, 0 ),
(3117590, 71, 9876.62, 2488.41, 1315.88, 0, 0, 0, 0, 100, 0 ),
(3117590, 72, 9876.19, 2481.46, 1316.11, 0, 0, 0, 0, 100, 0 ),
(3117590, 73, 9877.87, 2476.74, 1317.8, 0, 0, 0, 0, 100, 0  ),
(3117590, 74, 9880.84, 2470.35, 1317.88, 0, 0, 0, 0, 100, 0 ),
(3117590, 75, 9883.1, 2465.26, 1317.3, 0, 0, 0, 0, 100, 0   ),
(3117590, 76, 9886.26, 2458.91, 1317.37, 0, 0, 0, 0, 100, 0 ),
(3117590, 77, 9886.66, 2453.56, 1317.24, 0, 0, 0, 0, 100, 0 ),
(3117590, 78, 9883.71, 2439.95, 1316.24, 0, 0, 0, 0, 100, 0 ),
(3117590, 79, 9878.99, 2428.08, 1316.38, 0, 0, 0, 0, 100, 0 ),
(3117590, 80, 9863.95, 2399.86, 1316.92, 0, 0, 0, 0, 100, 0 ),
(3117590, 81, 9849.99, 2376.17, 1316.36, 0, 0, 0, 0, 100, 0 ),
(3117590, 82, 9843.15, 2368.84, 1315.63, 0, 0, 0, 0, 100, 0 ),
(3117590, 83, 9840.7, 2365.62, 1316.81, 0, 0, 0, 0, 100, 0  ),
(3117590, 84, 9837.72, 2360.19, 1316.68, 0, 0, 0, 0, 100, 0 ),
(3117590, 85, 9838.51, 2348.59, 1314.81, 0, 0, 0, 0, 100, 0 ),
(3117590, 86, 9839.29, 2340.45, 1314.31, 0, 0, 0, 0, 100, 0 ),
(3117590, 87, 9839.9, 2333.73, 1314.31, 0, 0, 0, 0, 100, 0  ),
(3117590, 88, 9839.62, 2321.73, 1315.66, 0, 0, 0, 0, 100, 0 ),
(3117590, 89, 9839.23, 2310.68, 1318.16, 0, 0, 0, 0, 100, 0 ),
(3117590, 90, 9840.33, 2308.16, 1318.53, 0, 0, 0, 0, 100, 0 ),
(3117590, 91, 9843.7, 2303.42, 1319.28, 0, 0, 0, 0, 100, 0  ),
(3117590, 92, 9846.72, 2298.52, 1320.74, 0, 0, 0, 0, 100, 0 ),
(3117590, 93, 9849.37, 2289.92, 1323.62, 0, 0, 0, 0, 100, 0 ),
(3117590, 94, 9850.79, 2280.19, 1326.24, 0, 0, 0, 0, 100, 0 ),
(3117590, 95, 9851.72, 2269.08, 1327.12, 0, 0, 0, 0, 100, 0 ),
(3117590, 96, 9851.05, 2260.47, 1327.67, 0, 0, 0, 0, 100, 0 ),
(3117590, 97, 9849.52, 2250.54, 1327.67, 0, 0, 0, 0, 100, 0 ),
(3117590, 98, 9846.16, 2241.25, 1327.79, 0, 0, 0, 0, 100, 0 ),
(3117590, 99, 9842.95, 2232.97, 1327.7, 0, 0, 0, 0, 100, 0  ),
(3117590, 100, 9838.71, 2226.47, 1327.7, 0, 0, 0, 0, 100, 0 ),
(3117590, 101, 9835.18, 2221.21, 1327.83, 0, 0, 0, 0, 100, 0),
(3117590, 102, 9830.41, 2218.2, 1327.89, 0, 0, 0, 0, 100, 0 ),
(3117590, 103, 9824.44, 2216.95, 1327.89, 0, 0, 0, 0, 100, 0),
(3117590, 104, 9816.69, 2216.25, 1327.77, 0, 0, 0, 0, 100, 0),
(3117590, 105, 9806.7, 2217.33, 1327.77, 0, 0, 0, 0, 100, 0 ),
(3117590, 106, 9798.7, 2220.23, 1327.7, 0, 0, 0, 0, 100, 0  ),
(3117590, 107, 9791.35, 2224.93, 1327.7, 0, 0, 0, 0, 100, 0 ),
(3117590, 108, 9781.25, 2231.72, 1327.7, 0, 0, 0, 0, 100, 0 ),
(3117590, 109, 9769.54, 2238.83, 1327.77, 0, 0, 0, 0, 100, 0),
(3117590, 110, 9759.6, 2244.79, 1327.73, 0, 0, 0, 0, 100, 0 ),
(3117590, 111, 9747.96, 2250.43, 1327.61, 0, 0, 0, 0, 100, 0),
(3117590, 112, 9739.26, 2255.18, 1327.61, 0, 0, 0, 0, 100, 0),
(3117590, 113, 9727.25, 2261.62, 1327.56, 0, 0, 0, 0, 100, 0),
(3117590, 114, 9719.52, 2265.09, 1327.56, 0, 0, 0, 0, 100, 0),
(3117590, 115, 9712.61, 2270.8, 1327.6, 0, 0, 0, 0, 100, 0  ),
(3117590, 116, 9704.03, 2278.19, 1327.6, 0, 0, 0, 0, 100, 0 ),
(3117590, 117, 9698.98, 2283.58, 1327.61, 0, 0, 0, 0, 100, 0),
(3117590, 118, 9696.37, 2289.91, 1327.61, 0, 0, 0, 0, 100, 0),
(3117590, 119, 9690.62, 2298.11, 1327.61, 0, 0, 0, 0, 100, 0),
(3117590, 120, 9681.88, 2308.4, 1327.61, 0, 0, 0, 0, 100, 0 ),
(3117590, 121, 9673.43, 2317.45, 1327.61, 0, 0, 0, 0, 100, 0),
(3117590, 122, 9667.44, 2324.24, 1327.61, 0, 0, 0, 0, 100, 0),
(3117690, 1, 9732.6, 2255.22, 1327.49, 0, 0, 0, 0, 100, 0),
(3117690, 2, 9750.81, 2248.85, 1327.57, 0, 0, 0, 0, 100, 0),
(3117690, 3, 9765.48, 2242.9, 1327.64, 0, 0, 0, 0, 100, 0),
(3117690, 4, 9780.38, 2233.58, 1327.64, 0, 0, 0, 0, 100, 0),
(3117690, 5, 9792.03, 2225.81, 1327.64, 0, 0, 0, 0, 100, 0),
(3117690, 6, 9803.69, 2220.45, 1327.65, 0, 0, 0, 0, 100, 0),
(3117690, 7, 9816.14, 2218.5, 1327.64, 0, 0, 0, 0, 100, 0 ),
(3117690, 8, 9832.52, 2220.79, 1327.75, 0, 0, 0, 0, 100, 0),
(3117690, 9, 9841.08, 2232.14, 1327.65, 0, 0, 0, 0, 100, 0),
(3117690, 10, 9846.54, 2247.42, 1327.65, 0, 0, 0, 0, 100, 0),
(3117690, 11, 9849.53, 2261.1, 1327.51, 0, 0, 0, 0, 100, 0 ),
(3117690, 12, 9849.22, 2276.46, 1326.57, 0, 0, 0, 0, 100, 0),
(3117690, 13, 9837.62, 2278.16, 1326.92, 0, 0, 0, 0, 100, 0),
(3117690, 14, 9827.37, 2278.44, 1326.96, 0, 0, 0, 0, 100, 0),
(3117690, 15, 9815.83, 2281.11, 1327.03, 0, 0, 0, 0, 100, 0),
(3117690, 16, 9804, 2284.11, 1327.04, 0, 0, 0, 0, 100, 0   ),
(3117690, 17, 9790.87, 2287.71, 1327.34, 0, 0, 0, 0, 100, 0),
(3117690, 18, 9776.07, 2295.24, 1327.32, 0, 0, 0, 0, 100, 0),
(3117690, 19, 9766.98, 2293.03, 1327.64, 0, 0, 0, 0, 100, 0),
(3117690, 20, 9757.68, 2285.88, 1327.64, 0, 0, 0, 0, 100, 0),
(3117690, 21, 9749.1, 2276.91, 1327.72, 0, 0, 0, 0, 100, 0 ),
(3117690, 22, 9740.25, 2265.85, 1327.52, 0, 0, 0, 0, 100, 0),
(8500, 1,10042.200, 2218.1, 1328.16, 0, 0, 0, 0, 100, 0 ),
(8500, 2,10083.334, 2228.231, 1327.499, 0, 0, 0, 0, 100, 0 ),
(8500, 3,10112.734, 2238.314, 1327.457, 0, 0, 0, 0, 100, 0 ),
(8500, 4,10161.411, 2280.265, 1328.408, 0, 0, 0, 0, 100, 0 ),
(8500, 5,10181.054, 2316.116, 1327.713, 0, 0, 0, 0, 100, 0 ),
(8500, 6,10191.550, 2364.978, 1328.128, 0, 0, 0, 0, 100, 0 ),
(8500, 7,10181.054, 2316.116, 1327.713, 0, 0, 0, 0, 100, 0 ),
(8500, 8,10161.411, 2280.265, 1328.408, 0, 0, 0, 0, 100, 0 ),
(8500, 9,10112.734, 2238.314, 1327.457, 0, 0, 0, 0, 100, 0 ),
(8500, 10,10083.334, 2228.231, 1327.499, 0, 0, 0, 0, 100, 0 ),
(8500, 11,10042.200, 2218.1, 1328.16, 0, 0, 0, 0, 100, 0 ),
(8480, 1,10172.0996, 2343.780, 1328.060,0, 0, 0, 0, 100, 0 ),
(8480, 2,10185.1748, 2334.716, 1327.782,0, 0, 0, 0, 100, 0 ),
(8480, 3,10181.2001, 2315.397, 1327.723,0, 0, 0, 0, 100, 0 ),
(8480, 4,10164.7333, 2285.181, 1328.442,0, 0, 0, 0, 100, 0 ),
(8480, 5,10181.2001, 2315.397, 1327.723,0, 0, 0, 0, 100, 0 ),
(8480, 6,10185.1748, 2334.716, 1327.782,0, 0, 0, 0, 100, 0 ),
(8480, 7,10172.0996, 2343.780, 1328.060,0, 0, 0, 0, 100, 0 ),
(8470, 1,10100.099, 2388.800, 1316.569946, 0, 0, 0, 0, 100, 0 ),
(8470, 2,10121.900, 2374.342, 1318.431152, 0, 0, 0, 0, 100, 0 ),
(8470, 3,10166.228, 2368.017, 1324.787354, 0, 0, 0, 0, 100, 0 ),
(8470, 4,10192.646, 2381.200, 1326.913574, 0, 0, 0, 0, 100, 0 ),
(8470, 5,10226.791, 2410.366, 1330.347168, 0, 0, 0, 0, 100, 0 ),
(8470, 6,10192.646, 2381.200, 1326.913574, 0, 0, 0, 0, 100, 0 ),
(8470, 7,10166.228, 2368.017, 1324.787354, 0, 0, 0, 0, 100, 0 ),
(8470, 8,10121.900, 2374.342, 1318.431152, 0, 0, 0, 0, 100, 0 ),
(8470, 9,10100.099, 2388.800, 1316.569946, 0, 0, 0, 0, 100, 0 ),
(8490, 1,10227.400, 2399.56, 1329.719, 0, 0, 0, 0, 100, 0 ),
(8490, 2,10263.773, 2383.90, 1332.873, 0, 0, 0, 0, 100, 0 ),
(8490, 3,10296.409, 2368.56, 1331.235, 0, 0, 0, 0, 100, 0 ),
(8490, 4,10348.800, 2381.83, 1329.645, 0, 0, 0, 0, 100, 0 ),
(8490, 5,10296.409, 2368.56, 1331.235, 0, 0, 0, 0, 100, 0 ),
(8490, 6,10263.773, 2383.90, 1332.873, 0, 0, 0, 0, 100, 0 ),
(8490, 7,10227.400, 2399.56, 1329.719, 0, 0, 0, 0, 100, 0 ),
(8540, 1, 10017.647, 1984.034, 1353.317, 0, 0, 0, 0, 100, 0 ),
(8540, 2, 9955.4651, 1984.927, 1353.317, 0, 0, 0, 0, 100, 0 ),
(3121150, 1, 10097.470, 2531.020, 1386.946, 0, 0, 0, 1, 100, 0 ),
(3121150, 2, 10026.932, 2634.012, 1370.469, 0, 0, 0, 1, 100, 0 ),
(3121150, 3, 10026.932, 2634.012, 1370.469, 0, 0, 0, 1, 100, 0 ),
(3121150, 4, 9800.4414, 2311.641, 1404, 0, 0, 0, 1, 100, 0 ),
(3121150, 5, 9960.3701, 2370.479, 1389.53, 0, 0, 0, 1, 100, 0 ),
(3120140, 1, 10117.139, 2486.552, 1348.284, 0, 0, 0, 1, 100, 0 ), 
(3120140, 2, 10221.493, 2416.681, 1374.043, 0, 0, 0, 1, 100, 0 ), 
(3120140, 3, 10127.816, 2258.413, 1386.260, 0, 0, 0, 1, 100, 0 ), 
(3120140, 4, 9894.2607, 2418.199, 1365.337, 0, 0, 0, 1, 100, 0 ), 
(3120140, 5, 9927.1865, 2597.109, 1361.576, 0, 0, 0, 1, 100, 0 ), 
(3120140, 6, 9955.2392, 2560.753, 1347.116, 0, 0, 0, 1, 100, 0 ), 
(3120140, 7, 10008.200, 2566.360, 1341.739, 0, 0, 0, 1, 100, 0 ),
(3119880, 1, 10153.196, 2617.701, 1359.432, 0, 0, 0, 1, 100, 0 ),
(3119880, 2, 10209.633, 2662.427, 1365.508, 0, 0, 0, 1, 100, 0 ),
(3119880, 3, 10182.389, 2718.963, 1360.894, 0, 0, 0, 1, 100, 0 ),
(3119880, 4, 10061.237, 2722.891, 1358.320, 0, 0, 0, 1, 100, 0 ),
(3119880, 5, 9917.8017, 2662.938, 1374.563, 0, 0, 0, 1, 100, 0 ),
(3119880, 6, 9749.5791, 2529.887, 1382.734, 0, 0, 0, 1, 100, 0 ),
(3119880, 7, 9929.2558, 2413.392, 1368.376, 0, 0, 0, 1, 100, 0 ),
(3119880, 8, 10111.625, 2505.268, 1377.637, 0, 0, 0, 1, 100, 0 ),
(3119880, 9, 10140.299, 2551.620, 1351.890, 0, 0, 0, 1, 100, 0 ),
(3119160, 1, 10006.700, 2410.917, 1361.761, 0, 0, 0, 1, 100, 0 ),
(3119160, 2, 10051.864, 2296.167, 1370.381, 0, 0, 0, 1, 100, 0 ),
(3119160, 3, 10187.174, 2298.910, 1396.856, 0, 0, 0, 1, 100, 0 ),
(3119160, 4, 10261.478, 2330.400, 1405.963, 0, 0, 0, 1, 100, 0 ),
(3119160, 5, 10234.970, 2383.418, 1393.465, 0, 0, 0, 1, 100, 0 ),
(3119160, 6, 10184.000, 2415.550, 1371.170, 0, 0, 0, 1, 100, 0 ),
(3120090, 1, 9729.057, 2581.711, 1375.611, 0, 0, 0, 1, 100, 0 ),
(3120090, 2, 9712.633, 2489.878, 1372.298, 0, 0, 0, 1, 100, 0 ),
(3120090, 3, 9627.213, 2418.566, 1384.625, 0, 0, 0, 1, 100, 0 ),
(3120090, 4, 9641.666, 2389.366, 1386.166, 0, 0, 0, 1, 100, 0 ),
(3120090, 5, 9725.690, 2424.249, 1384.370, 0, 0, 0, 1, 100, 0 ),
(3120090, 6, 9765.587, 2536.229, 1384.585, 0, 0, 0, 1, 100, 0 ),
(3120090, 7, 9830.080, 2598.350, 1382.410, 0, 0, 0, 1, 100, 0 ),
(3119260, 1, 10157.063, 2614.138, 1358.511, 0, 0, 0, 1, 100, 0 ),
(3119260, 2, 10286.864, 2528.797, 1375.039, 0, 0, 0, 1, 100, 0 ),
(3119260, 3, 10122.522, 2268.789, 1379.146, 0, 0, 0, 1, 100, 0 ),
(3119260, 4, 9887.8554, 2229.974, 1375.376, 0, 0, 0, 1, 100, 0 ),
(3119260, 5, 9813.0810, 2453.125, 1384.103, 0, 0, 0, 1, 100, 0 ),
(3119260, 6, 10079.196, 2452.313, 1386.352, 0, 0, 0, 1, 100, 0 ),
(3119260, 7, 10094.000, 2384.669, 1355.890, 0, 0, 0, 1, 100, 0 ),
(3117920, 1, 10185.937, 2405.571, 1395.253, 0, 0, 0, 1, 100, 0 ),
(3117920, 2, 10135.073, 2486.207, 1387.954, 0, 0, 0, 1, 100, 0 ),
(3117920, 3, 9771.2285, 2495.108, 1383.249, 0, 0, 0, 1, 100, 0 ),
(3117920, 4, 9717.3242, 2436.951, 1386.709, 0, 0, 0, 1, 100, 0 ),
(3117920, 5, 9687.7021, 2312.072, 1389.124, 0, 0, 0, 1, 100, 0 ),
(3117920, 6, 9882.2304, 2187.540, 1412.660, 0, 0, 0, 1, 100, 0 );

DELETE FROM `creature_addon` WHERE `guid` IN (312115, 312014, 311988, 311916, 312009, 311926, 311792);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`,`bytes2`,`path_id`,`auras`) VALUES
(312115,22470,0,1,3121150,''),
(312014,22470,0,1,3120140,''),
(311988,22470,0,1,3119880,''),
(311916,22470,0,1,3119160,''),
(312009,22470,0,1,3120090,''),
(311926,22470,0,1,3119260,''),
(311792,22470,0,1,3117920,'');

UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (312115, 312014, 311988, 311916, 312009, 311926, 311792);
DELETE FROM `creature_formations` WHERE `leaderGUID`=312115;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(312115, 312115, 0, 0, 2, 0, 0),
(312115, 312123, 6, 90, 2, 0, 0),
(312115, 312112, 6, 270, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=312014;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(312014, 312014, 0, 0, 2, 0, 0),
(312014, 312019, 6, 90, 2, 0, 0),
(312014, 312018, 6, 270, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=311988;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(311988, 311988, 0, 0, 2, 0, 0),
(311988, 311990, 6, 90, 2, 0, 0),
(311988, 311960, 6, 270, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=311916;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(311916, 311916, 0, 0, 2, 0, 0),
(311916, 311918, 6, 90, 2, 0, 0);

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='', `Flags_Extra`=0 WHERE `entry` IN (@ENTRY, 3568);
DELETE FROM `creature_text` WHERE `entry` IN (3519, 3568);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(3519,0,0,"Mist! I feared I would never see you again! Yes, I am well, do not worry for me. You must rest and recover your health.",12,7,100,0,0,0, 'Sentinel Arynia Cloudsbreak', 1330),
(3568,0,0,"%s growls in acknowledgement before straightening and making her way off into the forest.",16,0,100,0,0,0, 'Mist', 1340);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3568) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (356800, 356801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3568,0,0,0,19,0,100,0,938,0,0,0,80,356800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - On Quest Accepted- Action list"),
(356800,9,0,0,0,0,100,0,0,0,0,0,64,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mist - Actionlist - Store target"),
(356800,9,1,0,0,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Remove  unit flag"),
(356800,9,2,0,0,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - React def"),
(356800,9,3,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - remove npcflag"),
(356800,9,4,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mist - Actionlist - Start follow"),
(356800,9,5,0,0,0,100,0,540000,540000,0,0,6,928,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mist - Actionlist - Quest fail"),
(356800,9,6,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Despawn"),
(3568,0,1,0,75,0,100,1,0,3519,4,0,80,356801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Creature distance- Action list"),
(356801,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Root"),
(356801,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,3519,20,0,0,0,0,0,"Mist - Actionlist - Say text1"),
(356801,9,2,0,0,0,100,0,2000,2000,0,0,15,938,0,0,0,0,0,12,0,0,0,0,0,0,0,"Mist - Actionlist - CALL_AREAEXPLOREDOREVENTHAPPENS"),
(356801,9,3,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Say text1"),
(356801,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist - Actionlist - Despawn"),
(3568,0,2,0,6,0,100,0,0,0,0,0,6,938,0,0,0,0,0,12,0,0,0,0,0,0,0,'Mist - On Death - Fail Quest'),
(3568,0,3,4,11,0,100,0,0,0,0,0,2,80,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mist - On Respawn - Set faction'),
(3568,0,4,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mist - On Respawn - React passif');

DELETE FROM `spell_scripts` WHERE `id` IN (65797, 66166);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(65797,0,0,15,65822,0,0,0,0,0,0),
(66166,0,0,14,65602,0,0,0,0,0,0);

DELETE FROM `spell_area` WHERE `spell` IN (65602) AND `area` IN (478, 261);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(65602, 478, 14005, 0, 0, 0, 2, 1, 10, 0),
(65602, 261, 14005, 0, 0, 0, 2, 1, 10, 0);

UPDATE `creature_template` SET `unit_flags`=33280, `AIName`="SmartAI" WHERE `entry` IN (34517, 34530);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34517, 34530) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34517,0,0,0,0,0,100,0,1000,3000,5000,7000,11,65837,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ally of Nature - IC  - Cast Vine Lash"),
(34517,0,1,0,0,0,100,0,8000,10000,9000,12000,11,65605,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ally of Nature - IC  - Cast Bursting Seed"),
(34517,0,2,0,0,0,100,0,4000,5000,8000,12000,11,34745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ally of Nature - IC  - Cast Shoot Thorns"),
(34530,0,0,0,0,0,100,0,1000,3000,5000,7000,11,62245,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ally of Nature - IC  - Cast Vine Lash");

-- Add deleted data
DELETE FROM `spell_area` WHERE `spell` IN (49417, 49416) AND `area` IN (2481, 4521, 154, 4206, 4537);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(49416, 2481, 28000, 0, 0, 0, 2, 1, 64, 0),
(49416, 4521, 13364, 13364, 0, 0, 2, 1, 74, 11),
(49416, 4521, 13403, 13403, 0, 0, 2, 1, 74, 11),
(49417, 154, 24970, 24971, 0, 16, 2, 1, 66, 11),
(49417, 4206, 12431, 0, 0, 0, 2, 1, 64, 11),
(49417, 4537, 13304, 13304, 0, 690, 2, 1, 11, 11),
(49417, 4537, 13393, 13393, 0, 1101, 2, 1, 11, 11);
