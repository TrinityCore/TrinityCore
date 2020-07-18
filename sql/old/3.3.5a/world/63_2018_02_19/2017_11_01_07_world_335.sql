-- Tor'gan
DELETE FROM `creature_text` WHERE `CreatureID`=2706;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2706,0,0,"Easier than I expected... the sigil of Thoradin is whole, once again.",12,1,100,1,0,0,798,0,"Tor'gan");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2706 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=270600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2706,0,1,0,20,0,100,0,640,0,0,0,80,270600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tor'gan - On Quest 'The Broken Sigil' finished - Run Script"),
(270600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tor'gan - On Script - Remove Npc Flag Questgiver"),
(270600,9,1,0,0,0,100,0,1000,1000,0,0,11,4093,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tor'gan - On Script - Cast Reconstruction"),
(270600,9,2,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tor'gan - On Script - Say Line 0"),
(270600,9,3,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tor'gan - On Script - Add Npc Flag Questgiver");
