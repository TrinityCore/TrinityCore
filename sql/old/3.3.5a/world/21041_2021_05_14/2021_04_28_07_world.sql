--
UPDATE `spell_dbc` SET `AttributesEx`=`AttributesEx`|32, `AttributesEx2`=1, `AttributesEx3`=1048576, `RangeIndex`=13, `Effect1`=6, `Effect2`=6, `EffectDieSides1`=1, `EffectDieSides2`=1, `EffectBasePoints1`=2, `EffectBasePoints2`=2, `EffectImplicitTargetA1`=1, `EffectImplicitTargetA2`=1, `EffectApplyAuraName1`=139, `EffectApplyAuraName2`=139, `EffectMiscValue1`=929, `EffectMiscValue2`=1001, `DmgMultiplier1`=1, `DmgMultiplier2`=1, `SchoolMask`=0 WHERE  `Id`=39960;

DELETE FROM `spell_area` WHERE `spell`=39960;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(39960, 3522, 11000, 0, 0, 0, 2, 1, 64, 11);
