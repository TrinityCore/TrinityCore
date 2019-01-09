-- 
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` IN (21685,24788);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21685)  AND `source_type`=0 AND `id`=19;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24788)  AND `source_type`=0 AND `id`=10;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)  VALUES
(21685,0, 19,0,63,0,100,0,0,0,0,0, 81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oronok Torn-heart - On just created - Remove NPC Flags Gossip'),
(24788,0, 10,0,63,0,100,0,0,0,0,0, 81,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jack Adams - On just created - Remove NPC Flags Gossip');
