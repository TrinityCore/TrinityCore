UPDATE `creature_template` SET `npcflag`=`npcflag`|0x0001000000  WHERE `entry`=52809;

UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=12759;

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (52809,52812);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(52809, 52812, 1, 'Toy Cart on Blax Bottlerocket', 5, 0),
(52812, 52810, 1, 'Toy Cart Bunny on Toy Cart', 5, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (52809,52812);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(52809, 46598, 0, 0),
(52812, 46598, 0, 0);

DELETE FROM `npc_vendor` WHERE `entry`=52809;
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52809, 104323, 1, 0, 0, 1, 0, 0, 20338),
(52809, 104324, 2, 0, 0, 1, 0, 0, 20338),
(52809, 95621, 3, 0, 0, 1, 0, 0, 20338),
(52809, 95481, 4, 0, 0, 1, 0, 0, 20338),
(52809, 95482, 5, 0, 0, 1, 0, 0, 20338),
(52809, 46725, 6, 0, 0, 1, 0, 0, 20338),
(52809, 48601, 7, 0, 0, 1, 0, 0, 20338),
(52809, 54436, 8, 0, 0, 1, 0, 0, 20338),
(52809, 54343, 9, 0, 0, 1, 0, 0, 20338),
(52809, 44481, 10, 0, 0, 1, 0, 0, 20338),
(52809, 34498, 11, 0, 0, 1, 0, 0, 20338),
(52809, 54437, 12, 0, 0, 1, 0, 0, 20338),
(52809, 54438, 13, 0, 0, 1, 0, 0, 20338),
(52809, 44482, 14, 0, 0, 1, 0, 0, 20338),
(52809, 44601, 15, 0, 0, 1, 0, 0, 20338),
(52809, 44599, 16, 0, 0, 1, 0, 0, 20338),
(52809, 45057, 17, 0, 0, 1, 0, 0, 20338),
(52809, 44606, 18, 0, 0, 1, 0, 0, 20338);
