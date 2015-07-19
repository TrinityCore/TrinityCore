UPDATE `creature_template` SET `faction`=35,`unit_flags`=0 WHERE `entry` IN 
(33562,33559,33558,33564,33561,33382,33383,33384,33306,33285,33739,33738,33747,33743,33740,33746,33748,33744,33745,33749);

-- Darnassus Champion
UPDATE `creature_template` SET `gossip_menu_id`=10453 WHERE `entry`=33738;
-- Exodar Champion
UPDATE `creature_template` SET `gossip_menu_id`=10454 WHERE `entry`=33739;
-- Gnomeregan Champion
UPDATE `creature_template` SET `gossip_menu_id`=10455 WHERE `entry`=33740;
-- Ironforge Champion
UPDATE `creature_template` SET `gossip_menu_id`=10456 WHERE `entry`=33743;
-- Orgrimmar Champion
UPDATE `creature_template` SET `gossip_menu_id`=10457 WHERE `entry`=33744;
-- Sen'jin Champion
UPDATE `creature_template` SET `gossip_menu_id`=10458 WHERE `entry`=33745;
-- Silvermoon Champion
UPDATE `creature_template` SET `gossip_menu_id`=10459 WHERE `entry`=33746;
-- Stormwind Champion
UPDATE `creature_template` SET `gossip_menu_id`=10460 WHERE `entry`=33747;
-- Thunder Bluff Champion
UPDATE `creature_template` SET `gossip_menu_id`=10461 WHERE `entry`=33748;
-- Undercity Champion
UPDATE `creature_template` SET `gossip_menu_id`=10462 WHERE `entry`=33749;
-- Darnassus Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10464 WHERE `entry`=33559;
-- Exodar Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10465 WHERE `entry`=33562;
-- Gnomeregan Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10466 WHERE `entry`=33558;
-- Ironforge Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10467 WHERE `entry`=33564;
-- Orgrimmar Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10468 WHERE `entry`=33306;
-- Sen'jin Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10469 WHERE `entry`=33285;
-- Silvermoon Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10470 WHERE `entry`=33382;
-- Stormwind Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10471 WHERE `entry`=33561;
-- Thunder Bluff Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10472 WHERE `entry`=33383;
-- Undercity Valiant
UPDATE `creature_template` SET `gossip_menu_id`=10473 WHERE `entry`=33384;

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10453,10454,10455,10456,10457,10458,10459,10460,10461,10462,10464,10465,10466,10467,10468,10469,10470,10471,10472,10473);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES 
(10469, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10468, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10470, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10472, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10473, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10466, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10464, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10471, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10465, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10467, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10453, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10454, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10455, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10456, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10457, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10458, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10459, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10460, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10461, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0),
(10462, 0, 0, 'I am ready to fight!', 33430, 1, 1, 0, 0, 0, 0, '', 0);
