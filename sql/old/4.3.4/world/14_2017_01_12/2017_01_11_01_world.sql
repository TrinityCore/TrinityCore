--
DELETE FROM `creature_template_addon` WHERE `entry`=42400;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (42400,0,0,0,1,0,'79143');
 
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (42399,42400);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42399, 46598, 0, 0),(42400, 46598, 0, 0);
 
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (42399,42400);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(42400,42399,0,1,'West Plains Drifter - Hobo Cart', 8, 0),
(42399,42403,1,1,'Hobo Cart - Hobo Goods (Boots)', 8, 0),
(42399,42401,2,1,'Hobo Cart - Hobo Goods (Bag)', 8, 0),
(42399,42401,3,1,'Hobo Cart - Hobo Goods (Bag)', 8, 0),
(42399,42402,4,1,'Hobo Cart - Hobo Goods (Poop)', 8, 0);
--