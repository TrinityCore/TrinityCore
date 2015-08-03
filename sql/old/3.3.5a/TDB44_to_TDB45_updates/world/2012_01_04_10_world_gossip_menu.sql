-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=4005 AND `text_id`=4869;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4005,4869);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=4005 WHERE `entry`=4731;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (4005) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4005,1,1, 'I would like to buy from you.',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=940 AND `text_id`=1513;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (940,1513);
DELETE FROM `gossip_menu` WHERE `entry`=941 AND `text_id`=1517;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (941,1517);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=940 WHERE `entry`=7607;
UPDATE `creature_template` SET `gossip_menu_id`=941 WHERE `entry`=7604;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (941) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(941,1,0, 'That''s it!  I''m tired of helping you out.  It''s time we settled things on the battlefield!',1,1,0,0,0,0, '');

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=28621;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=5710 AND `text_id`=6878;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5710,6878);
DELETE FROM `gossip_menu` WHERE `entry`=5711 AND `text_id`=6879;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5711,6879);
DELETE FROM `gossip_menu` WHERE `entry`=5712 AND `text_id`=6880;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5712,6880);
DELETE FROM `gossip_menu` WHERE `entry`=5713 AND `text_id`=6881;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5713,6881);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=3623 WHERE `entry`=11556; -- 3624 in db. possible different gossip depending on faction?
UPDATE `creature_template` SET `gossip_menu_id`=5710 WHERE `entry`=14354;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (5710,5711,5712,5713) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(5710,0,0, 'Why you little...',1,1,0,0,0,0, ''),
(5711,0,0, 'Mark my words, I will catch you, imp. And when I do!',1,1,0,0,0,0, ''),
(5712,0,0, 'DIE!',1,1,0,0,0,0, ''),
(5713,0,0, 'Prepare to meet your maker.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8310 AND `text_id`=10373;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8310,10373);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8310 WHERE `entry`=20977;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8006 AND `text_id`=9871;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8006,9871);
DELETE FROM `gossip_menu` WHERE `entry`=8007 AND `text_id`=9872;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8007,9872);
DELETE FROM `gossip_menu` WHERE `entry`=8036 AND `text_id`=9922;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8036,9922);
DELETE FROM `gossip_menu` WHERE `entry`=8036 AND `text_id`=10045;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8036,10045);
DELETE FROM `gossip_menu` WHERE `entry`=8082 AND `text_id`=9990;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8082,9990);
DELETE FROM `gossip_menu` WHERE `entry`=8038 AND `text_id`=9925;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8038,9925);
DELETE FROM `gossip_menu` WHERE `entry`=7829 AND `text_id`=9579;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7829,9579);
DELETE FROM `gossip_menu` WHERE `entry`=7831 AND `text_id`=9580;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7831,9580);
DELETE FROM `gossip_menu` WHERE `entry`=7840 AND `text_id`=9597;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7840,9597);
DELETE FROM `gossip_menu` WHERE `entry`=7852 AND `text_id`=9613;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7852,9613);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8006 WHERE `entry`=19468;
UPDATE `creature_template` SET `gossip_menu_id`=8082 WHERE `entry`=20162;
UPDATE `creature_template` SET `gossip_menu_id`=8038 WHERE `entry`=19840;
UPDATE `creature_template` SET `gossip_menu_id`=7852 WHERE `entry`=18887;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8036,8082,7830,7829,7831,7840,7852) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8036,0,0, '<Begin emergency shutdown.>',1,1,8036,0,0,0, ''),
(8082,0,0, 'I''m as ready as I''ll ever be.',1,1,0,0,0,0, ''),
(7830,0,0, 'Taretha cannot see you, Thrall.',1,1,7829,0,0,0, ''),
(7829,0,0, 'The situation is rather complicated, Thrall. It would be best for you to head into the mountains now, before more of Blackmoore''s men show up. We''ll make sure Taretha is safe.',1,1,7831,0,0,0, ''),
(7831,0,0, 'Tarren Mill.',1,1,0,0,0,0, ''),
(7840,0,0, 'We''re ready, Thrall.',1,1,0,0,0,0, ''),
(7852,0,0, 'We''ll get you out, Taretha. Don''t worry. I doubt the wizard would wander too far away.',1,1,0,0,0,0, '');

-- Creature Gossip_menu_option Update from sniff
UPDATE `gossip_menu_option` SET `action_menu_id`=7829 WHERE `menu_id`=7830 AND `id`=0;

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9185 AND `text_id`=12475;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9185,12475);
DELETE FROM `gossip_menu` WHERE `entry`=9248 AND `text_id`=12556;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9248,12556);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9185 WHERE `entry`=25381;
UPDATE `creature_template` SET `gossip_menu_id`=9248 WHERE `entry`=26158;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=5232 AND `text_id`=6250;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5232,6250);
DELETE FROM `gossip_menu` WHERE `entry`=6813 AND `text_id`=8139;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6813,8139);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=5232 WHERE `entry`=13445;
UPDATE `creature_template` SET `gossip_menu_id`=6813 WHERE `entry`=15760;

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=6026;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=10171 AND `text_id`=14115;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10171,14115);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10171 WHERE `entry`=32301;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10026) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10026,1,0, 'Take me to the ship.',1,1,0,0,0,0, '');
