-- 
UPDATE `creature_addon` SET `auras`=""  WHERE `guid` IN (133,55823,58656,58657,58658,58659,58671,58672,60280, 60281, 60283, 60286, 60288, 60289, 60290, 60292, 60294, 62205, 62208, 62209, 62213, 63260, 63261, 63262, 63263, 63279, 63280, 63281, 63282, 63283, 63284, 63285, 63456, 63459, 63465, 63470, 63471, 63486, 63927, 63933, 63934, 65894, 65898, 65902, 65904, 65960, 65966, 65967, 65968, 65972, 65973, 66151, 66526);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (17327);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17327,17606,17713,18077) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17327,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blacksilt Tidecaller - On missing aura - Cast 'Lightning Shield'"),
(17327,0,1,0,0,0,100,0,4000,7000,15000,19000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blacksilt Tidecaller - IC - Cast Rejuvenation"),
(17606,0,0,0,23,0,100,0,12544,0,3000,3000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunhawk Reclaimer - On missing aura - Cast 'Frost Armor'"),
(17606,0,1,0,0,0,100,0,2000,3000,3500,4000,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sunhawk Reclaimer - IC - Cast Fireball"),
(17606,0,2,0,0,0,100,0,0,1000,25000,30000,11,31734,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunhawk Reclaimer - IC - Cast Mark of the Sunhawk"),
(17713,0,0,0,23,0,100,0,12544,0,3000,3000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodcursed Naga - On missing aura - Cast 'Frost Armor'"),
(17713,0,1,0,0,0,100,0,2000,3000,3500,4000,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodcursed Naga - IC - Cast Frostbolt"),
(18077,0,0,0,23,0,100,0,12550,0,3000,3000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - On missing aura - Cast 'Lightning Shield'"),
(18077,0,1,0,2,0,100,0,0,49,22000,25000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - Between 0-49% Health - Cast 'Healing Wave'");

UPDATE `creature` SET `position_x`=-2862.61889, `position_y`=-11369.52246, `position_z`=-1.57192, `orientation`=1.889444 WHERE `guid`= 62209;
