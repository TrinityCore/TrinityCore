UPDATE `creature_template` SET `ScriptName`='mob_webwrap' WHERE `entry`=16486;
UPDATE `creature_template` SET `ScriptName`='boss_grobbulus' WHERE entry = 15931;
UPDATE `creature_template` SET `ScriptName`='mob_gothik_minion' WHERE entry IN (16124,16125,16126,16127,16148,16149,16150);
UPDATE `creature_template` SET `ScriptName`='boss_four_horsemen' WHERE `entry` IN (16063,16064,16065,30549);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN
(28732,54097,-29865,-55053,-28169,28059,39088,-28059,-39088,28062,39090,28084,
39091,-28084,-39091,28085,39093);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 28732,-28798,  1, 'Widow\'s Embrace - Frenzy'),
( 54097,-54100,  1, 'Widow\'s Embrace - Frenzy (H)'),
(-29865, 55594,  0, 'Deathbloom'),
(-55053, 55601,  0, 'Deathbloom (H)'),
(-28169, 28206,  0, 'Mutating Injection - Mutagen Explosion'),
(-28169, 28240,  0, 'Mutating Injection - Poison Cloud'),
( 28059,-28084,  1, 'Positive Charge - Negative Charge'),
(-28059,-29659,  0, 'Positive Charge'),
# ( 28062,-29659,  0, 'Positive Charge'),
( 28084,-28059,  1, 'Negative Charge - Positive Charge'),
(-28084,-29660,  0, 'Negative Charge'),
# ( 28085,-29660,  0, 'Negative Charge'),
( 39088,-39091,  1, 'Positive Charge - Negative Charge'),
(-39088,-29659,  0, 'Positive Charge'),
# ( 39090,-29659,  0, 'Positive Charge'),
( 39091,-39088,  1, 'Negative Charge - Positive Charge'),
(-39091,-39092,  0, 'Negative Charge');
# ( 39093,-39092,  0, 'Negative Charge');

INSERT INTO creature_template (entry, spell1, flags_extra, scriptname) VALUES
(16363, 28158, 128, ''), # Grobbulus Cloud
(29379, 54362, 128, ''), # Grobbulus Cloud (H)
(16697, 28158, 128, ''), # Void Zone
(29379, 54362, 128, '')  # Void Zone (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

INSERT INTO creature_template (entry, baseattacktime, spell1, flags_extra, scriptname) VALUES
(16474, 1000, 28547, 128, 'trigger_periodic'), # Blizzard (Sapphiron)
(30000, 1000, 55699, 128, 'trigger_periodic'), # Blizzard (Sapphiron) (H)
(16697, 1000, 28865, 128, 'trigger_periodic') # Void Zone (Lady Blaumeux)
ON DUPLICATE KEY UPDATE
baseattacktime = VALUES(baseattacktime),
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (29912);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `cast_flags`) VALUES
(29912, 55479, 0, 1); # Obedience Crystal - Force Obedience

DELETE FROM `spell_script_target` WHERE `entry` IN
(28732,54097,55479,
27892,27893,27928,27929,27935,27936);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(28732, 1, 15953), # Widow's Embrace
(54097, 1, 15953), # Widow's Embrace
(55479, 1, 16803), # Force Obedience - Death Knight Understudy
# (29105, 1, 16803), # Hopeless - Death Knight Understudy
(27892, 1, 16060), # To Anchor 1 - Gothik
(27893, 1, 16060), # To Anchor 2 - Gothik
(27928, 1, 16060), # To Anchor 1 - Gothik
(27929, 1, 16060), # To Anchor 2 - Gothik
(27935, 1, 16060), # To Anchor 1 - Gothik
(27936, 1, 16060); # To Anchor 2 - Gothik

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
