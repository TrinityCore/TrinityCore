DELETE FROM `spell_areatrigger_splines` WHERE `SpellMiscId` = 2148;
INSERT INTO `spell_areatrigger_splines` (`SpellMiscId`, `Idx`, `X`) VALUES
(2148, 0, 0),
(2148, 1, 24),
(2148, 2, 24),
(2148, 3, 0);

UPDATE `spell_areatrigger` SET `TimeToTarget` = 15000 WHERE `SpellMiscId` = 2148;

UPDATE areatrigger_template SET scriptname = "at_pri_divine_star" WHERE Id = 6700;
