DELETE FROM `areatrigger_template` WHERE `Id` IN (11204, 11627, 11109, 12356, 12456, 10827, 10826, 12600, 12638, 12637, 11875, 10926, 11124, 12120, 12724, 12678, 10916, 10947, 11556, 11496, 12376, 9660, 12015, 13355, 10914, 10936, 9575);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(11204, 0, 0, 8, 8, 0, 0, 0, 0, 26365),
(11627, 0, 0, 1, 1, 0, 0, 0, 0, 26365),
(11109, 4, 6, 6.5, 6.5, 6, 6, 0.3, 0.3, 26365),
(12356, 4, 0, 3, 3, 4, 4, 0.3, 0.3, 26365),
(12456, 0, 0, 1, 1, 0, 0, 0, 0, 26365),
(10827, 0, 0, 4, 4, 0, 0, 0, 0, 26365),
(10826, 0, 0, 4, 4, 0, 0, 0, 0, 26365),
(12600, 0, 0, 6, 6, 0, 0, 0, 0, 26365),
(12638, 0, 0, 4, 4, 0, 0, 0, 0, 26365),
(12637, 3, 0, 0, 0, 0, 0, 0, 0, 26365),
(11875, 0, 0, 4, 4, 0, 0, 0, 0, 26365),
(10926, 0, 0, 2, 2, 0, 0, 0, 0, 26365),
(11124, 0, 0, 10, 10, 0, 0, 0, 0, 26365),
(12120, 0, 0, 8, 8, 0, 0, 0, 0, 26365),
(12724, 0, 0, 4.5, 4.5, 0, 0, 0, 0, 26365),
(12678, 0, 0, 3, 3, 0, 0, 0, 0, 26365),
(10916, 0, 2, 0.2, 0.2, 0, 0, 0, 0, 26365),
(10947, 4, 4, 5, 5, 4, 4, 0.3, 0.3, 26365),
(11556, 0, 0, 7, 7, 0, 0, 0, 0, 26365),
(11496, 0, 0, 5, 5, 0, 0, 0, 0, 26365),
(12376, 0, 0, 5, 5, 0, 0, 0, 0, 26365),
(9660, 0, 66, 14, 14, 0, 0, 0, 0, 26365),
(12015, 0, 4, 10, 10, 0, 0, 0, 0, 26365),
(13355, 0, 32, 1, 1, 0, 0, 0, 0, 26365),
(10914, 0, 0, 10, 10, 0, 0, 0, 0, 26365),
(10936, 0, 2, 1, 12, 0, 0, 0, 0, 26365),
(9575, 3, 4, 0, 0, 0, 0, 0, 0, 26365);


UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=1, `Data1`=1, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=0, `Data0`=1, `Data1`=1, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Flags`=2 WHERE `Id`=9482;
UPDATE `areatrigger_template` SET `Flags`=2 WHERE `Id`=9482;


DELETE FROM `areatrigger_template_polygon_vertices` WHERE (`AreaTriggerId`=9575 AND `Idx`=3) OR (`AreaTriggerId`=9575 AND `Idx`=2) OR (`AreaTriggerId`=9575 AND `Idx`=1) OR (`AreaTriggerId`=9575 AND `Idx`=0) OR (`AreaTriggerId`=12637 AND `Idx`=3) OR (`AreaTriggerId`=12637 AND `Idx`=2) OR (`AreaTriggerId`=12637 AND `Idx`=1) OR (`AreaTriggerId`=12637 AND `Idx`=0);
INSERT INTO `areatrigger_template_polygon_vertices` (`AreaTriggerId`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(9575, 3, 100, 6.5, 100, 6.5, 26365),
(9575, 2, 100, -6.5, 100, 6.5, 26365),
(9575, 1, 0, -6.5, 0, -6.5, 26365),
(9575, 0, 0, 6.5, 0, -6.5, 26365),
(12637, 3, 0.75, 4, 0, -6.5, 26365),
(12637, 2, 0.75, -4, 0, -6.5, 26365),
(12637, 1, -0.75, -4, 0, -6.5, 26365),
(12637, 0, -0.75, 4, 0, -6.5, 26365);

DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=11781) OR (`SpellMiscId`=7802 AND `AreaTriggerId`=12120) OR (`SpellMiscId`=10085 AND `AreaTriggerId`=10202) OR (`SpellMiscId`=10084 AND `AreaTriggerId`=10202) OR (`SpellMiscId`=10083 AND `AreaTriggerId`=10202) OR (`SpellMiscId`=8430 AND `AreaTriggerId`=6197) OR (`SpellMiscId`=8624 AND `AreaTriggerId`=12724) OR (`SpellMiscId`=8539 AND `AreaTriggerId`=12678) OR (`SpellMiscId`=6616 AND `AreaTriggerId`=11204) OR (`SpellMiscId`=7175 AND `AreaTriggerId`=11627) OR (`SpellMiscId`=8284 AND `AreaTriggerId`=6197) OR (`SpellMiscId`=6216 AND `AreaTriggerId`=10916) OR (`SpellMiscId`=6484 AND `AreaTriggerId`=11109) OR (`SpellMiscId`=6249 AND `AreaTriggerId`=10947) OR (`SpellMiscId`=8129 AND `AreaTriggerId`=12356) OR (`SpellMiscId`=6146 AND `AreaTriggerId`=10827) OR (`SpellMiscId`=6145 AND `AreaTriggerId`=10826) OR (`AreaTriggerId`=0) OR (`SpellMiscId`=8449 AND `AreaTriggerId`=12600) OR (`SpellMiscId`=8485 AND `AreaTriggerId`=12638) OR (`SpellMiscId`=8484 AND `AreaTriggerId`=12637) OR (`SpellMiscId`=7432 AND `AreaTriggerId`=11875) OR (`SpellMiscId`=6226 AND `AreaTriggerId`=10926) OR (`SpellMiscId`=8149 AND `AreaTriggerId`=12376) OR (`SpellMiscId`=12015 AND `AreaTriggerId`=16725) OR (`SpellMiscId`=4943 AND `AreaTriggerId`=9660) OR (`SpellMiscId`=5428 AND `AreaTriggerId`=6197) OR (`SpellMiscId`=9865 AND `AreaTriggerId`=6197) OR (`SpellMiscId`=7614 AND `AreaTriggerId`=12015) OR (`SpellMiscId`=6214 AND `AreaTriggerId`=10914) OR (`SpellMiscId`=6238 AND `AreaTriggerId`=10936) OR (`SpellMiscId`=3938 AND `AreaTriggerId`=9575) OR (`SpellMiscId`=7088 AND `AreaTriggerId`=11556) OR (`SpellMiscId`=7025 AND `AreaTriggerId`=11496) OR (`SpellMiscId`=6505 AND `AreaTriggerId`=11124);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
-- (UNKNOWN, 11781, 0, 0, 0, 0, 0, 1251, 10000, 26365), -- SpellId : 215058
(7802, 12120, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 218927
(10085, 10202, 0, 0, 0, 0, 145, 0, 2800, 26365), -- SpellId : 239553
(10084, 10202, 0, 0, 0, 0, 145, 0, 2800, 26365), -- SpellId : 239552
(10083, 10202, 0, 0, 0, 0, 145, 0, 2800, 26365), -- SpellId : 239551
(8430, 6197, 0, 0, 0, 0, 70, 0, 1000, 26365), -- SpellId : 224399
(8624, 12724, 0, 0, 0, 0, 0, 0, 30000, 26365), -- SpellId : 225858
(8539, 12678, 0, 0, 0, 0, 0, 0, 20000, 26365), -- SpellId : 224194
(6616, 11204, 0, 0, 0, 0, 0, 0, 600000, 26365), -- SpellId : 209500
(7175, 11627, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 213956
(8284, 6197, 0, 0, 0, 0, 0, 0, 5000, 26365), -- SpellId : 223114
(6216, 10916, 0, 0, 0, 0, 84, 0, 3000, 26365), -- SpellId : 206399
(6484, 11109, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 208666
(6249, 10947, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 206585
(8129, 12356, 0, 0, 0, 0, 0, 5176, 30000, 26365), -- SpellId : 221552
(6146, 10827, 0, 0, 0, 0, 0, 0, 5200, 26365), -- SpellId : 205881
(6145, 10826, 0, 0, 0, 0, 0, 0, 5200, 26365), -- SpellId : 205880
-- (UNKNOWN, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 0
(8449, 12600, 0, 0, 0, 0, 0, 0, 8000, 26365), -- SpellId : 224570
(8485, 12638, 0, 0, 0, 0, 0, 0, 30000, 26365), -- SpellId : 224976
-- (UNKNOWN, 12456, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 0
(8484, 12637, 0, 0, 0, 0, 0, 11600, 20000, 26365), -- SpellId : 224972
(7432, 11875, 0, 0, 0, 0, 0, 0, 30000, 26365), -- SpellId : 216026
(6226, 10926, 0, 0, 0, 0, 0, 0, 10000, 26365), -- SpellId : 206462
(8149, 12376, 0, 0, 0, 0, 10, 0, 30000, 26365), -- SpellId : 221605
(12015, 16725, 0, 0, 0, 0, 0, 0, 12000, 26365), -- SpellId : 256823
-- (UNKNOWN, 5300, 392, 0, 0, 0, 0, 1334, 1000, 26365), -- SpellId : 123986
-- (UNKNOWN, 5302, 393, 0, 0, 0, 0, 1334, 1000, 26365), -- SpellId : 123986
(4943, 9660, 0, 0, 0, 0, 0, 0, 3600000, 26365), -- SpellId : 206939
(5428, 6197, 0, 0, 0, 0, 0, 0, 0, 26365), -- SpellId : 151120
(9865, 6197, 0, 0, 0, 0, 0, 2693, 3000, 26365), -- SpellId : 228642
(7614, 12015, 0, 0, 0, 0, 0, 0, 6000, 26365), -- SpellId : 217830
-- (UNKNOWN, 13355, 0, 0, 0, 0, 0, 3000, 3000, 26365), -- SpellId : 227753
(6214, 10914, 0, 0, 0, 0, 0, 0, 600000, 26365), -- SpellId : 209086
(6238, 10936, 0, 0, 1791, 0, 0, 0, 180000, 26365), -- SpellId : 206581
-- (UNKNOWN, 6197, 0, 0, 0, 0, 0, 6000, 6000, 26365), -- SpellId : 227696
(3938, 9575, 0, 0, 0, 0, 0, 0, 6000, 26365), -- SpellId : 206514
(7088, 11556, 0, 0, 0, 0, 0, 0, 120000, 26365), -- SpellId : 213276
(7025, 11496, 0, 0, 0, 0, 0, 0, 600000, 26365), -- SpellId : 212734
(6505, 11124, 0, 0, 0, 0, 0, 0, 70000, 26365); -- SpellId : 209881

DELETE FROM `conversation_line_template` WHERE `Id` IN (6413, 6412, 6411, 6410, 6819, 8706, 6818, 6817, 6816, 8190, 8189, 8188, 8187, 4304, 4303, 4302, 4301, 4300, 4299, 4308, 4307, 4306, 4305);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(6413, 5804, 0, 0, 0, 26365),
(6412, 0, 0, 0, 0, 26365),
(6411, 6184, 693732103, 0, 0, 26365),
(6410, 0, 693732103, 0, 0, 26365),
(6819, 27730, 39951, 256, 0, 26365),
(8706, 20023, 39951, 0, 0, 26365),
(6818, 13784, 39951, 0, 0, 26365),
(6817, 6955, 39951, 0, 0, 26365),
(6816, 0, 39951, 256, 0, 26365),
(8190, 13900, 1345847299, 2, 0, 26365),
(8189, 5600, 1345847299, 1, 0, 26365),
(8188, 3000, 1345847299, 1, 0, 26365),
(8187, 0, 1345847299, 256, 0, 26365),
(4304, 58000, 0, 0, 0, 26365),
(4303, 44000, 0, 0, 0, 26365),
(4302, 34000, 0, 0, 0, 26365),
(4301, 21000, 0, 0, 0, 26365),
(4300, 10000, 0, 0, 0, 26365),
(4299, 0, 0, 0, 0, 26365),
(4308, 30699, 915163584, 0, 0, 26365),
(4307, 19824, 915163584, 0, 0, 26365),
(4306, 8935, 915163584, 0, 0, 26365),
(4305, 0, 915163584, 0, 0, 26365);


DELETE FROM `conversation_template` WHERE `Id` IN (3232, 3031, 3030, 2040, 3637, 2041);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(3232, 6816, 27730, 26365),
(3031, 6412, 10391, 26365),
(3030, 6410, 13593, 26365),
(2040, 4299, 68000, 26365),
(3637, 8187, 17450, 26365),
(2041, 4305, 44641, 26365);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (266483 /*Gift of the Nightborne*/, 251259 /*Cylinder Collision*/, 250082 /*Eye of Amun'thul*/, 253128 /*Instance Portal*/, 266959 /*Containment Field*/, 251833 /*Botanist Door Left*/, 251832 /*Botanist Door Right*/, 258848 /*Doodad_7NB_NIGHTBORN_CITYTELEPORTER003*/, 255928 /*Doodad_7NB_NIGHTBORN_CITYTELEPORTER002*/, 254240 /*Sealed Door*/, 247973 /*Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN*/, 247972 /*Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN*/, 247971 /*Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN*/, 247970 /*Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN*/, 252322 /*Doodad_7sr_suramar_nightwellfx002*/, 252349 /*Anomaly Entrance*/, 252348 /*Anomaly Exit*/, 253989 /*Doodad_7DU_SuramarRaid_CourtyardGate002*/, 253924 /*Dreadlord Door*/, 248513 /*Felbound Chest*/, 251401 /*Doodad_7DU_SuramarRaid_Astrodome001*/, 251397 /*Trilliax Portcullis Entrance*/, 251398 /*Trilliax Portcullis Entrance*/, 252105 /*Arcane-imbued Wood Door*/, 252103 /*Arcane-imbued Wood Door*/, 251519 /*Nightwell Door*/, 252435 /*Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001*/, 266173 /*Doodad_7DU_SuramarRaid_Door_med001*/, 250241 /*Trilliax Portcullis 01*/, 250243 /*Trilliax Portcullis Exit*/, 250242 /*Trilliax Portcullis 02*/, 251984 /*Doodad_7DU_SuramarRaid_Door_med008*/, 252318 /*The Eye of Aman'thul*/, 251684 /*Doodad_7DU_SuramarRaid_Door_med006*/, 251687 /*Dreadlord Door*/, 251686 /*Dreadlord Door*/, 251683 /*Doodad_7DU_SuramarRaid_Door_med005*/, 252321 /*Nighthold Focusing Statue*/, 253988 /*Doodad_7DU_SuramarRaid_CourtyardGate001*/, 253178 /*Balcony Door*/, 253923 /*Dreadlord Door*/, 266395 /*The Eye of Aman'thul*/, 248932 /*Doodad_7NE_Nightelf_AcademyDoor001*/, 254241 /*Portcullis*/, 266174 /*The Eye of Aman'thul*/, 266181 /*Statue Energy Conduit*/, 266180 /*Statue Energy Conduit*/, 266183 /*Statue Energy Conduit*/, 266182 /*Statue Energy Conduit*/, 260985 /*The Eye of Aman'thul*/, 251983 /*Doodad_7DU_SuramarRaid_Door_Large003*/, 253462 /*Platform*/, 251988 /*Nighthold Focusing Statue*/, 252319 /*Nighthold Focusing Statue*/, 251685 /*Doodad_7DU_SuramarRaid_Door_med007*/, 252320 /*Nighthold Focusing Statue*/, 258847 /*Door*/, 254243 /*Observatory Door*/, 254242 /*Observatory Door*/, 255925 /*Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001*/, 251981 /*Doodad_7DU_SuramarRaid_Door_Large001*/, 252315 /*Doodad_7DU_SuramarRaid_Door_Small012*/, 251609 /*Chamber Door*/, 251608 /*Doodad_7DU_SuramarRaid_Door_Small001*/, 255926 /*Doodad_7NB_NIGHTBORN_CITYTELEPORTER001*/, 251982 /*Doodad_7DU_SuramarRaid_Door_Large002*/, 266835 /*Nightborne Teleporter*/, 258843 /*Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003*/, 251612 /*Doodad_7DU_SuramarRaid_Door_Small007*/, 255927 /*Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002*/, 252316 /*Doodad_7DU_SuramarRaid_Door_Small013*/, 251611 /*Chamber Door*/, 251610 /*Doodad_7DU_SuramarRaid_Door_Small005*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(266483, 94, 16416), -- Gift of the Nightborne
(251259, 16, 32), -- Cylinder Collision
(250082, 16, 48), -- Eye of Amun'thul
(253128, 0, 32), -- Instance Portal
(266959, 0, 16), -- Containment Field
(251833, 1375, 48), -- Botanist Door Left
(251832, 1375, 48), -- Botanist Door Right
(258848, 1375, 16), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER003
(255928, 1375, 16), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER002
(254240, 0, 34), -- Sealed Door
(247973, 0, 1048624), -- Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN
(247972, 0, 1048624), -- Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN
(247971, 0, 1048624), -- Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN
(247970, 0, 1048624), -- Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN
(252322, 0, 32), -- Doodad_7sr_suramar_nightwellfx002
(252349, 1375, 32), -- Anomaly Entrance
(252348, 1375, 32), -- Anomaly Exit
(253989, 1375, 48), -- Doodad_7DU_SuramarRaid_CourtyardGate002
(253924, 1375, 48), -- Dreadlord Door
(248513, 94, 2113568), -- Felbound Chest
(251401, 0, 4194352), -- Doodad_7DU_SuramarRaid_Astrodome001
(251397, 1375, 32), -- Trilliax Portcullis Entrance
(251398, 1375, 32), -- Trilliax Portcullis Entrance
(252105, 0, 48), -- Arcane-imbued Wood Door
(252103, 0, 48), -- Arcane-imbued Wood Door
(251519, 1375, 32), -- Nightwell Door
(252435, 1375, 4194352), -- Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001
(266173, 1375, 48), -- Doodad_7DU_SuramarRaid_Door_med001
(250241, 0, 48), -- Trilliax Portcullis 01
(250243, 0, 48), -- Trilliax Portcullis Exit
(250242, 0, 48), -- Trilliax Portcullis 02
(251984, 1375, 48), -- Doodad_7DU_SuramarRaid_Door_med008
(252318, 0, 48), -- The Eye of Aman'thul
(251684, 1375, 50), -- Doodad_7DU_SuramarRaid_Door_med006
(251687, 1375, 48), -- Dreadlord Door
(251686, 1375, 48), -- Dreadlord Door
(251683, 1375, 48), -- Doodad_7DU_SuramarRaid_Door_med005
(252321, 0, 48), -- Nighthold Focusing Statue
(253988, 1375, 48), -- Doodad_7DU_SuramarRaid_CourtyardGate001
(253178, 1375, 48), -- Balcony Door
(253923, 1375, 48), -- Dreadlord Door
(266395, 0, 48), -- The Eye of Aman'thul
(248932, 0, 48), -- Doodad_7NE_Nightelf_AcademyDoor001
(254241, 0, 32), -- Portcullis
(266174, 0, 48), -- The Eye of Aman'thul
(266181, 0, 48), -- Statue Energy Conduit
(266180, 0, 48), -- Statue Energy Conduit
(266183, 0, 48), -- Statue Energy Conduit
(266182, 0, 48), -- Statue Energy Conduit
(260985, 0, 48), -- The Eye of Aman'thul
(251983, 1375, 50), -- Doodad_7DU_SuramarRaid_Door_Large003
(253462, 0, 1048608), -- Platform
(251988, 0, 48), -- Nighthold Focusing Statue
(252319, 0, 48), -- Nighthold Focusing Statue
(251685, 1375, 50), -- Doodad_7DU_SuramarRaid_Door_med007
(252320, 0, 48), -- Nighthold Focusing Statue
(258847, 0, 34), -- Door
(254243, 0, 34), -- Observatory Door
(254242, 0, 34), -- Observatory Door
(255925, 1375, 16), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001
(251981, 1375, 48), -- Doodad_7DU_SuramarRaid_Door_Large001
(252315, 1375, 32), -- Doodad_7DU_SuramarRaid_Door_Small012
(251609, 0, 32), -- Chamber Door
(251608, 1375, 32), -- Doodad_7DU_SuramarRaid_Door_Small001
(255926, 1375, 16), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001
(251982, 1375, 48), -- Doodad_7DU_SuramarRaid_Door_Large002
(266835, 1375, 16), -- Nightborne Teleporter
(258843, 1375, 16), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003
(251612, 1375, 32), -- Doodad_7DU_SuramarRaid_Door_Small007
(255927, 1375, 16), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
(252316, 1375, 32), -- Doodad_7DU_SuramarRaid_Door_Small013
(251611, 0, 32), -- Chamber Door
(251610, 1375, 32); -- Doodad_7DU_SuramarRaid_Door_Small005

SET @CGUID := 860000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1536;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 111166, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 307.2371, 3100.198, 226.9067, 2.196002, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Resolute Courtesan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 190299 - Warden Salute)
(@CGUID+1, 111170, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 262.914, 3121.102, 227.9345, 2.134936, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Farseer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225958 - Spellcaster, 221577 - Arcane Burst)
(@CGUID+2, 111166, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.4011, 3143.844, 226.9067, 4.523971, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Resolute Courtesan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+3, 111164, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 308.1913, 3142.186, 226.9067, 3.742605, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Stardancer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+4, 111151, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 253.3385, 3143.271, 226.9358, 6.012927, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Midnight Siphoner (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+5, 115683, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3177, 3135.511, 236.7103, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Nightwell (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+6, 106643, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3177, 3135.511, 236.7103, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 208861 - Etched in Time)
(@CGUID+7, 111374, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.6563, 3138.589, 234.0484, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+8, 111833, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 317.6927, 3171.016, 226.9358, 0.7613583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+9, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.9392, 3030.89, 142.0951, 2.566464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+10, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 365.6129, 3052.33, 216.5816, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+11, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 319.0052, 3023.228, 142.9874, 1.901651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+12, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 314.1285, 3104.191, 146.8835, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+13, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 333.9601, 3187.003, 227.3798, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+14, 116670, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 339.0746, 3079.171, 289.498, 2.357195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+15, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 303.5611, 3039.73, 142.1364, 3.249582, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+16, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.2674, 3032.021, 142.0951, 4.925947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+17, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.7222, 3028.109, 142.0951, 0.6901805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+18, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.2326, 3029.243, 142.0951, 2.925902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+19, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 345.75, 3044.686, 142.0951, 3.62425, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+20, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 223.1476, 3038.454, 142.1367, 2.226188, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+21, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 217.7986, 3031.305, 142.0951, 3.787772, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+22, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 252.6406, 2996.174, 142.9874, 4.99868, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+23, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 238.8789, 3007.192, 142.9067, 3.0988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+24, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 238.6998, 3002.954, 142.9067, 3.098905, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+25, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 325.0366, 2983.639, 109.3067, 3.22287, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+26, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.0486, 3166.911, 146.8835, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+27, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.2066, 3016.762, 142.0951, 3.370568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+28, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 386.6389, 3031.495, 171.4524, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+29, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 255.7969, 2993.619, 142.9874, 2.998634, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+30, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 253.1499, 3026.314, 142.1367, 5.594519, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+31, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 330.9983, 2990.508, 110.8636, 4.922272, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+32, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 293.3224, 2988.756, 109.3067, 0.934886, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+33, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 287.059, 3011.097, 142.9874, 1.5936, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+34, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.3767, 2991.092, 110.8636, 4.721676, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+35, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 223.5131, 3041.684, 142.1367, 0.6433282, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+36, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.3819, 2992.161, 142.9874, 0.7629136, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+37, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 236.657, 3005.161, 142.9067, 3.097471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+38, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 196.4826, 2984.981, 142.9875, 4.544653, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+39, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 321.8165, 2979.829, 109.3067, 3.222881, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+40, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 158.6458, 3058.981, 142.9874, 1.383791, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+41, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 255.3733, 2983.22, 109.3202, 5.346361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+42, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 325.6273, 2976.596, 109.3067, 3.226479, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+43, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 144.6719, 3114.236, 142.9874, 4.36932, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+44, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 333.1458, 2968.553, 108.4854, 5.867829, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+45, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 149.7153, 3109.412, 142.9874, 3.484006, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+46, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 256.9236, 2976.372, 109.3202, 1.383791, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+47, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 190.8594, 3003.846, 142.9874, 4.925947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+48, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 193.8247, 3001.069, 142.9874, 2.925902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+49, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 211.9722, 2987.354, 142.9874, 4.958754, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+50, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 337.901, 2963.389, 108.4854, 1.905259, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+51, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.7743, 2969.08, 108.4854, 3.910918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+52, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 278.4668, 2972.195, 109.3067, 3.404334, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+53, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 260.5174, 2980.87, 109.3202, 3.38945, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+54, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 199.1736, 3218.853, 216.5816, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+55, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 375.1524, 2993.416, 109.6906, 3.798841, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+56, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.2406, 2976.333, 109.3067, 3.404344, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+57, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 189.3142, 2999.936, 142.9874, 0.6901805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+58, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.2736, 2969.557, 109.3067, 3.404288, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+59, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 162.2396, 3063.479, 142.9874, 3.38945, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+60, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 150.2326, 3070.251, 147.1797, 0.7095753, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+61, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 157.0955, 3065.828, 142.9874, 5.346361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+62, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 163.3646, 3195.921, 142.9874, 0.6901805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+63, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 125.9786, 3166.077, 109.3067, 4.555127, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+64, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 122.066, 3111.74, 112.9669, 3.086147, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+65, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 164.9097, 3199.833, 142.9874, 4.925947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+66, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 167.875, 3197.055, 142.9874, 2.925902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+67, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 139.9757, 3134.693, 142.9874, 0.3008062, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+68, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 143.5781, 3164.174, 147.0133, 5.44172, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+69, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 142.8854, 3137.726, 142.9874, 4.536573, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+70, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 144.5747, 3134.031, 142.9874, 2.536528, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+71, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 141.9549, 3106.576, 142.9874, 0.7247095, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+72, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 105.7228, 3088.791, 109.3067, 4.419792, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+73, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 156.5017, 3170.408, 142.9874, 4.895346, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+74, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 149.2361, 3168.998, 142.9874, 5.005446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+75, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.5495, 2953.017, 109.3067, 1.314419, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+76, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 106.1997, 3198.756, 110.8951, 5.522297, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+77, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.9028, 3364.995, 172.719, 1.25449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+78, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.3385, 3383.183, 178.4552, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+79, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 275.1476, 3368.592, 172.719, 3.55075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+80, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 95.38021, 3030.984, 112.8204, 5.370285, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+81, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 95.76389, 3043.241, 109.3197, 2.430738, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+82, 103999, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -12.48438, 2843.2, 3.244676, 3.141594, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+83, 92879, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 127.3021, 3255.496, -207.1448, 2.347122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic Stalker (Gigantic AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+84, 103725, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -107.5851, 2776.3, 4.62847, 0.5235988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+85, 103725, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -117.9236, 2793.97, 4.62847, 0.5235988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+86, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 241.4184, 3399.464, 171.8008, 5.355022, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+92, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 178.5347, 3239.784, 171.4581, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+93, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 138.5799, 3183.757, 110.8637, 2.549772, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+94, 116820, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 155.4757, 3185.904, 111.0176, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+95, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 139.1806, 3190.878, 110.8637, 3.242558, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+96, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 238.1044, 3299.96, 171.7067, 0.7766079, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+97, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 237.887, 3295.775, 171.7067, 0.7738781, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+98, 103685, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 249.0668, 3405.612, 171.9451, 2.002752, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tichondrius (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+99, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 233.9042, 3299.792, 171.7067, 0.7736668, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
-- (@CGUID+101, 32638, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Hakmud of Argus (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
-- (@CGUID+103, 89713, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.5004925, -0.02135613, 0.1695825, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Koak Hoburn (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+106, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) - !!! on transport - transport template not found !!!
-- (@CGUID+109, 32638, UNKNOWN, 0, 0, 1, '0', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Hakmud of Argus (Area: -Unknown- - Difficulty: Normal) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
(@CGUID+120, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3107.938, 226.8453, 2.638939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+121, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3175.583, 226.8453, 3.895574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+122, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3143.149, 226.8453, 6.157523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+123, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3188.36, 226.8453, 5.152212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+124, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3184.851, 226.8453, 4.146902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+125, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3128.611, 226.8453, 0.125663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+126, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3180.57, 226.8453, 5.403541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+127, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3078.907, 226.8453, 1.382301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+128, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.011, 3114.529, 226.8453, 0.3769926, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+129, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.015, 3169.971, 226.8453, 5.654867, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+130, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3077.994, 226.8453, 1.633628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+131, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.015, 3101.788, 226.8453, 0.6283186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+132, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3121.456, 226.8453, 2.890264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+133, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.011, 3157.231, 226.8453, 5.906193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+134, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.861, 3080.719, 226.8453, 1.884955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+135, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3091.19, 226.8453, 0.8796451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+136, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 339.938, 3135.88, 226.8453, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+137, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.861, 3191.041, 226.8453, 4.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+138, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3086.909, 226.8453, 2.136283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+139, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3150.304, 226.8453, 3.392921, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+140, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3083.4, 226.8453, 1.130974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+141, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3193.765, 226.8453, 4.649557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+142, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3096.176, 226.8453, 2.387612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+143, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3163.822, 226.8453, 3.644247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+144, 105315, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3192.853, 226.8453, 4.900885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+145, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3150.304, 226.8453, 3.392921, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+146, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3150.304, 226.8453, 3.392921, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+147, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3163.822, 226.8453, 3.644247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+148, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3175.583, 226.8453, 3.895574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+149, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3184.851, 226.8453, 4.146902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+150, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.861, 3191.041, 226.8453, 4.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+151, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3193.765, 226.8453, 4.649557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+152, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3163.822, 226.8453, 3.644247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+153, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3192.853, 226.8453, 4.900885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+154, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3188.36, 226.8453, 5.152212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+155, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3175.583, 226.8453, 3.895574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+156, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3180.57, 226.8453, 5.403541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+157, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.015, 3169.971, 226.8453, 5.654867, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+158, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.011, 3157.231, 226.8453, 5.906193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+159, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3184.851, 226.8453, 4.146902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+160, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3143.149, 226.8453, 6.157523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+161, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3128.611, 226.8453, 0.125663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+162, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.011, 3114.529, 226.8453, 0.3769926, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+163, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.015, 3101.788, 226.8453, 0.6283186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+164, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.861, 3191.041, 226.8453, 4.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+165, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3091.19, 226.8453, 0.8796451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+166, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3193.765, 226.8453, 4.649557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+167, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3083.4, 226.8453, 1.130974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+168, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3078.907, 226.8453, 1.382301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+169, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3077.994, 226.8453, 1.633628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+170, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.861, 3080.719, 226.8453, 1.884955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+171, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3086.909, 226.8453, 2.136283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+172, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3192.853, 226.8453, 4.900885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+173, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3096.176, 226.8453, 2.387612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+174, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3107.938, 226.8453, 2.638939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+175, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3188.36, 226.8453, 5.152212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+176, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3121.456, 226.8453, 2.890264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+177, 105367, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 339.938, 3135.88, 226.8453, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+178, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3180.57, 226.8453, 5.403541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+179, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.015, 3169.971, 226.8453, 5.654867, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+180, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.011, 3157.231, 226.8453, 5.906193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+181, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3143.149, 226.8453, 6.157523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+182, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3128.611, 226.8453, 0.125663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+183, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 228.011, 3114.529, 226.8453, 0.3769926, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+184, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.015, 3101.788, 226.8453, 0.6283186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+185, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3091.19, 226.8453, 0.8796451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+186, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3083.4, 226.8453, 1.130974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+187, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3078.907, 226.8453, 1.382301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+188, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3077.994, 226.8453, 1.633628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+189, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.861, 3080.719, 226.8453, 1.884955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+191, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3086.909, 226.8453, 2.136283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+192, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3096.176, 226.8453, 2.387612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+193, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3107.938, 226.8453, 2.638939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+194, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3121.456, 226.8453, 2.890264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+195, 105370, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 339.938, 3135.88, 226.8453, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+196, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.8379, 3103.595, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
-- (@CGUID+198, 32638, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Hakmud of Argus (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
(@CGUID+201, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 136.2431, 3228.296, 109.3209, 6.050001, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+202, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 262.6476, 3319.167, 148.866, 1.725245, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+203, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 115.4774, 3191.39, 108.4854, 4.002583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+204, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 111.4306, 3190.26, 108.4854, 6.050001, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+205, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 115.0503, 3187.35, 108.4854, 2.002538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+206, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 139.8629, 3225.385, 109.3209, 2.002538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+207, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 140.2899, 3229.425, 109.3209, 4.002583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+208, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 250.5909, 3135.979, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+211, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 255.0844, 3140.273, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+212, 105364, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.5603, 3166.837, 226.9901, 3.729255, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+214, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 266.6111, 3323.807, 148.866, 3.297078, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+215, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 277.6042, 3334.205, 172.1418, 2.421577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+216, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 261.3229, 3326.325, 148.866, 5.510412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+217, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6146, 3337.752, 172.1418, 5.871411, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+220, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.343, 3165.19, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+222, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.9352, 3165.844, 226.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+226, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 274.1224, 3149.306, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+228, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 261.8962, 3124.073, 226.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+230, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 274.9446, 3151.385, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+232, 113128, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 489.1563, 3355.167, 59.93459, 5.981131, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Withered Skulker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+233, 113128, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 491.3799, 3361.347, 59.9067, 5.735534, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Withered Skulker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+234, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 487.4657, 3355.254, 59.9067, 5.897136, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+235, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 487.4657, 3355.254, 59.9067, 5.897136, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+236, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 487.4657, 3355.254, 59.9067, 5.897136, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+237, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 413.1581, 3287.863, 59.9067, 3.444225, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+238, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 529.4739, 3387.432, 115.1, 6.197791, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+239, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.7639, 3349.205, 59.98999, 4.450373, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+240, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 534.5347, 3382.746, 115.1, 1.681841, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+241, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 533.7726, 3387.147, 115.0983, 4.798041, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+242, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 537.5382, 3374.291, 115.1034, 1.180162, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+243, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.0278, 3347.346, 59.97212, 4.450373, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+244, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 406.0035, 3342.15, 59.9722, 4.638996, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+245, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 521.5764, 3390.901, 115.1042, 0.372523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+246, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 505.8385, 3317.264, 59.98534, 0, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+247, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 505.3185, 3417.612, 109.5067, 1.797268, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+248, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.2708, 3344.828, 59.97849, 4.638996, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+249, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 406.9618, 3348.733, 59.97906, 4.450373, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+250, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 519.0521, 3311.931, 59.97278, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+251, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 531.8924, 3390.382, 114.0629, 3.753449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+252, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.0174, 3341.784, 59.96734, 4.638996, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+253, 113128, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 515.5538, 3299.639, 59.9676, 0, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Withered Skulker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+254, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 412.1979, 3348.05, 59.96956, 4.450373, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+255, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 507.5156, 3304.178, 59.98518, 0, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+256, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 502.3767, 3417.019, 109.5067, 3.096682, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+257, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 537.0712, 3385.556, 114.1025, 5.905883, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+258, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 411.934, 3343.925, 59.96732, 4.638996, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+259, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 504.7848, 3412.623, 109.5067, 3.254038, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+260, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 505.8329, 3416.674, 109.5067, 4.24083, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+261, 110791, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 408.0104, 3345.175, 59.97261, 4.558779, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- First Arcanist Thalyssra (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+262, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 442.2188, 3306.995, 142.2042, 5.782425, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+263, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 368.8004, 3417.698, 109.4497, 4.144657, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+264, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 384.7847, 3385.108, 142.9874, 2.027557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+265, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 440.6198, 3305.931, 142.2045, 5.782425, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+266, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 403.8299, 3336.099, 142.0951, 3.412367, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+267, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 450.6563, 3319.453, 142.2024, 5.782425, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+268, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 424.3559, 3274.715, 59.97963, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+269, 113128, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 411.2555, 3278.785, 59.90671, 4.17932, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Withered Skulker (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+270, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 442.3802, 3309.09, 142.2031, 5.645847, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+271, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 387.4219, 3390.662, 142.9874, 3.72026, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+272, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 448.3889, 3316.512, 142.2025, 5.782425, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+273, 113128, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.2886, 3281.44, 59.90671, 2.321667, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Withered Skulker (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+274, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 444.4879, 3312.323, 142.2023, 5.503112, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+275, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 364.1892, 3420.478, 109.4497, 5.342509, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+276, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 367.9496, 3413.983, 109.4496, 2.329644, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+277, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 423.7101, 3277.423, 59.98015, 5.335718, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+278, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 446.3785, 3313.286, 142.2027, 5.782425, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+279, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 446.5399, 3315.526, 142.2021, 5.370388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+280, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 396.9549, 3286.486, 59.98125, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+281, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 365.5399, 3416.333, 109.4496, 6.121222, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+282, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 444.1024, 3310.191, 142.2029, 5.782425, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+283, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 409.5573, 3360.883, 142.8789, 2.327995, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+284, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 411.1584, 3269.114, 59.90671, 3.249888, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+285, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 448.6858, 3318.806, 142.2018, 5.245067, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+286, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 553.7829, 3422.199, 109.5067, 1.053935, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+287, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 420.2552, 3257.728, 59.90199, 5.420245, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+288, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 575.9132, 3389.188, 109.447, 3.797286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+289, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 380.1389, 3384.978, 142.9874, 1.186652, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+290, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 517.0399, 3285.723, 59.97826, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+291, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 382.4097, 3389.641, 142.9874, 4.73911, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+292, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 366.2674, 3356.632, 142.7827, 1.872591, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+293, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 384.026, 3320.228, 142.5865, 1.016561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+294, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 566.7483, 3351.802, 109.4503, 1.849718, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+295, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 378.0418, 3347.428, 142.1368, 4.184939, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+296, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 559.9219, 3353.283, 109.4503, 1.170167, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+297, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 564.3385, 3401.583, 109.5067, 4.181705, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+298, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 558.934, 3413.361, 109.6467, 1.231464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+299, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 567.9045, 3364.992, 109.4504, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+300, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 375.3229, 3332.168, 142.0951, 4.041597, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+301, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 375.283, 3391.1, 142.9874, 5.809658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+302, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 555.7344, 3410.269, 109.6467, 3.581301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+303, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 559.5712, 3364.205, 109.4504, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+304, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 374.4722, 3328.452, 142.0995, 1.821707, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+305, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 396.9935, 3319.521, 142.1062, 0.6175188, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+306, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 563.9271, 3361.972, 109.4504, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+307, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 559.7413, 3409.253, 109.6467, 5.888321, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+308, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 372.0625, 3330.804, 142.0951, 6.099264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+309, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.6458, 3314.298, 142.9142, 3.744776, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+310, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 564.2639, 3294.6, 109.45, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+311, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 461.1996, 3238.615, 60.76167, 1.458156, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+312, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 583.6702, 3392.519, 109.4506, 4.73911, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+313, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 450.1476, 3240.683, 60.46651, 4.676984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+314, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 471.5764, 3237.342, 60.97228, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+315, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 464.5486, 3237.451, 60.9724, 1.458156, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+316, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 461.7448, 3242.042, 60.01169, 4.676984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+317, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 346.9618, 3379.838, 142.9874, 3.879231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+318, 111221, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 427.7917, 3280.218, 142.0951, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+319, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 454.3681, 3240.626, 60.02796, 4.676984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+320, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 345.5208, 3376.309, 142.9874, 1.65934, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+321, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 440.3715, 3238.557, 60.97192, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+322, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 420.7778, 3255.026, 59.93302, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+323, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 484.8142, 3250.031, 59.98251, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+324, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 576.7899, 3360.052, 110.937, 3.134479, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+325, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 343.5243, 3379.018, 142.9874, 5.936898, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+326, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 580.0695, 3389.245, 109.4506, 4.73911, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+327, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 444.3958, 3236.873, 60.97131, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+328, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 576.6094, 3356.738, 110.937, 2.936255, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+329, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 577.7986, 3384.581, 109.4467, 0.5861202, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+330, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 454.7535, 3238.24, 60.89635, 1.458156, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+331, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 450.9097, 3237.646, 60.97211, 1.458156, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+332, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 582.4445, 3384.711, 109.4506, 2.58344, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+333, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 562.4739, 3298.175, 109.45, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+334, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 538.1111, 3264.595, 142.9874, 3.199466, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+335, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 476.2865, 3236.513, 60.97231, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+336, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 508.5104, 3430.195, 110.937, 4.895306, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+337, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 569.8837, 3295.595, 109.4501, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+338, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 535.0035, 3254.728, 142.9874, 3.299041, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+339, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 476.0972, 3228.528, 142.0951, 4.221406, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+340, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 572.2552, 3302.675, 109.4501, 4.6782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+341, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 502.9045, 3429.362, 110.937, 4.895306, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+342, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 534.9011, 3266.642, 142.9874, 5.257128, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+343, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 536.0972, 3242.496, 142.9874, 5.616794, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224825 - Containment Field)
(@CGUID+344, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 457.4336, 3215.468, 142.1844, 0.8085665, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+345, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 490.276, 3218.879, 142.1291, 1.224246, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+346, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 474.3837, 3225.234, 142.0951, 1.102242, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+347, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 537.8611, 3260.609, 142.9874, 2.647254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+348, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 530.9167, 3269.095, 142.9874, 3.963229, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+349, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 326.2674, 3387.331, 148.866, 0.6008496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+350, 111587, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 541.6268, 3237.193, 142.9874, 3.126508, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nether Elemental (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+351, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 462.4792, 3252.619, 142.3913, 3.689929, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+352, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 516.8472, 3310.934, 59.96803, 0.983647, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+353, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 479.3351, 3235.758, 142.2072, 2.537066, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+354, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 467.8519, 3246.342, 142.1102, 0.7766809, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+355, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 476.0507, 3262.206, 142.5397, 3.348698, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+356, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 433.5504, 3167.04, 142.3391, 4.623832, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+357, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 378.0052, 3163.944, 142.1543, 4.743952, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+358, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 478.3438, 3210.608, 142.2878, 6.13833, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+359, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 588.309, 3245.647, 106.9713, 3.644359, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+360, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 420.5382, 3173.779, 142.0951, 5.077163, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+361, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 267.6875, 3244.163, 142.0951, 1.040404, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+362, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 536.0121, 3232.228, 142.9874, 1.093002, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224825 - Containment Field)
(@CGUID+363, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 587.2239, 3247.964, 106.9714, 3.807931, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+364, 112803, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 497.3403, 3145.609, 148.8522, 2.316893, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astrologer Jarin (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224655 - Nightborne Astrologer Views Planets) (possible waypoints or random movement)
(@CGUID+365, 104881, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 383.9099, 3200.294, 142.1326, 5.46972, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spellblade Aluriel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+366, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 266.5, 3262.427, 142.0951, 5.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+367, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 278.6371, 3262.08, 142.0951, 4.133325, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+368, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 321.0695, 3235.386, 142.1258, 6.005883, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+369, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 279.3021, 3243.443, 142.0951, 2.119103, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+370, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 227.8177, 3257.238, 142.398, 3.742157, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+371, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 243.4809, 3230.248, 142.5312, 3.804245, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+372, 103758, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 607.7674, 3187.991, 196.6637, 0.681235, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Star Augur Etraeus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232550 - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE])
(@CGUID+373, 92879, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 127.3021, 3255.496, -207.1448, 2.347122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic Stalker (Gigantic AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+374, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 715.816, 2969.442, 127.8349, 1.761456, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+375, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.1996, 3395.132, 142.9874, 4.041597, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+376, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 461.2934, 3299.378, 142.2024, 2.615341, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+377, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 409.349, 3391.417, 142.9874, 1.821707, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+378, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 504.8351, 3291.525, 59.90671, 0.5710912, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+379, 113383, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 494.8073, 3281.438, 59.98539, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fallen Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+380, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 398.0087, 3284.909, 59.98073, 1.779086, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+381, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 406.9392, 3393.767, 142.9874, 6.099264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+382, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 460.1371, 3297.526, 142.202, 2.373759, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+383, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 531.0625, 3434.353, 109.4506, 6.255309, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+384, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 456.875, 3295.569, 142.2026, 2.237276, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+385, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 496.3767, 3282.865, 59.98525, 4.32077, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+386, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 534.9375, 3431.781, 109.4506, 1.969445, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+387, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 535.6059, 3436.855, 109.4506, 4.125114, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+388, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 550.4271, 3433.496, 109.4506, 4.256186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+389, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 464.4184, 3301.406, 142.2021, 2.615341, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+390, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 524.873, 3301.014, 60.02878, 2.496061, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+391, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 453.4948, 3293.58, 142.2041, 2.091494, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+392, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 466.4375, 3301.539, 142.2015, 2.615341, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+393, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 467.5156, 3303.355, 142.2019, 2.615341, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+394, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 538.3524, 3433.814, 109.4506, 6.079905, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+395, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 454.6354, 3295.684, 142.2039, 2.615341, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+396, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 463.4566, 3299.487, 142.2017, 2.502283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+397, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 516.4896, 3287.97, 59.97553, 5.216488, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+398, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 532.5851, 3428.601, 109.4506, 4.125114, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+399, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 458.0642, 3297.464, 142.2027, 2.615341, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+400, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 580.1754, 3408.438, 109.4507, 3.795746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+401, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 561.6563, 3431.366, 109.4507, 4.256186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+402, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 579.5903, 3412.365, 109.4507, 3.795746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+403, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 557.9566, 3432.128, 109.4507, 4.256186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+404, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 578.8212, 3415.707, 109.4507, 3.795746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+405, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 451.652, 3263.684, 142.8387, 1.17956, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 226005 - Blink) (possible waypoints or random movement)
(@CGUID+406, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 554.1563, 3432.901, 109.4507, 4.256186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+407, 113321, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 465.7326, 3240.425, 60.46651, 4.676984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shambling Hungerer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+408, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 577.7552, 3418.917, 109.4507, 3.795746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+409, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.3594, 3268.504, 142.619, 4.073863, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+410, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 580.6979, 3404.8, 109.4507, 3.795746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+411, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 350.2662, 3389.761, 142.9566, 5.779605, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+412, 112709, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 565.2639, 3430.458, 109.4507, 4.256186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Promenade Guard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+413, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.3722, 3246.731, 142.1368, 3.584213, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+414, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 253.6563, 3314.957, 148.866, 3.946538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+415, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.401, 3250.299, 142.0951, 3.342769, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+416, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 274.2552, 3287.345, 142.5959, 4.053354, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+417, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 269.8559, 3284.74, 142.8073, 5.072204, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+418, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 269.2344, 3279.589, 142.6452, 1.519746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+419, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 293.349, 3249.806, 142.0951, 0.1208713, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+420, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.5833, 3281.233, 142.5833, 2.360651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+421, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 262.6424, 3283.788, 142.9549, 6.142752, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+422, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 373.8733, 3086.878, 142.6473, 3.970033, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+423, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 440.4879, 3192.01, 142.0951, 2.29012, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+424, 117085, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 279.2257, 3361.592, 145.7562, 5.485684, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ly'leth Lunastre (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+425, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 450.2986, 3201.59, 142.0951, 2.441649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+426, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 321.8023, 3246.49, 142.2888, 5.559222, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+427, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 403.5399, 3176.131, 142.0951, 1.1919, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+428, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 401.0417, 3175.09, 142.0951, 1.1919, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+429, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.7431, 3173.825, 142.0957, 1.1919, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+430, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.6962, 3196.492, 145.3147, 0.7370799, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+431, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 391.2552, 3065.894, 142.0951, 3.057181, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+432, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 536.1788, 3218.491, 142.9874, 3.091359, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+433, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 343.1371, 3185.757, 145.3147, 0.8322693, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+434, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 274.7117, 3151.306, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+436, 106680, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 270.1188, 3142.318, 226.9901, 4.076378, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+437, 105958, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 312.2606, 3129.435, 226.8453, 4.076378, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+438, 105958, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.438, 3150.602, 226.8453, 4.076378, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+439, 105958, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 252.8134, 3157.04, 226.8453, 4.076378, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+440, 105958, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.7496, 3109.637, 226.8453, 4.076378, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+441, 105958, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.5905, 3109.25, 226.8453, 4.076378, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+442, 107754, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 312.2606, 3129.435, 244.99, 0.4886922, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+443, 107754, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.5905, 3109.25, 244.9901, 0.296706, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+444, 107754, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.438, 3150.602, 244.9901, 1.570796, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+445, 107754, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.7496, 3109.637, 244.9901, 1.884956, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+446, 107754, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 252.8134, 3157.04, 244.9901, 1.797689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+447, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 242.7639, 3272.128, 142.0951, 5.556626, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+448, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 236.3819, 3295.585, 143.9949, 3.407435, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+449, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 232.9497, 3296.417, 143.9951, 5.465102, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+450, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 233.4983, 3293.097, 143.9956, 1.187544, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+451, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 250.6215, 3242.47, 142.0953, 4.352778, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+452, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 250.9497, 3238.675, 142.0953, 2.132887, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+453, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 235.5729, 3264.158, 142.1326, 5.556626, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+454, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 247.9358, 3240.175, 142.0951, 0.1272597, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+455, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 400.6096, 3154.97, 142.3886, 1.894967, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+456, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.7569, 3291.616, 143.9962, 4.531608, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+457, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.0208, 3151.685, 142.3868, 2.454611, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+458, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 226.4149, 3284.373, 143.9956, 3.46106, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+459, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 276.4686, 3155.561, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+460, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 222.7587, 3280.792, 143.9956, 0.7495067, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+461, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 221.2934, 3285.2, 143.9956, 6.191788, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+464, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.3229, 3137.589, 142.1115, 4.20977, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+465, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 474.8889, 3142.723, 148.6775, 6.052853, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+466, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 388.4792, 3129.7, 142.149, 5.996919, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+467, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 567.5434, 3210.195, 109.4496, 4.338797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+468, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 495.8594, 3162.378, 148.8522, 4.962232, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+469, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 543.7518, 3202.457, 142.9874, 1.864989, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+470, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 504.7066, 3165.231, 148.6658, 4.78172, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+471, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 543.8125, 3205.546, 142.9874, 4.250143, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+472, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 427.9514, 3128.203, 142.6535, 3.815975, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+473, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 484.3365, 3154.244, 148.7067, 5.496764, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+474, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 567.4254, 3206.383, 109.4496, 2.523783, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+475, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 541.9167, 3214.163, 142.9874, 3.873611, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224814 - Cosmetic Nightborne Reading Book)
(@CGUID+476, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 501.9392, 3163.146, 148.7533, 0.2866627, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+477, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 486.6594, 3155.921, 148.7067, 2.355192, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+478, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 488.3405, 3158.24, 148.7067, 5.496822, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+479, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 564.6094, 3208.226, 109.4496, 0.03217631, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+480, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 542.9202, 3210.17, 142.9874, 3.200636, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+481, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 476.1267, 3139.786, 148.6651, 3.97751, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+482, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 477.3629, 3146.439, 148.727, 3.008801, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224814 - Cosmetic Nightborne Reading Book)
(@CGUID+483, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 414.908, 3125.564, 142.1423, 3.168007, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+484, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 498.5851, 3166.194, 148.7136, 2.5151, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224439 - Cosmetic Use Standing Loop)
(@CGUID+485, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 394.8351, 3137.78, 142.1578, 5.320548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+486, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 479.8733, 3148.76, 148.8503, 5.732928, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+487, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 431.8281, 3119.441, 142.8125, 2.360651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+488, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 428.1007, 3122.948, 142.6823, 5.072204, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+489, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 409.2135, 3115.702, 142.1449, 2.105689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+490, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 427.4792, 3117.799, 142.6042, 1.519746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+491, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 390.9583, 3119.589, 142.2574, 0.4235268, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+492, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 481.3264, 3137.241, 148.7175, 0.2830461, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+493, 113406, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 294.3108, 3153.561, 145.2825, 4.073987, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Manaflush Noble (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225579 - Imbibe Nightwell)
(@CGUID+494, 113406, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.507, 3147.695, 145.2829, 3.838697, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Manaflush Noble (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225579 - Imbibe Nightwell)
(@CGUID+495, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 229.4376, 3237.552, 142.0585, 0.626579, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+496, 113406, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.276, 3149.38, 145.2817, 3.945174, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Manaflush Noble (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225579 - Imbibe Nightwell)
(@CGUID+498, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 433.5743, 3087.494, 144.1067, 3.927423, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+499, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 513.9566, 3138.375, 148.6753, 4.017395, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+500, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 511.059, 3141.415, 148.6764, 0.9434972, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224439 - Cosmetic Use Standing Loop)
(@CGUID+501, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 503.0938, 3129.406, 148.6756, 0.2428643, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+502, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 497.611, 3101.477, 168.7331, 0.3285737, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+503, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 433.576, 3083.494, 144.1067, 3.927315, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+504, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 460.2969, 3099.172, 171.7847, 3.872346, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+505, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.3299, 3088.829, 142.1002, 2.332203, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+506, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 487.9081, 3108.36, 172.7067, 4.554979, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+507, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 375.3976, 3108.142, 142.6788, 4.433678, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+508, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 453.9913, 3105.734, 171.7846, 3.801974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+509, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 532.2855, 3106.209, 148.7067, 5.496445, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+510, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 424.1545, 3107.625, 142.5075, 1.100995, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+511, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 536.5289, 3109.965, 148.7067, 5.496427, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+512, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 492.6418, 3101.748, 170.624, 4.300447, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+513, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 376.0365, 3104.385, 142.9931, 2.213787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+514, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 464.2274, 3104.726, 171.7849, 3.463858, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+515, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 372.9097, 3105.636, 142.7031, 0.2081591, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+516, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 450.7813, 3102.983, 171.7846, 4.152358, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+517, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 418.1632, 3096.18, 142.0955, 2.332203, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+518, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 459.7517, 3108.616, 171.7851, 4.037807, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+519, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 504.8021, 3127.639, 148.675, 3.97751, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224814 - Cosmetic Nightborne Reading Book)
(@CGUID+520, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 536.2483, 3113.43, 172.3285, 0.7193581, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+521, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 547.1938, 3124.164, 174.9067, 5.392729, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+522, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 433.4801, 3079.397, 144.1067, 3.927393, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+523, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 544.8619, 3127.735, 174.9067, 0.9785874, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+524, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 441.5771, 3079.497, 144.1067, 3.927382, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+525, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 559.4715, 3142.328, 177.7416, 1.792149, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+526, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 564.1563, 3141.459, 179.5964, 5.29407, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+527, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 524.1194, 3108.905, 164.9966, 2.958324, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+528, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 520.607, 3098.66, 162.9067, 1.901825, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+529, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 551.6392, 3134.379, 174.9067, 1.080081, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+530, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 437.5776, 3079.496, 144.1067, 3.927374, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+531, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 542.7192, 3120.548, 174.9067, 4.168007, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+532, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 516.4826, 3094.519, 162.9067, 3.568156, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+533, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 500.7222, 3093.556, 164.1635, 0.7193581, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+534, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 532.9013, 3118.161, 173.5103, 1.817516, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+535, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 457.7778, 3095.704, 171.7846, 3.79539, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+536, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 511.8438, 3095.073, 162.9067, 2.585062, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+537, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 499.1927, 3097, 166.1825, 0.7193581, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+538, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 530.5381, 3109.396, 168.1244, 2.355589, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+539, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 511.3613, 3092.092, 162.9067, 5.968675, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+540, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 496.9606, 3095.125, 166.5496, 1.90371, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+541, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 556.5071, 3135.052, 174.9067, 5.213199, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+542, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 533.6113, 3107.457, 169.2601, 4.843515, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+543, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 491.1688, 3098.586, 170.091, 6.147081, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+544, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 565.8264, 3143.882, 182.4799, 4.196166, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+545, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 506.3293, 3084.968, 162.9067, 2.760321, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+546, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 635.9479, 2793.026, 133.2171, 1.35371, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 224840 - Mana Orb Visual)
(@CGUID+547, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 506.9915, 3090.135, 163.0989, 2.582809, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+548, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 568.0758, 3153.245, 189.8141, 5.158189, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+549, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 567.6669, 3146.917, 185.4052, 3.167411, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+550, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 596.3611, 3036.666, 128.5076, 4.096195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+551, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 476.5781, 3065.557, 142.0956, 1.180072, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+552, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 508.4226, 3089.695, 163.2833, 4.238369, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+553, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 474.0781, 3069.256, 142.2157, 0.1612757, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+554, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 392.0855, 3078.174, 142.1618, 3.257123, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+555, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 547.7225, 3094.736, 148.7067, 5.496449, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+556, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 565.2456, 3144.384, 182.4335, 4.757283, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+557, 111221, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 574.0087, 3153.306, 193.1019, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+558, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 274.8185, 3158.923, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+559, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 432.0063, 3077.937, 171.7067, 0.7856163, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+560, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 425.8508, 3079.781, 171.7067, 0.7855897, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+561, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 429.8501, 3079.781, 171.7067, 0.7855782, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+562, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 436.2249, 3078.156, 171.7067, 0.7856236, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+563, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.1645, 3150.071, 226.99, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+564, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 440.587, 3078.52, 171.7067, 0.7856051, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+566, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.0821, 3151.182, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+567, 112767, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 575.0319, 3154.317, 194.2745, 2.320296, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Star Shooting Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+569, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 373.7049, 3072.269, 142.0951, 0.6818193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+570, 113406, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 306.1858, 3129.195, 145.2805, 1.659941, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Manaflush Noble (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225579 - Imbibe Nightwell)
(@CGUID+571, 113406, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.3802, 3134.129, 145.2814, 2.867327, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Manaflush Noble (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225579 - Imbibe Nightwell)
(@CGUID+572, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 653.7031, 3000.256, 128.5076, 1.181949, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+573, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 453.7708, 3030.484, 144.097, 1.466677, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+574, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 457.1007, 3031.964, 144.0976, 2.375437, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+575, 111936, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 607.783, 3187.376, 196.0556, 4.075927, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+576, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 663.005, 2966.99, 128.5067, 3.752458, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+578, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.7858, 3156.209, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+580, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.2932, 3154.1, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
-- (@CGUID+581, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) - !!! on transport - transport template not found !!!
(@CGUID+583, 106330, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3177, 3135.511, 236.7103, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 210745 - Etched in Time)
-- (@CGUID+584, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.27, 0, -0.27, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) - !!! on transport - transport template not found !!!
(@CGUID+590, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 333.9601, 3187.003, 227.3798, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+591, 111833, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 317.6927, 3171.016, 226.9358, 0.7613583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
-- (@CGUID+594, 32638, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Hakmud of Argus (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
(@CGUID+595, 113406, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 275.7552, 3157.523, 145.2808, 6.033355, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Manaflush Noble (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225579 - Imbibe Nightwell)
(@CGUID+596, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 214.6927, 3281.378, 143.9964, 0.2928423, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+597, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.0486, 3166.911, 146.8835, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+598, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 210.1024, 3272.32, 143.9951, 0.4843321, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+599, 111936, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.7951, 3396.01, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+600, 112660, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 212.684, 3274.912, 143.9951, 4.251002, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Citizen (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+601, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 199.1313, 3303.303, 142.1075, 0.2423722, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+603, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 314.1285, 3104.191, 146.8835, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+604, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 199.1736, 3218.853, 216.5816, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+605, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 178.5347, 3239.784, 171.4581, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+606, 111374, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.6563, 3138.589, 234.0484, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+607, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 190.8698, 3251.911, 146.5532, 0.6008496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+609, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 365.6129, 3052.33, 216.5816, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
-- (@CGUID+610, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.23, 0, -0.23, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak, 123240 - Grummle Booth B) - !!! on transport - transport template not found !!!
(@CGUID+611, 112655, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 314.2917, 3015.8, 142.9874, 3.957017, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Celestial Acolyte (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+612, 112638, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 315.5313, 3012.28, 142.9874, 2.652511, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Astral Defender (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+613, 112718, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.2101, 3019.626, 142.9874, 3.801974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sidereal Familiar (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+614, 116670, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 339.0746, 3079.171, 289.498, 2.357195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+615, 116820, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 155.4757, 3185.904, 111.0176, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
-- (@CGUID+629, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) - !!! on transport - transport template not found !!!
-- (@CGUID+634, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) - !!! on transport - transport template not found !!!
(@CGUID+638, 107980, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 347.0854, 3235.75, 142.2201, 4.253625, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spellblade Aluriel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213179 - Searing Brand)
(@CGUID+639, 107980, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 347.0854, 3235.75, 142.2201, 4.253625, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spellblade Aluriel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213179 - Searing Brand)
(@CGUID+640, 107980, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 347.0854, 3235.75, 142.2201, 4.253625, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spellblade Aluriel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213179 - Searing Brand)
(@CGUID+641, 107980, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 347.0854, 3235.75, 142.2201, 4.253625, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spellblade Aluriel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 213179 - Searing Brand)
(@CGUID+650, 110792, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 505.8039, 3366.79, 117.1515, 3.94437, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Archmage Khadgar (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+653, 114841, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 508.1275, 3360.85, 118.9275, 3.929105, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Lady Liadrin (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+654, 114838, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 508.2833, 3352.993, 122.4508, 3.931908, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Tyrande Whisperwind (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+655, 114883, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 506.3654, 3355.029, 122.4794, 3.923949, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Grand Magister Rommath (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+656, 115772, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 488.7809, 3333.275, 140.9828, 3.929426, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Kal (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+657, 116256, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 483.1962, 3341.33, 139.8916, 3.916039, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Victoire (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+658, 115840, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 477.7461, 3338.41, 142.3066, 3.955865, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Arcanist Valtrois (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+659, 116372, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 484.4244, 3335.805, 141.9539, 3.890854, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Arluelle (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+660, 107997, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 482.9265, 3331.326, 142.266, 3.920657, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Silgryn (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+661, 104154, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.1979, 3135.806, 465.9338, 0.7757543, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227639 - Gul'dan, 227743 - The Eye of Aman'thul, 227554 - Fel Scythe, 212294 - Parasitic Wound, 227037 - Parasitic Wound, 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room))
-- (@CGUID+662, 114438, UNKNOWN, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Eye of Aman'thul (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 46598 - Ride Vehicle Hardcoded, 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)) - !!! on transport - transport template not found !!!
(@CGUID+663, 114440, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 245.375, 3098.603, 465.6264, 4.01533, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Eye of Aman'thul (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room))
(@CGUID+665, 111936, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.2587, 3135.297, 443.3806, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+666, 111374, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.6545, 3135.285, 466.0736, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room))
(@CGUID+667, 114437, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 294.5781, 3147.31, 482.6606, 4.207493, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lord Illidan Stormrage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 208903 - Gul'dan, 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room))
(@CGUID+668, 114440, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 319.2188, 3172.226, 465.6264, 0.811895, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Eye of Aman'thul (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room))
(@CGUID+669, 114440, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 319.1945, 3098.544, 465.6264, 5.510952, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Eye of Aman'thul (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room))
(@CGUID+670, 92879, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 127.3021, 3255.496, -207.1448, 2.347122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic Stalker (Gigantic AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
-- (@CGUID+671, 62822, UNKNOWN, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -0.2, 0, -0.2, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room)) - !!! on transport - transport template not found !!!
-- (@CGUID+675, 32642, UNKNOWN, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Mojodishu (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
-- (@CGUID+677, 32642, UNKNOWN, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Mojodishu (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
(@CGUID+679, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 279.7961, 3135.251, 466.0736, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
-- (@CGUID+680, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) - !!! on transport - transport template not found !!!
(@CGUID+681, 92870, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.97, 3123.877, 476.0743, 2.207543, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+682, 92870, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 456.0234, 3187.313, 158.6864, 5.50329, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: )
(@CGUID+684, 112595, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 614.4388, 3028.01, 128.6097, 2.346468, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+685, 112596, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 609.7938, 3027.124, 128.5928, 2.353593, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+686, 112596, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 615.2484, 3032.983, 128.5068, 2.353575, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+688, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.195, 3118.472, 465.9485, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+689, 111303, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 638.2448, 3018.006, 128.5076, 6.271062, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+690, 112596, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 640.3924, 3015.922, 128.5076, 1.881011, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+691, 112955, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 744.0969, 2971.809, 127.4214, 4.405743, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+692, 112603, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 750.4688, 2964.311, 125.0763, 0.2817363, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+693, 112603, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 669.8559, 2851.085, 125.369, 0.7330383, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+696, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 259.9169, 3123.425, 465.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+697, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.3763, 3135.678, 465.9332, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+698, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 332.3073, 3319.564, 145.5592, 5.247856, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+699, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 320.3733, 3308.123, 145.5592, 5.642266, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+700, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 262.6476, 3319.167, 148.866, 1.725245, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+701, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.8524, 3363.452, 145.5568, 4.421372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+702, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 316.6979, 3375.873, 148.866, 1.747084, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+703, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 261.3229, 3326.325, 148.866, 5.510412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+704, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 260.4971, 3318.485, 171.7067, 3.868355, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+705, 111221, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 427.7917, 3280.218, 142.0951, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+706, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6146, 3337.752, 172.1418, 5.871411, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+707, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 266.6111, 3323.807, 148.866, 3.297078, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+708, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 316.0712, 3380.354, 171.7401, 5.871411, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+709, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 277.6042, 3334.205, 172.1418, 2.421577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+710, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 256.4572, 3318.536, 171.7523, 3.934445, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+711, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.066, 3357.484, 145.5602, 3.76079, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+712, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.2545, 3327.704, 145.5067, 2.354146, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+713, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.9931, 3365.08, 145.5601, 4.031784, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+714, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.2535, 3360.497, 145.5568, 3.344651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+715, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.6493, 3336.938, 145.5601, 0.8567197, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+716, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.75, 3357.014, 145.5568, 2.511203, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+717, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.974, 3379.74, 148.866, 0.175252, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+718, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 279.7222, 3355.785, 145.5568, 1.231122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+719, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 277.316, 3358.007, 145.5568, 0.2279469, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+720, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 320.0608, 3376.806, 171.7401, 2.421577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+721, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 275.8906, 3344.805, 145.56, 0.7191195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+722, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 315.0451, 3376.506, 171.7874, 0.7514946, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+723, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 319.1024, 3381.215, 148.866, 3.960419, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+724, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 406.9618, 3348.733, 59.97906, 4.450373, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+725, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 406.0035, 3342.15, 59.9722, 4.638996, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+726, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.9028, 3364.995, 172.719, 1.25449, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%) (possible waypoints or random movement)
(@CGUID+727, 117085, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 279.2257, 3361.592, 145.7562, 5.485684, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ly'leth Lunastre (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+728, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.0278, 3347.346, 59.97212, 4.450373, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+729, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 275.1476, 3368.592, 172.719, 3.55075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+730, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2334, 3323.14, 171.7067, 3.869549, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+731, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 411.934, 3343.925, 59.96732, 4.638996, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+732, 110791, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 408.0104, 3345.175, 59.97261, 4.558779, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- First Arcanist Thalyssra (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+733, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 275.1615, 3386.115, 171.8008, 5.94274, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+734, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.7639, 3349.205, 59.98999, 4.450373, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+735, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 404.2708, 3344.828, 59.97849, 4.638996, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+736, 113608, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 410.0174, 3341.784, 59.96734, 4.638996, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+737, 113605, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 412.1979, 3348.05, 59.96956, 4.450373, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kirin Tor Guardian (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+738, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.2674, 3364.128, 171.8008, 5.67874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+739, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.3385, 3383.183, 178.4552, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+740, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 333.9601, 3187.003, 227.3798, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+741, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 263.7118, 3398.259, 171.8008, 2.733552, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+742, 111936, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 244.7951, 3396.01, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+743, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 219.2778, 3388.184, 173.8221, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+744, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 249.1476, 3420.747, 173.8223, 5.035172, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+745, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 241.8177, 3374.958, 171.8008, 1.711823, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+746, 111833, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 317.6927, 3171.016, 226.9358, 0.7613583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Thal'kiel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+747, 103685, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 226.4271, 3413.01, 171.8008, 5.501315, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tichondrius (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 217507 - Tich Light)
(@CGUID+748, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 265.3681, 3421.55, 171.8008, 0.8800458, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+749, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 241.2049, 3393.769, 171.8008, 2.365096, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+750, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 241.3715, 3398.967, 171.8008, 2.365096, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+751, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 272.4495, 3393.554, 171.9067, 4.586026, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+752, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 247.1007, 3399.324, 171.8008, 2.365096, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+753, 113013, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 222.7986, 3371.068, 171.8008, 4.205703, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Shadowblade (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+754, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.0486, 3166.911, 146.8835, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+755, 113012, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 245.1176, 3364.229, 171.9067, 6.153108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Chaos-Mage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+756, 111170, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.7118, 3146.117, 226.9583, 5.497787, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Astral Farseer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 225958 - Spellcaster, 221485 - Spellcasting) (possible waypoints or random movement)
(@CGUID+757, 111166, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.3056, 3108.877, 226.9583, 5.497787, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Resolute Courtesan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 190299 - Warden Salute) (possible waypoints or random movement)
(@CGUID+758, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 191.0434, 3199.353, 145.9578, 4.261746, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+759, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 178.5347, 3239.784, 171.4581, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+760, 106643, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3177, 3135.511, 236.7103, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 208861 - Etched in Time)
(@CGUID+761, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 314.1285, 3104.191, 146.8835, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+762, 111374, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.6563, 3138.589, 234.0484, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+763, 104271, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 226.224, 3413.767, 171.8008, 5.508883, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Combat Stalker (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 207257 - Bat Spawner)
(@CGUID+764, 115683, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3177, 3135.511, 236.7103, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Nightwell (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+765, 111166, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 309.0035, 3112.575, 226.9583, 5.497787, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Resolute Courtesan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 190299 - Warden Salute) (possible waypoints or random movement)
(@CGUID+766, 111164, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.9965, 3117.833, 226.9583, 2.356194, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Twilight Stardancer (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 221589 - Focused) (possible waypoints or random movement)
(@CGUID+767, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 199.1736, 3218.853, 216.5816, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+768, 111151, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 253.3385, 3143.271, 226.9358, 6.012927, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Midnight Siphoner (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 221340 - Siphon Nightwell)
(@CGUID+769, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 176.2292, 3111.424, 145.439, 5.055022, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+770, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 106.1997, 3198.756, 110.8951, 5.522297, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+771, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 191.3142, 3061.349, 142.0951, 0.5778682, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+772, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 287.059, 3011.097, 142.9874, 1.5936, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+773, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 185.5425, 3110.621, 142.076, 1.872046, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+774, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 164.7118, 3100.603, 142.0951, 3.522887, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+775, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 175.1698, 3161.417, 142.134, 4.322777, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+776, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 319.0052, 3023.228, 142.9874, 1.901651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+777, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 158.1927, 3139.193, 142.9874, 5.980662, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+778, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 130.7285, 3192.426, 109.3067, 4.537896, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+779, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 170.4531, 3172.208, 142.9874, 6.170668, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+780, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 143.5781, 3164.174, 147.0133, 5.44172, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+781, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 141.9549, 3106.576, 142.9874, 0.7247095, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+782, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 177.7309, 3069.779, 142.0951, 3.816682, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+783, 92879, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 127.3021, 3255.496, -207.1448, 2.347122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic Stalker (Gigantic AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+784, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.2066, 3016.762, 142.0951, 3.370568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+785, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 122.066, 3111.74, 112.9669, 3.086147, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+786, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 217.7986, 3031.305, 142.0951, 3.787772, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+787, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 150.2326, 3070.251, 147.1797, 0.7095753, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+788, 103725, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -117.9236, 2793.97, 4.62847, 0.5235988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+789, 103725, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -107.5851, 2776.3, 4.62847, 0.5235988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+790, 103999, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -12.48438, 2843.2, 3.244676, 3.141594, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+791, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 241.4184, 3399.464, 171.8008, 5.355022, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+792, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 268.3659, 3135.781, 469.5853, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+793, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 249.9219, 3133.747, 465.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+794, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 270.6107, 3140.591, 466.0736, 2.850512, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+795, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 277.7408, 3133.031, 466.0736, 4.944898, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+796, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.7234, 3142.986, 466.0736, 0.7561258, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+797, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.4951, 3127.811, 466.0736, 4.933769, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+798, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 287.5883, 3137.732, 466.0736, 0.7449618, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+799, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 277.4496, 3135.451, 466.0736, 2.839365, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+800, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.5927, 3127.878, 466.0736, 4.44507, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+801, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.9817, 3135.186, 466.0736, 0.2562947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+802, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 278.9584, 3137.931, 466.0736, 2.350692, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+803, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 347.5088, 3292.668, 142.0951, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+804, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.0003, 3127.781, 466.0736, 4.514883, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+805, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.8614, 3135.587, 466.0736, 0.3261013, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+806, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 278.6711, 3137.626, 466.0736, 2.420502, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+807, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 278.0579, 3133.786, 466.0736, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+808, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 163.3646, 3195.921, 142.9874, 0.6901805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+809, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 164.9097, 3199.833, 142.9874, 4.925947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+810, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 167.875, 3197.055, 142.9874, 2.925902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+811, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6004, 3135.309, 466.0739, 3.069754, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+812, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.2042, 3129.48, 466.0739, 5.164135, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+813, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.9502, 3139.845, 466.0739, 0.9753409, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+814, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6569, 3133.951, 466.0739, 3.296632, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+815, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.3513, 3130.207, 466.0739, 5.391021, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+816, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.7465, 3140.475, 466.0739, 1.202248, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+817, 92870, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 269.955, 3135.961, 476.0727, 6.12511, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+818, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.736, 3133.54, 466.0739, 3.366464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+819, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.668, 3130.481, 466.0739, 5.460843, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+820, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.3508, 3140.612, 466.0739, 1.27205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+821, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6191, 3135.517, 466.0739, 3.034823, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+822, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.0142, 3129.392, 466.0739, 5.129226, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+823, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.1215, 3139.725, 466.0739, 0.9404426, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+824, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 140.2899, 3229.425, 109.3209, 4.002583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+825, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.5849, 3134.89, 466.0739, 3.139558, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+826, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.5743, 3129.676, 466.0739, 5.23396, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+827, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.5955, 3140.068, 466.0739, 1.045156, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+828, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.736, 3133.54, 466.0739, 3.366464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+829, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.668, 3130.481, 466.0739, 5.460843, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+830, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.3508, 3140.612, 466.0739, 1.27205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+831, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.736, 3133.54, 466.0739, 3.366464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+832, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.668, 3130.481, 466.0739, 5.460843, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+833, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.3508, 3140.612, 466.0739, 1.27205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+834, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6569, 3133.951, 466.0739, 3.296632, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+835, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.3513, 3130.207, 466.0739, 5.391021, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+836, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.7465, 3140.475, 466.0739, 1.202248, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+837, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.589, 3135.1, 466.0739, 3.104638, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+838, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.391, 3129.574, 466.0739, 5.199044, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+839, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.7748, 3139.96, 466.0739, 1.010256, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+840, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6312, 3135.621, 466.0739, 3.017372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+841, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.9181, 3129.35, 466.0739, 5.11178, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+842, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.2056, 3139.662, 466.0739, 0.9229861, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+843, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6607, 3135.829, 466.0739, 2.982475, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+844, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.7237, 3129.272, 466.0739, 5.076865, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+845, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.3703, 3139.533, 466.0739, 0.8880929, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+846, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6165, 3134.263, 466.0739, 3.244272, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+847, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.0365, 3140.354, 466.0739, 1.149884, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+848, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.1017, 3130.017, 466.0739, 5.338665, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+849, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6607, 3135.829, 466.0739, 2.982475, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+850, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.7237, 3129.272, 466.0739, 5.076865, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+851, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.3703, 3139.533, 466.0739, 0.8880929, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+852, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.7135, 3133.642, 466.0739, 3.34901, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+853, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.5906, 3130.411, 466.0739, 5.443391, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+854, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.4507, 3140.581, 466.0739, 1.254604, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+855, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6067, 3134.367, 466.0739, 3.22682, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+856, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.0164, 3129.956, 466.0739, 5.321223, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+857, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.1317, 3140.311, 466.0739, 1.132427, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+858, 92870, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 286.7287, 3334.518, 155.5572, 0.6445118, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+859, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.5925, 3134.576, 466.0739, 3.191907, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+860, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.8425, 3129.839, 466.0739, 5.286323, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+861, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3197, 3140.219, 466.0739, 1.097531, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+862, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.5219, 3341.273, 145.5568, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+863, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.6782, 3135.932, 466.0739, 2.965017, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+864, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.6256, 3129.236, 466.0739, 5.05942, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+865, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.451, 3139.466, 466.0739, 0.8706281, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+866, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.8425, 3129.839, 466.0739, 5.286323, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+867, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 273.5925, 3134.576, 466.0739, 3.191907, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+868, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.3197, 3140.219, 466.0739, 1.097531, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+869, 104214, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 277.5856, 3134.827, 468.122, 0.02526968, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightwell Entity (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+870, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 291.9873, 3132.491, 466.0736, 5.934745, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+871, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.3024, 3140.448, 466.0736, 1.745941, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+872, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.754, 3130.68, 466.0736, 3.840347, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+873, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 291.9507, 3132.393, 466.0736, 5.917285, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+874, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.4057, 3140.466, 466.0736, 1.728488, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+875, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.6873, 3130.761, 466.0736, 3.822886, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+876, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.3331, 3134.962, 466.0736, 0.07041129, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+877, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.9897, 3139.512, 466.0736, 2.164818, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+878, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.721, 3129.146, 466.0736, 4.259205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+879, 105630, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.3895, 3132.611, 466.0532, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Eye of Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 207718 - Eye of Gul'dan)
(@CGUID+880, 105630, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.5572, 3132.068, 466.0532, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Eye of Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 207718 - Eye of Gul'dan)
(@CGUID+881, 105630, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 293.4437, 3136.815, 466.0532, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Eye of Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 207718 - Eye of Gul'dan)
(@CGUID+882, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.29, 3133.709, 466.0736, 6.144188, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+883, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.0969, 3140.102, 466.0736, 1.955377, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+884, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.6568, 3129.81, 466.0736, 4.049762, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+885, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.571, 3135.183, 466.0736, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+886, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.3147, 3135.171, 466.0736, 0.105338, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+887, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.8183, 3139.392, 466.0736, 2.199714, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+888, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.9109, 3129.057, 466.0736, 4.294114, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+889, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.0868, 3132.789, 466.0736, 5.987089, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+890, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.9947, 3140.385, 466.0736, 1.798297, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+891, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 281.9623, 3130.445, 466.0736, 3.892702, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+892, 105630, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 307.6408, 3128.41, 465.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Eye of Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 207718 - Eye of Gul'dan)
(@CGUID+893, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.3028, 3135.275, 466.0736, 0.1227854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+894, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.7341, 3139.33, 466.0736, 2.217182, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+895, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.0069, 3129.016, 466.0736, 4.311568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+896, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.3331, 3134.962, 466.0736, 0.07041129, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+897, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.9897, 3139.512, 466.0736, 2.164818, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+898, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.721, 3129.146, 466.0736, 4.259205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+899, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.29, 3133.709, 466.0736, 6.144188, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+900, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.0969, 3140.102, 466.0736, 1.955377, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+901, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.6568, 3129.81, 466.0736, 4.049762, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+902, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.195, 3133.194, 466.0736, 6.056894, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+903, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.5902, 3140.277, 466.0736, 1.868108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+904, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.2586, 3130.149, 466.0736, 3.962507, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+905, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.439, 3133.047, 466.0736, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+906, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 136.2431, 3228.296, 109.3209, 6.050001, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+907, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 139.8629, 3225.385, 109.3209, 2.002538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+908, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.347, 3134.648, 466.0736, 0.01806738, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+909, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.2546, 3139.681, 466.0736, 2.112457, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+910, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.4423, 3129.291, 466.0736, 4.206853, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+911, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.3028, 3135.275, 466.0736, 0.1227854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+912, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.7341, 3139.33, 466.0736, 2.217182, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+913, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.0069, 3129.016, 466.0736, 4.311568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+914, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.195, 3133.194, 466.0736, 6.056894, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+915, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.5902, 3140.277, 466.0736, 1.868108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+916, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.2586, 3130.149, 466.0736, 3.962507, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+917, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.3028, 3135.275, 466.0736, 0.1227854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+918, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.7341, 3139.33, 466.0736, 2.217182, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+919, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.0069, 3129.016, 466.0736, 4.311568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+920, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.2735, 3135.482, 466.0736, 0.1576757, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+921, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.5692, 3139.201, 466.0736, 2.252075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+922, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.2011, 3128.937, 466.0736, 4.346479, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+923, 68553, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -67.61111, 3421.665, -255.2137, 0.7465991, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- SLG Generic MoP (Large AOI) (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232575 - Door Lock)
(@CGUID+924, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.2746, 3133.605, 466.0736, 6.126705, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+925, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.1943, 3140.14, 466.0736, 1.93793, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+926, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.5749, 3129.875, 466.0736, 4.032332, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+927, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.1753, 3120.346, 465.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+928, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.1542, 3131.646, 465.9335, 2.402481, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+929, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 302.3054, 3121.743, 465.9335, 4.496863, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+930, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 309.306, 3129.424, 465.9335, 0.3080737, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+931, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 300.2637, 3132.599, 465.9335, 2.158116, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+932, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 300.9256, 3122.228, 465.9335, 4.252527, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+933, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 309.5764, 3127.987, 465.9335, 0.06372312, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+934, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.6013, 3120.046, 465.9342, 0.4359182, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+935, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.6371, 3111.536, 465.9342, 4.624723, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+936, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.249, 3120.956, 465.9342, 2.530334, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+937, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 306.9804, 3112.829, 465.9342, 4.859038, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+938, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 310.8057, 3122.492, 465.9342, 0.6702449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+939, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 300.5249, 3120.973, 465.9342, 2.764645, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+940, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.7272, 3112.776, 465.9342, 4.6496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+941, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.4778, 3121.433, 465.9342, 0.4607974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+942, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.106, 3122.085, 465.9342, 2.555212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+943, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.3104, 3112.817, 465.9342, 4.579782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+944, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.6508, 3121.051, 465.9342, 0.3909905, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+945, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.3498, 3122.425, 465.9342, 2.485393, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+946, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 306.4766, 3113.075, 465.9342, 4.770635, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+947, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.14, 3122.362, 465.9342, 0.5818379, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+948, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 300.7654, 3121.757, 465.9342, 2.676246, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+949, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.1084, 3113.415, 465.9342, 4.369206, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+950, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 312.0299, 3120.141, 465.9342, 0.1804203, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+951, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 302.2436, 3123.638, 465.9342, 2.274812, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+952, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.8486, 3113.071, 465.9342, 4.665914, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+953, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.4572, 3121.82, 465.9342, 0.4771253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+954, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.0762, 3122.303, 465.9342, 2.571501, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+955, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 306.4766, 3113.075, 465.9342, 4.770635, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+956, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.14, 3122.362, 465.9342, 0.5818379, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+957, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 300.7654, 3121.757, 465.9342, 2.676246, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+958, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.0101, 3113.451, 465.9342, 4.351752, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+959, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 312.0478, 3120.038, 465.9342, 0.162952, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+960, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 302.324, 3123.705, 465.9342, 2.257353, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+961, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.876, 3124.772, 465.9332, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+962, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.1202, 3113.15, 465.9342, 4.543737, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+963, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.7533, 3121.15, 465.9342, 0.3549417, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+964, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.5085, 3122.894, 465.9342, 2.449347, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+965, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.744, 3113.077, 465.9342, 4.648458, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+966, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.1335, 3122.391, 465.9342, 2.55405, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+967, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.5045, 3121.727, 465.9342, 0.4596624, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+968, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.9144, 3113.188, 465.9342, 4.508836, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+969, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.8227, 3120.952, 465.9342, 0.3200505, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+970, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.6449, 3123.053, 465.9342, 2.414433, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+971, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 306.6854, 3113.091, 465.9342, 4.805538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+972, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.0219, 3122.535, 465.9342, 0.6167338, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+973, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 300.6747, 3121.568, 465.9342, 2.711145, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+974, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.3068, 3113.348, 465.9342, 4.404108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+975, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.9888, 3120.347, 465.9342, 0.2153235, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+976, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 302.0864, 3123.5, 465.9342, 2.309731, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+977, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 286.1649, 3344.857, 145.5568, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+978, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.2236, 3113.133, 465.9342, 4.561196, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+979, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.7161, 3121.248, 465.9342, 0.3723987, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+980, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.4423, 3122.813, 465.9342, 2.466782, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+981, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.3272, 3113.118, 465.9342, 4.578647, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+982, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.6771, 3121.345, 465.9342, 0.3898476, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+983, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 301.3776, 3122.731, 465.9342, 2.484261, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+984, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 304.3068, 3113.348, 465.9342, 4.404108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+985, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.9888, 3120.347, 465.9342, 0.2153235, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+986, 116233, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 302.0864, 3123.5, 465.9342, 2.309731, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fog Cloud (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 229478 - Mythic: Call Add)
(@CGUID+987, 116820, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 155.4757, 3185.904, 111.0176, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+988, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 139.1806, 3190.878, 110.8637, 3.242558, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+989, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 156.5017, 3170.408, 142.9874, 4.895346, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+990, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 149.2361, 3168.998, 142.9874, 5.005446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+991, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 138.5799, 3183.757, 110.8637, 2.549772, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+992, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 302.2713, 3118.722, 465.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+993, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 115.4774, 3191.39, 108.4854, 4.002583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+994, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 111.4306, 3190.26, 108.4854, 6.050001, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+995, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 115.0503, 3187.35, 108.4854, 2.002538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+996, 106522, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.0504, 3185.818, 374.1802, 4.849758, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Archmage Khadgar (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227671 - Arcane Flight)
-- (@CGUID+997, 105371, UNKNOWN, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 0, 0, 5, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Well of Souls (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+998, 116156, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 265.7303, 3109.346, 475.8518, 1.099469, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Light's Heart (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+999, 116156, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 266.1622, 3106.271, 477.2982, 1.099469, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Light's Heart (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+1000, 116156, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 268.9046, 3107.728, 475.8518, 1.099469, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Light's Heart (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+1001, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 282.8008, 3123.014, 466.0333, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
-- (@CGUID+1002, 105371, UNKNOWN, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 0, 0, 5, 3.044832, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Well of Souls (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room)) - !!! on transport - transport template not found !!!
(@CGUID+1003, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 305.6853, 3120.656, 465.998, 0.04184162, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1004, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.4757, 3125.471, 465.998, 2.136245, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1005, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.9106, 3115.088, 465.998, 4.230648, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1006, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 220.6889, 3393.892, 171.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1007, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 218.1833, 3395.752, 172.1916, 2.0944, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1008, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 218.1853, 3395.527, 172.1801, 4.188786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1009, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 218.3732, 3395.638, 172.1686, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1010, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.0193, 3129.665, 465.9636, 1.720237, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1011, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.221, 3119.992, 465.9636, 3.814637, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1012, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.4975, 3121.539, 465.9636, 5.909038, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1013, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.7053, 3391.981, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1014, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 289.5445, 3121.947, 465.9687, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1015, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.568, 3094.068, 465.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+1016, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 231.1061, 3377.027, 171.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1017, 106545, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.1564, 3130.306, 466.0125, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Empowered Eye of Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211107 - Empowered Eye of Gul'dan)
(@CGUID+1018, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.3297, 3129.836, 465.9524, 1.412717, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1019, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.7816, 3121.766, 465.9524, 3.5071, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1020, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 299.0443, 3120.13, 465.9524, 5.601514, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1021, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.2333, 3120.222, 465.9562, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1022, 106545, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 294.3929, 3135.308, 466.0426, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Empowered Eye of Gul'dan (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211107 - Empowered Eye of Gul'dan)
(@CGUID+1023, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 227.6264, 3396.769, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1024, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 284.97, 3127.657, 465.9945, 2.527557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1025, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 289.3322, 3118.224, 465.9945, 4.621961, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1026, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.3199, 3126.718, 465.9945, 0.4331786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1027, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 227.1255, 3403.88, 174.4674, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1028, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.4269, 3404.863, 174.4741, 2.0944, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1029, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.4289, 3402.9, 174.4674, 4.188786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1030, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.0208, 3129.301, 465.9524, 1.116006, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1031, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.3994, 3123.498, 465.9524, 3.210413, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1032, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.7354, 3118.933, 465.9524, 5.304801, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1033, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.8426, 3129.731, 465.9524, 1.325443, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1034, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.616, 3122.263, 465.9524, 3.419828, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1035, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.6971, 3119.738, 465.9524, 5.514228, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1036, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.0208, 3129.301, 465.9524, 1.116006, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1037, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.3994, 3123.498, 465.9524, 3.210413, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1038, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.7354, 3118.933, 465.9524, 5.304801, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1039, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 287.035, 3117.424, 465.9333, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1040, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.6385, 3129.778, 465.9524, 1.360355, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1041, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.677, 3122.062, 465.9524, 3.454751, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1042, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.84, 3119.891, 465.9524, 5.549139, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1043, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.8311, 3129.389, 465.9524, 1.150909, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1044, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.4174, 3123.29, 465.9524, 3.245294, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1045, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.907, 3119.053, 465.9524, 5.339699, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1046, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.6384, 3129.471, 465.9524, 1.185815, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1047, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.4427, 3123.082, 465.9524, 3.28022, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1048, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.0744, 3119.179, 465.9524, 5.374617, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1049, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.8426, 3129.731, 465.9524, 1.325443, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1050, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.616, 3122.263, 465.9524, 3.419828, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1051, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.6971, 3119.738, 465.9524, 5.514228, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1052, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.7408, 3129.756, 465.9524, 1.342901, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1053, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.6456, 3122.162, 465.9524, 3.437305, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1054, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.7692, 3119.814, 465.9524, 5.531684, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1055, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.6016, 3399.059, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1056, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.5698, 3128.996, 465.9524, 1.011296, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1057, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.3891, 3124.126, 465.9524, 3.105696, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1058, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.1967, 3118.61, 465.9524, 5.200073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1059, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.4753, 3122.875, 465.9524, 3.315111, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1060, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.443, 3129.547, 465.9524, 1.220717, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1061, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.2373, 3119.311, 465.9524, 5.409522, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1062, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 296.0448, 3129.677, 465.9524, 1.290539, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1063, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.562, 3122.465, 465.9524, 3.384913, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1064, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.5488, 3119.59, 465.9524, 5.479318, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1065, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.2993, 3129.156, 465.9524, 1.063653, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1066, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.386, 3123.812, 465.9524, 3.158032, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1067, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 297.4702, 3118.765, 465.9524, 5.252444, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1068, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 295.8426, 3129.731, 465.9524, 1.325443, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1069, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.616, 3122.263, 465.9524, 3.419828, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1070, 116710, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 298.6971, 3119.738, 465.9524, 5.514228, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kvaldir Minion (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 179293 - REUSE)
(@CGUID+1071, 92870, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 598.5086, 3178.907, 206.0427, 0.783437, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1072, 92870, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 289.9457, 3102.516, 475.9336, 1.43157, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1073, 106522, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 264.5208, 3102.599, 465.9332, 0.8599688, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Archmage Khadgar (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+1074, 110791, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.6007, 3108.451, 465.9332, 1.65969, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- First Arcanist Thalyssra (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1075, 107997, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 287.7188, 3102.412, 465.9332, 1.655769, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Silgryn (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1076, 116146, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 271.507, 3104.979, 465.9332, 2.197419, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Illidan Stormrage (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 227371 - Encounter Bounds Aura (Broken Room))
(@CGUID+1077, 116372, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 286.1302, 3106.703, 465.9332, 1.68865, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arluelle (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1078, 114838, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 290.1771, 3107.471, 465.9332, 1.647244, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tyrande Whisperwind (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1079, 114841, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.0243, 3106.139, 465.9332, 1.4163, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lady Liadrin (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1080, 114883, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 280.2986, 3100.747, 465.9332, 1.40699, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Grand Magister Rommath (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1081, 115772, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.7587, 3099.921, 465.9332, 1.721975, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1082, 116256, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.0538, 3103.281, 465.9332, 1.842836, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Victoire (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1083, 115840, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.5868, 3103.983, 465.9332, 1.625705, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanist Valtrois (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 105014 - 50% Increased Scale)
(@CGUID+1084, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.8687, 3406.956, 173.4159, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1085, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.9594, 3407.485, 173.4344, 2.0944, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1086, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.9614, 3406.43, 173.4252, 4.188786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1087, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 246.8634, 3388.992, 171.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1088, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 227.9523, 3398.633, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1089, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 222.6184, 3404.318, 174.8118, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1090, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 220.586, 3405.491, 174.8118, 2.0944, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1091, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 220.5857, 3403.144, 174.7988, 4.188787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1092, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 226.4986, 3399.208, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1093, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 226.804, 3398.603, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1094, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 252.3056, 3366.749, 171.8008, 2.478368, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1095, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 232.0434, 3366.313, 171.8008, 5.88176, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1096, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 232.0434, 3366.313, 171.8008, 1.553343, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1097, 113052, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 114.3434, 3117.408, 109.3067, 1.278201, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1098, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 281.9931, 3397.945, 171.8008, 1.308997, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1099, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 236.6528, 3394.978, 171.8008, 2.321288, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1100, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 228.3247, 3400.414, 171.8008, 0.8028514, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1101, 108739, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 252.3177, 3430.545, 171.8008, 4.555854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Carrion Nightmare (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215973 - Carrion Nightmare)
(@CGUID+1102, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 254.3177, 3389.302, 171.8008, 4.08407, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1103, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 228.3247, 3400.414, 171.8008, 6.021386, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1104, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 263.1875, 3395.677, 171.8008, 6.213372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1105, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 260.4392, 3387.945, 171.8008, 3.106686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1106, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 218.599, 3382.499, 171.8008, 5.340707, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1107, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 274.0556, 3395.034, 171.8008, 2.844887, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1108, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 234.2379, 3372.16, 171.8008, 4.677482, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1109, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 232.0434, 3366.313, 171.8008, 1.151917, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1110, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 264.9236, 3402.112, 171.8008, 2.617994, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1111, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 254.349, 3399.181, 171.8008, 1.797689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1112, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 221.4028, 3402.765, 171.8008, 0.1570796, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1113, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 228.3247, 3400.414, 171.8008, 2.251475, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1114, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 264.3038, 3416.504, 171.8008, 5.253441, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1115, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 250.8403, 3417.168, 171.8008, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1116, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 264.9236, 3402.112, 171.8008, 3.333579, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1117, 73400, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 245.7139, 3374.55, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1118, 108739, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 240.7969, 3430.175, 171.8008, 4.931521, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Carrion Nightmare (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215973 - Carrion Nightmare)
(@CGUID+1119, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 218.599, 3382.499, 171.8008, 4.555309, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1120, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 241.8212, 3381.736, 171.8008, 4.014257, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1121, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 258.4635, 3420.984, 171.8008, 2.740167, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1122, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 241.8212, 3381.736, 171.8008, 1.553343, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1123, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 218.599, 3382.499, 171.8008, 0.3665192, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1124, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 228.3247, 3400.414, 171.8008, 1.605703, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1125, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 260.1693, 3387.597, 171.9432, 4.053417, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1126, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 239.9497, 3404.708, 171.8008, 1.413717, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1127, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 260.4392, 3387.945, 171.8008, 0.8377581, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1128, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 264.9236, 3402.112, 171.8008, 1.343904, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1129, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 250.8403, 3417.168, 171.8008, 3.385939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1130, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 213.8004, 3397.443, 171.8008, 0.541052, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1131, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 228.7882, 3389.758, 171.8008, 3.036873, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1132, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 254.2934, 3397.396, 172.0502, 4.681265, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1133, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 241.849, 3429.504, 171.8008, 5.131268, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1134, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 234.2379, 3372.16, 171.8008, 0.2792527, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1135, 108739, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 284.4688, 3399.675, 171.8008, 3.348922, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Carrion Nightmare (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215973 - Carrion Nightmare)
(@CGUID+1136, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 252.3559, 3423.533, 171.8008, 4.328416, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1137, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 268.1441, 3408.886, 171.8008, 0.08726646, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1138, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 258.4635, 3420.984, 171.8008, 3.228859, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1139, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 263.1875, 3395.677, 171.8008, 1.396263, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1140, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 239.9497, 3404.708, 171.8008, 2.460914, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1141, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 258.2899, 3374.24, 171.8008, 1.239184, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1142, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 228.7882, 3389.758, 171.8008, 0.165613, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1143, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 250.8403, 3417.168, 171.8008, 2.234021, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1144, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 274.0556, 3395.034, 171.8008, 2.391101, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1145, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 249.0052, 3375.298, 171.8008, 2.897247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1146, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 232.0434, 3366.313, 171.8008, 1.239184, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1147, 104326, 1530, 8025, 8025, "14,15,16,17", '173', 0, 0, 0, 236.6528, 3394.978, 171.8008, 2.268928, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1148, 104326, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 218.6719, 3375.209, 171.8008, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Phantasmal Bloodfang (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 215605 - Bat Ghost Visual)
(@CGUID+1149, 92870, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 243.5746, 3400.727, 181.801, 3.241815, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1150, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 230.7801, 3401.312, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1151, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.6842, 3407.583, 171.8008, 4.188786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1152, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.6842, 3407.583, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1153, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.6842, 3407.583, 171.8008, 2.0944, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 206893 - Vampiric Aura)
(@CGUID+1154, 108591, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 246.5972, 3351.884, 171.8201, 2.385205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Spellguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
(@CGUID+1155, 108591, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 289.2674, 3394.229, 171.9137, 2.385205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Felsworn Spellguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 202427 - Mod Scale 150%)
-- (@CGUID+1156, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak, 123240 - Grummle Booth B) - !!! on transport - transport template not found !!!
(@CGUID+1176, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 227.2583, 3400.572, 171.8008, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1177, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.9682, 3400.27, 171.8251, 4.188786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1178, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.9762, 3400.276, 171.813, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1179, 108934, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 225.9662, 3400.287, 171.8372, 2.0944, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Blood (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
-- (@CGUID+1180, 32642, UNKNOWN, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Mojodishu (Area: 0 - Difficulty: Looking For Raid) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
(@CGUID+1181, 117085, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 279.2257, 3361.592, 145.7562, 5.485684, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ly'leth Lunastre (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1182, 103758, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 607.7674, 3187.991, 196.6637, 0.681235, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Star Augur Etraeus (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 232550 - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE])
(@CGUID+1183, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 272.5401, 3369.559, 172.7168, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1184, 92870, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 623.9013, 3187.142, 206.0427, 3.119618, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1185, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 313.5232, 3380.945, 148.8839, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1186, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 178.1424, 3136.586, 142.0951, 2.536196, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1187, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 176.4514, 3140.284, 142.0951, 4.53624, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1188, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 173.5399, 3137.253, 142.0951, 0.3004727, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+1189, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 196.4826, 2984.981, 142.9875, 4.544653, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1190, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 211.9722, 2987.354, 142.9874, 4.958754, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1191, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 139.9757, 3134.693, 142.9874, 0.3008062, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1192, 112603, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 95.76389, 3043.241, 109.3197, 2.430738, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1193, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 202.2292, 3082.411, 142.0951, 0.8524517, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1194, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 206.4983, 3084.254, 142.0951, 3.088175, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1195, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 203.1198, 3086.518, 142.0951, 5.088219, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1196, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 144.5747, 3134.031, 142.9874, 2.536528, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1197, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 142.8854, 3137.726, 142.9874, 4.536573, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1198, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 231.9254, 3054.824, 142.0951, 1.687795, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+1199, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 149.7153, 3109.412, 142.9874, 3.484006, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1200, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 144.6719, 3114.236, 142.9874, 4.36932, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1201, 113043, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 95.38021, 3030.984, 112.8204, 5.370285, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Abyss Watcher (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1202, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 233.4236, 3059.226, 142.0951, 3.923519, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1203, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 229.4757, 3058.241, 142.0951, 5.923563, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 211064 - Celerity Zone) (possible waypoints or random movement)
(@CGUID+1204, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 195.1215, 3068.527, 142.0951, 4.222478, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1205, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 199.408, 3063.017, 142.0951, 3.337164, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1206, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 209.5573, 3051.781, 142.0951, 1.027094, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1207, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 216.8648, 3037.325, 142.1367, 3.934382, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 226005 - Blink) (possible waypoints or random movement)
(@CGUID+1208, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 162.2396, 3063.479, 142.9874, 3.38945, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1209, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 158.6458, 3058.981, 142.9874, 1.383791, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1210, 113052, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 101.1979, 2989.276, 109.3152, 6.063646, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadguard (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1211, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 97.76563, 3080.25, 109.3199, 2.626554, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1212, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 95.75174, 3083.778, 109.3199, 4.626599, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1213, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 224.8641, 3037.101, 142.1367, 1.910495, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 226005 - Blink) (possible waypoints or random movement)
(@CGUID+1214, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 209.3993, 3044.75, 142.0951, 1.027094, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1215, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 93.125, 3080.497, 109.3199, 0.3908322, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1216, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 214.8455, 3046.445, 142.0951, 1.027094, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1217, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 157.0955, 3065.828, 142.9874, 5.346361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1218, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 257.9392, 3030.89, 142.0951, 2.566464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1219, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 250.8049, 3028.244, 142.1367, 5.594519, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1220, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 285.2674, 3032.021, 142.0951, 4.925947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1221, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 283.7222, 3028.109, 142.0951, 0.6901805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1222, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 288.2326, 3029.243, 142.0951, 2.925902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1223, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 189.3142, 2999.936, 142.9874, 0.6901805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1224, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 193.8247, 3001.069, 142.9874, 2.925902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1225, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 190.8594, 3003.846, 142.9874, 4.925947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1226, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 320.4668, 3041.105, 142.1364, 3.216583, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1227, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 265.308, 3007.28, 142.9067, 3.170848, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1228, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 260.8973, 3005.029, 142.9067, 3.170862, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+1229, 111227, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -77.11806, 2806.219, 3.244676, 3.656411, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Felweaver Pharamere (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 222078 - Infernal Blade) (possible waypoints or random movement)
(@CGUID+1230, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 258.826, 3002.846, 142.9067, 3.170852, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1231, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 202.2853, 3199.916, 142.0951, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1232, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 196.1609, 3174.98, 142.39, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1233, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 185.1786, 3161.331, 142.0951, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1234, 111225, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -85.375, 2788.696, 3.244673, 1.650522, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chaos Mage Beleron (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+1235, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 91.25868, 3004.147, 109.3195, 2.349946, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1236, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 90.28299, 3008.09, 109.3195, 4.349991, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1237, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 86.86285, 3005.651, 109.3195, 0.114223, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1238, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 108.0503, 2984.656, 109.507, 2.569778, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1239, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 110.7083, 2989.462, 109.507, 3.187671, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1240, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 255.7969, 2993.619, 142.9874, 2.998634, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1241, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 252.6406, 2996.174, 142.9874, 4.99868, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1242, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 86.92882, 3020.936, 110.8635, 5.809042, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1243, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 251.3819, 2992.161, 142.9874, 0.7629136, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1244, 111581, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -86.39236, 2800.839, 14.85734, 3.661615, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fiery Core (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1245, 111226, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -96.98264, 2808.141, 3.244676, 5.690885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Summoner Xiv (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+1246, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 85.0625, 3013.774, 110.8635, 6.235937, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1247, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 255.3733, 2983.22, 109.3202, 5.346361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1248, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 256.9236, 2976.372, 109.3202, 1.383791, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1249, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 260.5174, 2980.87, 109.3202, 3.38945, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1250, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 345.75, 3044.686, 142.0951, 3.62425, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1251, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 214.0556, 2959.742, 109.3067, 0.2196933, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1252, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 137.1059, 2963.017, 109.507, 1.72716, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1253, 111581, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -123.0955, 2778.256, -0.3207624, 3.661615, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fiery Core (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1254, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 218.5755, 2953.508, 109.3067, 0.2206069, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1255, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 162.4065, 2952.268, 109.3067, 0.100774, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1256, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 131.5399, 2960.528, 109.507, 1.530175, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1257, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 137.1111, 2955.861, 109.3144, 2.001544, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1258, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 292.0194, 2986.185, 109.3067, 1.343058, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1259, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 221.2703, 2957.736, 109.3067, 0.221159, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1260, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 308.2141, 2982.268, 109.3067, 0.08121648, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1261, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 160.6076, 2938.288, 110.8636, 1.529063, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1262, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 167.8958, 2939.595, 110.8636, 1.955959, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1263, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 214.0022, 2948.283, 109.3067, 5.882065, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1264, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 152.3038, 2942.236, 109.3195, 1.816347, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1265, 112804, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 230.2689, 2947.667, 109.3067, 0.4231941, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Trained Shadescale (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1266, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 153.4688, 2946.128, 109.3195, 3.816392, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1267, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 149.2847, 2945.769, 109.3194, 5.86381, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1268, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 311.8252, 2975.468, 109.3067, 0.08130671, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1269, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.3767, 2991.092, 110.8636, 4.721676, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1270, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 330.9983, 2990.508, 110.8636, 4.922272, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1271, 112665, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 315.0709, 2979.279, 109.3067, 0.08128815, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Nighthold Protector (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1272, 112676, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 333.1458, 2968.553, 108.4854, 5.867829, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nobleborn Warpcaster (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1273, 116667, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 365.6129, 3052.33, 216.5816, 0.7179957, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+1274, 112671, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 337.901, 2963.389, 108.4854, 1.905259, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Battle-Magus (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1275, 112675, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 338.7743, 2969.08, 108.4854, 3.910918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Sentinel (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1276, 92870, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 203.7193, 3083.352, 152.0952, 4.455253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1277, 116662, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 386.6389, 3031.495, 171.4524, 0.7013893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+1278, 113307, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 371.1717, 2990.606, 109.3067, 2.705742, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Chronowraith (Area: SuramarRaid - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1279, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 200.3137, 3073.303, 142.1395, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1280, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 197.7884, 3074.099, 142.0951, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1281, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 130.672, 2991.555, 109.507, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1282, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 135.087, 2990.251, 109.507, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1283, 73400, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 88.42108, 2942.27, 104.5053, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaid - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1284, 111221, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, -53.33854, 2820.434, 3.244669, 2.71918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Xal'atath (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1285, 105422, 1530, 8025, 8025, "14,15,16,17", '0', 0, 0, 0, 70.04223, 2923.437, 91.90143, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaid - Difficulty: Looking For Raid)
(@CGUID+1286, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -79.0897, 2804.855, 3.24468, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1287, 101002, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -124.0191, 2779.478, 3.742909, 0.5137269, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Krosus (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1288, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -104.8331, 2794.575, 3.244674, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1289, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -103.984, 2789.843, 3.244672, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1290, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -104.7798, 2789.009, 3.244679, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1291, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -107.2957, 2791.328, 3.244676, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1292, 105422, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -109.415, 2791.662, 3.244672, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaidBridge - Difficulty: Looking For Raid)
(@CGUID+1293, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -104.8012, 2792.626, 3.244676, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1294, 73400, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -78.64606, 2805.89, 3.244675, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1295, 105422, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -48.40909, 2819.274, 3.244664, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: SuramarRaidBridge - Difficulty: Looking For Raid)
(@CGUID+1296, 110677, 1530, 8025, 8388, "14,15,16,17", '0', 0, 0, 0, -11.40625, 2834.569, 3.244669, 3.56032, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Image of Khadgar (Area: SuramarRaidBridge - Difficulty: Looking For Raid) (Auras: 220061 - Image of Khadgar)
(@CGUID+1297, 103758, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 607.7674, 3187.991, 196.6637, 0.681235, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Star Augur Etraeus (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 232550 - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE])
(@CGUID+1298, 116670, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 339.0746, 3079.171, 289.498, 2.357195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Portal (Area: 0 - Difficulty: Looking For Raid) (Auras: 232277 - Portal Visual)
(@CGUID+1299, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 309.5889, 3124.738, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1300, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 269.805, 3141.469, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1301, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3077.994, 226.8453, 1.633628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1302, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 235.015, 3101.788, 226.8453, 0.6283186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1303, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3121.456, 226.8453, 2.890264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1304, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 228.011, 3157.231, 226.8453, 5.906193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1305, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.861, 3080.719, 226.8453, 1.884955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1306, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3091.19, 226.8453, 0.8796451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1307, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 339.938, 3135.88, 226.8453, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1308, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.861, 3191.041, 226.8453, 4.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1309, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3086.909, 226.8453, 2.136283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1310, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3150.304, 226.8453, 3.392921, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1311, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3083.4, 226.8453, 1.130974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1312, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3193.765, 226.8453, 4.649557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1313, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3096.176, 226.8453, 2.387612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1314, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3163.822, 226.8453, 3.644247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1315, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3192.853, 226.8453, 4.900885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1316, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3107.938, 226.8453, 2.638939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1317, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3175.583, 226.8453, 3.895574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1318, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3143.149, 226.8453, 6.157523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1319, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3188.36, 226.8453, 5.152212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1320, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3184.851, 226.8453, 4.146902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1321, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3128.611, 226.8453, 0.125663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1322, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3180.57, 226.8453, 5.403541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1323, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3078.907, 226.8453, 1.382301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1324, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 228.011, 3114.529, 226.8453, 0.3769926, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1325, 105315, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 235.015, 3169.971, 226.8453, 5.654867, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1326, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3150.304, 226.8453, 3.392921, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1327, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3163.822, 226.8453, 3.644247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1328, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3175.583, 226.8453, 3.895574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1329, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3150.304, 226.8453, 3.392921, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1330, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3184.851, 226.8453, 4.146902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1331, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.861, 3191.041, 226.8453, 4.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1332, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3163.822, 226.8453, 3.644247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1333, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3193.765, 226.8453, 4.649557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1334, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3192.853, 226.8453, 4.900885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1335, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3188.36, 226.8453, 5.152212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1336, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3180.57, 226.8453, 5.403541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1337, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3175.583, 226.8453, 3.895574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1338, 105422, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 260.1523, 3127.275, 226.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1339, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 235.015, 3169.971, 226.8453, 5.654867, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1340, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 228.011, 3157.231, 226.8453, 5.906193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1341, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3143.149, 226.8453, 6.157523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1342, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3184.851, 226.8453, 4.146902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1343, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3128.611, 226.8453, 0.125663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1344, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 228.011, 3114.529, 226.8453, 0.3769926, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1345, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 235.015, 3101.788, 226.8453, 0.6283186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1346, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.861, 3191.041, 226.8453, 4.398231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1347, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3091.19, 226.8453, 0.8796451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1348, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3083.4, 226.8453, 1.130974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1349, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3078.907, 226.8453, 1.382301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1350, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3077.994, 226.8453, 1.633628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1351, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.861, 3080.719, 226.8453, 1.884955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1352, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3193.765, 226.8453, 4.649557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1353, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3192.853, 226.8453, 4.900885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1354, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3096.176, 226.8453, 2.387612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1355, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3086.909, 226.8453, 2.136283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1356, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3188.36, 226.8453, 5.152212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1357, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3107.938, 226.8453, 2.638939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1358, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3121.456, 226.8453, 2.890264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1359, 105367, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 339.938, 3135.88, 226.8453, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1360, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3180.57, 226.8453, 5.403541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1361, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 235.015, 3169.971, 226.8453, 5.654867, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1362, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 228.011, 3157.231, 226.8453, 5.906193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1363, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3143.149, 226.8453, 6.157523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1364, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 224.3953, 3128.611, 226.8453, 0.125663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1365, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 228.011, 3114.529, 226.8453, 0.3769926, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1366, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 259.1278, 3129.172, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1367, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 235.015, 3101.788, 226.8453, 0.6283186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1368, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.9674, 3091.19, 226.8453, 0.8796451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1369, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 257.2428, 3083.4, 226.8453, 1.130974, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1370, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 271.0699, 3078.907, 226.8453, 1.382301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1371, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 285.5798, 3077.994, 226.8453, 1.633628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1372, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.861, 3080.719, 226.8453, 1.884955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1373, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 313.0159, 3086.909, 226.8453, 2.136283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1374, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 324.2182, 3096.176, 226.8453, 2.387612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1375, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 338.1158, 3121.456, 226.8453, 2.890264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1376, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 332.7638, 3107.938, 226.8453, 2.638939, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1377, 105370, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 339.938, 3135.88, 226.8453, 3.141593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanetic Ring (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1378, 92870, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 244.7173, 3131.203, 236.9225, 0.07044363, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1379, 105364, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 307.6349, 3116.81, 226.99, 2.934292, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1380, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 306.4524, 3114.993, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1381, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 308.2941, 3115.107, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1382, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 296.2694, 3112.816, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1383, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 295.5235, 3110.419, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1384, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 296.7042, 3113.298, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1385, 105958, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 279.7755, 3166.804, 226.8453, 0.09316491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1386, 106680, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 296.2624, 3113.676, 226.9901, 0.09316491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1387, 105958, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 243.3175, 3130.452, 226.8453, 0.09316491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1388, 105958, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 279.1545, 3116.074, 226.8453, 0.09316491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1389, 105958, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 303.9346, 3136.264, 226.8453, 0.09316491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Echo of Elisande (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1390, 107754, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 243.3175, 3130.452, 244.9901, 0.03490658, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: 0 - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+1391, 107754, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 279.1545, 3116.074, 244.9901, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: 0 - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+1392, 107754, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 303.9346, 3136.264, 244.99, 2.80998, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: 0 - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+1393, 107754, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 279.7755, 3166.804, 244.9901, 1.762783, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: 0 - Difficulty: Looking For Raid) (Auras: 213955 - Epocheric Orb)
(@CGUID+1394, 105422, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 291.7502, 3111.691, 226.9901, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tidal Totem (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1395, 92870, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 594.2171, 3185.314, 206.0432, 0.298083, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1396, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 297.0258, 3115.454, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1397, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 297.9848, 3116.192, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1398, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 299.4976, 3115.992, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1399, 73400, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 296.7666, 3116.958, 226.9358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Healing Ran Invisible Stalker DND (Area: 0 - Difficulty: Looking For Raid) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1400, 106330, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 282.3177, 3135.511, 236.7103, 5.497787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elisande (Area: 0 - Difficulty: Looking For Raid) (Auras: 210745 - Etched in Time)
-- (@CGUID+1401, 62822, UNKNOWN, 7813, 7813, 1, '5107 - 5173 - 5200 - 5997 - 6628 - 6629 - 7019 - 7278 - 7519 - 7581 - 7596 - 7705 - 7968', 0, 0, 0, -0.2, 0, -0.2, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cousin Slowhands (Area: ValhallasWarriorOrderHome - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak, 123240 - Grummle Booth B) - !!! on transport - transport template not found !!!
-- (@CGUID+1404, 32642, UNKNOWN, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Mojodishu (Area: 0 - Difficulty: Looking For Raid) (Auras: 61424 - Traveler's Tundra Mammoth) - !!! on transport - transport template not found !!!
(@CGUID+1405, 112955, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 738.3861, 2874.568, 126.1969, 5.497139, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: SuramarRaidSpace - Difficulty: Looking For Raid)
(@CGUID+1406, 112955, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 710.7842, 2835.598, 126.684, 4.450206, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1407, 111303, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 713.882, 2976.602, 126.2944, 5.02422, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1408, 112973, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 653.6597, 2795.788, 125.4, 3.218013, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1409, 112973, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 623.033, 2783.734, 125.3996, 0.6810853, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1410, 111295, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 674.2639, 2950.055, 127.1103, 4.859993, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Domesticated Manasaber (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1411, 112595, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 636.6771, 2893.405, 123.3245, 1.059772, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1412, 112973, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 649.5, 2802.332, 125.4011, 3.678307, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1413, 112595, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 642.257, 2895.809, 123.3245, 3.097565, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1414, 111303, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 710.6667, 2974.889, 126.2244, 5.478725, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1415, 112955, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 698.2277, 2815.058, 127.0134, 2.151964, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: SuramarRaidSpace - Difficulty: Looking For Raid)
(@CGUID+1416, 112603, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 695.2552, 2834.571, 125.259, 4.991992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1417, 112973, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 625.1736, 2808.266, 125.3996, 5.469242, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1418, 111303, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 718.5243, 2976.667, 126.2173, 4.39222, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1419, 112973, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 621.467, 2801.451, 125.3995, 5.91416, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1420, 112678, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 637.7066, 2898.491, 123.3245, 4.509731, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1421, 112973, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 632.934, 2809.707, 125.4017, 5.015439, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1422, 111303, 1530, 8025, 8389, "14,15,16,17", '0', 0, 0, 0, 640.7656, 2892.449, 123.3245, 2.432416, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidSpace - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1423, 112603, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 704.6198, 2803.535, 126.4591, 6.019719, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1424, 112603, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 699.632, 2799.01, 125.0957, 4.846516, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1425, 111295, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 731.1357, 2955.49, 124.4999, 6.237174, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Domesticated Manasaber (Area: 0 - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1426, 112603, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 707.7361, 2807.008, 126.2445, 5.151884, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1427, 112973, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 651.1563, 2788.295, 125.4009, 2.749341, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1428, 112595, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 733.1464, 2953.314, 124.4056, 6.206004, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%) (possible waypoints or random movement)
(@CGUID+1429, 112973, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 627.408, 2777.157, 125.4036, 1.097675, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1430, 112973, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 635.132, 2776.427, 125.4026, 1.508124, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Weaver (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%, 224861 - Arcane Channel)
(@CGUID+1431, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 731.6072, 2900.218, 124.8722, 0.9402608, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1432, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 732.0609, 2897.655, 124.8582, 0.7978378, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1433, 112956, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 638.9505, 2856.003, 124.7023, 4.043966, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1434, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 655.2879, 2849.55, 125.3812, 1.744382, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1435, 111295, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 736.9531, 2888.339, 125.0169, 1.53028, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Domesticated Manasaber (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1436, 109164, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 678.9375, 2756.681, 125.3331, 2.423896, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- High Botanist Tel'arn (Area: 0 - Difficulty: Looking For Raid) (Auras: 216897 - Share Health)
(@CGUID+1437, 111303, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 732.967, 2934.429, 126.1752, 2.181685, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1438, 104528, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 678.2986, 2757.03, 125.3331, 2.397755, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- High Botanist Tel'arn (Area: 0 - Difficulty: Looking For Raid) (Auras: 218502 - Recursive Strikes)
(@CGUID+1439, 112678, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 667.2292, 2878.251, 127.5001, 0.8984888, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1440, 112678, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 750.0562, 2902.665, 124.5628, 4.206279, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1441, 111295, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 670.8125, 2876.101, 126.9483, 0.8984888, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Domesticated Manasaber (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1442, 112595, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 685.5625, 2852.524, 125.5826, 2.94421, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1443, 112595, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 604.5018, 2829.849, 125.3433, 2.589605, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1444, 112603, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 608.5156, 2728.423, 125.5603, 4.200055, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1445, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 768.1285, 2904.524, 126.6907, 2.244577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1446, 112603, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 646.5018, 2732.462, 125.3331, 4.853331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrace Grove-Tender (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1447, 112595, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 652.1962, 2830.951, 125.3331, 4.075687, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1448, 111295, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 650.2761, 2832.58, 125.3331, 4.327458, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Domesticated Manasaber (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1449, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 778.2917, 2914.555, 126.6899, 2.102315, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid)
(@CGUID+1450, 111303, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 746.908, 2867.686, 126.1217, 0.483254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1451, 112678, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 603.4688, 2825.142, 125.3503, 2.373323, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1452, 112595, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 599.2847, 2823.918, 125.3177, 2.091391, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1453, 112678, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 775.5174, 2896.674, 126.6063, 5.843914, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1454, 112678, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 749.7882, 2866.873, 126.1322, 2.376388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1455, 112956, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 726.5066, 2842.913, 123.983, 0.7315085, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: 0 - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1456, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 679.2758, 2828.563, 125.3318, 4.175309, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid) (Auras: ) (possible waypoints or random movement)
(@CGUID+1457, 112595, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 777.0452, 2892.097, 126.6063, 1.638043, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: 0 - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1458, 111303, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 779.0521, 2898.083, 126.6063, 4.471269, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: 0 - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1459, 112955, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 618.3191, 2721.973, 126.9993, 2.442853, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: 0 - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1460, 112596, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 604.3835, 2818.638, 125.3179, 1.038306, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Duskwatch Warden (Area: 0 - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1461, 92870, 1530, 8025, 0, "14,15,16,17", '0', 0, 0, 0, 616.314, 3024.858, 138.5076, 5.748356, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: 0 - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1462, 112956, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 722.2913, 2788.695, 126.0206, 1.017936, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1463, 112956, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 584.5363, 2790.291, 124.7399, 1.779298, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (possible waypoints or random movement)
(@CGUID+1464, 112955, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 537.108, 2694.591, 122.5906, 0.7616127, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1465, 112955, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 527.2845, 2688.212, 122.3824, 4.123689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shadescale Wyrm (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1466, 112596, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 634.9494, 2754.494, 125.3679, 3.044623, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1467, 112596, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 585.8697, 2760.383, 125.1077, 0.454159, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1468, 111303, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 542.3108, 2793.975, 123.3245, 1.30606, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1469, 110341, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 670.2743, 2763.781, 125.3331, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanist Tel'arn (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1470, 112678, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 540.3906, 2796.595, 123.3245, 0.4212247, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1471, 112595, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 541.9549, 2799.695, 123.3245, 5.494909, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1472, 112678, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 545.3264, 2797.211, 123.3245, 3.59578, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1473, 112595, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 541.3368, 2776.728, 127.4944, 4.195005, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1474, 112595, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 546.9271, 2732.419, 121.1953, 3.168418, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1475, 112596, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 543.7309, 2736.196, 121.1943, 3.825068, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1476, 112956, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 579.578, 2728.234, 121.8296, 1.424278, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1477, 112956, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 621.9809, 2707.25, 125.2132, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1478, 112596, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 544.592, 2728.396, 121.1392, 2.20114, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Duskwatch Warden (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1479, 112956, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 562.7045, 2719.884, 121.8969, 0.2757528, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1480, 112678, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 549.173, 2713.097, 120.8589, 1.884668, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%) (possible waypoints or random movement)
(@CGUID+1481, 111303, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 501.9254, 2757.8, 121.3912, 4.471269, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1482, 111303, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 579.7882, 2684.24, 120.6545, 4.471269, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1483, 111303, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 577.7813, 2678.253, 120.6756, 1.638043, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1484, 111295, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 563.3438, 2676.339, 120.9267, 1.842296, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Domesticated Manasaber (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1485, 112595, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 576.2535, 2682.83, 120.8177, 5.843913, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1486, 112595, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 498.3906, 2756.391, 121.3912, 5.843913, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Archmage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 160758 - Mod Scale 140%)
(@CGUID+1487, 112678, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 499.9184, 2751.814, 121.3681, 1.638043, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shal'dorei Naturalist (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1488, 111303, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 529.3489, 2697.795, 121.6499, 4.702948, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1489, 112956, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 513.5273, 2696.164, 120.9004, 1.091686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Shimmering Manaspine (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1490, 111303, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 479.7691, 2710.85, 118.9368, 3.371239, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Sage (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 188236 - Mod Scale 125%)
(@CGUID+1491, 109583, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 656.6723, 2782.147, 125.5101, 1.466077, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Solar Collapse Stalker (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1492, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 640.7322, 2814.388, 125.5686, 5.094412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218357 - Parasitic Fetter)
(@CGUID+1493, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 654.5907, 2794.14, 125.568, 5.069107, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1494, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 655.056, 2777.77, 125.3953, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1495, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 610.007, 2787.85, 125.4043, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1496, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 640.286, 2817.88, 125.3983, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1497, 109583, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 660.4586, 2802.245, 125.5099, 1.43117, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Solar Collapse Stalker (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1498, 92870, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 637.8885, 2788.024, 135.3853, 5.972192, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1499, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 651.3782, 2807.711, 125.5741, 4.954452, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218357 - Parasitic Fetter)
(@CGUID+1500, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 658.9012, 2787.305, 125.59, 4.769359, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1501, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 660.6779, 2777.898, 125.3866, 0.6898727, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1502, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 655.056, 2777.77, 125.3953, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1503, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 610.007, 2787.85, 125.4043, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1504, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 640.286, 2817.88, 125.3983, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1505, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 626.9672, 2809.25, 125.5493, 5.528614, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218357 - Parasitic Fetter)
(@CGUID+1506, 109583, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 656.1255, 2784.194, 125.3849, 2.740167, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Solar Collapse Stalker (Area: SuramarRaidGarden - Difficulty: Looking For Raid)
(@CGUID+1507, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 653.1099, 2786.697, 125.5852, 2.073404, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: )
(@CGUID+1508, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 655.056, 2777.77, 125.3953, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1509, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 610.007, 2787.85, 125.4043, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1510, 109804, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 640.286, 2817.88, 125.3983, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Plasma Sphere (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218520 - Plasma Sphere)
(@CGUID+1511, 109075, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 629.1953, 2791.969, 125.481, 6.262758, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Parasitic Lasher (Area: SuramarRaidGarden - Difficulty: Looking For Raid) (Auras: 218357 - Parasitic Fetter)
(@CGUID+1512, 109583, 1530, 8025, 8348, "14,15,16,17", '0', 0, 0, 0, 652.4758, 2794.96, 125.385, 4.869469, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Solar Collapse Stalker (Area: SuramarRaidGarden - Difficulty: Looking For Raid)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1536;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, '190299'), -- Resolute Courtesan - 190299 - Warden Salute
(@CGUID+1, 0, 0, 33554432, 1, 0, 0, 0, 0, '225958 221577'), -- Astral Farseer - 225958 - Spellcaster, 221577 - Arcane Burst
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Resolute Courtesan
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Stardancer
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Midnight Siphoner
(@CGUID+5, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- The Nightwell
(@CGUID+6, 0, 0, 50331648, 1, 0, 0, 0, 0, '208861'), -- Elisande - 208861 - Etched in Time
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+16, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+17, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+18, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+29, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+36, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+40, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+41, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+43, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+44, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+45, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+46, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+47, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+48, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+50, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+51, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+53, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+57, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+59, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+60, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+61, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+62, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+64, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+65, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+66, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+67, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+68, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+69, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+70, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+76, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic MoP (Large AOI)
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+80, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+82, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+84, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+85, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic MoP (Large AOI)
(@CGUID+87, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+89, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+91, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tichondrius
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+100, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Hakmud of Argus - 61424 - Traveler's Tundra Mammoth
(@CGUID+102, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Koak Hoburn - 46598 - Ride Vehicle Hardcoded
(@CGUID+104, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+105, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- Cousin Slowhands - 122729 - Grand Expedition Yak
(@CGUID+107, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Hakmud of Argus - 61424 - Traveler's Tundra Mammoth
(@CGUID+110, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+111, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+112, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+114, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+116, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+117, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+118, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+119, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+120, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+121, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+122, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+123, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+124, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+125, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+126, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+127, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+128, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+129, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+130, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+131, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+132, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+133, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+134, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+135, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+136, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+137, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+138, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+139, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+140, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+141, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+142, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+143, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+144, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+145, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+146, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+147, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+148, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+149, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+150, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+151, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+152, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+153, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+154, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+155, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+156, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+157, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+158, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+159, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+160, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+161, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+162, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+163, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+164, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+165, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+166, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+167, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+168, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+169, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+170, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+171, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+172, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+173, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+174, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+175, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+176, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+177, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+178, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+179, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+180, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+181, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+182, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+183, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+184, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+185, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+186, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+187, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+188, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+189, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+190, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+191, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+192, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+193, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+194, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+195, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+196, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+197, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Hakmud of Argus - 61424 - Traveler's Tundra Mammoth
(@CGUID+199, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+200, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+201, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+203, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+204, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+205, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+206, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+207, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+208, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+209, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+210, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+211, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+213, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+218, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+219, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+220, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+221, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+222, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+223, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+224, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+225, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+226, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+227, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+229, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+230, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+231, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Withered Skulker
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Withered Skulker
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+238, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+240, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+241, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+242, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+245, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+250, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+251, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Withered Skulker
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+257, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - 211064 - Celerity Zone
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- First Arcanist Thalyssra - 211064 - Celerity Zone
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+264, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+268, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Withered Skulker
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+271, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Withered Skulker
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+280, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+288, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+289, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+290, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+291, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+295, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+298, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+299, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+301, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+302, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+312, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+314, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+315, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+316, 0, 0, 0, 1, 0, 11760, 0, 0, ''), -- Shambling Hungerer
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+319, 0, 0, 0, 1, 0, 11760, 0, 0, ''), -- Shambling Hungerer
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+321, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+322, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+323, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+326, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+327, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+329, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+330, 0, 0, 0, 1, 0, 11760, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+331, 0, 0, 0, 1, 0, 11760, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+332, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+335, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+338, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, '224825'), -- Celestial Acolyte - 224825 - Containment Field
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+349, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nether Elemental
(@CGUID+351, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, '224825'), -- Celestial Acolyte - 224825 - Containment Field
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, '224655'), -- Astrologer Jarin - 224655 - Nightborne Astrologer Views Planets
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spellblade Aluriel
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+368, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+372, 0, 0, 50331648, 1, 0, 0, 0, 0, '232550'), -- Star Augur Etraeus - 232550 - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE]
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic MoP (Large AOI)
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+379, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- Fallen Defender
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+383, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+386, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+387, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+394, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+398, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, '226005'), -- Trained Shadescale - 226005 - Blink
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shambling Hungerer
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Promenade Guard
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+416, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+417, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+418, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+420, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+421, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ly'leth Lunastre
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+427, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+428, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+431, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+432, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+434, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+435, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+436, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+440, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+441, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+442, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+443, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+444, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+445, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+446, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+454, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+456, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+458, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+459, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+460, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+461, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+462, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+463, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+464, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+466, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+472, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, '224814'), -- Celestial Acolyte - 224814 - Cosmetic Nightborne Reading Book
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, '224814'), -- Celestial Acolyte - 224814 - Cosmetic Nightborne Reading Book
(@CGUID+483, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, '224439'), -- Celestial Acolyte - 224439 - Cosmetic Use Standing Loop
(@CGUID+485, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+487, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+488, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+489, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+490, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+491, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- Manaflush Noble - 225579 - Imbibe Nightwell
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- Manaflush Noble - 225579 - Imbibe Nightwell
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+496, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- Manaflush Noble - 225579 - Imbibe Nightwell
(@CGUID+497, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, '224439'), -- Celestial Acolyte - 224439 - Cosmetic Use Standing Loop
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+503, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+510, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, '224814'), -- Celestial Acolyte - 224814 - Cosmetic Nightborne Reading Book
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+523, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+525, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+526, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+528, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+529, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+533, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+534, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+535, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+537, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+541, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+544, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+546, 0, 0, 0, 1, 0, 0, 0, 0, '224840'), -- SLG Generic MoP (Large AOI) - 224840 - Mana Orb Visual
(@CGUID+547, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+548, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+549, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+550, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+551, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+553, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+554, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+556, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+557, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+558, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+560, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+561, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+562, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+563, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+564, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+565, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+566, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+567, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Star Shooting Stalker
(@CGUID+568, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+570, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- Manaflush Noble - 225579 - Imbibe Nightwell
(@CGUID+571, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- Manaflush Noble - 225579 - Imbibe Nightwell
(@CGUID+572, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+573, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+574, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+575, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+576, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+577, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+578, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+579, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+580, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+581, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- Cousin Slowhands - 122729 - Grand Expedition Yak
(@CGUID+582, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+583, 0, 0, 50331648, 1, 0, 0, 0, 0, '210745'), -- Elisande - 210745 - Etched in Time
(@CGUID+584, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- Cousin Slowhands - 122729 - Grand Expedition Yak
(@CGUID+585, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+586, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+587, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+588, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+589, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+590, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+591, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+592, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+593, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+594, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Hakmud of Argus - 61424 - Traveler's Tundra Mammoth
(@CGUID+595, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- Manaflush Noble - 225579 - Imbibe Nightwell
(@CGUID+596, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+597, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+598, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+599, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+600, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Citizen
(@CGUID+601, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+602, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+603, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+604, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+605, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+607, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+608, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+609, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+610, 0, 0, 0, 1, 0, 0, 0, 0, '122729 123240'), -- Cousin Slowhands - 122729 - Grand Expedition Yak, 123240 - Grummle Booth B
(@CGUID+611, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Celestial Acolyte
(@CGUID+612, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Astral Defender
(@CGUID+613, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sidereal Familiar
(@CGUID+614, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+615, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+616, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+617, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+618, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+619, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+620, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+621, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+622, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+623, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+624, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+625, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+626, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+627, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+628, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+629, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- Cousin Slowhands - 122729 - Grand Expedition Yak
(@CGUID+630, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+631, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+632, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+633, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+634, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- Cousin Slowhands - 122729 - Grand Expedition Yak
(@CGUID+635, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+636, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+637, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+638, 0, 0, 0, 1, 0, 0, 0, 0, '213179'), -- Spellblade Aluriel - 213179 - Searing Brand
(@CGUID+639, 0, 0, 0, 1, 0, 0, 0, 0, '213179'), -- Spellblade Aluriel - 213179 - Searing Brand
(@CGUID+640, 0, 0, 0, 1, 0, 0, 0, 0, '213179'), -- Spellblade Aluriel - 213179 - Searing Brand
(@CGUID+641, 0, 0, 0, 1, 0, 0, 0, 0, '213179'), -- Spellblade Aluriel - 213179 - Searing Brand
(@CGUID+642, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+643, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+644, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+645, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+646, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+647, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+648, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+649, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+650, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Archmage Khadgar
(@CGUID+651, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+652, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lady Liadrin
(@CGUID+654, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tyrande Whisperwind
(@CGUID+655, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Grand Magister Rommath
(@CGUID+656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kal
(@CGUID+657, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Victoire
(@CGUID+658, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcanist Valtrois
(@CGUID+659, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arluelle
(@CGUID+660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silgryn
(@CGUID+661, 0, 0, 0, 1, 0, 0, 0, 0, '227639 227743 227554 212294 227037 227371 206261'), -- Gul'dan - 227639 - Gul'dan, 227743 - The Eye of Aman'thul, 227554 - Fel Scythe, 212294 - Parasitic Wound, 227037 - Parasitic Wound, 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+662, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 227371 206261'), -- The Eye of Aman'thul - 46598 - Ride Vehicle Hardcoded, 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+663, 0, 0, 0, 1, 0, 0, 0, 0, '227371 206261'), -- The Eye of Aman'thul - 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+664, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+665, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+666, 0, 0, 0, 1, 0, 0, 0, 0, '227371 206261'), -- Xal'atath - 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+667, 0, 0, 50331648, 1, 0, 0, 0, 0, '208903 227371 206261'), -- Lord Illidan Stormrage - 208903 - Gul'dan, 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+668, 0, 0, 0, 1, 0, 0, 0, 0, '227371 206261'), -- The Eye of Aman'thul - 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+669, 0, 0, 0, 1, 0, 0, 0, 0, '227371 206261'), -- The Eye of Aman'thul - 227371 - Encounter Bounds Aura (Broken Room), 206261 - Encounter Bounds Aura (Intact Room)
(@CGUID+670, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+671, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Cousin Slowhands - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+672, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+673, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+674, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+675, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Mojodishu - 61424 - Traveler's Tundra Mammoth
(@CGUID+676, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+677, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Mojodishu - 61424 - Traveler's Tundra Mammoth
(@CGUID+678, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+679, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+680, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- Cousin Slowhands - 122729 - Grand Expedition Yak
(@CGUID+681, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+682, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+683, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+684, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+685, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+687, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+688, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+689, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+690, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+691, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+692, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+693, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+694, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+695, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+696, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Tidal Totem - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+697, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+698, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+699, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+700, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+701, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+702, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+703, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+704, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+705, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+706, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+707, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+708, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+709, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+710, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+711, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+712, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+713, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+714, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+715, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+716, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+717, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+718, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+719, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+720, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+721, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+722, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+723, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+724, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+725, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+726, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+727, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ly'leth Lunastre
(@CGUID+728, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+729, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+731, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+732, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- First Arcanist Thalyssra
(@CGUID+733, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+734, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+735, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+736, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+737, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kirin Tor Guardian
(@CGUID+738, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+739, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic MoP (Large AOI)
(@CGUID+740, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+741, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+742, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+743, 0, 0, 50331648, 1, 0, 0, 0, 0, '206893'), -- Abyss Watcher - 206893 - Vampiric Aura
(@CGUID+744, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+745, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+746, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+747, 0, 0, 0, 1, 0, 0, 0, 0, '217507'), -- Tichondrius - 217507 - Tich Light
(@CGUID+748, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+749, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+750, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+751, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+752, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+753, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Shadowblade - 202427 - Mod Scale 150%
(@CGUID+754, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+755, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Felsworn Chaos-Mage - 188236 - Mod Scale 125%
(@CGUID+756, 0, 0, 33554432, 1, 0, 0, 0, 0, '225958 221485'), -- Astral Farseer - 225958 - Spellcaster, 221485 - Spellcasting
(@CGUID+757, 0, 0, 0, 1, 0, 0, 0, 0, '190299'), -- Resolute Courtesan - 190299 - Warden Salute
(@CGUID+758, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+759, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+760, 0, 0, 50331648, 1, 0, 0, 0, 0, '208861'), -- Elisande - 208861 - Etched in Time
(@CGUID+761, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+762, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+763, 0, 0, 0, 1, 0, 0, 0, 0, '207257'), -- Combat Stalker - 207257 - Bat Spawner
(@CGUID+764, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- The Nightwell
(@CGUID+765, 0, 0, 0, 1, 0, 0, 0, 0, '190299'), -- Resolute Courtesan - 190299 - Warden Salute
(@CGUID+766, 0, 0, 0, 1, 0, 0, 0, 0, '221589'), -- Twilight Stardancer - 221589 - Focused
(@CGUID+767, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+768, 0, 0, 0, 1, 0, 0, 0, 0, '221340'), -- Midnight Siphoner - 221340 - Siphon Nightwell
(@CGUID+769, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+770, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+771, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+772, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+773, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+774, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+775, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+776, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+777, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+778, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+779, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+780, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+781, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+782, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+783, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+784, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+785, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+786, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+787, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+788, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+789, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+790, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+791, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic MoP (Large AOI)
(@CGUID+792, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+793, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Tidal Totem - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+794, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+795, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+796, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+797, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+798, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+799, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+800, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+801, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+802, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+803, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+804, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+805, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+806, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+807, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+808, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+809, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+810, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+811, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+812, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+813, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+814, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+815, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+816, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+817, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+818, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+819, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+820, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+821, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+822, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+823, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+824, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+825, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+826, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+827, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+828, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+829, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+830, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+831, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+832, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+833, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+834, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+835, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+836, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+837, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+838, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+839, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+840, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+841, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+842, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+843, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+844, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+845, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+846, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+847, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+848, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+849, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+850, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+851, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+852, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+853, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+854, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+855, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+856, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+857, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+858, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+859, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+860, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+861, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+862, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+863, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+864, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+865, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+866, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+867, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+868, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+869, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightwell Entity
(@CGUID+870, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+871, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+872, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+873, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+874, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+875, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+876, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+877, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+878, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+879, 0, 0, 33554432, 1, 0, 0, 0, 0, '207718'), -- Eye of Gul'dan - 207718 - Eye of Gul'dan
(@CGUID+880, 0, 0, 33554432, 1, 0, 0, 0, 0, '207718'), -- Eye of Gul'dan - 207718 - Eye of Gul'dan
(@CGUID+881, 0, 0, 33554432, 1, 0, 0, 0, 0, '207718'), -- Eye of Gul'dan - 207718 - Eye of Gul'dan
(@CGUID+882, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+883, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+884, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+885, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+886, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+887, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+888, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+889, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+890, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+891, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+892, 0, 0, 33554432, 1, 0, 0, 0, 0, '207718'), -- Eye of Gul'dan - 207718 - Eye of Gul'dan
(@CGUID+893, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+894, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+895, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+896, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+897, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+898, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+899, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+900, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+901, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+902, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+903, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+904, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+905, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+906, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+907, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+908, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+909, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+910, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+911, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+912, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+913, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+914, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+915, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+916, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+917, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+918, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+919, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+920, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+921, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+922, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+923, 0, 0, 0, 1, 0, 0, 0, 0, '232575'), -- SLG Generic MoP (Large AOI) - 232575 - Door Lock
(@CGUID+924, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+925, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+926, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+927, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Tidal Totem - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+928, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+929, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+930, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+931, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+932, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+933, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+934, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+935, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+936, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+937, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+938, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+939, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+940, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+941, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+942, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+943, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+944, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+945, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+946, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+947, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+948, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+949, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+950, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+951, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+952, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+953, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+954, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+955, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+956, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+957, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+958, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+959, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+960, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+961, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+962, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+963, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+964, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+965, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+966, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+967, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+968, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+969, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+970, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+971, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+972, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+973, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+974, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+975, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+976, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+977, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+978, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+979, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+980, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+981, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+982, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+983, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+984, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+985, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+986, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- Fog Cloud - 229478 - Mythic: Call Add
(@CGUID+987, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+988, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+989, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+990, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+991, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+992, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Tidal Totem - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+993, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+994, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+995, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+996, 0, 0, 0, 1, 0, 0, 0, 0, '227671'), -- Archmage Khadgar - 227671 - Arcane Flight
(@CGUID+997, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Well of Souls - 46598 - Ride Vehicle Hardcoded
(@CGUID+998, 0, 0, 50331648, 1, 0, 0, 0, 0, '227371'), -- Light's Heart - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+999, 0, 0, 50331648, 1, 0, 0, 0, 0, '227371'), -- Light's Heart - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+1000, 0, 0, 50331648, 1, 0, 0, 0, 0, '227371'), -- Light's Heart - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+1001, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1002, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Well of Souls - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+1003, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1004, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1005, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1006, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1007, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1008, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1009, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1010, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1011, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1012, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1013, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1014, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1015, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Tidal Totem - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+1016, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1017, 0, 0, 33554432, 1, 0, 0, 0, 0, '211107'), -- Empowered Eye of Gul'dan - 211107 - Empowered Eye of Gul'dan
(@CGUID+1018, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1019, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1020, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1021, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1022, 0, 0, 33554432, 1, 0, 0, 0, 0, '211107'), -- Empowered Eye of Gul'dan - 211107 - Empowered Eye of Gul'dan
(@CGUID+1023, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1024, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1025, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1026, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1027, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1028, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1029, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1030, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1031, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1032, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1033, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1034, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1035, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1036, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1037, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1038, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1039, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1040, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1041, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1042, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1043, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1044, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1045, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1046, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1047, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1048, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1049, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1050, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1051, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1052, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1053, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1054, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1055, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1056, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1057, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1058, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1059, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1060, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1061, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1062, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1063, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1064, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1065, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1066, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1067, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1068, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1069, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1070, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- Kvaldir Minion - 179293 - REUSE
(@CGUID+1071, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1072, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1073, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Archmage Khadgar - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+1074, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- First Arcanist Thalyssra - 105014 - 50% Increased Scale
(@CGUID+1075, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Silgryn - 105014 - 50% Increased Scale
(@CGUID+1076, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Illidan Stormrage - 227371 - Encounter Bounds Aura (Broken Room)
(@CGUID+1077, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Arluelle - 105014 - 50% Increased Scale
(@CGUID+1078, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Tyrande Whisperwind - 105014 - 50% Increased Scale
(@CGUID+1079, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Lady Liadrin - 105014 - 50% Increased Scale
(@CGUID+1080, 0, 0, 0, 257, 0, 0, 0, 0, '105014'), -- Grand Magister Rommath - 105014 - 50% Increased Scale
(@CGUID+1081, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Kal - 105014 - 50% Increased Scale
(@CGUID+1082, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Victoire - 105014 - 50% Increased Scale
(@CGUID+1083, 0, 0, 0, 1, 0, 0, 0, 0, '105014'), -- Arcanist Valtrois - 105014 - 50% Increased Scale
(@CGUID+1084, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1085, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1086, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1087, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1088, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1089, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1090, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1091, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1092, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1093, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1094, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1095, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1096, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1097, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+1098, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1099, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1100, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1101, 0, 0, 0, 1, 0, 12418, 0, 0, '215973'), -- Carrion Nightmare - 215973 - Carrion Nightmare
(@CGUID+1102, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1103, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1104, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1105, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1106, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1107, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1108, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1109, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1110, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1111, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1112, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1113, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1114, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1115, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1116, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1117, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1118, 0, 0, 0, 1, 0, 12418, 0, 0, '215973'), -- Carrion Nightmare - 215973 - Carrion Nightmare
(@CGUID+1119, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1120, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1121, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1122, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1123, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1124, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1125, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1126, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1127, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1128, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1129, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1130, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1131, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1132, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1133, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1134, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1135, 0, 0, 0, 1, 0, 12418, 0, 0, '215973'), -- Carrion Nightmare - 215973 - Carrion Nightmare
(@CGUID+1136, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1137, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1138, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1139, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1140, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1141, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1142, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1143, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1144, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1145, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1146, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1147, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1148, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- Phantasmal Bloodfang - 215605 - Bat Ghost Visual
(@CGUID+1149, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1150, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1151, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1152, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1153, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- Tainted Blood - 206893 - Vampiric Aura
(@CGUID+1154, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Spellguard - 202427 - Mod Scale 150%
(@CGUID+1155, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- Felsworn Spellguard - 202427 - Mod Scale 150%
(@CGUID+1156, 0, 0, 0, 1, 0, 0, 0, 0, '122729 123240'), -- Cousin Slowhands - 122729 - Grand Expedition Yak, 123240 - Grummle Booth B
(@CGUID+1157, 0, 0, 0, 1, 0, 12290, 0, 0, ''), -- Battlelord's Armor
(@CGUID+1158, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1159, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Aerylia
(@CGUID+1160, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Haklang Ulfsson
(@CGUID+1161, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1162, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Einar the Runecaster
(@CGUID+1163, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1165, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyseer Ghrent
(@CGUID+1167, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fjornson Stonecarver
(@CGUID+1169, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Captain Hjalmar Stahlstrom
(@CGUID+1170, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Eye of Odyn
(@CGUID+1171, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Odyn
(@CGUID+1172, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1173, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1174, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1175, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1176, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1177, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Blood
(@CGUID+1178, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Blood
(@CGUID+1179, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Blood
(@CGUID+1180, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Mojodishu - 61424 - Traveler's Tundra Mammoth
(@CGUID+1181, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ly'leth Lunastre
(@CGUID+1182, 0, 0, 50331648, 1, 0, 1626, 0, 0, '232550'), -- Star Augur Etraeus - 232550 - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE]
(@CGUID+1183, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1184, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1185, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1186, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1187, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1188, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1189, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1190, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1191, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1192, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1193, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1194, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1195, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1196, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1197, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1198, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1199, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1200, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1201, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Abyss Watcher
(@CGUID+1202, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1203, 0, 0, 0, 0, 0, 0, 0, 0, '211064'), -- Duskwatch Sentinel - 211064 - Celerity Zone
(@CGUID+1204, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1205, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1206, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1207, 0, 0, 0, 1, 0, 0, 0, 0, '226005'), -- Trained Shadescale - 226005 - Blink
(@CGUID+1208, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1209, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dreadguard
(@CGUID+1211, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1212, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1213, 0, 0, 0, 1, 0, 0, 0, 0, '226005'), -- Trained Shadescale - 226005 - Blink
(@CGUID+1214, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+1215, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1216, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1217, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+1219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+1220, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1221, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1222, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1223, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1224, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1225, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1226, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+1227, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1228, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1229, 0, 0, 0, 1, 0, 0, 0, 0, '222078'), -- Felweaver Pharamere - 222078 - Infernal Blade
(@CGUID+1230, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1231, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1233, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1234, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Chaos Mage Beleron - 123978 - Mod Scale 95-120%
(@CGUID+1235, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1236, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1237, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1238, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1239, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1240, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1241, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1243, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1244, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fiery Core
(@CGUID+1245, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Summoner Xiv - 123978 - Mod Scale 95-120%
(@CGUID+1246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1247, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1248, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1249, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+1251, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1252, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1253, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fiery Core
(@CGUID+1254, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+1256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1257, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+1258, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+1259, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+1260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1263, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+1264, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1265, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Trained Shadescale
(@CGUID+1266, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1267, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1268, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nighthold Protector
(@CGUID+1272, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- Nobleborn Warpcaster - 160758 - Mod Scale 140%
(@CGUID+1273, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+1274, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Battle-Magus
(@CGUID+1275, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskwatch Sentinel
(@CGUID+1276, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1277, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+1278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chronowraith
(@CGUID+1279, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1280, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1281, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1282, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1283, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1284, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+1285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1286, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1287, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Krosus
(@CGUID+1288, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1289, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1290, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1291, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1292, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1293, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1294, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1295, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1296, 0, 0, 0, 1, 0, 0, 0, 0, '220061'), -- Image of Khadgar - 220061 - Image of Khadgar
(@CGUID+1297, 0, 0, 50331648, 1, 0, 1626, 0, 0, '232550'), -- Star Augur Etraeus - 232550 - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE]
(@CGUID+1298, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- Suramar Portal - 232277 - Portal Visual
(@CGUID+1299, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1300, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1301, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1302, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1303, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1304, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1305, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1306, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1307, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1308, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1309, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1310, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1311, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1312, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1313, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1314, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1315, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1316, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1317, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1318, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1319, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1320, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1321, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1322, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1323, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1324, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1325, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1326, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1327, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1328, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1329, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1330, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1331, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1332, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1333, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1334, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1335, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1336, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1337, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1338, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1339, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1340, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1341, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1342, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1343, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1344, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1345, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1346, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1347, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1348, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1349, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1350, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1351, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1352, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1353, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1354, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1355, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1356, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1357, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1358, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1359, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1360, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1361, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1362, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1363, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1364, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1365, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1366, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1367, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1368, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1369, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1370, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1371, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1372, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1373, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1374, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1375, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1376, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1377, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Arcanetic Ring
(@CGUID+1378, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1379, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+1380, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1381, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1382, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1383, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1384, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1385, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+1386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+1387, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+1388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+1389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Echo of Elisande
(@CGUID+1390, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+1391, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+1392, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+1393, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- Elisande - 213955 - Epocheric Orb
(@CGUID+1394, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+1395, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1396, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1397, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1398, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1399, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+1400, 0, 0, 50331648, 1, 0, 0, 0, 0, '210745'), -- Elisande - 210745 - Etched in Time
(@CGUID+1401, 0, 0, 0, 1, 0, 0, 0, 0, '122729 123240'), -- Cousin Slowhands - 122729 - Grand Expedition Yak, 123240 - Grummle Booth B
(@CGUID+1402, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1403, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1404, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Mojodishu - 61424 - Traveler's Tundra Mammoth
(@CGUID+1405, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+1406, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+1407, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1408, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1409, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1410, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- Domesticated Manasaber
(@CGUID+1411, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1412, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1413, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1414, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1415, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+1416, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1417, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1418, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1419, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1420, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1421, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1422, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1423, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1424, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Domesticated Manasaber
(@CGUID+1426, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1427, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1428, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1429, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1430, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- Duskwatch Weaver - 160758 - Mod Scale 140%, 224861 - Arcane Channel
(@CGUID+1431, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1432, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1434, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1435, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- Domesticated Manasaber
(@CGUID+1436, 0, 0, 0, 1, 0, 0, 0, 0, '216897'), -- High Botanist Tel'arn - 216897 - Share Health
(@CGUID+1437, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1438, 0, 0, 0, 1, 0, 0, 0, 0, '218502'), -- High Botanist Tel'arn - 218502 - Recursive Strikes
(@CGUID+1439, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1440, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1441, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Domesticated Manasaber
(@CGUID+1442, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1443, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1444, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1445, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1446, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Terrace Grove-Tender - 188236 - Mod Scale 125%
(@CGUID+1447, 0, 0, 1, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1448, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Domesticated Manasaber
(@CGUID+1449, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1450, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1451, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1452, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1453, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1454, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1455, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1456, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1457, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1458, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1459, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+1460, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1461, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1462, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1463, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1464, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+1465, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Shadescale Wyrm
(@CGUID+1466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1468, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcanist Tel'arn
(@CGUID+1470, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1471, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1472, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1473, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1474, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1475, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1476, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1477, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1478, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Duskwatch Warden
(@CGUID+1479, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1480, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1481, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1482, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1483, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1484, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- Domesticated Manasaber
(@CGUID+1485, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1486, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- Shal'dorei Archmage - 160758 - Mod Scale 140%
(@CGUID+1487, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Shal'dorei Naturalist - 188236 - Mod Scale 125%
(@CGUID+1488, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1489, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shimmering Manaspine
(@CGUID+1490, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- Nightborne Sage - 188236 - Mod Scale 125%
(@CGUID+1491, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Solar Collapse Stalker
(@CGUID+1492, 0, 0, 0, 1, 0, 0, 0, 0, '218357'), -- Parasitic Lasher - 218357 - Parasitic Fetter
(@CGUID+1493, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Parasitic Lasher
(@CGUID+1494, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1495, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1496, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1497, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Solar Collapse Stalker
(@CGUID+1498, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+1499, 0, 0, 0, 1, 0, 0, 0, 0, '218357'), -- Parasitic Lasher - 218357 - Parasitic Fetter
(@CGUID+1500, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Parasitic Lasher
(@CGUID+1501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Parasitic Lasher
(@CGUID+1502, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1503, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1504, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1505, 0, 0, 0, 1, 0, 0, 0, 0, '218357'), -- Parasitic Lasher - 218357 - Parasitic Fetter
(@CGUID+1506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Solar Collapse Stalker
(@CGUID+1507, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Parasitic Lasher
(@CGUID+1508, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1509, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1510, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- Plasma Sphere - 218520 - Plasma Sphere
(@CGUID+1511, 0, 0, 0, 1, 0, 0, 0, 0, '218357'), -- Parasitic Lasher - 218357 - Parasitic Fetter
(@CGUID+1512, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Solar Collapse Stalker
(@CGUID+1513, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Aerylia
(@CGUID+1514, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1515, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Quartermaster Durnolf
(@CGUID+1516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1517, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Haklang Ulfsson
(@CGUID+1518, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1519, 0, 0, 0, 1, 0, 12290, 0, 0, ''), -- Battlelord's Armor
(@CGUID+1520, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Eye of Odyn
(@CGUID+1521, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Captain Hjalmar Stahlstrom
(@CGUID+1522, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1523, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1524, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyseer Ghrent
(@CGUID+1525, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1526, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fjornson Stonecarver
(@CGUID+1527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1528, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1529, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Einar the Runecaster
(@CGUID+1530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stormforged Valarjar
(@CGUID+1531, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1532, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1533, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Odyn
(@CGUID+1534, 0, 0, 0, 1, 0, 0, 0, 0, '52642'), -- Stormforged Valarjar - 52642 - Dull Weapons
(@CGUID+1535, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Val'kyr of Odyn
(@CGUID+1536, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- Val'kyr of Odyn

ALTER TABLE gameobject DROP COLUMN isActive;

SET @OGUID := 860000;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES 
(@OGUID+1, 256877, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 582.49, 2678.55, 120.569, 1.22173, 0, 0, 0.573576, 0.819152, 604800, 255, 1, '', 26365),
(@OGUID+2, 256876, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 580.344, 2679.31, 120.569, 0.802851, 0, 0, 0.390731, 0.920505, 604800, 255, 1, '', 26365),
(@OGUID+3, 256879, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 583.759, 2681.92, 120.569, 4.33715, 0, 0, -0.826589, 0.562806, 604800, 255, 1, '', 26365),
(@OGUID+4, 256878, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 584.778, 2677.81, 120.569, 1.28282, 0, 0, 0.598325, 0.801254, 604800, 255, 1, '', 26365),
(@OGUID+5, 256881, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 579.09, 2681.67, 120.573, 5.92539, 0, 0, -0.177943, 0.984041, 604800, 255, 1, '', 26365),
(@OGUID+6, 256880, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 581.688, 2682.78, 120.569, 4.55531, 0, 0, -0.760405, 0.649449, 604800, 255, 1, '', 26365),
(@OGUID+7, 256883, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 586.118, 2681.3, 120.57, 4.65131, 0, 0, -0.72837, 0.685184, 604800, 255, 1, '', 26365),
(@OGUID+8, 256882, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 586.766, 2678.87, 120.571, 2.75761, 0, 0, 0.981627, 0.190812, 604800, 255, 1, '', 26365),
(@OGUID+9, 256903, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 533.986, 2775.25, 127.411, 0.139625, 0, 0, 0.0697555, 0.997564, 604800, 255, 1, '', 26365),
(@OGUID+10, 256902, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 534.67, 2773.23, 127.411, 0.820307, 0, 0, 0.39875, 0.917059, 604800, 255, 1, '', 26365),
(@OGUID+11, 256873, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 547.641, 2771.66, 127.411, 2.19039, 0, 0, 0.889017, 0.457874, 604800, 255, 1, '', 26365),
(@OGUID+12, 256875, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 537.109, 2772.64, 127.411, 1.8326, 0, 0, 0.793354, 0.60876, 604800, 255, 1, '', 26365),
(@OGUID+13, 256901, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 545.132, 2775.33, 127.411, 5.48907, 0, 0, -0.386709, 0.922202, 604800, 255, 1, '', 26365),
(@OGUID+14, 256874, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 549.113, 2773.2, 127.411, 2.87106, 0, 0, 0.990866, 0.134852, 604800, 255, 1, '', 26365),
(@OGUID+15, 256885, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 743.809, 2861.79, 126.049, 1.9984, 0, 0, 0.841039, 0.540975, 604800, 255, 1, '', 26365),
(@OGUID+16, 256884, 1530, 8025, 8348, '14,15,16,17', 0, 0, 0, -1, 742.028, 2863.11, 126.049, 5.5676, 0, 0, -0.350207, 0.936672, 604800, 255, 1, '', 26365),
(@OGUID+17, 256887, 1530, 8025, 8389, '14,15,16,17', 0, 0, 0, -1, 707.88, 2978.5, 126.376, 5.8238, 0.0140548, 0.0642204, -0.227124, 0.971644, 604800, 255, 1, '', 26365),
(@OGUID+18, 233282, 1530, 8025, 8389, '14,15,16,17', 0, 0, 0, -1, 248.201, 3128.64, 226.907, 0.725015, 0, 0, 0.35462, 0.935011, 604800, 255, 1, '', 26365),
(@OGUID+19, 256893, 1530, 8025, 8389, '14,15,16,17', 0, 0, 0, -1, 453.246, 3028.29, 143.975, 1.09955, 0, 0, 0.522497, 0.852641, 604800, 255, 1, '', 26365),
(@OGUID+20, 256892, 1530, 8025, 8389, '14,15,16,17', 0, 0, 0, -1, 458.493, 3030.24, 143.976, 2.61799, 0, 0, 0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+21, 233282, 1530, 8025, 8389, '14,15,16,17', 0, 0, 0, -1, 593.891, 3171.15, 196.107, 0.0925585, 0, 0, 0.0462627, 0.998929, 604800, 255, 1, '', 26365),
(@OGUID+22, 248513, 1530, 8025, 8388, '14,15,16,17', 0, 0, 0, -1, -18.8108, 2839.46, 3.16134, 3.6707, 0, 0, -0.96521, 0.261476, 604800, 255, 1, '', 26365),
(@OGUID+23, 255926, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 386.622, 3031.55, 171.277, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+24, 251259, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 241.054, 3414.29, 171.907, 0.635402, 0, 0, 0.312384, 0.949956, 604800, 255, 1, '', 26365),
(@OGUID+25, 251259, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 243.047, 3376.3, 171.907, 5.33324, 0, 0, -0.457314, 0.889305, 604800, 255, 1, '', 26365),
(@OGUID+26, 251259, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 223.116, 3397.13, 171.907, 3.89353, 0, 0, -0.930152, 0.367175, 604800, 255, 1, '', 26365),
(@OGUID+27, 250082, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.198, 3135.81, 465.85, 3.24536, 0, 0, -0.998654, 0.0518602, 604800, 255, 1, '', 26365),
(@OGUID+28, 251033, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -967.254, 4435.98, 735.737, 2.16421, 0, 0, 0.882947, 0.469473, 604800, 255, 1, '', 26365),
(@OGUID+29, 242174, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -960.444, 4325, 740.158, 0.890117, 0, 0, 0.43051, 0.902586, 604800, 255, 1, '', 26365),
(@OGUID+30, 266919, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1235.95, 4205.98, -65.1805, 2.61799, 0, 0, 0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+31, 252322, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 273.4, 3135.17, -237.065, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+32, 252349, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 162.025, 3220.88, -225.78, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+33, 254240, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -69.1153, 3420.24, -265.13, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+34, 247973, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+35, 247972, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+36, 247971, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+37, 247970, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+38, 251844, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1100.5, 3435.93, 20.7628, 4.53786, 0, 0, -0.766044, 0.642789, 604800, 255, 1, '', 26365),
(@OGUID+39, 252105, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.7536, 3476, -249.978, 5.45801, 0, 0, -0.400981, 0.916086, 604800, 255, 0, '', 26365),
(@OGUID+40, 252103, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.6137, 3411.8, -250.389, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+41, 251519, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 128.62, 3254.37, -225.612, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+42, 253988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 101.112, 2954.19, 108.911, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+43, 251397, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 418.252, 3269.75, -224.57, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+44, 251398, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 400.234, 3251.71, -224.424, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+45, 266181, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+46, 266180, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+47, 266183, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+48, 266182, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+49, 260985, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+50, 252321, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.148, 3179.33, 438.941, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+51, 252320, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.592, 3091.18, 438.941, 5.49779, 0, 0, -0.382682, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+52, 266174, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.349, 3135.41, 464.98, 3.83973, 0, 0, -0.939692, 0.342021, 604800, 255, 1, '', 26365),
(@OGUID+53, 252348, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 370.308, 3221.55, -225.78, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+54, 252319, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.303, 3179.78, 438.941, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+55, 252318, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+56, 266395, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 1.5708, 0, 0, 0.707107, 0.707107, 604800, 255, 1, '', 26365),
(@OGUID+57, 251988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.747, 3091.62, 438.941, 0.785399, 0, 0, 0.382684, 0.923879, 604800, 255, 1, '', 26365),
(@OGUID+58, 251984, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 558.055, 3084.65, 148.595, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+59, 250241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 470.96, 3258.62, -225.562, 3.3685, 0, 0, -0.993571, 0.113208, 604800, 255, 1, '', 26365),
(@OGUID+60, 250243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 495.448, 3347.27, -225.562, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+61, 250242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 406.708, 3323.29, -225.562, 1.29154, 0, 0, 0.601815, 0.798635, 604800, 255, 1, '', 26365),
(@OGUID+62, 253462, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 347.977, 3201.06, 72.6628, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+63, 251401, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+64, 251609, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 246.843, 3171.53, 296.644, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+65, 251611, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 318.424, 3099.9, 296.644, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+66, 251610, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 341.045, 3077, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+67, 248932, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 586.881, 3167.01, 198.061, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+68, 252316, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.241, 3094.77, 227.221, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+69, 254242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 479.949, 3114.23, 173.413, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+70, 251982, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.227, 3091.31, 146.791, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+71, 252435, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+72, 258847, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 142.035, 3187, 110.98, 6.18719, 0, 0, -0.0479775, 0.998848, 604800, 255, 1, '', 26365),
(@OGUID+73, 253989, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 577.799, 3430.88, 108.911, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+74, 251608, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 223.902, 3194.11, 227.221, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+75, 252315, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 241.672, 3176.31, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+76, 254241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 549.432, 3208.23, 109.36, 4.67748, 0, 0, -0.719339, 0.694659, 604800, 255, 1, '', 26365),
(@OGUID+77, 254243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 492.031, 3127.71, 150.653, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+78, 251685, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 466.397, 3111.55, 148.52, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+79, 251684, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 531.466, 3176.84, 148.52, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+80, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 314.076, 3104.14, 146.8, 5.50553, 0, 0, -0.379104, 0.925354, 604800, 255, 1, '', 26365),
(@OGUID+81, 251330, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.506, 3135.57, 226.859, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+82, 255928, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 178.445, 3239.73, 171.283, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+83, 255925, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 199.175, 3218.98, 216.211, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+84, 256872, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 545.901, 3227.47, 142.888, 3.15906, 0, 0, -0.999962, 0.00873464, 604800, 255, 1, '', 26365),
(@OGUID+85, 256857, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 545.055, 3246.65, 142.888, 3.21142, 0, 0, -0.999391, 0.0349061, 604800, 255, 1, '', 26365),
(@OGUID+86, 251612, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.344, 3176.39, 227.23, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+87, 253924, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 283.198, 3414.1, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+88, 253923, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 226.57, 3357.47, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+89, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.997, 3166.86, 146.81, 5.48892, 0, 0, -0.386774, 0.922175, 604800, 255, 1, '', 26365),
(@OGUID+90, 252317, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.482, 3135.58, 145.196, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+91, 251983, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 461.111, 3181.49, 148.609, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+92, 258843, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 333.977, 3186.94, 227.009, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+93, 256894, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 187.993, 3302, 142.007, 1.22173, 0, 0, 0.573576, 0.819152, 604800, 255, 1, '', 26365),
(@OGUID+94, 266173, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.857, 3385.09, 148.778, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+95, 256899, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 371.934, 3399.32, 142.888, 4.71239, 0, 0, -0.707106, 0.707108, 604800, 255, 1, '', 26365),
(@OGUID+96, 256898, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 391.184, 3399.03, 142.888, 4.68621, 0, 0, -0.716301, 0.697792, 604800, 255, 1, '', 26365),
(@OGUID+97, 253178, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 269.559, 3370.91, 172.636, 2.36439, 0, 0, 0.92544, 0.378895, 604800, 255, 0, '', 26365),
(@OGUID+98, 266959, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 279.319, 3361.54, 145.473, 5.47663, 0, 0, -0.392436, 0.919779, 604800, 255, 1, '', 26365),
(@OGUID+99, 251687, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 293.266, 3389.96, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+100, 251686, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.635, 3347.35, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+101, 251683, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 255.552, 3316.56, 148.778, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+102, 250082, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.198, 3135.81, 465.85, 3.56104, 0, 0, -0.978088, 0.20819, 604800, 255, 1, '', 26365),
(@OGUID+103, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 339.121, 3079.11, 289.415, 5.48892, 0, 0, -0.386774, 0.922175, 604800, 255, 1, '', 26365),
(@OGUID+104, 233282, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 244.49, 3124.4, 465.907, 0.498516, 0, 0, 0.246685, 0.969096, 604800, 255, 1, '', 26365),
(@OGUID+105, 251844, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1100.5, 3435.93, 20.7628, 4.53786, 0, 0, -0.766044, 0.642789, 604800, 255, 1, '', 26365),
(@OGUID+106, 266919, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1235.95, 4205.98, -65.1805, 2.61799, 0, 0, 0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+107, 266173, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.857, 3385.09, 148.778, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+108, 253989, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 577.799, 3430.88, 108.911, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+109, 253988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 101.112, 2954.19, 108.911, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+110, 248932, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 586.881, 3167.01, 198.061, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+111, 250241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 470.96, 3258.62, -225.562, 3.3685, 0, 0, -0.993571, 0.113208, 604800, 255, 1, '', 26365),
(@OGUID+112, 250243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 495.448, 3347.27, -225.562, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+113, 250242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 406.708, 3323.29, -225.562, 1.29154, 0, 0, 0.601815, 0.798635, 604800, 255, 1, '', 26365),
(@OGUID+114, 251519, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 128.62, 3254.37, -225.612, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+115, 252349, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 162.025, 3220.88, -225.78, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+116, 252348, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 370.308, 3221.55, -225.78, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+117, 251401, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+118, 251397, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 418.252, 3269.75, -224.57, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+119, 251398, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 400.234, 3251.71, -224.424, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+120, 254241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 549.432, 3208.23, 109.36, 4.67748, 0, 0, -0.719339, 0.694659, 604800, 255, 1, '', 26365),
(@OGUID+121, 254240, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -69.1153, 3420.24, -265.13, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+122, 251984, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 558.055, 3084.65, 148.595, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+123, 252435, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+124, 252105, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.7536, 3476, -249.978, 5.45801, 0, 0, -0.400981, 0.916086, 604800, 255, 0, '', 26365),
(@OGUID+125, 252103, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.6137, 3411.8, -250.389, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+126, 247973, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+127, 247972, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+128, 247971, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+129, 247970, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+130, 251684, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 531.466, 3176.84, 148.52, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+131, 251687, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 293.266, 3389.96, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+132, 251686, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.635, 3347.35, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+133, 251683, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 255.552, 3316.56, 148.778, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+134, 258847, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 142.035, 3187, 110.98, 6.18719, 0, 0, -0.0479775, 0.998848, 604800, 255, 1, '', 26365),
(@OGUID+135, 253924, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 283.198, 3414.1, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+136, 253923, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 226.57, 3357.47, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+137, 252316, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.241, 3094.77, 227.221, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+138, 252319, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.303, 3179.78, 438.941, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+139, 252315, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 241.672, 3176.31, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+140, 251612, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.344, 3176.39, 227.23, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+141, 251609, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 246.843, 3171.53, 296.644, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+142, 251608, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 223.902, 3194.11, 227.221, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+143, 251611, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 318.424, 3099.9, 296.644, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+144, 251610, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 341.045, 3077, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+145, 254243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 492.031, 3127.71, 150.653, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+146, 254242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 479.949, 3114.23, 173.413, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+147, 251988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.747, 3091.62, 438.941, 0.785399, 0, 0, 0.382684, 0.923879, 604800, 255, 1, '', 26365),
(@OGUID+148, 251981, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.779, 3179.86, 146.791, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+149, 251983, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 461.111, 3181.49, 148.609, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+150, 251982, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.227, 3091.31, 146.791, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+151, 251685, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 466.397, 3111.55, 148.52, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+152, 266181, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+153, 266180, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+154, 266183, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+155, 266182, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+156, 266174, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.349, 3135.41, 464.98, 3.83973, 0, 0, -0.939692, 0.342021, 604800, 255, 1, '', 26365),
(@OGUID+157, 260985, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+158, 252321, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.148, 3179.33, 438.941, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+159, 252320, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.592, 3091.18, 438.941, 5.49779, 0, 0, -0.382682, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+160, 252318, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+161, 266395, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 1.5708, 0, 0, 0.707107, 0.707107, 604800, 255, 1, '', 26365),
(@OGUID+162, 253462, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 347.977, 3201.06, 72.6628, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+163, 253128, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 575.196, 3429.05, 111.855, 0.683464, 0, 0, 0.335119, 0.942176, 604800, 255, 1, '', 26365),
(@OGUID+164, 258848, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 155.574, 3185.84, 110.605, 3.05027, 0, 0, 0.998958, 0.0456471, 604800, 255, 1, '', 26365),
(@OGUID+165, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 339.121, 3079.11, 289.415, 5.48892, 0, 0, -0.386774, 0.922175, 604800, 255, 1, '', 26365),
(@OGUID+166, 255926, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 386.622, 3031.55, 171.277, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+167, 255927, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 365.853, 3052.3, 216.211, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+168, 251330, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.506, 3135.57, 226.859, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+169, 255928, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 178.445, 3239.73, 171.283, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+170, 255925, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 199.175, 3218.98, 216.211, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+171, 256894, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 187.993, 3302, 142.007, 1.22173, 0, 0, 0.573576, 0.819152, 604800, 255, 1, '', 26365),
(@OGUID+172, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 314.076, 3104.14, 146.8, 5.50553, 0, 0, -0.379104, 0.925354, 604800, 255, 1, '', 26365),
(@OGUID+173, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.997, 3166.86, 146.81, 5.48892, 0, 0, -0.386774, 0.922175, 604800, 255, 1, '', 26365),
(@OGUID+174, 252317, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.482, 3135.58, 145.196, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+175, 258843, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 333.977, 3186.94, 227.009, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+176, 256893, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 453.246, 3028.29, 143.975, 1.09955, 0, 0, 0.522497, 0.852641, 604800, 255, 1, '', 26365),
(@OGUID+177, 233282, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 409.022, 3340.98, 59.9067, 4.43425, 0, 0, -0.798302, 0.602258, 604800, 255, 1, '', 26365),
(@OGUID+178, 256872, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 545.901, 3227.47, 142.888, 3.15906, 0, 0, -0.999962, 0.00873464, 604800, 255, 1, '', 26365),
(@OGUID+179, 260985, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+180, 251988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.747, 3091.62, 438.941, 0.785399, 0, 0, 0.382684, 0.923879, 604800, 255, 1, '', 26365),
(@OGUID+181, 266181, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+182, 266180, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+183, 266183, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+184, 266182, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+185, 266174, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.349, 3135.41, 464.98, 3.83973, 0, 0, -0.939692, 0.342021, 604800, 255, 1, '', 26365),
(@OGUID+186, 252320, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.592, 3091.18, 438.941, 5.49779, 0, 0, -0.382682, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+187, 252318, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+188, 266959, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 279.319, 3361.54, 145.473, 5.47663, 0, 0, -0.392436, 0.919779, 604800, 255, 1, '', 26365),
(@OGUID+189, 266395, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 1.5708, 0, 0, 0.707107, 0.707107, 604800, 255, 1, '', 26365),
(@OGUID+190, 247972, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+191, 254239, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 492.336, 4064.58, 0.101564, 2.93364, 0, 0, 0.994599, 0.103789, 604800, 255, 24, '', 26365),
(@OGUID+192, 254148, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 869.861, 4216.88, 0.101564, 2.20305, 0, 0, 0.891897, 0.452238, 604800, 255, 24, '', 26365),
(@OGUID+193, 254147, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1234.82, 3738.02, 0.151466, 2.69406, 0.00101376, -0.00167465, 0.975066, 0.221906, 604800, 255, 24, '', 26365),
(@OGUID+194, 266919, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1235.95, 4205.98, -65.1805, 2.61799, 0, 0, 0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+195, 251844, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1100.5, 3435.93, 20.7628, 4.53786, 0, 0, -0.766044, 0.642789, 604800, 255, 1, '', 26365),
(@OGUID+196, 253988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 101.112, 2954.19, 108.911, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+197, 251833, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 674.507, 2828.93, 125.25, 3.94851, 0, 0, -0.919708, 0.392603, 604800, 255, 0, '', 26365),
(@OGUID+198, 251832, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 610.502, 2761.56, 125.25, 3.93683, 0, 0, -0.921987, 0.387222, 604800, 255, 0, '', 26365),
(@OGUID+199, 265470, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 638.838, 4056.75, 0.101564, 3.59904, 0, 0, -0.973956, 0.226737, 604800, 255, 24, '', 26365),
(@OGUID+200, 265469, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 817.164, 3901.8, 0.101564, 1.28795, 0, 0, 0.600378, 0.799716, 604800, 255, 24, '', 26365),
(@OGUID+201, 253462, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 347.977, 3201.06, 72.6628, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+202, 252321, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.148, 3179.33, 438.941, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+203, 252322, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 273.4, 3135.17, -237.065, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+204, 252349, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 162.025, 3220.88, -225.78, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+205, 252319, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.303, 3179.78, 438.941, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+206, 259929, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 617.342, 3812.09, 0.101564, 2.18519, -0.00187349, -0.000592232, 0.887823, 0.460181, 604800, 255, 24, '', 26365),
(@OGUID+207, 254240, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -69.1153, 3420.24, -265.13, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+208, 247973, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+209, 247971, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+210, 247970, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+211, 251611, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 318.424, 3099.9, 296.644, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+212, 254276, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 684.087, 3851.78, 0.101564, 0.18242, 0, 0, 0.0910835, 0.995843, 604800, 255, 24, '', 26365),
(@OGUID+213, 254238, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 324.921, 3909.51, 0.101564, 0.785521, 0, 0, 0.38274, 0.923856, 604800, 255, 24, '', 26365),
(@OGUID+214, 254149, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1007.97, 3777.79, 0.101517, 2.9475, 0, 0, 0.995295, 0.0968955, 604800, 255, 24, '', 26365),
(@OGUID+215, 251519, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 128.62, 3254.37, -225.612, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+216, 252105, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.7536, 3476, -249.978, 5.45801, 0, 0, -0.400981, 0.916086, 604800, 255, 0, '', 26365),
(@OGUID+217, 252103, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.6137, 3411.8, -250.389, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+218, 251982, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.227, 3091.31, 146.791, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+219, 250241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 470.96, 3258.62, -225.562, 3.3685, 0, 0, -0.993571, 0.113208, 604800, 255, 1, '', 26365),
(@OGUID+220, 250243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 495.448, 3347.27, -225.562, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+221, 250242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 406.708, 3323.29, -225.562, 1.29154, 0, 0, 0.601815, 0.798635, 604800, 255, 1, '', 26365),
(@OGUID+222, 251984, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 558.055, 3084.65, 148.595, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+223, 252435, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+224, 251685, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 466.397, 3111.55, 148.52, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+225, 252348, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 370.308, 3221.55, -225.78, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+226, 252316, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.241, 3094.77, 227.221, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+227, 252315, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 241.672, 3176.31, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+228, 254243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 492.031, 3127.71, 150.653, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+229, 254242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 479.949, 3114.23, 173.413, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+230, 251612, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.344, 3176.39, 227.23, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+231, 251609, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 246.843, 3171.53, 296.644, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+232, 251608, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 223.902, 3194.11, 227.221, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+233, 251610, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 341.045, 3077, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+234, 254145, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 441.961, 3749.59, 0.101564, 5.79802, 0, 0, -0.240211, 0.970721, 604800, 255, 24, '', 26365),
(@OGUID+235, 258847, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 142.035, 3187, 110.98, 6.18719, 0, 0, -0.0479775, 0.998848, 604800, 255, 1, '', 26365),
(@OGUID+236, 248932, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 586.881, 3167.01, 198.061, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+237, 251401, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+238, 251397, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 418.252, 3269.75, -224.57, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+239, 251398, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 400.234, 3251.71, -224.424, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+240, 251981, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.779, 3179.86, 146.791, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+241, 251983, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 461.111, 3181.49, 148.609, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+242, 253924, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 283.198, 3414.1, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+243, 251684, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 531.466, 3176.84, 148.52, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+244, 251687, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 293.266, 3389.96, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+245, 251686, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.635, 3347.35, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+246, 253923, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 226.57, 3357.47, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+247, 251683, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 255.552, 3316.56, 148.778, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+248, 254241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 549.432, 3208.23, 109.36, 4.67748, 0, 0, -0.719339, 0.694659, 604800, 255, 1, '', 26365),
(@OGUID+249, 256857, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 545.055, 3246.65, 142.888, 3.21142, 0, 0, -0.999391, 0.0349061, 604800, 255, 1, '', 26365),
(@OGUID+250, 253989, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 577.799, 3430.88, 108.911, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+251, 243403, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 580.464, 3433.17, 109.517, 3.94541, 0, 0, -0.920316, 0.391176, 604800, 255, 1, '', 26365),
(@OGUID+252, 266173, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.857, 3385.09, 148.778, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+253, 256899, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 371.934, 3399.32, 142.888, 4.71239, 0, 0, -0.707106, 0.707108, 604800, 255, 1, '', 26365),
(@OGUID+254, 256898, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 391.184, 3399.03, 142.888, 4.68621, 0, 0, -0.716301, 0.697792, 604800, 255, 1, '', 26365),
(@OGUID+255, 256894, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 187.993, 3302, 142.007, 1.22173, 0, 0, 0.573576, 0.819152, 604800, 255, 1, '', 26365),
(@OGUID+256, 258848, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 155.574, 3185.84, 110.605, 3.05027, 0, 0, 0.998958, 0.0456471, 604800, 255, 1, '', 26365),
(@OGUID+257, 255928, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 178.445, 3239.73, 171.283, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+258, 251844, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1100.5, 3435.93, 20.7628, 4.53786, 0, 0, -0.766044, 0.642789, 604800, 255, 1, '', 26365),
(@OGUID+259, 266919, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 1235.95, 4205.98, -65.1805, 2.61799, 0, 0, 0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+260, 254240, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -69.1153, 3420.24, -265.13, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+261, 247973, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+262, 247972, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+263, 247971, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+264, 247970, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -34.882, 2830.16, -80.3633, 3.6652, 0, 0, -0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+265, 252322, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 273.4, 3135.17, -237.065, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+266, 252349, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 162.025, 3220.88, -225.78, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+267, 252348, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 370.308, 3221.55, -225.78, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+268, 253989, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 577.799, 3430.88, 108.911, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+269, 253924, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 283.198, 3414.1, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+270, 248513, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, -18.8108, 2839.46, 3.16134, 3.6707, 0, 0, -0.96521, 0.261476, 604800, 255, 1, '', 26365),
(@OGUID+271, 251401, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+272, 251397, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 418.252, 3269.75, -224.57, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+273, 251398, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 400.234, 3251.71, -224.424, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+274, 252105, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.7536, 3476, -249.978, 5.45801, 0, 0, -0.400981, 0.916086, 604800, 255, 0, '', 26365),
(@OGUID+275, 252103, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 60.6137, 3411.8, -250.389, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+276, 251519, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 128.62, 3254.37, -225.612, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+277, 252435, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 607.768, 3188, 195.959, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+278, 266173, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.857, 3385.09, 148.778, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+279, 250241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 470.96, 3258.62, -225.562, 3.3685, 0, 0, -0.993571, 0.113208, 604800, 255, 1, '', 26365),
(@OGUID+280, 250243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 495.448, 3347.27, -225.562, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+281, 250242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 406.708, 3323.29, -225.562, 1.29154, 0, 0, 0.601815, 0.798635, 604800, 255, 1, '', 26365),
(@OGUID+282, 251984, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 558.055, 3084.65, 148.595, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+283, 252318, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+284, 251684, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 531.466, 3176.84, 148.52, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+285, 251687, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 293.266, 3389.96, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+286, 251686, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.635, 3347.35, 173.603, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+287, 251683, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 255.552, 3316.56, 148.778, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+288, 252321, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.148, 3179.33, 438.941, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+289, 253988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 101.112, 2954.19, 108.911, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+290, 253178, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 269.559, 3370.91, 172.636, 2.36439, 0, 0, 0.92544, 0.378895, 604800, 255, 0, '', 26365),
(@OGUID+291, 253923, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 226.57, 3357.47, 173.627, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+292, 266395, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 1.5708, 0, 0, 0.707107, 0.707107, 604800, 255, 1, '', 26365),
(@OGUID+293, 248932, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 586.881, 3167.01, 198.061, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+294, 254241, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 549.432, 3208.23, 109.36, 4.67748, 0, 0, -0.719339, 0.694659, 604800, 255, 1, '', 26365),
(@OGUID+295, 266174, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.349, 3135.41, 464.98, 3.83973, 0, 0, -0.939692, 0.342021, 604800, 255, 1, '', 26365),
(@OGUID+296, 266181, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+297, 266180, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+298, 266183, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+299, 266182, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.834, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+300, 260985, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.351, 3135.4, 465.82, 4.01426, 0, 0, -0.906307, 0.422619, 604800, 255, 1, '', 26365),
(@OGUID+301, 251983, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 461.111, 3181.49, 148.609, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+302, 253462, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 347.977, 3201.06, 72.6628, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+303, 251988, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.747, 3091.62, 438.941, 0.785399, 0, 0, 0.382684, 0.923879, 604800, 255, 1, '', 26365),
(@OGUID+304, 256893, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 453.246, 3028.29, 143.975, 1.09955, 0, 0, 0.522497, 0.852641, 604800, 255, 1, '', 26365),
(@OGUID+305, 256892, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 458.493, 3030.24, 143.976, 2.61799, 0, 0, 0.965925, 0.258821, 604800, 255, 1, '', 26365),
(@OGUID+306, 252319, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.303, 3179.78, 438.941, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+307, 251685, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 466.397, 3111.55, 148.52, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+308, 252320, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.592, 3091.18, 438.941, 5.49779, 0, 0, -0.382682, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+309, 258847, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 142.035, 3187, 110.98, 6.18719, 0, 0, -0.0479775, 0.998848, 604800, 255, 1, '', 26365),
(@OGUID+310, 254243, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 492.031, 3127.71, 150.653, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+311, 254242, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 479.949, 3114.23, 173.413, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+312, 255925, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 199.175, 3218.98, 216.211, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+313, 251981, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 326.779, 3179.86, 146.791, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+314, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 250.997, 3166.86, 146.81, 5.48892, 0, 0, -0.386774, 0.922175, 604800, 255, 1, '', 26365),
(@OGUID+315, 252315, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 241.672, 3176.31, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+316, 251609, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 246.843, 3171.53, 296.644, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+317, 251608, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 223.902, 3194.11, 227.221, 2.35619, 0, 0, 0.92388, 0.382683, 604800, 255, 1, '', 26365),
(@OGUID+318, 255926, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 386.622, 3031.55, 171.277, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+319, 251982, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 238.227, 3091.31, 146.791, 0.785397, 0, 0, 0.382683, 0.92388, 604800, 255, 0, '', 26365),
(@OGUID+320, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 314.076, 3104.14, 146.8, 5.50553, 0, 0, -0.379104, 0.925354, 604800, 255, 1, '', 26365),
(@OGUID+321, 252317, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.482, 3135.58, 145.196, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+322, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 339.121, 3079.11, 289.415, 5.48892, 0, 0, -0.386774, 0.922175, 604800, 255, 1, '', 26365),
(@OGUID+323, 258843, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 333.977, 3186.94, 227.009, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+324, 251612, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.344, 3176.39, 227.23, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+325, 255927, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 365.853, 3052.3, 216.211, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+326, 251330, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 282.506, 3135.57, 226.859, 3.927, 0, 0, -0.923879, 0.382686, 604800, 255, 1, '', 26365),
(@OGUID+327, 252316, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 323.241, 3094.77, 227.221, 2.35619, 0, 0, 0.923879, 0.382686, 604800, 255, 0, '', 26365),
(@OGUID+328, 251611, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 318.424, 3099.9, 296.644, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 1, '', 26365),
(@OGUID+329, 251610, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, -1, 341.045, 3077, 227.221, 5.49779, 0, 0, -0.382683, 0.92388, 604800, 255, 0, '', 26365);


DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+355;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small005
(@OGUID+1, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+2, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small013
(@OGUID+3, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx004
(@OGUID+4, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
(@OGUID+5, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small007
(@OGUID+6, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003
(@OGUID+8, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx003
(@OGUID+10, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large002
(@OGUID+11, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001
(@OGUID+12, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small001
(@OGUID+13, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+14, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small012
(@OGUID+16, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large001
(@OGUID+17, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001
(@OGUID+18, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+19, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+20, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+21, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+22, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med007
(@OGUID+23, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+26, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+27, 0, 0, 0, 1), -- Platform
(@OGUID+28, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large003
(@OGUID+29, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+30, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+31, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+32, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+33, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+34, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+35, 0, 0, 0.9238795, -0.3826835), -- Portcullis
(@OGUID+36, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NE_Nightelf_AcademyDoor001
(@OGUID+37, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+38, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+40, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate001
(@OGUID+41, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+42, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med005
(@OGUID+43, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+44, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+45, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med006
(@OGUID+46, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+47, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med008
(@OGUID+48, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 02
(@OGUID+49, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Exit
(@OGUID+50, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 01
(@OGUID+51, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med001
(@OGUID+52, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001
(@OGUID+53, 0, 0, 0.9238795, -0.3826835), -- Nightwell Door
(@OGUID+54, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+55, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+56, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+57, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+58, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Astrodome001
(@OGUID+60, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+61, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate002
(@OGUID+62, 0, 0, 0.9238795, -0.3826835), -- Anomaly Exit
(@OGUID+63, 0, 0, 0.9238795, -0.3826835), -- Anomaly Entrance
(@OGUID+64, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx002
(@OGUID+65, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN
(@OGUID+66, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN
(@OGUID+67, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN
(@OGUID+68, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN
(@OGUID+69, 0, 0, 0.9238795, -0.3826835), -- Sealed Door
(@OGUID+70, 0, 0, -0.8660253, 0.5000002), -- The Nighthold Portcullis
(@OGUID+71, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+72, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER002
(@OGUID+73, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER003
(@OGUID+77, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med001
(@OGUID+79, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate002
(@OGUID+81, 0, 0, 0.9238795, -0.3826835), -- Portcullis
(@OGUID+82, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med005
(@OGUID+83, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+84, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+85, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+86, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med006
(@OGUID+87, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+88, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large003
(@OGUID+89, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large001
(@OGUID+90, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+91, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+92, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Astrodome001
(@OGUID+93, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NE_Nightelf_AcademyDoor001
(@OGUID+94, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+95, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+96, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small005
(@OGUID+97, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small001
(@OGUID+98, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+99, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small007
(@OGUID+100, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+101, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+102, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small012
(@OGUID+103, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small013
(@OGUID+104, 0, 0, 0.9238795, -0.3826835), -- Anomaly Exit
(@OGUID+105, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med007
(@OGUID+106, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001
(@OGUID+107, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med008
(@OGUID+108, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 02
(@OGUID+109, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Exit
(@OGUID+110, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 01
(@OGUID+111, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large002
(@OGUID+112, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+113, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+114, 0, 0, 0.9238795, -0.3826835), -- Nightwell Door
(@OGUID+115, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+116, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+117, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+118, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+119, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN
(@OGUID+120, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN
(@OGUID+121, 0, 0, -0.3746065, 0.9271839), -- Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN
(@OGUID+122, 0, 0, 0.9238795, -0.3826835), -- Sealed Door
(@OGUID+123, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+124, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+125, 0, 0, 0.9238795, -0.3826835), -- Anomaly Entrance
(@OGUID+126, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx002
(@OGUID+127, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+128, 0, 0, 0, 1), -- Platform
(@OGUID+129, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+130, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+133, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate001
(@OGUID+134, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+135, 0, 0, -0.8660253, 0.5000002), -- The Nighthold Portcullis
(@OGUID+136, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+137, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+138, 0, 0, 0.9238795, -0.3826835), -- 0
(@OGUID+139, 0, 0, 0.9238795, -0.3826835), -- Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN
(@OGUID+140, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+142, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+143, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+144, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+145, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+146, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+147, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+148, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+149, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+150, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+154, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003
(@OGUID+155, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx003
(@OGUID+159, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001
(@OGUID+160, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER002
(@OGUID+161, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx004
(@OGUID+162, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
(@OGUID+163, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001
(@OGUID+165, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER003
(@OGUID+167, 0, 0, 0, 1), -- Platform
(@OGUID+168, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+169, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+170, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+171, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+172, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+173, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+174, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+175, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+176, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+177, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+178, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med007
(@OGUID+179, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large002
(@OGUID+180, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large003
(@OGUID+181, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large001
(@OGUID+182, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+183, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+184, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+185, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small005
(@OGUID+186, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+187, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small001
(@OGUID+188, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+189, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small007
(@OGUID+190, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small012
(@OGUID+191, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+192, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small013
(@OGUID+193, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+194, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+195, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+196, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med005
(@OGUID+197, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+198, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+199, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med006
(@OGUID+200, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN
(@OGUID+201, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN
(@OGUID+202, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN
(@OGUID+203, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN
(@OGUID+204, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+205, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+206, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001
(@OGUID+207, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med008
(@OGUID+208, 0, 0, 0.9238795, -0.3826835), -- Sealed Door
(@OGUID+209, 0, 0, 0.9238795, -0.3826835), -- Portcullis
(@OGUID+210, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+211, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+212, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Astrodome001
(@OGUID+213, 0, 0, 0.9238795, -0.3826835), -- Anomaly Exit
(@OGUID+214, 0, 0, 0.9238795, -0.3826835), -- Anomaly Entrance
(@OGUID+215, 0, 0, 0.9238795, -0.3826835), -- Nightwell Door
(@OGUID+216, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 02
(@OGUID+217, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Exit
(@OGUID+218, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 01
(@OGUID+219, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NE_Nightelf_AcademyDoor001
(@OGUID+220, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate001
(@OGUID+221, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate002
(@OGUID+222, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med001
(@OGUID+223, 0, 0, -0.8660253, 0.5000002), -- The Nighthold Portcullis
(@OGUID+224, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+225, 0, 0, -0.333807, 0.9426414), -- Violet Hold Gate
(@OGUID+227, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large001
(@OGUID+228, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med005
(@OGUID+229, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+230, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+235, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med001
(@OGUID+237, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003
(@OGUID+238, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large003
(@OGUID+239, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx003
(@OGUID+241, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+242, 0, 0, 0.9238795, -0.3826835), -- Dreadlord Door
(@OGUID+243, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small007
(@OGUID+246, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001
(@OGUID+247, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER002
(@OGUID+248, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx004
(@OGUID+250, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med006
(@OGUID+251, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med007
(@OGUID+252, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+253, 0, 0, 0.9238795, -0.3826835), -- Portcullis
(@OGUID+254, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small012
(@OGUID+255, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small001
(@OGUID+256, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate002
(@OGUID+257, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+258, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001
(@OGUID+259, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Large002
(@OGUID+260, 0, 0, 0.9238795, -0.3826835), -- Observatory Door
(@OGUID+261, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small013
(@OGUID+262, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NE_Nightelf_AcademyDoor001
(@OGUID+263, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_Small005
(@OGUID+264, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+265, 0, 0, 0.9238795, -0.3826835), -- Chamber Door
(@OGUID+266, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Astrodome001
(@OGUID+267, 0, 0, 0, 1), -- Platform
(@OGUID+268, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 02
(@OGUID+269, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Exit
(@OGUID+270, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis 01
(@OGUID+271, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_Door_med008
(@OGUID+272, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+273, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+274, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+275, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+276, 0, 0, 0.9238795, -0.3826835), -- Anomaly Exit
(@OGUID+277, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+278, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+279, 0, 0, 0.9238795, -0.3826835), -- Nighthold Focusing Statue
(@OGUID+280, 0, 0, 0.9238795, -0.3826835), -- The Eye of Aman'thul
(@OGUID+281, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+282, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+283, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+284, 0, 0, 0.9238795, -0.3826835), -- Statue Energy Conduit
(@OGUID+285, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+286, 0, 0, 0.9238795, -0.3826835), -- Trilliax Portcullis Entrance
(@OGUID+287, 0, 0, 0.9238795, -0.3826835), -- Doodad_7DU_SuramarRaid_CourtyardGate001
(@OGUID+288, 0, 0, 0.9238795, -0.3826835), -- Nightwell Door
(@OGUID+289, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+290, 0, 0, 0.9238795, -0.3826835), -- Arcane-imbued Wood Door
(@OGUID+291, 0, 0, 0.9238795, -0.3826835), -- Door
(@OGUID+292, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN
(@OGUID+293, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN
(@OGUID+294, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN
(@OGUID+295, 0, 0, 0, 1), -- Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN
(@OGUID+296, 0, 0, 0.9238795, -0.3826835), -- Sealed Door
(@OGUID+297, 0, 0, 0.9238795, -0.3826835), -- Anomaly Entrance
(@OGUID+298, 0, 0, 0.9238795, -0.3826835), -- Doodad_7sr_suramar_nightwellfx002
(@OGUID+299, 0, 0, -0.8660253, 0.5000002), -- The Nighthold Portcullis
(@OGUID+300, 0, 0, -0.333807, 0.9426414), -- Violet Hold Gate
(@OGUID+301, 0, 0, -0.333807, 0.9426414), -- Facade
(@OGUID+302, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER003
(@OGUID+318, 0, 0, 0.9238795, -0.3826835), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
(@OGUID+319, 0, 0, 0.9238795, -0.3826835); -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001


DELETE FROM `spell_target_position` WHERE (`ID`=232284 AND `EffectIndex`=0) OR (`ID`=206385 AND `EffectIndex`=0) OR (`ID`=234642 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(232284, 0, 1530, 359.84, 3058.16, 216.2, 26365), -- Spell: Teleport to Elisande Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(206385, 0, 1530, 241.47, 3392.21, 171.72, 26365), -- Spell: Illusionary Night Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(234642, 0, 1220, -899.07, 2222.4, -0.91, 26365); -- Spell: The Broken Shore (Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=26365 WHERE (`ID`=226373 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26365 WHERE (`ID`=89157 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `MapID`=1153, `PositionX`=5563.7, `PositionY`=4599.9, `PositionZ`=141.71 WHERE (`ID`=171253 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (109804 /*109804 (Plasma Sphere) - Plasma Sphere*/, 109075 /*109075 (Parasitic Lasher) - Parasitic Fetter*/, 109583 /*109583 (Solar Collapse Stalker)*/, 110341 /*110341 (Arcanist Tel'arn)*/, 104528 /*104528 (High Botanist Tel'arn) - Recursive Strikes*/, 109164 /*109164 (High Botanist Tel'arn) - Share Health*/, 112956 /*112956 (Shimmering Manaspine)*/, 112678 /*112678 (Shal'dorei Naturalist) - Mod Scale 125%*/, 111295 /*111295 (Domesticated Manasaber)*/, 112973 /*112973 (Duskwatch Weaver) - Mod Scale 140%, Arcane Channel*/, 110677 /*110677 (Image of Khadgar) - Image of Khadgar*/, 101002 /*101002 (Krosus)*/, 111226 /*111226 (Summoner Xiv) - Mod Scale 95-120%*/, 111581 /*111581 (Fiery Core)*/, 111225 /*111225 (Chaos Mage Beleron) - Mod Scale 95-120%*/, 111227 /*111227 (Felweaver Pharamere) - Infernal Blade*/, 108591 /*108591 (Felsworn Spellguard) - Mod Scale 150%*/, 108739 /*108739 (Carrion Nightmare) - Carrion Nightmare*/, 104326 /*104326 (Phantasmal Bloodfang) - Bat Ghost Visual*/, 116146 /*Illidan Stormrage - Encounter Bounds Aura (Broken Room)*/, 106545 /*106545 (Empowered Eye of Gul'dan) - Empowered Eye of Gul'dan*/, 108934 /*108934 (Tainted Blood) - Vampiric Aura*/, 116710 /*116710 (Kvaldir Minion) - REUSE*/, 116156 /*116156 (Light's Heart) - Encounter Bounds Aura (Broken Room)*/, 104594 /*104594 (Well of Souls) - Ride Vehicle Hardcoded*/, 105371 /*105371 (Well of Souls) - Ride Vehicle Hardcoded*/, 106522 /*106522 (Archmage Khadgar) - Arcane Flight*/, 105630 /*105630 (Eye of Gul'dan) - Eye of Gul'dan*/, 104214 /*104214 (Nightwell Entity)*/, 116233 /*116233 (Fog Cloud) - Mythic: Call Add*/, 104271 /*104271 (Combat Stalker) - Bat Spawner*/, 112955 /*112955 (Shadescale Wyrm)*/, 111303 /*111303 (Nightborne Sage) - Mod Scale 125%*/, 112596 /*112596 (Duskwatch Warden)*/, 112595 /*112595 (Shal'dorei Archmage) - Mod Scale 140%*/, 114437 /*114437 (Lord Illidan Stormrage) - Gul'dan, Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)*/, 114440 /*114440 (The Eye of Aman'thul) - Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)*/, 114438 /*114438 (The Eye of Aman'thul) - Ride Vehicle Hardcoded, Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)*/, 104154 /*104154 (Gul'dan) - Gul'dan, The Eye of Aman'thul, Fel Scythe, Parasitic Wound, Parasitic Wound, Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)*/, 116372 /*Arluelle*/, 115840 /*Arcanist Valtrois*/, 116256 /*116256 (Victoire)*/, 110792 /*110792 (Archmage Khadgar)*/, 107980 /*Spellblade Aluriel - Searing Brand*/, 106330 /*106330 (Elisande) - Etched in Time*/, 112767 /*112767 (Star Shooting Stalker)*/, 113406 /*113406 (Manaflush Noble) - Imbibe Nightwell*/, 107754 /*107754 (Elisande) - Epocheric Orb*/, 105958 /*105958 (Echo of Elisande)*/, 106680 /*106680 (Echo of Elisande)*/, 117085 /*117085 (Ly'leth Lunastre)*/, 103758 /*103758 (Star Augur Etraeus) - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE]*/, 104881 /*Spellblade Aluriel*/, 112803 /*112803 (Astrologer Jarin) - Nightborne Astrologer Views Planets*/, 111587 /*111587 (Nether Elemental)*/, 112718 /*112718 (Sidereal Familiar)*/, 112638 /*112638 (Astral Defender)*/, 112655 /*112655 (Celestial Acolyte)*/, 112660 /*112660 (Nighthold Citizen)*/, 112709 /*112709 (Promenade Guard)*/, 110791 /*110791 (First Arcanist Thalyssra) - Celerity Zone*/, 113383 /*113383 (Fallen Defender)*/, 113605 /*Kirin Tor Guardian - Celerity Zone*/, 113321 /*113321 (Shambling Hungerer)*/, 113128 /*Withered Skulker*/, 105364 /*105364 (Echo of Elisande)*/, 105370 /*105370 (Arcanetic Ring)*/, 105367 /*105367 (Arcanetic Ring)*/, 105315 /*105315 (Arcanetic Ring)*/, 103685 /*103685 (Tichondrius)*/, 116820 /*116820 (Suramar Portal) - Portal Visual*/, 103725 /*103725 (Krosus)*/, 103999 /*103999 (Krosus)*/, 113012 /*113012 (Felsworn Chaos-Mage) - Mod Scale 125%*/, 113013 /*113013 (Felsworn Shadowblade) - Mod Scale 150%*/, 113052 /*113052 (Dreadguard)*/, 113043 /*113043 (Abyss Watcher)*/, 112804 /*112804 (Trained Shadescale)*/, 112671 /*112671 (Duskwatch Battle-Magus)*/, 112676 /*112676 (Nobleborn Warpcaster) - Mod Scale 140%*/, 112675 /*112675 (Duskwatch Sentinel)*/, 112665 /*112665 (Nighthold Protector)*/, 116670 /*116670 (Suramar Portal) - Portal Visual*/, 116662 /*116662 (Suramar Portal) - Portal Visual*/, 112603 /*112603 (Terrace Grove-Tender) - Mod Scale 125%*/, 116667 /*116667 (Suramar Portal) - Portal Visual*/, 113307 /*113307 (Chronowraith)*/, 106643 /*106643 (Elisande) - Etched in Time*/, 115683 /*115683 (The Nightwell)*/, 111151 /*111151 (Midnight Siphoner)*/, 111164 /*111164 (Twilight Stardancer)*/, 111170 /*111170 (Astral Farseer) - Spellcaster, Arcane Burst*/, 111166 /*111166 (Resolute Courtesan) - Warden Salute*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(109804, 0, 0, 0, 1, 0, 0, 0, 0, '218520'), -- 109804 (Plasma Sphere) - Plasma Sphere
(109075, 0, 0, 0, 1, 0, 0, 0, 0, '218357'), -- 109075 (Parasitic Lasher) - Parasitic Fetter
(109583, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109583 (Solar Collapse Stalker)
(110341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110341 (Arcanist Tel'arn)
(104528, 0, 0, 0, 1, 0, 0, 0, 0, '218502'), -- 104528 (High Botanist Tel'arn) - Recursive Strikes
(109164, 0, 0, 0, 1, 0, 0, 0, 0, '216897'), -- 109164 (High Botanist Tel'arn) - Share Health
(112956, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112956 (Shimmering Manaspine)
(112678, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- 112678 (Shal'dorei Naturalist) - Mod Scale 125%
(111295, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 111295 (Domesticated Manasaber)
(112973, 0, 0, 0, 1, 0, 0, 0, 0, '160758 224861'), -- 112973 (Duskwatch Weaver) - Mod Scale 140%, Arcane Channel
(110677, 0, 0, 0, 1, 0, 0, 0, 0, '220061'), -- 110677 (Image of Khadgar) - Image of Khadgar
(101002, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 101002 (Krosus)
(111226, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 111226 (Summoner Xiv) - Mod Scale 95-120%
(111581, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 111581 (Fiery Core)
(111225, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 111225 (Chaos Mage Beleron) - Mod Scale 95-120%
(111227, 0, 0, 0, 1, 0, 0, 0, 0, '222078'), -- 111227 (Felweaver Pharamere) - Infernal Blade
(108591, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- 108591 (Felsworn Spellguard) - Mod Scale 150%
(108739, 0, 0, 0, 1, 0, 12418, 0, 0, '215973'), -- 108739 (Carrion Nightmare) - Carrion Nightmare
(104326, 0, 0, 50331648, 1, 0, 0, 0, 0, '215605'), -- 104326 (Phantasmal Bloodfang) - Bat Ghost Visual
(116146, 0, 0, 0, 1, 0, 0, 0, 0, '227371'), -- Illidan Stormrage - Encounter Bounds Aura (Broken Room)
(106545, 0, 0, 33554432, 1, 0, 0, 0, 0, '211107'), -- 106545 (Empowered Eye of Gul'dan) - Empowered Eye of Gul'dan
(108934, 0, 0, 0, 1, 0, 0, 0, 0, '206893'), -- 108934 (Tainted Blood) - Vampiric Aura
(116710, 0, 0, 0, 1, 0, 0, 0, 0, '179293'), -- 116710 (Kvaldir Minion) - REUSE
(116156, 0, 0, 50331648, 1, 0, 0, 0, 0, '227371'), -- 116156 (Light's Heart) - Encounter Bounds Aura (Broken Room)
(104594, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 104594 (Well of Souls) - Ride Vehicle Hardcoded
(105371, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 105371 (Well of Souls) - Ride Vehicle Hardcoded
(106522, 0, 0, 0, 1, 0, 0, 0, 0, '227671'), -- 106522 (Archmage Khadgar) - Arcane Flight
(105630, 0, 0, 33554432, 1, 0, 0, 0, 0, '207718'), -- 105630 (Eye of Gul'dan) - Eye of Gul'dan
(104214, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 104214 (Nightwell Entity)
(116233, 0, 0, 0, 1, 0, 0, 0, 0, '229478'), -- 116233 (Fog Cloud) - Mythic: Call Add
(104271, 0, 0, 0, 1, 0, 0, 0, 0, '207257'), -- 104271 (Combat Stalker) - Bat Spawner
(112955, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 112955 (Shadescale Wyrm)
(111303, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- 111303 (Nightborne Sage) - Mod Scale 125%
(112596, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112596 (Duskwatch Warden)
(112595, 0, 0, 0, 1, 0, 0, 0, 0, '160758'), -- 112595 (Shal'dorei Archmage) - Mod Scale 140%
(114437, 0, 0, 50331648, 1, 0, 0, 0, 0, '208903 227371 206261'), -- 114437 (Lord Illidan Stormrage) - Gul'dan, Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)
(114440, 0, 0, 0, 1, 0, 0, 0, 0, '227371 206261'), -- 114440 (The Eye of Aman'thul) - Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)
(114438, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 227371 206261'), -- 114438 (The Eye of Aman'thul) - Ride Vehicle Hardcoded, Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)
(104154, 0, 0, 0, 1, 0, 0, 0, 0, '227639 227743 227554 212294 227037 227371 206261'), -- 104154 (Gul'dan) - Gul'dan, The Eye of Aman'thul, Fel Scythe, Parasitic Wound, Parasitic Wound, Encounter Bounds Aura (Broken Room), Encounter Bounds Aura (Intact Room)
(116372, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arluelle
(115840, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Arcanist Valtrois
(116256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116256 (Victoire)
(110792, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110792 (Archmage Khadgar)
(107980, 0, 0, 0, 1, 0, 0, 0, 0, '213179'), -- Spellblade Aluriel - Searing Brand
(106330, 0, 0, 50331648, 1, 0, 0, 0, 0, '210745'), -- 106330 (Elisande) - Etched in Time
(112767, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112767 (Star Shooting Stalker)
(113406, 0, 0, 0, 1, 0, 0, 0, 0, '225579'), -- 113406 (Manaflush Noble) - Imbibe Nightwell
(107754, 0, 0, 50331648, 1, 0, 0, 0, 0, '213955'), -- 107754 (Elisande) - Epocheric Orb
(105958, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105958 (Echo of Elisande)
(106680, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106680 (Echo of Elisande)
(117085, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 117085 (Ly'leth Lunastre)
(103758, 0, 0, 50331648, 1, 0, 0, 0, 0, '232550'), -- 103758 (Star Augur Etraeus) - Astromancer Stars Pre-Combat Visual [DO NOT TRANSLATE]
(104881, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spellblade Aluriel
(112803, 0, 0, 0, 1, 0, 0, 0, 0, '224655'), -- 112803 (Astrologer Jarin) - Nightborne Astrologer Views Planets
(111587, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111587 (Nether Elemental)
(112718, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112718 (Sidereal Familiar)
(112638, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112638 (Astral Defender)
(112655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112655 (Celestial Acolyte)
(112660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112660 (Nighthold Citizen)
(112709, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112709 (Promenade Guard)
(110791, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- 110791 (First Arcanist Thalyssra) - Celerity Zone
(113383, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- 113383 (Fallen Defender)
(113605, 0, 0, 0, 1, 0, 0, 0, 0, '211064'), -- Kirin Tor Guardian - Celerity Zone
(113321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113321 (Shambling Hungerer)
(113128, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Withered Skulker
(105364, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105364 (Echo of Elisande)
(105370, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 105370 (Arcanetic Ring)
(105367, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 105367 (Arcanetic Ring)
(105315, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 105315 (Arcanetic Ring)
(103685, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103685 (Tichondrius)
(116820, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- 116820 (Suramar Portal) - Portal Visual
(103725, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 103725 (Krosus)
(103999, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 103999 (Krosus)
(113012, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- 113012 (Felsworn Chaos-Mage) - Mod Scale 125%
(113013, 0, 0, 0, 1, 0, 0, 0, 0, '202427'), -- 113013 (Felsworn Shadowblade) - Mod Scale 150%
(113052, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113052 (Dreadguard)
(113043, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 113043 (Abyss Watcher)
(112804, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112804 (Trained Shadescale)
(112671, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 112671 (Duskwatch Battle-Magus)
(112676, 0, 0, 0, 0, 0, 0, 0, 0, '160758'), -- 112676 (Nobleborn Warpcaster) - Mod Scale 140%
(112675, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 112675 (Duskwatch Sentinel)
(112665, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112665 (Nighthold Protector)
(116670, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- 116670 (Suramar Portal) - Portal Visual
(116662, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- 116662 (Suramar Portal) - Portal Visual
(112603, 0, 0, 0, 1, 0, 0, 0, 0, '188236'), -- 112603 (Terrace Grove-Tender) - Mod Scale 125%
(116667, 0, 0, 0, 1, 0, 0, 0, 0, '232277'), -- 116667 (Suramar Portal) - Portal Visual
(113307, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113307 (Chronowraith)
(106643, 0, 0, 50331648, 1, 0, 0, 0, 0, '208861'), -- 106643 (Elisande) - Etched in Time
(115683, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 115683 (The Nightwell)
(111151, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111151 (Midnight Siphoner)
(111164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111164 (Twilight Stardancer)
(111170, 0, 0, 33554432, 1, 0, 0, 0, 0, '225958 221577'), -- 111170 (Astral Farseer) - Spellcaster, Arcane Burst
(111166, 0, 0, 0, 0, 0, 0, 0, 0, '190299'); -- 111166 (Resolute Courtesan) - Warden Salute

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=107997; -- 107997 (Silgryn)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=115772; -- 115772 (Kal)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114883; -- 114883 (Grand Magister Rommath)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=114838; -- Tyrande Whisperwind
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114841; -- Lady Liadrin
UPDATE `creature_template_addon` SET `auras`='211064' WHERE `entry`=113608; -- Kirin Tor Guardian
UPDATE `creature_template_addon` SET `auras`='122729' WHERE `entry`=62821; -- 62821 (Mystic Birdhat)
UPDATE `creature_template_addon` SET `auras`='122729' WHERE `entry`=62822; -- 62822 (Cousin Slowhands)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=89713; -- 89713 (Koak Hoburn)
UPDATE `creature_template_addon` SET `auras`='61424' WHERE `entry`=32639; -- 32639 (Gnimo)
UPDATE `creature_template_addon` SET `auras`='61424' WHERE `entry`=32638; -- 32638 (Hakmud of Argus)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=68553; -- 68553 (SLG Generic MoP (Large AOI))

DELETE FROM `creature_template_scaling` WHERE `Entry`=116372;
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(116372, 110, 110, 0, 0, 26365);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=26365 WHERE `Entry`=100635;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26365 WHERE `Entry`=107994;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26365 WHERE `Entry`=112392;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26365 WHERE `Entry`=113268;

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (75610, 75606);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(75610, 1.05, 8.75, 0, 26365),
(75606, 0.9, 7.5, 0, 26365);

UPDATE `creature_model_info` SET `BoundingRadius`=5, `CombatReach`=6, `VerifiedBuild`=26365 WHERE `DisplayID`=71214;
UPDATE `creature_model_info` SET `BoundingRadius`=2.232307, `CombatReach`=1.3, `VerifiedBuild`=26365 WHERE `DisplayID`=71423;
UPDATE `creature_model_info` SET `BoundingRadius`=1.346166, `CombatReach`=4.5, `VerifiedBuild`=26365 WHERE `DisplayID`=68963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=26365 WHERE `DisplayID`=44466;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=64304;
UPDATE `creature_model_info` SET `BoundingRadius`=1.800289, `CombatReach`=2.625, `VerifiedBuild`=26365 WHERE `DisplayID`=72124;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9797121, `CombatReach`=1.725, `VerifiedBuild`=26365 WHERE `DisplayID`=66586;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66275;
UPDATE `creature_model_info` SET `BoundingRadius`=15.58945, `CombatReach`=24.5, `VerifiedBuild`=26365 WHERE `DisplayID`=68323;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=71770;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=71769;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=71771;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=69052;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=73429;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72034;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67937;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72035;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=65678;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=74255;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72055;
UPDATE `creature_model_info` SET `BoundingRadius`=3.451858, `CombatReach`=4, `VerifiedBuild`=26365 WHERE `DisplayID`=72822;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=27571;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `CombatReach`=14.25, `VerifiedBuild`=26365 WHERE `DisplayID`=69635;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=33010;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8227149, `CombatReach`=1.5, `VerifiedBuild`=26365 WHERE `DisplayID`=69625;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=8, `VerifiedBuild`=26365 WHERE `DisplayID`=69232;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70878;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=71895;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66589;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66266;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=28120;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=28118;
UPDATE `creature_model_info` SET `BoundingRadius`=2.638643, `CombatReach`=4.125, `VerifiedBuild`=26365 WHERE `DisplayID`=68500;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=68890;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=73864;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=73854;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=73514;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=64629;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=19706;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=61971;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=65834;
UPDATE `creature_model_info` SET `BoundingRadius`=1.612829, `CombatReach`=1.5, `VerifiedBuild`=26365 WHERE `DisplayID`=70367;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=27710;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=17200;
UPDATE `creature_model_info` SET `BoundingRadius`=1.360725, `CombatReach`=1.5, `VerifiedBuild`=26365 WHERE `DisplayID`=74382;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70210;
UPDATE `creature_model_info` SET `BoundingRadius`=1.937479, `CombatReach`=7, `VerifiedBuild`=26365 WHERE `DisplayID`=68378;
UPDATE `creature_model_info` SET `BoundingRadius`=1.612829, `CombatReach`=6, `VerifiedBuild`=26365 WHERE `DisplayID`=70243;
UPDATE `creature_model_info` SET `BoundingRadius`=1.567539, `CombatReach`=2.76, `VerifiedBuild`=26365 WHERE `DisplayID`=72342;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70079;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70548;
UPDATE `creature_model_info` SET `BoundingRadius`=1.775124, `CombatReach`=4.375, `VerifiedBuild`=26365 WHERE `DisplayID`=72773;
UPDATE `creature_model_info` SET `BoundingRadius`=1.273626, `CombatReach`=2.2425, `VerifiedBuild`=26365 WHERE `DisplayID`=72131;
UPDATE `creature_model_info` SET `BoundingRadius`=1.795303, `CombatReach`=2.84625, `VerifiedBuild`=26365 WHERE `DisplayID`=72145;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70082;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70080;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72201;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=26365 WHERE `DisplayID`=70038;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67340;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67345;
UPDATE `creature_model_info` SET `BoundingRadius`=1.4539, `CombatReach`=1.25, `VerifiedBuild`=26365 WHERE `DisplayID`=71176;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=27216;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=27215;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=27217;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70279;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=69144;
UPDATE `creature_model_info` SET `BoundingRadius`=1.360725, `CombatReach`=1.5, `VerifiedBuild`=26365 WHERE `DisplayID`=69315;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=46710;
UPDATE `creature_model_info` SET `BoundingRadius`=1.625, `CombatReach`=3.25, `VerifiedBuild`=26365 WHERE `DisplayID`=70158;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67938;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67361;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=61763;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=68320;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70110;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67161;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=67162;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=71685;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=70879;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=64171;
UPDATE `creature_model_info` SET `BoundingRadius`=2.7502, `CombatReach`=1.1, `VerifiedBuild`=26365 WHERE `DisplayID`=71753;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66255;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66547;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72161;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72164;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=62387;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72162;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66555;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72163;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=72211;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=66246;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=2, `VerifiedBuild`=26365 WHERE `DisplayID`=64487;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=55233;
UPDATE `creature_model_info` SET `VerifiedBuild`=26365 WHERE `DisplayID`=69082;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=26365 WHERE `DisplayID`=72712;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028698, `CombatReach`=1.81125, `VerifiedBuild`=26365 WHERE `DisplayID`=71734;
UPDATE `creature_model_info` SET `BoundingRadius`=1.468884, `CombatReach`=2.32875, `VerifiedBuild`=26365 WHERE `DisplayID`=71737;
UPDATE `creature_model_info` SET `BoundingRadius`=1.196869, `CombatReach`=1.8975, `VerifiedBuild`=26365 WHERE `DisplayID`=71740;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469568, `CombatReach`=2.5875, `VerifiedBuild`=26365 WHERE `DisplayID`=71739;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=110437 AND `ID`=2) OR (`CreatureID`=112678 AND `ID`=1) OR (`CreatureID`=112973 AND `ID`=1) OR (`CreatureID`=111226 AND `ID`=1) OR (`CreatureID`=111225 AND `ID`=1) OR (`CreatureID`=111227 AND `ID`=1) OR (`CreatureID`=108591 AND `ID`=1) OR (`CreatureID`=116146 AND `ID`=1) OR (`CreatureID`=116710 AND `ID`=1) OR (`CreatureID`=106522 AND `ID`=1) OR (`CreatureID`=116233 AND `ID`=1) OR (`CreatureID`=111303 AND `ID`=1) OR (`CreatureID`=112596 AND `ID`=1) OR (`CreatureID`=112595 AND `ID`=1) OR (`CreatureID`=116372 AND `ID`=1) OR (`CreatureID`=116256 AND `ID`=1) OR (`CreatureID`=110792 AND `ID`=1) OR (`CreatureID`=107980 AND `ID`=1) OR (`CreatureID`=104881 AND `ID`=1) OR (`CreatureID`=112803 AND `ID`=1) OR (`CreatureID`=112638 AND `ID`=1) OR (`CreatureID`=112709 AND `ID`=1) OR (`CreatureID`=110791 AND `ID`=1) OR (`CreatureID`=113605 AND `ID`=1) OR (`CreatureID`=113012 AND `ID`=1) OR (`CreatureID`=113013 AND `ID`=1) OR (`CreatureID`=113052 AND `ID`=1) OR (`CreatureID`=112671 AND `ID`=1) OR (`CreatureID`=112676 AND `ID`=1) OR (`CreatureID`=112675 AND `ID`=1) OR (`CreatureID`=112603 AND `ID`=1) OR (`CreatureID`=111164 AND `ID`=1) OR (`CreatureID`=111170 AND `ID`=1) OR (`CreatureID`=111166 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(110437, 2, 122078, 0, 0, 126883, 0, 0, 0, 0, 0), -- Haklang Ulfsson
(112678, 1, 45613, 0, 0, 0, 0, 0, 0, 0, 0), -- Shal'dorei Naturalist
(112973, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Weaver
(111226, 1, 126793, 0, 0, 0, 0, 0, 0, 0, 0), -- Summoner Xiv
(111225, 1, 115069, 0, 0, 0, 0, 0, 0, 0, 0), -- Chaos Mage Beleron
(111227, 1, 116496, 0, 0, 0, 0, 0, 0, 0, 0), -- Felweaver Pharamere
(108591, 1, 138751, 0, 0, 138743, 0, 0, 0, 0, 0), -- Felsworn Spellguard
(116146, 1, 32632, 0, 0, 32633, 0, 0, 0, 0, 0), -- Illidan Stormrage
(116710, 1, 88793, 0, 0, 0, 0, 0, 0, 0, 0), -- Kvaldir Minion
(106522, 1, 22589, 0, 0, 0, 0, 0, 0, 0, 0), -- Archmage Khadgar
(116233, 1, 88793, 0, 0, 0, 0, 0, 0, 0, 0), -- Fog Cloud
(111303, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Nightborne Sage
(112596, 1, 132170, 0, 0, 137253, 0, 0, 0, 0, 0), -- Duskwatch Warden
(112595, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Shal'dorei Archmage
(116372, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Arluelle
(116256, 1, 137254, 0, 0, 0, 0, 0, 0, 0, 0), -- Victoire
(110792, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0), -- Archmage Khadgar
(107980, 1, 137256, 0, 0, 137259, 0, 0, 0, 0, 0), -- Spellblade Aluriel
(104881, 1, 137255, 0, 0, 137258, 0, 0, 0, 0, 0), -- Spellblade Aluriel
(112803, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0), -- Astrologer Jarin
(112638, 1, 132170, 0, 0, 132249, 0, 0, 0, 0, 0), -- Astral Defender
(112709, 1, 133177, 0, 0, 0, 0, 0, 0, 0, 0), -- Promenade Guard
(110791, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(113605, 1, 43617, 0, 0, 0, 0, 0, 0, 0, 0), -- Kirin Tor Guardian
(113012, 1, 138747, 0, 0, 0, 0, 0, 0, 0, 0), -- Felsworn Chaos-Mage
(113013, 1, 138755, 0, 0, 0, 0, 0, 0, 0, 0), -- Felsworn Shadowblade
(113052, 1, 138753, 0, 0, 138753, 0, 0, 0, 0, 0), -- Dreadguard
(112671, 1, 132170, 0, 0, 132171, 0, 0, 0, 0, 0), -- Duskwatch Battle-Magus
(112676, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Nobleborn Warpcaster
(112675, 1, 133177, 0, 0, 137253, 0, 0, 0, 0, 0), -- Duskwatch Sentinel
(112603, 1, 133176, 0, 0, 0, 0, 0, 0, 0, 0), -- Terrace Grove-Tender
(111164, 1, 40497, 0, 0, 0, 0, 0, 0, 0, 0), -- Twilight Stardancer
(111170, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Astral Farseer
(111166, 1, 132170, 0, 0, 132249, 0, 0, 0, 0, 0); -- Resolute Courtesan

UPDATE `creature_equip_template` SET `ItemID2`=133367 WHERE (`CreatureID`=110437 AND `ID`=1); -- Haklang Ulfsson

DELETE FROM `gossip_menu` WHERE (`MenuId`=20697 AND `TextId`=31058) OR (`MenuId`=20094 AND `TextId`=29853) OR (`MenuId`=20407 AND `TextId`=30511) OR (`MenuId`=20408 AND `TextId`=30513);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(20697, 31058), -- 116662 (Suramar Portal)
(20094, 29853), -- 110677 (Image of Khadgar)
(20407, 30511), -- 110792 (Archmage Khadgar)
(20408, 30513); -- 110791 (First Arcanist Thalyssra)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=20697 AND `OptionIndex`=3) OR (`MenuId`=20094 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(20697, 3, 0, 'Teleport to the Nightspire.', 0),
(20094, 0, 0, 'I''m ready.', 0);

UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2654208 WHERE `entry`=109804; -- Plasma Sphere
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=1.6, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2097152 WHERE `entry`=109075; -- Parasitic Lasher
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=109583; -- Solar Collapse Stalker
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=110341; -- Arcanist Tel'arn
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=104528; -- High Botanist Tel'arn
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=69206016, `unit_flags3`=1 WHERE `entry`=109164; -- High Botanist Tel'arn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2136, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112956; -- Shimmering Manaspine
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112678; -- Shal'dorei Naturalist
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111295; -- Domesticated Manasaber
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=112973; -- Duskwatch Weaver
UPDATE `creature_template` SET `gossip_menu_id`=20094, `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2099200 WHERE `entry`=110677; -- Image of Khadgar
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=4227072, `VehicleId`=5350 WHERE `entry`=101002; -- Krosus
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111226; -- Summoner Xiv
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=634, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=4194304 WHERE `entry`=111581; -- Fiery Core
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111225; -- Chaos Mage Beleron
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=111227; -- Felweaver Pharamere
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=97389; -- Eye of Odyn
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=106459; -- Captain Hjalmar Stahlstrom
UPDATE `creature_template` SET `npcflag`=1099511627779 WHERE `entry`=111741; -- Fjornson Stonecarver
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=110437; -- Haklang Ulfsson
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96679; -- Aerylia
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=108591; -- Felsworn Spellguard
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1, `VehicleId`=584 WHERE `entry`=108739; -- Carrion Nightmare
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=104326; -- Phantasmal Bloodfang
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=116146; -- Illidan Stormrage
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=6.8, `speed_run`=2.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33554432, `unit_flags2`=4194304 WHERE `entry`=106545; -- Empowered Eye of Gul'dan
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=108934; -- Tainted Blood
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=116710; -- Kvaldir Minion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116156; -- Light's Heart
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4329 WHERE `entry`=104594; -- Well of Souls
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4329 WHERE `entry`=105371; -- Well of Souls
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=2110, `speed_walk`=5.6, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=768, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=106522; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33554432, `unit_flags2`=4194304, `unit_flags3`=1 WHERE `entry`=105630; -- Eye of Gul'dan
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33555200, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=104214; -- Nightwell Entity
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=116233; -- Fog Cloud
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912 WHERE `entry`=104271; -- Combat Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=112955; -- Shadescale Wyrm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=111303; -- Nightborne Sage
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112596; -- Duskwatch Warden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112595; -- Shal'dorei Archmage
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=114437; -- Lord Illidan Stormrage
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=114440; -- The Eye of Aman'thul
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=114438; -- The Eye of Aman'thul
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=768, `unit_flags2`=1073741824, `VehicleId`=5096 WHERE `entry`=104154; -- Gul'dan
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=33280, `unit_flags3`=1 WHERE `entry`=107997; -- Silgryn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2885, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33280, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=116372; -- Arluelle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33280, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=115840; -- Arcanist Valtrois
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=116256; -- Victoire
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=115772; -- Kal
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `npcflag`=0, `unit_flags`=33344, `unit_flags3`=1 WHERE `entry`=114883; -- Grand Magister Rommath
UPDATE `creature_template` SET `npcflag`=0, `unit_flags2`=18432 WHERE `entry`=114838; -- Tyrande Whisperwind
UPDATE `creature_template` SET `npcflag`=0, `unit_flags3`=1 WHERE `entry`=114841; -- Lady Liadrin
UPDATE `creature_template` SET `gossip_menu_id`=20407, `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=110792; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587264, `unit_flags3`=1 WHERE `entry`=107980; -- Spellblade Aluriel
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33555202, `unit_flags2`=67108864, `VehicleId`=4081 WHERE `entry`=106330; -- Elisande
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=34816, `unit_flags3`=1 WHERE `entry`=112767; -- Star Shooting Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=113406; -- Manaflush Noble
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=107754; -- Elisande
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=105958; -- Echo of Elisande
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=106680; -- Echo of Elisande
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=117085; -- Ly'leth Lunastre
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=103758; -- Star Augur Etraeus
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=2.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=6291456, `VehicleId`=4827 WHERE `entry`=104881; -- Spellblade Aluriel
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=112803; -- Astrologer Jarin
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=111587; -- Nether Elemental
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112718; -- Sidereal Familiar
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112638; -- Astral Defender
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112655; -- Celestial Acolyte
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=112660; -- Nighthold Citizen
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112709; -- Promenade Guard
UPDATE `creature_template` SET `gossip_menu_id`=20408, `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=110791; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=113383; -- Fallen Defender
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2007, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=113605; -- Kirin Tor Guardian
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113321; -- Shambling Hungerer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=0.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=113128; -- Withered Skulker
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=105364; -- Echo of Elisande
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.8, `speed_run`=1.357143, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=100663296 WHERE `entry`=105370; -- Arcanetic Ring
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.8, `speed_run`=1.357143, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=100663296 WHERE `entry`=105367; -- Arcanetic Ring
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.8, `speed_run`=1.357143, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=100663296 WHERE `entry`=105315; -- Arcanetic Ring
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=89713; -- Koak Hoburn
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2097152 WHERE `entry`=103685; -- Tichondrius
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=116820; -- Suramar Portal
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=103725; -- Krosus
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=103999; -- Krosus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=113012; -- Felsworn Chaos-Mage
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=113013; -- Felsworn Shadowblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=113052; -- Dreadguard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=35653632, `HoverHeight`=1.5 WHERE `entry`=113043; -- Abyss Watcher
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112804; -- Trained Shadescale
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112671; -- Duskwatch Battle-Magus
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112676; -- Nobleborn Warpcaster
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=112675; -- Duskwatch Sentinel
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=112665; -- Nighthold Protector
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=116670; -- Suramar Portal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=116662; -- Suramar Portal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=112603; -- Terrace Grove-Tender
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=116667; -- Suramar Portal
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113307; -- Chronowraith
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=1.6, `speed_run`=2, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=2147517184, `VehicleId`=4081 WHERE `entry`=106643; -- Elisande
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=115683; -- The Nightwell
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=4000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111151; -- Midnight Siphoner
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=4000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111164; -- Twilight Stardancer
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=4000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111170; -- Astral Farseer
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=4000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111166; -- Resolute Courtesan

-- INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
-- (104154, 114438, 0, UNKNOWN, 'Gul''dan - The Eye of Aman''thul', UNKNOWN, UNKNOWN); -- Gul'dan - The Eye of Aman'thul


UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=115784; -- Snowfeather Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=110677; -- Image of Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=100868; -- Chi-Ji
UPDATE `creature_template` SET `modelid1`=74015, `VerifiedBuild`=26365 WHERE `entry`=104262; -- Burning Ember
UPDATE `creature_template` SET `HealthModifier`=749.32, `VerifiedBuild`=26365 WHERE `entry`=101002; -- Krosus
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26365 WHERE `entry`=51600; -- Lil' Ragnaros
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111554; -- Felblaze Trickster
UPDATE `creature_template` SET `HealthModifier`=185, `VerifiedBuild`=26365 WHERE `entry`=111210; -- Searing Infernal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111581; -- Fiery Core
UPDATE `creature_template` SET `HealthModifier`=112.5, `VerifiedBuild`=26365 WHERE `entry`=111226; -- Summoner Xiv
UPDATE `creature_template` SET `HealthModifier`=100, `VerifiedBuild`=26365 WHERE `entry`=111225; -- Chaos Mage Beleron
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=105850; -- Akaari's Soul
UPDATE `creature_template` SET `HealthModifier`=100, `VerifiedBuild`=26365 WHERE `entry`=111227; -- Felweaver Pharamere
UPDATE `creature_template` SET `HealthModifier`=9.6, `VerifiedBuild`=26365 WHERE `entry`=108591; -- Felsworn Spellguard
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=23767, `HealthScalingExpansion`=3, `VerifiedBuild`=26365 WHERE `entry`=64367; -- Invisible Man
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=108739; -- Carrion Nightmare
UPDATE `creature_template` SET `HealthModifier`=3.88178, `VerifiedBuild`=26365 WHERE `entry`=104326; -- Phantasmal Bloodfang
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=19668; -- Shadowfiend
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=108677; -- Spire Protector
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=108625; -- Fel Spire
UPDATE `creature_template` SET `HealthModifier`=7.47602, `VerifiedBuild`=26365 WHERE `entry`=108934; -- Tainted Blood
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=100099; -- Voodoo Totem
UPDATE `creature_template` SET `type_flags`=1024, `VerifiedBuild`=26365 WHERE `entry`=61146; -- Black Ox Statue
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=89652; -- Shallows Heron
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104271; -- Combat Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113605; -- Kirin Tor Guardian
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113608; -- Kirin Tor Guardian
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=117085; -- Ly'leth Lunastre
UPDATE `creature_template` SET `modelid1`=46939, `modelid2`=46955, `modelid3`=46956, `type`=12, `VerifiedBuild`=26365 WHERE `entry`=33810; -- Sen'jin Fetish
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112167; -- Lagan
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26365 WHERE `entry`=68666; -- Ashstone Core
UPDATE `creature_template` SET `modelid1`=69315, `type_flags`=1074790400, `HealthModifier`=341.0995, `ManaModifier`=1, `VerifiedBuild`=26365 WHERE `entry`=106330; -- Elisande
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=94584; -- Unstable Tear
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=107754; -- Elisande
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=105958; -- Echo of Elisande
UPDATE `creature_template` SET `modelid1`=74382, `VerifiedBuild`=26365 WHERE `entry`=106680; -- Echo of Elisande
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=99904; -- T'uure
UPDATE `creature_template` SET `HealthModifier`=33.839, `VerifiedBuild`=26365 WHERE `entry`=105301; -- Expedient Elemental
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=105364; -- Echo of Elisande
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=97369; -- Liquid Magma Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=99887; -- Shadowy Tear
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=108493; -- Chaos Tear
UPDATE `creature_template` SET `modelid1`=64965, `HealthScalingExpansion`=2, `type_flags2`=1, `HealthModifier`=1, `ManaModifier`=1, `VerifiedBuild`=26365 WHERE `entry`=11859; -- Doomguard
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113346; -- Beast
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=121643; -- Flame Rift
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=67235; -- Shadowfiend
UPDATE `creature_template` SET `HealthModifier`=22.2339, `VerifiedBuild`=26365 WHERE `entry`=105299; -- Recursive Elemental
UPDATE `creature_template` SET `type_flags`=1076887640, `type_flags2`=134, `movementId`=987, `VerifiedBuild`=26365 WHERE `entry`=105370; -- Arcanetic Ring
UPDATE `creature_template` SET `type_flags`=1076887640, `type_flags2`=134, `movementId`=987, `VerifiedBuild`=26365 WHERE `entry`=105367; -- Arcanetic Ring
UPDATE `creature_template` SET `movementId`=987, `VerifiedBuild`=26365 WHERE `entry`=105315; -- Arcanetic Ring
UPDATE `creature_template` SET `HealthModifier`=341.109, `ManaModifier`=1, `movementId`=184, `VerifiedBuild`=26365 WHERE `entry`=105297; -- Elisande
UPDATE `creature_template` SET `HealthModifier`=341.109, `ManaModifier`=1, `movementId`=184, `VerifiedBuild`=26365 WHERE `entry`=105474; -- Elisande
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113845; -- Totem Mastery
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=106321; -- Tailwind Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=106319; -- Ember Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=106317; -- Storm Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=102392; -- Resonance Totem
UPDATE `creature_template` SET `HealthModifier`=1009.8, `VerifiedBuild`=26365 WHERE `entry`=103685; -- Tichondrius
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116820; -- Suramar Portal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=43499; -- Consecration
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=103725; -- Krosus
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=103999; -- Krosus
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113012; -- Felsworn Chaos-Mage
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113013; -- Felsworn Shadowblade
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113052; -- Dreadguard
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113043; -- Abyss Watcher
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112804; -- Trained Shadescale
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112603; -- Terrace Grove-Tender
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112676; -- Nobleborn Warpcaster
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112671; -- Duskwatch Battle-Magus
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112675; -- Duskwatch Sentinel
UPDATE `creature_template` SET `modelid1`=55233, `VerifiedBuild`=26365 WHERE `entry`=113307; -- Chronowraith
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112665; -- Nighthold Protector
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116662; -- Suramar Portal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116667; -- Suramar Portal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111151; -- Midnight Siphoner
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=115683; -- The Nightwell
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111170; -- Astral Farseer
UPDATE `creature_template` SET `HealthModifier`=341.1089, `ManaModifier`=1, `VerifiedBuild`=26365 WHERE `entry`=106643; -- Elisande
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111164; -- Twilight Stardancer
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26365 WHERE `entry`=53884; -- Feline Familiar
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111166; -- Resolute Courtesan
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=26365 WHERE `entry`=68845; -- Nexus Whelpling
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=109792; -- Controlled Chaos Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=110125; -- Toxic Spore
UPDATE `creature_template` SET `HealthModifier`=1287, `VerifiedBuild`=26365 WHERE `entry`=109041; -- Naturalist Tel'arn
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111722; -- Aluneth
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=109804; -- Plasma Sphere
UPDATE `creature_template` SET `HealthModifier`=1287, `VerifiedBuild`=26365 WHERE `entry`=109038; -- Solarist Tel'arn
UPDATE `creature_template` SET `type`=4, `HealthModifier`=3.4125, `VerifiedBuild`=26365 WHERE `entry`=109075; -- Parasitic Lasher
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=109583; -- Solar Collapse Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=110341; -- Arcanist Tel'arn
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113554; -- Astral Anomaly
UPDATE `creature_template` SET `HealthModifier`=1287, `VerifiedBuild`=26365 WHERE `entry`=109164; -- High Botanist Tel'arn
UPDATE `creature_template` SET `HealthModifier`=1287, `VerifiedBuild`=26365 WHERE `entry`=104528; -- High Botanist Tel'arn
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112956; -- Shimmering Manaspine
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112973; -- Duskwatch Weaver
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111295; -- Domesticated Manasaber
UPDATE `creature_template` SET `modelid1`=66275, `modelid2`=66589, `VerifiedBuild`=26365 WHERE `entry`=112678; -- Shal'dorei Naturalist
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112664; -- Arc Well
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=108452; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=89; -- Infernal
UPDATE `creature_template` SET `HealthModifier`=116.592, `VerifiedBuild`=26365 WHERE `entry`=104880; -- Thing That Should Not Be
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104688; -- Voidling
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=103790; -- Coronal Ejection
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112955; -- Shadescale Wyrm
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111303; -- Nightborne Sage
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112596; -- Duskwatch Warden
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112595; -- Shal'dorei Archmage
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `type_flags`=2162761, `VerifiedBuild`=26365 WHERE `entry`=61945; -- Gurthan Iron Maw
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=110792; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=107285; -- Fiery Enchantment
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=107584; -- Searing Brand
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=107980; -- Spellblade Aluriel
UPDATE `creature_template` SET `HealthModifier`=6.9984, `movementId`=206, `VerifiedBuild`=26365 WHERE `entry`=107237; -- Icy Enchantment
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=107694; -- Mark of Frost
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104493; -- Spitting Cobra
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=102199; -- Stampede
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=47244; -- Mirror Image
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112978; -- Elemental Raptor
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26365 WHERE `entry`=26119; -- Phoenix Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=97285; -- Wind Rush Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112767; -- Star Shooting Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113406; -- Manaflush Noble
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116107; -- Murky
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=88708; -- Gara
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=115785; -- Direbeak Hatchling
UPDATE `creature_template` SET `type_flags`=1049600, `type_flags2`=16, `VerifiedBuild`=26365 WHERE `entry`=113405; -- Frenzy Stalker
UPDATE `creature_template` SET `KillCredit1`=117099, `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=3, `VerifiedBuild`=26365 WHERE `entry`=116518; -- Felguard Legionnaire
UPDATE `creature_template` SET `HealthModifier`=1094.4, `VerifiedBuild`=26365 WHERE `entry`=103758; -- Star Augur Etraeus
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113573; -- Cliffclutch Thornwitch
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112803; -- Astrologer Jarin
UPDATE `creature_template` SET `movementId`=203, `VerifiedBuild`=26365 WHERE `entry`=104881; -- Spellblade Aluriel
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=111587; -- Nether Elemental
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112655; -- Celestial Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112638; -- Astral Defender
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112718; -- Sidereal Familiar
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=112660; -- Nighthold Citizen
UPDATE `creature_template` SET `movementId`=186, `VerifiedBuild`=26365 WHERE `entry`=112709; -- Promenade Guard
UPDATE `creature_template` SET `type_flags`=64, `VerifiedBuild`=26365 WHERE `entry`=113383; -- Fallen Defender
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113128; -- Withered Skulker
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=113321; -- Shambling Hungerer
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=88402; -- Blacksmithing Follower - Horde
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=115840; -- Arcanist Valtrois
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=107997; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116372; -- Arluelle
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=114838; -- Tyrande Whisperwind
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=115772; -- Kal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=114883; -- Grand Magister Rommath
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=114841; -- Lady Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=110791; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116146; -- Illidan Stormrage
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116256; -- Victoire
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=101297; -- Yu'lon
UPDATE `creature_template` SET `HealthModifier`=20, `movementId`=864, `VerifiedBuild`=26365 WHERE `entry`=106545; -- Empowered Eye of Gul'dan
UPDATE `creature_template` SET `type_flags`=16778240, `type_flags2`=16, `VerifiedBuild`=26365 WHERE `entry`=110688; -- Dark Soul
UPDATE `creature_template` SET `modelid1`=75610, `type`=10, `type_flags`=16778240, `type_flags2`=16, `VerifiedBuild`=26365 WHERE `entry`=116710; -- Kvaldir Minion
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116156; -- Light's Heart
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116153; -- Light's Heart
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=105371; -- Well of Souls
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104594; -- Well of Souls
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104526; -- Well of Souls
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=106522; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=95160; -- Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=61245; -- Lightning Surge Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=78001; -- Cloudburst Totem
UPDATE `creature_template` SET `rank`=0, `HealthModifier`=6, `VerifiedBuild`=26365 WHERE `entry`=105630; -- Eye of Gul'dan
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104214; -- Nightwell Entity
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=95061; -- Greater Fire Elemental
UPDATE `creature_template` SET `modelid1`=13069, `VerifiedBuild`=26365 WHERE `entry`=44199; -- Ring of Frost
UPDATE `creature_template` SET `type_flags`=16778240, `type_flags2`=16, `VerifiedBuild`=26365 WHERE `entry`=104308; -- Bonds of Fel
UPDATE `creature_template` SET `type_flags`=16778240, `type_flags2`=16, `VerifiedBuild`=26365 WHERE `entry`=104252; -- Bonds of Fel
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=59764; -- Healing Tide Totem
UPDATE `creature_template` SET `modelid1`=75606, `modelid2`=0, `movementId`=0, `VerifiedBuild`=26365 WHERE `entry`=116233; -- Fog Cloud
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26365 WHERE `entry`=27829; -- Ebon Gargoyle
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=53006; -- Spirit Link Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=105422; -- Tidal Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `type_flags2`=1, `VerifiedBuild`=26365 WHERE `entry`=26125; -- Risen Ally
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=99541; -- Risen Skulker
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=97055; -- Shambling Horror
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104534; -- D'zorykx the Trapper
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104536; -- Inquisitor Vethriz
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=92870; -- Sindragosa's Fury
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=97022; -- Greater Lightning Elemental
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=94365; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=24207; -- Army of the Dead
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=104537; -- Fel Lord Kuraz'mal
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=100820; -- Spirit Wolf
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=94358; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=108804; -- Mechanical Bomb Squirrel
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=73400; -- Healing Ran Invisible Stalker DND
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=100876; -- Val'kyr Battlemaiden
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=3527; -- Healing Stream Totem
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=116670; -- Suramar Portal
UPDATE `creature_template` SET `type_flags`=16778240, `type_flags2`=144, `VerifiedBuild`=26365 WHERE `entry`=104396; -- Liquid Hellfire
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=106848; -- Abomination
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=92879; -- SLG Generic Stalker (Gigantic AOI)
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=114437; -- Lord Illidan Stormrage
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=114440; -- The Eye of Aman'thul
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=115787; -- Bloodgazer Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=114438; -- The Eye of Aman'thul
UPDATE `creature_template` SET `type_flags`=270532716, `HealthModifier`=1200, `VerifiedBuild`=26365 WHERE `entry`=104154; -- Gul'dan
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26365 WHERE `entry`=31575; -- Giant Sewer Rat
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26365 WHERE `entry`=47944; -- Dark Phoenix Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=38374; -- Toxic Wasteling
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26365 WHERE `entry`=54539; -- Alliance Balloon
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26365 WHERE `entry`=33238; -- Argent Squire
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=119824; -- Rivermane Shaman
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=14822; -- Sayge
UPDATE `creature_template` SET `VerifiedBuild`=26365 WHERE `entry`=89713; -- Koak Hoburn

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=105297 AND `Idx`=6) OR (`CreatureEntry`=105474 AND `Idx`=6) OR (`CreatureEntry`=116518 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(105297, 6, 146682, 26365), -- Elisande
(105474, 6, 146682, 26365), -- Elisande
(116518, 0, 147282, 26365); -- Felguard Legionnaire


DELETE FROM `gameobject_template` WHERE `entry` IN (251259 /*Cylinder Collision*/, 256872 /*Bench*/, 256857 /*Bench*/, 256898 /*Bench*/, 256899 /*Bench*/, 256894 /*Bench*/, 255928 /*Doodad_7NB_NIGHTBORN_CITYTELEPORTER002*/, 258848 /*Doodad_7NB_NIGHTBORN_CITYTELEPORTER003*/, 252322 /*Doodad_7sr_suramar_nightwellfx002*/, 256892 /*Bench*/, 256893 /*Bench*/, 255925 /*Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001*/, 255926 /*Doodad_7NB_NIGHTBORN_CITYTELEPORTER001*/, 258843 /*Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003*/, 252317 /*Doodad_7sr_suramar_nightwellfx003*/, 255927 /*Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002*/, 256883 /*Chair*/, 256882 /*Chair*/, 256881 /*Chair*/, 256880 /*Chair*/, 256879 /*Chair*/, 256878 /*Chair*/, 256877 /*Chair*/, 256876 /*Chair*/, 256903 /*Chair*/, 256902 /*Chair*/, 256875 /*Chair*/, 256873 /*Chair*/, 256901 /*Chair*/, 256874 /*Chair*/, 256885 /*Chair*/, 256884 /*Chair*/, 256887 /*Chair*/, 256886 /*Chair*/, 253128 /*Instance Portal*/, 266835 /*Nightborne Teleporter*/, 254240 /*Sealed Door*/, 252105 /*Arcane-imbued Wood Door*/, 252103 /*Arcane-imbued Wood Door*/, 250243 /*Trilliax Portcullis Exit*/, 250241 /*Trilliax Portcullis 01*/, 250242 /*Trilliax Portcullis 02*/, 251397 /*Trilliax Portcullis Entrance*/, 251398 /*Trilliax Portcullis Entrance*/, 251519 /*Nightwell Door*/, 252348 /*Anomaly Exit*/, 252349 /*Anomaly Entrance*/, 247971 /*Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN*/, 247972 /*Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN*/, 247973 /*Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN*/, 253989 /*Doodad_7DU_SuramarRaid_CourtyardGate002*/, 247970 /*Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN*/, 254241 /*Portcullis*/, 251401 /*Doodad_7DU_SuramarRaid_Astrodome001*/, 252435 /*Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001*/, 251984 /*Doodad_7DU_SuramarRaid_Door_med008*/, 248932 /*Doodad_7NE_Nightelf_AcademyDoor001*/, 251684 /*Doodad_7DU_SuramarRaid_Door_med006*/, 253988 /*Doodad_7DU_SuramarRaid_CourtyardGate001*/, 266173 /*Doodad_7DU_SuramarRaid_Door_med001*/, 253924 /*Dreadlord Door*/, 254243 /*Observatory Door*/, 251687 /*Dreadlord Door*/, 251685 /*Doodad_7DU_SuramarRaid_Door_med007*/, 251983 /*Doodad_7DU_SuramarRaid_Door_Large003*/, 254242 /*Observatory Door*/, 258847 /*Door*/, 253923 /*Dreadlord Door*/, 251683 /*Doodad_7DU_SuramarRaid_Door_med005*/, 251686 /*Dreadlord Door*/, 251981 /*Doodad_7DU_SuramarRaid_Door_Large001*/, 251982 /*Doodad_7DU_SuramarRaid_Door_Large002*/, 251610 /*Doodad_7DU_SuramarRaid_Door_Small005*/, 251612 /*Doodad_7DU_SuramarRaid_Door_Small007*/, 252316 /*Doodad_7DU_SuramarRaid_Door_Small013*/, 251608 /*Doodad_7DU_SuramarRaid_Door_Small001*/, 252315 /*Doodad_7DU_SuramarRaid_Door_Small012*/, 251611 /*Chamber Door*/, 251609 /*Chamber Door*/, 253462 /*Platform*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(251259, 5, 19131, 'Cylinder Collision', '', '', '', 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cylinder Collision
(256872, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(256857, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(256898, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(256899, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(256894, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(255928, 5, 36343, 'Doodad_7NB_NIGHTBORN_CITYTELEPORTER002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER002
(258848, 5, 36343, 'Doodad_7NB_NIGHTBORN_CITYTELEPORTER003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER003
(252322, 5, 35936, 'Doodad_7sr_suramar_nightwellfx002', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7sr_suramar_nightwellfx002
(256892, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(256893, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bench
(255925, 5, 36224, 'Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001
(255926, 5, 36343, 'Doodad_7NB_NIGHTBORN_CITYTELEPORTER001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001
(258843, 5, 36224, 'Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003
(252317, 5, 35935, 'Doodad_7sr_suramar_nightwellfx003', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7sr_suramar_nightwellfx003
(255927, 5, 36224, 'Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
(256883, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256882, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256881, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256880, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256879, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256878, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256877, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256876, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256903, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256902, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256875, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256873, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256901, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256874, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256885, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256884, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256887, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(256886, 7, 34334, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chair
(253128, 5, 6450, 'Instance Portal', '', '', '', 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Instance Portal
(266835, 5, 36343, 'Nightborne Teleporter', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightborne Teleporter
(254240, 0, 34024, 'Sealed Door', '', '', '', 0.85, 0, 2598, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sealed Door
(252105, 0, 34023, 'Arcane-imbued Wood Door', '', '', '', 0.9206064, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcane-imbued Wood Door
(252103, 0, 34024, 'Arcane-imbued Wood Door', '', '', '', 0.8338647, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcane-imbued Wood Door
(250243, 0, 33999, 'Trilliax Portcullis Exit', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trilliax Portcullis Exit
(250241, 0, 33999, 'Trilliax Portcullis 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trilliax Portcullis 01
(250242, 0, 33999, 'Trilliax Portcullis 02', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trilliax Portcullis 02
(251397, 0, 34945, 'Trilliax Portcullis Entrance', '', '', '', 1.0774, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trilliax Portcullis Entrance
(251398, 0, 34945, 'Trilliax Portcullis Entrance', '', '', '', 1.067725, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Trilliax Portcullis Entrance
(251519, 0, 35130, 'Nightwell Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nightwell Door
(252348, 0, 34945, 'Anomaly Exit', '', '', '', 2.0207, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Anomaly Exit
(252349, 0, 34945, 'Anomaly Entrance', '', '', '', 2.0207, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Anomaly Entrance
(247971, 33, 32140, 'Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Raid - Doomlord - Destructible Bridge - 02 - MRN
(247972, 33, 32139, 'Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Raid - Doomlord - Destructible Bridge - 01 - MRN
(247973, 33, 32141, 'Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Raid - Doomlord - Destructible Bridge - 03 - MRN
(253989, 0, 36475, 'Doodad_7DU_SuramarRaid_CourtyardGate002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_CourtyardGate002
(247970, 33, 32142, 'Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 189, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Suramar Raid - Doomlord - Destructible Bridge - 04 - MRN
(254241, 0, 33999, 'Portcullis', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Portcullis
(251401, 0, 35009, 'Doodad_7DU_SuramarRaid_Astrodome001', '', '', '', 0.9810173, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Astrodome001
(252435, 0, 36033, 'Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001', '', '', '', 0.9810173, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SURAMARRAID_ASTRODOME01_CollisionOnly001
(251984, 0, 35341, 'Doodad_7DU_SuramarRaid_Door_med008', '', '', '', 0.8568431, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_med008
(248932, 0, 31374, 'Doodad_7NE_Nightelf_AcademyDoor001', '', '', '', 0.436505, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7NE_Nightelf_AcademyDoor001
(251684, 0, 35341, 'Doodad_7DU_SuramarRaid_Door_med006', '', '', '', 1.029025, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_med006
(253988, 0, 36475, 'Doodad_7DU_SuramarRaid_CourtyardGate001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_CourtyardGate001
(266173, 0, 35341, 'Doodad_7DU_SuramarRaid_Door_med001', '', '', '', 1.029025, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_med001
(253924, 0, 35255, 'Dreadlord Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadlord Door
(254243, 0, 35255, 'Observatory Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Observatory Door
(251687, 0, 35255, 'Dreadlord Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadlord Door
(251685, 0, 35341, 'Doodad_7DU_SuramarRaid_Door_med007', '', '', '', 1.029025, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_med007
(251983, 0, 35701, 'Doodad_7DU_SuramarRaid_Door_Large003', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Large003
(254242, 0, 35255, 'Observatory Door', '', '', '', 1.01935, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Observatory Door
(258847, 0, 35255, 'Door', '', '', '', 1.0774, 0, 2598, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Door
(253923, 0, 35255, 'Dreadlord Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadlord Door
(251683, 0, 35341, 'Doodad_7DU_SuramarRaid_Door_med005', '', '', '', 1.029025, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_med005
(251686, 0, 35255, 'Dreadlord Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dreadlord Door
(251981, 0, 35701, 'Doodad_7DU_SuramarRaid_Door_Large001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Large001
(251982, 0, 35701, 'Doodad_7DU_SuramarRaid_Door_Large002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Large002
(251610, 0, 35255, 'Doodad_7DU_SuramarRaid_Door_Small005', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Small005
(251612, 0, 35255, 'Doodad_7DU_SuramarRaid_Door_Small007', '', '', '', 1.203175, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Small007
(252316, 0, 35255, 'Doodad_7DU_SuramarRaid_Door_Small013', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Small013
(251608, 0, 35255, 'Doodad_7DU_SuramarRaid_Door_Small001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Small001
(252315, 0, 35255, 'Doodad_7DU_SuramarRaid_Door_Small012', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Doodad_7DU_SuramarRaid_Door_Small012
(251611, 0, 35255, 'Chamber Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chamber Door
(251609, 0, 35255, 'Chamber Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chamber Door
(253462, 33, 35766, 'Platform', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Platform

UPDATE `gameobject_template` SET `type`=10, `displayId`=36092, `IconName`='questinteract', `size`=0.8, `Data0`=2063, `Data2`=55894, `Data18`=1, `RequiredLevel`=110, `VerifiedBuild`=26365 WHERE `entry`=266959; -- Containment Field
UPDATE `gameobject_template` SET `type`=3, `displayId`=27394, `size`=2, `Data0`=1634, `Data1`=70565, `Data3`=1, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data15`=1, `Data20`=100, `Data25`=1842, `Data27`=1, `Data30`=70672, `Data32`=2, `VerifiedBuild`=26365 WHERE `entry`=248513; -- Felbound Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=26365 WHERE `entry`=253178; -- Balcony Door
UPDATE `gameobject_template` SET `type`=10, `displayId`=34930, `size`=1.2, `VerifiedBuild`=26365 WHERE `entry`=251330; -- Doodad_7sr_suramar_nightwellfx004
UPDATE `gameobject_template` SET `VerifiedBuild`=26365 WHERE `entry`=251832; -- Botanist Door Right
UPDATE `gameobject_template` SET `VerifiedBuild`=26365 WHERE `entry`=251833; -- Botanist Door Left
UPDATE `gameobject_template` SET `type`=3, `displayId`=36450, `IconName`='questinteract', `size`=2, `Data0`=1634, `Data1`=70581, `Data3`=1, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data15`=1, `Data20`=110, `Data25`=1866, `Data27`=1, `Data30`=68261, `Data32`=2, `VerifiedBuild`=26365 WHERE `entry`=266483; -- Gift of the Nightborne
UPDATE `gameobject_template` SET `type`=10, `displayId`=13594, `size`=1.15, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=250082; -- Eye of Amun'thul
UPDATE `gameobject_template` SET `type`=10, `displayId`=35702, `size`=11.14733, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=252319; -- Nighthold Focusing Statue
UPDATE `gameobject_template` SET `type`=10, `displayId`=35702, `size`=11.14733, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=251988; -- Nighthold Focusing Statue
UPDATE `gameobject_template` SET `type`=10, `displayId`=35702, `size`=11.14733, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=252321; -- Nighthold Focusing Statue
UPDATE `gameobject_template` SET `type`=10, `displayId`=35702, `size`=11.14733, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=252320; -- Nighthold Focusing Statue
UPDATE `gameobject_template` SET `type`=10, `displayId`=39030, `Data13`=1, `Data29`=1, `VerifiedBuild`=26365 WHERE `entry`=266174; -- The Eye of Aman'thul
UPDATE `gameobject_template` SET `type`=10, `displayId`=35131, `Data13`=1, `Data29`=1, `VerifiedBuild`=26365 WHERE `entry`=252318; -- The Eye of Aman'thul
UPDATE `gameobject_template` SET `type`=10, `displayId`=39101, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=266395; -- The Eye of Aman'thul
UPDATE `gameobject_template` SET `type`=10, `displayId`=38790, `Data13`=1, `Data29`=1, `VerifiedBuild`=26365 WHERE `entry`=260985; -- The Eye of Aman'thul
UPDATE `gameobject_template` SET `type`=10, `displayId`=39033, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=266181; -- Statue Energy Conduit
UPDATE `gameobject_template` SET `type`=10, `displayId`=39033, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=266180; -- Statue Energy Conduit
UPDATE `gameobject_template` SET `type`=10, `displayId`=39033, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=266183; -- Statue Energy Conduit
UPDATE `gameobject_template` SET `type`=10, `displayId`=39033, `Data13`=1, `VerifiedBuild`=26365 WHERE `entry`=266182; -- Statue Energy Conduit

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=266483 AND `Idx`=1) OR (`GameObjectEntry`=266483 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(266483, 1, 140198, 26365), -- Gift of the Nightborne
(266483, 0, 140198, 26365); -- Gift of the Nightborne


DELETE FROM `npc_text` WHERE `ID` IN (31058 /*31058*/, 29853 /*29853*/, 30511 /*30511*/, 30513 /*30513*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(31058, 1, 0, 0, 0, 0, 0, 0, 0, 125359, 0, 0, 0, 0, 0, 0, 0, 26365), -- 31058
(29853, 1, 0, 0, 0, 0, 0, 0, 0, 118749, 0, 0, 0, 0, 0, 0, 0, 26365), -- 29853
(30511, 1, 1, 1, 0, 0, 0, 0, 0, 122444, 122445, 122447, 0, 0, 0, 0, 0, 26365), -- 30511
(30513, 1, 1, 1, 0, 0, 0, 0, 0, 122449, 122450, 122453, 0, 0, 0, 0, 0, 26365); -- 30513

UPDATE `npc_text` SET `VerifiedBuild`=26365 WHERE `ID`=30468; -- 30468
