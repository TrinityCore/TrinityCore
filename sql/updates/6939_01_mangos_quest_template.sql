ALTER TABLE db_version CHANGE COLUMN required_6936_01_mangos_spell_chain required_6939_01_mangos_quest_template bit;

ALTER TABLE `quest_template`
    CHANGE `RewHonorableKills` `RewHonorableKills` int unsigned NOT NULL default '0';
