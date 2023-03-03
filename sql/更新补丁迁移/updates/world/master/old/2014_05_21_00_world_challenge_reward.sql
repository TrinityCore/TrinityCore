--
-- Структура таблицы `chellenge_reward`
--

DROP TABLE IF EXISTS `chellenge_reward`;
CREATE TABLE `chellenge_reward` (
  `mapId` mediumint(6) unsigned NOT NULL,
  `questCredit` int(11) unsigned NOT NULL,
  PRIMARY KEY (`mapId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Дамп данных таблицы `chellenge_reward`
--

INSERT INTO `chellenge_reward` (`mapId`, `questCredit`) VALUES
(959, 66953),
(960, 66951),
(961, 66952),
(962, 66954),
(994, 66953),
(1001, 66957),
(1004, 66956),
(1007, 66958),
(1011, 66955);
