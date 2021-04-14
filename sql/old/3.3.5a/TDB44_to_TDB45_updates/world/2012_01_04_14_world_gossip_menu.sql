-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9635 AND `text_id`=13322;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9635,13322);
DELETE FROM `gossip_menu` WHERE `entry`=9724 AND `text_id`=13307;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9724,13307);
DELETE FROM `gossip_menu` WHERE `entry`=9720 AND `text_id`=13303;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9720,13303);
DELETE FROM `gossip_menu` WHERE `entry`=9688 AND `text_id`=13147;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9688,13147);
DELETE FROM `gossip_menu` WHERE `entry`=9738 AND `text_id`=13352;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9738,13352);
DELETE FROM `gossip_menu` WHERE `entry`=9723 AND `text_id`=13306;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9723,13306);
DELETE FROM `gossip_menu` WHERE `entry`=9721 AND `text_id`=13304;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9721,13304);
DELETE FROM `gossip_menu` WHERE `entry`=9722 AND `text_id`=13305;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9722,13305);
DELETE FROM `gossip_menu` WHERE `entry`=9748 AND `text_id`=13366;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9748,13366);
DELETE FROM `gossip_menu` WHERE `entry`=9677 AND `text_id`=13124;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9677,13124);
DELETE FROM `gossip_menu` WHERE `entry`=9679 AND `text_id`=13124;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9679,13124);
DELETE FROM `gossip_menu` WHERE `entry`=9684 AND `text_id`=13124;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9684,13124);
DELETE FROM `gossip_menu` WHERE `entry`=9742 AND `text_id`=13361;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9742,13361);
DELETE FROM `gossip_menu` WHERE `entry`=9678 AND `text_id`=13137;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9678,13137);
DELETE FROM `gossip_menu` WHERE `entry`=9686 AND `text_id`=13138;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9686,13138);
DELETE FROM `gossip_menu` WHERE `entry`=9743 AND `text_id`=13362;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9743,13362);
DELETE FROM `gossip_menu` WHERE `entry`=9746 AND `text_id`=13365;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9746,13365);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9724 WHERE `entry`=28604;
UPDATE `creature_template` SET `gossip_menu_id`=9720 WHERE `entry`=27801;
UPDATE `creature_template` SET `gossip_menu_id`=9688 WHERE `entry`=28376;
UPDATE `creature_template` SET `gossip_menu_id`=9738 WHERE `entry`=28771;
UPDATE `creature_template` SET `gossip_menu_id`=9723 WHERE `entry`=28374;
UPDATE `creature_template` SET `gossip_menu_id`=9748 WHERE `entry`=28216;
UPDATE `creature_template` SET `gossip_menu_id`=9677 WHERE `entry`=28217;
UPDATE `creature_template` SET `gossip_menu_id`=9742 WHERE `entry`=28027;
UPDATE `creature_template` SET `gossip_menu_id`=9678 WHERE `entry`=28315;
UPDATE `creature_template` SET `gossip_menu_id`=9743 WHERE `entry`=28114;
UPDATE `creature_template` SET `gossip_menu_id`=9746 WHERE `entry`=28122;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9804,9750,9713,9720,9721,9722,9674,9677,9684,9678,9686,9728,2384,1624) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10024,9724,2384) AND `id` IN (1);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9742,2384) AND `id` IN (2);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10024,1,0, 'I''m ready to fly to Sholazar Basin.',1,1,0,0,0,0, ''),
(9804,0,1, 'Show me what you have for sale.',3,128,0,0,0,0, ''),
(9750,0,3, 'Train me.',5,16,0,0,0,0, ''),
(9724,1,0, 'Have a spare bunch of bananas?',1,1,0,0,0,0, ''),
(9713,0,0, 'I''m ready to start the distillation, uh, Tipsy.',1,1,0,0,0,0, ''),
(9720,0,0, 'I want to stop the Scourge as much as you do.  How can I help?',1,1,9721,0,0,0, ''),
(9721,0,0, 'You can trust me.  I am no friend of the Lich King''s.',1,1,9722,0,0,0, ''),
(9722,0,0, 'I will not fail.',1,1,0,0,0,0, ''),
(9674,0,0, 'You look safe enough... let''s do this.',1,1,0,0,0,0, ''),
(9677,0,0, '<Reach down and pull the Injured Rainspeaker Oracle to its feet.>',1,1,0,0,0,0, ''),
(9684,0,0, 'I am ready to travel to your village now.',1,1,0,0,0,0, ''),
(9678,0,0, 'Shaman Vekjik, I have spoken with the big-tongues and they desire peace. I have brought this offering on their behalf.',1,1,9686,0,0,0, ''),
(9686,0,0, 'No no... I had no intentions of betraying your people. I was only defending myself. It was all a misunderstanding.',1,1,0,0,0,0, ''),
(9742,2,0, 'I need to find Jaloot, do you have his favorite crystal?',1,1,0,0,0,0, ''),
(9728,0,0, '<Check for a pulse...>',1,1,0,0,0,0, ''),
(2384,0,3, 'I am interested in warlock training.',5,16,0,0,0,0, ''),
(2384,1,0, 'I wish to unlearn my talents.',16,16,0,0,0,0, ''),
(2384,2,0, 'I wish to know about Dual Talent Specialization.',1,1,0,0,0,0, ''),
(1624,0,1, 'I want to browse your goods.',3,128,0,0,0,0, '');
