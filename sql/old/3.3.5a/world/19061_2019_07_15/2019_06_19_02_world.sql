-- Building a Perimeter (10240)
DELETE FROM smart_scripts WHERE entryorguid IN(19866, 19867, 19868) AND source_type=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19866, 0, 0, 0, 8, 0, 100, 0, 34646, 0, 1000, 1000, 33, 19866, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis East KV Rune - On Spell Hit - Kill Monster Credit'),
(19866, 0, 1, 0, 8, 0, 100, 0, 34646, 0, 120000, 120000, 50, 183948, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis East KV Rune - On Spell Hit - Summon Gameobject'),
(19867, 0, 0, 0, 8, 0, 100, 0, 34646, 0, 1000, 1000, 33, 19867, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis NE KV Rune - On Spell Hit - Kill Monster Credit'),
(19867, 0, 1, 0, 8, 0, 100, 0, 34646, 0, 120000, 120000, 50, 183948, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis NE KV Rune - On Spell Hit - Summon Gameobject'),
(19868, 0, 0, 0, 8, 0, 100, 0, 34646, 0, 1000, 1000, 33, 19868, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis West KV Rune - On Spell Hit - Kill Monster Credit'),
(19868, 0, 1, 0, 8, 0, 100, 0, 34646, 0, 120000, 120000, 50, 183948, 120, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invis West KV Rune - On Spell Hit - Summon Gameobject');

DELETE FROM `gameobject` WHERE `id` = 183955;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(9009, 183955, 530, 1, 1, 2194.7275, 2314.035, 145, 2.179214, 0, 0, 0.133363, -0.991067, 180, 0, 1);

DELETE FROM `gameobject_addon` WHERE `guid` = 9009;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`) VALUES
(9009,0.133363,-0.991067, 7, 1000);

DELETE FROM `spell_area` WHERE `spell` IN (60194) AND `area` IN (3879,3934,3935);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(60194,3879,10240,0,0,0,2,1,64,0),
(60194,3934,10240,0,0,0,2,1,64,0),
(60194,3935,10240,0,0,0,2,1,64,0);
