-- Some Gossip updates
UPDATE `creature_template` SET `npcflag`=`npcflag`&~1 WHERE `entry` IN (239,353,658,1215,1233,2079);
UPDATE `creature_template` SET `gossip_menu_id`=5241 WHERE `entry` IN (22658,32099);
UPDATE `creature_template` SET `gossip_menu_id`=5124 WHERE `entry` IN (22571,32080);
UPDATE `creature_template` SET `gossip_menu_id`=5442 WHERE `entry` IN (22628);
UPDATE `creature_template` SET `gossip_menu_id`=6500 WHERE `entry` IN (22656);
UPDATE `creature_template` SET `gossip_menu_id`=7499 WHERE `entry` IN (20548);
UPDATE `creature_template` SET `gossip_menu_id`=9695 WHERE `entry` IN (31210);

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=1632 AND `text_id`=2289;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1632,2289);
DELETE FROM `gossip_menu` WHERE `entry`=4322 AND `text_id`=5494;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4322,5494);
DELETE FROM `gossip_menu` WHERE `entry`=2801 AND `text_id`=3494;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2801,3494);
DELETE FROM `gossip_menu` WHERE `entry`=2831 AND `text_id`=3523;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2831,3523);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=1632 WHERE `entry`=1340;
UPDATE `creature_template` SET `gossip_menu_id`=4322 WHERE `entry`=2057;
UPDATE `creature_template` SET `gossip_menu_id`=2801 WHERE `entry`=1154;
UPDATE `creature_template` SET `gossip_menu_id`=2831 WHERE `entry`=1156;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (2831) AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(2831,0,5, 'Make this inn your home.',8,65536,0,0,0,0, ''),
(2831,1,1, 'Let me browse your goods.',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9838 AND `text_id`=13349;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9838,13349);
DELETE FROM `gossip_menu` WHERE `entry`=10854 AND `text_id`=15066;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10854,15066);
DELETE FROM `gossip_menu` WHERE `entry`=10147 AND `text_id`=14091;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10147,14091);
DELETE FROM `gossip_menu` WHERE `entry`=9873 AND `text_id`=13690;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9873,13690);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9838 WHERE `entry`=28774;
UPDATE `creature_template` SET `gossip_menu_id`=9832 WHERE `entry`=28776;
UPDATE `creature_template` SET `gossip_menu_id`=10854 WHERE `entry`=36856;
UPDATE `creature_template` SET `gossip_menu_id`=10180 WHERE `entry`=29478;
UPDATE `creature_template` SET `gossip_menu_id`=10147 WHERE `entry`=31136;
UPDATE `creature_template` SET `gossip_menu_id`=9873 WHERE `entry`=28701;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9838,9873) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9838,9873,10180) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9838,0,8, 'I want to create a guild crest.',11,524288,0,0,0,0, ''),
(9838,1,7, 'How do I form a guild?',10,262144,0,0,0,0, ''),
(10180,1,1, 'I want to browse your goods.',3,128,0,0,0,0, ''),
(9873,0,3, 'Train me.',5,16,0,0,0,0, ''),
(9873,1,1, 'May I browse your epic gem recipes?',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=2061 AND `text_id`=2713;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2061,2713);
DELETE FROM `gossip_menu` WHERE `entry`=5818 AND `text_id`=6991;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5818,6991);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=2061 WHERE `entry`=9563;
UPDATE `creature_template` SET `gossip_menu_id`=5818 WHERE `entry`=14437;
UPDATE `creature_template` SET `gossip_menu_id`=10188 WHERE `entry`=31051;

-- Creature Gossip_menu_option Update from sniff
-- You must manually add delete statement
-- DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (5818) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(5818,0,1, 'Gorzeeki, I wish to make a purchase.',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8023 AND `text_id`=9899;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8023,9899);
DELETE FROM `gossip_menu` WHERE `entry`=8021 AND `text_id`=9896;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8021,9896);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8021 WHERE `entry`=19679;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8023,8021,4005) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8023,0,0, '<Push a random button.>',1,1,8023,0,0,0, ''),
(8021,0,1, 'Show me what you have for sale, "Slim."',3,128,0,0,0,0, ''),
(4005,0,1, 'I would like to buy from you.',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=4143 AND `text_id`=5136;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4143,5136);
DELETE FROM `gossip_menu` WHERE `entry`=6229 AND `text_id`=7403;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6229,7403);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9781 WHERE `entry`=29143;
UPDATE `creature_template` SET `gossip_menu_id`=4143 WHERE `entry`=2857;
UPDATE `creature_template` SET `gossip_menu_id`=6229 WHERE `entry`=7010;
UPDATE `creature_template` SET `gossip_menu_id`=9107 WHERE `entry`=24930;
UPDATE `creature_template` SET `gossip_menu_id`=9108 WHERE `entry`=25081;
UPDATE `creature_template` SET `gossip_menu_id`=9107 WHERE `entry`=24931;
UPDATE `creature_template` SET `gossip_menu_id`=9106 WHERE `entry`=24926;

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=4667 WHERE `entry`=906;

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=4644 AND `text_id`=5716;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4644,5716);
DELETE FROM `gossip_menu` WHERE `entry`=4045 AND `text_id`=4935;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4045,4935);
DELETE FROM `gossip_menu` WHERE `entry`=3926 AND `text_id`=4786;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3926,4786);
DELETE FROM `gossip_menu` WHERE `entry`=4006 AND `text_id`=4862;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4006,4862);
DELETE FROM `gossip_menu` WHERE `entry`=4012 AND `text_id`=4998;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4012,4998);
DELETE FROM `gossip_menu` WHERE `entry`=4185 AND `text_id`=5287;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4185,5287);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=4045 WHERE `entry`=2980;
UPDATE `creature_template` SET `gossip_menu_id`=5856 WHERE `entry`=5939;
UPDATE `creature_template` SET `gossip_menu_id`=10181 WHERE `entry`=3079;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (4644,3926,4006) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4644,0,3, 'I seek further druidic training to have a closer understanding of the Earth Mother''s will.',5,16,0,0,0,0, ''),
(3926,0,3, 'I seek training as a druid.',5,16,0,0,0,0, ''),
(4006,0,1, 'I would like to buy from you.',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7369 AND `text_id`=8805;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7369,8805);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=7369 WHERE `entry`=17109;

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=4486 AND `text_id`=538;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4486,538);

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (4486) AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4486,0,3, 'I am interested in mage training.',5,16,0,0,0,0, ''),
(4486,1,0, 'I wish to unlearn my talents.',16,16,0,0,0,0, '');

-- Gossip conditions
SET @ID := 4486;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@ID,538,0,15,8,0,0,0,'','Show gossip text if player is mage');
-- Gossip option conditions
SET @ID := 4486;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@ID,0,0,15,8,0,0,0,'','Show gossip option if player is mage'),
(15,@ID,1,0,15,8,0,0,0,'','Show gossip option if player is mage');
