-- Mana Tombs Instance
-- UPDATE `creature_template` SET `exp`=2 WHERE `entry` IN (22930);
-- Hillsbrad Foothills Instance
UPDATE `creature_template` SET `maxlevel`=67 WHERE `entry` IN (17819);
UPDATE `creature_template` SET `minlevel`=67 WHERE `entry` IN (18170,18171,18172);
UPDATE `creature_template` SET `minlevel`=69 WHERE `entry` IN (20528,20537,20538,20543);
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry` IN (20526);
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry` IN (20533,20534,20546,20547);
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=69 WHERE `entry` IN (20524,20541);
UPDATE `creature_template` SET `minlevel`=71, `maxlevel`=71 WHERE `entry` IN (20525,20529,20548);
-- Sethekk Halls Heroic
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry` IN (20692); -- Sethekk Guard (1)
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry` IN (20686); -- Avian Darkhawk (1)
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry` IN (20572); -- Sethekk Prophet (1)
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry` IN (20697); -- Time-Lost Scryer (1)
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry` IN (20701); -- Sethekk Talon Lord (1)
