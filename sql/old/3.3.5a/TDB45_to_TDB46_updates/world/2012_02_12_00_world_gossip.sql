-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9709 AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9731 AND `id` IN (0,1,2,3,4,5);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9714,9717,9732,11091) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9709,0,0, 'I''ve lost Nass...',1,1,0,0,0,0, ''),
(9709,1,0, 'I''ve lost my ensorcelled choker!',1,1,9797,0,0,0, ''),
(9714,0,0, 'Stefan told me you would demonstrate the purpose of this item',1,1,0,0,0,0, ''),
(9717,0,1, 'What are you hiding under that fold of flesh?',3,128,0,0,0,0, ''),
(9731,0,0, 'I am ready to accompany you, Drakuru.',1,1,0,0,0,0, ''),
(9731,1,0, 'Gorebag has shown me the Drakkari Empire. I am eager to help you conquer it!',1,1,10403,0,0,0, ''),
(9731,2,0, 'I have whipped the Blight Geists into shape!',1,1,10404,0,0,0, ''),
(9731,3,0, 'I have defeated Darmuk! How else may I serve you?',1,1,10405,0,0,0, ''),
(9731,4,0, 'The Drakkari Chieftains have been captured! What more would you have me do?',1,1,10406,0,0,0, ''),
(9731,5,0, 'I have witnessed your magnificent operation, Drakuru. When do we put your plan into effect?',1,1,10407,0,0,0, ''),
(9732,0,0, 'Uhh, can you send me on the tour of Zul''Drak?',1,1,0,0,0,0, ''),
(11091,0,0, 'I''m ready.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9639 AND `text_id`=13046;
DELETE FROM `gossip_menu` WHERE `entry`=9655 AND `text_id`=13078;
DELETE FROM `gossip_menu` WHERE `entry`=9657 AND `text_id`=13080;
DELETE FROM `gossip_menu` WHERE `entry`=9675 AND `text_id`=13121;
DELETE FROM `gossip_menu` WHERE `entry`=9709 AND `text_id`=13271;
DELETE FROM `gossip_menu` WHERE `entry`=9714 AND `text_id`=13290;
DELETE FROM `gossip_menu` WHERE `entry`=9717 AND `text_id`=13300;
DELETE FROM `gossip_menu` WHERE `entry`=9731 AND `text_id`=13324;
DELETE FROM `gossip_menu` WHERE `entry`=9731 AND `text_id`=13325;
DELETE FROM `gossip_menu` WHERE `entry`=9731 AND `text_id`=13348;
DELETE FROM `gossip_menu` WHERE `entry`=9731 AND `text_id`=13422;
DELETE FROM `gossip_menu` WHERE `entry`=9732 AND `text_id`=13326;
DELETE FROM `gossip_menu` WHERE `entry`=9752 AND `text_id`=13390;
DELETE FROM `gossip_menu` WHERE `entry`=9752 AND `text_id`=13391;
DELETE FROM `gossip_menu` WHERE `entry`=9797 AND `text_id`=13501;
DELETE FROM `gossip_menu` WHERE `entry`=9848 AND `text_id`=13619;
DELETE FROM `gossip_menu` WHERE `entry`=9852 AND `text_id`=13639;
DELETE FROM `gossip_menu` WHERE `entry`=9861 AND `text_id`=13658;
DELETE FROM `gossip_menu` WHERE `entry`=10403 AND `text_id`=14441;
DELETE FROM `gossip_menu` WHERE `entry`=10404 AND `text_id`=14442;
DELETE FROM `gossip_menu` WHERE `entry`=10405 AND `text_id`=14443;
DELETE FROM `gossip_menu` WHERE `entry`=10406 AND `text_id`=14444;
DELETE FROM `gossip_menu` WHERE `entry`=10407 AND `text_id`=14445;
DELETE FROM `gossip_menu` WHERE `entry`=11091 AND `text_id`=15432;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9639,13046),
(9655,13078),
(9657,13080),
(9675,13121),
(9709,13271),
(9714,13290),
(9717,13300),
(9731,13324),(9731,13325),(9731,13348),(9731,13422),
(9732,13326),
(9752,13390),(9752,13391),
(9797,13501),
(9848,13619),
(9852,13639),
(9861,13658),
(10403,14441),
(10404,14442),
(10405,14443),
(10406,14444),
(10407,14445),
(11091,15432);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9639 WHERE `entry`=28059; -- Commander Falstaav
UPDATE `creature_template` SET `gossip_menu_id`=9655 WHERE `entry`=28141; -- Crusader Lamoof
UPDATE `creature_template` SET `gossip_menu_id`=9657 WHERE `entry`=28143; -- Crusader Josephine
UPDATE `creature_template` SET `gossip_menu_id`=9675 WHERE `entry`=28309; -- Sub-Lieutenant Jax
UPDATE `creature_template` SET `gossip_menu_id`=9715 WHERE `entry`=28561; -- Spirit of Rhunok
UPDATE `creature_template` SET `gossip_menu_id`=9717 WHERE `entry`=28589; -- Gristlegut
UPDATE `creature_template` SET `gossip_menu_id`=9731 WHERE `entry`=28503; -- Overlord Drakuru
UPDATE `creature_template` SET `gossip_menu_id`=9732 WHERE `entry`=28666; -- Gorebag
UPDATE `creature_template` SET `gossip_menu_id`=9752 WHERE `entry`=28888; -- Captured Drakkari Chieftain
UPDATE `creature_template` SET `gossip_menu_id`=9848 WHERE `entry`=29688; -- Engineer Reed
UPDATE `creature_template` SET `gossip_menu_id`=9852 WHERE `entry`=29647; -- Gymer
UPDATE `creature_template` SET `gossip_menu_id`=9861 WHERE `entry`=29689; -- Crusader MacKellar
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=28790; -- Fala Softhoof

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9709 AND `SourceEntry`=13271;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9714 AND `SourceEntry`=13290;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9731 AND `SourceEntry` IN (13324,13325,13348,13422);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9752 AND `SourceEntry`=13391;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9709,9714,9732) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9709 AND `SourceEntry`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9731 AND `SourceEntry` IN (0,1,2,3,4,5);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9709,13271,0,0,9,12630,0,0,0,0,'','Stefan Vadu - Show different gossip if player has taken quest 12630'),
(14,9709,13271,0,0,1,61438,0,0,1,0,'','Stefan Vadu - Show different gossip if player is not affected by aura 61438'),
(14,9714,13290,0,0,9,12637,0,0,0,0,'','Bloodrose Datura - Show different gossip if player has taken quest 12637'),
(14,9714,13290,0,1,9,12638,0,0,0,0,'','Bloodrose Datura - Show different gossip if player has taken quest 12638'),
(14,9731,13324,0,0,8,12238,0,0,0,0,'','Overlord Drakuru - Show different gossip if player has rewarded quest 12238'),
(14,9731,13325,0,0,8,12661,0,0,0,0,'','Overlord Drakuru - Show different gossip if player has rewarded quest 12663'),
(14,9731,13348,0,0,8,12238,0,0,1,0,'','Overlord Drakuru - Show different gossip if player has not rewarded quest 12238'),
(14,9731,13422,0,0,9,12713,0,0,0,0,'','Overlord Drakuru - Show different gossip if player has taken quest 12713'),
(14,9752,13391,0,0,1,51966,0,0,0,0,'','Captured Drakkari Chieftain - Show different gossip if player is affected by aura 51966'),
(15,9709,0,0,0,9,12630,0,0,0,0,'','Show gossip option only if player has taken quest 12630'),
(15,9709,0,0,0,1,61438,0,0,1,0,'','Show gossip option only if player is not affected by aura 61438'),
(15,9709,1,0,0,9,12648,0,0,0,0,'','Show gossip option only if player has taken quest 12648'),
(15,9709,1,0,0,2,38699,1,0,1,0,'','Show gossip option only if player has no item 38699'),
(15,9709,1,0,1,9,12649,0,0,0,0,'','Show gossip option only if player has taken quest 12649'),
(15,9709,1,0,1,2,38699,1,0,1,0,'','Show gossip option only if player no item 38699'),
(15,9709,1,0,2,9,12661,0,0,0,0,'','Show gossip option only if player has taken quest 12661'),
(15,9709,1,0,2,2,38699,1,0,1,0,'','Show gossip option only if player no item 38699'),
(15,9709,1,0,3,9,12669,0,0,0,0,'','Show gossip option only if player has taken quest 12669'),
(15,9709,1,0,3,2,38699,1,0,1,0,'','Show gossip option only if player no item 38699'),
(15,9709,1,0,4,9,12676,0,0,0,0,'','Show gossip option only if player has taken quest 12676'),
(15,9709,1,0,4,2,38699,1,0,1,0,'','Show gossip option only if player no item 38699'),
(15,9709,1,0,5,9,12677,0,0,0,0,'','Show gossip option only if player has taken quest 12677'),
(15,9709,1,0,5,2,38699,1,0,1,0,'','Show gossip option only if player no item 38699'),
(15,9709,1,0,6,9,12713,0,0,0,0,'','Show gossip option only if player has taken quest 12713'),
(15,9709,1,0,6,2,38699,1,0,1,0,'','Show gossip option only if player no item 38699'),
(15,9714,0,0,0,9,12637,0,0,0,0,'','Show gossip option only if player has taken quest 12637'),
(15,9714,0,0,1,9,12638,0,0,0,0,'','Show gossip option only if player has taken quest 12638'),
(15,9714,0,0,0,2,38678,1,0,0,0,'','Show gossip option only if player has item 38678'),
(15,9731,0,0,0,9,12713,0,0,0,0,'','Show gossip option only if player has taken quest 12713'),
(15,9731,1,0,0,8,12663,0,0,0,0,'','Show gossip option only if player has rewarded quest 12663'),
(15,9731,1,0,0,8,12661,0,0,1,0,'','Show gossip option only if player has not rewarded quest 12661'),
(15,9731,1,0,1,8,12664,0,0,0,0,'','Show gossip option only if player has rewarded quest 12664'),
(15,9731,1,0,1,8,12661,0,0,1,0,'','Show gossip option only if player has not rewarded quest 12661'),
(15,9731,2,0,0,8,12673,0,0,0,0,'','Show gossip option only if player has rewarded quest 12673'),
(15,9731,2,0,0,8,12669,0,0,1,0,'','Show gossip option only if player has not rewarded quest 12669'),
(15,9731,3,0,0,8,12686,0,0,0,0,'','Show gossip option only if player has rewarded quest 12686'),
(15,9731,3,0,0,8,12677,0,0,1,0,'','Show gossip option only if player has not rewarded quest 12677'),
(15,9731,4,0,0,8,12690,0,0,0,0,'','Show gossip option only if player has rewarded quest 12690'),
(15,9731,4,0,0,8,12676,0,0,1,0,'','Show gossip option only if player has not rewarded quest 12676'),
(15,9731,5,0,0,8,12710,0,0,0,0,'','Show gossip option only if player has rewarded quest 12710'),
(15,9731,5,0,0,8,12676,0,0,1,0,'','Show gossip option only if player has not rewarded quest 12676'),
(15,9732,0,0,0,9,12663,0,0,0,0,'','Show gossip option only if player has taken quest 12663'),
(15,9732,0,0,1,9,12664,0,0,0,0,'','Show gossip option only if player has taken quest 12664');
