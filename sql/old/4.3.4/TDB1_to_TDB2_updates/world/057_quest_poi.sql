DELETE FROM `quest_poi` WHERE `questid` IN (28753, 29172, 29513, 30100, 30104, 8789, 8790, 29387);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(8789, 2, 4, 1, 261, 0, 0, 7), -- Imperial Qiraji Armaments
(8790, 2, 4, 1, 261, 0, 0, 7), -- Imperial Qiraji Regalia
(28753, 0, 1, 644, 759, 3, 0, 7), -- Doing it the Hard Way
(28753, 1, 3, 644, 759, 3, 0, 7), -- Doing it the Hard Way
(28753, 2, 2, 644, 759, 3, 0, 7), -- Doing it the Hard Way
(28753, 3, 0, 644, 759, 3, 0, 7), -- Doing it the Hard Way
(28753, 4, -1, 644, 759, 3, 0, 7), -- Doing it the Hard Way
(29172, 0, 0, 859, 793, 0, 0, 1), -- The Beasts Within
(29172, 1, 1, 859, 793, 0, 0, 1), -- The Beasts Within
(29172, 2, 2, 859, 793, 0, 0, 1), -- The Beasts Within
(29172, 3, -1, 859, 793, 0, 0, 1), -- The Beasts Within
(29513, 0, -1, 974, 823, 0, 0, 3), -- Spoilin' for Salty Sea Dogs
(29513, 1, 4, 974, 823, 0, 0, 7), -- Spoilin' for Salty Sea Dogs
(30100, 0, 0, 939, 816, 0, 0, 1), -- The Vainglorious
(30100, 2, -1, 939, 816, 0, 0, 1), -- The Vainglorious
(30104, 3, 1, 939, 816, 0, 0, 1), -- Documenting the Timeways
(30104, 4, 1, 939, 816, 0, 0, 1), -- Documenting the Timeways
(30104, 5, 2, 939, 816, 0, 0, 7), -- Documenting the Timeways
(30104, 6, -1, 939, 816, 0, 0, 7), -- Documenting the Timeways
(30104, 7, 0, 939, 816, 0, 0, 7), -- Documenting the Timeways
(29387, 0, -1, 1, 606, 0, 0, 1); -- Guardians of Hyjal: Firelands Invasion!


UPDATE `quest_poi` SET `unk4`=3 WHERE `questid`=8790 AND `id`=1; -- Imperial Qiraji Regalia
UPDATE `quest_poi` SET `unk4`=3 WHERE `questid`=8789 AND `id`=1; -- Imperial Qiraji Armaments
UPDATE `quest_poi` SET `unk3`=2 WHERE `questid`=9948 AND `id`=0; -- Finding the Survivors
UPDATE `quest_poi` SET `unk3`=2 WHERE `questid`=9374 AND `id`=0; -- Arelion's Journal
UPDATE `quest_poi` SET `unk3`=1 WHERE `questid`=9948 AND `id`=1; -- Finding the Survivors
UPDATE `quest_poi` SET `unk3`=1 WHERE `questid`=9374 AND `id`=1; -- Arelion's Journal
UPDATE `quest_poi` SET `unk3`=1 WHERE `questid`=12619 AND `id`=0; -- The Emblazoned Runeblade
UPDATE `quest_poi` SET `WorldMapAreaId`=504, `FloorId`=1, `unk4`=3 WHERE `questid`=13832 AND `id`=0; -- Jewel Of The Sewers
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=14152 AND `id`=4; -- Rescue at Sea
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=14144 AND `id`=1; -- The Light's Mercy
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=14143 AND `id`=1; -- A Leg Up
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=14096 AND `id`=3; -- You've Really Done It This Time, Kul
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13861 AND `id`=1; -- Battle Before The Citadel
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13860 AND `id`=3; -- At The Enemy's Gates
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13858 AND `id`=3; -- At The Enemy's Gates
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13856 AND `id`=3; -- At The Enemy's Gates
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13837 AND `id`=1; -- Mastery Of The Charge
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13835 AND `id`=3; -- Mastery Of The Shield-Breaker
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13828 AND `id`=3; -- Mastery Of Melee
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13790 AND `id`=0; -- Among the Champions
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13789 AND `id`=3; -- Taking Battle To The Enemy
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13782 AND `id`=0; -- The Grand Melee
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13781 AND `id`=1; -- A Valiant's Field Training
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13779 AND `id`=0; -- A Worthy Weapon
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13777 AND `id`=0; -- The Grand Melee
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13776 AND `id`=1; -- A Valiant's Field Training
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13775 AND `id`=0; -- The Edge Of Winter
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13774 AND `id`=0; -- A Worthy Weapon
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13773 AND `id`=0; -- A Blade Fit For A Champion
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13770 AND `id`=0; -- The Edge Of Winter
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13768 AND `id`=0; -- A Blade Fit For A Champion
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13767 AND `id`=0; -- The Grand Melee
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13765 AND `id`=1; -- A Valiant's Field Training
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13764 AND `id`=0; -- The Edge Of Winter
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13728 AND `id`=0; -- The Valiant's Challenge
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13727 AND `id`=0; -- The Valiant's Challenge
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13710 AND `id`=0; -- Valiant Of Undercity
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13682 AND `id`=0; -- Threat From Above
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13672 AND `id`=0; -- Up To The Challenge
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13671 AND `id`=1; -- Training In The Field
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13669 AND `id`=0; -- A Worthy Weapon
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13667 AND `id`=0; -- The Argent Tournament
UPDATE `quest_poi` SET `WorldMapAreaId`=492, `unk4`=3 WHERE `questid`=13625 AND `id`=3; -- Learning The Reins


DELETE FROM `quest_poi_points` WHERE (`questId`=29387 AND `id`=0) OR (`questId`=8789 AND `id`=1) OR (`questId`=8789 AND `id`=2) OR (`questId`=8790 AND `id`=1) OR (`questId`=8790 AND `id`=2) OR (`questId`=28753 AND `id`=0) OR (`questId`=28753 AND `id`=1) OR (`questId`=28753 AND `id`=2) OR (`questId`=28753 AND `id`=3) OR (`questId`=28753 AND `id`=4) OR (`questId`=29172 AND `id`=0) OR (`questId`=29172 AND `id`=1) OR (`questId`=29172 AND `id`=2) OR (`questId`=29172 AND `id`=3) OR (`questId`=30100 AND `id`=0) OR (`questId`=30100 AND `id`=2) OR (`questId`=30104 AND `id`=3) OR (`questId`=30104 AND `id`=4) OR (`questId`=30104 AND `id`=5) OR (`questId`=30104 AND `id`=6) OR (`questId`=30104 AND `id`=7) OR (`questId`=29513 AND `id`=0) OR (`questId`=29513 AND `id`=1);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(30104, 3, 0, 3520, -5209), -- Documenting the Timeways
(30104, 4, 0, 3522, -5212), -- Documenting the Timeways
(30104, 5, 0, 3335, -5735), -- Documenting the Timeways
(30104, 6, 0, 3332, -5747), -- Documenting the Timeways
(30104, 7, 0, 3198, -4943), -- Documenting the Timeways
(30100, 0, 0, 3459, -5240), -- The Vainglorious
(30100, 2, 0, 3126, -5552), -- The Vainglorious
(29513, 0, 0, -4165, 6286), -- Spoilin' for Salty Sea Dogs
(29513, 1, 0, -4422, 6214), -- Spoilin' for Salty Sea Dogs
(29513, 1, 1, -4401, 6247), -- Spoilin' for Salty Sea Dogs
(29513, 1, 2, -4398, 6298), -- Spoilin' for Salty Sea Dogs
(29513, 1, 3, -4398, 6346), -- Spoilin' for Salty Sea Dogs
(29513, 1, 4, -4401, 6390), -- Spoilin' for Salty Sea Dogs
(29513, 1, 5, -4412, 6434), -- Spoilin' for Salty Sea Dogs
(29513, 1, 6, -4449, 6437), -- Spoilin' for Salty Sea Dogs
(29513, 1, 7, -4462, 6387), -- Spoilin' for Salty Sea Dogs
(29513, 1, 8, -4462, 6353), -- Spoilin' for Salty Sea Dogs
(29513, 1, 9, -4462, 6312), -- Spoilin' for Salty Sea Dogs
(29513, 1, 10, -4462, 6264), -- Spoilin' for Salty Sea Dogs
(29513, 1, 11, -4449, 6217), -- Spoilin' for Salty Sea Dogs
(29172, 0, 0, -11858, -1487), -- The Beasts Within
(29172, 0, 1, -11759, -1414), -- The Beasts Within
(29172, 0, 2, -11789, -1370), -- The Beasts Within
(29172, 0, 3, -11926, -1469), -- The Beasts Within
(29172, 1, 0, -11782, -1280), -- The Beasts Within
(29172, 2, 0, -12020, -1589), -- The Beasts Within
(29172, 3, 0, -11892, -1265), -- The Beasts Within
(28753, 0, 0, -692, 193), -- Doing it the Hard Way
(28753, 1, 0, -504, 3), -- Doing it the Hard Way
(28753, 2, 0, -317, 192), -- Doing it the Hard Way
(28753, 3, 0, -508, 379), -- Doing it the Hard Way
(28753, 4, 0, -449, 194), -- Doing it the Hard Way
(8789, 1, 0, -8327, 1820), -- Imperial Qiraji Armaments
(8789, 2, 0, -8328, 1823), -- Imperial Qiraji Armaments
(8790, 1, 0, -8303, 1821), -- Imperial Qiraji Regalia
(8790, 2, 0, -8308, 1813), -- Imperial Qiraji Regalia
(29387, 0, 0, 4411, -2076); -- Guardians of Hyjal: Firelands Invasion!
