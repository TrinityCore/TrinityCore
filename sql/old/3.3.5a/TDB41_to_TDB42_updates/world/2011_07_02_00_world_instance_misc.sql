UPDATE `gameobject_template` SET `flags`=48 WHERE `entry`=202223; -- Scourge Transporter to the Frozen Throne
UPDATE `gameobject_template` SET `flags`=32 WHERE `entry` IN (202242,202243,202244,202245,202235,202246); -- Scourge Transporters

DELETE FROM `gameobject` WHERE `id` IN (202189,202188);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(151,202189,631,15,1,503.62,-2124.66,836.607,3.14159,0,0,0,1,6000,255,1),
(153,202188,631,15,1,503.62,-2124.66,836.607,3.14159,0,0,0,1,6000,255,0);

-- Highlord Tirion Fordring gossip
UPDATE `creature_template` SET `gossip_menu_id`=10993 WHERE `entry`=38995;

DELETE FROM `gossip_menu` WHERE `entry`=10993;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(10993,15290);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10993;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10993,0,0,'We are prepared, Highlord. Let us battle for the fate of Azeroth! For the light of dawn!',1,1,0,0,0,0,'');
