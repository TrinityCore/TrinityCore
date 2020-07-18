-- Completion event for quest "Jin'Zil's Forest Magic"
DELETE FROM `creature_text` WHERE `CreatureID`=3995;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3995,0,0,"%s drops the animal parts into the bubbling cauldron.",16,0,100,69,0,0,1405,0,"Witch Doctor Jin\'Zil"),
(3995,1,0,"Ah, feel the magic seep into the cave, my little elves... muhahaha.",12,1,100,5,0,0,1406,0,"Witch Doctor Jin\'Zil"),
(3995,2,0,"So much for the power of nature... muhahahaha.",12,1,100,11,0,0,1407,0,"Witch Doctor Jin\'Zil");

UPDATE `creature` SET `spawntimesecs`=60 WHERE `id`=4072;
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=4072;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3995;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3995 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=399500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3995,0,0,0,20,0,100,0,1058,0,0,0,80,399500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Witch Doctor Jin\'Zil - On Quest \'Jin\'Zil\'s Forest Magic\' Finished - Run Script'),
(399500,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Remove Npc Flag Questgiver"),
(399500,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0078,"Witch Doctor Jin\'Zil - On Script - Set Orientation"),
(399500,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Say Line 0"),
(399500,9,3,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Set Orientation"),
(399500,9,4,0,0,0,100,0,0,0,0,0,86,6584,0,9,4072,0,30,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Cross Cast Jin'Zil\'s Curse"),
(399500,9,5,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Say Line 1"),
(399500,9,6,0,0,0,100,0,6000,6000,0,0,51,0,0,0,0,0,0,9,4072,0,30,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Kill Target"),
(399500,9,7,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Say Line 2"),
(399500,9,8,0,0,0,100,0,3000,3000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin\'Zil - On Script - Add Npc Flag Questgiver");
