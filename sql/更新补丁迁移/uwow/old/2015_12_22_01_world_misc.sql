update creature set spawndist = 0, movementType = 0 where id = 60701;
update creature_template set mechanic_immune_mask = mechanic_immune_mask &~33554432 where entry in (60701,60708);
update creature_template set modelid2 = 0, modelid3 = 0, unit_flags = 131844, flags_extra = 130 where entry = 60942;
update creature_template set ScriptName = 'npc_flanking_mogu' where entry = 60847;

delete from creature_template_addon where entry = 60709;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(60709, 0, 0, 0, 1, 0, NULL);

delete from spell_target_filter where spellId in (118121,117684,117504);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(118121, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Rain of Arrows'),
(117684, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Charged Shadows'),
(117504, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Undying Shadows');

delete from spell_dummy_trigger where spell_id in (118121,117684,117504);
INSERT INTO `spell_dummy_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) VALUES 
(118121, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Rain of Arrows'),
(117684, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Charged Shadows'),
(117504, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Undying Shadows');

delete from spell_script_names where spell_id in (117737,117756);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(117737, 'spell_meng_crazed'),
(117756, 'spell_meng_crazed');

delete from spell_radius where spell_id in (117558,117529);
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `effectradius3`, `effectradius4`, `comments`) VALUES 
(117558, 13, 0, 0, 0, 0, '10 yards'),
(117529, 13, 0, 0, 0, 0, '10 yards');