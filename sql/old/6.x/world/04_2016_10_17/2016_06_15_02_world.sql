--
SET @OGUID := 300915; -- set by TDB team (1)

DELETE FROM `gameobject_template` WHERE `entry`=244447;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `unkInt32`, `VerifiedBuild`) VALUES
(244447, 3, 3851, 'White Murloc Egg', '', '', '', 1, 1691, 62019, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20726); -- White Murloc Egg

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `PhaseID`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 244447, 571, 1, 0, 1462.983, 5422.067, 0.6317602, 4.443114, 0, 0, 0, 1, 5, 255, 1, 20726); -- White Murloc Egg (Area: Riplash Ruins)

DELETE FROM `gameobject_loot_template` WHERE `Entry`=244447;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(244447, 22780, 0, 100, 0, 1, 0, 1, 1, 'White Murloc Egg');
