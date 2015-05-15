UPDATE `creature_template` SET `ScriptName`="npc_meteor_strike_flame" WHERE `entry`=40055;

DELETE FROM `spell_script_names` WHERE `spell_id`=75880 OR `ScriptName`="spell_halion_spawn_living_embers";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75880, "spell_halion_spawn_living_embers");

DELETE FROM `spelleffect_dbc` WHERE `EffectSpellId` IN (75880, 75881);
SET @MaxEffectEntry := (SELECT MAX(Id) + 1 FROM `spelleffect_dbc`);
INSERT INTO `spelleffect_dbc` (`Id`, `EffectSpellId`, `EffectIndex`, `Effect`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectMiscValue`, `EffectMiscValueB`) VALUES
(@MaxEffectEntry + 0, 75880, 0, 77, 22, 7, 12, 12, 0, 0),
(@MaxEffectEntry + 1, 75881, 0, 28, 18, 0, 12, 12, 40055, 64);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75880;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 75880, 31, 0, 3, 40055, "Spawn Living Embers can only target Meteor Strike (Flame)");
