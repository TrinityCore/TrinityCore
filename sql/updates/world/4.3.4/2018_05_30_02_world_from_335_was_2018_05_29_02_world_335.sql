/*
-- Defias Tower Patroller
DELETE FROM `creature_text` WHERE `CreatureID`=7052;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7052,0,0,"Hey, Raven...",12,0,100,0,0,0,3126,0,"Defias Tower Patroller"),
(7052,1,0,"Yea?",12,0,100,0,0,0,3127,0,"Defias Tower Patroller"),
(7052,2,0,"Can we take a break? My feet are killing me and those ... those things down there are creeping me out.",12,0,100,6,0,0,3128,0,"Defias Tower Patroller"),
(7052,3,0,"I dunno, Jill. If Klaven comes down while we're slacking, we may end up as one of those things!",12,0,100,274,0,0,3129,0,"Defias Tower Patroller"),
(7052,4,0,"*Sigh* You're probably right, Raven. I'm going back on patrol....",12,0,100,1,0,0,3130,0,"Defias Tower Patroller");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7052;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-66988,-66991) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=705200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-66991,0,0,0,11,0,100,0,0,0,0,0,80,705200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Tower Patroller - On Respawn - Run Script"),
(-66991,0,1,0,40,0,100,0,30,705201,0,0,80,705200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Tower Patroller - On Waypoint 30 Reached - Run Script"),
(-66988,0,0,0,38,0,100,0,1,1,0,0,53,0,705200,0,0,0,2,1,0,0,0,0,0,0,0,"Defias Tower Patroller - On Data Set - Start Waypoint"),
(-66988,0,1,0,40,0,100,0,24,705200,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.50239,"Defias Tower Patroller - On Waypoint 24 Reached - Set Orientation"),
(705200,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.36865,"Defias Tower Patroller - On Script - Set Orientation"),
(705200,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,10,66988,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Say Line 0"),
(705200,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Say Line 1"),
(705200,9,3,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,10,66988,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Say Line 2"),
(705200,9,4,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Say Line 3"),
(705200,9,5,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,10,66988,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Say Line 4"),
(705200,9,6,0,0,0,100,0,5000,5000,0,0,53,0,705201,0,0,0,2,1,0,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Start Waypoint"),
(705200,9,7,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,66988,0,0,0,0,0,0,"Defias Tower Patroller - On Script - Set Data");

DELETE FROM `waypoints` WHERE `entry` IN (705200,705201);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(705200,1,-11149.1,554.466,55.8049,""),
(705200,2,-11144.7,556.683,55.1371,""),
(705200,3,-11140.4,556.894,53.8734,""),
(705200,4,-11136,554.83,52.5735,""),
(705200,5,-11131.7,549.872,50.3729,""),
(705200,6,-11130.7,546.131,49.4701,""),
(705200,7,-11131.7,549.872,50.3729,""),
(705200,8,-11136,554.83,52.5735,""),
(705200,9,-11140.4,556.894,53.8734,""),
(705200,10,-11144.7,556.683,55.1371,""),
(705200,11,-11149.1,554.466,55.8049,""),
(705200,12,-11152.3,552.681,55.8918,""),
(705200,13,-11149.1,554.466,55.8049,""),
(705200,14,-11144.7,556.683,55.1371,""),
(705200,15,-11140.4,556.894,53.8734,""),
(705200,16,-11136,554.83,52.5735,""),
(705200,17,-11131.7,549.872,50.3729,""),
(705200,18,-11130.7,546.131,49.4701,""),
(705200,19,-11131.7,549.872,50.3729,""),
(705200,20,-11136,554.83,52.5735,""),
(705200,21,-11140.4,556.894,53.8734,""),
(705200,22,-11144.7,556.683,55.1371,""),
(705200,23,-11149.1,554.466,55.8049,""),
(705200,24,-11152.5,552.716,55.8919,""),
(705201,1,-11151.1,551.26,55.8923,""),
(705201,2,-11140.5,543.668,56.3212,""),
(705201,3,-11142.6,541.549,55.92,""),
(705201,4,-11146,536.9,53.7638,""),
(705201,5,-11147,534.896,52.495,""),
(705201,6,-11147.6,532.728,52.4694,""),
(705201,7,-11147.6,535.236,52.5826,""),
(705201,8,-11145.2,538.529,54.7388,""),
(705201,9,-11141.9,543.463,56.2928,""),
(705201,10,-11139.4,542.983,56.6356,""),
(705201,11,-11138.4,539.196,57.9116,""),
(705201,12,-11138.3,535.496,59.8756,""),
(705201,13,-11137.9,539.928,57.7232,""),
(705201,14,-11139.9,543.434,56.4715,""),
(705201,15,-11149.7,550.018,55.9364,""),
(705201,16,-11140.5,543.668,56.3212,""),
(705201,17,-11142.6,541.549,55.92,""),
(705201,18,-11146,536.9,53.7638,""),
(705201,19,-11147,534.896,52.495,""),
(705201,20,-11147.6,532.728,52.4694,""),
(705201,21,-11147.6,535.236,52.5826,""),
(705201,22,-11145.2,538.529,54.7388,""),
(705201,23,-11141.9,543.463,56.2928,""),
(705201,24,-11139.4,542.983,56.6356,""),
(705201,25,-11138.4,539.196,57.9116,""),
(705201,26,-11138.3,535.496,59.8756,""),
(705201,27,-11137.9,539.928,57.7232,""),
(705201,28,-11139.9,543.434,56.4715,""),
(705201,29,-11149.7,550.018,55.9364,""),
(705201,30,-11151.1,551.26,55.8923,"");

DELETE FROM `waypoint_data` WHERE `id` IN (669880,669910);
DELETE FROM `creature_addon` WHERE `guid` IN (66988,66991);
UPDATE `creature` SET `position_x`=-11152.5, `position_y`=552.716, `position_z`=55.8919, `orientation`=5.50239, `MovementType`=0 WHERE `guid`=66988;
UPDATE `creature` SET `position_x`=-11151.1, `position_y`=551.26, `position_z`=55.8923, `orientation`=2.36865, `MovementType`=0 WHERE `guid`=66991;
*/
