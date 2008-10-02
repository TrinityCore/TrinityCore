ALTER TABLE `quest_template` 
  ADD `RepObjectiveFaction` int(10) unsigned NOT NULL default '0' AFTER `RequiredSkillValue`,
  ADD `RepObjectiveValue`   int(10)          NOT NULL default '0' AFTER `RepObjectiveFaction`;