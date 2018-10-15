/*
-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (6070,6069);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6070,6069) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6070,0,0,0,2,0,100,0,0,45,15300,22900,0,11,11431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maraudine Khan Advisorr - Cast Healing Touch When Below 45% HP'),
(6070,0,1,0,0,0,100,0,2000,4000,12700,17800,0,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Khan Advisorr - IC - Casts Frost Shock"),
(6070,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Maraudine Khan Advisorr - Just summoned - start atack"),
(6069,0,0,0,4,0,100,0,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maraudine Khan Guard - Casts Defensive Stance on Aggro"),
(6069,0,1,0,0,0,100,0,1200,3800,11900,13700,0,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Khan Guard - IC - Casts Shield Bash"),
(6069,0,2,0,0,0,100,0,5000,5000,15000,15000,0,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Maraudine Khan Guard - IC - Cast Sunder Armor"),
(6069,0,3,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Maraudine Khan Guard - Just summoned - start atack");
*/
