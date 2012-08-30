-- Quest: I was a lot of things
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=21195;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21195 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param2`,`action_type`,`action_param1`,`action_param2`,`target_type`,`target_param1`,`target_param2`,`comment`) VALUES
(21195,1,0,34,1,24,0,0, 1,    0,0,'Domesticated Felboar - Movementinform - Evade (Required for core script npc_shadowmoon_tuber_node)'),
(21195,2,0,34,1,45,1,1,11,21347,5,'Domesticated Felboar - Movementinform - Set data (Required for core script npc_shadowmoon_tuber_node)');
