DELETE FROM `spell_proc` WHERE `SpellId` IN (440616);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(440616,0x00,6,0x10000400,0x00000000,0x00000000,0x00000400,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Lightwell

DELETE FROM `creature_template` WHERE `entry` IN (189820);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `Classification`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `family`, `trainer_class`, `type`, `VehicleId`, `AIName`, `MovementType`, `ExperienceModifier`, `RacialLeader`, `movementId`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `CreatureImmunitiesId`, `flags_extra`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES (189820, 0, 0, 'Lightwell', '', NULL, NULL, NULL, 0, 0, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 11, 0, '', 0, 1, 0, 0, 0, 0, 1, 0, 0, 'npc_pet_pri_lightwell', NULL, 63796);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_lightwell', 'spell_pri_lightwell_trigger', 'spell_pri_lightspring_renew', 'spell_pri_lightwell_missile', 'spell_pri_lightwell_cd_reduction');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(372835, 'spell_pri_lightwell'),
(372845, 'spell_pri_lightwell_trigger'),
(126141, 'spell_pri_lightspring_renew'),
(439820, 'spell_pri_lightwell_missile'),
(440616, 'spell_pri_lightwell_cd_reduction');
