-- Attach touch of the magi aura script
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_touch_of_the_magi_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(210824,'spell_mage_touch_of_the_magi_aura');
