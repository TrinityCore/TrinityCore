DELETE FROM `gameobject_template` WHERE `entry` IN (254237 /*Portal to Dalaran - Broken Isles*/, 254168 /*Spoils of the Nightmare*/, 252003 /*Portal*/, 252006 /*Portal*/, 252043 /*Door*/, 252042 /*Door*/, 252004 /*Portal*/, 244921 /*Fertile Soil*/, 248002 /*Felwort*/, 251751 /*Treasure Chest*/, 251668 /*Treasure Chest*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(254237, 22, 8111, 'Portal to Dalaran - Broken Isles', '', '', '', 1, 224873, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Portal to Dalaran - Broken Isles
(254168, 3, 36470, 'Spoils of the Nightmare', 'openhand', '', '', 1.5, 1634, 67803, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 110, 0, 0, 0, 0, 1877, 0, 1, 0, 0, 0, 0, 2, 0, 22498), -- Spoils of the Nightmare
(252003, 10, 35705, 'Portal', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Portal
(252006, 10, 36949, 'Portal', '', '', '', 1.24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Portal
(252043, 0, 32552, 'Door', '', '', '', 3.3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Door
(252042, 0, 32552, 'Door', '', '', '', 4.56, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Door
(252004, 10, 36949, 'Portal', '', '', '', 1.11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Portal
(244921, 22, 25548, 'Fertile Soil', '', '', '', 0.5, 193802, -1, 0, 0, 0, 36318, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22498), -- Fertile Soil
(248002, 3, 32112, 'Felwort', '', '', '', 1.2, 29, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 46829, 110, 3, 0, 0, 0, 800, 800, 0, 193384, 0, 0, 0, 62242, 0, 0, 98, 22498), -- Felwort
(251751, 3, 33265, 'Treasure Chest', '', 'Opening', '', 1.5, 1744, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1470, 66930, 0, 0, 98, 22498), -- Treasure Chest
(251668, 3, 33265, 'Treasure Chest', '', 'Opening', '', 1.5, 1744, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1451, 66872, 0, 0, 98, 22498); -- Treasure Chest

UPDATE `gameobject_template` SET `VerifiedBuild`=22498 WHERE `entry`=218986; -- Sunreaver Onslaught Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=22498 WHERE `entry`=223229; -- Eternal Kiln
UPDATE `gameobject_template` SET `VerifiedBuild`=22498 WHERE `entry`=177280; -- Moonwell
UPDATE `gameobject_template` SET `VerifiedBuild`=22498 WHERE `entry`=194283; -- Thunder Bluff Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=22498 WHERE `entry`=184594; -- Portal to Shattrath

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=254168 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(254168, 0, 136413, 22498); -- Spoils of the Nightmare
