-- No longer used as of patch 3.3.0
DELETE FROM `areatrigger_teleport` WHERE `id`=4156;

UPDATE `game_graveyard_zone` SET `faction`=469 WHERE `id`=1308; -- Alliance Only

DELETE FROM `game_graveyard_zone` WHERE `id`=1309;
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES
(1309, 3456, 67); -- Dragonblight, Forsaken East GY - Horde Only

DELETE FROM `gameobject` WHERE `guid` IN (5216, 5222);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(5216, 202277, 533, 3, 1, 3495.97, -5357.84, 144.9645, 0.5410506, 0, 0, 0, 1, 7200, 255, 1), -- Orb of Naxxramas
(5222, 202278, 533, 3, 1, 2997.675, -3437.799, 304.1996, 1.151916, 0, 0, 0, 1, 7200, 255, 1); -- Orb of Naxxramas

-- Teleportation positions for Orbs from sniff - TODO: add db coords for spell 72613
DELETE FROM `spell_target_position` WHERE `id` IN (28444, 72617);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(28444, 533, 3005.74, -3434.27, 304.196, 0), -- Portal Effect: Deathknight Wing
(72617, 533, 3498.22, -5349.36, 144.969, 1.32679); -- Naxxramas Teleport - Sapphiron Entry
