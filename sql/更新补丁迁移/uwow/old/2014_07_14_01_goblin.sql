
DELETE FROM spell_area WHERE spell in(68258, 68256) AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68258', '4720', '14001', '0', '0', '0', '2', '1', '10', '0'),
('68256', '4720', '14001', '0', '0', '0', '2', '1', '10', '0');

UPDATE `quest_template` SET `PrevQuestId` = '14239' WHERE `Id` = 14001;
UPDATE `quest_template` SET `NextQuestId` = '14001' WHERE `Id` = 14239;

DELETE FROM creature_involvedrelation WHERE quest in (14474, 14001);
DELETE FROM creature_questrelation WHERE quest in (14474, 14001);

INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES
(35650, 14001);
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES
(36600, 14001);
