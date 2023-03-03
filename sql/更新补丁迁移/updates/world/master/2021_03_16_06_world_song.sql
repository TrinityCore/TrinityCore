UPDATE `areatrigger_template` SET `ScriptName`='at_monk_song_of_chiji' WHERE (`Id`='10191');
UPDATE `spell_areatrigger` SET `AreaTriggerId`='2763' WHERE (`SpellMiscId`='2763');
REPLACE INTO `areatrigger_template` (`Id`, `Type`, `Data0`, `Data1`, `ScriptName`) VALUES ('2763', '5', '10', '10', 'at_monk_windwalking');
