--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (31198, 31150);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31198, 31150) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(31150,0,0,0,0,0,100,0,2000,8000,12000,15000,11,60678,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Plagued Fiend - IC - Plague Bite"),
(31198,0,0,0,0,0,100,0,2000,2000,15000,20000,11,38971,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Coprous the Defiled - IC - Cast Acid Geyser"),
(31198,0,1,0,0,0,100,0,5000,5000,10000,10000,11,5164,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Coprous the Defiled - IC - Cast Knockdown");
