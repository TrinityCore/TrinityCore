delete from spell_linked_spell where spell_trigger = -122761;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastype`, `hastalent`, `hastype2`, `hastalent2`, `chance`, `cooldown`, `duration`, `hitmask`, `removeMask`, `targetCountType`, `targetCount`, `actiontype`, `group`, `comment`) VALUES 
(-122761, -122852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 'Remove Zorlok Inhale');

delete from spell_target_filter where spellId in (124258);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(124258, 15, 2, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Tayak - Storm unleashed Ride Veh');

update areatrigger_data set windSpeed = 7 where entry = 381;
update creature_template set InhabitType = 7 where entry = 62908;

delete from areatrigger_scripts where entry in (8196,8197);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(8196, 'at_storm_unleashed'),
(8197, 'at_storm_unleashed');
