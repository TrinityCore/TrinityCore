-- Althea Ebonlocke
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=264;
DELETE FROM `smart_scripts` WHERE `entryorguid`=264;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(264,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Althea Ebonlocke - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=264;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(264,0,0,"Stay on the roads.  The forest is overrun with undead.",12,7,100,0,0,0,61,0,"Commander Althea Ebonlocke"),
(264,0,1,"Fear not.  The Night Watch will rid the land of this foul taint soon enough.",12,7,100,0,0,0,62,0,"Commander Althea Ebonlocke");
