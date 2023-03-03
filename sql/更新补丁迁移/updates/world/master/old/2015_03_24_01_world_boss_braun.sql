delete from creature where id = 59309;
update creature_template set mindmg = mindmg * 8, maxdmg = maxdmg * 8, faction_A = 2579, faction_H = 2579, ScriptName = 'boss_houndmaster_braun' where entry = 59303;
update creature_template set mindmg = mindmg * 8, maxdmg = maxdmg * 8, ScriptName = 'npc_obedient_hound' where entry = 59309;
update creature_template set mindmg = mindmg * 8, maxdmg = maxdmg * 8, ScriptName = 'npc_braun_scarlet_guardian' where entry in (59299,59302);

update gameobject set state = 1 where id = 210097;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (116224,114260);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 116224, 0, 0, 31, 0, 3, 59303, 0, 0, 0, '', NULL),
(13, 3, 116224, 0, 1, 31, 0, 3, 59302, 0, 0, 0, '', NULL),
(13, 3, 116224, 0, 2, 31, 0, 3, 59299, 0, 0, 0, '', NULL),
(13, 1, 114260, 0, 0, 31, 0, 3, 59309, 0, 0, 0, '', NULL);

delete from creature_text where entry in (59303,59309,59302);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(59303, 0, 0, 'Хм-м... Эй, вы слышали?', 12, 0, 100, 0, 0, 27549, 'Псарь Браун to 0'),
(59303, 1, 0, 'Ах, свежее мясо для собак.', 12, 0, 100, 0, 0, 27550, 'Псарь Браун to 0'),
(59303, 2, 0, 'Взять их! Разорвать!', 12, 0, 100, 0, 0, 27536, 'Псарь Браун to 0'),
(59303, 3, 0, 'Нет!', 14, 0, 100, 0, 0, 27546, 'Псарь Браун to Послушный пес'),
(59303, 3, 1, 'Мой пес!', 14, 0, 100, 0, 0, 27547, 'Псарь Браун to Послушный пес'),
(59303, 3, 2, 'Мой пес!', 14, 0, 100, 0, 0, 27536, 'Псарь Браун to Послушный пес'),
(59303, 4, 0, 'Спустить псов!', 12, 0, 100, 0, 0, 27546, 'Псарь Браун to 0'),
(59303, 5, 0, 'Взять их! Разорвать!', 12, 0, 100, 0, 0, 27547, 'Псарь Браун to 0'),
(59303, 6, 0, 'Да как вы посмели?!', 14, 0, 100, 0, 0, 27548, 'Псарь Браун to Послушный пес'),
(59303, 7, 0, 'Хватит сидеть просто так! Убейте их!', 12, 0, 100, 5, 0, 27542, 'Псарь Браун to 0'),
(59303, 8, 0, 'Глупые животные! Я убью этих слабаков, а потом займусь вами.', 12, 0, 100, 5, 0, 27543, 'Псарь Браун to 0'),
(59303, 9, 0, 'Я истекаю кровью... ха-ха... но я не умру!', 12, 0, 100, 11, 0, 27544, 'Псарь Браун to 0'),
(59303, 10, 0, 'Что?! Нет... нет! Стойте! Вы должны слушаться хозяина!', 12, 0, 100, 274, 0, 27545, 'Псарь Браун to 0'),
(59303, 11, 0, 'А-а-а!', 12, 0, 100, 0, 0, 0, 'Псарь Браун to 0'),
(59303, 12, 0, 'Это я спустил собак!', 14, 0, 100, 0, 0, 0, 'Псарь браун'),
(59309, 0, 0, '%s повинуется хозяину и атакует.', 41, 0, 100, 0, 0, 0, 'Послушный пес to Player'),
(59302, 0, 0, 'Столько собак. Нам не сдержать их!', 14, 0, 100, 0, 0, 31467, 'Сержант Вердон to Послушный пес');