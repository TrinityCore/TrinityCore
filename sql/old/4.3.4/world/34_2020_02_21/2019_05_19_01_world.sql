-- Fix Quest 27950 "Gobbles!"

-- Add missing gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN 203038 AND 203046;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`phaseMask`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`ScriptName`,`VerifiedBuild`) VALUES
(203038,206572,1,0,0,1,0,1,312,0,-1,-10690.65,924.967,26.63605,3.351047,0,0,-0.9945211,0.1045355,120,255,1, '', 0),
(203039,206571,1,0,0,1,0,1,312,0,-1,-10689.2,926.821,26.4897,5.759588,0,0,-0.2588186,0.9659259,120,255,1, '', 0),
(203040,206571,1,0,0,1,0,1,312,0,-1,-10688.24,925.1094,26.46245,4.852017,0,0,-0.6560583,0.7547102,120,255,1, '', 0),
(203041,206571,1,0,0,1,0,1,312,0,-1,-10691,927.444,26.5564,0.05235888,0,0,0.02617645,0.9996573,120,255,1, '', 0),
(203042,206571,1,0,0,1,0,1,312,0,-1,-10688.82,923.2153,26.49851,3.996807,0,0,-0.9099607,0.4146944,120,255,1, '', 0),
(203043,206571,1,0,0,1,0,1,312,0,-1,-10692.7,926.51,26.6309,0.8901166,0,0,0.4305105,0.9025856,120,255,1, '', 0),
(203044,206571,1,0,0,1,0,1,312,0,-1,-10690.58,922.3333,26.57419,3.054327,0,0,0.9990482,0.04361926,120,255,1, '', 0),
(203045,206571,1,0,0,1,0,1,312,0,-1,-10693.21,924.6493,26.66352,1.588249,0,0,0.7132502,0.7009096,120,255,1, '', 0),
(203046,206571,1,0,0,1,0,1,312,0,-1,-10692.2,922.896,26.6352,2.426008,0,0,0.9366722,0.3502074,120,255,1, '', 0);

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN 203038 AND 203046;
INSERT INTO `gameobject_addon` (`guid`,`parent_rotation3`,`invisibilityType`,`invisibilityValue`) VALUES
(203038,1,7,1000),(203039,1,7,1000),(203040,1,7,1000),(203041,1,7,1000),(203042,1,7,1000),(203043,1,7,1000),(203044,1,7,1000),(203045,1,7,1000),(203046,1,7,1000);

-- Commander Schnottz SAI
SET @ENTRY := 47159;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,12213,0,0,0,0,11,88107,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Schnottz - Gossip Option Select - Cast 'Gobbles Initialize'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Schnottz - Gossip Option Select - Close Gossip");

-- Commander Schnottz SAI
SET @ENTRY := 47249;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (472490,472491,472492,472493,472494,472495,472496) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,0,44,312,1,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Just Summoned - Set InGame Phase"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Schnottz - Just Summoned - TurnTo Summoner"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,0,80,472490,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Just Summoned - Run Script"),
(@ENTRY,0,3,0,58,0,100,0,2,472490,0,0,0,80,472491,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Run Script"),
(@ENTRY,0,4,0,58,0,100,0,1,472491,0,0,0,80,472492,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Run Script"),
(@ENTRY,0,5,0,58,0,100,0,1,472492,0,0,0,80,472493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Run Script"),
(@ENTRY,0,6,0,58,0,100,0,1,472493,0,0,0,80,472494,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Run Script"),
(@ENTRY,0,7,0,58,0,100,0,2,472494,0,0,0,80,472495,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Run Script"),
(@ENTRY,0,8,0,58,0,100,0,1,472495,0,0,0,80,472496,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Run Script"),
(@ENTRY,0,9,10,58,0,100,0,1,472496,0,0,0,11,88128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Cast 'Clean-up Ping'"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,0,11,88143,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Cast 'Clean-up'"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - End Of Path - Despawn"),
(472490,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 0"),
(472490,9,1,0,0,0,100,0,2000,2000,0,0,0,53,0,472490,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472490"),
(472491,9,0,0,0,0,100,0,0,0,0,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Play Emote"),
(472491,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 1"),
(472491,9,2,0,0,0,100,0,1000,1000,0,0,0,53,0,472491,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472491"),
(472492,9,1,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 2"),
(472492,9,2,0,0,0,100,0,1000,1000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Kneel"),
(472492,9,3,0,0,0,100,0,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Set Emotestate"),
(472492,9,4,0,0,0,100,0,3000,3000,0,0,0,5,21,0,0,0,0,0,11,47251,10,1,0,0,0,0,"Commander Schnottz - Script - Target Play Emote 'OneShotApplaud'"),
(472492,9,5,0,0,0,100,0,1000,1000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Stand"),
(472492,9,6,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Set Emotestate"),
(472492,9,7,0,0,0,100,0,0,0,0,0,0,11,88116,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Cast 'Creator Summon Gobbles'"),
(472492,9,8,0,0,0,100,0,2000,2000,0,0,0,53,0,472492,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472492"),
(472493,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.869469,"Commander Schnottz - Script - TurnTo"),
(472493,9,1,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 3"),
(472493,9,2,0,0,0,100,0,4000,4000,0,0,0,11,88121,2,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Cast 'Schnottz Ping'"),
(472493,9,3,0,0,0,100,0,0,0,0,0,0,11,88118,0,0,0,0,0,11,47255,10,1,0,0,0,0,"Commander Schnottz - Script - Cast 'Fire LPAC at Gobbles'"),
(472493,9,4,0,0,0,100,0,8000,8000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 4"),
(472493,9,5,0,0,0,100,0,2000,2000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 5"),
(472493,9,6,0,0,0,100,0,0,0,0,0,0,53,0,472493,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472493"),
(472494,9,0,0,0,0,100,0,1000,1000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Kneel"),
(472494,9,1,0,0,0,100,0,4000,4000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 6"),
(472494,9,2,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Stand"),
(472494,9,3,0,0,0,100,0,0,0,0,0,0,53,0,472494,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472494"),
(472495,9,0,0,0,0,100,0,3000,3000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 7"),
(472495,9,1,0,0,0,100,0,3000,3000,0,0,0,53,1,472495,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472495"),
(472496,9,0,0,0,0,100,0,3000,3000,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 8"),
(472496,9,1,0,0,0,100,0,4000,4000,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 9"),
(472496,9,2,0,0,0,100,0,4000,4000,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 10"),
(472496,9,3,0,0,0,100,0,3000,3000,0,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Say 11"),
(472496,9,4,0,0,0,100,0,0,0,0,0,0,11,88127,2,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Cast 'Kill Credit'"),
(472496,9,5,0,0,0,100,0,6000,6000,0,0,0,53,0,472496,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Schnottz - Script - Load Path 472496");

DELETE FROM `waypoints` WHERE `entry` IN (472490,472491,472492,472493,472494,472495,472496);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(472490,1,-10684,930.243,26.2597, 'Commander Schnottz'),
(472490,2,-10684.4,932.252,26.26217, 'Commander Schnottz'),
(472491,1,-10690.6,925.205,26.55584, 'Commander Schnottz'),
(472492,1,-10692.4,930.745,26.59044, 'Commander Schnottz'),
(472493,1,-10691,925.96,26.56671, 'Commander Schnottz'),
(472494,1,-10684.4,929.488,26.28065, 'Commander Schnottz'),
(472494,2,-10684.4,932.471,26.26071, 'Commander Schnottz'),
(472495,1,-10687.5,927.516,26.41711, 'Commander Schnottz'),
(472496,1,-10676.04,927.8622,26.31276, 'Commander Schnottz');

DELETE FROM `creature_text` WHERE `CreatureID`=47249;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(47249, 0, 0, 'Very vell, zhen. Let me just check my notes vone lasht time...', 12, 0, 100, 396, 0, 0, 47381, 'Commander Schnottz'),
(47249, 1, 0, 'Mmm-hmmm, yes, yes... simple enough...', 12, 0, 100, 396, 0, 0, 47382, 'Commander Schnottz'),
(47249, 2, 0, 'Oh, Gobbles! Ve''re ready to begin! Come, come!', 14, 0, 100, 22, 0, 0, 47383, 'Commander Schnottz'),
(47249, 3, 0, 'Text: Hold on, Gobbles! Shtand back everyvone!', 12, 0, 100, 22, 0, 0, 47385, 'Commander Schnottz'),
(47249, 4, 0, 'VHAT!?', 14, 0, 100, 388, 0, 0, 47388, 'Commander Schnottz'),
(47249, 5, 0, 'My poor Gobbles...', 12, 0, 100, 0, 0, 0, 47395, 'Commander Schnottz'),
(47249, 6, 0, 'Vhat could haf possibly gone vrong? I followed every lasht detail...', 14, 0, 100, 22, 0, 0, 47389, 'Commander Schnottz'),
(47249, 7, 0, 'Vait a shekkont! Vhat''s zhis!?', 12, 0, 100, 6, 0, 0, 47390, 'Commander Schnottz'),
(47249, 8, 0, 'You only brought me eight idols!', 14, 0, 100, 397, 0, 0, 47391, 'Commander Schnottz'),
(47249, 9, 0, 'Zhe ritual shpecifically calls for NINE!!', 14, 0, 100, 0, 0, 0, 47392, 'Commander Schnottz'),
(47249, 10, 0, 'NINE! NINE! NINE! NINE! NINE!!!', 14, 0, 100, 5, 0, 0, 47393, 'Commander Schnottz'),
(47249, 11, 0, 'Out of my sight, vizh you! Auch...', 14, 0, 100, 18, 0, 0, 47394, 'Commander Schnottz');

-- Gobbles SAI
SET @ENTRY := 47255;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*10) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Gobbles - OOC - Load Path 'No Repeat'"),
(@ENTRY,0,1,0,58,0,100,0,7,@ENTRY,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.710423,"Gobbles - End Of Path - TurnTo"),
(@ENTRY,0,2,0,8,0,100,0,88119,0,0,0,0,80,@ENTRY*10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gobbles - Spellhit - Run Script"),
(@ENTRY,0,3,0,8,0,100,0,88128,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gobbles - Spellhit - despawn"),
(@ENTRY*10,9,0,0,0,0,100,0,1000,1000,0,0,0,11,35426,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gobbles - Script - Cast 'Arcane Explosion Visual'"),
(@ENTRY*10,9,1,0,0,0,100,0,0,0,0,0,0,11,29266,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gobbles - Script - Cast 'Permanent Feign Death'"),
(@ENTRY*10,9,2,0,0,0,100,0,0,0,0,0,0,3,0,21774,0,0,0,0,1,0,0,0,0,0,0,0,"Gobbles - Script - Set Model");

-- Gobbles Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (47255);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(47255,1,-10676.5,940.067,25.52802, 'Gobbles'),
(47255,2,-10676,938.067,26.52802, 'Gobbles'),
(47255,3,-10676,937.567,26.52802, 'Gobbles'),
(47255,4,-10675,933.067,26.52802, 'Gobbles'),
(47255,5,-10674.75,932.067,26.52802, 'Gobbles'),
(47255,6,-10681,925.317,26.27802, 'Gobbles'),
(47255,7,-10690.7,924.821,26.5624, 'Gobbles');

-- Belloc Brightblade SAI
SET @ENTRY := 47251;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,0,44,312,1,0,0,0,0,1,0,0,0,0,0,0,0,"Belloc Brightblade - Just Summoned - Set InGame Phase"),
(@ENTRY,0,1,0,8,0,100,0,88128,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Belloc Brightblade - Spellhit - despawn");

-- Condition for source Gossip menu condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=12213 AND `SourceEntry`=17153 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 12213, 17153, 0, 0, 8, 0, 27950, 0, 0, 1, 0, 0, '', 'Show gossip menu 12213 text id 17153 if quest Gobbles! has been rewarded.');

-- Condition for source Gossip menu option condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12213 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12213, 0, 0, 0, 9, 0, 27950, 0, 0, 0, 0, 0, '', 'Show gossip menu 12213 option id 0 if quest Gobbles! is taken');

DELETE FROM `gossip_menu_option` WHERE `MenuID`=12213;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`VerifiedBuild`) VALUES
(12213,0,0, 'The perimeter is secure, commander.', 47376, 1, 1, 14333);

-- Quest "Make Yourself Useful" requires "Gobbles!"
UPDATE `quest_template_addon` SET `PrevQuestID`=27950 WHERE `ID`=27969;

-- Quest "Crisis Management" requires "Make Yourself Useful"
DELETE FROM `quest_template_addon` WHERE `ID` IN (28002);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`,`ProvidedItemCount`) VALUES  (28002,27969,0);

-- Quest "Battlezone" requires "Crisis Management"
DELETE FROM `quest_template_addon` WHERE `ID` IN (27990);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`,`ProvidedItemCount`) VALUES  (27990,28002,0);

-- Fix Spawns
UPDATE `creature_template` SET `unit_class`=2, `unit_flags`=768 WHERE `entry` IN (47249);
UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=768 WHERE `entry` IN (47251);

-- Add Spell Script
DELETE FROM `spell_script_names` WHERE `spell_id`=88107;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (88107, 'spell_gobbles_initialize');

-- Add Spell Script
DELETE FROM `spell_script_names` WHERE `spell_id`=88108;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (88108, 'spell_summon_schnottz');

-- Add Spell Script for Spell Creator Summon Gobbles
DELETE FROM `spell_scripts` WHERE `id`=88116;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(88116,0,0,15,88112,2,0,0,0,0,0),
(88116,0,0,15,88117,2,0,0,0,0,0);

-- Add Spell Script for Spell Clean-up
DELETE FROM `spell_scripts` WHERE `id`=88143;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(88143,0,0,14,88144,0,0,0,0,0,0),
(88143,0,0,14,88112,0,0,0,0,0,0),
(88143,0,0,14,88111,0,0,0,0,0,0);

-- Fix spell target position for Spell Summon Ve'vah
DELETE FROM `spell_target_position` WHERE `ID`=88109;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(88109,0,1,-10694.4,932.092,26.74553,5.427974,0);

-- You need to see Gobbles until this quest is done. Add Spell See Quest Invis 10 to Area Schnottz's Landing
DELETE FROM `spell_area` WHERE `spell`=88144;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(88144,5602,0,27950,0,0,2,1,64,9);

-- Add Quest reward text for Quest Gobbles!
DELETE FROM `quest_offer_reward` WHERE `ID`=27950;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`,`Emote2`,`RewardText`) VALUES
(27950, 0, 0, 'That was probably not the transformation Schnottz was hoping for...');
