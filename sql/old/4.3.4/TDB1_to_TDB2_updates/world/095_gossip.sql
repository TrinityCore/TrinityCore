UPDATE `gossip_menu_option` SET `action_menu_id`=2321, `action_poi_id`=50 WHERE `menu_id`=2121 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=2141, `action_poi_id`=51 WHERE `menu_id`=2121 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=3082, `action_poi_id`=52 WHERE `menu_id`=2121 AND `id`=2;
UPDATE `gossip_menu_option` SET `action_menu_id`=2142, `action_poi_id`=53 WHERE `menu_id`=2121 AND `id`=3;
UPDATE `gossip_menu_option` SET `action_menu_id`=2143, `action_poi_id`=54 WHERE `menu_id`=2121 AND `id`=4;
UPDATE `gossip_menu_option` SET `action_menu_id`=2145, `action_poi_id`=55 WHERE `menu_id`=2121 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_menu_id`=2146, `action_poi_id`=56 WHERE `menu_id`=2121 AND `id`=6;
UPDATE `gossip_menu_option` SET `action_menu_id`=4927, `action_poi_id`=57 WHERE `menu_id`=2121 AND `id`=7;
UPDATE `gossip_menu_option` SET `action_menu_id`=8220, `action_poi_id`=59 WHERE `menu_id`=2121 AND `id`=8;
UPDATE `gossip_menu_option` SET `action_menu_id`=10014, `action_poi_id`=60 WHERE `menu_id`=2121 AND `id`=9;
UPDATE `gossip_menu_option` SET `action_menu_id`=2144 WHERE `menu_id`=2121 AND `id`=10;
UPDATE `gossip_menu_option` SET `action_menu_id`=2168 WHERE `menu_id`=2121 AND `id`=11;
UPDATE `gossip_menu_option` SET `action_menu_id`=12756, `action_poi_id`=455 WHERE `menu_id`=2144 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=2147, `action_poi_id`=61 WHERE `menu_id`=2144 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=2148, `action_poi_id`=62 WHERE `menu_id`=2144 AND `id`=2;
UPDATE `gossip_menu_option` SET `action_menu_id`=2150, `action_poi_id`=62 WHERE `menu_id`=2144 AND `id`=3;
UPDATE `gossip_menu_option` SET `action_menu_id`=2149, `action_poi_id`=62 WHERE `menu_id`=2144 AND `id`=4;
UPDATE `gossip_menu_option` SET `action_menu_id`=2151, `action_poi_id`=63 WHERE `menu_id`=2144 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_menu_id`=2152, `action_poi_id`=64 WHERE `menu_id`=2144 AND `id`=6;
UPDATE `gossip_menu_option` SET `action_menu_id`=2153, `action_poi_id`=61 WHERE `menu_id`=2144 AND `id`=7;
UPDATE `gossip_menu_option` SET `action_menu_id`=8643, `action_poi_id`=65 WHERE `menu_id`=2144 AND `id`=8;
UPDATE `gossip_menu_option` SET `action_menu_id`=2161, `action_poi_id`=66 WHERE `menu_id`=2168 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=12306, `action_poi_id`=456 WHERE `menu_id`=2168 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=2162, `action_poi_id`=67 WHERE `menu_id`=2168 AND `id`=2;
UPDATE `gossip_menu_option` SET `action_menu_id`=2163, `action_poi_id`=68 WHERE `menu_id`=2168 AND `id`=3;
UPDATE `gossip_menu_option` SET `action_menu_id`=2164, `action_poi_id`=69 WHERE `menu_id`=2168 AND `id`=4;
UPDATE `gossip_menu_option` SET `action_menu_id`=2165, `action_poi_id`=401 WHERE `menu_id`=2168 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_menu_id`=2166, `action_poi_id`=70 WHERE `menu_id`=2168 AND `id`=6;
UPDATE `gossip_menu_option` SET `action_menu_id`=2167, `action_poi_id`=71 WHERE `menu_id`=2168 AND `id`=7;
UPDATE `gossip_menu_option` SET `action_menu_id`=2169, `action_poi_id`=70 WHERE `menu_id`=2168 AND `id`=8;
UPDATE `gossip_menu_option` SET `action_menu_id`=10013, `action_poi_id`=72 WHERE `menu_id`=2168 AND `id`=9;
UPDATE `gossip_menu_option` SET `action_menu_id`=12773, `action_poi_id`=74 WHERE `menu_id`=2168 AND `id`=10;
UPDATE `gossip_menu_option` SET `action_menu_id`=2170, `action_poi_id`=73 WHERE `menu_id`=2168 AND `id`=11;
UPDATE `gossip_menu_option` SET `action_menu_id`=2172, `action_poi_id`=74 WHERE `menu_id`=2168 AND `id`=12;
UPDATE `gossip_menu_option` SET `action_menu_id`=2173, `action_poi_id`=73 WHERE `menu_id`=2168 AND `id`=13;
UPDATE `gossip_menu_option` SET `action_menu_id`=2175, `action_poi_id`=75 WHERE `menu_id`=2168 AND `id`=14;


UPDATE `points_of_interest` SET `icon_name`='Deepmountain Mining & Jewelcrafting' WHERE `entry`=74;

DELETE FROM `points_of_interest` WHERE `entry` IN (455, 456);
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES
(455, -5081.342, -780.4653, 7, 99, 0, 'Ironforge Druid Trainer'),
(456, -4627.94, -1311.17, 7, 99, 0, 'Ironforge Archaeology');


-- Old gossip + fix sub-menu
DELETE FROM `gossip_menu_option` WHERE `menu_id`=2121 AND `id`=12;
UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id` IN (2121, 2144, 2168);

DELETE FROM `gossip_menu` WHERE `entry` IN (12773, 12306, 12756);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12773, 17961), -- 5595
(12306, 17299), -- 5595
(12756, 17906); -- 5595
