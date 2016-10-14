UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=38222;
UPDATE `creature_template` SET `speed_run`=0.571429 WHERE `entry`=38222;
UPDATE `spell_dbc` SET `DurationIndex`=29, `Effect1`=6, `EffectImplicitTargetA1`=1, `EffectApplyAuraName1`=61, `EffectBasePoints1`=100 WHERE `Id`=71290;

DELETE FROM `linked_respawn`WHERE `guid`=201129 AND `linkedGuid`=201129;
DELETE FROM `creature_template_addon` WHERE `entry` IN (38009,38010,38136);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(38009,0,0,0,0,0,71235),
(38010,0,0,0,0,0,'71234 70768'),
(38136,0,0,0,0,0,70901);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_deathwhisper_dominated_mind', 'spell_deathwhisper_summon_spirits','spell_cultist_dark_martyrdom');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71289,'spell_deathwhisper_dominated_mind'),
(72478,'spell_deathwhisper_summon_spirits');
