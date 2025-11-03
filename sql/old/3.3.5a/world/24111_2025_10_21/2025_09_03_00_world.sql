DELETE FROM `quest_greeting_locale` WHERE `ID` IN (2080,2083,3446,3567,3845,4077,4078,4080,4201,4453,5638,1141,4048,4630,7407,7877,7882,7900,17433) AND `locale`='ruRU';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(2080, 0, 'ruRU', 'Создание Тельдрассила было огромным достижением, но теперь, чтобы восстановить равновесия, мир должен измениться.', 12340),
(2083, 0, 'ruRU', 'Как и сам Тельдрассил, Доланаар принимает тех, кто принимает эту землю.', 12340),
(3446, 0, 'ruRU', 'Да, да, да! Именно тебя мне и нужно, $r!$B$BПрисаживайся! Нам нужно многое обсудить!', 12340),
(3567, 0, 'ruRU', 'Приятно встретить вас, $n. Хорошо, что такой $c как вы, принимает активное участие в защите рощ.', 12340),
(3845, 0, 'ruRU', 'У нас эльфов большая история. Будем надеяться, что она никогда не повторится, и не будет преследовать нас.', 12340),
(4077, 0, 'ruRU', 'Если я заполучу все необходимые ингредиенты, я смогу создать взрывчатку, которая не только нанесет урон Торговой Компании, но еще и отвлечет ее.$B$BЯ знаю что тебя это впечатлило, но еще лучше... обо всем остальном я расскажу тебе позже.', 0),
(4078, 0, 'ruRU', 'Приветствую, $gдруг:подруга;. Что я могу сделать для вас?', 12340),
(4080, 0, 'ruRU', 'Приветствую, $n.', 12340),
(4201, 0, 'ruRU', 'Приветствую, $n.', 12340),
(4453, 0, 'ruRU', 'Будьте осторожны, куда ставите ногу, $gсэр: мэм;. Не все мы наделены таким высоким ростом, как у $r.', 12340),
(5638, 0, 'ruRU', 'У меня много дел здесь в Пустошах, $n. Ройттен хочет, чтобы мы забрали некоторые реагенты для одного из наших клиентов, а также доставили несколько утраченных предметов.$B$BПохоже, что ты здесь чтобы помочь нам, так почему бы нам не начать?', 0),
(1141, 0, 'ruRU', 'Если вы здесь ради еды, тогда добро пожаловать! Вы не найдете еду лучше во всем Штормграде... или Азероте!$B$BЕсли вы здесь по другим вопросам, тогда, пожалуйста, давайте быстрее. У меня готовится очень много блюд и мне нужно позаботиться о каждом из них.', 12340),
(4048, 0, 'ruRU', 'Приветствую, $n.', 12340),
(4630, 0, 'ruRU', 'Приветствую, $n.', 12340),
(7407, 0, 'ruRU', 'Меня зовут Чепухастер и я главный инженер компании "Воды Прибамбасска". Чем я могу помочь тебе?', 12340),
(7877, 0, 'ruRU', 'Приветствую, $n.', 12340),
(7882, 0, 'ruRU', 'Мы здесь ради прибыли, а украденные товары этому не способствуют.', 12340),
(7900, 0, 'ruRU', 'Привет, $n. У тебя не найдется времени поговорить?', 12340),
(17433, 0, 'ruRU', 'Приветствую, $n.', 12340);


UPDATE `quest_template_locale` SET `EndText`='Мелицца Жужжалит провождена в безопасное место.' WHERE `ID`=6132 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `Title`='Отшельник сторожки "Болотный огонек"' WHERE `ID`=11177 AND `locale`='ruRU';

UPDATE `quest_request_items_locale` SET `CompletionText`='Ты что-то мне $gпринес:принесла;?' WHERE `ID`=931 AND `locale`='ruRU';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Где ты это $gнашел:нашла;? Я не видел таких растений с тех пор, как жил на Болоте Печали. А это было много десятилетий назад! Удивительно, как он попал в Тельдрассил. Да еще вырос до такой величины!$B$BСпасибо тебе, $N. Прости мою немногословность, но мне не терпится провести кое-какие опыты с этим ростком...' WHERE `ID`=931 AND `locale`='ruRU';


UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Талену в Ясеневый лес.' WHERE `ID`=1007 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Шиндрелл Огненному Всполоху в Астранаар, что в Ясеневом лесу.' WHERE `ID`=1008 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Талену в Ясеневый лес.' WHERE `ID`=1009 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Орендилу Широколисту на Заставу Мейстры, что в Ясеневом лесу.' WHERE `ID`=1010 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Кайнету Штилю в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=1011 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Кайнету Штилю в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=1012 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к часовому Велене Звездный Всполох в Приют Серебряного Ветра, что в Ясеневом лесу.' WHERE `ID`=1017 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к часовому Мелирии Ледяной Тени в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=1022 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Раэне Волкопас в Астранаар, что в Ясеневом лесу.' WHERE `ID`=1023 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Раэне Волкопас в Астранаар, что в Ясеневом лесу.' WHERE `ID`=1025 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Шаэл''дрин в Ясеневый лес.' WHERE `ID`=1027 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Пельтуру Белой Луне в Астранаар, что в Ясеневом лесу.' WHERE `ID`=1035 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Поговорите с клерком Далтри в Темнолесье, что в Сумеречном лесу.' WHERE `ID`=1041 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Джонатану Карвину в Темнолесье, что в Сумеречном лесу.' WHERE `ID`=1043 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Шиндрелл Огненному Всполоху в Астранаар, что в Ясеневом лесу.' WHERE `ID`=1134 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к капралу Мелкису на Высоту Найджела, что в Пустошах.' WHERE `ID`=1387 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Далинде Малем в Пустоши.' WHERE `ID`=1439 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Валлариелю Истребителю Демонов на Высоту Найджела, что в Пустошах.' WHERE `ID`=1440 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Крелдигу Унгору на Высоту Найджела, что в Пустошах.' WHERE `ID`=1456 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Крелдигу Унгору на Высоту Найджела, что в Пустошах.' WHERE `ID`=1459 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Крелдигу Унгору на Высоту Найджела, что в Пустошах.' WHERE `ID`=1466 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Смиду Заржавеню в Лагерь Заржавня, что в Пустошах.' WHERE `ID`=5561 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к сундуку Ракмора на Побережье Сар''Терис, что в Пустошах.' WHERE `ID`=6161 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к воздаятелю Ведаару в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=9516 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Кривокрону в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=9517 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к часовому Люсьели Шепоту Звезд в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=9518 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к воздаятелю Ведаару в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=9522 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Кривокрону в Лесную Песнь, что в Ясеневом лесу.' WHERE `ID`=9526 AND `locale`='ruRU';


DELETE FROM `gameobject_template_locale` WHERE `entry` IN (149480,149481,149482,149483) AND `locale`='ruRU';
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`) VALUES
(149480, 'ruRU', 'Руна Джин''яэль', '', 0),
(149481, 'ruRU', 'Руна Бет''Амары', '', 0),
(149482, 'ruRU', 'Руна Маркри', '', 0),
(149483, 'ruRU', 'Руна Саэл''Хаи', '', 0);
