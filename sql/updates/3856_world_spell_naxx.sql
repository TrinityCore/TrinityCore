UPDATE `creature_template` SET `minlevel`='80',`maxlevel`='80',`faction_A`='21',`faction_H`='21' WHERE entry IN (16286,30068);

INSERT INTO creature_template (entry, baseattacktime, spell1, flags_extra, scriptname) VALUES
(16129, 10000, 27812, 128, 'trigger_periodic') # Shadow Fissure (Kel'thezad)
ON DUPLICATE KEY UPDATE
baseattacktime = VALUES(baseattacktime),
spell1 = VALUES(spell1),
flags_extra = VALUES(flags_extra),
scriptname = VALUES(scriptname);