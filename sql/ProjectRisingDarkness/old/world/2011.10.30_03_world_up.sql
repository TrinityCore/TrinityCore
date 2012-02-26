-- Scourge Hulk, necessary for The Incredible Hulk achievement
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_scourge_hulk' WHERE `entry` = 26555;

-- Ritual Target
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35, `unit_flags` = '33554944', `flags_extra` = '130' WHERE `entry` IN (27327, 30805);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (5140, 'at_observance_chamber');

-- Ritual Sword NPC
DELETE FROM `creature_template` WHERE (`entry`=27325);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (27325, 0, 0, 0, 0, 0, 11686, 0, 0, 0, 'Svala Sorrowgrave', 'Sword', '', 0, 80, 80, 2, 21, 21, 0, 0.4, 0.4, 1, 1, 422, 586, 0, 642, 7.5, 2400, 0, 1, 33554434, 8, 0, 0, 0, 0, 0, 345, 509, 103, 10, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 5, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 122, 1, 1886, 0, 0, 'npc_sword_ritual', 12340);

-- Ritual teleports
DELETE FROM `spell_target_position` WHERE `id` IN (48267,48276);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) values('48267','575','296.632','-346.075','90.547','4.60767');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) values('48276','575','296.632','-346.075','113.547','4.60767');

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 26668;

UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16, `flags_extra` = 130 WHERE `entry` IN (30771,27273);

-- Texts
DELETE FROM `script_texts` WHERE npc_entry IN (24266, 29281, 26668);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc6`, `content_loc7`, `sound`, `type`, `comment`) VALUES
('24266','-1575038','Your sacrifice is a testament to your obedience. Indeed you are worthy of this charge. Arise, and forever be known as Svala Sorrowgrave!','Tu sacrificio corrobora tu obediencia. No cabe duda de que vales para este cargo. Levantate, y que todos te conozcan como Svala Tumbapena.','Tu sacrificio corrobora tu obediencia. No cabe duda de que vales para este cargo. Levantate, y que todos te conozcan como Svala Tumbapena.','14732','1',NULL),
('24266','-1575039','Your first test awaits you. Destroy our uninvited guests.','Tu primera prueba te espera. Acaba con nuestros invitados indeseados.','Tu primera prueba te espera. Acaba con nuestros invitados indeseados.','14733','1',NULL),
('26668','-1575027','Any last words?','żTus últimas palabras?','żTus últimas palabras?','13854','1','svala SAY_SACRIFICE_5'),
('26668','-1575026','Yor-guul mak!','ˇYor-guul mak!','ˇYor-guul mak!','13853','1','svala SAY_SACRIFICE_4'),
('26668','-1575025','Your end is inevitable.','Tu fin es inevitable.','Tu fin es inevitable.','13852','1','svala SAY_SACRIFICE_3'),
('26668','-1575024','Go now to my master.','Ve ya junto a mi maestro.','Ve ya junto a mi maestro.','13851','1','svala SAY_SACRIFICE_2'),
('26668','-1575023','Your death approaches.','Vuestra muerte se aproxima.','Vuestra muerte se aproxima.','13850','1','svala SAY_SACRIFICE_1'),
('26668','-1575022','Nooo! I did not come this far... to...','ˇNooo! No he llegado tan lejos... para...','ˇNooo! No he llegado tan lejos... para...','13855','1','Svala Sorrowgrave SAY_DEATH'),
('26668','-1575021','Another soul for my master.','Otra alma para mi maestro.','Otra alma para mi maestro.','13848','1','Svala Sorrowgrave SAY_SLAY_3'),
('26668','-1575020','Your will is done, my king.','Se ha cumplido vuestra voluntad, mi rey.','Se ha cumplido vuestra voluntad, mi rey.','13847','1','Svala Sorrowgrave SAY_SLAY_2'),
('26668','-1575019','You were a fool to challenge the power of the Lich King!','ˇQue estupidez desafiar el poder del Rey Exánime!','ˇQue estupidez desafiar el poder del Rey Exánime!','13845','1','Svala Sorrowgrave SAY_SLAY_1'),
('26668','-1575018','I will vanquish your soul!','ˇSometeré vuestra alma!','ˇSometeré vuestra alma!','13842','1','Svala Sorrowgrave SAY_AGGRO'),
('29281','-1575017','I will be happy to slaughter them in your name! Come, enemies of the Scourge! I will show you the might of the Lich King!','ˇSerá un placer matarlos en vuestro nombre! ˇAcercaos, enemigos de la Plaga! ˇOs enseńaré el poder del Rey Exánime!','ˇSerá un placer matarlos en vuestro nombre! ˇAcercaos, enemigos de la Plaga! ˇOs enseńaré el poder del Rey Exánime!','13858','1','Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_3'),
('29281','-1575016','The sensation is... beyond my imagining. I am yours to command, my king.','La sensación... Va más allá de mi imaginación. Estoy vuestra disposición, mi rey.','La sensación... Va más allá de mi imaginación. Estoy vuestra disposición, mi rey.','13857','1','Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_2'),
('29281','-1575015','My liege! I have done as you asked, and now beseech you for your blessing!','ˇMi seńor! ˇHe hecho lo que pediste, y ahora suplico vuestra bendición!','ˇMi seńor! ˇHe hecho lo que pediste, y ahora suplico vuestra bendición!','13856','1','Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_1');

-- >> SKADI THE RUTHLESS

UPDATE script_texts SET content_default = 'Skadi the Ruthless is within range of the harpoon launchers!', content_loc6 = 'ˇSkadi el Despiadado esta a tiro para los arpones!', content_loc7 = content_loc6 WHERE entry = -1575007;

-- >> KING YMIRON
UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16 WHERE `entry` IN (27386, 30756);

-- Harpoons
UPDATE `gameobject_template` SET `ScriptName` = 'go_skadi_harpoon' WHERE `entry` = 192539;