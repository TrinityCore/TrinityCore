ALTER TABLE `quest_template` ADD COLUMN `RequiredClasses` smallint(5) unsigned NOT NULL default '0' AFTER `Type`;

UPDATE `quest_template`
  SET `RequiredClasses` = `RequiredClasses`|
    CASE `SkillOrClassMask`
      WHEN  -1 THEN    1 -- warrior
      WHEN  -2 THEN    2 -- paladin
      WHEN  -3 THEN    4 -- hunter
      WHEN  -4 THEN    8 -- rogue
      WHEN  -5 THEN   16 -- priest
      WHEN  -6 THEN   32 -- dk
      WHEN  -7 THEN   64 -- shaman
      WHEN  -8 THEN  128 -- mage
      WHEN  -9 THEN  256 -- warlock
      WHEN -11 THEN 1024 -- druid
      ELSE 0
    END
  WHERE `SkillOrClassMask` < 0;

UPDATE `quest_template`
  SET `RequiredClasses` = `RequiredClasses`|
    CASE `ZoneOrSort`
      WHEN  -81 THEN    1 -- warrior
      WHEN -141 THEN    2 -- paladin
      WHEN -261 THEN    4 -- hunter
      WHEN -162 THEN    8 -- rogue
      WHEN -262 THEN   16 -- priest
      WHEN -372 THEN   32 -- dk
      WHEN  -82 THEN   64 -- shaman
      WHEN -161 THEN  128 -- mage
      WHEN  -61 THEN  256 -- warlock
      WHEN -263 THEN 1024 -- druid
      ELSE 0
    END
  WHERE `ZoneOrSort` < 0;

UPDATE `quest_template` SET `SkillOrClassMask`=0 WHERE `SkillOrClassMask`<0;
ALTER TABLE `quest_template` CHANGE COLUMN `SkillOrClassMask` `RequiredSkill` smallint(5) unsigned NOT NULL default '0' AFTER `RequiredRaces`;
