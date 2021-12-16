--
UPDATE `creature_template` SET `unit_flags` = 33024, `AIName` = "SmartAI" WHERE `entry` = 28118;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28118 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2811800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28118,0,0,0,54,0,100,0,0,0,0,0,0,80,2811800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watery Lord - On Just Summoned - Run Script"),
(28118,0,1,0,0,0,100,0,5000,10000,10000,15000,0,11,35735,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Watery Lord - In Combat - Cast 'Water Spout'"),

(2811800,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Watery Lord - On Script - Set Orientation Owner"),
(2811800,9,1,0,0,0,100,0,0,0,0,0,0,11,32995,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watery Lord - On Script - Cast 'Water Elemental Impact Visual'"),
(2811800,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,0,"Watery Lord - On Script - Say Line 0"),
(2811800,9,3,0,0,0,100,0,3000,3000,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Watery Lord - On Script - Remove Flag Immune To Players"),
(2811800,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Watery Lord - On Script - Start Attack Owner");

DELETE FROM `creature_text` WHERE `CreatureID` = 28118;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28118,0,0,"You dare summon me?!",12,0,100,34,0,0,27501,0,"Watery Lord"),
(28118,0,1,"Prepare to drown!",12,0,100,34,0,0,27502,0,"Watery Lord"),
(28118,0,2,"The depths consume you!",12,0,100,34,0,0,27503,0,"Watery Lord"),
(28118,0,3,"I will add your watery innards to my own.",12,0,100,34,0,0,27504,0,"Watery Lord");
