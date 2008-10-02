ALTER TABLE `quest_template` 
    CHANGE `RequiredSkillValue` `RequiredSkillValue` int(11) unsigned NOT NULL default '0';

UPDATE `quest_template` 
    SET `RequiredSkillValue` = 0 WHERE `RequiredSkillValue` = 1 AND `ZoneOrSort` >= 0;