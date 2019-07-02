-- Yeh'kinya
DELETE FROM `creature_template_movement` WHERE `CreatureId`=8579;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(8579,1,0,2,0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8579;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8579 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=857900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8579,0,0,0,20,0,100,0,8181,0,0,0,80,857900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Quest 'Confront Yeh'kinya' Finished - Run Script"),
(8579,0,1,0,20,0,100,0,8181,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Quest 'Confront Yeh'kinya' Finished - Set Active On"),
(8579,0,2,0,40,0,100,0,2,8579,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Waypoint 2 Reached - Despawn"),
(857900,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Remove Npc Flag Questgiver+Gossip"),
(857900,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Say Line 0"),
(857900,9,2,0,0,0,100,0,6000,6000,0,0,3,0,2706,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Morph To Model 2706"),
(857900,9,3,0,0,0,100,0,0,0,0,0,11,7741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Cast 'Summoned Demon'"),
(857900,9,4,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Say Line 1"),
(857900,9,5,0,0,0,100,0,0,0,0,0,53,1,8579,0,0,0,0,1,0,0,0,0,0,0,0,"Yeh'kinya - On Script - Start Waypoint");

DELETE FROM `creature_text` WHERE `CreatureID`=8579;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8579,0,0,"It is true, $n.  The wheels of doom now turn, inevitably, toward the true return of Hakkar!",12,0,100,5,0,0,10456,0,"Yeh'kinya"),
(8579,1,0,"Blood and souls for Hakkar!  HAHAHAH!",14,0,100,0,0,6963,10457,0,"Yeh'kinya");

DELETE FROM `waypoints` WHERE `entry`=8579;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(8579,1,-6916.84,-4847.92,12.5325,""),
(8579,2,-6964.45,-4949.57,6.45678,"");


