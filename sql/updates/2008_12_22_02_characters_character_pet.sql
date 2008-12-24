ALTER TABLE character_db_version CHANGE COLUMN required_2008_12_15_01_character_arenas required_2008_12_22_02_characters_character_pet bit;

alter table `character_pet`
    drop column `trainpoint`,
    drop column `loyaltypoints`,
    drop column `loyalty`,
    add `talentpoints` int(11) UNSIGNED default '0' NOT NULL after `Reactstate`;
