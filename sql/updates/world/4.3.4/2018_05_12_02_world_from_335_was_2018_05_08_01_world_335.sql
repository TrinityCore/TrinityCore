/*
-- Quest "The Videre Elixir"
-- Miblon's Bait
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=164758;
DELETE FROM `smart_scripts` WHERE `entryorguid`=164758 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(164758,1,0,0,1,0,100,1,0,0,0,1000,45,1,1,0,0,0,0,19,9467,50,0,0,0,0,0,"Miblon's Bait - Out of Combat - Set Data to Miblon Snarltooth (No Repeat)");

-- Miblon Snarltooth
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9467;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9467 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=946700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9467,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Respawn - Set Event Phase 1"),
(9467,0,1,0,38,1,100,0,1,1,0,0,80,946700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Data Set - Run Script (Phase 1)"),
(946700,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Set Event Phase 0"),
(946700,9,1,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Remove NPC Flag Gossip"),
(946700,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Say Line 0"),
(946700,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,20,164758,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Set Orientation"),
(946700,9,4,0,0,0,100,0,1000,1000,0,0,41,0,115,0,0,0,0,14,17428,164729,0,0,0,0,0,"Miblon Snarltooth - On Script - Despawn Gameobject 'Miblon's Door'"),
(946700,9,5,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Set Run On"),
(946700,9,6,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,20,164758,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Move to Closest Gameobject 'Miblon's Bait'"),
(946700,9,7,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Say Line 1"),
(946700,9,8,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Say Line 2"),
(946700,9,9,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Say Line 3"),
(946700,9,10,0,0,0,100,0,105000,105000,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Evade"),
(946700,9,11,0,0,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Add NPC Flag Gossip"),
(946700,9,12,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Miblon Snarltooth - On Script - Set Event Phase 1");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=9467;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9467,0,0,"%s abandons the block he was holding up in the doorway, and looks towards the bait.",16,0,100,0,0,0,4836,0,"Miblon Snarltooth"),
(9467,1,0,"%s sniffs the bait.",16,0,100,0,0,0,4768,0,"Miblon Snarltooth"),
(9467,2,0,"Grumble...",12,0,100,0,0,0,4766,0,"Miblon Snarltooth"),
(9467,3,0,"%s gnaws at the bait ravenously.",16,0,100,0,0,0,4771,0,"Miblon Snarltooth");
*/
