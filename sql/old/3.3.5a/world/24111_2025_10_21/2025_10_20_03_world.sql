-- It Goes to 11... - Wrong ObjectiveText1. Also during the quest there are broadcast_text messages in English about the arrival of the vrykul defenders, but I don't know how to fix it yet. Creating similar lines with translation into Russian in table broadcast_text_locale did not help. Also Wrong CompletionText. Also addressing a character without taking into account his gender.
-- https://www.wowhead.com/wotlk/quest=11421/it-goes-to-11
UPDATE quest_template_locale SET ObjectiveText1='Защитники клана Укротителей драконов убиты' WHERE ID=11421 AND locale='ruRU';
UPDATE quest_request_items_locale SET CompletionText='Надеюсь, ты пришёл сказать мне, что Деревня Драконьего Черепа охвачена пламенем?' WHERE ID=11421 AND locale='ruRU';
UPDATE quest_offer_reward_locale SET RewardText='Прекрасно, $N! Ты $Gубил:убила; множество драконьих наездников и серьезно $Gразозлил:разозлила; их предводителей.$B$B$GГотов:Готова; вернуться в Валгард и сообщить хорошие новости Зореку? А то у меня появилась совершенно безумная идея!' WHERE ID=11421 AND locale='ruRU';

-- The Defias Brotherhood - Edwin VanCleef is human. No need for $r.
-- https://www.wowhead.com/wotlk/quest=141/the-defias-brotherhood
UPDATE quest_offer_reward_locale SET RewardText='Эдвин ван Клиф... Мне хорошо известно это имя. Обидно думать, что этот трудолюбивый и талантливый человек мог превратиться в такого мерзавца. Мне понадобятся дополнительные доказательства, чтобы я поверил в это.' WHERE ID=141 AND locale='ruRU';

-- Shoni the Shilent - Missing greeting
-- https://www.wowhead.com/wotlk/npc=6579/shoni-the-shilent
DELETE FROM quest_greeting_locale WHERE ID=6579 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('6579', 'ruRU', 'За Гномреган!', '0');

-- Verner Osgood - Missing greeting
-- https://www.wowhead.com/wotlk/npc=415/verner-osgood
DELETE FROM quest_greeting_locale WHERE ID=415 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('415', 'ruRU', 'Эй, $Gприятель:мадам;, как думаешь, ты сможешь мне помочь? Я действительно в отчаянном положении...', '0');

-- Dockmaster Baren - Missing greeting
-- https://www.wowhead.com/wotlk/npc=381/dockmaster-baren
DELETE FROM quest_greeting_locale WHERE ID=381 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('381', 'ruRU', 'Рад встрече, $C. Если ты здесь по делу, то возьми себе пива, и мы поговорим.', '0');

-- Martie Jainrose - Missing greeting
-- https://www.wowhead.com/wotlk/npc=342/martie-jainrose
DELETE FROM quest_greeting_locale WHERE ID=342 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('342', 'ruRU', 'Приветствую, $n. Добро пожаловать в мой скромный сад. Погода в последнее время была идеальной. Будем надеяться, что она такой сохранится до сбора урожая.', '0');

-- Howling in the Hills - Small correction. Now it says "Red Mountains", but it should be "Redridge Mountains"
-- https://www.wowhead.com/wotlk/quest=126/howling-in-the-hills
UPDATE quest_offer_reward_locale SET RewardText='И снова благодарю тебя за помощь. Штормград еле-еле справляется с орками, у них не хватает солдат, чтобы защищать Красногорье от напастей вроде гноллов.' WHERE ID=126 AND locale='ruRU';

-- Brother Paxton <Librarian> - Missing title
-- https://www.wowhead.com/wotlk/npc=951/brother-paxton
UPDATE creature_template_locale SET Title='Библиотекарь' WHERE entry=951 AND locale='ruRU';

-- Tua'kea - Missing greeting in quest_greeting and quest_greeting_locale ruRU
-- https://www.wowhead.com/wotlk/npc=26245/tuakea
DELETE FROM quest_greeting WHERE ID=26245;
INSERT INTO quest_greeting (ID, Greeting, VerifiedBuild) VALUES ('26245', 'Greetings, $n.', '0');
DELETE FROM quest_greeting_locale WHERE ID=26245 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('26245', 'ruRU', 'Приветствую, $n.', '0');

-- Warden Thelwater - Missing greeting.
-- https://www.wowhead.com/classic/npc=1719/warden-thelwater
DELETE FROM quest_greeting_locale WHERE ID=1719 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1719', 'ruRU', 'Ну давайте, нападайте, ничтожества!...$B$BЭй $gпарень:девчёнка;, если хочешь сделать что-то полезное, слушай скорее!', '0');

-- Marshal Marris - Missing greeting
-- https://www.wowhead.com/classic/npc=382/marshal-marris
DELETE FROM quest_greeting_locale WHERE ID=382 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('382', 'ruRU', 'У меня нет времени на болтовню, гражданин, но если вы готовы помочь нам в борьбе с орками, то я найду вам применение.', '0');

-- Theocritus <Mage of Tower Azora> - Missing greeting
-- https://www.wowhead.com/classic/npc=313/theocritus
DELETE FROM quest_greeting_locale WHERE ID=313 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('313', 'ruRU', 'Добро пожаловать в Башню Азоры, юный $C. Я Теокрит.$B$BУ тебя ко мне дело? Или... у меня к тебе дело, может быть?', '0');

-- Shindrell Swiftfire - Missing greeting
-- https://www.wowhead.com/wotlk/npc=3845/shindrell-swiftfire
DELETE FROM quest_greeting_locale WHERE ID=3845 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('3845', 'ruRU', 'У нас, эльфов, долгая история. Будем надеяться, что эта история не вернется, чтобы преследовать нас.', '0');

-- The Charred Vale (road sign) - Missing translation
DELETE FROM gameobject_template_locale WHERE entry=19577 AND locale='ruRU';
INSERT INTO gameobject_template_locale (entry, locale, name, VerifiedBuild) VALUES ('19577', 'ruRU', 'Обугленная долина', '0');

-- Mebok Mizzyrix - Missing greeting
-- https://www.wowhead.com/wotlk/npc=3446/mebok-mizzyrix
DELETE FROM quest_greeting_locale WHERE ID=3446 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('3446', 'ruRU', 'Да, да, да! Ты именно тот $r, которого я ищу!$B$BСадись! Нам нужно многое обсудить!!', '0');

-- First Mate Fitzsimmons - Missing greeting
-- https://www.wowhead.com/wotlk/npc=1239/first-mate-fitzsimmons
DELETE FROM quest_greeting_locale WHERE ID=1239 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1239', 'ruRU', 'Если вы готовы слушать истории, от которых у вас побегут мурашки по коже и промокнет нижнее белье, тогда налейте себе выпить и присаживайтесь рядом...', '0');

-- Edwina Monzor <Fletcher> - Incorrect title
-- https://www.wowhead.com/wotlk/npc=1462/edwina-monzor
UPDATE creature_template_locale SET Title='Торговец стрелами' WHERE entry=1462 AND locale='ruRU';

-- Magistrate Bluntnose - Missing greeting
-- https://www.wowhead.com/wotlk/npc=1139/magistrate-bluntnose
DELETE FROM quest_greeting_locale WHERE ID=1139 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1139', 'ruRU', 'Ну привет, гражданин. Меня зовут Тупонос, Мировой судья Тупонос, если быть точным. Я отвечаю за благополучие Телсамара, и поверь мне, нам здесь всегда не помешает еще одна сильная пара рук!', '0');

-- A Hunter's Challenge - Missing objective
-- https://www.wowhead.com/wotlk/quest=258/a-hunters-challenge
UPDATE quest_template_locale SET CompletedText='Вернитесь к Дэрилу Юному в Приют странников.' WHERE ID=258 AND locale='ruRU';

-- Bingles' Missing Supplies - Missing objective
-- https://www.wowhead.com/wotlk/quest=2038/bingles-missing-supplies
UPDATE quest_template_locale SET CompletedText='Возвращайтесь к Бинглзу Подрывайстерру на озеро Лок в Лок-Модане.' WHERE ID=2038 AND locale='ruRU';

-- Crocolisk Hunting - Missing objective
-- https://www.wowhead.com/wotlk/quest=385/crocolisk-hunting
UPDATE quest_template_locale SET CompletedText='Вернитесь к Мареку Железносерду в Лок Модан.' WHERE ID=385 AND locale='ruRU';

-- Mercenaries - Missing objective
-- https://www.wowhead.com/wotlk/quest=255/mercenaries
UPDATE quest_template_locale SET CompletedText='Возвращайтесь к Мировому судье Тупоносу в Лок Модане.' WHERE ID=255 AND locale='ruRU';

-- Vyrin's Revenge - Missing objective
-- https://www.wowhead.com/wotlk/quest=271/vyrins-revenge
UPDATE quest_template_locale SET CompletedText='Вернитесь к Дэрилу Юному в Приют странников.' WHERE ID=271 AND locale='ruRU';

-- Longbraid the Grim - Missing greeting
-- https://www.wowhead.com/wotlk/npc=1071/longbraid-the-grim
DELETE FROM quest_greeting_locale WHERE ID=1071 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1071', 'ruRU', 'Если Раг чему-то меня и научил, так это тому, что не бывает скучных заданий. Защита моста Тандола должна была быть легкой задачей. Но с основным ударом армии, сражающейся вместе с Альянсом, мы были подавлены здесь, и Дун Модр пал.', '0');

-- Madame Eva - Missing greeting
-- https://www.wowhead.com/wotlk/npc=265/madame-eva
DELETE FROM quest_greeting_locale WHERE ID=265 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('265', 'ruRU', 'Я уже давно предчувствовала твоё приближение, $n. На это мне указали звёзды.', '0');

-- Elaine Carevin - Missing greeting
-- https://www.wowhead.com/wotlk/npc=633/elaine-carevin
DELETE FROM quest_greeting_locale WHERE ID=633 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('633', 'ruRU', 'Настали тёмные времена, $c... Слишком скоро мы потеряем всё... Когда Свет оставит всех, кроме тех, кто действительно ходит под Светом.', '0');

-- Commander Althea Ebonlocke - Missing greeting
-- https://www.wowhead.com/wotlk/npc=264/commander-althea-ebonlocke
DELETE FROM quest_greeting_locale WHERE ID=264 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('264', 'ruRU', 'Вольно, $c. Если ты просто проезжаешь мимо, советую придерживаться дорог и путешествовать только днем. Если у тебя дела здесь, в Темнолесье, подумай о том, чтобы помочь Ночному Дозору. Наше Мастерство неоспоримо, но нас мало.', '0');

-- Jitters - Missing greeting
-- https://www.wowhead.com/classic/npc=288/jitters
DELETE FROM quest_greeting_locale WHERE ID=288 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('288', 'ruRU', 'А?!? Ох. Ты не похож на вора из Братства Справедливости... или члена Ночного Дозора. Пожалей бедную душу, ладно?', '0');

-- James Halloran - Missing greeting
-- https://www.wowhead.com/classic/npc=2094/james-halloran
DELETE FROM quest_greeting_locale WHERE ID=2094 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('2094', 'ruRU', 'Приветствую, $c. Я сейчас в затруднительном положении, шкуры у меня заканчиваются.', '0');

-- The Path of Redemption - HTML Web code in the book. Other languages ​​also have this code. Fix only for the specified item and ruRU localization. It also looks like the pages are mixed up. Guided by page_text
-- https://www.wowhead.com/wotlk/item=37931/the-path-of-redemption
UPDATE page_text_locale SET Text='Я снова слышала голос. "Приди..." – воззвал ко мне Свет.\r\n\r\nЯ проснулась, дрожа до кончиков пальцев, но причиной тому был не холод моих покоев. Я должна удвоить усилия! Сегодня же скажу верховному настоятелю, что желаю возносить в два раза больше молитв. Хватит полумер!\r\n\r\nВеликий Свет возрадуется нашим добрым деяниям. Теперь я это знаю наверняка!' WHERE ID=3094 AND locale='ruRU';
UPDATE page_text_locale SET Text='Я снова слышала голос. "Приди..." – воззвал ко мне Свет.\r\n\r\nЯ проснулась, дрожа до кончиков пальцев, но причиной тому был не холод моих покоев. Я должна удвоить усилия! Сегодня же скажу верховному настоятелю, что желаю возносить в два раза больше молитв. Хватит полумер!\r\n\r\nВеликий Свет возрадуется нашим добрым деяниям. Теперь я это знаю наверняка!' WHERE ID=3123 AND locale='ruRU';
UPDATE page_text_locale SET Text='Это произошло снова! Теперь я уже не спала. Чуть больше минуты я внимала голосу Света, и посреди теплого летнего дня с моих губ вдруг сорвалось облачко холодного пара. Это заметил один из жрецов и пал на колени в благоговейной молитве.\r\n\r\nПравда, никто, кроме меня, не слышал священный глас. Но теперь я точно знаю, что не сошла с ума. Может быть, мне попросить Ландгрена помолиться за меня?\r\n\r\nНадо сказать Джордану и Стриту, чтобы они более тщательно подходили к набору добровольцев. Наша армия переполнена скептиками и неверующими, желающими только сражаться с нежитью. Довольно! Больше я не потерплю такого кощунства.' WHERE ID=3095 AND locale='ruRU';
UPDATE page_text_locale SET Text='Это произошло снова! Теперь я уже не спала. Чуть больше минуты я внимала голосу Света, и посреди теплого летнего дня с моих губ вдруг сорвалось облачко холодного пара. Это заметил один из жрецов и пал на колени в благоговейной молитве.\r\n\r\nПравда, никто, кроме меня, не слышал священный глас. Но теперь я точно знаю, что не сошла с ума. Может быть, мне попросить Ландгрена помолиться за меня?\r\n\r\nНадо сказать Джордану и Стриту, чтобы они более тщательно подходили к набору добровольцев. Наша армия переполнена скептиками и неверующими, желающими только сражаться с нежитью. Довольно! Больше я не потерплю такого кощунства.' WHERE ID=3124 AND locale='ruRU';
UPDATE page_text_locale SET Text='Епископ и главнокомандующий приняли мое предложение – правда, у них не было выбора. Епископ Стрит особенно воодушевленно отнесся к моим словам, и все время говорил о том, что нашей армии не помешает небольшая чистка. \r\n\r\nЯ велела ему успокоиться. В мои намерения не входит уничтожение всего ордена. Однако, мне по душе идея создания элитного отряда преданных Свету солдат, которые будут выполнять его волю в Нордсколе. Боюсь, дружба с Лекрафтом очень сильно на него влияет. Впрочем, оба они еще мне пригодятся.\r\n\r\nОднако слова Стрита о новом Ордене заставили меня задуматься. Если бы мы создали новую силу, я дала бы ей другое имя, гордое, отражающее нашу великую цель, но все же связанное с прошлым орденом. Я буду молиться, чтобы на меня снизошло вдохновение.' WHERE ID=3096 AND locale='ruRU';
UPDATE page_text_locale SET Text='Я намереваюсь оставить здесь большую часть Ордена, чтобы они продолжали зачистку земель от нежити за нашей спиной. Надеюсь, что когда начатое нами дело будет завершено, они смогут отправиться по домам, к своим семьям, и жить отныне в мире и согласии.\r\n\r\nКажется, я правильно поступаю. В конце концов, только на нас держалась эта земля, склонившаяся под гнетом омерзительной Плети, и только мы могли вернуть Лордерону его былую славу. Вернуть те времена, когда нежить не ходила по нашим полям, когда еще не было Артаса и его предательства... когда еще не было Короля-лича.' WHERE ID=3097 AND locale='ruRU';
UPDATE page_text_locale SET Text='Мои люди верят, что вскоре настанет решающий день для всего Алого ордена. Епископ Стрит дал имя этому событию, назвав его в проповеди Багровым Рассветом.\r\n\r\nМне надо поразмыслить над происходящим – хотя у меня нет сомнений в том, что все идет так, как задумано. Я буду молиться, чтобы это событие обернулось во благо нашему Ордену.' WHERE ID=3098 AND locale='ruRU';
UPDATE page_text_locale SET Text='Свет снова говорил со мной, с настойчивостью и убедительностью. Я проснулась в тревоге, боясь его подвести. Больше медлить нельзя. Мы должны выступать!\r\n\r\nКакое совпадение – признаться, я с трудом сдерживаю вздох облегчения, но именно сегодня капитан Шели предоставил нам новый флот для путешествия. Хотя, возможно, это было вовсе не совпадение? Неисповедимы пути Света, и я могу лишь надеяться, что это он руководит моими действиями.\r\n\r\nМоим флагманом будет "Глупость Грешника". По-моему, вполне подходящее название.' WHERE ID=3099 AND locale='ruRU';
UPDATE page_text_locale SET Text='Теперь я знаю, почему Свет так настойчиво побуждал меня к действию. Под покровом ночи в небесах появились некрополи Плети и обрушили тысячи демонов на наши головы!\r\n\r\nЗахватчиков возглавляет новый выводок рыцарей смерти, и мы потеряли множество людей в сражении с этими тварями. Теперь, когда Плеть может нападать на нас повсюду, и даже с небес, нам будет гораздо сложнее удерживать оборону.\r\n\r\nБоюсь, наша экспедиция в Нордскол закончится, не успев начаться.' WHERE ID=3100 AND locale='ruRU';
UPDATE page_text_locale SET Text='Мне сообщили, что Дольный Очаг готов оказать нам поддержку. Спасательную операцию намеревается возглавить сам главнокомандующий Галвар Чистокров, но усилия его напрасны.\r\n\r\nНадо отправить моих лучших курьеров, чтобы они прорвались за линию огня и передали мой приказ к отступлению. Дольный Очаг должен сосредоточиться на обороне, чтобы иметь возможность принять под свою защиту остатки Ордена.\r\n\r\nНадеюсь, мое послание достигнет их еще до наступления ночи.' WHERE ID=3101 AND locale='ruRU';
UPDATE page_text_locale SET Text='К утру от моих курьеров не поступило ни единого донесения. Очевидно, никто из них не добрался до Дольного Очага. Чумные земли потеряны для нас. Скоро сюда прибудет Чистокров, но его войска будут разбиты еще на подходе.\r\n\r\nСегодня днем мне было видение, посланное Светом. Я видела гибель всего, что мы возвели собственными руками. Теперь я знаю, что должна забрать с собой самых преданных воинов и предоставить остатки Ордена на откуп судьбе.' WHERE ID=3143 AND locale='ruRU';
UPDATE page_text_locale SET Text='Позже Ландгрен сказал, что видел то же, что и я. Не понимаю, почему Свет побуждает нас совершить столь бесчестное деяние, но не имею права сомневаться в его повелении. Я должна повиноваться, и я повинуюсь.\r\n\r\nС трепетом взираю я на Новый Авалон, ибо мне кажется, что вижу его в последний раз. Наша судьба решится в Нордсколе, но меня обуревает гнетущее чувство неминуемой беды. Я надеюсь, что наши грядущие деяния очистят мою душу от смятений. Я должна выбросить сомнения прочь из головы.' WHERE ID=3144 AND locale='ruRU';
UPDATE page_text_locale SET Text='Молюсь Свету, чтобы главнокомандующий Чистокров избежал страшной участи на поле боя. Я же чувствую себя предательницей. Трусливым псом, поджавшим хвост от страха.\r\n\r\nГоворят, что путешествие займет около двух месяцев – остальные корабли не столь быстроходны, как "Грешник". На них находится большая часть наших войск и экипировки, но они должны доплыть в целости и сохранности.\r\n\r\nМеня совсем не тянет к воде, но во имя Света я должна перетерпеть морскую болезнь. Просто не буду никому показываться на глаза.' WHERE ID=3145 AND locale='ruRU';
UPDATE page_text_locale SET Text='Я давно уже ничего не писала в дневнике – в последнее время мне с трудом удается удержаться на ногах, чтобы не почувствовать очередной приступ тошноты. Солдаты начинают волноваться за меня – ведь я практически не покидаю своей каюты. Но я не могу позволить им увидеть себя в таком плачевном состоянии.\r\n\r\nК счастью, терпеть осталось недолго. Молю Свет, чтобы наше путешествие поскорее закончилось. Мы плывем вот уже шесть недель, и с каждым днем погода становится все хуже и хуже. Надеюсь, в Нордсколе будет немного теплее – с детства ненавижу холод.\r\n\r\nИ глас Великого Света давно уже ко мне не обращался.' WHERE ID=3146 AND locale='ruRU';
UPDATE page_text_locale SET Text='На нас напали без единого предупреждения! Эти великаны в грубо выточенных каноэ выплыли из тумана подобно призракам! Бесшумные, как мертвецы...\r\n\r\nМы потеряли один корабль со всей командой. Они сражались отважно и умело, учитывая, что до сих пор им не приходилось участвовать в реальных морских сражениях.\r\n\r\nВопли наших моряков, захваченных великанами, еще долго отражались от прибрежных скал. Потом все стихло. Епископ Стрит созвал команду на панихиду.' WHERE ID=3147 AND locale='ruRU';
UPDATE page_text_locale SET Text='Сегодня утром я проснулась и обнаружила себя склонившейся над морскими картами. Сам Свет водил моей рукой, прокладывая путь к цели.\r\n\r\nМы почти на месте!' WHERE ID=3148 AND locale='ruRU';
UPDATE page_text_locale SET Text='Наконец-то, земля!\r\n\r\nСойдя со шлюпки на берег, я установила наш флаг, и тут же услышала глас Великого Света. Он говорил моими устами. Сегодня великий день, сказал он – день Багрового Рассвета. Здесь, в этом самом месте, будет основан Новый Дольный Очаг. Отныне мы носим иное имя. Мы – Алый Натиск!\r\n\r\nТак мы начинаем наступление на Нордскол! Скверна Плети угрожает захватить власть над миром и погубить все живое. Настало время дать ей отпор. Скоро мы будем стоять у подножия трона самого Короля-лича!' WHERE ID=3149 AND locale='ruRU';
UPDATE page_text_locale SET Text='Прошел уже месяц, и я вполне довольна темпами строительства. Ничего не писала в дневнике – было не до того. Разведчики докладывают, что в этих землях полно драконов и прочих странных зверей. Мы должны быть настороже.\r\n\r\nСегодня, во время проповеди верховный настоятель провозгласил пришествие посланника Света, который поведет нас к победе.\r\n\r\nНе знаю даже, что и думать об этом. Почему Свет не обращается больше ко мне? Неужто я чем-то прогневила небеса, и меня хотят заменить каким-то чужестранцем?' WHERE ID=3150 AND locale='ruRU';
UPDATE page_text_locale SET Text='Сегодня меня посетил сам адмирал Бареан Вествинд! По всем сведениям он считался погибшим много лет назад.\r\n\r\nОн выглядел довольно молодо, но я все равно узнала его с первого взгляда. Адмирал рассказал мне, что остался единственным выжившим человеком из всего обреченного флота, и что он спасся только благодаря милости Света.\r\n' WHERE ID=3151 AND locale='ruRU';
UPDATE page_text_locale SET Text='Мы провели за беседой всю ночь и все утро. Адмирал заверил меня, что не собирается покушаться на мой авторитет, но Свет повелел ему отправиться в Драконий Погост, чтобы стать моим советником и формальным главнокомандующим. Он утверждает, что скоро в Нордсколе произойдут великие перемены. Альянс и Орда объединятся перед лицом единой опасности – страшной чумы, которую намеревается наслать на них проклятый Король-лич.\r\n' WHERE ID=3152 AND locale='ruRU';
UPDATE page_text_locale SET Text='Солдаты восторженно приняли нового главнокомандующего – особенно верховный настоятель Ландгрен и епископ Стрит. Не иначе, Свет нашептал им благословения адмиралу, пока они спали. Некоторые воины приняли постриг и теперь именуют себя "жрецами-воронами".\r\n\r\nКажется, только Джордан остался в стороне от всеобщего ликования, и я вполне его понимаю. Он тоже чувствует, насколько шатко наше положение.' WHERE ID=3153 AND locale='ruRU';
UPDATE page_text_locale SET Text='Что-то не так. Я не могу понять, что именно, но я не могу полностью доверять адмиралу. Он не сделал ничего плохого. Совсем наоборот! И всё же, я должна доверять своей интуиции.\r\n\r\nЯ буду молиться о понимании. Свет послал адмирала, чтобы привести нас к победе, и не мне подвергать сомнению его решения. Я продолжу подчиняться. Я верена.' WHERE ID=3154 AND locale='ruRU';
UPDATE page_text_locale SET Text='Прошло еще несколько месяцев. Мы достигли больших успехов в строительстве Нового Дольного Очага. Стена почти завершена, впрочем как и казармы. Люди Калейки просто чудесные работники.\r\n\r\nЯ давно не делала здесь никаких записей – не хотелось. По какой-то причине я даже этого избегала. В последнее время Свет не говорит со мной, однако адмирал уверяет, что здесь не о чем волноваться.\r\n' WHERE ID=3155 AND locale='ruRU';
UPDATE page_text_locale SET Text='Мои люди сообщают, что небольшая группа Отрекшихся разбила лагерь вдоль склона холма на севере. По другую сторону холма Альянс, по-видимому, начал строительство гораздо более крупной базы.\r\n\r\nАдмирал говорит, что нам следует оставить их в покое. На западе собрались другие силы Орды, которые наверняка придут им на помощь, если мы нападем. Мне это не нравится, но я вижу логику в его рассуждениях.' WHERE ID=3156 AND locale='ruRU';

-- Archbishop Benedictus - Missing greeting
-- https://www.wowhead.com/classic/npc=1284/archbishop-benedictus
DELETE FROM quest_greeting_locale WHERE ID=1284 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1284', 'ruRU', 'Приветствую, $n.', '0');

-- Plea To The Alliance - Captain Nials https://www.wowhead.com/wotlk/npc=2700/captain-nials speaks about herself in the masculine gender
-- https://www.wowhead.com/wotlk/quest=634/plea-to-the-alliance
UPDATE quest_offer_reward_locale SET RewardText='Передай мои соболезнования Длинной Косе и его солдатам. Я искренне опечалена вестью о трагедии на мосту Тандола и падении Дун Модра...$B$BНо знайте, что и Стромгард пал! Именно поэтому мы сейчас стоим у Опорного пункта. Впереди – битва за наш великий город.$B$BДолг и честь не позволяют мне покинуть нагорье до тех пор, пока над Стромгардом не взовьется гордое знамя нашего короля! Придется Длинной Косе обходиться своими силами...' WHERE ID=634 AND locale='ruRU';

-- Marshal Redpath - Missing greeting
-- https://www.wowhead.com/classic/npc=2263/marshal-redpath
DELETE FROM quest_greeting_locale WHERE ID=2263 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('2263', 'ruRU', 'Надеюсь, ты здесь, чтобы работать, $C. У нас много дел, а Орда, Синдикат и Огры нам не помогут.', '0');

-- Wanted Board - Missing greeting
-- https://www.wowhead.com/classic/object=2713/wanted-board
DELETE FROM quest_greeting_locale WHERE ID=2713 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, Type, locale, Greeting, VerifiedBuild) VALUES ('2713', 1, 'ruRU', 'На этой деревянной доске висят грубо сделанные плакаты с надписью «Разыскивается».', '0');

-- Searing Totem III - The row in the creature_template_locale table exists but is filled in incorrectly
-- https://www.wowhead.com/classic/npc=3903/searing-totem-iii
UPDATE creature_template_locale SET Name='Опаляющий тотем III' WHERE entry=3903 AND locale='ruRU';

-- Angus Stern - Missing greeting
-- https://www.wowhead.com/classic/npc=1141/angus-stern
DELETE FROM quest_greeting_locale WHERE ID=1141 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1141', 'ruRU', 'Если вы здесь ради еды, то добро пожаловать! Вы не найдете более изысканной еды во всем Штормграде... или Азероте!$B$BЕсли вы здесь по другим вопросам, то, пожалуйста, будьте кратки. У меня готовится дюжина блюд, и я должен позаботиться о каждом.', '0');
