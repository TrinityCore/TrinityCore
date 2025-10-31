SET @CGUID := 777777777;
SET @ATPROP := 55555;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 164255, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2036.204833984375, -3596.0087890625, 3263.586669921875, 5.108221054077148437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Globgrog (Area: Plaguefall - Difficulty: 0) CreateObject1 (Auras: 324366 - Living Slime Flesh, 324304 - Slime Energy Bar, 346098 - Festive Globgrog, 324284 - Slime Infused Bones)
(@CGUID+1, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2065.329833984375, -3489.607666015625, 3259.728759765625, 4.418760299682617187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: 0) CreateObject1
(@CGUID+2, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2001.6632080078125, -3496.3369140625, 3259.882080078125, 5.323053836822509765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: 0) CreateObject1
(@CGUID+3, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 1986.467041015625, -3535.326416015625, 3259.689208984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+4, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 1986.3507080078125, -3514.569580078125, 3259.451904296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+5, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2080.114501953125, -3501.203125, 3259.46337890625, 4.344142436981201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+6, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 1986.295166015625, -3556.33154296875, 3259.406494140625, 0.417013734579086303, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+7, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2088.338623046875, -3521.80029296875, 3259.458984375, 3.311464786529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+8, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2054.375, -3583.257080078125, 3259.46630859375, 1.897548079490661621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+9, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2089.20654296875, -3550.02783203125, 3259.4208984375, 2.60940098762512207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+10, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2075.007080078125, -3575.5869140625, 3259.41162109375, 2.214966058731079101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+11, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2028.78125, -3582.810791015625, 3259.513671875, 1.888534903526306152, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1
(@CGUID+12, 166480, 2289, 13228, 13228, '1,2,8,23', '0', 0, 0, 0, 2001.2569580078125, -3580.640625, 3259.760498046875, 1.018098831176757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Living Slime Stalker (Area: Plaguefall - Difficulty: Mythic) CreateObject1

UPDATE `creature_template` SET `unit_flags3`=0x41000001 WHERE `entry`=166480; -- Living Slime Stalker
UPDATE `creature_template` SET `ScriptName`='boss_globgrog' WHERE `entry`=164255; -- Globgrog
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x280000, `ScriptName`='boss_globgrog_slimy_creature' WHERE `entry`=164362; -- Slimy Morsel
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x280001, `ScriptName`='boss_globgrog_slimy_creature' WHERE `entry`=171887; -- Slimy Smorgasbord

DELETE FROM `creature_template_addon` WHERE `entry` IN (171887,164362,164255);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(171887, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 171887 (Slimy Smorgasbord) - Mod Scale 105-110%
(164362, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 164362 (Slimy Morsel) - Mod Scale 105-110%
(164255, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '324366 324304 346098'); -- 164255 (Globgrog) - Living Slime Flesh, Slime Energy Bar, Festive Globgrog

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_globgrog_victory_start_convo', 'spell_globgrog_beckon_slime_start_convo', 'spell_globgrog_plaguestomp_start_convo', 'spell_globgrog_plaguestomp_damage', 'spell_globgrog_slime_wave_start_convo','spell_globgrog_slime_wave_selector', 'spell_globgrog_beckon_slime_selector', 'spell_globgrog_beckon_slime_mythic_selector');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(332865, 'spell_globgrog_slime_wave_selector'),
(333420, 'spell_globgrog_slime_wave_start_convo'),
(324527, 'spell_globgrog_plaguestomp_damage'),
(333424, 'spell_globgrog_plaguestomp_start_convo'),
(333417, 'spell_globgrog_beckon_slime_start_convo'),
(333428, 'spell_globgrog_victory_start_convo'),
(326273, 'spell_globgrog_beckon_slime_mythic_selector'),
(324459, 'spell_globgrog_beckon_slime_selector');

-- Conversations
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (15333,15332,15336,15334,15337,15330,15335,15338,15339,15340));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`)  VALUES
(15330, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15332, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15333, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15334, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15335, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15336, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15337, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15338, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15339, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441
(15340, 74599, @CGUID+0, 0, 0, 0, 0, 0, 63305); -- Full: 0x202FD51E20A067C0005A3B00005AFAC9 Creature/0 R3061/S23099 Map: 2289 (Plaguefall) Entry: 164255 (Globgrog) Low: 5962441

DELETE FROM `conversation_line_template` WHERE `Id` IN (38462, 38461, 38465, 38463, 38466, 38457, 38464, 38467, 38468, 38469);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(38457, 0, 0, 0, 1, 63305),
(38461, 0, 0, 0, 1, 63305),
(38462, 0, 0, 0, 1, 63305),
(38463, 0, 0, 0, 1, 63305),
(38464, 0, 0, 0, 1, 63305),
(38465, 0, 0, 0, 1, 63305),
(38466, 0, 0, 0, 1, 63305),
(38467, 0, 0, 0, 1, 63305),
(38468, 0, 0, 0, 1, 63305),
(38469, 0, 0, 0, 1, 63305);

DELETE FROM `conversation_template` WHERE `Id` IN (15334, 15336, 15335, 15338, 15330, 15337, 15332, 15333, 15339, 15340);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(15330, 38457, 0, 63305),
(15332, 38461, 0, 63305),
(15333, 38462, 0, 63305),
(15334, 38463, 0, 63305),
(15335, 38464, 0, 63305),
(15336, 38465, 0, 63305),
(15337, 38466, 0, 63305),
(15338, 38467, 0, 63305),
(15339, 38468, 0, 63305),
(15340, 38469, 0, 63305);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (171887,164362));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(171887, 23, 8, 2, 1, 193364, 0x200048, 128, 0), -- Slimy Smorgasbord
(164362, 23, 8, 0.524999976158142089, 1, 184769, 0x200048, 128, 0); -- Slimy Morsel

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=166480 AND `DifficultyID`=0); -- 166480 (Living Slime Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=749, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=164255 AND `DifficultyID`=0); -- 164255 (Globgrog) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=749, `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=193364, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=171887 AND `DifficultyID`=23); -- Slimy Smorgasbord
UPDATE `creature_template_difficulty` SET `ContentTuningID`=749, `HealthScalingExpansion`=8, `HealthModifier`=0.524999976158142089, `CreatureDifficultyID`=184769, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=164362 AND `DifficultyID`=23); -- Slimy Morsel

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 164255;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(164255, 0, 0, 'Intruders! You will be devoured whole!', 14, 0, 100, 0, 0, 152566, 191813, 0, 'Globgrog'),
(164255, 1, 0, 'The... hunger... ends...', 14, 0, 100, 0, 0, 152556, 191819, 0, 'Globgrog');

-- Instance
DELETE FROM `instance_template` WHERE `map`=2289;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2289, 0, 'instance_plaguefall');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN (324459, 326273, 326248);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 326248, 0, 0, 51, 0, 5, 164255, 0, '', 0, 0, 0, '', 'Spell \'Beckon Slime\' can only hit \'Globgrog\''),
(13, 1, 324459, 0, 0, 51, 0, 5, 166480, 0, '', 0, 0, 0, '', 'Spell \'Beckon Slime\' can only hit \'Living Slime Stalker\''),
(13, 1, 326273, 0, 0, 51, 0, 5, 166480, 0, '', 0, 0, 0, '', 'Spell \'Beckon Slime\' can only hit \'Living Slime Stalker\'');

-- Areatrigger
SET @ATPROP := 55555;

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (19879));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(19879, 0, @ATPROP, 1, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 'at_globgrog_living_slime_flesh', 63305);

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=1 AND `Id` IN (@ATPROP));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(@ATPROP, 1, 63305);
