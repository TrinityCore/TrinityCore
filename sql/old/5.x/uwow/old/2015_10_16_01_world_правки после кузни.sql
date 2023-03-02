update creature set spawntimesecs = 600 where id = 69099;
update creature_template set dmg_multiplier = 1000 where entry = 69739;

delete from creature_questrelation where id = 70438 and quest = 32594;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES 
(70438, 32594);

update quest_template set startscript = 32594 where id = 32594;
delete from quest_start_scripts where id = 32594;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(32594, 0, 8, 70456, 0, 0, 0, 0, 0, 0);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (137658,137660);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 137658, 0, 0, 31, 0, 3, 69099, 0, 0, 0, '', 'only quest npc spell target'),
(13, 1, 137660, 0, 0, 31, 0, 3, 69099, 0, 0, 0, '', 'only quest npc spell target');

delete from spell_linked_spell where spell_effect = 51775;