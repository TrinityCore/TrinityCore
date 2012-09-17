-- Cast Armistice in front of the pavillions as well
DELETE FROM `spell_area` WHERE `spell`=64373 AND `area` IN (4676, 4677);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(64373,4676,0,0,0,0,0,2,1), -- Sunreaver Pavillion
(64373,4677,0,0,0,0,0,2,1); -- SIlver Covenant Pavillion
