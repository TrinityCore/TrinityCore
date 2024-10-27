ALTER TABLE `achievement`   
	CHANGE `UiOrder` `UiOrder` SMALLINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `achievement_category`   
	CHANGE `UiOrder` `UiOrder` TINYINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `area_trigger`   
	CHANGE `ContinentID` `ContinentID` SMALLINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `chr_customization_choice`   
	CHANGE `ChrCustomizationOptionID` `ChrCustomizationOptionID` INT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `chr_model`   
	CHANGE `DisplayID` `DisplayID` INT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `chr_race_x_chr_model`   
	CHANGE `ChrRacesID` `ChrRacesID` INT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `dungeon_encounter`   
	CHANGE `MapID` `MapID` SMALLINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `item_currency_cost`   
	CHANGE `ItemID` `ItemID` INT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `item_modified_appearance`   
	CHANGE `ItemID` `ItemID` INT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `journal_encounter_section`   
	CHANGE `Type` `Type` TINYINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `skill_line_ability`   
	CHANGE `SkillLine` `SkillLine` SMALLINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `skill_race_class_info`   
	CHANGE `SkillID` `SkillID` SMALLINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `ui_map`   
	CHANGE `ParentUiMapID` `ParentUiMapID` INT UNSIGNED DEFAULT 0 NOT NULL,
	CHANGE `System` `System` TINYINT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `ui_map_assignment`   
	CHANGE `UiMapID` `UiMapID` INT UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `ui_map_link`   
	CHANGE `ParentUiMapID` `ParentUiMapID` INT UNSIGNED DEFAULT 0 NOT NULL;
