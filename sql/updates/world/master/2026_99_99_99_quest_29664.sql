-- Quest
UPDATE `quest_template_locale` SET `LogTitle`='Las llamas del desafío', `LogDescription`='Enciende tu antorcha de contendiente sin encender en el blandón de llamas chisporroteantes y luego úsala para encender los 3 blandones cerca del maestro Li Fei.', `QuestDescription`='Tu mente y tu voluntad son fuertes, pero te falta la habilidad necesaria para desafiarme en combate. Debes luchar con el cuerpo, pero en realidad es tu carácter lo que está a prueba.$b$bVamos a darte un poco de ventaja.$b$bCoge esta antorcha, enciéndela en el blandón que tengo al lado y luego enciende los tres blandones que hay alrededor de la charca.', `VerifiedBuild`=55461 WHERE (`ID`=29664 AND `locale`='esES');

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='esES' AND `ID` IN (29664,29420));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(29664, 'esES', 'Esas llamas te darán la fuerza que aún no has obtenido. Iluminarán tu potencial.', 55461),
(29420, 'esES', 'El objetivo de la vida no es encontrarse a uno mismo: es crearse a uno mismo. Un camino se extiende ante ti, pero eres tú quien debe elegir las pruebas a las que te enfrentarás... y las pruebas que superarás.', 55461);

DELETE FROM `quest_template_addon` WHERE `ID` IN (29420, 29664, 29421);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(29420, 0, 0, 0, 29418, 29664, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(29664, 0, 0, 0, 29420, 29421, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, ''),
(29421, 0, 0, 0, 29664, 29422, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `quest_objectives_locale` SET `Description`='Blandón violeta encendido', `VerifiedBuild`=55461 WHERE (`ID`=255754 AND `locale`='esES');
UPDATE `quest_objectives_locale` SET `Description`='Blandón azul encendido', `VerifiedBuild`=55461 WHERE (`ID`=255753 AND `locale`='esES');
UPDATE `quest_objectives_locale` SET `Description`='Blandón rojo encendido', `VerifiedBuild`=55461 WHERE (`ID`=255752 AND `locale`='esES');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=55461 WHERE (`ID`=255751 AND `locale`='esES');

DELETE FROM `quest_request_items_locale` WHERE (`ID`=29664 AND `locale`='esES');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(29664, 'esES', 'No estás $glisto:lista; para desafiarme. Antes debes encender los blandones.', 55461);

DELETE FROM `quest_request_items` WHERE `ID`=29664;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `VerifiedBuild`) VALUES
(29664, 0, 1, 0, 0, 55461); -- The Challenger's Fires

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID`=255751;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(255751, NULL, 108695, NULL, 0, 1);

UPDATE `quest_template_addon` SET `ScriptName`='quest_the_challengers_fires' WHERE `ID`=29664;

-- Creatures
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=57625;

DELETE FROM `creature` WHERE `guid` IN (450604, 450603, 450602); -- Duplicated spawns
DELETE FROM `creature` WHERE `guid` IN (450598, 450599, 450600, 450601);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(450598, 57625, 860, 5736, 5849, '0', 0, 0, 0, 0, 1333.5191650390625, 3945.1171875, 110.6262893676757812, 5.951572895050048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Generic Sparkle Bunny (CSA) (Area: Shrine of Inner-Light - Difficulty: 0) CreateObject1 (Auras: 92406 - Cosmetic - Loot Sparkles (3.00), 84957 - Generic Quest Invisibility 19)
(450599, 57625, 860, 5736, 5849, '0', 0, 0, 0, 0, 1333.3958740234375, 3932.41845703125, 110.48321533203125, 4.206243515014648437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Generic Sparkle Bunny (CSA) (Area: Shrine of Inner-Light - Difficulty: 0) CreateObject1 (Auras: 92406 - Cosmetic - Loot Sparkles (3.00), 85813 - Generic Quest Invisibility 20, 90442 - Generic Quest Invisibility 17)
(450600, 57625, 860, 5736, 5849, '0', 0, 0, 0, 0, 1367.3367919921875, 3937.702392578125, 110.3123931884765625, 4.206243515014648437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Generic Sparkle Bunny (CSA) (Area: Shrine of Inner-Light - Difficulty: 0) CreateObject1 (Auras: 92406 - Cosmetic - Loot Sparkles (3.00), 85813 - Generic Quest Invisibility 20, 84667 - Generic Quest Invisibility 16)
(450601, 57625, 860, 5736, 5849, '0', 0, 0, 0, 0, 1343.078125, 3957.512939453125, 110.526123046875, 4.206243515014648437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Generic Sparkle Bunny (CSA) (Area: Shrine of Inner-Light - Difficulty: 0) CreateObject1 (Auras: 92406 - Cosmetic - Loot Sparkles (3.00), 85813 - Generic Quest Invisibility 20, 87237 - Generic Quest Invisibility 18)

DELETE FROM `creature_addon` WHERE `guid` IN (450598, 450599, 450600, 450601);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450598, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '92406 84957'), -- Generic Sparkle Bunny (CSA) - 92406 - Cosmetic - Loot Sparkles (3.00), 84957 - Generic Quest Invisibility 19
(450599, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '92406 85813 90442'), -- Generic Sparkle Bunny (CSA) - 92406 - Cosmetic - Loot Sparkles (3.00), 85813 - Generic Quest Invisibility 20, 90442 - Generic Quest Invisibility 17
(450600, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '92406 85813 84667'), -- Generic Sparkle Bunny (CSA) - 92406 - Cosmetic - Loot Sparkles (3.00), 85813 - Generic Quest Invisibility 20, 84667 - Generic Quest Invisibility 16
(450601, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '92406 85813 87237'); -- Generic Sparkle Bunny (CSA) - 92406 - Cosmetic - Loot Sparkles (3.00), 85813 - Generic Quest Invisibility 20, 87237 - Generic Quest Invisibility 18

UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=55461 WHERE (`Entry`=57625 AND `DifficultyID`=0); -- 57625 (Generic Sparkle Bunny (CSA)) - Sessile, Floating
UPDATE `creature_template` SET `unit_flags3`=0x40000000 WHERE `entry`=57625; -- Generic Sparkle Bunny (CSA)

-- GameObject
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (209369, 209803, 209802, 209801);
DELETE FROM `gameobject` WHERE `guid` IN (300150, 300151, 300153); -- Duplicated spawns

UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=55461 WHERE `entry`=209803; -- Brazier of the Violet Flame
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=55461 WHERE `entry`=209801; -- Brazier of the Red Flame
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=55461 WHERE `entry`=209369; -- Brazier of the Flickering Flame
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=55461 WHERE `entry`=209802; -- Brazier of the Blue Flame

DELETE FROM `gameobject_addon` WHERE `guid` IN (300145, 300146, 300147);
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`, `WorldEffectID`, `AIAnimKitID`) VALUES
(300145, 0, 0, 0, 1, 23, 1000, 0, 0),
(300146, 0, 0, 0, 1, 21, 1000, 0, 0),
(300147, 0, 0, 0, 1, 22, 1000, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 34 AND `SourceEntry` = 13004);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(34, 0, 13004, 0, 0, 48, 0, 255751, 0, 0, 0, 0, 0, '', 'Satisfy PlayerCondition 13004 if questobjective 255751 is not done');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 34 AND `SourceEntry` = 13007);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(34, 0, 13007, 0, 0, 48, 0, 255751, 0, 1, 0, 0, 0, '', 'Satisfy PlayerCondition 13007 if questobjective 255751 is done');

-- Spell Area
DELETE FROM `spell_area` WHERE `spell` IN (108694, 108695, 105156, 105157, 105158) AND `area`=5849;
DELETE FROM `spell_area` WHERE `spell`=108695 AND `area`=5849 AND `quest_start`=29664 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(108695, 5849, 29664, 0, -108694, 0, 2, 3, 8, 0);
(108694, 5849, 29664, 0, -108695, 0, 2, 3, 8, 0);

-- Missing data from prior quest 29420
-- Flame Spouts Serverside spells
DELETE FROM `serverside_spell` WHERE `Id` IN (115914, 115915, 85438) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(115914, 0, 0, 0, 0, 0x29800180, 0x10000420, 0x10484005, 0x10130200, 0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 13, 0, 0, 0, -1, 0, 0, 0, 'Grow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1, 0),
(115915, 0, 0, 0, 0, 0x29800180, 0x10000420, 0x10484005, 0x10130200, 0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 13, 0, 0, 0, -1, 0, 0, 0, 'Grow', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1, 0),
(85438, 0, 0, 0, 0, 0x800180, 0x10000000, 0x5, 0x100000, 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 13, 0, 0, 0, -1, 0, 0, 0, 'Shrink', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (115914, 115915, 85438) AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(115914, 0, 0, 6, 61, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(115915, 0, 0, 6, 61, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(85438, 0, 0, 6, 61, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -20, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (450558, 450560, 450561, 450562, 450566, 450567, 450568, 450569, 450571, 450575, 450576, 450579, 450580, 450582, 450583, 450585);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450558, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115915'),
(450560, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96112'),
(450561, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115914'),
(450562, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '85438'),
(450566, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '85438'),
(450567, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115914'),
(450568, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '85438'),
(450569, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '85438'),
(450571, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96112'),
(450575, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115914'),
(450576, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115915'),
(450579, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115914'),
(450580, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '85438'),
(450582, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115915'),
(450583, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '85438'),
(450585, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96112');
