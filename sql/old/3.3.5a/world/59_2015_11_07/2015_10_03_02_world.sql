-- 
DELETE FROM `gossip_menu` WHERE `entry`=8750 AND `text_id`=11082;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (8750, 11082);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8750) AND `id`=2;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`, `OptionBroadcastTextID`, `option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(8750,2,0,"I'm ready. Take me to the Chamber of Command.",21879,1,1,0); 

DELETE FROM `spell_target_position` WHERE `id`=41570;
INSERT INTO `spell_target_position` (`id`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`) VALUES
(41570, 564, 603.42, 305.982, 271.9, 0);

UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE `entry`=23411;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23411) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23411,0,0,1,62,0,100,0,8750,1,0,0,85,41566,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirit of Olum - On gossip select - cast spell"),
(23411,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirit of Olum - On gossip select - Close gossip"),
(23411,0,2,3,62,0,100,0,8750,2,0,0,85,41570,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirit of Olum - On gossip select - cast spell"),
(23411,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spirit of Olum - On gossip select - Close gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=8750;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8750, 1, 0, 0, 13, 1, 1, 3, 2, 0, 0, 0, '', 'Show options for gossip only if SUPREMUS done'),
(15, 8750, 2, 0, 0, 13, 1, 7, 3, 2, 0, 0, 0, '', 'Show options for gossip only if COUNCIL done'),
(14, 8750, 11082, 0, 0, 13, 1, 1, 3, 2, 1, 0, 0, '', 'Show gossip text only if SUPREMUS not done'),
(14, 8750, 11081, 0, 0, 13, 1, 1, 3, 2, 0, 0, 0, '', 'Show gossip text only if SUPREMUS done');
