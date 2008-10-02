ALTER TABLE `areatrigger_template`
 DROP COLUMN `trigger_map`,
 DROP COLUMN `trigger_position_x`,
 DROP COLUMN `trigger_position_y`,
 DROP COLUMN `trigger_position_z`;


DELETE FROM `areatrigger_template`
 WHERE `required_level` = 0 AND `required_item` = 0 
   AND `target_map` = 0 AND `target_position_x` = 0 AND `target_position_y` = 0 AND `target_position_z` = 0 AND `target_orientation` = 0;

ALTER TABLE `areatrigger_template` RENAME TO `areatrigger_teleport`;
