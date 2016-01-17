DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (14173,14175,14176,14177,14178,14179,14180,14181,14182,14183);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(14173,21,7,0,''),  -- Realm First! Level 85 Shaman
(14175,21,11,0,''), -- Realm First! Level 85 Druid
(14176,21,2,0,''),  -- Realm First! Level 85 Paladin
(14177,21,5,0,''),  -- Realm First! Level 85 Priest
(14178,21,9,0,''),  -- Realm First! Level 85 Warlock
(14179,21,3,0,''),  -- Realm First! Level 85 Hunter
(14180,21,6,0,''),  -- Realm First! Level 85 Death Knight
(14181,21,8,0,''),  -- Realm First! Level 85 Mage
(14182,21,1,0,''),  -- Realm First! Level 85 Warrior
(14183,21,4,0,'');  -- Realm First! Level 85 Rogue

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (5223,5224,5227,10279,10698,12818,12350);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(5223,12,1,0,''),  -- Realm First! Magic Seeker
(5224,12,1,0,''),  -- Realm First! Obsidian Slayer
(5227,12,1,0,''),  -- Realm First! Conqueror of Naxxramas
(10279,12,1,0,''), -- Realm First! Death's Demise
(10279,18,0,0,''),
(10698,12,1,0,''), -- Realm First! Celestial Defender
(12350,12,3,0,''), -- Realm First! Grand Crusader
(12350,18,0,0,''),
(12818,12,3,0,''); -- Realm First! Fall of the Lich King
