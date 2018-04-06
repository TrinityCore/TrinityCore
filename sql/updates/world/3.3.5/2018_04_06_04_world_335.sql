-- Orm Stonehoof
DELETE FROM `creature_text` WHERE `CreatureID`=6410;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6410,0,0,"%s begins to work...",16,0,100,0,0,0,2348,0,"Orm Stonehoof"),
(6410,1,0,"I have completed your helm, $n.",12,1,100,1,0,0,2635,0,"Orm Stonehoof");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6410;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6410 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=641000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6410,0,0,0,20,0,100,0,1844,0,0,0,80,641000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Quest 'Chimaeric Horn' Finished - Run Script"),
(641000,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Script - Remove Npc Flag Questgiver"),
(641000,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Script - Say Line 0"),
(641000,9,2,0,0,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Script - Set Emote State 233"),
(641000,9,3,0,0,0,100,0,20000,20000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Script - Set Emote State 0"),
(641000,9,4,0,0,0,100,0,500,500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Script - Say Line 1"),
(641000,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orm Stonehoof - On Script - Add Npc Flag Questgiver");

UPDATE `creature` SET `position_x`=-1239.54, `position_y`=109.707, `position_z`=129.58, `orientation`=1.89658 WHERE `guid`=24678;
