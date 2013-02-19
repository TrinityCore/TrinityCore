-- Spell script name linking for Defending Wyrmrest Temple: Character Script Cast From Gossip ID: 49123
DELETE FROM `spell_script_names` WHERE `spell_id`=49213;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49213,'spell_q12372_cast_from_gossip_trigger');
