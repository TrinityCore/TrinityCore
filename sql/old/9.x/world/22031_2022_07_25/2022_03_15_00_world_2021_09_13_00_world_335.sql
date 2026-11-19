-- Add ruRU offer rewards for quest 2202
-- https://ru.tbc.wowhead.com/quest=2202/в-ульдаман-за-реактивом
SET @ID := 2202;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $N, ты снова $Gпоказал:показала;, на что $Gспособен:способна;! Эти грибы очень пригодятся для моих исследований!$B$BА теперь, как я и обещал, можешь насладиться вкусом одного из самых действенных восстановительных составов из моих личных запасов...$B$BЕсли ты тоже увлекаешься алхимией, мы можем вдобавок поговорить о других делах. В любом случае, благодарю за помощь!', 0);

-- Add ruRU offer rewards for quest 2203
-- https://ru.tbc.wowhead.com/quest=2203/пробежка-по-бесплодным-землям-2
SET @ID := 2203;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Между нами, алхимиками, говоря, ты просто $Gгерой:героиня;! Вот, возьми этот рецепт. Пусть он принесет тебе успех и богатство, как и мне!', 0);

-- Add ruRU offer rewards for quest 2218
-- https://ru.tbc.wowhead.com/quest=2218/путь-к-спасению
SET @ID := 2218;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Стало быть, ты считаешь себя $Gнастоящим:настоящей; $Gмерзавцем:мерзавкой;? $GДостойным:Достойной; оказаться среди немногих избранных ребят Черной Бороды – стать офицером Тайного Круга?B$BТолько $Gнастоящий:настоящая; $Gпрохвост:прохвостка; так высоко себя ценит!$B$BТаких мы и ищем! Добро пожаловать, $N!', 0);

-- Add ruRU offer rewards for quest 2238
-- https://ru.tbc.wowhead.com/quest=2238/простая-уловка
SET @ID := 2238;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тсссс! Тише, балда. Нас подслушивают.', 0);

-- Add ruRU offer rewards for quest 2239
-- https://ru.tbc.wowhead.com/quest=2239/донесение-онина
SET @ID := 2239;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Большой крюк? Клянусь собственной бородой!$B$BТы $Gпостарался:постаралась; на славу, $N. Возьми вот этот кинжал и ступай. Круг призовет тебя снова, когда будет готов третий шаг.$B$BЧто такое третий шаг? Да тот, что идет после второго, а именно – хороший пинок тебе под зад.$B$BХочешь?', 0);

-- Add ruRU offer rewards for quest 2258
-- https://ru.tbc.wowhead.com/quest=2258/пробежка-по-бесплодным-землям
SET @ID := 2258;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $N. Этого мне должно хватить на некоторое время. Вот обещанная плата.$B$BЕсли ты не против получить новое задание, то вот – мне нужны еще кое-какие реактивы. Некоторые из них можно найти только в глубинах ульдаманского раскопа. Добыть их нелегко, но и плата за помощь будет немалая.$B$BМожет быть, кое-что получше блестящих монет!', 0);

-- Add ruRU offer rewards for quest 2259
-- https://ru.tbc.wowhead.com/quest=2259/эрион-шепот-тени
SET @ID := 2259;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Пора идти дальше, |3-6($R), – мир ждет.', 0);

-- Add ruRU offer rewards for quest 2260
-- https://ru.tbc.wowhead.com/quest=2260/директива-эриона
SET @ID := 2260;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы откликнулись на призыв ШРУ, $N, и проделали долгий путь от дальних берегов, чтобы вступить в наши ряды. Однако вам многому предстоит научиться.', 0);

-- Add ruRU offer rewards for quest 2280
-- https://ru.tbc.wowhead.com/quest=2280/платиновые-диски
SET @ID := 2280;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что это у нас тут?$B$BНевероятно, мой юный друг! На этих дисках записаны древние и давно утерянные тайны. Ты $Gпоступил:поступила; мудро, принеся их мне.', 0);

-- Add ruRU offer rewards for quest 2283
-- https://ru.tbc.wowhead.com/quest=2283/пропавшее-ожерелье
SET @ID := 2283;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О-о, добыча! Отсюда чую, оно здесь... Дай-ка взглянуть…$B$BЭй, что это ты нам подсовываешь? Тут же камней не хватает. Ты что $Gдумал:думала;, мы не заметим? Даже Мальтон увидел бы, что камней нету!$B$BНу, может, это и не ты их $Gспер:сперла;... Но ведь ожерелье без них ничего не стоит! Не-ет, твоя работа еще не окончена!', 0);

-- Add ruRU offer rewards for quest 2284
-- https://ru.tbc.wowhead.com/quest=2284/пропавшее-ожерелье-этап-2
SET @ID := 2284;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Похоже, вам-таки удалось отыскать останки паладина, о которых говорил Дран. Обыскав их, вы находите дневник паладина. Дневник в плохом состоянии, большая часть страниц перепачкана запекшейся кровью. Но и оставшийся текст – сплошная галиматья. Похоже, это язык людей.$B$BПридется вам найти кого-то, кто сможет это перевести.', 0);

-- Add ruRU offer rewards for quest 2298
-- https://ru.tbc.wowhead.com/quest=2298/королевская-облава
SET @ID := 2298;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Всегда рад видеть в наших рядах ребят Хальфдана!', 0);

-- Add ruRU offer rewards for quest 2299
-- https://ru.tbc.wowhead.com/quest=2299/к-хальфдану
SET @ID := 2299;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Говори тише, $N, стража может услышать.', 0);

-- Add ruRU offer rewards for quest 2318
-- https://ru.tbc.wowhead.com/quest=2318/трудности-перевода
SET @ID := 2318;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Могучий|3-6($C), я знаю зачем Вы здесь, в Бесплодных землях. Я знаю, что Вам нужны мои умения по части языков. Вы – в поисках частей того ожерелья, которое вы нашли в Ульдамане.$B$BУдивлены? Не стоит – знать такие вещи – моя работа. Вместо этого давайте обсудим, что Вы сделаете для того, чтобы перевести дневник. Доверяйте мне – я – единственный, кто может перевести его.$B$BТак что позвольте мне сделать вам лучшее предложение, чем может Дран Дрофферз и можете без помех продолжать переговоры с ними. Заинтригованы?', 0);

-- Add ruRU offer rewards for quest 2338
-- https://ru.tbc.wowhead.com/quest=2338/трудности-перевода
SET @ID := 2338;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Благодарю тебя, секрет ожерелий разгадать несложно, если иметь достаточно времени, чтобы изучить всего одно из них.$B$BА теперь погоди еще минутку, я произнесу заклинание, чтобы быстро перевести дневник с человеческого языка на понятный тебе. Я тролль слова, спроси кого хочешь в Орде, и тебе скажут: Джаркалу Замшелому Клыку можно доверять! Ну-с, приступим...', 0);

-- Add ruRU offer rewards for quest 2339
-- https://ru.tbc.wowhead.com/quest=2339/найти-самоцветы-и-источник-энергии
SET @ID := 2339;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, |3-6($C)! Скоро мы пожнем плоды наших трудов. Я закончил работу над ожерельем и уверен, что теперь смогу создать такое же.$B$BНо сначала я использую специальное заклинание, чтобы быстро исследовать эти самоцветы, прежде чем ты унесешь их и ожерелье в Оргриммар. Это займет всего пару минут.', 0);

-- Add ruRU offer rewards for quest 2340
-- https://ru.tbc.wowhead.com/quest=2340/принести-самоцветы
SET @ID := 2340;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, все в порядке. Я могу оставить себе и мешок? Спасибо, премного благодарен.$B$BИ все же лучший трофей – это ожерелье! Не строй такую кислую мину, оно было бы тебе не к лицу!$B$BСделка есть сделка, поэтому вот твоя награда за принесенные трофеи. Что ж, с этим покончено, можешь заглядывать иногда, если понадобится работа. А пока будь $Gлюбезен:любезна;, покинь помещение!', 0);

-- Add ruRU offer rewards for quest 2341
-- https://ru.tbc.wowhead.com/quest=2341/пропавшее-ожерелье-этап-3
SET @ID := 2341;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Источник силы, полученный от тебя, превзошел все мои ожидания! Мне удалось сделать два ожерелья – тебе и мне, – и в нем осталось достаточно энергии, чтобы сделать как минимум еще три! Я на этом неплохо наживусь, а семейка Дрофферсов ничего и не узнает!$B$BВот, держи. Я тебе очень благодарен... а это знак моей благодарности!', 0);

-- Add ruRU offer rewards for quest 2342
-- https://ru.tbc.wowhead.com/quest=2342/возвращенные-сокровища
SET @ID := 2342;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наконец-то – метла, достойная Гарретта. Не зря я потратил на тебя деньги!$B$BВы слышите меня, летучие мыши? Теперь у меня есть истинное оружие семьи Гарреттов! Трепещите, проклятые пискуны!', 0);

-- Add ruRU offer rewards for quest 2358
-- https://wowroad.info/goha.ru?quest=2358
SET @ID := 2358;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отказать Черному Ворону в артефакте значило бы отказать в собственное существование. Молодец, |3-6($C). Вы еще можете прогуляться среди убийц Черного Ворона.$B$BКогда я был молодым |3-6($C), путешествующим по Темным берегам, я обнаружил чай, который восполняет энергию в бою. Он хорошо служил мне на протяжении многих лет, и теперь я передаю вам вкус чая из чертополоха. Выпей его, когда устанешь, $N, и снова сражайся отважно!', 0);

-- Add ruRU offer rewards for quest 2359
-- https://ru.tbc.wowhead.com/quest=2359/башня-клейвена
SET @ID := 2359;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это объясняет присутствие мертвяков из Братства Справедливости, которых вы с Кеарнен видели рядом с башней. Это может объяснить и вовлеченность Торговой Компании в дела Братства Справедливости и эти странные поставки из Сумеречного леса.$B$BКак явствует из этой книги, тролли Занзила в Тернистой долине нашли возможность поднимать мертвых с помощью зелий... выражаясь точнее – ядов.$B$BВы бесполезны для ШРУ, если у вас нет четкого представления о ядах, $N, особенно когда рецепт того, как поднимать нежить, почти у нас в руках.', 0);

-- Add ruRU offer rewards for quest 2360
-- https://ru.tbc.wowhead.com/quest=2360/матиас-и-братство-справедливости
SET @ID := 2360;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наконец-то Матиас прислал еще одного агента мне в помощь. Ну, надеюсь, он готов к вороху неприятных новостей.', 0);

-- Add ruRU offer rewards for quest 2361
-- https://ru.tbc.wowhead.com/quest=2361/восстановление-ожерелье
SET @ID := 2361;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я с великой радостью вручаю тебе это ожерелье, $Gмогучий:могучая; |3-6($C). Ты $Gоказал:оказала; мне неоценимую услугу, и я благодарен тебе за это. Носи же его с гордостью и не забывай при этом все время упоминать о том, кто сделал его для тебя!$B$BДа, если еще добавишь, что на ожерелье нет проклятия, это будет великолепно.', 0);

-- Add ruRU offer rewards for quest 2378
-- https://ru.tbc.wowhead.com/quest=2378/поиски-изувеченной-длани
SET @ID := 2378;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так вот кого могучие союзники прислали Шентулу... Не впечатляет…', 0);

-- Add ruRU offer rewards for quest 2379
-- https://ru.tbc.wowhead.com/quest=2379/зандозан
SET @ID := 2379;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Быть может, Зандо\'зан ошибся. Зандо\'зан просит прощения.', 0);

-- Add ruRU offer rewards for quest 2380
-- https://ru.tbc.wowhead.com/quest=2380/в-оргриммар
SET @ID := 2380;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень важно, чтобы Изувеченная Длань сохраняла бдительность перед лицом перемен, которые Тралл намеревается ввести в Орде. Числом тут не возьмешь – для нас главное незаметность и разнообразные уловки!', 0);

-- Add ruRU offer rewards for quest 2440
-- https://ru.tbc.wowhead.com/quest=2440/платиновые-диски
SET @ID := 2440;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, $N, ты, видать, $Gугодил:угодила; Ведуну Искателю Истины, принеся ему ту штуку. Так что вдобавок ты получишь в награду зелья из его личного хранилища. Можешь выбрать или 5 наилучших целебных зелий, либо 5 сильных зелий маны.', 0);

-- Add ruRU offer rewards for quest 2458
-- https://ru.tbc.wowhead.com/quest=2458/надежное-прикрытие
SET @ID := 2458;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приятно видеть в здешних местах еще одного агента Изувеченной Длани! Вот только боюсь, как бы твоих вспышек не заметил кто-то лишний.$B$BВ следующий раз, когда тебе нужно будет со мной поговорить, дважды свистни в этот свисток, и я пойму, что это свои.', 0);

-- Add ruRU offer rewards for quest 2460
-- https://ru.tbc.wowhead.com/quest=2460/приветствие-изувеченной-длани
SET @ID := 2460;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $N! Теперь мы можем продолжать.', 0);

-- Add ruRU offer rewards for quest 2478
-- https://ru.tbc.wowhead.com/quest=2478/миссия-выполнима-но-с-трудом
SET @ID := 2478;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Бедный Физзул, он был прекрасным агентом, одним из лучших. Увы, мы заплатили за победу высокую цену, $N. Да, работа агента Изувеченной Длани опасна.$B$BНо ты отлично $Gсправился:справилась; с заданием, |3-6($C). Хорошо, что тебе удалось выжить. Ты ведь можешь и дальше служить нам.', 0);

-- Add ruRU offer rewards for quest 2479
-- https://ru.tbc.wowhead.com/quest=2479/помощь-хинотта
SET @ID := 2479;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, |3-6($C), $Gкакой:какая; ты $Gбледненький:бледненькая;! А чем это от тебя так мерзко благоухает? Я должен выяснить!', 0);

-- Add ruRU offer rewards for quest 2480
-- https://ru.tbc.wowhead.com/quest=2480/помощь-хинотта
SET @ID := 2480;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Лекарство готово! Выпей это противоядие, и наступление безумия остановится. Впрочем, с запахом ничего не поделаешь.', 0);

-- Add ruRU offer rewards for quest 2501
-- https://ru.tbc.wowhead.com/quest=2501/пробежка-по-бесплодным-землям-2
SET @ID := 2501;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Между нами, алхимиками, говоря, ты просто $Gгерой:героиня;! Вот, возьми этот рецепт. Пусть он принесет тебе успех и богатство, как и мне!', 0);

-- Add ruRU offer rewards for quest 2521
-- https://ru.tbc.wowhead.com/quest=2521/служба-для-кумиша
SET @ID := 2521;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не обманывают ли меня глаза? Невозможно! Откуда... Каким образом...$B$BБыть может, теперь откроется разлом и мы сможем вернуться на родину.', 0);

-- Add ruRU offer rewards for quest 2522
-- https://ru.tbc.wowhead.com/quest=2522/попытки-кумиша
SET @ID := 2522;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Просто поразительно. Я сомневался, что тебе удастся найти еще одну сферу, но вот она – пульсирует у меня в ладонях.$B$BОтлично сделано, $N!$B$BЕсли найдешь еще – а я верю, что это возможно – то принеси мне, и я вознагражу тебя.', 0);

-- Add ruRU offer rewards for quest 2581
-- https://ru.tbc.wowhead.com/quest=2581/челюсти-гиены-хохотуна
SET @ID := 2581;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как самочувствие, $N? Ты излучаешь ауру гиены-ухмыльника – силу, с которой никто из смертных не сравнится!$B$BК несчастью, из принесенных тобой компонентов я смогу сделать эссенции только на одну таблетку. Если тебе понадобится еще одна таблетка, мне нужно будет больше компонентов.', 0);

-- Add ruRU offer rewards for quest 2582
-- https://ru.tbc.wowhead.com/quest=2582/ярость-веков
SET @ID := 2582;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот, возьми! И помни, что использовать это зелье надо расчетливо. Если понадобится еще, приходи ко мне после того, как израсходуешь порцию, которую я тебе только что выдал.', 0);

-- Add ruRU offer rewards for quest 2583
-- https://ru.tbc.wowhead.com/quest=2583/жизненная-сила-вепря
SET @ID := 2583;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Дух вепря озаряет твое существование, $N! Может быть, ты веришь, что тебе дарована неуязвимость, как и этим тварям?', 0);

-- Add ruRU offer rewards for quest 2584
-- https://ru.tbc.wowhead.com/quest=2584/дух-вепря
SET @ID := 2584;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хочу предупредить тебя, $N, не пытайся смешивать созданные мною составы. Химические свойства состава, недавно принятого тобою, всегда возобладают над предшествующими заклинаниями, таким образом, эффект другого зелья будет сведен на нет.', 0);

-- Add ruRU offer rewards for quest 2585
-- https://ru.tbc.wowhead.com/quest=2585/решительный-удар
SET @ID := 2585;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Потрясающе. Анализ этой эссенции был самым сложным.$B$BВозьми щепотку этой солевой вытяжки и положи ее под язык. Ты испытаешь легкое чувство эйфории, после которого наступит состояние невероятной ловкости и быстроты.', 0);

-- Add ruRU offer rewards for quest 2586
-- https://ru.tbc.wowhead.com/quest=2586/скорпоковая-соль
SET @ID := 2586;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Вот одна мера настойки для тебя, а оставшиеся девять будут использованы для моих исследований.$B$BВ любой момент, когда тебе понадобится скорпоковая настойка, возвращайся ко мне, и мы заключим сделку.', 0);

-- Add ruRU offer rewards for quest 2601
-- https://ru.tbc.wowhead.com/quest=2601/укус-василиска
SET @ID := 2601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Замечательно, $N! Предлагаю тебе отведать на вкус внутреннюю суть василисков красного камня.$B$BЕсли этот состав тебе понравится, всегда можно сделать еще... за определенную плату.', 0);

-- Add ruRU offer rewards for quest 2602
-- https://ru.tbc.wowhead.com/quest=2602/непогрешимый-разум
SET @ID := 2602;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, да, $N, дай мне минутку, и нужные тебе составы будут готовы к употреблению.$B$BВот, возьми... и помни, $N, что нельзя даже пытаться употреблять эти экспериментальные составы слишком часто. Результат будет катастрофическим.', 0);

-- Add ruRU offer rewards for quest 2603
-- https://ru.tbc.wowhead.com/quest=2603/стойкость-стервятника
SET @ID := 2603;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Я немедленно приступаю к работе. Возможно, удастся найти лекарство от множества недугов, существующих в этом мире!$B$BАх да, твоя награда – конечно, если тебе опять понадобится зелье, возвращайся ко мне, я дам тебе новое поручение.', 0);

-- Add ruRU offer rewards for quest 2604
-- https://ru.tbc.wowhead.com/quest=2604/духовное-превосходство
SET @ID := 2604;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Возможно, когда-нибудь я смогу выделить активные компоненты этой эссенции и получить куда более эффективный результат. К несчастью, пока тебе придется довольствоваться тем, что я в состоянии сделать на настоящий момент. Если понадобится еще зелье из потрошков, возвращайся ко мне.', 0);

-- Add ruRU offer rewards for quest 2607
-- https://ru.tbc.wowhead.com/quest=2607/прикосновение-занзила
SET @ID := 2607;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как раз вовремя! Просто положите сыр на стол и проваливайте. Осборн заплатит вам на выходе.', 0);

-- Add ruRU offer rewards for quest 2608
-- https://ru.tbc.wowhead.com/quest=2608/прикосновение-занзила
SET @ID := 2608;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Позвольте, я минутку посовещаюсь со своими коллегами, $N. Доктор Монтгомери, мистер Ноарм, все на консилиум!', 0);

-- Add ruRU offer rewards for quest 2609
-- https://ru.tbc.wowhead.com/quest=2609/прикосновение-занзила
SET @ID := 2609;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что я делаю? А на что похоже то, что я делаю? Я продумываю, как вылечить ваш чтотит! И нечего так возмущенно на меня смотреть, $N! Еще несколько секунд... Готово! Побрызгайте на себя этим лечебным средством с... эээ... необыкновенным запахом – и вы в полном порядке!', 0);

-- Add ruRU offer rewards for quest 2621
-- https://ru.tbc.wowhead.com/quest=2621/опозоренный
SET @ID := 2621;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хватка Тралла... Эта история все еще свежа в моей памяти.$B$B*Командир Руаг качает головой.*$B$BУжасная вещь – то, что случилось с этим подразделением. Орда потеряла немало своих лучших солдат, когда этот батальон был уничтожен.', 0);

-- Add ruRU offer rewards for quest 2622
-- https://ru.tbc.wowhead.com/quest=2622/пропавшие-приказы
SET @ID := 2622;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Болот... ный... гово... говорун...', 0);

-- Add ruRU offer rewards for quest 2681
-- https://ru.tbc.wowhead.com/quest=2681/камни-что-связывают-нас
SET @ID := 2681;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе это удалось, $N! Несчастные, истерзанные души наконец-то обретут покой.$B$BНо наша работа еще не завершена, $N. Нам еще многое нужно обсудить и еще больше сделать.', 0);
