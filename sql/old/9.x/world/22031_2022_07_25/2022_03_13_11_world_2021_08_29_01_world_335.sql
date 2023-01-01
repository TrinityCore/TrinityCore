-- Add ruRU offer rewards for quest 328
-- https://ru.classic.wowhead.com/quest=328/спрятанный-ключ
SET @ID := 328;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Открыв сейф, вы понимаете, что именно здесь Герод хранил самые ценные монеты и прочие вещи.', 0);

-- Add ruRU offer rewards for quest 329
-- https://ru.classic.wowhead.com/quest=329/шпион-найден
SET @ID := 329;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Эта записка позволит нам вычислить и уничтожить предателя!', 0);

-- Add ruRU offer rewards for quest 330
-- https://ru.classic.wowhead.com/quest=330/расписание-дежурств
SET @ID := 330;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, да, я могу узнать. Посмотрим... на прошлой неделе…$B$B... Да, с Торсеном дежурил рядовой Мерль. Всю прошлую неделю у них совпадало расписание дежурств.', 0);

-- Add ruRU offer rewards for quest 331
-- https://ru.classic.wowhead.com/quest=331/доклад-дорену
SET @ID := 331;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мне больно слышать, что нас предал Мерль. Он был храбрым солдатом, и мне казалось, что верным. С другой стороны, хорошо, что мы его нашли – с таким шпионом в наших рядах... мы недолго продержались бы против полковника Курцена.', 0);

-- Add ruRU offer rewards for quest 343
-- https://ru.classic.wowhead.com/quest=343/кстати-о-стойкости-духа
SET @ID := 343;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Металлургия? Да, конечно, у нас много книг по данной отрасли знаний, и мы будем рады помочь брату Кристофу в подготовке лекции! Какая же книга его интересует?', 0);

-- Add ruRU offer rewards for quest 379
-- https://ru.classic.wowhead.com/quest=379/утолить-жажду
SET @ID := 379;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, вот тебе источник энергии. Честно говоря, он создан совсем не для исследовательского набора вроде этого, поэтому у тебя будет не так уж много времени, а потом все данные кирдыкнутся!$B$BКак только соберешь, все, что нужно, принеси эту штуковину мне, чтобы я отключил ее как надо. У тебя не больше двух часов на все про все.$B$BЕсли ты не успеешь, я, конечно, продам тебе еще один источник энергии. Ключевое слово – продам!', 0);

-- Add ruRU offer rewards for quest 397
-- https://ru.classic.wowhead.com/quest=397/за-достойную-службу
SET @ID := 397;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хозяин дал подарок для $N. Згги хотел бы оставить его себе, но Згги знает, что будет, если предать хозяина.', 0);

-- Add ruRU offer rewards for quest 403
-- https://ru.classic.wowhead.com/quest=403/охраняемый-бочонок-громопойла
SET @ID := 403;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Этот бочонок эля охраняет Ярвен Громовар. Пока он в подвале, до бочек не добраться.', 0);

-- Add ruRU offer rewards for quest 410
-- https://ru.classic.wowhead.com/quest=410/спящая-тень
SET @ID := 410;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы ставите на стол Манящую свечу и зажигаете ее...', 0);

-- Add ruRU offer rewards for quest 415
-- https://ru.classic.wowhead.com/quest=415/новое-пиво-регольда
SET @ID := 415;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Помнишь тот звездолист, что ты $Gпринес:принесла; мне? Ну так я его использовал в новых рецептах, над которыми работал, и в одном случае вышло просто великолепно!$B$BВот, попробуй и скажи, как пошло...', 0);

-- Add ruRU offer rewards for quest 431
-- https://ru.classic.wowhead.com/quest=431/манящие-свечи
SET @ID := 431;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы берете одну свечу и кладете ее в сумку.', 0);

-- Add ruRU offer rewards for quest 485
-- https://ru.classic.wowhead.com/quest=485/найти-кпх-9-hl
SET @ID := 485;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы помещаете яйцевидный аварийный маяк в механического цыпленка.$B$BС гудением и жужжанием робот поднимается на ноги, после чего из его механических внутренностей слышится голос Карлса:$B$B"Что ж, по крайней мере, OOX-09/HL работает, но ему требуется капитальный ремонт! Он тяжелый, и нести его ты не сможешь, но вообще у меня есть одна мысль... Не хочешь ли присмотреть за ним еще немного?"', 0);

-- Add ruRU offer rewards for quest 507
-- https://ru.classic.wowhead.com/quest=507/лорд-алиден-перенольд
SET @ID := 507;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Нет, прошу вас, не убивайте меня! Я не хотела причинять зло вашему народу, он взял меня против воли! Пожалуйста... Пощадите меня!', 0);

-- Add ruRU offer rewards for quest 508
-- https://ru.classic.wowhead.com/quest=508/подарок-тареты
SET @ID := 508;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Странно, что вождь пошел на такие затраты ради этой мелочи. Я не всегда понимаю его мотивы, но я последую за ним, каковы бы ни были его приказы. Ты отлично $Gпоработал:поработала;, $N, и я не сомневаюсь, что вождь будет рад услышать о твоем успехе.', 0);

-- Add ruRU offer rewards for quest 511
-- https://ru.classic.wowhead.com/quest=511/зашифрованное-письмо
SET @ID := 511;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что это? Минуточку... Дай-ка взглянуть поближе.$B$B...$B$BХм, никогда не встречался с таким шифром, но, признаться, в этой области я не очень сведущ.', 0);

-- Add ruRU offer rewards for quest 522
-- https://ru.classic.wowhead.com/quest=522/контракт-убийцы
SET @ID := 522;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Малеб изучает контракт.>$B$BТеперь мне понятна подоплека последнего нападения на Южнобережье. Наверное, Синдикат хочет добраться до меня, как и до моего предшественника!', 0);

-- Add ruRU offer rewards for quest 525
-- https://ru.classic.wowhead.com/quest=525/все-больше-тайн
SET @ID := 525;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Малеб читает письмо.>$B$BЭто расшифровка письма, найденного вами в лагере Синдиката? Оно написано не вором, и даже не альтеракским аристократом.$B$BПохоже, у Синдиката есть связи с другими силами, и мне страшно подумать, что это за силы могут быть.', 0);

-- Add ruRU offer rewards for quest 536
-- https://ru.tbc.wowhead.com/quest=536/на-побережье
SET @ID := 536;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Надеюсь, этого хватит, чтобы убедить Крассена, что я – ха! – выполняю его приказы и избавляю Южнобережье от страшной и ужасной угрозы, жутких мурлоков! Нет ничего страшнее ярости рыбы-переростка!', 0);

-- Add ruRU offer rewards for quest 537
-- https://ru.tbc.wowhead.com/quest=537/темный-совет
SET @ID := 537;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $N. Не хотелось бы, чтобы Недремлющий Аргус присоединился к Синдикату.$B$BХотя тебе и удалось убить их главаря в этих землях, ясно, что Нагаз был чьим-то слугой. Похоже, Недремлющий Аргус пустил корни по всему нашему континенту.$B$BИли по всему миру.', 0);

-- Add ruRU offer rewards for quest 551
-- https://ru.tbc.wowhead.com/quest=551/заколдованный-пергамент
SET @ID := 551;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Опять зашифрованные записки?$B$BХотел бы я уметь разгадывать шифры, чтобы разобрать все странные фрагменты записей, что доходят к нам из Альтерака. Но боюсь, мне не хватает знаний.', 0);

-- Add ruRU offer rewards for quest 555
-- https://ru.tbc.wowhead.com/quest=555/нежный-черепаховый-суп
SET @ID := 555;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Все будут в восторге – здесь снова подают нежный черепаховый суп шеф-повара Джессена!', 0);

-- Add ruRU offer rewards for quest 564
-- https://ru.tbc.wowhead.com/quest=564/серьезная-угроза
SET @ID := 564;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличные новости! Надо было сразу же найти нормального героя войны, чтобы он разобрался со зверюгами. Твой папка гордился бы тобой, $N.', 0);

-- Add ruRU offer rewards for quest 571
-- https://ru.tbc.wowhead.com/quest=571/чары-моктардина
SET @ID := 571;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходное сухожилие, $N. Твои усилия скоро окупятся.', 0);

-- Add ruRU offer rewards for quest 573
-- https://ru.tbc.wowhead.com/quest=573/чары-моктардина
SET @ID := 573;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты принес мне воду Святого источника, и я могу наложить чары на церемониальное колье.$B$BНоси его с гордостью, во имя Вождя и мощи Орды.', 0);

-- Add ruRU offer rewards for quest 584
-- https://ru.classic.wowhead.com/quest=584/головы-племени-кровавого-скальпа
SET @ID := 584;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы кладете в котел головы Ган\'зулаха и Неззилока...', 0);

-- Add ruRU offer rewards for quest 592
-- https://ru.classic.wowhead.com/quest=592/спасение-йеннику
SET @ID := 592;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Победа! Ты $Gосвободил:освободила; Йеннику от воли Занзила и выполнил задание, которое я считал безнадежным.$B$BНаше племя будет воспевать твое имя, $N, и мы на каменных плитах напишем повесть о тебе, чтобы она никогда не забылась.', 0);

-- Add ruRU offer rewards for quest 593
-- https://ru.classic.wowhead.com/quest=593/наполнение-самоцвета-души
SET @ID := 593;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вы прикасаетесь к его лбу самоцветом Души. Он вздрагивает, когда волшебный предмет всасывает его разум, оставляя лишь тело, бездушную оболочку.', 0);

-- Add ruRU offer rewards for quest 595
-- https://ru.classic.wowhead.com/quest=595/пираты-кровавого-паруса
SET @ID := 595;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'На крышке бочки лежит карта, на которой торопливо нацарапана пара слов, и несколько монет.', 0);
