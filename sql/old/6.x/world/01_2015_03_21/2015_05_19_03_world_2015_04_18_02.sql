--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=17918;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17918 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

(17918, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 8000, 12000, 11, 31478, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Time Keeper - IC - Cast Sand Breath'),
(17918, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 20000, 30000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Time Keeper - IC - Cast Sand Breath');

DELETE FROM `creature_text` WHERE `entry` IN (17918);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(17918, 0, 0, 'Victory will be ours!', 14, 0, 100, 0, 0, 0, 15194, 0, 'Time Keeper'),
(17918, 0, 1, 'Carry on! Victory at all costs!', 14, 0, 100, 0, 0, 0, 15195, 0, 'Time Keeper'),
(17918, 0, 2, 'Continue the fight! Do not falter!', 14, 0, 100, 0, 0, 0, 15196, 0, 'Time Keeper');
