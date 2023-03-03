INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `comment`) VALUES ('146346', '146347', '9', 'Life Steal');
DELETE FROM `spell_bonus_data` WHERE (`entry`='146347');
INSERT INTO `spell_bonus_data` (`entry`, `comments`) VALUES ('146347', 'Life Steal');