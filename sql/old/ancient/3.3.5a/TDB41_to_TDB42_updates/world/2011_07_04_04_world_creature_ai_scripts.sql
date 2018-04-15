-- Remove EAI events for Eye of the Storm Emissary and Eye of the Storm Envoy (incorrectly added earlier)
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (22013,22015);

-- Scripts already converted to SAI, removing EAI equivalents
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (18103,26349,26370,27234,27235,27236,27237);

-- Update: Use EventAI for Oluf the Violent, Iron Rune-shaper, Slag, Apprentice Osterkilgr, Scarlet Highlord Daion
UPDATE `creature_template` SET `AIName`='EventAI', `ScriptName`='' WHERE `entry` IN (23931,26270,28585,30409,32417);

