-- 
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 176093;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 176093 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(176093,1,0,1,1,0,100,1,0,0,0,0,0,64,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Beacon Torch - On Update - Store Targetlist"),
(176093,1,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,10902,30,0,0,0,0,0,0,"Beacon Torch - On Link - Send Target 1 (Andorhal Tower One)"),
(176093,1,2,3,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,10903,30,0,0,0,0,0,0,"Beacon Torch - On Link - Send Target 1 (Andorhal Tower Two)"),
(176093,1,3,4,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,10904,30,0,0,0,0,0,0,"Beacon Torch - On Link - Send Target 1 (Andorhal Tower Three)"),
(176093,1,4,5,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,10905,30,0,0,0,0,0,0,"Beacon Torch - On Link - Send Target 1 (Andorhal Tower Four)"),
(176093,1,5,6,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,10902,30,0,0,0,0,0,0,"Beacon Torch - On Link - Set Data 0 1 (Andorhal Tower One)"),
(176093,1,6,7,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,10903,30,0,0,0,0,0,0,"Beacon Torch - On Link - Set Data 0 1 (Andorhal Tower Two)"),
(176093,1,7,8,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,10904,30,0,0,0,0,0,0,"Beacon Torch - On Link - Set Data 0 1 (Andorhal Tower Three)"),
(176093,1,8,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,10905,30,0,0,0,0,0,0,"Beacon Torch - On Link - Set Data 0 1 (Andorhal Tower Four)");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (10902,10903,10904,10905);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (10902,10903,10904,10905) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10902,0,0,0,38,0,100,0,0,1,0,0,0,33,10902,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Andorhal Tower One - On Data Set 0 1 - Quest Credit 'All Along the Watchtowers'"),
(10903,0,0,0,38,0,100,0,0,1,0,0,0,33,10903,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Andorhal Tower Two - On Data Set 0 1 - Quest Credit 'All Along the Watchtowers'"),
(10904,0,0,0,38,0,100,0,0,1,0,0,0,33,10904,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Andorhal Tower Three - On Data Set 0 1 - Quest Credit 'All Along the Watchtowers'"),
(10905,0,0,0,38,0,100,0,0,1,0,0,0,33,10905,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Andorhal Tower Four - On Data Set 0 1 - Quest Credit 'All Along the Watchtowers'");
