-- Ample Inspiration (12828)

SET @GOB_UDED           := 191553; -- U.D.E.D. Dispenser
SET @GOSSIP_MENU        := 10211;
SET @NPC_MAMMOTH        := 29402; -- Ironwool Mammoth
SET @NPC_MEAT_BUNNY     := 29524; -- Mammoth Meat Bunny
SET @SPELL_THROW_UDED   := 54577; -- Throw U.D.E.D.
SET @SPELL_GIVE_UDED    := 54576; -- Forceitem U.D.E.D.
SET @SPELL_SPAWNER      := 54581; -- Mammoth Explosion Spell Spawner
SET @SPELL_MAIN_MEAT    := 57444; -- Summon Main Mammoth Meat
SET @SPELL_MEAT         := 54625; -- Summon Mammoth Meat
SET @SPELL_MEAT_BUNNY1  := 54627; -- Quest - Mammoth Explosion Summon Object
SET @SPELL_MEAT_BUNNY2  := 54628; -- Quest - Mammoth Explosion Summon Object
SET @SPELL_MEAT_BUNNY3  := 54623; -- Quest - Mammoth Explosion Summon Object

DELETE FROM `spell_script_names` WHERE `spell_id`=@SPELL_THROW_UDED;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP_MENU;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP_MENU,0,0,'<Retrieve a bomb from the dispenser.>',1,0,0,0,0,0,NULL);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@GOB_UDED;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@GOB_UDED;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GOB_UDED,1,0,1,62,0,100,0,@GOSSIP_MENU,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip  - Close gossip'),
(@GOB_UDED,1,1,0,61,0,100,0,0,0,0,0,85,@SPELL_GIVE_UDED,0,0,0,0,0,7,0,0,0,0,0,0,0,'On link  - Cast Forceitem U.D.E.D.');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_MAMMOTH;
UPDATE `creature_template` SET `flags_extra`=128,`AIName`='SmartAI' WHERE `entry`=@NPC_MEAT_BUNNY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC_MAMMOTH;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_MAMMOTH,@NPC_MEAT_BUNNY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Ironwool Mammoth
(@NPC_MAMMOTH,0,0,0,0,0,100,0,1000,3000,7000,10000,11,56356,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ironwool Coat'),
(@NPC_MAMMOTH,0,1,2,8,0,100,0,@SPELL_THROW_UDED,0,0,0,11,@SPELL_SPAWNER,0,0,0,0,0,1,0,0,0,0,0,0,0,'On spellhit - Cast Mammoth Explosion Spell Spawner'),
(@NPC_MAMMOTH,0,2,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Despawn'),
-- Mammoth Meat Bunny
(@NPC_MEAT_BUNNY,0,0,0,54,0,100,1,0,0,0,0,11,@SPELL_MEAT,0,0,0,0,0,1,0,0,0,0,0,0,0,'On spawn - Cast');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_SPAWNER;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_SPAWNER,@SPELL_MAIN_MEAT,0,'Mammoth Explosion Spell Spawner link to Summon Main Mammoth Meat'),
(@SPELL_SPAWNER,@SPELL_MEAT_BUNNY1,0,'Mammoth Explosion Spell Spawner link to Quest - Mammoth Explosion Summon Object'),
(@SPELL_SPAWNER,@SPELL_MEAT_BUNNY2,0,'Mammoth Explosion Spell Spawner link to Quest - Mammoth Explosion Summon Object'),
(@SPELL_SPAWNER,@SPELL_MEAT_BUNNY3,0,'Mammoth Explosion Spell Spawner link to Quest - Mammoth Explosion Summon Object');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_THROW_UDED) OR (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP_MENU);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_THROW_UDED,0,0,31,1,3,@NPC_MAMMOTH,0,0,0,'','Require Ironwool Mammoth as target'),
(15,@GOSSIP_MENU,0,0,0,9,0,12828,0,0,0,0,'','Show gossip if quest taken');
