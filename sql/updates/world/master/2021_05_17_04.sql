
DELETE FROM `areatrigger_template` WHERE `Id` IN (25543, 22316, 26169, 26205, 10801);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(25543, 1, 0, 0, 2, 2, 0, 0, 0, 0, 38134),
(22316, 1, 0, 4, 15, 15, 0, 0, 0, 0, 38134),
(26169, 1, 0, 0, 8, 8, 0, 0, 0, 0, 38134),
(26205, 1, 0, 0, 3, 3, 0, 0, 0, 0, 38134),
(10801, 1, 4, 0, 8, 8, 4, 4, 0.300000011920928955, 0.300000011920928955, 38134);


UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Flags`=1 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Type`=0, `Flags`=24, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0, `VerifiedBuild`=38134 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=0, `Flags`=24, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0, `VerifiedBuild`=38134 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `Type`=0, `Flags`=24, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0, `VerifiedBuild`=38134 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `Type`=0, `Flags`=24, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0, `VerifiedBuild`=38134 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=22173;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=3, `Data2`=3, `Data3`=2.5, `Data4`=3, `Data5`=3, `VerifiedBuild`=38134 WHERE `Id`=23820;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=6095;


REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(21565, 22316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 339781
(21993, 26169, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 38134), -- SpellId : 344546
(22037, 26205, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 38134); -- SpellId : 345078

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=21238 AND `AreaTriggerId`=25527); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=21238 AND `AreaTriggerId`=25527); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=21238 AND `AreaTriggerId`=25527); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=21238 AND `AreaTriggerId`=25527); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6783 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1878, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18184 AND `AreaTriggerId`=22316); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=19481 AND `AreaTriggerId`=23463); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=19481 AND `AreaTriggerId`=23463); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1060, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1098, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1098, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1098, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11997 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=22022 AND `AreaTriggerId`=26196); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18036 AND `AreaTriggerId`=22173); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20410 AND `AreaTriggerId`=24310); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=21269 AND `AreaTriggerId`=25556); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=21269 AND `AreaTriggerId`=25556); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=21269 AND `AreaTriggerId`=25556); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20531 AND `AreaTriggerId`=24417); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=21902 AND `AreaTriggerId`=26096); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=15999 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=748, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=22071 AND `AreaTriggerId`=26240); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=756, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=22071 AND `AreaTriggerId`=26240); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=19583 AND `AreaTriggerId`=23556); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=1000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19863 AND `AreaTriggerId`=23820); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6122 AND `AreaTriggerId`=10801); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=21902 AND `AreaTriggerId`=26096); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=19583 AND `AreaTriggerId`=23556); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6122 AND `AreaTriggerId`=10801); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=120000 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=120000 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6122 AND `AreaTriggerId`=10801); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6122 AND `AreaTriggerId`=10801); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=19897 AND `AreaTriggerId`=23847); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1972, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=1612 AND `AreaTriggerId`=6095); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7500 WHERE (`SpellMiscId`=21827 AND `AreaTriggerId`=26038); -- SpellId : 0



DELETE FROM `conversation_actor_template` WHERE `Id` IN (74118, 73735, 76712, 73916);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(74118, 167040, 95394, 38134),
(73735, 161907, 96443, 38134),
(76712, 158544, 95245, 38134),
(73916, 161985, 96138, 38134);


DELETE FROM `conversation_line_template` WHERE `Id` IN (34487, 35165, 39717, 41357, 40104, 34484, 40105, 35164, 35163, 35162, 35161, 41356, 39716);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(34487, 0, 1536, 0, 0, 38134),
(35165, 0, 0, 0, 0, 38134),
(39717, 0, 1372, 0, 0, 38134),
(41357, 0, 1554, 0, 0, 38134),
(40104, 0, 141, 0, 0, 38134),
(34484, 0, 1536, 0, 0, 38134),
(40105, 0, 141, 0, 0, 38134),
(35164, 18500, 0, 1, 0, 38134),
(35163, 11900, 0, 0, 0, 38134),
(35162, 2750, 0, 1, 0, 38134),
(35161, 0, 0, 0, 0, 38134),
(41356, 0, 1554, 0, 0, 38134),
(39716, 0, 1372, 0, 0, 38134);

UPDATE `conversation_line_template` SET `StartTime`=16000, `VerifiedBuild`=38134 WHERE `Id`=34910;
UPDATE `conversation_line_template` SET `StartTime`=11950, `VerifiedBuild`=38134 WHERE `Id`=34909;
UPDATE `conversation_line_template` SET `StartTime`=6150, `VerifiedBuild`=38134 WHERE `Id`=34895;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=34892;
UPDATE `conversation_line_template` SET `StartTime`=8900, `VerifiedBuild`=38134 WHERE `Id`=33571;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=33570;


UPDATE `conversation_template` SET `LastLineEndTime`=13400, `VerifiedBuild`=38134 WHERE `Id`=13494;
UPDATE `conversation_template` SET `LastLineEndTime`=18200, `VerifiedBuild`=38134 WHERE `Id`=13939;
UPDATE `conversation_template` SET `LastLineEndTime`=11200, `VerifiedBuild`=38134 WHERE `Id`=13603;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (338672 /*Madriguera de gorm*/, 352697 /*Semilla silvestre*/, 354925 /*Portal*/, 338622 /*Carro de cadáveres*/, 355040 /*Runa de rituales*/, 355048 /*Runa de rituales*/, 355038 /*Arca con vínculo rúnico*/, 355049 /*Runa de rituales*/, 357568 /*Resguardos y barreras mayores, volumen IV*/, 357567 /*Los caminos de los Primeros*/, 357566 /*Arcanum alado*/, 355980 /*Alijo de ritualista*/, 355979 /*Páginas de ritual*/, 358326 /*Polvo de amatista*/, 355051 /*Runa de rituales*/, 356366 /*Libro de rituales de vinculación*/, 364948 /*Bastón de runas de Sin'dane*/, 355073 /*Runa de rituales*/, 364945 /*Estandarte de Sin'dane*/, 364949 /*Conocimiento ligado a los exánimes*/, 364933 /*Círculo ritual*/, 355193 /*Runa de rituales*/, 339750 /*Huevo de oro*/, 358381 /*Arpa*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(338672, 0, 262148, 0, 0), -- Madriguera de gorm
(352697, 0, 262176, 0, 0), -- Semilla silvestre
(354925, 0, 1048608, 0, 0), -- Portal
(338622, 0, 32, 0, 0), -- Carro de cadáveres
(355040, 1375, 0, 0, 0), -- Runa de rituales
(355048, 1375, 0, 0, 0), -- Runa de rituales
(355038, 0, 0, 2437, 0), -- Arca con vínculo rúnico
(355049, 1375, 0, 0, 0), -- Runa de rituales
(357568, 0, 2113540, 0, 0), -- Resguardos y barreras mayores, volumen IV
(357567, 0, 2113540, 0, 0), -- Los caminos de los Primeros
(357566, 0, 2113540, 0, 0), -- Arcanum alado
(355980, 0, 2113536, 2437, 0), -- Alijo de ritualista
(355979, 0, 2113536, 2437, 0), -- Páginas de ritual
(358326, 0, 2113540, 0, 0), -- Polvo de amatista
(355051, 0, 262176, 0, 0), -- Runa de rituales
(356366, 0, 270337, 2437, 0), -- Libro de rituales de vinculación
(364948, 0, 262148, 0, 0), -- Bastón de runas de Sin'dane
(355073, 0, 262176, 0, 0), -- Runa de rituales
(364945, 0, 262148, 0, 0), -- Estandarte de Sin'dane
(364949, 0, 262149, 0, 0), -- Conocimiento ligado a los exánimes
(364933, 0, 0, 16714, 0), -- Círculo ritual
(355193, 0, 262176, 0, 0), -- Runa de rituales
(339750, 0, 2113540, 0, 0), -- Huevo de oro
(358381, 0, 1, 0, 0); -- Arpa

UPDATE `gameobject_template_addon` SET `flags`=33 WHERE `entry`=353815; -- Puerta
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=354128; -- Hacha arrojadiza maldraxxi
UPDATE `gameobject_template_addon` SET `faction`=3171 WHERE `entry`=35591; -- Corcho de pesca
UPDATE `gameobject_template_addon` SET `flags`=8193 WHERE `entry`=355375; -- Depósito de ánima volátil

DELETE FROM `creature_template_locale` WHERE (`locale`='esMX' AND `entry` IN (171697,170827,170819,175698,172631,175012,176308,173640,161846,172110,174776,169882,174606,174170,160501,168075,174139,174138,174131,174130,168076,170677,168032,174521,167505,167507,169860,169874,173380,173379,173378,173377,170790,175858,166180,164040,170206,164033,170442,169978,176021,169979,165910,163967,165603,170250,170227,169915,160074,170209,169913,170205,165907,170733,170730,169206,169210,172172,169205,165857,165855,171349,165164,160816,170902,158921,165159,166248,177513,162446,162434,160814,160813,158495,158494,160077,158487,166073,165157,164728,160817,171116,165162,165154,165155,160440,165156,173539,169400,165685,164923,164922,168620,168660,157885,157883,164802,171883,164872,176020,170768,164875,164874,169812,164924,164809,170769,170734,169803,170446,169136,159030,169169,172965,164700,159029,172838,172813,174395,174431,173582,174020,172606,160700,172922,173573,174435,172590,170779,174226,172591,173495,172609,172607,172567,173509,174377,173505,172604,172833,173563,173507,173564,173503,172556,172601,173433,172596,157952,174654,172589,172627,172557,167353,161907,173489,175022,169512,169190,169234,158442,158977,176219,175789,169863,161196,173045,159747,173046,159901,159750,159737,159714,159886,159852,159708,161249,168857,168859,161985,160917,175478,165214,173274,169699,169250,169249,160522,169395,169184,159916,159893,165376,169698,169521,168677,157517,157844,162732,174533,165566,164312,166186,162727,165549,165551,158032,165440,167040,158053,166370,158387,170095,165561,158566,158752,165473,168226,168440,172854,162937,170190,166663,159239,168148,172633,173994,168147,163224,172656,161599,158071,162899,166253,161597,162813,163824,163084,162816,166331,166534,166321,155654,166640,166545,166540,163043,163019,161585,161559,159833,175392,166400,163083,161710,159830,169795,166562,166552,160256,163032,162588,174652,169830,159689,164507,159824,159825,159822,159696,164508,164492,163041,158642,168216,175394,163030,166226,162477,175393,166570,166568,162872,161733,161697,164833,161696,166567,166565,173003,170542,169697,166564,166420,161712,161702,157540,166424,161757,169055,166421,162873,162853,170496,164997,166423,176024,173200,168196,175100,170191,169751,159856,176023,175097,175095,174653,174223,167435,162258,175021,157671,170971,167273,162259,161890,167747,167743,166908,169634,167355,167354,161881,156558,165017,173000,164221,160419,160418,165350,172173,167649,167645,165321,164667,174491,174488,174484,176400,156479,171242,174564,159200,158259,162880,167195,165701,156634,175519,170026,175579,174705,170045,175439,174729,169960,175054,175053,174731,174730,173906,174704,172815,172966,174713,172945,174837,172934,172723,165690,172722,172979,165901,176019,173106,174777,170039,166187,167503,174634,174633,174632,173766,169862,168513,161920,161917,161882,174631,175421,173899,173884,173862,174371,174365,174364,174362,173916,174570,174567,171397,164023,174569,174914,174613,174611,167193,174774,158556,174571,160292,158554,174568,158544,174572,174566,174565,165751,173681,158547,167527,174732,173682,175419,175418,173171,165550,158543,170034,174775,167206,165702,165659,174655,170033,176096,160481,174209,175417,161509,174610,174614,174835,170107,158555,175415,172400,167196,174608,168100,168116,164701,175413,158553,174609,160262,175414,160482));
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(171697, 'esMX', 'Pureza', NULL, NULL, NULL, 38134),
(170827, 'esMX', 'Barrera venari 04', NULL, NULL, NULL, 38134),
(170819, 'esMX', 'Barrera venari', NULL, NULL, NULL, 38134),
(175698, 'esMX', 'Alma condenada', 'Alma condenada', NULL, NULL, 38134),
(172631, 'esMX', 'Controlador 02: Devoradores de almas', NULL, NULL, NULL, 38134),
(175012, 'esMX', 'Ikras, el Devorador', NULL, NULL, NULL, 38134),
(176308, 'esMX', 'Punto de agarre', NULL, NULL, NULL, 38134),
(173640, 'esMX', 'Sabueso sombrío obediente', NULL, NULL, NULL, 38134),
(161846, 'esMX', 'Asesino', NULL, 'Inquisidor jurafauces', NULL, 38134),
(172110, 'esMX', 'Shan', NULL, NULL, NULL, 38134),
(174776, 'esMX', 'Aynnstykny', NULL, NULL, NULL, 38134),
(169882, 'esMX', 'Llevar semilla onírica al corazón', NULL, NULL, NULL, 38134),
(174606, 'esMX', 'Una voz incorpórea', NULL, NULL, NULL, 38134),
(174170, 'esMX', 'Acecho de las Fauces', NULL, NULL, NULL, 38134),
(160501, 'esMX', 'Ysera', NULL, NULL, NULL, 38134),
(168075, 'esMX', 'Lenro', NULL, 'Víveres', NULL, 38134),
(174139, 'esMX', 'Princesa Penicilia', NULL, NULL, NULL, 38134),
(174138, 'esMX', 'Guardia fúngica real', NULL, NULL, NULL, 38134),
(174131, 'esMX', 'Champibum', NULL, NULL, NULL, 38134),
(174130, 'esMX', 'Champifauces enloquecido', NULL, NULL, NULL, 38134),
(168076, 'esMX', 'Limonero', NULL, 'Comida y bebida', NULL, 38134),
(170677, 'esMX', 'Ostara', NULL, NULL, NULL, 38134),
(168032, 'esMX', 'Flwngyrr', NULL, 'Tabernera', NULL, 38134),
(174521, 'esMX', 'Gus', NULL, NULL, NULL, 38134),
(167505, 'esMX', 'Vigilante de nido alavelo', NULL, NULL, NULL, 38134),
(167507, 'esMX', 'Polluelo alavelo', NULL, NULL, NULL, 38134),
(169860, 'esMX', 'Pez', NULL, NULL, NULL, 38134),
(169874, 'esMX', 'Matriarca alavelo', NULL, NULL, NULL, 38134),
(173380, 'esMX', 'Brillitos', NULL, NULL, NULL, 38134),
(173379, 'esMX', 'Nariguja', NULL, NULL, NULL, 38134),
(173378, 'esMX', 'Cola astral', NULL, NULL, NULL, 38134),
(173377, 'esMX', 'Faryl', NULL, NULL, NULL, 38134),
(170790, 'esMX', 'Ave zancuda pacífica', NULL, NULL, NULL, 38134),
(175858, 'esMX', 'Ermitaña polvorienta', NULL, NULL, NULL, 38134),
(166180, 'esMX', 'Defensor de la arboleda', 'Defensora de la arboleda', 'Cazadores salvajes', NULL, 38134),
(164040, 'esMX', 'Gormulino madrinocturno', NULL, NULL, NULL, 38134),
(170206, 'esMX', 'Venado rúnico', NULL, NULL, NULL, 38134),
(164033, 'esMX', 'Matriarca madriscura', NULL, NULL, NULL, 38134),
(170442, 'esMX', 'Búho sombraluna', NULL, NULL, NULL, 38134),
(169978, 'esMX', 'Valvaperla', NULL, NULL, NULL, 38134),
(176021, 'esMX', 'Polilla estelar', NULL, NULL, NULL, 38134),
(169979, 'esMX', 'Polilla estelar', NULL, NULL, NULL, 38134),
(165910, 'esMX', 'Boggart nudorrama', NULL, NULL, NULL, 38134),
(163967, 'esMX', 'Asolador nudorrama', NULL, NULL, NULL, 38134),
(165603, 'esMX', 'Acechador invis', NULL, NULL, NULL, 38134),
(170250, 'esMX', 'Huevo de gorm', NULL, NULL, NULL, 38134),
(170227, 'esMX', 'Larva de gorm', NULL, NULL, NULL, 38134),
(169915, 'esMX', 'Acecharrunas', NULL, NULL, NULL, 38134),
(160074, 'esMX', 'Gorm rebanador', NULL, NULL, NULL, 38134),
(170209, 'esMX', 'Estelavispa', NULL, NULL, NULL, 38134),
(169913, 'esMX', 'Cachorro de acecharrunas', NULL, NULL, NULL, 38134),
(170205, 'esMX', 'Ciervorruna juvenil', NULL, NULL, NULL, 38134),
(165907, 'esMX', 'Venado rúnico', NULL, NULL, NULL, 38134),
(170733, 'esMX', 'Putriérnaga hinchada', NULL, NULL, NULL, 38134),
(170730, 'esMX', 'Polilla de Ardenweald marchita', NULL, NULL, NULL, 38134),
(169206, 'esMX', 'Hidra devoradora', NULL, NULL, NULL, 38134),
(169210, 'esMX', 'Cuidador de semilla silvestre', 'Cuidadora de semilla silvestre', NULL, NULL, 38134),
(172172, 'esMX', 'Spell Bunny', NULL, NULL, NULL, 38134),
(169205, 'esMX', 'Flor voraz', NULL, NULL, NULL, 38134),
(165857, 'esMX', 'Polilla estelar', NULL, NULL, NULL, 38134),
(165855, 'esMX', 'Rana lunar', NULL, NULL, NULL, 38134),
(171349, 'esMX', 'Estrellita', NULL, 'Cuidadora de la noche', NULL, 38134),
(165164, 'esMX', 'Lanra', NULL, 'Maestra de vuelo', NULL, 38134),
(160816, 'esMX', 'Rury', NULL, NULL, NULL, 38134),
(170902, 'esMX', 'Alma pacífica', NULL, NULL, NULL, 38134),
(158921, 'esMX', 'Guardiana Kota', NULL, 'Protectora de Tirna Vaal', NULL, 38134),
(165159, 'esMX', 'Alma de la naturaleza', 'Alma de la naturaleza', NULL, NULL, 38134),
(166248, 'esMX', 'Ermitaña solitaria', NULL, NULL, NULL, 38134),
(177513, 'esMX', 'Mor\'Kirk', NULL, NULL, NULL, 38134),
(162446, 'esMX', 'Nolon', NULL, 'Tabernero', NULL, 38134),
(162434, 'esMX', 'Alerín', NULL, 'Maestro de establos', NULL, 38134),
(160814, 'esMX', 'Chufa', NULL, NULL, NULL, 38134),
(160813, 'esMX', 'Buuwo', NULL, NULL, NULL, 38134),
(158495, 'esMX', 'Fandu\'lor', NULL, 'Víveres', NULL, 38134),
(158494, 'esMX', 'Anir', NULL, 'Objetos comerciables y reparaciones', NULL, 38134),
(160077, 'esMX', 'Gormulino salvaje', NULL, NULL, NULL, 38134),
(158487, 'esMX', 'Droman Tashmur', NULL, 'Corte de la Noche', NULL, 38134),
(166073, 'esMX', 'Polilla de Ardenweald superior', NULL, NULL, NULL, 38134),
(165157, 'esMX', 'Alma de la naturaleza', 'Alma de la naturaleza', NULL, NULL, 38134),
(164728, 'esMX', 'Evacuado de Arboleda de Duramen', 'Evacuada de Arboleda de Duramen', NULL, NULL, 38134),
(160817, 'esMX', 'Slanknen', NULL, NULL, NULL, 38134),
(171116, 'esMX', 'Alma pacífica', 'Alma pacífica', NULL, NULL, 38134),
(165162, 'esMX', 'Alma pacífica', NULL, NULL, NULL, 38134),
(165154, 'esMX', 'Protector de espíritus', 'Protectora de espíritus', NULL, NULL, 38134),
(165155, 'esMX', 'Protector de espíritus', 'Protectora de espíritus', NULL, NULL, 38134),
(160440, 'esMX', 'Brigdin', NULL, NULL, NULL, 38134),
(165156, 'esMX', 'Defensor de la arboleda', 'Defensora de la arboleda', NULL, NULL, 38134),
(173539, 'esMX', 'Spell Bunny', NULL, NULL, NULL, 38134),
(169400, 'esMX', 'Regresar al camino', NULL, NULL, NULL, 38134),
(165685, 'esMX', 'Pastador de la cañada', NULL, NULL, NULL, 38134),
(164923, 'esMX', 'Zorrito de las laderas', NULL, NULL, NULL, 38134),
(164922, 'esMX', 'Vulpino de las laderas', NULL, NULL, NULL, 38134),
(168620, 'esMX', 'Acechasombras famélico', NULL, NULL, NULL, 38134),
(168660, 'esMX', 'Alma de la naturaleza', NULL, NULL, NULL, 38134),
(157885, 'esMX', 'Vorkai poseído', 'Vorkai poseída', NULL, NULL, 38134),
(157883, 'esMX', 'Sylvar poseído', 'Sylvar poseída', NULL, NULL, 38134),
(164802, 'esMX', 'Gormulino invasivo', NULL, NULL, NULL, 38134),
(171883, 'esMX', 'Blanco de misil', NULL, NULL, NULL, 38134),
(164872, 'esMX', 'Saposcuro', NULL, NULL, NULL, 38134),
(176020, 'esMX', 'Larva de descomposición', NULL, NULL, NULL, 38134),
(170768, 'esMX', 'Putriérnaga hinchada', NULL, NULL, NULL, 38134),
(164875, 'esMX', 'Venado rúnico de ciénaga', NULL, NULL, NULL, 38134),
(164874, 'esMX', 'Ciervo de ciénaga juvenil', NULL, NULL, NULL, 38134),
(169812, 'esMX', 'Centinela convertido', 'Centinela convertida', NULL, NULL, 38134),
(164924, 'esMX', 'Alamarchita', NULL, NULL, NULL, 38134),
(164809, 'esMX', 'Putriérnaga', NULL, NULL, NULL, 38134),
(170769, 'esMX', 'Polilla de Ardenweald marchita', NULL, NULL, NULL, 38134),
(170734, 'esMX', 'Putriérnaga', NULL, NULL, NULL, 38134),
(169803, 'esMX', 'Feérico convertido', 'Feérica convertida', NULL, NULL, 38134),
(170446, 'esMX', 'Find Korenth Credit', NULL, NULL, NULL, 38134),
(169136, 'esMX', 'Spriggan acechador', NULL, NULL, NULL, 38134),
(159030, 'esMX', 'Venado rúnico', NULL, NULL, NULL, 38134),
(169169, 'esMX', 'Objetivo de hechizo', NULL, NULL, NULL, 38134),
(172965, 'esMX', 'Kill Credit: Night Lily Collected', NULL, NULL, NULL, 38134),
(164700, 'esMX', 'Rana lunar', NULL, NULL, NULL, 38134),
(159029, 'esMX', 'Ciervorruna juvenil', NULL, NULL, NULL, 38134),
(172838, 'esMX', 'Lar\'eye', NULL, 'Maestro lapidario', NULL, 38134),
(172813, 'esMX', 'Ton\'hamil', NULL, 'Guardián del círculo', NULL, 38134),
(174395, 'esMX', 'Raspamédulas', NULL, NULL, NULL, 38134),
(174431, 'esMX', 'Sastrona cautiva', NULL, NULL, NULL, 38134),
(173582, 'esMX', 'Mantarraya contagiada prófuga', NULL, NULL, NULL, 38134),
(174020, 'esMX', 'Capitán Prateq', NULL, NULL, NULL, 38134),
(172606, 'esMX', 'Coalescencia fatal', NULL, NULL, NULL, 38134),
(160700, 'esMX', 'Gato espectral', NULL, NULL, NULL, 38134),
(172922, 'esMX', 'Margravina Sin\'dane', NULL, NULL, NULL, 38134),
(173573, 'esMX', 'Óculo decrépito', NULL, NULL, NULL, 38134),
(174435, 'esMX', 'Muñeco de entrenamiento', NULL, NULL, NULL, 38134),
(172590, 'esMX', 'Campeón juraexánimes', NULL, NULL, NULL, 38134),
(170779, 'esMX', 'Contendiente de la arena', 'Contendiente de la arena', NULL, NULL, 38134),
(174226, 'esMX', 'Valdemar', NULL, NULL, NULL, 38134),
(172591, 'esMX', 'Mortisombra de Xantuth', NULL, NULL, NULL, 38134),
(173495, 'esMX', 'Karaxi la Desertora', NULL, NULL, NULL, 38134),
(172609, 'esMX', 'Mortisombra de Xantuth', NULL, NULL, NULL, 38134),
(172607, 'esMX', 'Mortisombra de Xantuth', NULL, NULL, NULL, 38134),
(172567, 'esMX', 'Mortisombra de Xantuth', NULL, NULL, NULL, 38134),
(173509, 'esMX', 'Tuetacánido animado', NULL, NULL, NULL, 38134),
(174377, 'esMX', 'Cor\'lat', NULL, NULL, NULL, 38134),
(173505, 'esMX', 'Qexu', NULL, NULL, NULL, 38134),
(172604, 'esMX', 'Guardahuesos animado', NULL, NULL, NULL, 38134),
(172833, 'esMX', 'Antare', NULL, NULL, NULL, 38134),
(173563, 'esMX', 'Tomo errante', NULL, NULL, NULL, 38134),
(173507, 'esMX', 'Nhaurra', NULL, NULL, NULL, 38134),
(173564, 'esMX', 'Pluma traviesa', NULL, NULL, NULL, 38134),
(173503, 'esMX', 'Acólito estudioso', 'Acólita estudiosa', NULL, NULL, 38134),
(172556, 'esMX', 'Oculus encantado', NULL, NULL, NULL, 38134),
(172601, 'esMX', 'Hechicero necrótico', 'Hechicera necrótica', NULL, NULL, 38134),
(173433, 'esMX', 'Acólita Nelesis', NULL, NULL, NULL, 38134),
(172596, 'esMX', 'Acólito necrótico', 'Acólita necrótica', NULL, NULL, 38134),
(157952, 'esMX', 'Acechador invisible: Esqueleto', NULL, NULL, NULL, 38134),
(174654, 'esMX', 'Filo de hechizo rebelde', NULL, NULL, NULL, 38134),
(172589, 'esMX', 'Centinela juraexánimes', 'Centinela juraexánimes', NULL, NULL, 38134),
(172627, 'esMX', 'Esclavo animado', 'Esclava animada', NULL, NULL, 38134),
(172557, 'esMX', 'Guardián juraexánimes', 'Guardiana juraexánimes', NULL, NULL, 38134),
(167353, 'esMX', 'Garra estridente', NULL, NULL, NULL, 38134),
(161907, 'esMX', 'Baronesa Draka', NULL, NULL, NULL, 38134),
(173489, 'esMX', 'Abominación cosida', NULL, NULL, NULL, 38134),
(175022, 'esMX', 'Arácnido sombrío', NULL, NULL, NULL, 38134),
(169512, 'esMX', 'Zángano putreaguijón', NULL, NULL, NULL, 38134),
(169190, 'esMX', 'Cerdo colmillo de hueso vengativo', NULL, NULL, NULL, 38134),
(169234, 'esMX', 'Cerdo colmillo de hueso', NULL, NULL, NULL, 38134),
(158442, 'esMX', 'Ácaro de tuétano', NULL, NULL, NULL, 38134),
(158977, 'esMX', 'Saqueador huesofundido', NULL, NULL, NULL, 38134),
(176219, 'esMX', 'Kearnen, la Espada', NULL, NULL, NULL, 38134),
(175789, 'esMX', 'Sombralúgubre', NULL, NULL, NULL, 38134),
(169863, 'esMX', 'Filacteria de exánime', NULL, NULL, NULL, 38134),
(161196, 'esMX', 'Arin\'gore', NULL, 'El inmortal', NULL, 38134),
(173045, 'esMX', 'Matriarca alaflagelada', NULL, NULL, NULL, 38134),
(159747, 'esMX', 'Reina pozamédula', NULL, NULL, NULL, 38134),
(173046, 'esMX', 'Vigilante de nido feroz', NULL, NULL, NULL, 38134),
(159901, 'esMX', 'Arañuelo tejehuesos', NULL, NULL, NULL, 38134),
(159750, 'esMX', 'Nido pozamédula', NULL, NULL, NULL, 38134),
(159737, 'esMX', 'Emboscadora tejehuesos', NULL, NULL, NULL, 38134),
(159714, 'esMX', 'Trepadora pozamédula', NULL, NULL, NULL, 38134),
(159886, 'esMX', 'Hermana Chelicerae', NULL, NULL, NULL, 38134),
(159852, 'esMX', 'Barrera de telaraña', NULL, NULL, NULL, 38134),
(159708, 'esMX', 'Glotona pozamédula', NULL, NULL, NULL, 38134),
(161249, 'esMX', 'Sombralúgubre', NULL, NULL, NULL, 38134),
(168857, 'esMX', 'Transportista alacosida', NULL, NULL, NULL, 38134),
(168859, 'esMX', 'Barril recuperado', NULL, NULL, NULL, 38134),
(161985, 'esMX', 'Baronesa Vashj', NULL, NULL, NULL, 38134),
(160917, 'esMX', 'Sombralúgubre', NULL, NULL, NULL, 38134),
(175478, 'esMX', 'Tauralus de manada', NULL, NULL, NULL, 38134),
(165214, 'esMX', 'Recuperador belicosido', NULL, NULL, NULL, 38134),
(173274, 'esMX', 'Bocaglotón', NULL, 'Experimento fallido', NULL, 38134),
(169699, 'esMX', 'Carroñero Bajard', NULL, 'Víveres', NULL, 38134),
(169250, 'esMX', 'Obrera putreaguijón', NULL, NULL, NULL, 38134),
(169249, 'esMX', 'Zángano putreaguijón', NULL, NULL, NULL, 38134),
(160522, 'esMX', 'Ojo remanente', 'Ojo remanente', NULL, NULL, 38134),
(169395, 'esMX', 'Baba descerebrada', NULL, NULL, NULL, 38134),
(169184, 'esMX', 'Cachorro de colmillo de hueso', NULL, NULL, NULL, 38134),
(159916, 'esMX', 'Arrasadora tejehuesos', NULL, NULL, NULL, 38134),
(159893, 'esMX', 'Oseadora Mimm', NULL, 'Suministros de herrería', NULL, 38134),
(165376, 'esMX', 'Oseador Tolvar', NULL, NULL, NULL, 38134),
(169698, 'esMX', 'Kere Hojahermana', NULL, 'Tabernera', NULL, 38134),
(169521, 'esMX', 'Aprendiz de gladiador', 'Aprendiza de gladiadora', NULL, NULL, 38134),
(168677, 'esMX', 'Colmillo de hueso carroñero', NULL, NULL, NULL, 38134),
(157517, 'esMX', 'Eliera \"ojos de mosca\"', NULL, 'Maestra de vuelo', NULL, 38134),
(157844, 'esMX', 'Messana', NULL, NULL, NULL, 38134),
(162732, 'esMX', 'Masa coagulante', NULL, NULL, NULL, 38134),
(174533, 'esMX', 'Arácnido desplazado', NULL, NULL, NULL, 38134),
(165566, 'esMX', 'Mortojo', NULL, NULL, NULL, 38134),
(164312, 'esMX', 'Alaflagelada con garfas', NULL, NULL, NULL, 38134),
(166186, 'esMX', 'Novata muerta', NULL, NULL, NULL, 38134),
(162727, 'esMX', 'Burbusangre', NULL, NULL, NULL, 38134),
(165549, 'esMX', 'Succión agria', NULL, NULL, NULL, 38134),
(165551, 'esMX', 'Piojo de cadáver succionante', NULL, NULL, NULL, 38134),
(158032, 'esMX', 'La Anatema', NULL, NULL, NULL, 38134),
(165440, 'esMX', 'Crecimiento fibroso', NULL, NULL, NULL, 38134),
(167040, 'esMX', 'Gran maestro Vole', NULL, NULL, NULL, 38134),
(158053, 'esMX', 'Madre de piojos de cadáver', NULL, NULL, NULL, 38134),
(166370, 'esMX', 'Madre del enjambre', NULL, NULL, NULL, 38134),
(158387, 'esMX', 'Avispón fétido', NULL, NULL, NULL, 38134),
(170095, 'esMX', 'Aprendiz de la arena', NULL, NULL, NULL, 38134),
(165561, 'esMX', 'Piojos de cadáver hinchados', NULL, NULL, NULL, 38134),
(158566, 'esMX', 'Engendro de piojo de cadáver', NULL, NULL, NULL, 38134),
(158752, 'esMX', 'Colmisangre depredador', NULL, NULL, NULL, 38134),
(165473, 'esMX', 'Colmisangre alfa', NULL, NULL, NULL, 38134),
(168226, 'esMX', 'Earl el ciego', NULL, 'Especialista en entregas', NULL, 38134),
(168440, 'esMX', 'Aprendiz de gladiador', 'Aprendiza de gladiadora', NULL, NULL, 38134),
(172854, 'esMX', 'Mayordomo dragador', NULL, NULL, NULL, 38134),
(162937, 'esMX', 'Señora Dyrax', NULL, 'Tutora demoníaca', NULL, 38134),
(170190, 'esMX', 'Tótem de agarre de las sombras', NULL, NULL, NULL, 38134),
(166663, 'esMX', 'Auxiliar', NULL, NULL, NULL, 38134),
(159239, 'esMX', 'Neena', NULL, NULL, NULL, 38134),
(168148, 'esMX', 'Drolkrad', NULL, NULL, NULL, 38134),
(172633, 'esMX', 'Acechador de volcán', NULL, NULL, NULL, 38134),
(173994, 'esMX', 'Voluntad de Remornia', NULL, NULL, NULL, 38134),
(168147, 'esMX', 'Sabriel, la Rajahuesos', NULL, NULL, NULL, 38134),
(163224, 'esMX', 'Arena - Bunny', NULL, NULL, NULL, 38134),
(172656, 'esMX', 'Acechador del centro de la arena', NULL, NULL, NULL, 38134),
(161599, 'esMX', 'Esclerosis burbujeante', NULL, NULL, NULL, 38134),
(158071, 'esMX', 'Animado descerebrado', NULL, NULL, NULL, 38134),
(162899, 'esMX', 'Gran maestro Vole', NULL, NULL, NULL, 38134),
(166253, 'esMX', 'Gran maestro Vole', NULL, NULL, NULL, 38134),
(161597, 'esMX', 'Baba arrasadora', NULL, NULL, NULL, 38134),
(162813, 'esMX', 'Aprendiz de la arena', 'Aprendiza de la arena', NULL, NULL, 38134),
(163824, 'esMX', 'Guardiana esquelética', NULL, NULL, NULL, 38134),
(163084, 'esMX', 'Examinadora Sahaari', NULL, 'Organizadora de encuentros', NULL, 38134),
(162816, 'esMX', 'Generic Bunny', NULL, NULL, NULL, 38134),
(166331, 'esMX', 'Zo\'umlo', NULL, 'Especialista en contención', NULL, 38134),
(166534, 'esMX', 'Ti\'or', NULL, NULL, NULL, 38134),
(166321, 'esMX', 'Proveedor de especímenes', NULL, NULL, NULL, 38134),
(155654, 'esMX', 'Spell Bunny', NULL, NULL, NULL, 38134),
(166640, 'esMX', 'Au\'larrynar', NULL, 'Mejoradores', NULL, 38134),
(166545, 'esMX', 'Instructor Erix', NULL, NULL, NULL, 38134),
(166540, 'esMX', 'Aprendiz incansable', 'Aprendiza incansable', NULL, NULL, 38134),
(163043, 'esMX', 'Espectadora de la arena', NULL, NULL, NULL, 38134),
(163019, 'esMX', 'Gran maestro Vole', NULL, NULL, NULL, 38134),
(161585, 'esMX', 'Huesos', NULL, NULL, NULL, 38134),
(161559, 'esMX', 'Louison', NULL, NULL, NULL, 38134);

INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(159833, 'esMX', 'So\'narynar', NULL, NULL, NULL, 38134),
(175392, 'esMX', 'Trampero Hickman', NULL, NULL, NULL, 38134),
(166400, 'esMX', 'Aprendiz incansable', 'Aprendiz incansable', NULL, NULL, 38134),
(163083, 'esMX', 'Evaluador Malus', NULL, 'Instructor de la arena', NULL, 38134),
(161710, 'esMX', 'Marcel Mullby', NULL, 'Víveres', NULL, 38134),
(159830, 'esMX', 'Au\'narim', NULL, 'Supervisor de apuestas', NULL, 38134),
(169795, 'esMX', 'Avispa cinérea zombi', NULL, NULL, NULL, 38134),
(166562, 'esMX', 'Talzedo', NULL, NULL, NULL, 38134),
(166552, 'esMX', 'Jessana', NULL, NULL, NULL, 38134),
(160256, 'esMX', 'Desguazadora Minoire', NULL, NULL, NULL, 38134),
(163032, 'esMX', 'Contendiente de la arena', 'Contendiente de la arena', NULL, NULL, 38134),
(162588, 'esMX', 'Picartílago', NULL, NULL, NULL, 38134),
(174652, 'esMX', 'Crúor animado', NULL, NULL, NULL, 38134),
(169830, 'esMX', 'Larva parasitaria', NULL, NULL, NULL, 38134),
(159689, 'esMX', 'Sobrestante Kalvaros', NULL, 'Coordinador de vuelo', NULL, 38134),
(164507, 'esMX', 'Espectador de la arena', 'Espectadora de la arena', NULL, NULL, 38134),
(159824, 'esMX', 'Gunn Tragahuesos', NULL, NULL, NULL, 38134),
(159825, 'esMX', 'Fan de Tragahuesos', NULL, NULL, NULL, 38134),
(159822, 'esMX', 'Fan de Dínamo', 'Fan de Dínamo', NULL, NULL, 38134),
(159696, 'esMX', 'Rencissa, la Dínamo', NULL, NULL, NULL, 38134),
(164508, 'esMX', 'Espectador de la arena', 'Espectadora de la arena', NULL, NULL, 38134),
(164492, 'esMX', 'Espectador de la arena', NULL, NULL, NULL, 38134),
(163041, 'esMX', 'Prospector de la arena', 'Prospectora de la arena', NULL, NULL, 38134),
(158642, 'esMX', 'Carne de alma podrida', NULL, NULL, NULL, 38134),
(168216, 'esMX', 'Ancestro chillavientos', NULL, NULL, NULL, 38134),
(175394, 'esMX', 'Ja\'red Haze', NULL, NULL, NULL, 38134),
(163030, 'esMX', 'Contendiente de la arena', NULL, NULL, NULL, 38134),
(166226, 'esMX', 'Contendiente de la arena', 'Contendiente de la arena', NULL, NULL, 38134),
(162477, 'esMX', 'Tauralus piel de sangre', NULL, NULL, NULL, 38134),
(175393, 'esMX', 'Eli\'ot Roush', NULL, NULL, NULL, 38134),
(166570, 'esMX', 'Avrilla Angar', NULL, 'Gerenta de conflicto', NULL, 38134),
(166568, 'esMX', 'Hellinka', NULL, 'Contendiente de arena', NULL, 38134),
(162872, 'esMX', 'Xantuth la Contagiada', NULL, NULL, NULL, 38134),
(161733, 'esMX', 'Anzio, el Infalible', NULL, 'Maestro de la arena', NULL, 38134),
(161697, 'esMX', 'Fogonero Marahueso', NULL, NULL, NULL, 38134),
(164833, 'esMX', 'Tauralus de manada', NULL, NULL, NULL, 38134),
(161696, 'esMX', 'Acerón Wilhelm', NULL, 'Forjador de armaduras de la arena', NULL, 38134),
(166567, 'esMX', 'Mímico', NULL, NULL, NULL, 38134),
(166565, 'esMX', 'Zandara', NULL, NULL, NULL, 38134),
(173003, 'esMX', 'Nalcorn Talsen', NULL, 'Intendente del Ejército Inmortal', NULL, 38134),
(170542, 'esMX', 'Duelistas veteranos', 'Duelistas veteranas', NULL, NULL, 38134),
(169697, 'esMX', 'Acerino Obernolte', NULL, 'Contrincante de arena', NULL, 38134),
(166564, 'esMX', 'Aprendiz incansable', 'Aprendiza incansable', NULL, NULL, 38134),
(166420, 'esMX', 'Varissa Stubin', NULL, 'Objetos comerciables', NULL, 38134),
(161712, 'esMX', 'Nana Gorrorojo', NULL, 'Maestro de establos', NULL, 38134),
(161702, 'esMX', 'Slumbar Valorum', NULL, 'Tabernero', NULL, 38134),
(157540, 'esMX', 'Guardián alado Alamar', NULL, 'Maestro de vuelo', NULL, 38134),
(166424, 'esMX', 'Obrero de la Arena', NULL, NULL, NULL, 38134),
(161757, 'esMX', 'Contendiente de la arena', 'Contendiente de la arena', NULL, NULL, 38134),
(169055, 'esMX', 'Raspamédulas', NULL, NULL, NULL, 38134),
(166421, 'esMX', 'Alaflagelada entrenado', NULL, NULL, NULL, 38134),
(162873, 'esMX', 'Azmogal', NULL, NULL, NULL, 38134),
(162853, 'esMX', 'Urtz el Irrompible', NULL, NULL, NULL, 38134),
(170496, 'esMX', 'Shanir Cortavenas', NULL, 'Contrincante de arena', NULL, 38134),
(164997, 'esMX', 'Pellizcador de cadáveres', NULL, NULL, NULL, 38134),
(166423, 'esMX', 'Alaflagelada entrenado', NULL, NULL, NULL, 38134),
(176024, 'esMX', 'Bucheciélago', NULL, NULL, NULL, 38134),
(173200, 'esMX', 'Arácnido sombrío', NULL, NULL, NULL, 38134),
(168196, 'esMX', 'Plaga virulenta', NULL, NULL, NULL, 38134),
(175100, 'esMX', 'Un cuerpo', NULL, NULL, NULL, 38134),
(170191, 'esMX', 'Espora fibrosa', NULL, NULL, NULL, 38134),
(169751, 'esMX', 'Avispa cinérea', NULL, NULL, NULL, 38134),
(159856, 'esMX', 'Peste virulenta', NULL, NULL, NULL, 38134),
(176023, 'esMX', 'Bucheciélago', NULL, NULL, NULL, 38134),
(175097, 'esMX', 'Corcel esquelético', NULL, NULL, NULL, 38134),
(175095, 'esMX', 'Gladiador arrasador', NULL, NULL, NULL, 38134),
(174653, 'esMX', 'Larva purulenta', NULL, NULL, NULL, 38134),
(174223, 'esMX', 'Gato con botas', NULL, NULL, NULL, 38134),
(167435, 'esMX', 'Tornado de huesos', NULL, NULL, NULL, 38134),
(162258, 'esMX', 'Chillavientos voraz', NULL, NULL, NULL, 38134),
(175021, 'esMX', 'Cresa pulsante', NULL, NULL, NULL, 38134),
(157671, 'esMX', 'Guardia de espadas supremo', 'Guardia de espadas suprema', NULL, NULL, 38134),
(170971, 'esMX', 'Tauralus listo para la batalla', NULL, NULL, NULL, 38134),
(167273, 'esMX', 'Tiradora certera de placas óseas', NULL, NULL, NULL, 38134),
(162259, 'esMX', 'Cría de chillavientos', NULL, NULL, NULL, 38134),
(161890, 'esMX', 'Carroñero carne sajada', NULL, NULL, NULL, 38134),
(167747, 'esMX', 'Aliya Jubón', NULL, NULL, NULL, 38134),
(167743, 'esMX', 'Vassili Tirolibre', NULL, NULL, NULL, 38134),
(166908, 'esMX', 'Malifis', NULL, 'Espectro de la ruina', NULL, 38134),
(169634, 'esMX', 'Veterano almapartida', NULL, NULL, NULL, 38134),
(167355, 'esMX', 'Cresa pulsante', NULL, NULL, NULL, 38134),
(167354, 'esMX', 'Rachis retorcido', NULL, NULL, NULL, 38134),
(161881, 'esMX', 'Espinacero herido', NULL, NULL, NULL, 38134),
(156558, 'esMX', 'Generic - Empty Bunny', NULL, NULL, NULL, 38134),
(165017, 'esMX', 'Inventor de plagas', 'Inventora de plagas', NULL, NULL, 38134),
(173000, 'esMX', 'Madeleine Roux', NULL, 'Ensayista de conflictos', NULL, 38134),
(164221, 'esMX', 'Kevin', NULL, NULL, NULL, 38134),
(160419, 'esMX', 'Limo', NULL, NULL, NULL, 38134),
(160418, 'esMX', 'Moc', NULL, NULL, NULL, 38134),
(165350, 'esMX', 'Lyra Granizormenta', NULL, NULL, NULL, 38134),
(172173, 'esMX', 'Intérprete de disputas', NULL, NULL, NULL, 38134),
(167649, 'esMX', 'Kresto Piromuerte', NULL, 'Cosmocartógrafo', NULL, 38134),
(167645, 'esMX', 'Jericó Murallada', NULL, 'Explotador de tácticas', NULL, 38134),
(165321, 'esMX', 'Merick Feldcicatriz', NULL, 'Comunicador', NULL, 38134),
(164667, 'esMX', 'Escudero supremo', 'Escudera suprema', NULL, NULL, 38134),
(174491, 'esMX', 'Probador de hierro', NULL, 'Muñeco tanque de asaltante', NULL, 38134),
(174488, 'esMX', 'Defensor inquebrantable', NULL, 'Muñeco de entrenamiento de asaltante', NULL, 38134),
(174484, 'esMX', 'Campeón inamovible', NULL, 'Muñeco de entrenamiento del combatiente de calabozo', NULL, 38134),
(176400, 'esMX', '|cFFFFFFFF|rNecrópolis: Zerekriss', NULL, NULL, NULL, 38134),
(156479, 'esMX', 'Guardián de la riqueza', NULL, 'Banquero', NULL, 38134),
(171242, 'esMX', 'Excavador hambriento', NULL, NULL, NULL, 38134),
(174564, 'esMX', 'Cuidador Kah-Rahm', NULL, 'Mano de la Árbitra', NULL, 38134),
(159200, 'esMX', 'Unidad', NULL, NULL, NULL, 38134),
(158259, 'esMX', 'Abominación', NULL, NULL, NULL, 38134),
(162880, 'esMX', 'Señora Dyrax', NULL, NULL, NULL, 38134),
(167195, 'esMX', 'Blodwyn', NULL, 'Enviada de la reina', NULL, 38134),
(165701, 'esMX', 'Ceridwyn', NULL, 'Maestra de vuelo', NULL, 38134),
(156634, 'esMX', 'Reina del invierno', NULL, NULL, NULL, 38134),
(175519, 'esMX', 'Pústula espumosa', NULL, NULL, NULL, 38134),
(170026, 'esMX', 'Nigromante novato', NULL, NULL, NULL, 38134),
(175579, 'esMX', 'Guardiana feérica', NULL, NULL, NULL, 38134),
(174705, 'esMX', 'Lord Amalthwyn', NULL, 'Guardián del despertar', NULL, 38134),
(170045, 'esMX', 'Dragador goteante', NULL, NULL, NULL, 38134),
(175439, 'esMX', 'Cazadora veterana', NULL, NULL, NULL, 38134),
(174729, 'esMX', 'Conquistador contagiado', NULL, NULL, NULL, 38134),
(169960, 'esMX', 'Llevar semilla onírica a la arboleda', NULL, NULL, NULL, 38134),
(175054, 'esMX', 'Defensor de la arboleda', 'Defensora de la arboleda', NULL, NULL, 38134),
(175053, 'esMX', 'Defensor de la arboleda', 'Defensora de la arboleda', 'Cazadores salvajes', NULL, 38134),
(174731, 'esMX', 'Cuidador de arboledas poseído', 'Cuidadora de arboledas poseída', NULL, NULL, 38134),
(174730, 'esMX', 'Trepador invasivo', NULL, NULL, NULL, 38134),
(173906, 'esMX', 'Alma pacífica', 'Alma pacífica', NULL, NULL, 38134),
(174704, 'esMX', 'Guardián pacífico', 'Guardiana pacífica', NULL, NULL, 38134),
(172815, 'esMX', 'Saltaestrellas', NULL, NULL, NULL, 38134),
(172966, 'esMX', 'Correbruma salvaje', NULL, NULL, NULL, 38134),
(174713, 'esMX', 'Alabrillo crepuscular', NULL, NULL, NULL, 38134),
(172945, 'esMX', 'Alabrillo del alba', NULL, NULL, NULL, 38134),
(174837, 'esMX', 'Acaparador de Bosquerruna', NULL, NULL, NULL, 38134),
(172934, 'esMX', 'Venado rúnico ramalvaje', NULL, NULL, NULL, 38134),
(172723, 'esMX', 'Vulpino cachorro de la arboleda', NULL, NULL, NULL, 38134),
(165690, 'esMX', 'Potro de la cañada', NULL, NULL, NULL, 38134),
(172722, 'esMX', 'Merodeador de la arboleda', NULL, NULL, NULL, 38134),
(172979, 'esMX', 'Esporeadora Almíbar', NULL, NULL, NULL, 38134),
(165901, 'esMX', 'Estelavispa', NULL, NULL, NULL, 38134),
(176019, 'esMX', 'Cachorro glauco', NULL, NULL, NULL, 38134),
(173106, 'esMX', 'Luciérnaga de del sotobosque', NULL, NULL, NULL, 38134),
(174777, 'esMX', 'Saltador frondavelada', NULL, NULL, NULL, 38134),
(170039, 'esMX', 'Polluela de auxiliar', NULL, NULL, NULL, 38134),
(166187, 'esMX', 'Venado rúnico', NULL, NULL, NULL, 38134),
(167503, 'esMX', 'Guardián alavelo', NULL, NULL, NULL, 38134),
(174634, 'esMX', 'Littlefield', NULL, NULL, NULL, 38134),
(174633, 'esMX', 'Zeke\'Tur', NULL, NULL, NULL, 38134),
(174632, 'esMX', 'Kimreed', NULL, NULL, NULL, 38134),
(173766, 'esMX', 'Polvoriento arrasador', NULL, NULL, NULL, 38134),
(169862, 'esMX', 'Croador reluciente', NULL, NULL, NULL, 38134),
(168513, 'esMX', 'Modeladora ancestral An\'wyn', NULL, 'Artesana del corazón', NULL, 38134),
(161920, 'esMX', 'Cachorro glauco', NULL, NULL, NULL, 38134),
(161917, 'esMX', 'Merodeador glauco', NULL, NULL, NULL, 38134),
(161882, 'esMX', 'Polilla de Ardenweald plácida', NULL, NULL, NULL, 38134),
(174631, 'esMX', 'Xan\'Shiells', NULL, 'Cazadores salvajes', NULL, 38134),
(175421, 'esMX', 'Cerdith', NULL, 'Protectora de espíritus', NULL, 38134),
(173899, 'esMX', 'Alma pacífica', 'Alma pacífica', NULL, NULL, 38134),
(173884, 'esMX', 'Alma pacífica', 'Alma pacífica', NULL, NULL, 38134),
(173862, 'esMX', 'Alma pacífica', 'Alma pacífica', NULL, NULL, 38134),
(174371, 'esMX', 'Mixy Mak', NULL, NULL, NULL, 38134),
(174365, 'esMX', 'Narciso', NULL, NULL, NULL, 38134),
(174364, 'esMX', 'Gwynceirw', NULL, 'El lobo invernal', NULL, 38134),
(174362, 'esMX', 'Estrujín', NULL, NULL, NULL, 38134),
(173916, 'esMX', 'Marasmius', NULL, NULL, NULL, 38134),
(174570, 'esMX', 'Muñeco de entrenamiento de enjambre', NULL, NULL, NULL, 38134),
(174567, 'esMX', 'Muñeco de entrenamiento de asaltante', NULL, NULL, NULL, 38134),
(171397, 'esMX', 'Forestal sylvari', NULL, 'Cazadores salvajes', NULL, 38134),
(164023, 'esMX', 'Vigía Carriflor', NULL, 'Cazadores salvajes', NULL, 38134),
(174569, 'esMX', 'Muñeco de entrenamiento', NULL, NULL, NULL, 38134),
(174914, 'esMX', 'Elwyn', NULL, 'Intendente de reconocimiento', NULL, 38134),
(174613, 'esMX', 'M\'Can', NULL, NULL, NULL, 38134),
(174611, 'esMX', 'Boles', NULL, NULL, NULL, 38134),
(167193, 'esMX', 'Plumaligera', NULL, 'Asistente de Baya Lunar', NULL, 38134),
(174774, 'esMX', 'Rahad', NULL, NULL, NULL, 38134),
(158556, 'esMX', 'Aithlyn', NULL, 'Intendente de los Cazadores salvajes', NULL, 38134),
(174571, 'esMX', 'Muñeco de entrenamiento de rajadura', NULL, NULL, NULL, 38134),
(160292, 'esMX', 'Kewarin', NULL, 'Tabernero', NULL, 38134),
(158554, 'esMX', 'Lafwyn', NULL, 'Reparaciones', NULL, 38134),
(174568, 'esMX', 'Muñeco de entrenamiento del combatiente de calabozo', NULL, NULL, NULL, 38134),
(158544, 'esMX', 'Lord Herne', NULL, 'Cazadores salvajes', NULL, 38134),
(174572, 'esMX', 'Lillyensthoom', NULL, 'La que entrena con sanadores', NULL, 38134),
(174566, 'esMX', 'Muñeco tanque del combatiente', NULL, NULL, NULL, 38134),
(174565, 'esMX', 'Muñeco tanque de asaltante', NULL, NULL, NULL, 38134),
(165751, 'esMX', 'Guardián', 'Guardiana', 'Cazadores salvajes', NULL, 38134),
(173681, 'esMX', 'Samn\'go', NULL, 'Cazadores salvajes', NULL, 38134),
(158547, 'esMX', 'Guardián', 'Guardiana', 'Cazadores salvajes', NULL, 38134),
(167527, 'esMX', 'Oranomonos, la Enramada', NULL, NULL, NULL, 38134),
(174732, 'esMX', 'Ingra Krazic', NULL, NULL, NULL, 38134),
(173682, 'esMX', 'Dor\'levgoren', NULL, 'Cazadores salvajes', NULL, 38134),
(175419, 'esMX', 'Maestra artesana Lamda', NULL, 'Mejora de objetos', NULL, 38134),
(175418, 'esMX', 'Mar\'lan', NULL, 'Comerciante de armaduras noctifeérico', NULL, 38134),
(173171, 'esMX', 'Viverista Noche Estrellada', NULL, 'Vivero de la Reina', NULL, 38134),
(165550, 'esMX', 'Asistente alabrillante', NULL, 'Personal de la cámara de audiencias de la reina', NULL, 38134),
(158543, 'esMX', 'Asistente Rociolux', NULL, 'Personal de la cámara de audiencias de la reina', NULL, 38134),
(170034, 'esMX', 'Karras', NULL, NULL, NULL, 38134),
(174775, 'esMX', 'Ofer', NULL, NULL, NULL, 38134),
(167206, 'esMX', 'Yanlar', NULL, 'Cazadores salvajes', NULL, 38134),
(165702, 'esMX', 'Zayhad, la constructora', NULL, 'Mejoras de sagrario', NULL, 38134),
(165659, 'esMX', 'Capitana de los Cazadores Korayn', NULL, 'Cazadores salvajes', NULL, 38134),
(174655, 'esMX', 'Artesano feérico', 'Artesana feérica', NULL, NULL, 38134),
(170033, 'esMX', 'Aprendiz vorkai', NULL, NULL, NULL, 38134),
(176096, 'esMX', 'Laurel', NULL, 'Guardiana de reconocimiento', NULL, 38134),
(160481, 'esMX', 'Niya', NULL, NULL, NULL, 38134),
(174209, 'esMX', 'Lady Muunn', NULL, 'Recuerdo de las formas', NULL, 38134),
(175417, 'esMX', 'Sulanoom', NULL, 'Forjadora de armas nathriana mítica', NULL, 38134),
(161509, 'esMX', 'Lady Baya Lunar', NULL, 'Corte de la Noche', NULL, 38134),
(174610, 'esMX', 'R\'chll', NULL, NULL, NULL, 38134),
(174614, 'esMX', 'Ka\'ruth', NULL, NULL, NULL, 38134),
(174835, 'esMX', 'Acaparadora veteada', NULL, NULL, NULL, 38134),
(170107, 'esMX', 'Ir al Corazón del Bosque', NULL, NULL, NULL, 38134),
(158555, 'esMX', 'Guardia de la reina de élite', 'Guardia de la reina de élite', 'Cazadores salvajes', NULL, 38134),
(175415, 'esMX', 'Harkoth', NULL, 'Forjador de armas nathriano heroico', NULL, 38134),
(172400, 'esMX', 'Mesa de comando', NULL, NULL, NULL, 38134),
(167196, 'esMX', 'Sesselie', NULL, 'Cuyas raíces tocan el ánima', NULL, 38134),
(174608, 'esMX', 'Chispa', NULL, NULL, NULL, 38134),
(168100, 'esMX', 'Cortesano feérico', 'Cortesana feérica', NULL, NULL, 38134),
(168116, 'esMX', 'Cortesano feérico', 'Cortesana feérica', NULL, NULL, 38134),
(164701, 'esMX', 'Polilla estelar', NULL, NULL, NULL, 38134),
(175413, 'esMX', 'Brisaluciente', NULL, 'Forjador de armas nathriano de buscador de bandas', NULL, 38134),
(158553, 'esMX', 'Mapirosa', NULL, 'Celadora de almas', NULL, 38134),
(174609, 'esMX', 'Zaki', NULL, NULL, NULL, 38134),
(160262, 'esMX', 'Ysera', NULL, NULL, NULL, 38134),
(175414, 'esMX', 'Adera', NULL, 'Forjadora de armas nathriana normal', NULL, 38134),
(160482, 'esMX', 'Tejesueños', NULL, NULL, NULL, 38134);

UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=90212 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150357 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=75065 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=417 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=71655 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136402 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=98035 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=55659 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=58964 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=95061 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=61029 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=78116 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=93008 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=158637 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=29238 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=62822 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=62821 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143622 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=34337 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=58965 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=58960 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=3527 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132366 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=127956 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=31216 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=79205 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=81670 AND `locale`='esMX');

DELETE FROM `quest_template_locale` WHERE (`locale`='esMX' AND `ID` IN (57531,60458,60256,60250,62055,62054,60498,60460,60640,60276,60459,62866,62217,62194,61511,60765,60429,60402,60291,60237,58525,58095,63073,62899,62900,61550,61542,63008,61541,62898,62897,62894,62837,60289,61355,60287,62882,62893,62892,62891,62890,60623,61549,57443,61603,61787,61867,61883,61949,60786,60655,59743,59826,58221,59642,61631,60911,60858,60457,63346,61331,60388));
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(57531, 'esMX', 'Una situación desafortunada', 'Derrota a Costel y recupera las pertenencias de Laurent.', 'Laurent, fabricante de espejos del amo. Un placer conocerte. Disculpa mi aspecto desaliñado. Parece que estoy en una situación desafortunada. \n\nIntentaba viajar por asuntos reales cuando mi espejo me envió a este páramo.\n\nApenas un momento después de que llegué, un grupo de exiliados me arrancó la ropa, y por eso es imposible que pueda viajar por estas tierras crueles.\n\nAyúdame a crear un espejo que nos permita escapar de este lugar maldito.', '', 'Un ladrón conocido que tiene vínculos con El Asilo de los Amortajados.', 'Costel', '', '', '', 38134),
(60458, 'esMX', 'Rescate de ánima', 'Reúne 150 ascuas de ánima de Torghast, la Torre de los Condenados.', 'Cuando llevamos las almas a la Árbitra, jamás creímos que esto podía llegar a ocurrir. Veíamos con desesperación cómo las arrojaban a las Fauces, una por una, y luego de a cientos y miles.\n\nLas almas devoradas, consumidas, y su ánima, perdida para nosotros. Tráenos de vuelta lo que puedas.', '', '', '', '', '', '', 38134),
(60256, 'esMX', 'Un hallazgo importante: Salones de Expiación', 'Consigue el orbe dorado de energía del Lord Chambelán en los Salones de Expiación.', 'La aristocracia de Revendreth está acostumbrada a los espectáculos lujosos e invaluables, pero casi nunca nos incluyen a nosotros. A menudo viajan con uno o dos distintivos en sus atuendos para destacar su posición.\n\nAhora, muchos de los suyos se han aliado con sir Denathrius en contra de los habitantes de las Tierras de las Sombras. Desde luego, hay que detenerlo. \n\nNo hay opción.\n\nPero si además de encargarte de eso les quitas algunas de esas posesiones, con mucho gusto comerciaré contigo.', '', '', '', '', '', '', 38134),
(60250, 'esMX', 'Un hallazgo importante: Teatro del Dolor', 'Consigue el anillo de metal de otro mundo de Mordretha en el Teatro del Dolor.', 'El Teatro del Dolor de Maldraxxus es un lugar brutal, donde solo sobreviven los más fuertes. \n\nCon las casas en una competencia tan feroz entre sí, se considera que es motivo de gran orgullo para la casa tener un campeón con un historial de victorias.\n\nPor eso, los señores de las casas suelen vestir a los competidores con armas, armaduras y abalorios de gran poderío. Con frecuencia son objetos de renombre que han pasado por muchas batallas.\n\nMe gustaría mucho ver un objeto así.', '', '', '', '', '', '', 38134),
(62055, 'esMX', 'Castillo Nathria: Una cabeza de ventaja', 'Recoge la cabeza de Fangopuño 4 veces en el Castillo Nathria en dificultad heroica.', 'Tenemos que demostrarle a Denathrius que hablamos en serio. Su dragador... esa mascota... bastará.\n\nTráeme su cabeza. Cuatro veces serán suficientes. Los dragadores son criaturas curiosas.', '', '', '', '', '', '', 38134),
(62054, 'esMX', 'Castillo Nathria: Una cabeza de ventaja', 'Recoge la cabeza de Fangopuño 4 veces en el Castillo Nathria en dificultad normal.', 'Tenemos que demostrarle a Denathrius que hablamos en serio. Su dragador... esa mascota... bastará.\n\nTráeme su cabeza. Cuatro veces serán suficientes. Los dragadores son criaturas curiosas.', '', '', '', '', '', '', 38134),
(60498, 'esMX', 'Una prueba por delante', 'Derrota a Kalisthene en la Senda de Ascensión.', 'Estos nuevos escarpines pueden darle a Pelagos la ventaja que necesita para derrotar a Kalisthene.\n\nVuelve a la Senda, $n. Equipa a Pelagos con estos escarpines y derroten a su oponente.\n\nPuede que les lleve más de un intento, pero así suelen ser las pruebas.\n\nVive para servir. ¡Y busca la gloria!', '', '', '', '', '', '', 38134),
(60460, 'esMX', 'Rescate de ánima', 'Reúne 150 ascuas de ánima de Torghast, la Torre de los Condenados.', 'Revendreth no es el destino más deseado para las almas, pero es el destino que se merecen. Aquí, sus pecados se exponen ante todos, y sus almas se quebrantan y adquieren una nueva forma útil para nuestra sociedad.\n\nEs una parte necesaria del ciclo.\n\nY sin embargo, ahora el ciclo se ha roto y no pueden servir a nuestro gran propósito.\n\nPara poder hacer nuestro trabajo, necesitamos ánima. Viaja a Torghast, Surcafauces, y busca aquello que no podemos buscar nosotros. Sin eso, nos marchitamos y desaparecemos.', '', '', '', '', '', '', 38134),
(60640, 'esMX', 'El renacer de la arboleda', 'Mejora el Vivero de la Reina a nivel 3.', 'La arboleda florece, mi $gquerido:querida; mortal, pero todavía puede crecer más.\n\nCon suficiente ánima, puede alimentar a aún más semillas silvestres a la vez. Cada una es un espíritu que de otra forma podría perderse para siempre.\n\nVuelve a hablar con Zayhad y encárgate de que el vivero vuelva a crecer.', '', '', '', '', '', '', 38134),
(60276, 'esMX', 'SE BUSCA: Invocador Marcelis', 'Busca y mata al invocador Marcelis.', 'Atención:\n\nEl invocador Marcelis y sus seguidores emplean magias peligrosas. Invocan elementales cinéreos para arrasar con estas tierras abrasadas por la Luz. \n\nNo podemos permitir que estos actos continúen. \n\nSe solicita a todo el que pueda que ponga fin a esta esté locura. \n\n- Despachante Raluca', '', 'Invoca elementales en algún lugar desde las sombras.', 'Invocador Marcelis', '', '', 'Habla con la despachante Raluca.', 38134),
(60459, 'esMX', 'Rescate de ánima', 'Reúne 150 ascuas de ánima de Torghast, la Torre de los Condenados.', 'La Árbitra nos ha provocado una gran ofensa. Nuestros ejércitos se reducen debido a que las almas van a las Fauces en lugar de ocupar su lugar en Maldraxxus.\n\nEl Ejército Inmortal no desaparecerá. Para que las Tierras de las Sombras sobrevivan, debemos darles suministros a nuestras filas.\n\nVe a las Fauces, Surcafauces, e ingresa a Torghast. Regresa con las ascuas de ánima para ayudar a encender nuestros suministros.', '', '', '', '', '', '', 38134),
(62866, 'esMX', 'La salvación de las almas perdidas', 'Rescata almas en las Fauces.', 'Surcafauces, imagino que has visto con tus propios ojos las almas que siguen cayendo en las Fauces. \n\nTenemos que hacer algo rápido para recuperar todas las almas que podamos y quitarle poder al Carcelero. Ese poder les pertenece a los necroseñores.\n\nTe ayudaré a salvar estas almas para que luego podamos encontrarles un sitio en los ejércitos de Maldraxxus.\n\nVuelve a las Fauces y rescata a todas las que puedas.', '', '', '', '', '', '', 38134),
(62217, 'esMX', 'Entrenamiento de campo', 'Elimina $2oa fuerzas de los Rechazados en La Forja Eterna de Bastión.', 'Maldraxxus ha infligido una gran injusticia a los kyrian de Bastión, aunque no hayamos sido artífices de esos actos. Debemos hacer todo lo posible por enmendarlo.\n\nLos jurafauces siguen siendo una amenaza para ellos. Creo que es la oportunidad perfecta para mostrar nuestro apoyo y para que nuestros reclutas adquieran experiencia en combate.', '', '', '', '', '', '', 38134),
(62194, 'esMX', 'Palabras contendientes', 'Ayuda a Sabrina a recoger $2oa enseñanzas ancestrales y elimina $3oa enemigos rechazados.', 'A lo largo y a lo ancho de la Tierra de las Sombras hay mucha magia que aprender.\n\nUna amenaza contra Bastión ha puesto muchas de las enseñanzas ancestrales en peligro. Deseo estudiar los pergaminos antes de que se pierdan para siempre. ¡Debemos viajar ahí y resguardar todo lo que podamos!\n\nAyúdame a enfrentar a los Rechazados en el Templo de la Humildad y salvar los pergaminos que guarda.', '', '', '', '', '', '', 38134),
(61511, 'esMX', 'Lo que nos han dejado', 'Usa a Coqui para ubicar y recolectar $2oa restos valiosos en Revendreth.', 'Coqui está aburrido. ¡Coqui quiere embarcarse en una aventura! ¿Tú también?\n\nLas personas pálidas en edificios altos tienen muchos objetos brillantes y grisgrises. ¡Iremos ahí y buscaremos algunos para nosotros!\n\n¿Estás $Glisto:lista; para partir?', '', '', '', '', '', '', 38134),
(60765, 'esMX', 'La cura de todos los males', 'Usa la muda regenerativa de Hervoria para curar a $2oa sobrevivientes apestados.', 'Muchos sobrevivientes de la Casa de las Plagas aún necesitan ayuda. Su sufrimiento me llena de tristeza.\n\nSurcafauces, haría lo que fuera para ayudarlos. Aunque salvemos solo a unos pocos, será mejor que no hacer nada.\n\n¡Por favor, ayúdame a curarlos!', '', '', '', '', '', '', 38134),
(60429, 'esMX', 'Problemas en casa', 'Completa misiones diarias y misiones de mundo, despoja tesoros y mata criaturas raras para defender Maldraxxus. También puedes derrotar enemigos poderosos en los calabozos Plaga Abrumadora y Teatro del Dolor.', '¡Mira! ¡Mira a tu alrededor! Donde sea que mires, los enemigos esperan la mano aplastante de la victoria.\n\nHay una alteración en el equilibrio de poder, y por eso, los defensores de las Tierras de las Sombras están debilitados.\n\n¡La única cura es más combate!\n\nDesafía a las casas que buscaban perjudicar a Maldraxxus y oblígalos a humillarse bajo el peso de tus botas.', '', '', '', '', '', '', 38134),
(60402, 'esMX', 'Entrenamiento en Ardenweald', 'Completa 3 misiones de mundo en Ardenweald con tu aprendiz.', '¡Mira esto! Todos puro huesos y cartílago. Necesitan un poco de carne en el esqueleto y entrenamiento en la cabeza.\n\nLleva este aprendiz para que tenga un poco de experiencia real de combate.\n\nArdenweald es un buen lugar, lleno de cosas que combatir. Que aprenda tácticas nuevas, se acostumbre al caos de la batalla, esas cosas.', '', '', '', '', '', '', 38134),
(60291, 'esMX', 'Traslado de cadáveres', 'Devuelve la carcasa de hueso a Rathan en el Bloque del Carnicero.', 'Hay trabajo que hacer por aquí. Mmm, mmm...\n\nVi una enorme y fantástica carcasa aquí cerca. Mi objetivo es desarmarla y quedarme con algunas partes. \n\nPodrías venir y ayudarme a llevársela a Rathan. A él le gustaría. Mmm, mmm... \n\nCreo que hasta podría llevarte a cuestas ida y vuelta. No eres grande.\n\n¿Estás $glisto:lista; para nuestra aventura?', '', '', '', '', '', '', 38134),
(60237, 'esMX', 'Terrenos pisoteados', 'Recoge $2oa bellotas de ánima perdidas. Usa el Sacudemundos de Mondadientes para desenterrarlas.', 'Una vez, hace mucho tiempo, fui al reino de Ardenweald para asistir en la destrucción de una amenaza ya olvidada.\n\nMientras estuve allí, recuerdo haber visto pequeñas criaturas que tomaban diminutos cúmulos de ánima, que los feéricos llamaban bellotas de ánima, y los ocultaban bajo tierra.\n\nSi esos cúmulos todavía están allí, ¡deberíamos desenterrarlos y aprovecharlos!\n\nSeguramente podré desenterrar todas las bellotas de ánima que encontremos. ¡Es hora de salir de cacería!', '', '', '', '', '', '', 38134),
(58525, 'esMX', 'Los dos lados de la historia', 'Busca ejemplares de \"En hueso y piedra\" y \"La malicia de Maldraxxus\".', 'Los mortales como tú siempre dicen que la historia la escriben los ganadores. Pero en las Tierras de las Sombras descubrí que eso no es cierto.\n\nTodos tienen su propia versión de los acontecimientos. Quisiera conocerlas todas. \n\nHabía una autora de libros de historia que se instaló en la Torre Caída Oscura de Revendreth. Escribió desde la perspectiva de los venthyr acerca de diversas incursiones y batallas junto al Primus. Si pudiéramos encontrar ejemplares de su obra...', '', '', '', '', '', '', 38134),
(58095, 'esMX', 'Teatro del Dolor: Se busca ayuda', 'Entra al calabozo del Teatro del Dolor y vence a los campeones.', 'Uf, qué problema. La campeona exánime se ha retirado del concurso.\n\nBueno, entonces... ¡parece que hay una vacante! ¿Alguien querría entrar en su lugar?\n\n¿Quizás para aumentar las probabilidades de su casa?\n\n¿Nadie?\n\n¡Ah, $n! Qué amable eres en presentarte como $gvoluntario:voluntaria;. ¡No hay mejor manera de conseguir experiencia que saltar a la acción sin ningún tipo de preparación!\n\nRecuerda que no todos podemos ser ganadores.', '', '', '', '', '', '', 38134),
(63073, 'esMX', 'Una red micelial', 'Activa la red de transporte.', 'El ánima fluye hacia lo más profundo de las raíces y alimenta a los champiñones. Ha pasado mucho tiempo desde que usamos los anillos para viajar por todo Ardenweald.\n\nRestaura nuestra conexión a la red de champiñones.', '', '', '', '', '', 'Habla con Zaki.', 38134),
(62899, 'esMX', 'El bosque interminable', 'Vuelve con Lady Baya Lunar', 'Bueno, ¡eso es todo lo que tengo para ti! ¡Uf! Has pasado por este lugar como un torbellino, ¿no? Arriba, abajo, en diagonal, ¡y hasta en las Fauces has estado! No sé cómo no te has mareado.\n\n<Mapirosa suelta una risita.>\n\n¡Deberías ir a ver a Lady Baya Lunar y avisarle que has terminado con tu entrenamiento!b\n\nNo creo que te tome examen.\n\nAunque quizás sí...', '', '', '', '', '', 'Vuelve con Lady Baya Lunar', 38134),
(62900, 'esMX', 'Un conducto para crecer', 'Agrega los conductos a la Forja de lazos y aplica uno a una ranura de Niya.', 'Si bien nuestro lazo es poderoso en sí mismo, también puedes mejorarlo usando conductos.\n\nLos conductos canalizan el ánima entre lazos de alma de diferentes modos, y al mismo tiempo mejoran el potencial de $Glos dos:las dos;. Nos permiten armonizarnos con las fortalezas únicas de $Gcada uno:cada una;.\n\nUsemos algunos ahora. Si pueden potenciar aún más nuestro vínculo, pueden ayudarnos a proteger el bosque.', '', '', '', '', '', '', 38134),
(61550, 'esMX', 'Fortalecer el lazo', 'Activa un poder de lazo de almas con la Forja de lazos.', 'Sé cómo te sientes... y lo que has tenido que pasar para defender a tu mundo. \n\nAhora tú también conoces mis propios triunfos y tragedias.\n\nNuestro lazo se fortalecerá con el tiempo. Pero por ahora, veamos lo que nos ha otorgado.\n\nArdenweald nos necesita. Tenemos que hacer todo lo que podamos para salvarla.', '', '', '', '', '', '', 38134),
(61542, 'esMX', 'El favor de los lazos', 'Completa el ritual para enlazar almas.', '<Mapirosa junta las manos al frente y adopta un aire de tranquilidad.>\n\nEnlazar almas no es algo irrevocable. Sin embargo, es un vínculo que hay que evaluar con detenimiento antes de tomar una decisión.\n\nCada uno conocerá los miedos y esperanzas del otro, los sueños, los recuerdos... compartirán todo. \n\nMientras el lazo exista, estarán entrelazados, siempre juntos aunque se separen.\n\nCuando el proceso se haya completado, su conexión trascenderá el plano de lo físico y los hará más fuertes.', '', '', '', '', '', '', 38134),
(63008, 'esMX', 'La Forja de lazos', 'Reúnete con Mapirosa en la Forja de Lazos.', 'Para servir mejor a la corte y el bosque, debes enlazarte con otro feérico.\n\nEs un ritual antiguo que te otorgará gran fortaleza para enfrentar muchas pruebas por venir.\n\nMapirosa te dará más instrucciones.', '', '', '', '', '', 'Reúnete con Mapirosa en la Forja de Lazos.', 38134),
(61541, 'esMX', 'La Forja de Lazos', 'Reúnete con Mapirosa en la Forja de Lazos.', '$n, ¿estás $glisto:lista; para otro regalo?\n\nEl siguiente favor que te otorgaremos es el de los lazos. Así como tú tienes un lazo con nosotros, nosotros tendremos un lazo contigo. Cuando formamos lazos de almas, nos convertimos en algo superior.\n\n<Baya Lunar se inclina para acercarse.>\n\nSuena un poco escalofriante, ¿no? ¡No te preocupes! Tú y tu lazo de alma se harán más fuertes.\n\nCuando pedí voluntarios, muchos feéricos se ofrecieron. Escogí a alguien que sé que te gustará. Y además ella también se beneficiará.\n\nVe a ver a Mapirosa. $gLos ayudará a los dos:Las ayudará a las dos;.', '', '', '', '', '', 'Reúnete con Mapirosa en la Forja de Lazos.', 38134),
(62898, 'esMX', 'El primer nuevo crecimiento', 'Da inicio a una mejora en el sagrario.', 'Hace tanto que dormíamos. Con almas, con ánima, volvemos a crecer. \n\nAhora nos queda tomar una decisión. ¿Cómo vamos a crecer? Puedes decidir qué flor florecerá primero.\n\nCon el tiempo, con más ánima y almas dispuestas, todo el jardín prosperará. Pero por ahora, un solo brote nos da esperanza para el futuro.\n\nLady Baya Lunar querrá saber qué has decidido. Ve a verla cuando lo sepas.', '', '', '', '', '', '', 38134),
(62897, 'esMX', 'Almas recuperadas', 'Habla con Zayhad.', '¡Me pregunto qué tipo de formas podrán adoptar estas almas!\n\nNo hay palabras para expresar nuestra gratitud por haberlas salvado. No solo le pusiste fin a su tormento, sino que ahora quizá quieran ayudarnos también. \n\nVe a hablar con Zayhad. Hace mucho tiempo que el cuidado del bosque está abandonado, pero puede que eso esté por cambiar. ¡Qué emoción!', '', '', '', '', '', 'Habla con Zayhad.', 38134),
(62894, 'esMX', 'Mapirosa dichosa', 'Ve a ver a Mapirosa en el Corazón del Bosque, en Ardenweald.', 'Baine sufre en Torghast, pero al menos sabemos que aún vive.\n\nApurar este rescate sería desastroso sin un plan de ataque. Me ocuparé de prepararlo.\n\nMientras tanto, te sugiero que traigas las almas que rescataste a Ardenweald.\n\nSe merecen un descanso después de todo lo que pasaron en las Fauces, y seguramente serán vitales para los noctifeéricos.', '', '', '', '', '', 'Ve a ver a Mapirosa en el Corazón del Bosque, en Ardenweald.', 38134),
(62837, 'esMX', 'Noticias esperanzadoras', 'Habla con Bolvar Fordragón en Oribos.', 'Los términos de nuestro trato se han cumplido. Puedes marcharte con las almas que has encontrado.\n\nTal vez el destino de este \"Baine\" sea de interés para ti o tus aliados. Sugiero que regreses a Oribos y los consultes.\n\nNo es necesario que te apresures. Después de todo, a los cautivos de Torghast los torturan durante siglos.\n\nPor favor, recuerda no contarle a nadie sobre nuestro arreglo. Después de todo, la discreción es clave entre $gsocios:socias;.', '', '', '', '', '', 'Habla con Bolvar Fordragón en Oribos.', 38134),
(60289, 'esMX', 'Regla 3: La confianza se gana', 'Coloca un faro de señalización en Cocyrus.', 'Antes de que abandones este reino maldito, hay una tarea final que debes completar para mí.\n\nLos jurafauces suelen transferir almas a varios bloques de Torghast desde diferentes áreas de las Fauces.\n\nPues resulta que conozco una de esas áreas. Coloca este faro ahí para que yo sepa cuándo se realizará la próxima transferencia.\n\nY si el enemigo detecta tu presencia... Bueno, eres $Gfamoso:famosa; por tus habilidades de combate, ¿no?', '', '', '', '', '', '', 38134),
(61355, 'esMX', 'Regla 2: Mantén un perfil bajo', 'Refuerza $1oa resguardos de alma.', 'Aunque lo único que quieras es marcharte con todas tus preciosas almas, todavía tenemos trabajo por hacer.\n\nEl Ojo del Carcelero se ha fijado en ti. Y eso no es bueno para nadie.\n\nToma este dispositivo. Reforzarás mis resguardos para que no me encuentre a mí también.\n\nLo último que necesito es $gun mortal ruidoso y falto de elegancia:una mortal ruidosa y falta de elegancia; que llame la atención sobre mí. Después de todo, no puedo permitir que el Carcelero me capture.\n\nSoy demasiado valiosa.', '', '', '', '', '', '', 38134),
(60287, 'esMX', 'Regla 1: Tener un plan de escape', 'Rescata 5 almas y consigue $2oa muestras de estigia. \n\nLos enemigos más fuertes tienen más probabilidad de dejar caer grandes cantidades de estigia. \n\nUsa la estigia para comprarle una clave de reubicación a Ve\'nari.', 'Muchas almas condenadas sufren en el interior de las Fauces. Debes tener cuidado si no quieres ser una de ellas.\n\nTu guardián de almas puede retener unas pocas hasta que regreses a tu Pacto. Pero eso no será de mucha ayuda si no logras sobrevivir a este lugar.\n\nHay una sustancia, la estigia, que se encuentra en algunas de las criaturas de las Fauces. Cuanto más fuerte es el alma, más estigia tiene.\n\nRecoge un poco para mí y podré usarla para crear muchas cosas que te resultarán de gran utilidad.', '', '', '', '', '', '', 38134),
(62882, 'esMX', 'Pautas claras', 'Establece las reglas básicas para trabajar con Ve\'nari.', '¿Volviste para rescatar más almas? Qué $gintrépido:intrépida;.\n\nAunque debo decir que tu escape anterior ha captado la atención del Carcelero… y su ira. Después de todo, nadie antes logró escapar de él.\n\nExcepto yo.\n\nAhora sus fuerzas están en alerta, y cazan a toda alma errante que $gel afamado:la afamada; Surcafauces pueda intentar robarle.\n\nSe ha vuelto todo un poco… complicado para mí. Si tú y yo vamos a trabajar $gjuntos:juntas;, tenemos que fijar algunas reglas básicas.\n\nY tienes que llevar el equipamiento adecuado.', '', '', '', '', '', '', 38134),
(62893, 'esMX', 'Por nosotros', 'Busca a Ve\'nari en las Fauces.', 'Se dice que has estado en las Fauces y has vuelto... ¡y hasta que te hiciste $Gamigo:amiga; de una negociante allí! \n\nTantas almas que estaban destinadas a Ardenweald quedaron atrapadas en ese reino oscuro. Necesitan nuestra ayuda... ¡y nosotros la de ellas! No podemos cultivar la magia del Corazón del Bosque sin almas.\n\nSé que es mucho pedir... pero quizá seas nuestra última oportunidad de rescatarlas. Ve a las Fauces y haz lo que para nosotros es imposible. ¡El futuro de Ardenweald depende de ello!', '', '', '', '', '', 'Busca a Ve\'nari en las Fauces.', 38134),
(62892, 'esMX', 'Recupera a los perdidos', 'Habla con Mapirosa en el Corazón del Bosque.', 'Ánima y almas. Viento y lluvia. Ardenweald necesita una combinación para prosperar.\n\nLas almas destinadas a nuestras ramas sufren en la oscuridad. Nadie escapa de las Fauces... pero tú eres capaz de caminar entre sus sombras y volver. Tú eres su salvación.\n\nMapirosa guía al rebaño con cuidado y compasión. Habla con ella. Trae nuestras almas perdidas a casa.', '', '', '', '', '', 'Habla con Mapirosa en el Corazón del Bosque.', 38134),
(62891, 'esMX', 'A la reserva', 'Deposita ánima en la reserva de tu sagrario.', 'Las arboledas se marchitan y las lágrimas de nuestra reina caen sobre suelo árido. El ánima, preciosa como el agua, ahora es tan escasa como la nieve. Nuestra reina da de su ánima, protege a todos bajo sus ramas... pero no hay árbol que haga un bosque.\n\nTu dádiva se atesorará y protegerá. El ánima nutre nuestras raíces como la esperanza nutre nuestro corazón. Es posible que Ardenweald vuelva a florecer.', '', '', '', '', '', '', 38134),
(62890, 'esMX', 'La formadora del bosque', 'Busca a Zayhad en las Raíces del Corazón del Bosque.', 'Has cumplido con tu deber, Surcafauces, y has traído la calma a nuestro bosque.\n\nMantente alerta, porque otros también requerirán de tus servicios.\n\nEl ánima que has recuperado será de gran utilidad en el Corazón del Bosque. Llévasela a Zayhad. Ella se encargará de mantenerla a salvo hasta que la necesitemos. La encontrarás en la profundidad de las Raíces del Corazón del bosque.', '', '', '', '', '', 'Busca a Zayhad en las Raíces del Corazón del Bosque.', 38134),
(60623, 'esMX', '¡AHHH! ¡Monstruos de verdad!', '', '', '', '', '', '', '', '', 38134),
(61549, 'esMX', 'Condiciones de la sequía', '', '', '', '', '', '', '', '', 38134),
(57443, 'esMX', 'Trabajo sucio: Servicio de demolición', '', '', '', '', '', '', '', '', 38134),
(61603, 'esMX', 'Desuello: Cuero de gorm grueso', '', '', '', '', '', '', '', '', 38134),
(61787, 'esMX', 'Fuerza de microdefensa', 'Derrota a Grixis Pequeñín en un duelo de mascotas.', '', '', '', '', '', '', '', 38134),
(61867, 'esMX', 'Piezas adicionales', 'Derrota a Grixis Pequeñín en un duelo de mascotas.', '', '', '', '', '', '', '', 38134),
(61883, 'esMX', 'Sobrevivientes resistentes', 'Derrota a Grixis Pequeñín en un duelo de mascotas.', '', '', '', '', '', '', '', 38134),
(61949, 'esMX', 'Tramposos de Ardenweald', 'Derrota a Grixis Pequeñín en un duelo de mascotas', '', '', '', '', '', '', '', 38134),
(60786, 'esMX', 'Defensa del enjambre', '', '', '', '', '', '', '', '', 38134),
(60655, 'esMX', 'Un maligno de piedra secuestrado', '', '', '', '', '', '', '', '', 38134),
(59743, 'esMX', 'La araña en el muro', '', '', '', '', '', '', '', '', 38134),
(59826, 'esMX', 'Apuesta por ti', 'Derrota a la señora Dyrax en el Teatro del Dolor cuando aparezca.', '$GEstimado:Estimada; Surcafauces... $Gamigo mío:amiga mía;... vas a perder. Todo el mundo sabe que no puedes competir en la arena. \n\nTodo el Paseo del Contendiente lo sabe, los negociantes de Oribos lo saben, hasta Zo\'umlo lo sabe.\n\nHe traído a una contendiente especial solo para demostrarlo. Enfréntate a la señora Dyrax en el Teatro del Dolor y demuestra que estamos equivocados... o en lo cierto.\n\nHabrá apuestas, así que no nos decepciones.', '', '', 'Señora Dyrax', '', '', '', 38134),
(58221, 'esMX', 'Hora de la venganza', '', '', '', '', '', '', '', '', 38134),
(59642, 'esMX', 'Tirada de pelo', 'Elimina al estratega Orco, el lanzador de altura Jalrax y el municionador Vizic', 'Las abominaciones están bien organizadas y abastecidas. No hemos podido ganar terreno.\n\nSi logramos desorganizar un poco sus suministros y refuerzos, obtendremos una ventaja.\n\nNecesito que te metas entre sus líneas y elimines a tres de las abominaciones que se ocupan de los suministros.', '', '', '', '', '', '', 38134),
(61631, 'esMX', 'Drust entre tú y yo', '', '', '', '', '', '', '', '', 38134),
(60911, 'esMX', 'Clases de vuelo: Aleteo frenético', '', '', '', '', '', '', '', '', 38134),
(60858, 'esMX', 'Clases de vuelo: ¡Despegue!', '', '', '', '', '', '', '', '', 38134),
(60457, 'esMX', 'Rescate de ánima', 'Reúne 150 ascuas de ánima de Torghast, la Torre de los Condenados.', 'Tantas almas que deberían haber sido nutridas aquí se han perdido en las Fauces, me duele de solo pensarlo.\n\nSurcafauces, te pedimos que hagas lo que nosotros no podemos. Atraviesa el territorio del Carcelero, camina por sus campos áridos, sube su torre maldita.\n\nTráenos lo que nos falta.', '', '', '', '', '', '', 38134),
(63346, 'esMX', 'Veterano de los noctifeéricos', 'Reúnete con Zo\'sorg en el Enclave de Oribos.', 'Gracias a ti, Ardenweald goza de una seguridad que ha desconocido durante mucho tiempo.\n\nTus logros no han pasado inadvertidos, incluso más allá de las fronteras de Ardenweald.\n\nLos relatos sobre tus victorias han resonado por los salones de Oribos. Zo\'sorg, el Maestro del conflicto, ha solicitado una reunión contigo en el Enclave.\n\nTiene un gran interés en el arte de la guerra. Te sugiero que no lo dejes esperando.', '', '', '', '', '', '', 38134),
(61331, 'esMX', 'La salvación de las almas perdidas', 'Rescata almas en las Fauces', 'Las almas siguen cayendo en las Fauces. Mientras esto siga sucediendo, ¡debemos salvar a todas las que podamos!\n\nEl Carcelero distorsiona el ciclo de la vida y el renacimiento. ¡Hay que detenerlo! Tenemos que desbaratar sus planes.\n\nRegresa a las Fauces y rescata a todas las almas que puedas.', '', '', '', '', '', '', 38134),
(60388, 'esMX', 'A entrenar a nuestras fuerzas', 'Completa 3 misiones de mundo en Ardenweald con tu aprendiz.', 'Arriba, aprendiz, ¡debes levantarte!\n\nNecesita mucho más entrenamiento para que podamos resistir el embate de nuestros enemigos. \n\nTenemos muy poco tiempo para desarrollar destreza guerrera en estos días, con tantos enemigos a nuestras espaldas.\n\nLlévate a este contigo, muéstrale cómo son las batallas, pero cuida que esté a salvo de desafíos abrumadores. Solo así podremos mejorar lo suficiente.', '', '', '', '', '', '', 38134);

UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=31889 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56087 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=47904 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=45381 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=45238 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=45175 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=29335 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=27123 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=26013 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=7848 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=58632 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56358 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=54438 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=24756 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=58374 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=57567 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=57565 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55609 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51813 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=43179 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=42422 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=42421 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=31591 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50792 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51681 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51106 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51665 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51500 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=43478 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52430 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=57340 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55889 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52864 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50876 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52794 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50846 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55834 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50853 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55264 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=54569 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50519 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56048 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55900 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51644 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51699 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52316 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51874 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51609 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51422 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=49097 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51972 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51166 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52889 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51108 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52140 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51411 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51639 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=54540 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55302 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51619 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56036 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51687 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52456 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52167 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55720 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52464 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51576 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50857 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50514 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=54622 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=55837 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52054 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=52884 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=44765 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=57338 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=54236 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51178 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50747 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=51035 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=50605 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=35174 AND `locale`='esMX');

DELETE FROM `quest_objectives_locale` WHERE (`locale`='esMX' AND `ID` IN (392616,398460,405142,398458,399108,398459,408877,407458,407457,407350,407344,407343,406093,406092,404552,404551,398630,398629,398628,398627,398626,398559,398558,398434,398098,398099,398097,397989,397988,407663,407662,407908,409169,408911,406260,406236,408996,405412,405384,408881,398086,405800,405294,408965,405406,408857,408896,408906,408959,399071,406262,406258,392429,392436,406712,406765,406804,406869,404687,404431,404430,404429,404428,404427,396871,396253,396683,396682,396662,408061,405012,405011,404920,404949,398461,405601,398432));
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES
(392616, 'esMX', 57531, 0, 'Pertenencias de Laurent recuperadas', 38134),
(398460, 'esMX', 60458, 0, 'Recoge ascuas de ánima en Torghast', 38134),
(405142, 'esMX', 60498, 0, 'Kalisthene derrotada', 38134),
(398458, 'esMX', 60460, 0, 'Recoge ascuas de ánima en Torghast', 38134),
(399108, 'esMX', 60640, 0, 'Mejora el Vivero de la Reina', 38134),
(398459, 'esMX', 60459, 0, 'Recoge ascuas de ánima en Torghast', 38134),
(408877, 'esMX', 62866, 0, 'Rescata almas de las Fauces', 38134),
(407458, 'esMX', 62217, 0, 'Fuerzas de los Rechazados derrotadas', 38134),
(407457, 'esMX', 62217, 4, 'Recluta a Marz', 38134),
(407350, 'esMX', 62194, 1, 'Fuerzas de los Rechazados derrotadas', 38134),
(407344, 'esMX', 62194, 3, 'Enseñanzas ancestrales recibidas por Sabrina', 38134),
(407343, 'esMX', 62194, 0, 'Recluta a Sabrina', 38134),
(406093, 'esMX', 61511, 3, 'Restos valiosos recogidos en Revendreth', 38134),
(406092, 'esMX', 61511, 0, 'Recluta a Coqui', 38134),
(404552, 'esMX', 60765, 0, 'Sobreviviente apestado curado por Hervoria', 38134),
(404551, 'esMX', 60765, 4, 'Recluta a Hervoria', 38134),
(398630, 'esMX', 60429, 5, 'Jefes de calabozo', 38134),
(398629, 'esMX', 60429, 4, 'Misiones diarias', 38134),
(398628, 'esMX', 60429, 3, 'Misiones de mundo', 38134),
(398627, 'esMX', 60429, 2, 'Tesoros', 38134),
(398626, 'esMX', 60429, 1, 'Élites raros', 38134),
(398559, 'esMX', 60429, 0, 'Raros', 38134),
(398558, 'esMX', 60429, -1, 'Maldraxxus defendido', 38134),
(398434, 'esMX', 60402, 0, 'Completa 3 misiones de mundo en Ardenweald con tu aprendiz', 38134),
(398098, 'esMX', 60291, 3, 'Cadáver recuperable devuelto a Rathan en el Bloque del Carnicero', 38134),
(398099, 'esMX', 60291, 1, 'Monta a Atrapamoscas', 38134),
(398097, 'esMX', 60291, 0, 'Recluta a Atrapamoscas', 38134),
(397989, 'esMX', 60237, 0, 'Bellota de ánima perdida recolectada', 38134),
(397988, 'esMX', 60237, 1, 'Recluta a Mondadientes', 38134),
(407663, 'esMX', 58525, 1, 'Recupera \"La malicia de Maldraxxus\"', 38134),
(407662, 'esMX', 58525, 0, 'Recupera \"Sobre huesos y piedras\"', 38134),
(407908, 'esMX', 58525, 2, 'Recluta al Profesor', 38134),
(409169, 'esMX', 63073, 0, 'Red de transporte activada', 38134),
(408911, 'esMX', 62900, 1, 'Agrega los conductos a la Forja de lazos', 38134),
(406260, 'esMX', 61550, 0, 'Poder de lazo de almas activado', 38134),
(406236, 'esMX', 61542, 0, 'Enlaza almas con Niya', 38134),
(408996, 'esMX', 63008, 0, 'Abandona la cámara de la Reina del invierno', 38134),
(405412, 'esMX', 60289, 3, 'Actually Return', 38134),
(405384, 'esMX', 60289, 2, 'Usa tu clave de reubicación para regresar con Ve\'nari', 38134),
(408881, 'esMX', 60289, 4, 'Maza de guerra Pezuña de Sangre recuperada', 38134),
(398086, 'esMX', 60289, 0, 'Faro de señalización colocado', 38134),
(405800, 'esMX', 61355, 0, 'Resguardo de alma reforzado', 38134),
(405294, 'esMX', 60287, 1, 'Compra una clave de reubicación', 38134),
(408965, 'esMX', 60287, 2, 'Puedes encontrar más estigia en enemigos poderosos', 38134),
(405406, 'esMX', 60287, 0, 'Estigia', 38134),
(408857, 'esMX', 60287, 3, 'Almas conservadas en el guardaalmas', 38134),
(408896, 'esMX', 62882, 2, 'Reglas básicas acordadas con Ve\'nari', 38134),
(408906, 'esMX', 62891, 1, 'Ánima depositada', 38134),
(408959, 'esMX', 62891, 0, 'Botín de los celadores de arboleda abierto', 38134),
(399071, 'esMX', 60623, -1, 'Repele la amenaza de devoradores', 38134),
(406262, 'esMX', 61549, 1, 'Cuidadores evacuados', 38134),
(406258, 'esMX', 61549, 0, 'Vermis de éter asesinados', 38134),
(392429, 'esMX', 57443, 0, 'Restos de escombros demolidos', 38134),
(392436, 'esMX', 57443, 1, 'Busca un dragador', 38134),
(406712, 'esMX', 61787, 0, 'Derrota a Zolla en un duelo de mascotas.', 38134),
(406765, 'esMX', 61867, 0, 'Derrota a Garrafón en un duelo de mascotas', 38134),
(406804, 'esMX', 61883, 0, 'Derrota a Sylla en un duelo de mascotas', 38134),
(406869, 'esMX', 61949, 0, 'Derrota a Pilluelo en un duelo de mascotas', 38134),
(404687, 'esMX', 60786, 1, 'Centinela alavelo montado', 38134),
(404431, 'esMX', 60655, 4, 'Maligno de piedra perdido rescatado', 38134),
(404430, 'esMX', 60655, 3, 'Maligno de piedra perdido encontrado', 38134),
(404429, 'esMX', 60655, 2, 'Maligno de piedra perdido encontrado', 38134),
(404428, 'esMX', 60655, 1, 'Maligno de piedra perdido encontrado', 38134),
(404427, 'esMX', 60655, 0, 'Maligno de piedra perdido encontrado', 38134),
(396871, 'esMX', 59743, 4, 'Habla con Khaliiq', 38134),
(396253, 'esMX', 58221, 2, 'Ensamblajes huesofundidos asesinados', 38134),
(396683, 'esMX', 59642, 1, 'Antena de Succión agria recogida', 38134),
(396682, 'esMX', 59642, 0, 'Pelos de piojos de cadáver recogidos', 38134),
(396662, 'esMX', 59642, 3, 'Crecimiento fibroso arrancado', 38134),
(408061, 'esMX', 61631, 0, 'Fuerzas drust asesinadas', 38134),
(405012, 'esMX', 60911, 0, 'Meta alcanzada', 38134),
(405011, 'esMX', 60911, 1, 'Habla con el instructor Malo', 38134),
(404920, 'esMX', 60858, 0, 'Cima del Templo alcanzada', 38134),
(404949, 'esMX', 60858, 1, 'Ingreso a la corriente ascendente', 38134),
(398461, 'esMX', 60457, 0, 'Recoge ascuas de ánima en Torghast', 38134),
(405601, 'esMX', 61331, 0, 'Rescata almas de las Fauces', 38134),
(398432, 'esMX', 60388, 0, 'Completa 3 misiones de mundo en Ardenweald con tu aprendiz', 38134);

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=269150 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=269149 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=269148 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=269147 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=269145 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=291117 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=287714 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=287855 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=387198 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=285073 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=284172 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=284171 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=268799 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=333827 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336764 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=338950 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=340126 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=389751 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=388979 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=388978 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336588 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `Description`='Normal Credit', `VerifiedBuild`=38134 WHERE (`ID`=336587 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336586 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336585 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336584 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=338752 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336452 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=335848 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=334937 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=338443 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=335757 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `Description`='Normal Credit', `VerifiedBuild`=38134 WHERE (`ID`=335756 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=335755 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=335754 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=335753 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=341806 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336572 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=389002 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=389001 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336526 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390099 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336798 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=339028 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=339027 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=338205 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=389542 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336324 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336322 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=387780 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=389734 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=337891 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=340210 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=392167 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=386610 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=333688 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=336308 AND `locale`='esMX');

DELETE FROM `page_text_locale` WHERE (`ID`=8226 AND `locale`='esMX');
INSERT INTO `page_text_locale` (`ID`, `Text`, `locale`, `VerifiedBuild`) VALUES
(8226, 'Este tesoro está cerrado por medios mágicos.\n\nHay tres runas en el cofre. Parecen obtener poder de las runas cercanas.', 'esMX', 38134);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (60420 /*-Unknown-*/, 61984 /*-Unknown-*/, 59826 /*-Unknown-*/, 60388 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(60420, 0, 0, 0, 0, 0, 0, 0, 0, 'Las casas de Maldraxxus están nuevamente en armonía, y ya no representan una amenaza para nosotros... por ahora, al menos. \n\n¡Lo hiciste muy bien!', 38134), -- -Unknown-
(61984, 0, 0, 0, 0, 0, 0, 0, 0, 'El ánima que has conseguido nutrirá nuestras valiosas arboledas. Te agradecemos.', 38134), -- -Unknown-
(59826, 0, 0, 0, 0, 0, 0, 0, 0, 'Tu desempeño me ha dado una buena ganancia... Zo\'umlo apostó mal.', 38134), -- -Unknown-
(60388, 0, 0, 0, 0, 0, 0, 0, 0, 'Has hecho bien, ahora que descanse. Hoy ha aprendido que incluso en las praderas más calmas siempre hay peligro.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=61708 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=61708 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=61708 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=61708 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(61708, 0, 3, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(61708, 0, 2, 31, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(61708, 0, 1, 3, 406539, 161196, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(61708, 0, 0, 0, 407152, 160917, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59826 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59826 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59826 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=61708 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=61708 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=61708 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=61708 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(61708, 3, 0, 3510, -2770, 3342, 38134), -- -Unknown-
(61708, 2, 0, 3687, -3056, 3518, 38134), -- -Unknown-
(61708, 1, 0, 3683, -3069, 3518, 38134), -- -Unknown-
(61708, 0, 0, 3505, -2767, 3342, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61539 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59642 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59826 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59826 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59826 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61631 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60388 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (59826 /*-Unknown-*/, 60457 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59826, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60457, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`ID`=320160 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(320160, 0, 2222, -1834.2099609375, 1551.43994140625, 5274.31005859375, 38134); -- Spell: 320160 (Portal: Oribos) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=319721 AND `EffectIndex`=3);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=89158 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=347650 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=326498 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=308437 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=329260 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (174131 /*174131 (Champibum)*/, 174139 /*174139 (Princesa Penicilia)*/, 174130 /*174130 (Champifauces enloquecido) - No NPC Damage Below Override Points%*/, 174138 /*174138 (Guardia fúngica real) - No NPC Damage Below Override Points%*/, 170227 /*170227 (Larva de gorm) - Squish Aura*/, 170250 /*170250 (Huevo de gorm)*/, 177513 /*177513 (Mor'Kirk)*/, 173539 /*173539 (Spell Bunny)*/, 172838 /*172838 (Lar'eye)*/, 172813 /*172813 (Ton'hamil)*/, 174395 /*174395 (Raspamédulas)*/, 174431 /*174431 (Sastrona cautiva) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 173582 /*173582 (Mantarraya contagiada prófuga)*/, 172606 /*172606 (Coalescencia fatal)*/, 174020 /*174020 (Capitán Prateq)*/, 160700 /*160700 (Gato espectral) - Shadowy Ghost Visual*/, 172922 /*172922 (Margravina Sin'dane)*/, 173573 /*173573 (Óculo decrépito) - Detector, Invisibility and Stealth Detection*/, 174435 /*174435 (Muñeco de entrenamiento)*/, 174226 /*174226 (Valdemar)*/, 173509 /*173509 (Tuetacánido animado)*/, 173505 /*173505 (Qexu)*/, 174377 /*174377 (Cor'lat)*/, 172604 /*172604 (Guardahuesos animado)*/, 172833 /*172833 (Antare)*/, 173563 /*173563 (Tomo errante)*/, 173507 /*173507 (Nhaurra)*/, 173564 /*173564 (Pluma traviesa)*/, 173503 /*173503 (Acólito estudioso) - [DNT] Highlight Me*/, 173433 /*173433 (Acólita Nelesis) - [DNT] Channel Necromancy Omni*/, 175022 /*175022 (Bleak Skitterer) - Battle Pet Periodic*/, 175789 /*175789 (Sombralúgubre)*/, 161196 /*161196 (Arin'gore)*/, 173045 /*173045 (Matriarca alaflagelada)*/, 173046 /*173046 (Vigilante de nido feroz)*/, 159886 /*159886 (Hermana Chelicerae)*/, 159852 /*159852 (Barrera de telaraña)*/, 160917 /*160917 (Sombralúgubre)*/, 157844 /*157844 (Messana)*/, 165440 /*165440 (Crecimiento fibroso) - Stringy Growth*/, 166534 /*166534 (Ti'or) - Containment Field*/, 176400 /*176400 (|cFFFFFFFF|rNecrópolis: Zerekriss)*/, 156634 /*156634 (Winter Queen)*/, 174705 /*174705 (Lord Amalthwyn) - Empowering*/, 174732 /*174732 (Ingra Krazic)*/, 174729 /*174729 (Conquistador contagiado) - Dark Portents*/, 169960 /*169960 (Llevar semilla onírica a la arboleda)*/, 175054 /*175054 (Defensor de la arboleda)*/, 174730 /*174730 (Trepador invasivo)*/, 175053 /*175053 (Defensor de la arboleda)*/, 174731 /*174731 (Cuidador de arboledas poseído)*/, 174611 /*174611 (Boles)*/, 174613 /*174613 (M'Can)*/, 158544 /*158544 (Lord Herne)*/, 174572 /*174572 (Lillyensthoom) - Training Dummy Marker, Passive Uber DoT*/, 165751 /*165751 (Guardián)*/, 173681 /*173681 (Samn'go)*/, 173682 /*173682 (Dor'levgoren)*/, 158543 /*158543 (Asistente Rociolux)*/, 175419 /*175419 (Maestra artesana Lamda)*/, 175418 /*175418 (Mar'lan)*/, 173171 /*173171 (Viverista Noche Estrellada)*/, 174775 /*174775 (Ofer)*/, 174614 /*174614 (Ka'ruth)*/, 161509 /*161509 (Lady Baya Lunar)*/, 175417 /*175417 (Sulanoom)*/, 167196 /*167196 (Sesselie)*/, 175415 /*175415 (Harkoth)*/, 174608 /*174608 (Chispa)*/, 172400 /*172400 (Mesa de comando)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(174131, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174131 (Champibum)
(174139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174139 (Princesa Penicilia)
(174130, 0, 0, 0, 1, 0, 0, 0, 0, '155893'), -- 174130 (Champifauces enloquecido) - No NPC Damage Below Override Points%
(174138, 0, 0, 0, 1, 0, 0, 0, 0, '155893'), -- 174138 (Guardia fúngica real) - No NPC Damage Below Override Points%
(170227, 0, 0, 0, 1, 0, 0, 0, 0, '331601'), -- 170227 (Larva de gorm) - Squish Aura
(170250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170250 (Huevo de gorm)
(177513, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 177513 (Mor'Kirk)
(173539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173539 (Spell Bunny)
(172838, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172838 (Lar'eye)
(172813, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172813 (Ton'hamil)
(174395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174395 (Raspamédulas)
(174431, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 174431 (Sastrona cautiva) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(173582, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 173582 (Mantarraya contagiada prófuga)
(172606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172606 (Coalescencia fatal)
(174020, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174020 (Capitán Prateq)
(160700, 0, 0, 1, 1, 0, 0, 0, 0, '295709'), -- 160700 (Gato espectral) - Shadowy Ghost Visual
(172922, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 172922 (Margravina Sin'dane)
(173573, 0, 0, 0, 1, 0, 0, 0, 0, '339781 67236'), -- 173573 (Óculo decrépito) - Detector, Invisibility and Stealth Detection
(174435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174435 (Muñeco de entrenamiento)
(174226, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174226 (Valdemar)
(173509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173509 (Tuetacánido animado)
(173505, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173505 (Qexu)
(174377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174377 (Cor'lat)
(172604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172604 (Guardahuesos animado)
(172833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172833 (Antare)
(173563, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 173563 (Tomo errante)
(173507, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173507 (Nhaurra)
(173564, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 173564 (Pluma traviesa)
(173503, 0, 0, 0, 1, 0, 0, 0, 0, '292025'), -- 173503 (Acólito estudioso) - [DNT] Highlight Me
(173433, 0, 0, 0, 1, 0, 0, 0, 0, '337602'), -- 173433 (Acólita Nelesis) - [DNT] Channel Necromancy Omni
(175022, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- 175022 (Bleak Skitterer) - Battle Pet Periodic
(175789, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 175789 (Sombralúgubre)
(161196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161196 (Arin'gore)
(173045, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173045 (Matriarca alaflagelada)
(173046, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 173046 (Vigilante de nido feroz)
(159886, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159886 (Hermana Chelicerae)
(159852, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159852 (Barrera de telaraña)
(160917, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 160917 (Sombralúgubre)
(157844, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157844 (Messana)
(165440, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 165440 (Crecimiento fibroso) - Stringy Growth
(166534, 0, 0, 0, 1, 0, 0, 0, 0, '347254'), -- 166534 (Ti'or) - Containment Field
(176400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 176400 (|cFFFFFFFF|rNecrópolis: Zerekriss)
(156634, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156634 (Winter Queen)
(174705, 0, 0, 0, 0, 0, 0, 0, 0, '343291'), -- 174705 (Lord Amalthwyn) - Empowering
(174732, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174732 (Ingra Krazic)
(174729, 0, 0, 0, 1, 0, 0, 0, 0, '334735'), -- 174729 (Conquistador contagiado) - Dark Portents
(169960, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169960 (Llevar semilla onírica a la arboleda)
(175054, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175054 (Defensor de la arboleda)
(174730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174730 (Trepador invasivo)
(175053, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175053 (Defensor de la arboleda)
(174731, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174731 (Cuidador de arboledas poseído)
(174611, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174611 (Boles)
(174613, 0, 0, 0, 1, 0, 15009, 0, 0, ''), -- 174613 (M'Can)
(158544, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158544 (Lord Herne)
(174572, 0, 0, 0, 1, 0, 0, 0, 0, '98892 167347'), -- 174572 (Lillyensthoom) - Training Dummy Marker, Passive Uber DoT
(165751, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165751 (Guardián)
(173681, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173681 (Samn'go)
(173682, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173682 (Dor'levgoren)
(158543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158543 (Asistente Rociolux)
(175419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175419 (Maestra artesana Lamda)
(175418, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175418 (Mar'lan)
(173171, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173171 (Viverista Noche Estrellada)
(174775, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174775 (Ofer)
(174614, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174614 (Ka'ruth)
(161509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161509 (Lady Baya Lunar)
(175417, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175417 (Sulanoom)
(167196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167196 (Sesselie)
(175415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175415 (Harkoth)
(174608, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174608 (Chispa)
(172400, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 172400 (Mesa de comando)


UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=167507; -- 167507 (Polluelo alavelo)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=166180; -- 166180 (Defensor de la arboleda)
UPDATE `creature_template_addon` SET `auras`='169471' WHERE `entry`=170206; -- 170206 (Venado rúnico)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=165910; -- 165910 (Boggart nudorrama)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=169915; -- 169915 (Acecharrunas)
UPDATE `creature_template_addon` SET `auras`='322745' WHERE `entry`=170205; -- 170205 (Ciervorruna juvenil)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=164728; -- 164728 (Heartwood Grove Evacuee)
UPDATE `creature_template_addon` SET `auras`='312156 330450' WHERE `entry`=157883; -- 157883 (Sylvar poseído)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='330583' WHERE `entry`=169803; -- 169803 (Feérico convertido)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='336451' WHERE `entry`=172590; -- 172590 (Campeón juraexánimes)
UPDATE `creature_template_addon` SET `auras`='321276 344872' WHERE `entry`=172567; -- 172567 (Mortisombra de Xantuth)
UPDATE `creature_template_addon` SET `auras`='337602' WHERE `entry`=172601; -- 172601 (Hechicero necrótico)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=172627; -- 172627 (Esclavo animado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=168859; -- 168859 (Barril recuperado)
UPDATE `creature_template_addon` SET `bytes1`=50593792, `auras`='154470' WHERE `entry`=169249; -- 169249 (Zángano putreaguijón)
UPDATE `creature_template_addon` SET `bytes1`=50593792, `auras`='154470' WHERE `entry`=169250; -- 169250 (Obrera putreaguijón)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='154470' WHERE `entry`=162732; -- 162732 (Masa coagulante)
UPDATE `creature_template_addon` SET `auras`='316729 331108' WHERE `entry`=162727; -- 162727 (Burbusangre)
UPDATE `creature_template_addon` SET `auras`='93970' WHERE `entry`=165551; -- 165551 (Piojo de cadáver succionante)
UPDATE `creature_template_addon` SET `auras`='302892' WHERE `entry`=158053; -- 158053 (Madre de piojos de cadáver)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=158566; -- 158566 (Engendro de piojo de cadáver)
UPDATE `creature_template_addon` SET `bytes1`=7, `auras`='302892' WHERE `entry`=158752; -- 158752 (Colmisangre depredador)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=162816; -- 162816 (Generic Bunny)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=163041; -- 163041 (Prospector de la arena)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=175394; -- 175394 (Ja'red Haze)
UPDATE `creature_template_addon` SET `auras`='317096' WHERE `entry`=162872; -- 162872 (Xantuth la Contagiada)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=170542; -- 170542 (Duelistas veteranos)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=166564; -- 166564 (Aprendiz incansable)
UPDATE `creature_template_addon` SET `auras`='317184' WHERE `entry`=162873; -- 162873 (Azmogal)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=166423; -- 166423 (Alaflagelada entrenado)
UPDATE `creature_template_addon` SET `auras`='214567' WHERE `entry`=159856; -- 159856 (Peste virulenta)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=162258; -- 162258 (Chillavientos voraz)
UPDATE `creature_template_addon` SET `auras`='343329' WHERE `entry`=156558; -- 156558 (Generic - Empty Bunny)
UPDATE `creature_template_addon` SET `auras`='273259' WHERE `entry`=165017; -- 165017 (Inventor de plagas)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=172173; -- 172173 (Intérprete de disputas)
UPDATE `creature_template_addon` SET `aiAnimKit`=21543 WHERE `entry`=164123; -- 164123 (Escriba asistente)
UPDATE `creature_template_addon` SET `aiAnimKit`=13352 WHERE `entry`=164803; -- 164803 (Protector supremo de la bóveda)
UPDATE `creature_template_addon` SET `aiAnimKit`=16748 WHERE `entry`=156698; -- 156698 (Protector asistente)
UPDATE `creature_template_addon` SET `auras`='343291' WHERE `entry`=174704; -- 174704 (Guardián pacífico)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=172934; -- 172934 (Venado rúnico ramalvaje)
UPDATE `creature_template_addon` SET `auras`='184506 96577' WHERE `entry`=176019; -- 176019 (Verdant Kit)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=167503; -- 167503 (Guardián alavelo)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=173766; -- 173766 (Polvoriento arrasador)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=161917; -- 161917 (Merodeador glauco)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (170250,177513,172838,172813,174395,174431,173582,172606,174020,160700,172922,173573,174435,174226,173509,173505,174377,172604,172833,173563,173507,173564,173503,173433,175789,159886,159852,157844,166534,176400,174705,174732,174729,175054,174730,175053,174731));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(170250, 0, 56, 56, 0, 0, 1233, 38134),
(177513, 0, 60, 60, 0, 0, 837, 38134),
(172838, 0, 60, 60, 0, 0, 837, 38134),
(172813, 0, 60, 60, 0, 0, 837, 38134),
(174395, 0, 54, 54, 0, 0, 1336, 38134),
(174431, 0, 60, 60, 0, 0, 837, 38134),
(173582, 0, 60, 60, 0, 0, 837, 38134),
(172606, 0, 60, 60, 0, 0, 837, 38134),
(174020, 0, 60, 60, 0, 0, 837, 38134),
(160700, 0, 60, 60, 0, 0, 837, 38134),
(172922, 0, 60, 60, 0, 0, 837, 38134),
(173573, 0, 60, 60, 0, 0, 837, 38134),
(174435, 0, 60, 60, 0, 0, 837, 38134),
(174226, 0, 1, 1, 0, 0, 81, 38134),
(173509, 0, 60, 60, 0, 0, 837, 38134),
(173505, 0, 60, 60, 0, 0, 837, 38134),
(174377, 0, 60, 60, 0, 0, 837, 38134),
(172604, 0, 60, 60, 0, 0, 2060, 38134),
(172833, 0, 60, 60, 0, 0, 837, 38134),
(173563, 0, 50, 50, 0, 0, 703, 38134),
(173507, 0, 60, 60, 0, 0, 837, 38134),
(173564, 0, 50, 50, 0, 0, 703, 38134),
(173503, 0, 60, 60, 0, 0, 837, 38134),
(173433, 0, 60, 60, 0, 0, 837, 38134),
(175789, 0, 60, 60, 0, 0, 837, 38134),
(159886, 0, 60, 60, 2, 2, 2060, 38134),
(159852, 0, 60, 60, 0, 0, 837, 38134),
(157844, 0, 60, 60, 0, 0, 837, 38134),
(166534, 0, 53, 55, 1, 1, 745, 38134),
(176400, 0, 60, 60, 0, 0, 2060, 38134),
(174705, 0, 60, 60, 0, 0, 2060, 38134),
(174732, 0, 60, 60, 0, 0, 837, 38134),
(174729, 0, 60, 60, 0, 0, 837, 38134),
(175054, 0, 60, 60, 0, 0, 837, 38134),
(174730, 0, 60, 60, 0, 0, 837, 38134),
(175053, 0, 60, 60, 0, 0, 837, 38134),
(174731, 0, 60, 60, 0, 0, 837, 38134);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172110 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174776 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174139 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174130 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174138 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=167505 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=167507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169874 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173378 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=173377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170790 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=166180 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175858 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164033 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170442 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=176021 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169979 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=163967 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165603 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=56, `LevelScalingMax`=56, `ContentTuningID`=1233, `VerifiedBuild`=38134 WHERE (`Entry`=170227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169913 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170733 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170730 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165855 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172172 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165857 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=171349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165164 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160816 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158921 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170902 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165159 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=166248 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158495 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=162446 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158494 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=162434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160814 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160817 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164728 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=166073 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158487 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165157 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=171116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165154 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165162 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165155 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165156 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173539 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164922 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164923 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168620 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=157885 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=157883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164802 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=171883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164874 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=176020 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164809 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164924 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170769 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170734 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170446 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169169 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172965 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164700 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172590 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172601 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172596 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=157952 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=172589 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=172627 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=172557 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=173489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175022 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=54, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169512 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `ContentTuningID`=1330, `VerifiedBuild`=38134 WHERE (`Entry`=158977 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=176219 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161196 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=173045 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159747 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=173046 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=159901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159708 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=160917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=53, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=175478 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `ContentTuningID`=1334, `VerifiedBuild`=38134 WHERE (`Entry`=165214 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=169699 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=54, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169249 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173274 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=54, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169250 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=159916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `ContentTuningID`=1331, `VerifiedBuild`=38134 WHERE (`Entry`=159893 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=54, `ContentTuningID`=1331, `VerifiedBuild`=38134 WHERE (`Entry`=165376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=169521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=157517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=162732 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=165440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=175215 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167195 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=55, `LevelScalingMax`=58, `ContentTuningID`=744, `VerifiedBuild`=38134 WHERE (`Entry`=165701 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=156634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169960 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172966 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174713 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172934 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172945 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174837 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172722 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172979 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=176019 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173106 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174777 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=166187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=167503 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174633 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173766 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174632 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=169862 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=161917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=161920 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=161882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174631 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173862 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173884 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174362 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174365 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174364 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174371 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164023 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174570 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174569 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174613 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167193 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174914 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174571 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160292 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158544 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=174572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165751 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158547 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=173682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=55, `LevelScalingMax`=58, `ContentTuningID`=744, `VerifiedBuild`=38134 WHERE (`Entry`=158543 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=175419 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=175418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=173171 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160262 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=170107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=167206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=176096 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=165659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=161509 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160482 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=160481 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=175417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=175414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=55, `LevelScalingMax`=58, `ContentTuningID`=744, `VerifiedBuild`=38134 WHERE (`Entry`=167196 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=175415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174608 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=158555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=172400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=164701 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=168100 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=38134 WHERE (`Entry`=174835 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=0.678112566471099853, `CombatReach`=1 WHERE `DisplayID`=92415;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100033;
UPDATE `creature_model_info` SET `BoundingRadius`=0.961840033531188964, `CombatReach`=1 WHERE `DisplayID`=92627;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97850;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95542;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96662;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83608;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90583;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83590;
UPDATE `creature_model_info` SET `BoundingRadius`=1.075765132904052734, `CombatReach`=3 WHERE `DisplayID`=83597;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83615;
UPDATE `creature_model_info` SET `BoundingRadius`=1.075765132904052734, `CombatReach`=3 WHERE `DisplayID`=83594;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99798;
UPDATE `creature_model_info` SET `BoundingRadius`=1.547241449356079101 WHERE `DisplayID`=64331;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99782;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98908;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96412;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97050;
UPDATE `creature_model_info` SET `BoundingRadius`=0.055679995566606521, `CombatReach`=0.079999998211860656 WHERE `DisplayID`=42677;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78832;
UPDATE `creature_model_info` SET `BoundingRadius`=4.472733497619628906, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=96411;
UPDATE `creature_model_info` SET `BoundingRadius`=0.85237276554107666, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=95690;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96900;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83194;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95556;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95871;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100041;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94222;
UPDATE `creature_model_info` SET `BoundingRadius`=8.3603363037109375, `CombatReach`=8, `VerifiedBuild`=38134 WHERE `DisplayID`=94412;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93783;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68393;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97290;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97291;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19530;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100152;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95928;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97278;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93782;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=55077;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94197;
UPDATE `creature_model_info` SET `BoundingRadius`=0.168749988079071044, `CombatReach`=0.28125, `VerifiedBuild`=38134 WHERE `DisplayID`=97253;
UPDATE `creature_model_info` SET `BoundingRadius`=0.769695639610290527, `VerifiedBuild`=38134 WHERE `DisplayID`=62590;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1875, `CombatReach`=0.3125, `VerifiedBuild`=38134 WHERE `DisplayID`=97252;
UPDATE `creature_model_info` SET `BoundingRadius`=0.206250011920928955, `CombatReach`=0.34375, `VerifiedBuild`=38134 WHERE `DisplayID`=97249;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=95202;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62591;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39210;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93786;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94209;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55764;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57544;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97272;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97271;
UPDATE `creature_model_info` SET `BoundingRadius`=0.140000000596046447, `CombatReach`=0.400000005960464477 WHERE `DisplayID`=80463;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99804;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99780;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96976;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95257;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98616;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94869;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99686;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34170;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95639;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95048;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97169;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95640;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94458;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95297;
UPDATE `creature_model_info` SET `BoundingRadius`=0.437308698892593383, `VerifiedBuild`=38134 WHERE `DisplayID`=95840;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97414;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94208;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99707;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97480;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95532;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96104;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96963;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99706;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99695;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99752;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97496;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97171;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95661;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95271;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95450;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93755;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93745;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4615;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62728;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23506;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62588;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60611;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95249;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=901;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95561;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94213;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95560;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94210;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93793;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96039;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90867;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=18724;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93788;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100151;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96759;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95927;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95244;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97364;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96105;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96764;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95695;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93785;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78850;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97281;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97282;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87593;
UPDATE `creature_model_info` SET `BoundingRadius`=0.874301791191101074, `CombatReach`=1.5625 WHERE `DisplayID`=96754;
UPDATE `creature_model_info` SET `BoundingRadius`=0.843031287193298339, `CombatReach`=1.85000002384185791 WHERE `DisplayID`=92192;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93601;
UPDATE `creature_model_info` SET `BoundingRadius`=2.368456602096557617, `CombatReach`=2.47500014305114746 WHERE `DisplayID`=96545;
UPDATE `creature_model_info` SET `BoundingRadius`=2.368456602096557617, `CombatReach`=2.47500014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=96077;
UPDATE `creature_model_info` SET `BoundingRadius`=2.416819572448730468, `CombatReach`=0.82500004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=97399;
UPDATE `creature_model_info` SET `BoundingRadius`=2.416819572448730468, `CombatReach`=0.82500004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=97657;
UPDATE `creature_model_info` SET `BoundingRadius`=0.166421771049499511, `VerifiedBuild`=38134 WHERE `DisplayID`=46897;
UPDATE `creature_model_info` SET `BoundingRadius`=3.97793745994567871, `CombatReach`=4.387499809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=96075;
UPDATE `creature_model_info` SET `BoundingRadius`=0.435061991214752197, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=46938;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96886;
UPDATE `creature_model_info` SET `BoundingRadius`=0.435061991214752197, `VerifiedBuild`=38134 WHERE `DisplayID`=72239;
UPDATE `creature_model_info` SET `BoundingRadius`=2.153142213821411132, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=96079;
UPDATE `creature_model_info` SET `BoundingRadius`=2.153142213821411132, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=96546;
UPDATE `creature_model_info` SET `BoundingRadius`=2.153142213821411132, `CombatReach`=2.25 WHERE `DisplayID`=96373;
UPDATE `creature_model_info` SET `BoundingRadius`=0.439141005277633666, `VerifiedBuild`=38134 WHERE `DisplayID`=60887;
UPDATE `creature_model_info` SET `BoundingRadius`=0.439141005277633666, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=97328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.880216360092163085, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=94050;
UPDATE `creature_model_info` SET `BoundingRadius`=0.200000002980232238, `CombatReach`=7, `VerifiedBuild`=38134 WHERE `DisplayID`=100154;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64177;
UPDATE `creature_model_info` SET `BoundingRadius`=0.880216360092163085, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=95990;
UPDATE `creature_model_info` SET `BoundingRadius`=0.733513593673706054, `CombatReach`=1.5 WHERE `DisplayID`=95991;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96542;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41199;
UPDATE `creature_model_info` SET `BoundingRadius`=0.67146378755569458, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=96132;
UPDATE `creature_model_info` SET `BoundingRadius`=0.67146378755569458, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=96131;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100228;
UPDATE `creature_model_info` SET `BoundingRadius`=3.22971343994140625, `CombatReach`=3.375 WHERE `DisplayID`=96864;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82379;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94594;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94076;
UPDATE `creature_model_info` SET `BoundingRadius`=7.649127483367919921, `CombatReach`=4.950000286102294921, `VerifiedBuild`=38134 WHERE `DisplayID`=96755;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=94100;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96946;
UPDATE `creature_model_info` SET `BoundingRadius`=2.757707834243774414, `CombatReach`=4 WHERE `DisplayID`=94922;
UPDATE `creature_model_info` SET `BoundingRadius`=1.626700997352600097, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=96468;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94833;
UPDATE `creature_model_info` SET `BoundingRadius`=1.771826744079589843, `CombatReach`=1.5 WHERE `DisplayID`=95796;
UPDATE `creature_model_info` SET `BoundingRadius`=0.67146378755569458, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=96553;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94384;
UPDATE `creature_model_info` SET `BoundingRadius`=1.239107370376586914, `CombatReach`=0.60000002384185791 WHERE `DisplayID`=80021;
UPDATE `creature_model_info` SET `BoundingRadius`=9.271669387817382812, `CombatReach`=6 WHERE `DisplayID`=94406;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100155;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96597;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95762;
UPDATE `creature_model_info` SET `BoundingRadius`=0.880216360092163085, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=94145;
UPDATE `creature_model_info` SET `BoundingRadius`=0.870888888835906982, `CombatReach`=2.925000190734863281 WHERE `DisplayID`=95944;
UPDATE `creature_model_info` SET `BoundingRadius`=3.544458389282226562, `VerifiedBuild`=38134 WHERE `DisplayID`=76770;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5 WHERE `DisplayID`=96196;
UPDATE `creature_model_info` SET `BoundingRadius`=0.733513593673706054, `CombatReach`=1.5 WHERE `DisplayID`=94526;
UPDATE `creature_model_info` SET `BoundingRadius`=0.965654373168945312, `CombatReach`=1.019999980926513671 WHERE `DisplayID`=95384;
UPDATE `creature_model_info` SET `BoundingRadius`=0.551690876483917236, `CombatReach`=0.375 WHERE `DisplayID`=95788;
UPDATE `creature_model_info` SET `BoundingRadius`=0.551690876483917236, `CombatReach`=0.375 WHERE `DisplayID`=95787;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699441432952880859, `CombatReach`=1.25 WHERE `DisplayID`=96201;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699441432952880859, `CombatReach`=1.25 WHERE `DisplayID`=96200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.557368874549865722, `CombatReach`=1.871999979019165039 WHERE `DisplayID`=95968;
UPDATE `creature_model_info` SET `BoundingRadius`=0.93155074119567871, `CombatReach`=1.5 WHERE `DisplayID`=95559;
UPDATE `creature_model_info` SET `BoundingRadius`=1.079260706901550292, `CombatReach`=1.139999985694885253 WHERE `DisplayID`=95376;
UPDATE `creature_model_info` SET `BoundingRadius`=1.197071075439453125, `CombatReach`=1.5 WHERE `DisplayID`=95113;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5 WHERE `DisplayID`=96209;
UPDATE `creature_model_info` SET `BoundingRadius`=1.091128706932067871, `CombatReach`=1.95000004768371582 WHERE `DisplayID`=96555;
UPDATE `creature_model_info` SET `BoundingRadius`=2.083333253860473632, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=94614;
UPDATE `creature_model_info` SET `BoundingRadius`=0.912485718727111816, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=77687;
UPDATE `creature_model_info` SET `BoundingRadius`=0.912485718727111816, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=77690;
UPDATE `creature_model_info` SET `BoundingRadius`=2.455555438995361328, `CombatReach`=2.599999904632568359 WHERE `DisplayID`=93592;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96425;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95857;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95678;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97594;
UPDATE `creature_model_info` SET `BoundingRadius`=0.623116374015808105, `CombatReach`=2.519999980926513671 WHERE `DisplayID`=99048;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95882;
UPDATE `creature_model_info` SET `BoundingRadius`=1.157220005989074707, `VerifiedBuild`=38134 WHERE `DisplayID`=96881;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96777;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083141326904296, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=99061;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083141326904296, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97612;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97597;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95868;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97603;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083141326904296, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97606;
UPDATE `creature_model_info` SET `BoundingRadius`=0.703680276870727539, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=96774;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97601;
UPDATE `creature_model_info` SET `BoundingRadius`=0.703680276870727539, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=96776;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96029;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95256;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97596;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083141326904296, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=99062;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=97595;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95884;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96248;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85884;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96032;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96027;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98634;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=99053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.400000005960464477, `CombatReach`=0.5 WHERE `DisplayID`=40712;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94292;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94296;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95199;
UPDATE `creature_model_info` SET `BoundingRadius`=0.031000001356005668, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=60862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.229153215885162353, `VerifiedBuild`=38134 WHERE `DisplayID`=93750;
UPDATE `creature_model_info` SET `BoundingRadius`=1.763289451599121093, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=93790;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95201;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98457;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95581;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.227499991655349731, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=95200;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=20042;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60863;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98458;
UPDATE `creature_model_info` SET `BoundingRadius`=1.46940779685974121, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=93791;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93795;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96413;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97940;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97510;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95056;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96867;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93758;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93748;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=95198;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98609;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99632;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97746;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94217;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97756;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98786;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97478;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759995520114898681, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=98617;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98982;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97383;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95045;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99153;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98625;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95879;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95908;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99155;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95932;
UPDATE `creature_model_info` SET `BoundingRadius`=1.043871760368347167, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=95899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083141326904296, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=95912;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95245;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95880;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95909;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95918;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95867;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95915;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95866;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95916;
UPDATE `creature_model_info` SET `BoundingRadius`=1.66953587532043457, `VerifiedBuild`=38134 WHERE `DisplayID`=98201;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95911;
UPDATE `creature_model_info` SET `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=95869;
UPDATE `creature_model_info` SET `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=95887;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95877;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95254;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95881;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99771;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99621;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99614;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98917;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94457;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95259;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98618;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98983;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96928;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98633;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98981;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99788;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99755;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95261;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98760;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99019;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95248;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94474;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94430;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95232;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99781;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=95541;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99750;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94475;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083051919937133, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=95251;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99612;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95681;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99613;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98626;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96508;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95930;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95533;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94466;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98460;


UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173762 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Ardendew
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173761 AND `ExtendedCost`=0 AND `type`=1); -- Glazed Glowberries
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173760 AND `ExtendedCost`=0 AND `type`=1); -- Sylberry Snowcake
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173759 AND `ExtendedCost`=0 AND `type`=1); -- Candied Brightbark
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173762 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Ardendew
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173761 AND `ExtendedCost`=0 AND `type`=1); -- Glazed Glowberries
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173760 AND `ExtendedCost`=0 AND `type`=1); -- Sylberry Snowcake
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=158554 AND `item`=173759 AND `ExtendedCost`=0 AND `type`=1); -- Candied Brightbark


DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (174020,172922,173503,173433,174705,174729,175054,175053,174731));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(174020, 1, 176544, 0, 0, 176726, 0, 0, 0, 0, 0), -- Capitán Prateq
(172922, 1, 180218, 0, 0, 0, 0, 0, 0, 0, 0), -- Margravina Sin'dane
(173503, 1, 176588, 0, 0, 0, 0, 0, 0, 0, 0), -- Acólito estudioso
(173433, 1, 181323, 0, 0, 0, 0, 0, 0, 0, 0), -- Acólita Nelesis
(174705, 1, 178118, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Amalthwyn
(174729, 1, 180159, 0, 0, 0, 0, 0, 0, 0, 0), -- Conquistador contagiado
(175054, 1, 178119, 0, 0, 0, 0, 0, 0, 0, 0), -- Defensor de la arboleda
(175053, 1, 178119, 0, 0, 0, 0, 0, 0, 0, 0), -- Defensor de la arboleda
(174731, 1, 180159, 0, 0, 0, 0, 0, 176025, 0, 0); -- Cuidador de arboledas poseído

UPDATE `creature_equip_template` SET `ItemID1`=180024 WHERE (`CreatureID`=158555 AND `ID`=2); -- Guardia de la reina de élite
UPDATE `creature_equip_template` SET `ItemID1`=176033 WHERE (`CreatureID`=158555 AND `ID`=1); -- Guardia de la reina de élite

DELETE FROM `gossip_menu` WHERE (`MenuId`=26337 AND `TextId`=41798) OR (`MenuId`=24905 AND `TextId`=39240) OR (`MenuId`=26554 AND `TextId`=42163) OR (`MenuId`=26553 AND `TextId`=42162) OR (`MenuId`=25657 AND `TextId`=40493);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(26337, 41798, 38134), -- 173503 (Acólito estudioso)
(24905, 39240, 38134), -- 160917 (Sombralúgubre)
(26554, 42163, 38134), -- 174705 (Lord Amalthwyn)
(26553, 42162, 38134), -- 174705 (Lord Amalthwyn)
(25657, 40493, 38134); -- 158553 (Mapirosa)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25513 AND `TextId`=40297); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25513 AND `TextId`=40297); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25513 AND `TextId`=40297); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25513 AND `TextId`=40297); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24842 AND `TextId`=39125); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=26161 AND `TextId`=27251); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25513 AND `TextId`=40297); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (24905,26553));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(24905, 0, 0, '<Montar a Sombralúgubre.>', 0, 38134),
(26553, 0, 0, '¿Qué es este lugar?', 0, 38134);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=26553 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(26553, 0, 26554, 0);



DELETE FROM `creature_template` WHERE `entry`=177513;
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `VehicleId`, `HoverHeight`) VALUES
(177513, 0, 60, 60, 35, 0, 1, 1.142857193946838378, 2000, 0, 32768, 2048, 0, 0, 0, 1); -- Mor'Kirk

UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=174606; -- A disembodied voice
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=173379; -- Needlenose
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=173378; -- Star Tail
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=173377; -- Faryl
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=173380; -- Brite
UPDATE `creature_template` SET `npcflag`=281474976710656, `unit_flags`=33536, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=170206; -- Venado rúnico
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=165910; -- Boggart nudorrama
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=163967; -- Asolador nudorrama
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=160074; -- Gorm rebanador
UPDATE `creature_template` SET `minlevel`=56, `maxlevel`=56, `faction`=190, `speed_walk`=0.400000005960464477, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=170227; -- Larva de gorm
UPDATE `creature_template` SET `minlevel`=56, `maxlevel`=56, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `dynamicflags`=128 WHERE `entry`=170250; -- Huevo de gorm
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=170205; -- Ciervorruna juvenil
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=172172; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=173539; -- Spell Bunny
UPDATE `creature_template` SET `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=168620; -- Acechasombras famélico
UPDATE `creature_template` SET `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=164802; -- Gormulino invasivo
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=169803; -- Feérico convertido
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=172838; -- Lar'eye
UPDATE `creature_template` SET `faction`=3161, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=172813; -- Ton'hamil
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2576, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=174395; -- Raspamédulas
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=174431; -- Sastrona cautiva
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=173582; -- Mantarraya contagiada prófuga
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=172606; -- Coalescencia fatal
UPDATE `creature_template` SET `faction`=3230, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=174020; -- Capitán Prateq
UPDATE `creature_template` SET `faction`=3160, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=160700; -- Gato espectral
UPDATE `creature_template` SET `faction`=3160, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=172922; -- Margravina Sin'dane
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=173573; -- Óculo decrépito
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=100698112 WHERE `entry`=174435; -- Muñeco de entrenamiento
UPDATE `creature_template` SET `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=174226; -- Valdemar
UPDATE `creature_template` SET `faction`=3161, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=173509; -- Tuetacánido animado
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=173505; -- Qexu
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=174377; -- Cor'lat
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=172604; -- Guardahuesos animado
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=172833; -- Antare
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=173563; -- Tomo errante
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=173507; -- Nhaurra
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=173564; -- Pluma traviesa
UPDATE `creature_template` SET `faction`=3160, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18432 WHERE `entry`=173503; -- Acólito estudioso
UPDATE `creature_template` SET `faction`=3161, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18432 WHERE `entry`=173433; -- Acólita Nelesis
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=120 WHERE `entry`=157952; -- Invisible Stalker: Skeleton
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=176219; -- Kearnen the Blade
UPDATE `creature_template` SET `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175789; -- Sombralúgubre
UPDATE `creature_template` SET `minlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161196; -- Arin'gore
UPDATE `creature_template` SET `minlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=67141696, `unit_flags2`=2048, `unit_flags3`=131072 WHERE `entry`=173045; -- Matriarca alaflagelada
UPDATE `creature_template` SET `minlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=173046; -- Vigilante de nido feroz
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=159750; -- Marrowbore Nest
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=159886; -- Hermana Chelicerae
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=159852; -- Barrera de telaraña
UPDATE `creature_template` SET `VehicleId`=7195 WHERE `entry`=168857; -- Transportista alacosida
UPDATE `creature_template` SET `gossip_menu_id`=24905, `minlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160917; -- Sombralúgubre
UPDATE `creature_template` SET `unit_flags`=33280 WHERE `entry`=165214; -- Recuperador belicosido
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=169699; -- Carroñero Bajard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=173274; -- Gorgemouth
UPDATE `creature_template` SET `unit_flags`=570688256 WHERE `entry`=169521; -- Aprendiz de gladiador
UPDATE `creature_template` SET `faction`=3172, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=157844; -- Messana
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=162732; -- Masa coagulante
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=165566; -- Mortojo
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=34816 WHERE `entry`=165440; -- Crecimiento fibroso
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=158566; -- Engendro de piojo de cadáver
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=32768 WHERE `entry`=158752; -- Colmisangre depredador
UPDATE `creature_template` SET `unit_flags3`=131072 WHERE `entry`=168148; -- Drolkrad
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=161599; -- Esclerosis burbujeante
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=163084; -- Examinadora Sahaari
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=16, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=166534; -- Ti'or
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=161559; -- Louison
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=166640; -- Au'larrynar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=163083; -- Evaluador Malus
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=159830; -- Au'narim
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=161710; -- Marcel Mullby
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=159824; -- Gunn Tragahuesos
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=159696; -- Rencissa, la Dínamo
UPDATE `creature_template` SET `unit_flags`=2147582208, `HoverHeight`=13.5 WHERE `entry`=162872; -- Xantuth la Contagiada
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=162873; -- Azmogal
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=159856; -- Peste virulenta
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=170191; -- Espora fibrosa
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872, `VehicleId`=7418 WHERE `entry`=176400; -- |cFFFFFFFF|rNecrópolis: Zerekriss
UPDATE `creature_template` SET `gossip_menu_id`=26693 WHERE `entry`=162666; -- Pathscribe Roh-Avonavi
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=156758; -- Criatura domesticada
UPDATE `creature_template` SET `unit_flags`=33817344 WHERE `entry`=121541; -- Ban-Lu
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=164173; -- Sinoescriba Roh-Tahl
UPDATE `creature_template` SET `unit_flags2`=4229120 WHERE `entry`=156698; -- Protector asistente
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=167195; -- Blodwyn
UPDATE `creature_template` SET `npcflag`=8193 WHERE `entry`=165701; -- Ceridwyn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=120, `maxlevel`=120 WHERE `entry`=156634; -- Winter Queen
UPDATE `creature_template` SET `gossip_menu_id`=26554, `faction`=3196, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=174705; -- Lord Amalthwyn
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=174732; -- Ingra Krazic
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=174729; -- Conquistador contagiado
UPDATE `creature_template` SET `faction`=3194, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=175054; -- Defensor de la arboleda
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=174730; -- Trepador invasivo
UPDATE `creature_template` SET `faction`=3194, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=175053; -- Defensor de la arboleda
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=174731; -- Cuidador de arboledas poseído
UPDATE `creature_template` SET `gossip_menu_id`=24842 WHERE `entry`=160292; -- Kewarin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=158544; -- Lord Herne
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=174572; -- Lillyensthoom
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=158543; -- Asistente Rociolux
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=173171; -- Viverista Noche Estrellada
UPDATE `creature_template` SET `gossip_menu_id`=25513, `npcflag`=2199023255555 WHERE `entry`=165702; -- Zayhad, la constructora
UPDATE `creature_template` SET `gossip_menu_id`=25657 WHERE `entry`=158553; -- Mapirosa
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=161509; -- Lady Baya Lunar
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=158555; -- Guardia de la reina de élite


DELETE FROM `quest_template` WHERE `ID` IN (60256 /*-Unknown-*/, 62866 /*-Unknown-*/, 61787 /*-Unknown-*/, 61867 /*-Unknown-*/, 61883 /*-Unknown-*/, 60786 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(60256, 2, 0, 837, 10565, 81, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 2097216, 0, 0, 0, 0, 0, 0, 184374, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 178593, 178592, 178590, 178591, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1594, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 38134), -- -Unknown-
(62866, 2, 0, 2060, -576, 0, 0, 0, 0, 1, 514800, 6, 1, 0, 348847, 0, 0, 0, 0, 1, 0, 35684360, 2099264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1864, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 38134), -- -Unknown-
(61787, 3, 0, 837, 10534, 115, 0, 0, 5, 1, 0, 0, 0, 0, 344547, 0, 0, 0, 0, 1, 0, 3735808, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2407, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1593, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 38134), -- -Unknown-
(61867, 3, 0, 837, 11462, 115, 0, 0, 5, 1, 0, 0, 0, 0, 344573, 0, 0, 0, 0, 1, 0, 3735808, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1622, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 38134), -- -Unknown-
(61883, 3, 0, 837, 10413, 115, 0, 0, 5, 1, 0, 0, 0, 0, 344554, 0, 0, 0, 0, 1, 0, 3735808, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1593, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 38134), -- -Unknown-
(60786, 3, 0, 2060, 11510, 109, 0, 0, 5, 1, 0, 0, 0, 0, 331361, 0, 0, 0, 0, 1, 0, 37290240, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2465, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 6842, 0, 18446744073709551615, 1579, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 38134); -- -Unknown-

UPDATE `quest_template` SET `RewardMoney`=386100, `RewardBonusMoney`=92600, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=57531; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=257400, `RewardBonusMoney`=6850, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31889; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60458; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60250; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62055; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62054; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097218, `VerifiedBuild`=38134 WHERE `ID`=60498; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56087; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47904; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=45381; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=45238; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=45175; -- -Unknown-
UPDATE `quest_template` SET `Flags`=536870920, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29335; -- -Unknown-
UPDATE `quest_template` SET `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27123; -- -Unknown-
UPDATE `quest_template` SET `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26013; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=7848; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60460; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097472, `VerifiedBuild`=38134 WHERE `ID`=58632; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56358; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=54438; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=24756; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=257400, `RewardBonusMoney`=61750, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60640; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60276; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60459; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=62217; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=62194; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=61511; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60765; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60429; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60402; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60291; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60237; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=58525; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=58374; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=57567; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=57565; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105409, `VerifiedBuild`=38134 WHERE `ID`=55609; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=257400, `RewardBonusMoney`=6850, `RewardSpell`=262916, `FlagsEx`=6299712, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=51813; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=43179; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=42422; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `VerifiedBuild`=38134 WHERE `ID`=42421; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=257400, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31591; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=58095; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=25740, `RewardBonusMoney`=7700 WHERE `ID`=62279; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=25740, `RewardBonusMoney`=7700 WHERE `ID`=62277; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=25740, `RewardBonusMoney`=7700 WHERE `ID`=62278; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=25740, `RewardBonusMoney`=7700 WHERE `ID`=62275; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=20220, `RewardBonusMoney`=65 WHERE `ID`=39733; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=20220, `RewardBonusMoney`=65 WHERE `ID`=39735; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=20220, `RewardBonusMoney`=65 WHERE `ID`=39731; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=20220, `RewardBonusMoney`=65 WHERE `ID`=39718; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=63073; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50792; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51681; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `RewardSpell`=271112, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51106; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51665; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `FlagsEx2`=2, `VerifiedBuild`=38134 WHERE `ID`=51500; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=347, `FlagsEx`=2097216, `RewardFactionID1`=1090, `Expansion`=6, `VerifiedBuild`=38134 WHERE `ID`=43478; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=52430; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=690, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=57340; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=690, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55889; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=52864; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50876; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=52794; -- -Unknown-
UPDATE `quest_template` SET `Flags`=37289984, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50846; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2129984, `VerifiedBuild`=38134 WHERE `ID`=55834; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `Flags`=37289984, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50853; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55264; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=691, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=54569; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50519; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=690, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=56048; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55900; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `RewardSpell`=282105, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51644; -- -Unknown-
UPDATE `quest_template` SET `Flags`=34144256, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51699; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=52316; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51874; -- -Unknown-
UPDATE `quest_template` SET `RewardSpell`=271185, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51609; -- -Unknown-
UPDATE `quest_template` SET `RewardSpell`=271180, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51422; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=49097; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51972; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=51166; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=52889; -- -Unknown-
UPDATE `quest_template` SET `RewardSpell`=270898, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51108; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=52140; -- -Unknown-
UPDATE `quest_template` SET `RewardSpell`=282105, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51411; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51639; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=691, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=54540; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55302; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=51619; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56036; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=51687; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=52456; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=52167; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2129984, `VerifiedBuild`=38134 WHERE `ID`=55720; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=52464; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=51576; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50857; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=50514; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=54622; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2129984, `VerifiedBuild`=38134 WHERE `ID`=55837; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=52054; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `RewardSpell`=271185, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=52884; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=391, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=44765; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=57338; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=54236; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=51178; -- -Unknown-
UPDATE `quest_template` SET `ContentTuningID`=464, `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=50747; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `FlagsEx2`=2, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=51035; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105412, `VerifiedBuild`=38134 WHERE `ID`=62899; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097220, `VerifiedBuild`=38134 WHERE `ID`=62900; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097220, `VerifiedBuild`=38134 WHERE `ID`=61550; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097220, `VerifiedBuild`=38134 WHERE `ID`=61542; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097220, `VerifiedBuild`=38134 WHERE `ID`=63008; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097220, `VerifiedBuild`=38134 WHERE `ID`=61541; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=62898; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62897; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62894; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62837; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=514800, `RewardBonusMoney`=77150, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60289; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=61355; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=257400, `RewardBonusMoney`=61750, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60287; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=62882; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62893; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62892; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62891; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62890; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60623; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=61549; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=57443; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=61603; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=61949; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=60655; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=59743; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2138176, `VerifiedBuild`=38134 WHERE `ID`=59826; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=58221; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=59642; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=61631; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60911; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60858; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60457; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=455280, `RewardBonusMoney`=1100 WHERE `ID`=48181; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097472, `VerifiedBuild`=38134 WHERE `ID`=63346; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2099264, `TreasurePickerID`=1874, `RewardCurrencyID1`=0, `RewardCurrencyID2`=0, `RewardCurrencyQty1`=0, `RewardCurrencyQty2`=0, `VerifiedBuild`=38134 WHERE `ID`=61331; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60388; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=23400, `RewardBonusMoney`=80 WHERE `ID`=51149; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=69206080, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=38134 WHERE `ID`=50605; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=35174; -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (398064 /*398064*/, 408877 /*408877*/, 406712 /*406712*/, 406765 /*406765*/, 406804 /*406804*/, 404688 /*404688*/, 404687 /*404687*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `VerifiedBuild`) VALUES
(398064, 60256, 1, 0, 0, 178575, 1, 0, 1, 0, 38134), -- 398064
(408877, 62866, 0, 0, 0, 175227, 20, 0, 0, 0, 38134), -- 408877
(406712, 61787, 11, 0, 0, 173130, 1, 0, 0, 0, 38134), -- 406712
(406765, 61867, 11, 0, 0, 173263, 1, 0, 0, 0, 38134), -- 406765
(406804, 61883, 11, 0, 0, 173315, 1, 0, 0, 0, 38134), -- 406804
(404688, 60786, 0, 1, 0, 163616, 45, 2, 0, 0, 38134), -- 404688
(404687, 60786, 0, 0, 1, 170125, 1, 0, 0, 0, 38134); -- 404687

UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392616; -- 392616
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269150; -- 269150
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269149; -- 269149
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269148; -- 269148
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269147; -- 269147
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269145; -- 269145
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398460; -- 398460
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398061; -- 398061
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407095; -- 407095
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407094; -- 407094
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405142; -- 405142
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=291117; -- 291117
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=287890; -- 287890
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=287714; -- 287714
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=287855; -- 287855
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=258965; -- 258965
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398458; -- 398458
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394592; -- 394592
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390659; -- 390659
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=387198; -- 387198
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399108; -- 399108
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398101; -- 398101
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398459; -- 398459
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407458; -- 407458
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407457; -- 407457
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407350; -- 407350
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407344; -- 407344
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407343; -- 407343
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406093; -- 406093
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406092; -- 406092
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404552; -- 404552
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404551; -- 404551
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398630; -- 398630
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398629; -- 398629
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398628; -- 398628
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398627; -- 398627
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398626; -- 398626
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398559; -- 398559
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398558; -- 398558
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398434; -- 398434
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398098; -- 398098
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398099; -- 398099
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398097; -- 398097
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397989; -- 397989
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397988; -- 397988
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407663; -- 407663
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407662; -- 407662
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407908; -- 407908
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395143; -- 395143
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395142; -- 395142
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394159; -- 394159
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392894; -- 392894
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389382; -- 389382
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341448; -- 341448
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=285073; -- 285073
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=284172; -- 284172
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=284171; -- 284171
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=268799; -- 268799
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407803; -- 407803
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407802; -- 407802
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407801; -- 407801
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=407800; -- 407800
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409169; -- 409169
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=333827; -- 333827
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388573; -- 388573
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336771; -- 336771
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336770; -- 336770
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336769; -- 336769
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336768; -- 336768
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336767; -- 336767
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336766; -- 336766
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336765; -- 336765
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336764; -- 336764
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334761; -- 334761
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336656; -- 336656
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=393814; -- 393814
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=340114; -- 340114
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338950; -- 338950
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392170; -- 392170
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389843; -- 389843
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=340126; -- 340126
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334148; -- 334148
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=340049; -- 340049
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339948; -- 339948
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339947; -- 339947
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334087; -- 334087
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334079; -- 334079
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389751; -- 389751
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334102; -- 334102
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388979; -- 388979
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388978; -- 388978
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=387633; -- 387633
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=332921; -- 332921
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390117; -- 390117
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389865; -- 389865
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=385397; -- 385397
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=385396; -- 385396
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336590; -- 336590
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336589; -- 336589
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336588; -- 336588
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336587; -- 336587
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336586; -- 336586
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336585; -- 336585
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336584; -- 336584
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337454; -- 337454
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338752; -- 338752
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337430; -- 337430
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336452; -- 336452
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341896; -- 341896
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341895; -- 341895
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341894; -- 341894
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341893; -- 341893
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335852; -- 335852
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335851; -- 335851
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335850; -- 335850
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335849; -- 335849
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335848; -- 335848
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337628; -- 337628
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334938; -- 334938
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334937; -- 334937
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=340227; -- 340227
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334765; -- 334765
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338455; -- 338455
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338447; -- 338447
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338446; -- 338446
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338445; -- 338445
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338444; -- 338444
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338443; -- 338443
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=385377; -- 385377
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=385376; -- 385376
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335759; -- 335759
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335758; -- 335758
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335757; -- 335757
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335756; -- 335756
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335755; -- 335755
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335754; -- 335754
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335753; -- 335753
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341806; -- 341806
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336572; -- 336572
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=387573; -- 387573
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389002; -- 389002
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389001; -- 389001
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336526; -- 336526
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336524; -- 336524
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336523; -- 336523
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390099; -- 390099
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336798; -- 336798
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339028; -- 339028
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339027; -- 339027
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=385847; -- 385847
UPDATE `quest_objectives` SET `StorageIndex`=4, `ObjectID`=142810, `Amount`=10, `ProgressBarWeight`=10, `VerifiedBuild`=38134 WHERE `ID`=340712; -- 340712
UPDATE `quest_objectives` SET `Type`=2, `StorageIndex`=3, `ObjectID`=296164, `Amount`=17, `ProgressBarWeight`=6, `VerifiedBuild`=38134 WHERE `ID`=340711; -- 340711
UPDATE `quest_objectives` SET `Type`=0, `StorageIndex`=2, `ObjectID`=131306, `Amount`=15, `ProgressBarWeight`=7, `VerifiedBuild`=38134 WHERE `ID`=340710; -- 340710
UPDATE `quest_objectives` SET `StorageIndex`=0, `ObjectID`=145535, `Amount`=25, `ProgressBarWeight`=4, `VerifiedBuild`=38134 WHERE `ID`=340709; -- 340709
UPDATE `quest_objectives` SET `ObjectID`=146408, `VerifiedBuild`=38134 WHERE `ID`=340708; -- 340708
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=338205; -- 338205
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389542; -- 389542
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339047; -- 339047
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336324; -- 336324
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336322; -- 336322
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334117; -- 334117
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=332916; -- 332916
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=387780; -- 387780
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389734; -- 389734
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337891; -- 337891
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337890; -- 337890
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=340210; -- 340210
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=286940; -- 286940
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392167; -- 392167
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386616; -- 386616
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386615; -- 386615
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386614; -- 386614
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386613; -- 386613
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386612; -- 386612
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386611; -- 386611
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=386610; -- 386610
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335007; -- 335007
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=333688; -- 333688
UPDATE `quest_objectives` SET `Amount`=10, `VerifiedBuild`=38134 WHERE `ID`=334573; -- 334573
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408912; -- 408912
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408911; -- 408911
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406260; -- 406260
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406236; -- 406236
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408996; -- 408996
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408908; -- 408908
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405412; -- 405412
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405384; -- 405384
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405356; -- 405356
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408881; -- 408881
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398086; -- 398086
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405800; -- 405800
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405294; -- 405294
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408989; -- 408989
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408965; -- 408965
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405406; -- 405406
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408857; -- 408857
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408896; -- 408896
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408906; -- 408906
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408959; -- 408959
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405281; -- 405281
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405280; -- 405280
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405271; -- 405271
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405270; -- 405270
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405269; -- 405269
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399076; -- 399076
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399075; -- 399075
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399074; -- 399074
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399073; -- 399073
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399072; -- 399072
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=399071; -- 399071
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406262; -- 406262
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406258; -- 406258
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392429; -- 392429
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392436; -- 392436
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406383; -- 406383
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=406869; -- 406869
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404431; -- 404431
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404430; -- 404430
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404429; -- 404429
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404428; -- 404428
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404427; -- 404427
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396874; -- 396874
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396873; -- 396873
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396872; -- 396872
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396871; -- 396871
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=397046; -- 397046
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409162; -- 409162
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396253; -- 396253
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396683; -- 396683
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396682; -- 396682
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396662; -- 396662
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408062; -- 408062
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408061; -- 408061
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405012; -- 405012
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405011; -- 405011
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404920; -- 404920
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=404949; -- 404949
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398461; -- 398461
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=405601; -- 405601
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398432; -- 398432
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336308; -- 336308
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273665; -- 273665
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273530; -- 273530

DELETE FROM `quest_visual_effect` WHERE (`Index`=0 AND `ID` IN (406712,406765,406804));
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(406712, 0, 15900, 38134),
(406765, 0, 15922, 38134),
(406804, 0, 15935, 38134);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269150 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269149 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269148 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269147 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269145 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405142 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405142 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=291117 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394592 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407457 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407343 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406092 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404552 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404551 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398097 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407908 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389382 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341448 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=409169 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333827 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336766 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336764 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336764 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393814 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340114 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=338950 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334087 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334079 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334102 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=388978 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335848 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335848 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335848 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335848 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337628 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334937 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341806 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341806 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336572 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389002 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389001 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=339028 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=339027 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389542 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336322 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=387780 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337891 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335007 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333688 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408912 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408911 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406260 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406236 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408996 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408908 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398086 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405294 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=12);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=11);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=10);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=9);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=8);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=7);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=6);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408965 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408857 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408857 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408896 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408906 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405281 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405280 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405271 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405270 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405269 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392429 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392429 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392429 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392429 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392436 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406869 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404687 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404431 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396874 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396873 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396872 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396871 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396871 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=409162 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408062 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408061 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405012 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405011 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404920 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273530 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56087 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61603 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=63346 AND `Idx`=0);

DELETE FROM `creature_template` WHERE `entry`=177513;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(177513, 0, 0, 'Mor\'Kirk', '', NULL, NULL, NULL, 8, 0, 0, 2, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 38134); -- Mor'Kirk


DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` IN (177513,177829));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(177513, 0, 97510, 1, 1, 38134), -- Mor'Kirk
(177829, 0, 93592, 1, 1, 38134); -- Ko'tul

UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171697 AND `Idx`=0); -- Purity
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170827 AND `Idx`=0); -- Barrera venari 04
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170819 AND `Idx`=0); -- Barrera venari
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=90212 AND `Idx`=0); -- Sunblade Micro-Defender
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=34); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=33); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=32); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=31); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=30); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=29); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=28); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=27); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=26); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=25); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=24); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=23); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=22); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=21); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=20); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=19); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=18); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=17); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=16); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=15); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=14); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=13); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=12); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=11); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=10); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=9); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=8); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=7); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=6); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=5); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=4); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=3); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=2); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=1); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175698 AND `Idx`=0); -- Doomed Soul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172631 AND `Idx`=1); -- Controlador 02: Devoradores de almas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172631 AND `Idx`=0); -- Controlador 02: Devoradores de almas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175012 AND `Idx`=0); -- Ikras, el Devorador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176308 AND `Idx`=1); -- Punto de agarre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176308 AND `Idx`=0); -- Punto de agarre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173640 AND `Idx`=0); -- Sabueso sombrío obediente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161846 AND `Idx`=0); -- Asesino
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=32642 AND `Idx`=0); -- Mojodishu
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=32641 AND `Idx`=0); -- Drix Llavenegra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170640 AND `Idx`=0); -- Alto señor Darion Mograine
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172110 AND `Idx`=0); -- Shan
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174776 AND `Idx`=0); -- Aynnstykny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169882 AND `Idx`=1); -- Llevar semilla onírica al corazón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169882 AND `Idx`=0); -- Llevar semilla onírica al corazón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174606 AND `Idx`=1); -- A disembodied voice
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174606 AND `Idx`=0); -- A disembodied voice
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477, `VerifiedBuild`=38134 WHERE (`CreatureID`=150357 AND `Idx`=0); -- Comet
UPDATE `creature_template_model` SET `CreatureDisplayID`=100727, `VerifiedBuild`=38134 WHERE (`CreatureID`=174170 AND `Idx`=0); -- Maw Haunt
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160501 AND `Idx`=0); -- Ysera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168075 AND `Idx`=0); -- Lenro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174139 AND `Idx`=0); -- Princesa Penicilia
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174138 AND `Idx`=1); -- Guardia fúngica real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174138 AND `Idx`=0); -- Guardia fúngica real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174131 AND `Idx`=0); -- Champibum
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174130 AND `Idx`=1); -- Champifauces enloquecido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174130 AND `Idx`=0); -- Champifauces enloquecido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168076 AND `Idx`=0); -- Limonero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170677 AND `Idx`=0); -- Ostara
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168032 AND `Idx`=0); -- Flwngyrr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174521 AND `Idx`=0); -- Gus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167505 AND `Idx`=0); -- Vigilante de nido alavelo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167507 AND `Idx`=0); -- Polluelo alavelo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169860 AND `Idx`=0); -- Pez
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169874 AND `Idx`=0); -- Matriarca alavelo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173380 AND `Idx`=0); -- Brite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173379 AND `Idx`=0); -- Needlenose
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173378 AND `Idx`=0); -- Star Tail
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173377 AND `Idx`=0); -- Faryl
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170790 AND `Idx`=0); -- Ave zancuda pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175858 AND `Idx`=1); -- Ermitaña polvorienta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175858 AND `Idx`=0); -- Ermitaña polvorienta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166180 AND `Idx`=5); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166180 AND `Idx`=4); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166180 AND `Idx`=3); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166180 AND `Idx`=2); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166180 AND `Idx`=1); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166180 AND `Idx`=0); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164040 AND `Idx`=0); -- Gormulino madrinocturno
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170206 AND `Idx`=3); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170206 AND `Idx`=2); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170206 AND `Idx`=1); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170206 AND `Idx`=0); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164033 AND `Idx`=0); -- Matriarca madriscura
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170442 AND `Idx`=0); -- Búho sombraluna
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169978 AND `Idx`=1); -- Valvaperla
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169978 AND `Idx`=0); -- Valvaperla
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176021 AND `Idx`=0); -- Starmoth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169979 AND `Idx`=1); -- Polilla estelar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169979 AND `Idx`=0); -- Polilla estelar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165910 AND `Idx`=0); -- Boggart nudorrama
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163967 AND `Idx`=0); -- Asolador nudorrama
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165603 AND `Idx`=0); -- Acechador invis
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170250 AND `Idx`=0); -- Huevo de gorm
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170227 AND `Idx`=2); -- Larva de gorm
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170227 AND `Idx`=1); -- Larva de gorm
UPDATE `creature_template_model` SET `CreatureDisplayID`=97252, `DisplayScale`=0.5, `VerifiedBuild`=38134 WHERE (`CreatureID`=170227 AND `Idx`=0); -- Larva de gorm
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169915 AND `Idx`=1); -- Acecharrunas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169915 AND `Idx`=0); -- Acecharrunas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160074 AND `Idx`=0); -- Gorm rebanador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170209 AND `Idx`=1); -- Estelavispa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170209 AND `Idx`=0); -- Estelavispa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169913 AND `Idx`=0); -- Cachorro de acecharrunas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170205 AND `Idx`=1); -- Ciervorruna juvenil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170205 AND `Idx`=0); -- Ciervorruna juvenil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165907 AND `Idx`=3); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165907 AND `Idx`=2); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165907 AND `Idx`=1); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165907 AND `Idx`=0); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170733 AND `Idx`=1); -- Putriérnaga hinchada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170733 AND `Idx`=0); -- Putriérnaga hinchada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170730 AND `Idx`=0); -- Polilla de Ardenweald marchita
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169206 AND `Idx`=1); -- Hidra devoradora
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169206 AND `Idx`=0); -- Hidra devoradora
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169210 AND `Idx`=1); -- Cuidador de semilla silvestre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169210 AND `Idx`=0); -- Cuidador de semilla silvestre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172172 AND `Idx`=1); -- Spell Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172172 AND `Idx`=0); -- Spell Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169205 AND `Idx`=0); -- Flor voraz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165857 AND `Idx`=1); -- Polilla estelar
UPDATE `creature_template_model` SET `CreatureDisplayID`=97271, `VerifiedBuild`=38134 WHERE (`CreatureID`=165857 AND `Idx`=0); -- Polilla estelar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165855 AND `Idx`=1); -- Rana lunar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165855 AND `Idx`=0); -- Rana lunar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171349 AND `Idx`=0); -- Estrellita
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165164 AND `Idx`=0); -- Lanra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160816 AND `Idx`=0); -- Rury
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170902 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170902 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158921 AND `Idx`=0); -- Guardiana Kota
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165159 AND `Idx`=1); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `CreatureDisplayID`=99685, `DisplayScale`=0.699999988079071044, `VerifiedBuild`=38134 WHERE (`CreatureID`=165159 AND `Idx`=0); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166248 AND `Idx`=1); -- Ermitaña solitaria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166248 AND `Idx`=0); -- Ermitaña solitaria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162446 AND `Idx`=0); -- Nolon
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162434 AND `Idx`=0); -- Alerín
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160814 AND `Idx`=0); -- Chufa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160813 AND `Idx`=0); -- Buuwo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158495 AND `Idx`=0); -- Fandu'lor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158494 AND `Idx`=0); -- Anir
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160077 AND `Idx`=1); -- Gormulino salvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160077 AND `Idx`=0); -- Gormulino salvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158487 AND `Idx`=0); -- Droman Tashmur
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166073 AND `Idx`=0); -- Polilla de Ardenweald superior
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165157 AND `Idx`=1); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `CreatureDisplayID`=99706, `VerifiedBuild`=38134 WHERE (`CreatureID`=165157 AND `Idx`=0); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164728 AND `Idx`=3); -- Heartwood Grove Evacuee
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164728 AND `Idx`=2); -- Heartwood Grove Evacuee
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164728 AND `Idx`=1); -- Heartwood Grove Evacuee
UPDATE `creature_template_model` SET `CreatureDisplayID`=95297, `VerifiedBuild`=38134 WHERE (`CreatureID`=164728 AND `Idx`=0); -- Heartwood Grove Evacuee
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160817 AND `Idx`=0); -- Slanknen
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171116 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `CreatureDisplayID`=99694, `DisplayScale`=0.699999988079071044, `VerifiedBuild`=38134 WHERE (`CreatureID`=171116 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165162 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165162 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165154 AND `Idx`=1); -- Protector de espíritus
UPDATE `creature_template_model` SET `CreatureDisplayID`=94869, `VerifiedBuild`=38134 WHERE (`CreatureID`=165154 AND `Idx`=0); -- Protector de espíritus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165155 AND `Idx`=1); -- Protector de espíritus
UPDATE `creature_template_model` SET `CreatureDisplayID`=95661, `VerifiedBuild`=38134 WHERE (`CreatureID`=165155 AND `Idx`=0); -- Protector de espíritus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160440 AND `Idx`=0); -- Brigdin
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165156 AND `Idx`=3); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165156 AND `Idx`=2); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165156 AND `Idx`=1); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `CreatureDisplayID`=95450, `VerifiedBuild`=38134 WHERE (`CreatureID`=165156 AND `Idx`=0); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173539 AND `Idx`=1); -- Spell Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173539 AND `Idx`=0); -- Spell Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169400 AND `Idx`=1); -- Regresar al camino
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169400 AND `Idx`=0); -- Regresar al camino
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165685 AND `Idx`=1); -- Pastador de la cañada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165685 AND `Idx`=0); -- Pastador de la cañada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164923 AND `Idx`=1); -- Zorrito de las laderas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164923 AND `Idx`=0); -- Zorrito de las laderas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164922 AND `Idx`=1); -- Vulpino de las laderas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164922 AND `Idx`=0); -- Vulpino de las laderas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168620 AND `Idx`=1); -- Acechasombras famélico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168620 AND `Idx`=0); -- Acechasombras famélico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168660 AND `Idx`=3); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168660 AND `Idx`=2); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168660 AND `Idx`=1); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168660 AND `Idx`=0); -- Alma de la naturaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157885 AND `Idx`=1); -- Vorkai poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157885 AND `Idx`=0); -- Vorkai poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157883 AND `Idx`=1); -- Sylvar poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157883 AND `Idx`=0); -- Sylvar poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164802 AND `Idx`=1); -- Gormulino invasivo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164802 AND `Idx`=0); -- Gormulino invasivo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=75065 AND `Idx`=1); -- Gota de sangre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=75065 AND `Idx`=0); -- Gota de sangre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171883 AND `Idx`=1); -- Blanco de misil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171883 AND `Idx`=0); -- Blanco de misil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164872 AND `Idx`=1); -- Saposcuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164872 AND `Idx`=0); -- Saposcuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176020 AND `Idx`=0); -- Decay Grub
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170768 AND `Idx`=1); -- Putriérnaga hinchada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170768 AND `Idx`=0); -- Putriérnaga hinchada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164875 AND `Idx`=1); -- Venado rúnico de ciénaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164875 AND `Idx`=0); -- Venado rúnico de ciénaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164874 AND `Idx`=1); -- Ciervo de ciénaga juvenil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164874 AND `Idx`=0); -- Ciervo de ciénaga juvenil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169812 AND `Idx`=1); -- Centinela convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169812 AND `Idx`=0); -- Centinela convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164924 AND `Idx`=0); -- Alamarchita
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164809 AND `Idx`=1); -- Putriérnaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164809 AND `Idx`=0); -- Putriérnaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170769 AND `Idx`=0); -- Polilla de Ardenweald marchita
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170734 AND `Idx`=1); -- Putriérnaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170734 AND `Idx`=0); -- Putriérnaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169803 AND `Idx`=5); -- Feérico convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169803 AND `Idx`=4); -- Feérico convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169803 AND `Idx`=3); -- Feérico convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169803 AND `Idx`=2); -- Feérico convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169803 AND `Idx`=1); -- Feérico convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169803 AND `Idx`=0); -- Feérico convertido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170446 AND `Idx`=1); -- Find Korenth Credit
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170446 AND `Idx`=0); -- Find Korenth Credit
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169136 AND `Idx`=0); -- Spriggan acechador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159030 AND `Idx`=3); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159030 AND `Idx`=2); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159030 AND `Idx`=1); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159030 AND `Idx`=0); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169169 AND `Idx`=1); -- Objetivo de hechizo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169169 AND `Idx`=0); -- Objetivo de hechizo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172965 AND `Idx`=0); -- Kill Credit: Night Lily Collected
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164700 AND `Idx`=1); -- Rana lunar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164700 AND `Idx`=0); -- Rana lunar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159029 AND `Idx`=1); -- Ciervorruna juvenil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159029 AND `Idx`=0); -- Ciervorruna juvenil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173388 AND `Idx`=0); -- Taelia Fordragón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173386 AND `Idx`=0); -- Calia Menethil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171821 AND `Idx`=0); -- Secutor Mevix
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162918 AND `Idx`=0); -- Escudero acompañante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162896 AND `Idx`=0); -- Vanguardia caballero de la muerte
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176368 AND `Idx`=0); -- Archivista Leonara
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176067 AND `Idx`=0); -- Dar Vattish
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176066 AND `Idx`=0); -- Darvel, el Frugal
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176065 AND `Idx`=0); -- Liawyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176064 AND `Idx`=0); -- Ayudante Mikaros
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171589 AND `Idx`=0); -- General Draven
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156504 AND `Idx`=0); -- Dragador Page
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164684 AND `Idx`=0); -- Cuidador Kah-Vosh
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164100 AND `Idx`=0); -- Emisario Ba'silk
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164099 AND `Idx`=0); -- Emisario Ba'julk
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164098 AND `Idx`=0); -- Emisario Ba'hask
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164078 AND `Idx`=0); -- Guardia venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173369 AND `Idx`=0); -- Artesano Ta'bone
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156791 AND `Idx`=0); -- Guardián Ta'saran
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=417 AND `Idx`=0); -- Felhunter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=71655 AND `Idx`=0); -- Zeradar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175042 AND `Idx`=4); -- Comerciante real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175042 AND `Idx`=3); -- Comerciante real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175042 AND `Idx`=2); -- Comerciante real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175042 AND `Idx`=1); -- Comerciante real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175042 AND `Idx`=0); -- Comerciante real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170607 AND `Idx`=4); -- Comerciante de información
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170607 AND `Idx`=3); -- Comerciante de información
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170607 AND `Idx`=2); -- Comerciante de información
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170607 AND `Idx`=1); -- Comerciante de información
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170607 AND `Idx`=0); -- Comerciante de información
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175218 AND `Idx`=5); -- Mensajero real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175218 AND `Idx`=4); -- Mensajero real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175218 AND `Idx`=3); -- Mensajero real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175218 AND `Idx`=2); -- Mensajero real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175218 AND `Idx`=1); -- Mensajero real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175218 AND `Idx`=0); -- Mensajero real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172838 AND `Idx`=0); -- Lar'eye
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172813 AND `Idx`=0); -- Ton'hamil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174395 AND `Idx`=0); -- Raspamédulas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=115634 AND `Idx`=1); -- Controlador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=115634 AND `Idx`=0); -- Controlador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174431 AND `Idx`=0); -- Sastrona cautiva
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173582 AND `Idx`=2); -- Mantarraya contagiada prófuga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173582 AND `Idx`=1); -- Mantarraya contagiada prófuga
UPDATE `creature_template_model` SET `CreatureDisplayID`=97657, `VerifiedBuild`=38134 WHERE (`CreatureID`=173582 AND `Idx`=0); -- Mantarraya contagiada prófuga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174020 AND `Idx`=0); -- Capitán Prateq
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172606 AND `Idx`=0); -- Coalescencia fatal
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160700 AND `Idx`=0); -- Gato espectral
UPDATE `creature_template_model` SET `DisplayScale`=1.5, `Probability`=0, `VerifiedBuild`=38134 WHERE (`CreatureID`=172922 AND `Idx`=0); -- Margravina Sin'dane
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173573 AND `Idx`=0); -- Óculo decrépito
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174435 AND `Idx`=0); -- Muñeco de entrenamiento
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172590 AND `Idx`=0); -- Campeón juraexánimes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170779 AND `Idx`=1); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170779 AND `Idx`=0); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174226 AND `Idx`=0); -- Valdemar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172591 AND `Idx`=0); -- Mortisombra de Xantuth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173495 AND `Idx`=0); -- Karaxi la Desertora
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172609 AND `Idx`=0); -- Mortisombra de Xantuth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172607 AND `Idx`=0); -- Mortisombra de Xantuth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172567 AND `Idx`=0); -- Mortisombra de Xantuth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173509 AND `Idx`=0); -- Tuetacánido animado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174377 AND `Idx`=0); -- Cor'lat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173505 AND `Idx`=0); -- Qexu
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172604 AND `Idx`=0); -- Guardahuesos animado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172833 AND `Idx`=0); -- Antare
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173563 AND `Idx`=3); -- Tomo errante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173563 AND `Idx`=2); -- Tomo errante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173563 AND `Idx`=1); -- Tomo errante
UPDATE `creature_template_model` SET `CreatureDisplayID`=46938, `DisplayScale`=2, `VerifiedBuild`=38134 WHERE (`CreatureID`=173563 AND `Idx`=0); -- Tomo errante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173507 AND `Idx`=0); -- Nhaurra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173564 AND `Idx`=0); -- Pluma traviesa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173503 AND `Idx`=1); -- Acólito estudioso
UPDATE `creature_template_model` SET `CreatureDisplayID`=94992, `VerifiedBuild`=38134 WHERE (`CreatureID`=173503 AND `Idx`=0); -- Acólito estudioso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172556 AND `Idx`=0); -- Oculus encantado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172601 AND `Idx`=1); -- Hechicero necrótico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172601 AND `Idx`=0); -- Hechicero necrótico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173433 AND `Idx`=0); -- Acólita Nelesis
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172596 AND `Idx`=1); -- Acólito necrótico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172596 AND `Idx`=0); -- Acólito necrótico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157952 AND `Idx`=1); -- Invisible Stalker: Skeleton
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157952 AND `Idx`=0); -- Invisible Stalker: Skeleton
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174654 AND `Idx`=0); -- Filo de hechizo rebelde
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172589 AND `Idx`=1); -- Centinela juraexánimes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172589 AND `Idx`=0); -- Centinela juraexánimes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172627 AND `Idx`=1); -- Esclavo animado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172627 AND `Idx`=0); -- Esclavo animado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172557 AND `Idx`=1); -- Guardián juraexánimes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172557 AND `Idx`=0); -- Guardián juraexánimes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167353 AND `Idx`=0); -- Garra estridente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161907 AND `Idx`=0); -- Baronesa Draka
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173489 AND `Idx`=3); -- Abominación cosida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173489 AND `Idx`=2); -- Abominación cosida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173489 AND `Idx`=1); -- Abominación cosida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173489 AND `Idx`=0); -- Abominación cosida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175022 AND `Idx`=0); -- Bleak Skitterer
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169512 AND `Idx`=0); -- Zángano putreaguijón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169190 AND `Idx`=0); -- Cerdo colmillo de hueso vengativo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169234 AND `Idx`=0); -- Cerdo colmillo de hueso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158442 AND `Idx`=0); -- Ácaro de tuétano
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158977 AND `Idx`=4); -- Saqueador huesofundido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158977 AND `Idx`=3); -- Saqueador huesofundido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158977 AND `Idx`=2); -- Saqueador huesofundido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158977 AND `Idx`=1); -- Saqueador huesofundido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158977 AND `Idx`=0); -- Saqueador huesofundido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176219 AND `Idx`=0); -- Kearnen the Blade
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175789 AND `Idx`=0); -- Sombralúgubre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169863 AND `Idx`=0); -- Filacteria de exánime
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161196 AND `Idx`=0); -- Arin'gore
UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089, `VerifiedBuild`=38134 WHERE (`CreatureID`=173045 AND `Idx`=0); -- Matriarca alaflagelada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159747 AND `Idx`=0); -- Reina pozamédula
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173046 AND `Idx`=0); -- Vigilante de nido feroz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159901 AND `Idx`=0); -- Arañuelo tejehuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159750 AND `Idx`=0); -- Marrowbore Nest
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159737 AND `Idx`=0); -- Emboscadora tejehuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159714 AND `Idx`=0); -- Trepadora pozamédula
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159886 AND `Idx`=0); -- Hermana Chelicerae
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159852 AND `Idx`=0); -- Barrera de telaraña
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159708 AND `Idx`=0); -- Glotona pozamédula
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161249 AND `Idx`=0); -- Sombralúgubre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168857 AND `Idx`=0); -- Transportista alacosida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168859 AND `Idx`=0); -- Barril recuperado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161985 AND `Idx`=0); -- Baronesa Vashj
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160917 AND `Idx`=0); -- Sombralúgubre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175478 AND `Idx`=1); -- Tauralus de manada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175478 AND `Idx`=0); -- Tauralus de manada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165214 AND `Idx`=1); -- Recuperador belicosido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165214 AND `Idx`=0); -- Recuperador belicosido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173274 AND `Idx`=0); -- Gorgemouth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169699 AND `Idx`=0); -- Carroñero Bajard
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169250 AND `Idx`=0); -- Obrera putreaguijón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169249 AND `Idx`=0); -- Zángano putreaguijón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160522 AND `Idx`=2); -- Ojo remanente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160522 AND `Idx`=1); -- Ojo remanente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160522 AND `Idx`=0); -- Ojo remanente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169395 AND `Idx`=0); -- Baba descerebrada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169184 AND `Idx`=0); -- Cachorro de colmillo de hueso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159916 AND `Idx`=0); -- Arrasadora tejehuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159893 AND `Idx`=0); -- Oseadora Mimm
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165376 AND `Idx`=0); -- Oseador Tolvar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169698 AND `Idx`=0); -- Kere Hojahermana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169521 AND `Idx`=2); -- Aprendiz de gladiador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169521 AND `Idx`=1); -- Aprendiz de gladiador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169521 AND `Idx`=0); -- Aprendiz de gladiador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168677 AND `Idx`=1); -- Colmillo de hueso carroñero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168677 AND `Idx`=0); -- Colmillo de hueso carroñero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157517 AND `Idx`=0); -- Eliera "ojos de mosca"
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157844 AND `Idx`=0); -- Messana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162732 AND `Idx`=0); -- Masa coagulante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174533 AND `Idx`=2); -- Arácnido desplazado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174533 AND `Idx`=1); -- Arácnido desplazado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174533 AND `Idx`=0); -- Arácnido desplazado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165566 AND `Idx`=0); -- Mortojo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164312 AND `Idx`=1); -- Alaflagelada con garfas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164312 AND `Idx`=0); -- Alaflagelada con garfas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=136402 AND `Idx`=3); -- Ur'zul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=136402 AND `Idx`=2); -- Ur'zul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=136402 AND `Idx`=1); -- Ur'zul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=136402 AND `Idx`=0); -- Ur'zul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166186 AND `Idx`=0); -- Novata muerta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=98035 AND `Idx`=2); -- Dreadstalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=98035 AND `Idx`=1); -- Dreadstalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=98035 AND `Idx`=0); -- Dreadstalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55659 AND `Idx`=2); -- Wild Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55659 AND `Idx`=1); -- Wild Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55659 AND `Idx`=0); -- Wild Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162727 AND `Idx`=0); -- Burbusangre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165549 AND `Idx`=0); -- Succión agria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165551 AND `Idx`=0); -- Piojo de cadáver succionante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158032 AND `Idx`=0); -- La Anatema
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=137744 AND `Idx`=1); -- Generic - Empty Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=137744 AND `Idx`=0); -- Generic - Empty Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=58964 AND `Idx`=0); -- Observer
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165440 AND `Idx`=0); -- Crecimiento fibroso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167040 AND `Idx`=0); -- Grandmaster Vole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158053 AND `Idx`=0); -- Madre de piojos de cadáver
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166370 AND `Idx`=0); -- Madre del enjambre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158387 AND `Idx`=0); -- Avispón fétido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170095 AND `Idx`=0); -- Aprendiz de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165561 AND `Idx`=2); -- Piojos de cadáver hinchados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165561 AND `Idx`=1); -- Piojos de cadáver hinchados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165561 AND `Idx`=0); -- Piojos de cadáver hinchados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158566 AND `Idx`=0); -- Engendro de piojo de cadáver
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158752 AND `Idx`=0); -- Colmisangre depredador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165473 AND `Idx`=0); -- Colmisangre alfa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=95061 AND `Idx`=0); -- Elemental de fuego superior
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=61029 AND `Idx`=0); -- Elemental de fuego primigenio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168226 AND `Idx`=0); -- Earl el ciego
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168440 AND `Idx`=2); -- Aprendiz de gladiador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168440 AND `Idx`=1); -- Aprendiz de gladiador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168440 AND `Idx`=0); -- Aprendiz de gladiador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=78116 AND `Idx`=1); -- Elemental de agua
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=78116 AND `Idx`=0); -- Elemental de agua
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172854 AND `Idx`=0); -- Dredger Butler
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162937 AND `Idx`=0); -- Señora Dyrax
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170190 AND `Idx`=0); -- Tótem de agarre de las sombras
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166663 AND `Idx`=0); -- Auxiliar
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=38134 WHERE (`CreatureID`=159239 AND `Idx`=0); -- Neena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168148 AND `Idx`=0); -- Drolkrad
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172633 AND `Idx`=1); -- Acechador de volcán
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172633 AND `Idx`=0); -- Acechador de volcán
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173994 AND `Idx`=0); -- Will of Remornia
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168147 AND `Idx`=0); -- Sabriel, la Rajahuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163224 AND `Idx`=1); -- Arena - Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163224 AND `Idx`=0); -- Arena - Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172656 AND `Idx`=1); -- Acechador del centro de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172656 AND `Idx`=0); -- Acechador del centro de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161599 AND `Idx`=0); -- Esclerosis burbujeante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158071 AND `Idx`=0); -- Animado descerebrado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162899 AND `Idx`=0); -- Gran maestro Vole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166253 AND `Idx`=0); -- Gran maestro Vole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161597 AND `Idx`=1); -- Baba arrasadora
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161597 AND `Idx`=0); -- Baba arrasadora
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162813 AND `Idx`=1); -- Aprendiz de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162813 AND `Idx`=0); -- Aprendiz de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163824 AND `Idx`=0); -- Guardiana esquelética
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163084 AND `Idx`=0); -- Examinadora Sahaari
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162816 AND `Idx`=1); -- Generic Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162816 AND `Idx`=0); -- Generic Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166331 AND `Idx`=0); -- Zo'umlo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166534 AND `Idx`=0); -- Ti'or
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166321 AND `Idx`=0); -- Proveedor de especímenes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155654 AND `Idx`=1); -- Spell Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155654 AND `Idx`=0); -- Spell Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166640 AND `Idx`=0); -- Au'larrynar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166545 AND `Idx`=0); -- Instructor Erix
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166540 AND `Idx`=4); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166540 AND `Idx`=3); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166540 AND `Idx`=2); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166540 AND `Idx`=1); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166540 AND `Idx`=0); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163043 AND `Idx`=2); -- Espectadora de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163043 AND `Idx`=1); -- Espectadora de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163043 AND `Idx`=0); -- Espectadora de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163019 AND `Idx`=0); -- Gran maestro Vole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161585 AND `Idx`=0); -- Huesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161559 AND `Idx`=0); -- Louison
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159833 AND `Idx`=0); -- So'narynar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175392 AND `Idx`=0); -- Trampero Hickman
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166400 AND `Idx`=4); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166400 AND `Idx`=3); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166400 AND `Idx`=2); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166400 AND `Idx`=1); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166400 AND `Idx`=0); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163083 AND `Idx`=0); -- Evaluador Malus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161710 AND `Idx`=0); -- Marcel Mullby
UPDATE `creature_template_model` SET `CreatureDisplayID`=100590, `VerifiedBuild`=38134 WHERE (`CreatureID`=159830 AND `Idx`=0); -- Au'narim
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169795 AND `Idx`=0); -- Avispa cinérea zombi
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166562 AND `Idx`=0); -- Talzedo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166552 AND `Idx`=0); -- Jessana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160256 AND `Idx`=0); -- Desguazadora Minoire
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163032 AND `Idx`=1); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163032 AND `Idx`=0); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162588 AND `Idx`=0); -- Picartílago
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174652 AND `Idx`=1); -- Animated Cruor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174652 AND `Idx`=0); -- Animated Cruor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169830 AND `Idx`=0); -- Larva parasitaria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159689 AND `Idx`=0); -- Sobrestante Kalvaros
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164507 AND `Idx`=3); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164507 AND `Idx`=2); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164507 AND `Idx`=1); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164507 AND `Idx`=0); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159824 AND `Idx`=0); -- Gunn Tragahuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159825 AND `Idx`=1); -- Fan de Tragahuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159825 AND `Idx`=0); -- Fan de Tragahuesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159822 AND `Idx`=1); -- Fan de Dínamo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159822 AND `Idx`=0); -- Fan de Dínamo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159696 AND `Idx`=0); -- Rencissa, la Dínamo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164508 AND `Idx`=1); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164508 AND `Idx`=0); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164492 AND `Idx`=1); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164492 AND `Idx`=0); -- Espectador de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=11); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=10); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=9); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=8); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=7); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=6); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=5); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=4); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=3); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=2); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=1); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163041 AND `Idx`=0); -- Prospector de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158642 AND `Idx`=0); -- Carne de alma podrida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168216 AND `Idx`=1); -- Ancestro chillavientos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168216 AND `Idx`=0); -- Ancestro chillavientos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175394 AND `Idx`=0); -- Ja'red Haze
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163030 AND `Idx`=4); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163030 AND `Idx`=3); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163030 AND `Idx`=2); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163030 AND `Idx`=1); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163030 AND `Idx`=0); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166226 AND `Idx`=3); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166226 AND `Idx`=2); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166226 AND `Idx`=1); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166226 AND `Idx`=0); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162477 AND `Idx`=1); -- Tauralus piel de sangre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162477 AND `Idx`=0); -- Tauralus piel de sangre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175393 AND `Idx`=0); -- Eli'ot Roush
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166570 AND `Idx`=0); -- Avrilla Angar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166568 AND `Idx`=0); -- Hellinka
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162872 AND `Idx`=0); -- Xantuth la Contagiada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161733 AND `Idx`=0); -- Anzio, el Infalible
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161697 AND `Idx`=0); -- Fogonero Marahueso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164833 AND `Idx`=1); -- Tauralus de manada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164833 AND `Idx`=0); -- Tauralus de manada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161696 AND `Idx`=0); -- Acerón Wilhelm
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166567 AND `Idx`=0); -- Mímico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166565 AND `Idx`=0); -- Zandara
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173003 AND `Idx`=0); -- Nalcorn Talsen
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170542 AND `Idx`=3); -- Duelistas veteranos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170542 AND `Idx`=2); -- Duelistas veteranos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170542 AND `Idx`=1); -- Duelistas veteranos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170542 AND `Idx`=0); -- Duelistas veteranos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169697 AND `Idx`=0); -- Acerino Obernolte
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166564 AND `Idx`=3); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166564 AND `Idx`=2); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166564 AND `Idx`=1); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166564 AND `Idx`=0); -- Aprendiz incansable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166420 AND `Idx`=0); -- Varissa Stubin
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161712 AND `Idx`=0); -- Nana Gorrorojo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161702 AND `Idx`=0); -- Slumbar Valorum
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157540 AND `Idx`=0); -- Guardián alado Alamar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=93008 AND `Idx`=1); -- Gusano de cadáver
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=93008 AND `Idx`=0); -- Gusano de cadáver
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166424 AND `Idx`=1); -- Obrero de la Arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166424 AND `Idx`=0); -- Obrero de la Arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=7); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=6); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=5); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=4); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=3); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=2); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=1); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161757 AND `Idx`=0); -- Contendiente de la arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169055 AND `Idx`=0); -- Raspamédulas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166421 AND `Idx`=0); -- Alaflagelada entrenado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162873 AND `Idx`=0); -- Azmogal
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162853 AND `Idx`=0); -- Urtz el Irrompible
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170496 AND `Idx`=0); -- Shanir Cortavenas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164997 AND `Idx`=0); -- Pellizcador de cadáveres
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166423 AND `Idx`=0); -- Alaflagelada entrenado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176024 AND `Idx`=2); -- Crawbat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176024 AND `Idx`=1); -- Crawbat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176024 AND `Idx`=0); -- Crawbat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173200 AND `Idx`=0); -- Bleak Skitterer
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168196 AND `Idx`=1); -- Plaga virulenta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168196 AND `Idx`=0); -- Plaga virulenta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175100 AND `Idx`=0); -- Un cuerpo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170191 AND `Idx`=0); -- Espora fibrosa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169751 AND `Idx`=0); -- Avispa cinérea
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159856 AND `Idx`=1); -- Peste virulenta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159856 AND `Idx`=0); -- Peste virulenta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176023 AND `Idx`=2); -- Crawbat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176023 AND `Idx`=1); -- Crawbat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176023 AND `Idx`=0); -- Crawbat
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175097 AND `Idx`=0); -- Corcel esquelético
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175095 AND `Idx`=0); -- Gladiador arrasador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174653 AND `Idx`=0); -- Larva purulenta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174223 AND `Idx`=0); -- Gato con botas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167435 AND `Idx`=1); -- Tornado de huesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167435 AND `Idx`=0); -- Tornado de huesos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162258 AND `Idx`=1); -- Chillavientos voraz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162258 AND `Idx`=0); -- Chillavientos voraz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175021 AND `Idx`=0); -- Pulsating Maggot
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=6); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=5); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=4); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=3); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=2); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=1); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157671 AND `Idx`=0); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170971 AND `Idx`=0); -- Tauralus listo para la batalla
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167273 AND `Idx`=0); -- Tiradora certera de placas óseas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162259 AND `Idx`=0); -- Cría de chillavientos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161890 AND `Idx`=0); -- Carroñero carne sajada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167747 AND `Idx`=0); -- Aliya Jubón
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167743 AND `Idx`=0); -- Vassili Tirolibre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166908 AND `Idx`=0); -- Malifis
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169634 AND `Idx`=1); -- Veterano almapartida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169634 AND `Idx`=0); -- Veterano almapartida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167355 AND `Idx`=0); -- Pulsating Maggot
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167354 AND `Idx`=0); -- Rachis retorcido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161881 AND `Idx`=2); -- Espinacero herido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161881 AND `Idx`=1); -- Espinacero herido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161881 AND `Idx`=0); -- Espinacero herido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156558 AND `Idx`=1); -- Generic - Empty Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156558 AND `Idx`=0); -- Generic - Empty Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165017 AND `Idx`=1); -- Inventor de plagas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165017 AND `Idx`=0); -- Inventor de plagas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173000 AND `Idx`=0); -- Madeleine Roux
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164221 AND `Idx`=0); -- Kevin
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160419 AND `Idx`=0); -- Limo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160418 AND `Idx`=0); -- Moc
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165350 AND `Idx`=0); -- Lyra Granizormenta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172173 AND `Idx`=0); -- Intérprete de disputas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167649 AND `Idx`=0); -- Kresto Piromuerte
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167645 AND `Idx`=0); -- Jericó Murallada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165321 AND `Idx`=0); -- Merick Feldcicatriz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164667 AND `Idx`=1); -- Prime Shieldguard
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164667 AND `Idx`=0); -- Prime Shieldguard
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174491 AND `Idx`=0); -- Probador de hierro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174488 AND `Idx`=0); -- Defensor inquebrantable
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174484 AND `Idx`=0); -- Campeón inamovible
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176400 AND `Idx`=1); -- |cFFFFFFFF|rNecrópolis: Zerekriss
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176400 AND `Idx`=0); -- |cFFFFFFFF|rNecrópolis: Zerekriss
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156479 AND `Idx`=0); -- Guardián de la riqueza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171242 AND `Idx`=0); -- Hungry Burrower
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174564 AND `Idx`=0); -- Cuidador Kah-Rahm
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159200 AND `Idx`=0); -- Unidad
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175066 AND `Idx`=3); -- Proveedor de especímenes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175066 AND `Idx`=2); -- Proveedor de especímenes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175066 AND `Idx`=1); -- Proveedor de especímenes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175066 AND `Idx`=0); -- Proveedor de especímenes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175019 AND `Idx`=1); -- Transportista craneopálido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175019 AND `Idx`=0); -- Transportista craneopálido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173370 AND `Idx`=0); -- Adquiriente Ta'wah
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169524 AND `Idx`=0); -- Adquiriente Ta'gosh
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166284 AND `Idx`=0); -- Cubo de almacenamiento dimensional
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165796 AND `Idx`=0); -- Mozo de cuadra Ta'shno
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156664 AND `Idx`=0); -- Guardabóvedas Ta'khis
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156663 AND `Idx`=0); -- Tejedor de distorsión Ta'oren
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175067 AND `Idx`=3); -- Guerrero elegido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175067 AND `Idx`=2); -- Guerrero elegido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175067 AND `Idx`=1); -- Guerrero elegido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175067 AND `Idx`=0); -- Guerrero elegido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175036 AND `Idx`=0); -- Llangystor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173318 AND `Idx`=0); -- Especialista en logística
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166312 AND `Idx`=0); -- Ta'mari
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175083 AND `Idx`=0); -- Capitán guardia de espadas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158637 AND `Idx`=0); -- Orbe guía
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175080 AND `Idx`=0); -- Capitán protector
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173330 AND `Idx`=0); -- Custodio asistente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173327 AND `Idx`=0); -- Escudero asistente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159478 AND `Idx`=0); -- Tal-Inara
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175082 AND `Idx`=2); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175082 AND `Idx`=1); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175082 AND `Idx`=0); -- Guardia de espadas supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171822 AND `Idx`=1); -- Escudero supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171822 AND `Idx`=0); -- Escudero supremo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=54638 AND `Idx`=1); -- Generic Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=54638 AND `Idx`=0); -- Generic Bunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175215 AND `Idx`=4); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175215 AND `Idx`=3); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175215 AND `Idx`=2); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175215 AND `Idx`=1); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175215 AND `Idx`=0); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170310 AND `Idx`=1); -- Kill Credit: Meet with Kleia
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170310 AND `Idx`=0); -- Kill Credit: Meet with Kleia
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165654 AND `Idx`=0); -- La Árbitra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170256 AND `Idx`=1); -- Kill Credit: Go to Maw
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170256 AND `Idx`=0); -- Kill Credit: Go to Maw
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=29238 AND `Idx`=0); -- Scourge Haunt
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170557 AND `Idx`=0); -- Protector asistente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173354 AND `Idx`=0); -- Deceased Monkey
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175081 AND `Idx`=0); -- Comandante de los Necroseñores
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156768 AND `Idx`=0); -- Sobrestante Ta'readon
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173355 AND `Idx`=0); -- Trepador automatizado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173353 AND `Idx`=0); -- Pico automatizado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175214 AND `Idx`=0); -- Guardapiedra venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173356 AND `Idx`=0); -- Alas automatizadas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175035 AND `Idx`=0); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175016 AND `Idx`=5); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175016 AND `Idx`=4); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175016 AND `Idx`=3); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175016 AND `Idx`=2); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175016 AND `Idx`=1); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175016 AND `Idx`=0); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173357 AND `Idx`=0); -- Guardián Ta'hilt
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173352 AND `Idx`=0); -- Deceased Monkey
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165657 AND `Idx`=0); -- Cuidador Kah-Syne
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164596 AND `Idx`=0); -- Custodio asistente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162929 AND `Idx`=0); -- Funcionario acompañante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162928 AND `Idx`=0); -- Sobrestante Kah-Delen
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=26125 AND `Idx`=3); -- Necrófago resucitado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=26125 AND `Idx`=2); -- Necrófago resucitado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=26125 AND `Idx`=1); -- Necrófago resucitado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=26125 AND `Idx`=0); -- Necrófago resucitado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158259 AND `Idx`=0); -- Abominación
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175212 AND `Idx`=0); -- Espíritu de feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=142668 AND `Idx`=0); -- Mercader Maku
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=142666 AND `Idx`=0); -- Coleccionista Unta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173348 AND `Idx`=0); -- Artesano coral
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164352 AND `Idx`=0); -- Comerciante Ba'telk
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156688 AND `Idx`=0); -- Anfitrión Ta'rela
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=62822 AND `Idx`=0); -- Primo Manos Torpes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164685 AND `Idx`=0); -- Cuidador Kah-Lod
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173301 AND `Idx`=0); -- Curador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167881 AND `Idx`=0); -- Ta'lan, el anticuario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173305 AND `Idx`=0); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165405 AND `Idx`=0); -- Emisario Ba'solo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164173 AND `Idx`=0); -- Sinoescriba Roh-Tahl
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164686 AND `Idx`=0); -- Cuidador Kah-Sar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156735 AND `Idx`=0); -- Barbero Ta'visage
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175327 AND `Idx`=0); -- Escriba del pasado Roh-Idlab
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175222 AND `Idx`=5); -- Observador real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175222 AND `Idx`=4); -- Observador real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175222 AND `Idx`=3); -- Observador real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175222 AND `Idx`=2); -- Observador real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175222 AND `Idx`=1); -- Observador real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175222 AND `Idx`=0); -- Observador real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166307 AND `Idx`=0); -- Cuidador Kah-Toll
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=62821 AND `Idx`=0); -- Místico Gorro de Ave
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173304 AND `Idx`=4); -- Facilitador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173304 AND `Idx`=3); -- Facilitador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173304 AND `Idx`=2); -- Facilitador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173304 AND `Idx`=1); -- Facilitador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173304 AND `Idx`=0); -- Facilitador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176545 AND `Idx`=0); -- Vermis de ánima
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175017 AND `Idx`=4); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175017 AND `Idx`=3); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175017 AND `Idx`=2); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175017 AND `Idx`=1); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175017 AND `Idx`=0); -- Ascendiente kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173325 AND `Idx`=0); -- Facilitador discreto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162666 AND `Idx`=0); -- Pathscribe Roh-Avonavi
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175206 AND `Idx`=5); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175206 AND `Idx`=4); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175206 AND `Idx`=3); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175206 AND `Idx`=2); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175206 AND `Idx`=1); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175206 AND `Idx`=0); -- Enlace real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166061 AND `Idx`=0); -- Funcionario acompañante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164353 AND `Idx`=0); -- Comerciante Ba'gor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156769 AND `Idx`=0); -- Guardián Ta'hult
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175018 AND `Idx`=5); -- Aristócrata venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175018 AND `Idx`=4); -- Aristócrata venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175018 AND `Idx`=3); -- Aristócrata venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175018 AND `Idx`=2); -- Aristócrata venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175018 AND `Idx`=1); -- Aristócrata venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175018 AND `Idx`=0); -- Aristócrata venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173350 AND `Idx`=0); -- Ba'vol
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156734 AND `Idx`=2); -- Facilitador discreto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156734 AND `Idx`=1); -- Facilitador discreto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156734 AND `Idx`=0); -- Facilitador discreto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173302 AND `Idx`=0); -- Ensamblador culinario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172702 AND `Idx`=0); -- Facilitador de mercado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156758 AND `Idx`=3); -- Criatura domesticada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156758 AND `Idx`=2); -- Criatura domesticada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156758 AND `Idx`=1); -- Criatura domesticada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156758 AND `Idx`=0); -- Criatura domesticada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173118 AND `Idx`=5); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173118 AND `Idx`=4); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173118 AND `Idx`=3); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173118 AND `Idx`=2); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173118 AND `Idx`=1); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173118 AND `Idx`=0); -- Facilitador de comercio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175087 AND `Idx`=1); -- Noble venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175087 AND `Idx`=0); -- Noble venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175207 AND `Idx`=5); -- Asistente real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175207 AND `Idx`=4); -- Asistente real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175207 AND `Idx`=3); -- Asistente real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175207 AND `Idx`=2); -- Asistente real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175207 AND `Idx`=1); -- Asistente real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175207 AND `Idx`=0); -- Asistente real
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165403 AND `Idx`=0); -- Opulencia Ba'hare
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=121541 AND `Idx`=0); -- Ban-Lu
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175216 AND `Idx`=5); -- Comerciante venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175216 AND `Idx`=4); -- Comerciante venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175216 AND `Idx`=3); -- Comerciante venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175216 AND `Idx`=2); -- Comerciante venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175216 AND `Idx`=1); -- Comerciante venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175216 AND `Idx`=0); -- Comerciante venthyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173367 AND `Idx`=0); -- Facilitador de saneamiento
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175208 AND `Idx`=5); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175208 AND `Idx`=4); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175208 AND `Idx`=3); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175208 AND `Idx`=2); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175208 AND `Idx`=1); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175208 AND `Idx`=0); -- Auxiliar kyrian
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156698 AND `Idx`=0); -- Protector asistente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167880 AND `Idx`=0); -- Buscador Ta'sul
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164803 AND `Idx`=0); -- Protector supremo de la bóveda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164123 AND `Idx`=0); -- Escriba asistente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171796 AND `Idx`=3); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171796 AND `Idx`=2); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171796 AND `Idx`=1); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171796 AND `Idx`=0); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175020 AND `Idx`=3); -- Hablarrunas de los Necroseñores
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175020 AND `Idx`=2); -- Hablarrunas de los Necroseñores
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175020 AND `Idx`=1); -- Hablarrunas de los Necroseñores
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175020 AND `Idx`=0); -- Hablarrunas de los Necroseñores
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173300 AND `Idx`=5); -- Administrador de mercados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173300 AND `Idx`=4); -- Administrador de mercados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173300 AND `Idx`=3); -- Administrador de mercados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173300 AND `Idx`=2); -- Administrador de mercados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173300 AND `Idx`=1); -- Administrador de mercados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173300 AND `Idx`=0); -- Administrador de mercados
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173364 AND `Idx`=0); -- Especialista en seguridad
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162880 AND `Idx`=0); -- Señora Dyrax
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167195 AND `Idx`=0); -- Blodwyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165701 AND `Idx`=0); -- Ceridwyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=143622 AND `Idx`=2); -- Wild Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=143622 AND `Idx`=1); -- Wild Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=143622 AND `Idx`=0); -- Wild Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=34337 AND `Idx`=0); -- El Jefe de correos
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=58965 AND `Idx`=0); -- Wrathguard
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156634 AND `Idx`=0); -- Winter Queen
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175519 AND `Idx`=0); -- Pústula espumosa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=58960 AND `Idx`=0); -- Voidlord
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=3527 AND `Idx`=0); -- Tótem Corriente de sanación
UPDATE `creature_template_model` SET `DisplayScale`=0.85000002384185791, `VerifiedBuild`=38134 WHERE (`CreatureID`=170026 AND `Idx`=0); -- Nigromante novato
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175579 AND `Idx`=0); -- Guardiana feérica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174705 AND `Idx`=0); -- Lord Amalthwyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170045 AND `Idx`=0); -- Dragador goteante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=7); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=6); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=5); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=4); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=3); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=2); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=1); -- Cazadora veterana
UPDATE `creature_template_model` SET `CreatureDisplayID`=95866, `VerifiedBuild`=38134 WHERE (`CreatureID`=175439 AND `Idx`=0); -- Cazadora veterana
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=132366 AND `Idx`=0); -- Mailemental
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174729 AND `Idx`=2); -- Conquistador contagiado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174729 AND `Idx`=1); -- Conquistador contagiado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174729 AND `Idx`=0); -- Conquistador contagiado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169960 AND `Idx`=1); -- Llevar semilla onírica a la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169960 AND `Idx`=0); -- Llevar semilla onírica a la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=23); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=22); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=21); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=20); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=19); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=18); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=17); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=16); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=15); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=14); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=13); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=12); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=11); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=10); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=9); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=8); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=7); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=6); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=5); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=4); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=3); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=2); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=1); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `CreatureDisplayID`=97593, `VerifiedBuild`=38134 WHERE (`CreatureID`=175054 AND `Idx`=0); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=15); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=14); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=13); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=12); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=11); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=10); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=9); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=8); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=7); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=6); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=5); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=4); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=3); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=2); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=1); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `CreatureDisplayID`=95258, `VerifiedBuild`=38134 WHERE (`CreatureID`=175053 AND `Idx`=0); -- Defensor de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174731 AND `Idx`=5); -- Cuidador de arboledas poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174731 AND `Idx`=4); -- Cuidador de arboledas poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174731 AND `Idx`=3); -- Cuidador de arboledas poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174731 AND `Idx`=2); -- Cuidador de arboledas poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174731 AND `Idx`=1); -- Cuidador de arboledas poseído
UPDATE `creature_template_model` SET `CreatureDisplayID`=99061, `VerifiedBuild`=38134 WHERE (`CreatureID`=174731 AND `Idx`=0); -- Cuidador de arboledas poseído
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174730 AND `Idx`=0); -- Trepador invasivo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173906 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173906 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174704 AND `Idx`=5); -- Guardián pacífico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174704 AND `Idx`=4); -- Guardián pacífico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174704 AND `Idx`=3); -- Guardián pacífico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174704 AND `Idx`=2); -- Guardián pacífico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174704 AND `Idx`=1); -- Guardián pacífico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174704 AND `Idx`=0); -- Guardián pacífico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172815 AND `Idx`=0); -- Saltaestrellas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172966 AND `Idx`=1); -- Correbruma salvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172966 AND `Idx`=0); -- Correbruma salvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174713 AND `Idx`=0); -- Alabrillo crepuscular
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172945 AND `Idx`=0); -- Alabrillo del alba
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174837 AND `Idx`=0); -- Acaparador de Bosquerruna
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172934 AND `Idx`=1); -- Venado rúnico ramalvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172934 AND `Idx`=0); -- Venado rúnico ramalvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172723 AND `Idx`=0); -- Vulpino cachorro de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165690 AND `Idx`=0); -- Potro de la cañada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172722 AND `Idx`=0); -- Merodeador de la arboleda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172979 AND `Idx`=0); -- Esporeadora Almíbar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165901 AND `Idx`=1); -- Estelavispa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165901 AND `Idx`=0); -- Estelavispa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176019 AND `Idx`=0); -- Verdant Kit
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173106 AND `Idx`=1); -- Luciérnaga de del sotobosque
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173106 AND `Idx`=0); -- Luciérnaga de del sotobosque
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174777 AND `Idx`=0); -- Saltador frondavelada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170039 AND `Idx`=0); -- Polluela de auxiliar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166187 AND `Idx`=3); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166187 AND `Idx`=2); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166187 AND `Idx`=1); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166187 AND `Idx`=0); -- Venado rúnico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167503 AND `Idx`=0); -- Guardián alavelo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174634 AND `Idx`=0); -- Littlefield
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174633 AND `Idx`=0); -- Zeke'Tur
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174632 AND `Idx`=0); -- Kimreed
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173766 AND `Idx`=0); -- Polvoriento arrasador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169862 AND `Idx`=1); -- Croador reluciente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169862 AND `Idx`=0); -- Croador reluciente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168513 AND `Idx`=0); -- Modeladora ancestral An'wyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161920 AND `Idx`=0); -- Cachorro glauco
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161917 AND `Idx`=0); -- Merodeador glauco
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161882 AND `Idx`=0); -- Polilla de Ardenweald plácida
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174631 AND `Idx`=0); -- Xan'Shiells
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175421 AND `Idx`=0); -- Cerdith
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173899 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173899 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173884 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173884 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173862 AND `Idx`=1); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173862 AND `Idx`=0); -- Alma pacífica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174371 AND `Idx`=0); -- Mixy Mak
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174365 AND `Idx`=0); -- Narciso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174364 AND `Idx`=0); -- Gwynceirw
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174362 AND `Idx`=0); -- Estrujín
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173916 AND `Idx`=0); -- Marasmius
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=127956 AND `Idx`=0); -- Amalgam of Destruction
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174570 AND `Idx`=0); -- Muñeco de entrenamiento de enjambre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174567 AND `Idx`=0); -- Muñeco de entrenamiento de asaltante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171397 AND `Idx`=1); -- Forestal sylvari
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171397 AND `Idx`=0); -- Forestal sylvari
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164023 AND `Idx`=0); -- Vigía Carriflor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174569 AND `Idx`=0); -- Muñeco de entrenamiento
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174914 AND `Idx`=0); -- Elwyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174613 AND `Idx`=0); -- M'Can
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174611 AND `Idx`=0); -- Boles
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167193 AND `Idx`=0); -- Plumaligera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174774 AND `Idx`=0); -- Rahad
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158556 AND `Idx`=0); -- Aithlyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=60199 AND `Idx`=0); -- Runa de poder
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174571 AND `Idx`=0); -- Muñeco de entrenamiento de rajadura
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160292 AND `Idx`=0); -- Kewarin
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158554 AND `Idx`=0); -- Lafwyn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174568 AND `Idx`=0); -- Muñeco de entrenamiento del combatiente de calabozo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158544 AND `Idx`=0); -- Lord Herne
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=31216 AND `Idx`=0); -- Reflejo exacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174572 AND `Idx`=0); -- Lillyensthoom
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174566 AND `Idx`=0); -- Muñeco tanque del combatiente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174565 AND `Idx`=0); -- Muñeco tanque de asaltante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=15); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=14); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=13); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=12); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=11); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=10); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=9); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=8); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=7); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=6); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=5); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=4); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=3); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=2); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=1); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165751 AND `Idx`=0); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173681 AND `Idx`=0); -- Samn'go
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=15); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=14); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=13); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=12); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=11); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=10); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=9); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=8); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=7); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=6); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=5); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=4); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=3); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=2); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=1); -- Guardián
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158547 AND `Idx`=0); -- Guardián
UPDATE `creature_template_model` SET `DisplayScale`=1.75, `VerifiedBuild`=38134 WHERE (`CreatureID`=167527 AND `Idx`=0); -- Oranomonos, la Enramada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174732 AND `Idx`=0); -- Ingra Krazic
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173682 AND `Idx`=0); -- Dor'levgoren
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175419 AND `Idx`=0); -- Maestra artesana Lamda
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175418 AND `Idx`=0); -- Mar'lan
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173171 AND `Idx`=0); -- Viverista Noche Estrellada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165550 AND `Idx`=0); -- Asistente alabrillante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158543 AND `Idx`=0); -- Asistente Rociolux
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089, `VerifiedBuild`=38134 WHERE (`CreatureID`=170034 AND `Idx`=0); -- Karras
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=79205 AND `Idx`=0); -- Devorador pálido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=81670 AND `Idx`=0); -- Gnaw Buscasangre
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174775 AND `Idx`=0); -- Ofer
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=142644 AND `Idx`=0); -- Carentan
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175123 AND `Idx`=0); -- Celador Arkoban
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167206 AND `Idx`=0); -- Yanlar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165702 AND `Idx`=0); -- Zayhad, la constructora
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165659 AND `Idx`=0); -- Capitana de los Cazadores Korayn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=18); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=17); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=16); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=15); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=14); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=13); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=12); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=11); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=10); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=9); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=8); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=7); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=6); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=5); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=4); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=3); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=2); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=1); -- Artesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174655 AND `Idx`=0); -- Artesano feérico
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089, `VerifiedBuild`=38134 WHERE (`CreatureID`=170033 AND `Idx`=0); -- Aprendiz vorkai
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=176096 AND `Idx`=0); -- Laurel
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160481 AND `Idx`=0); -- Niya
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174209 AND `Idx`=0); -- Lady Muunn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175417 AND `Idx`=0); -- Sulanoom
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161509 AND `Idx`=0); -- Lady Baya Lunar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174610 AND `Idx`=0); -- R'chll
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174614 AND `Idx`=0); -- Ka'ruth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174835 AND `Idx`=0); -- Acaparadora veteada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170107 AND `Idx`=1); -- Ir al Corazón del Bosque
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=170107 AND `Idx`=0); -- Ir al Corazón del Bosque
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=7); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=6); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=5); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=4); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=3); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=2); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=1); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158555 AND `Idx`=0); -- Guardia de la reina de élite
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175415 AND `Idx`=0); -- Harkoth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172400 AND `Idx`=0); -- Mesa de comando
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167196 AND `Idx`=0); -- Sesselie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174608 AND `Idx`=0); -- Chispa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168100 AND `Idx`=3); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168100 AND `Idx`=2); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168100 AND `Idx`=1); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168100 AND `Idx`=0); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=19); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=18); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=17); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=16); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=15); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=14); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=13); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=12); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=11); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=10); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=9); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=8); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=7); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=6); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=5); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=4); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=3); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=2); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=1); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168116 AND `Idx`=0); -- Cortesano feérico
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164701 AND `Idx`=0); -- Polilla estelar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175413 AND `Idx`=0); -- Brisaluciente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158553 AND `Idx`=0); -- Mapirosa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174609 AND `Idx`=0); -- Zaki
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160262 AND `Idx`=0); -- Ysera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175414 AND `Idx`=0); -- Adera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160482 AND `Idx`=0); -- Tejesueños
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=173534 AND `Idx`=0); -- Bloodlouse Larva
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160703 AND `Idx`=0); -- Plagueborn Slime


UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=170206 AND `Idx`=0); -- Venado rúnico
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=164033 AND `Idx`=0); -- Matriarca madriscura
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=163967 AND `Idx`=0); -- Asolador nudorrama
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=165907 AND `Idx`=0); -- Venado rúnico
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=170730 AND `Idx`=0); -- Polilla de Ardenweald marchita
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=169205 AND `Idx`=0); -- Flor voraz
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=157885 AND `Idx`=0); -- Vorkai poseído
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=157883 AND `Idx`=0); -- Sylvar poseído
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=169812 AND `Idx`=1); -- Centinela convertido
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=169812 AND `Idx`=0); -- Centinela convertido
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=170769 AND `Idx`=0); -- Polilla de Ardenweald marchita
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=173582 AND `Idx`=0); -- Mantarraya contagiada prófuga
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=173503 AND `Idx`=0); -- Acólito estudioso
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=172601 AND `Idx`=0); -- Hechicero necrótico
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158977 AND `Idx`=0); -- Saqueador huesofundido
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159747 AND `Idx`=1); -- Reina pozamédula
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159747 AND `Idx`=0); -- Reina pozamédula
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159737 AND `Idx`=1); -- Emboscadora tejehuesos
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159737 AND `Idx`=0); -- Emboscadora tejehuesos
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159714 AND `Idx`=1); -- Trepadora pozamédula
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159714 AND `Idx`=0); -- Trepadora pozamédula
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159886 AND `Idx`=1); -- Hermana Chelicerae
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159886 AND `Idx`=0); -- Hermana Chelicerae
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159708 AND `Idx`=1); -- Glotona pozamédula
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159708 AND `Idx`=0); -- Glotona pozamédula
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159916 AND `Idx`=1); -- Arrasadora tejehuesos
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159916 AND `Idx`=0); -- Arrasadora tejehuesos
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162727 AND `Idx`=1); -- Burbusangre
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162727 AND `Idx`=0); -- Burbusangre
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=165549 AND `Idx`=0); -- Succión agria
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158053 AND `Idx`=0); -- Madre de piojos de cadáver
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=165561 AND `Idx`=0); -- Piojos de cadáver hinchados
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158566 AND `Idx`=0); -- Engendro de piojo de cadáver
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158752 AND `Idx`=1); -- Colmisangre depredador
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158752 AND `Idx`=0); -- Colmisangre depredador
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=165473 AND `Idx`=1); -- Colmisangre alfa
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=165473 AND `Idx`=0); -- Colmisangre alfa
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=168148 AND `Idx`=1); -- Drolkrad
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=168148 AND `Idx`=0); -- Drolkrad
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=168147 AND `Idx`=1); -- Sabriel, la Rajahuesos
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=168147 AND `Idx`=0); -- Sabriel, la Rajahuesos
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162588 AND `Idx`=1); -- Picartílago
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162588 AND `Idx`=0); -- Picartílago
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158642 AND `Idx`=0); -- Carne de alma podrida
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159856 AND `Idx`=1); -- Peste virulenta
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=159856 AND `Idx`=0); -- Peste virulenta
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=161890 AND `Idx`=0); -- Carroñero carne sajada
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=161881 AND `Idx`=0); -- Espinacero herido
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=174731 AND `Idx`=0); -- Cuidador de arboledas poseído
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=174713 AND `Idx`=0); -- Alabrillo crepuscular
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=172945 AND `Idx`=0); -- Alabrillo del alba
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=172934 AND `Idx`=0); -- Venado rúnico ramalvaje
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=172722 AND `Idx`=0); -- Merodeador de la arboleda
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=172979 AND `Idx`=0); -- Esporeadora Almíbar
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=161917 AND `Idx`=0); -- Merodeador glauco
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=79205 AND `Idx`=0); -- Devorador pálido

DELETE FROM `gameobject_template` WHERE `entry` IN (354925 /*Portal*/, 358335 /*Grimorio de invocaciones ancestrales*/, 356587 /*Pedestal*/, 356595 /*Jaula*/, 357576 /*Huella*/, 355049 /*Runa de rituales*/, 355048 /*Runa de rituales*/, 357580 /*Impacto de sangre*/, 357574 /*Huella*/, 357573 /*Impacto de sangre*/, 357568 /*Resguardos y barreras mayores, volumen IV*/, 357567 /*Los caminos de los Primeros*/, 357566 /*Arcanum alado*/, 357525 /*Estante*/, 336679 /*Brazo incorpóreo*/, 357516 /*Montón de huesos*/, 358326 /*Polvo de amatista*/, 355051 /*Runa de rituales*/, 356366 /*Libro de rituales de vinculación*/, 364947 /*Ruinas de estandarte de Sin'dane*/, 364948 /*Bastón de runas de Sin'dane*/, 364945 /*Estandarte de Sin'dane*/, 355073 /*Runa de rituales*/, 364949 /*Conocimiento ligado a los exánimes*/, 364933 /*Círculo ritual*/, 355193 /*Runa de rituales*/, 339836 /*Percha*/, 339750 /*Huevo de oro*/, 339411 /*Diario de Arin'gore*/, 346019 /*Zerekriss*/, 367758 /*Buzón*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `IconName`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(354925, 43, 65459, '', '', 1, -1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Portal
(358335, 10, 61893, 'questinteract', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 341656, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Grimorio de invocaciones ancestrales
(356587, 5, 60152, '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Pedestal
(356595, 5, 59387, '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Jaula
(357576, 5, 44364, '', '', 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Huella
(355049, 10, 65101, '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2060, 38134), -- Runa de rituales
(355048, 10, 65101, '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2060, 38134), -- Runa de rituales
(357580, 5, 48291, '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Impacto de sangre
(357574, 5, 66678, '', '', 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Huella
(357573, 5, 46825, '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Impacto de sangre
(357568, 3, 59323, 'questinteract', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104620, 0, 0, 0, 837, 38134), -- Resguardos y barreras mayores, volumen IV
(357567, 3, 60086, 'questinteract', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104618, 0, 0, 0, 837, 38134), -- Los caminos de los Primeros
(357566, 3, 59920, 'questinteract', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104617, 0, 0, 0, 837, 38134), -- Arcanum alado
(357525, 5, 60085, '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Estante
(336679, 5, 8373, '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Brazo incorpóreo
(357516, 5, 61334, '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Montón de huesos
(358326, 3, 15588, 'questinteract', '', 0.5, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 105118, 0, 0, 0, 837, 38134), -- Polvo de amatista
(355051, 10, 65101, '', '', 0.5, 93, 0, 0, 0, 0, 0, 1, 0, 0, 0, 334300, 0, 0, 1, 33516, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2060, 38134), -- Runa de rituales
(356366, 10, 59857, 'interact', '', 1, 3273, 0, 0, 1, 0, 0, 1, 0, 0, 0, 337041, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 83815, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 38134), -- Libro de rituales de vinculación
(364947, 5, 61255, '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Ruinas de estandarte de Sin'dane
(364948, 10, 58690, 'questinteract', '', 1, 2557, 61539, 0, 3000, 0, 0, 0, 0, 0, 0, 346551, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Bastón de runas de Sin'dane
(364945, 10, 62006, 'questinteract', '', 1, 2668, 61539, 0, 3000, 0, 0, 0, 0, 0, 0, 346514, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Estandarte de Sin'dane
(355073, 10, 65101, '', '', 0.5, 93, 0, 0, 0, 0, 0, 1, 0, 0, 0, 334328, 0, 0, 1, 33516, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2060, 38134), -- Runa de rituales
(364949, 10, 61885, 'questinteract', '', 1, 2741, 61539, 0, 3000, 0, 0, 0, 0, 0, 0, 346566, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Conocimiento ligado a los exánimes
(364933, 5, 62381, '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Círculo ritual
(355193, 10, 65101, '', '', 0.5, 93, 0, 0, 0, 0, 0, 1, 0, 0, 0, 334327, 0, 0, 1, 33516, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2060, 38134), -- Runa de rituales
(339836, 5, 25121, '', '', 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Percha
(339750, 3, 12446, 'questinteract', '', 3, 43, 0, 1, 0, 0, 0, 0, 0, 61708, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99724, 0, 0, 0, 745, 38134), -- Huevo de oro
(339411, 10, 59573, '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 8203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 745, 38134), -- Diario de Arin'gore
(346019, 15, 58938, '', '', 1, 7986, 5, 1, 0, 0, 0, 2276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2060, 38134), -- Zerekriss
(367758, 19, 65009, '', '', 0.999999701976776123, 4383, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- Buzón

UPDATE `gameobject_template` SET `type`=5, `Data1`=1, `Data2`=0, `Data3`=1, `VerifiedBuild`=38134 WHERE `entry`=364374; -- Portal a Torghast
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349900; -- Depósito de eletio
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353816; -- Puerta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353815; -- Puerta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=344767; -- Piedra de camino a Oribos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364888; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355914; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353826; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354218; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354217; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353827; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349363; -- Portón de la muerte de Bwondsamdi a la necrópolis
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352613; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352612; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352611; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=311205; -- Decoración del portón de la muerte de Bwondsamdi
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349082; -- Banco de lenguados perdidos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=338672; -- Madriguera de gorm
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358572; -- Pegote de gorm extrapegajoso
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349533; -- Mam'toth
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349534; -- Tharon'ja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355043; -- Cache of the Moon VFX
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350845; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350843; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350842; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350840; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350839; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350823; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350852; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352697; -- Semilla silvestre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349982; -- Depósito de fedrum
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350829; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350846; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364345; -- Una semilla apenas reluciente
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=336686; -- Estrella mortal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352060; -- Lirios nocturnos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352059; -- Lirios nocturnos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352058; -- Lirio de la noche
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357285; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357298; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357294; -- Silla
UPDATE `gameobject_template` SET `IconName`='', `unk1`='', `VerifiedBuild`=38134 WHERE `entry`=191083; -- Círculo demoníaco: invocar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=338622; -- Carro de cadáveres
UPDATE `gameobject_template` SET `type`=10, `size`=0.200000002980232238, `ContentTuningId`=2060, `VerifiedBuild`=38134 WHERE `entry`=355040; -- Runa de rituales
UPDATE `gameobject_template` SET `type`=10, `displayId`=60824, `size`=2, `Data3`=1, `Data7`=8226, `Data9`=2, `Data24`=4375, `ContentTuningId`=2060, `VerifiedBuild`=38134 WHERE `entry`=355038; -- Arca con vínculo rúnico
UPDATE `gameobject_template` SET `type`=3, `size`=1.5, `Data0`=3272, `Data2`=1, `Data13`=1, `Data14`=21400, `Data19`=3, `Data26`=331856, `Data29`=4457, `Data30`=104230, `ContentTuningId`=2060, `VerifiedBuild`=38134 WHERE `entry`=355980; -- Alijo de ritualista
UPDATE `gameobject_template` SET `Data0`=43, `Data1`=0, `Data2`=1, `Data4`=1, `Data5`=1, `Data14`=78745, `Data30`=104247, `ContentTuningId`=2060, `VerifiedBuild`=38134 WHERE `entry`=355979; -- Páginas de ritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350085; -- Depósito de oxxina abundante
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=335485; -- Montón de huesos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=335486; -- Montón de huesos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=335484; -- Montón de huesos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357480; -- Despojos ricos en ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357481; -- Cristal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357495; -- Suministros
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357485; -- Botín vaciado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357494; -- Suministros
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357486; -- Botín vaciado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357478; -- Despojos ricos en ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357476; -- Despojos ricos en ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357165; -- Cajón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357161; -- Barril
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357484; -- Botín vaciado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357483; -- Botín vaciado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357482; -- Botín vaciado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357479; -- Despojos ricos en ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357475; -- Carro
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357474; -- Despojos ricos en ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357154; -- Cajón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357446; -- Círculo de piedra
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353881; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348535; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236184; -- Espada rota
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=341408; -- Cristal de poder
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364863; -- Puerta de la torre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=246280; -- Cylinder Collision (2 Scale)
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348532; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348536; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=337095; -- Anclaje volátil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348935; -- Verruga terrestre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=351470; -- Estrella mortal
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=38134 WHERE `entry`=214229; -- Yunque térmico
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353615; -- Cristal desviador
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=335655; -- Brazo de Oonar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=335649; -- Aterrangustias
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354128; -- Hacha arrojadiza maldraxxi
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353395; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353396; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357723; -- Portal de negociantes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353394; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353393; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349560; -- Portal de negociantes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349612; -- Se busca: Tasador Vix
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353821; -- Jaula de negociantes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353400; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353397; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353398; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353399; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349981; -- Depósito de oxxina
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354970; -- Teatro del Dolor
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355447; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348533; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348534; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=356879; -- Cajón de artesano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353882; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=348537; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349546; -- Jaula de negociantes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352110; -- Puerta de la torre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364394; -- Calavera de dragón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353614; -- Cristal desviador
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=336689; -- Corraíz
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=252145; -- Portal de instancia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364393; -- Cebolla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355505; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353602; -- Cristal desviador
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352577; -- Puerta de sagrario
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=338855; -- Zerekriss
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364892; -- Reservorio de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358873; -- Reservorio de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358872; -- Reservorio de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358871; -- Reservorio de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=351447; -- Forja de lazos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355042; -- Conductor de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357089; -- 9NC_Necro_Covenant_PrimusArmorStand04
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=356600; -- Sala principal, Trono del Primus
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364865; -- Puerta de pinchos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=350775; -- Puerta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=336675; -- Necrópolis - Guerreros
UPDATE `gameobject_template` SET `Data2`=3, `VerifiedBuild`=38134 WHERE `entry`=354927; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353391; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364864; -- Puerta de pináculo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353392; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353633; -- Puerta de sagrario
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353601; -- Cristal desviador
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353389; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353390; -- Puerta de celda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355424; -- Puerta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353616; -- Cristal desviador
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357300; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357271; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357263; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357293; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357292; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357291; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353484; -- La Gran Bóveda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353485; -- Inscripción
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353483; -- Peletería
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353490; -- Joyería
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=365154; -- Al Anillo de los Destinos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352745; -- Al Anillo de Transferencia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352746; -- Al Anillo de los Destinos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=345445; -- Al Anillo de los Destinos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=365155; -- Al Anillo de los Destinos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353489; -- Ingeniería
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353480; -- Alquimia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353481; -- Sastrería
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357272; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=365157; -- Al Anillo de Transferencia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357340; -- Jaula de negociantes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=345444; -- Al Anillo de Transferencia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357301; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357277; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357269; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357325; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353479; -- Salón de las Formas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357306; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357282; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353822; -- Portal a Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357266; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357322; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353487; -- Encantamiento
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357314; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357303; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357274; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353482; -- Silla de peluquero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364422; -- Puerta a Revendreth
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353750; -- Salón de Posesiones
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357287; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355063; -- Cámara de la hermandad
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354924; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357327; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357319; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357311; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353476; -- La Idilia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353478; -- El Enclave
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=365156; -- Al Anillo de Transferencia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354923; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357308; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357324; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357316; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353492; -- Silla de peluquero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364497; -- Doodad_9FX_ORIBOS_ARDENWEALD_DOORWRAP001
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354921; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357305; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354681; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357321; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357462; -- Obelisco espiritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357313; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364419; -- Puerta a Bastión
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357302; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354922; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357286; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357278; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357262; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357326; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357318; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364499; -- Resplandor de portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357310; -- Silla
UPDATE `gameobject_template` SET `IconName`='', `unk1`='', `VerifiedBuild`=38134 WHERE `entry`=353823; -- Portal a Ventormenta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357307; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357299; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357267; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357323; -- Silla
UPDATE `gameobject_template` SET `type`=10, `Data13`=1, `Data25`=1, `Data27`=1, `Data28`=1, `VerifiedBuild`=38134 WHERE `entry`=364424; -- Puerta a Maldraxxus
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357315; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353491; -- Olla para cocinar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357095; -- Mapa de pacto de las Tierras de las Sombras
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357288; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357264; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354680; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=357320; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353488; -- Silla de peluquero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364423; -- Puerta a Ardenweald
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353477; -- Salón de Curiosidades
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355375; -- Depósito de ánima volátil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355797; -- Vaina de ánima inestable
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=336688; -- Antorcha de la vigilia
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349898; -- Depósito de lestrita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=354201; -- Pluma de dragón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353378; -- Obelisco espiritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=360053; -- Tambor
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358381; -- Arpa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355228; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355227; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=355226; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358820; -- Mapa de exploración
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359279; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359285; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359284; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359283; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359282; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359281; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359280; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=359286; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=352107; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353524; -- 9ARD_FaeMushroomCircle_B01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353521; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364329; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364325; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353525; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364326; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=353526; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364327; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364328; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364324; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364893; -- Reservorio de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=328303; -- Conductor de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=351448; -- Forja de lazos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=356396; -- Reservorio de ánima
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=364335; -- Pieza central de sagrario

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (357568,357567,357566,355980,358326,339750)) OR (`Idx`=1 AND `GameObjectEntry`=355980);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(357568, 0, 182644, 38134), -- Resguardos y barreras mayores, volumen IV
(357567, 0, 182643, 38134), -- Los caminos de los Primeros
(357566, 0, 182642, 38134), -- Arcanum alado
(355980, 1, 179317, 38134), -- Alijo de ritualista
(355980, 0, 179327, 38134), -- Alijo de ritualista
(358326, 0, 183400, 38134), -- Polvo de amatista
(339750, 0, 174043, 38134); -- Huevo de oro

UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=352058 AND `Idx`=0); -- Lirio de la noche
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=11); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=10); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=9); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=8); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=7); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=6); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=5); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=4); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=3); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=2); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=1); -- Cajón de artesano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=356879 AND `Idx`=0); -- Cajón de artesano

DELETE FROM `page_text` WHERE `ID`=8226;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(8226, 'Este tesoro está cerrado por medios mágicos.\n\nHay tres runas en el cofre. Parecen obtener poder de las runas cercanas.', 0, 0, 0, 38134); -- 8226


DELETE FROM `npc_text` WHERE `ID` IN (41798 /*41798*/, 39240 /*39240*/, 42163 /*42163*/, 42162 /*42162*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(41798, 1, 1, 1, 0, 0, 0, 0, 0, 204733, 204734, 204735, 0, 0, 0, 0, 0, 38134), -- 41798
(39240, 1, 0, 0, 0, 0, 0, 0, 0, 184898, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39240
(42163, 1, 0, 0, 0, 0, 0, 0, 0, 206262, 0, 0, 0, 0, 0, 0, 0, 38134), -- 42163
(42162, 1, 1, 1, 0, 0, 0, 0, 0, 206196, 206208, 206211, 0, 0, 0, 0, 0, 38134); -- 42162

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=39125; -- 39125
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=40297; -- 40297

DELETE FROM `world_quest` WHERE `id` IN (57443 /*57443*/, 57340 /*57340*/, 60623 /*60623*/, 44765 /*44765*/, 59642 /*59642*/, 59826 /*59826*/, 60388 /*60388*/, 61631 /*61631*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(57443, 86400, 19061, 1), -- 57443
(57340, 43200, 18142, 1), -- 57340
(60623, 86400, 19408, 1), -- 60623
(44765, 604800, 13203, 1), -- 44765
(59642, 86400, 18288, 1), -- 59642
(59826, 86400, 17592, 1), -- 59826
(60388, 259200, 19328, 1), -- 60388
(61631, 86400, 20197, 1); -- 61631

UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982
UPDATE `world_quest` SET `variable`=14061 WHERE `id`=48982; -- 48982

