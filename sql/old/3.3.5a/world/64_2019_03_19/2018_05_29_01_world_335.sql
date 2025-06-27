-- Klaven Mortwake
UPDATE `creature_text` SET `Emote`=5 WHERE `CreatureID`=7053 AND `GroupID`=2;
UPDATE `creature_text` SET `Emote`=11 WHERE `CreatureID`=7053 AND `GroupID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=7053 AND `GroupID`=5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7053,5,0,"You cannot hide from me, rogue. I can smell your fear.",12,0,100,0,0,0,3092,0,"Klaven Mortwake");

UPDATE `smart_scripts` SET `action_param6`=2 WHERE `entryorguid`=7053 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7053 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7053,0,3,0,4,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Klaven Mortwake - On Aggro - Say Line 5");
