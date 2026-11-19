DELETE FROM `hotfix_data` WHERE (`TableHash`=3322146344 AND `RecordID`=153925 AND `Timestamp`=1428345292);
INSERT INTO `hotfix_data` (`TableHash`, `RecordID`, `Timestamp`, `Deleted`) VALUES
(3322146344, 153925, 1428345292, 0); -- SpellMisc - 153925 - 153925

UPDATE `chr_upgrade_bucket_spell` SET `VerifiedBuild`=19865 WHERE `ID` IN (1708 /*1708*/, 1709 /*1709*/, 1710 /*1710*/);

UPDATE `creature_difficulty` SET `VerifiedBuild`=19865 WHERE `Id` IN (86788, 78258, 78259);

UPDATE `curve_point` SET `VerifiedBuild`=19865 WHERE `ID` IN (4865 /*4865*/, 3101 /*3101*/, 5182 /*5182*/);

UPDATE `item` SET `VerifiedBuild`=19865 WHERE `ID` IN (122147 /*-Unknown-*/, 122154 /*-Unknown-*/, 121837 /*-Unknown-*/, 122706 /*-Unknown-*/, 122707 /*-Unknown-*/, 122101 /*-Unknown-*/, 121820 /*-Unknown-*/, 120989 /*-Unknown-*/);

DELETE FROM `spell_misc` WHERE `ID`=153925;
INSERT INTO `spell_misc` (`ID`, `Attributes`, `AttributesEx`, `AttributesExB`, `AttributesExC`, `AttributesExD`, `AttributesExE`, `AttributesExF`, `AttributesExG`, `AttributesExH`, `AttributesExI`, `AttributesExJ`, `AttributesExK`, `AttributesExL`, `AttributesExM`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `Speed`, `SpellVisualID1`, `SpellVisualID2`, `SpellIconID`, `ActiveIconID`, `SchoolMask`, `MultistrikeSpeedMod`, `VerifiedBuild`) VALUES
(153925, 553648384, 0, 0, 0, 65536, 0, 2048, 0, 268435456, 0, 0, 65536, 0, 0, 1, 6, 1, 0, 45708, 0, 3482, 0, 1, 0, 19865); -- 153925

UPDATE `spell_misc` SET `VerifiedBuild`=19865 WHERE `ID` IN (152224 /*152224*/, 142312 /*142312*/, 129047 /*129047*/, 136620 /*136620*/, 140581 /*140581*/, 148759 /*148759*/, 148827 /*148827*/, 148760 /*148760*/, 149497 /*149497*/, 150373 /*150373*/, 130608 /*130608*/, 130275 /*130275*/, 147181 /*147181*/, 147185 /*147185*/, 147186 /*147186*/, 133455 /*133455*/);
