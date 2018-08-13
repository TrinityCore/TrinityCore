UPDATE areatrigger_template SET ScriptName = "at_monk_chi_burst_heal" WHERE Id = 5300;
UPDATE areatrigger_template SET ScriptName = "at_monk_chi_burst_damage" WHERE Id = 5302;

UPDATE spell_areatrigger SET TimeToTarget = 1000 WHERE SpellMiscId IN (1315, 1316);

DELETE FROM `spell_areatrigger_splines` WHERE SpellMiscId IN (1315, 1316);
INSERT INTO `spell_areatrigger_splines` VALUES
(1315, 0, 2, 0, 0, 0),
(1315, 1, 40, 0, 0, 0),
(1316, 0, 2, 0, 0, 0),
(1316, 1, 40, 0, 0, 0);
