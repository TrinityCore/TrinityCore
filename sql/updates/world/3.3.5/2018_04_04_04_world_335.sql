-- Mehlar Dawnblade
DELETE FROM `creature_text` WHERE `CreatureID`=17099;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17099,0,0,"Uther Lightbringer brought only darkness to Quel'Thalas.  Let us see if we can bring some darkness to his tomb!",12,0,100,1,0,0,14112,0,"Mehlar Dawnblade"),
(17099,1,0,"At last I will have my revenge!",12,0,100,11,0,0,14115,0,"Mehlar Dawnblade");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17099;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17099 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1709900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17099,0,0,0,20,0,100,0,9443,0,0,0,80,1709900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mehlar Dawnblade - On Quest 'The So-Called Mark of the Lightbringer' Finished - Run Script"),
(1709900,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mehlar Dawnblade - On Script - Remove Npc Flag Questgiver+Gossip"),
(1709900,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mehlar Dawnblade - On Script - Say Line 0"),
(1709900,9,2,0,0,0,100,0,3000,3000,0,0,11,16633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mehlar Dawnblade - On Script - Cast 'Create Item Visual (DND)'"),
(1709900,9,3,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mehlar Dawnblade - On Script - Say Line 1"),
(1709900,9,4,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mehlar Dawnblade - On Script - Add Npc Flag Questgiver+Gossip");
