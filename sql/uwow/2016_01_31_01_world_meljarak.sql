delete from creature where id in (62408,65499,65500);
update creature_template set minlevel = 90, maxlevel = 90, unit_flags = 33555200, AIName = 'SmartAI', flags_extra = 128 where entry in (63930,67046);
update creature_template set minlevel = 90, maxlevel = 90, unit_flags = 34079488, ScriptName = 'npc_meljarak_wind_bomb' where entry = 67053;
update creature_template set minlevel = 90, maxlevel = 90, faction = 35, npcflag = 16777216, unit_flags = 524288, unit_flags2 = 69208064, ScriptName = 'npc_meljarak_amber_prison' where entry = 62531;

update gameobject set spawntimesecs = 604800 where id = 212386;

delete from creature_template_addon where entry = 67046;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(67046, 0, 0, 0, 1, 0, '129005');

delete from smart_scripts where entryorguid in (63930,67046);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(63930, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Just Summon - React State Passive'),
(67046, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Just Summon - React State Passive');

delete from spell_script_names where spell_id in (121898,121896,122064);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(121898, 'spell_meljarak_whirling_blade'),
(121896, 'spell_meljarak_whirling_blade_visual'),
(122064, 'spell_meljarak_corrosive_resin');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (131813,122354,125935,125936,125873);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 131813, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', NULL),
(13, 3, 122354, 0, 0, 31, 0, 3, 62397, 0, 0, 0, '', NULL),
(13, 1, 125935, 0, 0, 31, 0, 3, 62397, 0, 0, 0, '', NULL),
(13, 1, 125936, 0, 0, 31, 0, 3, 62397, 0, 0, 0, '', NULL),
(13, 7, 125873, 0, 0, 31, 0, 3, 62397, 0, 0, 0, '', NULL);

delete from spell_linked_spell where spell_trigger = 121885;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`,`comment`) VALUES
(121885, 129078, 0, 'Heart of Fear - Meljarak');

delete from spell_area where spell = 121885;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(121885, 6297, 0, 0, 0, 0, 2, 0, 64, 11);