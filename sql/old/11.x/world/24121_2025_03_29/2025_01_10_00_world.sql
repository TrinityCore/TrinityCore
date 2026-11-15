ALTER TABLE `areatrigger_create_properties`
  DROP `TimeToTarget`,
  ADD `Speed` float NOT NULL DEFAULT 1 AFTER `TimeToTargetScale`;

UPDATE `areatrigger_create_properties` SET `Speed`=40 WHERE `Id`=1315 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=40 WHERE `Id`=1316 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=20 WHERE `Id`=1612 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=26 WHERE `Id`=2148 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=6.5 WHERE `Id`=5838 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=7 WHERE `Id`=6887 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=15 WHERE `Id`=8661 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=5 WHERE `Id`=13339 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=7 WHERE `Id`=13734 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=18 WHERE `Id`=24322 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=14 WHERE `Id`=24599 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=15 WHERE `Id`=24740 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `Speed`=18 WHERE `Id`=24741 AND `IsCustom`=0;
