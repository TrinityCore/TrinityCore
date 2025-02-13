DELETE FROM `gameobject_template` WHERE `entry` IN (377452 /*Campfire*/, 377441 /*Campfire*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(377452, 8, 8062, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Campfire
(377441, 8, 8062, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158); -- Campfire

UPDATE `gameobject_template` SET `castBarCaption`='Stealing', `Data6`=0, `Data14`=26365, `VerifiedBuild`=58558 WHERE `entry`=206786; -- Windspeaker Pylon
UPDATE `gameobject_template` SET `Data3`=1, `VerifiedBuild`=58158 WHERE `entry`=184605; -- Portal to Netherstorm
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192251; -- Argent Vanguard Support
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192250; -- Argent Vanguard Support
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192249; -- Argent Vanguard Tower
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192248; -- Argent Vanguard Tower
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192247; -- Argent Vanguard Tower
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192246; -- Argent Vanguard Tower
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192245; -- Argent Vanguard Support
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=58158 WHERE `entry`=192244; -- Argent Vanguard Support
UPDATE `gameobject_template` SET `Data0`=17334, `VerifiedBuild`=58158 WHERE `entry`=202357; -- Drakuru's Last Wish
UPDATE `gameobject_questitem` SET `ItemId`=30524 WHERE (`Idx`=1 AND `GameObjectEntry` IN (184814,184813));
UPDATE `gameobject_questitem` SET `ItemId`=30525 WHERE (`GameObjectEntry`=184812 AND `Idx`=1);
