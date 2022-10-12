DELETE FROM `areatrigger_template` WHERE `Id` IN (7170, 22687, 20909, 9225, 21076, 11451, 3319, 7312, 7445, 7371, 10133);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(7170, 0, 1, 0, 4, 4, 0, 0, 0, 0, 38134),
(22687, 0, 1, 0, 4, 4, 0, 0, 0, 0, 38134),
(20909, 0, 1, 0, 4, 4, 0, 0, 0, 0, 38134),
(9225, 0, 1, 0, 8, 8, 0, 0, 0, 0, 38134),
(21076, 0, 1, 0, 4, 4, 0, 0, 0, 0, 38134),
(11451, 4, 1, 0, 8, 8, 7, 7, 3, 3, 38134),
(3319, 0, 1, 0, 3, 3, 0, 0, 0, 0, 38134),
(7312, 0, 1, 0, 3, 3, 0, 0, 0, 0, 38134),
(7445, 0, 1, 4, 45, 45, 0, 0, 0, 0, 38134),
(7371, 0, 1, 4, 5, 5, 0, 0, 0, 0, 38134),
(10133, 0, 1, 0, 8, 8, 0, 0, 0, 0, 38134);


REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(1422, 5653, 0, 0, 0, 0, 0, 0, 0, 6000, 6000, 38134), -- SpellId : 150794
(2561, 7170, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 38134), -- SpellId : 164173
(9810, 14725, 0, 0, 0, 0, 0, 0, 0, 0, 60000, 38134), -- SpellId : 236775
(6951, 11451, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 38134), -- SpellId : 212182
(4462, 9202, 1466, 0, 0, 0, 0, 0, 0, 2889, 3000, 38134), -- SpellId : 187892
(12002, 16713, 0, 0, 0, 0, 0, 0, 0, 0, 6000, 38134), -- SpellId : 256820
(2708, 7312, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 38134), -- SpellId : 165674
(2836, 7445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 167343
(2757, 7371, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- SpellId : 166539



UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3136, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2001, `TimeToTargetScale`=2500, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1612 AND `AreaTriggerId`=6095); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=658 AND `AreaTriggerId`=3921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=658 AND `AreaTriggerId`=3921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=314 AND `AreaTriggerId`=3020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6523 AND `AreaTriggerId`=11142); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6523 AND `AreaTriggerId`=11142); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3013, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=658 AND `AreaTriggerId`=3921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=314 AND `AreaTriggerId`=3020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5760 AND `AreaTriggerId`=10471); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6615 AND `AreaTriggerId`=11203); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2024, `TimeToTargetScale`=2500, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1612 AND `AreaTriggerId`=6095); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `AnimId`=153, `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6523 AND `AreaTriggerId`=11142); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=314 AND `AreaTriggerId`=3020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6523 AND `AreaTriggerId`=11142); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5760 AND `AreaTriggerId`=10471); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=600000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3468 AND `AreaTriggerId`=8090); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7999, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=314 AND `AreaTriggerId`=3020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=314 AND `AreaTriggerId`=3020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=658 AND `AreaTriggerId`=3921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7462, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1524 AND `AreaTriggerId`=5972); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2981, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6615 AND `AreaTriggerId`=11203); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2012, `TimeToTargetScale`=2500, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1612 AND `AreaTriggerId`=6095); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5740, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=8800 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=1524 AND `AreaTriggerId`=5972); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `AnimId`=153, `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3594, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7151, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12609 AND `AreaTriggerId`=17283); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12609 AND `AreaTriggerId`=17283); -- SpellId : 0

DELETE FROM `conversation_line_template` WHERE `Id` IN (128, 127, 126, 125, 13637, 129);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(128, 19708, 0, 0, 0, 38134),
(127, 8735, 0, 0, 0, 38134),
(126, 4284, 0, 0, 0, 38134),
(125, 0, 0, 0, 0, 38134),
(13637, 0, 0, 0, 0, 38134),
(129, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14692;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13648;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13647;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13646;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14694;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14693;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13632;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13631;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14690;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13635;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13634;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13633;
UPDATE `conversation_line_template` SET `StartTime`=30494, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13642;
UPDATE `conversation_line_template` SET `StartTime`=28434, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13641;
UPDATE `conversation_line_template` SET `StartTime`=26278, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13640;
UPDATE `conversation_line_template` SET `StartTime`=14548, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13639;
UPDATE `conversation_line_template` SET `StartTime`=9064, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13638;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13813;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13812;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13811;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=12146;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13657;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13656;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13655;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13654;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13653;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13652;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13651;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13650;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13649;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17470;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17469;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17468;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17467;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17466;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=14691;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13645;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13644;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17470;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17469;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17468;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17467;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17466;

DELETE FROM `conversation_template` WHERE `Id` IN (36, 37);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(36, 125, 23438, 0, 38134),
(37, 129, 8280, 0, 38134);

UPDATE `conversation_template` SET `LastLineEndTime`=20100, `VerifiedBuild`=38134 WHERE `Id`=7668;
UPDATE `conversation_template` SET `LastLineEndTime`=20100, `VerifiedBuild`=38134 WHERE `Id`=7668;
UPDATE `conversation_template` SET `LastLineEndTime`=12760, `VerifiedBuild`=38134 WHERE `Id`=6495;
UPDATE `conversation_template` SET `LastLineEndTime`=3200, `VerifiedBuild`=38134 WHERE `Id`=6494;
UPDATE `conversation_template` SET `LastLineEndTime`=4900, `VerifiedBuild`=38134 WHERE `Id`=6493;
UPDATE `conversation_template` SET `LastLineEndTime`=4000, `VerifiedBuild`=38134 WHERE `Id`=6492;
UPDATE `conversation_template` SET `LastLineEndTime`=13100, `VerifiedBuild`=38134 WHERE `Id`=5420;
UPDATE `conversation_template` SET `LastLineEndTime`=69075, `VerifiedBuild`=38134 WHERE `Id`=6136;
UPDATE `conversation_template` SET `LastLineEndTime`=13677, `VerifiedBuild`=38134 WHERE `Id`=6135;
UPDATE `conversation_template` SET `LastLineEndTime`=18931, `VerifiedBuild`=38134 WHERE `Id`=6134;
UPDATE `conversation_template` SET `FirstLineID`=13637, `LastLineEndTime`=39082, `VerifiedBuild`=38134 WHERE `Id`=6133;
UPDATE `conversation_template` SET `LastLineEndTime`=20738, `VerifiedBuild`=38134 WHERE `Id`=6131;
UPDATE `conversation_template` SET `LastLineEndTime`=9686, `VerifiedBuild`=38134 WHERE `Id`=6130;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (339711 /*Gate*/, 339739 /*Gate*/, 339742 /*Gate*/, 339713 /*Gate*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(339711, 1375, 33, 0, 0), -- Gate
(339739, 1375, 33, 0, 0), -- Gate
(339742, 1375, 33, 0, 0), -- Gate
(339713, 1375, 33, 0, 0); -- Gate

UPDATE `gameobject_template_addon` SET `faction`=94, `flags`=32804 WHERE `entry`=233922; -- Small Timber
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=231064; -- Lady Sena's Other Materials Stash
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=231092; -- Log Stack
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=233633; -- Unused Wood Pile
UPDATE `gameobject_template_addon` SET `flags`=262144, `WorldEffectID`=8830 WHERE `entry`=207324; -- Warchief's Command Board
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=233081; -- Large Plot
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=233083; -- Small Plot
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=231063; -- Lady Sena's Materials Stash
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=239181; -- Architect Table Collision
UPDATE `gameobject_template_addon` SET `flags`=48 WHERE `entry`=234092; -- Back Gate
UPDATE `gameobject_template_addon` SET `flags`=48 WHERE `entry`=234091; -- North Gate
UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry`=233664; -- Master Surveyor
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=230563; -- Logs
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=230561; -- Bonfire
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=230945; -- Portal to Orgrimmar
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=230562; -- Logs
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=230527; -- Tree Marking
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=229057; -- Horde Banner
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=233117; -- Frostweed
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=230544; -- Frostwolf Shamanstone
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32, `AIAnimKitID`=1256 WHERE `entry`=233707; -- Khadgar's Barrier (NEEDS ARCANE VERSION)
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=237667; -- Dark Portal
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=233111; -- Iron Horde Mace
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=233109; -- Iron Horde Axe
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=233108; -- Iron Pike
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=233110; -- Iron Horde Spear
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5460 WHERE `entry`=231261; -- Worldbreaker Side Turret
UPDATE `gameobject_template_addon` SET `faction`=114, `AIAnimKitID`=5460 WHERE `entry`=232539; -- Side Turret
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=231119; -- Blackrock Powder Keg
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=231816; -- Iron Horde Weapon Rack
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=233097; -- Bellows
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=231815; -- Iron Horde Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=231817; -- Iron Horde Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=231818; -- Iron Horde Weapon
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=231819; -- Iron Horde Weapon
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=231820; -- Iron Horde Weapon
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=1048608 WHERE `entry`=236093; -- Iron Worldbreaker
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=231197; -- Cave In
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=231136; -- Tar'thog Bridge
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229323; -- Boiled Ichor
UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry`=229353; -- Bleeding Hollow Cage
UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry`=229352; -- Bleeding Hollow Cage
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=233432; -- Iron Horde Supply Crate
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=234623; -- Dark Portal Door
UPDATE `gameobject_template_addon` SET `flags`=32, `AIAnimKitID`=7254 WHERE `entry`=236914; -- Soul Crystal L
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=233057; -- Mark of the Bleeding Hollow
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=234622; -- Dark Portal Door
UPDATE `gameobject_template_addon` SET `flags`=32, `AIAnimKitID`=7254 WHERE `entry`=236913; -- Soul Crystal R
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=238955; -- Doodad_6IH_IronHorde_darkportaldoor002
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=238954; -- Doodad_6IH_IronHorde_darkportaldoor001
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=233056; -- Mark of the Shadowmoon
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=233614; -- Chamber Door
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=233160; -- GoHome Object
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32, `AIAnimKitID`=1483 WHERE `entry`=233906; -- Doodad_6TJ_DarkPortal_FX_Wrap001
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=1048608 WHERE `entry`=233297; -- Horde Ship
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=1048608 WHERE `entry`=233298; -- Alliance Ship
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=237670; -- Dark Portal
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232505; -- Spiked Ball
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232503; -- Debris 002
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=6714 WHERE `entry`=233104; -- Stasis Rune
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=231137; -- Tar'thog Bridge
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=231766; -- Destroyed Iron Horde War Machine
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=231957; -- Gate
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=231958; -- Gate
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=236692; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Center001
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=236691; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Left001
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=236690; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Right001
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=234140; -- Gul'dan Door Light B
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=233197; -- Iron Cage Door
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=234139; -- Gul'dan Door Light
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229599; -- Mark of the Shattered Hand
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229598; -- Mark of the Burning Blade
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232504; -- Debris 003
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232506; -- Smoke Plume
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232500; -- Destroyed Iron Horde War Machine Type 01
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232502; -- Debris 001
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229600; -- Mark of the Blackrock
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=3890 WHERE `entry`=237261; -- Gul'dan Light Shaft
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=1048608 WHERE `entry`=233277; -- Blackrock Dam
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=231860; -- Dark Portal Power Spire
UPDATE `gameobject_template_addon` SET `flags`=8192, `AIAnimKitID`=3761 WHERE `entry`=231763; -- Iron Horde Capsule
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=142145; -- Gromsblood
UPDATE `gameobject_template_addon` SET `flags`=36 WHERE `entry`=232625; -- Cooking Pot
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233909; -- Iron Tank
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233905; -- Iron Tank
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233910; -- Iron Wagon
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233904; -- Iron Tank
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233913; -- Iron Banner
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233911; -- Iron Barricade
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=324; -- Small Thorium Vein
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=233914; -- Iron Banner
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=2047; -- Truesilver Deposit
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=235880; -- Portal to Orgrimmar
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=279378; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=3761 WHERE `entry`=272639; -- Vilescale Chest
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=279253; -- Lucky Horace's Lucky Chest
UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=282721; -- Treasure Chest

DELETE FROM `scene_template` WHERE (`SceneId`=608 AND `ScriptPackageID`=798) OR (`SceneId`=604 AND `ScriptPackageID`=789) OR (`SceneId`=594 AND `ScriptPackageID`=778) OR (`SceneId`=578 AND `ScriptPackageID`=771) OR (`SceneId`=817 AND `ScriptPackageID`=953) OR (`SceneId`=729 AND `ScriptPackageID`=906) OR (`SceneId`=686 AND `ScriptPackageID`=870) OR (`SceneId`=798 AND `ScriptPackageID`=948);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(608, 16, 798, 0),
(604, 16, 789, 0),
(594, 16, 778, 0),
(578, 16, 771, 0),
(817, 25, 953, 0),
(729, 16, 906, 0),
(686, 16, 870, 0),
(798, 16, 948, 0);

DELETE FROM `quest_poi` WHERE (`QuestID`=33868 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=33868 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=34737 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=34737 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=34737 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=34737 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=34737 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=34429 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=34429 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=34429 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=34429 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=34429 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=34429 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49136 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49136 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49136 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=31459 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(33868, 0, 1, 32, 0, 0, 1116, 525, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(33868, 0, 0, -1, 0, 0, 1116, 525, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34737, 0, 4, 32, 0, 0, 1265, 578, 0, 0, 0, 0, 0, 898338, 0, 38134), -- -Unknown-
(34737, 0, 3, 2, 272984, 79593, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34737, 0, 2, 1, 272983, 79585, 1265, 578, 0, 0, 0, 0, 0, 868748, 0, 38134), -- -Unknown-
(34737, 0, 1, 0, 272982, 79583, 1265, 578, 0, 0, 0, 0, 0, 868749, 0, 38134), -- -Unknown-
(34737, 0, 0, -1, 0, 0, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34429, 0, 5, 32, 0, 0, 1265, 577, 0, 0, 0, 0, 0, 896150, 0, 38134), -- -Unknown-
(34429, 0, 4, 3, 273759, 82140, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34429, 0, 3, 2, 273763, 82142, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34429, 0, 2, 1, 273713, 82066, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34429, 0, 1, 0, 273758, 82139, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(34429, 0, 0, -1, 0, 0, 1265, 577, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(49136, 0, 2, 32, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1395965, 0, 38134), -- -Unknown-
(49136, 0, 1, 0, 293814, 128184, 1642, 863, 0, 0, 0, 0, 0, 1396924, 0, 38134), -- -Unknown-
(49136, 0, 0, -1, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1395965, 0, 38134), -- -Unknown-
(31459, 0, 0, -1, 0, 0, 870, 379, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

DELETE FROM `quest_poi_points` WHERE (`QuestID`=33868 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=33868 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=34737 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=34737 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=34737 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=34737 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=34737 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=34429 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=34429 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=11) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=10) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=34429 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=34429 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=34429 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=34429 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49136 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49136 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49136 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=31459 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(33868, 1, 0, 5523, 5012, 0, 38134), -- -Unknown-
(33868, 0, 0, 5540, 5012, 13, 38134), -- -Unknown-
(34737, 4, 0, 4498, -2629, 1, 38134), -- -Unknown-
(34737, 3, 0, 4614, -2474, 14, 38134), -- -Unknown-
(34737, 2, 0, 4614, -2525, 28, 38134), -- -Unknown-
(34737, 1, 0, 4429, -2465, 25, 38134), -- -Unknown-
(34737, 0, 0, 4517, -2494, 16, 38134), -- -Unknown-
(34429, 5, 0, 4230, -2813, 5, 38134), -- -Unknown-
(34429, 4, 0, 4511, -2635, 1, 38134), -- -Unknown-
(34429, 3, 11, 4397, -2870, 17, 38134), -- -Unknown-
(34429, 3, 10, 4371, -2867, 17, 38134), -- -Unknown-
(34429, 3, 9, 4354, -2844, 17, 38134), -- -Unknown-
(34429, 3, 8, 4355, -2812, 17, 38134), -- -Unknown-
(34429, 3, 7, 4368, -2790, 17, 38134), -- -Unknown-
(34429, 3, 6, 4385, -2782, 17, 38134), -- -Unknown-
(34429, 3, 5, 4420, -2784, 17, 38134), -- -Unknown-
(34429, 3, 4, 4436, -2791, 17, 38134), -- -Unknown-
(34429, 3, 3, 4447, -2814, 17, 38134), -- -Unknown-
(34429, 3, 2, 4446, -2841, 17, 38134), -- -Unknown-
(34429, 3, 1, 4434, -2862, 17, 38134), -- -Unknown-
(34429, 3, 0, 4410, -2871, 17, 38134), -- -Unknown-
(34429, 2, 11, 4397, -2870, 17, 38134), -- -Unknown-
(34429, 2, 10, 4371, -2867, 17, 38134), -- -Unknown-
(34429, 2, 9, 4354, -2844, 17, 38134), -- -Unknown-
(34429, 2, 8, 4355, -2812, 17, 38134), -- -Unknown-
(34429, 2, 7, 4368, -2790, 17, 38134), -- -Unknown-
(34429, 2, 6, 4385, -2782, 17, 38134), -- -Unknown-
(34429, 2, 5, 4420, -2784, 17, 38134), -- -Unknown-
(34429, 2, 4, 4436, -2791, 17, 38134), -- -Unknown-
(34429, 2, 3, 4447, -2814, 17, 38134), -- -Unknown-
(34429, 2, 2, 4446, -2841, 17, 38134), -- -Unknown-
(34429, 2, 1, 4434, -2862, 17, 38134), -- -Unknown-
(34429, 2, 0, 4410, -2871, 17, 38134), -- -Unknown-
(34429, 1, 11, 4397, -2870, 17, 38134), -- -Unknown-
(34429, 1, 10, 4371, -2867, 17, 38134), -- -Unknown-
(34429, 1, 9, 4354, -2844, 17, 38134), -- -Unknown-
(34429, 1, 8, 4355, -2812, 17, 38134), -- -Unknown-
(34429, 1, 7, 4368, -2790, 17, 38134), -- -Unknown-
(34429, 1, 6, 4385, -2782, 17, 38134), -- -Unknown-
(34429, 1, 5, 4420, -2784, 17, 38134), -- -Unknown-
(34429, 1, 4, 4436, -2791, 17, 38134), -- -Unknown-
(34429, 1, 3, 4447, -2814, 17, 38134), -- -Unknown-
(34429, 1, 2, 4446, -2841, 17, 38134), -- -Unknown-
(34429, 1, 1, 4434, -2862, 17, 38134), -- -Unknown-
(34429, 1, 0, 4410, -2871, 17, 38134), -- -Unknown-
(34429, 0, 0, 4511, -2635, 1, 38134), -- -Unknown-
(49136, 2, 0, 2593, 475, 1, 38134), -- -Unknown-
(49136, 1, 0, 2904, 234, 8, 38134), -- -Unknown-
(49136, 0, 0, 2593, 475, 1, 38134), -- -Unknown-
(31459, 0, 0, 3044, 1251, 655, 38134); -- -Unknown-


DELETE FROM `quest_details` WHERE `ID`=32674;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(32674, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID` IN (49160 /*-Unknown-*/, 35005 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(49160, 0, 0, 0, 0, 'You can read that scroll, can you?', 38134), -- -Unknown-
(35005, 0, 0, 0, 0, 'These prisoners are no less brave than you or I, $n. Give them a weapon and an ounce of hope and they will fight like the storm.', 0); -- -Unknown-

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=167220 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=164041 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=167960 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=167771 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-11788.7001953125, `PositionY`=-3855.64990234375, `PositionZ`=60.029998779296875, `VerifiedBuild`=38134 WHERE (`ID`=171229 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `MapID`=1330, `PositionX`=5565.7998046875, `PositionY`=4593.5, `PositionZ`=140.8899993896484375 WHERE (`ID`=171253 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=-11.109999656677246, `PositionY`=6746.18994140625, `VerifiedBuild`=38134 WHERE (`ID`=296901 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=35715 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=121847 AND `EffectIndex`=0);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=1 AND `Entry` IN (72849,85003,86775,79252));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(72849, 1, 10, 40, 0, 0, 64, 38134),
(85003, 1, 1, 1, 0, 0, 371, 38134),
(86775, 1, 10, 40, 0, 0, 302, 38134),
(79252, 1, 10, 40, 0, 0, 302, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80172 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80174 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=82715 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=75416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=75417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79756 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=76928 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=83482 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=79774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=79916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=86614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=301, `VerifiedBuild`=38134 WHERE (`Entry`=79603 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=80600 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=79407 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=80437 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=80436 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=88649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=80432 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=76872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=80440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=80438 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=78320 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=80299 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=80288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=79605 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=79925 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=79781 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=85253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=88427 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=88985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80222 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80202 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=302, `VerifiedBuild`=38134 WHERE (`Entry`=79301 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79729 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=86906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80330 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78478 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78495 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78487 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=2113, `VerifiedBuild`=38134 WHERE (`Entry`=79687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78466 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79529 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80779 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80419 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79525 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78314 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=86000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78272 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=78288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=70859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=79451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=76411 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80241 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=64, `VerifiedBuild`=38134 WHERE (`Entry`=80192 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=84050 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=44664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=44663 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=44665 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=44659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=84049 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78563 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=86039 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=86691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=86690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=83441 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81063 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80468 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80783 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81016 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=982, `VerifiedBuild`=38134 WHERE (`Entry`=13117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=982, `VerifiedBuild`=38134 WHERE (`Entry`=13116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63096 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160692 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=160681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=1, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160686 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=64786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=163510 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=163509 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=163508 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163699 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163697 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163683 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=163680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=970, `VerifiedBuild`=38134 WHERE (`Entry`=160691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=163700 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81367 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78994 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79707 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79583 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78561 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=79661 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82373 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79589 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79590 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79097 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82057 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79537 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82530 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80290 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79403 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78650 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78560 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78651 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81926 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81895 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78905 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=83670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=85145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78820 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=85141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=86780 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=80715 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78589 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78591 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78590 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78529 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78559 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81761 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78573 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=85856 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78510 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78509 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=83652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=83651 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79062 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78333 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82305 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82647 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=83538 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76648 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82001 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82263 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78569 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81993 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82004 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81997 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82189 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82025 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81994 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82264 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79316 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82259 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82013 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82011 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82010 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81995 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82015 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82016 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=81990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79315 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82005 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82260 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78430 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=79675 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=77653 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78193 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=6491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=77090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61326 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=78674 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=34, `VerifiedBuild`=38134 WHERE (`Entry`=5985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82003 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76189 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76503 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=84199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=15, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=34, `VerifiedBuild`=38134 WHERE (`Entry`=5992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82273 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=34, `VerifiedBuild`=38134 WHERE (`Entry`=5983 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76522 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76500 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=82851 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=34, `VerifiedBuild`=38134 WHERE (`Entry`=5990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76520 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76519 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=9699 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76524 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=85734 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=85247 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=76886 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=31727 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=31726 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=31725 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=31724 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=31723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=31720 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=60242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=125222 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123548 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123544 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123546 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123547 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=122198 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=125242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125154 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136342 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125230 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=125229 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=125241 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=125240 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131286 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=135026 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131155 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123233 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123461 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=131269 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131458 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123831 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125203 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123455 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123539 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123832 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123453 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123810 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130502 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125214 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=123450 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124631 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123436 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123178 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143050 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=124996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125211 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131156 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131157 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125213 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125207 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131254 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131169 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131168 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=143317 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120551 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122334 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123328 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126039 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124547 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120560 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124383 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122240 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131299 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122991 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=132020 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=132021 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131993 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=131213 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126213 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=141840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124301 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=121207 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=120804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124302 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124300 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=120588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128734 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130268 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=123647 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130796 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129164 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=140830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=132025 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=132030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=132031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=130224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133980 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=125992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128185 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128186 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128184 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128005 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128371 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128235 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128033 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=663, `VerifiedBuild`=38134 WHERE (`Entry`=14645 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=981, `VerifiedBuild`=38134 WHERE (`Entry`=42615 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=981, `VerifiedBuild`=38134 WHERE (`Entry`=51128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=981, `VerifiedBuild`=38134 WHERE (`Entry`=51126 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=981, `VerifiedBuild`=38134 WHERE (`Entry`=51127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=981, `VerifiedBuild`=38134 WHERE (`Entry`=51130 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127925 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=150412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=122276 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138583 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128179 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129461 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=129462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127921 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127961 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127960 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127958 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127847 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=794, `VerifiedBuild`=38134 WHERE (`Entry`=129545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127493 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127864 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138817 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127928 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128900 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138816 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130446 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138815 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127902 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60715;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59830;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61080;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=60001;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55547;
UPDATE `creature_model_info` SET `BoundingRadius`=2.869888782501220703, `CombatReach`=1.836734771728515625, `VerifiedBuild`=38134 WHERE `DisplayID`=52706;
UPDATE `creature_model_info` SET `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=55319;
UPDATE `creature_model_info` SET `BoundingRadius`=2.869888782501220703, `CombatReach`=1.836734771728515625, `VerifiedBuild`=38134 WHERE `DisplayID`=55316;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58611;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54432;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58610;
UPDATE `creature_model_info` SET `BoundingRadius`=0.267973870038986206, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=43163;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=59765;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56543;
UPDATE `creature_model_info` SET `BoundingRadius`=0.410187005996704101, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=58744;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55595;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55756;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59842;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=46172;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54554;
UPDATE `creature_model_info` SET `BoundingRadius`=1.507900357246398925, `CombatReach`=2.585714101791381835, `VerifiedBuild`=38134 WHERE `DisplayID`=61638;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52371;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=35312;
UPDATE `creature_model_info` SET `BoundingRadius`=1.048227906227111816, `VerifiedBuild`=38134 WHERE `DisplayID`=61121;
UPDATE `creature_model_info` SET `BoundingRadius`=2.611331939697265625, `VerifiedBuild`=38134 WHERE `DisplayID`=56633;
UPDATE `creature_model_info` SET `BoundingRadius`=1.507900357246398925, `CombatReach`=2.585714101791381835, `VerifiedBuild`=38134 WHERE `DisplayID`=61639;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53532;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=55672;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55603;
UPDATE `creature_model_info` SET `BoundingRadius`=2.915829658508300781, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=52374;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52373;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61126;
UPDATE `creature_model_info` SET `BoundingRadius`=4.314821243286132812, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=55721;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54957;
UPDATE `creature_model_info` SET `BoundingRadius`=2.012644052505493164, `CombatReach`=1.1661224365234375, `VerifiedBuild`=38134 WHERE `DisplayID`=55571;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58102;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30759;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30756;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30757;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30758;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58101;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56416;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56414;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56413;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56415;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53587;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520799994468688964, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=56207;
UPDATE `creature_model_info` SET `BoundingRadius`=0.259600013494491577, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56757;
UPDATE `creature_model_info` SET `BoundingRadius`=5.571620464324951171, `CombatReach`=6.25, `VerifiedBuild`=38134 WHERE `DisplayID`=58197;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=59854;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=3.799999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=59866;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=55736;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53637;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=57707;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56755;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=56752;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56756;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=56753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=56754;
UPDATE `creature_model_info` SET `BoundingRadius`=2.172716379165649414, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=55983;
UPDATE `creature_model_info` SET `BoundingRadius`=2.172716379165649414, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=51998;
UPDATE `creature_model_info` SET `BoundingRadius`=0.502200007438659667, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56370;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520799994468688964, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=56749;
UPDATE `creature_model_info` SET `BoundingRadius`=0.483599990606307983, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=56747;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520799994468688964, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=56750;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=13339;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=13337;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39627;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=40620;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40829;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39621;
UPDATE `creature_model_info` SET `BoundingRadius`=2.217561006546020507, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=39358;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=41898;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39646;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44084;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=42031;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40921;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40916;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40906;
UPDATE `creature_model_info` SET `BoundingRadius`=0.99294358491897583, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=44109;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43361;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2408;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47054;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47058;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44332;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44198;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2405;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47072;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40828;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47057;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44185;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42462;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44327;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759995520114898681, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39553;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=95277;
UPDATE `creature_model_info` SET `BoundingRadius`=0.539400041103363037, `CombatReach`=2.175000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=56751;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=56746;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=56748;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=56745;
UPDATE `creature_model_info` SET `BoundingRadius`=0.283200025558471679, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=55212;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20000004768371582, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=60214;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=55278;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=54245;
UPDATE `creature_model_info` SET `BoundingRadius`=0.283200025558471679, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=55208;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=55207;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54894;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.543993115425109863, `VerifiedBuild`=38134 WHERE `DisplayID`=56969;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56739;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56740;
UPDATE `creature_model_info` SET `BoundingRadius`=0.543993115425109863, `VerifiedBuild`=38134 WHERE `DisplayID`=56967;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54897;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54895;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54896;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56738;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54576;
UPDATE `creature_model_info` SET `BoundingRadius`=1.126714944839477539, `CombatReach`=2.799999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=55867;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54759;
UPDATE `creature_model_info` SET `BoundingRadius`=0.427799999713897705, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=54814;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52435;
UPDATE `creature_model_info` SET `BoundingRadius`=5.490011215209960937, `CombatReach`=12.5, `VerifiedBuild`=38134 WHERE `DisplayID`=52911;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54760;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58205;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33005;
UPDATE `creature_model_info` SET `BoundingRadius`=0.713853776454925537, `VerifiedBuild`=38134 WHERE `DisplayID`=58206;
UPDATE `creature_model_info` SET `BoundingRadius`=0.713853776454925537, `VerifiedBuild`=38134 WHERE `DisplayID`=58204;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58209;
UPDATE `creature_model_info` SET `BoundingRadius`=0.713853776454925537, `VerifiedBuild`=38134 WHERE `DisplayID`=58208;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58210;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=58207;
UPDATE `creature_model_info` SET `BoundingRadius`=0.595200002193450927, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56720;
UPDATE `creature_model_info` SET `BoundingRadius`=0.377600014209747314, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56608;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54758;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=60225;
UPDATE `creature_model_info` SET `BoundingRadius`=1.048227906227111816, `VerifiedBuild`=38134 WHERE `DisplayID`=57413;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58668;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58666;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58669;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=58667;
UPDATE `creature_model_info` SET `BoundingRadius`=1.048227906227111816, `VerifiedBuild`=38134 WHERE `DisplayID`=57410;
UPDATE `creature_model_info` SET `BoundingRadius`=3.016618728637695312, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=52415;
UPDATE `creature_model_info` SET `BoundingRadius`=1.118460893630981445, `VerifiedBuild`=38134 WHERE `DisplayID`=57412;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35803;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54578;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54575;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520799994468688964, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=56743;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59103;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54577;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=55029;
UPDATE `creature_model_info` SET `BoundingRadius`=0.483599990606307983, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=56742;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59101;
UPDATE `creature_model_info` SET `BoundingRadius`=0.259600013494491577, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=52028;
UPDATE `creature_model_info` SET `BoundingRadius`=0.502200007438659667, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=56744;
UPDATE `creature_model_info` SET `BoundingRadius`=2.197226285934448242, `VerifiedBuild`=38134 WHERE `DisplayID`=58758;
UPDATE `creature_model_info` SET `BoundingRadius`=0.502200007438659667, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=57853;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53438;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=57869;
UPDATE `creature_model_info` SET `BoundingRadius`=1.759163737297058105, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59707;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=57870;
UPDATE `creature_model_info` SET `BoundingRadius`=1.25, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=57867;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=57868;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520799994468688964, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=57854;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=56548;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55047;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=57168;
UPDATE `creature_model_info` SET `BoundingRadius`=11.22445011138916015, `CombatReach`=12.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56977;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59620;
UPDATE `creature_model_info` SET `BoundingRadius`=0.613799989223480224, `CombatReach`=2.474999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=57780;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=57165;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=57166;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59619;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59618;
UPDATE `creature_model_info` SET `BoundingRadius`=1.439259529113769531, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=59808;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=57167;
UPDATE `creature_model_info` SET `BoundingRadius`=0.502200007438659667, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=59614;
UPDATE `creature_model_info` SET `BoundingRadius`=0.483599990606307983, `CombatReach`=1.95000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=59613;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306799978017807006, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=59616;
UPDATE `creature_model_info` SET `BoundingRadius`=0.318599998950958251, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=59615;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=56765;
UPDATE `creature_model_info` SET `BoundingRadius`=0.613799989223480224, `CombatReach`=2.474999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=57781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54659;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53357;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56796;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56794;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56928;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52528;
UPDATE `creature_model_info` SET `BoundingRadius`=1.338706493377685546, `VerifiedBuild`=38134 WHERE `DisplayID`=56774;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56881;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56785;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56782;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56882;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52540;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56776;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56802;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56789;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56779;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56793;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56929;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29405;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=56879;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56925;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=56792;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56784;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56783;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56780;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56781;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=56798;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=56799;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56778;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56883;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=56773;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56800;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36185;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56772;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=55046;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56791;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56771;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56880;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56926;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=50650;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52434;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58494;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=61871;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56833;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56777;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56826;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53998;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53681;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54363;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5233;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53682;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54646;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53155;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54639;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54647;
UPDATE `creature_model_info` SET `BoundingRadius`=0.724374592304229736, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=2714;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=56801;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53355;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53183;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53256;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53257;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=53332;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53259;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53262;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53261;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58186;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3026;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53699;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16882;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53272;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53271;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53258;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53276;
UPDATE `creature_model_info` SET `BoundingRadius`=3.004200458526611328, `VerifiedBuild`=38134 WHERE `DisplayID`=2743;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53270;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53269;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53274;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53275;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53277;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33221;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53514;
UPDATE `creature_model_info` SET `BoundingRadius`=0.704809427261352539, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=48515;
UPDATE `creature_model_info` SET `BoundingRadius`=0.244800001382827758, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=30316;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88735;
UPDATE `creature_model_info` SET `BoundingRadius`=1.044361352920532226, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=5775;
UPDATE `creature_model_info` SET `BoundingRadius`=3.625804424285888671, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=41363;
UPDATE `creature_model_info` SET `BoundingRadius`=5.96703195571899414, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=12209;
UPDATE `creature_model_info` SET `BoundingRadius`=0.948167622089385986, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=77429;
UPDATE `creature_model_info` SET `BoundingRadius`=5.709749221801757812, `CombatReach`=7, `VerifiedBuild`=38134 WHERE `DisplayID`=67607;
UPDATE `creature_model_info` SET `BoundingRadius`=3.311084747314453125, `CombatReach`=4.050000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=32348;
UPDATE `creature_model_info` SET `BoundingRadius`=1.648991703987121582, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=77427;
UPDATE `creature_model_info` SET `BoundingRadius`=1.094039678573608398, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78391;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81737;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81733;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81077;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30313;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=77392;
UPDATE `creature_model_info` SET `BoundingRadius`=1.611232161521911621, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84331;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81730;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985729217529296, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=27849;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=30312;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77394;
UPDATE `creature_model_info` SET `BoundingRadius`=4.282311916351318359, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=66814;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=81738;
UPDATE `creature_model_info` SET `BoundingRadius`=0.729359745979309082, `VerifiedBuild`=38134 WHERE `DisplayID`=81706;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83218;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77395;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=42751;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77393;
UPDATE `creature_model_info` SET `BoundingRadius`=1.648991703987121582, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=77651;
UPDATE `creature_model_info` SET `BoundingRadius`=0.729359745979309082, `VerifiedBuild`=38134 WHERE `DisplayID`=77428;
UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=50962;
UPDATE `creature_model_info` SET `BoundingRadius`=1.099327802658081054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77426;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30314;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30315;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=34160;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81736;
UPDATE `creature_model_info` SET `BoundingRadius`=1.272553205490112304, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80375;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47273;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81734;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81735;
UPDATE `creature_model_info` SET `BoundingRadius`=1.938240408897399902, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=33453;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32814;
UPDATE `creature_model_info` SET `BoundingRadius`=3.613313913345336914, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=78372;
UPDATE `creature_model_info` SET `BoundingRadius`=3.648767948150634765, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=78164;
UPDATE `creature_model_info` SET `BoundingRadius`=2.181008815765380859, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84329;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80467;
UPDATE `creature_model_info` SET `BoundingRadius`=0.757188200950622558, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78437;
UPDATE `creature_model_info` SET `BoundingRadius`=9.244469642639160156, `CombatReach`=16.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76791;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=76793;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80091;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84006;
UPDATE `creature_model_info` SET `BoundingRadius`=1.745316624641418457, `CombatReach`=3.860999822616577148, `VerifiedBuild`=38134 WHERE `DisplayID`=76129;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86145;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86147;
UPDATE `creature_model_info` SET `BoundingRadius`=0.348477542400360107, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=77988;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=77990;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=82368;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86146;
UPDATE `creature_model_info` SET `BoundingRadius`=1.41093301773071289, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=76795;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86148;
UPDATE `creature_model_info` SET `BoundingRadius`=1.41093301773071289, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=76794;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82367;
UPDATE `creature_model_info` SET `BoundingRadius`=1.546077370643615722, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=76851;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77981;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77693;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75969;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=75967;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81058;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=42407;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77486;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01109480857849121, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=77067;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75968;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81055;
UPDATE `creature_model_info` SET `BoundingRadius`=1.514376401901245117, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=77554;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77943;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79270;
UPDATE `creature_model_info` SET `BoundingRadius`=1.514376401901245117, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=77553;
UPDATE `creature_model_info` SET `BoundingRadius`=1.514376401901245117, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=77552;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47990;
UPDATE `creature_model_info` SET `BoundingRadius`=3.45185708999633789, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=53767;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47992;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77687;
UPDATE `creature_model_info` SET `BoundingRadius`=0.240000009536743164, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=47989;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81377;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75891;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81376;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77491;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342625141143798828, `CombatReach`=0.300000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199187994003295898, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=29596;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81428;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80419;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81427;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80418;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199187994003295898, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=29594;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81380;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199187994003295898, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=76694;
UPDATE `creature_model_info` SET `BoundingRadius`=4.409517288208007812, `CombatReach`=6.600000381469726562 WHERE `DisplayID`=78853;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=80155;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028887391090393066, `CombatReach`=1.539999961853027343, `VerifiedBuild`=38134 WHERE `DisplayID`=79232;
UPDATE `creature_model_info` SET `BoundingRadius`=0.656697094440460205, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=79170;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230400562286376953, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=75850;
UPDATE `creature_model_info` SET `BoundingRadius`=2.799999952316284179, `CombatReach`=12, `VerifiedBuild`=38134 WHERE `DisplayID`=61773;
UPDATE `creature_model_info` SET `BoundingRadius`=1.097076892852783203, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=84871;
UPDATE `creature_model_info` SET `BoundingRadius`=0.410187005996704101, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=58745;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=81098;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=1.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=79788;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77689;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83189;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79697;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=78854;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75889;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=75892;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79698;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75890;
UPDATE `creature_model_info` SET `BoundingRadius`=6.851508140563964843, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=78991;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76728;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591772913932800292, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=76727;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=389;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18751;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18749;
UPDATE `creature_model_info` SET `BoundingRadius`=0.320209264755249023, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=36332;
UPDATE `creature_model_info` SET `BoundingRadius`=0.192125573754310607, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30412;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34890;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33346;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33347;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18752;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=18750;
UPDATE `creature_model_info` SET `BoundingRadius`=0.256167411804199218, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=36336;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17759;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33348;
UPDATE `creature_model_info` SET `BoundingRadius`=2.170666217803955078, `VerifiedBuild`=38134 WHERE `DisplayID`=76653;
UPDATE `creature_model_info` SET `BoundingRadius`=0.075000002980232238, `CombatReach`=0.075000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=80457;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=2956;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `VerifiedBuild`=38134 WHERE `DisplayID`=91019;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85386;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79694;
UPDATE `creature_model_info` SET `BoundingRadius`=6.444928646087646484, `CombatReach`=10, `VerifiedBuild`=38134 WHERE `DisplayID`=85881;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=85146;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79693;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80611;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19986;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79691;
UPDATE `creature_model_info` SET `BoundingRadius`=1.578887343406677246, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=83648;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79692;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85218;
UPDATE `creature_model_info` SET `BoundingRadius`=1.254667878150939941, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=85217;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23856;
UPDATE `creature_model_info` SET `BoundingRadius`=0.292758256196975708, `CombatReach`=0.375, `VerifiedBuild`=38134 WHERE `DisplayID`=79015;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75961;
UPDATE `creature_model_info` SET `BoundingRadius`=1.866102457046508789, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77903;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38732;
UPDATE `creature_model_info` SET `BoundingRadius`=3.01109480857849121, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=79629;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79501;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86019;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79502;
UPDATE `creature_model_info` SET `BoundingRadius`=0.691260099411010742, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79500;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=75882;
UPDATE `creature_model_info` SET `BoundingRadius`=1.832476615905761718, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79591;
UPDATE `creature_model_info` SET `BoundingRadius`=1.832476615905761718, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79585;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=75884;
UPDATE `creature_model_info` SET `BoundingRadius`=2.577971458435058593, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=84376;
UPDATE `creature_model_info` SET `BoundingRadius`=0.035000000149011611, `CombatReach`=0.100000001490116119, `VerifiedBuild`=38134 WHERE `DisplayID`=47512;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=75883;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840021967887878417, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=75885;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=78131;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79988;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413480490446090698, `CombatReach`=0.200000002980232238, `VerifiedBuild`=38134 WHERE `DisplayID`=81218;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79987;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79986;
UPDATE `creature_model_info` SET `BoundingRadius`=0.591166138648986816, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79985;

DELETE FROM `npc_vendor` WHERE (`entry`=78568 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(78568, 3, 180733, 0, 0, 1, 0, 0, 38134); -- Luminous Flux

UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=120959 AND `ExtendedCost`=0 AND `type`=1); -- Pinchwhistle "Nitro Fuel"
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=119324 AND `ExtendedCost`=0 AND `type`=1); -- Savage Remedy
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=119022 AND `ExtendedCost`=0 AND `type`=1); -- Shadowmoon Sugar Pear Cider
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117439 AND `ExtendedCost`=0 AND `type`=1); -- "Da Bruisery" Hot & Wroth
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117442 AND `ExtendedCost`=0 AND `type`=1); -- Thunderbelly Mead
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117440 AND `ExtendedCost`=0 AND `type`=1); -- Peglegger's Porter
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117568 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Ironwine
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117453 AND `ExtendedCost`=0 AND `type`=1); -- "Da Bruisery" OPA
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117437 AND `ExtendedCost`=0 AND `type`=1); -- Skyreach Sunrise
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=117441 AND `ExtendedCost`=0 AND `type`=1); -- Elekk's Neck
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=78568 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (86775,79252,86614,80225,80209,80202,79301,86906,80330,78478,78495,78272,78288,80415,70859,79451,80783,81016,160689,160687,163510,163697,163689,163694,163687,163700,76504,76503,76521,76500,82851,76520,76524,85247,124547,131978,132025,128185,51130,127960)) OR (`ID`=2 AND `CreatureID` IN (76503,51130,51128)) OR (`ID`=4 AND `CreatureID`=51128) OR (`ID`=3 AND `CreatureID`=51128);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(86775, 1, 2901, 0, 0, 0, 0, 0, 0, 0, 0), -- Senior Peon II
(79252, 1, 32425, 0, 0, 0, 0, 0, 0, 0, 0), -- Cordana Felsong
(86614, 1, 60985, 0, 0, 0, 0, 0, 49462, 0, 0), -- Murla Longeye
(80225, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Skaggit
(80209, 1, 109674, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrall
(80202, 1, 14084, 0, 0, 0, 0, 0, 0, 0, 0), -- Olin Umberhide
(79301, 1, 2901, 0, 0, 0, 0, 0, 0, 0, 0), -- Horde Peon
(86906, 1, 2901, 0, 0, 0, 0, 0, 0, 0, 0), -- Senior Peon II
(80330, 1, 24321, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrison Battlemage
(78478, 1, 29433, 0, 0, 0, 0, 0, 0, 0, 0), -- Shadow Hunter Kajassa
(78495, 1, 29433, 0, 0, 0, 0, 0, 0, 0, 0), -- Shadow Hunter Ukambe
(78272, 1, 94647, 0, 0, 0, 0, 0, 0, 0, 0), -- Durotan
(78288, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0), -- Archmage Khadgar
(80415, 1, 163831, 0, 0, 163832, 0, 0, 0, 0, 0), -- Lady Liadrin
(70859, 1, 109674, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrall
(79451, 1, 14084, 0, 0, 0, 0, 0, 0, 0, 0), -- Olin Umberhide
(80783, 1, 110235, 0, 0, 0, 0, 0, 0, 0, 0), -- Liberated Frostwolf Prisoner
(81016, 1, 110235, 0, 0, 0, 0, 0, 0, 0, 0), -- Liberated Frostwolf Prisoner
(160689, 1, 79719, 0, 0, 0, 0, 0, 0, 0, 0), -- Brewmaster
(160687, 1, 82351, 0, 0, 0, 0, 0, 0, 0, 0), -- Field Hand
(163510, 1, 3364, 0, 0, 4067, 0, 0, 5261, 0, 0), -- Alliance Peacekeeper
(163697, 1, 31309, 0, 0, 0, 0, 0, 0, 0, 0), -- Alliance Druid
(163689, 1, 1485, 0, 0, 0, 0, 0, 5260, 0, 0), -- Halfhill Defender
(163694, 1, 18608, 0, 0, 0, 0, 0, 0, 0, 0), -- Alliance Priest
(163687, 1, 82351, 0, 0, 0, 0, 0, 0, 0, 0), -- Den Mudclaw
(163700, 1, 65492, 0, 0, 111717, 0, 0, 62400, 0, 0), -- Alliance Footman
(76504, 1, 43175, 0, 0, 46957, 0, 0, 0, 0, 0), -- Cap'n Gorok
(76503, 2, 1905, 0, 0, 2081, 0, 0, 0, 0, 0), -- Hatchet Cannoneer
(76503, 1, 1905, 0, 0, 0, 0, 0, 0, 0, 0), -- Hatchet Cannoneer
(76521, 1, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Alkra Hammerslam
(76500, 1, 10898, 0, 0, 1905, 0, 0, 0, 0, 0), -- Orgrimmar Sea Dog
(82851, 1, 109674, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrall
(76520, 1, 2196, 0, 0, 0, 0, 0, 0, 0, 0), -- Ulzann
(76524, 1, 91813, 0, 0, 0, 0, 0, 91812, 0, 0), -- Grizzled Grenadier
(85247, 1, 29433, 0, 0, 0, 0, 0, 0, 0, 0), -- Rokhan
(124547, 1, 128193, 0, 0, 0, 0, 0, 0, 0, 0), -- Bloodhunter Drudge
(131978, 1, 116391, 0, 0, 0, 0, 0, 0, 0, 0), -- Lashk
(132025, 1, 153588, 0, 0, 0, 0, 0, 0, 0, 0), -- Mi'ja
(128185, 1, 116391, 0, 0, 0, 0, 0, 0, 0, 0), -- Lashk
(51128, 4, 1485, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(51128, 3, 14533, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(51130, 2, 12294, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(51128, 2, 2901, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(51130, 1, 37, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(127960, 1, 116391, 0, 0, 0, 0, 0, 0, 0, 0); -- -Unknown-

UPDATE `creature_equip_template` SET `ItemID1`=109232, `ItemID2`=108474 WHERE (`CreatureID`=79589 AND `ID`=3); -- Shadowmoon Voidaxe
UPDATE `creature_equip_template` SET `ItemID1`=110396, `ItemID2`=108475 WHERE (`CreatureID`=79589 AND `ID`=2); -- Shadowmoon Voidaxe
UPDATE `creature_equip_template` SET `ItemID1`=112013, `ItemID2`=0 WHERE (`CreatureID`=83538 AND `ID`=2); -- Warsong Commander
UPDATE `creature_equip_template` SET `ItemID1`=112388, `ItemID2`=107159 WHERE (`CreatureID`=83538 AND `ID`=1); -- Warsong Commander
UPDATE `creature_equip_template` SET `ItemID1`=163831, `ItemID2`=163832 WHERE (`CreatureID`=79675 AND `ID`=1); -- Lady Liadrin
UPDATE `creature_equip_template` SET `ItemID1`=37 WHERE (`CreatureID`=51128 AND `ID`=1); -- -Unknown-

DELETE FROM `gossip_menu` WHERE (`MenuId`=16420 AND `TextId`=23790) OR (`MenuId`=17090 AND `TextId`=25119) OR (`MenuId`=16475 AND `TextId`=23892) OR (`MenuId`=23796 AND `TextId`=37252) OR (`MenuId`=23793 AND `TextId`=37234);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(16420, 23790, 38134), -- 78466 (Gazlowe)
(17090, 25119, 38134), -- 86775 (Senior Peon II)
(16475, 23892, 38134), -- 80225 (Skaggit)
(23796, 37252, 38134), -- 149626
(23793, 37234, 38134); -- 149523

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `TextId`=23994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16432 AND `TextId`=23823); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16432 AND `TextId`=23823); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16641 AND `TextId`=24170); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16641 AND `TextId`=24170); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16376 AND `TextId`=23740); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16433 AND `TextId`=23824); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16863 AND `TextId`=24524); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21310 AND `TextId`=32367); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22256 AND `TextId`=34097); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22255 AND `TextId`=34096); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22254 AND `TextId`=34095); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22254 AND `TextId`=34095); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21656 AND `TextId`=32981); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21661 AND `TextId`=32991); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=7 AND `MenuId`=16593) OR (`OptionIndex`=0 AND `MenuId` IN (17090,16475)) OR (`OptionIndex`=1 AND `MenuId`=23796);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(16593, 7, 0, 'I\'m responding to the Steamwheedle call for help. Take me to the Spires of Arak.', 88555, 38134),
(17090, 0, 0, 'Gazlowe needs you.', 88705, 38134),
(16475, 0, 0, 'Get the peons back to work.', 82740, 38134),
(23796, 1, 0, 'I must help Khadgar. Send me to the Blasted Lands!', 168994, 38134);



UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16518 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16641 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16641 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=38134 WHERE (`MenuId`=16863 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=147751, `VerifiedBuild`=38134 WHERE (`MenuId`=22256 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=147749, `VerifiedBuild`=38134 WHERE (`MenuId`=22255 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=147747, `VerifiedBuild`=38134 WHERE (`MenuId`=22254 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=147747, `VerifiedBuild`=38134 WHERE (`MenuId`=22254 AND `OptionIndex`=0);




UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80172; -- Bladespire Raider
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2681, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80174; -- Pack Boar
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.857142865657806396, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=82715; -- Frostfur Rat
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1712, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=75416; -- Coldsnout Boar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1712, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=75417; -- Coldsnout Piglet
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1712, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=79756; -- Coldsnout Sow
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `speed_walk`=1.399999976158142089, `speed_run`=1.428571462631225585, `RangeAttackTime`=0, `unit_flags2`=2099200 WHERE `entry`=72849; -- Driftwatcher Rylak
UPDATE `creature_template` SET `npcflag`=1073741824, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=85003; -- Icespine Hatchling
UPDATE `creature_template` SET `gossip_menu_id`=17090, `minlevel`=40, `maxlevel`=40, `npcflag`=0, `RangeAttackTime`=0, `unit_flags`=0, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=86775; -- Senior Peon II
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=79619; -- Rezlak
UPDATE `creature_template` SET `minlevel`=92, `maxlevel`=92, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=79252; -- Cordana Felsong
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=83858; -- Khadgar's Servant
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=76928; -- Kraank
UPDATE `creature_template` SET `minlevel`=-20, `maxlevel`=-20 WHERE `entry`=83482; -- Yu'rina the Mystic
UPDATE `creature_template` SET `npcflag`=17179869187 WHERE `entry`=79774; -- Sergeant Grimjaw
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=17179869187, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=86614; -- Murla Longeye
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=80151; -- Provisioner Rashma
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=79407; -- Bron Skyhorn
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=0 WHERE `entry`=80432; -- Command Table
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=76872; -- Supplymaster Eri
UPDATE `creature_template` SET `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=85253; -- Twilight Wasp
UPDATE `creature_template` SET `maxlevel`=1, `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=88427; -- Twilight Wasp
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=88985; -- Frostfur Rat
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=80223; -- Lady Sena
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=90, `maxlevel`=90, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=512, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=80225; -- Skaggit
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=80209; -- Thrall
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=3000, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480, `dynamicflags`=4 WHERE `entry`=79903; -- Skog
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2361, `RangeAttackTime`=0, `unit_flags`=16, `unit_flags2`=2048 WHERE `entry`=80202; -- Olin Umberhide
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `RangeAttackTime`=0, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=79301; -- Horde Peon
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=33554432, `unit_flags2`=2048, `VehicleId`=3537 WHERE `entry`=79729; -- Dead Peon
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1801, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=86906; -- Senior Peon II
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=2 WHERE `entry`=79740; -- Warmaster Zog
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2201, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80330; -- Garrison Battlemage
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78478; -- Shadow Hunter Kajassa
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78495; -- Shadow Hunter Ukambe
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `unit_flags3`=0 WHERE `entry`=78487; -- Rokhan
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=85, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79687; -- Vol'jin's Pride Grunt
UPDATE `creature_template` SET `gossip_menu_id`=16420 WHERE `entry`=78466; -- Gazlowe
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79529; -- Frostfire Gronnling
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2574, `BaseAttackTime`=2000, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=78919; -- Icehoof Cow
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=33554432, `unit_flags2`=2048, `VehicleId`=3532 WHERE `entry`=79574; -- Dead Clefthoof
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80779; -- Icespine Ravager
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2099200, `VehicleId`=3576 WHERE `entry`=80419; -- Frostfire Gronnling
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=190, `RangeAttackTime`=0, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=80420; -- Icehoof Calf
UPDATE `creature_template` SET `minlevel`=92, `maxlevel`=92, `RangeAttackTime`=0, `unit_flags2`=2099200 WHERE `entry`=80227; -- Icewing Drift-Hunter
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=1, `RangeAttackTime`=0, `unit_flags`=33555200, `unit_flags2`=71862272, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=79525; -- Tree
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=0, `unit_flags2`=2099200 WHERE `entry`=78314; -- Glacial Icemaw
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=86000; -- Gentle Clefthoof
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=78272; -- Durotan
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=1, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=78288; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `HoverHeight`=1.25 WHERE `entry`=80242; -- Chillfang
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=1, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=80415; -- Lady Liadrin
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=70859; -- Thrall
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2361, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=79451; -- Olin Umberhide
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_walk`=1.399999976158142089, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=80241; -- Blazing Pyreclaw
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=80192; -- Icecave Bat
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=84050; -- Fallen Hero of Auchindoun
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=44664; -- Water Totem
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=44663; -- Air Totem
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=44665; -- Earth Totem
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=44659; -- Fire Totem
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=84049; -- Fallen Hero of Karabor
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81014; -- Iron Grunt
UPDATE `creature_template` SET `gossip_menu_id`=16518, `minlevel`=90, `maxlevel`=90, `npcflag`=4739, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=80521; -- Thaelin Darkanvil
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=78563; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `dynamicflags`=4 WHERE `entry`=80574; -- Overseer Gotrigg
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2111, `npcflag`=0, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `dynamicflags`=4 WHERE `entry`=86039; -- Gogluk
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2111, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=86691; -- Gun Turret
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2111, `speed_walk`=0.400000005960464477, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=86690; -- Cannon Turret
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81422; -- Blackrock Deadeye
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=79917; -- Ga'nar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2111, `BaseAttackTime`=1200, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81129; -- Burning Blade Saberguard
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0, `unit_flags2`=32768 WHERE `entry`=83441; -- Cluster Bomb Palette
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81063; -- Blackrock Laborer
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80468; -- Blackrock Machinist
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=80775; -- Ogron Warcrusher
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80783; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81016; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80786; -- Blackrock Grunt
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=13117; -- Horde Spirit Guide
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=13116; -- Alliance Spirit Guide
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160690; -- Chin
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33816576, `unit_flags2`=2048 WHERE `entry`=160689; -- Brewmaster
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160688; -- Dawn Watcher
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33849600, `unit_flags2`=2048, `unit_flags3`=1, `HoverHeight`=1.60000002384185791 WHERE `entry`=160682; -- Speckled Trout
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33816576, `unit_flags2`=2048 WHERE `entry`=160680; -- Monk
UPDATE `creature_template` SET `maxlevel`=1, `npcflag`=1073741824, `RangeAttackTime`=0, `unit_flags`=262656, `unit_flags2`=2048 WHERE `entry`=63096; -- Marsh Fiddler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33850112, `unit_flags2`=2048 WHERE `entry`=160692; -- Yu'lon Priest
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33816576, `unit_flags2`=2048 WHERE `entry`=160681; -- Tanuki
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160687; -- Field Hand
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160686; -- Halfhill Villager
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160685; -- Piggy
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160684; -- Twitchheel Hoarder
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=262144, `unit_flags2`=2048 WHERE `entry`=64786; -- Marsh Fiddler
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1802, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163510; -- Alliance Peacekeeper
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1732, `npcflag`=128, `BaseAttackTime`=1000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163509; -- Sarya Teaflower
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1735, `npcflag`=640, `BaseAttackTime`=1000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163508; -- Tina Wang
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=12, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163699; -- Riding Horse
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=84, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags3`=1 WHERE `entry`=163697; -- Alliance Druid
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=84, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=33556480, `unit_flags3`=1 WHERE `entry`=163689; -- Halfhill Defender
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=2201, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163695; -- Swift Gray Wolf
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=84, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163694; -- Alliance Priest
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163683; -- Tang Ironhoe
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=29, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163682; -- Warchief's Herald
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1735, `npcflag`=128, `BaseAttackTime`=1000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163681; -- Brewmaster Roland
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1735, `npcflag`=128, `BaseAttackTime`=1000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163680; -- Hoka Stonecrush
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=294912, `unit_flags2`=2048 WHERE `entry`=163687; -- Den Mudclaw
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=1732, `npcflag`=128, `BaseAttackTime`=1000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163684; -- Aster
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33849344, `unit_flags2`=2048 WHERE `entry`=160691; -- Ink-Tipped Crane
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags3`=1 WHERE `entry`=163696; -- Horde Grunt
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `faction`=123, `BaseAttackTime`=2000, `unit_flags`=295680, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=163700; -- Alliance Footman
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81357; -- Blackrock Slaghauler
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=78562; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81367; -- Blackrock Forgeworker
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=537166144, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=79593; -- Ankova the Fallen
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78994; -- Yrel
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32848, `unit_flags2`=2048 WHERE `entry`=79702; -- Keli'dan the Breaker
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67108864 WHERE `entry`=79707; -- Void Totem
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `dynamicflags`=4 WHERE `entry`=79583; -- Ungra
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `dynamicflags`=4 WHERE `entry`=79585; -- Taskmaster Gurran
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=78561; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=79661; -- Luuka
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=82373; -- Void Wolf
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79589; -- Shadowmoon Voidaxe
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1924, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79590; -- Shadowmoon Ritualist
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=82141; -- Shattered Hand Brawler
UPDATE `creature_template` SET `minlevel`=103, `maxlevel`=103, `speed_walk`=3.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=79097; -- Kargath Bladefist
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `speed_walk`=0.100000001490116119, `speed_run`=0.114285714924335479, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=82057; -- Shattered Hand Brawler
UPDATE `creature_template` SET `minlevel`=95, `maxlevel`=95, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18432 WHERE `entry`=78996; -- Farseer Drek'Thar
UPDATE `creature_template` SET `minlevel`=95, `maxlevel`=95, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=79537; -- Exarch Maladaar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=3698 WHERE `entry`=82530; -- Mandragora
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=49152 WHERE `entry`=80290; -- Dying Prisoner
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags2`=100665344 WHERE `entry`=79403; -- Tanaan Rope Bunny
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=78650; -- Shattered Hand Torturer
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=78560; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=78651; -- Shattered Hand Bonechopper
UPDATE `creature_template` SET `minlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=81926; -- Kilrogg Deadeye
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=81895; -- Bleeding Hollow Bloodchosen
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=18433, `unit_flags3`=8192, `dynamicflags`=128 WHERE `entry`=78905; -- Battered Frostwolf Prisoner
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78830; -- Bleeding Hollow Ritualist
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=18433, `unit_flags3`=8192, `dynamicflags`=128 WHERE `entry`=78906; -- Battered Karabor Prisoner
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `HoverHeight`=3 WHERE `entry`=83670; -- Blood Ritual Orb
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81901; -- Bleeding Hollow Savage
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85145; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=80803; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `VehicleId`=3479 WHERE `entry`=78768; -- Hanging Orc Vehicle
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78820; -- Bleeding Hollow Savage
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2636, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=85141; -- Frostwolf Slave
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=86780; -- Napestone Riverbeast
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1965, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=80715; -- Deathspine Ravager
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=78589; -- Snake
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=78591; -- Small Spider
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=78590; -- Spider
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2636, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=78529; -- Frostwolf Slave
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=78559; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2636, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=16384 WHERE `entry`=81761; -- Ashka
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2636, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=16384, `dynamicflags`=0 WHERE `entry`=78573; -- Korag
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85856; -- Bloodthirsty Axebeak
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78510; -- Bleeding Hollow Hatchet
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=78507; -- Bleeding Hollow Savage
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `speed_walk`=1.60000002384185791, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=78509; -- Bleeding Hollow Berserker
UPDATE `creature_template` SET `minlevel`=96, `maxlevel`=96, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=81696; -- Teron'gor
UPDATE `creature_template` SET `minlevel`=3, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=4196352 WHERE `entry`=82624; -- Grommash Hellscream
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=98, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=81695; -- Cho'gall
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=83652; -- Battered Draenei Prisoner
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=83651; -- Battered Frostwolf Prisoner
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=79062; -- Arnold Croman
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `speed_walk`=0.400000005960464477, `speed_run`=1, `RangeAttackTime`=0, `unit_flags`=33554688, `unit_flags2`=4196352 WHERE `entry`=82417; -- Iron Horde War Machine
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=81711; -- Shadowmoon Ritualist
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=18432, `HoverHeight`=1 WHERE `entry`=78333; -- Gul'dan
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872 WHERE `entry`=82305; -- Khadgar Shield Target
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=33587472, `unit_flags2`=2048 WHERE `entry`=82647; -- Tormented Soul
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78883; -- Iron Grunt
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=4229120 WHERE `entry`=78558; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=83538; -- Warsong Commander
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78696; -- Ironmarch Champion
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76648; -- Ironmarch Scarhide
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33040, `unit_flags2`=2048 WHERE `entry`=81998; -- Anruin
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82001; -- Monishot
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82000; -- Elaynea Welton the Wind and Sea
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82263; -- Agios Lumen
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33040, `unit_flags2`=18432 WHERE `entry`=78569; -- Hansel Heavyhands
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81993; -- Starcaller Astrylian
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82004; -- Salty Futz
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81997; -- Roague
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81996; -- Turkina
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82189; -- Lupas
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `npcflag`=4739, `BaseAttackTime`=2000, `unit_flags`=33040, `unit_flags2`=18432 WHERE `entry`=78568; -- Thaelin Darkanvil
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82025; -- Yoori
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82002; -- Alya
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81999; -- Nevo
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81994; -- Corselle
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82014; -- Archon
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82264; -- Johnny Oshimo
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=18432 WHERE `entry`=79316; -- Qiana Moonshadow
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82187; -- Etubrute
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82259; -- Thrend
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82013; -- Plainsmender Darragh
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82011; -- Northpaul
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82010; -- Bonesaw
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81995; -- Maelgwyn
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82009; -- Barbery the Crazy Cat Lady
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82015; -- Moonalli
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82016; -- Durphorn the Bullheaded
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=82008; -- Malothas
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82191; -- High Warlord Shoju
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82006; -- Pazo Stonehoof
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82017; -- Miserain Starsorrow
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=90, `maxlevel`=90, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=18432 WHERE `entry`=78556; -- Ariok
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=81990; -- Moriccalas
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=18432 WHERE `entry`=79315; -- Olin Umberhide
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82012; -- Kengtus Pranch the Patient
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82005; -- Challe Tebrilinde
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82188; -- Mumper
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82260; -- Rainiara the Kingslayer
UPDATE `creature_template` SET `minlevel`=92, `maxlevel`=92, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=78430; -- Cordana Felsong
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=79675; -- Lady Liadrin
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=18432 WHERE `entry`=78554; -- Vindicator Maraad
UPDATE `creature_template` SET `gossip_menu_id`=16863, `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=78423; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82082; -- Racy
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82007; -- Tore
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18432 WHERE `entry`=78553; -- Thrall
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=82075; -- Ryii the Shameless
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=77653; -- Ironmarch Warsmith
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78193; -- Ironmarch Gundriver
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000 WHERE `entry`=6491; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `RangeAttackTime`=0 WHERE `entry`=77090; -- Ironmarch Forager
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=61326; -- Scorpid
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=78670; -- Ironmarch Warcaster
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=78667; -- Ironmarch Legionnaire
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=78674; -- Ironmarch Scorcher
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=5985; -- Snickerfang Hyena
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=4196352 WHERE `entry`=82003; -- Ed
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76556; -- Ironmarch Grunt
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2502, `BaseAttackTime`=3000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76189; -- Ironmarch Grunt
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=15476; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1935, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76504; -- Cap'n Gorok
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1935, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=76503; -- Hatchet Cannoneer
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=84199; -- Iron Horde Capsule
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction`=14, `RangeAttackTime`=0, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=5992; -- Ashmane Boar
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=40, `npcflag`=16777216, `speed_walk`=0.400000005960464477, `speed_run`=1, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=71321600, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=82273; -- Iron Demolisher
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0 WHERE `entry`=5983; -- Bonepicker Felfeeder
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1735, `npcflag`=2688, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=76522; -- Zerpy Clampshock
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1735, `npcflag`=4224, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=76521; -- Alkra Hammerslam
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1935, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76500; -- Orgrimmar Sea Dog
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=82851; -- Thrall
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1, `RangeAttackTime`=0, `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=5990; -- Redstone Basilisk
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1735, `npcflag`=640, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=76520; -- Ulzann
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1735, `npcflag`=16, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=76519; -- Rott Bonefinger
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=9699; -- Fire Beetle
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=1801, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76524; -- Grizzled Grenadier
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1734, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85734; -- Ameri Windblade
UPDATE `creature_template` SET `minlevel`=93, `maxlevel`=93, `npcflag`=3, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=85247; -- Rokhan
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=76886; -- Ironmarch Scout
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=25075; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=31727; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=31726; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=31725; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=31724; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=31723; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=31720; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=149404; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=23796 WHERE `entry`=149626; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=23793 WHERE `entry`=149523; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=62114; -- Spiny Lizard
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `faction`=31, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=60242; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125222; -- Unbound Tide Elemental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123548; -- Ticker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123544; -- Patch
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123545; -- Newt
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123546; -- Volt
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123547; -- Grit
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=122198; -- Zibir the Wingmaster
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125242; -- Vilescale Scavenger
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=125154; -- Hungry Shoalfin Thresher
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136342; -- Lurking Sandskin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125230; -- Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125229; -- Vilescale Tidebinder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125241; -- Vilescale Goliath
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123550; -- Lord Slithin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123588; -- Vilescale Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125240; -- Vilescale Hydromancer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131286; -- Corrupted Energy
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123400; -- Volt
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135026; -- Lucky Horace
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131152; -- Faceless Subjugator
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131155; -- Nazwathan Guardian
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131151; -- Faceless Destroyer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123233; -- Grit
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=123461; -- Vilescale Behemoth
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=131269; -- Vilescale Relic Hunter
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131458; -- Void Portal
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123831; -- Captive Sailor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=125203; -- Defiant Sailor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123455; -- Spiny Kelp Clicker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123539; -- Injured Sailor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123832; -- Vilescale Slaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=123453; -- Vilescale Sorceress
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123810; -- Hardshell Sand Sifter
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130502; -- Thornfin Seahorse
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125214; -- Krubbs
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=123450; -- Vilescale Fathom-Hunter
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124631; -- Frogmarsh Riverbeast
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123436; -- Ticker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123178; -- Patch
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143050; -- Young Sand Sifter
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124996; -- Alabaster Gull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125211; -- Matriarch Jawbreaker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131156; -- Nazwathan Hulk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131288; -- Gruesh's Brood
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131157; -- Nazwathan Blood Bender
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=125212; -- Patriarch Jawbreaker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=125213; -- Juvenile Jawbreaker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125205; -- Coastal Jawbreaker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125207; -- Peering Shrieker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=570458880, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=125206; -- Sharptooth Scavenger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=131285; -- Reanimated Monstrosity
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131254; -- Titan Keeper Shavras
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=16 WHERE `entry`=131169; -- Nazwathan Spectre
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=131168; -- Blood-Infused Lasher
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143317; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=120551; -- Krag'wa the Huge
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122334; -- Dreadtick Nest
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `HoverHeight`=1.299999952316284179 WHERE `entry`=122335; -- Young Dreadtick
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123328; -- Warmother Boatema
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126039; -- Mag'ash the Poisonous
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126052; -- Bloodhunter Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120572; -- Roughback Leaper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=124547; -- Bloodhunter Drudge
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124504; -- Spawn of Krag'wa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `HoverHeight`=1.299999952316284179 WHERE `entry`=120560; -- Marshfly Dreadtick
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124383; -- Shadow Hunter Mutumba
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122240; -- Bloodhunter Cursecarver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122239; -- Bloodhunter Stalker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131299; -- Deactivated Titan Keeper
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124376; -- Witch Doctor Zentimo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122991; -- Shadow Hunter Mutumba
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132020; -- Tortollan Warrior
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132021; -- Tortollan Mystic
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131978; -- Lashk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131993; -- Yash
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131988; -- Korkush
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131213; -- Rokhan
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126213; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131987; -- Crez
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141840; -- Snaps
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130225; -- Mire Whelk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124301; -- Saurolisk Matriarch
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=121207; -- Cuja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=120804; -- Darkspear Scout
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130199; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124302; -- Saurolisk Youngling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124300; -- Saurolisk Patriarch
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123083; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120554; -- Spawn of Krag'wa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=120588; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123423; -- River Shrieker
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131210; -- Yash
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130226; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128734; -- Amaki Guard
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130268; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123647; -- Saurolisk
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=130796; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130815; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=129164; -- Chronicler Jabari
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131209; -- Korkush
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130217; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140830; -- Nazmani Skitterer
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128930; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132025; -- Mi'ja
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132030; -- Adolescent Crawg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=136606; -- Ju'mak
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132031; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131208; -- Crez
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130224; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=133980; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125992; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=124917; -- Natha'vor Sacrifice
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126014; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130218; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128185; -- Lashk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128186; -- Princess Talanji
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128187; -- Kisha
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128184; -- Jungo, Herald of G'huun
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138606; -- Drained Blood Troll
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129127; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127915; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `speed_run`=1.714285731315612792, `BaseAttackTime`=1333, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=128005; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128006; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128267; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128371; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128145; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128235; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128033; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126381; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128048; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=33555200 WHERE `entry`=14645; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=42615; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=51128; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=51126; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1, `speed_run`=2.285714387893676757, `RangeAttackTime`=0, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=51127; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=51130; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127925; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128044; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130634; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=150412; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=122276; -- Taloc
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127919; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138583; -- Visage of Jungo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128179; -- Sanctifying Totem
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129461; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129462; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130636; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=127869; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127870; -- Scrounger Youngling
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127921; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127961; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127960; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127958; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130566; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127847; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags2`=34816 WHERE `entry`=129545; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127493; -- Coastal Swooper
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127864; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138817; -- The Shredder
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127928; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128900; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127968; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32848 WHERE `entry`=127903; -- Reanimated Horror
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127929; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130212; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138816; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127907; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=127854; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=130446; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138815; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127902; -- -Unknown-

UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300 WHERE `ID`=34823; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300 WHERE `ID`=34822; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34824; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=410, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=36862; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34378; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34765; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34592; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34375; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `RewardSpell`=158587, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34364; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=410, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=38567; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=33543; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2500, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34402; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=410, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=33815; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=410, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=33868; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4950, `FlagsEx`=2175040, `VerifiedBuild`=38134 WHERE `ID`=34446; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4950, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=34445; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=35747; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1650, `FlagsEx`=2105412, `VerifiedBuild`=38134 WHERE `ID`=34437; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34925; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=34958; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34987; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34442; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2900, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29926; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4950, `FlagsEx`=2170946, `VerifiedBuild`=38134 WHERE `ID`=34439; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=35005; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=202200, `RewardBonusMoney`=7450, `RewardSpell`=259545, `FlagsEx`=6291522, `QuestDescription`='Would you like to hear how the nightborne came to join the Horde?\n\nWe earned their trust when we aided them in liberating Suramar from the tyranny of Grand Magistrix Elisande and the Burning Legion.\n\nLor\'themar Theron later asked them to join him in Quel\'Thalas. Lady Liadrin made the journey to extend the invitation to First Arcanist Thalyssra...', `VerifiedBuild`=38134 WHERE `ID`=49973; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=17630, `RewardBonusMoney`=420, `FlagsEx`=35651904, `VerifiedBuild`=38134 WHERE `ID`=42175; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=352560, `RewardBonusMoney`=4250, `FlagsEx`=6291520, `VerifiedBuild`=38134 WHERE `ID`=37656; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=352560, `RewardBonusMoney`=4250, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=37450; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=410, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=34867; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=16980, `RewardBonusMoney`=410 WHERE `ID`=34209; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3150, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=28656; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `RewardBonusMoney`=3400, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=48992; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `RewardBonusMoney`=3400, `FlagsEx`=6316096, `VerifiedBuild`=38134 WHERE `ID`=48991; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `RewardBonusMoney`=3400, `FlagsEx`=6299712, `VerifiedBuild`=38134 WHERE `ID`=48993; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `RewardBonusMoney`=3400, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31903; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `RewardBonusMoney`=3400, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31891; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `RewardBonusMoney`=3400 WHERE `ID`=51771; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=38946; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=176280, `FlagsEx`=2097216, `ItemDropQuantity1`=1, `VerifiedBuild`=38134 WHERE `ID`=26556; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=17630, `RewardBonusMoney`=420 WHERE `ID`=51532; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34741; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34740; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34739; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34737; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=4150, `RewardSpell`=165634, `FlagsEx`=2170946, `VerifiedBuild`=38134 WHERE `ID`=34429; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34427; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1650, `RewardSpell`=81040, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34425; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2162758, `VerifiedBuild`=38134 WHERE `ID`=34423; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=35241; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34421; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `StartItem`=113191, `FlagsEx`=2170944, `ItemDrop1`=113191, `ItemDropQuantity1`=1, `VerifiedBuild`=38134 WHERE `ID`=34422; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=410, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34420; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34393; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2170944, `VerifiedBuild`=38134 WHERE `ID`=34392; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=35933; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=25674; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1650, `FlagsEx`=2162752, `VerifiedBuild`=38134 WHERE `ID`=34398; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=32674; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=339600, `RewardBonusMoney`=4150, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47711; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47596; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47599; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47597; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=16980, `RewardBonusMoney`=410, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47631; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=339600, `RewardBonusMoney`=6600, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47756; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=48402; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47660; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=339600, `RewardBonusMoney`=4150, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47659; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=509400, `RewardBonusMoney`=4950, `FlagsEx`=2097216, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=52477; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=16980, `RewardBonusMoney`=410, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47525; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=84900, `RewardBonusMoney`=1650, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47245; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=16980, `RewardBonusMoney`=410, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49902; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=16980, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49160; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=509400, `RewardBonusMoney`=4950, `FlagsEx`=2105408, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=49136; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=42431; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=43241; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=38842; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=40316; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=39371; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=40050; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=37779; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=37965; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=40111; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=6600 WHERE `ID`=37466; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49132; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49131; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=169800, `RewardBonusMoney`=3300, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=49130; -- -Unknown-


UPDATE `quest_objectives` SET `Description`='Speak with Senior Peon II', `VerifiedBuild`=38134 WHERE `ID`=275373; -- 275373
UPDATE `quest_objectives` SET `Description`='Investigate your Garrison Cache', `VerifiedBuild`=38134 WHERE `ID`=273086; -- 273086
UPDATE `quest_objectives` SET `Description`='Instruct Skaggit to release the peons', `VerifiedBuild`=38134 WHERE `ID`=273085; -- 273085
UPDATE `quest_objectives` SET `Description`='Travel to Pinchwhistle Gearworks', `VerifiedBuild`=38134 WHERE `ID`=275334; -- 275334
UPDATE `quest_objectives` SET `Description`='Use the Master Surveyor to watch your Garrison be constructed', `VerifiedBuild`=38134 WHERE `ID`=272928; -- 272928
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273016; -- 273016
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=272861; -- 272861
UPDATE `quest_objectives` SET `Description`='Trees marked for peons', `VerifiedBuild`=38134 WHERE `ID`=272601; -- 272601
UPDATE `quest_objectives` SET `Description`='Horde Banner Planted', `VerifiedBuild`=38134 WHERE `ID`=272600; -- 272600
UPDATE `quest_objectives` SET `Description`='Peacefully approach Deadgrin', `VerifiedBuild`=38134 WHERE `ID`=271524; -- 271524
UPDATE `quest_objectives` SET `Description`='Ride with Durotan', `VerifiedBuild`=38134 WHERE `ID`=272647; -- 272647
UPDATE `quest_objectives` SET `Description`='Introduced to Durotan', `VerifiedBuild`=38134 WHERE `ID`=272643; -- 272643
UPDATE `quest_objectives` SET `Description`='Get to the docks', `VerifiedBuild`=38134 WHERE `ID`=273401; -- 273401
UPDATE `quest_objectives` SET `Description`='Press the Main Cannon Trigger', `VerifiedBuild`=38134 WHERE `ID`=273397; -- 273397
UPDATE `quest_objectives` SET `Description`='Iron Horde slain', `VerifiedBuild`=38134 WHERE `ID`=273041; -- 273041
UPDATE `quest_objectives` SET `Description`='Enter the Worldbreaker Side Turret', `VerifiedBuild`=38134 WHERE `ID`=273388; -- 273388
UPDATE `quest_objectives` SET `Description`='Climb the rear chains of the Iron Worldbreaker', `VerifiedBuild`=38134 WHERE `ID`=274030; -- 274030
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=274994; -- 274994
UPDATE `quest_objectives` SET `Description`='Speak with Thaelin', `VerifiedBuild`=38134 WHERE `ID`=274029; -- 274029
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273246; -- 273246
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273259; -- 273259
UPDATE `quest_objectives` SET `Description`='Depress the Makeshift Plunger', `VerifiedBuild`=38134 WHERE `ID`=273296; -- 273296
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273294; -- 273294
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255450; -- 255450
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255449; -- 255449
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273336; -- 273336
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273211; -- 273211
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273320; -- 273320
UPDATE `quest_objectives` SET `Description`='Cast the spell, \"Teleport: Hall of the Guardian\"', `VerifiedBuild`=38134 WHERE `ID`=286598; -- 286598
UPDATE `quest_objectives` SET `Description`='Demon Hunters freed', `VerifiedBuild`=38134 WHERE `ID`=277252; -- 277252
UPDATE `quest_objectives` SET `Description`='First chain unlocked', `VerifiedBuild`=38134 WHERE `ID`=283274; -- 283274
UPDATE `quest_objectives` SET `Description`='Chains unlocked', `VerifiedBuild`=38134 WHERE `ID`=277273; -- 277273
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=277456; -- 277456
UPDATE `quest_objectives` SET `Description`='Find Stellagosa', `VerifiedBuild`=38134 WHERE `ID`=277290; -- 277290
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293693; -- 293693
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293649; -- 293649
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293695; -- 293695
UPDATE `quest_objectives` SET `Description`='Defeat Durin Darkhammer', `VerifiedBuild`=38134 WHERE `ID`=269185; -- 269185
UPDATE `quest_objectives` SET `Description`='Defeat Everessa', `VerifiedBuild`=38134 WHERE `ID`=269184; -- 269184
UPDATE `quest_objectives` SET `Description`='Defeat Kortas Darkhammer', `VerifiedBuild`=38134 WHERE `ID`=269183; -- 269183
UPDATE `quest_objectives` SET `Description`='Defeat Deiza Plaguehorn', `VerifiedBuild`=38134 WHERE `ID`=269182; -- 269182
UPDATE `quest_objectives` SET `Description`='Defeat David Kosse', `VerifiedBuild`=38134 WHERE `ID`=269181; -- 269181
UPDATE `quest_objectives` SET `Description`='Defeat Elena Flutterfly', `VerifiedBuild`=38134 WHERE `ID`=269155; -- 269155
UPDATE `quest_objectives` SET `Description`='Defeat Zoltan', `VerifiedBuild`=38134 WHERE `ID`=269154; -- 269154
UPDATE `quest_objectives` SET `Description`='Defeat Kela Grimtotem', `VerifiedBuild`=38134 WHERE `ID`=269153; -- 269153
UPDATE `quest_objectives` SET `Description`='Defeat Grazzle the Great', `VerifiedBuild`=38134 WHERE `ID`=269152; -- 269152
UPDATE `quest_objectives` SET `Description`='Defeat Traitor Gluk', `VerifiedBuild`=38134 WHERE `ID`=269151; -- 269151
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252865; -- 252865
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=272989; -- 272989
UPDATE `quest_objectives` SET `Description`='Escort Yrel to safety', `VerifiedBuild`=38134 WHERE `ID`=272988; -- 272988
UPDATE `quest_objectives` SET `Description`='Enemy slain in the Umbral Halls', `VerifiedBuild`=38134 WHERE `ID`=272987; -- 272987
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=272984; -- 272984
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=272983; -- 272983
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=272982; -- 272982
UPDATE `quest_objectives` SET `Description`='Escape Kargath\'s arena', `VerifiedBuild`=38134 WHERE `ID`=273759; -- 273759
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=273763; -- 273763
UPDATE `quest_objectives` SET `Description`='Combatants slain in the arena', `VerifiedBuild`=38134 WHERE `ID`=273713; -- 273713
UPDATE `quest_objectives` SET `Description`='Enter the arena', `VerifiedBuild`=38134 WHERE `ID`=273758; -- 273758
UPDATE `quest_objectives` SET `Description`='Farseer Drek\'Thar freed', `VerifiedBuild`=38134 WHERE `ID`=272869; -- 272869
UPDATE `quest_objectives` SET `Description`='Follow Khadgar', `VerifiedBuild`=38134 WHERE `ID`=273737; -- 273737
UPDATE `quest_objectives` SET `Description`='Find Khadgar on Tar\'thog Bridge', `VerifiedBuild`=38134 WHERE `ID`=274409; -- 274409
UPDATE `quest_objectives` SET `Description`='Blood Ritual Orb destroyed', `VerifiedBuild`=38134 WHERE `ID`=273678; -- 273678
UPDATE `quest_objectives` SET `Description`='Escort Ariok to the Bleeding Altar', `VerifiedBuild`=38134 WHERE `ID`=273677; -- 273677
UPDATE `quest_objectives` SET `Description`='Speak with Ariok', `VerifiedBuild`=38134 WHERE `ID`=273075; -- 273075
UPDATE `quest_objectives` SET `Description`='Bleeding Hollow orc slain', `VerifiedBuild`=38134 WHERE `ID`=273644; -- 273644
UPDATE `quest_objectives` SET `Description`='Southern cage opened', `VerifiedBuild`=38134 WHERE `ID`=272710; -- 272710
UPDATE `quest_objectives` SET `Description`='Eastern cage opened', `VerifiedBuild`=38134 WHERE `ID`=272692; -- 272692
UPDATE `quest_objectives` SET `Description`='Bleeding Hollow huts burned', `VerifiedBuild`=38134 WHERE `ID`=273635; -- 273635
UPDATE `quest_objectives` SET `Description`='Stasis Rune destroyed', `VerifiedBuild`=38134 WHERE `ID`=273936; -- 273936
UPDATE `quest_objectives` SET `Description`='Mark of the Blackrock destroyed', `VerifiedBuild`=38134 WHERE `ID`=273557; -- 273557
UPDATE `quest_objectives` SET `Description`='Mark of the Shattered Hand destroyed', `VerifiedBuild`=38134 WHERE `ID`=273556; -- 273556
UPDATE `quest_objectives` SET `Description`='Mark of the Burning Blade destroyed', `VerifiedBuild`=38134 WHERE `ID`=273438; -- 273438
UPDATE `quest_objectives` SET `Description`='Enter Gul\'dan\'s prison', `VerifiedBuild`=38134 WHERE `ID`=273930; -- 273930
UPDATE `quest_objectives` SET `Description`='Southern Fel Spire disabled', `VerifiedBuild`=38134 WHERE `ID`=273946; -- 273946
UPDATE `quest_objectives` SET `Description`='Northern Fel Spire disabled', `VerifiedBuild`=38134 WHERE `ID`=272621; -- 272621
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=274206; -- 274206
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=267358; -- 267358
UPDATE `quest_objectives` SET `Order`=1, `Description`='Speak with Archmage Khadgar', `VerifiedBuild`=38134 WHERE `ID`=272640; -- 272640
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388379; -- 388379
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290808; -- 290808
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290829; -- 290829
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290828; -- 290828
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290827; -- 290827
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290800; -- 290800
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290665; -- 290665
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290663; -- 290663
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290662; -- 290662
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=291381; -- 291381
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295290; -- 295290
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295289; -- 295289
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290906; -- 290906
UPDATE `quest_objectives` SET `Amount`=5, `VerifiedBuild`=38134 WHERE `ID`=292033; -- 292033
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290700; -- 290700
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290697; -- 290697
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339074; -- 339074
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290540; -- 290540
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=291225; -- 291225
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295593; -- 295593
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295592; -- 295592
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295591; -- 295591
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=295587; -- 295587
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293840; -- 293840
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293814; -- 293814
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293807; -- 293807
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293804; -- 293804
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293802; -- 293802


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272928 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272647 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273397 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273388 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274029 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273296 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273294 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273320 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273320 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273320 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273320 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273320 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273320 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=277252 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=277252 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=277252 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=277252 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=277456 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269185 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269184 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269183 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269182 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269181 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269155 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269154 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269153 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269152 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269151 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272984 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273713 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273713 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=274409 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273678 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273075 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272710 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272692 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273936 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273936 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273557 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273556 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273438 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=273946 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272621 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=272640 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=388379 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290829 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290828 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290827 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290665 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290663 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290662 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=291381 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295289 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292033 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292033 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292033 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=292033 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290540 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=290540 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=291225 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295593 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295592 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295591 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295587 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295587 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295587 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293814 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34765 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34592 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=33868 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35747 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34925 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34442 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34439 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35005 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34740 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34423 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=34420 AND `Idx`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131987; -- Crez
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131988; -- Korkush
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131993; -- Yash
UPDATE `creature_template` SET `type_flags`=2162761, `movementId`=149, `VerifiedBuild`=38134 WHERE `entry`=78314; -- Glacial Icemaw
UPDATE `creature_template` SET `movementId`=140, `VerifiedBuild`=38134 WHERE `entry`=78320; -- Frostwolf Rylak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132020; -- Tortollan Warrior
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132021; -- Tortollan Mystic
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78333; -- Gul'dan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80574; -- Overseer Gotrigg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=132025; -- Mi'ja
UPDATE `creature_template` SET `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=132030; -- Adolescent Crawg
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=38134 WHERE `entry`=80600; -- Architect Table
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82851; -- Thrall
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138817; -- The Shredder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78423; -- Archmage Khadgar
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=76189; -- Ironmarch Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85141; -- Frostwolf Slave
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78430; -- Cordana Felsong
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=85145; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123178; -- Patch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136606; -- Ju'mak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78466; -- Gazlowe
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78478; -- Shadow Hunter Kajassa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80715; -- Deathspine Ravager
UPDATE `creature_template` SET `type_flags`=266240, `VerifiedBuild`=38134 WHERE `entry`=78487; -- Rokhan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123233; -- Grit
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=78495; -- Shadow Hunter Ukambe
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163508; -- Tina Wang
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163509; -- Sarya Teaflower
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163510; -- Alliance Peacekeeper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78507; -- Bleeding Hollow Savage
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78509; -- Bleeding Hollow Berserker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78510; -- Bleeding Hollow Hatchet
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78529; -- Frostwolf Slave
UPDATE `creature_template` SET `type_flags`=6144, `VerifiedBuild`=38134 WHERE `entry`=80772; -- Sawame Brightburn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85247; -- Rokhan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80775; -- Ogron Warcrusher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80776; -- Practice Target
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85253; -- Twilight Wasp
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=80779; -- Icespine Ravager
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=80783; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80786; -- Blackrock Grunt
UPDATE `creature_template` SET `rank`=1, `type_flags`=262148, `VerifiedBuild`=38134 WHERE `entry`=78553; -- Thrall
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78554; -- Vindicator Maraad
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78556; -- Ariok
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78558; -- Archmage Khadgar
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78559; -- Archmage Khadgar
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78560; -- Archmage Khadgar
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78561; -- Archmage Khadgar
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78562; -- Archmage Khadgar
UPDATE `creature_template` SET `rank`=1, `type_flags2`=16384, `VerifiedBuild`=38134 WHERE `entry`=78563; -- Archmage Khadgar
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=80803; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=78568; -- Thaelin Darkanvil
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78569; -- Hansel Heavyhands
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78573; -- Korag
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=105419; -- Dire Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123328; -- Warmother Boatema
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=78589; -- Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=78590; -- Spider
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=78591; -- Small Spider
UPDATE `creature_template` SET `type_flags`=2147483752, `VerifiedBuild`=38134 WHERE `entry`=143505; -- Echo of Gul'dan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123372; -- Newt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62982; -- Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76411; -- Farseer Drek'Thar
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=80886; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78650; -- Shattered Hand Torturer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78651; -- Shattered Hand Bonechopper
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=127870; -- Scrounger Youngling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123400; -- Volt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78667; -- Ironmarch Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78670; -- Ironmarch Warcaster
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163680; -- Hoka Stonecrush
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123414; -- Champion of Krag'wa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78674; -- Ironmarch Scorcher
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=38134 WHERE `entry`=58542; -- Past Self
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163681; -- Brewmaster Roland
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163682; -- Warchief's Herald
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163683; -- Tang Ironhoe
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163684; -- Aster
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163687; -- Den Mudclaw
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163689; -- Halfhill Defender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123423; -- River Shrieker
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163694; -- Alliance Priest
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=163695; -- Swift Gray Wolf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127903; -- Reanimated Horror
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163696; -- Horde Grunt
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163697; -- Alliance Druid
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163699; -- Riding Horse
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=163700; -- Alliance Footman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123436; -- Ticker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78696; -- Ironmarch Champion
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=121207; -- Cuja
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123450; -- Vilescale Fathom-Hunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123453; -- Vilescale Sorceress
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123455; -- Spiny Kelp Clicker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123461; -- Vilescale Behemoth
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76500; -- Orgrimmar Sea Dog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76503; -- Hatchet Cannoneer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76504; -- Cap'n Gorok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60849; -- Jade Serpent Statue
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76519; -- Rott Bonefinger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76520; -- Ulzann
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76521; -- Alkra Hammerslam
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76522; -- Zerpy Clampshock
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76524; -- Grizzled Grenadier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78768; -- Hanging Orc Vehicle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130225; -- Mire Whelk
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=81014; -- Iron Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81016; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123526; -- Ticker
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `HealthModifier`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `entry`=76556; -- Ironmarch Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123539; -- Injured Sailor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123544; -- Patch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123545; -- Newt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123546; -- Volt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123547; -- Grit
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123548; -- Ticker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78820; -- Bleeding Hollow Savage
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=81063; -- Blackrock Laborer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78830; -- Bleeding Hollow Ritualist
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123588; -- Vilescale Warrior
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=78883; -- Iron Grunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=76648; -- Ironmarch Scarhide
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=81129; -- Burning Blade Saberguard
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=78905; -- Battered Frostwolf Prisoner
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=78906; -- Battered Karabor Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123647; -- Saurolisk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78919; -- Icehoof Cow
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81166; -- Refugee Lo'nash
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128179; -- Sanctifying Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=83441; -- Cluster Bomb Palette
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128184; -- Jungo, Herald of G'huun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128185; -- Lashk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128186; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128187; -- Kisha
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78994; -- Yrel
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=78996; -- Farseer Drek'Thar
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=83482; -- Yu'rina the Mystic
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=85734; -- Ameri Windblade
UPDATE `creature_template` SET `type`=11, `VerifiedBuild`=38134 WHERE `entry`=101398; -- Psyfiend
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81274; -- Mana Bombs Conversation Controller
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=9699; -- Fire Beetle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130502; -- Thornfin Seahorse
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126039; -- Mag'ash the Poisonous
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79062; -- Arnold Croman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=83538; -- Warsong Commander
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=83539; -- Shattered Hand Brawler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123810; -- Hardshell Sand Sifter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126052; -- Bloodhunter Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=135002; -- Demonic Tyrant
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123831; -- Captive Sailor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81329; -- Taste of Iron Conversation Controller
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123832; -- Vilescale Slaver
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=58963; -- Shivarra
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=79097; -- Kargath Bladefist
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=58964; -- Observer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135026; -- Lucky Horace
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=76872; -- Supplymaster Eri
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=121, `VerifiedBuild`=38134 WHERE `entry`=36607; -- Onyxian Whelpling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81357; -- Blackrock Slaghauler
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=76886; -- Ironmarch Scout
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81367; -- Blackrock Forgeworker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123874; -- Ticker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=123877; -- Bound Tide Elemental
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=85856; -- Bloodthirsty Axebeak
UPDATE `creature_template` SET `type_flags`=6144, `VerifiedBuild`=38134 WHERE `entry`=76928; -- Kraank
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=85882; -- Blixthraz Blastcharge
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=83651; -- Battered Frostwolf Prisoner
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=83652; -- Battered Draenei Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81422; -- Blackrock Deadeye
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=137355; -- Shadowburst Skeleton
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=83670; -- Blood Ritual Orb
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=141840; -- Snaps
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61326; -- Scorpid
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126213; -- Princess Talanji
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79252; -- Cordana Felsong
UPDATE `creature_template` SET `type_flags`=4, `VerifiedBuild`=38134 WHERE `entry`=74808; -- Thrall
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=86000; -- Gentle Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79301; -- Horde Peon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79315; -- Olin Umberhide
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79316; -- Qiana Moonshadow
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=77090; -- Ironmarch Forager
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=86039; -- Gogluk
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=155428; -- Wrenchbot
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=155431; -- Display Base: Mechagon
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=38134 WHERE `entry`=83858; -- Khadgar's Servant
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=38134 WHERE `entry`=79403; -- Tanaan Rope Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=79407; -- Bron Skyhorn
UPDATE `creature_template` SET `IconName`='workorders', `type_flags`=262144, `VerifiedBuild`=38134 WHERE `entry`=81688; -- Gorsol
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79451; -- Olin Umberhide
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=81695; -- Cho'gall
UPDATE `creature_template` SET `rank`=1, `HealthModifier`=1, `ManaModifier`=1, `VerifiedBuild`=38134 WHERE `entry`=81696; -- Teron'gor
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=81711; -- Shadowmoon Ritualist
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=88427; -- Twilight Wasp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=88443; -- Firefury Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128734; -- Amaki Guard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81761; -- Ashka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79525; -- Tree
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=79526; -- Peon Lumberjack
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=79529; -- Frostfire Gronnling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79537; -- Exarch Maladaar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=75065; -- Blood Drip
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=72849; -- Driftwatcher Rylak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124300; -- Saurolisk Patriarch
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124301; -- Saurolisk Matriarch
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=124302; -- Saurolisk Youngling
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=79574; -- Dead Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=84049; -- Fallen Hero of Karabor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=84050; -- Fallen Hero of Auchindoun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79583; -- Ungra
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79585; -- Taskmaster Gurran
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=79589; -- Shadowmoon Voidaxe
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=79590; -- Shadowmoon Ritualist
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79593; -- Ankova the Fallen
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=79603; -- Emote Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=79605; -- Frostwall Peon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79619; -- Rezlak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124376; -- Witch Doctor Zentimo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=148989; -- Lord Woofington
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124383; -- Shadow Hunter Mutumba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81895; -- Bleeding Hollow Bloodchosen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79661; -- Luuka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81901; -- Bleeding Hollow Savage
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=79675; -- Lady Liadrin
UPDATE `creature_template` SET `femaleName`='', `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=79687; -- Vol'jin's Pride Grunt
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=38134 WHERE `entry`=81926; -- Kilrogg Deadeye
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122198; -- Zibir the Wingmaster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131151; -- Faceless Destroyer
UPDATE `creature_template` SET `movementId`=44, `VerifiedBuild`=38134 WHERE `entry`=88649; -- Draka
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131152; -- Faceless Subjugator
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79702; -- Keli'dan the Breaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131155; -- Nazwathan Guardian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131156; -- Nazwathan Hulk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131157; -- Nazwathan Blood Bender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79707; -- Void Totem
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=131168; -- Blood-Infused Lasher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131169; -- Nazwathan Spectre
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=84199; -- Iron Horde Capsule
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=79729; -- Dead Peon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122239; -- Bloodhunter Stalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122240; -- Bloodhunter Cursecarver
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=79740; -- Warmaster Zog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81990; -- Moriccalas
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79756; -- Coldsnout Sow
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81993; -- Starcaller Astrylian
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131208; -- Crez
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81994; -- Corselle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131209; -- Korkush
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81995; -- Maelgwyn
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=86470; -- Pepe
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131210; -- Yash
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81996; -- Turkina
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81997; -- Roague
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81998; -- Anruin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131213; -- Rokhan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=81999; -- Nevo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82000; -- Elaynea Welton the Wind and Sea
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124504; -- Spawn of Krag'wa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82001; -- Monishot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82002; -- Alya
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82003; -- Ed
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82004; -- Salty Futz
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82005; -- Challe Tebrilinde
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82006; -- Pazo Stonehoof
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82007; -- Tore
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82008; -- Malothas
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82009; -- Barbery the Crazy Cat Lady
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82010; -- Bonesaw
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=79774; -- Sergeant Grimjaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82011; -- Northpaul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82012; -- Kengtus Pranch the Patient
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82013; -- Plainsmender Darragh
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82014; -- Archon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82015; -- Moonalli
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82016; -- Durphorn the Bullheaded
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82017; -- Miserain Starsorrow
UPDATE `creature_template` SET `type_flags`=266240, `VerifiedBuild`=38134 WHERE `entry`=79781; -- Frostwall Grunt
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=79783; -- Liberated Karabor Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82025; -- Yoori
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=79794; -- Yrel
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=79795; -- Draenei Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131254; -- Titan Keeper Shavras
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=5983; -- Bonepicker Felfeeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=5985; -- Snickerfang Hyena
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=70859; -- Thrall
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124547; -- Bloodhunter Drudge
UPDATE `creature_template` SET `family`=130, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=5990; -- Redstone Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=5992; -- Ashmane Boar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131269; -- Vilescale Relic Hunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82057; -- Shattered Hand Brawler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79822; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=79823; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=133513; -- Corpse Feeder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122334; -- Dreadtick Nest
UPDATE `creature_template` SET `rank`=6, `family`=296, `type`=1, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=122335; -- Young Dreadtick
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131285; -- Reanimated Monstrosity
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131286; -- Corrupted Energy
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131288; -- Gruesh's Brood
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82075; -- Ryii the Shameless
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82082; -- Racy
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131299; -- Deactivated Titan Keeper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=75416; -- Coldsnout Boar
UPDATE `creature_template` SET `femaleName`='', `VerifiedBuild`=38134 WHERE `entry`=77653; -- Ironmarch Warsmith
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=75417; -- Coldsnout Piglet
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=124631; -- Frogmarsh Riverbeast
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=86614; -- Murla Longeye
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=79903; -- Skog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82141; -- Shattered Hand Brawler
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=79916; -- Zaggron
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=79917; -- Ga'nar
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=79925; -- Frostwall Peon
UPDATE `creature_template` SET `type_flags`=0, `VerifiedBuild`=38134 WHERE `entry`=129164; -- Chronicler Jabari
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82187; -- Etubrute
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82188; -- Mumper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82189; -- Lupas
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82191; -- High Warlord Shoju
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=86690; -- Cannon Turret
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=86691; -- Gun Turret
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131458; -- Void Portal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=169501; -- Shadowlands Wormhole
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82259; -- Thrend
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82260; -- Rainiara the Kingslayer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82263; -- Agios Lumen
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82264; -- Johnny Oshimo
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=82273; -- Iron Demolisher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=88985; -- Frostfur Rat
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=26351; -- Horde Graveyard Teleporter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=19644; -- Image of Archmage Vargoth
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=86775; -- Senior Peon II
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82305; -- Khadgar Shield Target
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=86780; -- Napestone Riverbeast
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=82315; -- Void Monstrosity Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=82319; -- Void Monstrosity
UPDATE `creature_template` SET `femaleName`='', `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=80087; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82373; -- Void Wolf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160680; -- Monk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160681; -- Tanuki
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160682; -- Speckled Trout
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=80151; -- Provisioner Rashma
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=160684; -- Twitchheel Hoarder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160685; -- Piggy
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=160686; -- Halfhill Villager
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160687; -- Field Hand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160688; -- Dawn Watcher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160689; -- Brewmaster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160690; -- Chin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160691; -- Ink-Tipped Crane
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=160692; -- Yu'lon Priest
UPDATE `creature_template` SET `HealthScalingExpansion`=7, `VerifiedBuild`=38134 WHERE `entry`=131613; -- Hand of Fate
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80167; -- Groog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80172; -- Bladespire Raider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80174; -- Pack Boar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82417; -- Iron Horde War Machine
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=80192; -- Icecave Bat
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=86906; -- Senior Peon II
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80202; -- Olin Umberhide
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80209; -- Thrall
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80221; -- Libby Wrenchwrecker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80222; -- Mr. Pleeb
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80223; -- Lady Sena
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=80225; -- Skaggit
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=13116; -- Alliance Spirit Guide
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80227; -- Icewing Drift-Hunter
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=13117; -- Horde Spirit Guide
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=82469; -- Cluster Bomb
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80241; -- Blazing Pyreclaw
UPDATE `creature_template` SET `VignetteID`=330, `family`=24, `type`=1, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=80242; -- Chillfang
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=38134 WHERE `entry`=80244; -- Archmage Khadgar
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=124996; -- Alabaster Gull
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120551; -- Krag'wa the Huge
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=80288; -- Frostwall Peon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=120554; -- Spawn of Krag'wa
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80290; -- Dying Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=82530; -- Mandragora
UPDATE `creature_template` SET `rank`=6, `family`=296, `type_flags`=1, `VerifiedBuild`=38134 WHERE `entry`=120560; -- Marshfly Dreadtick
UPDATE `creature_template` SET `type_flags`=266240, `VerifiedBuild`=38134 WHERE `entry`=80299; -- Frostwall Axe Thrower
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=120572; -- Roughback Leaper
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=89262; -- Frostwall Peon
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=80330; -- Garrison Battlemage
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=33404; -- Wind-Up Train Wrecker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125122; -- Darkspear Scout
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=38134 WHERE `entry`=82624; -- Grommash Hellscream
UPDATE `creature_template` SET `femaleName`='', `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=82647; -- Tormented Soul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=143050; -- Young Sand Sifter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125154; -- Hungry Shoalfin Thresher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80415; -- Lady Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136342; -- Lurking Sandskin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80419; -- Frostfire Gronnling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80420; -- Icehoof Calf
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138583; -- Visage of Jungo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=31216; -- Mirror Image
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78193; -- Ironmarch Gundriver
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=140830; -- Nazmani Skitterer
UPDATE `creature_template` SET `type`=10, `VerifiedBuild`=38134 WHERE `entry`=80432; -- Command Table
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=80436; -- Cave Crab
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=80437; -- Frostwall Rat
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=80438; -- Tundra Hare
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=121, `VerifiedBuild`=38134 WHERE `entry`=80440; -- Ridge Condor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138606; -- Drained Blood Troll
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=44659; -- Fire Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=44663; -- Air Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=44664; -- Water Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=44665; -- Earth Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125203; -- Defiant Sailor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125205; -- Coastal Jawbreaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125206; -- Sharptooth Scavenger
UPDATE `creature_template` SET `type_flags`=65537, `VerifiedBuild`=38134 WHERE `entry`=125207; -- Peering Shrieker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80468; -- Blackrock Machinist
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125211; -- Matriarch Jawbreaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125212; -- Patriarch Jawbreaker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125213; -- Juvenile Jawbreaker
UPDATE `creature_template` SET `type_flags`=2097225, `VerifiedBuild`=38134 WHERE `entry`=125214; -- Krubbs
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136402; -- Ur'zul
UPDATE `creature_template` SET `movementId`=121, `VerifiedBuild`=38134 WHERE `entry`=82715; -- Frostfur Rat
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136403; -- Void Terror
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136406; -- Shivarra
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125222; -- Unbound Tide Elemental
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=122991; -- Shadow Hunter Mutumba
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125229; -- Vilescale Tidebinder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125230; -- Bunny
UPDATE `creature_template` SET `type_flags`=4096, `VerifiedBuild`=38134 WHERE `entry`=84967; -- "Appraiser" Sazsel Stickyfingers
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125240; -- Vilescale Hydromancer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125241; -- Vilescale Goliath
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=125242; -- Vilescale Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78272; -- Durotan
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=60383; -- The Golden Banana
UPDATE `creature_template` SET `family`=26, `VerifiedBuild`=38134 WHERE `entry`=127493; -- Coastal Swooper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=80521; -- Thaelin Darkanvil
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=78288; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131978; -- Lashk
UPDATE `creature_template` SET `movementId`=121, `VerifiedBuild`=38134 WHERE `entry`=85003; -- Icespine Hatchling


UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=131152 AND `Idx`=0); -- Faceless Subjugator
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=131285 AND `Idx`=0); -- Reanimated Monstrosity
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=131168 AND `Idx`=0); -- Blood-Infused Lasher
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=123328 AND `Idx`=0); -- Warmother Boatema
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=124504 AND `Idx`=0); -- Spawn of Krag'wa
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=120554 AND `Idx`=0); -- Spawn of Krag'wa
UPDATE `creature_template_model` SET `DisplayScale`=2.5 WHERE (`CreatureID`=128184 AND `Idx`=0); -- Jungo, Herald of G'huun
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=127870 AND `Idx`=0); -- Scrounger Youngling


UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233922; -- Small Timber
UPDATE `gameobject_template` SET `type`=3, `Data17`=0, `VerifiedBuild`=38134 WHERE `entry`=231064; -- Lady Sena's Other Materials Stash
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233528; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233706; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233705; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233704; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233699; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233700; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233698; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233094; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233084; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231212; -- Practice Axe
UPDATE `gameobject_template` SET `name`='Survey Tool (Green)', `VerifiedBuild`=38134 WHERE `entry`=204272; -- Survey Tool (Green)
UPDATE `gameobject_template` SET `name`='Log Stack', `VerifiedBuild`=38134 WHERE `entry`=231092; -- Log Stack
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233538; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233086; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=38134 WHERE `entry`=233082; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233090; -- Campfire
UPDATE `gameobject_template` SET `Data18`=681, `VerifiedBuild`=38134 WHERE `entry`=233633; -- Unused Wood Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=239181; -- Architect Table Collision
UPDATE `gameobject_template` SET `name`='North Gate', `VerifiedBuild`=38134 WHERE `entry`=234091; -- North Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233703; -- Campfire
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233091; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233087; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=230910; -- Debug - Garrison - Stool (Follower Test)
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=239174; -- Command Table Collision
UPDATE `gameobject_template` SET `name`='Back Gate', `VerifiedBuild`=38134 WHERE `entry`=234092; -- Back Gate
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233088; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233092; -- Chair
UPDATE `gameobject_template` SET `Data18`=681, `VerifiedBuild`=38134 WHERE `entry`=231063; -- Lady Sena's Materials Stash
UPDATE `gameobject_template` SET `type`=10, `Data0`=2824, `Data1`=0, `Data3`=0, `Data10`=261655, `Data17`=1, `Data20`=1, `Data23`=1, `VerifiedBuild`=38134 WHERE `entry`=207324; -- Warchief's Command Board
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233701; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233093; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233081; -- Large Plot
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=233089; -- Bonfire
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233085; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233083; -- Small Plot
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=233702; -- Chair
UPDATE `gameobject_template` SET `type`=10, `Data0`=0, `Data1`=0, `Data3`=0, `Data10`=161033, `Data13`=1, `Data20`=1, `Data23`=1, `VerifiedBuild`=38134 WHERE `entry`=233664; -- Master Surveyor
UPDATE `gameobject_template` SET `name`='Logs', `VerifiedBuild`=38134 WHERE `entry`=230563; -- Logs
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=230945; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `name`='Logs', `VerifiedBuild`=38134 WHERE `entry`=230562; -- Logs
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=230561; -- Bonfire
UPDATE `gameobject_template` SET `castBarCaption`='Marking', `Data0`=1690, `VerifiedBuild`=38134 WHERE `entry`=230527; -- Tree Marking
UPDATE `gameobject_template` SET `name`='Horde Banner', `VerifiedBuild`=38134 WHERE `entry`=229057; -- Horde Banner
UPDATE `gameobject_template` SET `type`=50, `IconName`='', `Data0`=2860, `Data3`=0, `Data4`=100, `Data5`=100, `Data7`=0, `Data12`=681, `Data13`=1, `Data14`=170534, `Data18`=1, `Data19`=0, `Data23`=0, `Data24`=0, `VerifiedBuild`=38134 WHERE `entry`=233117; -- Frostweed
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=233116; -- Bonfire
UPDATE `gameobject_template` SET `Data1`=60127, `VerifiedBuild`=38134 WHERE `entry`=229070; -- Fire Ammonite School
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=230544; -- Frostwolf Shamanstone
UPDATE `gameobject_template` SET `Data1`=60125, `VerifiedBuild`=38134 WHERE `entry`=229071; -- Sea Scorpion School
UPDATE `gameobject_template` SET `Data0`=1, `VerifiedBuild`=38134 WHERE `entry`=233707; -- Khadgar's Barrier (NEEDS ARCANE VERSION)
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=237994; -- Bonfire
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=237993; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=237990; -- Cookpot
UPDATE `gameobject_template` SET `name`='Dark Portal', `VerifiedBuild`=38134 WHERE `entry`=237667; -- Dark Portal
UPDATE `gameobject_template` SET `name`='Iron Horde Mace', `VerifiedBuild`=38134 WHERE `entry`=233111; -- Iron Horde Mace
UPDATE `gameobject_template` SET `name`='Iron Horde Spear', `VerifiedBuild`=38134 WHERE `entry`=233110; -- Iron Horde Spear
UPDATE `gameobject_template` SET `name`='Iron Horde Axe', `VerifiedBuild`=38134 WHERE `entry`=233109; -- Iron Horde Axe
UPDATE `gameobject_template` SET `name`='Iron Pike', `VerifiedBuild`=38134 WHERE `entry`=233108; -- Iron Pike
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231261; -- Worldbreaker Side Turret
UPDATE `gameobject_template` SET `name`='Stone Training Dummy', `VerifiedBuild`=38134 WHERE `entry`=231664; -- Stone Training Dummy
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236052; -- Doodad_6IH_IronHorde_supertank_wheel002
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236051; -- Doodad_6IH_IronHorde_supertank_wheel001
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236050; -- Doodad_6IH_IronHorde_Supertank_furnace002
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236049; -- Doodad_6IH_IronHorde_Supertank_furnace001
UPDATE `gameobject_template` SET `type`=5, `name`='Side Turret', `VerifiedBuild`=38134 WHERE `entry`=232539; -- Side Turret
UPDATE `gameobject_template` SET `castBarCaption`='Pushing', `VerifiedBuild`=38134 WHERE `entry`=232538; -- Main Cannon Trigger
UPDATE `gameobject_template` SET `name`='Slave Shackle', `VerifiedBuild`=38134 WHERE `entry`=231010; -- Slave Shackle
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `Data2`=1, `Data3`=0, `Data10`=0, `Data11`=0, `Data12`=0, `Data13`=0, `Data14`=19676, `Data21`=0, `VerifiedBuild`=38134 WHERE `entry`=231119; -- Blackrock Powder Keg
UPDATE `gameobject_template` SET `castBarCaption`='Depressing', `VerifiedBuild`=38134 WHERE `entry`=231066; -- Makeshift Plunger
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231816; -- Iron Horde Weapon Rack
UPDATE `gameobject_template` SET `name`='Bellows', `VerifiedBuild`=38134 WHERE `entry`=233097; -- Bellows
UPDATE `gameobject_template` SET `name`='Bellows', `VerifiedBuild`=38134 WHERE `entry`=233096; -- Bellows
UPDATE `gameobject_template` SET `name`='Bellows', `VerifiedBuild`=38134 WHERE `entry`=233095; -- Bellows
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231815; -- Iron Horde Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231817; -- Iron Horde Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=193963; -- Toy Train Set
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332594; -- Capture Point
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332593; -- Capture Point
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332592; -- Capture Point
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332591; -- Capture Point
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332590; -- Capture Point
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236814; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=38134 WHERE `entry`=215963; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236810; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236818; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339743; -- Campfire
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236815; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=211363; -- Refreshment Table
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236811; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236807; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236803; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236799; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=342348; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339740; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236804; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236800; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236816; -- Woodbench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236812; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236808; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339737; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236817; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339742; -- Gate
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236813; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=38134 WHERE `entry`=236809; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339739; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236805; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236801; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339713; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339711; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=343707; -- Stormstout Brew
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339738; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236806; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236802; -- Woodbench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231819; -- Iron Horde Weapon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231818; -- Iron Horde Weapon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=231820; -- Iron Horde Weapon
UPDATE `gameobject_template` SET `name`='Iron Worldbreaker', `VerifiedBuild`=38134 WHERE `entry`=236093; -- Iron Worldbreaker
UPDATE `gameobject_template` SET `name`='Cave In', `VerifiedBuild`=38134 WHERE `entry`=231197; -- Cave In
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=237996; -- Bonfire
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=237995; -- Bonfire
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=237989; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=238716; -- Forge
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=237988; -- Bonfire
UPDATE `gameobject_template` SET `name`='Ice Shard', `VerifiedBuild`=38134 WHERE `entry`=232242; -- Ice Shard
UPDATE `gameobject_template` SET `name`='Ice Shard', `VerifiedBuild`=38134 WHERE `entry`=232239; -- Ice Shard
UPDATE `gameobject_template` SET `name`='Ice Shard', `VerifiedBuild`=38134 WHERE `entry`=232241; -- Ice Shard
UPDATE `gameobject_template` SET `name`='Ice Shard', `VerifiedBuild`=38134 WHERE `entry`=232240; -- Ice Shard
UPDATE `gameobject_template` SET `name`='Iron Horde Gibbet', `VerifiedBuild`=38134 WHERE `entry`=233003; -- Iron Horde Gibbet
UPDATE `gameobject_template` SET `name`='Tar\'thog Bridge', `VerifiedBuild`=38134 WHERE `entry`=231136; -- Tar'thog Bridge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=237981; -- Campfire
UPDATE `gameobject_template` SET `name`='Poisonous Mushroom', `VerifiedBuild`=38134 WHERE `entry`=231986; -- Poisonous Mushroom
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=237997; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=237992; -- Cookpot
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `VerifiedBuild`=38134 WHERE `entry`=229323; -- Boiled Ichor
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=237998; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=229353; -- Bleeding Hollow Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=229352; -- Bleeding Hollow Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=237999; -- Campfire
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=233432; -- Iron Horde Supply Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236914; -- Soul Crystal L
UPDATE `gameobject_template` SET `name`='Dark Portal Door', `VerifiedBuild`=38134 WHERE `entry`=234623; -- Dark Portal Door
UPDATE `gameobject_template` SET `castBarCaption`='Destroying', `VerifiedBuild`=38134 WHERE `entry`=233057; -- Mark of the Bleeding Hollow
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236913; -- Soul Crystal R
UPDATE `gameobject_template` SET `name`='Dark Portal Door', `VerifiedBuild`=38134 WHERE `entry`=234622; -- Dark Portal Door
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=238955; -- Doodad_6IH_IronHorde_darkportaldoor002
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=238954; -- Doodad_6IH_IronHorde_darkportaldoor001
UPDATE `gameobject_template` SET `castBarCaption`='Destroying', `VerifiedBuild`=38134 WHERE `entry`=233056; -- Mark of the Shadowmoon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233614; -- Chamber Door
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233160; -- GoHome Object
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236691; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Left001
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=234140; -- Gul'dan Door Light B
UPDATE `gameobject_template` SET `name`='Spiked Ball', `VerifiedBuild`=38134 WHERE `entry`=232505; -- Spiked Ball
UPDATE `gameobject_template` SET `name`='Gate', `VerifiedBuild`=38134 WHERE `entry`=231957; -- Gate
UPDATE `gameobject_template` SET `name`='Blackrock Dam', `VerifiedBuild`=38134 WHERE `entry`=233277; -- Blackrock Dam
UPDATE `gameobject_template` SET `name`='Iron Cage Door', `Data2`=3000, `VerifiedBuild`=38134 WHERE `entry`=233197; -- Iron Cage Door
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=230833; -- Gul'dan Beam (TEMP)
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=232502; -- Debris 001
UPDATE `gameobject_template` SET `name`='Destroyed Iron Horde War Machine', `VerifiedBuild`=38134 WHERE `entry`=231766; -- Destroyed Iron Horde War Machine
UPDATE `gameobject_template` SET `name`='Alliance Ship', `VerifiedBuild`=38134 WHERE `entry`=233298; -- Alliance Ship
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233906; -- Doodad_6TJ_DarkPortal_FX_Wrap001
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236690; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Right001
UPDATE `gameobject_template` SET `castBarCaption`='Destroying', `VerifiedBuild`=38134 WHERE `entry`=229598; -- Mark of the Burning Blade
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=234139; -- Gul'dan Door Light
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=236692; -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Center001
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=232504; -- Debris 003
UPDATE `gameobject_template` SET `castBarCaption`='Destroying', `VerifiedBuild`=38134 WHERE `entry`=229600; -- Mark of the Blackrock
UPDATE `gameobject_template` SET `castBarCaption`='Destroying', `VerifiedBuild`=38134 WHERE `entry`=233104; -- Stasis Rune
UPDATE `gameobject_template` SET `name`='Horde Ship', `VerifiedBuild`=38134 WHERE `entry`=233297; -- Horde Ship
UPDATE `gameobject_template` SET `name`='Tar\'thog Bridge', `VerifiedBuild`=38134 WHERE `entry`=231137; -- Tar'thog Bridge
UPDATE `gameobject_template` SET `name`='Gul\'dan Light Shaft', `VerifiedBuild`=38134 WHERE `entry`=237261; -- Gul'dan Light Shaft
UPDATE `gameobject_template` SET `name`='Plunger', `VerifiedBuild`=38134 WHERE `entry`=231985; -- Plunger
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=232500; -- Destroyed Iron Horde War Machine Type 01
UPDATE `gameobject_template` SET `name`='Smoke Plume', `VerifiedBuild`=38134 WHERE `entry`=232506; -- Smoke Plume
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=232503; -- Debris 002
UPDATE `gameobject_template` SET `name`='Gate', `VerifiedBuild`=38134 WHERE `entry`=231958; -- Gate
UPDATE `gameobject_template` SET `name`='Dark Portal', `VerifiedBuild`=38134 WHERE `entry`=237670; -- Dark Portal
UPDATE `gameobject_template` SET `name`='Iron Horde Capsule', `VerifiedBuild`=38134 WHERE `entry`=231763; -- Iron Horde Capsule
UPDATE `gameobject_template` SET `castBarCaption`='Destroying', `VerifiedBuild`=38134 WHERE `entry`=229599; -- Mark of the Shattered Hand
UPDATE `gameobject_template` SET `name`='Dark Portal Power Spire', `VerifiedBuild`=38134 WHERE `entry`=231860; -- Dark Portal Power Spire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=227645; -- Broken Wagon Supplies
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=230609; -- Collision PC Size x2.5
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=225787; -- Bonfire
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=225742; -- Bonfire
UPDATE `gameobject_template` SET `castBarCaption`='Poisoning', `ContentTuningId`=1221, `VerifiedBuild`=38134 WHERE `entry`=232625; -- Cooking Pot
UPDATE `gameobject_template` SET `type`=50, `IconName`='', `Data0`=2850, `Data3`=0, `Data4`=275, `Data5`=300, `Data6`=30, `Data12`=683, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=38134 WHERE `entry`=142145; -- Gromsblood
UPDATE `gameobject_template` SET `name`='Iron Tank', `VerifiedBuild`=38134 WHERE `entry`=233909; -- Iron Tank
UPDATE `gameobject_template` SET `IconName`='', `Data0`=2850, `Data4`=300, `Data5`=300, `Data12`=683, `VerifiedBuild`=38134 WHERE `entry`=176586; -- Mountain Silversage
UPDATE `gameobject_template` SET `name`='Iron Tank', `VerifiedBuild`=38134 WHERE `entry`=233905; -- Iron Tank
UPDATE `gameobject_template` SET `name`='Iron Wagon', `VerifiedBuild`=38134 WHERE `entry`=233910; -- Iron Wagon
UPDATE `gameobject_template` SET `name`='Iron Tank', `VerifiedBuild`=38134 WHERE `entry`=233904; -- Iron Tank
UPDATE `gameobject_template` SET `name`='Iron Banner', `VerifiedBuild`=38134 WHERE `entry`=233913; -- Iron Banner
UPDATE `gameobject_template` SET `name`='Iron Barricade', `VerifiedBuild`=38134 WHERE `entry`=233911; -- Iron Barricade
UPDATE `gameobject_template` SET `type`=50, `Data0`=2863, `Data1`=51298, `Data3`=0, `Data4`=225, `Data5`=275, `Data6`=30, `Data12`=683, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=38134 WHERE `entry`=324; -- Small Thorium Vein
UPDATE `gameobject_template` SET `name`='Iron Banner', `VerifiedBuild`=38134 WHERE `entry`=233914; -- Iron Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=233392; -- Hatchet Cannon
UPDATE `gameobject_template` SET `name`='Cannonball Stack', `VerifiedBuild`=38134 WHERE `entry`=226707; -- Cannonball Stack
UPDATE `gameobject_template` SET `IconName`='', `Data0`=2850, `Data5`=300, `Data12`=683, `VerifiedBuild`=38134 WHERE `entry`=176584; -- Dreamfoil
UPDATE `gameobject_template` SET `Data1`=17539, `VerifiedBuild`=38134 WHERE `entry`=180712; -- Stonescale Eel Swarm
UPDATE `gameobject_template` SET `type`=50, `Data0`=2863, `Data3`=0, `Data4`=190, `Data5`=215, `Data6`=30, `Data12`=683, `Data13`=1, `Data18`=10, `Data19`=0, `ContentTuningId`=683, `VerifiedBuild`=38134 WHERE `entry`=2047; -- Truesilver Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=235880; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `name`='Bonfire', `VerifiedBuild`=38134 WHERE `entry`=225730; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=213729; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279314; -- Small Rock
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=279378; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=272631; -- Cursed Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=272639; -- Vilescale Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=272638; -- Vilescale Chest
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=271667; -- Naga Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=207177; -- Alliance Door
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=205496; -- Alliance Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=205495; -- Horde Gate
UPDATE `gameobject_template` SET `size`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `entry`=207178; -- Horde Gate
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=279253; -- Lucky Horace's Lucky Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=272614; -- Large Fish Skeleton
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=271664; -- Airtight Escape Pod
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=281417; -- Keeper Shavras's Core
UPDATE `gameobject_template` SET `Data1`=87436, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=282721; -- Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=271648; -- Stolen Idol of Krag'wa
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=280480; -- Titan Keeper Data Core
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=272439; -- Rubble
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=272409; -- Message Rocket
UPDATE `gameobject_template` SET `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=293567; -- Wanted Poster
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291134; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291133; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=287145; -- Cooking Pot
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=89627, `ContentTuningId`=190, `VerifiedBuild`=38134 WHERE `entry`=293569; -- River Clam
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=297489; -- Tales of de Loa: Krag'wa
UPDATE `gameobject_template` SET `IconName`='', `Data1`=76083, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=281872; -- Sea Stalks


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231119 AND `Idx`=0); -- Blackrock Powder Keg
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231816 AND `Idx`=0); -- Iron Horde Weapon Rack
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231815 AND `Idx`=0); -- Iron Horde Weapon Rack
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231817 AND `Idx`=0); -- Iron Horde Weapon Rack
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231819 AND `Idx`=0); -- Iron Horde Weapon
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231818 AND `Idx`=0); -- Iron Horde Weapon
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=231820 AND `Idx`=0); -- Iron Horde Weapon
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=229323 AND `Idx`=0); -- Boiled Ichor
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=281417 AND `Idx`=0); -- Keeper Shavras's Core
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=271648 AND `Idx`=0); -- Stolen Idol of Krag'wa
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=280480 AND `Idx`=0); -- Titan Keeper Data Core



DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=342 AND `ResponseId`=896 AND `Index`=2);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `ResponseIdentifier`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(342, 896, 896, 2, 1851129, 0, 0, 0, 0, 0, 'Vashj\'ir', '', '', 'Travel to Bladefist Bay', 'A new landmass on the western coast of the Eastern Kingdoms has appeared, and we must gain control of it before the Alliance.\n\nA mercenary vessel has been commissioned to transport the Horde into battle against the Alliance.', '', 0, 0, 38134);

UPDATE `playerchoice_response` SET `ResponseIdentifier`=895, `Header`='Tanaan Jungle', `Answer`='Enter the Dark Portal', `Description`='The Iron Horde are invading Azeroth!\n\nWe must stop them to save our world. For Azeroth!' WHERE (`ChoiceId`=342 AND `ResponseId`=1013 AND `Index`=1);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=894 WHERE (`ChoiceId`=342 AND `ResponseId`=1429 AND `Index`=0);

DELETE FROM `npc_text` WHERE `ID`=37234;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(37234, 1, 0, 0, 0, 0, 0, 0, 0, 168875, 0, 0, 0, 0, 0, 0, 0, 38134); -- 37234

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=25119; -- 25119
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23892; -- 23892
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23790; -- 23790
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23994; -- 23994
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23823; -- 23823
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24170; -- 24170
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23740; -- 23740
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=23824; -- 23824
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=24524; -- 24524
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=32367; -- 32367
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34097; -- 34097
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34096; -- 34096
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34095; -- 34095

REPLACE INTO transports VALUES
(35, 333479, '9.0 Transport - NPE - Alliance Battleship', 0, 0, 0, '');
REPLACE INTO transports VALUES (36, 349879, '9.0 Transport - NPE - Horde Battleship', 0, 0, 0, '');

