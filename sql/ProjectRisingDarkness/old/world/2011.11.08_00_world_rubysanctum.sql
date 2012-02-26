-- immunities for trash
UPDATE creature_template SET mechanic_immune_mask=534724095 WHERE entry IN(40417,40418,40419,40420,40421,40422,40423,40424);
-- immunities for bosses
UPDATE creature_template SET mechanic_immune_mask=1071595519 WHERE entry IN(39747,39823,39751,39899,39920,39922,39863,39864,40142,39944,39945,40143,40144,40145,39746,49805);
-- zarithian elites
UPDATE creature_template SET mechanic_immune_mask=534722559 WHERE entry IN(39815,39814);
-- template updates
UPDATE creature_template SET unit_flags=2 WHERE entry IN(39751,39920,39746,39805);
UPDATE creature_addon SET auras='',path_id=0 WHERE guid IN(SELECT guid FROM creature WHERE id IN(37951,39920));
UPDATE creature_template SET flags_extra =130 WHERE entry =26712;
-- flags for zarithrian
UPDATE creature_template SET unit_flags=2 WHERE entry IN(39746,39805);
DELETE FROM creature WHERE id =39794;
INSERT INTO creature VALUES
(397941,39794,724,15,1,16925,0,3043.649170,452.039093,85.533585,0,604800,0,0,12600,0,0,0,0,0),
(397942,39794,724,15,1,16925,0,3048.162109,601.734741,86.851151,0,604800,0,0,12600,0,0,0,0,0);
UPDATE creature_template SET unit_flags=33554434 WHERE entry IN(39814,39815);
-- deathstate aura for sanctum wardens
DELETE FROM creature_addon WHERE guid IN(112656,112661);
INSERT INTO creature_addon VALUES 
(112656,0,0,0,0,65,'29266'),
(112661,0,0,0,0,65,'29266');

-- Ruby sanctum
UPDATE `instance_template` SET `Script`='instance_ruby_sanctum' WHERE `map`=724;
-- Halion
UPDATE `creature_template` SET `ScriptName`='boss_halion_real', `AIName` ='' WHERE `entry`=39863;
UPDATE `creature_template` SET `ScriptName`='boss_halion_twilight', `AIName` ='' WHERE `entry`=40142;
UPDATE `creature_template` SET `ScriptName`='mob_halion_meteor', `AIName` ='' WHERE `entry` = 40029;
UPDATE `creature_template` SET `ScriptName`='mob_halion_flame', `AIName` ='' WHERE `entry` IN (40041);
UPDATE `creature_template` SET `ScriptName`='mob_halion_control', `AIName` ='' WHERE `entry` IN (40146);
UPDATE `creature_template` SET `ScriptName`='mob_halion_orb', `AIName` ='' WHERE `entry` IN (40083,40100);
UPDATE `creature_template` SET `ScriptName`='mob_orb_rotation_focus', `AIName` ='' WHERE `entry` = 40091;
UPDATE `creature_template` SET `ScriptName`='mob_orb_carrier', `AIName` ='' WHERE `entry` = 40081;
UPDATE `creature_template` SET `ScriptName`='mob_fiery_combustion', `AIName` ='' WHERE `entry` = 40001;
UPDATE `creature_template` SET `ScriptName`='mob_soul_consumption', `AIName` ='' WHERE `entry` = 40135;
UPDATE `creature_template` SET `ScriptName`='', `AIName` ='' WHERE `entry` IN (40143, 40144, 40145);

-- spell_halion_fiery_combustion 74562
DELETE FROM `spell_script_names` WHERE `spell_id`=74562 AND `ScriptName`='spell_halion_fiery_combustion';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74562,'spell_halion_fiery_combustion');

-- spell_halion_soul_consumption 74792
DELETE FROM `spell_script_names` WHERE `spell_id`=74792 AND `ScriptName`='spell_halion_soul_consumption';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74792,'spell_halion_soul_consumption');

-- spell_baltharus_enervaring_brand 74502
DELETE FROM `spell_script_names` WHERE `spell_id`= 74502 AND `ScriptName`='spell_baltharus_enervating_brand';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74502,'spell_baltharus_enervating_brand');

-- spell_baltharus_enervaring_brand_trigger 74505
DELETE FROM `spell_script_names` WHERE `spell_id`= 74505 AND `ScriptName`='spell_baltharus_enervating_brand_trigger';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74505,'spell_baltharus_enervating_brand_trigger');

-- spell_intimdating_roar 74384
DELETE FROM `spell_script_names` WHERE `spell_id`= 74384 AND `ScriptName`='spell_intimdating_roar';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74384,'spell_intimdating_roar');

UPDATE `gameobject_template` SET `data10` = 74807, `faction` = '0', `ScriptName` = 'go_halion_portal_twilight' WHERE `gameobject_template`.`entry` IN (202794,202795);
UPDATE `gameobject_template` SET `faction` = '0', `ScriptName` = 'go_halion_portal_real' WHERE `gameobject_template`.`entry` IN (202796);

-- Baltharus
UPDATE `creature_template` SET `ScriptName`='boss_baltharus', `AIName` ='', `dmg_multiplier` = 80  WHERE `entry`=39751;
UPDATE `creature_template` SET `ScriptName`='mob_baltharus_clone', `AIName` ='', `dmg_multiplier` = 80  WHERE `entry`=39899;


-- zarithrian
UPDATE `creature_template` SET `ScriptName`='boss_zarithrian', `AIName` ='' WHERE `entry`=39746;
UPDATE `creature` SET `position_x` = '3008.552734',`position_y` = '530.471680',`position_z` = '89.195290',`orientation` = '6.16' WHERE `id` = 39746;
UPDATE `creature_template` SET `ScriptName`='npc_onyx_flamecaller', `AIName` ='' WHERE `entry`=39814;

-- Saviana Ragefire
UPDATE `creature_template` SET `ScriptName`='boss_ragefire', `AIName` ='' WHERE `entry`=39747;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=74455 AND `ConditionTypeOrReference`=18 AND `ConditionValue2`=39747;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13,0,74455,0,18,1,39747,0,0, '', 'Ragefire - Conflagration');

-- Xerestrasza
UPDATE `creature_template` SET `ScriptName`='mob_xerestrasza', `AIName` ='' WHERE `entry`=40429;

-- trash mobs
UPDATE `creature_template` SET `ScriptName`='npc_charscale_assaulter', `AIName` ='' WHERE `entry`=40417;
UPDATE `creature_template` SET `ScriptName`='npc_charscale_invoker', `AIName` ='' WHERE `entry`=40419;
UPDATE `creature_template` SET `ScriptName`='npc_charscale_elite', `AIName` ='' WHERE `entry`=40421;
UPDATE `creature_template` SET `ScriptName`='npc_charscale_commander', `AIName` ='' WHERE `entry`=40423;

-- SOME TEXT and SOUND EFECTS
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1666406 AND -1666000;

-- xerestrasza
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
('-1666000','Help! I am trapped within this tree! I require aid!','Спасите! Я под этим деревом. Мне нужна помощь!','17490','6','0','0','SAY_XERESTRASZA_YELL_1'),
('-1666001','Thank you! I could have not held out for much longer. A terrible thing has happened here.','Спасибо! Без вас я бы долго не продержалась... Здесь произошли страшные события...','17491','6','0','0','SAY_XERESTRASZA_YELL_2'),
('-1666002','We believed that the Sanctum was well fortified, but we were not prepareted for the nature of this assault.','Святилище считалось неприступным, но до сих пор оно не подвергалось такому штурму...','17492','0','0','0','SAY_XERESTRASZA_SAY_1'),
('-1666003','The Black Dragonkin materialized from thin air, and set upon us before we could react.','Черные драконы явились из ниоткуда. Мы даже не успели понять что происходит...','17493','0','0','0','SAY_XERESTRASZA_SAY_2'),
('-1666004','We did not stand a chance. As my brethren perished around me, I managed to retreat here and bar the entrance.','Силы были неравны, мои братья гибли один за другим. А я спряталась здесь и запечатала вход.','17494','0','0','0','SAY_XERESTRASZA_SAY_3'),
('-1666005','They slaughtered us with cold efficiency, but the true focus of their interest seemed to be the eggs kept here in the sanctum.','Нас убивали с расчетливой жестокостью, но основной целью врага была кладка яиц в святилище.','17495','0','0','0','SAY_XERESTRASZA_SAY_4'),
('-1666006','The commander of the forces on the ground here is a cruel brute named Zarithrian. But I fear there are greater powers at work.',' Атакой руководил кровожадный Заритриан, но, боюсь, тут замешано и более могущественное зло.','17496','0','0','0','SAY_XERESTRASZA_SAY_5'),
('-1666007','In their initial assault I caught a glimpse of their true leader, a fearsome full-grown Twilight Dragon.','В самом начале я ощутила присутствие их настоящего лидера - огромного сумеречного дракона.','17497','0','0','0','SAY_XERESTRASZA_SAY_6'),
('-1666008','I know not the extent of their plans heroes, but I know this: they cannot be allowed to succeed!','Герои, мне не ведомо чего добиваются эти захватчики. Одно я знаю точно - их нужно остановить!','17498','0','0','0','SAY_XERESTRASZA_SAY_7'),

-- Halion
('-1666100','Meddlesome insects, you\'re too late! The Ruby Sanctum is lost.','Назойливая мошкара! Вы опоздали. Рубиновое святилище пало!','17499','6','0','0','SAY_HALION_SPAWN'),
('-1666101','Your world teeters on the brink of annihilation. You will all bear witness to the coming of a new age of destruction!','Этот мир вот-вот соскользнет в бездну. Вам выпала честь узреть начало эры РАЗРУШЕНИЯ!','17500','6','0','0','SAY_HALION_AGGRO'),
('-1666102','Another hero falls.','Сколько еще таких героев?','17501','6','0','0','SAY_HALION_SLAY_1'),
('-1666103','Ha Ha Ha!','','17502','6','0','0','SAY_HALION_SLAY_2'),
('-1666104','Relish this victory mortals, for it will be your last. This world will burn with the Master\'s return!','Это ваша последняя победа. Насладитесь сполна ее вкусом. Ибо когда вернется мой господин, этот мир сгинет в огне!','17503','6','0','0','SAY_HALION_DEATH'),
('-1666105','Not good enough!','Надоело!','17504','6','0','0','SAY_HALION_BERSERK'),
('-1666106','The heavens burn!','Небеса в огне!','17505','6','0','0','SAY_HALION_SPECIAL_1'),
('-1666107','Beware the shadow!','','17506','6','0','0','SAY_HALION_SPECIAL_2'),
('-1666108','You will find only suffering within the realm of Twilight. Enter if you dare.','Вы найдете только тьму в мире Сумерек. Входите, если посмеете.','17507','6','0','0','SAY_HALION_PHASE_2'),
('-1666109','I am the light AND the darkness! Cower mortals before the Herald of Deathwing!','Я есть свет и я есть тьма! Трепещите, ничтожные, перед посланником Смертокрыла!','17508','6','0','0','SAY_HALION_PHASE_3'),
('-1666110','The orbiting spheres pulse with dark energy!','Во вращающихся сферах пульсирует темная энергия!','0','3','0','0',''),
('-1666111','Your companions effort force Halion further into the physical realm!','Ваши союзники протолкнули Халиона дальше в физический мир!','0','3','0','0',''),
('-1666112','Your companions effort force Halion further into the twilight realm!','Ваши союзники протолкнули Халиона дальше в реальный мир!','0','3','0','0',''),
('-1666113','Your efforts force Halion further out of the physical realm!','','0','3','0','0',''),
('-1666114','Your efforts force Halion further out of the twilight realm!','','0','3','0','0',''),
('-1666115','<need translate>','Находясь в покое в одном из миров, Халион восстанавливает жизненные силы.','0','3','0','0',''),

-- Zarithrian
('-1666200','Alexstrasza has chosen capable allies. A pity that I must END YOU!','Алекстраза выбрала достойных союзников... Жаль, что придется ПРИКОНЧИТЬ ВАС!','17512','6','0','0','SAY_ZARITHRIAN_AGGRO'),
('-1666201','You thought you stood a chance?','Глупо было и надеяться!','17513','6','0','0','SAY_ZARITHRIAN_SLAY_1'),
('-1666202','It\'s for the best.','Все только к лучшему!','17514','6','0','0','SAY_ZARITHRIAN_SLAY_2'),
('-1666203','Halion! I\'m...aah!','ХАЛИОН! Я...','17515','6','0','0','SAY_ZARITHRIAN_DEATH'),
('-1666204','Turn them to ash, minions!','Слуги! Обратите их в пепел!','17516','6','0','0','SAY_ZARITHRIAN_SPECIAL_1'),

-- baltharus
('-1666300','Ah, the entertainment has arrived...','А-а-а, цирк приехал.','17520','6','0','0','SAY_BALTHARUS_AGGRO'),
('-1666301','Baltharus leaves no survivors!','Балтар не оставляет живых!','17521','6','0','0','SAY_BALTHARUS_SLAY_1'),
('-1666302','This world has enough heroes!','В мире хватает героев и без тебя...','17522','6','0','0','SAY_BALTHARUS_SLAY_2'),
('-1666303','I...didn\'t see that coming...','Как… это могло произойти?..','17523','1','0','0','SAY_BALTHARUS_DEATH'),
('-1666304','Twice the pain and half the fun!','Вдвое сильнее страдание.','17524','6','0','0','SAY_BALTHARUS_SPECIAL_1'),
('-1666305','Your power wanes, ancient one! Soon, you will join your friends!','Твоя сила на исходе, Древнейшая! Скоро ты присоединишься к своим друзьям!','17525','6','0','0','SAY_BALTHARUS_YELL'),

-- saviana
('-1666400','You will suffer for this intrusion...','Ваш-ш-ши муки с-cтанут платой за это вторжение!','17528','6','0','0','SAY_SAVIANA_AGGRO'),
('-1666401','As it should be!','Так и должно быть!','17529','6','0','0','SAY_SAVIANA_SLAY_1'),
('-1666402','Halion will be pleased...','Халион будет доволен!','17530','6','0','0','SAY_SAVIANA_SLAY_2'),
('-1666403','Burn in the master\'s flame!','Горите в огне хозяина!','17532','6','0','0','SAY_SAVIANA_SPECIAL_1'),
('-1666404','Saviana Ragefire becomes enraged !','|3-3(%s) впадает в исступление!','0','2','0','0','SAY_SAVIANA_ENRAGE');


-- Ruby sanctum bosses respawn time
UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `id` IN (39863,39751,39746,39747);
UPDATE `creature_template` SET `rank` = 3 WHERE `entry` IN  (39863,39751,39746,39747);

-- Ruby Sanctum bosses id saving
UPDATE `creature_template` SET `flags_extra` = 1 WHERE `entry` IN
(39863,39864,39944,39945, -- Halion
 39751,39920, -- Baltharus
 39746,39805, -- General Zarithrian
 39747,39823); -- Saviana Ragefire
 

-- Charscale Invoker
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40417;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40418;
 -- Charscale Assaulter
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40419;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40420;
 -- Charscale Elite
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40421;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40422;
 -- Charscale Commander
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '7.5' WHERE entry =40423;
 UPDATE creature_template SET mindmg = '422',maxdmg = '586',attackpower = '642',dmg_multiplier = '12.5' WHERE entry =40424;

-- Baltharus the Warborn
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39751;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39920;

-- Baltharus Clone
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39899;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39922;

-- Saviana Ragefire
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39747;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39823;

-- General Zarithrian
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39746;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39805;

-- Halion
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =39863;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =39864;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '55' WHERE entry =39944;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '75' WHERE entry =39945;

-- Twilight Halion
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '35' WHERE entry =40142;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '45' WHERE entry =40143;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '55' WHERE entry =40144;
 UPDATE creature_template SET mindmg = '496',maxdmg = '674',attackpower = '783',dmg_multiplier = '75' WHERE entry =40145;

UPDATE creature_template SET mechanic_immune_mask = 617299803 WHERE entry IN (39751,39920,39899,39922,39747,39823,39746,39805,39863,39864,39944,39945,40142,40143,40144,40145);

UPDATE creature_template SET faction_A=103, faction_H=103, speed_walk=2, unit_flags=64 WHERE entry IN (39746,39805);

DELETE FROM creature WHERE id = 39863;
INSERT INTO creature VALUES ('250456', '39863', '724', '15', '1', '0', '0', '3144,93', '527,233', ' 72.887245', '0,110395', '604800', '0', '0', '11156000', '0', '0', '0', '0', '0');
