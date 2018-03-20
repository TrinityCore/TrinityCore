-- FULL `gameobject_loot_template` of Entry 271668
DELETE FROM `gameobject_loot_template` WHERE (Entry = 271668);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(271668, 151128, 0, 100, 1, 1, 0, 1, 1, ''),
(271668, 151127, 0, 100, 1, 1, 0, 1, 1, ''),
(271668, 151126, 0, 100, 1, 1, 0, 1, 1, '');

-- FULL `gameobject` of id 271668
DELETE FROM `gameobject` WHERE (guid = 21002276);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES
(21002276, 271668, 1669, 0, 0, 1, 0, 0, 5662.57, 9492.49, -67.1966, 2.59023, 0, 0, -0.96224, -0.272204, 300, 255, 1, 0, '', 0);

-- Table `gameobject_template`
UPDATE `gameobject_template` SET `type` = 3, `displayId` = 23883, `castBarCaption` = 'Opening', `Data0` = 57, `Data1` = 271668, `VerifiedBuild` = 19831 WHERE (entry = 271668);
