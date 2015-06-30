UPDATE `creature_template` SET `ScriptName`="npc_meteor_strike_flame" WHERE `entry`=40055;

DELETE FROM `spell_script_names` WHERE `spell_id`=75880 OR `ScriptName`="spell_halion_spawn_living_embers";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75880, "spell_halion_spawn_living_embers");

UPDATE `spell_dbc` SET `Effect1`=77, `EffectImplicitTargetA1`=22, `EffectImplicitTargetB1`=7, `EffectRadiusIndex1`=12, `EffectMiscValue1`=0, `EffectMiscValueB1`=0 WHERE `Id`=75880;
UPDATE `spell_dbc` SET `Effect1`=28, `EffectImplicitTargetA1`=18, `EffectImplicitTargetB1`=0, `EffectRadiusIndex1`=12, `EffectMiscValue1`=40683, `EffectMiscValueB1`=64 WHERE `Id`=75881;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75880;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 75880, 31, 0, 3, 40055, "Spawn Living Embers can only target Meteor Strike (Flame)");
