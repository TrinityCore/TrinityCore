-- Quest "Rescue From Jaedenar"
UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=5203; -- Prevents quest from auto completing
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=176306; -- Players should not be able to open the cage

DELETE FROM `gossip_menu` WHERE `MenuID`=3129;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(3129,3865,0),
(3129,4113,0),
(3129,4114,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=3129;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=11016;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,3129,4113,0,0,8,0,5202,0,0,0,0,0,'',"Captured Arko\'narin - Show Gossip Menu Text 3129 if Quest 4113 is rewarded"),
(14,3129,4114,0,0,8,0,5203,0,0,0,0,0,'',"Captured Arko\'narin - Show Gossip Menu Text 4114 if Quest 5203 is rewarded"),
(22,28,11016,0,0,29,1,11141,100,0,1,0,0,'',"Captured Arko\'narin - Execute SAI 27 only if not within 100 yards of Spirit of Trey Lightforge");

DELETE FROM `creature_text` WHERE `CreatureID` IN (11016, 11141);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11016,0,0,"I'm ready, $n. Let\'s find my equipment and get out of here. I think I know where it is.",12,0,100,1,0,0,6433,0,"Captured Arko\'narin"),
(11016,1,0,"We've failed, $n!!",12,0,100,0,0,0,6434,0,"Captured Arko\'narin"),
(11016,2,0,"Oh my! Look at this... all these candles. I\'m sure they\'re used for some terrible ritual or dark summoning. We best make haste!",12,0,100,5,0,0,6456,0,"Captured Arko\'narin"),
(11016,3,0,"There! Over there!",12,0,100,25,0,0,6457,0,"Captured Arko\'narin"),
(11016,4,0,"All I need now is a golden lasso.",12,0,100,15,0,0,6458,0,"Captured Arko\'narin"),
(11016,5,0,"Let\'s get out of here, $n. I'm ready now!",12,0,100,0,0,0,6459,0,"Captured Arko\'narin"),
(11016,6,0,"DIE, DEMON DOGS!",12,0,100,0,0,0,6460,0,"Captured Arko\'narin"),
(11016,7,0,"Ah! Fresh air at last! I never thought I\'d see the day...",12,0,100,4,0,0,6461,0,"Captured Arko\'narin"),
(11016,8,0,"What was that?! Trey? TREY!?",12,0,100,5,0,0,6463,0,"Captured Arko\'narin"),
(11016,9,0,"NO! What have they done to you!?",12,0,100,0,0,0,6467,0,"Captured Arko\'narin"),
(11016,10,0,"No! My friend... what\'s happened? This is all my fault...",12,0,100,18,0,0,6468,0,"Captured Arko\'narin"),
(11016,11,0,"I can travel faster on my own from here, $n. Meet Jessir Moonbow near Ashenvale. She should be with the druids of the Emerald Circle. She\'ll tell you what to do next. Thank you so much for your help!",12,0,100,1,0,0,6469,0,"Captured Arko\'narin"),
(11016,12,0,"You will not stop me from escaping here, $r!",12,0,100,0,0,0,6801,0,"Captured Arko\'narin"),
(11016,12,1,"You kept me in that cell for too long, monster!",12,0,100,0,0,0,6802,0,"Captured Arko\'narin"),
(11016,12,2,"You will pay for what you've done to Trey!",12,0,100,0,0,0,6803,0,"Captured Arko\'narin"),
(11141,0,0,"BETRAYER!",14,0,100,0,0,0,6466,0,"Spirit of Trey Lightforge");

-- Captured Arko'narin
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=0 WHERE `entry`=11016;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11016 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11016,0,0,1,19,0,100,0,5203,0,0,0,53,0,11016,0,0,0,2,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Quest \'Rescue From Jaedenar\' Taken - Start Waypoint"),
(11016,0,1,2,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,48840,176306,0,0,0,0,0,"Captured Arko\'narin - On Quest \'Rescue From Jaedenar\' Taken - Activate Gameobject"),
(11016,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captured Arko\'narin - On Quest \'Rescue From Jaedenar\' Taken - Store Targetlist"),
(11016,0,3,4,61,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Quest \'Rescue From Jaedenar\' Taken - Remove Flag Standstate Kneel"),
(11016,0,4,5,61,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Quest \'Rescue From Jaedenar\' Taken - Remove Npc Flag Questgiver+Gossip"),
(11016,0,5,0,61,0,100,0,0,0,0,0,19,514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Quest \'Rescue From Jaedenar\' Taken - Remove Unit Flag Immune To NPC"),
(11016,0,6,7,40,0,100,0,1,11016,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 1 Reached - Say Line 0"),
(11016,0,7,0,61,0,100,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 1 Reached - Pause Waypoint"),
(11016,0,8,9,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Death - Say Line 1"),
(11016,0,9,0,61,0,100,0,0,0,0,0,6,5203,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Death - Fail Quest \'Rescue From Jaedenar\'"),
(11016,0,10,11,40,0,100,0,15,11016,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 15 Reached - Say Line 2"),
(11016,0,11,0,61,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 15 Reached - Pause Waypoint"),
(11016,0,12,0,40,0,100,0,35,11016,0,0,80,1101600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 35 Reached - Run Script 1"),
(11016,0,13,0,40,0,100,0,39,11016,0,0,80,1101601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 39 Reached - Run Script 2"),
(11016,0,14,0,40,0,100,0,40,11016,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 40 Reached - Set Run Off"),
(11016,0,15,16,40,0,100,0,102,11016,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 102 Reached - Say Line 7"),
(11016,0,16,17,61,0,100,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 102 Reached - Pause Waypoint"),
(11016,0,17,0,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 102 Reached - Set Run On"),
(11016,0,18,19,40,0,100,0,103,11016,0,0,12,11141,3,300000,0,0,0,8,0,0,0,4851.68,-396.316,351.325,0.0431306,"Captured Arko\'narin - On Waypoint 103 Reached - Summon Creature \'Spirit of Trey Lightforge\'"),
(11016,0,19,0,61,0,100,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 103 Reached - Pause Waypoint"),
(11016,0,20,0,40,0,100,0,104,11016,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.27897,"Captured Arko\'narin - On Waypoint 104 Reached - Set Orientation"),
(11016,0,21,0,40,0,100,0,104,11016,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 104 Reached - Pause Waypoint"),
(11016,0,22,0,40,0,100,0,106,11016,0,0,80,1101602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 106 - Run Script 3"),
(11016,0,23,0,40,0,100,0,110,11016,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Waypoint 110 Reached - Despawn"),
(11016,0,24,0,7,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Evade - Remove Flag Standstate Kneel"),
(11016,0,25,0,0,0,100,0,5000,8000,9000,13000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captured Arko\'narin - In Combat - Cast Mortal Strike"),
(11016,0,26,0,9,0,100,0,0,5,12000,15000,11,18819,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captured Arko\'narin - Within 0-5 Range - Cast Holy Cleave"),
(11016,0,27,0,4,0,50,0,0,0,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Aggro - Say Line 12");

-- Captured Arko'narin --> Actionlist 1
DELETE FROM `smart_scripts` WHERE `entryorguid`=1101600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1101600,9,0,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Pause Waypoint"),
(1101600,9,1,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Set Run On"),
(1101600,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.44275,"Captured Arko\'narin - On Script - Set Orientation"),
(1101600,9,3,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Say Line 3");

-- Captured Arko'narin --> Actionlist 2
DELETE FROM `smart_scripts` WHERE `entryorguid`=1101601 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1101601,9,0,0,0,0,100,0,0,0,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Pause Waypoint"),
(1101601,9,1,0,0,0,100,0,1000,1000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Set Flag Standstate Kneel"),
(1101601,9,2,0,0,0,100,0,1000,1000,0,0,9,0,0,0,0,0,0,14,48860,176225,0,0,0,0,0,"Captured Arko\'narin - On Script - Activate Gameobject"),
(1101601,9,3,0,0,0,100,0,3000,3000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Remove Flag Standstate Kneel"),
(1101601,9,4,0,0,0,100,0,1000,1000,0,0,11,18163,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Cast Strength of Arko\'narin"),
(1101601,9,5,0,0,0,100,0,4000,4000,0,0,3,11018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Morph To Arko\'narin"),
(1101601,9,6,0,0,0,100,0,0,0,0,0,71,0,0,13316,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Equip Item"),
(1101601,9,7,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Set Orientation"),
(1101601,9,8,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Say Line 4"),
(1101601,9,9,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Say Line 5"),
(1101601,9,10,0,0,0,100,0,4000,4000,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Summon Group 1"),
(1101601,9,11,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,9862,70,0,0,0,0,0,"Captured Arko\'narin - On Script - Set Data"),
(1101601,9,12,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Say Line 6");

-- Captured Arko'narin --> Actionlist 3
DELETE FROM `smart_scripts` WHERE `entryorguid`=1101602 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1101602,9,0,0,0,0,100,0,0,0,0,0,18,514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Add Unit Flag Immune To NPC"),
(1101602,9,1,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Pause Waypoint"),
(1101602,9,2,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.27897,"Captured Arko\'narin - On Script - Set Orientation"),
(1101602,9,3,0,0,0,100,0,1000,1000,0,0,1,10,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Say Line 10"),
(1101602,9,4,0,0,0,100,0,5000,5000,0,0,1,11,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Say Line 11"),
(1101602,9,5,0,0,0,100,0,2000,2000,0,0,15,5203,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Complete Quest"),
(1101602,9,6,0,0,0,100,0,1000,1000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Arko\'narin - On Script - Play Emote Bow");

-- Spirit of Trey Lightforge
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=770 WHERE `entry`=11141;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11141 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11141,0,0,0,54,0,100,0,0,0,0,0,80,1114100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Trey Lightforge - Just Summoned - Run Script"),
(11141,0,1,0,1,0,100,1,0,0,0,0,11,17695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Trey Lightforge - Out of Combat - Cast Defiling Aura (No Repeat)"),
(11141,0,2,0,9,0,100,0,8,40,3400,4800,11,18164,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spirit of Trey Lightforge - Within 8-40 Range - Cast Shadow Bolt"),
(11141,0,3,0,2,0,100,0,0,40,14000,19000,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Trey Lightforge - Between 0-40% Health - Cast Holy Light");

-- Spirit of Trey Lightforge --> Actionlist 1
DELETE FROM `smart_scripts` WHERE `entryorguid`=1114100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1114100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Trey Lightforge - On Script - Say Line 0"),
(1114100,9,1,0,0,0,100,0,3000,3000,0,0,1,8,0,0,0,0,0,19,11016,0,0,0,0,0,0,"Spirit of Trey Lightforge - On Script - Say Line 8 (Captured Arko\'narin)"),
(1114100,9,2,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,19,11016,0,0,0,0,0,0,"Spirit of Trey Lightforge - On Script - Say Line 9 (Captured Arko\'narin)"),
(1114100,9,3,0,0,0,100,0,0,0,0,0,19,770,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Trey Lightforge - On Script - Remove Unit Flag"),
(1114100,9,4,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,11016,0,0,0,0,0,0,"Spirit of Trey Lightforge - On Script - Start Attack");

-- Jaedenar Legionnaire
DELETE FROM `smart_scripts` WHERE `entryorguid`=9862 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9862,0,1,0,38,0,100,0,1,1,0,0,49,0,0,0,0,0,0,19,11016,0,0,0,0,0,0,"Jaedenar Legionnaire - On Data Set - Start Attacking");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=11016;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(11016,0,1,9862,5078.45,-480.791,298.158,5.27389,3,300000),
(11016,0,1,9862,5076.87,-493.36,296.772,5.58412,3,300000),
(11016,0,1,9862,5076.33,-487.275,297.841,5.92969,3,300000);

DELETE FROM `waypoints` WHERE `entry`=11016;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(11016,1,5004.98,-440.237,319.059,''),
(11016,2,4992.22,-449.964,317.057,''),
(11016,3,4988.55,-457.438,316.289,''),
(11016,4,4989.98,-464.297,316.846,''),
(11016,5,4994.04,-467.754,318.055,''),
(11016,6,5002.31,-466.318,319.965,''),
(11016,7,5011.8,-462.889,321.501,''),
(11016,8,5020.53,-460.797,321.97,''),
(11016,9,5026.84,-463.171,321.345,''),
(11016,10,5028.66,-476.805,318.726,''),
(11016,11,5029.5,-487.131,318.179,''),
(11016,12,5031.18,-497.678,316.533,''),
(11016,13,5032.72,-504.748,314.744,''),
(11016,14,5035,-513.138,314.372,''),
(11016,15,5037.49,-521.733,313.221,''),
(11016,16,5049.06,-519.546,313.221,''),
(11016,17,5059.17,-522.93,313.221,''),
(11016,18,5062.75,-529.933,313.221,''),
(11016,19,5063.9,-538.827,313.221,''),
(11016,20,5062.22,-545.635,313.221,''),
(11016,21,5061.69,-552.333,313.101,''),
(11016,22,5060.33,-560.349,310.873,''),
(11016,23,5055.62,-565.541,308.737,''),
(11016,24,5049.8,-567.604,306.537,''),
(11016,25,5043.01,-564.946,303.682,''),
(11016,26,5038.22,-559.823,301.463,''),
(11016,27,5039.46,-548.675,297.824,''),
(11016,28,5043.44,-538.807,297.801,''),
(11016,29,5056.4,-528.954,297.801,''),
(11016,30,5064.4,-521.904,297.801,''),
(11016,31,5067.62,-512.999,297.196,''),
(11016,32,5065.99,-505.329,297.214,''),
(11016,33,5062.24,-499.086,297.448,''),
(11016,34,5065.09,-492.069,298.054,''),
(11016,35,5071.19,-491.173,297.666,''),
(11016,36,5087.47,-496.478,296.677,''),
(11016,37,5095.55,-508.639,296.677,''),
(11016,38,5104.3,-521.014,296.677,''),
(11016,39,5110.13,-532.123,296.677,''),
(11016,40,5099.75,-510.823,296.677,''),
(11016,41,5091.94,-497.516,296.677,''),
(11016,42,5079.38,-486.811,297.638,''),
(11016,43,5069.21,-488.77,298.082,''),
(11016,44,5064.24,-496.051,297.275,''),
(11016,45,5065.08,-505.239,297.361,''),
(11016,46,5067.82,-515.245,297.125,''),
(11016,47,5064.62,-521.17,297.801,''),
(11016,48,5053.22,-530.739,297.801,''),
(11016,49,5045.73,-538.311,297.801,''),
(11016,50,5039.69,-548.112,297.801,''),
(11016,51,5038.78,-557.588,300.787,''),
(11016,52,5042.01,-566.749,303.838,''),
(11016,53,5050.56,-568.149,306.782,''),
(11016,54,5056.98,-564.674,309.342,''),
(11016,55,5060.79,-556.801,311.936,''),
(11016,56,5059.58,-551.626,313.221,''),
(11016,57,5062.83,-541.994,313.221,''),
(11016,58,5063.55,-531.288,313.221,''),
(11016,59,5057.93,-523.088,313.221,''),
(11016,60,5049.47,-519.36,313.221,''),
(11016,61,5040.79,-519.809,313.221,''),
(11016,62,5034.3,-515.361,313.948,''),
(11016,63,5032,-505.532,314.663,''),
(11016,64,5029.92,-495.645,316.821,''),
(11016,65,5028.87,-487,318.179,''),
(11016,66,5028.11,-475.531,318.839,''),
(11016,67,5027.76,-465.442,320.643,''),
(11016,68,5019.96,-460.892,321.969,''),
(11016,69,5009.43,-464.793,321.248,''),
(11016,70,4999.57,-468.062,319.426,''),
(11016,71,4992.03,-468.128,317.894,''),
(11016,72,4988.17,-461.293,316.369,''),
(11016,73,4990.62,-447.459,317.104,''),
(11016,74,4993.48,-438.643,318.272,''),
(11016,75,4995.45,-430.178,318.462,''),
(11016,76,4993.56,-422.876,318.864,''),
(11016,77,4985.4,-420.864,320.205,''),
(11016,78,4976.52,-426.168,323.112,''),
(11016,79,4969.83,-429.755,325.029,''),
(11016,80,4960.7,-425.44,325.834,''),
(11016,81,4955.45,-418.765,327.433,''),
(11016,82,4949.7,-408.796,328.004,''),
(11016,83,4940.02,-403.222,329.956,''),
(11016,84,4934.98,-401.475,330.898,''),
(11016,85,4928.69,-399.302,331.744,''),
(11016,86,4926.94,-398.436,333.079,''),
(11016,87,4916.16,-393.822,333.729,''),
(11016,88,4908.39,-396.217,333.217,''),
(11016,89,4905.61,-396.535,335.05,''),
(11016,90,4897.88,-395.245,337.346,''),
(11016,91,4895.21,-388.203,339.295,''),
(11016,92,4896.94,-382.429,341.04,''),
(11016,93,4901.88,-378.799,342.771,''),
(11016,94,4908.09,-380.635,344.597,''),
(11016,95,4911.91,-385.818,346.491,''),
(11016,96,4910.1,-393.444,348.798,''),
(11016,97,4903.5,-396.947,350.812,''),
(11016,98,4898.08,-394.226,351.821,''),
(11016,99,4891.33,-393.436,351.801,''),
(11016,100,4881.2,-395.211,351.59,''),
(11016,101,4877.84,-395.536,349.713,''),
(11016,102,4873.97,-394.919,349.844,''),
(11016,103,4873.97,-394.919,349.844,''),
(11016,104,4873.97,-394.919,349.844,''),
(11016,105,4873.97,-394.919,349.844,''),
(11016,106,4873.97,-394.919,349.844,''),
(11016,107,4863.02,-394.521,350.65,''),
(11016,108,4848.7,-397.612,351.215,''),
(11016,109,4810.83,-402.127,349.427,''),
(11016,110,4786.06,-424.654,344.842,'');
