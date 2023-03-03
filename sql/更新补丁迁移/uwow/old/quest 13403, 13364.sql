update creature_template set ScriptName = 'npc_tg_tirion_fordring' where entry = 32239;
update creature_template set dmg_multiplier = 100, ScriptName = 'npc_tg_helper' where entry in (32310,32311,32312);
update creature_template set mechanic_immune_mask = 1, ScriptName = 'npc_tg_helper' where entry = 32184;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 60456;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 60456, 0, 0, 31, 0, 3, 24042, 0, 0, 0, '', NULL);

delete from creature_text where entry in (32239,32184,32312,32311,32310,32241,32175);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(32175, 0, 0, 'We lost many to the faceless ones, my lord. But we succeeded in retrieving the heart from Naz\'anak.', 12, 0, 100, 0, 0, 0, ''),
(32184, 0, 0, 'Uninvited guests! Did you think you\'d go unnoticed inside my dominion?', 12, 0, 100, 1, 0, 0, ''),
(32184, 1, 0, 'I must confess... you were not altogether unexpected. I hope you find your final resting place... to your liking.', 12, 0, 100, 1, 0, 0, ''),
(32184, 2, 0, 'Last time we met, you had the advantage of fighting on holy ground. You\'ll find that our situation has been... reversed.', 12, 0, 100, 1, 0, 0, ''),
(32184, 3, 0, 'I call your bluff. You\'re a paladin after all. Your obsession with redemption goes beyond the inane.', 12, 0, 100, 1, 0, 0, ''),
(32184, 4, 0, 'You surely wouldn\'t destroy humanity\'s only chance to redeem its most wayward son. You\'d sooner die!', 12, 0, 100, 1, 0, 0, ''),
(32184, 5, 0, 'Arrrrggggggggggh!!!!', 14, 0, 100, 0, 0, 0, ''),
(32184, 6, 0, 'You... will pay for that, old man. Slay them all!', 14, 0, 100, 0, 0, 0, ''),
(32239, 0, 0, 'It is time. May the Light give us strength.', 12, 0, 100, 0, 0, 0, ''),
(32239, 1, 0, 'Keep your heads down and follow my lead.', 12, 0, 100, 0, 0, 0, ''),
(32239, 2, 0, 'Here it comes. Stand ready.', 12, 0, 100, 0, 0, 0, ''),
(32239, 3, 0, 'Something\'s wrong... I sense a dark presence.', 12, 0, 100, 0, 0, 0, ''),
(32239, 4, 0, 'The Lich King is here. May the Light guide our blades.', 12, 0, 100, 0, 0, 0, ''),
(32239, 5, 0, 'You sound a little too confident. Especially considering the way our last encounter ended.', 12, 0, 100, 0, 0, 0, ''),
(32239, 6, 0, 'That might be, but I don\'t need to stand on holy ground to run that disembodied heart of yours through with the Ashbringer.', 12, 0, 100, 0, 0, 0, ''),
(32239, 7, 0, 'The heart... the last remaining vestige of your humanity. I had to stop it from being destroyed. I had to see for myself. And at last I\'m sure...', 12, 0, 100, 0, 0, 0, ''),
(32239, 8, 0, 'Only shadows from the past remain. There\'s nothing left to redeem!', 12, 0, 100, 0, 0, 0, ''),
(32241, 0, 0, 'Tirion\'s down! Defend him with your lives!', 14, 0, 100, 0, 0, 0, ''),
(32310, 0, 0, 'I hope you fellows don\'t mind if we crash this party. I brought some old friends with me!', 14, 0, 100, 0, 0, 0, ''),
(32310, 1, 0, 'Looks like whatever Tirion did put some hurt on the Lich King. It\'s too bad we can\'t finish him off....', 12, 0, 100, 0, 0, 0, ''),
(32311, 0, 0, 'Take courage, crusaders. You do not fight alone!', 14, 0, 100, 0, 0, 0, ''),
(32311, 1, 0, 'The Lich King is badly hurt. We ought to stay behind and finish him.', 12, 0, 100, 0, 0, 0, ''),
(32312, 0, 0, 'Quick, through the portal! He won\'t stay down for long.', 12, 0, 100, 0, 0, 0, ''),
(32312, 1, 0, 'Patience... we will get our chance soon enough. Be content that for once, it is Tirion who is in our debt.', 12, 0, 0, 0, 0, 0, '');

delete from locales_creature_text where entry in (32239,32184,32312,32311,32310,32241);
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(32239, 0, 0, 'Время пришло. Пусть Свет дарует нам силу.'),
(32239, 1, 0, 'Ведите себя осторожно и ждите моей команды.'),
(32239, 2, 0, 'Смотрите! Вот сердце!'),
(32239, 3, 0, 'Что-то не так... я чувствую присутствие чего-то зловещего.'),
(32239, 4, 0, 'Это... Король-лич. Он здесь. Да направит Свет клинки наших мечей.'),
(32239, 5, 0, 'Слишком уж ты самоуверен! Забыл, чем закончилась наша предыдущая встреча?'),
(32239, 6, 0, 'Возможно... но мне не нужна сила святой земли, чтобы пронзить твое черное сердце Испепелителем.'),
(32239, 7, 0, 'Сердце... последнее вместилище твоей человечности. Я должен его спасти. Я должен взять все в свои руки. Наконец-то я знаю, что делать...'),
(32239, 8, 0, 'Нам остались лишь тени прошлого. Некого больше спасать!'),
(32184, 0, 0, 'Незваные гости! Вы думали, что сможете прокрасться в мои владения незамеченными?'),
(32184, 1, 0, 'Должен признаться, ваше появление небыло для меня неожиданностью. Надеюсь, вы найдете себе место упокоения по своему вкусу.'),
(32184, 2, 0, 'Во время нашей прошлой встречи у тебя было преимущество, ибо ты сражался на святой земле. Видишь ли, теперь мы поменялись местами.'),
(32184, 3, 0, 'Ты блефуешь, но я принимаю твою ставку. В конце концов, ты же паладин. Твоя жажда искупления не имеет разумных границ.'),
(32184, 4, 0, 'Вряд ли ты захочешь уничтожить последний шанс человечества ради того, чтобы спасти его заблудшего сына. Ты сам скорее умрешь!'),
(32184, 5, 0, 'Арррррргггггггггххххх!'),
(32184, 6, 0, 'Ты… заплатишь за это, старик. Убить их всех!'),
(32312, 0, 0, 'Быстрее, бегом в портал! Он долго не простоит.'),
(32312, 1, 0, 'Терпение... скоро мы получим свой шанс. Довольствуйся тем, что на сей раз Тирион пред нами в долгу, а не мы.'),
(32311, 0, 0, 'Мужайтесь, рыцари. Вы не будете сражаться одни!'),
(32311, 1, 0, 'Король-лич тяжело ранен. Мы должны остаться и добить его!'),
(32310, 0, 0, 'Надеюсь, твои приятели не возражают, если мы немного попортим эту вечеринку. Я привел с собой особого гостя!'),
(32310, 1, 0, 'Что бы ни сделал Тирион, похоже, он сумел ранить Короля-Лича. Как жаль, что мы не можем добить его...'),
(32241, 0, 0, 'Тирион повержен! Защитите его любой ценой, даже ценой ваших жизней!');