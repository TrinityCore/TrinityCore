DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_heroic_leap_damage', 'spell_warr_heroic_leap_jump');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52174, 'spell_warr_heroic_leap_damage');

UPDATE `jump_charge_params` SET `speed`=0.616, `jumpGravity`=126.496856689453125, `triggerSpellId`=52174 WHERE `id` = 17;
