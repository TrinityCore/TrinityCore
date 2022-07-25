-- Add ruRU offer rewards for quest 3501
-- https://ru.tbc.wowhead.com/quest=3501/счет-идет-на-большие-числа
SET @ID := 3501;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты разочаровываешь меня, |3-6($R). Такой большой, а роняет слюни над грудой хлама? Какое жалкое зрелище! Забирай свою награду и прочь с глаз моих!', 0);

-- Add ruRU offer rewards for quest 3502
-- https://ru.tbc.wowhead.com/quest=3502/дренейский-хлам
SET @ID := 3502;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты разочаровываешь меня, |3-6($R). Такой большой, а роняет слюни над грудой хлама? Какое жалкое зрелище! Забирай свою награду и прочь с глаз моих.$B$BЗнакомые слова? А как же – я повторяю их тысячу раз на дню.$B$BО, как мне отвратителен этот мир!', 0);

-- Add ruRU offer rewards for quest 3503
-- https://ru.tbc.wowhead.com/quest=3503/встреча-с-господином
SET @ID := 3503;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, уж не вернуть тех дней, когда я мог требовать с желающих видеть моего господина все, что заблагорассудится. Теперь-то я отправляю к нему любой сброд – только попроси!$B$BКак меня это бесит! Но приказы не обсуждаются. Я могу потешить себя лишь глумясь над твоей безвкусной одеждой и жалким выражением лица. Впрочем, мне и это уже наскучило!$B$BИ необходимость трепаться тут с тобой меня бесит! Будешь телепортироваться к господину или нет?!', 0);

-- Add ruRU offer rewards for quest 3504
-- https://ru.tbc.wowhead.com/quest=3504/предательница
SET @ID := 3504;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мы уже многих посылали против нее и ее приспешников, но они слишком сильны! Никто из посланных не вернулся. Наверное, некоторые погибли, но большинство, подозреваю, просто сбежали. Трусы!$B$BОднако теперь, когда прибыло подкрепление, у нас снова появилась надежда. Быть может, мы все-таки сумеем с ней разобраться.$B$BНу так что, ты с нами?', 0);

-- Add ruRU offer rewards for quest 3505
-- https://ru.tbc.wowhead.com/quest=3505/предательница
SET @ID := 3505;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы начинаете листать страницы и обнаруживаете, что одна из них заложена узкой ленточкой черного шелка.$B$BВы пытаетесь разобрать непонятные слова и видите на одной из страниц схему. Присмотревшись, вы понимаете, что кристаллы, круг и некоторые другие компоненты, лежащие на земле, расположены так же, как на рисунке.', 0);

-- Add ruRU offer rewards for quest 3506
-- https://ru.tbc.wowhead.com/quest=3506/предательница
SET @ID := 3506;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага!!! Невероятно!$B$BТебе это удалось! То-то Белгром обрадуется! Наконец-то души десятков наших воинов упокоятся в мире. Спасибо тебе, $N.', 0);

-- Add ruRU offer rewards for quest 3507
-- https://ru.tbc.wowhead.com/quest=3507/предательница
SET @ID := 3507;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ха-ха-ха! Вот и ты, жалкая девчонка! Я плюю на твои останки!$B$BСпасибо, $N. Я благодарю тебя от всей души! Это воистину великий день!$B$BБудь это в моей власти, я наградил бы тебя целым королевством! Но, может быть, ты согласишься на это?$B$B<Белгром смотрит на голову |3-6($C), который предал его.>$B$BХа-ха! Глупая эльфийка! Вот что с тобой стало! В парусиновом мешке, голова отдельно, тело отдельно! Не надо было предавать Белгрома!', 0);

-- Add ruRU offer rewards for quest 3508
-- https://ru.tbc.wowhead.com/quest=3508/минуя-охрану
SET @ID := 3508;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Необходимо отыскать имя зверя.', 0);

-- Add ruRU offer rewards for quest 3509
-- https://ru.tbc.wowhead.com/quest=3509/имя-зверя
SET @ID := 3509;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Повелитель демонов?$B$B<Лорд Арккорос смеется.>$B$BБыть может, кое-кто сможет помочь тебе этими сведениями, но сначала ты должен помочь кое-кому.', 0);

-- Add ruRU offer rewards for quest 3510
-- https://ru.tbc.wowhead.com/quest=3510/имя-зверя
SET @ID := 3510;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наконец-то хоть кто-то достойный мудрости Арккороса!', 0);

-- Add ruRU offer rewards for quest 3511
-- https://ru.tbc.wowhead.com/quest=3511/имя-зверя
SET @ID := 3511;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Этот состав содержит протравку, необходимую нам для отковки оружия. Это еще один шаг к созданию сего оружия.', 0);

-- Add ruRU offer rewards for quest 3512
-- https://ru.tbc.wowhead.com/quest=3512/судя-по-словам-эраникуса
SET @ID := 3512;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что Итар послал тебя ко мне. Хотя Эраникус и не мертв в общем смысле этого слова, я смогу поговорить с ним. Но прямо сейчас я не могу помочь тебе...$B$BЯ с удовольствием это сделаю, но сначала мне самому нужна помощь того, кто, в отличие от меня, не скован старческой немощью. Мой наиболее ценный гадальный инструмент был у меня украден, и, пока я не заполучу его обратно, я бессилен помочь Эраникусу.', 0);

-- Add ruRU offer rewards for quest 3514
-- https://ru.tbc.wowhead.com/quest=3514/мощь-орды
SET @ID := 3514;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да ты $Gсилен:сильна;! Это большое дело – лишить Логово Когтя Ринтариэль. Наши противники не сразу оправятся от потери, и в ближайшее время в Степи будет проникать меньше лазутчиков Альянса. Они подумают дважды, чем прежде чем снова соваться к нам.$B$BСпасибо.', 0);

-- Add ruRU offer rewards for quest 3517
-- https://ru.tbc.wowhead.com/quest=3517/тайненькое-знаньице
SET @ID := 3517;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N, ты $Gпринес:принесла; все таблички, и они в хорошем состоянии. Мы получим за них хорошую цену.$B$BНу, не будем тратить время зря. Пора обменять таблички на денежки!', 0);

-- Add ruRU offer rewards for quest 3518
-- https://ru.tbc.wowhead.com/quest=3518/доставка-магате
SET @ID := 3518;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, наконец-то! Табличка Бет\'Амары! А я уж гадала, неужели орк не сдержала обещания, или, чего доброго, бедняжка нашла кончину в Азшаре. Я рада, что ей удалось.$B$BБет\'Амара был одним из самых могущественных алхимиков высокорожденных. Говорят, что он единственный овладел искусством трансмутации металлов.', 0);

-- Add ruRU offer rewards for quest 3526
-- https://ru.tbc.wowhead.com/quest=3526/гоблинское-инженерное-дело
SET @ID := 3526;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, $N, ты $Gнашел:нашла; подходящего учителя! Любой болван может освоить основы инженерного дела – как доказали гномы и их радиоактивный Гномреган. Требуется острый ум и верная рука (повторяю: ВЕРНАЯ), чтобы освоить премудрости гоблинского инженерного дела.$B$BДержи ушки на макушке, $N, тогда чему-нибудь научишься.', 0);

-- Add ruRU offer rewards for quest 3541
-- https://ru.tbc.wowhead.com/quest=3541/доставка-джесримону
SET @ID := 3541;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага, Джедига прислала мне посылку... Великолепно, я ждал ее.$B$BДа, Джедига славная бабенка! Свирепая как волчица... что может быть лучше?$B$BКак я погляжу, табличка в целости и сохранности. А что это значит, $N? Значит, посыльный получит на магарыч!', 0);

-- Add ruRU offer rewards for quest 3542
-- https://ru.tbc.wowhead.com/quest=3542/доставка-андрону-ганту
SET @ID := 3542;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот, возьми пару монет... *ик*... купи себе новую броню... или шляпу.$B$BНичего не жаль для хороших посыльных!', 0);

-- Add ruRU offer rewards for quest 3561
-- https://ru.tbc.wowhead.com/quest=3561/доставка-верховному-магу-ксилему
SET @ID := 3561;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, табличка Саэль\'Хай... как давно я мечтал изучить ее!$B$BБлагодарю тебя, $N. Скажи Джедиге, что я доволен работой. Орк заслужила свою награду.', 0);

-- Add ruRU offer rewards for quest 3562
-- https://ru.tbc.wowhead.com/quest=3562/плата-магаты-джедиге
SET @ID := 3562;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, отлично. Она поступила вполне разумно. По крайней мене по отношению к тебе. Я побаивалась, что она сделает с тобой что-нибудь неприятное, чтобы наказать меня за высокомерие. Она любит, чтобы к ней являлись лично, а не отправляли мальчиков на побегушках. Похоже, она действительно обрадовалась табличке.$B$BЧто ж, посмотрим.', 0);

-- Add ruRU offer rewards for quest 3563
-- https://ru.tbc.wowhead.com/quest=3563/плата-джесримона-джедиге
SET @ID := 3563;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Судя по этому письму, Джесримон весьма доволен нашей работой...$B$BЗнал бы он как я довольна работой, которую он мне дает... Ну, теперь у меня есть еще одна причина задержаться в Азшаре.$B$BВот, забирай свою долю.', 0);

-- Add ruRU offer rewards for quest 3564
-- https://ru.tbc.wowhead.com/quest=3564/плата-андрона-джедиге
SET @ID := 3564;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ха-ха! Что ты $Gсказал:сказала; ему, когда отдавал табличку, $N? Он заплатил нам едва ли не дважды сверх уговоренного! Нет, я конечно, не жалуюсь... Ты $Gсказал:сказала; ему, что я изменила условия сделки? Или этот пьянчуга опять шары залил и не соображал, что делает?$B$BНу, уже неважно. Вот, держи свою долю – с премией!', 0);

-- Add ruRU offer rewards for quest 3565
-- https://ru.tbc.wowhead.com/quest=3565/плата-ксилема-джедиге
SET @ID := 3565;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что, в самом деле не случилось ничего неприятного? И он отдал тебе деньги не торгуясь? Ушам не верю... Я, честно признаться, ожидала какого-то подвоха. Похоже, с ним все же можно иметь дело.$B$BВот, держи свою награду. Спасибо за помощь.', 0);

-- Add ruRU offer rewards for quest 3566
-- https://ru.tbc.wowhead.com/quest=3566/восстань-обсидион
SET @ID := 3566;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Ториус бледнеет.>$B$BЭтого не может быть... Мой единокровный брат! Неужели он мог это сделать?!$B$B<Лицо Ториуса искажает ярость>$B$BОн предал меня, он предал Стальгорн! Видимо, влияние Древних Богов еще сильно в этих землях. Боюсь, если даже мой брат – некогда благородный и уважаемый человек – так легко поддался воле Рагнароса, никто их нас не может чувствовать себя в безопасности!', 0);

-- Add ruRU offer rewards for quest 3567
-- https://ru.tbc.wowhead.com/quest=3567/умный-в-гору-не-пойдет
SET @ID := 3567;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хочешь посмотреть, какой вид открывается во-он оттуда, с тех Двух Колоссов? Могу тебя туда отправить, |3-6($R).$B$BТолько подумай заранее, как потом будешь спускаться. Это путешествие в один конец.', 0);

-- Add ruRU offer rewards for quest 3570
-- https://ru.tbc.wowhead.com/quest=3570/разносчик-порчи
SET @ID := 3570;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я и не думал, что эликсир сработает так быстро. Спасибо, $N. Займусь-ка работой над остальными образцами. Уверен, вскоре леди Сильвана и Отрекшиеся будут их активно использовать.', 0);

-- Add ruRU offer rewards for quest 3601
-- https://ru.tbc.wowhead.com/quest=3601/оскорбленный-кимджаель
SET @ID := 3601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ха! Так им и надо!$B$BВот это круто! Теперь-то они знают, что значит предавать своих партнеров! Особенно гоблинов!$B$BНу, теперь о твоей награде... я же сказал, значит, заплачу.$B$BВот, держи... может, пригодится.', 0);

-- Add ruRU offer rewards for quest 3602
-- https://ru.tbc.wowhead.com/quest=3602/азшарит
SET @ID := 3602;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твои задачи в Азшаре завершены. Теперь я должен подготовить все необходимое для следующего шага твоего пути.', 0);

-- Add ruRU offer rewards for quest 3621
-- https://ru.tbc.wowhead.com/quest=3621/создание-отравы-скверны
SET @ID := 3621;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Могу лишь вообразить, через что тебе пришлось пройти, чтобы раздобыть эти материалы. Немногим удавалось вернуться живыми из Азшары, не говоря уж о том, чтобы встретиться лицом к лицу с полубогами и демонами.', 0);

-- Add ruRU offer rewards for quest 3625
-- https://ru.tbc.wowhead.com/quest=3625/зачарованное-азшаритовое-оружие-отравленное-скверной
SET @ID := 3625;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Гальван вытирает пот со лба..>$B$BНикогда еще не существовало более подходящего оружия для убиения демона, $N.', 0);

-- Add ruRU offer rewards for quest 3626
-- https://ru.tbc.wowhead.com/quest=3626/возвращение-в-выжженные-земли
SET @ID := 3626;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Похоже, сражения закалили тебя, $N. Но достаточно ли в тебе силы и решимости, чтобы противостоять Разелиху и его приспешникам?', 0);

-- Add ruRU offer rewards for quest 3627
-- https://ru.tbc.wowhead.com/quest=3627/воссоединить-расколотый-амулет
SET @ID := 3627;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Амулет Разелиха Осквернителя наконец-то собран воедино. Но Разелих чует, что цепь его власти порвана. Он знает, что ты собираешься убить его...', 0);

-- Add ruRU offer rewards for quest 3628
-- https://ru.tbc.wowhead.com/quest=3628/ты-рахлих-демон
SET @ID := 3628;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сегодняшний день останется в памяти навеки. Демонический повелитель Выжженных земель наконец-то пал!', 0);

-- Add ruRU offer rewards for quest 3629
-- https://wowroad.info/goha.ru?quest=3629
SET @ID := 3629;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, $N, ты $Gвыбрал:выбрала; правильный путь. Не смотри на похвальбу гномов, разве они умеют обращаться с взрывчатыми веществами... в их зараженном радиацией городе Гномрегане так уже не думают, хе-хе-хе... Я покажу тебе, что такое настоящая гоблинская инженерия.$B$BДержи свои глаза широко открытыми, $N, и учись.', 0);

-- Add ruRU offer rewards for quest 3630
-- https://ru.tbc.wowhead.com/quest=3630/гномское-инженерное-дело
SET @ID := 3630;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, молодой инженер, заинтересованный в освоении единственно верной школы инженерного дела! Что ж, $Gдружище:подруга;, прости мне мою мелодраматичность. Пока ситуация наша остается тяжелой, день всегда кажется светлее, когда встречаешь собрата по ремеслу, откликнувшегося на трубный призыв истинного инженерного дела!', 0);

-- Add ruRU offer rewards for quest 3631
-- https://ru.tbc.wowhead.com/quest=3631/призывание-коня-скверны
SET @ID := 3631;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Значит, ты снова $Gрешил:решила; пожаловать меня своим визитом. Очень мило с твоей стороны.$B$BМои помощники все гадали – придешь или нет? Я говорил им – несомненно, придет. Когда речь заходит о могуществе, летишь как мотылек на свечу.', 0);

-- Add ruRU offer rewards for quest 3632
-- https://ru.tbc.wowhead.com/quest=3632/гномское-инженерное-дело
SET @ID := 3632;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, юный инженер желает изучать единственное истинное направление в инженерном деле! Простите мне мою горячность, любезный друг. В нашем горестном положении всегда очень радостно встретить инженера, отозвавшегося на чистый зов истинного искусства!', 0);

-- Add ruRU offer rewards for quest 3633
-- https://ru.tbc.wowhead.com/quest=3633/гоблинское-инженерное-дело
SET @ID := 3633;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, $N, ты $Gнашел:нашла; подходящего учителя! Любой болван может освоить основы инженерного дела – как доказали гномы и их радиоактивный Гномреган. Требуется острый ум и верная рука (ключевое слово – ВЕРНАЯ), чтобы освоить премудрости гоблинского инженерного дела.$B$BДержи ушки на макушке, $N, и чему-нибудь научишься.', 0);

-- Add ruRU offer rewards for quest 3634
-- https://ru.tbc.wowhead.com/quest=3634/гномское-инженерное-дело
SET @ID := 3634;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, юный инженер желает изучать единственное истинное направление в инженерном деле! Простите мне мою горячность, любезный друг. В нашем горестном положении всегда очень радостно встретить инженера, отозвавшегося на чистый зов истинного искусства!', 0);

-- Add ruRU offer rewards for quest 3635
-- https://ru.tbc.wowhead.com/quest=3635/гномское-инженерное-дело
SET @ID := 3635;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Значит, тебе захотелось поучиться гномскому инженерному делу? Что ж, я очень подходящий гном. Хотя гномреганская правящая клика пытается преследовать тех, кто, по их мнению, слишком умный, знания нельзя посадить за решетку.$B$BМы с ними отлично понимаем, что после того, как я покинул Гномреган, они лишились одного из величайших гномов-инженеров наших дней. Если ты – способный ученик, я обучу тебя всему, что знаю.', 0);

-- Add ruRU offer rewards for quest 3637
-- https://ru.tbc.wowhead.com/quest=3637/гномское-инженерное-дело
SET @ID := 3637;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Значит, тебе захотелось поучиться гномскому инженерному делу? Что ж, я очень подходящий гном. Хотя гномреганская правящая клика пытается преследовать тех, кто, по их мнению, слишком умный, знания нельзя посадить за решетку.$B$BМы с ними отлично понимаем, что после того, как я покинул Гномреган, они лишились одного из величайших гномов-инженеров наших дней. Если ты – способный ученик, я обучу тебя всему, что знаю.', 0);

-- Add ruRU offer rewards for quest 3638
-- https://ru.tbc.wowhead.com/quest=3638/договор-о-неразглашении
SET @ID := 3638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в клуб, $N! Скоро ты получишь доступ к наиболее передовым разработкам во всем Азероте.$B$BТеперь, когда ты $Gрешил:решила; посвятить себя этому искусству, пора познакомиться с гоблинским инженерным делом. С этого мгновения мы будем помогать тебе разрабатывать план предельного раскрытия талантов гоблинского инженера!', 0);

-- Add ruRU offer rewards for quest 3639
-- https://ru.tbc.wowhead.com/quest=3639/покажи-свою-работу
SET @ID := 3639;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твой первый членский билет гильдии гоблинов-инженеров!$B$BБилет оплачивается вперед за четырнадцать дней. Через две недели срок действия истечет. Когда это произойдет, то для продления заплати очередную пошлину любому наставнику гоблинской инженерного дела. Без билета твое членство будет временно приостановлено, и ты не будешь иметь доступа к новым чертежам.$B$BЭто никак не повлияет на уже обретенные знания: если уж стал гоблинским инженером, то это навсегда.', 0);

-- Add ruRU offer rewards for quest 3640
-- https://ru.tbc.wowhead.com/quest=3640/договор-о-неразглашении
SET @ID := 3640;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в клуб, $N! Скоро вы получите доступ к наиболее передовым разработкам во всем Азероте.$B$BТеперь, когда вы посвятили себя этому искусству, пора испытать ваши навыки гномского инженерного дела. С этого мгновения мы будем помогать вам разрабатывать план предельного раскрытия ваших талантов гномского инженера!', 0);

-- Add ruRU offer rewards for quest 3641
-- https://ru.tbc.wowhead.com/quest=3641/покажи-свою-работу
SET @ID := 3641;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот ваш первый ччленский билет гильдии гномов-инженеров!$B$BБилет оплачивается вперед за четырнадцать дней. Через две недели срок действия истечет. Когда это произойдет, вы заплатите очередную пошлину любому наставнику гномской инженери и получите продление. Без билета ваше членство будет временно приостановлено, и вы не будете иметь доступа к новым чертежам.$B$BЭто никак не повлияет на уже обретенные вами знания: если уж стал гномским инженером, то это навсегда.', 0);

-- Add ruRU offer rewards for quest 3642
-- https://ru.tbc.wowhead.com/quest=3642/договор-о-неразглашении
SET @ID := 3642;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в клуб, $N! Скоро вы получите доступ к наиболее передовым разработкам во всем Азероте.$B$BТеперь, когда вы посвятили себя этому искусству, пора испытать ваши навыки гномского инженерного дела. С этого мгновения мы будем помогать вам разрабатывать план предельного раскрытия ваших талантов гномского инженера!', 0);

-- Add ruRU offer rewards for quest 3643
-- https://ru.tbc.wowhead.com/quest=3643/покажи-свою-работу
SET @ID := 3643;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вот твой первый членский билет гильдии гномов-инженеров!$B$BБилет оплачивается вперед за четырнадцать дней. Через две недели срок действия истечет. Когда это произойдет, то для продления заплати очередную пошлину любому наставнику гномского инженерного дела. Без билета твое членство будет временно приостановлено, и ты не будешь иметь доступа к новым чертежам.$B$BЭто никак не повлияет на уже обретенные знания: если уж стал гномским инженером, то это навсегда.', 0);

-- Add ruRU offer rewards for quest 3644
-- https://ru.tbc.wowhead.com/quest=3644/продление-членского-билета
SET @ID := 3644;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поскольку ты занимаешься гоблинским инженерным делом и у всех на хорошем счету, то я могу восстановить просроченный членский билет за два золотых. Как только ты заплатишь пошлину, то немедленно получишь новый членский билет. Это даст тебе доступ к гоблинским чертежам соотвествующих наставников.$B$BБилет будет действителен две недели, по истечении которых придется снова заплатить.', 0);

-- Add ruRU offer rewards for quest 3645
-- https://ru.tbc.wowhead.com/quest=3645/продление-членского-билета
SET @ID := 3645;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поскольку ты занимаешься гномским инженерным делом и у всех на хорошем счету, то я могу восстановить просроченный членский билет за два золотых. Как только ты заплатишь пошлину, то немедленно получишь новый членский билет. Это даст тебе доступ к гномским чертежам соотвествующих наставников.$B$BБилет будет действителен две недели, по истечении которых придется снова заплатить.', 0);

-- Add ruRU offer rewards for quest 3646
-- https://ru.tbc.wowhead.com/quest=3646/продление-членского-билета
SET @ID := 3646;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поскольку ты занимаешься гоблинским инженерным делом и у всех на хорошем счету, то я могу восстановить просроченный членский билет за два золотых. Как только ты заплатишь пошлину, то немедленно получишь новый членский билет. Это даст тебе доступ к гоблинским чертежам соответствующих наставников.$B$BБилет будет действителен две недели, по истечении которых придется снова заплатить! Если ты хочешь иметь доступ к чертежам, не просрочивай платежи.', 0);

-- Add ruRU offer rewards for quest 3647
-- https://ru.tbc.wowhead.com/quest=3647/продление-членского-билета
SET @ID := 3647;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поскольку ты занимаешься гномским инженерным делом и у всех на хорошем счету, то я могу восстановить просроченный членский билет за два золотых. Как только ты заплатишь пошлину, то немедленно получишь новый членский билет. Это даст тебе доступ к гномским чертежам соотвествующих наставников.$B$BБилет будет действителен две недели, по истечении которых придется снова заплатить.', 0);

-- Add ruRU offer rewards for quest 3681
-- https://ru.tbc.wowhead.com/quest=3681/фолиант-божественности
SET @ID := 3681;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать в Собор Света, |3-6($C).', 0);

-- Add ruRU offer rewards for quest 3721
-- https://ru.tbc.wowhead.com/quest=3721/собственный-ккх
SET @ID := 3721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось выручить всех трех моих роботов серии ООХ! Ты $Gсделал:сделала; все, что требовалось и даже больше, поэтому я хочу особым образом отблагодарить тебя за помощь. Это миниатюрная версия того же робота, с которым ты $Gпровел:провела; так много времени и $Gполюбил:полюбила;, ООХ!$B$BОбычно я никому не дарю такие опасные устройства, но ты $Gоказал:оказала; мне неоценимую помощь. Кроме того у этой тварюшки отключены боевые механизмы и устройство самонаведения.$B$BА в остальном это полноценный ООХ!', 0);

-- Add ruRU offer rewards for quest 3761
-- https://ru.tbc.wowhead.com/quest=3761/почва-унгоро
SET @ID := 3761;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ладно, $Gрядовой:рядовая; $N, и не пытайся помогать мне сваливать эту землю в кучу! Если бы Великие духи этого хотели, то прямо тут и устроили бы чудо, что, не так?!$B$BВерховный друид Рунический Тотем опять хочет с тобой говорить, но чтобы выполнить его очередное поручение, тебе нужно разбираться в травничестве на уровне подмастерья. Но если ты еще не $Gдоучился:доучилась;, он все равно тебе дельце подберет.', 0);

-- Add ruRU offer rewards for quest 3762
-- https://ru.tbc.wowhead.com/quest=3762/помощь-верховному-друиду-руническому-тотему
SET @ID := 3762;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C). Я рад, что ты хочешь помочь нам в наших исследованиях. Сделать предстоит многое, и я дурно поступил бы, если бы сказал, что труды наши не сулят опасности. Надеюсь, это тебя не отпугнет... но, судя по твоему виду, тебе и прежде приходилось сталкиваться с опасностями.', 0);

-- Add ruRU offer rewards for quest 3763
-- https://ru.tbc.wowhead.com/quest=3763/помощь-верховному-друиду-оленьему-шлему
SET @ID := 3763;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, |3-6($C)... поскольку вам сказали, что этими исследованиями руковожу лично я, то вы, несомненно, прибыли сюда так быстро, как могли.$B$BИ раз уж вы здесь, постарайтесь запомнить мои пояснения с первого раза, ибо повторять я не буду.', 0);

-- Add ruRU offer rewards for quest 3765
-- https://ru.tbc.wowhead.com/quest=3765/проблема-за-морем
SET @ID := 3765;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, вас прислал мой брат Аргос? Должно быть, вы устали от долгого пути. Но нам очень о многом нужно поговорить.', 0);

-- Add ruRU offer rewards for quest 3781
-- https://ru.tbc.wowhead.com/quest=3781/изучение-рассветницы
SET @ID := 3781;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, расписка на двадцать пакетиков семян. Если все изведешь, еще достанем. Хотя производить семена Тарлендриса в большом количестве – дело, увы, недешевое. Потому Круг Кенария и просит помощи в частичном возмещении стоимости.$B$BТе, кто находит рассветницу и приносит нам, видит, что награда верховного друида с лихвой окупает труды.', 0);

-- Add ruRU offer rewards for quest 3782
-- https://ru.tbc.wowhead.com/quest=3782/изучение-рассветницы
SET @ID := 3782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, расписка на двадцать пакетиков семян. Если все израсходуешь, у меня есть еще на продажу.$B$BУвы, $N, производить семена Тарлендриса в большом количестве дорого. Потому Круг Кенария и просит помощи в частичном возмещении стоимости.$B$BТе, кто находит рассветницу и приносит нам, видит, что награда верховного друида с лихвой окупает труды.', 0);

-- Add ruRU offer rewards for quest 3784
-- https://ru.tbc.wowhead.com/quest=3784/помощь-верховному-друиду-руническому-тотему
SET @ID := 3784;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приветствую, |3-6($C)! Я рад, что тебя заинтересовало наше исследование. Дел очень много, и я обманул бы тебя, сказав, что речь идет о безопасном задании. Надеюсь, тебя так просто не напугать... По твоему виду можно предположить, что тебе приходилось сталкиваться с опасностями.', 0);

-- Add ruRU offer rewards for quest 3785
-- https://ru.tbc.wowhead.com/quest=3785/изучение-рассветницы
SET @ID := 3785;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо, $N, я непременно отнесу их лично верховному друиду, когда они ему понадобятся. А пока прими это в знак признательности от Круга Кенария.$B$BНам рассветница нужна всегда. Если ты желаешь и дальше помогать нам, приноси любую рассветницу, какую сумеешь вырастить.', 0);

-- Add ruRU offer rewards for quest 3786
-- https://ru.tbc.wowhead.com/quest=3786/изучение-рассветницы
SET @ID := 3786;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо, $N, я непременно отнесу их лично верховному друиду, когда они ему понадобятся. А пока прими это в знак признательности от Круга Кенария.$B$BНам рассветница нужна всегда. Если ты желаешь и дальше помогать нам, приноси любую рассветницу, какую сумеешь вырастить.', 0);

-- Add ruRU offer rewards for quest 3787
-- https://ru.tbc.wowhead.com/quest=3787/кинтис-пламень
SET @ID := 3787;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Благодарю вас за ваш визит, $Gусталый:усталая; $Gпутник:путница;! Позвольте представиться: я – Квинтис Ночной Костер, друид и скромный слуга Малфуриона и Круга Кенария. Мои коллеги (генерал Шандриса Оперенная Луна и Протекторат – вы, может быть, о нас слыхали) и я хотели бы поговорить с вами о той работе, которую вы проводите для Фэндрала Оленьего Шлема в Дарнассе.$B$BПрежде чем мы пойдем дальше, я хотел бы попросить вас, чтобы этот разговор остался строго между нами. Если вы с этим согласны, мы можем продолжать.', 0);

-- Add ruRU offer rewards for quest 3788
-- https://ru.tbc.wowhead.com/quest=3788/кинтис-пламень
SET @ID := 3788;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Благодарю вас, что явились ко мне, $Gусталый:усталая; $Gпутник:путница;! Позвольте представиться. Я – Квинтис Ночной Костер, друид и смиренный служитель Малфуриона и Круга Кенария. Мои коллеги (генерал Шандриса Оперенная Луна и Протекторат – быть может, вы о нас слышали), и я хотел поговорить с вами о работе, которую вы ведете в Дарнассе по поручению Фэндрала Оленьего Шлема.$B$BНо прежде, чем мы продолжим наш разговор, я хотел бы вас попросить, чтобы эта беседа осталась между нами. Если вы не против, то мы можем перейти к делу.', 0);

-- Add ruRU offer rewards for quest 3790
-- https://ru.tbc.wowhead.com/quest=3790/помощь-верховному-друиду-оленьему-шлему
SET @ID := 3790;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что же, |3-6($C)... поскольку вам сказали, что этими исследованиями руковожу лично я, то вы, несомненно, прибыли сюда так быстро, как могли.$B$BИ раз уж вы здесь, постарайтесь запомнить мои пояснения с первого раза, ибо повторять я не буду.', 0);

-- Add ruRU offer rewards for quest 3791
-- https://ru.tbc.wowhead.com/quest=3791/тайна-рассветницы
SET @ID := 3791;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Какое... какое странное ощущение вызывают у меня эти растения! Во имя Элуны, что же затеял Олений Шлем?$B$BНу, как бы то ни было, спасибо вам за помощь. Вот кое-что... ну, понимаете, за труды. Мои исследования, несомненно, затянутся, и мне потребуется еще немало такой травы. Раз уж я этим занялся, пожалуй, стоит проверить, пригодна ли рассветница для использования в алхимии. И тем не менее мне не по себе от этих растений...', 0);

-- Add ruRU offer rewards for quest 3792
-- https://ru.tbc.wowhead.com/quest=3792/рассветница-для-крепости-оперенной-луны
SET @ID := 3792;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Я их пока припрячу. У меня, конечно, нет таких значительных средств, как у Оленьего Шлема, однако я все же способен вознаградить вас за труды! Тем более, кто знает, что может случиться, если Олений Шлем будет получать все больше рассветницы... Тут что-то нечисто, помяните мои слова!$B$BНе забывайте, что от лишней рассветницы я никогда не откажусь. Приносите по пять штук за раз, и я их возьму.', 0);

-- Add ruRU offer rewards for quest 3803
-- https://ru.tbc.wowhead.com/quest=3803/рассветница-для-дарнасса
SET @ID := 3803;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Верховный друид, несомненно, обрадуется этой рассветнице. Правда, должен признать... даже находиться рядом с ней с ней не особо приятно. Представляю, как тяжело верховному друиду все время возиться с этой травой!$B$BА это для тебя, $N. Круг Кенария благодарит тебя за безотказную помощь.', 0);

-- Add ruRU offer rewards for quest 3804
-- https://ru.tbc.wowhead.com/quest=3804/рассветница-для-громового-утеса
SET @ID := 3804;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно – эта рассветница несомненно поможет нам в будущем! Мы знаем, что и ночные эльфы проводят подобные исследования трав, хотя непонятно, для чего будут они использовать результаты – если, конечно, что-нибудь найдут. Верховный друид считает, что рассветница будет нам нужна до тех пор, пока мы на узнаем тайну этого растения.$B$BА это для тебя, $N. Круг Кенария благодарит тебя за неустанную помощь.', 0);

-- Add ruRU offer rewards for quest 3821
-- https://ru.tbc.wowhead.com/quest=3821/скала-молота-ужаса
SET @ID := 3821;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Бедный мой Талтрак...$B$BА мы ведь хотели уехать во Внутренние земли вместе с родителями, когда закончим службу. Теперь этим мечтам не суждено сбыться!', 0);

-- Add ruRU offer rewards for quest 3822
-- https://ru.tbc.wowhead.com/quest=3822/кромгрул
SET @ID := 3822;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Талтрак опускается на пол.>$B$BМы собирались уехать во Внутренние земли. Она рассказывала? Это было ее последнее задание.$B$B<Талтрак плачет.>$B$BОно мне не нужно, $N. Оставь его себе или выброси, мне все равно! Теперь кольцо ничего для меня не значит. Без нее оно ничто...', 0);

-- Add ruRU offer rewards for quest 3823
-- https://ru.tbc.wowhead.com/quest=3823/угасание-огненного-чрева
SET @ID := 3823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Потрясающе, солдат! Оркам и ограм понадобится несколько минут или даже часов, чтобы оправиться от удара!', 0);

-- Add ruRU offer rewards for quest 3824
-- https://ru.tbc.wowhead.com/quest=3824/гортеш-жестокий
SET @ID := 3824;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Только посмотрите на нее. Какая мерзость! Когда остатки огров Огненного Чрева увидят этот жирный чайник на вершине собственной скалы, начнется паника!$B$B<Орелиус хохочет.>', 0);

-- Add ruRU offer rewards for quest 3825
-- https://ru.tbc.wowhead.com/quest=3825/голова-огра-на-палочке-вечеринка
SET @ID := 3825;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, солдат! Поразительная! Ах, я получу медаль за храбрость, то есть, я хочу сказать, ты получишь недурную награду!', 0);

-- Add ruRU offer rewards for quest 3841
-- https://ru.tbc.wowhead.com/quest=3841/бездомный-сиротка
SET @ID := 3841;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, яйцо летучего хамелеона! И вот-вот должно проклюнуться, если я не ошибаюсь. Удивительно, как тебе удалось его добыть, да еще в таком хорошем состоянии? В Фераласе в наше время эти животные почти не делают кладок... Насколько я понимаю, в тамошних лесах развелась уйма браконьеров, которые охотятся на этих прекрасных созданий и убивают их. Какая жалость, не правда ли?$B$BНо откуда у тебя это яйцо?', 0);

-- Add ruRU offer rewards for quest 3842
-- https://ru.tbc.wowhead.com/quest=3842/инкубатор
SET @ID := 3842;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Это то, что надо. Сейчас, я смешаю все компоненты, и мы поглядим, как будет себя чувствовать детеныш...', 0);

-- Add ruRU offer rewards for quest 3843
-- https://ru.tbc.wowhead.com/quest=3843/новый-член-семьи
SET @ID := 3843;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Так-так-так... Таких мелких я даже и не видел. Лесной дракончик, если не ошибаюсь... точнее, летучий хамелеон. Отлично, отлично!$B$BНу, чтобы этот малыш благополучно выжил и вырос крепким и здоровым, нужно раздобыть для него еды! Хорошо, что ты вовремя до меня $Gдобрался:добралась;!', 0);

-- Add ruRU offer rewards for quest 3861
-- https://ru.tbc.wowhead.com/quest=3861/куд-кудаааа
SET @ID := 3861;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '"Куд-кудааа!!!"$B$BКурица начинает жадно клевать корм, который вы рассыпали перед ней.$B$BЧерез несколько мгновений она испуганно оглядывается по сторонам. Начинает скрести лапой и суетиться. Она что, яйца снести хочет? Вы думаете, что надо бы заглянуть под нее.', 0);

-- Add ruRU offer rewards for quest 3883
-- https://ru.tbc.wowhead.com/quest=3883/экология-чужих
SET @ID := 3883;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, прекрасно, ты очень $Gпомог:помогла; мне. Хотелось бы мне дать тебе большую награду, но жизнь на лоне дикой природы накладывает свои ограничения. Однако могу заверить, без твоей помощи наши исследования были бы невозможны.', 0);

-- Add ruRU offer rewards for quest 3906
-- https://ru.tbc.wowhead.com/quest=3906/дисгармония-пламени
SET @ID := 3906;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не может быть... Не может быть! Уничтожение Пирона лишь приоткрыло завесу над истинным положением вещей. В глубинах Черной горы скрываются еще более коварные силы.', 0);

-- Add ruRU offer rewards for quest 3907
-- https://ru.tbc.wowhead.com/quest=3907/дисгармония-пламени
SET @ID := 3907;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Громосерд хватает табличку Каринья>$B$BРагнарос... здесь...$B$BСтарейшины были правы, страшась зла, исходящего от Черной горы. Могущественный служитель Древних Богов! В НАШЕМ МИРЕ! Мы должны оценить наши позиции здесь, в Каргате. Нужно решить, стоит ли остаться и драться или бежать в страхе перед новым Расколом.$B$BЛучше больше не приближайся к Черной горе, $N. В ее глубинах кроется куда более великое зло, чем все, что встречалось тебе раньше.', 0);

-- Add ruRU offer rewards for quest 3909
-- https://ru.tbc.wowhead.com/quest=3909/эликсир-видере
SET @ID := 3909;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мне нужна одна склянка эликсира, чтобы проверить, правильный ли это состав... Да, это он.', 0);

-- Add ruRU offer rewards for quest 3911
-- https://wowroad.info/?quest=3911
SET @ID := 3911;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Замечательно! Я немедленно отправлю их курьером в Подгород!$B$BДля вас - оплата, как и было обещано.', 0);

-- Add ruRU offer rewards for quest 3912
-- https://ru.tbc.wowhead.com/quest=3912/встречаемся-на-кладбище
SET @ID := 3912;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Давненько никто не говорил со мной...', 0);

-- Add ruRU offer rewards for quest 3913
-- https://ru.tbc.wowhead.com/quest=3913/замогильная-история
SET @ID := 3913;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Камень отодвинут в сторону, под ним находится небольшое углубление. Положив в него меч Линкена, вы понимаете, что меч идеально ложится туда.', 0);

-- Add ruRU offer rewards for quest 3914
-- https://ru.tbc.wowhead.com/quest=3914/меч-линкена
SET @ID := 3914;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мой меч, он закончен!$B$BВспомнить бы еще, на что он мне сдался...$B$BДай-ка я пока заплачу тебе за работу.', 0);

-- Add ruRU offer rewards for quest 3941
-- https://ru.tbc.wowhead.com/quest=3941/помощь-гномов
SET @ID := 3941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Стой на месте, не шевелись... Я испытываю новую комбинацию кристаллов...', 0);

-- Add ruRU offer rewards for quest 3942
-- https://ru.tbc.wowhead.com/quest=3942/память-линкена
SET @ID := 3942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Приветствую тебя, |3-6($C). Могу ли я чем-то помочь тебе?', 0);

-- Add ruRU offer rewards for quest 3961
-- https://ru.tbc.wowhead.com/quest=3961/приключения-линкена
SET @ID := 3961;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Джей Ди вообще хоть чем-нибудь помогла тебе?', 0);

-- Add ruRU offer rewards for quest 3962
-- https://ru.tbc.wowhead.com/quest=3962/один-в-поле-не-воин
SET @ID := 3962;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N.$B$BТеперь Золотое пламя будет возвращено на мою родину, где мы сможем защитить его от посягающих на него негодяев.$B$BЕсли бы не ты, я до сих пор не помнил бы, кто я такой и зачем пришел! Я хочу отблагодарить тебя!$B$BБери все что нравится!', 0);

-- Add ruRU offer rewards for quest 3981
-- https://ru.tbc.wowhead.com/quest=3981/командир-горшак
SET @ID := 3981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'У нас мало времени. Слушай внимательно, |3-6($R). Сведения, которые я сообщу тебе, совершенно секретны и не подлежат разглашению.', 0);

-- Add ruRU offer rewards for quest 3982
-- https://ru.tbc.wowhead.com/quest=3982/что-происходит
SET @ID := 3982;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'На этот раз все обошлось. Но теперь они поднимут тревогу... и пришлют за тобой еще стражников.', 0);
