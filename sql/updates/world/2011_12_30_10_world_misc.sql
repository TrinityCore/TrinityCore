-- Glyph Chasing quest workaround by unknown autor (updated by maxxx)
-- Closes #1682

DELETE FROM `gossip_menu` WHERE entry IN (6559,6560,6561);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(6559,7770),
(6560,7770),
(6561,7770);

DELETE FROM `gossip_menu_option` WHERE menu_id IN (6559,6560,6561);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(6559,0,0,'<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL),
(6560,0,0,'<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL),
(6561,0,0,'<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=180453;
DELETE FROM smart_scripts WHERE (entryorguid=180453 AND source_type=1);
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,COMMENT) VALUES
(180453,1,0,1,62,0,100,0,6561,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180453,1,1,0,61,0,100,1,0,0,0,0,56,20456,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20456');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=180454;
DELETE FROM smart_scripts WHERE (entryorguid=180454 AND source_type=1);
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,COMMENT) VALUES
(180454,1,0,1,62,0,100,0,6560,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180454,1,1,0,61,0,100,1,0,0,0,0,56,20455,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20455');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=180455;
DELETE FROM smart_scripts WHERE (entryorguid=180455 AND source_type=1);
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,COMMENT) VALUES
(180455,1,0,1,62,0,100,0,6559,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180455,1,1,0,61,0,100,1,0,0,0,0,56,20454,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20454');
