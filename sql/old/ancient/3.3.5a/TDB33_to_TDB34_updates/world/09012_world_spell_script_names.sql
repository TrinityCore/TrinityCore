DROP TABLE IF EXISTS `spell_script_names`;
CREATE TABLE `spell_script_names` (
  `spell_id` int(11) NOT NULL,
  `ScriptName` char(64) NOT NULL,
  UNIQUE (`spell_id`, `ScriptName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
