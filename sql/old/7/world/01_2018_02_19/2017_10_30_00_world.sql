UPDATE `creature_template` SET `VehicleId`=2273 WHERE `entry`=62809;

DELETE FROM `creature_template_addon` WHERE `entry` IN (62821,62822);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(62821, 0, 0, 0, 0, 0, 0, 0, 0, '123236'),
(62822, 0, 0, 0, 0, 0, 0, 0, 0, '123240');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=62809;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(62809, 122729, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=62809;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(62809, 62821, 0, 1, 'Grand Expedition Yak - Transmogrifier',   6, 30000),
(62809, 62822, 1, 1, 'Grand Expedition Yak - Traveling Trader', 6, 30000);
