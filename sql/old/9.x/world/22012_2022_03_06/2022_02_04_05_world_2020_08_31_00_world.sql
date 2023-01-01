--
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (24514,24515);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-114324,-114325,24514) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2451400,2451401) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-114324,0,0,0,38,0,100,0,1,1,0,0,0,53,1,2451501,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spotted Hippogryph Hatchling - On Data Set 1 1 - Start Waypoint"),
(-114325,0,0,0,38,0,100,0,1,1,0,0,0,53,1,2451502,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spotted Hippogryph Hatchling - On Data Set 1 1 - Start Waypoint"),
(-114324,0,1,0,38,0,100,0,2,2,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spotted Hippogryph Hatchling - On Data Set 2 2 - Evade"),
(-114325,0,1,0,38,0,100,0,2,2,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Spotted Hippogryph Hatchling - On Data Set 2 2 - Evade"),

(24514,0,0,1,8,0,100,0,43969,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Steelfeather - On Spellhit 'Feathered Charm' - Store Targetlist"),
(24514,0,1,2,61,0,100,0,0,0,0,0,0,127,2,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steelfeather - On Link - Pause Movement"),
(24514,0,2,0,61,0,100,0,0,0,0,0,0,53,1,24514,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steelfeather - On Link - Start Waypoint"),
(24514,0,3,0,40,0,100,0,1,24514,0,0,0,80,2451400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steelfeather - On Waypoint 1 Reached  - Run Script"),
(24514,0,4,0,40,0,100,0,2,24514,0,0,0,80,2451401,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steelfeather - On Waypoint 2 Reached  - Run Script"),

(2451400,9,0,0,0,0,100,0,0,0,0,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steelfeather - On Script - Pause Waypoint"),
(2451400,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.94444,"Steelfeather - On Script - Set Orientation"),
(2451400,9,2,0,0,0,100,0,5000,5000,0,0,0,45,1,1,0,0,0,0,9,24515,0,20,0,0,0,0,0,"Steelfeather - On Script - Set Data 1 1 (Spotted Hippogryph Hatchling)"),
(2451400,9,3,0,0,0,100,0,5000,5000,0,0,0,45,2,2,0,0,0,0,9,24515,0,20,0,0,0,0,0,"Steelfeather - On Script - Set Data 2 2 (Spotted Hippogryph Hatchling)"),
(2451400,9,4,0,0,0,100,0,1000,1000,0,0,0,11,43984,2,0,0,0,0,12,1,0,0,0,0,0,0,0,"Steelfeather - On Script - Cast 'Steelfeather Quest Credit"),
-- We just need to evade him after aura fades
(2451401,9,0,0,0,0,100,0,1000,1000,0,0,0,28,43968,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Steelfeather - On Script - Remove Aura 'Feathered Charm'"),
(2451401,9,1,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steelfeather - On Script - Evade");

DELETE FROM `waypoints` WHERE `entry` IN (24514,2451501,2451502);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 
(24514,1,2575.582,-5219.65,375.2497,"Steelfeather"),
(24514,2,2470.353,-5202.818,349.8742,"Steelfeather"),
(2451501,1,2575.237,-5223.781,374.644,"Spotted Hippogryph Hatchling"),
(2451502,1,2573.845,-5222.854,374.2438,"Spotted Hippogryph Hatchling");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 43969;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,43969,0,0,31,1,3,24514,0,0,0,0,"","Group 0: Spell 'Feathered Charm' targets creature 'Steelfeather'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (24131,24139);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24131,24139) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2413100,2413900) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- https://youtu.be/jPpXC8mT6VY?t=231
(24131,0,0,0,20,0,100,0,11292,0,0,0,0,80,2413100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trapper Jethan - On Quest 'Preying Upon the Weak' Finished - Run Script"),

(2413100,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,24139,0,0,0,0,0,0,0,"Trapper Jethan - On Script - Set Orientation Closest Creature 'Gil Grisert'"), -- 22:00:44.190
(2413100,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trapper Jethan - On Script - Say Line 0"), -- 22:00:44.205
(2413100,9,2,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,19,24139,0,0,0,0,0,0,0,"Trapper Jethan - On Script - Say Line 0 (Gil Grisert)"), -- 22:00:50.586
(2413100,9,3,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,19,24139,0,0,0,0,0,0,0,"Trapper Jethan - On Script - Say Line 1 (Gil Grisert)"), -- 22:00:55.234
(2413100,9,4,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trapper Jethan - On Script - Say Line 1"), -- 22:01:01.178
(2413100,9,5,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trapper Jethan - On Script - Set Orientation Home Position"), -- 22:01:05.952
-- https://youtu.be/506zDg3DAio?t=92
(24139,0,0,0,20,0,100,0,11418,0,0,0,0,80,2413900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gil Grisert - On Quest 'We Call Him Steelfeather' Finished - Run Script"), -- 22:02:09.818

(2413900,9,0,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gil Grisert - On Script - Say Line 2"), -- 22:02:09.818
(2413900,9,1,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,19,24131,0,0,0,0,0,0,0,"Gil Grisert - On Script - Say Line 2 (Trapper Jethan)"), -- 22:02:14.530
(2413900,9,2,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,19,24131,0,0,0,0,0,0,0,"Gil Grisert - On Script - Set Orientation Closest Creature 'Trapper Jethan'"), -- 22:02:18.149
(2413900,9,3,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gil Grisert - On Script - Say Line 3"), -- 22:02:18.289
(2413900,9,4,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,19,24131,0,0,0,0,0,0,0,"Gil Grisert - On Script - Say Line 3 (Trapper Jethan)"), -- 22:02:20.723
(2413900,9,5,0,0,0,100,0,5000,5000,0,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gil Grisert - On Script - Play Emote 274"), -- 22:02:26.557
(2413900,9,6,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gil Grisert - On Script - Set Orientation Home Position"); -- 22:02:26.557

DELETE FROM `creature_text` WHERE `CreatureID` IN (24131,24139);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24131,0,0,"Hey, Gil, you give my offer any more thought? I'll have plenty of skins and preserved meat to trade for those heavy yeti furs or down your men are working with.",12,0,100,1,0,0,22937,0,"Trapper Jethan"),
(24131,1,0,"I'll be lookin' forward to it. Guess I'll get to preserving this meat, then. A good quartermaster won't turn down a reliable supply of rations.",12,0,100,1,0,0,22940,0,"Trapper Jethan"),
(24131,2,0,"Why not? Just think how much better it'll look with the hatchlings to either side --",12,0,100,6,0,0,23549,0,"Trapper Jethan"),
(24131,3,0,"What? I'm just sayin' that's how we do things in Grizzly Hills.",12,0,100,1,0,0,23551,0,"Trapper Jethan"),
(24139,0,0,"Much as I'd like to do business with you, Jethan, all this stuff is the property of the Alliance expeditionary forces.",12,0,100,274,0,0,22938,0,"Gil Grisert"),
(24139,1,0,"Maybe after everything dies down, you and I can make a deal with some of the surplus. I'm sure the troops will give your people plenty of business as they head into the Grizzly Hills.",12,0,100,1,0,0,22939,0,"Gil Grisert"),
(24139,2,0,"Y'hear that, Jethan? You're not getting that Steelfeather trophy now that we know she's a mother.",12,0,100,1,0,0,23548,0,"Gil Grisert"),
(24139,3,0,"Jethan!",12,0,100,25,0,0,23550,0,"Gil Grisert");
