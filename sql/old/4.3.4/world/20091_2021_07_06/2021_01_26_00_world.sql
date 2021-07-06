DELETE FROM `spelleffect_dbc` WHERE `Id`= 160110;
INSERT INTO `spelleffect_dbc`(`Id`, `Effect`, `EffectAmplitude`, `EffectAura`, `EffectAuraPeriod`, `EffectBasePoints`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectPointsPerResource`, `EffectRadiusIndex`, `EffectRadiusMaxIndex`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160110, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 43388, 0, '(Serverside/Non-DB2) Suicide, No Blood, No Logging');

UPDATE `creature_template` SET `unit_flags`= `unit_flags` | 0x2000000 WHERE `entry`= 44709;
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 0x200 WHERE `entry` IN (44704, 49260);

DELETE FROM `smart_scripts` WHERE `entryorguid`= 44713 AND `source_type`= 0;
UPDATE `creature_template` SET `AIName`= 'NullCreatureAI' WHERE `entry`= 44713;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_siamat_cloud_burst';
