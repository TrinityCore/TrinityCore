-- Update Template
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_anduin_wrynn_nation_of_kultiras' WHERE `entry` = 120756;

UPDATE `creature` SET `npcflag` = 3 WHERE `guid` = 850697;

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=4896;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(4896, 17624, 0, 52607);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=4896 AND `Idx` IN (2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(4896, 64275, 850675, 2, 0, 0, 0, 0, 52607), -- Full: 0x203CC8000075F50000187100000163C1 Creature/0 R3890/S6257 Map: 0 (Eastern Kingdoms) Entry: 120788 (Genn Greymane) Low: 91073
(4896, 53220, 850679, 1, 0, 0, 0, 0, 52607), -- Full: 0x203CC8000075ED0000187100000163C2 Creature/0 R3890/S6257 Map: 0 (Eastern Kingdoms) Entry: 120756 (Anduin Wrynn) Low: 91074
(4896, 0, 0, 0, 0, 0, 0, 1, 52607); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

DELETE FROM `conversation_line_template` WHERE `Id` IN (17623, 17622, 17621, 17620, 17619, 17618, 17624);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(17623, 0, 2, 0, 0, 52607),
(17622, 0, 1, 0, 0, 52607),
(17621, 0, 1, 0, 0, 52607),
(17620, 0, 1, 0, 0, 52607),
(17619, 0, 2, 0, 0, 52607),
(17618, 0, 1, 0, 0, 52607),
(17624, 0, 0, 0, 0, 52607);

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` = 279998;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(279998, 'spell_kultiras_skip_intro');

-- Serverside spell
DELETE FROM `serverside_spell` WHERE `Id` = 247285;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(247285, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'KulTiras Skip Intro - Teleport Unit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 247285 AND `EffectIndex` = 0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(247285, 0, 0, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.52375, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 17);

-- Spell target pos.
DELETE FROM `spell_target_position` WHERE `ID` = 247285;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(247285, 0, 1643, 1053.48, -627.64, 0.54, 0);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 120590;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(120590, 0, 0, 'I must prepare my ship. Champion, meet me in the harbor when you are ready to depart.', 12, 0, 100, 1, 0, 112107, 1, 129944, 0, 'Lady Jaina Proudmoore to Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=120590 AND `MenuID`=22328);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(120590, 22328, 52607); -- Lady Jaina Proudmoore

UPDATE `gossip_menu` SET `VerifiedBuild`=52607 WHERE (`MenuID`=22328 AND `TextID`=34271);

UPDATE `gossip_menu_option` SET `GossipOptionID`=47616, `BoxText`='Are you sure you want to skip the Kul Tiras introductory quests?', `BoxBroadcastTextID`=161817, `VerifiedBuild`=52607 WHERE (`MenuID`=22328 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47615, `VerifiedBuild`=52607 WHERE (`MenuID`=22328 AND `OptionID`=0);

-- Quest stuff
DELETE FROM `creature_queststarter` WHERE (`id`=120756 AND `quest`=46728);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(120756, 46728, 52607); -- The Nation of Kul Tiras offered Anduin Wrynn

DELETE FROM `quest_template_addon` WHERE `ID` = 46728;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(46728, 0, 0, 0, 46727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
