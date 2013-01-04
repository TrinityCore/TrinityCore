-- add aura to be able to hand in quests
DELETE FROM `spell_area` WHERE `spell`=52217;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(52217,4306,12574,1,0,0,0,2,1);
