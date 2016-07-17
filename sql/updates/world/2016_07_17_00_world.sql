--
SET @NPC_OVERLORD_RUNTHAK:= 31431;
SET @NPC_THRALL:= 31412;
SET @NPC_SYLVANAS:= 31419;

SET @OG_TELEPORTSPELL:= 59064;
SET @UCTELEPORTSPELL:= 59439;

UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = @NPC_OVERLORD_RUNTHAK;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = @NPC_THRALL;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = @NPC_SYLVANAS;

DELETE FROM `areatrigger_scripts` WHERE `entry` = 5279;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (@OG_TELEPORTSPELL, @UCTELEPORTSPELL);
