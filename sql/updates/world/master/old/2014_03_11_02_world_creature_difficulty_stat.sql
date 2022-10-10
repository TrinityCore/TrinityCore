-- Some updates for HP mod.
DELETE FROM creature_difficulty_stat WHERE `entry` in (40600, 42897, 44704, 44932);
INSERT INTO `creature_difficulty_stat` (`entry`, `difficulty`, `dmg_multiplier`, `Health_mod`) VALUES
(40600, 0, 1.15, 3.62012),
(40600, 1, 1.15, 4.34946),
(42897, 3, 1.15, 6.95914),
(42897, 2, 1.15, 5.21935),
(42897, 1, 1.15, 2.08774),
(42897, 0, 1.15, 2.08774),
(44704, 0, 1.15, 1.75854),
(44704, 1, 1.15, 5.63432),
(44932, 0, 1.15, 5.07709),
(44932, 1, 1.15, 10.1666);