--
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 49591;
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 70055;

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (49591,70055);
INSERT INTO `serverside_spell_effect` (`SpellID`,`Effect`,`EffectItemType`,`ImplicitTarget1`) VALUES
(49591,24,37888,25),
(70055,24,49278,25);
