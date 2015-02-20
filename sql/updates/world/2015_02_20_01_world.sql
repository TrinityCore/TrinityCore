-- Golden Lotus
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN
(72275, 58411, 65170, 72280, 63447, 63674, 59378, 63044, 58928, 65132, 63610, 58927, 65134, 65131, 65133, 63611, 63641, 58455, 63605, 58456);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `RewOnKillRepValue1`, `MaxStanding2`, `RewOnKillRepValue2`) VALUES
(72275, 1269, 0, 7, 20, 0, 0),     -- Black Bengal Goat + 20 reputation with Golden Lotus
(58411, 1269, 0, 6, 20, 0, 0),     -- Docile Porcupine + 20 reputation with Golden Lotus (stops at Revered)
(65170, 1269, 1359, 7, 20, 5, 10), -- Jade Warrior + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(72280, 1269, 0, 7, 20, 0, 0),     -- Manifestation of Pride + 20 reputation with Golden Lotus
(63447, 1269, 1359, 7, 20, 5, 10), -- Mogu Statue + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(63674, 1269, 1359, 7, 20, 5, 10), -- Mogu Statue + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(59378, 1269, 0, 7, 20, 0, 0),     -- Paleblade Flesheater + 20 reputation with Golden Lotus
(63044, 1269, 0, 6, 20, 0, 0),     -- Paleblade Slithertongue + 20 reputation with Golden Lotus (stops at Revered)
(58928, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Antiquator + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(65132, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Conqueror + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(63610, 1269, 1359, 7, 20, 6, 10), -- Shao-Tien Dominator + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Revered)
(58927, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Fist + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(65134, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Fist + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(65131, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Painweaver + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(65133, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Sorcerer + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(63611, 1269, 1359, 7, 20, 5, 10), -- Shao-Tien Soul-Caller + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(63641, 1269, 0, 7, 20, 0, 0),     -- Shao-Tien Torturer + 20 reputation with Golden Lotus
(58455, 1269, 0, 7, 20, 0, 0),     -- Stillwater Crocolisk + 20 reputation with Golden Lotus
(63605, 1269, 1359, 7, 20, 5, 10), -- Stonebound Watcher + 20 reputation with Golden Lotus, + 10 reputation with The Black Prince (stops at Honored)
(58456, 1269, 0, 7, 20, 0, 0);     -- Thundermaw + 20 reputation with Golden Lotus
