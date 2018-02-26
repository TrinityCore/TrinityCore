DELETE FROM `areatrigger_template` WHERE `Id`=15101;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(15101, 0, 0, 1, 1, 0, 0, 0, 0, 25996);

UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=2.5, `Data2`=3, `Data3`=2.5, `Data4`=2.5, `Data5`=3 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10688;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=7657;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=7856;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11513;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=6000 AND `AreaTriggerId`=10688) OR (`SpellMiscId`=3178 AND `AreaTriggerId`=7856) OR (`SpellMiscId`=10228 AND `AreaTriggerId`=15101);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(6000, 10688, 0, 0, 0, 0, 0, 0, 30000, 25996), -- SpellId : 204159
(3178, 7856, 0, 0, 0, 0, 0, 0, 15000, 25996), -- SpellId : 172828
(10228, 15101, 0, 0, 0, 0, 0, 0, 6000, 25996); -- SpellId : 240692

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8724 AND `AreaTriggerId`=12802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5972 AND `AreaTriggerId`=10660); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3023 AND `AreaTriggerId`=7657); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=15000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3023 AND `AreaTriggerId`=7657); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11941, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11444, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11886, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8726, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11136, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7763, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10544, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10344, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7921, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11189, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11482, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10232, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10770, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10631, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10690, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11111, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10295, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8448 AND `AreaTriggerId`=12599); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10428, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10619, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9171, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9145, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9843, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9404, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10497, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10575, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10240, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8966, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9004, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9979, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8927, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10378, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9441, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=90000 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=6710 AND `AreaTriggerId`=11266); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7992, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8485, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10860, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10570, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10950, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11231, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9285, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9155, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9319, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1817, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10472, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10646, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1785, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1691, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8919, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11120, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10510, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10696, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10322, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9318, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9289, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10395, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10157, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9544, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9188, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=14000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7044 AND `AreaTriggerId`=11513); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=3436 AND `ConversationActorId`=54980 AND `Idx`=0) OR (`ConversationId`=3855 AND `Idx`=1) OR (`ConversationId`=3855 AND `Idx`=0) OR (`ConversationId`=3435 AND `ConversationActorId`=54980 AND `Idx`=0) OR (`ConversationId`=2417 AND `ConversationActorId`=49527 AND `Idx`=0) OR (`ConversationId`=3430 AND `ConversationActorId`=54981 AND `Idx`=1) OR (`ConversationId`=3430 AND `ConversationActorId`=54980 AND `Idx`=0) OR (`ConversationId`=2421 AND `ConversationActorId`=49527 AND `Idx`=0) OR (`ConversationId`=3439 AND `Idx`=0) OR (`ConversationId`=2415 AND `ConversationActorId`=49527 AND `Idx`=0) OR (`ConversationId`=3852 AND `Idx`=0) OR (`ConversationId`=3437 AND `ConversationActorId`=54980 AND `Idx`=0) OR (`ConversationId`=2418 AND `ConversationActorId`=49527 AND `Idx`=0) OR (`ConversationId`=3989 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=3434 AND `ConversationActorId`=54980 AND `Idx`=0) OR (`ConversationId`=2416 AND `ConversationActorId`=49527 AND `Idx`=0) OR (`ConversationId`=3433 AND `ConversationActorId`=54980 AND `Idx`=0) OR (`ConversationId`=2768 AND `ConversationActorId`=51109 AND `Idx`=0) OR (`ConversationId`=1806 AND `Idx`=1) OR (`ConversationId`=1806 AND `Idx`=0) OR (`ConversationId`=3278 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=3277 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=3429 AND `Idx`=257) OR (`ConversationId`=3429 AND `Idx`=1) OR (`ConversationId`=3429 AND `Idx`=0) OR (`ConversationId`=1282 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(3436, 54980, 0, 25996),
-- (3855, UNKNOWN, 1, 25996), -- Full: 0x203CC89880701B40001DA10000104ADB Creature/0 R3890/S7585 Map: Îles Brisées Entry: 114797 (Angus Stormbrew) Low: 1067739
-- (3855, UNKNOWN, 0, 25996), -- Full: 0x203CC89880656B00001DA10000104ADB Creature/0 R3890/S7585 Map: Îles Brisées Entry: 103852 (Brambley Morrison) Low: 1067739
(3435, 54980, 0, 25996),
(2417, 49527, 0, 25996),
(3430, 54981, 1, 25996),
(3430, 54980, 0, 25996),
(2421, 49527, 0, 25996),
-- (3439, UNKNOWN, 0, 25996), -- Full: 0x2016FCCB406B7640004FAC0000903350 Creature/0 R1471/S20396 Map: L’Effondrement - Scénario de Suramar Entry: Télémancien en chef Oculeth Low: 9450320
(2415, 49527, 0, 25996),
-- (3852, UNKNOWN, 0, 25996), -- Full: 0x203CC89880701B40001DA100009044BD Creature/0 R3890/S7585 Map: Îles Brisées Entry: 114797 (Angus Stormbrew) Low: 9454781
(3437, 54980, 0, 25996),
(2418, 49527, 0, 25996),
(3989, 53609, 0, 25996),
(3434, 54980, 0, 25996),
(2416, 49527, 0, 25996),
(3433, 54980, 0, 25996),
(2768, 51109, 0, 25996),
-- (1806, UNKNOWN, 1, 25996), -- Full: 0x2016F4B6406257400060AC000010557A Creature/0 R1469/S24748 Map: Repaire de Neltharion Entry: Marcheur des esprits Corne-d’Ebène Low: 1070458
-- (1806, UNKNOWN, 0, 25996), -- Full: 0x2016F4B6406257000060AC0000105579 Creature/0 R1469/S24748 Map: Repaire de Neltharion Entry: 100700 (Navarrogg) Low: 1070457
(3278, 53609, 0, 25996),
(3277, 53609, 0, 25996);
-- (3429, UNKNOWN, 257, 25996), -- Full: 0x2016FCCB406B7640004FAC0000103350 Creature/0 R1471/S20396 Map: L’Effondrement - Scénario de Suramar Entry: Télémancien en chef Oculeth Low: 1061712
-- (3429, UNKNOWN, 1, 25996), -- Full: 0x2016FCCB406B7640004FAC0000103350 Creature/0 R1471/S20396 Map: L’Effondrement - Scénario de Suramar Entry: Télémancien en chef Oculeth Low: 1061712
-- (3429, UNKNOWN, 0, 25996), -- Full: 0x2016FCCB406A7400004FAC0000103350 Creature/0 R1471/S20396 Map: L’Effondrement - Scénario de Suramar Entry: 109008 (First Arcanist Thalyssra) Low: 1061712
-- (1282, UNKNOWN, 0, 25996); -- Full: 0x203CC89880618C80001DA100001044B4 Creature/0 R3890/S7585 Map: Îles Brisées Entry: 99890 (Lyana Darksorrow) Low: 1066164


DELETE FROM `conversation_actor_template` WHERE `Id` IN (54980, 54981);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(54980, 109008, 65100, 25996),
(54981, 110041, 65843, 25996);

UPDATE `conversation_actor_template` SET `CreatureId`=115099, `CreatureModelId`=61971 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=97140, `CreatureModelId`=65100 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=97140, `CreatureModelId`=65100 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=97140, `CreatureModelId`=65100 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=115099, `CreatureModelId`=61971 WHERE `Id`=53609;

DELETE FROM `conversation_line_template` WHERE `Id` IN (7210, 8756, 8755, 8754, 8753, 8752, 8751, 7209, 5126, 7202, 7201, 5132, 7213, 5124, 8736, 7211, 5127, 9107, 7208, 5125, 7207, 5757, 5756, 6914, 6913, 7200, 7196, 7195, 7194, 3008);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(7210, 0, 576, 0, 0, 25996),
(8756, 12700, 0, 1, 0, 25996),
(8755, 10400, 0, 0, 0, 25996),
(8754, 9100, 0, 1, 0, 25996),
(8753, 5800, 0, 0, 0, 25996),
(8752, 2300, 0, 1, 0, 25996),
(8751, 0, 0, 0, 0, 25996),
(7209, 0, 576, 0, 0, 25996),
(5126, 0, 577, 0, 0, 25996),
(7202, 3810, 574, 1, 0, 25996),
(7201, 0, 576, 0, 0, 25996),
(5132, 0, 577, 0, 0, 25996),
(7213, 0, 393649336, 0, 0, 25996),
(5124, 0, 577, 0, 0, 25996),
(8736, 0, 0, 0, 0, 25996),
(7211, 0, 576, 0, 0, 25996),
(5127, 0, 577, 0, 0, 25996),
(9107, 0, 120, 0, 0, 25996),
(7208, 0, 576, 0, 0, 25996),
(5125, 0, 577, 0, 0, 25996),
(7207, 0, 576, 0, 0, 25996),
(5757, 5340, 575, 0, 0, 25996),
(5756, 0, 575, 0, 0, 25996),
(6914, 0, 576, 0, 0, 25996),
(6913, 0, 576, 0, 0, 25996),
(7200, 22628, 163590308, 257, 0, 25996),
(7196, 17350, 163590308, 1, 0, 25996),
(7195, 8600, 163590308, 0, 0, 25996),
(7194, 0, 163590308, 0, 0, 25996),
(3008, 0, 4044157920, 0, 0, 25996);


DELETE FROM `conversation_template` WHERE `Id` IN (2768, 3989, 3855, 3852, 1282, 3278, 3277, 2421, 2418, 2417, 2416, 2415, 3437, 3439, 3433, 3436, 3434, 3435, 3430, 3429);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(2768, 5756, 11581, 25996),
(3989, 9107, 9683, 25996),
(3855, 8751, 15550, 25996),
(3852, 8736, 3600, 25996),
(1282, 3008, 4046, 25996),
(3278, 6914, 5568, 25996),
(3277, 6913, 12415, 25996),
(2421, 5132, 4551, 25996),
(2418, 5127, 5606, 25996),
(2417, 5126, 6962, 25996),
(2416, 5125, 6568, 25996),
(2415, 5124, 8323, 25996),
(3437, 7211, 6083, 25996),
(3439, 7213, 3734, 25996),
(3433, 7207, 5024, 25996),
(3436, 7210, 6140, 25996),
(3434, 7208, 5174, 25996),
(3435, 7209, 2200, 25996),
(3430, 7201, 8136, 25996),
(3429, 7194, 22628, 25996);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (247027 /*Legion Portal*/, 265437 /*Doodad_7sr_hubmanatree002*/, 258977 /*Telemancy Beacon*/, 251785 /*Sealed Door*/, 260549 /*Invisible Door*/, 259239 /*Sealed Door*/, 258976 /*Telemancy Beacon*/, 251781 /*Sealed Door*/, 251783 /*Sealed Door*/, 251777 /*Sealed Door*/, 251778 /*Sealed Door*/, 251779 /*Sealed Door*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(247027, 0, 262144), -- Legion Portal
(265437, 0, 8192), -- Doodad_7sr_hubmanatree002
(258977, 0, 262144), -- Telemancy Beacon
(251785, 114, 32), -- Sealed Door
(260549, 0, 16), -- Invisible Door
(259239, 0, 34), -- Sealed Door
(258976, 0, 262144), -- Telemancy Beacon
(251781, 0, 34), -- Sealed Door
(251783, 0, 34), -- Sealed Door
(251777, 0, 34), -- Sealed Door
(251778, 0, 34), -- Sealed Door
(251779, 0, 34); -- Sealed Door

UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=241634; -- Medium Metal Scrap
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=241635; -- Large Metal Scrap
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=241633; -- Small Metal Scrap
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251493; -- Shadefruit
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251492; -- Purified Water
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251494; -- Silver Jasmine
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=251771; -- Fel Engine Injector
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247398; -- Soul Vaults Keyring
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=249344; -- Fragile Demonsbreath Crucible
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=251774; -- Soul Configuration Matrix
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=254008; -- Kyrtos's Research Notes
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=245245; -- Vengeful Warglaive
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247339; -- Chest of Shrouds
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=251035; -- Private Correspondence
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=251034; -- Stack of Arcane Tomes
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=251032; -- Armoire
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=251046; -- Basket of Clothing
UPDATE `gameobject_template_addon` SET `flags`=2375680 WHERE `entry`=260493; -- Mana-Infused Gem
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=251033; -- Facade
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252806; -- Small Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2375680 WHERE `entry`=252774; -- Ancient Mana Crystal
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=245507; -- Supply Cache

DELETE FROM `spell_target_position` WHERE (`ID`=203986 AND `EffectIndex`=0) OR (`ID`=196971 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(203986, 0, 1220, 664.96, 4822.75, -90.06, 25996), -- Spell: Téléportation vers le vaisseau de la Légion Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(196971, 0, 1220, 312.84, 4928.55, -85.18, 25996); -- Spell: Invocation Efffect: 28 (SPELL_EFFECT_SUMMON)

UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=223149 AND `EffectIndex`=2);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=217309 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=216980 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=221364 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=187753 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=203985 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=217765 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=224669 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=212534 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (110504 /*Bébé marche-neige*/, 94877 /*Brogrul le Puissant*/, 100559 /*100559 (Lassa Skymane)*/, 110503 /*110503 (Young Snowstrider) - Cosmetic - Sleep Zzz*/, 110502 /*110502 (Snowstrider Bull)*/, 113598 /*113598 (Highmountain Protector)*/, 113594 /*113594 (Drogbar)*/, 113592 /*113592 (Highmountain Protector)*/, 116458 /*116458 (Barrels o' Fun)*/, 109411 /*109411 (Shadescale Flyeater)*/, 112076 /*Gardien du vignoble*/, 112653 /*112653 (Sylverin)*/, 108872 /*Margaux*/, 108870 /*108870 (Sylverin)*/, 113487 /*113487 (Menagerie Shopkeeper)*/, 109657 /*109657 (Domesticated Screecher)*/, 109655 /*109655 (Conjured Familiar)*/, 110998 /*110998 (Instructor Solag)*/, 111012 /*111012 (Incinerator Evixa)*/, 110957 /*110957 (Commander Vigrox)*/, 111002 /*111002 (Doombringer Sinarus)*/, 110955 /*110955 (Hulking Shocktrooper)*/, 111006 /*111006 (Felblaze Dominator)*/, 113705 /*113705 (Loyalist Sycophant)*/, 113702 /*113702 (Loyalist Spellblade)*/, 111003 /*111003 (Lady Covix)*/, 113703 /*113703 (Loyalist Magus)*/, 110999 /*110999 (Felsword Adept)*/, 111013 /*111013 (Felsoul Champion)*/, 111065 /*111065 (Menagerie Keeper)*/, 111062 /*111062 (Su'esh)*/, 111019 /*111019 (Nighteyes) - Camouflage*/, 109145 /*109145 (Lunastre Attendant) - Plateau - homme*/, 109144 /*Ly’leth Lunastre*/, 109114 /*109114 (Palanquin) - Costume de palanquin*/, 110987 /*110987 (Nighteyes)*/, 113485 /*113485 (Menagerie Shopkeeper)*/, 109158 /*109158 (Underglow Locust)*/, 104161 /*104161 (Brambley Morrison)*/, 114797 /*114797 (Angus Stormbrew) - Ambidextrie*/, 103852 /*103852 (Brambley Morrison)*/, 103670 /*103670 (Brambley Morrison)*/, 100878 /*100878 (Lyana Darksorrow)*/, 100823 /*100823 (Lyana Darksorrow)*/, 116019 /*116019 (Fel Power Source)*/, 99722 /*99722 (Image of Azoran)*/, 102837 /*102837 (Servant of Azoran)*/, 99890 /*99890 (Lyana Darksorrow)*/, 102292 /*102292 (Grimwing the Devourer)*/, 99514 /*99514 (Lyana Darksorrow)*/, 100779 /*100779 (Thaedris Feathersong)*/, 99575 /*99575 (Thaedris Feathersong)*/, 99483 /*99483 (Thaedris Feathersong)*/, 99093 /*99093 (Thaedris Feathersong)*/, 116118 /*116118 (Felborne Magus) - Détecteur, Détection de l'invisibilité et du camouflage, Canalisation gangrenée*/, 110651 /*110651 (Lylandre's Frost Crystal)*/, 107846 /*107846 (Pinchshank) - Lame de Pince-jarret*/, 115715 /*115715 (Arcing Fel Crystal) - Gangrefoudre*/, 115954 /*115954 (Valthis Ama'ran)*/, 115692 /*115692 (Felborne Collaborator) - Canalisation gangrenée*/, 115738 /*115738 (Felblade Protector)*/, 115755 /*115755 (Scathing Felbeast) - Morsure pénétrante, Cosmetic - Sleep Zzz*/, 109656 /*109656 (Domesticated Mana Saber)*/, 116360 /*116360 (Duskwatch Scryer) - Détecteur, Détection de l'invisibilité et du camouflage*/, 114959 /*Molosse du moteur d’âmes - Image démoniaque, Détection de l'invisibilité et du camouflage*/, 116660 /*116660 (Felsoul Ferry)*/, 114904 /*Geôlier du moteur d’âmes*/, 114997 /*114997 (Felsoul Ferry)*/, 115012 /*115012 (Felborne Conspirator)*/, 97507 /*Disidra Foudregloire*/, 97513 /*Juwanamana*/, 110386 /*110386 (Spellwyrm)*/, 112411 /*112411 (Psillych)*/, 110383 /*110383 (Hungering Husk)*/, 112412 /*112412 (Psillych Spiderling) - Venin de jeune araignée*/, 114267 /*114267 (Ley Spider Egg)*/, 110954 /*110954 (Leystalker Dro)*/, 110931 /*110931 (Furog the Elfbreaker)*/, 112425 /*112425 (Volatile Wraithlord)*/, 110381 /*110381 (Fal'dorei Silkwitch)*/, 110380 /*110380 (Fal'dorei Devourer)*/, 110385 /*110385 (Fal'dorei Broodlord)*/, 110790 /*110790 (Brood Guardian Phyx)*/, 110376 /*110376 (Leyline Spiderling) - Venin de jeune araignée*/, 110377 /*110377 (Fal'dorei Webspinner)*/, 110029 /*110029 (Unfettered Arcana)*/, 110369 /*110369 (Shardback Skitterer)*/, 110844 /*110844 (Lapillia)*/, 110371 /*110371 (Shardback Spiderling)*/, 110370 /*110370 (Shardmaiden)*/, 110141 /*110141 (Withered Exile)*/, 110374 /*110374 (Fal'dorei Weaver)*/, 110375 /*110375 (Webbed Victim)*/, 110028 /*110028 (Withered Shambler) - Afflux titubant*/, 110771 /*110771 (Volatile Wraith)*/, 110373 /*110373 (Fal'dorei Slicer)*/, 109008 /*109008 (First Arcanist Thalyssra)*/, 110041 /*Télémancien en chef Oculeth - Cosmetic - Alpha State 0%*/, 111904 /*111904 (Waning Crescent Porter) - Porte un panier 2 - cosmétique*/, 107134 /*107134 (Projection of Aargoss) - Forme d'Ombre*/, 100331 /*100331 (Iadreth)*/, 100301 /*100301 (Astoril)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(110504, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bébé marche-neige
(94877, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Brogrul le Puissant
(100559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100559 (Lassa Skymane)
(110503, 0, 0, 0, 1, 0, 0, 0, 0, '145953'), -- 110503 (Young Snowstrider) - Cosmetic - Sleep Zzz
(110502, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110502 (Snowstrider Bull)
(113598, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 113598 (Highmountain Protector)
(113594, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113594 (Drogbar)
(113592, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 113592 (Highmountain Protector)
(116458, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 116458 (Barrels o' Fun)
(109411, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 109411 (Shadescale Flyeater)
(112076, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gardien du vignoble
(112653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112653 (Sylverin)
(108872, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Margaux
(108870, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108870 (Sylverin)
(113487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113487 (Menagerie Shopkeeper)
(109657, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 109657 (Domesticated Screecher)
(109655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109655 (Conjured Familiar)
(110998, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110998 (Instructor Solag)
(111012, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111012 (Incinerator Evixa)
(110957, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110957 (Commander Vigrox)
(111002, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111002 (Doombringer Sinarus)
(110955, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110955 (Hulking Shocktrooper)
(111006, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111006 (Felblaze Dominator)
(113705, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113705 (Loyalist Sycophant)
(113702, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113702 (Loyalist Spellblade)
(111003, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111003 (Lady Covix)
(113703, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113703 (Loyalist Magus)
(110999, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110999 (Felsword Adept)
(111013, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111013 (Felsoul Champion)
(111065, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111065 (Menagerie Keeper)
(111062, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111062 (Su'esh)
(111019, 0, 0, 1, 1, 0, 0, 0, 0, '86603'), -- 111019 (Nighteyes) - Camouflage
(109145, 0, 0, 0, 1, 0, 0, 0, 0, '209887'), -- 109145 (Lunastre Attendant) - Plateau - homme
(109144, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ly’leth Lunastre
(109114, 0, 0, 50331648, 1, 0, 0, 0, 0, '216951'), -- 109114 (Palanquin) - Costume de palanquin
(110987, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110987 (Nighteyes)
(113485, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113485 (Menagerie Shopkeeper)
(109158, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 109158 (Underglow Locust)
(104161, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104161 (Brambley Morrison)
(114797, 0, 0, 0, 1, 0, 0, 0, 0, '42459 205666 205665 205664 205663 205657'), -- 114797 (Angus Stormbrew) - Ambidextrie
(103852, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103852 (Brambley Morrison)
(103670, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103670 (Brambley Morrison)
(100878, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100878 (Lyana Darksorrow)
(100823, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100823 (Lyana Darksorrow)
(116019, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116019 (Fel Power Source)
(99722, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99722 (Image of Azoran)
(102837, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102837 (Servant of Azoran)
(99890, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99890 (Lyana Darksorrow)
(102292, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 102292 (Grimwing the Devourer)
(99514, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99514 (Lyana Darksorrow)
(100779, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 100779 (Thaedris Feathersong)
(99575, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99575 (Thaedris Feathersong)
(99483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99483 (Thaedris Feathersong)
(99093, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99093 (Thaedris Feathersong)
(116118, 0, 0, 0, 0, 0, 0, 0, 0, '203761 67236 229992'), -- 116118 (Felborne Magus) - Détecteur, Détection de l'invisibilité et du camouflage, Canalisation gangrenée
(110651, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110651 (Lylandre's Frost Crystal)
(107846, 0, 0, 0, 1, 0, 0, 0, 0, '223290'), -- 107846 (Pinchshank) - Lame de Pince-jarret
(115715, 0, 0, 50331648, 1, 0, 0, 0, 0, '183273'), -- 115715 (Arcing Fel Crystal) - Gangrefoudre
(115954, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115954 (Valthis Ama'ran)
(115692, 0, 0, 0, 0, 0, 0, 0, 0, '230001'), -- 115692 (Felborne Collaborator) - Canalisation gangrenée
(115738, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 115738 (Felblade Protector)
(115755, 0, 0, 0, 1, 0, 0, 0, 0, '231772 84186'), -- 115755 (Scathing Felbeast) - Morsure pénétrante, Cosmetic - Sleep Zzz
(109656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109656 (Domesticated Mana Saber)
(116360, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236'), -- 116360 (Duskwatch Scryer) - Détecteur, Détection de l'invisibilité et du camouflage
(114959, 0, 0, 0, 1, 0, 0, 0, 0, '213486 67236'), -- Molosse du moteur d’âmes - Image démoniaque, Détection de l'invisibilité et du camouflage
(116660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116660 (Felsoul Ferry)
(114904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Geôlier du moteur d’âmes
(114997, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114997 (Felsoul Ferry)
(115012, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115012 (Felborne Conspirator)
(97507, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Disidra Foudregloire
(97513, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Juwanamana
(110386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110386 (Spellwyrm)
(112411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112411 (Psillych)
(110383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110383 (Hungering Husk)
(112412, 0, 0, 0, 1, 0, 0, 0, 0, '213741'), -- 112412 (Psillych Spiderling) - Venin de jeune araignée
(114267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114267 (Ley Spider Egg)
(110954, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110954 (Leystalker Dro)
(110931, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110931 (Furog the Elfbreaker)
(112425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112425 (Volatile Wraithlord)
(110381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110381 (Fal'dorei Silkwitch)
(110380, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110380 (Fal'dorei Devourer)
(110385, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110385 (Fal'dorei Broodlord)
(110790, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110790 (Brood Guardian Phyx)
(110376, 0, 0, 0, 1, 0, 0, 0, 0, '213741'), -- 110376 (Leyline Spiderling) - Venin de jeune araignée
(110377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110377 (Fal'dorei Webspinner)
(110029, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110029 (Unfettered Arcana)
(110369, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110369 (Shardback Skitterer)
(110844, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110844 (Lapillia)
(110371, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110371 (Shardback Spiderling)
(110370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110370 (Shardmaiden)
(110141, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 110141 (Withered Exile)
(110374, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110374 (Fal'dorei Weaver)
(110375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110375 (Webbed Victim)
(110028, 0, 0, 0, 1, 0, 0, 0, 0, '213988'), -- 110028 (Withered Shambler) - Afflux titubant
(110771, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110771 (Volatile Wraith)
(110373, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110373 (Fal'dorei Slicer)
(109008, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109008 (First Arcanist Thalyssra)
(110041, 0, 0, 0, 1, 0, 0, 0, 0, '80808'), -- Télémancien en chef Oculeth - Cosmetic - Alpha State 0%
(111904, 0, 0, 0, 1, 0, 0, 0, 0, '223741'), -- 111904 (Waning Crescent Porter) - Porte un panier 2 - cosmétique
(107134, 0, 0, 0, 1, 0, 0, 0, 0, '43395'), -- 107134 (Projection of Aargoss) - Forme d'Ombre
(100331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100331 (Iadreth)
(100301, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 100301 (Astoril)

UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=98406; -- 98406 (Embershard Scorpion)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=96247; -- 96247 (Vileshard Crawler)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=110501; -- 110501 (Snowrunner Fox)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=112489; -- 112489 (Callus)
UPDATE `creature_template_addon` SET `auras`='226086' WHERE `entry`=104844; -- 104844 ("Old Wise" Ewaye)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=102476; -- 102476 (Prison Shackle Bunny)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=99122; -- 99122 (Withered Captive)
UPDATE `creature_template_addon` SET `auras`='225291' WHERE `entry`=113123; -- 113123 (Leytouched Cliffquill)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113122; -- 113122 (Suramar Cliffquill)
UPDATE `creature_template_addon` SET `auras`='206881' WHERE `entry`=99764; -- Ecraseur gangrâme
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113125; -- 113125 (Lowland Hardshell)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113974; -- 113974 (Leyline Spiderling)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=98306; -- Hurleuse niche-falaise
UPDATE `creature_template_addon` SET `auras`='225291' WHERE `entry`=113185; -- 113185 (Mana-Infused Bushtail)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=115924; -- Magus garde de l’aube
UPDATE `creature_template_addon` SET `auras`='205061' WHERE `entry`=105640; -- 105640 (Bound Goat)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=114897; -- Sentinelle de Darnassus
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=100775; -- 100775 (Lilryia Dawnwind)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=68553; -- 68553 (SLG Generic MoP (Large AOI))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=108190; -- 108190 (Magisterial Sleuth)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=116119; -- 116119 (Felborne Energist)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=115724; -- 115724 (Felborne Marauder)
UPDATE `creature_template_addon` SET `auras`='152209' WHERE `entry`=110253; -- Rôdeur plumelune
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=111921; -- 111921 (Buried Exile)
UPDATE `creature_template_addon` SET `auras`='86603' WHERE `entry`=100778; -- 100778 (Nightborne Trapper)
UPDATE `creature_template_addon` SET `auras`='217640' WHERE `entry`=108873; -- 108873 (Distillery Attendant)
UPDATE `creature_template_addon` SET `auras`='216946 216948' WHERE `entry`=109023; -- 109023 (Shadescale Flyeater)
UPDATE `creature_template_addon` SET `auras`='217438' WHERE `entry`=108869; -- Travailleur du vignoble
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108931; -- 108931 (Vineyard Laborer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=109647; -- 109647 (Imperial Arcbinder)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=109461; -- 109461 (Vineyard Porter)
UPDATE `creature_template_addon` SET `auras`='216450' WHERE `entry`=108943; -- Domestique du vignoble
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=107296; -- 107296 (Suramar Aristocrat)
UPDATE `creature_template_addon` SET `auras`='228118' WHERE `entry`=111485; -- 111485 (Duskwatch Spellshield)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=108188; -- 108188 (Imperial Arcbinder)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108189; -- 108189 (Imperial Servant)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=107342; -- 107342 (Duskwatch Spell-Fencer)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=109650; -- 109650 (Duskwatch Spell-Fencer)
UPDATE `creature_template_addon` SET `auras`='209887' WHERE `entry`=111498; -- 111498 (Imperial Servant)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=114888; -- 114888 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=114958; -- 114958 (Duskwatch Subjugator)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=106032; -- 106032 (Duskwatch Battlemaster)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=112190; -- Jeune sabre curieux
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=107451; -- 107451 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=108405; -- 108405 (Kal)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=108811; -- 108811 (Audric)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=113752; -- 113752 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114892; -- Civil flétrissant
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114889; -- Civile shal’dorei
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=96198; -- 96198 (Catriona Macrae)
UPDATE `creature_template_addon` SET `auras`='210063' WHERE `entry`=96782; -- 96782 (Lucian Trias)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=96778; -- 96778 (Aemara)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=111902; -- 111902 (Suramar Refugee)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=111901; -- 111901 (Suramar Refugee)
UPDATE `creature_template_addon` SET `auras`='152209' WHERE `entry`=112910; -- 112910 (Misthollow Hunter)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='28892' WHERE `entry`=104235; -- 104235 (Val'Sharah Refugee)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=107712; -- 107712 (Verene)
UPDATE `creature_template_addon` SET `auras`='215282' WHERE `entry`=94282; -- 94282 (Djin'zal)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `aiAnimKit`=0 WHERE `entry`=112336; -- 112336 (Meredil Glider)
UPDATE `creature_template_addon` SET `auras`='203761 67236 220618' WHERE `entry`=111621; -- 111621 (Duskwatch Executor)
UPDATE `creature_template_addon` SET `auras`='155893' WHERE `entry`=114927; -- 114927 (Fist of the Duskwatch)
UPDATE `creature_template_addon` SET `auras`='210868' WHERE `entry`=114929; -- 114929 (Duskwatch Defender)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=102415; -- 102415 (Suramar Skyhunter)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (108875, 107449, 98555, 112910, 106609, 111065, 110805, 114849, 111446, 101581, 114926, 101900, 114929, 107846, 99789, 91824, 112336, 106339, 101580, 115381, 99762, 110025, 104837, 112796, 110043, 105014, 104404, 113190, 110042, 101868, 109023, 98862, 116716, 114472, 102415, 116360, 107567, 101878, 114865, 114927, 97732, 99584, 105650, 98979, 98306, 114468, 114876, 97729, 113184, 113634, 106375, 104845, 113974, 108190, 102960, 109650, 113606, 108871, 116063, 115606, 115279, 113206, 114874, 115595, 115691, 111490, 105756, 115594, 99581, 114845, 105654, 112827, 116119, 99765, 111621, 100777, 109463, 108314, 113122, 114931, 100778, 104844, 111921, 111489, 113707, 115924, 114958, 111749, 113573, 115806, 100779, 115926, 99749, 106648, 111045, 113679, 110503, 112301, 99764, 110502, 111568, 103089, 115480, 114897, 115549, 111485, 106055, 103631, 111484, 114904, 99075, 110728, 102748, 112370, 114474, 99070, 106109, 113675, 99638, 114879, 112909, 112331, 106032, 105759, 125875, 102747, 102746, 113198, 105481, 102303, 109670, 115544, 117355, 100595, 100237, 113577, 111622, 107134, 111557, 112489, 105653, 113592, 113594, 115519, 113125, 115518, 109509, 115515, 113127, 105640, 113572, 108096, 111614, 101577, 115724, 121412, 112825, 111197, 116118, 121416, 109782, 106348, 111523, 109411, 114924, 115526, 113185, 107342, 115514, 113123, 115738, 105655, 100780, 105232, 111750, 119081, 89829, 111869, 111699, 109652, 112972, 100019, 102016, 116715, 112545, 114718, 105656, 106263, 106262, 115690, 99862, 105652, 110726, 113633, 111675, 114995, 112948, 102819, 105645, 105646, 111944, 111685, 105644, 117412, 116068, 112543, 95722, 103671, 115216, 111389, 69759, 111558, 110024, 110501, 114480, 108553, 111872, 110944, 102837, 102292, 110651, 102898, 111871, 111870, 111445, 111620, 113598, 102495, 114866, 111556, 116116, 103223, 111376, 115954, 113567, 100047, 116117, 106654, 115692, 118678, 108628, 111618, 97750, 109647, 116206, 101688, 112530, 103514, 101821, 106526, 113741, 99636, 111612, 111007, 114946, 111273, 108188, 114470, 119067, 110870, 115012, 99485, 115715, 99859, 111651, 105480, 114880, 106752, 111050, 104810, 99593, 111056, 107717, 99610, 94877, 103677, 113201, 115607, 107333, 94282, 100864, 122130, 100700, 115517, 110727, 119077, 108554, 107772, 110354, 100559);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(108875, 0, 25996),
(107449, 0, 25996),
(98555, 0, 25996),
(112910, 0, 25996),
(106609, 0, 25996),
(111065, 0, 25996),
(110805, 0, 25996),
(114849, 0, 25996),
(111446, 0, 25996),
(101581, 0, 25996),
(114926, 0, 25996),
(101900, 0, 25996),
(114929, 0, 25996),
(107846, 0, 25996),
(99789, 0, 25996),
(91824, 0, 25996),
(112336, 0, 25996),
(106339, 0, 25996),
(101580, 0, 25996),
(115381, 0, 25996),
(99762, 0, 25996),
(110025, 0, 25996),
(104837, 0, 25996),
(112796, 0, 25996),
(110043, 0, 25996),
(105014, 0, 25996),
(104404, 0, 25996),
(113190, 0, 25996),
(110042, 0, 25996),
(101868, 0, 25996),
(109023, 0, 25996),
(98862, 0, 25996),
(116716, 0, 25996),
(114472, 0, 25996),
(102415, 0, 25996),
(116360, 0, 25996),
(107567, 0, 25996),
(101878, 0, 25996),
(114865, 0, 25996),
(114927, 0, 25996),
(97732, 0, 25996),
(99584, 0, 25996),
(105650, 0, 25996),
(98979, 0, 25996),
(98306, 0, 25996),
(114468, 0, 25996),
(114876, 0, 25996),
(97729, 0, 25996),
(113184, 0, 25996),
(113634, 0, 25996),
(106375, 0, 25996),
(104845, 0, 25996),
(113974, 0, 25996),
(108190, 0, 25996),
(102960, 0, 25996),
(109650, 0, 25996),
(113606, 0, 25996),
(108871, 0, 25996),
(116063, 0, 25996),
(115606, 0, 25996),
(115279, 0, 25996),
(113206, 0, 25996),
(114874, 0, 25996),
(115595, 0, 25996),
(115691, 0, 25996),
(111490, 0, 25996),
(105756, 0, 25996),
(115594, 0, 25996),
(99581, 0, 25996),
(114845, 0, 25996),
(105654, 0, 25996),
(112827, 0, 25996),
(116119, 0, 25996),
(99765, 0, 25996),
(111621, 0, 25996),
(100777, 0, 25996),
(109463, 0, 25996),
(108314, 0, 25996),
(113122, 0, 25996),
(114931, 0, 25996),
(100778, 0, 25996),
(104844, 0, 25996),
(111921, 0, 25996),
(111489, 0, 25996),
(113707, 0, 25996),
(115924, 0, 25996),
(114958, 0, 25996),
(111749, 0, 25996),
(113573, 0, 25996),
(115806, 0, 25996),
(100779, 0, 25996),
(115926, 0, 25996),
(99749, 0, 25996),
(106648, 0, 25996),
(111045, 0, 25996),
(113679, 0, 25996),
(110503, 0, 25996),
(112301, 0, 25996),
(99764, 0, 25996),
(110502, 0, 25996),
(111568, 0, 25996),
(103089, 0, 25996),
(115480, 0, 25996),
(114897, 0, 25996),
(115549, 0, 25996),
(111485, 0, 25996),
(106055, 0, 25996),
(103631, 0, 25996),
(111484, 0, 25996),
(114904, 0, 25996),
(99075, 0, 25996),
(110728, 0, 25996),
(102748, 0, 25996),
(112370, 0, 25996),
(114474, 0, 25996),
(99070, 0, 25996),
(106109, 0, 25996),
(113675, 0, 25996),
(99638, 0, 25996),
(114879, 0, 25996),
(112909, 0, 25996),
(112331, 0, 25996),
(106032, 0, 25996),
(105759, 0, 25996),
(125875, 0, 25996),
(102747, 0, 25996),
(102746, 0, 25996),
(113198, 0, 25996),
(105481, 0, 25996),
(102303, 0, 25996),
(109670, 0, 25996),
(115544, 0, 25996),
(117355, 0, 25996),
(100595, 0, 25996),
(100237, 0, 25996),
(113577, 0, 25996),
(111622, 0, 25996),
(107134, 0, 25996),
(111557, 0, 25996),
(112489, 0, 25996),
(105653, 0, 25996),
(113592, 0, 25996),
(113594, 0, 25996),
(115519, 0, 25996),
(113125, 0, 25996),
(115518, 0, 25996),
(109509, 0, 25996),
(115515, 0, 25996),
(113127, 0, 25996),
(105640, 0, 25996),
(113572, 0, 25996),
(108096, 0, 25996),
(111614, 0, 25996),
(101577, 0, 25996),
(115724, 0, 25996),
(121412, 0, 25996),
(112825, 0, 25996),
(111197, 0, 25996),
(116118, 0, 25996),
(121416, 0, 25996),
(109782, 0, 25996),
(106348, 0, 25996),
(111523, 0, 25996),
(109411, 0, 25996),
(114924, 0, 25996),
(115526, 0, 25996),
(113185, 0, 25996),
(107342, 0, 25996),
(115514, 0, 25996),
(113123, 0, 25996),
(115738, 0, 25996),
(105655, 0, 25996),
(100780, 0, 25996),
(105232, 0, 25996),
(111750, 0, 25996),
(119081, 0, 25996),
(89829, 0, 25996),
(111869, 0, 25996),
(111699, 0, 25996),
(109652, 0, 25996),
(112972, 0, 25996),
(100019, 0, 25996),
(102016, 0, 25996),
(116715, 0, 25996),
(112545, 0, 25996),
(114718, 0, 25996),
(105656, 0, 25996),
(106263, 0, 25996),
(106262, 0, 25996),
(115690, 0, 25996),
(99862, 0, 25996),
(105652, 0, 25996),
(110726, 0, 25996),
(113633, 0, 25996),
(111675, 0, 25996),
(114995, 0, 25996),
(112948, 0, 25996),
(102819, 0, 25996),
(105645, 0, 25996),
(105646, 0, 25996),
(111944, 0, 25996),
(111685, 0, 25996),
(105644, 0, 25996),
(117412, 0, 25996),
(116068, 0, 25996),
(112543, 0, 25996),
(95722, 0, 25996),
(103671, 0, 25996),
(115216, 0, 25996),
(111389, 0, 25996),
(69759, 0, 25996),
(111558, 0, 25996),
(110024, 0, 25996),
(110501, 0, 25996),
(114480, 0, 25996),
(108553, 0, 25996),
(111872, 0, 25996),
(110944, 0, 25996),
(102837, 0, 25996),
(102292, 0, 25996),
(110651, 0, 25996),
(102898, 0, 25996),
(111871, 0, 25996),
(111870, 0, 25996),
(111445, 0, 25996),
(111620, 0, 25996),
(113598, 0, 25996),
(102495, 0, 25996),
(114866, 0, 25996),
(111556, 0, 25996),
(116116, 0, 25996),
(103223, 0, 25996),
(111376, 0, 25996),
(115954, 0, 25996),
(113567, 0, 25996),
(100047, 0, 25996),
(116117, 0, 25996),
(106654, 0, 25996),
(115692, 0, 25996),
(118678, 0, 25996),
(108628, 0, 25996),
(111618, 0, 25996),
(97750, 0, 25996),
(109647, 0, 25996),
(116206, 0, 25996),
(101688, 0, 25996),
(112530, 0, 25996),
(103514, 0, 25996),
(101821, 0, 25996),
(106526, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(113741, 0, 25996),
(99636, 0, 25996),
(111612, 0, 25996),
(111007, 0, 25996),
(114946, 0, 25996),
(111273, 0, 25996),
(108188, 0, 25996),
(114470, 0, 25996),
(119067, 0, 25996),
(110870, 0, 25996),
(115012, 0, 25996),
(99485, 0, 25996),
(115715, 0, 25996),
(99859, 0, 25996),
(111651, 0, 25996),
(105480, 0, 25996),
(114880, 0, 25996),
(106752, 0, 25996),
(111050, 0, 25996),
(104810, 0, 25996),
(99593, 0, 25996),
(111056, 0, 25996),
(107717, 0, 25996),
(99610, 0, 25996),
(94877, 0, 25996),
(103677, 0, 25996),
(113201, 0, 25996),
(115607, 0, 25996),
(107333, 0, 25996),
(94282, 0, 25996),
(100864, 0, 25996),
(122130, 0, 25996),
(100700, 2, 25996),
(115517, 0, 25996),
(110727, 0, 25996),
(119077, 0, 25996),
(108554, 0, 25996),
(107772, 0, 25996),
(110354, 0, 25996),
(100559, 0, 25996);



UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65478;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66488;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64340;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67421;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67592;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1556894, `VerifiedBuild`=25996 WHERE `DisplayID`=65389;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6671286, `VerifiedBuild`=25996 WHERE `DisplayID`=40075;
UPDATE `creature_model_info` SET `BoundingRadius`=1.790547, `VerifiedBuild`=25996 WHERE `DisplayID`=62207;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5189645, `VerifiedBuild`=25996 WHERE `DisplayID`=30254;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64014;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66304;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66305;
UPDATE `creature_model_info` SET `BoundingRadius`=3.581095, `VerifiedBuild`=25996 WHERE `DisplayID`=70260;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66029;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63662;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62859;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62861;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62865;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70613;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66186;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70612;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6671286, `VerifiedBuild`=25996 WHERE `DisplayID`=66292;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69544;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65091;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72656;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66556;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66570;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70934;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70745;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70746;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70754;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70486;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70627;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63525;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028736, `CombatReach`=1.5 WHERE `DisplayID`=61928;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72936;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64590;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63825;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63842;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63841;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65330;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63839;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63840;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72889;
UPDATE `creature_model_info` SET `BoundingRadius`=2.498933, `VerifiedBuild`=25996 WHERE `DisplayID`=39390;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65157;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71656;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70832;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24978;
UPDATE `creature_model_info` SET `BoundingRadius`=3.627138, `VerifiedBuild`=25996 WHERE `DisplayID`=41425;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=913;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55318;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68314;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23830;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63813;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63799;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21999;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64804;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67611;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23748;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67427;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68075;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67640;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66847;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20914;
UPDATE `creature_model_info` SET `BoundingRadius`=1.8742, `VerifiedBuild`=25996 WHERE `DisplayID`=52317;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67765;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67766;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25, `VerifiedBuild`=25996 WHERE `DisplayID`=66312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67768;
UPDATE `creature_model_info` SET `BoundingRadius`=2.498933, `VerifiedBuild`=25996 WHERE `DisplayID`=67882;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69570;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66210;
UPDATE `creature_model_info` SET `BoundingRadius`=5.077595, `VerifiedBuild`=25996 WHERE `DisplayID`=67569;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69935;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67430;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69934;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69936;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65772;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67628;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66332;
UPDATE `creature_model_info` SET `BoundingRadius`=5.38295, `VerifiedBuild`=25996 WHERE `DisplayID`=62716;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66189;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72998;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24565;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65374;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65379;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64664;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65378;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26069;
UPDATE `creature_model_info` SET `BoundingRadius`=1.65039 WHERE `DisplayID`=68393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70753;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73452;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=41395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70747;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70458;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70460;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70461;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7571489, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=73934;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71158;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66562;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66564;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71120;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71122;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71121;
UPDATE `creature_model_info` SET `BoundingRadius`=3.0042, `VerifiedBuild`=25996 WHERE `DisplayID`=45448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2702;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71874;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73504;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61926;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71123;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10191;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70128;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70760;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70758;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71118;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70757;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71582;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73659;
UPDATE `creature_model_info` SET `BoundingRadius`=1.595593, `VerifiedBuild`=25996 WHERE `DisplayID`=73535;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73755;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73754;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028736, `CombatReach`=1.5 WHERE `DisplayID`=61927;
UPDATE `creature_model_info` SET `BoundingRadius`=1.65039 WHERE `DisplayID`=64629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65239;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65243;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=54441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27720;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2610845, `VerifiedBuild`=25996 WHERE `DisplayID`=27882;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27681;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40674;
UPDATE `creature_model_info` SET `BoundingRadius`=8.821245, `VerifiedBuild`=25996 WHERE `DisplayID`=36513;
UPDATE `creature_model_info` SET `BoundingRadius`=0.58156, `VerifiedBuild`=25996 WHERE `DisplayID`=68062;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7718589, `VerifiedBuild`=25996 WHERE `DisplayID`=35688;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72736;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71556;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71664;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36700;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72066;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69272;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38411;
UPDATE `creature_model_info` SET `BoundingRadius`=1.801506, `VerifiedBuild`=25996 WHERE `DisplayID`=71642;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=0.9375 WHERE `DisplayID`=70400;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70748;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71612;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67525;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=69822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71290;


UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=113843 AND `item`=130151 AND `ExtendedCost`=6099 AND `type`=1); -- Panier-repas « le diablosaure »
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=113843 AND `item`=140671 AND `ExtendedCost`=6097 AND `type`=1); -- Raptor souvenir
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=113843 AND `item`=140670 AND `ExtendedCost`=6097 AND `type`=1); -- Elekk souvenir
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=113843 AND `item`=130151 AND `ExtendedCost`=6099 AND `type`=1); -- Panier-repas « le diablosaure »
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=113843 AND `item`=140671 AND `ExtendedCost`=6097 AND `type`=1); -- Raptor souvenir
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=113843 AND `item`=140670 AND `ExtendedCost`=6097 AND `type`=1); -- Elekk souvenir
UPDATE `npc_vendor` SET `slot`=9 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=9 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=9 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=95722 AND `ID`=1) OR (`CreatureID`=94877 AND `ID`=1) OR (`CreatureID`=113592 AND `ID`=1) OR (`CreatureID`=112076 AND `ID`=1) OR (`CreatureID`=110998 AND `ID`=1) OR (`CreatureID`=111012 AND `ID`=1) OR (`CreatureID`=110957 AND `ID`=1) OR (`CreatureID`=111002 AND `ID`=1) OR (`CreatureID`=110955 AND `ID`=1) OR (`CreatureID`=111006 AND `ID`=1) OR (`CreatureID`=113702 AND `ID`=1) OR (`CreatureID`=113703 AND `ID`=1) OR (`CreatureID`=110999 AND `ID`=1) OR (`CreatureID`=111013 AND `ID`=1) OR (`CreatureID`=111065 AND `ID`=1) OR (`CreatureID`=100878 AND `ID`=1) OR (`CreatureID`=100823 AND `ID`=1) OR (`CreatureID`=99890 AND `ID`=1) OR (`CreatureID`=100779 AND `ID`=1) OR (`CreatureID`=116118 AND `ID`=1) OR (`CreatureID`=115954 AND `ID`=1) OR (`CreatureID`=115692 AND `ID`=1) OR (`CreatureID`=115738 AND `ID`=1) OR (`CreatureID`=116360 AND `ID`=1) OR (`CreatureID`=115012 AND `ID`=1) OR (`CreatureID`=115338 AND `ID`=1) OR (`CreatureID`=97513 AND `ID`=1) OR (`CreatureID`=110954 AND `ID`=1) OR (`CreatureID`=110931 AND `ID`=1) OR (`CreatureID`=109008 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(95722, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0), -- Skyhorn Interceptor
(94877, 1, 133777, 0, 0, 133777, 0, 0, 0, 0, 0), -- Brogrul le Puissant
(113592, 1, 56193, 0, 0, 56173, 0, 0, 101484, 0, 0), -- Highmountain Protector
(112076, 1, 133177, 0, 0, 0, 0, 0, 0, 0, 0), -- Gardien du vignoble
(110998, 1, 138422, 0, 0, 138422, 0, 0, 0, 0, 0), -- Instructor Solag
(111012, 1, 75010, 0, 0, 127580, 0, 0, 0, 0, 0), -- Incinerator Evixa
(110957, 1, 124524, 0, 0, 0, 0, 0, 0, 0, 0), -- Commander Vigrox
(111002, 1, 138422, 0, 0, 138422, 0, 0, 0, 0, 0), -- Doombringer Sinarus
(110955, 1, 82810, 0, 0, 0, 0, 0, 0, 0, 0), -- Hulking Shocktrooper
(111006, 1, 75010, 0, 0, 127580, 0, 0, 0, 0, 0), -- Felblaze Dominator
(113702, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Loyalist Spellblade
(113703, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Loyalist Magus
(110999, 1, 127651, 0, 0, 127651, 0, 0, 0, 0, 0), -- Felsword Adept
(111013, 1, 137257, 0, 0, 0, 0, 0, 0, 0, 0), -- Felsoul Champion
(111065, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Menagerie Keeper
(100878, 1, 131718, 0, 0, 0, 0, 0, 0, 0, 0), -- Lyana Darksorrow
(100823, 1, 131718, 0, 0, 0, 0, 0, 0, 0, 0), -- Lyana Darksorrow
(99890, 1, 131718, 0, 0, 0, 0, 0, 0, 0, 0), -- Lyana Darksorrow
(100779, 1, 0, 0, 0, 0, 0, 0, 24319, 0, 0), -- Thaedris Feathersong
(116118, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Magus
(115954, 1, 142316, 0, 0, 142316, 0, 0, 0, 0, 0), -- Valthis Ama'ran
(115692, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Collaborator
(115738, 1, 142316, 0, 0, 137260, 0, 0, 0, 0, 0), -- Felblade Protector
(116360, 1, 133174, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Scryer
(115012, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Conspirator
(115338, 1, 132170, 0, 0, 137253, 0, 0, 0, 0, 0), -- Rebellious Citizen
(97513, 1, 113857, 0, 0, 0, 0, 0, 0, 0, 0), -- Juwanamana
(110954, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Leystalker Dro
(110931, 1, 105954, 0, 0, 0, 0, 0, 0, 0, 0), -- Furog the Elfbreaker
(109008, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0); -- First Arcanist Thalyssra

UPDATE `creature_equip_template` SET `ItemID2`=7946, `ItemID3`=0 WHERE (`CreatureID`=92242 AND `ID`=1); -- Barm Stonebreaker
UPDATE `creature_equip_template` SET `ItemID2`=55790, `ItemID3`=0 WHERE (`CreatureID`=106752 AND `ID`=1); -- Dorgrub the Cruel
UPDATE `creature_equip_template` SET `ItemID2`=132249, `ItemID3`=0 WHERE (`CreatureID`=102303 AND `ID`=1); -- Lieutenant Strathmar
UPDATE `creature_equip_template` SET `ItemID2`=137253, `ItemID3`=0 WHERE (`CreatureID`=111484 AND `ID`=1); -- Duskwatch Spellshield
UPDATE `creature_equip_template` SET `ItemID2`=137253, `ItemID3`=0 WHERE (`CreatureID`=111485 AND `ID`=1); -- Duskwatch Spellshield
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=107342 AND `ID`=1); -- Duskwatch Spell-Fencer
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=109650 AND `ID`=1); -- Duskwatch Spell-Fencer

DELETE FROM `gossip_menu` WHERE (`MenuID`=6944 AND `TextID`=7778) OR (`MenuID`=18748 AND `TextID`=27380) OR (`MenuID`=20193 AND `TextID`=30060) OR (`MenuID`=19907 AND `TextID`=29581) OR (`MenuID`=19908 AND `TextID`=29580) OR (`MenuID`=19905 AND `TextID`=29579) OR (`MenuID`=19906 AND `TextID`=29578) OR (`MenuID`=19902 AND `TextID`=29575) OR (`MenuID`=19893 AND `TextID`=29574) OR (`MenuID`=20268 AND `TextID`=30272) OR (`MenuID`=19895 AND `TextID`=29564) OR (`MenuID`=19885 AND `TextID`=29551) OR (`MenuID`=20372 AND `TextID`=30465) OR (`MenuID`=19960 AND `TextID`=28198) OR (`MenuID`=19301 AND `TextID`=28397) OR (`MenuID`=18475 AND `TextID`=26697) OR (`MenuID`=20507 AND `TextID`=30713) OR (`MenuID`=19392 AND `TextID`=28576) OR (`MenuID`=18482 AND `TextID`=26705) OR (`MenuID`=20422 AND `TextID`=30540) OR (`MenuID`=19267 AND `TextID`=28329) OR (`MenuID`=19264 AND `TextID`=28323) OR (`MenuID`=18966 AND `TextID`=27693) OR (`MenuID`=18967 AND `TextID`=27692) OR (`MenuID`=20399 AND `TextID`=30507) OR (`MenuID`=18958 AND `TextID`=27672) OR (`MenuID`=18959 AND `TextID`=27673) OR (`MenuID`=19687 AND `TextID`=29172) OR (`MenuID`=18723 AND `TextID`=12487) OR (`MenuID`=19952 AND `TextID`=27259) OR (`MenuID`=20063 AND `TextID`=29793) OR (`MenuID`=19945 AND `TextID`=29641) OR (`MenuID`=19978 AND `TextID`=29641) OR (`MenuID`=19986 AND `TextID`=29641) OR (`MenuID`=19988 AND `TextID`=29641) OR (`MenuID`=19991 AND `TextID`=29641) OR (`MenuID`=19979 AND `TextID`=29641) OR (`MenuID`=19980 AND `TextID`=29641) OR (`MenuID`=19952 AND `TextID`=29660);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(6944, 7778), -- 111675 (Ancient Cloudwing)
(18748, 27380), -- 97140 (First Arcanist Thalyssra)
(20193, 30060), -- Margaux
(19907, 29581), -- 109223 (Margaux)
(19908, 29580), -- 109223 (Margaux)
(19905, 29579), -- 109223 (Margaux)
(19906, 29578), -- 109223 (Margaux)
(19902, 29575), -- 109223 (Margaux)
(19893, 29574), -- 109223 (Margaux)
(20268, 30272), -- Margaux
(19895, 29564), -- Margaux
(19885, 29551), -- Ly’leth Lunastre
(20372, 30465), -- 103131 (Keelay Moongrow)
(19960, 28198), -- 98548 (Chief Telemancer Oculeth)
(19301, 28397), -- 103155 (Arcanist Valtrois)
(18475, 26697), -- 92264 (Felsmith Nal'ryssa)
(20507, 30713), -- 114797 (Angus Stormbrew)
(19392, 28576), -- 103852 (Brambley Morrison)
(18482, 26705), -- 242411
(20422, 30540), -- 113682 (Felbound Manasaber)
(19267, 28329), -- 99890 (Lyana Darksorrow)
(19264, 28323), -- 99514 (Lyana Darksorrow)
(18966, 27693), -- 99575 (Thaedris Feathersong)
(18967, 27692), -- 99575 (Thaedris Feathersong)
(20399, 30507), -- 113577 (Spirit Font)
(18958, 27672), -- 99093 (Thaedris Feathersong)
(18959, 27673), -- 99093 (Thaedris Feathersong)
(19687, 29172), -- 104618 (Theryn)
(18723, 12487), -- 96813 (Aludane Whitecloud)
(19952, 27259), -- 109008 (First Arcanist Thalyssra)
(20063, 29793), -- Télémancien en chef Oculeth
(19945, 29641), -- 251666
(19978, 29641), -- 251724
(19986, 29641), -- 251732
(19988, 29641), -- 251740
(19991, 29641), -- 251743
(19979, 29641), -- 251725
(19980, 29641), -- 251726
(19952, 29660); -- 109008 (First Arcanist Thalyssra)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=18748 AND `OptionIndex`=3) OR (`MenuId`=20193 AND `OptionIndex`=0) OR (`MenuId`=19907 AND `OptionIndex`=0) OR (`MenuId`=19908 AND `OptionIndex`=0) OR (`MenuId`=19905 AND `OptionIndex`=0) OR (`MenuId`=19906 AND `OptionIndex`=0) OR (`MenuId`=19902 AND `OptionIndex`=0) OR (`MenuId`=19893 AND `OptionIndex`=0) OR (`MenuId`=19895 AND `OptionIndex`=0) OR (`MenuId`=19885 AND `OptionIndex`=0) OR (`MenuId`=20372 AND `OptionIndex`=0) OR (`MenuId`=19960 AND `OptionIndex`=1) OR (`MenuId`=19301 AND `OptionIndex`=8) OR (`MenuId`=18475 AND `OptionIndex`=2) OR (`MenuId`=19392 AND `OptionIndex`=0) OR (`MenuId`=20422 AND `OptionIndex`=0) OR (`MenuId`=18966 AND `OptionIndex`=0) OR (`MenuId`=18967 AND `OptionIndex`=0) OR (`MenuId`=18959 AND `OptionIndex`=0) OR (`MenuId`=18958 AND `OptionIndex`=0) OR (`MenuId`=19301 AND `OptionIndex`=7) OR (`MenuId`=20063 AND `OptionIndex`=0) OR (`MenuId`=19945 AND `OptionIndex`=0) OR (`MenuId`=19978 AND `OptionIndex`=0) OR (`MenuId`=19986 AND `OptionIndex`=0) OR (`MenuId`=19988 AND `OptionIndex`=0) OR (`MenuId`=19991 AND `OptionIndex`=0) OR (`MenuId`=19979 AND `OptionIndex`=0) OR (`MenuId`=19980 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(18748, 3, 0, 'I''ve come to help the withered with their combat training.', 120520),
(20193, 0, 0, 'Yes, I am ready to help make arcwine.', 114922),
(19907, 0, 0, 'I am ready.', 114311), -- OptionBroadcastTextID: 35320 - 35539 - 39152 - 52091 - 52966 - 68157 - 72264 - 98694 - 101165 - 102817 - 104314 - 105294 - 105455 - 105611 - 106714 - 107434 - 108067 - 110410 - 114311 - 115011 - 120845 - 120867 - 120960 - 122483 - 130536 - 129525
(19908, 0, 0, 'Hope is not lost. We are making progress every day.', 115000),
(19905, 0, 0, 'Thank you! I am ready to move on now.', 115006),
(19906, 0, 0, 'Thalyssra said you had a unique way of dealing with insects. What is it?', 114999),
(19902, 0, 0, 'After you, Margaux.', 115004),
(19893, 0, 0, 'She is surviving, but not easily.', 114998),
(19895, 0, 0, '<Show your Sigil.>', 114966), -- OptionBroadcastTextID: 111841 - 114966
(19885, 0, 0, 'Thalyssra said you would be able to help me infiltrate the Twilight Vineyards.', 121276),
(20372, 0, 1, 'Let me see what you have for sale.', 51295),
(19960, 1, 0, '<Gain Warpwalking for 10 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121607),
(19301, 8, 0, '<Gain Leyline Mastery for 10 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121650),
(18475, 2, 3, 'Train me.', 3266),
(19392, 0, 0, 'Lead the way. I''ll be right behind you.', 106702),
(20422, 0, 0, '<Free the Felbound Manasaber by spending 50 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:15|t Ancient Mana.>', 122567),
(18966, 0, 0, 'What will you do now?', 103139),
(18967, 0, 0, 'We may have a way to stave off the hunger - long enough to find a cure. Let us help.', 101204),
(18959, 0, 0, 'Very well.', 111532), -- OptionBroadcastTextID: 18047 - 53933 - 53936 - 80374 - 82319 - 90890 - 103121 - 111532 - 111654 - 114217 - 128544
(18958, 0, 0, 'There is another way, Thaedris. We have a refuge not far from here. Thalyssra is there.', 101033),
(19301, 7, 0, '<Gain Leyline Mastery for 20 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121649),
(20063, 0, 0, 'Send me back home, Oculeth.', 116408),
(19945, 0, 0, '|c999900005 Withered:|r Bring the chest back to Thalyssra.', 115557),
(19978, 0, 0, '|c999900005 Withered:|r Bring the chest back to Thalyssra.', 115557),
(19986, 0, 0, '|c999900005 Withered:|r Bring the chest back to Thalyssra.', 115557),
(19988, 0, 0, '|c9999000010 Withered:|r Bring the chest back to Thalyssra.', 115558),
(19991, 0, 0, '|c9999000010 Withered:|r Bring the chest back to Thalyssra.', 115558),
(19979, 0, 0, '|c999900005 Withered:|r Bring the chest back to Thalyssra.', 115557),
(19980, 0, 0, '|c999900005 Withered:|r Bring the chest back to Thalyssra.', 115557);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=19908 AND `OptionIndex`=0) OR (`MenuId`=19906 AND `OptionIndex`=0) OR (`MenuId`=19893 AND `OptionIndex`=0) OR (`MenuId`=19895 AND `OptionIndex`=0) OR (`MenuId`=18967 AND `OptionIndex`=0) OR (`MenuId`=18958 AND `OptionIndex`=0) OR (`MenuId`=19986 AND `OptionIndex`=0) OR (`MenuId`=19979 AND `OptionIndex`=0) OR (`MenuId`=19980 AND `OptionIndex`=0) OR (`MenuId`=19952 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(19908, 0, 19907, 0),
(19906, 0, 19905, 0),
(19893, 0, 19902, 0),
(19895, 0, 20268, 0),
(18967, 0, 18966, 0),
(18958, 0, 18959, 0),
(19986, 0, 19978, 0),
(19979, 0, 19986, 0),
(19980, 0, 19979, 0),
(19952, 0, 19980, 0);





UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags2`=4196352, `unit_flags3`=0 WHERE `entry`=98406; -- Embershard Scorpion
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=0 WHERE `entry`=96247; -- Vileshard Crawler
UPDATE `creature_template` SET `unit_flags3`=8193 WHERE `entry`=95722; -- Skyhorn Interceptor
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=110504; -- Bébé marche-neige
UPDATE `creature_template` SET `minlevel`=98, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=94877; -- Brogrul le Puissant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110903; -- Mana Saber
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2785, `npcflag`=8193, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=100559; -- Lassa Skymane
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=97730; -- Black-Footed Fox Kit
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=91824; -- Bluffwalker Goat
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=110501; -- Snowrunner Fox
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110503; -- Young Snowstrider
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110502; -- Snowstrider Bull
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=113598; -- Highmountain Protector
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=14, `speed_walk`=2.8, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=113594; -- Drogbar
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=113592; -- Highmountain Protector
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=99862; -- Great Eagle
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=93691; -- Ronos Ironhorn
UPDATE `creature_template` SET `npcflag`=67 WHERE `entry`=92242; -- Barm Stonebreaker
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=108554; -- Burnedhoof the Retired
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=106752; -- Dorgrub the Cruel
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=106109; -- Frostcrag Crusher
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=108553; -- Azgo, the Old Bull
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `speed_walk`=1.6, `speed_run`=0.7142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=64, `unit_flags2`=67127296, `unit_flags3`=1 WHERE `entry`=116458; -- Barrels o' Fun
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99636; -- Highpeak Goat
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108 WHERE `entry`=106271; -- Jarum Skymane
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111273; -- Lowland Manashell
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2200, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=109411; -- Shadescale Flyeater
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=256, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=112076; -- Gardien du vignoble
UPDATE `creature_template` SET `unit_flags`=33024, `unit_flags3`=1 WHERE `entry`=107333; -- Surveillant Durant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112530; -- Garion
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112489; -- Callus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=112653; -- Sylverin
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109313; -- Night Lily Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109312; -- Purified Water Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109310; -- Shadefruit Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109305; -- Arcwine Event Missile Target
UPDATE `creature_template` SET `npcflag`=0, `speed_run`=1.142857 WHERE `entry`=109202; -- Vintner Iltheux
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111699; -- Loyalist Aristocrat
UPDATE `creature_template` SET `gossip_menu_id`=20268, `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=108872; -- Margaux
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=108870; -- Sylverin
UPDATE `creature_template` SET `gossip_menu_id`=20372, `speed_run`=1.142857 WHERE `entry`=103131; -- Keelay Moongrow
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102303; -- Lieutenant Strathmar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=113487; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113486; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=109657; -- Domesticated Screecher
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110655; -- Duskmere Smuggler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110654; -- Frightened Laborer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111558; -- Felgaze Doomseer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110786; -- Astravar Attendant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109655; -- Conjured Familiar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110780; -- Astravar Attendant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110783; -- Courtly Noble
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=110998; -- Instructor Solag
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111012; -- Incinerator Evixa
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=110957; -- Commander Vigrox
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111002; -- Doombringer Sinarus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=110955; -- Hulking Shocktrooper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111006; -- Felblaze Dominator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=113705; -- Loyalist Sycophant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=113702; -- Loyalist Spellblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111003; -- Lady Covix
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=113703; -- Loyalist Magus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=110999; -- Felsword Adept
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111013; -- Felsoul Champion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111065; -- Menagerie Keeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_walk`=2, `speed_run`=0.7142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=111062; -- Su'esh
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111019; -- Nighteyes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103677; -- Graedis Oenthar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109145; -- Lunastre Attendant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=109144; -- Ly’leth Lunastre
UPDATE `creature_template` SET `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=109114; -- Palanquin
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113843; -- Kieule
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104844; -- "Old Wise" Ewaye
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110987; -- Nighteyes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99638; -- Caged Polar Bear
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113488; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=113485; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111750; -- Felborne Collaborator
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=113675; -- Wyrmtongue Scribe
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100096; -- Thaedris Feathersong
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2575, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=109158; -- Underglow Locust
UPDATE `creature_template` SET `gossip_menu_id`=18475 WHERE `entry`=92264; -- Felsmith Nal'ryssa
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=104161; -- Brambley Morrison
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114797; -- Angus Stormbrew
UPDATE `creature_template` SET `gossip_menu_id`=19392, `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103852; -- Brambley Morrison
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=103670; -- Brambley Morrison
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2110, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=33589248 WHERE `entry`=100878; -- Lyana Darksorrow
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=100823; -- Lyana Darksorrow
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=99485; -- Kozak the Afflictor
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102365; -- Selthaes Starsong
UPDATE `creature_template` SET `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=39859; -- Dave's Industrial Light and Magic Bunny (Large)(Sessile)
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102442; -- Felsoul Captive
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=100019; -- Azoran
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106526; -- Dame Rivantas
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=100698112 WHERE `entry`=116019; -- Fel Power Source
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=99722; -- Image of Azoran
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=102837; -- Servant of Azoran
UPDATE `creature_template` SET `gossip_menu_id`=19267, `minlevel`=110, `maxlevel`=110, `faction`=2110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=33589248 WHERE `entry`=99890; -- Lyana Darksorrow
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102898; -- Shivan Strifebringer
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=99122; -- Withered Captive
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106348; -- Overburdened Taskmaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100595; -- Baelbug
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=113682; -- Felbound Manasaber
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=67141632, `unit_flags2`=2048 WHERE `entry`=102292; -- Grimwing the Devourer
UPDATE `creature_template` SET `gossip_menu_id`=19264, `minlevel`=110, `maxlevel`=110, `faction`=2110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=33589248 WHERE `entry`=99514; -- Lyana Darksorrow
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=110807; -- Corruption Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=110858; -- Soul Harvester
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106375; -- Felsoul Trickster
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=98862; -- Fel Cannon
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=106339; -- Artificier odieux
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=99764; -- Ecraseur gangrâme
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=100779; -- Thaedris Feathersong
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99593; -- Cliffclutch Matriarch
UPDATE `creature_template` SET `gossip_menu_id`=18966, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=99575; -- Thaedris Feathersong
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103514; -- Leystone Basilisk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=99483; -- Thaedris Feathersong
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99610; -- Garvrulg
UPDATE `creature_template` SET `gossip_menu_id`=18958, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=99093; -- Thaedris Feathersong
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=113577; -- Spirit Font
UPDATE `creature_template` SET `HoverHeight`=6 WHERE `entry`=115549; -- Workshop Tome
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=111675; -- Ancient Cloudwing
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108874; -- Vineyard Attendant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116118; -- Felborne Magus
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=100775; -- Lilryia Dawnwind
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=42, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=110651; -- Lylandre's Frost Crystal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2753, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107846; -- Pinchshank
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108190; -- Magisterial Sleuth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=954, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=18432, `HoverHeight`=8 WHERE `entry`=115715; -- Arcing Fel Crystal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115954; -- Valthis Ama'ran
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115692; -- Felborne Collaborator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115738; -- Felblade Protector
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115755; -- Scathing Felbeast
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=114718; -- Ancient Cloudwing
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103223; -- Hertha Grimdottir
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109463; -- Magisterial Escort
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108931; -- Vineyard Laborer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109647; -- Imperial Arcbinder
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109509; -- Spellsinger Quiris
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111685; -- Loyalist Aristocrat
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109461; -- Vineyard Porter
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111489; -- Loyalist Sycophant
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=105646; -- Captive Basilisk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111651; -- Degren
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111484; -- Duskwatch Spellshield
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111485; -- Duskwatch Spellshield
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109652; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108188; -- Imperial Arcbinder
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2831, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109656; -- Domesticated Mana Saber
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111490; -- Flagorneur loyaliste
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111749; -- Felborne Collaborator
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111523; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111557; -- Legion Battlematron
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108189; -- Imperial Servant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107342; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109650; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109670; -- Chronarch Defender
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111498; -- Imperial Servant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110728; -- Marina Sentry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116360; -- Duskwatch Scryer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114959; -- Molosse du moteur d’âmes
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `VehicleId`=5087 WHERE `entry`=116660; -- Felsoul Ferry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114904; -- Geôlier du moteur d’âmes
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `VehicleId`=5023 WHERE `entry`=114997; -- Felsoul Ferry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2886, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115012; -- Felborne Conspirator
UPDATE `creature_template` SET `unit_flags2`=34816 WHERE `entry`=107598; -- Vanthir
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=114892; -- Civil flétrissant
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=114889; -- Civile shal’dorei
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=1732, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97507; -- Disidra Foudregloire
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=1735, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97513; -- Juwanamana
UPDATE `creature_template` SET `minlevel`=107 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `gossip_menu_id`=18723 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=103, `maxlevel`=103 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110386; -- Spellwyrm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112411; -- Psillych
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2822, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110383; -- Hungering Husk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112412; -- Psillych Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=6000, `RangeAttackTime`=2000 WHERE `entry`=114267; -- Ley Spider Egg
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=110954; -- Leystalker Dro
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200, `VehicleId`=4629 WHERE `entry`=110931; -- Furog the Elfbreaker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112425; -- Volatile Wraithlord
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110381; -- Fal'dorei Silkwitch
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110380; -- Fal'dorei Devourer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110385; -- Fal'dorei Broodlord
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=110790; -- Brood Guardian Phyx
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110376; -- Leyline Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110377; -- Fal'dorei Webspinner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110029; -- Unfettered Arcana
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110369; -- Shardback Skitterer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=110844; -- Lapillia
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110371; -- Shardback Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110370; -- Shardmaiden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1665, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280 WHERE `entry`=110141; -- Withered Exile
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110374; -- Fal'dorei Weaver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=6000, `RangeAttackTime`=2000 WHERE `entry`=110375; -- Webbed Victim
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2822, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110028; -- Withered Shambler
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110771; -- Volatile Wraith
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2848, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110373; -- Fal'dorei Slicer
UPDATE `creature_template` SET `gossip_menu_id`=19952, `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109008; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=110041; -- Télémancien en chef Oculeth
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=108063; -- Korine
UPDATE `creature_template` SET `npcflag`=4227 WHERE `entry`=98548; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=111904; -- Waning Crescent Porter
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=107134; -- Projection of Aargoss
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=94282; -- Djin'zal
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=107028; -- Arcane Circle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=100331; -- Iadreth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=100301; -- Astoril
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102016; -- Ambushing Husk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113567; -- Ambushing Thirster
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=100192; -- Astoril

SET @GROUP_ID := 0;
SET @ID := 0;

REPLACE INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(32642, @GROUP_ID+0, @ID+0, 'Be dat way den!', 12, 0, 100, 1, 0, 0, 33029, 'Mojodishu to Player'),
(32642, @GROUP_ID+1, @ID+0, 'Dis bad mojo what you doin''. Don''t say Mojodishu didn''t warn ya!', 12, 0, 100, 1, 0, 0, 33028, 'Mojodishu to Player'),
(32642, @GROUP_ID+2, @ID+0, 'Really, mon? Just like dat you be leavin'' Mojodishu behind?', 12, 0, 100, 1, 0, 0, 33027, 'Mojodishu to Player'),
(97140, @GROUP_ID+0, @ID+0, 'My head... still spinning...', 12, 0, 100, 0, 0, 67413, 99795, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+1, @ID+0, 'I remember seeing something like this before. But where...', 12, 0, 100, 0, 0, 67587, 114959, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+2, @ID+0, 'Ah! The vineyards!', 12, 0, 100, 0, 0, 67588, 114960, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+3, @ID+0, 'I have seen first hand what Arcan''dor''s energies do for the Withered. I have faith that it is worth the risk.', 12, 0, 100, 0, 0, 70987, 120608, 'First Arcanist Thalyssra to Player'),
(97729, @GROUP_ID+0, @ID+0, 'Trespasser...', 12, 0, 100, 0, 0, 66052, 102386, 'Disturbed Apparition to Player'),
(97729, @GROUP_ID+1, @ID+0, 'What has become of us?', 12, 0, 100, 0, 0, 66048, 102394, 'Disturbed Apparition to Player'),
(97729, @GROUP_ID+2, @ID+0, 'You will be cold... like us.', 12, 0, 100, 0, 0, 66053, 102388, 'Disturbed Apparition to Player'),
(97729, @GROUP_ID+3, @ID+0, 'Desecrator...', 12, 0, 100, 0, 0, 66045, 102387, 'Disturbed Apparition to Player'),
(97750, @GROUP_ID+0, @ID+0, 'My mind is... cleared. I will sleep now. Give Thaedris my love.', 12, 0, 100, 0, 0, 65609, 102867, 'Latara to Player'),
(98306, @GROUP_ID+0, @ID+0, 'Curses upon you!', 12, 0, 100, 0, 0, 61255, 121847, 'Cliffclutch Screecher to Player'), -- BroadcastTextID: 97738 - 121847
(99065, @GROUP_ID+0, @ID+0, 'Off with you, then. Find me some cliffthorn.', 12, 0, 100, 0, 0, 65625, 100992, 'Thaedris Feathersong to Player'),
(99485, @GROUP_ID+0, @ID+0, 'This world will... burn...', 12, 0, 100, 0, 0, 0, 101128, 'Kozak the Afflictor to Player'),
(99581, @GROUP_ID+0, @ID+0, 'We are Legion.', 12, 0, 100, 0, 0, 55369, 102139, 'Wrathguard Fury to Player'),
(99581, @GROUP_ID+1, @ID+0, 'Feel my wrath!', 12, 0, 100, 0, 0, 55368, 102138, 'Wrathguard Fury to Player'), -- BroadcastTextID: 95978 - 102138
(99593, @GROUP_ID+0, @ID+0, 'You will pay for attacking my daughters!', 12, 0, 100, 0, 0, 0, 102857, 'Cliffclutch Matriarch to Player'),
(99593, @GROUP_ID+1, @ID+0, 'First the cave dwellers, now this...', 12, 0, 100, 0, 0, 0, 102861, 'Cliffclutch Matriarch to Player'),
(99762, @GROUP_ID+0, @ID+0, 'For the Legion!', 12, 0, 100, 0, 0, 55192, 96663, 'Legion Endbringer to Player'), -- BroadcastTextID: 95990 - 96663 - 129918 - 128940 - 124936
(99762, @GROUP_ID+1, @ID+0, 'You are easily dealt with.', 12, 0, 100, 0, 0, 55196, 102131, 'Legion Endbringer to Player'),
(99762, @GROUP_ID+2, @ID+0, 'You dare attack us here?!', 12, 0, 100, 0, 0, 55191, 96662, 'Legion Endbringer to Player'),
(99851, @GROUP_ID+0, @ID+0, 'My glaives have gone too long without tasting demon blood...', 12, 0, 100, 0, 0, 67593, 101595, 'Lyana Darksorrow to Player'),
(99851, @GROUP_ID+1, @ID+0, 'If you wish to find me when Grimwing is slain... follow the trail of demon corpses.', 12, 0, 100, 0, 0, 71821, 105159, 'Lyana Darksorrow to Player'),
(99890, @GROUP_ID+0, @ID+0, 'Speak now, demon. Lead me to your master and I may let you live.', 12, 0, 100, 0, 0, 71820, 105176, 'Lyana Darksorrow to Player'),
(100053, @GROUP_ID+0, @ID+0, 'Now that the portal has been opened, the path to Azoran is clear.', 12, 0, 100, 0, 0, 67601, 105686, 'Lyana Darksorrow to Player'),
(100301, @GROUP_ID+0, @ID+0, 'We must leave now. Soon we will be home.', 12, 0, 100, 0, 0, 65731, 102081, 'Astoril to Player'),
(100301, @GROUP_ID+1, @ID+0, 'Do not be afraid. Soon all will be set right.', 12, 0, 100, 0, 0, 65754, 102082, 'Astoril to Player'),
(100301, @GROUP_ID+2, @ID+0, 'We are here.', 12, 0, 100, 0, 0, 65729, 102100, 'Astoril to Player'),
(100301, @GROUP_ID+3, @ID+0, 'Silence. I tire of your prattling. Do not worry, it will all be over soon.', 12, 0, 100, 0, 0, 65730, 102102, 'Astoril to Player'),
(100301, @GROUP_ID+4, @ID+0, 'FEL MASTERS, I BRING YOU YOUR FINAL SACRIFICE! Nine times nine souls I have brought you, my own kith and kin!', 12, 0, 100, 0, 0, 65740, 102103, 'Astoril to Player'),
(100331, @GROUP_ID+0, @ID+0, 'Yes, I am ready. Let us make haste. I worry that we will be found by our enemies.', 12, 0, 100, 0, 0, 65932, 102083, 'Iadreth to Player'),
(100331, @GROUP_ID+1, @ID+0, 'I don''t understand. This isn''t the city. Wher-', 12, 0, 100, 0, 0, 65933, 102101, 'Iadreth to Player'),
(100595, @GROUP_ID+0, @ID+0, 'Begone, filthy $c! Baelbug find the glaive and keeps it!', 12, 0, 100, 0, 0, 0, 106040, 'Baelbug to Player'),
(100595, @GROUP_ID+1, @ID+0, 'You no take warglaive!', 12, 0, 100, 0, 0, 0, 102723, 'Baelbug to Player'),
(100779, @GROUP_ID+0, @ID+0, 'I thank you for giving me newfound purpose. I will meet you at Shal''Aran. I think I will be needing a source of magic after all.', 12, 0, 100, 0, 0, 65622, 103155, 'Thaedris Feathersong to Player'),
(100823, @GROUP_ID+0, @ID+0, 'Enter the portal and fight your way to Azoran.', 12, 0, 100, 0, 0, 67599, 101993, 'Lyana Darksorrow to Player'),
(100823, @GROUP_ID+1, @ID+0, 'Do not worry about reinforcements. I will guard this portal with my life.', 12, 0, 100, 0, 0, 71817, 105725, 'Lyana Darksorrow to Player'),
(100823, @GROUP_ID+2, @ID+0, 'Time is short... Go swiftly!', 12, 0, 100, 0, 0, 71818, 105726, 'Lyana Darksorrow to Player'),
(100878, @GROUP_ID+0, @ID+0, 'The Burning Legion has been dealt a great blow this day, but our work is far from over.', 12, 0, 100, 0, 0, 67600, 105972, 'Lyana Darksorrow to Player'),
(101878, @GROUP_ID+0, @ID+0, 'You cannot hide from me.', 12, 0, 100, 0, 0, 55374, 102155, 'Felsoul Inquisitor to Player'),
(102127, @GROUP_ID+0, @ID+0, 'What do you think you''re doing?', 12, 0, 100, 0, 0, 68252, 119572, 'Menagerie Keeper to Player'), -- BroadcastTextID: 19523 - 26089 - 35357 - 41207 - 70546 - 119572
(102127, @GROUP_ID+1, @ID+0, 'Stop that at once!', 12, 0, 100, 0, 0, 68251, 119571, 'Menagerie Keeper to Player'),
(102365, @GROUP_ID+0, @ID+0, 'Your human friend was taken by the demons. Grant me my freedom and I will tell you where he was taken!', 12, 0, 100, 0, 0, 0, 106088, 'Selthaes Starsong to Player'),
(102365, @GROUP_ID+1, @ID+0, 'Your friend was taken to the felstalker pits beneath the great Burning Legion command ship.', 12, 0, 100, 0, 0, 0, 106191, 'Selthaes Starsong to Player'),
(102365, @GROUP_ID+2, @ID+0, 'Sadly, it''s probably too late for him... don''t foolishly throw your lives away for a dead man!', 12, 0, 100, 0, 0, 0, 106192, 'Selthaes Starsong to Player'),
(103155, @GROUP_ID+0, @ID+0, 'Eugh... I will never get used to that.', 12, 0, 100, 0, 0, 67408, 105777, 'Arcanist Valtrois to Player'),
(103155, @GROUP_ID+1, @ID+0, 'Tell me you are not seriously considering sending our friend on such a mission. That is suicide.', 12, 0, 100, 0, 0, 70986, 120607, 'Arcanist Valtrois to Player'),
(103155, @GROUP_ID+2, @ID+0, 'Hmph. We will have to see, then.', 12, 0, 100, 0, 0, 70985, 120609, 'Arcanist Valtrois to Player'),
(103437, @GROUP_ID+0, @ID+0, 'We gotta get to Brambley, before it''s too late!', 12, 0, 100, 0, 0, 0, 105916, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+1, @ID+0, 'Which fist do ye want? How about both!', 12, 0, 100, 0, 0, 0, 106072, 'Angus Stormbrew'),
(103437, @GROUP_ID+2, @ID+0, 'Who ordered a knuckle sandwich?!', 12, 0, 100, 0, 0, 0, 106067, 'Angus Stormbrew'),
(103437, @GROUP_ID+3, @ID+0, 'Och, what happened to yer face? MAH FISTS!', 12, 0, 100, 0, 0, 0, 106071, 'Angus Stormbrew'),
(103437, @GROUP_ID+4, @ID+0, 'Aye, let''s get him the key... but be on your guard. This place is crawling with demons.', 12, 0, 100, 0, 0, 0, 105917, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+5, @ID+0, 'Don''t worry, I''ll go easy on ye!', 12, 0, 100, 0, 0, 0, 106069, 'Angus Stormbrew'),
(103437, @GROUP_ID+6, @ID+0, 'Ye wanna fight, eh? I''ll give ye a fight!', 12, 0, 100, 0, 0, 0, 106064, 'Angus Stormbrew'),
(103437, @GROUP_ID+7, @ID+0, 'Now, THAT''S a face worth punching!', 12, 0, 100, 0, 0, 0, 106068, 'Angus Stormbrew'),
(103437, @GROUP_ID+8, @ID+0, 'Who needs an axe when ye''ve got fists o'' steel!', 12, 0, 100, 0, 0, 0, 106065, 'Angus Stormbrew'),
(103437, @GROUP_ID+9, @ID+0, 'Och! This one fell off the ugly tree an'' hit my fists on the way down!', 12, 0, 100, 0, 0, 0, 106066, 'Angus Stormbrew'),
(103437, @GROUP_ID+10, @ID+0, 'Look! That''s Brambley''s helm, I''d recognize it anywhere!', 12, 0, 100, 0, 0, 0, 105919, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+11, @ID+0, 'Brambley! No... no it canna'' be true!', 12, 0, 100, 0, 0, 0, 105918, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+12, @ID+0, 'Those demons musta'' ate ol'' Brambley... look at him! He''s just bones, now!', 12, 0, 100, 18, 0, 0, 105920, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+13, @ID+0, 'Curses upon ye, demons! CURSES UPON YE!', 12, 0, 100, 20, 0, 0, 105924, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+14, @ID+0, 'Don''t worry Brambley, I''ll carry yer wee head to safety!', 12, 0, 100, 381, 0, 0, 106438, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+15, @ID+0, 'Here lies his mighty arm that defended the realm in so many battles!', 12, 0, 100, 381, 0, 0, 106442, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+16, @ID+0, 'I''ll take ye home Brambley! Piece by piece, I swear it!', 12, 0, 100, 381, 0, 0, 106445, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+17, @ID+0, 'Och, looks like the demons chewed on this one. Aye, it''s still moist...', 12, 0, 100, 381, 0, 0, 106446, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+18, @ID+0, 'Good eye! That''s his alright... I''d know it a mile away!', 12, 0, 100, 381, 0, 0, 106444, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+19, @ID+0, 'It''s Brambley''s Dagger! We''ll take it home an'' bury it with the rest o'' him.', 12, 0, 100, 381, 0, 0, 106447, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+20, @ID+0, 'I can still hear Brambley''s voice in my head, tellin'' me to stay alive.', 12, 0, 100, 0, 0, 0, 106514, 'Angus Stormbrew to Player'),
(103437, @GROUP_ID+21, @ID+0, 'I will laddy! I''ll stay alive for the both of us!', 12, 0, 100, 0, 0, 0, 106515, 'Angus Stormbrew to Player'),
(103634, @GROUP_ID+0, @ID+0, 'Su''esh eyes the wounds on Graedis.', 16, 0, 100, 0, 0, 0, 106272, 'Su''esh to Graedis Oenthar'),
(103634, @GROUP_ID+1, @ID+0, 'Su''esh looks hungrily at Graedis.', 16, 0, 100, 0, 0, 0, 106273, 'Su''esh to Graedis Oenthar'),
(103670, @GROUP_ID+0, @ID+0, 'Angus, I''m alive! I''m up here!', 14, 0, 100, 0, 0, 0, 106452, 'Brambley Morrison to Player'),
(103670, @GROUP_ID+1, @ID+0, 'It IS my voice you daft dwarf! I''m ALIVE!', 14, 0, 100, 0, 0, 0, 106453, 'Brambley Morrison to Player'),
(103677, @GROUP_ID+0, @ID+0, 'Enough of this! To me, Su''esh! Destroy these interlopers!', 14, 0, 100, 0, 0, 65641, 106261, 'Graedis Oenthar'),
(103677, @GROUP_ID+1, @ID+0, 'What''s this? Listen to me! I am the alpha!', 12, 0, 100, 0, 0, 65642, 106262, 'Graedis Oenthar to Su''esh'),
(103677, @GROUP_ID+2, @ID+0, 'Is that how it is? Clever girl.', 12, 0, 100, 0, 0, 65643, 106263, 'Graedis Oenthar to Su''esh'),
(104161, @GROUP_ID+0, @ID+0, 'We should get out of here before it''s too late.', 12, 0, 100, 0, 0, 0, 123298, 'Brambley Morrison to Player'),
(105640, @GROUP_ID+0, @ID+0, 'The creature shakes its head, coming to its senses!', 16, 0, 100, 0, 0, 0, 107211, 'Freed Goat'),
(105759, @GROUP_ID+0, @ID+0, 'Who goes there?!', 12, 0, 100, 0, 0, 65802, 118520, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105557 - 118520 - 124631
(105759, @GROUP_ID+1, @ID+0, 'An illusion! What are you hiding?', 12, 0, 100, 0, 0, 66003, 118518, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105559 - 118518 - 124629
(105759, @GROUP_ID+2, @ID+0, 'Something''s not quite right...', 12, 0, 100, 0, 0, 66004, 118519, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105558 - 118519 - 124630
(106375, @GROUP_ID+0, @ID+0, 'Quickly, grab them!', 12, 0, 100, 0, 0, 55202, 96653, 'Felsoul Trickster to Player'),
(106375, @GROUP_ID+1, @ID+0, 'Help! Baddies here!', 12, 0, 100, 0, 0, 55202, 96655, 'Felsoul Trickster to Player'),
(106375, @GROUP_ID+2, @ID+0, 'Hmm... medium or well-done?', 12, 0, 100, 0, 0, 55202, 102137, 'Felsoul Trickster to Player'),
(106375, @GROUP_ID+3, @ID+0, 'Tasty meats for me to eats.', 12, 0, 100, 0, 0, 55207, 96658, 'Felsoul Trickster to Player'),
(106375, @GROUP_ID+4, @ID+0, 'Hey! You''re not supposed to be here.', 12, 0, 100, 0, 0, 55206, 96657, 'Felsoul Trickster to Player'),
(107126, @GROUP_ID+0, @ID+0, 'As I feared. The arcan''dor is in peril.', 12, 0, 100, 0, 0, 66368, 114957, 'Valewalker Farodin to Player'),
(107134, @GROUP_ID+0, @ID+0, 'Well well, the little elf returns. You are most... persistent.', 12, 0, 100, 0, 0, 0, 111300, 'Projection of Aargoss to Player'),
(107134, @GROUP_ID+1, @ID+0, 'You have fulfilled your end of the bargain. As promised, I give you a taste of the Legion''s power. Earn more by proving your strength!', 12, 0, 100, 25, 0, 0, 111301, 'Projection of Aargoss to Player'),
(107481, @GROUP_ID+0, @ID+0, 'It will be easier for me to travel on the road.', 12, 0, 100, 0, 0, 65938, 116542, 'Iadreth to Player'),
(107481, @GROUP_ID+1, @ID+0, 'You must protect me!', 12, 0, 100, 0, 0, 66396, 118677, 'Iadreth to Player'),
(107481, @GROUP_ID+2, @ID+0, 'Look at them... they are not even people any more. I cannot turn into one of them. We must reach Astoril quickly. Clear the path faster!', 12, 0, 100, 0, 0, 65951, 104334, 'Iadreth to Player'),
(107481, @GROUP_ID+3, @ID+0, 'We must hurry.', 12, 0, 100, 0, 0, 66391, 118672, 'Iadreth to Player'), -- BroadcastTextID: 1397 - 118672
(107481, @GROUP_ID+4, @ID+0, 'I am too weak to defend myself. Help!', 12, 0, 100, 0, 0, 66393, 118674, 'Iadreth to Player'),
(107481, @GROUP_ID+5, @ID+0, 'More exiles... like me. All I did was punish those servants... You would have done the same!', 12, 0, 100, 0, 0, 65931, 104335, 'Iadreth to Player'),
(107481, @GROUP_ID+6, @ID+0, 'You must be Astoril! Finally! The first thing I shall do when I get back in the city is drink a cool, tall glass of arcwine.', 12, 0, 100, 0, 0, 65934, 104336, 'Iadreth to Player'),
(107603, @GROUP_ID+0, @ID+0, 'I''m starving!', 12, 0, 100, 0, 0, 0, 114601, 'Shal''dorei Civilian to Vineyard Enforcer'), -- BroadcastTextID: 42353 - 114601
(107603, @GROUP_ID+1, @ID+0, 'I am shal''dorei! I will not be denied!', 12, 0, 100, 0, 0, 0, 114780, 'Shal''dorei Civilian to Player'),
(107603, @GROUP_ID+2, @ID+0, 'My daughter is dying! Please, you must help me save her!', 12, 0, 100, 0, 0, 0, 114607, 'Shal''dorei Civilian to Vineyard Enforcer'),
(107603, @GROUP_ID+3, @ID+0, 'Please help me... please...', 12, 0, 100, 0, 0, 0, 114606, 'Shal''dorei Civilian to Vineyard Enforcer'),
(108190, @GROUP_ID+0, @ID+0, 'Your death is certain!', 12, 0, 100, 0, 0, 65904, 116682, 'Magisterial Sleuth to Player'), -- BroadcastTextID: 116682 - 116696
(108870, @GROUP_ID+0, @ID+0, 'Oh no...', 12, 0, 100, 0, 0, 66343, 115290, 'Sylverin to Player'), -- BroadcastTextID: 54947 - 65690 - 68228 - 115290
(108871, @GROUP_ID+0, @ID+0, 'No! It is not my time....', 12, 0, 100, 25, 0, 66015, 116768, 'Vineyard Warden to Player'), -- BroadcastTextID: 116768 - 116778
(108872, @GROUP_ID+0, @ID+0, 'Margaux glances to each side, silently assessing the situation.', 16, 0, 100, 0, 0, 0, 114972, 'Margaux to Player'),
(108872, @GROUP_ID+1, @ID+0, 'A tour? Of course! I will show you the grounds myself.', 12, 0, 100, 0, 0, 66287, 114973, 'Margaux to Player'),
(108872, @GROUP_ID+2, @ID+0, 'The courtyard you just left is open to visitors. From here forward, one of my staff must accompany you.', 12, 0, 100, 0, 0, 66288, 114978, 'Margaux to Player'),
(108872, @GROUP_ID+3, @ID+0, 'You can purchase souvenirs and gifts from Sylverin, my assistant. Perhaps you could do that on your way out?', 12, 0, 100, 0, 0, 66289, 114979, 'Margaux to Player'),
(108872, @GROUP_ID+4, @ID+0, 'This is our tasting pavilion. We serve only the finest varietals here - many of them enjoyed in the palace!', 12, 0, 100, 0, 0, 66290, 114980, 'Margaux to Player'),
(108872, @GROUP_ID+5, @ID+0, 'Feel free to try the samples we have available today. We will continue the tour when you are finished.', 12, 0, 100, 0, 0, 66291, 114982, 'Margaux to Player'),
(108875, @GROUP_ID+0, @ID+0, 'Return to your home.', 12, 0, 100, 0, 0, 0, 114595, 'Vineyard Enforcer'),
(108875, @GROUP_ID+1, @ID+0, 'The Vineyards are open to special guests only. You must leave immediately.', 12, 0, 100, 0, 0, 0, 114600, 'Vineyard Enforcer'),
(108875, @GROUP_ID+2, @ID+0, 'Stand back!', 12, 0, 100, 0, 0, 0, 114763, 'Vineyard Enforcer to Shal''dorei Civilian'), -- BroadcastTextID: 79377 - 114763
(108875, @GROUP_ID+3, @ID+0, 'Very good.', 12, 0, 100, 0, 0, 0, 121508, 'Vineyard Enforcer to Vineyard Laborer'), -- BroadcastTextID: 109724 - 121508
(108875, @GROUP_ID+4, @ID+0, 'You there! Back to work!', 12, 0, 100, 6, 0, 0, 115111, 'Vineyard Enforcer to Player'),
(108875, @GROUP_ID+5, @ID+0, 'I will hear none of your excuses. Back to work!', 12, 0, 100, 0, 0, 0, 115113, 'Vineyard Enforcer to Player'),
(108875, @GROUP_ID+6, @ID+0, 'The Overseer will hear of this. Mark my words, Margaux.', 12, 0, 100, 0, 0, 0, 115115, 'Vineyard Enforcer to Player'),
(108877, @GROUP_ID+0, @ID+0, 'This is a heavy blend of barely-ripe shadowberry and manafruit, triple infused with Nightwell essence. It is best appreciated in small sips.', 12, 0, 100, 0, 0, 66178, 114934, 'Sacheverell Leburque to Player'),
(108877, @GROUP_ID+1, @ID+0, 'This three year Infusion incorporates delightful berry elements with a scintillating melon bouquet. Refreshing, yes?', 12, 0, 100, 0, 0, 66176, 114932, 'Sacheverell Leburque to Player'),
(108877, @GROUP_ID+2, @ID+0, 'Ah, this is a fine vintage. Seventh generation manafruit entangled with slippery nightsap flavors and a delicate walnut finish.', 12, 0, 100, 0, 0, 66177, 114933, 'Sacheverell Leburque to Player'),
(108931, @GROUP_ID+0, @ID+0, 'I was just resting. I-', 12, 0, 100, 0, 0, 0, 115112, 'Vineyard Laborer to Player'),
(108931, @GROUP_ID+1, @ID+0, 'Agh!', 12, 0, 100, 0, 0, 66279, 115114, 'Vineyard Laborer to Player'), -- BroadcastTextID: 19526 - 109120 - 115114
(109144, @GROUP_ID+0, @ID+0, 'I''ve procured a palanquin for you. Try to look imperious- it helps with the illusion.', 12, 0, 100, 0, 0, 67565, 114863, 'Ly''leth Lunastre to Player'),
(109144, @GROUP_ID+1, @ID+0, 'The woman you are looking for is named Margaux. She has shown interest in our cause.', 12, 0, 100, 0, 0, 67566, 114864, 'Ly''leth Lunastre to Player'),
(109223, @GROUP_ID+0, @ID+0, 'The building we approach now is called the Aging Chamber.', 12, 0, 100, 1, 0, 66268, 115021, 'Margaux to Player'),
(109223, @GROUP_ID+1, @ID+0, 'If you are at all familiar with the wine crafting process, you know that it is necessary to allow the juice to ferment.', 12, 0, 100, 1, 0, 66271, 115025, 'Margaux to Player'),
(109223, @GROUP_ID+2, @ID+0, 'We prefer to shorten the process using time magic. Such power is our birthright!', 12, 0, 100, 603, 0, 66269, 115022, 'Margaux to Player'),
(109223, @GROUP_ID+3, @ID+0, 'To my left you will see one of our orchards.', 12, 0, 100, 1, 0, 66270, 115023, 'Margaux to Player'),
(109223, @GROUP_ID+4, @ID+0, 'This one houses a species of tree that produces extra sweet fruit, which you tasted in the Infusion.', 12, 0, 100, 1, 0, 66272, 115026, 'Margaux to Player'),
(109223, @GROUP_ID+5, @ID+0, 'The buildings before you house our bottling facilities.', 12, 0, 100, 1, 0, 66273, 115028, 'Margaux to Player'),
(109223, @GROUP_ID+6, @ID+0, 'Each bottle is sealed with magic to prevent any of the Nightwell''s essence from fading.', 12, 0, 100, 1, 0, 66274, 115029, 'Margaux to Player'),
(109223, @GROUP_ID+7, @ID+0, 'A cask of arcwine from our vineyard can be safely stored for hundreds of years!', 12, 0, 100, 603, 0, 66275, 115030, 'Margaux to Player'),
(109223, @GROUP_ID+8, @ID+0, 'Ahead you will see our distribution facility.', 12, 0, 100, 1, 0, 66276, 115031, 'Margaux to Player'),
(109223, @GROUP_ID+9, @ID+0, 'Here we arrange to send hundreds of barrels and casks of arcwine out to the city.', 12, 0, 100, 1, 0, 66277, 115032, 'Margaux to Player'),
(109223, @GROUP_ID+10, @ID+0, 'The Magistrix monitors these activities very-', 12, 0, 100, 1, 0, 66278, 115033, 'Margaux to Player'),
(109223, @GROUP_ID+11, @ID+0, 'Don''t hurt him!', 12, 0, 100, 603, 0, 66279, 115034, 'Margaux to Player'),
(109223, @GROUP_ID+12, @ID+0, 'I am so sorry- please forgive this mistake. I will personally ensure it does not happen again.', 12, 0, 100, 20, 0, 66280, 115035, 'Margaux to Player'),
(109223, @GROUP_ID+13, @ID+0, 'Where were we?', 12, 0, 100, 6, 0, 66281, 115036, 'Margaux to Player'),
(109223, @GROUP_ID+14, @ID+0, 'Across this bridge is the most crucial part of our winemaking process.', 12, 0, 100, 1, 0, 66282, 115038, 'Margaux to Player'),
(109223, @GROUP_ID+15, @ID+0, 'It is here that we instill our wine with Nightwell essence, which gives it the restorative properties our people enjoy.', 12, 0, 100, 1, 0, 66283, 115039, 'Margaux to Player'),
(109223, @GROUP_ID+16, @ID+0, 'And this is where I leave you. I must prepare the next activity.', 12, 0, 100, 1, 0, 66284, 115040, 'Margaux to Player'),
(109223, @GROUP_ID+17, @ID+0, 'I will meet you at the next station. My assistant Sylverin will be happy to show you how the infusion process works.', 12, 0, 100, 273, 0, 66285, 115042, 'Margaux to Player'),
(110931, @GROUP_ID+0, @ID+0, 'Come to Furog, tiny elf-monsters!', 12, 0, 100, 0, 0, 0, 119271, 'Furog the Elfbreaker'),
(110931, @GROUP_ID+1, @ID+0, 'I break your elf-thing!', 12, 0, 100, 0, 0, 0, 119284, 'Furog the Elfbreaker to Withered Exile'),
(110955, @GROUP_ID+0, @ID+0, 'Die, beast!', 12, 0, 100, 0, 0, 0, 119459, 'Hulking Shocktrooper to Su''esh'), -- BroadcastTextID: 40616 - 119459
(111002, @GROUP_ID+0, @ID+0, 'The enemy may be using magic to deceive us! Do not let your guard down!', 14, 0, 100, 0, 0, 0, 119473, 'Doombringer Sinarus'),
(111002, @GROUP_ID+1, @ID+0, 'Move quickly, and crush any who resist the Legion!', 14, 0, 100, 0, 0, 0, 119469, 'Doombringer Sinarus'),
(111013, @GROUP_ID+0, @ID+0, 'Kill it! Kill it now!', 12, 0, 100, 0, 0, 0, 119462, 'Felsoul Champion to Su''esh'),
(111013, @GROUP_ID+1, @ID+0, 'Fools! Su''esh has escaped the menagerie!', 12, 0, 100, 0, 0, 0, 119461, 'Felsoul Champion to Su''esh'),
(111013, @GROUP_ID+2, @ID+0, 'Su''esh is loose! To arms!', 12, 0, 100, 0, 0, 0, 119460, 'Felsoul Champion to Su''esh'),
(112055, @GROUP_ID+0, @ID+0, 'Take your place near the table. Once we begin, it is important that we keep up the pace. These delicate ingredients spoil quickly.', 12, 0, 100, 1, 0, 66296, 115231, 'Margaux to Player'),
(112055, @GROUP_ID+1, @ID+0, 'The juices need a little massaging- step into the vat and jump to squish the mixture around!', 12, 0, 100, 25, 0, 66303, 115242, 'Margaux to Player'),
(112055, @GROUP_ID+2, @ID+0, 'The arcwine has soured... you must start over!', 42, 0, 100, 0, 0, 66293, 123135, 'Margaux to Player'),
(112055, @GROUP_ID+3, @ID+0, 'Are you certain you are ready to participate? This batch will have to be destroyed.', 12, 0, 100, 0, 0, 66293, 115228, 'Margaux to Player'),
(112055, @GROUP_ID+4, @ID+0, 'I feel as though you are losing focus. Is something else on your mind? Step back for a moment and we will try again.', 12, 0, 100, 0, 0, 66294, 115229, 'Margaux to Player'),
(112055, @GROUP_ID+5, @ID+0, 'Well done. Now let me see...', 12, 0, 100, 1, 0, 66298, 115236, 'Margaux to Player'),
(112055, @GROUP_ID+6, @ID+0, 'Let us add a little moisture. Just enough to keep the taps flowing.', 12, 0, 100, 0, 0, 66301, 115240, 'Margaux to Player'),
(112055, @GROUP_ID+7, @ID+0, 'Exactly what it needed. But there is still something missing...', 12, 0, 100, 0, 0, 66299, 115238, 'Margaux to Player'),
(112055, @GROUP_ID+8, @ID+0, 'You, my friend, are a natural. The blend needs something more, though. Let me think...', 12, 0, 100, 0, 0, 66297, 115237, 'Margaux to Player'),
(112055, @GROUP_ID+9, @ID+0, 'Ah! It needs something floral, to add a little brightness.', 12, 0, 100, 0, 0, 66300, 115239, 'Margaux to Player'),
(112055, @GROUP_ID+10, @ID+0, 'Excellent! You did very well- are you certain you have never made wine before? I will have this bottled immediately.', 12, 0, 100, 1, 0, 66297, 115230, 'Margaux to Player'),
(112301, @GROUP_ID+0, @ID+0, 'I fear nothing!', 12, 0, 100, 0, 0, 68513, 117446, 'Finna Bjornsdottir to Player'),
(112301, @GROUP_ID+1, @ID+0, 'I will crush you!', 12, 0, 100, 0, 0, 68464, 104829, 'Finna Bjornsdottir to Player'), -- BroadcastTextID: 25224 - 31795 - 58070 - 65264 - 79965 - 80170 - 83593 - 87324 - 95421 - 104829
(112301, @GROUP_ID+2, @ID+0, 'This should be good!', 12, 0, 100, 0, 0, 68512, 117445, 'Finna Bjornsdottir to Player'),
(113573, @GROUP_ID+0, @ID+0, 'Grawk... the Mother will get you...', 12, 0, 100, 0, 0, 0, 102726, 'Cliffclutch Thornwitch to Player'),
(114926, @GROUP_ID+0, @ID+0, 'HALT. Inspection required.', 12, 0, 100, 0, 0, 0, 119793, 'Arcane Sentinel to Player'),
(114998, @GROUP_ID+0, @ID+0, 'Let there be no slack in their chains!', 14, 0, 100, 0, 0, 0, 123540, 'Aargoss'),
(115691, @GROUP_ID+0, @ID+0, 'Your death is fated!', 12, 0, 100, 0, 0, 65814, 116703, 'Felborne Magus to Player'), -- BroadcastTextID: 100929 - 116703
(115691, @GROUP_ID+1, @ID+0, 'I shall dispose of you, lowborn!', 12, 0, 100, 0, 0, 66024, 116692, 'Felborne Magus to Player'), -- BroadcastTextID: 116678 - 116692
(116050, @GROUP_ID+0, @ID+0, 'The shal''dorei will rule this world!', 12, 0, 100, 0, 0, 66019, 116430, 'Duskwatch Conjurer to Player'); -- BroadcastTextID: 102164 - 116430

DELETE FROM `creature_template` WHERE `entry`=133064;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(133064, 0, 0, 82688, 0, 0, 0, 'Silithid Mini-Tank', NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 12, 0, 0, 0.01, 1, 0, 0, 25996); -- Silithid Mini-Tank

UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95722; -- Skyhorn Interceptor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110504; -- Bébé marche-neige
UPDATE `creature_template` SET `RequiredExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=94877; -- Brogrul le Puissant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110903; -- Mana Saber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111423; -- Wyrmelin détaché
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97730; -- Black-Footed Fox Kit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=62818; -- Ecureuil des Grisonnes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=91824; -- Bluffwalker Goat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=89829; -- Highcrag Eagle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110501; -- Snowrunner Fox
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97126; -- Epervière boréale
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110503; -- Young Snowstrider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110502; -- Snowstrider Bull
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113598; -- Highmountain Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113594; -- Drogbar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113592; -- Highmountain Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99862; -- Great Eagle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93691; -- Ronos Ironhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92247; -- Apashuala Ironhide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92244; -- Sturm Oakenhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92242; -- Barm Stonebreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108554; -- Burnedhoof the Retired
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92246; -- Kiyale Shalehoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106752; -- Dorgrub the Cruel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108553; -- Azgo, the Old Bull
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106109; -- Frostcrag Crusher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116458; -- Barrels o' Fun
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99636; -- Highpeak Goat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106271; -- Jarum Skymane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98303; -- Northern Hawk Owl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111273; -- Lowland Manashell
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100559; -- Lassa Skymane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98966; -- Poca Firemantle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=33776; -- Gondria
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100468; -- Landrius Ravenfall
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109411; -- Shadescale Flyeater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112076; -- Gardien du vignoble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112530; -- Garion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=119067; -- Chamane du Totem-Sinistre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112055; -- Margaux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112489; -- Callus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112653; -- Sylverin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109202; -- Vintner Iltheux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109313; -- Night Lily Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109312; -- Purified Water Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109310; -- Shadefruit Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109305; -- Arcwine Event Missile Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111699; -- Loyalist Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111168; -- Huffer
UPDATE `creature_template` SET `HealthModifier`=1.5, `VerifiedBuild`=25996 WHERE `entry`=50959; -- Karkin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109223; -- Margaux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108870; -- Sylverin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109130; -- Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108872; -- Margaux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112957; -- Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102303; -- Lieutenant Strathmar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113487; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113486; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110655; -- Duskmere Smuggler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110650; -- Gondola
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110654; -- Frightened Laborer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109657; -- Domesticated Screecher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111558; -- Felgaze Doomseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109655; -- Conjured Familiar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110786; -- Astravar Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110780; -- Astravar Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110783; -- Courtly Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113778; -- Deactivated Security Module
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103131; -- Keelay Moongrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110998; -- Instructor Solag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111012; -- Incinerator Evixa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110957; -- Commander Vigrox
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111002; -- Doombringer Sinarus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110955; -- Hulking Shocktrooper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111006; -- Felblaze Dominator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113705; -- Loyalist Sycophant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113702; -- Loyalist Spellblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111003; -- Lady Covix
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113703; -- Loyalist Magus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111013; -- Felsoul Champion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110999; -- Felsword Adept
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111065; -- Menagerie Keeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111162; -- Su'esh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111062; -- Su'esh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116161; -- Arcane Minion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103634; -- Su'esh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103677; -- Graedis Oenthar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105664; -- Freed Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105666; -- Freed Wind Serpent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105661; -- Freed Goat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105668; -- Freed Penguin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102127; -- Menagerie Keeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104787; -- Freed Polar Bear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109145; -- Lunastre Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109144; -- Ly’leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109114; -- Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109056; -- Luxurious Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113843; -- Kieule
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111019; -- Nighteyes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105654; -- Captive Penguin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104844; -- "Old Wise" Ewaye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99638; -- Caged Polar Bear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113488; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113485; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111750; -- Felborne Collaborator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113675; -- Wyrmtongue Scribe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110987; -- Nighteyes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=58965; -- Garde-courroux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100096; -- Thaedris Feathersong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111906; -- Ashtongue Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109158; -- Underglow Locust
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104161; -- Brambley Morrison
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114797; -- Angus Stormbrew
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103852; -- Brambley Morrison
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103670; -- Brambley Morrison
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107292; -- Legion Ship Beam Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100878; -- Lyana Darksorrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100053; -- Lyana Darksorrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100823; -- Lyana Darksorrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107634; -- Wounded Battle Mage Kill Credit 1
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111568; -- Felsoul Magus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107633; -- Starving Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113210; -- Fel Lock - Target Right
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110948; -- Fel Lock - Target Left
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110899; -- Fel Lock - Channeler Left
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113209; -- Fel Lock - Channeler Right
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99485; -- Kozak the Afflictor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102365; -- Selthaes Starsong
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=39859; -- Dave's Industrial Light and Magic Bunny (Large)(Sessile)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102217; -- Black Tome Floating Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102216; -- Black Tome Spinner Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99462; -- The Black Tome
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102476; -- Prison Shackle Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102450; -- Prison Shackle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102442; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113741; -- Sabre-de-mana loyal
UPDATE `creature_template` SET `KillCredit1`=100274, `modelid1`=71954, `modelid2`=0, `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=3, `VerifiedBuild`=25996 WHERE `entry`=100019; -- Azoran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103204; -- Angus Stormbrew
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116037; -- Flétri résistant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103671; -- Mangelrath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106526; -- Dame Rivantas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102754; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102752; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102758; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116019; -- Fel Power Source
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102759; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102753; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102757; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102713; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102750; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102933; -- Fel Meteor Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102837; -- Servant of Azoran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99722; -- Image of Azoran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102595; -- Summoning Crystal Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102755; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102756; -- Felsoul Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102898; -- Shivan Strifebringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99890; -- Lyana Darksorrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99851; -- Lyana Darksorrow
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=29358; -- Frostworg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106348; -- Overburdened Taskmaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100595; -- Baelbug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99513; -- Rejeton vicieux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113745; -- Imprisoning Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113682; -- Felbound Manasaber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102292; -- Grimwing the Devourer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99514; -- Lyana Darksorrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99117; -- Soul Harvester
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99122; -- Withered Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101987; -- Demonic Tome
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110805; -- Felsoul Corrupter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110807; -- Corruption Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110858; -- Soul Harvester
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106375; -- Felsoul Trickster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106339; -- Artificier odieux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98862; -- Fel Cannon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99764; -- Ecraseur gangrâme
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111944; -- Kayn Sunfury
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111510; -- Lightspawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99470; -- Soul Harvester
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98801; -- Lyana Darksorrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99593; -- Cliffclutch Matriarch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100779; -- Thaedris Feathersong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97750; -- Latara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99575; -- Thaedris Feathersong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103514; -- Leystone Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99483; -- Thaedris Feathersong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99610; -- Garvrulg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99093; -- Thaedris Feathersong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116355; -- Gnoll
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111912; -- Ashtongue Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111962; -- Illidari Adept
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108874; -- Vineyard Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116118; -- Felborne Magus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110651; -- Lylandre's Frost Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107846; -- Pinchshank
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108190; -- Magisterial Sleuth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115099; -- Dame Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115715; -- Arcing Fel Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115954; -- Valthis Ama'ran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115738; -- Felblade Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115755; -- Scathing Felbeast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115692; -- Felborne Collaborator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109180; -- Tattered Silkwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103223; -- Hertha Grimdottir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109647; -- Imperial Arcbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109463; -- Magisterial Escort
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108931; -- Vineyard Laborer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111664; -- Lavish Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111685; -- Loyalist Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109461; -- Vineyard Porter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109509; -- Spellsinger Quiris
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111489; -- Loyalist Sycophant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111651; -- Degren
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105652; -- Confined Wind Serpent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105646; -- Captive Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111484; -- Duskwatch Spellshield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111485; -- Duskwatch Spellshield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109656; -- Domesticated Mana Saber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109652; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108188; -- Imperial Arcbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111490; -- Flagorneur loyaliste
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111749; -- Felborne Collaborator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111556; -- Felsoul Courtesan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111557; -- Legion Battlematron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111523; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108189; -- Imperial Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107342; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109650; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109670; -- Chronarch Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111498; -- Imperial Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110728; -- Marina Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116360; -- Duskwatch Scryer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114959; -- Molosse du moteur d’âmes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116660; -- Felsoul Ferry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114997; -- Felsoul Ferry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115012; -- Felborne Conspirator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=117131; -- Crate of Weapons
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115338; -- Rebellious Citizen
UPDATE `creature_template` SET `RequiredExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=97517; -- Tourbeffroi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101644; -- Greystone Shardmaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102501; -- Shardmaster Azurrogg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97507; -- Disidra Foudregloire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97513; -- Juwanamana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35189; -- Skoll
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=81431; -- Rejeton terogriffe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114847; -- Mana Basin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110386; -- Spellwyrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112411; -- Psillych
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110383; -- Hungering Husk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112412; -- Psillych Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114692; -- Leyline Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114267; -- Ley Spider Egg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110954; -- Leystalker Dro
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109556; -- Treasure Chest
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110931; -- Furog the Elfbreaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112425; -- Volatile Wraithlord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110381; -- Fal'dorei Silkwitch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110380; -- Fal'dorei Devourer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110385; -- Fal'dorei Broodlord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110790; -- Brood Guardian Phyx
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110376; -- Leyline Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110377; -- Fal'dorei Webspinner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110029; -- Unfettered Arcana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110369; -- Shardback Skitterer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110844; -- Lapillia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110371; -- Shardback Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110370; -- Shardmaiden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110374; -- Fal'dorei Weaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110375; -- Webbed Victim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110771; -- Volatile Wraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110373; -- Fal'dorei Slicer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110028; -- Withered Shambler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109011; -- Withered Exile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110141; -- Withered Exile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110041; -- Télémancien en chef Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109008; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=70005; -- Young Primal Devilsaur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2034; -- Feral Nightsaber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111904; -- Waning Crescent Porter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103437; -- Angus Stormbrew
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100381; -- Astoril
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107134; -- Projection of Aargoss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94282; -- Djin'zal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107028; -- Arcane Circle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100331; -- Iadreth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100301; -- Astoril
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102016; -- Ambushing Husk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113567; -- Ambushing Thirster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107481; -- Iadreth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110024; -- Mal’Dreth le Corrupteur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104096; -- Sleeping Version


UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=91824 AND `Idx`=0); -- Bluffwalker Goat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110501 AND `Idx`=0); -- Snowrunner Fox
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110503 AND `Idx`=2); -- Young Snowstrider
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110503 AND `Idx`=1); -- Young Snowstrider
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110503 AND `Idx`=0); -- Young Snowstrider
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110502 AND `Idx`=2); -- Snowstrider Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110502 AND `Idx`=1); -- Snowstrider Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110502 AND `Idx`=0); -- Snowstrider Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99636 AND `Idx`=0); -- Highpeak Goat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111273 AND `Idx`=2); -- Lowland Manashell
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111273 AND `Idx`=1); -- Lowland Manashell
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111273 AND `Idx`=0); -- Lowland Manashell
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105654 AND `Idx`=0); -- Captive Penguin
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113675 AND `Idx`=2); -- Wyrmtongue Scribe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113675 AND `Idx`=1); -- Wyrmtongue Scribe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113675 AND `Idx`=0); -- Wyrmtongue Scribe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99485 AND `Idx`=0); -- Kozak the Afflictor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100019 AND `Idx`=0); -- Azoran
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103671 AND `Idx`=0); -- Mangelrath
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106526 AND `Idx`=2); -- Dame Rivantas
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106526 AND `Idx`=1); -- Dame Rivantas
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106526 AND `Idx`=0); -- Dame Rivantas
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102898 AND `Idx`=2); -- Shivan Strifebringer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102898 AND `Idx`=1); -- Shivan Strifebringer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102898 AND `Idx`=0); -- Shivan Strifebringer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106348 AND `Idx`=2); -- Overburdened Taskmaster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106348 AND `Idx`=1); -- Overburdened Taskmaster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106348 AND `Idx`=0); -- Overburdened Taskmaster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100595 AND `Idx`=0); -- Baelbug
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102292 AND `Idx`=1); -- Grimwing the Devourer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102292 AND `Idx`=0); -- Grimwing the Devourer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106375 AND `Idx`=0); -- Felsoul Trickster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106339 AND `Idx`=2); -- Artificier odieux
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106339 AND `Idx`=1); -- Artificier odieux
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106339 AND `Idx`=0); -- Artificier odieux
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99764 AND `Idx`=3); -- Ecraseur gangrâme
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99764 AND `Idx`=2); -- Ecraseur gangrâme
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99764 AND `Idx`=1); -- Ecraseur gangrâme
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99764 AND `Idx`=0); -- Ecraseur gangrâme
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=97750 AND `Idx`=0); -- Latara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103514 AND `Idx`=1); -- Leystone Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103514 AND `Idx`=0); -- Leystone Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107846 AND `Idx`=2); -- Pinchshank
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107846 AND `Idx`=1); -- Pinchshank
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107846 AND `Idx`=0); -- Pinchshank
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108190 AND `Idx`=0); -- Magisterial Sleuth
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105652 AND `Idx`=1); -- Confined Wind Serpent
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105652 AND `Idx`=0); -- Confined Wind Serpent
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105646 AND `Idx`=1); -- Captive Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105646 AND `Idx`=0); -- Captive Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109670 AND `Idx`=0); -- Chronarch Defender
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114959 AND `Idx`=2); -- Molosse du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114959 AND `Idx`=1); -- Molosse du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114959 AND `Idx`=0); -- Molosse du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=97517 AND `Idx`=0); -- Tourbeffroi
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=2034 AND `Idx`=0); -- Feral Nightsaber
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=94282 AND `Idx`=1); -- Djin'zal
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=94282 AND `Idx`=0); -- Djin'zal

DELETE FROM `gameobject_template` WHERE `entry` IN (247026 /*Shard of Vorgos*/, 247025 /*Shard of Kozak*/, 246521 /*Fresh Mound of Flesh*/, 252190 /*Portal Key*/, 265437 /*Doodad_7sr_hubmanatree002*/, 258005 /*Bench*/, 258004 /*Bench*/, 258007 /*Bench*/, 258006 /*Bench*/, 254803 /*Chair*/, 254802 /*Chair*/, 266192 /*Black Rook Ballista*/, 251785 /*Sealed Door*/, 260549 /*Invisible Door*/, 259239 /*Sealed Door*/, 251781 /*Sealed Door*/, 251783 /*Sealed Door*/, 251779 /*Sealed Door*/, 251778 /*Sealed Door*/, 251777 /*Sealed Door*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(247026, 5, 15516, 'Shard of Vorgos', 'questinteract', '', '', 0.1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Shard of Vorgos
(247025, 5, 15516, 'Shard of Kozak', 'questinteract', '', '', 0.1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Shard of Kozak
(246521, 5, 13840, 'Fresh Mound of Flesh', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fresh Mound of Flesh
(252190, 18, 27726, 'Portal Key', '', '', '', 1, 1, 220432, 220430, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal Key
(265437, 5, 32750, 'Doodad_7sr_hubmanatree002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7sr_hubmanatree002
(258005, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(258004, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(258007, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(258006, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254803, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(254802, 7, 34334, 'Chair', '', '', '', 0.9999999, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Chair
(266192, 5, 39013, 'Black Rook Ballista', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Black Rook Ballista
(251785, 0, 34023, 'Sealed Door', '', '', '', 1, 0, 93, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Sealed Door
(260549, 0, 10403, 'Invisible Door', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Invisible Door
(259239, 0, 34023, 'Sealed Door', '', '', '', 1, 0, 2603, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Sealed Door
(251781, 0, 34024, 'Sealed Door', '', '', '', 2.1, 0, 2576, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Sealed Door
(251783, 0, 34023, 'Sealed Door', '', '', '', 0.92, 0, 2576, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Sealed Door
(251779, 0, 34024, 'Sealed Door', '', '', '', 1, 0, 2576, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Sealed Door
(251778, 0, 31374, 'Sealed Door', '', '', '', 1, 0, 2576, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Sealed Door
(251777, 0, 31374, 'Sealed Door', '', '', '', 1, 0, 2580, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Sealed Door

UPDATE `gameobject_template` SET `Data1`=62231, `VerifiedBuild`=25996 WHERE `entry`=244777; -- Fjarnskaggl
UPDATE `gameobject_template` SET `name`='Doodad_7VR_Vrykul_ElevatorPlatform001', `VerifiedBuild`=25996 WHERE `entry`=250089; -- Doodad_7VR_Vrykul_ElevatorPlatform001
UPDATE `gameobject_template` SET `name`='Cylinder Collision (6.0 scale)', `VerifiedBuild`=25996 WHERE `entry`=233912; -- Cylinder Collision (6.0 scale)
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=25996 WHERE `entry`=247396; -- Bonfire
UPDATE `gameobject_template` SET `name`='Brazier', `VerifiedBuild`=25996 WHERE `entry`=248767; -- Brazier
UPDATE `gameobject_template` SET `name`='Campfire', `VerifiedBuild`=25996 WHERE `entry`=248784; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Salvaging', `VerifiedBuild`=25996 WHERE `entry`=241635; -- Large Metal Scrap
UPDATE `gameobject_template` SET `castBarCaption`='Salvaging', `VerifiedBuild`=25996 WHERE `entry`=241634; -- Medium Metal Scrap
UPDATE `gameobject_template` SET `name`='Greenhoof''s Anvil', `VerifiedBuild`=25996 WHERE `entry`=241435; -- Greenhoof's Anvil
UPDATE `gameobject_template` SET `castBarCaption`='Salvaging', `VerifiedBuild`=25996 WHERE `entry`=241633; -- Small Metal Scrap
UPDATE `gameobject_template` SET `name`='Greenhoof''s Forge', `VerifiedBuild`=25996 WHERE `entry`=241436; -- Greenhoof's Forge
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=25996 WHERE `entry`=254063; -- Bonfire
UPDATE `gameobject_template` SET `name`='Doodad_7HM_HighMountain_Elevator002', `VerifiedBuild`=25996 WHERE `entry`=243894; -- Doodad_7HM_HighMountain_Elevator002
UPDATE `gameobject_template` SET `name`='Doodad_7HM_HighMountain_Elevator001', `VerifiedBuild`=25996 WHERE `entry`=243893; -- Doodad_7HM_HighMountain_Elevator001
UPDATE `gameobject_template` SET `name`='Portal to Twilight Vineyards', `VerifiedBuild`=25996 WHERE `entry`=254139; -- Portal to Twilight Vineyards
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255172; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255170; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255171; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255167; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255166; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255169; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255168; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255165; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Inspecting', `VerifiedBuild`=25996 WHERE `entry`=247615; -- Crown of Mavrana Mooncrest
UPDATE `gameobject_template` SET `name`='Crown Pillar', `VerifiedBuild`=25996 WHERE `entry`=247614; -- Crown Pillar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242412; -- Ondri's Summoning Stone
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255137; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255135; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255139; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255136; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255140; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255134; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255141; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255120; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Placing seal.', `VerifiedBuild`=25996 WHERE `entry`=252783; -- Arcway Outlet
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255138; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255118; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255049; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255038; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255117; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255119; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=33265, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1598, `Data30`=67976, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252880; -- Treasure Chest
UPDATE `gameobject_template` SET `Data3`=0, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=251494; -- Silver Jasmine
UPDATE `gameobject_template` SET `Data3`=0, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=251493; -- Shadefruit
UPDATE `gameobject_template` SET `Data3`=0, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=251492; -- Purified Water
UPDATE `gameobject_template` SET `name`='Manafruit Extractor', `VerifiedBuild`=25996 WHERE `entry`=251475; -- Manafruit Extractor
UPDATE `gameobject_template` SET `name`='Collision PC Size x2.5', `VerifiedBuild`=25996 WHERE `entry`=230609; -- Collision PC Size x2.5
UPDATE `gameobject_template` SET `name`='Infused Arcwine', `VerifiedBuild`=25996 WHERE `entry`=251566; -- Infused Arcwine
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255898; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255116; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255115; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255897; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258117; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258116; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258119; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258188; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258120; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258118; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258186; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258199; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258187; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258185; -- Chair
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252881; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255182; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255048; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255045; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255043; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255042; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255039; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255047; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258206; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258205; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258204; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254282; -- Frozen Friends
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254280; -- Frozen Friends
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254284; -- Frozen Friends
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254283; -- Misty Monsters
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255008; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258014; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254287; -- Desolate Deserts
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255009; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254286; -- Aquatic Wonders
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254285; -- Aquatic Wonders
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258163; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258162; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258161; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258160; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255187; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258029; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258028; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255023; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255022; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258184; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255024; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258191; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258190; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258189; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258074; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258075; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258025; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258076; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255020; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255021; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258145; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258146; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258147; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258030; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255019; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255025; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Placing seal.', `VerifiedBuild`=25996 WHERE `entry`=252779; -- Arcway Outlet
UPDATE `gameobject_template` SET `name`='Death Gate', `VerifiedBuild`=25996 WHERE `entry`=190942; -- Death Gate
UPDATE `gameobject_template` SET `name`='Doodad_7sr_hubmanatree_lightbeam003', `VerifiedBuild`=25996 WHERE `entry`=265443; -- Doodad_7sr_hubmanatree_lightbeam003
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=247392; -- Right Arm
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=247394; -- Tibia
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=247393; -- Left Arm
UPDATE `gameobject_template` SET `name`='Brambley''s Helm', `VerifiedBuild`=25996 WHERE `entry`=247391; -- Brambley's Helm
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=247389; -- Human Skull
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=247029; -- Legion Portal
UPDATE `gameobject_template` SET `castBarCaption`='Taking', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=251771; -- Fel Engine Injector
UPDATE `gameobject_template` SET `name`='7LG_Legion_Altar01', `VerifiedBuild`=25996 WHERE `entry`=251770; -- 7LG_Legion_Altar01
UPDATE `gameobject_template` SET `type`=10, `displayId`=27772, `size`=1.5, `Data3`=3000, `Data10`=203986, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=247027; -- Legion Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246884; -- Portal Activation Altar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246885; -- Portal Activation Altar
UPDATE `gameobject_template` SET `name`='rock', `VerifiedBuild`=25996 WHERE `entry`=244959; -- rock
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252450; -- Shimmering Ancient Mana Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252219; -- Fel Lock
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252191; -- Cage
UPDATE `gameobject_template` SET `castBarCaption`='Entering', `VerifiedBuild`=25996 WHERE `entry`=252691; -- Sewer Exit
UPDATE `gameobject_template` SET `name`='Fel Lock', `VerifiedBuild`=25996 WHERE `entry`=252218; -- Fel Lock
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=247398; -- Soul Vaults Keyring
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252264; -- Leyline Feed
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=247292; -- Locked Cage
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=247291; -- Opened Cage
UPDATE `gameobject_template` SET `name`='rock', `VerifiedBuild`=25996 WHERE `entry`=247397; -- rock
UPDATE `gameobject_template` SET `type`=3, `displayId`=25514, `IconName`='questinteract', `castBarCaption`='Taking', `size`=0.5, `Data0`=43, `Data14`=96454, `Data30`=65867, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=249344; -- Fragile Demonsbreath Crucible
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=247062; -- Reinforced Cage
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252805; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251155; -- Fel Blood
UPDATE `gameobject_template` SET `castBarCaption`='Searching', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=247063; -- Demonwaste Pile
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=247390; -- Brambley's Dagger
UPDATE `gameobject_template` SET `name`='Chain', `VerifiedBuild`=25996 WHERE `entry`=247416; -- Chain
UPDATE `gameobject_template` SET `name`='Legion Hologram Screen', `VerifiedBuild`=25996 WHERE `entry`=251775; -- Legion Hologram Screen
UPDATE `gameobject_template` SET `castBarCaption`='Taking', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=251774; -- Soul Configuration Matrix
UPDATE `gameobject_template` SET `Data1`=68399, `VerifiedBuild`=25996 WHERE `entry`=254008; -- Kyrtos's Research Notes
UPDATE `gameobject_template` SET `displayId`=233, `VerifiedBuild`=25996 WHERE `entry`=184633; -- Forge
UPDATE `gameobject_template` SET `name`='Thermal Anvil', `VerifiedBuild`=25996 WHERE `entry`=214229; -- Thermal Anvil
UPDATE `gameobject_template` SET `name`='Legion Cesspit', `VerifiedBuild`=25996 WHERE `entry`=249711; -- Legion Cesspit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251180; -- Felblaze Oil
UPDATE `gameobject_template` SET `name`='Grimwing Altar', `VerifiedBuild`=25996 WHERE `entry`=246526; -- Grimwing Altar
UPDATE `gameobject_template` SET `type`=3, `displayId`=26360, `IconName`='questinteract', `Data0`=1691, `Data2`=1, `Data8`=40307, `Data30`=62796, `VerifiedBuild`=25996 WHERE `entry`=245245; -- Vengeful Warglaive
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=246527; -- Fel-Infused Plate
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=246525; -- Fel-Infused Plate
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252803; -- Small Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=245940; -- Fel-Infused Plate
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252824; -- Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252447; -- Shimmering Ancient Mana Cluster
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252211; -- Memorial Plaque
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252829; -- Small Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=246254; -- Dusty Coffer
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=247339; -- Chest of Shrouds
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=245688; -- Shattered Burial Urn
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252830; -- Small Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252207; -- Plaque
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254847; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254845; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254838; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254846; -- Bench
UPDATE `gameobject_template` SET `name`='Telemancy Beacon', `VerifiedBuild`=25996 WHERE `entry`=253393; -- Telemancy Beacon
UPDATE `gameobject_template` SET `name`='Teleporter', `VerifiedBuild`=25996 WHERE `entry`=253134; -- Teleporter
UPDATE `gameobject_template` SET `type`=3, `displayId`=34582, `IconName`='questinteract', `size`=0.8, `Data0`=2124, `Data30`=66865, `VerifiedBuild`=25996 WHERE `entry`=251035; -- Private Correspondence
UPDATE `gameobject_template` SET `type`=3, `displayId`=34581, `IconName`='questinteract', `Data0`=2124, `Data30`=66864, `VerifiedBuild`=25996 WHERE `entry`=251034; -- Stack of Arcane Tomes
UPDATE `gameobject_template` SET `type`=2, `displayId`=34579, `IconName`='questinteract', `Data0`=43, `Data1`=20245, `VerifiedBuild`=25996 WHERE `entry`=251032; -- Armoire
UPDATE `gameobject_template` SET `type`=3, `displayId`=34596, `IconName`='questinteract', `Data0`=2124, `Data30`=66863, `VerifiedBuild`=25996 WHERE `entry`=251046; -- Basket of Clothing
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252833; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255130; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255131; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255007; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255158; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255112; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255129; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255128; -- Bench
UPDATE `gameobject_template` SET `name`='Spilled Arcwine', `VerifiedBuild`=25996 WHERE `entry`=254069; -- Spilled Arcwine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251626; -- Thousand-Year Arcwine
UPDATE `gameobject_template` SET `name`='Arcwine Barrel', `VerifiedBuild`=25996 WHERE `entry`=254067; -- Arcwine Barrel
UPDATE `gameobject_template` SET `type`=3, `displayId`=33264, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1597, `Data30`=67975, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252876; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255113; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255114; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255145; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255146; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255144; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258018; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258015; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255127; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255126; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258022; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258021; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258020; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258019; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258017; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258016; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252883; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255125; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255124; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255175; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255174; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255180; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255181; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255179; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255177; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255178; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255176; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258013; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258164; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258165; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258031; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258166; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258170; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258171; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258172; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255027; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255026; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255018; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258192; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258197; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258196; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258183; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258182; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258033; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258032; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255106; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255030; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255028; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255017; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258198; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258195; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258194; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258193; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255105; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255029; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255016; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255015; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255014; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255013; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255012; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255011; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255010; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266663; -- Duskwatch Scrying Orb
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258132; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258131; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258142; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258141; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258140; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258137; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258136; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258135; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258134; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258133; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258123; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258143; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254367; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254360; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258139; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258138; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258124; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258128; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258127; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258126; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258125; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258122; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254368; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254359; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254357; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254356; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254372; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254365; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254364; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254363; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254358; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254355; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254354; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254339; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254460; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254456; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254369; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254346; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254459; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254343; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254457; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254458; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254342; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254455; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254362; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254341; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254461; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254462; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254370; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254344; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254466; -- Bench
UPDATE `gameobject_template` SET `name`='Portal to Shal''Aran', `VerifiedBuild`=25996 WHERE `entry`=260269; -- Portal to Shal'Aran
UPDATE `gameobject_template` SET `type`=3, `displayId`=33266, `castBarCaption`='Opening', `size`=2.5, `Data0`=57, `Data2`=1, `Data3`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data30`=67109, `RequiredLevel`=98, `VerifiedBuild`=25996 WHERE `entry`=252452; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251747; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19978, `VerifiedBuild`=25996 WHERE `entry`=251724; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19986, `VerifiedBuild`=25996 WHERE `entry`=251732; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=10, `displayId`=34597, `size`=2, `Data3`=3000, `Data10`=226901, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=258977; -- Telemancy Beacon
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19945, `VerifiedBuild`=25996 WHERE `entry`=251666; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=2, `Data3`=19988, `VerifiedBuild`=25996 WHERE `entry`=251740; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=2, `Data3`=19992, `VerifiedBuild`=25996 WHERE `entry`=251744; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=2, `Data3`=19991, `VerifiedBuild`=25996 WHERE `entry`=251743; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19979, `VerifiedBuild`=25996 WHERE `entry`=251725; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251741; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251726; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19984, `VerifiedBuild`=25996 WHERE `entry`=251730; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=2, `Data3`=19990, `VerifiedBuild`=25996 WHERE `entry`=251742; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19982, `VerifiedBuild`=25996 WHERE `entry`=251728; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=2, `Data3`=19987, `VerifiedBuild`=25996 WHERE `entry`=251739; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `type`=2, `displayId`=33265, `size`=1.5, `Data3`=19944, `VerifiedBuild`=25996 WHERE `entry`=251665; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=3, `displayId`=33264, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data3`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data30`=67110, `RequiredLevel`=98, `VerifiedBuild`=25996 WHERE `entry`=251954; -- Small Treasure Chest
UPDATE `gameobject_template` SET `type`=10, `displayId`=34597, `size`=2, `Data3`=3000, `Data10`=226900, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=258976; -- Telemancy Beacon
UPDATE `gameobject_template` SET `name`='Portal to Felsoul Hold', `VerifiedBuild`=25996 WHERE `entry`=254131; -- Portal to Felsoul Hold
UPDATE `gameobject_template` SET `name`='Portal to Shal''Aran', `VerifiedBuild`=25996 WHERE `entry`=260263; -- Portal to Shal'Aran


UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=241635 AND `Idx`=0); -- Large Metal Scrap
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=241634 AND `Idx`=0); -- Medium Metal Scrap
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=241633 AND `Idx`=0); -- Small Metal Scrap
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=251771 AND `Idx`=0); -- Fel Engine Injector
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247398 AND `Idx`=0); -- Soul Vaults Keyring
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=249344 AND `Idx`=0); -- Fragile Demonsbreath Crucible
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=251774 AND `Idx`=0); -- Soul Configuration Matrix
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=245245 AND `Idx`=0); -- Vengeful Warglaive
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246527 AND `Idx`=0); -- Fel-Infused Plate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246525 AND `Idx`=0); -- Fel-Infused Plate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=245940 AND `Idx`=0); -- Fel-Infused Plate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247339 AND `Idx`=0); -- Chest of Shrouds
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=251035 AND `Idx`=0); -- Private Correspondence
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=251034 AND `Idx`=0); -- Stack of Arcane Tomes
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=251046 AND `Idx`=0); -- Basket of Clothing

DELETE FROM `page_text` WHERE `ID` IN (6285 /*6285*/, 6283 /*6283*/, 6284 /*6284*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(6285, 'This enclosure closely replicates a barren landscape, where these particular creatures thrive.$b$bDID YOU KNOW? Tigers are furry friends and very warm. They are perfect for snuggling up next to on a cold night, if it were not for our weather being magically controlled. Scratching behind their ears will be sure to elicit a wonderful purr.$b$bDID YOU KNOW? The monohorn within are a rare breed, their distinctive hides being used for all manner of fashion, including hats, coat linings, and other fine apparel.$b$bThere is some discussion within the zoological community to naming these magnificent beasts "unicorns," but the majority agree that monohorn is a much more fitting name.$b$b$b$bPLEASE DO NOT TOUCH THE EXHIBITS - Management.', 0, 0, 0, 25996), -- 6285
(6283, 'This pen is carefully engineered by our staff to replicate the desolate wastes of deserts.$b$bDID YOU KNOW? Our scholars believe that had we not raised the shield, Suramar might have ended up looking much like this!$b$bDID YOU KNOW? Basilisks used to be all over Suramar! Aggressive culling and hunting for their eyes made them endangered, and only a few species struggle for survival in remote locations.$b$bBasilisks use their mighty gaze to petrify their prey, because they eat rocks!$b$bOur basilisks, of course, are fed a regular diet of rocks and flowers to maintain their brilliant scales. Don''t look at them too long!$b$b$b$bNOTE: PLEASE do not stare too long at the basilisks. Management is not responsible for additional dispel-petrification fees.', 0, 0, 0, 25996), -- 6283
(6284, 'This pit closely resembles the environments of the jungle basins. It is said that this is where life began! Inside this pen you can find Old Wise, our resident yeti.$b$bDID YOU KNOW?$b$bOld Wise did not need a collar of domination to come with us. Our top trappers realized he had an appetite for goats and lured him back to the city. He seems content to sit here and eat goats. It is said the Magistrix herself commended him for his wise behavior, and he has been affectionately called "Old Wise" ever since.$b$b$b$bPLEASE DO NOT ANGER OLD WISE - Management.', 0, 0, 0, 25996); -- 6284

UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=6287; -- 6287

DELETE FROM `npc_text` WHERE `ID` IN (26697 /*26697*/, 26705 /*26705*/, 28329 /*28329*/, 28323 /*28323*/, 29793 /*29793*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(26697, 1, 0, 0, 0, 0, 0, 0, 0, 95486, 0, 0, 0, 0, 0, 0, 0, 25996), -- 26697
(26705, 1, 0, 0, 0, 0, 0, 0, 0, 95519, 0, 0, 0, 0, 0, 0, 0, 25996), -- 26705
(28329, 1, 0, 0, 0, 0, 0, 0, 0, 105180, 0, 0, 0, 0, 0, 0, 0, 25996), -- 28329
(28323, 1, 0, 0, 0, 0, 0, 0, 0, 105152, 0, 0, 0, 0, 0, 0, 0, 25996), -- 28323
(29793, 1, 0, 0, 0, 0, 0, 0, 0, 116407, 0, 0, 0, 0, 0, 0, 0, 25996); -- 29793

UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30060; -- 30060
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29581; -- 29581
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29580; -- 29580
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29579; -- 29579
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29578; -- 29578
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29575; -- 29575
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29574; -- 29574
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30272; -- 30272
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29564; -- 29564
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29551; -- 29551
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30465; -- 30465
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28576; -- 28576
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30713; -- 30713
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30540; -- 30540
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27693; -- 27693
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27692; -- 27692
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27673; -- 27673
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27672; -- 27672
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27259; -- 27259
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29641; -- 29641
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29660; -- 29660
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27379; -- 27379

