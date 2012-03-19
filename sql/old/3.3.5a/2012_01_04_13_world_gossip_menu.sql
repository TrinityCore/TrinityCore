-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8895 AND `text_id`=11667;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8895,11667);
DELETE FROM `gossip_menu` WHERE `entry`=8805 AND `text_id`=11291;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8805,11291);
DELETE FROM `gossip_menu` WHERE `entry`=10116 AND `text_id`=14042;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10116,14042);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8895 WHERE `entry`=24111;
UPDATE `creature_template` SET `gossip_menu_id`=8805 WHERE `entry`=23733;
UPDATE `creature_template` SET `gossip_menu_id`=10116 WHERE `entry`=26914;
UPDATE `creature_template` SET `gossip_menu_id`=9879 WHERE `entry`=26916;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10116) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10116,0,3, 'Train me.',5,16,0,0,0,0, '');
-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID` IN (11291);
INSERT INTO `npc_text` (`ID`,`prob0`,`text0_0`,`text0_1`,`lang0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`prob1`,`text1_0`,`text1_1`,`lang1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`prob2`,`text2_0`,`text2_1`,`lang2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`prob3`,`text3_0`,`text3_1`,`lang3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`prob4`,`text4_0`,`text4_1`,`lang4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`prob5`,`text5_0`,`text5_1`,`lang5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`prob6`,`text6_0`,`text6_1`,`lang6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`prob7`,`text7_0`,`text7_1`,`lang7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(11291,1,'When I grow up I want to be a stable man!','',0,0,1,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1);

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7434 AND `text_id`=8983;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7434,8983);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=7434 WHERE `entry`=17440;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=10922 AND `text_id`=15171;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10922,15171);
DELETE FROM `gossip_menu` WHERE `entry`=10950 AND `text_id`=15215;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10950,15215);
DELETE FROM `gossip_menu` WHERE `entry`=10909 AND `text_id`=15157;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10909,15157);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10922 WHERE `entry`=37592;
UPDATE `creature_template` SET `gossip_menu_id`=10950 WHERE `entry`=37223;
UPDATE `creature_template` SET `gossip_menu_id`=10909 WHERE `entry`=37554;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10950) AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10909) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10950,0,0, 'Can you remove the sword?',1,1,0,0,0,0, ''),
(10950,1,0, 'Dark Lady, I think I hear Arthas coming. Whatever you''re going to do, do it quickly.',1,1,0,0,0,0, ''),
(10909,0,0, 'We''re ready! Let''s go!',1,1,0,0,0,0, '');
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9024 AND `text_id`=12194;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9024,12194);

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9024) AND `id` IN (0,1,2,3);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9024,0,0, '<Get on the work bench and let Walt put you in the golem suit.>',1,1,0,0,0,0, ''),
(9024,1,0, '<Get on the work bench and let Walt put you in the golem suit.>',1,1,0,0,0,0, ''),
(9024,2,0, '<Get on the work bench and let Walt put you in the golem suit.>',1,1,0,0,0,0, ''),
(9024,3,0, '<Get on the work bench and let Walt put you in the golem suit.>',1,1,0,0,0,0, '');

-- Gossip conditions
SET @ID := 9024;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@ID,0,0,9,11485,0,0,0,'','Show gossip option if player has quest Iron Rune Constructs and You: Rocket Jumping'),
(15,@ID,1,0,9,11489,0,0,0,'','Show gossip option if player has quest Iron Rune Constructs and You: Collecting Data'),
(15,@ID,2,0,9,11491,0,0,0,'','Show gossip option if player has quest Iron Rune Constructs and You: The Bluff'),
(15,@ID,3,0,9,11494,0,0,0,'','Show gossip option if player has quest Lightning Infused Relics');


-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8560 AND `text_id`=10723;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8560,10723);

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9562 AND `text_id`=12881;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9562,12881);
DELETE FROM `gossip_menu` WHERE `entry`=9562 AND `text_id`=12882;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9562,12882);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9562 WHERE `entry`=27318;

-- Gossip conditions
SET @ID := 9562;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@ID,12882,0,8,12311,0,0,0,'','Show gossip text if player completed quest The Noble''s Crypt');

UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=14354;

