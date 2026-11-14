-- Trader's Gilded Brutosaur (mount 2265, spell 465235) still stores creature 305 (White Stallion)
-- in its mount effect. Its model (15227) is the ceremonial brutosaur skeleton with a new skin,
-- so it uses that howdah vehicle (6372). 9002265 is never spawned.
-- Seat 0 is the driver bone. Positive attachment Y is the mount's left.
-- Killia (auctioneer) rides the left seat. Melanie Morten (mailbox) rides the right.

DELETE FROM `creature_template_model` WHERE `CreatureID` = 9002265;
DELETE FROM `vehicle_template_accessory` WHERE `entry` = 9002265;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 9002265;
DELETE FROM `creature_template` WHERE `entry` = 9002265;
DELETE FROM `mount_vehicle` WHERE `MountId` = 2265;

INSERT INTO `creature_template` (`entry`, `name`, `subname`, `faction`, `npcflag`, `unit_class`, `VehicleId`, `VerifiedBuild`) VALUES
(9002265, 'Trader''s Gilded Brutosaur', 'Mount Vehicle', 35, 0, 1, 6372, 69933);

INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(9002265, 0, 122769, 1, 1, 69933);

INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(9002265, 46598, 1, 0);

INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`, `RideSpellID`) VALUES
(9002265, 231086, 1, 1, 'Trader''s Gilded Brutosaur - Melanie Morten', 6, 30000, NULL),
(9002265, 231085, 2, 1, 'Trader''s Gilded Brutosaur - Killia', 6, 30000, NULL);

INSERT INTO `mount_vehicle` (`MountId`, `VehicleCreatureId`) VALUES
(2265, 9002265);
