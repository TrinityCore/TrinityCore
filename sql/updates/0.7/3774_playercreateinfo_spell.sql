INSERT INTO `playercreateinfo_spell` VALUES ('4','11','33948','Flight Form (Passive)',0);
INSERT INTO `playercreateinfo_spell` VALUES ('6','11','33948','Flight Form (Passive)',0);

INSERT IGNORE INTO `character_spell`
SELECT `character`.`guid`,`playercreateinfo_spell`.`spell` AS `spell`, '65535' AS `slot`,`playercreateinfo_spell`.`Active` AS `active`
FROM `character`,`playercreateinfo_spell` 
WHERE `character`.`class`=`playercreateinfo_spell`.`class` AND `character`.`race`=`playercreateinfo_spell`.`race`;