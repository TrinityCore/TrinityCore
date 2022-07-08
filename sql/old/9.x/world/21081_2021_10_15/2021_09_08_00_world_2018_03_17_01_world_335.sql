-- 
-- Summoned Voidwalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=5676 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5676,0,2,0,11,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Voidwalker - On Respawn - Say Line 0"),
(5676,0,3,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Voidwalker - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=5676;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5676,0,0,"Who dares summon the power of the void?",12,8,100,0,0,0,1986,0,"Summoned Voidwalker"),
(5676,1,0,"You will live forever in torment for this, pathetic warlock.",12,8,100,0,0,0,1987,0,"Summoned Voidwalker");

-- Summoned Succubus
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5677;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5677 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5677,0,0,0,11,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Succubus - On Respawn - Say Line 0"),
(5677,0,1,0,0,0,100,0,3000,5000,7000,11000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Succubus - In Combat - Cast 'Shadow Shock'");

DELETE FROM `creature_text` WHERE `CreatureID`=5677;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5677,0,0,"Interesting... Now this is more than I expected. Delicious...",12,8,100,0,0,0,1991,0,"Summoned Succubus");
