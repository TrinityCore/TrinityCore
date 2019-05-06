-- A Lost Master
DELETE FROM `creature_text` WHERE `CreatureID`=3693 AND `GroupID` IN (8, 9);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3693,8,0,"I shall get started right away, $n.",12,7,100,0,0,0,1247,0,"Terenthis"),
(3693,9,0,"Now... where was my thread and needle. Ah! There it is...",12,7,100,0,0,0,1248,0,"Terenthis");
DELETE FROM `smart_scripts` WHERE `entryorguid`=3693 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3693,0,5,0,20,0,100,0,986,0,0,0,80,369302,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Quest \A Lost Master (Part 1)\ Finished - Run Script");
DELETE FROM `smart_scripts` WHERE `entryorguid`=369302 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(369302,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Remove Npc Flag Questgiver+Gossip"),
(369302,9,1,0,0,0,100,0,1000,1000,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 8"),
(369302,9,2,0,0,0,100,0,3000,3000,0,0,1,9,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 9"),
(369302,9,3,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Set Emote State 69"),
(369302,9,4,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Set Emote State 0"),
(369302,9,5,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terenthis - On Script - Add Npc Flag Questgiver+Gossip");
