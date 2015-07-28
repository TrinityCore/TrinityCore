--
UPDATE `creature_template` SET `AIName`= 'SmartAI', `ScriptName`= '' WHERE  `entry`=4979;

DELETE FROM `smart_scripts` WHERE `entryorguid` =4979 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4979,0,0,1,62,0,100,0,8851,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - on Gossip option select - set NPC Flags'),
(4979,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - Linked with Previous Event - Close Gossip'),
(4979,0,2,3,61,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - Linked with Previous Event - Say Line 0'),
(4979,0,3,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Theramore Guard - Linked with Previous Event - Store Targetlist'),
(4979,0,4,0,52,0,100,0,0,4979,0,0,11,42725,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - Linked with Previous Event - Cast Doctored Leaflet'),
(4979,0,5,6,23,0,100,0,42246,1,121000,121000,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - On Has Aura Propagandized! - Say Line 1'),
(4979,0,6,0,61,0,100,0,0,0,0,0,33,4979,0,0,0,0,0,12,1,0,0,0,0,0,0,'Theramore Guard - Linked with Previous Event - Give Kill Credit'),
(4979,0,7,8,52,0,100,0,1,4979,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - On Text Over Line 1 - Say line 2'),
(4979,0,8,0,61,0,100,0,0,0,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - Linked with Previous Event - Play Emote ONESHOT_LAUGH'),
(4979,0,9,0,52,0,100,0,2,4979,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theramore Guard - On Text Over Line 2 - Set NPC Flags');

DELETE FROM `gossip_menu_option` WHERE `menu_id` in(8851);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(8851, 0, 0, 'You look like an intelligent person. Why don''t you read one of these leaflets and give it some thought?', 22549, 1, 1, 21084, 0, 0, 0, NULL, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(8851);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8851, 0, 0, 0, 9, 0, 11133, 0, 0, 0, 0, 0, '', 'Gossip Option requires Discrediting the Deserters Taken'),
(15, 8851, 0, 0, 0, 1, 1, 42246, 0, 0, 1, 0, 0, '', 'Gossip Option requires NPC does not have aura Propagandized!');
