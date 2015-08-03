-- Update text's with creature_text.type old format values - some missing texts should be fixed.
-- based on http://collab.kpsn.org/display/tc/Creature+text+tc2#Creaturetexttc2-type
UPDATE `creature_text` SET `type`=12 WHERE `type`=0; -- Say
UPDATE `creature_text` SET `type`=14 WHERE `type`=1; -- Yell
UPDATE `creature_text` SET `type`=16 WHERE `type`=2; -- Emote
UPDATE `creature_text` SET `type`=41 WHERE `type`=3; -- Boss Emote
UPDATE `creature_text` SET `type`=15 WHERE `type`=4; -- Whisper
UPDATE `creature_text` SET `type`=42 WHERE `type`=5; -- Boss Whisper
