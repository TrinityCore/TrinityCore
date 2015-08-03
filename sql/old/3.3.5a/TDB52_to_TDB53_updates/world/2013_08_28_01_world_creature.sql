SET @CGUID := 53919; -- set by TDB team (8)

UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=30755;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 30755, 571, 1, 1, 5844.797, 479.632, 657.6495, 3.351032, 120, 0, 0), -- Kor'kron Reaver (Area: 4395)
(@CGUID+1, 30755, 571, 1, 1, 5848.494, 480.568, 657.6278, 3.368485, 120, 0, 0), -- Kor'kron Reaver (Area: 4395)
(@CGUID+2, 30755, 571, 1, 1, 5845.834, 475.8459, 657.7172, 3.298672, 120, 0, 0), -- Kor'kron Reaver (Area: 4395)
(@CGUID+3, 30755, 571, 1, 1, 5849.62, 476.4291, 657.7032, 3.222836, 120, 0, 0), -- Kor'kron Reaver (Area: 4395)
(@CGUID+4, 30352, 571, 1, 1, 5803.514, 494.7659, 657.2115, 5.54129, 120, 0, 0), -- Skybreaker Marine (Area: 4395)
(@CGUID+5, 30352, 571, 1, 1, 5805.08, 492.9698, 657.2003, 5.584598, 120, 0, 0), -- Skybreaker Marine (Area: 4395)
(@CGUID+6, 30352, 571, 1, 1, 5801.245, 492.336, 657.3757, 5.602507, 120, 0, 0), -- Skybreaker Marine (Area: 4395)
(@CGUID+7, 30352, 571, 1, 1, 5802.888, 490.7988, 657.3538, 5.602507, 120, 0, 0); -- Skybreaker Marine (Area: 4395)
