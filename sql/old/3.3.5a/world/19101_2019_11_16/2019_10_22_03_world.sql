-- 
UPDATE `creature_addon` SET `auras`="60921" WHERE `guid` IN (104811);
DELETE FROM `spell_area` WHERE `spell`=56582 AND `area`=4432;
DELETE FROM `spell_area` WHERE `spell`=60922 AND `area` IN (4432,4431);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(60922, 4432, 0, 12973, 0, 0, 2, 1, 0, 11),
(60922, 4431, 0, 12973, 0, 0, 2, 1, 0, 11);
