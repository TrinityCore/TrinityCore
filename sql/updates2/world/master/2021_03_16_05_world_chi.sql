UPDATE `areatrigger_template` SET `ScriptName`='at_monk_chi_burst_damage' WHERE (`Id`='5302');
UPDATE `areatrigger_template` SET `ScriptName`='at_monk_chi_burst_heal' WHERE (`Id`='5300');
REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`) VALUES ('1316', '5300');
REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`) VALUES ('1315', '5300');
UPDATE `areatrigger_template` SET `ScriptName`='at_monk_chi_burst' WHERE (`Id`='5300');
UPDATE `areatrigger_template` SET `ScriptName`='' WHERE (`Id`='5302');
