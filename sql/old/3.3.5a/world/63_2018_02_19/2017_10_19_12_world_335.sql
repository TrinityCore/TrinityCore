-- Athrikus Narassin
DELETE FROM `creature_text` WHERE `CreatureID`=3660 AND `GroupID` IN (1,2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3660,1,0,"My... My powers have diminished... You shall pay for this insolence!",14,10,100,0,0,0,1449,0,"Athrikus Narassin"),
(3660,2,0,"No! You can't defeat me!",12,0,100,0,0,0,1450,0,"Athrikus Narassin");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3660 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3660,0,1,0,4,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Athrikus Narassin - On Aggro - Say Line 1"),
(3660,0,2,0,6,0,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Athrikus Narassin - On Just Died - Say Line 2");
