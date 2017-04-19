-- add AI to bloodworms to make them not stupid and suicidal
UPDATE `creature_template` SET `ScriptName`='npc_pet_dk_guardian', `AIName`='' WHERE `entry` IN (26125,28017);
