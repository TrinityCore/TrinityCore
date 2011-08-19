/*ALTER TABLE db_version CHANGE COLUMN required_7720_01_mangos_mangos_string required_7776_01_mangos_npc_spellclick_spells bit;*/

CREATE TABLE `npc_spellclick_spells` (
    `npc_entry` INT UNSIGNED NOT NULL COMMENT 'reference to creature_template',
    `spell_id` INT UNSIGNED NOT NULL COMMENT 'spell which should be casted ',
    `quest_id` INT UNSIGNED NOT NULL COMMENT 'reference to quest_template',
    `cast_flags` TINYINT UNSIGNED NOT NULL COMMENT 'first bit defines caster: 1=player, 0=creature; second bit defines target, same mapping as caster bit'
) ENGINE = MYISAM DEFAULT CHARSET=utf8;
