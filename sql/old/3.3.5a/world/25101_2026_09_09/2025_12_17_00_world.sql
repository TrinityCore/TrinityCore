-- Flame Quills
UPDATE `spell_target_position` SET `PositionX` =   244.1, `PositionY` =  49.9153, `PositionZ` = 20.1795, `VerifiedBuild` = 26365 WHERE `ID` = 34269;
UPDATE `spell_target_position` SET `PositionX` = 260.572, `PositionY` =  67.3991, `PositionZ` = 20.1799, `VerifiedBuild` = 26365 WHERE `ID` = 34270;
UPDATE `spell_target_position` SET `PositionX` = 279.967, `PositionY` =  83.4335, `PositionZ` = 20.1794, `VerifiedBuild` = 26365 WHERE `ID` = 34271;
UPDATE `spell_target_position` SET `PositionX` =  306.56, `PositionY` =  92.0271, `PositionZ` = 20.1798, `VerifiedBuild` = 26365 WHERE `ID` = 34272;
UPDATE `spell_target_position` SET `PositionX` = 332.415, `PositionY` =  86.6608, `PositionZ` = 20.3436, `VerifiedBuild` = 26365 WHERE `ID` = 34273;
UPDATE `spell_target_position` SET `PositionX` = 358.834, `PositionY` =   90.569, `PositionZ` =  20.032, `VerifiedBuild` = 26365 WHERE `ID` = 34274;
UPDATE `spell_target_position` SET `PositionX` = 382.319, `PositionY` =  83.0517, `PositionZ` = 20.1796, `VerifiedBuild` = 26365 WHERE `ID` = 34275;
UPDATE `spell_target_position` SET `PositionX` = 403.761, `PositionY` =  69.5173, `PositionZ` = 20.1796, `VerifiedBuild` = 26365 WHERE `ID` = 34276;
UPDATE `spell_target_position` SET `PositionX` = 402.296, `PositionY` =  44.3146, `PositionZ` = 20.1797, `VerifiedBuild` = 26365 WHERE `ID` = 34277;
UPDATE `spell_target_position` SET `PositionX` =  422.53, `PositionY` =  26.9552, `PositionZ` = 20.1798, `VerifiedBuild` = 26365 WHERE `ID` = 34278;
UPDATE `spell_target_position` SET `PositionX` = 261.468, `PositionY` = -73.6918, `PositionZ` = 20.1795, `VerifiedBuild` = 26365 WHERE `ID` = 34279;
UPDATE `spell_target_position` SET `PositionX` = 249.358, `PositionY` = -52.7987, `PositionZ` = 20.1795, `VerifiedBuild` = 26365 WHERE `ID` = 34280;
UPDATE `spell_target_position` SET `PositionX` = 424.829, `PositionY` =  1.01505, `PositionZ` =   20.18, `VerifiedBuild` = 26365 WHERE `ID` = 34281;
UPDATE `spell_target_position` SET `PositionX` = 423.478, `PositionY` = -23.9648, `PositionZ` = 20.1799, `VerifiedBuild` = 26365 WHERE `ID` = 34282;
UPDATE `spell_target_position` SET `PositionX` = 283.424, `PositionY` = -85.9517, `PositionZ` = 20.1798, `VerifiedBuild` = 26365 WHERE `ID` = 34283;
UPDATE `spell_target_position` SET `PositionX` = 404.622, `PositionY` = -42.1397, `PositionZ` = 20.1798, `VerifiedBuild` = 26365 WHERE `ID` = 34284;
UPDATE `spell_target_position` SET `PositionX` =  309.55, `PositionY` = -89.3632, `PositionZ` = 20.1796, `VerifiedBuild` = 26365 WHERE `ID` = 34285;
UPDATE `spell_target_position` SET `PositionX` = 403.462, `PositionY` = -67.8334, `PositionZ` =   20.18, `VerifiedBuild` = 26365 WHERE `ID` = 34286;
UPDATE `spell_target_position` SET `PositionX` = 335.024, `PositionY` =   -83.21, `PositionZ` =  20.388, `VerifiedBuild` = 26365 WHERE `ID` = 34287;
UPDATE `spell_target_position` SET `PositionX` = 384.251, `PositionY` = -84.3709, `PositionZ` =   20.18, `VerifiedBuild` = 26365 WHERE `ID` = 34288;
UPDATE `spell_target_position` SET `PositionX` = 359.997, `PositionY` = -92.7042, `PositionZ` = 20.0127, `VerifiedBuild` = 26365 WHERE `ID` = 34289;
UPDATE `spell_target_position` SET `PositionX` = 241.768, `PositionY` =  24.8276, `PositionY` = 20.3438, `VerifiedBuild` = 26365 WHERE `ID` = 34314;
UPDATE `spell_target_position` SET `PositionX` = 239.111, `PositionY` = -1.59108, `PositionY` = 27.0491, `VerifiedBuild` = 26365 WHERE `ID` = 34315;
UPDATE `spell_target_position` SET `PositionX` = 241.073, `PositionY` = -27.0846, `PositionY` = 20.1794, `VerifiedBuild` = 26365 WHERE `ID` = 34316;

-- Ashtongue Ruse
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 4, `DmgMultiplier1` = 1 WHERE `Id` = 39555;
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 16, `EffectImplicitTargetA1` = 1, `EffectMiscValue1` = 10946, `DmgMultiplier1` = 1 WHERE `Id` = 39701;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_alar_ashtongue_ruse_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39555, 'spell_alar_ashtongue_ruse_master');

UPDATE `quest_template_addon` SET `SpecialFlags` = 2 WHERE `ID` = 10946;

-- Flame Patch
UPDATE `spell_dbc` SET `EffectApplyAuraName1` = 0 WHERE `Id` = 29218;

-- Ember Blast (damage component)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 2, `EffectBasePoints1` = 70000, `EffectImplicitTargetA1` = 38, `DmgMultiplier1` = 1, `DmgMultiplier2` = 1, `DmgMultiplier3` = 1 WHERE `Id` = 41910;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 41910;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,41910,0,0,31,0,3,19514,0,0,0,0,"","Group 0: Spell 'Ember Blast' (Effect 0) targets creature 'Al'ar'");

DELETE FROM `spell_custom_attr` WHERE `entry` = 41910;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(41910, 32768); -- SPELL_ATTR0_CU_IGNORE_ARMOR

-- Ember of Al'ar (copied from 39110, matches sniff)
UPDATE `spell_dbc` SET `ProcChance` = 101, `EquippedItemSubClassMask` = -1, `Effect1` = 28, `EffectDieSides1` = 1, `EffectImplicitTargetA1` = 72, `EffectRadiusIndex1` = 13, `EffectMiscValue1` = 19551, `EffectMiscValueB1` = 64, `DmgMultiplier1` = 1, `DmgMultiplier2` = 1, `DmgMultiplier3` = 1 WHERE `Id` = 41824;

-- Platforms
UPDATE `creature` SET `StringId` = 'AlarPlatformTrigger1' WHERE `guid` = 144097 AND `id` = 15384;
UPDATE `creature` SET `StringId` = 'AlarPlatformTrigger2' WHERE `guid` = 144100 AND `id` = 15384;
UPDATE `creature` SET `StringId` = 'AlarPlatformTrigger3' WHERE `guid` = 144099 AND `id` = 15384;
UPDATE `creature` SET `StringId` = 'AlarPlatformTrigger4' WHERE `guid` = 144098 AND `id` = 15384;
UPDATE `creature` SET `StringId` = 'AlarCenterTrigger' WHERE `guid` = 144096 AND `id` = 15384;

-- A'lar
UPDATE `creature_template` SET `flags_extra` = `flags_extra` |512 WHERE `entry` = 19514;
UPDATE `creature_template_movement` SET `Ground` = 1 WHERE `CreatureId` = 19514;
