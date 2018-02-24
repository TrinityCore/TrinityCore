SET @CGUID := 21010578;
SET @OGUID := 21002115;

DELETE FROM instance_template WHERE `map`= 1571;
INSERT INTO instance_template VALUES
(1571, 1220, "instance_court_of_stars", 0, 1);

DELETE FROM `areatrigger_template` WHERE `Id` IN (12579, 11386, 11382);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(12579, 0, 4, 3, 3, 0, 0, 0, 0, 25996),
(11386, 0, 0, 2, 2, 0, 0, 0, 0, 25996),
(11382, 0, 0, 3, 3, 0, 0, 0, 0, 25996);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10470;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10470;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12929;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12929;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10470;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10133;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11209;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11203;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11209;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10470;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11209;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11209;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11209;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11209;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9110;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=8425 AND `AreaTriggerId`=12579) OR (`SpellMiscId`=6881 AND `AreaTriggerId`=11386) OR (`SpellMiscId`=6878 AND `AreaTriggerId`=11382) OR (`SpellMiscId`=6622 AND `AreaTriggerId`=11209);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(8425, 12579, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 224330
(6881, 11386, 0, 0, 0, 0, 0, 0, 120000, 25996), -- SpellId : 207887
(6878, 11382, 0, 0, 0, 0, 0, 0, 8000, 25996), -- SpellId : 211387
(6622, 11209, 0, 0, 0, 0, 0, 0, 8000, 25996); -- SpellId : 209495

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2051, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2564, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2564, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6452, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6615 AND `AreaTriggerId`=11203); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2564, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1429, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1429, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=2292 AND `ConversationActorId`=52792 AND `Idx`=0) OR (`ConversationId`=2405 AND `ConversationActorId`=52792 AND `Idx`=0) OR (`ConversationId`=2291 AND `ConversationActorId`=52792 AND `Idx`=0) OR (`ConversationId`=2294 AND `ConversationActorId`=52792 AND `Idx`=0) OR (`ConversationId`=2402 AND `ConversationActorId`=52792 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(2292, 52792, 0, 25996),
(2405, 52792, 0, 25996),
(2291, 52792, 0, 25996),
(2294, 52792, 0, 25996),
(2402, 52792, 0, 25996);


DELETE FROM `conversation_actor_template` WHERE `Id`=52792;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(52792, 105734, 70583, 25996);


DELETE FROM `conversation_line_template` WHERE `Id` IN (4840, 4839, 5103, 4838, 4837, 4842, 4841, 5096);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(4840, 4451, 984, 0, 8252, 25996),
(4839, 0, 984, 0, 0, 25996),
(5103, 0, 984, 0, 0, 25996),
(4838, 10321, 984, 0, 8252, 25996),
(4837, 0, 984, 0, 0, 25996),
(4842, 8766, 984, 0, 0, 25996),
(4841, 0, 984, 0, 0, 25996),
(5096, 0, 984, 0, 0, 25996);


DELETE FROM `conversation_template` WHERE `Id` IN (2405, 2402, 2292, 2291, 2294);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(2405, 5103, 10138, 25996),
(2402, 5096, 7084, 25996),
(2292, 4839, 12295, 25996),
(2291, 4837, 17629, 25996),
(2294, 4841, 14975, 25996);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (253046 /*Nightborne Goods*/, 253047 /*Nightborne Goods*/, 252966 /*Nightborne Bazaar*/, 252967 /*Nightborne Goods*/, 252968 /*Nightborne Goods*/, 246805 /*Fel Fire*/, 251848 /*Skyward Terrace*/, 251849 /*Waypoint Door*/, 251846 /*House Door*/, 251847 /*Manor Door*/, 253922 /*Apprentice's Door*/, 249386 /*Arcane Barrier*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(253046, 1375, 8192), -- Nightborne Goods
(253047, 1375, 8192), -- Nightborne Goods
(252966, 1375, 8192), -- Nightborne Bazaar
(252967, 1375, 8192), -- Nightborne Goods
(252968, 1375, 8192), -- Nightborne Goods
(246805, 0, 8192), -- Fel Fire
(251848, 0, 34), -- Skyward Terrace
(251849, 1375, 32), -- Waypoint Door
(251846, 1375, 32), -- House Door
(251847, 1375, 32), -- Manor Door
(253922, 1375, 32), -- Apprentice's Door
(249386, 0, 48); -- Arcane Barrier

UPDATE `gameobject_template_addon` SET `faction`=190 WHERE `entry`=233778; -- Collision PC Size

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+18 AND @CGUID+517;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+18, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 990.1758, 3689.306, -19.06444, 5.805018, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+19, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 936.2717, 3807.607, -40.48835, 4.678756, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+20, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 969.2342, 3782.981, -35.89544, 6.116921, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+21, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1002.726, 3746.206, -48.11553, 1.928052, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+22, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 997.255, 3739.736, -24.99984, 5.84945, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+23, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 956.8621, 3774.771, -23.79767, 1.402938, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+24, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 994.6252, 3706.325, -41.92222, 4.324154, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+25, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1029.732, 3778.485, -7.230434, 0.3393081, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+26, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 971.7328, 3724.895, -38.86706, 0.8438918, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+27, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 949.6791, 3717.518, -14.51327, 6.103909, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+28, 111367, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1047.087, 3661.334, 2.699288, 0.4836567, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+29, 111367, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1052.474, 3665.41, 2.699287, 3.931749, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+30, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1031.759, 3733.922, -20.7127, 4.052128, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+31, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1023.93, 3656.353, -13.77094, 5.418612, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+32, 105729, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1014.974, 3782.855, 2.937944, 4.570401, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Signal Lantern (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209519 - Lanterne)
(@CGUID+33, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 929.4368, 3810.573, -27.23808, 5.228023, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+34, 111372, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1153.076, 3701.83, 2.704654, 4.916741, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+35, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1005.049, 3666.003, -32.16203, 1.921569, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+36, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1002.581, 3773.543, -39.03415, 0.1735075, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+37, 111367, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1150.925, 3696.963, 2.48702, 0.3733368, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+38, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1006.35, 3632.121, -14.44929, 1.685924, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
-- (@CGUID+39, 104400, UNKNOWN, 8079, 8079, 8388868, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Resonant Stalker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+40, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1012.873, 3629.302, -32.62171, 0.7597989, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+41, 104215, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1297.152, 3551.358, 20.20659, 1.531595, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Patrol Captain Gerdo (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 227147 - Zone sécurisée, 210143 - Commandement)
(@CGUID+42, 107564, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1057.432, 3457.683, 19.34439, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Conversation Stalker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+43, 111372, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1039.17, 3623.823, 0.826004, 1.677313, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%) (possible waypoints or random movement)
(@CGUID+44, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1080.925, 3614.778, 35.6066, 3.202829, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+45, 111367, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1043.967, 3596.993, 0.7779854, 2.405574, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+46, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1082.783, 3613.29, 35.6066, 6.092181, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+47, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1084.219, 3616.719, 35.6066, 5.984891, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+48, 111372, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1039.998, 3601.969, 0.7704052, 5.252469, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+49, 111367, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1039.571, 3596.664, 0.7885643, 0.7090645, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+50, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1081.814, 3616.608, 35.6066, 6.110427, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+51, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 965.2432, 3593.077, -15.21922, 4.609523, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+52, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1087.882, 3616.694, 35.6066, 0.7822736, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+53, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1086.349, 3613.964, 35.6066, 1.155313, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+54, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 997.5007, 3586.032, -29.84748, 1.596964, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+55, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1083.939, 3614.463, 35.6066, 0.8229488, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+56, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 907.4788, 3603.116, -13.50309, 0.3932282, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+57, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1084.891, 3612.899, 35.6066, 5.779191, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+58, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1088.715, 3612.539, 35.6066, 1.727306, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+59, 107141, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1166.326, 3409.537, 0.7272969, 0.9914054, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
-- (@CGUID+60, 107151, UNKNOWN, 8079, 8079, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+61, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1014.521, 3562.257, -12.13881, 5.899037, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+62, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1058.722, 3548.572, 3.961897, 2.989885, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+63, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1131.324, 3574.005, 24.36222, 5.95092, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+64, 104696, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1054.823, 3551.637, 3.961915, 6.224386, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+65, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1061.656, 3549.95, 3.96189, 3.054194, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+66, 105705, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1060.677, 3546.062, 3.961892, 2.9651, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bound Energy (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+67, 104696, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1056.099, 3546.332, 3.961903, 0.5214469, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+68, 105705, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1059.035, 3553.201, 3.961902, 3.071385, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bound Energy (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+69, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1003.202, 3544.833, -19.38379, 1.248581, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+70, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 967.0549, 3550.176, -23.72893, 5.796248, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+71, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 931.0418, 3571.782, -42.38581, 4.290476, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%)
(@CGUID+72, 104247, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1128.688, 3571.684, 25.23926, 2.839707, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques) (possible waypoints or random movement)
(@CGUID+73, 104247, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1138.991, 3564.562, 19.92156, 4.349345, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques)
(@CGUID+74, 105699, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1127.506, 3569.009, 24.85312, 2.795861, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Saber (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+75, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1185.167, 3591.165, 20.66722, 0.8820368, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+76, 104696, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1043.236, 3524.267, 3.961913, 4.302119, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+77, 105699, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1103.795, 3535.861, 20.89313, 2.700201, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+78, 104247, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1061.92, 3523.637, 8.403567, 2.594108, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques)
(@CGUID+79, 104270, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1169.851, 3581.89, 19.84354, 6.242165, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Guardian Construct (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+80, 105704, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1135.882, 3559.91, 19.92155, 0.6065648, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Manifestation (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+81, 104251, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1079.213, 3511.944, 14.06784, 2.502307, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Sentry (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 227148 - Tache lumineuse) (possible waypoints or random movement)
(@CGUID+82, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1141.762, 3550.474, 19.96322, 0.6484391, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+83, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1169.229, 3550.701, 19.92155, 0.2971129, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+84, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1164.694, 3553.345, 19.92155, 0.2971129, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+85, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1144.473, 3547.463, 19.96322, 5.504012, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+86, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 983.6732, 3497.301, -20.41345, 3.71468, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+87, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1139.122, 3548.573, 19.96322, 1.164106, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+88, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1170.762, 3553.431, 19.92155, 0.2971129, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+89, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1137.264, 3547.353, 19.96322, 2.359344, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+90, 104270, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1192.988, 3601.035, 21.00896, 3.295732, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+91, 104251, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1177.521, 3567.007, 19.84354, 0.1511776, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Sentry (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 227148 - Tache lumineuse) (possible waypoints or random movement)
(@CGUID+92, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1166.819, 3551.2, 19.92155, 0.2971129, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+93, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1143.698, 3545.043, 19.96322, 0.63065, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+94, 104270, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1118.16, 3512.192, 25.71492, 4.149871, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+95, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1053.448, 3516.593, 6.22297, 3.054194, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+96, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1167.771, 3549.636, 19.92155, 2.255113, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+97, 104251, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1192.444, 3583.96, 20.97497, 4.640855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Sentry (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 227148 - Tache lumineuse)
(@CGUID+98, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1171.595, 3549.276, 19.92155, 0.2971129, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+99, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1138.429, 3546.88, 19.96322, 3.663248, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+100, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1167.099, 3553.456, 19.92155, 4.485434, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+101, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1102.934, 3530.955, 20.89313, 2.700201, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+102, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1163.806, 3551.515, 19.92155, 0.2971129, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+103, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1137.527, 3546.742, 19.96322, 5.976995, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+104, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1137.398, 3542.642, 19.96322, 5.230762, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (possible waypoints or random movement)
(@CGUID+105, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1041.061, 3519.006, 3.961914, 1.135476, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+106, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1165.663, 3550.027, 19.92155, 0.2971129, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+107, 104217, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1088.278, 3313.549, 25.05948, 3.985519, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Talixae Flamewreath (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209723 - Lien de flamme, 209435 - Mains de flammes, 42459 - Ambidextrie)
(@CGUID+108, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 919.6922, 3525.643, -19.93815, 5.052767, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+109, 111575, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 935.0699, 3515.337, -47.98806, 2.870101, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Overgrown Eel (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+110, 104245, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1174.748, 3557.615, 19.84368, 5.43253, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Beacon (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde)
(@CGUID+111, 104275, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1088.879, 3306.012, 25.05701, 1.431016, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Imacu'tya (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209712 - Lien de ruse)
(@CGUID+112, 104274, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1083.045, 3307.558, 25.05324, 0.7791104, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Baalgar the Watchful (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 209717 - Lien de cruauté)
(@CGUID+113, 104273, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1081.217, 3313.443, 25.0578, 0.2321424, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Jazshariu (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 207819 - Lien de force)
(@CGUID+114, 104270, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1157.012, 3527.708, 20.89313, 2.846056, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+115, 111572, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 948.9114, 3496.518, -27.76854, 5.328534, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Engorged Manafeeder (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+116, 111563, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1042.595, 3463.473, 3.898811, 2.654635, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+117, 113617, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 966.4844, 3470.706, 1.984411, 4.722818, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 188236 - , 86603 - Camouflage)
(@CGUID+118, 105699, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1187.599, 3541.95, 21.96456, 3.285552, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+119, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1181.792, 3541.305, 21.57191, 0.06439843, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+120, 104251, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1102.892, 3466.229, 19.96137, 4.830514, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Sentry (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+121, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1099.913, 3465.876, 19.87888, 5.110071, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+122, 104245, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1121.674, 3479.855, 19.97371, 3.439043, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Beacon (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde)
(@CGUID+123, 105703, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1105.871, 3466.583, 19.96137, 5.099724, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+124, 105699, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1190.271, 3538.484, 21.96456, 2.725589, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+125, 104694, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1050.135, 3452.6, 23.0275, 0.9062268, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+126, 104246, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1120.795, 3471.068, 19.92156, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+127, 105699, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1124.087, 3473.009, 19.92156, 4.147412, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+128, 104270, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1102.439, 3451.765, 19.71984, 1.162247, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+129, 105699, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1124.76, 3469.189, 19.92156, 2.501322, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: )
(@CGUID+130, 107324, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1073.646, 3440.406, 20.19814, 4.521907, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 220629 - Etraeus, l’augure stellaire)
(@CGUID+131, 107486, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 956.5764, 3239.398, 52.25293, 5.404879, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chatty Rumormonger (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+132, 107324, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1070.899, 3439.109, 20.196, 6.261688, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 220629 - Etraeus, l’augure stellaire)
(@CGUID+133, 104270, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1107.047, 3450.97, 19.71984, 1.456243, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+134, 107486, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 906.1893, 3250.204, 12.94779, 2.113657, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chatty Rumormonger (Area: Cour des Étoiles - Difficulty: Héroïque)
(@CGUID+135, 107324, 1571, 8079, 8079, 8388868, '0', 0, 0, 0, 1073.514, 3437.186, 20.19776, 1.675012, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Cour des Étoiles - Difficulty: Héroïque) (Auras: 220629 - Etraeus, l’augure stellaire)
(@CGUID+136, 111575, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 926.0098, 3449.009, -26.71031, 2.938052, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Overgrown Eel (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 151051 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+137, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1046.405, 3421.584, 45.88892, 5.402945, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+138, 107486, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1000.832, 3220.26, 25.26938, 2.424398, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chatty Rumormonger (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+139, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1044.375, 3419.91, 45.88892, 5.593165, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+140, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1040.083, 3415.098, 45.88892, 1.168971, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+141, 111367, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 966.0123, 3406.471, 1.068092, 3.584157, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%) (possible waypoints or random movement)
(@CGUID+142, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 918.4514, 3424.979, 1.984886, 0.6204026, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+143, 111366, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 959.658, 3413.818, 1.163244, 2.224968, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+144, 104246, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1141.674, 3447.544, 21.19291, 0.01156717, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 29266 - Feindre la mort permanent)
(@CGUID+145, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 947.3386, 3199.683, 22.65857, 1.400843, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213089 -)
(@CGUID+146, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 950.4063, 3203.106, 22.6587, 3.287702, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213095 -)
(@CGUID+147, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 903.0156, 3420.81, 1.985495, 0.7992631, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+148, 111367, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 916.3854, 3424.323, 2.19715, 0.577751, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+149, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 945.25, 3202.018, 22.65815, 0.2665899, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213101 -)
(@CGUID+150, 105699, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1147.972, 3453.023, 21.19272, 4.233991, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+151, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 947.0886, 3204.845, 22.65814, 5.062984, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213106 -)
(@CGUID+152, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 946.7621, 3409.462, 1.734598, 0.06678409, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+153, 111372, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 937.3685, 3395.759, 1.189418, 3.508359, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%) (possible waypoints or random movement)
(@CGUID+154, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1122.371, 3417.846, 19.96137, 0.4323113, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire) (possible waypoints or random movement)
(@CGUID+155, 105699, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1147.047, 3446.985, 21.51933, 2.957121, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+156, 111372, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 917.7621, 3403.688, 2.19715, 4.809374, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+157, 107442, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 966.9739, 3190.619, 24.79621, 0.7463014, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Suramar Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+158, 105715, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1048.745, 3392.439, 19.96322, 3.974277, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Inquisitor (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 211861 - Garde sinistre)
(@CGUID+159, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1059.543, 3388.401, 19.92155, 5.893472, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+160, 111366, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 921.7778, 3397.888, 2.19715, 0.1250993, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+161, 104277, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1136.085, 3427.556, 19.92156, 0.1025562, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Legion Hound (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+162, 111362, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 897.4983, 3407.387, 0.934131, 2.0514, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+163, 111366, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 955.132, 3390.983, 0.8912689, 2.61381, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+164, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 919.2882, 3396.023, 1.984887, 0.4116874, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+165, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 919.9496, 3398.91, 1.984887, 0.4653171, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+166, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 920.8594, 3402.936, 1.984887, 0.506236, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+167, 107471, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1115.472, 3421.589, 19.92156, 5.422793, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+168, 111367, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 938.9845, 3377.985, 1.280943, 0.1705632, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%) (possible waypoints or random movement)
(@CGUID+169, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 958.467, 3385.347, 1.655905, 5.280087, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 191779 -)
(@CGUID+170, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1062.672, 3387.634, 19.92155, 3.046577, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+171, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 974.4965, 3169.764, 22.65841, 4.565788, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213099 -)
(@CGUID+172, 104300, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1051.704, 3389.748, 19.96322, 3.974226, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Shadow Mistress (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+173, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 903.7621, 3380.622, 1.166505, 2.08667, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+174, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1117.913, 3419.485, 19.92156, 2.575898, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+175, 111367, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 957.3559, 3396.406, 0.9143596, 0.1578775, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+176, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 906.0903, 3417.135, 1.984887, 5.91275, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+177, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 960.9479, 3395.377, 0.8881371, 2.309258, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+178, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 901.4566, 3399.216, 1.669306, 5.417257, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+179, 107471, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 993.8521, 3366.983, 20.16562, 0.2376271, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Wealthy Elite (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire) (possible waypoints or random movement)
(@CGUID+180, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 933.9653, 3169.989, 49.65668, 2.668368, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213080 -)
(@CGUID+181, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 977.2795, 3169.001, 22.65814, 3.509423, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213108 - , 227258 - Déclencheur de zone de Garde-Vérité)
(@CGUID+182, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 968.2969, 3166.591, 22.65816, 4.804648, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213105 -)
(@CGUID+183, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 931.0018, 3169.213, 49.64631, 0.9991509, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213102 -)
(@CGUID+184, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 971.9896, 3168.02, 22.65829, 5.931212, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213104 -)
(@CGUID+185, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 929.4739, 3171.398, 49.66725, 6.063186, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213107 -)
(@CGUID+186, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 932.809, 3172.714, 49.67452, 4.08476, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213100 -)
(@CGUID+187, 104300, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1140.766, 3426.188, 19.92156, 2.383524, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Shadow Mistress (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 206888 - Canalisation de l’ombre)
(@CGUID+188, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 939.6823, 3354.684, 1.712341, 2.092706, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+189, 105715, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1035.599, 3362.002, 19.92156, 3.837875, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Inquisitor (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 211861 - Garde sinistre)
(@CGUID+190, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1109.21, 3391.56, 19.92156, 1.140831, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+191, 107471, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1110.964, 3394.267, 19.92156, 3.987726, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+192, 111366, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 942.8333, 3359.838, 1.712348, 1.54796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+193, 111372, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 934.2344, 3358.958, 1.712341, 4.31173, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+194, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 884.7552, 3376.2, 1.734589, 0.06678409, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+195, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1107.939, 3394.548, 19.92156, 5.727508, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+196, 104300, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1030.745, 3362.443, 19.92156, 4.994899, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Shadow Mistress (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+197, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 949.7257, 3359.511, 1.712341, 1.064851, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 191779 -)
(@CGUID+198, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 940.5816, 3147.038, 52.33255, 3.247925, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213097 -)
(@CGUID+199, 111372, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 907.2961, 3359.07, 1.826004, 0.3132626, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%) (possible waypoints or random movement)
(@CGUID+200, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 939.0625, 3144.713, 52.33255, 1.804818, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213103 -)
(@CGUID+201, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 936.6458, 3146.404, 52.33255, 0.2154071, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213098 -)
(@CGUID+202, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 933.1823, 3349.957, 1.712341, 1.959243, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 191779 -)
(@CGUID+203, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 882.5469, 3365.813, 1.11466, 0.06678409, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+204, 107435, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 938.4549, 3149.059, 52.33255, 4.75917, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 213096 -)
(@CGUID+205, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 997.8542, 3334.63, 41.84537, 2.575898, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+206, 111367, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 886.3055, 3358.825, 1.093652, 4.416262, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+207, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 909.2552, 3342.795, 1.76761, 0.3458424, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+208, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 913.7222, 3346.775, 1.712341, 1.465739, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+209, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 885.3386, 3353.484, 1.127669, 5.347168, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+210, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 908.4549, 3346.603, 1.712341, 0.2343837, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+211, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1065.585, 3348.323, 25.07764, 2.641969, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+212, 111372, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 906.3906, 3346.93, 1.767624, 5.414724, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Dockworker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 123168 - Échelle : 115-120%)
(@CGUID+213, 107486, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 976.7795, 3130.047, 52.33256, 2.956543, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chatty Rumormonger (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+214, 107486, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1017.957, 3130.875, 14.86776, 1.350157, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chatty Rumormonger (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+215, 107471, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 995.4132, 3336.733, 41.83689, 5.422793, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+216, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1062.968, 3338.866, 25.02276, 2.363786, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+217, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1062.968, 3338.866, 25.02276, 2.363786, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+218, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 870.7153, 3347.339, 0.4100561, 1.213256, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+219, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1062.968, 3338.866, 25.02276, 2.363786, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+220, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1073.195, 3346.298, 25.0066, 3.170941, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+221, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1062.968, 3338.866, 25.02276, 2.363786, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+222, 107471, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1175.946, 3461.244, 1.886977, 5.422793, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+223, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1075.523, 3348.838, 24.86049, 3.06884, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+224, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1178.387, 3459.141, 1.886977, 2.575898, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+225, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1062.968, 3338.866, 25.02276, 2.363786, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+226, 107151, UNKNOWN, 8079, 8181, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+227, 105715, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1155.321, 3398.849, 28.68397, 5.792928, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Inquisitor (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 211861 - Garde sinistre)
(@CGUID+228, 104277, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1082.994, 3336.822, 24.96571, 6.252253, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Legion Hound (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+229, 111362, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 873.2587, 3339.074, 0.7454796, 1.878872, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+230, 108740, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 959.8472, 3310.666, 41.6928, 0.4130968, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Velimar (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+231, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 892.9809, 3331.016, 1.235061, 1.227237, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+232, 104270, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1080.004, 3332.019, 25.00659, 0.01424343, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Guardian Construct (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+233, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 894.1111, 3327.519, 1.103038, 1.817663, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+234, 111365, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 873.7847, 3338.166, 1.149951, 5.555798, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+235, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 890.7952, 3328.713, 1.146821, 0.06678409, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+236, 104277, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1152.461, 3393.575, 28.65721, 5.792791, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Legion Hound (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+237, 105715, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1093.243, 3327.109, 24.99921, 5.726388, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Inquisitor (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 211861 - Garde sinistre)
-- (@CGUID+238, 105765, UNKNOWN, 8079, 8181, 8388868, '0', 0, 0, 0, 0, 0, -0.02361075, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Gale Stalker (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+239, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 903.1285, 3273.383, 12.94779, 2.025771, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+240, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 906.4319, 3263.978, 12.89009, 0.3788039, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+241, 104270, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1175.608, 3383.119, 22.52444, 5.743917, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Guardian Construct (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+242, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1010.872, 3250.634, 25.34271, 5.577305, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+243, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1216.602, 3479.504, 28.24154, 0.06436434, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+244, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1219.318, 3475.812, 28.24154, 2.293932, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+245, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1206.332, 3438.841, 60.5731, 2.501322, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+246, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1219.252, 3481.829, 28.24153, 4.279144, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+247, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1206.03, 3435.598, 60.57378, 1.081137, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+248, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1209.304, 3440.714, 60.5731, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+249, 104277, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1188.743, 3361.762, 20.20395, 6.028511, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Legion Hound (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1204.002, 3436.784, 60.57338, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+251, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1208.731, 3434.24, 60.57394, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+252, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1203.946, 3439.994, 60.57309, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+253, 104246, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1205.66, 3442.661, 60.5731, 4.147412, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+254, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1201.512, 3385.02, 20.08637, 0.5122728, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire) (possible waypoints or random movement)
(@CGUID+255, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1208.309, 3442.685, 41.66802, 3.110796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+256, 105703, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1209.571, 3436.906, 60.57342, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+257, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1225.273, 3434.273, 23.48059, 2.935922, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+258, 104300, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1193.556, 3360.981, 20.20395, 3.170396, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Shadow Mistress (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 206888 - Canalisation de l’ombre)
(@CGUID+259, 104251, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1195.523, 3567.19, 20.40658, 2.936867, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Sentry (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 227148 - Tache lumineuse) (possible waypoints or random movement)
(@CGUID+260, 104246, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1196.055, 3570.143, 20.40659, 2.936702, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+261, 105699, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1198.673, 3571.532, 20.8933, 3.097108, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+262, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1223.153, 3389.286, 20.08359, 1.504488, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+263, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1220.149, 3394.22, 20.08359, 5.806706, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+264, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1123.963, 3292.798, 25.04175, 2.005856, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+265, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1145.693, 3302.339, 23.8093, 0.9877318, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+266, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1147.835, 3304.74, 23.87929, 3.834627, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+267, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1226.156, 3395.978, 20.08359, 4.029421, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+268, 105715, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1223.29, 3392.599, 20.08359, 3.327443, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Inquisitor (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 211861 - Garde sinistre)
(@CGUID+269, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1124.558, 3291.35, 24.97413, 1.393245, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+270, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1124.558, 3291.35, 24.97413, 1.393245, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+271, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1124.558, 3291.35, 24.97413, 1.393245, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+272, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1124.558, 3291.35, 24.97413, 1.393245, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+273, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1120.515, 3287.268, 25.00659, 1.449678, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+274, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1121.638, 3287.342, 25.00659, 1.624082, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+275, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1124.558, 3291.35, 24.97413, 1.393245, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+276, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1184.556, 3326.378, 20.08359, 6.261689, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+277, 107471, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1187.302, 3327.674, 20.08359, 4.521907, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+278, 107470, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1187.17, 3324.453, 20.08359, 1.675012, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+279, 104295, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1226.002, 3390.03, 20.08359, 2.299895, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blazing Imp (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+280, 107472, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1103.809, 3264.759, 25.00659, 2.298314, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Fancy Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire) (possible waypoints or random movement)
(@CGUID+281, 104694, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1255.198, 3414.222, 54.04576, 1.405624, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Citizen (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel) (possible waypoints or random movement)
(@CGUID+282, 105719, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1268.047, 3441.774, 28.90902, 5.816803, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 207221 - Sommeil)
(@CGUID+283, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1246.233, 3376.831, 50.94781, 5.037354, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+284, 104246, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1261.601, 3526.801, 20.94905, 4.147412, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+285, 107324, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1253.934, 3440.595, 53.94661, 3.591019, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 220633 - Sorcelame Aluriel)
(@CGUID+286, 104694, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1245.427, 3413.536, 53.94661, 4.951725, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+287, 111366, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1242.04, 3381.289, 50.94985, 6.216056, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+288, 105699, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1258.307, 3524.86, 20.9503, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+289, 107324, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1251.123, 3439.269, 53.94661, 0.4330097, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 220633 - Sorcelame Aluriel)
(@CGUID+290, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1246.965, 3412.603, 53.94661, 3.833368, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+291, 104694, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1259.286, 3457.195, 53.94662, 4.601311, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+292, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1266.7, 3474.695, 32.69947, 3.567032, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+293, 105705, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1262.273, 3522.982, 20.94817, 2.501322, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bound Energy (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+294, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1263.995, 3472.944, 32.69947, 0.720138, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+295, 107324, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1282.809, 3442.6, 29.00659, 1.279397, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 220633 - Sorcelame Aluriel)
(@CGUID+296, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1272.391, 3416.214, 53.81786, 2.973191, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+297, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1255.25, 3377.979, 50.94636, 4.799234, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+298, 104270, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1297.347, 3478.898, 30.38802, 1.406917, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+299, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1263.255, 3402.439, 53.98182, 1.926502, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+300, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1252.352, 3386.308, 50.94331, 1.426084, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+301, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1254.28, 3375.878, 50.95412, 4.799234, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+302, 104247, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1284.123, 3505.925, 21.00659, 0.1927971, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques) (possible waypoints or random movement)
(@CGUID+303, 104246, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1283.548, 3508.87, 21.00659, 0.192797, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+304, 111363, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1256.188, 3380.097, 50.94764, 4.837884, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+305, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1286.056, 3445.753, 28.90902, 2.575898, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+306, 105719, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1297.892, 3414.111, 28.90869, 2.966634, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 207221 - Sommeil)
(@CGUID+307, 105719, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1273.793, 3418.42, 31.04861, 6.066208, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 207221 - Sommeil)
(@CGUID+308, 104246, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1268.071, 3559.004, 20.10921, 3.124333, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+309, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1246.556, 3375.117, 50.96729, 2.700884, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+310, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1271.655, 3431.458, 31.04861, 1.03396, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+311, 105705, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1266.689, 3551.77, 20.10921, 2.779246, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bound Energy (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
(@CGUID+312, 105704, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1284.698, 3502.981, 21.00659, 0.192797, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcane Manifestation (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+313, 107324, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1288.844, 3411.932, 28.90869, 1.948044, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 220633 - Sorcelame Aluriel)
(@CGUID+314, 111364, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1248.299, 3374.109, 50.95248, 4.330552, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Supplies (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@CGUID+315, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1283.615, 3447.857, 28.90902, 5.422793, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+316, 104694, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1283.696, 3438.656, 28.90902, 1.161964, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+317, 104245, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1272.984, 3513.678, 20.8121, 0.6127326, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Beacon (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde)
(@CGUID+318, 104270, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1270.234, 3554.542, 20.10921, 2.939686, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guardian Construct (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+319, 104694, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1305.569, 3419.66, 28.90901, 2.74613, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel)
(@CGUID+320, 104696, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1315.743, 3461.986, 32.69946, 5.422793, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+321, 104300, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1149.831, 3274.421, 20.00738, 1.909729, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Shadow Mistress (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+322, 104277, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1144.172, 3272.426, 20.00738, 1.90975, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Legion Hound (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+323, 108419, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1208.788, 3440.684, 23.48162, 0, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Automated Sweeper (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 215252 - Balayeur automatique) (possible waypoints or random movement)
(@CGUID+324, 105715, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1147.002, 3273.424, 20.00738, 1.909733, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Inquisitor (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 211861 - Garde sinistre)
(@CGUID+325, 104695, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1298.082, 3388.586, 36.43924, 3.530753, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Merchant (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 196285 - , 220633 - Sorcelame Aluriel) (possible waypoints or random movement)
(@CGUID+326, 108419, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1194.856, 3412.879, 21.79829, 3.395204, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Automated Sweeper (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 215252 - Balayeur automatique) (possible waypoints or random movement)
(@CGUID+327, 107141, 1571, 8079, 8181, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: )
-- (@CGUID+328, 107151, UNKNOWN, 8079, 8181, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+329, 104245, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1303.769, 3586.332, 20.10921, 0.2300747, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Beacon (Area: Marché Doré - Difficulty: Héroïque) (Auras: 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde)
(@CGUID+330, 105704, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1310.358, 3605.939, 20.10921, 4.147412, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Manifestation (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+331, 105699, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1311.03, 3602.12, 20.10921, 2.501322, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Saber (Area: Marché Doré - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+332, 104247, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1307.064, 3603.998, 20.10921, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Marché Doré - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques)
(@CGUID+333, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1325.16, 3508.615, 20.10928, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+334, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1332.097, 3508.61, 20.10928, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+335, 104247, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1313.337, 3617.198, 20.05468, 5.999364, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Marché Doré - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques)
(@CGUID+336, 105699, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1334.64, 3513.454, 20.15094, 4.177993, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Mana Saber (Area: Marché Doré - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage) (possible waypoints or random movement)
(@CGUID+337, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1331.524, 3502.136, 20.10928, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+338, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1326.795, 3504.68, 20.10928, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+339, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1332.365, 3504.801, 20.10928, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+340, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1326.74, 3507.89, 20.10928, 6.116659, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+341, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1329.125, 3506.737, 20.10928, 2.501322, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+342, 104695, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1320.446, 3454.55, 32.69946, 1.893446, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+343, 104246, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1328.453, 3510.556, 20.10928, 4.147412, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+344, 104695, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1324.592, 3462.058, 32.69945, 3.056497, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+345, 104246, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1340.966, 3513.205, 20.15094, 1.206671, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Marché Doré - Difficulty: Héroïque) (Auras: ) (possible waypoints or random movement)
(@CGUID+346, 105705, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1314.191, 3620.612, 20.25703, 2.035433, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bound Energy (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+347, 104247, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1338.163, 3514.275, 20.15094, 1.206606, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Marché Doré - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques) (possible waypoints or random movement)
(@CGUID+348, 104246, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1340.308, 3592.405, 29.47375, 4.058744, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
(@CGUID+349, 104247, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1341.818, 3589.453, 28.9371, 4.060964, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcaniste de la Garde crépusculaire (Area: Marché Doré - Difficulty: Héroïque) (Auras: 209438 - Mains arcaniques)
(@CGUID+350, 104245, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1358.962, 3566.575, 20.86803, 3.663928, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arcane Beacon (Area: Marché Doré - Difficulty: Héroïque) (Auras: 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde)
(@CGUID+351, 107141, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
-- (@CGUID+352, 107151, UNKNOWN, 8079, 8182, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+353, 104246, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1366.647, 3637.564, 35.60659, 1.083691, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Duskwatch Guard (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+354, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1368.762, 3634.174, 35.60659, 5.512854, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+355, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1366.398, 3632.993, 35.60659, 4.811331, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+356, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1364.886, 3640.319, 35.60659, 1.741219, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+357, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1365.448, 3636.862, 35.60659, 2.798146, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+358, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1371.016, 3636.926, 35.60659, 2.760998, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+359, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1371.364, 3637.421, 35.60659, 1.50204, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+360, 105703, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1372.874, 3631.308, 35.60659, 4.959527, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mana Wyrm (Area: Marché Doré - Difficulty: Héroïque)
(@CGUID+361, 107141, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
-- (@CGUID+362, 107151, UNKNOWN, 8079, 8182, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+363, 104400, UNKNOWN, 8079, 8182, 8388868, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Resonant Stalker (Area: Marché Doré - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+364, 104278, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1023.809, 3373.88, 19.92156, 4.25119, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Felbound Enforcer (Area: Marché Doré - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
-- (@CGUID+365, 107151, UNKNOWN, 8079, 8182, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+366, 108419, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1231, 3436.514, 53.48313, 5.969172, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Automated Sweeper (Area: Marché Doré - Difficulty: Héroïque) (Auras: 215252 - Balayeur automatique) (possible waypoints or random movement)
(@CGUID+367, 108419, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1287.539, 3420.353, 29.00659, 0.1716499, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Automated Sweeper (Area: Marché Doré - Difficulty: Héroïque) (Auras: 215252 - Balayeur automatique) (possible waypoints or random movement)
(@CGUID+368, 108419, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1260.563, 3413.281, 54.00347, 4.744248, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Automated Sweeper (Area: Marché Doré - Difficulty: Héroïque) (Auras: 215252 - Balayeur automatique) (possible waypoints or random movement)
-- (@CGUID+369, 107151, UNKNOWN, 8079, 8182, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+370, 108419, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1205.575, 3440.456, 60.60659, 0.2131843, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Automated Sweeper (Area: Marché Doré - Difficulty: Héroïque) (Auras: 215252 - Balayeur automatique) (possible waypoints or random movement)
(@CGUID+371, 107472, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1175.132, 3270.573, 53.99639, 2.716312, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+372, 107471, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1210.997, 3274.442, 20.00738, 4.415725, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Wealthy Elite (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire) (possible waypoints or random movement)
(@CGUID+373, 107472, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1167.094, 3266.411, 20.08359, 4.521907, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+374, 104695, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1200.153, 3261.551, 53.99741, 0.522721, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+375, 107324, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1194.434, 3280.938, 20.08359, 2.589372, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Marché Doré - Difficulty: Héroïque) (Auras: 220629 - Etraeus, l’augure stellaire)
(@CGUID+376, 107470, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1202.75, 3259.476, 53.99751, 2.130798, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+377, 105249, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1127.653, 3320.572, 24.51352, 4.973417, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightshade Refreshments (Area: Marché Doré - Difficulty: Héroïque) (Auras: 208561 - Nourriture)
(@CGUID+378, 107470, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1182.625, 3276.395, 53.99599, 2.99929, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+379, 107324, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1191.965, 3283.007, 20.08359, 5.436267, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Child (Area: Marché Doré - Difficulty: Héroïque) (Auras: 220629 - Etraeus, l’augure stellaire)
(@CGUID+380, 104695, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1178.616, 3275.02, 53.99599, 0.3020344, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+381, 107472, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1178.823, 3262.321, 53.99659, 3.55653, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 202427 -)
(@CGUID+382, 107470, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1166.962, 3263.191, 20.08359, 1.675012, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+383, 104695, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1164.347, 3265.115, 20.08359, 6.261688, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+384, 106110, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1211.22, 3347.639, 20.53681, 1.582506, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Waterlogged Scroll (Area: Marché Doré - Difficulty: Héroïque) (Auras: 210270 - Parchemin détrempé)
(@CGUID+385, 105215, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1146.408, 3256.534, 20.08359, 2.259741, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Discarded Junk (Area: Marché Doré - Difficulty: Héroïque) (Auras: 208378 - Débris)
(@CGUID+386, 107141, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1121.515, 3347.117, 0.3225774, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Marché Doré - Difficulty: Héroïque) (Auras: )
-- (@CGUID+387, 107151, UNKNOWN, 8079, 8182, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Marché Doré - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+388, 104694, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1021.704, 3376.693, 19.87077, 3.021462, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Citizen (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+389, 104694, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1020.364, 3368.81, 19.87077, 0.09458248, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+390, 104695, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1015.428, 3370.344, 19.87077, 0.2315095, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Merchant (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+391, 104696, 1571, 8079, 8182, 8388868, '0', 0, 0, 0, 1018.812, 3364.448, 19.87077, 0.254512, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Marché Doré - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+392, 106296, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1067.472, 3462.681, 20.79881, 0.8564523, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+393, 106296, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1128.158, 3470.695, 19.92156, 3.294155, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+394, 106296, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1104.479, 3447.857, 19.92156, 1.497632, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+395, 106296, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1085.844, 3482.291, 19.92156, 5.219141, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+396, 111937, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1115.516, 3448.058, 19.92156, 3.680662, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+397, 111937, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1113.063, 3451.187, 19.92156, 4.652345, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+398, 106296, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1060.536, 3467.56, 20.79881, 0.705775, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+399, 106024, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1170.441, 3314.227, 22.08325, 0.5693311, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Magical Lantern (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 210129 - Lanterne luminescente)
(@CGUID+400, 106296, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1092.684, 3445.361, 19.92156, 1.174328, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily Agent (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+401, 110560, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1113.427, 3448.736, 19.86362, 3.992134, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Vanthir (Area: Cour de Minuit - Difficulty: Héroïque)
-- (@CGUID+402, 107291, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, 0.02864359, 0.3912373, 2.123986, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Oculus (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+403, 107151, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+404, 111936, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1086.194, 3309.354, 25.06015, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Thal'kiel (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+405, 111374, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1086.194, 3309.354, 25.06015, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Xal'atath (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+406, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1010.991, 3223.935, 25.0812, 2.305104, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+407, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1086.979, 3189.563, 41.6928, 6.261688, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+408, 105410, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 997.9393, 3229.463, 25.08082, 1.854069, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Musician (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 208900 - Harpe)
(@CGUID+409, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1089.594, 3187.64, 41.6928, 1.675012, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+410, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1089.726, 3190.86, 41.6928, 4.521907, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 - , 220629 - Etraeus, l’augure stellaire)
(@CGUID+411, 105410, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1005.707, 3221.241, 25.0809, 6.240074, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Musician (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 208900 - Harpe)
(@CGUID+412, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 987.1545, 3218.743, 25.14657, 0.07165075, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+413, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 989.5868, 3220.788, 25.14657, 4.361908, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+414, 110958, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 990.2934, 3218.031, 25.14657, 2.307836, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 220697 - Noble élégant)
(@CGUID+415, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 994.431, 3205.8, 22.72914, 2.648113, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+416, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 968.8976, 3228.49, 22.65564, 0.9754397, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+417, 107756, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 981.0712, 3203.944, 22.62618, 5.953574, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Estate Attendant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 213954 - Tenir le plateau) (possible waypoints or random movement)
(@CGUID+418, 110958, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 970.2795, 3212.448, 22.65842, 0.5789019, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 220697 - Noble élégant)
(@CGUID+419, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 970.4106, 3207.843, 22.61543, 3.299887, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+420, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 972.1268, 3215.745, 22.65789, 4.869159, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+421, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 974.6875, 3212.885, 22.65818, 2.755394, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+422, 107756, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1021.906, 3183.409, 52.22601, 1.40472, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Estate Attendant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 213954 - Tenir le plateau) (possible waypoints or random movement)
(@CGUID+423, 112699, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 979.4028, 3201.595, 22.65824, 2.416556, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+424, 112697, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 977.0382, 3203.587, 22.65837, 5.639878, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suspicious Noble (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+425, 110960, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 982.2986, 3183.337, 22.6592, 0.07165075, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+426, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 966.9097, 3199.243, 24.15474, 1.575833, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+427, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 974.0816, 3187.439, 24.27178, 4.916246, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+428, 110959, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 985.7639, 3186.191, 22.65882, 4.361908, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 220633 - Sorcelame Aluriel)
(@CGUID+429, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 986.4757, 3182.259, 22.65851, 2.307836, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+430, 107756, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 935.5972, 3214.501, 29.02602, 2.573784, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Estate Attendant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 213954 - Tenir le plateau) (possible waypoints or random movement)
(@CGUID+431, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 985.5365, 3175.5, 22.57648, 4.976161, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 - , 165091 - Mod Scale -20%)
(@CGUID+432, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 986.3871, 3179.031, 22.65833, 0.1159343, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+433, 110958, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 909.8212, 3242.448, 14.85774, 2.601692, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 220697 - Noble élégant)
(@CGUID+434, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 933.0156, 3214.156, 29.09062, 0.8165667, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+435, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 934.9636, 3216.628, 29.09058, 4.138765, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+436, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 904.4549, 3256.116, 12.1046, 0.9480949, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+437, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 890.0799, 3271.23, 12.94779, 4.022826, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+438, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 907.2864, 3244.316, 14.85774, 5.562678, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+439, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 900.3438, 3252.011, 12.1046, 4.46644, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+440, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 941.4467, 3194.426, 22.57648, 3.940624, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 - , 165091 - Mod Scale -20%)
(@CGUID+441, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 898.7413, 3250.739, 12.1046, 6.114868, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+442, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 891.993, 3258.669, 15.15514, 0.9728032, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+443, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 888.2882, 3268.638, 12.94779, 1.06184, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+444, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 963.625, 3179.408, 23.52892, 2.601692, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+445, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 961.0903, 3181.276, 23.81723, 5.562678, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+446, 107756, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 879.3132, 3274.331, 12.30506, 6.269867, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Estate Attendant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 213954 - Tenir le plateau) (possible waypoints or random movement)
(@CGUID+447, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1224.251, 3382.758, 20.17806, 3.310872, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+448, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 896.7118, 3239.691, 12.94779, 4.737586, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+449, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 925.1589, 3224.447, 52.42601, 1.875746, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+450, 104696, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1152.92, 3221.705, 20.08359, 3.266664, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+451, 104278, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1148.979, 3222.84, 20.08359, 3.460974, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Felbound Enforcer (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+452, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1147.431, 3217.416, 20.08359, 1.226902, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+453, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1145.814, 3221.507, 20.08359, 3.657031, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+454, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1150.2, 3216.811, 20.08359, 1.884629, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+455, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1144.227, 3219.958, 20.08359, 0.2630532, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
-- (@CGUID+456, 107291, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, 0.02864359, 0.3912373, 2.123986, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Oculus (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+457, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1059.543, 3388.401, 19.92155, 5.893472, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
-- (@CGUID+458, 107151, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, 1.5, 0, -0.625, 3.141593, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
-- (@CGUID+459, 107291, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, -0.09158916, 1, 2.842124, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Watchful Oculus (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+460, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1109.21, 3391.56, 19.92156, 1.140831, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+461, 107756, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1028.205, 3130.604, 13.48217, 0.240632, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Estate Attendant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 213954 - Tenir le plateau) (possible waypoints or random movement)
(@CGUID+462, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1037.13, 3129.27, 13.53289, 3.975484, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+463, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1036.328, 3120.151, 13.53289, 2.342141, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+464, 110960, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1039.259, 3114.891, 12.94779, 2.755394, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+465, 110959, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1035.483, 3114.903, 13.11301, 0.5789019, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 220633 - Sorcelame Aluriel)
(@CGUID+466, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1022.116, 3122.578, 13.14549, 4.12512, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+467, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 963.9115, 3163.786, 22.57648, 1.084335, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 - , 165091 - Mod Scale -20%)
(@CGUID+468, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 995.4132, 3336.733, 41.83689, 5.422793, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+469, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 997.8542, 3334.63, 41.84537, 2.575898, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+470, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 990.4841, 3144.383, 52.44525, 0.5854812, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+471, 107141, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: )
-- (@CGUID+472, 107151, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+473, 104278, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1023.362, 3372.98, 19.9121, 4.25119, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Felbound Enforcer (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+474, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1020.644, 3372.547, 19.92156, 5.436825, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+475, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1022.26, 3368.456, 19.92156, 2.801224, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+476, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1025.03, 3367.851, 19.92156, 0.9817731, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+477, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1019.057, 3370.998, 19.92156, 0.2630532, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+478, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1224.259, 3382.76, 20.17826, 3.310872, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+479, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1167.094, 3266.411, 20.08359, 4.521907, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+480, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1164.347, 3265.115, 20.08359, 6.261688, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+481, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1166.962, 3263.191, 20.08359, 1.675012, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+482, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1117.54, 3399.474, 19.92156, 1.249795, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+483, 107141, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: )
-- (@CGUID+484, 107151, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, 1.5, 0, -0.625, 3.141593, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+485, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1110.964, 3394.267, 19.92156, 3.987726, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+486, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1109.21, 3391.56, 19.92156, 1.140831, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+487, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1064.646, 3419.075, 19.92155, 6.174846, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+488, 104695, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1069.031, 3414.378, 19.92156, 1.733765, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Merchant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+489, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1063.059, 3417.526, 19.92155, 6.209546, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+490, 104696, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1071.754, 3419.273, 19.92155, 3.454847, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Civilian (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+491, 104278, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1068.738, 3420.078, 19.9239, 5.940439, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Felbound Enforcer (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 18950 - Détection de l'invisibilité et du camouflage)
(@CGUID+492, 104694, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1066.264, 3414.984, 19.92155, 5.63293, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Citizen (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+493, 104696, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1208.309, 3442.685, 41.66802, 3.110796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Civilian (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+494, 106468, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1061.802, 3286.725, 23.67176, 0.7328305, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Ly'leth Lunastre (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 34427 - Téléportation éthérienne)
(@CGUID+495, 107471, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1040.386, 3361.915, 19.9174, 2.697349, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Wealthy Elite (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+496, 107141, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: )
-- (@CGUID+497, 107151, UNKNOWN, 8079, 8183, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+498, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 941.6389, 3169.374, 22.78631, 2.187808, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+499, 107470, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 939.6077, 3171.775, 22.78631, 5.510007, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 107472, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 941.8906, 3160.955, 49.6574, 5.02366, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fancy Noble (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+501, 110960, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 940.2483, 3156.777, 49.63323, 0.3641995, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Cour de Minuit - Difficulty: Héroïque)
(@CGUID+502, 108406, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 1012.529, 3237.692, 25.02601, 3.468501, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcane Custodian (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 215238 - Corvée de nettoyage) (possible waypoints or random movement)
(@CGUID+503, 107756, 1571, 8079, 8183, 8388868, '0', 0, 0, 0, 936.2136, 3148.623, 52.42601, 5.477516, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Estate Attendant (Area: Cour de Minuit - Difficulty: Héroïque) (Auras: 213954 - Tenir le plateau) (possible waypoints or random movement)
-- (@CGUID+504, 32641, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Drix Blackwrench (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 61424 - Mammouth de voyage de la toundra) - !!! on transport - transport template not found !!!
(@CGUID+505, 108406, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 992.0746, 3199.969, 22.65494, 1.580868, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcane Custodian (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 215238 - Corvée de nettoyage) (possible waypoints or random movement)
(@CGUID+506, 110443, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 871.2882, 3111.109, 54.93766, 5.873211, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Elisande (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@CGUID+507, 108406, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 939.8373, 3140.862, 52.42601, 2.90659, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Arcane Custodian (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 215238 - Corvée de nettoyage) (possible waypoints or random movement)
(@CGUID+508, 107141, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 1120.941, 3346.287, 0.2817549, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: )
-- (@CGUID+509, 107151, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
(@CGUID+510, 107470, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 997.8542, 3334.63, 41.84537, 2.575898, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Haughty Aristocrat (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 196285 -)
(@CGUID+511, 107141, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 1121.508, 3347.106, 0.3220722, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Boat (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: )
-- (@CGUID+512, 107151, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Noble (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+513, 107141, 1571, 8079, 8184, 8388868, '0', 0, 0, 0, 1121.505, 3347.102, 0.3218701, 0.9655151, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Nightborne Boat (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: )
-- (@CGUID+514, 107151, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 10, 0, 0, 0, 1, 0, 0, 0, 25996), -- Suramar Noble (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+515, 107151, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
-- (@CGUID+516, 107151, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, -1.875, 0, -0.625, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Suramar Noble (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 188236 -) - !!! on transport - transport template not found !!!
-- (@CGUID+517, 105765, UNKNOWN, 8079, 8184, 8388868, '0', 0, 0, 0, 0, 0, -0.02361075, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Gale Stalker (Area: Domaine des Joyaux - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+18 AND @CGUID+517;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+18, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+19, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+20, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+21, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+22, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+23, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+24, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+25, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+26, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+27, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+30, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+31, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, '209519'), -- Signal Lantern - 209519 - Lanterne
(@CGUID+33, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+35, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+36, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+38, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Resonant Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+40, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, '227147 210143'), -- Patrol Captain Gerdo - 227147 - Zone sécurisée, 210143 - Commandement
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Conversation Stalker
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+51, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+54, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+56, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '46598 188236'), -- Suramar Noble - 46598 - Ride Vehicle Hardcoded, 188236 -
(@CGUID+61, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bound Energy
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bound Energy
(@CGUID+69, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+70, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+71, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+72, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+73, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+78, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcane Manifestation
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '227148'), -- Duskwatch Sentry - 227148 - Tache lumineuse
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+86, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+88, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, '227148'), -- Duskwatch Sentry - 227148 - Tache lumineuse
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, '227148'), -- Duskwatch Sentry - 227148 - Tache lumineuse
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, '209723 209435 42459'), -- Talixae Flamewreath - 209723 - Lien de flamme, 209435 - Mains de flammes, 42459 - Ambidextrie
(@CGUID+108, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+109, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, '212480 206309 212479'), -- Arcane Beacon - 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, '209712'), -- Imacu'tya - 209712 - Lien de ruse
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, '209717'), -- Baalgar the Watchful - 209717 - Lien de cruauté
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, '207819'), -- Jazshariu - 207819 - Lien de force
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Engorged Manafeeder - 151051 - Échelle : 95-120%
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, '188236 86603'), -- Dusk Lily Agent - 188236 - , 86603 - Camouflage
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentry
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, '212480 206309 212479'), -- Arcane Beacon - 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+125, 0, 0, 3, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Saber
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Saber
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, '220629'), -- Suramar Child - 220629 - Etraeus, l’augure stellaire
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chatty Rumormonger
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, '220629'), -- Suramar Child - 220629 - Etraeus, l’augure stellaire
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chatty Rumormonger
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '220629'), -- Suramar Child - 220629 - Etraeus, l’augure stellaire
(@CGUID+136, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- Overgrown Eel - 151051 - Échelle : 95-120%
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Haughty Aristocrat - 196285 - , 202427 -
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chatty Rumormonger
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Suramar Merchant - 196285 - , 202427 -
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Fancy Noble - 196285 - , 202427 -
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- Duskwatch Guard - 29266 - Feindre la mort permanent
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '213089'), -- Suspicious Noble - 213089 -
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, '213095'), -- Suspicious Noble - 213095 -
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '213101'), -- Suspicious Noble - 213101 -
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, '213106'), -- Suspicious Noble - 213106 -
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Suspicious Suramar Noble
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- Watchful Inquisitor - 211861 - Garde sinistre
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Legion Hound - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+167, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+168, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, '191779'), -- Nightborne Supplies - 191779 -
(@CGUID+170, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, '213099'), -- Suspicious Noble - 213099 -
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Mistress
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, '213080'), -- Suspicious Noble - 213080 -
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, '213108 227258'), -- Suspicious Noble - 213108 - , 227258 - Déclencheur de zone de Garde-Vérité
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '213105'), -- Suspicious Noble - 213105 -
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, '213102'), -- Suspicious Noble - 213102 -
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '213104'), -- Suspicious Noble - 213104 -
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '213107'), -- Suspicious Noble - 213107 -
(@CGUID+186, 0, 0, 0, 1, 0, 0, 0, 0, '213100'), -- Suspicious Noble - 213100 -
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, '206888'), -- Shadow Mistress - 206888 - Canalisation de l’ombre
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- Watchful Inquisitor - 211861 - Garde sinistre
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Mistress
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, '191779'), -- Nightborne Supplies - 191779 -
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '213097'), -- Suspicious Noble - 213097 -
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, '213103'), -- Suspicious Noble - 213103 -
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, '213098'), -- Suspicious Noble - 213098 -
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, '191779'), -- Nightborne Supplies - 191779 -
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, '213096'), -- Suspicious Noble - 213096 -
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+211, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- Suramar Dockworker - 123168 - Échelle : 115-120%
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chatty Rumormonger
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chatty Rumormonger
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+221, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+222, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- Watchful Inquisitor - 211861 - Garde sinistre
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Legion Hound - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Velimar
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Legion Hound - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- Watchful Inquisitor - 211861 - Garde sinistre
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Gale Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+242, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, '18950'); -- Legion Hound - 18950 - Détection de l'invisibilité et du camouflage

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+251, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Civilian - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+257, 0, 0, 1, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Civilian - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, '206888'), -- Shadow Mistress - 206888 - Canalisation de l’ombre
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, '227148'), -- Duskwatch Sentry - 227148 - Tache lumineuse
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Suramar Merchant - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- Watchful Inquisitor - 211861 - Garde sinistre
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blazing Imp
(@CGUID+280, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Citizen - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, '196285 207221'), -- Mana Saber - 196285 - , 207221 - Sommeil
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- Suramar Child - 220633 - Sorcelame Aluriel
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Citizen - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- Suramar Child - 220633 - Sorcelame Aluriel
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Merchant - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+291, 0, 0, 1, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Citizen - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bound Energy
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+295, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- Suramar Child - 220633 - Sorcelame Aluriel
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Civilian - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+298, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+299, 0, 0, 1, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Civilian - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Suramar Merchant
(@CGUID+301, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+302, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Merchant - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, '196285 207221'), -- Mana Saber - 196285 - , 207221 - Sommeil
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, '196285 207221'), -- Mana Saber - 196285 - , 207221 - Sommeil
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+310, 0, 0, 1, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Civilian - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bound Energy
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcane Manifestation
(@CGUID+313, 0, 0, 1, 1, 0, 0, 0, 0, '220633'), -- Suramar Child - 220633 - Sorcelame Aluriel
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Supplies
(@CGUID+315, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Civilian - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+316, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Citizen - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, '212480 206309 212479'), -- Arcane Beacon - 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Guardian Construct - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+319, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Citizen - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadow Mistress
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Legion Hound - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- Automated Sweeper - 215252 - Balayeur automatique
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- Watchful Inquisitor - 211861 - Garde sinistre
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220633'), -- Suramar Merchant - 196285 - , 220633 - Sorcelame Aluriel
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- Automated Sweeper - 215252 - Balayeur automatique
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, '212480 206309 212479'), -- Arcane Beacon - 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcane Manifestation
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+332, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+335, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Mana Saber - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bound Energy
(@CGUID+347, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+349, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - 209438 - Mains arcaniques
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, '212480 206309 212479'), -- Arcane Beacon - 212480 - Proximité du poste de garde, 206309 - Tache lumineuse, 212479 - Proximité du poste de garde
(@CGUID+351, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Guard
(@CGUID+354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mana Wyrm
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Resonant Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Felbound Enforcer - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- Automated Sweeper - 215252 - Balayeur automatique
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- Automated Sweeper - 215252 - Balayeur automatique
(@CGUID+368, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- Automated Sweeper - 215252 - Balayeur automatique
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- Automated Sweeper - 215252 - Balayeur automatique
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Fancy Noble - 196285 - , 202427 -
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Wealthy Elite - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Suramar Merchant - 196285 - , 202427 -
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, '220629'), -- Suramar Child - 220629 - Etraeus, l’augure stellaire
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Haughty Aristocrat - 196285 - , 202427 -
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, '208561'), -- Nightshade Refreshments - 208561 - Nourriture
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Haughty Aristocrat - 196285 - , 202427 -
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, '220629'), -- Suramar Child - 220629 - Etraeus, l’augure stellaire
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Suramar Merchant - 196285 - , 202427 -
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- Fancy Noble - 196285 - , 202427 -
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Suramar Merchant - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, '210270'), -- Waterlogged Scroll - 210270 - Parchemin détrempé
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, '208378'), -- Discarded Junk - 208378 - Débris
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+393, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+394, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+396, 0, 0, 0, 1, 0, 10282, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+397, 0, 0, 0, 1, 0, 10282, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, '210129'), -- Magical Lantern - 210129 - Lanterne luminescente
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dusk Lily Agent
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Vanthir
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Watchful Oculus - 46598 - Ride Vehicle Hardcoded
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Fancy Noble - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, '208900'), -- Suramar Musician - 208900 - Harpe
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Haughty Aristocrat - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- Suramar Merchant - 196285 - , 220629 - Etraeus, l’augure stellaire
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, '208900'), -- Suramar Musician - 208900 - Harpe
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, '220697'), -- Fancy Noble - 220697 - Noble élégant
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- Estate Attendant - 213954 - Tenir le plateau
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, '220697'), -- Fancy Noble - 220697 - Noble élégant
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- Estate Attendant - 213954 - Tenir le plateau
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Suspicious Noble
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Suspicious Noble
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Haughty Aristocrat
(@CGUID+426, 0, 0, 1, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+427, 0, 0, 1, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+428, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- Wealthy Elite - 220633 - Sorcelame Aluriel
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- Estate Attendant - 213954 - Tenir le plateau
(@CGUID+431, 0, 0, 6, 1, 0, 0, 0, 0, '196285 165091'), -- Fancy Noble - 196285 - , 165091 - Mod Scale -20%
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, '220697'), -- Fancy Noble - 220697 - Noble élégant
(@CGUID+434, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+436, 0, 0, 1, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+439, 0, 0, 1, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+440, 0, 0, 6, 1, 0, 0, 0, 0, '196285 165091'), -- Fancy Noble - 196285 - , 165091 - Mod Scale -20%
(@CGUID+441, 0, 0, 1, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+442, 0, 0, 3, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+444, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+446, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- Estate Attendant - 213954 - Tenir le plateau
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Felbound Enforcer - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+454, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Watchful Oculus - 46598 - Ride Vehicle Hardcoded
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Watchful Oculus - 46598 - Ride Vehicle Hardcoded
(@CGUID+460, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+461, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- Estate Attendant - 213954 - Tenir le plateau
(@CGUID+462, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+463, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Haughty Aristocrat
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- Wealthy Elite - 220633 - Sorcelame Aluriel
(@CGUID+466, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+467, 0, 0, 6, 1, 0, 0, 0, 0, '196285 165091'), -- Fancy Noble - 196285 - , 165091 - Mod Scale -20%
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Felbound Enforcer - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Merchant - 196285 -
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+491, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- Felbound Enforcer - 18950 - Détection de l'invisibilité et du camouflage
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Citizen - 196285 -
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Suramar Civilian - 196285 -
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, '34427'), -- Ly'leth Lunastre - 34427 - Téléportation éthérienne
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Wealthy Elite - 196285 -
(@CGUID+496, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, '196285'); -- Haughty Aristocrat - 196285 -

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Fancy Noble - 196285 -
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Haughty Aristocrat
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, '215238'), -- Arcane Custodian - 215238 - Corvée de nettoyage
(@CGUID+503, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- Estate Attendant - 213954 - Tenir le plateau
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Drix Blackwrench - 61424 - Mammouth de voyage de la toundra
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, '215238'), -- Arcane Custodian - 215238 - Corvée de nettoyage
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Elisande
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, '215238'), -- Arcane Custodian - 215238 - Corvée de nettoyage
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Haughty Aristocrat - 196285 -
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightborne Boat
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Suramar Noble - 188236 -
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, '46598'); -- Gale Stalker - 46598 - Ride Vehicle Hardcoded

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+1 AND @OGUID+37;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 249386, 1571, 8079, 8079, 8388868, '', 0, 1024.153, 3805.538, 7.176136, 6.126032, 0, 0, -0.07849598, 0.9969144, 86400, 255, 1, 25996), -- Arcane Barrier (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+2, 252245, 1571, 8079, 8079, 8388868, '', 0, 1017.852, 3827.853, 9.486423, 4.531372, 0, 0, -0.7681246, 0.6403005, 86400, 255, 1, 25996), -- Instance Portal (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+3, 249386, 1571, 8079, 8079, 8388868, '', 0, 1008.247, 3779.665, 4.419988, 4.521422, 0, 0, -0.7713003, 0.6364714, 86400, 255, 1, 25996), -- Arcane Barrier (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+4, 253955, 1571, 8079, 8079, 8388868, '', 0, 1002.696, 3856.199, 11.44764, 3.795101, 0, 0, -0.9470892, 0.3209705, 86400, 255, 1, 25996), -- Meeting Stone (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+5, 249386, 1571, 8079, 8079, 8388868, '', 0, 1003.115, 3809.075, 6.770661, 6.031605, 0, 0, -0.1254587, 0.9920988, 86400, 255, 1, 25996), -- Arcane Barrier (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+6, 265469, 1571, 8079, 8079, 8388868, '', 0, 817.1643, 3901.796, 0.1015638, 4.193961, 0, 0, -0.8647299, 0.5022372, 86400, 255, 24, 25996), -- 0 (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+7, 265470, 1571, 8079, 8079, 8388868, '', 0, 638.838, 4056.745, 0.1015638, 0.4934123, 0, 0, 0.2442112, 0.9697221, 86400, 255, 24, 25996), -- 0 (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+8, 253922, 1571, 8079, 8079, 8388868, '', 0, 1219.918, 3433.739, 62.22258, 5.93412, 0, 0, -0.1736479, 0.9848078, 86400, 255, 1, 25996), -- Apprentice's Door (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+9, 251847, 1571, 8079, 8079, 8388868, '', 0, 1027.246, 3251.448, 25.12713, 3.926996, 0, 0, -0.9238787, 0.3826855, 86400, 255, 1, 25996), -- Manor Door (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+10, 251846, 1571, 8079, 8079, 8388868, '', 0, 1294.68, 3467.201, 30.56839, 4.363324, 0, 0, -0.8191519, 0.5735767, 86400, 255, 1, 25996), -- House Door (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+11, 266919, 1571, 8079, 8079, 8388868, '', 0, 1235.946, 4205.98, -65.18047, 2.617989, 0, 0, 0.9659252, 0.2588213, 86400, 255, 1, 25996), -- The Nighthold Portcullis (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+12, 249386, 1571, 8079, 8079, 8388868, '', 0, 1205.781, 3531.569, 1.452854, 1.467519, 0, 0, 0.6696663, 0.7426621, 86400, 255, 1, 25996), -- Arcane Barrier (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+13, 251849, 1571, 8079, 8079, 8388868, '', 0, 1100.5, 3435.926, 20.76277, 4.537859, 0, 0, -0.7660437, 0.6427886, 86400, 255, 1, 25996), -- Waypoint Door (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+14, 251848, 1571, 8079, 8079, 8388868, '', 0, 906.8651, 3131.031, 54.84539, 3.926996, 0, 0, -0.9238787, 0.3826855, 86400, 255, 1, 25996), -- Skyward Terrace (Area: Cour des Étoiles - Difficulty: Héroïque)
(@OGUID+15, 246805, 1571, 8079, 8181, 8388868, '', 0, 962.9462, 3319.8, 41.60947, 0.4130948, 0, 0, 0.2050819, 0.9787448, 86400, 255, 1, 25996), -- Fel Fire (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@OGUID+16, 246805, 1571, 8079, 8181, 8388868, '', 0, 966.8906, 3326.994, 41.60946, 0.4130948, 0, 0, 0.2050819, 0.9787448, 86400, 255, 1, 25996), -- Fel Fire (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@OGUID+17, 246805, 1571, 8079, 8181, 8388868, '', 0, 971.3524, 3310.499, 41.60946, 0.4130948, 0, 0, 0.2050819, 0.9787448, 86400, 255, 1, 25996), -- Fel Fire (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@OGUID+18, 246805, 1571, 8079, 8181, 8388868, '', 0, 958.6129, 3303.875, 41.60947, 0.4130948, 0, 0, 0.2050819, 0.9787448, 86400, 255, 1, 25996), -- Fel Fire (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@OGUID+19, 246805, 1571, 8079, 8181, 8388868, '', 0, 968.2222, 3293.707, 41.7769, 0.4130948, 0, 0, 0.2050819, 0.9787448, 86400, 255, 1, 25996), -- Fel Fire (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
-- (@OGUID+20, 233778, 1571, 8079, 8181, 8388868, '', 0, 1121.674, 3479.855, 19.96137, 3.43905, 0, 0, -0.9889603, 0.1481809, 86400, 255, 1, 25996), -- Collision PC Size (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+21, 252967, 1571, 8079, 8181, 8388868, '', 0, 1255.344, 3388.587, 51.80642, 1.013432, 0, 0, 0.4853086, 0.8743429, 86400, 255, 1, 25996), -- Nightborne Goods (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
(@OGUID+22, 252966, 1571, 8079, 8181, 8388868, '', 0, 1252.854, 3387.861, 50.78098, 1.234492, 0, 0, 0.5787916, 0.8154755, 86400, 255, 1, 25996), -- Nightborne Bazaar (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque)
-- (@OGUID+23, 233778, 1571, 8079, 8181, 8388868, '', 0, 1174.748, 3557.615, 19.96137, 5.432531, 0, 0, -0.4126186, 0.9109039, 86400, 255, 1, 25996), -- Collision PC Size (Area: Débarcadère Clair-de-Lune - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+24, 253046, 1571, 8079, 8183, 8388868, '', 0, 1113.026, 3447.313, 20.93531, 2.677037, 0, 0, 0.9731445, 0.230195, 86400, 255, 1, 25996), -- Nightborne Goods (Area: Cour de Minuit - Difficulty: Héroïque)
(@OGUID+25, 250625, 1571, 8079, 8184, 8388868, '', 0, 960.9926, 3212.964, 22.57291, 5.402188, 0, 0, -0.4263906, 0.9045391, 86400, 255, 1, 25996), -- Doodad_7NB_Nightborn_Harp002 (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+26, 250624, 1571, 8079, 8184, 8388868, '', 0, 988.6498, 3185.307, 22.57287, 5.402188, 0, 0, -0.4263906, 0.9045391, 86400, 255, 1, 25996), -- Doodad_7NB_Nightborn_Harp001 (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+27, 250613, 1571, 8079, 8184, 8388868, '', 0, 951.7659, 3212.396, 22.57648, 4.61846, 0, 0, -0.7395239, 0.6731303, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+28, 250619, 1571, 8079, 8184, 8388868, '', 0, 988.6779, 3176.338, 22.57648, 2.924575, 0, 0, 0.9941187, 0.1082961, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+29, 250618, 1571, 8079, 8184, 8388868, '', 0, 985.5365, 3175.5, 22.57648, 4.976161, 0, 0, -0.6079788, 0.7939533, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+30, 250615, 1571, 8079, 8184, 8388868, '', 0, 947.8177, 3207.086, 22.57648, 1.67926, 0, 0, 0.7443962, 0.6677382, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+31, 250614, 1571, 8079, 8184, 8388868, '', 0, 944.5916, 3206.766, 22.57648, 6.017181, 0, 0, -0.1326103, 0.9911683, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+32, 250620, 1571, 8079, 8184, 8388868, '', 0, 982.7293, 3169.054, 22.57648, 1.632172, 0, 0, 0.7284698, 0.6850778, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+33, 250617, 1571, 8079, 8184, 8388868, '', 0, 941.4467, 3194.426, 22.57648, 3.940624, 0, 0, -0.9212494, 0.3889724, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+34, 250616, 1571, 8079, 8184, 8388868, '', 0, 940.2469, 3196.969, 22.57648, 5.541856, 0, 0, -0.3622351, 0.9320868, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+35, 250622, 1571, 8079, 8184, 8388868, '', 0, 969.8198, 3165.969, 22.57648, 3.875716, 0, 0, -0.9333858, 0.3588744, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+36, 250621, 1571, 8079, 8184, 8388868, '', 0, 972.4869, 3164.462, 22.57648, 2.011289, 0, 0, 0.8445072, 0.5355442, 86400, 255, 1, 25996), -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
(@OGUID+37, 250623, 1571, 8079, 8184, 8388868, '', 0, 963.9115, 3163.786, 22.57648, 1.084335, 0, 0, 0.5159941, 0.8565921, 86400, 255, 1, 25996); -- Chair (Area: Domaine des Joyaux - Difficulty: Héroïque)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+1 AND @OGUID+37;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+4, 0, 0, 0.9238795, -0.3826835), -- Meeting Stone
(@OGUID+6, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+7, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+8, 0, 0, 0.9238795, -0.3826835), -- Apprentice's Door
(@OGUID+9, 0, 0, 0.9238795, -0.3826835), -- Manor Door
(@OGUID+10, 0, 0, 0.9238795, -0.3826835), -- House Door
(@OGUID+11, 0, 0, -0.8660253, 0.5000002), -- The Nighthold Portcullis
(@OGUID+13, 0, 0, 0.9238795, -0.3826835), -- Waypoint Door
(@OGUID+14, 0, 0, 0.9238795, -0.3826835), -- Skyward Terrace
(@OGUID+25, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_Nightborn_Harp002
(@OGUID+26, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_Nightborn_Harp001
(@OGUID+27, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+28, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+29, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+30, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+31, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+32, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+33, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+34, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+35, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+36, 0, 0, 0.9238795, -0.3826835), -- Chair
(@OGUID+37, 0, 0, 0.9238795, -0.3826835); -- Chair

DELETE FROM `spell_target_position` WHERE (`ID`=213233 AND `EffectIndex`=0) OR (`ID`=208702 AND `EffectIndex`=0) OR (`ID`=208631 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(213233, 0, 1571, 1067.74, 3291.17, 23.59, 25996), -- Spell: Invité indésirable Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(208702, 0, 1571, 961.92, 3464.99, 2.23, 25996), -- Spell: Sortir du bateau Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(208631, 0, 1571, 940.44, 3841.49, 0, 25996); -- Spell: Invocation de bateau Efffect: 28 (SPELL_EFFECT_SUMMON)


DELETE FROM `creature_template_addon` WHERE `entry` IN (110443 /*110443 (Elisande)*/, 108406 /*108406 (Arcane Custodian) - Corvée de nettoyage*/, 106468 /*106468 (Ly'leth Lunastre) - Téléportation éthérienne*/, 110959 /*110959 (Wealthy Elite) - Sorcelame Aluriel*/, 110960 /*110960 (Haughty Aristocrat)*/, 112697 /*112697 (Suspicious Noble)*/, 112699 /*112699 (Suspicious Noble)*/, 107756 /*107756 (Estate Attendant) - Tenir le plateau*/, 110958 /*110958 (Fancy Noble) - Noble élégant*/, 105410 /*105410 (Suramar Musician) - Harpe*/, 106112 /*106112 (Wounded Nightborne Civilian) - Blessure gangrenée*/, 107281 /*107281 (Eye Storm)*/, 107291 /*107291 (Watchful Oculus) - Ride Vehicle Hardcoded*/, 110560 /*110560 (Vanthir)*/, 106024 /*106024 (Magical Lantern) - Lanterne luminescente*/, 111937 /*111937 (Dusk Lily Agent)*/, 106296 /*106296 (Dusk Lily Agent)*/, 105215 /*105215 (Discarded Junk) - Débris*/, 106110 /*106110 (Waterlogged Scroll) - Parchemin détrempé*/, 105249 /*105249 (Nightshade Refreshments) - Nourriture*/, 104278 /*104278 (Felbound Enforcer) - Détection de l'invisibilité et du camouflage*/, 107559 /*107559 (Conversation Stalker)*/, 105117 /*105117 (Flask of the Solemn Night) - Flacon de la nuit solennelle*/, 108419 /*108419 (Automated Sweeper) - Balayeur automatique*/, 105719 /*105719 (Mana Saber) - , Sommeil*/, 104218 /*104218 (Advisor Melandrus) - Mains de vent*/, 105765 /*105765 (Gale Stalker) - Ride Vehicle Hardcoded*/, 108740 /*108740 (Velimar)*/, 104295 /*104295 (Blazing Imp)*/, 104300 /*104300 (Shadow Mistress)*/, 107471 /*107471 (Wealthy Elite) - , Etraeus, l’augure stellaire*/, 111362 /*111362 (Nightborne Boat)*/, 104277 /*104277 (Legion Hound) - Détection de l'invisibilité et du camouflage*/, 105715 /*105715 (Watchful Inquisitor) - Garde sinistre*/, 107442 /*107442 (Suspicious Suramar Noble)*/, 111364 /*111364 (Nightborne Supplies)*/, 111365 /*111365 (Nightborne Supplies)*/, 107435 /*107435 (Suspicious Noble)*/, 111366 /*111366 (Nightborne Supplies)*/, 111363 /*111363 (Nightborne Supplies)*/, 107472 /*107472 (Fancy Noble)*/, 104695 /*104695 (Suramar Merchant)*/, 107470 /*107470 (Haughty Aristocrat)*/, 107486 /*107486 (Chatty Rumormonger)*/, 107324 /*107324 (Suramar Child) - Etraeus, l’augure stellaire*/, 104694 /*104694 (Suramar Citizen)*/, 113617 /*113617 (Dusk Lily Agent) - , Camouflage*/, 111563 /*111563 (Duskwatch Guard)*/, 104273 /*104273 (Jazshariu) - Lien de force*/, 104274 /*104274 (Baalgar the Watchful) - Lien de cruauté*/, 104275 /*104275 (Imacu'tya) - Lien de ruse*/, 104245 /*104245 (Arcane Beacon) - Proximité du poste de garde, Tache lumineuse, Proximité du poste de garde*/, 104217 /*104217 (Talixae Flamewreath) - Lien de flamme, Mains de flammes, Ambidextrie*/, 104251 /*104251 (Duskwatch Sentry) - Tache lumineuse*/, 105704 /*105704 (Arcane Manifestation)*/, 104270 /*104270 (Guardian Construct) - Détection de l'invisibilité et du camouflage*/, 105699 /*105699 (Mana Saber) - Détection de l'invisibilité et du camouflage*/, 104247 /*Arcaniste de la Garde crépusculaire - Mains arcaniques*/, 105705 /*105705 (Bound Energy)*/, 104696 /*104696 (Suramar Civilian)*/, 107151 /*107151 (Suramar Noble) - Ride Vehicle Hardcoded*/, 107141 /*107141 (Nightborne Boat)*/, 104246 /*104246 (Duskwatch Guard)*/, 105703 /*105703 (Mana Wyrm)*/, 107564 /*107564 (Conversation Stalker)*/, 104215 /*104215 (Patrol Captain Gerdo) - Zone sécurisée, Commandement*/, 104400 /*104400 (Resonant Stalker) - Ride Vehicle Hardcoded*/, 111372 /*111372 (Suramar Dockworker) - Échelle : 115-120%*/, 105729 /*105729 (Signal Lantern) - Lanterne*/, 111367 /*111367 (Suramar Dockworker) - Échelle : 115-120%*/, 111575 /*111575 (Overgrown Eel) - Échelle : 95-120%*/, 111572 /*111572 (Engorged Manafeeder) - Échelle : 95-120%*/, 114960 /*114960 (Felsoul Ferry)*/, 116658 /*116658 (Felborne Conspirator) - Ride Vehicle Hardcoded*/, 115338 /*115338 (Rebellious Citizen)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(110443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110443 (Elisande)
(108406, 0, 0, 0, 1, 0, 0, 0, 0, '215238'), -- 108406 (Arcane Custodian) - Corvée de nettoyage
(106468, 0, 0, 0, 1, 0, 0, 0, 0, '34427'), -- 106468 (Ly'leth Lunastre) - Téléportation éthérienne
(110959, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- 110959 (Wealthy Elite) - Sorcelame Aluriel
(110960, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110960 (Haughty Aristocrat)
(112697, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112697 (Suspicious Noble)
(112699, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112699 (Suspicious Noble)
(107756, 0, 0, 0, 1, 0, 0, 0, 0, '213954'), -- 107756 (Estate Attendant) - Tenir le plateau
(110958, 0, 0, 0, 1, 0, 0, 0, 0, '220697'), -- 110958 (Fancy Noble) - Noble élégant
(105410, 0, 0, 0, 1, 0, 0, 0, 0, '208900'), -- 105410 (Suramar Musician) - Harpe
(106112, 0, 0, 0, 1, 0, 0, 0, 0, '210860'), -- 106112 (Wounded Nightborne Civilian) - Blessure gangrenée
(107281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107281 (Eye Storm)
(107291, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 107291 (Watchful Oculus) - Ride Vehicle Hardcoded
(110560, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110560 (Vanthir)
(106024, 0, 0, 0, 1, 0, 0, 0, 0, '210129'), -- 106024 (Magical Lantern) - Lanterne luminescente
(111937, 0, 0, 0, 1, 0, 10282, 0, 0, ''), -- 111937 (Dusk Lily Agent)
(106296, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106296 (Dusk Lily Agent)
(105215, 0, 0, 0, 1, 0, 0, 0, 0, '208378'), -- 105215 (Discarded Junk) - Débris
(106110, 0, 0, 0, 1, 0, 0, 0, 0, '210270'), -- 106110 (Waterlogged Scroll) - Parchemin détrempé
(105249, 0, 0, 0, 1, 0, 0, 0, 0, '208561'), -- 105249 (Nightshade Refreshments) - Nourriture
(104278, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 104278 (Felbound Enforcer) - Détection de l'invisibilité et du camouflage
(107559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107559 (Conversation Stalker)
(105117, 0, 0, 0, 1, 0, 0, 0, 0, '208182'), -- 105117 (Flask of the Solemn Night) - Flacon de la nuit solennelle
(108419, 0, 0, 0, 1, 0, 0, 0, 0, '215252'), -- 108419 (Automated Sweeper) - Balayeur automatique
(105719, 0, 0, 0, 1, 0, 0, 0, 0, '196285 207221'), -- 105719 (Mana Saber) - , Sommeil
(104218, 0, 0, 0, 1, 0, 0, 0, 0, '210140'), -- 104218 (Advisor Melandrus) - Mains de vent
(105765, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 105765 (Gale Stalker) - Ride Vehicle Hardcoded
(108740, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108740 (Velimar)
(104295, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104295 (Blazing Imp)
(104300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104300 (Shadow Mistress)
(107471, 0, 0, 0, 1, 0, 0, 0, 0, '196285 220629'), -- 107471 (Wealthy Elite) - , Etraeus, l’augure stellaire
(111362, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111362 (Nightborne Boat)
(104277, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 104277 (Legion Hound) - Détection de l'invisibilité et du camouflage
(105715, 0, 0, 0, 1, 0, 0, 0, 0, '211861'), -- 105715 (Watchful Inquisitor) - Garde sinistre
(107442, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107442 (Suspicious Suramar Noble)
(111364, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111364 (Nightborne Supplies)
(111365, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111365 (Nightborne Supplies)
(107435, 0, 0, 0, 1, 0, 0, 0, 0, '213089'), -- 107435 (Suspicious Noble)
(111366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111366 (Nightborne Supplies)
(111363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111363 (Nightborne Supplies)
(107472, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- 107472 (Fancy Noble)
(104695, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- 104695 (Suramar Merchant)
(107470, 0, 0, 0, 1, 0, 0, 0, 0, '196285 202427'), -- 107470 (Haughty Aristocrat)
(107486, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107486 (Chatty Rumormonger)
(107324, 0, 0, 0, 1, 0, 0, 0, 0, '220629'), -- 107324 (Suramar Child) - Etraeus, l’augure stellaire
(104694, 0, 0, 3, 1, 0, 0, 0, 0, '196285'), -- 104694 (Suramar Citizen)
(113617, 0, 0, 0, 1, 0, 0, 0, 0, '188236 86603'), -- 113617 (Dusk Lily Agent) - , Camouflage
(111563, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111563 (Duskwatch Guard)
(104273, 0, 0, 0, 1, 0, 0, 0, 0, '207819'), -- 104273 (Jazshariu) - Lien de force
(104274, 0, 0, 0, 1, 0, 0, 0, 0, '209717'), -- 104274 (Baalgar the Watchful) - Lien de cruauté
(104275, 0, 0, 0, 1, 0, 0, 0, 0, '209712'), -- 104275 (Imacu'tya) - Lien de ruse
(104245, 0, 0, 0, 1, 0, 0, 0, 0, '212480 206309 212479'), -- 104245 (Arcane Beacon) - Proximité du poste de garde, Tache lumineuse, Proximité du poste de garde
(104217, 0, 0, 0, 1, 0, 0, 0, 0, '209723 209435 42459'), -- 104217 (Talixae Flamewreath) - Lien de flamme, Mains de flammes, Ambidextrie
(104251, 0, 0, 0, 1, 0, 0, 0, 0, '227148'), -- 104251 (Duskwatch Sentry) - Tache lumineuse
(105704, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105704 (Arcane Manifestation)
(104270, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 104270 (Guardian Construct) - Détection de l'invisibilité et du camouflage
(105699, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 105699 (Mana Saber) - Détection de l'invisibilité et du camouflage
(104247, 0, 0, 0, 0, 0, 0, 0, 0, '209438'), -- Arcaniste de la Garde crépusculaire - Mains arcaniques
(105705, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105705 (Bound Energy)
(104696, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- 104696 (Suramar Civilian)
(107151, 0, 0, 0, 1, 0, 0, 0, 0, '46598 188236'), -- 107151 (Suramar Noble) - Ride Vehicle Hardcoded
(107141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107141 (Nightborne Boat)
(104246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104246 (Duskwatch Guard)
(105703, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105703 (Mana Wyrm)
(107564, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107564 (Conversation Stalker)
(104215, 0, 0, 0, 1, 0, 0, 0, 0, '227147 210143'), -- 104215 (Patrol Captain Gerdo) - Zone sécurisée, Commandement
(104400, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 104400 (Resonant Stalker) - Ride Vehicle Hardcoded
(111372, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- 111372 (Suramar Dockworker) - Échelle : 115-120%
(105729, 0, 0, 0, 1, 0, 0, 0, 0, '209519'), -- 105729 (Signal Lantern) - Lanterne
(111367, 0, 0, 0, 1, 0, 0, 0, 0, '123168'), -- 111367 (Suramar Dockworker) - Échelle : 115-120%
(111575, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- 111575 (Overgrown Eel) - Échelle : 95-120%
(111572, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- 111572 (Engorged Manafeeder) - Échelle : 95-120%
(114960, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114960 (Felsoul Ferry)
(116658, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 116658 (Felborne Conspirator) - Ride Vehicle Hardcoded
(115338, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 115338 (Rebellious Citizen)


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (111364, 107471, 104694, 107435, 111365, 104695, 104400, 107486, 112697, 104696, 104245, 107472, 111367, 107151, 107470, 112699, 108406, 106024, 107756, 111372, 108419, 106032, 111363, 107324, 107141, 106296, 107564, 111937, 110960, 105296, 107559, 105215, 107281, 114480, 105729, 106468, 114472, 108154, 113617, 106110, 106426, 111366, 105719, 105765, 105249, 102748, 105410, 110958, 110959, 105117, 111362, 106112, 107442, 114474, 112687);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(111364, 0, 25996),
(107471, 0, 25996),
(104694, 0, 25996),
(107435, 0, 25996),
(111365, 0, 25996),
(104695, 0, 25996),
(104400, 2, 25996),
(107486, 0, 25996),
(112697, 0, 25996),
(104696, 0, 25996),
(104245, 0, 25996),
(107472, 0, 25996),
(111367, 0, 25996),
(107151, 0, 25996),
(107470, 0, 25996),
(112699, 0, 25996),
(108406, 0, 25996),
(106024, 0, 25996),
(107756, 0, 25996),
(111372, 0, 25996),
(108419, 0, 25996),
(106032, 0, 25996),
(111363, 0, 25996),
(107324, 0, 25996),
(107141, 0, 25996),
(106296, 0, 25996),
(107564, 2, 25996),
(111937, 0, 25996),
(110960, 0, 25996),
(105296, 0, 25996),
(107559, 2, 25996),
(105215, 0, 25996),
(107281, 2, 25996),
(114480, 0, 25996),
(105729, 0, 25996),
(106468, 0, 25996),
(114472, 0, 25996),
(108154, 0, 25996),
(113617, 0, 25996),
(106110, 0, 25996),
(106426, 0, 25996),
(111366, 0, 25996),
(105719, 0, 25996),
(105765, 2, 25996),
(105249, 0, 25996),
(102748, 0, 25996),
(105410, 0, 25996),
(110958, 0, 25996),
(110959, 0, 25996),
(105117, 0, 25996),
(111362, 0, 25996),
(106112, 0, 25996),
(107442, 0, 25996),
(114474, 0, 25996),
(112687, 0, 25996);



UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70029;
UPDATE `creature_model_info` SET `BoundingRadius`=1.224653, `CombatReach`=5.85, `VerifiedBuild`=25996 WHERE `DisplayID`=71560;
UPDATE `creature_model_info` SET `BoundingRadius`=1.406043, `CombatReach`=2.6, `VerifiedBuild`=25996 WHERE `DisplayID`=70594;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6360515, `CombatReach`=1.4375, `VerifiedBuild`=25996 WHERE `DisplayID`=70583;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68764;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684871, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=72182;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123776, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=72185;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684871, `CombatReach`=1.704545, `VerifiedBuild`=25996 WHERE `DisplayID`=70096;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6106094, `CombatReach`=1.38, `VerifiedBuild`=25996 WHERE `DisplayID`=70033;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6106094, `CombatReach`=1.38, `VerifiedBuild`=25996 WHERE `DisplayID`=70035;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67001;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69927;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2819405, `VerifiedBuild`=25996 WHERE `DisplayID`=63538;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70123;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69467;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66579;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66278;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66560;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69032;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69492;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69054;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68765;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=68992;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28120;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28118;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=70534;
UPDATE `creature_model_info` SET `BoundingRadius`=1.338126, `VerifiedBuild`=25996 WHERE `DisplayID`=10925;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2883655, `VerifiedBuild`=25996 WHERE `DisplayID`=69609;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70080;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2015157, `VerifiedBuild`=25996 WHERE `DisplayID`=69533;
UPDATE `creature_model_info` SET `BoundingRadius`=1.13161, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=61928;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123776, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70102;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6106094, `CombatReach`=1.38, `VerifiedBuild`=25996 WHERE `DisplayID`=70076;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684872, `CombatReach`=1.630435, `VerifiedBuild`=25996 WHERE `DisplayID`=70090;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684871, `CombatReach`=1.744186, `VerifiedBuild`=25996 WHERE `DisplayID`=70100;
UPDATE `creature_model_info` SET `BoundingRadius`=1.665511, `CombatReach`=2.9325, `VerifiedBuild`=25996 WHERE `DisplayID`=70592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19976;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123777, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70098;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17035;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69965;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69964;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69967;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69976;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69973;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69971;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69974;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69977;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69961;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123777, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70092;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10923;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123777, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70103;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684871, `CombatReach`=1.666667, `VerifiedBuild`=25996 WHERE `DisplayID`=70095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62513;
UPDATE `creature_model_info` SET `BoundingRadius`=0.768487, `CombatReach`=1.5625, `VerifiedBuild`=25996 WHERE `DisplayID`=70091;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9889601, `CombatReach`=2.625, `VerifiedBuild`=25996 WHERE `DisplayID`=68418;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70089;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69975;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69968;
UPDATE `creature_model_info` SET `BoundingRadius`=1.852439, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=71814;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7834075, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69962;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6881899, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=69970;
UPDATE `creature_model_info` SET `BoundingRadius`=1.178756, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=71815;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8509513, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=70628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684871, `CombatReach`=1.079137, `VerifiedBuild`=25996 WHERE `DisplayID`=70101;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123776, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70115;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123777, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70093;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2883655, `VerifiedBuild`=25996 WHERE `DisplayID`=69610;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123776, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70114;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2015157, `VerifiedBuild`=25996 WHERE `DisplayID`=69606;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70079;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70030;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9018;
UPDATE `creature_model_info` SET `BoundingRadius`=1.942403, `CombatReach`=0.715, `VerifiedBuild`=25996 WHERE `DisplayID`=63588;
UPDATE `creature_model_info` SET `BoundingRadius`=7.1, `CombatReach`=2.13, `VerifiedBuild`=25996 WHERE `DisplayID`=68548;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=69267;
UPDATE `creature_model_info` SET `BoundingRadius`=1.077683, `CombatReach`=1.8975, `VerifiedBuild`=25996 WHERE `DisplayID`=70567;
UPDATE `creature_model_info` SET `BoundingRadius`=1.676435, `CombatReach`=3.1, `VerifiedBuild`=25996 WHERE `DisplayID`=68553;
UPDATE `creature_model_info` SET `BoundingRadius`=1.196869, `CombatReach`=1.8975, `VerifiedBuild`=25996 WHERE `DisplayID`=70566;
UPDATE `creature_model_info` SET `BoundingRadius`=2.002498, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=54282;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68554;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64620;
UPDATE `creature_model_info` SET `BoundingRadius`=1.196869, `CombatReach`=1.8975, `VerifiedBuild`=25996 WHERE `DisplayID`=70563;
UPDATE `creature_model_info` SET `BoundingRadius`=1.077683, `CombatReach`=1.8975, `VerifiedBuild`=25996 WHERE `DisplayID`=70564;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587033, `CombatReach`=1.685393, `VerifiedBuild`=25996 WHERE `DisplayID`=70036;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55561;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70562;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7123776, `CombatReach`=1.61, `VerifiedBuild`=25996 WHERE `DisplayID`=70097;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6106094, `CombatReach`=1.38, `VerifiedBuild`=25996 WHERE `DisplayID`=70075;
UPDATE `creature_model_info` SET `BoundingRadius`=2.19137, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69852;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587033, `CombatReach`=1.25, `VerifiedBuild`=25996 WHERE `DisplayID`=70081;
UPDATE `creature_model_info` SET `CombatReach`=1.293103, `VerifiedBuild`=25996 WHERE `DisplayID`=70082;
UPDATE `creature_model_info` SET `BoundingRadius`=1.196869, `CombatReach`=1.8975, `VerifiedBuild`=25996 WHERE `DisplayID`=70561;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6009315, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=70565;
UPDATE `creature_model_info` SET `CombatReach`=1.260504, `VerifiedBuild`=25996 WHERE `DisplayID`=70078;
UPDATE `creature_model_info` SET `BoundingRadius`=1.665511, `CombatReach`=2.9325, `VerifiedBuild`=25996 WHERE `DisplayID`=68521;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587033, `CombatReach`=1.271186, `VerifiedBuild`=25996 WHERE `DisplayID`=70039;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=23767;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587033, `CombatReach`=1.271186, `VerifiedBuild`=25996 WHERE `DisplayID`=70077;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587033, `CombatReach`=1.260504, `VerifiedBuild`=25996 WHERE `DisplayID`=70038;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587033, `CombatReach`=1.25, `VerifiedBuild`=25996 WHERE `DisplayID`=70037;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32263;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31774;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32265;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67726;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66257;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73503;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70880;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70138;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73756;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73413;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028736, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=61927;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71600;


UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1); -- Dague simple
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Poussière évanescente
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Coffret de calligraphie de virtuose
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Trousse de joaillier
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Parchemin léger
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Verroterie
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Fiole de cristal
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Fil d'éternium
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=32641 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Fil runique

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=106468 AND `ID`=1) OR (`CreatureID`=104278 AND `ID`=1) OR (`CreatureID`=104218 AND `ID`=1) OR (`CreatureID`=111563 AND `ID`=1) OR (`CreatureID`=104273 AND `ID`=1) OR (`CreatureID`=104217 AND `ID`=1) OR (`CreatureID`=104251 AND `ID`=1) OR (`CreatureID`=104247 AND `ID`=1) OR (`CreatureID`=104246 AND `ID`=1) OR (`CreatureID`=104215 AND `ID`=1) OR (`CreatureID`=116658 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(106468, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Ly'leth Lunastre
(104278, 1, 9425, 0, 0, 0, 0, 0, 0, 0, 0), -- Felbound Enforcer
(104218, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Advisor Melandrus
(111563, 1, 133176, 0, 0, 132249, 0, 0, 0, 0, 0), -- Duskwatch Guard
(104273, 1, 21856, 0, 0, 0, 0, 0, 0, 0, 0), -- Jazshariu
(104217, 1, 63538, 0, 0, 63538, 0, 0, 0, 0, 0), -- Talixae Flamewreath
(104251, 1, 9386, 0, 0, 15592, 0, 0, 0, 0, 0), -- Duskwatch Sentry
(104247, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Arcaniste de la Garde crépusculaire
(104246, 1, 133176, 0, 0, 132249, 0, 0, 0, 0, 0), -- Duskwatch Guard
(104215, 1, 40497, 0, 0, 0, 0, 0, 0, 0, 0), -- Patrol Captain Gerdo
(116658, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0); -- Felborne Conspirator

UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=114472 AND `ID`=1); -- Duskwatch Highblade
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=114474 AND `ID`=1); -- Hautelame de la Garde crépusculaire

DELETE FROM `gossip_menu` WHERE (`MenuId`=19764 AND `TextId`=29265) OR (`MenuId`=19722 AND `TextId`=29253) OR (`MenuId`=19748 AND `TextId`=29229) OR (`MenuId`=19749 AND `TextId`=29218) OR (`MenuId`=19754 AND `TextId`=29232) OR (`MenuId`=19755 AND `TextId`=29218) OR (`MenuId`=19730 AND `TextId`=29227) OR (`MenuId`=19731 AND `TextId`=29218) OR (`MenuId`=19515 AND `TextId`=28836);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(19764, 29265), -- 107435 (Suspicious Noble)
(19722, 29253), -- 106468 (Ly'leth Lunastre)
(19748, 29229), -- 107486 (Chatty Rumormonger)
(19749, 29218), -- 107486 (Chatty Rumormonger)
(19754, 29232), -- 107486 (Chatty Rumormonger)
(19755, 29218), -- 107486 (Chatty Rumormonger)
(19730, 29227), -- 107486 (Chatty Rumormonger)
(19731, 29218), -- 107486 (Chatty Rumormonger)
(19515, 28836); -- 105729 (Signal Lantern)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=19764 AND `OptionIndex`=0) OR (`MenuId`=19722 AND `OptionIndex`=0) OR (`MenuId`=19749 AND `OptionIndex`=0) OR (`MenuId`=19755 AND `OptionIndex`=0) OR (`MenuId`=19731 AND `OptionIndex`=0) OR (`MenuId`=19515 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(19764, 0, 0, 'Don''t be coy. I know you''re here to spy for the Grand Magistrix.', 111873),
(19722, 0, 0, 'Go ahead. I''m ready for my disguise.', 111838),
(19749, 0, 0, 'Go on...', 111872), -- OptionBroadcastTextID: 111872 - 127631
(19755, 0, 0, 'Go on...', 111872), -- OptionBroadcastTextID: 111872 - 127631
(19731, 0, 0, 'Go on...', 111872), -- OptionBroadcastTextID: 111872 - 127631
(19515, 0, 0, 'Send a signal to Ly''leth Lunastre.', 108581);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=19749 AND `OptionIndex`=0) OR (`MenuId`=19755 AND `OptionIndex`=0) OR (`MenuId`=19731 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(19749, 0, 19748, 0),
(19755, 0, 19754, 0),
(19731, 0, 19730, 0);



UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2097152, `unit_flags3`=1 WHERE `entry`=110443; -- Elisande
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=108406; -- Arcane Custodian
UPDATE `creature_template` SET `gossip_menu_id`=19722, `minlevel`=98, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=6293504 WHERE `entry`=106468; -- Ly'leth Lunastre
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=110959; -- Wealthy Elite
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=110960; -- Haughty Aristocrat
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=112697; -- Suspicious Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=112699; -- Suspicious Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=107756; -- Estate Attendant
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=110958; -- Fancy Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=105410; -- Suramar Musician
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=34816, `unit_flags3`=1 WHERE `entry`=106112; -- Wounded Nightborne Civilian
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200, `VehicleId`=4770 WHERE `entry`=107281; -- Eye Storm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.2, `speed_run`=0.07142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=107291; -- Watchful Oculus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=110560; -- Vanthir
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=106024; -- Magical Lantern
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111937; -- Dusk Lily Agent
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=106296; -- Dusk Lily Agent
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=105215; -- Discarded Junk
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=106110; -- Waterlogged Scroll
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=105249; -- Nightshade Refreshments
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=6293504 WHERE `entry`=104278; -- Felbound Enforcer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872, `VehicleId`=4695 WHERE `entry`=107559; -- Conversation Stalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=105117; -- Flask of the Solemn Night
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=108419; -- Automated Sweeper
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=105719; -- Mana Saber
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4721 WHERE `entry`=104218; -- Advisor Melandrus
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2131968 WHERE `entry`=105765; -- Gale Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=108740; -- Velimar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104295; -- Blazing Imp
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104300; -- Shadow Mistress
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=107471; -- Wealthy Elite
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111362; -- Nightborne Boat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104277; -- Legion Hound
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200, `VehicleId`=25 WHERE `entry`=105715; -- Watchful Inquisitor
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=6293504 WHERE `entry`=107442; -- Suspicious Suramar Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111364; -- Nightborne Supplies
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111365; -- Nightborne Supplies
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `npcflag`=1, `speed_walk`=1.6, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=6293504 WHERE `entry`=107435; -- Suspicious Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111366; -- Nightborne Supplies
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111363; -- Nightborne Supplies
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=107472; -- Fancy Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=104695; -- Suramar Merchant
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=107470; -- Haughty Aristocrat
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `npcflag`=1, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=6293504 WHERE `entry`=107486; -- Chatty Rumormonger
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=107324; -- Suramar Child
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=104694; -- Suramar Citizen
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113617; -- Dusk Lily Agent
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111563; -- Duskwatch Guard
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=2.142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=104273; -- Jazshariu
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=2.857143, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=104274; -- Baalgar the Watchful
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=2.857143, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=104275; -- Imacu'tya
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=16777216, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=104245; -- Arcane Beacon
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=2.857143, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=104217; -- Talixae Flamewreath
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104251; -- Duskwatch Sentry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105704; -- Arcane Manifestation
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=104270; -- Guardian Construct
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105699; -- Mana Saber
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104247; -- Arcaniste de la Garde crépusculaire
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105705; -- Bound Energy
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=104696; -- Suramar Civilian
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=4196352 WHERE `entry`=107151; -- Suramar Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=4196352, `VehicleId`=4765 WHERE `entry`=107141; -- Nightborne Boat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104246; -- Duskwatch Guard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105703; -- Mana Wyrm
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872, `VehicleId`=4695 WHERE `entry`=107564; -- Conversation Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `VehicleId`=4667 WHERE `entry`=104215; -- Patrol Captain Gerdo
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=104400; -- Resonant Stalker
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111372; -- Suramar Dockworker
UPDATE `creature_template` SET `gossip_menu_id`=19515, `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=105729; -- Signal Lantern
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2099200 WHERE `entry`=111367; -- Suramar Dockworker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `speed_walk`=1.2, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=111575; -- Overgrown Eel
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `speed_walk`=1.2, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=111572; -- Engorged Manafeeder
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106032; -- Duskwatch Battlemaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114472; -- Duskwatch Highblade
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114474; -- Hautelame de la Garde crépusculaire
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=71305216, `VehicleId`=5014 WHERE `entry`=114960; -- Felsoul Ferry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2886, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=116658; -- Felborne Conspirator
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106919; -- Nightborne Courier
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=115338; -- Rebellious Citizen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114527; -- Timid Shopkeeper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102748; -- Tamed Manasaber
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114480; -- Observateur de la Garde crépusculaire

SET @GROUP_ID := 0;
SET @ID := 0;

INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(104215, @GROUP_ID+0, @ID+0, 'No trespassers allowed!', 14, 0, 100, 0, 0, 58627, 108480, 'Patrol Captain Gerdo to Player'),
(104215, @GROUP_ID+1, @ID+0, 'Guards! To me!', 14, 0, 100, 0, 0, 58637, 108973, 'Patrol Captain Gerdo'),
(104215, @GROUP_ID+2, @ID+0, '|TInterface\\Icons\\ability_socererking_arcaneacceleration|t%s begins to cast |cFFFF0000|Hspell:207278|h[Arcane Lockdown]|h|r! Jump to remove the effect!', 41, 0, 100, 0, 0, 0, 111983, 'Patrol Captain Gerdo'),
(104215, @GROUP_ID+3, @ID+0, 'This will even the odds!', 14, 0, 100, 0, 0, 58629, 108488, 'Patrol Captain Gerdo'),
(104215, @GROUP_ID+4, @ID+0, 'My watch... is ended.', 14, 0, 100, 0, 0, 58628, 108484, 'Patrol Captain Gerdo to Player'),
(104217, @GROUP_ID+0, @ID+0, 'Make yourself useful and take a look around!', 14, 0, 100, 0, 0, 58644, 108509, 'Talixae Flamewreath to Felbound Enforcer'),
(104217, @GROUP_ID+1, @ID+0, 'What are you waiting for? Check out that noise!', 14, 0, 100, 0, 0, 58645, 108510, 'Talixae Flamewreath to Felbound Enforcer'),
(104217, @GROUP_ID+2, @ID+0, 'You! Have a look over there!', 14, 0, 100, 0, 0, 58646, 108512, 'Talixae Flamewreath to Felbound Enforcer'),
(104217, @GROUP_ID+3, @ID+0, 'Who needs henchmen? I''ll burn you myself!', 14, 0, 100, 0, 0, 58639, 108517, 'Talixae Flamewreath to Player'),
(104217, @GROUP_ID+4, @ID+0, 'It will amuse me to watch you melt!', 14, 0, 100, 0, 0, 58642, 108516, 'Talixae Flamewreath'),
(104217, @GROUP_ID+5, @ID+0, 'My funeral pyre... will be... glorious...', 14, 0, 100, 0, 0, 58643, 108507, 'Talixae Flamewreath to Player'),
(104218, @GROUP_ID+0, @ID+0, 'Must you leave so soon, Grand Magistrix?', 12, 0, 100, 0, 0, 67729, 117105, 'Advisor Melandrus to Player'),
(104218, @GROUP_ID+1, @ID+0, 'Impossible! My guards would never permit such an intrusion!', 12, 0, 100, 0, 0, 67728, 117088, 'Advisor Melandrus to Player'),
(104218, @GROUP_ID+2, @ID+0, 'Finally. I''ll make this quick.', 14, 0, 100, 0, 0, 58650, 108987, 'Advisor Melandrus to Player'),
(104218, @GROUP_ID+3, @ID+0, 'I will speed you towards your demise!', 14, 0, 100, 0, 0, 58653, 108997, 'Advisor Melandrus'),
(104218, @GROUP_ID+4, @ID+0, 'Bleed for the Grand Magistrix!', 14, 0, 100, 0, 0, 58657, 108995, 'Advisor Melandrus'),
(104218, @GROUP_ID+5, @ID+0, 'Death by a thousand cuts!', 14, 0, 100, 0, 0, 58656, 108994, 'Advisor Melandrus'),
(104218, @GROUP_ID+6, @ID+0, 'If you blink... you bleed!', 14, 0, 100, 0, 0, 58654, 108998, 'Advisor Melandrus'),
(104218, @GROUP_ID+7, @ID+0, 'Elisande... forgive me!', 14, 0, 100, 0, 0, 58658, 109002, 'Advisor Melandrus to Player'),
(104251, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\INV_Misc_Bell_01:20|tA %s has been alerted to your presence!', 41, 0, 100, 0, 0, 0, 109269, 'Duskwatch Sentry to Player'),
(104278, @GROUP_ID+0, @ID+0, 'The Legion.. will prevail!', 14, 0, 100, 0, 0, 71114, 109577, 'Felbound Enforcer to Player'),
(104278, @GROUP_ID+1, @ID+0, 'You will never stop our plans!', 14, 0, 100, 0, 0, 71111, 109580, 'Felbound Enforcer to Player'),
(104694, @GROUP_ID+0, @ID+0, 'Hey, keep it down out there! We''re trying to have a party!', 14, 0, 100, 0, 0, 0, 116332, 'Suramar Citizen to Player'),
(104694, @GROUP_ID+1, @ID+0, 'Outsiders!', 12, 0, 100, 0, 0, 0, 121049, 'Suramar Citizen'),
(104694, @GROUP_ID+2, @ID+0, '%s runs away in terror!', 16, 0, 100, 0, 0, 0, 121586, 'Suramar Citizen to Watchful Inquisitor'),
(104695, @GROUP_ID+0, @ID+0, 'Intruders!', 12, 0, 100, 1, 0, 0, 121052, 'Suramar Merchant'),
(104696, @GROUP_ID+0, @ID+0, 'Run! They have weapons!', 12, 0, 100, 0, 0, 0, 121053, 'Suramar Civilian'),
(105296, @GROUP_ID+0, @ID+0, 'Your arrival is fortuitous. Tonight, the nobles have gathered in honor of the Grand Magistrix.', 12, 0, 100, 396, 0, 70446, 108582, 'Ly''leth Lunastre to Player'),
(105296, @GROUP_ID+1, @ID+0, 'Our spies report that Elisande herself will attend. This presents a rare opportunity to catch her away from her source of power.', 12, 0, 100, 396, 0, 70447, 108583, 'Ly''leth Lunastre to Player'),
(105296, @GROUP_ID+2, @ID+0, 'We''ll take a side entrance to the grounds... too many eyes are watching the front.', 12, 0, 100, 396, 0, 70448, 108584, 'Ly''leth Lunastre to Player'),
(105296, @GROUP_ID+3, @ID+0, 'This is your best chance to eliminate the Grand Magistrix. Good luck!', 12, 0, 100, 396, 0, 70449, 108586, 'Ly''leth Lunastre to Player'),
(106468, @GROUP_ID+0, @ID+0, 'You''ve done well so far, but we must ensure you blend in at the party. I''ll enhance your disguise, infusing it with latent magic to make you appear as one of the nobles.', 12, 0, 100, 396, 0, 70450, 108585, 'Ly''leth Lunastre'),
(107324, @GROUP_ID+0, @ID+0, 'How did you get in here?', 12, 0, 100, 11, 0, 0, 121051, 'Suramar Child'),
(107435, @GROUP_ID+0, @ID+0, 'You insult my honor, $n. Who exactly are you?', 12, 0, 100, 463, 0, 0, 111881, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+1, @ID+0, '$n, you think I would spy on my own? Maybe we should look closer at you instead!', 12, 0, 100, 463, 0, 0, 111882, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+2, @ID+0, 'How dare you accuse me of such a thing, $n? Do you know who I am? I don''t recognize you at all...', 12, 0, 100, 463, 0, 0, 111874, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+3, @ID+0, 'Well I never! $n, who do you think you are?!', 12, 0, 100, 463, 0, 0, 111883, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+4, @ID+0, 'Now now, let''s not be hasty $n. Why don''t you follow me so we can talk about this in a more private setting...', 12, 0, 100, 0, 0, 0, 111875, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+5, @ID+0, 'I don''t know how you found me out, but now it''s time to die!', 12, 0, 100, 274, 0, 0, 111886, 'Suspicious Noble to Player'),
(110443, @GROUP_ID+0, @ID+0, 'Do you expect me to waste time chattering with vapid nobles even as my enemies close in? Look there, you fool! We are not alone.', 12, 0, 100, 0, 0, 67614, 117106, 'Elisande to Player'),
(110443, @GROUP_ID+1, @ID+0, 'Yet another failure, Melandrus. Consider this your chance to correct it. Dispose of these outsiders. I must return to the Nighthold.', 12, 0, 100, 0, 0, 67613, 117104, 'Elisande to Player'),
(110958, @GROUP_ID+0, @ID+0, 'You know, there are times I feel that the commoners don''t properly appreciate us.', 12, 0, 100, 1, 0, 0, 118924, 'Fancy Noble'),
(110958, @GROUP_ID+1, @ID+0, 'I saw Spellblade Aluriel pacing about. She always seems so... angry.', 12, 0, 100, 1, 0, 0, 118920, 'Fancy Noble');


UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112687; -- Enveloping Winds
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105754; -- Image of Advisor Melandrus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108154; -- Arcane Keys
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108151; -- Gerenth the Vile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110443; -- Elisande
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108406; -- Arcane Custodian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106468; -- Ly'leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121643; -- Flame Rift
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95160; -- Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94584; -- Unstable Tear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108493; -- Chaos Tear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99887; -- Shadowy Tear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106426; -- Disturbance
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110960; -- Haughty Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110959; -- Wealthy Elite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112699; -- Suspicious Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112697; -- Suspicious Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107756; -- Estate Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110958; -- Fancy Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105410; -- Suramar Musician
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111936; -- Thal'kiel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111374; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106112; -- Wounded Nightborne Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107291; -- Watchful Oculus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107281; -- Eye Storm
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=25996 WHERE `entry`=10259; -- Jeune worg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106585; -- Watchful Oculus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106584; -- Watchful Oculus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106586; -- Watchful Oculus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110560; -- Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106024; -- Magical Lantern
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111937; -- Dusk Lily Agent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106296; -- Dusk Lily Agent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105215; -- Discarded Junk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106110; -- Waterlogged Scroll
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105249; -- Nightshade Refreshments
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104278; -- Felbound Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107559; -- Conversation Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104918; -- Vigilant Duskwatch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104384; -- Resonant Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105117; -- Flask of the Solemn Night
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47649; -- Efflorescence
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=52831; -- Bébé de Berceau-de-l’Hiver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108419; -- Automated Sweeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105719; -- Mana Saber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105734; -- Ly'leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104218; -- Advisor Melandrus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105765; -- Gale Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108740; -- Velimar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104295; -- Blazing Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107442; -- Suspicious Suramar Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104277; -- Legion Hound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107471; -- Wealthy Elite
UPDATE `creature_template` SET `modelid1`=69852, `VerifiedBuild`=25996 WHERE `entry`=111362; -- Nightborne Boat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104300; -- Shadow Mistress
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105715; -- Watchful Inquisitor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107435; -- Suspicious Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111365; -- Nightborne Supplies
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111364; -- Nightborne Supplies
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111366; -- Nightborne Supplies
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111363; -- Nightborne Supplies
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107472; -- Fancy Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107470; -- Haughty Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104695; -- Suramar Merchant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107486; -- Chatty Rumormonger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107324; -- Suramar Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104694; -- Suramar Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113617; -- Dusk Lily Agent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111563; -- Duskwatch Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104275; -- Imacu'tya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104274; -- Baalgar the Watchful
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104217; -- Talixae Flamewreath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104273; -- Jazshariu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104245; -- Arcane Beacon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104251; -- Duskwatch Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105704; -- Arcane Manifestation
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104270; -- Guardian Construct
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105699; -- Mana Saber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104247; -- Arcaniste de la Garde crépusculaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105705; -- Bound Energy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104696; -- Suramar Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107141; -- Nightborne Boat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107151; -- Suramar Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105296; -- Ly'leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105703; -- Mana Wyrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104246; -- Duskwatch Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105264; -- Nightborne Boat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104215; -- Patrol Captain Gerdo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107564; -- Conversation Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104400; -- Resonant Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111372; -- Suramar Dockworker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111367; -- Suramar Dockworker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111575; -- Overgrown Eel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111572; -- Engorged Manafeeder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94986; -- Fleshrender Roc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94983; -- Sorcière du ciel folfurie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95270; -- Ours ensorcelé
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95310; -- Harpie sorcebois
UPDATE `creature_template` SET `KillCredit1`=117806, `VerifiedBuild`=25996 WHERE `entry`=97919; -- Swamprock Marshstomper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98311; -- Mrrklr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94358; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105729; -- Signal Lantern
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=54441; -- Thaumaturge Vashreen
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=34337; -- The Postmaster

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=104218 AND `Idx`=4) OR (`CreatureEntry`=97919 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(104218, 4, 146680, 25996), -- Advisor Melandrus
(97919, 0, 143840, 25996); -- Swamprock Marshstomper

UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104218 AND `Idx`=3); -- Advisor Melandrus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104218 AND `Idx`=2); -- Advisor Melandrus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104218 AND `Idx`=1); -- Advisor Melandrus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104218 AND `Idx`=0); -- Advisor Melandrus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104277 AND `Idx`=1); -- Legion Hound
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104277 AND `Idx`=0); -- Legion Hound
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105699 AND `Idx`=2); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105699 AND `Idx`=1); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105699 AND `Idx`=0); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105703 AND `Idx`=0); -- Mana Wyrm
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104215 AND `Idx`=0); -- Patrol Captain Gerdo
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=94986 AND `Idx`=0); -- Fleshrender Roc
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95270 AND `Idx`=4); -- Ours ensorcelé
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95270 AND `Idx`=3); -- Ours ensorcelé
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95270 AND `Idx`=2); -- Ours ensorcelé
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95270 AND `Idx`=1); -- Ours ensorcelé
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95270 AND `Idx`=0); -- Ours ensorcelé
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95310 AND `Idx`=0); -- Harpie sorcebois

DELETE FROM `gameobject_template` WHERE `entry` IN (250623 /*Chair*/, 250622 /*Chair*/, 250621 /*Chair*/, 250617 /*Chair*/, 250616 /*Chair*/, 250615 /*Chair*/, 250614 /*Chair*/, 250620 /*Chair*/, 250613 /*Chair*/, 250619 /*Chair*/, 250618 /*Chair*/, 250625 /*Doodad_7NB_Nightborn_Harp002*/, 250624 /*Doodad_7NB_Nightborn_Harp001*/, 253047 /*Nightborne Goods*/, 253046 /*Nightborne Goods*/, 252967 /*Nightborne Goods*/, 252966 /*Nightborne Bazaar*/, 252968 /*Nightborne Goods*/, 246805 /*Fel Fire*/, 251848 /*Skyward Terrace*/, 251847 /*Manor Door*/, 251846 /*House Door*/, 253922 /*Apprentice's Door*/, 251849 /*Waypoint Door*/, 249386 /*Arcane Barrier*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(250623, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250622, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250621, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250617, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250616, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250615, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250614, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250620, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250613, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250619, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250618, 7, 34334, 'Chair', '', '', '', 1.1548, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(250625, 5, 34335, 'Doodad_7NB_Nightborn_Harp002', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7NB_Nightborn_Harp002
(250624, 5, 34335, 'Doodad_7NB_Nightborn_Harp001', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7NB_Nightborn_Harp001
(253047, 5, 36175, 'Nightborne Goods', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Goods
(253046, 5, 36174, 'Nightborne Goods', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Goods
(252967, 5, 34494, 'Nightborne Goods', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Goods
(252966, 5, 36120, 'Nightborne Bazaar', '', '', '', 1.1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Bazaar
(252968, 5, 36121, 'Nightborne Goods', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Goods
(246805, 5, 31732, 'Fel Fire', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fel Fire
(251848, 0, 35528, 'Skyward Terrace', '', '', '', 1.202818, 0, 1845, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Skyward Terrace
(251847, 0, 35528, 'Manor Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Manor Door
(251846, 0, 35527, 'House Door', '', '', '', 0.7738997, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- House Door
(253922, 0, 35527, 'Apprentice''s Door', '', '', '', 0.3506287, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Apprentice's Door
(251849, 0, 35528, 'Waypoint Door', '', '', '', 0.7524738, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Waypoint Door
(249386, 0, 10403, 'Arcane Barrier', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Arcane Barrier

UPDATE `gameobject_template` SET `size`=3.5, `VerifiedBuild`=25996 WHERE `entry`=233778; -- Collision PC Size
UPDATE `gameobject_template` SET `name`='Meeting Stone', `VerifiedBuild`=25996 WHERE `entry`=253955; -- Meeting Stone

DELETE FROM `npc_text` WHERE `ID` IN (29229 /*29229*/, 29232 /*29232*/, 29265 /*29265*/, 29227 /*29227*/, 29218 /*29218*/, 29253 /*29253*/, 28836 /*28836*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(29229, 1, 1, 1, 1, 0, 0, 0, 0, 111717, 111718, 111719, 111720, 0, 0, 0, 0, 25996), -- 29229
(29232, 1, 1, 0, 0, 0, 0, 0, 0, 111756, 111757, 0, 0, 0, 0, 0, 0, 25996), -- 29232
(29265, 1, 1, 1, 1, 0, 0, 0, 0, 111876, 111878, 111879, 111880, 0, 0, 0, 0, 25996), -- 29265
(29227, 1, 1, 1, 1, 0, 0, 0, 0, 111701, 111702, 111703, 111704, 0, 0, 0, 0, 25996), -- 29227
(29218, 1, 1, 1, 1, 1, 1, 1, 1, 111690, 111691, 111692, 111693, 111694, 111695, 111696, 111697, 25996), -- 29218
(29253, 1, 0, 0, 0, 0, 0, 0, 0, 111837, 0, 0, 0, 0, 0, 0, 0, 25996), -- 29253
(28836, 1, 0, 0, 0, 0, 0, 0, 0, 108580, 0, 0, 0, 0, 0, 0, 0, 25996); -- 28836


