/* 4.x removed
-- Captain Vanessa Beltis
UPDATE `creature_template` SET `gossip_menu_id`=1641 WHERE `entry`=8380;
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry` IN (1641);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (1641,2293);
*/

-- Franclorn Forgewright 8888
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry` IN (1664,1665,1666);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(1664,2316), (1665,2317), (1666,2318);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1663,1664,1665);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(1663,0,0, 'Amazing! I''ve never spoken to a ghost. I wish to learn!',1,1,1664),
(1664,0,0, 'Continue please.',1,1,1665),
(1665,0,0, 'Fascinating. Please, tell me more.',1,1,1666);

-- Ribbly Screwspigot
UPDATE `creature_template` SET `gossip_menu_id`=1970 WHERE `entry`=9543;
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry` IN (1970);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (1970,2643);

-- Arei "npc has two text, possible scripting required"
UPDATE `creature_template` SET `gossip_menu_id`=2063 WHERE `entry`=9598;
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry` IN (2063);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (2063,2726), (2063,2809);

/* 4.x removed
-- Add SAI for Un'Goro Crystal Pylon Quests 4285, 4287, 4288
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI',`ScriptName`= '' WHERE `entry` IN (164955,164957,164956);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (164955,164957,164956) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(164955, 1, 0, 0, 62, 0, 100, 0, 2177, 0, 0, 0, 15, 4285, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Northern Crystal Pylon - Gossip Option 0 - Complete quest 4285'),
(164957, 1, 0, 0, 62, 0, 100, 0, 2178, 0, 0, 0, 15, 4287, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eastern Crystal Pylon - Gossip Option 0 - Complete quest 4287'),
(164956, 1, 0, 0, 62, 0, 100, 0, 2179, 0, 0, 0, 15, 4288, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Western Crystal Pylon - Gossip Option 0 - Complete quest 4288');

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry` IN (2177,2178,2179,2180,2181,2182);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(2177,2810),(2177,2933),(2178,2810),(2178,2933),(2179,2810),(2179,2933),(2180,2811),(2181,2812),(2182,2813);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (2177,2178,2179);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(2177,0,0, 'I want to examine this pylon.',1,1,2181),
(2178,0,0, 'I want to examine this pylon.',1,1,2180),
(2179,0,0, 'I want to examine this pylon.',1,1,2182);
-- Gossip Options Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (2177,2178,2179);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,2177,0,0,0,9,0,4285,0,0,0,'','Gossip Option requires quest not complete'),
(15,2178,0,0,0,9,0,4287,0,0,0,'','Gossip Option requires quest not complete'),
(15,2179,0,0,0,9,0,4288,0,0,0,'','Gossip Option requires quest not complete');
*/
