ALTER TABLE `access_requirement`   
  ADD COLUMN `dungeonId` SMALLINT(8) DEFAULT 0  NOT NULL AFTER `difficulty`, 
  CHANGE `mapId` `mapId` MEDIUMINT(8) NOT NULL,
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`mapId`, `difficulty`, `dungeonId`);

replace into `access_requirement` (`mapId`, `difficulty`, `dungeonId`, `level_min`, `level_max`, `item_level`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `completed_achievement_A`, `quest_failed_text`, `comment`) values
('1136','7','0','90','0','496','0','0','0','0','0','0',NULL,'Siege of Orgrimmar - LFR'),
('1136','14','771','90','0','510','0','0','0','0','0','0',NULL,'Siege of Orgrimmar - Flex'),
('1136','14','772','90','0','517','0','0','0','0','0','0',NULL,'Siege of Orgrimmar - Flex'),
('1136','14','773','90','0','524','0','0','0','0','0','0',NULL,'Siege of Orgrimmar - Flex'),
('1136','14','774','90','0','531','0','0','0','0','0','0',NULL,'Siege of Orgrimmar - Flex'),
('1136','7','717','90','0','496','0','0','0','0','8458','0',NULL,'Расплата у врат - LFR'),
('1136','7','724','90','0','496','0','0','0','0','8459','0',NULL,'Подземная крепость - LFR'),
('1136','7','725','90','0','496','0','0','0','0','8461','0',NULL,'Низвержение - LFR'),
('996','7','0','90','0','470','0','0','0','0','0','0',NULL,'Терраса Вечной Весны - LFR'),
('1008','7','0','90','0','460','0','0','0','0','0','0',NULL,'Подземелья Могу\'шан - LFR'),
('1008','7','528','90','0','460','0','0','0','0','6458','0',NULL,'Хранилище тайн - LFR'),
('1098','7','0','90','0','480','0','0','0','0','0','0',NULL,'Престол Гроз - LFR'),
('1098','7','611','90','0','480','0','0','0','0','8069','0',NULL,'Забытые глубины - LFR'),
('1098','7','612','90','0','480','0','0','0','0','8070','0',NULL,'Залы Искажения Плоти - LFR'),
('1098','7','613','90','0','480','0','0','0','0','8071','0',NULL,'Вершина Бурь - LFR'),
('1009','7','0','90','0','470','0','0','0','0','0','0',NULL,'Heart of Fear - LFR'),
('1009','7','530','90','0','470','0','0','0','0','6718','0',NULL,'Кошмар Шек\'зир - LFR');


replace into `access_requirement` (`mapId`, `difficulty`, `dungeonId`, `level_min`, `level_max`, `item_level`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `completed_achievement_A`, `quest_failed_text`, `comment`) values
('999','12','0','90','0','425','0','0','0','0','0','0',NULL,'Theramore\'s Fall (Horde) - Normal'),
('1000','12','0','90','0','425','0','0','0','0','0','0',NULL,'Theramore\'s Fall (Alliance) - Normal scenario'),
('1048','12','0','90','0','425','0','0','0','0','0','0',NULL,'Unga Ingoo - Normal scenario?'),
('1104','11','0','90','0','0','0','0','0','0','0','0',NULL,'Немного терпения - Heroic scenario'),
('1104','12','0','90','0','425','0','0','0','0','0','0',NULL,'Немного терпения - Normal scenario'),
('1102','12','0','90','0','425','0','0','0','0','0','0',NULL,'Крепость Покорителей - Normal scenario'),
('1103','11','0','90','0','0','0','0','0','0','0','0',NULL,'Львиный лагерь - Heroic scenario'),
('1103','12','0','90','0','425','0','0','0','0','0','0',NULL,'Львиный лагерь - Normal scenario'),
('-1','12','493','90','0','425','0','0','0','0','0','0',NULL,'Случайный сценарий Mists of Pandaria'),
('1050','12','0','90','0','425','0','0','0','0','0','0',NULL,'Assault on Zan\'vess - Normal scenario'),
('1051','12','0','90','0','425','0','0','0','0','0','0',NULL,'Brewmoon Festival - Normal scenario'),
('1031','12','0','90','0','425','0','0','0','0','0','0',NULL,'Arena of Annihilation - Normal scenario'),
('1005','12','0','90','0','425','0','0','0','0','0','0',NULL,'A Brewing Storm - Normal scenario'),
('1030','12','0','90','0','425','0','0','0','0','0','0',NULL,'Crypt of Forgotten Kings - Normal scenario'),
('1024','12','0','90','0','425','0','0','0','0','0','0',NULL,'Greenstone Village - Normal scenario'),
('1130','12','0','90','0','425','0','0','0','0','0','0',NULL,'Кровь на снегу - Normal scenario'),
('1099','12','0','90','0','429','0','0','0','0','0','0',NULL,'Битва в открытом море - Normal scenario'),
('1144','12','0','90','0','425','0','0','0','0','0','0',NULL,'Темное сердце Пандарии - Normal scenario'),
('1095','12','0','90','0','425','0','0','0','0','0','0',NULL,'Dagger in the Dark - Normal scenario'),
('1131','12','0','90','0','425','0','0','0','0','0','0',NULL,'Секреты Огненной Пропасти - Normal scenario');

insert ignore into `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) values
('2','999','7','','','Theramore scenario'),
('2','1000','7','','','Theramore scenario'),
('2','1048','7','','','Unga Ingoo - scenario'),
('2','1104','7','','','Немного терпения - scenario'),
('2','1102','7','','','Крепость Покорителей - scenario'),
('2','1103','7','','','Львиный лагерь - scenario'),
('2','1050','7','','','Assault on Zanvess - scenario'),
('2','1051','7','','','Brewmoon Festival - scenario'),
('2','1005','7','','','A Brewing Storm - scenario'),
('2','1030','7','','','Crypt of Forgotten Kings - scenario'),
('2','1024','7','','','Greenstone Village - scenario'),
('2','1130','7','','','Кровь на снегу - scenario'),
('2','1099','7','','','Битва в открытом море - scenario'),
('2','1144','7','','','Темное сердце Пандарии - scenario'),
('2','1095','7','','','Dagger in the Dark - scenario'),
('2','1131','7','','','Секреты Огненной Пропасти - scenario');

replace into `access_requirement` (`mapId`, `difficulty`, `dungeonId`, `level_min`, `level_max`, `item_level`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `completed_achievement_A`, `quest_failed_text`, `comment`) values
('960','1','0','85','0','358','0','0','0','0','0','0',NULL,'Temple of the Jade Serpent'),
('960','2','0','90','0','440','0','0','0','0','0','0',NULL,'Temple of the Jade Serpent'),
('961','1','0','85','0','358','0','0','0','0','0','0',NULL,'Stormstout Brewery'),
('961','2','0','90','0','440','0','0','0','0','0','0',NULL,'Stormstout Brewery'),
('962','1','0','88','0','393','0','0','0','0','0','0',NULL,'Gate of the Setting Sun'),
('962','2','0','90','0','440','0','0','0','0','0','0',NULL,'Gate of the Setting Sun'),
('994','1','0','87','0','393','0','0','0','0','0','0',NULL,'Mogu\'shan Palace'),
('994','2','0','90','0','440','0','0','0','0','0','0',NULL,'Mogu\'shan Palace'),
('959','1','0','87','0','393','0','0','0','0','0','0',NULL,'Shado-Pan Monastery'),
('959','2','0','90','0','440','0','0','0','0','0','0',NULL,'Shado-Pan Monastery'),
('1011','1','0','87','0','393','0','0','0','0','0','0',NULL,'Siege of Niuzao Temple'),
('1011','2','0','90','0','440','0','0','0','0','0','0',NULL,'Siege of Niuzao Temple');
