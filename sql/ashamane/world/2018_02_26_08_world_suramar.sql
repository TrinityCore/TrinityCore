DELETE FROM `areatrigger_template` WHERE `Id` IN (14815, 10710, 12729);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(14815, 0, 0, 10, 10, 0, 0, 0, 0, 25996),
(10710, 0, 0, 3, 3, 0, 0, 0, 0, 25996),
(12729, 0, 0, 12, 12, 0, 0, 0, 0, 25996);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10593;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10568;
UPDATE `areatrigger_template` SET `Type`=4, `Data0`=5, `Data1`=5, `Data2`=2, `Data3`=2, `Data4`=0.3, `Data5`=0.3 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Type`=0, `Data0`=4, `Data1`=4, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10370;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12399;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12921;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9852;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9791;
UPDATE `areatrigger_template` SET `Type`=0, `Data0`=1, `Data1`=1, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `Data0`=3, `Data1`=5, `VerifiedBuild`=25996 WHERE `Id`=9799;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9790;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9817;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10407;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10460;
UPDATE `areatrigger_template` SET `Flags`=18, `VerifiedBuild`=25996 WHERE `Id`=10460;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12124;
UPDATE `areatrigger_template` SET `Flags`=2, `VerifiedBuild`=25996 WHERE `Id`=9482;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=9921 AND `AreaTriggerId`=14815) OR (`SpellMiscId`=8198 AND `AreaTriggerId`=12399) OR (`SpellMiscId`=8856 AND `AreaTriggerId`=12921) OR (`SpellMiscId`=5070 AND `AreaTriggerId`=9852) OR (`SpellMiscId`=4048 AND `AreaTriggerId`=9791) OR (`SpellMiscId`=5077 AND `AreaTriggerId`=9799) OR (`SpellMiscId`=5095 AND `AreaTriggerId`=9817) OR (`SpellMiscId`=5838 AND `AreaTriggerId`=10407) OR (`SpellMiscId`=5748 AND `AreaTriggerId`=10460) OR (`SpellMiscId`=7806 AND `AreaTriggerId`=12124) OR (`SpellMiscId`=6023 AND `AreaTriggerId`=10710);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(9921, 14815, 0, 0, 0, 0, 0, 0, 3000, 25996), -- SpellId : 238422
(8198, 12399, 0, 0, 0, 0, 0, 0, 60000, 25996), -- SpellId : 188020
(8856, 12921, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 191806
(5070, 9852, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 195167
(4048, 9791, 0, 0, 0, 0, 0, 0, 1000, 25996), -- SpellId : 194603
(5077, 9799, 0, 0, 0, 0, 82, 0, 30000, 25996), -- SpellId : 194232
(5095, 9817, 0, 0, 0, 0, 0, 260447, 10000, 25996), -- SpellId : 194442
(5838, 10407, 0, 0, 0, 0, 26, 31636, 21000, 25996), -- SpellId : 193465
(5748, 10460, 1706, 0, 0, 0, 0, 13271, 6000, 25996), -- SpellId : 201567
(7806, 12124, 0, 0, 0, 0, 0, 0, 30000, 25996), -- SpellId : 218944
(6023, 10710, 0, 0, 0, 0, 0, 0, 20000, 25996); -- SpellId : 204456

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1984 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6000 WHERE (`SpellMiscId`=12002 AND `AreaTriggerId`=16713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11385 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5000, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8430 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1501, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11075 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5663 AND `AreaTriggerId`=10370); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=43, `TimeToTarget`=0, `TimeToTargetScale`=600000 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5972 AND `AreaTriggerId`=10660); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7048 AND `AreaTriggerId`=11516); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2874, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8650, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1563, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2246, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2204, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1579, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8745, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2066, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2213, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5249, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5978, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2155, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8659, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7870, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2151, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2088, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2053, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2127, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5122, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1898, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1268, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7263 AND `AreaTriggerId`=11719); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2000 WHERE (`SpellMiscId`=10104 AND `AreaTriggerId`=14978); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8724 AND `AreaTriggerId`=12802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4500, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=1697 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7774 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=5428 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=1697 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10228 AND `AreaTriggerId`=15101); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=6622 AND `AreaTriggerId`=11209); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8448 AND `AreaTriggerId`=12599); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7341 AND `AreaTriggerId`=11791); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=42, `TimeToTarget`=0, `TimeToTargetScale`=600000 WHERE (`SpellMiscId`=7349 AND `AreaTriggerId`=11813); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=7663 AND `AreaTriggerId`=12051); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4756 AND `AreaTriggerId`=9482); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=3461 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=1356 AND `ConversationActorId`=49746 AND `Idx`=0) OR (`ConversationId`=1580 AND `ConversationActorId`=51685 AND `Idx`=0) OR (`ConversationId`=4090 AND `Idx`=2) OR (`ConversationId`=4090 AND `Idx`=1) OR (`ConversationId`=4090 AND `Idx`=0) OR (`ConversationId`=3955 AND `Idx`=1) OR (`ConversationId`=3955 AND `Idx`=0) OR (`ConversationId`=3887 AND `Idx`=0) OR (`ConversationId`=4073 AND `Idx`=2) OR (`ConversationId`=4073 AND `Idx`=0) OR (`ConversationId`=4073 AND `Idx`=1) OR (`ConversationId`=3296 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=4092 AND `Idx`=1) OR (`ConversationId`=4092 AND `Idx`=0) OR (`ConversationId`=4042 AND `Idx`=1) OR (`ConversationId`=4042 AND `Idx`=0) OR (`ConversationId`=4093 AND `Idx`=0) OR (`ConversationId`=4093 AND `Idx`=1) OR (`ConversationId`=4371 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=3298 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=2807 AND `ConversationActorId`=48975 AND `Idx`=0) OR (`ConversationId`=3305 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=4089 AND `Idx`=2) OR (`ConversationId`=4089 AND `Idx`=1) OR (`ConversationId`=4089 AND `Idx`=0) OR (`ConversationId`=3888 AND `ConversationActorId`=55868 AND `Idx`=0) OR (`ConversationId`=3886 AND `Idx`=0) OR (`ConversationId`=3891 AND `ConversationActorId`=0 AND `Idx`=0) OR (`ConversationId`=4383 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=4010 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=3956 AND `Idx`=0) OR (`ConversationId`=3956 AND `Idx`=1) OR (`ConversationId`=3893 AND `ConversationActorId`=55868 AND `Idx`=0) OR (`ConversationId`=3885 AND `Idx`=0) OR (`ConversationId`=3964 AND `ConversationActorId`=55868 AND `Idx`=0) OR (`ConversationId`=3460 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=1355 AND `ConversationActorId`=49746 AND `Idx`=0) OR (`ConversationId`=3892 AND `Idx`=0) OR (`ConversationId`=2819 AND `ConversationActorId`=48975 AND `Idx`=0) OR (`ConversationId`=3957 AND `Idx`=1) OR (`ConversationId`=3957 AND `Idx`=0) OR (`ConversationId`=1581 AND `ConversationActorId`=51685 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(3461, 53609, 0, 25996),
(1356, 49746, 0, 25996),
(1580, 51685, 0, 25996),
-- (4090, UNKNOWN, 2, 25996), -- Full: 0x2016F49880705EC000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: Silgryn Low: 1157595
-- (4090, UNKNOWN, 1, 25996), -- Full: 0x2016F4988070618000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: Arluelle Low: 1157595
-- (4090, UNKNOWN, 0, 25996), -- Full: 0x2016F498807061C000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: Victoire Low: 1157595
-- (3955, UNKNOWN, 1, 25996), -- Full: 0x203AEC988070E600001023000011B68E Creature/0 R3771/S4131 Map: Îles Brisées Entry: 115608 (Silgryn) Low: 1160846
-- (3955, UNKNOWN, 0, 25996), -- Full: 0x203AEC988070E5C0001023000011B213 Creature/0 R3771/S4131 Map: Îles Brisées Entry: 115607 (Thoramir) Low: 1159699
-- (3887, UNKNOWN, 0, 25996), -- Full: 0x2016F498807049C000035A000091A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: 114983 (Thorvos) Low: 9546203
-- (4073, UNKNOWN, 2, 25996), -- Full: 0x2016F4988070430000035A000011B057 Creature/0 R1469/S858 Map: Îles Brisées Entry: 114956 (Victoire) Low: 1159255
-- (4073, UNKNOWN, 0, 25996), -- Full: 0x2016F4988070414000035A000011B057 Creature/0 R1469/S858 Map: Îles Brisées Entry: 114949 (Arluelle) Low: 1159255
-- (4073, UNKNOWN, 1, 25996), -- Full: 0x2016F4988070410000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: 114948 (Silgryn) Low: 1157595
(3296, 53609, 0, 25996),
-- (4092, UNKNOWN, 1, 25996), -- Full: 0x2016F49880705EC000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: Silgryn Low: 1157595
-- (4092, UNKNOWN, 0, 25996), -- Full: 0x2016F498807061C000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: Victoire Low: 1157595
-- (4042, UNKNOWN, 1, 25996), -- Full: 0x2016F4988071060000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: Première arcaniste Thalyssra Low: 1157595
-- (4042, UNKNOWN, 0, 25996), -- Full: 0x2016F49880715D4000035A000011AFF1 Creature/0 R1469/S858 Map: Îles Brisées Entry: 116085 (Arluelle) Low: 1159153
-- (4093, UNKNOWN, 0, 25996), -- Full: 0x2016F4988070410000035A000011B30A Creature/0 R1469/S858 Map: Îles Brisées Entry: 114948 (Silgryn) Low: 1159946
-- (4093, UNKNOWN, 1, 25996), -- Full: 0x2016F4988070414000035A000011B30A Creature/0 R1469/S858 Map: Îles Brisées Entry: 114949 (Arluelle) Low: 1159946
(4371, 53609, 0, 25996),
(3298, 53609, 0, 25996),
(2807, 48975, 0, 25996),
(3305, 53609, 0, 25996),
-- (4089, UNKNOWN, 2, 25996), -- Full: 0x2016F4988070414000035A000011A9DE Creature/0 R1469/S858 Map: Îles Brisées Entry: 114949 (Arluelle) Low: 1157598
-- (4089, UNKNOWN, 1, 25996), -- Full: 0x2016F4988070430000035A000011A9DD Creature/0 R1469/S858 Map: Îles Brisées Entry: 114956 (Victoire) Low: 1157597
-- (4089, UNKNOWN, 0, 25996), -- Full: 0x2016F4988070410000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: 114948 (Silgryn) Low: 1157595
(3888, 55868, 0, 25996),
-- (3886, UNKNOWN, 0, 25996), -- Full: 0x2016F49880704A4000035A000011A9DD Creature/0 R1469/S858 Map: Îles Brisées Entry: 114985 (Scarleth) Low: 1157597
(3891, 0, 0, 25996),
(4383, 53609, 0, 25996),
(4010, 53609, 0, 25996),
-- (3956, UNKNOWN, 0, 25996), -- Full: 0x203AEC988070E5C0001023000011B213 Creature/0 R3771/S4131 Map: Îles Brisées Entry: 115607 (Thoramir) Low: 1159699
-- (3956, UNKNOWN, 1, 25996), -- Full: 0x203AEC988070E600001023000011B68E Creature/0 R3771/S4131 Map: Îles Brisées Entry: 115608 (Silgryn) Low: 1160846
(3893, 55868, 0, 25996),
-- (3885, UNKNOWN, 0, 25996), -- Full: 0x2016F4988070488000035A000011A9DB Creature/0 R1469/S858 Map: Îles Brisées Entry: 114978 (Master Devlyn) Low: 1157595
(3964, 55868, 0, 25996),
(3460, 53609, 0, 25996),
(1355, 49746, 0, 25996),
-- (3892, UNKNOWN, 0, 25996), -- Full: 0x2016F49880705A4000035A000011AEFA Creature/0 R1469/S858 Map: Îles Brisées Entry: 115049 (Silgryn) Low: 1158906
(2819, 48975, 0, 25996),
-- (3957, UNKNOWN, 1, 25996), -- Full: 0x203AEC988070E5C0001023000011B213 Creature/0 R3771/S4131 Map: Îles Brisées Entry: 115607 (Thoramir) Low: 1159699
-- (3957, UNKNOWN, 0, 25996), -- Full: 0x203AEC988070E600001023000011B68E Creature/0 R3771/S4131 Map: Îles Brisées Entry: 115608 (Silgryn) Low: 1160846
(1581, 51685, 0, 25996);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (49746, 51685, 48975, 55868, 0);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(49746, 93841, 63719, 25996),
(51685, 93826, 73318, 25996),
(48975, 103959, 68431, 25996),
(55868, 115710, 73853, 25996),
(0, 114998, 73604, 25996);

UPDATE `conversation_actor_template` SET `CreatureId`=109144, `CreatureModelId`=70210 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=107598, `CreatureModelId`=70123 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=110791, `CreatureModelId`=67345 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=107598, `CreatureModelId`=70123 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=109144, `CreatureModelId`=70210 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=116736, `CreatureModelId`=67345 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=109144, `CreatureModelId`=70210 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=109144, `CreatureModelId`=70210 WHERE `Id`=53609;

DELETE FROM `conversation_line_template` WHERE `Id` IN (7242, 3134, 3452, 9386, 9385, 9384, 9034, 9033, 8826, 9330, 9329, 9328, 9327, 9326, 6937, 9392, 9391, 9229, 9228, 9227, 9226, 9225, 9395, 9394, 9393, 9942, 6939, 5842, 6947, 9383, 9382, 9381, 8828, 8825, 8848, 8847, 8846, 8853, 9954, 9152, 9037, 9036, 9035, 8854, 8824, 9051, 7241, 3133, 8852, 8850, 5854, 9039, 9038, 3453);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(7242, 0, 795, 0, 0, 25996),
(3134, 0, 126, 0, 0, 25996),
(3452, 0, 129, 0, 0, 25996),
(9386, 7582, 0, 2, 0, 25996),
(9385, 3106, 0, 1, 0, 25996),
(9384, 0, 0, 0, 0, 25996),
(9034, 5389, 0, 1, 0, 25996),
(9033, 0, 0, 0, 0, 25996),
(8826, 0, 0, 0, 0, 25996),
(9330, 15854, 0, 2, 0, 25996),
(9329, 9672, 0, 2, 0, 25996),
(9328, 7216, 0, 0, 0, 25996),
(9327, 2868, 0, 1, 0, 25996),
(9326, 0, 0, 0, 0, 25996),
(6937, 0, 793, 0, 0, 25996),
(9392, 3443, 1546292960, 1, 0, 25996),
(9391, 0, 1546292960, 0, 0, 25996),
(9229, 25121, 0, 1, 0, 25996),
(9228, 16398, 0, 0, 0, 25996),
(9227, 12246, 0, 1, 0, 25996),
(9226, 3962, 0, 1, 0, 25996),
(9225, 0, 0, 0, 0, 25996),
(9395, 7375, 2387553392, 0, 0, 25996),
(9394, 3380, 2387553392, 1, 0, 25996),
(9393, 0, 2387553392, 0, 0, 25996),
(9942, 0, 795, 0, 0, 25996),
(6939, 0, 793, 0, 0, 25996),
(5842, 0, 813, 0, 0, 25996),
(6947, 0, 795, 0, 0, 25996),
(9383, 14408, 0, 2, 0, 25996),
(9382, 8629, 0, 1, 0, 25996),
(9381, 0, 0, 0, 0, 25996),
(8828, 0, 988, 0, 0, 25996),
(8825, 0, 2387550232, 0, 0, 25996),
(8848, 16133, 106, 0, 0, 25996),
(8847, 8437, 106, 0, 0, 25996),
(8846, 3552, 106, 0, 0, 25996),
(8853, 0, 106, 0, 0, 25996),
(9954, 0, 795, 0, 0, 25996),
(9152, 0, 575, 0, 0, 25996),
(9037, 12257, 2362382672, 0, 0, 25996),
(9036, 7302, 2362382672, 1, 0, 25996),
(9035, 0, 2362382672, 0, 0, 25996),
(8854, 0, 988, 0, 0, 25996),
(8824, 0, 1172985652, 0, 0, 25996),
(9051, 0, 988, 0, 0, 25996),
(7241, 0, 795, 0, 0, 25996),
(3133, 0, 126, 0, 0, 25996),
(8852, 10109, 0, 0, 0, 25996),
(8850, 0, 0, 0, 0, 25996),
(5854, 0, 813, 0, 0, 25996),
(9039, 3635, 0, 1, 0, 25996),
(9038, 0, 0, 0, 0, 25996),
(3453, 0, 129, 0, 0, 25996);


DELETE FROM `conversation_template` WHERE `Id` IN (1356, 1355, 1581, 1580, 3298, 3296, 3461, 3460, 4383, 4371, 3955, 3956, 3957, 2819, 2807, 4093, 4092, 4090, 4089, 3891, 4073, 4042, 3893, 3888, 3892, 3886, 3887, 3885, 3964, 4010, 3305);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(1356, 3134, 13581, 25996),
(1355, 3133, 9448, 25996),
(1581, 3453, 7591, 25996),
(1580, 3452, 10536, 25996),
(3298, 6939, 8316, 25996),
(3296, 6937, 10031, 25996),
(3461, 7242, 7101, 25996),
(3460, 7241, 7336, 25996),
(4383, 9954, 6527, 25996),
(4371, 9942, 7616, 25996),
(3955, 9033, 9816, 25996),
(3956, 9035, 18617, 25996),
(3957, 9038, 10187, 25996),
(2819, 5854, 2550, 25996),
(2807, 5842, 3600, 25996),
(4093, 9393, 14547, 25996),
(4092, 9391, 8574, 25996),
(4090, 9384, 10513, 25996),
(4089, 9381, 17851, 25996),
(3891, 8853, 21562, 25996),
(4073, 9326, 19682, 25996),
(4042, 9225, 32176, 25996),
(3893, 8854, 5460, 25996),
(3888, 8828, 7492, 25996),
(3892, 8850, 17207, 25996),
(3886, 8825, 2950, 25996),
(3887, 8826, 2100, 25996),
(3885, 8824, 2550, 25996),
(3964, 9051, 5526, 25996),
(4010, 9152, 9397, 25996),
(3305, 6947, 9950, 25996);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (248422 /*Stack of Bandages*/, 246036 /*Waterlogged Cache of Ancient Relics*/, 251960 /*The Raven's Eye Tablet*/, 246125 /*Musty Crate*/, 246844 /*Trap Door 004*/, 246841 /*Trap Door 011*/, 246840 /*Trap Door 001*/, 246843 /*Trap Door 003*/, 246842 /*Trap Door 002*/, 246837 /*Trap Door 010*/, 246836 /*Trao Door 008*/, 246839 /*Trap Door 005*/, 246838 /*Trap Door 006*/, 246835 /*Trap Door 009*/, 246834 /*Trap Door 007*/, 246889 /*Heavy Barnacled Door*/, 246888 /*Heavy Barnacled Door*/, 246890 /*Heavy Barnacled Door*/, 246919 /*The Naglfar*/, 249462 /*Crate of Dragur Dust*/, 224697 /*Fresh Carcass*/, 246948 /*Wall of Souls*/, 246947 /*Wall of Souls*/, 265477 /*Murky Fog*/, 265476 /*Murky Fog*/, 246435 /*Wall of Souls*/, 251963 /*7VR_VRYKUL_RITUALROCKS02 [scale x3]*/, 246763 /*The Maw of Souls*/, 245609 /*Invisible Door*/, 253001 /*Rune-etched Archway*/, 247041 /*Echoing Horn of the Damned*/, 245067 /*Kvaldir Cage*/, 245066 /*Kvaldir Cage*/, 245062 /*Kvaldir Cage*/, 245065 /*Kvaldir Cage*/, 245064 /*Kvaldir Cage*/, 245063 /*Kvaldir Cage*/, 266138 /*Containment Field*/, 266029 /*Felsoul Cage*/, 265521 /*Felsoul Cage*/, 265528 /*Telemancy Beacon*/, 265532 /*Telemancy Beacon*/, 265509 /*Broken Telemancy Beacon*/, 265440 /*Doodad_7sr_hubmanatree003*/, 254939 /*Library Door*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(248422, 0, 262144), -- Stack of Bandages
(246036, 94, 16416), -- Waterlogged Cache of Ancient Relics
(251960, 0, 262144), -- The Raven's Eye Tablet
(246125, 0, 4), -- Musty Crate
(246844, 1375, 0), -- Trap Door 004
(246841, 1375, 0), -- Trap Door 011
(246840, 1375, 0), -- Trap Door 001
(246843, 1375, 0), -- Trap Door 003
(246842, 1375, 0), -- Trap Door 002
(246837, 1375, 0), -- Trap Door 010
(246836, 1375, 0), -- Trao Door 008
(246839, 1375, 0), -- Trap Door 005
(246838, 1375, 0), -- Trap Door 006
(246835, 1375, 0), -- Trap Door 009
(246834, 1375, 0), -- Trap Door 007
(246889, 1375, 32), -- Heavy Barnacled Door
(246888, 1375, 32), -- Heavy Barnacled Door
(246890, 1375, 32), -- Heavy Barnacled Door
(246919, 0, 1048608), -- The Naglfar
(249462, 0, 4), -- Crate of Dragur Dust
(224697, 0, 16), -- Fresh Carcass
(246948, 0, 48), -- Wall of Souls
(246947, 0, 48), -- Wall of Souls
(265477, 0, 48), -- Murky Fog
(265476, 0, 48), -- Murky Fog
(246435, 0, 48), -- Wall of Souls
(251963, 114, 0), -- 7VR_VRYKUL_RITUALROCKS02 [scale x3]
(246763, 0, 48), -- The Maw of Souls
(245609, 14, 48), -- Invisible Door
(253001, 0, 48), -- Rune-etched Archway
(247041, 0, 16), -- Echoing Horn of the Damned
(245067, 0, 48), -- Kvaldir Cage
(245066, 0, 48), -- Kvaldir Cage
(245062, 0, 48), -- Kvaldir Cage
(245065, 0, 48), -- Kvaldir Cage
(245064, 0, 48), -- Kvaldir Cage
(245063, 0, 48), -- Kvaldir Cage
(266138, 0, 262144), -- Containment Field
(266029, 0, 262144), -- Felsoul Cage
(265521, 0, 262144), -- Felsoul Cage
(265528, 0, 262144), -- Telemancy Beacon
(265532, 0, 4), -- Telemancy Beacon
(265509, 0, 262144), -- Broken Telemancy Beacon
(265440, 0, 8192), -- Doodad_7sr_hubmanatree003
(254939, 0, 48); -- Library Door

UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247074; -- Wax Ingots
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247072; -- Wax Ingot
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247073; -- Wax Ingots
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247075; -- Secreted Wax Glob
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=247695; -- Elementium Slats
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=244473; -- Thunder Totem Stolen Goods
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=246710; -- Nomi's Silver Mackerel
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=246229; -- Cracked Warpsleeve
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=243403; -- Collision Wall
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=247050; -- Mornath's Curio Chest
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=247398; -- Soul Vaults Keyring
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=245507; -- Supply Cache
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=253081; -- Fruit of the Arcan'dor
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250434; -- Door C
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250636; -- Door J
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250276; -- Door K
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250278; -- Door B
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250272; -- Door A
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250273; -- Door D (Bottom)
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250274; -- Door D (Top)
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250275; -- Door G
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250634; -- Door F
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250635; -- Door I
UPDATE `gameobject_template_addon` SET `flags`=51 WHERE `entry`=250277; -- Door H
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=252774; -- Ancient Mana Crystal
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=257291; -- Nightborne Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=260493; -- Mana-Infused Gem

DELETE FROM `scene_template` WHERE (`SceneId`=1495 AND `ScriptPackageID`=1764) OR (`SceneId`=1494 AND `ScriptPackageID`=1762) OR (`SceneId`=1450 AND `ScriptPackageID`=1653);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1495, 17, 1764),
(1494, 25, 1762),
(1450, 27, 1653);


DELETE FROM `spell_target_position` WHERE (`ID`=203039 AND `EffectIndex`=0) OR (`ID`=229548 AND `EffectIndex`=1) OR (`ID`=229061 AND `EffectIndex`=0) OR (`ID`=229157 AND `EffectIndex`=0) OR (`ID`=231618 AND `EffectIndex`=0) OR (`ID`=231400 AND `EffectIndex`=0) OR (`ID`=231399 AND `EffectIndex`=1) OR (`ID`=228951 AND `EffectIndex`=0) OR (`ID`=230903 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(203039, 0, 1220, 3328.89, 4010.13, 1072.75, 25996), -- Spell: Téléportation de la terre Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(229548, 1, 1220, 476.29, 3745.05, 1.23, 25996), -- Spell: Téléportation au phare Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(229061, 0, 1220, 154.64, 5276.77, 1.2, 25996), -- Spell: Trajet en bateau Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(229157, 0, 1220, 686.79, 3735.8, 2.85, 25996), -- Spell: Entraves Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(231618, 0, 1220, 528.36, 3759.63, 33.02, 25996), -- Spell: Chute lente Efffect: 144 (SPELL_EFFECT_KNOCK_BACK_DEST)
(231400, 0, 1220, 518.32, 3774.72, 33.02, 25996), -- Spell: Téléportation : terrasse de Sempiterlune Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(231399, 1, 1220, 522.62, 3796.12, 1.55, 25996), -- Spell: Aura de téléportation Efffect: 3 (SPELL_EFFECT_DUMMY)
(228951, 0, 1220, 220.7, 3822.05, 0.36, 25996), -- Spell: Invocation de gondole sacrenuit Efffect: 28 (SPELL_EFFECT_SUMMON)
(230903, 0, 1220, 400.64, 3955.46, 1.39, 25996); -- Spell: Invocation d’un garde Efffect: 28 (SPELL_EFFECT_SUMMON)

UPDATE `spell_target_position` SET `MapID`=1153, `PositionX`=5563.7, `PositionY`=4599.9, `PositionZ`=141.71 WHERE (`ID`=171253 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=217698 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222547 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=2945.721, `PositionY`=874.7188, `VerifiedBuild`=25996 WHERE (`ID`=191558 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (104690 /*104690 (Beamer) - Harnais à basilic*/, 103235 /*103235 (Taskmaster Filthwhisker)*/, 103234 /*103234 (Taskmaster Skraggletail)*/, 103179 /*103179 (Gunksnout Geomancer)*/, 103177 /*103177 (Gunksnout Runt)*/, 103227 /*103227 (Wax Miner)*/, 102634 /*102634 (Scalewhisker Cavalry)*/, 102633 /*102633 (Waxeye Glazer) - Harnais à basilic*/, 103178 /*103178 (Gunksnout Scavenger)*/, 104248 /*104248 (Gazarogg the Stonespeaker)*/, 103197 /*103197 (Kill Credit: Kobold Candle) - Etat luminescent, Flamme de bougie violette*/, 103196 /*103196 (Kobold Candle)*/, 104244 /*104244 (Uzgarogg the Seer)*/, 131971 /*131971 (Bloodtotem Trapper)*/, 131953 /*131953 (Bloodtotem Survivor)*/, 104692 /*104692 (Greystone Flanker)*/, 104624 /*104624 (Wounded Highmountain Protector) - Wounded Sentinel Healing Tracker Proc*/, 104660 /*104660 (Blargrul the Siegebrul)*/, 111184 /*111184 (Greystone Shardcaster)*/, 104615 /*104615 (Greystone Flanker)*/, 109376 /*109376 (Rendezvous Point) - Effet de rendez-vous*/, 115625 /*115625 (Vanthir)*/, 102306 /*102306 (Swirling Pool) - Eaux turbulentes*/, 100354 /*100354 (Grasping Tentacle) - Ride Vehicle Hardcoded*/, 100353 /*100353 (Grasping Tentacle)*/, 100188 /*100188 (Piercing Tentacle) - Cage aux âmes*/, 99801 /*99801 (Destructor Tentacle) - Ride Vehicle Hardcoded*/, 99803 /*99803 (Destructor Tentacle)*/, 97099 /*97099 (Swirling Pool) - Bassin tourbillonnant*/, 98363 /*98363 (Grasping Tentacle) - Ride Vehicle Hardcoded*/, 99800 /*99800 (Grasping Tentacle)*/, 101502 /*101502 (Helya's Tentacle)*/, 100360 /*100360 (Grasping Tentacle) - Ride Vehicle Hardcoded*/, 100359 /*100359 (Grasping Tentacle)*/, 96759 /*96759 (Helya) - Cri sans âme*/, 101504 /*101504 (Grasping Tentacle) - Helya*/, 101814 /*101814 (Grasping Tentacle) - Helya*/, 114289 /*114289 (Skeletal Sorcerer) - Mana*/, 114288 /*114288 (Skeletal Warrior) - Rage*/, 99033 /*99033 (Helarjar Mistcaller) - Soigne-mer kvaldir*/, 99307 /*99307 (Skjal) - Voile*/, 98761 /*98761 (Soul Fragment)*/, 98989 /*98989 (Cosmic Scythe) - Faux cosmique*/, 100839 /*100839 (Cosmic Scythe)*/, 104906 /*104906 (Captured Val'kyr) - Siphon d’âme*/, 102830 /*102830 (Deceased Sorcerer) - Feindre la mort permanent*/, 98973 /*98973 (Skeletal Warrior) - Rage*/, 97365 /*97365 (Seacursed Mistmender)*/, 103115 /*103115 (Helheim) - Cage kvaldir*/, 98919 /*98919 (Seacursed Swiftblade) - Couvre-œil, Agenouillé, Ambidextrie*/, 97185 /*97185 (The Grimewalker) - Marteau en os*/, 97097 /*97097 (Helarjar Champion) - Ambidextrie*/, 97119 /*97119 (Shroud Hound)*/, 102742 /*102742 (Fallen Shieldmaiden) - Cadavre vrykul*/, 97182 /*97182 (Night Watch Mariner) - Casque, Escrime, Détection de l'invisibilité et du camouflage*/, 102325 /*102325 (Seacursed Rower)*/, 96754 /*Harbaron*/, 102769 /*102769 (Decrepit Runecarver) - Cadavre vrykul*/, 102326 /*102326 (Seacursed Rower) - Ride Vehicle Hardcoded, Rame*/, 98291 /*98291 (Seacursed Rower) - Ride Vehicle Hardcoded, Rame*/, 99188 /*99188 (Waterlogged Soul Guard) - Blocage*/, 102327 /*102327 (Seacursed Rower)*/, 96756 /*96756 (Ymiron, the Fallen King) - Puissance à zéro + régénération à zéro, Agenouillé*/, 101013 /*101013 (Captured Runecarver)*/, 102894 /*102894 (Runecarver Slave)*/, 102375 /*102375 (Runecarver Slave)*/, 114712 /*114712 (Runecarver Slave)*/, 102104 /*102104 (Enslaved Shieldmaiden) - Ride Vehicle Hardcoded*/, 102896 /*102896 (Enslaved Shieldmaiden)*/, 102108 /*102108 (Captured Shieldmaiden)*/, 97208 /*97208 (Spear) - Ride Vehicle Hardcoded, Lance*/, 97043 /*Esclavagiste maudit par les flots*/, 97163 /*97163 (Cursed Falke) - Plongeon*/, 97200 /*97200 (Seacursed Soulkeeper)*/, 115720 /*115720 (Dusk Lily Sigil)*/, 115604 /*115604 (Vanthir)*/, 115608 /*115608 (Silgryn) - Frappes entrecroisées*/, 115571 /*115571 (Echo of Vanthir)*/, 115687 /*115687 (Echo of Vanthir)*/, 115590 /*115590 (Echo of Vanthir)*/, 115570 /*115570 (Echo of Vanthir)*/, 115569 /*115569 (Echo of Vanthir)*/, 115584 /*115584 (Echo of Vanthir)*/, 115581 /*115581 (Echo of Vanthir)*/, 115557 /*115557 (First Arcanist Thalyssra)*/, 115260 /*115260 (Echo of Vanthir)*/, 116559 /*116559 (Echo of Vanthir)*/, 116558 /*116558 (Echo of Vanthir)*/, 115259 /*115259 (Echo of Vanthir) - Sommeil endormi*/, 115258 /*115258 (Echo of Vanthir)*/, 115531 /*115531 (Echo of Vanthir)*/, 115530 /*115530 (Echo of Vanthir)*/, 115535 /*Assassin rôdeur - Lames empoisonnées, Camouflage*/, 115248 /*115248 (First Arcanist Thalyssra)*/, 115247 /*115247 (Ly'leth Lunastre)*/, 115243 /*115243 (Image of Ly'leth Lunastre)*/, 115377 /*115377 (Shal'dorei Civilian)*/, 115072 /*115072 (Doomed Shal'dorei Civilian)*/, 115378 /*115378 (Shal'dorei Civilian)*/, 115075 /*115075 (Doomed Shal'dorei Civilian)*/, 116368 /*116368 (Felsoul Imp)*/, 115376 /*115376 (Maribeth)*/, 116411 /*116411 (Soul Engine Gateway)*/, 114998 /*114998 (Aargoss)*/, 115071 /*115071 (Doomed Shal'dorei Civilian)*/, 115080 /*115080 (Deline's Gondola)*/, 116367 /*116367 (Felborne Conspirator)*/, 115000 /*115000 (Doomed Shal'dorei Civilian)*/, 115003 /*115003 (Doomed Shal'dorei Civilian)*/, 115067 /*Silgryn - Frappes entrecroisées*/, 115002 /*115002 (Maribeth)*/, 115081 /*Deline - Ride Vehicle Hardcoded*/, 115079 /*Victoire*/, 115078 /*Arluelle - Frappes entrecroisées*/, 115073 /*115073 (Doomed Shal'dorei Civilian)*/, 115074 /*115074 (Doomed Shal'dorei Civilian)*/, 115014 /*115014 (Felsoul Imp)*/, 116659 /*116659 (Felsoul Ferry)*/, 115066 /*115066 (Shal'dorei Civilian)*/, 116317 /*116317 (Slowfall Rune)*/, 114956 /*114956 (Victoire)*/, 114949 /*114949 (Arluelle)*/, 116506 /*116506 (Image of Ly'leth Lunastre)*/, 116085 /*116085 (Arluelle)*/, 114970 /*114970 (Deline's Gondola)*/, 116044 /*116044 (Deline)*/, 114989 /*114989 (Jynn)*/, 114988 /*114988 (Ruthela)*/, 114987 /*114987 (Vyvari)*/, 114986 /*114986 (Celandra)*/, 114985 /*114985 (Scarleth)*/, 116054 /*116054 (Master Devlyn) - Le vase du maître*/, 115018 /*115018 (Silgryn)*/, 116057 /*116057 (Brigitte)*/, 116056 /*116056 (Emille)*/, 116055 /*116055 (Eneas)*/, 114978 /*114978 (Master Devlyn)*/, 116001 /*116001 (Eneas)*/, 114983 /*114983 (Thorvos)*/, 114984 /*114984 (Valanth)*/, 115992 /*115992 (Brigitte)*/, 115991 /*115991 (Emille)*/, 116584 /*116584 (The Waning Crescent)*/, 115772 /*115772 (Kal)*/, 114948 /*114948 (Silgryn)*/, 114969 /*114969 (Kill Credit: Silgryn Found)*/, 114868 /*114868 (Felborne Enforcer) - Détecteur, Détection de l'invisibilité et du camouflage*/, 114875 /*114875 (Felwing Purifier) - Image démoniaque, Détection de l'invisibilité et du camouflage*/, 115810 /*115810 (FX Stalker [DNT]) - Gangrefeu*/, 114873 /*114873 (Palace Warden) - Détecteur, Détection de l'invisibilité et du camouflage, Attaque de citoyens*/, 115710 /*Télémancien en chef Oculeth*/, 115371 /*Arcaniste Valtrois*/, 115736 /*Première arcaniste Thalyssra*/, 110698 /*110698 (Arluelle)*/, 112145 /*112145 (Arcanist Valtrois)*/, 112146 /*112146 (First Arcanist Thalyssra)*/, 112147 /*112147 (Chief Telemancer Oculeth)*/, 114291 /*114291 (Arcan'dor Vine)*/, 113585 /*113585 (Arcway Reclaimer) - Bouclier de distorsion*/, 113426 /*113426 (Place E.M.P.) - Etat visuel P.E.M.*/, 113332 /*113332 (Mana Hunter)*/, 113061 /*113061 (First Arcanist Thalyssra) - Déclencheur de zone Thalyssra 01*/, 113062 /*113062 (Arluin) - Déclencheur de zone Arluin 01*/, 113178 /*113178 (Archivist's Tome)*/, 113191 /*113191 (Duskwatch Archivist)*/, 113168 /*113168 (Duskwatch Ley-Warden)*/, 113172 /*113172 (Duskwatch Rune Scribe) - Scribouillage*/, 113202 /*113202 (Runebound Wyrm)*/, 113166 /*113166 (Duskwatch Arcblade)*/, 113114 /*113114 (Arluin) - Ambidextrie*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(104690, 0, 0, 0, 1, 0, 0, 0, 0, '202786'), -- 104690 (Beamer) - Harnais à basilic
(103235, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103235 (Taskmaster Filthwhisker)
(103234, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103234 (Taskmaster Skraggletail)
(103179, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103179 (Gunksnout Geomancer)
(103177, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103177 (Gunksnout Runt)
(103227, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103227 (Wax Miner)
(102634, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102634 (Scalewhisker Cavalry)
(102633, 0, 0, 0, 1, 0, 0, 0, 0, '202786'), -- 102633 (Waxeye Glazer) - Harnais à basilic
(103178, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103178 (Gunksnout Scavenger)
(104248, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104248 (Gazarogg the Stonespeaker)
(103197, 0, 0, 0, 1, 0, 0, 0, 0, '204258 197784'), -- 103197 (Kill Credit: Kobold Candle) - Etat luminescent, Flamme de bougie violette
(103196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103196 (Kobold Candle)
(104244, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104244 (Uzgarogg the Seer)
(131971, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131971 (Bloodtotem Trapper)
(131953, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131953 (Bloodtotem Survivor)
(104692, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104692 (Greystone Flanker)
(104624, 0, 0, 8, 1, 0, 0, 0, 0, '119800'), -- 104624 (Wounded Highmountain Protector) - Wounded Sentinel Healing Tracker Proc
(104660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104660 (Blargrul the Siegebrul)
(111184, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111184 (Greystone Shardcaster)
(104615, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104615 (Greystone Flanker)
(109376, 0, 0, 0, 1, 0, 0, 0, 0, '217706'), -- 109376 (Rendezvous Point) - Effet de rendez-vous
(115625, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115625 (Vanthir)
(102306, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'), -- 102306 (Swirling Pool) - Eaux turbulentes
(100354, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 100354 (Grasping Tentacle) - Ride Vehicle Hardcoded
(100353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100353 (Grasping Tentacle)
(100188, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- 100188 (Piercing Tentacle) - Cage aux âmes
(99801, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 99801 (Destructor Tentacle) - Ride Vehicle Hardcoded
(99803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99803 (Destructor Tentacle)
(97099, 0, 0, 50331648, 1, 0, 0, 0, 0, '195167'), -- 97099 (Swirling Pool) - Bassin tourbillonnant
(98363, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 98363 (Grasping Tentacle) - Ride Vehicle Hardcoded
(99800, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99800 (Grasping Tentacle)
(101502, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 101502 (Helya's Tentacle)
(100360, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 100360 (Grasping Tentacle) - Ride Vehicle Hardcoded
(100359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100359 (Grasping Tentacle)
(96759, 0, 0, 0, 1, 0, 0, 0, 0, '194603'), -- 96759 (Helya) - Cri sans âme
(101504, 0, 0, 50331648, 1, 0, 0, 0, 0, '198180'), -- 101504 (Grasping Tentacle) - Helya
(101814, 0, 0, 50331648, 1, 0, 0, 0, 0, '196450'), -- 101814 (Grasping Tentacle) - Helya
(114289, 0, 0, 0, 1, 0, 0, 0, 0, '198404'), -- 114289 (Skeletal Sorcerer) - Mana
(114288, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- 114288 (Skeletal Warrior) - Rage
(99033, 0, 0, 0, 1, 0, 0, 0, 0, '239777'), -- 99033 (Helarjar Mistcaller) - Soigne-mer kvaldir
(99307, 0, 0, 0, 1, 0, 0, 0, 0, '195517'), -- 99307 (Skjal) - Voile
(98761, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98761 (Soul Fragment)
(98989, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- 98989 (Cosmic Scythe) - Faux cosmique
(100839, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 100839 (Cosmic Scythe)
(104906, 0, 0, 50331648, 1, 0, 0, 0, 0, '207772'), -- 104906 (Captured Val'kyr) - Siphon d’âme
(102830, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 102830 (Deceased Sorcerer) - Feindre la mort permanent
(98973, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- 98973 (Skeletal Warrior) - Rage
(97365, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 97365 (Seacursed Mistmender)
(103115, 0, 0, 50331648, 1, 0, 0, 0, 0, '204001'), -- 103115 (Helheim) - Cage kvaldir
(98919, 0, 0, 0, 1, 0, 0, 0, 0, '195219 197227 42459'), -- 98919 (Seacursed Swiftblade) - Couvre-œil, Agenouillé, Ambidextrie
(97185, 0, 0, 0, 1, 0, 0, 0, 0, '194583'), -- 97185 (The Grimewalker) - Marteau en os
(97097, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 97097 (Helarjar Champion) - Ambidextrie
(97119, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97119 (Shroud Hound)
(102742, 0, 0, 0, 1, 0, 0, 0, 0, '203038'), -- 102742 (Fallen Shieldmaiden) - Cadavre vrykul
(97182, 0, 0, 0, 1, 0, 0, 0, 0, '199867 203605 67236'), -- 97182 (Night Watch Mariner) - Casque, Escrime, Détection de l'invisibilité et du camouflage
(102325, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 102325 (Seacursed Rower)
(96754, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Harbaron
(102769, 0, 0, 0, 1, 0, 0, 0, 0, '203058'), -- 102769 (Decrepit Runecarver) - Cadavre vrykul
(102326, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 202034'), -- 102326 (Seacursed Rower) - Ride Vehicle Hardcoded, Rame
(98291, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 193667'), -- 98291 (Seacursed Rower) - Ride Vehicle Hardcoded, Rame
(99188, 0, 0, 0, 1, 0, 0, 0, 0, '203602'), -- 99188 (Waterlogged Soul Guard) - Blocage
(102327, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 102327 (Seacursed Rower)
(96756, 0, 0, 0, 1, 0, 0, 0, 0, '118357 197227'), -- 96756 (Ymiron, the Fallen King) - Puissance à zéro + régénération à zéro, Agenouillé
(101013, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 101013 (Captured Runecarver)
(102894, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102894 (Runecarver Slave)
(102375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102375 (Runecarver Slave)
(114712, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 114712 (Runecarver Slave)
(102104, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 102104 (Enslaved Shieldmaiden) - Ride Vehicle Hardcoded
(102896, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102896 (Enslaved Shieldmaiden)
(102108, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 102108 (Captured Shieldmaiden)
(97208, 0, 0, 0, 1, 0, 0, 0, 0, '46598 191903'), -- 97208 (Spear) - Ride Vehicle Hardcoded, Lance
(97043, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Esclavagiste maudit par les flots
(97163, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- 97163 (Cursed Falke) - Plongeon
(97200, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97200 (Seacursed Soulkeeper)
(115720, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 115720 (Dusk Lily Sigil)
(115604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115604 (Vanthir)
(115608, 0, 0, 0, 1, 0, 0, 0, 0, '231514'), -- 115608 (Silgryn) - Frappes entrecroisées
(115571, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115571 (Echo of Vanthir)
(115687, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115687 (Echo of Vanthir)
(115590, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115590 (Echo of Vanthir)
(115570, 0, 0, 0, 1, 0, 12009, 0, 0, ''), -- 115570 (Echo of Vanthir)
(115569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115569 (Echo of Vanthir)
(115584, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 115584 (Echo of Vanthir)
(115581, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115581 (Echo of Vanthir)
(115557, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115557 (First Arcanist Thalyssra)
(115260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115260 (Echo of Vanthir)
(116559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116559 (Echo of Vanthir)
(116558, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116558 (Echo of Vanthir)
(115259, 0, 0, 0, 1, 0, 0, 0, 0, '217075'), -- 115259 (Echo of Vanthir) - Sommeil endormi
(115258, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115258 (Echo of Vanthir)
(115531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115531 (Echo of Vanthir)
(115530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115530 (Echo of Vanthir)
(115535, 0, 0, 131072, 1, 0, 0, 0, 0, '212061 118969'), -- Assassin rôdeur - Lames empoisonnées, Camouflage
(115248, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115248 (First Arcanist Thalyssra)
(115247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115247 (Ly'leth Lunastre)
(115243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115243 (Image of Ly'leth Lunastre)
(115377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115377 (Shal'dorei Civilian)
(115072, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115072 (Doomed Shal'dorei Civilian)
(115378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115378 (Shal'dorei Civilian)
(115075, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115075 (Doomed Shal'dorei Civilian)
(116368, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116368 (Felsoul Imp)
(115376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115376 (Maribeth)
(116411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116411 (Soul Engine Gateway)
(114998, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114998 (Aargoss)
(115071, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115071 (Doomed Shal'dorei Civilian)
(115080, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 115080 (Deline's Gondola)
(116367, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116367 (Felborne Conspirator)
(115000, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115000 (Doomed Shal'dorei Civilian)
(115003, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115003 (Doomed Shal'dorei Civilian)
(115067, 0, 0, 0, 1, 0, 0, 0, 0, '231514'), -- Silgryn - Frappes entrecroisées
(115002, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115002 (Maribeth)
(115081, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Deline - Ride Vehicle Hardcoded
(115079, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Victoire
(115078, 0, 0, 0, 1, 0, 0, 0, 0, '231222'), -- Arluelle - Frappes entrecroisées
(115073, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115073 (Doomed Shal'dorei Civilian)
(115074, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115074 (Doomed Shal'dorei Civilian)
(115014, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115014 (Felsoul Imp)
(116659, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116659 (Felsoul Ferry)
(115066, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115066 (Shal'dorei Civilian)
(116317, 0, 0, 0, 1, 0, 0, 0, 0, '231617'), -- 116317 (Slowfall Rune)
(114956, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114956 (Victoire)
(114949, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 114949 (Arluelle)
(116506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116506 (Image of Ly'leth Lunastre)
(116085, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116085 (Arluelle)
(114970, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 114970 (Deline's Gondola)
(116044, 0, 0, 33554432, 1, 0, 0, 0, 0, '230985'), -- 116044 (Deline)
(114989, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114989 (Jynn)
(114988, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114988 (Ruthela)
(114987, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114987 (Vyvari)
(114986, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114986 (Celandra)
(114985, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114985 (Scarleth)
(116054, 0, 0, 0, 1, 0, 0, 0, 0, '231000'), -- 116054 (Master Devlyn) - Le vase du maître
(115018, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 115018 (Silgryn)
(116057, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 116057 (Brigitte)
(116056, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 116056 (Emille)
(116055, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 116055 (Eneas)
(114978, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114978 (Master Devlyn)
(116001, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 116001 (Eneas)
(114983, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114983 (Thorvos)
(114984, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114984 (Valanth)
(115992, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115992 (Brigitte)
(115991, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115991 (Emille)
(116584, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 116584 (The Waning Crescent)
(115772, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 115772 (Kal)
(114948, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 114948 (Silgryn)
(114969, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114969 (Kill Credit: Silgryn Found)
(114868, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236'), -- 114868 (Felborne Enforcer) - Détecteur, Détection de l'invisibilité et du camouflage
(114875, 0, 0, 0, 1, 0, 0, 0, 0, '213486 67236'), -- 114875 (Felwing Purifier) - Image démoniaque, Détection de l'invisibilité et du camouflage
(115810, 0, 0, 0, 1, 0, 0, 0, 0, '185866'), -- 115810 (FX Stalker [DNT]) - Gangrefeu
(114873, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236 228771'), -- 114873 (Palace Warden) - Détecteur, Détection de l'invisibilité et du camouflage, Attaque de citoyens
(115710, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Télémancien en chef Oculeth
(115371, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcaniste Valtrois
(115736, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Première arcaniste Thalyssra
(110698, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110698 (Arluelle)
(112145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112145 (Arcanist Valtrois)
(112146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112146 (First Arcanist Thalyssra)
(112147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112147 (Chief Telemancer Oculeth)
(114291, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114291 (Arcan'dor Vine)
(113585, 0, 0, 0, 1, 0, 0, 0, 0, '221573'), -- 113585 (Arcway Reclaimer) - Bouclier de distorsion
(113426, 0, 0, 0, 1, 0, 0, 0, 0, '225630'), -- 113426 (Place E.M.P.) - Etat visuel P.E.M.
(113332, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113332 (Mana Hunter)
(113061, 0, 0, 0, 1, 0, 0, 0, 0, '225338'), -- 113061 (First Arcanist Thalyssra) - Déclencheur de zone Thalyssra 01
(113062, 0, 0, 0, 1, 0, 0, 0, 0, '225337'), -- 113062 (Arluin) - Déclencheur de zone Arluin 01
(113178, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113178 (Archivist's Tome)
(113191, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113191 (Duskwatch Archivist)
(113168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113168 (Duskwatch Ley-Warden)
(113172, 0, 0, 0, 1, 0, 0, 0, 0, '225305'), -- 113172 (Duskwatch Rune Scribe) - Scribouillage
(113202, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 113202 (Runebound Wyrm)
(113166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113166 (Duskwatch Arcblade)
(113114, 0, 0, 1, 1, 0, 0, 0, 0, '42459'); -- 113114 (Arluin) - Ambidextrie

UPDATE `creature_template_addon` SET `auras`='204693' WHERE `entry`=104243; -- 104243 (Bound Elemental)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=101644; -- 101644 (Greystone Shardmaster)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110501; -- 110501 (Snowrunner Fox)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=110502; -- 110502 (Snowstrider Bull)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=110503; -- 110503 (Young Snowstrider)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=102871; -- 102871 (Gilnean Shotgunner)
UPDATE `creature_template_addon` SET `auras`='203303' WHERE `entry`=102866; -- 102866 (Gilnean Swiftclaw)
UPDATE `creature_template_addon` SET `auras`='221006 214338 214955' WHERE `entry`=96590; -- 96590 (Gurbog da Basher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=95718; -- Aigle de guerre
UPDATE `creature_template_addon` SET `auras`='164276 213439' WHERE `entry`=99217; -- 99217 (Naxa)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108185; -- 108185 (Coldscale Gazecrawler)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=99699; -- 99699 (Thunder Drum Circle)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='191226' WHERE `entry`=96084; -- 96084 (Sella Waterwise)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=96083; -- 96083 (Rordan Waterwise)
UPDATE `creature_template_addon` SET `auras`='214285' WHERE `entry`=107726; -- 107726 (Ethel Waterwise)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=96782; -- 96782 (Lucian Trias)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=34330; -- 34330 (Jones)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=107326; -- 107326 (Draemus)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108931; -- 108931 (Vineyard Laborer)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108873; -- 108873 (Distillery Attendant)
UPDATE `creature_template_addon` SET `auras`='213741' WHERE `entry`=113974; -- 113974 (Leyline Spiderling)
UPDATE `creature_template_addon` SET `auras`='187057' WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template_addon` SET `auras`='155893' WHERE `entry`=115272; -- 115272 (Felsworn Overseer)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=112150; -- Lapin à tout faire (JSB)
UPDATE `creature_template_addon` SET `auras`='209887 209898' WHERE `entry`=105835; -- 105835 (Lunastre Attendant)
UPDATE `creature_template_addon` SET `auras`='209213' WHERE `entry`=109950; -- 109950 (Unstable Illusion)
UPDATE `creature_template_addon` SET `auras`='219489 223531 214336' WHERE `entry`=109954; -- 109954 (Magister Phaedris)
UPDATE `creature_template_addon` SET `auras`='221101 221104' WHERE `entry`=111056; -- 111056 (Tiny Illusory Dancer)
UPDATE `creature_template_addon` SET `auras`='225291 152209' WHERE `entry`=113123; -- 113123 (Leytouched Cliffquill)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=101878; -- Inquisiteur gangrâme
UPDATE `creature_template_addon` SET `auras`='203761' WHERE `entry`=114470; -- 114470 (Duskwatch Orbitist)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=108386; -- 108386 (Ambrena)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=108385; -- 108385 (Lunette)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=108810; -- 108810 (Chloe)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=108387; -- 108387 (Donatien)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=108812; -- 108812 (Iseult)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=113514; -- 113514 (Joshen Lafave)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=113516; -- 113516 (Dasdonia)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=108388; -- 108388 (Clotaire)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='186571' WHERE `entry`=108811; -- 108811 (Audric)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113850; -- 113850 (Wyrmtongue Gorger)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=113840; -- 113840 (Shal'dorei Harpist)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=113752; -- 113752 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=113618; -- Loyaliste de Suramar
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=113619; -- 113619 (Suramar Loyalist)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=107451; -- 107451 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `mount`=69468 WHERE `entry`=106032; -- 106032 (Duskwatch Battlemaster)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='203761 67236 155893' WHERE `entry`=113707; -- 113707 (Duskwatch Astralite)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110354; -- 110354 (Coryn)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=111621; -- 111621 (Duskwatch Executor)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=104235; -- 104235 (Val'Sharah Refugee)
UPDATE `creature_template_addon` SET `auras`='225842' WHERE `entry`=72587; -- VFX Bunny
UPDATE `creature_template_addon` SET `auras`='201446 225154' WHERE `entry`=98548; -- 98548 (Chief Telemancer Oculeth)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116715; -- Rebelle souffrenuit
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=111901; -- 111901 (Suramar Refugee)
UPDATE `creature_template_addon` SET `auras`='209901' WHERE `entry`=111903; -- 111903 (Lunastre Attendant)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=115924; -- Magus garde de l’aube
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=115926; -- Sentinelle de Darnassus
UPDATE `creature_template_addon` SET `auras`='227309' WHERE `entry`=113936; -- 113936 (Rudaux)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114927; -- 114927 (Fist of the Duskwatch)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=102415; -- 102415 (Suramar Skyhunter)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=113201; -- 113201 (Thicket Manahunter)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=112972; -- Ecrabouilleur des fourrés géant
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=104404; -- 104404 (Thicket Hunter)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=100778; -- 100778 (Nightborne Trapper)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110253; -- Rôdeur plumelune
UPDATE `creature_template_addon` SET `auras`='70628' WHERE `entry`=110042; -- 110042 (Heartwood Stag)
UPDATE `creature_template_addon` SET `auras`='216946' WHERE `entry`=109023; -- 109023 (Shadescale Flyeater)
UPDATE `creature_template_addon` SET `auras`='223741' WHERE `entry`=108869; -- Travailleur du vignoble
UPDATE `creature_template_addon` SET `auras`='203761 67236 220618' WHERE `entry`=112489; -- 112489 (Callus)
UPDATE `creature_template_addon` SET `auras`='203761 67236 228118' WHERE `entry`=109652; -- 109652 (Duskwatch Warpcaster)
UPDATE `creature_template_addon` SET `auras`='203761 67236 220618' WHERE `entry`=112531; -- 112531 (Leleyna)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110655; -- 110655 (Duskmere Smuggler)
UPDATE `creature_template_addon` SET `auras`='203761' WHERE `entry`=111750; -- 111750 (Felborne Collaborator)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='231655' WHERE `entry`=114958; -- 114958 (Duskwatch Subjugator)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=116653; -- 116653 (Loyalist Spectator)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `auras`='' WHERE `entry`=114888; -- 114888 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `auras`='203761 67236 228119' WHERE `entry`=108188; -- 108188 (Imperial Arcbinder)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=111649; -- 111649 (Ambassador D'vwinn)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=111489; -- 111489 (Loyalist Sycophant)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=111490; -- Flagorneur loyaliste
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=107342; -- 107342 (Duskwatch Spell-Fencer)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=112190; -- Jeune sabre curieux

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (111446, 99708, 114904, 101645, 110043, 108875, 97498, 99636, 113572, 115806, 113268, 113172, 114931, 99755, 111490, 111489, 104615, 110042, 114474, 113270, 114849, 102415, 108096, 113679, 110944, 99894, 114874, 112370, 111485, 116117, 103227, 111730, 100237, 112825, 102747, 99862, 110499, 119081, 107567, 99749, 106654, 115381, 102960, 114472, 113707, 109670, 115606, 113634, 111869, 111007, 99652, 111872, 116206, 131953, 114958, 112796, 106032, 113184, 110728, 101785, 115279, 116715, 113166, 99789, 98555, 113619, 105759, 105481, 111414, 116063, 111523, 111389, 105653, 111376, 111377, 103177, 100635, 109023, 107449, 114927, 112910, 108188, 114468, 113618, 111612, 114929, 105372, 110418, 113190, 116368, 109647, 113765, 112331, 111556, 113126, 107801, 109652, 110496, 131971, 111622, 111197, 113850, 105232, 104404, 105655, 111749, 117355, 114995, 96691, 107726, 100778, 107727, 108554, 101688, 114926, 106648, 111747, 105014, 109159, 115012, 103179, 105650, 110502, 111675, 99913, 113738, 109950, 112827, 102634, 104243, 104691, 102633, 114876, 113577, 98979, 113332, 108871, 113168, 114873, 106609, 114875, 105656, 104810, 104757, 115595, 114470, 115690, 112336, 107342, 109650, 113061, 97732, 114897, 99533, 112909, 114480, 104660, 114845, 111045, 103485, 113122, 104837, 111921, 107717, 108017, 113205, 111050, 105645, 115926, 119907, 111614, 103592, 114869, 104845, 99765, 114865, 108185, 117412, 106055, 115924, 111484, 113606, 102203, 116716, 102746, 97729, 100780, 121413, 116653, 101644, 115594, 112543, 113974, 105640, 113675, 96084, 102495, 111620, 109954, 119079, 105480, 96083, 106810, 111558, 102748, 103090, 101878, 104369, 118678, 111557, 103178, 95688, 113585, 107333, 104692, 111750, 95718, 115562, 112545, 96690, 109199, 115272, 106111, 113191, 69759, 107720, 114868, 121416, 98017, 113127, 108082, 105662, 119067, 114946, 113114, 114924, 116068, 102866, 114866, 113571, 105644, 116118, 108129, 107660, 99225, 99624, 116360, 115273, 108148, 104624, 41200, 111870, 108553, 116116, 111871, 95722, 99711, 106109, 112489, 114718, 116367, 115691, 110365, 101630, 109782, 99912, 115526, 119061, 115517, 115535, 103886, 99670, 101825, 102875, 115607, 113198, 114879, 97976, 111445, 103631, 111621, 115014, 101821, 106263, 106262, 106261, 112972, 101823, 114998, 99672, 113633, 111056, 115561, 110501, 110503, 99216, 119059, 103235, 103234, 112531, 113201, 111618, 99214, 103223, 109055, 107797, 102205, 119077, 104248, 113123, 99753, 110415, 110726, 107994, 100437, 99905, 97750, 110727, 110354, 99903, 97508, 99217, 110949, 108528, 102871, 107988, 99859, 100777, 103733, 104244, 107772, 111649, 112392, 99485, 100559, 95717, 101813, 104690, 101577, 115687, 94877, 97013, 96590, 113208, 97572, 122130, 97506, 113124, 111699);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(111446, 0, 25996),
(99708, 0, 25996),
(114904, 0, 25996),
(101645, 0, 25996),
(110043, 0, 25996),
(108875, 0, 25996),
(97498, 0, 25996),
(99636, 0, 25996),
(113572, 0, 25996),
(115806, 0, 25996),
(113268, 0, 25996),
(113172, 0, 25996),
(114931, 0, 25996),
(99755, 0, 25996),
(111490, 0, 25996),
(111489, 0, 25996),
(104615, 0, 25996),
(110042, 0, 25996),
(114474, 0, 25996),
(113270, 0, 25996),
(114849, 0, 25996),
(102415, 0, 25996),
(108096, 0, 25996),
(113679, 0, 25996),
(110944, 0, 25996),
(99894, 0, 25996),
(114874, 0, 25996),
(112370, 0, 25996),
(111485, 0, 25996),
(116117, 0, 25996),
(103227, 0, 25996),
(111730, 0, 25996),
(100237, 0, 25996),
(112825, 0, 25996),
(102747, 0, 25996),
(99862, 0, 25996),
(110499, 0, 25996),
(119081, 0, 25996),
(107567, 0, 25996),
(99749, 0, 25996),
(106654, 0, 25996),
(115381, 0, 25996),
(102960, 0, 25996),
(114472, 0, 25996),
(113707, 0, 25996),
(109670, 0, 25996),
(115606, 0, 25996),
(113634, 0, 25996),
(111869, 0, 25996),
(111007, 0, 25996),
(99652, 0, 25996),
(111872, 0, 25996),
(116206, 0, 25996),
(131953, 0, 25996),
(114958, 0, 25996),
(112796, 0, 25996),
(106032, 0, 25996),
(113184, 0, 25996),
(110728, 0, 25996),
(101785, 0, 25996),
(115279, 0, 25996),
(116715, 0, 25996),
(113166, 0, 25996),
(99789, 0, 25996),
(98555, 0, 25996),
(113619, 0, 25996),
(105759, 0, 25996),
(105481, 0, 25996),
(111414, 0, 25996),
(116063, 0, 25996),
(111523, 0, 25996),
(111389, 0, 25996),
(105653, 0, 25996),
(111376, 0, 25996),
(111377, 0, 25996),
(103177, 0, 25996),
(100635, 0, 25996),
(109023, 0, 25996),
(107449, 0, 25996),
(114927, 0, 25996),
(112910, 0, 25996),
(108188, 0, 25996),
(114468, 0, 25996),
(113618, 0, 25996),
(111612, 0, 25996),
(114929, 0, 25996),
(105372, 0, 25996),
(110418, 0, 25996),
(113190, 0, 25996),
(116368, 0, 25996),
(109647, 0, 25996),
(113765, 0, 25996),
(112331, 0, 25996),
(111556, 0, 25996),
(113126, 0, 25996),
(107801, -1, 25996),
(109652, 0, 25996),
(110496, 0, 25996),
(131971, 0, 25996),
(111622, 0, 25996),
(111197, 0, 25996),
(113850, 0, 25996),
(105232, 0, 25996),
(104404, 0, 25996),
(105655, 0, 25996),
(111749, 0, 25996),
(117355, 0, 25996),
(114995, 0, 25996),
(96691, 0, 25996),
(107726, 0, 25996),
(100778, 0, 25996),
(107727, 0, 25996),
(108554, 0, 25996),
(101688, 0, 25996),
(114926, 0, 25996),
(106648, 0, 25996),
(111747, 0, 25996),
(105014, 0, 25996),
(109159, 0, 25996),
(115012, 0, 25996),
(103179, 0, 25996),
(105650, 0, 25996),
(110502, 0, 25996),
(111675, 0, 25996),
(99913, 0, 25996),
(113738, 0, 25996),
(109950, 0, 25996),
(112827, 0, 25996),
(102634, 0, 25996),
(104243, 0, 25996),
(104691, 0, 25996),
(102633, 0, 25996),
(114876, 0, 25996),
(113577, 0, 25996),
(98979, 0, 25996),
(113332, 0, 25996),
(108871, 0, 25996),
(113168, 0, 25996),
(114873, 0, 25996),
(106609, 0, 25996),
(114875, 0, 25996),
(105656, 0, 25996),
(104810, 0, 25996),
(104757, 0, 25996),
(115595, 0, 25996),
(114470, 0, 25996),
(115690, 0, 25996),
(112336, 0, 25996),
(107342, 0, 25996),
(109650, 0, 25996),
(113061, 0, 25996),
(97732, 0, 25996),
(114897, 0, 25996),
(99533, 0, 25996),
(112909, 0, 25996),
(114480, 0, 25996),
(104660, 0, 25996),
(114845, 0, 25996),
(111045, 0, 25996),
(103485, 0, 25996),
(113122, 0, 25996),
(104837, 0, 25996),
(111921, 0, 25996),
(107717, 0, 25996),
(108017, 0, 25996),
(113205, 0, 25996),
(111050, 0, 25996),
(105645, 0, 25996),
(115926, 0, 25996),
(119907, 0, 25996),
(111614, 0, 25996),
(103592, 0, 25996),
(114869, 0, 25996),
(104845, 0, 25996),
(99765, 0, 25996),
(114865, 0, 25996),
(108185, 0, 25996),
(117412, 0, 25996),
(106055, 0, 25996),
(115924, 0, 25996),
(111484, 0, 25996),
(113606, 0, 25996),
(102203, 0, 25996),
(116716, 0, 25996),
(102746, 0, 25996),
(97729, 0, 25996),
(100780, 0, 25996),
(121413, 0, 25996),
(116653, 0, 25996),
(101644, 0, 25996),
(115594, 0, 25996),
(112543, 0, 25996),
(113974, 0, 25996),
(105640, 0, 25996),
(113675, 0, 25996),
(96084, 0, 25996),
(102495, 0, 25996),
(111620, 0, 25996),
(109954, 0, 25996),
(119079, 0, 25996),
(105480, 0, 25996),
(96083, 0, 25996),
(106810, 0, 25996),
(111558, 0, 25996),
(102748, 0, 25996),
(103090, 0, 25996),
(101878, 0, 25996),
(104369, 0, 25996),
(118678, 0, 25996),
(111557, 0, 25996),
(103178, 0, 25996),
(95688, 0, 25996),
(113585, 0, 25996),
(107333, 0, 25996),
(104692, 0, 25996),
(111750, 0, 25996),
(95718, 0, 25996),
(115562, 0, 25996),
(112545, 0, 25996),
(96690, 0, 25996),
(109199, 0, 25996),
(115272, 0, 25996),
(106111, 0, 25996),
(113191, 0, 25996),
(69759, 0, 25996),
(107720, 0, 25996),
(114868, 0, 25996),
(121416, 0, 25996),
(98017, 0, 25996),
(113127, 0, 25996),
(108082, 0, 25996),
(105662, 0, 25996),
(119067, 0, 25996),
(114946, 0, 25996),
(113114, 0, 25996),
(114924, 0, 25996),
(116068, 0, 25996),
(102866, 0, 25996),
(114866, 0, 25996),
(113571, 0, 25996),
(105644, 0, 25996),
(116118, 0, 25996),
(108129, 0, 25996),
(107660, 0, 25996),
(99225, 0, 25996),
(99624, 0, 25996),
(116360, 0, 25996),
(115273, 0, 25996),
(108148, 0, 25996),
(104624, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(41200, 0, 25996),
(111870, 0, 25996),
(108553, 0, 25996),
(116116, 0, 25996),
(111871, 0, 25996),
(95722, 0, 25996),
(99711, 0, 25996),
(106109, 0, 25996),
(112489, 0, 25996),
(114718, 0, 25996),
(116367, 0, 25996),
(115691, 0, 25996),
(110365, 0, 25996),
(101630, 0, 25996),
(109782, 0, 25996),
(99912, 0, 25996),
(115526, 0, 25996),
(119061, 0, 25996),
(115517, 0, 25996),
(115535, 0, 25996),
(103886, 0, 25996),
(99670, 0, 25996),
(101825, 0, 25996),
(102875, 0, 25996),
(115607, 0, 25996),
(113198, 0, 25996),
(114879, 0, 25996),
(97976, 0, 25996),
(111445, 0, 25996),
(103631, 0, 25996),
(111621, 0, 25996),
(115014, 0, 25996),
(101821, 0, 25996),
(106263, 0, 25996),
(106262, 0, 25996),
(106261, 0, 25996),
(112972, 0, 25996),
(101823, 0, 25996),
(114998, 0, 25996),
(99672, 0, 25996),
(113633, 0, 25996),
(111056, 0, 25996),
(115561, 0, 25996),
(110501, 0, 25996),
(110503, 0, 25996),
(99216, 0, 25996),
(119059, 0, 25996),
(103235, 0, 25996),
(103234, 0, 25996),
(112531, 0, 25996),
(113201, 0, 25996),
(111618, 0, 25996),
(99214, 0, 25996),
(103223, 0, 25996),
(109055, 1, 25996),
(107797, -1, 25996),
(102205, 0, 25996),
(119077, 0, 25996),
(104248, 0, 25996),
(113123, 0, 25996),
(99753, 0, 25996),
(110415, 0, 25996),
(110726, 0, 25996),
(107994, 0, 25996),
(100437, 0, 25996),
(99905, 0, 25996),
(97750, 0, 25996),
(110727, 0, 25996),
(110354, 0, 25996),
(99903, 0, 25996),
(97508, 0, 25996),
(99217, 0, 25996),
(110949, 0, 25996),
(108528, 0, 25996),
(102871, 0, 25996),
(107988, 0, 25996),
(99859, 0, 25996),
(100777, 0, 25996),
(103733, 0, 25996),
(104244, 0, 25996),
(107772, 0, 25996),
(111649, 0, 25996),
(112392, 0, 25996),
(99485, 0, 25996),
(100559, 0, 25996),
(95717, 0, 25996),
(101813, 0, 25996),
(104690, 0, 25996),
(101577, 0, 25996),
(115687, 0, 25996),
(94877, 0, 25996),
(97013, 0, 25996),
(96590, 0, 25996),
(113208, 0, 25996),
(97572, 0, 25996),
(122130, 0, 25996),
(97506, 0, 25996),
(113124, 0, 25996),
(111699, 0, 25996);



UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65131;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62864;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65044;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6671286, `VerifiedBuild`=25996 WHERE `DisplayID`=40021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64568;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65436;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68664;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65105;
UPDATE `creature_model_info` SET `BoundingRadius`=1.251622, `VerifiedBuild`=25996 WHERE `DisplayID`=33692;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67704;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67703;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65475;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42409;
UPDATE `creature_model_info` SET `BoundingRadius`=3.858196, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=68549;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67335;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4410623, `VerifiedBuild`=25996 WHERE `DisplayID`=65129;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67702;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33309;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67831;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67848;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67832;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64964;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=58573;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34706;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64335;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66323;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63943;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65089;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64985;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40713;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70251;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66647;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65770;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65769;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66650;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66059;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66058;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66060;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66653;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66061;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40716;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61204;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47992;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=41300;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67044;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70380;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66294;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66389;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65466;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70221;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65533;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70371;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70920;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65470;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65469;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65471;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66394;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65706;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66392;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65705;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63712;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66297;
UPDATE `creature_model_info` SET `BoundingRadius`=0.95975, `CombatReach`=4.125, `VerifiedBuild`=25996 WHERE `DisplayID`=63703;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65484;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66229;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66227;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63859;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70255;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64343;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64671;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68220;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66296;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72888;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68343;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67489;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64672;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64677;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6640207, `CombatReach`=0.54 WHERE `DisplayID`=69273;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66495;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66346;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66348;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65778;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66681;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66618;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66345;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65043;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67211;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70528;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=985;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66852;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26725;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66183;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70529;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66103;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=30710;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66181;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64467;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67179;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67556;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65823;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66102;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65079;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66119;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66091;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25630;
UPDATE `creature_model_info` SET `BoundingRadius`=7.5, `CombatReach`=7.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73937;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5364968, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73873;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5364968, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73874;
UPDATE `creature_model_info` SET `BoundingRadius`=1.322611, `CombatReach`=2.32875, `VerifiedBuild`=25996 WHERE `DisplayID`=73926;
UPDATE `creature_model_info` SET `BoundingRadius`=2.156982, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73880;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=73878;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5852861, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=73876;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6964399, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=74240;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=74239;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71707;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73848;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73729;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=74234;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=74233;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73847;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73867;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=74219;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71709;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66503;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73604;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=48804;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32214;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74245;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=55964;
UPDATE `creature_model_info` SET `BoundingRadius`=1.088063, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=74232;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2544206, `CombatReach`=0.575, `VerifiedBuild`=25996 WHERE `DisplayID`=74260;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73864;
UPDATE `creature_model_info` SET `BoundingRadius`=2.629644, `CombatReach`=7.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73595;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73634;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73633;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73632;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73631;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73630;
UPDATE `creature_model_info` SET `CombatReach`=1.5 WHERE `DisplayID`=70078;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73627;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73629;
UPDATE `creature_model_info` SET `BoundingRadius`=1.622357, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=63867;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73853;
UPDATE `creature_model_info` SET `BoundingRadius`=1.088063, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=73854;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67345;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5103856, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=71613;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8366695, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73190;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65962;
UPDATE `creature_model_info` SET `BoundingRadius`=1.22464, `CombatReach`=2.15625, `VerifiedBuild`=25996 WHERE `DisplayID`=72685;
UPDATE `creature_model_info` SET `BoundingRadius`=1.13161, `CombatReach`=1.65 WHERE `DisplayID`=61928;
UPDATE `creature_model_info` SET `BoundingRadius`=1.088063, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=72666;
UPDATE `creature_model_info` SET `BoundingRadius`=1.360078, `CombatReach`=2.15625, `VerifiedBuild`=25996 WHERE `DisplayID`=72706;
UPDATE `creature_model_info` SET `BoundingRadius`=0.435062, `CombatReach`=6, `VerifiedBuild`=25996 WHERE `DisplayID`=72693;
UPDATE `creature_model_info` SET `BoundingRadius`=1.22464, `CombatReach`=2.15625, `VerifiedBuild`=25996 WHERE `DisplayID`=72705;
UPDATE `creature_model_info` SET `BoundingRadius`=1.088063, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=72692;
UPDATE `creature_model_info` SET `BoundingRadius`=1.360078, `CombatReach`=2.15625, `VerifiedBuild`=25996 WHERE `DisplayID`=72686;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9797121, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=72687;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9797121, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=72665;

DELETE FROM `npc_vendor` WHERE (`entry`=115736 AND `item`=128609 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=128600 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=128602 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=128603 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=137850 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=137979 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=137976 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=137973 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=115736 AND `item`=142120 AND `ExtendedCost`=6068 AND `type`=1) OR (`entry`=115736 AND `item`=139686 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=115736 AND `item`=140575 AND `ExtendedCost`=6107 AND `type`=1) OR (`entry`=115736 AND `item`=139604 AND `ExtendedCost`=6050 AND `type`=1) OR (`entry`=115736 AND `item`=140325 AND `ExtendedCost`=6106 AND `type`=1) OR (`entry`=115736 AND `item`=136899 AND `ExtendedCost`=6108 AND `type`=1) OR (`entry`=115736 AND `item`=139683 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=115736 AND `item`=139600 AND `ExtendedCost`=6051 AND `type`=1) OR (`entry`=115736 AND `item`=140324 AND `ExtendedCost`=6105 AND `type`=1) OR (`entry`=115736 AND `item`=140746 AND `ExtendedCost`=6109 AND `type`=1) OR (`entry`=115736 AND `item`=140015 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=115736 AND `item`=139979 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=115736 AND `item`=121738 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=115736 AND `item`=121736 AND `ExtendedCost`=6118 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(115736, 47, 128609, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement de cape (Lien d'Intelligence)
(115736, 46, 128600, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement d'anneau (Lien de coup critique)
(115736, 45, 128602, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement d'anneau (Lien de Maîtrise)
(115736, 44, 128603, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement d'anneau (Lien de polyvalence)
(115736, 43, 137850, 0, 6066, 1, 0, 0, 25996), -- Dessin : Pendentif en rubistre subtil
(115736, 42, 137979, 0, 6066, 1, 0, 0, 25996), -- Patron : Mules en soie tissée imprégnée
(115736, 41, 137976, 0, 6066, 1, 0, 0, 25996), -- Patron : Culotte en soie tissée imprégnée
(115736, 40, 137973, 0, 6066, 1, 0, 0, 25996), -- Patron : Brassards en soie tissée imprégnée
(115736, 39, 142120, 0, 6068, 1, 0, 0, 25996), -- Recette : Potion de puissance prolongée
(115736, 37, 139686, 0, 6125, 1, 0, 0, 25996), -- Espauliers de seigneur de bataille
(115736, 25, 140575, 0, 6107, 1, 0, 0, 25996), -- Tabard des Souffrenuit
(115736, 24, 139604, 0, 6050, 1, 0, 0, 25996), -- Pendentif d'améthyste trempé de mana
(115736, 23, 140325, 0, 6106, 1, 0, 0, 25996), -- Masque de fête artisanal
(115736, 22, 136899, 0, 6108, 1, 0, 0, 25996), -- Oeil éteint
(115736, 21, 139683, 0, 6125, 1, 0, 0, 25996), -- Gantelets de seigneur de bataille
(115736, 9, 139600, 0, 6051, 1, 0, 0, 25996), -- Cordelière tressée en fil de mana
(115736, 7, 140324, 0, 6105, 1, 0, 0, 25996), -- Balise de télémancie mobile
(115736, 6, 140746, 0, 6109, 1, 0, 0, 25996), -- Carte au trésor : Suramar
(115736, 5, 140015, 0, 6118, 1, 0, 0, 25996), -- Solerets gangrâme de récupération
(115736, 4, 139979, 0, 6118, 1, 0, 0, 25996), -- Souliers des Coursenuit
(115736, 3, 121738, 0, 6118, 1, 0, 0, 25996), -- Bottes de réfugié de Ferbois
(115736, 2, 121736, 0, 6118, 1, 0, 0, 25996); -- Mules « glissantes » sacrenuit

UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=115736 AND `item`=140218 AND `ExtendedCost`=0 AND `type`=1); -- Faveur du cherche-mana
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Parchemin léger
UPDATE `npc_vendor` SET `slot`=13, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion grossière
UPDATE `npc_vendor` SET `slot`=12, `maxcount`=2, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion basique
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Encre d'ingénieur
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Déclencheur sensible
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Crosse en noyer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Crosse lourde
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Crosse en bois
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Kit de bricoleur
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=140324 AND `ExtendedCost`=0 AND `type`=1); -- Balise de télémancie mobile
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Parchemin léger
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion grossière
UPDATE `npc_vendor` SET `slot`=12, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion basique
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Encre d'ingénieur
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Déclencheur sensible
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Crosse en noyer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Crosse lourde
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Crosse en bois
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Kit de bricoleur
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=115710 AND `item`=140324 AND `ExtendedCost`=0 AND `type`=1); -- Balise de télémancie mobile
UPDATE `npc_vendor` SET `maxcount`=2 WHERE (`entry`=98548 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion basique
UPDATE `npc_vendor` SET `maxcount`=4 WHERE (`entry`=98548 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion grossière
UPDATE `npc_vendor` SET `maxcount`=2 WHERE (`entry`=98548 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Poudre d'explosion basique
UPDATE `npc_vendor` SET `slot`=22 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=103235 AND `ID`=1) OR (`CreatureID`=103179 AND `ID`=1) OR (`CreatureID`=103177 AND `ID`=1) OR (`CreatureID`=103227 AND `ID`=1) OR (`CreatureID`=102634 AND `ID`=1) OR (`CreatureID`=103178 AND `ID`=1) OR (`CreatureID`=104248 AND `ID`=1) OR (`CreatureID`=102205 AND `ID`=1) OR (`CreatureID`=102203 AND `ID`=1) OR (`CreatureID`=104244 AND `ID`=1) OR (`CreatureID`=99225 AND `ID`=1) OR (`CreatureID`=104692 AND `ID`=1) OR (`CreatureID`=104624 AND `ID`=1) OR (`CreatureID`=104660 AND `ID`=1) OR (`CreatureID`=111184 AND `ID`=1) OR (`CreatureID`=104615 AND `ID`=1) OR (`CreatureID`=114289 AND `ID`=1) OR (`CreatureID`=114288 AND `ID`=1) OR (`CreatureID`=99033 AND `ID`=1) OR (`CreatureID`=99307 AND `ID`=1) OR (`CreatureID`=98973 AND `ID`=1) OR (`CreatureID`=97365 AND `ID`=1) OR (`CreatureID`=98919 AND `ID`=1) OR (`CreatureID`=97185 AND `ID`=1) OR (`CreatureID`=97097 AND `ID`=1) OR (`CreatureID`=97182 AND `ID`=1) OR (`CreatureID`=96754 AND `ID`=1) OR (`CreatureID`=102326 AND `ID`=1) OR (`CreatureID`=98291 AND `ID`=1) OR (`CreatureID`=99188 AND `ID`=1) OR (`CreatureID`=96756 AND `ID`=1) OR (`CreatureID`=102894 AND `ID`=1) OR (`CreatureID`=102375 AND `ID`=1) OR (`CreatureID`=114712 AND `ID`=1) OR (`CreatureID`=102104 AND `ID`=1) OR (`CreatureID`=102896 AND `ID`=1) OR (`CreatureID`=97043 AND `ID`=1) OR (`CreatureID`=97200 AND `ID`=1) OR (`CreatureID`=115608 AND `ID`=1) OR (`CreatureID`=115687 AND `ID`=1) OR (`CreatureID`=115557 AND `ID`=1) OR (`CreatureID`=115258 AND `ID`=1) OR (`CreatureID`=115535 AND `ID`=1) OR (`CreatureID`=115248 AND `ID`=1) OR (`CreatureID`=116367 AND `ID`=1) OR (`CreatureID`=115067 AND `ID`=1) OR (`CreatureID`=115079 AND `ID`=1) OR (`CreatureID`=115078 AND `ID`=1) OR (`CreatureID`=114956 AND `ID`=1) OR (`CreatureID`=114949 AND `ID`=1) OR (`CreatureID`=114985 AND `ID`=1) OR (`CreatureID`=115018 AND `ID`=1) OR (`CreatureID`=114948 AND `ID`=1) OR (`CreatureID`=114868 AND `ID`=1) OR (`CreatureID`=114873 AND `ID`=1) OR (`CreatureID`=115736 AND `ID`=1) OR (`CreatureID`=112146 AND `ID`=1) OR (`CreatureID`=113061 AND `ID`=1) OR (`CreatureID`=113062 AND `ID`=1) OR (`CreatureID`=113191 AND `ID`=1) OR (`CreatureID`=113168 AND `ID`=1) OR (`CreatureID`=113172 AND `ID`=1) OR (`CreatureID`=113166 AND `ID`=1) OR (`CreatureID`=113114 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(103235, 1, 19987, 0, 0, 19987, 0, 0, 0, 0, 0), -- Taskmaster Filthwhisker
(103179, 1, 9659, 0, 0, 0, 0, 0, 0, 0, 0), -- Gunksnout Geomancer
(103177, 1, 2023, 0, 0, 0, 0, 0, 0, 0, 0), -- Gunksnout Runt
(103227, 1, 2901, 0, 0, 0, 0, 0, 0, 0, 0), -- Wax Miner
(102634, 1, 19987, 0, 0, 0, 0, 0, 0, 0, 0), -- Scalewhisker Cavalry
(103178, 1, 12854, 0, 0, 12854, 0, 0, 0, 0, 0), -- Gunksnout Scavenger
(104248, 1, 116487, 0, 0, 0, 0, 0, 0, 0, 0), -- Gazarogg the Stonespeaker
(102205, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0), -- Pathfinder Linny
(102203, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0), -- Skyhorn Pathfinder
(104244, 1, 116487, 0, 0, 0, 0, 0, 0, 0, 0), -- Uzgarogg the Seer
(99225, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0), -- Lasan Skyhorn
(104692, 1, 133776, 0, 0, 133776, 0, 0, 0, 0, 0), -- Greystone Flanker
(104624, 1, 56193, 0, 0, 56173, 0, 0, 101484, 0, 0), -- Wounded Highmountain Protector
(104660, 1, 107696, 0, 0, 0, 0, 0, 0, 0, 0), -- Blargrul the Siegebrul
(111184, 1, 113049, 0, 0, 0, 0, 0, 0, 0, 0), -- Greystone Shardcaster
(104615, 1, 133776, 0, 0, 133776, 0, 0, 0, 0, 0), -- Greystone Flanker
(114289, 1, 129723, 0, 0, 115802, 0, 0, 0, 0, 0), -- Skeletal Sorcerer
(114288, 1, 106837, 0, 0, 106837, 0, 0, 0, 0, 0), -- Skeletal Warrior
(99033, 1, 35942, 0, 0, 0, 0, 0, 0, 0, 0), -- Helarjar Mistcaller
(99307, 1, 1925, 0, 0, 130101, 0, 0, 0, 0, 0), -- Skjal
(98973, 1, 106837, 0, 0, 106837, 0, 0, 0, 0, 0), -- Skeletal Warrior
(97365, 1, 35942, 0, 0, 0, 0, 0, 0, 0, 0), -- Seacursed Mistmender
(98919, 1, 77076, 0, 0, 75009, 0, 0, 0, 0, 0), -- Seacursed Swiftblade
(97185, 1, 115802, 0, 0, 0, 0, 0, 0, 0, 0), -- The Grimewalker
(97097, 1, 76287, 0, 0, 107823, 0, 0, 0, 0, 0), -- Helarjar Champion
(97182, 1, 118083, 0, 0, 6341, 0, 0, 0, 0, 0), -- Night Watch Mariner
(96754, 1, 88793, 0, 0, 0, 0, 0, 0, 0, 0), -- Harbaron
(102326, 1, 81357, 0, 0, 0, 0, 0, 0, 0, 0), -- Seacursed Rower
(98291, 1, 81357, 0, 0, 0, 0, 0, 0, 0, 0), -- Seacursed Rower
(99188, 1, 113562, 0, 0, 56173, 0, 0, 0, 0, 0), -- Waterlogged Soul Guard
(96756, 1, 129189, 0, 0, 0, 0, 0, 0, 0, 0), -- Ymiron, the Fallen King
(102894, 1, 130196, 0, 0, 0, 0, 0, 0, 0, 0), -- Runecarver Slave
(102375, 1, 61297, 0, 0, 0, 0, 0, 0, 0, 0), -- Runecarver Slave
(114712, 1, 61297, 0, 0, 0, 0, 0, 0, 0, 0), -- Runecarver Slave
(102104, 1, 127346, 0, 0, 77408, 0, 0, 0, 0, 0), -- Enslaved Shieldmaiden
(102896, 1, 127346, 0, 0, 77408, 0, 0, 0, 0, 0), -- Enslaved Shieldmaiden
(97043, 1, 81357, 0, 0, 0, 0, 0, 0, 0, 0), -- Esclavagiste maudit par les flots
(97200, 1, 132557, 0, 0, 0, 0, 0, 0, 0, 0), -- Seacursed Soulkeeper
(115608, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Silgryn
(115687, 1, 137256, 0, 0, 0, 0, 0, 0, 0, 0), -- Echo of Vanthir
(115557, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(115258, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Echo of Vanthir
(115535, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Assassin rôdeur
(115248, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(116367, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Conspirator
(115067, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Silgryn
(115079, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Victoire
(115078, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Arluelle
(114956, 1, 143500, 0, 0, 0, 0, 0, 0, 0, 0), -- Victoire
(114949, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Arluelle
(114985, 1, 134637, 0, 0, 0, 0, 0, 0, 0, 0), -- Scarleth
(115018, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Silgryn
(114948, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Silgryn
(114868, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Enforcer
(114873, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Palace Warden
(115736, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Première arcaniste Thalyssra
(112146, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(113061, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(113062, 1, 125646, 0, 0, 12851, 0, 0, 0, 0, 0), -- Arluin
(113191, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Archivist
(113168, 1, 132170, 0, 0, 137253, 0, 0, 0, 0, 0), -- Duskwatch Ley-Warden
(113172, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Rune Scribe
(113166, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Arcblade
(113114, 1, 125646, 0, 0, 12851, 0, 0, 0, 0, 0); -- Arluin

UPDATE `creature_equip_template` SET `ItemID2`=55790, `ItemID3`=0 WHERE (`CreatureID`=106111 AND `ID`=1); -- Frostcrag Stonecaller
UPDATE `creature_equip_template` SET `ItemID2`=115334, `ItemID3`=0 WHERE (`CreatureID`=102123 AND `ID`=1); -- Ronir Wrangler
UPDATE `creature_equip_template` SET `ItemID2`=115334, `ItemID3`=0 WHERE (`CreatureID`=101645 AND `ID`=1); -- Greystone Trencher
UPDATE `creature_equip_template` SET `ItemID2`=119725, `ItemID3`=0 WHERE (`CreatureID`=97506 AND `ID`=1); -- Chaman crin-de-rive
UPDATE `creature_equip_template` SET `ItemID2`=36449, `ItemID3`=101484 WHERE (`CreatureID`=99711 AND `ID`=1); -- Highmountain Protector
UPDATE `creature_equip_template` SET `ItemID1`=129112 WHERE (`CreatureID`=110437 AND `ID`=1); -- Haklang Ulfsson

DELETE FROM `gossip_menu` WHERE (`MenuID`=18724 AND `TextID`=27208) OR (`MenuID`=20344 AND `TextID`=30432) OR (`MenuID`=18747 AND `TextID`=27251) OR (`MenuID`=20644 AND `TextID`=27259) OR (`MenuID`=6944 AND `TextID`=7778) OR (`MenuID`=20576 AND `TextID`=30843) OR (`MenuID`=20576 AND `TextID`=30837) OR (`MenuID`=20549 AND `TextID`=30775) OR (`MenuID`=19554 AND `TextID`=28901) OR (`MenuID`=19929 AND `TextID`=29607) OR (`MenuID`=20560 AND `TextID`=30817) OR (`MenuID`=20591 AND `TextID`=30866) OR (`MenuID`=20643 AND `TextID`=30960) OR (`MenuID`=20638 AND `TextID`=30942) OR (`MenuID`=20635 AND `TextID`=30937) OR (`MenuID`=20639 AND `TextID`=30945) OR (`MenuID`=20618 AND `TextID`=30920) OR (`MenuID`=20617 AND `TextID`=30919) OR (`MenuID`=20620 AND `TextID`=30921) OR (`MenuID`=20619 AND `TextID`=30922) OR (`MenuID`=20228 AND `TextID`=30210) OR (`MenuID`=20212 AND `TextID`=30122) OR (`MenuID`=20196 AND `TextID`=30083) OR (`MenuID`=20197 AND `TextID`=30084) OR (`MenuID`=20198 AND `TextID`=30085) OR (`MenuID`=18748 AND `TextID`=27380) OR (`MenuID`=19960 AND `TextID`=28198) OR (`MenuID`=19301 AND `TextID`=28397);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(18724, 27208), -- 96679 (Aerylia)
(20344, 30432), -- 110437 (Haklang Ulfsson)
(18747, 27251), -- 97389 (Eye of Odyn)
(20644, 27259), -- Première arcaniste Thalyssra
(6944, 7778), -- 114718 (Ancient Cloudwing)
(20576, 30843), -- 115557 (First Arcanist Thalyssra)
(20576, 30837), -- 115557 (First Arcanist Thalyssra)
(20549, 30775), -- 115247 (Ly'leth Lunastre)
(19554, 28901), -- 105835 (Lunastre Attendant)
(19929, 29607), -- 109409 (Nightborne Wretch)
(20560, 30817), -- 115376 (Maribeth)
(20591, 30866), -- Télémancien en chef Oculeth
(20643, 30960), -- 116085 (Arluelle)
(20638, 30942), -- 114985 (Scarleth)
(20635, 30937), -- 114983 (Thorvos)
(20639, 30945), -- 114978 (Master Devlyn)
(20618, 30920), -- 115991 (Emille)
(20617, 30919), -- 115992 (Brigitte)
(20620, 30921), -- 116001 (Eneas)
(20619, 30922), -- 116001 (Eneas)
(20228, 30210), -- 108870 (Sylverin)
(20212, 30122), -- 110698 (Arluelle)
(20196, 30083), -- 112146 (First Arcanist Thalyssra)
(20197, 30084), -- 112145 (Arcanist Valtrois)
(20198, 30085), -- 112147 (Chief Telemancer Oculeth)
(18748, 27380), -- 97140 (First Arcanist Thalyssra)
(19960, 28198), -- 98548 (Chief Telemancer Oculeth)
(19301, 28397); -- 103155 (Arcanist Valtrois)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=20644 AND `OptionIndex`=4) OR (`MenuId`=20644 AND `OptionIndex`=3) OR (`MenuId`=20644 AND `OptionIndex`=2) OR (`MenuId`=20644 AND `OptionIndex`=1) OR (`MenuId`=20576 AND `OptionIndex`=0) OR (`MenuId`=20591 AND `OptionIndex`=3) OR (`MenuId`=20591 AND `OptionIndex`=2) OR (`MenuId`=20643 AND `OptionIndex`=0) OR (`MenuId`=20638 AND `OptionIndex`=0) OR (`MenuId`=20635 AND `OptionIndex`=0) OR (`MenuId`=20620 AND `OptionIndex`=1) OR (`MenuId`=20618 AND `OptionIndex`=0) OR (`MenuId`=20617 AND `OptionIndex`=0) OR (`MenuId`=20620 AND `OptionIndex`=0) OR (`MenuId`=20212 AND `OptionIndex`=0) OR (`MenuId`=20196 AND `OptionIndex`=0) OR (`MenuId`=20197 AND `OptionIndex`=0) OR (`MenuId`=20198 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(20644, 4, 5, 'I wish to bind my hearthstone here.', 122363),
(20644, 3, 1, 'I wish to trade.', 122362), -- OptionBroadcastTextID: 122362 - 125204
(20644, 2, 0, '<Gain Ward of the First Arcanist for 50 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121814),
(20644, 1, 0, 'I''ve come to help the withered with their combat training.', 120520),
(20576, 0, 0, 'I am ready, Thalyssra.', 124117),
(20591, 3, 1, 'Can you repair my equipment?', 118613),
(20591, 2, 0, '<Gain Warpwalking for 10 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121607),
(20643, 0, 0, 'Right this way, Arluelle.', 124832),
(20638, 0, 0, 'It looks like you have things handled, Scarleth. You and your girls should leave while you have a chance.', 124773),
(20635, 0, 0, 'I will protect you both. Let''s go!', 124765),
(20620, 1, 0, 'Eneas, you need to go now.', 124740),
(20618, 0, 0, 'Your father will help you get to safety. Go downstairs now!', 124730),
(20617, 0, 0, 'Your father is waiting for you downstairs- hurry!', 124728),
(20620, 0, 0, 'You need to get out of here. It isn''t safe!', 124738),
(20212, 0, 0, 'Arluin is not coming, I''m afraid. He died to ensure we could bring this to you. <Offer Arcan''dor Fruit.>', 120809),
(20196, 0, 0, '<Offer Fruit of the Arcan''dor.>', 120732),
(20197, 0, 0, '<Offer Fruit of the Arcan''dor.>', 120732),
(20198, 0, 0, '<Offer Fruit of the Arcan''dor.>', 120732);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=20620 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(20620, 0, 20619, 0);

DELETE FROM `creature_template` WHERE `entry` IN (131971 /*Bloodtotem Trapper*/, 131953 /*Bloodtotem Survivor*/);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `VehicleId`, `HoverHeight`, `VerifiedBuild`) VALUES
(131971, 0, 0, 65770, 65769, 0, 0, 'Bloodtotem Trapper', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1.3, 1, 0, 0, 0, 110, 110, 2785, 1, 1, 1.142857, 2000, 2000, 1, 33536, 2048, 0, 0, 0, 1, 25996), -- Bloodtotem Trapper
(131953, 0, 0, 66647, 66648, 66649, 66650, 'Bloodtotem Survivor', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1.3, 1, 0, 0, 0, 110, 110, 2785, 1, 1, 1.142857, 2000, 2000, 1, 33536, 2048, 0, 0, 0, 1, 25996); -- Bloodtotem Survivor

UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=106111; -- Frostcrag Stonecaller
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=92242; -- Barm Stonebreaker
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103886; -- Twilight Orelifter
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=4684 WHERE `entry`=104690; -- Beamer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103235; -- Taskmaster Filthwhisker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103234; -- Taskmaster Skraggletail
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=101630; -- Trancheterre pierre-d’ambre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103179; -- Gunksnout Geomancer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103177; -- Gunksnout Runt
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103227; -- Wax Miner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102634; -- Scalewhisker Cavalry
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=4583 WHERE `entry`=102633; -- Waxeye Glazer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103178; -- Gunksnout Scavenger
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=104248; -- Gazarogg the Stonespeaker
UPDATE `creature_template` SET `minlevel`=98, `speed_walk`=1 WHERE `entry`=104243; -- Bound Elemental
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33570816, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=103197; -- Kill Credit: Kobold Candle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=103196; -- Kobold Candle
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102629; -- Brick
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102123; -- Ronir Wrangler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101823; -- Mushroom Merchant
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=104244; -- Uzgarogg the Seer
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=101813; -- Greystone Chompkeeper
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=101785; -- Steelgaze Basilisk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101644; -- Greystone Shardmaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101645; -- Greystone Trencher
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=98310; -- Burrow Spiderling
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=103090; -- Greystone Fishbrul
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=67141696 WHERE `entry`=101649; -- Frostshard
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102623; -- Stonefist Brawler
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=102632; -- Glowing Deepshard
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=96548; -- Rabbit
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=96590; -- Gurbog da Basher
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61167; -- Lapin des montagnes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99216; -- Arxas
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=96691; -- Mightstone Slinger
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=95718; -- Aigle de guerre
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=95717; -- Intercepteur corne-céleste
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=99217; -- Naxa
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=97013; -- Xist
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=96690; -- Mightstone Flanker
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108185; -- Coldscale Gazecrawler
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=99214; -- Siege Worm
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=99027; -- Mora Cliffhoof
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=99026; -- Gala Woodbridge
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=99028; -- Ferra Leafheart
UPDATE `creature_template` SET `faction`=2785, `npcflag`=643, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=100437; -- Lanna Skyspark
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=99029; -- A'te Amberfur
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=97572; -- Cavern Eel
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110496; -- Coldwater Goldscale
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110499; -- Aileron-long d’eau douce
UPDATE `creature_template` SET `minlevel`=110, `faction`=35, `speed_walk`=1.6, `speed_run`=0.5714286, `unit_flags2`=2099200 WHERE `entry`=104757; -- Winter Elderhorn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=99699; -- Thunder Drum Circle
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=99894; -- Losro Greyfeather
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=2785, `npcflag`=66179, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=97852; -- Ernu Mesawind
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=107660; -- Bolas Skyfeather
UPDATE `creature_template` SET `faction`=2785, `npcflag`=83, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=98017; -- Guron Twaintail
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=108082; -- Bolas Launcher
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=107988; -- Bolas Launcher
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=2785, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=97858; -- Galica Bravepaw
UPDATE `creature_template` SET `faction`=2785, `npcflag`=4226, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=99905; -- Shale Greyfeather
UPDATE `creature_template` SET `faction`=2785, `npcflag`=211, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=99903; -- Sprig Hashhoof
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=99913; -- Whitewater Grouper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99672; -- Sakrul the Brewbrul
UPDATE `creature_template` SET `npcflag`=3, `speed_run`=1.142857 WHERE `entry`=99624; -- Navarrogg
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=99225; -- Lasan Skyhorn
UPDATE `creature_template` SET `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=95688; -- Windtamer Nalt
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=104692; -- Greystone Flanker
UPDATE `creature_template` SET `faction`=2785, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=107726; -- Ethel Waterwise
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99671; -- Obrul the Thug
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99670; -- Uungbrul
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99669; -- Bogrogg the Stonescreamer
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=103485; -- Lessah Moonwater
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2785, `npcflag`=131, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=51200 WHERE `entry`=106902; -- Ransa Greyfeather
UPDATE `creature_template` SET `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=103733; -- Luron
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2785, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags3`=128 WHERE `entry`=104624; -- Wounded Highmountain Protector
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=104660; -- Blargrul the Siegebrul
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111184; -- Greystone Shardcaster
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=104615; -- Greystone Flanker
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=100635; -- Skyseer Ghrent
UPDATE `creature_template` SET `gossip_menu_id`=20344 WHERE `entry`=110437; -- Haklang Ulfsson
UPDATE `creature_template` SET `maxlevel`=102 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96830; -- Linda Ann Kastinglow
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=109376; -- Rendezvous Point
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=6491; -- Spirit Healer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115625; -- Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=102306; -- Swirling Pool
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784 WHERE `entry`=100354; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4494 WHERE `entry`=100353; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=100188; -- Piercing Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784 WHERE `entry`=99801; -- Destructor Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4471 WHERE `entry`=99803; -- Destructor Tentacle
UPDATE `creature_template` SET `minlevel`=103, `maxlevel`=103, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4545 WHERE `entry`=97099; -- Swirling Pool
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784 WHERE `entry`=98363; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4470 WHERE `entry`=99800; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872 WHERE `entry`=101502; -- Helya's Tentacle
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784 WHERE `entry`=100360; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4495 WHERE `entry`=100359; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=1142949888 WHERE `entry`=96759; -- Helya
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33817344, `unit_flags2`=2048 WHERE `entry`=101504; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33817344, `unit_flags2`=1073743872 WHERE `entry`=101814; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.8571429, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114289; -- Skeletal Sorcerer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.8571429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=114288; -- Skeletal Warrior
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=1.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=3.9 WHERE `entry`=99033; -- Helarjar Mistcaller
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_walk`=1.2, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=99307; -- Skjal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=98761; -- Soul Fragment
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=98989; -- Cosmic Scythe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4515 WHERE `entry`=100839; -- Cosmic Scythe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=101187584, `HoverHeight`=4 WHERE `entry`=104906; -- Captured Val'kyr
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570688256, `unit_flags2`=67110913, `unit_flags3`=8193 WHERE `entry`=102830; -- Deceased Sorcerer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.8571429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=98973; -- Skeletal Warrior
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=33556480, `HoverHeight`=3.6 WHERE `entry`=97365; -- Seacursed Mistmender
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872, `unit_flags3`=1, `VehicleId`=4608 WHERE `entry`=103115; -- Helheim
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=98919; -- Seacursed Swiftblade
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=97185; -- The Grimewalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=1.6, `speed_run`=1.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=97097; -- Helarjar Champion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=97119; -- Shroud Hound
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=102742; -- Fallen Shieldmaiden
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=1.2, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=97182; -- Night Watch Mariner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4573 WHERE `entry`=102325; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=39847936 WHERE `entry`=96754; -- Harbaron
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=102769; -- Decrepit Runecarver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=102326; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=98291; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=99188; -- Waterlogged Soul Guard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4574 WHERE `entry`=102327; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=6291456 WHERE `entry`=96756; -- Ymiron, the Fallen King
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4521 WHERE `entry`=101013; -- Captured Runecarver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33088, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=102894; -- Runecarver Slave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=102375; -- Runecarver Slave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=114712; -- Runecarver Slave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=67110912 WHERE `entry`=102104; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=102896; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4559 WHERE `entry`=102108; -- Captured Shieldmaiden
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=97208; -- Spear
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `VehicleId`=4383 WHERE `entry`=97043; -- Esclavagiste maudit par les flots
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=97163; -- Cursed Falke
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=97200; -- Seacursed Soulkeeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=115720; -- Dusk Lily Sigil
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115604; -- Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=115608; -- Silgryn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115571; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115687; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587968, `unit_flags2`=67143680 WHERE `entry`=115590; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115570; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=115569; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200, `unit_flags2`=34816 WHERE `entry`=115584; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200, `unit_flags2`=34816 WHERE `entry`=115581; -- Echo of Vanthir
UPDATE `creature_template` SET `gossip_menu_id`=20576, `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115557; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115260; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=67143680 WHERE `entry`=116559; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=116558; -- Echo of Vanthir
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=107333; -- Surveillant Durant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115259; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115258; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115531; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=115530; -- Echo of Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.5, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115535; -- Assassin rôdeur
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115248; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115247; -- Ly'leth Lunastre
UPDATE `creature_template` SET `faction`=35 WHERE `entry`=113515; -- Maribeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115243; -- Image of Ly'leth Lunastre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115377; -- Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115072; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115378; -- Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115075; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116368; -- Felsoul Imp
UPDATE `creature_template` SET `gossip_menu_id`=20560, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115376; -- Maribeth
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116411; -- Soul Engine Gateway
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114998; -- Aargoss
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115071; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111414; -- Saltscale Grouper
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `VehicleId`=5026 WHERE `entry`=115080; -- Deline's Gondola
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2886, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116367; -- Felborne Conspirator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115000; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115003; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2885, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115067; -- Silgryn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115002; -- Maribeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115081; -- Deline
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2885, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115079; -- Victoire
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2885, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115078; -- Arluelle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115073; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115074; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115014; -- Felsoul Imp
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `VehicleId`=5086 WHERE `entry`=116659; -- Felsoul Ferry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=115066; -- Shal'dorei Civilian
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116317; -- Slowfall Rune
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=114956; -- Victoire
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114949; -- Arluelle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=116506; -- Image of Ly'leth Lunastre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=116085; -- Arluelle
UPDATE `creature_template` SET `gossip_menu_id`=19929 WHERE `entry`=109409; -- Nightborne Wretch
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33344, `unit_flags2`=67110912, `VehicleId`=5016 WHERE `entry`=114970; -- Deline's Gondola
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.7 WHERE `entry`=116044; -- Deline
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114989; -- Jynn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114988; -- Ruthela
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114987; -- Vyvari
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114986; -- Celandra
UPDATE `creature_template` SET `gossip_menu_id`=20638, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114985; -- Scarleth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=116054; -- Master Devlyn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115018; -- Silgryn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=116057; -- Brigitte
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=116056; -- Emille
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=116055; -- Eneas
UPDATE `creature_template` SET `gossip_menu_id`=20639, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=114978; -- Master Devlyn
UPDATE `creature_template` SET `gossip_menu_id`=20620, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=116001; -- Eneas
UPDATE `creature_template` SET `gossip_menu_id`=20635, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114983; -- Thorvos
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114984; -- Valanth
UPDATE `creature_template` SET `gossip_menu_id`=20617, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=115992; -- Brigitte
UPDATE `creature_template` SET `gossip_menu_id`=20618, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=115991; -- Emille
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=108386; -- Ambrena
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=108385; -- Lunette
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=108810; -- Chloe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680 WHERE `entry`=116584; -- The Waning Crescent
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=108387; -- Donatien
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=115772; -- Kal
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=537166080, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=113514; -- Joshen Lafave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=114948; -- Silgryn
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=114969; -- Kill Credit: Silgryn Found
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=537166080, `unit_flags2`=1, `unit_flags3`=8192 WHERE `entry`=113516; -- Dasdonia
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=34817, `unit_flags3`=8192 WHERE `entry`=108388; -- Clotaire
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=108811; -- Audric
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=114868; -- Felborne Enforcer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114875; -- Felwing Purifier
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=115810; -- FX Stalker [DNT]
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114873; -- Palace Warden
UPDATE `creature_template` SET `gossip_menu_id`=20591, `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=4227, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115710; -- Télémancien en chef Oculeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115371; -- Arcaniste Valtrois
UPDATE `creature_template` SET `gossip_menu_id`=20644, `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=65667, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115736; -- Première arcaniste Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=110698; -- Arluelle
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=113707; -- Duskwatch Astralite
UPDATE `creature_template` SET `gossip_menu_id`=20197, `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112145; -- Arcanist Valtrois
UPDATE `creature_template` SET `gossip_menu_id`=20196, `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112146; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `gossip_menu_id`=20198, `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112147; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=114291; -- Arcan'dor Vine
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=113585; -- Arcway Reclaimer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=94, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=113426; -- Place E.M.P.
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113332; -- Mana Hunter
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2871, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113061; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2871, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=113062; -- Arluin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048, `HoverHeight`=2 WHERE `entry`=113178; -- Archivist's Tome
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113191; -- Duskwatch Archivist
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113168; -- Duskwatch Ley-Warden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113172; -- Duskwatch Rune Scribe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113202; -- Runebound Wyrm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113166; -- Duskwatch Arcblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113114; -- Arluin
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=97140; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `gossip_menu_id`=19301 WHERE `entry`=103155; -- Arcanist Valtrois
UPDATE `creature_template` SET `gossip_menu_id`=19960 WHERE `entry`=98548; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=111903; -- Lunastre Attendant
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=101848; -- Absolon
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=112972; -- Ecrabouilleur des fourrés géant
UPDATE `creature_template` SET `unit_flags`=570720256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=110042; -- Heartwood Stag
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=114888; -- Shal'dorei Civilian

SET @GROUP_ID := 0;
SET @ID := 0;

REPLACE INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(32642, @GROUP_ID+0, @ID+0, 'Be dat way den!', 12, 0, 100, 1, 0, 0, 33029, 'Mojodishu to Player'),
(32642, @GROUP_ID+1, @ID+0, 'Dis bad mojo what you doin''. Don''t say Mojodishu didn''t warn ya!', 12, 0, 100, 1, 0, 0, 33028, 'Mojodishu to Player'),
(96590, @GROUP_ID+0, @ID+0, 'Gonna BASH you!', 14, 0, 100, 0, 0, 0, 111786, 'Gurbog da Basher'),
(96754, @GROUP_ID+0, @ID+0, 'The spirits grow hungry from the scent of blood.', 14, 0, 100, 0, 0, 54387, 102201, 'Harbaron to Player'),
(96754, @GROUP_ID+1, @ID+0, 'New passengers... New souls. I will guide you to the depths of Helheim for a small price: your flesh and blood.', 14, 0, 100, 0, 0, 54373, 102206, 'Harbaron to Player'),
(96754, @GROUP_ID+2, @ID+0, 'If I cannot bleed the payment from you, the spirits will!', 14, 0, 100, 0, 0, 54386, 102200, 'Harbaron'),
(96754, @GROUP_ID+3, @ID+0, 'The flesh burdens the soul. A nuisance that must be flayed from your bones!', 14, 0, 100, 0, 0, 54384, 102198, 'Harbaron to Player'),
(96754, @GROUP_ID+4, @ID+0, '|TInterface\\Icons\\Ability_Warlock_ImprovedSoulLeech:20|t %s begins to |cFFFF0000|Hspell:194325|h[Fragment]|h|r $n.', 41, 0, 100, 0, 0, 54384, 105669, 'Harbaron to Player'),
(96754, @GROUP_ID+5, @ID+0, 'Life... death... I am but one ripple in the eternal ebb and flow...', 14, 0, 100, 0, 0, 54376, 102660, 'Harbaron to Player'),
(96756, @GROUP_ID+0, @ID+0, 'Mortals... Your wretched kind murdered MY people... destroyed MY kingdom! Long have I waited for a chance to repay what was done to me!', 14, 0, 100, 0, 0, 54370, 102189, 'Ymiron, the Fallen King to Player'),
(96756, @GROUP_ID+1, @ID+0, 'Know the bitter chill of death as I have!', 14, 0, 100, 0, 0, 54362, 102177, 'Ymiron, the Fallen King'),
(96756, @GROUP_ID+2, @ID+0, 'The shadows of the underworld bend to me!', 14, 0, 100, 0, 0, 54357, 102171, 'Ymiron, the Fallen King'),
(96756, @GROUP_ID+3, @ID+0, 'You have not won... The Naglfar comes... for you...', 14, 0, 100, 0, 0, 54363, 102180, 'Ymiron, the Fallen King to Player'),
(96759, @GROUP_ID+0, @ID+0, 'You ALL will regret trespassing in my realm.', 14, 0, 100, 0, 0, 54395, 102212, 'Helya to Player'),
(96759, @GROUP_ID+1, @ID+0, 'You have come far enough. Time to die.', 14, 0, 100, 0, 0, 54180, 102213, 'Helya to Player'),
(96759, @GROUP_ID+2, @ID+0, 'You will pay for that.', 14, 0, 100, 0, 0, 54244, 102221, 'Helya to Helya'),
(96759, @GROUP_ID+3, @ID+0, 'I am losing my patience.', 14, 0, 100, 0, 0, 54245, 102222, 'Helya to Helya'),
(96759, @GROUP_ID+4, @ID+0, 'Embrace your fate, fools!', 14, 0, 100, 0, 0, 54391, 102228, 'Helya to Helya'),
(96759, @GROUP_ID+5, @ID+0, 'Your fate rains down!', 14, 0, 100, 0, 0, 54392, 102217, 'Helya'),
(96759, @GROUP_ID+6, @ID+0, 'No! This is not possible!', 14, 0, 100, 0, 0, 54389, 102223, 'Helya to Helya'),
(96759, @GROUP_ID+7, @ID+0, 'What manner of creatures ARE you??', 14, 0, 100, 0, 0, 54389, 102227, 'Helya to Helya'),
(96759, @GROUP_ID+8, @ID+0, '|TInterface\\Icons\\Spell_Shadow_Possession:20|t %s begins to cast |cFFFF0000|Hspell:227233|h[Corrupted Bellow]|h|r. Look out!', 41, 0, 100, 0, 0, 54400, 123006, 'Helya'),
(96759, @GROUP_ID+9, @ID+0, 'I will drown you all like rats.', 14, 0, 100, 0, 0, 54400, 102218, 'Helya'),
(96759, @GROUP_ID+10, @ID+0, 'Do you think you have won? You have merely survived the storm... The seas are unstoppable.', 14, 0, 100, 0, 0, 54396, 102661, 'Helya'),
(97043, @GROUP_ID+0, @ID+0, 'Silence. Your soul belongs to Helya.', 14, 0, 100, 25, 0, 0, 100494, 'Seacursed Slaver to Player'),
(97043, @GROUP_ID+1, @ID+0, 'Want to live? Kill these fools.', 14, 0, 100, 0, 0, 0, 104366, 'Seacursed Slaver'),
(97043, @GROUP_ID+2, @ID+0, 'Fight them. Earn your freedom!', 14, 0, 100, 0, 0, 0, 104438, 'Seacursed Slaver'),
(97097, @GROUP_ID+0, @ID+0, 'Harbaron won''t have your kind around here, mortal.', 14, 0, 100, 0, 0, 0, 105467, 'Helarjar Champion to Player'),
(97140, @GROUP_ID+0, @ID+0, 'I thought you were only interested in lining your pockets.', 12, 0, 100, 1, 0, 67302, 118640, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+1, @ID+0, 'Ah... the fog has lifted, just a bit...', 12, 0, 100, 1, 0, 67302, 99791, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+2, @ID+0, 'But the most important, by far. If we fail, Suramar is doomed.', 12, 0, 100, 396, 0, 67336, 118649, 'First Arcanist Thalyssra to Player'),
(97200, @GROUP_ID+0, @ID+0, 'Vrykul dogs, get over here and fight or I''ll kill you myself!', 14, 0, 100, 0, 0, 0, 104657, 'Seacursed Soulkeeper'),
(97200, @GROUP_ID+1, @ID+0, 'I will flay you!', 14, 0, 100, 0, 0, 0, 105657, 'Seacursed Soulkeeper to Player'),
(97200, @GROUP_ID+2, @ID+0, 'I will sharpen my blade with your bones!', 14, 0, 100, 0, 0, 0, 105658, 'Seacursed Soulkeeper to Player'),
(97729, @GROUP_ID+0, @ID+0, 'I will rest now.', 12, 0, 100, 0, 0, 66047, 102391, 'Disturbed Apparition to Player'),
(97729, @GROUP_ID+1, @ID+0, 'Our people... shu dalees-na.', 12, 0, 100, 0, 0, 66051, 102393, 'Disturbed Apparition to Player'),
(97729, @GROUP_ID+2, @ID+0, 'Thandae-alah...', 12, 0, 100, 0, 0, 66044, 102385, 'Disturbed Apparition to Player'),
(98548, @GROUP_ID+0, @ID+0, 'I will teleport you in past the main defenses. When you are ready to leave, activate this beacon so I can locate you and pull you back.', 12, 0, 100, 1, 0, 67333, 118646, 'Chief Telemancer Oculeth to Player'),
(98548, @GROUP_ID+1, @ID+0, 'Now this is important - once that manastorm gets going, there will be too much interference for me to teleport anyone. You must get out before the storm!', 12, 0, 100, 5, 0, 67334, 118647, 'Chief Telemancer Oculeth to Player'),
(98548, @GROUP_ID+2, @ID+0, 'Alright everybody, gather in close. Do not be shy now. Group hug.', 12, 0, 100, 0, 0, 67337, 118644, 'Chief Telemancer Oculeth to Player'),
(99188, @GROUP_ID+0, @ID+0, 'What are you doing out of your cage, $c?', 14, 0, 100, 1, 0, 0, 100454, 'Waterlogged Soul Guard to Player'),
(99307, @GROUP_ID+0, @ID+0, 'No quarter to these scallywags! Helya doesn''t abide intruders.', 14, 0, 100, 0, 0, 57460, 103137, 'Skjal to Player'),
(99307, @GROUP_ID+1, @ID+0, 'No prey, no pay. Now secure the Naglfar!', 14, 0, 100, 0, 0, 57455, 105434, 'Skjal to Player'),
(99307, @GROUP_ID+2, @ID+0, 'All hands on deck!', 14, 0, 100, 0, 0, 57456, 105432, 'Skjal'),
(99307, @GROUP_ID+3, @ID+0, 'Belay these bilge rats!', 14, 0, 100, 0, 0, 57462, 105431, 'Skjal'),
(99307, @GROUP_ID+4, @ID+0, 'This be... my final plunder...', 14, 0, 100, 0, 0, 57458, 105754, 'Skjal to Player'),
(99801, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\inv_misc_monsterhorn_03.blp:20|t A %s emerges!', 41, 0, 100, 0, 0, 0, 104026, 'Destructor Tentacle to Destructor Tentacle'),
(101013, @GROUP_ID+0, @ID+0, 'Runes curse you. I will send you to the bottom of the sea where you belong!', 14, 0, 100, 0, 0, 0, 100513, 'Captured Runecarver to Seacursed Slaver'),
(102108, @GROUP_ID+0, @ID+0, 'You may take my soul, cursed, but you will never take my will.', 14, 0, 100, 0, 0, 0, 100493, 'Captured Shieldmaiden to Seacursed Slaver'),
(103155, @GROUP_ID+0, @ID+0, 'I shall not squander this gift.', 12, 0, 100, 0, 0, 67407, 105787, 'Arcanist Valtrois to Player'),
(104615, @GROUP_ID+0, @ID+0, 'Lemme hear your bones crunch!', 12, 0, 100, 0, 0, 54860, 96412, 'Greystone Flanker to Player'),
(104906, @GROUP_ID+0, @ID+0, 'Harbaron begins to drain the soul of the %s.', 16, 0, 100, 0, 0, 0, 107439, 'Captured Val''kyr'),
(104906, @GROUP_ID+1, @ID+0, 'The %s returns to the Halls of Valor...', 16, 0, 100, 0, 0, 54376, 107436, 'Captured Val''kyr to Captured Val''kyr'),
(105759, @GROUP_ID+0, @ID+0, 'Who goes there?!', 12, 0, 100, 0, 0, 65802, 105557, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105557 - 118520 - 124631
(105759, @GROUP_ID+1, @ID+0, 'An illusion! What are you hiding?', 12, 0, 100, 0, 0, 66003, 105559, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105559 - 118518 - 124629
(106616, @GROUP_ID+0, @ID+0, 'Hearts are full of pity...', 12, 0, 100, 18, 0, 65979, 112859, 'Nightborne Child'),
(106616, @GROUP_ID+1, @ID+0, 'Crashing! Clashing!', 12, 0, 100, 18, 0, 65978, 112860, 'Nightborne Child'),
(106617, @GROUP_ID+0, @ID+0, 'Outside lies doom.', 12, 0, 100, 0, 0, 65777, 112861, 'Nightborne Child'),
(106617, @GROUP_ID+1, @ID+0, 'Ring around the city...', 12, 0, 100, 0, 0, 65778, 112858, 'Nightborne Child'),
(107126, @GROUP_ID+0, @ID+0, 'Behold. The gift of the ancient magi.', 12, 0, 100, 0, 0, 67330, 118723, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+1, @ID+0, 'The arcan''dor will not merely sustain you. By the fruit of its bough, you will be made whole again.', 12, 0, 100, 0, 0, 67332, 118725, 'Valewalker Farodin to Player'),
(108930, @GROUP_ID+0, @ID+0, 'Legion, come to our aid!', 12, 0, 100, 0, 0, 65978, 114783, 'Nightborne Envoy'),
(109048, @GROUP_ID+0, @ID+0, 'To me, servant!', 12, 0, 100, 0, 0, 0, 114785, 'Arcane Engineer to Player'),
(109388, @GROUP_ID+0, @ID+0, 'As you wish. I will meet the Lieutenant where we met last. Send word for her to expect me.', 12, 0, 100, 2, 0, 0, 115280, 'Nightborne Spy to Player'),
(109388, @GROUP_ID+1, @ID+0, 'Keep an eye out for rebels. You can''t be too careful.', 12, 0, 100, 22, 0, 0, 115284, 'Nightborne Spy to Player'),
(109388, @GROUP_ID+2, @ID+0, 'If you see someone stealing arcwine, report them at once!', 12, 0, 100, 0, 0, 0, 115285, 'Nightborne Spy to Player'),
(109407, @GROUP_ID+0, @ID+0, 'A list of traitors? You will have to get this to Lieutenant Piet at once.', 12, 0, 100, 1, 0, 0, 115279, 'Nightborne Sergeant to Player'),
(109954, @GROUP_ID+0, @ID+0, 'My illusions will be your end!', 12, 0, 100, 0, 0, 0, 116340, 'Magister Phaedris to Player'),
(109954, @GROUP_ID+1, @ID+0, 'The illusion... is broken.', 12, 0, 100, 0, 0, 0, 116341, 'Magister Phaedris to Player'),
(110698, @GROUP_ID+0, @ID+0, 'Who is there?', 12, 0, 100, 0, 0, 67306, 118774, 'Arluelle to Player'),
(110698, @GROUP_ID+1, @ID+0, '<Cough.> Arluin, is that you? It is so dark...', 12, 0, 100, 0, 0, 67307, 118775, 'Arluelle to Player'),
(110698, @GROUP_ID+2, @ID+0, 'I understand... He never could stay out of trouble...', 12, 0, 100, 0, 0, 67308, 118776, 'Arluelle to Player'),
(110698, @GROUP_ID+3, @ID+0, 'Thank you... I will remember this.', 12, 0, 100, 0, 0, 67309, 118777, 'Arluelle to Player'),
(111523, @GROUP_ID+0, @ID+0, 'Something''s not quite right...', 12, 0, 100, 1, 0, 65803, 118519, 'Duskwatch Warpcaster to Player'), -- BroadcastTextID: 105558 - 118519 - 124630
(111620, @GROUP_ID+0, @ID+0, 'Die, outlander!', 12, 0, 100, 0, 0, 65820, 116708, 'Duskwatch Executor to Player'), -- BroadcastTextID: 6226 - 100934 - 116708
(111901, @GROUP_ID+0, @ID+0, 'Now, as before, we do what we must to carry on.', 12, 0, 100, 11, 0, 0, 125324, 'Suramar Refugee to Player'),
(111902, @GROUP_ID+0, @ID+0, 'This fruit actually cured Thalyssra? Amazing.', 12, 0, 100, 7, 0, 0, 125323, 'Suramar Refugee to Player'),
(112145, @GROUP_ID+0, @ID+0, 'Perhaps there is a new path for us after all...', 12, 0, 100, 0, 0, 67374, 118753, 'Arcanist Valtrois to Player'),
(112145, @GROUP_ID+1, @ID+0, 'You have my thanks, outlander.', 12, 0, 100, 0, 0, 67375, 118756, 'Arcanist Valtrois to Player'),
(112146, @GROUP_ID+0, @ID+0, 'This tree came at a high cost... You are sure it can sustain us?', 12, 0, 100, 0, 0, 67331, 118739, 'First Arcanist Thalyssra to Player'),
(112146, @GROUP_ID+1, @ID+0, 'We are on the brink of a new age for the Nightborne.', 12, 0, 100, 0, 0, 67376, 118771, 'First Arcanist Thalyssra to Player'),
(112146, @GROUP_ID+2, @ID+0, 'Without you, none of this would have been possible.', 12, 0, 100, 0, 0, 67377, 118772, 'First Arcanist Thalyssra to Player'),
(112146, @GROUP_ID+3, @ID+0, 'For now, we shall gather our strength. When the time comes, I trust we can call upon you to help us liberate Suramar.', 12, 0, 100, 0, 0, 67378, 118773, 'First Arcanist Thalyssra to Player'),
(112147, @GROUP_ID+0, @ID+0, 'Hmm... a little tart, with a hint of- oh, my... there it is.', 12, 0, 100, 0, 0, 67372, 118645, 'Chief Telemancer Oculeth to Player'),
(112147, @GROUP_ID+1, @ID+0, 'Astounding.', 12, 0, 100, 0, 0, 67373, 118742, 'Chief Telemancer Oculeth to Player'),
(113061, @GROUP_ID+0, @ID+0, 'Yes. We are close.', 12, 0, 100, 0, 0, 67339, 118660, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+1, @ID+0, 'There! Place the manastorm generator near the conduit.', 12, 0, 100, 0, 0, 67342, 118665, 'First Arcanist Thalyssra to First Mate Snellig'),
(113061, @GROUP_ID+2, @ID+0, 'Something is wrong... The temporal warp sequencer-', 12, 0, 100, 0, 0, 67344, 118669, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+3, @ID+0, 'The fuse is broken. We must trigger the manastorm manually.', 12, 0, 100, 0, 0, 67346, 118670, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+4, @ID+0, 'We have no choice. This must be done.', 12, 0, 100, 0, 0, 67348, 118681, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+5, @ID+0, 'Rath, anu''telar!', 12, 0, 100, 463, 0, 67349, 118682, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+6, @ID+0, 'We just need to hold out until the storm is over!', 12, 0, 100, 0, 0, 67350, 118683, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+7, @ID+0, 'Erath-omnas!', 12, 0, 100, 0, 0, 67353, 118704, 'First Arcanist Thalyssra to First Mate Snellig'),
(113061, @GROUP_ID+8, @ID+0, 'It is too dangerous! The arcane torrents would tear us apart!', 12, 0, 100, 0, 0, 67355, 118705, 'First Arcanist Thalyssra to First Mate Snellig'),
(113061, @GROUP_ID+9, @ID+0, 'What are you doing?!', 12, 0, 100, 0, 0, 67358, 81078, 'First Arcanist Thalyssra to First Mate Snellig'), -- BroadcastTextID: 41145 - 81078
(113061, @GROUP_ID+10, @ID+0, 'Arluin! NO!!', 12, 0, 100, 0, 0, 67359, 118709, 'First Arcanist Thalyssra to First Mate Snellig'),
(113061, @GROUP_ID+11, @ID+0, 'Oculeth, get us out of here!', 12, 0, 100, 0, 0, 67361, 118711, 'First Arcanist Thalyssra to First Mate Snellig'),
(113061, @GROUP_ID+12, @ID+0, 'Ugh... we made it...', 12, 0, 100, 0, 0, 67362, 118712, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+13, @ID+0, 'Where is Arluin?!', 12, 0, 100, 0, 0, 67363, 118713, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+14, @ID+0, 'Oh no...', 12, 0, 100, 0, 0, 67364, 115290, 'First Arcanist Thalyssra to Player'), -- BroadcastTextID: 54947 - 65690 - 68228 - 115290
(113061, @GROUP_ID+15, @ID+0, 'Do not speak! You are wounded-', 12, 0, 100, 0, 0, 67366, 118716, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+16, @ID+0, 'Yes. You saved us. Please... try to rest.', 12, 0, 100, 0, 0, 67368, 118719, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+17, @ID+0, 'He is gone.', 12, 0, 100, 0, 0, 67370, 118720, 'First Arcanist Thalyssra to Player'),
(113061, @GROUP_ID+18, @ID+0, 'Come... Let us check on the others.', 12, 0, 100, 0, 0, 67371, 118721, 'First Arcanist Thalyssra to Player'),
(113062, @GROUP_ID+0, @ID+0, 'This is not looking real conduit-y. You sure the old man knows his stuff?', 12, 0, 100, 0, 0, 67338, 118661, 'Arluin to Player'),
(113062, @GROUP_ID+1, @ID+0, 'Whatever you gotta do, do it quick! Lots of guards heading our way.', 12, 0, 100, 0, 0, 67343, 118668, 'Arluin to First Mate Snellig'),
(113062, @GROUP_ID+2, @ID+0, 'Small words, please.', 12, 0, 100, 0, 0, 67345, 118679, 'Arluin to Player'),
(113062, @GROUP_ID+3, @ID+0, 'Wait, aren''t we supposed to leave BEFORE the storm starts?', 12, 0, 100, 0, 0, 67347, 118680, 'Arluin to Player'),
(113062, @GROUP_ID+4, @ID+0, 'Easier said than done...', 12, 0, 100, 0, 0, 67351, 118684, 'Arluin to Player'),
(113062, @GROUP_ID+5, @ID+0, 'The manastorm is only getting stronger! We need to shut that thing down!', 12, 0, 100, 0, 0, 67354, 118700, 'Arluin to First Mate Snellig'),
(113062, @GROUP_ID+6, @ID+0, 'Damn it...', 12, 0, 100, 0, 0, 67356, 118706, 'Arluin to First Mate Snellig'), -- BroadcastTextID: 27556 - 118706
(113062, @GROUP_ID+7, @ID+0, 'You guys owe me...', 12, 0, 100, 0, 0, 67357, 118707, 'Arluin to First Mate Snellig'),
(113062, @GROUP_ID+8, @ID+0, 'Hhghh-AAAHHHH!!!', 14, 0, 100, 16, 0, 67360, 118710, 'Arluin to First Mate Snellig'),
(113062, @GROUP_ID+9, @ID+0, '<cough> Nghh...', 12, 0, 100, 0, 0, 67365, 118715, 'Arluin to Player'),
(113062, @GROUP_ID+10, @ID+0, 'We pulled it off... <wheeze> didn''t we?', 12, 0, 100, 0, 0, 67367, 118718, 'Arluin to Player'),
(113062, @GROUP_ID+11, @ID+0, 'Hey... <cough> Tell Vanthir I said... thanks... for every...', 12, 0, 100, 0, 0, 67369, 118717, 'Arluin to Player'),
(113114, @GROUP_ID+0, @ID+0, 'I heard about this crazy job you guys are planning. You weren''t thinking of leaving me out, were you?', 12, 0, 100, 0, 0, 67301, 118629, 'Arluin to Player'),
(113114, @GROUP_ID+1, @ID+0, 'Look, I am not blind. I see what is happening in Suramar.', 12, 0, 100, 1, 0, 67303, 118630, 'Arluin to Player'),
(113114, @GROUP_ID+2, @ID+0, 'I am not sitting this one out. The stakes are too high. So I am in, you got that?', 12, 0, 100, 0, 0, 67304, 118631, 'Arluin to Player'),
(113114, @GROUP_ID+3, @ID+0, 'Oh and don''t worry about my usual fee - you can pay me when the job is done.', 12, 0, 100, 1, 0, 67305, 118632, 'Arluin to Player'), -- BroadcastTextID: 118632 - 118641
(113114, @GROUP_ID+4, @ID+0, 'Get in, plant the device, get out before it goes off. Not the most complicated job I have been on.', 12, 0, 100, 1, 0, 67335, 118648, 'Arluin to Player'),
(113166, @GROUP_ID+0, @ID+0, 'You will bow to us!', 12, 0, 100, 0, 0, 65667, 116700, 'Duskwatch Arcblade to First Arcanist Thalyssra'), -- BroadcastTextID: 116686 - 116700
(113166, @GROUP_ID+1, @ID+0, 'Scum like you should obey your betters.', 12, 0, 100, 0, 0, 65867, 116706, 'Duskwatch Arcblade to Player'), -- BroadcastTextID: 100932 - 116706
(113207, @GROUP_ID+0, @ID+0, 'I never met a lock I could not open.', 12, 0, 100, 0, 0, 67340, 118663, 'Arluin to Player'),
(113207, @GROUP_ID+1, @ID+0, 'Just give me one moment.', 12, 0, 100, 0, 0, 67341, 118664, 'Arluin to Player'),
(113208, @GROUP_ID+0, @ID+0, 'Look out!', 12, 0, 100, 0, 0, 67341, 114489, 'First Arcanist Thalyssra to Player'), -- BroadcastTextID: 14999 - 25299 - 27921 - 39797 - 40269 - 54489 - 56206 - 58002 - 78487 - 87001 - 91594 - 99114 - 107590 - 114489
(114472, @GROUP_ID+0, @ID+0, 'Arash-falas...', 12, 0, 100, 0, 0, 65900, 116431, 'Duskwatch Highblade to Player'), -- BroadcastTextID: 102165 - 116431 - 116760 - 116771 - 116781 - 116791
(114474, @GROUP_ID+0, @ID+0, 'Tor''theras falar!', 12, 0, 100, 0, 0, 65689, 116432, 'Duskwatch Highblade to First Arcanist Thalyssra'), -- BroadcastTextID: 102166 - 116432 - 116759 - 116770 - 116780 - 116790
(114474, @GROUP_ID+1, @ID+0, 'Im... impossible.', 12, 0, 100, 0, 0, 65688, 116429, 'Duskwatch Highblade to Player'), -- BroadcastTextID: 102163 - 116429
(114868, @GROUP_ID+0, @ID+0, 'It is hopeless to resist...', 12, 0, 100, 0, 0, 66020, 116783, 'Felborne Enforcer to Player'), -- BroadcastTextID: 116773 - 116783
(114876, @GROUP_ID+0, @ID+0, 'You flee at the cost of your life!', 12, 0, 100, 0, 0, 0, 124634, 'Vengeful Wrathguard'),
(114904, @GROUP_ID+0, @ID+0, 'Line them up!', 14, 0, 100, 36, 0, 0, 123594, 'Soul Engine Jailer to Player'),
(114904, @GROUP_ID+1, @ID+0, 'Ah, look, another prisoner!', 12, 0, 100, 0, 0, 0, 123595, 'Soul Engine Jailer to Player'),
(114904, @GROUP_ID+2, @ID+0, 'Just in time for the next ferry. It''s off to the Soul Engine with you!', 12, 0, 100, 0, 0, 0, 123746, 'Soul Engine Jailer to Player'),
(114948, @GROUP_ID+0, @ID+0, 'There you are! Over here!', 12, 0, 100, 0, 0, 78391, 124353, 'Silgryn to Player'),
(114948, @GROUP_ID+1, @ID+0, 'Elisande knows about Vanthir''s involvement in the rebellion. He is gone.', 12, 0, 100, 0, 0, 78392, 123461, 'Silgryn to Player'),
(114948, @GROUP_ID+2, @ID+0, 'I will move ahead and clear out a safe haven for the survivors. Stay strong, my friend.', 12, 0, 100, 0, 0, 78360, 124361, 'Silgryn to Player'),
(114948, @GROUP_ID+3, @ID+0, 'Now all we need is a to make contact with--', 12, 0, 100, 0, 0, 78554, 123716, 'Silgryn to Player'),
(114948, @GROUP_ID+4, @ID+0, 'Thalyssra?!', 12, 0, 100, 0, 0, 65777, 124165, 'Silgryn to Player'),
(114948, @GROUP_ID+5, @ID+0, 'What manner of spell is this?', 12, 0, 100, 0, 0, 78524, 124166, 'Silgryn to Player'),
(114948, @GROUP_ID+6, @ID+0, 'Fear not, First Arcanist. I will see to it that our friend here comes to no harm.', 12, 0, 100, 0, 0, 78594, 124160, 'Silgryn to Player'),
(114948, @GROUP_ID+7, @ID+0, 'I am sadly familiar with Vanthir''s captor.', 12, 0, 100, 0, 0, 78595, 124161, 'Silgryn to Player'),
(114958, @GROUP_ID+0, @ID+0, 'Elisande must be stopped!', 12, 0, 100, 0, 0, 79245, 123450, 'Duskwatch Subjugator to Player'),
(114958, @GROUP_ID+1, @ID+0, 'This is too much... if I must be labeled a traitor then so be it!', 12, 0, 100, 397, 0, 79245, 123451, 'Duskwatch Subjugator to Player'),
(114958, @GROUP_ID+2, @ID+0, 'I knew there were others! I will no longer bloody my hands for Elisande!', 12, 0, 100, 0, 0, 79245, 123449, 'Duskwatch Subjugator to Player'),
(114978, @GROUP_ID+0, @ID+0, 'Oh, thank you! This masterpiece is worth my life a hundred times over.', 12, 0, 100, 603, 0, 0, 123472, 'Master Devlyn to Player'),
(114983, @GROUP_ID+0, @ID+0, 'Behind you!', 12, 0, 100, 0, 0, 0, 124769, 'Thorvos to Player'),
(114983, @GROUP_ID+1, @ID+0, 'I am right behind you! Go!', 12, 0, 100, 603, 0, 0, 124770, 'Thorvos to Player'),
(114984, @GROUP_ID+0, @ID+0, 'F-father... Run...', 12, 0, 100, 396, 0, 0, 123479, 'Valanth to Player'),
(114985, @GROUP_ID+0, @ID+0, '%s spits on the corpse of the demon.', 16, 0, 100, 0, 0, 0, 123473, 'Scarleth to Player'),
(114985, @GROUP_ID+1, @ID+0, 'I know where to find Shal''Aran. Come, ladies. We are no longer safe in the city.', 12, 0, 100, 396, 0, 0, 123476, 'Scarleth to Player'),
(114998, @GROUP_ID+0, @ID+0, 'Let there be no slack in their chains!', 14, 0, 100, 0, 0, 53329, 123540, 'Aargoss'),
(114998, @GROUP_ID+1, @ID+0, 'More come from Suramar every hour! Move out! Make room!', 14, 0, 100, 0, 0, 0, 123543, 'Aargoss'),
(114998, @GROUP_ID+2, @ID+0, 'We must not leave the Soul Engine waiting!', 14, 0, 100, 0, 0, 78451, 123542, 'Aargoss'),
(114998, @GROUP_ID+3, @ID+0, 'Ha! You walk willingly to your death, mortal!', 12, 0, 100, 0, 0, 78444, 124519, 'Aargoss'),
(114998, @GROUP_ID+4, @ID+0, 'I will take great pleasure in grinding your soul to nothing!', 12, 0, 100, 0, 0, 78445, 124520, 'Aargoss'),
(114998, @GROUP_ID+5, @ID+0, 'Shaza-kiel!', 12, 0, 100, 0, 0, 78446, 124521, 'Aargoss to Player'), -- BroadcastTextID: 18243 - 91201 - 124521
(114998, @GROUP_ID+6, @ID+0, 'You are nothing! Insignificant gnat!', 12, 0, 100, 0, 0, 78447, 124522, 'Aargoss'),
(114998, @GROUP_ID+7, @ID+0, 'No! ... I will be... fuel...', 12, 0, 100, 0, 0, 78448, 124523, 'Aargoss to Player'),
(115014, @GROUP_ID+0, @ID+0, 'Hmm... medium or well-done?', 12, 0, 100, 0, 0, 53329, 102137, 'Felsoul Imp to Player'),
(115014, @GROUP_ID+1, @ID+0, 'Tasty meats for me to eats.', 12, 0, 100, 0, 0, 55207, 96658, 'Felsoul Imp to Player'),
(115018, @GROUP_ID+0, @ID+0, 'I hope she sees this...', 12, 0, 100, 0, 0, 78550, 124501, 'Silgryn to Player'),
(115018, @GROUP_ID+1, @ID+0, 'This way! Everyone into the boat!', 12, 0, 100, 0, 0, 78551, 124502, 'Silgryn to Player'),
(115018, @GROUP_ID+2, @ID+0, 'Excellent timing as usual, Deline.', 12, 0, 100, 0, 0, 78552, 124503, 'Silgryn to Player'),
(115049, @GROUP_ID+0, @ID+0, 'See that these people escape the city, Deline. $n, stay with me.', 12, 0, 100, 0, 0, 78557, 123713, 'Silgryn to Player'),
(115049, @GROUP_ID+1, @ID+0, 'This way!', 12, 0, 100, 397, 0, 78553, 123714, 'Silgryn to Player'), -- BroadcastTextID: 49296 - 56640 - 92787 - 123714
(115078, @GROUP_ID+0, @ID+0, 'He will be fine. The fruit will bring him back.', 12, 0, 100, 0, 0, 78582, 124539, 'Arluelle to Player'),
(115243, @GROUP_ID+0, @ID+0, 'I have urgent news, Thalyssra.', 12, 0, 100, 0, 0, 78611, 124022, 'Image of Ly''leth Lunastre to Player'),
(115243, @GROUP_ID+1, @ID+0, 'The portal to my estate is secure. You will want to hear this in person.', 12, 0, 100, 0, 0, 78612, 124023, 'Image of Ly''leth Lunastre to Player'),
(115247, @GROUP_ID+0, @ID+0, 'Welcome home, First Arcanist. Thank you for coming on such short notice.', 12, 0, 100, 0, 0, 0, 124055, 'Ly''leth Lunastre to Player'),
(115247, @GROUP_ID+1, @ID+0, 'I have heard terrible rumors about our friend Vanthir.', 12, 0, 100, 0, 0, 78616, 124063, 'Ly''leth Lunastre to Player'),
(115247, @GROUP_ID+2, @ID+0, 'He is to be made an example for all to see.', 12, 0, 100, 0, 0, 78617, 124535, 'Ly''leth Lunastre to Player'),
(115247, @GROUP_ID+3, @ID+0, 'I do not know. I only hope we are not too late.', 12, 0, 100, 0, 0, 78619, 124537, 'Ly''leth Lunastre to Player'),
(115247, @GROUP_ID+4, @ID+0, 'Be safe, Thalyssra. I must return to the palace.', 12, 0, 100, 0, 0, 78406, 124075, 'Ly''leth Lunastre to Player'),
(115248, @GROUP_ID+0, @ID+0, 'Thank you, Advisor. What news?', 12, 0, 100, 0, 0, 78615, 124056, 'First Arcanist Thalyssra to Player'),
(115248, @GROUP_ID+1, @ID+0, 'How much time do we have?', 12, 0, 100, 0, 0, 78618, 124536, 'First Arcanist Thalyssra to Player'),
(115248, @GROUP_ID+2, @ID+0, 'Keep your voice down, Silgryn. It is good to see you too.', 12, 0, 100, 0, 0, 78408, 124164, 'First Arcanist Thalyssra to Player'),
(115248, @GROUP_ID+3, @ID+0, 'One that will find our friend.', 12, 0, 100, 0, 0, 78525, 124167, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+0, @ID+0, 'I will find him. Preferably without being seen.', 12, 0, 100, 0, 0, 78416, 123637, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+1, @ID+0, 'This must be where he took many meals...', 12, 0, 100, 0, 0, 78409, 123698, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+2, @ID+0, 'There it is. We are coming, Vanthir.', 12, 0, 100, 0, 0, 78410, 123699, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+3, @ID+0, 'This garden likely gave him many hours of respite. His essence is strong and bright, here.', 12, 0, 100, 0, 0, 78411, 123700, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+4, @ID+0, 'I can feel him! He is still alive, at least.', 12, 0, 100, 0, 0, 78412, 123701, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+5, @ID+0, 'One of his suppliers must have served him here. Reminders of a simpler time.', 12, 0, 100, 0, 0, 78413, 123702, 'First Arcanist Thalyssra to Player'),
(115277, @GROUP_ID+6, @ID+0, 'Perfect. This will be enough to find him.', 12, 0, 100, 0, 0, 78414, 123703, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+0, @ID+0, 'Talk to me, Vanthir...', 12, 0, 100, 0, 0, 78526, 124129, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+1, @ID+0, 'The moment he was taken from the Waning Crescent he felt such terrible fear... but not for himself.', 12, 0, 100, 0, 0, 78527, 124130, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+2, @ID+0, 'Fear for those that he sheltered, those he sacrificed for.', 12, 0, 100, 0, 0, 78528, 124131, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+3, @ID+0, 'He was taken somewhere dark and isolated. He began to feel hunger settling its roots in his gut.', 12, 0, 100, 0, 0, 78529, 124132, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+4, @ID+0, 'Hunger that did not pass, but grew...', 12, 0, 100, 0, 0, 78530, 124133, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+5, @ID+0, '... Until he could think of nothing else!', 12, 0, 100, 0, 0, 78531, 124134, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+6, @ID+0, 'He is near to withering. His thoughts are jumbled, frantic... I just need to...', 12, 0, 100, 0, 0, 78532, 124135, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+7, @ID+0, 'Focus! There!', 12, 0, 100, 0, 0, 78533, 124136, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+8, @ID+0, 'He is being held at the Terrace of Order! It must be time for the display...', 12, 0, 100, 0, 0, 78534, 124137, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+9, @ID+0, 'That took more out of me than I thought it would. You will have to free Vanthir without me. I am sorry.', 12, 0, 100, 0, 0, 78580, 124154, 'First Arcanist Thalyssra to Player'),
(115557, @GROUP_ID+10, @ID+0, 'Thank you, Silgryn. Be careful.', 12, 0, 100, 0, 0, 78581, 124162, 'First Arcanist Thalyssra to Player'),
(115604, @GROUP_ID+0, @ID+0, 'Vanthir struggles to his feet.', 16, 0, 100, 0, 0, 0, 125238, 'Vanthir to Player'),
(115604, @GROUP_ID+1, @ID+0, 'Relief... at last...', 12, 0, 100, 0, 0, 78596, 124540, 'Vanthir to Player'),
(115604, @GROUP_ID+2, @ID+0, 'Aran''ethil... The nightmare is over!', 12, 0, 100, 0, 0, 78597, 124541, 'Vanthir to Player'),
(115604, @GROUP_ID+3, @ID+0, 'They wanted to make an example. We have stolen their message and made it ours.', 12, 0, 100, 0, 0, 78568, 124543, 'Vanthir to Player'),
(115604, @GROUP_ID+4, @ID+0, 'All will see... hope... in the Dusk Lily.', 12, 0, 100, 0, 0, 78569, 124544, 'Vanthir to Player'),
(115604, @GROUP_ID+5, @ID+0, '<Cough.> I need... to rest now. Thank you. Thank you for everything.', 12, 0, 100, 0, 0, 78566, 124545, 'Vanthir to Player'),
(115607, @GROUP_ID+0, @ID+0, 'You think to stop this demonstration? Very well. I will make an example of you first!', 12, 0, 100, 0, 0, 78599, 124260, 'Thoramir'),
(115607, @GROUP_ID+1, @ID+0, 'She... was right... about you...', 12, 0, 100, 0, 0, 78607, 124269, 'Thoramir to Arluelle'),
(115608, @GROUP_ID+0, @ID+0, 'I know.', 12, 0, 100, 0, 0, 78608, 124270, 'Silgryn to Arluelle'),
(115608, @GROUP_ID+1, @ID+0, 'Lay still, my friend. We will get you out.', 12, 0, 100, 0, 0, 78610, 124538, 'Silgryn to Player'),
(115608, @GROUP_ID+2, @ID+0, 'Welcome back, old friend.', 12, 0, 100, 0, 0, 78598, 124542, 'Silgryn to Player'),
(115608, @GROUP_ID+3, @ID+0, 'We will see him back to safety. Go inform Thalyssra of our success.', 12, 0, 100, 0, 0, 78567, 124546, 'Silgryn to Player'),
(115710, @GROUP_ID+0, @ID+0, 'No need to delay. Onto the pad with you.', 12, 0, 100, 25, 0, 78389, 123457, 'Chief Telemancer Oculeth to Player'),
(115710, @GROUP_ID+1, @ID+0, 'I will get you as close to the Crescent as I can. We will be in touch.', 12, 0, 100, 0, 0, 78390, 124348, 'Chief Telemancer Oculeth to Player'),
(115736, @GROUP_ID+0, @ID+0, 'She is waiting for you just outside.', 12, 0, 100, 1, 0, 78535, 124504, 'First Arcanist Thalyssra to Player'),
(115736, @GROUP_ID+1, @ID+0, 'Come. I do not want to keep her waiting.', 12, 0, 100, 0, 0, 78613, 124024, 'First Arcanist Thalyssra to Player'),
(115991, @GROUP_ID+0, @ID+0, 'Father!!', 12, 0, 100, 1, 0, 0, 124735, 'Emille to Player'),
(115992, @GROUP_ID+0, @ID+0, 'I''m going!', 12, 0, 100, 1, 0, 0, 124736, 'Brigitte to Player'),
(116001, @GROUP_ID+0, @ID+0, 'Praise all that is good... you are both safe. Come, let us get out of here!', 12, 0, 100, 0, 0, 0, 123469, 'Eneas to Player'),
(116013, @GROUP_ID+0, @ID+0, 'You think you can hide from Elisande? Die, traitors!', 12, 0, 100, 0, 0, 0, 124768, 'Duskwatch Punisher to Player'),
(116085, @GROUP_ID+0, @ID+0, 'Arluelle places a dusky purple flower before the little planter.', 16, 0, 100, 0, 0, 0, 124894, 'Arluelle to Player'),
(116085, @GROUP_ID+1, @ID+0, 'Do you remember me, outlander?', 12, 0, 100, 1, 0, 78536, 124505, 'Arluelle to Player'),
(116085, @GROUP_ID+2, @ID+0, 'My brother rests here. My name is Arluelle.', 12, 0, 100, 1, 0, 78537, 124507, 'Arluelle to Player');

UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106111; -- Frostcrag Stonecaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92245; -- Thala Steeltotem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103886; -- Twilight Orelifter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104690; -- Beamer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103235; -- Taskmaster Filthwhisker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103234; -- Taskmaster Skraggletail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101630; -- Trancheterre pierre-d’ambre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103179; -- Gunksnout Geomancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103177; -- Gunksnout Runt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104691; -- Gunksnout Backstabber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103227; -- Wax Miner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93841; -- Lasan Skyhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103178; -- Gunksnout Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102634; -- Scalewhisker Cavalry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102633; -- Waxeye Glazer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104243; -- Bound Elemental
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103197; -- Kill Credit: Kobold Candle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102078; -- Rogg Shard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102629; -- Brick
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102628; -- Stonefist Pit Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102205; -- Pathfinder Linny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102203; -- Skyhorn Pathfinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102123; -- Ronir Wrangler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101823; -- Mushroom Merchant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=62313; -- Escargot rouille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101813; -- Greystone Chompkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101645; -- Greystone Trencher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98310; -- Burrow Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101785; -- Steelgaze Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103090; -- Greystone Fishbrul
UPDATE `creature_template` SET `RequiredExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=101649; -- Frostshard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102623; -- Stonefist Brawler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102632; -- Glowing Deepshard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=26614; -- Lièvre patte-blanche
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97741; -- Renardeau sombre-patte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102875; -- Gilnean Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102871; -- Gilnean Shotgunner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102866; -- Gilnean Swiftclaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103592; -- Bonebeak Hawk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96590; -- Gurbog da Basher
UPDATE `creature_template` SET `KillCredit1`=0, `VerifiedBuild`=25996 WHERE `entry`=97976; -- Bonebeak Hawk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96548; -- Rabbit
UPDATE `creature_template` SET `modelid3`=74405, `VerifiedBuild`=25996 WHERE `entry`=49996; -- Mountain Cottontail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97118; -- Hibou à grandes oreilles
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61167; -- Lapin des montagnes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99216; -- Arxas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95718; -- Aigle de guerre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95717; -- Intercepteur corne-céleste
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96691; -- Mightstone Slinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97013; -- Xist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99217; -- Naxa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97735; -- Long-Eared Owl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97506; -- Chaman crin-de-rive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97498; -- Brave-guerrier de Haut-Roc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96690; -- Mightstone Flanker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98211; -- Castor à queue piquante
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99214; -- Siege Worm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108185; -- Coldscale Gazecrawler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99027; -- Mora Cliffhoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99026; -- Gala Woodbridge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99029; -- A'te Amberfur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99028; -- Ferra Leafheart
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100437; -- Lanna Skyspark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98210; -- Spiketail Beaver
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=72654; -- General Purpose Stalker (RKS)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97572; -- Cavern Eel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99711; -- Highmountain Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104757; -- Winter Elderhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=83674; -- Mud Jumper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110496; -- Coldwater Goldscale
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110499; -- Aileron-long d’eau douce
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108017; -- Torv Dubstomp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99699; -- Thunder Drum Circle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99652; -- Highmountain Spiritwalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=73678; -- General Purpose Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107988; -- Bolas Launcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108082; -- Bolas Launcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107660; -- Bolas Skyfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98017; -- Guron Twaintail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109159; -- Holk the Wanderer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97857; -- Bilge Clearwater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97852; -- Ernu Mesawind
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99894; -- Losro Greyfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97856; -- Nol Wildpath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99905; -- Shale Greyfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97858; -- Galica Bravepaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99903; -- Sprig Hashhoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99753; -- Rivermane Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97508; -- Healing Stream Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98220; -- Injured Warbrave
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4096, `HealthModifier`=20, `VerifiedBuild`=25996 WHERE `entry`=119824; -- Rivermane Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99912; -- Old Hook-eye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99913; -- Whitewater Grouper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99672; -- Sakrul the Brewbrul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115784; -- Nouveau-né plume-neige
UPDATE `creature_template` SET `type_flags2`=32768, `VerifiedBuild`=25996 WHERE `entry`=93826; -- Mayla Highmountain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97880; -- Rivermane Fisherman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99624; -- Navarrogg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99533; -- Jale Rivermane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99225; -- Lasan Skyhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108434; -- Mayla Highmountain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99670; -- Uungbrul
UPDATE `creature_template` SET `modelid1`=66920, `VerifiedBuild`=25996 WHERE `entry`=99671; -- Obrul the Thug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104692; -- Greystone Flanker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99669; -- Bogrogg the Stonescreamer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96084; -- Sella Waterwise
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96083; -- Rordan Waterwise
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107726; -- Ethel Waterwise
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103485; -- Lessah Moonwater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103733; -- Luron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99660; -- Fara Dawntrail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104624; -- Wounded Highmountain Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99708; -- Highmountain Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111184; -- Greystone Shardcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104660; -- Blargrul the Siegebrul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104615; -- Greystone Flanker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106460; -- Savyn Valorborn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113270; -- Vierge guerrière
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=88708; -- Gara
UPDATE `creature_template` SET `HealthModifier`=1.4, `VerifiedBuild`=25996 WHERE `entry`=90134; -- Grizzly de Llothien
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `family`=39, `type_flags`=2162797, `type_flags2`=129, `VerifiedBuild`=25996 WHERE `entry`=71529; -- Thok the Bloodthirsty
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103196; -- Kobold Candle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95688; -- Windtamer Nalt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96565; -- Chofa Nighthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111351; -- Garona Halforcen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109407; -- Nightborne Sergeant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109388; -- Nightborne Spy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5274; -- Ironfur Patriarch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109376; -- Rendezvous Point
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97174; -- Oeil éteint
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115563; -- Captured Nightfallen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115562; -- Duskwatch Felblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115561; -- Duskwatch Felblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105662; -- Freed Zhevra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=9690; -- Ember Worg
UPDATE `creature_template` SET `modelid3`=0, `VerifiedBuild`=25996 WHERE `entry`=116736; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `modelid1`=67345, `modelid2`=0, `VerifiedBuild`=25996 WHERE `entry`=110791; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115625; -- Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=119061; -- Marteleur de Griseveille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102306; -- Swirling Pool
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100354; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100353; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100188; -- Piercing Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99801; -- Destructor Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97099; -- Swirling Pool
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99803; -- Destructor Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98363; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99800; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101502; -- Helya's Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100360; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100359; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96759; -- Helya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101814; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101504; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114289; -- Skeletal Sorcerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114288; -- Skeletal Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99033; -- Helarjar Mistcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99307; -- Skjal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98761; -- Soul Fragment
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98693; -- Shackled Servitor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98989; -- Cosmic Scythe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100839; -- Cosmic Scythe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104906; -- Captured Val'kyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98973; -- Skeletal Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97097; -- Helarjar Champion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96754; -- Harbaron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102830; -- Deceased Sorcerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102769; -- Decrepit Runecarver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102742; -- Fallen Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102327; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102326; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97185; -- The Grimewalker
UPDATE `creature_template` SET `type`=6, `VerifiedBuild`=25996 WHERE `entry`=97119; -- Shroud Hound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102325; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98291; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99188; -- Waterlogged Soul Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98919; -- Seacursed Swiftblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97365; -- Seacursed Mistmender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97182; -- Night Watch Mariner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103115; -- Helheim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=76168; -- Ravager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96756; -- Ymiron, the Fallen King
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114712; -- Runecarver Slave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102894; -- Runecarver Slave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101013; -- Captured Runecarver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102375; -- Runecarver Slave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97200; -- Seacursed Soulkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102896; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102108; -- Captured Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102104; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97208; -- Spear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97043; -- Esclavagiste maudit par les flots
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97163; -- Cursed Falke
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115720; -- Dusk Lily Sigil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115604; -- Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115608; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=45380; -- Ashtail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115687; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115590; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115571; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115589; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115570; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115581; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115569; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115584; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115557; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=119059; -- Apprenti de la Tirisgarde
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116559; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116558; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115260; -- Echo of Vanthir
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=69943; -- Gumi
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `type`=12, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=69848; -- Porc-épique spectral
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115259; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115531; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115530; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115535; -- Assassin rôdeur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107801; -- Unstable Power
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103959; -- Sira Moonwarden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115258; -- Echo of Vanthir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107797; -- Volatile Mana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115248; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115247; -- Ly'leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98233; -- Withered Hungerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115243; -- Image of Ly'leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115377; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115072; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115378; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115075; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116368; -- Felsoul Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115376; -- Maribeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116411; -- Soul Engine Gateway
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115071; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111377; -- Knobbed Welk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111414; -- Saltscale Grouper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115081; -- Deline
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116367; -- Felborne Conspirator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115079; -- Victoire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115078; -- Arluelle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115003; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115002; -- Maribeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116659; -- Felsoul Ferry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115000; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115074; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115014; -- Felsoul Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115073; -- Doomed Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115067; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115066; -- Shal'dorei Civilian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114998; -- Aargoss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=55370; -- General Purpose Bunny ZTO
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116317; -- Slowfall Rune
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114956; -- Victoire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114949; -- Arluelle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116256; -- Victoire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116506; -- Image of Ly'leth Lunastre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116085; -- Arluelle
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=35396; -- Jeune raptor véloce
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115049; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115048; -- Deline
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114971; -- Deline's Gondola
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114970; -- Deline's Gondola
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116044; -- Deline
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115080; -- Deline's Gondola
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116013; -- Duskwatch Punisher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114989; -- Jynn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114988; -- Ruthela
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114987; -- Vyvari
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114986; -- Celandra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116054; -- Master Devlyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114985; -- Scarleth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115018; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116057; -- Brigitte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116056; -- Emille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116055; -- Eneas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114978; -- Master Devlyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114984; -- Valanth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114983; -- Thorvos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116001; -- Eneas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115991; -- Emille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115992; -- Brigitte
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116584; -- The Waning Crescent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115772; -- Kal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114969; -- Kill Credit: Silgryn Found
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114948; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114868; -- Felborne Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114875; -- Felwing Purifier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114873; -- Palace Warden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115810; -- FX Stalker [DNT]
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=4139; -- [Deprecated for 4.x]Scorpid Terror
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115710; -- Télémancien en chef Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115371; -- Arcaniste Valtrois
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115736; -- Première arcaniste Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110698; -- Arluelle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112146; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112145; -- Arcanist Valtrois
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114291; -- Arcan'dor Vine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112147; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113585; -- Arcway Reclaimer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113332; -- Mana Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113426; -- Place E.M.P.
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113208; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113207; -- Arluin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113191; -- Duskwatch Archivist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113178; -- Archivist's Tome
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113168; -- Duskwatch Ley-Warden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113172; -- Duskwatch Rune Scribe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113062; -- Arluin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113061; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113202; -- Runebound Wyrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113166; -- Duskwatch Arcblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113114; -- Arluin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97179; -- Oeil d’inquisition
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115600; -- Terrified Nightfallen
UPDATE `creature_template` SET `KillCredit1`=127375, `HealthScalingExpansion`=6, `VignetteID`=2281, `rank`=2, `type`=3, `type_flags`=2097224, `HealthModifier`=63, `VerifiedBuild`=25996 WHERE `entry`=127376; -- Chief Alchemist Munculus
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2279, `rank`=2, `type`=3, `type_flags`=2097224, `HealthModifier`=66, `VerifiedBuild`=25996 WHERE `entry`=127300; -- Void Warden Valsuran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126338; -- Wrath-Lord Yarez
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93444; -- Thistleleaf Thorndancer
UPDATE `creature_template` SET `RequiredExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=95123; -- Grelda la Harpie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109015; -- Lagertha
UPDATE `creature_template` SET `KillCredit1`=117325, `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=1.8, `VerifiedBuild`=25996 WHERE `entry`=118322; -- Punisseur gangrenuit
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=117352; -- Sister Bloodweb
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=117351; -- Sister Silkreaver
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=117350; -- Sister Deathweaver
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=42, `VerifiedBuild`=25996 WHERE `entry`=116955; -- Garthulak the Crusher
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=6, `VerifiedBuild`=25996 WHERE `entry`=116436; -- Maître des portails Arinor
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=6, `VerifiedBuild`=25996 WHERE `entry`=116297; -- Doom Lord Kro'nak
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=45, `movementId`=123, `VerifiedBuild`=25996 WHERE `entry`=118000; -- Subjugator Val'rek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98680; -- Sphere of Insanity

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=95123 AND `Idx`=2);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(95123, 2, 143322, 25996); -- Grelda la Harpie

UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103886 AND `Idx`=0); -- Twilight Orelifter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101630 AND `Idx`=0); -- Trancheterre pierre-d’ambre
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104243 AND `Idx`=0); -- Bound Elemental
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101785 AND `Idx`=1); -- Steelgaze Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101785 AND `Idx`=0); -- Steelgaze Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101649 AND `Idx`=2); -- Frostshard
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101649 AND `Idx`=1); -- Frostshard
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101649 AND `Idx`=0); -- Frostshard
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103592 AND `Idx`=0); -- Bonebeak Hawk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=97976 AND `Idx`=0); -- Bonebeak Hawk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99216 AND `Idx`=1); -- Arxas
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99216 AND `Idx`=0); -- Arxas
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96691 AND `Idx`=0); -- Mightstone Slinger
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=97013 AND `Idx`=1); -- Xist
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=97013 AND `Idx`=0); -- Xist
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99217 AND `Idx`=1); -- Naxa
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99217 AND `Idx`=0); -- Naxa
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96690 AND `Idx`=0); -- Mightstone Flanker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108185 AND `Idx`=2); -- Coldscale Gazecrawler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108185 AND `Idx`=1); -- Coldscale Gazecrawler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108185 AND `Idx`=0); -- Coldscale Gazecrawler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=97572 AND `Idx`=0); -- Cavern Eel
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110496 AND `Idx`=0); -- Coldwater Goldscale
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111184 AND `Idx`=0); -- Greystone Shardcaster
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=6); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=5); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=4); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=3); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=2); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=1); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=90134 AND `Idx`=0); -- Grizzly de Llothien
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=5274 AND `Idx`=0); -- Ironfur Patriarch
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=9690 AND `Idx`=0); -- Ember Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=45380 AND `Idx`=0); -- Ashtail
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=111414 AND `Idx`=0); -- Saltscale Grouper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93444 AND `Idx`=1); -- Thistleleaf Thorndancer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93444 AND `Idx`=0); -- Thistleleaf Thorndancer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95123 AND `Idx`=1); -- Grelda la Harpie
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=95123 AND `Idx`=0); -- Grelda la Harpie

DELETE FROM `gameobject_template` WHERE `entry` IN (268759 /*Firmament Stone in Highmountain*/, 248588 /*Brazier*/, 245389 /*Bow*/, 245388 /*Arrow Stack 02*/, 245387 /*Arrow Stack 01*/, 259115 /*Highmountain Postcard*/, 245378 /*Eagle Perch*/, 267034 /*Portal to Stormheim*/, 265477 /*Murky Fog*/, 265476 /*Murky Fog*/, 246948 /*Wall of Souls*/, 246947 /*Wall of Souls*/, 246890 /*Heavy Barnacled Door*/, 246889 /*Heavy Barnacled Door*/, 246888 /*Heavy Barnacled Door*/, 246435 /*Wall of Souls*/, 245609 /*Invisible Door*/, 246839 /*Trap Door 005*/, 246838 /*Trap Door 006*/, 246837 /*Trap Door 010*/, 246835 /*Trap Door 009*/, 246836 /*Trao Door 008*/, 246834 /*Trap Door 007*/, 246844 /*Trap Door 004*/, 246840 /*Trap Door 001*/, 246843 /*Trap Door 003*/, 246842 /*Trap Door 002*/, 246841 /*Trap Door 011*/, 224697 /*Fresh Carcass*/, 251963 /*7VR_VRYKUL_RITUALROCKS02 [scale x3]*/, 246919 /*The Naglfar*/, 253001 /*Rune-etched Archway*/, 245066 /*Kvaldir Cage*/, 245062 /*Kvaldir Cage*/, 245067 /*Kvaldir Cage*/, 245063 /*Kvaldir Cage*/, 245064 /*Kvaldir Cage*/, 245065 /*Kvaldir Cage*/, 265956 /*Portal to Evermoon Terrace*/, 265529 /*Portal to Shal'Aran*/, 266404 /*Bookcase*/, 266403 /*Book Pile 1*/, 266402 /*Generic Rubble Glass B*/, 266400 /*Generic Rubble B*/, 266399 /*Generic Rubble A*/, 265520 /*Master's Vase*/, 266401 /*Generic Rubble Glass A*/, 265485 /*Legion Altar*/, 266585 /*Shattered Teleporter Pad*/, 266179 /*Teleporter Pad*/, 257973 /*Fruit Basket*/, 257974 /*Wine Bottle*/, 257971 /*Dusk Lily*/, 257970 /*Nightborne Planter*/, 257972 /*Lantern*/, 265440 /*Doodad_7sr_hubmanatree003*/, 254939 /*Library Door*/, 254856 /*Ancient Tome*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(268759, 8, 9147, 'Firmament Stone in Highmountain', '', '', '', 1, 1917, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Firmament Stone in Highmountain
(248588, 8, 32834, 'Brazier', '', '', '', 0.63, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Brazier
(245389, 5, 29936, 'Bow', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bow
(245388, 5, 11658, 'Arrow Stack 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arrow Stack 02
(245387, 5, 11685, 'Arrow Stack 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Arrow Stack 01
(259115, 22, 16956, 'Highmountain Postcard', '', '', '', 0.25, 199942, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Highmountain Postcard
(245378, 5, 29814, 'Eagle Perch', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Eagle Perch
(267034, 22, 15196, 'Portal to Stormheim', '', '', '', 0.5, 233512, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Stormheim
(265477, 0, 31091, 'Murky Fog', '', '', '', 1.087075, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Murky Fog
(265476, 0, 31091, 'Murky Fog', '', '', '', 1.087075, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Murky Fog
(246948, 0, 31091, 'Wall of Souls', '', '', '', 0.6526883, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wall of Souls
(246947, 0, 31091, 'Wall of Souls', '', '', '', 0.6526883, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wall of Souls
(246890, 0, 31838, 'Heavy Barnacled Door', '', '', '', 0.8035647, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Heavy Barnacled Door
(246889, 0, 31838, 'Heavy Barnacled Door', '', '', '', 0.8035647, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Heavy Barnacled Door
(246888, 0, 31838, 'Heavy Barnacled Door', '', '', '', 1.029025, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Heavy Barnacled Door
(246435, 0, 10403, 'Wall of Souls', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wall of Souls
(245609, 0, 13594, 'Invisible Door', '', '', '', 0.175, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Invisible Door
(246839, 35, 31784, 'Trap Door 005', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 005
(246838, 35, 31783, 'Trap Door 006', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 006
(246837, 35, 31782, 'Trap Door 010', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 010
(246835, 35, 31780, 'Trap Door 009', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 009
(246836, 35, 31781, 'Trao Door 008', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trao Door 008
(246834, 35, 31779, 'Trap Door 007', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 007
(246844, 35, 31789, 'Trap Door 004', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 004
(246840, 35, 31785, 'Trap Door 001', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 001
(246843, 35, 31788, 'Trap Door 003', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 003
(246842, 35, 31787, 'Trap Door 002', '', '', '', 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 002
(246841, 35, 31786, 'Trap Door 011', '', '', '', 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Trap Door 011
(224697, 5, 14, 'Fresh Carcass', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fresh Carcass
(251963, 5, 35069, '7VR_VRYKUL_RITUALROCKS02 [scale x3]', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- 7VR_VRYKUL_RITUALROCKS02 [scale x3]
(246919, 33, 31852, 'The Naglfar', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- The Naglfar
(253001, 5, 36159, 'Rune-etched Archway', '', '', '', 1.147469, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rune-etched Archway
(245066, 0, 28949, 'Kvaldir Cage', '', '', '', 1.04, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kvaldir Cage
(245062, 0, 29585, 'Kvaldir Cage', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kvaldir Cage
(245067, 0, 28949, 'Kvaldir Cage', '', '', '', 1.04, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kvaldir Cage
(245063, 0, 29585, 'Kvaldir Cage', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kvaldir Cage
(245064, 0, 28949, 'Kvaldir Cage', '', '', '', 1.13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kvaldir Cage
(245065, 0, 28949, 'Kvaldir Cage', '', '', '', 1.04, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kvaldir Cage
(265956, 22, 36660, 'Portal to Evermoon Terrace', '', '', '', 1, 229361, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Evermoon Terrace
(265529, 22, 36654, 'Portal to Shal''Aran', '', '', '', 1, 202605, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Shal'Aran
(266404, 5, 39109, 'Bookcase', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bookcase
(266403, 5, 39108, 'Book Pile 1', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Book Pile 1
(266402, 5, 36390, 'Generic Rubble Glass B', '', '', '', 0.7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Generic Rubble Glass B
(266400, 5, 38878, 'Generic Rubble B', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Generic Rubble B
(266399, 5, 38877, 'Generic Rubble A', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Generic Rubble A
(265520, 22, 38880, 'Master''s Vase', 'questinteract', '', '', 1, 229000, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Master's Vase
(266401, 5, 36392, 'Generic Rubble Glass A', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Generic Rubble Glass A
(265485, 5, 27636, 'Legion Altar', '', '', '', 1.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Legion Altar
(266585, 5, 39202, 'Shattered Teleporter Pad', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Shattered Teleporter Pad
(266179, 5, 35940, 'Teleporter Pad', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Teleporter Pad
(257973, 5, 36175, 'Fruit Basket', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fruit Basket
(257974, 5, 34982, 'Wine Bottle', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Wine Bottle
(257971, 5, 35104, 'Dusk Lily', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Dusk Lily
(257970, 5, 37377, 'Nightborne Planter', '', '', '', 0.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nightborne Planter
(257972, 5, 37378, 'Lantern', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Lantern
(265440, 5, 32753, 'Doodad_7sr_hubmanatree003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7sr_hubmanatree003
(254939, 0, 34024, 'Library Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Library Door
(254856, 5, 34727, 'Ancient Tome', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Ancient Tome

UPDATE `gameobject_template` SET `name`='Firmament Stone', `VerifiedBuild`=25996 WHERE `entry`=254125; -- Firmament Stone
UPDATE `gameobject_template` SET `type`=3, `displayId`=31985, `castBarCaption`='Pilfering', `Data0`=43, `Data2`=1, `Data3`=1, `Data13`=1, `Data14`=83155, `Data30`=64451, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=247074; -- Wax Ingots
UPDATE `gameobject_template` SET `type`=3, `displayId`=31984, `castBarCaption`='Pilfering', `Data0`=43, `Data2`=1, `Data3`=1, `Data13`=1, `Data14`=83155, `Data30`=64450, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=247073; -- Wax Ingots
UPDATE `gameobject_template` SET `type`=3, `displayId`=31983, `castBarCaption`='Pilfering', `Data0`=43, `Data2`=1, `Data3`=1, `Data13`=1, `Data14`=83155, `Data30`=64449, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=247072; -- Wax Ingot
UPDATE `gameobject_template` SET `type`=3, `displayId`=31986, `castBarCaption`='Mining', `Data0`=899, `Data2`=1, `Data3`=1, `Data13`=1, `Data14`=78976, `Data30`=64449, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=247075; -- Secreted Wax Glob
UPDATE `gameobject_template` SET `name`='Kobold Sack Large 02', `VerifiedBuild`=25996 WHERE `entry`=245030; -- Kobold Sack Large 02
UPDATE `gameobject_template` SET `name`='Kobold Trash Pile 04', `VerifiedBuild`=25996 WHERE `entry`=245028; -- Kobold Trash Pile 04
UPDATE `gameobject_template` SET `name`='Kobold Trash Pile 03', `VerifiedBuild`=25996 WHERE `entry`=245027; -- Kobold Trash Pile 03
UPDATE `gameobject_template` SET `name`='Kobold Sack Large 01', `VerifiedBuild`=25996 WHERE `entry`=245029; -- Kobold Sack Large 01
UPDATE `gameobject_template` SET `name`='Kobold Trash Pile 01', `VerifiedBuild`=25996 WHERE `entry`=243686; -- Kobold Trash Pile 01
UPDATE `gameobject_template` SET `name`='EXIT', `VerifiedBuild`=25996 WHERE `entry`=246807; -- EXIT
UPDATE `gameobject_template` SET `type`=9, `displayId`=29925, `Data0`=5253, `Data1`=11, `Data2`=2, `VerifiedBuild`=25996 WHERE `entry`=247864; -- Ancient Neltharion Tablets
UPDATE `gameobject_template` SET `castBarCaption`='Pilfering', `VerifiedBuild`=25996 WHERE `entry`=247695; -- Elementium Slats
UPDATE `gameobject_template` SET `name`='Greystone Enclave', `VerifiedBuild`=25996 WHERE `entry`=246461; -- Greystone Enclave
UPDATE `gameobject_template` SET `name`='Conjured Boulders', `VerifiedBuild`=25996 WHERE `entry`=250547; -- Conjured Boulders
UPDATE `gameobject_template` SET `name`='Brulzerking', `VerifiedBuild`=25996 WHERE `entry`=246736; -- Brulzerking
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246734; -- Featherstone
UPDATE `gameobject_template` SET `name`='Deep Rejuvenation', `VerifiedBuild`=25996 WHERE `entry`=246740; -- Deep Rejuvenation
UPDATE `gameobject_template` SET `name`='Neltharion''s Lair', `VerifiedBuild`=25996 WHERE `entry`=243067; -- Neltharion's Lair
UPDATE `gameobject_template` SET `name`='Drogbar Doorway Prop', `VerifiedBuild`=25996 WHERE `entry`=245482; -- Drogbar Doorway Prop
UPDATE `gameobject_template` SET `name`='Banner', `VerifiedBuild`=25996 WHERE `entry`=246680; -- Banner
UPDATE `gameobject_template` SET `name`='Definitely not a trap.', `VerifiedBuild`=25996 WHERE `entry`=253996; -- Definitely not a trap.
UPDATE `gameobject_template` SET `name`='If Rich, Please Take', `VerifiedBuild`=25996 WHERE `entry`=253995; -- If Rich, Please Take
UPDATE `gameobject_template` SET `name`='Adventurers this way.', `VerifiedBuild`=25996 WHERE `entry`=253997; -- Adventurers this way.
UPDATE `gameobject_template` SET `name`='Free lootz ahead.', `VerifiedBuild`=25996 WHERE `entry`=253998; -- Free lootz ahead.
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data29`=1977, `VerifiedBuild`=25996 WHERE `entry`=250541; -- Treasure Chest
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.85, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=259084; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.69, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=259081; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.6, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=259080; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.69, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=259079; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.85, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=253068; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.69, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=253067; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.6, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=253066; -- Schwinderhoof
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `size`=1.69, `Data0`=5766, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=253065; -- Schwinderhoof
UPDATE `gameobject_template` SET `name`='Cooking Cauldron', `VerifiedBuild`=25996 WHERE `entry`=248593; -- Cooking Cauldron
UPDATE `gameobject_template` SET `type`=3, `displayId`=28816, `castBarCaption`='Opening', `size`=1.5, `Data0`=57, `Data2`=1, `Data4`=1, `Data5`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data27`=1, `Data30`=62031, `RequiredLevel`=98, `VerifiedBuild`=25996 WHERE `entry`=244473; -- Thunder Totem Stolen Goods
UPDATE `gameobject_template` SET `name`='Brazier', `VerifiedBuild`=25996 WHERE `entry`=248584; -- Brazier
UPDATE `gameobject_template` SET `type`=25, `displayId`=6435, `Data0`=4, `Data1`=64265, `Data2`=3, `Data3`=5, `Data4`=1628, `VerifiedBuild`=25996 WHERE `entry`=246490; -- Highmountain Salmon School
UPDATE `gameobject_template` SET `name`='Brazier', `VerifiedBuild`=25996 WHERE `entry`=248766; -- Brazier
UPDATE `gameobject_template` SET `name`='Skyhorn Totem', `VerifiedBuild`=25996 WHERE `entry`=244834; -- Skyhorn Totem
UPDATE `gameobject_template` SET `name`='Stonedark Idol', `VerifiedBuild`=25996 WHERE `entry`=245320; -- Stonedark Idol
UPDATE `gameobject_template` SET `name`='Rivermane Totem', `VerifiedBuild`=25996 WHERE `entry`=245227; -- Rivermane Totem
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=247839; -- Drum
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=247840; -- Drum
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=247841; -- Drum
UPDATE `gameobject_template` SET `name`='Bedroll', `VerifiedBuild`=25996 WHERE `entry`=244851; -- Bedroll
UPDATE `gameobject_template` SET `name`='Drogbar Salt Jar', `VerifiedBuild`=25996 WHERE `entry`=245373; -- Drogbar Salt Jar
UPDATE `gameobject_template` SET `name`='Drogbar Table', `VerifiedBuild`=25996 WHERE `entry`=245372; -- Drogbar Table
UPDATE `gameobject_template` SET `name`='Drogbar Cauldron', `VerifiedBuild`=25996 WHERE `entry`=245374; -- Drogbar Cauldron
UPDATE `gameobject_template` SET `name`='The Drog Bar', `VerifiedBuild`=25996 WHERE `entry`=245371; -- The Drog Bar
UPDATE `gameobject_template` SET `name`='Drogbar Barricade', `VerifiedBuild`=25996 WHERE `entry`=245370; -- Drogbar Barricade
UPDATE `gameobject_template` SET `type`=10, `displayId`=8395, `IconName`='questinteract', `castBarCaption`='Collecting', `size`=2, `Data0`=1691, `Data3`=1, `Data10`=207115, `Data14`=19676, `Data20`=1, `Data22`=38979, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=248422; -- Stack of Bandages
UPDATE `gameobject_template` SET `type`=3, `displayId`=14240, `size`=2, `Data0`=1634, `Data3`=1, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data15`=1, `Data18`=110, `Data19`=3, `Data25`=1824, `Data27`=1, `Data30`=68086, `RequiredLevel`=98, `VerifiedBuild`=25996 WHERE `entry`=246036; -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_template` SET `type`=10, `displayId`=31707, `Data13`=1, `Data29`=1, `VerifiedBuild`=25996 WHERE `entry`=246763; -- The Maw of Souls
UPDATE `gameobject_template` SET `type`=3, `displayId`=33131, `IconName`='questinteract', `castBarCaption`='Collecting', `size`=2, `Data0`=43, `Data14`=19676, `Data30`=65916, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=249462; -- Crate of Dragur Dust
UPDATE `gameobject_template` SET `type`=10, `displayId`=28949, `Data0`=2495, `Data3`=1000, `Data22`=38352, `VerifiedBuild`=25996 WHERE `entry`=246987; -- Barnacled Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=28949, `Data0`=2495, `Data3`=1000, `Data22`=38351, `VerifiedBuild`=25996 WHERE `entry`=246986; -- Barnacled Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=28949, `Data0`=2495, `Data3`=1000, `Data22`=38350, `VerifiedBuild`=25996 WHERE `entry`=246985; -- Barnacled Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=28949, `Data0`=2495, `Data3`=1000, `Data22`=38353, `VerifiedBuild`=25996 WHERE `entry`=246989; -- Barnacled Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=28949, `Data0`=2495, `Data3`=1000, `Data22`=38354, `VerifiedBuild`=25996 WHERE `entry`=246988; -- Barnacled Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=33622, `IconName`='questinteract', `castBarCaption`='Rubbing', `size`=3, `Data0`=93, `Data3`=1, `Data10`=219308, `Data14`=91532, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=251960; -- The Raven's Eye Tablet
UPDATE `gameobject_template` SET `type`=3, `displayId`=30825, `IconName`='questinteract', `castBarCaption`='Collecting', `size`=0.7, `Data0`=43, `Data14`=19676, `Data30`=64101, `Data31`=1, `VerifiedBuild`=25996 WHERE `entry`=246125; -- Musty Crate
UPDATE `gameobject_template` SET `name`='Collision Wall', `VerifiedBuild`=25996 WHERE `entry`=243403; -- Collision Wall
UPDATE `gameobject_template` SET `type`=10, `displayId`=31928, `Data3`=3000, `Data10`=191560, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=247041; -- Echoing Horn of the Damned
UPDATE `gameobject_template` SET `type`=10, `displayId`=36092, `IconName`='questinteract', `size`=0.8, `Data0`=2063, `Data3`=5000, `Data18`=1, `Data20`=1, `Data23`=1, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=266138; -- Containment Field
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266029; -- Felsoul Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=265521; -- Felsoul Cage
UPDATE `gameobject_template` SET `type`=10, `displayId`=34597, `IconName`='questinteract', `Data10`=229027, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=265528; -- Telemancy Beacon
UPDATE `gameobject_template` SET `type`=2, `displayId`=34597, `Data1`=20631, `VerifiedBuild`=25996 WHERE `entry`=265532; -- Telemancy Beacon
UPDATE `gameobject_template` SET `type`=10, `displayId`=39201, `IconName`='questinteract', `castBarCaption`='Examine Beacon', `Data0`=1690, `Data3`=1, `Data7`=6861, `Data9`=4, `Data10`=228989, `Data14`=124895, `Data17`=1, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=265509; -- Broken Telemancy Beacon
UPDATE `gameobject_template` SET `type`=3, `displayId`=36205, `IconName`='questinteract', `castBarCaption`='Plucking...', `size`=0.5, `Data0`=2173, `Data14`=120728, `Data17`=43140, `Data30`=68374, `VerifiedBuild`=25996 WHERE `entry`=253081; -- Fruit of the Arcan'dor

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=246036 AND `Idx`=5);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(246036, 5, 138969, 25996); -- Waterlogged Cache of Ancient Relics

UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247074 AND `Idx`=0); -- Wax Ingots
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247073 AND `Idx`=0); -- Wax Ingots
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247072 AND `Idx`=0); -- Wax Ingot
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247075 AND `Idx`=0); -- Secreted Wax Glob
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247695 AND `Idx`=0); -- Elementium Slats
UPDATE `gameobject_questitem` SET `ItemId`=138971, `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246036 AND `Idx`=4); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `ItemId`=138968, `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246036 AND `Idx`=3); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `ItemId`=138482, `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246036 AND `Idx`=2); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246036 AND `Idx`=1); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246036 AND `Idx`=0); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=249462 AND `Idx`=0); -- Crate of Dragur Dust
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246125 AND `Idx`=0); -- Musty Crate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=253081 AND `Idx`=0); -- Fruit of the Arcan'dor

DELETE FROM `page_text` WHERE `ID`=6861;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(6861, 'The Telemancy Beacon lies in several pieces. A faint buzzing sound emanates from the cracked crystal core.\n\nOculeth''s voice is audible through the noise, but the words are too indistinct to make out.\n\nWhoever destroyed this beacon intended to cut off all contact with the outside world.', 0, 0, 0, 25996); -- 6861


DELETE FROM `npc_text` WHERE `ID` IN (30843 /*30843*/, 30837 /*30837*/, 30775 /*30775*/, 30817 /*30817*/, 30960 /*30960*/, 30942 /*30942*/, 30937 /*30937*/, 30945 /*30945*/, 30920 /*30920*/, 30919 /*30919*/, 30922 /*30922*/, 30921 /*30921*/, 30866 /*30866*/, 30122 /*30122*/, 30083 /*30083*/, 30084 /*30084*/, 30085 /*30085*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(30843, 1, 0, 0, 0, 0, 0, 0, 0, 124112, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30843
(30837, 1, 0, 0, 0, 0, 0, 0, 0, 124163, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30837
(30775, 1, 0, 0, 0, 0, 0, 0, 0, 123627, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30775
(30817, 1, 0, 0, 0, 0, 0, 0, 0, 123908, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30817
(30960, 1, 0, 0, 0, 0, 0, 0, 0, 124831, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30960
(30942, 1, 0, 0, 0, 0, 0, 0, 0, 124772, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30942
(30937, 1, 0, 0, 0, 0, 0, 0, 0, 124739, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30937
(30945, 1, 0, 0, 0, 0, 0, 0, 0, 124777, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30945
(30920, 1, 0, 0, 0, 0, 0, 0, 0, 124729, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30920
(30919, 1, 0, 0, 0, 0, 0, 0, 0, 124727, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30919
(30922, 1, 0, 0, 0, 0, 0, 0, 0, 124771, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30922
(30921, 1, 0, 0, 0, 0, 0, 0, 0, 124737, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30921
(30866, 1, 1, 1, 0, 0, 0, 0, 0, 124285, 124286, 124287, 0, 0, 0, 0, 0, 25996), -- 30866
(30122, 1, 0, 0, 0, 0, 0, 0, 0, 120808, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30122
(30083, 1, 0, 0, 0, 0, 0, 0, 0, 120729, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30083
(30084, 1, 0, 0, 0, 0, 0, 0, 0, 120730, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30084
(30085, 1, 0, 0, 0, 0, 0, 0, 0, 120731, 0, 0, 0, 0, 0, 0, 0, 25996); -- 30085

UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30210; -- 30210
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28396; -- 28396

