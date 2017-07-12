-- Class: Warrior, Spec: Arms, Protection, Spells: Impending Victory & Victorious State
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_impending_victory','spell_warr_victorious_state');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(202168,'spell_warr_impending_victory'),
(32215,'spell_warr_victorious_state');
