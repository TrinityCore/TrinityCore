-- Debug spell, set reqSkillValue because it does not belong to any skilline
UPDATE `skill_discovery_template` SET `reqSkillValue`=0 WHERE `reqSpell`=61756;
