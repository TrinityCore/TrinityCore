DELETE FROM `areatrigger_template` WHERE `Id`=17439;
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(17439, 1, 0, 16, 2, 2, 0, 0, 0, 0, 38134);

UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=18267;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=18267;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;

REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(13792, 18267, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 38134), -- SpellId : 273840
(12778, 17439, 0, 0, 0, 0, 0, 0, 0, 10000, 10000, 38134); -- SpellId : 264184

DELETE FROM `conversation_actors` WHERE (`ConversationId`=6833 AND `Idx` IN (1,0)) OR (`ConversationId`=6813 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(6833, 62686, 1, 38134), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(6833, 62686, 0, 38134),
(6813, 62686, 0, 38134);

UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5800 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5800 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5800 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6460 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6460 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6460 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6460 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59483, `VerifiedBuild`=38134 WHERE (`ConversationId`=5057 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59483, `VerifiedBuild`=38134 WHERE (`ConversationId`=5057 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6436 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6436 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5031 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6329 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6437 AND `Idx`=1);
UPDATE `conversation_actors` SET `ConversationActorId`=58423, `VerifiedBuild`=38134 WHERE (`ConversationId`=6437 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5731 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5883 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5883 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5642 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5642 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5642 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5919 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5030 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5030 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5030 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5030 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5030 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6336 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6336 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6336 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5730 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5730 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5409 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6466 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5643 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=60707, `VerifiedBuild`=38134 WHERE (`ConversationId`=5999 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59483, `VerifiedBuild`=38134 WHERE (`ConversationId`=5061 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=60707, `VerifiedBuild`=38134 WHERE (`ConversationId`=5999 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59483, `VerifiedBuild`=38134 WHERE (`ConversationId`=5169 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6335 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6335 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5117 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5732 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6446 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6446 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5029 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5905 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5905 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6618 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6454 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6454 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6454 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59483, `VerifiedBuild`=38134 WHERE (`ConversationId`=5325 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5325 AND `Idx`=1);
UPDATE `conversation_actors` SET `ConversationActorId`=59483, `VerifiedBuild`=38134 WHERE (`ConversationId`=5325 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5119 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5119 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6406 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5902 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5902 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5902 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=60707, `VerifiedBuild`=38134 WHERE (`ConversationId`=5999 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6438 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6438 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6438 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (15616, 15615, 15553);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(15616, 5205, 0, 1, 1, 38134),
(15615, 0, 1062, 0, 0, 38134),
(15553, 0, 1062, 0, 0, 38134);

UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13111;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14571;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13038;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14631;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14630;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14629;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14628;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11897;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11287;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14538;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14537;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13787;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13786;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13785;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13784;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13783;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11230;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14218;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14540;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14539;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12865;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13173;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13172;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12615;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12613;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12612;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13257;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13255;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13254;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13256;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13252;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13253;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13251;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15094;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11229;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15093;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15092;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11228;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14230;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14229;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14228;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12864;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12863;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12121;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14640;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12616;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=13392;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13787;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13786;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13785;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13784;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13783;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11898;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=13392;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11561;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14227;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14226;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11458;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12866;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14573;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14572;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11226;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13233;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13232;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15050;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14609;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14608;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14607;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11896;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11895;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11894;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11462;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=11463;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14439;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13229;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13228;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13227;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=13392;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14543;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14542;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14541;

DELETE FROM `conversation_template` WHERE `Id` IN (6833, 6813);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(6833, 15615, 5205, 0, 38134),
(6813, 15553, 15285, 0, 38134);

UPDATE `conversation_template` SET `LastLineEndTime`=6100, `VerifiedBuild`=38134 WHERE `Id`=5732;
UPDATE `conversation_template` SET `LastLineEndTime`=4100, `VerifiedBuild`=38134 WHERE `Id`=5409;
UPDATE `conversation_template` SET `LastLineEndTime`=5150, `VerifiedBuild`=38134 WHERE `Id`=5731;
UPDATE `conversation_template` SET `LastLineEndTime`=9050, `VerifiedBuild`=38134 WHERE `Id`=5730;
UPDATE `conversation_template` SET `LastLineEndTime`=16837, `VerifiedBuild`=38134 WHERE `Id`=5057;
UPDATE `conversation_template` SET `LastLineEndTime`=9115, `VerifiedBuild`=38134 WHERE `Id`=5169;
UPDATE `conversation_template` SET `LastLineEndTime`=6965, `VerifiedBuild`=38134 WHERE `Id`=5061;
UPDATE `conversation_template` SET `LastLineEndTime`=18761, `VerifiedBuild`=38134 WHERE `Id`=5325;
UPDATE `conversation_template` SET `LastLineEndTime`=29600, `VerifiedBuild`=38134 WHERE `Id`=6190;
UPDATE `conversation_template` SET `LastLineEndTime`=29600, `VerifiedBuild`=38134 WHERE `Id`=6190;
UPDATE `conversation_template` SET `LastLineEndTime`=13850, `VerifiedBuild`=38134 WHERE `Id`=5902;
UPDATE `conversation_template` SET `LastLineEndTime`=12650, `VerifiedBuild`=38134 WHERE `Id`=5905;
UPDATE `conversation_template` SET `LastLineEndTime`=12400, `VerifiedBuild`=38134 WHERE `Id`=5883;
UPDATE `conversation_template` SET `LastLineEndTime`=33600, `VerifiedBuild`=38134 WHERE `Id`=5919;
UPDATE `conversation_template` SET `LastLineEndTime`=43018, `VerifiedBuild`=38134 WHERE `Id`=5030;
UPDATE `conversation_template` SET `LastLineEndTime`=9901, `VerifiedBuild`=38134 WHERE `Id`=5031;
UPDATE `conversation_template` SET `LastLineEndTime`=9708, `VerifiedBuild`=38134 WHERE `Id`=5029;
UPDATE `conversation_template` SET `LastLineEndTime`=10087, `VerifiedBuild`=38134 WHERE `Id`=5643;
UPDATE `conversation_template` SET `LastLineEndTime`=26190, `VerifiedBuild`=38134 WHERE `Id`=5642;
UPDATE `conversation_template` SET `LastLineEndTime`=20573, `VerifiedBuild`=38134 WHERE `Id`=6454;
UPDATE `conversation_template` SET `LastLineEndTime`=6800, `VerifiedBuild`=38134 WHERE `Id`=6618;
UPDATE `conversation_template` SET `LastLineEndTime`=25166, `VerifiedBuild`=38134 WHERE `Id`=6438;
UPDATE `conversation_template` SET `LastLineEndTime`=9448, `VerifiedBuild`=38134 WHERE `Id`=6437;
UPDATE `conversation_template` SET `LastLineEndTime`=2153, `VerifiedBuild`=38134 WHERE `Id`=6436;
UPDATE `conversation_template` SET `LastLineEndTime`=31702, `VerifiedBuild`=38134 WHERE `Id`=6336;
UPDATE `conversation_template` SET `LastLineEndTime`=17755, `VerifiedBuild`=38134 WHERE `Id`=6335;
UPDATE `conversation_template` SET `LastLineEndTime`=11133, `VerifiedBuild`=38134 WHERE `Id`=6329;
UPDATE `conversation_template` SET `LastLineEndTime`=17992, `VerifiedBuild`=38134 WHERE `Id`=5119;
UPDATE `conversation_template` SET `LastLineEndTime`=22200, `VerifiedBuild`=38134 WHERE `Id`=6460;
UPDATE `conversation_template` SET `LastLineEndTime`=3200, `VerifiedBuild`=38134 WHERE `Id`=6466;
UPDATE `conversation_template` SET `LastLineEndTime`=18178, `VerifiedBuild`=38134 WHERE `Id`=6446;
UPDATE `conversation_template` SET `LastLineEndTime`=21629, `VerifiedBuild`=38134 WHERE `Id`=5800;
UPDATE `conversation_template` SET `LastLineEndTime`=10709, `VerifiedBuild`=38134 WHERE `Id`=5117;
UPDATE `conversation_template` SET `LastLineEndTime`=8449, `VerifiedBuild`=38134 WHERE `Id`=6406;
UPDATE `conversation_template` SET `LastLineEndTime`=5650, `VerifiedBuild`=38134 WHERE `Id`=5999;
UPDATE `conversation_template` SET `LastLineEndTime`=5650, `VerifiedBuild`=38134 WHERE `Id`=5999;
UPDATE `conversation_template` SET `LastLineEndTime`=5650, `VerifiedBuild`=38134 WHERE `Id`=5999;


UPDATE `gameobject_template_addon` SET `flags`=2113542 WHERE `entry`=273484; -- Repaired Phylactery
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=277715; -- Cursed Nazmani Chest
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=291238; -- Bwonsamdi's Tears
UPDATE `gameobject_template_addon` SET `flags`=2113542 WHERE `entry`=278340; -- Ancient Phylactery
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=277885; -- Wunja's Trove
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=291241; -- Gnarl Root
UPDATE `gameobject_template_addon` SET `flags`=0, `WorldEffectID`=11674 WHERE `entry`=325471; -- Boiling Cauldron
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=279260; -- "Cleverly" Disguised Chest
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8876 WHERE `entry`=281385; -- Mysterious Trashpile
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=282723; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=279299; -- Venomous Seal

DELETE FROM `quest_offer_reward` WHERE `ID`=50381;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50381, 0, 0, 0, 0, 0, 0, 0, 0, 'Haha! Well done, richmon. You bruised Tik\'su\'s pride and his backside. He gonna be hurtin\' for a while. You have earned my favor.', 38134); -- -Unknown-

UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48478; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47241; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47241; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48473; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48468; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48590; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48584; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48578; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48577; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48576; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48573; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48574; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48669; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47188; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47263; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47262; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47262; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47130; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47264; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47105; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48535; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47103; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47103; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47512; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49663; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47310; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47310; -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47310 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47310 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47310 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(47244, 0, 2, 32, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1322864, 0, 38134), -- -Unknown-
(47244, 0, 1, 0, 290562, 122204, 1642, 863, 0, 0, 0, 0, 0, 1323924, 0, 38134), -- -Unknown-
(47244, 0, 0, -1, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1344153, 0, 38134), -- -Unknown-
(47310, 0, 2, 32, 0, 0, 1642, 862, 0, 0, 0, 0, 0, 1312598, 0, 38134), -- -Unknown-
(47310, 0, 1, 0, 290844, 123677, 1642, 862, 0, 0, 0, 0, 0, 1337080, 0, 38134), -- -Unknown-
(47310, 0, 0, -1, 0, 0, 1642, 862, 0, 0, 0, 0, 0, 1312598, 0, 38134), -- -Unknown-
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48578 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48578 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48578 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48669 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48669 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48669 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47188 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47188 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47188 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47262 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47262 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47262 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47105 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47105 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47105 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47103 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47103 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47512 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=47244 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47244 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47244 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47310 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47310 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47310 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(47244, 2, 0, 1639, 1523, 26, 38134), -- -Unknown-
(47244, 1, 0, 1777, 1420, 20, 38134), -- -Unknown-
(47244, 0, 0, 1990, 1373, 16, 38134), -- -Unknown-
(47310, 2, 0, -1015, 57, 279, 38134), -- -Unknown-
(47310, 1, 0, -992, -64, 251, 38134), -- -Unknown-
(47310, 0, 0, -1015, 57, 279, 38134), -- -Unknown-
(31459, 0, 0, 3044, 1251, 655, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48478 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48473 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48468 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48588 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48590 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48584 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48578 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48578 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48578 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48577 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48576 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48574 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48573 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48669 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48669 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48669 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47241 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47188 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47188 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47188 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47263 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47262 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47262 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47262 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47130 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47264 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47105 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47105 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47105 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48535 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47103 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47103 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47512 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50381 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49663 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID`=50381;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(50381, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48479; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47244; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48478; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48473; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48468; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48590; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48584; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48578; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48577; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48576; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48574; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48573; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48669; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48669; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47241; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51089; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47188; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47263; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47262; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47130; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47264; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47105; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49768; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48535; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47103; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47512; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=50381;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(50381, 0, 0, 0, 0, 'You had a chat with Tik\'su about his hat yet, richmon?', 38134); -- -Unknown-

UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`ID`=262659 AND `EffectIndex`=3) OR (`ID`=262574 AND `EffectIndex`=1);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(262659, 3, 1642, -1267.3199462890625, 466.920013427734375, 224.410003662109375, 38134), -- Spell: 262659 (The Great Hat Robbery Wrap Up) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(262574, 1, 1642, -1267.3199462890625, 466.920013427734375, 224.410003662109375, 38134); -- Spell: 262574 (Curse of Jani) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `PositionX`=1445.2099609375, `PositionY`=-4499.56005859375, `PositionZ`=18.30999946594238281, `VerifiedBuild`=38134 WHERE (`ID`=3567 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (141801 /*141801 (Little Blue)*/, 141802 /*141802 (Scars)*/, 141803 /*141803 (Delta)*/, 136395 /*136395 (Plains Brutosaur)*/, 137654 /*137654 (Faceless Corruptor) - Azerite Corruption*/, 137653 /*137653 (Faceless Destroyer)*/, 152126 /*152126 (Expedition Guard)*/, 135399 /*135399*/, 135257 /*135257*/, 131695 /*131695*/, 152019 /*152019*/, 147641 /*147641*/, 147642 /*147642*/, 134495 /*134495 (Congealing Slime)*/, 134047 /*134047 (Enthralled Saurid)*/, 134046 /*134046 (Enthralled Saurid)*/, 136009 /*136009 (7th Legion Marine)*/, 136152 /*136152 (7th Legion Scout)*/, 133500 /*133500 (Eye of Yazma)*/, 133615 /*133615 (Caravan Brutosaur)*/, 133614 /*133614 (Tik'su) - Ride Vehicle Hardcoded, Generic Quest Invisibility 1, Troll Merchant's Hat*/, 133612 /*133612 (Jani)*/, 150412 /*150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura, Inert Golem Stun*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(141801, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141801 (Little Blue)
(141802, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141802 (Scars)
(141803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141803 (Delta)
(136395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136395 (Plains Brutosaur)
(137654, 0, 0, 0, 1, 0, 0, 0, 0, '267921'), -- 137654 (Faceless Corruptor) - Azerite Corruption
(137653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137653 (Faceless Destroyer)
(152126, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 152126 (Expedition Guard)
(135399, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 135399
(135257, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 135257
(131695, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131695
(152019, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 152019
(147641, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 147641
(147642, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147642
(134495, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 134495 (Congealing Slime)
(134047, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 134047 (Enthralled Saurid)
(134046, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 134046 (Enthralled Saurid)
(136009, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 136009 (7th Legion Marine)
(136152, 0, 0, 0, 258, 0, 0, 0, 0, ''), -- 136152 (7th Legion Scout)
(133500, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133500 (Eye of Yazma)
(133615, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133615 (Caravan Brutosaur)
(133614, 0, 0, 65536, 1, 0, 0, 0, 0, '46598 49414 262567'), -- 133614 (Tik'su) - Ride Vehicle Hardcoded, Generic Quest Invisibility 1, Troll Merchant's Hat
(133612, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133612 (Jani)
(150412, 0, 0, 0, 1, 0, 15263, 0, 0, '291587 282764'); -- 150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura; Inert Golem Stun

UPDATE `creature_template_addon` SET `aiAnimKit`=14306 WHERE `entry`=135836; -- 135836 (Vision of a Heretical Nazmani)
UPDATE `creature_template_addon` SET `aiAnimKit`=14301 WHERE `entry`=129574; -- 129574 (Vision of Kel'vax Deathwalker)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122636; -- 122636 (Blood Bonepicker)
UPDATE `creature_template_addon` SET `aiAnimKit`=14299 WHERE `entry`=129567; -- 129567 (Vision of a Heretical Nazmani)
UPDATE `creature_template_addon` SET `aiAnimKit`=14296 WHERE `entry`=135835; -- 135835 (Vision of a Heretical Nazmani)
UPDATE `creature_template_addon` SET `aiAnimKit`=14297 WHERE `entry`=129565; -- 129565 (Vision of a Bwonsamdi Priest)
UPDATE `creature_template_addon` SET `aiAnimKit`=1551 WHERE `entry`=129569; -- 129569 (Vision of an Ancient Nazmani Body)
UPDATE `creature_template_addon` SET `aiAnimKit`=14297 WHERE `entry`=129563; -- 129563 (Vision of Kol'jun Deathwalker)
UPDATE `creature_template_addon` SET `aiAnimKit`=14296 WHERE `entry`=129568; -- 129568 (Vision of a Heretical Nazmani)
UPDATE `creature_template_addon` SET `aiAnimKit`=14308 WHERE `entry`=129564; -- 129564 (Vision of Shinga Deathwalker)
UPDATE `creature_template_addon` SET `aiAnimKit`=14294 WHERE `entry`=129555; -- 129555 (Vision of a Bwonsamdi Priest)
UPDATE `creature_template_addon` SET `aiAnimKit`=1551 WHERE `entry`=129562; -- 129562 (Vision of Kel'vax Deathwalker)
UPDATE `creature_template_addon` SET `aiAnimKit`=14293 WHERE `entry`=129557; -- 129557 (Vision of an Ancient Nazmani)
UPDATE `creature_template_addon` SET `aiAnimKit`=6291 WHERE `entry`=126090; -- 126090 (Defiled Worshiper)
UPDATE `creature_template_addon` SET `aiAnimKit`=9959, `auras`='254493' WHERE `entry`=126091; -- 126091 (Defiled Embalmer)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=126133; -- 126133 (Swamp Scavenger)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122102; -- 122102 (Hanzabu)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=122103; -- 122103 (Blood Scavenger)
UPDATE `creature_template_addon` SET `aiAnimKit`=13792 WHERE `entry`=127246; -- 127246 (Empowered Totem)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='12787 145363' WHERE `entry`=127267; -- 127267 (Sickly Snapjaw)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=131872; -- 131872 (Sur'jan)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=124404; -- 124404 (Dreadtick Stalker)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=124400; -- 124400 (Dreadtick Stalker)
UPDATE `creature_template_addon` SET `aiAnimKit`=16510 WHERE `entry`=143898; -- 143898 (Makatau)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=125253; -- 125253
UPDATE `creature_template_addon` SET `auras`='12787' WHERE `entry`=126723; -- 126723 (Primal Snapjaw)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=133076; -- 133076 (Nazmani Headhunter)
UPDATE `creature_template_addon` SET `auras`='256313' WHERE `entry`=133122; -- 133122 (Nazmani Warrior)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=130227; -- 130227 (Rotfeeder)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121301; -- 121301 (Zandalari Soldier)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=123711; -- 123711 (Blood Hunter)
UPDATE `creature_template_addon` SET `aiAnimKit`=2189 WHERE `entry`=122276; -- 122276 (Taloc)
UPDATE `creature_template_addon` SET `auras`='260422' WHERE `entry`=124084; -- 124084
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=120593; -- 120593
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='140387' WHERE `entry`=130876; -- 130876
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=137392; -- 137392
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=131598; -- 131598
UPDATE `creature_template_addon` SET `aiAnimKit`=10381 WHERE `entry`=121696; -- 121696 (Torcalin Ironhide)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131774; -- 131774
UPDATE `creature_template_addon` SET `aiAnimKit`=14635 WHERE `entry`=131659; -- 131659
UPDATE `creature_template_addon` SET `auras`='256130' WHERE `entry`=129300; -- 129300
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131746; -- 131746
UPDATE `creature_template_addon` SET `auras`='243129' WHERE `entry`=138274; -- 138274
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=126623; -- 126623
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=129329; -- 129329
UPDATE `creature_template_addon` SET `mount`=47238 WHERE `entry`=131007; -- 131007
UPDATE `creature_template_addon` SET `aiAnimKit`=14580 WHERE `entry`=131164; -- 131164
UPDATE `creature_template_addon` SET `auras`='281448' WHERE `entry`=122701; -- 122701
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=131216; -- 131216 (Forsaken Battleguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=131840; -- 131840
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=132686; -- 132686
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='270114' WHERE `entry`=132394; -- 132394
UPDATE `creature_template_addon` SET `mount`=48100 WHERE `entry`=130995; -- 130995
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132687; -- 132687
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142567; -- 142567
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131834; -- 131834
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132689; -- 132689
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132690; -- 132690
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131809; -- 131809
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=132097; -- 132097
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=132308; -- 132308
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=132085; -- 132085 (Lofty Libram)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=132082; -- 132082
UPDATE `creature_template_addon` SET `auras`='196285 145953' WHERE `entry`=126725; -- 126725 (Elder Diemetradon)
UPDATE `creature_template_addon` SET `auras`='120703' WHERE `entry`=123672; -- 123672 (Direhorn Juvenile)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='196285 130966' WHERE `entry`=126726; -- 126726 (Young Diemetradon)
UPDATE `creature_template_addon` SET `auras`='151597' WHERE `entry`=131560; -- 131560 (Feral Ravasaur)
UPDATE `creature_template_addon` SET `auras`='250946' WHERE `entry`=125414; -- 125414 (Spiny Gekkota)
UPDATE `creature_template_addon` SET `aiAnimKit`=13307 WHERE `entry`=126653; -- 126653 (Hungry Saurid)
UPDATE `creature_template_addon` SET `auras`='263057' WHERE `entry`=133910; -- 133910 (Lil' Stompy)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=126562; -- 126562 (Irritable Diemetradon)
UPDATE `creature_template_addon` SET `mount`=0, `auras`='297109' WHERE `entry`=125784; -- 125784 (Beastcaller Guardian)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=125783; -- 125783 (Apprentice Beastcaller)


UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=129545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131533 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135836 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133531 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122204 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135835 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129569 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129563 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129557 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126113 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126150 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128934 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126080 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126142 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126132 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126091 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130481 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126079 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126204 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129576 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135557 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122102 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122103 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141801 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141802 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141799 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122094 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127350 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127348 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127351 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127247 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127385 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127294 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129536 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127298 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128943 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127255 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127278 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127279 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127276 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=137654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=137653 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124404 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124399 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=137656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=143898 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=141860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=141858 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130446 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=141728 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131855 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126749 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127001 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128343 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126703 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133829 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133831 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123809 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127132 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=152126 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126713 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135758 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121638 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=121639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=140513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125834 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121873 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=121828 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121289 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=131146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=139816 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=139709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=139829 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133020 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133063 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=132985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129461 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129730 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121241 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127779 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127770 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121437 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130844 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120613 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120607 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121301 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120587 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130780 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120905 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130796 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127474 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121863 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122934 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=120804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143055 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130794 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127475 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126551 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130829 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122276 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123736 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126628 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126635 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135399 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135257 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126590 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130876 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=152019 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131598 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121810 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136092 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136079 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=136074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142101 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143523 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143522 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131753 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130712 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134018 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130749 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130718 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130577 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130447 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130575 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131765 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126330 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131769 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131767 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=130988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=130990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=130987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131791 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131781 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131783 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133248 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131741 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141957 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129595 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141628 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131746 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128150 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141617 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126304 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126329 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126618 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138274 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126623 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129329 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126560 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131164 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131162 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126331 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127665 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=124040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141956 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131745 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=140868 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141954 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126586 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=140869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137237 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131811 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=122231 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=126549 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142503 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137818 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132959 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132686 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122699 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=129479 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122698 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132983 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132984 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141936 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122700 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=130995 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=132711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132707 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=132714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131835 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131836 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133062 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=144085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133231 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131827 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133065 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132097 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=34278 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131403 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=68659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132301 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=147641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=147642 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=127123 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=77221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132103 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140445 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=54227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=33810 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=53225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132106 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=33227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131734 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=81431 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=196, `VerifiedBuild`=38134 WHERE (`Entry`=93432 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=140411 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=85517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133237 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=48609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=115152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132110 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=15699 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=14629 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=132089 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=132085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132109 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132111 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=73668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=66950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144256 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144258 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=132077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=64899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=71942 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=82464 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144254 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144257 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126725 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=133420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126722 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123672 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130922 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134495 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134046 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=136009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133500 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133615 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133612 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126726 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131560 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=150412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=125414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126653 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122059 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130589 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123062 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122402 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=121706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135249 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122399 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=123677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=123060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140305 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122447 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=125784 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122445 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=125417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=122400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125783 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=24889;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75961;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19986;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80023;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78801;
UPDATE `creature_model_info` SET `BoundingRadius`=0.898638069629669189, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=82986;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=76764;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75865;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45494;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=78779;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80726;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79979;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80713;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80711;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80712;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80718;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80729;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80714;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84662;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80727;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80710;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80715;
UPDATE `creature_model_info` SET `BoundingRadius`=0.175650030374526977, `VerifiedBuild`=38134 WHERE `DisplayID`=84856;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80717;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82573;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.532049536705017089, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=82571;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79978;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79975;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79980;
UPDATE `creature_model_info` SET `BoundingRadius`=1.425259590148925781, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79977;
UPDATE `creature_model_info` SET `BoundingRadius`=0.85839998722076416, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78737;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78719;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75889;
UPDATE `creature_model_info` SET `BoundingRadius`=1.903635621070861816, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78750;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78723;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=76727;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=9904;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78693;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78692;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78727;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78726;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77485;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76641;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77483;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=34418;
UPDATE `creature_model_info` SET `BoundingRadius`=1.110454082489013671, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78131;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82919;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79123;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79334;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79335;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80042;
UPDATE `creature_model_info` SET `BoundingRadius`=1.072999954223632812, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=33736;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79333;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79367;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80014;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=80459;
UPDATE `creature_model_info` SET `BoundingRadius`=1.522709608078002929, `CombatReach`=3.375, `VerifiedBuild`=38134 WHERE `DisplayID`=80047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=34417;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79340;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32814;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80057;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80061;
UPDATE `creature_model_info` SET `BoundingRadius`=2.071114301681518554, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=55376;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80058;
UPDATE `creature_model_info` SET `BoundingRadius`=1.832476615905761718, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79585;
UPDATE `creature_model_info` SET `BoundingRadius`=0.517778575420379638, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=65547;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79361;
UPDATE `creature_model_info` SET `BoundingRadius`=5.709589958190917968, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81973;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=2956;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=47934;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=82107;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985729217529296, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=28002;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985729217529296, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=85427;
UPDATE `creature_model_info` SET `BoundingRadius`=1.41093301773071289, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=76736;
UPDATE `creature_model_info` SET `BoundingRadius`=1.25, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=74268;
UPDATE `creature_model_info` SET `BoundingRadius`=1.627999663352966308, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=76734;
UPDATE `creature_model_info` SET `BoundingRadius`=8.290376663208007812, `CombatReach`=7, `VerifiedBuild`=38134 WHERE `DisplayID`=85567;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=87486;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=87491;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87431;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82097;
UPDATE `creature_model_info` SET `BoundingRadius`=1.41093301773071289, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=78021;
UPDATE `creature_model_info` SET `BoundingRadius`=1.832476615905761718, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79591;
UPDATE `creature_model_info` SET `BoundingRadius`=6.022189617156982421, `CombatReach`=10, `VerifiedBuild`=38134 WHERE `DisplayID`=76656;
UPDATE `creature_model_info` SET `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=47234;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77489;
UPDATE `creature_model_info` SET `BoundingRadius`=9.121919631958007812, `CombatReach`=9, `VerifiedBuild`=38134 WHERE `DisplayID`=84196;
UPDATE `creature_model_info` SET `BoundingRadius`=0.636844754219055175, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47586;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79061;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84377;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47992;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84381;
UPDATE `creature_model_info` SET `BoundingRadius`=0.293149083852767944, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=83640;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=81218;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61083;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59831;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60715;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61081;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=60001;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84261;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.240000009536743164, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=47989;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47990;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75968;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=79274;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78936;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=75850;
UPDATE `creature_model_info` SET `BoundingRadius`=1.938240408897399902, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=33450;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33451;
UPDATE `creature_model_info` SET `BoundingRadius`=0.373770296573638916, `CombatReach`=0.1875, `VerifiedBuild`=38134 WHERE `DisplayID`=45908;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77503;
UPDATE `creature_model_info` SET `BoundingRadius`=0.373770296573638916, `CombatReach`=0.1875, `VerifiedBuild`=38134 WHERE `DisplayID`=77652;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=86053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.782324552536010742, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=88147;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75892;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82872;
UPDATE `creature_model_info` SET `BoundingRadius`=9.121919631958007812, `CombatReach`=9, `VerifiedBuild`=38134 WHERE `DisplayID`=79247;
UPDATE `creature_model_info` SET `BoundingRadius`=0.924024164676666259, `CombatReach`=1.980000019073486328, `VerifiedBuild`=38134 WHERE `DisplayID`=82871;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78718;
UPDATE `creature_model_info` SET `BoundingRadius`=0.622134089469909667, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=78717;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=76730;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82687;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80611;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81377;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78650;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23856;
UPDATE `creature_model_info` SET `BoundingRadius`=1.260033011436462402, `CombatReach`=2.70000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=75882;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036890149116516113, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=79502;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036890149116516113, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=79500;
UPDATE `creature_model_info` SET `BoundingRadius`=5.47315216064453125, `CombatReach`=5.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=78169;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036890149116516113, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=79499;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036890149116516113, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=79501;
UPDATE `creature_model_info` SET `BoundingRadius`=0.035000000149011611, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=47512;
UPDATE `creature_model_info` SET `BoundingRadius`=2.441002368927001953, `CombatReach`=5.399999618530273437, `VerifiedBuild`=38134 WHERE `DisplayID`=84798;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80796;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80793;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82832;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80795;
UPDATE `creature_model_info` SET `BoundingRadius`=0.397799968719482421, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=76390;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38732;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58804;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80419;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76728;
UPDATE `creature_model_info` SET `BoundingRadius`=0.410187005996704101, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=58745;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79328;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75970;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81380;
UPDATE `creature_model_info` SET `BoundingRadius`=1.578887343406677246, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=83649;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342625141143798828, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54692;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75967;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75969;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81055;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81058;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79834;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81427;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81428;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78419;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=60235;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=82696;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85386;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=0.625, `VerifiedBuild`=38134 WHERE `DisplayID`=44656;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75864;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84580;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84569;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84793;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84561;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=37190;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381700009107589721, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=87576;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76568;
UPDATE `creature_model_info` SET `BoundingRadius`=1.937266349792480468, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=32649;
UPDATE `creature_model_info` SET `BoundingRadius`=0.564377963542938232, `CombatReach`=1.5 WHERE `DisplayID`=86800;
UPDATE `creature_model_info` SET `BoundingRadius`=0.564377963542938232, `CombatReach`=1.5 WHERE `DisplayID`=86801;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77687;
UPDATE `creature_model_info` SET `BoundingRadius`=4.036835670471191406, `CombatReach`=3 WHERE `DisplayID`=47620;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82684;
UPDATE `creature_model_info` SET `BoundingRadius`=1.018429756164550781 WHERE `DisplayID`=88157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.167755126953125, `CombatReach`=0.559183716773986816, `VerifiedBuild`=38134 WHERE `DisplayID`=58930;
UPDATE `creature_model_info` SET `BoundingRadius`=0.08749999850988388, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=14657;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2504291832447052, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=47731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2504291832447052, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=48055;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2504291832447052, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=48057;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58978;
UPDATE `creature_model_info` SET `BoundingRadius`=4.550885200500488281, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=79075;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68139;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47935;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76567;
UPDATE `creature_model_info` SET `BoundingRadius`=2.392235517501831054, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76481;
UPDATE `creature_model_info` SET `BoundingRadius`=6.851508140563964843, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=81484;
UPDATE `creature_model_info` SET `BoundingRadius`=3.033923625946044921, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=13210;
UPDATE `creature_model_info` SET `BoundingRadius`=4.143049240112304687, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=4065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85767;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84617;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83043;
UPDATE `creature_model_info` SET `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=46565;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79085;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `VerifiedBuild`=38134 WHERE `DisplayID`=91019;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216573551297187805, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=36599;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81897;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121 WHERE `DisplayID`=78161;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47233;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=47933;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=31482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=79535;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=31288;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=74881;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=79534;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=76502;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16357;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01109480857849121, `CombatReach`=5 WHERE `DisplayID`=76658;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79533;
UPDATE `creature_model_info` SET `BoundingRadius`=2.378643512725830078, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=83627;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79526;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79554;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83182;
UPDATE `creature_model_info` SET `BoundingRadius`=4.516642093658447265, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76660;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=9, `VerifiedBuild`=38134 WHERE `DisplayID`=47236;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79528;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19283;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79542;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79529;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79527;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83181;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79581;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79582;
UPDATE `creature_model_info` SET `BoundingRadius`=0.262499988079071044, `CombatReach`=0.375, `VerifiedBuild`=38134 WHERE `DisplayID`=4268;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79553;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79532;

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (122102,152126,133077,127770,121744,126560,136009,136152));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(122102, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(152126, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Expedition Guard
(133077, 1, 128193, 0, 0, 128193, 0, 0, 0, 0, 0), -- Nazmani War Slave
(127770, 1, 128193, 0, 0, 128193, 0, 0, 0, 0, 0), -- Blood Troll Warrior
(121744, 1, 128193, 0, 0, 128193, 0, 0, 0, 0, 0), -- Blood Troll
(126560, 1, 128100, 0, 0, 0, 0, 0, 0, 0, 0), -- Wardruid Loti
(136009, 1, 1493, 0, 0, 143, 0, 0, 2552, 0, 0), -- 7th Legion Marine
(136152, 1, 0, 0, 0, 0, 0, 0, 37249, 0, 0); -- 7th Legion Scout

UPDATE `creature_equip_template` SET `ItemID1`=106945, `ItemID3`=0 WHERE (`CreatureID`=129545 AND `ID`=1); -- Bwonsamdi
UPDATE `creature_equip_template` SET `ItemID1`=116485 WHERE (`CreatureID`=133122 AND `ID`=3); -- Nazmani Warrior
UPDATE `creature_equip_template` SET `ItemID1`=108286 WHERE (`CreatureID`=133122 AND `ID`=2); -- Nazmani Warrior
UPDATE `creature_equip_template` SET `ItemID1`=114962 WHERE (`CreatureID`=133122 AND `ID`=1); -- Nazmani Warrior

DELETE FROM `gossip_menu` WHERE (`MenuId`=22261 AND `TextId`=34123) OR (`MenuId`=22210 AND `TextId`=34029);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(22261, 34123, 38134), -- 134049
(22210, 34029, 38134); -- 133612 (Jani)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21425 AND `TextId`=32627); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21425 AND `TextId`=32627); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21425 AND `TextId`=32627); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21828 AND `TextId`=33358); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `TextId`=32733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `TextId`=32137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `TextId`=32137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `TextId`=32137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `TextId`=32137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21814 AND `TextId`=33343); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21132 AND `TextId`=32033); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21132 AND `TextId`=32033); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22445 AND `TextId`=34568); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23237 AND `TextId`=35990); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21178 AND `TextId`=32124); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=22261 AND `OptionIndex`=0) OR (`MenuId`=22210 AND `OptionIndex` IN (0,1));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(22261, 0, 0, 'Investigate the egg.', 147884, 38134),
(22210, 0, 0, 'Release me.', 137226, 38134),
(22210, 1, 0, 'I need a new disguise.', 156606, 38134);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136807, `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136807, `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136807, `VerifiedBuild`=38134 WHERE (`MenuId`=21487 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=135272, `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=135272, `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=135272, `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=135272, `VerifiedBuild`=38134 WHERE (`MenuId`=21185 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140967, `VerifiedBuild`=38134 WHERE (`MenuId`=21814 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=148197, `VerifiedBuild`=38134 WHERE (`MenuId`=22290 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22445 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21178 AND `OptionIndex`=0);




UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126234; -- Kel'vax's Phylactery
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129545; -- Bwonsamdi
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130636; -- Crimsontail Moth
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131533; -- Troll Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135836; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129574; -- Vision of Kel'vax Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133531; -- Xu'ba
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122204; -- Blood Witch Najima
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122636; -- Blood Bonepicker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122987; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126187; -- Corpse Bringer Yal'kar
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129567; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135835; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129565; -- Vision of a Bwonsamdi Priest
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129569; -- Vision of an Ancient Nazmani Body
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129563; -- Vision of Kol'jun Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129568; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129564; -- Vision of Shinga Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129555; -- Vision of a Bwonsamdi Priest
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129562; -- Vision of Kel'vax Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129557; -- Vision of an Ancient Nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32848 WHERE `entry`=126113; -- Kel'vax Brute
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=126150; -- Resurrected Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126107; -- Kel'vax Skeleton Shaper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126146; -- Kel'vax Offering
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=128934; -- Phylactery Guardian
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126112; -- Kel'vax Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126117; -- Bound Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126080; -- Shinga Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126191; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126142; -- Bajiatha
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128931; -- Firebreathing Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126090; -- Defiled Worshiper
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122434; -- Disembodied Head
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126132; -- Sickly Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126091; -- Defiled Embalmer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0, `HoverHeight`=1.299999952316284179 WHERE `entry`=122242; -- Bloodbound Dreadtick
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126183; -- Leeching Grub
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130481; -- Shinga Deathwalker
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=126079; -- Kol'jun Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126204; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129576; -- Zandalari Leguaan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126133; -- Swamp Scavenger
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135557; -- Target
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135567; -- Ghosts
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=122102; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122103; -- Blood Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129554; -- Zandalari Leguaan
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141801; -- Little Blue
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141802; -- Scars
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141803; -- Delta
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=141799; -- Grady Prett
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=122094; -- Blood Scavenger
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126833; -- Blind Wunja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127350; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127347; -- Skeletal Mound 02
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127348; -- Skeletal Mound 03
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127351; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127357; -- Skeletal Mound
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127246; -- Empowered Totem
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127247; -- Returned Predator
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127224; -- Empowered Worshipper
UPDATE `creature_template` SET `minlevel`=50, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=127225; -- Hexxer Nana'kwug
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127385; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127294; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129536; -- Marsh Feaster
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127298; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128943; -- Zardrax Release Power Point
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130347; -- Returned Hatchling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127245; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=127267; -- Sickly Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127265; -- Bloodscreecher Broodling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127255; -- Zardrax Conduit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127253; -- Reconstructed Terror
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127278; -- Skittering Feeder
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130300; -- Bloodscreecher Pup
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127279; -- Skittering Feeder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136395; -- Plains Brutosaur
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130634; -- Hookjaw Viper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127276; -- Cinderscale Youngling
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=131872; -- Sur'jan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=136381; -- Tojek
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137654; -- Faceless Corruptor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137653; -- Faceless Destroyer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `HoverHeight`=1.299999952316284179 WHERE `entry`=124404; -- Dreadtick Stalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124399; -- Infected Direhorn
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124400; -- Dreadtick Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=123757; -- Urok
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137656; -- Overlord Shugvoth
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143898; -- Makatau
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=141860; -- Sur'jan's Right Shoulderpad
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141858; -- Sur'jan's Left Shoulderpad
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130446; -- Scrounging Hatchling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141728; -- Sur'jan's Helm
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131855; -- Infected Saurolisk Egg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `HoverHeight`=1.299999952316284179 WHERE `entry`=126749; -- Dreadtick Latcher
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127001; -- Gwugnug the Cursed
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128343; -- Skyterror Hatchling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832, `dynamicflags`=4 WHERE `entry`=126703; -- Jarkadiax
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `RangeAttackTime`=0 WHERE `entry`=133829; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133831; -- Child of Jani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123809; -- Cinderscale Direhorn
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=127132; -- Infected Saurolisk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133812; -- Zanxib
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133815; -- Primal Snapjaw
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=32784 WHERE `entry`=152126; -- Expedition Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127134; -- Zandalari Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126713; -- Sur'jan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=127099; -- Urok
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135740; -- Rovash the One Eyed
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135750; -- Beastmaster Veayeka
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135757; -- Kiba
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135758; -- Kuko
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126702; -- Primal Skyterror
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135459; -- Provisioner Lija
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121638; -- Image of Krag'wa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121639; -- Image of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140513; -- Chukay
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121652; -- Image of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125834; -- Image of Torga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121873; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121572; -- Listen to Talk 1
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121288; -- Princess Talanji
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130226; -- Wetland Toad
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120903; -- Expedition Guard
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=121828; -- Zabar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121840; -- Crazy Vaza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121872; -- Shadow Hunter Bwu'ja
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121289; -- Rokhan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=127000; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=126689; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632, `dynamicflags`=4 WHERE `entry`=126723; -- Primal Snapjaw
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131017; -- Bloodfever Tarantula
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123654; -- Juvenile Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124217; -- Raptor Patriarch
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143047; -- Bloodfever Tarantula
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133076; -- Nazmani Headhunter
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131146; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133122; -- Nazmani Warrior
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139816; -- VFX Blood Orb
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139709; -- Rotting Monstrosity
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139829; -- Nazmani Necromancer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133020; -- Barricade
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133077; -- Nazmani War Slave
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133063; -- Nazmani Blood Witch
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=132985; -- Zandalari Soldier
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129462; -- Juvenile Stonehide
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130227; -- Rotfeeder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129461; -- Stonehide Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129730; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33587264 WHERE `entry`=121504; -- Grand Ma'da Ateena
UPDATE `creature_template` SET `minlevel`=25, `RangeAttackTime`=0 WHERE `entry`=141588; -- Bloodtusk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121241; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129723; -- Blood Troll
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=127779; -- Blood Weaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=127768; -- Siege Monstrosity
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127770; -- Blood Troll Warrior
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121437; -- Entered First Camp
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33024 WHERE `entry`=130844; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120613; -- Blood Troll Warmother
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120606; -- Blood Troll Hexxer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=570426112, `unit_flags2`=67110913, `unit_flags3`=8192 WHERE `entry`=129424; -- Captive Rope Anchor Point
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120607; -- Blood Troll Brutalizer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121296; -- Dead Zandalari
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `unit_flags`=33587712, `unit_flags2`=18432, `unit_flags3`=0 WHERE `entry`=121301; -- Zandalari Soldier
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130205; -- Lowland Rat
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130212; -- Reeking Maggot
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120587; -- Rivermarsh Raptor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=120588; -- Rivermarsh Snapjaw
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130780; -- Elusive Skimmer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123711; -- Blood Hunter
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123695; -- Nazmani Skyterror
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120904; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124226; -- Raptor Matriarch
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120905; -- Rokhan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121869; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130796; -- Guard Satao
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=570458880 WHERE `entry`=123071; -- Blood Hunter
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130218; -- Verdant Darter
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127474; -- Kal'dran
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123649; -- Juvenile Raptor
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130217; -- Nazmani Weevil
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121863; -- Shadow Hunter Bwu'ja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122934; -- Witch Doctor Kejabu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120804; -- Darkspear Scout
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143055; -- Boghopper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130794; -- Crazy Vaza
UPDATE `creature_template` SET `maxlevel`=1, `faction`=35, `RangeAttackTime`=0 WHERE `entry`=130199; -- Boghopper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=127475; -- Jo'chunga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130815; -- Expedition Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130910; -- Vaza's Least Favorite Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126551; -- Shadow Hunter Narez
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130829; -- Vaza's Favorite Skull
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122173; -- Direhorn Packbeast
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122276; -- Taloc
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130224; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143048; -- Elusive Skimmer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123083; -- Razorjaw Chomper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124084; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123736; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126628; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126635; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120593; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123731; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135399; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135257; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126590; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130775; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130876; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=137392; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137394; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131695; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912 WHERE `entry`=152019; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131598; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121810; -- Blood Minion
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121744; -- Blood Troll
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121930; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=121696; -- Torcalin Ironhide
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136092; -- Trynaklei
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=136082; -- Saranklei
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=136488; -- Alchemist Bleakheart
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33088 WHERE `entry`=136079; -- Falloughue the Hospitable
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=136074; -- Kina Cobbleflame
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142101; -- Argrim Stonedeep
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143523; -- Direhorn Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143521; -- Raptor Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143522; -- Baby Diemetradon
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131753; -- Dark Iron Golem
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130712; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=134018; -- T'eem
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=134017; -- Le'xi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130743; -- Adolescent Direhorn
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=130749; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130710; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=130718; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130577; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130489; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130447; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=130575; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131765; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126330; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131774; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131768; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141614; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131769; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131767; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130988; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130990; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130987; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131791; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131696; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131781; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131783; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133248; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131660; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131659; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131655; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131741; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132265; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=126564; -- Hexlord Raal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141957; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129300; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129597; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129595; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141628; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131746; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128078; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128150; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141617; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128148; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126304; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126329; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=127074; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126618; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127664; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138274; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126221; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131173; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126623; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131170; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129329; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=126560; -- Wardruid Loti
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128077; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131007; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131164; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131162; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126331; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127665; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=124040; -- Caravan Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141956; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=127030; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127029; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131745; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=140868; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137234; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141954; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128076; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126586; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140870; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=140869; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137237; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131813; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131811; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144082; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122231; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=126549; -- Rokhan
UPDATE `creature_template` SET `gossip_menu_id`=23237 WHERE `entry`=120740; -- King Rastakhan
UPDATE `creature_template` SET `gossip_menu_id`=22445 WHERE `entry`=135775; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=147, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=131840; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142504; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142503; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122693; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `npcflag`=147, `RangeAttackTime`=0 WHERE `entry`=122694; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137818; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132968; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127112; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132959; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127031; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132686; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122699; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129479; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122696; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=147, `RangeAttackTime`=0 WHERE `entry`=122698; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132983; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141609; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132984; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132978; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141936; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=147, `RangeAttackTime`=0 WHERE `entry`=122700; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122702; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130995; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=132711; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132707; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144074; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132704; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=132714; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132687; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142565; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142567; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132691; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132689; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132690; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144078; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131835; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131836; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133062; -- Razaji
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144085; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133231; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131574; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131827; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133065; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132312; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132012; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132098; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132097; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=34278; -- Withers
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=131403; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132107; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=68659; -- Anubisath Idol
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132301; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147641; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147642; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127123; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=77221; -- Iron Starlette
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132103; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140445; -- Beaker
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=54227; -- Nuts
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140415; -- Kona
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=33810; -- Sen'jin Fetish
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140423; -- Slobberchops
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140412; -- Evie
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=53225; -- Pterrordax Hatchling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140414; -- Arashi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132106; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=33227; -- Enchanted Broom
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140422; -- Nibbler
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140418; -- Piper
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131734; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=81431; -- Teroclaw Hatchling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=63621; -- Feral Vermling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140416; -- Bailey
UPDATE `creature_template` SET `minlevel`=30, `RangeAttackTime`=0 WHERE `entry`=93432; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140417; -- Bandit
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140413; -- Ashley
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133238; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=140411; -- Smudge
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=85517; -- Challenge Post
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132296; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133237; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132084; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=48609; -- Clockwork Gnome
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=115152; -- Wicked Soul
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132110; -- Emerald Turtle
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=15699; -- Tranquil Mechanical Yeti
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=14629; -- Loggerhead Snapjaw
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132089; -- Wolpertinger
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132085; -- Lofty Libram
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132109; -- Tortollan Tamer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132111; -- Turquoise Turtle
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=132112; -- Enchanted Pen
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=73668; -- Bonkers
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132083; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=66950; -- Pandaren Water Spirit
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=144256; -- Zandalari Kneebiter
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=144258; -- Zandalari Anklerender
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=132077; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132082; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=64899; -- Mechanical Pandaren Dragonling
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=71942; -- Xu-Fu, Cub of Xuen
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=82464; -- Elekk Plushie
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=144254; -- Zandalari Toenibbler
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=144257; -- Zandalari Footslasher
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126731; -- Diemetradon Egg
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126725; -- Elder Diemetradon
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=133420; -- Dazarian Toad
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126722; -- Diemetradon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123672; -- Direhorn Juvenile
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121688; -- Old Scargiver
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121680; -- Direhorn Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=133321; -- Razorwing Defender
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130922; -- Irritable Maka'fon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=130568; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134495; -- Congealing Slime
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=134048; -- Vukuba
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=134047; -- Enthralled Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=134046; -- Enthralled Saurid
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=136009; -- 7th Legion Marine
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136152; -- 7th Legion Scout
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133500; -- Eye of Yazma
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2900, `speed_walk`=1.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432, `unit_flags3`=1, `VehicleId`=5817 WHERE `entry`=133615; -- Caravan Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2900, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=133614; -- Tik'su
UPDATE `creature_template` SET `gossip_menu_id`=22210, `minlevel`=50, `maxlevel`=50, `faction`=2028, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=133612; -- Jani
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126655; -- Direhorn Juvenile
UPDATE `creature_template` SET `gossip_menu_id`=22261, `unit_flags`=33555200 WHERE `entry`=134049; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=126726; -- Young Diemetradon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131560; -- Feral Ravasaur
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=150412; -- Inert Voodoo Mask
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=131558; -- Invasive Razorwing
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=131554; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=125414; -- Spiny Gekkota
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126653; -- Hungry Saurid
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122223; -- Direhorn Cow
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122059; -- Direhorn Juvenile
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140287; -- Barder Zitaki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130589; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123062; -- Jes'tri
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122402; -- Brute Bodyguard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122129; -- Trader Alexxi Cruzpot
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121706; -- Beastlord L'kala
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135249; -- Meatminder Teki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122399; -- Pig
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140285; -- Rez'caza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133910; -- Lil' Stompy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1, `RangeAttackTime`=0, `unit_flags2`=67110912 WHERE `entry`=123677; -- Kill Credit: Naptime
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126562; -- Irritable Diemetradon
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=123060; -- Paku'ai Verraki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122114; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140305; -- Kraal Warhauler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122447; -- Kill Credit: Bush 01
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122009; -- Kraal Master B'khor
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=125784; -- Beastcaller Guardian
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126597; -- Dino Egg
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122445; -- Zandalari Pterrorwing
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=125417; -- Pygmy Anaconda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122400; -- Wingrider Bladeguard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125783; -- Apprentice Beastcaller


UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48479; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=274800, `RewardBonusMoney`=3600, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47244; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48478; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48473; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48468; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=261840, `RewardBonusMoney`=5650, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=48588; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48590; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48584; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=261840, `RewardBonusMoney`=3500, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48578; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48577; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48576; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48574; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=48573; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=13090, `RewardBonusMoney`=350, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48669; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=130920, `RewardBonusMoney`=2800, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47241; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=392760, `RewardBonusMoney`=4200, `FlagsEx`=2097216, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=51089; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=65460, `RewardBonusMoney`=1400, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=47188; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=124440, `RewardBonusMoney`=2750, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=47263; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=124440, `RewardBonusMoney`=2750, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47262; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=124440, `RewardBonusMoney`=2750, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47130; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=124440, `RewardBonusMoney`=2750, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47264; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=12445, `RewardBonusMoney`=340, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=49768; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=12445, `RewardBonusMoney`=340, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=48535; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=12445, `RewardBonusMoney`=340, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47103; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=12445, `RewardBonusMoney`=340, `RewardSpell`=267118, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47512; -- -Unknown-
UPDATE `quest_template` SET `QuestType`=2, `RewardMoney`=124440, `RewardBonusMoney`=2750, `FlagsEx`=6299712, `RewardFactionID1`=0, `RewardFactionValue1`=0, `VerifiedBuild`=38134 WHERE `ID`=50381; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292197; -- 292197
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290562; -- 290562
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334318; -- 334318
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294566; -- 294566
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294563; -- 294563
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292194; -- 292194
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312547; -- 312547
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292192; -- 292192
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292181; -- 292181
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296003; -- 296003
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296002; -- 296002
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292586; -- 292586
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296024; -- 296024
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=296023; -- 296023
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292591; -- 292591
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292583; -- 292583
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292565; -- 292565
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292563; -- 292563
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292561; -- 292561
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292555; -- 292555
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334789; -- 334789
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292557; -- 292557
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292758; -- 292758
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290567; -- 290567
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290183; -- 290183
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290624; -- 290624
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290618; -- 290618
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290248; -- 290248
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290182; -- 290182
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334716; -- 334716
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290079; -- 290079
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290222; -- 290222
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290211; -- 290211
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=289992; -- 289992
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290225; -- 290225
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295229; -- 295229
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292435; -- 292435
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312328; -- 312328
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312327; -- 312327
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=312326; -- 312326


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292197 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292197 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292197 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292197 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292197 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290562 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334318 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334318 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334318 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334318 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334318 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334318 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294566 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294566 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294563 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294563 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292194 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292194 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312547 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292181 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292181 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296002 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296024 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296023 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292591 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292565 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292557 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292758 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290183 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290624 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290182 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290079 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290222 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290211 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=289992 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295229 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312327 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312326 AND `Index`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141860; -- Sur'jan's Right Shoulderpad
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129574; -- Vision of Kel'vax Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129576; -- Zandalari Leguaan
UPDATE `creature_template` SET `rank`=6, `family`=11, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=134046; -- Enthralled Saurid
UPDATE `creature_template` SET `rank`=6, `family`=11, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=134047; -- Enthralled Saurid
UPDATE `creature_template` SET `family`=27, `type_flags`=73, `VerifiedBuild`=38134 WHERE `entry`=134048; -- Vukuba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127347; -- Skeletal Mound 02
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127348; -- Skeletal Mound 03
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127350; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126234; -- Kel'vax's Phylactery
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127351; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127357; -- Skeletal Mound
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130717; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127385; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131855; -- Infected Saurolisk Egg
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=121810; -- Blood Minion
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132985; -- Zandalari Soldier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122934; -- Witch Doctor Kejabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131872; -- Sur'jan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143047; -- Bloodfever Tarantula
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143048; -- Elusive Skimmer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121828; -- Zabar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143055; -- Boghopper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139709; -- Rotting Monstrosity
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121840; -- Crazy Vaza
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130780; -- Elusive Skimmer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130785; -- Huntmaster Kil'ja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133020; -- Barricade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130794; -- Crazy Vaza
UPDATE `creature_template` SET `type_flags`=2147483721, `VerifiedBuild`=38134 WHERE `entry`=136381; -- Tojek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130796; -- Guard Satao
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121863; -- Shadow Hunter Bwu'ja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121869; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=95061; -- Greater Fire Elemental
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122987; -- Hanzabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139743; -- Enchanted Tiki Mask
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121872; -- Shadow Hunter Bwu'ja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121873; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136395; -- Plains Brutosaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130815; -- Expedition Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127474; -- Kal'dran
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127475; -- Jo'chunga
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133062; -- Razaji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133063; -- Nazmani Blood Witch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130829; -- Vaza's Favorite Skull
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129723; -- Blood Troll
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133076; -- Nazmani Headhunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133077; -- Nazmani War Slave
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130844; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129730; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120804; -- Darkspear Scout
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138687; -- Blood Simulacrum
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=120822; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139816; -- VFX Blood Orb
UPDATE `creature_template` SET `KillCredit1`=0, `VerifiedBuild`=38134 WHERE `entry`=133122; -- Nazmani Warrior
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123071; -- Blood Hunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139829; -- Nazmani Necromancer
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=123083; -- Razorjaw Chomper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=152126; -- Expedition Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136488; -- Alchemist Bleakheart
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130910; -- Vaza's Least Favorite Skull
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124217; -- Raptor Patriarch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124226; -- Raptor Matriarch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=142101; -- Argrim Stonedeep
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=137653; -- Faceless Destroyer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=137654; -- Faceless Corruptor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=137656; -- Overlord Shugvoth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120903; -- Expedition Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120904; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120905; -- Rokhan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135459; -- Provisioner Lija
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131017; -- Bloodfever Tarantula
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126549; -- Rokhan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126551; -- Shadow Hunter Narez
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122094; -- Blood Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122102; -- Hanzabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122103; -- Blood Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129959; -- Grand Ma'da Ateena
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135557; -- Target
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135567; -- Ghosts
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124399; -- Infected Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124400; -- Dreadtick Stalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124404; -- Dreadtick Stalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122173; -- Direhorn Packbeast
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127768; -- Siege Monstrosity
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127770; -- Blood Troll Warrior
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127779; -- Blood Weaver
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122204; -- Blood Witch Najima
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134495; -- Congealing Slime
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131146; -- Princess Talanji
UPDATE `creature_template` SET `rank`=6, `family`=11, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=126689; -- Sickly Saurid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128931; -- Firebreathing Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128934; -- Phylactery Guardian
UPDATE `creature_template` SET `type_flags`=65537, `VerifiedBuild`=38134 WHERE `entry`=126702; -- Primal Skyterror
UPDATE `creature_template` SET `type_flags`=2147549257, `VerifiedBuild`=38134 WHERE `entry`=126703; -- Jarkadiax
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128943; -- Zardrax Release Power Point
UPDATE `creature_template` SET `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=122242; -- Bloodbound Dreadtick
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126713; -- Sur'jan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126723; -- Primal Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122276; -- Taloc
UPDATE `creature_template` SET `rank`=6, `family`=296, `type`=1, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=126749; -- Dreadtick Latcher
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=143521; -- Raptor Hatchling
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=143522; -- Baby Diemetradon
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=143523; -- Direhorn Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=84330; -- Meadowstomper Calf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133490; -- Jani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133500; -- Eye of Yazma
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135740; -- Rovash the One Eyed
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135750; -- Beastmaster Veayeka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135757; -- Kiba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135758; -- Kuko
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121241; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133531; -- Xu'ba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126833; -- Blind Wunja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130199; -- Boghopper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130205; -- Lowland Rat
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130212; -- Reeking Maggot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130217; -- Nazmani Weevil
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130218; -- Verdant Darter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121288; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121289; -- Rokhan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130226; -- Wetland Toad
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130227; -- Rotfeeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121296; -- Dead Zandalari
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121301; -- Zandalari Soldier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135835; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135836; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122434; -- Disembodied Head
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133612; -- Jani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133614; -- Tik'su
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133615; -- Caravan Brutosaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130300; -- Bloodscreecher Pup
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125834; -- Image of Torga
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130347; -- Returned Hatchling
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=123649; -- Juvenile Raptor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127000; -- Sickly Saurid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127001; -- Gwugnug the Cursed
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=123654; -- Juvenile Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121437; -- Entered First Camp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123672; -- Direhorn Juvenile
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132624; -- Zandalari War Priest
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123695; -- Nazmani Skyterror
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123711; -- Blood Hunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131533; -- Troll Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141588; -- Bloodtusk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121504; -- Grand Ma'da Ateena
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130446; -- Scrounging Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127099; -- Urok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122636; -- Blood Bonepicker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123757; -- Urok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=140513; -- Chukay
UPDATE `creature_template` SET `type_flags`=73, `VerifiedBuild`=38134 WHERE `entry`=133812; -- Zanxib
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133815; -- Primal Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121530; -- Tze'na
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=133829; -- Spell Bunny
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=133831; -- Child of Jani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130481; -- Shinga Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127132; -- Infected Saurolisk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127134; -- Zandalari Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136074; -- Kina Cobbleflame
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143898; -- Makatau
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136079; -- Falloughue the Hospitable
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136082; -- Saranklei
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136092; -- Trynaklei
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121572; -- Listen to Talk 1
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123809; -- Cinderscale Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129424; -- Captive Rope Anchor Point
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126079; -- Kol'jun Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126080; -- Shinga Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126087; -- Zombie Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126090; -- Defiled Worshiper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141728; -- Sur'jan's Helm
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126091; -- Defiled Embalmer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121638; -- Image of Krag'wa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126107; -- Kel'vax Skeleton Shaper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127224; -- Empowered Worshipper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121639; -- Image of Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127225; -- Hexxer Nana'kwug
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=128343; -- Skyterror Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129461; -- Stonehide Brutosaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129462; -- Juvenile Stonehide
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126112; -- Kel'vax Warrior
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126113; -- Kel'vax Brute
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=126117; -- Bound Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121652; -- Image of Hir'eek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127245; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127246; -- Empowered Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127247; -- Returned Predator
UPDATE `creature_template` SET `rank`=6, `family`=11, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=126132; -- Sickly Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126133; -- Swamp Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127253; -- Reconstructed Terror
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127255; -- Zardrax Conduit
UPDATE `creature_template` SET `type_flags`=73, `VerifiedBuild`=38134 WHERE `entry`=126142; -- Bajiatha
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126146; -- Kel'vax Offering
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127265; -- Bloodscreecher Broodling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126150; -- Resurrected Warrior
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127267; -- Sickly Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=100463; -- Invisible Man
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=127276; -- Cinderscale Youngling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141799; -- Grady Prett
UPDATE `creature_template` SET `rank`=6, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=127278; -- Skittering Feeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127279; -- Skittering Feeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141801; -- Little Blue
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141802; -- Scars
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141803; -- Delta
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130634; -- Hookjaw Viper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130636; -- Crimsontail Moth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120587; -- Rivermarsh Raptor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120588; -- Rivermarsh Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127294; -- Sickly Saurid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127298; -- Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126183; -- Leeching Grub
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129536; -- Marsh Feaster
UPDATE `creature_template` SET `type_flags`=72, `VerifiedBuild`=38134 WHERE `entry`=126187; -- Corpse Bringer Yal'kar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126191; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120606; -- Blood Troll Hexxer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120607; -- Blood Troll Brutalizer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129545; -- Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120613; -- Blood Troll Warmother
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131787; -- Dreadtick Larvae
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129554; -- Zandalari Leguaan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129555; -- Vision of a Bwonsamdi Priest
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126204; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129557; -- Vision of an Ancient Nazmani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129562; -- Vision of Kel'vax Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129563; -- Vision of Kol'jun Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121744; -- Blood Troll
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129564; -- Vision of Shinga Deathwalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129565; -- Vision of a Bwonsamdi Priest
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129567; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129568; -- Vision of a Heretical Nazmani
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129569; -- Vision of an Ancient Nazmani Body
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141858; -- Sur'jan's Left Shoulderpad


UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=126087 AND `Idx`=0); -- Zombie Bunny
UPDATE `creature_template_model` SET `DisplayScale`=0.649999976158142089 WHERE (`CreatureID`=141803 AND `Idx`=0); -- Delta
UPDATE `creature_template_model` SET `DisplayScale`=0.550000011920928955 WHERE (`CreatureID`=141801 AND `Idx`=0); -- Little Blue
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=127298 AND `Idx`=0); -- Zardrax the Empowerer
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=136395 AND `Idx`=0); -- Plains Brutosaur
UPDATE `creature_template_model` SET `DisplayScale`=1.649999976158142089 WHERE (`CreatureID`=136381 AND `Idx`=0); -- Tojek
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=123757 AND `Idx`=0); -- Urok
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=143898 AND `Idx`=0); -- Makatau
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=133812 AND `Idx`=0); -- Zanxib
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=127099 AND `Idx`=0); -- Urok
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=121652 AND `Idx`=0); -- Image of Hir'eek
UPDATE `creature_template_model` SET `Probability`=100 WHERE (`CreatureID`=121639 AND `Idx`=0); -- Image of Bwonsamdi
UPDATE `creature_template_model` SET `DisplayScale`=0.649999976158142089 WHERE (`CreatureID`=126689 AND `Idx`=0); -- Sickly Saurid
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=124217 AND `Idx`=0); -- Raptor Patriarch
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=127779 AND `Idx`=3); -- Blood Weaver
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=127779 AND `Idx`=2); -- Blood Weaver
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=127779 AND `Idx`=1); -- Blood Weaver
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=127779 AND `Idx`=0); -- Blood Weaver
UPDATE `creature_template_model` SET `DisplayScale`=1.5, `Probability`=0 WHERE (`CreatureID`=127768 AND `Idx`=0); -- Siege Monstrosity
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=127770 AND `Idx`=0); -- Blood Troll Warrior
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=120613 AND `Idx`=0); -- Blood Troll Warmother
UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089 WHERE (`CreatureID`=124226 AND `Idx`=0); -- Raptor Matriarch
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=123649 AND `Idx`=0); -- Juvenile Raptor
UPDATE `creature_template_model` SET `DisplayScale`=0.649999976158142089 WHERE (`CreatureID`=122276 AND `Idx`=0); -- Taloc
UPDATE `creature_template_model` SET `DisplayScale`=0.25 WHERE (`CreatureID`=143522 AND `Idx`=0); -- Baby Diemetradon
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=143521 AND `Idx`=0); -- Raptor Hatchling
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=142101 AND `Idx`=0); -- Argrim Stonedeep
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=123672 AND `Idx`=0); -- Direhorn Juvenile


UPDATE `gameobject_template` SET `Data30`=75889, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=273484; -- Repaired Phylactery
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279897; -- Rubble
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=277715; -- Cursed Nazmani Chest
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278337; -- Repaired Phylactery
UPDATE `gameobject_template` SET `Data30`=77435, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278343; -- Pristine Phylactery
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278342; -- Pristine Phylactery
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278341; -- Ancient Phylactery
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=297522; -- Tales of de Loa: Hir'eek
UPDATE `gameobject_template` SET `Data30`=77434, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278340; -- Ancient Phylactery
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296520; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281208; -- Broken Zandalari Supply Barrel
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281207; -- Broken Zandalari Supply Crate
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281361; -- Ritual Powder
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278335; -- Meat Chunk
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=277693; -- Ritual Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270916; -- Incense
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270911; -- Femur
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270910; -- Offering Urn
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=270902; -- Weathered Shrine
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=271557; -- Blood Stain
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=271556; -- Blood Stain
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=271170; -- Broken Spear
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231074; -- Bonfire
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=282660; -- Urn of Agussu
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=271095; -- Altar of Gee'dae
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277280; -- Bone Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277279; -- Bone Pile
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=277885; -- Wunja's Trove
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=276280; -- Skeleton Mound 02
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=269911; -- Sacrificial Altar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296501; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296530; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296500; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296534; -- Cookpot
UPDATE `gameobject_template` SET `Data1`=76252, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=276618; -- Platinum Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=297128; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=325471; -- Boiling Cauldron
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=279260; -- "Cleverly" Disguised Chest
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=273827; -- Skyterror Egg
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281385; -- Mysterious Trashpile
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=38134 WHERE `entry`=253936; -- Meat Hunk
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293416; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293415; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=287328; -- Map
UPDATE `gameobject_template` SET `Data8`=1, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=287232; -- Scouting Report
UPDATE `gameobject_template` SET `ContentTuningId`=482, `VerifiedBuild`=38134 WHERE `entry`=207386; -- Refreshment Table
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=269896; -- Basket
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=269797; -- Pool of Visions
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=296736; -- Crazy Vaza'z Crazy Diary
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=282441; -- Mailbox
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=280611; -- Ancient Gong
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=38134 WHERE `entry`=243439; -- Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295697; -- Stewpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296514; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296486; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280795; -- Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296538; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281002; -- Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296537; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=282723; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281001; -- Barricade
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281000; -- Barricade
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=291241; -- Gnarl Root
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296548; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=291238; -- Bwonsamdi's Tears
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296546; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296539; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=292823; -- Krag'wa's Ire
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=291261; -- Woven Idol
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=291247; -- Roasted Raptor
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=291233; -- Saurolisk Tail
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280388; -- Corpse
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=279299; -- Venomous Seal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278450; -- Troll Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=297633; -- Spores
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281177; -- Triangulation Platform
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=268919; -- Zandalari Sack
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=282458; -- Triangulation Platform
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=268918; -- Zandalari Cart
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=268917; -- Zandalari Sack
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=268967; -- Zandalari Crate
UPDATE `gameobject_template` SET `Data1`=76262, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=276622; -- Rich Storm Silver Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294049; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=297131; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=297130; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=297129; -- Bench


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=273484 AND `Idx`=0); -- Repaired Phylactery
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278337 AND `Idx`=0); -- Repaired Phylactery
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278343 AND `Idx`=0); -- Pristine Phylactery
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278342 AND `Idx`=0); -- Pristine Phylactery
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278341 AND `Idx`=0); -- Ancient Phylactery
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278340 AND `Idx`=0); -- Ancient Phylactery
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=281361 AND `Idx`=0); -- Ritual Powder
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=277885 AND `Idx`=0); -- Wunja's Trove

DELETE FROM `npc_text` WHERE `ID` IN (34123 /*34123*/, 34029 /*34029*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(34123, 1, 0, 0, 0, 0, 0, 0, 0, 147883, 0, 0, 0, 0, 0, 0, 0, 38134), -- 34123
(34029, 1, 0, 0, 0, 0, 0, 0, 0, 147360, 0, 0, 0, 0, 0, 0, 0, 38134); -- 34029

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32627; -- 32627
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32756; -- 32756
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32733; -- 32733
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32137; -- 32137
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33343; -- 33343
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32033; -- 32033
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32124; -- 32124

UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16787;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16787;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=512, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Flags`=512, `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Flags`=512, `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;


REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(20281, 24192, 0, 0, 0, 0, 0, 22302, 0, 0, 30000, 38134), -- SpellId : 327195
(20280, 24192, 0, 0, 0, 0, 0, 22302, 0, 0, 30000, 38134), -- SpellId : 327257
(20553, 24192, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 38134); -- SpellId : 329604


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12080 AND `AreaTriggerId`=16787); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4999, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12080 AND `AreaTriggerId`=16787); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0

UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6357 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5968 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5968 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5980 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5980 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5980 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6315 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6315 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5828 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=5142 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5975 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5784 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5909 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5909 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5909 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7676 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7676 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7676 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6275 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6275 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6255 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6255 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=5801 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5799 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5799 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5799 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5976 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5976 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=5115 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6192 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6192 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5829 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6208 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6208 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6208 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6319 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5974 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5974 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=6419 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=6419 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (13056, 13010);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(13056, 0, 0, 0, 0, 38134),
(13010, 2000, 0, 1, 0, 38134);

UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14299;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13339;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13338;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13359;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13358;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13357;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14466;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14336;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13059;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11505;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14245;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14244;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14243;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14242;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14241;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13312;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13311;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14246;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14267;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13349;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13787;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13786;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13785;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13784;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13783;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12991;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13241;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13240;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13239;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17489;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17488;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17487;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14064;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14063;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13019;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13018;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13017;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13020;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14031;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14030;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=13016;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13787;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13786;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13785;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13784;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13783;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13011;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13012;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13351;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13350;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11456;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13791;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13790;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14330;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13063;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13062;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13061;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13060;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13856;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13855;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13854;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14205;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13348;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13347;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14465;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14464;


DELETE FROM `conversation_template` WHERE `Id`=5825;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(5825, 13056, 8516, 0, 38134);

UPDATE `conversation_template` SET `LastLineEndTime`=15903, `VerifiedBuild`=38134 WHERE `Id`=6275;
UPDATE `conversation_template` SET `LastLineEndTime`=11000, `VerifiedBuild`=38134 WHERE `Id`=5976;
UPDATE `conversation_template` SET `LastLineEndTime`=4800, `VerifiedBuild`=38134 WHERE `Id`=5975;
UPDATE `conversation_template` SET `LastLineEndTime`=10150, `VerifiedBuild`=38134 WHERE `Id`=5968;
UPDATE `conversation_template` SET `LastLineEndTime`=12250, `VerifiedBuild`=38134 WHERE `Id`=6192;
UPDATE `conversation_template` SET `LastLineEndTime`=9850, `VerifiedBuild`=38134 WHERE `Id`=5974;
UPDATE `conversation_template` SET `LastLineEndTime`=46150, `VerifiedBuild`=38134 WHERE `Id`=5944;
UPDATE `conversation_template` SET `LastLineEndTime`=29600, `VerifiedBuild`=38134 WHERE `Id`=6190;
UPDATE `conversation_template` SET `LastLineEndTime`=11850, `VerifiedBuild`=38134 WHERE `Id`=5980;
UPDATE `conversation_template` SET `LastLineEndTime`=29600, `VerifiedBuild`=38134 WHERE `Id`=6190;
UPDATE `conversation_template` SET `LastLineEndTime`=14644, `VerifiedBuild`=38134 WHERE `Id`=6319;
UPDATE `conversation_template` SET `LastLineEndTime`=19991, `VerifiedBuild`=38134 WHERE `Id`=6255;
UPDATE `conversation_template` SET `LastLineEndTime`=23483, `VerifiedBuild`=38134 WHERE `Id`=7676;
UPDATE `conversation_template` SET `FirstLineID`=13061, `LastLineEndTime`=17059, `VerifiedBuild`=38134 WHERE `Id`=5830;
UPDATE `conversation_template` SET `LastLineEndTime`=7690, `VerifiedBuild`=38134 WHERE `Id`=5829;
UPDATE `conversation_template` SET `LastLineEndTime`=8312, `VerifiedBuild`=38134 WHERE `Id`=5828;
UPDATE `conversation_template` SET `LastLineEndTime`=16515, `VerifiedBuild`=38134 WHERE `Id`=6419;
UPDATE `conversation_template` SET `LastLineEndTime`=9689, `VerifiedBuild`=38134 WHERE `Id`=6315;
UPDATE `conversation_template` SET `LastLineEndTime`=12698, `VerifiedBuild`=38134 WHERE `Id`=5142;
UPDATE `conversation_template` SET `LastLineEndTime`=16602, `VerifiedBuild`=38134 WHERE `Id`=5115;
UPDATE `conversation_template` SET `LastLineEndTime`=21928, `VerifiedBuild`=38134 WHERE `Id`=5909;
UPDATE `conversation_template` SET `LastLineEndTime`=25357, `VerifiedBuild`=38134 WHERE `Id`=5802;
UPDATE `conversation_template` SET `LastLineEndTime`=12875, `VerifiedBuild`=38134 WHERE `Id`=5801;
UPDATE `conversation_template` SET `LastLineEndTime`=13315, `VerifiedBuild`=38134 WHERE `Id`=5799;
UPDATE `conversation_template` SET `LastLineEndTime`=8029, `VerifiedBuild`=38134 WHERE `Id`=5784;
UPDATE `conversation_template` SET `LastLineEndTime`=7431, `VerifiedBuild`=38134 WHERE `Id`=6357;
UPDATE `conversation_template` SET `LastLineEndTime`=17740, `VerifiedBuild`=38134 WHERE `Id`=6208;


UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=282722; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=276269; -- Blood Troll Cage
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=276506; -- Mojo Brewing Cauldron
UPDATE `gameobject_template_addon` SET `WorldEffectID`=520 WHERE `entry`=278497; -- Vial of Vampiric Mojo
UPDATE `gameobject_template_addon` SET `WorldEffectID`=520 WHERE `entry`=278566; -- Flask of Blood Rage
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=278437; -- Offering to Bwonsamdi
UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=279366; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=273768; -- Shadow Rune
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=273769; -- Shadow Rune
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=273767; -- Shadow Rune
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=3421 WHERE `entry`=270920; -- Soul Barrier
UPDATE `gameobject_template_addon` SET `flags`=5 WHERE `entry`=278691; -- Sarcophagus Lid
UPDATE `gameobject_template_addon` SET `faction`=2201 WHERE `entry`=281711; -- Mailbox

UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48890; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48801; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48869; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48856; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48857; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48854; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48699; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49440; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47491; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47880; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49278; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47244; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47244; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=51089; -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(47244, 0, 2, 32, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1322864, 0, 38134), -- -Unknown-
(47244, 0, 1, 0, 290562, 122204, 1642, 863, 0, 0, 0, 0, 0, 1323924, 0, 38134), -- -Unknown-
(47244, 0, 0, -1, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1344153, 0, 38134), -- -Unknown-
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=2 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=47244 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47244 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47244 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(47244, 2, 0, 1639, 1523, 26, 38134), -- -Unknown-
(47244, 1, 0, 1777, 1420, 20, 38134), -- -Unknown-
(47244, 0, 0, 1990, 1373, 16, 38134), -- -Unknown-
(31459, 0, 0, 3044, 1251, 655, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-


UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48800; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49078; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48869; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48856; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48857; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50933; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48854; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48890; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48801; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48699; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49432; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47247; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49348; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47491; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47880; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49440; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49278; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=50381;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(50381, 0, 0, 0, 0, 'You had a chat with Tik\'su about his hat yet, richmon?', 38134); -- -Unknown-

UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-

DELETE FROM `creature_template_addon` WHERE `entry` IN (141801 /*141801 (Little Blue)*/, 141802 /*141802 (Scars)*/, 141803 /*141803 (Delta)*/, 127744 /*127744 (Magura) - Set Health % (Uses Override Points) (No Health Regen), Blood Splatter*/, 128584 /*128584 (Vugthuth) - Vugthuth Cosmetic Skirt*/, 143054 /*143054 (Spectral Raven)*/, 152126 /*152126 (Expedition Guard)*/, 150412 /*150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura, Inert Golem Stun*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(141801, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141801 (Little Blue)
(141802, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141802 (Scars)
(141803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141803 (Delta)
(127744, 0, 0, 3, 1, 0, 0, 0, 0, '247866 167641'), -- 127744 (Magura) - Set Health % (Uses Override Points) (No Health Regen), Blood Splatter
(128584, 0, 0, 0, 1, 0, 0, 0, 0, '275108'), -- 128584 (Vugthuth) - Vugthuth Cosmetic Skirt
(143054, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 143054 (Spectral Raven)
(152126, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 152126 (Expedition Guard)
(150412, 0, 0, 0, 1, 0, 15263, 0, 0, '291587 282764'); -- 150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura; Inert Golem Stun

UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=127394; -- 127394 (Empowered Kal'dran)
UPDATE `creature_template_addon` SET `aiAnimKit`=13500 WHERE `entry`=124475; -- 124475 (Shambling Ambusher)
UPDATE `creature_template_addon` SET `aiAnimKit`=13792 WHERE `entry`=127246; -- 127246 (Empowered Totem)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126891; -- 126891 (Blood Witch Yialu)
UPDATE `creature_template_addon` SET `auras`='255220' WHERE `entry`=126888; -- 126888 (Blood Witch Vashera)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=13581, `auras`='' WHERE `entry`=126823; -- 126823 (Sacrificed Drudge)
UPDATE `creature_template_addon` SET `auras`='252155' WHERE `entry`=126807; -- 126807 (Obedient Drudge)
UPDATE `creature_template_addon` SET `aiAnimKit`=13932 WHERE `entry`=128139; -- 128139 (Unworthy Sacrifice)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=129424; -- 129424 (Captive Rope Anchor Point)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=127176; -- 127176 (Crawg Spawnling)
UPDATE `creature_template_addon` SET `aiAnimKit`=13906 WHERE `entry`=126933; -- 126933 (Unproven Drudge)
UPDATE `creature_template_addon` SET `aiAnimKit`=924 WHERE `entry`=126588; -- 126588 (Keula)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122666; -- 122666 (Hex Priestess Tizeja)
UPDATE `creature_template_addon` SET `aiAnimKit`=13582 WHERE `entry`=129755; -- 129755 (Zalazane)
UPDATE `creature_template_addon` SET `auras`='256573 257852' WHERE `entry`=122684; -- 122684 (Reanimated Horror)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122795; -- 122795 (Witch Doctor Kejabu)
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=134363; -- 134363 (Drained Spirit)
UPDATE `creature_template_addon` SET `bytes1`=1, `aiAnimKit`=0 WHERE `entry`=126664; -- 126664 (Doomwing Raven)
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=128898; -- 128898 (Drained Spirit)
UPDATE `creature_template_addon` SET `aiAnimKit`=5481 WHERE `entry`=129748; -- 129748 (Zandalari Spirit)
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=128875; -- 128875 (Drained Spirit)
UPDATE `creature_template_addon` SET `auras`='256313' WHERE `entry`=133122; -- 133122 (Nazmani Warrior)
UPDATE `creature_template_addon` SET `auras`='145363' WHERE `entry`=123071; -- 123071 (Blood Hunter)
UPDATE `creature_template_addon` SET `auras`='260422' WHERE `entry`=124084; -- 124084
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='114943' WHERE `entry`=120804; -- 120804 (Darkspear Scout)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=120593; -- 120593
UPDATE `creature_template_addon` SET `auras`='12787' WHERE `entry`=126723; -- 126723 (Primal Snapjaw)
UPDATE `creature_template_addon` SET `auras`='254493' WHERE `entry`=126091; -- 126091 (Defiled Embalmer)
UPDATE `creature_template_addon` SET `aiAnimKit`=2189 WHERE `entry`=122276; -- 122276 (Taloc)
UPDATE `creature_template_addon` SET `auras`='256644' WHERE `entry`=126112; -- 126112 (Kel'vax Warrior)
UPDATE `creature_template_addon` SET `auras`='256644' WHERE `entry`=126150; -- 126150 (Resurrected Warrior)
UPDATE `creature_template_addon` SET `auras`='105944' WHERE `entry`=126133; -- 126133 (Swamp Scavenger)


UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141801 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141802 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141799 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129779 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=129545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127385 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127294 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124473 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124475 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127351 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127298 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127348 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128943 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127350 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135784 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127384 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127255 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127247 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127216 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126452 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126460 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126433 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126926 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127215 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128067 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127268 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126890 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126891 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129536 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127391 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126888 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143053 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126823 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127056 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126807 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126846 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128290 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130297 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128139 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127176 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126933 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128426 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127142 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126616 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=128584 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127496 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=126588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126658 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126650 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143054 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=122688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129010 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129755 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129657 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127764 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130214 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129086 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126529 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123039 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127738 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=143644 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128701 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130268 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=139173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129535 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=122191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124460 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124428 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129028 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128898 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129748 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127140 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128746 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122204 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=152126 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123736 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130829 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121638 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=121639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=121828 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125834 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135758 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121289 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=140513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130780 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=120804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120587 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126091 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=150412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126132 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129576 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135557 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122276 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128934 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126079 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126113 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126150 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126080 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129461 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=1.110454082489013671 WHERE `DisplayID`=78162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=34418;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82919;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79123;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84283;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80057;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79367;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80061;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=34970;
UPDATE `creature_model_info` SET `BoundingRadius`=2.196302175521850585, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79803;
UPDATE `creature_model_info` SET `BoundingRadius`=1.832476615905761718, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79585;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79340;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80042;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80014;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79334;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=34417;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84398;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79335;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80058;
UPDATE `creature_model_info` SET `BoundingRadius`=1.072999954223632812, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=33736;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79333;
UPDATE `creature_model_info` SET `BoundingRadius`=1.218167662620544433, `CombatReach`=2.699999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=80047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80560;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81055;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79717;
UPDATE `creature_model_info` SET `BoundingRadius`=3.45185708999633789, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=57486;
UPDATE `creature_model_info` SET `BoundingRadius`=6.460801124572753906, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=40269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58804;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78650;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80541;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80588;
UPDATE `creature_model_info` SET `BoundingRadius`=2.071114301681518554, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=55376;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32814;
UPDATE `creature_model_info` SET `BoundingRadius`=1.938240408897399902, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=33453;
UPDATE `creature_model_info` SET `BoundingRadius`=0.966025233268737792, `CombatReach`=2.069999933242797851, `VerifiedBuild`=38134 WHERE `DisplayID`=79151;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79152;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=80459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80539;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=76729;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79230;
UPDATE `creature_model_info` SET `BoundingRadius`=6.826453208923339843, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=80851;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78719;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78720;
UPDATE `creature_model_info` SET `BoundingRadius`=0.075000002980232238, `CombatReach`=0.075000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=80457;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028887391090393066, `CombatReach`=1.539999961853027343, `VerifiedBuild`=38134 WHERE `DisplayID`=79232;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78718;
UPDATE `creature_model_info` SET `BoundingRadius`=0.622134089469909667, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=78717;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79228;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79229;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79227;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79236;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79306;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80538;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80540;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79856;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79126;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79127;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79265;
UPDATE `creature_model_info` SET `BoundingRadius`=0.656697094440460205, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=79169;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79171;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79272;
UPDATE `creature_model_info` SET `BoundingRadius`=0.656697094440460205, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=79170;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79129;
UPDATE `creature_model_info` SET `BoundingRadius`=1.725928544998168945, `VerifiedBuild`=38134 WHERE `DisplayID`=67783;
UPDATE `creature_model_info` SET `BoundingRadius`=0.622134089469909667, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79172;
UPDATE `creature_model_info` SET `BoundingRadius`=2.416299819946289062, `CombatReach`=1.399999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=81162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.955395400524139404, `CombatReach`=1.429999947547912597, `VerifiedBuild`=38134 WHERE `DisplayID`=79305;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80461;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82832;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79174;
UPDATE `creature_model_info` SET `BoundingRadius`=0.955395400524139404, `CombatReach`=1.429999947547912597, `VerifiedBuild`=38134 WHERE `DisplayID`=79304;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79173;
UPDATE `creature_model_info` SET `BoundingRadius`=2.204758644104003906, `CombatReach`=3.300000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=79919;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79273;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382499992847442626, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=79562;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399305284023284912, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79010;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19986;
UPDATE `creature_model_info` SET `BoundingRadius`=10.7612762451171875, `CombatReach`=15, `VerifiedBuild`=38134 WHERE `DisplayID`=66284;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=2956;
UPDATE `creature_model_info` SET `BoundingRadius`=0.292758256196975708, `CombatReach`=0.375, `VerifiedBuild`=38134 WHERE `DisplayID`=79015;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75372;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=76975;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80399;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80397;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80398;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=76966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.700529217720031738, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79028;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79027;
UPDATE `creature_model_info` SET `BoundingRadius`=6.851508140563964843, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=78991;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=76984;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75961;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=80847;
UPDATE `creature_model_info` SET `BoundingRadius`=3.053412199020385742, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=80186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79589;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520833015441894531, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=77012;
UPDATE `creature_model_info` SET `BoundingRadius`=3.41694188117980957, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=81103;
UPDATE `creature_model_info` SET `BoundingRadius`=1.026381731033325195, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=81076;
UPDATE `creature_model_info` SET `BoundingRadius`=0.425056040287017822, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=15136;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80371;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80758;
UPDATE `creature_model_info` SET `BoundingRadius`=0.636844754219055175, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80770;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80773;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81077;
UPDATE `creature_model_info` SET `BoundingRadius`=0.636844754219055175, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79026;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80755;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80756;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42365;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80757;
UPDATE `creature_model_info` SET `BoundingRadius`=10.27726173400878906, `CombatReach`=3.599999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=78698;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80446;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80866;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41766;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81376;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80462;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01109480857849121, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=86174;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80458;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80838;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80839;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80610;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83585;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83586;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80837;
UPDATE `creature_model_info` SET `BoundingRadius`=1.026381731033325195 WHERE `DisplayID`=32546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.227821439504623413, `VerifiedBuild`=38134 WHERE `DisplayID`=78995;
UPDATE `creature_model_info` SET `BoundingRadius`=0.175650030374526977, `VerifiedBuild`=38134 WHERE `DisplayID`=83583;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80840;
UPDATE `creature_model_info` SET `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=81238;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77494;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=80855;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.517778575420379638, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=65547;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75864;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75865;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=76764;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=78779;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45494;
UPDATE `creature_model_info` SET `BoundingRadius`=0.532049536705017089, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=82571;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75892;
UPDATE `creature_model_info` SET `BoundingRadius`=2.565691709518432617, `CombatReach`=1.949999928474426269 WHERE `DisplayID`=83645;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76728;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=60235;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84377;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75970;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84261;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=79274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=81218;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75969;
UPDATE `creature_model_info` SET `BoundingRadius`=0.293149083852767944, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=83640;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47990;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84381;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=0.625, `VerifiedBuild`=38134 WHERE `DisplayID`=44656;
UPDATE `creature_model_info` SET `BoundingRadius`=0.240000009536743164, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=47989;
UPDATE `creature_model_info` SET `BoundingRadius`=4.03800058364868164, `CombatReach`=3.75, `VerifiedBuild`=38134 WHERE `DisplayID`=77504;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75968;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75967;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78936;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77503;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121 WHERE `DisplayID`=78161;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33451;
UPDATE `creature_model_info` SET `BoundingRadius`=1.938240408897399902, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=33450;
UPDATE `creature_model_info` SET `BoundingRadius`=2.960413694381713867, `CombatReach`=2.25 WHERE `DisplayID`=83646;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=75850;
UPDATE `creature_model_info` SET `BoundingRadius`=1.973609089851379394, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83649;
UPDATE `creature_model_info` SET `BoundingRadius`=0.410187005996704101, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=58745;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.373770296573638916, `CombatReach`=0.1875, `VerifiedBuild`=38134 WHERE `DisplayID`=77652;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78727;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `VerifiedBuild`=38134 WHERE `DisplayID`=91019;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79980;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78131;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342625141143798828, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.373770296573638916, `CombatReach`=0.1875, `VerifiedBuild`=38134 WHERE `DisplayID`=45908;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79979;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78726;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80611;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79978;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77483;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78723;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81377;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85386;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79975;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=24889;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78692;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79977;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82573;
UPDATE `creature_model_info` SET `BoundingRadius`=1.425259590148925781, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78722;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78693;
UPDATE `creature_model_info` SET `BoundingRadius`=0.85839998722076416, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78737;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=9904;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77485;

DELETE FROM `npc_vendor` WHERE (`entry`=32641 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32641, 15, 183950, 0, 0, 1, 0, 0, 38134), -- Distilled Death Extract
(32641, 14, 180733, 0, 0, 1, 0, 0, 38134), -- Luminous Flux
(32641, 13, 183951, 0, 0, 1, 0, 0, 38134), -- Immortal Shard
(32641, 12, 183952, 0, 0, 1, 0, 0, 38134), -- Machinist's Oil
(32641, 11, 183953, 0, 0, 1, 0, 0, 38134), -- Sealing Wax
(32641, 10, 183954, 0, 0, 1, 0, 0, 38134), -- Malleable Wire
(32641, 9, 183955, 0, 0, 1, 0, 0, 38134), -- Curing Salt
(32641, 8, 6219, 0, 0, 1, 0, 0, 38134); -- Arclight Spanner

UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1); -- Simple Dagger
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (127744,126529,124513,124428,152126));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(127744, 1, 94681, 0, 0, 152892, 0, 0, 0, 0, 0), -- Magura
(126529, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(124513, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(124428, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(152126, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0); -- Expedition Guard

UPDATE `creature_equip_template` SET `ItemID1`=106945, `ItemID3`=0 WHERE (`CreatureID`=129545 AND `ID`=1); -- Bwonsamdi
UPDATE `creature_equip_template` SET `ItemID1`=116485 WHERE (`CreatureID`=133122 AND `ID`=2); -- Nazmani Warrior
UPDATE `creature_equip_template` SET `ItemID1`=153589 WHERE (`CreatureID`=133122 AND `ID`=1); -- Nazmani Warrior


UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=83 AND `TextId`=580); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32779); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32779); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `TextId`=32813); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `TextId`=32813); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `TextId`=32814); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `TextId`=32814); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21785 AND `TextId`=33275); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21787 AND `TextId`=33276); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21786 AND `TextId`=33276); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21766 AND `TextId`=33236); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21530 AND `TextId`=32782); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `TextId`=33231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `TextId`=33231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21736 AND `TextId`=33163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21736 AND `TextId`=33163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21736 AND `TextId`=33163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `TextId`=34426); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `TextId`=34426); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `TextId`=34426); -- 0

UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=83 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138526, `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138526, `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136975, `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136975, `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140514, `VerifiedBuild`=38134 WHERE (`MenuId`=21785 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140518, `VerifiedBuild`=38134 WHERE (`MenuId`=21787 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140516, `VerifiedBuild`=38134 WHERE (`MenuId`=21786 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140031, `VerifiedBuild`=38134 WHERE (`MenuId`=21766 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136986, `VerifiedBuild`=38134 WHERE (`MenuId`=21530 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=139727, `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=139727, `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `OptionIndex`=0);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=21530 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21530, 0, 21766, 0);

UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141801; -- Little Blue
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141802; -- Scars
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141803; -- Delta
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=141799; -- Grady Prett
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126833; -- Blind Wunja
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135507; -- Zandalari Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129779; -- Zalamar Ambusher
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129545; -- Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=127394; -- Empowered Kal'dran
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127385; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=127225; -- Hexxer Nana'kwug
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127294; -- Sickly Saurid
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143052; -- Returned Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124473; -- Abandoned Treasure
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124475; -- Shambling Ambusher
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127351; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=127298; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127348; -- Skeletal Mound 03
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128943; -- Zardrax Release Power Point
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127253; -- Reconstructed Terror
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127350; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127347; -- Skeletal Mound 02
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127245; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127246; -- Empowered Totem
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127349; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127346; -- Skeletal Mound 01
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127357; -- Skeletal Mound
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130347; -- Returned Hatchling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135784; -- Imperial Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127384; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127255; -- Zardrax Conduit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127247; -- Returned Predator
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127224; -- Empowered Worshipper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127216; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129380; -- Wardrummer Sheej
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126452; -- Marsh Prowler
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126460; -- Tainted Guardian
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130199; -- Boghopper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127999; -- Wardrummer Saljo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128066; -- Engorged Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126433; -- Bloodscreecher Wanderer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126926; -- Venomjaw
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127212; -- Kal'dran
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127215; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128067; -- Poisoned Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129381; -- Wardrummer Gix
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127265; -- Bloodscreecher Broodling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127267; -- Sickly Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127268; -- Sickly Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126890; -- Blood Priestess Zu'Anji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126891; -- Blood Witch Yialu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129536; -- Marsh Feaster
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127145; -- Zalamar Bloodsinger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127391; -- Bloodseeker Jo'chunga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126888; -- Blood Witch Vashera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128074; -- Hir'eek
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143053; -- Glutted Bleeder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127060; -- Blood Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126823; -- Sacrificed Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127056; -- Zalamar Nighthunter Trainer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127040; -- Zalamar Zealot
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127075; -- Prisoner Binding
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127177; -- High Priestess Zenja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=129335; -- Zandalari Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126930; -- Spawn of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127128; -- Bloodseeker Jo'chunga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126807; -- Obedient Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126846; -- Warspawn Rider
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128290; -- Spawn of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127223; -- Corrupted Blood
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128071; -- Tamed Warspawn
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130297; -- Glutted Bleeder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128139; -- Unworthy Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129424; -- Captive Rope Anchor Point
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=127176; -- Crawg Spawnling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126933; -- Unproven Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128426; -- Gutrip
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129311; -- Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127142; -- Zalamar Warrior
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127744; -- Magura
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126616; -- The Matron Shaazula
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130636; -- Crimsontail Moth
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128584; -- Vugthuth
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130634; -- Hookjaw Viper
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130566; -- Young Sand Sifter
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127496; -- Sandy Snapper
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=126588; -- Keula
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122664; -- Warlord Malaja
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108, `RangeAttackTime`=0 WHERE `entry`=129131; -- Zandalari Spirit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126662; -- Bound Horror
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126658; -- Shadow Stalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122666; -- Hex Priestess Tizeja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126654; -- Disciple of Tizeja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126650; -- Corrupted Acolyte
UPDATE `creature_template` SET `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=143054; -- Spectral Raven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126381; -- Stonehide Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122706; -- Theurgist Salazae
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `RangeAttackTime`=0 WHERE `entry`=122688; -- Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129010; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129755; -- Zalazane
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129657; -- Za'amar the Queen's Blade
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127764; -- Valjabu
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32848 WHERE `entry`=122754; -- Gee'dae the Cursed
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122670; -- Necropolis Guardian
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130214; -- Spectral Raven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129086; -- Vile Desecration
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126529; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=127711; -- Seeping Corruption
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=123039; -- Corrupted Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124513; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127738; -- Seeping Corruption
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127737; -- Acolyte of Tizeja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122684; -- Reanimated Horror
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126550; -- Brazier
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130246; -- Silverweb Spider
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143644; -- Goramor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129223; -- Blood Troll Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122795; -- Witch Doctor Kejabu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128701; -- Ru'ka
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129795; -- Zam'cha
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122793; -- Ouda
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130268; -- Fluttering Glowfly
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139173; -- Pterrordax Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129535; -- Ixoda Tick
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=122191; -- Du'ba
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124460; -- Mire Terror
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134420; -- Kanzim Zubo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134421; -- Tastoa Zubo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=134363; -- Drained Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124428; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129028; -- Q1 Proxy Placement
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126664; -- Doomwing Raven
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=128898; -- Drained Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134413; -- Karaja Zubo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134414; -- Wun'to Zubo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129748; -- Zandalari Spirit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127141; -- Mirehunter Juvenile
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127140; -- Mirehunter Forktongue
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128746; -- Guardian of Zo'bal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=128875; -- Drained Spirit
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130300; -- Bloodscreecher Pup
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122204; -- Blood Witch Najima
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126187; -- Corpse Bringer Yal'kar
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122636; -- Blood Bonepicker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122987; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133122; -- Nazmani Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124217; -- Raptor Patriarch
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123071; -- Blood Hunter
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131017; -- Bloodfever Tarantula
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=32784 WHERE `entry`=152126; -- Expedition Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124084; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123736; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123083; -- Razorjaw Chomper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123731; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143048; -- Elusive Skimmer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123649; -- Juvenile Raptor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130910; -- Vaza's Least Favorite Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130829; -- Vaza's Favorite Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126702; -- Primal Skyterror
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=127099; -- Urok
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135740; -- Rovash the One Eyed
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121840; -- Crazy Vaza
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135459; -- Provisioner Lija
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121638; -- Image of Krag'wa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121639; -- Image of Bwonsamdi
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=121828; -- Zabar
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125834; -- Image of Torga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121652; -- Image of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135758; -- Kuko
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121288; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121289; -- Rokhan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140513; -- Chukay
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121572; -- Listen to Talk 1
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135757; -- Kiba
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135750; -- Beastmaster Veayeka
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120903; -- Expedition Guard
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130780; -- Elusive Skimmer
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130226; -- Wetland Toad
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130224; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123655; -- Matriarch Snapjaw
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120804; -- Darkspear Scout
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127000; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126689; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120593; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=120588; -- Rivermarsh Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123654; -- Juvenile Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126723; -- Primal Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133812; -- Zanxib
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133815; -- Primal Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120587; -- Rivermarsh Raptor
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130218; -- Verdant Darter
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122434; -- Disembodied Head
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=126091; -- Defiled Embalmer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128931; -- Firebreathing Bunny
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=150412; -- Inert Voodoo Mask
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126090; -- Defiled Worshiper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126132; -- Sickly Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129576; -- Zandalari Leguaan
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143047; -- Bloodfever Tarantula
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129462; -- Juvenile Stonehide
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135567; -- Ghosts
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135557; -- Target
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130217; -- Nazmani Weevil
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122276; -- Taloc
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126107; -- Kel'vax Skeleton Shaper
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126234; -- Kel'vax's Phylactery
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=128934; -- Phylactery Guardian
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126079; -- Kol'jun Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126112; -- Kel'vax Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126113; -- Kel'vax Brute
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126191; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126146; -- Kel'vax Offering
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126150; -- Resurrected Warrior
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130205; -- Lowland Rat
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126080; -- Shinga Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126133; -- Swamp Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126117; -- Bound Scavenger
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126183; -- Leeching Grub
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129554; -- Zandalari Leguaan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129461; -- Stonehide Brutosaur


UPDATE `quest_template` SET `RewardMoney`=300720, `RewardBonusMoney`=6100, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=49406; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=150360, `RewardBonusMoney`=3050, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=48800; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=150360, `RewardBonusMoney`=3050, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=49078; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=300720, `RewardBonusMoney`=3850, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48869; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=287760, `RewardBonusMoney`=3700, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48857; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=2105408, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=48856; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=14390, `RewardBonusMoney`=370, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=50933; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=287760, `RewardBonusMoney`=3700, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=287760, `RewardBonusMoney`=5950, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=48852; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=2105409, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=14390, `RewardBonusMoney`=370, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48854; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=48890; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=2097216, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=48801; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=71940, `RewardBonusMoney`=1500, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48699; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=6299712, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=49432; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=143880, `RewardBonusMoney`=3000, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=274800, `RewardBonusMoney`=5800, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=48934; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=274800, `RewardBonusMoney`=3600, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=47247; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=49348; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=47491; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47880; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=13740, `RewardBonusMoney`=360, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=68700, `RewardBonusMoney`=1450, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49440; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=68700, `RewardBonusMoney`=1450, `FlagsEx`=2105410, `VerifiedBuild`=38134 WHERE `ID`=49278; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294606; -- 294606
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294536; -- 294536
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294482; -- 294482
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294481; -- 294481
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294480; -- 294480
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294475; -- 294475
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293184; -- 293184
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293183; -- 293183
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292919; -- 292919
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293782; -- 293782
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293083; -- 293083
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294116; -- 294116
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293039; -- 293039
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293037; -- 293037
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293035; -- 293035
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292992; -- 292992
UPDATE `quest_objectives` SET `Amount`=10, `ProgressBarWeight`=10, `VerifiedBuild`=38134 WHERE `ID`=293022; -- 293022
UPDATE `quest_objectives` SET `Amount`=20, `ProgressBarWeight`=5, `VerifiedBuild`=38134 WHERE `ID`=293021; -- 293021
UPDATE `quest_objectives` SET `Amount`=20, `ProgressBarWeight`=5, `VerifiedBuild`=38134 WHERE `ID`=293020; -- 293020
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293019; -- 293019
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294091; -- 294091
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293026; -- 293026
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293025; -- 293025
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293018; -- 293018
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292988; -- 292988
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293032; -- 293032
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293030; -- 293030
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293399; -- 293399
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294495; -- 294495
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294494; -- 294494
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292921; -- 292921
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292801; -- 292801
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294572; -- 294572
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294571; -- 294571
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290440; -- 290440
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293273; -- 293273
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293249; -- 293249
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293247; -- 293247
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293245; -- 293245
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293237; -- 293237
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290429; -- 290429
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290428; -- 290428
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294310; -- 294310
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290444; -- 290444
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292430; -- 292430
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=292426; -- 292426
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=291054; -- 291054
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=291077; -- 291077
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294593; -- 294593
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294592; -- 294592
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294164; -- 294164
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294160; -- 294160
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294154; -- 294154
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=294152; -- 294152


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293184 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293183 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292919 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293782 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293083 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294116 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293039 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292992 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293022 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293018 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292988 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293032 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294495 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294494 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292921 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292801 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294571 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290440 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290440 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293237 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293237 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293237 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293237 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294310 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=291054 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294593 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294164 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294160 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=294154 AND `Index`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123655; -- Matriarch Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126452; -- Marsh Prowler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129795; -- Zam'cha
UPDATE `creature_template` SET `type_flags`=72, `VerifiedBuild`=38134 WHERE `entry`=126460; -- Tainted Guardian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128139; -- Unworthy Sacrifice
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128701; -- Ru'ka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127040; -- Zalamar Zealot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127056; -- Zalamar Nighthunter Trainer
UPDATE `creature_template` SET `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=127060; -- Blood Crawg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122614; -- Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128746; -- Guardian of Zo'bal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127075; -- Prisoner Binding
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129311; -- Hir'eek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126529; -- Hanzabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126548; -- Spirit Fire
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129335; -- Zandalari Sacrifice
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=126550; -- Brazier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122664; -- Warlord Malaja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122666; -- Hex Priestess Tizeja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134363; -- Drained Spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122670; -- Necropolis Guardian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127128; -- Bloodseeker Jo'chunga
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127140; -- Mirehunter Forktongue
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122684; -- Reanimated Horror
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=127141; -- Mirehunter Juvenile
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127142; -- Zalamar Warrior
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122688; -- Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126588; -- Keula
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127145; -- Zalamar Bloodsinger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135507; -- Zandalari Skull
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129380; -- Wardrummer Sheej
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129381; -- Wardrummer Gix
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127711; -- Seeping Corruption
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122706; -- Theurgist Salazae
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=126606; -- Keula
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134413; -- Karaja Zubo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134414; -- Wun'to Zubo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126616; -- The Matron Shaazula
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=128290; -- Spawn of Hir'eek
UPDATE `creature_template` SET `rank`=6, `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=127176; -- Crawg Spawnling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127177; -- High Priestess Zenja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134420; -- Kanzim Zubo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134421; -- Tastoa Zubo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127737; -- Acolyte of Tizeja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127738; -- Seeping Corruption
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127744; -- Magura
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128875; -- Drained Spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122191; -- Du'ba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127764; -- Valjabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126650; -- Corrupted Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122754; -- Gee'dae the Cursed
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126654; -- Disciple of Tizeja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127212; -- Kal'dran
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124428; -- Hanzabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127215; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126658; -- Shadow Stalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127216; -- Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130001; -- Salazae's Soul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126662; -- Bound Horror
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126664; -- Doomwing Raven
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127223; -- Corrupted Blood
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130566; -- Young Sand Sifter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128898; -- Drained Spirit
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=127236; -- Crawg Spawnling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124460; -- Mire Terror
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122793; -- Ouda
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122795; -- Witch Doctor Kejabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124473; -- Abandoned Treasure
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124475; -- Shambling Ambusher
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=127268; -- Sickly Snapjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124513; -- Hanzabu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129535; -- Ixoda Tick
UPDATE `creature_template` SET `family`=296, `type_flags`=72, `VerifiedBuild`=38134 WHERE `entry`=128426; -- Gutrip
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129010; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129012; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127346; -- Skeletal Mound 01
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127349; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129028; -- Q1 Proxy Placement
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126807; -- Obedient Drudge
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130161; -- Matron Shaazula
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126823; -- Sacrificed Drudge
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127384; -- Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127391; -- Bloodseeker Jo'chunga
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127394; -- Empowered Kal'dran
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126846; -- Warspawn Rider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127407; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129086; -- Vile Desecration
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135784; -- Imperial Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130214; -- Spectral Raven
UPDATE `creature_template` SET `type_flags`=72, `VerifiedBuild`=38134 WHERE `entry`=129657; -- Za'amar the Queen's Blade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127999; -- Wardrummer Saljo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126888; -- Blood Witch Vashera
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126890; -- Blood Priestess Zu'Anji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126891; -- Blood Witch Yialu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143052; -- Returned Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143053; -- Glutted Bleeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143054; -- Spectral Raven
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129131; -- Zandalari Spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130246; -- Silverweb Spider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128584; -- Vugthuth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=139173; -- Pterrordax Spirit
UPDATE `creature_template` SET `type_flags`=73, `VerifiedBuild`=38134 WHERE `entry`=126926; -- Venomjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130268; -- Fluttering Glowfly
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126930; -- Spawn of Hir'eek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126933; -- Unproven Drudge
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143644; -- Goramor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126381; -- Stonehide Brutosaur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123039; -- Corrupted Spirit
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=127496; -- Sandy Snapper
UPDATE `creature_template` SET `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=128066; -- Engorged Crawg
UPDATE `creature_template` SET `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=128067; -- Poisoned Crawg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130297; -- Glutted Bleeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128071; -- Tamed Warspawn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128074; -- Hir'eek
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129748; -- Zandalari Spirit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129755; -- Zalazane
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126433; -- Bloodscreecher Wanderer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129779; -- Zalamar Ambusher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129223; -- Blood Troll Skull


UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=127394 AND `Idx`=0); -- Empowered Kal'dran
UPDATE `creature_template_model` SET `DisplayScale`=0.649999976158142089 WHERE (`CreatureID`=143054 AND `Idx`=0); -- Spectral Raven
UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089 WHERE (`CreatureID`=129657 AND `Idx`=0); -- Za'amar the Queen's Blade
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=143644 AND `Idx`=0); -- Goramor
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=139173 AND `Idx`=0); -- Pterrordax Spirit
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=129028 AND `Idx`=0); -- Q1 Proxy Placement


UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281695; -- Cursed Statue
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296482; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=276278; -- Skeleton Mound 01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291032; -- Blood Stain
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296502; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=292825; -- Stonebloom
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296531; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296508; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296507; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=276275; -- Spores
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295583; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295582; -- Stewpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295581; -- Stewpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296533; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296503; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295692; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295691; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295690; -- Cauldron
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=282722; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273483; -- Spear
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=275079; -- Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273487; -- Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296495; -- Brazier
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=276269; -- Blood Troll Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295590; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295589; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295588; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278497; -- Vial of Vampiric Mojo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=277264; -- Hanging Spire
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=276506; -- Mojo Brewing Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296504; -- Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278566; -- Flask of Blood Rage
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278692; -- Sarcophagus Lid
UPDATE `gameobject_template` SET `Data1`=77463, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=278401; -- Sand Shifter School
UPDATE `gameobject_template` SET `Data1`=77464, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=278403; -- Slimy Mackerel School
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270989; -- Coffin
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=278437; -- Offering to Bwonsamdi
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=292812; -- Sapphire Amaraina
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270993; -- Salazae's Urn
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270992; -- Broken Altar
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=279366; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294016; -- Sa'rii
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294012; -- Zhan
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294002; -- Ka'urt
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294001; -- Ki'mon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293994; -- Jini'fur
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294014; -- Sar'ah
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294013; -- Sa'tiib
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293993; -- E'ban
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293991; -- Ka'reez
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293990; -- A'dru
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293989; -- Er'eek
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278421; -- Queen's Mask
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278420; -- Queen's Coffin
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278419; -- Queen's Bones
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=270991; -- Ancient Urn
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294011; -- Zuteebe
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294010; -- Tre'bah
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294007; -- Ray'zon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294000; -- Jah'nii
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293999; -- Jo'shi
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293997; -- Kazerin
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293996; -- Kahti
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293995; -- Ju'ri
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293992; -- Don'ad
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=268882; -- Zandalari Spear
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293998; -- Kaymon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273773; -- Shadow Circle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273770; -- Shadow Circle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273769; -- Shadow Rune
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273768; -- Shadow Rune
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273767; -- Shadow Rune
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=271563; -- Door
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294009; -- Zah'ki
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273780; -- Ritual Candle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273778; -- Ritual Candle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=273776; -- Ritual Candle
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=272250; -- Drum of Spirits
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=270920; -- Soul Barrier
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294003; -- Rah'chil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294005; -- Michul'mon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294015; -- Rav
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294008; -- Zarah
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294006; -- Reiyon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278514; -- Kelua's Doll
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278513; -- Sarcophagus
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278501; -- Sarcophagus
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=278691; -- Sarcophagus Lid
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278502; -- Sarcophagus
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=297491; -- Tales of de Loa: Bwonsamdi
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281713; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281698; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281712; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281711; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278478; -- Stone Pedestal
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=272207; -- Graveweed


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=270991 AND `Idx`=0); -- Ancient Urn
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=272207 AND `Idx`=0); -- Graveweed


UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=580; -- 580
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32779; -- 32779
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32813; -- 32813
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32812; -- 32812
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32814; -- 32814
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33275; -- 33275
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33276; -- 33276
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32819; -- 32819
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33236; -- 33236
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32782; -- 32782
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33231; -- 33231
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32123; -- 32123
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33163; -- 33163
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34426; -- 34426
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16787;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16787;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16819;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=512, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Flags`=512, `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `Flags`=512, `Data1`=4, `Data4`=4, `VerifiedBuild`=38134 WHERE `Id`=24192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=6.5, `Data1`=6.5, `VerifiedBuild`=38134 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12967;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=20281 AND `AreaTriggerId`=24192) OR (`SpellMiscId`=20280 AND `AreaTriggerId`=24192) OR (`SpellMiscId`=20553 AND `AreaTriggerId`=24192) OR (`AreaTriggerId`=12967) OR (`AreaTriggerId`=0);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(20281, 24192, 0, 0, 0, 0, 0, 22302, 0, 0, 30000, 38134), -- SpellId : 327195
(20280, 24192, 0, 0, 0, 0, 0, 22302, 0, 0, 30000, 38134), -- SpellId : 327257
(20553, 24192, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 38134); -- SpellId : 329604

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12080 AND `AreaTriggerId`=16787); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4999, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12080 AND `AreaTriggerId`=16787); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0

UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6357 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5968 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5968 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5980 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5980 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5980 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6315 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6315 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5828 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=5142 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5944 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5975 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5784 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5909 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5909 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5909 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7676 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7676 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7676 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6275 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6275 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5802 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6255 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6255 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=5801 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5799 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5799 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5799 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5976 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5976 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=5115 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6192 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6192 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5830 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5829 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6208 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6208 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6208 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6319 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5974 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=5974 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=6419 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=58839, `VerifiedBuild`=38134 WHERE (`ConversationId`=6419 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (13056, 13010);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(13056, 0, 0, 0, 0, 38134),
(13010, 2000, 0, 1, 0, 38134);

UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14299;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13339;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13338;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13359;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13358;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13357;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14466;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14336;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13059;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11505;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14245;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14244;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14243;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14242;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14241;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13312;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13311;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14246;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14267;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13349;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13787;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13786;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13785;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13784;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13783;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12991;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13241;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13240;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13239;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17489;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17488;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17487;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14064;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14063;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13019;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13018;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13017;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13020;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14031;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14030;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=13016;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13787;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13786;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13785;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13784;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13783;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13011;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13012;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13351;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13350;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=11456;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13791;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13790;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14330;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13063;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13062;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13061;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13060;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13856;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13855;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13854;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14205;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13348;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13347;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14465;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14464;

DELETE FROM `conversation_template` WHERE `Id`=5825;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(5825, 13056, 8516, 0, 38134);

UPDATE `conversation_template` SET `LastLineEndTime`=15903, `VerifiedBuild`=38134 WHERE `Id`=6275;
UPDATE `conversation_template` SET `LastLineEndTime`=11000, `VerifiedBuild`=38134 WHERE `Id`=5976;
UPDATE `conversation_template` SET `LastLineEndTime`=4800, `VerifiedBuild`=38134 WHERE `Id`=5975;
UPDATE `conversation_template` SET `LastLineEndTime`=10150, `VerifiedBuild`=38134 WHERE `Id`=5968;
UPDATE `conversation_template` SET `LastLineEndTime`=12250, `VerifiedBuild`=38134 WHERE `Id`=6192;
UPDATE `conversation_template` SET `LastLineEndTime`=9850, `VerifiedBuild`=38134 WHERE `Id`=5974;
UPDATE `conversation_template` SET `LastLineEndTime`=46150, `VerifiedBuild`=38134 WHERE `Id`=5944;
UPDATE `conversation_template` SET `LastLineEndTime`=29600, `VerifiedBuild`=38134 WHERE `Id`=6190;
UPDATE `conversation_template` SET `LastLineEndTime`=11850, `VerifiedBuild`=38134 WHERE `Id`=5980;
UPDATE `conversation_template` SET `LastLineEndTime`=29600, `VerifiedBuild`=38134 WHERE `Id`=6190;
UPDATE `conversation_template` SET `LastLineEndTime`=14644, `VerifiedBuild`=38134 WHERE `Id`=6319;
UPDATE `conversation_template` SET `LastLineEndTime`=19991, `VerifiedBuild`=38134 WHERE `Id`=6255;
UPDATE `conversation_template` SET `LastLineEndTime`=23483, `VerifiedBuild`=38134 WHERE `Id`=7676;
UPDATE `conversation_template` SET `FirstLineID`=13061, `LastLineEndTime`=17059, `VerifiedBuild`=38134 WHERE `Id`=5830;
UPDATE `conversation_template` SET `LastLineEndTime`=7690, `VerifiedBuild`=38134 WHERE `Id`=5829;
UPDATE `conversation_template` SET `LastLineEndTime`=8312, `VerifiedBuild`=38134 WHERE `Id`=5828;
UPDATE `conversation_template` SET `LastLineEndTime`=16515, `VerifiedBuild`=38134 WHERE `Id`=6419;
UPDATE `conversation_template` SET `LastLineEndTime`=9689, `VerifiedBuild`=38134 WHERE `Id`=6315;
UPDATE `conversation_template` SET `LastLineEndTime`=12698, `VerifiedBuild`=38134 WHERE `Id`=5142;
UPDATE `conversation_template` SET `LastLineEndTime`=16602, `VerifiedBuild`=38134 WHERE `Id`=5115;
UPDATE `conversation_template` SET `LastLineEndTime`=21928, `VerifiedBuild`=38134 WHERE `Id`=5909;
UPDATE `conversation_template` SET `LastLineEndTime`=25357, `VerifiedBuild`=38134 WHERE `Id`=5802;
UPDATE `conversation_template` SET `LastLineEndTime`=12875, `VerifiedBuild`=38134 WHERE `Id`=5801;
UPDATE `conversation_template` SET `LastLineEndTime`=13315, `VerifiedBuild`=38134 WHERE `Id`=5799;
UPDATE `conversation_template` SET `LastLineEndTime`=8029, `VerifiedBuild`=38134 WHERE `Id`=5784;
UPDATE `conversation_template` SET `LastLineEndTime`=7431, `VerifiedBuild`=38134 WHERE `Id`=6357;
UPDATE `conversation_template` SET `LastLineEndTime`=17740, `VerifiedBuild`=38134 WHERE `Id`=6208;


UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=282722; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=276269; -- Blood Troll Cage
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=276506; -- Mojo Brewing Cauldron
UPDATE `gameobject_template_addon` SET `WorldEffectID`=520 WHERE `entry`=278497; -- Vial of Vampiric Mojo
UPDATE `gameobject_template_addon` SET `WorldEffectID`=520 WHERE `entry`=278566; -- Flask of Blood Rage
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=278437; -- Offering to Bwonsamdi
UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=279366; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=273768; -- Shadow Rune
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=273769; -- Shadow Rune
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=273767; -- Shadow Rune
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=3421 WHERE `entry`=270920; -- Soul Barrier
UPDATE `gameobject_template_addon` SET `flags`=5 WHERE `entry`=278691; -- Sarcophagus Lid
UPDATE `gameobject_template_addon` SET `faction`=2201 WHERE `entry`=281711; -- Mailbox

UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48890; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48801; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48869; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48856; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48857; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48854; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=48699; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49440; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47491; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47880; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=49278; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47244; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=47244; -- -Unknown-
UPDATE `quest_offer_reward` SET `VerifiedBuild`=38134 WHERE `ID`=51089; -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47244 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(47244, 0, 2, 32, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1322864, 0, 38134), -- -Unknown-
(47244, 0, 1, 0, 290562, 122204, 1642, 863, 0, 0, 0, 0, 0, 1323924, 0, 38134), -- -Unknown-
(47244, 0, 0, -1, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1344153, 0, 38134), -- -Unknown-
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=2 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=47244 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47244 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47244 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(47244, 2, 0, 1639, 1523, 26, 38134), -- -Unknown-
(47244, 1, 0, 1777, 1420, 20, 38134), -- -Unknown-
(47244, 0, 0, 1990, 1373, 16, 38134), -- -Unknown-
(31459, 0, 0, 3044, 1251, 655, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49406 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48800 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49078 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48869 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48855 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48856 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48857 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50933 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48852 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48825 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48823 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48854 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48890 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48801 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48699 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49432 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47248 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48934 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47247 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49348 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47491 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47880 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47868 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49440 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49278 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51089 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48479 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31457 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31453 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31451 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31034 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-


UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48800; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49078; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48869; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48855; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48856; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48857; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50933; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48825; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48854; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48890; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48801; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48699; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49432; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47248; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47247; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49348; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47491; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47880; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47868; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49440; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49278; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=50381;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(50381, 0, 0, 0, 0, 'You had a chat with Tik\'su about his hat yet, richmon?', 38134); -- -Unknown-

UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=48823; -- -Unknown-
UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=49491; -- -Unknown-

DELETE FROM `creature_template_addon` WHERE `entry` IN (141801 /*141801 (Little Blue)*/, 141802 /*141802 (Scars)*/, 141803 /*141803 (Delta)*/, 127744 /*127744 (Magura) - Set Health % (Uses Override Points) (No Health Regen), Blood Splatter*/, 128584 /*128584 (Vugthuth) - Vugthuth Cosmetic Skirt*/, 143054 /*143054 (Spectral Raven)*/, 152126 /*152126 (Expedition Guard)*/, 150412 /*150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura, Inert Golem Stun*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(141801, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141801 (Little Blue)
(141802, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141802 (Scars)
(141803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141803 (Delta)
(127744, 0, 0, 3, 1, 0, 0, 0, 0, '247866 167641'), -- 127744 (Magura) - Set Health % (Uses Override Points) (No Health Regen), Blood Splatter
(128584, 0, 0, 0, 1, 0, 0, 0, 0, '275108'), -- 128584 (Vugthuth) - Vugthuth Cosmetic Skirt
(143054, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 143054 (Spectral Raven)
(152126, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 152126 (Expedition Guard)
(150412, 0, 0, 0, 1, 0, 15263, 0, 0, '291587 282764'); -- 150412 (Inert Voodoo Mask) - Inert Voodoo Mask Aura; Inert Golem Stun

UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=127394; -- 127394 (Empowered Kal'dran)
UPDATE `creature_template_addon` SET `aiAnimKit`=13500 WHERE `entry`=124475; -- 124475 (Shambling Ambusher)
UPDATE `creature_template_addon` SET `aiAnimKit`=13792 WHERE `entry`=127246; -- 127246 (Empowered Totem)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126891; -- 126891 (Blood Witch Yialu)
UPDATE `creature_template_addon` SET `auras`='255220' WHERE `entry`=126888; -- 126888 (Blood Witch Vashera)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=13581, `auras`='' WHERE `entry`=126823; -- 126823 (Sacrificed Drudge)
UPDATE `creature_template_addon` SET `auras`='252155' WHERE `entry`=126807; -- 126807 (Obedient Drudge)
UPDATE `creature_template_addon` SET `aiAnimKit`=13932 WHERE `entry`=128139; -- 128139 (Unworthy Sacrifice)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=129424; -- 129424 (Captive Rope Anchor Point)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=127176; -- 127176 (Crawg Spawnling)
UPDATE `creature_template_addon` SET `aiAnimKit`=13906 WHERE `entry`=126933; -- 126933 (Unproven Drudge)
UPDATE `creature_template_addon` SET `aiAnimKit`=924 WHERE `entry`=126588; -- 126588 (Keula)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122666; -- 122666 (Hex Priestess Tizeja)
UPDATE `creature_template_addon` SET `aiAnimKit`=13582 WHERE `entry`=129755; -- 129755 (Zalazane)
UPDATE `creature_template_addon` SET `auras`='256573 257852' WHERE `entry`=122684; -- 122684 (Reanimated Horror)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122795; -- 122795 (Witch Doctor Kejabu)
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=134363; -- 134363 (Drained Spirit)
UPDATE `creature_template_addon` SET `bytes1`=1, `aiAnimKit`=0 WHERE `entry`=126664; -- 126664 (Doomwing Raven)
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=128898; -- 128898 (Drained Spirit)
UPDATE `creature_template_addon` SET `aiAnimKit`=5481 WHERE `entry`=129748; -- 129748 (Zandalari Spirit)
UPDATE `creature_template_addon` SET `aiAnimKit`=1652 WHERE `entry`=128875; -- 128875 (Drained Spirit)
UPDATE `creature_template_addon` SET `auras`='256313' WHERE `entry`=133122; -- 133122 (Nazmani Warrior)
UPDATE `creature_template_addon` SET `auras`='145363' WHERE `entry`=123071; -- 123071 (Blood Hunter)
UPDATE `creature_template_addon` SET `auras`='260422' WHERE `entry`=124084; -- 124084
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='114943' WHERE `entry`=120804; -- 120804 (Darkspear Scout)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=120593; -- 120593
UPDATE `creature_template_addon` SET `auras`='12787' WHERE `entry`=126723; -- 126723 (Primal Snapjaw)
UPDATE `creature_template_addon` SET `auras`='254493' WHERE `entry`=126091; -- 126091 (Defiled Embalmer)
UPDATE `creature_template_addon` SET `aiAnimKit`=2189 WHERE `entry`=122276; -- 122276 (Taloc)
UPDATE `creature_template_addon` SET `auras`='256644' WHERE `entry`=126112; -- 126112 (Kel'vax Warrior)
UPDATE `creature_template_addon` SET `auras`='256644' WHERE `entry`=126150; -- 126150 (Resurrected Warrior)
UPDATE `creature_template_addon` SET `auras`='105944' WHERE `entry`=126133; -- 126133 (Swamp Scavenger)


UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141801 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141802 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141799 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129779 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=129545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127385 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127294 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124473 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124475 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127351 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127298 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127348 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128943 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127350 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135784 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127384 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127255 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127247 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127216 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126452 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126460 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126433 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126926 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127215 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128067 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127268 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126890 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126891 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129536 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127391 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126888 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143053 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126823 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127056 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126807 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126846 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128290 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130297 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128139 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127176 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126933 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128426 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127142 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126616 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=128584 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127496 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=126588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126658 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126650 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143054 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=122688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129010 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129755 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129657 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127764 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130214 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129086 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126529 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123039 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127738 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=143644 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128701 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130268 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=139173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129535 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=122191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124460 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124428 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129028 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128898 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=134414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129748 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-2, `LevelScalingDeltaMax`=-2, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127140 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128746 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122204 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=152126 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123736 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130829 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121638 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=121639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=121828 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125834 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135758 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121289 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=140513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=121572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130780 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=120804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120587 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126091 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=150412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126132 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129576 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135557 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122276 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128934 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126079 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126113 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126150 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126080 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129461 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=1.110454082489013671 WHERE `DisplayID`=78162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=34418;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82919;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79123;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84283;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80057;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79367;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80061;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=34970;
UPDATE `creature_model_info` SET `BoundingRadius`=2.196302175521850585, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79803;
UPDATE `creature_model_info` SET `BoundingRadius`=1.832476615905761718, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79585;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79340;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80042;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80014;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79334;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=34417;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84398;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79335;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80058;
UPDATE `creature_model_info` SET `BoundingRadius`=1.072999954223632812, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=33736;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79333;
UPDATE `creature_model_info` SET `BoundingRadius`=1.218167662620544433, `CombatReach`=2.699999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=80047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80560;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81055;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79717;
UPDATE `creature_model_info` SET `BoundingRadius`=3.45185708999633789, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=57486;
UPDATE `creature_model_info` SET `BoundingRadius`=6.460801124572753906, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=40269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58804;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78650;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80541;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80588;
UPDATE `creature_model_info` SET `BoundingRadius`=2.071114301681518554, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=55376;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32814;
UPDATE `creature_model_info` SET `BoundingRadius`=1.938240408897399902, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=33453;
UPDATE `creature_model_info` SET `BoundingRadius`=0.966025233268737792, `CombatReach`=2.069999933242797851, `VerifiedBuild`=38134 WHERE `DisplayID`=79151;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79152;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=80459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80539;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=76729;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79230;
UPDATE `creature_model_info` SET `BoundingRadius`=6.826453208923339843, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=80851;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78719;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78720;
UPDATE `creature_model_info` SET `BoundingRadius`=0.075000002980232238, `CombatReach`=0.075000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=80457;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028887391090393066, `CombatReach`=1.539999961853027343, `VerifiedBuild`=38134 WHERE `DisplayID`=79232;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78718;
UPDATE `creature_model_info` SET `BoundingRadius`=0.622134089469909667, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=78717;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79228;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=79229;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79227;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79236;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=79306;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80538;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80540;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79856;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79126;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79127;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79265;
UPDATE `creature_model_info` SET `BoundingRadius`=0.656697094440460205, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=79169;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79171;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79272;
UPDATE `creature_model_info` SET `BoundingRadius`=0.656697094440460205, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=79170;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79129;
UPDATE `creature_model_info` SET `BoundingRadius`=1.725928544998168945, `VerifiedBuild`=38134 WHERE `DisplayID`=67783;
UPDATE `creature_model_info` SET `BoundingRadius`=0.622134089469909667, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79172;
UPDATE `creature_model_info` SET `BoundingRadius`=2.416299819946289062, `CombatReach`=1.399999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=81162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.955395400524139404, `CombatReach`=1.429999947547912597, `VerifiedBuild`=38134 WHERE `DisplayID`=79305;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80461;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82832;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79174;
UPDATE `creature_model_info` SET `BoundingRadius`=0.955395400524139404, `CombatReach`=1.429999947547912597, `VerifiedBuild`=38134 WHERE `DisplayID`=79304;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79173;
UPDATE `creature_model_info` SET `BoundingRadius`=2.204758644104003906, `CombatReach`=3.300000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=79919;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79273;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382499992847442626, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=79562;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399305284023284912, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=79010;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19986;
UPDATE `creature_model_info` SET `BoundingRadius`=10.7612762451171875, `CombatReach`=15, `VerifiedBuild`=38134 WHERE `DisplayID`=66284;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=2956;
UPDATE `creature_model_info` SET `BoundingRadius`=0.292758256196975708, `CombatReach`=0.375, `VerifiedBuild`=38134 WHERE `DisplayID`=79015;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75372;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=76975;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80399;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80397;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80398;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=76966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.700529217720031738, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=79028;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79027;
UPDATE `creature_model_info` SET `BoundingRadius`=6.851508140563964843, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=78991;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=76984;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75961;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=80847;
UPDATE `creature_model_info` SET `BoundingRadius`=3.053412199020385742, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=80186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79589;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520833015441894531, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=77012;
UPDATE `creature_model_info` SET `BoundingRadius`=3.41694188117980957, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=81103;
UPDATE `creature_model_info` SET `BoundingRadius`=1.026381731033325195, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=81076;
UPDATE `creature_model_info` SET `BoundingRadius`=0.425056040287017822, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=15136;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80371;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80758;
UPDATE `creature_model_info` SET `BoundingRadius`=0.636844754219055175, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80770;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80773;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81077;
UPDATE `creature_model_info` SET `BoundingRadius`=0.636844754219055175, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79026;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80755;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80756;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42365;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80757;
UPDATE `creature_model_info` SET `BoundingRadius`=10.27726173400878906, `CombatReach`=3.599999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=78698;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80446;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80866;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41766;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81376;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80462;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01109480857849121, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=86174;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80458;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80838;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80839;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80610;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83585;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83586;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80837;
UPDATE `creature_model_info` SET `BoundingRadius`=1.026381731033325195 WHERE `DisplayID`=32546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.227821439504623413, `VerifiedBuild`=38134 WHERE `DisplayID`=78995;
UPDATE `creature_model_info` SET `BoundingRadius`=0.175650030374526977, `VerifiedBuild`=38134 WHERE `DisplayID`=83583;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80840;
UPDATE `creature_model_info` SET `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=81238;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77494;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=80855;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.517778575420379638, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=65547;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75864;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75865;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=76764;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=78779;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45494;
UPDATE `creature_model_info` SET `BoundingRadius`=0.532049536705017089, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=82571;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75892;
UPDATE `creature_model_info` SET `BoundingRadius`=2.565691709518432617, `CombatReach`=1.949999928474426269 WHERE `DisplayID`=83645;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76728;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=60235;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84377;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75970;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84261;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434027493000030517, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=79274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=81218;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75969;
UPDATE `creature_model_info` SET `BoundingRadius`=0.293149083852767944, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=83640;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47990;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84381;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=0.625, `VerifiedBuild`=38134 WHERE `DisplayID`=44656;
UPDATE `creature_model_info` SET `BoundingRadius`=0.240000009536743164, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=47989;
UPDATE `creature_model_info` SET `BoundingRadius`=4.03800058364868164, `CombatReach`=3.75, `VerifiedBuild`=38134 WHERE `DisplayID`=77504;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75968;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75967;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78936;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77503;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121 WHERE `DisplayID`=78161;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33451;
UPDATE `creature_model_info` SET `BoundingRadius`=1.938240408897399902, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=33450;
UPDATE `creature_model_info` SET `BoundingRadius`=2.960413694381713867, `CombatReach`=2.25 WHERE `DisplayID`=83646;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=75850;
UPDATE `creature_model_info` SET `BoundingRadius`=1.973609089851379394, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83649;
UPDATE `creature_model_info` SET `BoundingRadius`=0.410187005996704101, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=58745;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.373770296573638916, `CombatReach`=0.1875, `VerifiedBuild`=38134 WHERE `DisplayID`=77652;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78727;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `VerifiedBuild`=38134 WHERE `DisplayID`=91019;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79980;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78131;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342625141143798828, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.373770296573638916, `CombatReach`=0.1875, `VerifiedBuild`=38134 WHERE `DisplayID`=45908;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79979;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78726;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80611;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79978;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77483;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78723;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81377;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85386;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79975;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=24889;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78692;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79977;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82573;
UPDATE `creature_model_info` SET `BoundingRadius`=1.425259590148925781, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78722;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78693;
UPDATE `creature_model_info` SET `BoundingRadius`=0.85839998722076416, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78737;
UPDATE `creature_model_info` SET `BoundingRadius`=0.150000005960464477, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=9904;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77485;

DELETE FROM `npc_vendor` WHERE (`entry`=32641 AND `item`=183950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183954 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=183955 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32641 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32641, 15, 183950, 0, 0, 1, 0, 0, 38134), -- Distilled Death Extract
(32641, 14, 180733, 0, 0, 1, 0, 0, 38134), -- Luminous Flux
(32641, 13, 183951, 0, 0, 1, 0, 0, 38134), -- Immortal Shard
(32641, 12, 183952, 0, 0, 1, 0, 0, 38134), -- Machinist's Oil
(32641, 11, 183953, 0, 0, 1, 0, 0, 38134), -- Sealing Wax
(32641, 10, 183954, 0, 0, 1, 0, 0, 38134), -- Malleable Wire
(32641, 9, 183955, 0, 0, 1, 0, 0, 38134), -- Curing Salt
(32641, 8, 6219, 0, 0, 1, 0, 0, 38134); -- Arclight Spanner

UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1); -- Simple Dagger
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=32641 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=122793 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (127744,126529,124513,124428,152126));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(127744, 1, 94681, 0, 0, 152892, 0, 0, 0, 0, 0), -- Magura
(126529, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(124513, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(124428, 1, 147908, 0, 0, 0, 0, 0, 0, 0, 0), -- Hanzabu
(152126, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0); -- Expedition Guard

UPDATE `creature_equip_template` SET `ItemID1`=106945, `ItemID3`=0 WHERE (`CreatureID`=129545 AND `ID`=1); -- Bwonsamdi
UPDATE `creature_equip_template` SET `ItemID1`=116485 WHERE (`CreatureID`=133122 AND `ID`=2); -- Nazmani Warrior
UPDATE `creature_equip_template` SET `ItemID1`=153589 WHERE (`CreatureID`=133122 AND `ID`=1); -- Nazmani Warrior


UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=83 AND `TextId`=580); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32779); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32779); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `TextId`=32813); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `TextId`=32813); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `TextId`=32812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `TextId`=32814); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `TextId`=32814); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21785 AND `TextId`=33275); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21787 AND `TextId`=33276); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21786 AND `TextId`=33276); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21533 AND `TextId`=32819); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21766 AND `TextId`=33236); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21530 AND `TextId`=32782); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `TextId`=33231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `TextId`=33231); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21177 AND `TextId`=32123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21736 AND `TextId`=33163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21736 AND `TextId`=33163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21736 AND `TextId`=33163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `TextId`=34426); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `TextId`=34426); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `TextId`=34426); -- 0

UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=83 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138526, `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138526, `VerifiedBuild`=38134 WHERE (`MenuId`=21528 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=138500, `VerifiedBuild`=38134 WHERE (`MenuId`=21527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136975, `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136975, `VerifiedBuild`=38134 WHERE (`MenuId`=21529 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140514, `VerifiedBuild`=38134 WHERE (`MenuId`=21785 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140518, `VerifiedBuild`=38134 WHERE (`MenuId`=21787 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140516, `VerifiedBuild`=38134 WHERE (`MenuId`=21786 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=140031, `VerifiedBuild`=38134 WHERE (`MenuId`=21766 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=136986, `VerifiedBuild`=38134 WHERE (`MenuId`=21530 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=139727, `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=139727, `VerifiedBuild`=38134 WHERE (`MenuId`=21762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22439 AND `OptionIndex`=0);

UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141801; -- Little Blue
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141802; -- Scars
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141803; -- Delta
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=141799; -- Grady Prett
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126833; -- Blind Wunja
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135507; -- Zandalari Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129779; -- Zalamar Ambusher
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129545; -- Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=127394; -- Empowered Kal'dran
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127385; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=127225; -- Hexxer Nana'kwug
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127294; -- Sickly Saurid
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143052; -- Returned Hatchling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124473; -- Abandoned Treasure
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124475; -- Shambling Ambusher
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127351; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=127298; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127348; -- Skeletal Mound 03
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128943; -- Zardrax Release Power Point
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127253; -- Reconstructed Terror
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127350; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127347; -- Skeletal Mound 02
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127245; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127246; -- Empowered Totem
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127349; -- Image of Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127346; -- Skeletal Mound 01
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127357; -- Skeletal Mound
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130347; -- Returned Hatchling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135784; -- Imperial Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127384; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127255; -- Zardrax Conduit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127247; -- Returned Predator
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127224; -- Empowered Worshipper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127216; -- Zardrax the Empowerer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129380; -- Wardrummer Sheej
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126452; -- Marsh Prowler
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126460; -- Tainted Guardian
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130199; -- Boghopper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127999; -- Wardrummer Saljo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128066; -- Engorged Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126433; -- Bloodscreecher Wanderer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126926; -- Venomjaw
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127212; -- Kal'dran
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127215; -- Shadow Hunter Da'jul
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128067; -- Poisoned Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129381; -- Wardrummer Gix
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127265; -- Bloodscreecher Broodling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127267; -- Sickly Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127268; -- Sickly Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126890; -- Blood Priestess Zu'Anji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126891; -- Blood Witch Yialu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129536; -- Marsh Feaster
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127145; -- Zalamar Bloodsinger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127391; -- Bloodseeker Jo'chunga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126888; -- Blood Witch Vashera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128074; -- Hir'eek
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143053; -- Glutted Bleeder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127060; -- Blood Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126823; -- Sacrificed Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127056; -- Zalamar Nighthunter Trainer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127040; -- Zalamar Zealot
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127075; -- Prisoner Binding
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127177; -- High Priestess Zenja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=129335; -- Zandalari Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126930; -- Spawn of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127128; -- Bloodseeker Jo'chunga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126807; -- Obedient Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126846; -- Warspawn Rider
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128290; -- Spawn of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127223; -- Corrupted Blood
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128071; -- Tamed Warspawn
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130297; -- Glutted Bleeder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128139; -- Unworthy Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129424; -- Captive Rope Anchor Point
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=127176; -- Crawg Spawnling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126933; -- Unproven Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128426; -- Gutrip
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129311; -- Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127142; -- Zalamar Warrior
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127744; -- Magura
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126616; -- The Matron Shaazula
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130636; -- Crimsontail Moth
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128584; -- Vugthuth
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130634; -- Hookjaw Viper
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130566; -- Young Sand Sifter
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127496; -- Sandy Snapper
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=126588; -- Keula
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122664; -- Warlord Malaja
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108, `RangeAttackTime`=0 WHERE `entry`=129131; -- Zandalari Spirit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126662; -- Bound Horror
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126658; -- Shadow Stalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122666; -- Hex Priestess Tizeja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126654; -- Disciple of Tizeja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126650; -- Corrupted Acolyte
UPDATE `creature_template` SET `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=143054; -- Spectral Raven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126381; -- Stonehide Brutosaur
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122706; -- Theurgist Salazae
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `RangeAttackTime`=0 WHERE `entry`=122688; -- Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129010; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129755; -- Zalazane
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129657; -- Za'amar the Queen's Blade
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127764; -- Valjabu
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32848 WHERE `entry`=122754; -- Gee'dae the Cursed
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122670; -- Necropolis Guardian
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130214; -- Spectral Raven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129086; -- Vile Desecration
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126529; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=127711; -- Seeping Corruption
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=123039; -- Corrupted Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124513; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=127738; -- Seeping Corruption
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127737; -- Acolyte of Tizeja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122684; -- Reanimated Horror
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126550; -- Brazier
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130246; -- Silverweb Spider
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143644; -- Goramor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129223; -- Blood Troll Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122795; -- Witch Doctor Kejabu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128701; -- Ru'ka
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129795; -- Zam'cha
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122793; -- Ouda
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130268; -- Fluttering Glowfly
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139173; -- Pterrordax Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129535; -- Ixoda Tick
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=122191; -- Du'ba
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124460; -- Mire Terror
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134420; -- Kanzim Zubo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134421; -- Tastoa Zubo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=134363; -- Drained Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124428; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129028; -- Q1 Proxy Placement
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126664; -- Doomwing Raven
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=128898; -- Drained Spirit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134413; -- Karaja Zubo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134414; -- Wun'to Zubo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129748; -- Zandalari Spirit
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127141; -- Mirehunter Juvenile
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127140; -- Mirehunter Forktongue
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128746; -- Guardian of Zo'bal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=128875; -- Drained Spirit
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130300; -- Bloodscreecher Pup
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122204; -- Blood Witch Najima
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126187; -- Corpse Bringer Yal'kar
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122636; -- Blood Bonepicker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122987; -- Hanzabu
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133122; -- Nazmani Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124217; -- Raptor Patriarch
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123071; -- Blood Hunter
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131017; -- Bloodfever Tarantula
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=32784 WHERE `entry`=152126; -- Expedition Guard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124084; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123736; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123083; -- Razorjaw Chomper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123731; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143048; -- Elusive Skimmer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123649; -- Juvenile Raptor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130910; -- Vaza's Least Favorite Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130829; -- Vaza's Favorite Skull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126702; -- Primal Skyterror
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=127099; -- Urok
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135740; -- Rovash the One Eyed
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121840; -- Crazy Vaza
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135459; -- Provisioner Lija
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121638; -- Image of Krag'wa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121639; -- Image of Bwonsamdi
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=121828; -- Zabar
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125834; -- Image of Torga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121652; -- Image of Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135758; -- Kuko
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121288; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121289; -- Rokhan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140513; -- Chukay
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=121572; -- Listen to Talk 1
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135757; -- Kiba
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135750; -- Beastmaster Veayeka
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120903; -- Expedition Guard
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130780; -- Elusive Skimmer
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130226; -- Wetland Toad
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130224; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123655; -- Matriarch Snapjaw
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120804; -- Darkspear Scout
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127000; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126689; -- Sickly Saurid
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120593; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=120588; -- Rivermarsh Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123654; -- Juvenile Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126723; -- Primal Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133812; -- Zanxib
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133815; -- Primal Snapjaw
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120587; -- Rivermarsh Raptor
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130218; -- Verdant Darter
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122434; -- Disembodied Head
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=126091; -- Defiled Embalmer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128931; -- Firebreathing Bunny
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=150412; -- Inert Voodoo Mask
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126090; -- Defiled Worshiper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126132; -- Sickly Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129576; -- Zandalari Leguaan
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143047; -- Bloodfever Tarantula
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129462; -- Juvenile Stonehide
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135567; -- Ghosts
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135557; -- Target
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130217; -- Nazmani Weevil
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122276; -- Taloc
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126107; -- Kel'vax Skeleton Shaper
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126234; -- Kel'vax's Phylactery
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=128934; -- Phylactery Guardian
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126079; -- Kol'jun Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126112; -- Kel'vax Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=4 WHERE `entry`=126113; -- Kel'vax Brute
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126191; -- Servant of Bwonsamdi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126146; -- Kel'vax Offering
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126150; -- Resurrected Warrior
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130205; -- Lowland Rat
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126080; -- Shinga Deathwalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126133; -- Swamp Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126117; -- Bound Scavenger
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126183; -- Leeching Grub
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129554; -- Zandalari Leguaan
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129461; -- Stonehide Brutosaur

