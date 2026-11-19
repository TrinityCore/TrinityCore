-- 
DELETE FROM `conversation_line_template` WHERE `Id` IN (32915, 32916, 32917, 32918, 32919, 32926);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(32915, 0, 0, 0, 0, 40120),
(32916, 9878, 0, 0, 0, 40120),
(32917, 22389, 0, 0, 0, 40120),
(32918, 33855, 0, 0, 0, 40120),
(32919, 43842, 0, 0, 0, 40120),
(32926, 55409, 0, 1, 1, 40120);

DELETE FROM `conversation_template` WHERE `Id`=13254;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES
(13254, 32915, 55409, 0, 'conversation_allied_race_dk_defender_of_azeroth', 40120);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=13254 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`,  `Idx`, `VerifiedBuild`) VALUES
-- (13254, 0, 0, 1, 40120), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(13254, 74042, 1050053, 0, 40120); -- Full: 0x203AF51F209DEB400009E0000059DA73 Creature/0 R3773/S2528 Map: 2297 (Icecrown Citadel (8.3)) Entry: 161709 (Highlord Darion Mograine) Low: 5888627
