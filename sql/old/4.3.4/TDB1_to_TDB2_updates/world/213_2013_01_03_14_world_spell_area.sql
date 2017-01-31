-- add aura to be able to hand in quests
DELETE FROM `spell_area` WHERE `spell`=52217;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(52217,4306,12574,0,0,0,2,1,1,64);
