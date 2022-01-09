-- 
UPDATE `creature_template_addon` SET `auras`=""  WHERE `entry` IN (13142,30681,17160,19415,30680,19952,19945,19985,20673,21453,21663,24497);
UPDATE `creature_template_addon` SET `auras`="16093" WHERE `entry` IN (19027,19030);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (19945,19985,21453,21663,20673,17160);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19945,19985,21453,21663,20673,17160) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19945,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lashh'an Windwalker - On missing aura - Cast 'Lightning Shield'"),
(19945,0,1,0,0,0,100,0,1000,2000,3000,4000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lashh'an Windwalker - IC - Cast 'Lightning Bolt"),
(19985,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ruuan'ok Cloudgazer - On missing aura - Cast 'Lightning Shield'"),
(19985,0,1,0,0,0,100,0,1000,2000,3000,4000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ruuan'ok Cloudgazer - IC - Cast 'Lightning Bolt"),
(20673,0,0,0,23,0,100,0,12550,0,3000,3000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swiftwing Shredder - On missing aura - Cast 'Lightning Shield'"),
(20673,0,1,0,0,0,100,0,2000,5000,3000,5000,11,36594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swiftwing Shredder - IC - Cast Lightning Breath"),
(21453,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Shaman - On missing aura - Cast 'Lightning Shield'"),
(21453,0,1,0,0,0,100,0,8000,10000,30000,35000,11,36594,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Shaman - IC - Cast bloodlust"),
(21663,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Shaman - On missing aura - Cast 'Lightning Shield'"),
(21663,0,1,0,0,0,100,0,8000,10000,10000,15000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Shaman - IC - Cast Healing Wave"),
(17160,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Living Cyclone - On missing aura - Cast 'Lightning Shield'"),
(17160,0,1,0,0,0,100,0,2000,4000,2000,4000,11,31705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Living Cyclone - IC - Cast 'Magnetic Pull");
