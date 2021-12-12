--
UPDATE `smart_scripts` SET `action_type` = 80, `action_param1` = 1960600, `action_param2` = 0, `action_param3` = 0, `comment` = "Grek - On Gossip Option 0 Selected - Run Script" WHERE `entryorguid` = 19606 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19606 AND `source_type` = 0 AND `id` IN (4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1960600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1960600,9,0,0,0,0,100,0,0,0,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Grek - On Script - Say Line 2"),
(1960600,9,1,0,0,0,100,0,2000,2000,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grek - On Script - Set Emote State 69"),
(1960600,9,2,0,0,0,100,0,4000,4000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grek - On Script - Set Emote State 0"),
(1960600,9,3,0,0,0,100,0,0,0,0,0,0,1,3,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Grek - On Script - Say Line 3"),
(1960600,9,4,0,0,0,100,0,0,0,0,0,0,33,19606,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Grek - On Script - Quest Credit 'And Now, the Moment of Truth'");

UPDATE `creature_text` SET `Emote` = 0 WHERE `CreatureID` = 19606 AND `GroupID` = 2;
UPDATE `creature_text` SET `Emote` = 15 WHERE `CreatureID` = 19606 AND `GroupID` = 3;
