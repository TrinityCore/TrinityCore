DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12822,12996,12972,12989,12758,12955,13049,13060,13102,13133,13134,13135);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(12822,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (10 player)
(12822,12,0,0, ''), -- All You Can Eat (10 player)
(12996,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (10 player) Heroic
(12996,12,2,0, ''), -- All You Can Eat (10 player) Heroic
(12972,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (25 player)
(12972,12,1,0, ''), -- All You Can Eat (25 player)
(12989,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (25 player) Heroic
(12989,12,3,0, ''), -- All You Can Eat (25 player) Heroic
(12758,12,0,0, ''), -- The Frostwing Halls (10 player) Sindragosa
(12955,12,1,0, ''), -- The Frostwing Halls (25 player) Sindragosa
(13049,12,2,0, ''), -- Heroic: The Frostwing Halls (10 player) Sindragosa
(13060,12,3,0, ''), -- Heroic: The Frostwing Halls (25 player) Sindragosa
(13102,12,0,0, ''), -- Sindragosa kills (Icecrown 10 player)
(13133,12,1,0, ''), -- Sindragosa kills (Icecrown 25 player)
(13134,12,2,0, ''), -- Sindragosa kills (Heroic Icecrown 10 player)
(13135,12,3,0, ''); -- Sindragosa kills (Heroic Icecrown 25 player)
