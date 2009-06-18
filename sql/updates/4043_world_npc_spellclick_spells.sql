ALTER TABLE npc_spellclick_spells
  DROP COLUMN quest_status,
  CHANGE COLUMN quest_id quest_start mediumint(8) unsigned NOT NULL COMMENT 'reference to quest_template',
  ADD COLUMN    quest_start_active   tinyint(1) unsigned NOT NULL default '0' AFTER quest_start,
  ADD COLUMN    quest_end            mediumint(8) unsigned NOT NULL default '0' AFTER quest_start_active;

/* compatibility with old data */
UPDATE npc_spellclick_spells
  SET quest_end = quest_start, quest_start_active = 1
  WHERE quest_start <> 0;

DELETE FROM `npc_spellclick_spells` WHERE `spell_id` IN (
54568, 54575, 52263, 52280, 52447);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`) VALUES
(29488, 54568, 12670, 1, 0, 3), -- Taxi to Death's Breath
(29501, 54575, 12670, 1, 0, 3),
(28605, 52263, 12680, 1, 12680, 1), -- Stolen Horse
(28606, 52263, 12680, 1, 12680, 1),
(28607, 52263, 12680, 1, 12680, 1),
(28782, 52280, 12687, 1, 12687, 1), -- Unbound Charger
(28833, 52447, 12701, 1, 12701, 1), -- Scarlet Cannon Master
(28887, 52447, 12701, 1, 12701, 1);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (29912);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`) VALUES
(29912, 55479, 0, 0, 0, 3); # Obedience Crystal - Force Obedience

REPLACE into `spell_target_position` values (51852, 609, 2361.21, -5660.45, 503.828, 4.49);
