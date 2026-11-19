-- Quest 'Ruthless Cunning' exploit fix
-- Spell Place Kil'sorrow Banner can not only be cast on Warmaul Ogres
DELETE FROM `conditions` WHERE `SourceEntry` IN (32307) AND `ConditionValue2` IN (17148,17147,17146,18391);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,32307,0,18,1,17148,0,0,'',"Spell Place Kil'sorrow Banner can not only be cast on Kil'sorrow mobs"), -- Kil'sorrow Deathsworn
(13,0,32307,1,18,1,17147,0,0,'',"Spell Place Kil'sorrow Banner can not only be cast on Kil'sorrow mobs"), -- Kil'sorrow Cultist
(13,0,32307,2,18,1,17146,0,0,'',"Spell Place Kil'sorrow Banner can not only be cast on Kil'sorrow mobs"), -- Kil'sorrow Spellbinder
(13,0,32307,3,18,1,18391,0,0,'',"Spell Place Kil'sorrow Banner can not only be cast on Kil'sorrow mobs"); -- Giselda the Crone
