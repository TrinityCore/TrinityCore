-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9130,9495,9879,9893,9988,10115) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9879 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9130,0,1, 'I want to browse your goods.',3,128,0,0,0,0, ''),
(9495,0,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),
(9879,0,3, 'Train me',5,16,0,0,0,0, ''),
(9879,1,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),
(9893,0,3, 'Train me',5,16,0,0,0,0, ''),
(9988,0,3, 'Train me',5,16,0,0,0,0, ''),
(10115,0,3, 'Train me',5,16,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9130 AND `text_id`=12343;
DELETE FROM `gossip_menu` WHERE `entry`=9130 AND `text_id`=12344;
DELETE FROM `gossip_menu` WHERE `entry`=9133 AND `text_id`=12349;
DELETE FROM `gossip_menu` WHERE `entry`=9133 AND `text_id`=12350;
DELETE FROM `gossip_menu` WHERE `entry`=9134 AND `text_id`=12354;
DELETE FROM `gossip_menu` WHERE `entry`=9134 AND `text_id`=12352;
DELETE FROM `gossip_menu` WHERE `entry`=9137 AND `text_id`=12360;
DELETE FROM `gossip_menu` WHERE `entry`=9137 AND `text_id`=12361;
DELETE FROM `gossip_menu` WHERE `entry`=9138 AND `text_id`=12362;
DELETE FROM `gossip_menu` WHERE `entry`=9138 AND `text_id`=12363;
DELETE FROM `gossip_menu` WHERE `entry`=9153 AND `text_id`=12384;
DELETE FROM `gossip_menu` WHERE `entry`=9154 AND `text_id`=12387;
DELETE FROM `gossip_menu` WHERE `entry`=9158 AND `text_id`=12394;
DELETE FROM `gossip_menu` WHERE `entry`=9159 AND `text_id`=12395;
DELETE FROM `gossip_menu` WHERE `entry`=9160 AND `text_id`=12403;
DELETE FROM `gossip_menu` WHERE `entry`=9170 AND `text_id`=12433;
DELETE FROM `gossip_menu` WHERE `entry`=9172 AND `text_id`=12440;
DELETE FROM `gossip_menu` WHERE `entry`=9173 AND `text_id`=12441;
DELETE FROM `gossip_menu` WHERE `entry`=9210 AND `text_id`=12521;
DELETE FROM `gossip_menu` WHERE `entry`=9214 AND `text_id`=12525;
DELETE FROM `gossip_menu` WHERE `entry`=9216 AND `text_id`=12527;
DELETE FROM `gossip_menu` WHERE `entry`=9219 AND `text_id`=12530;
DELETE FROM `gossip_menu` WHERE `entry`=9223 AND `text_id`=13481;
DELETE FROM `gossip_menu` WHERE `entry`=9224 AND `text_id`=12538;
DELETE FROM `gossip_menu` WHERE `entry`=9247 AND `text_id`=12555;
DELETE FROM `gossip_menu` WHERE `entry`=9280 AND `text_id`=12585;
DELETE FROM `gossip_menu` WHERE `entry`=9417 AND `text_id`=12663;
DELETE FROM `gossip_menu` WHERE `entry`=9495 AND `text_id`=12781;
DELETE FROM `gossip_menu` WHERE `entry`=9685 AND `text_id`=13134;
DELETE FROM `gossip_menu` WHERE `entry`=9685 AND `text_id`=13135;
DELETE FROM `gossip_menu` WHERE `entry`=9893 AND `text_id`=13735;
DELETE FROM `gossip_menu` WHERE `entry`=9988 AND `text_id`=13842;
DELETE FROM `gossip_menu` WHERE `entry`=10115 AND `text_id`=14041;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9130,12343),(9130,12344),
(9133,12349),(9133,12350),
(9134,12354),(9134,12352),
(9137,12360),(9137,12361),
(9138,12362),(9138,12363),
(9153,12384),(9154,12387),
(9158,12394),(9159,12395),
(9160,12403),(9170,12433),
(9172,12440),(9173,12441),
(9210,12521),(9214,12525),
(9216,12527),(9219,12530),
(9223,13481),(9224,12538),
(9247,12555),(9280,12585),
(9417,12663),(9495,12781),
(9685,13134),(9685,13135),
(9893,13735),(9988,13842),
(10115,14041);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (9130,9133,9134,9137,9138,9685);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9130,12344,0,8,11571,0,0,0,'','Ahlurglgr - Show different gossip if player has rewarded quest 11571'),
(14,9133,12350,0,8,11571,0,0,0,'','Brglmurgl - Show different gossip if player has rewarded quest 11571'),
(14,9134,12354,0,14,11571,0,0,0,'','Mrmrglmr - Show different gossip if player has not rewarded quest 11571'),
(14,9137,12361,0,8,11571,0,0,0,'','Lurgglbr - Show different gossip if player has rewarded quest 11571'),
(14,9138,12363,0,8,11571,0,0,0,'','Winterfin Gatherer - Show different gossip if player has rewarded quest 11571'),
(14,9685,13135,0,8,11571,0,0,0,'','Glrglrglr - Show different gossip if player has rewarded quest 11571');

-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID`=13481;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(13481,'','I''ll never forget what you did for Thassarian.  I will always be in your debt.',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9130 WHERE `entry`=25206; -- Ahlurglgr
UPDATE `creature_template` SET `gossip_menu_id`=9133 WHERE `entry`=25199; -- Brglmurgl
UPDATE `creature_template` SET `gossip_menu_id`=9134 WHERE `entry`=25205; -- Mrmrglmr
UPDATE `creature_template` SET `gossip_menu_id`=9137 WHERE `entry`=25208; -- Lurgglbr
UPDATE `creature_template` SET `gossip_menu_id`=9138 WHERE `entry`=25198; -- Winterfin Gatherer
UPDATE `creature_template` SET `gossip_menu_id`=9153 WHERE `entry`=25336; -- Grunt Ragefist
UPDATE `creature_template` SET `gossip_menu_id`=9154 WHERE `entry`=25339; -- Spirit Talker Snarlfang
UPDATE `creature_template` SET `gossip_menu_id`=9158 WHERE `entry`=25374; -- Ortrosh
UPDATE `creature_template` SET `gossip_menu_id`=9159 WHERE `entry`=25376; -- Imperean
UPDATE `creature_template` SET `gossip_menu_id`=9160 WHERE `entry`=25335; -- Longrunner Proudhoof
UPDATE `creature_template` SET `gossip_menu_id`=9170 WHERE `entry`=25589; -- Bonker Togglevolt
UPDATE `creature_template` SET `gossip_menu_id`=9172 WHERE `entry`=25602; -- Greatmother Taiga
UPDATE `creature_template` SET `gossip_menu_id`=9173 WHERE `entry`=25604; -- Sage Highmesa
UPDATE `creature_template` SET `gossip_menu_id`=9210 WHERE `entry`=26085; -- Wendy Darren
UPDATE `creature_template` SET `gossip_menu_id`=9214 WHERE `entry`=26084; -- Jeremiah Hawning
UPDATE `creature_template` SET `gossip_menu_id`=9216 WHERE `entry`=25285; -- Harbinger Vurenn
UPDATE `creature_template` SET `gossip_menu_id`=9219 WHERE `entry`=25828; -- Guard Mitchells
UPDATE `creature_template` SET `gossip_menu_id`=9223 WHERE `entry`=25251; -- Leryssa
UPDATE `creature_template` SET `gossip_menu_id`=9224 WHERE `entry`=26083; -- Gerald Green
UPDATE `creature_template` SET `gossip_menu_id`=9247 WHERE `entry`=25395; -- Private Brau
UPDATE `creature_template` SET `gossip_menu_id`=9280 WHERE `entry`=26219; -- Iruk
UPDATE `creature_template` SET `gossip_menu_id`=9417 WHERE `entry`=26170; -- Thassarian
UPDATE `creature_template` SET `gossip_menu_id`=9495 WHERE `entry`=26110; -- Librarian Serrah
UPDATE `creature_template` SET `gossip_menu_id`=9685 WHERE `entry`=28375; -- Glrglrglr
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=27065; -- Breka Wolfsister
UPDATE `creature_template` SET `gossip_menu_id`=9879 WHERE `entry`=26977; -- Adelene Sunlance
UPDATE `creature_template` SET `gossip_menu_id`=9893 WHERE `entry`=26982; -- Geba'li
UPDATE `creature_template` SET `gossip_menu_id`=9988 WHERE `entry`=26972; -- Orn Tenderhoof
UPDATE `creature_template` SET `gossip_menu_id`=10115 WHERE `entry`=26969; -- Raenah
