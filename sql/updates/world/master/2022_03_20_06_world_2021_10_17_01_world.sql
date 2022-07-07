-- Add ruRU offer rewards for quest 4503
-- https://ru.tbc.wowhead.com/quest=4503/крылолет-шиззла
SET @ID := 4503;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, эта чешуя подходит просто превосходно! С помощью этих чешуек мне уж точно удастся поднять мое творение в воздух!$B$BБлагодарю тебя!', 0);

-- Add ruRU offer rewards for quest 4505
-- https://ru.tbc.wowhead.com/quest=4505/источник-порчи
SET @ID := 4505;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо.Нам надо найти способ использовать эту порчу против наших врагов...', 0);

-- Add ruRU offer rewards for quest 4506
-- https://ru.tbc.wowhead.com/quest=4506/зараженные-саблезубы
SET @ID := 4506;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично!$B$BОтрекшиеся не побрезгуют никакими средствами, чтобы сокрушить Альянс! И эта оскверненная вода весьма поможет нам в наших будущих трудах...', 0);

-- Add ruRU offer rewards for quest 4521
-- https://ru.tbc.wowhead.com/quest=4521/одичавшие-стражи
SET @ID := 4521;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличные новости, $N. Теперь, когда эти твари не стоят у нас на пути, мы можем проникнуть в Зимние Ключи. Ты $Gготов:готова;?', 0);

-- Add ruRU offer rewards for quest 4561
-- https://ru.tbc.wowhead.com/quest=4561/образцы-на-пробу-из-кратера-ан-горо
SET @ID := 4561;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы берете чашку Петри с пробой слизи. Выяснить, достаточно ли образец чистый, можно только одним способом – открыть колбы и самостоятельно исследовать их содержимое. В конце концов вы должны найти пробу, которая устроит химика Барабоса.?', 0);

-- Add ruRU offer rewards for quest 4602
-- https://ru.tbc.wowhead.com/quest=4602/чистер-5200
SET @ID := 4602;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы кладете покрытый грязью предмет и три серебряные монеты в Чистер 5200, и машина начинает работать, с гудением отскребая въевшуюся грязь. Металлический корпус аппарата скрипит и вибрирует.', 0);

-- Add ruRU offer rewards for quest 4603
-- https://ru.tbc.wowhead.com/quest=4603/работа-для-чистера
SET @ID := 4603;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Чистер 5200 с яростным гудением принимается за работу. Въевшаяся грязь растворяется под воздействием гномьих чистящих средств.$B$BНаконец Чистер 5200 перестает вибрировать. Окошко премника со звоном открывается – в нем лежит аккуратно завернутая коробка.', 0);

-- Add ruRU offer rewards for quest 4604
-- https://ru.tbc.wowhead.com/quest=4604/работа-для-чистера
SET @ID := 4604;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Чистер 5200 с яростным гудением принимается за работу. Въевшаяся грязь растворяется под воздействием гномьих чистящих средств.$B$BНаконец Чистер 5200 перестает вибрировать. Окошко премника со звоном открывается – в нем лежит аккуратно завернутая коробка.', 0);

-- Add ruRU offer rewards for quest 4605
-- https://ru.tbc.wowhead.com/quest=4605/работа-для-чистера
SET @ID := 4605;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Проглотив кольцо, машина несколько минут с гудением вертит его в своих недрах и наконец останавливается, звенящим звуком оповестив вас о том, что работа закончена. Окошко приемника открывается, и вы видите в нем аккуратно завернутую коробочку. Видимо, машина выдает очищенные предметы в подарочной упаковке. Ну, даже если кольцо не удалось очистить, вы получили довольно миленькую коробочку за свои деньги...$B$BЧто ж, посмотрим...', 0);

-- Add ruRU offer rewards for quest 4606
-- https://ru.tbc.wowhead.com/quest=4606/работа-для-чистера
SET @ID := 4606;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Проглотив кольцо, машина несколько минут с гудением вертит его в своих недрах и наконец останавливается, звенящим звуком оповестив вас о том, что работа закончена. Окошко приемника открывается, и вы видите в нем аккуратно завернутую коробочку. Видимо, машина выдает очищенные предметы в подарочной упаковке. Ну, даже если кольцо не удалось очистить, вы получили довольно миленькую коробочку за свои деньги...$B$BЧто ж, посмотрим...', 0);

-- Add ruRU offer rewards for quest 4621
-- https://wowroad.info/?quest=4621
SET @ID := 4621;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Стой... Адмирал $N! Ты пират пиратов, $Gпарень:девица;!$B$BМеня аж до печенки пробирает от гордости, когда я вручаю тебе эту шляпу. Ты ничего подобного нигде не найдешь, и все, кто глянут на тебя сразу поймут, вот идет адмирал флота Кровавого Паруса!', 0);

-- Add ruRU offer rewards for quest 4642
-- https://ru.tbc.wowhead.com/quest=4642/слияние
SET @ID := 4642;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, великолепно, $N. Великолепно.$B$BНу и дела. Кто бы подумал, что они будут взаимодействовать таким образом... Придется посвятить побольше времени изучению феноменов окружающей среды, которые вызывают в этих тварях подобные изменения.$B$BА теперь я вернусь к своим исследованиям. Быть может, вскоре свидимся. Пока же – всего наилучшего.', 0);

-- Add ruRU offer rewards for quest 4661
-- https://ru.tbc.wowhead.com/quest=4661/проба-образцы-из-оскверненного-леса
SET @ID := 4661;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы берете чашку Петри с пробой слизи. Выяснить, достаточно ли образец чистый, можно только одним способом – открыть колбы и самостоятельно исследовать их содержимое. В конце концов вы должны найти пробу, которая устроит химика Барабоса.', 0);

-- Add ruRU offer rewards for quest 4701
-- https://ru.tbc.wowhead.com/quest=4701/устранение-опасности
SET @ID := 4701;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не думай о том, страдала ли она, $N. Этого зверя осквернило касание темной магии. Ты оказал Альянсу огромную услугу и получишь за нее награду.', 0);

-- Add ruRU offer rewards for quest 4721
-- https://ru.tbc.wowhead.com/quest=4721/одичавшие-стражи
SET @ID := 4721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот что я уважаю – так это хорошую работу, $N. Теперь мы можем дальше действовать в Зимних Ключах.', 0);

-- Add ruRU offer rewards for quest 4724
-- https://ru.tbc.wowhead.com/quest=4724/праматерь-стаи
SET @ID := 4724;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Бешеные щенки? Гизрул Поработитель? И ты стоишь передо мной $Gживехонький:живехонькая; и рассказываешь об этом?! Глазам не верю! Ты $Gзаслужил:заслужила; свою награду!', 0);

-- Add ruRU offer rewards for quest 4734
-- https://ru.tbc.wowhead.com/quest=4734/заморозка-яйца
SET @ID := 4734;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сработало? Великолепно! Я так и знала!$B$BПока тебя не было, я создала новую модель яйцехладоскопа. С куда большим радиусом действия.$B$BВозьми его, вдруг случайно забредешь на пик Черной горы.', 0);

-- Add ruRU offer rewards for quest 4735
-- https://ru.tbc.wowhead.com/quest=4735/сбор-яиц
SET @ID := 4735;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ух ты! Яйца! Значит, устройство-коллекционер сработало! Я гений!$B$BСпасибо, $N. Мой заказчик очень порадуется яйцам...', 0);

-- Add ruRU offer rewards for quest 4736
-- https://ru.tbc.wowhead.com/quest=4736/поиски-менары-расщепительницы-бездны
SET @ID := 4736;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, тебя прислал Остротерн. Хорошо. Значит, вести обо мне распространяются по всей земле, и ученики приходят сами. Приятно.$B$BНаш брат всегда старается держаться вместе, независимо от расы. Это особенно важно, учитывая, что те, с кем мы по большей части имеем дело, не преминут воспользоваться нашей слабостью и вырваться из-под контроля.$B$BВижу, ты многому $Gнаучился:научилась;, и если хочешь, я создам для тебя инструменты, которые помогут раскрыться твоему таланту.', 0);

-- Add ruRU offer rewards for quest 4738
-- https://ru.tbc.wowhead.com/quest=4738/поиски-менары-расщепительницы-бездны
SET @ID := 4738;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, тебя прислала Демизетта. Хорошо. Значит, вести обо мне распространяются по всей земле, и ученики приходят сами. Приятно.$B$BНаш брат всегда старается держаться вместе, независимо от расы. Это особенно важно, учитывая, что те, с кем мы по большей части имеем дело, не преминут воспользоваться нашей слабостью и вырваться из-под контроля.$B$BВижу, ты многому $Gнаучился:научилась;, и если хочешь, я создам для тебя инструменты, которые помогут раскрыться твоему таланту.', 0);

-- Add ruRU offer rewards for quest 4739
-- https://ru.tbc.wowhead.com/quest=4739/поиски-менары-расщепительницы-бездны
SET @ID := 4739;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, тебя прислал Каэл. Хорошо. Значит, вести обо мне распространяются по всей земле, и ученики приходят сами. Приятно.$B$BНаш брат всегда старается держаться вместе, независимо от расы. Это особенно важно, учитывая, что те, с кем мы по большей части имеем дело, не преминут воспользоваться нашей слабостью и вырваться из-под контроля.$B$BВижу, ты многому $Gнаучился:научилась;, и если хочешь, я создам для тебя инструменты, которые помогут раскрыться твоему таланту.', 0);

-- Add ruRU offer rewards for quest 4741
-- https://ru.tbc.wowhead.com/quest=4741/одичавшие-стражи
SET @ID := 4741;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сдается мне, тебе нравится эта работенка. Думаю, мы стараемся не напрасно.', 0);

-- Add ruRU offer rewards for quest 4742
-- https://ru.tbc.wowhead.com/quest=4742/печать-вознесения
SET @ID := 4742;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Образ Ваелана на миг расплывается мутным пятном.>$B$B<Камни, которые вы принесли, исчезли.>$B$BТеперь все готово к тому, чтобы печать вознесения обрела свою силу. Пора приступать к завершающему этапу.', 0);

-- Add ruRU offer rewards for quest 4743
-- https://ru.tbc.wowhead.com/quest=4743/печать-вознесения
SET @ID := 4743;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Стой спокойно. Я наложу последнее защитное заклинание.$B$B<Глаза Ваелана превращаются в два огненных шара.>$B$BТеперь печать Вознесения обрела свою полную силу...$B$BЯ вложил в артефакт очень мощные защитные чары. В минуту предельного отчаяния, когда тебе покажется, что все потеряно, призови силу красных драконов и используй ее для защиты.', 0);

-- Add ruRU offer rewards for quest 4766
-- https://ru.tbc.wowhead.com/quest=4766/майра-светлое-крыло
SET @ID := 4766;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты из Штормграда? Чудесно – я знаю об одном предмете искусства, который Ремингтон любой ценой захочет заполучить в свой музей. Но это будет нелегко.$B$BТут-то ты и понадобишься.', 0);

-- Add ruRU offer rewards for quest 4768
-- https://ru.tbc.wowhead.com/quest=4768/табличка-темнокамня
SET @ID := 4768;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно. Для того чтобы разобраться со всеми формулами, мне потребуется не один день, но я уверена, что результат будет стоить затраченного труда.$B$BСпасибо, $N. Ты $Gоказал:оказала; нам поистине неоценимую услугу.', 0);

-- Add ruRU offer rewards for quest 4771
-- https://ru.tbc.wowhead.com/quest=4771/рассветный-гамбит
SET @ID := 4771;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я поместила "Рассветный гамбит" в ящик, в котором были драконьи яйца. Ты $Gдолжен:должна; отнести его в самую глубину Некроситета.$B$BВектус, маг из нежити, руководит группой студентов Плети. Доставь "Рассветный гамбит" в комнату, которую они называют смотровой. Если все пойдет как надо, устройство уничтожит всю нежить, находящуюся в этот момент в комнате.$B$BПосле этого уничтожить Вектуса будет проще пареной репы. Так ведь?', 0);

-- Add ruRU offer rewards for quest 4785
-- https://ru.tbc.wowhead.com/quest=4785/нить-из-чистого-золота
SET @ID := 4785;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот, бери. И пожалуйста, передай от нас привет Менаре.$B$BМы ждем от тебя великих свершений. Быть может, когда Легион падет на колени, прозвучит твое имя и хвала твоей силе. Жду не дождусь!', 0);

-- Add ruRU offer rewards for quest 4788
-- https://ru.tbc.wowhead.com/quest=4788/последние-таблички
SET @ID := 4788;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Невероятно! Ты их $Gнашел:нашела;! Ты настоящий герой, $N!$B$BИ это очень удачно, потому что судя по предыдущим табличкам... без героя нам не обойдтись. Грядет такое...', 0);

-- Add ruRU offer rewards for quest 4842
-- https://ru.tbc.wowhead.com/quest=4842/выяснение-причин
SET @ID := 4842;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, демоны добрались до Теснины Зловещего Шепота. Я уверена, мы наблюдаем следы их присутствия. И я собираюсь и дальше наблюдать на горячими ключами, чтобы узнать о них больше.$B$BЯ немного подожду, чтобы ты $Gнабрался:набралась; сил, а потом снова привлеку тебя к исследованию Теснины Зловещего Шепота.', 0);

-- Add ruRU offer rewards for quest 4866
-- https://ru.tbc.wowhead.com/quest=4866/материнское-молоко
SET @ID := 4866;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Из этого выйдет потрясный эль!$B$BА ты что $Gдумал:думала;? Что я сделаю яд или что-то такое?$B$BНу, дети пошли...', 0);

-- Add ruRU offer rewards for quest 4867
-- https://ru.tbc.wowhead.com/quest=4867/аррок-смертный-вопль
SET @ID := 4867;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я уже чувствую, как ко мне возвращаются силы! И проклятие Аррока уже не разрушает мой разум.$B$BСпасибо, $N! Я не люблю быть кому-то обязанным, но должен признать: ты мне очень $Gпомог:помогла;.$B$BЖелаю удачи в походе на Пик Черной горы. Это безрассудство, если ты думаешь, что сможешь дойти до вершины, хотя твоя смелость поистине не знает границ.', 0);

-- Add ruRU offer rewards for quest 4882
-- https://ru.tbc.wowhead.com/quest=4882/умение-хранить-секреты
SET @ID := 4882;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Важная находка?', 0);

-- Add ruRU offer rewards for quest 4883
-- https://ru.tbc.wowhead.com/quest=4883/умение-хранить-секреты
SET @ID := 4883;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Полагаю, у энергии этого ожерелья лишь один источник, $N.$B$B<Нара закрывает глаза и замолкает на мгновение.>$B$BДикосовухи, обманутые и испуганные существа, не всегда были такими. Они были созданы для того чтобы служить ночным эльфам. Богиня ночных эльфов Элуна сотворила их, чтобы охранять священные места.$B$BКонечно, это кажется неважным, однако я призываю тебя взглянуть глубже.$B$BВ свое время ты поймешь. Спасибо, что $Gпринес:принесла; мне это ожерелье, $N.', 0);

-- Add ruRU offer rewards for quest 4903
-- https://ru.tbc.wowhead.com/quest=4903/приказ-полководца
SET @ID := 4903;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Зеленые щеки полководца на минуту покрываются мертвенной бледностью.>', 0);

-- Add ruRU offer rewards for quest 4907
-- https://ru.tbc.wowhead.com/quest=4907/тинки-кипеллер
SET @ID := 4907;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Фелнок не ошибся! Мне снова нужна твоя помощь, и на сей раз... задание будет опасным.', 0);

-- Add ruRU offer rewards for quest 4941
-- https://ru.tbc.wowhead.com/quest=4941/мудрость-эйтригга
SET @ID := 4941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Тралл, похоже, весьма встревожен услышанным.>', 0);

-- Add ruRU offer rewards for quest 4961
-- https://ru.tbc.wowhead.com/quest=4961/очищение-шара-орахила
SET @ID := 4961;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно, $N. Тебе удалось преподать этому демону урок, который он надолго запомнит. Могущества и умения тебе не занимать. Полагаю, пришло время вернуться к Менаре с очищенным шаром и найти ему доброе применение.$B$BУдачи, |3-6($C). Быть может, наши пути еще пересекутся.', 0);

-- Add ruRU offer rewards for quest 4964
-- https://ru.tbc.wowhead.com/quest=4964/завершение-шара-дарорахила
SET @ID := 4964;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Готово. А теперь скажи, что ты предпочитаешь,: посох, который займет обе руки, или шар, который позволит тебе пользоваться кинжалом или мечом.$B$BСражение с огненным големом – суровое испытание. Нет сомнений, что этот предмет славно послужит тебе в будущем. Прилежно изучай тайные искусства, $N. Я буду ждать вестей о твоих подвигах.', 0);

-- Add ruRU offer rewards for quest 4965
-- https://ru.tbc.wowhead.com/quest=4965/знание-шара-орахила
SET @ID := 4965;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты ищешь чего-то более... вещественного. Я помогу тебе, если хочешь.$B$BПриятно видеть, что не все наши сородичи стремятся к одним лишь знаниям.$B$BИтак, думаешь, ты $Gготов:готова;, $N?', 0);

-- Add ruRU offer rewards for quest 4968
-- https://wowroad.info/?quest=4968
SET @ID := 4968;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты ищешь чего-то более... вещественного. Я помогу тебе, если хочешь.$B$BПриятно видеть, что не все наши сородичи стремятся к одним лишь знаниям.$B$BИтак, думаешь, ты $Gготов:готова;, $N?', 0);

-- Add ruRU offer rewards for quest 4970
-- https://ru.tbc.wowhead.com/quest=4970/накормить-ледопардов
SET @ID := 4970;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо за помощь, $N. Мое мнение о вас со временем становится все лучше.', 0);

-- Add ruRU offer rewards for quest 4974
-- https://ru.tbc.wowhead.com/quest=4974/за-орду
SET @ID := 4974;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось нанести силам Черной горы сокрушительный удар, $N! Теперь, когда их вождь убит, воинство Черной горы снова ввергнуто в хаос.$B$BНаградой за твой героизм будет процветание народа Калимдора!', 0);

-- Add ruRU offer rewards for quest 4975
-- https://wowroad.info/?quest=4975
SET @ID := 4975;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Готово, $N. Просто скажи, что же ты предпочитаешь – посох, который занимает обе руки, или сферу, с которой ты можешь использовать кинжал или что-то еще в своей правой руке.$B$BЖелаю тебе всяческих успехов в совершенствовании твоих искусств, $N.', 0);

-- Add ruRU offer rewards for quest 4976
-- https://ru.tbc.wowhead.com/quest=4976/возвращение-к-менаре
SET @ID := 4976;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N. Подходящая сфера.$B$BОсталось одно – решить, какого демона следует заключить в нее. Решишь – считай, новый предмет силы у тебя в кармане.', 0);

-- Add ruRU offer rewards for quest 4981
-- https://ru.tbc.wowhead.com/quest=4981/агент-блестяшка
SET @ID := 4981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не буду лгать тебе, |3-6($R). Мне были нужны деньги! Киблер хорошо платит – куда больше, чем в Каргатском экспедиционном корпусе в лучшие его годы.$B$BНо можешь не сомневаться, я верна присяге! Думаешь, зачем я здесь? Чтобы таскать этому придурку-гоблину яйца экзотических зверушек или еще для каких глупостей? Нужно быть очень крупным идиотом, чтобы явиться в пик Черной горы отлавливать зверье! Не думаю, что на свете много таких сумасшедших.$B$B<Блестяшка заливисто хохочет.>$B$BВот что я тебе скажу, такие просто не должны размножаться, да-да!', 0);

-- Add ruRU offer rewards for quest 4982
-- https://ru.tbc.wowhead.com/quest=4982/вещи-блестяшки
SET @ID := 4982;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ой, $Gмолодчина:умница;! Когда я передам Лекслорту эти планы, он позабудет обо всех страшных угрозах в мой адрес и уж точно не станет спускать с меня шкуру.$B$B$N, ты $Gмой:моя; $Gгерой:героиня;!', 0);

-- Add ruRU offer rewards for quest 4983
-- https://ru.tbc.wowhead.com/quest=4983/по-данным-разведки
SET @ID := 4983;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Все-таки надо отдать ей должное;, хитрая бестия снова сумела выкрутиться! Ее донесение содержит бесценную информацию, которая очень поможет в наших делах с орками Черной Горы.$B$BРазумеется, ты не останешься без награды. Всякий труд должен быть оплачен.', 0);

-- Add ruRU offer rewards for quest 5023
-- https://ru.tbc.wowhead.com/quest=5023/лучше-поздно-чем-никогда
SET @ID := 5023;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Посылка для Иеремии Фелстоуна... В Лордерон... Пожалуй, я смогу помочь.$B$BДо наступления чумы Иеремия Фелстоун жил в городе. Бывший Иеремия Фелстоун – многие представители нежити изменили фамилии, чтобы избавиться от прошлого. Так произошло и в этом случае. Иеремения Фелстоун стал Иеремией Пэйсоном.$B$BМинуточку... разве это не он продает тараканов?', 0);

-- Add ruRU offer rewards for quest 5042
-- https://ru.tbc.wowhead.com/quest=5042/сила-агамаггана
SET @ID := 5042;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, если бы Кривозуб мог видеть, как ты наказал предавших его! <фыркает>$B$BБлагодарю тебя, ведь, собирая эти осколки, ты $Gубил:убила; еще нескольких иглогривов Дыбогривов. Продолжай в том же духе, и я вновь буду помогать тебе. <фыркает>', 0);

-- Add ruRU offer rewards for quest 5043
-- https://ru.tbc.wowhead.com/quest=5043/ловкость-агамаггана
SET @ID := 5043;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да будет верной твоя цель и метким оружие, |3-6($R).$B$BДух Агамаггана пребывает с тобой. <фыркает> Возвращайся, если захочешь. Кривозуб снова благословит тебя, если будет на то воля великого кабаньего бога. <фыркает>', 0);

-- Add ruRU offer rewards for quest 5044
-- https://ru.tbc.wowhead.com/quest=5044/мудрость-агамаггана
SET @ID := 5044;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Теперь враги будут трепетать от одного твоего вида, |3-6($R). <фыркает>$B$BПоведай Кривозубу о своих битвах, когда мы встретимся в следующий раз – в этой жизни или в следующей. <фыркает>', 0);

-- Add ruRU offer rewards for quest 5045
-- https://ru.tbc.wowhead.com/quest=5045/высокий-дух
SET @ID := 5045;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наши величайшие воины и величайшие шаманы <фыркает> позавидовали бы твоей силе воли, |3-6($R).$B$BТеперь, зная, что иглогривам не остановить тебя, ты нанесешь еще больший урон племени Вздыбленной Щетины. <фыркает>', 0);

-- Add ruRU offer rewards for quest 5046
-- https://ru.tbc.wowhead.com/quest=5046/иглошкура
SET @ID := 5046;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В бой, |3-6($R)!', 0);

-- Add ruRU offer rewards for quest 5047
-- https://ru.tbc.wowhead.com/quest=5047/айс-вентурон-к-вашим-услугам
SET @ID := 5047;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Он жив? Костюм цел? А что это там у тебя?', 0);

-- Add ruRU offer rewards for quest 5049
-- https://ru.tbc.wowhead.com/quest=5049/грусть-иеремии
SET @ID := 5049;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не пользовался этим именем много лет... Да, некогда, до того прекрасного момента, когда я влился в ряды нежити, меня так звали.$B$BТак ты $Gзнал:знала; мою сестру... или, точнее, недавно $Gговорил:говорила; с моей сестрой?$B$BОна умерла.$B$BЧетыре года назад.$B$BЗнаешь, не будь у меня такие хрупкие кости, я бы с радостью тебя пнул. Глумишься над чужим горем?$B$BЧто... у тебя посылка от моей сестры?!', 0);

-- Add ruRU offer rewards for quest 5061
-- https://ru.tbc.wowhead.com/quest=5061/водный-облик
SET @ID := 5061;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно, $N. Ты $Gготов:готова; принимать водный облик, и я с радостью научу тебя.$B$BА также, в знак признания твоих успехов в двух испытаниях, я даю тебе вот это. Надеюсь, тебе приятно будет присоединить эту вещь к своему снаряжению защитника Природы и хранителя равновесия.', 0);

-- Add ruRU offer rewards for quest 5062
-- https://ru.tbc.wowhead.com/quest=5062/священное-пламя
SET @ID := 5062;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно, вы собрали достаточно огненной агавы. Эта редкая трава растет лишь в Тысяче Игл, и она поможет мне разбудить священное пламя жизни.$B$B<Магата начинает зачаровывать огненную агаву.>', 0);

-- Add ruRU offer rewards for quest 5063
-- https://wowroad.info/?quest=5063
SET @ID := 5063;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Изумительно! Мне бы потребовались недели, чтобы собрать все это... и как тебе удалось найти нетронутую звериную шкуру?!$B$BНоси с удовольствием, $N!', 0);

-- Add ruRU offer rewards for quest 5065
-- https://ru.tbc.wowhead.com/quest=5065/утраченные-таблички-мошару
SET @ID := 5065;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gнашел:нашла; их! Отлично!$B$BСпасибо, $N. Я изучу эти тексты и расшифрую их значение.$B$BДля тебя же у меня есть еще одно задание...', 0);

-- Add ruRU offer rewards for quest 5067
-- https://wowroad.info/?quest=5067
SET @ID := 5067;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Никогда не видел лучших поножей! Носи с удовольствием!', 0);

-- Add ruRU offer rewards for quest 5068
-- https://ru.tbc.wowhead.com/quest=5068/кираса-кровавой-жажды
SET @ID := 5068;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я уж думал, что не доживу до этого дня.$B$BДостижение такого масштаба может превзойти лишь награда за него.', 0);

-- Add ruRU offer rewards for quest 5081
-- https://ru.tbc.wowhead.com/quest=5081/миссия-максвелла
SET @ID := 5081;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. По меньшей мере нам удалось выиграть время – а на счету каждая минута.', 0);

-- Add ruRU offer rewards for quest 5090
-- https://ru.tbc.wowhead.com/quest=5090/призыв-к-оружию-чумные-земли
SET @ID := 5090;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в Чумные земли, герой. Здесь одна из самых опасных границ Азерота, тем более когда с севера и северо-востока нам грозит Плеть. Я рад слышать, что зов долга и служения великому добру прозвучал не напрасно!$B$BЕсли вы готовы к тяжелому труду, то на краю Чумных земель всем героям найдется дело.', 0);

-- Add ruRU offer rewards for quest 5091
-- https://ru.tbc.wowhead.com/quest=5091/призыв-к-оружию-чумные-земли
SET @ID := 5091;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в Чумные земли, герой. Здесь одна из самых опасных границ Азерота, тем более когда с севера и северо-востока нам грозит Плеть. Я рад слышать, что зов долга и служения великому добру прозвучал не напрасно!$B$BЕсли вы готовы к тяжелому труду, то на краю Чумных земель всем героям найдется дело.', 0);

-- Add ruRU offer rewards for quest 5093
-- https://ru.tbc.wowhead.com/quest=5093/призыв-к-оружию-чумные-земли
SET @ID := 5093;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в Чумные земли, герой. Здесь одна из самых опасных границ Азерота, тем более когда с севера и северо-востока нам грозит Плеть. Я рад слышать, что зов долга и служения великому добру прозвучал не напрасно!$B$BЕсли вы готовы к тяжелому труду, то на краю Чумных земель всем героям найдется дело.', 0);

-- Add ruRU offer rewards for quest 5094
-- https://ru.tbc.wowhead.com/quest=5094/призыв-к-оружию-чумные-земли
SET @ID := 5094;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в Чумные земли, герой. Здесь одна из самых опасных границ Азерота, тем более когда с севера и северо-востока нам грозит Плеть. Я рад слышать, что зов долга и служения великому добру прозвучал не напрасно!$B$BЕсли вы готовы к тяжелому труду, то на краю Чумных земель всем героям найдется дело.', 0);

-- Add ruRU offer rewards for quest 5095
-- https://ru.tbc.wowhead.com/quest=5095/призыв-к-оружию-чумные-земли
SET @ID := 5095;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в Чумные земли, герой. Здесь одна из самых опасных границ Азерота, тем более когда с севера и северо-востока нам грозит Плеть. Я рад слышать, что зов долга и служения великому добру прозвучал не напрасно!$B$BЕсли вы готовы к тяжелому труду, то на краю Чумных земель всем героям найдется дело.', 0);

-- Add ruRU offer rewards for quest 5096
-- https://ru.tbc.wowhead.com/quest=5096/вылазка-в-стан-алого-ордена
SET @ID := 5096;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Благодаря налету на Алый орден мы выиграли время. Я послал разведчика наблюдать за лагерем, чтобы убедиться, что прибывшее подкрепленея поддастся на провокацию.$B$BЕсли натиск ордена ослабеет, мы сможем рискнуть и устроить вылазку в Андорал. Это очень важно. Я бы хотел, чтобы этим тоже $Gзанялся:занялась; ты – в конце концов, у тебя такой большой опыт.', 0);

-- Add ruRU offer rewards for quest 5102
-- https://ru.tbc.wowhead.com/quest=5102/кончина-генерала-драккисата
SET @ID := 5102;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Следующий удар мы несомненно нанесем по драконьим лордам. $GМолодец:Умница;, храбрый солдат Альянса! Отличная работа.', 0);

-- Add ruRU offer rewards for quest 5122
-- https://ru.tbc.wowhead.com/quest=5122/медальон-веры
SET @ID := 5122;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринес:принесла; медальон! Теперь я смогу наконец покинуть священные стены и исполнить свой долг!$B$BЯ должен убить чудовище, из-за которых скверна поразила меня и многих моих братьев и сестер! Имя его – барон Ривендер.', 0);

-- Add ruRU offer rewards for quest 5125
-- https://ru.tbc.wowhead.com/quest=5125/слова-аурия
SET @ID := 5125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я умираю, $N… но душа моя обрела спасение. Я так многим обязан тебе... Прошу, прими это... И продолжай биться за правое дело, храбрый |3-6($C)!', 0);

-- Add ruRU offer rewards for quest 5127
-- https://ru.tbc.wowhead.com/quest=5127/демонова-кузня
SET @ID := 5127;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты не $Gнарушил:нарушила; договора. Душу я забрал. Награду я отдам.', 0);

-- Add ruRU offer rewards for quest 5141
-- https://ru.tbc.wowhead.com/quest=5141/кожевничество-чешуя-драконов
SET @ID := 5141;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринял:приняла; важное решение. Уверяю тебя, ты не пожалеешь о том, что $Gвыбрал:выбрала; школу чешуи драконов – это очень выгодное ремесло.$B$BЧтобы получить новые знания, просто побеседуй со мной, и я расскажу все, что тебе нужно.', 0);

-- Add ruRU offer rewards for quest 5143
-- https://ru.tbc.wowhead.com/quest=5143/кожевничество-традиции-предков
SET @ID := 5143;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпожертвовал:пожертвовала; лучшее, что у тебя было, и вскоре природа отплатит тебе сторицей. Когда мы завершим твое обучение, силы природы покорятся тебе.$B$BВ будущем, чтобы улучшить свое мастерство, просто обратись ко мне, и я сообщу тебе все, что ты захочешь знать.', 0);

-- Add ruRU offer rewards for quest 5144
-- https://wowroad.info/?quest=5144
SET @ID := 5144;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gзаслужил:заслужила; это искусство. Так получи же его!$B$BИ кроме того, я буду тренировать тебя в будущем – и научу тебя чему смогу.', 0);

-- Add ruRU offer rewards for quest 5145
-- https://ru.tbc.wowhead.com/quest=5145/кожевничество-чешуя-драконов
SET @ID := 5145;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринял:приняла; важное решение. Уверяю тебя, ты не пожалеешь о том, что выбрал школу чешуи драконов – это очень выгодное ремесло.$B$BЧтобы получить новые знания, просто побеседуй со мной, и я расскажу все, что тебе нужно.', 0);

-- Add ruRU offer rewards for quest 5146
-- https://ru.tbc.wowhead.com/quest=5146/кожевничество-сила-стихий
SET @ID := 5146;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gбросил:бросила; жребий, и Стихии приняли тебя. Когда я закончу твое обучение, ты овладеешь искусством изготовления наилучших кожаных доспехов.$B$BЧтобы учиться этому искусству и дальше, приходи ко мне, и я разделю с тобой те знания, которые ты захочешь со мной разделить.', 0);

-- Add ruRU offer rewards for quest 5148
-- https://ru.tbc.wowhead.com/quest=5148/кожевничество-традиции-предков
SET @ID := 5148;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринес:принесла; богатые жертвы, и Природа вскоре позволит подчинить себя. Закончив обучение, ты сможешь делать истинные воплощения силы Природы.$B$BКогда решишь поучиться, поговори со мной, и я оделю тебя знаниями, к которым ты будешь $Gготов:готова;.', 0);

-- Add ruRU offer rewards for quest 5150
-- https://ru.tbc.wowhead.com/quest=5150/даданга-проголодалась
SET @ID := 5150;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Даданга с видимым удовольствием принюхивается к побегам.$B$BВ благодарность за лакомство она подталкивает к вам носом маленький коричневый сверток.', 0);

-- Add ruRU offer rewards for quest 5166
-- https://ru.tbc.wowhead.com/quest=5166/кираса-всецветных-драконов
SET @ID := 5166;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Неужели ты не понимаешь? Сам путь и был целью. Неужели тебя не тревожат шрамы? И боль забыта?$B$BВыстояв в испытании, ты $Gсделался:сделалась; сильнее. Гораздо сильнее. И кираса – лишь внешнее проявление внутренней мощи.', 0);

-- Add ruRU offer rewards for quest 5167
-- https://ru.tbc.wowhead.com/quest=5167/ножные-латы-всецветного-воина
SET @ID := 5167;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Когда ты войдешь в их чертоги, они почуют запах павших братьев. Пусть страх станет твоим оружием!', 0);

-- Add ruRU offer rewards for quest 5168
-- https://ru.tbc.wowhead.com/quest=5168/герои-дарроушира
SET @ID := 5168;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это книга и щит!$B$BОни тесно связаны с историей Дарроушира, и я уверен – эта история еще не закончена.', 0);

-- Add ruRU offer rewards for quest 5181
-- https://ru.tbc.wowhead.com/quest=5181/негодяи-дарроушира
SET @ID := 5181;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gнашел:нашла; их! Прекрасно, $N! В этих предметах заключена великая сила, и однажды ты сможешь овладеть ею.$B$BОднако они навевают на меня печальные воспоминания о потерянных близких и о предательстве...', 0);

-- Add ruRU offer rewards for quest 5201
-- https://ru.tbc.wowhead.com/quest=5201/вторжение-племени-зимней-спячки
SET @ID := 5201;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Меня невероятно радует, что хотя бы на короткое время мы можем забыть о вторжении фурболгов племени Зимней Спячки.$B$BЯ начинаю замечать вашу настойчивость, $N.', 0);

-- Add ruRU offer rewards for quest 5202
-- https://ru.tbc.wowhead.com/quest=5202/странный-красный-ключ
SET @ID := 5202;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ключ! Ты его $Gнашел:нашла;! Пожалуйста, дай его мне, и я, наконец, освобожусь!', 0);

-- Add ruRU offer rewards for quest 5203
-- https://ru.tbc.wowhead.com/quest=5203/спасение-из-джеденара
SET @ID := 5203;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так это ты $Gпомог:помогла; Арко спастись? Как я рада увидеть тебя! Она не так давно проходила мимо этих мест в Дарнасс. Она несла Светлую Сталь и у нее не было даже времени поговорить с друидами, чтобы те ее исцелили. Говорила, что дело слишком спешное.$B$BНо все же она рассказала мне о твоей встрече с духом Трея. Какая страшная судьба для рыцаря Серебряной Длани! Она, конечно, не подает виду, но я знаю, что ее душа разрывается от потери одного из ближайших друзей...', 0);

-- Add ruRU offer rewards for quest 5204
-- https://ru.tbc.wowhead.com/quest=5204/воздаяние-света
SET @ID := 5204;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы как можно осторожнее собираете останки паладина, сознавая, что его хотя бы его дух свободен от мучений, которым его подвергали.', 0);

-- Add ruRU offer rewards for quest 5206
-- https://ru.tbc.wowhead.com/quest=5206/мародеры-дарроушира
SET @ID := 5206;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, у нас есть черепа!$B$BХоть я и не совсем понимаю, зачем именно они нужны, я чувствую исходящую от них силу и то, что они связаны с моей родной деревней, Дарроушир.', 0);

-- Add ruRU offer rewards for quest 5210
-- https://ru.tbc.wowhead.com/quest=5210/брат-карлин
SET @ID := 5210;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что это за книга? Анналы Дарроушира? О, там был мой дом... пока не пришла Плеть! Зачем ты $Gпринес:принесла; мне эту книгу?$B$BЧто это? Смотри, на последних страницах рассказывается о том, что случилось уже после битвы! Здесь говорится и обо мне, и о моем брате Джозефе... Неужели это правда?$B$BЯ должен знать!', 0);

-- Add ruRU offer rewards for quest 5228
-- https://ru.tbc.wowhead.com/quest=5228/котлы-плети
SET @ID := 5228;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да благословит тебя Тьма, брат |3-6($R). Я помогу тебе организовать нападение на котлы Плети.$B$BНаша цель – таким образом изменить состав яда в котлах, чтобы он стал погибелью приспешников Плети. Для этого придется взять пробы из всех котлов в Западных Чумных землях.$B$BТебя ждет героическая схватка с Плетью!', 0);

-- Add ruRU offer rewards for quest 5229
-- https://ru.tbc.wowhead.com/quest=5229/цель-поле-джанис
SET @ID := 5229;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ключ, который вы забрали у Хранителя котла Желчня входит в замочную скважину и немедленно исчезает. И все же, кажется, отныне вы сможете открывать панель доступа без ключа. Изнутри доносится гнусный запах. В котле бурлит смесь неизвестных веществ.$B$BБутылка отлично помещается под небольшой кран, так что набрать в нее образец яда для жрицы Тени Вандис с вершины Холодного Ветра не составляет труда.', 0);

-- Add ruRU offer rewards for quest 5230
-- https://ru.tbc.wowhead.com/quest=5230/возвращение-в-бастион
SET @ID := 5230;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $N! Аптекарь Дитерс мигом проведет анализ этой дряни и составит противодействующее вещество. Надо будет внести его в котел и постараться, чтобы побольше испарений попало в воздух. Кто знает, может удастся ослабить Плеть.$B$BЭто будет нелегко – придется постоянно устраивать набеги на котлы и добавлять в них необходимые реагенты. И все же у нас есть шанс получить в решающей битве преимущество перед Плетью!', 0);

-- Add ruRU offer rewards for quest 5231
-- https://ru.tbc.wowhead.com/quest=5231/цель-слезы-далсона
SET @ID := 5231;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Неприятного вида ключ, найденный в останках Хранителя котла, легко входит в замочную скважину и исчезает. Вы получили постоянный доступ у котлу. По переплетенным трубкам течет гнусная тягучая жижа.$B$BБутылка отлично помещается под небольшой кран, так что набрать в нее образец яда для жрицы Тени Вандис из Бастиона не составляет труда.', 0);

-- Add ruRU offer rewards for quest 5232
-- https://ru.tbc.wowhead.com/quest=5232/возвращение-в-бастион
SET @ID := 5232;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, мне будет чем заняться. $GМолодец:Умница;, $N!$B$BИтак, следующий шаг ясен. Мы должны составить список компонентов, которые будет необходимо смешать с зельем чумы, чтобы добиться от него обратного действия.$B$BДля этого придется поместить эти составляющие непосредственно в котел. Аптекарь Дитерс знает гораздо больше чем я, поэтому в ближайшее время поговори с ним.', 0);

-- Add ruRU offer rewards for quest 5233
-- https://ru.tbc.wowhead.com/quest=5233/цель-удел-страданий
SET @ID := 5233;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Коснувшись панели доступа, ключ Хранителя котла исчезает, как и в прошлый раз. Внутри бурлит омерзительно пахнующая жидкость.$B$BБутылка отлично помещается под небольшой кран, так что набрать в нее образец яда для жрицы Тени Вандис из Бастиона не составляет труда.', 0);

-- Add ruRU offer rewards for quest 5234
-- https://ru.tbc.wowhead.com/quest=5234/возвращение-в-бастион
SET @ID := 5234;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Еще одно задание выполнено без сучка, без задоринки! Итак, у нас есть доступ вот уже к трем котлам! Если бы не страшная некромантская власть Кел\'Тузада в этих землях, я бы сказала, что нам удастся полностью нейтрализовать их!$B$BАптекарь Дитерс вскоре сообщит, что требуется добавить в этот котел – и другие, подвластные нам – чтобы справиться с чумой нежити. Итак, настало время добраться до последнего из западных котлов!', 0);

-- Add ruRU offer rewards for quest 5235
-- https://ru.tbc.wowhead.com/quest=5235/цель-пустошь-гаррона
SET @ID := 5235;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Коснувшись панели доступа у основания, ключ Хранителя котла Душегнева исчезает. Раздается негромкий щелчок, и панель распахивается, открывая доступ к зловредным ядам.$B$BБутылка отлично помещается под небольшой кран, так что набрать в нее образец яда для жрицы Тени Вандис из Бастиона не составляет труда.', 0);

-- Add ruRU offer rewards for quest 5236
-- https://ru.tbc.wowhead.com/quest=5236/возвращение-в-бастион
SET @ID := 5236;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поздравляю, $N, тебе удалось обеспечить нам доступ к последнему из котлов! Аптекарь Дитерс вскоре составит список компонентов, которые необходимо добавить в него.$B$BЧто до тебя, я не сомневаюсь, что верховный палач Деррингтон пожелает лично поблагодарить тебя за помощь. Без тебя наша борьба с Плетью была обречена. Спасибо, могучий |3-6($C).', 0);

-- Add ruRU offer rewards for quest 5249
-- https://ru.tbc.wowhead.com/quest=5249/в-зимние-ключи
SET @ID := 5249;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Друг Иви Росистой Листвы? Приятно познакомиться, $N.', 0);

-- Add ruRU offer rewards for quest 5263
-- https://ru.tbc.wowhead.com/quest=5263/быстрее-выше-сильнее
SET @ID := 5263;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Давно мне не приходилось объявлять о новых героях. Ты будешь первым, кого лорд Максвелл удостоит аудиенции за много лет.', 0);

-- Add ruRU offer rewards for quest 5264
-- https://ru.tbc.wowhead.com/quest=5264/лорд-максвелл-тиросс
SET @ID := 5264;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты для нас очень ценный союзник, $N, и ты получишь достойную награду.', 0);

-- Add ruRU offer rewards for quest 5265
-- https://ru.tbc.wowhead.com/quest=5265/серебряный-оплот
SET @ID := 5265;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ух ты...', 0);

-- Add ruRU offer rewards for quest 5282
-- https://ru.tbc.wowhead.com/quest=5282/мятущиеся-души
SET @ID := 5282;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Эган утирает скупую слезу>$B$B$GВидел:Видела; ли ты мою матушку, $N? Она обрела свободу?$B$BТы просто образец благородства. Прими эту скромную награду за труды...', 0);

-- Add ruRU offer rewards for quest 5301
-- https://ru.tbc.wowhead.com/quest=5301/искусство-школы-брони
SET @ID := 5301;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это последний шаг перед тем, как ты начнешь свою новую карьеру в школе Брони, $N. Если ты колеблешься, сейчас твой последний шанс отступить. А иначе готовься к жизни, полной славы!', 0);

-- Add ruRU offer rewards for quest 5302
-- https://wowroad.info/?quest=5302
SET @ID := 5302;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это последний шанс отказаться перед тем, как ты начнешь новую карьеру, $N. $GГотов:готова; ли ты к пути оружейника? Слава и почести ждут тебя.', 0);

-- Add ruRU offer rewards for quest 5341
-- https://ru.tbc.wowhead.com/quest=5341/сокровище-баровых
SET @ID := 5341;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Теперь главное – подтвердить мое право наследования...', 0);

-- Add ruRU offer rewards for quest 5342
-- https://ru.tbc.wowhead.com/quest=5342/последний-из-баровых
SET @ID := 5342;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Чудесно! Теперь лишь в моих руках мощь и все сокровища дома Баровых.$B$B<Алекси швыряет в вас большим мешком.>$B$BСдачу оставь себе, животное.', 0);

-- Add ruRU offer rewards for quest 5385
-- https://ru.tbc.wowhead.com/quest=5385/останки-трея-светогорна
SET @ID := 5385;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось! Хвала Элуне и всем силам, что ты почитаешь, $N! Сегодня ты $Gсовершил:совершила; деяние благое и почетное. Я уверена, что Арконарин возрадуется, узнав, что ты не только $Gспас:спасла; ее, но так же $Gубил:убила; тварь, которая истязала одного из лучших ее друзей.$B$BЯ бы хотела сделать для тебя больше, но прошу тебя – прими эту скромную награду.', 0);

-- Add ruRU offer rewards for quest 5421
-- https://ru.tbc.wowhead.com/quest=5421/рыбка-в-ведерке
SET @ID := 5421;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, $Gдружочек:подружка;, нет ничего лучше хорошо сделанной работы, особенно когда делаешь ее не ты... Верно ведь?', 0);

-- Add ruRU offer rewards for quest 5461
-- https://ru.tbc.wowhead.com/quest=5461/рас-ледяной-шепот-человек
SET @ID := 5461;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Честно говоря, я сомневался, что эта вещь вообще существует. Перед нами открывается удивительная возможность – главное, ее не пропустить.$B$BГотовься, $N, ведь то, о чем я тебя попрошу, низведет тебя в самые глубины Преисподней.', 0);

-- Add ruRU offer rewards for quest 5462
-- https://ru.tbc.wowhead.com/quest=5462/рас-ледяной-шепот-гибель
SET @ID := 5462;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не задавай вопросов, если не хочешь узнать ответы.', 0);

-- Add ruRU offer rewards for quest 5463
-- https://ru.tbc.wowhead.com/quest=5463/дар-менетила
SET @ID := 5463;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы кладете книгу на оскверненную землю.', 0);

-- Add ruRU offer rewards for quest 5464
-- https://ru.tbc.wowhead.com/quest=5464/дар-менетила
SET @ID := 5464;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как эта душа цепляется за книгу, также она будет цепляться и за человеческое обличье Раса Ледяного Шепота.', 0);

-- Add ruRU offer rewards for quest 5465
-- https://ru.tbc.wowhead.com/quest=5465/книга-души
SET @ID := 5465;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Признаться, я ожидал вновь увидеть тебя в обличье несчастного призрака.', 0);

-- Add ruRU offer rewards for quest 5466
-- https://ru.tbc.wowhead.com/quest=5466/рас-ледяной-шепот-лич
SET @ID := 5466;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Десять тысяч душ возопили единым гласом! Ты $Gнанес:нанесла; смертельный удар Плети и ее хозяевам.', 0);
