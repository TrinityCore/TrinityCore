-- 
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (56000,56001,56002);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES 
(56000,0,0,"Dreadlords? Perhaps you mean Lord Banehollow. He sends his regards, and has a message for you...",9737,1,1,56001,0,0,0,NULL,0),
(56001,0,0,"No, Ulathek. He knows your secret. He knows you plot with Lord Hel'nurath of Xoroth.",9739,1,1,56002,0,0,0,NULL,0),
(56002,0,0,"It's no lie, traitor. Banehollow wants your heart, and I'm going to get it for him.",9741,1,1,0,0,0,0,NULL,0);

-- Create new entries in gossip_menu
DELETE FROM `gossip_menu` WHERE `entry` IN (56000,56001,56002) AND `text_id` IN (7038,7039,7040);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(56000,7038),
(56001,7039),
(56002,7040);

-- Gossip conditions, show gossip option if player has Quest 7624, Ulathek the Traitor
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`= 56000;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,56000,0,0,9,7624,0,0,0,'','Show gossip option if player has Quest 7624, Ulathek the Traitor');

-- Update table `creature_template`
UPDATE `creature_template` SET `AIName` = 'SmartAI', `gossip_menu_id`= 56000 WHERE `entry` = 14523;

-- Update table `smart_scripts`
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 14523;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14523, 0, 0, 1, 62, 0, 100, 0, 56002, 0, 0, 0, 28, 23179, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ulathek - On GossipSelected - Remove Aura \'Taint of Shadow\''),
(14523, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ulathek - On Gossip Selected - Close Gossip'),
(14523, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ulathek - On Gossip Selected - Start attack'),
(14523, 0, 3, 0, 0, 0, 100, 0, 1000, 2000, 3000, 4000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ulathek - IC - Cast Shadow Bolt'),
(14523, 0, 4, 0, 2,0,100,1,0,30,0,0,11,8699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulathek - IN health pct 30% - Cast Unholy Frenzy"),
(14523, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ulathek - On reset - Cast Summon Imp');
