-- I sense you've cleared the path to my brethren.  My connection to them and to the temple is still strong.  Do you wish to delve deeper inside?
UPDATE `creature_template` SET `gossip_menu_id`=8750 WHERE `entry`=23411;
DELETE FROM `gossip_menu` WHERE `entry`=8750 AND `text_id`=11081;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (8750, 11081);
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=8750 AND `id`=1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(8750, 1, 0, 'Take me to the other Deathsworn, Olum.', 0, 0, '');
