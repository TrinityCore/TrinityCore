-- Dummy aura of 32146 with 1s duration and TARGET_UNIT_CASTER may be used to force caster cast 32147 (TARGET_DEST_NEARBY_ENTRY),
-- they scripts auras like that. However, usually to remove aura or cast spell on player. And this case is different because there's also
-- 39189 and it's a copy of 32146 but it summons creature via 39191 (TARGET_DEST_CASTER) and not object. It more looks like it's scripted
-- directly in creature script.
-- Probably they just copied 32146 to make 39189, but changed implementation and didn't bothered to remove dummy aura effect of 39189. Or
-- maybe TARGET_DEST_NEARBY_ENTRY of 32147 is a typo, who knows. There's not too much options to think of what exactly dummy auras does.
-- We'll cast 32147 directly in creature script for now
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18240;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18240 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18240,0,0,1,8,0,100,1,32146,0,0,0,0,33,18240,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sunspring Villager - On Spellhit 'Liquid Fire' - Quest Credit 'Stopping the Spread' (No Repeat)"),
(18240,0,1,2,61,0,100,0,0,0,0,0,0,11,32147,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunspring Villager - On Spellhit 'Liquid Fire' - Cast 'Ignite Corpse'"),
(18240,0,2,0,61,0,100,0,0,0,0,0,0,41,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunspring Villager - On Spellhit 'Liquid Fire' - Delayed Despawn");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q9874_liquid_fire';
