/*  QUEST : [Débitez-les !] (ID = 12050)
    ISSUE ID = 313
    Impossible de monter dans les déchicteurs
*/
SET @SHREDDER := 27061; -- Déchiqueteur de Xink
SET @XINK	:= 26660; -- Xink
SET @SPELL := 52872; -- Télécommande de Déchicteur de Xink

UPDATE `creature_template` SET `npcflag`=16777216,`unit_flags`=32768,`spell1`=47938,`spell2`=47921,`spell3`=49857,`spell4`=47966, `spell6`=47939 ,`VehicleId`=42 WHERE `entry`=@SHREDDER;

-- Conditions Gossip option
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=9422);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9422,0,1,9,12050,0,0,0,'','Affiche le gossip seulement si [Débitez-les] est pris'),
(15,9422,0,1,26,36734,0,0,0,'','Affiche le gossip seuelement si le joueur n\'a pas l\'item Télécommande du Déchicteur'),
(15,9422,0,2,26,36734,0,0,0,'','Affiche le gossip seuelement si le joueur n\'a pas l\'item Télécommande du Déchicteur'),
(15,9422,0,2,9,12052,0,0,0,'','Affiche les options du gossip si le joueur a prit la quête');

DELETE FROM `conditions` WHERE `SourceEntry`=@SHREDDER;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)VALUES
(16,0,@SHREDDER,0,23,4230,0,0,0,'',"Dismount le joueur lorsqu'il sort de la zone de quête");

-- Ajout NPC Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (26660,27061) AND `groupid` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@XINK,0,0, 'About time!  Get that lumber and get moving.  The horde won''t be up there fighting forever, there''s money to be made!',12,0,100,25,1000,0, 'Xink'),
(@SHREDDER,0,0, 'Xink''s Shredder ready and available for woodland destruction.',16,0,100,0,0,0, 'Xink''s Shredder'),
(@SHREDDER,1,0, 'Xink''s Shredder security features activated.  Returning to base.',16,0,100,0,0,0, 'Xink''s Shredder');

-- SAI Xink
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@XINK;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@XINK AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@XINK,0,0,0,19,0,100,0,12050,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Xink - Acceptation de la quête'),
(@XINK,0,1,2,62,0,100,0,9422,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xink - Sélectin du gossip - Cast la spell télécommande'),
(@XINK,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Xink - Sélection du gossip - Ferme le gossip');

DELETE FROM `conditions` WHERE `SourceEntry`=47939;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 47939, 0, 0, 35, 0, 1, 5, 3, 0, 0, 0, '', 'Farm du bois - Limite les Cibles');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27061;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(27061, 47920, 1, 0);



/* Quête : [Entretien avec les profondeurs] (ID = 12032)
  ISSUE ID = 313
  Rien ne se passe quand on clique sur la perle.
*/
SET @TRIGGER := 4951;
SET @OACHANOA := 26648;
SET @PEARL := 188422;
SET @ENTRY := 12032;
SET @SOURCETYPE := 5;

-- CORRECTIF DU NPC & DU GOB
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=@PEARL;
UPDATE `creature_template` SET `speed_run`=2.14286, `faction`=190, `unit_flags`=33536, `unit_flags2`=2080, `AIName`='SmartAI', `InhabitType`=4 WHERE `entry`=@OACHANOA;

DELETE FROM `areatrigger_scripts` WHERE `entry`=@TRIGGER;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@TRIGGER,'SmartTrigger');
-- AJOUT DE L'EVENT LORSQUE LE NPC ARRIVE.
DELETE FROM `event_scripts` WHERE `id`=17612;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(17612,20,10,@OACHANOA,120000,0,2367.975,1712.07,0.232847,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@TRIGGER AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGGER,2,0,9,0,12032,0,0,0,0,'','SAI only activates if player is on quest Conversing With the Depths'),
(22,1,@TRIGGER,2,0,1,0,47098,0,0,0,0,'','SAI only activates if player has aura Oacha''noa''s Compulsion');

-- Ajout des Smart Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid`=@OACHANOA AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEARL AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@OACHANOA*100,@OACHANOA*100+1,@PEARL*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OACHANOA,0,0,1,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On Spawn - Set event phase 1'),
(@OACHANOA,0,1,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,2367.975,1712.07,43.56623,0, 'Oacha''noa - On Spawn - Move to position'),
(@OACHANOA,0,2,0,34,1,100,0,0,1,0,0,80,@OACHANOA*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On movement inform (phase 1) - Run script 0'),
(@OACHANOA,0,3,0,52,1,100,0,3,@OACHANOA,0,0,1,4,10100,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On text 3 over (phase 1) - Say line'),
(@OACHANOA,0,4,5,52,1,100,0,4,@OACHANOA,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa - On text 4 over (phase 1) - Say line'),
(@OACHANOA,0,5,6,61,0,100,0,0,0,0,0,6,12032,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa - On text 4 over (phase 1) - Fail quest'),
(@OACHANOA,0,6,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On text 4 over (phase 1) - Despawn after 2 seconds'),
(@OACHANOA,0,7,8,38,1,100,0,0,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On data 0 1 set (phase 1) - Set event phase 0'),
(@OACHANOA,0,8,0,61,0,100,0,0,0,0,0,80,@OACHANOA*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On data 0 1 set (phase 1) - Run script 1'),

(@TRIGGER,2,0,0,46,0,100,0,0,0,0,0,45,0,1,0,0,0,0,14,21195,@PEARL,0,0,0,0,0, 'On trigger - Set data 0 1 Pearl of the Depths'),

(@PEARL,1,0,0,70,0,100,0,2,0,0,0,80,@PEARL*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Pearl of the Depths - On state changed - Run script'),
(@PEARL,1,1,0,38,0,100,0,0,1,0,0,45,0,1,0,0,0,0,19,@OACHANOA,100,0,0,0,0,0, 'Pearl of the Depths - On data 0 1 set - Set data 0 1 Oacha''noa'),

(@OACHANOA*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 0 - Turn to'),
(@OACHANOA*100,9,1,0,0,0,100,0,1200,1200,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),
(@OACHANOA*100,9,2,0,0,0,100,0,8500,8500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),
(@OACHANOA*100,9,3,0,0,0,100,0,9700,9700,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),
(@OACHANOA*100,9,4,0,0,0,100,0,0,0,0,0,11,47098,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 0 - Spellcast Oacha''noa''s Compulsion'),
(@OACHANOA*100,9,5,0,0,0,100,0,10900,10900,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),

(@OACHANOA*100+1,9,0,0,0,0,100,0,0,0,0,0,15,12032,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Complete quest'),
(@OACHANOA*100+1,9,1,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,2,0,0,0,100,0,10600,10600,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,3,0,0,0,100,0,10800,10800,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,4,0,0,0,100,0,10700,10700,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.281219, 'Oacha''noa script 1 - Turn to'),
(@OACHANOA*100+1,9,5,0,0,0,100,0,200,200,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,6,0,0,0,100,0,1000,1000,0,0,5,374,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 1 - Play emote'),
(@OACHANOA*100+1,9,7,0,0,0,100,0,0,0,0,0,4,11561,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 1 - Play sound'),
(@OACHANOA*100+1,9,8,0,0,0,100,0,2300,2300,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 1 - Despawn'),

(@PEARL*100,9,0,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Pearl of the Depths script - Store targetlist'),
(@PEARL*100,9,1,0,0,0,100,0,0,0,0,0,99,0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Pearl of the Depths script - Set state'),
(@PEARL*100,9,2,0,0,0,100,0,21000,21000,0,0,100,1,0,0,0,0,0,19,@OACHANOA,100,0,0,0,0,0, 'Pearl of the Depths script - Send targetlist'),
(@PEARL*100,9,6,0,0,0,100,0,44000,44000,0,0,99,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Pearl of the Depths script - Set state');

-- Ajout des textes pour OACHANOA (NPC)
DELETE FROM `creature_text` WHERE `creatureid`=@OACHANOA;
INSERT INTO `creature_text` (`CreatureID`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@OACHANOA,0,0,'Little $N, why do you call me forth? Are you working with the trolls of this land? Have you come to kill me and take my power as your own?',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,1,0,'I sense uncertainty in you, and I do not trust it whether you are with them, or not. If you wish my augury for the Kalu''ak, you will have to prove yourself first.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,2,0,'I will lay a mild compulsion upon you. Jump into the depths before me so that you put yourself into my element and thereby display your submission.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,3,0,'Though you are compelled, the choice, and the last step before you leap, are yours. You have twenty more seconds to decide.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,4,0,'I''m rather curious as to what will happen, should you ignore this and NOT jump into the water.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,5,0,'Well done, $N. Your display of respect is duly noted. Now, I have information for you that you must convey to the Kalu''ak.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,6,0,'Simply put, you must tell the tuskarr that they cannot run. If they do so, their spirits will be destroyed by the evil rising within Northrend.',15,0,100,0,0,0,'Oacha''noa'),
(@OACHANOA,7,0,'Tell the mystic that his people are to stand and fight alongside the Horde and Alliance against the forces of Malygos and the Lich King.',15,0,100,0,0,0,'Oacha''noa'),
(@OACHANOA,8,0,'Now swim back with the knowledge I have granted you. Do what you can for them, $r.',15,0,100,0,0,0,'Oacha''noa'),
(@OACHANOA,9,0,'Very well, $N, you have failed to act. The prophecy is not yours to learn. Do not call upon me again until you have found your backbone.',14,0,100,33,0,11557,'Oacha''noa');
