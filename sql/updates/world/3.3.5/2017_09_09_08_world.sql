-- Princess Poobah
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2634;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2634 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2634,0,0,0,20,0,100,0,630,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Princess Poobah - On Quest \'Message in a Bottle\' Finished - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=2634;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2634,0,0,"Thank you again for your aid. May the wind always be at your back during your travels.",12,0,100,2,0,0,765,0,"Princess Poobah");
