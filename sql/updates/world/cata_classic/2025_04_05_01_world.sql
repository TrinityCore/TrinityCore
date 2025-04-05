DELETE FROM `gameobject_template` WHERE `entry` IN (507509 /*Sha-Touched Tea Set*/, 445415 /*Instance Portal (Party + Heroic)*/, 445437 /*Instance Portal (Party + Heroic)*/, 445411 /*Instance Portal (Party + Heroic)*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(507509, 22, 100621, 'Sha-Touched Tea Set', '', '', '', 0.699999988079071044, 1216892, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59536), -- Sha-Touched Tea Set
(445415, 31, 74868, 'Instance Portal (Party + Heroic)', '', '', '', 5, 1, 214, 215, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59536), -- Instance Portal (Party + Heroic)
(445437, 31, 74868, 'Instance Portal (Party + Heroic)', '', '', '', 1.25, 1, 214, 215, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59536), -- Instance Portal (Party + Heroic)
(445411, 31, 74868, 'Instance Portal (Party + Heroic)', '', '', '', 3, 1, 214, 215, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59536); -- Instance Portal (Party + Heroic)

UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=59536 WHERE `entry`=175152; -- Doodad_OnyxiasGate01
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=59297 WHERE `entry`=175152; -- Doodad_OnyxiasGate01
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=59185 WHERE `entry`=175152; -- Doodad_OnyxiasGate01
