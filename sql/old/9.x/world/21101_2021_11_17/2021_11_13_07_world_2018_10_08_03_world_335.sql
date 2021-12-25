-- Quest "Prospect of Faith (Part 2)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=291600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(291600,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Remove Npc Flag Questgiver"),
(291600,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.30863,"Historian Karnik - On Script - Set Orientation"),
(291600,9,2,0,0,0,100,0,1000,1000,0,0,0,11,4985,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Cast 'Summon Hammertoe's Spirit'"),
(291600,9,3,0,0,0,100,0,0,0,0,0,0,12,2915,3,21000,0,0,0,8,0,0,0,-4633.14,-1324.99,503.383,5.44702,"Historian Karnik - On Script - Summon Creature 'Hammertoe's Spirit'"),
(291600,9,4,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,19,2915,0,0,0,0,0,0,"Historian Karnik - On Script - Say Line 0"),
(291600,9,5,0,0,0,100,0,7000,7000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Say Line 0"),
(291600,9,6,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,19,2915,0,0,0,0,0,0,"Historian Karnik - On Script - Say Line 1"),
(291600,9,7,0,0,0,100,0,8000,8000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Say Line 1"),
(291600,9,8,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.76278,"Historian Karnik - On Script - Set Orientation"),
(291600,9,9,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Add Npc Flag Questgiver");

UPDATE `creature_text` SET `Emote`=6 WHERE `CreatureID`=2916 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=2915;
