SET @DIBear=30292; -- Dead Icemaw Bear
SET @LJBunny=30366; -- Lure Jormuttar Bunny

-- WTF?! Spell Carve Bear Flank have no triggered spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=56562;
-- Set Spell script
DELETE FROM `spell_script_names` WHERE `spell_id`=56565;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56565,'spell_q13011_bear_flank_master');
-- Update Item's Target requirement
UPDATE `conditions` SET `ConditionTypeOrReference`=31 ,`ConditionTarget`=1 ,`ConditionValue1` =3,`ConditionValue2`=@DIBear WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=56562;
-- Update creature_templates to use SAI
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (@DIBear,@LJBunny);
-- Update Icy Crater phaseMask
UPDATE `gameobject` SET `phaseMask`=4 WHERE `guid`=99730;
-- Add Dead Icemaw Bear SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=30292 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@DIBear,0,0,1,8,0,100,0,56562,0,0,0,11,56565,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dead Icemaw Bear - On Spell Hit - Cast Bear Flank Master'),
(@DIBear,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dead Icemaw Bear - Link With Previous Event - Despawn'),
(@DIBear,0,2,0,8,0,100,0,56569,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dead Icemaw Bear - On Spell Hit - Despawn');
-- Add Lure Jormuttar Bunny SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LJBunny AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@LJBunny,0,0,0,11,0,100,0,0,0,0,0,12,30340,2,120000,0,0,0,1,0,0,0,0,0,0,0,'Lure Jormuttar Bunny - On Spawn - Summon Jormuttar');
-- Add Dead Icemaw Bear creature_text
DELETE FROM `creature_text` WHERE `entry`=30292;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@DIBear,0,0,'This bear\'s flank is frozen solid... try again.',42,0,0,0,0,0,'');
