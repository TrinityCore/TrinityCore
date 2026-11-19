-- Add ruRU offer rewards for quest 1201
-- https://ru.tbc.wowhead.com/quest=1201/тераморские-шпионы
SET @ID := 1201;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отличная работа. Их шпионы хитроумны, но недостаточно, чтобы спастить от всевидящих глаз Орды.', 0);

-- Add ruRU offer rewards for quest 1202
-- https://ru.tbc.wowhead.com/quest=1202/доки-терамора
SET @ID := 1202;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Браво, $N. Это было нелегко, но документы, которые ты $Gдобыл:добыла; – весьма ценны.', 0);

-- Add ruRU offer rewards for quest 1203
-- https://ru.tbc.wowhead.com/quest=1203/ярлу-нужен-клинок
SET @ID := 1203;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Это хороший клинок... Он хорошо танцует, – стало быть, это – хороший танцующий клинок! Спасибо-спасибо-спасибо!!! Таак. Теперь я его испробую...$B$BПозже. Я испробую его позже. Но все равно спасибо тебе!', 0);

-- Add ruRU offer rewards for quest 1206
-- https://ru.tbc.wowhead.com/quest=1206/ярлу-нужны-глаза
SET @ID := 1206;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринес:принесла; вкусные глазки... Паучьи глаза чисты как слеза.$B$BИх едят, а они глядят…$B$BВот те, что глядят, съешь последними, а то на болотах-то другой компании и нет.$B$BПривет, глазки мои маленькие, привеет! На вкус лучше курочки, с солью, с приправками...$B$BМмм...', 0);

-- Add ruRU offer rewards for quest 1218
-- https://ru.tbc.wowhead.com/quest=1218/лягушачьи-лапки
SET @ID := 1218;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага, вот и специи. Вот теперь жабятина вполне готова.', 0);

-- Add ruRU offer rewards for quest 1219
-- https://ru.tbc.wowhead.com/quest=1219/орочье-донесение
SET @ID := 1219;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хм... Я не силен в орочьем, но это похоже... на отчет шпиона!', 0);

-- Add ruRU offer rewards for quest 1220
-- https://ru.tbc.wowhead.com/quest=1220/капитан-ваймс
SET @ID := 1220;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Донесение орочьего шпиона! Как тебе удалось его раздобыть? Впрочем, неважно, – давай-ка посмотрим, о чем там говорится...', 0);

-- Add ruRU offer rewards for quest 1222
-- https://ru.tbc.wowhead.com/quest=1222/побег-вонючки
SET @ID := 1222;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мистер Игнац не так давно приносил листья болотного боба, и он расказал мне, что вы помогли ему выбраться из весьма затруднительной ситуации.$B$BБлагодарю вас, $n. Я попрошу своего дядю принять вас по-королевски, когда вы в следующий раз окажетесь в "Синем отшельнике", в Штормграде.', 0);

-- Add ruRU offer rewards for quest 1238
-- https://ru.tbc.wowhead.com/quest=1238/потерянный-рапорт
SET @ID := 1238;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, $N. Наш агент Марг Ночной Соглядатай был отправлен на разведку в Терамор.$B$BЭто его последний рапорт и, видимо, уже окончательно последний – судя по твоим словам, я боюсь, Марг навсегда остался в болотах...', 0);

-- Add ruRU offer rewards for quest 1252
-- https://ru.tbc.wowhead.com/quest=1252/лейтенант-павал-рит
SET @ID := 1252;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'День, когда мне приносят бляхи погибших стражей, светлым не назовешь.$B$BИногда они гибнут в битве, и мне приходится сообщать об их участи семье и близким... Иногда мы так и не знаем, что с ними сталось. А иногда знаем, и это еще хуже...', 0);

-- Add ruRU offer rewards for quest 1253
-- https://ru.tbc.wowhead.com/quest=1253/черный-щит
SET @ID := 1253;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хмм... Я в устройстве оружия и доспехов не разбираюсь, я ими пользуюсь.$B$BЩит как щит, разве что огнем опалило.', 0);

-- Add ruRU offer rewards for quest 1258
-- https://ru.tbc.wowhead.com/quest=1258/и-жуки
SET @ID := 1258;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Прекрасные экземпляры, $N. На самих клешнях ни царапинки, а мясо как и положено, розовое и нежное. У вас несомненный талант к этому делу! Не задумывались о карьере шеф-повара?', 0);

-- Add ruRU offer rewards for quest 1259
-- https://ru.tbc.wowhead.com/quest=1259/лейтенант-павал-рит
SET @ID := 1259;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Здравствуй, $N. Так тебе нужна информация об одном из нас? Как его бишь, Рит?$B$BСейчас проверю по своим записям.', 0);

-- Add ruRU offer rewards for quest 1267
-- https://ru.tbc.wowhead.com/quest=1267/пропавший-дипломат
SET @ID := 1267;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Сначала позвольте вас, $N, поблагодарить за все, что вы уже сделали. Вы оказали неоценимую услугу моим людям и всем обитателям Штормграда. Жаль, что наше знакомство не состоялось при более благоприятных обстоятельствах.$B$BНадеюсь, вы понимаете, что я не имею возможности публично выразить вам свою признательность, но знайте, что она поистине безгранична...$B$BВо время следующего визита в Терамор разыщите меня и я сделаю для вас все, что смогу.$B$B$N, позвольте еще раз поблагодарить вас.', 0);

-- Add ruRU offer rewards for quest 1270
-- https://ru.tbc.wowhead.com/quest=1270/побег-вонючки
SET @ID := 1270;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вонючка недавно приносил тут мне травки, и он расказал, что ты $Gпомог:помогла; ему выпутаться из мерзкой ситуации. Хорошая работа! Друг Вонючки и мой друг.$B$BПеред тем как вернуться обратно на болота, он просил передать тебе это, если мы вдруг увидимся.', 0);

-- Add ruRU offer rewards for quest 1271
-- https://ru.tbc.wowhead.com/quest=1271/праздник-в-голубом-отшельнике
SET @ID := 1271;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мой племянник сказал, что ты $Gпомог:помогла; ему с его поисками в Пыльной трясине, а заодно и вытащил его компаньона из неслабой передряги. Мы, Штерны, держимся друг дружки и не забываем наших друзей!$B$BТак что мой руки, $N, сегодня пируем в твою честь!', 0);

-- Add ruRU offer rewards for quest 1282
-- https://ru.tbc.wowhead.com/quest=1282/зовут-его-улыбка-джим
SET @ID := 1282;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Настоящее его имя – Джеймс Хьяль. Он открыл таверну на краю Степей, хотел сделать уютное местечко для отдыха путешественников.$B$BМожет, он слишком многого хотел, но некоторое время дела в таверне шли хорошо. Потом мы потеряли контроль за дорогами через болота, и здесь стали шататься огры, а Джеймс был слишком упрям, он не захотел бросить свое детище ради безопасности. Теперь таверна "Последний привал" сгорела до основания. Мы пытались разобраться, но особых успехов не достигли, поэтому твою помощь примем с благодарностью. Если хочешь помочь – посмотри, вдруг что найдешь на развалинах.', 0);

-- Add ruRU offer rewards for quest 1284
-- https://ru.tbc.wowhead.com/quest=1284/подозрительные-следы-копыт
SET @ID := 1284;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Следы копыт, говоришь? В последнее время в этих краях зашевелились кентавры. Наши разведчики во время вылазки в Степи заметили несколько их лагерей и поселений.$B$BЯ пошлю одного из наших охотников, Фальграна Гастила, посмотреть, куда ведут эти следы.', 0);

-- Add ruRU offer rewards for quest 1285
-- https://ru.tbc.wowhead.com/quest=1285/солдаты-даэлина
SET @ID := 1285;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Пропал без вести? В переводе с языка Тезорана, это значит – предатель.$B$BНе сомневаюсь, что это один из тех глупцов, слепо преданных адмиралу Даэлину и готовых ради него предать собственную страну. Забавно, правда? Дезертиры обвиняют нас в предательстве дела Альянса.', 0);

-- Add ruRU offer rewards for quest 1286
-- https://ru.tbc.wowhead.com/quest=1286/дезертиры
SET @ID := 1286;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебя Ваймс прислал? Вечно он спихивает на других всю грязную работу...', 0);

-- Add ruRU offer rewards for quest 1301
-- https://ru.tbc.wowhead.com/quest=1301/джеймс-хьяль
SET @ID := 1301;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Джеймс? Так он еще когда уехал отсюда.$B$BВолна патриотизма накрыла, наверное. Можно понять. Многие после всего этого безумия, творящегося в Лордероне, последовали за море за Джайной Праудмур.', 0);

-- Add ruRU offer rewards for quest 1319
-- https://ru.tbc.wowhead.com/quest=1319/черный-щит
SET @ID := 1319;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хмм... Интересная железяка. Это точно не моя работа, и я не знаю ни одного кузнеца по эту сторону моря, из чьих рук она могла бы выйти.', 0);

-- Add ruRU offer rewards for quest 1320
-- https://ru.tbc.wowhead.com/quest=1320/черный-щит
SET @ID := 1320;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Узнать удалось немного, но и это сгодится. Будем надеяться, что вскоре прояснятся остальные части этой головоломки, и мы сможем увидеть полную картину произошедшего.', 0);

-- Add ruRU offer rewards for quest 1367
-- https://ru.tbc.wowhead.com/quest=1367/союз-с-племенем-маграм
SET @ID := 1367;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Кентавры племени Гелкис кричат от ужаса, заслышав твое имя, $N. Они страшатся и ненавидят тебя. Ненавидят так же, как племя Маграм!$B$BМожет, ты и не слабее нас. Может, ты даже $Gдостоин:достойна; того, чтобы мы с тобой говорили. Посмотрим...', 0);

-- Add ruRU offer rewards for quest 1368
-- https://ru.tbc.wowhead.com/quest=1368/союз-с-племенем-гелкис
SET @ID := 1368;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Земля говорит со мной, земля говорит, что ты $Gубил:убила; многих из племени Маграм. Это хорошо.$B$BЕсли хочешь быть другом племени Гелкис, слушай. Я буду говорить с тобой. У меня есть для тебя дело.', 0);

-- Add ruRU offer rewards for quest 1369
-- https://ru.tbc.wowhead.com/quest=1369/россыпи-слез
SET @ID := 1369;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ага! Вот они, Слезы! Теперь племя Гелкис поймет, что Терадрас не защитит их. Она не станет плакать, когда мы сокрушим их! Маграм будут править здесь!$B$BТы хорошо $Gсделал:сделала;, выбрав нашу сторону, $N. Мы – самые сильные.', 0);

-- Add ruRU offer rewards for quest 1370
-- https://ru.tbc.wowhead.com/quest=1370/похищение-припасов
SET @ID := 1370;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хорошо. Я слышу, как урчит в брюхе у голодных Маграм! Слышу это даже здесь!$B$BЯ отдам это мясо племени Гелкис. Мы будем воевать много дней без отдыха.$B$BТо, что ты $Gсделал:сделала;, хорошо для племени Гелкис.', 0);

-- Add ruRU offer rewards for quest 1371
-- https://ru.tbc.wowhead.com/quest=1371/игрушка-для-варуга
SET @ID := 1371;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да! Именно такой человек у меня и был! Он снова будет двигаться. Снова будет веселить меня!', 0);

-- Add ruRU offer rewards for quest 1372
-- https://ru.tbc.wowhead.com/quest=1372/правда-и-только-правда
SET @ID := 1372;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Зредус как раз перед твоим приходом рассказал мне об этом любопытном маленьком лазутчике.$B$BЭто и правда проблема. Нам вовсе не нужен нахал, вынюхивающий, что да как.$B$BУверен, орки Каменора с интересом выслушают его. Поскольку они, хм, наши союзники, мы должны помочь им добыть информацию от этого человека.$B$BПомоги мне, $N, – и мы доставим в Каменор сыворотку правды.$B$BЗа Орду!$B$BЭ-э... я правильно выразился?', 0);

-- Add ruRU offer rewards for quest 1373
-- https://ru.tbc.wowhead.com/quest=1373/онгеку
SET @ID := 1373;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О да, это и есть тот осколок, о котором шептала мне земля... Я ощущаю его магическую силу – ту силу, которую я направлю против врагов племени Гелкис.$B$BТебе удалось исполнить еще одно наше задание, $N. Возможно, со временем племя Гелкис сможет по праву считать тебя другом.', 0);

-- Add ruRU offer rewards for quest 1374
-- https://ru.tbc.wowhead.com/quest=1374/вождь-джен
SET @ID := 1374;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вождь Джехн был силен, но глуп. Он полагал, что наделен великой силой, но забыл, что магия Земли могущественнее любого смертного. Лишившись вождя, племя Маграм впадет в ничтожество, и племя Гелкис восторжествует!', 0);

-- Add ruRU offer rewards for quest 1375
-- https://ru.tbc.wowhead.com/quest=1375/вождь-шак
SET @ID := 1375;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вождь Шак мертв! Я насажу его голову на пику, чтобы любоваться ею каждый день! Пусть мертвые глаза Шака видят мощь племени Маграм!', 0);

-- Add ruRU offer rewards for quest 1380
-- https://ru.tbc.wowhead.com/quest=1380/вождь-храта
SET @ID := 1380;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Он мертв! Вождь Храта мертв! Теперь племя Мародин падет! И когда этой землей станет править племя Гелкис – клянусь, мы не забудем тебя, $N. Духи земли будут вечно славить твое имя!', 0);

-- Add ruRU offer rewards for quest 1381
-- https://ru.tbc.wowhead.com/quest=1381/вождь-храта
SET @ID := 1381;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Вождь Храта мертв! Теперь Маграм – сильнейшее из племен! Мы сокрушим всех! Мы будем править в Пустошах!$B$BМы не забудем тебя, $N, и в тот час, когда сотни будут гибнуть под нашими копытами, мы пощадим тебя.', 0);

-- Add ruRU offer rewards for quest 1382
-- https://ru.tbc.wowhead.com/quest=1382/странный-союз
SET @ID := 1382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'В племени Гелкис говорят о тебе. Твои руки в крови проклятых Маграм. Это хорошо.$B$BЯ буду говорить с тобой. Скажи, что ты можешь сделать для племени Гелкис – и что племя может сделать для тебя.', 0);

-- Add ruRU offer rewards for quest 1383
-- https://ru.tbc.wowhead.com/quest=1383/правда-и-только-правда
SET @ID := 1383;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Великолепно, $N! И как раз вовремя. Судя по тому, что говорит Зредус, лазутчик оправился от ран и готов к допросу.$B$BПогоди, сейчас я приготовлю отра... то есть сыворотку правды.', 0);

-- Add ruRU offer rewards for quest 1384
-- https://ru.tbc.wowhead.com/quest=1384/набег-на-племя-колкар
SET @ID := 1384;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gсделал:сделала; доброе дело для племени Гелкис. Клан Колкар слаб, он обречен и сгинет. Их жалкая магия не поможет им. Ты $Gпоказал:показала; им это – и страх сделает их еще слабее!$B$BВ этих землях слабаки долго не живут.', 0);

-- Add ruRU offer rewards for quest 1385
-- https://ru.tbc.wowhead.com/quest=1385/политика-силы
SET @ID := 1385;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Многие из племени Гелкис пали от твоей руки. Мне это нравится. Может, ты сумеешь сделать что-то еще, что мне понравится. Может, ты сумеешь стать другом племени Маграм.', 0);

-- Add ruRU offer rewards for quest 1386
-- https://ru.tbc.wowhead.com/quest=1386/нападение-на-племя-колкар
SET @ID := 1386;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Теперь клан Колкар страшится тебя. Скажи, ты $Gсмеялся:смеялась;, когда убивал их? Когда убиваешь, надо смеяться, тогда враги увидят, что они слабы.', 0);

-- Add ruRU offer rewards for quest 1388
-- https://ru.tbc.wowhead.com/quest=1388/правда-и-только-правда
SET @ID := 1388;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Я знал, что старина Фаустин что-нибудь придумает! Ты ему очень $Gпомог:помогла;, я даже не сомневаюсь.$B$BА теперь к делу, верно?', 0);

-- Add ruRU offer rewards for quest 1389
-- https://ru.tbc.wowhead.com/quest=1389/кристаллы-дренейского-аметиста
SET @ID := 1389;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Благодарю тебя, $N. Мы перед тобой в долгу.', 0);

-- Add ruRU offer rewards for quest 1390	
-- https://wowroad.info/goha.ru?quest=1390
SET @ID := 1390;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Спасибо за проделанную работу!', 0);

-- Add ruRU offer rewards for quest 1391	
-- https://ru.classic.wowhead.com/quest=1391/правда-и-только-правда
SET @ID := 1391;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринес:принесла; мне попить? Как мило с твоей стороны. Мне не давали даже губы смочить вот уже несколько дней. Позволь мне утолить жажду, и я расскажу обо всем, что узнал...', 0);

-- Add ruRU offer rewards for quest 1396	
-- https://ru.classic.wowhead.com/quest=1396/атака-тварей
SET @ID := 1396;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Судя по звукам, твари убрались. Благодарю тебя, $N. Теперь-то, надеюсь, они не вернутся!', 0);

-- Add ruRU offer rewards for quest 1398	
-- https://ru.classic.wowhead.com/quest=1398/плавник
SET @ID := 1398;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Дерево легкое, но крепкое. Спасибо, $N, это подойдет.', 0);

-- Add ruRU offer rewards for quest 1418	
-- https://ru.classic.wowhead.com/quest=1418/ника-алый-шрам
SET @ID := 1418;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Хелгруму нужен доклад, а? Я посылала гонца в Каменор около трех дней назад. Он что, не добрался? Если в Каменоре нет моего донесения, сдается мне, гонец сгинул. Будем надеяться, что следующий, кого я пошлю, будет лучше подготовлен, ну или более удачлив.', 0);

-- Add ruRU offer rewards for quest 1419
-- https://ru.classic.wowhead.com/quest=1419/койоты-воры
SET @ID := 1419;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Впечатляющий набор челюстей, $N. Теперь-то эти койоты поостерегутся подбираться к нашим припасам.$B$BОтлично! Койоты из Бесплодных земель – не такая уж легкая добыча. Теперь я уверена – ты сможешь тут выжить.', 0);

-- Add ruRU offer rewards for quest 1420
-- https://ru.classic.wowhead.com/quest=1420/донесение-хелгруму
SET @ID := 1420;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Благодарю тебя, $N. Из донесения Ники я понял, что Альянс озабочен собственными проблемами, и, может статься, что кое-какие враги у нас общие.', 0);

-- Add ruRU offer rewards for quest 1421
-- https://ru.classic.wowhead.com/quest=1421/пропавший-караван
SET @ID := 1421;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Браво! С этими реактивами волшебники Крепости Стражей Пустоты смогут продолжить работу. Я не знаю, чем они там занимаются, знаю только, что это связано с Темным порталом в Бесплодных землях и напрямую касается безопасности всего Альянса.', 0);

-- Add ruRU offer rewards for quest 1422
-- https://ru.classic.wowhead.com/quest=1422/угроза-с-моря
SET @ID := 1422;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Помолчи немного, |3-6($C). Даже сквозь глухой рокот моря все еще слышно отвратительное бульканье, заменяющее рыболюдям речь.', 0);

-- Add ruRU offer rewards for quest 1424
-- https://ru.classic.wowhead.com/quest=1424/озеро-слез
SET @ID := 1424;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Твое усердие в происках артефактов Аталаи достойно похвалы, |3-6($C).', 0);

-- Add ruRU offer rewards for quest 1425
-- https://ru.classic.wowhead.com/quest=1425/доставка-груза
SET @ID := 1425;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что? Груз из каравана Биггса? Мы думали, он пропал вместе с караваном.$B$BСпасибо, $N. Надеюсь там кристаллы Азоры, этот реактив, нам крайне необходим, а наш запас подходит к концу.', 0);

-- Add ruRU offer rewards for quest 1426
-- https://ru.classic.wowhead.com/quest=1426/угроза-с-моря
SET @ID := 1426;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Море безбрежно и безжалостно, но ты $Gзапятнал:запятнала; его кровью его собственных порождений. Рыболюди знают, что такое боль. Их тупость заставит их сплотить ряды после того разгрома, который ты им $Gучинил:учинила;, и это хорошо.$B$BПусть их булькающие крики заглушают шум моря по ночам. А я буду улыбаться каждый раз как услышу, что кто-то из них замолк.$B$BВозвращайся ко мне, если вдруг захочется поубивать еще рыболюдей. Я с удовольствием тебя вознагражу за это.', 0);

-- Add ruRU offer rewards for quest 1427
-- https://ru.classic.wowhead.com/quest=1427/угроза-с-моря
SET @ID := 1427;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О! $N, ты $Gвернулся:вернулась;! Хорошо. Я как раз закончил партию оружия против мурлоков. За свежее мясо кусак и за то, что заставил Катара улыбаться, выбери себе одно.', 0);

-- Add ruRU offer rewards for quest 1428
-- https://ru.classic.wowhead.com/quest=1428/продолжающаяся-угроза
SET @ID := 1428;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отлично, |3-6($C). Но мне мало этой крови. Пусть все рыболюди исчезнут с лица земли.', 0);

-- Add ruRU offer rewards for quest 1429
-- https://ru.classic.wowhead.com/quest=1429/изгнанник-аталай
SET @ID := 1429;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Ты $Gпринес:принесла; мне артефакты призыва Атал\'ай? Я вижу, Джаммал\'ан Пророк ведет своих последователей из Чертога Крови навстречу выбранному ими року. Интересно, вернулся ли Хаккар в свой храм? Встретили ли они свою судьбу?', 0);

-- Add ruRU offer rewards for quest 1430
-- https://ru.classic.wowhead.com/quest=1430/свежее-мясо
SET @ID := 1430;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'О! Замечательно, я жду не дождусь, когда попробую крабье мясо, должным образом приготовленное на открытом огне. Возьми с собой в дорогу малую толику, вкус просто несравненный!', 0);

-- Add ruRU offer rewards for quest 1435
-- https://ru.classic.wowhead.com/quest=1435/сжигание-душ
SET @ID := 1435;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, ты $Gвернулся:вернулась; с победой! Это хорошо. Давай сюда самоцветы, я их спрячу в надежное место…$B$BУ меня больше нет для тебя поручений, |3-6($C). Отдохнешь – поговори с Такатой. Возможно, у него найдется для тебя дело – а может, он попросит тебя вернуться в Оргриммар и сообщить Кельдрану, как идут дела у нас в Пустошах.', 0);

-- Add ruRU offer rewards for quest 1436
-- https://ru.classic.wowhead.com/quest=1436/отношения-с-альянсом
SET @ID := 1436;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебе удалось добиться успеха, да еще какого, $N! Спасибо тебе.$B$BБлагодарю тебя за труды, за потраченное время и за то, что ты с пониманием $Gотнесся:отнеслась; к моей просьбе. Тралл стремится к миру между Ордой и Альянсом и потому заботится, чтобы мы выглядели достойно в глазах противника. Не следует провоцировать новые конфликты.$B$BЯ твой должник!', 0);

-- Add ruRU offer rewards for quest 1444
-- https://ru.classic.wowhead.com/quest=1444/возвращение-к-фелзерулу
SET @ID := 1444;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Мы же виделись совсем недавно, |3-6($C). Надеюсь, твое путешествие было удачным. Что тебе поведал изгнанник-Атал\'ай во внутренних землях?', 0);

-- Add ruRU offer rewards for quest 1445
-- https://ru.classic.wowhead.com/quest=1445/храм-аталхаккара
SET @ID := 1445;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Отважный |3-6($C), ты $Gдоказал:доказала;, что являешься одним из лучших воинов Орды.$B$BТеперь-то мы разберемся с этими амулетами!', 0);

-- Add ruRU offer rewards for quest 1464
-- https://ru.classic.wowhead.com/quest=1464/сапта-огня
SET @ID := 1464;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Пусть огонь неугасимо пылает в твоем сердце, $N!Стихии ждут тебя.', 0);

-- Add ruRU offer rewards for quest 1468
-- https://ru.classic.wowhead.com/quest=1468/детская-неделя
SET @ID := 1468;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Э... ну, привет. Меня зовут Рандис, ты будешь за мной присматривать, да? А ты – $Gискатель:искательница; приключений? Мама и папа тоже были такими. Значит, ты меня поймешь!B$BДавай играть! Воспитатели мне сказали, что ты мне будешь вроде $Gстаршего:старшей; $Gбрата:сестры;. Это здорово! Если бы у меня были настоящие братишки и сестренки...', 0);

-- Add ruRU offer rewards for quest 1472
-- https://ru.classic.wowhead.com/quest=1472/пожирательница-душ
SET @ID := 1472;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Тебя прислал Карендин? Говоришь, ты $N?$B$BНе думай, что я просто беспомощный слепец. Я вижу истинную суть вещей с недоступной прежде ясностью, и то, что было моим проклятьем, обернулось благословением.', 0);

-- Add ruRU offer rewards for quest 1474
-- https://ru.classic.wowhead.com/quest=1474/оковы
SET @ID := 1474;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'И снова ты $Gсправился:справилась; с заданием. Давно мне не встречались чернокнижники с такими задатками. Не сомневайся, я буду следить за твоими успехами и помогу тебе подготовиться к ожидающим тебя испытаниям.$B$BА теперь я хочу научить тебя заклинанию призва личного суккуба.', 0);

-- Add ruRU offer rewards for quest 1475
-- https://ru.classic.wowhead.com/quest=1475/в-храме-аталхаккара
SET @ID := 1475;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Таблички Атал\'ай! Благодарю, $N!$B$BКогда я доставлю их в Лигу Исследователей, наши имена войдут в историю. Вы помогли старому дворфу выполнить его последнее задание, и я бесконечно признателен вам за это!', 0);

-- Add ruRU offer rewards for quest 1476
-- https://ru.classic.wowhead.com/quest=1476/чистые-сердца
SET @ID := 1476;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А с виду доброе сердце ничем не отличается от любого другого, да?$B$BМожет быть, мы просто... по-другому смотрим на мир. Но эти сердца прекрасно подойдут. Не сомневаюсь, их чистота привлечет суккуба.', 0);

-- Add ruRU offer rewards for quest 1480
-- https://ru.classic.wowhead.com/quest=1480/осквернитель-душ
SET @ID := 1480;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, $N, это действительно чужой язык, и весьма древний. Он отчасти напоминает эредан, но отличия несомненны. Если не ошибаюсь, это нечто вроде договора... Да, вот этот символ – подпись демона: лорд Азреток.', 0);

-- Add ruRU offer rewards for quest 1481
-- https://ru.classic.wowhead.com/quest=1481/осквернитель-душ
SET @ID := 1481;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Что, |3-6($C), тенеловы тебя не убили? Неплохо, очень неплохо.$B$BДа, этот скальп мне подходит. Пока тебя не было, мне удалось собрать остальные необходимые реагенты.$B$BЯ почти готов. Мне необходима только точка приложения заклинания – тот предмет, в котором мы увидим повелителя демонов и место, где он находится.', 0);

-- Add ruRU offer rewards for quest 1482
-- https://ru.classic.wowhead.com/quest=1482/осквернитель-душ
SET @ID := 1482;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Драгоценный кристалл оракула! Безупречный... великолепный…$B$BЧто ж, начнем немедленно. Нам следует отыскать этого повелителя демонов.$B$BОтступи на шаг, |3-6($C), и давай посмотрим, как выглядит Азреток и где его искать.', 0);

-- Add ruRU offer rewards for quest 1484
-- https://ru.classic.wowhead.com/quest=1484/осквернитель-душ
SET @ID := 1484;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Да, я видел, что только что произошло между Муарином и повелителем демонов! Похоже, это существо, даже в видении, обладает куда большим могуществом, чем мой соратник-чернокнижник. Сумеет ли он одолеть этого монстра? Лучше бы я занялся этим сам... Но вождю я нужен здесь. Я опозорю свой клан, если оставлю свои здешние обязанности и отправлюсь добывать себе славу.', 0);

-- Add ruRU offer rewards for quest 1488
-- https://ru.classic.wowhead.com/quest=1488/осквернитель-душ
SET @ID := 1488;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'Эта победа очень важна для нас, $N. Все мы радуемся вашему успеху. Теперь я думаю, что наше будущее не так беспросветно, как мне казалось.$B$BДемоны будут повержены, Пылающий Клинок потерпит крах, и в один прекрасный день у нас снова будет свой дом!', 0);

-- Add ruRU offer rewards for quest 1498
-- https://ru.classic.wowhead.com/quest=1498/путь-защиты
SET @ID := 1498;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` = 'ruRU';
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'ruRU', 'А, вижу, тебе удалось справиться с рокочущими ящерицами, значит, ты $Gкрепкий:крепкая;. А теперь я покажу тебе, как можно сделаться почти неуязвимым для противника благодаря толстой шкуре и ловкости.$B$BУчись хорошенько, $N. Вскоре тебе предстоит новый урок.', 0);
