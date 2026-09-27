DELETE FROM `gameobject_template` WHERE `entry` IN (214612 /*Instance Portal (Party + Heroic)*/, 452403 /*Instance Portal (Raid 4 Difficulties)*/, 214611 /*Instance Portal (Raid 4 Difficulties)*/, 218654 /*Burning Seed*/, 208532 /*Forlorn Spire*/, 214613 /*Instance Portal (Raid 4 Difficulties)*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(214612, 31, 11469, 'Instance Portal (Party + Heroic)', '', '', '', 7, 1, 214, 215, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61820), -- Instance Portal (Party + Heroic)
(452403, 31, 74868, 'Instance Portal (Raid 4 Difficulties)', '', '', '', 5, 2, 216, 217, 216, 217, 83033, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Instance Portal (Raid 4 Difficulties)
(214611, 31, 11469, 'Instance Portal (Raid 4 Difficulties)', '', '', '', 5, 2, 216, 217, 216, 217, 11471, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61820), -- Instance Portal (Raid 4 Difficulties)
(218654, 3, 7918, 'Burning Seed', '', '', '', 0.100000001490116119, 1690, 46500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3622, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61820), -- Burning Seed
(208532, 33, 10555, 'Forlorn Spire', '', '', '', 1, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57564), -- Forlorn Spire
(214613, 31, 11469, 'Instance Portal (Raid 4 Difficulties)', '', '', '', 4, 2, 216, 217, 216, 217, 11471, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61820); -- Instance Portal (Raid 4 Difficulties)

UPDATE `gameobject_template` SET `displayId`=9790, `VerifiedBuild`=60192 WHERE `entry`=180859; -- Cluster Launcher
UPDATE `gameobject_template` SET `Data0`=85, `VerifiedBuild`=61820 WHERE `entry`=209128; -- Firelands Meeting Stone
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=58558 WHERE `entry`=209107; -- Anvil of Conflagration Portal
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=60192 WHERE `entry`=207358; -- Big Cauldron of Battle
UPDATE `gameobject_template` SET `Data1`=-1, `VerifiedBuild`=61820 WHERE `entry`=181621; -- Soulwell
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=60895 WHERE `entry`=203994; -- Doodad_StratholmeFloatingEmbers64
UPDATE `gameobject_template` SET `VerifiedBuild`=54647 WHERE `entry` IN (208379, 208378, 204245, 182667, 182670, 182671, 195365, 182668, 182669);
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=60895 WHERE `entry`=203995; -- Doodad_StratholmeFloatingEmbers66
UPDATE `gameobject_template` SET `Data22`=17483, `VerifiedBuild`=61820 WHERE `entry`=209874; -- Essence of Dreams
UPDATE `gameobject_template` SET `Data6`=0, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data15`=1, `Data20`=85, `VerifiedBuild`=60895 WHERE `entry`=208044; -- Cache of the Broodmother
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=61820 WHERE `entry`=191083; -- Demonic Circle: Summon
UPDATE `gameobject_template` SET `Data22`=17483, `VerifiedBuild`=61820 WHERE `entry`=209873; -- Gift of Life
UPDATE `gameobject_template` SET `Data22`=17483, `VerifiedBuild`=61820 WHERE `entry`=209875; -- Source of Magic
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=60895 WHERE `entry`=203991; -- Doodad_StratholmeFloatingEmbers61
UPDATE `gameobject_template` SET `castBarCaption`='Looting', `Data6`=0, `Data8`=29234, `Data14`=37733, `Data17`=131792, `VerifiedBuild`=58558 WHERE `entry`=209100; -- Branch of Nordrassil
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=60895 WHERE `entry`=207358; -- Big Cauldron of Battle

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (210217,209100));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(210217, 0, 78352, 61820), -- Elementium Fragment
(209100, 0, 69646, 58558); -- Branch of Nordrassil
