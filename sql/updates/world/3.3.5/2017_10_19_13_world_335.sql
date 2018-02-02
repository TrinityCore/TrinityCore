-- Orgnil Soulscar
UPDATE `creature_text` SET `Emote`=5 WHERE `CreatureID`=3142 AND `GroupID`=0;
DELETE FROM `creature_text` WHERE `CreatureID`=3142 AND `GroupID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3142,3,0,"%s smashes the dead, twisted claw.",16,0,100,36,0,0,984,0,"Orgnil Soulscar");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3142 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=314201 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3142,0,0,0,20,0,100,0,806,0,0,0,80,314201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Quest 'Dark Storms' Finished - Run Script"),
(314201,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Remove Npc Flag Questgiver"),
(314201,9,1,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Say Line 3"),
(314201,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Say Line 0"),
(314201,9,3,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Add Npc Flag Questgiver");
