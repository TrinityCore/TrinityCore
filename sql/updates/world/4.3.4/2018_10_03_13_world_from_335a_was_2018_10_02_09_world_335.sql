/*
-- Pathing for Shadowsilk Poacher
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=5768;

DELETE FROM `creature_addon` WHERE `guid`=5768;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(5768,57680,0,0,1,0,"");

DELETE FROM `creature_formations` WHERE `leaderGUID`=5768;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(5768,5768,0,0,515,0,0),
(5768,5771,3,180,515,0,0),
(5768,5772,3,90,515,0,0),
(5768,5770,3,360,515,0,0),
(5768,5769,3,270,515,0,0);

DELETE FROM `waypoint_data` WHERE `id`=57680;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(57680,1,-6475.76,-1653.2,296.95,0,0,0,0,100,0),
(57680,2,-6456.78,-1641.12,302.886,0,0,0,0,100,0),
(57680,3,-6442.88,-1643.53,307.503,0,0,0,0,100,0),
(57680,4,-6433.85,-1639.7,311.784,0,0,0,0,100,0),
(57680,5,-6430.85,-1624.21,316.06,0,0,0,0,100,0),
(57680,6,-6437.13,-1611.54,317.35,0,0,0,0,100,0),
(57680,7,-6455.35,-1602.83,316.361,0,0,0,0,100,0),
(57680,8,-6483.23,-1602.32,313.864,0,0,0,0,100,0),
(57680,9,-6508.08,-1613.72,302.94,0,0,0,0,100,0),
(57680,10,-6524.63,-1629.45,296.374,0,0,0,0,100,0),
(57680,11,-6549.25,-1636.63,296.184,0,0,0,0,100,0),
(57680,12,-6558.26,-1629.93,293.225,0,0,0,0,100,0),
(57680,13,-6564.29,-1623.06,287.738,0,0,0,0,100,0),
(57680,14,-6567.7,-1614.35,284.125,0,0,0,0,100,0),
(57680,15,-6584.51,-1599.24,274.318,0,0,0,0,100,0),
(57680,16,-6586.88,-1592.99,273.086,0,0,0,0,100,0),
(57680,17,-6596.43,-1569.3,272.825,0,0,0,0,100,0),
(57680,18,-6595.06,-1553.18,273.489,0,0,0,0,100,0),
(57680,19,-6600.38,-1537.31,273.269,0,0,0,0,100,0),
(57680,20,-6600.03,-1528.85,273.124,0,0,0,0,100,0),
(57680,21,-6605.06,-1517.05,269.084,0,0,0,0,100,0),
(57680,22,-6606.51,-1506.95,271.175,0,0,0,0,100,0),
(57680,23,-6605.02,-1485.74,269.163,0,0,0,0,100,0),
(57680,24,-6600.2,-1474.55,269.11,0,0,0,0,100,0),
(57680,25,-6601.17,-1459.35,267.091,0,0,0,0,100,0),
(57680,26,-6609.78,-1431.57,265.835,0,0,0,0,100,0),
(57680,27,-6621.3,-1422.3,264.632,0,0,0,0,100,0),
(57680,28,-6628.59,-1423.14,260.498,0,0,0,0,100,0),
(57680,29,-6639.19,-1428.01,252.796,0,0,0,0,100,0),
(57680,30,-6649.86,-1430.2,249.935,0,0,0,0,100,0),
(57680,31,-6666.55,-1429.78,242.738,0,0,0,0,100,0),
(57680,32,-6682.08,-1439.36,240.719,0,0,0,0,100,0),
(57680,33,-6690.03,-1459.6,242.431,0,0,0,0,100,0),
(57680,34,-6693.66,-1476.71,242.766,0,0,0,0,100,0),
(57680,35,-6688.73,-1497.33,241.983,0,0,0,0,100,0),
(57680,36,-6666.39,-1526.66,243.709,0,0,0,0,100,0),
(57680,37,-6650.78,-1584.87,244.454,0,0,0,0,100,0),
(57680,38,-6624.57,-1635.45,244.219,0,0,0,0,100,0),
(57680,39,-6612.23,-1652.77,245.724,0,0,0,0,100,0),
(57680,40,-6617.72,-1674.4,244.826,0,0,0,0,100,0),
(57680,41,-6612.6,-1702.57,244.242,0,0,0,0,100,0),
(57680,42,-6608.79,-1707.23,244.058,0,0,0,0,100,0),
(57680,43,-6603.43,-1707.57,244.598,0,0,0,0,100,0),
(57680,44,-6599.1,-1704.02,247.051,0,0,0,0,100,0),
(57680,45,-6596.47,-1693.83,254.567,0,0,0,0,100,0),
(57680,46,-6579.82,-1684.53,266.768,0,0,0,0,100,0),
(57680,47,-6567.27,-1680.84,277.013,0,0,0,0,100,0),
(57680,48,-6558.48,-1671.8,281.61,0,0,0,0,100,0),
(57680,49,-6546.02,-1660.57,284.798,0,0,0,0,100,0),
(57680,50,-6527.17,-1658.61,289.643,0,0,0,0,100,0),
(57680,51,-6499.39,-1664.21,295.044,0,0,0,0,100,0);

-- Raze
UPDATE `creature` SET `spawntimesecs`=30 WHERE `guid`=5767;
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=0 WHERE `entry`=8441;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8441 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (844100,844101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8441,0,0,0,11,0,100,0,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Respawn - Add Unit Flags 'Immune To Player'+'Immune To NPC'"),
(8441,0,1,0,62,0,100,0,2306,0,0,0,0,80,844100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Gossip Option Selected - Run Script"),
(8441,0,2,0,62,0,100,0,2306,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Raze - On Gossip Option Selected - Close Gossip"),
(8441,0,3,0,62,0,100,0,2306,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Raze - On Gossip Option Selected - Store Target"),
(8441,0,4,0,62,0,100,0,2306,0,0,0,0,57,10464,1,0,0,0,0,7,0,0,0,0,0,0,0,"Raze - On Gossip Option Selected - Remove Item 'Staff of Command'"),
(8441,0,5,0,62,0,100,0,2306,0,0,0,0,85,15539,2,0,0,0,0,7,0,0,0,0,0,0,0,"Raze - On Gossip Option Selected - Invoker Cast 'Conjure Staff of Command'"),
(8441,0,6,0,38,0,100,1,2,2,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Raze - On Data Set - Say Line 1"),
(8441,0,7,0,38,0,100,1,1,1,0,0,0,80,844101,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Data Set - Run Script"),
(844100,9,0,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Script - Remove Npc Flag 'Gossip'"),
(844100,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,8439,0,0,0,0,0,0,"Raze - On Script - Say Line 0 (Nilith Lokrav)"),
(844100,9,2,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Raze - On Script - Start Follow Player"),
(844100,9,3,0,0,0,100,0,8000,8000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Raze - On Script - Say Line 0"),
(844100,9,4,0,0,0,100,0,2692000,2692000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Raze - On Script - Say Line 2"),
(844100,9,5,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Script - Despawn"),
(844101,9,0,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Script - Remove Unit Flags 'Immune To Player'+'Immune To NPC'"),
(844101,9,1,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Script - Set Faction 113"),
(844101,9,2,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,8442,0,0,0,0,0,0,"Raze - On Script - Start Attacking"),
(844101,9,3,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Raze - On Script - Say Line 2"),
(844101,9,4,0,0,0,100,0,5000,5000,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raze - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (8441,8439);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8439,0,0,"Use this Staff of Command on Raze when you are near Shadowsilk Poachers and he will make them rue the day they decided to poach in these lands.",12,0,100,1,0,0,4414,0,"Nilith Lokrav"),
(8441,0,0,"Raze follow $n! Raze SMASH poachers! SMASH SMASH SMASH! Tell Raze to SMASH by playing with stick! SMASH!",12,0,100,0,0,0,4521,0,"Raze"),
(8441,1,0,"Use staff, tell Raze what do! Show Raze poacher! Raze smash!",12,0,100,0,0,0,5949,0,"Raze"),
(8441,2,0,"Raze need go home now. Bye, bye, $r.",12,0,100,0,0,0,4413,0,"Raze"),
(8441,2,1,"Bye, bye, tiny little $r. Raze go now.",12,0,100,0,0,0,4415,0,"Raze");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2306;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2306,0,0,0,9,0,3379,0,0,0,0,0,"","Show gossip option if quest 'Shadoweaver' is taken");

-- Shadowsilk Poacher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8442;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8442 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8442,0,0,0,8,0,100,0,12347,0,0,0,0,45,1,1,0,0,0,0,19,8441,0,0,0,0,0,0,"Shadowsilk Poacher - On Spellhit 'Raze Attack' - Set Data to Raze"),
(8442,0,1,0,75,0,100,1,0,8441,15,0,0,45,2,2,0,0,0,0,19,8441,0,0,0,0,0,0,"Shadowsilk Poacher - On Creature 'Raze' in Range - Set Data to Raze");
*/
