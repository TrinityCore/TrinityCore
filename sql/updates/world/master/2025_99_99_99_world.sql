-- Creature templates
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x4000800, `unit_flags3`=0x1000000, `VehicleId`=2479, `flags_extra`=`flags_extra`|128 WHERE `entry`=66640; -- Rappelling Rope
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_rappelling_rope' WHERE `entry`=66640;

DELETE FROM `creature_template_addon` WHERE `entry`=66640;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(66640, 0, 0, 0, 3, 0, 1, 0, 0, 2353, 0, 0, 0, ''); -- 66640 (Rappelling Rope)

-- Vehicle data
DELETE FROM `vehicle_template` WHERE `creatureId`=66640;
INSERT INTO `vehicle_template` (`creatureId`, `despawnDelayMs`, `Pitch`, `CustomFlags`) VALUES
(66640, 0, NULL, 0x1);

-- Difficulties
UPDATE `creature_template_difficulty` SET `ContentTuningID`=57, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=66640 AND `DifficultyID`=0); -- 66640 (Rappelling Rope) - Floating
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (66640) AND `DifficultyID`!=0;

-- Quests
DELETE FROM `quest_template_addon` WHERE `ID`=31766;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(31766, 0, 0, 0, 31765, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `quest_poi` SET `VerifiedBuild`=61265 WHERE (`QuestID`=31766 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=31766 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=31766 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=83492 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32008 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32008 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=75874 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=65656 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=65656 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=65656 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=65656 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=65656 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=65656 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53435 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53435 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50603 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50562 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49930 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49930 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=27442 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=27442 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=13124 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=61265 WHERE (`QuestID`=31766 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31766 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=31766 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=83492 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=32009 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=32009 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=32008 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=32008 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=75874 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=65656 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=65656 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=65656 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=65656 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=65656 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=65656 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53435 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53435 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50604 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50604 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50603 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50562 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49930 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49930 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=27442 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27442 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=13124 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=31766;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(31766, 1, 0, 0, 0, 0, 0, 0, 0, 61265); -- Touching Ground

DELETE FROM `quest_request_items` WHERE `ID`=31766;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(31766, 0, 0, 0, 0, 'What?', 61265); -- Touching Ground

DELETE FROM `quest_offer_reward` WHERE `ID`=31766;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(31766, 1, 0, 0, 0, 0, 0, 0, 0, 'There you are!$b$bI was starting to worry we''d have to charge in and have all the fun without you.', 61265); -- Touching Ground

UPDATE `creature_queststarter` SET `VerifiedBuild`=61265 WHERE (`id`=66667 AND `quest`=31766);

UPDATE `creature_questender` SET `VerifiedBuild`=61265 WHERE (`id`=66190 AND `quest`=31766);

-- Spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=130970;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 130970, 0, 0, 31, 0, 3, 40789, 0, 0, 0, 0, '', 'Spell "Rappelling Rope Aura" targets Generic Controller Bunny (CSA)');

DELETE FROM `serverside_spell` WHERE `Id`=130999;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `AttributesEx15`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(130999,0,0,0,0,0x29800100,0x10000020,0x4005,0x10100000,0x80,0x60008,0x21600,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,13,0,0,0,-1,0,0,0,'Rappelling Rope Credit',0,0,0,0,0,0,0,0,0,0,0,0,1,0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=130999;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(130999,0,0,134,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66646,0,0,0,0,0,0,0,1,0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rappelling_rope', 'spell_rappelling_rope_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130960, 'spell_rappelling_rope'),
(130970, 'spell_rappelling_rope_aura');

-- Misc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=34 AND `SourceEntry`=18902;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(34, 0, 18902, 0, 0, 47, 0, 31766, 2 | 8, 0, '', 0, 0, 0, '', 'Satisfy player condition if quest 31766 is taken | completed');
