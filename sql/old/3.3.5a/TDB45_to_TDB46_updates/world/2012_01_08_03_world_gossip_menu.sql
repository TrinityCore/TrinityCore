-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9301,9512,9615) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9301,0,0, 'Come on, Budd. Time to play with the ice trolls!',1,1,0,0,0,0, ''),
(9512,0,0, 'Unchain and control Flamebringer.',1,1,0,0,0,0, ''),
(9615,0,0, 'Shake Drakuru''s outstretched hand.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9633 AND `text_id`=13034;
DELETE FROM `gossip_menu` WHERE `entry`=9490 AND `text_id`=12773;
DELETE FROM `gossip_menu` WHERE `entry`=9622 AND `text_id`=13011;
DELETE FROM `gossip_menu` WHERE `entry`=9416 AND `text_id`=12659;
DELETE FROM `gossip_menu` WHERE `entry`=9301 AND `text_id`=12617;
DELETE FROM `gossip_menu` WHERE `entry`=9615 AND `text_id` IN (12998,12999,13001);
DELETE FROM `gossip_menu` WHERE `entry`=9604 AND `text_id`=12966;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9633,13034),
(9490,12773),
(9622,13011),
(9416,12659),
(9301,12617),
(9615,12998),
(9615,12999),
(9615,13001),
(9604,12966);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9633 WHERE `entry`=26868;
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=29740;
UPDATE `creature_template` SET `gossip_menu_id`=9490 WHERE `entry`=27262;
UPDATE `creature_template` SET `gossip_menu_id`=9622 WHERE `entry`=26519;
UPDATE `creature_template` SET `gossip_menu_id`=9416 WHERE `entry`=26604;
UPDATE `creature_template` SET `gossip_menu_id`=9301 WHERE `entry`=26422;
UPDATE `creature_template` SET `gossip_menu_id`=9615 WHERE `entry`=26423;
UPDATE `creature_template` SET `gossip_menu_id`=9604 WHERE `entry`=26424;

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9615 AND `SourceEntry` IN (12998,12999,13001);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9632 AND `SourceEntry`=13033;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9633 AND `SourceEntry`=13034;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9301,9512,9615) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9615,12998,0,1,50001,0,0,0,'','Drakuru has different gossip if player has aura 50001'),
(14,9615,12999,0,11,50001,0,0,0,'','Drakuru has gossip only if player has not aura 50001'),
(14,9615,13001,0,8,11989,0,0,0,'','Drakuru has different gossip if player has quest 11989 rewarded'),
(14,9632,13033,0,14,12178,0,0,0,'','Hidetrader Jun''ik has gossip only if player has not taken quest 12178'),
(14,9633,13034,0,14,12436,0,0,0,'','Provisioner Lorkran has gossip only if player has not taken quest 12436'),
(15,9301,0,0,9,11984,0,0,0,'','Budd - Show gossip option if player has taken quest 11984'),
(15,9512,0,0,9,12259,0,0,0,'','Flamebringer - Show gossip option if player has taken quest 12259'),
(15,9512,0,1,9,12255,0,0,0,'','Flamebringer - Show gossip option if player has taken quest 12255'),
(15,9615,0,0,1,50001,0,0,0,'','Drakuru - Show gossip option if player has aura 50001');
