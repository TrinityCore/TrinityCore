delete from creature where id in (64446,59507);

SET @Korloff := (SELECT guid FROM creature WHERE id = 59223);
DELETE FROM waypoint_data WHERE id =@Korloff;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`, `wpguid`) VALUES
(@Korloff, 0, 860.95, 589.78, 10.00, 0, 10000, 0, 0, 100, 59223, 0),
(@Korloff, 1, 861.55, 623.24, 10.00, 0, 10000, 0, 0, 100, 59223, 0);

delete from creature_addon where guid =@Korloff;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@Korloff, @Korloff, 0, 0, 1, 0, '');

update creature_template set speed_walk = '1.8', ScriptName = 'boss_brother_korloff' where entry = 59223;
update creature_template set ScriptName = 'npc_korloff_training_dummy' where entry = 64446;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (125852,125844);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 125852, 0, 0, 31, 0, 3, 64446, 0, 0, 0, '', NULL),
(13, 1, 125844, 0, 0, 31, 0, 3, 64446, 0, 0, 0, '', NULL);

delete from creature_text where entry = 59223;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59223, 0, 0, 'Меня нельзя победить!', 14, 0, 100, 0, 0, 29496, 'Брат Корлофф to 0'),
(59223, 1, 0, 'Тебе не скрыться. Орден уничтожит всех, кто носит метку Плети.', 12, 0, 100, 0, 0, 29496, 'Брат Корлофф to Player'),
(59223, 2, 0, 'Мои кулаки алые... от вашей крови!', 14, 0, 100, 0, 0, 0, 'Брат Корлофф to 0'),
(59223, 3, 0, 'Вы... как железо...', 14, 0, 100, 0, 0, 29497, 'Брат Корлофф to Player');

delete from achievement_criteria_data where criteria_id = 20223;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(20223, 11, 0, 0, 'achievement_burning_man');