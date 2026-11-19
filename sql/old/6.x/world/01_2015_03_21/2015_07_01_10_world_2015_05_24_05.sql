-- Scarlet Hound
DELETE  FROM `creature` WHERE `id` IN (10979);
DELETE  FROM `creature_addon` WHERE `guid` IN (52633, 52634, 52635, 52637, 52641, 52662, 52664, 52665, 52666, 52667, 52668);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10979;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10979 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1831 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1831, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 17164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Scarlet Hunter - On Reset - Cast to summon Scarlet Hound'),
(10979, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 6000, 9000, 11, 17260, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Scarlet Hound - IC - Cast Bite'),
(10979, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 22000, 25000, 11, 59274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Scarlet Hound - IC - Furious Howl');
