-- 805_world_scripts
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533039 AND -1533000;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1533000,'Ahh... welcome to my parlor.',8788,1,0,'anubrekhan SAY_GREET'),
(-1533001,'Just a little taste...',8785,1,0,'anubrekhan SAY_AGGRO1'),
(-1533002,'There is no way out.',8786,1,0,'anubrekhan SAY_AGGRO2'),
(-1533003,'Yes, Run! It makes the blood pump faster!',8787,1,0,'anubrekhan SAY_AGGRO3'),
(-1533004,'I hear little hearts beating. Yesss... beating faster now. Soon the beating will stop.',8790,1,0,'anubrekhan SAY_TAUNT1'),
(-1533005,'Where to go? What to do? So many choices that all end in pain, end in death.',8791,1,0,'anubrekhan SAY_TAUNT2'),
(-1533006,'Which one shall I eat first? So difficult to choose... the all smell so delicious.',8792,1,0,'anubrekhan SAY_TAUNT3'),
(-1533007,'Closer now... tasty morsels. I\'ve been too long without food. Without blood to drink.',8793,1,0,'anubrekhan SAY_TAUNT4'),
(-1533008,'Shh... it will all be over soon.',8789,1,0,'anubrekhan SAY_SLAY'),
(-1533009,'Your old lives, your mortal desires, mean nothing. You are acolytes of the master now, and you will serve the cause without question! The greatest glory is to die in the master\'s service!',8799,1,0,'faerlina SAY_GREET'),
(-1533010,'Slay them in the master\'s name!',8794,1,0,'faerlina SAY_AGGRO1'),
(-1533011,'You cannot hide from me!',8795,1,0,'faerlina SAY_AGGRO2'),
(-1533012,'Kneel before me, worm!',8796,1,0,'faerlina SAY_AGGRO3'),
(-1533013,'Run while you still can!',8797,1,0,'faerlina SAY_AGGRO4'),
(-1533014,'You have failed!',8800,1,0,'faerlina SAY_SLAY1'),
(-1533015,'Pathetic wretch!',8801,1,0,'faerlina SAY_SLAY2'),
(-1533016,'The master... will avenge me!',8798,1,0,'faerlina SAY_DEATH'),
(-1533017,'Patchwerk want to play!',8909,1,0,'patchwerk SAY_AGGRO1'),
(-1533018,'Kel\'Thuzad make Patchwerk his Avatar of War!',8910,1,0,'patchwerk SAY_AGGRO2'),
(-1533019,'No more play?',8912,1,0,'patchwerk SAY_SLAY'),
(-1533020,'What happened to... Patch...',8911,1,0,'patchwerk SAY_DEATH'),
(-1533021,'goes into a berserker rage!',0,2,0,'patchwerk EMOTE_BERSERK'),
(-1533022,'becomes enraged!',0,2,0,'patchwerk EMOTE_ENRAGE'),
(-1533023,'Stalagg crush you!',8864,1,0,'stalagg SAY_STAL_AGGRO'),
(-1533024,'Stalagg kill!',8866,1,0,'stalagg SAY_STAL_SLAY'),
(-1533025,'Master save me...',8865,1,0,'stalagg SAY_STAL_DEATH'),
(-1533026,'Feed you to master!',8802,1,0,'feugen SAY_FEUG_AGGRO'),
(-1533027,'Feugen make master happy!',8804,1,0,'feugen SAY_FEUG_SLAY'),
(-1533028,'No... more... Feugen...',8803,1,0,'feugen SAY_FEUG_DEATH'),
(-1533029,'You are too late... I... must... OBEY!',8872,1,0,'thaddius SAY_GREET'),
(-1533030,'KILL!',8867,1,0,'thaddius SAY_AGGRO1'),
(-1533031,'EAT YOUR BONES!',8868,1,0,'thaddius SAY_AGGRO2'),
(-1533032,'BREAK YOU!',8869,1,0,'thaddius SAY_AGGRO3'),
(-1533033,'You die now!',8877,1,0,'thaddius SAY_SLAY'),
(-1533034,'Now YOU feel pain!',8871,1,0,'thaddius SAY_ELECT'),
(-1533035,'Thank... you...',8870,1,0,'thaddius SAY_DEATH'),
(-1533036,'Pleeease!',8873,1,0,'thaddius SAY_SCREAM1'),
(-1533037,'Stop, make it stop!',8874,1,0,'thaddius SAY_SCREAM2'),
(-1533038,'Help me! Save me!',8875,1,0,'thaddius SAY_SCREAM3'),
(-1533039,'Please, nooo!',8876,1,0,'thaddius SAY_SCREAM4');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533074 AND -1533040;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1533040,'Foolishly you have sought your own demise. Brazenly you have disregarded powers beyond your understanding. You have fought hard to invade the realm of the harvester. Now there is only one way out - to walk the lonely path of the damned.',8807,1,0,'gothik SAY_SPEECH'),
(-1533041,'Death is the only escape.',8806,1,0,'gothik SAY_KILL'),
(-1533042,'I... am... undone!',8805,1,0,'gothik SAY_DEATH'),
(-1533043,'I have waited long enough! Now, you face the harvester of souls!',8808,1,0,'gothik SAY_TELEPORT'),
(-1533044,'Defend youself!',8892,1,0,'blaumeux SAY_BLAU_AGGRO'),
(-1533045,'Come, Zeliek, do not drive them out. Not before we\'ve had our fun.',8896,1,0,'blaumeux SAY_BLAU_TAUNT1'),
(-1533046,'I do hope they stay alive long enough for me to... introduce myself.',8897,1,0,'blaumeux SAY_BLAU_TAUNT2'),
(-1533047,'The first kill goes to me! Anyone care to wager?',8898,1,0,'blaumeux SAY_BLAU_TAUNT3'),
(-1533048,'Your life is mine!',8895,1,0,'blaumeux SAY_BLAU_SPECIAL'),
(-1533049,'Who\'s next?',8894,1,0,'blaumeux SAY_BLAU_SLAY'),
(-1533050,'Tou... che!',8893,1,0,'blaumeux SAY_BLAU_DEATH'),
(-1533051,'Come out and fight, ye wee ninny!',8899,1,0,'korthazz SAY_KORT_AGGRO'),
(-1533052,'To arms, ye roustabouts! We\'ve got company!',8903,1,0,'korthazz SAY_KORT_TAUNT1'),
(-1533053,'I heard about enough of yer sniveling. Shut yer fly trap \'afore I shut it for ye!',8904,1,0,'korthazz SAY_KORT_TAUNT2'),
(-1533054,'I\'m gonna enjoy killin\' these slack-jawed daffodils!',8905,1,0,'korthazz SAY_KORT_TAUNT3'),
(-1533055,'I like my meat extra crispy!',8901,1,0,'korthazz SAY_KORT_SPECIAl'),
(-1533056,'Next time, bring more friends!',8902,1,0,'korthazz SAY_KORT_SLAY'),
(-1533057,'What a bloody waste this is!',8900,1,0,'korthazz SAY_KORT_DEATH'),
(-1533058,'Flee, before it\'s too late!',8913,1,0,'zeliek SAY_ZELI_AGGRO'),
(-1533059,'Invaders, cease this foolish venture at once! Turn away while you still can!',8917,1,0,'zeliek SAY_ZELI_TAUNT1'),
(-1533060,'Perhaps they will come to their senses, and run away as fast as they can!',8918,1,0,'zeliek SAY_ZELI_TAUNT2'),
(-1533061,'Do not continue! Turn back while there\'s still time!',8919,1,0,'zeliek SAY_ZELI_TAUNT3'),
(-1533062,'I- I have no choice but to obey!',8916,1,0,'zeliek SAY_ZELI_SPECIAL'),
(-1533063,'Forgive me!',8915,1,0,'zeliek SAY_ZELI_SLAY'),
(-1533064,'It is... as it should be.',8914,1,0,'zeliek SAY_ZELI_DEATH'),
(-1533065,'You seek death?',14571,1,0,'rivendare_naxx SAY_RIVE_AGGRO1'),
(-1533066,'None shall pass!',14572,1,0,'rivendare_naxx SAY_RIVE_AGGRO2'),
(-1533067,'Be still!',14573,1,0,'rivendare_naxx SAY_RIVE_AGGRO3'),
(-1533068,'You will find no peace in death.',14574,1,0,'rivendare_naxx SAY_RIVE_SLAY1'),
(-1533069,'The master\'s will is done.',14575,1,0,'rivendare_naxx SAY_RIVE_SLAY2'),
(-1533070,'Bow to the might of the scourge!',14576,1,0,'rivendare_naxx SAY_RIVE_SPECIAL'),
(-1533071,'Enough prattling. Let them come! We shall grind their bones to dust.',14577,1,0,'rivendare_naxx SAY_RIVE_TAUNT1'),
(-1533072,'Conserve your anger! Harness your rage! You will all have outlets for your frustration soon enough.',14578,1,0,'rivendare_naxx SAY_RIVE_TAUNT2'),
(-1533073,'Life is meaningless. It is in death that we are truly tested.',14579,1,0,'rivendare_naxx SAY_RIVE_TAUNT3'),
(-1533074,'Death... will not stop me...',14580,1,0,'rivendare_naxx SAY_RIVE_DEATH');

UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=16062;
UPDATE `creature_template` SET `ScriptName`='boss_rivendare_naxx' WHERE `entry`=30549;

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533108 AND -1533075;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1533075,'Glory to the master!',8845,1,0,'noth SAY_AGGRO1'),
(-1533076,'Your life is forfeit!',8846,1,0,'noth SAY_AGGRO2'),
(-1533077,'Die, trespasser!',8847,1,0,'noth SAY_AGGRO3'),
(-1533078,'Rise, my soldiers! Rise and fight once more!',8851,1,0,'noth SAY_SUMMON'),
(-1533079,'My task is done!',8849,1,0,'noth SAY_SLAY1'),
(-1533080,'Breathe no more!',8850,1,0,'noth SAY_SLAY2'),
(-1533081,'I will serve the master... in... death!',8848,1,0,'noth SAY_DEATH'),
(-1533082,'takes in a deep breath...',0,2,0,'sapphiron EMOTE_BREATH'),
(-1533083,'enrages!',0,2,0,'sapphiron EMOTE_ENRAGE'),
(-1533084,'Our preparations continue as planned, master.',14467,1,0,'kelthuzad SAY_SAPP_DIALOG1'),
(-1533085,'It is good that you serve me so faithfully. Soon, all will serve the Lich King and in the end, you shall be rewarded...so long as you do not falter.',8881,1,0,'kelthuzad SAY_SAPP_DIALOG2_LICH'),
(-1533086,'I see no complications... Wait... What is this?',14468,1,0,'kelthuzad SAY_SAPP_DIALOG3'),
(-1533087,'Your security measures have failed! See to this interruption immediately!',8882,1,0,'kelthuzad SAY_SAPP_DIALOG4_LICH'),
(-1533088,'Yes, master!',14469,1,0,'kelthuzad SAY_SAPP_DIALOG5'),
(-1533089,'No!!! A curse upon you, interlopers! The armies of the Lich King will hunt you down. You will not escape your fate...',14484,1,0,'kelthuzad SAY_CAT_DIED'),
(-1533090,'Who dares violate the sanctity of my domain? Be warned, all who trespass here are doomed.',14463,1,0,'kelthuzad SAY_TAUNT1'),
(-1533091,'Fools, you think yourselves triumphant? You have only taken one step closer to the abyss! ',14464,1,0,'kelthuzad SAY_TAUNT2'),
(-1533092,'I grow tired of these games. Proceed, and I will banish your souls to oblivion!',14465,1,0,'kelthuzad SAY_TAUNT3'),
(-1533093,'You have no idea what horrors lie ahead. You have seen nothing! The frozen heart of Naxxramas awaits you!',14466,1,0,'kelthuzad SAY_TAUNT4'),
(-1533094,'Pray for mercy!',14475,1,0,'kelthuzad SAY_AGGRO1'),
(-1533095,'Scream your dying breath!',14476,1,0,'kelthuzad SAY_AGGRO2'),
(-1533096,'The end is upon you!',14477,1,0,'kelthuzad SAY_AGGRO3'),
(-1533097,'The dark void awaits you!',14478,1,0,'kelthuzad SAY_SLAY1'),
(-1533098,'<Kel\'Thuzad cackles maniacally!>',14479,1,0,'kelthuzad SAY_SLAY2'),
(-1533099,'AAAAGHHH!... Do not rejoice... your victory is a hollow one... for I shall return with powers beyond your imagining!',14480,1,0,'kelthuzad SAY_DEATH'),
(-1533100,'Your soul, is bound to me now!',14472,1,0,'kelthuzad SAY_CHAIN1'),
(-1533101,'There will be no escape!',14473,1,0,'kelthuzad SAY_CHAIN2'),
(-1533102,'I will freeze the blood in your veins!',14474,1,0,'kelthuzad SAY_FROST_BLAST'),
(-1533103,'Master! I require aid! ',14470,1,0,'kelthuzad SAY_REQUEST_AID'),
(-1533104,'Very well... warriors of the frozen wastes, rise up! I command you to fight, kill, and die for your master. Let none survive...',0,1,0,'kelthuzad SAY_ANSWER_REQUEST'),
(-1533105,'Minions, servants, soldiers of the cold dark, obey the call of Kel\'Thuzad!',14471,1,0,'kelthuzad SAY_SUMMON_MINIONS'),
(-1533106,'Your petty magics are no challenge to the might of the Scourge! ',14481,1,0,'kelthuzad SAY_SPECIAL1_MANA_DET'),
(-1533107,'Enough! I grow tired of these distractions! ',14483,1,0,'kelthuzad SAY_SPECIAL3_MANA_DET'),
(-1533108,'Fools, you have spread your powers too thin. Be free, my minions!',14482,1,0,'kelthuzad SAY_SPECIAL2_DISPELL');
	
UPDATE `script_texts` SET `sound`=8902 WHERE `entry`=-1533055;
UPDATE `script_texts` SET `sound`=8901 WHERE `entry`=-1533056;

-- 1028_mangos_7141_01_world_instance_template
ALTER TABLE instance_template ADD maxPlayersHeroic tinyint(3) unsigned NOT NULL default '0' AFTER maxPlayers;
UPDATE instance_template SET maxPlayersHeroic = maxPlayers;
DELETE FROM instance_template WHERE map IN (533,615,616,624);
INSERT INTO instance_template VALUES
(533,0,80,0,10,25,0,NULL,NULL,NULL,NULL,''),
(615,0,80,0,10,25,0,NULL,NULL,NULL,NULL,''),
(616,0,80,0,10,25,0,NULL,NULL,NULL,NULL,''),
(624,0,80,0,10,25,0,NULL,NULL,NULL,NULL,'');

-- 1028_mangos_7147_01_world_creature_template
UPDATE creature_template
  SET family = 0 WHERE entry = 1;

-- 1028_mangos_7150_01_world_playercreateinfo_spell
DELETE FROM `playercreateinfo_spell` WHERE Spell = 58284;
INSERT INTO `playercreateinfo_spell` VALUES
(1,9,58284,'Chaos Bolt Passive'),
(2,9,58284,'Chaos Bolt Passive'),
(5,9,58284,'Chaos Bolt Passive'),
(7,9,58284,'Chaos Bolt Passive'),
(10,9,58284,'Chaos Bolt Passive');

-- 1084_mangos_7168_01_world_command
DELETE FROM `command` WHERE `name` IN ('learn','unlearn');
INSERT INTO `command` VALUES
('learn',3,'Syntax: .learn #spell [all]\r\n\r\nSelected character learn a spell of id #spell. If \'all\' provided then all ranks learned.'),
('unlearn',3,'Syntax: .unlearn #spell [all]\r\n\r\nUnlearn for selected player a spell #spell.  If \'all\' provided then all ranks unlearned.');

-- 1094_mangos_7193_01_world_trinity_string
UPDATE trinity_string SET content_default = 'Unit Flags: %u.\nDynamic Flags: %u.\nFaction Template: %u.' WHERE entry = 542;

-- 1108_mangos_7196_02_world_spell_bonus_data
-- ----------------------------
-- Table structure for spell_bonus_data
-- ----------------------------
DROP TABLE IF EXISTS `spell_bonus_data`;
CREATE TABLE `spell_bonus_data` (
  `entry` smallint(5) unsigned NOT NULL,
  `direct_bonus` float NOT NULL default '0',
  `dot_bonus` float NOT NULL default '0',
  `ap_bonus` float NOT NULL default '0',
  `comments` varchar(255) default NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_bonus_data` VALUES
('5185', '1.6104', '0', '0', 'Druid - Healing Touch'),
('33763', '0', '0.09518', '0', 'Druid - Lifebloom'),
('774', '0', '0.37604', '0', 'Druid - Rejuvenation'),
('8936', '0.539', '0.188', '0', 'Druid - Regrowth'),
('18562', '0', '0', '0', 'Druid - Swiftmend'),
('44203', '0.538', '0', '0', 'Druid - Tranquility Triggered'),
('48438', '0', '0.11505', '0', 'Druid - Wild Growth'),
('50464', '0.6611', '0', '0', 'Druid - Nourish'),
('339', '0', '0.1', '0', 'Druid - Entangling Roots'),
('42231', '0.12898', '0', '0', 'Druid - Hurricane Triggered'),
('5570', '0', '0.127', '0', 'Druid - Insect Swarm'),
('8921', '0.1515', '0.13', '0', 'Druid - Moonfire'),
('2912', '1', '0', '0', 'Druid - Starfire'),
('5176', '0.5714', '0', '0', 'Druid - Wrath'),
('30451', '0.7143', '0', '0', 'Mage - Arcane Blast'),
('1449', '0.2128', '0', '0', 'Mage - Arcane Explosion'),
('7268', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 1'),
('7269', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 2'),
('7270', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 3'),
('8419', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 4'),
('8418', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 5'),
('10273', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 6'),
('10274', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 7'),
('25346', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 8'),
('27076', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 9'),
('38700', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 10'),
('38703', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 11'),
('42844', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 12'),
('42845', '0.2857', '0', '0', 'Mage - Arcane Missiles Triggered Spell Rank 13'),
('1463', '0.8053', '0', '0', 'Mage - Mana Shield'),
('44425', '0.8571', '0', '0', 'Mage - Arcane Barrage'),
('11113', '0.1357', '0', '0', 'Mage - Blast Wave Rank'),
('31661', '0.1357', '0', '0', 'Mage - Dragons Breath'),
('2136', '0.4286', '0', '0', 'Mage - Fire Blast'),
('133', '1', '0', '0', 'Mage - Fire Ball'),
('2120', '0.2357', '0.122', '0', 'Mage - Flamestrike'),
('11366', '1.15', '0.05', '0', 'Mage - Pyroblast'),
('2948', '0.4286', '0', '0', 'Mage - Scorch'),
('44614', '0.8571', '0', '0', 'Frostfire Bolt'),
('44457', '0.4', '0.2', '0', 'Mage - Living Bomb'),
('42208', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 1'),
('42209', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 2'),
('42210', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 3'),
('42211', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 4'),
('42212', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 5'),
('42213', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 6'),
('42198', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 7'),
('42937', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 8'),
('42938', '0.0952', '0', '0', 'Mage - Blizzard Triggered Spell Rank 9'),
('120', '0.1357', '0', '0', 'Mage - Cone of Cold'),
('122', '0.193', '0', '0', 'Mage - Frost Nova'),
('116', '0.8143', '0', '0', 'Mage - Frost Bolt'),
('11426', '0.8053', '0', '0', 'Mage - Ice Barrier'),
('30455', '0.1429', '0', '0', 'Mage - Ice Lance'),
('19750', '0.4286', '0', '0', 'Paladin - Flash of Light'),
('635', '0.7143', '0', '0', 'Paladin - Holy Light'),
('25912', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 1'),
('25911', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 2'),
('25902', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 3'),
('27176', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 4'),
('33073', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 5'),
('48822', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 6'),
('48823', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Hurt Rank 7'),
('25914', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 1'),
('25913', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 2'),
('25903', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 3'),
('27175', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 4'),
('33074', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 5'),
('48820', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 6'),
('48821', '0.4286', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 7'),
('31935', '0.07', '0', '0.07', 'Paladin - Avengers Shiled'),
('26573', '0', '0.04', '0.04', 'Paladin - Consecration'),
('879', '0.15', '0', '0.15', 'Paladin - Exorcism'),
('24275', '0.15', '0', '0.15', 'Paladin - Hammer of Wrath'),
('20925', '0.09', '0', '0.056', 'Paladin - Holy Shield'),
('2812', '0.07', '0', '0.07', 'Paladin - Holy Wrath'),
('31893', '0.25', '0', '0.16', 'Paladin - Seal of Blood Enemy Proc'),
('32221', '0.25', '0', '0.16', 'Paladin - Seal of Blood Self Proc'),
('20424', '0.25', '0', '0.16', 'Paladin - Seal of Command Proc'),
('379', '0', '0', '0', 'Shaman - Earth Shield Triggered'),
('20167', '0.25', '0', '0.16', 'Paladin - Seal of Light Proc'),
('53719', '0.25', '0', '0.16', 'Paladin - Seal of The Martyr Enemy Proc'),
('53718', '0.25', '0', '0.16', 'Paladin - Seal of The Martyr Self Proc'),
('25742', '0.07', '0', '0.039', 'Paladin - Seal of Righteousness Dummy Proc'),
('31803', '0', '0.013', '0.15', 'Paladin - Holy Vengeance'),
('52042', '0.045', '0', '0', 'Shaman - Healing Stream Totem Triggered Heal'),
('32546', '0.8068', '0', '0', 'Priest - Binding Heal'),
('34861', '0.402', '0', '0', 'Priest - Circle of Healing'),
('19236', '0.8068', '0', '0', 'Priest - Desperate Prayer'),
('2061', '0.8068', '0', '0', 'Priest - Flash Heal'),
('2060', '1.6135', '0', '0', 'Priest - Greater Heal'),
('23455', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 1'),
('23458', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 2'),
('23459', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 3'),
('27803', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 4'),
('27804', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 5'),
('27805', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 6'),
('25329', '0.3035', '0', '0', 'Priest - Holy Nova Heal Rank 7'),
('17', '0.8068', '0', '0', 'Priest - Power Word: Shield'),
('596', '0.8086', '0', '0', 'Priest - Prayer of Healing'),
('33110', '0.8068', '0', '0', 'Priest - Prayer of Mending Heal Proc'),
('139', '1.88', '0', '0', 'Priest - Renew'),
('2944', '0.1849', '0', '0', 'Priest - Devouring Plague'),
('14914', '0.5711', '0.024', '0', 'Priest - Holy Fire'),
('15237', '0.1606', '0', '0', 'Priest - Holy Nova Damage'),
('8129', '0', '0', '0', 'Priest - Mana Burn'),
('8092', '0.4296', '0', '0', 'Priest - Mind Blast'),
('15407', '0.257', '0', '0', 'Priest - Mind Flay'),
('49821', '0.7143', '0', '0', 'Priest - Mind Sear Trigger Rank 1'),
('53022', '0.7143', '0', '0', 'Priest - Mind Sear Trigger Rank 2'),
('34433', '0.65', '0', '0', 'Priest - Shadowfiend'),
('32379', '0.4296', '0', '0', 'Priest - Shadow Word: Death'),
('589', '0', '0.1829', '0', 'Priest - Shadow Word: Pain'),
('585', '0.714', '0', '0', 'Priest - Smite'),
('34914', '0', '0.4', '0', 'Priest - Vampiric Touch'),
('974', '0.4762', '0', '0', 'Shaman - Earth Shield'),
('1064', '1.34', '0', '0', 'Shaman - Chain Heal'),
('331', '1.6106', '0', '0', 'Shaman - Healing Wave'),
('8004', '0.8082', '0', '0', 'Shaman - Lesser Healing Wave'),
('61295', '0.4', '0.18', '0', 'Shaman - Riptide'),
('421', '0.57', '0', '0', 'Shaman - Chain Lightning'),
('8042', '0.3858', '0', '0', 'Shaman - Earth Shock'),
('8443', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 1'),
('8504', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 2'),
('8505', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 3'),
('11310', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 4'),
('11311', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 5'),
('25538', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 6'),
('25539', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 7'),
('61651', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 8'),
('61660', '0.2142', '0', '0', 'Shaman - Fire Nova Totem Casted by Totem Rank 9'),
('8050', '0.2142', '0.1', '0', 'Shaman - Flame Shock'),
('8026', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 1'),
('8028', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 2'),
('8029', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 3'),
('10445', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 4'),
('16343', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 5'),
('16344', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 6'),
('25488', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 7'),
('58786', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 8'),
('58787', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 9'),
('58788', '0.1', '0', '0', 'Shaman - Flametongue Weapon Proc Rank 10'),
('8056', '0.3858', '0', '0', 'Shaman - Frost Shock'),
('8034', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 1'),
('8037', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 2'),
('10458', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 3'),
('16352', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 4'),
('16353', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 5'),
('25501', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 6'),
('58797', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 7'),
('58798', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 8'),
('58799', '0.1', '0', '0', 'Shaman - Frostbrand Attack Rank 9'),
('51505', '0.5714', '0', '0', 'Shaman - Lava Burst'),
('403', '0.7143', '0', '0', 'Shaman - Lightning Bolt'),
('26364', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 1'),
('26365', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 2'),
('26366', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 3'),
('26367', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 4'),
('26369', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 5'),
('26370', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 6'),
('26363', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 7'),
('26371', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 8'),
('26372', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 9'),
('49278', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 10'),
('49279', '0.33', '0', '0', 'Shaman - Lightning Shield Proc Rank 11'),
('8188', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 1'),
('10582', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 2'),
('10583', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 3'),
('10584', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 4'),
('25551', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 5'),
('58733', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 6'),
('58736', '0.1', '0', '0', 'Shaman - Magma Totam Passive Rank 7'),
('3606', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 1'),
('6350', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 2'),
('6351', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 3'),
('6352', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 4'),
('10435', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 5'),
('10436', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 6'),
('25530', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 7'),
('58700', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 8'),
('58701', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 9'),
('58702', '0.1667', '0', '0', 'Shaman - Searing Totem Attack Rank 10'),
('980', '0', '0.1', '0', 'Warlock - Curse of Agony'),
('603', '0', '2', '0', 'Warlock - Curse of Doom'),
('172', '0', '0.3', '0', 'Warlock - Corruption'),
('348', '0.2', '0.2', '0', 'Warlock - Immolate'),
('27243', '0.22', '0.25', '0', 'Warlock - Seed of Corruption'),
('18265', '0', '1', '0', 'Warlock - Siphon Life'),
('30108', '0', '0.24', '0', 'Warlock - Unstable Affliction'),
('17962', '0.4286', '0', '0', 'Warlock - Conflagrate'),
('6789', '0.22', '0', '0', 'Warlock - Death Coil'),
('48181', '0.4729', '0', '0', 'Warlock - Haunt'),
('29722', '0.7143', '0', '0', 'Warlock - Incinerate'),
('5676', '0.4286', '0', '0', 'Warlock - Searing Pain'),
('686', '0.8571', '0', '0', 'Warlock - Shadow Bolt'),
('17877', '0.4286', '0', '0', 'Warlock - Shadowburn'),
('30283', '0.195', '0', '0', 'Warlock - Shadowfury'),
('6353', '1.15', '0', '0', 'Warlock - Soul Fire'),
('689', '0', '0.1428', '0', 'Warlock - Drain Life'),
('5138', '0', '0', '0', 'Warlock - Drain Mana'),
('1120', '0', '0.4286', '0', 'Warlock - Drain Soul'),
('755', '0', '0.4485', '0', 'Warlock - Health Funnel'),
('1949', '0', '0.0946', '0', 'Warlock - Hellfire'),
('5857', '0.1428', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 1'),
('11681', '0.1428', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 2'),
('11682', '0.1428', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 3'),
('27214', '0.1428', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 4'),
('47822', '0.1428', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 5'),
('42223', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 1'),
('42224', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 2'),
('42225', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 3'),
('42226', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 4'),
('42218', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 5'),
('47817', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 6'),
('47818', '0.952', '0', '0', 'Warlock - Rain of Fire Triggered Rank 7'),
('18220', '0.96', '0', '0', 'Warlock - Dark Pact'),
('6229', '0.3', '0', '0', 'Warlock - Shadow Ward');

-- 1108_mangos_7199_01_world_spell_bonus_data
DELETE FROM `spell_bonus_data` WHERE `entry` IN (44614, 139, 49821, 53022, 18265, 31117, 28176);
INSERT INTO `spell_bonus_data` VALUES
('44614', '0.8571', '0', '0', 'Mage - Frostfire Bolt'),
('139', '0', '0.376', '0', 'Priest - Renew'),
('49821', '0.14286', '0', '0', 'Priest - Mind Sear Trigger Rank 1'),
('53022', '0.14286', '0', '0', 'Priest - Mind Sear Trigger Rank 2'),
('18265', '0', '0.1', '0', 'Warlock - Siphon Life'),
('31117', '1.8', '0', '0', 'Warlock - Unstable Affliction Dispell'),
('28176', '0', '0', '0', 'Warlock - Fel Armor');

-- 1135_mangos_7207_01_world_creature
ALTER TABLE creature
  ADD COLUMN `phaseMask` smallint(5) unsigned NOT NULL default '1' AFTER `spawnMask`;
  
-- 1135_mangos_7207_02_world_gameobject
ALTER TABLE gameobject
  ADD COLUMN `phaseMask` smallint(5) unsigned NOT NULL default '1' AFTER `spawnMask`;
  
-- 1140_mangos_7209_01_world_spell_bonus_data
DELETE FROM `spell_bonus_data` WHERE `entry` IN (53595);
INSERT INTO `spell_bonus_data` VALUES
('53595', '0', '0', '0','Paladin - Hammer of the Righteous');

-- 1185_mangos_7214_01_world_command
DELETE FROM `command` WHERE `name` IN ('gps','modify phase','npc phase','gobject phase');
INSERT INTO `command` VALUES
('gps',1,'Syntax: .gps [$name|$shift-link]\r\n\r\nDisplay the position information for a selected character or creature (also if player name $name provided then for named player, or if creature/gameobject shift-link provided then pointed creature/gameobject if it loaded). Position information includes X, Y, Z, and orientation, map Id and zone Id'),
('modify phase',3,'Syntax: .modify phase #phasemask\r\n\r\nSelected character phasemask changed to #phasemask with related world vision update. Change active until in game phase changed, or GM-mode enable/disable, or re-login. Character pts pasemask update to same value.'),
('npc phase',3,'Syntax: .npc phase #phasemask\r\n\r\nSelected unit or pet phasemask changed to #phasemask with related world vision update for players. In creature case state saved to DB and persistent. In pet case change active until in game phase changed for owner, owner re-login, or GM-mode enable/disable..'),
('gobject phase',3,'Syntax: .gobject phase #guid #phasemask\r\n\r\nGameobject with DB guid #guid phasemask changed to #phasemask with related world vision update for players. Gameobject state saved to DB and persistent.');

-- 1185_mangos_7214_02_world_trinity_string
DELETE FROM `trinity_string` WHERE entry = 101;
INSERT INTO `trinity_string` VALUES
(101,'Map: %u (%s) Zone: %u (%s) Area: %u (%s) Phase: %u\nX: %f Y: %f Z: %f Orientation: %f\ngrid[%u,%u]cell[%u,%u] InstanceID: %u\n ZoneX: %f ZoneY: %f\nGroundZ: %f FloorZ: %f Have height data (Map: %u VMap: %u)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1185_mangos_7214_03_world_spell_proc_event
DROP TABLE IF EXISTS `spell_proc_event`;
CREATE TABLE IF NOT EXISTS `spell_proc_event` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `SchoolMask` tinyint(4) NOT NULL default '0',
  `SpellFamilyName` smallint(5) unsigned NOT NULL default '0',
  `SpellFamilyMask0` int(10) unsigned NOT NULL default '0',
  `SpellFamilyMask1` int(10) unsigned NOT NULL default '0',
  `SpellFamilyMask2` int(10) unsigned NOT NULL default '0',
  `procFlags` int(10) unsigned NOT NULL default '0',
  `procEx` int(10) unsigned NOT NULL default '0',
  `ppmRate` float NOT NULL default '0',
  `CustomChance` float NOT NULL default '0',
  `Cooldown` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(324, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(325, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(905, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(945, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(974, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(1463, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(3232, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(5952, 0, 8, 1, 1, 0, 0, 0, 0, 0, 0),
(6346, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
(7383, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0),
(7434, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(8134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(8178, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(8494, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(8495, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(9452, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(9782, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(9784, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(9799, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(10191, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(10192, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(10193, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(10431, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(10432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(11095, 0, 3, 16, 0, 0, 0, 0, 0, 0, 0),
(11119, 4, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(11120, 4, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(11129, 0, 3, 12582935, 64, 0, 0, 0, 0, 0, 0),
(11180, 16, 3, 0, 0, 0, 0, 0, 0, 0, 0),
(11185, 0, 3, 128, 0, 0, 327680, 0, 0, 0, 0),
(11255, 0, 3, 16384, 0, 0, 0, 0, 0, 0, 0),
(12169, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(12281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6),
(12289, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0),
(12298, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(12311, 0, 4, 2048, 1, 0, 0, 0, 0, 0, 0),
(12317, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12319, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12322, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(12487, 0, 3, 128, 0, 0, 327680, 0, 0, 0, 0),
(12488, 0, 3, 128, 0, 0, 327680, 0, 0, 0, 0),
(12598, 0, 3, 16384, 0, 0, 0, 0, 0, 0, 0),
(12668, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0),
(12724, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(12725, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(12726, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(12727, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(12797, 0, 4, 1024, 0, 0, 0, 0, 0, 0, 0),
(12799, 0, 4, 1024, 0, 0, 0, 0, 0, 0, 0),
(12812, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6),
(12813, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6),
(12814, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6),
(12815, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6),
(12834, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12846, 4, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(12847, 4, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(12848, 4, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(12849, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12867, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12872, 0, 3, 16, 0, 0, 0, 0, 0, 0, 0),
(12873, 0, 3, 16, 0, 0, 0, 0, 0, 0, 0),
(12958, 0, 4, 2048, 1, 0, 0, 0, 0, 0, 0),
(12966, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(12967, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(12968, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(12969, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(12970, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(12971, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12972, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12973, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12974, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(12999, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
(13000, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
(13001, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
(13002, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
(13045, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(13046, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(13047, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(13048, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(13163, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
(13165, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(13754, 0, 8, 16, 0, 0, 0, 0, 0, 0, 0),
(13867, 0, 8, 16, 0, 0, 0, 0, 0, 0, 0),
(13983, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
(14070, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
(14071, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
(14156, 0, 8, 4063232, 0, 0, 0, 0, 0, 0, 0),
(14160, 0, 8, 4063232, 0, 0, 0, 0, 0, 0, 0),
(14161, 0, 8, 4063232, 0, 0, 0, 0, 0, 0, 0),
(14186, 0, 8, 1082131720, 2, 0, 0, 2, 0, 0, 0),
(14190, 0, 8, 1082131720, 2, 0, 0, 2, 0, 0, 0),
(14193, 0, 8, 1082131720, 2, 0, 0, 2, 0, 0, 0),
(14194, 0, 8, 1082131720, 2, 0, 0, 2, 0, 0, 0),
(14195, 0, 8, 1082131720, 2, 0, 0, 2, 0, 0, 0),
(14318, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(14319, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(14320, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(14321, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(14322, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(14531, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(14774, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(14892, 0, 6, 268443136, 65540, 0, 0, 2, 0, 0, 0),
(15088, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(15128, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(15268, 32, 6, 101187584, 2, 0, 0, 0, 0, 0, 0),
(15277, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
(15286, 32, 6, 0, 0, 0, 0, 0, 0, 0, 0),
(15323, 32, 6, 101187584, 2, 0, 0, 0, 0, 0, 0),
(15324, 32, 6, 101187584, 2, 0, 0, 0, 0, 0, 0),
(15325, 32, 6, 101187584, 2, 0, 0, 0, 0, 0, 0),
(15326, 32, 6, 101187584, 2, 0, 0, 0, 0, 0, 0),
(15337, 0, 6, 8192, 2, 0, 0, 2, 0, 0, 0),
(15338, 0, 6, 8192, 2, 0, 0, 2, 0, 0, 0),
(15346, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
(15362, 0, 6, 268443136, 65540, 0, 0, 2, 0, 0, 0),
(15363, 0, 6, 268443136, 65540, 0, 0, 2, 0, 0, 0),
(15600, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),
(16164, 0, 11, 2416967875, 0, 0, 0, 2, 0, 0, 0),
(16176, 0, 11, 448, 0, 0, 0, 2, 0, 0, 0),
(16180, 0, 11, 192, 0, 0, 0, 2, 0, 0, 0),
(16196, 0, 11, 192, 0, 0, 0, 2, 0, 0, 0),
(16198, 0, 11, 192, 0, 0, 0, 2, 0, 0, 0),
(16235, 0, 11, 448, 0, 0, 0, 2, 0, 0, 0),
(16240, 0, 11, 448, 0, 0, 0, 2, 0, 0, 0),
(16256, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16257, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(16277, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(16278, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(16279, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(16280, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(16281, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16282, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16283, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16284, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16487, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16489, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16492, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16550, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16620, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30),
(16624, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(16850, 0, 7, 4, 0, 0, 0, 0, 0, 0, 0),
(16864, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(16880, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16923, 0, 7, 4, 0, 0, 0, 0, 0, 0, 0),
(16924, 0, 7, 4, 0, 0, 0, 0, 0, 0, 0),
(16952, 0, 7, 233472, 1024, 0, 0, 2, 0, 0, 0),
(16954, 0, 7, 233472, 1024, 0, 0, 2, 0, 0, 0),
(16958, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(16961, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(17106, 0, 7, 524288, 0, 0, 0, 0, 0, 0, 0),
(17107, 0, 7, 524288, 0, 0, 0, 0, 0, 0, 0),
(17108, 0, 7, 524288, 0, 0, 0, 0, 0, 0, 0),
(17364, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17495, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(17793, 0, 5, 1, 0, 0, 0, 2, 0, 0, 0),
(17794, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0),
(17796, 0, 5, 1, 0, 0, 0, 2, 0, 0, 0),
(17797, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17798, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17799, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17800, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17801, 0, 5, 1, 0, 0, 0, 2, 0, 0, 0),
(17802, 0, 5, 1, 0, 0, 0, 2, 0, 0, 0),
(17803, 0, 5, 1, 0, 0, 0, 2, 0, 0, 0),
(18073, 0, 5, 96, 128, 0, 0, 0, 0, 0, 0),
(18094, 0, 5, 10, 0, 0, 0, 0, 0, 0, 0),
(18095, 0, 5, 10, 0, 0, 0, 0, 0, 0, 0),
(18096, 0, 5, 96, 128, 0, 0, 0, 0, 0, 0),
(18119, 0, 5, 997, 4288, 0, 0, 0, 0, 0, 0),
(18120, 0, 5, 997, 4288, 0, 0, 0, 0, 0, 0),
(18820, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(19184, 0, 9, 20, 8192, 0, 0, 0, 0, 0, 0),
(19228, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
(19232, 0, 9, 64, 0, 0, 0, 0, 0, 0, 0),
(19233, 0, 9, 64, 0, 0, 0, 0, 0, 0, 0),
(19387, 0, 9, 20, 8192, 0, 0, 0, 0, 0, 0),
(19388, 0, 9, 20, 8192, 0, 0, 0, 0, 0, 0),
(19572, 0, 9, 8388608, 0, 0, 16384, 0, 0, 0, 0),
(19573, 0, 9, 8388608, 0, 0, 16384, 0, 0, 0, 0),
(20049, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(20056, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(20057, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(20128, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(20131, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(20132, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(20164, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0),
(20165, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
(20166, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
(20182, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(20210, 0, 10, 3221225472, 65536, 0, 0, 2, 0, 0, 0),
(20212, 0, 10, 3221225472, 65536, 0, 0, 2, 0, 0, 0),
(20213, 0, 10, 3221225472, 65536, 0, 0, 2, 0, 0, 0),
(20214, 0, 10, 3221225472, 65536, 0, 0, 2, 0, 0, 0),
(20215, 0, 10, 3221225472, 65536, 0, 0, 2, 0, 0, 0),
(20234, 0, 10, 32768, 0, 0, 0, 0, 0, 0, 0),
(20235, 0, 10, 32768, 0, 0, 0, 0, 0, 0, 0),
(20375, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0),
(20500, 0, 4, 268435456, 0, 0, 0, 0, 0, 0, 0),
(20501, 0, 4, 268435456, 0, 0, 0, 0, 0, 0, 0),
(20705, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(20911, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(20925, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(20927, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(20928, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(21185, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(21882, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(21890, 0, 4, 712396527, 876, 0, 0, 0, 0, 0, 0),
(22007, 0, 3, 2097185, 0, 0, 0, 65536, 0, 0, 0),
(22618, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(22648, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(23547, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
(23548, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(23551, 0, 11, 192, 0, 0, 0, 0, 0, 0, 0),
(23552, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(23572, 0, 11, 192, 0, 0, 0, 0, 0, 0, 0),
(23578, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(23581, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(23602, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(23686, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(23688, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(23689, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
(23695, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0),
(23721, 0, 9, 2048, 0, 0, 0, 0, 0, 0, 0),
(23920, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(24353, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(24389, 0, 3, 12582935, 64, 0, 0, 0, 0, 0, 0),
(24398, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(24658, 0, 0, 0, 0, 0, 82192, 0, 0, 0, 0),
(24905, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0),
(24932, 0, 0, 0, 0, 0, 0, 2, 0, 0, 6),
(25050, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25296, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(25469, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(25472, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(25669, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),
(25899, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(25988, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(26016, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(26107, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0),
(26119, 0, 10, 2416967683, 0, 0, 0, 65536, 0, 0, 0),
(26128, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0),
(26135, 0, 10, 8388608, 0, 0, 0, 65536, 0, 0, 0),
(26480, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(26605, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(27044, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(27131, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(27179, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(27419, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(27498, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(27521, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(27656, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(27774, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(27787, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(27811, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(27815, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(27816, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(28592, 16, 3, 0, 0, 0, 0, 0, 0, 0, 0),
(28593, 16, 3, 0, 0, 0, 0, 0, 0, 0, 0),
(28716, 0, 7, 16, 0, 0, 294912, 0, 0, 0, 0),
(28719, 0, 7, 32, 0, 0, 0, 2, 0, 0, 0),
(28744, 0, 7, 64, 0, 0, 278528, 0, 0, 0, 0),
(28752, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(28789, 0, 10, 3221225472, 0, 0, 0, 0, 0, 0, 0),
(28802, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(28809, 0, 6, 4096, 0, 0, 0, 2, 0, 0, 0),
(28812, 0, 8, 33554438, 0, 0, 0, 2, 0, 0, 0),
(28816, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(28823, 0, 11, 192, 0, 0, 0, 0, 0, 0, 0),
(28847, 0, 7, 32, 0, 0, 0, 0, 0, 0, 0),
(28849, 0, 11, 128, 0, 0, 0, 0, 0, 0, 0),
(29074, 20, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(29075, 20, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(29076, 20, 3, 0, 0, 0, 0, 2, 0, 0, 0),
(29150, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29179, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(29180, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(29385, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0),
(29441, 0, 0, 0, 0, 0, 0, 8, 0, 0, 1),
(29444, 0, 0, 0, 0, 0, 0, 8, 0, 0, 1),
(29455, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(29501, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29593, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(29594, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(29624, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29625, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29626, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29632, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29633, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29634, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29635, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29636, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29637, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(29801, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(29834, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(29838, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(29977, 0, 3, 12582935, 64, 0, 0, 0, 0, 0, 0),
(30003, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(30160, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30293, 0, 5, 897, 192, 0, 0, 0, 0, 0, 0),
(30295, 0, 5, 897, 192, 0, 0, 0, 0, 0, 0),
(30296, 0, 5, 897, 192, 0, 0, 0, 0, 0, 0),
(30299, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30301, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30302, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30675, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0),
(30678, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0),
(30679, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0),
(30680, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0),
(30681, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0),
(30701, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30705, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30802, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30803, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30804, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30805, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30806, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30807, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30808, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30809, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30810, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30811, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(30823, 0, 0, 0, 0, 0, 0, 0, 10.5, 0, 0),
(30881, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5),
(30883, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5),
(30884, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5),
(30885, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5),
(30886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5),
(30937, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(31124, 0, 8, 536870926, 0, 0, 0, 0, 0, 0, 0),
(31126, 0, 8, 536870926, 0, 0, 0, 0, 0, 0, 0),
(31244, 0, 8, 4063232, 9, 0, 0, 4, 0, 0, 0),
(31245, 0, 8, 4063232, 9, 0, 0, 4, 0, 0, 0),
(31394, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(31569, 0, 3, 65536, 0, 0, 0, 0, 0, 0, 0),
(31570, 0, 3, 65536, 0, 0, 0, 0, 0, 0, 0),
(31785, 0, 0, 0, 0, 0, 34816, 0, 0, 0, 0),
(31794, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(31801, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
(31833, 0, 10, 2147483648, 0, 0, 0, 0, 0, 0, 0),
(31835, 0, 10, 2147483648, 0, 0, 0, 0, 0, 0, 0),
(31836, 0, 10, 2147483648, 0, 0, 0, 0, 0, 0, 0),
(31871, 0, 10, 16, 0, 0, 16384, 0, 0, 0, 0),
(31872, 0, 10, 16, 0, 0, 16384, 0, 0, 0, 0),
(31876, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(31877, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(31878, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(31904, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(32385, 0, 5, 1026, 17, 0, 0, 0, 0, 0, 0),
(32387, 0, 5, 1026, 17, 0, 0, 0, 0, 0, 0),
(32392, 0, 5, 1026, 17, 0, 0, 0, 0, 0, 0),
(32393, 0, 5, 1026, 17, 0, 0, 0, 0, 0, 0),
(32394, 0, 5, 1026, 17, 0, 0, 0, 0, 0, 0),
(32409, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(32587, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(32593, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(32594, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(32642, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(32734, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(32748, 0, 8, 0, 1, 0, 320, 0, 0, 0, 0),
(32776, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(32777, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(32837, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 45),
(32844, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
(32885, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33076, 0, 0, 0, 0, 0, 656040, 0, 0, 0, 0),
(33089, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(33127, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0),
(33142, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33145, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33146, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33150, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33151, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33154, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33191, 0, 6, 8421376, 1024, 0, 0, 0, 0, 0, 0),
(33192, 0, 6, 8421376, 1024, 0, 0, 0, 0, 0, 0),
(33193, 0, 6, 8421376, 1024, 0, 0, 0, 0, 0, 0),
(33299, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(33510, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0),
(33648, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33719, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(33736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(33746, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(33757, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(33759, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(33776, 0, 0, 0, 0, 0, 34816, 0, 0, 0, 0),
(33881, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33882, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33883, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(33953, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 45),
(34080, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0),
(34138, 0, 11, 128, 0, 0, 0, 0, 0, 0, 0),
(34139, 0, 10, 1073741824, 0, 0, 0, 0, 0, 0, 0),
(34258, 0, 10, 1024, 8, 0, 0, 0, 0, 0, 0),
(34262, 0, 10, 8388608, 0, 0, 0, 65536, 0, 0, 0),
(34320, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(34497, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34498, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34499, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34500, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34502, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34503, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34584, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30),
(34586, 0, 0, 0, 0, 0, 0, 0, 1.5, 0, 0),
(34598, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(34749, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0),
(34753, 0, 6, 6144, 4, 0, 0, 2, 0, 0, 0),
(34774, 0, 0, 0, 0, 0, 0, 0, 1.5, 0, 20),
(34783, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(34827, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(34859, 0, 6, 6144, 4, 0, 0, 2, 0, 0, 0),
(34860, 0, 6, 6144, 4, 0, 0, 2, 0, 0, 0),
(34914, 0, 6, 8192, 0, 0, 0, 0, 0, 0, 0),
(34916, 0, 6, 8192, 0, 0, 0, 0, 0, 0, 0),
(34917, 0, 6, 8192, 0, 0, 0, 0, 0, 0, 0),
(34935, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8),
(34938, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8),
(34939, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8),
(34950, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(34954, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(35077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60),
(35080, 0, 0, 0, 0, 0, 0, 0, 1, 0, 60),
(35083, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60),
(35086, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60),
(35100, 0, 9, 12289, 0, 0, 65856, 0, 0, 0, 0),
(35102, 0, 9, 12289, 0, 0, 0, 0, 0, 0, 0),
(35103, 0, 9, 12289, 0, 0, 0, 0, 0, 0, 0),
(35121, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(36096, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(36111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(36541, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(37165, 0, 8, 2098176, 0, 0, 0, 0, 0, 0, 0),
(37168, 0, 8, 4063232, 9, 0, 0, 0, 0, 0, 0),
(37170, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),
(37173, 0, 8, 750519704, 262, 0, 0, 0, 0, 0, 30),
(37189, 0, 10, 3221225472, 0, 0, 0, 2, 0, 0, 60),
(37193, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(37195, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(37197, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 45),
(37213, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(37214, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(37227, 0, 11, 448, 0, 0, 0, 2, 0, 0, 60),
(37237, 0, 11, 1, 0, 0, 0, 2, 0, 0, 0),
(37247, 8, 0, 0, 0, 0, 0, 65536, 0, 0, 45),
(37377, 32, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(37379, 32, 5, 0, 0, 0, 0, 0, 0, 0, 0),
(37384, 0, 5, 1, 0, 0, 0, 0, 0, 0, 0),
(37443, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(37514, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
(37516, 0, 4, 1024, 0, 0, 0, 0, 0, 0, 0),
(37519, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
(37523, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(37528, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0),
(37536, 0, 4, 65536, 0, 0, 0, 0, 0, 0, 0),
(37568, 0, 6, 2048, 0, 0, 0, 0, 0, 0, 0),
(37594, 0, 6, 4096, 0, 0, 0, 0, 0, 0, 0),
(37600, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(37601, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(37603, 0, 6, 32768, 0, 0, 0, 0, 0, 0, 0),
(37655, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60),
(37657, 0, 0, 0, 0, 0, 0, 2, 0, 0, 3),
(38026, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0),
(38031, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(38290, 0, 0, 0, 0, 0, 0, 0, 1.6, 0, 0),
(38326, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(38327, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(38334, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60),
(38347, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(38350, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(38394, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0),
(38857, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(39027, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(39372, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(39437, 4, 5, 4964, 192, 0, 0, 65536, 0, 0, 0),
(39442, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0),
(39443, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(39530, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(39958, 0, 0, 0, 0, 0, 0, 0, 0.7, 0, 40),
(40407, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
(40438, 0, 6, 32832, 0, 0, 0, 0, 0, 0, 0),
(40442, 0, 7, 20, 1088, 0, 0, 0, 0, 0, 0),
(40444, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(40458, 0, 4, 33554432, 1537, 0, 0, 0, 0, 0, 0),
(40463, 0, 11, 129, 16, 0, 0, 0, 0, 0, 0),
(40470, 0, 10, 3229614080, 0, 0, 0, 0, 0, 0, 0),
(40475, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0),
(40478, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0),
(40482, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(40485, 0, 9, 0, 1, 0, 0, 0, 0, 0, 0),
(40899, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(41034, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(41260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(41262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(41381, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
(41393, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
(41434, 0, 0, 0, 0, 0, 0, 0, 2, 0, 45),
(41469, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0),
(41635, 0, 0, 0, 0, 0, 656040, 0, 0, 0, 0),
(41989, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0),
(42083, 0, 0, 0, 0, 0, 0, 2, 0, 0, 45),
(42135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90),
(42136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90),
(42368, 0, 10, 1073741824, 0, 0, 0, 0, 0, 0, 0),
(42370, 0, 11, 64, 0, 0, 0, 0, 0, 0, 0),
(42770, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(43019, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(43020, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(43338, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(43443, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(43726, 0, 10, 1073741824, 0, 0, 0, 0, 0, 0, 0),
(43728, 0, 11, 128, 0, 0, 0, 0, 0, 0, 0),
(43737, 0, 7, 0, 1088, 0, 0, 0, 0, 0, 10),
(43739, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(43741, 0, 10, 2147483648, 0, 0, 0, 0, 0, 0, 0),
(43745, 0, 10, 0, 512, 0, 0, 0, 0, 0, 0),
(43748, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(43750, 0, 11, 1, 0, 0, 0, 0, 0, 0, 0),
(43819, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(44394, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(44395, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(44396, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(44401, 0, 3, 2097152, 0, 0, 0, 4095, 0, 0, 0),
(44404, 0, 3, 536870945, 36864, 0, 0, 0, 0, 0, 0),
(44442, 0, 3, 8388608, 64, 0, 0, 65536, 0, 0, 1),
(44443, 0, 3, 8388608, 64, 0, 0, 65536, 0, 0, 1),
(44445, 0, 3, 19, 4096, 0, 0, 0, 0, 0, 0),
(44446, 0, 3, 19, 4096, 0, 0, 0, 0, 0, 0),
(44448, 0, 3, 19, 4096, 0, 0, 0, 0, 0, 0),
(44449, 0, 3, 551686775, 102472, 0, 0, 2, 0, 0, 0),
(44469, 0, 3, 551686775, 102472, 0, 0, 2, 0, 0, 0),
(44470, 0, 3, 551686775, 102472, 0, 0, 2, 0, 0, 0),
(44471, 0, 3, 551686775, 102472, 0, 0, 2, 0, 0, 0),
(44472, 0, 3, 551686775, 102472, 0, 0, 2, 0, 0, 0),
(44546, 0, 3, 33555104, 0, 0, 0, 0, 0, 0, 0),
(44548, 0, 3, 33555104, 0, 0, 0, 0, 0, 0, 0),
(44549, 0, 3, 33555104, 0, 0, 0, 0, 0, 0, 0),
(44835, 0, 7, 0, 128, 0, 16, 0, 0, 0, 0),
(45054, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15),
(45057, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30),
(45234, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(45243, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(45244, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(45354, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(45481, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(45482, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(45483, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(45484, 0, 0, 0, 0, 0, 16384, 0, 0, 0, 45),
(46025, 32, 6, 0, 0, 0, 0, 0, 0, 0, 0),
(46092, 0, 10, 1073741824, 0, 0, 0, 0, 0, 0, 0),
(46098, 0, 11, 128, 0, 0, 0, 0, 0, 0, 0),
(46569, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(46662, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20),
(46832, 0, 7, 1, 0, 0, 0, 65536, 0, 0, 0),
(46854, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(46855, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(46867, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(46913, 0, 4, 0, 1024, 0, 0, 2, 0, 0, 0),
(46914, 0, 4, 0, 1024, 0, 0, 2, 0, 0, 0),
(46915, 0, 4, 0, 1024, 0, 0, 2, 0, 0, 0),
(46916, 0, 4, 0, 1024, 0, 0, 2, 0, 0, 0),
(46951, 0, 4, 1024, 64, 0, 0, 0, 0, 0, 0),
(46952, 0, 0, 1024, 64, 0, 0, 0, 0, 0, 0),
(46953, 0, 0, 1024, 64, 0, 0, 0, 0, 0, 0),
(47195, 0, 5, 2, 0, 0, 0, 0, 0, 0, 30),
(47196, 0, 5, 2, 0, 0, 0, 0, 0, 0, 30),
(47197, 0, 5, 2, 0, 0, 0, 0, 0, 0, 30),
(47201, 0, 5, 8, 262144, 0, 0, 65536, 0, 0, 0),
(47202, 0, 5, 8, 262144, 0, 0, 0, 0, 0, 0),
(47203, 0, 5, 8, 262144, 0, 0, 0, 0, 0, 0),
(47204, 0, 5, 8, 262144, 0, 0, 0, 0, 0, 0),
(47205, 0, 5, 8, 262144, 0, 0, 0, 0, 0, 0),
(47232, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(47234, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(47235, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(47245, 32, 5, 0, 0, 0, 0, 0, 0, 0, 0),
(47246, 32, 5, 0, 0, 0, 0, 0, 0, 0, 0),
(47247, 32, 5, 0, 0, 0, 0, 0, 0, 0, 0),
(47258, 0, 5, 0, 8388608, 0, 0, 65536, 0, 0, 0),
(47259, 0, 5, 0, 8388608, 0, 0, 65536, 0, 0, 0),
(47260, 0, 5, 0, 8388608, 0, 0, 65536, 0, 0, 0),
(47263, 32, 5, 0, 0, 0, 0, 2, 0, 0, 20),
(47264, 32, 5, 0, 0, 0, 0, 2, 0, 0, 20),
(47265, 32, 5, 0, 0, 0, 0, 2, 0, 0, 20),
(47509, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(47511, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(47515, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(47516, 0, 6, 6144, 65536, 0, 0, 0, 0, 0, 0),
(47517, 0, 6, 6144, 65536, 0, 0, 0, 0, 0, 0),
(47535, 0, 6, 6144, 8388608, 0, 0, 0, 0, 0, 0),
(47536, 0, 6, 6144, 8388608, 0, 0, 0, 0, 0, 0),
(47537, 0, 6, 6144, 8388608, 0, 0, 0, 0, 0, 0),
(47538, 0, 6, 6144, 8388608, 0, 0, 0, 0, 0, 0),
(47539, 0, 6, 6144, 8388608, 0, 0, 0, 0, 0, 0),
(47549, 0, 6, 0, 131072, 0, 0, 0, 0, 0, 0),
(47551, 0, 6, 0, 131072, 0, 0, 0, 0, 0, 0),
(47552, 0, 6, 0, 131072, 0, 0, 0, 0, 0, 0),
(47555, 0, 6, 6144, 0, 0, 0, 0, 0, 0, 0),
(47556, 0, 6, 6144, 0, 0, 0, 0, 0, 0, 0),
(47557, 0, 6, 6144, 0, 0, 0, 0, 0, 0, 0),
(47572, 0, 6, 65536, 0, 0, 0, 0, 0, 0, 0),
(47580, 0, 6, 0, 0, 64, 0, 65536, 0, 0, 0),
(47581, 0, 6, 0, 0, 64, 0, 65536, 0, 0, 0),
(47582, 0, 6, 0, 0, 64, 0, 65536, 0, 0, 0),
(48110, 0, 0, 0, 0, 0, 656040, 0, 0, 0, 0),
(48111, 0, 0, 0, 0, 0, 656040, 0, 0, 0, 0),
(48112, 0, 0, 0, 0, 0, 656040, 0, 0, 0, 0),
(48113, 0, 0, 0, 0, 0, 656040, 0, 0, 0, 0),
(48159, 0, 6, 8192, 0, 0, 0, 0, 0, 0, 0),
(48160, 0, 6, 8192, 0, 0, 0, 0, 0, 0, 0),
(48483, 0, 7, 34816, 1088, 0, 0, 0, 0, 0, 0),
(48484, 0, 7, 34816, 1088, 0, 0, 0, 0, 0, 0),
(48485, 0, 7, 34816, 1088, 0, 0, 0, 0, 0, 0),
(48496, 0, 7, 96, 33554434, 0, 0, 2, 0, 0, 0),
(48499, 0, 7, 96, 33554434, 0, 0, 2, 0, 0, 0),
(48500, 0, 7, 96, 33554434, 0, 0, 2, 0, 0, 0),
(48506, 0, 7, 5, 0, 0, 0, 0, 0, 0, 0),
(48510, 0, 7, 5, 0, 0, 0, 0, 0, 0, 0),
(48511, 0, 7, 5, 0, 0, 0, 0, 0, 0, 0),
(48516, 0, 7, 5, 0, 0, 0, 2, 0, 0, 30),
(48521, 0, 7, 5, 0, 0, 0, 2, 0, 0, 30),
(48525, 0, 7, 5, 0, 0, 0, 2, 0, 0, 30),
(48833, 0, 7, 0, 1088, 0, 0, 0, 0, 0, 0),
(48835, 0, 10, 0, 8, 0, 0, 0, 0, 0, 0),
(48837, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(48951, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(48952, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(48988, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(49018, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(49137, 0, 15, 0, 16384, 0, 0, 0, 0, 0, 0),
(49188, 0, 15, 2, 0, 0, 0, 0, 0, 0, 0),
(49208, 0, 15, 4456448, 0, 0, 0, 0, 0, 0, 0),
(49222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(49280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(49281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(49283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(49284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(49503, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(49504, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(49529, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(49530, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(49531, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(49532, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(49622, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60),
(49657, 0, 15, 0, 16384, 0, 0, 0, 0, 0, 0),
(50781, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51123, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51127, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51128, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51129, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51130, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51346, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(51349, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(51352, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(51359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10),
(51466, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51470, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51474, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(51478, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(51479, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(51556, 0, 11, 192, 0, 16, 0, 2, 0, 0, 0),
(51557, 0, 11, 192, 0, 16, 0, 2, 0, 0, 0),
(51558, 0, 11, 192, 0, 16, 0, 2, 0, 0, 0),
(51562, 0, 11, 256, 0, 16, 0, 0, 0, 0, 0),
(51563, 0, 11, 256, 0, 16, 0, 0, 0, 0, 0),
(51564, 0, 11, 256, 0, 16, 0, 0, 0, 0, 0),
(51565, 0, 11, 256, 0, 16, 0, 0, 0, 0, 0),
(51566, 0, 11, 256, 0, 16, 0, 0, 0, 0, 0),
(51625, 0, 8, 268476416, 0, 0, 0, 0, 0, 0, 0),
(51626, 0, 8, 268476416, 0, 0, 0, 0, 0, 0, 0),
(51627, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(51628, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(51629, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
(51634, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51635, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51636, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(51664, 0, 8, 131072, 8, 0, 0, 0, 0, 0, 0),
(51665, 0, 8, 131072, 8, 0, 0, 0, 0, 0, 0),
(51667, 0, 8, 131072, 8, 0, 0, 0, 0, 0, 0),
(51668, 0, 8, 131072, 8, 0, 0, 0, 0, 0, 0),
(51669, 0, 8, 131072, 8, 0, 0, 0, 0, 0, 0),
(51672, 0, 0, 0, 0, 0, 0, 16, 0, 0, 1),
(51674, 0, 0, 0, 0, 0, 0, 16, 0, 0, 1),
(51679, 0, 8, 1, 1, 0, 0, 0, 0, 0, 0),
(51692, 0, 8, 512, 0, 0, 0, 2, 0, 0, 0),
(51696, 0, 8, 512, 0, 0, 0, 2, 0, 0, 0),
(51698, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1),
(51700, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1),
(51701, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1),
(51940, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
(51989, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
(52004, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
(52005, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
(52007, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
(52008, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0),
(52020, 0, 7, 32768, 1048576, 0, 0, 0, 0, 0, 0),
(52127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(52129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(52131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(52134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(52136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(52138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(52420, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30),
(52423, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
(52795, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0),
(52797, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0),
(52798, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0),
(52799, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0),
(52800, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0),
(52898, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(53137, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(53138, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(53215, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(53216, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(53217, 0, 9, 1, 0, 0, 0, 0, 0, 0, 0),
(53221, 0, 9, 0, 1, 0, 0, 0, 0, 0, 0),
(53222, 0, 9, 0, 1, 0, 0, 0, 0, 0, 0),
(53224, 0, 9, 0, 1, 0, 0, 0, 0, 0, 0),
(53228, 0, 9, 32, 16777216, 0, 0, 0, 0, 0, 0),
(53232, 0, 9, 32, 16777216, 0, 0, 0, 0, 0, 0),
(53256, 0, 9, 2048, 8388609, 0, 0, 2, 0, 0, 0),
(53259, 0, 9, 2048, 8388609, 0, 0, 2, 0, 0, 0),
(53260, 0, 9, 2048, 8388609, 0, 0, 2, 0, 0, 0),
(53290, 0, 9, 2048, 2147483647, 0, 0, 2, 0, 0, 0),
(53291, 0, 9, 2048, 2147483647, 0, 0, 2, 0, 0, 0),
(53292, 0, 9, 2048, 2147483647, 0, 0, 2, 0, 0, 0),
(53293, 0, 9, 2048, 2147483647, 0, 0, 2, 0, 0, 0),
(53294, 0, 9, 2048, 2147483647, 0, 0, 2, 0, 0, 0),
(53380, 0, 10, 8388608, 131072, 0, 0, 2, 0, 0, 0),
(53381, 0, 10, 8388608, 131072, 0, 0, 2, 0, 0, 0),
(53382, 0, 10, 8388608, 131072, 0, 0, 2, 0, 0, 0),
(53383, 0, 10, 8388608, 131072, 0, 0, 2, 0, 0, 0),
(53384, 0, 10, 8388608, 131072, 0, 0, 2, 0, 0, 0),
(53486, 0, 10, 8388608, 163840, 0, 0, 2, 0, 0, 0),
(53488, 0, 10, 8388608, 163840, 0, 0, 2, 0, 0, 0),
(53501, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(53502, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(53503, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(53551, 0, 10, 4096, 0, 0, 0, 0, 0, 0, 0),
(53552, 0, 10, 4096, 0, 0, 0, 0, 0, 0, 0),
(53553, 0, 10, 4096, 0, 0, 0, 0, 0, 0, 0),
(53569, 0, 10, 2097152, 0, 0, 0, 2, 0, 0, 0),
(53576, 0, 10, 2097152, 0, 0, 0, 2, 0, 0, 0),
(53601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6),
(53671, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(53673, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(54149, 0, 10, 2097152, 0, 0, 0, 2, 0, 0, 0),
(54151, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(54154, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(54155, 0, 10, 8388608, 0, 0, 0, 0, 0, 0, 0),
(54278, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(54486, 0, 0, 536870945, 36864, 0, 0, 0, 0, 0, 0),
(54488, 0, 0, 536870945, 36864, 0, 0, 0, 0, 0, 0),
(54489, 0, 0, 536870945, 36864, 0, 0, 0, 0, 0, 0),
(54490, 0, 0, 536870945, 36864, 0, 0, 0, 0, 0, 0),
(54738, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(54747, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(54749, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0),
(54754, 0, 7, 16, 0, 0, 0, 0, 0, 0, 0),
(54841, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(54936, 0, 10, 1073741824, 0, 0, 0, 0, 0, 0, 0),
(54937, 0, 10, 2147483648, 0, 0, 0, 0, 0, 0, 0),
(54939, 0, 10, 32768, 0, 0, 0, 0, 0, 0, 0),
(55440, 0, 11, 64, 0, 0, 0, 0, 0, 0, 0),
(55620, 0, 15, 1, 134217728, 0, 0, 0, 0, 0, 0),
(55623, 0, 15, 1, 134217728, 0, 0, 0, 0, 0, 0),
(55666, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0),
(55667, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0),
(55668, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0),
(55669, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0),
(55670, 0, 15, 1, 0, 0, 0, 0, 0, 0, 0),
(55677, 0, 6, 0, 1, 0, 0, 0, 0, 0, 0),
(55680, 0, 6, 512, 0, 0, 0, 0, 0, 0, 0),
(55689, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(56218, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0),
(56333, 0, 9, 4, 0, 512, 0, 0, 0, 0, 0),
(56336, 0, 9, 4, 0, 512, 0, 0, 0, 0, 0),
(56337, 0, 9, 4, 0, 512, 0, 0, 0, 0, 0),
(56342, 0, 9, 16384, 0, 0, 0, 0, 0, 0, 0),
(56343, 0, 9, 16384, 0, 0, 0, 0, 0, 0, 0),
(56344, 0, 9, 16384, 0, 0, 0, 0, 0, 0, 0),
(56364, 0, 3, 0, 16777216, 0, 0, 0, 0, 0, 0),
(56451, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(56611, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(56612, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(56613, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(56614, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(56636, 0, 4, 32, 0, 0, 0, 0, 0, 0, 0),
(56637, 0, 4, 32, 0, 0, 0, 0, 0, 0, 0),
(56638, 0, 4, 32, 0, 0, 0, 0, 0, 0, 0),
(56821, 0, 8, 2, 0, 0, 0, 2, 0, 0, 0),
(56822, 0, 15, 2, 0, 0, 0, 0, 0, 0, 0),
(56834, 0, 15, 4456448, 0, 0, 0, 0, 0, 0, 0),
(56835, 0, 15, 4456448, 0, 0, 0, 0, 0, 0, 0),
(57878, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
(57880, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
(57881, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
(57960, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3),
(58357, 0, 4, 64, 0, 0, 0, 2, 0, 0, 0),
(58364, 0, 4, 1024, 0, 0, 0, 0, 0, 0, 0),
(58372, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0),
(58386, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
(58435, 0, 5, 2, 256, 0, 0, 0, 0, 0, 0),
(58436, 0, 5, 2, 256, 0, 0, 0, 0, 0, 0),
(58437, 0, 5, 2, 256, 0, 0, 0, 0, 0, 0),
(58616, 0, 15, 262144, 0, 0, 0, 0, 0, 0, 0),
(58620, 0, 15, 0, 16384, 0, 0, 0, 0, 0, 0),
(58626, 0, 15, 33554432, 0, 0, 0, 0, 0, 0, 0),
(58631, 0, 15, 2, 0, 0, 0, 0, 0, 0, 0),
(58642, 0, 15, 0, 134217728, 0, 0, 0, 0, 0, 0),
(58644, 0, 15, 0, 4, 0, 0, 0, 0, 0, 0),
(58647, 0, 15, 0, 4, 0, 0, 0, 0, 0, 0),
(58676, 0, 15, 0, 8, 0, 0, 0, 0, 0, 0),
(58677, 0, 15, 8192, 0, 0, 0, 0, 0, 0, 0),
(58872, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(58874, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
(58901, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(59057, 0, 15, 2, 0, 0, 0, 0, 0, 0, 0),
(59176, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(59327, 0, 15, 134217728, 0, 0, 0, 0, 0, 0, 0),
(59725, 0, 0, 0, 0, 0, 0, 2048, 0, 0, 0),
(60132, 0, 15, 0, 134348800, 0, 0, 0, 0, 0, 0),
(60170, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0),
(60172, 0, 5, 262144, 0, 0, 0, 65536, 0, 0, 0),
(60200, 0, 15, 4096, 0, 0, 0, 65536, 0, 0, 0),
(60493, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45),
(60503, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0),
(60537, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0),
(60564, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(60571, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(60572, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(60573, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(60574, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(60575, 0, 11, 2416967680, 0, 0, 0, 0, 0, 0, 0),
(60617, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
(60710, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(60717, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(60719, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(60722, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(60724, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(60726, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0),
(60770, 0, 11, 1, 0, 0, 0, 0, 0, 0, 0),
(60818, 0, 10, 0, 512, 0, 0, 0, 0, 0, 0),
(60826, 0, 15, 20971520, 0, 0, 0, 0, 0, 0, 0),
(61188, 0, 5, 4, 0, 0, 0, 0, 0, 0, 0),
(61257, 0, 0, 0, 0, 0, 131752, 65536, 0, 0, 0),
(61324, 0, 10, 0, 131072, 0, 0, 0, 0, 0, 0),
(61846, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
(61847, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0);

-- 1206_world_scripts
UPDATE `gameobject_template` SET `ScriptName`='go_legion_obelisk' WHERE `entry` IN (185193,185195,185196,185197,185198);

-- 1207_world_scripts
UPDATE `creature_template` SET `ScriptName`='npc_surristrasz' WHERE `entry`=24795;
UPDATE `creature_template` SET `ScriptName`='npc_tiare' WHERE `entry`=30051;

-- 1237_mangos_7230_01_world_spell_bonus_data
DELETE FROM `spell_bonus_data` WHERE `entry` IN (18220,18937,18938,27265,59092);
INSERT INTO `spell_bonus_data` VALUES
('18220', '0.96', '0', '0', 'Warlock - Dark Pact Rank 1'),
('18937', '0.96', '0', '0', 'Warlock - Dark Pact Rank 2'),
('18938', '0.96', '0', '0', 'Warlock - Dark Pact Rank 3'),
('27265', '0.96', '0', '0', 'Warlock - Dark Pact Rank 4'),
('59092', '0.96', '0', '0', 'Warlock - Dark Pact Rank 5');

-- 1248_mangos_7235_01_world_command
DELETE FROM `command` WHERE `name` = 'reset achievements';
INSERT INTO `command` VALUES
('reset achievements',3,'Syntax: .reset achievements [$playername]\r\n\r\nReset achievements data for selected or named (online or offline) character. Achievements for persistance progress data like completed quests/etc re-filled at reset. Achievements for events like kills/casts/etc will lost.');

-- 1288_mangos_7242_01_world_spell_bonus_data
DELETE FROM spell_bonus_data WHERE entry IN (34913, 43043, 43044);
INSERT INTO spell_bonus_data VALUES
 (34913, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 1'),
 (43043, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 2'),
 (43044, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 3');
 
-- 1293_mangos_7249_01_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry`='60200';

-- 1296_mangos_7252_01_world_command
DELETE FROM `command` WHERE `name` IN ('debug arena','debug bg');
INSERT INTO `command` VALUES
('debug arena',3,'Syntax: .debug arena\r\n\r\nToggle debug mode for arenas. In debug mode GM can start arena with single player.'),
('debug bg',3,'Syntax: .debug bg\r\n\r\nToggle debug mode for battlegrounds. In debug mode GM can start battleground with single player.');

-- 1296_mangos_7252_02_world_trinity_string
DELETE FROM `trinity_string` WHERE entry IN (737,738,739,740,741,742,743,744,745,746);
INSERT INTO `trinity_string` VALUES
(737,'Arenas are set to 1v1 for debugging. So, don\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(738,'Arenas are set to normal playercount.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(739,'Battlegrounds are set to 1v0 for debugging.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(740,'Battlegrounds are set to normal playercount.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(741,'Flushing Arena points based on team ratings, this may take a few minutes. Please stand by...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(742,'Distributing arena points to players...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(743,'Finished setting arena points for online players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(744,'Modifying played count, arena points etc. for loaded arena teams, sending updated stats to online players...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(745,'Modification done.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(746,'Done flushing Arena points.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1307_world
UPDATE `creature_template` SET `ScriptName`='npc_stormwind_harbor_taxi' WHERE `entry`=29154;

-- 1312_world
UPDATE `creature_template` SET `scriptname` = 'boss_keleseth' WHERE `entry` = '23953';
UPDATE `creature_template` SET `scriptname` = 'mob_frost_tomb' WHERE `entry` = '23965';
UPDATE `instance_template` SET `script`='instance_utgarde_keep' WHERE `map`= '574';
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1574000, 'Your blood is mine!',13221,1,0,'keleseth SAY_AGGRO'),
(-1574001, 'Darkness waits',13223,1,0, 'keleseth SAY_KILL'),
(-1574002, 'I join... the night.',13225,1,0, 'keleseth SAY_DEATH'),
(-1574003, 'Not so fast.',13222,1,0, 'keleseth SAY_FROST_TOMB'),
(-1574004, 'Aranal, lidel! Their fate shall be yours!',13224,1,0, 'keleseth SAY_SKELETONS');

-- 1327_world
ALTER TABLE `creature_template` ADD COLUMN `spell5` mediumint(8) unsigned NOT NULL default '0' AFTER `spell4`;
ALTER TABLE `creature_template` ADD COLUMN `spell6` mediumint(8) unsigned NOT NULL default '0' AFTER `spell5`;
ALTER TABLE `creature_template` ADD COLUMN `spell7` mediumint(8) unsigned NOT NULL default '0' AFTER `spell6`;
ALTER TABLE `creature_template` ADD COLUMN `spell8` mediumint(8) unsigned NOT NULL default '0' AFTER `spell7`;

-- 1351_world
DROP TABLE IF EXISTS `trinity_string`;
CREATE TABLE IF NOT EXISTS `trinity_string` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `mangos_string`
--

INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(1, 'You should select a character or a creature.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(2, 'You should select a creature.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(3, '|cffff0000[System Message]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4, '|cffff0000[Event Message]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5, 'There is no help for that command', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(6, 'There is no such command', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(7, 'There is no such subcommand', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(8, 'Command %s have subcommands:%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(9, 'Commands available to you:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10, 'Incorrect syntax.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(11, 'Your account level is: %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12, 'Online players: %u (max: %u) Queued players: %u (max: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(13, 'Server uptime: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(14, 'Player saved.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(15, 'All players saved.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(16, 'There are the following active GMs on this server:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(17, 'There are no GMs currently logged in on this server.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(18, 'Cannot do that while flying.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(19, 'Cannot do that in Battlegrounds.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(20, 'Target is flying you can''t do that.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(21, '%s is flying command failed.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(22, 'You are not mounted so you can''t dismount.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(23, 'Cannot do that while fighting.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(24, 'You used it recently.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(25, 'Password not changed (unknown error)!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(26, 'The password was changed', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(27, 'The new passwords do not match or the old password is wrong', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(28, 'Your account is now locked.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(29, 'Your account is now unlocked.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30, ', rank ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(31, ' [known]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(32, ' [learn]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(33, ' [passive]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(34, ' [talent]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(35, ' [active]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(36, ' [complete]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(37, ' (offline)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(38, 'on', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(39, 'off', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(40, 'You are: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(41, 'visible', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(42, 'invisible', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(43, 'done', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(44, 'You', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(45, ' <unknown> ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(46, '<error>', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(47, '<non-existing character>', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(48, 'UNKNOWN', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(49, 'You must be at least level %u to enter.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(50, 'You must be at least level %u and have item %s to enter.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(51, 'Hello! Ready for some training?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(52, 'Invaid item count (%u) for item %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(53, 'Mail can''t have more %u item stacks', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(54, 'The new passwords do not match', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(55, 'Your password can''t be longer than 16 characters (client limit), password not changed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(56, 'Current Message of the day: \r\n%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(57, 'Using World DB: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(58, 'Using script library: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(100, 'Global notify: ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(101, 'Map: %u (%s) Zone: %u (%s) Area: %u (%s)\nX: %f Y: %f Z: %f Orientation: %f\ngrid[%u,%u]cell[%u,%u] InstanceID: %u\n ZoneX: %f ZoneY: %f\nGroundZ: %f FloorZ: %f Have height data (Map: %u VMap: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(102, '%s is already being teleported.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(103, 'You can summon a player to your instance only if he is in your party with you as leader.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(104, 'You cannot go to the player''s instance because you are in a party now.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(105, 'You can go to the player''s instance while not being in his party only if your GM mode is on.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(106, 'You can not go to player %s from instance to instance.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(107, 'You can not summon player %s from instance to instance.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(108, 'You are summoning %s%s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(109, 'You are being summoned by %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(110, 'You are teleporting %s%s to %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(111, 'You are being teleported by %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(112, 'Player (%s) does not exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(113, 'Appearing at %s''s location.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(114, '%s is appearing to your location.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(115, 'Incorrect values.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(116, 'No character selected.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(117, '%s is not in a group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(118, 'You changed HP of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(119, '%s changed your HP to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(120, 'You changed MANA of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(121, '%s changed your MANA to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(122, 'You changed ENERGY of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(123, '%s changed your ENERGY to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(124, 'Current energy: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(125, 'You changed rage of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(126, '%s changed your rage to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(127, 'You changed level of %s to %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(128, 'GUID %i, faction is %i, flags is %i, npcflag is %i, DY flag is %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(129, 'Wrong faction: %u (not found in factiontemplate.dbc).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(130, 'You changed GUID=%i ''s Faction to %i, flags to %i, npcflag to %i, dyflag to %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(131, 'You changed the spellflatid=%i, val= %i, mark =%i to %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(132, '%s changed your spellflatid=%i, val= %i, mark =%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(133, '%s has access to all taxi nodes now (until logout).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(134, '%s has no more access to all taxi nodes now (only visited accessible).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(135, '%s has given you access to all taxi nodes (until logout).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(136, '%s has removed access to all taxi nodes (only visited still accessible).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(137, 'You set all speeds to %2.2f from normal of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(138, '%s set all your speeds to %2.2f from normal.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(139, 'You set the speed to %2.2f from normal of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(140, '%s set your speed to %2.2f from normal.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(141, 'You set the swim speed to %2.2f from normal of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(142, '%s set your swim speed to %2.2f from normal.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(143, 'You set the backwards run speed to %2.2f from normal of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(144, '%s set your backwards run speed to %2.2f from normal.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(145, 'You set the fly speed to %2.2f from normal of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(146, '%s set your fly speed to %2.2f from normal.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(147, 'You set the size %2.2f of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(148, '%s set your size to %2.2f.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(149, 'There is no such mount.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(150, 'You give a mount to %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(151, '%s gave you a mount.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(152, 'USER1: %i, ADD: %i, DIF: %i\n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(153, 'You take all copper of %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(154, '%s took you all of your copper.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(155, 'You take %i copper from %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(156, '%s took %i copper from you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(157, 'You give %i copper to %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(158, '%s gave you %i copper.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(159, 'You hear sound %u.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(160, 'USER2: %i, ADD: %i, RESULT: %i\n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(161, 'Removed bit %i in field %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(162, 'Set bit %i in field %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(163, 'Teleport location table is empty!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(164, 'Teleport location not found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(165, 'Requires search parameter.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(166, 'There are no teleport locations matching your request.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(168, 'Locations found are:\n%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(169, 'Mail sent to %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(170, 'You try to hear sound %u but it doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(172, 'server console command', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(173, 'You changed runic power of %s to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(174, '%s changed your runic power to %i/%i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(200, 'No selection.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(201, 'Object GUID is: lowpart %u highpart %X', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(202, 'The name was too long by %i characters.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(203, 'Error, name can only contain characters A-Z and a-z.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(204, 'The subname was too long by %i characters.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(205, 'Not yet implemented', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(206, 'Item ''%i'' ''%s'' added to list with maxcount ''%i'' and incrtime ''%i'' and extendedcost ''%i''', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(207, 'Item ''%i'' not found in database.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(208, 'Item ''%i'' ''%s'' deleted from vendor list', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(209, 'Item ''%i'' not found in vendor list.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(210, 'Item ''%i'' already in vendor list.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(211, 'Spells of %s reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(212, 'Spells of %s will reset at next login.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(213, 'Talents of %s reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(214, 'Talents of %s will reset at next login.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(215, 'Your spells have been reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(216, 'Your talents have been reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(217, 'Unknown case ''%s'' for .resetall command. Type full correct case name.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(218, 'Spells will reset for all players at login. Strongly recommend re-login!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(219, 'Talents will reset for all players at login. Strongly recommend re-login!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(220, 'Creature (GUID: %u) No waypoint found.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(221, 'Creature (GUID: %u) Last waypoint not found.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(222, 'Creature (GUID: %u) No waypoint found - used ''wpguid''. Now trying to find it by its position...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(223, 'Creature (GUID: %u) No waypoints found - This is a MaNGOS db problem (single float).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(224, 'Selected creature is ignored - provided GUID is used', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(225, 'Creature (GUID: %u) not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(226, 'You must select a visual waypoint.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(227, 'No visual waypoints found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(228, 'Could not create visual waypoint with creatureID: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(229, 'All visual waypoints removed', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(230, 'Could not create waypoint-creature with ID: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(231, 'No GUID provided.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(232, 'No waypoint number provided.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(233, 'Argument required for ''%s''.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(234, 'Waypoint %i added to GUID: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(235, 'Waypoint %d added.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(236, 'Waypoint changed.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(237, 'Waypoint %s modified.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(238, 'WP export successfull.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(239, 'No waypoints found inside the database.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(240, 'File imported.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(241, 'Waypoint removed.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(242, 'Warning: Could not delete WP from the world with ID: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(243, 'This happens if the waypoint is too far away from your char.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(244, 'The WP is deleted from the database, but not from the world here.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(245, 'They will disappear after a server restart.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(246, 'Waypoint %d: Info for creature: %s, GUID: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(247, 'Waittime: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(248, 'Model %d: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(249, 'Emote: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(250, 'Spell: %d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(251, 'Text%d (ID: %i): %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(252, 'AIScript: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(253, 'Forced rename for player %s will be requested at next login.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(254, 'Forced rename for player %s (GUID #%u) will be requested at next login.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(255, 'Waypoint-Creature (GUID: %u) Not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(256, 'Could not find NPC...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(257, 'Creature movement type set to ''%s'', waypoints removed (if any).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(258, 'Creature movement type set to ''%s'', waypoints were not removed.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(259, 'Incorrect value, use on or off', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(260, 'Value saved.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(261, 'Value saved, you may need to rejoin or clean your client cache.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(262, 'Areatrigger ID %u not found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(263, 'Target map or coordinates is invalid (X: %f Y: %f MapId: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(264, 'Zone coordinates is invalid (X: %f Y: %f AreaId: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(265, 'Zone %u (%s) is part of instanceable map %u (%s)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(266, 'Nothing found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(267, 'Object not found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(268, 'Creature not found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(269, 'Warning: Mob found more than once - you will be teleported to the first one found in DB.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(270, 'Creature Removed', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(271, 'Creature moved.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(272, 'Creature (GUID:%u) must be on the same map as player!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(273, 'Game Object (GUID: %u) not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(274, 'Game Object (GUID: %u) has references in not found creature %u GO list, can''t be deleted.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(275, 'Game Object (GUID: %u) removed', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(276, 'Game Object (GUID: %u) turned', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(277, 'Game Object (GUID: %u) moved', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(278, 'You must select a vendor', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(279, 'You must send id for item', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(280, 'Vendor has too many items (max 128)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(281, 'You can''t kick self, logout instead', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(282, 'Player %s kicked.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(283, 'Player %s not found.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(284, 'Accepting Whisper: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(285, 'Accepting Whisper: ON', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(286, 'Accepting Whisper: OFF', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(287, 'Creature (GUID: %u) not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(288, 'Tickets count: %i show new tickets: %s\n', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(289, 'New ticket from %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(290, 'Ticket of %s (Last updated: %s):\n%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(291, 'New ticket show: ON', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(292, 'New ticket show: OFF', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(293, 'Ticket %i doesn''t exist', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(294, 'All tickets deleted.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(295, 'Character %s ticket deleted.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(296, 'Ticket deleted.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(297, 'Spawn distance changed to: %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(298, 'Spawn time changed to: %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(299, 'The honor of %s was set to %u!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(300, 'Your chat has been disabled for %u minutes.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(301, 'You have disabled %s''s chat for %u minutes.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(302, 'Player''s chat is already enabled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(303, 'Your chat has been enabled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(304, 'You have enabled %s''s chat.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(305, 'Faction %s (%u) reputation of %s was set to %5d!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(306, 'The arena points of %s was set to %u!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(307, 'No faction found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(308, 'Faction %i unknown!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(309, 'Invalid parameter %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(310, 'delta must be between 0 and %d (inclusive)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(311, '%d - |cffffffff|Hfaction:%d|h[%s]|h|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(312, ' [visible]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(313, ' [at war]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(314, ' [peace forced]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(315, ' [hidden]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(316, ' [invisible forced]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(317, ' [inactive]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(318, 'Hated', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(319, 'Hostile', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(320, 'Unfriendly', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(321, 'Neutral', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(322, 'Friendly', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(323, 'Honored', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(324, 'Revered', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(325, 'Exalted', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(326, 'Faction %s (%u) can''not have reputation.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(327, ' [no reputation]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(328, 'Characters at account %s (Id: %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(329, '  %s (GUID %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(330, 'No players found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(331, 'Extended item cost %u not exist', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(332, 'GM mode is ON', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(333, 'GM mode is OFF', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(334, 'GM Chat Badge is ON', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(335, 'GM Chat Badge is OFF', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(336, 'You repair all %s''s items.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(337, 'All your items repaired by %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(338, 'You set waterwalk mode %s for %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(339, 'Your waterwalk mode %s by %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(340, '%s is now following you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(341, '%s is not following you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(342, '%s is now not following you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(343, 'Creature (Entry: %u) cannot be tamed.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(344, 'You already have pet.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(345, 'Forced customize for player %s will be requested at next login.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(346, 'Forced customize for player %s (GUID #%u) will be requested at next login.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(400, '|cffff0000[System Message]:|rScripts reloaded', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(401, 'You change security level of account %s to %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(402, '%s changed your security level to %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(403, 'You have low security level for this.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(404, 'Creature movement disabled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(405, 'Creature movement enabled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(406, 'Weather can''t be changed for this zone.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(407, 'Weather system disabled at server.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(408, '%s is banned for %s. Reason: %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(409, '%s is banned permanently for %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(410, '%s %s not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(411, '%s unbanned.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(412, 'There was an error removing the ban on %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(413, 'Account not exist: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(414, 'There is no such character.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(415, 'There is no such IP in banlist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(416, 'Account %s has never been banned', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(417, 'Ban history for account %s:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(418, 'Ban Date: %s Bantime: %s Still active: %s  Reason: %s Set by: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(419, 'Inf.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(420, 'Never', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(421, 'Yes', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(422, 'No', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(423, 'IP: %s\nBan Date: %s\nUnban Date: %s\nRemaining: %s\nReason: %s\nSet by: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(424, 'There is no matching IPban.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(425, 'There is no matching account.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(426, 'There is no banned account owning a character matching this part.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(427, 'The following IPs match your pattern:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(428, 'The following accounts match your query:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(429, 'You learned many spells/skills.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(430, 'You learned all spells for class.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(431, 'You learned all talents for class.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(432, 'You learned all languages.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(433, 'You learned all craft skills and recipes.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(434, 'Could not find ''%s''', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(435, 'Invalid item id: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(436, 'No items found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(437, 'Invalid gameobject id: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(438, 'Found items %u: %u ( inventory %u mail %u auction %u guild %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(439, 'Found gameobjects %u: %u ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(440, 'Invalid creature id: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(441, 'Found creatures %u: %u ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(442, 'No area found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(443, 'No item sets found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(444, 'No skills found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(445, 'No spells found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(446, 'No quests found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(447, 'No creatures found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(448, 'No gameobjects found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(449, 'Graveyard #%u doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(450, 'Graveyard #%u already linked to zone #%u (current).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(451, 'Graveyard #%u linked to zone #%u (current).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(452, 'Graveyard #%u can''t be linked to subzone or not existed zone #%u (internal error).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(454, 'No faction in Graveyard with id= #%u , fix your DB', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(455, 'invalid team, please fix database', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(456, 'any', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(457, 'alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(458, 'horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(459, 'Graveyard #%u (faction: %s) is nearest from linked to zone #%u.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(460, 'Zone #%u doesn''t have linked graveyards.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(461, 'Zone #%u doesn''t have linked graveyards for faction: %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(462, 'Teleport location already exists!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(463, 'Teleport location added.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(464, 'Teleport location NOT added: database error.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(465, 'Teleport location deleted.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(467, 'Target unit has %d auras:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(468, 'id: %d eff: %d type: %d duration: %d maxduration: %d name: %s%s%s caster: %s %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(469, 'Target unit has %d auras of type %d:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(470, 'id: %d eff: %d name: %s%s%s caster: %s %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(471, 'Quest %u not found.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(472, 'Quest %u started from item. For correct work, please, add item to inventory and start quest in normal way: .additem %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(473, 'Quest removed.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(474, ' [rewarded]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(475, ' [complete]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(476, ' [active]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(477, '%s''s Fly Mode %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(478, 'Opcode %u sent to %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(479, 'Character loaded successfully!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(480, 'Failed to load the character!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(481, 'Character dumped successfully!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(482, 'Character dump failed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(483, 'Spell %u broken and not allowed to cast or learn!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(484, 'Skill %u (%s) for player %s set to %u and current maximum set to %u (without permanent (talent) bonuses).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(485, 'Player %s must have skill %u (%s) before using this command.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(486, 'Invalid skill id (%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(487, 'You learned default GM spells/skills.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(488, 'You already know that spell.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(489, 'Target(%s) already know that spell.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(490, '%s doesn''t know that spell.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(491, 'You already forgot that spell.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(492, 'All spell cooldowns removed for %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(493, 'Spell %u cooldown removed for %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(494, 'Command : Additem, itemId = %i, amount = %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(495, 'Command : Additemset, itemsetId = %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(496, 'Removed itemID = %i, amount = %i from %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(497, 'Cannot create item ''%i'' (amount: %i)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(498, 'You need to provide a guild name!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(499, 'Player not found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(500, 'Player already has a guild!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(501, 'Guild not created! (already exists?)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(502, 'No items from itemset ''%u'' found.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(503, 'The distance is: (3D) %f (2D) %f yards.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(504, 'Item ''%i'' ''%s'' Item Slot %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(505, 'Item ''%i'' doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(506, 'Item ''%i'' ''%s'' Added to Slot %i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(507, 'Item save failed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(508, '%d - owner: %s (guid: %u account: %u ) %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(509, '%d - sender: %s (guid: %u account: %u ) receiver: %s (guid: %u account: %u ) %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(510, '%d - owner: %s (guid: %u account: %u ) %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(511, 'Wrong link type!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(512, '%d - |cffffffff|Hitem:%d:0:0:0:0:0:0:0|h[%s]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(513, '%d - |cffffffff|Hquest:%d|h[%s]|h|r %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(514, '%d - |cffffffff|Hcreature_entry:%d|h[%s]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(515, '%d - |cffffffff|Hcreature:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(516, '%d - |cffffffff|Hgameobject_entry:%d|h[%s]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(517, '%d - |cffffffff|Hgameobject:%d|h[%s X:%f Y:%f Z:%f MapId:%d]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(518, '%d - |cffffffff|Hitemset:%d|h[%s %s]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(519, '|cffffffff|Htele:%s|h[%s]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(520, '%d - |cffffffff|Hspell:%d|h[%s]|h|r ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(521, '%d - |cffffffff|Hskill:%d|h[%s %s]|h|r %s %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(522, 'Game Object (GUID: %u) not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(523, '>> Game Object %s (GUID: %u) at %f %f %f. Orientation %f.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(524, 'Selected object:\n|cffffffff|Hitemset:%d|h[%s]|h|r\nGUID: %u ID: %u\nX: %f Y: %f Z: %f MapId: %u\nOrientation: %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(525, '>> Add Game Object ''%i'' (%s) (GUID: %i) added at ''%f %f %f''.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(526, '%s (lowguid: %u) movement generators stack:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(527, '   Idle', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(528, '   Random', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(529, '   Waypoint', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(530, '   Animal random', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(531, '   Confused', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(532, '   Targeted to player %s (lowguid %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(533, '   Targeted to creature %s (lowguid %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(534, '   Targeted to <NULL>', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(535, '   Home movement to (X:%f Y:%f Z:%f)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(536, '   Home movement used for player?!?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(537, '   Taxi flight', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(538, '   Unknown movement generator (%u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(539, 'Player selected NPC\nGUID: %u.\nFaction: %u.\nnpcFlags: %u.\nEntry: %u.\nDisplayID: %u (Native: %u).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(540, 'Level: %u.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(541, 'Health (base): %u. (max): %u. (current): %u.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(542, 'Field Flags: %u.\nDynamic Flags: %u.\nFaction Template: %u.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(543, 'Loot: %u Pickpocket: %u Skinning: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(544, 'Position: %f %f %f.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(545, '*** Is a vendor!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(546, '*** Is a trainer!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(547, 'InstanceID: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(548, 'Player%s %s (guid: %u) Account: %s (id: %u) GMLevel: %u Last IP: %s Last login: %s Latency: %ums', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(549, 'Played time: %s Level: %u Money: %ug%us%uc', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(550, 'Command .pinfo doesn''t support ''rep'' option for offline players.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(551, '%s has explored all zones now.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(552, '%s has no more explored zones.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(553, '%s has explored all zones for you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(554, '%s has hidden all zones from you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(555, 'Hover enabled', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(556, 'Hover disabled', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(557, 'You have been leveled up (%i)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(558, 'You have been leveled down (%i)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(559, 'Your level progress has been reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(560, 'The area has been set as explored.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(561, 'The area has been set as not explored.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(562, 'GUID=%i ''s updateIndex: %i, value:  %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(563, 'You change GUID=%i ''s UpdateIndex: %i value to %i.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(564, 'The value index %u is too big to %u(count: %u).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(565, 'Set %u uint32 Value:[OPCODE]:%u [VALUE]:%u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(566, 'You Set %u Field:%u to uint32 Value: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(567, 'Set %u float Value:[OPCODE]:%u [VALUE]:%f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(568, 'You Set %u Field:%i to float Value: %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(569, 'Get %u uint32 Value:[OPCODE]:%u [VALUE]:%u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(570, 'The uint32 value of %u in %u is: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(571, 'Get %u float Value:[OPCODE]:%u [VALUE]:%f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(572, 'The float of %u value in %u is: %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(573, '.Set32Bit:[OPCODE]:%u [VALUE]:%u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(574, 'You set Bit of Field:%u to Value: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(575, '.Mod32Value:[OPCODE]:%u [VALUE]:%i', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(576, 'You modified the value of Field:%u to Value: %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(577, 'You are now invisible.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(578, 'You are now visible.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(579, 'Selected player or creature not have victim.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(580, 'Player %s learned all default spells for race/class and completed quests rewarded spells.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(581, 'Found near gameobjects (distance %f): %u ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(582, 'SpawnTime: Full:%s Remain:%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(583, '%d - |cffffffff|Hgameevent:%d|h[%s]|h|r%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(584, 'No event found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(585, 'Event not exist!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(586, 'Event %u: %s%s\nStart: %s End: %s Occurence: %s Length: %s\nNext state change: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(587, 'Event %u already active!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(588, 'Event %u not active!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(589, '   Point movement to (X:%f Y:%f Z:%f)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(590, '   Fear movement', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(591, '   Distract movement', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(592, 'You have learned all spells in craft: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(593, 'Currently Banned Accounts:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(594, '|    Account    |   BanDate    |   UnbanDate  |  Banned By    |   Ban Reason  |', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(595, 'Currently Banned IPs:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(596, '|      IP       |   BanDate    |   UnbanDate  |  Banned By    |   Ban Reason  |', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(597, 'Current gamemasters:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(598, '|    Account    |  GM  |', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(599, 'No gamemasters.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(600, 'The Alliance wins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(601, 'The Horde wins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(602, 'The battle for Warsong Gulch begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(603, 'The battle for Warsong Gulch begins in 30 seconds. Prepare yourselves!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(604, 'Let the battle for Warsong Gulch begin!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(605, '$n captured the Horde flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(606, '$n captured the Alliance flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(607, 'The Horde flag was dropped by $n!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(608, 'The Alliance Flag was dropped by $n!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(609, 'The Alliance Flag was returned to its base by $n!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(610, 'The Horde flag was returned to its base by $n!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(611, 'The Horde flag was picked up by $n!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(612, 'The Alliance Flag was picked up by $n!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(613, 'The flags are now placed at their bases.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(614, 'The Alliance flag has been respawned!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(615, 'The Horde flag has been respawned!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(636, 'The Battle for Eye of the Storm begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(637, 'The Battle for Eye of the Storm begins in 30 seconds.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(638, 'The Battle for Eye of the Storm has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(650, 'Alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(651, 'Horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(652, 'stables', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(653, 'blacksmith', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(654, 'farm', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(655, 'lumber mill', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(656, 'mine', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(657, 'The %s has taken the %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(658, '$n has defended the %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(659, '$n has assaulted the %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(660, '$n claims the %s! If left unchallenged, the %s will control it in 1 minute!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(661, 'The Battle for Arathi Basin begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(662, 'The Battle for Arathi Basin begins in 30 seconds. Prepare yourselves!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(663, 'The Battle for Arathi Basin has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(664, 'The Alliance has gathered $1776W resources, and is near victory!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(665, 'The Horde has gathered $1777W resources, and is near victory!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(666, 'After your recent battle in %s our best attempts to award you a Mark of Honor failed. Enclosed you will find the Mark of Honor we were not able to deliver to you at the time. Thanks for fighting in %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(667, 'The Alliance has taken control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(668, 'The Horde has taken control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(669, 'The Alliance has taken control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(670, 'The Horde has taken control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(671, 'The Alliance has taken control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(672, 'The Horde has taken control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(673, 'The Alliance has taken control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(674, 'The Horde has taken control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(675, 'The Alliance has lost control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(676, 'The Horde has lost control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(677, 'The Alliance has lost control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(678, 'The Horde has lost control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(679, 'The Alliance has lost control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(680, 'The Horde has lost control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(681, 'The Alliance has lost control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(682, 'The Horde has lost control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(683, '$N has taken the flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(684, 'The Alliance has captured the flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(685, 'The Horde has captured the flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(686, 'The Flag has been dropped!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(687, 'The flag has been reset', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(700, 'You must be level %u to form an arena team', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(701, 'One minute until the Arena battle begins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(702, 'Thirty seconds until the Arena battle begins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(703, 'Fifteen seconds until the Arena battle begins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(704, 'The Arena battle has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(705, 'You must wait %s before speaking again.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(706, 'This item(s) have problems with equipping/storing in inventory.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(707, '%s wishes to not be disturbed and cannot receive whisper messages: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(708, '%s is Away from Keyboard: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(709, 'Do not Disturb', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(710, 'Away from Keyboard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(711, 'Queue status for %s (Lvl: %u to %u)\nQueued alliances: %u (Need at least %u more)\nQueued hordes: %u (Need at least %u more)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(712, '|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] A: %u/%u, H: %u/%u|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(713, 'You must be level %u to join an arena team!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(715, 'You don''t meet Battleground level requirements', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(717, '|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] Started!|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(718, '|cffff0000[Arena Queue Announcer]:|r %s -- Joined : %ux%u : %u|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(719, '|cffff0000[Arena Queue Announcer]:|r %s -- Exited : %ux%u : %u|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(720, 'Your group is too large for this battleground. Please regroup to join.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(721, 'Your group is too large for this arena. Please regroup to join.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(722, 'Your group has members not in your arena team. Please regroup to join.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(723, 'Your group does not have enough players to join this match.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(724, 'The Gold Team wins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(725, 'The Green Team wins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(726, 'There aren''t enough players in this battleground. It will end soon unless some more players join to balance the fight.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(727, 'Your group has an offline member. Please remove him before joining.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(728, 'Your group has players from the opposing faction. You can''t join the battleground as a group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(729, 'Your group has players from different battleground brakets. You can''t join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(730, 'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(731, 'Someone in your party is Deserter. You can''t join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(732, 'Someone in your party is already in three battleground queues. You cannot join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(733, 'You cannot teleport to a battleground or arena map.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(734, 'You cannot summon players to a battleground or arena map.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(735, 'You must be in GM mode to teleport to a player in a battleground.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(736, 'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(737, 'Arenas are set to 1v1 for debugging. So, don''t join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(738, 'Arenas are set to normal playercount.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(739, 'Battlegrounds are set to 1v0 for debugging.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(740, 'Battlegrounds are set to normal playercount.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(741, 'Flushing Arena points based on team ratings, this may take a few minutes. Please stand by...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(742, 'Distributing arena points to players...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(743, 'Finished setting arena points for online players.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(744, 'Modifying played count, arena points etc. for loaded arena teams, sending updated stats to online players...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(745, 'Modification done.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(746, 'Done flushing Arena points.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(785, 'Arena testing turned %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(786, '|cffff0000[Automatic]:|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(787, '|cffffff00[|c1f40af20Announce by|r |cffff0000%s|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(800, 'Invalid name', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(801, 'You do not have enough gold', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(802, 'You do not have enough free slots', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(803, 'Your partner does not have enough free bag slots', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(804, 'You do not have permission to perform that function', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(805, 'Unknown language', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(806, 'You don''t know that language', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(807, 'Please provide character name', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(808, 'Player %s not found or offline', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(809, 'Account for character %s not found', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1000, 'Exiting daemon...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1001, 'Account deleted: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1002, 'Account %s NOT deleted (probably sql file format was updated)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1003, 'Account %s NOT deleted (unknown error)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1004, 'Account created: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1005, 'Account name can''t be longer than 16 characters (client limit), account not created!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1006, 'Account with this name already exist!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1007, 'Account %s NOT created (probably sql file format was updated)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1008, 'Account %s NOT created (unknown error)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1009, 'Player %s (Guid: %u) Account %s (Id: %u) deleted.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1010, '|    Account    |       Character      |       IP        | GM | TBC |', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1011, '|<Error>        | %20s |<Error>          |<Er>|<Err>|', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1100, 'Account %s (Id: %u) have up to %u expansion allowed now.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1101, 'Message of the day changed to:\r\n%s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1102, 'Message sent to %s: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1103, '%d - %s %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1104, '%d - %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1105, '%d - %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1106, '%d - %s %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1107, '%d - %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1108, '%d - %s %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1109, '%d - %s %s %s %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1110, '%d - %s X:%f Y:%f Z:%f MapId:%d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1111, '%d - %s X:%f Y:%f Z:%f MapId:%d', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1112, 'Failed to open file: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1113, 'Account %s (%u) have max amount allowed characters (client limit)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1114, 'Dump file have broken data!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1115, 'Invalid character name!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1116, 'Invalid character guid!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1117, 'Character guid %u in use!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1118, '%d - guild: %s (guid: %u) %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1119, 'You must use male or female as gender.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1120, 'You change gender of %s to %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1121, 'Your gender changed to %s by %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1122, '(%u/%u +perm %u +temp %u)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),

(1200,'Alliance',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1201,'Horde',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1202,'%s was destroyed by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1203,'The %s is under attack! If left unchecked, the %s will destroy it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1204,'The %s was taken by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1205,'The %s was taken by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1206,'The %s was taken by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1207,'The %s is under attack! If left unchecked, the %s will capture it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1208,'The %s has taken the %s! Its supplies will now be used for reinforcements!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1209,'Irondeep Mine',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1210,'Coldtooth Mine',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1211,'Stormpike Aid Station',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1212,'Dun Baldar South Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1213,'Dun Baldar North Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1214,'Stormpike Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1215,'Icewing Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1216,'Stonehearth Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1217,'Stonehearth Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1218,'Snowfall Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1219,'Iceblood Tower',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1220,'Iceblood Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1221,'Tower Point',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1222,'Frostwolf Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1223,'East Frostwolf Tower',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1224,'West Frostwolf Tower',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1225,'Frostwolf Relief Hut',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1226,'The Battle for Alterac Valley begins in 1 minute.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1227,'The Battle for Alterac Valley begins in 30 seconds. Prepare yourselves!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1228,'The Battle for Alterac Valley has begun!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1229,'The Alliance Team is running out of reinforcements!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1230,'The Horde Team is running out of reinforcements!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1231,'The Frostwolf General is Dead!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1232,'The Stormpike General is Dead!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(2000, '|cff00ff00New ticket from|r|cffff00ff %s.|r |cff00ff00Ticket entry:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2001, '|cff00ff00Character|r|cffff00ff %s |r|cff00ff00edited his/her ticket:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2002, '|cff00ff00Character|r|cffff00ff %s |r|cff00ff00abandoned ticket entry:|r|cffff00ff %d.|r', '', '', '', '', '', '', '', ''),
(2003, '|cff00ff00Closed by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2004, '|cff00ff00Deleted by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2005, 'Ticket not found.', '', '', '', '', '', '', '', ''),
(2006, 'Please close ticket before deleting it permanently.', '', '', '', '', '', '', '', ''),
(2007, 'Ticket %d is already assigned.', '', '', '', '', '', '', '', ''),
(2008, '%u Tickets succesfully reloaded from the database.', '', '', '', '', '', '', '', ''),
(2009, 'Showing list of open tickets.', '', '', '', '', '', '', '', ''),
(2010, 'Showing list of open tickets whose creator is online.', '', '', '', '', '', '', '', ''),
(2011, 'Showing list of closed tickets.', '', '', '', '', '', '', '', ''),
(2012, 'Invalid name specified. Name should be that of an online Gamemaster.', '', '', '', '', '', '', '', ''),
(2013, 'This ticket is already assigned to yourself. To unassign use .ticket unassign %d and then reassign.', '', '', '', '', '', '', '', ''),
(2014, 'Ticket %d is not assigned, you cannot unassign it.', '', '', '', '', '', '', '', ''),
(2015, 'You cannot unassign tickets from staffmembers with a higher security level than yourself.', '', '', '', '', '', '', '', ''),
(2016, 'Cannot close ticket %d, it is assigned to another GM.', '', '', '', '', '', '', '', ''),
(2017, '|cff00ff00Ticket|r:|cff00ccff %d.|r ', '', '', '', '', '', '', '', ''),
(2018, '|cff00ff00Created by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2019, '|cff00ff00Last change|r:|cff00ccff %s ago|r ', '', '', '', '', '', '', '', ''),
(2020, '|cff00ff00Assigned to|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2021, '|cff00ff00Unassigned by|r:|cff00ccff %s|r ', '', '', '', '', '', '', '', ''),
(2022, '\n|cff00ff00Message|r: \"%s\"|r ', '', '', '', '', '', '', '', ''),
(2023, '\n|cff00ff00Comment|r: \"%s\"|r ', '', '', '', '', '', '', '', ''),
(2024, '\n|cff00ccff%s|r |cff00ff00Added comment|r: \"%s\"|r ', '', '', '', '', '', '', '', ''),

(5000, 'You froze player %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5001, 'It might be amusing but no... you cant freeze yourself!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5002, 'Invalid input check the name of target.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5003, 'You unfroze player %s.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5004, 'There are no frozen players.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5005, 'Following players are frozen on the server:', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5006, '- %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5009, 'Sound %u Played to server', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),

(6613, '|cfff00000[GM Announcement]: %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(6614, 'Notification to GM''s - ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(6615, '|cffffff00[|c1f40af20GM Announce by|r |cffff0000%s|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),

(10001, 'The Horde has taken The Overlook!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10002, 'The Alliance has taken The Overlook!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10003, 'The Horde has taken The Stadium!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10004, 'The Alliance has taken The Stadium!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10005, 'The Horde has taken Broken Hill!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10006, 'The Alliance has taken Broken Hill!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10007, 'The Horde lost The Overlook!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10008, 'The Alliance lost The Overlook!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10009, 'The Horde lost The Stadium!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10010, 'The Alliance lost The Stadium!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10011, 'The Horde lost Broken Hill!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10012, 'The Alliance lost Broken Hill!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10013, 'The Horde has taken the West Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10014, 'The Alliance has taken the West Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10015, 'The Horde has taken the East Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10016, 'The Alliance has taken the East Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10017, 'The Horde has captured the Twin Spire Graveyard!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10018, 'The Alliance has captured the Twin Spire Graveyard!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10019, 'The Horde lost the West Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10020, 'The Alliance lost the West Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10021, 'The Horde lost the East Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10022, 'The Alliance lost the East Beacon!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10023, 'The Horde lost the Twin Spire Graveyard!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10024, 'The Alliance lost the Twin Spire Graveyard!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10025, 'The Horde has captured Halaa!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10026, 'The Alliance has captured Halaa!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10027, 'The Horde lost Halaa!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10028, 'The Alliance lost Halaa!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10029, 'The Horde has taken a Spirit Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10030, 'The Alliance has taken a Spirit Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10031, 'The Horde lost a Spirit Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10032, 'The Alliance lost a Spirit Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10033, 'The Horde has taken the Northpass Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10034, 'The Alliance has taken the Northpass Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10035, 'The Horde has taken the Eastwall Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10036, 'The Alliance has taken the Eastwall Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10037, 'The Horde has taken the Crown Guard Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10038, 'The Alliance has taken the Crown Guard Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10039, 'The Horde has taken the Plaguewood Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10040, 'The Alliance has taken the Plaguewood Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10041, 'The Horde lost the Northpass Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10042, 'The Alliance lost the Northpass Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10043, 'The Horde lost the Eastwall Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10044, 'The Alliance lost the Eastwall Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10045, 'The Horde lost the Crown Guard Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10046, 'The Alliance lost the Crown Guard Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10047, 'The Horde lost the Plaguewood Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10048, 'The Alliance lost the Plaguewood Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10049, 'The Horde has collected 200 silithyst!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10050, 'The Alliance has collected 200 silithyst!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10051, 'Take me to Northpass Tower.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10052, 'Take me to Eastwall Tower.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10053, 'Take me to Crown Guard Tower.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10054, 'Give me the flag, I''ll take it to the central beacon for the glory of the Alliance!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10055, 'Give me the flag, I''ll take it to the central beacon for the glory of the Horde!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10056, 'You must be a member of the Horde to enter the Hall of Legends.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(10057, 'You must be a member of the Alliance to enter the Champion''s Hall.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- 1414_world_scripts
-- r847_scriptdev2_script_texts.sql
UPDATE `script_texts` SET emote=15 WHERE `entry`=-1000123;
UPDATE `script_texts` SET emote=1 WHERE `entry`=-1560028;
UPDATE `script_texts` SET emote=1 WHERE `entry`=-1560031;
UPDATE `script_texts` SET emote=5 WHERE `entry`=-1560032;
UPDATE `script_texts` SET emote=16 WHERE `entry`=-1000119;
UPDATE `script_texts` SET emote=254 WHERE `entry`=-1249002;
UPDATE `script_texts` SET emote=293 WHERE `entry`=-1249003;
UPDATE `script_texts` SET emote=1 WHERE `entry`=-1033000;
-- r848_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1540047 AND -1540042;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1540042,'Ours is the true Horde! The only Horde!',10323,1,0,0,'kargath SAY_AGGRO1'),
(-1540043,'I\'ll carve the meat from your bones!',10324,1,0,0,'kargath SAY_AGGRO2'),
(-1540044,'I am called Bladefist for a reason, as you will see!',10325,1,0,0,'kargath SAY_AGGRO3'),
(-1540045,'For the real Horde!',10326,1,0,0,'kargath SAY_SLAY1'),
(-1540046,'I am the only Warchief!',10327,1,0,0,'kargath SAY_SLAY2'),
(-1540047,'The true Horde... will.. prevail...',10328,1,0,0,'kargath SAY_DEATH');
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533118 AND -1533109;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1533109,'You are mine now!',8825,1,0,0,'heigan SAY_AGGRO1'),
(-1533110,'I see you!',8826,1,0,0,'heigan SAY_AGGRO2'),
(-1533111,'You...are next!',8827,1,0,0,'heigan SAY_AGGRO3'),
(-1533112,'Close your eyes... sleep!',8829,1,0,0,'heigan SAY_SLAY'),
(-1533113,'The races of the world will perish. It is only a matter of time.',8830,1,0,0,'heigan SAY_TAUNT1'),
(-1533114,'I see endless suffering, I see torment, I see rage. I see... everything!',8831,1,0,0,'heigan SAY_TAUNT2'),
(-1533115,'Soon... the world will tremble!',8832,1,0,0,'heigan SAY_TAUNT3'),
(-1533116,'The end is upon you.',8833,1,0,0,'heigan SAY_TAUNT4'),
(-1533117,'Hungry worms will feast on your rotten flesh!',8834,1,0,0,'heigan SAY_TAUNT5'),
(-1533118,'Noo... o...',8828,1,0,0,'heigan SAY_DEATH');
-- r849_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry`=-1070000;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1070000,'None may steal the secrets of the makers!',5851,1,0,0,'ironaya SAY_AGGRO');
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1129004 AND -1129000;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1129000,'You\'ll never leave this place... alive.',5825,1,0,0,'amnennar SAY_AGGRO'),
(-1129001,'To me, my servants!',5828,1,0,0,'amnennar SAY_SUMMON60'),
(-1129002,'Come, spirits, attend your master!',5829,1,0,0,'amnennar SAY_SUMMON30'),
(-1129003,'I am the hand of the Lich King!',5827,1,0,0,'amnennar SAY_HP'),
(-1129004,'Too...easy!',5826,1,0,0,'amnennar SAY_KILL');
DELETE FROM `script_texts` WHERE `entry` IN (-1230002,-1230001);
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1230001,'Come to aid the Throne!',0,1,0,0,'dagran SAY_AGGRO'),
(-1230002,'Hail to the king, baby!',0,1,0,0,'dagran SAY_SLAY');
-- r852_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189021 AND -1189011;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1189011,'Tell me... tell me everything!',5847,1,0,0,'vishas SAY_AGGRO'),
(-1189012,'Naughty secrets!',5849,1,0,0,'vishas SAY_HEALTH1'),
(-1189013,'I\'ll rip the secrets from your flesh!',5850,1,0,0,'vishas SAY_HEALTH2'),
(-1189014,'Purged by pain!',5848,1,0,0,'vishas SAY_KILL'),
(-1189015,'The monster got what he deserved.',0,0,1,0,'vishas SAY_TRIGGER_VORREL'),
(-1189016,'We hunger for vengeance.',5844,1,0,0,'thalnos SAY_AGGRO'),
(-1189017,'No rest, for the angry dead.',5846,1,0,0,'thalnos SAY_HEALTH'),
(-1189018,'More... More souls.',5845,1,0,0,'thalnos SAY_KILL'),
(-1189019,'You will not defile these mysteries!',5842,1,0,0,'doan SAY_AGGRO'),
(-1189020,'Burn in righteous fire!',5843,1,0,0,'doan SAY_SPECIALAE'),
(-1189021,'Release the hounds!',5841,1,0,0,'loksey SAY_AGGRO');
-- r854_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1070006 AND -1070001;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1070001,'Taste blade, mongrel!',0,0,0,0,'SAY_GUARD_SIL_AGGRO1'),
(-1070002,'Please tell me that you didn\'t just do what I think you just did. Please tell me that I\'m not going to have to hurt you...',0,0,0,0,'SAY_GUARD_SIL_AGGRO2'),
(-1070003,'As if we don\'t have enough problems, you go and create more!',0,0,0,0,'SAY_GUARD_SIL_AGGRO3'),
(-1070004,'looks up at you quizzically. Maybe you should inspect it?',0,2,0,0,'cluck EMOTE_A_HELLO'),
(-1070005,'looks at you unexpectadly.',0,2,0,0,'cluck EMOTE_H_HELLO'),
(-1070006,'starts pecking at the feed.',0,2,0,0,'cluck EMOTE_CLUCK_TEXT2');
-- r855_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` IN (-1000004,-1000001);
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000001,'goes into a killing frenzy!',0,2,0,0,'EMOTE_GENERIC_FRENZY_KILL'),
(-1000004,'goes into a berserker rage!',0,2,0,0,'EMOTE_GENERIC_BERSERK');
DELETE FROM `script_texts` WHERE `entry` = -1000005;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000005,'Greetings citizen',0,0,7,0,'general_marcus SAY_GREETING');
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1329003 AND -1329000;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1329000,'Thanks to Egan',0,0,0,0,'freed_soul SAY_ZAPPED0'),
(-1329001,'Rivendare must die',0,0,0,0,'freed_soul SAY_ZAPPED1'),
(-1329002,'Who you gonna call?',0,0,0,0,'freed_soul SAY_ZAPPED2'),
(-1329003,'Don\'t cross those beams!',0,0,0,0,'freed_soul SAY_ZAPPED3');
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1999925 AND -1999900;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1999900,'Let the games begin.',8280,1,0,0,'example_creature SAY_AGGRO'),
(-1999901,'I see endless suffering. I see torment. I see rage. I see everything.',8831,1,0,0,'example_creature SAY_RANDOM_0'),
(-1999902,'Muahahahaha',8818,1,0,0,'example_creature SAY_RANDOM_1'),
(-1999903,'These mortal infedels my lord, they have invaded your sanctum and seek to steal your secrets.',8041,1,0,0,'example_creature SAY_RANDOM_2'),
(-1999904,'You are already dead.',8581,1,0,0,'example_creature SAY_RANDOM_3'),
(-1999905,'Where to go? What to do? So many choices that all end in pain, end in death.',8791,1,0,0,'example_creature SAY_RANDOM_4'),
(-1999906,'$N, I sentance you to death!',8588,1,0,0,'example_creature SAY_BESERK'),
(-1999907,'The suffering has just begun!',0,1,0,0,'example_creature SAY_PHASE'),
(-1999908,'I always thought I was a good dancer.',0,0,0,0,'example_creature SAY_DANCE'),
(-1999909,'Move out Soldier!',0,0,0,0,'example_creature SAY_SALUTE'),
(-1999910,'Help $N! I\'m under attack!',0,0,0,0,'example_escort SAY_AGGRO1'),
(-1999911,'Die scum!',0,0,0,0,'example_escort SAY_AGGRO2'),
(-1999912,'Hmm a nice day for a walk alright',0,0,0,0,'example_escort SAY_WP_1'),
(-1999913,'Wild Felboar attack!',0,0,0,0,'example_escort SAY_WP_2'),
(-1999914,'Time for me to go! See ya around $N!',0,0,0,3,'example_escort SAY_WP_3'),
(-1999915,'Bye Bye!',0,0,0,3,'example_escort SAY_WP_4'),
(-1999916,'How dare you leave me like that! I hate you! =*(',0,3,0,0,'example_escort SAY_DEATH_1'),
(-1999917,'...no...how could you let me die $N',0,0,0,0,'example_escort SAY_DEATH_2'),
(-1999918,'ugh...',0,0,0,0,'example_escort SAY_DEATH_3'),
(-1999919,'Taste death!',0,0,0,0,'example_escort SAY_SPELL'),
(-1999920,'Fireworks!',0,0,0,0,'example_escort SAY_RAND_1'),
(-1999921,'Hmm, I think I could use a buff.',0,0,0,0,'example_escort SAY_RAND_2'),
(-1999922,'Normal select, guess you\'re not interested.',0,0,0,0,'example_gossip_codebox SAY_NOT_INTERESTED'),
(-1999923,'Wrong!',0,0,0,0,'example_gossip_codebox SAY_WRONG'),
(-1999924,'You\'re right, you are allowed to see my inner secrets.',0,0,0,0,'example_gossip_codebox SAY_CORRECT'),
(-1999925,'Hi!',0,0,0,0,'example_areatrigger SAY_HI');

-- 1423_mangos_7290_01_world_command
DELETE FROM `command` WHERE `name` = 'npc setdeathstate';
INSERT INTO `command` VALUES
('npc setdeathstate',2,'Syntax: .npc setdeathstate on/off\r\n\r\nSet default death state (dead/alive) for npc at spawn.');

-- 1426_mangos_7292_01_world_points_of_interest
DROP TABLE IF EXISTS `points_of_interest`; 
CREATE TABLE `points_of_interest` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `icon` mediumint(8) unsigned NOT NULL default '0',
  `flags` mediumint(8) unsigned NOT NULL default '0',
  `data` mediumint(8) unsigned NOT NULL default '0',
  `icon_name` text NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 1426_mangos_7292_02_world_locales_points_of_interest
DROP TABLE IF EXISTS `locales_points_of_interest`; 
CREATE TABLE `locales_points_of_interest` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `icon_name_loc1` text,
  `icon_name_loc2` text,
  `icon_name_loc3` text,
  `icon_name_loc4` text,
  `icon_name_loc5` text,
  `icon_name_loc6` text,
  `icon_name_loc7` text,
  `icon_name_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 1463_mangos_7303_01_world_pools
DROP TABLE IF EXISTS `pool_creature`;
CREATE TABLE `pool_creature` (
  `guid` int(10) unsigned NOT NULL default '0',
  `pool_entry` mediumint(8) unsigned NOT NULL default '0',
  `chance` float unsigned NOT NULL default '0',
  PRIMARY KEY  (`pool_entry`,`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pool_gameobject`;
CREATE TABLE `pool_gameobject` (
  `guid` int(10) unsigned NOT NULL default '0',
  `pool_entry` mediumint(8) unsigned NOT NULL default '0',
  `chance` float unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`pool_entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pool_pool`;
CREATE TABLE `pool_pool` (
  `pool_id` mediumint(8) unsigned NOT NULL default '0',
  `mother_pool` mediumint(8) unsigned NOT NULL default '0',
  `chance` float NOT NULL default '0',
  PRIMARY KEY  (`pool_id`,`mother_pool`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pool_template`;
CREATE TABLE `pool_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Pool entry',
  `max_limit` int(10) unsigned NOT NULL default '0' COMMENT 'Max number of objects (0) is no limit',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `game_event_pool`;
CREATE TABLE `game_event_pool` (
  `pool_entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Id of the pool',
  `event` smallint(6) NOT NULL default '0' COMMENT 'Put negatives values to remove during event',
  PRIMARY KEY  (`pool_entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 1470_world_scripts
-- Remove script for quest 8346. Note support for this quest will be added in next ACID release(25)
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (15273,15274,15294,15298,15367);
UPDATE `creature_template` SET `ScriptName`='mob_broggok_poisoncloud' WHERE `entry`=17662;
-- UPDATE `creature_template` SET `ScriptName`='npc_draenei_survivor' WHERE `entry`=16483;

-- 1495_mangos_7312_01_world_trinity_string
DELETE FROM `trinity_string` WHERE entry = 810;
INSERT INTO `trinity_string` VALUES
(810,'|Hplayer:$N|h[$N]|h has earned the achievement $a!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1525_world_scripts
-- Script for Yrykul Skeleton - Prince Keleseth Event
UPDATE `creature_template` SET `ScriptName`='mob_vrykul_skeleton' WHERE `entry`=23970;

-- 1555_mangos_7331_01_world_command
DELETE FROM `command` WHERE `name` = 'account set addon';
DELETE FROM `command` WHERE `name` = 'ban account';
DELETE FROM `command` WHERE `name` = 'ban character';
DELETE FROM `command` WHERE `name` = 'ban ip';
DELETE FROM `command` WHERE `name` = 'baninfo account';
DELETE FROM `command` WHERE `name` = 'baninfo character';
DELETE FROM `command` WHERE `name` = 'baninfo ip';
DELETE FROM `command` WHERE `name` = 'banlist account';
DELETE FROM `command` WHERE `name` = 'banlist character';
DELETE FROM `command` WHERE `name` = 'banlist ip';
DELETE FROM `command` WHERE `name` = 'gm fly';
/* next command deleted even in case it has been already corrected (trailing space) */
DELETE FROM `command` WHERE `name` = 'gobject near ';
DELETE FROM `command` WHERE `name` = 'gobject near';
DELETE FROM `command` WHERE `name` = 'lookup player account';
DELETE FROM `command` WHERE `name` = 'lookup player ip';
DELETE FROM `command` WHERE `name` = 'lookup player email';
DELETE FROM `command` WHERE `name` = 'modify money';
DELETE FROM `command` WHERE `name` = 'modify mount';
DELETE FROM `command` WHERE `name` = 'modify speed';
DELETE FROM `command` WHERE `name` = 'modify titles';
DELETE FROM `command` WHERE `name` = 'pdump write';
DELETE FROM `command` WHERE `name` = 'pdump load';
DELETE FROM `command` WHERE `name` = 'reset honor';
DELETE FROM `command` WHERE `name` = 'reset level';
DELETE FROM `command` WHERE `name` = 'reset spells';
DELETE FROM `command` WHERE `name` = 'reset stats';
DELETE FROM `command` WHERE `name` = 'reset talents';
DELETE FROM `command` WHERE `name` = 'unban account';
DELETE FROM `command` WHERE `name` = 'unban character';
DELETE FROM `command` WHERE `name` = 'unban ip';

INSERT INTO `command` VALUES
('account set addon',3,'Syntax: .account set addon [$account] #addon\r\n\r\nSet user (possible targeted) expansion addon level allowed. Addon values: 0 - normal, 1 - tbc, 2 - wotlk.'),
('ban account',3,'Syntax: .ban account $Name $bantime $reason\r\nBan account kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('ban character',3,'Syntax: .ban character $Name $bantime $reason\r\nBan account and kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('ban ip',3,'Syntax: .ban ip $Ip $bantime $reason\r\nBan IP.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('baninfo account',3,'Syntax: .baninfo account\r\nWatch full information about a specific ban.'),
('baninfo character',3,'Syntax: .baninfo character\r\nWatch full information about a specific ban.'),
('baninfo ip',3,'Syntax: .baninfo ip\r\nWatch full information about a specific ban.'),
('banlist account',3,'Syntax: .banlist account [$Name]\r\nSearches the banlist for a account name pattern or show full list account bans.'),
('banlist character',3,'Syntax: .banlist character $Name\r\nSearches the banlist for a character name pattern. Pattern required.'),
('banlist ip',3,'Syntax: .banlist ip [$Ip]\r\nSearches the banlist for a IP pattern or show full list of IP bans.'),
('gm fly',3,'Syntax: .gm fly [on/off]\r\nEnable/disable gm fly mode.'),
('gobject near',3,'Syntax: .gobject near  [#distance]\r\n\r\nOutput gameobjects at distance #distance from player. Output gameobject guids and coordinates sorted by distance from character. If #distance not provided use 10 as default value.'),
('lookup player account',2,'Syntax: .lookup player account $account ($limit) \r\n\r\n Searchs players, which account username is $account with optional parametr $limit of results.'),
('lookup player ip',2,'Syntax: .lookup player ip $ip ($limit) \r\n\r\n Searchs players, which account ast_ip is $ip with optional parametr $limit of results.'),
('lookup player email',2,'Syntax: .lookup player email $email ($limit) \r\n\r\n Searchs players, which account email is $email with optional parametr $limit of results.'),
('modify money',1,'Syntax: .modify money #money\r\n.money #money\r\n\r\nAdd or remove money to the selected player. If no player is selected, modify your money.\r\n\r\n #gold can be negative to remove money.'),
('modify mount',1,'Syntax: .modify mount #id #speed\r\nDisplay selected player as mounted at #id creature and set speed to #speed value.'),
('modify speed',1,'Syntax: .modify speed #rate\r\n.speed #rate\r\n\r\nModify the running speed of the selected player to \"normal base run speed\"*rate. If no player is selected, modify your speed.\r\n\r\n #rate may range from 0.1 to 10.'),
('modify titles',1,'Syntax: .modify titles #mask\r\n\r\nAllows user to use all titles from #mask.\r\n\r\n #mask=0 disables the title-choose-field'),
('pdump write',3,'Syntax: .pdump write $filename $playerNameOrGUID\r\nWrite character dump with name/guid $playerNameOrGUID to file $filename.'),
('pdump load',3,'Syntax: .pdump load $filename $account [$newname] [$newguid]\r\nLoad character dump from dump file into character list of $account with saved or $newname, with saved (or first free) or $newguid guid.'),
('reset honor',3,'Syntax: .reset honor [Playername]\r\n  Reset all honor data for targeted character.'),
('reset level',3,'Syntax: .reset level [Playername]\r\n  Reset level to 1 including reset stats and talents.  Equipped items with greater level requirement can be lost.'),
('reset spells',3,'Syntax: .reset spells [Playername]\r\n  Removes all non-original spells from spellbook.\r\n. Playername can be name of offline character.'),
('reset stats',3,'Syntax: .reset stats [Playername]\r\n  Resets(recalculate) all stats of the targeted player to their original VALUESat current level.'),
('reset talents',3,'Syntax: .reset talents [Playername]\r\n  Removes all talents of the targeted player. Playername can be name of offline character.'),
('unban account',3,'Syntax: .unban account $Name\r\nUnban accounts for account name pattern.'),
('unban character',3,'Syntax: .unban character $Name\r\nUnban accounts for character name pattern.'),
('unban ip',3,'Syntax : .unban ip $Ip\r\nUnban accounts for IP pattern.');

-- 1558_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '44869' AND `spell_effect` = '-45018';
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '46019' AND `spell_effect` = '-45018';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(44869, -45018, 1, 'Remove Arcane Buffet'),
(46019, -45018, 1, 'Remove Arcane Buffet');

-- 1559_world
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(48077, 48075, 0, 'Holy Nova (rank8)'),
(48078, 48076, 0, 'Holy Nova (rank9)'),
(47585, 60069, 0, 'Dispersion (transform/regen)');
DELETE FROM `spell_proc_event` WHERE `entry` IN (47549);
INSERT INTO `spell_proc_event` VALUES (47549, 0x00, 6, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
DELETE FROM `spell_proc_event` WHERE `entry` IN (47551);
INSERT INTO `spell_proc_event` VALUES (47551, 0x00, 6, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
DELETE FROM `spell_proc_event` WHERE `entry` IN (47552);
INSERT INTO `spell_proc_event` VALUES (47552, 0x00, 6, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- 1576_mangos_7332_01_world_command
DELETE FROM `command` WHERE `name` = 'distance';
INSERT INTO `command` VALUES
('distance',3,'Syntax: .distance [$name/$link]\r\n\r\nDisplay the distance from your character to the selected creature/player, or player with name $name, or player/creature/gameobject pointed to shift-link with guid.');

-- 1605_mangos_7349_01_world_spell_area
DROP TABLE IF EXISTS `spell_area`;
CREATE TABLE `spell_area` (
  `spell`              mediumint(8) unsigned NOT NULL default '0',
  `area`               mediumint(8) unsigned NOT NULL default '0',
  `quest_start`        mediumint(8) unsigned NOT NULL default '0',
  `quest_start_active` tinyint(1) unsigned NOT NULL default '0',
  `quest_end`          mediumint(8) unsigned NOT NULL default '0',
  `aura_spell`         mediumint(8) unsigned NOT NULL default '0',
  `racemask`           mediumint(8) unsigned NOT NULL default '0',
  `gender`             tinyint(1) unsigned NOT NULL default '2',
  `autocast`           tinyint(1) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spell`,`area`,`quest_start`,`quest_start_active`,`aura_spell`,`racemask`,`gender`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 1613_world_scripts
-- Script for Skarvald and Dalronn
UPDATE `creature_template` SET `ScriptName`= 'boss_skarvald_the_constructor' WHERE `entry` IN (24200,27390);
UPDATE `creature_template` SET `ScriptName`= 'boss_dalronn_the_controller' WHERE `entry` IN (24201,27389);

-- 1618_world
-- Glyph of power word: shield
INSERT INTO `spell_proc_event` VALUES (55672, 0x00, 6, 0x00000001, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 0);
-- Bloodsurge
DELETE FROM `spell_proc_event` WHERE `entry` IN (46915);
INSERT INTO `spell_proc_event` VALUES (46915, 0x00, 4, 0x00000040, 0x00000404, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- 1646_mangos_7369_01_world_quest_template
ALTER TABLE quest_template
  DROP COLUMN ReqSourceRef1,
  DROP COLUMN ReqSourceRef2,
  DROP COLUMN ReqSourceRef3,
  DROP COLUMN ReqSourceRef4;

-- 1654_world
INSERT INTO `spell_proc_event` VALUES (17619, 0x00, 13, 0x00000000, 0x00000000, 0x00000000, 0x00008000, 0x00000000, 0.000000, 0.000000, 0);

-- 1657_world
DELETE FROM `trinity_string` WHERE `entry`=1010;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES(1010, "|    Account    |       Character      |       IP        | GM | EXP |");

-- 1661_world
-- Death Strike
INSERT INTO `spell_proc_event` VALUES (45469, 0x00, 15, 0x00000010, 0x00000000, 0x00000000, 0x00000010, 0x00000000, 0.000000, 0.000000, 0);

-- 1663_mangos_7376_01_world_spell_area
ALTER TABLE spell_area
  CHANGE COLUMN `aura_spell`  `aura_spell` mediumint(8) NOT NULL default '0';

-- 1688_mangos_7382_01_world_creature_template
ALTER TABLE creature_template
  ADD COLUMN unk16 float NOT NULL default '1' AFTER InhabitType,
  ADD COLUMN unk17 float NOT NULL default '1' AFTER unk16;
  
-- 1693_world
-- Update Proc Rate
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
('60442', '0', '0', '0', '0', '0', '0', '0', '0', '0', '45'),
('57345', '0', '0', '0', '0', '0', '0', '0', '0', '0', '45'),
('61356', '0', '0', '0', '0', '0', '0', '0', '0', '0', '45'),
('54707', '0', '0', '0', '0', '0', '0', '0', '0', '0', '60'),
('54808', '0', '0', '0', '0', '0', '0', '0', '0', '0', '60');
-- Update Spell Coefficients 
DELETE FROM `spell_bonus_data` WHERE `entry` IN ('689', '18790', '172', '42223', '42224', '42225', '42226', '42218', '47817', '47818', '1949', '5857', '11681', '11682', '27214', '47822', '27243', '30108', '17962', '6789', '48181', '29722', '5676', '686', '17877', '30283', '1120', '30294', '44425', '42208', '42209', '42210', '42211', '42212', '42213', '42198', '42937', '42938', '11113', '31661', '120', '19750', '635', '25914', '25913', '25903', '27175', '33074', '48820', '48821', '58597', '31803', '53742', '31893', '32221', '53719', '53718', '20167', '20424', '31804', '53733', '31898', '32220', '53726', '53725', '20267', '20187', '20467', '53600', '596', '2944', '8092', '27813', '27817', '27818', '33619');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `comments`) VALUES
('689', '0', '0.143', '0', 'Warlock - Drain Life'),
('18790', '0', '0', '0','Warlock - Fel Stamina'),
('172', '0', '0.2', '0', 'Warlock - Corruption'),
('42223', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 1'),
('42224', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 2'),
('42225', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 3'),
('42226', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 4'),
('42218', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 5'),
('47817', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 6'),
('47818', '0.6932', '0', '0', 'Warlock - Rain of Fire Triggered Rank 7'),
('1949', '0', '0.0949', '0', 'Warlock - Hellfire'),
('5857', '0.1427', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 1'),
('11681', '0.1427', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 2'),
('11682', '0.1427', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 3'),
('27214', '0.1427', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 4'),
('47822', '0.1427', '0', '0', 'Warlock - Hellfire Effect on Enemy Rank 5'),
('27243', '0.2129', '0.25', '0', 'Warlock - Seed of Corruption'),
('30108', '0', '0.2', '0', 'Warlock - Unstable Affliction'),
('17962', '0.4293', '0', '0', 'Warlock - Conflagrate'),
('6789', '0.214', '0', '0', 'Warlock - Death Coil'),
('48181', '0.4793', '0', '0', 'Warlock - Haunt'),
('29722', '0.7139', '0', '0', 'Warlock - Incinerate'),
('5676', '0.4293', '0', '0', 'Warlock - Searing Pain'),
('686', '0.8569', '0', '0', 'Warlock - Shadow Bolt'),
('17877', '0.4293', '0', '0', 'Warlock - Shadowburn'),
('30283', '0.1932', '0', '0', 'Warlock - Shadowfury'),
('1120', '0', '0.429', '0', 'Warlock - Drain Soul'),
('30294', '0', '0', '0', 'Warlock - Soul Leech'),
('44425', '0.7143', '0', '0', 'Mage - Arcane Barrage'),
('42208', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 1'),
('42209', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 2'),
('42210', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 3'),
('42211', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 4'),
('42212', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 5'),
('42213', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 6'),
('42198', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 7'),
('42937', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 8'),
('42938', '0.1437', '0', '0', 'Mage - Blizzard Triggered Spell Rank 9'),
('11113', '0.1936', '0', '0', 'Mage - Blast Wave Rank'),
('31661', '0.1936', '0', '0', 'Mage - Dragons Breath'),
('120', '0.214', '0', '0', 'Mage - Cone of Cold'),
('19750', '1', '0', '0', 'Paladin - Flash of Light'),
('635', '1.66', '0', '0', 'Paladin - Holy Light'),
('25914', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 1'),
('25913', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 2'),
('25903', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 3'),
('27175', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 4'),
('33074', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 5'),
('48820', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 6'),
('48821', '0.81', '0', '0', 'Paladin - Holy Shock Triggered Heal Rank 7'),
('58597', '0.75', '0', '0', 'Paladin - Sacred Shield'),
('31803', '0', '0.018', '0.03', 'Paladin - Holy Vengeance'),
('53742', '0', '0.018', '0.03', 'Paladin - Blood Corruption'),
('31893', '0', '0', '0', 'Paladin - Seal of Blood Enemy Proc'),
('32221', '0', '0', '0', 'Paladin - Seal of Blood Self Proc'),
('53719', '0', '0', '0', 'Paladin - Seal of The Martyr Enemy Proc'),
('53718', '0', '0', '0', 'Paladin - Seal of The Martyr Self Proc'),
('20167', '0.15', '0', '0.15', 'Paladin - Seal of Light Proc'),
('20424', '0.1035', '0', '0', 'Paladin - Seal of Command Proc'),
('31804', '0.22', '0', '0.14', 'Paladin - Judgement of Vengeance'),
('53733', '0.22', '0', '0.14', 'Paladin - Judgement of Corruption'),
('31898', '0.25', '0', '0.16', 'Paladin - Judgement of Blood Enemy'),
('32220', '0', '0', '0', 'Paladin - Judgement of Blood Self'),
('53726', '0.25', '0', '0.16', 'Paladin - Judgement of the Martyr Enemy'),
('53725', '0', '0', '0', 'Paladin - Judgement of the Martyr Self'),
('20267', '0.1', '0', '0.1', 'Paladin - Judgement of Light Proc'),
('20187', '0.4', '0', '0.25', 'Paladin - Judgement of Righteousness'),
('20467', '0.25', '0', '0.16', 'Paladin - Judgement of Command'),
('53600', '0', '0', '0', 'Paladin - Shield of Righteousness'),
('596', '0.8068', '0', '0', 'Priest - Prayer of Healing'),
('2944', '0.8149', '0', '0', 'Priest - Devouring Plague'),
('8092', '0.428', '0', '0', 'Priest - Mind Blast'),
('27813', '0', '0', '0', 'Priest - Blessed Recovery Rank 1'),
('27817', '0', '0', '0', 'Priest - Blessed Recovery Rank 2'),
('27818', '0', '0', '0', 'Priest - Blessed Recovery Rank 3'),
('33619', '0', '0', '0', 'Priest - Reflective Shield');

-- 1694_world
-- Sanctified Wrath
INSERT INTO `spell_proc_event` VALUES (57318, 0x00, 10, 0x00000000, 0x00002000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 6);
INSERT INTO `spell_proc_event` VALUES (53375, 0x00, 10, 0x00000000, 0x00002000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 6);
-- Star Sinner
DELETE FROM `spell_proc_event` WHERE `entry` IN (54738);
INSERT INTO `spell_proc_event`  VALUES (54738, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 45);
-- Tentacles
DELETE FROM `spell_proc_event` WHERE `entry` IN (61618);
INSERT INTO `spell_proc_event`  VALUES (61618, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);
-- Demonic Sacrifice
DELETE FROM `spell_bonus_data` WHERE `entry` = 18790;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`comments`) VALUES
('18790','0','0','0','Warlock - Fel Stamina');

-- 1697_mangos_7388_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (750,751);
INSERT INTO `trinity_string` VALUES
(750,'Not enough players. This game will close in %u mins.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(751,'Not enough players. This game will close in %u seconds.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1703_world
DROP TABLE IF EXISTS `access_requirement`;
CREATE TABLE `access_requirement` (
  `id` bigint(20) unsigned NOT NULL COMMENT 'Identifier',
  `level_min` tinyint(3) unsigned NOT NULL default '0',
  `level_max` tinyint(3) unsigned NOT NULL default '0',
  `item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `item2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_key` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_key2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `quest_failed_text` TEXT NULL DEFAULT NULL,
  `heroic_quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_quest_failed_text` TEXT NULL DEFAULT NULL,
  `comment` TEXT NULL DEFAULT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Access Requirements';

ALTER TABLE `instance_template`
 DROP COLUMN `levelMin`,
 DROP COLUMN `levelMax`,
 ADD COLUMN `access_id` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `reset_delay`;

ALTER TABLE `areatrigger_teleport`
 DROP COLUMN `required_level`,
 DROP COLUMN `required_item`,
 DROP COLUMN `required_item2`,
 DROP COLUMN `heroic_key`,
 DROP COLUMN `heroic_key2`,
 DROP COLUMN `heroic_required_quest_done`,
 DROP COLUMN `heroic_required_failed_quest_text`,
 DROP COLUMN `required_quest_done`,
 DROP COLUMN `required_failed_text`,
 ADD COLUMN `access_id` bigint(20) unsigned NOT NULL DEFAULT '0' AFTER `name`;

INSERT INTO `access_requirement` VALUES
('1','10','0','0','0','0','0','0',NULL,'0',NULL,'instance Shadowfang Keep (33)'),
('2','15','0','0','0','0','0','0',NULL,'0',NULL,'instance The Stockade (34)'),
('3','10','0','0','0','0','0','0',NULL,'0',NULL,'instance The Deadmines (36)'),
('4','10','0','0','0','0','0','0',NULL,'0',NULL,'instance Wailing Caverns (43)'),
('5','15','0','0','0','0','0','0',NULL,'0',NULL,'instance Razorfen Kraul (47)'),
('6','10','0','0','0','0','0','0',NULL,'0',NULL,'instance Blackfathom Deeps (48)'),
('7','30','0','0','0','0','0','0',NULL,'0',NULL,'instance Uldaman (70)'),
('8','15','0','0','0','0','0','0',NULL,'0',NULL,'instance Gnomeregan (90)'),
('9','35','0','0','0','0','0','0',NULL,'0',NULL,'instance Sunken Temple (109)'),
('10','25','0','0','0','0','0','0',NULL,'0',NULL,'instance Razorfen Downs (129)'),
('11','20','0','0','0','0','0','0',NULL,'0',NULL,'instance Scarlet Monastery (189)'),
('12','35','0','0','0','0','0','0',NULL,'0',NULL,'instance Zul\'Farrak (209)'),
('13','45','0','0','0','0','0','0',NULL,'0',NULL,'instance Blackrock Spire (229)'),
('14','40','0','0','0','0','0','0',NULL,'0',NULL,'instance Blackrock Depths (230)'),
('15','55','0','16309','0','0','0','0',NULL,'0',NULL,'instance Onyxia\'s Lair (249)'),
('16','66','0','0','0','30635','0','10285','You can\'t enter Black Morass until you rescue Thrall from Durnholde Keep.','0',NULL,'instance The Black Morass (269)'),
('17','45','0','13704','0','0','0','0',NULL,'0',NULL,'instance Scholomance (289)'),
('18','50','0','0','0','0','0','0',NULL,'0',NULL,'instance Zul\'Gurub (309)'),
('19','45','0','0','0','0','0','0',NULL,'0',NULL,'instance Stratholme (329)'),
('20','30','0','0','0','0','0','0',NULL,'0',NULL,'instance Maraudon (349)'),
('21','8','0','0','0','0','0','0',NULL,'0',NULL,'instance Ragefire Chasm (389)'),
('22','50','0','0','0','0','0','7487',NULL,'0',NULL,'instance Molten Core (409)'),
('23','45','0','0','0','0','0','0',NULL,'0',NULL,'instance Dire Maul (429)'),
('24','60','0','0','0','0','0','7761',NULL,'0',NULL,'instance Blackwing Lair (469)'),
('25','60','0','0','0','0','0','0',NULL,'0',NULL,'instance Ruins of Ahn\'Qiraj (509)'),
('26','60','0','0','0','0','0','0',NULL,'0',NULL,'instance Temple of Ahn\'Qiraj (531)'),
('27','68','0','0'/*'24490'*/,'0','0','0','0',NULL,'0',NULL,'instance Karazhan (532)'),
('28','60','0','0','0','0','0','0',NULL,'0',NULL,'instance Naxxramas (533)'),
('29','70','0','0','0','0','0','10445',NULL,'0',NULL,'instance Hyjal Summit (534)'),
('30','55','0','0'/*'28395'*/,'0','30637','30622','0',NULL,'0',NULL,'instance The Shattered Halls (540)'),
('31','55','0','0','0','30637','30622','0',NULL,'0',NULL,'instance The Blood Furnace (542)'),
('32','55','0','0','0','30637','30622','0',NULL,'0',NULL,'instance Hellfire Ramparts (543)'),
('33','65','0','0','0','0','0','0',NULL,'0',NULL,'instance Magtheridon\'s Lair (544)'),
('34','55','0','0','0','30623','0','0',NULL,'0',NULL,'instance The Steamvault (545)'),
('35','55','0','0','0','30623','0','0',NULL,'0',NULL,'instance The Underbog (546)'),
('36','55','0','0','0','30623','0','0',NULL,'0',NULL,'instance The Slave Pens (547)'),
('37','70','0','0','0','0','0','0'/*'10901'*/,NULL,'0',NULL,'instance Serpentshrine Cavern (548)'),
('38','70','0','0'/*'31704'*/,'0','0','0','0',NULL,'0',NULL,'instance The Eye (550)'),
('39','68','0','0'/*'31084'*/,'0','30634','0','0',NULL,'0',NULL,'instance The Arcatraz (552)'),
('40','68','0','0','0','30634','0','0',NULL,'0',NULL,'instance The Botanica (553)'),
('41','68','0','0','0','30634','0','0',NULL,'0',NULL,'instance The Mechanar (554)'),
('42','65','0','27991','0','30633','0','0',NULL,'0',NULL,'instance Shadow Labyrinth (555)'),
('43','55','0','0','0','30633','0','0',NULL,'0',NULL,'instance Sethekk Halls (556)'),
('44','55','0','0','0','30633','0','0',NULL,'0',NULL,'instance Mana-Tombs (557)'),
('45','55','0','0','0','30633','0','0',NULL,'0',NULL,'instance Auchenai Crypts (558)'),
('46','66','0','0','0','30635','0','0',NULL,'0',NULL,'instance Old Hillsbrad Foothills (560)'),
('47','70','0','32649','0','0','0','0',NULL,'0',NULL,'instance Black Temple (564)'),
('48','65','0','0','0','0','0','0',NULL,'0',NULL,'instance Gruul\'s Lair (565)'),
('49','70','0','0','0','0','0','0',NULL,'0',NULL,'instance Zul\'Aman (568)'),
('50','70','0','0','0','0','0','0',NULL,'0',NULL,'instance Sunwell Plateau (580)'),
('51','70','0','0','0','0','0','0',NULL,'11492','Heroic Difficulty requires completion of the "Hard to Kill" quest.','instance Magisters\' Terrace (585)'),
('52','58','0','0','0','0','0','0',NULL,'0',NULL,'Dark Portal');
UPDATE `instance_template` SET `access_id` = '1' WHERE `map` = '33';
UPDATE `instance_template` SET `access_id` = '2' WHERE `map` = '34';
UPDATE `instance_template` SET `access_id` = '3' WHERE `map` = '36';
UPDATE `instance_template` SET `access_id` = '4' WHERE `map` = '43';
UPDATE `instance_template` SET `access_id` = '5' WHERE `map` = '47';
UPDATE `instance_template` SET `access_id` = '6' WHERE `map` = '48';
UPDATE `instance_template` SET `access_id` = '7' WHERE `map` = '70';
UPDATE `instance_template` SET `access_id` = '8' WHERE `map` = '90';
UPDATE `instance_template` SET `access_id` = '9' WHERE `map` = '109';
UPDATE `instance_template` SET `access_id` = '10' WHERE `map` = '129';
UPDATE `instance_template` SET `access_id` = '11' WHERE `map` = '189';
UPDATE `instance_template` SET `access_id` = '12' WHERE `map` = '209';
UPDATE `instance_template` SET `access_id` = '13' WHERE `map` = '229';
UPDATE `instance_template` SET `access_id` = '14' WHERE `map` = '230';
UPDATE `instance_template` SET `access_id` = '15' WHERE `map` = '249';
UPDATE `instance_template` SET `access_id` = '16' WHERE `map` = '269';
UPDATE `instance_template` SET `access_id` = '17' WHERE `map` = '289';
UPDATE `instance_template` SET `access_id` = '18' WHERE `map` = '309';
UPDATE `instance_template` SET `access_id` = '19' WHERE `map` = '329';
UPDATE `instance_template` SET `access_id` = '20' WHERE `map` = '349';
UPDATE `instance_template` SET `access_id` = '21' WHERE `map` = '389';
UPDATE `instance_template` SET `access_id` = '22' WHERE `map` = '409';
UPDATE `instance_template` SET `access_id` = '23' WHERE `map` = '429';
UPDATE `instance_template` SET `access_id` = '24' WHERE `map` = '469';
UPDATE `instance_template` SET `access_id` = '25' WHERE `map` = '509';
UPDATE `instance_template` SET `access_id` = '26' WHERE `map` = '531';
UPDATE `instance_template` SET `access_id` = '27' WHERE `map` = '532';
UPDATE `instance_template` SET `access_id` = '28' WHERE `map` = '533';
UPDATE `instance_template` SET `access_id` = '29' WHERE `map` = '534';
UPDATE `instance_template` SET `access_id` = '30' WHERE `map` = '540';
UPDATE `instance_template` SET `access_id` = '31' WHERE `map` = '542';
UPDATE `instance_template` SET `access_id` = '32' WHERE `map` = '543';
UPDATE `instance_template` SET `access_id` = '33' WHERE `map` = '544';
UPDATE `instance_template` SET `access_id` = '34' WHERE `map` = '545';
UPDATE `instance_template` SET `access_id` = '35' WHERE `map` = '546';
UPDATE `instance_template` SET `access_id` = '36' WHERE `map` = '547';
UPDATE `instance_template` SET `access_id` = '37' WHERE `map` = '548';
UPDATE `instance_template` SET `access_id` = '38' WHERE `map` = '550';
UPDATE `instance_template` SET `access_id` = '39' WHERE `map` = '552';
UPDATE `instance_template` SET `access_id` = '40' WHERE `map` = '553';
UPDATE `instance_template` SET `access_id` = '41' WHERE `map` = '554';
UPDATE `instance_template` SET `access_id` = '42' WHERE `map` = '555';
UPDATE `instance_template` SET `access_id` = '43' WHERE `map` = '556';
UPDATE `instance_template` SET `access_id` = '44' WHERE `map` = '557';
UPDATE `instance_template` SET `access_id` = '45' WHERE `map` = '558';
UPDATE `instance_template` SET `access_id` = '46' WHERE `map` = '560';
UPDATE `instance_template` SET `access_id` = '47' WHERE `map` = '564';
UPDATE `instance_template` SET `access_id` = '48' WHERE `map` = '565';
UPDATE `instance_template` SET `access_id` = '49' WHERE `map` = '568';
UPDATE `instance_template` SET `access_id` = '50' WHERE `map` = '580';
UPDATE `instance_template` SET `access_id` = '51' WHERE `map` = '585';
UPDATE `areatrigger_teleport` SET `access_id` = '52' WHERE `id` IN ('4352','4354');

-- 1709_mangos_7393_01_world_game_event
ALTER TABLE `game_event`
  ADD COLUMN `holiday` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Client side holiday id' AFTER `length`;
  
-- 1724_mangos_7399_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (753, 754, 755);
INSERT INTO `trinity_string` VALUES
(753,'The battle for Warsong Gulch begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(754,'The battle for Arathi Basin begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(755,'The battle for Eye of the Storm begins in 2 minutes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1727_world
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES (42857,1,23954);

-- 1727_world_script
UPDATE `creature_template` SET `ScriptName`='boss_ingvar_the_plunderer' WHERE `entry`=23954;
UPDATE `creature_template` SET `ScriptName`='mob_annhylde_the_caller' WHERE `entry`=24068;
UPDATE `creature_template` SET `ScriptName`='mob_ingvar_throw_dummy' WHERE `entry`=23997;

-- 1729_world
-- Judgements of the Wise
REPLACE INTO `spell_proc_event` VALUES (31876, 0x00, 10, 0x20180400, 0x0000008, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
REPLACE INTO `spell_proc_event` VALUES (31877, 0x00, 10, 0x20180400, 0x0000008, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
REPLACE INTO `spell_proc_event` VALUES (31878, 0x00, 10, 0x20180400, 0x0000008, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- 1730_world
-- Faerie fire
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `comments`) VALUES ('60089', '0', '0', '0.05', 'Druid - Faerie Fire (Bear Form)');
-- Glyph of Devastate
INSERT INTO `spell_proc_event` VALUES (58388, 0x00, 4, 0x00000040, 0x00000000, 0x00000000, 0x00000110, 0x00000000, 0.000000, 0.000000, 0);

-- 1755_world
DELETE FROM spell_proc_event WHERE entry IN (47535, 47536, 47537, 47538, 47539,34074,58426,31221,31222,31223);
-- Rapture
INSERT INTO `spell_proc_event` VALUES (47535, 0x00, 6, 0x1800, 0x10000, 0x00000000, 0x00014010, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (47536, 0x00, 6, 0x1800, 0x10000, 0x00000000, 0x00014010, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (47537, 0x00, 6, 0x1800, 0x10000, 0x00000000, 0x00014010, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (47538, 0x00, 6, 0x1800, 0x10000, 0x00000000, 0x00014010, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (47539, 0x00, 6, 0x1800, 0x10000, 0x00000000, 0x00014010, 0x00000000, 0.000000, 0.000000, 0);
-- Aspect of the viper
INSERT INTO `spell_proc_event` VALUES (34074, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0.000000, 0.000000, 0);
-- Overkill
INSERT INTO `spell_proc_event` VALUES (58426, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x00000000, 0.000000, 0.000000, 0);
-- Master of subtlety
INSERT INTO `spell_proc_event` VALUES (31221, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (31222, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (31223, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x00000000, 0.000000, 0.000000, 0);
DELETE FROM `spell_bonus_data` WHERE entry=2944;
INSERT INTO `spell_bonus_data` VALUES ('2944', '0', '0.1849', '0', 'Priest - Devouring Plague');

-- 1764_world
DELETE FROM spell_proc_event WHERE entry IN (54149,53672,20210,20212,20213,20214,20215);
-- Infusion of Light
INSERT INTO `spell_proc_event` VALUES (54149, 0x00, 10, 2097152, 65536, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (53672, 0x00, 10, 2097152, 65536, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- Illumination
INSERT INTO `spell_proc_event` VALUES (20210, 0x00, 10, 3221225472, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (20212, 0x00, 10, 3221225472, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (20213, 0x00, 10, 3221225472, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (20214, 0x00, 10, 3221225472, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (20215, 0x00, 10, 3221225472, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- 1766_world
DELETE FROM spell_proc_event WHERE entry IN (33182,33174);
INSERT INTO `spell_proc_event` VALUES (33182, 0x00, 6, 32, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (33174, 0x00, 6, 32, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 0.000000, 0);

-- 1791_mangos_7422_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (811, 812, 813, 814, 815);
INSERT INTO `trinity_string` VALUES
(811,'Guild Master',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(812,'Officer',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(813,'Veteran',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(814,'Member',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(815,'Initiate',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1814_world
-- Improved Fire Nova Totem
DELETE FROM `spell_proc_event` WHERE `entry` IN (16086, 16544);
INSERT INTO `spell_proc_event` VALUES (16086, 0x00, 7, 0, 0x00040000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (16544, 0x00, 7, 0, 0x00040000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- 1825_world
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-47953);
INSERT INTO `spell_linked_spell` VALUES (-47953, 60406, 0, 'Divine hymn buff to enemies');

-- 1828_world
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (48265,49772,48263);
INSERT INTO `spell_linked_spell` VALUES (48265, 49772, 2, 'Unholy Presence');
INSERT INTO `spell_linked_spell` VALUES (49772, 55222, 2, 'Unholy Presence');
INSERT INTO `spell_linked_spell` VALUES (48263, 61261, 2, 'Frost Presence');

-- 1877_mangos_7439_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (175);
INSERT INTO `trinity_string` VALUES
(175,'Liquid level: %f, ground: %f, type: %d, status: %d',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 1884_world
DELETE FROM `trinity_string` WHERE `entry` IN (10056, 10057);

-- 1886_world
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (61847,61846);
INSERT INTO `spell_linked_spell` VALUES (61847, 61848, 2, 'Aspect of te dragonhawk');
INSERT INTO `spell_linked_spell` VALUES (61846, 61848, 2, 'Aspect of te dragonhawk');
-- Glyph of Aspect of the Monkey
DELETE FROM `spell_proc_event` WHERE `entry` IN (13163,61848);
INSERT INTO `spell_proc_event` VALUES (13163, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000010, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (61848, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000010, 0.000000, 0.000000, 0);

-- 1911_world
DELETE FROM `spell_proc_event` WHERE `entry` IN (44545, 44543);
INSERT INTO `spell_proc_event` VALUES
(44545, 0x00, 3, 1049120, 4096, 0x00000000, 0x0010000, 0x00000000, 15.000000, 0.000000, 0),
(44543, 0x00, 3, 1049120, 4096, 0x00000000, 0x0010000, 0x00000000, 7.000000, 0.000000, 0);

-- 1912_world
-- Shattered Barrier
-- Improved Fear
DELETE FROM `spell_proc_event` WHERE `entry` IN (44745, 54787, 53754, 53759);
INSERT INTO `spell_proc_event` VALUES
(44745, 0x00, 3, 0x00000000, 0x00000001, 0x00000000, 0x00008000, 0x0006000, 0.000000, 0.000000, 0),
(54787, 0x00, 3, 0x00000000, 0x00000001, 0x00000000, 0x00008000, 0x0006000, 0.000000, 0.000000, 0),
(53754, 0x00, 5, 0x00000000, 1024, 0x00000000, 0x00000000, 0x0006000, 0.000000, 0.000000, 0),
(53759, 0x00, 5, 0x00000000, 1024, 0x00000000, 0x00000000, 0x0006000, 0.000000, 0.000000, 0);

-- 1927_world
-- Nature's Grace --
DELETE FROM `spell_proc_event` WHERE `entry` IN (16880, 61345, 61346);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(16880, 0x48, 7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0),
(61345, 0x48, 7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0),
(61346, 0x48, 7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- Blade Twisting --
DELETE FROM `spell_proc_event` WHERE `entry` IN (31124, 31126);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(31124, 0x00, 8, 0x01000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0),
(31126, 0x00, 8, 0x01000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- 1939_world
-- Psychic Horror
DELETE FROM `spell_proc_event` WHERE `entry` IN (47571, 47572);
INSERT INTO `spell_proc_event` VALUES
(47571, 0x00, 6, 65536, 0x00000000, 0x00000000, 0x00010000, 0x0006000, 0.000000, 50.000000, 0),
(47572, 0x00, 6, 65536, 0x00000000, 0x00000000, 0x00010000, 0x0006000, 0.000000, 100.000000, 0);

-- 1957_word
-- Furious Attacks
DELETE FROM `spell_proc_event` WHERE `entry` IN (46910, 46911);
INSERT INTO `spell_proc_event` VALUES
(46910, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000001, 5.5000000, 0.000000, 0),
(46911, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000001, 7.5000000, 0.000000, 0);

-- 1962_mangos_7472_01_world_trinity_string
DELETE FROM trinity_string WHERE entry >= 667 and entry <= 687 or entry = 614 or entry = 615;
INSERT INTO trinity_string VALUES
(614,'The Alliance flag is now placed at its base.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(615,'The Horde flag is now placed at its base.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(667,'The Alliance has taken control of the Mage Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(668,'The Horde has taken control of the Mage Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(669,'The Alliance has taken control of the Draenei Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(670,'The Horde has taken control of the Draenei Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(671,'The Alliance has taken control of the Blood Elf Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(672,'The Horde has taken control of the Blood Elf Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(673,'The Alliance has taken control of the Fel Reaver Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(674,'The Horde has taken control of the Fel Reaver Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(675,'The Alliance has lost control of the Mage Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(676,'The Horde has lost control of the Mage Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(677,'The Alliance has lost control of the Draenei Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(678,'The Horde has lost control of the Draenei Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(679,'The Alliance has lost control of the Blood Elf Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(680,'The Horde has lost control of the Blood Elf Tower!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(681,'The Alliance has lost control of the Fel Reaver Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(682,'The Horde has lost control of the Fel Reaver Ruins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(683,'%s has taken the flag!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(684,'The Alliance have captured the flag!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(685,'The Horde have captured the flag!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(686,'The flag has been dropped.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(687,'The flag has been reset.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2013_world
-- Shattered Barrier
DELETE FROM `spell_proc_event` WHERE `entry` IN (44745, 54787, 58426, 31221, 31222, 31223);
INSERT INTO `spell_proc_event` VALUES
(44745, 0x00, 3, 0x00000000, 0x00000001, 0x00000000, 0x00008000, 0x0002000, 0.000000, 0.000000, 0),
(54787, 0x00, 3, 0x00000000, 0x00000001, 0x00000000, 0x00008000, 0x0002000, 0.000000, 0.000000, 0),
-- Overkill
(58426, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0004001, 0.000000, 0.000000, 0),
-- Master of subtlety
(31221, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0004001, 0.000000, 0.000000, 0),
(31222, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0004001, 0.000000, 0.000000, 0),
(31223, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0004001, 0.000000, 0.000000, 0);

-- 2021_world
DELETE FROM `spell_proc_event` WHERE `entry` IN (30293, 30295, 30296);
INSERT INTO `spell_proc_event` VALUES
-- Soul Leech
(30293, 0x00, 5, 0x00000381, 0x200C0, 0x00000000, 0x0000000, 0x0000000, 0.000000, 0.000000, 0),
(30295, 0x00, 5, 0x00000381, 0x200C0, 0x00000000, 0x0000000, 0x0000000, 0.000000, 0.000000, 0),
(30296, 0x00, 5, 0x00000381, 0x200C0, 0x00000000, 0x0000000, 0x0000000, 0.000000, 0.000000, 0);

-- 2025_mangos_7493_01_world_command
DELETE FROM `command` WHERE `name` IN ('gobject near','gobject phase','gobject setphase');
INSERT INTO `command` VALUES
('gobject near',2,'Syntax: .gobject near  [#distance]\r\n\r\nOutput gameobjects at distance #distance from player. Output gameobject guids and coordinates sorted by distance from character. If #distance not provided use 10 as default value.'),
('gobject setphase',2,'Syntax: .gobject setphase #guid #phasemask\r\n\r\nGameobject with DB guid #guid phasemask changed to #phasemask with related world vision update for players. Gameobject state saved to DB and persistent.');

-- 2025_mangos_7495_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (276,277,524);
INSERT INTO `trinity_string` VALUES
(276,'Game Object |cffffffff|Hgameobject:%d|h[%s]|h|r (GUID: %u) turned',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(277,'Game Object |cffffffff|Hgameobject:%d|h[%s]|h|r (GUID: %u) moved',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(524,'Selected object:\n|cffffffff|Hgameobject:%d|h[%s]|h|r GUID: %u ID: %u\nX: %f Y: %f Z: %f MapId: %u\nOrientation: %f',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2057_world
DELETE FROM `spell_bonus_data` WHERE `entry` IN (15290, 39373, 33778, 379, 38395, 40972, 22845, 33504, 34299);
INSERT INTO `spell_bonus_data` VALUES
(15290, 0, 0, 0, 'Vampiric Embrace'),
(39373, 0, 0, 0, 'Shadowmend'),
(33778, 0, 0, 0, 'Lifebloom'),
(379, 0, 0, 0, 'Earth Shield'),
(38395, 0, 0, 0, 'Siphon Essence'),
(40972, 0, 0, 0, 'Heal'),
(22845, 0, 0, 0, 'Frenzied Regeneration'),
(33504, 0, 0, 0, 'Mark of Conquest'),
(34299, 0, 0, 0, 'Improved Leader of the Pack');

-- 2064_world
DELETE FROM `trinity_string` WHERE `entry` IN (7523,7524);
INSERT INTO `trinity_string` VALUES
(7523,'WORLD: Denying connections.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(7524,'WORLD: Accepting connections.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
DELETE FROM `command` WHERE `name` IN ('server set closed');
INSERT INTO `command` VALUES ('server set closed', 3, 'Syntax: server set closed on/off\r\n\r\nSets whether the world accepts new client connectsions.');

-- 2080_mangos_7503_01_world_command
DELETE FROM `command` WHERE `name` IN ('addmove','allowmove','debug Mod32Value','debug standstate','go creature','go graveyard','go trigger','gobject phase','gobject setphase','Mod32Value','modify arena','modify standstate','npc addmove','npc allowmove','npc textemote','npc phase','npc setphase','showhonor');
INSERT INTO `command` VALUES
('debug Mod32Value',3,'Syntax: .debug Mod32Value #field #value\r\n\r\nAdd #value to field #field of your character.'),
('go creature',1,'Syntax: .go creature #creature_guid\r\nTeleport your character to creature with guid #creature_guid.\r\n.gocreature #creature_name\r\nTeleport your character to creature with this name.\r\n.gocreature id #creature_id\r\nTeleport your character to a creature that was spawned from the template with this entry.\r\n*If* more than one creature is found, then you are teleported to the first that is found inside the database.'),
('go graveyard',1,'Syntax: .go graveyard #graveyardId\r\n Teleport to graveyard with the graveyardId specified.'),
('go trigger',1,'Syntax: .go trigger #trigger_id\r\n\r\nTeleport your character to areatrigger with id #trigger_id. Character will be teleported to trigger target if selected areatrigger is telporting trigger.'),
('gobject setphase',2,'Syntax: .gobject setphase #guid #phasemask\r\n\r\nGameobject with DB guid #guid phasemask changed to #phasemask with related world vision update for players. Gameobject state saved to DB and persistent.'),
('modify arena',1,'Syntax: .modify arena #value\r\nAdd $amount arena points to the selected player.'),
('modify standstate',2,'Syntax: .modify standstate #emoteid\r\n\r\nChange the emote of your character while standing to #emoteid.'),
('npc addmove',2,'Syntax: .npc addmove #creature_guid [#waittime]\r\n\r\nAdd your current location as a waypoint for creature with guid #creature_guid. And optional add wait time.'),
('npc allowmove',3,'Syntax: .npc allowmove\r\n\r\nEnable or disable movement creatures in world. Not implemented.'),
('npc setphase',2,'Syntax: .npc setphase #phasemask\r\n\r\nSelected unit or pet phasemask changed to #phasemask with related world vision update for players. In creature case state saved to DB and persistent. In pet case change active until in game phase changed for owner, owner re-login, or GM-mode enable/disable..'),
('npc textemote',1,'Syntax: .npc textemote #emoteid\r\n\r\nMake the selected creature to do textemote with an emote of id #emoteid.');

-- 2131_world
DELETE FROM `command` WHERE `name` IN ('server difftime', 'npc tempadd', 'gobject tempadd', '');
INSERT INTO `command` VALUES
('gobject tempadd','2','Adds a temporary gameobject that is not saved to DB.'),
('npc tempadd','2','Adds temporary NPC, not saved to database.');
UPDATE `command` SET `name`="ahbotoption" WHERE `name`="ahbotoptions";
DELETE FROM `command` WHERE `name` IN ('reload tickets');
DELETE FROM `command` WHERE `name` LIKE "path%";
DELETE FROM `command` WHERE `name` LIKE "wp%";
INSERT INTO `command` VALUES 
('wp load',2,'Syntax: .path load $pathid\nLoad pathid number for selected creature. Creature must have no waypoint data.'),
('wp event',2,'Syntax: .path event $subcommand\nType .path event to see the list of possible subcommands or .help path event $subcommand to see info on subcommands.'),
('wp event add',2,'Syntax: .path event add $subcommand\nAdd new waypoint action in DB.'),
('wp event mod',2,'Syntax: .path mod $eventid $parameter $parameter_value\nModify parameter value for specified eventid.\nPossible parameters: pos_x, pos_y, pos_z, command, datalong, datalon2, dataint.'),
('wp event listid',2,'Syntax: .path event listid $eventid\nShows specified eventid info.'),
('wp unload',2,'Syntax: .path unload\nUnload path for selected creature.'),
('wp show',2,'Syntax: .path show $option\nOptions:\non $pathid (or selected creature with loaded path) - Show path\noff - Hide path\ninfo $slected_waypoint - Show info for selected waypoint.'),
('wp mod ',2,'Syntax: .path mod\nType .path mod to see the list of possible subcommands or .help path mod $subcommand to see info on subcommands.'),
('wp mod del',2,'Syntax: .path mod del\nDelete selected waypoint.'),
('wp mod move',2,'Syntax: .path mod move\nChange selected waypoint coordinates to your position.'),
('wp mod move_flag',2,'Syntax: .path mod move_flag\nSet move/run flag.'),
('wp mod action',2,'Syntax: .path mod action\nAssign action (waypoint script id) to selected waypoint.'),
('wp mod action_chance',2,'Syntax: .path mod action_chance\nAssign chance.');

-- 2138_world
DELETE FROM `spell_proc_event` WHERE `entry` IN (55198, 34026);
INSERT INTO `spell_proc_event` VALUES
-- Tidial Force
(55198, 0x00, 11, 0x000001C0, 0x00000000, 0x00000000, 0x00004000, 0x00000002, 0.000000, 0.000000, 0),
-- Kill Command
(34026, 0x00, 9, 0x00000000, 0x10000000, 0x00000000, 0x0000000, 0x00000000, 0.000000, 0.000000, 0);

-- 2139_script_waypoint
DROP TABLE IF EXISTS script_waypoint;
CREATE TABLE script_waypoint (
  entry mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'creature_template entry',
  pointid mediumint(8) unsigned NOT NULL DEFAULT '0',
  location_x float NOT NULL DEFAULT '0',
  location_y float NOT NULL DEFAULT '0',
  location_z float NOT NULL DEFAULT '0',
  waittime int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'waittime in millisecs',
  point_comment text,
  PRIMARY KEY (entry, pointid)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Creature waypoints';
DELETE FROM `script_waypoint` WHERE `entry`=16295;
INSERT INTO `script_waypoint` VALUES
(16295, 0, 7545.070000, -7359.870000, 162.354000, 4000, 'SAY_START'),
(16295, 1, 7550.048340, -7362.237793, 162.235657, 0, ''),
(16295, 2, 7566.976074, -7364.315430, 161.738770, 0, ''),
(16295, 3, 7578.830566, -7361.677734, 161.738770, 0, ''),
(16295, 4, 7590.969238, -7359.053711, 162.257660, 0, ''),
(16295, 5, 7598.354004, -7362.815430, 162.256683, 4000, 'SAY_PROGRESS_1'),
(16295, 6, 7605.861328, -7380.424316, 161.937073, 0, ''),
(16295, 7, 7605.295410, -7387.382813, 157.253998, 0, ''),
(16295, 8, 7606.131836, -7393.893555, 156.941925, 0, ''),
(16295, 9, 7615.207520, -7400.187012, 157.142639, 0, ''),
(16295, 10, 7618.956543, -7402.652832, 158.202042, 0, ''),
(16295, 11, 7636.850586, -7401.756836, 162.144791, 0, 'SAY_PROGRESS_2'),
(16295, 12, 7637.058105, -7404.944824, 162.206970, 4000, ''),
(16295, 13, 7636.910645, -7412.585449, 162.366425, 0, ''),
(16295, 14, 7637.607910, -7425.591797, 162.630661, 0, ''),
(16295, 15, 7637.816895, -7459.057129, 163.302704, 0, ''),
(16295, 16, 7638.859863, -7470.902344, 162.517059, 0, ''),
(16295, 17, 7641.395996, -7488.217285, 157.381287, 0, ''),
(16295, 18, 7634.455566, -7505.451660, 154.682159, 0, 'SAY_PROGRESS_3'),
(16295, 19, 7631.906738, -7516.948730, 153.597382, 0, ''),
(16295, 20, 7622.231445, -7537.037598, 151.587112, 0, ''),
(16295, 21, 7610.921875, -7550.670410, 149.639374, 0, ''),
(16295, 22, 7598.229004, -7562.551758, 145.953888, 0, ''),
(16295, 23, 7588.509277, -7577.755371, 148.294479, 0, ''),
(16295, 24, 7567.339355, -7608.456055, 146.006485, 0, ''),
(16295, 25, 7562.547852, -7617.417969, 148.097504, 0, ''),
(16295, 26, 7561.508789, -7645.064453, 151.245163, 0, ''),
(16295, 27, 7563.337402, -7654.652344, 151.227158, 0, ''),
(16295, 28, 7565.533691, -7658.296387, 151.248886, 0, ''),
(16295, 39, 7571.155762, -7659.118652, 151.244568, 0, ''),
(16295, 30, 7579.119629, -7662.213867, 151.651505, 0, 'quest complete'),
(16295, 31, 7603.768066, -7667.000488, 153.997726, 0, ''),
(16295, 32, 7603.768066, -7667.000488, 153.997726, 4000, 'SAY_END_1'),
(16295, 33, 7603.768066, -7667.000488, 153.997726, 8000, 'SAY_END_2'),
(16295, 34, 7603.768066, -7667.000488, 153.997726, 0, '');

-- 2139_world
UPDATE `gameobject_template` SET `ScriptName`='go_cat_figurine' WHERE `entry`=13873;
UPDATE `creature_template` SET `ScriptName`='npc_garments_of_quests' WHERE `entry` IN (12429,12423,12427,12430,12428);

-- 2139_world_script
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000164 AND -1000174;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000164,'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.',0,0,0,2,'garments SAY_COMMON_HEALED'),
(-1000165,'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those gnolls with your power to back me!',0,0,1,1,'garments SAY_DG_KEL_THANKS'),
(-1000166,'Farewell to you, and may shadow always protect you!',0,0,1,3,'garments SAY_DG_KEL_GOODBYE'),
(-1000167, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those murlocs with the Light on my side!',0,0,7,1,'garments SAY_ROBERTS_THANKS'),
(-1000168, 'Farewell to you, and may the Light be with you always.',0,0,7,3,'garments SAY_ROBERTS_GOODBYE'),
(-1000169, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those humans with your power to back me!',0,0,1,1,'garments SAY_KORJA_THANKS'),
(-1000170, 'Farewell to you, and may our ancestors be with you always!',0,0,1,3,'garments SAY_KORJA_GOODBYE'),
(-1000171, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those wendigo with the Light on my side!',0,0,7,1,'garments SAY_DOLF_THANKS'),
(-1000172, 'Farewell to you, and may the Light be with you always.',0,0,7,3,'garments SAY_DOLF_GOODBYE'),
(-1000173, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those corrupt timberlings with Elune\'s power behind me!',0,0,2,1,'garments SAY_SHAYA_THANKS'),
(-1000174, 'Farewell to you, and may Elune be with you always.',0,0,2,3,'garments SAY_SHAYA_GOODBYE');

-- 2160_world
DELETE FROM `command` WHERE `name` LIKE "ahbotoption %";
DELETE FROM `command` WHERE `name` LIKE "ahbotoptions %";
DELETE FROM `command` WHERE `name` IN ('gobject addtemp','npc addtemp');

-- 2161_world
DELETE FROM `command` WHERE `name` LIKE "wp mod %";
DELETE FROM `command` WHERE `name` LIKE "wp event %";

-- 2227_mangos_7544_01_world_uptime
DROP TABLE IF EXISTS `uptime`;

-- 2254_world
DELETE FROM `command` WHERE `name` IN ('server difftime', 'addmove', 'Mod32Value', 'allowmove', 'reload tickets', 'npc tempadd', 'gobject tempadd', 'gobject addtemp', 'npc addtemp');
INSERT INTO `command` VALUES
('gobject tempadd','2','Adds a temporary gameobject that is not saved to DB.'),
('npc tempadd','2','Adds temporary NPC, not saved to database.');
UPDATE `command` SET `name`="ahbotoption" WHERE `name`="ahbotoptions";
DELETE FROM `command` WHERE `name` LIKE "path%";
DELETE FROM `command` WHERE `name` LIKE "wp%";
INSERT INTO `command` VALUES 
('wp load',2,'Syntax: .wp load $pathid\nLoad pathid number for selected creature. Creature must have no waypoint data.'),
('wp event',2,'Syntax: .wp event $subcommand\nType .path event to see the list of possible subcommands or .help path event $subcommand to see info on subcommands.'),
('wp unload',2,'Syntax: .wp unload\nUnload path for selected creature.'),
('wp show',2,'Syntax: .wp show $option\nOptions:\non $pathid (or selected creature with loaded path) - Show path\noff - Hide path\ninfo $slected_waypoint - Show info for selected waypoint.'),
('wp mod',2,'Syntax: .wp mod\nType .path mod to see the list of possible subcommands or .help path mod $subcommand to see info on subcommands.');

-- 2274_mangos_7558_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (1123,1124,1125,1126,1127);
INSERT INTO `trinity_string` VALUES
(1123,'Not pet found',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1124,'Wrong pet type',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1125,'Your pet learned all talents',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1126,'Your pet talents have been reset.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1127,'Talents of %s\'s pet reset.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2274_mangos_7558_02_world_command
DELETE FROM `command` WHERE `name` IN ('learn all_mypettalents');
INSERT INTO `command` VALUES
('learn all_mypettalents',3,'Syntax: .learn all_mypettalents\r\n\r\nLearn all talents for your pet available for his creature type (only for hunter pets).');

-- 2276_mangos_7560_01_world_gameobject_template
ALTER TABLE gameobject_template
  ADD COLUMN IconName varchar(100) NOT NULL default '' AFTER name;
  
-- 2280_mangos_7565_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (1010,1011,1012,1013,1014);
INSERT INTO `trinity_string` VALUES
(1010,'|    Account    |       Character      |       IP        | GM | Expansion |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1011,'|<Error>        | %20s |<Error>          |<Er>| <Error>   |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1012,'===========================================================================',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1013,'|%15s| %20s | %15s |%4d| %9d |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1014,'No online players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2284_mangos_7568_01_world_spell_proc_event
-- (53569) Infusion of Light (Rank 1)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53569);
INSERT INTO `spell_proc_event` VALUES (53569, 0x00, 10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- (53576) Infusion of Light (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (53576);
INSERT INTO `spell_proc_event` VALUES (53576, 0x00, 10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- (54149) Infusion of Light (Rank 2)
DELETE FROM `spell_proc_event` WHERE `entry` IN (54149);
INSERT INTO `spell_proc_event` VALUES (54149, 0x00, 10, 0x00200000, 0x00010000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- (55776) Swordguard Embroidery ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55776);
INSERT INTO `spell_proc_event` VALUES (55776, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);
-- (55768) Darkglow Embroidery ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55768);
INSERT INTO `spell_proc_event` VALUES (55768, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);
-- (55640) Lightweave Embroidery ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55640);
INSERT INTO `spell_proc_event` VALUES (55640, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);
-- (55380) Skyflare Swiftness ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (55380);
INSERT INTO `spell_proc_event` VALUES (55380, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 45);
-- (56355) Titanium Shield Spike ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (56355);
INSERT INTO `spell_proc_event` VALUES (56355, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0.000000, 0.000000, 0);
-- (61345) Natures Grace ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61345);
INSERT INTO `spell_proc_event` VALUES (61345, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- (61346) Natures Grace ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61346);
INSERT INTO `spell_proc_event` VALUES (61346, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- (61356) Invigorating Earthsiege Diamond Passive ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (61356);
INSERT INTO `spell_proc_event` VALUES (61356, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
-- (24905) Moonkin Form (Passive) (Passive)
DELETE FROM `spell_proc_event` WHERE `entry` IN (24905);
INSERT INTO `spell_proc_event` VALUES (24905, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 15.000000, 0.000000, 0);

-- 2296_world
ALTER TABLE creature_template
  ADD COLUMN `VehicleId` mediumint(8) unsigned NOT NULL default '0' AFTER `PetSpellDataId`;
  
-- 2339_world - 2346_world
DELETE FROM `command` WHERE `name` LIKE "ahbotoption %";
DELETE FROM `command` WHERE `name` LIKE "ahbotoptions %";

-- 2412_world
UPDATE `trinity_string` SET `content_default` = 'id: %d effmask: %d charges: %d stack: %d slot %d duration: %d maxduration: %d' WHERE `entry` =468;
UPDATE `trinity_string` SET `content_default` = 'id: %d eff: %d amount: %d' WHERE `trinity_string`.`entry` =470;

-- 2432_mangos_7615_01_world_command
DELETE FROM `command` WHERE `name` IN ('senditems','sendmail','sendmoney','sendmessage','send items','send mail','send money','send message');
INSERT INTO `command` VALUES
('send items',3,'Syntax: .send items #playername "#subject" "#text" itemid1[:count1] itemid2[:count2] ... itemidN[:countN]\r\n\r\nSend a mail to a player. Subject and mail text must be in "". If for itemid not provided related count values then expected 1, if count > max items in stack then items will be send in required amount stacks. All stacks amount in mail limited to 12.'),
('send mail',1,'Syntax: .send mail #playername "#subject" "#text"\r\n\r\nSend a mail to a player. Subject and mail text must be in "".'),
('send message',3,'Syntax: .send message $playername $message\r\n\r\nSend screen message to player from ADMINISTRATOR.'),
('send money','3','Syntax: .send money #playername "#subject" "#text" #money\r\n\r\nSend mail with money to a player. Subject and mail text must be in "".');

-- 2433_mangos_7616_01_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (1200,1201);
INSERT INTO `trinity_string` VALUES
(1200,'You try to view cinemitic %u but it doesn\'t exist.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1201,'You try to view movie %u but it doesn\'t exist.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2433_mangos_7616_02_world_command
DELETE FROM `command` WHERE `name` IN ('debug playsound','debug play sound','debug play cinematic','debug play movie');
INSERT INTO `command` VALUES
('debug play cinematic',1,'Syntax: .debug play cinematic #cinematicid\r\n\r\nPlay cinematic #cinematicid for you. You stay at place while your mind fly.\r\n'),
('debug play movie',1,'Syntax: .debug play movie #movieid\r\n\r\nPlay movie #movieid for you.'),
('debug play sound',1,'Syntax: .debug play sound #soundid\r\n\r\nPlay sound with #soundid.\r\nSound will be play only for you. Other players do not hear this.\r\nWarning: client may have more 5000 sounds...');

-- 2444_world
DELETE FROM `command` WHERE `name` IN ('reload spell_linked_spell');
INSERT INTO `command` VALUES
('reload spell_linked_spell','3','Usage: .reload spell_linked_spell\r\nReloads the spell_linked_spell DB table.');

-- 2450_world
UPDATE `gameobject_template` SET `ScriptName`='go_jump_a_tron' WHERE `entry`=183146;
UPDATE `gameobject_template` SET `ScriptName`='go_ethereum_prison' WHERE `entry`=184421;
UPDATE `gameobject_template` SET `scriptname`='go_sacred_fire_of_life' WHERE `entry`=175944;
UPDATE `gameobject_template` SET `scriptname`='go_skull_pile' WHERE `entry`=185913;
DELETE FROM `command` WHERE `name` IN ('reload spell_linked_spell');
INSERT INTO `command` VALUES
('reload spell_linked_spell','3','Usage: .reload spell_linked_spell\r\nReloads the spell_linked_spell DB table.');

-- 2479_world
DELETE FROM `trinity_string` WHERE `entry` = 5007;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES (5007, 'You must be in a raid group to enter this instance.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- 2492_mangos_7622_01_world_creature_ai_scripts
DROP TABLE IF EXISTS `creature_ai_scripts`;
CREATE TABLE `creature_ai_scripts` (
  `id` int(11) unsigned NOT NULL COMMENT 'Identifier' AUTO_INCREMENT,
  `creature_id` int(11) unsigned NOT NULL default '0' COMMENT 'Creature Template Identifier',
  `event_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Event Type',
  `event_inverse_phase_mask` int(11) signed NOT NULL default '0' COMMENT 'Mask which phases this event will not trigger in',
  `event_chance` int(3) unsigned NOT NULL default '100',
  `event_flags` int(3) unsigned NOT NULL default '0',
  `event_param1` int(11) signed NOT NULL default '0',
  `event_param2` int(11) signed NOT NULL default '0',
  `event_param3` int(11) signed NOT NULL default '0',
  `event_param4` int(11) signed NOT NULL default '0',
  `action1_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Action Type',
  `action1_param1` int(11) signed NOT NULL default '0',
  `action1_param2` int(11) signed NOT NULL default '0',
  `action1_param3` int(11) signed NOT NULL default '0',
  `action2_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Action Type',
  `action2_param1` int(11) signed NOT NULL default '0',
  `action2_param2` int(11) signed NOT NULL default '0',
  `action2_param3` int(11) signed NOT NULL default '0',
  `action3_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Action Type',
  `action3_param1` int(11) signed NOT NULL default '0',
  `action3_param2` int(11) signed NOT NULL default '0',
  `action3_param3` int(11) signed NOT NULL default '0',
  `comment` varchar(255) NOT NULL default '' COMMENT 'Event Comment',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='EventAI Scripts';

-- 2492_mangos_7622_02_world_creature_ai_summons
DROP TABLE IF EXISTS `creature_ai_summons`;
CREATE TABLE `creature_ai_summons` (
  `id` int(11) unsigned NOT NULL COMMENT 'Location Identifier' AUTO_INCREMENT,
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `spawntimesecs` int(11) unsigned NOT NULL default '120',
  `comment` varchar(255) NOT NULL default '' COMMENT 'Summon Comment',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='EventAI Summoning Locations';

-- 2492_mangos_7622_03_world_creature_ai_texts
DROP TABLE IF EXISTS `creature_ai_texts`;
CREATE TABLE `creature_ai_texts` (
  `entry` mediumint(8) NOT NULL,
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  `sound` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `language` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `emote` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `comment` text,
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Texts';

-- 2515_world_scripts
UPDATE `creature_template` SET `ScriptName`='mob_giant_infernal' WHERE `entry`=17908;
UPDATE `creature_template` SET `ScriptName`='mob_abomination' WHERE `entry`=17898;
UPDATE `creature_template` SET `ScriptName`='mob_ghoul' WHERE `entry`=17895;
UPDATE `creature_template` SET `ScriptName`='mob_necromancer' WHERE `entry`=17899;
UPDATE `creature_template` SET `ScriptName`='mob_banshee' WHERE `entry`=17905;
UPDATE `creature_template` SET `ScriptName`='mob_crypt_fiend' WHERE `entry`=17897;
UPDATE `creature_template` SET `ScriptName`='mob_fel_stalker' WHERE `entry`=17916;
UPDATE `creature_template` SET `ScriptName`='mob_frost_wyrm' WHERE `entry`=17907;
UPDATE `creature_template` SET `ScriptName`='mob_gargoyle' WHERE `entry`=17906;
UPDATE `creature_template` SET `ScriptName`='alliance_rifleman' WHERE `entry`=17921;
UPDATE `creature_template` SET `ScriptName`='mob_towering_infernal' WHERE `entry`=17818;
UPDATE `creature_template` SET `ScriptName`='boss_anetheron' WHERE `entry`=17808;
UPDATE `creature_template` SET `ScriptName`='boss_azgalor' WHERE `entry`=17842;
UPDATE `creature_template` SET `ScriptName`='mob_lesser_doomguard' WHERE `entry`=17864;
UPDATE `creature_template` SET `ScriptName`='boss_kazrogal' WHERE `entry`=17888;
UPDATE `creature_template` SET `ScriptName`='boss_rage_winterchill' WHERE `entry`=17767;
UPDATE `creature_template` SET `scale`='0.5' WHERE `entry`=17968;
UPDATE `creature_template` SET `equipment_id`='17888' WHERE `entry`=17888;
UPDATE `creature_template` SET `equipment_id`='17921' WHERE `entry`=17921;

-- 2521_world
-- Sudden Death
DELETE FROM `spell_proc_event` WHERE `entry` IN (29723, 29725, 29724);
INSERT INTO `spell_proc_event` VALUES (29723, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (29725, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (29724, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0.000000, 0.000000, 0);

-- 2522_mangos_7627_01_world_achievement_criteria_data
DROP TABLE IF EXISTS `achievement_criteria_data`;
CREATE TABLE `achievement_criteria_data` (
  `criteria_id` mediumint(8) NOT NULL,
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `value1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `value2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`criteria_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Achievment system';

-- 2528_mangos_7633_01_world_achievement_criteria_data
ALTER TABLE `achievement_criteria_data`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`criteria_id`,`type`);
  
-- 2551_world_spell_bonus_data
-- Judgement
DELETE FROM `spell_bonus_data` WHERE `entry` = 54158;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`comments`) VALUES
('54158','0.25','0','0.16','Paladin - Unleashing spell for Seal of Wisdom, Justice and Light');

-- 2559_world_spell_proc_event
-- Fingers of frost triggered spell
DELETE FROM `spell_proc_event` WHERE `entry` IN (44544);
INSERT INTO `spell_proc_event` VALUES (44544, 0x00, 0x00000003, 0x00000000, 0x00100000, 0x00000000, 0x00010000, 0x00000000, 0.000000, 0.000000, 0);
-- Sudden Death
DELETE FROM `spell_proc_event` WHERE `entry` IN (29723, 29725, 29724);
INSERT INTO `spell_proc_event` VALUES (29723, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (29725, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);
INSERT INTO `spell_proc_event` VALUES (29724, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0.000000, 0.000000, 0);

-- 2565_world_SD2_scripts
-- script waypoint
DELETE FROM script_waypoint WHERE entry=467;
INSERT INTO script_waypoint VALUES
(467, 0, -10508.40, 1068.00, 55.21, 0, ''),
(467, 1, -10518.30, 1074.84, 53.96, 0, ''),
(467, 2, -10534.82, 1081.92, 49.88, 0, ''),
(467, 3, -10546.51, 1084.88, 50.13, 0, ''),
(467, 4, -10555.29, 1084.45, 45.75, 0, ''),
(467, 5, -10566.57, 1083.53, 42.10, 0, ''),
(467, 6, -10575.83, 1082.34, 39.46, 0, ''),
(467, 7, -10585.67, 1081.08, 37.77, 0, ''),
(467, 8, -10600.08, 1078.19, 36.23, 0, ''),
(467, 9, -10608.69, 1076.08, 35.88, 0, ''),
(467, 10, -10621.26, 1073.00, 35.40, 0, ''),
(467, 11, -10638.12, 1060.18, 33.61, 0, ''),
(467, 12, -10655.87, 1038.99, 33.48, 0, ''),
(467, 13, -10664.68, 1030.54, 32.70, 0, ''),
(467, 14, -10708.68, 1033.86, 33.32, 0, ''),
(467, 15, -10754.43, 1017.93, 32.79, 0, ''),
(467, 16, -10802.26, 1018.01, 32.16, 0, ''),
(467, 17, -10832.60, 1009.04, 32.71, 0, ''),
(467, 18, -10866.56, 1006.51, 31.71, 0, ''),
(467, 19, -10879.98, 1005.10, 32.84, 0, ''),
(467, 20, -10892.45, 1001.32, 34.46, 0, ''),
(467, 21, -10906.14, 997.11, 36.15, 0, ''),
(467, 22, -10922.26, 1002.23, 35.74, 0, ''),
(467, 23, -10936.32, 1023.38, 36.52, 0, ''),
(467, 24, -10933.35, 1052.61, 35.85, 0, ''),
(467, 25, -10940.25, 1077.66, 36.49, 0, ''),
(467, 26, -10957.09, 1099.33, 36.83, 0, ''),
(467, 27, -10956.53, 1119.90, 36.73, 0, ''),
(467, 28, -10939.30, 1150.75, 37.42, 0, ''),
(467, 29, -10915.14, 1202.09, 36.55, 0, ''),
(467, 30, -10892.59, 1257.03, 33.37, 0, ''),
(467, 31, -10891.93, 1306.66, 35.45, 0, ''),
(467, 32, -10896.17, 1327.86, 37.77, 0, ''),
(467, 33, -10906.03, 1368.05, 40.91, 0, ''),
(467, 34, -10910.18, 1389.33, 42.62, 0, ''),
(467, 35, -10915.42, 1417.72, 42.93, 0, ''),
(467, 36, -10926.37, 1421.18, 43.04, 0, 'walk here and say'),
(467, 37, -10952.31, 1421.74, 43.40, 0, ''),
(467, 38, -10980.04, 1411.38, 42.79, 0, ''),
(467, 39, -11006.06, 1420.47, 43.26, 0, ''),
(467, 40, -11021.98, 1450.59, 43.09, 0, ''),
(467, 41, -11025.36, 1491.59, 43.15, 0, ''),
(467, 42, -11036.09, 1508.32, 43.28, 0, ''),
(467, 43, -11060.68, 1526.72, 43.19, 0, ''),
(467, 44, -11072.75, 1527.77, 43.20, 5000, 'say and quest credit');
DELETE FROM script_waypoint WHERE entry=2768;
INSERT INTO script_waypoint VALUES
(2768, 0, -2066.45, -2085.96, 9.08, 0, ''),
(2768, 1, -2077.99, -2105.33, 13.24, 0, ''),
(2768, 2, -2074.60, -2109.67, 14.24, 0, ''),
(2768, 3, -2076.60, -2117.46, 16.67, 0, ''),
(2768, 4, -2073.51, -2123.46, 18.42, 2000, ''),
(2768, 5, -2073.51, -2123.46, 18.42, 4000, ''),
(2768, 6, -2066.60, -2131.85, 21.56, 0, ''),
(2768, 7, -2053.85, -2143.19, 20.31, 0, ''),
(2768, 8, -2043.49, -2153.73, 20.20, 10000, ''),
(2768, 9, -2043.49, -2153.73, 20.20, 20000, ''),
(2768, 10, -2043.49, -2153.73, 20.20, 10000, ''),
(2768, 11, -2043.49, -2153.73, 20.20, 2000, ''),
(2768, 12, -2053.85, -2143.19, 20.31, 0, ''),
(2768, 13, -2066.60, -2131.85, 21.56, 0, ''),
(2768, 14, -2073.51, -2123.46, 18.42, 0, ''),
(2768, 15, -2076.60, -2117.46, 16.67, 0, ''),
(2768, 16, -2074.60, -2109.67, 14.24, 0, ''),
(2768, 17, -2077.99, -2105.33, 13.24, 0, ''),
(2768, 18, -2066.45, -2085.96, 9.08, 0, ''),
(2768, 19, -2066.41, -2086.21, 8.97, 6000, ''),
(2768, 20, -2066.41, -2086.21, 8.97, 2000, '');
DELETE FROM script_waypoint WHERE entry=12818;
INSERT INTO script_waypoint VALUES
(12818, 0, 3347.250089, -694.700989, 159.925995, 0, ''),
(12818, 1, 3341.527039, -694.725891, 161.124542, 4000, ''),
(12818, 2, 3338.351074, -686.088138, 163.444000, 0, ''),
(12818, 3, 3352.744873, -677.721741, 162.316269, 0, ''),
(12818, 4, 3370.291016, -669.366943, 160.751358, 0, ''),
(12818, 5, 3381.479492, -659.449097, 162.545303, 0, ''),
(12818, 6, 3389.554199, -648.500000, 163.651825, 0, ''),
(12818, 7, 3396.645020, -641.508911, 164.216019, 0, ''),
(12818, 8, 3410.498535, -634.299622, 165.773453, 0, ''),
(12818, 9, 3418.461426, -631.791992, 166.477615, 0, ''),
(12818, 10, 3429.500000, -631.588745, 166.921265, 0, ''),
(12818, 11,3434.950195, -629.245483, 168.333969, 0, ''),
(12818, 12,3438.927979, -618.503235, 171.503143, 0, ''),
(12818, 13,3444.217529, -609.293640, 173.077972, 1000, 'Ambush 1'),
(12818, 14,3460.505127, -593.794189, 174.342255, 0, ''),
(12818, 15,3480.283203, -578.210327, 176.652313, 0, ''),
(12818, 16,3492.912842, -562.335449, 181.396301, 0, ''),
(12818, 17,3495.230957, -550.977600, 184.652267, 0, ''),
(12818, 18,3496.247070, -529.194214, 188.172028, 0, ''),
(12818, 19,3497.619385, -510.411499, 188.345322, 1000, 'Ambush 2'),
(12818, 20,3498.498047, -497.787506, 185.806274, 0, ''),
(12818, 21,3484.218750, -489.717529, 182.389862, 4000, '');
DELETE FROM script_waypoint WHERE entry=12858;
INSERT INTO script_waypoint VALUES
(12858, 0, 1782.63, -2241.11, 109.73, 5000, ''),
(12858, 1, 1788.88, -2240.17, 111.71, 0, ''),
(12858, 2, 1797.49, -2238.11, 112.31, 0, ''),
(12858, 3, 1803.83, -2232.77, 111.22, 0, ''),
(12858, 4, 1806.65, -2217.83, 107.36, 0, ''),
(12858, 5, 1811.81, -2208.01, 107.45, 0, ''),
(12858, 6, 1820.85, -2190.82, 100.49, 0, ''),
(12858, 7, 1829.60, -2177.49, 96.44, 0, ''),
(12858, 8, 1837.98, -2164.19, 96.71, 0, 'prepare'),
(12858, 9, 1839.99, -2149.29, 96.78, 0, ''),
(12858, 10, 1835.14, -2134.98, 96.80, 0, ''),
(12858, 11, 1823.57, -2118.27, 97.43, 0, ''),
(12858, 12, 1814.99, -2110.35, 98.38, 0, ''),
(12858, 13, 1806.60, -2103.09, 99.19, 0, ''),
(12858, 14, 1798.27, -2095.77, 100.04, 0, ''),
(12858, 15, 1783.59, -2079.92, 100.81, 0, ''),
(12858, 16, 1776.79, -2069.48, 101.77, 0, ''),
(12858, 17, 1776.82, -2054.59, 109.82, 0, ''),
(12858, 18, 1776.88, -2047.56, 109.83, 0, ''),
(12858, 19, 1776.86, -2036.55, 109.83, 0, ''),
(12858, 20, 1776.90, -2024.56, 109.83, 0, 'win'),
(12858, 21, 1776.87, -2028.31, 109.83,60000, 'stay'),
(12858, 22, 1776.90, -2028.30, 109.83, 0, '');
DELETE FROM script_waypoint WHERE entry=15420;
INSERT INTO script_waypoint VALUES
(15420, 0, 9294.78, -6682.51, 22.42, 0, ''),
(15420, 1, 9298.27, -6667.99, 22.42, 0, ''),
(15420, 2, 9309.63, -6658.84, 22.43, 0, ''),
(15420, 3, 9304.43, -6649.31, 26.46, 0, ''),
(15420, 4, 9298.83, -6648.00, 28.61, 0, ''),
(15420, 5, 9291.06, -6653.46, 31.83,2500, ''),
(15420, 6, 9289.08, -6660.17, 31.85,5000, ''),
(15420, 7, 9291.06, -6653.46, 31.83, 0, '');
DELETE FROM script_waypoint WHERE entry=16993;
INSERT INTO script_waypoint VALUES
(16993, 0, -1137.72, 4272.10, 14.04, 5000, ''),
(16993, 1, -1141.34, 4232.42, 14.63, 0, ''),
(16993, 2, -1133.47, 4220.88, 11.78, 0, ''),
(16993, 3, -1126.18, 4213.26, 13.51, 0, ''),
(16993, 4, -1100.12, 4204.32, 16.41, 0, ''),
(16993, 5, -1063.68, 4197.92, 15.51, 0, ''),
(16993, 6, -1027.28, 4194.36, 15.52, 0, ''),
(16993, 7, -995.68, 4189.59, 19.84, 0, ''),
(16993, 8, -970.90, 4188.60, 24.61, 0, ''),
(16993, 9, -961.93, 4193.34, 26.11, 15000, 'Summon 1'),
(16993, 10, -935.52, 4210.99, 31.98, 0, ''),
(16993, 11, -913.42, 4218.27, 37.29, 0, ''),
(16993, 12, -896.53, 4207.73, 43.23, 0, ''),
(16993, 13, -868.49, 4194.77, 46.75, 30000, 'Kneel and Rest Here'),
(16993, 14, -852.83, 4198.29, 47.28, 15000, 'Summon 2'),
(16993, 15, -819.85, 4200.50, 46.37, 0, ''),
(16993, 16, -791.92, 4201.96, 44.19, 0, ''),
(16993, 17, -774.42, 4202.46, 47.41, 0, ''),
(16993, 18, -762.90, 4202.17, 48.81, 0, ''),
(16993, 19, -728.25, 4195.35, 50.68, 0, ''),
(16993, 20, -713.58, 4192.07, 53.98, 0, ''),
(16993, 21, -703.09, 4189.74, 56.96, 0, ''),
(16993, 22, -693.70, 4185.43, 57.06, 0, ''),
(16993, 23, -686.38, 4159.81, 60.26, 0, ''),
(16993, 24, -679.88, 4147.04, 64.20, 0, ''),
(16993, 25, -656.74, 4147.72, 64.11, 0, ''),
(16993, 26, -652.22, 4137.50, 64.58, 0, ''),
(16993, 27, -649.99, 4136.38, 64.63, 30000, 'Quest Credit');
DELETE FROM script_waypoint WHERE entry=17312;
INSERT INTO script_waypoint VALUES
(17312, 0, -4784.532227, -11051.060547, 3.484263, 0, ''),
(17312, 1, -4805.509277, -11037.293945, 3.043942, 0, ''),
(17312, 2, -4827.826172, -11034.398438, 1.741959, 0, ''),
(17312, 3, -4852.630859, -11033.695313, 2.208656, 0, ''),
(17312, 4, -4876.791992, -11034.517578, 3.175228, 0, ''),
(17312, 5, -4895.486816, -11038.306641, 9.390890, 0, ''),
(17312, 6, -4915.464844, -11048.402344, 12.369793, 0, ''),
(17312, 7, -4937.288086, -11067.041992, 13.857983, 0, ''),
(17312, 8, -4966.577637, -11067.507813, 15.754786, 0, ''),
(17312, 9, -4993.799805, -11056.544922, 19.175295, 0, ''),
(17312, 10, -5017.836426, -11052.569336, 22.476587, 0, ''),
(17312, 11, -5039.706543, -11058.459961, 25.831593, 0, ''),
(17312, 12, -5057.289063, -11045.474609, 26.972496, 0, ''),
(17312, 13, -5078.828125, -11037.601563, 29.053417, 0, ''),
(17312, 14, -5104.158691, -11039.195313, 29.440195, 0, ''),
(17312, 15, -5120.780273, -11039.518555, 30.142139, 0, ''),
(17312, 16, -5140.833008, -11039.810547, 28.788074, 0, ''),
(17312, 17, -5161.201660, -11040.050781, 27.879545, 4000, ''),
(17312, 18, -5171.842285, -11046.803711, 27.183821, 0, ''),
(17312, 19, -5185.995117, -11056.359375, 20.234867, 0, ''),
(17312, 20, -5198.485840, -11065.065430, 18.872593, 0, ''),
(17312, 21, -5214.062500, -11074.653320, 19.215731, 0, ''),
(17312, 22, -5220.157227, -11088.377930, 19.818476, 0, ''),
(17312, 23, -5233.652832, -11098.846680, 18.349432, 0, ''),
(17312, 24, -5250.163086, -11111.653320, 16.438959, 0, ''),
(17312, 25, -5268.194336, -11125.639648, 12.668313, 0, ''),
(17312, 26, -5286.270508, -11130.669922, 6.912246, 0, ''),
(17312, 27, -5317.449707, -11137.392578, 4.963446, 0, ''),
(17312, 28, -5334.854492, -11154.384766, 6.742664, 0, ''),
(17312, 29, -5353.874512, -11171.595703, 6.903912, 20000, ''),
(17312, 30, -5354.240000, -11171.940000, 6.890000, 0, '');
DELETE FROM script_waypoint WHERE entry=19685;
INSERT INTO script_waypoint VALUES
(19685, 0, -1863.369019, 5419.517090, -10.463668, 5000, ''),
(19685, 1, -1861.749023, 5416.465332, -10.508068, 0, ''),
(19685, 2, -1857.036133, 5410.966309, -12.428039, 0, ''),
(19685, 3, -1831.539185, 5365.472168, -12.428039, 0, ''),
(19685, 4, -1813.416504, 5333.776855, -12.428039, 0, ''),
(19685, 5, -1800.354370, 5313.290039, -12.428039, 0, ''),
(19685, 6, -1775.624878, 5268.786133, -38.809181, 0, ''),
(19685, 7, -1770.147339, 5259.268066, -38.829231, 0, ''),
(19685, 8, -1762.814209, 5261.098145, -38.848995, 0, ''),
(19685, 9, -1740.110474, 5268.858398, -40.208965, 0, ''),
(19685, 10, -1725.837402, 5270.936035, -40.208965, 0, ''),
(19685, 11, -1701.580322, 5290.323242, -40.209187, 0, ''),
(19685, 12, -1682.877808, 5291.406738, -34.429646, 0, ''),
(19685, 13, -1670.101685, 5291.201172, -32.786007, 0, ''),
(19685, 14, -1656.666870, 5294.333496, -37.862648, 0, ''),
(19685, 15, -1652.035767, 5295.413086, -40.245499, 0, ''),
(19685, 16, -1620.860596, 5300.133301, -40.208992, 0, ''),
(19685, 17, -1607.630981, 5293.983398, -38.577045, 5000, ''),
(19685, 18, -1607.630981, 5293.983398, -38.577045, 5000, ''),
(19685, 19, -1607.630981, 5293.983398, -38.577045, 5000, ''),
(19685, 20, -1622.140869, 5301.955566, -40.208897, 0, ''),
(19685, 21, -1621.131836, 5333.112793, -40.208897, 0, ''),
(19685, 22, -1637.598999, 5342.134277, -40.208790, 0, ''),
(19685, 23, -1648.521606, 5352.309570, -47.496170, 0, ''),
(19685, 24, -1654.606934, 5357.419434, -45.870892, 0, ''),
(19685, 25, -1633.670044, 5422.067871, -42.835541, 0, ''),
(19685, 26, -1656.567505, 5426.236328, -40.405815, 0, ''),
(19685, 27, -1664.932373, 5425.686523, -38.846405, 0, ''),
(19685, 28, -1681.406006, 5425.871094, -38.810928, 0, ''),
(19685, 29, -1730.875977, 5427.413574, -12.427910, 0, ''),
(19685, 30, -1743.509521, 5369.599121, -12.427910, 0, ''),
(19685, 31, -1877.217041, 5303.710449, -12.427989, 0, ''),
(19685, 32, -1890.371216, 5289.273438, -12.428268, 0, ''),
(19685, 33, -1905.505737, 5266.534668, 2.630672, 0, ''),
(19685, 34, -1909.381348, 5273.008301, 1.663714, 10000, ''),
(19685, 35, -1909.381348, 5273.008301, 1.663714, 12000, ''),
(19685, 36, -1909.381348, 5273.008301, 1.663714, 8000, ''),
(19685, 37, -1909.381348, 5273.008301, 1.663714, 15000, ''),
(19685, 38, -1927.561401, 5275.324707, 1.984987, 0, ''),
(19685, 39, -1927.385498, 5300.879883, -12.427236, 0, ''),
(19685, 40, -1921.063965, 5314.318359, -12.427236, 0, ''),
(19685, 41, -1965.425415, 5379.298828, -12.427236, 0, ''),
(19685, 42, -1981.233154, 5450.743652, -12.427236, 0, ''),
(19685, 43, -1958.022461, 5455.904297, 0.487659, 0, ''),
(19685, 44, -1951.991455, 5463.580566, 0.874490, 10000, ''),
(19685, 45, -1951.991455, 5463.580566, 0.874490, 12000, ''),
(19685, 46, -1968.730225, 5481.752930, -12.427846, 0, ''),
(19685, 47, -1881.839844, 5554.040039, -12.427846, 0, ''),
(19685, 48, -1841.566650, 5545.965332, -12.427846, 0, ''),
(19685, 49, -1837.658325, 5523.780273, 0.558756, 0, ''),
(19685, 50, -1831.321777, 5534.821777, 1.221819, 6000, ''),
(19685, 51, -1831.321777, 5534.821777, 1.221819, 8000, ''),
(19685, 52, -1831.321777, 5534.821777, 1.221819, 5000, ''),
(19685, 53, -1850.060669, 5472.610840, 0.857320, 6000, ''),
(19685, 54, -1850.060669, 5472.610840, 0.857320, 8000, ''),
(19685, 55, -1850.060669, 5472.610840, 0.857320, 9000, ''),
(19685, 56, -1850.060669, 5472.610840, 0.857320, 9000, ''),
(19685, 57, -1850.060669, 5472.610840, 0.857320, 4000, '');
DELETE FROM script_waypoint WHERE entry=20129;
INSERT INTO script_waypoint VALUES
(20129, 0, -8374.93,-4250.21, -204.38,5000, ''),
(20129, 1, -8374.93,-4250.21, -204.38,16000, ''),
(20129, 2, -8374.93,-4250.21, -204.38,10000, ''),
(20129, 3, -8374.93,-4250.21, -204.38,2000, ''),
(20129, 4, -8439.40,-4180.05, -209.25, 0, ''),
(20129, 5, -8437.82,-4120.84, -208.59,10000, ''),
(20129, 6, -8437.82,-4120.84, -208.59,16000, ''),
(20129, 7, -8437.82,-4120.84, -208.59,13000, ''),
(20129, 8, -8437.82,-4120.84, -208.59,18000, ''),
(20129, 9, -8437.82,-4120.84, -208.59,15000, ''),
(20129, 10, -8437.82,-4120.84, -208.59,2000, ''),
(20129, 11, -8467.26,-4198.63, -214.21, 0, ''),
(20129, 12, -8667.76,-4252.13, -209.56, 0, ''),
(20129, 13, -8703.71,-4234.58, -209.5,14000, ''),
(20129, 14, -8703.71,-4234.58, -209.5,2000, ''),
(20129, 15, -8642.81,-4304.37, -209.57, 0, ''),
(20129, 16, -8649.06,-4394.36, -208.46,6000, ''),
(20129, 17, -8649.06,-4394.36, -208.46,18000, ''),
(20129, 18, -8649.06,-4394.36, -208.46,2000, ''),
(20129, 19, -8468.72,-4437.67, -215.45, 0, ''),
(20129, 20, -8427.54,-4426, -211.13, 0, ''),
(20129, 21, -8364.83,-4393.32, -205.91, 0, ''),
(20129, 22, -8304.54,-4357.2, -208.2,18000, ''),
(20129, 23, -8304.54,-4357.2, -208.2,2000, ''),
(20129, 24, -8375.42,-4250.41, -205.14,5000, ''),
(20129, 25, -8375.42,-4250.41, -205.14,5000, '');
DELETE FROM script_waypoint WHERE entry=6575;
INSERT INTO script_waypoint VALUES
(6575, 0, 1945.81, -431.54, 16.36, 0, ''),
(6575, 1, 1946.21, -436.41, 16.36, 0, ''),
(6575, 2, 1950.01, -444.11, 14.63, 0, ''),
(6575, 3, 1956.08, -449.34, 13.12, 0, ''),
(6575, 4, 1966.59, -450.55, 11.27, 0, ''),
(6575, 5, 1976.09, -447.51, 11.27, 0, ''),
(6575, 6, 1983.42, -435.85, 11.27, 0, ''),
(6575, 7, 1978.17, -428.81, 11.27, 0, ''),
(6575, 8, 1973.97, -422.08, 9.04, 0, ''),
(6575, 9, 1963.84, -418.90, 6.17, 0, ''),
(6575, 10, 1961.22, -422.74, 6.17, 0, ''),
(6575, 11, 1964.80, -431.26, 6.17, 300000, '');
DELETE FROM script_waypoint WHERE entry=3849;
INSERT INTO script_waypoint VALUES
(3849, 0, -252.92, 2126.82, 81.17, 0, ''),
(3849, 1, -253.88, 2131.11, 81.21, 0, ''),
(3849, 2, -249.66, 2142.45, 87.01, 0, ''),
(3849, 3, -248.08, 2143.68, 87.01, 0, ''),
(3849, 4, -238.87, 2139.93, 87.01, 0, ''),
(3849, 5, -235.47, 2149.18, 90.59, 0, ''),
(3849, 6, -239.89, 2156.06, 90.62, 20000, 'SAY_FREE');
DELETE FROM script_waypoint WHERE entry=3850;
INSERT INTO script_waypoint VALUES
(3850, 0, -255.33, 2117.99, 81.17, 0, ''),
(3850, 1, -253.88, 2131.11, 81.21, 0, ''),
(3850, 2, -249.66, 2142.45, 87.01, 0, ''),
(3850, 3, -248.08, 2143.68, 87.01, 0, ''),
(3850, 4, -238.87, 2139.93, 87.01, 0, ''),
(3850, 5, -235.47, 2149.18, 90.59, 0, ''),
(3850, 6, -239.89, 2156.06, 90.62, 20000, 'SAY_FREE');
-- Henry Stern
UPDATE `creature_template` SET `ScriptName`='npc_henry_stern' WHERE `entry`=8696;
DELETE FROM `trinity_string` WHERE `entry` IN (59);
INSERT INTO `trinity_string` VALUES
(59,'Using creature EventAI: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2570_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (47988,47987,27272,17854,17853,17852,17851,17850,17767);
INSERT INTO `spell_linked_spell` VALUES (47988, 54501, 2, 'Consume Shadows - Rank 9');
INSERT INTO `spell_linked_spell` VALUES (47987, 54501, 2, 'Consume Shadows - Rank 8');
INSERT INTO `spell_linked_spell` VALUES (27272, 54501, 2, 'Consume Shadows - Rank 7');
INSERT INTO `spell_linked_spell` VALUES (17854, 54501, 2, 'Consume Shadows - Rank 6');
INSERT INTO `spell_linked_spell` VALUES (17853, 54501, 2, 'Consume Shadows - Rank 5');
INSERT INTO `spell_linked_spell` VALUES (17852, 54501, 2, 'Consume Shadows - Rank 4');
INSERT INTO `spell_linked_spell` VALUES (17851, 54501, 2, 'Consume Shadows - Rank 3');
INSERT INTO `spell_linked_spell` VALUES (17850, 54501, 2, 'Consume Shadows - Rank 2');
INSERT INTO `spell_linked_spell` VALUES (17767, 54501, 2, 'Consume Shadows - Rank 1');

-- 2586_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (53563);
INSERT INTO `spell_linked_spell` VALUES (53563, 53651, 2, 'Beacon of Light');
DELETE FROM `spell_proc_event` WHERE `entry` IN (53651);
INSERT INTO `spell_proc_event` VALUES
(53651, 0x00, 10, 0xC0008000, 0x00000000, 0x00000000, 0x00000000, 0x0000000, 0.000000, 0.000000, 0);

-- 2591_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (16857,17390,17391,17392,27011,48475);
INSERT INTO `spell_linked_spell` VALUES (16857, 60089, 0, 'Faerie Fire (Feral) Rank 1');
INSERT INTO `spell_linked_spell` VALUES (17390, 60089, 0, 'Faerie Fire (Feral) Rank 2');
INSERT INTO `spell_linked_spell` VALUES (17391, 60089, 0, 'Faerie Fire (Feral) Rank 3');
INSERT INTO `spell_linked_spell` VALUES (17392, 60089, 0, 'Faerie Fire (Feral) Rank 4');
INSERT INTO `spell_linked_spell` VALUES (27011, 60089, 0, 'Faerie Fire (Feral) Rank 5');
INSERT INTO `spell_linked_spell` VALUES (48475, 60089, 0, 'Faerie Fire (Feral) Rank 6');

-- 2617_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (781, 57635, 60932, 61507, 49576);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(781,    56446,  0, 'Disengage'),
(57635,  57636,  0, 'Disengage'),
(60932,  60934,  0, 'Disengage'),
(61507,  61508,  0, 'Disengage'),
(49576,  49560,  0, 'Death Grip');

-- 2629_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (47897,61290);
INSERT INTO `spell_linked_spell` VALUES (47897, 47960, 1, 'Shadowflame Rank 1');
INSERT INTO `spell_linked_spell` VALUES (61290, 61291, 1, 'Shadowflame Rank 2');

-- 2678_mangos_7662_01_world_spell_bonus_data
DELETE FROM `spell_bonus_data` WHERE entry IN (50288, 50294);
INSERT INTO `spell_bonus_data` VALUES
(50288, 0.05, 0, 0, "Druid - Starfall"),
(50294, 0.012, 0, 0, "Druid - Starfall AOE");

-- 2682_world_SD2_scripts
DELETE FROM script_waypoint WHERE entry=3849;
INSERT INTO script_waypoint VALUES
(3849, 0, -250.923431, 2116.264160, 81.179, 0, 'SAY_FREE_AD'),
(3849, 1, -255.048538, 2119.392578, 81.179, 0, ''),
(3849, 2, -254.129105, 2123.454346, 81.179, 0, ''),
(3849, 3, -253.897552, 2130.873535, 81.179, 0, ''),
(3849, 4, -249.889435, 2142.307861, 86.972, 0, ''),
(3849, 5, -248.204926, 2144.017090, 87.013, 0, ''),
(3849, 6, -240.552826, 2140.552734, 87.012, 0, ''),
(3849, 7, -237.513916, 2142.066650, 87.012, 0, ''),
(3849, 8, -235.638138, 2149.231689, 90.587, 0, ''),
(3849, 9, -237.188019, 2151.946045, 90.624, 0, ''),
(3849, 10, -241.162064, 2153.649658, 90.624, 0, 'SAY_OPEN_DOOR_AD'),
(3849, 11, -241.129700, 2154.562988, 90.624, 5000, ''),
(3849, 12, -241.129700, 2154.562988, 90.624, 5000, 'SAY_POST1_DOOR_AD'),
(3849, 13, -241.129700, 2154.562988, 90.624, 25000, 'SAY_POST2_DOOR_AD');

DELETE FROM script_waypoint WHERE entry=3850;
INSERT INTO script_waypoint VALUES
(3850, 0, -241.816895, 2122.904053, 81.179, 0, 'SAY_FREE_AS'),
(3850, 1, -247.139297, 2124.886475, 81.179, 0, ''),
(3850, 2, -253.179184, 2127.406738, 81.179, 0, ''),
(3850, 3, -253.897552, 2130.873535, 81.179, 0, ''),
(3850, 4, -249.889435, 2142.307861, 86.972, 0, ''),
(3850, 5, -248.204926, 2144.017090, 87.013, 0, ''),
(3850, 6, -240.552826, 2140.552734, 87.012, 0, ''),
(3850, 7, -237.513916, 2142.066650, 87.012, 0, ''),
(3850, 8, -235.638138, 2149.231689, 90.587, 0, ''),
(3850, 9, -237.188019, 2151.946045, 90.624, 0, ''),
(3850, 10, -241.162064, 2153.649658, 90.624, 0, 'SAY_OPEN_DOOR_AS'),
(3850, 11, -241.129700, 2154.562988, 90.624, 5000, 'cast'),
(3850, 12, -241.129700, 2154.562988, 90.624, 5000, 'SAY_POST_DOOR_AS'),
(3850, 13, -241.129700, 2154.562988, 90.624, 25000, '');

UPDATE script_texts SET content_default='Follow me and I\'ll open the courtyard door for you.', language=7, comment='prisoner ashcrombe SAY_FREE_AS' WHERE entry=-1033000;

DELETE FROM script_texts WHERE entry BETWEEN -1033008 AND -1033001;
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1033001,'I have just the spell to get this door open. Too bad the cell doors weren\'t locked so haphazardly.',0,0,7,1,'prisoner ashcrombe SAY_OPEN_DOOR_AS'),
(-1033002,'There it is! Wide open. Good luck to you conquering what lies beyond. I must report back to the Kirin Tor at once!',0,0,7,1,'prisoner ashcrombe SAY_POST_DOOR_AS'),
(-1033003,'Free from this wretched cell at last! Let me show you to the courtyard....',0,0,1,1,'prisoner adamant SAY_FREE_AD'),
(-1033004,'You are indeed courageous for wanting to brave the horrors that lie beyond this door.',0,0,1,1,'prisoner adamant SAY_OPEN_DOOR_AD'),
(-1033005,'There we go!',0,0,1,1,'prisoner adamant SAY_POST1_DOOR_AD'),
(-1033006,'Good luck with Arugal. I must hurry back to Hadrec now.',0,0,1,1,'prisoner adamant SAY_POST2_DOOR_AD'),
(-1033007,'About time someone killed the wretch.',0,0,1,1,'prisoner adamant SAY_BOSS_DIE_AD'),
(-1033008,'For once I agree with you... scum.',0,0,7,1,'prisoner ashcrombe SAY_BOSS_DIE_AS');

-- 2683_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry`=2025;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
('2025','|cff00ff00Created|r:|cff00ccff %s ago|r ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2685_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (56337, 56336, 56333);
INSERT INTO `spell_proc_event` VALUES
(56337, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00022200, 0x0000000, 0.000000, 0.000000, 0),
(56336, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00022200, 0x0000000, 0.000000, 0.000000, 0),
(56333, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00022200, 0x0000000, 0.000000, 0.000000, 0);

-- 2686_world_command
DELETE FROM `command` WHERE `name` IN ('go ticket');
INSERT INTO `command` VALUES 
('go ticket','1','Syntax: .go ticket #ticketid\r\nTeleports the user to the location where $ticketid was created.');

-- 2687_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (44545, 44543);
INSERT INTO `spell_proc_event` VALUES
(44545, 0x00, 3, 1049120, 4096, 0, 65536, 0x0000000, 0.000000, 15.000000, 0),
(44543, 0x00, 3, 1049120, 4096, 0, 65536, 0x0000000, 0.000000, 7.000000, 0);

-- 2689_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (51723);
INSERT INTO `spell_linked_spell` VALUES (51723, 52874, 0, 'Fan Of Knives');

-- 2702_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (56337, 56336, 56333);
INSERT INTO `spell_proc_event` VALUES
(56337, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00011100, 0x0000000, 0.000000, 0.000000, 0),
(56336, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00011100, 0x0000000, 0.000000, 0.000000, 0),
(56333, 0x00, 9, 0x00000004, 0x00000000, 0x00000200, 0x00011100, 0x0000000, 0.000000, 0.000000, 0);

-- 2706_world_SD2_scripts
UPDATE creature_template SET ScriptName='npc_kingdom_of_dalaran_quests' WHERE entry IN (29169,23729,26673,27158,29158,29161,26471,29155,29159,29160,29162);
DELETE FROM spell_target_position WHERE id=53360;
INSERT INTO spell_target_position VALUES
(53360, 571, 5807.829, 587.960, 660.939, 1.663);

-- 2715_TC1_1362_world_creature_linked_respawn
DROP TABLE IF EXISTS `creature_linked_respawn`;
CREATE TABLE `creature_linked_respawn` (
  `guid` int(10) unsigned NOT NULL COMMENT 'dependent creature',
  `linkedGuid` int(10) unsigned NOT NULL COMMENT 'master creature',
  PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature Respawn Link System';
DELETE FROM `trinity_string` WHERE `entry` = '750';
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
('750', 'linkGUID: %u, Entry: %u (%s)', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- 2724_TC1_world_1371_script
UPDATE `creature_template` SET `ScriptName` = 'mob_unkor_the_ruthless' WHERE `entry` = 18262;

-- 2774_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (56337, 56336, 56333, 58426, 31221, 31222, 31223);
INSERT INTO `spell_proc_event` VALUES
(56337, 0x00, 9, 0x00000004, 0x00000000, 0x00000040, 0x00022200, 0x0000000, 0.000000, 0.000000, 0),
(56336, 0x00, 9, 0x00000004, 0x00000000, 0x00000040, 0x00022200, 0x0000000, 0.000000, 0.000000, 0),
(56333, 0x00, 9, 0x00000004, 0x00000000, 0x00000040, 0x00022200, 0x0000000, 0.000000, 0.000000, 0),
-- Overkill
(58426, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0006001, 0.000000, 0.000000, 0),
-- Master of subtlety
(31221, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0006001, 0.000000, 0.000000, 0),
(31222, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0006001, 0.000000, 0.000000, 0),
(31223, 0x00, 8, 0x400000, 0x00000000, 0x00000000, 0x00014000, 0x0006001, 0.000000, 0.000000, 0);

-- 2792_world_spell_bonus_data
DELETE FROM `spell_bonus_data` WHERE entry IN (33778);
INSERT INTO `spell_bonus_data` VALUES
(33778, 0.6453, 0, 0, "Lifebloom- final effect");

-- 2792_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (16180, 16198, 16196);
INSERT INTO `spell_proc_event` VALUES
(16180, 0x00, 11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x0000002, 0.000000, 0.000000, 0),
(16198, 0x00, 11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x0000002, 0.000000, 0.000000, 0),
(16196, 0x00, 11, 0x000000C0, 0x00000000, 0x00000010, 0x00000000, 0x0000002, 0.000000, 0.000000, 0);

-- 2793_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (54754);
INSERT INTO `spell_proc_event` VALUES
(54754, 0x00, 7, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x0000000, 0.000000, 0.000000, 0);

-- 2794_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (54754);
INSERT INTO `spell_proc_event` VALUES
(54754, 0x00, 7, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x0000000, 0.000000, 0.000000, 0);

-- 2798_world_SD2_scripts
UPDATE gameobject_template SET ScriptName='go_tele_to_dalaran_crystal' WHERE entry=191230;
UPDATE gameobject_template SET ScriptName='go_tele_to_violet_stand' WHERE entry=191229;

-- 2802_world_SD2_scripts
DELETE FROM script_waypoint WHERE entry=17876;
INSERT INTO script_waypoint VALUES
(17876, 0, 2230.91, 118.765, 82.2947,5000, ''),
(17876, 1, 2230.33, 114.980, 82.2946, 0, ''),
(17876, 2, 2233.36, 111.057, 82.2996, 0, ''),
(17876, 3, 2231.17, 108.486, 82.6624, 0, ''),
(17876, 4, 2220.22, 114.605, 89.4264, 0, ''),
(17876, 5, 2215.23, 115.990, 89.4549, 0, ''),
(17876, 6, 2210.00, 106.849, 89.4549, 0, ''),
(17876, 7, 2205.66, 105.234, 89.4549, 0, ''),
(17876, 8, 2192.26, 112.618, 89.4549, 0, 'spawn armorer'),
(17876, 9, 2181.28, 118.612, 89.4549,8000, 'get weapon'),
(17876, 10, 2181.62, 120.385, 89.4549,5000, 'get armor'),
(17876, 11, 2189.44, 113.922, 89.4549, 0, ''),
(17876, 12, 2195.63, 110.584, 89.4549, 0, ''),
(17876, 13, 2201.09, 115.115, 89.4549, 0, ''),
(17876, 14, 2204.34, 121.036, 89.4355, 0, ''),
(17876, 15, 2208.66, 129.127, 87.9560, 0, 'first ambush'),
(17876, 16, 2193.09, 137.940, 88.2164, 0, ''),
(17876, 17, 2173.39, 149.064, 87.9227, 0, ''),
(17876, 18, 2164.25, 137.965, 85.0595, 0, ''),
(17876, 19, 2149.31, 125.645, 77.0858, 0, ''),
(17876, 20, 2142.78, 127.173, 75.5954, 0, ''),
(17876, 21, 2139.28, 133.952, 73.6386, 0, 'second ambush'),
(17876, 22, 2139.54, 155.235, 67.1269, 0, ''),
(17876, 23, 2145.38, 167.551, 64.8974, 0, ''),
(17876, 24, 2134.28, 175.304, 67.9446, 0, ''),
(17876, 25, 2118.08, 187.387, 68.8141, 0, ''),
(17876, 26, 2105.88, 195.461, 65.1854, 0, 'third ambush'),
(17876, 27, 2096.77, 196.939, 65.2117, 0, ''),
(17876, 28, 2083.90, 209.395, 64.8736, 0, ''),
(17876, 29, 2067.84, 224.376, 64.8022,30000, 'meeting scarloc'),
(17876, 30, 2055.40, 242.90, 63.3418, 0, 'after skarloc'),
(17876, 31, 2039.20, 266.460, 63.0182,10000, 'mount up'),
(17876, 32, 2011.77, 278.478, 65.3388, 0, ''),
(17876, 33, 2005.08, 289.676, 66.1179, 0, ''),
(17876, 34, 2033.11, 337.450, 66.0948, 0, ''),
(17876, 35, 2070.30, 416.208, 66.0893, 0, ''),
(17876, 36, 2086.76, 469.768, 65.9182, 0, ''),
(17876, 37, 2101.70, 497.955, 61.7881, 0, 'road ambush'),
(17876, 38, 2133.39, 530.933, 55.3700,5000, ''),
(17876, 39, 2157.91, 559.635, 48.5157, 0, ''),
(17876, 40, 2167.34, 586.191, 42.4394, 0, ''),
(17876, 41, 2174.17, 637.643, 33.9002, 0, ''),
(17876, 42, 2179.31, 656.053, 34.723, 0, ''),
(17876, 43, 2183.65, 670.941, 34.0318, 0, ''),
(17876, 44, 2201.50, 668.616, 36.1236, 0, ''),
(17876, 45, 2221.56, 652.747, 36.6153, 0, ''),
(17876, 46, 2238.97, 640.125, 37.2214, 0, ''),
(17876, 47, 2251.17, 620.574, 40.1473, 0, ''),
(17876, 48, 2261.98, 595.303, 41.4117, 0, ''),
(17876, 49, 2278.67, 560.172, 38.9090, 0, ''),
(17876, 50, 2336.72, 528.327, 40.9369, 0, ''),
(17876, 51, 2381.04, 519.612, 37.7312, 0, ''),
(17876, 52, 2412.20, 515.425, 39.2068, 0, ''),
(17876, 53, 2452.39, 516.174, 42.9387, 0, ''),
(17876, 54, 2467.38, 539.389, 47.4992, 0, ''),
(17876, 55, 2470.70, 554.333, 46.6668, 0, ''),
(17876, 56, 2478.07, 575.321, 55.4549, 0, ''),
(17876, 57, 2480.00, 585.408, 56.6921, 0, ''),
(17876, 58, 2482.67, 608.817, 55.6643, 0, ''),
(17876, 59, 2485.62, 626.061, 58.0132, 2000, 'dismount'),
(17876, 60, 2486.91, 626.356, 58.0761, 0, 'scare horse'),
(17876, 61, 2488.58, 660.940, 57.3913, 0, ''),
(17876, 62, 2502.56, 686.059, 55.6252, 0, ''),
(17876, 63, 2502.08, 694.360, 55.5083, 0, ''),
(17876, 64, 2491.46, 694.321, 55.7163, 0, ''),
(17876, 65, 2491.10, 703.300, 55.7630, 0, ''),
(17876, 66, 2485.64, 702.992, 55.7917, 0, ''),
(17876, 67, 2479.10, 695.291, 55.7901, 10000, ''),
(17876, 68, 2476.75, 693.689, 55.7960, 0, 'spawn mobs'),
(17876, 69, 2475.39, 695.983, 55.8146, 0, ''),
(17876, 70, 2477.75, 694.473, 55.7945, 0, ''),
(17876, 71, 2481.27, 697.747, 55.7910, 0, 'mobs in doorway'),
(17876, 72, 2486.31, 703.131, 55.7861, 5000, ''),
(17876, 73, 2490.76, 703.511, 55.7662, 0, ''),
(17876, 74, 2491.30, 694.792, 55.7195, 0, ''),
(17876, 75, 2518.69, 693.876, 55.1383, 0, ''),
(17876, 76, 2531.33, 681.914, 55.1383, 0, ''),
(17876, 77, 2568.25, 682.654, 55.1778, 0, ''),
(17876, 78, 2589.61, 689.981, 55.1421, 0, ''),
(17876, 79, 2634.74, 679.833, 54.6613, 0, ''),
(17876, 80, 2630.41, 661.464, 54.2761, 0, ''),
(17876, 81, 2629.00, 656.982, 56.0651, 0, ''),
(17876, 82, 2620.84, 633.007, 56.0300, 3000, 'stop in church'),
(17876, 83, 2622.99, 639.178, 56.0300, 0, 'summon'),
(17876, 84, 2628.73, 656.693, 56.0610, 5000, ''),
(17876, 85, 2630.34, 661.135, 54.2738, 0, ''),
(17876, 86, 2635.38, 672.243, 54.4508, 0, ''),
(17876, 87, 2644.13, 668.158, 55.3797, 0, ''),
(17876, 88, 2646.82, 666.740, 56.9898, 0, ''),
(17876, 89, 2658.22, 665.432, 57.1725, 0, ''),
(17876, 90, 2661.88, 674.849, 57.1725, 0, ''),
(17876, 91, 2656.23, 677.208, 57.1725, 0, ''),
(17876, 92, 2652.28, 670.270, 61.9353, 0, ''),
(17876, 93, 2650.79, 664.290, 61.9302, 0, 'summon inn'),
(17876, 94, 2658.19, 660.454, 61.9320, 5000, ''),
(17876, 95, 2660.57, 659.173, 61.9370, 0, 'speak with Taretha'),
(17876, 96, 2658.19, 660.454, 61.9320, 5000, 'epoch calls'),
(17876, 97, 2659.84, 659.482, 61.9361, 5000, 'taretha "dies"'),
(17876, 98, 2654.28, 662.722, 61.9313, 0, ''),
(17876, 99, 2652.37, 670.561, 61.9368, 0, ''),
(17876, 100, 2656.05, 676.761, 57.1727, 0, ''),
(17876, 101, 2658.49, 677.166, 57.1727, 0, ''),
(17876, 102, 2659.28, 667.117, 57.1727, 0, ''),
(17876, 103, 2649.71, 665.387, 57.1727, 0, ''),
(17876, 104, 2634.79, 672.964, 54.4577, 0, 'outside inn'),
(17876, 105, 2635.06, 673.892, 54.4713, 30000, 'getting ready'),
(17876, 106, 2634.79, 672.964, 54.4577, 60000, 'when all dead and meet Taretha'),
(17876, 107, 2631.72, 665.629, 54.2923, 0, 'run off'),
(17876, 108, 2647.40, 640.530, 55.7634, 0, '');
DELETE FROM script_waypoint WHERE entry=18887;
INSERT INTO script_waypoint VALUES
(18887, 0, 2650.06, 665.473, 61.9305, 0, ''),
(18887, 1, 2652.44, 670.761, 61.9370, 0, ''),
(18887, 2, 2655.96, 676.913, 57.1725, 0, ''),
(18887, 3, 2659.40, 677.317, 57.1725, 0, ''),
(18887, 4, 2651.75, 664.482, 57.1725, 0, ''),
(18887, 5, 2647.49, 666.595, 57.0824, 0, ''),
(18887, 6, 2644.37, 668.167, 55.4182, 0, ''),
(18887, 7, 2640.96, 669.890, 54.7567, 60000, '');
DELETE FROM script_waypoint WHERE entry=10096;
INSERT INTO script_waypoint VALUES
(10096, 0, 604.802673, -191.081985, -54.058590, 0,'ring'),
(10096, 1, 604.072998, -222.106918, -52.743759, 0,'first gate'),
(10096, 2, 621.400391, -214.499054, -52.814453, 0,'hiding in corner'),
(10096, 3, 601.300781, -198.556992, -53.950256, 0,'ring'),
(10096, 4, 631.818359, -180.548126, -52.654770, 0,'second gate'),
(10096, 5, 627.390381, -201.075974, -52.692917, 0,'hiding in corner');
DELETE FROM script_waypoint WHERE entry=9503;
INSERT INTO script_waypoint VALUES
(9503, 0, 883.294861, -188.926300, -43.703655, 0,''),
(9503, 1, 872.763550, -185.605621, -43.703655, 5000,'b1'),
(9503, 2, 867.923401, -188.006393, -43.703655, 5000,'b2'),
(9503, 3, 863.295898, -190.795212, -43.703655, 5000,'b3'),
(9503, 4, 856.139587, -194.652756, -43.703655, 5000,'b4'),
(9503, 5, 851.878906, -196.928131, -43.703655, 15000,'b5'),
(9503, 6, 877.035217, -187.048080, -43.703655, 0,''),
(9503, 7, 891.198000, -197.924000, -43.620400, 0,'home');

-- 2813_world_scripts
UPDATE `creature_template` SET `ScriptName` = 'boss_elder_nadox' WHERE `entry` = 29309;
UPDATE `creature_template` SET `ScriptName` = 'mob_ahnkahar_nerubian' WHERE `entry` in (30176,30178);
UPDATE `instance_template` SET `script`= 'instance_ahnkahet' WHERE `map` = 619;

-- 2813_world_SD2_scripts
DELETE FROM script_waypoint WHERE entry=12423;
INSERT INTO script_waypoint VALUES
(12423, 0, -9509.72, -147.03, 58.74, 0, ''),
(12423, 1, -9517.07, -172.82, 58.66, 0, '');
DELETE FROM script_waypoint WHERE entry=12427;
INSERT INTO script_waypoint VALUES
(12427, 0, -5689.20, -456.44, 391.08, 0, ''),
(12427, 1, -5700.37, -450.77, 393.19, 0, '');
DELETE FROM script_waypoint WHERE entry=12428;
INSERT INTO script_waypoint VALUES
(12428, 0, 2454.09, 361.26, 31.51, 0, ''),
(12428, 1, 2472.03, 378.08, 30.98, 0, '');
DELETE FROM script_waypoint WHERE entry=12429;
INSERT INTO script_waypoint VALUES
(12429, 0, 9654.19, 909.58, 1272.11, 0, ''),
(12429, 1, 9642.53, 908.11, 1269.10, 0, '');
DELETE FROM script_waypoint WHERE entry=12430;
INSERT INTO script_waypoint VALUES
(12430, 0, 161.65, -4779.34, 14.64, 0, ''),
(12430, 1, 140.71, -4813.56, 17.04, 0, '');
UPDATE script_texts SET emote=20 WHERE entry=-1000231;
UPDATE script_texts SET emote=4 WHERE entry IN (-1000232, -1000256, -1000258, -1000260, -1000262);

-- 2814_world_spell_linked_spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (32386, 32388, 32389, 32390, 32391);
INSERT INTO `spell_linked_spell` VALUES (32386, 60448, 2, 'Shadow Embrace Rank1');
INSERT INTO `spell_linked_spell` VALUES (32388, 60465, 2, 'Shadow Embrace Rank2');
INSERT INTO `spell_linked_spell` VALUES (32389, 60466, 2, 'Shadow Embrace Rank3');
INSERT INTO `spell_linked_spell` VALUES (32390, 60467, 2, 'Shadow Embrace Rank4');
INSERT INTO `spell_linked_spell` VALUES (32391, 60468, 2, 'Shadow Embrace Rank5');

-- 2828_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (16544, 16086);
INSERT INTO `spell_proc_event` VALUES
(16544, 0x00, 11, 0x00000000, 0x00040000, 0x00000000, 0x00000000, 0x0000000, 0.000000, 0.000000, 0),
(16086, 0x00, 11, 0x00000000, 0x00040000, 0x00000000, 0x00000000, 0x0000000, 0.000000, 0.000000, 0);

-- 2885_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (34457);
INSERT INTO `spell_proc_event` VALUES
(34457, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0);
DELETE FROM `spell_proc_event` WHERE `entry` IN (34456);
INSERT INTO `spell_proc_event` VALUES
(19615, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000002, 0.000000, 0.000000, 0);
INSERT INTO trinity_string (entry, content_default)VALUES (6616 , "Pet spells will reset for all players at login. Strongly recommend re-login!");

-- 2907_mangos_7705_01_world_command
DELETE FROM `command` WHERE `name` IN 
('account lock','account password','chardelete','character customize','character delete','character rename','customize','lockaccount','password','rename');
INSERT INTO `command` VALUES
('account lock',0,'Syntax: .account lock [on|off]\r\n\r\nAllow login from account only from current used IP or remove this requirement.'),
('account password',0,'Syntax: .account password $old_password $new_password $new_password\r\n\r\nChange your account password.'),
('character customize',2,'Syntax: .character customize [$name]\r\n\r\nMark selected in game or by $name in command character for customize at next login.'),
('character delete',4,'Syntax: .character delete $name\r\n\r\nDelete character $name.'),
('character rename',2,'Syntax: .character rename [$name]\r\n\r\nMark selected in game or by $name in command character for rename at next login.');

-- 2907_mangos_7706_01_world_command
DELETE FROM `command` WHERE `name` IN ('plimit','server plimit');
INSERT INTO `command` VALUES
('server plimit',3,'Syntax: .server plimit [#num|-1|-2|-3|reset|player|moderator|gamemaster|administrator]\r\n\r\nWithout arg show current player amount and security level limitations for login to server, with arg set player linit ($num > 0) or securiti limitation ($num < 0 or security leme name. With `reset` sets player limit to the one in the config file');

-- 2923_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (47569, 47570);
INSERT INTO `spell_proc_event` VALUES
(47569, 0x00, 6, 0x00004000, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 50.000000, 0),
(47570, 0x00, 6, 0x00004000, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0.000000, 100.000000, 0);

-- 2932_mangos_7714_01_world_command
DELETE FROM `command` WHERE `name` IN ('character level');
INSERT INTO `command` VALUES
('character level',3,'Syntax: .character level [$playername] [#level]\r\n\r\nSet the level of character with $playername (or the selected if not name provided) by #numberoflevels Or +1 if no #numberoflevels provided). If #numberoflevels is omitted, the level will be increase by 1. If #numberoflevels is 0, the same level will be restarted. If no character is selected and name not provided, increase your level. Command can be used for offline character. All stats and dependent values recalculated. At level decrease talents can be reset if need. Also at level decrease equipped items with greater level requirement can be lost.');

-- 2938_mangos_7720_01_world_trinity_string
DELETE FROM trinity_string WHERE entry IN(557,558,559);
INSERT INTO trinity_string VALUES
(557,'%s level up you to (%i)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(558,'%s level down you to (%i)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(559,'%s reset your level progress.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- 2949_world_creature_template
INSERT INTO creature_template (entry, spell1, spell2, spell3, spell4) VALUES
(15352, 36213, 0, 0, 0), # Greater Earth Elemental
(15438, 57984, 12470, 13376, 0), # Greater Fire Elemental
(29264, 58861, 58875, 58867, 58857), # Spirit Wolf
(510, 31707, 33395, 0, 0) # Water Elemental
ON DUPLICATE KEY UPDATE
spell1 = VALUES(spell1),
spell2 = VALUES(spell2),
spell3 = VALUES(spell3),
spell4 = VALUES(spell4);

-- 2955_world_scripts_naxx
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-28169, 28206,  0, 'Mutating Injection - Mutagen Explosion'),
(-28169, 28240,  0, 'Mutating Injection - Poison Cloud');
UPDATE creature_template SET spell1 = 28158, spell2 = 54362, flags_extra = 128 WHERE entry = 16363;
UPDATE creature_template SET scriptname = 'boss_grobbulus' WHERE entry = 15931;

-- 2963_world_spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry` IN (20911, 25899);
-- Blessing of sanctuary
INSERT INTO `spell_proc_event` VALUES
(20911, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070, 0.000000, 0.000000, 0),
(25899, 0x00, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000070, 0.000000, 0.000000, 0);
DELETE FROM `spell_required` WHERE `spell_id` IN (25899);
INSERT INTO spell_required VALUES (25899, 20911);

-- 2986_TC1_world
-- Kil'jaeden
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45909;
DELETE FROM `spell_script_target` WHERE `entry` IN (46589, 45839);
INSERT INTO `spell_script_target` () VALUES (46589, 1, 30598);
INSERT INTO `spell_script_target` () VALUES (46589, 1, 30614);
INSERT INTO `spell_script_target` () VALUES (45839, 1, 25653);

DELETE FROM `creature_template` WHERE entry in (30598, 30614);
INSERT INTO `creature_template` () VALUES 
(30598, 0, 4449, 0, 4449, 0, 'Spike Target', '', '', 70, 70, 1, 1, 0, 0, 0, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 2600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 0, 0, 1, 0, 0, 128, ''),
(30614, 0, 4449, 0, 4449, 0, 'Spike Target 2', '', '', 70, 70, 1, 1, 0, 0, 0, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 2600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 0, 0, 1, 0, 0, 128, '');

UPDATE `creature_template` SET `flags_extra` = 128  WHERE `entry` IN (30614, 30598, 25735);
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73, unit_flags = 33554432, minhealth=5000000, maxhealth=5000000 WHERE entry IN (26046, 25319);
UPDATE `creature_template` SET `minlevel` = 70, `unit_flags` = 33554432 WHERE entry = 26046;
UPDATE `creature_template` SET `minlevel` =70, `maxlevel` = 70, `unit_flags` = 33554432, spell1 = 45848, spell2 = 45862, spell3 = 45860, spell4 = 45856, minhealth = 5000000, maxhealth=5000000 WHERE entry=25653;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `minhealth` = 20000, maxhealth = 20000 WHERE entry = 25502;
UPDATE `creature_template` SET `minhealth` = 12600000, maxhealth = 12600000, minmana = 2000000, maxmana = 2000000 WHERE entry = 25315;
UPDATE `creature_template` SET `minhealth` = 110000, maxhealth = 110000, minmana = 100000, maxmana = 100000 WHERE entry =25708;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73 WHERE entry = 25735;

DELETE FROM creature WHERE id IN (25319, 25588, 25608);
INSERT INTO creature (id, map, spawnMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, DeathState, MovementType) VALUES
(25319, 580, 1, 0, 0, 1701.7, 635.515, 72.2884, 4.65461, 25, 0, 0, 1, 0, 0, 0),
(25608, 580, 1, 0, 0, 1698.9, 627.877, 27.6233, 0.034907, 604800, 0, 0, 1, 0, 0, 0);

DELETE FROM gameobject WHERE id=188415;
INSERT INTO gameobject (id, map, spawnMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES
(188415, 580, 1, 1653.12, 635.41, 28.0932, 0.0977725, 0, 0, 0.0488668, 0.998805, 25, 0, 1),
(188415, 580, 1, 1704.14, 583.591, 28.1696, 1.59003, 0, 0, 0.713874, 0.700274, 25, 0, 1),
(188415, 580, 1, 1745.68, 621.823, 28.0505, 2.93777, 0, 0, 0.994812, 0.101733, 25, 0, 1),
(188415, 580, 1, 1694.48, 674.29, 28.0502, 4.86985, 0, 0, 0.649302, -0.760531, 25, 0, 1);
UPDATE `gameobject_template` SET `type` = 1 WHERE `entry` = 188415;

-- M'uru
UPDATE `creature_template` SET `modelid_A` = 23842 WHERE `entry` = 25744;
UPDATE `creature_template` SET `flags_extra` = 128 WHERE entry IN (25855, 25770);
UPDATE `creature_template` SET `spell1` = 46262, flags_extra = 128, scriptname = '' WHERE entry = 25879;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (46242, 46228, 46228, 46262);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46242, 46247, 0, 'Black Hole Visual (Birth)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46228, 46235, 0, 'Black Hole Visual (Grown)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46228, -46247, 0, 'Black Hole Visual (Grown)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46262, 46265, 0, 'Void Zone Visual');

DELETE FROM `spell_script_target` WHERE `entry` IN (45976, 46177);
INSERT INTO `spell_script_target` VALUES (45976, 1, 25770);
INSERT INTO `spell_script_target` VALUES (46177, 1, 25770);

-- EAI for Berserks FROM Megamage
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 25798;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_flags`,`event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`, `event_chance`, `event_inverse_phase_mask`) VALUES
(2579800, 25798, 11, 0, 0*1000, 0*1000, 0*1000, 0*1000, 11, 45769, 0, 0, 20, 1, 0, 0, 21, 1, 0, 0,"Shadowsword Berserker - Sunwell Radiance", 100, 0),
(2579801, 25798, 0, 1, 10*1000, 12*1000, 10*1000, 15*1000, 11, 46160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowsword Berserker - Cast Flurry', 70, 0),
(2579802, 25798, 1, 0, 180*1000, 180*1000, 0*1000, 0*1000, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowsword Berserker - 180s OOC => Evade', 100, 0);

-- Brutallus
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 24882;

-- Felmyst
UPDATE `creature_template` SET `modelid_H` = 22838 WHERE `entry` = 25038;
DELETE FROM `script_texts` WHERE `entry` BETWEEN '-1580109' and '-1580036';
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `comment`) VALUES
(-1580036, 'Glory to Kil\'jaeden! Death to all who oppose!', 12477, 1, 'felmyst - YELL_BIRTH'),
(-1580037, 'I kill for the master!', 12480, 1, 'felmyst - YELL_KILL1'),
(-1580038, 'The end has come!', 12481, 1, 'felmyst - YELL_KILL2'),
(-1580039, 'Choke on your final breath!', 12478, 1, 'felmyst - YELL_BREATH'),
(-1580040, 'I am stronger than ever before!', 12479, 1, 'felmyst- YELL_TAKEOFF'),
(-1580041, 'No more hesitation! Your fates are written!', 12482, 1, 'felmyst - YELL_BERSERK'),
(-1580042, 'Kil\'jaeden... will... prevail...', 12483, 1, 'felmyst - YELL_DEATH'),
(-1580043, 'Madrigosa deserved a far better fate. You did what had to be done, but this battle is far from over.', 12439, 1, 'felmyst - YELL_KALECGOS'),
(-1580044, 'Fire to the aid of shadow!', 12489, 1, 'eredar - YELL_CANFLAGRATION'),
(-1580045, 'Sacrolash!', 12492, 1, 'eredar - YELL_SISTER_SACROLASH_DEAD'),
(-1580046, 'Fire consume.', 12490, 1, 'eredar - YELL_ALY_KILL_1'),
(-1580047, 'Ed-ir Halach!', 12491, 1, 'eredar - YELL_ALY_KILL_2'),
(-1580048, 'De-ek Anur!', 12494, 1, 'eredar - YELL_ALY_DEAD'),
(-1580049, 'Your luck has run its curse!', 12493, 1, 'eredar - YELL_BERSERK'),
(-1580050, 'Shadow to the aid of fire!', 12485, 1, 'eredar - YELL_SHADOW_NOVA'),
(-1580051, 'Alythess! Your fire burns within me!', 12488, 1, 'eredar - YELL_SISTER_ALYTHESS_DEAD'),
(-1580052, 'Shadow engulf.', 12486, 1, 'eredar - YELL_SAC_KILL_1'),
(-1580053, 'Ee-nok Kryul!', 12487, 1, 'eredar - YELL_SAC_KILL_2'),
(-1580054, 'I... fade.', 0, 1, 'eredar - YELL_SAC_DEAD'),
(-1580055, 'Time is a luxury you no longer possess!', 0, 1, 'eredar - YELL_ENRAGE'),
(-1580056, 'Misery...', 12484, 1, 'eredar - YELL_INTRO_SAC_1'),
(-1580057, 'Depravity...', 0, 1, 'eredar - YELL_INTRO_ALY_2'),
(-1580058, 'Confusion...', 0, 1, 'eredar - YELL_INTRO_SAC_3'),
(-1580059, 'Hatred...', 0, 1, 'eredar - YELL_INTRO_ALY_4'),
(-1580060, 'Mistrust...', 0, 1, 'eredar - YELL_INTRO_SAC_5'),
(-1580061, 'Chaos...', 0, 1, 'eredar - YELL_INTRO_ALY_6'),
(-1580062, 'These are the hallmarks...', 0, 1, 'eredar - YELL_INTRO_SAC_7'),
(-1580063, 'These are the pillars...', 0, 1, 'eredar - YELL_INTRO_ALY_8'),
(-1580064, 'directs Shadow Nova at $N', 0, 3, 'eredar - emote shadow nova'),
(-1580065, 'directs Conflagration at $N', 0, 3, 'eredar - emote conflagration'),
(-1580066, 'All my plans have led to this!', 12495, 1, 'KJ - SAY_KJ_OFFCOMBAT1'),
(-1580067, 'Stay on task! Do not waste tim!', 12496, 1, 'KJ - SAY_KJ_OFFCOMBAT2'),
(-1580068, 'I have waited long enough!', 12497, 1, 'KJ - SAY_KJ_OFFCOMBAT3'),
(-1580069, 'Fail me and suffer for eternity!', 12498, 1, 'KJ - SAY_KJ_OFFCOMBAT4'),
(-1580070, 'Drain the girl! Drain her power until there is nothing but a vacant shell!', 12499, 1, 'KJ - SAY_KJ_OFFCOMBAT5'),
(-1580071, 'The expendible have perished... So be it! Now I shall succeed where Sargeras could not! I will bleed this wretched world and secure my place as the true master of the Burning Legion. The end has come! Let the unraveling of this world commence!', 12500, 1, 'KJ - SAY_KJ_EMERGE'),
(-1580072, 'Another step towards destruction!', 12501, 1, 'KJ - SAY_KJ_SLAY1'),
(-1580073, 'Anak-ky\'ri!', 12502, 1, 'KJ - SAY_KJ_SLAY2'),
(-1580074, 'Who can you trust?', 12503, 1, 'KJ - SAY_KJ_REFLECTION1'),
(-1580075, 'The enemy is among you.', 12504, 1, 'KJ - SAY_KJ_REFLECTION2'),
(-1580076, 'Chaos!', 12505, 1, 'KJ - SAY_KJ_DARKNESS1'),
(-1580077, 'Destruction!', 12506, 1, 'KJ - SAY_KJ_DARKNESS2'),
(-1580078, 'Oblivion!', 12507, 1, 'KJ - SAY_KJ_DARKNESS3'),
(-1580079, 'I will not be denied! This world shall fall!', 12508, 1, 'KJ - SAY_KJ_PHASE3'),
(-1580080, 'Do not harbor false hope. You cannot win!', 12509, 1, 'KJ - SAY_KJ_PHASE4'),
(-1580081, 'Aggghh! The powers of the Sunwell... turned... against me! What have you done? WHAT HAVE YOU DONE?', 12510, 1, 'KJ - SAY_KJ_PHASE5'),
(-1580082, 'Anveena, you must awaken, this world needs you!', 12445, 1, 'KJ - SAY_KALECGOS_AWAKEN'),
(-1580083, 'I serve only the Master now.', 12511, 1, 'KJ - SAY_ANVEENA_IMPRISONED'),
(-1580084, 'You must let go! You must become what you were always meant to be! The time is now, Anveena!', 12446, 1, 'KJ - SAY_KALECGOS_LETGO'),
(-1580085, 'But I\'m... lost... I cannot find my way back!', 12512, 1, 'KJ - SAY_ANVEENA_LOST'),
(-1580086, 'Anveena, I love you! Focus on my voice, come back for me now! Only you can cleanse the Sunwell!', 12447, 1, 'KJ - SAY_KALECGOS_FOCUS'),
(-1580087, 'Kalec... Kalec?', 12513, 1, 'KJ - SAY_ANVEENA_KALEC'),
(-1580088, 'Yes, Anveena! Let fate embrace you now!', 12448, 1, 'KJ - SAY_KALECGOS_FATE'),
(-1580089, 'The nightmare is over, the spell is broken! Goodbye, Kalec, my love!', 12514, 1, 'KJ - SAY_ANVEENA_GOODBYE'),
(-1580090, 'Goodbye, Anveena, my love. Few will remember your name, yet this day you change the course of destiny. What was once corrupt is now pure. Heroes, do not let her sacrifice be in vain.', 12450, 1, 'KJ - SAY_KALECGOS_GOODBYE'),
(-1580091, 'Strike now, heroes, while he is weakened! Vanquish the Deceiver!', 12449, 1, 'KJ - SAY_KALECGOS_ENCOURAGE'),
(-1580092, 'You are not alone. The Blue Dragonflight shall help you vanquish the Deceiver.', 12438, 1, 'KJ - SAY_KALECGOS_JOIN'),
(-1580093, 'Nooooooooooooo!', 12527, 1, 'KJ - SAY_KJ_DEATH'),
(-1580094, 'begins to channel dark energy', 0, 3, 'KJ - EMOTE_KJ_DARKNESS'),
(-1580095, 'I will channel my power into the orbs, be ready!', 12440, 1, 'KJ - SAY_KALEC_ORB_READY1'),
(-1580096, 'I have empowered another orb! Use it quickly!', 12441, 1, 'KJ - SAY_KALEC_ORB_READY2'),
(-1580097, 'Another orb is ready! Make haste!', 12442, 1, 'KJ - SAY_KALEC_ORB_READY3'),
(-1580098, 'I have channeled all I can! The power is in your hands!', 12443, 1, 'KJ - SAY_KALEC_ORB_READY4'),
(-1580099, 'Mortal heroes, your victory here today was foretold long ago. My brother\'s anguished cry of defeat will echo across the universe, bringing renewed hope to all those who still stand against the Burning Crusade.', 12515, 0, 'prophet velen - SAY1'),
(-1580100, 'As the Legion\'s final defeat draws ever-nearer, stand proud in the knowledge that you have saved worlds without number from the flame. Just as this day marks an ending, so too does it herald a new beginning...', 12516, 0, 'prophet velen - SAY2'), -- van mégegy hang 12517 ami ehhez tartozik
(-1580101, 'The creature Entropius, whom you were forced to destroy, was once the noble naaru, M\'uru. In life, M\'uru channeled vast energies of LIGHT and HOPE. For a time, a misguided few sought to steal those energies...', 12518, 0, 'prophet velen - SAY3'),
(-1580102, 'Then fortunate it is, that I have reclaimed the noble naaru\'s spark from where it fell! Where faith dwells, hope is never lost, young blood elf.', 12519, 0, 'prophet velen - SAY4'),
(-1580103, 'Gaze now, mortals - upon the HEART OF M\'URU! Unblemished. Bathed by the light of Creation - just as it was at the Dawn.', 12520, 0, 'prophet velen - SAY5'),
(-1580104, 'In time, the light and hope held within - will rebirth more than this mere fount of power... Mayhap, they will rebirth the soul of a nation.', 12521, 0, 'prophet velen - SAY6'),
(-1580105, 'Salvation, young one. It waits for us all.', 12522, 0, 'prophet velen - SAY7'),
(-1580106, 'Farewell...', 12523, 0, 'prophet velen - SAY8'),
(-1580107, 'Our arrogance was unpardonable. We damned one of the most noble beings of all. We may never atone for this sin.', 12524, 0, 'lady liadrinn - SAY1'),
(-1580108, 'Can it be?', 12525, 0, 'lady liadrinn - SAY2'),
(-1580109, 'Blessed ancestors! I feel it... so much love... so much grace... there are... no words... impossible to describe...', 12525, 0, 'lady liadrinn - SAY3');

-- Kil'jaeden script
UPDATE `creature_template` SET `ScriptName`='boss_kiljaeden' WHERE `entry`=25315;
UPDATE `creature_template` SET `ScriptName`='boss_kalecgosKJ' WHERE `entry`=25319;
UPDATE `creature_template` SET `ScriptName`='mob_kiljaeden_controller' WHERE `entry`=25608;
UPDATE `creature_template` SET `ScriptName`='mob_hand_of_the_deceiver' WHERE `entry`=25588;
UPDATE `creature_template` SET `ScriptName`='mob_felfire_portal' WHERE `entry`=25603;
UPDATE `creature_template` SET `ScriptName`='mob_volatile_felfire_fiend' WHERE `entry`=25598;
UPDATE `creature_template` SET `ScriptName`='mob_armageddon' WHERE `entry`=25735;
UPDATE `creature_template` SET `ScriptName`='mob_shield_orb' WHERE `entry`=25502;
UPDATE `creature_template` SET `ScriptName`='mob_sinster_reflection' WHERE `entry`=25708;
UPDATE `gameobject_template` SET `ScriptName`='go_orb_of_the_blue_flight' WHERE `entry`=188415;

-- M'uru& Entropius
UPDATE `creature_template` SET `ScriptName`='npc_void_sentinel' WHERE `entry`=25772;
UPDATE `creature_template` SET `ScriptName`='npc_dark_fiend' WHERE `entry`=25744;
UPDATE `creature_template` SET `ScriptName`='boss_muru' WHERE `entry`=25741;
UPDATE `creature_template` SET `ScriptName`='boss_entropius' WHERE `entry`=25840;
UPDATE `creature_template` SET `ScriptName`='npc_muru_portal' WHERE `entry`=25770;
UPDATE `creature_template` SET `AIName`='EventAI' WHERE `entry`=25798;

-- 2996_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` IN (750,751);
INSERT INTO `trinity_string` VALUES
(750,'Not enough players. This game will close in %u mins.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(751,'Not enough players. This game will close in %u seconds.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1200 AND 1232;
INSERT INTO `trinity_string` VALUES
(1200, 'You try to view cinemitic %u but it doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1201, 'You try to view movie %u but it doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1300 AND 1332;
INSERT INTO `trinity_string` VALUES
(1300, 'Alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1301, 'Horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1302, '%s was destroyed by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1303, 'The %s is under attack! If left unchecked, the %s will destroy it!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1304, 'The %s was taken by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1305, 'The %s was taken by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1306, 'The %s was taken by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1307, 'The %s is under attack! If left unchecked, the %s will capture it!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1308, 'The %s has taken the %s! Its supplies will now be used for reinforcements!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1309, 'Irondeep Mine', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1310, 'Coldtooth Mine', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1311, 'Stormpike Aid Station', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1312, 'Dun Baldar South Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1313, 'Dun Baldar North Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1314, 'Stormpike Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1315, 'Icewing Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1316, 'Stonehearth Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1317, 'Stonehearth Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1318, 'Snowfall Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1319, 'Iceblood Tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1320, 'Iceblood Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1321, 'Tower Point', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1322, 'Frostwolf Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1323, 'East Frostwolf Tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1324, 'West Frostwolf Tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1325, 'Frostwolf Relief Hut', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1326, 'The Battle for Alterac Valley begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1327, 'The Battle for Alterac Valley begins in 30 seconds. Prepare yourselves!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1328, 'The Battle for Alterac Valley has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1329, 'The Alliance Team is running out of reinforcements!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1330, 'The Horde Team is running out of reinforcements!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1331, 'The Frostwolf General is Dead!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1332, 'The Stormpike General is Dead!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- 2997_world_trinity_string
DELETE FROM `trinity_string` WHERE `entry` = 5010;
INSERT INTO `trinity_string` VALUES
(5010,'linkGUID: %u, Entry: %u (%s)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);