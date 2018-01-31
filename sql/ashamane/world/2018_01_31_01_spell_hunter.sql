DELETE FROM spell_script_names WHERE scriptname = "spell_hun_explosive_shot_detonate");
INSERT INTO spell_script_names VALUES
(212679, "spell_hun_explosive_shot_detonate");

DELETE FROM `spell_areatrigger_splines` WHERE SpellMiscId = 7019;
INSERT INTO `spell_areatrigger_splines` (`SpellMiscId`, `Idx`, `X`, `VerifiedBuild`) VALUES
(7019, 0, 0,  25549),
(7019, 1, 42, 25549);
