-- Add ruRU offer rewards for quest 787
-- 
SET @ID := 787;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Еще один из новобранцев Эйтригга, хм? В каком плачевном положении мы оказались, если это лучшее, что может произвести Орда. Неважно. К тому времени, когда мы решим, что вы готовы покинуть Долину, вы будете гордиться собой.', 0);

-- Add ruRU offer rewards for quest 1800
-- https://wowroad.info/goha.ru?quest=1800
SET @ID := 1800;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эта тронная комната наводит ужас, $N! Хоть даже она и пуста, но в этих стенах чувствуется, что великое зло. Я чувствую гнев... но также и горечь. Я понимаю, почему няньки рассказывают нам подобные истории; я никогда не предам свой народ подобным образом!$B$BБлагодарю тебя за то, что ты $Gпроводил:проводила; меня в тронную комнату, $N. Я многому научился здесь.', 0);

-- Add ruRU offer rewards for quest 1802
-- https://ru.tbc.wowhead.com/quest=1802/фолиант-заговора
SET @ID := 1802;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'С ума сойти! Теперь я один из немногих, что сумел хоть мельком заглянуть в нее.$B$BНе терпится повнимательнее изучить этот текст. Какой великий день, $N! Позволь мне еще раз заглянуть в нее прежде, чем уйдешь. Уверен, что Страхад охотно пришлет мне копию.', 0);

-- Add ruRU offer rewards for quest 1804
-- https://ru.tbc.wowhead.com/quest=1804/фолиант-заговора
SET @ID := 1804;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Фолиант Заговора и три практически нетронутых жезла направления.$B$BЗабавно выходит. Давно молодые чернокнижники не приручали охотников Скверны.', 0);

-- Add ruRU offer rewards for quest 1805
-- https://ru.tbc.wowhead.com/quest=1805/фолиант-заговора
SET @ID := 1805;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Фолиант Заговора и три практически нетронутых жезла направления.$B$BЗабавно выходит. Давно молодые чернокнижники не приручали охотников Скверны.', 0);

-- Add ruRU offer rewards for quest 1818
-- https://ru.tbc.wowhead.com/quest=1818/разговор-с-диллинджером
SET @ID := 1818;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хочешь получить задание? Отлично. У меня есть одно. Довольно важное. Заодно и свою силу нам покажешь... И решимость защищать дело Отрекшихся.', 0);

-- Add ruRU offer rewards for quest 1819
-- https://ru.tbc.wowhead.com/quest=1819/улаг-колун
SET @ID := 1819;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Молодец, $N. Улаг был серьезным сторонником Плети. Тебе удалось доказать стражам смерти и через них Темной Госпоже, что ты опытный и умелый воин и заслуживаешь дальнейшего обучения.', 0);

-- Add ruRU offer rewards for quest 1820
-- https://ru.tbc.wowhead.com/quest=1820/разговор-с-колманом
SET @ID := 1820;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это правда. Мне нужна помощь закаленного воина. Средств у меня немного, зато ты послужишь не только мне, но и делу Отрекшихся. Так что если ты справишься, наградой будет почет.', 0);

-- Add ruRU offer rewards for quest 1821
-- https://ru.tbc.wowhead.com/quest=1821/наследие-агамондов
SET @ID := 1821;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А! Вот оно! Итак, проклятые земли Агамондов лишены остатков чести и памяти. Отныне семьи воистину не существует!', 0);

-- Add ruRU offer rewards for quest 1822
-- https://ru.tbc.wowhead.com/quest=1822/фамильное-оружие
SET @ID := 1822;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я оставлю принесенное тобой оружие на память о понесенных потерях. Впрочем, ты можешь выбрать наиболее полюбившуюся тебе вещь и оставить ее себе.$B$BДа послужит она тебе лучше, чем прежним проклятым владельцами.', 0);

-- Add ruRU offer rewards for quest 1823
-- https://ru.tbc.wowhead.com/quest=1823/разговор-с-ругой
SET @ID := 1823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хочешь пройти испытание, $N?', 0);

-- Add ruRU offer rewards for quest 1824
-- https://ru.tbc.wowhead.com/quest=1824/испытание-на-полях-великанов
SET @ID := 1824;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N! Ты $Gпрошел:прошла; испытание на Полях Великанов, сделав тем самым еще один шаг по тропе воина.', 0);

-- Add ruRU offer rewards for quest 1825
-- https://ru.tbc.wowhead.com/quest=1825/разговор-с-тунгримом
SET @ID := 1825;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, ты $Gпришел:пришла;. Отлично, нам с тобой многое придется обсудить.', 0);

-- Add ruRU offer rewards for quest 1838
-- https://ru.tbc.wowhead.com/quest=1838/доспехи-жестокости
SET @ID := 1838;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринес:принесла; все, что я просил. Теперь дело за мной...', 0);

-- Add ruRU offer rewards for quest 1839
-- https://ru.tbc.wowhead.com/quest=1839/улаелек-и-рукавицы-жестокости
SET @ID := 1839;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, $N. Старый Тунгрим предупредил меня о твоем приходе, но умолчи он, я не удивился бы твоему появлению.$B$BДухи следят за каждым твоим шагом, юный воин, и они говорят, что от твоей руки пало немало врагов.', 0);

-- Add ruRU offer rewards for quest 1840
-- https://ru.tbc.wowhead.com/quest=1840/орм-каменное-копыто-и-шлем-жестокости
SET @ID := 1840;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, воин. Я Орм. Тунгрим сказал, что тебе нужен шлем. Это правда?', 0);

-- Add ruRU offer rewards for quest 1841
-- https://ru.tbc.wowhead.com/quest=1841/велора-нители-и-набедренники-жестокости
SET @ID := 1841;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе нужны набедренники? Отлично!$B$BХм... Тогда кто из нас будет их делать?$B$BШутка. Смешно? Я вот не понимаю... Чувство юмора я утратила одновременно с обонянием. Примерно в те времена, как перестала дышать.', 0);

-- Add ruRU offer rewards for quest 1842
-- https://ru.tbc.wowhead.com/quest=1842/копыта-сатиров
SET @ID := 1842;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага, вот и они! Сатиры похитили силу Ясеневого леса, а их сила вольется в мое творение...', 0);

-- Add ruRU offer rewards for quest 1843
-- https://ru.tbc.wowhead.com/quest=1843/рукавицы-жестокости
SET @ID := 1843;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Эти рукавицы – мое величайшее достижение. Возьми их. Ты окажешь мне честь, если пойдешь в них в бой.', 0);

-- Add ruRU offer rewards for quest 1844
-- https://ru.tbc.wowhead.com/quest=1844/рог-химеры
SET @ID := 1844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, задание выполнено, $N. Теперь я не сомневаюсь в твоей решимости и храбрости. Ты $Gзаслужил:заслужила; шлем...', 0);

-- Add ruRU offer rewards for quest 1845
-- https://ru.tbc.wowhead.com/quest=1845/шлем-жестокости
SET @ID := 1845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Возьми этот шлем.$B$BТебя привели ко мне великие свершения, и если Матери-земле будет угодно... тебе предстоит немало подвигов.', 0);

-- Add ruRU offer rewards for quest 1846
-- https://ru.tbc.wowhead.com/quest=1846/берцовые-кости
SET @ID := 1846;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;! На вид они крепкие. Пожалуй, подойдут. Орки не возражали? Сильно жаловались?$B$BОпять я пошутила. Ты не смеешься.$B$BЧто-то у меня не так с чувством юмора...', 0);

-- Add ruRU offer rewards for quest 1847
-- https://ru.tbc.wowhead.com/quest=1847/набедренники-жестокости
SET @ID := 1847;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твои набедренники, $N. Ну как, подходят? Или надо что-то менять? Мне хочется угодить заказчику! По крайней мере всегда хотелось.$B$BТеперь ремесло утратило прежнюю прелесть. Но все лучше, чем быть безмозглым рабом Плети!$B$BНаверное.', 0);

-- Add ruRU offer rewards for quest 1848
-- https://ru.tbc.wowhead.com/quest=1848/хауберк-жестокости
SET @ID := 1848;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе несомненно пришлось пролить немало крови, чтобы справиться с моим заданием, $N. Вот плод твоих трудов.$B$BНоси с удовольствием. Как-нибудь заходи, расскажешь, как он тебе пригодился в бою.', 0);

-- Add ruRU offer rewards for quest 1858
-- https://ru.tbc.wowhead.com/quest=1858/изувеченная-длань
SET @ID := 1858;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так-так, интересно... Что ж, $N, ты полностью $Gоправдал:оправдала; мое доверие. Отныне можешь считать себя членом клана Изувеченной Длани. И возьми это. Думаю, он тебе очень пригодится в будущем.', 0);

-- Add ruRU offer rewards for quest 1859
-- https://ru.tbc.wowhead.com/quest=1859/терзок
SET @ID := 1859;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, это ты! Очень хорошо, что Каплак сумел тебя перехватить.$B$BНам нужно поговорить кое о чем, не в последнюю очередь – о твоем будущем в Раздробленной Руке.', 0);

-- Add ruRU offer rewards for quest 1860
-- https://ru.tbc.wowhead.com/quest=1860/поговорите-с-джиннией
SET @ID := 1860;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебя послали мне на подмогу, $N? Хорошо. Приятно видеть, что молодые маги рады внести свой вклад в общее дело…$B$BКакое дело, спросишь ты? Вырастешь – узнаешь. Обязательно узнаешь... со временем.', 0);

-- Add ruRU offer rewards for quest 1861
-- https://ru.tbc.wowhead.com/quest=1861/зеркальное-озеро
SET @ID := 1861;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Я исследую магические свойства этой воды. Будем надеяться, что их не окажется, а то, неровен час, окажется, что магия повлияла на всех, кто пил много воды из Зеркального озера.$B$BВозьми эту сферу или этот посох в знак моей благодарности за услугу. Пускай они служат тебе верой и правдой.', 0);

-- Add ruRU offer rewards for quest 1879
-- https://ru.tbc.wowhead.com/quest=1879/поговорите-с-бинк
SET @ID := 1879;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, я вижу в тебе неплохие задатки, да-да! Но чтобы стать хорошим магом, одних задатков мало. А не сликшом хороший маг – плохой маг. А из-за плохих магов и возникают все проблемы!$B$BОй, кажется, я немного забегаю вперед. Начнем сначала!', 0);

-- Add ruRU offer rewards for quest 1880
-- https://ru.tbc.wowhead.com/quest=1880/маг-тастический-гизмонитор
SET @ID := 1880;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, радость! Создавая гизмонитор, я и не догадывалась, в какую зависимость от него попаду! Теперь я могу возобновить свои исследования.$B$BСпасибо, $N! Вот, смотри. Это мой первый набор магических инструментов. Они не так блестят, как новые, зато проверены временем. Выбирай любой из них – все они могут тебе пригодиться.', 0);

-- Add ruRU offer rewards for quest 1881
-- https://ru.tbc.wowhead.com/quest=1881/разговор-с-анастасией
SET @ID := 1881;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, $N. Ты правильно $Gпоступил:поступила;, откликнувшись на мой зов, но еще правильнее будет меня выслушать...', 0);

-- Add ruRU offer rewards for quest 1882
-- https://ru.tbc.wowhead.com/quest=1882/ферма-балнира
SET @ID := 1882;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличные цветы. Я отправлю их на изучение нашим аптекарям. Пусть поищут в них скверну Проклятых земель.$B$BМолодец, $N. Я предлагаю тебе выбрать награду – сферу или посох. И то, и другое может тебе здорово пригодиться.', 0);

-- Add ruRU offer rewards for quest 1883
-- https://ru.tbc.wowhead.com/quest=1883/разговор-с-унтувой
SET @ID := 1883;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, $N. Хвала тебе, ибо ты $Gответил:ответила; на мой зов о помощи. Будем надеяться, что ты справишься с заданием...', 0);

-- Add ruRU offer rewards for quest 1884
-- https://ru.tbc.wowhead.com/quest=1884/груды-джуджу
SET @ID := 1884;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я чувствую, что груды джуджу уничтожены. При удаче все труды Залазана пойдут насмарку и в Дуротаре восстановится нормальное течение магической энергии.$B$BТвой подвиг во имя Орды достоин всяческой хвалы!', 0);

-- Add ruRU offer rewards for quest 1919
-- https://ru.tbc.wowhead.com/quest=1919/задание-джиннии
SET @ID := 1919;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N, у меня есть для тебя задание. Да-да, прямо здесь, в квартале магов. Слушай внимательно, не будем терять время даром.', 0);

-- Add ruRU offer rewards for quest 1920
-- https://ru.tbc.wowhead.com/quest=1920/синий-отшельник
SET @ID := 1920;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну ты $Gмолодец:умница;! Я займусь изучением этих существ, и при удаче пойму, как они ухитрились пробраться в наш мир.$B$BТы приносишь сообществу магов все больше пользы, $N.', 0);

-- Add ruRU offer rewards for quest 1921
-- https://ru.tbc.wowhead.com/quest=1921/сбор-материалов
SET @ID := 1921;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, превосходный лен. Из него выйдет отличная ряса. А после того, как я разошью ее самоцветами, получится настоящее одеяние для мага!', 0);

-- Add ruRU offer rewards for quest 1938
-- https://ru.tbc.wowhead.com/quest=1938/трактат-ура-по-темной-магии
SET @ID := 1938;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я опасался, что Моргант спрятал книгу где-то еще или же нашел способ открыть ее и прочесть.$B$BХорошо, что он не успел, и что все печати, наложенные на этот трактат, сохранились в целости.', 0);

-- Add ruRU offer rewards for quest 1939
-- https://ru.tbc.wowhead.com/quest=1939/верховный-колдун-андромат
SET @ID := 1939;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, $N. Рад тебя видеть. Надеюсь, у тебя найдется время выслушать старика...', 0);

-- Add ruRU offer rewards for quest 1940
-- https://ru.tbc.wowhead.com/quest=1940/безупречная-паутина
SET @ID := 1940;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Неплохая паутина. Я немедленно примусь за работу!', 0);

-- Add ruRU offer rewards for quest 1941
-- https://ru.tbc.wowhead.com/quest=1941/одеяние-из-ткани-маны
SET @ID := 1941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твое одеяние. Один из моих шедевров! Носи на здоровье, а если тебя спросят, кто шил... Посоветуй им обратиться в суконную лавку Ларсона!', 0);

-- Add ruRU offer rewards for quest 1942
-- https://ru.tbc.wowhead.com/quest=1942/одеяние-волшебного-плетения
SET @ID := 1942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое одеяние готово! Отличный шелк тебе достался... Ты уж прости, одеяние получилось довольно короткое, часть шелка я себе оставила.$B$BШучу, шучу. Оно тебе идеально подойдет, причем будет уместно смотреться как в бою, так и на торжественном обеде. Наслаждайся!', 0);

-- Add ruRU offer rewards for quest 1943
-- https://ru.tbc.wowhead.com/quest=1943/разговор-с-дейно
SET @ID := 1943;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что ты здесь. Я хочу дать тебе довольно сложное задание. Оно жизненно важно для всего сообщества магов. Помоги мне, и маги отплатят тебе сторицей.', 0);

-- Add ruRU offer rewards for quest 1944
-- https://ru.tbc.wowhead.com/quest=1944/воды-ксавиана
SET @ID := 1944;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, отлично. Надеюсь, сатиры Ксавиана тебе не слишком сильно помешали?$B$BСпасибо, $N. Я немедленно займусь изучением пробы воды из Ксавиана.', 0);

-- Add ruRU offer rewards for quest 1945
-- https://ru.tbc.wowhead.com/quest=1945/смеющиеся-сестры
SET @ID := 1945;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, из этих волос выйдет отличное одеяние. Жаль, что приходится убивать Смеющихся сестер ради добычи волос, впрочем, добровольно они их все равно не отдали бы.$B$BЖаль, но не очень.', 0);

-- Add ruRU offer rewards for quest 1946
-- https://ru.tbc.wowhead.com/quest=1946/одеяние-из-кружева-пустоты
SET @ID := 1946;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твое пустокружево. Оно прочное и удобное и хранит в себе магию волос Смеющейся сестрички.$B$BНаслаждайся. Если понравится, не забудь упомянуть об этом в разговоре с Дейно. Вот уж с кем бы не хотелось ссориться...', 0);

-- Add ruRU offer rewards for quest 1947
-- https://ru.tbc.wowhead.com/quest=1947/путь-в-болото
SET @ID := 1947;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твое пустокружево. Оно прочное и удобное и хранит в себе магию волос Смеющейся сестрички.$B$BНаслаждайся. Если понравится, не забудь упомянуть об этом в разговоре с Дейно. Вот уж с кем бы не хотелось ссориться...', 0);

-- Add ruRU offer rewards for quest 1948
-- https://ru.tbc.wowhead.com/quest=1948/волшебные-предметы
SET @ID := 1948;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага! Тебе удалось найти нефрит и сделать шипастый жезл! $GМолодец:Умница;!$B$BУ тебя что, из ушей дым идет? Наверное, ты $Gподошел:подошла; слишком близко, когда молния била в заготовки. Такое случается. Не расстраивайся, получить удар молнии – хорошая примета!', 0);

-- Add ruRU offer rewards for quest 1949
-- https://ru.tbc.wowhead.com/quest=1949/великие-тайны
SET @ID := 1949;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что? Говори громче! У меня не такой острый слух, как бывало.$B$BНадеюсь, ты несешь мне кружку свежего эля или верные сведениями о следующей гонке! Если нет, проваливай... А то у меня наготове жезл превращения!', 0);

-- Add ruRU offer rewards for quest 1950
-- https://ru.tbc.wowhead.com/quest=1950/волшебное-слово
SET @ID := 1950;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах да, припоминаю…$B$BЯ и правда наложил на Джонсона проклятье. Не помню, зачем я это сделал, но так ему и надо, маленькому нахалу!', 0);

-- Add ruRU offer rewards for quest 1951
-- https://ru.tbc.wowhead.com/quest=1951/обряды-силы
SET @ID := 1951;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот она! То что нужно для последнего обряда создания жезла! Надеюсь, поиски были не слишком сложными?', 0);

-- Add ruRU offer rewards for quest 1952
-- https://ru.tbc.wowhead.com/quest=1952/магический-жезл
SET @ID := 1952;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну вот, жезлы готовы. Выбирай любой!', 0);

-- Add ruRU offer rewards for quest 1953
-- https://ru.tbc.wowhead.com/quest=1953/назад-в-болото
SET @ID := 1953;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, да. Тебе нужна сфера или жезл? Ну, хорошо. Я помогу тебе.$B$BВпрочем, знай. Это очень опасно и может привести к твоей гибели.$B$BИли моей гибели. В общем, кому-то умереть придется…$B$BБудем надеяться, что не нам, а?', 0);

-- Add ruRU offer rewards for quest 1954
-- https://ru.tbc.wowhead.com/quest=1954/сфера-подземного-огня
SET @ID := 1954;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага, недурная сфера. Не в том смысле недурная, как охлажденная вода с соком в жаркий день.$B$BБолее того, она вовсе НЕ недурная, если посмотреть повнимательнее. Да не вода, сфера!$B$BСосредоточься, $N! Иначе с этим заданием не справиться!', 0);

-- Add ruRU offer rewards for quest 1955
-- https://ru.tbc.wowhead.com/quest=1955/поединок-с-демоном
SET @ID := 1955;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно, $N. Тебе удалось преподать этому демону урок, который он надолго запомнит.$B$BТеперь он трижды подумает, прежде чем вновь сунуться в наш мир. Однако если это произойдет, единственной целью демона будет найти того дерзкого смертного, что одолел его когда-то. Скорее всего, он вернется с приятелями. Огромными, жуткими приятелями, жаждущими твоей крови.$B$BНу что, $N, тебе уже страшно?', 0);

-- Add ruRU offer rewards for quest 1956
-- https://wowroad.info/goha.ru?quest=1956
SET @ID := 1956;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gсделал:сделала; это? $GМолодец:Умница;.$B$BЯ общалась с некоторыми моими коллегами и когда я случайно назвала твое имя, то они сказали: "Да, мы знаем $N, и $Gон:она; не поддается стрессу, даже в критических ситуациях".$B$BНо когда я сказала, что послала тебя в Ульдаман против обсидианового стражника, они не поверили, что ты выполнишь задачу. А я сказала им – вот увидите!$B$BЧто-ж, мы им показали, не так ли?', 0);

-- Add ruRU offer rewards for quest 1957
-- https://ru.tbc.wowhead.com/quest=1957/волнолов-маны
SET @ID := 1957;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Надо же, ты $Gсправился:справилась;! Я в тебе не сомневалась! Ну ладно, чуть-чуть сомневалась, даже не чуть-чуть... Но не так уж сильно.$B$BЧестно.', 0);

-- Add ruRU offer rewards for quest 1958
-- https://wowroad.info/goha.ru?quest=1958
SET @ID := 1958;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gдолжен:должна; гордиться собой, $N. Не многие справились с теми трудностями, с которыми пришлось тебе столкнуться.$B$BНебесная сфера готова или я могу сделать посох. Все зависит от тебя. Я бы предпочла сферу, но кто я такая, чтобы судить?', 0);

-- Add ruRU offer rewards for quest 1959
-- https://ru.tbc.wowhead.com/quest=1959/задание-анастасии
SET @ID := 1959;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это правда. В нашем городе произошел выплеск магической энергии. Мы не поняли, что именно произошло, и даже к добру это или к худу. Не хватает информации…$B$BЧто подводит нас к разговору о задании.', 0);

-- Add ruRU offer rewards for quest 1960
-- https://ru.tbc.wowhead.com/quest=1960/лавка-алхимика
SET @ID := 1960;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N. Лучшие умы Подгорода займутся изучением невидимых тварей. Мы выясним, откуда они взялись в нашем городе.$B$BЕсли дело в возникновении провала Маны, потребуется определить, случайно он возник или нет. Если не случайно,а в результате действий враждебных сил, нам придется готовиться к появлению более серьезных противников.', 0);

-- Add ruRU offer rewards for quest 1961
-- https://ru.tbc.wowhead.com/quest=1961/сбор-материалов
SET @ID := 1961;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличный материал. Оценить качество самоцветов я не могу, но вскоре мы узнаем, подходят ли они для создания одеяний из чароткани...', 0);

-- Add ruRU offer rewards for quest 1962
-- https://ru.tbc.wowhead.com/quest=1962/одеяние-из-чароткани
SET @ID := 1962;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твое новое одеяние, $N. Носи на здоровье.', 0);

-- Add ruRU offer rewards for quest 1963
-- https://ru.tbc.wowhead.com/quest=1963/изувеченная-длань
SET @ID := 1963;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хм. Я, конечно, рад слышать, что Тазана больше нет в живых, однако от запертой сумки проку мало. Нам нужно то, что внутри!$B$BВот и второе задание для того, кто стремится вступить в клан Изувеченной Длани!', 0);

-- Add ruRU offer rewards for quest 1999
-- https://ru.tbc.wowhead.com/quest=1999/предметы-торговли
SET @ID := 1999;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно, $N. Тебе удалось освоить искусство вскрытия замков куда быстрее, чем я ожидал.$B$BВижу, я был прав, положившись на тебя. Поверь, $Gмальчик:девочка; G$мой:моя;, ты далеко пойдешь.', 0);
