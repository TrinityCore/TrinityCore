SET @CGUID := 461000;

-- Zidormi spawn
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 88206, 0, 4, 0, '0', 1, 0, 0, 0, 0, -10761.142578125, -2957.66845703125, 58.74221420288085937, 3.043509483337402343, 120, 0, 0, 2035, 0, 0, 0, 0, 50747); -- Zidormi (Area: 0 - Difficulty: 0) CreateObject1

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 88206;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(88206, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 88206 (Zidormi)

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId`=88206;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(88206, 0, 0, 3, 1, 0, 0, NULL);

-- Serverside Spells
DELETE FROM `serverside_spell` WHERE `Id`=81040 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(81040, 0, 0, 0, 0, (0x29800180), (0x420), (0x10484005), (0x10130200), (0x800080), (0x60008), (0x1200), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, '(Serverside/Non-DB2) Update Zone Auras and Phase Shift', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=81040 AND `EffectIndex` IN (0, 1) AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(81040, 0, 0, 170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(81040, 1, 0, 167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell` WHERE `Id`=176113 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(176113, 0, 0, 0, 0, (0x29800180), (0xc20), (0x10484005), (0x10130200), (0x8000c0), (0x60008), (0x1200), 0, 0, (0x100000), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66, 1, 0, 0, 0, -1, 0, 0, 0, '(Serverside/Non-DB2) Time Travelling', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=176113 AND `EffectIndex` IN (0, 1, 2, 3) AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(176113, 0, 0, 139, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 66560, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(176113, 1, 0, 164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 176111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(176113, 2, 0, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 129809, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(176113, 3, 0, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 81040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Tracker Quest
DELETE FROM `quest_template` WHERE `ID`=66560;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(66560, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Blasted Lands Terrain Swap Condition Quest', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0);

-- Gossip data
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=17269 AND `OptionID`=1);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(42959, 17269, 1, 0, 'Take me back to the present.', 68815, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50747);

UPDATE `gossip_menu_option` SET `GossipOptionID`=42958, `OptionBroadcastTextID`=90350, `VerifiedBuild`=50747 WHERE (`MenuID`=17269 AND `OptionID`=0);

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId`=4 AND `PhaseId` IN (2801, 3146);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4, 2801, 'Blasted Lands Present (A)'),
(4, 3146, 'Blasted Lands Present (H)');

-- TerrainSwap
DELETE FROM `terrain_worldmap` WHERE `UiMapPhaseId` IN (2801, 3146);
INSERT INTO `terrain_worldmap` (`TerrainSwapMap`, `UiMapPhaseId`, `Comment`) VALUES
(1190, 2801, 'Blasted Land Swap Alliance'),
(1190, 3146, 'Blasted Land Swap Horde');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `ConditionValue1` IN (66560, 81408);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25, 0, 1190, 0, 0, 47, 0, 66560, 1, 0, 0, 0, 0, '', 'TerrainSwap to 1190 if Quest: 66560 is not taken'),
(25, 0, 1190, 0, 0, 56, 0, 81408, 0, 0, 0, 0, 0, '', 'TerrainSwap to 1190 if PlayerCondition 81408 is satisfied');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=17269 AND `ConditionValue1` IN (66560, 81408);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 17269, 0, 0, 0, 47, 0, 66560, 1, 0, 0, 0, 0, '', 'Gossip Option 17269 - Show Option 0 if Quest 66560 is not taken'),
(15, 17269, 0, 0, 0, 56, 0, 81408, 0, 0, 0, 0, 0, '', 'Gossip Option 17269 - Show Option 0 if PlayerCondition 81408 is satisfied'),
(15, 17269, 1, 0, 0, 47, 0, 66560, 64, 0, 0, 0, 0, '', 'Gossip Option 17269 - Show Option 1 if Quest 66560 is rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=2801 AND `ConditionValue1` IN (66560, 81408, 469);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 2801, 4, 0, 0, 47, 0, 66560, 1, 0, 0, 0, 0, '', 'Apply Phase 2801 if Quest 66560 is not taken'),
(26, 2801, 4, 0, 0, 56, 0, 81408, 0, 0, 0, 0, 0, '', 'Apply Phase 2801 if PlayerCondition 81408 is satisfied'),
(26, 2801, 4, 0, 0, 6, 0, 469, 0, 0, 0, 0, 0, '', 'Apply Phase 2801 if Team Alliance');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3146 AND `ConditionValue1` IN (66560, 81408, 67);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3146, 4, 0, 0, 47, 0, 66560, 1, 0, 0, 0, 0, '', 'Apply Phase 3146 if Quest 66560 is not taken'),
(26, 3146, 4, 0, 0, 56, 0, 81408, 0, 0, 0, 0, 0, '', 'Apply Phase 3146 if PlayerCondition 81408 is satisfied'),
(26, 3146, 4, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply Phase 3146 if Team Horde');

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=88206; -- 88206 (Zidormi)
DELETE FROM `smart_scripts` WHERE `entryorguid`=88206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(88206, 0, 0, 1, 62, 0, 100, 0, 17269, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Zidormi - On Gossip Option 0 Selected - Close Gossip'),
(88206, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 176111, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Zidormi - On Gossip Option 0 Selected - Invoker Cast \'Time Travelling\''),
(88206, 0, 2, 3, 62, 0, 100, 0, 17269, 1, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Zidormi - On Gossip Option 1 Selected - Close Gossip'),
(88206, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 176113, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Zidormi - On Gossip Option 1 Selected - Invoker Cast \'Time Travelling\'');
