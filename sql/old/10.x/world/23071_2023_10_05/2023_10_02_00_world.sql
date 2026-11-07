SET @CGUID := 6000139;

SET @NPCTEXTID := 560007;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 99917, 1481, 7705, 7740, '0', 5464, 0, 0, 1, 756.76739501953125, 2401.420166015625, -60.9138259887695312, 1.067818880081176757, 120, 0, 0, 27954, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Sevis Brightflame (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+1, 99914, 1481, 7705, 7740, '0', 5461, 0, 0, 0, 758.97222900390625, 2403.007080078125, -60.9143829345703125, 1.19526827335357666, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 51536); -- Ashtongue Mystic (Area: Molten Shore - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Sevis Brightflame

-- Creature Template
UPDATE `creature_template` SET `ScriptName` = 'npc_sevis_brightflame_coilskar_gateway_private' WHERE `entry` = 99917;

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 99914;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(99914, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Ashtongue Mystic

-- Creature text
DELETE FROM `creature_text` WHERE `CreatureID` = 99917;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(99917, 0, 0, '$n, hurry! You don\'t have much time.', 12, 0, 100, 3, 0, 55345, 0, 101658, 5, 'Sevis Brightflame to Player'),
(99917, 1, 0, 'Sevis looks down at the dying broken mystic.', 16, 0, 100, 3, 0, 55345, 0, 101659, 5, 'Sevis Brightflame to Player'),
(99917, 2, 0, 'I will see you at the final gateway.', 12, 0, 100, 1, 0, 55347, 1, 101662, 0, 'Sevis Brightflame to Player');

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 99914;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(99914, 0, 0, 1, 1, 0, 0, NULL);

-- Objective completion effect
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 280770;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(280770, NULL, NULL, NULL, 1, 0);

-- Gossip & text
DELETE FROM `npc_text` WHERE `ID` = @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 101660, 0, 0, 0, 0, 0, 0, 0, 51536); -- 99917 (Sevis Brightflame)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19017 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19017, @NPCTEXTID+0, 51536); -- 99917 (Sevis Brightflame)

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1077;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1077, 20, 1468, 0);

Update `scene_template` SET `ScriptName` = 'scene_enter_the_illidari_coilskar' WHERE `SceneId` = 1077;

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` = 184562;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(184562, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Enter the Illidari: Coilskar - Legion Gateway Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 184562 AND `EffectIndex` IN (0, 1);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(184562, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94406, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184562, 1, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` IN (5464, 5461) AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5464, 'Sevis Brightflame at Coilskar Gateway'),
(7705, 5461, 'Ashtongue Mystic (for sacrifice) at Coilskar Gateway');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=14 AND `SourceGroup` = 19015 AND `SourceEntry` = 27769); -- Ashtongue Mystic text after sacrifice
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 19015, 27769, 0, 0, 48, 0, 280770, 0, 1, 0, 0, 0, '', 'Show gossip text if player has quest objective done: Soul sacrificed');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup` = 19015 AND `SourceEntry` = 0); -- Ashtongue Mystic gossip menu option
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19015, 0, 0, 0, 48, 0, 280770, 0, 1, 1, 0, 0, '', 'Show gossip menu option if player has not quest objective done: Soul sacrificed');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=14 AND `SourceGroup` = 19017 AND `SourceEntry` = 27773); -- Sevis Brightflame text after sacrifice
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 19017, 27773, 0, 0, 48, 0, 280770, 0, 1, 0, 0, 0, '', 'Show gossip text if player has quest objective done: Soul sacrificed');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup` = 1 AND `SourceEntry` = 191664);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 191664, 0, 0, 31, 0, 3, 24021, 0, 0, 0, 0, '', 'Spell: Enter the Illidari: Shivarra - Soul Missiles 02 - can only hit "ELM general purpose bunny"');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5464 AND `SourceEntry` = 0); -- Sevis Brightflame
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5464, 0, 0, 0, 47, 0, 40379, 8, 0, 0, 'Apply Phase 5464 if Quest 40379 is in progress'),
(26, 5464, 0, 0, 0, 48, 0, 280771, 0, 1, 1, 'Apply Phase 5464 if Questobjective 280771 (Coilskar forces) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5461 AND `SourceEntry` = 0); -- Ashtongue Mystic
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5461, 0, 0, 0, 47, 0, 40379, 2|8|64, 0, 0, 'Apply Phase 5461 if Quest 40379 is complete | in progress | rewarded'),
(26, 5461, 0, 0, 0, 48, 0, 280770, 0, 1, 1, 'Apply Phase 5461 if Questobjective 280770 (Soul sacrificed) is not rewarded');

-- Ashtongue Mystic smart ai
SET @ENTRY := 99914;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 19015, 0, 0, 0, 86, 196724, 0, 7, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Mystic, thank you for you... (0) from menu 19015 selected - Gossip player: Cast spell  196724 at Self'),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 19015, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Mystic, thank you for you... (0) from menu 19015 selected - Gossip player: Close gossip'),
(@ENTRY, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 9991400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Ashtongue Mystic #0 (9991400) (update out of combat)');

 -- Timed list 9991400 smart ai
SET @ENTRY := 9991400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 137, 25111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 25111, KitType: 0 for 0 ms'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 9256, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 9256'),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 159474, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 159474 on self'),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 191664, 0, 0, 0, 0, 0, 10, 7000364, 24021, 0, 0, 0, 0, 0, 'After 1 seconds - cast: (Enter the Illidari: Shivarra - Soul Missiles 02) - to Entry/Guid'),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 191664, 0, 0, 0, 0, 0, 10, 7000364, 24021, 0, 0, 0, 0, 0, 'After 2 seconds - cast: (Enter the Illidari: Shivarra - Soul Missiles 02) - to Entry/Guid'),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 191664, 0, 0, 0, 0, 0, 10, 7000364, 24021, 0, 0, 0, 0, 0, 'After 1 seconds - cast: (Enter the Illidari: Shivarra - Soul Missiles 02) - to Entry/Guid');

-- SendEvent: 47548
SET @EVENTID := 47548;
DELETE FROM `event_script_names` WHERE `Id` = @EVENTID;
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(@EVENTID, 'SmartEventTrigger');

DELETE FROM `smart_scripts` WHERE `source_type` = 3 AND `entryOrGuid` = @EVENTID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@EVENTID, 3, 0, 0, 87, 0, 100, 0, 0, 0, 0, 0, 33, 99914, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On SendEvent: 47548 - reward QuestObjective "Soul sacrificed" - to Invoker'),
(@EVENTID, 3, 1, 0, 87, 0, 100, 0, 0, 0, 0, 0, 12, 99914, 3, 60000, 0, 1, 0, 8, 0, 0, 0, 758.9722, 2403.0070, -60.91438, 1.1952, 'On SendEvent: 47548 - spawn Ashtongue Mystic - to position');

-- Path for Sevis Brightflame Coilskar Gateway
SET @ENTRY := 99917;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 768.1684, 2414.826, -60.3881, NULL, 0, 1),
(@PATH, 1, 795.434, 2450.884, -58.21667, NULL, 0, 1),
(@PATH, 2, 806.4601, 2463.714, -58.40237, NULL, 0, 1),
(@PATH, 3, 818.092, 2477.028, -59.66295, NULL, 0, 1);
