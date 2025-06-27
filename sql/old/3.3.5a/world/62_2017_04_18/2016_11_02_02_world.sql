-- 
DELETE FROM `gameobject_template` WHERE `entry` IN (4,129);
INSERT INTO `gameobject_template` (`entry`,  `type`,  `displayId`,  `name`,  `IconName`,  `castBarCaption`,  `unk1`,  `size`,  `Data0`,  `Data1`,  `Data2`,  `Data3`,  `Data4`,  `Data5`,  `Data6`,  `Data7`,  `Data8`,  `Data9`,  `Data10`,  `Data11`,  `Data12`,  `Data13`,  `Data14`,  `Data15`,  `Data16`,  `Data17`,  `Data18`,  `Data19`,  `Data20`,  `Data21`,  `Data22`,  `Data23`,  `AIName`,  `ScriptName`,  `VerifiedBuild`) VALUES
(4, 6, 0, "Bonfire Damage", "", "", "", 1, 0, 1, 3, 7902, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", 0),
(129, 6, 0, "Naxx Teleporter trap", "", "", "", 1, 0, 1, 0, 64446, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", 0);

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (4);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`) VALUES
(4, 14, 0, 0, 0);
