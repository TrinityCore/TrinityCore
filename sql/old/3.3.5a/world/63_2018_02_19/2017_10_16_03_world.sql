-- Update boss Toravon the Ice Watcher
UPDATE `creature_template` SET `InhabitType`=11, `ScriptName`='' WHERE `entry`=38461;
UPDATE `spell_dbc` SET `Effect1`=3, `EffectImplicitTargetA1`=22, `EffectImplicitTargetB1`=15, `EffectRadiusIndex1`=28, `MaxAffectedTargets`=1 WHERE `Id`=46523;

DELETE FROM `creature_template_addon` WHERE `entry`=38461;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(38461,0,0,0,1,0,72094);

DELETE FROM `spell_proc` WHERE `SpellId`=71993;
INSERT INTO `spell_proc` (`SpellId`,`ProcFlags`,`HitMask`,`Cooldown`) VALUES
(71993,4,12287,4000);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_toravon_random_aggro';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46523,'spell_toravon_random_aggro');
