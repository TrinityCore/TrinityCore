-- Gazban
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2624;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2624 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2624,0,0,0,0,0,100,0,6000,12000,7000,15000,11,5403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazban - In Combat - Cast Crash of Waves"),
(2624,0,1,0,54,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazban - Just Summoned - Say Line 0"),
(2624,0,2,0,0,0,100,1,4000,4000,4000,4000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazban - IC - Say Line 1"),
(2624,0,3,0,0,0,100,1,4000,4000,4000,4000,11,5402,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gazban - IC - Cast Gazban Water Form"),
(2624,0,4,0,0,0,100,1,4000,4000,4000,4000,11,5404,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gazban - IC - Cast Gazban Water Form");
DELETE FROM `creature_text` WHERE `CreatureID`=2624;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2624,0,0,"What is happening? What force draws me to the Altar of the Tides!",14,0,100,0,0,0,769,0,"Gazban"),
(2624,1,0,"Oh now you've gone and angered me! Time to see the true force of the Stone of Tides!",12,0,100,0,0,0,1113,0,"Gazban");
