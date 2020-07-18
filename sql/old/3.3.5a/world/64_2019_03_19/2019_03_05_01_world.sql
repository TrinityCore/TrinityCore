-- 
UPDATE `smart_scripts` SET `action_type`=134 WHERE `entryorguid`=2841300 AND `source_type`=9 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=23 WHERE `entryorguid`=28415 AND `source_type`=0 AND `id`=0;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (28414);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28414) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28414, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, "Drakkari Captive - On Just Summoned - Attack");

DELETE FROM `creature_template_addon` WHERE `entry`=28414;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (28414,"54450");
