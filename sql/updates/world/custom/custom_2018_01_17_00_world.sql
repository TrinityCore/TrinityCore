-- Add Pet trainer scriptname to pet trainer in stormwind
UPDATE `creature_template` SET `ScriptName`= 'npc_pet_trainer' WHERE `entry`= 44251;

-- druid's natures grace should have a 60 seconds cooldown and should proc on cast, not on hit
UPDATE `spell_proc` SET `SpellPhaseMask`= 1, `Cooldown`= 60000, `HitMask`= 12287 WHERE `SpellId`= -16880;
