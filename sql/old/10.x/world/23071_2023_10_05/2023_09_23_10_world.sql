SET @CGUID := 6000124;
SET @OGUID := 6000171;

SET @ATID := 32;
SET @ATIDSPAWN := 37;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 99916, 1481, 7705, 7741, '0', 5463, 0, 0, 1, 1023.25347900390625, 2849.716064453125, 5.42197418212890625, 1.753069400787353515, 120, 0, 0, 27954, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Sevis Brightflame (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+1, 101518, 1481, 7705, 7741, '0', 5658, 0, 0, 0, 1016.70831298828125, 2849.3134765625, 5.483273983001708984, 1.382026076316833496, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Felsaber (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+2, 100982, 1481, 7705, 7741, '0', 5595, 0, 0, 1, 826.904541015625, 2758.647705078125, -30.5066184997558593, 4.404995918273925781, 120, 0, 0, 27954, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Sevis Brightflame (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+3, 94410, 1481, 7705, 7741, '0', 5094, 0, 0, 1, 824.59722900390625, 2758.497314453125, -30.352325439453125, 4.542752742767333984, 120, 0, 0, 31060, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Allari the Souleater (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 105316, 1481, 7705, 7741, '0', 5094, 0, 0, 0, 822.51214599609375, 2744.765625, -30.9782161712646484, 1.432027459144592285, 120, 0, 0, 24850, 19005, 0, NULL, NULL, NULL, NULL, 51261), -- Questioner Arev'naal (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+5, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 822.94097900390625, 2727.411376953125, -30.8847217559814453, 1.687772512435913085, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+6, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 837.70489501953125, 2770.400146484375, -30.6522693634033203, 3.850893735885620117, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+7, 97592, 1481, 7705, 7741, '0', 0, 0, 0, 1, 827.99652099609375, 2763.361083984375, -30.6998558044433593, 1.511899471282958984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Felguard Sentry (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+8, 97592, 1481, 7705, 7741, '0', 0, 0, 0, 1, 818.78643798828125, 2776.356689453125, -30.9636096954345703, 0.002212021499872207, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Felguard Sentry (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+9, 97142, 1481, 7705, 7741, '0', 0, 0, 0, 0, 797.72222900390625, 2790.532958984375, -33.0243721008300781, 0, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Fel Spreader (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+10, 93112, 1481, 7705, 7741, '0', 0, 0, 0, 1, 796.00347900390625, 2779.09716796875, -31.921335220336914, 5.917963504791259765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Felguard Sentry (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+11, 93115, 1481, 7705, 7741, '0', 0, 0, 0, 0, 850.43402099609375, 2801.387939453125, -22.4901905059814453, 4.18784952163696289, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+12, 93115, 1481, 7705, 7741, '0', 0, 0, 0, 0, 797.217041015625, 2780.400146484375, -31.5374717712402343, 5.818414211273193359, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+13, 93115, 1481, 7705, 7741, '0', 0, 0, 0, 0, 851.23089599609375, 2798.546142578125, -22.1982803344726562, 4.154862403869628906, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51261), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+14, 24021, 1481, 7705, 7741, '0', 5094, 0, 0, 0, 825.8819580078125, 2755.15283203125, -27.5832767486572265, 1.882045865058898925, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51261); -- ELM General Purpose Bunny (scale x0.01) (Area: Despair Ridge - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sevis Brightflame
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Sevis Brightflame
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 376, 0, 0, 0, 3, ''), -- Allari the Souleater
(@CGUID+4, 0, 0, 0, 3, 0, 1, 0, 0, 6761, 0, 0, 0, ''), -- Questioner Arev'naal
(@CGUID+7, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Felguard Sentry - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+8, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- Felguard Sentry - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 241751, 1481, 7705, 7741, '0', 0, 0, 1027.810791015625, 2846.22998046875, 5.979487895965576171, 1.590266227722167968, 0, 0, 0.713956832885742187, 0.700189709663391113, 120, 255, 1, 51261), -- Legion Gateway Activator (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@OGUID+1, 253931, 1481, 7705, 7741, '0', 5094, 0, 825.8819580078125, 2755.15283203125, -29.257577896118164, 5.065802574157714843, 0, 0, -0.57179450988769531, 0.820396840572357177, 120, 255, 1, 51261); -- Creature_Demoncrystal_03_fel (Area: Despair Ridge - Difficulty: 0) CreateObject1

-- Serverside AT
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID+0 AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 38, 38, 25, 38, 38, 25, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN AND `IsServerSide` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES
(@ATIDSPAWN, @ATID, 1, 1481, 831.3651, 2790.655, -30.7197, 4.595217, 0, 5094, 0, 1, 38, 38, 25, 38, 38, 25, 0, 0, 'at_enter_the_illidari_ashtongue_allari_killcredit', 'Mardum - Trigger KillCredit for Quest "Enter the Illidari: Ashtongue"');

-- update Template
UPDATE `creature_template` SET `ScriptName` = 'npc_kayn_sunfury_ashtongue_intro' WHERE `entry` = 98229;
UPDATE `creature_template` SET `ScriptName` = 'npc_sevis_brightflame_ashtongue_gateway_private' WHERE `entry` = 99916;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=101518; -- Felsaber
UPDATE `creature_template` SET `npcflag`=281474976710658 WHERE `entry`=100982; -- Sevis Brightflame
UPDATE `creature_template` SET `npcflag`=281474976710659 WHERE `entry`=94410; -- Allari the Souleater

UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51261 WHERE `entry`=244441; -- Legion Communicator
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51261 WHERE `entry` IN (242990, 244916); -- Jailer Cage
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51261 WHERE `entry`=241756; -- Legion Gateway Activator
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51261 WHERE `entry`=244440; -- Legion Communicator
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51261 WHERE `entry`=242989; -- Jailer Cage

-- Creature Movement data
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 105316;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(105316, 0, 0, 1, 1, 0, 0, NULL);

-- Creature text
DELETE FROM `creature_text` WHERE `CreatureID` IN (98229, 98354, 99916);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98229, 0, 0, 'Activate all three gateways and summon in the rest of our forces.', 12, 0, 100, 0, 0, 55244, 1, 96304, 0, 'Kayn Sunfury to Player'),
(98229, 1, 0, 'I\'ll cut a hole through the demons and meet you in the volcano.', 12, 0, 100, 0, 0, 55245, 1, 100023, 0, 'Kayn Sunfury to Player'),
(98354, 0, 0, 'I will join you. Let\'s kill some more demons.', 12, 0, 100, 0, 0, 55285, 1, 96404, 0, 'Kor\'vas Bloodthorn to Player'),
(99916, 0, 0, 'Plenty of souls were sacrificed here. The activator is powered.', 12, 0, 100, 273, 0, 55344, 0, 101656, 0, 'Sevis Brightflame to Player'),
(99916, 1, 0, 'I will move ahead and find Allari.', 12, 0, 100, 0, 0, 55346, 1, 101657, 0, 'Sevis Brightflame to Player');

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 101518;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(101518, 200255, 3, 0);

-- ScriptName
DELETE FROM `spell_script_names` WHERE `spell_id` = 200255;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(200255, 'spell_accepting_felsaber_gift');

-- Update Tracker Channel serverside Spell
UPDATE `serverside_spell` SET `AttributesEx2` = `AttributesEx2` | 0x00000004 WHERE `Id` = 175799;

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` IN (184561, 200254);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(184561, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Enter the Illidari: Ashtongue - Legion Gateway Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(200254, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Enter the Illidari: Ashtongue - See Felsaber Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (184561, 200254) AND `EffectIndex` IN (0, 1);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(184561, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88872, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184561, 1, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 189261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(200254, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101534, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1053;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1053, 20, 1451, 0);

UPDATE `scene_template` SET `ScriptName` = 'scene_enter_the_illidari_ashtongue' WHERE `SceneId` = 1053;

-- objective completion effect
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (280768, 281156, 281030);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(280768, NULL, NULL, NULL, 1, 0),
(281156, NULL, NULL, NULL, 1, 0),
(281030, NULL, NULL, NULL, 1, 0);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=40378;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(40378, 0, 0, 0, 0, 0, 0, 0, 0, 'I saw them run by. Not the most impressive of our troops, but the Ashtongue have proven effective in the past.', 51261); -- Enter the Illidari: Ashtongue

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` IN (5463, 5658, 5595, 5094) AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5463, 'Sevis Brightflame at Ashtongue Gateway'),
(7705, 5658, 'Felsaber at Ashtongue Gateway'),
(7705, 5595, 'Sevis Brightflame at Dispair Ridge Cave'),
(7705, 5094, 'Allari the Souleater at Dispair Ridge Cave');

-- Sevis Brightflame (Gateway)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5463 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5463, 0, 0, 0, 47, 0, 40378, 8, 0, 0, 'Apply Phase 5463 if Quest 40378 is in progress'),
(26, 5463, 0, 0, 0, 48, 0, 280768, 0, 1, 1, 'Apply Phase 5463 if Questobjective 280768 (Ashtongue forces) is not rewarded');

-- Felsaber
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5658 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5658, 0, 0, 0, 47, 0, 40378, 8, 0, 0, 'Apply Phase 5658 if Quest 40378 is in progress'),
(26, 5658, 0, 0, 0, 48, 0, 281158, 0, 1, 0, 'Apply Phase 5658 if Questobjective 281158 (Hidden Felsaber Objective) is rewarded'),
(26, 5658, 0, 0, 0, 48, 0, 281156, 0, 1, 1, 'Apply Phase 5658 if Questobjective 281156 (Accept Illidans Gift) is not rewarded');

-- Sevis Brightflame (cave)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5595 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5595, 0, 0, 0, 47, 0, 40378, 2|64, 0, 0, 'Apply Phase 5595 if Quest 40378 is complete | rewarded');

-- Allari Souleater (cave)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5094 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5094, 0, 0, 0, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded');

-- Kayn Path
SET @ENTRY := 98229;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 980.7327, 2950.867, -9.954125, NULL, 0, 1),
(@PATH, 1, 961.9722, 2939.735, -13.23198, NULL, 0, 1),
(@PATH, 2, 951.1823, 2930.971, -14.02309, NULL, 0, 1),
(@PATH, 3, 921.0833, 2908.53, -19.44963, NULL, 0, 1),
(@PATH, 4, 915.7257, 2905.109, -20.14307, NULL, 0, 1);

-- Path Korvas
SET @ENTRY := 98354;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1005.794, 2955.427, -10.47164, NULL, 0, 1),
(@PATH, 1, 1003.294, 2941.927, -10.22164, NULL, 0, 1),
(@PATH, 2, 992.5443, 2927.677, -8.721643, NULL, 0, 1),
(@PATH, 3, 973.2943, 2916.677, -8.971643, NULL, 0, 1),
(@PATH, 4, 951.5443, 2912.177, -12.22164, NULL, 0, 1),
(@PATH, 5, 921.7943, 2906.927, -18.97164, NULL, 0, 1),
(@PATH, 6, 915.9184, 2904.354, -20.05361, NULL, 0, 1);

-- Path Sevis
SET @ENTRY := 99916;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1004.658, 2859.47, 4.856629, NULL, 0, 1),
(@PATH, 1, 993.2535, 2864.65, 4.184957, NULL, 0, 1),
(@PATH, 2, 980.0729, 2876.393, 0.9802456, NULL, 0, 1),
(@PATH, 3, 966.257, 2896.878, -6.551769, NULL, 0, 1),
(@PATH, 4, 953.1111, 2902.888, -10.93261, NULL, 0, 1),
(@PATH, 5, 938.8733, 2902.069, -15.50097, NULL, 0, 1),
(@PATH, 6, 934.0608, 2901.299, -16.59744, NULL, 0, 1);
