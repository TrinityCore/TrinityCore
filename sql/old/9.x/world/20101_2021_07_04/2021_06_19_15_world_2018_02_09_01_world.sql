-- 
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (20869, 21586);
UPDATE `creature` SET `curhealth`=62315 WHERE `id` IN (20869);
DELETE FROM `smart_scripts` WHERE `entryorguid`=20869 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20869, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 28, 31261, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arcatraz Sentinel - On aggro - remove aura');
