DELETE FROM `gameobject_template` WHERE `entry` IN (385414 /*Supply Crate*/, 209506 /*Stolen Treats*/, 209497 /*Stolen Treats*/, 209465 /*Greench Stash*/, 209474 /*Metzen Cage Post*/, 209473 /*Metzen Cage Segment*/, 405880 /*Forge*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(385414, 3, 6448, 'Supply Crate', '', '', '', 1, 57, 118469, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56713), -- Supply Crate
(209506, 10, 7678, 'Stolen Treats', '', '', '', 2, 1691, 6983, 0, 3000, 0, 0, 0, 0, 0, 0, 102781, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12758, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Stolen Treats
(209497, 10, 7678, 'Stolen Treats', '', '', '', 2, 1691, 7043, 0, 3000, 0, 0, 0, 0, 0, 0, 102781, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12758, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Stolen Treats
(209465, 5, 10808, 'Greench Stash', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Greench Stash
(209474, 5, 8380, 'Metzen Cage Post', '', '', '', 1.20000004768371582, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Metzen Cage Post
(209473, 5, 10813, 'Metzen Cage Segment', '', '', '', 1.20000004768371582, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158), -- Metzen Cage Segment
(405880, 8, 233, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58158); -- Forge

UPDATE `gameobject_template` SET `Data0`=61, `VerifiedBuild`=57294 WHERE `entry`=182558; -- Meeting Stone
UPDATE `gameobject_template` SET `Data0`=61, `VerifiedBuild`=57294 WHERE `entry`=182558; -- Meeting Stone
UPDATE `gameobject_template` SET `name`='Ezra Grimm\'s Premium Tobacco', `VerifiedBuild`=56713 WHERE `entry`=187590; -- Fras Siabi's Premium Tobacco
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=193978; -- Cask of Peaked Dalaran Red
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=56713 WHERE `entry`=193070; -- Nexus Raid Platform
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=187234; -- Tall/Thin Medium - Xmas
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=187234; -- Tall/Thin Medium - Xmas
UPDATE `gameobject_template` SET `Data0`=2061, `VerifiedBuild`=58158 WHERE `entry`=151951; -- Idol Oven Fire
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=187234; -- Tall/Thin Medium - Xmas
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=187234; -- Tall/Thin Medium - Xmas
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=187234; -- Tall/Thin Medium - Xmas
UPDATE `gameobject_template` SET `Data0`=80, `VerifiedBuild`=58158 WHERE `entry`=195013; -- Meeting Stone
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=187234; -- Tall/Thin Medium - Xmas
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=207205; -- Flames scale 0.05
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=207204; -- XMasStocking01 scale 0.5
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=207203; -- XMasGift02 scale 0.5
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=207202; -- XMasGift01 scale 0.5
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58158 WHERE `entry`=207201; -- Hobo Christmas Tree
UPDATE `gameobject_template` SET `type`=22, `Data0`=100523, `Data3`=1, `Data6`=1, `Data10`=0, `Data17`=0, `Data23`=0, `VerifiedBuild`=57564 WHERE `entry`=209038; -- Portal to Hyjal
UPDATE `gameobject_template` SET `Data0`=0, `VerifiedBuild`=56713 WHERE `entry`=193070; -- Nexus Raid Platform
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=56713 WHERE `entry`=182255; -- Wyvern Roost
UPDATE `gameobject_template` SET `Data0`=20, `VerifiedBuild`=56713 WHERE `entry`=178828; -- Meeting Stone

UPDATE `gameobject_template` SET `name`='Pip\'s Helm' WHERE `entry`=207331;

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=193597 AND `Idx` IN (2,1));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(193597, 2, 211207, 56713), -- Dark Runed Chest
(193597, 1, 211206, 56713); -- Dark Runed Chest

UPDATE `gameobject_questitem` SET `ItemId`=30525, `VerifiedBuild`=58158 WHERE (`Idx`=1 AND `GameObjectEntry` IN (184812,184814)); -- Sealed Coffin
UPDATE `gameobject_questitem` SET `ItemId`=30526, `VerifiedBuild`=58158 WHERE (`Idx`=1 AND `GameObjectEntry` IN (184811,184812,184813)); -- Sealed Coffin
