ALTER TABLE `jump_charge_params` ADD COLUMN `triggerSpellId` INT(11) NULL AFTER `parabolicCurveId`;

DELETE FROM `jump_charge_params` WHERE `id` IN (529,530,531,592,574,566,661,557,707,658,719,660,700,693,649,720,648,647,709,702);
INSERT INTO `jump_charge_params` (`id`,`speed`,`treatSpeedAsMoveTimeSeconds`,`jumpGravity`,`spellVisualId`,`progressCurveId`,`parabolicCurveId`,`triggerSpellId`) VALUES
(529,   0.5,   1, 47.8086, NULL,   NULL, NULL, NULL),
(530,   0.5,   1, 47.8086, NULL,   NULL, NULL, NULL),
(531,   0.15,  1, 526.293, NULL,   NULL, NULL, NULL),
(592,   0.3,   1, 266.666, 109373, NULL, NULL, NULL),
(574,   0.04,  1, 5234.23, 108414, NULL, NULL, NULL),
(566,   1,     1, 39.3676, 108168, NULL, NULL, NULL),
(557,   1.25,  1, 19.2911, 109373, NULL, NULL, NULL),
(661,   0.75,  1, 70.9219, NULL,   392,  NULL, NULL),
(707,   2,     1, 19.2911, NULL,   NULL, NULL, NULL),
(658,   2,     1, 19.2911, 116541, NULL, NULL, 374075),
(719,   2,     1, 23.976,  NULL,   NULL, NULL, NULL),
(660,   1,     1, 23.9521, NULL,   NULL, NULL, NULL),
(700,   0.75,  1, 73.6797, 119220, NULL, NULL, NULL),
(693,   1,     1, 6.96146, 93595,  NULL, NULL, 382441),
(649,   0.75,  1, 42.5531, NULL,   NULL, NULL, 369696),
(720,   5,     1, 3.19871, NULL,   NULL, NULL, NULL),
(648,   0.35,  1, 189.37,  NULL,   NULL, NULL, 369602),
(647,   0.5,   1, 84.7985, NULL,   NULL, NULL, 369424),
(709,   0.233, 1, 19.2911, NULL,   NULL, NULL, NULL),
(702,   0.5,   1, 19.2911, NULL,   NULL, NULL, NULL);
