-- Cannot Reproduce (13320,13355)
-- Retest Now (13321,13322,13356,13357)

SET @NPC_BLUE_KC      := 32242; -- Blue Sample KC Bunny
SET @NPC_GREEN_KC     := 32244; -- Green Sample KC Bunny
SET @NPC_DARK_KC      := 32245; -- Dark Sample KC Bunny
SET @SPELL_COLLECT    := 60256; -- Collect Sample
SET @SPELL_WRITHING   := 60310; -- Throw Writhing Mass
SET @NPC_MASS_KC      := 32266; -- Writhing Mass KC Bunny
SET @AURA_DISCERNMENT := 60311; -- Dark Discernment
SET @ITEM_ESSENCE     := 44301; -- Tainted Essence

UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=128 WHERE `entry` IN (@NPC_BLUE_KC,@NPC_GREEN_KC,@NPC_DARK_KC);
UPDATE `creature` SET `MovementType`=0 WHERE `id` IN (@NPC_BLUE_KC,@NPC_GREEN_KC,@NPC_DARK_KC);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_BLUE_KC,@NPC_GREEN_KC,@NPC_DARK_KC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_BLUE_KC,0,0,0,8,0,100,0,@SPELL_COLLECT,0,0,0,33,@NPC_BLUE_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blue Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_BLUE_KC,0,1,0,8,0,100,0,@SPELL_WRITHING,0,0,0,33,@NPC_MASS_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blue Sample KC Bunny - On spellhit - Killed moster credit"),
--
(@NPC_GREEN_KC,0,0,0,8,0,100,0,@SPELL_COLLECT,0,0,0,33,@NPC_GREEN_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Green Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_GREEN_KC,0,1,0,8,0,100,0,@SPELL_WRITHING,0,0,0,33,@NPC_MASS_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Green Sample KC Bunny - On spellhit - Killed moster credit"),
--
(@NPC_DARK_KC,0,0,0,8,0,100,0,@SPELL_COLLECT,0,0,0,33,@NPC_DARK_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Sample KC Bunny - On spellhit - Killed moster credit"),
(@NPC_DARK_KC,0,1,0,8,0,100,0,@SPELL_WRITHING,0,0,0,33,@NPC_MASS_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Sample KC Bunny - On spellhit - Killed moster credit");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (32290,32289);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32290,32289) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32289, 0, 0, 0, 0, 0, 100, 0, 0, 0, 7000, 9000, 11, 34359, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Damned Apothecary - IC - Cast Fire Breath Potion (Self)'),
(32289, 0, 1, 0, 2, 0, 100, 0, 30, 50, 60000, 60000, 11, 17534, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Damned Apothecary - On between 30 and 50% HP - Cast Healing Potion (Self)'),
--
(32290, 0, 0, 0, 0, 0, 100, 0, 0, 2000, 3000, 10000, 11, 60846, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cultist Alchemist - IC - Cast Corrosive Vial');


DELETE FROM `conditions` WHERE `SourceEntry` IN (@SPELL_COLLECT,@SPELL_WRITHING) AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`=@ITEM_ESSENCE AND `SourceTypeOrReferenceId`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_COLLECT,0,0,31,0,3,@NPC_BLUE_KC,0,0,0,'','Spell target creature'),
(13,1,@SPELL_COLLECT,0,1,31,0,3,@NPC_GREEN_KC,0,0,0,'','Spell target creature'),
(13,1,@SPELL_COLLECT,0,2,31,0,3,@NPC_DARK_KC,0,0,0,'','Spell target creature'),
--
(13,1,@SPELL_WRITHING,0,0,31,0,3,@NPC_BLUE_KC,0,0,0,'','Spell target creature'),
(13,1,@SPELL_WRITHING,0,1,31,0,3,@NPC_GREEN_KC,0,0,0,'','Spell target creature'),
(13,1,@SPELL_WRITHING,0,2,31,0,3,@NPC_DARK_KC,0,0,0,'','Spell target creature'),

-- Tainted Essence drops only if player has aura
(1,32236,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32259,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32262,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32268,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32276,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32279,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32289,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32290,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura'),
(1,32297,@ITEM_ESSENCE,0,0,1,0,@AURA_DISCERNMENT,0,0,0,0,'','Loot requires aura');
