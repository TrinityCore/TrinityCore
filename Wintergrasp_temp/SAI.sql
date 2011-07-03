/*
These two npcs already have a scriptname assigned (npc_wg_spiritguide). That core script should make these npcs cast the 22011 spell.
-- Spirit healers SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (31841,31842);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (31841,31842);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31841,0,0,0,1,0,100,0,0,0,30000,30000,11,22011,0,0,0,0,0,1,0,0,0,0,0,0,0, 'cast Spirit Heal Channel every 30 sec'),
(31842,0,0,0,1,0,100,0,0,0,30000,30000,11,22011,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dwarven Spirit Guide - cast Spirit Heal Channel every 30 sec');
*/
