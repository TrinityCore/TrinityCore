delete from creature where id in (7382,60106,60107,60040) and map = 1004;

update creature_template set ScriptName = 'boss_high_inquisitor_whitemane' where entry = 3977;
update creature_template set ScriptName = 'npc_commander_durand' where entry = 60040;
update creature_template set ScriptName = 'npc_scarlet_judicator' where entry = 58605;

delete from areatrigger_scripts where entry = 7496;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(7496, 'at_enter_durand_room');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (9232,113134,115876);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 9232, 0, 0, 31, 0, 3, 60040, 0, 0, 0, '', NULL),
(13, 1, 113134, 0, 0, 31, 0, 3, 58605, 0, 0, 0, '', NULL),
(13, 3, 115876, 0, 0, 31, 0, 3, 3977, 0, 0, 0, '', NULL);

delete from achievement_criteria_data where criteria_id = 20284;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(20284, 11, 0, 0, 'achievement_and_stay_dead');

delete from creature_text where entry in (60040, 3977);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60040, 0, 0, 'Подумать только! Так далеко зайти лишь для того, чтобы погибнуть здесь. Я дарую вам быструю смерть.', 14, 0, 100, 0, 0, 27529, 'Командир Дюранд to Player'),
(60040, 1, 0, 'Вот оно – начало моей легенды!', 14, 0, 100, 0, 0, 27527, 'Командир Дюранд to 0'),
(60040, 2, 0, 'Но как же... легенда?!', 14, 0, 100, 0, 0, 27528, 'Командир Дюранд to 0'),
-- boss talk
(3977, 0, 0, 'Вы заплатите за свое вероломство!', 14, 0, 100, 0, 0, 29616, 'Верховный инквизитор Вайтмейн to 0'),
(3977, 1, 0, '%s начинает читать заклинание |cFFFF0000|Hspell:113134|h[Массовое воскрешение]|h|r!', 41, 0, 100, 0, 0, 0, 'Верховный инквизитор Вайтмейн to 0'),
(3977, 2, 0, 'Восстань, защитник мой!', 14, 0, 100, 66, 0, 0, 'Верховный инквизитор Вайтмейн to 0'),
(3977, 3, 0, 'Могрейн...', 14, 0, 100, 0, 0, 29617, 'Верховный инквизитор Вайтмейн to 0');

delete from creature where id = 58605 and map = 1004;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(58605, 1004, 6109, 874, 262, 1, 0, 0, 916.778, 663.271, 11.6328, -0.994838, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 938.951, 623.913, 1.16071, 1.51844, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 938.971, 627.24, 1.16071, -1.5708, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 948.767, 583.986, 0.684073, 3.07178, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 984.533, 610.703, 0.684138, 3.01927, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 984.682, 614.471, 0.684009, -1.95568, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 995.757, 631.502, 0.858119, 0.965425, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 999.946, 627.578, 0.824833, 0.649476, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 1047.16, 651.163, 1.14178, 3.05529, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0),
(58605, 1004, 6109, 874, 262, 1, 0, 0, 1050.3, 633.771, 1.12611, 4.59911, 14400, 0, 0, 1181823, 1181823, 0, 0, 0, 0, 0, 0);