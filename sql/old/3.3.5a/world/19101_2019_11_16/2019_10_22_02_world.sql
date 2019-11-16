-- 
UPDATE `creature_addon` SET `auras`="54500" WHERE `guid` IN (104811);
DELETE FROM `spell_area` WHERE `spell`=56582 AND `area`=4432;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(56582, 4432, 0, 12973, 0, 0, 2, 1, 0, 11);
UPDATE `spell_area` SET `quest_end`=12973, `quest_end_status`=11 WHERE `spell`=55782 AND `area`=4432;
