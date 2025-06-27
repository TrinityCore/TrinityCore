-- 
UPDATE `creature` SET `equipment_id`=2 WHERE `guid`= 114137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23745;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-114137 AND source_type=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-114137, 0, 0, 0, 1, 0, 100, 0, 10000, 15000, 20000, 30000, 11, 53824, 0, 0, 0, 0, 0, 19, 23033, 0, 0, 0, 0, 0, 0, 'Garg - OOC - Cast Throw');
UPDATE `creature_template_addon` SET `auras`="32951" WHERE `entry` IN (23565);
DELETE FROM `creature_addon` WHERE `guid` IN (97576);
