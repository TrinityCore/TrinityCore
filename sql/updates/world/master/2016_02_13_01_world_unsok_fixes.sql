delete from creature_template where entry = 90903;
update creature_template set modelid2 = 0, modelid3 = 0, minlevel = 90, maxlevel = 90, unit_flags = 34080768, inhabittype = 7, flags_extra = 128, scriptName = 'npc_amberbeam_stalker' where entry = 62510;
update creature_template set flags_extra = 536870912 where entry = 62711;
update creature_template set AIName = 'SmartAI', mechanic_immune_mask = 76220995 where entry = 62701;

delete from smart_scripts where entryorguid = 62701;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(62701, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Just Summon - Attack Start'),
(62701, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 11, 122398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Amber Explosion');

update spell_linked_spell set spell_trigger = -122784 where spell_trigger = 122784;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 122532;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 122532, 0, 0, 1, 0, 122370, 0, 0, 0, 0, '', NULL),
(13, 2, 122532, 0, 1, 31, 0, 3, 62691, 0, 0, 0, '', NULL);

delete from spell_linked_spell where spell_trigger = 123060;

delete from spell_script_names where spell_id = 123060;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(123060, 'spell_unsok_break_free');
