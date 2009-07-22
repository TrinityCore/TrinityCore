-- --------
-- TRIGGER
-- --------

INSERT INTO creature_template (entry, spell1, flags_extra, scriptname) VALUES
(23095, 40980, 128, 'molten_flame'), # molten_flame
# (23085, 40117, 128, ''), # volcano
(23336, 40836, 128, ''), # flame crash
(23259, 40610, 128, ''), # blaze
(23069, 40029, 128, ''), # demon fire
(24187, 43218, 128, ''), # pillar of fire
(17662, 30914, 128, ''), # Broggok Poison Cloud
(25879, 46262, 128, ''), # Void Zone Periodic
(16363, 28158, 128, ''), # Grobbulus Cloud
(29379, 54362, 128, '') # Grobbulus Cloud (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

UPDATE creature_template SET speed = 1.0 WHERE entry = 23095; # molten_flame

-- --------
-- MISC
-- --------
UPDATE `creature_template` SET `flags_extra` = 33 WHERE `entry` = 23576; /*no crush*/

-- --------
-- PET
-- --------
INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4) VALUES
(15352, 36213, 0, 0, 0), # Greater Earth Elemental
(15438, 57984, 12470, 13376, 0), # Greater Fire Elemental
(29264, 58861, 58875, 58867, 58857), # Spirit Wolf
(510, 31707, 33395, 0, 0) # Water Elemental
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4);

-- Three-seat mammoth
UPDATE creature_template SET VehicleId = 312 WHERE entry IN (31857,31858,31861,31862,32212,32213,32633,32640);

-- --------
-- Death Knight
-- --------
update creature_template set spell5=51890 where entry = 28511; -- Eye of Acherus flight

update creature_template set minlevel=50,maxlevel=52,minhealth=2215,maxhealth=2317,faction_A=2084,faction_H=2084,mindmg=50,maxdmg=50 where entry=28528; -- ghoul
UPDATE `creature_template` SET spell1=52372,spell2=52373,spell3=52374,spell4=52375 WHERE `entry`=28406;

-- Horses for quest 12680 / not sure if its offilike
UPDATE creature_template SET `VehicleId`=200, spell1=52264, spell2=52268 WHERE `entry` IN (28605, 28606, 28607);

-- Vehicle and summon spell(summon npc 28788) for Acherus Deathcharger
UPDATE creature_template SET `spell1`=52362, `VehicleId`=200 WHERE `entry`=28782;

-- DK quest data TODO: remove these when DB projects release with proper data
DELETE FROM `creature_questrelation` WHERE `quest`=12701;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28377, 12701);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12701;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28377, 12701);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12723;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12723);
DELETE FROM `creature_questrelation` WHERE `quest`=12724;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12724);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12724;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12724);
DELETE FROM `creature_questrelation` WHERE `quest`=12725;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28913, 12725);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12725;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28912, 12725);
DELETE FROM `creature_questrelation` WHERE `quest`=12727;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28912, 12727);
DELETE FROM `creature_involvedrelation` WHERE `quest`=12727;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28913, 12727);
DELETE FROM `creature_questrelation` WHERE `quest` = 12754; 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12754); 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12754; 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12754); 
DELETE FROM `creature_questrelation` WHERE `quest` = 12757; 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12757); 
DELETE FROM `creature_questrelation` WHERE `quest` = 12754; 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12754); 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12754; 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12754); 
DELETE FROM `creature_questrelation` WHERE `quest` = 12755; 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12755); 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12756; 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12756); 
DELETE FROM `creature_questrelation` WHERE `quest` = 12757; 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12757); 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12800; 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (31082, 12800); 
DELETE FROM `creature_questrelation` WHERE `quest` = 12801; 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (31082, 12801); 
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12801; 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (29173, 12801);
UPDATE `quest_template` SET `PrevQuestId`=13166 WHERE `entry`=13188;
UPDATE `quest_template` SET `PrevQuestId`=13166 WHERE `entry`=13189;

UPDATE creature_template SET spell1=52435,spell2=52576,spell5=52588,VehicleId=68,speed=0 WHERE entry IN (28833,28887);
UPDATE creature_template SET spell1=52211 WHERE entry=28864;
-- Citizen of New Avalon
UPDATE creature_template SET unit_flags = 537166336, dynamicflags = 0 WHERE entry = 28942;
-- frostbrood vanquisher
update creature_template set maxhealth = 133525, minhealth = 133525, maxmana = 51360, minmana = 51360, spell1 = 53114, spell2 = 53112, spell3=53110, VehicleId = 156 where entry = 28670;

UPDATE `creature` SET `phaseMask`=128 WHERE `id` IN (31082,29173,29199,29204,29200);

-- --------
-- NAXXARAMAS
-- --------
INSERT INTO creature_template (entry, spell1, flags_extra, scriptname) VALUES
(16363, 28158, 128, ''), # Grobbulus Cloud
(29379, 54362, 128, ''), # Grobbulus Cloud (H)
(16697, 28158, 128, ''), # Void Zone
(29379, 54362, 128, '')  # Void Zone (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

INSERT INTO creature_template (entry, baseattacktime, spell1, flags_extra) VALUES
(16474, 1000, 28547, 128), # Blizzard (Sapphiron)
(30000, 1000, 55699, 128), # Blizzard (Sapphiron) (H)
(16697, 1000, 28865, 128), # Void Zone (Lady Blaumeux)
(16129, 10000, 27812, 128) # Shadow Fissure (Kel'thezad)
ON DUPLICATE KEY UPDATE
baseattacktime = VALUES(baseattacktime),
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra);

INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4, spell5, spell6, spell7, spell8) VALUES
(16573, 15284, 28991, 28969, 34970, 0, 0, 0, 28864), # Crypt Guard
(29256, 15284, 28991, 56098, 34970, 0, 0, 0, 28864), # Crypt Guard (H)
(16506, 54095, 0, 0, 0, 0, 0, 0, 28732), # Naxxramas Worshipper
(29274, 54096, 0, 0, 0, 0, 0, 0, 54097), # Naxxramas Worshipper (H)
(17055, 54121, 0, 0, 0, 0, 0, 0, 0), # Maexxna Spiderling
(29279, 28776, 0, 0, 0, 0, 0, 0, 0), # Maexxna Spiderling (H)
(16486, 28622, 0, 0, 0, 0, 0, 0, 0), # Web Wrap
(30183, 28622, 0, 0, 0, 0, 0, 0, 0), # Web Wrap (H)
(16984, 15496, 0, 0, 0, 0, 0, 0, 0), # Plagued Warrior
(29632, 15496, 0, 0, 0, 0, 0, 0, 0), # Plagued Warrior (H)
(16983, 32736, 30138, 0, 0, 0, 0, 0, 0), # Plagued Champion
(29632, 32736, 54889, 0, 0, 0, 0, 0, 0), # Plagued Champion (H)
(16981, 15496, 54890, 0, 0, 0, 0, 0, 0), # Plagued Guardian
(29632, 15496, 54891, 0, 0, 0, 0, 0, 0), # Plagued Guardian (H)
(16286, 0, 0, 0, 0, 0, 0, 0, 29232), # Spore
(30068, 0, 0, 0, 0, 0, 0, 0, 29232), # Spore (H)
(16290, 28156, 0, 0, 0, 0, 0, 0, 0), # Fallout Slime
(29388, 54367, 0, 0, 0, 0, 0, 0, 0), # Fallout Slime (H)
(16360, 29307, 0, 0, 0, 0, 0, 0, 0), # Zombie Chow
(30303, 29307, 0, 0, 0, 0, 0, 0, 0), # Zombie Chow (H)
(16803, 0, 0, 0, 61696, 29060, 29061, 0, 0), # Death Knight Understudy
(29941, 0, 0, 0, 61696, 29060, 29061, 0, 0), # Death Knight Understudy (H)
(16124, 55604, 0, 0, 0, 0, 0, 0, 27892), # Unrelenting Trainee
(16125, 27825, 0, 0, 0, 0, 0, 0, 27928), # Unrelenting Death Knight
(16126, 27831, 55606, 0, 0, 0, 0, 0, 27935), # Unrelenting Rider
(16127, 27989, 0, 0, 0, 0, 0, 0, 0), # Spectral Trainee
(16148, 56408, 0, 0, 0, 0, 0, 0, 0), # Spectral Death Knight
(16150, 27994, 55648, 55606, 0, 0, 0, 0, 0), # Spectral Rider
(16149, 27993, 0, 0, 0, 0, 0, 0, 0), # Spectral Horse
(29985, 55645, 0, 0, 0, 0, 0, 0, 27892), # Unrelenting Trainee (H)
(29986, 27825, 0, 0, 0, 0, 0, 0, 27928), # Unrelenting Death Knight (H)
(29987, 55638, 55608, 0, 0, 0, 0, 0, 27935), # Unrelenting Rider (H)
(30264, 56407, 0, 0, 0, 0, 0, 0, 0), # Spectral Trainee (H)
(29990, 56408, 0, 0, 0, 0, 0, 0, 0), # Spectral Death Knight (H)
(29988, 55646, 27995, 55608, 0, 0, 0, 0, 0), # Spectral Rider (H)
(29989, 27993, 0, 0, 0, 0, 0, 0, 0) # Spectral Horse (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4),
spell5 = VALUES(spell5),
spell6 = VALUES(spell6),
spell7 = VALUES(spell7),
spell8 = VALUES(spell8);

UPDATE `creature_template` SET `spell1`=59638, `spell2` = 59637 WHERE `entry`=31216; # Mirror Image

# Spore
UPDATE `creature_template` SET `minlevel`='80',`maxlevel`='80',`faction_A`='21',`faction_H`='21' WHERE entry IN (16286,30068);

-- --------
-- WINTERGRASP
-- --------
update creature_template set maxhealth = 30000, minhealth = 30000, speed = 2, spell1=50025, spell2=50989, VehicleId = 36 where entry = 27881;
update creature_template set maxhealth = 50000, minhealth = 50000, speed = 1.6, spell1=50896, spell2=50652, VehicleId = 106 where entry = 28094;
update creature_template set maxhealth = 75000, minhealth = 75000, speed = 1, spell1=51678, VehicleId = 117 where entry IN (28312,32627);
update creature_template set maxhealth = 50000, minhealth = 50000, spell1=51362, VehicleId = 116 where entry IN (28319,32629);

UPDATE creature_template SET VehicleId = 174 WHERE entry IN (31125,31722);
