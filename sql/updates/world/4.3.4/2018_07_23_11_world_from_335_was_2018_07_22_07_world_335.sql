/*
-- Quest "Protecting the Shipment"
UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=309; -- Prevents quest from auto completing

-- Miran
UPDATE `creature` SET `spawntimesecs`=120 WHERE `guid`=8975;

DELETE FROM `creature_text` WHERE `CreatureID`=1379 AND `GroupID` IN (1,2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1379,1,0,"Help! I've only one hand to defend myself with.",12,7,100,0,0,0,510,0,"Miran"),
(1379,2,0,"Send them on! I'm not afraid of some scrawny beasts!",12,7,100,0,0,0,511,0,"Miran"),
(1379,3,0,"Ah, here at last! It's going to feel so good to get rid of these barrels.",12,7,100,0,0,0,498,0,"Miran");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1379;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1379 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (137900,137901) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1379,0,0,1,19,0,100,0,309,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Miran - On Quest 'Protecting the Shipment' Taken - Store Targetlist"),
(1379,0,1,2,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Quest 'Protecting the Shipment' Taken - Remove Npc Flag Questgiver"),
(1379,0,2,0,61,0,100,0,0,0,0,0,0,53,0,1379,0,0,0,2,1,0,0,0,0,0,0,0,"Miran - On Quest 'Protecting the Shipment' Taken - Start Waypoint"),
(1379,0,3,0,6,0,100,0,0,0,0,0,0,6,309,0,0,0,0,0,12,1,0,0,0,0,0,0,"Miran - On Just Died - Fail Quest 'Protecting the Shipment'"),
(1379,0,4,0,40,0,100,0,19,1379,0,0,0,80,137900,2,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Waypoint 19 Reached - Run Script"),
(1379,0,5,0,40,0,100,0,23,1379,0,0,0,80,137901,2,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Waypoint 23 Reached - Run Script"),
(1379,0,6,0,40,0,100,0,24,1379,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Waypoint 24 Reached - Despawn"),
(137900,9,0,0,0,0,100,0,0,0,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Script - Pause Waypoint"),
(137900,9,1,0,0,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Script - Summon Group"),
(137900,9,2,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Script - Say Line 1"),
(137900,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,2149,0,0,0,0,0,0,"Miran - On Script - Say Line 0 (Dark Iron Raider)"),
(137900,9,4,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Script - Say Line 2"),
(137901,9,0,0,0,0,100,0,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Script - Pause Waypoint"),
(137901,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miran - On Script - Say Line 3"),
(137901,9,2,0,0,0,100,0,0,0,0,0,0,15,309,0,0,0,0,0,12,1,0,0,0,0,0,0,"Miran - On Script - Complete Quest 'Protecting the Shipment'");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=1379;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(1379,0,1,2149,-5699.63,-3745.94,319.454,1.56927,1,10000),
(1379,0,1,2149,-5706.36,-3744.81,318.798,1.04306,1,10000);

DELETE FROM `waypoints` WHERE `entry`=1379;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1379,1,-5751.12,-3441.01,301.743,""),
(1379,2,-5738.58,-3485.14,302.41,""),
(1379,3,-5721.62,-3507.85,304.011,""),
(1379,4,-5710.21,-3527.97,304.708,""),
(1379,5,-5706.92,-3542.89,304.871,""),
(1379,6,-5701.53,-3551.24,305.962,""),
(1379,7,-5699.53,-3555.69,306.505,""),
(1379,8,-5690.56,-3571.98,309.035,""),
(1379,9,-5678.61,-3587.17,310.607,""),
(1379,10,-5677.05,-3594.35,311.527,""),
(1379,11,-5674.39,-3605.19,312.239,""),
(1379,12,-5674.45,-3614.39,312.337,""),
(1379,13,-5673.05,-3630.56,311.105,""),
(1379,14,-5680.34,-3645.44,315.185,""),
(1379,15,-5684.46,-3650.05,314.687,""),
(1379,16,-5693.9,-3674.14,313.03,""),
(1379,17,-5701.43,-3712.54,313.959,""),
(1379,18,-5698.79,-3720.88,316.943,""),
(1379,19,-5699.95,-3733.63,318.597,""),
(1379,20,-5698.61,-3754.74,322.047,""),
(1379,21,-5688.68,-3769,323.957,""),
(1379,22,-5688.14,-3782.65,322.667,""),
(1379,23,-5699.23,-3792.65,322.448,""),
(1379,24,-5700.8,-3792.78,322.588,"");

-- Dark Iron Raider
DELETE FROM `creature_text` WHERE `CreatureID`=2149;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2149,0,0,"Get him!",12,6,100,0,0,0,512,0,"Dark Iron Raider");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2149 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2149,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,1379,0,0,0,0,0,0,"Dark Iron Raider - Just Summoned - Start Attacking");

-- Huldar
DELETE FROM `gossip_menu` WHERE `MenuID`=4322 AND `TextID`=5501;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4322,5501,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4322;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4322,5494,0,0,29,0,1379,20,0,0,0,0,"","Show gossip text 5494 if Miran is nearby"),
(14,4322,5501,0,0,29,0,1379,20,0,1,0,0,"","Show gossip text 3522 if Miran is not nearby");
*/
