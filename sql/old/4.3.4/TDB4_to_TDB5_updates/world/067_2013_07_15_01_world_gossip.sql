-- Gossip fixup for Drull and Tog'thar
UPDATE `creature_template` SET `gossip_menu_id`=262 WHERE `entry`=2239;
DELETE FROM `gossip_menu` WHERE `entry` IN (261,262,263);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
('261','760'), ('262','759'), ('263','762');
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (262,264);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(262,0,0, 'Where is the key to this lock?',1,1,261),
(264,1,0, 'Where is the key to this lock?',1,1,263);
-- Gossip Options Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (262,264);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,262,0,0,0,9,0,498,0,0,0,'','Gossip Option requires quest not complete'),
(15,264,1,0,0,9,0,498,0,0,0,'','Gossip Option requires quest not complete');
