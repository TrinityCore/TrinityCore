-- Add ruRU offer rewards for quest 4001
-- https://ru.tbc.wowhead.com/quest=4001/что-происходит
SET @ID := 4001;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сейчас у Орды есть шанс изменить политическую ситуацию в нашем мире, истерзанном войной. Причем изменить радикально. Раз и навсегда. Слушай внимательно, $N.$B$BПостарайся, чтобы все получилось. Провал в этом деле смерти подобен.', 0);

-- Add ruRU offer rewards for quest 4002
-- https://ru.tbc.wowhead.com/quest=4002/восточные-королевства
SET @ID := 4002;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Все, $N. Отныне пути назад нет.', 0);

-- Add ruRU offer rewards for quest 4003
-- https://ru.tbc.wowhead.com/quest=4003/спасение-принцессы
SET @ID := 4003;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ты $Gнаделал:наделала;!', 0);

-- Add ruRU offer rewards for quest 4004
-- https://ru.tbc.wowhead.com/quest=4004/спасенная-принцесса
SET @ID := 4004;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Тралл поражен вашим рассказом. Он явно не ожидал ничего подобного.>$B$BСтало быть, надо ждать новой угрозы. Магни уже немолод, кто знает, сколько ему осталось. А если Магни не станет, дорога к трону Стальгорна будет открыта для еще не рожденного отпрыска Черного Железа.$B$BТы $Gисполнил:исполнила; мое поручение и получишь награду.$B$BА теперь оставь меня, $N! Мне надо посовещаться с Сильваной и Кэрном.', 0);

-- Add ruRU offer rewards for quest 4005
-- https://ru.tbc.wowhead.com/quest=4005/аквамонтос
SET @ID := 4005;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Яропламень, говоришь...$B$BДа, я знаю, этот могучий элементаль обитает в опаленном центре кратера. Мы все стараемся держаться от этого места подальше – никому не удавалось проникнуть сквозь ауру этого создания. Многие смельчаки нашли свою смерть в расщелинах сердца кратера.', 0);

-- Add ruRU offer rewards for quest 4022
-- https://ru.tbc.wowhead.com/quest=4022/вкус-пламени
SET @ID := 4022;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Цирус изучает шкуру.>$B$BНу что ж, тебе удалось доказать, что ты хоть на что-то $Gпригоден:пригодна;, $Gсмертный:смертная;.', 0);

-- Add ruRU offer rewards for quest 4023
-- https://ru.tbc.wowhead.com/quest=4023/вкус-пламени
SET @ID := 4023;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Цирус изучает шкуру.>$B$BНу что ж, тебе удалось доказать, что ты хоть на что-то $Gпригоден:пригодна;, $Gсмертный:смертная;.', 0);

-- Add ruRU offer rewards for quest 4024
-- https://ru.tbc.wowhead.com/quest=4024/вкус-пламени
SET @ID := 4024;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Цирус выхватывает сущность Огня у вас из рук.>$B$BДА!$B$BБери награду и убирайся. Долой с глаз моих!', 0);

-- Add ruRU offer rewards for quest 4041
-- https://ru.tbc.wowhead.com/quest=4041/эликсир-видере
SET @ID := 4041;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну что, удалось тебе обойти старого Миблона, а?', 0);

-- Add ruRU offer rewards for quest 4061
-- https://ru.tbc.wowhead.com/quest=4061/восстание-машин
SET @ID := 4061;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Теодора раскладывает перед собой осколки и рассматривает их в огромную лупу.>$B$BПрелюбопытно... На каждом из этих осколков выгравированы... инициалы.', 0);

-- Add ruRU offer rewards for quest 4062
-- https://ru.tbc.wowhead.com/quest=4062/восстание-машин
SET @ID := 4062;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Лотвил неожиданно бледнеет>$B$BЯ узнаю эти знаки...', 0);

-- Add ruRU offer rewards for quest 4063
-- https://ru.tbc.wowhead.com/quest=4063/восстание-машин
SET @ID := 4063;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что это?! Голова... Она не из плоти и крови! Это какое-то создание из черного железа! Аргелмах был ЕЩЕ ОДНОЙ машиной! Полагаю, в таком случае нам рано праздновать победу – на его место вскоре придет другой!', 0);

-- Add ruRU offer rewards for quest 4081
-- https://ru.tbc.wowhead.com/quest=4081/уничтожить-на-месте-дворфы-черного-железа
SET @ID := 4081;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Небось, после такого Кузня Гнева в штаны наложил! Теперь проходи, проходи, солдат. У меня еще масса дел!$B$BСмотри внимательно на объявления, для тебя может найтись еще работенка.', 0);

-- Add ruRU offer rewards for quest 4082
-- https://ru.tbc.wowhead.com/quest=4082/уничтожить-на-месте-высокопоставленные-чины-черного-железа
SET @ID := 4082;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не сомневаюсь, генерал Кузня Гнева теперь... в гневе. Возвращайся ко мне, когда получишь третью награду, и мы приступим к операции "Смерть Кузне Гнева". Пока не буду вдаваться в детали, но могу заверить наперед, что точно кто-нибудь умрет!', 0);

-- Add ruRU offer rewards for quest 4083
-- https://ru.tbc.wowhead.com/quest=4083/призрачный-кубок
SET @ID := 4083;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Драгоценные камни беззвучно падают в глубину кубка...', 0);

-- Add ruRU offer rewards for quest 4084
-- https://ru.tbc.wowhead.com/quest=4084/серебряное-сердце
SET @ID := 4084;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно, $N. Вижу, ты всегда $Gготов:готова; помогать друзьям.', 0);

-- Add ruRU offer rewards for quest 4102
-- https://ru.tbc.wowhead.com/quest=4102/очищение-оскверненного-леса
SET @ID := 4102;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Этот кровавый янтарь поможет мне найти средство борьбы с порчей, поразившей Оскверненный лес. Ты $Gдоказал:доказала; мне, что $Gготов:готова; сделать все для Круга Кенария. Теперь я доверяю тебе.$B$BМожет показаться странным, что доказательством твоей преданности послужило истребление элементалей, но наша цель – спасение бесчисленных живых существ – оправдывает средства. Теперь мы с тобой можем заняться спасением жизней при помощи бальзамов. которые я смогу сделать.', 0);

-- Add ruRU offer rewards for quest 4120
-- https://ru.tbc.wowhead.com/quest=4120/сила-порчи
SET @ID := 4120;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Судя по твоему описанию, эти твари отличаются безоглядной свирепостью…$B$BОставайся начеку, $N. Тебе стоит как можно больше узнать о порче. Врага нужно знать в лицо!', 0);

-- Add ruRU offer rewards for quest 4121
-- https://ru.tbc.wowhead.com/quest=4121/опасное-положение
SET @ID := 4121;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твой подвиг не пропадет втуне. Ты $Gзаслужил:заслужила; эту награду. Теперь Вождь поведает тебе о последнем задании.', 0);

-- Add ruRU offer rewards for quest 4122
-- https://ru.tbc.wowhead.com/quest=4122/грарк-лоркруб
SET @ID := 4122;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Разве ты не понимаешь, какую силу можно обрести, присоединившись к армии Черной горы?', 0);

-- Add ruRU offer rewards for quest 4124
-- https://ru.tbc.wowhead.com/quest=4124/пропавший-курьер
SET @ID := 4124;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты от Латро, я так понимаю? Я думаю, что дело глухо, но готов принять любую помощь. Должен признаться... я буду рад, когда вопрос решится хоть как-то. Я каждое утро выезжаю в лес разыскивать следы Раскала, и каждый вечер возвращаюсь домой с пустыми руками!', 0);

-- Add ruRU offer rewards for quest 4125
-- https://ru.tbc.wowhead.com/quest=4125/пропавший-курьер
SET @ID := 4125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы обнаружили затонувшую лодку. Сквозь мутноватую воду видны дыры, зияющие в левом борту. Кажется, будто лодка буквально ободрана до своего деревянного остова. Такое впечатление, что лодку пытались перекусить пополам. На правом борту нарисован небольшой герб Крепости Оперенной Луны.$B$BВ иле, скопившемся на дне лодки, блеснул металл...', 0);

-- Add ruRU offer rewards for quest 4127
-- https://ru.tbc.wowhead.com/quest=4127/разбитая-лодка
SET @ID := 4127;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Интересно... Похоже, это нож Раскала. Так говоришь, он валялся на дне, рядом с обломками его лодки? Ну, может быть, этой находки и недостаточно, чтобы делать какие-то выводы. Но у нас есть один необычный способ узнать побольше…$B$BДоводилось ли тебе слышать о сверхзнании?', 0);

-- Add ruRU offer rewards for quest 4128
-- https://ru.tbc.wowhead.com/quest=4128/рагнар-громовар
SET @ID := 4128;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, ты $Gправ:права;, я не просто рассержен. Я в бешенстве! Меня обокрали! Эти скоты сперли наш старый фамильный рецепт! Да как они только посмели?! Я и раньше-то их ненавидел... этих поганых дворфов из клана Черного Железа! А теперь... ох, как я зол!', 0);

-- Add ruRU offer rewards for quest 4129
-- https://ru.tbc.wowhead.com/quest=4129/тайна-ножа
SET @ID := 4129;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N.$B$BКонечно, сверхзнание точным искусством не назовешь, с какой стороны ни взгляни, но все же в былые времена я не раз с его помощью разбирался в ситуациях, которые все прочие сочли безнадежными. Думаю, на этот раз оно поможет нам хотя бы отчасти понять, что произошло с Раскалом.$B$BВремени это много не займет, но легким и приятным это дело не назовешь. Так что будь $Gготов:готова; прийти мне на помощь.', 0);

-- Add ruRU offer rewards for quest 4130
-- https://ru.tbc.wowhead.com/quest=4130/сверхзнание
SET @ID := 4130;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, что $Gрассказал:рассказала; мне о видениях Кинта, $N. Так и быть, в следующий раз, как мы с ним сядем за карты, постараюсь быть к нему подобрее.$B$BНу, в бою Раскал никому не уступит, и гноллы – не те, кто может его обеспокоить, тем более, напугать. Но, может быть, эти новые сведения тебе все же пригодятся?', 0);

-- Add ruRU offer rewards for quest 4131
-- https://ru.tbc.wowhead.com/quest=4131/гноллы-из-стаи-древолапов
SET @ID := 4131;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'На ближайшем дереве висят два больших кожаных мешка. На обоих виднеется метка Крепости Оперенной Луны...', 0);

-- Add ruRU offer rewards for quest 4132
-- https://ru.tbc.wowhead.com/quest=4132/операция-смерть-кузне-гнева
SET @ID := 4132;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наконец-то! Возмездие настигло негодяя! Ты отлично $Gсражался:сражалась;, $N! Носи этот медальон как символ твоих заслуг перед Ордой и Каргатским экспедиционным корпусом.', 0);

-- Add ruRU offer rewards for quest 4134
-- https://ru.tbc.wowhead.com/quest=4134/украденный-рецепт-громоварского
SET @ID := 4134;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот и славно. Я отошлю рецепт в Район Фармацевтов. Его там изучат, и со временем мы раскроем его секреты. И, возможно, придет такой день, когда дворфы Альянса с удивлением обнаружат, что волшебные свойства их тайного напитка против них же и обернулись!$B$BПо-моему, это будет забавно. Видимо, смерть как-то странно влияет на чувство юмора... ты не находишь?', 0);

-- Add ruRU offer rewards for quest 4135
-- https://ru.tbc.wowhead.com/quest=4135/гудящая-бездна
SET @ID := 4135;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вам удалось обнаружить огромный кокон непонятного происхождения. Сам кокон мягкий и слизистый, но изнутри в разных местах выпирает что-то твердое. Размеры кокона позволяют предположить, что внутри может находиться гуманоид среднего роста... и сквозь стенки кокона действительно просвечивают очертания фигуры гуманоида!', 0);

-- Add ruRU offer rewards for quest 4141
-- https://ru.tbc.wowhead.com/quest=4141/майджин-и-ларион
SET @ID := 4141;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Надеюсь, они не доставили тебе забот, $N? Крайне дикие создания!$B$BОднажды я попытался перепрыгнуть через один такой цветочек, так он напал на меня! Растения не должны так себя вести...', 0);

-- Add ruRU offer rewards for quest 4142
-- https://ru.tbc.wowhead.com/quest=4142/визит-к-грегану
SET @ID := 4142;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Надеюсь, они не доставили тебе забот, $N? Крайне дикие создания!$B$BОднажды я попытался перепрыгнуть через один такой цветочек, так он напал на меня! Растения не должны так себя вести...', 0);

-- Add ruRU offer rewards for quest 4143
-- https://ru.tbc.wowhead.com/quest=4143/туман-зла
SET @ID := 4143;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Признаю, мне очень боязно прикасаться с этой штуке, $N! Но раз Греган утверждает, что она работает, надо попробовать.', 0);

-- Add ruRU offer rewards for quest 4144
-- https://ru.tbc.wowhead.com/quest=4144/побеги-кровоцвета
SET @ID := 4144;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, приступим, $N! Уж это привлечет внимание Лариона, будь $Gуверен:уверена;!', 0);

-- Add ruRU offer rewards for quest 4145
-- https://ru.tbc.wowhead.com/quest=4145/ларион-и-майджин
SET @ID := 4145;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо за помощь, $N, однако боюсь, у меня плохие новости...', 0);

-- Add ruRU offer rewards for quest 4146
-- https://ru.tbc.wowhead.com/quest=4146/питание-для-шокера
SET @ID := 4146;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так Марвона там не было? И что же ты оттуда $Gпринес:принесла;?', 0);

-- Add ruRU offer rewards for quest 4147
-- https://ru.tbc.wowhead.com/quest=4147/мастерская-марвона
SET @ID := 4147;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Марвона здесь давно нет, $N. Он отправился в Танарис, изучать развалины древних поселений троллей.$B$BА зачем он был тебе нужен?', 0);

-- Add ruRU offer rewards for quest 4148
-- https://ru.tbc.wowhead.com/quest=4148/разряд-кровоцвета
SET @ID := 4148;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Похоже, это устройство прекрасно сработает, $N. Помни, как только заметишь где-нибудь этих паразитов, немедленно используй шокер!', 0);

-- Add ruRU offer rewards for quest 4181
-- https://ru.tbc.wowhead.com/quest=4181/гоблинское-инженерное-дело
SET @ID := 4181;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, $N, ты разумно поступаешь, прося у меня наставничества! Любой дурак может стать экспертом в азах инженерного дела – что прекрасно видно на примере гномов и их радиоактивного Гномрегана. Для овладения гоблинским инженерным делом требуется крепкая соображаловка и твердая (повторяю – ТВЕРДАЯ) рука.$B$BДержи ушки на макушке, $N, может, что и усвоишь.', 0);

-- Add ruRU offer rewards for quest 4182
-- https://ru.tbc.wowhead.com/quest=4182/драконья-угроза
SET @ID := 4182;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добрая охота, $N. Ну, раз ты можешь справиться с драконами и их прихвостнями, пора поговорить о более насущных проблемах.', 0);

-- Add ruRU offer rewards for quest 4183
-- https://ru.tbc.wowhead.com/quest=4183/подлинные-хозяева
SET @ID := 4183;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Мировой судья Соломон распечатывает письмо от Хелендиса и начинает читать.>', 0);

-- Add ruRU offer rewards for quest 4184
-- https://ru.tbc.wowhead.com/quest=4184/подлинные-хозяева
SET @ID := 4184;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Драконы? Быть того не может!', 0);

-- Add ruRU offer rewards for quest 4185
-- https://ru.tbc.wowhead.com/quest=4185/подлинные-хозяева
SET @ID := 4185;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Болвар подпирает рукой подбородок, как бы глубоко задумавшись.>$B$BВ то время как я уважаю позицию леди Престор, я уверен, что для этой дилеммы есть решение, которое могло бы развеять все наши тревоги.', 0);

-- Add ruRU offer rewards for quest 4186
-- https://ru.tbc.wowhead.com/quest=4186/подлинные-хозяева
SET @ID := 4186;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, полагаю, могло быть и хуже...$B$B<Мировой судья изучает вас взглядом.>$B$BПохоже, что судьба Озер ложится теперь на ваши плечи.$B$B<Вы замечаете, что мировой судья часто-часто моргает. Кажется, он плачет.>', 0);

-- Add ruRU offer rewards for quest 4223
-- https://ru.tbc.wowhead.com/quest=4223/подлинные-хозяева
SET @ID := 4223;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Маршал Максвелл смеется.>', 0);

-- Add ruRU offer rewards for quest 4224
-- https://ru.tbc.wowhead.com/quest=4224/подлинные-хозяева
SET @ID := 4224;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я мог бы тебя предупредить, но разве это интересно?', 0);

-- Add ruRU offer rewards for quest 4241
-- https://ru.tbc.wowhead.com/quest=4241/маршал-винздор
SET @ID := 4241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Где он! Я убью его!', 0);

-- Add ruRU offer rewards for quest 4242
-- https://ru.tbc.wowhead.com/quest=4242/утраченная-надежда
SET @ID := 4242;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вполне очевидно, что он повредился рассудком.$B$B<Максвелл скорбно склоняет голову.>$B$BПечально, когда благородный и доблестный воин превращается в невменяемого идиота. Как я понимаю, мы зашли в тупик...$B$BНо ты хорошо $Gпотрудился:потрудилась;, $N. И получишь награду.', 0);

-- Add ruRU offer rewards for quest 4243
-- https://ru.tbc.wowhead.com/quest=4243/в-поисках-чи-та-3
SET @ID := 4243;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Осмотрев Чи-Та 3, вы обнаруживаете две глубоких вмятины в творении инженерного искусства Карны. Одна вмятина украшает плечо робота, другая зияет на голове.$B$BПохоже, энергии в машине не осталось.', 0);

-- Add ruRU offer rewards for quest 4244
-- https://ru.tbc.wowhead.com/quest=4244/в-поисках-чи-та-3
SET @ID := 4244;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы снова отдвигаете панель на спине Чи-Та 3 и осторожно вынимаете обгоревшую мифриловую обшивку, заменяя ее новой. Если действительно считать, что это и была основная причина поломки, то осталось лишь включить питание.', 0);

-- Add ruRU offer rewards for quest 4245
-- https://ru.tbc.wowhead.com/quest=4245/в-поисках-чи-та-3
SET @ID := 4245;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, тебе удалось, какое счастье! Спасибо, $N!$B$BО, моя бедняжечка! Как тебе досталось! Ничего, я починю тебя, будешь как новенькая!$B$BЕще раз благодарю тебя, $N, твоя помощь неоценима.', 0);

-- Add ruRU offer rewards for quest 4263
-- https://ru.tbc.wowhead.com/quest=4263/опалитель
SET @ID := 4263;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О небо! Ты $Gуверен:уверена;, что Опалитель сказал перед смертью "Рагнарос"?$B$B<Джалинда протягивает вам что-то и морщит лоб в раздумье.>', 0);

-- Add ruRU offer rewards for quest 4264
-- https://ru.tbc.wowhead.com/quest=4264/измятая-записка
SET @ID := 4264;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Маршал Виндзор читает записку.>', 0);

-- Add ruRU offer rewards for quest 4265
-- https://ru.tbc.wowhead.com/quest=4265/освобожденный-из-улья
SET @ID := 4265;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'С возвращением, $N! Раскал не так давно явился ко мне и сообщил обо всем, что произошло.$B$BЯ... да что там, вся наша крепость не знает, как тебя благодарить за твои подвиги. Раскал погиб бы, если бы не твоя своевременная помощь. А ведь ты помогаешь нам не ради платы, как какой-нибудь наемник! Ты – подлинный герой. Знай, что отныне Гинро Пылающий Очаг – твой друг до скончания веков!', 0);

-- Add ruRU offer rewards for quest 4266
-- https://ru.tbc.wowhead.com/quest=4266/благодарность-за-отвагу
SET @ID := 4266;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N, я от души благодарю тебя за всю оказанную тобой помощь. Твоя отвага перед лицом превосходящих сил противника достойна награды в тысячу раз большей. Тем не менее, я надеюсь, что ты примешь в дар от всей крепости хотя бы это.$B$BА теперь, если можно... я хотела бы попросить тебя еще об одной услуге. Сейчас, когда здесь, в Фераласе, обнаружен улей Цуккаш, думаю, это задание следует поручить именно тебе...', 0);

-- Add ruRU offer rewards for quest 4267
-- https://ru.tbc.wowhead.com/quest=4267/появление-силитидов
SET @ID := 4267;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Нам, ночным эльфам, немало известно об ужасах, описанных в этом докладе. Сандрис поступила мудро, отправив ко мне доклад – и тебя с ним.$B$BЭти твари стремительно заполонят весь Фералас. Можно сказать, что это одна из самых страшных опасностей, какие нам когда-либо грозили! Насекомые, с которыми столкнулись вы с курьером, называются силитидами. Они – всего лишь орудие одной из величайших угроз, с какими встречались как Альянс, так и Орда.$B$BМолюсь, чтобы у нас хватило решимости разгромить их прежде, чем они уничтожат нас!', 0);

-- Add ruRU offer rewards for quest 4281
-- https://ru.tbc.wowhead.com/quest=4281/посылка-в-таланаар
SET @ID := 4281;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Слава Элуне! Наконец-то пришла посылка из Крепости Оперенной Луны!$B$BНо раз ее $Gпринес:принесла; ты, значит, с нашим курьером, Раскалом, что-то случилось? Надеюсь, что все уладится... Насколько я знаю, в последнее время гноллы из клана Древолапов очень боятся чего-то, что происходит на юге. Может быть, Раскал заблудился в глуши? Будь осторожнее.$B$BНу, как бы то ни было, спасибо тебе еще раз. А вот и плата за доставку!', 0);

-- Add ruRU offer rewards for quest 4282
-- https://ru.tbc.wowhead.com/quest=4282/проблеск-надежды
SET @ID := 4282;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Маршал Виндзор выхватывает у вас из рук таблички.>$B$BУходим!', 0);

-- Add ruRU offer rewards for quest 4283
-- https://ru.tbc.wowhead.com/quest=4283/пятьдесят-ага
SET @ID := 4283;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gсправился:справилась;! И вот твоя награда: ПОЧЕШИ МНЕ ЖИВОТИК! ДАВАЙ! ЧЕШИ!', 0);

-- Add ruRU offer rewards for quest 4285
-- https://ru.tbc.wowhead.com/quest=4285/северный-пилон
SET @ID := 4285;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я знаю, что все эти рассказы – правда, $N.', 0);

-- Add ruRU offer rewards for quest 4286
-- https://ru.tbc.wowhead.com/quest=4286/хороший-товар
SET @ID := 4286;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Орелиус роется в груде поясных сумок.>$B$BВЕЛИКОЛЕПНО!$B$B<Орелиус сует нос в кучу и принюхивается.>$B$BВОСХИТИТЕЛЬНО! Только посмотри на это добро!$B$BВозьми одну себе, здесь их полно.', 0);

-- Add ruRU offer rewards for quest 4287
-- https://ru.tbc.wowhead.com/quest=4287/восточный-пилон
SET @ID := 4287;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ун\'Горо такое странное место, $N! Входишь – и будто оказываешься в другом мире!', 0);

-- Add ruRU offer rewards for quest 4288
-- https://ru.tbc.wowhead.com/quest=4288/западный-пилон
SET @ID := 4288;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В стенах кратера много ниш и пещер. Попробуй обыскать извилистые тропинки в тех местах, если больше ничего не можешь придумать.', 0);

-- Add ruRU offer rewards for quest 4289
-- https://ru.tbc.wowhead.com/quest=4289/обезьяны-унгоро
SET @ID := 4289;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Значит, тебе хватило сил одолеть обезьян Ун\'Горо. Это славно. Конечно, это не такая сложная задача, как сражение с Лар\'корви, и все же немалая победа.$B$BМое племя обрадуется шкурам, из них получатся прекрасные одежды! Ты $Gпомог:помогла; мне и $Gпоказал:показала; себя $Gдостойным:достойной;.$B$BПрежде чем ты отправишься далее, воздадим хвалу Матери-Земле и поблагодарим духов обезьян, убитых тобой – они должны знать, что их смерть была не напрасна!', 0);

-- Add ruRU offer rewards for quest 4290
-- https://ru.tbc.wowhead.com/quest=4290/добыча-ларкорви
SET @ID := 4290;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Этот кусок послужит хорошей приманкой, $N. Похоже, удача в охоте сопутствует Лар\'корви. Однако странно, где он смог найти жесткозуба в этих краях...$B$BЯ сохраню это для тебя до тех пор, пока ты не будешь $Gготов:готова; встретиться с чудовищем. Не волнуйся за меня – полагаю, ты уже $Gуспел:успела; так разозлить Лар\'корви, что он не станет убивать меня раньше, чем вкусит твоей плоти.', 0);

-- Add ruRU offer rewards for quest 4291
-- https://ru.tbc.wowhead.com/quest=4291/запах-ларкорви
SET @ID := 4291;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это отличные образцы, $N. С их помощью мы сможем выманить Лар\'корви. Мне не терпится узнать, чем закончится твой бой с чудовищем. Это огромная тварь с зубами, подобными булатным клинкам. Ты посмотришь в его глаза и познаешь, каков взгляд смерти.', 0);

-- Add ruRU offer rewards for quest 4292
-- https://ru.tbc.wowhead.com/quest=4292/приманка-для-ларкорви
SET @ID := 4292;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хвала Матери-Земле! Ты $Gсправился:справилась;!Ты $Gпоказал:показала; себя $Gвеликим:великой;, $N. Твой дух силен. Твоей храбрости нет равных. А сила твоя укрепилась. Я склоняюсь пред твоим мастерством.$B$BТолько самым великим из моих предков были под силу подобные свершения.', 0);

-- Add ruRU offer rewards for quest 4293
-- https://ru.tbc.wowhead.com/quest=4293/проба-слизи
SET @ID := 4293;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно. Эти пробы прекрасно подойдут. Благодарю за помощь.$B$BСобрав все образцы слизи, мы сможем двинуться дальше. Я начинаю подозревать, что леди Сильвана не зря заинтересовалась этими существами. Более того, сама того не зная, она, похоже, оказалась на грани великого открытия. Эти пробы очень интересны. А как они прореагировали с моими препаратами... хм, да, нам есть над чем поработать.', 0);

-- Add ruRU offer rewards for quest 4294
-- https://ru.tbc.wowhead.com/quest=4294/и-образцы-слизнюков
SET @ID := 4294;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Удивительно! Кратер Ун\'Горо таит куда больше секретов, чем я думал. Интересно, какие еще открытия нас ждут?$B$BПоразительно... Изумительно чистые образцы. Хм, что бы это значило? Похоже, по природе они относятся скорее к стихиям... но непростым. Они напоминают мне... о Древних богах. Мы находили их следы по всему Азероту – вдруг и эти существа каким-то образом связаны с ними?$B$BНадо продолжать исследования.', 0);

-- Add ruRU offer rewards for quest 4295
-- https://ru.tbc.wowhead.com/quest=4295/эль-для-каменного-узла
SET @ID := 4295;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это что? Ага! Пахнет элем Черного Железа! Пусть я пьян и мало что соображаю, но скажу тебе, добрый сэр: ты настоящий друг!', 0);

-- Add ruRU offer rewards for quest 4296
-- https://ru.tbc.wowhead.com/quest=4296/табличка-семерых
SET @ID := 4296;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты $Gнашел:нашла; табличку! И как хорошо переписан текст! Ты точно |3-6($C), а не $Gпереписчик:переписчица;?$B$BВот, возьми,$N. Это обещанные деньги.', 0);

-- Add ruRU offer rewards for quest 4297
-- https://ru.tbc.wowhead.com/quest=4297/покормить-малыша
SET @ID := 4297;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это мясо вполне годится. А тем временем, если я не ошибаюсь, твой дракончик начинает вылупляться! Ну, как тебе это? В смысле, каково быть $Gпапой:мамой;? Груз ответственности не давит пока?', 0);

-- Add ruRU offer rewards for quest 4298
-- https://ru.tbc.wowhead.com/quest=4298/у-вас-появился-малыш
SET @ID := 4298;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот, бери яйцо... Тебе лучше держать его при себе, чтобы вылупившийся детеныш сразу привязался к тебе. Тогда он будет считать тебя $Gсвоим:своей; $Gпапочкой:мамочкой;.$B$BНу все, $N, поздравляю! У тебя теперь все равно что собственный ребенок!', 0);

-- Add ruRU offer rewards for quest 4300
-- https://ru.tbc.wowhead.com/quest=4300/костяные-клинки
SET @ID := 4300;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это то, что надо! Спасибо, $N. И тебе удалось уложиться в срок... это замечательно.$B$BБыть может, мы сумеем изготовить из этих когтей оружие и для тебя. Что скажешь?', 0);

-- Add ruRU offer rewards for quest 4301
-- https://ru.tbc.wowhead.com/quest=4301/могучая-уча
SET @ID := 4301;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N! Я доволен. Сегодня ты $Gсовершил:совершила; великое деяние.$B$BУча была одной из самых огромных обезьян, виденных мною за всю жизнь. То, что ты $Gсмог:смога; сразить ее, говорит о твоей собственной силе и храбрости.$B$BПрими это в знак моего уважения. Ты $Gзаслужил:заслужила; это.', 0);

-- Add ruRU offer rewards for quest 4321
-- https://ru.tbc.wowhead.com/quest=4321/давай-ка-разберемся
SET @ID := 4321;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так вот, $N! Все это очень интересно... Надюсь, мои диаграммы верны! Я собрала все сведения в эту книгу и отдам ее тебе.$B$BПолагаю, теперь я могу ответить на все твои вопросы о кристаллах, $N.', 0);

-- Add ruRU offer rewards for quest 4322
-- https://ru.tbc.wowhead.com/quest=4322/побег
SET @ID := 4322;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поразительно, $N. Просто невероятно. Виндзор был здесь буквально перед твоим приходом. Ворвался, как ураган, весь такой разгоряченный и буйный. Его притязания поистине грандиозны, но он заявляет, что у него есть на то основания. Сейчас он направляется в Штормград и собирается бросить вызов Болвару и... госпоже Престор.', 0);

-- Add ruRU offer rewards for quest 4324
-- https://ru.tbc.wowhead.com/quest=4324/юка-крутипроб
SET @ID := 4324;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я ищу брата. Его надо найти и вернуть.$B$BПриведи его ко мне. А если он будет сопротивляться... тогда принеси мне хотя бы его голову.', 0);

-- Add ruRU offer rewards for quest 4362
-- https://ru.tbc.wowhead.com/quest=4362/судьба-королевства
SET @ID := 4362;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Принцесса оплакивает гибель императора Даграна Тауриссана.>$B$BЗа что???', 0);

-- Add ruRU offer rewards for quest 4363
-- https://ru.tbc.wowhead.com/quest=4363/королевский-сюрприз
SET @ID := 4363;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Король Магни Бронзобород явно расстроен.>$B$BСдается мне, даже в смерти Тауриссан победил.$B$BБольше я не нуждаюсь в твоих услугах, $N. Но прежде чем ты покинешь нас, выбери себе награду из королевских сокровищниц.$B$B<Король садится на трон и погружается в раздумья.>', 0);

-- Add ruRU offer rewards for quest 4381
-- https://ru.tbc.wowhead.com/quest=4381/кристалл-восстановления
SET @ID := 4381;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы аккуратно выстраиваете кристаллы в табличке. Когда последний из них занимает свое место, вспыхивает яркий свет, и кристаллы оказываются сплавлены воедино.$B$BТеперь полученное сочетание – ваше.', 0);

-- Add ruRU offer rewards for quest 4382
-- https://ru.tbc.wowhead.com/quest=4382/кристалл-силы-духа
SET @ID := 4382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы аккуратно выстраиваете кристаллы в табличке. Когда последний из них занимает свое место, вспыхивает яркий свет, и кристаллы оказываются сплавлены воедино.$B$BТеперь полученное сочетание – ваше.', 0);

-- Add ruRU offer rewards for quest 4383
-- https://ru.tbc.wowhead.com/quest=4383/кристалл-хранитель
SET @ID := 4383;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы аккуратно выстраиваете кристаллы в табличке. Когда последний из них занимает свое место, вспыхивает яркий свет, и кристаллы оказываются сплавлены воедино.$B$BТеперь полученное сочетание – ваше.', 0);

-- Add ruRU offer rewards for quest 4384
-- https://ru.tbc.wowhead.com/quest=4384/хрустальный-удар
SET @ID := 4384;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы аккуратно выстраиваете кристаллы в табличке. Когда последний из них занимает свое место, вспыхивает яркий свет, и кристаллы оказываются сплавлены воедино.$B$BТеперь полученное сочетание – ваше.', 0);

-- Add ruRU offer rewards for quest 4385
-- https://ru.tbc.wowhead.com/quest=4385/хрустальный-заряд
SET @ID := 4385;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы аккуратно выстраиваете кристаллы в табличке. Когда последний из них занимает свое место, вспыхивает яркий свет, и кристаллы оказываются сплавлены воедино.$B$BТеперь полученное сочетание – ваше.', 0);

-- Add ruRU offer rewards for quest 4386
-- https://ru.tbc.wowhead.com/quest=4386/хрустальная-спираль
SET @ID := 4386;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы аккуратно выстраиваете кристаллы в табличке. Когда последний из них занимает свое место, вспыхивает яркий свет, и кристаллы оказываются сплавлены воедино.$B$BТеперь полученное сочетание – ваше.', 0);

-- Add ruRU offer rewards for quest 4449
-- https://ru.tbc.wowhead.com/quest=4449/попался
SET @ID := 4449;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, какое облегчение! Как я рад, $N! Тебе удалось отомстить проклятым геологам? Их наглость не знала границ, однако. Не знаю как благодарить тебя! Ты это... погоди минутку, мне тут надо закончить некоторые дела...', 0);

-- Add ruRU offer rewards for quest 4450
-- https://ru.tbc.wowhead.com/quest=4450/учетная-книга-из-танариса
SET @ID := 4450;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ого, да ты $Gсмог:смогла; выполнить эту работу! Прекрасно. Полагаю, теперь ты попросишь меня выковать для тебя что-нибудь.$B$BУ меня есть превосходное оружие и доспехи. Благодарю тебя, |3-6($C)!$B$BДумаю, ты $Gзаслужил:заслужила;... хммм... что-нибудь полезное.', 0);

-- Add ruRU offer rewards for quest 4451
-- https://ru.tbc.wowhead.com/quest=4451/ключ-к-свободе
SET @ID := 4451;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот те на! Чтоб мне провалиться! Ты $Gнашел:нашл; ключ! Я знал, что проклятые дворфы Черного Железа спрятали его, после того как заперли меня в этой дыре! О, благодарю тебя, $N! Скорее открой дверь и выпусти старика Локида на свободу!', 0);

-- Add ruRU offer rewards for quest 4463
-- https://ru.tbc.wowhead.com/quest=4463/манускрипт-размышления
SET @ID := 4463;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Забирай свою безделушку, неразумная тварь. Оставь меня в покое!', 0);

-- Add ruRU offer rewards for quest 4481
-- https://ru.tbc.wowhead.com/quest=4481/манускрипт-здоровья
SET @ID := 4481;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это вызов его памяти... Смертный оканчивает работу всей его жизни.$B$BЗабирай свою безделушку и убирайся!', 0);

-- Add ruRU offer rewards for quest 4482
-- https://wowroad.info/goha.ru?quest=4482
SET @ID := 4482;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Кариэль потребовалось несколько жизней, чтобы завершить текущую библиотеку, $R.Все для чего? Чтобы его ученик мог стоять в Пылающих степях и убивать свои исследования, чтобы утолить нескончаемую тайную жажду ... Прокляните эту гнусную зависимость.$B$BМне противно ваше отсутствие сострадания и ненасытная жадность. Уходи!', 0);

-- Add ruRU offer rewards for quest 4483
-- https://ru.tbc.wowhead.com/quest=4483/манускрипт-устойчивости
SET @ID := 4483;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прочие манускрипты рассеяны по свету. По таким уголкам, куда ты не осмелишься войти. Которых бы лучше и не было.$B$BЯ выпью из этих составляющих силу. А ты получишь то, что останется...', 0);

-- Add ruRU offer rewards for quest 4484
-- https://ru.tbc.wowhead.com/quest=4484/манускрипт-ненасытности
SET @ID := 4484;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Голова болит... Сила бескрайних пределов вселенной... Ахххх!$B$B<Матредис кривится от боли.>$B$BБери, что тебе нужно, и уходи!', 0);

-- Add ruRU offer rewards for quest 4489
-- https://ru.tbc.wowhead.com/quest=4489/призывание-коня-скверны
SET @ID := 4489;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Значит, ты снова $Gрешил:решила; пожаловать меня своим визитом. Очень мило с твоей стороны.$B$BМои помощники все гадали – придешь или нет? Я говорил им – несомненно, придет. Когда речь заходит о могуществе, летишь как мотылек на свечу.', 0);

-- Add ruRU offer rewards for quest 4490
-- https://ru.tbc.wowhead.com/quest=4490/призывание-коня-скверны
SET @ID := 4490;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Удачи, $N. Надеюсь встретиться с тобой в будущем.', 0);

-- Add ruRU offer rewards for quest 4491
-- https://ru.tbc.wowhead.com/quest=4491/дружеская-помощь
SET @ID := 4491;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, Ринго совсем плох, $N, но я рада, что он вернулся в целости и сохранности...$B$BСпасибо, что $Gразыскал:разыскала; его!', 0);

-- Add ruRU offer rewards for quest 4492
-- https://ru.tbc.wowhead.com/quest=4492/потерялся
SET @ID := 4492;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, я так рад, что ты $Gнашел:нашла; меня!', 0);

-- Add ruRU offer rewards for quest 4494
-- https://ru.tbc.wowhead.com/quest=4494/нашествие-силитидов
SET @ID := 4494;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я так понимаю, тебя Зилзибин прислал? Твой опыт воистину бесценен: до тебя я не встречал никого, кому доводилось сражаться с этими тварями. Что касается идеи Зиба насчет Кратера Ун\'Горо... Может быть, он и прав. Ун\'Горо – это таинственные и опасные джунгли к западу отсюда. Может быть, мы действительно подошли на шаг ближе к разрешению загадки силитидов.', 0);
