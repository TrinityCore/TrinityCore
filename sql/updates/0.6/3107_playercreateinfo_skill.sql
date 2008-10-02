ALTER TABLE `playercreateinfo_skill` 
  MODIFY COLUMN `SkillMin` smallint(5) NOT NULL default '0',
  MODIFY COLUMN `SkillMax` smallint(5) NOT NULL default '0';

UPDATE `playercreateinfo_skill` SET `SkillMin` = '-1' WHERE `SkillMin` = 300;
UPDATE `playercreateinfo_skill` SET `SkillMax` = '-1' WHERE `SkillMax` = 300;
