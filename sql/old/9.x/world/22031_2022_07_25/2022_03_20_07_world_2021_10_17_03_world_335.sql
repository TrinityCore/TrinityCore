-- Add ruRU offer rewards for quest 4504
-- https://ru.tbc.wowhead.com/quest=5504/оплечья-рассвета
SET @ID := 4504;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поразительно – не зря всех восхищает твоя преданность Серебряному Рассвету. Теперь я с радостью предлагаю на выбор наши оплечья. Пока наше отношение к тебе не изменится, ты сможешь купить эти мантии у любого интенданта Серебряного Рассвета.$B$BЗа Рассвет, $Gбрат:сестра; $Gмой:моя;!', 0);

-- Add ruRU offer rewards for quest 4507
-- Duplicate text in En locale
SET @ID := 4507;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поразительно – не зря всех восхищает твоя преданность Серебряному Рассвету. Теперь я с радостью предлагаю на выбор наши оплечья. Пока наше отношение к тебе не изменится, ты сможешь купить эти мантии у любого интенданта Серебряного Рассвета.$B$BЗа Рассвет, $Gбрат:сестра; $Gмой:моя;!', 0);

-- Add ruRU offer rewards for quest 5517
-- https://ru.tbc.wowhead.com/quest=5517/многоцветная-драгоценность-рассвета
SET @ID := 5517;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что и говорить, твои подвиги весьма впечатляют, $N – прими же многоцветное оплечье Рассвета!$B$BПока в Серебряном Рассвете тебя превозносят, ты можешь покупать дополнительные многоцветные оплечья у любого из интендантов Рассвета.', 0);

-- Add ruRU offer rewards for quest 5521
-- Duplicate Text in En locale
SET @ID := 5521;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что и говорить, твои подвиги весьма впечатляют, $N – прими же многоцветное оплечье Рассвета!$B$BПока в Серебряном Рассвете тебя превозносят, ты можешь покупать дополнительные многоцветные оплечья у любого из интендантов Рассвета.', 0);

-- Add ruRU offer rewards for quest 5524
-- Duplicate Text in En locale
SET @ID := 5524;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что и говорить, твои подвиги весьма впечатляют, $N – прими же многоцветное оплечье Рассвета!$B$BПока в Серебряном Рассвете тебя превозносят, ты можешь покупать дополнительные многоцветные оплечья у любого из интендантов Рассвета.', 0);

-- Add ruRU offer rewards for quest 5628
-- https://wowroad.info/?quest=5628
SET @ID := 5628;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что ты $Gвернулся:вернулась; домой, $N. Это всегда радует Тиранду и меня лично, когда кто-то из наших возвращается из дальних странствий. Надеюсь, Элуна благословила твое путешествие!$B$BМожет быть, ты расскажешь мне что-нибудь о том, что ты $Gвидел:видела; после того, как мы закончим с делами.', 0);

-- Add ruRU offer rewards for quest 5630
-- Duplicate Text in En locale
SET @ID := 5630;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что ты $Gвернулся:вернулась; домой, $N. Это всегда радует Тиранду и меня лично, когда кто-то из наших возвращается из дальних странствий. Надеюсь, Элуна благословила твое путешествие!$B$BМожет быть, ты расскажешь мне что-нибудь о том, что ты $Gвидел:видела; после того, как мы закончим с делами.', 0);

-- Add ruRU offer rewards for quest 5629
-- https://wowroad.info/?quest=5629
SET @ID := 5629;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо, что ты $Gвернулся:вернулась;, $N. Это всегда радует Тиранду и меня лично, когда кто-то из наших возвращается из дальних странствий. Надеюсь, Элуна благословила твое путешествие!$B$BМожет быть, ты расскажешь мне что-нибудь о том, что ты $Gвидел:видела; после того, как мы закончим с делами.', 0);

-- Add ruRU offer rewards for quest 5635
-- https://ru.tbc.wowhead.com/quest=5635/молитва-отчаяния
SET @ID := 5635;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рада твоему прибытию, $N. Есть множество вещей, которые нам нужно обсудить, но самая важная – твое будущее обучение тайному знанию Света.$B$BЕсть уроки, которые должны выучить все, кто служит Свету. Если ты чувствуешь в себе силы, мы можем начать прямо сейчас.', 0);

-- Add ruRU offer rewards for quest 5636
-- Duplicate Text in En locale
SET @ID := 5636;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рада твоему прибытию, $N. Есть множество вещей, которые нам нужно обсудить, но самая важная – твое будущее обучение тайному знанию Света.$B$BЕсть уроки, которые должны выучить все, кто служит Свету. Если ты чувствуешь в себе силы, мы можем начать прямо сейчас.', 0);

-- Add ruRU offer rewards for quest 5637
-- Duplicate Text in En locale
SET @ID := 5637;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рада твоему прибытию, $N. Есть множество вещей, которые нам нужно обсудить, но самая важная – твое будущее обучение тайному знанию Света.$B$BЕсть уроки, которые должны выучить все, кто служит Свету. Если ты чувствуешь в себе силы, мы можем начать прямо сейчас.', 0);

-- Add ruRU offer rewards for quest 5638
-- Duplicate Text in En locale
SET @ID := 5638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рада твоему прибытию, $N. Есть множество вещей, которые нам нужно обсудить, но самая важная – твое будущее обучение тайному знанию Света.$B$BЕсть уроки, которые должны выучить все, кто служит Свету. Если ты чувствуешь в себе силы, мы можем начать прямо сейчас.', 0);

-- Add ruRU offer rewards for quest 5639
-- Duplicate Text in En locale
SET @ID := 5639;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рада твоему прибытию, $N. Есть множество вещей, которые нам нужно обсудить, но самая важная – твое будущее обучение тайному знанию Света.$B$BЕсть уроки, которые должны выучить все, кто служит Свету. Если ты чувствуешь в себе силы, мы можем начать прямо сейчас.', 0);

-- Add ruRU offer rewards for quest 5640
-- Duplicate Text in En locale
SET @ID := 5640;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рада твоему прибытию, $N. Есть множество вещей, которые нам нужно обсудить, но самая важная – твое будущее обучение тайному знанию Света.$B$BЕсть уроки, которые должны выучить все, кто служит Свету. Если ты чувствуешь в себе силы, мы можем начать прямо сейчас.', 0);

-- Add ruRU offer rewards for quest 5659
-- https://wowroad.info/?quest=5659
SET @ID := 5659;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, хорошо, еще $Gодин:одна; $Gприбыл:прибыла;. Время для меня не имеет значения, но для других-то оно ценно. Много вещей предстоит тебе изучить, а мне предстоит тебя многому научить. Так что давай, учись. Учись, и будешь $Gвознагражден:вознаграждена;.', 0);

-- Add ruRU offer rewards for quest 5660
-- Duplicate Text in En locale
SET @ID := 5660;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, хорошо, еще $Gодин:одна; $Gприбыл:прибыла;. Время для меня не имеет значения, но для других-то оно ценно. Много вещей предстоит тебе изучить, а мне предстоит тебя многому научить. Так что давай, учись. Учись, и будешь $Gвознагражден:вознаграждена;.', 0);

-- Add ruRU offer rewards for quest 5661
-- Duplicate Text in En locale
SET @ID := 5661;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, хорошо, еще $Gодин:одна; $Gприбыл:прибыла;. Время для меня не имеет значения, но для других-то оно ценно. Много вещей предстоит тебе изучить, а мне предстоит тебя многому научить. Так что давай, учись. Учись, и будешь $Gвознагражден:вознаграждена;.', 0);

-- Add ruRU offer rewards for quest 5662
-- Duplicate Text in En locale
SET @ID := 5662;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, хорошо, еще $Gодин:одна; $Gприбыл:прибыла;. Время для меня не имеет значения, но для других-то оно ценно. Много вещей предстоит тебе изучить, а мне предстоит тебя многому научить. Так что давай, учись. Учись, и будешь $Gвознагражден:вознаграждена;.', 0);

-- Add ruRU offer rewards for quest 5663
-- Duplicate Text in En locale
SET @ID := 5663;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, хорошо, еще $Gодин:одна; $Gприбыл:прибыла;. Время для меня не имеет значения, но для других-то оно ценно. Много вещей предстоит тебе изучить, а мне предстоит тебя многому научить. Так что давай, учись. Учись, и будешь $Gвознагражден:вознаграждена;.', 0);

-- Add ruRU offer rewards for quest 5805
-- https://wowroad.info/?quest=5805
SET @ID := 5805;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, теперь приветствую тебя в мире Азерота. Иди вперед, к славе, наградам и почестям!', 0);

-- Add ruRU offer rewards for quest 5841
-- Duplicate Text in En locale
SET @ID := 5841;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, теперь приветствую тебя в мире Азерота. Иди вперед, к славе, наградам и почестям!', 0);

-- Add ruRU offer rewards for quest 5842
-- Duplicate Text in En locale
SET @ID := 5842;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, теперь приветствую тебя в мире Азерота. Иди вперед, к славе, наградам и почестям!', 0);

-- Add ruRU offer rewards for quest 5843
-- Duplicate Text in En locale
SET @ID := 5843;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, теперь приветствую тебя в мире Азерота. Иди вперед, к славе, наградам и почестям!', 0);

-- Add ruRU offer rewards for quest 5844
-- Duplicate Text in En locale
SET @ID := 5844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, теперь приветствую тебя в мире Азерота. Иди вперед, к славе, наградам и почестям!', 0);

-- Add ruRU offer rewards for quest 5847
-- Duplicate Text in En locale
SET @ID := 5847;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ну, $N, теперь приветствую тебя в мире Азерота. Иди вперед, к славе, наградам и почестям!', 0);

-- Add ruRU offer rewards for quest 5923
-- https://ru.tbc.wowhead.com/quest=5923/зов-природы
SET @ID := 5923;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рад, что ты $Gнашел:нашла; сюда дорогу, $Gюный:юная; $Gдруид:дева-друид;. Пришло тебе время вступить в большой мир.$B$BВ сердце каждого из детей Кенария звучит зов природы. Животные и растения – наши друзья и наша забота. Мы сознательно посвящаем наши жизни сохранению равновесия ради их и нашего блага. Чтобы сделать первый шаг в этот мир, ты $Gдолжен:должна; обучиться искусству превращения в медведя. Так ты познаешь, что такое сила тела и духа.$B$BГотовься!', 0);

-- Add ruRU offer rewards for quest 5924
-- Duplicate Text in En locale
SET @ID := 5924;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рад, что ты $Gнашел:нашла; сюда дорогу, $Gюный:юная; $Gдруид:дева-друид;. Пришло тебе время вступить в большой мир.$B$BВ сердце каждого из детей Кенария звучит зов природы. Животные и растения – наши друзья и наша забота. Мы сознательно посвящаем наши жизни сохранению равновесия ради их и нашего блага. Чтобы сделать первый шаг в этот мир, ты $Gдолжен:должна; обучиться искусству превращения в медведя. Так ты познаешь, что такое сила тела и духа.$B$BГотовься!', 0);

-- Add ruRU offer rewards for quest 5926
-- Duplicate Text in En locale
SET @ID := 5926;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рад, что ты $Gнашел:нашла; сюда дорогу, $Gюный:юная; $Gдруид:дева-друид;. Пришло тебе время вступить в большой мир.$B$BВ сердце каждого из детей Кенария звучит зов природы. Животные и растения – наши друзья и наша забота. Мы сознательно посвящаем наши жизни сохранению равновесия ради их и нашего блага. Чтобы сделать первый шаг в этот мир, ты $Gдолжен:должна; обучиться искусству превращения в медведя. Так ты познаешь, что такое сила тела и духа.$B$BГотовься!', 0);

-- Add ruRU offer rewards for quest 5927
-- Duplicate Text in En locale
SET @ID := 5927;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рад, что ты $Gнашел:нашла; сюда дорогу, $Gюный:юная; $Gдруид:дева-друид;. Пришло тебе время вступить в большой мир.$B$BВ сердце каждого из детей Кенария звучит зов природы. Животные и растения – наши друзья и наша забота. Мы сознательно посвящаем наши жизни сохранению равновесия ради их и нашего блага. Чтобы сделать первый шаг в этот мир, ты $Gдолжен:должна; обучиться искусству превращения в медведя. Так ты познаешь, что такое сила тела и духа.$B$BГотовься!', 0);

-- Add ruRU offer rewards for quest 5928
-- Duplicate Text in En locale
SET @ID := 5928;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я рад, что ты $Gнашел:нашла; сюда дорогу, $Gюный:юная; $Gдруид:дева-друид;. Пришло тебе время вступить в большой мир.$B$BВ сердце каждого из детей Кенария звучит зов природы. Животные и растения – наши друзья и наша забота. Мы сознательно посвящаем наши жизни сохранению равновесия ради их и нашего блага. Чтобы сделать первый шаг в этот мир, ты $Gдолжен:должна; обучиться искусству превращения в медведя. Так ты познаешь, что такое сила тела и духа.$B$BГотовься!', 0);

-- Add ruRU offer rewards for quest 6065
-- https://wowroad.info/?quest=6065
SET @ID := 6065;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я полагаю, что ты уже $Gготов:готова;...', 0);

-- Add ruRU offer rewards for quest 6066
-- Duplicate Text in En locale
SET @ID := 6066;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я полагаю, что ты уже $Gготов:готова;...', 0);

-- Add ruRU offer rewards for quest 6067
-- Duplicate Text in En locale
SET @ID := 6067;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я полагаю, что ты уже $Gготов:готова;...', 0);

-- Add ruRU offer rewards for quest 6068
-- https://wowroad.info/?quest=6068
SET @ID := 6068;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, тебе, пожалуй, пора учиться дальше.', 0);

-- Add ruRU offer rewards for quest 6069
-- Duplicate Text in En locale
SET @ID := 6069;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, тебе, пожалуй, пора учиться дальше.', 0);

-- Add ruRU offer rewards for quest 6070
-- Duplicate Text in En locale
SET @ID := 6070;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, тебе, пожалуй, пора учиться дальше.', 0);

-- Add ruRU offer rewards for quest 6071
-- https://wowroad.info/?quest=6071
SET @ID := 6071;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, пришло время, $C.', 0);

-- Add ruRU offer rewards for quest 6072
-- Duplicate Text in En locale
SET @ID := 6072;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, пришло время, $C.', 0);

-- Add ruRU offer rewards for quest 6073
-- Duplicate Text in En locale
SET @ID := 6073;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, пришло время, $C.', 0);

-- Add ruRU offer rewards for quest 6074
-- https://wowroad.info/?quest=6074
SET @ID := 6074;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я думаю, что теперь ты $Gготов:готова;...', 0);

-- Add ruRU offer rewards for quest 6075
-- Duplicate Text in En locale
SET @ID := 6075;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я думаю, что теперь ты $Gготов:готова;...', 0);

-- Add ruRU offer rewards for quest 6076
-- Duplicate Text in En locale
SET @ID := 6076;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я думаю, что теперь ты $Gготов:готова;...', 0);

-- Add ruRU offer rewards for quest 6123
-- https://ru.tbc.wowhead.com/quest=6123/создание-лекарства
SET @ID := 6123;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N, вы принесли так много, что должно хватить на несколько больших доз мази – по крайней мере чтобы исцеление началось.$B$BИзготовление средств против ядов иногда бывает весьма сложным, поскольку каждый из них требует конкретного антидота для нейтрализации воздействия. Здорово было бы уметь в любой момент снимать отравление, не беспокоясь о конкретных ингредиентах, которые должен содержать антидот!$B$BА теперь позвольте мне приступить к работе!', 0);

-- Add ruRU offer rewards for quest 6128
-- Duplicate Text in En locale
SET @ID := 6128;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N, вы принесли так много, что должно хватить на несколько больших доз мази – по крайней мере чтобы исцеление началось.$B$BИзготовление средств против ядов иногда бывает весьма сложным, поскольку каждый из них требует конкретного антидота для нейтрализации воздействия. Здорово было бы уметь в любой момент снимать отравление, не беспокоясь о конкретных ингредиентах, которые должен содержать антидот!$B$BА теперь позвольте мне приступить к работе!', 0);

-- Add ruRU offer rewards for quest 6642
-- https://ru.tbc.wowhead.com/quest=6642/покровительство-братства-черное-железо
SET @ID := 6642;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твой дар приняли и оценили. Ты $Gзаслужил:заслужила; добрую славу. Если братство удостоверится в твоей преданности, тебе дадут доступ к тайнам древних ремесел.', 0);

-- Add ruRU offer rewards for quest 6643
-- Duplicate Text in En locale
SET @ID := 6643;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твой дар приняли и оценили. Ты $Gзаслужил:заслужила; добрую славу. Если братство удостоверится в твоей преданности, тебе дадут доступ к тайнам древних ремесел.', 0);

-- Add ruRU offer rewards for quest 6644
-- Duplicate Text in En locale
SET @ID := 6644;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твой дар приняли и оценили. Ты $Gзаслужил:заслужила; добрую славу. Если братство удостоверится в твоей преданности, тебе дадут доступ к тайнам древних ремесел.', 0);

-- Add ruRU offer rewards for quest 6645
-- Duplicate Text in En locale
SET @ID := 6645;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твой дар приняли и оценили. Ты $Gзаслужил:заслужила; добрую славу. Если братство удостоверится в твоей преданности, тебе дадут доступ к тайнам древних ремесел.', 0);

-- Add ruRU offer rewards for quest 6646
-- Duplicate Text in En locale
SET @ID := 6646;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твой дар приняли и оценили. Ты $Gзаслужил:заслужила; добрую славу. Если братство удостоверится в твоей преданности, тебе дадут доступ к тайнам древних ремесел.', 0);

-- Add ruRU offer rewards for quest 7002
-- https://ru.tbc.wowhead.com/quest=7002/упряжь-из-бараньей-кожи
SET @ID := 7002;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, солдат. Я скажу тебе, когда будет достаточно.$B$BА пока продолжай работать!', 0);

-- Add ruRU offer rewards for quest 7026
-- Duplicate Text in En locale
SET @ID := 7026;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, солдат. Я скажу тебе, когда будет достаточно.$B$BА пока продолжай работать!', 0);

-- Add ruRU offer rewards for quest 7022
-- https://ru.tbc.wowhead.com/quest=7022/здравствуй-дедушка-зима
SET @ID := 7022;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хо-хо-хо! Я Дедушка Зима, и от имени доброго народа Пастбищ Дымного Леса... "Свежие фрукты от нашего села да к вашему столу, вкусная и здоровая пища из Пастбищ Дымного Леса," – хотел бы пожелать всем замечательно провести праздник Зимнего Покрова.$B$BЕсли в этом году ты $Gбыл:была; $Gпримерным:примерной; $Gмальчиком:девочкой;, то, может быть, ты получишь лакомство от Пастбищ Дымного Леса в качестве угощения на праздник Зимнего Покрова. Хо-хо!', 0);

-- Add ruRU offer rewards for quest 7023
-- Duplicate Text in En locale
SET @ID := 7023;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хо-хо-хо! Я Дедушка Зима, и от имени доброго народа Пастбищ Дымного Леса... "Свежие фрукты от нашего села да к вашему столу, вкусная и здоровая пища из Пастбищ Дымного Леса," – хотел бы пожелать всем замечательно провести праздник Зимнего Покрова.$B$BЕсли в этом году ты $Gбыл:была; $Gпримерным:примерной; $Gмальчиком:девочкой;, то, может быть, ты получишь лакомство от Пастбищ Дымного Леса в качестве угощения на праздник Зимнего Покрова. Хо-хо!', 0);

-- Add ruRU offer rewards for quest 7498
-- https://ru.tbc.wowhead.com/quest=7498/гарона-исследование-уловок-и-предательства
SET @ID := 7498;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7499
-- Duplicate Text in En locale
SET @ID := 7499;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7500
-- Duplicate Text in En locale
SET @ID := 7500;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 501
-- Duplicate Text in En locale
SET @ID := 7501;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7502
-- Duplicate Text in En locale
SET @ID := 7502;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7503
-- Duplicate Text in En locale
SET @ID := 7503;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7504
-- Duplicate Text in En locale
SET @ID := 7504;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7505
-- Duplicate Text in En locale
SET @ID := 7505;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7506
-- Duplicate Text in En locale
SET @ID := 7506;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, |3-6($R). Если найдете еще какие-то книги, несите их нам, не раздумывая.$B$BСо временем мы подбираем все новые награды за возвращение пропавших экземпляров!', 0);

-- Add ruRU offer rewards for quest 7649
-- https://ru.tbc.wowhead.com/quest=7649/зачарованная-ториевая-броня-том-i
SET @ID := 7649;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $Gмой:моя; $Gмальчик:девочка;!$B$B<Сказитель Лидрос выдирает из книги одну страницу.>$B$BВот, этот чертеж тебе наверняка пригодится!', 0);

-- Add ruRU offer rewards for quest 7650
-- Duplicate Text in En locale
SET @ID := 7650;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $Gмой:моя; $Gмальчик:девочка;!$B$B<Сказитель Лидрос выдирает из книги одну страницу.>$B$BВот, этот чертеж тебе наверняка пригодится!', 0);

-- Add ruRU offer rewards for quest 7651
-- Duplicate Text in En locale
SET @ID := 7651;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$GМолодец:Умница;, $Gмой:моя; $Gмальчик:девочка;!$B$B<Сказитель Лидрос выдирает из книги одну страницу.>$B$BВот, этот чертеж тебе наверняка пригодится!', 0);

-- Add ruRU offer rewards for quest 7793
-- https://ru.tbc.wowhead.com/quest=7793/пожертвование-шелк
SET @ID := 7793;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7794
-- Duplicate Text in En locale
SET @ID := 7794;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7799
-- Duplicate Text in En locale
SET @ID := 7799;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7803
-- Duplicate Text in En locale
SET @ID := 7803;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7804
-- Duplicate Text in En locale
SET @ID := 7804;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7807
-- Duplicate Text in En locale
SET @ID := 7807;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7808
-- Duplicate Text in En locale
SET @ID := 7808;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7809
-- Duplicate Text in En locale
SET @ID := 7809;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7813
-- Duplicate Text in En locale
SET @ID := 7813;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7814
-- Duplicate Text in En locale
SET @ID := 7814;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7817
-- Duplicate Text in En locale
SET @ID := 7817;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7820
-- Duplicate Text in En locale
SET @ID := 7820;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7821
-- Duplicate Text in En locale
SET @ID := 7821;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7822
-- Duplicate Text in En locale
SET @ID := 7822;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7826
-- Duplicate Text in En locale
SET @ID := 7826;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7827
-- Duplicate Text in En locale
SET @ID := 7827;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7831
-- Duplicate Text in En locale
SET @ID := 7831;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7833
-- Duplicate Text in En locale
SET @ID := 7833;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7834
-- Duplicate Text in En locale
SET @ID := 7834;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7835
-- Duplicate Text in En locale
SET @ID := 7835;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасно! $N, благодарим тебя за щедрое пожертвование!', 0);

-- Add ruRU offer rewards for quest 7795
-- https://ru.tbc.wowhead.com/quest=7795/пожертвование-руническая-ткань
SET @ID := 7795;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7800
-- Duplicate Text in En locale
SET @ID := 7800;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7811
-- Duplicate Text in En locale
SET @ID := 7811;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7818
-- Duplicate Text in En locale
SET @ID := 7818;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7823
-- Duplicate Text in En locale
SET @ID := 7823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7824
-- Duplicate Text in En locale
SET @ID := 7824;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7836
-- Duplicate Text in En locale
SET @ID := 7836;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Превосходно! Ткань сразу пойдет в дело, уж не сомневайся. Благодарю тебя за помощь! Без тебя мы бы точно пропали.$B$BХотя мы и так получили от тебя много ткани, если ты вдруг соблаговолишь в будущем пожертвовать еще, я найду ей применение. Просто свяжись со мной, и я лично позабочусь, чтобы твои добрые дела не остались незамеченными!', 0);

-- Add ruRU offer rewards for quest 7796
-- https://ru.tbc.wowhead.com/quest=7796/больше-рунической-ткани
SET @ID := 7796;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7801
-- Duplicate Text in En locale
SET @ID := 7801;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7806
-- Duplicate Text in En locale
SET @ID := 7806;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7812
-- Duplicate Text in En locale
SET @ID := 7812;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7819
-- Duplicate Text in En locale
SET @ID := 7819;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7825
-- Duplicate Text in En locale
SET @ID := 7825;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7832
-- Duplicate Text in En locale
SET @ID := 7832;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7837
-- Duplicate Text in En locale
SET @ID := 7837;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '$N! Что бы мы делали без героев, щедростью сравнимых с тобой?! Спасибо за то, что не забываешь о нас!', 0);

-- Add ruRU offer rewards for quest 7863
-- https://wowroad.info/?quest=7863
SET @ID := 7863;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хорошо $Gзарекомендовал:зарекомендовала; себя, $N, тут сомнений нет! В награду возьми этот пакет! В нем паек и бинты, которые найдешь только в Ущелье Песни Войны.$B$BКогда в Ущелье тебя еще больше зауважают, тебе их тут даже продадут. Паек мы выдаем, если относимся к кому-то дружественно, а бинты – когда уважаем.', 0);

-- Add ruRU offer rewards for quest 7864
-- Duplicate Text in En locale
SET @ID := 7864;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хорошо $Gзарекомендовал:зарекомендовала; себя, $N, тут сомнений нет! В награду возьми этот пакет! В нем паек и бинты, которые найдешь только в Ущелье Песни Войны.$B$BКогда в Ущелье тебя еще больше зауважают, тебе их тут даже продадут. Паек мы выдаем, если относимся к кому-то дружественно, а бинты – когда уважаем.', 0);

-- Add ruRU offer rewards for quest 7865
-- Duplicate Text in En locale
SET @ID := 7865;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хорошо $Gзарекомендовал:зарекомендовала; себя, $N, тут сомнений нет! В награду возьми этот пакет! В нем паек и бинты, которые найдешь только в Ущелье Песни Войны.$B$BКогда в Ущелье тебя еще больше зауважают, тебе их тут даже продадут. Паек мы выдаем, если относимся к кому-то дружественно, а бинты – когда уважаем.', 0);

-- Add ruRU offer rewards for quest 7866
-- Duplicate Text in En locale
SET @ID := 7866;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хорошо $Gзарекомендовал:зарекомендовала; себя, $N, тут сомнений нет! В награду возьми этот пакет! В нем паек и бинты, которые найдешь только в Ущелье Песни Войны.$B$BКогда в Ущелье тебя еще больше зауважают, тебе их тут даже продадут. Паек мы выдаем, если относимся к кому-то дружественно, а бинты – когда уважаем.', 0);

-- Add ruRU offer rewards for quest 7867
-- Duplicate Text in En locale
SET @ID := 7867;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хорошо $Gзарекомендовал:зарекомендовала; себя, $N, тут сомнений нет! В награду возьми этот пакет! В нем паек и бинты, которые найдешь только в Ущелье Песни Войны.$B$BКогда в Ущелье тебя еще больше зауважают, тебе их тут даже продадут. Паек мы выдаем, если относимся к кому-то дружественно, а бинты – когда уважаем.', 0);

-- Add ruRU offer rewards for quest 7868
-- Duplicate Text in En locale
SET @ID := 7868;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты хорошо $Gзарекомендовал:зарекомендовала; себя, $N, тут сомнений нет! В награду возьми этот пакет! В нем паек и бинты, которые найдешь только в Ущелье Песни Войны.$B$BКогда в Ущелье тебя еще больше зауважают, тебе их тут даже продадут. Паек мы выдаем, если относимся к кому-то дружественно, а бинты – когда уважаем.', 0);

-- Add ruRU offer rewards for quest 7874
-- https://wowroad.info/?quest=7874
SET @ID := 7874;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Капитан Лободроб одобрительно порыкивает.>$B$BИ сколько еще они смогут так продержаться? Сколько еще солдат Альянса должно погибнуть, чтобы они поняли, что пора отступать? Время покажет, $R, время покажет…', 0);

-- Add ruRU offer rewards for quest 7875
-- Duplicate Text in En locale
SET @ID := 7875;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Капитан Лободроб одобрительно порыкивает.>$B$BИ сколько еще они смогут так продержаться? Сколько еще солдат Альянса должно погибнуть, чтобы они поняли, что пора отступать? Время покажет, $R, время покажет…', 0);

-- Add ruRU offer rewards for quest 7876
-- Duplicate Text in En locale
SET @ID := 7876;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', '<Капитан Лободроб одобрительно порыкивает.>$B$BИ сколько еще они смогут так продержаться? Сколько еще солдат Альянса должно погибнуть, чтобы они поняли, что пора отступать? Время покажет, $R, время покажет…', 0);

-- Add ruRU offer rewards for quest 7886
-- https://wowroad.info/?quest=7886
SET @ID := 7886;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Твои подвиги в Ущелье Песни Войны прозвучат по всему Ясеневому лесу.', 0);

-- Add ruRU offer rewards for quest 7887
-- Duplicate Text in En locale
SET @ID := 7887;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Твои подвиги в Ущелье Песни Войны прозвучат по всему Ясеневому лесу.', 0);

-- Add ruRU offer rewards for quest 7888
-- Duplicate Text in En locale
SET @ID := 7888;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо, $N. Твои подвиги в Ущелье Песни Войны прозвучат по всему Ясеневому лесу.', 0);

-- Add ruRU offer rewards for quest 7891
-- https://wowroad.info/?quest=7891
SET @ID := 7891;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо большое, $N. Вот твой купон!', 0);

-- Add ruRU offer rewards for quest 7892
-- Duplicate Text in En locale
SET @ID := 7892;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо большое, $N. Вот твой купон!', 0);

-- Add ruRU offer rewards for quest 7893
-- Duplicate Text in En locale
SET @ID := 7893;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо большое, $N. Вот твой купон!', 0);

-- Add ruRU offer rewards for quest 7922
-- https://wowroad.info/?quest=7922
SET @ID := 7922;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ночные эльфы и их союзники должны дрожать даже при шепоте твоего имени! За Орду!', 0);

-- Add ruRU offer rewards for quest 7923
-- Duplicate Text in En locale
SET @ID := 7923;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ночные эльфы и их союзники должны дрожать даже при шепоте твоего имени! За Орду!', 0);

-- Add ruRU offer rewards for quest 7924
-- Duplicate Text in En locale
SET @ID := 7924;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ночные эльфы и их союзники должны дрожать даже при шепоте твоего имени! За Орду!', 0);

-- Add ruRU offer rewards for quest 7925
-- Duplicate Text in En locale
SET @ID := 7925;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ночные эльфы и их союзники должны дрожать даже при шепоте твоего имени! За Орду!', 0);

-- Add ruRU offer rewards for quest 7930
-- https://ru.tbc.wowhead.com/quest=7930/5-купонов-цветок-новолуния
SET @ID := 7930;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7931
-- Duplicate Text in En locale
SET @ID := 7931;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7932
-- Duplicate Text in En locale
SET @ID := 7932;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7933
-- Duplicate Text in En locale
SET @ID := 7933;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7934
-- Duplicate Text in En locale
SET @ID := 7934;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7935
-- Duplicate Text in En locale
SET @ID := 7935;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7936
-- Duplicate Text in En locale
SET @ID := 7936;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7940
-- Duplicate Text in En locale
SET @ID := 7940;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 7981
-- Duplicate Text in En locale
SET @ID := 7981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Не зевай, забирай! Приз, достойный короля! Поздравляю с приобретением!$B$BЕсли у тебя еще появятся купоны – приходи, призов у меня целый воз и маленькая тележка!', 0);

-- Add ruRU offer rewards for quest 8154
-- https://wowroad.info/?quest=8154
SET @ID := 8154;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'У тебя есть ресурсы! Прекрасная работа! Я пошлю их нашим интендантам, которые могут быстро разогнать их по нашим войскам.$B$BСпасибо, $N. Действительно, успешное выполнение миссий, подобных той, которую ты $Gвыполнил:выполнила;, - вот как действительно выигрывают войны.', 0);

-- Add ruRU offer rewards for quest 8155
-- Duplicate Text in En locale
SET @ID := 8155;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'У тебя есть ресурсы! Прекрасная работа! Я пошлю их нашим интендантам, которые могут быстро разогнать их по нашим войскам.$B$BСпасибо, $N. Действительно, успешное выполнение миссий, подобных той, которую ты $Gвыполнил:выполнила;, - вот как действительно выигрывают войны.', 0);

-- Add ruRU offer rewards for quest 8156
-- Duplicate Text in En locale
SET @ID := 8156;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'У тебя есть ресурсы! Прекрасная работа! Я пошлю их нашим интендантам, которые могут быстро разогнать их по нашим войскам.$B$BСпасибо, $N. Действительно, успешное выполнение миссий, подобных той, которую ты $Gвыполнил:выполнила;, - вот как действительно выигрывают войны.', 0);

-- Add ruRU offer rewards for quest 8157
-- https://wowroad.info/?quest=8157
SET @ID := 8157;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как целитель, так и фельдмаршал.', 0);

-- Add ruRU offer rewards for quest 8158
-- Duplicate Text in En locale
SET @ID := 8158;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как целитель, так и фельдмаршал.', 0);

-- Add ruRU offer rewards for quest 8159
-- Duplicate Text in En locale
SET @ID := 8159;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как целитель, так и фельдмаршал.', 0);

-- Add ruRU offer rewards for quest 8124
-- https://wowroad.info/?quest=8124
SET @ID := 8124;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как ворчун, так и верховный полководец.', 0);

-- Add ruRU offer rewards for quest 8163
-- Duplicate Text in En locale
SET @ID := 8163;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как ворчун, так и верховный полководец.', 0);

-- Add ruRU offer rewards for quest 8164
-- Duplicate Text in En locale
SET @ID := 8164;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как ворчун, так и верховный полководец.', 0);

-- Add ruRU offer rewards for quest 8165
-- Duplicate Text in En locale
SET @ID := 8165;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Очень хорошо. Я немедленно передам их нашим интендантам.$B$BЕще раз спасибо, $N. Твой вклад в нашу борьбу заметят как ворчун, так и верховный полководец.', 0);

-- Add ruRU offer rewards for quest 8166
-- https://wowroad.info/?quest=8166
SET @ID := 8166;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я получил сообщения о ваших подвигах в Низине Арати, $N. Отлично сработано! С теми, кто, как вы, присоединяется к борьбе здесь, я верю,что однажды мы вернем наши родные земли.', 0);

-- Add ruRU offer rewards for quest 8167
-- Duplicate Text in En locale
SET @ID := 8167;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я получил сообщения о ваших подвигах в Низине Арати, $N. Отлично сработано! С теми, кто, как вы, присоединяется к борьбе здесь, я верю,что однажды мы вернем наши родные земли.', 0);

-- Add ruRU offer rewards for quest 8168
-- Duplicate Text in En locale
SET @ID := 8168;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я получил сообщения о ваших подвигах в Низине Арати, $N. Отлично сработано! С теми, кто, как вы, присоединяется к борьбе здесь, я верю,что однажды мы вернем наши родные земли.', 0);

-- Add ruRU offer rewards for quest 8184
-- https://ru.tbc.wowhead.com/quest=8184/явление-силы
SET @ID := 8184;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8185
-- Duplicate Text in En locale
SET @ID := 8185;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8186
-- Duplicate Text in En locale
SET @ID := 8186;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8187
-- Duplicate Text in En locale
SET @ID := 8187;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8188
-- Duplicate Text in En locale
SET @ID := 8188;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8189
-- Duplicate Text in En locale
SET @ID := 8189;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8190
-- Duplicate Text in En locale
SET @ID := 8190;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8191
-- Duplicate Text in En locale
SET @ID := 8191;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8192
-- Duplicate Text in En locale
SET @ID := 8192;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Используй подарок с умом, |3-6($C). Не давай спуску приспешникам Хаккара!', 0);

-- Add ruRU offer rewards for quest 8195
-- https://ru.tbc.wowhead.com/quest=8195/монеты-племен-зулиан-раззаши-и-хаккари
SET @ID := 8195;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – эти монеты прекрасно дополнят в мою коллекцию... Они нужны племени, чтобы помешать возрождению Кровавого бога. Этот почетный знак – твой по праву, $N, прими его вместе с нашей благодарностью!', 0);

-- Add ruRU offer rewards for quest 8238
-- Duplicate Text in En locale
SET @ID := 8238;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – эти монеты прекрасно дополнят в мою коллекцию... Они нужны племени, чтобы помешать возрождению Кровавого бога. Этот почетный знак – твой по праву, $N, прими его вместе с нашей благодарностью!', 0);

-- Add ruRU offer rewards for quest 8239
-- Duplicate Text in En locale
SET @ID := 8239;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – эти монеты прекрасно дополнят в мою коллекцию... Они нужны племени, чтобы помешать возрождению Кровавого бога. Этот почетный знак – твой по праву, $N, прими его вместе с нашей благодарностью!', 0);

-- Add ruRU offer rewards for quest 8241
-- https://ru.tbc.wowhead.com/quest=8241/пополнить-запасы-огненного-плавня-с-помощью-железа
SET @ID := 8241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Плавень в кузне лишним не бывает, поверь моему слову... Неси сколько можешь, пока не скажу – хватит.', 0);

-- Add ruRU offer rewards for quest 8242
-- Duplicate Text in En locale
SET @ID := 8242;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Плавень в кузне лишним не бывает, поверь моему слову... Неси сколько можешь, пока не скажу – хватит.', 0);

-- Add ruRU offer rewards for quest 8260
-- https://wowroad.info/?quest=8260
SET @ID := 8260;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты определенно $Gначал:начала; показывать нам себя, $N. В награду возьмите эту амуницию! Внутри вы найдете пайки и бинты, которые можно использовать только в Низине Арати.По мере того, как вы продолжаете проявлять себя в Низине, вы обнаружите, что эти предметы станут доступны вам для покупки. Пайки становятся доступными, когда вы дружите с нами, и бинты, когда вас уважают.', 0);

-- Add ruRU offer rewards for quest 8261
-- Duplicate Text in En locale
SET @ID := 8261;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты определенно $Gначал:начала; показывать нам себя, $N. В награду возьмите эту амуницию! Внутри вы найдете пайки и бинты, которые можно использовать только в Низине Арати.По мере того, как вы продолжаете проявлять себя в Низине, вы обнаружите, что эти предметы станут доступны вам для покупки. Пайки становятся доступными, когда вы дружите с нами, и бинты, когда вас уважают.', 0);

-- Add ruRU offer rewards for quest 8262
-- Duplicate Text in En locale
SET @ID := 8262;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты определенно $Gначал:начала; показывать нам себя, $N. В награду возьмите эту амуницию! Внутри вы найдете пайки и бинты, которые можно использовать только в Низине Арати.По мере того, как вы продолжаете проявлять себя в Низине, вы обнаружите, что эти предметы станут доступны вам для покупки. Пайки становятся доступными, когда вы дружите с нами, и бинты, когда вас уважают.', 0);

-- Add ruRU offer rewards for quest 8263
-- https://wowroad.info/?quest=8263
SET @ID := 8263;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В награду возьми это! Внутри ты найдешь пайки и бинты, которые можно использовать только в Низине Арати.$B$BПо мере того, как ты продолжишь проявлять себя в Низине, ты обнаружишь, что эти предметы станут доступны тебе к покупке. Пайки станут доступными, когда ты заслужишь уважение, и бинты, когда заслужишь почтение.', 0);

-- Add ruRU offer rewards for quest 8264
-- Duplicate Text in En locale
SET @ID := 8264;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В награду возьми это! Внутри ты найдешь пайки и бинты, которые можно использовать только в Низине Арати.$B$BПо мере того, как ты продолжишь проявлять себя в Низине, ты обнаружишь, что эти предметы станут доступны тебе к покупке. Пайки станут доступными, когда ты заслужишь уважение, и бинты, когда заслужишь почтение.', 0);

-- Add ruRU offer rewards for quest 8265
-- Duplicate Text in En locale
SET @ID := 8265;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В награду возьми это! Внутри ты найдешь пайки и бинты, которые можно использовать только в Низине Арати.$B$BПо мере того, как ты продолжишь проявлять себя в Низине, ты обнаружишь, что эти предметы станут доступны тебе к покупке. Пайки станут доступными, когда ты заслужишь уважение, и бинты, когда заслужишь почтение.', 0);

-- Add ruRU offer rewards for quest 8266
-- https://wowroad.info/?quest=8266
SET @ID := 8266;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ж, ты не $Gсбежал:сбежала; перед лицом поражения. Ты $Gстоял:стояла; на своем, $N, и именно это делает тебя настоящим героем. Без сомнения, в следующий раз ты выиграешь ... но тем не менее мы благодарим тебя за твои старания.', 0);

-- Add ruRU offer rewards for quest 8267
-- Duplicate Text in En locale
SET @ID := 8267;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ж, ты не $Gсбежал:сбежала; перед лицом поражения. Ты $Gстоял:стояла; на своем, $N, и именно это делает тебя настоящим героем. Без сомнения, в следующий раз ты выиграешь ... но тем не менее мы благодарим тебя за твои старания.', 0);

-- Add ruRU offer rewards for quest 8268
-- Duplicate Text in En locale
SET @ID := 8268;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ж, ты не $Gсбежал:сбежала; перед лицом поражения. Ты $Gстоял:стояла; на своем, $N, и именно это делает тебя настоящим героем. Без сомнения, в следующий раз ты выиграешь ... но тем не менее мы благодарим тебя за твои старания.', 0);

-- Add ruRU offer rewards for quest 8269
-- Duplicate Text in En locale
SET @ID := 8269;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что ж, ты не $Gсбежал:сбежала; перед лицом поражения. Ты $Gстоял:стояла; на своем, $N, и именно это делает тебя настоящим героем. Без сомнения, в следующий раз ты выиграешь ... но тем не менее мы благодарим тебя за твои старания.', 0);

-- Add ruRU offer rewards for quest 8369
-- https://ru.tbc.wowhead.com/quest=8369/вторжение-в-альтеракскую-долину
SET @ID := 8369;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gвстал:встала; на защиту наших земель с невиданной храбостью! Я непременно расскажу командующим о твоих подвигах.', 0);

-- Add ruRU offer rewards for quest 8375
-- Duplicate Text in En locale
SET @ID := 8375;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gвстал:встала; на защиту наших земель с невиданной храбостью! Я непременно расскажу командующим о твоих подвигах.', 0);

-- Add ruRU offer rewards for quest 8376
-- https://ru.tbc.wowhead.com/quest=8376/оружие-войны
SET @ID := 8376;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8377
-- Duplicate Text in En locale
SET @ID := 8377;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8378
-- Duplicate Text in En locale
SET @ID := 8378;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8379
-- Duplicate Text in En locale
SET @ID := 8379;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8380
-- Duplicate Text in En locale
SET @ID := 8380;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8381
-- Duplicate Text in En locale
SET @ID := 8381;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8382
-- Duplicate Text in En locale
SET @ID := 8382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Грядет война, а вместе с ней невиданные ужасы. Ты $Gсделал:сделала; все, что $Gмог:могла;, и $Gдолжен:должна; получить награду.$B$BЕсли это... пророчество сбудется…$B$B<Геолог Ехидная бледнеет.>$B$BМожно считать, что у нас нет будущего.$B$BЭто оружие понадобится тебе на войне в пустыне.', 0);

-- Add ruRU offer rewards for quest 8368
-- https://ru.tbc.wowhead.com/quest=8368/битва-за-ущелье-песни-войны
SET @ID := 8368;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8386
-- Duplicate Text in En locale
SET @ID := 8386;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8389
-- Duplicate Text in En locale
SET @ID := 8389;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8426
-- Duplicate Text in En locale
SET @ID := 8426;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8427
-- Duplicate Text in En locale
SET @ID := 8427;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8428
-- Duplicate Text in En locale
SET @ID := 8428;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8429
-- Duplicate Text in En locale
SET @ID := 8429;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8430
-- Duplicate Text in En locale
SET @ID := 8430;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8431
-- Duplicate Text in En locale
SET @ID := 8431;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8432
-- Duplicate Text in En locale
SET @ID := 8432;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8433
-- Duplicate Text in En locale
SET @ID := 8433;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8434
-- Duplicate Text in En locale
SET @ID := 8434;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);

-- Add ruRU offer rewards for quest 8435
-- Duplicate Text in En locale
SET @ID := 8435;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Ты $Gпоказал:показала;, чего стоишь, выступив против врага в Ущелье Песни Войны! Да разнесутся вести о твоих подвигах по всем нашим землям.', 0);
