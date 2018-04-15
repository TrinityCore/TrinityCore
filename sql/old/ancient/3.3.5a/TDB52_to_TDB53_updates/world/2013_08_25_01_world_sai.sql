SET @NPC_BLUE_KC      := 32242; -- Blue Sample KC Bunny
SET @NPC_GREEN_KC     := 32244; -- Green Sample KC Bunny
SET @NPC_DARK_KC      := 32245; -- Dark Sample KC Bunny
SET @SPELL_COLLECT    := 60256; -- Collect Sample
SET @SPELL_WRITHING   := 60310; -- Throw Writhing Mass
SET @NPC_MASS_KC      := 32266; -- Writhing Mass KC Bunny
SET @ITEM_ESSENCE     := 44301; -- Tainted Essence

UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=128 WHERE `entry` IN (@NPC_BLUE_KC,@NPC_GREEN_KC,@NPC_DARK_KC);
UPDATE `creature` SET `MovementType`=0 WHERE `id` IN (@NPC_BLUE_KC,@NPC_GREEN_KC,@NPC_DARK_KC);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_BLUE_KC,@NPC_GREEN_KC,@NPC_DARK_KC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_BLUE_KC,0,0,0,8,0,100,0,@SPELL_COLLECT,0,0,0,33,@NPC_BLUE_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blue Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_BLUE_KC,0,1,2,8,0,100,0,@SPELL_WRITHING,0,0,0,33,@NPC_MASS_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blue Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_BLUE_KC,0,2,0,61,0,100,0,0,0,0,0,11,60505,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blue Sample KC Bunny - On Link - Cast Fury of the Fallen Cultist to Invoker"),
--
(@NPC_GREEN_KC,0,0,0,8,0,100,0,@SPELL_COLLECT,0,0,0,33,@NPC_GREEN_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Green Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_GREEN_KC,0,1,2,8,0,100,0,@SPELL_WRITHING,0,0,0,33,@NPC_MASS_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Green Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_GREEN_KC,0,2,0,61,0,100,0,0,0,0,0,11,60506,0,0,0,0,0,7,0,0,0,0,0,0,0,"Green Sample KC Bunny - On Link - Cast Blood of the Fallen Cultist to Invoker"),
--
(@NPC_DARK_KC,0,0,0,8,0,100,0,@SPELL_COLLECT,0,0,0,33,@NPC_DARK_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_DARK_KC,0,1,2,8,0,100,0,@SPELL_WRITHING,0,0,0,33,@NPC_MASS_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_DARK_KC,0,2,0,61,0,100,0,0,0,0,0,11,60504,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Sample KC Bunny - On Link - Cast Agony of the Fallen Cultist to Invoker");
