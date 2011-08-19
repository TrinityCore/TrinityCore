-- Add Spectral Gyphron to Wintergrasp
DELETE FROM `spell_area` WHERE `spell`=55164 AND `area`=4197;
INSERT INTO `spell_area` 
(`spell`,`area`,`quest_start`,`quest_start_active`,`aura_spell`,`racemask`,`gender`,`autocast`) 
VALUES
(55164,4197,0,0,8326,65527,2,1);
