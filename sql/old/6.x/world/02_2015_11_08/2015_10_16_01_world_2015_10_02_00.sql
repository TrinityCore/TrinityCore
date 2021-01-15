-- 
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7143, 8172);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7139) AND `id`=3;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`, `OptionBroadcastTextID`, `option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(7143,0,0,"Help you with what situation?",18420,1,1,8172),
(8172,0,0,"Big ones?",18421,1,1,8171),
(7139,3,0,"Please transport me to the Guardian's Library.",20519,1,1,0); 

UPDATE `gossip_menu_option` SET `action_menu_id`=8167 WHERE `menu_id`=7139 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=8168 WHERE `menu_id`=7139 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=8169 WHERE `menu_id`=7139 AND `id`=2;

UPDATE `creature_template` SET `gossip_menu_id`=8173 WHERE `entry`=16426;
DELETE FROM `gossip_menu` WHERE `entry`=8173 AND `text_id`=10120;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (8173, 10120);

UPDATE `creature_template` SET `gossip_menu_id`=8175 WHERE `entry`=16806;
DELETE FROM `gossip_menu` WHERE `entry`=8175 AND `text_id`=10123;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (8175, 10123);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7139;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 7139, 3, 0, 0, 13, 1, 7, 3, 0, 0, 0, 0, '', 'Show options for gossip only if ARAN done');

UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE `entry`=16153;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16153) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16153,0,0,1,62,0,100,0,7139,3,0,0,85,39567,0,0,0,0,0,7,0,0,0,0,0,0,0,"Berthold - On gossip select - cast spell"),
(16153,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Berthold  - On gossip select - Close gossip");
