DELETE FROM `creature_sparring_template` WHERE `CreatureID` IN (50471, 50474);
INSERT INTO `creature_sparring_template` (`CreatureID`, `HealthLimitPct`) VALUES
(50471, 85.0),
(50474, 85.0);

UPDATE `creature` SET `terrainSwapMap`= 638 WHERE `id` IN (35229, 36057, 35317);
