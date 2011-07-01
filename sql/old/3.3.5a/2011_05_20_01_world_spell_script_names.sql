DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_mana_void';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_decay_periodic_timer';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_summoner';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_summon_suppresser';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_summon_dream_portal';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_summon_nightmare_portal';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dreamwalker_nightmare_cloud';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_putricide_slime_puddle_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(71085,'spell_dreamwalker_mana_void'),
(70915,'spell_dreamwalker_decay_periodic_timer'),
(70912,'spell_dreamwalker_decay_periodic_timer'),
(70916,'spell_dreamwalker_decay_periodic_timer'),
(70913,'spell_dreamwalker_decay_periodic_timer'),
(70921,'spell_dreamwalker_summoner'),
(70912,'spell_dreamwalker_summon_suppresser'),
(71032,'spell_dreamwalker_summoner'),
(71078,'spell_dreamwalker_summoner'),
(70933,'spell_dreamwalker_summoner'),
(72224,'spell_dreamwalker_summon_dream_portal'),
(72480,'spell_dreamwalker_summon_nightmare_portal'),
(71970,'spell_dreamwalker_nightmare_cloud'),
-- bind only on heroic modes, normal does not need this replacement
(72868,'spell_putricide_slime_puddle_aura'),
(72869,'spell_putricide_slime_puddle_aura');
