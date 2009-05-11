DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-28169);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-28169, 28206,  0, 'Mutating Injection - Mutagen Explosion'),
(-28169, 28240,  0, 'Mutating Injection - Poison Cloud');

UPDATE creature_template SET scriptname = 'boss_grobbulus' WHERE entry = 15931;

INSERT INTO creature_template (entry, spell1, flags_extra, scriptname) VALUES
(16363, 28158, 128, ''), # Grobbulus Cloud
(29379, 54362, 128, '')  # Grobbulus Cloud (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

INSERT INTO creature_template (entry, spell1, spell2, flags_extra, scriptname) VALUES
(16474, 28547, 1000, 128, 'trigger_periodic'), # Blizzard (Sapphiron)
(30000, 55699, 1000, 128, 'trigger_periodic')  # Blizzard (Sapphiron) (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (29912);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `cast_flags`) VALUES
(29912, 55479, 0, 1); # Obedience Crystal - Force Obedience

DELETE FROM `spell_script_target` WHERE `entry` IN (55479);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(55479, 1, 16803); # Force Obedience - Death Knight Understudy

INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4, spell5, spell6, spell7, spell8) VALUES
(16803, 0, 0, 0, 61696, 29060, 29061, 0, 0), # Death Knight Understudy
(29941, 0, 0, 0, 61696, 29060, 29061, 0, 0), # Death Knight Understudy (H)
(16573, 15284, 28991, 28969, 34970, 28864, 0, 0, 0), # Crypt Guard
(29256, 15284, 28991, 56098, 34970, 28864, 0, 0, 0), # Crypt Guard (H)
(16984, 15496, 0, 0, 0, 0, 0, 0, 0), # Plagued Warrior
(29632, 15496, 0, 0, 0, 0, 0, 0, 0), # Plagued Warrior (H)
(16290, 28156, 0, 0, 0, 0, 0, 0, 0), # Fallout Slime
(29388, 54367, 0, 0, 0, 0, 0, 0, 0) # Fallout Slime (H)
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4),
spell5 = VALUES(spell5),
spell6 = VALUES(spell6),
spell7 = VALUES(spell7),
spell8 = VALUES(spell8);
