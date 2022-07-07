-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24027;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24027 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24027, 0, 0, 0, 1, 0, 100, 0, 20000, 40000, 60000, 120000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sergeant Gorth - OOC - Talk");

DELETE FROM `creature_text` WHERE `CreatureID`=24027;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24027, 0, 0, "Crush them!  Crush their faces!", 14, 1, 100, 0, 0, 0, 22623, 0, "Sergeant Gorth"),
(24027, 0, 1, "Hold positions!  Keep vrykul men back!", 14, 1, 100, 0, 0, 0, 22624, 0, "Sergeant Gorth"),
(24027, 0, 2, "Kill vrykul scum!  For Sylvanas!", 14, 1, 100, 0, 0, 0, 22625, 0, "Sergeant Gorth"),
(24027, 0, 3, "Don't let vrykul come through!  Kill all!", 14, 1, 100, 0, 0, 0, 22626, 0, "Sergeant Gorth"),
(24027, 0, 4, "Some things Gorth has to do himself!", 12, 1, 100, 0, 0, 0, 22627, 0, "Sergeant Gorth"),
(24027, 0, 5, "You no match for Gorth!", 12, 1, 100, 0, 0, 0, 22628, 0, "Sergeant Gorth"),
(24027, 0, 6, "Gorth no care if he die!  Gorth get put back together!", 12, 1, 100, 0, 0, 0, 22629, 0, "Sergeant Gorth");
