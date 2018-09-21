-- Add quest invisibility spells for See Quest Invis 3
DELETE FROM `spell_area` WHERE `spell` IN (73205);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(73205,4865,24622,25035,0,128,2,1,64,11),(73205,4866,24622,25035,0,128,2,1,64,11),(73205,4875,24622,25035,0,128,2,1,64,11);

-- Add quest invisibility spells for See Quest Invis 4
DELETE FROM `spell_area` WHERE `spell` IN (73206);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(73206,4865,0,0,-73205,128,2,1,0,0),(73206,4866,0,0,-73205,128,2,1,0,0),(73206,4875,0,0,-73205,128,2,1,0,0);
