-- == Logros ==
DELETE FROM `achievement_criteria_data` WHERE criteria_id IN (7323, 7324, 7325, 7177, 7178, 7179);
INSERT INTO `achievement_criteria_data` VALUES
-- Drake Voids
(7323, 11, 0, 0, 'achievement_ruby_void'),
(7324, 11, 0, 0, 'achievement_emerald_void'),
(7325, 11, 0, 0, 'achievement_amber_void'),
-- Drake Rider
(7177, 11, 0, 0, 'achievement_amber_drake_rider'),
(7178, 11, 0, 0, 'achievement_emerald_drake_rider'),
(7179, 11, 0, 0, 'achievement_ruby_drake_rider');

-- Delete disables
DELETE FROM `disables` WHERE sourcetype = 4 AND entry IN(7323, 7324, 7325, 7177, 7178, 7179);

-- == Creature ==

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1 WHERE `entry` IN (27755, 27756, 27692);
-- El aura del draco rubi no tiene que ser un spell
UPDATE `creature_template` SET `spell2` = 50240, `spell3` = 50253, `spell4` = 0 WHERE `entry` = 27756;
-- Los spells para montar deben ser instantaneos
UPDATE `npc_spellclick_spells` SET `spell_id` = 49460 WHERE `npc_entry` = 27755;
UPDATE `npc_spellclick_spells` SET `spell_id` = 49464 WHERE `npc_entry` = 27756;
UPDATE `npc_spellclick_spells` SET `spell_id` = 49346 WHERE `npc_entry` = 27692;


UPDATE `creature_template` SET `ScriptName` = 'npc_centrifuge_construct' WHERE `entry` = 27641;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_ringlord_conjurer' WHERE `entry` = 27640;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_ringlord_sorceress' WHERE `entry` = 27639;


UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_greater_ley_whelp' WHERE `entry` = 28276;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_azure_ring_guardian' WHERE `entry` = 27638;

-- VAROS --
-- Spell visual
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 13 AND SourceEntry = 51024;
INSERT INTO conditions (SourceTypeOrReferenceId, Sourcegroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1) VALUES (13, 51024, 18, 1, 28239);
UPDATE `creature_template` SET `modelid2` = 11686, `faction_A` = 35, `faction_H` = 35 WHERE `entry` IN (28239, 31628);

-- DRAKOS

-- Texts
DELETE FROM script_texts WHERE npc_entry = 27654;
insert into `script_texts` (`entry`, `npc_entry`, `content_default`, `sound`, `type`, `content_loc6`, `content_loc7`) values
('-1578017','27654','Can you fly?','13597','1','¿Podeis volar?','¿Podeis volar?'),
('-1578016','27654','I will crush you!','13596','1','¡Os aplastaré!','¡Os aplastaré!'),
('-1578015','27654','Tremble, worms!','13595','1','¡Temblad, gusanos!','¡Temblad, gusanos!'),
('-1578014','27654','I condemn you to death!','13601','1','¡Os condeno a muerte!','¡Os condeno a muerte!'),
('-1578013','27654','None shall escape!','13600','1','¡Nadie escapará!','¡Nadie escapará!'),
('-1578012','27654','Gather \'round...','13599','1','¡Reunios!','¡Reunios!'),
('-1578011','27654','It is too late to run!','13598','1','¡Es demasiado tarde para correr!','¡Es demasiado tarde para correr!'),
('-1578009','27654','The war... goes on.','13605','1','La guerra... continua...','La guerra... continua...'),
('-1578008','27654','Another casualty of war!','13604','1','¡Otra baja de guerra!','¡Otra baja de guerra!'),
('-1578007','27654','Sentence: executed!','13603','1','¡Sentencia ejecutada!','¡Sentencia ejecutada!'),
('-1578006','27654','A fitting punishment!','13602','1','Un castigo apropiado...','Un castigo apropiado...'),
('-1578005','27654','The prisoners shall not go free. The word of Malygos is law!','13594','1','Los prisioneros no serán liberados. ¡La palabra de Malygos es ley!','Los prisioneros no serán liberados. ¡La palabra de Malygos es ley!');

-- VAROS

-- Texts
DELETE FROM script_texts WHERE npc_entry = 27447;
insert into `script_texts` (`entry`, `npc_entry`, `content_default`, `sound`, `type`, `content_loc6`, `content_loc7`) values
('-1578010','27447','Intruders, your victory will be short-lived. I am Commander Varos Cloudstrider. My drakes control the skies and protect this conduit. I will see to it personally that the Oculus does not fall into your hands!','13648','1','Intrusos, vuestra victoria será efímera. Soy el Comandante Varos Zancanubes. Mis dracos controlan el cielo y protejen este conducto. Yo me encargaré personalmente de que El Oculus no caiga en vuestro poder.','Intrusos, vuestra victoria será efímera. Soy el Comandante Varos Zancanubes. Mis dracos controlan el cielo y protejen este conducto. Yo me encargaré personalmente de que El Oculus no caiga en vuestro poder.'),
('-1578029','27447','There will be no mercy!','13649','1','¡No habrá piedad!','¡No habrá piedad!'),
('-1578030','27447','Blast them! Destroy them!','13650','1','¡Reventadlos! ¡Acabad con ellos!','¡Reventadlos! ¡Acabad con ellos!'),
('-1578031','27447','Take no prisoners! Attack! ','13651','1','¡No tomeis prisioneros! ¡Atacad!','¡No tomeis prisioneros! ¡Atacad!'),
('-1578032','27447','Strike now! Obliterate them!','13652','1','¡Atacad ahora! ¡Borradlos del mapa!','¡Atacad ahora! ¡Borradlos del mapa!'),
('-1578033','27447','I warned you!','13653','1','¡Te avisé!','¡Te avisé!'),
('-1578034','27447','Oculus is ours!','13654','1','¡El Oculus es nuestro!','¡El Oculus es nuestro!'),
('-1578035','27447','They are... too strong! Underestimated their... fortitude.','13655','1','¡Son... demasiado fuertes! Hemos subestimado su... fortaleza...',NULL),
('-1578036','27447','%s calls an Azure Ring Captain!','0','4','¡%s llama a un Capitan del Anillo Azur!','¡%s llama a un Capitan del Anillo Azur!');

-- UROM

-- Texts
DELETE FROM script_texts WHERE npc_entry = 27655;
insert into `script_texts` (`entry`, `npc_entry`, `content_default`, `sound`, `type`, `content_loc6`, `content_loc7`) values
('-1578000','27655','What do we have here... those that would defy the Spell-Weaver? Those without foresight our understanding. How can i make you see? Malygos is saving the world from itself! Bah! You are hardly worth my time!','13635','1','¿Qué tenemos aquí? ¿Aquellos que se atreven a desafiar al Tejehechizos? ¿Aquellos a quienes les falta previsión y entendimiento? ¿Cómo puedo explicaroslo? Malygos está intentando salvar al mundo de sí mismo... ¡Bah! ¡No malgasteis mi tiempo!','¿Qué tenemos aquí? ¿Aquellos que se atreven a desafiar al Tejehechizos? ¿Aquellos a quienes les falta previsión y entendimiento? ¿Cómo puedo explicaroslo? Malygos está intentando salvar al mundo de sí mismo... ¡Bah! ¡No malgasteis mi tiempo!'),
('-1578001','27655','Clearly my pets failed. Perhaps another demonstration is in order.','13636','1','Es evidente que mis mascotas han fracasdo. Quizás sea necesaria otra \"demostración\".','Es evidente que mis mascotas han fracasdo. Quizás sea necesaria otra \"demostración\".'),
('-1578002','27655','Still you fight. Still you cling to misguided principles. If you survive, you\'ll find me in the center ring.','13637','1','¡Seguis luchando! ¡Seguis aferrandoos a principios erroneos! ¡Si sobrevivis me encontrareis en el anillo central!','¡Seguis luchando! ¡Seguis aferrandoos a principios erroneos! ¡Si sobrevivis me encontrareis en el anillo central!'),
('-1578003','27655','Poor blind fools!','13638','1','¡Pobres necios ciegos!','¡Pobres necios ciegos!'),
('-1578004','27655','A taste... just a small taste... of the Spell-Weaver\'s power!','13639','1','Una muestra... ¡Una pequeña muestra del poder del Tejehechizos!','Una muestra... ¡Una pequeña muestra del poder del Tejehechizos!'),
('-1578018','27655','Everything I\'ve done... has been for Azeroth...','13644','1','Todo lo que he hecho... ha sido por Azeroth...','Todo lo que he hecho... ha sido por Azeroth...'),
('-1578019','27655','If only you understood!','13641','1','¡Si pudieras entenderlo...!','¡Si pudieras entenderlo...!'),
('-1578020','27655','Now do you see? Do you?!','13642','1','¡Ahora lo ves! ¡¿Verdad?!','¡Ahora lo ves! ¡¿Verdad?!'),
('-1578021','27655','Unfortunate, but necessary.','13643','1','Desafortunado... ¡Pero necesario!','Desafortunado... ¡Pero necesario!'),
('-1578037','27655','So much unstable energy... but worth the risk to destroy you!','13640','1','¡Tanta energía inestable! ¡Pero vale la pena correr el riesgo de destruiros!','¡Tanta energía inestable! ¡Pero vale la pena correr el riesgo de destruiros!');

-- EREGOS --


UPDATE `creature_template` SET `modelid2` = 0, `ScriptName` = 'mob_planar_anomaly' WHERE `entry` = 30879;

-- Texts
DELETE FROM `creature_text` WHERE entry = 27656;
DELETE FROM script_texts WHERE npc_entry = 27656;
INSERT INTO script_texts (npc_entry, entry, content_default, content_loc6, content_loc7, sound, TYPE) VALUES
(27656, -1578022, 'Simpletons! You cannot comprehend the forces you have set in motion. The ley line conduit will not be disrupted! Your defeat shall be absolute!', '¡Simplones! No podeis comprender las fuerzas que habeis puesto en marcha. ¡El conducto de lineas Ley no sera interrumpido! ¡Vuestra derrota será total!', content_loc6, 13622, 1),
(27656, -1578023, 'You brash interlopers are out of your element! I will ground you!', '¡Entrometidos descarados, estais fuera de vuestro elemento! ¡Os enterraré!', content_loc6, 13623, 1),
(27656, -1578024, 'It\'s a long way down...', 'Hay mucha caida...', content_loc6, 13628, 1),
(27656, -1578025, 'Back to the earth with you!', '¡Vuelve a la tierra!', content_loc6, 13629, 1),
(27656, -1578026, 'Enjoy the fall!', '¡Disfruta de la caida!', content_loc6, 13630, 1),
(27656, -1578027, 'Such insolence... such arrogance... must be PUNISHED!', '¡Tanta insolencia... tanta arrogancia... deben ser CASTIGADAS!', content_loc6, 13624, 1),
(27656, -1578028, 'Savor this small victory, foolish little creatures. You and your dragon allies have won this battle. But we will win... the Nexus War.', 'Saboread esta pequeña victoria, criaturitas insensatas. Vosotros y vuestros aliados dragones habeis ganado esta batalla... pero nosotros ganaremos la guerra del nexo...', content_loc6, 13631, 1);

-- == Game Objects ==
UPDATE `gameobject_template` SET `flags` = 32 WHERE `entry` IN (191349, 193603);
UPDATE `gameobject` SET `spawntimesecs` = 608400 WHERE `id` IN (191349, 193603);
UPDATE `gameobject` SET `spawntimesecs` = 608400 WHERE `id` = 191351;

DELETE FROM `spell_script_names` WHERE spell_id IN (49840, 49838, 49592, 50341, 50344, 50241, 50325, 49460, 49464, 49346, 53797);
INSERT INTO `spell_script_names` VALUES
(49840, 'spell_oculus_shock_lance'),
(49838, 'spell_oculus_stop_time'),
(49592, 'spell_oculus_temporal_rift'),
(50341,'spell_oculus_touch_nightmare'),
(50344,'spell_oculus_dream_funnel'),
(50241, 'spell_oculus_evasive_charges'),
(50325, 'spell_oculus_soar'),
(49460, 'spell_oculus_rider_aura'),
(49464, 'spell_oculus_rider_aura'),
(49346, 'spell_oculus_rider_aura'),
(53797, 'spell_oculus_drake_flag');