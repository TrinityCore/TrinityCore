UPDATE creature_template SET scriptname = "boss_flame_leviathan" WHERE entry = 33113;
UPDATE creature_template SET scriptname = "boss_flame_leviathan_turret" WHERE entry = 33139;
UPDATE creature_template SET scriptname = "boss_flame_leviathan_seat" WHERE entry = 33114;
UPDATE creature_template SET scriptname = "boss_flame_leviathan_defense_turret" WHERE entry = 33142;
UPDATE creature_template SET scriptname = "boss_flame_leviathan_overload_device" WHERE entry = 33143;
UPDATE creature_template SET scriptname = "boss_razorscale" WHERE entry = 33186;

INSERT INTO creature_template (entry, vehicleid) VALUES
(33113, 340), # Flame Leviathan
(33114, 341) # Flame Leviathan Seat
ON DUPLICATE KEY UPDATE
vehicleid = VALUES(vehicleid);

UPDATE creature_template SET flags_extra = 128 WHERE entry IN (33114);

INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4, spell5, spell6, vehicleid) VALUES
(33062, 62974, 62286, 62299, 64660, 0, 0, 335), # Salvaged Chopper
(33109, 62306, 62490, 62308, 62324, 0, 0, 338), # Salvaged Demolisher
(33167, 62634, 64979, 62479, 62471, 0, 62428, 345), # Salvaged Demolisher Mechanic Seat
(33060, 62345, 62522, 62346, 0, 0, 0, 336), # Salvaged Siege Engine
(33067, 62358, 62359, 64677, 0, 0, 0, 337) # Salvaged Siege Turret
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4),
spell5 = VALUES(spell5),
spell6 = VALUES(spell6),
vehicleid = VALUES(vehicleid);

DELETE FROM `spell_script_target` WHERE `entry` IN (62374,62399);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(62374, 1, 33060), # Pursued
(62374, 1, 33109),
(62399, 1, 33139); # Overload Circuit
