SET @CGUID := 21013000;
SET @OGUID := 21003000;

UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10698;
UPDATE `areatrigger_template` SET `Type`=0, `Data0`=4, `Data1`=4, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10470;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11353;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11189;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12929;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=26124 WHERE `Id`=11189;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9482;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12498;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12493;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12401;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11547;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12469;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11420;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=7020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12673;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12506;
UPDATE `areatrigger_template` SET `Data0`=9, `Data1`=9, `VerifiedBuild`=26124 WHERE `Id`=12549;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `Flags`=1031, `VerifiedBuild`=26124 WHERE `Id`=10003;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=16572;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10003;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10594;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12740;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=6514 AND `AreaTriggerId`=11189) OR (`SpellMiscId`=8312 AND `AreaTriggerId`=12498) OR (`SpellMiscId`=7078 AND `AreaTriggerId`=11547) OR (`SpellMiscId`=8282 AND `AreaTriggerId`=12469) OR (`SpellMiscId`=8534 AND `AreaTriggerId`=12673) OR (`SpellMiscId`=8320 AND `AreaTriggerId`=12506) OR (`SpellMiscId`=8391 AND `AreaTriggerId`=12549) OR (`SpellMiscId`=5887 AND `AreaTriggerId`=10594);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(6514, 11189, 0, 0, 0, 0, 17, 0, 10000, 26124), -- SpellId : 208931
(8312, 12498, 0, 0, 0, 0, 0, 0, 6000, 26124), -- SpellId : 223423
-- (0, 12493, 0, 0, 0, 0, 17, 0, 0, 26124), -- SpellId : 0
(7078, 11547, 0, 0, 0, 0, 60, 0, 0, 26124), -- SpellId : 225519
(8282, 12469, 0, 0, 0, 0, 60, 0, 30000, 26124), -- SpellId : 223065
(8534, 12673, 0, 0, 0, 0, 0, 0, 0, 26124), -- SpellId : 225355
(8320, 12506, 0, 0, 0, 0, 0, 0, 2500, 26124), -- SpellId : 223419
(8391, 12549, 0, 0, 0, 0, 0, 0, 20000, 26124), -- SpellId : 223944
(5887, 10594, 0, 0, 0, 0, 31, 12500, 0, 26124); -- SpellId : 203044

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7545, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=70, `TimeToTarget`=0, `TimeToTargetScale`=1000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=8430 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1549, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1495, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6000 WHERE (`SpellMiscId`=12002 AND `AreaTriggerId`=16713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6826 AND `AreaTriggerId`=11353); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7983, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11644, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11029, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1248, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1407, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4756 AND `AreaTriggerId`=9482); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2430, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1519, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10378, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1434, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1436, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1435, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1438, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8484, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1464, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8957, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1510, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1992, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1509, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1442, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1439, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2378, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1437, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1502, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1196, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=120000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1466, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1464, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1460, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1463, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1458, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1455, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1440, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1433, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1441, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1447, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4481, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3972, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1555, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1489, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=9808, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1549, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1488, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1397, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1431, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1432, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1429, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=977, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7267 AND `AreaTriggerId`=11721); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1497, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1523, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1481, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1484, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1443, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1445, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1446, `TimeToTargetScale`=1750 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1903, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1818, `TimeToTargetScale`=5000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5280 AND `AreaTriggerId`=10003); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=11883 AND `AreaTriggerId`=16572); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3599, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5280 AND `AreaTriggerId`=10003); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3862, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3517, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7998, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3685, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1500, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2800, `TimeToTargetScale`=15000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1944, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=8200 AND `AreaTriggerId`=12401); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=3605 AND `Idx`=257) OR (`ConversationId`=3605 AND `Idx`=0) OR (`ConversationId`=3601 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3609 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3608 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3613 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3602 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3617 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3610 AND `ConversationActorId`=55299 AND `Idx`=0) OR (`ConversationId`=3626 AND `ConversationActorId`=55299 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
-- (3605, 0, 257, 26124), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: Royaumes de l’Est Low: 1099511627775
-- (3605, 0, 0, 26124), -- Full: 0x2016FCBE006224400000C10000437E0E Creature/0 R1471/S193 Map: Le Cauchemar d’émeraude Entry: 100497 (Ursoc) Low: 4423182
(3601, 55299, 0, 26124),
(3609, 55299, 0, 26124),
(3608, 55299, 0, 26124),
(3613, 55299, 0, 26124),
(3602, 55299, 0, 26124),
(3617, 55299, 0, 26124),
(3610, 55299, 0, 26124),
(3626, 55299, 0, 26124);


DELETE FROM `conversation_actor_template` WHERE `Id`=55299;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(55299, 106482, 70004, 26124);


DELETE FROM `conversation_line_template` WHERE `Id` IN (8087, 8074, 8069, 8083, 8082, 8081, 8080, 8092, 8070, 8105, 8104, 8086, 8124);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(8087, 11871, 4030116880, 257, 0, 26124),
(8074, 0, 4030116880, 0, 0, 26124),
(8069, 0, 98, 0, 0, 26124),
(8083, 14698, 98, 0, 9238, 26124),
(8082, 0, 98, 0, 0, 26124),
(8081, 8401, 98, 0, 9238, 26124),
(8080, 0, 98, 0, 0, 26124),
(8092, 0, 98, 0, 0, 26124),
(8070, 0, 98, 0, 0, 26124),
(8105, 11074, 98, 0, 9238, 26124),
(8104, 0, 98, 0, 0, 26124),
(8086, 0, 98, 0, 0, 26124),
(8124, 0, 98, 0, 0, 26124);


DELETE FROM `conversation_template` WHERE `Id` IN (3617, 3626, 3609, 3608, 3613, 3610, 3605, 3602, 3601);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(3617, 8104, 26565, 26124),
(3626, 8124, 12709, 26124),
(3609, 8082, 19131, 26124),
(3608, 8080, 18038, 26124),
(3613, 8092, 9365, 26124),
(3610, 8086, 12632, 26124),
(3605, 8074, 11871, 26124),
(3602, 8070, 17029, 26124),
(3601, 8069, 10988, 26124);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (251997 /*Portal*/, 248849 /*Wall of Roots*/, 248848 /*NgihtmareRaid_UnGoro_RootWall03*/, 248850 /*Wall of Roots*/, 251555 /*Eye of Il'gynoth's Forcefield*/, 251995 /*Portal*/, 255000 /*Twisting Roots*/, 252006 /*Portal*/, 252004 /*Portal*/, 252043 /*Door*/, 252042 /*Door*/, 251980 /*Nightmare Iris*/, 260552 /*Doodad_7DU_Nightmare_RootWall010*/, 260551 /*Doodad_7DU_Nightmare_RootWall009*/, 260550 /*Doodad_7DU_Nightmare_RootWall008*/, 254271 /*Thunder Bluff*/, 254270 /*Un'goro Crater*/, 254273 /*The Emerald Dreamway*/, 254272 /*Grizzly Hills*/, 248925 /*Entrance Vines*/, 248927 /*Thunder Bluff Vines*/, 248926 /*Ungoro Vines*/, 248929 /*Dragons Vines*/, 248928 /*Grizzly Vines*/, 251533 /*Doodad_7DU_Nightmare_RootWall001*/, 251534 /*Doodad_7DU_Nightmare_RootWall002*/, 251535 /*Doodad_7DU_Nightmare_RootWall003*/, 251536 /*Doodad_7DU_Nightmare_RootWall004*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(251997, 0, 32), -- Portal
(248849, 0, 48), -- Wall of Roots
(248848, 0, 48), -- NgihtmareRaid_UnGoro_RootWall03
(248850, 0, 48), -- Wall of Roots
(251555, 0, 48), -- Eye of Il'gynoth's Forcefield
(251995, 0, 32), -- Portal
(255000, 0, 48), -- Twisting Roots
(252006, 0, 32), -- Portal
(252004, 0, 32), -- Portal
(252043, 1375, 32), -- Door
(252042, 1375, 32), -- Door
(251980, 0, 16), -- Nightmare Iris
(260552, 1375, 32), -- Doodad_7DU_Nightmare_RootWall010
(260551, 114, 32), -- Doodad_7DU_Nightmare_RootWall009
(260550, 1375, 32), -- Doodad_7DU_Nightmare_RootWall008
(254271, 1375, 32), -- Thunder Bluff
(254270, 1375, 32), -- Un'goro Crater
(254273, 114, 32), -- The Emerald Dreamway
(254272, 1375, 32), -- Grizzly Hills
(248925, 1375, 32), -- Entrance Vines
(248927, 1375, 32), -- Thunder Bluff Vines
(248926, 1375, 32), -- Ungoro Vines
(248929, 1375, 32), -- Dragons Vines
(248928, 1375, 32), -- Grizzly Vines
(251533, 0, 48), -- Doodad_7DU_Nightmare_RootWall001
(251534, 0, 48), -- Doodad_7DU_Nightmare_RootWall002
(251535, 0, 48), -- Doodad_7DU_Nightmare_RootWall003
(251536, 0, 48); -- Doodad_7DU_Nightmare_RootWall004

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+865;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.453, 1381.532, 369.5058, 0.6552992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+1, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1875.611, 1366.588, 369.5058, 0.7690535, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+2, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.758, 1364.335, 369.5058, 2.96608, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+3, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.345, 1312.981, 369.5058, 1.965422, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+4, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1834.613, 1347.235, 369.5058, 1.428986, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+5, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.039, 1340.139, 369.5058, 5.353669, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+6, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.45, 1375.901, 369.5058, 3.332501, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+7, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1852.563, 1329.804, 369.5058, 0.4663034, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+8, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1878.733, 1346.369, 369.5058, 3.180668, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+9, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.006, 1329.795, 369.5058, 4.786224, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+10, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.522, 1337.727, 369.5058, 4.400882, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+11, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1908.06, 1331.272, 369.5058, 2.70779, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+12, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1904.194, 1345.112, 369.5058, 2.038719, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+13, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1903.091, 1317.2, 369.5058, 4.241662, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+14, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.643, 1356.763, 369.5058, 1.513716, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+15, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1879.883, 1330.415, 369.5058, 4.650832, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+16, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1876.764, 1362.569, 369.5058, 2.275227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+17, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.576, 1346.949, 369.5058, 2.457269, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+18, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.931, 1304.929, 369.5058, 6.232647, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+19, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1913.675, 1354.79, 369.5058, 1.599001, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+20, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1902.92, 1340.296, 369.5058, 1.606847, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+21, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1861.311, 1313.011, 369.5058, 5.116901, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+22, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1854.756, 1313.185, 369.5058, 2.112972, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+23, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.878, 1306.815, 369.5058, 4.069682, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+24, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1875.579, 1309.594, 369.5058, 2.84813, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+25, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1856.647, 1325.015, 369.5058, 3.493619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+26, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.674, 1326.153, 369.5058, 4.295965, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+27, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1865.475, 1324.057, 369.5058, 4.688885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+28, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1867.692, 1366.411, 369.5058, 5.95886, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+29, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.982, 1362.285, 369.5058, 0.8010526, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+30, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1890.16, 1310.545, 369.5058, 2.114608, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+31, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1865.676, 1372.163, 369.5058, 3.070657, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+32, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1866.357, 1330.37, 369.5058, 4.944401, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+33, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1858.777, 1373.36, 369.5058, 2.745271, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+34, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.986, 1352.347, 369.5058, 1.123453, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+35, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.37, 1340.739, 369.5058, 4.765112, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+36, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.521, 1368.14, 369.5058, 3.941609, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+37, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1905.18, 1325.5, 369.5058, 1.105955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+38, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.032, 1352.153, 369.5058, 0.4772032, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+39, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.39, 1358.358, 369.5058, 2.463298, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+40, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1910.976, 1332.732, 369.5058, 6.194691, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+41, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1906.9, 1353.266, 369.5058, 0.453494, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+42, 111004, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1838.587, 1322.019, 369.5058, 6.232699, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Gelatinized Decay (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+43, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1912.463, 1325.865, 369.5058, 4.019435, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+44, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.044, 1342.21, 369.5058, 5.409037, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+45, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.676, 1375.49, 369.5058, 4.10812, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+46, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1885.905, 1336.263, 369.5058, 4.983428, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+47, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.743, 1339.835, 369.5058, 1.502856, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+48, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.436, 1340.371, 369.5058, 0.5339129, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+49, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.468, 1305.784, 369.5058, 4.386674, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+50, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.731, 1334.706, 369.5058, 1.971331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+51, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.301, 1348.988, 369.5058, 5.536827, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+52, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.272, 1319.157, 369.5058, 1.261724, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+53, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1887.059, 1323.247, 369.5058, 2.187199, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+54, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.665, 1372.472, 369.5058, 6.02243, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+55, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1828.145, 1355.084, 369.5058, 4.913075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+56, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1838.068, 1379.279, 369.5058, 4.911668, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+57, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1875.056, 1351.232, 369.5058, 3.081728, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+58, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1877.988, 1315.081, 369.5058, 1.723903, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+59, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.962, 1354.2, 369.5058, 5.30148, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+60, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.275, 1317.483, 369.5058, 2.828948, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+61, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1892.191, 1347.585, 369.5058, 0.3000607, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+62, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.551, 1316.024, 369.5058, 1.592068, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+63, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1924.163, 1348.752, 369.5058, 1.91887, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+64, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1872.795, 1342.392, 369.5058, 0.2762737, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+65, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1844.004, 1364.863, 369.5058, 5.325682, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+66, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.229, 1351.759, 369.5058, 5.007418, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+67, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1885.335, 1309.003, 369.5058, 2.018029, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+68, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.398, 1341.532, 369.5058, 2.473238, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+69, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.758, 1325.944, 369.5058, 5.753616, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+70, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1918.89, 1336.978, 369.5058, 4.568198, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+71, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1837.08, 1353.852, 369.5058, 4.637999, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+72, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1863.499, 1354.39, 369.5058, 2.063345, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+73, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1879.26, 1376.566, 369.5058, 0.1417521, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+74, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1871.611, 1371.832, 369.5058, 5.258283, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+75, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1880.992, 1322.492, 369.5058, 4.129972, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+76, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.978, 1327.397, 369.5058, 2.152602, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+77, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.245, 1321.53, 369.5058, 0.5994485, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+78, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1921.702, 1352.141, 369.5058, 5.395164, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+79, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1831.025, 1370.534, 369.5058, 2.427969, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+80, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.829, 1333.605, 369.5058, 5.911196, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+81, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.225, 1338.831, 369.5058, 3.056342, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+82, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.629, 1365.335, 369.5058, 4.093276, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+83, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.707, 1346.469, 369.5058, 2.582298, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+84, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1827.009, 1363.541, 369.5058, 1.974817, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+85, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.995, 1361.567, 369.5058, 2.002082, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+86, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.528, 1346.603, 369.5058, 4.414049, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+87, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.055, 1363.477, 369.5058, 5.472412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+88, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1879.348, 1307.499, 369.5058, 3.190524, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+89, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1837.798, 1367.234, 369.5058, 3.980966, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+90, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1860.28, 1333.736, 369.5058, 5.158384, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+91, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.89, 1325.648, 369.5058, 2.062275, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+92, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.52, 1335.407, 369.5058, 1.516491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+93, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1844.774, 1331.28, 369.5058, 0.5776286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+94, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1900.045, 1322.555, 369.5058, 0.7439555, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+95, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1922.133, 1336.724, 369.5058, 3.30564, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+96, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.667, 1318.978, 369.5058, 1.444652, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+97, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1884.266, 1316.375, 369.5058, 4.478237, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+98, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1915.71, 1347.024, 369.5058, 2.631616, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+99, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1909.615, 1341.857, 369.5058, 2.895779, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+100, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.936, 1374.304, 369.5058, 6.084316, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+101, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.715, 1346.989, 369.5058, 4.670016, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+102, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.976, 1353.885, 369.5058, 5.341652, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+103, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1845.276, 1380.273, 370.0392, 6.046055, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+104, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.085, 1347.409, 369.5058, 0.04005231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+105, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.212, 1320.385, 369.5058, 3.495533, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+106, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.365, 1315.048, 369.5058, 0.6863555, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+107, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.214, 1345.755, 369.5058, 4.457509, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+108, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1859.952, 1306.188, 369.5058, 1.795246, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+109, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.625, 1339.053, 369.5058, 4.446825, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+110, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1920.807, 1343.562, 369.5058, 5.16663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+111, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1834.674, 1359.507, 369.5058, 1.985539, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+112, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.252, 1312.161, 369.5058, 2.603346, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+113, 111004, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1905.548, 1335.184, 369.5058, 1.561895, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Gelatinized Decay (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+114, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.981, 1318.764, 369.5058, 1.570837, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+115, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1863.14, 1354.373, 369.5058, 5.152643, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+116, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.306, 1357.201, 369.5058, 5.686988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+117, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.569, 1358.932, 369.5058, 2.148952, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+118, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1914.438, 1340.627, 369.5058, 0.5108169, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+119, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.823, 1350.78, 369.5058, 6.187986, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+120, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1827.382, 1352.201, 369.5058, 5.53086, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+121, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1880.793, 1302.93, 369.5058, 1.91576, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+122, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.12, 1297.422, 369.5058, 3.888714, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+123, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1918.878, 1319.391, 369.5058, 2.531008, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+124, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.208, 1311.808, 369.5058, 0.5253879, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+125, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.771, 1297.627, 369.5058, 5.039831, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+126, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1863.112, 1299.448, 369.5058, 4.226724, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+127, 102672, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1892.227, 1297.517, 369.5849, 2.358792, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nythendra (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 220189 - Aura de visée de Nythendra)
(@CGUID+128, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1856.777, 1297.451, 369.5058, 4.88792, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+129, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.5, 1307.356, 369.5058, 0.4206107, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+130, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1904.507, 1301.336, 369.5058, 2.881548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+131, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1852.612, 1303.793, 369.5058, 1.56016, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+132, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1838.003, 1310.359, 369.5058, 3.309874, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+133, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1846.433, 1301.665, 369.5058, 2.686665, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+134, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1894.137, 1300.786, 369.5058, 3.904898, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+135, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1904.827, 1304.086, 369.5058, 4.949573, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+136, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.102, 1320.684, 369.5058, 1.852181, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+137, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.179, 1317.211, 369.5058, 3.915646, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+138, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1877.529, 1297.625, 369.5058, 4.240769, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+139, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1917.898, 1310.983, 369.5058, 5.823919, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+140, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1929.227, 1341.893, 369.5058, 1.344188, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+141, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1927.299, 1326.535, 369.5058, 3.957744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+142, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1920.142, 1327.651, 369.5058, 0.9370246, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+143, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.386, 1301.028, 369.5058, 0.9994802, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+144, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1834.131, 1309.043, 369.5058, 1.926835, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+145, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1832.734, 1312.089, 369.5058, 4.741226, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+146, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1910.161, 1300.375, 369.5058, 2.255155, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+147, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.677, 1291.274, 369.5058, 0.6226651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+148, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1892.633, 1291.746, 369.5058, 0.08913524, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+149, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1912.844, 1305.742, 369.5058, 3.847868, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+150, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1861.4, 1292.101, 369.5058, 3.445762, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+151, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1881.993, 1289.614, 369.5058, 4.145204, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+152, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1917.188, 1303.62, 369.5058, 3.630819, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+153, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1922.783, 1310.998, 369.5058, 0.9760385, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+154, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1858.069, 1287.666, 369.5058, 2.199386, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+155, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1935.142, 1326.624, 369.5058, 5.888832, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+156, 111221, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1844.078, 1375.168, 369.5849, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+157, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1887.441, 1288.886, 369.5058, 4.490101, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+158, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1925.23, 1319.585, 369.5058, 5.235046, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+159, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.208, 1300.074, 369.5058, 2.172996, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+160, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1903.306, 1293.29, 369.5058, 2.41397, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+161, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1933.056, 1329.518, 369.5058, 0.9592326, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+162, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1875.676, 1289.213, 369.5058, 5.339115, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+163, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.6, 1298.3, 369.5058, 4.802107, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+164, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.413, 1296.663, 369.5058, 3.223809, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+165, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.97, 1294.532, 369.5058, 0.6461121, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+166, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1828.865, 1305.403, 369.5058, 3.52181, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+167, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.252, 1288.349, 369.5058, 5.513607, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+168, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.086, 1294.5, 369.5058, 0.04969566, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+169, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.007, 1294.05, 369.5058, 1.24799, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+170, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1881.751, 1283.549, 369.5058, 4.750521, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+171, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1846.205, 1290.281, 369.5058, 5.983663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+172, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1853.222, 1287.397, 369.5058, 1.346379, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+173, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1827.926, 1301.479, 369.5058, 3.806086, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+174, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1867.141, 1282.804, 369.5058, 1.803454, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+175, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.857, 1278.088, 369.5058, 4.300164, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+176, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1907.197, 1287.11, 369.5058, 1.5194, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+177, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1883.652, 1278.958, 369.5058, 6.03004, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+178, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1830.262, 1293.268, 369.5058, 1.952011, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+179, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1916.916, 1294.472, 369.5058, 3.835262, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+180, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1925.338, 1297.206, 369.5058, 6.03424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+181, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1927.135, 1303.611, 369.5058, 1.063299, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+182, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.932, 1287.837, 369.5058, 3.68985, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+183, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.862, 1289.297, 369.5058, 0.3635649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+184, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1837.288, 1295.082, 369.5058, 3.333439, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+185, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.769, 1283.285, 369.5058, 2.44429, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+186, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.985, 1276.801, 369.5058, 1.726583, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+187, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1872.141, 1282.656, 369.5058, 3.332709, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+188, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.79, 1278.962, 369.5058, 3.346258, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+189, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1875.681, 1276.388, 369.5058, 0.2078214, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+190, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1931.809, 1313.336, 369.5058, 1.493575, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+191, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1888.102, 1283.136, 369.5058, 0.388574, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+192, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.685, 1280.949, 369.5058, 3.170101, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+193, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.05, 1282.307, 369.5058, 4.898562, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+194, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1909.233, 1276.235, 369.5058, 4.720531, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+195, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.592, 1276.668, 369.5058, 0.6309677, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+196, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.074, 1270.152, 369.5058, 2.911216, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+197, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1864.153, 1269.796, 369.5058, 4.868885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+198, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1919.423, 1280.362, 369.5058, 3.910372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+199, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.701, 1276.219, 369.5058, 2.209962, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+200, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1914.986, 1413.175, 407.6575, 6.011025, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+201, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.905, 1271.916, 369.5058, 2.122977, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+202, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1923.389, 1290.651, 369.5058, 0.7575178, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+203, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1858.695, 1268.587, 369.5058, 2.10613, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+204, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.493, 1266.668, 369.5058, 4.207601, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+205, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1832.965, 1287.32, 369.5058, 0.9004577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+206, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.688, 1283.034, 369.5058, 5.551918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+207, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.408, 1282.685, 369.5058, 2.081645, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+208, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.933, 1271.773, 369.5058, 4.350309, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+209, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1922.304, 1410.497, 405.6225, 2.797683, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+210, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.589, 1274.628, 369.5058, 1.386559, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+211, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.796, 1282.555, 369.5058, 2.483021, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+212, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.506, 1280.42, 369.5058, 4.587398, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+213, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.683, 1269.187, 369.5058, 1.205411, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+214, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1912.466, 1287.288, 369.5058, 2.342897, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+215, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.263, 1271.709, 369.5058, 0.5539651, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+216, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1914.403, 1280.023, 369.5058, 3.484126, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+217, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.781, 1277.486, 369.5058, 3.453568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+218, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.061, 1272.302, 369.5058, 3.940835, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+219, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.605, 1425.096, 422.4035, 0.5871922, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+220, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1955.66, 1299.469, 391.4996, 4.031293, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+221, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1937.209, 1408.374, 402.9949, 2.109409, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+222, 111528, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1941.604, 1411.591, 402.8694, 2.502886, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Deathroot Ancient (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage) (possible waypoints or random movement)
(@CGUID+223, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1837.497, 1427.792, 423.1064, 0.2476123, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+224, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1937.209, 1408.374, 402.9949, 2.109409, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+225, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1920.398, 1417.788, 407.2242, 3.772905, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+226, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1901.206, 1264.848, 369.5058, 3.736845, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+227, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.687, 1427.854, 423.2411, 0.2671433, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+228, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1876.705, 1265.374, 369.5058, 6.138989, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+229, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1937.209, 1408.374, 402.9949, 2.109409, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+230, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1955.911, 1306.438, 391.4996, 5.278434, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+231, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1840.771, 1426.282, 422.8993, 0.4560429, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+232, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1962.686, 1304.368, 391.4997, 2.824217, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+233, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.713, 1429.454, 423.4945, 0.2768759, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+234, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1937.209, 1408.374, 402.9949, 2.109409, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+235, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1951.458, 1294.252, 391.4996, 0.8959343, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+236, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1929.895, 1417.841, 405.2478, 2.294266, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+237, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1915.352, 1419.446, 408.5957, 5.069936, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+238, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1840.863, 1425.902, 422.7586, 0.4034878, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+239, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.589, 1268.297, 369.5058, 2.791323, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+240, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1941.374, 1410.12, 402.831, 2.518613, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+241, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1937.209, 1408.374, 402.9949, 2.109409, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+242, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1906.34, 1270.264, 369.5058, 0.8505599, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+243, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1932.8, 1407.998, 403.3316, 6.078135, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+244, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1820.536, 1411.113, 431.574, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+245, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1985.547, 1392.521, 396.2651, 5.826765, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage) (possible waypoints or random movement)
(@CGUID+246, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1853.995, 1448.974, 426.9198, 1.219027, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+247, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2002.033, 1352.023, 391.5058, 0.9245282, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+248, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1971.649, 1341.692, 391.4171, 0.5272878, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+249, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1863.736, 1447.7, 424.4965, 5.492575, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 111528, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1810.051, 1440.256, 434.0393, 3.068331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Deathroot Ancient (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage)
(@CGUID+251, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1946.735, 1422.457, 403.751, 3.98631, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+252, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1961.601, 1410.218, 400.5866, 1.520903, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+253, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1955.616, 1291.406, 391.4995, 4.643345, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+254, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2002.033, 1352.023, 391.5058, 0.9245282, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+255, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1971.747, 1337.233, 391.4997, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+256, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1860.115, 1457.059, 426.618, 3.180312, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+257, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.885, 1435.612, 425.031, 0.4323648, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+258, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1845.021, 1454.809, 429.4262, 2.886564, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage)
(@CGUID+259, 111528, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1968.783, 1272.076, 391.49, 1.056339, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Deathroot Ancient (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage)
(@CGUID+260, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1907.948, 1430.728, 412.1189, 1.368277, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+261, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1854.255, 1456.842, 427.9671, 5.935637, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+262, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1996.84, 1381.214, 393.9272, 2.030297, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage) (possible waypoints or random movement)
(@CGUID+263, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2003.656, 1318.365, 391.5013, 5.050732, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage) (possible waypoints or random movement)
(@CGUID+264, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1996.01, 1316.181, 391.5058, 4.156187, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+265, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1796.672, 1420.687, 435.415, 2.47371, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+266, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1999.023, 1327.29, 391.5058, 4.334431, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+267, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2008.022, 1359.963, 391.644, 2.160337, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+268, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2001.257, 1325.592, 391.5058, 4.615683, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+269, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1939.921, 1249.224, 391.4162, 5.16444, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque)
(@CGUID+270, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1916.04, 1225.286, 390.6955, 1.732571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+271, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1999.023, 1327.29, 391.5058, 4.328056, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+272, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2002.033, 1352.023, 391.5058, 0.9245282, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+273, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1999.023, 1327.29, 391.5058, 4.347502, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+274, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2001.508, 1328.312, 391.5058, 4.612603, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+275, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1810.625, 1428.563, 433.2718, 4.342683, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+276, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2002.033, 1352.023, 391.5058, 0.9245282, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+277, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1918.92, 1224.342, 390.8856, 1.802808, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+278, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1828.916, 1449.69, 431.2652, 2.274024, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+279, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2002.033, 1352.023, 391.5058, 0.9245282, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+280, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1993.28, 1389.113, 395.2649, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+281, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2002.033, 1352.023, 391.5058, 0.9245282, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+282, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1999.023, 1327.29, 391.5058, 4.335267, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+283, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1761.683, 1463.881, 440.4204, 5.486134, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+284, 111535, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1981.678, 1279.685, 391.4171, 2.574542, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fog Beast Spawner Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 222115 - Brouillard cauchemardesque) (possible waypoints or random movement)
(@CGUID+285, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1913.49, 1221.507, 391.1349, 1.587296, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+286, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1978.752, 1240.436, 391.5016, 4.391056, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+287, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1986.705, 1257.625, 391.5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+288, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1925.148, 1215.988, 391.9325, 5.960646, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+289, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1975.347, 1243.995, 391.5011, 5.168855, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+290, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2030.389, 1336.981, 391.5563, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+291, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1980.884, 1248.866, 391.5008, 0.9160576, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage) (possible waypoints or random movement)
(@CGUID+292, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1936.858, 1218.12, 391.6076, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+293, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1942.509, 1221.488, 391.5006, 3.7994, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage)
(@CGUID+294, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1826.201, 1459.931, 434.1348, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+295, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1766.646, 1455.943, 439.5582, 5.494545, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+296, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1810.868, 1459.615, 436.6425, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+297, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1982.46, 1268.599, 391.5004, 5.071206, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage) (possible waypoints or random movement)
(@CGUID+298, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2021.486, 1310.934, 391.4996, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+299, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1802.972, 1454.76, 437.2332, 0.4712858, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage)
(@CGUID+300, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1810.868, 1459.615, 436.6425, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+301, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1758.788, 1460.527, 440.2746, 5.648346, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+302, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2006.637, 1309.858, 391.5013, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+303, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1930.222, 1214.599, 391.955, 2.8914, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+304, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1977.852, 1235.13, 391.502, 1.529918, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+305, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1992.845, 1242.507, 391.1701, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+306, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1972.321, 1233.694, 391.5017, 0.5385828, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+307, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1746.882, 1436.335, 439.4376, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+308, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1758.373, 1461.839, 440.3893, 5.583803, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+309, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1726.646, 1454.752, 443.1257, 0.4158382, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+310, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 2052.248, 1389.566, 395.4434, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+311, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1730.264, 1463.752, 444.7323, 4.226765, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+312, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1759.707, 1464.47, 440.5789, 5.547532, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+313, 106482, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1871.188, 1344.372, 598.0057, 4.987593, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Malfurion Hurlorage (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+314, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1760.317, 1461.731, 440.3037, 5.539684, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+315, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1734.481, 1455.002, 441.9596, 6.054873, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+316, 113520, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1858.418, 1450.718, 647.9918, 3.109146, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Ancient Spirit (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225758 - Visuels d’Ysera) (possible waypoints or random movement)
(@CGUID+317, 111354, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1739.259, 1446.411, 440.3677, 5.396381, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupteur cœur-corrompu (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 8279 - Détection du camouflage)
(@CGUID+318, 113113, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1758.811, 1463.071, 440.5005, 5.568196, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Essence of Nightmare (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+319, 92870, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1871.43, 1327.32, 379.5848, 5.539001, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sindragosa's Fury (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+320, 102930, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.649, 1335.104, 369.5848, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Breath Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+321, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1909.488, 1292.903, 369.8037, 5.849483, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+322, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1880.925, 1291.319, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+323, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.854, 1346.396, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+324, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1919.689, 1304.618, 369.8037, 0.9458573, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+325, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1856.91, 1278.594, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+326, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1872.556, 1342.155, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+327, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1902.422, 1265.703, 369.5849, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+328, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1919.79, 1327.898, 369.8037, 6.150631, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+329, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1877.351, 1351.042, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+330, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.41, 1333.592, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+331, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1827.559, 1307.153, 370.9604, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+332, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1883.358, 1271.175, 369.5849, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+333, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1834.267, 1320.193, 370.7612, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+334, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.194, 1325.129, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+335, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.464, 1326.783, 370.8009, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+336, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1878.458, 1323.955, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+337, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1827.052, 1301.016, 370.4774, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+338, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1867.828, 1289.729, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+339, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1919.783, 1321.097, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+340, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1877.328, 1360.932, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+341, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1860.201, 1285.375, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+342, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1903.172, 1344.847, 369.8037, 5.375928, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+343, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.786, 1363.481, 369.5849, 3.350113, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+344, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1892.979, 1309.609, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+345, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1851.764, 1267.495, 369.9876, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+346, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1856.495, 1339.196, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+347, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.911, 1306.354, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+348, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1929.392, 1339.658, 369.9034, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+349, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1903.693, 1292.188, 369.8037, 1.856464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+350, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.255, 1339.439, 369.8037, 2.58062, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+351, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1851.004, 1354.667, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+352, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1916.714, 1313.675, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+353, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1904.951, 1298.693, 369.8037, 4.077594, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+354, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1912.323, 1326.056, 369.8037, 1.273544, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+355, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1826.556, 1364.142, 371.383, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+356, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1916.835, 1346.083, 369.5849, 0.7172686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+357, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1863.278, 1364.042, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+358, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.868, 1319.677, 369.8037, 3.350113, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+359, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1926.686, 1320.109, 369.8037, 3.256984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+360, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.354, 1276.804, 369.8919, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+361, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1864.453, 1356.738, 369.8037, 3.981254, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+362, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1907.97, 1285.613, 369.8037, 0.7511542, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+363, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1933.642, 1331.995, 369.8719, 4.01577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+364, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1853.634, 1283.854, 369.8037, 0.6463534, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+365, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1859.486, 1267.405, 370.0468, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+366, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.87, 1354.819, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+367, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.28, 1299.797, 369.8037, 0.7158598, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+368, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1865.299, 1339.075, 369.8037, 1.532334, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+369, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1837.953, 1380.017, 369.8918, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+370, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1872.896, 1335.53, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+371, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.09, 1305.964, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+372, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1857.747, 1352.304, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+373, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.941, 1300.813, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+374, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.526, 1334.139, 369.8037, 6.002367, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+375, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1871.87, 1355.847, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+376, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1896.526, 1316.139, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+377, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.111, 1368.398, 369.936, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+378, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1864.905, 1371.484, 369.7633, 3.350113, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+379, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.823, 1376.127, 369.5849, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+380, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1847.156, 1318.451, 369.8037, 0.4890075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+381, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.884, 1296.639, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+382, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.882, 1294.769, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+383, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.845, 1367.415, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+384, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1874.927, 1367.595, 369.8037, 5.849483, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+385, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.786, 1268.684, 370.0659, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+386, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1865.035, 1300.13, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+387, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.658, 1346.3, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+388, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1846.146, 1303.403, 369.8037, 1.235432, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+389, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.592, 1319.01, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+390, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1880.7, 1310.28, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+391, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.595, 1300.71, 369.8037, 3.359577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+392, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1904.601, 1325.8, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+393, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.161, 1293.507, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+394, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.266, 1313.047, 369.8037, 2.255409, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+395, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1834.123, 1300.523, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+396, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1925.552, 1346.123, 369.7483, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+397, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1879.448, 1344.497, 369.8037, 2.126622, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+398, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1922.03, 1341.059, 369.5849, 0.7172686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+399, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1865.066, 1351.481, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+400, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1826.148, 1356.934, 370.1802, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+401, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.47, 1348.549, 369.8037, 3.622348, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+402, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1835.005, 1376.102, 370.8189, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+403, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1883.818, 1318.998, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+404, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1864.816, 1270.514, 369.9823, 4.424389, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+405, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1901.186, 1281.389, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+406, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1923.92, 1312.679, 369.8037, 0.1607963, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+407, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.585, 1379.431, 369.8037, 1.808127, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+408, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1884.988, 1326.372, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+409, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1896.201, 1340.406, 369.8037, 5.185566, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+410, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1881.418, 1357.243, 369.8037, 5.849483, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+411, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1901.932, 1338.024, 369.8037, 1.291346, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+412, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1878.97, 1331.707, 369.8037, 6.225206, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+413, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1831.28, 1313.814, 370.8091, 5.137702, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+414, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1911.818, 1273.62, 369.8037, 1.450971, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+415, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.004, 1289.243, 369.8037, 2.605464, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+416, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1858.613, 1326.115, 369.8037, 4.633914, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+417, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.005, 1351.79, 369.8037, 3.523265, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+418, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.573, 1284.957, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+419, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1851.642, 1367.655, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+420, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1872.135, 1321.094, 369.8037, 5.560019, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+421, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1906.215, 1270.106, 369.8037, 2.517448, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+422, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1915.009, 1280.733, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+423, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1866.066, 1331.925, 369.8037, 3.982305, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+424, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.212, 1322.227, 370.0233, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+425, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1918.983, 1336.028, 369.5849, 0.7172686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+426, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1863.056, 1275.91, 369.8037, 0.1797096, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+427, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.906, 1312.569, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+428, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1880.601, 1284.245, 369.8037, 5.926648, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+429, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.436, 1360.629, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+430, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1927.262, 1326.648, 369.8037, 2.821038, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+431, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1903.563, 1318.33, 369.8037, 4.016508, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+432, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.715, 1292.879, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+433, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1906.092, 1353.26, 369.5849, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+434, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1884.851, 1350.997, 369.8037, 5.491098, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+435, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1928.858, 1306.887, 370.0046, 1.239227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+436, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.175, 1313.903, 370.0234, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+437, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1857.623, 1358.951, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+438, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1923.389, 1290.651, 369.95, 2.517448, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+439, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.146, 1361.708, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+440, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1876.998, 1296.91, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+441, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1914.389, 1340.38, 369.5849, 3.582799, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+442, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1845.873, 1271.359, 369.914, 2.150271, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+443, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.774, 1289.188, 369.8037, 2.068853, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+444, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.54, 1277.231, 369.8037, 0.5556098, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+445, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.938, 1348.642, 369.8037, 1.725061, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+446, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1935.2, 1322.939, 369.8926, 0.009309479, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+447, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1905.944, 1332.354, 369.8037, 0.3607649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+448, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.656, 1338.602, 369.944, 0.7176792, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+449, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1924.745, 1333.901, 369.5849, 2.740188, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+450, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1913.41, 1354.127, 369.5849, 0.7914259, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+451, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.575, 1311.194, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+452, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1859.609, 1333.686, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+453, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1932.707, 1314.45, 369.9585, 2.183316, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+454, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1876.661, 1376.557, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+455, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.431, 1287.469, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+456, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.911, 1373.936, 369.5849, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+457, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.12, 1297.422, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+458, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1860.885, 1305.736, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+459, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1909.708, 1346.556, 369.5849, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+460, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1889.351, 1276.259, 369.8037, 3.754173, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+461, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1862.214, 1345.755, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+462, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.858, 1373.01, 369.8037, 3.751128, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+463, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1897.979, 1268.497, 369.8037, 0.7511542, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+464, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1841.953, 1345.714, 369.9219, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+465, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1867.113, 1282.813, 369.8037, 0.1797096, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+466, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1833.988, 1345.519, 370.5764, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+467, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1906.411, 1277.774, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+468, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1896.63, 1323.285, 369.8037, 3.600093, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+469, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1898.521, 1303.326, 369.8037, 1.259065, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+470, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.668, 1365.656, 369.8037, 5.849483, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+471, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1854.241, 1331.123, 369.8037, 4.478755, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+472, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1874.722, 1290.217, 369.8037, 0.1643956, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+473, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1855.677, 1291.274, 369.8037, 3.536946, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+474, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1876.352, 1266.441, 369.8606, 5.005692, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+475, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1905.776, 1305.349, 369.8037, 4.354554, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+476, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1846.368, 1281.651, 369.8037, 5.388945, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+477, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1913.366, 1306.694, 369.8037, 3.737542, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+478, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1857.55, 1373.149, 369.5849, 5.366792, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+479, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1829.142, 1350.655, 370.4399, 6.024808, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+480, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.25, 1307.931, 369.8037, 4.455202, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+481, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.54, 1359.035, 369.8037, 3.964731, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+482, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1850.613, 1276.095, 369.8037, 2.007389, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+483, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1900.693, 1310.436, 369.8037, 4.934389, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+484, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1880.839, 1372.274, 369.8037, 1.929751, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+485, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.535, 1353.592, 369.8037, 3.395253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+486, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.491, 1281.87, 369.9623, 5.735727, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+487, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1833.247, 1361.557, 369.9185, 0.2199839, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+488, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1909.014, 1339.477, 369.5849, 0.8699947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+489, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1867.583, 1307.047, 369.8037, 5.980457, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+490, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1869.413, 1315.474, 369.8037, 4.967619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+491, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.892, 1327.882, 369.8037, 1.670439, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+492, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.686, 1341.486, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+493, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.431, 1310.243, 369.8037, 3.350113, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+494, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1881.038, 1302.568, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+495, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1890.089, 1320.7, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+496, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1853.479, 1305.17, 369.8037, 1.635446, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -) (possible waypoints or random movement)
(@CGUID+497, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1920.347, 1351.486, 369.8423, 5.375928, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+498, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1907.321, 1312.229, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+499, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.385, 1340.276, 370.7581, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1922.13, 1282.396, 369.8438, 2.744017, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+501, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1857.536, 1365.943, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+502, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1874.894, 1281.595, 369.5849, 3.350113, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+503, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1894.559, 1280.224, 369.8037, 3.477404, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+504, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1891.34, 1270.274, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+505, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1887.227, 1282.571, 369.8037, 2.718695, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+506, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1877.09, 1274.002, 369.5849, 0.5813468, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+507, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.03, 1297.071, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+508, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1877.726, 1316.323, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+509, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1829.889, 1294.002, 369.9467, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+510, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.059, 1352.915, 369.8037, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+511, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1893.418, 1286.394, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+512, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1849.828, 1333.918, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+513, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1915.444, 1288.519, 369.8037, 2.517448, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+514, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1837.288, 1295.082, 369.8037, 3.378272, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+515, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1832.703, 1287.563, 369.9419, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+516, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1913.811, 1332.455, 369.5849, 6.197451, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+517, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1865.483, 1324.866, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+518, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1872.63, 1328.352, 369.8037, 5.431541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+519, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1910.538, 1266.911, 369.5849, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+520, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.281, 1333.439, 370.8318, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+521, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1897.752, 1295.517, 369.8037, 1.151611, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+522, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1881.031, 1338.552, 369.8037, 5.849483, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+523, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1912.63, 1319.729, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+524, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1856.573, 1272.021, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+525, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1842.653, 1329.795, 369.9912, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+526, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.035, 1330.2, 369.8037, 5.178958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+527, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1873.903, 1303.722, 369.8037, 0.6343671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+528, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1857.328, 1298.917, 369.8037, 2.347776, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+529, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1830.724, 1370.339, 369.5058, 5.474824, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+530, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1848.049, 1379.597, 370.0779, 6.068122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+531, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1925.694, 1298.839, 369.96, 5.011698, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+532, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1887.458, 1313.431, 369.8037, 5.820277, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+533, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1887.144, 1290.264, 369.8037, 1.635446, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+534, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.047, 1275.936, 369.8037, 0.7567409, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+535, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1917.745, 1296.5, 369.8037, 0.3856173, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+536, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1886.941, 1344.649, 369.8037, 2.265172, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+537, 102998, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1899.215, 1275.214, 369.8037, 3.194129, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Vermin (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+538, 73400, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1965.96, 1268.011, 391.4998, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+539, 73400, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1977.956, 1303.048, 391.5002, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+540, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1844.425, 1499.59, 539.881, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+541, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1851.219, 1477.656, 554.028, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+542, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1822.705, 1501.42, 534.6617, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+543, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1839.127, 1461.273, 564.5984, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+544, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1831.26, 1484.613, 548.5795, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+545, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1815.46, 1520.983, 519.0347, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+546, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1834.276, 1519.351, 526.5553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+547, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1823.271, 1541.898, 511.6868, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+548, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1800.226, 1538.95, 502.382, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+549, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1832.303, 1505.314, 563.2698, 2.248086, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+550, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1784.451, 1543.879, 491.2439, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+551, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1771.212, 1541.177, 483.5253, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+552, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1814.315, 1497.691, 570.9894, 4.739899, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+553, 111355, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1718.644, 1459.719, 445.1511, 1.932514, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Tormenter (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+554, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1798.455, 1557.703, 498.9833, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+555, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1845.542, 1488.447, 586.7006, 1.11196, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+556, 111333, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1715.667, 1467.818, 447.1746, 5.054961, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taintheart Trickster (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+557, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1836.894, 1524.745, 578.0023, 2.637261, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+558, 113203, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1773.483, 1561.457, 487.1157, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fureur de drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 225324 - Colère de drake)
(@CGUID+559, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1801.183, 1552.125, 540.8624, 1.992605, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+560, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1831.719, 1466.422, 597.2614, 1.905382, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+561, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1815.46, 1550.188, 558.326, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+562, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1794.367, 1529.017, 569.3434, 0.3120997, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+563, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1764.406, 1557.426, 521.7579, 2.251836, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+564, 111412, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1705.635, 1511.592, 457.39, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Satyr Channel Cosmetic Stalker (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+565, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1858.196, 1445.044, 614.5175, 2.354123, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+566, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1843.752, 1475.989, 607.4344, 4.268657, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+567, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1781.029, 1549.531, 539.4943, 4.076568, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@CGUID+568, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1833.456, 1474.503, 614.5568, 5.537572, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+569, 111567, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1840.588, 1447.69, 623.9008, 0.3078197, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Nightmare Drake (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+570, 73400, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1769.75, 1448.071, 438.6453, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+571, 113575, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1882.542, 1330.731, 600.363, 1.895005, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Iris (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+572, 113575, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1870.299, 1330.564, 601.2935, 1.895005, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Iris (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+573, 113575, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1878.736, 1324.083, 601.8117, 1.895005, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Iris (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+574, 113575, 1520, 8026, 8026, 245760, '0', 0, 0, 0, 1871.915, 1322.559, 600.4058, 1.895005, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Iris (Area: Le Cauchemar d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+575, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12607.56, -12886.46, 229.8722, 5.176048, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+576, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12438.72, -13032.86, 329.4988, 4.010854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+577, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12409.67, -13151.16, 328.3795, 4.192996, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+578, 100497, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12181.29, -13108.31, 329.7119, 3.06784, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ursoc (Area: Les Grisonnes - Difficulty: Normal) (Auras: 205270 -)
(@CGUID+579, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12385.55, -12991.43, 318.0461, 3.171946, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+580, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12502.78, -13331.82, 190.8838, 0.5658823, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+581, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12436.86, -13152.25, 330.5328, 6.099736, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+582, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12416.98, -13033.22, 326.9547, 3.813725, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+583, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12399.34, -13108.46, 321.9878, 3.255735, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+584, 112290, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12428.11, -12974.78, 329.3546, 3.38612, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+585, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12436.9, -13145.77, 330.9563, 5.85994, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+586, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12427, -13009.68, 325.4158, 5.755285, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+587, 112303, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12668.94, -12976.9, 352.9013, 4.507027, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+588, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12423.81, -13036.63, 327.1299, 0.2667023, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+589, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12469.94, -13060.58, 339.5662, 5.471623, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+590, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12411.97, -12959.53, 319.6241, 1.4138, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+591, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12386.14, -13001.12, 318.126, 5.066895, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+592, 112290, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12427.44, -13074.79, 350.456, 2.911084, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+593, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12427.94, -13050.47, 334.5261, 2.057922, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+594, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12619.37, -13259.69, 185.8786, 4.876281, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+595, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12431.62, -13156.52, 330.6546, 2.119223, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+596, 112303, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12579.35, -12922.72, 295.7663, 3.051532, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+597, 111221, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12376.45, -13114.22, 320.7833, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Les Grisonnes - Difficulty: Normal)
(@CGUID+598, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12384.95, -13008.65, 319.3043, 1.971134, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+599, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12405.4, -13147.1, 326.7751, 1.604199, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+600, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12581.95, -13103.82, 218.0857, 0.1257854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+601, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12393.63, -13022.33, 324.6167, 4.342139, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+602, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12460.57, -13054.66, 339.0137, 4.142689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+603, 111858, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12396.88, -13114.63, 321.9878, 3.255735, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Guardian Rurson (Area: Les Grisonnes - Difficulty: Normal) (Auras: )
(@CGUID+604, 111856, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12433.45, -13037.42, 328.8891, 4.026969, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Guardian Gorroc (Area: Les Grisonnes - Difficulty: Normal) (Auras: )
(@CGUID+605, 112290, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12461.11, -13012.14, 326.052, 2.231331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+606, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12413.81, -13154.54, 329.5351, 1.169461, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+607, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12408.06, -13071.1, 348.8118, 3.183435, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+608, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12758.16, -12941.4, 256.8933, 5.240747, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+609, 113520, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12976.66, -13544.48, 345.06, 5.899747, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ancient Spirit (Area: Les Grisonnes - Difficulty: Normal) (Auras: 225758 - Visuels d’Ysera)
(@CGUID+610, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12408.67, -12957.44, 319.6337, 1.381062, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+611, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12389.95, -12987.54, 317.6622, 2.969099, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+612, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12398, -13122.55, 321.9878, 2.601644, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+613, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12426.57, -13014.78, 325.4158, 0.7522194, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+614, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12427.75, -12994.01, 326.4084, 6.108627, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+615, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12420.9, -13159.88, 330.6854, 1.8125, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+616, 112162, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12396.12, -13025.65, 325.7213, 1.070521, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grisly Trapper (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+617, 112303, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12540.24, -13344.18, 296.0261, 3.328029, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+618, 112153, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12464.75, -13057.69, 339.0137, 0.3066784, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dire Shaman (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+619, 111263, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12413.77, -13162.71, 330.9396, 2.478703, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tur Ragepaw (Area: Les Grisonnes - Difficulty: Normal) (Auras: 222687 - Liens du Cauchemar, 222696 - Tur Ragepatte)
(@CGUID+620, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12339.59, -13458.64, 236.6622, 2.191364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+621, 113088, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12426.36, -13159.72, 331.0553, 1.743935, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Feeler (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+622, 112307, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12615.36, -13395.22, 171.8719, 0.8004684, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmetic Nightmare Tentacle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+623, 112303, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12443.03, -13315.88, 295.7851, 3.436551, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Horrid Eagle (Area: Les Grisonnes - Difficulty: Normal) (Auras: 212515 - Aura de cauchemar)
(@CGUID+624, 92870, 1520, 8026, 7953, 245760, '0', 0, 0, 0, -12196.33, -13112.44, 339.1781, 0.1457357, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sindragosa's Fury (Area: Les Grisonnes - Difficulty: Normal) (Auras: )
(@CGUID+625, 103395, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 557.316, -12753.49, 9.34914, 4.675216, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmare Rift (Area: Chemin du Rêve d’émeraude - Difficulty: Normal)
(@CGUID+626, 113090, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 514.7865, -12792.26, 13.43846, 3.951395, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Gatewarden (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+627, 113089, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 517.739, -12791.83, 12.80018, 0.5275119, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Defiled Keeper (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+628, 103396, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 703.3577, -12789.07, 8.888801, 3.543326, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shadowy Rift (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204617 - Portail cauchemardesque)
(@CGUID+629, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.2435, -12794.85, 12.94724, 4.277774, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+630, 103378, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 574.3958, -12925.28, 10.18586, 1.435541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Diseased Rift (Area: Chemin du Rêve d’émeraude - Difficulty: Normal)
(@CGUID+631, 102679, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 582.8438, -12845.16, 6.262308, 2.328569, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ysondre (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 205283 - , 224200 - Energie du Cauchemar)
(@CGUID+632, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.2896, -12795.47, 12.78855, 4.450876, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+633, 102682, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 616.7384, -12832.9, 4.469628, 2.846762, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lethon (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 205283 - , 224200 - Energie du Cauchemar, 204719 - Liaison à la masse)
(@CGUID+634, 113090, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 513.8478, -12794.16, 13.43626, 4.151315, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Gatewarden (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+635, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.2312, -12795.01, 12.91355, 4.321198, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+636, 113520, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 464.2583, -12821.86, 55.93409, 1.60663, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ancient Spirit (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 225758 - Visuels d’Ysera)
(@CGUID+637, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.2448, -12794.85, 12.94871, 4.276608, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+638, 111852, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 527.095, -12791.82, 11.64011, 3.509558, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rothos (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 223181 - Don de Taerar, 223180 - Don de Léthon)
(@CGUID+639, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.2122, -12795.38, 12.82932, 4.422482, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+640, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.2417, -12794.82, 12.95555, 4.269702, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+641, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 517.312, -12791.78, 13.01512, 0.6474364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+642, 113090, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 517.4608, -12790.27, 12.9304, 0.4476812, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corrupted Gatewarden (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+643, 113089, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 515.6837, -12793.27, 13.10179, 4.036206, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Defiled Keeper (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 196285 -)
(@CGUID+644, 113092, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 519.3677, -12791.47, 12.60948, 4.561256, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swarming Dread (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 204729 - Angoisse terrassante)
(@CGUID+645, 73400, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 520.8751, -12788.56, 12.26665, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+646, 92870, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 572.1195, -12831.54, 16.31581, 5.614505, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sindragosa's Fury (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+647, 92870, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 572.9909, -12822.98, 15.67328, 5.553376, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sindragosa's Fury (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: )
(@CGUID+648, 102681, 1520, 8026, 8190, 245760, '0', 0, 0, 0, 618.4827, -12806.79, 4.794478, 3.396683, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Taerar (Area: Chemin du Rêve d’émeraude - Difficulty: Normal) (Auras: 205283 -)
(@CGUID+649, 113520, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11574.16, 11744.89, 180.2684, 2.645841, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ancient Spirit (Area: Mulgore - Difficulty: Normal) (Auras: 225758 - Visuels d’Ysera)
(@CGUID+650, 113108, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11251.86, 11037.49, 24.16111, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lapin cauchemardesque (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar)
(@CGUID+651, 113091, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11278.53, 11145.89, -35.47605, 3.488142, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Tainted Plainstrider (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+652, 113103, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11265.81, 11015.63, 48.59205, 1.157952, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupted Swoop (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+653, 113106, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11263.67, 11097.68, -14.58511, 0.4862056, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Sickly Cougar (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+654, 113108, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11245.51, 11110.48, -10.18669, 0.9544441, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lapin cauchemardesque (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+655, 113108, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11343.2, 11052.14, 8.414978, 1.890009, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lapin cauchemardesque (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+656, 113609, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11405.57, 11401.25, -84.33374, 4.618897, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Elerethe Renferal (Area: Mulgore - Difficulty: Normal) (Auras: 221869 - Ombres distordues)
(@CGUID+657, 113091, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11251.78, 11016.02, 34.71265, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Plainstrider (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar)
(@CGUID+658, 113091, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11184, 11113.13, -8.846759, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Plainstrider (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar)
(@CGUID+659, 113093, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11283.72, 11014.78, 34.66455, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Infected Gazelle (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar)
(@CGUID+660, 113103, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11268.22, 11062.19, 16.99874, 0.00857822, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupted Swoop (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+661, 113103, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11304.96, 11159.9, -35.04695, 0.8471689, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupted Swoop (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+662, 113108, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11284.48, 11196.25, -56.55813, 5.497787, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lapin cauchemardesque (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+663, 113091, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11317.25, 11047.48, 11.16064, 0.6393983, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Tainted Plainstrider (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+664, 113093, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11243.74, 11193.58, -26.1173, 3.370472, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Infected Gazelle (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+665, 113103, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11268.26, 11131.93, -12.74736, 2.665393, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupted Swoop (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+666, 113108, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11298.69, 11100.64, -16.15347, 4.17398, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lapin cauchemardesque (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+667, 113106, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11274.85, 11048.67, 14.02333, 2.13433, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Sickly Cougar (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+668, 113108, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11294.94, 11056.57, 4.144584, 5.219298, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lapin cauchemardesque (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+669, 113604, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11202.61, 11282.82, -6.176599, 5.928988, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Elerethe Renferal (Area: Mulgore - Difficulty: Normal)
(@CGUID+670, 113093, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11215.98, 11114.84, -9.254367, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Infected Gazelle (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar)
(@CGUID+671, 113091, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11252.4, 11078.5, 1.252181, 2.651567, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Tainted Plainstrider (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+672, 113093, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11279.39, 11078.89, -6.672631, 3.224086, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Infected Gazelle (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+673, 113103, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11323.93, 11117.95, -7.991978, 5.780863, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Corrupted Swoop (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar) (possible waypoints or random movement)
(@CGUID+674, 113106, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11219.48, 11082.63, 4.558537, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sickly Cougar (Area: Mulgore - Difficulty: Normal) (Auras: 225048 - Corruption du Cauchemar)
(@CGUID+675, 106510, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11383.93, 11230.11, -101.7834, 0.6881555, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flight Loc Stalker (Area: Mulgore - Difficulty: Normal)
(@CGUID+676, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11351.25, 11225.28, -99.78478, 0.1733704, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+677, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11393.75, 11214.58, -100.1244, 5.679849, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+678, 112039, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11380.92, 11238.31, -99.83724, 2.623309, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Screeching Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+679, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11376.39, 11239.36, -99.59866, 2.592187, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+680, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11353.07, 11244.16, -100.1299, 5.571099, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+681, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11404.36, 11234.22, -100.6392, 2.456655, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+682, 111975, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11396.65, 11259.03, -98.38519, 4.35463, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shadowfeather (Area: Mulgore - Difficulty: Normal) (Auras: )
(@CGUID+683, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11460.8, 11225.38, -91.39921, 0.1309221, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+684, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11456.07, 11228.26, -93.49833, 4.726341, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+685, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11461.16, 11230.02, -92.37112, 3.738153, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+686, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11371.71, 11320.16, -97.94533, 2.579887, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+687, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11371.63, 11307.51, -99.78006, 1.900046, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+688, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11453.47, 11243.43, -97.59705, 2.689895, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+689, 112078, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11367.77, 11317.74, -98.66963, 0.744361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pulsing Egg Sac (Area: Mulgore - Difficulty: Normal) (Auras: 215581 - Oeufs vibrant - cosmétique)
-- (@CGUID+690, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 4, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+691, 111439, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11460.97, 11240.44, -93.18857, 3.566196, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 221869 - Ombres distordues, 210792 - Ombres distordues)
(@CGUID+692, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11381.17, 11323.22, -97.77774, 0.9876615, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+693, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+694, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 4, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+695, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+696, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11496.5, 11254.96, -86.03719, 0.1309221, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+697, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11513.23, 11245.77, -83.25801, 2.159353, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+698, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11513.53, 11287.83, -88.1569, 5.399264, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+699, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11501.89, 11306.27, -89.95432, 1.861119, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+700, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11525.65, 11243.38, -83.12895, 0.9063579, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+701, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11498.35, 11298.54, -90.56091, 0.2761064, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+702, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11535.05, 11237.57, -78.58669, 3.932218, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+703, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11521.17, 11273.77, -87.05399, 4.198285, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
-- (@CGUID+704, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 4, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+705, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 6, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+706, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 6, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+707, 112039, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11542.83, 11288.3, -85.97662, 5.340205, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Screeching Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+708, 112078, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11556.26, 11156.44, -122.4317, 6.170538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pulsing Egg Sac (Area: Mulgore - Difficulty: Normal) (Auras: 215581 - Oeufs vibrant - cosmétique)
-- (@CGUID+709, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+710, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11539.45, 11247.25, -83.36858, 5.654794, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+711, 106510, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11530.34, 11291.86, -87.50114, 2.3668, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flight Loc Stalker (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+712, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 3, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+713, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 4, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+714, 112078, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11554.47, 11254.2, -80.89885, 3.674757, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pulsing Egg Sac (Area: Mulgore - Difficulty: Normal) (Auras: 215581 - Oeufs vibrant - cosmétique)
(@CGUID+715, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11491.68, 11327.99, -92.87758, 3.3239, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+716, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11520.52, 11321.38, -90.64677, 1.952028, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+717, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11544.05, 11253.26, -84.27038, 3.637862, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+718, 111439, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11376.59, 11392.78, -84.6529, 4.4478, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 221869 - Ombres distordues, 210792 - Ombres distordues)
(@CGUID+719, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11493.73, 11318.83, -89.72164, 2.562719, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+720, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 3, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+721, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+722, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11514.84, 11343.25, -93.07131, 1.95821, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+723, 113626, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, -5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants) - !!! on transport - transport template not found !!!
(@CGUID+724, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11426.97, 11421.8, -87.46895, 5.473705, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+725, 106510, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11411.78, 11408.35, -85.40462, 5.27214, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flight Loc Stalker (Area: Mulgore - Difficulty: Normal)
(@CGUID+726, 111439, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11431.46, 11396.32, -84.87776, 3.24655, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 221869 - Ombres distordues, 210792 - Ombres distordues)
-- (@CGUID+727, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+728, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11524.95, 11342.62, -91.29549, 1.562536, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+729, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11415.62, 11427.03, -86.3543, 2.207303, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+730, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 6, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+731, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11523.52, 11337.05, -90.44707, 5.986601, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+732, 111980, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11556.92, 11291.44, -84.95747, 2.852022, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmother (Area: Mulgore - Difficulty: Normal) (Auras: )
(@CGUID+733, 111933, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11540.07, 11324.05, -87.91753, 2.87587, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants)
(@CGUID+734, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11580.81, 11285.73, -79.86621, 5.066329, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+735, 107767, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, 4, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Shadows (Area: Mulgore - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+736, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11568.64, 11331.99, -84.76928, 4.607918, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+737, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11573.02, 11276.76, -79.84315, 3.932218, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+738, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11388.41, 11422.77, -85.50974, 3.107261, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+739, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11427.08, 11417.47, -87.77983, 1.350163, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+740, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11575.44, 11326.29, -85.62497, 6.237844, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+741, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11400.86, 11435.66, -86.00256, 2.350103, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+742, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11420.98, 11439.68, -84.75169, 1.29152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+743, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11409.25, 11445.28, -79.97234, 1.090847, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+744, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11403.76, 11443.26, -83.58125, 2.035463, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
(@CGUID+745, 112078, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11551.41, 11403.62, -117.489, 3.740242, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pulsing Egg Sac (Area: Mulgore - Difficulty: Normal) (Auras: 215581 - Oeufs vibrant - cosmétique)
(@CGUID+746, 108540, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11413.83, 11442.82, -83.6813, 2.158482, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Surging Egg Sac (Area: Mulgore - Difficulty: Normal)
-- (@CGUID+747, 113626, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, -5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants) - !!! on transport - transport template not found !!!
(@CGUID+748, 106087, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11405.56, 11400.7, -85.32238, 4.621968, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Elerethe Renferal (Area: Mulgore - Difficulty: Normal) (Auras: 226017 - Transformation initiale de druide)
(@CGUID+749, 92870, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11431.94, 11395.29, -75.90771, 3.613758, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Sindragosa's Fury (Area: Mulgore - Difficulty: Normal) (Auras: )

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+750, 92870, 1520, 8026, 8298, 245760, '0', 0, 0, 0, 11427.61, 11398.54, -75.85838, 3.702063, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sindragosa's Fury (Area: Mulgore - Difficulty: Normal) (Auras: )
-- (@CGUID+751, 107459, 0, 8026, 8298, 245760, '0', 0, 0, 0, 0, 0, -5, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Venomous Spiderling (Area: Mulgore - Difficulty: Normal) (Auras: 210229 - Crochets dégoulinants) - !!! on transport - transport template not found !!!
(@CGUID+752, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13013.64, 12212.12, -282.9019, 3.692162, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+753, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13008.89, 12140.9, -269.4925, 1.625509, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+754, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13224.52, 12167.64, -246.2245, 0.9570715, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+755, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13057.83, 12142.74, -272.056, 1.954396, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+756, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13161.55, 12040.54, -249.0186, 4.189227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+757, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12948.85, 12054.27, -265.5139, 3.579548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 223400 - Pétale-de-sang corrompu)
(@CGUID+758, 113520, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13046.83, 12559.48, -206.9688, 0.3130227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ancient Spirit (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 225758 - Visuels d’Ysera)
(@CGUID+759, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13138.72, 12239.87, -259.828, 5.650395, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+760, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13144.53, 12219.63, -228.107, 6.209403, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+761, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13067.05, 12222.89, -264.4781, 5.858014, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+762, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13205.62, 12152.87, -215.532, 0.5867219, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+763, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12943.72, 12082.81, -267.287, 0, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+764, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13015.18, 12079, -264.2446, 0.4752301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+765, 112168, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13068.94, 12238.04, -264.2471, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Bloodpetal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+766, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13210.48, 12175.53, -248.5338, 1.586481, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+767, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13185.48, 12168.71, -248.9882, 4.349677, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+768, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13122.94, 12254.24, -262.6962, 2.929271, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+769, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13074.38, 12198.32, -262.2263, 1.686307, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+770, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13165.89, 12018.98, -248.4008, 0.03515514, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+771, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13022.18, 12188.78, -282.7889, 6.219017, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+772, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13009.98, 12181.1, -282.6068, 3.225168, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+773, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13001.1, 12151.35, -271.5169, 5.531994, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 223400 - Pétale-de-sang corrompu)
(@CGUID+774, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13203.1, 12178.58, -248.2613, 0.1277106, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+775, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13049.48, 12127.6, -264.9281, 3.055309, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+776, 111860, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12954.77, 12251.48, -276.8613, 0.7856326, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Bo'lan the Marked (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 222879 - Diablosaure cauchemardesque)
(@CGUID+777, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13154.45, 12012.21, -248.4216, 4.132783, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+778, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13113.42, 12249.51, -262.6989, 5.884697, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+779, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13018.92, 12088.82, -263.3947, 6.010655, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+780, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13055.22, 12097.15, -258.22, 4.974644, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+781, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13025.39, 12089.46, -262.7256, 1.139239, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+782, 112168, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13000.01, 12147.08, -271.0989, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Bloodpetal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+783, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13219.79, 12181.08, -247.9234, 3.112523, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+784, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12969, 12110.68, -269.531, 0.5744655, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 223400 - Pétale-de-sang corrompu)
(@CGUID+785, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13120.81, 12244.61, -261.288, 1.597591, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+786, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13159.47, 12029.75, -248.6411, 3.226024, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+787, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13011.27, 12200.54, -282.7327, 5.323609, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+788, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13021.83, 12107.81, -262.9514, 0.4659281, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+789, 105304, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12843.59, 12331.36, -249.0134, 3.569767, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dominator Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+790, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13077.46, 12227.25, -263.1979, 4.10253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+791, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13073.35, 12122.04, -266.0949, 4.549489, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+792, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13165.64, 12021.39, -248.5527, 1.065373, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+793, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13161.36, 12023.31, -248.4587, 3.187794, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+794, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12993.02, 12075.31, -266.3144, 3.977854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+795, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13024.66, 12109.07, -263.0627, 1.420345, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+796, 112168, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12951.84, 12117.76, -270.7899, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Bloodpetal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+797, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13062.57, 12153.47, -273.3624, 5.365104, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+798, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13207.21, 12158.64, -244.9478, 0.06502075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+799, 112168, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13042.92, 12104.54, -260.4368, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Bloodpetal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+800, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13089.55, 12211.12, -259.7767, 5.650947, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+801, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12945.02, 12119.14, -270.7677, 3.037681, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 223400 - Pétale-de-sang corrompu) (possible waypoints or random movement)
(@CGUID+802, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13179.08, 12219.52, -254.8506, 1.684313, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+803, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13121.83, 12246.35, -261.5608, 2.430512, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+804, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13130.98, 12279.22, -208.746, 0.3434365, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+805, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13092.15, 12269.31, -265.4057, 4.433284, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+806, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13015.33, 12089.65, -263.5495, 1.121165, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+807, 105906, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12818.11, 12328.26, -245.7215, 3.795443, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Eye of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 209915 - Essence des cauchemars)
(@CGUID+808, 105304, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12821.77, 12302.83, -248.1222, 3.830852, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dominator Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+809, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13071.17, 12204.37, -263.102, 5.961435, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+810, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13051.78, 12140.43, -267.8506, 6.222107, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+811, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13017.2, 12196.48, -282.9021, 1.944435, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+812, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13159.31, 12009.04, -248.0568, 1.851256, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+813, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12947.12, 12105.88, -235.6324, 4.270488, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+814, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13009.18, 12098.72, -263.474, 5.835986, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+815, 112168, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12953.19, 12054.02, -265.3214, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Bloodpetal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+816, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13050.35, 12125.27, -264.5819, 5.630431, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+817, 112168, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13003.16, 12082.14, -264.9324, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tainted Bloodpetal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+818, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13067.49, 12222.14, -264.3684, 6.251945, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+819, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12960.76, 12050.29, -265.2455, 0.3736714, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+820, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13212.05, 12094.26, -241.8835, 3.040999, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+821, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13124.7, 12226.36, -258.5151, 5.172276, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+822, 112143, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13060.92, 12255.45, -264.9484, 1.175968, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flagellant pétale-de-sang (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+823, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13028.93, 12107.04, -262.3488, 3.569551, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+824, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13209.16, 12186.26, -246.9564, 3.934936, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+825, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13083.01, 12221.6, -262.0555, 2.142124, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+826, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13125.74, 12279.81, -230.4875, 5.019251, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+827, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12962.31, 12035.89, -228.8227, 2.438951, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+828, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12911.33, 12087.76, -271.0583, 4.637167, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+829, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12901.63, 12070.6, -270.0601, 3.655556, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+830, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12978.41, 12240.78, -282.9702, 1.314652, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+831, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12905.85, 12059.96, -268.9304, 3.146963, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+832, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12909.16, 12090.94, -241.8836, 4.33659, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+833, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12943.43, 12209.2, -282.5562, 5.638984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+834, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12913.34, 12071.38, -269.1519, 4.017526, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+835, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12922.15, 12156.79, -282.8256, 2.489175, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+836, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12907.79, 12050.19, -268.6146, 3.146963, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+837, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12902.55, 12134.26, -282.8074, 3.70326, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+838, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12918.82, 12060.12, -267.8368, 3.146963, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+839, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13001.25, 12271.43, -271.7963, 5.950473, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+840, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13018.77, 12281.57, -267.5209, 4.210128, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+841, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13003.15, 12286.57, -269.4989, 2.699334, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+842, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13018.61, 12294.49, -269.0894, 2.782136, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+843, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12873.41, 12175.43, -273.8024, 5.314514, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+844, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12996.83, 12302.8, -270.2152, 1.446002, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+845, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12888.34, 11990.55, -270.0401, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+846, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12977.35, 12298.38, -278.2577, 2.495864, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+847, 112118, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13008.45, 12305.98, -270.111, 4.967079, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pétale-de-sang corrompu (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+848, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12948.72, 12298.33, -276.9039, 3.859519, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+849, 111221, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12901.48, 12278.59, -262.0751, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+850, 113041, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13037.95, 12320.71, -269.662, 1.674744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Dimeurtrodon infecté (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+851, 105393, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12792.02, 12353.46, -244.8482, 3.149815, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 224929 - Déclencheur de Repoussement d’Il’gynoth, 210780 - Pire cauchemar)
(@CGUID+852, 113920, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12968.21, 12340.95, -278.3162, 4.346003, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Flail of Il'gynoth (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@CGUID+853, 113040, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -13020.27, 12419.91, -228.5406, 4.405259, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Pterreurdactyle frénétique (Area: Cratère d’Un’Goro - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+854, 73400, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12824.58, 12321.75, -248.4277, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+855, 92870, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12839.3, 12317.76, -239.0543, 0.4985533, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Sindragosa's Fury (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+856, 105322, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12836.86, 12333.24, -249.3577, 0.08894828, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Deathglare Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+857, 73400, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12821.5, 12327.46, -247.0273, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+858, 105591, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12852.11, 12298.65, -252.5724, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Nightmare Horror (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+859, 105383, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12847.92, 12334.87, -249.3293, 5.387468, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corruptor Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+860, 105383, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12836.86, 12333.24, -249.3577, 5.621372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Corruptor Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+861, 73400, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12822.97, 12323.95, -247.9056, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+862, 105322, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12845.41, 12338, -248.4048, 0.08255132, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Deathglare Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+863, 105322, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12819.38, 12300.72, -247.7564, 0.0612281, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Deathglare Tentacle (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: )
(@CGUID+864, 73400, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12826.08, 12323.71, -248.5265, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Healing Ran Invisible Stalker DND (Area: Cratère d’Un’Goro - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+865, 92870, 1520, 8026, 8034, 245760, '0', 0, 0, 0, -12793.87, 12331.99, -234.7279, 1.314107, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Sindragosa's Fury (Area: Cratère d’Un’Goro - Difficulty: Normal)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+865;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gelatinized Decay
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+88, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gelatinized Decay
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+115, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, '220189'), -- Nythendra - 220189 - Aura de visée de Nythendra
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+134, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+167, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+168, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+170, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+186, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+211, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+221, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+222, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Deathroot Ancient - 8279 - Détection du camouflage
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+225, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+232, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+242, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+243, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+246, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+249, 0, 0, 8, 1, 0, 0, 0, 0, ''); -- Taintheart Trickster

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Deathroot Ancient - 8279 - Détection du camouflage
(@CGUID+251, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+253, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+257, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Deathroot Ancient - 8279 - Détection du camouflage
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+270, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+280, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- Fog Beast Spawner Stalker - 222115 - Brouillard cauchemardesque
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+288, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+289, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+291, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+295, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+298, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+299, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+301, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+302, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+306, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+311, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Malfurion Hurlorage
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+315, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+316, 0, 0, 50331648, 1, 0, 0, 0, 0, '225758'), -- Ancient Spirit - 225758 - Visuels d’Ysera
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - 8279 - Détection du camouflage
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Essence of Nightmare
(@CGUID+319, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+320, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Breath Stalker
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+335, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+349, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+351, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+354, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+355, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+368, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+394, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+427, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+428, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+431, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+434, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+436, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+440, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+441, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+442, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+444, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+446, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+454, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+460, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+461, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+462, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+463, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+466, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+491, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+496, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, '196285'); -- Corrupted Vermin - 196285 -

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+503, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+523, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+525, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+526, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+527, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+528, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+529, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+530, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+531, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+532, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+533, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+534, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+535, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+537, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Vermin - 196285 -
(@CGUID+538, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+539, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+540, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+541, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+542, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+543, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+544, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+545, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+546, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+547, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+548, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+549, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+550, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+551, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+552, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+553, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Tormenter
(@CGUID+554, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+555, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+556, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Taintheart Trickster
(@CGUID+557, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+558, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - 225324 - Colère de drake
(@CGUID+559, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+560, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+561, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+562, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+563, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+564, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Satyr Channel Cosmetic Stalker
(@CGUID+565, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+566, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+567, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+568, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+569, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Nightmare Drake
(@CGUID+570, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+571, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Iris
(@CGUID+572, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Iris
(@CGUID+573, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Iris
(@CGUID+574, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Iris
(@CGUID+575, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+576, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+577, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+578, 0, 0, 0, 1, 0, 0, 0, 0, '205270'), -- Ursoc - 205270 -
(@CGUID+579, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+580, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+581, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+582, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+583, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+584, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+585, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+586, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+587, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+588, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+589, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+590, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+591, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+592, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+593, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+594, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+595, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+596, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+597, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+598, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+599, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+600, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+601, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+602, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+603, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Guardian Rurson
(@CGUID+604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Guardian Gorroc
(@CGUID+605, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+606, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+607, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+608, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+609, 0, 0, 50331648, 1, 0, 0, 0, 0, '225758'), -- Ancient Spirit - 225758 - Visuels d’Ysera
(@CGUID+610, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+611, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+612, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+613, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+614, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+615, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+616, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Grisly Trapper - 212515 - Aura de cauchemar
(@CGUID+617, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+618, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Dire Shaman - 212515 - Aura de cauchemar
(@CGUID+619, 0, 0, 0, 1, 0, 0, 0, 0, '222687 222696'), -- Tur Ragepaw - 222687 - Liens du Cauchemar, 222696 - Tur Ragepatte
(@CGUID+620, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+621, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Corrupted Feeler - 123978 - Échelle : 95-120%
(@CGUID+622, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Cosmetic Nightmare Tentacle - 123978 - Échelle : 95-120%
(@CGUID+623, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- Horrid Eagle - 212515 - Aura de cauchemar
(@CGUID+624, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+625, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightmare Rift
(@CGUID+626, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Gatewarden - 196285 -
(@CGUID+627, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Defiled Keeper - 196285 -
(@CGUID+628, 0, 0, 0, 1, 0, 0, 0, 0, '204617'), -- Shadowy Rift - 204617 - Portail cauchemardesque
(@CGUID+629, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+630, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Diseased Rift
(@CGUID+631, 0, 0, 0, 1, 0, 0, 0, 0, '205283 224200'), -- Ysondre - 205283 - , 224200 - Energie du Cauchemar
(@CGUID+632, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+633, 0, 0, 0, 1, 0, 0, 0, 0, '205283 224200 204719'), -- Lethon - 205283 - , 224200 - Energie du Cauchemar, 204719 - Liaison à la masse
(@CGUID+634, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Gatewarden - 196285 -
(@CGUID+635, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+636, 0, 0, 50331648, 1, 0, 0, 0, 0, '225758'), -- Ancient Spirit - 225758 - Visuels d’Ysera
(@CGUID+637, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+638, 0, 0, 0, 1, 0, 0, 0, 0, '223181 223180'), -- Rothos - 223181 - Don de Taerar, 223180 - Don de Léthon
(@CGUID+639, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+640, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+641, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+642, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Corrupted Gatewarden - 196285 -
(@CGUID+643, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- Defiled Keeper - 196285 -
(@CGUID+644, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- Swarming Dread - 204729 - Angoisse terrassante
(@CGUID+645, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+646, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+647, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+648, 0, 0, 0, 1, 0, 0, 0, 0, '205283'), -- Taerar - 205283 -
(@CGUID+649, 0, 0, 50331648, 1, 0, 0, 0, 0, '225758'), -- Ancient Spirit - 225758 - Visuels d’Ysera
(@CGUID+650, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - 225048 - Corruption du Cauchemar
(@CGUID+651, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Tainted Plainstrider - 225048 - Corruption du Cauchemar
(@CGUID+652, 0, 0, 50331648, 1, 0, 0, 0, 0, '225048'), -- Corrupted Swoop - 225048 - Corruption du Cauchemar
(@CGUID+653, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Sickly Cougar - 225048 - Corruption du Cauchemar
(@CGUID+654, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - 225048 - Corruption du Cauchemar
(@CGUID+655, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - 225048 - Corruption du Cauchemar
(@CGUID+656, 0, 0, 50331648, 1, 0, 0, 0, 0, '221869'), -- Elerethe Renferal - 221869 - Ombres distordues
(@CGUID+657, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Tainted Plainstrider - 225048 - Corruption du Cauchemar
(@CGUID+658, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Tainted Plainstrider - 225048 - Corruption du Cauchemar
(@CGUID+659, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Infected Gazelle - 225048 - Corruption du Cauchemar
(@CGUID+660, 0, 0, 50331648, 1, 0, 0, 0, 0, '225048'), -- Corrupted Swoop - 225048 - Corruption du Cauchemar
(@CGUID+661, 0, 0, 50331648, 1, 0, 0, 0, 0, '225048'), -- Corrupted Swoop - 225048 - Corruption du Cauchemar
(@CGUID+662, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - 225048 - Corruption du Cauchemar
(@CGUID+663, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Tainted Plainstrider - 225048 - Corruption du Cauchemar
(@CGUID+664, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Infected Gazelle - 225048 - Corruption du Cauchemar
(@CGUID+665, 0, 0, 50331648, 1, 0, 0, 0, 0, '225048'), -- Corrupted Swoop - 225048 - Corruption du Cauchemar
(@CGUID+666, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - 225048 - Corruption du Cauchemar
(@CGUID+667, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Sickly Cougar - 225048 - Corruption du Cauchemar
(@CGUID+668, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - 225048 - Corruption du Cauchemar
(@CGUID+669, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Elerethe Renferal
(@CGUID+670, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Infected Gazelle - 225048 - Corruption du Cauchemar
(@CGUID+671, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Tainted Plainstrider - 225048 - Corruption du Cauchemar
(@CGUID+672, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Infected Gazelle - 225048 - Corruption du Cauchemar
(@CGUID+673, 0, 0, 50331648, 1, 0, 0, 0, 0, '225048'), -- Corrupted Swoop - 225048 - Corruption du Cauchemar
(@CGUID+674, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Sickly Cougar - 225048 - Corruption du Cauchemar
(@CGUID+675, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Flight Loc Stalker
(@CGUID+676, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+677, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+678, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Screeching Spiderling - 210229 - Crochets dégoulinants
(@CGUID+679, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+680, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+681, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+682, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shadowfeather
(@CGUID+683, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+684, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+685, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+687, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+688, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+689, 0, 0, 0, 1, 0, 0, 0, 0, '215581'), -- Pulsing Egg Sac - 215581 - Oeufs vibrant - cosmétique
(@CGUID+690, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+691, 0, 0, 50331648, 1, 0, 0, 0, 0, '221869 210792'), -- Twisting Shadows - 221869 - Ombres distordues, 210792 - Ombres distordues
(@CGUID+692, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+693, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+694, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+695, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+697, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+698, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+699, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+700, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+701, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+702, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+703, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+704, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+705, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+706, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+707, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Screeching Spiderling - 210229 - Crochets dégoulinants
(@CGUID+708, 0, 0, 0, 1, 0, 0, 0, 0, '215581'), -- Pulsing Egg Sac - 215581 - Oeufs vibrant - cosmétique
(@CGUID+709, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+710, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+711, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Flight Loc Stalker
(@CGUID+712, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+713, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+714, 0, 0, 0, 1, 0, 0, 0, 0, '215581'), -- Pulsing Egg Sac - 215581 - Oeufs vibrant - cosmétique
(@CGUID+715, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+716, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+717, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+718, 0, 0, 50331648, 1, 0, 0, 0, 0, '221869 210792'), -- Twisting Shadows - 221869 - Ombres distordues, 210792 - Ombres distordues
(@CGUID+719, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+720, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+721, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+722, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+723, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+724, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+725, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Flight Loc Stalker
(@CGUID+726, 0, 0, 50331648, 1, 0, 0, 0, 0, '221869 210792'), -- Twisting Shadows - 221869 - Ombres distordues, 210792 - Ombres distordues
(@CGUID+727, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+728, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+730, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+731, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+732, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightmother
(@CGUID+733, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+734, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+735, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Twisting Shadows - 46598 - Ride Vehicle Hardcoded
(@CGUID+736, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+737, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+738, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+739, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+740, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+741, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+742, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+743, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+744, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+745, 0, 0, 0, 1, 0, 0, 0, 0, '215581'), -- Pulsing Egg Sac - 215581 - Oeufs vibrant - cosmétique
(@CGUID+746, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Surging Egg Sac
(@CGUID+747, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+748, 0, 0, 0, 1, 0, 0, 0, 0, '226017'), -- Elerethe Renferal - 226017 - Transformation initiale de druide
(@CGUID+749, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- Sindragosa's Fury

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+750, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+751, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- Venomous Spiderling - 210229 - Crochets dégoulinants
(@CGUID+752, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+753, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+754, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+755, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+756, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+757, 0, 0, 0, 1, 0, 0, 0, 0, '223400'), -- Flagellant pétale-de-sang - 223400 - Pétale-de-sang corrompu
(@CGUID+758, 0, 0, 50331648, 1, 0, 0, 0, 0, '225758'), -- Ancient Spirit - 225758 - Visuels d’Ysera
(@CGUID+759, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+760, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+761, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+762, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+763, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+764, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+765, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Bloodpetal
(@CGUID+766, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+767, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+768, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+769, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+770, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+771, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+772, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+773, 0, 0, 0, 1, 0, 0, 0, 0, '223400'), -- Flagellant pétale-de-sang - 223400 - Pétale-de-sang corrompu
(@CGUID+774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+775, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+776, 0, 0, 0, 1, 0, 0, 0, 0, '222879'), -- Bo'lan the Marked - 222879 - Diablosaure cauchemardesque
(@CGUID+777, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+778, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+779, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+780, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+781, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+782, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Bloodpetal
(@CGUID+783, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+784, 0, 0, 0, 1, 0, 0, 0, 0, '223400'), -- Flagellant pétale-de-sang - 223400 - Pétale-de-sang corrompu
(@CGUID+785, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+786, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+787, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+788, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+789, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Dominator Tentacle
(@CGUID+790, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+791, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+792, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+793, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+794, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+795, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+796, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Bloodpetal
(@CGUID+797, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+798, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+799, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Bloodpetal
(@CGUID+800, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+801, 0, 0, 0, 1, 0, 0, 0, 0, '223400'), -- Flagellant pétale-de-sang - 223400 - Pétale-de-sang corrompu
(@CGUID+802, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+804, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+805, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+806, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+807, 0, 0, 50331648, 1, 0, 0, 0, 0, '209915'), -- Eye of Il'gynoth - 209915 - Essence des cauchemars
(@CGUID+808, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Dominator Tentacle
(@CGUID+809, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+810, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+811, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+812, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+813, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+814, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+815, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Bloodpetal
(@CGUID+816, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+817, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tainted Bloodpetal
(@CGUID+818, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+819, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+820, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+821, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+822, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(@CGUID+823, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+824, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+825, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+826, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+827, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+828, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+829, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+830, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+831, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+832, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+834, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+835, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+836, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+837, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+838, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+839, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+840, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+841, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+842, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+843, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+844, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+845, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+846, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+847, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(@CGUID+848, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+849, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+850, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(@CGUID+851, 0, 0, 50331648, 1, 0, 0, 0, 0, '224929 210780'), -- Il'gynoth - 224929 - Déclencheur de Repoussement d’Il’gynoth, 210780 - Pire cauchemar
(@CGUID+852, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flail of Il'gynoth
(@CGUID+853, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(@CGUID+854, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+855, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+856, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Deathglare Tentacle
(@CGUID+857, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+858, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nightmare Horror
(@CGUID+859, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Corruptor Tentacle
(@CGUID+860, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Corruptor Tentacle
(@CGUID+861, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+862, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Deathglare Tentacle
(@CGUID+863, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Deathglare Tentacle
(@CGUID+864, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+865, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- Sindragosa's Fury

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 251536, 1520, 8026, 8026, 245760, '0', 0, 1848.6, 1384.651, 369.0928, 4.757155, 0, 0, -0.6911039, 0.7227554, 604800, 255, 0, 26124), -- Doodad_7DU_Nightmare_RootWall004 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+1, 251535, 1520, 8026, 8026, 245760, '0', 0, 1837.144, 1385.495, 369.7708, 1.61907, 0, 0, 0.7239666, 0.689835, 604800, 255, 0, 26124), -- Doodad_7DU_Nightmare_RootWall003 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+2, 253129, 1520, 8026, 8026, 245760, '0', 0, 1790.936, 1421.97, 350.1419, 0.2969019, 0, 0, 0.1479063, 0.9890014, 604800, 255, 1, 26124), -- Instance Portal (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+3, 251534, 1520, 8026, 8026, 245760, '0', 0, 1911.963, 1261.471, 368.3508, 4.885175, 0, 0, -0.6434565, 0.7654827, 604800, 255, 1, 26124), -- Doodad_7DU_Nightmare_RootWall002 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+4, 251533, 1520, 8026, 8026, 245760, '0', 0, 1903.908, 1261.17, 368.3508, 1.765096, 0, 0, 0.7723598, 0.6351852, 604800, 255, 1, 26124), -- Doodad_7DU_Nightmare_RootWall001 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+5, 248928, 1520, 8026, 8026, 245760, '0', 0, 1876.323, 1325.014, 597.8997, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Grizzly Vines (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+6, 248929, 1520, 8026, 8026, 245760, '0', 0, 1876.323, 1325.014, 597.8997, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Dragons Vines (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+7, 248926, 1520, 8026, 8026, 245760, '0', 0, 1876.323, 1325.014, 597.8997, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Ungoro Vines (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+8, 248927, 1520, 8026, 8026, 245760, '0', 0, 1876.323, 1325.014, 597.8997, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Thunder Bluff Vines (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+9, 248925, 1520, 8026, 8026, 245760, '0', 0, 1876.323, 1325.014, 597.8997, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Entrance Vines (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+10, 254272, 1520, 8026, 8026, 245760, '0', 0, 1988.717, 1339.299, 582.8891, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Grizzly Hills (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+11, 254273, 1520, 8026, 8026, 245760, '0', 0, 1933.413, 1273.809, 643.7105, 2.268925, 0, 0, 0.9063072, 0.4226195, 604800, 255, 1, 26124), -- The Emerald Dreamway (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+12, 254270, 1520, 8026, 8026, 245760, '0', 0, 1793.171, 1331.155, 613.6365, 0, 0, 0, 0, 1, 604800, 255, 1, 26124), -- Un'goro Crater (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+13, 254271, 1520, 8026, 8026, 245760, '0', 0, 1831.417, 1252.326, 615.4836, 0.9930774, 0, 0, 0.4763851, 0.8792367, 604800, 255, 1, 26124), -- Thunder Bluff (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+14, 260550, 1520, 8026, 8026, 245760, '0', 0, 1864.35, 1407.664, 589.7158, 1.906457, -0.05629492, 0.0787735, 0.8097715, 0.5787017, 604800, 255, 0, 26124), -- Doodad_7DU_Nightmare_RootWall008 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+15, 260551, 1520, 8026, 8026, 245760, '0', 0, 1854.764, 1405.274, 589.7156, 1.906457, -0.05629492, 0.0787735, 0.8097715, 0.5787017, 604800, 255, 0, 26124), -- Doodad_7DU_Nightmare_RootWall009 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+16, 260552, 1520, 8026, 8026, 245760, '0', 0, 1845.235, 1401.094, 592.269, 1.93579, -0.05622149, 0.1728992, 0.8006535, 0.5708756, 604800, 255, 0, 26124), -- Doodad_7DU_Nightmare_RootWall010 (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+17, 251980, 1520, 8026, 8026, 245760, '0', 0, 1875.788, 1328.563, 598.7389, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 26124), -- Nightmare Iris (Area: Le Cauchemar d’émeraude - Difficulty: Normal)
(@OGUID+18, 252042, 1520, 8026, 7953, 245760, '0', 0, -12282.51, -13095.09, 327.3927, 3.019413, 0, 0, 0.9981346, 0.06105176, 604800, 255, 0, 26124), -- Door (Area: Les Grisonnes - Difficulty: Normal)
(@OGUID+19, 252043, 1520, 8026, 7953, 245760, '0', 0, -12279.71, -13111.13, 327.5927, 3.551751, 0, 0, -0.9790449, 0.2036445, 604800, 255, 0, 26124), -- Door (Area: Les Grisonnes - Difficulty: Normal)
(@OGUID+20, 252004, 1520, 8026, 7953, 245760, '0', 0, -12359.09, -12956.2, 336.3266, 3.447027, 0, 0, -0.9883614, 0.1521243, 604800, 255, 1, 26124), -- Portal (Area: Les Grisonnes - Difficulty: Normal)
(@OGUID+21, 252006, 1520, 8026, 8190, 245760, '0', 0, 454.8681, -12729.91, 34.96235, 4.89565, 0, 0, -0.6394386, 0.7688421, 604800, 255, 1, 26124), -- Portal (Area: Chemin du Rêve d’émeraude - Difficulty: Normal)
(@OGUID+22, 255000, 1520, 8026, 8298, 245760, '0', 0, 11349.17, 11181.61, -103.5485, 3.874631, 0, 0, -0.9335804, 0.358368, 604800, 255, 0, 26124), -- Twisting Roots (Area: Mulgore - Difficulty: Normal)
(@OGUID+23, 251995, 1520, 8026, 8298, 245760, '0', 0, 11326.44, 11030.37, 20.63319, 1.640607, 0, 0, 0.7313528, 0.6819993, 604800, 255, 1, 26124), -- Portal (Area: Mulgore - Difficulty: Normal)
(@OGUID+24, 254247, 1520, 8026, 8034, 245760, '0', 0, -13214.73, 12092.73, -241.4587, 0.3005705, 0, 0, 0.1497202, 0.9887284, 604800, 255, 1, 26124), -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+25, 251555, 1520, 8026, 8034, 245760, '0', 0, -12818.58, 12328.89, -250.6537, 0.6806767, 0, 0, 0.333806, 0.9426418, 604800, 255, 1, 26124), -- Eye of Il'gynoth's Forcefield (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+26, 254247, 1520, 8026, 8034, 245760, '0', 0, -13010.91, 12129.03, -265.9635, 0.3005705, 0, 0, 0.1497202, 0.9887284, 604800, 255, 1, 26124), -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+27, 248850, 1520, 8026, 8034, 245760, '0', 0, -12894.22, 12284.15, -259.679, 3.481937, 0, 0, -0.9855556, 0.169352, 604800, 255, 0, 26124), -- Wall of Roots (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+28, 248848, 1520, 8026, 8034, 245760, '0', 0, -12891.59, 12277.45, -259.6259, 0.6195911, 0, 0, 0.3048639, 0.9523959, 604800, 255, 0, 26124), -- NgihtmareRaid_UnGoro_RootWall03 (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+29, 248849, 1520, 8026, 8034, 245760, '0', 0, -12898.63, 12291.74, -258.5766, 3.769912, 0, 0, -0.9510565, 0.3090171, 604800, 255, 0, 26124), -- Wall of Roots (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+30, 251997, 1520, 8026, 8034, 245760, '0', 0, -13149.69, 12074.34, -249.8499, 1.108283, 0, 0, 0.5262136, 0.8503524, 604800, 255, 1, 26124), -- Portal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+31, 254248, 1520, 8026, 8034, 245760, '0', 0, -13191.6, 12216.93, -253.7561, 0.3005705, 0, 0, 0.1497202, 0.9887284, 604800, 255, 1, 26124), -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+32, 254249, 1520, 8026, 8034, 245760, '0', 0, -13110.71, 12057.91, -251.4818, 0.3005705, 0, 0, 0.1497202, 0.9887284, 604800, 255, 1, 26124), -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+33, 254248, 1520, 8026, 8034, 245760, '0', 0, -13027.05, 12264.23, -267.3759, 0.3005705, 0, 0, 0.1497202, 0.9887284, 604800, 255, 1, 26124), -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+34, 254249, 1520, 8026, 8034, 245760, '0', 0, -12870.58, 12116.54, -276.382, 0.05497165, -0.0259881, -0.0549202, 0.02593994, 0.9978154, 604800, 255, 1, 26124), -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
(@OGUID+35, 254248, 1520, 8026, 8034, 245760, '0', 0, -12947.4, 12471.07, -272.2379, 0.3005705, 0, 0, 0.1497202, 0.9887284, 604800, 255, 1, 26124); -- Corrupted Power Crystal (Area: Cratère d’Un’Goro - Difficulty: Normal)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall004
(@OGUID+1, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall003
(@OGUID+3, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall002
(@OGUID+4, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall001
(@OGUID+5, 0, 0, 1, -0.00000004371139), -- Grizzly Vines
(@OGUID+6, 0, 0, 1, -0.00000004371139), -- Dragons Vines
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- Ungoro Vines
(@OGUID+8, 0, 0, 1, -0.00000004371139), -- Thunder Bluff Vines
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- Entrance Vines
(@OGUID+10, 0, 0, 1, -0.00000004371139), -- Grizzly Hills
(@OGUID+11, 0, 0, 1, -0.00000004371139), -- The Emerald Dreamway
(@OGUID+12, 0, 0, 1, -0.00000004371139), -- Un'goro Crater
(@OGUID+13, 0, 0, 1, -0.00000004371139), -- Thunder Bluff
(@OGUID+14, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall008
(@OGUID+15, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall009
(@OGUID+16, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_Nightmare_RootWall010
(@OGUID+17, 0, 0, 1, -0.00000004371139); -- Nightmare Iris

DELETE FROM `spell_target_position` WHERE (`ID`=224877 AND `EffectIndex`=0) OR (`ID`=224891 AND `EffectIndex`=0) OR (`ID`=224878 AND `EffectIndex`=0) OR (`ID`=224893 AND `EffectIndex`=0) OR (`ID`=224879 AND `EffectIndex`=0) OR (`ID`=224894 AND `EffectIndex`=0) OR (`ID`=224880 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(224877, 0, 1520, -13141.8, 12097.2, -256.58, 26124), -- Spell: Téléportation vers Un’goro Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(224891, 0, 1520, 1855.54, 1284.94, 598.14, 26124), -- Spell: Téléportation depuis les Pitons-du-Tonnerre Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(224878, 0, 1520, 11328.1, 11057.6, 13.35, 26124), -- Spell: Téléportation vers les Pitons-du-Tonnerre Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(224893, 0, 1520, 1905.47, 1303.19, 601.87, 26124), -- Spell: Téléportation depuis le chemin du Rêve d’émeraude Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(224879, 0, 1520, 459.38, -12757.3, 27.12, 26124), -- Spell: Téléportation vers le chemin du Rêve d’émeraude Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(224894, 0, 1520, 1944.71, 1351.92, 581.97, 26124), -- Spell: Téléportation depuis les Grisonnes Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(224880, 0, 1520, -12378.8, -12959.7, 328.66, 26124); -- Spell: Téléportation vers les Grisonnes Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)


DELETE FROM `creature_template_addon` WHERE `entry` IN (105383 /*105383 (Corruptor Tentacle)*/, 105591 /*105591 (Nightmare Horror)*/, 105322 /*105322 (Deathglare Tentacle)*/, 105393 /*105393 (Il'gynoth) - Déclencheur de Repoussement d’Il’gynoth, Pire cauchemar*/, 105906 /*105906 (Eye of Il'gynoth) - Essence des cauchemars*/, 105304 /*105304 (Dominator Tentacle)*/, 111860 /*111860 (Bo'lan the Marked) - Diablosaure cauchemardesque*/, 112168 /*112168 (Tainted Bloodpetal)*/, 113041 /*Dimeurtrodon infecté*/, 113040 /*Pterreurdactyle frénétique*/, 112143 /*Flagellant pétale-de-sang*/, 113920 /*113920 (Flail of Il'gynoth)*/, 112118 /*Pétale-de-sang corrompu*/, 107459 /*107459 (Venomous Spiderling) - Crochets dégoulinants*/, 106087 /*106087 (Elerethe Renferal) - Transformation initiale de druide*/, 111980 /*111980 (Nightmother)*/, 113626 /*113626 (Venomous Spiderling) - Crochets dégoulinants*/, 109849 /*109849 (Nightmare Spawn Stalker)*/, 111439 /*111439 (Twisting Shadows) - Ombres distordues, Ombres distordues*/, 107767 /*107767 (Twisting Shadows) - Ride Vehicle Hardcoded*/, 112078 /*112078 (Pulsing Egg Sac) - Oeufs vibrant - cosmétique*/, 108540 /*108540 (Surging Egg Sac)*/, 111975 /*111975 (Shadowfeather)*/, 112039 /*112039 (Screeching Spiderling) - Crochets dégoulinants*/, 111933 /*111933 (Venomous Spiderling) - Crochets dégoulinants*/, 106510 /*106510 (Flight Loc Stalker)*/, 113604 /*113604 (Elerethe Renferal)*/, 113093 /*113093 (Infected Gazelle) - Corruption du Cauchemar*/, 113609 /*113609 (Elerethe Renferal) - Ombres distordues*/, 113106 /*113106 (Sickly Cougar) - Corruption du Cauchemar*/, 113103 /*113103 (Corrupted Swoop) - Corruption du Cauchemar*/, 113091 /*113091 (Tainted Plainstrider) - Corruption du Cauchemar*/, 113108 /*Lapin cauchemardesque - Corruption du Cauchemar*/, 102681 /*102681 (Taerar)*/, 111852 /*111852 (Rothos) - Don de Taerar, Don de Léthon*/, 102682 /*102682 (Lethon) - , Energie du Cauchemar, Liaison à la masse*/, 102679 /*102679 (Ysondre) - , Energie du Cauchemar*/, 103378 /*103378 (Diseased Rift)*/, 113092 /*113092 (Swarming Dread) - Angoisse terrassante*/, 103396 /*103396 (Shadowy Rift) - Portail cauchemardesque*/, 113089 /*113089 (Defiled Keeper)*/, 113090 /*113090 (Corrupted Gatewarden)*/, 103395 /*103395 (Nightmare Rift)*/, 111263 /*111263 (Tur Ragepaw) - Liens du Cauchemar, Tur Ragepatte*/, 111856 /*111856 (Guardian Gorroc)*/, 111858 /*111858 (Guardian Rurson)*/, 112303 /*112303 (Horrid Eagle) - Aura de cauchemar*/, 112290 /*112290 (Horrid Eagle) - Aura de cauchemar*/, 113088 /*113088 (Corrupted Feeler) - Échelle : 95-120%*/, 100497 /*100497 (Ursoc)*/, 112162 /*112162 (Grisly Trapper) - Aura de cauchemar*/, 112153 /*112153 (Dire Shaman) - Aura de cauchemar*/, 112307 /*112307 (Cosmetic Nightmare Tentacle) - Échelle : 95-120%*/, 113575 /*113575 (Iris)*/, 111567 /*111567 (Nightmare Drake)*/, 113203 /*Fureur de drake - Colère de drake*/, 102930 /*102930 (Breath Stalker)*/, 113520 /*113520 (Ancient Spirit) - Visuels d’Ysera*/, 106482 /*Malfurion Hurlorage*/, 111535 /*111535 (Fog Beast Spawner Stalker) - Brouillard cauchemardesque*/, 111354 /*Corrupteur cœur-corrompu - Détection du camouflage*/, 111412 /*111412 (Satyr Channel Cosmetic Stalker)*/, 111528 /*111528 (Deathroot Ancient) - Détection du camouflage*/, 111333 /*111333 (Taintheart Trickster)*/, 113113 /*113113 (Essence of Nightmare)*/, 111355 /*111355 (Taintheart Tormenter)*/, 102672 /*102672 (Nythendra) - Aura de visée de Nythendra*/, 111004 /*111004 (Gelatinized Decay)*/, 102998 /*102998 (Corrupted Vermin)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(105383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105383 (Corruptor Tentacle)
(105591, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105591 (Nightmare Horror)
(105322, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105322 (Deathglare Tentacle)
(105393, 0, 0, 50331648, 1, 0, 0, 0, 0, '224929 210780'), -- 105393 (Il'gynoth) - Déclencheur de Repoussement d’Il’gynoth, Pire cauchemar
(105906, 0, 0, 50331648, 1, 0, 0, 0, 0, '209915'), -- 105906 (Eye of Il'gynoth) - Essence des cauchemars
(105304, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 105304 (Dominator Tentacle)
(111860, 0, 0, 0, 1, 0, 0, 0, 0, '222879'), -- 111860 (Bo'lan the Marked) - Diablosaure cauchemardesque
(112168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112168 (Tainted Bloodpetal)
(113041, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Dimeurtrodon infecté
(113040, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Pterreurdactyle frénétique
(112143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Flagellant pétale-de-sang
(113920, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113920 (Flail of Il'gynoth)
(112118, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pétale-de-sang corrompu
(107459, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- 107459 (Venomous Spiderling) - Crochets dégoulinants
(106087, 0, 0, 0, 1, 0, 0, 0, 0, '226017'), -- 106087 (Elerethe Renferal) - Transformation initiale de druide
(111980, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111980 (Nightmother)
(113626, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- 113626 (Venomous Spiderling) - Crochets dégoulinants
(109849, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 109849 (Nightmare Spawn Stalker)
(111439, 0, 0, 50331648, 1, 0, 0, 0, 0, '221869 210792'), -- 111439 (Twisting Shadows) - Ombres distordues, Ombres distordues
(107767, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 107767 (Twisting Shadows) - Ride Vehicle Hardcoded
(112078, 0, 0, 0, 1, 0, 0, 0, 0, '215581'), -- 112078 (Pulsing Egg Sac) - Oeufs vibrant - cosmétique
(108540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108540 (Surging Egg Sac)
(111975, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111975 (Shadowfeather)
(112039, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- 112039 (Screeching Spiderling) - Crochets dégoulinants
(111933, 0, 0, 0, 1, 0, 0, 0, 0, '210229'), -- 111933 (Venomous Spiderling) - Crochets dégoulinants
(106510, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 106510 (Flight Loc Stalker)
(113604, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 113604 (Elerethe Renferal)
(113093, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- 113093 (Infected Gazelle) - Corruption du Cauchemar
(113609, 0, 0, 50331648, 1, 0, 0, 0, 0, '221869'), -- 113609 (Elerethe Renferal) - Ombres distordues
(113106, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- 113106 (Sickly Cougar) - Corruption du Cauchemar
(113103, 0, 0, 50331648, 1, 0, 0, 0, 0, '225048'), -- 113103 (Corrupted Swoop) - Corruption du Cauchemar
(113091, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- 113091 (Tainted Plainstrider) - Corruption du Cauchemar
(113108, 0, 0, 0, 1, 0, 0, 0, 0, '225048'), -- Lapin cauchemardesque - Corruption du Cauchemar
(102681, 0, 0, 0, 1, 0, 0, 0, 0, '205283'), -- 102681 (Taerar)
(111852, 0, 0, 0, 1, 0, 0, 0, 0, '223181 223180'), -- 111852 (Rothos) - Don de Taerar, Don de Léthon
(102682, 0, 0, 0, 1, 0, 0, 0, 0, '205283 224200 204719'), -- 102682 (Lethon) - , Energie du Cauchemar, Liaison à la masse
(102679, 0, 0, 0, 1, 0, 0, 0, 0, '205283 224200'), -- 102679 (Ysondre) - , Energie du Cauchemar
(103378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103378 (Diseased Rift)
(113092, 0, 0, 0, 1, 0, 0, 0, 0, '204729'), -- 113092 (Swarming Dread) - Angoisse terrassante
(103396, 0, 0, 0, 1, 0, 0, 0, 0, '204617'), -- 103396 (Shadowy Rift) - Portail cauchemardesque
(113089, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- 113089 (Defiled Keeper)
(113090, 0, 0, 0, 1, 0, 0, 0, 0, '196285'), -- 113090 (Corrupted Gatewarden)
(103395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103395 (Nightmare Rift)
(111263, 0, 0, 0, 1, 0, 0, 0, 0, '222687 222696'), -- 111263 (Tur Ragepaw) - Liens du Cauchemar, Tur Ragepatte
(111856, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111856 (Guardian Gorroc)
(111858, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111858 (Guardian Rurson)
(112303, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- 112303 (Horrid Eagle) - Aura de cauchemar
(112290, 0, 0, 1, 1, 0, 0, 0, 0, '212515'), -- 112290 (Horrid Eagle) - Aura de cauchemar
(113088, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 113088 (Corrupted Feeler) - Échelle : 95-120%
(100497, 0, 0, 0, 1, 0, 0, 0, 0, '205270'), -- 100497 (Ursoc)
(112162, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- 112162 (Grisly Trapper) - Aura de cauchemar
(112153, 0, 0, 0, 1, 0, 0, 0, 0, '212515'), -- 112153 (Dire Shaman) - Aura de cauchemar
(112307, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 112307 (Cosmetic Nightmare Tentacle) - Échelle : 95-120%
(113575, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 113575 (Iris)
(111567, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 111567 (Nightmare Drake)
(113203, 0, 0, 50331648, 1, 0, 0, 0, 0, '225324'), -- Fureur de drake - Colère de drake
(102930, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 102930 (Breath Stalker)
(113520, 0, 0, 50331648, 1, 0, 0, 0, 0, '225758'), -- 113520 (Ancient Spirit) - Visuels d’Ysera
(106482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Malfurion Hurlorage
(111535, 0, 0, 0, 1, 0, 0, 0, 0, '222115'), -- 111535 (Fog Beast Spawner Stalker) - Brouillard cauchemardesque
(111354, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- Corrupteur cœur-corrompu - Détection du camouflage
(111412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111412 (Satyr Channel Cosmetic Stalker)
(111528, 0, 0, 0, 1, 0, 0, 0, 0, '8279'), -- 111528 (Deathroot Ancient) - Détection du camouflage
(111333, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111333 (Taintheart Trickster)
(113113, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113113 (Essence of Nightmare)
(111355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111355 (Taintheart Tormenter)
(102672, 0, 0, 0, 1, 0, 0, 0, 0, '220189'), -- 102672 (Nythendra) - Aura de visée de Nythendra
(111004, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111004 (Gelatinized Decay)
(102998, 0, 0, 0, 1, 0, 0, 0, 0, '196285'); -- 102998 (Corrupted Vermin)


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (111567, 112143, 112178);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(111567, 0, 26124),
(112143, 0, 26124),
(112178, 0, 26124);



UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69880;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69881;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69115;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69879;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69882;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=47511;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72624;
UPDATE `creature_model_info` SET `BoundingRadius`=4.428069, `VerifiedBuild`=26124 WHERE `DisplayID`=41485;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=43560;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=73008;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69316;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71937;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70606;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65258;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65922;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67790;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=42838;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70237;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1547;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=18406;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72878;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=4626;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=2031;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1105;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9608659, `VerifiedBuild`=26124 WHERE `DisplayID`=1284;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67745;
UPDATE `creature_model_info` SET `BoundingRadius`=8.455193, `VerifiedBuild`=26124 WHERE `DisplayID`=69096;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67749;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67748;
UPDATE `creature_model_info` SET `CombatReach`=1.595745, `VerifiedBuild`=26124 WHERE `DisplayID`=71539;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69643;
UPDATE `creature_model_info` SET `BoundingRadius`=1.672791, `VerifiedBuild`=26124 WHERE `DisplayID`=24555;
UPDATE `creature_model_info` SET `BoundingRadius`=2.131796, `VerifiedBuild`=26124 WHERE `DisplayID`=72647;
UPDATE `creature_model_info` SET `BoundingRadius`=1.279078, `VerifiedBuild`=26124 WHERE `DisplayID`=63266;
UPDATE `creature_model_info` SET `BoundingRadius`=4.476369, `VerifiedBuild`=26124 WHERE `DisplayID`=72012;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72640;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66676;
UPDATE `creature_model_info` SET `BoundingRadius`=1.705437, `VerifiedBuild`=26124 WHERE `DisplayID`=23773;
UPDATE `creature_model_info` SET `BoundingRadius`=1.406985, `VerifiedBuild`=26124 WHERE `DisplayID`=62198;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72021;
UPDATE `creature_model_info` SET `BoundingRadius`=4.227596, `VerifiedBuild`=26124 WHERE `DisplayID`=69158;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27710;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68977;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70004;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65064;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66740;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72644;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66106;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68077;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71690;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=113090 AND `ID`=1) OR (`CreatureID`=111856 AND `ID`=1) OR (`CreatureID`=111858 AND `ID`=1) OR (`CreatureID`=112162 AND `ID`=1) OR (`CreatureID`=112153 AND `ID`=1) OR (`CreatureID`=111354 AND `ID`=1) OR (`CreatureID`=111333 AND `ID`=1) OR (`CreatureID`=111355 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(113090, 1, 137012, 0, 0, 0, 0, 0, 0, 0, 0), -- Corrupted Gatewarden
(111856, 1, 111070, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardian Gorroc
(111858, 1, 39422, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardian Rurson
(112162, 1, 118801, 0, 0, 0, 0, 0, 0, 0, 0), -- Grisly Trapper
(112153, 1, 59288, 0, 0, 0, 0, 0, 0, 0, 0), -- Dire Shaman
(111354, 1, 51432, 0, 0, 0, 0, 0, 0, 0, 0), -- Corrupteur cœur-corrompu
(111333, 1, 137012, 0, 0, 0, 0, 0, 0, 0, 0), -- Taintheart Trickster
(111355, 1, 51392, 0, 0, 0, 0, 0, 0, 0, 0); -- Taintheart Tormenter



UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=105383; -- Corruptor Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33587456, `unit_flags2`=6291456 WHERE `entry`=105591; -- Nightmare Horror
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=105322; -- Deathglare Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2656256 WHERE `entry`=105393; -- Il'gynoth
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=105906; -- Eye of Il'gynoth
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=6293504 WHERE `entry`=105304; -- Dominator Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=111860; -- Bo'lan the Marked
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=112168; -- Tainted Bloodpetal
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113041; -- Dimeurtrodon infecté
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113040; -- Pterreurdactyle frénétique
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=112143; -- Flagellant pétale-de-sang
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=1.428571, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113920; -- Flail of Il'gynoth
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112118; -- Pétale-de-sang corrompu
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000 WHERE `entry`=107459; -- Venomous Spiderling
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=256, `unit_flags2`=1073741824, `unit_flags3`=1 WHERE `entry`=106087; -- Elerethe Renferal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2 WHERE `entry`=111980; -- Nightmother
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000 WHERE `entry`=113626; -- Venomous Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=67110912 WHERE `entry`=109849; -- Nightmare Spawn Stalker
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=1.2, `speed_run`=0.4285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `VehicleId`=4798 WHERE `entry`=111439; -- Twisting Shadows
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4799 WHERE `entry`=107767; -- Twisting Shadows
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=634, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554432 WHERE `entry`=112078; -- Pulsing Egg Sac
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=634, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33554432 WHERE `entry`=108540; -- Surging Egg Sac
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2 WHERE `entry`=111975; -- Shadowfeather
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000 WHERE `entry`=112039; -- Screeching Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000 WHERE `entry`=111933; -- Venomous Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=67110912 WHERE `entry`=106510; -- Flight Loc Stalker
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=768, `unit_flags2`=4194304, `unit_flags3`=1 WHERE `entry`=113604; -- Elerethe Renferal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113093; -- Infected Gazelle
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200, `unit_flags2`=1073741824, `unit_flags3`=1 WHERE `entry`=113609; -- Elerethe Renferal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2156, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113106; -- Sickly Cougar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=15, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113103; -- Corrupted Swoop
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=189, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113091; -- Tainted Plainstrider
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=113108; -- Lapin cauchemardesque
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=1077936128, `HoverHeight`=14.5 WHERE `entry`=102681; -- Taerar
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=6293504, `HoverHeight`=9 WHERE `entry`=111852; -- Rothos
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=1075838976, `HoverHeight`=14.5 WHERE `entry`=102682; -- Lethon
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=1077936128, `HoverHeight`=16 WHERE `entry`=102679; -- Ysondre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=103378; -- Diseased Rift
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113092; -- Swarming Dread
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=103396; -- Shadowy Rift
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113089; -- Defiled Keeper
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=5.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=113090; -- Corrupted Gatewarden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=103395; -- Nightmare Rift
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=111263; -- Tur Ragepaw
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048, `VehicleId`=4852 WHERE `entry`=111856; -- Guardian Gorroc
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048, `VehicleId`=4852 WHERE `entry`=111858; -- Guardian Rurson
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=4196352, `HoverHeight`=2.5 WHERE `entry`=112303; -- Horrid Eagle
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `HoverHeight`=2.5 WHERE `entry`=112290; -- Horrid Eagle
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113088; -- Corrupted Feeler
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=4194304 WHERE `entry`=100497; -- Ursoc
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=112162; -- Grisly Trapper
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=112153; -- Dire Shaman
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=4196352 WHERE `entry`=112307; -- Cosmetic Nightmare Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_walk`=1.2, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=113575; -- Iris
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048, `HoverHeight`=4.5 WHERE `entry`=111567; -- Nightmare Drake
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=0.5714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=113203; -- Fureur de drake
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=100665344 WHERE `entry`=102930; -- Breath Stalker
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=768, `unit_flags2`=1140852736 WHERE `entry`=113520; -- Ancient Spirit
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `npcflag`=3, `speed_run`=2.142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=1073741824, `unit_flags3`=2 WHERE `entry`=106482; -- Malfurion Hurlorage
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=111535; -- Fog Beast Spawner Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=111354; -- Corrupteur cœur-corrompu
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=111412; -- Satyr Channel Cosmetic Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=111528; -- Deathroot Ancient
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=111333; -- Taintheart Trickster
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=113113; -- Essence of Nightmare
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=111355; -- Taintheart Tormenter
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=4.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `HoverHeight`=18.75 WHERE `entry`=102672; -- Nythendra
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111004; -- Gelatinized Decay
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=102998; -- Corrupted Vermin

SET @GROUP_ID := 0;
SET @ID := 0;

DELETE FROM `creature_text` WHERE `CreatureID` IN (100497, 102672, 102679, 102681, 102682, 105393, 105906, 106087, 106482);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(100497, @GROUP_ID+0, @ID+0, 'You should have fled! Now I''ll feed your bones to the storm crows!', 14, 0, 100, 0, 0, 58379, 0, 'Ursoc to Player'),
(100497, @GROUP_ID+1, @ID+0, '|TInterface\\Icons\\spell_druid_bearhug:20|t%s targets |cFFFF0000$n|r with an intense |cFFFF0000|Hspell:198006|h[Focused Gaze]|h|r!', 41, 0, 100, 0, 0, 58385, 0, 'Ursoc to Player'),
(100497, @GROUP_ID+2, @ID+0, 'I WILL FLATTEN YOU LIKE SAPLINGS!', 14, 0, 100, 0, 0, 58385, 0, 'Ursoc to Player'),
(100497, @GROUP_ID+3, @ID+0, '|TInterface\\Icons\\ability_deathwing_assualtaspects:20|t%s goes into a crazed |cFFFF0000|Hspell:198388|h[Blood Frenzy]|h|r!', 41, 0, 100, 0, 0, 0, 0, 'Ursoc'),
(102672, @GROUP_ID+0, @ID+0, 'You seek the Dream? It seeks you, too.', 14, 0, 100, 0, 0, 58662, 0, 'Nythendra'),
(102672, @GROUP_ID+1, @ID+0, 'Consumed from within!', 14, 0, 100, 0, 0, 58670, 0, 'Nythendra to Player'),
(102672, @GROUP_ID+2, @ID+0, '|TInterface\\Icons\\spell_nature_insect_swarm2:20|t Nythendra inhales for an |cFFFF0404|Hspell:202977|h[Infested Breath]|h|r!', 41, 0, 100, 0, 0, 58667, 0, 'Nythendra to Breath Stalker'),
(102672, @GROUP_ID+3, @ID+0, 'Breathe deeply. Embrace your fate.', 14, 0, 100, 0, 0, 58667, 0, 'Nythendra to Breath Stalker'),
(102672, @GROUP_ID+4, @ID+0, 'I dreamed the Dream. Now I wake...', 14, 0, 100, 0, 0, 58665, 0, 'Nythendra to Player'),
(102679, @GROUP_ID+0, @ID+0, 'The strands of life have been severed! The dreamers must be avenged!', 14, 0, 100, 0, 0, 58510, 0, 'Ysondre to Player'),
(102679, @GROUP_ID+1, @ID+0, 'Come forth, dreamers... and claim your vengeance!', 14, 0, 100, 0, 0, 58500, 0, 'Ysondre to Player'),
(102679, @GROUP_ID+2, @ID+0, 'At last... the long dream comes.', 14, 0, 100, 0, 0, 58499, 0, 'Ysondre to Player'),
(102681, @GROUP_ID+0, @ID+0, 'Peace is but a fleeting dream! Let the Nightmare reign!', 14, 0, 100, 0, 0, 58509, 0, 'Taerar'),
(102682, @GROUP_ID+0, @ID+0, 'I can sense the shadow on your hearts. There can be no rest for the wicked!', 14, 0, 100, 0, 0, 58508, 0, 'Lethon to Player'),
(105393, @GROUP_ID+0, @ID+0, 'Your coming was foretold in the rings. The long circle is nearly complete.', 15, 0, 100, 0, 0, 58910, 0, 'Il''gynoth to Player'),
(105393, @GROUP_ID+1, @ID+0, 'Come, little ones. Savor your fear as we feast upon it!', 15, 0, 100, 0, 0, 58911, 0, 'Il''gynoth to Player'),
(105393, @GROUP_ID+2, @ID+0, 'At last, the feeding hour!', 15, 0, 100, 0, 0, 58912, 0, 'Il''gynoth to Player'),
(105393, @GROUP_ID+3, @ID+0, 'Every blow struck at our heart will be repaid a thousand fold!', 15, 0, 100, 0, 0, 58921, 0, 'Il''gynoth to Player'),
(105393, @GROUP_ID+4, @ID+0, 'Still you fight? Still you refuse the gift?', 15, 0, 100, 0, 0, 58923, 0, 'Il''gynoth to Player'),
(105393, @GROUP_ID+5, @ID+0, 'N''zoth... I journey... to Ny''alotha...', 15, 0, 100, 0, 0, 58924, 0, 'Il''gynoth to Player'),
(105906, @GROUP_ID+0, @ID+0, 'The Eye of Il''gynoth is creating a Nightmare Horror!', 41, 0, 100, 0, 0, 0, 0, 'Eye of Il''gynoth to Nightmare Horror'),
(106087, @GROUP_ID+0, @ID+0, 'Mercy? None for you! Only gushing blood and broken bodies!', 14, 0, 100, 0, 0, 58625, 0, 'Elerethe Renferal'),
(106087, @GROUP_ID+1, @ID+0, 'I''ll adorn my web with your bones!', 14, 0, 100, 0, 0, 58620, 0, 'Elerethe Renferal to Elerethe Renferal'),
(106087, @GROUP_ID+2, @ID+0, '|TInterface\\Icons\\ability_hunter_pet_spider.blp:20|t %s calls for |cFFF00000|Hspell:212364|h[Feeding Time]|h|r.', 41, 0, 100, 0, 0, 58618, 0, 'Elerethe Renferal'),
(106087, @GROUP_ID+3, @ID+0, 'Such juicy morsels!', 14, 0, 100, 0, 0, 58618, 0, 'Elerethe Renferal'),
(106482, @GROUP_ID+0, @ID+0, 'I sense the touch of Cenarius upon this Iris. It is a portal that leads to Moonglade, but the way has been sealed by dark magic. We must sever the tendrils of power that bind it.', 14, 0, 100, 0, 0, 61373, 0, 'Malfurion Stormrage to Player'),
(106482, @GROUP_ID+1, @ID+0, 'From each of these pathways, a palpable evil emanates. Choose a course, and know that I will stand with you.', 14, 0, 100, 0, 0, 61374, 0, 'Malfurion Stormrage to Player');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 111263;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(111263, 222693, 0, 0);

DELETE FROM `creature_template` WHERE `entry`=130907;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(130907, 0, 0, 81472, 81473, 81474, 0, 'Egg', NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 10, 0, 0, 1, 1, 0, 80, 26124); -- Egg

UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105383; -- Corruptor Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105591; -- Nightmare Horror
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105322; -- Deathglare Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105721; -- Nightmare Ichor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105393; -- Il'gynoth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105906; -- Eye of Il'gynoth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105304; -- Dominator Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111860; -- Bo'lan the Marked
UPDATE `creature_template` SET `type_flags`=72, `VerifiedBuild`=26124 WHERE `entry`=113920; -- Flail of Il'gynoth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113040; -- Pterreurdactyle frénétique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112168; -- Tainted Bloodpetal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112143; -- Flagellant pétale-de-sang
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112118; -- Pétale-de-sang corrompu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113041; -- Dimeurtrodon infecté
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=9, `type_flags`=1628439632, `type_flags2`=6, `HealthModifier`=50, `VerifiedBuild`=26124 WHERE `entry`=129063; -- Legion Cruiser
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107969; -- Vile Ambush Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107459; -- Venomous Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109519; -- Web
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111374; -- Xal'atath
UPDATE `creature_template` SET `HealthModifier`=342, `VerifiedBuild`=26124 WHERE `entry`=106087; -- Elerethe Renferal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111978; -- Wretched Ambush Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111980; -- Nightmother
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113626; -- Venomous Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113625; -- Web
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109849; -- Nightmare Spawn Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111439; -- Twisting Shadows
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107767; -- Twisting Shadows
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112078; -- Pulsing Egg Sac
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108540; -- Surging Egg Sac
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111975; -- Shadowfeather
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112039; -- Screeching Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111933; -- Venomous Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106510; -- Flight Loc Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113609; -- Elerethe Renferal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113604; -- Elerethe Renferal
UPDATE `creature_template` SET `type`=8, `VerifiedBuild`=26124 WHERE `entry`=113108; -- Lapin cauchemardesque
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113106; -- Sickly Cougar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113103; -- Corrupted Swoop
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113093; -- Infected Gazelle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113091; -- Tainted Plainstrider
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103080; -- Defiled Druid Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102681; -- Taerar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113214; -- Seeping Fog
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102682; -- Lethon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102679; -- Ysondre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103396; -- Shadowy Rift
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103395; -- Nightmare Rift
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111852; -- Rothos
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103378; -- Diseased Rift
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113092; -- Swarming Dread
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113090; -- Corrupted Gatewarden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113089; -- Defiled Keeper
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112178; -- Dread Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111263; -- Tur Ragepaw
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112474; -- Corrupted Totem
UPDATE `creature_template` SET `HealthModifier`=371.621, `VerifiedBuild`=26124 WHERE `entry`=100497; -- Ursoc
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112307; -- Cosmetic Nightmare Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112303; -- Horrid Eagle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112290; -- Horrid Eagle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112162; -- Grisly Trapper
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112153; -- Dire Shaman
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111856; -- Guardian Gorroc
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111858; -- Guardian Rurson
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113088; -- Corrupted Feeler
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113575; -- Iris
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111567; -- Nightmare Drake
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113203; -- Fureur de drake
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=3527; -- Healing Stream Totem
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=73400; -- Healing Ran Invisible Stalker DND
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111331; -- Lurking Horror
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102930; -- Breath Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26124 WHERE `entry`=67235; -- Shadowfiend
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92870; -- Sindragosa's Fury
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=43499; -- Consecration
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=47649; -- Efflorescence
UPDATE `creature_template` SET `type_flags2`=128, `VerifiedBuild`=26124 WHERE `entry`=26668; -- Svala Sorrowgrave
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113520; -- Ancient Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106482; -- Malfurion Hurlorage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111354; -- Corrupteur cœur-corrompu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111412; -- Satyr Channel Cosmetic Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111535; -- Fog Beast Spawner Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111528; -- Deathroot Ancient
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113113; -- Essence of Nightmare
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111333; -- Taintheart Trickster
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111355; -- Taintheart Tormenter
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111221; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=33030; -- Magnificent Flying Carpet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=65011; -- Albino Riding Crane
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=29929; -- Mechano-Hog
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=77178; -- Dread Raven
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=65078; -- Great Purple Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=62106; -- Great Red Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=40725; -- X-53 Touring Rocket
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=37059; -- Great Sunwalker Kodo
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=36883; -- Sunwalker Kodo
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32640; -- Traveler's Tundra Mammoth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32207; -- Armored Brown Bear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31694; -- Azure Drake Mount
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=26124 WHERE `entry`=29582; -- Winged Steed of the Ebon Blade
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=28302; -- Acherus Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=18379; -- Swift Purple Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=18377; -- Coursier du vent rouge rapide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=18380; -- Swift Yellow Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=20030; -- Thalassian Charger
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=30542; -- Rivendare's Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=20029; -- Thalassian Warhorse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=304; -- Palefroi corrompu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=358; -- Timber Wolf
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=305; -- Etalon blanc
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=51195; -- Kor'kron Annihilator
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=26124 WHERE `entry`=40054; -- Abyssal Seahorse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102672; -- Nythendra
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112798; -- Flagellant cauchemardesque
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112132; -- Jeune chauve-souris de feu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98463; -- Broute
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99403; -- Jeune sabre fantomatique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99394; -- Ondulin fétide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98077; -- Crépin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93143; -- Louveteau de braise
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26124 WHERE `entry`=49588; -- Page de guilde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=94867; -- Requin gauche
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26124 WHERE `entry`=68657; -- Abomination fongique
UPDATE `creature_template` SET `type`=12, `movementId`=100, `VerifiedBuild`=26124 WHERE `entry`=83594; -- Jeune pousse de belladone
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=88225; -- Compagnon de sentinelle
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=37865; -- Groopy
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=84915; -- Corgi du magma
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `VerifiedBuild`=26124 WHERE `entry`=85387; -- Chasseur de fruits
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=84330; -- Jeune foule-prairie
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=85231; -- Broyeur de pierres
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `type`=12, `VerifiedBuild`=26124 WHERE `entry`=88103; -- Fleur de mort
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=86716; -- Spore cramoisie
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=88222; -- Paonneau de la Flore éternelle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=86447; -- Ikky
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=36871; -- Chiot du magma
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=77137; -- Bébé corbeau de l’effroi
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=77221; -- Petite étoile de Fer
UPDATE `creature_template` SET `modelid1`=27718, `type`=12, `VerifiedBuild`=26124 WHERE `entry`=10598; -- Jeune couveuse
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=7565; -- Cobra noir
UPDATE `creature_template` SET `type`=12, `movementId`=100, `VerifiedBuild`=26124 WHERE `entry`=14421; -- Chien de prairie brun
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=29726; -- M. Glagla
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111004; -- Gelatinized Decay
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102998; -- Corrupted Vermin


UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=105393 AND `Idx`=2); -- Il'gynoth
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=105393 AND `Idx`=1); -- Il'gynoth
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=105393 AND `Idx`=0); -- Il'gynoth
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=102672 AND `Idx`=1); -- Nythendra
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=102672 AND `Idx`=0); -- Nythendra

DELETE FROM `gameobject_template` WHERE `entry` IN (251555 /*Eye of Il'gynoth's Forcefield*/, 248850 /*Wall of Roots*/, 248849 /*Wall of Roots*/, 248848 /*NgihtmareRaid_UnGoro_RootWall03*/, 255000 /*Twisting Roots*/, 252043 /*Door*/, 252042 /*Door*/, 254273 /*The Emerald Dreamway*/, 254271 /*Thunder Bluff*/, 254270 /*Un'goro Crater*/, 254272 /*Grizzly Hills*/, 260552 /*Doodad_7DU_Nightmare_RootWall010*/, 260551 /*Doodad_7DU_Nightmare_RootWall009*/, 260550 /*Doodad_7DU_Nightmare_RootWall008*/, 251534 /*Doodad_7DU_Nightmare_RootWall002*/, 251533 /*Doodad_7DU_Nightmare_RootWall001*/, 251535 /*Doodad_7DU_Nightmare_RootWall003*/, 251536 /*Doodad_7DU_Nightmare_RootWall004*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(251555, 0, 6391, 'Eye of Il''gynoth''s Forcefield', '', '', '', 2.37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Eye of Il'gynoth's Forcefield
(248850, 0, 32552, 'Wall of Roots', '', '', '', 1.79, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wall of Roots
(248849, 0, 32552, 'Wall of Roots', '', '', '', 1.74, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wall of Roots
(248848, 0, 32552, 'NgihtmareRaid_UnGoro_RootWall03', '', '', '', 1.13, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- NgihtmareRaid_UnGoro_RootWall03
(255000, 0, 32552, 'Twisting Roots', '', '', '', 3.87, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Twisting Roots
(252043, 0, 32552, 'Door', '', '', '', 3.3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Door
(252042, 0, 32552, 'Door', '', '', '', 4.56, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Door
(254273, 5, 36810, 'The Emerald Dreamway', '', '', '', 4, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- The Emerald Dreamway
(254271, 5, 36808, 'Thunder Bluff', '', '', '', 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Thunder Bluff
(254270, 5, 36807, 'Un''goro Crater', '', '', '', 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Un'goro Crater
(254272, 5, 36809, 'Grizzly Hills', '', '', '', 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grizzly Hills
(260552, 0, 32552, 'Doodad_7DU_Nightmare_RootWall010', '', '', '', 1.75465, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7DU_Nightmare_RootWall010
(260551, 0, 32552, 'Doodad_7DU_Nightmare_RootWall009', '', '', '', 1.75465, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7DU_Nightmare_RootWall009
(260550, 0, 32552, 'Doodad_7DU_Nightmare_RootWall008', '', '', '', 1.75465, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7DU_Nightmare_RootWall008
(251534, 0, 32552, 'Doodad_7DU_Nightmare_RootWall002', '', '', '', 1.819293, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7DU_Nightmare_RootWall002
(251533, 0, 32552, 'Doodad_7DU_Nightmare_RootWall001', '', '', '', 1.819293, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7DU_Nightmare_RootWall001
(251535, 0, 32552, 'Doodad_7DU_Nightmare_RootWall003', '', '', '', 1.819293, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7DU_Nightmare_RootWall003
(251536, 0, 32552, 'Doodad_7DU_Nightmare_RootWall004', '', '', '', 2.030513, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Doodad_7DU_Nightmare_RootWall004

UPDATE `gameobject_template` SET `type`=10, `displayId`=36949, `size`=0.82, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=251997; -- Portal
UPDATE `gameobject_template` SET `type`=10, `displayId`=2973, `Data10`=224938, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=254248; -- Corrupted Power Crystal
UPDATE `gameobject_template` SET `type`=10, `displayId`=2972, `size`=1.1, `Data10`=224939, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=254249; -- Corrupted Power Crystal
UPDATE `gameobject_template` SET `type`=10, `displayId`=2974, `Data10`=224937, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=254247; -- Corrupted Power Crystal
UPDATE `gameobject_template` SET `type`=10, `displayId`=36949, `size`=1.39, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=251995; -- Portal
UPDATE `gameobject_template` SET `type`=10, `displayId`=36949, `size`=1.24, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=252006; -- Portal
UPDATE `gameobject_template` SET `type`=10, `displayId`=36949, `size`=1.11, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=252004; -- Portal
UPDATE `gameobject_template` SET `type`=10, `displayId`=35699, `IconName`='openhand', `size`=1.738989, `Data10`=224881, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=251980; -- Nightmare Iris
UPDATE `gameobject_template` SET `type`=10, `displayId`=33125, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=248925; -- Entrance Vines
UPDATE `gameobject_template` SET `type`=10, `displayId`=33126, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=248926; -- Ungoro Vines
UPDATE `gameobject_template` SET `type`=10, `displayId`=33129, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=248929; -- Dragons Vines
UPDATE `gameobject_template` SET `type`=10, `displayId`=33127, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=248927; -- Thunder Bluff Vines
UPDATE `gameobject_template` SET `type`=10, `displayId`=33128, `Data13`=1, `VerifiedBuild`=26124 WHERE `entry`=248928; -- Grizzly Vines
UPDATE `gameobject_template` SET `name`='Instance Portal', `VerifiedBuild`=26124 WHERE `entry`=253129; -- Instance Portal

