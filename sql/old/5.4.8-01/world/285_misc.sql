INSERT IGNORE INTO spell_script_names VALUE (104027, 'spell_warl_demonic_call');

DELETE FROM spell_script_names WHERE spell_id = 77485;

INSERT INTO spell_script_names VALUE (77485, 'spell_mastery_echo_of_light');

DELETE FROM spell_script_names WHERE ScriptName = 'spell_pri_from_darkness_comes_light';

INSERT INTO spell_script_names VALUE (109186, 'spell_pri_from_darkness_comes_light');

INSERT IGNORE INTO spell_script_names VALUE (3411, 'spell_warr_intervene');

-- A: Baradin's Wardens - H: Hellscream's Reach
DELETE FROM player_factionchange_reputations WHERE alliance_id=1177 OR horde_id=1178;
INSERT INTO player_factionchange_reputations (alliance_id, horde_id) VALUES
(1177, 1178);

-- A: Wildhammer Clan - H: Dragonmaw Clan
DELETE FROM player_factionchange_reputations WHERE alliance_id=1174 OR horde_id=1172;
INSERT INTO player_factionchange_reputations (alliance_id, horde_id) VALUES
(1174, 1172);

-- A: Kirin Tor Offensive - H: Sunreaver Onslaught
DELETE FROM player_factionchange_reputations WHERE alliance_id=1387 OR horde_id=1388;
INSERT INTO player_factionchange_reputations (alliance_id, horde_id) VALUES
(1387, 1388);

-- A: Operation: Shieldwall - H: Dominance Offensive
DELETE FROM player_factionchange_reputations WHERE alliance_id=1376 OR horde_id=1375;
INSERT INTO player_factionchange_reputations (alliance_id, horde_id) VALUES
(1376, 1375);

UPDATE spell_bonus_data SET ap_bonus = 0.374 WHERE entry = 108196;

UPDATE spell_bonus_data SET ap_bonus = 1.2 WHERE entry = 114867;

DELETE FROM spell_linked_spell WHERE spell_effect=147531;
