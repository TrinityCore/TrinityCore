ALTER TABLE `quest_template` 
    CHANGE `RequiredTradeskill` `RequiredSkill` int(11) unsigned NOT NULL default '0',
    ADD COLUMN `RequiredSkillValue` int(11) unsigned NOT NULL default '1' AFTER `RequiredSkill`;
