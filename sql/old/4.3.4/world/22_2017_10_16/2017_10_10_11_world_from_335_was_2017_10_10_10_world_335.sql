/*
-- Quest "Report to Orgnil" --> Add completion Event
DELETE FROM `smart_scripts` WHERE `entryorguid`=3142 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=314200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3142,0,1,0,20,0,100,0,823,0,0,0,80,314200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Quest 'Report to Orgnil' Finished - Run Script"),
(314200,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Remove Npc Flag Questgiver"),
(314200,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Say Line 1"),
(314200,9,2,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Say Line 2"),
(314200,9,3,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgnil Soulscar - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=3142 AND `GroupID` IN (1,2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3142,1,0,"%s listens to $n's report...",16,0,100,0,0,0,981,0,"Orgnil Soulscar"),
(3142,2,0,"What??  The Burning Blade is spreading!  We must investigate!",12,1,100,5,0,0,982,0,"Orgnil Soulscar");
*/
