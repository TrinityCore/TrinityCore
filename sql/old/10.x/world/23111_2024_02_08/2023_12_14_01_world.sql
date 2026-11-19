-- Heroic Leap (5644)
DELETE FROM `jump_charge_params` WHERE `id` = 17;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`) VALUES
(17, 0.799, 1, 75.1878, 50217, NULL, NULL);
