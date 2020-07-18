-- Completion event for quest 'Bathran's Hair'
DELETE FROM `creature_text` WHERE `CreatureID`=3847;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3847,0,0,"%s mixes the Bathran's Hair...",16,0,100,0,0,0,1307,0,"Orendil Broadleaf"),
(3847,1,0,"The mixture is finished, $n.  Now we must save the child.",12,7,100,1,0,0,1308,0,"Orendil Broadleaf");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3847 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=384700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3847,0,1,0,20,0,100,0,1010,0,0,0,80,384700,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orendil Broadleaf - On Quest \'Bathran\'s Hair\' Finished - Run Script'),
(384700,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orendil Broadleaf - On Script - Remove Npc Flag Questgiver"),
(384700,9,1,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orendil Broadleaf - On Script - Set Emote State 69"),
(384700,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orendil Broadleaf - On Script - Say Line 0"),
(384700,9,3,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orendil Broadleaf - On Script - Set Emote State 0"),
(384700,9,4,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orendil Broadleaf - On Script - Say Line 1"),
(384700,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orendil Broadleaf - On Script - Add Npc Flag Questgiver");
