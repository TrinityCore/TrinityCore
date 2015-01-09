-- Add some missing gossip to Nagrand From UDB
UPDATE `creature_template` SET `gossip_menu_id`=7675 WHERE `entry`=18261;
UPDATE `creature_template` SET `gossip_menu_id`=7723 WHERE `entry`=18333;
UPDATE `creature_template` SET `gossip_menu_id`=7719 WHERE `entry`=18417;
UPDATE `creature_template` SET `gossip_menu_id`=7724 WHERE `entry`=18581;
UPDATE `creature_template` SET `gossip_menu_id`=7625 WHERE `entry`=18265;
UPDATE `creature_template` SET `gossip_menu_id`=7626 WHERE `entry`=18276;
UPDATE `creature_template` SET `gossip_menu_id`=7631 WHERE `entry`=18335;
UPDATE `creature_template` SET `gossip_menu_id`=7699 WHERE `entry`=18471;
UPDATE `creature_template` SET `gossip_menu_id`=7563 WHERE `entry`=18074;
UPDATE `creature_template` SET `gossip_menu_id`=7592 WHERE `entry`=18200;
UPDATE `creature_template` SET `gossip_menu_id`=7579 WHERE `entry`=18180;
UPDATE `creature_template` SET `gossip_menu_id`=7607 WHERE `entry`=18218;
UPDATE `creature_template` SET `gossip_menu_id`=7704 WHERE `entry`=18482;
UPDATE `creature_template` SET `gossip_menu_id`=8493, `npcflag`=`npcflag`|1 WHERE `entry`=22113;

DELETE FROM `gossip_menu` WHERE `entry`=7563 AND `text_id`=9181;
DELETE FROM `gossip_menu` WHERE `entry`=7578 AND `text_id`=9220;
DELETE FROM `gossip_menu` WHERE `entry`=7579 AND `text_id` IN (9219,9221,9256,9257);
DELETE FROM `gossip_menu` WHERE `entry`=7592 AND `text_id` IN (9240,9283,9284);
DELETE FROM `gossip_menu` WHERE `entry`=7607 AND `text_id` IN (9258,9286);
DELETE FROM `gossip_menu` WHERE `entry`=7625 AND `text_id`=9287;
DELETE FROM `gossip_menu` WHERE `entry`=7626 AND `text_id`=9288;
DELETE FROM `gossip_menu` WHERE `entry`=7631 AND `text_id`=9312;
DELETE FROM `gossip_menu` WHERE `entry`=7675 AND `text_id` IN (9361,9369);
DELETE FROM `gossip_menu` WHERE `entry`=7676 AND `text_id`=9368;
DELETE FROM `gossip_menu` WHERE `entry`=7677 AND `text_id`=9367;
DELETE FROM `gossip_menu` WHERE `entry`=7678 AND `text_id`=9366;
DELETE FROM `gossip_menu` WHERE `entry`=7679 AND `text_id`=9365;
DELETE FROM `gossip_menu` WHERE `entry`=7680 AND `text_id`=9364;
DELETE FROM `gossip_menu` WHERE `entry`=7681 AND `text_id`=9363;
DELETE FROM `gossip_menu` WHERE `entry`=7682 AND `text_id`=9362;
DELETE FROM `gossip_menu` WHERE `entry`=7699 AND `text_id`=9394;
DELETE FROM `gossip_menu` WHERE `entry`=7704 AND `text_id`=9405;
DELETE FROM `gossip_menu` WHERE `entry`=7705 AND `text_id`=9406;
DELETE FROM `gossip_menu` WHERE `entry`=7714 AND `text_id`=9424;
DELETE FROM `gossip_menu` WHERE `entry`=7715 AND `text_id`=9423;
DELETE FROM `gossip_menu` WHERE `entry`=7716 AND `text_id`=9422;
DELETE FROM `gossip_menu` WHERE `entry`=7717 AND `text_id`=9421;
DELETE FROM `gossip_menu` WHERE `entry`=7718 AND `text_id`=9420;
DELETE FROM `gossip_menu` WHERE `entry`=7719 AND `text_id` IN (9419,9427);
DELETE FROM `gossip_menu` WHERE `entry`=7723 AND `text_id`=9429;
DELETE FROM `gossip_menu` WHERE `entry`=7724 AND `text_id`=9433;
DELETE FROM `gossip_menu` WHERE `entry`=8393 AND `text_id`=10493;
DELETE FROM `gossip_menu` WHERE `entry`=8394 AND `text_id`=10492;
DELETE FROM `gossip_menu` WHERE `entry`=8394 AND `text_id`=10614; -- was incorrect in the db
DELETE FROM `gossip_menu` WHERE `entry`=8395 AND `text_id`=10494;
DELETE FROM `gossip_menu` WHERE `entry`=8395 AND `text_id`=10615; -- was incorrect in the db
DELETE FROM `gossip_menu` WHERE `entry`=8396 AND `text_id`=10495;
DELETE FROM `gossip_menu` WHERE `entry`=8396 AND `text_id`=10616; -- was incorrect in the db
DELETE FROM `gossip_menu` WHERE `entry`=8398 AND `text_id`=10497;
DELETE FROM `gossip_menu` WHERE `entry`=8493 AND `text_id` IN (10606,10655,10854);
DELETE FROM `gossip_menu` WHERE `entry`=8497 AND `text_id`=10616;
DELETE FROM `gossip_menu` WHERE `entry`=8498 AND `text_id`=10615;
DELETE FROM `gossip_menu` WHERE `entry`=8499 AND `text_id`=10614;
DELETE FROM `gossip_menu` WHERE `entry` BETWEEN 21296 AND 21303; -- the old menus assigned to Lantresor which were not sniffed
DELETE FROM `gossip_menu` WHERE `entry` BETWEEN 21304 AND 21309; -- the old menus assigned to Altruis which were not sniffed
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7563,9181),
(7578,9220),
(7579,9219),(7579,9221),(7579,9256),(7579,9257),
(7592,9240),(7592,9283),(7592,9284),
(7625,9287),
(7626,9288),
(7631,9312),
(7699,9394),
(7607,9258),(7607,9286),
(7675,9361),(7675,9369),
(7676,9368),
(7677,9367),
(7678,9366),
(7679,9365),
(7680,9364),
(7681,9363),
(7682,9362),
(7704,9405),
(7705,9406),
(7714,9424),
(7715,9423),
(7716,9422),
(7717,9421),
(7718,9420),
(7719,9419),(7719,9427),
(7723,9429),
(7724,9433),
(8394,10492),
(8393,10493),
(8395,10494),
(8396,10495),
(8398,10497),
(8493,10606),(8493,10655),(8493,10854),
(8497,10616),
(8498,10615),
(8499,10614);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7579,7704,7715,7716,7717,7718,7719,8393,8394,8395,8396,8398,8497,8498,8499) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7719,7724) AND `id`=1;
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 7675 AND 7682 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=8499 WHERE `menu_id`=8397; -- was incorrect
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 21296 AND 21303; -- the old options assigned to Lantresor which were not sniffed
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 21304 AND 21309; -- the old options assigned to Altruis which was not sniffed
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(7579,0,0,'Hemet Nesingwary, what are you doing here in the Outland?',1,1,7578,0,0,0,''),
(7704,0,0,'Empoor, you''re going to tell me what I want to know, or else!',1,1,0,0,0,0,''),
(7715,0,0,'Forge camps?',1,1,7714,0,0,0,''),
(7716,0,0,'How do you see them now?',1,1,7715,0,0,0,''),
(7717,0,0,'And now?',1,1,7716,0,0,0,''),
(7718,0,0,'Legion?',1,1,7717,0,0,0,''),
(7719,0,0,'I see twisted steel and smell sundered earth.',1,1,7718,0,0,0,''),
(7719,1,0,'Tell me about the demon hunter training grounds at the Ruins of Karabor.',1,1,8394,0,0,0,''),
(7724,1,1,'I have marks to redeem!',3,128,0,0,0,0,''),
(7675,0,0,'I have killed many of your ogres, Lantresor. I have no fear.',1,1,7682,0,0,0,''),
(7682,0,0,'Should I know? You look like an orc to me.',1,1,7681,0,0,0,''),
(7681,0,0,'And the other half?',1,1,7680,0,0,0,''),
(7680,0,0,'I have heard of your kind, but I never thought to see the day when I would meet a half-breed.',1,1,7679,0,0,0,''),
(7679,0,0,'My apologies. I did not mean to offend. I am here on behalf of my people.',1,1,7678,0,0,0,''),
(7678,0,0,'My people ask that you pull back your Boulderfist ogres and cease all attacks on our territories. In return, we will also pull back our forces.',1,1,7677,0,0,0,''),
(7677,0,0,'We will fight you until the end, then, Lantresor. We will not stand idly by as you pillage our towns and kill our people.',1,1,7676,0,0,0,''),
(7676,0,0,'What do I need to do?',1,1,0,0,0,0,''),
(8394,0,0,'I''m listening.',1,1,8393,0,0,0,''),
(8393,0,0,'Go on, please.',1,1,8395,0,0,0,''),
(8395,0,0,'Interesting.',1,1,8396,0,0,0,''),
(8396,0,0,'That''s quite a story.',1,1,8398,0,0,0,''),
(8398,0,0,'There was something else I wanted to ask you, Altruis.',1,1,7719,0,0,0,''),
(8499,0,0,'But you are dragons! How could orcs do this to you?',1,1,8498,0,0,0,''),
(8498,0,0,'Your mate?',1,1,8497,0,0,0,''),
(8497,0,0,'I have battled many beasts, dragon. I will help you.',1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7579 AND `SourceEntry` IN (9221,9256,9257);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7592 AND `SourceEntry` IN (9283,9284);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7607 AND `SourceEntry`=9286;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7675 AND `SourceEntry`=9369;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7719 AND `SourceEntry`=9427;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8493 AND `SourceEntry` IN (10655,10854);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7675 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (7704,7719) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (7719) AND `SourceEntry`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21304; -- condition for Altruis' gossip that wasn't sniffed
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21295; -- condition for Lantresor's gossip that wasn't sniffed
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7579,9221,0,0,8,208,0,0,0,0,'','Show different gossip if player has rewarded quest 208'),
(14,7579,9256,0,0,8,9851,0,0,0,0,'','Show different gossip if player has rewarded quest 9851'),
(14,7579,9257,0,0,8,9852,0,0,0,0,'','Show different gossip if player has rewarded quest 9852'),
(14,7592,9283,0,0,8,9854,0,0,0,0,'','Show different gossip if player has rewarded quest 9854'),
(14,7592,9284,0,0,8,9856,0,0,0,0,'','Show different gossip if player has rewarded quest 9856'),
(14,7607,9286,0,0,8,9859,0,0,0,0,'','Show different gossip if player has rewarded quest 9859'),
(14,7675,9369,0,0,8,10107,0,0,0,0,'','Show different gossip if player has rewarded quest 10107'),
(14,7675,9369,0,1,8,10108,0,0,0,0,'','Show different gossip if player has rewarded quest 10108'),
(14,7719,9427,0,0,8,9991,0,0,0,0,'','Show different gossip if player has rewarded quest 9991'),
(14,8493,10655,0,0,8,10870,0,0,0,0,'','Show different gossip if player has rewarded quest 10870'),
(14,8493,10854,0,0,8,11012,0,0,0,0,'','Show different gossip if player has rewarded quest 11012'),
(15,7675,0,0,0,9,10107,0,0,0,0,'','Show gossip option if player has quest 10107 but not complete'),
(15,7675,0,0,1,9,10108,0,0,0,0,'','Show gossip option if player has quest 10108 but not complete'),
(15,7704,0,0,0,9,9978,0,0,0,0,'','Show gossip option if player has quest 9978 but not complete'),
(15,7719,0,0,0,8,9991,0,0,1,0,'','Show gossip option if player has not rewarded quest 9991'),
(15,7719,1,0,0,9,10646,0,0,0,0,'','Show gossip option if player has quest 10646 but not complete');

UPDATE `smart_scripts` SET `event_param1`=7715 WHERE `entryorguid`=18417 AND `id` IN (0,1); -- correct Altruis' script
UPDATE `smart_scripts` SET `event_param1`=8396 WHERE `entryorguid`=18417 AND `id`=2;

UPDATE `smart_scripts` SET `event_param1`=8497 WHERE `entryorguid`=21657 AND `id`=0; -- correct Neltharaku's script

UPDATE `smart_scripts` SET `link`=3, `event_param1`=7676 WHERE `entryorguid`=18261 AND `id` IN (1,2); -- correct Lantresor's script
DELETE FROM `smart_scripts` WHERE `entryorguid`=18261 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18261,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lantresor - On gossip select - Close gossip');
