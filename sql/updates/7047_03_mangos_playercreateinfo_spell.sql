ALTER TABLE db_version CHANGE COLUMN required_7047_02_mangos_playercreateinfo_action required_7047_03_mangos_playercreateinfo_spell bit;

DELETE FROM `playercreateinfo_spell` WHERE `Spell` IN ('28880', 59542, 59543, 59544, 59545, 59547, 59548);

INSERT INTO `playercreateinfo_spell` VALUES
(11,1,28880,'Gift of the Naaru',1),
(11,2,59542,'Gift of the Naaru',1),
(11,3,59543,'Gift of the Naaru',1),
(11,5,59544,'Gift of the Naaru',1),
(11,6,59545,'Gift of the Naaru',1),
(11,7,59547,'Gift of the Naaru',1),
(11,8,59548,'Gift of the Naaru',1);