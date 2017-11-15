-- Jin'thala, Nekali, Voldreka, Darkspear Jailor, Legati, Nortet, Ortezza, Tunari, Zen'tabra, Soratha, Wounded Darkspear Watcher
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (37951,38242,42618,39062,38244,38037,38247,38245,38243,38246,47057);
-- Novice Darkspear Warrior, Novice Darkspear Rogue, Novice Darkspear Priest, Novice Darkspear Mage, Novice Darkspear Druid, Novice Darkspear Shaman, Novice Darkspear Hunter, Novice Darkspear Warlock 
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (38268,38272,38278,38279,38280,38281,38282,42619);

-- Gora'tin, Moraya, Morakki, Torenda, Jornun, Bloodtalon Thrasher, Sortura, Tora'jin, Hira'jin
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (39032,38005,38442,39031,38989,38987,39033,39007,39008);

UPDATE `creature_classlevelstats` SET `basehp3`=227 WHERE `level`=8 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=248 WHERE `level`=9 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=290 WHERE `level`=11 AND `class` IN (1,2,4);
UPDATE `creature_classlevelstats` SET `basehp3`=232 WHERE `level`=11 AND `class` IN (8);
