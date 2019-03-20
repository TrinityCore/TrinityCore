-- 
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=`unit_flags`|768 WHERE `entry`=10581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10539;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (10539,10581) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10539,0,0,1,20,0,100,0,4821,0,0,0,41,0,0,0,0,0,0,19,10581,20,0,0,0,0,0, 'Hagar Lightninghoof - On quest rewarded - despawn npc'),
(10539,0,1,0,61,0,100,0,0,0,0,0,12,10581,3,10000,0,0,0,8,0,0,0,-5440.1005, -2401.906, 89.2746, 4.631578, 'Hagar Lightninghoof  - On quest rewarded - summon npc'),
(10581,0,0,0,54,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Young Arikara - On Just summoned - random movements');
