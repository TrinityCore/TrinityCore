DROP TABLE IF EXISTS `battle_pet_ability`;
CREATE TABLE `battle_pet_ability`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `Name` TEXT, `Description` TEXT,
    `IconFileDataID` INT(10) NOT NULL,
    `BattlePetVisualID` SMALLINT(5) UNSIGNED NOT NULL,
    `PetTypeEnum` TINYINT(3) NOT NULL,
    `Flags` TINYINT(3) UNSIGNED NOT NULL,
    `Cooldown` INT(10) UNSIGNED NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `battle_pet_ability_locale`;
CREATE TABLE `battle_pet_ability_locale`(
    `ID` INT(10) NOT NULL,
    `locale` VARCHAR(4) NOT NULL,
    `Name_lang` TEXT,
    `Description_lang` TEXT,
    PRIMARY KEY (`ID`)
); 

DROP TABLE IF EXISTS `battle_pet_ability_effect`;
CREATE TABLE `battle_pet_ability_effect`(
    `BattlePetAbilityTurnID` SMALLINT(5) UNSIGNED NOT NULL,
    `BattlePetVisualID` SMALLINT(5) UNSIGNED NOT NULL,
    `AuraBattlePetAbilityID` SMALLINT(5) UNSIGNED NOT NULL,
    `BattlePetEffectPropertiesID` SMALLINT(5) UNSIGNED NOT NULL,
    `Param1` SMALLINT(5) NOT NULL,
    `Param2` SMALLINT(5) NOT NULL,
    `Param3` SMALLINT(5) NOT NULL,
    `Param4` SMALLINT(5) NOT NULL,
    `Param5` SMALLINT(5) NOT NULL,
    `Param6` SMALLINT(5) NOT NULL,
    `OrderIndex` TINYINT(3) UNSIGNED NOT NULL,
    `ID` INT(10) UNSIGNED NOT NULL, PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `battle_pet_ability_state`;
CREATE TABLE `battle_pet_ability_state`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `Value` INT(10) NOT NULL,
    `BattlePetStateID` TINYINT(3) UNSIGNED NOT NULL,
    `BattlePetAbilityID` SMALLINT(5) UNSIGNED NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `battle_pet_ability_turn`;
CREATE TABLE `battle_pet_ability_turn`(
    `BattlePetAbilityID` SMALLINT(5) UNSIGNED NOT NULL,
    `BattlePetVisualID` SMALLINT(5) UNSIGNED NOT NULL,
    `OrderIndex` TINYINT(3) UNSIGNED NOT NULL,
    `TurnTypeEnum` TINYINT(3) UNSIGNED NOT NULL,
    `EventTypeEnum` TINYINT(3) NOT NULL,
    `ID` INT(10) UNSIGNED NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `battle_pet_species_x_abitily`;
CREATE TABLE `battle_pet_species_x_abitily`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `BattlePetAbilityID` SMALLINT(5) UNSIGNED NOT NULL,
    `RequiredLevel` TINYINT(3) UNSIGNED NOT NULL,
    `SlotEnum` TINYINT(3) NOT NULL,
    `BattlePetSpeciesID` SMALLINT(5) UNSIGNED NOT NULL,
    PRIMARY KEY (`ID`)
); 
