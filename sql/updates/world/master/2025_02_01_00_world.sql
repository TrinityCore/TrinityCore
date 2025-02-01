SET @CGUID := 10005739;
SET @OGUID := 10001464;
SET @ATSPAWNID := 109;
SET @ATPROPERTIESID := 96;
SET @WORLD_SAFE_LOC := 100070;
SET @TRIGGER_ID_ALLIANCE := 30; -- Trigger ID for capture flag area trigger alliance
SET @TRIGGER_ID_HORDE := 31; -- Trigger ID for capture flag area trigger horde

SET @SPAWNGROUP := 1263;
SET @TEXT_ID := 10056;

DELETE FROM `trinity_string` WHERE `entry` BETWEEN @TEXT_ID+0 AND @TEXT_ID+5;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@TEXT_ID+0, '$n has taken the crystal!'),
(@TEXT_ID+1, '$n has taken the crystal! The crystal can be captured outside an Earthen cart building!');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC+0 AND @WORLD_SAFE_LOC+5;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC+0, 2656, 4162.46, -2536.93, 277.266, 4.712389 / (2 * PI() / 360), 'Deephaul Ravine - Horde Start Location'),
(@WORLD_SAFE_LOC+1, 2656, 3963.75, -3391.00, 280.669, 1.5707964/ (2 * PI() / 360), 'Deephaul Ravine - Alliance Start Location'),
(@WORLD_SAFE_LOC+2, 2656, 4027.3074, -2785.8733, 239.7386, 5.386397838592529296 / (2 * PI() / 360), 'Deephaul Ravine - Horde Center Graveyard'),
(@WORLD_SAFE_LOC+3, 2656, 4162.6416, -2626.2466, 257.4485, 4.689783096313476562 / (2 * PI() / 360), 'Deephaul Ravine - Horde Spawn Graveyard'),
(@WORLD_SAFE_LOC+4, 2656, 4103.5547, -3113.059, 239.73898, 2.31174635887145996 / (2 * PI() / 360), 'Deephaul Ravine - Alliance Center Graveyard'),
(@WORLD_SAFE_LOC+5, 2656, 3963.7405, -3267.1458, 258.48502, 1.589281320571899414 / (2 * PI() / 360), 'Deephaul Ravine - Alliance Spawn Graveyard');

DELETE FROM `battleground_template` WHERE `ID`=1110;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `Weight`, `Comment`) VALUES
(1110, @WORLD_SAFE_LOC+1, @WORLD_SAFE_LOC+0, 1, 'Deephaul Ravine');

DELETE FROM `battleground_scripts` WHERE `MapId`=2656;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(2656, 0, 'battleground_deephaul_ravine');

DELETE FROM `graveyard_zone` WHERE `ID` IN (@WORLD_SAFE_LOC+2, @WORLD_SAFE_LOC+3, @WORLD_SAFE_LOC+4, @WORLD_SAFE_LOC+5);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@WORLD_SAFE_LOC+2, 14990, 'Deephaul Ravine - Horde Center Graveyard'),
(@WORLD_SAFE_LOC+3, 14990, 'Deephaul Ravine - Horde Spawn Graveyard'),
(@WORLD_SAFE_LOC+4, 14990, 'Deephaul Ravine - Alliance Center Graveyard'),
(@WORLD_SAFE_LOC+5, 14990, 'Deephaul Ravine - Alliance Spawn Graveyard');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (@WORLD_SAFE_LOC+2, @WORLD_SAFE_LOC+3, @WORLD_SAFE_LOC+4, @WORLD_SAFE_LOC+5);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(27, @WORLD_SAFE_LOC+4, 14990, 0, 6, 469, 0, 0, 'Graveyard - Deephaul Ravine - Alliance Center Graveyard - Team Alliance'),
(27, @WORLD_SAFE_LOC+4, 14990, 0, 23, 15100, 0, 0, 'Graveyard - Deephaul Ravine - Alliance Center Graveyard - Earthenworks area'),
(27, @WORLD_SAFE_LOC+2, 14990, 0, 6, 67, 0, 0, 'Graveyard - Deephaul Ravine - Horde Center Graveyard - Team Horde'),
(27, @WORLD_SAFE_LOC+2, 14990, 0, 23, 15099, 0, 0, 'Graveyard - Deephaul Ravine - Horde Center Graveyard - Waterworks area'),
(27, @WORLD_SAFE_LOC+5, 14990, 0, 6, 469, 0, 0, 'Graveyard - Deephaul Ravine - Alliance Spawn Graveyard - Team Alliance'),
(27, @WORLD_SAFE_LOC+3, 14990, 0, 6, 67, 0, 0, 'Graveyard - Deephaul Ravine - Horde Spawn Graveyard - Team Horde');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_bg_deephaul_ravine_cart_cap', 'spell_bg_deephaul_ravine_earthen_mine_cart_ride');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(430207, 'spell_bg_deephaul_ravine_cart_cap'),
(424166, 'spell_bg_deephaul_ravine_earthen_mine_cart_ride'),
(424383, 'spell_bg_deephaul_ravine_earthen_mine_cart_ride');

DELETE FROM `world_state` WHERE `ID` IN (6954, 6955, 7852, 25412, 24959, 24958, 24960, 25415, 25414, 25421, 25420);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `Comment`) VALUES
(6954, 0, '2373,2656', 'Deephaul Ravine - Alliance Capture Cart'),
(6955, 0, '2373,2656', 'Deephaul Ravine - Horde Capture Cart'),
(7852, 0, '2656', 'Deephaul Ravine - Battleground Started'),
(25412, 0, '2656', 'Deephaul Ravine - Flag Enabled (0 or 3)'),
(24959, 0, '2656', 'Deephaul Ravine - Horde Team Score'),
(24958, 0, '2656', 'Deephaul Ravine - Alliance Team Score'),
(24960, 1500, '2656', 'Deephaul Ravine - Max Team Score'),
(25415, 0, '2656', 'Deephaul Ravine - Alliance Control State East Cart'),
(25414, 0, '2656', 'Deephaul Ravine - Horde Control State East Cart'),
(25421, 0, '2656', 'Deephaul Ravine - Alliance Control State West Cart'),
(25420, 0, '2656', 'Deephaul Ravine - Horde Control State West Cart');

UPDATE `world_state` SET `MapIDs` = '489,726,2106,2656' WHERE `ID` IN (1545, 1546);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Deephaul Ravine - Crystal', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 1, @OGUID+20);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 25412, 3, 0, 0, 0, 0, '', 'Deephaul Ravine - Crystal - Only spawn when worldstate 25412 is 3');

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (21076, 21077, 33926));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(21076, 0, 0, 56311),
(21077, 0, 0, 56311),
(33926, 0, 0, 56311);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=1 AND `Id` BETWEEN @ATPROPERTIESID+0 AND @ATPROPERTIESID+3);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `SpellForVisuals`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, 21077, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 296582, 'at_bg_deephaul_ravine_buff', 56311),
(@ATPROPERTIESID+1, 1, 21076, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 296579, 'at_bg_deephaul_ravine_buff', 56311),
(@ATPROPERTIESID+2, 1, 33926, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 425662, 'at_bg_deephaul_ravine_buff', 56311);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+7 AND `IsCustom` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 2656, 4214.64501953125, -2963.7744140625, 220.6110382080078125, 2.571687936782836914, 0, '0', 0, '', '', 56311), -- 296582 (PvP Rune Berserking Visual (New)) (Area: Deephaul Ravine - Difficulty: 0)
(@ATSPAWNID+1, @ATPROPERTIESID+1, 1, 2656, 4216.25, -2719.491455078125, 241.1346893310546875, 4.750776290893554687, 0, '0', 0, '', '', 56311), -- 296579 (PvP Rune Rejuv Visual (New)) (Area: Deephaul Ravine - Difficulty: 0)
(@ATSPAWNID+2, @ATPROPERTIESID+2, 1, 2656, 4043.9296875, -2844.163330078125, 196.4862060546875, 5.54541778564453125, 0, '0', 0, '', '', 56311), -- 425662 (PvP Rune Cooldown Visual (New)) (Area: Deephaul Ravine - Difficulty: 0)
(@ATSPAWNID+3, @ATPROPERTIESID+2, 1, 2656, 4082.973876953125, -3050.604248046875, 200.3532562255859375, 2.415738582611083984, 0, '0', 0, '', '', 56311), -- 425662 (PvP Rune Cooldown Visual (New)) (Area: Deephaul Ravine - Difficulty: 0)
(@ATSPAWNID+4, @ATPROPERTIESID+0, 1, 2656, 3915.22314453125, -2936.760498046875, 221.4468994140625, 5.737958908081054687, 0, '0', 0, '', '', 56311), -- 296582 (PvP Rune Berserking Visual (New)) (Area: Deephaul Ravine - Difficulty: 0)
(@ATSPAWNID+5, @ATPROPERTIESID+1, 1, 2656, 3916.983642578125, -3176.982666015625, 240.982879638671875, 1.561099767684936523, 0, '0', 0, '', '', 56311), -- 296579 (PvP Rune Rejuv Visual (New)) (Area: Deephaul Ravine - Difficulty: 0)
(@ATSPAWNID+6, @TRIGGER_ID_ALLIANCE, 1, 2656, 3919.4697265625, -3120.225830078125, 240.8458404541015625, 2.530723094940185546, 0, '0', 0, 'areatrigger_action_capture_flag', 'Deephaul Ravine - Capture Flag - Alliance', 0),
(@ATSPAWNID+7, @TRIGGER_ID_HORDE, 1, 2656, 4207.8994140625, -2777.05029296875, 239.8165435791015625, 2.391098499298095703, 0, '0', 0, 'areatrigger_action_capture_flag', 'Deephaul Ravine - Capture Flag - Horde', 0);

DELETE FROM `gameobject_template` WHERE `entry` IN (415330, 415326, 422412 /*Deephaul Crystal*/, 422413 /*Deephaul Crystal*/, 452913 /*Waterworks Vehicle Cart Exit*/, 452869 /*Purple Minecart Second Navigation Light*/, 452914 /*Earthenworks Vehicle Cart Exit*/, 452863 /*Junction Crystal Platform (Mid)*/, 452870 /*Purple Minecart First Navigation Light*/, 452864 /*Earthenworks Crystal Platform (Mid)*/, 437274 /*Earthenworks Starting Gate*/, 452871 /*Gold Minecart Second Navigation Light*/, 452897 /*Purple Cart Starting Door*/, 452865 /*Waterworks Cyrstal Platform*/, 449781 /*Gate*/, 452898 /*Gold Cart Starting Door*/, 452911 /*Earthenworks Vehicle Cart Entrance*/, 452899 /*Purple Cart Ending Door*/, 446147 /*Waterworks Starting Gate*/, 452912 /*Waterworks Vehicle Cart Entrance*/, 415206 /*Capture Point*/, 452900 /*Gold Cart Ending Door*/, 452868 /*Gold Minecart First Navigation Light*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(422412, 37, 91024, 'Deephaul Crystal', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Deephaul Crystal
(422413, 36, 91024, 'Deephaul Crystal', '', '', '', 1, 2178, 434339, 0, 1, 0, 1, 1, 10000, 30000, 422412, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Deephaul Crystal
(452913, 5, 85925, 'Waterworks Vehicle Cart Exit', '', '', '', 0.919063031673431396, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Waterworks Vehicle Cart Exit
(452869, 5, 92747, 'Purple Minecart Second Navigation Light', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Purple Minecart Second Navigation Light
(452914, 5, 85925, 'Earthenworks Vehicle Cart Exit', '', '', '', 0.919062972068786621, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Earthenworks Vehicle Cart Exit
(452863, 5, 92743, 'Junction Crystal Platform (Mid)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Junction Crystal Platform (Mid)
(452870, 5, 92747, 'Purple Minecart First Navigation Light', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Purple Minecart First Navigation Light
(452864, 5, 92744, 'Earthenworks Crystal Platform (Mid)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Earthenworks Crystal Platform (Mid)
(437274, 0, 85925, 'Earthenworks Starting Gate', '', '', '', 1.651218652725219726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Earthenworks Starting Gate
(452871, 5, 92747, 'Gold Minecart Second Navigation Light', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Gold Minecart Second Navigation Light
(452897, 0, 85281, 'Purple Cart Starting Door', '', '', '', 3.651738882064819335, 0, 86, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Purple Cart Starting Door
(452865, 5, 92742, 'Waterworks Cyrstal Platform', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Waterworks Cyrstal Platform
(449781, 0, 85925, 'Gate', '', '', '', 0.999999523162841796, 0, 0, 3000, 0, 0, 0, 0, 5793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Gate
(452898, 0, 84624, 'Gold Cart Starting Door', '', '', '', 4.273799896240234375, 0, 0, 3000, 0, 0, 0, 0, 5793, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Gold Cart Starting Door
(452911, 5, 85925, 'Earthenworks Vehicle Cart Entrance', '', '', '', 0.919062972068786621, 0, 0, 0, 0, 0, 0, 5793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Earthenworks Vehicle Cart Entrance
(452899, 0, 85281, 'Purple Cart Ending Door', '', '', '', 3.676867008209228515, 0, 86, 3000, 0, 0, 0, 1, 5793, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Purple Cart Ending Door
(446147, 0, 85925, 'Waterworks Starting Gate', '', '', '', 1.651219010353088378, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Waterworks Starting Gate
(452912, 5, 85925, 'Waterworks Vehicle Cart Entrance', '', '', '', 0.919062972068786621, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Waterworks Vehicle Cart Entrance
(415206, 5, 21202, 'Capture Point', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Capture Point
(452900, 0, 84624, 'Gold Cart Ending Door', '', '', '', 3.676867008209228515, 0, 86, 3000, 0, 0, 0, 0, 5793, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Gold Cart Ending Door
(452868, 5, 92747, 'Gold Minecart First Navigation Light', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56311), -- Gold Minecart First Navigation Light
(415330, 29, 0, 'Mine Cart Control Point Lava (West)', '', '', '', 1, 30, 0, 25424, 25423, 0, 0, 0, 0, 88514, 88515, 0, 0, 0, 25422, 1, 1, 50, 50, 1, 0, 0, 0, 0, 0, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421), -- Mine Cart Control Point Lava (West)
(415326, 29, 0, 'Mine Cart Control Point Cenote (East)', '', '', '', 1, 30, 0, 25416, 25417, 0, 0, 0, 0, 88510, 88511, 88512, 88512, 0, 25418, 1, 1, 50, 50, 1, 0, 100, 0, 0, 0, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56421); -- Mine Cart Control Point Cenote (East)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (422412 /*Deephaul Crystal*/, 422413 /*Deephaul Crystal*/, 452863 /*Junction Crystal Platform (Mid)*/, 437274 /*Earthenworks Starting Gate*/, 449781 /*Gate*/, 452864 /*Earthenworks Crystal Platform (Mid)*/, 452865 /*Waterworks Cyrstal Platform*/, 452898 /*Gold Cart Starting Door*/, 452899 /*Purple Cart Ending Door*/, 452897 /*Purple Cart Starting Door*/, 452900 /*Gold Cart Ending Door*/, 446147 /*Waterworks Starting Gate*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(422412, 2059, 0, 0, 0), -- Deephaul Crystal
(422413, 2059, 32, 0, 0), -- Deephaul Crystal
(452863, 0, 0, 0, 9984), -- Junction Crystal Platform (Mid)
(437274, 1375, 32, 0, 0), -- Earthenworks Starting Gate
(449781, 0, 32, 0, 0), -- Gate
(452864, 0, 0, 0, 9984), -- Earthenworks Crystal Platform (Mid)
(452865, 0, 0, 0, 9984), -- Waterworks Cyrstal Platform
(452898, 0, 32, 0, 0), -- Gold Cart Starting Door
(452899, 0, 32, 0, 0), -- Purple Cart Ending Door
(452897, 1375, 32, 0, 0), -- Purple Cart Starting Door
(452900, 1375, 32, 0, 0), -- Gold Cart Ending Door
(446147, 1375, 32, 0, 0); -- Waterworks Starting Gate

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 446147, 2656, 14990, 14990, '0', '0', 0, 3963.607666015625, -3332.4931640625, 277.823486328125, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 56311), -- Waterworks Starting Gate (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+1, 452913, 2656, 14990, 14990, '0', '0', 0, 3915.74658203125, -3089.673583984375, 240.85406494140625, 2.487152338027954101, 0, 0, 0.946939468383789062, 0.321411937475204467, 7200, 255, 1, 56311), -- Waterworks Vehicle Cart Exit (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+2, 452912, 2656, 14990, 14990, '0', '0', 0, 3898.280517578125, -3076.1875, 240.8842315673828125, 2.487152338027954101, 0, 0, 0.946939468383789062, 0.321411937475204467, 7200, 255, 1, 56311), -- Waterworks Vehicle Cart Entrance (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+3, 452914, 2656, 14990, 14990, '0', '0', 0, 4212.33349609375, -2805.507080078125, 240.9688262939453125, 5.558939456939697265, 0, 0, -0.35426044464111328, 0.935146808624267578, 7200, 255, 1, 56311), -- Earthenworks Vehicle Cart Exit (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+4, 452900, 2656, 14990, 14990, '0', '0', 0, 4214.5947265625, -2915.310791015625, 199.0317535400390625, 0.000001907348632812, 0, 0, 0.000000953674316406, 1, 7200, 255, 1, 56311), -- Gold Cart Ending Door (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+5, 452897, 2656, 14990, 14990, '0', '0', 0, 4254.08251953125, -2750.7119140625, 237.290069580078125, 6.265735149383544921, 0, 0, -0.00872516632080078, 0.999961912631988525, 7200, 255, 1, 56311), -- Purple Cart Starting Door (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+6, 452899, 2656, 14990, 14990, '0', '0', 0, 3914.236083984375, -2984.739501953125, 199.1048431396484375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56311), -- Purple Cart Ending Door (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+7, 452898, 2656, 14990, 14990, '0', '0', 0, 3875.40283203125, -3150.314208984375, 236.704071044921875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56311), -- Gold Cart Starting Door (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+8, 452911, 2656, 14990, 14990, '0', '0', 0, 4229.45556640625, -2819.204833984375, 240.998992919921875, 5.593845844268798828, 0, 0, -0.33788585662841796, 0.941187083721160888, 7200, 255, 1, 56311), -- Earthenworks Vehicle Cart Entrance (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+9, 452869, 2656, 14990, 14990, '0', '0', 0, 3982.30029296875, -2971.098876953125, 199.8299102783203125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56311), -- Purple Minecart Second Navigation Light (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+10, 452868, 2656, 14990, 14990, '0', '0', 0, 4020.803955078125, -3058.25341796875, 205.85986328125, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 56311), -- Gold Minecart First Navigation Light (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+11, 452871, 2656, 14990, 14990, '0', '0', 0, 4145.8525390625, -2929.111083984375, 201.28411865234375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56311), -- Gold Minecart Second Navigation Light (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+12, 452870, 2656, 14990, 14990, '0', '0', 0, 4108.4443359375, -2841.63720703125, 201.9049224853515625, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 56311), -- Purple Minecart First Navigation Light (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+13, 452865, 2656, 14990, 14990, '0', '0', 0, 3919.4697265625, -3120.225830078125, 240.8458404541015625, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 7200, 255, 1, 56311), -- Waterworks Cyrstal Platform (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+14, 452864, 2656, 14990, 14990, '0', '0', 0, 4207.8994140625, -2777.05029296875, 239.8165435791015625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 7200, 255, 1, 56311), -- Earthenworks Crystal Platform (Mid) (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+15, 415206, 2656, 14990, 14990, '0', '0', 0, 4064.75, -2947.583251953125, 192.6782989501953125, 4.428785324096679687, 0, 0, -0.7999429702758789, 0.600076079368591308, 7200, 255, 1, 56311), -- Capture Point (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+16, 449781, 2656, 14990, 14990, '0', '0', 0, 4383.41259765625, -3345.90966796875, 341.52484130859375, 1.527163028717041015, 0, 0, 0.6915130615234375, 0.722363948822021484, 7200, 255, 1, 56311), -- Gate (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+17, 437274, 2656, 14990, 14990, '0', '0', 0, 4162.62841796875, -2569.15625, 276.757110595703125, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 56311), -- Earthenworks Starting Gate (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+18, 452863, 2656, 14990, 14990, '0', '0', 0, 4062.65283203125, -2949.3525390625, 204.7332305908203125, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 7200, 255, 1, 56311), -- Junction Crystal Platform (Mid) (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+19, 465705, 2656, 14990, 14990, '0', '0', 0, 3752.389404296875, -3484.66748046875, 324.779205322265625, 0.177568942308425903, 0, 0, 0.088667869567871093, 0.996061265468597412, 7200, 255, 1, 56311), -- Cooking Fire (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@OGUID+20, 422413, 2656, 14990, 15100, '0', '0', 0, 4062.6181640625, -2949.401123046875, 204.7358856201171875, 2.468524694442749023, 0, 0, 0.943904876708984375, 0.33021751046180725, 7200, 255, 1, 56311); -- Deephaul Crystal (Area: The Earthenworks - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+13, 0, 0, 0, 1, 0, 9984), -- Waterworks Cyrstal Platform
(@OGUID+14, 0, 0, 0, 1, 0, 9984), -- Earthenworks Crystal Platform (Mid)
(@OGUID+16, 0, 0, 0.691513776779174804, 0.722363293170928955, 0, 0), -- Gate
(@OGUID+18, 0, 0, 0, 1, 0, 9984), -- Junction Crystal Platform (Mid)
(@OGUID+19, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0); -- Cooking Fire

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (117037, 119944, 119945, 120457, 114328, 116912);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(117037, 4.821242809295654296, 0.800000011920928955, 0, 56311),
(119944, 0.372000008821487426, 1.5, 0, 56311),
(119945, 0.236000001430511474, 1.5, 0, 56311),
(120457, 1, 1, 0, 56311),
(114328, 2.18238067626953125, 0, 0, 56311),
(116912, 1.928423166275024414, 2.5, 0, 56311);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+103;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 223791, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4280.15283203125, -2787.59375, 260.647735595703125, 5.158649921417236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Golem (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+1, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4240.21728515625, -2699.244873046875, 241.6643829345703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+2, 223873, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4264.9599609375, -2603.873291015625, 305.3443603515625, 4.717678546905517578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Ironhaul Stoneskitterer (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+3, 224085, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4334.369140625, -2897.060791015625, 324.234710693359375, 3.236279726028442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Earthfury Cragshar (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+4, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4176.8193359375, -2629.192626953125, 257.613037109375, 1.754981637001037597, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3938.1298828125, -3312.26025390625, 279.753753662109375, 1.977250218391418457, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4125.02734375, -2632.217041015625, 265.973785400390625, 1.18469393253326416, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3892.064208984375, -3316.33154296875, 295.68316650390625, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 224058, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4282.98193359375, -2744.80029296875, 281.999755859375, 4.033280372619628906, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Shaleshell clicker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 223873, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4062.74560546875, -2704.70654296875, 268.97674560546875, 0.079499617218971252, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ironhaul Stoneskitterer (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4226.1396484375, -2674.201416015625, 243.859832763671875, 3.65311288833618164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+11, 224088, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4211.77099609375, -2956.390625, 221.3336639404296875, 1.676120638847351074, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ploughworm (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4157.56005859375, -2565.689208984375, 295.46600341796875, 1.537462592124938964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+13, 224079, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4095.571044921875, -3296.84521484375, 345.941925048828125, 3.046056032180786132, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Dusty Shalewing (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 224078, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4072.17431640625, -3104.51806640625, 222.511993408203125, 1.558755755424499511, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Glowmite (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+15, 223791, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4321.1396484375, -2741.222900390625, 294.047027587890625, 6.022153377532958984, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Golem (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3864.8837890625, -3216.314697265625, 281.835540771484375, 4.230333328247070312, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 224052, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3850.3994140625, -3136.876708984375, 279.928985595703125, 3.482315778732299804, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ghostcap Menace (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 224052, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3919.5634765625, -3251.953125, 269.473388671875, 0.780105948448181152, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ghostcap Menace (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 224079, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4050.11181640625, -3328.05615234375, 327.0787353515625, 1.601912379264831542, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Dusty Shalewing (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 224078, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3887.577392578125, -3059.763916015625, 246.73699951171875, 5.465106964111328125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Glowmite (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4179.6279296875, -2887.163818359375, 203.08648681640625, 2.861192703247070312, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4142.96240234375, -2518.680419921875, 277.28424072265625, 0.123077638447284698, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3874.857666015625, -3247.270751953125, 286.9083251953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+24, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4152.8212890625, -2687.2109375, 241.5498809814453125, 1.411480426788330078, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3896.02001953125, -3122.123291015625, 243.780548095703125, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3953.788818359375, -2873.005615234375, 243.004302978515625, 2.448262453079223632, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4068.678955078125, -2773.416748046875, 216.4803009033203125, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 224778, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3977.7509765625, -3364.632080078125, 278.2138671875, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Troglofrog (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 223792, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3967.65283203125, -3335.935791015625, 298.38873291015625, 4.463271617889404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Mud Skipper (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+30, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4212.89404296875, -2898.83154296875, 221.1344146728515625, 3.245197057723999023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+31, 223879, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4103.1328125, -2638.607666015625, 266.462890625, 2.179662466049194335, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Railbot (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 223873, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4181.56103515625, -2997.744873046875, 240.4316864013671875, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ironhaul Stoneskitterer (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+33, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4121.931640625, -2654.8681640625, 269.307464599609375, 5.302462577819824218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+34, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4143.7255859375, -2530.28125, 277.367584228515625, 0.996418535709381103, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+35, 223792, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4032.342041015625, -3288.29345703125, 302.747650146484375, 3.748849391937255859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Mud Skipper (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+36, 223464, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3869.118896484375, -2969.0400390625, 252.381591796875, 0.027695277705788612, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Oath Eater (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+37, 224087, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3978.8681640625, -3357.302001953125, 321.9140625, 3.805659294128417968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Ruffious (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+38, 224086, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4175.00244140625, -2560.21875, 328.111358642578125, 2.168870925903320312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Foreman Uzjax (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+39, 223792, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3960.916748046875, -2890.661376953125, 241.05975341796875, 0.518357694149017333, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Mud Skipper (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+40, 224052, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3932.8955078125, -3308.306640625, 276.990386962890625, 0.22862941026687622, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ghostcap Menace (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 224088, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4082.125, -3019.30029296875, 203.185943603515625, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ploughworm (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 223791, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4268.8427734375, -2887.6357421875, 270.68572998046875, 5.930243492126464843, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Golem (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3925.585693359375, -3386.93701171875, 280.682464599609375, 5.390571117401123046, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+44, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3989.843017578125, -2779.399658203125, 278.238037109375, 4.766505241394042968, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+45, 224078, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3927.150146484375, -3217.47216796875, 254.1864166259765625, 0.893170952796936035, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Glowmite (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4159.62060546875, -2501.354248046875, 277.367584228515625, 4.013216018676757812, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4124.59912109375, -2688.510498046875, 239.72265625, 5.20873880386352539, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4015.407958984375, -3360.741455078125, 320.223388671875, 3.10334014892578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+49, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3922.49951171875, -3368.96630859375, 298.03399658203125, 4.929032325744628906, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3982.87841796875, -2795.9619140625, 268.650054931640625, 0.180171936750411987, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+51, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4179.5341796875, -2552.65185546875, 277.28424072265625, 3.726926803588867187, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3876.9248046875, -3325.234375, 303.460205078125, 4.861912727355957031, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4180.568359375, -2652.763427734375, 245.2271575927734375, 2.706277847290039062, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+54, 224778, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3981.3447265625, -3408.77783203125, 280.821044921875, 2.347647905349731445, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Troglofrog (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3910.49560546875, -2920.815673828125, 257.009765625, 4.855585575103759765, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+56, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3999.3203125, -3296.27783203125, 282.006683349609375, 1.385261893272399902, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+57, 223792, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3961.36376953125, -2891.65625, 241.00408935546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Mud Skipper (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+58, 223792, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4032.34814453125, -3287.345458984375, 302.48486328125, 2.981364011764526367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Mud Skipper (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+59, 223879, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4065.162353515625, -2619.489501953125, 266.7166748046875, 6.064524650573730468, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Railbot (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+60, 224088, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4068.751708984375, -2858.723876953125, 197.462188720703125, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ploughworm (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+61, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4234.330078125, -2643.708251953125, 266.2962646484375, 3.639921188354492187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+62, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4114.5302734375, -2676.609375, 239.63909912109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+63, 224078, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3942.138916015625, -3030.73779296875, 223.63775634765625, 0.692813873291015625, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Glowmite (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4108.244140625, -3004.1875, 200.5729827880859375, 0.057115137577056884, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4172.859375, -2824.72119140625, 239.798187255859375, 1.992575645446777343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+66, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4197.396484375, -2800, 240.294219970703125, 4.383592605590820312, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+67, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4050.494873046875, -3213.200927734375, 259.499053955078125, 0.179143592715263366, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4181.4091796875, -2518.305419921875, 277.28424072265625, 2.034933805465698242, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+69, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3977.631591796875, -2930.059326171875, 213.80938720703125, 3.098464012145996093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 224058, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4075.100830078125, -2713.348876953125, 263.24017333984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Shaleshell clicker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+71, 224778, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3944.460205078125, -3401.026123046875, 280.42919921875, 5.897035121917724609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Troglofrog (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4147.85595703125, -2600.454833984375, 257.615753173828125, 5.624623775482177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+73, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4235.3427734375, -2847.32421875, 239.317596435546875, 0.436967164278030395, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 224082, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3972.276123046875, -3354.09423828125, 285.96917724609375, 1.712916254997253417, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Vibrant Glowfly (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+75, 223879, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4208.72802734375, -3024.903076171875, 248.004302978515625, 1.425424814224243164, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Railbot (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+76, 224088, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4243.82373046875, -2833.5078125, 239.8661651611328125, 1.318714618682861328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ploughworm (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+77, 224088, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4149.46435546875, -2669.803955078125, 244.431427001953125, 5.459437370300292968, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ploughworm (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+78, 224079, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4096.81689453125, -3300.0517578125, 363.412139892578125, 1.722026705741882324, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Dusty Shalewing (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 224079, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4063.9140625, -3307.0625, 358.053192138671875, 3.00242924690246582, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Dusty Shalewing (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 224078, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4025.16748046875, -3222.338623046875, 248.995574951171875, 1.300907254219055175, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Glowmite (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3834.193115234375, -3122.380859375, 287.869384765625, 0.604109525680541992, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+82, 224059, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4031.098876953125, -3313.03466796875, 298.04058837890625, 2.026293754577636718, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Terrace Moth (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+83, 223868, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3911.896728515625, -3281.44091796875, 277.61737060546875, 4.759921073913574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Sweetsnuffler (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+84, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4201.58740234375, -2876.96533203125, 219.7887725830078125, 0.140408962965011596, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+85, 223879, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4122.34814453125, -2606.569580078125, 266.725830078125, 6.012950897216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Railbot (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+86, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4193.54150390625, -2630.338623046875, 267.031005859375, 3.21850895881652832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+87, 223874, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4178.53369140625, -2546.154541015625, 277.367584228515625, 4.545335292816162109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Cogwalker (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+88, 223792, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3966.75, -3335.842041015625, 298.396392822265625, 4.643887042999267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Mud Skipper (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+89, 224052, 2656, 14990, 14990, '0', '0', 0, 0, 0, 3977.747314453125, -2890.05029296875, 230.1460723876953125, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ghostcap Menace (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4230.4150390625, -2738.34033203125, 239.8985748291015625, 4.959980964660644531, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 224052, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4002.046875, -3258.30908203125, 271.576080322265625, 1.861364364624023437, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Ghostcap Menace (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+92, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4049.49560546875, -2867.057373046875, 196.3338623046875, 3.77356719970703125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4055.8369140625, -2816.19970703125, 203.812774658203125, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+94, 224079, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4106.361328125, -3294.195068359375, 352.8839111328125, 2.860113859176635742, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Dusty Shalewing (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+95, 223870, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4142.984375, -2557.3994140625, 277.549957275390625, 5.774860382080078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Stagshell (Area: Deephaul Ravine - Difficulty: 0) CreateObject1
(@CGUID+96, 223879, 2656, 14990, 14990, '0', '0', 0, 0, 0, 4164.69384765625, -3047.6923828125, 246.6746673583984375, 5.391783714294433593, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 56311), -- Malfunctioning Railbot (Area: Deephaul Ravine - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+97, 214731, 2656, 14990, 15100, '0', '0', 0, 0, 0, 4086.218017578125, -2918.017333984375, 238.4026641845703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Generic Bunny (Area: The Earthenworks - Difficulty: 0) CreateObject2
(@CGUID+98, 225893, 2656, 14990, 15100, '0', '0', 0, 0, 0, 4207.73974609375, -2777.22216796875, 239.90032958984375, 2.41066741943359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Crystal (Area: The Earthenworks - Difficulty: 0) CreateObject1
(@CGUID+99, 225893, 2656, 14990, 15100, '0', '0', 0, 0, 0, 3919.1875, -3120.069580078125, 240.883331298828125, 5.662075519561767578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Crystal (Area: The Earthenworks - Difficulty: 0) CreateObject1
(@CGUID+100, 13117, 2656, 14990, 15101, '0', '0', 0, 0, 1, 4025.411376953125, -2783.75, 239.82196044921875, 5.483966350555419921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Horde Spirit Guide (Area: Junction - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+101, 13116, 2656, 14990, 15101, '0', '0', 0, 0, 1, 3964.228271484375, -3267.25341796875, 257.626953125, 1.527171611785888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Alliance Spirit Guide (Area: Junction - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+102, 13117, 2656, 14990, 15101, '0', '0', 0, 0, 1, 4162.6962890625, -2622.84716796875, 258.04852294921875, 4.668649196624755859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311), -- Horde Spirit Guide (Area: Junction - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+103, 13116, 2656, 14990, 15101, '0', '0', 0, 0, 1, 4107.74462890625, -3117.55908203125, 239.823455810546875, 2.410429239273071289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56311); -- Alliance Spirit Guide (Area: Junction - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=225893; -- Crystal
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1073741824 WHERE `entry`=214731; -- Generic Bunny
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_walk`=10, `speed_run`=3.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912, `unit_flags3`=16777217, `ScriptName`='npc_bg_deephaul_ravine_earthen_mine_cart' WHERE `entry`=211271; -- Earthen Mine Cart
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_walk`=10, `speed_run`=3.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912, `unit_flags3`=16777216, `ScriptName`='npc_bg_deephaul_ravine_earthen_mine_cart' WHERE `entry`=211155; -- Earthen Mine Cart
UPDATE `creature_template` SET `faction`=3398, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=229276; -- Foreman Uzjax
UPDATE `creature_template` SET `faction`=3398, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=229277; -- Ruffious
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224082; -- Vibrant Glowfly
UPDATE `creature_template` SET `faction`=3398, `speed_run`=1.38888859748840332, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=8657, `ScriptName`='npc_bg_deephaul_ravine_foreman_uzjax' WHERE `entry`=224086; -- Foreman Uzjax
UPDATE `creature_template` SET `faction`=3398, `speed_run`=1.38888859748840332, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=8658, `ScriptName`='npc_bg_deephaul_ravine_ruffious' WHERE `entry`=224087; -- Ruffious
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223464; -- Oath Eater
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223879; -- Malfunctioning Railbot
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223792; -- Mud Skipper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224778; -- Troglofrog
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223868; -- Sweetsnuffler
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224052; -- Ghostcap Menace
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224078; -- Glowmite
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224079; -- Dusty Shalewing
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224088; -- Ploughworm
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224058; -- Shaleshell clicker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223874; -- Malfunctioning Cogwalker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224059; -- Terrace Moth
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=224085; -- Earthfury Cragshar
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223873; -- Ironhaul Stoneskitterer
UPDATE `creature_template` SET `faction`=2575, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223870; -- Stagshell
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=223791; -- Golem
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.399999976158142089, `speed_run`=0.5, `BaseAttackTime`=2000, `unit_flags2`=67108864, `unit_flags3`=16777217, `VehicleId`=2119, `ScriptName`='npc_bg_deephaul_cavern_mine_cart' WHERE `entry` IN (214690, 217346); -- Mine Cart
UPDATE `creature_template` SET `faction`=35, `speed_walk`=10, `speed_run`=3.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=16809984, `VehicleId`=8256 WHERE `entry` IN (211153, 211270); -- Earthen Mine Cart
UPDATE `creature_template` SET `ScriptName`='npc_bg_deephaul_ravine_earthen_mine_cart_horde' WHERE `entry`=211153;
UPDATE `creature_template` SET `ScriptName`='npc_bg_deephaul_ravine_earthen_mine_cart_alliance' WHERE `entry`=211270;

DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (211153, 225893, 214731, 211270, 211271, 211155, 217346, 214690, 223464, 223873, 224085, 223874, 223791, 229276, 223868, 224086, 224778, 223792, 229277, 224087, 223870, 224088, 224082, 224052, 224058, 224078, 223879, 224059, 224079);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(225893, 0, 10, 1, 1, 276874, 1610612818, 6), -- Crystal
(214731, 0, 10, 1, 1, 264182, 1073742848, 0), -- Generic Bunny
(211270, 0, 10, 1, 1, 260650, 1073741824, 131078), -- Earthen Mine Cart
(211271, 0, 10, 1, 1, 260651, 1073741824, 6), -- Earthen Mine Cart
(211155, 0, 10, 1, 1, 260506, 1073741824, 6), -- Earthen Mine Cart
(217346, 0, 10, 0.023800000548362731, 1, 266838, 1077936130, 0), -- Mine Cart
(214690, 0, 10, 0.023800000548362731, 1, 264141, 1077936130, 0), -- Mine Cart
(223464, 0, 10, 1, 1, 274291, 0, 0), -- Oath Eater
(223873, 0, 10, 1, 1, 274735, 0, 0), -- Ironhaul Stoneskitterer
(224085, 0, 10, 1, 1, 274952, 0, 0), -- Earthfury Cragshar
(223874, 0, 10, 1, 1, 274736, 0, 0), -- Malfunctioning Cogwalker
(223791, 0, 10, 1, 1, 274653, 0, 0), -- Golem
(229276, 0, 10, 1, 1, 280555, 0, 0), -- Foreman Uzjax
(223868, 0, 10, 1, 1, 274730, 0, 0), -- Sweetsnuffler
(224086, 0, 10, 1, 1, 274953, 0, 0), -- Foreman Uzjax
(224778, 0, 10, 1, 1, 275704, 0, 0), -- Troglofrog
(223792, 0, 10, 1, 1, 274654, 0, 0), -- Mud Skipper
(229277, 0, 10, 1, 1, 280556, 0, 0), -- Ruffious
(224087, 0, 10, 1, 1, 274954, 0, 0), -- Ruffious
(223870, 0, 10, 1, 1, 274732, 0, 0), -- Stagshell
(224088, 0, 10, 1, 1, 274955, 0, 0), -- Ploughworm
(224082, 0, 10, 1, 1, 274949, 0, 0), -- Vibrant Glowfly
(224052, 0, 10, 1, 1, 274919, 0, 0), -- Ghostcap Menace
(224058, 0, 10, 1, 1, 274925, 0, 0), -- Shaleshell clicker
(224078, 0, 10, 1, 1, 274945, 0, 0), -- Glowmite
(223879, 0, 10, 1, 1, 274741, 0, 0), -- Malfunctioning Railbot
(224059, 0, 10, 1, 1, 274926, 0, 0), -- Terrace Moth
(224079, 0, 10, 1, 1, 274946, 0, 0), -- Dusty Shalewing
(211153, 0, 10, 1, 1, 260504, 1073741824, 131078); -- Earthen Mine Cart

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224079 AND `DifficultyID`=0); -- 224079 (Dusty Shalewing) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224059 AND `DifficultyID`=0); -- 224059 (Terrace Moth) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223879 AND `DifficultyID`=0); -- 223879 (Malfunctioning Railbot) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224078 AND `DifficultyID`=0); -- 224078 (Glowmite) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224058 AND `DifficultyID`=0); -- 224058 (Shaleshell clicker) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224052 AND `DifficultyID`=0); -- 224052 (Ghostcap Menace) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224082 AND `DifficultyID`=0); -- 224082 (Vibrant Glowfly) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224088 AND `DifficultyID`=0); -- 224088 (Ploughworm) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223870 AND `DifficultyID`=0); -- 223870 (Stagshell) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224087 AND `DifficultyID`=0); -- 224087 (Ruffious) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `StaticFlags1`=536871168, `VerifiedBuild`=56311 WHERE (`Entry`=229277 AND `DifficultyID`=0); -- 229277 (Ruffious) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223792 AND `DifficultyID`=0); -- 223792 (Mud Skipper) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224778 AND `DifficultyID`=0); -- 224778 (Troglofrog) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224086 AND `DifficultyID`=0); -- 224086 (Foreman Uzjax) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223868 AND `DifficultyID`=0); -- 223868 (Sweetsnuffler) -
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=973, `StaticFlags1`=536871168, `VerifiedBuild`=56311 WHERE (`Entry`=225893 AND `DifficultyID`=0); -- 225893 (Crystal) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=181, `StaticFlags1`=536871168, `VerifiedBuild`=56311 WHERE (`Entry`=214731 AND `DifficultyID`=0); -- 214731 (Generic Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2737, `VerifiedBuild`=56311 WHERE (`Entry`=211270 AND `DifficultyID`=0); -- 211270 (Earthen Mine Cart) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2737, `VerifiedBuild`=56311 WHERE (`Entry`=211271 AND `DifficultyID`=0); -- 211271 (Earthen Mine Cart) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2737, `VerifiedBuild`=56311 WHERE (`Entry`=211155 AND `DifficultyID`=0); -- 211155 (Earthen Mine Cart) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2737, `StaticFlags1`=268435456, `VerifiedBuild`=56311 WHERE (`Entry`=214690 AND `DifficultyID`=0); -- 214690 (Mine Cart) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2737, `StaticFlags1`=268435456, `VerifiedBuild`=56311 WHERE (`Entry`=217346 AND `DifficultyID`=0); -- 217346 (Mine Cart) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223464 AND `DifficultyID`=0); -- 223464 (Oath Eater) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223873 AND `DifficultyID`=0); -- 223873 (Ironhaul Stoneskitterer) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=224085 AND `DifficultyID`=0); -- 224085 (Earthfury Cragshar) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223874 AND `DifficultyID`=0); -- 223874 (Malfunctioning Cogwalker) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `VerifiedBuild`=56311 WHERE (`Entry`=223791 AND `DifficultyID`=0); -- 223791 (Golem) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2809, `StaticFlags1`=536871168, `VerifiedBuild`=56311 WHERE (`Entry`=229276 AND `DifficultyID`=0); -- 229276 (Foreman Uzjax) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2737 WHERE (`Entry`=211153 AND `DifficultyID`=0); -- 211153 (Earthen Mine Cart)

DELETE FROM `creature_text` WHERE `CreatureID` IN (224086, 224087);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(224086, 0, 0, 'This is the Deephaul Ravine, where we harvest precious materials. Your task is to secure as many of them as possible before Ruffious does the same.', 12, 0, 100, 0, 0, 247070, 260583, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224086, 1, 0, 'Focus your attention on escorting the mine carts and on seizing the crystal in the center of the mine. Failure is not an option.', 12, 0, 100, 0, 0, 247071, 262502, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224086, 2, 0, 'A crystal has formed deep within the mine. Seize it before Ruffious does!', 12, 0, 100, 0, 0, 247064, 262649, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224086, 3, 0, 'One of our carts is leaving the station. Do not let it fall into Ruffious\'s clutches!', 12, 0, 100, 0, 0, 247066, 262676, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224086, 3, 1, 'Ruffious\'s lackeys have loaded up a cart. Take control of it and siphon its contents!', 12, 0, 100, 0, 0, 247065, 262657, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224086, 4, 0, 'The Unbound will surely waste such precious materials. At least we are not leaving empty handed.', 12, 0, 100, 0, 0, 247069, 260596, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224086, 5, 0, 'An admirable performance. The Machine Speakers will put these materials to good use.', 12, 0, 100, 0, 0, 247072, 260594, 3, 'Foreman Uzjax'), -- Only visible if PvpFaction = Horde
(224087, 0, 0, 'Welcome to the Deephaul Ravine, friends! Our job today: gather as many minerals and gems as we can carry, before Uzjax gets to them.', 12, 0, 100, 0, 0, 247055, 260449, 3, 'Ruffious'), -- Only visible if PvpFaction = Alliance
(224087, 1, 0, 'To do that, you\'ll have to stick close to the mine carts and grab hold of the shiny crystal in the center of the tracks. Let\'s get to it!', 12, 0, 100, 0, 0, 247056, 262501, 3, 'Ruffious'), -- Only visible if PvpFaction = Alliance
(224087, 2, 0, 'I see a crystal down in the mines! Grab it before Uzjax gets to it!', 12, 0, 100, 0, 0, 247049, 260475, 3, 'Ruffious'), -- Only visible if PvpFaction = Alliance
(224087, 3, 0, 'Uzjax has a cart leaving his quarry. I say we take it for ourselves!', 12, 0, 100, 0, 0, 247051, 260464, 3, 'Ruffious'), -- Only visible if PvpFaction = Alliance
(224087, 3, 1, 'One of our carts is loaded up! Make sure that it reaches its destination!', 12, 0, 100, 0, 0, 247050, 260463, 3, 'Ruffious'), -- Only visible if PvpFaction = Alliance
(224087, 4, 0, 'Well, it\'s not the best haul I\'ve ever seen. But it will do. Thanks for the hard work.', 12, 0, 100, 0, 0, 247054, 260458, 3, 'Ruffious'), -- Only visible if PvpFaction = Alliance
(224087, 5, 0, 'Nice work! With a haul like this, we\'ll be able to make all sorts of repairs around Khaz Algar.', 12, 0, 100, 0, 0, 247057, 260457, 3, 'Ruffious'); -- Only visible if PvpFaction = Alliance

DELETE FROM `vehicle_template` WHERE `creatureId` IN (211153, 211270);
INSERT INTO `vehicle_template` (`creatureId`, `despawnDelayMs`) VALUES
(211153, 10000),
(211270, 10000);

DELETE FROM `vehicle_template_accessory` WHERE (`entry`=224086 AND `seat_id`=0) OR (`entry`=224087 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(224086, 229276, 0, 0, 'Foreman Uzjax - Foreman Uzjax', 7, 0), -- Foreman Uzjax - Foreman Uzjax
(224087, 229277, 0, 0, 'Ruffious - Ruffious', 7, 0); -- Ruffious - Ruffious

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (224086, 224087, 211155, 211271);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(224086, 46598, 0x0, 0),
(224087, 46598, 0x0, 0),
(211155, 424166, 0x3, 0),
(211271, 424383, 0x3, 0);

SET @PATH := 217346 * 100;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Deephaul Ravine - Mine Cart - West');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4251.2393, -2750.6267, 239.93042, NULL, 0),
(@PATH, 1, 4209.2393, -2750.6267, 239.68042, NULL, 0),
(@PATH, 2, 4197.2393, -2750.6267, 239.43042, NULL, 0),
(@PATH, 3, 4192.4893, -2750.6267, 239.43042, NULL, 0),
(@PATH, 4, 4189.2393, -2750.6267, 239.43042, NULL, 0),
(@PATH, 5, 4186.9893, -2750.6267, 238.93042, NULL, 0),
(@PATH, 6, 4184.7393, -2750.6267, 238.43042, NULL, 0),
(@PATH, 7, 4182.4893, -2750.3767, 237.68042, NULL, 0),
(@PATH, 8, 4180.4893, -2750.3767, 236.93042, NULL, 0),
(@PATH, 9, 4178.2393, -2750.3767, 236.18042, NULL, 0),
(@PATH, 10, 4175.7393, -2750.3767, 235.18042, NULL, 0),
(@PATH, 11, 4173.7393, -2750.3767, 234.68042, NULL, 0),
(@PATH, 12, 4171.4893, -2750.6267, 233.93042, NULL, 0),
(@PATH, 13, 4168.9893, -2750.3767, 232.93042, NULL, 0),
(@PATH, 14, 4166.7393, -2750.3767, 232.18042, NULL, 0),
(@PATH, 15, 4164.9893, -2750.3767, 231.68042, NULL, 0),
(@PATH, 16, 4162.2393, -2750.3767, 230.68042, NULL, 0),
(@PATH, 17, 4159.9893, -2750.3767, 229.93042, NULL, 0),
(@PATH, 18, 4157.7393, -2750.3767, 229.18042, NULL, 0),
(@PATH, 19, 4155.2393, -2750.1267, 228.18042, NULL, 0),
(@PATH, 20, 4152.9893, -2750.3767, 227.68042, NULL, 0),
(@PATH, 21, 4150.9893, -2750.1267, 226.93042, NULL, 0),
(@PATH, 22, 4148.7393, -2750.3767, 226.18042, NULL, 0),
(@PATH, 23, 4146.2393, -2750.3767, 225.18042, NULL, 0),
(@PATH, 24, 4143.7393, -2750.3767, 224.43042, NULL, 0),
(@PATH, 25, 4141.4893, -2750.3767, 223.93042, NULL, 0),
(@PATH, 26, 4139.2393, -2750.1267, 223.43042, NULL, 0),
(@PATH, 27, 4136.4893, -2750.3767, 223.18042, NULL, 0),
(@PATH, 28, 4133.9893, -2750.3767, 223.18042, NULL, 0),
(@PATH, 29, 4131.7393, -2750.1267, 223.18042, NULL, 0),
(@PATH, 30, 4129.7393, -2750.3767, 223.18042, NULL, 0),
(@PATH, 31, 4126.9893, -2750.6267, 223.18042, NULL, 0),
(@PATH, 32, 4124.4893, -2750.3767, 223.18042, NULL, 0),
(@PATH, 33, 4121.9893, -2750.6267, 223.18042, NULL, 0),
(@PATH, 34, 4119.9893, -2750.8767, 223.18042, NULL, 0),
(@PATH, 35, 4117.2393, -2752.3767, 223.18042, NULL, 0),
(@PATH, 36, 4116.2393, -2754.6267, 223.18042, NULL, 0),
(@PATH, 37, 4115.9893, -2756.6267, 223.18042, NULL, 0),
(@PATH, 38, 4115.9893, -2759.1267, 223.18042, NULL, 0),
(@PATH, 39, 4116.2393, -2761.1267, 222.93042, NULL, 0),
(@PATH, 40, 4116.2393, -2763.6267, 222.68042, NULL, 0),
(@PATH, 41, 4115.9893, -2766.1267, 222.43042, NULL, 0),
(@PATH, 42, 4116.4893, -2769.1267, 221.93042, NULL, 0),
(@PATH, 43, 4116.4893, -2771.6267, 221.43042, NULL, 0),
(@PATH, 44, 4116.2393, -2773.3767, 220.68042, NULL, 0),
(@PATH, 45, 4116.2393, -2775.6267, 220.43042, NULL, 0),
(@PATH, 46, 4116.2393, -2777.8767, 219.68042, NULL, 0),
(@PATH, 47, 4116.2393, -2780.1267, 218.93042, NULL, 0),
(@PATH, 48, 4115.9893, -2782.3767, 218.18042, NULL, 0),
(@PATH, 49, 4116.2393, -2784.6267, 217.43042, NULL, 0),
(@PATH, 50, 4116.2393, -2786.8767, 216.68042, NULL, 0),
(@PATH, 51, 4116.2393, -2788.8767, 215.93042, NULL, 0),
(@PATH, 52, 4116.2393, -2791.1267, 215.18042, NULL, 0),
(@PATH, 53, 4116.2393, -2793.6267, 214.43042, NULL, 0),
(@PATH, 54, 4116.2393, -2796.1267, 213.43042, NULL, 0),
(@PATH, 55, 4116.2393, -2798.1267, 212.68042, NULL, 0),
(@PATH, 56, 4116.4893, -2800.8767, 211.93042, NULL, 0),
(@PATH, 57, 4116.2393, -2802.6267, 211.18042, NULL, 0),
(@PATH, 58, 4116.2393, -2804.8767, 210.43042, NULL, 0),
(@PATH, 59, 4116.2393, -2807.3767, 209.68042, NULL, 0),
(@PATH, 60, 4116.2393, -2809.6267, 208.93042, NULL, 0),
(@PATH, 61, 4116.2393, -2812.1267, 208.18042, NULL, 0),
(@PATH, 62, 4115.9893, -2814.3767, 207.18042, NULL, 0),
(@PATH, 63, 4116.2393, -2816.6267, 206.43042, NULL, 0),
(@PATH, 64, 4116.2393, -2818.3767, 205.93042, NULL, 0),
(@PATH, 65, 4116.2393, -2820.6267, 205.18042, NULL, 0),
(@PATH, 66, 4115.9893, -2823.3767, 204.18042, NULL, 0),
(@PATH, 67, 4115.9893, -2825.6267, 203.43042, NULL, 0),
(@PATH, 68, 4115.7393, -2828.1267, 202.93042, NULL, 0),
(@PATH, 69, 4115.7393, -2830.3767, 202.43042, NULL, 0),
(@PATH, 70, 4115.9893, -2832.8767, 202.18042, NULL, 0),
(@PATH, 71, 4115.9893, -2835.3767, 202.18042, NULL, 0),
(@PATH, 72, 4115.9893, -2837.3767, 201.68042, NULL, 0),
(@PATH, 73, 4115.9893, -2846.8767, 201.68042, NULL, 0),
(@PATH, 74, 4115.9893, -2858.6267, 201.68042, NULL, 0),
(@PATH, 75, 4115.7393, -2872.8767, 201.43042, NULL, 0),
(@PATH, 76, 4115.7393, -2886.3767, 201.68042, NULL, 0),
(@PATH, 77, 4115.9893, -2903.3767, 201.68042, NULL, 0),
(@PATH, 78, 4116.2393, -2925.1267, 201.68042, NULL, 0),
(@PATH, 79, 4115.9893, -2944.1267, 201.68042, NULL, 0),
(@PATH, 80, 4115.9893, -2966.6267, 201.43042, NULL, 0),
(@PATH, 81, 4115.9893, -2975.8767, 201.68042, NULL, 0),
(@PATH, 82, 4115.9893, -2978.3767, 201.68042, NULL, 0),
(@PATH, 83, 4115.7393, -2980.6267, 201.68042, NULL, 0),
(@PATH, 84, 4114.4893, -2982.6267, 201.68042, NULL, 0),
(@PATH, 85, 4111.9893, -2984.1267, 201.68042, NULL, 0),
(@PATH, 86, 4109.4893, -2984.6267, 201.68042, NULL, 0),
(@PATH, 87, 4107.2393, -2984.6267, 201.68042, NULL, 0),
(@PATH, 88, 4085.7393, -2984.6267, 201.68042, NULL, 0),
(@PATH, 89, 4070.9893, -2984.3767, 201.68042, NULL, 0),
(@PATH, 90, 4052.4893, -2984.3767, 201.68042, NULL, 0),
(@PATH, 91, 4033.7393, -2984.3767, 201.68042, NULL, 0),
(@PATH, 92, 4017.2393, -2984.3767, 201.93042, NULL, 0),
(@PATH, 93, 4002.7393, -2984.3767, 201.93042, NULL, 0),
(@PATH, 94, 3993.2393, -2984.3767, 201.93042, NULL, 0),
(@PATH, 95, 3980.7393, -2984.6267, 201.68042, NULL, 0),
(@PATH, 96, 3971.2393, -2984.3767, 201.68042, NULL, 0),
(@PATH, 97, 3958.9893, -2984.6267, 201.68042, NULL, 0),
(@PATH, 98, 3947.2393, -2984.6267, 201.68042, NULL, 0),
(@PATH, 99, 3932.9893, -2984.6267, 201.93042, NULL, 0),
(@PATH, 100, 3924.2393, -2984.3767, 201.68042, NULL, 0),
(@PATH, 101, 3912.1138, -2984.6875, 201.39113, NULL, 0);

SET @PATH := 214690 * 100;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Deephaul Ravine - Mine Cart - East');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3879.0408, -3149.059, 239.93472, NULL, 0),
(@PATH, 1, 3894.2908, -3149.059, 239.93472, NULL, 0),
(@PATH, 2, 3912.7908, -3149.309, 239.93472, NULL, 0),
(@PATH, 3, 3936.2908, -3149.309, 239.68472, NULL, 0),
(@PATH, 4, 3951.7908, -3149.559, 235.93472, NULL, 0),
(@PATH, 5, 3973.2908, -3149.559, 228.68472, NULL, 0),
(@PATH, 6, 3998.5408, -3149.559, 223.18472, NULL, 0),
(@PATH, 7, 4008.7908, -3149.309, 223.18472, NULL, 0),
(@PATH, 8, 4012.2908, -3147.059, 223.18472, NULL, 0),
(@PATH, 9, 4013.0408, -3127.059, 221.18472, NULL, 0),
(@PATH, 10, 4013.0408, -3107.309, 214.43472, NULL, 0),
(@PATH, 11, 4012.7908, -3087.309, 207.93472, NULL, 0),
(@PATH, 12, 4013.0408, -3062.559, 206.68472, NULL, 0),
(@PATH, 13, 4013.2908, -3048.059, 203.93472, NULL, 0),
(@PATH, 14, 4013.2908, -3014.809, 201.93472, NULL, 0),
(@PATH, 15, 4013.2908, -2989.059, 201.93472, NULL, 0),
(@PATH, 16, 4013.5408, -2942.809, 201.93472, NULL, 0),
(@PATH, 17, 4013.5408, -2926.309, 201.93472, NULL, 0),
(@PATH, 18, 4013.5408, -2917.309, 201.68472, NULL, 0),
(@PATH, 19, 4019.7908, -2915.309, 201.93472, NULL, 0),
(@PATH, 20, 4044.5408, -2915.809, 201.93472, NULL, 0),
(@PATH, 21, 4064.2908, -2915.059, 201.93472, NULL, 0),
(@PATH, 22, 4094.7908, -2915.559, 201.68472, NULL, 0),
(@PATH, 23, 4131.041, -2915.309, 201.93472, NULL, 0),
(@PATH, 24, 4168.791, -2915.809, 201.68472, NULL, 0),
(@PATH, 25, 4212.5815, -2915.1182, 201.57816, NULL, 0);

SET @PATH := 211153 * 100;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 50, 'Battleground Deephaul Ravine - Earthen Mine Cart Horde - Path 1');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3959.79, -3080.2102, 240.29422, NULL, 0);

SET @PATH := 211153 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Deephaul Ravine - Earthen Mine Cart Horde - Path 2');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3961.7886, -3077.5425, 241.08409, NULL, 0);

SET @PATH := 211153 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Deephaul Ravine - Earthen Mine Cart Horde - Path 3');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3959.867, -3080.2627, 240.68915, NULL, 0),
(@PATH, 1, 3952.617, -3088.2627, 240.68915, NULL, 0),
(@PATH, 2, 3945.867, -3089.2627, 240.68915, NULL, 0),
(@PATH, 3, 3927.367, -3075.2627, 240.68915, NULL, 0),
(@PATH, 4, 3920.867, -3077.2627, 240.68915, NULL, 0),
(@PATH, 5, 3914.867, -3087.5127, 240.68915, NULL, 0),
(@PATH, 6, 3921.9453, -3094.4827, 240.29422, NULL, 0);

SET @PATH := 211270 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 50, 'Battleground Deephaul Ravine - Earthen Mine Cart Alliance - Path 1');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4174.4663, -2807.8455, 240.14261, NULL, 0);

SET @PATH := 211270 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 25, 'Battleground Deephaul Ravine - Earthen Mine Cart Alliance - Path 2');

-- [0] IDx: 0
-- [0] Speed: 5000
-- [1] IDx: 1
-- [1] Speed: 2500
-- [2] IDx: 2
-- [2] Speed: 5000
DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4179.624, -2804.3325, 240.39261, NULL, 0),
(@PATH, 1, 4185.624, -2808.3325, 240.39261, NULL, 0),
(@PATH, 2, 4198.374, -2817.8325, 240.39261, NULL, 0),
(@PATH, 3, 4205.124, -2819.3325, 240.39261, NULL, 0),
(@PATH, 4, 4212.124, -2809.8325, 240.39261, NULL, 0),
(@PATH, 5, 4212.874, -2805.0825, 240.39261, NULL, 0), -- end of waypoint
(@PATH, 6, 4208.2812, -2800.8196, 240.14261, NULL, 0); -- point

SET @PATH := 224086 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 33, 'Battleground Deephaul Ravine - Foreman Uzjax - Path 1');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4188.4463, -2548.4219, 329.72302, NULL, 0),
(@PATH, 1, 4224.0947, -2565.5295, 326.40300, NULL, 0),
(@PATH, 2, 4246.4585, -2622.8090, 277.03200, NULL, 0),
(@PATH, 3, 4169.7476, -2693.5676, 299.68692, NULL, 0),
(@PATH, 4, 4149.9910, -2678.2048, 296.52530, NULL, 0),
(@PATH, 5, 4162.2915, -2577.9932, 279.36070, NULL, 0);

SET @PATH := 224086 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 96, 'Battleground Deephaul Ravine - Foreman Uzjax - Path 2');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4168.613, -2640.9011, 281.1842, NULL, 0),
(@PATH, 1, 4191.263, -2692.2258, 267.64813, NULL, 0),
(@PATH, 2, 4222.9976, -2729.1736, 263.76917, NULL, 0),
(@PATH, 3, 4231.6006, -2788.804, 265.68582, NULL, 0),
(@PATH, 4, 4207.4775, -2777.0261, 248.44023, NULL, 0);

SET @PATH := 224086 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 46, 'Battleground Deephaul Ravine - Foreman Uzjax - Path 3');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4169.778, -2842.4775, 255.24617, NULL, 0),
(@PATH, 1, 4146.7134, -2846.9705, 232.46617, NULL, 0),
(@PATH, 2, 4072.5947, -2843.8003, 207.92842, NULL, 0),
(@PATH, 3, 4033.808, -2895.0852, 212.79057, NULL, 0),
(@PATH, 4, 4044.6997, -2928.712, 228.9742, NULL, 0);

SET @PATH := 224086 * 100 + 3;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 75.5, 'Battleground Deephaul Ravine - Foreman Uzjax - Path 4');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3988.382, -2982.7466, 214.14328, NULL, 0),
(@PATH, 1, 3947.4392, -2951.6946, 240.32492, NULL, 0),
(@PATH, 2, 3925.5322, -2930.2517, 256.00693, NULL, 0),
(@PATH, 3, 3904.342, -2949.0608, 264.22525, NULL, 0),
(@PATH, 4, 3897.8916, -2981.356, 237.08006, NULL, 0),
(@PATH, 5, 3917.2778, -2984.9983, 218.29788, NULL, 0);

SET @PATH := 224087 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 38.8, 'Battleground Deephaul Ravine - Ruffious - Path 1');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4002.2283, -3361.882, 332.31503, NULL, 0),
(@PATH, 1, 4002.8665, -3316.3994, 328.91605, NULL, 0),
(@PATH, 2, 4022.6824, -3274.7986, 311.5371, NULL, 0),
(@PATH, 3, 3998.4011, -3233.3716, 296.26743, NULL, 0),
(@PATH, 4, 3973.8438, -3264.9307, 274.9113, NULL, 0),
(@PATH, 5, 3964.125, -3314.4531, 280.55475, NULL, 0);

SET @PATH := 224087 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 98.56, 'Battleground Deephaul Ravine - Ruffious - Path 2');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3960.322, -3256.4602, 286.95575, NULL, 0),
(@PATH, 1, 3936.6033, -3172.7744, 277.38278, NULL, 0),
(@PATH, 2, 3906.1562, -3144.1633, 264.19034, NULL, 0),
(@PATH, 3, 3913.6858, -3109.5815, 258.5746, NULL, 0),
(@PATH, 4, 3919.1042, -3119.9028, 245.78943, NULL, 0);

SET @PATH := 224087 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 35.32, 'Battleground Deephaul Ravine - Ruffious - Path 3');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3932.731, -3105.6633, 253.1566, NULL, 0),
(@PATH, 1, 3957.2883, -3035.4097, 232.8352, NULL, 0),
(@PATH, 2, 4014.341, -3071.4915, 219.23582, NULL, 0),
(@PATH, 3, 4110.386, -3021.5312, 217.72392, NULL, 0),
(@PATH, 4, 4084.6997, -2975.6667, 222.90218, NULL, 0);

SET @PATH := 224087 * 100 + 3;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 67.6, 'Battleground Deephaul Ravine - Ruffious - Path 4');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4143.3853, -2915.0364, 209.77501, NULL, 0),
(@PATH, 1, 4188.9844, -2952.1511, 240.86447, NULL, 0),
(@PATH, 2, 4228.529, -2972.8994, 255.17062, NULL, 0),
(@PATH, 3, 4262.8057, -2968.0295, 262.20547, NULL, 0),
(@PATH, 4, 4240.884, -2920.5208, 269.71332, NULL, 0),
(@PATH, 5, 4216.3003, -2915.2847, 220.86351, NULL, 0);
