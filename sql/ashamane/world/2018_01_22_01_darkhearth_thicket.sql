DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceGroup = 1 AND SourceEntry = 204613;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 204613, 31, 3, 103344, 'Darkheart Thicket - Oakhearth - crushing grip');

UPDATE creature_template SET inhabittype = 4 WHERE entry IN (101072, 95769);
UPDATE creature_template SET scriptname = "npc_dresaron_corrupted_dragon_egg" WHERE entry = 101072;

DELETE FROM spell_areatrigger WHERE SpellMiscId IN (6084, 8722);
INSERT INTO spell_areatrigger (SpellMiscId, AreaTriggerId) VALUES
(6084, 10771),
(8722, 10771);

UPDATE `creature_template` SET `minlevel` = 98, `maxlevel` = 110, `faction` = 16, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE entry = 101074;
