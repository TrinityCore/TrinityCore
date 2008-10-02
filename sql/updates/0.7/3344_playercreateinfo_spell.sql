INSERT INTO `playercreateinfo_spell` VALUES ('1','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('2','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('3','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('4','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('5','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('6','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('7','1','21156','Battle Stance Passive',0);
INSERT INTO `playercreateinfo_spell` VALUES ('8','1','21156','Battle Stance Passive',0);

INSERT IGNORE INTO `character_spell`
SELECT `character`.`guid`,`playercreateinfo_spell`.`spell` AS `spell`, '65535' AS `slot`,`playercreateinfo_spell`.`Active` AS `active`
FROM `character`,`playercreateinfo_spell` 
WHERE `character`.`class`=`playercreateinfo_spell`.`class` AND `character`.`race`=`playercreateinfo_spell`.`race`;