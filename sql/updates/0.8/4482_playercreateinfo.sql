UPDATE playercreateinfo_spell SET Spell = '21084' WHERE Spell = '20154';
UPDATE playercreateinfo_action SET action = '21084' WHERE action = '20154';
DELETE FROM `character_spell` WHERE spell='20154';

-- re-add all default spells if not have with from spell list
INSERT IGNORE INTO `character_spell`
SELECT `character`.`guid`,`playercreateinfo_spell`.`spell` AS `spell`, '65535' AS `slot`,`playercreateinfo_spell`.`Active` AS `active`
FROM `character`,`playercreateinfo_spell` 
WHERE `character`.`class`=`playercreateinfo_spell`.`class` AND `character`.`race`=`playercreateinfo_spell`.`race`;

UPDATE character_action SET action = '21084' WHERE action = '20154' AND `type` = 0;
