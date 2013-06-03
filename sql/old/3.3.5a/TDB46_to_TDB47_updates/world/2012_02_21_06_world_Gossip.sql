-- Gossip Update from Pitcrawler
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=7692 WHERE `entry`=18424;
UPDATE `creature_template` SET `gossip_menu_id`=9033 WHERE `entry`=24838;
UPDATE `creature_template` SET `gossip_menu_id`=9038 WHERE `entry`=24833;
UPDATE `creature_template` SET `gossip_menu_id`=9066 WHERE `entry`=25011;
UPDATE `creature_template` SET `gossip_menu_id`=9067 WHERE `entry`=25015;
UPDATE `creature_template` SET `gossip_menu_id`=9068 WHERE `entry`=25009;
UPDATE `creature_template` SET `gossip_menu_id`=9069 WHERE `entry`=25017;
UPDATE `creature_template` SET `gossip_menu_id`=9070 WHERE `entry`=25018;
UPDATE `creature_template` SET `gossip_menu_id`=9071 WHERE `entry`=25016;
UPDATE `creature_template` SET `gossip_menu_id`=9072 WHERE `entry` IN (25013,25014);
UPDATE `creature_template` SET `gossip_menu_id`=9091 WHERE `entry`=25076;
UPDATE `creature_template` SET `gossip_menu_id`=9107 WHERE `entry`=24929;
UPDATE `creature_template` SET `gossip_menu_id`=9109 WHERE `entry`=24927;
UPDATE `creature_template` SET `gossip_menu_id`=9110 WHERE `entry`=24924;
UPDATE `creature_template` SET `gossip_menu_id`=9116 WHERE `entry`=25105;
UPDATE `creature_template` SET `gossip_menu_id`=9117 WHERE `entry`=25100;
UPDATE `creature_template` SET `gossip_menu_id`=9118 WHERE `entry`=25104;
UPDATE `creature_template` SET `gossip_menu_id`=9120 WHERE `entry`=25107;
UPDATE `creature_template` SET `gossip_menu_id`=9121 WHERE `entry` IN (25101,25102,25103);
UPDATE `creature_template` SET `gossip_menu_id`=9122 WHERE `entry`=25106;
UPDATE `creature_template` SET `gossip_menu_id`=9349 WHERE `entry`=26539;
UPDATE `creature_template` SET `gossip_menu_id`=10120 WHERE `entry` IN (31704,31705,31706,31720,31723,31724);
UPDATE `creature_template` SET `gossip_menu_id`=10259 WHERE `entry`=31716;

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7692 AND `text_id`=9383;
DELETE FROM `gossip_menu` WHERE `entry`=7696 AND `text_id`=9444;
DELETE FROM `gossip_menu` WHERE `entry`=7704 AND `text_id`=9425;
DELETE FROM `gossip_menu` WHERE `entry`=7726 AND `text_id`=9437;
DELETE FROM `gossip_menu` WHERE `entry`=7727 AND `text_id`=9438;
DELETE FROM `gossip_menu` WHERE `entry`=7728 AND `text_id`=9439;
DELETE FROM `gossip_menu` WHERE `entry`=9033 AND `text_id`=12211;
DELETE FROM `gossip_menu` WHERE `entry`=9038 AND `text_id`=12216;
DELETE FROM `gossip_menu` WHERE `entry`=9040 AND `text_id`=12217;
DELETE FROM `gossip_menu` WHERE `entry`=9041 AND `text_id`=12218;
DELETE FROM `gossip_menu` WHERE `entry`=9042 AND `text_id`=12219;
DELETE FROM `gossip_menu` WHERE `entry`=9043 AND `text_id`=12220;
DELETE FROM `gossip_menu` WHERE `entry`=9066 AND `text_id`=12262;
DELETE FROM `gossip_menu` WHERE `entry`=9067 AND `text_id`=12263;
DELETE FROM `gossip_menu` WHERE `entry`=9068 AND `text_id`=12264;
DELETE FROM `gossip_menu` WHERE `entry`=9069 AND `text_id`=12266;
DELETE FROM `gossip_menu` WHERE `entry`=9070 AND `text_id`=12267;
DELETE FROM `gossip_menu` WHERE `entry`=9091 AND `text_id`=12292;
DELETE FROM `gossip_menu` WHERE `entry`=9109 AND `text_id`=12317;
DELETE FROM `gossip_menu` WHERE `entry`=9110 AND `text_id`=12318;
DELETE FROM `gossip_menu` WHERE `entry`=9116 AND `text_id`=12327;
DELETE FROM `gossip_menu` WHERE `entry`=9117 AND `text_id`=12328;
DELETE FROM `gossip_menu` WHERE `entry`=9118 AND `text_id`=12329;
DELETE FROM `gossip_menu` WHERE `entry`=9120 AND `text_id`=12331;
DELETE FROM `gossip_menu` WHERE `entry`=9121 AND `text_id`=12332;
DELETE FROM `gossip_menu` WHERE `entry`=9122 AND `text_id`=12333;
DELETE FROM `gossip_menu` WHERE `entry`=9349 AND `text_id`=12649;
DELETE FROM `gossip_menu` WHERE `entry`=10120 AND `text_id`=14047;
DELETE FROM `gossip_menu` WHERE `entry`=10259 AND `text_id`=14248;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7692,9383),
(7696,9444),
(7704,9425),
(7726,9437),
(7727,9438),
(7728,9439),
(9033,12211),
(9038,12216),
(9040,12217),
(9041,12218),
(9042,12219),
(9043,12220),
(9066,12262),
(9067,12263),
(9068,12264),
(9069,12266),
(9070,12267),
(9091,12292),
(9109,12317),
(9110,12318),
(9116,12327),
(9117,12328),
(9118,12329),
(9120,12331),
(9121,12332),
(9122,12333),
(9349,12649),
(10120,14047),
(10259,14248);

-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID` IN (9437,9438,9439,12211,12266);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(9437,'<Warden Treelos looks at you funny and then pauses a moment, clearly struggling.>$B$BZangarmarsh... too close to truth.$B$B<His face goes crazy again.>$B$BIs he still watching!?','',0,1,1000,1,1000,6,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(9438,'What''s that?  Zangarmarsh?  Why would I want to go there?$B$B<Treelos looks thoughtful.>$B$BYes, Zangarmarsh... we... the druids there are getting close to figuring out why the water level is dropping.  It''s destroying everything!$B$B<You can see the insanity creep back in behind the warden''s eyes.>$B$BDestroyed us all!  Bright light!  BOOM!!','',0,1,0,6,1000,1,1000,5,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(9439,'The Firewing blood elves... for some reason they want to stop us.$B$B<Warden Treelos visibly struggles to keep his wits about him for a few more seconds.>$B$BThey... they sent one of the Broken as ... as an emissary....  But he had a bomb!$B$BThey died, they all died!  They tried to run away!  The lucky ones didn''t even know.$B$BI must have been at the edge of the blast.  It was horr...IT''S WATCHING US AGAIN!$B$B<Treelos becomes despondent and looks straight through you as if you''re not there.>','',0,1,0,18,1000,18,1000,5,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(12211,'Fine day fer sailin'', innit?','',7,1,0,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(12266,'','I''m almost jealous of our Mr. Wavesinger. Why, he may well be prettier than me!',7,1,0,1,3,11,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);

-- Creature Gossip_menu_option insert from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7692,7726,7727) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9038,9040,9041,9042,9043) AND `id` IN (0,1,2);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9038 AND `id`=3;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(7692,0,0,'Treelos, I know that the truth is somewhere inside you.  Tell me what it is.',1,1,7726,0,0,0,''),
(7726,0,0,'Keep it together man!  What about Zangarmarsh?',1,1,7727,0,0,0,''),
(7727,0,0,'I don''t have time for this!  Warden, what happened?!',1,1,7728,0,0,0,''),
(9038,0,0,'The Lady Mehley',1,1,9040,0,0,0,''),
(9038,1,0,'Food & Drink',1,1,9041,0,0,0,''),
(9038,2,0,'Goods & Gear',1,1,9042,0,0,0,''),
(9038,3,0,'"Stash?"',1,1,9043,0,0,0,''),
(9040,0,0,'Food & Drink',1,1,9041,0,0,0,''),
(9040,1,0,'Goods & Gear',1,1,9042,0,0,0,''),
(9040,2,0,'"Stash?',1,1,9043,0,0,0,''),
(9041,0,0,'The Lady Mehley',1,1,9040,0,0,0,''),
(9041,1,0,'Goods & Gear',1,1,9042,0,0,0,''),
(9041,2,0,'"Stash?',1,1,9043,0,0,0,''),
(9042,0,0,'The Lady Mehley',1,1,9040,0,0,0,''),
(9042,1,0,'Food & Drink',1,1,9041,0,0,0,''),
(9042,2,0,'"Stash?',1,1,9043,0,0,0,''),
(9043,0,0,'The Lady Mehley',1,1,9040,0,0,0,''),
(9043,1,0,'Food & Drink',1,1,9041,0,0,0,''),
(9043,2,0,'Goods & Gear',1,1,9042,0,0,0,'');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7704 AND `SourceEntry`=9425;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7696 AND `SourceEntry`=9444;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (7704,7692);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7696,9444,0,0,8,10005,0,0,0,0,'','Show different gossip if player has rewarded quest 10005'),
(14,7696,9444,0,1,8,10006,0,0,0,0,'','Show different gossip if player has rewarded quest 10006'),
(14,7704,9425,0,0,8,9978,0,0,0,0,'','Show different gossip if player has rewarded quest 9978'),
(15,7704,0,0,0,9,9978,0,0,0,0,'','Show gossip option if player has quest 9978 but not complete'),
(15,7692,0,0,0,8,10006,0,0,0,0,'','Show gossip option if player has rewarded quest 10006'),
(15,7692,0,0,1,8,10005,0,0,0,0,'','Show gossip option if player has rewarded quest 10005');

-- Gossip Update from Malcrom
DELETE FROM `gossip_menu` WHERE `entry` IN (1042,1043,1044,1045,1046,1047,1048,1049,1050,1052,1053);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(1042,1635),(1043,1640),(1044,1644),(1045,1643),(1045,1753),
(1046,1648),(1047,1754),(1048,1650),(1049,1755),
(1050,1651),(1050,1756),(1052,1652),(1053,1653);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1045,1047,1049,1050);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1045,0,0,'Acquire Higher Level Access Card',1,1,0,0,0,0,''),
(1047,0,0,'Acquire Higher Level Access Card',1,1,0,0,0,0,''),
(1049,0,0,'Acquire Higher Level Access Card',1,1,0,0,0,0,''),
(1050,0,0,'Acquire high level data card.',1,1,0,0,0,0,'');

DELETE FROM `gossip_menu` WHERE `entry`=1080 AND `text_id`=1693;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1080,1693);
DELETE FROM `gossip_menu` WHERE `entry`=1100 AND `text_id`=1713;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1100,1713);
DELETE FROM `gossip_menu` WHERE `entry`=1143 AND `text_id`=1759;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1143,1759);
DELETE FROM `gossip_menu` WHERE `entry`=1161 AND `text_id`=1793;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1161,1793);
DELETE FROM `gossip_menu` WHERE `entry`=1162 AND `text_id`=1794;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1162,1794);
DELETE FROM `gossip_menu` WHERE `entry`=1201 AND `text_id`=1833;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1201,1833);
DELETE FROM `gossip_menu` WHERE `entry`=1281 AND `text_id`=1916;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1281,1916);
DELETE FROM `gossip_menu` WHERE `entry`=1282 AND `text_id`=1918;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1282,1918);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1282);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1282,0,0,'Touch the Suntara stone and call forth Lathoric the Black and his guardian, Obsidion.',1,1,0,0,0,0,'');

DELETE FROM `gossip_menu` WHERE `entry`=1301 AND `text_id`=1933;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1301,1933);
DELETE FROM `gossip_menu` WHERE `entry`=1301 AND `text_id`=1934;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1301,1934);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1301);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1301,0,0,'I wish to browse your wares.',3,128,0,0,0,0,'');

DELETE FROM `gossip_menu` WHERE `entry`=1302 AND `text_id`=1935;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1302,1935);
DELETE FROM `gossip_menu` WHERE `entry`=1321 AND `text_id`=1955;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1321,1955);
DELETE FROM `gossip_menu` WHERE `entry`=1322 AND `text_id`=1954;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1322,1954);
DELETE FROM `gossip_menu` WHERE `entry`=1362 AND `text_id`=1994;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1362,1994);
