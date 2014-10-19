-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=10987 AND `text_id`=15275;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10987,15275);
DELETE FROM `gossip_menu` WHERE `entry`=10974 AND `text_id`=15251;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10974,15251);
DELETE FROM `gossip_menu` WHERE `entry`=10986 AND `text_id`=15263;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10986,15263);
DELETE FROM `gossip_menu` WHERE `entry`=11112 AND `text_id`=15468;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11112,15468);
DELETE FROM `gossip_menu` WHERE `entry`=11126 AND `text_id`=15468;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11126,15468);
DELETE FROM `gossip_menu` WHERE `entry`=11130 AND `text_id`=15484;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11130,15484);
DELETE FROM `gossip_menu` WHERE `entry`=11131 AND `text_id`=15485;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11131,15485);
DELETE FROM `gossip_menu` WHERE `entry`=11137 AND `text_id`=15490;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11137,15490);
DELETE FROM `gossip_menu` WHERE `entry`=11020 AND `text_id`=15318;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11020,15318);
DELETE FROM `gossip_menu` WHERE `entry`=11107 AND `text_id`=15458;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11107,15458);
DELETE FROM `gossip_menu` WHERE `entry`=11127 AND `text_id`=15468;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11127,15468);
DELETE FROM `gossip_menu` WHERE `entry`=10985 AND `text_id`=15263;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10985,15263);
DELETE FROM `gossip_menu` WHERE `entry`=11645 AND `text_id`=15263;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11645,15263);
DELETE FROM `gossip_menu` WHERE `entry`=11933 AND `text_id`=16751;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11933,16751);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10987 WHERE `entry`=38246;
UPDATE `creature_template` SET `gossip_menu_id`=10974 WHERE `entry`=39062;
UPDATE `creature_template` SET `gossip_menu_id`=10986 WHERE `entry`=38245;
UPDATE `creature_template` SET `gossip_menu_id`=11112 WHERE `entry`=38966;
UPDATE `creature_template` SET `gossip_menu_id`=11130 WHERE `entry`=37987;
UPDATE `creature_template` SET `gossip_menu_id`=11131 WHERE `entry`=38989;
UPDATE `creature_template` SET `gossip_menu_id`=11137 WHERE `entry`=38442;
UPDATE `creature_template` SET `gossip_menu_id`=11020 WHERE `entry`=38225;
UPDATE `creature_template` SET `gossip_menu_id`=11107 WHERE `entry`=38437;
UPDATE `creature_template` SET `gossip_menu_id`=10985 WHERE `entry`=38244;
UPDATE `creature_template` SET `gossip_menu_id`=11645 WHERE `entry`=42618;
UPDATE `creature_template` SET `gossip_menu_id`=5665 WHERE `entry`=5941;
UPDATE `creature_template` SET `gossip_menu_id`=11912 WHERE `entry`=50006;
UPDATE `creature_template` SET `gossip_menu_id`=12050 WHERE `entry`=50015;
UPDATE `creature_template` SET `gossip_menu_id`=11932 WHERE `entry`=49998;
UPDATE `creature_template` SET `gossip_menu_id`=3644 WHERE `entry`=50001;
UPDATE `creature_template` SET `gossip_menu_id`=11933 WHERE `entry`=50002;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10987,11131,11020,11107,11127,11933,3162) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10974) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10987,0,3, 'I am interested in mage training.',5,16,0,0,0,0, ''),
(10974,1,0, 'I''m ready to face my challenge.',1,1,0,0,0,0, ''),
(11131,0,0, 'Yes.  Do you have a raptor that can take me there?',1,1,0,0,0,0, ''),
(11020,0,0, 'I am ready, Vol''jin.',1,1,0,0,0,0, ''),
(11107,0,0, 'Take me back to Darkspear Hold if you would, Vanira.',1,1,0,0,0,0, ''),
(11127,0,0, 'You spoke of communing with Thrall?  Did I miss it?',1,1,0,0,0,0, ''),
(11933,0,3, 'I am interested in mage training.',5,16,0,0,0,0, ''),
(3162,0,1, 'I would like to buy from you.',3,128,0,0,0,0, '');
-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID` IN (15275,15263,15484,15485,16751);
INSERT INTO `npc_text` (`ID`,`prob0`,`text0_0`,`text0_1`,`lang0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`prob1`,`text1_0`,`text1_1`,`lang1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`prob2`,`text2_0`,`text2_1`,`lang2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`prob3`,`text3_0`,`text3_1`,`lang3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`prob4`,`text4_0`,`text4_1`,`lang4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`prob5`,`text5_0`,`text5_1`,`lang5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`prob6`,`text6_0`,`text6_1`,`lang6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`prob7`,`text7_0`,`text7_1`,`lang7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(15275,1,'Wit'' practice, ya''ll find that magic can be much stronga than any weapon.','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,14545),
(15263,1,'I can''t help ya. Go talk ta Soratha if ya want mage trainin''.','I can''t help ya. Go talk ta Soratha if ya want mage trainin''.',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,14545),
(15484,1,'People tink raptors wild and vicious, but little else. In truth, they be loyal and cunnin'' in ways ya hardly know.','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,14545),
(15485,1,'Ya want to join the attack on the naga?','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,14545),
(16751,1,'Greetin''s, $N.  Are ya here ta be learnin'' of de Hidden Arts?','Greetin''s, $N.  Are ya here ta be learnin'' of de Hidden Arts?',1,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,14545);
