UPDATE `creature` SET `position_x`=340.1726, `position_y`=-878.5924, `position_z`=-74.86385, `orientation`=0.3316126 WHERE `id`=30258;
UPDATE `creature_template` SET `InhabitType`=12, `flags_extra`=0 WHERE `entry` IN(30391,31461,30435,31462);
UPDATE `spell_dbc` SET `StackAmount`=3 ,`Effect1`=6, `EffectBasePoints1`=100, `EffectImplicitTargetA1`=1, `EffectApplyAuraName1`=61 WHERE `Id`=57059;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_amanitar_potent_fungus';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56648,'spell_amanitar_potent_fungus');
