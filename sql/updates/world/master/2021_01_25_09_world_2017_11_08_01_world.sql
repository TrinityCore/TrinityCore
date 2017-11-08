-- 
DELETE FROM `creature_text` WHERE `CreatureID`=16793;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16793, 0, 0, "You're such a good friend, Twinkle.  You'd never leave me, would you?", 12, 1, 100, 16, 0, 0, 13586, 0, "Magistrix Carinda"),
(16793, 0, 1, "It's just you and me, Twinkle.  Daddy's not going to be coming home.", 12, 1, 100, 16, 0, 0, 13587, 0, "Magistrix Carinda"),
(16793, 0, 2, "Did you find something fun to chase around, Twinkle?  I bet you did!", 12, 1, 100, 16, 0, 0, 13588, 0, "Magistrix Carinda");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16793 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16793, 0, 0, 0, 1, 0, 100, 0, 5000, 20000, 120000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Magistrix Carinda - Out Of Combat - Talk");
