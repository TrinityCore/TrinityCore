-- High Priest Thel'danis
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1854 AND `source_type` = 0 AND `id` = 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 185400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1854,0,5,0,20,0,100,0,8414,0,0,0,0,80,185400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Priest Thel'danis - On Quest 'Dispelling Evil' Finished - Run Script"),

(185400,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Priest Thel'danis - On Script - Remove NPC Flag Questgiver"),
(185400,9,1,0,0,0,100,0,0,0,0,0,0,11,24997,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Priest Thel'danis - On Script - Cast 'Greater Dispel'"),
(185400,9,2,0,0,0,100,0,5000,5000,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"High Priest Thel'danis - On Script - Say Line 2"),
(185400,9,3,0,0,0,100,0,3000,3000,0,0,0,1,3,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"High Priest Thel'danis - On Script - Say Line 3"),
(185400,9,4,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"High Priest Thel'danis - On Script - Add NPC Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID` = 1854 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(1854,2,0,"%s examines the Scourgestone closely.",16,0,100,0,0,0,10834,0,"High Priest Thel'danis"),
(1854,3,0,"The evil in these stones is strong, but it has been dispelled.",12,0,100,1,0,0,10835,0,"High Priest Thel'danis");
