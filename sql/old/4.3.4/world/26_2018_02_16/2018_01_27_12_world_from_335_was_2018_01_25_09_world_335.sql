/*
-- Quest "The Torch of Retribution"
DELETE FROM `smart_scripts` WHERE `entryorguid`=847900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(847900,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Close Gossip"),
(847900,9,1,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Remove Npc Flags Gossip & Questgiver"),
(847900,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Say Line 0"),
(847900,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Set Emote State 69"),
(847900,9,4,0,0,0,100,0,10000,10000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast 'Torch Combine'"),
(847900,9,5,0,0,0,100,0,8000,8000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast 'Torch Combine'"),
(847900,9,6,0,0,0,100,0,7000,7000,0,0,11,12511,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast 'Torch Combine'"),
(847900,9,7,0,0,0,100,0,10000,10000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Say Line 1"),
(847900,9,8,0,0,0,100,0,7000,7000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Set Emote State 0"),
(847900,9,9,0,0,0,100,0,1000,1000,0,0,11,12512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Cast 'Kalaran Conjures Torch'"),
(847900,9,10,0,0,0,100,0,1000,1000,0,0,70,180,0,0,0,0,0,14,24166,149410,0,0,0,0,0,"Kalaran Windblade - On Script - Respawn Light of Retribution"),
(847900,9,11,0,0,0,100,0,0,0,0,0,70,180,0,0,0,0,0,14,16762,149047,0,0,0,0,0,"Kalaran Windblade - On Script - Respawn Torch of Retribution"),
(847900,9,12,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Say Line 2"),
(847900,9,13,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Set Flag Standstate Kneel"),
(847900,9,14,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Say Line 3"),
(847900,9,15,0,0,0,100,0,2000,2000,0,0,15,3453,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Quest Credit 'The Torch of Retribution'"),
(847900,9,16,0,0,0,100,0,2000,2000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Remove Flag Standstate Kneel"),
(847900,9,17,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Script - Add Npc Flags Gossip & Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=8479;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8479,0,0,"%s chants in an unknown tongue.",16,0,100,0,0,0,4447,0,"Kalaran Windblade"),
(8479,1,0,"Be patient, $n. The torch is almost complete.",12,0,100,1,0,0,4448,0,"Kalaran Windblade"),
(8479,2,0,"%s falls to one knee. He looks exhausted.",16,0,100,0,0,0,4449,0,"Kalaran Windblade"),
(8479,3,0,"It is done...",12,0,100,0,0,0,4450,0,"Kalaran Windblade");
*/
