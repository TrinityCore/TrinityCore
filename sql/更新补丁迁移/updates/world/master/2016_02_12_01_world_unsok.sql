delete from spell_script_names where spell_id in (121949,122370,123156);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(121949, 'spell_unsok_parasitic_growth'),
(122370, 'spell_unsok_reshape_life'),
(123156, 'spell_unsok_consume_amber');

delete from spell_proc_event where entry = 121949;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(121949, 0, 0, 0, 0, 0, 0, 32768, 262144, 0, 100, 0, 1);

delete from spell_linked_spell where spell_trigger in (122784,123060,123156,-122370,122395);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(122784, 122370, 0, 'Unsok - Reshape Life'),
(123060, -122370, 0, 'Break Free'),
(123156, 122516, 0, 'Consume Amber - Add Health'),
(-122370, -122516, 0, 'Consume Amber - Remove Health'),
(122395, 124802, 0, 'Vulnerable');

delete from spell_area where spell in (122370,122516);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(122370, 6297, 0, 0, 0, 0, 2, 0, 64, 11),
(122516, 6297, 0, 0, 0, 0, 2, 0, 64, 11);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (123156);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 123156, 0, 0, 31, 0, 3, 62691, 0, 0, 0, '', NULL);

delete from spell_target_filter where spellId = 122413;
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(122413, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Amber Monstrosity - Fling');

delete from creature where id = 62762;
update creature_template set ScriptName = 'npc_amber_pool_stalker' where entry = 62762;