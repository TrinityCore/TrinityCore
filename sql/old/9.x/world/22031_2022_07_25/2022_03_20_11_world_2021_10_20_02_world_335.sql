-- Add ruRU offer rewards for quest 8535
-- https://ru.tbc.wowhead.com/quest=8535/седой-храмовник
SET @ID := 8535;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Вот следующее задание.', 0);

-- Add ruRU offer rewards for quest 8536
-- Duplicate text in En locale
SET @ID := 8536;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Вот следующее задание.', 0);

-- Add ruRU offer rewards for quest 8537
-- Duplicate text in En locale
SET @ID := 8537;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Вот следующее задание.', 0);

-- Add ruRU offer rewards for quest 8540
-- https://ru.tbc.wowhead.com/quest=8540/сапоги-для-стражей
SET @ID := 8540;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Как раз то, что нужно. Спасибо.', 0);

-- Add ruRU offer rewards for quest 8541
-- Duplicate text in En locale
SET @ID := 8541;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Как раз то, что нужно. Спасибо.', 0);

-- Add ruRU offer rewards for quest 8548
-- https://wowroad.info/?quest=8548
SET @ID := 8548;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Те знаки, которые достались тебе во время выполнения боевых, тыловых и тактических заданий в Крепости Кенария, нужны не для красоты, $N.$B$BНе теряй их. Когда ты докажешь свою верность нашей организации, я смогу предложить тебе кое-какое снаряжение, которое мы храним для ближайших сподвижников, в обмен на эти знаки.', 0);

-- Add ruRU offer rewards for quest 8572
-- Duplicate text in En locale
SET @ID := 8572;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Те знаки, которые достались тебе во время выполнения боевых, тыловых и тактических заданий в Крепости Кенария, нужны не для красоты, $N.$B$BНе теряй их. Когда ты докажешь свою верность нашей организации, я смогу предложить тебе кое-какое снаряжение, которое мы храним для ближайших сподвижников, в обмен на эти знаки.', 0);

-- Add ruRU offer rewards for quest 8573
-- Duplicate text in En locale
SET @ID := 8573;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Те знаки, которые достались тебе во время выполнения боевых, тыловых и тактических заданий в Крепости Кенария, нужны не для красоты, $N.$B$BНе теряй их. Когда ты докажешь свою верность нашей организации, я смогу предложить тебе кое-какое снаряжение, которое мы храним для ближайших сподвижников, в обмен на эти знаки.', 0);

-- Add ruRU offer rewards for quest 8574
-- Duplicate text in En locale
SET @ID := 8574;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Те знаки, которые достались тебе во время выполнения боевых, тыловых и тактических заданий в Крепости Кенария, нужны не для красоты, $N.$B$BНе теряй их. Когда ты докажешь свою верность нашей организации, я смогу предложить тебе кое-какое снаряжение, которое мы храним для ближайших сподвижников, в обмен на эти знаки.', 0);

-- Add ruRU offer rewards for quest 8544
-- https://ru.tbc.wowhead.com/quest=8544/наплеч-завоевателя
SET @ID := 8544;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8594
-- Duplicate text in En locale
SET @ID := 8594;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8602
-- Duplicate text in En locale
SET @ID := 8602;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8628
-- Duplicate text in En locale
SET @ID := 8628;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8630
-- Duplicate text in En locale
SET @ID := 8630;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8641
-- Duplicate text in En locale
SET @ID := 8641;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8659
-- Duplicate text in En locale
SET @ID := 8659;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8664
-- Duplicate text in En locale
SET @ID := 8664;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8669
-- Duplicate text in En locale
SET @ID := 8669;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я изготовил это наплечье, $Gсмертный:смертная;, из принесенных тобой вещей и панцирей поверженных киражей. Тебя они защитят, а сердца врагов их вид наполнит ужасом.', 0);

-- Add ruRU offer rewards for quest 8611
-- https://ru.tbc.wowhead.com/quest=8611/орде-не-хватает-постных-стейков-из-волчатины
SET @ID := 8611;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, это мясо неплохо выглядит. Сейчас я его засолю и уберу на хранение. Надеюсь, до войны оно доживет свежим.$B$BСпасибо за вклад в наше общее дело, |3-6($C). А пока – как насчет того, чтобы принести мне еще порцию стейков?', 0);

-- Add ruRU offer rewards for quest 8613
-- Duplicate text in En locale
SET @ID := 8613;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, это мясо неплохо выглядит. Сейчас я его засолю и уберу на хранение. Надеюсь, до войны оно доживет свежим.$B$BСпасибо за вклад в наше общее дело, |3-6($C). А пока – как насчет того, чтобы принести мне еще порцию стейков?', 0);

-- Add ruRU offer rewards for quest 8615
-- Duplicate text in En locale
SET @ID := 8615;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О, это мясо неплохо выглядит. Сейчас я его засолю и уберу на хранение. Надеюсь, до войны оно доживет свежим.$B$BСпасибо за вклад в наше общее дело, |3-6($C). А пока – как насчет того, чтобы принести мне еще порцию стейков?', 0);

-- Add ruRU offer rewards for quest 8559
-- https://wowroad.info/?quest=8559
SET @ID := 8559;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8596
-- Duplicate text in En locale
SET @ID := 8596;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8626
-- Duplicate text in En locale
SET @ID := 8626;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8634
-- Duplicate text in En locale
SET @ID := 8634;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8637
-- Duplicate text in En locale
SET @ID := 8637;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8655
-- Duplicate text in En locale
SET @ID := 8655;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8660
-- Duplicate text in En locale
SET @ID := 8660;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8665
-- Duplicate text in En locale
SET @ID := 8665;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Ты $Gдоказал:доказала; что ты не $Gпростой:простая; $Gсмертный:смертная;.$B$BВозьми это, они помогут тебя в сражении против этих мерзких Киражей.', 0);

-- Add ruRU offer rewards for quest 8562
-- https://wowroad.info/?quest=8562
SET @ID := 8562;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не ожидала, что ты сумеешь вернуться $Gживым:живой; $N.$B$BТебе удалось исполнить то, что не под силу многим бессмертным.$B$BУбив К\'Туна, ты не только $Gспас:спасла; Азерот, ты $Gпоколоебал:поколебала; чаши космических весов, на которых лежат события, далеко превосходящие твое понимание.$B$BПрими эти одежды как символ великой славы и знак великого груза, который ты $Gвзвалил:взвалила; на себя своим поступком.$B$BБыть может, они помогут преодолеть тяготы пути, который отныне лежит перед тобой, богоубийца.', 0);

-- Add ruRU offer rewards for quest 8627
-- Duplicate text in En locale
SET @ID := 8627;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не ожидала, что ты сумеешь вернуться $Gживым:живой; $N.$B$BТебе удалось исполнить то, что не под силу многим бессмертным.$B$BУбив К\'Туна, ты не только $Gспас:спасла; Азерот, ты $Gпоколоебал:поколебала; чаши космических весов, на которых лежат события, далеко превосходящие твое понимание.$B$BПрими эти одежды как символ великой славы и знак великого груза, который ты $Gвзвалил:взвалила; на себя своим поступком.$B$BБыть может, они помогут преодолеть тяготы пути, который отныне лежит перед тобой, богоубийца.', 0);

-- Add ruRU offer rewards for quest 8638
-- Duplicate text in En locale
SET @ID := 8638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не ожидала, что ты сумеешь вернуться $Gживым:живой; $N.$B$BТебе удалось исполнить то, что не под силу многим бессмертным.$B$BУбив К\'Туна, ты не только $Gспас:спасла; Азерот, ты $Gпоколоебал:поколебала; чаши космических весов, на которых лежат события, далеко превосходящие твое понимание.$B$BПрими эти одежды как символ великой славы и знак великого груза, который ты $Gвзвалил:взвалила; на себя своим поступком.$B$BБыть может, они помогут преодолеть тяготы пути, который отныне лежит перед тобой, богоубийца.', 0);

-- Add ruRU offer rewards for quest 8656
-- Duplicate text in En locale
SET @ID := 8656;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не ожидала, что ты сумеешь вернуться $Gживым:живой; $N.$B$BТебе удалось исполнить то, что не под силу многим бессмертным.$B$BУбив К\'Туна, ты не только $Gспас:спасла; Азерот, ты $Gпоколоебал:поколебала; чаши космических весов, на которых лежат события, далеко превосходящие твое понимание.$B$BПрими эти одежды как символ великой славы и знак великого груза, который ты $Gвзвалил:взвалила; на себя своим поступком.$B$BБыть может, они помогут преодолеть тяготы пути, который отныне лежит перед тобой, богоубийца.', 0);

-- Add ruRU offer rewards for quest 8666
-- Duplicate text in En locale
SET @ID := 8666;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я не ожидала, что ты сумеешь вернуться $Gживым:живой; $N.$B$BТебе удалось исполнить то, что не под силу многим бессмертным.$B$BУбив К\'Туна, ты не только $Gспас:спасла; Азерот, ты $Gпоколоебал:поколебала; чаши космических весов, на которых лежат события, далеко превосходящие твое понимание.$B$BПрими эти одежды как символ великой славы и знак великого груза, который ты $Gвзвалил:взвалила; на себя своим поступком.$B$BБыть может, они помогут преодолеть тяготы пути, который отныне лежит перед тобой, богоубийца.', 0);

-- Add ruRU offer rewards for quest 8561
-- https://wowroad.info/?quest=8561
SET @ID := 8561;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8592
-- Duplicate text in En locale
SET @ID := 8592;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8632
-- Duplicate text in En locale
SET @ID := 8632;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8639
-- Duplicate text in En locale
SET @ID := 8639;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8657
-- Duplicate text in En locale
SET @ID := 8657;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8662
-- Duplicate text in En locale
SET @ID := 8662;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8667
-- Duplicate text in En locale
SET @ID := 8667;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось одержать победу! Императоры-близнецы прекратили шептаться в моей голове.$B$BПрими же от меня награду. Один вид этой вещи вселит ужас в сердца киражи... Она напомнит им, что самые могучие их предводители погибли от рук смертных.', 0);

-- Add ruRU offer rewards for quest 8629
-- https://wowroad.info/?quest=8629
SET @ID := 8629;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да... Эту шкуру невозможно пробить почти ничем. Если добавить самые прочные куски панцирей киражи, убитых нами по дороге сюда, из нее получится великолепный доспех. Пусть он защитит тебя при встрече с невообразимыми ужасами, что ожидают внутри Ан\'Киража.', 0);

-- Add ruRU offer rewards for quest 8663
-- Duplicate text in En locale
SET @ID := 8663;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да... Эту шкуру невозможно пробить почти ничем. Если добавить самые прочные куски панцирей киражи, убитых нами по дороге сюда, из нее получится великолепный доспех. Пусть он защитит тебя при встрече с невообразимыми ужасами, что ожидают внутри Ан\'Киража.', 0);

-- Add ruRU offer rewards for quest 8668
-- Duplicate text in En locale
SET @ID := 8668;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да... Эту шкуру невозможно пробить почти ничем. Если добавить самые прочные куски панцирей киражи, убитых нами по дороге сюда, из нее получится великолепный доспех. Пусть он защитит тебя при встрече с невообразимыми ужасами, что ожидают внутри Ан\'Киража.', 0);

-- Add ruRU offer rewards for quest 8689
-- https://ru.tbc.wowhead.com/quest=8689/накидка-бесконечной-мудрости
SET @ID := 8689;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8690
-- Duplicate text in En locale
SET @ID := 8690;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8691
-- Duplicate text in En locale
SET @ID := 8691;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8692
-- Duplicate text in En locale
SET @ID := 8692;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8693
-- Duplicate text in En locale
SET @ID := 8693;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8694
-- Duplicate text in En locale
SET @ID := 8694;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8695
-- Duplicate text in En locale
SET @ID := 8695;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8696
-- Duplicate text in En locale
SET @ID := 8696;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да... Эта пелерина безукоризненна.$B$BВозьми ее, $N. Пусть она защитит тебя от нечистой магии кираи.', 0);

-- Add ruRU offer rewards for quest 8697
-- https://ru.tbc.wowhead.com/quest=8697/кольцо-бесконечной-мудрости
SET @ID := 8697;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8698
-- Duplicate text in En locale
SET @ID := 8698;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8699
-- Duplicate text in En locale
SET @ID := 8699;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8700
-- Duplicate text in En locale
SET @ID := 8700;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8701
-- Duplicate text in En locale
SET @ID := 8701;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8702
-- Duplicate text in En locale
SET @ID := 8702;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8703
-- Duplicate text in En locale
SET @ID := 8703;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8704
-- Duplicate text in En locale
SET @ID := 8704;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я заменю камень в этом кольце. Увидишь, это сделает его эффективность куда более... приемлемой.', 0);

-- Add ruRU offer rewards for quest 8705
-- https://ru.tbc.wowhead.com/quest=8705/чекан-беспредельной-мудрости
SET @ID := 8705;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8706
-- Duplicate text in En locale
SET @ID := 8706;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8707
-- Duplicate text in En locale
SET @ID := 8707;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8708
-- Duplicate text in En locale
SET @ID := 8708;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8709
-- Duplicate text in En locale
SET @ID := 8709;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8710
-- Duplicate text in En locale
SET @ID := 8710;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8711
-- Duplicate text in En locale
SET @ID := 8711;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8712
-- Duplicate text in En locale
SET @ID := 8712;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты славно $Gпотрудился:потрудилась;, |3-6($C). Эта рукоять отлично сработана... Как в руке лежит!$B$BПрими это оружие, $N. Пусть оно поможет тебе сокрушить наших врагов!', 0);

-- Add ruRU offer rewards for quest 8688
-- https://ru.tbc.wowhead.com/quest=8688/старейшина-бегун-ветра
SET @ID := 8688;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В небесах, в бессчетных созвездиях, записана разгадка всех наших земных тайн. Смогут ли мудрые – и удачливые – обратить взор к небесной тверди и узнать правду?', 0);

-- Add ruRU offer rewards for quest 8714
-- Duplicate text in En locale
SET @ID := 8714;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В небесах, в бессчетных созвездиях, записана разгадка всех наших земных тайн. Смогут ли мудрые – и удачливые – обратить взор к небесной тверди и узнать правду?', 0);

-- Add ruRU offer rewards for quest 8719
-- Duplicate text in En locale
SET @ID := 8719;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В небесах, в бессчетных созвездиях, записана разгадка всех наших земных тайн. Смогут ли мудрые – и удачливые – обратить взор к небесной тверди и узнать правду?', 0);

-- Add ruRU offer rewards for quest 8722
-- Duplicate text in En locale
SET @ID := 8722;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В небесах, в бессчетных созвездиях, записана разгадка всех наших земных тайн. Смогут ли мудрые – и удачливые – обратить взор к небесной тверди и узнать правду?', 0);

-- Add ruRU offer rewards for quest 8738
-- https://ru.tbc.wowhead.com/quest=8738/донесение-разведчика-из-улья-регал
SET @ID := 8738;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мы очень ценим твои усилия, $N. Я немедленно займусь этими донесениями, а ты можешь переходить к следующему заданию.', 0);

-- Add ruRU offer rewards for quest 8739
-- Duplicate text in En locale
SET @ID := 8739;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мы очень ценим твои усилия, $N. Я немедленно займусь этими донесениями, а ты можешь переходить к следующему заданию.', 0);

-- Add ruRU offer rewards for quest 8748
-- https://wowroad.info/?quest=8748
SET @ID := 8748;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Да не сворачивай ты с пути защитника!', 0);

-- Add ruRU offer rewards for quest 8749
-- Duplicate text in En locale
SET @ID := 8749;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Да не сворачивай ты с пути защитника!', 0);

-- Add ruRU offer rewards for quest 8750
-- Duplicate text in En locale
SET @ID := 8750;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Да не сворачивай ты с пути защитника!', 0);


-- Add ruRU offer rewards for quest 8753
-- https://wowroad.info/?quest=8753
SET @ID := 8753;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Да не сворачивай ты с пути победителя!', 0);

-- Add ruRU offer rewards for quest 8754
-- Duplicate text in En locale
SET @ID := 8754;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Да не сворачивай ты с пути победителя!', 0);

-- Add ruRU offer rewards for quest 8755
-- Duplicate text in En locale
SET @ID := 8755;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Да не сворачивай ты с пути победителя!', 0);

-- Add ruRU offer rewards for quest 8758
-- https://wowroad.info/?quest=8758
SET @ID := 8758;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Пусть ты никогда не отклонишься с пути заклинателя!', 0);

-- Add ruRU offer rewards for quest 8759
-- Duplicate text in En locale
SET @ID := 8759;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Пусть ты никогда не отклонишься с пути заклинателя!', 0);

-- Add ruRU offer rewards for quest 8760
-- Duplicate text in En locale
SET @ID := 8760;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое восхождение в ранг стаи впечатляет, $N. Пусть ты никогда не отклонишься с пути заклинателя!', 0);

-- Add ruRU offer rewards for quest 8764
-- https://wowroad.info/?quest=8764
SET @ID := 8764;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Будь $Gздоров:здорова;, $N. Если вы передумаете, я буду здесь, чтобы помочь вам.', 0);

-- Add ruRU offer rewards for quest 8765
-- Duplicate text in En locale
SET @ID := 8765;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Будь $Gздоров:здорова;, $N. Если вы передумаете, я буду здесь, чтобы помочь вам.', 0);

-- Add ruRU offer rewards for quest 8766
-- Duplicate text in En locale
SET @ID := 8766;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Будь $Gздоров:здорова;, $N. Если вы передумаете, я буду здесь, чтобы помочь вам.', 0);

-- Add ruRU offer rewards for quest 8774
-- https://wowroad.info/?quest=8774
SET @ID := 8774;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Твои подвиги в сражении при Улье Регал не прошли незамеченными.', 0);

-- Add ruRU offer rewards for quest 8775
-- Duplicate text in En locale
SET @ID := 8775;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Твои подвиги в сражении при Улье Регал не прошли незамеченными.', 0);

-- Add ruRU offer rewards for quest 8776
-- Duplicate text in En locale
SET @ID := 8776;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Твои подвиги в сражении при Улье Регал не прошли незамеченными.', 0);

-- Add ruRU offer rewards for quest 8777
-- Duplicate text in En locale
SET @ID := 8777;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа, $N. Твои подвиги в сражении при Улье Регал не прошли незамеченными.', 0);

-- Add ruRU offer rewards for quest 8792
-- https://wowroad.info/?quest=8792
SET @ID := 8792;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тромька, $C! Приятно видеть, что так много представителей Орды,как ты,$N, выступают, чтобы оказать свою поддержку в предстоящей Ан\'киражской войне. Наши старания гарантируют, что мы победим силитидов и их злых хозяев, скрытых внутри Ан\'Киража.', 0);

-- Add ruRU offer rewards for quest 8793
-- Duplicate text in En locale
SET @ID := 8793;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тромька, $C! Приятно видеть, что так много представителей Орды,как ты,$N, выступают, чтобы оказать свою поддержку в предстоящей Ан\'киражской войне. Наши старания гарантируют, что мы победим силитидов и их злых хозяев, скрытых внутри Ан\'Киража.', 0);

-- Add ruRU offer rewards for quest 8794
-- Duplicate text in En locale
SET @ID := 8794;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тромька, $C! Приятно видеть, что так много представителей Орды,как ты,$N, выступают, чтобы оказать свою поддержку в предстоящей Ан\'киражской войне. Наши старания гарантируют, что мы победим силитидов и их злых хозяев, скрытых внутри Ан\'Киража.', 0);

-- Add ruRU offer rewards for quest 8815
-- https://wowroad.info/?quest=8815
SET @ID := 8815;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8816
-- Duplicate text in En locale
SET @ID := 8816;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8817
-- Duplicate text in En locale
SET @ID := 8817;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8818
-- Duplicate text in En locale
SET @ID := 8818;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8830
-- Duplicate text in En locale
SET @ID := 8830;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8832
-- Duplicate text in En locale
SET @ID := 8832;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8834
-- Duplicate text in En locale
SET @ID := 8834;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8836
-- Duplicate text in En locale
SET @ID := 8836;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8838
-- Duplicate text in En locale
SET @ID := 8838;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8840
-- Duplicate text in En locale
SET @ID := 8840;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8842
-- Duplicate text in En locale
SET @ID := 8842;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8844
-- Duplicate text in En locale
SET @ID := 8844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично – твои подвиги записаны, и тебе воздастся по заслугам. Продолжай в том же духе, $C!$B$BЕсли ты хочешь сдать еще несколько жетонов, я с радостью их приму.', 0);

-- Add ruRU offer rewards for quest 8823
-- https://wowroad.info/?quest=8823
SET @ID := 8823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8824
-- Duplicate text in En locale
SET @ID := 8824;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8825
-- Duplicate text in En locale
SET @ID := 8825;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8826
-- Duplicate text in En locale
SET @ID := 8826;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8831
-- Duplicate text in En locale
SET @ID := 8831;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8833
-- Duplicate text in En locale
SET @ID := 8833;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8835
-- Duplicate text in En locale
SET @ID := 8835;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8837
-- Duplicate text in En locale
SET @ID := 8837;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8839
-- Duplicate text in En locale
SET @ID := 8839;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8841
-- Duplicate text in En locale
SET @ID := 8841;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8843
-- Duplicate text in En locale
SET @ID := 8843;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8845
-- Duplicate text in En locale
SET @ID := 8845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично! Чтобы получить такое количество жетонов, тебе пришлось многим пожертвовать, но и награда будет велика. Благодаря таким искателям приключений, как ты, мир меняется к лучшему.$B$BСообщи, если у тебя появятся новые жетоны - я с радостью приму любое количество.', 0);

-- Add ruRU offer rewards for quest 8870
-- https://wowroad.info/?quest=8870
SET @ID := 8870;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать, $N. Ты $Gпришел:пришла;, чтобы праздновать вместе с нами?', 0);

-- Add ruRU offer rewards for quest 8872
-- Duplicate text in En locale
SET @ID := 8872;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать, $N. Ты $Gпришел:пришла;, чтобы праздновать вместе с нами?', 0);

-- Add ruRU offer rewards for quest 8875
-- Duplicate text in En locale
SET @ID := 8875;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Добро пожаловать, $N. Ты $Gпришел:пришла;, чтобы праздновать вместе с нами?', 0);

-- Add ruRU offer rewards for quest 8905
-- https://wowroad.info/?quest=8905
SET @ID := 8905;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8906
-- Duplicate text in En locale
SET @ID := 8906;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8907
-- Duplicate text in En locale
SET @ID := 8907;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8908
-- Duplicate text in En locale
SET @ID := 8908;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8909
-- Duplicate text in En locale
SET @ID := 8909;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8910
-- Duplicate text in En locale
SET @ID := 8910;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8911
-- Duplicate text in En locale
SET @ID := 8911;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8912
-- Duplicate text in En locale
SET @ID := 8912;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно! Так совершим обмен! Жалко расставаться с такими великолепными доспехами, но, боюсь, в ближайшее время они мне не понадобятся.$B$BЕсли ты согласишься выполнить для меня еще кое-какие поручения, то, может, я отдам и остальную часть комплекта.', 0);

-- Add ruRU offer rewards for quest 8913
-- https://wowroad.info/?quest=8913
SET @ID := 8913;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C)! Судя по тому, как ты держишься, тебе немало довелось повидать на белом свете. Но бьюсь об заклад, что таких доспехов, как эти, тебе видеть не доводилось!$B$BОкажи мне небольшую услугу, и я отдам их тебе в обмен на наручи попроще.$B$BМне нужен яд тварей, обитающих в Силитусе. Принеси мне этот яд и немного золотых монет, и я произведу обмен.', 0);

-- Add ruRU offer rewards for quest 8916
-- Duplicate text in En locale
SET @ID := 8916;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C)! Судя по тому, как ты держишься, тебе немало довелось повидать на белом свете. Но бьюсь об заклад, что таких доспехов, как эти, тебе видеть не доводилось!$B$BОкажи мне небольшую услугу, и я отдам их тебе в обмен на наручи попроще.$B$BМне нужен яд тварей, обитающих в Силитусе. Принеси мне этот яд и немного золотых монет, и я произведу обмен.', 0);

-- Add ruRU offer rewards for quest 8917
-- Duplicate text in En locale
SET @ID := 8917;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C)! Судя по тому, как ты держишься, тебе немало довелось повидать на белом свете. Но бьюсь об заклад, что таких доспехов, как эти, тебе видеть не доводилось!$B$BОкажи мне небольшую услугу, и я отдам их тебе в обмен на наручи попроще.$B$BМне нужен яд тварей, обитающих в Силитусе. Принеси мне этот яд и немного золотых монет, и я произведу обмен.', 0);

-- Add ruRU offer rewards for quest 8919
-- Duplicate text in En locale
SET @ID := 8919;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C)! Судя по тому, как ты держишься, тебе немало довелось повидать на белом свете. Но бьюсь об заклад, что таких доспехов, как эти, тебе видеть не доводилось!$B$BОкажи мне небольшую услугу, и я отдам их тебе в обмен на наручи попроще.$B$BМне нужен яд тварей, обитающих в Силитусе. Принеси мне этот яд и немного золотых монет, и я произведу обмен.', 0);

-- Add ruRU offer rewards for quest 8920
-- Duplicate text in En locale
SET @ID := 8920;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Привет тебе, |3-6($C)! Судя по тому, как ты держишься, тебе немало довелось повидать на белом свете. Но бьюсь об заклад, что таких доспехов, как эти, тебе видеть не доводилось!$B$BОкажи мне небольшую услугу, и я отдам их тебе в обмен на наручи попроще.$B$BМне нужен яд тварей, обитающих в Силитусе. Принеси мне этот яд и немного золотых монет, и я произведу обмен.', 0);

-- Add ruRU offer rewards for quest 8926
-- https://wowroad.info/?quest=8926
SET @ID := 8926;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8931
-- Duplicate text in En locale
SET @ID := 8931;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8932
-- Duplicate text in En locale
SET @ID := 8932;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8933
-- Duplicate text in En locale
SET @ID := 8933;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8934
-- Duplicate text in En locale
SET @ID := 8934;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8935
-- Duplicate text in En locale
SET @ID := 8935;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8936
-- Duplicate text in En locale
SET @ID := 8936;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8937
-- Duplicate text in En locale
SET @ID := 8937;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты свою часть сделки $Gвыполнил:выполнила;, я выполню свою.$B$BНо помни: лучшее я придержу до завершения работы. Сладкое – на закуску.', 0);

-- Add ruRU offer rewards for quest 8927
-- https://wowroad.info/?quest=8927
SET @ID := 8927;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8938
-- Duplicate text in En locale
SET @ID := 8938;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8939
-- Duplicate text in En locale
SET @ID := 8939;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8940
-- Duplicate text in En locale
SET @ID := 8940;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8941
-- Duplicate text in En locale
SET @ID := 8941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8942
-- Duplicate text in En locale
SET @ID := 8942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8943
-- Duplicate text in En locale
SET @ID := 8943;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8944
-- Duplicate text in En locale
SET @ID := 8944;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Наше соглашение остается в силе. Просто помните, это лишь вкус того, что вас ждет. Освободи меня от этой проклятой судьбы, и я награду тебя предметами поистине великой силы.', 0);

-- Add ruRU offer rewards for quest 8951
-- https://wowroad.info/?quest=8951
SET @ID := 8951;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8952
-- Duplicate text in En locale
SET @ID := 8952;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8953
-- Duplicate text in En locale
SET @ID := 8953;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8954
-- Duplicate text in En locale
SET @ID := 8954;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8955
-- Duplicate text in En locale
SET @ID := 8955;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8956
-- Duplicate text in En locale
SET @ID := 8956;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8958
-- Duplicate text in En locale
SET @ID := 8958;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8959
-- Duplicate text in En locale
SET @ID := 8959;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Поверить не могу, что наша жизнь висит на волоске из-за какого-то дурацкого медальона! А ты $Gуверен:уверен;, что Антион упомянул Бодли?$B$BЛадно, ты свое дело $Gсделал:сделала;, так что давай закончим и с твоей наградой.', 0);

-- Add ruRU offer rewards for quest 8999
-- https://wowroad.info/?quest=8999
SET @ID := 8999;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9000
-- Duplicate text in En locale
SET @ID := 9000;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9001
-- Duplicate text in En locale
SET @ID := 9001;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9002
-- Duplicate text in En locale
SET @ID := 9002;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9003
-- Duplicate text in En locale
SET @ID := 9003;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9004
-- Duplicate text in En locale
SET @ID := 9004;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9005
-- Duplicate text in En locale
SET @ID := 9005;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9006
-- Duplicate text in En locale
SET @ID := 9006;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи, и что они будут защищать тебя.', 0);

-- Add ruRU offer rewards for quest 9007
-- https://wowroad.info/?quest=9007
SET @ID := 9007;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9008
-- Duplicate text in En locale
SET @ID := 9008;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9009
-- Duplicate text in En locale
SET @ID := 9009;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9010
-- Duplicate text in En locale
SET @ID := 9010;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9011
-- Duplicate text in En locale
SET @ID := 9011;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9012
-- Duplicate text in En locale
SET @ID := 9012;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9013
-- Duplicate text in En locale
SET @ID := 9013;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9014
-- Duplicate text in En locale
SET @ID := 9014;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я буду скучать по тебе, $N. Я в долгу перед тобой,думаю, я никогда не смогу расплатиться за это.$B$BНадеюсь, что тебе понравятся твои новые доспехи и они помогут добиться ещё большей чести!', 0);

-- Add ruRU offer rewards for quest 9016
-- https://wowroad.info/?quest=9016
SET @ID := 9016;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);

-- Add ruRU offer rewards for quest 9017
-- Duplicate text in En locale
SET @ID := 9017;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);

-- Add ruRU offer rewards for quest 9018
-- Duplicate text in En locale
SET @ID := 9018;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);

-- Add ruRU offer rewards for quest 9019
-- Duplicate text in En locale
SET @ID := 9019;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);

-- Add ruRU offer rewards for quest 9020
-- Duplicate text in En locale
SET @ID := 9020;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);

-- Add ruRU offer rewards for quest 9021
-- Duplicate text in En locale
SET @ID := 9021;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);

-- Add ruRU offer rewards for quest 9022
-- Duplicate text in En locale
SET @ID := 9022;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это проклятие было наложено на нас за простой медальон. Лорд Валтхалак определенно знает, как затаить обиду.$B$BМы постараемся найти оставшиеся части - надеюсь, прежде чем я встречу безвременную кончину. Но перед этим давай посмотрим на твою награду.', 0);
