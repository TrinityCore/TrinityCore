-- Dragonmaw Fel Orc illusion for Netherwing Mines area after Netherwing quest chain for reputation is complete
DELETE FROM `spell_area` WHERE `spell`=40214 AND `area`=3965;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`) VALUES
(40214,3965,11013,1,0,0,0,2,1);
