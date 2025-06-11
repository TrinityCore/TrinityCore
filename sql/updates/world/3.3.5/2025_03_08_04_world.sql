-- Marshal Dughan - Missing greeting
-- https://www.wowhead.com/classic/npc=240/marshal-dughan
DELETE FROM quest_greeting_locale WHERE ID=240 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('240', 'ruRU', 'Ох, тут и так сложно поддерживать порядок, а тут еще и новые неприятности вылезают! Надеюсь, у тебя хорошие новости, $n...', '0');

-- Goldtooth - Incorrect quest description: now it says that Goldtooth hid in his lair ABOVE the mine, but on the wowhead it says that he hid IN the mine.
-- https://www.wowhead.com/classic/quest=87/goldtooth
UPDATE quest_template_locale SET Details='Я играл около рудника Подземных глубин и, похоже, уронил... М-м... В смысле, я там видел ожерелье этой самой дамы. Представления не имею, как оно туда попало; я тут ни при чем!\r\n\r\nВ общем, короче, я видел, как здоровенный кобольд с золотыми зубами схватил ожерелье и скрылся в руднике. Если отыщешь этого кобольда, найдешь и ожерелье, точно тебе говорю!' WHERE ID=87 AND locale='ruRU';

-- William Pestle - Missing greeting
-- https://www.wowhead.com/classic/npc=253/william-pestle
DELETE FROM quest_greeting_locale WHERE ID=253 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('253', 'ruRU', 'Ага! Добрый день, добрый день, Мастер $C! Присаживайтесь и выпейте. У вас предприимчивый взгляд, и я думаю, вы найдете разговор со мной стоящим вашего времени...', '0');

-- Further Concerns - Incorrect quest description. Marshal Dughan offers to use his mount, but he doesn’t give you any mount, and the wowhead doesn’t mention a mount.
-- https://www.wowhead.com/classic/quest=35/further-concerns
UPDATE quest_template_locale SET Details='Если ты думаешь, что слухи о мурлоках могут оказаться правдой, отправляйся к восточному мосту Элвиннского леса и поговори со стражником Томасом. Он уже неделю несет стражу у моста и должен знать, что там происходит на самом деле.\r\n\r\nПринеси мне его отчет.' WHERE ID=35 AND locale='ruRU';

-- Rema Schneider - Missing greeting
-- https://www.wowhead.com/classic/npc=1428/rema-schneider
DELETE FROM quest_greeting_locale WHERE ID=1428 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1428', 'ruRU', 'Приветствую, $n.', '0');

-- Guard Thomas - Missing greeting
-- https://www.wowhead.com/classic/npc=261/guard-thomas
DELETE FROM quest_greeting_locale WHERE ID=261 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('261', 'ruRU', 'Привет, гражданин. Выглядишь как $gмужчина:женщина; с целью - у тебя есть дело к армии Штормграда?', '0');

-- Surena Caledon - Missing ruRU localisation text
-- https://www.wowhead.com/classic/quest=1688/surena-caledon
UPDATE quest_template_locale SET Details='У меня была ученица по имени Сурена Каледон. Помню, она стояла как раз там, где сейчас стоишь ты… Просила меня научить ее искусству чернокнижия, а у самой даже капли таланта к этому не было. Хм, зато она была молода и довольно миловидна. Если бы я видел тогда, что это за вероломная дрянь!\r\n\r\nРаспутная девка сбежала с одним из членов Братства Справедливости по имени Эрлан Драджмур. Об этой потере я нисколько не сожалею, однако колье Кровавого камня, которое я подарил ей, мне все еще нужно.\r\n\r\nЕе жизнь для меня больше ничего не значит. Ты найдешь девку на тыквенной ферме Бреквеллов. Верни мне мое имущество!' WHERE ID=1688 AND locale='ruRU';

-- Grelin Whitebeard - Missing greeting
-- https://www.wowhead.com/classic/npc=786/grelin-whitebeard
DELETE FROM quest_greeting_locale WHERE ID=786 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('786', 'ruRU', 'Приветствую, $Gпарень:девчёнка;. Я Грелин Белобород. Я здесь, чтобы изучить угрозу, которую представляет растущее число троллей в Холодной долине. Что я обнаружил? Это немного тревожно...', '0');

-- Mountaineer Stormpike - Missing greeting
-- https://www.wowhead.com/classic/npc=1343/mountaineer-stormpike
DELETE FROM quest_greeting_locale WHERE ID=1343 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('1343', 'ruRU', 'Так, молодой, ощетинившийся $c, несомненно, привлечённый сюда разговорами о моих подвигах на полях сражений!$B$BСейчас не время для историй, ибо есть великие, важные дела, которые нужно совершить! Так что если вы ищете славы, то удача вам сегодня улыбнётся...', '0');

-- Woo Ping <Weapon Master> - Missing title
-- https://www.wowhead.com/classic/npc=11867/woo-ping
UPDATE creature_template_locale SET Title='Эксперт по оружию' WHERE entry=11867 AND locale='ruRU';

-- The Collector - Incorrect quest text
-- https://www.wowhead.com/classic/quest=123/the-collector
UPDATE quest_template_locale SET Details='На этом листке – расписание поставок золота из рудников в Элвиннском лесу. Поставки расписаны по дням и часам, а в качестве получателя указан некий "Вымогатель".\r\n\r\nСудя по всему, Вымогатель обосновался неподалеку от тыквенного поля Бреквеллов в восточной части Элвиннского леса.\r\n\r\nПохоже, это важные сведения. Было бы неплохо сообщить их маршалу Дугхану: он сейчас в Златоземье.', Objectives='Пойдите в Златоземье к маршалу Дугхану и отдайте ему расписание Вымогателя.' WHERE ID=123 AND locale='ruRU';

-- The Collector's Ring - There is no description of the item
-- https://www.wowhead.com/classic/item=2239/the-collectors-ring
UPDATE item_template_locale SET Description='На кольце выгравировано: "За долгую верную службу - ЭВК"' WHERE ID=2239 AND locale='ruRU';

-- Farmer Furlbrow - Missing greeting
-- https://www.wowhead.com/classic/npc=237/farmer-furlbrow
DELETE FROM quest_greeting_locale WHERE ID=237 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('237', 'ruRU', 'В этих краях одни неприятности. Я пытался сказать этому дураку Сальдену, чтобы он убирался, пока он ещё может, но он и слышать об этом не хочет. Но я не дурак. Мы с Верной уедем отсюда, как только починим эту повозку.', '0');

-- Verna Furlbrow - Missing greeting
-- https://www.wowhead.com/classic/npc=238/verna-furlbrow
DELETE FROM quest_greeting_locale WHERE ID=238 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('238', 'ruRU', 'Иногда мне кажется, что на небе большая серая туча, которая просто обрушивает на нас несчастья. Сначала нас прогнали с нашей земли, а теперь мы даже не можем выбраться из Западного Края. Кругом бардак. Что-то нужно делать.', '0');

-- Salma Saldean - Missing greeting
-- https://www.wowhead.com/classic/npc=235/salma-saldean
DELETE FROM quest_greeting_locale WHERE ID=235 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('235', 'ruRU', 'Добро пожаловать в нашу скромную обитель! Всегда приятно видеть дружелюбное лицо. И какие у вас сильные руки. Мы с мужем всегда ищем помощь на ферме. Теперь, когда большинство хороших людей уехали, трудно найти способного человека, который мог бы помочь.', '0');

-- Gryan Stoutmantle - Missing greeting
-- https://www.wowhead.com/classic/npc=234/gryan-stoutmantle
DELETE FROM quest_greeting_locale WHERE ID=234 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('234', 'ruRU', 'Западный Край погряз в отвратительной коррупции. Пока я исполнял свой долг на полях сражений Лордерона, эти честные фермы были захвачены и превращены в убежища для головорезов и убийц. Народному ополчению нужна ваша помощь.', '0');

-- Magistrate Solomon - Missing greeting
-- https://www.wowhead.com/classic/npc=344/magistrate-solomon
DELETE FROM quest_greeting_locale WHERE ID=344 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('344', 'ruRU', 'Красногорье охвачено хаосом!', '0');

-- Kimberly Hiett <Fletcher> - Incorrect title
-- https://www.wowhead.com/classic/npc=789/kimberly-hiett
UPDATE creature_template_locale SET Title='Торговец стрелами' WHERE entry=789 AND locale='ruRU';

-- Darcy <Waitress> - Missing title
-- https://www.wowhead.com/classic/npc=379/darcy
UPDATE creature_template_locale SET Title='Официантка' WHERE entry=379 AND locale='ruRU';

-- Turalyon's Monument in Stormwind - Incorrect title of Uter
UPDATE page_text_locale SET Text='Генерал Туралион\r\n\r\nБывший наместник лорда Андуина Лотара. Рыцарь Серебряной Длани. Верховный генерал экспедиции Альянса, которая отправилась в Дренор, родной мир орков. Предположительно погиб.\r\n\r\nЭзарус тар-но Дарадор – Кровью и честью мы служим.\r\nТы был правой рукой справедливости и добродетели, старый друг. Твое имя всегда будет почитаться в наших залах.\r\n\r\n- Лорд Утер Светоносный, рыцарь Серебряной Длани' WHERE ID=290 AND locale='ruRU';

-- Protector of the People <The People's Militia> - Missing title
-- https://www.wowhead.com/classic/npc=8096/protector-of-the-people
UPDATE creature_template_locale SET Title='Народное ополчение' WHERE entry=8096 AND locale='ruRU';

-- Wilder Thistlenettle - Missing greeting
-- https://www.wowhead.com/classic/npc=656/wilder-thistlenettle
DELETE FROM quest_greeting_locale WHERE ID=656 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('656', 'ruRU', 'Везде были воры! $b$bЭто было ужасно. Пещера обрушилась на нас. Я думаю, что все шахтёры мертвы, включая моего брата, бригадира.', '0');

-- Postponing the Inevitable - Archmage Berinand https://wow.66wan.net/wotlk/en/?npc=25314 speaks about himself in feminine gender
-- https://www.wowhead.com/wotlk/quest=11905/postponing-the-inevitable
UPDATE quest_template_locale SET Details='Я определил причину нестабильности!\r\n\r\nСиловые линии Азерота перенаправлены на Нексус. Потрясающе! Если бы я мог провести остаток своих дней, исследуя эту аномалию…\r\n\r\nУвы, придется заняться текущими проблемами. Поток магической энергии расширяет разлом между измерениями.\r\n\r\nВ глубине Нексуса творится то, из-за чего ткань нашей вселенной истончается. Остановить это я не могу, однако нашел способ замедлить это.\r\n\r\nОтнеси это в Нексус и активируй поблизости от формирующегося разлома.' WHERE ID=11905 AND locale='ruRU';

-- Quickening - Archmage Berinand https://www.wowhead.com/wotlk/npc=25314/archmage-berinand speaks about himself in feminine gender, and incorrect questgiver in objectives
-- https://www.wowhead.com/wotlk/quest=11911/quickening
UPDATE quest_template_locale SET Details='Хотя мы, может быть, стоим на пороге прекращения нашего существования, я не перестаю изумляться. За короткое время, проведенное здесь, я узнал больше, чем за десятилетия исследований.\r\n\r\nЭти древа постоянно находятся под воздействием магической энергии. Она буквально на глазах превращает их в нечто... иное.\r\n\r\nЯ уверен, что это ещё одна ступень их трансформации. Я хочу, чтобы ты $Gотправился:отправилась; прямо в Нексус и $Gнашёл:нашла; какие-нибудь свидетельства об их конечном состоянии.\r\n\r\nПожалуйста, будь осторожнее...' WHERE ID=11911 AND locale='ruRU';
UPDATE quest_template_locale SET Objectives='Верховный маг Беринард в Нексусе хочет, чтобы вы собрали 5 магических обломков кристаллических заступников.' WHERE ID=11911 AND locale='ruRU';

-- Have They No Shame? (Alliance) - Incorrect questgiver in objectives
-- https://www.wowhead.com/wotlk/quest=13094/have-they-no-shame
UPDATE quest_template_locale SET Objectives='Библиотекарь Серра просит вас зайти в Нексус и найти книгу с исследованиями Беринарда.' WHERE ID=13094 AND locale='ruRU';

-- Have They No Shame? (Horde) - Incorrect questgiver in objectives
-- https://www.wowhead.com/wotlk/quest=13095/have-they-no-shame
UPDATE quest_template_locale SET Objectives='Библиотекарь Серра просит вас зайти в Нексус и найти книгу с исследованиями Беринарда.' WHERE ID=13095 AND locale='ruRU';

-- Count Remington Ridgewell <House of Nobles> - Missing greeting
-- https://www.wowhead.com/wotlk/npc=2285/count-remington-ridgewell
DELETE FROM quest_greeting_locale WHERE ID=2285 AND locale='ruRU';
INSERT INTO quest_greeting_locale (ID, locale, Greeting, VerifiedBuild) VALUES ('2285', 'ruRU', 'Моя семья может похвастаться лучшей коллекцией ювелирных изделий и предметов изящного искусства среди всех дворян Штормграда!$b$bИ мы всегда хотим увеличить размер нашей коллекции...', '0');

-- Collection of Goods - Just a quick clarification that it's not "Stratholme Water" but "Water FROM Stratholme"
-- https://www.wowhead.com/wotlk/quest=7642/collection-of-goods
UPDATE quest_template_locale SET Details='Для чепрака тебе понадобятся четыре вещи: руническая ткань для подкладки, арканитовые слитки для покрытия, цветки слезы Артаса для настройки на призрачный мир и святая вода из Стратхольма для духовного укрепления. На самом деле, вещей понадобится пять... если считать золото для меня. Эта плата – за весь мой труд, а также седло и стремена ручной работы.$b$bКогда наберешь все это, я смогу изготовить твой чепрак. А пока ты ищешь необходимое, я приступлю к работе.' WHERE ID=7642 AND locale='ruRU';
