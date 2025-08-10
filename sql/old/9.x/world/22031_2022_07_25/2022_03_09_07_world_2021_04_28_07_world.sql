--
UPDATE `serverside_spell` SET `AttributesEx`=`AttributesEx`|32, `AttributesEx2`=1, `AttributesEx3`=1048576, `RangeIndex`=13, `SchoolMask`=0 WHERE `Id`=39960;

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=39960;
INSERT INTO `serverside_spell_effect` (`SpellID`,`EffectIndex`,`Effect`,`EffectAura`,`EffectChainAmplitude`,`EffectBasePoints`,`EffectMiscValue1`,`ImplicitTarget1`) VALUES
(39960, 0, 6, 139, 1, 2, 929, 1),
(39960, 1, 6, 139, 1, 2, 1001, 1);

DELETE FROM `spell_area` WHERE `spell`=39960;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(39960, 3522, 11000, 0, 0, 0, 2, 3, 64, 11);
