DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47670; -- Awaken Gortok
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,47670,0,0,31,0,3,26687,0,0,0,0,'','Effect_0 hits Gortok Palehoof');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47669; -- Awaken Subboss
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,47669,0,0,31,0,3,26683,0,0,0,0,'','Effect_0 hits Frenzied Worgen'),
(13,1,47669,0,1,31,0,3,26684,0,0,0,0,'','Effect_0 hits Ravenous Furbolg'),
(13,1,47669,0,2,31,0,3,26685,0,0,0,0,'','Effect_0 hits Massive Jormungar'),
(13,1,47669,0,3,31,0,3,26686,0,0,0,0,'','Effect_0 hits Ferocious Rhino');

-- DELETE FROM `linked_respawn` WHERE `linkedGuid`=126102;
-- DELETE FROM `creature` WHERE `guid` IN(126091,126092,126093,126094,126256);
-- DELETE FROM `creature_addon` WHERE `guid` IN(126091,126092,126093,126094,126256);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=26687; -- Gortok Palehoof
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(26687,0,1,26683,262.195,-440.502,104.82 ,3.9968 ,6,6000),
(26687,0,1,26684,262.119,-463.103,104.787,2.04204,6,6000),
(26687,0,1,26685,290.781,-440.816,104.816,3.56047,6,6000),
(26687,0,1,26686,291.549,-462.653,104.824,2.67035,6,6000),
(26687,0,1,22515,238.608,-460.71 ,109.567,1.53589,8,0   );

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_palehoof_crazed',
'spell_palehoof_awaken_subboss',
'spell_palehoof_awaken_gortok',
'spell_palehoof_crazed_effect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48139,'spell_palehoof_crazed'),
(47669,'spell_palehoof_awaken_subboss'),
(47670,'spell_palehoof_awaken_gortok'),
(48146,'spell_palehoof_crazed_effect');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=48048;

UPDATE `creature_template` SET `ScriptName`='boss_frenzied_worgen' WHERE `entry`=26683;
UPDATE `creature_template` SET `ScriptName`='boss_ravenous_furbolg' WHERE `entry`=26684;
UPDATE `creature_template` SET `ScriptName`='boss_massive_jormungar' WHERE `entry`=26685;
UPDATE `creature_template` SET `ScriptName`='boss_ferocious_rhino' WHERE `entry`=26686;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=26688;

-- DELETE FROM `spelldifficulty_dbc` WHERE  `id` IN (48261,48256,48140,48137,48105,48136,48133);
-- INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
-- (48261, 48261, 59268),
-- (48256, 48256, 59267),
-- (48140, 48140, 59273),
-- (48137, 48137, 59265),
-- (48105, 48105, 59263),
-- (48136, 48136, 59272),
-- (48133, 48133, 59271);
