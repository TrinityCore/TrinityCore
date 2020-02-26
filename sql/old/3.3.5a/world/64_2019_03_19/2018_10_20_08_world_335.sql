-- Myra Tyrngaarde
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5109;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5109 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5109,0,0,0,1,0,100,0,10000,15000,40000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myra Tyrngaarde - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=5109;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5109,0,0,"Fresh Bread! Get your oven fresh bread here!",12,7,100,0,0,0,4014,0,"Myra Tyrngaarde"),
(5109,0,1,"Fresh bread for sale!",12,7,100,0,0,0,4013,0,"Myra Tyrngaarde"),
(5109,0,2,"Come get yer fresh bread!",12,7,100,0,0,0,4015,0,"Myra Tyrngaarde");
