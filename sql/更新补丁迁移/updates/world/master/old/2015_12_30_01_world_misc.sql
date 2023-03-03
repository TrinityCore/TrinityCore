delete from areatrigger_actions where entry = 306;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) VALUES 
(306, 0, 1, 0, 4096, 116663, 0, 0, 0, 0, 0, 0, 0, 'Elegon - Energy Conduit Entry'),
(306, 1, 42, 1, 4096, 116663, 0, 0, 0, 0, 0, 0, 0, 'Elegon - Energy Conduit Remove');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (116989,117220,118430);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 116989, 0, 0, 31, 0, 3, 60410, 0, 0, 0, '', NULL),
(13, 1, 117220, 0, 0, 31, 0, 3, 60410, 0, 0, 0, '', NULL),
(13, 1, 118430, 0, 0, 31, 0, 3, 60776, 0, 0, 0, '', NULL);

delete from spell_target_position where id in (129724);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(129724, 1008, 4023.12, 1907.75, 368, 0);

delete from spell_script_names where spell_id in (132222,118010,118011,118012,118014,118015,118016,117912,117914);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(132222, 'spell_elegon_destabilizing_energies'),
(118010, 'spell_elegon_draw_power'),
(118011, 'spell_elegon_draw_power'),
(118012, 'spell_elegon_draw_power'),
(118014, 'spell_elegon_draw_power'),
(118015, 'spell_elegon_draw_power'),
(118016, 'spell_elegon_draw_power'),
(117912, 'spell_elegon_vortex_filter'),
(117914, 'spell_elegon_vortex_filter'),
(132222, 'spell_elegon_vortex_filter');

delete from spell_dummy_trigger where spell_id in (129711,119358);
INSERT INTO `spell_dummy_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) VALUES 
(129711, 117914, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Elegon - Total Annihilation'),
(119358, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Elegon - Focus Power');

delete from spell_radius where spell_id = 127005;
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `effectradius3`, `effectradius4`, `comments`) VALUES 
(127005, 23, 0, 0, 0, 0, '40 yards');

delete from smart_scripts where entryorguid = 62618;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(62618, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summon - Start Attack');

delete from creature where id in (60776,61330);

update creature_template set inhabitType = 7, AIName = 'SmartAI' where entry = 62618;
update creature_template set inhabitType = 7, flags_extra = 128 where entry = 61330;
update creature_template set inhabitType = 7, ScriptName = 'npc_celestial_protector' where entry = 60793;
update creature_template set speed_run = 0.3, ScriptName = 'npc_energy_charge', mechanic_immune_mask = 667893759 where entry = 60913;
update creature_template set inhabitType = 7, ScriptName = 'npc_empyreal_focus' where entry = 60776;

delete from creature_template_addon where entry = 60776;