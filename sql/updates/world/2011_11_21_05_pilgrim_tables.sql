UPDATE `creature_template` SET `unit_flags`=33555200,`VehicleId`=323 WHERE `entry`=32830; -- Food Holder
UPDATE `creature_template` SET `unit_flags`=33555200,`VehicleId`=325 WHERE `entry`=32840; -- Plate Holder
UPDATE `creature_template` SET `unit_flags`=33554432,`speed_run`=1,`VehicleId`=320 WHERE `entry`=32823; -- Bountiful Table
UPDATE `creature_template` SET `unit_flags`=33554432,`speed_run`=1 WHERE `entry`=32839; -- Sturdy Plate
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32824; -- [PH] Pilgrim's Bounty Table - Turkey
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32827; -- [PH] Pilgrim's Bounty Table - Cranberry Sauce
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32831; -- [PH] Pilgrim's Bounty Table - Stuffing
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32825; -- [PH] Pilgrim's Bounty Table - Yams
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32829; -- [PH] Pilgrim's Bounty Table - Pie

UPDATE `creature_model_info` SET `bounding_radius`=1.8,`combat_reach`=0,`gender`=2 WHERE `modelid`=28293; -- Bountiful Table
UPDATE `creature_model_info` SET `bounding_radius`=1.75,`combat_reach`=0,`gender`=2 WHERE `modelid`=28310; -- Sturdy Plate
UPDATE `creature_model_info` SET `bounding_radius`=0.125,`combat_reach`=0.25,`gender`=2 WHERE `modelid`=17188; -- [PH] Pilgrim's Bounty Table - X

DELETE FROM `creature_template_addon` WHERE `entry` IN (32830,32840,32839,32824,32827,32831,32829,32825);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32830,0,0,1,0, NULL), -- Food Holder
(32840,0,0,1,0, NULL), -- Plate Holder
(32839,0,0,1,0, NULL), -- Sturdy Plate
(32824,0,0,1,0, NULL), -- [PH] Pilgrim's Bounty Table - Turkey
(32827,0,0,1,0, NULL), -- [PH] Pilgrim's Bounty Table - Cranberry Sauce
(32831,0,0,1,0, NULL), -- [PH] Pilgrim's Bounty Table - Stuffing
(32825,0,0,1,0, NULL), -- [PH] Pilgrim's Bounty Table - Yams
(32829,0,0,1,0, NULL); -- [PH] Pilgrim's Bounty Table - Pie

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (32823,32830,32840);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `aura_required`, `aura_forbidden`, `user_type`) VALUES
(32823, 46598, 0, 0, 0, 1, 0, 0, 0), -- Bountiful Table (Ride Vehicle Hardcoded)
(32830, 46598, 0, 0, 0, 1, 0, 0, 0), -- Food Holder (Ride Vehicle Hardcoded)
(32840, 46598, 0, 0, 0, 1, 0, 0, 0); -- Plate Holder (Ride Vehicle Hardcoded)

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (32823,32830,32840);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(32823, 34812, 0, 1, 'Bountiful Table - The Turkey Chair', 8, 0),
(32823, 34823, 1, 1, 'Bountiful Table - The Cranberry Chair', 8, 0),
(32823, 34819, 2, 1, 'Bountiful Table - The Stuffing Chair', 8, 0),
(32823, 34824, 3, 1, 'Bountiful Table - The Sweet Potato Chair', 8, 0),
(32823, 34822, 4, 1, 'Bountiful Table - The Pie Chair', 8, 0),
(32823, 32830, 5, 1, 'Bountiful Table - Food Holder', 8, 0),
(32823, 32840, 6, 1, 'Bountiful Table - Plate Holder', 8, 0),
--
(32830, 32824, 0, 1, 'Food Holder - [PH] Pilgrim''s Bounty Table - Turkey', 8, 0),
(32830, 32827, 1, 1, 'Food Holder - [PH] Pilgrim''s Bounty Table - Cranberry Sauce', 8, 0),
(32830, 32831, 2, 1, 'Food Holder - [PH] Pilgrim''s Bounty Table - Stuffing', 8, 0),
(32830, 32825, 3, 1, 'Food Holder - [PH] Pilgrim''s Bounty Table - Yams', 8, 0),
(32830, 32829, 4, 1, 'Food Holder - [PH] Pilgrim''s Bounty Table - Pie', 8, 0),
--
(32840, 32839, 0, 1, 'Plate Holder - Sturdy Plate', 8, 0),
(32840, 32839, 1, 1, 'Plate Holder - Sturdy Plate', 8, 0),
(32840, 32839, 2, 1, 'Plate Holder - Sturdy Plate', 8, 0),
(32840, 32839, 3, 1, 'Plate Holder - Sturdy Plate', 8, 0),
(32840, 32839, 4, 1, 'Plate Holder - Sturdy Plate', 8, 0);
