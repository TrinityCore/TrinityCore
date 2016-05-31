-- Gossip fixup for Aleanna Edune
UPDATE `creature_template` SET `gossip_menu_id`=361 WHERE `entry`=24734;
DELETE FROM `gossip_menu` WHERE `entry` IN (361);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (361,838);

-- Gossip fixup for Marli Wishrunner
UPDATE `creature_template` SET `gossip_menu_id`=1421 WHERE `entry`=7773;
DELETE FROM `gossip_menu` WHERE `entry` IN (1421);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (1421,2053);

-- Gossip fixup for Kalin Windflight "This guy may be missing a script"
UPDATE `creature_template` SET `gossip_menu_id`=1422 WHERE `entry`=7772;
DELETE FROM `gossip_menu` WHERE `entry` IN (1422);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (1422,2054);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1422);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(1422,0,1, 'Can you help me get down?',3,128,0);

-- Gossip fixup for Henry Stern
UPDATE `creature_template` SET `gossip_menu_id`=1443 WHERE `entry`=8696;
DELETE FROM `gossip_menu` WHERE `entry` IN (1442,1443,1444,1501,1502);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(1442,2115),(1443,2113),(1444,2114),(1501,2173),(1502,2174);
-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1443);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(1443,0,0, 'You can cook?  So can I!  Is there a recipe you can teach me?',1,1,0),
(1443,1,0, 'You''re an alchemist?  So am I.  Perhaps you can teach me what you know...',1,1,0);

-- Gossip Options Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1443;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1443,0,0,0,7,0,185,0,0,0,0,'','Gossip Option requires cooking skill'),
(15,1443,0,0,1,25,0,13028,0,0,1,0,'','Gossip Option requires player not learned spell'),
(15,1443,1,0,0,7,0,171,0,0,0,0,'','Gossip Option requires alchemy skill'),
(15,1443,1,0,1,25,0,3451,0,0,1,0,'','Gossip Option requires player not learned spell');
