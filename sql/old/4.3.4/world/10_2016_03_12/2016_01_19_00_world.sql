DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_rapid_recuperation' AND `spell_id` IN (56654,58882);
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_replenishment' AND `spell_id`=61782;
-- Add missing data for spell Spawn Living Embers, serverside
-- Info taken from TDB 335.60
DELETE FROM `spelleffect_dbc` WHERE `Id`=155915 AND `EffectSpellId`=75880;
INSERT INTO `spelleffect_dbc` (`Id`,`Effect`,`EffectValueMultiplier`,`EffectApplyAuraName`,`EffectAmplitude`,`EffectBasePoints`,`EffectBonusMultiplier`,`EffectDamageMultiplier`,`EffectChainTarget`,`EffectDieSides`,`EffectItemType`,`EffectMechanic`,`EffectMiscValue`,`EffectMiscValueB`,`EffectRadiusIndex`,`EffectRadiusIndexMax`,`EffectRealPointsPerLevel`,`EffectSpellClassMaskA`,`EffectSpellClassMaskB`,`EffectSpellClassMaskC`,`EffectTriggerSpell`,`EffectImplicitTargetA`,`EffectImplicitTargetB`,`EffectSpellId`,`EffectIndex`) VALUES
(155915,77,0,0,0,0,0,0,0,0,0,0,0,0,12,12,0,0,0,0,0,22,7,75880,0);
