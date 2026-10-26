ALTER TABLE `areatrigger_create_properties` 
  ADD COLUMN `MaxSummons` int NULL COMMENT 'Maximum number of areatriggers that can be summoned with these properties' AFTER `SpellForVisuals`,
  ADD COLUMN `MaxUnits` int NULL COMMENT 'Maximum number of units that can be inside it' AFTER `MaxSummons`;

UPDATE `areatrigger_create_properties` SET `MaxSummons`=3 WHERE `Id`=337 AND `IsCustom`=0; -- Angelic Feather
UPDATE `areatrigger_create_properties` SET `MaxSummons`=1 WHERE `Id`=1524 AND `IsCustom`=0; -- Binding Shot
UPDATE `areatrigger_create_properties` SET `MaxSummons`=1 WHERE `Id`=4424 AND `IsCustom`=0; -- Freezing Trap
UPDATE `areatrigger_create_properties` SET `MaxSummons`=1 WHERE `Id`=4435 AND `IsCustom`=0; -- Tar Trap
UPDATE `areatrigger_create_properties` SET `MaxSummons`=1 WHERE `Id`=9810 AND `IsCustom`=0; -- High Explosive Trap
UPDATE `areatrigger_create_properties` SET `MaxSummons`=1 WHERE `Id`=34378 AND `IsCustom`=0; -- Implosive Trap
