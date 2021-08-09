UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='73723';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='73724';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='73725';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71408';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71409';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='73948';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='73949';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='73951';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71395';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71393';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71392';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71397';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71405';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71380';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71382';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71378';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71385';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71388';
UPDATE `creature_template` SET `ScriptName`='npc_generic_sop_units' WHERE `entry`='71383';
DELETE FROM `locales_creature` WHERE `entry`='72828'; 
DELETE FROM `locales_creature` WHERE `entry`='72810';
DELETE FROM `locales_creature` WHERE `entry`='72787';
INSERT INTO `locales_creature` (`entry`, `name_loc1`, `name_loc2`, `name_loc3`, `name_loc4`, `name_loc5`, `name_loc6`, `name_loc7`, `name_loc8`, `name_loc9`, `name_loc10`, `subname_loc1`, `subname_loc2`, `subname_loc3`, `subname_loc4`, `subname_loc5`, `subname_loc6`, `subname_loc7`, `subname_loc8`, `subname_loc9`, `subname_loc10`) values('72828','?? ?? ???? ??','Esprit de marche-vent sans nom','Geist eines namenlosen Windlaufers','???????','????????','Espiritu de viajero del viento sin nombre','Espiritu de viajero del viento sin nombre','Безымянный дух танцующего с ветром','Espirito do Andarilho do Vento Sem Nome','Spirito dell\'Impetuoso Innominato','','','','','','','','','','');
UPDATE `creature_template` SET `modelid1`='48864',`IconName`='',`npcflag`='0',`name`='Nameless Windwalker Spirit',`ScriptName`='npc_generic_sop_units' WHERE `entry`='72828'; 
INSERT INTO `locales_creature` (`entry`, `name_loc1`, `name_loc2`, `name_loc3`, `name_loc4`, `name_loc5`, `name_loc6`, `name_loc7`, `name_loc8`, `name_loc9`, `name_loc10`, `subname_loc1`, `subname_loc2`, `subname_loc3`, `subname_loc4`, `subname_loc5`, `subname_loc6`, `subname_loc7`, `subname_loc8`, `subname_loc9`, `subname_loc10`) values('72810','??? ???? ??','Esprit de sage tisse-brume','Geist einer weisen Nebelwirkerin','???????','????????','Espiritu de tejedora de niebla sabia','Espiritu de tejedora de niebla sabia','Дух мудрого ткача туманов','Espirito de Tecela da Nevoa Sabia','Spirito del Mistico Saggio','','','','','','','','','','');
UPDATE `creature_template` SET `modelid1`='48859',`IconName`='',`npcflag`='0',`name`='Wise Mistweaver Spirit',`ScriptName`='npc_generic_sop_units' WHERE `entry`='72810'; 
INSERT INTO `locales_creature` (`entry`, `name_loc1`, `name_loc2`, `name_loc3`, `name_loc4`, `name_loc5`, `name_loc6`, `name_loc7`, `name_loc8`, `name_loc9`, `name_loc10`, `subname_loc1`, `subname_loc2`, `subname_loc3`, `subname_loc4`, `subname_loc5`, `subname_loc6`, `subname_loc7`, `subname_loc8`, `subname_loc9`, `subname_loc10`) values('72787','?? ???? ??','Esprit d’ancien maitre brasseur','Geist eines alten Braumeisters','??????','????????','Espiritu de maestro cervecero anciano','Espiritu de maestro cervecero anciano','Дух древнего хмелевара','Espirito de Mestre Cervejeiro Antigo','Spirito del Mastro Birraio Antico','','','','','','','','','','');
UPDATE `creature_template` SET `modelid1`='48863',`IconName`='',`npcflag`='0',`name`='Ancient Brewmaster Spirit',`ScriptName`='npc_generic_sop_units' WHERE `entry`='72787';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '146222','spell_breath_of_fire'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '146180','spell_gusting_crane_kick'); 
INSERT INTO `areatrigger_actions`(`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`comment`) VALUES ( '1158','0','1','0','1','145458','0','-145458','0','0','0','0','OO:Mogu Rune of Power'); 
INSERT INTO `areatrigger_actions`(`entry`,`id`,`moment`,`actionType`,`targetFlags`,`spellId`,`maxCharges`,`aura`,`hasspell`,`chargeRecoveryTime`,`scale`,`hitMaxCount`,`comment`) VALUES ( '1158','1','2','1','1','145458','0','145458','0','0','0','0','OO:Mogu Rune of Power Remove'); 
UPDATE `areatrigger_data` SET `Radius`='2',`RadiusTarget`='2' WHERE `entry`='1158'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE `entry` IN (73723,73724,73725,71408,71409,73948,73949,73951,71395,71393,71392,71397,71405,71380,71382,71378,71385,71388,71383,71398,72828,72810,72787);


 
