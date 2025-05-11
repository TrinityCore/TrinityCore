DELETE FROM `creature_equip_template` WHERE `ID`=1 AND `CreatureID`= 240309;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(240309, 1, 73442, 0, 0, 0, 0, 0, 0, 0, 0, 60192); -- Wyrmrest Defender

DELETE FROM `creature_template_gossip` WHERE `CreatureID`=240309 AND `MenuID`=38508;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(240309, 38508, 60192); -- Wyrmrest Defender

SET @NPCTEXTID := 530008;
DELETE FROM `npc_text` WHERE `ID`= @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 284310, 0, 0, 0, 0, 0, 0, 0, 60192); -- 240309 (Wyrmrest Defender)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38508 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38508, @NPCTEXTID+0, 60192); -- 240309 (Wyrmrest Defender)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=38508 AND `OptionID` IN (3,1,0,2)) OR (`MenuID`=37143 AND `OptionID`=1);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38508, 132708, 3, 0, 'Gift of the Blue Dragonflight', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 1224930, NULL, 60192),
(37143, 132707, 1, 0, 'Activate Protocol Twilight.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 1224920, NULL, 60192),
(38508, 132710, 1, 0, 'Gift of the Bronze Dragonflight', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 1224928, NULL, 60192),
(38508, 132711, 0, 0, 'Gift of the Red Dragonflight', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 1224926, NULL, 60192),
(38508, 132709, 2, 0, 'Gift of the Green Dragonflight', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 1224932, NULL, 60192);

UPDATE `creature_template` SET `faction`=2041, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=240309; -- Wyrmrest Defender

DELETE FROM `gameobject_template` WHERE `entry`=525077;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(525077, 18, 2650, 'Protocol Twilight', '', '', '', 0.200000002980232238, 1, 1224921, 1224922, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60192); -- Protocol Twilight

UPDATE `gameobject_template` SET `Data0`=1, `Data1`=1224921, `Data2`=1224922, `VerifiedBuild`=60192 WHERE `entry`=494622; -- Protocol Inferno

-- The gameobject has been moved in a later patch
DELETE FROM `gameobject` WHERE `guid`= 3990004;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(3990004, 494621, 725, 5088, 5088, 2, 169, 0, 846.59375, 998.56768798828125, 317.42462158203125, 4.595711231231689453, 0, 0, -0.7471323013305664, 0.664675354957580566, 7200, 255, 1, 60192); -- Mysterious Elemental Device (Area: The Stonecore - Difficulty: 2) CreateObject2

