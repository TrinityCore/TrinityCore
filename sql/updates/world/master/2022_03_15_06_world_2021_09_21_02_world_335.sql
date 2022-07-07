-- Add ruRU offer rewards for quest 2701
-- https://ru.tbc.wowhead.com/quest=2701/герои-древних-времен
SET @ID := 2701;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Искристый блеск на какое-то время ослепляет вас.', 0);

-- Add ruRU offer rewards for quest 2702
-- https://ru.tbc.wowhead.com/quest=2702/герои-древних-времен
SET @ID := 2702;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поистине, ты оказываешь честь нам всем. Одних лишь благодарностей будет недостаточно.', 0);

-- Add ruRU offer rewards for quest 2721
-- https://ru.tbc.wowhead.com/quest=2721/кирит
SET @ID := 2721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Требор? Тебя послал Требор?', 0);

-- Add ruRU offer rewards for quest 2742
-- https://ru.tbc.wowhead.com/quest=2742/ринджи-в-ловушке
SET @ID := 2742;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эта табличка, наверное, и есть тот самый "секрет", о котором говорил Рин\'джи.$B$BОна покрыта странными письменами, которые вам совершенно не знакомы.', 0);

-- Add ruRU offer rewards for quest 2743
-- https://ru.tbc.wowhead.com/quest=2743/покров-тьмы
SET @ID := 2743;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Повелитель демонов проявляет хитрость почти столь же расчетливую, как и его жестокость, $N.', 0);

-- Add ruRU offer rewards for quest 2744
-- https://ru.tbc.wowhead.com/quest=2744/охотник-на-демонов
SET @ID := 2744;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я помогу тебе. Однако мне кажется, что ты не совсем понимаешь, против чего сражаешься.', 0);

-- Add ruRU offer rewards for quest 2751
-- https://wowroad.info/goha.ru?quest=2751
SET @ID := 2751;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наш род иссякнет, но, возможно, легенды об Омошах будут жить!$B$BДа, $N, ты настоящий кузнец! Главная награда для кузнеца – видеть оружие и доспехи своей работы обагренными кровью врагов!$B$BПусть изготовленная тобою кираса ржавеет только от вражеской крови!', 0);

-- Add ruRU offer rewards for quest 2752
-- https://ru.tbc.wowhead.com/quest=2752/за-железными-наплечниками
SET @ID := 2752;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Орокк гордится тобой, $N. Вот, читай, как изготовить железное оплечье!', 0);

-- Add ruRU offer rewards for quest 2753
-- https://ru.tbc.wowhead.com/quest=2753/тяжелая-поступь
SET @ID := 2753;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты напоминаешь Орокку его деда, Горокка Омоша! Вот, читай, учись делать железные сапоги.', 0);

-- Add ruRU offer rewards for quest 2754
-- https://ru.tbc.wowhead.com/quest=2754/рога-безумия
SET @ID := 2754;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Потрясающе, $N! Теперь ты знаешь все секреты Омошей!', 0);

-- Add ruRU offer rewards for quest 2755
-- https://ru.tbc.wowhead.com/quest=2755/радости-омоша
SET @ID := 2755;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Давненько Орокк не плясал танец Радости Омошей! Ну, $N, смотри и учись!', 0);

-- Add ruRU offer rewards for quest 2756
-- https://wowroad.info/goha.ru?quest=2756
SET @ID := 2756;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Похоже ты еще жив, $N. Как разочаровывающе. Разве ты не знаешь, что самой славной наградой является смерть на поле битвы! А я вот здесь, по приказу Тралла учу детишек мастерить. Смотри и учись... дитя...', 0);

-- Add ruRU offer rewards for quest 2757
-- https://ru.tbc.wowhead.com/quest=2757/вперед-в-пиратскую-бухту
SET @ID := 2757;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Клянусь задницей Черного Копыта! Наконец хоть кто-то достойный Ордена мифрила!', 0);

-- Add ruRU offer rewards for quest 2766
-- https://ru.tbc.wowhead.com/quest=2766/найти-ккx-22-fe
SET @ID := 2766;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы помещаете яйцо... то есть аварийный маяк... внутрь цыпленка... то есть автономного робота.$B$BВнутри робота слышится гудение и жужжание. Он пытается подняться на ноги. После того как робот оживает, снова слышится голос Карлса, но на этот раз изнутри робота:$B$B"Ну что ж, по крайней мере, OOX-22/FE работает. Однако он нуждается в серьезном ремонте! Нести его вы не сможете, он слишком тяжелый... О! У меня идея! Не согласитесь ли вы его проводить?"', 0);

-- Add ruRU offer rewards for quest 2767
-- https://ru.tbc.wowhead.com/quest=2767/спасти-ккx-22-fe
SET @ID := 2767;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, спаситель! Вы доставили на место OOX-22/FE! У меня просто слов нет, настолько я вам благодарен! Моя серия автономных роботов постоянно нуждается в усовершенствованиях, однако ваша помощь сберегла мне немало часов кропотливой работы, и дорогостоящих деталей вдобавок!$B$BПрошу вас, выбирайте любую из этих готовых моделей. Еще раз спасибо вам, $N! Мы с моими роботами – ваши должники!', 0);

-- Add ruRU offer rewards for quest 2782
-- https://ru.tbc.wowhead.com/quest=2782/секрет-ринджи
SET @ID := 2782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хм, какая необычная табличка... Где вы ее взяли, $N?', 0);

-- Add ruRU offer rewards for quest 2784
-- https://ru.tbc.wowhead.com/quest=2784/попавший-в-немилость
SET @ID := 2784;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Будучи духом, я бессилен что-либо сделать. Помоги мне, $N. Дай мне возможность снова обрести свою честь.', 0);

-- Add ruRU offer rewards for quest 2821
-- https://ru.tbc.wowhead.com/quest=2821/знак-качества
SET @ID := 2821;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну что, видишь, каковы эти шкуры? Надо тебе сказать, что после специальной обработки они делаются прочнее железа! Немногие про это знают, а вот я, с помощью своих особых дубильных составов, смогу делать из них вещи несравненного качества! Ну да, и все это – благодаря тебе.$B$BПожалуйста, $N, выбирай себе любое из моих готовых изделий.', 0);

-- Add ruRU offer rewards for quest 2822
-- https://ru.tbc.wowhead.com/quest=2822/знак-качества
SET @ID := 2822;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, отлично! Надо тебе сказать, что эти шкуры после специальной обработки делаются прочнее железа! Правда, подобрать состав для дубления не так-то просто, но все равно, я уверен, что мои вещи, изготовленные из них, будут еще лучше прежнего.$B$BЧто до тебя, $N, – ты воистину $Gбесценный:бесценная; $Gпомощник:помощница;! Пожалуйста, выбирай себе любое из моих готовых изделий.', 0);

-- Add ruRU offer rewards for quest 2844
-- https://ru.tbc.wowhead.com/quest=2844/великан-опекун
SET @ID := 2844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ой, как хорошо, что ты меня $Gнашел:нашла;! По правде говоря, я немножко заблудилась... Но тут очень красиво, правда?', 0);

-- Add ruRU offer rewards for quest 2845
-- https://ru.tbc.wowhead.com/quest=2845/шай-бродяжница
SET @ID := 2845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Шо? Так говоришь, этот колокольчик помогает найти Шай, когда она убежала? Вот это да!$B$BНу, $N, раз я стольким тебе обязан, на, держи!', 0);

-- Add ruRU offer rewards for quest 2847
-- https://wowroad.info/goha.ru?quest=2847
SET @ID := 2847;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, я рад, что ты уже с нами, так сказать, на борту. Ты получишь начальные знания в создании дикарских кожаных доспехов и, как я говорил, практически даром. За работу же!', 0);

-- Add ruRU offer rewards for quest 2848
-- https://ru.tbc.wowhead.com/quest=2848/наплечники-из-дикой-кожи
SET @ID := 2848;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, это хорошие, надежные наборы для усиления брони. Если я чего требую не только от себя, но и от своих подмастерьев, так это высокого качества!$B$BТы неплохо $Gпотрудился:потрудилась;, и заслуживаешь того, чтобы получить эту выкройку. Надеюсь, она позволит тебе добиться не меньшего уважения, чем мне.', 0);

-- Add ruRU offer rewards for quest 2849
-- https://ru.tbc.wowhead.com/quest=2849/жилет-из-дикой-кожи
SET @ID := 2849;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, неплохие вещицы! За одно умение и старание, вложенное в них, можно получить несколько лишних серебряных монет.$B$BНу что, мой приказ выполнен, вот и твоя награда. Теперь ты умеешь изготовлять дикарские кожаные жилеты!', 0);

-- Add ruRU offer rewards for quest 2850
-- https://ru.tbc.wowhead.com/quest=2850/шлем-из-дикой-кожи
SET @ID := 2850;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это Ночное снаряжение – именно то, что я просил тебя принести, $N. Впрочем, от кожевника твоего уровня я другого и не ждал.$B$BТы $Gдостоин:достойна; уметь изготовлять дикарские кожаные шлемы. Вот тебе выкройка. Надеюсь, ты применишь ее с пользой.', 0);

-- Add ruRU offer rewards for quest 2851
-- https://wowroad.info/goha.ru?quest=2851
SET @ID := 2851;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Итак, ты $Gвыполнил:выполнила; комплексный заказ и как всегда $Gсделал:сделала; это профессионально. Так что получи эту выкройку и мою благодарность!', 0);

-- Add ruRU offer rewards for quest 2852
-- https://wowroad.info/goha.ru?quest=2852
SET @ID := 2852;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хм. Ты опять $Gвыполнил:выполнила; приказ. Возможно, в один прекрасный день я приду к тебе за знаниями, а, $N?$B$BВот выкройка поножей, вместе с моими благодарностями.', 0);

-- Add ruRU offer rewards for quest 2853
-- https://ru.tbc.wowhead.com/quest=2853/мастер-школы-дикаря
SET @ID := 2853;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты от Пратта! Он, конечно, человек, но временами напоминает мне нас, ночных эльфов. Он действительно гениальный кожевенник! И если он тебя так расхваливает, это говорит в твою пользу.$B$BНасколько я понимаю, он обучил тебя секретам дикарских кожаных доспехов? Позволь же, я завершу твое обучение, дав тебе вот эту выкройку. Пользуйся ею с умом: немного на свете тех, кто владеет тайной изготовления дикарских кожаных плащей!', 0);

-- Add ruRU offer rewards for quest 2854
-- https://ru.tbc.wowhead.com/quest=2854/доспехи-из-дикой-кожи
SET @ID := 2854;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну что ж, $N, я рад, что ты теперь $Gмой:моя; $Gученик:ученица;. Ты $Gпоступил:поступила; разумно, избрав ремесло кожевника: когда ты научишься изготовлять дикарские кожаные доспехи, у тебя отбою не будет от тех, кто одевается в кожу.$B$BНу, за работу! С чего мы начнем?', 0);

-- Add ruRU offer rewards for quest 2855
-- https://ru.tbc.wowhead.com/quest=2855/наплечники-из-дикой-кожи
SET @ID := 2855;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, это хорошие, надежные доспехи. Если я чего требую не только от себя, но и от своих учеников, так это высокого качества!$B$BТы неплохо $Gпотрудился:потрудилась;, и заслуживаешь того, чтобы получить эту выкройку. Надеюсь, она позволит тебе добиться не меньшего уважения, чем мне.', 0);

-- Add ruRU offer rewards for quest 2856
-- https://ru.tbc.wowhead.com/quest=2856/жилет-из-дикой-кожи
SET @ID := 2856;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, неплохие вещицы! Судя по умению и старанию, с какими они изготовлены, ты всерьез относишься к своему ремеслу.$B$BНу что, мой приказ выполнен, вот и твоя награда. Теперь ты умеешь изготовлять дикарские кожаные жилеты!', 0);

-- Add ruRU offer rewards for quest 2857
-- https://ru.tbc.wowhead.com/quest=2857/шлем-из-дикой-кожи
SET @ID := 2857;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это Ночное снаряжение – именно то, что я просил тебя принести, $N. Впрочем, от кожевника твоего уровня я другого и не ждал.$B$BТы достоин того, чтобы изготовлять дикарские кожаные шлемы. Вот тебе выкройка. Надеюсь, ты применишь ее с пользой.', 0);

-- Add ruRU offer rewards for quest 2858
-- https://ru.tbc.wowhead.com/quest=2858/сапоги-из-дикой-кожи
SET @ID := 2858;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'И снова ты выполняешь непростой заказ с искусством опытного профессионала! Ты $Gзаслужил:заслужила; эту выкройку, равно как и мою благодарность.', 0);

-- Add ruRU offer rewards for quest 2859
-- https://ru.tbc.wowhead.com/quest=2859/поножи-из-дикой-кожи
SET @ID := 2859;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну что, мой приказ снова выполнен отлично. Может, в один прекрасный день уже я явлюсь к тебе, как ученик к учителю, а, $N?$B$BВот выкройка поножей, а с ней и моя благодарность. Пусти полученные знания в дело, и пусть твои изделия будут достойны твоих способностей!', 0);

-- Add ruRU offer rewards for quest 2860
-- https://ru.tbc.wowhead.com/quest=2860/мастер-школы-дикаря
SET @ID := 2860;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты от Джангора! Приятно видеть, что у одного из моих лучших учеников теперь свои ученики…$B$BДжангор – очень талантливый и добросовестный кожевенник. И если он тебя так расхваливает, это говорит в твою пользу.$B$BНасколько я понимаю, он обучил тебя секретам дикарских кожаных доспехов? Позволь же, я завершу твое обучение, дав тебе вот эту выкройку. Пользуйся ею с умом: немного на свете тех, кто владеет тайной изготовления дикарских кожаных плащей!', 0);

-- Add ruRU offer rewards for quest 2862
-- https://ru.tbc.wowhead.com/quest=2862/война-с-племенем-древолапов
SET @ID := 2862;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Неплохое начало, $N! Таких воинов, как ты, еще поискать!$B$BЯ ведь давал такое задание не только тебе. И до тебя немало бойцов сражались с гноллами, и в былые времена наших усилий хватало, чтобы заставить их отступить. Однако в последнее время они упорно прут на север, в наши земли. Гноллы бьются так отчаянно... как будто им некуда отступать!$B$BОднако у меня есть один план. Возможно, он позволит раз и навсегда покончить с этой войной...', 0);

-- Add ruRU offer rewards for quest 2863
-- https://ru.tbc.wowhead.com/quest=2863/истребление-вожаков
SET @ID := 2863;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось выполнить мою просьбу. $GМолодец:Умница;, $N! Вот, прими эту небольшую награду за свои труды.$B$BТеперь, когда число гноллов сократилось, и их вожаки перебиты, эти твари дважды подумают, прежде чем решатся снова напасть на лагерь! Однако проблемы это не решает...$B$BГноллы не могли так озвереть безо всякой причины! И я хочу выяснить, в чем дело, прежде, чем они пришли в себя.', 0);

-- Add ruRU offer rewards for quest 2866
-- https://ru.tbc.wowhead.com/quest=2866/руины-соларсаля
SET @ID := 2866;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Внимательно изучив беседку, вы обнаруживаете следующее.$B$BВо-первых, беседка явно новая, и не похожа на окружающие руины. Во-вторых, столбы беседки исписаны мелкими значками. Значки повторяются, но что это за письмена и что они означают, вам непонятно. Ну и, в-третьих, камень беседки – теплый на ощупь.$B$BДа, все это, несомненно, подозрительно!', 0);

-- Add ruRU offer rewards for quest 2867
-- https://ru.tbc.wowhead.com/quest=2867/возвращение-в-крепость-оперенной-луны
SET @ID := 2867;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'С возвращением, $N! Обнаруженная тобой беседка действительно весьма... подозрительна. Очевидно, что даже если наги и не замышляют нападения, их присутствие не сулит нам ничего хорошего. Ну, как бы то ни было, вот твоя заслуженная награда.$B$BСудя по всему, Крепость Оперенной Луны отчаянно нуждается в помощи для борьбы с нагами из клана Гребня Ненависти. Я бы хотела дать тебе еще одно поручение, если ты не против...', 0);

-- Add ruRU offer rewards for quest 2869
-- https://ru.tbc.wowhead.com/quest=2869/борьба-с-гребнем-ненависти
SET @ID := 2869;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да-да, эта чешуя вполне годится. Думаю, мы отправим ее Пратту. Может быть, он сумеет изготовить из нее что-нибудь полезное.$B$BА для тебя у меня есть еще одно задание. Но сначала вот твоя награда за труды. Твоя служба генералу и всей Крепости Оперенной Луны очень ценна перед лицом грозящей нам опасности.', 0);

-- Add ruRU offer rewards for quest 2870
-- https://ru.tbc.wowhead.com/quest=2870/борьба-с-лордом-шалзару
SET @ID := 2870;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N! Гибель лорда Шалзару повергнет наг в смятение – надолго, если не навсегда. Так что теперь они представляют значительно меньшую угрозу, чем прежде, и все это – благодаря тебе!$B$BВот тебе новая награда из сокровищницы замка. Эта награда заслужена тобой – вся, вплоть до последней монеты! Добро пожаловать в Крепость Оперенной Луны в любое время, друг мой.$B$BДа, $N, и прежде, чем ты уйдешь... еще одна просьба...', 0);

-- Add ruRU offer rewards for quest 2871
-- https://ru.tbc.wowhead.com/quest=2871/доставка-реликвии
SET @ID := 2871;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Интересно... Так говоришь, это вещь из руин Соларсаля? Ну да, Латро прав: мне следовало на это взглянуть... Такое впечатление, что эта вещь – не оттуда. С другой стороны, на работу наг это тоже не похоже. Далеко не столь чуждое…$B$BМне потребуется некоторое время на то, чтобы с ней разобраться. А когда я завершу свои исследования, возможно, ты мне снова пригодишься – если ты, конечно, окажешься в это время поблизости.$B$BНа, возьми это – у нас таких вещиц много, а тебе она, думаю, пригодится!', 0);

-- Add ruRU offer rewards for quest 2876
-- https://ru.tbc.wowhead.com/quest=2876/расписание-кораблей
SET @ID := 2876;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ох, похоже это список рейсов, причем здесь указаны дни и часы отбытия и прибытия! Если эти сведения попали в руки капитана пиратского корабля, у нас будут большие неприятности!$B$BТы их у пирата нашел? Дурные вести…$B$BСпасибо, $N. Я рад, что ты $Gнашел:нашла; этот документ и $Gотправил:отправила; пирата кормить рыб!', 0);

-- Add ruRU offer rewards for quest 2879
-- https://ru.tbc.wowhead.com/quest=2879/посох-равноденствия
SET @ID := 2879;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Заряженный посох буквально вырывается из рук. Невероятная мощь отдается дрожью во всем теле.$B$BВы касаетесь холодной поверхности Монолита…$B$BОтворяется небольшая дверка, за ней виднеется артефакт.$B$BВсе пространство вокруг Монолита Равноденствия озаряется светом.', 0);

-- Add ruRU offer rewards for quest 2881
-- https://ru.tbc.wowhead.com/quest=2881/ожерелья-троллей
SET @ID := 2881;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Чем больше ожерелий, тем меньше троллей во Внутренних Землях! Вы $Gмолодец:умница;, $N. Так держать!', 0);

-- Add ruRU offer rewards for quest 2902
-- https://ru.tbc.wowhead.com/quest=2902/разведка-планов-древолапов
SET @ID := 2902;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это те самые планы, которые просил отыскать Хадокен Быстрый Странник. Множество стрелок, очевидно, обозначают передвижения войск, однако большая часть этих стрелок направлена не на север, к Лагерю Мохаче, а на юг.$B$BВ углу карты нарисовано нечто вроде крупного насекомого, окруженного разнообразными значками. Судя по всему, гноллов действительно донимают какие-то насекомые...', 0);

-- Add ruRU offer rewards for quest 2903
-- https://ru.tbc.wowhead.com/quest=2903/планы-битвы
SET @ID := 2903;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, это именно то, что нам нужно! Я, правда, не мастак разбирать всякие каракули, однако я на своем веку повидал достаточно планов битв, чтобы понять, что творится у гноллов. Похоже, сейчас они ведут войну на два фронта. Один противник – это мы... но, судя по всему, основные их силы брошены на юг.$B$BТут все не так просто! Возможно, пора выяснить, с кем же они воюют.', 0);

-- Add ruRU offer rewards for quest 2925
-- https://ru.tbc.wowhead.com/quest=2925/базовые-элементы-клацморта
SET @ID := 2925;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да! Да! Мне очень нужна помощь в Гномрегане! И |3-6($C) вроде тебя как раз подойдет!', 0);

-- Add ruRU offer rewards for quest 2931
-- https://ru.tbc.wowhead.com/quest=2931/поручение-чугонотрубза
SET @ID := 2931;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я готовлю миссию в Гномреган для возвращения важных данных. Если вы пришли помочь, то слушайте!', 0);

-- Add ruRU offer rewards for quest 2932
-- https://ru.tbc.wowhead.com/quest=2932/предупреждение
SET @ID := 2932;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'До меня дошли вести о ваших подвигах. Это жестокий поступок, но почетный. Надеюсь, тролли Сухокожих внимут нашему предупреждению.', 0);

-- Add ruRU offer rewards for quest 2933
-- https://ru.tbc.wowhead.com/quest=2933/бутыли-с-ядом
SET @ID := 2933;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, что это? Похоже на яд... яд какого-то паукообразного, да? Где же вы его взяли?', 0);

-- Add ruRU offer rewards for quest 2934
-- https://ru.tbc.wowhead.com/quest=2934/неповрежденная-ядовитая-железа
SET @ID := 2934;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, замечательно! Яд свежий и, я уверен, чрезвычайно смертоносный! Спасибо!', 0);

-- Add ruRU offer rewards for quest 2935
-- https://ru.tbc.wowhead.com/quest=2935/разговор-с-мастером-гадрином
SET @ID := 2935;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, так вам нужен свежий яд пауков Сухокожих? Ну что ж, присядьте... вам не понравится то, что я сейчас скажу.', 0);

-- Add ruRU offer rewards for quest 2936
-- https://ru.tbc.wowhead.com/quest=2936/паучья-богиня
SET @ID := 2936;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Элорта но Шадра... Произносите это имя лишь шепотом, потому что один его звук повергает духов в смятение.$B$BЯ напишу его на бумаге и сотворю для вас заклинание призыва.', 0);

-- Add ruRU offer rewards for quest 2937
-- https://ru.tbc.wowhead.com/quest=2937/призыв-шадры
SET @ID := 2937;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Лучше и быть не могло!', 0);

-- Add ruRU offer rewards for quest 2938
-- https://ru.tbc.wowhead.com/quest=2938/яд-в-подгород
SET @ID := 2938;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Лидон говорил, что яд в этом свертке – самый смертоносный из тех, что ему встречались, и теперь он в срочном порядке ищет способ его применения.$B$BНадеюсь, применений ему найдется немало.$B$BСпасибо, $N. Вы оказали Королевскому Фармацевтическому Обществу неоценимую услугу.', 0);

-- Add ruRU offer rewards for quest 2939
-- https://ru.tbc.wowhead.com/quest=2939/в-поисках-знаний
SET @ID := 2939;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, так ты от Трояса Лунного Бриза?$B$B*Бормочет себе под нос*$B$BВот вечно он меня донимает: ему все время кажется, что он обнаружил что-то чрезвычайно важное…$B$BПослушай, $N, я буду говорить откровенно. Троясу каждый раз кажется, будто он нашел в этих развалинах невесть какую диковинку. На самом же деле все, что там было ценного, давно уже растащили огры либо гарпии.$B$BТы, конечно, можешь порыться в библиотеке, но не думаю, что ты сумеешь найти что-то, что тебе пригодится.', 0);

-- Add ruRU offer rewards for quest 2940
-- https://ru.tbc.wowhead.com/quest=2940/история-фераласа
SET @ID := 2940;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хочешь взять "Историю Фераласа"?$B$BДай подумать…$B$BХорошо, я разрешу тебе позаимствовать эту книгу, $N, если ты сначала окажешь мне одну услугу.', 0);

-- Add ruRU offer rewards for quest 2941
-- https://ru.tbc.wowhead.com/quest=2941/в-обмен-на-книгу
SET @ID := 2941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты $Gодин:одна; из $Gстудентов:студенток; Дарин? Она очень сведущий историк, $N. Тебе повезло, что ты занимаешься под ее руководством.$B$BНу, давай я покажу тебе свой супер-хвататель. Он тебе понравится!', 0);

-- Add ruRU offer rewards for quest 2942
-- https://ru.tbc.wowhead.com/quest=2942/завтрашний-камень
SET @ID := 2942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я с самого вашего ухода не отрывался от книги, $N. Так вот: добытый вами камень называется Завтрашний камень. Для чего он нужен, я пока точно не знаю, однако понятно, что пустяковую вещь так прятать не стали бы.$B$BЯ буду продолжать свои исследования. Надеюсь, что я и в будущем смогу на вас рассчитывать, $N. Спасибо вам за все!', 0);

-- Add ruRU offer rewards for quest 2943
-- https://ru.tbc.wowhead.com/quest=2943/возвращение-к-троясу
SET @ID := 2943;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Книга у вас! Чудесно!', 0);

-- Add ruRU offer rewards for quest 2944
-- https://ru.tbc.wowhead.com/quest=2944/супер-хвататель-фх
SET @ID := 2944;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да! Изобретение Гурдл оправдало все мои ожидания!$B$BТы только не зазнавайся, $N, но имей в виду, что я тобой довольна.$B$BТак, где же я оставила эту книгу...', 0);

-- Add ruRU offer rewards for quest 2945
-- https://ru.tbc.wowhead.com/quest=2945/кольцо-покрытое-грязью
SET @ID := 2945;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы опускаете кольцо и три монеты в Чистер 5200.$B$BМашина с яростным гудением принимается за работу, скрипя и вибрируя. Сложно представить, что происходит внутри...$B$BНаконец Чистер 5200 замирает и окошко премника со звоном открывается. В нем лежит маленькая аккуратно завернутая коробка с красным бантиком. Похоже, Чистер 5200 также предоставляет подарочную упаковку!', 0);

-- Add ruRU offer rewards for quest 2947
-- https://ru.tbc.wowhead.com/quest=2947/возвращение-кольца
SET @ID := 2947;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Кольцо, говорите? Ну конечно, это я его сделал!$B$BДо падения Гномрегана у меня была там небольшая мастерская. Видимо, кольцо осталось там, когда пришлось очень быстро давать деру. Довольно простое кольцо – я сделал таких несколько.$B$BГоворите, сняли с дворфа Черного Железа? Занятно, занятно – дело пахнет весьма запутанной интригой... Возможно, следует дать знать властям, такие вещи не для нашего брата...$B$BЧто касается кольца...', 0);

-- Add ruRU offer rewards for quest 2948
-- https://ru.tbc.wowhead.com/quest=2948/гномское-усовершенствование
SET @ID := 2948;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ах, именно то, что нужно! Когда нибудь, когда я выберусь из этой ямы, в которую так незаслуженно попал, я сделаю для вас, для ВСЕХ лучшие украшения во всем Азероте! А пока благодарю вас за хлопоты. Обычно я прошу в десять раз больше, чем я взял с вас за кольцо такого качества...$B$BКстати, о кольцах – вот ваша обновка!', 0);

-- Add ruRU offer rewards for quest 2949
-- https://ru.tbc.wowhead.com/quest=2949/возвращение-кольца
SET @ID := 2949;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Кольцо из Гномрегана? Очень любопытно... Нет, его сделал не я.$B$BГномреганская штучка – н-да, неплохо для горстки болванов. Подумать только, эти ходячие недоразумения вдруг научились делать машины лучше нас...$B$BЧто, кольцо было у дворфа Черного Железа? Еще интереснее... Возможно, гномы сперли и подправили чертежи их жутких големов – я бы этому совсем не удивился. Значит, теперь дворфы жаждут мести. Очень любопытно...', 0);

-- Add ruRU offer rewards for quest 2950
-- https://ru.tbc.wowhead.com/quest=2950/переделка-кольца
SET @ID := 2950;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот оно, твое кольцо, лучше прежнего. Еще раз спасибо за сведения об этих дворфах Черного Железа. Это объясняет, откуда вдруг у гномов взялись гоблинские идеи...', 0);

-- Add ruRU offer rewards for quest 2952
-- https://ru.tbc.wowhead.com/quest=2952/чистер-5200
SET @ID := 2952;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Проглотив кольцо, машина несколько минут с гудением вертит его в своих недрах и наконец останавливается, звенящим звуком оповестив вас о том, что работа закончена. Окошко приемника открывается, и вы видите в нем аккуратно завернутую коробочку. Видимо, машина выдает очищенные предметы в подарочной упаковке. Ну, даже если кольцо не удалось очистить, вы получили довольно миленькую коробочку за свои деньги...$B$BЧто ж, посмотрим...', 0);

-- Add ruRU offer rewards for quest 2953
-- https://ru.tbc.wowhead.com/quest=2953/работа-для-чистера
SET @ID := 2953;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Чистер 5200 с яростным гудением принимается за работу. Въевшаяся грязь растворяется под воздействием гномьих чистящих средств.$B$BНаконец Чистер 5200 перестает вибрировать. Окошко премника со звоном открывается – в нем лежит аккуратно завернутая коробка.', 0);

-- Add ruRU offer rewards for quest 2969
-- https://ru.tbc.wowhead.com/quest=2969/свободу-всем-живым-существам
SET @ID := 2969;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Слава Элуне! $N, ты настоящий подарок судьбы! Нам с Джер\'Кай в одиночку никогда бы не удалось спасти бедных дракончиков.$B$BПожалуйста, поговори теперь с Джер\'Кай. А мне нужно приготовиться к мести! Если дракончики на свободе, это еще не значит, что таурены не наловят новых! Так что мы с Джер\'Кай собираемся перейти в наступление.', 0);

-- Add ruRU offer rewards for quest 2970
-- https://ru.tbc.wowhead.com/quest=2970/небольшое-возмездие
SET @ID := 2970;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, Кайдел была права насчет тебя: у тебя талант к этому делу! Ты – куда более $Gопытный:опытная; искатель приключений, чем мы обе. Спасибо, что ты с нами!$B$BЭтот клан Зловещего Тотема куда опаснее остальных тауренов. Подозреваю, что их боятся даже собственные сородичи!$B$BВпрочем, об этом потом.', 0);

-- Add ruRU offer rewards for quest 2972
-- https://ru.tbc.wowhead.com/quest=2972/небольшое-возмездие
SET @ID := 2972;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасная история, $N! Мы очень рады, что ты $Gпомог:помогла; не только драконьему племени, но и одной из наших жриц. Джер\'Кай поступила правильно, прислав тебя к нам. Я позабочусь о том, чтобы вернуть ей ее кольцо – в Фералас в ближайшее время отправятся наши разведчики. Пусть заодно разведают и это...$B$BСпасибо тебе еще раз. Чувствуй себя у нас, как дома!', 0);

-- Add ruRU offer rewards for quest 2973
-- https://ru.tbc.wowhead.com/quest=2973/новый-сверкающий-плащ
SET @ID := 2973;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, |3-6($C)! Да, это то, что надо. Этого вполне хватит на плащ для Коррин, а может, и останется! Спасибо тебе.$B$BНу что, надеюсь, охота была не очень опасной? А то ведь Фералас ошибок не прощает.$B$BСпасибо еще раз, |3-6($C)!', 0);

-- Add ruRU offer rewards for quest 2974
-- https://ru.tbc.wowhead.com/quest=2974/зловещее-открытие
SET @ID := 2974;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличные рога, |3-6($C)! $GМолодец:Умница;! Я заберу их у тебя и сообщу о твоих деяниях Белгрому, как только вернусь в Оргриммар. Ты $Gпомог:помогла; мне уже дважды, и я тебя запомню. Быть может, когда-нибудь и я тебе помогу! Удачи.', 0);

-- Add ruRU offer rewards for quest 2975
-- https://ru.tbc.wowhead.com/quest=2975/огры-фераласа
SET @ID := 2975;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N! Еще немного, и эта земля исцелится. Мы не сдадимся!', 0);

-- Add ruRU offer rewards for quest 2976
-- https://ru.tbc.wowhead.com/quest=2976/зловещее-открытие
SET @ID := 2976;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Клан Зловещего Тотема?! Интересно... Так говоришь, ты $Gнаткнулся:наткнулась; на них во время охоты в Фераласе? В самом деле?$B$BТвои новости очень важны для нас, |3-6($C). Расскажи все как было, а я пока отсчитаю твою награду.$B$BДа, и пока ты не $Gушел:ушла;: имей в виду, я тебе очень признателен за эту информацию.', 0);

-- Add ruRU offer rewards for quest 2978
-- https://ru.tbc.wowhead.com/quest=2978/свиток-гордунни
SET @ID := 2978;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Этот свиток... Ты $Gнашел:нашла; его в Поселении Гордунни?', 0);

-- Add ruRU offer rewards for quest 2979
-- https://ru.tbc.wowhead.com/quest=2979/темный-обряд
SET @ID := 2979;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эта сфера поможет нам получить информацию о Гордунни... И мы используем эту информацию, чтобы разгромить их!', 0);

-- Add ruRU offer rewards for quest 2980
-- https://ru.tbc.wowhead.com/quest=2980/огры-фераласа
SET @ID := 2980;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, ты воистину надежный и верный союзник!', 0);

-- Add ruRU offer rewards for quest 2982
-- https://ru.tbc.wowhead.com/quest=2982/высокогорные-дебри
SET @ID := 2982;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, как я вам благодарна!$B$BТолько, пожалуйста, Троясу об этом ни слова!', 0);

-- Add ruRU offer rewards for quest 2984
-- https://ru.tbc.wowhead.com/quest=2984/зов-огня
SET @ID := 2984;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что, тебя Нарм прислал, да?$B$BНу, на Нарма положиться можно. Значит, ты уже $Gготов:готова; вкусить следующую сапту – сапту огня.$B$BДа, я уже вижу в твоих глазах огонь стремления к познанию! Тебе довелось вкусить власти, и теперь тебе пора сделать новый шаг... Но терпение, $N. Помни, чему тебя научила земля. Власть разрушения обрести нетрудно, но следует знать, где остановиться.', 0);

-- Add ruRU offer rewards for quest 2987
-- https://ru.tbc.wowhead.com/quest=2987/кобальт-гордунни
SET @ID := 2987;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Захвачу это с собой, когда снова отправлюсь в путь. Я наверняка сумею найти кого-то, кто выложит за эти образцы кругленькую сумму!$B$BБлагодарю вас, $N. Вот, возьмите за труды.', 0);

-- Add ruRU offer rewards for quest 2995
-- https://ru.tbc.wowhead.com/quest=2995/линии-связи
SET @ID := 2995;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно. Пока эльфы будут восстанавливать утраченную информацию, мы сможем еще навсегда отрезать их от остального мира…', 0);

-- Add ruRU offer rewards for quest 2997
-- https://wowroad.info/goha.ru?quest=2997
SET @ID := 2997;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, $N. Надеюсь, Свет укажет тебе истинный путь и сохранит тебя от зла.', 0);

-- Add ruRU offer rewards for quest 2998
-- https://ru.tbc.wowhead.com/quest=2998/фолиант-божественности
SET @ID := 2998;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Как красив Штормград, не правда ли?..$B$BТвой визит в это время более чем уместен, $N.', 0);

-- Add ruRU offer rewards for quest 2999
-- https://ru.tbc.wowhead.com/quest=2999/фолиант-божественности
SET @ID := 2999;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, $N. Надеюсь, Свет укажет тебе истинный путь и сохранит тебя от зла.', 0);

-- Add ruRU offer rewards for quest 3000
-- https://wowroad.info/goha.ru?quest=3000
SET @ID := 3000;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приветствую и добро пожаловать, $N.', 0);

-- Add ruRU offer rewards for quest 3001
-- https://wowroad.info/goha.ru?quest=3001
SET @ID := 3001;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Всегда жизнь в Кабестане, бьет ключом, не так ли. Ну так, на то он и порт. Столько всяких тайн, столько приключений, столько невежества…$B$BЯ вижу ненависть в твоих глазах, $N? Хорошо, мы найдем ей полезное применение.', 0);

-- Add ruRU offer rewards for quest 3002
-- https://ru.tbc.wowhead.com/quest=3002/сфера-гордунни
SET @ID := 3002;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, занятная вещица…$B$BЭтот шар весьма могуществен, но и очень опасен!', 0);

-- Add ruRU offer rewards for quest 3062
-- https://ru.tbc.wowhead.com/quest=3062/темное-сердце
SET @ID := 3062;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, вот теперь я точно знаю, что Эдана мертва! А это сердце я оставлю себе на память о твоем подвиге, $N. Спасибо тебе!', 0);

-- Add ruRU offer rewards for quest 3063
-- https://ru.tbc.wowhead.com/quest=3063/месть-стае-студеных-ключей
SET @ID := 3063;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо тебе, $N. Ты возвращаешь покой душе старого таурена.', 0);

-- Add ruRU offer rewards for quest 3098
-- https://ru.tbc.wowhead.com/quest=3098/свиток-покрытый-письменами
SET @ID := 3098;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе стоит возвращаться ко мне почаще, если ты хочешь обрести достаточно сил для уничтожения наших недругов. Законы магии по-прежнему относятся и к тебе, $N. Ты узнаешь, что скверна следует за тобой по пятам, аки тать в ночи. Ты узнаешь, что ее прикосновение сродни пагубной страсти. Она будет льнуть к тебе, как трепетный любовник. И все же ты можешь избежать ее. Скверна обретет власть над тобой, только если ты ей это позволишь.$B$BА сейчас иди... возвращайся, когда силы твои возрастут.', 0);

-- Add ruRU offer rewards for quest 3121
-- https://ru.tbc.wowhead.com/quest=3121/странная-просьба
SET @ID := 3121;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, я давно ждал, когда Узери ее пришлет…$B$BА вот и смесь трав, которую я изготовил для его... экспериментов.', 0);

-- Add ruRU offer rewards for quest 3122
-- https://ru.tbc.wowhead.com/quest=3122/возвращение-к-знахарю-узери
SET @ID := 3122;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, это именно то, что мне нужно, чтобы изготовить сосуд уменьшения! Скоро увидим, так ли могущественны мои последние заклинания, как я рассчитывал!$B$BТак, минутку... Мне надо совершить ритуал и использовать травы...', 0);

-- Add ruRU offer rewards for quest 3123
-- https://ru.tbc.wowhead.com/quest=3123/испытание-сосуда
SET @ID := 3123;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Дух существа, преданного насильственной смерти, может вырваться на волю и попытаться отомстить. А помещая их в сосуд уменьшения, мы препятствуем духу вырваться на свободу. И теперь мы можем использовать его, как нам угодно!', 0);

-- Add ruRU offer rewards for quest 3124
-- https://ru.tbc.wowhead.com/quest=3124/уменьшенный-гиппогриф
SET @ID := 3124;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Если мы убьем существо и позволим его духу ускользнуть, оно может превратиться в куда более могущественное создание! И тогда оно будет вечно грозить нам местью.$B$BЯ поручил тебе опасную работу, $N. Но тебе удалось с ней справиться.', 0);

-- Add ruRU offer rewards for quest 3125
-- https://ru.tbc.wowhead.com/quest=3125/уменьшенный-лесной-дракончик
SET @ID := 3125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N! Теперь нам будет доступна сила духа лесных дракончиков.$B$BНадеюсь, ты не откажешься поработать на меня еще немного?', 0);

-- Add ruRU offer rewards for quest 3126
-- https://ru.tbc.wowhead.com/quest=3126/уменьшенный-древень
SET @ID := 3126;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N! Наше собрание уменьшенных существ почти готово...', 0);

-- Add ruRU offer rewards for quest 3127
-- https://ru.tbc.wowhead.com/quest=3127/уменьшенный-горный-великан
SET @ID := 3127;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Только представь себе, $N, какими возможностями мы теперь обладаем! С теми материалами, которые тебе удалось собрать, я могу сколько угодно уловлять души этих созданий.', 0);

-- Add ruRU offer rewards for quest 3128
-- https://ru.tbc.wowhead.com/quest=3128/природные-материалы
SET @ID := 3128;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Все это, вкупе с духами животных, позволит мне изготовить именно то, что нужно!', 0);

-- Add ruRU offer rewards for quest 3129
-- https://ru.tbc.wowhead.com/quest=3129/оружие-духа
SET @ID := 3129;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну что ж, $N, выбирай, что тебе больше по нраву! В это оружие навечно заточены души могучих созданий.$B$BТеперь их сила – твоя сила.', 0);

-- Add ruRU offer rewards for quest 3130
-- https://ru.tbc.wowhead.com/quest=3130/борьба-с-гребнем-ненависти
SET @ID := 3130;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ж, $N, отлично: я ценю готовность сражаться в тех, с кем имею дело.$B$BГенерал Лунное Перо поручила мне подготовить нападение на наг. Мои планы состоят из двух частей: во-первых, мы ослабим их силы и лишим командования, а во-вторых, выясним, что же они делают в этих развалинах. С твоей помощью мы сумеем задать нагам перцу, не ослабляя защиты крепости.', 0);

-- Add ruRU offer rewards for quest 3141
-- https://ru.tbc.wowhead.com/quest=3141/лорамус
SET @ID := 3141;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да будет так...', 0);

-- Add ruRU offer rewards for quest 3181
-- https://ru.tbc.wowhead.com/quest=3181/рог-чудовища
SET @ID := 3181;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что это у тебя? Бессовестная подделка, вестимо!$B$BЯ встречалась с Марголом один на один, и могу ответственно заявить тебе – рог у него раз в восемь больше, чем вот эта твоя закорючка! Небось, $Gвыдрал:выдрала; ее из какого-нибудь несчастного грозорыла в Степях. Нет, $Gмилый:милая;, ты не обманешь Щебеночку!', 0);

-- Add ruRU offer rewards for quest 3182
-- https://ru.tbc.wowhead.com/quest=3182/доказательство-собственности
SET @ID := 3182;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что это?$B$BЯ не могу поверить! Вы понимаете, что это, |3-6($R)? Это же рог Маргола Яростеня! Маргола, причины гибели множества археологов, оказавшихся в Тлеющем ущелье.$B$BМожно мне оставить его себе?', 0);

-- Add ruRU offer rewards for quest 3201
-- https://ru.tbc.wowhead.com/quest=3201/наконец-то
SET @ID := 3201;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не понимаю, как $Gмог:могла; $Gтакой:такая; $Gслабак:слабачка;, как ты, одолеть Маргола, но я хозяйка своего слова.$B$BНо если после этого с тобой случится что-то нехорошее, пеняй на себя!', 0);

-- Add ruRU offer rewards for quest 3367
-- https://ru.tbc.wowhead.com/quest=3367/камни-сунтары
SET @ID := 3367;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Письмо выронил Дориус, когда падал.', 0);

-- Add ruRU offer rewards for quest 3371
-- https://ru.tbc.wowhead.com/quest=3371/правосудие-дворфов
SET @ID := 3371;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Оставь меня, спасай остальных!', 0);

-- Add ruRU offer rewards for quest 3372
-- https://ru.tbc.wowhead.com/quest=3372/отпусти-их
SET @ID := 3372;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы возлагаете таинственный артефакт на алтарь Сунтары.', 0);

-- Add ruRU offer rewards for quest 3374
-- https://ru.tbc.wowhead.com/quest=3374/сущность-эраникуса
SET @ID := 3374;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Выбор сделан, начало положено. Пока, на мой взгляд, ты $выбирал:выбирала; верный путь. С нынешнего момента от твоих деяний будет зависеть, будет ли так и впредь.', 0);

-- Add ruRU offer rewards for quest 3375
-- https://ru.tbc.wowhead.com/quest=3375/запасной-фиал
SET @ID := 3375;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Могучий искатель приключений все принес. Слава мне! Кстати, я соврал – у меня был запасной фиал. Вот.$B$BА чего ты $Gожидал:ожидала;?! "Нате-пожалуйста вам другой! Мне, дураку, делать больше нечего, кроме как задарма раздавать магические устройства связи искателям приключений!" Но ты не беспокойся, все, что ты мне $Gдал:дала;, пойдет на изготовление для тебя очередного фиала, когда ты и этот посеешь.$B$BПожалуйста, пусть я ошибусь в тебе – не потеряй еще и этот, ладно?', 0);

-- Add ruRU offer rewards for quest 3377
-- https://ru.tbc.wowhead.com/quest=3377/молитва-элуне
SET @ID := 3377;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я смирился с тем, что отныне моя судьба – эта клетка, но молитву нужно найти!', 0);

-- Add ruRU offer rewards for quest 3378
-- https://ru.tbc.wowhead.com/quest=3378/молитва-элуне
SET @ID := 3378;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Элуна улыбается тебе, $N. Ты $Gвозвратил:возвратила; к ней потерянную душу. Прими это в знак нашей благодарности.', 0);

-- Add ruRU offer rewards for quest 3379
-- https://ru.tbc.wowhead.com/quest=3379/мастер-по-тенеткани
SET @ID := 3379;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Прими это в награду – уверена, подобной работы из тенеткани тебе еще не встречалось!', 0);

-- Add ruRU offer rewards for quest 3380
-- https://ru.tbc.wowhead.com/quest=3380/затонувший-храм
SET @ID := 3380;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да, я видел затонувший храм собственными глазами. Хочешь узнать о нем побольше?$B$BУж я сразу узнаю настоящего искателя приключений!', 0);

-- Add ruRU offer rewards for quest 3381
-- https://wowroad.info/goha.ru?quest=3381
SET @ID := 3381;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Два пера, как я и просил. И совсем не плохие.$B$BТогда готовы?Просто скажите слово и в путь.$B$BА, ещё запомните …мой хозяин не любит слабоумных, но он очень великодушен к тем, кто ему нравится.', 0);

-- Add ruRU offer rewards for quest 3382
-- https://ru.tbc.wowhead.com/quest=3382/на-абордаж
SET @ID := 3382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Победа! Спасибо тебе! Уф... это был самый жаркий бой за всю мою жизнь. Не знаю как тебя благодарить!$B$BКак жаль, что так много моих людей погибло в этой схватке.$B$BПожалуйста, поговори с моими пассажирами. Многие прибыли сюда по делу и наверняка кому-то из них понадобится помощь. Возможно, тебе будет это интересно. Еще раз благодарю тебя!$B$B', 0);

-- Add ruRU offer rewards for quest 3385
-- https://ru.tbc.wowhead.com/quest=3385/черный-рынок
SET @ID := 3385;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gнанес:нанесла; решающий удар по Черному рынку. Теперь эти бандиты дважды подумают, прежде чем отправлять сюда кого-то из своих.$B$BЯ осмотрела сумку – в ней нет ничего полезного. Если тебе приглянется что-то из его барахла, можешь смело оставить себе.', 0);

-- Add ruRU offer rewards for quest 3402
-- https://ru.tbc.wowhead.com/quest=3402/черный-рынок
SET @ID := 3402;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ковис убит? О, счастье! Столько лет этот прохвост творил что хотел, обтяпывал незаконные сделки, устанавливал бессовестно низкие цены, разоряя нас, честных тружеников!', 0);

-- Add ruRU offer rewards for quest 3421
-- https://ru.tbc.wowhead.com/quest=3421/возвращение
SET @ID := 3421;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Теперь я отправлю тебя назад к лагерю Саната.$B$BНе обращай внимание на его манеры – он груб со всеми, кроме собственного господина. Возможно, однажды его заносчивость сыграет с ним злую шутку.', 0);

-- Add ruRU offer rewards for quest 3441
-- https://ru.tbc.wowhead.com/quest=3441/божественное-воздаяние
SET @ID := 3441;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе все ясно, |3-6($N)? Ты готов действовать?', 0);

-- Add ruRU offer rewards for quest 3442
-- https://ru.tbc.wowhead.com/quest=3442/неугасимое-пламя
SET @ID := 3442;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно, $N. Все готово к работе.', 0);

-- Add ruRU offer rewards for quest 3443
-- https://ru.tbc.wowhead.com/quest=3443/древко-факела
SET @ID := 3443;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N, я просто поражен! Ты не $Gзадумывался:задумывалась; о смене профессии? Чтобы стать, скажем, детективом? Ну или старьевщиком? Или примкнуть к этим глупеньким гномам, ползающим по побережьям с металлоискателями в поисках сокровищ? Это ведь наверняка твое призвание!', 0);

-- Add ruRU offer rewards for quest 3444
-- https://ru.tbc.wowhead.com/quest=3444/круглый-камень
SET @ID := 3444;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, это тот самый камень.$B$BЗатонувший храм так и стоит у меня перед глазами...', 0);

-- Add ruRU offer rewards for quest 3445
-- https://ru.tbc.wowhead.com/quest=3445/затонувший-храм
SET @ID := 3445;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да, я видел затонувший храм собственными глазами. Хочешь узнать о нем побольше?$B$BУж я сразу узнаю настоящего искателя приключений!', 0);

-- Add ruRU offer rewards for quest 3447
-- https://ru.tbc.wowhead.com/quest=3447/тайна-камня
SET @ID := 3447;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Глаз идола ярко сияют даже в полумраке, царящем в храме. Кажется, внутри спрятано что-то блестящее. Вы просовываете руку внутрь статуи и хватаете то, что там лежит. Теперь сокровище Аталаи – ваше!', 0);

-- Add ruRU offer rewards for quest 3452
-- https://ru.tbc.wowhead.com/quest=3452/защита-пламени
SET @ID := 3452;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Символ источает злые чары – именно они и требуются для завершения работы над факелом.', 0);

-- Add ruRU offer rewards for quest 3453
-- https://ru.tbc.wowhead.com/quest=3453/факел-воздаяния
SET @ID := 3453;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Есть еще одно, последнее задание, которое ты $Gдолжен:должна; выполнить.', 0);

-- Add ruRU offer rewards for quest 3454
-- https://ru.tbc.wowhead.com/quest=3454/факел-воздаяния
SET @ID := 3454;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы хватаете факел обеими руками и ощущаете исходящие от него волны гнева и ненависти.', 0);

-- Add ruRU offer rewards for quest 3462
-- https://ru.tbc.wowhead.com/quest=3462/оруженосец-малтрейк
SET @ID := 3462;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты готов нанести удар?', 0);

-- Add ruRU offer rewards for quest 3463
-- https://ru.tbc.wowhead.com/quest=3463/задай-им-жару
SET @ID := 3463;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! С тобой можно идти в разведку, $N!', 0);

-- Add ruRU offer rewards for quest 3481
-- https://ru.tbc.wowhead.com/quest=3481/безделушки
SET @ID := 3481;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Замок открывается, как только вы прикасаетесь к нему. Любопытно, сколько же может быть внутри сокровищ? Есть только один способ узнать.', 0);

-- Add ruRU offer rewards for quest 3483
-- https://ru.tbc.wowhead.com/quest=3483/сигнал-взять-на-борт
SET @ID := 3483;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Еще одно сигнальное ружье, да? Это можно.$B$BИ не забудьте – южная оконечность Азшары. Этот крохотный островок переделан в посадочную площадку. Вы ее не пропустите, если окажетесь в нужном месте.', 0);
