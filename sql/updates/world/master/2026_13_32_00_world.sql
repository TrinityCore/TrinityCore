-- Mighty Caravan Brutosaur (mount 1039, spell 264058) still stores creature 305 (White Stallion)
-- in its mount effect. That creature has no vehicle, so Collector Unta and Merchant Maku are never installed.
-- Vehicle 6372 belongs to the ceremonial brutosaur (146032), the only vehicle on this mount's model.
-- 9001039 is never spawned. It only supplies that VehicleId to the player's mount kit.
-- Seat 0 is the ceremonial driver bone. The howdah passengers are seats 1 and 2.

DROP TABLE IF EXISTS `mount_vehicle`;
CREATE TABLE `mount_vehicle` (
  `MountId` int unsigned NOT NULL COMMENT 'Mount.db2 ID',
  `VehicleCreatureId` int unsigned NOT NULL COMMENT 'creature_template.entry whose VehicleId the mount should use',
  PRIMARY KEY (`MountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Mounts whose spell EffectMiscValue creature is not the vehicle';

DELETE FROM `creature_template_model` WHERE `CreatureID` = 9001039;
DELETE FROM `vehicle_template_accessory` WHERE `entry` = 9001039;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 9001039;
DELETE FROM `creature_template` WHERE `entry` = 9001039;

INSERT INTO `creature_template` (`entry`, `name`, `subname`, `faction`, `npcflag`, `unit_class`, `VehicleId`, `VerifiedBuild`)
SELECT 9001039, 'Mighty Caravan Brutosaur', 'Mount Vehicle', 35, 0, 1, `VehicleId`, 69933
FROM `creature_template` WHERE `entry` = 146032;

INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(9001039, 0, 83632, 1, 1, 69933);

INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(9001039, 46598, 1, 0);

INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`, `RideSpellID`) VALUES
(9001039, 142666, 1, 1, 'Mighty Caravan Brutosaur - Collector Unta', 6, 30000, NULL),
(9001039, 142668, 2, 1, 'Mighty Caravan Brutosaur - Merchant Maku', 6, 30000, NULL);

INSERT INTO `mount_vehicle` (`MountId`, `VehicleCreatureId`) VALUES
(1039, 9001039);
