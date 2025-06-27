-- Sprinkle
DELETE FROM `creature_text` WHERE `CreatureID`=7583 AND `GroupID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7583,3,0,"Just sit tight while I get this prepared for you!",12,0,100,0,0,0,3661,0,"Sprinkle");

DELETE FROM `smart_scripts` WHERE `entryorguid`=7583 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=758302 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7583,0,2,0,20,0,100,0,2641,0,0,0,80,758302,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Quest 'Sprinkle's Secret Ingredient' Finished - Run Script"),
(758302,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Remove Npc Flag Questgiver"),
(758302,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Say Line 3"),
(758302,9,2,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Set Emote State 'Usestanding'"),
(758302,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Set Emote State 'None'"),
(758302,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sprinkle - On Script - Add Npc Flag Questgiver");
