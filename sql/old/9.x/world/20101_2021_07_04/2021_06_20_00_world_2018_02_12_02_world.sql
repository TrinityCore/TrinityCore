UPDATE `serverside_spell` SET `BaseLevel`=0, `SpellLevel`=0, `SpellFamilyName`=0, `SpellFamilyFlags1`=0, `PreventionType`=0 WHERE `Id`=47802;

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=47802;
INSERT INTO `serverside_spell_effect` (`SpellID`,`EffectIndex`,`Effect`,`ImplicitTarget1`,`EffectAura`) VALUES
(47802,0,6,1,118),
(47802,1,6,1,88);
