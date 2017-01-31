DELETE FROM `playercreateinfo_skills` WHERE `skill` IN (795,796,798,800,804,829,840,849,904,921,924);
INSERT INTO `playercreateinfo_skills` (`raceMask`,`classMask`,`skill`,`rank`,`comment`) VALUES
(0, 4, 795, 0, "Hunter skills."),
(0, 32, 796, 0, "Death Knight skills."),
(0, 1024, 798, 0, "Druid skills."),
(0, 2, 800, 0, "Paladin skills."),
(0, 16, 804, 0, "Priest skills."),
(0, 512, 829, 0, "Monk skills."),
(0, 1, 840, 0, "Warrior skills."),
(0, 256, 849, 0, "Warlock skills."),
(0, 128, 904, 0, "Mage skills."),
(0, 8, 921, 0, "Rogue skills."),
(0, 64, 924, 0, "Shaman skills.");

DELETE FROM `spell_ranks` WHERE `first_spell_id`=127650;
INSERT INTO `spell_ranks` (`first_spell_id`,`spell_id`,`rank`) VALUES
(127650,127650,1), -- Remove Talent: Vanishing Powder
(127650,127649,2), -- Remove Talent: Dust of Disappearance
(127650,113873,3); -- Remove Talent: Tome of the Clear Mind
