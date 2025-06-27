DELETE FROM `creature_queststarter` WHERE `quest`IN(8143,8144);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(14905, 8143),
(14905, 8144);

DELETE FROM `creature_questender` WHERE `quest`IN(8143,8144);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(14905, 8143),
(14905, 8144);

UPDATE `quest_template` SET `AllowableRaces`=0 WHERE  `ID`=8144;
