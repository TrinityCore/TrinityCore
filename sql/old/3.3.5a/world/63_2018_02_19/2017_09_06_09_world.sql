-- Denalan
DELETE FROM `smart_scripts` WHERE `entryorguid`=2080 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2080,0,4,0,20,0,100,512,927,0,0,0,80,208003,2,0,0,0,0,1,0,0,0,0,0,0,0,"Denalan - On Quest \The Moss-twined Heart\ Finished - Run Script");
DELETE FROM `smart_scripts` WHERE `entryorguid`=208003 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(208003,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Denalan - On Script - Remove Npc Flag Questgiver"),
(208003,9,1,0,0,0,100,0,1000,1000,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 7"),
(208003,9,2,0,0,0,100,0,2000,2000,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 8"),
(208003,9,3,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,7,0,0,0,0,0,0,0,"Denalan - On Script - Say Line 9"),
(208003,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Denalan - On Script - Add Npc Flag Questgiver");
DELETE FROM `creature_text` WHERE `CreatureID`=2080 AND `GroupID`>6;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2080,7,0,"%s examines the Moss-twined Heart...",16,0,100,0,0,0,1126,0,"Denalan"),
(2080,8,0,"$n, underneath the moss, this heart looks like a seed!",12,7,100,1,0,0,1127,0,"Denalan"),
(2080,9,0,"Let's try planting it in some of my special, prepared soil...",12,7,100,1,0,0,1128,0,"Denalan");
