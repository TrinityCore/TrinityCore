-- Fix Creature_text with incorrect Type (Greetings to Cooler-SAI)
UPDATE creature_text SET Type = 12 WHERE Type = 0; -- Most of them use Type 12 (Say)
UPDATE creature_text SET Type = 14 WHERE CreatureID IN (28890,29664,38409,38437,38696,75506,76172,76759,77312,82133,85061) AND GroupID = 0;
UPDATE creature_text SET Type = 15 WHERE CreatureID = 22258 AND GroupID = 0;

-- Fix Docile Boar for Troll Starting Zone
UPDATE creature_template SET unit_flags= 32768 WHERE entry = 38141;
DELETE FROM creature_template_addon WHERE entry = 38141;
DELETE FROM creature WHERE guid = 210115472;

-- Fix some Russian Offer Reward (Greetings to Cooler-SAI)
DELETE FROM `quest_offer_reward` WHERE ID IN (24758,24759,24761,24762,24763,25037,25064);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) values
('24758','0','0','0','0','0','0','0','0','Anotha newblood, eh?$B$BYa actually have a sly look about ya though. Fierce eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.','25383'),
('24759','0','0','0','0','0','0','0','0','Not bad, mon. Ya have a natural flow to ya swings - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.','25383'),
('24761','0','0','0','0','0','0','0','0','Dese are some fine pelts, $G boy:girl;. We could make some hefty cloaks outta dese.','25383'),
('24762','0','0','0','0','0','0','0','0','Ya handle yerself quite well. Ya gonna be quite powerful some day.','25383'),
('24763','0','0','0','0','0','0','0','0','Ya tha new recruit everyone\'s talkin\' about, eh? Welcome ta tha Darkspear.','25383'),
('25037','0','0','0','0','0','0','0','0','Oi! Tasty, mon. Thank ya for your great kindness, young one. Da spirits shall surely be regardin\' ya with great favor.','15595'),
('25064','0','0','0','0','0','0','0','0','Hey there, hon. Vol\'jin sent you? So sweet of him to be thinkin\' of me.$B$BI surely could use da help, but ya have a bit more walkin\' ahead of ya.','15595');

-- Set Russian offer reward texts to _locale table
DELETE FROM `quest_offer_reward_locale` WHERE ID IN (24758,24759,24761,24762,24763,25037,25064) AND (`locale` = "ruRU");
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) values
('24758',"ruRU",'Еще один новобранец?$B$BВид у тебя бывалый.И глаза мудрые. Может, ты и вправду $gнастоящий:настоящая:c; |3-6($c).$B$BНе будем терять время.','26365'),
('24759',"ruRU",'Неплохо, $gдружище:подруга;. У тебя прирожденные способности к магии. Прямо-таки настоящий талант.$B$BКонечно, тебе предстоит потрудиться, чтобы овладеть магией по-настоящему. Но я тебя научу.','26365'),
('24761',"ruRU",'Хорошие шкуры, $gмалыш:малышка;. Из них можно справить отличные плащи.','26365'),
('24762',"ruRU",'А ты молодец. Когда-нибудь станешь очень $gсильным:сильной;.','26365'),
('24763',"ruRU",'Так ты и есть $gтот новенький:та новенькая;, о $gкотором:которой; все говорят? Добро пожаловать в Черное Копье.','26365'),
('25037',"ruRU",'Ммм, как вкусно. Спасибо тебе за доброту. Ты $gзаслужил:заслужила; расположение духов.','26365'),
('25064',"ruRU",'Привет, $gдорогой:дорогуша;. Тебя прислал Вол\'джин? Как мило с его стороны.$B$BДа, помощь мне нужна, и на месте тебе сидеть не придется.','26365');
