ALTER TABLE `quest_template` CHANGE COLUMN `SkillOrClass` `SkillOrClassMask` mediumint(8) NOT NULL DEFAULT '0';
UPDATE `quest_template` SET `SkillOrClassMask`=-(1<<(-`SkillOrClassMask`-1)) WHERE `SkillOrClassMask`<0;
