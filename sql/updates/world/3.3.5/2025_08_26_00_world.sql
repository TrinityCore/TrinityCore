--
DELETE FROM `gameobject_template_locale` WHERE `entry` IN (175329,175330,175331) AND `locale`='ruRU';
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`) VALUES
(175329, 'ruRU', 'Ореховый склад Чернолесья', 'Изучение', 0),
(175330, 'ruRU', 'Фруктовый склад Чернолесья', 'Изучение', 0),
(175331, 'ruRU', 'Зернохранилище племени Чернолесья', 'Изучение', 0);


DELETE FROM `quest_greeting_locale` WHERE `ID` IN (3649,5396) AND `locale`='ruRU';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(3649, 0, 'ruRU', 'Темные силы посягают на наши границы, возрождается древняя зараза, появляется новое зло желающее разрушить тонкий баланс земли. В эти темные времена мы все должны быть бдительны.', 12340),
(5396, 0, 'ruRU', 'Альянс имеет много ставок здесь в Пустошах, и наша позиция здесь неустойчива.$B$BПоможете ли вы нам?', 12340);


UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к археологу Холли в Аубердин, что на Темных берегах.' WHERE `ID`=731 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Жужжалке 827 в Аубердин, что на Темных берегах.' WHERE `ID`=983 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Терентису в Аубердин, что на Темных берегах.' WHERE `ID`=984 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к археологу Бутылопузу в Гавань Менетилов, что в Болотине.' WHERE `ID`=943 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тересили.' WHERE `ID`=945 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Баритасу Лунному Сумраку в Аубердин, что на Темных берегах.' WHERE `ID`=947 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Ону в Сумеречную долину, что на Темных берегах.' WHERE `ID`=951 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к часовому Тише Лунному Клинку в Амет''Аран, что на Темных берегах.' WHERE `ID`=953 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Астериону в Туманный Предел, что на Темных берегах.' WHERE `ID`=955 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Астериону в Туманный Предел, что на Темных берегах.' WHERE `ID`=956 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Астериону в Туманный Предел, что на Темных берегах.' WHERE `ID`=957 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тандрису Ветропряду в Аубердин, что на Темных берегах.' WHERE `ID`=958 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Кириллиану Белому Когтю в Туманный Предел, что на Темных берегах.' WHERE `ID`=963 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Балтулу Удару Тени на Темные берега.' WHERE `ID`=966 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Горбольду Сталеруку в Аубердин, что на Темных берегах.' WHERE `ID`=982 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Терентису в Аубердин, что на Темных берегах.' WHERE `ID`=985 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Терентису в Аубердин, что на Темных берегах.' WHERE `ID`=986 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Терентису в Аубердин, что на Темных берегах.' WHERE `ID`=994 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Терентису в Аубердин, что на Темных берегах.' WHERE `ID`=995 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Жужжалке 411 на Туманный Предел, что на Темных берегах.' WHERE `ID`=1001 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Жужжалке 323 у Реки Скалистой, что на Темных берегах.' WHERE `ID`=1002 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Жужжалке 525 на Сумеречную излучину, что на Темных берегах.' WHERE `ID`=1003 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Грубберу Блумпу в Аубердин, что на Темных берегах.' WHERE `ID`=1138 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Балтулу Удару Тени на Темные берега.' WHERE `ID`=1143 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Гелхаку Гиромачту в Туманный Предел, что на Темных берегах.' WHERE `ID`=2078 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Гелхаку Гиромачту в Туманный Предел, что на Темных берегах.' WHERE `ID`=2098 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тарнариуну Исцелителю Деревьев в Аубердин, что на Темных берегах.' WHERE `ID`=2118 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тарнариуну Исцелителю Деревьев в Аубердин, что на Темных берегах.' WHERE `ID`=2138 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тарнариуну Исцелителю Деревьев в Аубердин, что на Темных берегах.' WHERE `ID`=2139 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Гвеннид Блай''леггонд в Аубердин, что на Темных берегах.' WHERE `ID`=3524 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Гвеннид Блай''леггонд в Аубердин, что на Темных берегах.' WHERE `ID`=4681 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к часовому Глинде Нал''шии в Аубердин, что на Темных берегах.' WHERE `ID`=4740 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тандрису Ветропряду в Аубердин, что на Темных берегах.' WHERE `ID`=4762 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Тандрису Ветропряду в Аубердин, что на Темных берегах.' WHERE `ID`=4763 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к часовому Глинде Нал''шии в Аубердин, что на Темных берегах.' WHERE `ID`=4811 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к таинственному красному кристаллу на Темных берегах.' WHERE `ID`=4812 AND `locale`='ruRU';
UPDATE `quest_template_locale` SET `CompletedText`='Вернитесь к Лиладрису Лунной Реке в Ясеневый лес.' WHERE `ID`=5321 AND `locale`='ruRU';
