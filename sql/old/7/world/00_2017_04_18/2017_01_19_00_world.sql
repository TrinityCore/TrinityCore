DELETE FROM `npc_trainer` WHERE `ID` = 202001 OR `SpellID` = -202001;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
-- Fishing trainers
(1651,   -202001, 0, 0, 0, 0), -- Lee Brown
(1680,   -202001, 0, 0, 0, 0), -- Matthew Hooper
(1683,   -202001, 0, 0, 0, 0), -- Warg Deepwater
(1700,   -202001, 0, 0, 0, 0), -- Paxton Ganter
(2367,   -202001, 0, 0, 0, 0), -- Donald Rabonne
(2834,   -202001, 0, 0, 0, 0), -- Myizz Luckycatch
(3028,   -202001, 0, 0, 0, 0), -- Kah Mistrunner
(3179,   -202001, 0, 0, 0, 0), -- Harold Riggs
(3332,   -202001, 0, 0, 0, 0), -- Lumak
(3607,   -202001, 0, 0, 0, 0), -- Androl Oakhand
(4156,   -202001, 0, 0, 0, 0), -- Astaia
(4573,   -202001, 0, 0, 0, 0), -- Armand Cromwell
(5161,   -202001, 0, 0, 0, 0), -- Grimnur Stonebrand
(5493,   -202001, 0, 0, 0, 0), -- Arnold Leland
(5690,   -202001, 0, 0, 0, 0), -- Clyde Kellen
(5938,   -202001, 0, 0, 0, 0), -- Uthan Stillwater
(5941,   -202001, 0, 0, 0, 0), -- Lau'Tiki
(7946,   -202001, 0, 0, 0, 0), -- Brannock
(12032,  -202001, 0, 0, 0, 0), -- Lui'Mala
(12961,  -202001, 0, 0, 0, 0), -- Kil'Hiwana
(14740,  -202001, 0, 0, 0, 0), -- Katoom the Angler
(16774,  -202001, 0, 0, 0, 0), -- Erett
(16780,  -202001, 0, 0, 0, 0), -- Drathen
(17101,  -202001, 0, 0, 0, 0), -- Diktynna
(18018,  -202001, 0, 0, 0, 0), -- Zurjaya
(18911,  -202001, 0, 0, 0, 0), -- Juno Dufrain
(23896,  -202001, 0, 0, 0, 0), -- "Dirty" Michael Crowe
(26909,  -202001, 0, 0, 0, 0), -- Byron Welwick
(26957,  -202001, 0, 0, 0, 0), -- Angelina Soren
(26993,  -202001, 0, 0, 0, 0), -- Old Man Robert
(28742,  -202001, 0, 0, 0, 0), -- Marcia Chase
(32474,  -202001, 0, 0, 0, 0), -- Fishy Ser'ji
(33623,  -202001, 0, 0, 0, 0), -- Fishing
(44975,  -202001, 0, 0, 0, 0), -- Old Umbehto
(50570,  -202001, 0, 0, 0, 0), -- Whilsey Bottomtooth
(56068,  -202001, 0, 0, 0, 0), -- Steven Stagnaro
(70398,  -202001, 0, 0, 0, 0), -- Ben of the Booming Voice
(77733,  -202001, 0, 0, 0, 0), -- Ron Ashton
(79892,  -202001, 0, 0, 0, 0), -- Mak'jin
(85825,  -202001, 0, 0, 0, 0), -- Nuraa
(85926,  -202001, 0, 0, 0, 0), -- Austin Windmill
(86628,  -202001, 0, 0, 0, 0), -- Brix Rocketcast
(94311,  -202001, 0, 0, 0, 0), -- Lester Scaleworth
(95844,  -202001, 0, 0, 0, 0), -- Marcia Chase
(96097,  -202001, 0, 0, 0, 0), -- Sverre
(108825, -202001, 0, 0, 0, 0), -- Conjurer Margoss
-- Fishing spells
(202001,   7733,    100,   0,   0,  5), -- Apprentice Fishing
(202001,   7734,    500, 356,  50, 10), -- Journeyman Fishing
(202001,  18249,  25000, 356, 200, 10), -- Artisan Fishing
(202001,  54083,  10000, 356, 125, 10), -- Expert Fishing
(202001,  54084, 100000, 356, 275, 10), -- Master Fishing
(202001,  51293, 150000, 356, 350, 10), -- Grand Master Fishing
(202001,  88869, 250000, 356, 425, 10), -- Illustrious Grand Master Fishing
(202001, 110412, 300000, 356, 500, 10); -- Zen Master Fishing
