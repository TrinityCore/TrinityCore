-- 190925 - Harpoon
DELETE FROM `jump_charge_params` WHERE `id` = 18;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`) VALUES
(18, 0.36, 1, 30.8642, 47819, NULL, NULL);
