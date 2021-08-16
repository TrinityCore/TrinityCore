RENAME TABLE `areatrigger_template_polygon_vertices` TO `spell_areatrigger_vertices`;

ALTER TABLE `spell_areatrigger_vertices` ADD COLUMN `SpellMiscId` INT(10) NULL FIRST;

UPDATE `spell_areatrigger_vertices`
LEFT JOIN `spell_areatrigger` ON `spell_areatrigger_vertices`.AreaTriggerId = `spell_areatrigger`.AreaTriggerId
SET `spell_areatrigger_vertices`.SpellMiscId = `spell_areatrigger`.SpellMiscId;

DELETE FROM `spell_areatrigger_vertices` WHERE SpellMiscId IS NULL;

ALTER TABLE `spell_areatrigger_vertices` DROP COLUMN `SpellMiscId`,
                                         CHANGE `AreaTriggerId` `SpellMiscId` INT(10) UNSIGNED NOT NULL,
                                         DROP PRIMARY KEY,
                                         ADD PRIMARY KEY (`SpellMiscId` , `Idx`);
